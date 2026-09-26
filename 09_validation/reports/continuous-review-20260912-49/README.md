# NXHash 삭제·조건부 삽입·복사·비교의 원본 계약

원본 ASM/C와 바이트를 대조해 report48의 후속 경로를 연결했다. **정적 분기 판독과 Python 산술이며 실제 table을 생성하거나 원본을 실행한 시험은 아니다.**

## membership을 Get 반환값으로 대체할 수 없다

`NXHashMember` `1cb3bc`는 `(info, query)` hash를 호출한 뒤 unsigned modulo로 bucket을 선택한다(`1cb3d1`, `1cb3d5`). bucket count가 0이면 0, 점유 bucket에서 pointer identity 또는 `(info, query, stored)` equality가 성립하면 정확히 1을 반환한다. equality callback의 임의 nonzero 결과를 그대로 반환하는 것이 아니라 0/1로 정규화한다. 충돌 배열은 앞에서부터 조사한다.

원본 `NXPtrPrototype` 초기 기록 `1cde40`은 `(1cbb1c, 1cbb7c, 1cbc00, 0)`이다. pointer hash는 NULL에도 단순 정수 연산으로 0을 만들고, pointer equality는 pointer 값을 비교할 뿐 역참조하지 않는다. 이 equality의 원본 `SETZ AL` 뒤 `AND EAX,0xff`는 정확한 0/1 반환이며 Ghidra의 현대 `bool` 타입을 그대로 GCC 2.7 선언으로 채택하지 않는다.

정상적인 nonzero bucket 수와 안정된 pointer-prototype table에서 **count가 1이고 저장 data가 NULL인 bucket**을 조건으로 삼으면, NULL query의 Member는 1이지만 Get은 저장 포인터인 0을 반환한다. 빈 bucket과 달리 항목은 존재한다. Remove도 성공하면서 반환 포인터는 0일 수 있다. 따라서 `Member = (Get != NULL)`이나 `Remove 반환 0 = 반드시 삭제 실패`는 원본 전체 입력에 대한 등가 변환이 아니다.

이는 명시한 상태의 원본 분기 결과이며 실제 caller가 NULL을 저장하는 장면을 관찰했다는 뜻은 아니다. 포인터가 아닌 다른 prototype이 NULL을 처리한다는 일반 보장도 아니다. 증거 JSON은 이 전제를 기록하고 runtime 성공으로 표시하지 않는다.

## InsertIfAbsent는 일반 Insert와 다르다

`NXHashInsertIfAbsent` `1cb738`는 hash/modulo와 zone 조회 후 bucket을 처리한다. 이미 같은 항목이 있으면 기존 포인터를 반환하고 저장 위치는 바꾸지 않는다(`1cb7bd`, `1cb832`). [report47](../continuous-review-20260912-47/README.md)의 일반 Insert는 기존 포인터를 반환하면서 저장 slot을 새 포인터로 교체하므로 같은 API로 합치면 안 된다.

빈 bucket에는 새 data를 직접 저장하고 bucket/total count를 증가시킨 뒤 **새 data 포인터**를 반환한다(`1cb788`에서 `1cb89e`로 이동). 이 경로는 growth 비교를 건너뛴다. 기존 단일 항목과 충돌하면 `[new, old]` 배열을 만들고, 기존 배열과 충돌하면 새 data를 앞에 두고 기존 배열을 뒤에 복사한 뒤 old array를 해제한다. 충돌 신규 삽입은 total count가 bucket 수보다 클 때 growth `1cb504`를 호출한다(`1cb899`).

일반 Insert의 신규 삽입 반환값 0과 달리 IfAbsent는 신규 data를 반환한다. 기존 data가 NULL이면 기존 항목을 발견해도 반환값은 0이다. 이름에 IfAbsent가 있다고 해서 caller 동시성까지 보장하는 원자적 연산으로 간주하지 않는다. 직접 본문에 entry free callback을 호출하는 경로는 없지만 hash/equality의 사용자 효과는 별도다.

## Remove의 bucket별 전환

`NXHashRemove` `1cb8ac`는 먼저 `(info, query)` hash와 unsigned modulo를 수행하고 zone을 조회한다. bucket count가 0이면 NULL이다. equality 방향은 `(info, query, stored)`이며 pointer identity 일치 시 equality 호출을 생략한다.

| 삭제 전 bucket count | 같은 항목 발견 시 원본 처리 | 해제 대상 |
|---|---|---|
| 1 | 저장 포인터를 반환용으로 보존하고 total/bucket count 감소, data 필드 0 | 별도 배열 없음 |
| 2 | 배열 앞 항목부터 비교, 남은 포인터를 bucket에 직접 저장하고 count 감소 | 기존 포인터 배열 |
| 3 이상 | 배열 앞에서부터 첫 일치를 찾고, 제외한 항목들을 새 배열에 순서대로 복사 | 기존 포인터 배열 |

count 2 경로는 남은 포인터를 bucket에 먼저 저장한 뒤 `_free(oldarray)`를 호출하고 count를 감소시킨다(`1cb975`/`1cb9ae`, `1cb9b8`, `1cb9c0`, `1cb9c3`). 순서까지 보존하며 callback·allocator 재진입 중간 상태를 임의로 안정된 완료 상태로 바꾸어 설명하지 않는다.

일반 배열 경로는 **처음 일치한 저장 포인터**를 반환용으로 보존한다. query 포인터가 별도 동등 객체인 경우 query가 아니라 저장된 포인터를 돌려준다. 이후 현재 bucket count를 다시 읽어 작은 배열을 할당하고 prefix/suffix를 복사한다. old array 해제 뒤 total/bucket count를 감소시키고 새 배열을 공개한다(`1cba6f`, `1cba77`, `1cba7a`, `1cba7c`).

안정된 count N과 삭제 index i에서 원본의 남은 loop counter는 `N-1-i`이다. prefix는 `4*i` 바이트, suffix는 `4*(N-1-i)` 바이트이며 old offset `4*(i+1)`에서 new offset `4*i`로 복사한다. Python으로 count 3부터 10의 각 삭제 위치에 대해 이동 범위와 순서 보존을 계산했다. 첫/마지막 항목은 대응하는 memmove를 건너뛴다. 실제 메모리 복사나 allocator 성공 시험은 아니다.

원본은 일반 배열 경로에서도 bucket count를 다시 읽고 1인지 검사하는 분기를 포함한다(`1cb9ff`). callback이 구조를 변경하지 않는 정상 전제에서의 분석과 별도로 이 분기를 보존하며, 도달 불가능하다고 삭제하지 않는다. 수정 중 callback의 안정성·도달성은 미확인이다.

이 Remove 본문에는 entry free callback, 재삽입 또는 전체 bucket 수 축소 호출이 없다. 배열 저장 용량을 줄이는 것과 hash table의 bucket 수를 줄이는 것은 다르다. NXMapRemove의 cluster 재구성·재삽입 동작을 여기에 적용하지 않는다. 항목이 없으면 자체 저장 변경 없이 NULL 경로로 가지만 hash/equality와 zone 조회까지 없었다는 뜻은 아니다.

## Copy는 포인터 공유를 유지한다

`NXCopyHashTable` `1cb328`은 source iterator 상태를 먼저 얻고, source의 zone으로 새 본체 `0x14` 바이트를 할당한다. prototype 포인터를 공유하고 count는 0, **info는 source에서 복사**하며 초기 bucket 수를 source와 같게 설정한다(`1cb354`, `1cb356`, `1cb360`, `1cb366`). 이는 report48의 rehash용 임시 본체가 info를 복사하지 않는 것과 다르다.

새 bucket 배열을 할당한 뒤 source를 순회하여 같은 data 포인터들을 `NXHashInsert`로 넣는다(`1cb382`, `1cb393`). 본문에 data 객체 복제·retain·새 prototype 복제 호출은 없다. 단순한 bucket 배열의 byte copy도 아니다. 순회와 hash/equality가 실행되므로 callback 효과와 source 안정성 전제를 유지한다.

복사 결과는 entry 포인터와 free callback/정보를 공유한다. 두 table을 해제할 때 caller의 소유권 정책이 필요하며, 이것만으로 실제 이중 해제가 발생했다고 결론내리지 않는다. allocation 실패·중간 rollback과 연속 실행은 별도 미완료다.

## 비교 entry들의 같은 구현과 선언의 한계

`NXIsEqualHashTable` `1cb240`과 `NXCompareHashTables` `1cb2b4`는 서로 다른 원본 주소의 함수다. Python에서 내부 branch 목적지만 entry-relative offset으로 정규화하고 외부 call 목적지·나머지 operands를 유지하여 비교한 결과 명령열이 같았다. 같은 함수 포인터나 linker alias라는 뜻은 아니다.

양쪽은 table 포인터가 같으면 1, 다르면 Count 결과를 비교한다. count가 같을 때 A를 순회해 B의 `NXHashMember(B, item)`로 모든 항목을 조회하며, 없으면 0, 순회 종료면 1이다. prototype 포인터·info·bucket 수 자체를 비교하지 않는다. B의 callback을 사용하는 한 방향 membership 검사이므로 서로 다른 또는 비대칭 prototype까지 수학적 대칭성을 보장한다고 추가 가정하지 않는다. `NXCountHashTable`은 `+0x4` 필드의 단순 read이며 유효 count를 재계산하지 않는다.

로컬 `hashtable2.h`에는 `NXCompareHashTables`의 BOOL 반환 선언이 있으나 `NXIsEqualHashTable` 선언은 없다. 본문 동일성만으로 누락된 이름의 정확한 원본 공개 선언·출처까지 확정하지 않는다. GCC 2.7에서 실제 typedef와 호출 ABI를 확인해야 한다.

선택한 metadata 직접 참조는 조건부 삽입을 `NXUniqueStringNoCopy`의 `1cbe46`에 연결한다. 이 caller의 전체 의미는 이번에 분석하지 않았으며 다음 원본 caller 추적 대상으로 남긴다. 다른 검색 결과나 참조 부재를 간접 호출의 부재 증거로 사용하지 않는다.

## 검증 범위

본문 12개에서 명령 경계 804개·본문 바이트 1,921개와 직접 분기 목적지를 대조했다. 비교 명령열 정규화는 50개 명령, 삭제 배열 이동 산술은 52개 표본이다. 입력 해시 41개와 이전 보존 파일 해시 606개가 일치했다. 이 수치는 선택 범위의 진단이며 전체 의미 검증 coverage가 아니다.

Ghidra 스킬의 읽기 전용 흐름으로 원본·디컴파일 타입·조건부 해석을 분리했다. 모든 계산은 Python이며 기존 원본·reference·DB/export·보고서를 수정하지 않았다. 독립 계획 검토 미수신 상태를 유지하고 신규 실행/검증 코드·복원 소스·GCC 2.7 빌드를 진행하지 않았다.

[원본·계산 증거](operations-evidence.json) · [보존 목록](preservation.json) · [범위](SCOPE.md) · [남은 분석](OPEN_ITEMS.md)
