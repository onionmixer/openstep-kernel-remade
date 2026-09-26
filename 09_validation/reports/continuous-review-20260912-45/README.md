# NXMap 삽입·삭제·확장의 정적 계약

원본 NXMapInsert, NXMapRemove, 확장 helper와 reset/free 연결을 대조했다. 이번 결과는 **원본 정적 분석과 후속 실행 후보**이며 새 emulator 실행이나 전체 동작 검증을 수행한 결과가 아니다.

## 삽입과 교체

`NXMapInsert`의 hash 호출(`1cc4fb`)과 bucket 계산/DIV(`1cc51a`)는 invalid key 비교(`1cc52c`)보다 먼저다. 따라서 key가 sentinel `0xffffffff`이면 callback 실행 전 안전하게 거부된다고 해석하면 안 된다. 앞선 처리가 반환한 뒤에야 오류 메시지와 반환 경로에 도달한다.

| 분기 | 원본 동작 |
|---|---|
| 첫 bucket이 비어 있음 | key/value 기록, count 증가 후 바로 0 반환. 이 분기에는 확장 비율 검사가 없음 |
| 기존 key와 pointer/equality 일치 | 기존 key와 count 유지. value가 다르면 value만 교체하고 이전 value 반환 |
| 첫 bucket 불일치이고 count가 bucket 수와 같음 | 확장 helper 호출 후 hash부터 다시 시작 |
| 충돌 탐색 중 같은 key 발견 | 그 bucket의 value만 필요 시 교체하고 이전 value 반환 |
| 충돌 탐색 중 빈 bucket 발견 | 새 쌍을 원래 home bucket부터 삽입하면서 기존 쌍들을 다음 bucket으로 밀어 빈 bucket까지 이동 |
| 충돌 삽입 완료 | count 증가 후 `4*count`와 `3*bucket_count`의 unsigned 비교; 클 때 확장 |

원본의 pair 이동은 `1cc634..1cc647`에서 기존 key/value를 먼저 저장하고 새 쌍을 기록한 뒤 저장한 쌍을 다음 반복으로 전달한다. 단순히 처음 발견한 빈 bucket에 새 쌍을 놓는 알고리즘으로 바꾸면 같은 저장 순서를 보장하지 못한다.

교체 경로는 기존 key를 새 key로 바꾸지 않는다. equality가 참인 별도의 key 객체를 전달했더라도 저장 key는 유지된다. 이 경로에는 prototype의 free callback 호출이 없으며 새 key/이전 value를 자동 해제하지 않는다. 다만 hash/equality 사용자 callback 자체의 부작용은 별도 문제다. 반환 0만으로 새 삽입, 이전 NULL value 교체, 오류를 모두 구분할 수도 없다.

확장 비교를 모든 삽입에 일괄 적용하거나 항상 같은 load factor가 유지된다고 가정하지 않는다. 식의 곱셈은 실제 32-bit 연산이며 큰 크기의 overflow·도달성 검증도 아직 남아 있다.

## 삭제는 충돌 구간을 재구성한다

`NXMapRemove`는 hash의 home bucket부터 빈 bucket 또는 시작점으로 돌아올 때까지 연속 구간을 조사한다. 첫 일치에서 즉시 끝내지 않고 일치 수와 반환할 value를 기록한다. 일치가 없으면 0으로 반환한다. 이때도 통계 및 callback 부작용까지 없다고 주장하지 않는다.

안정적인 equality와 정확히 한 일치가 있는 정상 전제에서의 순서는 다음과 같다.

1. 충돌 구간 길이와 일치를 조사한다.
2. 두 번째 순회에서 equality를 다시 평가하며 남길 쌍들을 임시 저장한다.
3. 구간의 각 bucket을 `(0xffffffff, 0)`으로 비운다.
4. table count에서 구간 길이를 뺀다.
5. 저장한 생존 쌍들을 **역순으로 NXMapInsert에 전달**한다.
6. heap 임시 저장소를 사용했다면 해제하고 기록한 이전 value를 반환한다.

이는 tombstone 하나만 남기거나 뒤의 항목을 한 칸씩 당기는 단순 삭제와 다르다. 두 번째 equality 호출이 있다는 점도 중요하다. 일치 수나 생존 수가 예상과 다르면 오류 로그 호출이 있지만, 그 뒤 코드가 계속되는 경로가 있다. 진단을 rollback이나 입력 복구로 해석하지 않는다. callback의 일관성·재진입·동시 수정에 대한 전제가 필요하다.

임시 저장소의 경계도 원본 비교를 따른다.

| 충돌 구간 길이 | 한 일치일 때 생존 쌍 | 필요한 payload | 실제 분기 |
|---:|---:|---:|---|
| 16 | 15 | 120바이트 | stack scratch |
| 17 | 16 | 128바이트 | heap malloc |

원본 stack scratch 영역은 128바이트지만 분기는 구간 길이 `<=16`이다. 생존 payload가 stack에 들어갈 것 같다는 이유로 17을 stack 경로로 바꾸면 원본과 달라진다. heap 크기는 `(구간 길이-1)*8`이며 callback 일관성과 allocator 성공을 실제로 검증한 것은 아니다.

삭제 본문은 prototype의 free callback을 직접 호출하지 않는다. `_free` 호출의 직접 대상은 heap scratch다. 그러나 재삽입의 내부 확장으로 이전 bucket 배열이 해제될 수 있으므로 전체 호출 수명을 scratch 해제만으로 설명해서는 안 된다.

## 삭제 중 확장 가능성 — 실행 전 후보

삭제의 재삽입 호출(`1cc98d`)은 원본 NXMapInsert이며 그 안의 확장 분기가 그대로 적용된다. 따라서 삭제가 bucket 수·bucket 배열 주소를 보존한다는 일반 계약은 현재 근거로 확정할 수 없다.

다음은 pointer callback의 hash를 Python으로 계산해 고른 **정적 예측용 후보이며 실행하지 않았다**.

- 초기 bucket 수: 7.
- 삽입 key 순서: `0, 7, 1, 5, 2, 6, 3`.
- 각 home bucket: `0, 0, 2, 3, 4, 5, 6`.
- 삭제 key: `3`.

읽은 원본 분기를 따르면 앞선 충돌로 저장 순서가 바뀌고, 삭제의 역순 재삽입 마지막 충돌 단계에서 count 6에 대한 비교 `24 > 21`이 성립할 것으로 예상한다. 이 예상은 유효 초기 table, 안정적인 pointer callback, 성공하는 할당, 비재진입·비동시 수정 전제에 의존한다. 원본 실행으로 확장을 관찰한 결과나 커널 오류 발견으로 표현하지 않는다.

## 확장·reset·free의 소유권

확장 helper `1cc3f8`은 이전 bucket 배열·count·bucket 수를 보관하고 bucket 수를 `2*N+1`로 바꾸며 count를 0으로 만든다. 새 배열을 할당·초기화한 뒤 table에 연결하고, 이전 배열을 순서대로 조사하여 점유 항목을 NXMapInsert로 재삽입한다. count를 비교한 뒤 이전 배열을 `_free`한다. 불일치 진단은 별도 rollback으로 이어지지 않는다.

metadata 변경은 할당 호출보다 앞서 있다. 이 사실만으로 allocator 실패 동작을 단정하지 않으며, 원본 allocator의 실패 계약을 확인하기 전 실패 원자성이나 복원 동작을 추가 가정하지 않는다.

호출되는 `NXZoneFromPtr`의 현재 원본 본문(`1cdefc`)은 인자를 조사하지 않고 고정 주소 `1e55e4`를 반환한다. 초기 allocator 슬롯 `1e55e8`은 `1cdec4`를 가리키며 해당 wrapper는 크기 인자를 `_malloc`에 전달한다. Ghidra는 이 wrapper를 void로 표시하지만 원본은 EAX를 전달하고 확장 호출자는 이를 새 배열 주소로 사용한다. 현재 커널 구현을 일반적인 pointer-to-zone 검색으로 대체해서는 안 된다.

확장 통계 갱신 `1cc476..1cc479`는 count를 0으로 설정한 후 그 현재 필드를 읽는다. 과거 count를 더하도록 임의로 정리하지 않는다. 외부 호출의 재진입·부작용을 검증하지 않았으므로 모든 runtime 조건에서의 통계 값까지 확정하지 않는다.

`NXFreeMapTable`은 먼저 NXResetMapTable을 호출하고, bucket 배열과 table 본체를 차례로 `_free`한다. reset은 각 점유 bucket에 prototype free callback을 호출하는 경로다. 따라서 insert/replace/remove/rehash와 reset/free의 key/value 소유권 동작을 같은 것으로 취급하면 안 된다.

## 근거와 검증 한계

본문 8개, 원본 명령 574개, 본문 바이트 1,674개를 대조했고 간접 호출 9곳의 정적 역할을 분류했다. 입력 28개와 이전 보존 파일 582개의 해시를 확인했다. 모든 주소·크기·개수·경계 식은 Python으로 계산했다.

Ghidra 스킬을 사용해 보존 ASM/C를 읽기 전용으로 대조했다. 원본·DB·export·이전 보고서를 변경하지 않았다. 신규 동적 시험, 복원 코드, GCC 2.7 빌드는 수행하지 않았으며 코딩 전 독립 검토 미수신 상태도 유지한다.

[원본·호출·계산 근거](mutation-evidence.json) · [보존 목록](preservation.json) · [검토 범위](SCOPE.md) · [남은 전체 분석](OPEN_ITEMS.md)
