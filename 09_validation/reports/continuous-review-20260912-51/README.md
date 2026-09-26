# 문자열 공유에서 selector 등록으로 이어지는 원본 계약

report50의 실제 caller 조사를 통해 문자열 공유가 Objective-C selector 등록에 연결됨을 확인했다. **원본 정적 분석이며 모듈 등록·unload를 실행하거나 모든 caller의 수명·잠금을 검증한 것은 아니다.**

## 직접 참조의 범위와 반환 누락

현재 metadata의 직접 call을 원본 바이트와 대조하면 `NXUniqueString`은 WithLength 내부와 `sel_registerName`에서 호출된다. `NXCopyStringBufferFromZone`은 일반 copy wrapper에서 호출된다. 선택한 metadata에는 WithLength, NoCopy, 일반 copy wrapper로 향하는 직접 call이 없다. 이는 해당 API가 불필요하거나 간접 사용되지 않는다는 증거가 아니다.

`sel_registerName` `1d0288`의 Ghidra C 출력도 `void`지만 원본은 조회 또는 등록 결과를 **EAX로 반환**한다. 로컬 `objc.h`는 `SEL sel_registerName(const char *)`로 선언하며 SEL은 opaque pointer 타입이다. 원본의 이름 포인터 반환 구현과 공개 타입을 구분하고, 현대 C 타입으로 임의 대체하지 않는다.

모듈 등록 함수 `objc_registerModule` 안의 직접 호출 지점 8개에서 call 뒤의 제한된 원본 명령을 읽었다. 모두 EAX를 기존 저장값과 비교하고 다를 때 그 위치에 EAX를 저장한다. 따라서 반환값이 실제 소비된다는 caller 근거도 있다. 이 주변 명령 48개가 모듈 함수 전체의 구조·수명·동시성을 증명하지는 않는다.

## 조회만 하는 getUid와 공유 후 등록하는 wrapper

`sel_getUid` `1d0304`는 NULL 입력에서 0을 반환한다. non-NULL에서는 문자열을 NUL까지 읽어 report50의 string hash와 같은 byte-lane XOR를 계산한다. 이어 table 목록을 탐색해 이름을 찾으면 저장 pointer, 목록 끝까지 없으면 0을 반환한다. 본문에는 신규 문자열 할당이나 등록 호출이 없다.

`sel_registerName`은 먼저 getUid(`1d0290`)를 호출한다. nonzero이면 바로 반환하며, 없으면 `NXUniqueString`(`1d029d`)으로 받은 결과를 내부 `__sel_registerName`(`1d02a3`)에 전달한다. 즉 조회 실패 시 입력을 안정된 공유 문자열로 만드는 경로가 있다. 내부 등록 함수는 별도로 받은 문자열 포인터 자체를 보관할 수 있으므로 두 entry를 같은 복사 정책으로 요약하면 안 된다.

NULL 입력은 getUid와 NXUniqueString을 거쳐 내부 등록의 NULL 검사에서도 0이 된다. 이 wrapper 자체에는 전체 get/share/register 구간을 잠그는 명령이 없으며, caller 직렬화나 callee 전체의 동시성 보장은 별도로 확인해야 한다.

## selector table은 NXHashTable이 아니다

조회/등록 함수에서 관찰한 record 배치는 다음과 같다. 필드 이름은 역할 설명이며 원본 C typedef 확정이 아니다.

| offset | 관찰된 용도 |
|---|---|
| `0x0` | 초기화 caller의 첫 인자 보관; 이번 조회/등록 본문에서 의미 확정 안 함 |
| `0x4` | bucket 수 |
| `0x8` | 등록 시 증가되는 필드 |
| `0xc` | 이름 영역 시작 주소 |
| `0x10` | 이름 영역 끝 주소, exclusive |
| `0x14` | bucket head pointer 배열 |
| `0x18` | 다음 table |

chain node는 `(next, name_pointer)`다. NXHash의 count/data bucket이나 NXMap의 key/value pair를 대입하면 안 된다. 일반 lookup은 hash의 unsigned modulo로 bucket을 골라 node를 순회하며 첫 byte 비교 뒤 strcmp의 0 결과로 일치를 판단한다.

이름 pointer가 record의 `[start, end)` 범위에 들어오면 저장 chain 조회 없이 입력 pointer 자체를 반환하는 경로가 있다(`1d0378..1d0380`, `1d0154..1d015f`). 다만 **hash를 위한 문자열 읽기가 이 범위 검사보다 먼저** 실행된다. 주소가 범위 안이라는 이유만으로 읽기 전제 검증이 생략된 안전한 arbitrary-pointer API라고 해석하지 않는다. 범위가 정확한 selector name 시작점만 포함한다는 caller/loader 전제도 아직 미검증이다.

## 초기 base table과 동적 등록

원본 초기 전역 목록 head `1e5640`은 base record `1e5624`를 가리킨다. base는 bucket 수 1, 등록 필드 0, 이름 범위 `(0,0)`, bucket 배열 포인터 `1d6750`, next 0이며 첫 bucket도 0이다. 이는 초기 파일 bytes이지 runtime 관측은 아니다.

내부 등록 `1d00e8`은 기존 목록/chain에서 같은 이름을 먼저 찾는다. 찾지 못하고 base record에 도달하면 `1e562c`를 증가시킨다. bucket 배열이 초기 stub `1d6750`이면 bucket 수를 `0x335`로 설정하고 `0xcd4` 바이트를 할당·zero한 뒤 modulo를 다시 계산한다. Python 계산상 bucket 821개, DWORD head 배열 3,284바이트다. 초기 stub가 비어 있다는 전제를 건너뛰고 일반적인 기존 entry rehash 구현이라고 부르지 않는다.

새 node는 별도 block에서 얻는다. block이 없거나 사용량이 signed 비교로 `0x27`보다 크면 `0x140` 바이트를 새로 할당하고 사용량을 0으로 설정한다. 정상 상태의 Python 계산상 320바이트에 8바이트 node 40개이며 slot 39까지 사용한 다음 새 block으로 진행한다. 이 크기는 문자열 내용 저장 공간이 아니라 chain node 저장 공간이다.

node에 이전 bucket head와 입력 name pointer를 넣고 bucket head를 새 node로 바꾼다(`1d024a`, `1d024f`, `1d0258`). 문자열을 여기서 다시 복사하지 않는다. 신규 등록 시 반환은 입력 pointer, 기존 일치 시 기존 node의 name pointer다. 목록에서 base를 찾지 못하고 끝나면 `1d026b`에서 abort를 호출하는 경로가 있다. 오류 종료 callee와 allocator 실패의 전체 계약은 이번 범위 밖이다.

할당 helper `1cffec`는 ObjC zone을 얻어 `(zone, size)` allocator를 호출하고, nonzero 크기에 NULL 결과이면 fatal 함수를 호출한다. fatal이 반드시 반환하지 않는지, zone 초기화·VM 실패·회수가 어떻게 이어지는지까지 완료한 것으로 간주하지 않는다.

## init의 목록 전제와 unload의 제한

`__sel_init` `1d03c8`은 새 record `0x1c` 바이트를 할당하고 caller의 시작 주소와 길이로 끝 주소를 계산한다. bucket 수는 `0x335`, 등록 필드는 0, bucket 배열 pointer는 caller 인자를 보관한다. 새로운 bucket 배열을 이 본문에서 만들지는 않는다.

목록을 따라 base record를 발견하면 새 record의 next를 base로 하고, base를 가리키던 링크를 새 record로 교체한다. 따라서 기존 외부 record 뒤, base 앞에 연결된다. **head가 NULL이거나 base 없이 목록이 끝나는 경로에는 새 record를 연결하는 store가 없다.** 임의의 빈 목록에도 정상 append하는 함수로 복원하지 않는다. 초기 원본에는 base가 존재하지만 그 전제가 runtime 내내 유지되는지·오류 경로에서 할당이 회수되는지는 별도 의무다.

`__sel_unloadSelectors` `1d02b0`는 base record의 bucket들만 조사한다. name pointer가 `[start, end)` 안인 node를 pointer-to-link 방식으로 제거하고 같은 링크 위치를 다시 검사한다. 아니면 현재 node의 next 위치로 진행한다. 이름 내용 비교가 아니라 pointer 주소 범위 비교이며, 인접한 여러 제거 대상도 처리하는 분기다.

이 unload 본문에는 node/string/block free 호출, `1e562c` 감소 또는 외부 record 목록 제거가 없다. 따라서 등록 필드를 항상 현재 살아 있는 entry 수라고 가정하거나 unload가 전체 selector 자원을 회수한다고 표현하지 않는다. `objc_unregisterModule`에서의 직접 호출은 연결했지만 module metadata 해제와 selector 수명의 전체 순서는 아직 미분석이다.

## 이번 근거와 남은 확인

본문 6개에서 명령 경계 337개·본문 바이트 886개와 직접 분기 목적지를 대조했다. 별도로 선택한 직접 call 24개와 selector 반환을 소비하는 caller 주변 명령을 확인했다. 이 참조 집계는 metadata 기반 선택이며 전체 원본의 간접 호출까지 찾았다는 뜻이 아니다.

범위 경계·node slot·hash/modulo·크기는 모두 Python 산술이다. 입력 해시 23개와 이전 보존 파일 해시 618개가 일치했다. Ghidra 스킬의 읽기 전용 절차로 원본·디컴파일 해석·헤더·caller를 분리했으며 기존 자료를 변경하지 않았다.

독립 계획 검토 미수신 조건을 유지하고 신규 실행/검증 프로그램·복원 코드·GCC 2.7 빌드를 진행하지 않았다. 전체 의미 분석이나 module loader의 수명·잠금·부팅 검증 완료를 주장하지 않는다.

[원본·산술 근거](selectors-evidence.json) · [보존 목록](preservation.json) · [범위](SCOPE.md) · [남은 분석](OPEN_ITEMS.md)
