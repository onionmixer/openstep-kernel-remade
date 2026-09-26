# ObjC 모듈 상위 로드·종료 경로 정적 검토

## 판정

원본의 `kern_serv_load_objc`는 등록 결과를 상위에 전달하지 않는다. 부팅 등록 반복문도 결과 검사 없이 진행한다. 종료 함수는 ObjC 등록 해제 후 서버 자원을 정리하지만, 모듈 이미지 할당의 실제 해제 주체와 시점은 아직 규명되지 않았다. 이 결과는 **본문 수준 정적 분석**이며 실패 입력의 실제 실행 또는 전체 수명 검증이 아니다.

[범위](SCOPE.md), [원본 디코딩·입력 해시·Python 계산](loader-evidence.json), [이전 증거 보존 목록](preservation.json), [남은 분석](OPEN_ITEMS.md)을 함께 보존한다. Ghidra 스킬의 함수·호출자·타입 교차 확인 절차를 보존 export에 적용했다. 원본 DB, export, 참조 소스와 `07_kernel`은 수정하지 않았다.

## 원본 재대조

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.

- 함수 본문 6개, 명령 235개, 본문 607바이트를 원본 디코더와 대조했다. 본문의 바이트 범위가 metadata와 일치하고 중복되지 않음을 확인했다.
- 직접 호출 19개 및 직접 분기 목적지를 ASM과 대조했다. `_probeNativeDevices`의 별도 호출 창은 전체 함수 의미 검증으로 집계하지 않았다.
- 입력 26개를 지문 기록했다. Ghidra 입력은 기존 full-analysis manifest와 일치한다. 참조 소스·외부 SDK 헤더의 현재 해시는 원본 소스 동일성이나 과거 취득 시각을 증명하지 않는다.
- report52 checkpoint 해시와 파일 목록을 확인하고 이전 파일 630개를 재해시했다.
- 초기 진단은 참조 TSV의 `0xStack[0xc]`를 RAM 정수 주소로 변환하려다 중단되었다. 파일 출력 전 실패했으며, 재실행은 필요한 RAM 주소 문자열과 정확히 일치하는 행만 선택했다. 원본 TSV는 변경하지 않았다.

## `kern_serv_load_objc` — 성공 반환과 등록 성공은 다르다

본문 `0x0016c96c`:

1. 첫 인자를 역참조하여 서버 포인터를 얻는다. `void *arg` 자체가 서버 구조체 주소라는 해석은 맞지 않는다.
2. `0x0016c977`: 두 번째 인자인 header를 서버 `+0x4d0`에 먼저 저장한다.
3. `0x0016c980`: `objc_registerModule(header, 0)`을 호출한다.
4. `0x0016c985`: `XOR EAX,EAX` 후 반환한다.

따라서 callee가 정상적으로 제어를 돌려주면 등록 반환값에 관계없이 wrapper 결과는 0이다. callee의 fault·비복귀까지 0 반환으로 단정하지 않는다. 등록이 거절되더라도 header 필드를 원복하는 분기는 이 본문에 없다. report52의 사전 조회 인자 문제를 고려하면 이것을 곧바로 관찰된 실패 사례나 안전한 rollback으로 판정할 수 없다.

보존 Darwin `kernel/kernserv/kern_server.c`의 `kern_serv_load_objc`에는 `KERNOBJC` 조건부 header 저장, `error = objc_registerModule(...)`, 사용되지 않는 `error`, 최종 `KERN_SUCCESS` 반환이 대응된다. OPENSTEP `kern_server_types.h`에도 함수 선언과 `mach_header` 필드가 있다. 이는 대응 근거이지 해당 Darwin 파일을 원본의 정확한 빌드 입력으로 확정하는 근거가 아니다.

## `kern_serv_shutdown` — 정리 순서와 범위

본문 `0x0016cc88`에서 확인한 순서는 다음과 같다. callee들이 제어를 반환한다는 조건의 순서이며 각 하위 서비스의 성공까지 증명하지 않는다.

| 원본 호출 지점 | 동작 |
|---|---|
| `0x0016cca0` | 서버 `+0x4d0`가 nonzero이면 `objc_unregisterModule(header, 0)` |
| `0x0016ccb2` | 로그 레벨 `+0x30`가 nonzero이면 로그 정리; 이후 레벨 0 |
| `0x0016ccd8` | 포트 매핑의 nonzero 포트를 deallocate; 해당 port와 proc만 0 |
| `0x0016cd07`, `0x0016cd14` | 서버 `+0x14`, `+0x1c` 포트를 deallocate |
| `0x0016cd21` | 서버 `+0x20` 포트 집합을 deallocate |
| `0x0016cd2e` | 서버 `+0x44` 메시지 포인터를 `+0x48` 크기로 `kfree` |
| `0x0016cd3c` | 서버 구조체 자체를 `0x4d4` 크기로 `kfree` |
| `0x0016cd48` | 전역 `0x001e8b54`에서 읽은 값을 인자로 `thread_terminate` |
| `0x0016cd50` | `thread_halt_self`를 호출하는 무조건 반복으로 진입 |

포트 반복은 Python 계산으로 50개이다. stride는 `0x10`, 첫 port/proc 오프셋은 `0x18c`/`0x190`, 마지막은 `0x49c`/`0x4a0`이다. 헤더의 `KERN_SERVER_NPORTPROC 50`과 대응한다. 이미 port가 0인 항목은 proc도 새로 지우지 않으며, uarg/type을 지우는 명령은 이 반복문에 없다.

서버 해제 크기는 Python 계산으로 1236바이트이고, `mach_header` 필드의 DWORD 끝은 `0x4d4`이다. 이 경계 대응만으로 헤더 전체 구조체 정렬을 실제 GCC 2.7에서 검증했다고 할 수 없다.

이 본문에는 module header가 가리키는 이미지 할당을 직접 `kfree`/VM 해제하는 호출이 없다. 그렇다고 전체 시스템이 이미지를 해제하지 않는다는 뜻도 아니다. 상위 loader, unregister의 하위 처리 및 대기 중인 참조의 수명을 더 연결해야 한다. header 필드나 호출자의 서버 포인터를 먼저 0으로 만들지 않으므로 중복 shutdown의 안전성도 입증되지 않았다.

본문에는 정상 `RET`가 없다. Darwin 소스와 SDK 선언의 `kern_return_t` 및 소스 끝의 도달 불가능한 `return KERN_SUCCESS`를 보고 실제 정상 반환을 가정하면 안 된다. 반대로 Ghidra의 `void` 추론만으로 복원 선언을 확정하지도 않는다.

Darwin 참조의 종료 순서는 ObjC unregister를 포함하여 대응된다. 보존 NeXTMach `mk-108.1/kernserv/kern_server.c`의 종료 함수에는 이 ObjC 블록이 없고, 같은 파일에서 `kern_serv_load_objc`/`objc_registerModule`도 발견되지 않았다. 이 제한된 파일 비교를 저장소 전체의 부재로 확대하지 않는다.

### 로그 정리 보조 함수

`0x0016d054`는 log 시작 포인터와 끝 포인터의 차이를 전역 page mask로 반올림한 DWORD 크기로 `kfree`에 전달한 뒤 log의 `+4`, `+8`, `+0`을 지운다. 정확한 모듈 이미지 해제 함수라는 근거는 없다. Python 증거에는 DWORD wrap을 명시한 수식을 기록했으며, 실제 page mask·포인터 값 또는 allocator 계약은 이번 단계에서 검증하지 않았다.

## 부팅 등록 반복문 `0x00194890`

`_probeNativeDevices`의 `0x00193f3d`에서 호출된다. 여기서는 그 호출 창만 별도로 대조했다. 전체 device probing 의미는 미완료다.

- 기준 `0x11000`의 `+0x154`, 즉 `0x11154`를 signed count로 검사한다.
- `+0x168 + index*8`, 즉 첫 슬롯 `0x11168`에서 header를 읽는다. 이 부팅 시점 메모리의 실제 descriptor 내용은 원본 Mach-O 파일에서 추정하지 않는다.
- `getsectbynamefromheader(header, "__DATA", "__bss")`의 결과가 있으면 `section.addr`와 `section.size`로 `bzero`한다.
- 이후 `0x001948d9`에서 `objc_registerModule(header, 0)`을 호출한다.
- 결과를 검사하지 않고 index를 증가시키며, count를 다시 읽어 signed 비교로 반복한다.

BSS 초기화는 ObjC 등록보다 앞선다. 등록 실패를 이유로 BSS 변경을 되돌리는 본문 분기는 없다. header NULL 검사, descriptor의 다른 DWORD 사용 또는 descriptor 배열 최대 범위 검사는 이 본문에서 확인되지 않는다. 이 사실만으로 잘못된 입력이 실제 전달된다고 주장하지 않는다.

## Mach-O 섹션 접근 계약

`getsectdatafromheader` (`0x0015c354`)는 검색 성공 시 `section+0x24`를 출력 크기로 쓰고 `section+0x20`을 반환한다. 검색 실패 시 크기와 반환값을 0으로 한다. 반환 주소는 `section.addr`이며 파일 offset, header-relative 주소나 추가 slide 계산 결과가 아니다.

`getsectbynamefromheader` (`0x0015c38c`)는 다음을 수행한다.

- header `+0x1c`에서 시작하여 unsigned `ncmds` 횟수만큼 command를 순회하고 `cmdsize`로 다음 위치에 간다.
- `cmd == LC_SEGMENT`이면 command의 segment 이름을 길이 16으로 비교한다. command 이름 불일치 시에도 `MH_OBJECT`이면 section 검색을 허용한다.
- section은 command `+0x38`에서 시작하고, `+0x30`의 `nsects`를 unsigned로 비교하며 `0x44`씩 진행한다.
- section의 sectname과 segname은 모두 길이 16 비교에서 일치해야 반환된다. `MH_OBJECT`가 section의 segment 이름 검사까지 생략시키지는 않는다.

OPENSTEP `mach-o/loader.h`의 필드와 원본 오프셋을 대조했다. Python의 명시적 i386 폭 계산에서 header/segment/section 크기는 각각 `0x1c`/`0x38`/`0x44`이다. 호스트 `sizeof` 또는 실제 GCC 2.7 컴파일 결과를 사용한 것은 아니다.

이 함수의 Ghidra C에서는 load command 포인터를 `mach_header *`로 잘못 표현하여 `pmVar4->magic`, `pmVar4->cputype`, `pmVar4[1].sizeofcmds`가 나타난다. 원본 오프셋상 각각 command의 **cmd, cmdsize, nsects**이다. 그 C 필드명을 복원 구조체 정의로 채택하면 안 된다.

이 본문에는 Mach-O magic/CPU/`sizeofcmds`, command와 section의 실제 메모리 범위, 최소 `cmdsize` 또는 주소 매핑 유효성 검증이 없다. 검색 helper 자체를 완전한 이미지 validator로 취급할 수 없다. 호출 전 검증이 다른 곳에서 이루어지는지, 입력 주소의 생명주기가 어떻게 보장되는지는 미완료다. `strncmp` 하위 구현 전체도 이번 범위에서 새로 검증하지 않았다.

## 호출자 발견의 한계와 다음 경계

보존 references에는 `0x001d12a8 → kern_serv_shutdown`, `0x001d12bc → kern_serv_load_objc`의 DATA 참조가 있으며 원본 DWORD도 일치한다. 직접 CALL이 없다는 이유로 사용되지 않는 함수라고 판단하지 않는다. 이 단계는 해당 테이블의 실제 dispatch, 메시지 검증 및 포트 권한을 검증한 것이 아니다.

다음 읽기 전용 분석 경계는 dispatch/MIG 입력 계약과 모듈 이미지 매핑·해제 주체다. report52의 사전 조회 인자 불일치, class/category/header 조작과 selector 참조 수명 문제는 그대로 남는다. 신규 독립 계획 검토·동적 실행·GCC 2.7 실빌드 없이 전체 완료를 선언하지 않는다.
