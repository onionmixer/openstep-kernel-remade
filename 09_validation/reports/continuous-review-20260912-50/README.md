# 문자열 atom·복사·hash/equality의 원본 계약

report49에서 직접 연결된 문자열 공유 경로를 원본 명령과 로컬 헤더에 대조했다. **정적 분기·반환 레지스터 분석과 Python 산술이며 실제 호출·동시성·메모리 보호 시험은 아니다.**

## 디컴파일 void 반환 누락

다음 entry들의 Ghidra C 출력은 `void`지만, 원본은 호출 결과를 EAX에 유지한 채 반환한다. 로컬 `hashtable2.h`도 포인터 반환으로 선언한다.

| entry | 원본 반환 근거 | 로컬 선언 |
|---|---|---|
| `NXUniqueStringNoCopy` `1cbdfc` | `1cbe46`의 IfAbsent 반환 뒤 EAX 변경 없음 | `NXAtom` |
| `NXCopyStringBufferFromZone` `1cbeb8` | `1cbeea`의 strcpy가 destination을 EAX로 반환, 이후 EAX 변경 없음 | `char *` |
| `NXCopyStringBuffer` `1cbef8` | `1cbf06`의 FromZone 반환 뒤 EAX 변경 없음 | `char *` |

`NXAtom`은 이 헤더에서 `const char *`다. `strcpy` `101b48`의 원본 `101bb4`가 EAX에 최초 destination을 넣는 것까지 확인했다. FromZone의 `MOV EDX,EAX`를 EAX 반환 소실로 해석해서는 안 된다. 기존 export는 수정하지 않고 반환형 복원 의무로 기록했다. 실제 GCC 2.7 ABI 시험을 대체하는 증거는 아니다.

## string hash와 NULL/빈 문자열 equality

초기 `NXStrPrototype` 기록 `1cde50`은 `(1cbb2c, 1cbb94, 1cbc00, 0)`이다. `NXStrHash`는 NULL 또는 빈 문자열에서 0, 나머지는 NUL 이전 바이트들을 shift `0, 8, 16, 24` 위치에 순환 배치해 XOR한다. 첫 NUL 이후 바이트는 hash에 포함하지 않는다. 첫 바이트들에는 MOVZX가 있고, 네 번째 바이트의 `MOV AL` 뒤 DWORD shift 24는 기존 상위 bit를 결과에서 밀어낸다. Python으로 다양한 이전 EAX 상위값과 모든 byte 값을 계산해 이 산술을 확인했다.

예를 들어 `abcd`의 hash는 `0x64636261`, `abcdabcd`는 0이다. 따라서 0 hash가 NULL/빈 문자열만 뜻하는 것도 아니고 hash가 같다고 같은 문자열인 것도 아니다. 계산 표본에는 높은 bit 바이트와 중간 NUL도 포함했다.

`NXStrIsEqual` `1cbb94`는 pointer identity 일치 시 1이다. 하나만 NULL이면 다른 문자열을 REPNE SCASB로 NUL까지 스캔한 뒤 counter를 비교하여 **다른 문자열이 비어 있을 때 1**을 반환한다. 즉 NULL과 빈 문자열을 같게 취급한다. 단순히 첫 바이트만 검사하는 명령열은 아니므로 접근 범위까지 그런 구현으로 요약하지 않는다.

둘 다 non-NULL이면 첫 바이트가 다를 때 0, 같을 때 `_strcmp` 결과가 0인지 검사한다. 이 함수의 반환은 원본에서 0/1로 정규화된다. 문자열의 유효성·NUL 종료·안정성은 caller 전제다.

직접 의존 `_strcmp` `101e7c`는 종료/불일치 위치의 양쪽 byte를 **MOVSX로 부호 확장한 뒤 감산**한다(`101eed`, `101ef0`, `101ef3`). Python에서 byte `0x80`과 `0x7f`의 차이는 -255이며 unsigned-byte 감산의 1과 다르다. string equality는 결과가 0인지 사용하므로 이 부호 차이로 equality가 달라지지는 않지만, 다른 caller의 정렬 비교까지 일반 라이브러리로 대체할 수 있다고 간주하지 않는다. 이 보고서는 표준 strcmp 준수 여부의 외부 조사나 전체 caller 검증이 아니다.

## UniqueString과 NoCopy의 공유 table

원본 초기 전역 `1e5558`, `1e555c`, `1e5560`, `1e5564`, `1e5568`은 모두 0이다. 런타임 상태를 관찰한 것은 아니다. 앞의 table 포인터는 NXMap/NXHash prototype cache와 별개인 문자열 공유 table이다.

`NXUniqueString` `1cbd64`는 입력 NULL이면 즉시 0 경로로 간다. non-NULL에서만 `1e555c` DWORD를 증가시키고, 필요하면 위 string prototype·capacity 0·info 0으로 table을 생성한다. `NXHashGet`(`1cbdb4`)이 nonzero면 저장 포인터를 반환한다. 없으면 복사 helper `1cbc80`을 호출하고 일반 `NXHashInsert`(`1cbdd2`)로 저장한다. Insert가 0을 반환하면 새 복사 포인터를 반환하고, nonzero이면 invariant 로그를 호출한 뒤 0을 반환한다.

일반 Insert는 기존 동등 항목을 교체하므로 오류 로그가 생기는 경로를 무변경/rollback으로 표현하면 안 된다. 본문에는 새 복사본을 직접 회수하거나 이전 table 상태로 되돌리는 코드가 없다. 다만 이 경로가 실제 발생한 경쟁·누수 사례라고 주장하지 않는다.

`NXUniqueStringNoCopy` `1cbdfc`는 NULL 입력 early return이 없고 항상 `1e555c`를 증가시킨 뒤 필요시 같은 table을 생성한다. 이후 `NXHashInsertIfAbsent`에 받은 pointer를 그대로 전달한다. 문자열 복사 helper를 호출하지 않으며 기존 동등 포인터 또는 신규 입력 포인터를 반환한다. 호출자는 등록된 저장 내용과 수명을 유지해야 한다. 함수명이나 헤더만으로 불변성이 하드웨어에 의해 강제된다고 단정하지 않는다.

report49의 NULL 항목 모호성은 이 string prototype에서도 고려해야 한다. 조건부 정적 예로, 처음 빈 table에 NoCopy(NULL)을 넣으면 count가 있는 NULL 항목이 될 수 있고 NoCopy(빈 문자열)는 동등한 기존 NULL을 반환할 수 있다. 이후 UniqueString(빈 문자열)은 Get의 NULL을 부재처럼 처리해 복사 후 일반 Insert로 포인터를 교체할 수 있다. 이 경우 기존 포인터도 NULL이므로 Insert 반환 검사만으로 교체를 구분하지 못한다. **실행한 시나리오가 아니며 caller가 NULL을 실제 전달한다는 증거도 아니다.** NoCopy의 전체 간접 caller·도달성과 NULL 허용 계약은 남겨 둔다.

## 복사용 pool과 잠금의 범위

helper `1cbc80`은 SCASB 결과로 NUL을 포함한 바이트 수를 얻는다. 그 크기가 `0xb4` 이하이면 short pool, 더 크면 `_kalloc(size)`와 memmove의 직접 할당 경로다. Python 계산상 일반 문자열 길이 179자는 NUL 포함 180바이트로 short 경로, 180자는 181바이트로 직접 할당 경로다.

short 경로는 `1e5568` 잠금 객체를 필요시 만들고 0으로 초기화한다. busy 검사와 XCHG로 잠금을 획득한 뒤 pool 잔여량 `1e5564`를 확인한다. 부족하면 `((size+0x167)/0x168)*0x168`의 크기를 계산해 `_kalloc`하고 현재 포인터 `1e5560`을 교체한다. 일반적인 short 입력의 새 chunk 계산값은 360바이트다.

현재 포인터에 NUL을 포함해 복사하고 pointer에 size를 더하고 remaining에서 size를 뺀 뒤, XCHG로 잠금 값을 0으로 돌린다. 별도 alignment 반올림을 적용하는 명령은 이 증가 부분에 없다. 새 chunk로 바꿀 때 이전 chunk를 직접 free하는 호출도 없다. 이전 문자열 포인터가 유지되어야 하는 정책과 전체 수명/회수 검증은 구분한다.

pool 잠금이 존재한다고 전체 interning이 잠겼다고 주장하지 않는다. table 초기화·Get·Insert는 이 helper 바깥에 있고, 큰 문자열의 직접 할당도 short pool 잠금 경로 밖이다. 잠금 객체의 최초 생성 자체, caller 직렬화, callback 재진입 및 scheduler 영향은 미검증이다. 잠금 word를 정상 0/1 상태로 사용하는 전제를 넘어 손상 상태까지 안전하다는 보장도 없다.

로컬 헤더에는 read-only zone/보호를 설명하는 주석이 있지만, 확인한 복사 본문은 `_kalloc`·memmove를 사용하며 직접 보호 설정 호출은 없다. allocator 및 VM 보호 경로까지 확인하기 전 이 주석을 해당 kernel 구현의 강제 보호 완료 증거로 사용하지 않는다.

## WithLength의 signed 길이와 복사 순서

`NXUniqueStringWithLength` `1cbe50`의 로컬 선언은 `int length`지만 Ghidra C는 `size_t`로 표시한다. 원본은 DWORD `length+1`을 구한 뒤 **signed JLE**로 `0x100`과 비교한다(`1cbe67`, `1cbea0`). 일반적인 비음수 길이 255까지는 stack buffer, 256부터는 heap 경로다.

먼저 지정한 length만큼 memmove하고, 그 뒤 `buffer[length]=0`을 저장하여 `NXUniqueString`에 넘긴다. heap scratch는 공유 문자열 반환 후 해제한다. 중간 NUL이 있으면 최종 공유 문자열은 거기서 끝나지만, 앞선 memmove가 그 NUL에서 중단되는 것은 아니다. 입력에는 지정한 길이만큼 읽을 수 있는 메모리가 필요하다.

Python 경계 계산에는 signed 값과 DWORD wrap을 보존했다. 큰 값이나 음수에 해당하는 입력이 stack 분기를 선택할 수 있다는 산술 결과는 정상 caller 도달성·실제 복사 성공·지원 길이 범위를 증명하지 않는다. 그런 입력으로 원본을 실행하거나 메모리를 접근하지 않았다. 부호/범위 검증을 확인하기 전 decompiler의 unsigned 타입으로 광범위한 입력을 지원한다고 결론내리지 않는다.

## 일반 buffer copy는 interning이 아니다

`NXCopyStringBufferFromZone`은 source의 NUL 포함 길이를 스캔하고 `(zone, size)` allocator를 호출한 뒤 `_strcpy(destination, source)`를 호출한다. allocator 호출 이전에 stack에 저장한 source 인자가 뒤의 strcpy에서 사용된다. 반환 EAX는 새 destination이다. wrapper `NXCopyStringBuffer`는 기본 zone을 얻어 FromZone에 전달한다.

이 경로는 공유 hash table 조회 없이 별도 복사본을 만든다. NULL 입력 검사나 allocator 실패/rollback 처리는 본문에 없으며, source가 길이 스캔과 실제 복사 사이에 변하지 않는다는 전제를 확인해야 한다. 문자열의 NUL까지 바이트를 복사하는 직접 strcpy 본문은 확인했지만 모든 메모리 fault·alias·동시성 입력을 실행한 것은 아니다.

## 증거와 미완료 경계

본문 10개에서 원본 명령 경계 434개·본문 바이트 1,061개와 직접 분기 목적지를 대조했다. Python 계산은 string hash 10개, 네 번째 byte shift 1,024개, NULL equality scan 4개, pool 크기 6개, WithLength 분기 10개, signed strcmp byte 차이 4개다. 모두 산술 진단이며 원본 실행 표본이 아니다. 입력 해시 35개와 기존 보존 파일 해시 612개가 일치했다.

Ghidra 스킬의 읽기 전용 절차에 따라 디컴파일 반환형과 실제 레지스터·헤더 근거를 분리했다. 원본·reference·DB/export·이전 보고서를 변경하지 않았다. 독립 계획 검토 미수신 상태를 유지하며 신규 실행 코드·복원 소스·GCC 2.7 빌드는 없다.

[원본·산술 증거](strings-evidence.json) · [보존 목록](preservation.json) · [범위](SCOPE.md) · [남은 전체 분석](OPEN_ITEMS.md)
