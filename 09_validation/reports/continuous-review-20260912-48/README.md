# NXHash bootstrap·확장·순회·정리의 원본 계약

report47의 의존 경로를 이어서 원본 명령과 보존된 디컴파일 출력을 대조했다. **정적 분석이며 실제 cache 초기화·rehash·해제를 실행한 결과가 아니다.**

## 디컴파일의 순회 상태 반환 누락

`NXInitHashState` `1cbaa0`의 Ghidra C 출력은 `undefined4` 반환과 table의 bucket 수만 보여준다. 그러나 원본은 `1cbaac`에서 EAX에 bucket 수, `1cbaae`에서 EDX에 0을 넣고 반환한다. 확장 함수의 caller는 `1cb55b`와 `1cb55e`에서 **두 레지스터를 인접한 stack DWORD에 각각 저장한다.**

metadata가 가리키는 직접 호출 지점 8개 모두에서 원본 call과 뒤따르는 명령을 읽었다. 모두 EAX와 EDX를 저장하는 형태였다. 이것은 선택한 call 주변의 근거이지 caller 전체의 의미 검증이나 간접 호출 전수조사는 아니다.

로컬 `hashtable2.h`는 `NXHashState`를 `int i; int j;`의 구조체로 선언하며 생성 함수의 반환형도 그 타입이다. 따라서 현재 C 출력만 따라 scalar 반환으로 복원하면 상태의 일부를 잃는다. 원본의 레지스터 반환 증거와 선택할 GCC 2.7의 실제 구조체 반환 ABI 시험은 별개이며 후자는 미수행이다. 기존 export는 수정하지 않았다.

## prototype cache의 자기 등록 초기화

원본 초기 데이터 `1e5544`는 `(1caef4, 1caf40, 1cbc00, 0)`이고 전역 cache 포인터 `1e5554`는 0이다. hash/equality callback은 report47의 NXMap prototype cache용 callback과 별도 entry이지만, 본문에서 같은 위치별 기록 hash/equality 계산을 수행한다. 주소가 다르므로 단순히 같은 함수 포인터라고 취급하지 않는다.

bootstrap `1caf74`는 `_malloc(8)`과 해당 반환 포인터의 `_free`를 먼저 호출한다. 이 호출의 목적이나 제거 가능성은 확인하지 않았으므로 불필요한 코드로 간주하지 않는다. 이후 기본 zone allocator에 본체 `0x14` 바이트를 요청하고 `1caf99`에서 전역 포인터를 저장한다. 이는 본체 필드와 bucket 초기화가 모두 끝난 후의 마지막 공개가 아니다.

본체 prototype은 static 기록 `1e5544`, count와 bucket 수는 각각 1이다. `_NXZoneCalloc(zone, 1, 8)` 결과를 연결하고 info를 0으로 설정한다. 유일한 bucket의 count를 1로, 그 data 포인터를 다시 `1e5544`로 설정한다. 즉 별도의 일반 생성자를 재귀 호출해 시작하는 대신 **자기 prototype을 이미 포함한 table을 직접 구성한다.**

기본 zone 호출 전에 stack에 남겨 둔 size/count 인자들은 이어지는 allocator/calloc 호출에 사용된다. Ghidra C에서 `_NXDefaultMallocZone(0x14)` 또는 `_NXDefaultMallocZone(1,8)`처럼 보이는 표현을 실제 원본 함수 선언으로 채택하지 않는다. 할당 실패 처리와 전역 공개의 동시성 안전성을 이 본문만으로 보장하지 않는다.

## capacity와 확장 크기

생성자 `1cb020`의 연결은 [report47](../continuous-review-20260912-47/README.md)에 있다. `1caebc`는 unsigned 입력이 1 이하이면 0, 그 외에는 논리적 우측 shift 후 재귀 결과에 1을 더한다. 생성자가 이 결과에 1을 더해 `1caedc`에 전달하면, 그 helper는 x86의 masked shift와 DWORD 감산으로 bucket 수를 계산한다.

Python 계산상 capacity 0/1은 bucket 1, 2/3은 3, 4/7은 7, 8/15는 15, 16은 31이다. 높은 bit의 입력은 shift count가 wrap하여 0 bucket을 만들 수 있다. 큰 입력의 메모리 할당이나 이후 DIV 경로를 실행하지 않았으며, 이 입력들이 합법적인 caller에서 실제 도달한다고 주장하지 않는다.

growth `1cb504`는 기존 bucket 수 N을 `2*N+1`의 DWORD 결과로 바꾸고 count를 0으로 설정한 뒤 `_NXZoneCalloc(zone, newN, 8)`을 호출한다. 단순히 `2*N`으로 확장하지 않는다. 증거의 크기 곱셈은 Python 산술일 뿐 calloc의 overflow 검출·실제 할당 성공을 검증한 결과는 아니다.

## 확장 중 임시 본체와 재삽입 순서

growth는 먼저 zone allocator에서 임시 본체 `0x14` 바이트를 얻어 기존 table의 prototype, count, bucket 수, bucket 포인터를 복사한다(`1cb524`, `1cb529`, `1cb52f`, `1cb535`). 본문에는 임시 본체의 info 위치 `+0x10`을 복사하거나 초기화하는 store가 없다. 전체 NXHashTable을 완전히 복제하는 동작으로 요약해서는 안 된다.

살아 있는 원래 table의 크기·count·bucket을 바꾼 뒤, 임시 본체를 `NXInitHashState`와 `NXNextHashState`로 순회하여 각 data 포인터를 원래 table의 `NXHashInsert`로 재삽입한다(`1cb57f`). entry 자체를 deep copy하지 않는다. hash/equality와 info는 재삽입 대상인 원래 table의 것을 사용한다. 임시 본체의 iterator는 bucket 필드를 사용하며 info를 읽지 않는다.

재삽입 뒤 `1cb58f`에서 정리 helper를 flag 0으로 호출한다. 이 helper는 임시 본체의 `+0x10`을 읽어 인자로 전달하지만 free callback을 고정 `_NXNoEffectFree`로 선택하고, 해당 원본 callback은 그 인자를 읽지 않는다. **임시 info가 0이라는 증거는 없지만 이 경로가 임의의 사용자 free callback에 그 값을 넘기는 경로도 아니다.** 이 구분을 유지하며 실제 할당 메모리의 값이나 C 수준의 안전한 복원 표현까지 검증한 것으로 간주하지 않는다.

정리 helper는 bucket 내용만 정리하고 table의 total count는 바꾸지 않는다. 그래서 `1cb597`의 임시 count는 여전히 재삽입 전 count이며, 새 count와의 비교가 의미를 가진다. 다르면 로그를 호출한 뒤에도 old bucket 배열과 임시 본체 해제로 진행한다. 원상복구·실패 반환 경로가 있다고 추가하지 않는다.

## iterator와 정리 순서는 서로 다르다

`NXNextHashState` `1cbab8`는 상태의 j가 0이면 i가 0인지 검사한 뒤 i를 감소시키고 bucket count를 j로 가져온다. 항목을 반환할 때 j를 감소시키므로 **bucket index는 높은 쪽부터, 충돌 배열 index도 높은 쪽부터** 진행한다. 단일 항목 bucket은 직접 data 포인터를 반환한다.

정상 종료 상태는 `(i, j) = (0, 0)`이며 이 상태에서는 다시 호출해도 감소·출력 store 없이 0으로 반환하는 분기다. 이는 종료 cursor를 다시 감소시키는 NXMap의 원본과 다르다. 불변의 정상 table/state를 전제로 한 정적 판독이며, 변경 중 순회나 잘못된 state까지 허용한다는 보장은 아니다. 종료 경로는 output을 지우지 않는다.

반대로 정리 helper `1cb174`는 bucket을 낮은 index부터 처리하고, 항목별 helper `1cb124`도 충돌 배열을 앞에서부터 처리한다. 증거 JSON에는 bucket count `[2, 0, 1, 3]`인 상징적 예의 index 순서를 Python으로 계산했다. 메모리를 구성하거나 원본 명령을 실행한 fixture가 아니다.

## Empty / Reset / Free의 소유권 차이

| 원본 API | 항목 callback | 충돌 포인터 배열 | bucket 배열·본체 | total count 처리 |
|---|---|---|---|---|
| `NXEmptyHashTable` `1cb200` | 고정 no-effect callback | 해제 | 유지 | 정리 뒤 0 |
| `NXResetHashTable` `1cb220` | prototype의 free callback | 해제 | 유지 | 정리 뒤 0 |
| `NXFreeHashTable` `1cb1d8` | prototype의 free callback | 해제 | 모두 해제 | 해제 전 별도 0 store 없음 |

정리 helper는 count가 nonzero인 bucket에서만 항목별 정리를 호출하고, **callback과 배열 해제가 돌아온 뒤** 해당 bucket의 count/data 필드를 0으로 만든다(`1cb1b3`, `1cb1b9`). 이미 빈 bucket에는 이 store를 하지 않는다. 항목별 helper는 count 1이면 `(info, data)` callback만 호출하고, 배열이면 같은 인자로 각 항목을 처리한 뒤 배열 주소를 `_free`한다(`1cb165`). 따라서 Empty가 entry를 해제하지 않는다는 설명을 컨테이너 메모리도 전혀 해제하지 않는다는 의미로 확대하면 안 된다.

Reset/Empty는 total count를 모든 정리가 끝난 뒤에 바꾼다. callback이 실행되는 동안 이미 완전히 비워진 table 상태라고 가정하지 않는다. callback이 원래 구조를 바꾸거나 재진입하는 경우의 안정성은 별도 검증 대상이다.

Free는 prototype 기록 자체를 직접 해제하지 않는다. prototype cache의 no-effect free와 static 자기 등록 기록을 일반 소유 entry처럼 해제하는 복원은 원본과 다르다. 다만 전역 cache의 모든 alias·종료 경로와 기록의 전체 수명까지 검증한 것은 아니다.

## 증거와 판정

본문 15개의 원본 명령 경계 377개·본문 바이트 890개와 직접 분기 목적지를 대조했다. 별도로 직접 caller 8개의 제한된 주변 명령 40개를 읽었다. 이 집계는 중복을 제거한 전체 kernel coverage가 아니다. capacity 산술 14개, growth 산술 7개와 상징적 순회 순서는 모두 Python 계산이다. 입력 해시 49개와 이전 보존 파일 해시 600개가 일치했다.

Ghidra 스킬에 따라 보존 ASM/C와 원본 레지스터·caller 근거를 구분하여 반환형 누락을 기록했다. 원본·reference·DB/export·이전 보고서를 변경하지 않았고, 독립 계획 검토 통과나 동적 검증을 주장하지 않는다. 신규 실행 코드·복원 소스·실제 GCC 2.7 빌드는 없다.

[원본·계산 근거](lifecycle-evidence.json) · [보존 목록](preservation.json) · [범위](SCOPE.md) · [미완료 분석](OPEN_ITEMS.md)
