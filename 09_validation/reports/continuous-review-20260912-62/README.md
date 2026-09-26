# IPC splay tree: split/join/bounds와 조회 상태

## 판정과 증거 범위

split/join/bounds의 원본 본문과 lookup/init을 정적으로 대조했다. 분할은 엄격한 `< name` 기준이고, 병합은 작은 tree를 소비한다. 조회 실패는 저장된 root를 비우지 않으며 bounds도 연결을 변경할 수 있다. root만 있는 일반 BST나 구조체 전체 zeroing으로 단순 치환하면 원본의 상태 계약을 놓친다.

원본은 OPENSTEP x86 mk-183.34.4, SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다. [정적 증거](splay-evidence.json)에 함수별 원본 명령어·파일 오프셋·Ghidra listing·독립 디코딩·직접 분기 목적지·경고를 남겼다. Python으로 Mach-O load command를 별도 해석하여 보존 디코더의 매핑과 대조했다. 함수 범위 내 byte의 중복/누락 및 분기 목적지의 instruction head도 검사했다. 이는 원래 도구가 지정한 함수 경계 밖까지 의미적으로 증명했다는 뜻은 아니다.

| 함수 | 원본 주소 | instruction heads | body bytes |
| --- | --- | ---: | ---: |
| split | `0x151060` | 184 | 521 |
| join | `0x15126c` | 174 | 474 |
| bounds | `0x15144c` | 162 | 451 |
| lookup | `0x150a48` | 126 | 350 |
| init | `0x150a08` | 7 | 17 |

Python 집계: 5개 본문, 653개 명령어, 1813 bytes, 직접 분기 80개, CALL 0개, 보존된 Ghidra 경고 4개. 입력 fingerprint 22개와 이전 파일 684개의 해시를 확인했다. 본문에는 allocator/free/lock 호출이 없고 자체 lock 획득 명령도 보이지 않는다. 참조 소스의 `ist_lock/ist_unlock` 역시 no-op이다. 이 사실은 동시 접근 안전성을 보장하지 않는다.

참조는 보존된 Darwin `ipc/ipc_splay.c`의 prim_assemble, init/lookup, split/join/bounds 및 `ipc_splay.h`, `ipc_entry.h`이다. 구조와 계약 비교용이며 원본 빌드에 사용된 동일 소스라는 증거는 아니다. Ghidra 스킬은 보존 export 읽기 전용 비교에 적용했으며 DB는 변경하지 않았다.

## 구조체와 self-pointer 규칙

아래 field 명칭은 원본 offset에 참조 소스의 이름을 대응시킨 것이다. 대상은 i386이며 크기와 차이는 Python으로 계산했다.

| tree 필드 | offset | node 필드 | offset |
| --- | --- | --- | --- |
| ist_name | `+0x0` | ite_bits | `+0x0` |
| ist_root | `+0x4` | ite_object | `+0x4` |
| ist_ltree | `+0x8` | ite_request | `+0x8` |
| ist_ltreep | `+0xc` | hash next | `+0xc` |
| ist_rtree | `+0x10` | ite_name | `+0x10` |
| ist_rtreep | `+0x14` | ite_space | `+0x14` |
| — | — | ite_lchild | `+0x18` |
| — | — | ite_rchild | `+0x1c` |

tree는 24 bytes, node는 32 bytes이다. `ltreep/rtreep`는 node base가 아니라 child를 저장할 slot의 주소일 수 있고, 자기 tree의 `&ltree`/`&rtree`를 가리킬 수도 있다. 따라서 tree 구조체를 다른 주소로 단순 복사했을 때 self-pointer가 자동 보정된다고 가정할 수 없다.

분리된 tree를 assemble하는 저장 순서는 `*ltreep = root.left`, `*rtreep = root.right` 다음 `root.left = ltree`, `root.right = rtree`이다. 앞선 간접 저장이 바로 ltree/rtree 자체를 갱신할 수 있다. 처음부터 모든 값을 임시 변수에 읽어 둔 뒤 저장하는 표현은 이 alias 관계를 보존하지 못할 수 있다. 단, 임의의 잘못된 포인터 alias까지 지원한다는 의미는 아니다.

`ist_name`은 마지막 조회 이름이다. 항상 `root->ite_name`과 같다는 불변조건은 없다. 중간 root와 양쪽 분리 tree/tail이 함께 현재 상태를 표현한다.

## init과 lookup

init의 `0x150a0e`는 `tree+4`에만 0을 저장한다. 다른 필드는 초기화하지 않는다. 이는 아직 소유한 node들을 해제하는 clear/destructor가 아니다.

lookup은 root가 비어 있으면 0을 반환하며 tree에 저장하지 않는다. root가 있고 cached name이 요청과 다르면 assemble 후 unsigned 비교로 탐색·회전한다. 해당 key를 찾거나 다음 child가 없을 때 멈춘다. `0x150b82`는 요청 이름을 cached name에, `0x150b87`은 마지막 root를 tree에 저장한다.

그 뒤 `0x150b90`에서 실제 root의 key와 요청을 비교한다. 일치하지 않으면 `0x150b95`가 반환용 local만 0으로 만든다. tree.root는 비우지 않는다. 같은 요청을 다시 받으면 cached-name 경로로 재탐색은 생략하지만 실제 root-key 비교는 여전히 수행한다. 따라서 miss를 다음 호출의 성공으로 오인해서는 안 된다. 반환값은 포인터/NULL 계약으로 해석해야 하며 Ghidra의 정수 타입 표기를 그대로 복원 ABI로 채택하지 않는다.

이는 보고서 59의 entry lookup에서 splay callee가 성공/실패를 구분하는 부분을 보완한다. 모든 entry 생성자의 BST 불변조건까지 닫은 것은 아니다.

## split: 작은 key를 이동시키는 파괴적 분할

인자는 `(tree, name, small)`이다. `0x15106c`에서 small.root를 먼저 0으로 만든 뒤 `0x151076`에서 원본 root를 읽는다. 원본이 비어 있으면 그 상태로 반환한다. 목적지가 기존 node를 소유하지 않는 별도의 scratch tree라는 전제가 필요하다. 기존 small의 node 해제나 self-alias 검사는 없다.

원본 root가 있고 cached name이 다르면 lookup primitive가 inline으로 수행된다. `0x1511a2`의 root-key/name 비교와 `0x1511a5 JNC`가 경계를 정한다. 유효한 정렬 tree와 cached-state 계약 아래에서 small은 `key < name`, 원본은 `key >= name`을 갖는다. 같은 key는 원본 쪽이다.

- root key가 name보다 작으면 왼쪽 tail에 root.left를 연결하고 오른쪽 tail에 NULL을 저장한다. root.left를 ltree로 재조립한 root를 small로 넘긴다. small의 cached name은 실제 root key, tail들은 자기 필드 주소가 된다. 원본은 rtree를 root로 받으며, 비어 있지 않을 때만 실제 root key와 self-tail들을 재설정한다. 참조 소스의 `root.right == NULL` assert에 해당하는 런타임 검사는 본문에 없다.
- root key가 name 이상이면 왼쪽 tail을 닫고 root.left를 NULL로 만든다. 원본 root는 유지되며 cached name에는 실제 root key가 아닌 요청 name을 저장한다(`0x15122b`). 왼쪽 tail만 self-pointer로 재설정하고 오른쪽 tail 상태는 유지한다. small은 ltree를 받으며, 비어 있지 않으면 자체 key와 self-tail들을 설정한다.

빈 결과 tree의 다른 cached 필드나 새로 정규화한 tree의 ltree/rtree 값 자체를 모두 0으로 만들지는 않는다. 뒤의 assemble이 self-tail 저장을 통해 필요한 값을 세팅한다. 분할은 노드를 복사한 snapshot이 아니며 실제 연결과 소유 tree를 바꾼다. 전체 node 보존/중복 부재는 입력 불변조건과 생산자 검증이 남아 있다.

## join: 작은 tree를 소비하며 수신 tree의 최소 key 아래에 연결

인자는 `(tree, small)`이다. small.root가 0이면 `0x151280`에서 epilogue로 가며 tree/node에 저장하지 않는다. small이 비어 있지 않으면 먼저 assemble하고 `0x1512a5`에서 small.root를 0으로 만든다. 수신 root를 읽는 것은 그 다음 `0x1512af`이다. small의 다른 필드는 전부 지우지 않는다.

수신 tree가 비어 있으면 small의 조립된 root를 받는다. 비어 있지 않으면 cached name이 0인지 확인하고, 필요하면 assemble 후 상수 0을 찾는 최소-key 탐색을 수행한다. 이어 수신 tree를 assemble하고 `0x151419`에서 root.left에 small의 root를 붙인다. 최종 root, 실제 root key, 자기 ltree/rtree를 가리키는 tail들을 저장한다.

모든 small key가 수신 tree의 모든 key보다 작고, 두 tree가 유효하며 node를 공유하지 않는다는 조건을 호출자가 보장해야 한다. 참조 소스의 root.left NULL 및 순서 assert는 원본에서 실행되지 않는다. 일반적인 두 집합의 union이나 중복 key 해결 함수가 아니다. 자체 lock, node 할당/해제, 참조 count 변화도 없다. small은 비워진 채 소비되며 원래 상태로 보존되지 않는다.

## join 디컴파일 경고와 상수 분기

Ghidra C에는 `while (key != 0)` 안에 `if (key == 0)`가 남아 있고 `0x151390`, `0x151396`, `0x151367`, `0x15136d`의 unreachable 경고가 있다. C의 모양만 보고 누락된 실행 경로를 상상하거나 원본 bytes를 삭제해서는 안 된다.

- `0x15131b`에서 레지스터를 0으로 만들고 key와 비교한다. key가 0이면 탐색을 빠져나간다. loop back도 `0x1513d0` 비교 후 key가 0이 아닐 때만 `0x151328`로 간다.
- 따라서 정상 entry와 이 loop back으로 도달한 `0x15132c JNC`에서 비교식 `0 >= key`는 거짓이다. 오른쪽 탐색 branch `0x151380`은 이 경로 조건 아래에서 선택되지 않는다.
- `0x151365`, `0x15138e`는 0과 unsigned key를 비교한 JBE이다. unsigned DWORD 영역 전체에서 `0 <= key`이므로 해당 비교에 도달하면 분기는 항상 참이다. 바로 뒤 fallthrough 블록들은 이 조건으로 설명된다.

Python 증거에는 unsigned 영역, field 산술과 경계 sample predicate를 보존했다. sample 검사 자체가 전수 실행 증명은 아니다. 위 결론의 근거는 상수 unsigned 비교와 해당 branch 앞의 제어 흐름이다. 원본 bytes/직접 목적지는 모두 보존했으며 전역의 임의 jump-in, 모든 malformed state, 커널 전체 CFG 또는 경고 전수 해결을 주장하지 않는다.

## bounds: inclusive 경계와 간접 slot의 역산

인자는 `(tree, name, lowerp, upperp)`이다. 유효한 별도 출력 포인터와 tree 상태를 전제한다. 빈 tree는 `0x151465`에서 lower에 `0xffffffff`, `0x15146e`에서 upper에 0을 쓴다. 출력 포인터가 tree를 alias하지 않는 정상 계약에서는 tree 저장이 없다.

비어 있지 않고 요청이 cached name과 다르면 assemble/탐색 후 `0x15159e`, `0x1515a3`에서 cached name과 root를 갱신한다. 조회처럼 보이지만 tree와 node 연결을 변경할 수 있으므로 무조건 read-only 연산으로 복원해서는 안 된다.

root key를 rname이라고 하면 다음과 같다.

| 결과 | 비교/상태 | 원본에서 읽거나 저장하는 값 |
| --- | --- | --- |
| lower | name >= rname | rname |
| lower | name < rname, ltreep == &ltree | `0xffffffff` |
| lower | name < rname, 다른 ltreep | `[ltreep - 0xc]` |
| upper | name <= rname | rname |
| upper | name > rname, rtreep == &rtree | 0 |
| upper | name > rname, 다른 rtreep | `[rtreep - 0x8]` |

`0x1515d4`의 음수 offset은 node의 rchild slot에서 name을 읽는 것이고, `0x151604`는 lchild slot에서 name을 읽는 것이다. Python으로 계산한 `0x10 - 0x1c = -12`, `0x10 - 0x18 = -8`과 맞는다. 포인터 자체를 key나 node base로 읽는 표현은 잘못된 해석이다.

정상 tree에서는 lower가 요청 이하의 최대 key, upper가 요청 이상의 최소 key이며 정확히 존재하는 key는 lower=upper=name이다. 빈 방향의 sentinel은 lower가 최댓값, upper가 0으로 서로 반대다. 다만 이 함수 자체에 0/최댓값 key의 입력 차단 검사는 없다. sentinel의 무조건적인 비모호성은 key 인정 범위를 생산자까지 확인해야 한다. 출력 포인터 alias 및 잘못된 입력에 대한 방어를 임의로 추가한 코드도 아직 작성하지 않았다.

## 이전 분석과 남은 경계

[보고서 61](../continuous-review-20260912-61/README.md)의 entry dealloc은 split을 통해 같은 index의 충돌 node를 분리하고 이후 join/bounds를 사용한다. 이번 결과는 엄격한 분할 경계, small 소비, bounds의 inclusive 의미 및 cached-state를 보완한다. first pick의 성공 전제, node membership/세대 bits, 중복 key 부재, 모든 table 크기의 경계까지 증명한 것은 아니다.

다음 정적 범위는 tree insert와 entry alloc/grow/get 및 local/global lookup의 생산자 불변조건이다. 전체 미완료 항목은 [OPEN_ITEMS](OPEN_ITEMS.md)에 유지했다. 신규 독립 계획 검토는 확보되지 않았으며, 새 실행 검증 프로그램·동적 검증·커널 구현을 진행하지 않았다. GCC 2.7 실컴파일·Mach-O 링크·부팅과 전체 원본 의미 분석은 미완료이다. 이번 정적 결과를 그 완료 판정으로 사용하지 않는다.
