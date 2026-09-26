# NXMap 생성·순회·비교의 원본 정적 계약

생성 함수와 capacity 보조 함수, count/iterator/compare의 원본 명령을 대조했다. **정적 계약과 경계 계산 결과이며 실제 객체를 생성하거나 순회한 시험은 아니다.**

## 생성 순서와 오류 반환

`NXCreateMapTableFromZone`은 먼저 zone allocator로 table 본체의 `0x10` 바이트 할당을 요청한다(`1cbfc3`). 이후 전역 prototype 조회용 hash table이 없으면 생성하고, 그 다음에야 전달받은 prototype의 앞선 세 DWORD가 nonzero이고 다음 DWORD가 zero인지 확인한다(`1cc000..1cc016`).

검사를 통과하면 prototype 조회 결과를 재사용하거나 별도 기록을 할당해 전달받은 네 DWORD를 저장하고 hash table에 삽입한다. 그 결과를 table에 연결하고 count를 0으로 설정한 뒤 capacity 변환, bucket 배열 할당·초기화로 진행한다. 실제 prototype 동일성 판단 callback과 정확한 typedef는 아직 별도 검증 대상이다.

잘못된 prototype의 오류 경로는 로그 호출 후 NULL로 반환한다. 그러나 그 전에 할당 호출과 전역 초기화 경로가 있으므로 **오류 반환이 무할당·무부작용이라는 계약은 아니다.** 해당 오류 경로에 본체를 직접 `_free`하는 호출은 보이지 않는다. 실제 allocator·로그·호출자 상태까지 실행한 자원 회수 검증은 하지 않았으며 이를 관찰된 누수 사례로 표현하지 않는다.

일반 wrapper `NXCreateMapTable`은 기본 zone을 얻어 prototype에 해당하는 stack 인자들과 capacity를 FromZone에 전달한다. 디컴파일된 여러 scalar 인자를 곧바로 원본 C 선언으로 채택하지 않는다. 원래 aggregate 전달과 GCC 2.7 ABI는 별도로 확인해야 한다.

## capacity와 bucket 수

`1cbf14` 보조 함수는 unsigned 입력이 1 이하이면 0을 반환하고, 그 외에는 논리적 우측 shift 후 재귀 호출 결과에 1을 더한다. 생성자는 그 결과에 1을 더한 shift로 bucket 수를 만든다. 작은 정상 범위의 Python 계산은 다음과 같다.

| capacity | bucket 수 |
|---|---:|
| 0 또는 1 | 1 |
| 2 또는 3 | 3 |
| 4 또는 7 | 7 |
| 8 또는 15 | 15 |
| 16 | 31 |

capacity가 bucket 수와 항상 같거나, capacity 자체를 그대로 할당 크기에 곱하는 동작이 아니다. bucket 배열의 각 pair는 `(0xffffffff, 0)`으로 초기화된다.

경계 계산에서는 x86 shift count와 32-bit 크기 연산을 유지했다. 큰 입력에서 크기 곱셈이 wrap하거나 bucket 수가 0으로 계산되는 표본도 있다. 이는 산술상 결과일 뿐 그 입력이 정상 caller에서 도달하거나 실제 할당·초기화에 성공한다는 증거가 아니다. 허용 capacity 범위와 allocator 실패 계약을 확인하기 전 임의의 unsigned capacity를 지원한다고 판정하지 않는다. 큰 메모리를 할당하는 시험은 수행하지 않았다.

## 순회 상태와 종료 조건

`NXCountMapTable`은 table의 `+0x4` 필드를 읽지만, `NXInitMapState`는 `+0x8`의 **bucket 수**를 반환한다. 초기 순회 상태를 element count로 만들면 원본과 다르다. 관찰된 상태는 단일 DWORD cursor이며 NXHashState의 별도 구조체 선언을 그대로 적용하지 않는다.

`NXNextMapState`는 먼저 cursor를 감소시키고, 그 값이 `0xffffffff`가 아니면 해당 bucket을 조사한다. sentinel key의 빈 bucket은 건너뛴다. 점유 bucket이면 key/value 출력에 저장하고 1을 반환하므로 높은 index에서 낮은 index 방향으로 순회한다. 정상 종료 경로는 0을 반환하며 key/value 출력에는 새 값을 쓰지 않는다.

종료 시 cursor는 `0xffffffff`다. 다시 호출하면 원본 DEC는 그 값을 `0xfffffffe`로 바꾸므로 같은 종료 비교에 해당하지 않는다. 따라서 종료 후 반복 호출이 계속 0을 반환하는 idempotent 동작으로 복원해서는 안 된다. 이 사실은 분기와 Python 계산으로 확인했으며 잘못된 cursor로 실제 메모리를 접근하는 시험은 하지 않았다.

본문에는 iterator generation 검사나 수정 감지가 없다. 순회 중 insert/remove/rehash, 출력 포인터 alias, NULL 또는 범위를 벗어난 상태에 대한 API 보장은 별도 확인해야 한다.

## 비교는 value 비교가 아니다

`NXCompareMapTables`는 table 포인터가 같으면 바로 1을 반환한다. 서로 다르면 먼저 count를 비교하고, 같을 때 첫 table을 순회하면서 각 key를 두 번째 table의 `NXMapMember`로 조회한다. 하나라도 없는 경우 0, 순회가 끝나면 1이다.

`1cc1b9`의 iterator가 쓴 value 저장 위치는 `1cc1d5`의 membership 조회 출력으로 다시 사용되지만 **두 value 사이의 비교는 없다.** 따라서 서로 다른 value를 가진 table도 key membership과 count 조건에 따라 같다고 판정될 수 있다. 현재 원본을 일반적인 key/value map 동등 비교로 바꾸지 않는다.

조회는 두 번째 table의 callback 계약을 사용한다. 서로 다른 prototype이나 비대칭 equality를 허용하는 입력에서 비교 대칭성이 보장된다고 추가 가정하지 않는다. 올바른 count·중복 key 제약·안정적인 callback도 전제다. 또한 membership 호출의 통계·사용자 callback 효과까지 없는 순수 함수로 단정하지 않는다.

## 검증 범위와 보존

본문 8개, 원본 명령 239개와 본문 바이트 579개를 대조했다. capacity 표본 14개와 iterator 경계 계산 4개는 모두 Python 산술 점검이며 native/emulator 실행이 아니다. 입력 28개와 이전 보존 파일 588개의 해시를 확인했다.

Ghidra 스킬로 보존 ASM/C를 읽기 전용 사용했고 원본·DB·export·이전 보고서를 변경하지 않았다. 코딩 전 독립 검토 미수신 조건을 유지하며 새 동적 시험 프로그램, 복원 소스, GCC 2.7 빌드를 진행하지 않았다.

[원본·계산 근거](creation-evidence.json) · [보존 목록](preservation.json) · [검토 범위](SCOPE.md) · [남은 전체 분석](OPEN_ITEMS.md)
