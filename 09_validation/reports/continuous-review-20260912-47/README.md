# NXMap prototype 동일성·재사용과 NXHash 의존 경로

report46에서 미확인으로 남긴 prototype 동일성 callback과 조회·저장 경로를 정적으로 추적했다. **원본 바이트·분기 판독 및 Python 산술 결과이며 실제 cache 생성·삽입 실행 시험은 아니다.**

## 동일성은 기록 내용으로 판단한다

원본 초기 데이터 `1e556c`는 `(1cbf34, 1cbf80, 1cbc00, 0)`이다. 이는 NXMap의 prototype들을 저장할 **NXHash table의 prototype**이며, 개별 NXMap의 key를 처리하는 prototype과 구분해야 한다. 원본 파일에서 cache 포인터 `1e557c`의 초기값은 0이다. 실행 중 상태나 relocation/patch 후 값을 관측한 것은 아니다.

hash callback `1cbf34`는 전달된 기록의 앞선 세 DWORD 각각에 `_NXPtrHash`를 호출하고, 그 결과들과 다음 DWORD(style)를 XOR한다. `_NXPtrHash` `1cbb1c`의 원본은 unsigned DWORD `x`에 대해 `x XOR (x >> 16)`이다. callback의 info는 전달되지만 이 pointer hash 본문에서는 사용하지 않는다.

equality callback `1cbf80`은 두 기록의 offset `0`, `4`, `8`, `c`를 순서대로 비교하고, 하나라도 다르면 0, 모두 같으면 정확히 1을 반환한다. 기록을 보관하는 주소 자체의 동일성이 아니라 callback 주소와 style의 **위치별 동일성**이다. 이 callback 역시 info를 읽지 않는다. 바깥 NXMap 생성자가 style 0만 허용하더라도 비교 callback의 style 검사를 삭제할 근거는 없다.

Python 계산에서 원본 pointer-value prototype `1cde80`의 hash는 `0x1ccb98`, object prototype `1cdea0`의 hash는 `0x1ccac4`다. 앞선 필드들의 위치를 교환하면 XOR hash는 같지만 위치별 equality는 거짓이다. 따라서 hash만 비교해 prototype을 합칠 수 없다. 필드 교환 및 bit 변경 표본은 **산술 진단용 기록**이며 유효한 callback 조합이나 실행 가능한 prototype이라고 주장하지 않는다.

## 조회용 stack 기록과 보관되는 heap 기록

`NXCreateMapTableFromZone`은 cache가 없으면 `1cbff3`에서 `_NXCreateHashTable`을 호출한다. stack에 위 prototype의 DWORD 값들을 전달하고 capacity와 info는 모두 0이다. 따라서 cache의 callback 첫 인자는 map 포인터가 아니라 이 info 값이다.

유효성 검사 후 `1cc02c`에서 전달받은 stack prototype의 주소를 만들고, `1cc037`에서 `_NXHashGet`으로 조회한다. 결과가 nonzero이면 그 기존 기록 주소를 사용한다. 없으면 `1cc047`에서 `0x10` 바이트를 할당하고 `1cc051`, `1cc056`, `1cc05c`, `1cc062`에서 필드들을 복사한다. `1cc06d`에서 cache에 넣은 뒤 `1cc075`에서 map의 prototype 포인터로 연결한다. 이 신규 경로는 HashInsert가 반환한 이전 포인터를 사용하지 않는다.

따라서 정상적인 안정 상태의 조회·삽입 순서에서는 동일한 내용을 가진 prototype을 재사용하며 stack 기록 주소를 map에 영구 보관하지 않는다. 그러나 이것만으로 동시 호출에서 전역 초기화와 get/insert가 원자적이라는 보장은 없다. caller 직렬화·재진입·실패 계약은 미확인이고 경쟁이나 누수를 실제 관찰했다는 주장도 아니다.

## NXHash와 NXMap을 혼동하면 안 되는 부분

| 항목 | 이번 NXHash 경로 | 앞서 분석한 NXMap 경로 |
|---|---|---|
| hash 인자 | `(table.info, data)` | `(table, key)` |
| equality 인자 | `(table.info, query/new, stored)` | `(table, stored, query)` |
| home bucket | hash 결과의 unsigned 나머지 | 별도 hash mixing 후 unsigned 나머지 |
| bucket 표현 | count와 data/포인터 배열 | key/value pair, 빈 key sentinel |
| 충돌 표현 | 같은 bucket 안의 포인터 배열 | bucket 사이의 선형 탐색 |

NXMap 열은 [report44](../continuous-review-20260912-44/README.md), [report45](../continuous-review-20260912-45/README.md)의 근거를 유지한다. 일반 equality는 대칭이라고 추가 가정할 수 없으므로 인자 방향 차이를 보존한다.

`_NXHashGet` `1cb464`는 hash callback(`1cb479`) 뒤 unsigned DIV(`1cb47d`)를 수행한다. bucket의 count가 0이면 NULL, 1이면 직접 보관한 data 포인터를 비교한다. count가 더 크면 pointer array를 앞에서부터 조사한다. pointer identity가 일치하면 equality 호출을 생략하고, 아니면 `(info, query, stored)`로 호출한다(`1cb4b3`, `1cb4df`). 발견 시 반환하는 것은 query가 아니라 **저장된 포인터**다.

`_NXHashInsert` `1cb5c8`도 hash와 modulo를 사용한다. 빈 bucket에는 data 포인터를 직접 넣고 count를 올린 후 0으로 반환하며 growth 검사로 가지 않는다. 점유 bucket에서 같다고 판정하면 기존 포인터를 반환하면서 저장 위치를 새 포인터로 바꾼다(`1cb653`, `1cb6bf`). prototype의 free callback을 직접 호출하지 않는다. 즉 HashInsert 자체는 기존 포인터 보존형 interning API가 아니다.

단일 항목에서 충돌하면 `_NXZoneCalloc(zone, 2, 4)`로 배열을 만들고 `[new, old]` 순서로 보관한다. 이미 배열이면 같은 항목을 찾아 그 slot만 교체하거나, 새 배열의 앞에 new를 두고 기존 배열을 뒤에 복사한 후 old array를 해제한다(`1cb6f8`, `1cb709`). 이 해제는 **컨테이너 배열** 해제이지 entry callback 해제가 아니다. 충돌 신규 삽입 경로는 total count가 bucket 수보다 클 때 `1cb725`에서 growth helper `1cb504`를 호출한다. 그 helper의 내부 계약은 이번 범위 밖이다.

## cache 생성 내부와 수명에 대한 제한

`_NXCreateHashTable` wrapper `1cafec`는 기본 zone을 얻고 prototype 값·capacity·info·zone을 `1cb020`에 전달한다. `_NXCreateHashTableFromZone`은 본체 `0x14` 바이트를 할당한 뒤, 별도 전역 `1e5554`가 없으면 `1caf74` bootstrap을 호출한다. `1e5554`는 NXMap cache `1e557c`와 다른 전역이다.

이 생성자는 NULL hash/equality/free를 각각 `1cbb1c`, `1cbb7c`, `1cbc00`으로 보충하고 style을 검사한다. prototype을 별도 cache에서 조회하고, 없으면 기록을 복사·삽입한 뒤 다시 조회한다. 따라서 cache의 prototype 포인터가 원본 literal 주소 `1e556c` 자체라고 가정해서는 안 된다. 이후 count 0, info(`1cb0f4`), capacity helper 결과와 bucket 배열을 설정한다. sizing helper `1caebc`/`1caedc`와 bootstrap 내부는 이번에 검증하지 않았다.

`1cb098`에서 size를 push한 뒤 기본 zone 호출을 거쳐 zone을 push하고 allocator를 호출하는 `1cb0a3`의 stack을 확인했다. 디컴파일 표현에서 기본 zone 함수에 size 인자가 붙거나 allocator 인자가 누락돼 보여도 원본 stack에 남은 size를 무시하면 안 된다. 정확한 GCC 2.7 aggregate ABI 시험은 아직 없다.

cache prototype의 free callback `_NXNoEffectFree` `1cbc00`은 인자를 읽거나 EAX를 설정하지 않는 반환 본문이다. NXMap의 별도 no-effect callback `1ccb3c`와 주소·API를 구분한다. `NXFreeMapTable` `1cc108`은 reset, bucket 해제, table 해제를 호출하며 공유 prototype 기록을 직접 해제하지 않는다. 그러나 이를 전역 cache가 절대 해제되지 않거나 전체 수명·자원 회수가 검증되었다는 뜻으로 확대하지 않는다. 선택한 metadata 참조 역시 간접 alias·teardown의 완전한 부재 증거가 아니다.

## 근거와 완료 범위

본문 10개의 원본 명령 경계 520개, 본문 바이트 1,286개를 대조하고 직접 분기/call 목적지를 확인했다. 이것은 모든 명령의 의미나 모든 실행 경로를 자동 검증했다는 뜻이 아니다. Python 산술 기록 14개, 입력 해시 34개, 이전 보존 파일 해시 594개를 확인했다.

Ghidra 스킬에 따라 보존 ASM/C/metadata와 원본 바이트의 읽기 전용 비교를 사용했다. 원본·reference·DB/export·이전 보고서는 수정하지 않았다. 독립 계획 검토를 받은 것으로 간주하지 않았고 신규 동적 시험 프로그램·복원 코드·GCC 2.7 빌드도 없다. 로컬 `hashtable2.h`의 NXHash 선언은 확인했지만 이를 누락된 NXMap 원본 선언의 대체 증거로 사용하지 않는다.

[원본·산술 증거](prototype-evidence.json) · [보존 목록](preservation.json) · [범위](SCOPE.md) · [남은 분석](OPEN_ITEMS.md)
