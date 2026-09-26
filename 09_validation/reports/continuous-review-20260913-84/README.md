# 84차 — 원본 buffer I/O의 반환·완료·오류·수명 계약

## 결론과 증거 범위

원본 OPENSTEP x86 바이너리만 사용하여 buffer I/O 함수 본문을 대조했다.
`breadDirect`의 캐시 경로와 스택 직접 경로는 copy 방식과 오류 시 byte-count 반환이 다르다.
`geterror`의 대체 오류 값은 버퍼 오류 WORD에 기록되지 않으며, `biowait`는 별도의
uerror BYTE만 조건부로 갱신한다. 따라서 83차 NFS read의 error flag/WORD 불일치
가능성을 이 helper만으로 해소할 수 없다. `bdwrite`의 반환은 실제 write 완료가 아니고,
`biodone`도 콜백·비동기 반환·동기 wakeup을 분리한다.

이것은 지역 명령 계약의 확정이며 실제 데이터 손상·경쟁 발생이나 전체 원본 분석 완료를
뜻하지 않는다. strategy/장치 완료, allocator와 reuse, IRQ·실행 배타성은 남아 있다.

- 선택한 전체 본문: 15개, 명령 head 1,020개, 본문 2,914 bytes.
- 직접 분기 120개, 직접 CALL 82개, 간접 전달 13개를 원본에서 대조했다.
- Ghidra 경고 20개를 증거에 그대로 보존했다. 경고 개수는 미해결 결함 개수가 아니다.
- 상위 caller/하위 sleep의 한정 구간, 정적 strategy slot, 원본 문자열도 별도 기록했다.
- 기존 보존 파일 795개의 해시가 일치했다. 원본/DB/기존 확정 보고서는 변경하지 않았다.

계산·폭·주소·비트·해시는 Python으로 처리했다. Ghidra 스킬에 따라 C 표현을 가설로 두고
원본 명령과 분기를 대조했다. 라이브 Ghidra 변경, 구현·복원·빌드·동적 실행은 하지 않았다.
독립 계획 교차검토는 수신하지 않았고, 이번 정수 대조를 독립 검토로 표현하지 않는다.

근거는 [정적 증거 JSON](object-lifetime-evidence.json)의 함수별 전체 명령과
`critical_decoded_operands`, `raw_order_anchors`, `bounded_windows`, `arithmetic`에 있다.
[범위](SCOPE.md), [보존 해시](preservation.json), [최종 검증](checkpoint.json),
[남은 분석](OPEN_ITEMS.md)을 함께 보아야 한다.

## 1. 본문 선정과 원본 필드

선정 entry는 breadDirect `0x119e00`, bread `0x119b8c`, breada `0x119c10`,
vnReadAhead `0x119d88`, getblk `0x11a3e8`, incore `0x11a394`, brelse `0x11a288`,
bawrite `0x11a208`, bdwrite `0x11a1e0`, biowait `0x11aa80`, geterror `0x11b1c4`,
결합 helper `0x11b244`, 분리 helper `0x11b26c`, bwrite `0x11a168`, biodone `0x11aad4`다.
이름은 원본 nlist 또는 export 식별자이며 외부 소스에서 가져온 구현이 아니다.

이 보고서에서 `B`는 명령이 사용하는 버퍼 포인터다. 아래 이름은 용도를 설명하는 표기다.
외부 header에서 가져온 구조체 선언이나 모든 writer의 타입 확정은 아니다.

| B 기준 offset | 원본 접근 폭 | 이번 경로에서의 용도 |
| --- | --- | --- |
| `+0x0` | DWORD 및 부분 BYTE | 상태 flags |
| `+0x4`, `+0x8` | DWORD | hash next, prev |
| `+0xc`, `+0x10` | DWORD | 가용 목록 next, prev |
| `+0x14`, `+0x18` | DWORD | 요청 크기, 확보 크기로 사용되는 값 |
| `+0x1c` | WORD | signed 확장되는 오류 |
| `+0x1e` | WORD | vnode `+0x2c`에서 복사한 값 |
| `+0x20` | DWORD | data/physical 주소 |
| `+0x24`, `+0x28` | DWORD | block, residual |
| `+0x30` | DWORD | biodone의 조건부 완료 callback |
| `+0x3c` | DWORD | 직접 읽기에서 0으로 초기화하는 필드 |
| `+0x40` | DWORD | 결합 vnode |

## 2. incore와 getblk — 존재 여부와 소유권은 다르다

`incore`는 vnode와 block이 같고 flags `0x10000`이 없는 항목을 hash에서 찾으면
`EAX=1`, 없으면 `EAX=0`을 반환한다. buffer 포인터를 반환하지 않는다.
busy `0x8`, done `0x2`, 요청 크기, error/residual을 검사하지 않고 참조도 늘리지 않는다.
따라서 incore 성공을 읽기 완료나 buffer 수명 고정으로 볼 수 없다.

hash 식은 signed block을 8로 0 방향 절삭한 값과 vnode의 DWORD 합에서 low mask
`0xf`를 취한다. 음수 보정 `+7; SAR 3`이 원본에 있다. bucket은 16개이며 stride는
12 bytes, 기준 주소는 `0x1e8880`이다. Python 예시는 허용되는 native block 범위나
bucket 초기 상태를 증명하지 않는다.

`getblk`의 hit 조건도 동일하다. busy면 `0x40`을 설정하고
`sleep(B,0x15)` (`0x11a46b`/`0x11a46e`) 후 저장한 spl을 복구하여
`0x11a432`의 bucket head부터 다시 검색한다. 디컴파일의 1-인자 sleep 및
3-인자 splx 표현은 stack 정리 지연으로 생긴 잘못된 인자 분배다.
원본 sleep entry `0x10a58e`는 두 번째 stack 인자를 읽는다.

non-busy hit은 `splx` (`0x11a481`) **후** `splbio` (`0x11a486`)를 호출하고,
free-list의 `+0xc/+0x10` 링크를 제거하여 busy `0x8`을 설정한다.
크기가 다르면 `brealloc`을 부르고 0이면 다시 검색한다. hit 성공에는 `0x8000`을 추가한다.
이 호출 순서를 전역 MP 배타성 증명으로 바꾸지 않는다.

miss에서는 getnewbuf → bfree → 기존 hash unlink → vnode 결합 → block 설정 →
오류 WORD와 residual DWORD를 0으로 저장 → 새 hash 삽입 → brealloc 순서다.
hit에는 같은 오류/residual 초기화가 없고 miss 성공에는 자체 `0x8000` OR가 없다.
getnewbuf 결과의 자체 NULL 검사는 없으므로 하위 반환 계약은 별도 확인해야 한다.

## 3. 일반 read와 read-ahead

`bread(vnode,block,size)`는 size가 정확히 0이면 panic 경로다. 자체 양수 전체 검증은 아니다.
getblk 결과가 done이면 즉시 buffer를 반환하고 biowait를 부르지 않는다.
done이 아니면 read mask `0x1`을 추가하고 signed 요청 크기 <= 확보 크기를 검사한 뒤
`[[B+0x40]+0x1c]`의 slot `+0x54`에 B를 전달한다. strategy의 EAX는 검사하지 않는다.
그 후 active_u `+0x19c`를 증가시키고 biowait를 부른 뒤 **오류와 무관하게 B를 반환**한다.
이 함수 자체는 buffer를 release하지 않는다.

`breada`는 주 block이 incore에 없으면 먼저 확보하고 필요할 때 I/O를 제출한다.
read-ahead block이 0이 아니며 incore에도 없으면 별도 getblk를 사용한다.
RA buffer가 done이면 brelse, 아니면 `0x101`을 추가하여 strategy에 제출하며 RA를 기다리지 않는다.
주 buffer를 처음 확보하지 않았던 경우에는 뒤쪽의 bread 상당 경로로 들어간다.
처음 주 buffer를 확보했으면 done이었던 경우까지 포함하여 마지막에 biowait를 부른다.
size==0 panic은 fallback 쪽에 있으므로 모든 진입 경로의 선행 조건으로 일반화하지 않는다.

`vnReadAhead`도 block 0 또는 incore 성공이면 제출하지 않는다. 새 buffer의 done 상태면
release하고, 그렇지 않으면 `0x101` 후 strategy를 부른다. 자체 wait와 오류 검사 및
strategy 직후의 release는 없다. 이후 biodone 호출 여부는 strategy 계약이 필요하다.

## 4. breadDirect — 서로 다른 반환과 수명 순서

원본 stack 인자는 vnode, page, block, size, copyLength, RAblock, RAsize, outError 순서다.
첫 incore 결과로 경로를 나눈다. 캐시 쪽에서는 incore를 다시 검사하므로 첫 검색 결과를
지속되는 소유권으로 사용하지 않는다.

| 경로와 검사 시 상태 | payload 처리 | outError | EAX |
| --- | --- | --- | --- |
| 캐시, error mask `0x4` 없음 | `copy_to_phys(B+0x20, page+0x24, copyLength)` | release 전에 0 | release **후** 읽은 residual을 size에서 뺀 값 |
| 캐시, error mask `0x4` 있음 | copy 없음 | release **후** 읽은 signed error WORD | 0 |
| 스택 직접, error mask 없음 | physical 주소를 header에 넣어 strategy 호출 | hash unlink/vnode 분리 후 0 | size - stack residual |
| 스택 직접, error mask 있음 | 동일한 직접 strategy 경로 | hash unlink 전에 signed error WORD를 저장 | size - stack residual을 분리 전에 저장하여 반환 |

캐시 성공은 `0x119fab` copy → `0x119fb3` outError=0 → `0x119fba` brelse →
`0x119fc2` residual 읽기다. copy 전에 residual로 copyLength를 제한하는 명령은 없다.
캐시 오류는 `0x119fcd` brelse → `0x119fd2` 오류 WORD 읽기 → EAX=0이다.
**brelse는 여기서 payload/header를 직접 free하지 않지만 가용 목록으로 반환한다.**
따라서 이를 곧바로 해제 메모리 오류라고 단정하지 않으며, 재사용/동시성 조건을 따로 남긴다.

스택 경로의 B는 `EBP-0x44`이고 함수 local 영역은 68 bytes다. Ghidra의 개별 local 이름은
분리된 독립 객체의 증거가 아니다. 결합 helper에 이 주소를 넘기며 B `+0x40`은 그 전에 0이다.
flags는 `0x2000001`, 요청/확보 크기는 모두 **page_size**로 설정한다. size 또는 copyLength를
그대로 strategy 요청 크기에 쓰는 것이 아니다. 오류 WORD·residual·`+0x3c`는 0으로 설정하고
payload에는 page `+0x24`의 physical 주소를 넣는다. 전체 local 영역을 bzero하지 않는다.

`0x11a063`/`0x11a066`에서 stack header의 hash 링크를 만들고,
`0x11a06c`/`0x11a06f`에서 bucket에 게시한 뒤 `0x11a07c`에서 strategy를 호출한다.
선택적인 RA를 제출한 다음 stack B로 biowait를 부른다.
정상 반환 경로들은 hash 링크를 직접 제거하고 vnode 분리 helper를 호출한다.
스택 header를 brelse로 넘기지는 않는다.

스택 header의 초기 flags에는 busy `0x8`, async `0x100`, callback `0x200000`이 없다.
`0x2000001`과 callback mask `0x200000`을 혼동하면 안 된다.
게시된 stack header를 같은 key의 다른 getblk가 보지 않는 조건과 strategy의 flags 변경,
미초기화 필드 소비 여부는 아직 증명되지 않았다. 이 본문에는 전역 잠금 보장이 보이지 않으며,
native 실행 배타성이나 실제 결함을 그 사실만으로 확정할 수 없다.

## 5. geterror·biowait — 버퍼 WORD와 uerror BYTE를 구별

`geterror`는 flags `0x4`가 없으면 0, 있으면 B `+0x1c` WORD를 signed 확장하여 반환한다.
그 WORD가 0이면 EAX를 5로 바꾼다 (`0x11b1d9`). **버퍼에는 아무 값도 써 주지 않는다.**
상수 5에 외부 errno 이름을 붙여 원본 근거로 취급하지 않았다.

`biowait`는 splhigh를 저장하고 done mask `0x2`가 생길 때까지 `sleep(B,0x14)`를 반복한다.
반복 검사 `0x11aa9f`는 실제 메모리를 다시 읽는다. C에서 sleep의 우선순위 인자가 누락됐다.
이 본문에는 명시적 timeout 인자가 없고, 대기 하위 구현의 시간/중단 정책은 별도 범위다.

spl 복구 후 `[0x1e875c]+0x68`의 **BYTE가 0일 때만** geterror 결과의 low BYTE를 기록한다.
기존 nonzero BYTE는 보존한다. 반환 EAX를 독립 I/O 성공 코드로 볼 수 없다.
flags와 error WORD 및 residual을 보정하거나 비우지 않는다.

따라서 error mask=4, error WORD=0, 이전 uerror=0을 가정하면 biowait 이후 uerror는 5여도
buffer error WORD는 여전히 0이다. 83차 NFS buffered read는 이 WORD를 다시 읽고
copy를 생략한 뒤 local error nonzero 여부로 실패를 가른다 (`0x133c99`, `0x133cdd`).
`geterror` 존재만으로 그 조건부 불일치를 해소할 수 없다. 캐시 breadDirect도 error WORD가
0인 경우 outError=0/EAX=0이 될 수 있는 지역 제어 흐름이다. 실제 writer가 이 조합을 만드는지는
미완료다. WORD=0x100이 low BYTE 0이 되는 예시도 정수 폭 확인일 뿐 허용 오류 값 증명이 아니다.

NFS direct caller는 EAX를 보존하고 추가 RA를 제출한 뒤 outError를 검사한다.
UFS direct caller는 last-index를 기록하고 outError를 검사한 뒤 signed 비교로 길이를 줄인다.
이번 한정 caller window는 반환 소비를 확인하며 전체 filesystem 경로를 새로 완료시킨 것은 아니다.

## 6. 지연/비동기 write와 실제 완료

`bdwrite`는 이전 flags의 `0x200`이 없을 때 write accounting을 증가시키고,
`0x202`를 OR한 뒤 brelse를 호출한다. **자체 strategy 호출이나 완료 대기는 없다.**
done mask `0x2`는 여기서 I/O 제출 없이도 설정되므로 저장 장치의 영속성 지표가 아니다.

`bwrite`는 이전 flags를 ESI에 저장하고 `0xfffffdf8`로 flags를 마스킹한다.
지워지는 mask는 Python 계산상 `0x207`이다. 요청/확보 크기 signed 검사를 거쳐 strategy를
호출한 후 **이전 flags**의 `0x100`이 없으면 biowait와 brelse를 부른다.
있으면 기다리지 않으며 이전 `0x200`이 있는 경우 strategy 반환 뒤 `0x80`을 추가한다.
자체 오류 반환 코드를 구성하지 않는다.

`bawrite`는 ESI에 `0x100`을 강제로 OR (`0x11a213`)하고 같은 준비/제출을 수행한다.
이후 `TEST ESI,0x100` (`0x11a25e`)과 분기 때문에 통상적인 callee-saved ESI 계약 아래에서는
`0x11a266`의 wait/release 블록을 통과하지 않는다. Ghidra가 이 블록을 제거한 경고를
원본과 연결할 수 있지만 간접 callee의 레지스터 계약까지 이번에 확정한 것은 아니다.
이전 delayed mask가 있으면 `0x11a278`의 `0x80` 저장은 strategy 호출 **뒤**에 있다.
동기적으로 completion이 발생해 먼저 가용 목록으로 반환되는 경우의 수명은 하위 계약이 필요하다.

83차 NFS/UFS write caller는 bawrite/bdwrite의 EAX를 검사하지 않고 계속 진행한다.
이번 원본 caller window에서도 확인했다. 그 상위 함수의 반환 0을 비동기/지연 쓰기의
최종 성공이나 영속성으로 해석하지 않는다.

## 7. biodone과 brelse — 공통 처리와 실제 차이

`biodone`은 기존 done mask가 있으면 `dup biodone` panic 경로로 가고,
그렇지 않으면 done을 먼저 설정한다 (`0x11aaf0`/`0x11aaf2`).

- callback mask `0x200000`: 그 mask를 지우고 B `+0x30`의 함수를 B 인자로 호출하여 반환한다.
  자체 wakeup/가용 목록 반환은 이 경로에 없다. callback의 책임은 아직 미확인이다.
- callback mask 없음, async mask `0x100` 있음: brelse 상당 처리를 본문에 직접 수행한다.
- 둘 다 없음: wanted mask `0x40`을 지우고 B를 이벤트로 wakeup한다. 가용 목록에 넣지 않는다.

스택 직접 읽기의 초기 flags는 마지막 분기에 해당하지만, 실제 완료 시까지 그 flags가
유지되고 strategy가 biodone을 부른다는 것은 이 함수들만으로 증명되지 않는다.
또한 biodone 본문은 error WORD/residual의 타당성을 검증하거나 오류 WORD를 보정하지 않는다.

비동기 반환 구간과 standalone brelse를 명령별로 대조했다. 각 구간은 69개 명령이며
첫 TEST를 제외하면 내부 분기 목적지를 명령 순번으로 정규화한 연산/피연산자가 일치한다.
**첫 TEST는 다르다:** brelse `0x11a290`은 `[B]`의 BYTE를 읽지만
biodone `0x11ab19`는 이전 flags snapshot인 `AL`을 검사한다.
원본 메모리 재읽기와 register 검사 차이를 지우지 않았다. concurrent writer/IRQ 조건이
확인되기 전에는 전체 동등성도 실제 missed wakeup도 주장할 수 없다.

반환 처리의 공통 부분은 B wanted가 있으면 wakeup하고, global `0x1e8760` wanted를
지운 뒤 global 이벤트를 깨운다. `(flags & 0x400200)==0x400000`이면 `0x10000`을 추가한다.
error mask `0x4`가 있을 때 `0x20000`도 있으면 **error flag만** 지우고 WORD는 보존하며,
그 mask가 없으면 vnode 분리 helper를 부른다. 이 작업들은 뒤의 splhigh 호출보다 먼저다.

가용 목록 삽입은 splhigh 저장 후 다음 조건 순서로 결정한다.

| 우선 검사 조건 | sentinel | 삽입 위치 |
| --- | --- | --- |
| signed B `+0x18` <= 0 | `0x1e882c` | head |
| 위 조건 아님, flags `0x10004` 중 하나 있음 | `0x1e87e8` | head |
| 위 조건들 아님, flags `0x20000` 있음 | `0x1e8760` | tail |
| 위 조건들 아님, low BYTE sign bit 있음 | `0x1e87e8` | tail |
| 나머지 | `0x1e87a4` | tail |

head 삽입은 이전 head의 prev, B의 next, sentinel의 next, B의 prev를 순서대로 저장한다.
tail 삽입은 이전 tail의 next, B의 prev, sentinel의 prev, B의 next를 저장한다.
마지막 `flags &= 0xffbffe37`은 `0x8`, `0x40`, `0x80`, `0x100`, `0x400000`을 지우고
저장 spl을 복구한다. 버퍼 payload/header를 자체 해제하지 않으며, 후속 allocator의 reuse는 남아 있다.

## 8. vnode 결합과 정적 strategy 연결

결합 helper `0x11b244`는 기존 B `+0x40`이 nonzero면 **먼저 분리**하고,
새 vnode `+0x6`의 WORD를 증가시킨 뒤 B `+0x40`에 게시한다.
same-vnode인지 비교하지 않으며 새 포인터의 NULL 및 WORD overflow 자체 검사는 없다.
old release 이전에 새 참조를 확보하는 순서가 아니다. alias와 마지막 참조 조건은 호출자 계약이다.
분리 helper `0x11b26c`는 B `+0x40`을 0으로 먼저 저장하고 vn_rele를 호출한다.
스택 직접 읽기에서는 기존 포인터를 0으로 만든 뒤 결합하고 정상 종료 시 분리한다.
callee의 비정상 종료나 callback 수명까지 포함한 전역 참조 균형은 아직 주장하지 않는다.

원본 table DWORD slot을 Python으로 읽었다. NFS/UFS 명칭은 이전 원본 table 분석의 표기다.
이것은 정적 pointer 증거이며, 임의 B의 실제 receiver가 해당 table이라는 증거는 아니다.

| 원본 table | slot `+0x54` 주소 | 원본 target |
| --- | --- | --- |
| NFS `0x1dca20` | `0x1dca74` | `0x133130` |
| UFS `0x1de480` | `0x1de4d4` | `0x1455ec` |
| SPEC `0x1dd6d0` | `0x1dd724` | `0x13a568` |
| FIFO `0x1dd4b4` | `0x1dd508` | `0x139444` |

다음 분석은 이 target들의 완료/오류/residual writer와 getnewbuf·brealloc·bfree를 우선 연결한다.
전역 원본 분석의 나머지 범위는 축소하지 않고 OPEN_ITEMS에 유지한다.

## 9. 검증 중 발견한 차이와 한계

한정 caller 구간에는 export 명령 사이의 NOP padding이 있었다. 원본에서 별도로 읽어
NOP임을 확인하여 증거의 `unlisted_padding`에 보존했다. 이를 함수 본문 명령으로
몰래 편입하거나 손상/누락 코드로 단정하지 않았다.

release 구간 전체의 최초 동일성 검사는 첫 TEST 차이 때문에 실패했다. 그 차이를 제거하여
통과로 만들지 않고 별도 항목으로 기록했으며, 동일성 주장은 나머지 연산으로 제한했다.
직접 분기와 CALL 목적지, 선택 본문 byte 집합은 원본에서 전부 대조했다. 중요 operand는
별도 기대 연산과 확인했지만 모든 명령의 모든 의미, callee 부작용과 native 상태를 자동 증명한 것은 아니다.

추가로 Capstone이 `0x11b1cc`의 원본 `f60204` (`TEST byte ptr [EDX],4`)에
read/write 접근 속성을 보고했다. 이 속성을 메모리 쓰기의 증거로 사용하지 않았다.
원본 F6 group /0 opcode와 즉시값을 확인하고 geterror의 명시적 memory operand 전체가
MOV/MOVSX의 읽기 source 또는 TEST임을 별도 대조했다. 따라서 버퍼 쓰기가 없다는 결론과
함수 prologue의 stack 저장은 구분한다. decoder 버전과 관측 속성은 checkpoint에 보존했다.

잔여 오류 writer·residual bounds, stack hash 수명, 완료 도착 보장, sleep/wakeup 배타성 및
전체 함수/경로 ledger가 남아 있으므로 전체 목표는 계속 활성 상태다.
