# 83차 — pager 반환 ABI, pageout 후처리와 NFS/UFS 실제 I/O 본문

OPENSTEP 원본 x86만 분석했다. 82차 pagein/pageout의 상위 dispatch와 직접 pageout
caller, 원본 vnodeops의 하위 함수를 연결했다. 외부/복원 코드를 참고하지 않았다.
실패 시 page 상태를 복구하는 것과 packed 기록·파일 크기·저장소 내용을 되돌리는 것은
서로 다른 계약이다. 이번 본문 검토에서 이 구분과 디컴파일 ABI 차이를 확인했다.

## 범위·증거

[선정 계획](SCOPE.md), [원본 대조 증거](object-lifetime-evidence.json),
[보존 목록](preservation.json), [최종 재검증](checkpoint.json),
[미완료 분석](OPEN_ITEMS.md).

- 전체 ASM/C 본문 12개, 명령어 head 1,657개, 본문 바이트 4,741개.
- 직접 분기 207개, 직접 CALL 99개, 간접 CALL 6개, export 경고 4개.
- 제한적 window 14개·116 head, 원본 표 슬롯 9개, 문자열 22개.
- 선택 상위 함수의 export 참조 12행, 입력 fingerprint 55개, 이전 보존 파일 789개.
- 명시적 핵심 피연산자 대조 62개, register TEST 반복 spin 18곳.

모든 계산·해시는 Python으로 수행했다. 원본 Mach-O file mapping과 별도 x86 디코더로
본문 범위·바이트·길이·직접 분기/CALL을 확인했다. 본문 바이트는 export body 합집합이며
entry부터 마지막 주소까지의 span과 구별한다. C의 의미 전체를 자동 검증한 것은 아니다.
이번에 IDA/Hex-Rays 독립 재분석이나 native 실행·에뮬레이션은 하지 않았다.

## 원본 table 연결

| 원본 vnodeops | +0x74 pagein 경로 | +0x78 pageout 경로 | 추가 mapping 연결 |
| --- | --- | --- | --- |
| NFS 0x1dca20 | 0x1338c0 | 0x133de4 | +0x50 → 0x133884 |
| UFS 0x1de480 | 0x145848 | 0x145bbc | 이번 I/O 본문은 bmap을 직접 호출 |
| FIFO 0x1dd4b4 | 0x139444 | 0x139444 | — |
| SPEC 0x1dd6d0 | 0x139b14 | 0x139b14 | — |

원본 심볼이 없는 target은 주소로 지칭한다. 표에서 발견했다고 모든 runtime vnode가
이 target들만 사용한다고 확정하지 않는다. FIFO/SPEC의 선택 target은 각각 원본 문자열
`fifo_badop`, `spec_badop`를 인자로 panic을 호출한다. export 본문에는 정상 RET가 없다.
이를 정상 I/O 성공이나 일반 오류 반환 함수로 바꾸면 안 된다.

## pager dispatch의 실제 반환 ABI

### vm_pager_get — 0x17a248

인자는 pager, page, optional output이다. pager=NULL이면 vm_page_zero_fill(page)를
호출하고 정상 복귀 후 EAX를 0으로 만든다. pager의 첫 DWORD가 비0이면 device_pagein(page),
0이면 vnode_pagein(page,output)을 호출한다. 이 두 분기에서는 EAX를 그대로 반환한다.
NULL/device 분기는 optional output을 이 본문에서 갱신하지 않는다. 자체 잠금이나
참조 증가는 없다. zero-fill 호출이 비정상 종료하는 경우까지 성공을 보장한 것은 아니다.

### vm_pager_put — 0x17a284

NULL pager는 panic이다. 첫 DWORD가 비0이면 device_pageout(page), 0이면
vnode_pageout(page)을 호출한다. 원본은 호출 뒤 EAX를 변경하지 않고 RET한다.
Ghidra C는 `void`로 표현하지만 실제 상위 원본은 반환값을 사용한다.

- vm_pageout_scan: 0x179f9f CALL 뒤 0x179fa7 TEST EAX; 0일 때 local=1을 기록한다.
- FUN_0017bacc: 0x17bbd0 CALL 뒤 0x17bbd8 TEST EAX; 0일 때 local=0을 기록한다.

이 window는 반환값 소비의 근거이며 상위 함수 전체의 오류 정책을 검증한 것은 아니다.

### vm_pager_has_page — 0x17a308

NULL 또는 첫 DWORD가 비0인 pager는 panic이다. 그 외에는 vnode_has_page(pager,offset)의
EAX를 그대로 반환한다. C의 `void`와 달리 vm_fault는 0x172ed7 CALL 직후
0x172edc에서 EAX를 local에 저장한다. vm_pager_get도 vm_fault의 0x1727c3 CALL 뒤
TEST EAX로 결과가 소비된다. 타입 수정이나 DB 변경은 하지 않고 차이를 증거에 남겼다.

## vmp_push / vmp_push_all — pageout 결과 처리

### 진입·순회·대기

vmp_push(0x15fc58)는 입력+0x38의 mask 0x2가 없으면 바로 돌아간다. 있으면 이를
먼저 지우고 입력+0x24의 object가 NULL인지 검사한다. 따라서 object가 없거나 후속 I/O가
실패해도 이 요청 flag를 자체적으로 되살리지 않는다. 입력+0x10 시작, +0xc 길이로
page_mask를 사용해 start/end를 계산한다. 덧셈은 DWORD이며 unsigned start<end일 때 순회한다.

vmp_push_all(0x15fe70)은 요청 flag를 조건 없이 지우고 object의 page list를 순회한다.
양쪽 모두 전역 vm_page_queue_lock을 먼저, object+0x10 spin을 다음으로 잡는다.
이 순서의 전역 안전성은 다른 caller와 별도로 대조해야 한다.

page+0x21의 mask 0x8이 있으면 건너뛴다. page+0x20의 mask 0x1이 있으면 mask 0x2를
추가하고 assert_wait(page,0), object와 queue unlock, thread_block, queue와 object 재잠금으로
이어진다. vmp_push는 같은 offset을 다시 lookup하고, vmp_push_all은 object list의 head부터
재시작한다. 잠금 해제 후 옛 page 포인터를 그대로 처리하는 대기 재개로 해석하지 않는다.

### I/O 전후 상태

처리할 page는 필요하면 activate 후 deactivate하고, inactive list에서 분리한다.
page+0x1e mask 0x1을 지우고 inactive count를 감소시킨 뒤 page+0x20 mask 0x1을 세운다.
그 다음 page+0x1e mask 0x4가 있을 때만 다음 순서를 수행한다.

`pmap_remove_all → object+0x44 WORD 증가 → object/queue unlock → vnode_pageout → queue/object 재잠금 → object+0x44 WORD 감소`

이 +0x44는 **VM object의 I/O 카운터**다. 뒤에서 설명하는 UFS inode+0x44 flag WORD와
주소 기반 객체가 다르므로 같은 필드로 합쳐서는 안 된다.

I/O 반환 0일 때만 page+0x1e mask 0x4를 지운다(0x15fe1a / 0x15ffec).
오류여도 이후 activate를 호출하고, page+0x20 mask 0x1을 지우며,
이전 mask 0x2가 있으면 그것도 지우고 thread_wakeup_prim(page,0,0)을 호출한다.
이 wakeup 인자는 page이지 object가 아니다. object+0x44 감소 시 별도의 object-event
wakeup을 직접 호출하지 않는다. 이 카운터를 기다리는 전체 경로와 연결이 필요하다.

오류 시에는 현재 순회의 다음 항목으로 넘어간다. 이 본문에 즉각적인 같은 페이지 I/O 재시도,
packed 기록/bitmap 복구, vm_info/inode 크기 원복은 없다. page 상태 처리와 backing 기록
교체의 원자성을 동일시하지 않는다. I/O 성공도 caller가 받은 status=0이라는 국소 판정이다.

vmp_push_all의 다음 page는 0x16001a에서 현재 page+8을 읽어 얻는다. 이 읽기는 I/O와
재잠금·activate·wakeup 후다. I/O 전에 next를 저장하는 알고리즘이 아니다.
page/object 수명과 list 링크가 보존되는 상위 전제는 아직 전역적으로 검증되지 않았다.

두 함수의 EAX는 조기 종료에서는 입력 포인터, 일반 종료에서는 해제 XCHG의 이전 spin 값이
남을 수 있다. 이를 누적 I/O 성공/실패 반환으로 해석하지 않는다. mfs_sync/mfs_fsync의
선택 post-call window는 새 lock 값을 EAX에 읽으며 이전 EAX를 덮는다. 다른 상위 전체
분기까지 그 결과가 무시된다고 일반화하지 않는다.

## NFS mapping target — 0x133884

원본 NFS 표의 +0x50은 작은 인자/출력 계산 함수다. 인자는 vnode, logical index,
optional vnode output, optional block output이다. 첫 output이 있으면 vnode를 쓴다.
둘째 output이 있으면 `[[vnode+0x24]+0x128]+0x24`의 block-size DWORD를 signed로
해석하여 1024로 0 방향 나눗셈한 값에 logical index를 곱하고 low DWORD를 쓴다.
원본 구현은 음수면 0x3ff를 더한 뒤 SAR 0xa, IMUL이다. 마지막 EAX는 항상 0이다.
잠금·I/O·메모리 할당·다른 CALL은 없다.

NFS pagein은 이 block size를 `&0xfffffc00`한 값을 unsigned DIV의 divisor로 사용하고,
pageout은 mask하지 않은 값을 사용한다. mount 크기의 허용 범위·정렬·비0은 별도 전제다.
예를 들어 가정값 0x401이면 read divisor=0x400, write divisor=0x401, mapping stride=1이다.
이는 Python 유한 계산이며 그런 mount가 허용된다는 뜻은 아니다. 이 target의 반환 EAX를
무시하는 I/O caller는 output으로 오류/음수 여부를 판단하는 계약과 구분해야 한다.

## NFS pagein target — 0x1338c0

### 객체 flag와 credential

page+0x14의 object spin을 잡고 page+0x21 mask 0x8을 세운 뒤 unlock한다.
그 다음 vnode+0x30의 node에 rlock을 호출한다. 선택 vmp_push 경로가 건너뛰는 flag와
직접 연결되지만, 이 flag 하나가 모든 kernel 경로를 배제한다는 증명은 아니다.

credential은 우선 vm_info+0x30에서 얻는다. 없으면 현재 thread의 연결 context에 따른
검사 후 active_u+0x1c 또는 기존 node+0x70을 선택한다. context fallback을 사용할 수 없는
분기에서 node+0x70도 NULL이면 출력, runlock, object spin 재취득, page mask 0x8 clear,
unlock 후 2를 반환한다. active_u에서 읽은 credential을 다시 NULL 검사하는 명령은 없다.
선택 credential의 WORD를 먼저 증가시키고(0x1339b0), 기존 node+0x70이 있으면 crfree,
그 다음 선택 포인터를 node+0x70에 저장한다. 새 포인터와 기존 포인터가 같아도 증가가
해제보다 먼저다. 새 참조를 이 함수 끝에서 일회성 crfree하지 않고 node에 보관한다.

### 읽기 선택과 결과

node+0x98 크기가 offset+page_size DWORD보다 unsigned 비교로 작으면 먼저
vm_page_zero_fill(page)를 호출한다. block quotient/remainder, 남은 block 공간·page 길이·
파일 끝으로 읽기 길이를 제한한다. offset이 EOF 이상이고 아직 처리한 byte가 0이면 1,
앞서 처리한 byte가 있으면 성공 정리로 가서 0이다. mapping output block이 signed 음수인
경로는 처리량과 무관하게 1을 반환한다. mapping callback의 EAX 자체는 검사하지 않는다.

nfs_validate_caches는 길이를 정한 뒤 호출되므로 그 callee의 크기/캐시 변경 효과는 별도다.
block size=page_size, 처리량=0, block offset=0일 때 breadDirect 경로가 가능하다.
순차 index이면 다음 mapping과 조건부 추가 read-ahead mapping을 계산한다.
원본 nfsslowlink가 비0일 때 추가 mapping을 수행하는 조건을 이름의 직관으로 뒤집지 않는다.
breadDirect 뒤 추가 vnReadAhead들을 먼저 호출하고, 그 뒤 out-error를 검사한다.
out-error=0이면 반환 byte 수와 계획 길이를 signed 비교해 작은 값을 사용한다.

그 밖의 buffered 경로는 incore를 호출하지만 EAX를 검사하지 않는다. 순차 index이면
breada, 아니면 bread를 호출하고 node+0x64에 마지막 index를 게시한다.
버퍼 flag mask 0x4가 없으면 copy_to_phys(buffer+offset,page physical+진행량,길이),
있으면 버퍼+0x1c WORD를 sign-extend해 local error에 넣는다. 이 NFS buffered 본문에는
버퍼+0x28 residual에 따른 길이 재조정이 없다. 실제 buffer bounds는 하위 계약으로 확인해야 한다.

복사 후 원본 buffer flag DWORD에 대해 `&0xfffffffc == 0`인 경우에만 mask 0x400000을
추가한다. 이 조건을 특정 imported flag 이름의 조합으로 대체하지 않는다.
공통 brelse 뒤 local error가 비0인지 검사한다. 따라서 **buffer flag mask 0x4가 있지만
error WORD가 0이라는 가정**이면 그 분기에서는 복사하지 않았어도 오류 분기로 가지 않고
진행량을 갱신한다. 실제 buffer가 이런 상태를 가질 수 있다는 주장은 아니다.

읽기 오류는 vm_info+0x34에 기록하고 조건에 따라 원본 오류 문자열을 출력한 뒤 2를 반환한다.
부분 읽기 후 오류여도 앞서 복사한 bytes를 이 본문에서 되돌리지 않는다.
모든 정상 반환 경로는 runlock 후 object spin 아래 page mask 0x8을 지우고 unlock한다.
정상 종료나 missing/no-credential 경로 모두가 vm_info+0x34를 0으로 초기화하는 것은 아니다.

Ghidra는 이 함수에 `undefined8`과 `CONCAT44`를 붙였다. 원본 경로의 EDX에는 pointer 또는
해제 교환 값 등 서로 다른 값이 남을 수 있다. 82차 실제 caller는 callback 직후
`MOV EDX,EAX`로 status를 취한다. 이를 구조화된 64비트 반환 계약으로 채택하지 않는다.

## NFS pageout target — 0x133de4

현재 thread=pageoutThread, node+0x60 mask 0x1, node+0x68에서 연결된 +0x188 비0의
조합이면 rlock_timeout 호출 없이 2를 반환한다. 그 외에는 rlock_timeout(node,5)의
반환이 **정확히 1일 때** 2를 반환한다. timeout 인자의 단위나 다른 반환값 의미를 외부
소스로 보충하지 않는다. 이 두 진입 거절 경로는 자체 runlock을 하지 않는다.

credential은 vm_info+0x30 또는 허용된 현재 context의 active_u+0x1c를 사용한다.
pagein과 달리 node+0x70을 마지막 fallback으로 사용하는 분기는 없다. vm_info credential이
없고 현재 context fallback도 허용되지 않으면 출력·runlock 후 2다. active_u에서 읽은 값의
추가 NULL 검사는 없다. 선택 후에는 WORD 증가 → 기존 node credential crfree → +0x70 게시다.

각 chunk는 mask하지 않은 mount block size로 quotient/remainder를 구하고
block 잔여와 요청 길이의 작은 값으로 정한다. mapping callback 직후 node+0x62 WORD가
비0이면 sign-extend해 vm_info+0x34에 저장하고 오류 처리한다. 이 node error는
현재 mapping 함수 자체가 설정하는 값이라고 단정할 수 없다. 원본 mapping target은
그 필드를 쓰지 않는다.

node error=0x1c를 지우는 store(0x133f3b)는 **vm_info+4 WORD가 0인 출력 분기 안에만**
있다. 원본 문자열은 device full을 지칭한다. 그 밖의 0x46/기타 오류와 출력 생략 분기는
이 store를 거치지 않는다. 숫자만 보고 모든 오류가 소비되어 초기화된다고 해석하지 않는다.

mapping output이 signed 음수이면 출력/runlock 후 2다. 전체 block chunk이면 getblk,
부분 chunk이면 bread를 사용한다. 버퍼 flag mask 0x4이면 vm_info+0x34에 sign-extended
버퍼 error WORD를 쓰고 brelse/runlock 후 2를 반환한다. NFS pagein과 달리 이 오류 분기는
error WORD가 0이어도 2를 반환한다. 자체 residual 길이 clamp는 없다.

정상 버퍼에서는 copy_from_phys를 먼저 호출하고 node+0x98 크기를 필요시 증가시킨다.
요청 길이·진행량·offset을 바꾸고 node+0x60 mask 0x10을 세운 뒤,
chunk+block offset=block size이면 buffer mask 0x400000을 세워 bawrite,
그 외에는 bdwrite를 호출한다. **두 함수의 반환값은 검사하지 않는다.**
남은 길이가 0 또는 이번 길이가 0이면 runlock 후 0이다. 앞선 chunk의 복사·크기·쓰기 제출을
후속 실패에서 취소하는 본문은 없다. 현재 반환 0은 영속 저장 완료 증명이 아니다.

## UFS pagein target — 0x145848

vnode+0x30의 inode를 얻고 inode+0x44 WORD mask 0x1이 있으면 mask 0x10을 세워
`sleep(inode,0xa)` 후 재검사한다. C 출력의 `sleep(inode)`에는 두 번째 인자가 빠졌다.
원본 caller PUSH와 sleep callee의 EBP+0xc 읽기를 함께 보존했다. 잠금을 얻은 경로는
inode flag BYTE에 mask 0x5를 추가한다.

inode+0x40의 vnode와 +0x50의 filesystem geometry, page_size를 사용한다.
inode size(+0x6c)가 offset+page_size DWORD보다 작으면 zero-fill을 호출한다.
geometry+0x50 shift, +0x48의 보수 mask, +0x30 block size로 block index/offset/길이를
계산하며 파일 끝으로 길이를 제한한다. EOF에서 진행량=0이면 1, 일부 진행했으면 0이다.

bmap 직전 uerror BYTE(+0x68)를 저장하고 0으로 지운 뒤
`bmap(inode,index,1,block_offset+length,0)`을 호출한다. 결과를 geometry+0x64만큼 shift하고,
새 uerror BYTE를 sign-extend해 취한 뒤 이전 BYTE를 복구한다. 새 error가 있으면
vm_info+0x34 기록·출력·inode unlock/wakeup 후 2다. shifted mapping이 signed 음수이면
진행량과 무관하게 unlock/wakeup 후 1이다. bmap 내부 의미는 별도로 검토해야 한다.

선택 block 크기 계산에는 index의 signed 0xb 비교와 inode EOF, fragment 관련
geometry+0x34/+0x4c mask가 사용된다. geometry 값의 허용 조합은 아직 전역 확인되지 않았다.
선택 크기=page_size, 진행량=0, block offset=0이면 breadDirect를 호출한다. 비순차 접근이면
rablock/rasize를 0으로 만든다. last index는 direct-read out-error 검사 **전에** 게시한다.
out-error가 비0이면 vm_info 오류 기록·unlock/wakeup·출력 후 2이며,
0이면 반환 byte 수로 계획 길이를 signed clamp한다.

buffered 경로는 순차 접근이면 breada, 그 외 bread다. 버퍼 잔여 DWORD(+0x28)를 선택
buffer 크기에서 뺀 값으로 계획 길이를 signed clamp한 후 버퍼 error flag를 검사한다.
error flag가 있으면 sign-extended error WORD를 vm_info에 쓰고 brelse 후 2다.
아니면 copy_to_phys, 조건부 buffer mask 0x400000, brelse, 진행량 갱신이다.
남은 길이가 signed 0 이하 또는 이번 길이가 0이면 0으로 종료한다.

residual clamp 식 자체에는 block offset을 한 번 더 빼는 항이 없으며, 음수 결과를 별도로
거르는 분기도 없다. 이는 전체 buffer 계약을 조사할 이유이지 실제 잘못된 복사 증명이 아니다.
정상 반환의 inode unlock은 mask 0x1을 지우고, 이전 mask 0x10이 있으면 함께 지워 wakeup한다.

## UFS pageout target — 0x145bbc

같은 inode sleep 재검사 후 mask 0x1을 세운다. 요청 길이와 block의 남은 공간으로 chunk를
정하고 uerror BYTE를 보존·초기화한 뒤 bmap의 mode=0x20을 사용한다. 호출 뒤 이전 uerror를
복구하고, 새 error가 비0이거나 shifted mapping이 signed 음수이면 vm_info+0x34 기록·출력·
unlock/wakeup 후 2다. **mapping 음수, uerror=0인 조합에서는 vm_info 오류 값으로 0을
기록해도 반환 status는 2**다. 두 채널을 동일한 값이라고 가정하지 않는다.

inode size(+0x6c)는 chunk 끝이 더 클 때 `0x145c9f`에서 **getblk/bread 이전**에 증가한다.
이 점은 NFS pageout의 copy 이후 크기 증가와 다르다. 전체 block chunk이면 getblk,
아니면 bread다. UFS pagein과 같은 signed residual clamp 후 buffer error를 확인한다.
buffer 오류에서는 sign-extended error WORD를 vm_info에 쓰고 brelse·unlock 후 2를 반환하며,
이미 증가한 inode size를 이 본문에서 되돌리지 않는다.

정상 경로는 copy_from_phys 후 진행량·길이·offset을 갱신한다. block 끝까지 썼으면
mask 0x400000과 bawrite, 아니면 bdwrite다. 반환값은 검사하지 않는다.
그 뒤 inode+0x44 BYTE |=0x42, inode+0x64 WORD &=0xf3ff를 수행하고
microtime(&iuniqtime)를 호출한다. 당시 inode flags에 따라 +0x74/+0x7c/+0x84 DWORD에
시간 값을 쓰며 mask 0x40 경로는 inode+0x4c도 0으로 만든다.
동일 offset의 다른 객체와 혼동하거나 외부 헤더의 mode/flag 이름을 붙이지 않는다.

남은 길이=0 또는 이번 길이=0이면 unlock/wakeup 후 0이다. 이 함수 자체는 최초 길이=0을
반복문 전에 건너뛰지 않는다. 다만 82차 vnode_pageout caller는 길이 0일 때 callback 자체를
생략한다. 다른 직접/간접 caller의 입력 전제는 별도다. zero progress나 부분 제출 뒤의 0을
요청 전체 영속 저장 성공으로 확대하지 않는다.

## 교차 연결에서 남는 것

NFS pagein의 page mask 0x8과 vmp_push의 skip 조건, object+0x44의 I/O 증감,
inode/node 잠금, credential 게시, buffer 오류와 vm_info+0x34를 원본으로 연결했다.
다음은 아직 증명되지 않았다.

- bread/breada/breadDirect/getblk의 실제 buffer 크기·residual/error 일관성과 완료 계약.
- bawrite/bdwrite의 제출·지연/비동기 완료, 후속 오류 저장·전파와 파일시스템/장치 하위 경로.
- rlock/timeout/runlock, nfs_validate_caches의 필드 변경, mount block-size 검증과 bmap 전체.
- vm_fault/vm_pageout_scan의 모든 return 소비·재시도·page/object 수명 및 object-event 깨우기.
- 기존 packed 기록 선해제/교체 실패와 모든 상위 배타성·등록 sentinel의 실제 도달성.

선택 spin 18곳은 메모리 재읽기가 아니라 register TEST로 돌아가는 원본 `75fc` backedge를
보존했다. C의 반복 메모리 읽기나 생략된 XCHG를 그대로 원본 동시성 의미로 채택하지 않는다.
이번 검토는 독립 계획 교차검토를 새로 수신하지 않았다. 실패 요청을 재시도/우회하지 않았으며,
새 구현·검증기·에뮬레이터나 live DB 변경 없이 원본 대조와 Python 증거 계산만 수행했다.
Ghidra 스킬은 기존 본문·참조 export를 읽고 원본과 대조하는 절차에 적용했다.
전역 원본 분석 목표는 계속 미완료다.
