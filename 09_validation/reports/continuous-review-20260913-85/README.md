# 85차 — 원본 strategy·I/O worker·buffer 재사용

## 결과와 경계

원본 OPENSTEP x86 커널의 실제 strategy target과 직접 연결된 NFS worker/daemon,
UFS 하위 I/O, geometry callback 및 buffer 재사용 함수를 대조했다.
다른 프로젝트 소스와 재구현 코드는 참고하지 않았다.

이번에 원본으로 확인한 핵심은 다음과 같다.

- NFS daemon에 **error flag만 추가하고 error WORD/residual은 쓰지 않은 채 완료하는 분기**가 있다.
  84차의 조건부 error flag/WORD 불일치에 대한 실제 writer 후보를 찾았지만 그 분기의
  native 진입 가능성과 당시 필드 값은 아직 미확인이다.
- NFS worker의 짧은 read는 residual을 기록하고 성공이면 남은 영역을 zero-fill한다.
  별도의 EOF 성격 반환 `-98`은 일반 오류 플래그 설정에서 제외된다.
- UFS strategy는 하위 I/O 결과의 low WORD와 남은 residual을 **biodone 전에** 버퍼에 기록한다.
  그 하위 I/O에서 받은 buffer error flag는 원래 오류 WORD와 무관하게 상수 5로 바뀐다.
- SPEC strategy는 장치 함수의 EAX를 버리고 0을 반환한다. 정적 테이블의 nodev는
  완료를 호출하지 않으므로 제출 함수의 0만으로 완료를 판단할 수 없다.
- bfree는 요청 크기만 0으로 만들고, allocbuf는 기존 buffer 간 pagemove로 크기를 조절한다.
  getnewbuf와 brealloc의 재시도·게시·release 후 접근을 분리해 확인했다.

검증 범위는 전체 함수 본문 16개, 명령 head 1,522개, 본문 4,869 bytes다.
직접 분기 210개, 직접 CALL 96개, 간접 전달 8개를 원본 바이트에서 대조했다.
원본 vnode table slot 8개와 device strategy slot 24개, 중요 operand 124개도 확인했다.
Ghidra 경고 11개는 그대로 보존했고 기존 보존 파일 801개의 해시가 일치했다.
이 수치는 Python 계산이며 전역 함수 coverage나 native 실행 검증 수치가 아니다.

[증거 JSON](object-lifetime-evidence.json)의 함수별 원본 명령, `raw_order_anchors`,
`table_slots`, `device_strategy_table`, `arithmetic`을 근거로 한다.
[계획](SCOPE.md), [보존 해시](preservation.json), [검증 checkpoint](checkpoint.json),
[잔여 분석](OPEN_ITEMS.md)을 분리했다.
Ghidra 스킬에 따라 디컴파일의 타입·인자·반환을 원본과 대조했으며 DB를 변경하지 않았다.
독립 계획 교차검토는 수신하지 않았다. 계산을 그 검토의 대체 통과로 표현하지 않는다.

## 1. 선택 함수와 정적 연결

본문 entry는 `0x133130`, `0x1455ec`, `0x13a568`, `0x139444`, `0x11a924`,
`0x11a5e4`, `0x1934d8`, `0x1332c8`, `0x19335c`, `0x143e24`, `0x134120`,
`0x143c80`, `0x13a374`, `0x1395cc`, `0x1331cc`, `0x10cca4`다.
원본 nlist 이름 또는 export entry 식별자를 사용한다. 외부 구조체/errno 선언을 가져오지 않았다.

| 원본 vnode table | strategy `+0x54` target | geometry `+0x80` target |
| --- | --- | --- |
| NFS `0x1dca20` | `0x133130` | `0x134120` |
| UFS `0x1de480` | `0x1455ec` | `0x143c80` |
| SPEC `0x1dd6d0` | `0x13a568` | `0x13a374` |
| FIFO `0x1dd4b4` | `0x139444` | `0x1395cc` |

NFS/FIFO geometry는 EAX=`0x400`을 반환한다. SPEC은 `[[V+0x30]+0x48]`의 DWORD를 반환한다.
UFS는 `[[[V+0x24]+0x128]+0x8]`에서 얻은 vnode의 slot `+0x80`으로 전달하고 EAX를 보존한다.
이 UFS helper의 C `void` 표현은 반환 소비를 설명하지 못한다. brealloc과 NFS/UFS worker는
slot 호출 EAX를 실제 크기/offset 계산에 사용한다. SPEC 필드 writer와 UFS의 실제 하위 vnode
선정은 더 확인해야 한다. 정적 table 주소만으로 모든 runtime receiver를 확정하지 않는다.

이하 B는 buffer 포인터, V=`[B+0x40]`, N=`[V+0x30]`으로 표기한다.
명칭은 지역적인 설명이며 서로 다른 포인터의 alias 여부까지 가정하지 않는다.

## 2. NFS strategy와 async daemon

### 제출 함수 `0x133130`

read mask `0x1`이 없는 write에서 N `+0x62` WORD가 nonzero면 그 WORD를 B `+0x1c`에
복사하고 flags `0x4`를 추가한 뒤 biodone을 즉시 부른다 (`0x13314a`–`0x133152`).
이 분기는 자체 residual 초기화나 실제 I/O 제출을 하지 않는다.

나머지는 global `0x1e59ec`가 nonzero이며 B async mask `0x100`이 있을 때만
`_async_bufhead` (`0x1ef174`)에 게시한다. B `+0xc`를 queue next로 사용하며,
기존 tail의 next 또는 global head를 B로 저장한 **뒤** B next를 0으로 저장한다.
`_nfs_wakeup_one_biod` (`0x1dcb54`)가 정확히 1이면 wakeup_one, 아니면 wakeup이다.
큐 경로에는 자체 biowait나 biodone이 없다. 조건이 맞지 않으면 worker `0x1332c8`를
직접 부른다. 직접 worker 경로에서는 EAX를 보존하지만 다른 경로까지 일관된 반환 상태로
해석할 수는 없다. 본문에는 queue를 보호하는 자체 spl/MP lock이 없다.

### daemon `0x1331cc`

현재 thread `+0x78`을 1로 만들고 stack_privilege를 호출하며 `0x1e59ec`를 증가시킨다.
그 뒤 `[0x1e875c]+0x28`을 set_label에 넘긴다. 원본의 set_label 비지역 반환과
누가 다시 이 지점으로 돌아오게 하는지는 아직 별도 native 분석 대상이다.

최초 결과 0 쪽은 `0x1e59e8`을 증가시키고 큐가 빌 때 `sleep(head-event,0x1a)`를 반복한다.
일감이 있으면 이 counter를 감소시키고 **global head에서 제거한 뒤** worker를 부른다.
worker EAX는 검사하지 않고 다시 루프를 돈다. C에서 sleep의 두 번째 인자가 누락됐다.

set_label 결과 nonzero 쪽에서는 다음을 구별해야 한다.

- 당시 `0x1e59ec==0`: queued buffer에 `OR flags,4` (`0x133218`)만 수행하고
  head를 next로 바꾼 뒤 biodone (`0x133225`)을 부르며 큐를 비운다.
  이 경로 자체는 error WORD/residual을 저장하지 않고 N `+0x62`도 갱신하지 않는다.
- counter가 nonzero: 해당 counter와 `0x1e59e8`을 감소시킨다. 새 counter가 0이면
  남은 큐를 worker로 처리하고, 아니면 반환한다.

따라서 “buffer error flag를 설정하는 곳은 반드시 nonzero error WORD도 쓴다”는
지역 코드 규칙은 성립하지 않는다. 다만 첫 분기의 실제 도달성에는 다른 counter writer,
set_label 복귀 및 당시 queue/WORD 상태가 필요하다. 이를 확인하지 않고 NFS 상위 read의
실제 오류 은폐 또는 native 결함이 발생했다고 주장하지 않는다.

## 3. NFS worker `0x1332c8`

### read

geometry callback 결과와 B `+0x24`를 low-DWORD 곱하여 시작 byte offset을 만든다.
payload B `+0x20`, 요청 B `+0x14`, residual 출력 주소 B `+0x28`, credential N `+0x70`을
사용한다. 각 요청은 mount 관련 객체 `+0x1c`와 남은 크기를 signed 비교하여 작은 값을 택한다.
원본 REP MOVSD는 N `+0x40`에서 32 bytes를 request local에 복사한다.
rfscall은 procedure 6과 원본 xdr_readargs/xdr_rdresult 주소를 받는다.

transport 결과 nonzero면 그 값을 쓰고, transport 성공이면 reply status를 사용한다.
status `0x46`에는 원본 ESTALE 문자열 출력, btrash 및 nfs_invalidate_caches 호출이 있다.
이 callee들의 수명·무효화 범위는 아직 전부 확정하지 않았다.

오류가 없을 때 reply가 채운 count를 남은 크기에서 빼고 payload/offset에 더한다.
남은 값이 0이 아니며 reply count가 요청 chunk와 같을 때 반복한다.
루프 종료 시 남은 크기를 B residual에 기록하고, 성공일 때만 nattr_to_vattr를 부른다.
이후 상태의 low WORD를 B error에 쓰고 signed 확장한 값을 EBX에 둔다.

이 WORD 상태가 0이며 residual이 nonzero이면
`bzero(B.data + B.request - residual, residual)`을 호출한다 (`0x13350c`).
자체 residual 상한 검사는 보이지 않는다. XDR가 받은 count의 bounds와 mount chunk가
양수임을 보장하는 writer는 아직 확인해야 한다. Python의 over-count/zero-chunk 예시는
정수 식의 조건부 결과이지 네트워크에서 허용되는 값의 증명이 아니다.

성공인데 residual==request이고 시작 offset이 N `+0x98` 이상이면 EBX를
`0xffffff9e`, 즉 Python signed 값 `-98`로 바꾼다 (`0x13353f`).
**이 합성 상태를 B error WORD에 다시 쓰지는 않는다.** 일반 오류 flag 설정에서도 제외한다.
마지막에는 biodone을 호출하고 EBX를 EAX로 반환한다. 84차의 bread류는 strategy EAX를
직접 오류 코드로 사용하지 않으므로, 이 상태와 residual을 구별해야 한다.

### write

N `+0x62`의 기존 오류 WORD가 있으면 바로 B error WORD로 옮긴다.
없으면 `N.size - block_byte_offset`의 **DWORD wrap 결과**와 요청 크기를 unsigned min한 후
그 결과가 signed 음수일 때 panic으로 간다. 그러므로 그 panic만으로 EOF 초과나
모든 offset overflow가 배제됐다고 할 수 없다.

mount 관련 객체 `+0x20`을 chunk 상한으로 사용하고 procedure 8의 rfscall을 반복한다.
read와 달리 각 반복에서 **오류를 검사하기 전에도** 요청 chunk만큼 local 남은 크기를 빼고
local data/offset을 전진시킨다 (`0x13367e`–`0x133690`). 이 local 변경은 실제 전송 성공
증명이 아니며, write 경로 자체는 B residual을 갱신하지 않는다.
전체 local 남은 크기 0과 상태 0이면 nfs_attrcache를 부른다.

상태 `0x1c`, `0x45`, 그 밖의 값에 따라 로그 처리만 달라진다. 특히 `0x45`의 로그 생략을
오류 성공 변환으로 보지 않는다. status low WORD를 B error에 쓰고 signed 확장한다.
async mask가 있으면 성공 0을 포함하여 N `+0x62`에도 그 WORD를 기록한다.

공통 종료는 EBX가 0도 -98도 아닐 때 flags `0x4`를 추가하며,
V가 가리키는 vm_info가 존재하고 `+0x34`가 0일 때만 그 DWORD 오류도 기록한다.
기존 nonzero vm_info 오류는 덮어쓰지 않는다. 성공 경로에서 기존 error flag를 자체 제거하지 않는다.
마지막 biodone과 EAX 반환은 모든 정상 종료 경로에 있다. 원본의 WORD 절삭 결과와
전체 transport status는 폭이 다르므로 허용 상태 값의 범위는 RFScall/XDR 분석이 필요하다.

직접 stack header의 높은 flags mask `0x2000000`을 이 worker가 직접 검사하는 명령은 없다.
B data 주소를 RPC/XDR와 bzero에 넘기는 실제 주소 공간 계약은 아직 닫히지 않았다.

## 4. UFS strategy `0x1455ec`와 하위 I/O `0x143e24`

### strategy의 local 구성과 완료

V의 geometry slot 결과로 block byte offset을 계산한다. B data/request를 local iovec에 넣고
local U의 `+0`에 iovec 포인터, `+4`에 1, `+8`에 offset, `+0xc`에 1,
`+0x14`에 최초 요청 크기를 설정한다. local 전체를 초기화하는 것이 아니다.
U `+0xc` 상수의 실제 주소 공간 해석은 uiomove를 확인하기 전에는 외부 enum으로 확정하지 않는다.

하위 노드는 `I=[N+0x3c]`에서 얻는다. 이 I와 N의 alias 여부를 임의로 가정하지 않는다.
I mode WORD `+0x64`의 mask `0xf000`이 `0x8000`일 때만 I flag `+0x44`의
lock bit `0x1`을 기다리고 설정한다. 기다릴 때 wanted `0x10`, sleep priority `0xa`를 쓴다.
write 쪽에서는 `[N+0xc]`가 가리키는 객체의 첫 DWORD가 nonzero이면
`vnode_uncache(N+0xc)`를 먼저 호출한다.

read는 하위 함수 `(I,U,0,0)`, write는 `(I,U,1,0)`을 호출한다.
하위 상태를 EDI에 보존하고 노드 시간/flag 처리를 수행한다. `+0x44`의 `0x46` 중
비트가 있으면 `0x8`을 추가하고 microtime을 부르며, 각 비트에 따라 `+0x74`, `+0x7c`,
`+0x84`와 `+0x4c`를 갱신한 뒤 BYTE mask `0xb9`를 적용한다.
자체 획득했던 lock이면 해제하고 wanted가 있으면 I 이벤트를 깨운다.

이후 **B error WORD = DI**, **B residual DWORD = U.remaining**을 기록하고,
저장된 error WORD가 nonzero일 때만 flags `0x4`를 추가한다. 마지막에 biodone을 부른다.
WORD가 0일 때 기존 flags `0x4`를 자체 clear하지 않는다. 초기 flags 전제는 호출자/allocator 영역이다.
U.remaining의 변경은 하위 uiomove까지 연결해야 완전히 설명된다.

### 하위 rwip 성격 본문

원본 `rwip`/`rwip type` 문자열이 있는 `0x143e24`는 mode가 unsigned 0 또는 1이어야 하며
노드 mode mask는 `0x8000`, `0x4000`, `0xa000` 중 하나여야 한다.
U offset이 signed 음수이거나 offset+remaining DWORD 결과의 sign bit가 있으면 `0x16`을 반환한다.
이는 JNS 검사이며 임의의 음수 remaining까지 포함한 전체 수학적 overflow 검증은 아니다.
remaining==0이면 바로 0이다. regular-mask write가 active_u `+0x26c` 한계를 넘으면
signal `0x19`를 요청하고 `0x1b`를 반환한다.

작업 루프에 들어가면 uerror BYTE를 0으로 지우며 **이전 값을 저장·복구하지 않는다.**
노드 filesystem `+0x30` 값으로 offset을 unsigned DIV하여 block과 block 내 offset을 얻고,
남은 크기와 block 끝까지의 길이로 chunk를 잡는다. read는 node `+0x6c`의 EOF로 더 제한한다.
EOF이면 0으로 끝나며 U.remaining은 보존된다.

bmap 인자는 `(I,index,mode!=1,block_offset+chunk,optional_changed_out)`이다.
strategy가 넘기는 마지막 flags 인자는 0이므로 optional_changed_out은 그 경로에서는 NULL이다.
반환 block을 filesystem `+0x64`로 shift하고 uerror를 검사한다.
부분 write 뒤 오류 BYTE `0x1c`이며 process mask 조건이 맞으면 오류를 지우고 정리로 간다.
write에서 mapping block이 음수인 경우에는 uerror BYTE를 signed 확장한 값을 반환하므로,
그 BYTE도 0이면 상태 0과 진척 없음이 함께 나올 수 있는 지역 분기다. bmap invariant는 남아 있다.

write는 필요한 inode `+0x6c` 및 vm_info `+0x14` 크기를 **buffer 획득과 copy 전에** 늘린다.
이후 실패 시 자체 되돌림은 없다. fragment 크기 선정은 원본 mask/shift 식을 사용한다.
read hole은 geteblk와 blkclr 후 residual=0, 일반 read는 bread/breada,
write는 full-block chunk이면 getblk, 그렇지 않으면 bread를 쓴다.

버퍼 확보 후 chunk를 signed `B.request - B.residual`로 제한한다. 여기서 block 내 offset을
다시 빼지 않는다. buffer error mask가 있으면 **상수 5**를 local status에 저장하고 brelse 후
반환하며 buffer error WORD는 읽지 않는다 (`0x14411c` → `0x143f00`).
즉 원래 buffer WORD가 0인 경우에도 이 경로는 UFS strategy에 5를 반환한다.

나머지는 uiomove(data+offset,chunk,mode,U)를 호출하고 결과 low BYTE를 uerror에 저장한다.
directory-mask는 copy 전후 byte-swap helper를 쓴다. read는 brelse하고, write는 flags/directory
조건에 따라 bwrite, block 끝이면 bawrite, 그 외에는 bdwrite를 부른다.
그 write 호출들의 EAX는 직접 검사하지 않고 이후 uerror BYTE를 읽는다.
sync bwrite가 biowait를 통해 uerror를 바꾸는 것과 async/delayed 제출 성공을 구분해야 한다.

반복은 uerror==0, U.remaining signed 양수, chunk!=0일 때만 계속된다.
필요한 iupdat 후 local status가 아직 0이면 uerror BYTE를 signed 확장해 반환한다.
`uiomove`가 실제로 remaining/offset을 언제 바꾸고 physical/virtual 주소를 어떻게 다루는지는
다음 분석이다. 이 strategy 자체의 완료가 더 아래 저장소 write의 영속 완료를 뜻하지 않는다.

## 5. SPEC strategy와 원본 device table

`0x13a568`은 `[V+0x2d]` BYTE를 zero-extend하고,
`0x1e2cfc + index*24`의 함수를 B 인자로 호출한다. 돌아온 EAX는 버리고 **0을 반환**한다.
자체 index bounds, error/residual 기록, biodone 호출은 없다.

원본 nlist `_bdevsw=0x1e2cf4`, `_nblkdev=0x1e2f34`와 파일 DWORD 값을 읽었다.
정적 count는 24이고 table stride 24와 다음 심볼 경계까지의 크기가 일치한다.
초기 strategy slot의 index 6은 `_sdstrategy=0x183920`, 나머지는 `_nodev=0x10cca4`다.
nodev 전체 본문은 EAX=`0x13`을 반환할 뿐 buffer를 만지거나 biodone을 호출하지 않는다.
FIFO strategy `0x139444`는 fifo_badop panic 경로다.

따라서 SPEC 제출 반환 0은 장치 EAX도 완료 여부도 보존하지 않는다.
실제 허용 major/index, registration에 의한 table 변경, sdstrategy 완료 경로와
invalid-device 진입 배제는 아직 미확인이다. 파일의 초기 table을 live table로 간주하지 않는다.

## 6. getnewbuf·bfree — 반환 가능한 buffer의 조건

getnewbuf는 splhigh 아래 `0x1e87e8`, `0x1e87a4` 순서로 가용 목록을 보고
`0x1e8760`에 도달하면 global wanted를 설정하여 `sleep(global,0x15)` 후 처음부터 반복한다.
`0x1e8760` 목록의 항목이나 `0x1e882c`의 empty 목록을 여기서 직접 선택하지 않는다.

항목이 있으면 saved spl 복구 **후** head를 읽고 splbio로 free-list에서 제거하여 busy를 설정한다.
delayed mask `0x200`이 없으면 flags DWORD 전체를 **정확히 8**로 덮어쓰고 B를 반환한다.
오류 WORD/residual/hash/vnode/data/크기 필드를 여기서 함께 초기화하지 않는다.
명시적 실패 NULL 반환 경로는 없지만 pool 가용성·목록 일관성·모든 호출자의 배타성을
이 사실만으로 보장하지 않는다.

delayed buffer이면 async mask를 강제로 넣고 write 준비 후 strategy를 호출하여 다시 찾는다.
ESI의 강제 async bit를 검사하는 뒤쪽 wait/release 분기는 callee-saved ESI 전제에서 통과하지 않는다.
Ghidra의 unreachable 경고 `0x11aa02`는 이 원본 경로와 연결된다.
이전 delayed bit에 대한 accounting 분기에도 같은 값이 보존되어 있어 단순 C 조건문만으로
양쪽이 실제 도달한다고 해석하지 않는다. strategy 뒤의 age `0x80` 저장과 수명 조건은 남는다.

**bfree `0x1934d8`는 B `+0x14` DWORD를 0으로 저장하는 것만 한다.**
호출도 없고, payload/header free·vnode release·residual/error clear는 하지 않는다.
이것으로 84차 getblk miss의 bfree 호출 의미를 구체화했다.

## 7. brealloc — 재시도·겹침·반환 순서

요청 크기가 B `+0x14`와 같으면 1이다. 다르며 현재 B가 delayed이면 flags를 write용으로
준비하고 strategy에 제출한다. 이전 async flag에 따라 wait/release 또는 age 설정을 한 뒤
**EAX=0**으로 반환한다. getblk는 이를 재검색 신호로 사용한다. 단순한 alloc 실패 errno가 아니다.

축소는 mask `0x20000`이면 panic, 아니면 allocbuf로 간다.
확대는 done mask `0x2`를 먼저 지우고, vnode가 NULL이면 바로 allocbuf로 간다.
vnode가 있으면 geometry callback D를 얻는다. **signed 음수만 panic으로 거르므로 D=0은
자체 검사에서 통과하여 이후 IDIV의 분모가 될 수 있다.** 실제 callback 값의 invariant가 필요하다.

요청 시작 block S, 요청 길이 L이면 마지막 block은 low-DWORD `S + trunc(L/D) - 1`이다.
다른 buffer의 시작 T와 크기 M에 대해 `T<=last`와 `S<T+trunc(M/D)`를 signed 비교한다.
단, 검색하는 것은 **S의 hash bucket 하나뿐**이며 B 자신, 다른 vnode, invalid mask,
크기 0 항목은 건너뛴다.
Python 예시에서 S=7, L=0x800, D=0x400, T=8, M=0x400이면 수학적으로 겹치지만
같은 vnode에서도 hash bucket은 다르다. 이것은 허용되지 않는 배치일 수 있으므로
실제 충돌 누락으로 단정하지 않고 정렬/최대 크기 및 다른 배타성 전제를 남긴다.

겹치는 항목이 busy면 wanted와 `sleep(B,0x15)` 후 bucket head부터 재시작한다.
non-busy면 saved spl 복구 뒤 splbio로 free-list에서 떼어 busy로 만든다.
delayed이면 write 제출 및 wait/release 또는 async age 처리 후 bucket head부터 재시작한다.
clean이면 invalid `0x10000`을 먼저 추가한 후 brelse 상당의 목록 반환 처리를 수행한다.
그 다음 **반환한 항목의 hash next `+0x4`를 읽어** 순회를 계속한다 (`0x11a903`).
이 순서는 다음 포인터를 release 전에 저장한 형태가 아니다. callee/동시 reuse 조건은 미확인이다.
순회가 끝나면 allocbuf 결과 EAX를 그대로 반환한다.

## 8. allocbuf — page 이동과 크기 보장 범위

원본 round 식은 DWORD `page_size + requested - 1`의 wrap 결과를 page_size로
**unsigned DIV**한 뒤 page_size를 곱한다. 이후 capacity 비교는 signed 분기를 쓴다.
page_size nonzero, 요청 상한과 overflow 배제는 이 함수 자체의 검사로 확정되지 않는다.

rounded capacity가 현재 capacity와 같으면 요청 필드만 바꾸고 1이다.
축소할 때 empty-list `0x1e882c`가 비어 있으면 capacity를 그대로 두고도 요청 필드를 바꿔 1을 반환한다.
spare header가 있으면 그 header를 목록에서 떼고 busy로 만든 뒤,
`pagemove(B.data+rounded, spare.data, old_capacity-rounded)`를 호출한다.
그 뒤 두 capacity를 갱신하고 spare를 invalid/request=0으로 만든 후 release한다.
요청 크기와 확보 capacity가 항상 정확히 같다고 할 수 없다.

확대는 getnewbuf에서 donor를 얻어 `min(필요한 크기, donor.capacity)`를 택한다.
donor 끝부분을 target 끝으로 pagemove한 뒤 target capacity를 늘리고 donor capacity를 줄인다.
필요하면 donor request도 줄인다. donor capacity가 signed 0 이하이면 기존 hash를 제거하고
empty sentinel의 hash chain에 삽입하며 device WORD=`0xffff`, error WORD=0, invalid mask를 설정한다.
이 경로에는 별도의 vnode 분리 helper 호출이 없다. 이후 brelse로 반환하고 필요한 만큼 반복한다.

모든 정상 반환은 원래 requested를 B `+0x14`에 저장하고 EAX=1이다.
새 payload를 직접 malloc하는 함수가 아니며 pagemove 반환 상태를 검사하지 않는다.
page-table/physical 이동의 정확성, donor 수명과 진척, 허용 크기 및 주소 정렬은 아직 남는다.

## 9. 검증 해석

선택 함수 본문 byte 집합과 export 명령 경계, 직접 분기/CALL을 전부 원본 파일 mapping으로
대조했다. 중요 폭·mask·주소·순서에는 별도의 예상 operand 검사를 추가했다.
84차에서 발견한 TEST의 부정확한 Capstone access annotation을 메모리 write 증거로 사용하지 않았다.
정적 branch 대조는 모든 callee의 부작용이나 IRQ/native 도달성 검증이 아니다.

전체 목표는 계속 활성 상태다. 실제 디스크 strategy, pagemove/uiomove, RFScall/XDR,
daemon 비지역 복귀와 counter writer, buffer 및 물리 주소 공간 invariant와 전역 분석 요건이 남아 있다.
