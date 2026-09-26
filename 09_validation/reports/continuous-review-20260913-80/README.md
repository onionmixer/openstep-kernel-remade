# 80차 — OPENSTEP 원본 vnode pager와 VFS callback 경계

79차에서 미해결이던 속성 buffer 초기화 범위와 마지막 vnode 참조 callback을 연결했다.
원본의 이름 있는 vnodeops 표에서 +0x18/+0x4c 주소를 확인하고 해당 대상 본문을 읽었다.
pager 생성·선택도 함께 검토했으나 모든 실행 시점의 간접 호출 대상 집합이 닫혔다고
판정하지 않는다. 전체 OPENSTEP 분석 목표는 여전히 미완료다.

## 검증 범위와 근거

원본 `03_original/x86/binaries/mach_kernel`의 SHA-256은
`33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
Ghidra full-pass5의 선택 ASM/C와 metadata를 읽고, Python으로 Mach-O file-backed
mapping과 Capstone 재디코딩을 검증했다. 외부 소스 코드와 복원 코드는 참고하지 않았다.

선택한 12개 본문은 874 instruction head, 2,493바이트다. 직접 분기 112곳, 직접 CALL
65곳, 간접 호출 2곳을 포함한다. 이름 있는 표 4개에서 8개 슬롯을 읽었다.
별도 bounded window 20개에는 58개 head가 있으며, 본문 수치와 합산한 전역 coverage를
만들지 않는다. 일부 window는 선택 본문과 겹친다.

입력 58개를 fingerprint/기존 manifest와 대조하고, 보존 대상 이전 파일 771개를 재검증했다.
이전 checkpoint SHA-256은
`04b0930920a8e771d4afd87acccc8968948b4a91e405f062dc206c4fe6b7b9bd`이다.
본문의 instruction 크기·범위 합집합·직접 분기 대상 일치를 확인했고 주요 operand 41곳을
추가 검사했다. 이는 모든 operand의 의미나 미식별 코드까지 자동 증명했다는 뜻이 아니다.

모든 계산은 Python으로 수행했다. [원본 근거](object-lifetime-evidence.json)에 파일 offset,
원본 bytes, export와 독립 decode, 주소별 근거 및 유한 산술을 보존한다.
[남은 분석](OPEN_ITEMS.md)과 [이번 범위](SCOPE.md)를 함께 읽어야 한다.

## 속성 buffer: 64바이트 초기화, 크기 DWORD는 +0x18

`_vattr_null`(0x11ea88)은 EAX=0x3f에서 시작하여 BYTE 0xff를 기록하고 포인터 증가,
counter 감소 후 -1과 비교한다. 따라서 정확히 64바이트를 기록한다.

`_vnode_dealloc`의 0x17dfb7은 EBP-0x40을 만들고 0x17dfba에서 EBP-0x5c에 보관한다.
0x17e06c/0x17e06f는 그 포인터를 vattr_null에 전달한다. 0x17e07e의 DWORD 기록은
EBP-0x28이므로 buffer+0x18이다. 초기화 범위 EBP-0x40..EBP-1은 원본의 SUB ESP,0x60
지역 frame 안에 들어간다. **Ghidra의 `local_44[24]`는 이 실제 buffer 범위를 표현하지 못한다.**
이것은 원본 stack overflow의 증거가 아니라 디컴파일의 지역 변수 분할을 그대로
C 객체 경계로 믿으면 안 된다는 근거다. 모든 필드의 원래 typedef와 의미는 아직 미확정이다.

64바이트가 모두 0xff이고 +0x18만 크기일 때, 이번 NFS/UFS 대상의 초기 금지 필드 검사는
모두 sentinel을 받는다. mode/owner/time 변경 분기도 해당 인자 값만 보면 생략된다.
크기 0xffffffff는 두 대상 모두 크기 변경 생략 sentinel이다. 유한 예제는 인자 내용에
대한 산술이며, 특정 크기의 원본 caller 도달성이나 모든 호출 중 buffer 불변성을 증명하지 않는다.

## 원본 함수 표와 마지막 참조

표 이름은 원본 nlist에서 확인했다. FUN 이름은 export 식별자일 뿐 새 원본 심볼을
추정해 붙이지 않았다. 아래 주소는 표의 해당 슬롯에서 읽은 little-endian DWORD다.

| 원본 표 / 시작 주소 | +0x18 속성 호출 대상 | +0x4c 마지막 참조 대상 |
| --- | --- | --- |
| _nfs_vnodeops / 0x1dca20 | FUN_00131a84 | FUN_00131d8c |
| _fifo_vnodeops / 0x1dd4b4 | _spec_setattr / 0x13a27c | FUN_001393d0 |
| _spec_vnodeops / 0x1dd6d0 | _spec_setattr / 0x13a27c | FUN_0013a130 |
| _ufs_vnodeops / 0x1de480 | FUN_001443d8 | FUN_00144814 |

`_vn_rele`(0x11df54)은 vnode+6 WORD가 0이면 원본 문자열 `vn_rele`로 panic을 호출한다.
그 외에는 WORD를 감소시킨다. **감소 전 값이 1일 때만** vnode+0x1c 표의 +0x4c를
0x11df92에서 호출한다. stack 인자는 `(vnode, [active_u+0x1c])`다. 자신의 본문에는
참조 변경을 감싸는 lock이나 callback 결과를 검사하는 분기가 없다. EAX에 남는 값을
공식 상태 반환 계약으로 승격하지 않는다. NULL vnode 선행 검사도 본문에는 없다.

이름 있는 표 시작 주소에 대한 export 참조 17개를 원본에서 재디코딩했다.
6개는 주소 저장이고 11개는 비교다. 저장 주소는 0x12f5ee, 0x139512, 0x13969d,
0x1397e3, 0x140626, 0x1408f2다. `_smount`, `_vno_stat`, `_spec_realvp`, `_vswap_allocate`,
`_vnode_alloc`, `_vnode_uncache`의 해당 참조들은 비교다.
저장 destination은 각각의 register base+0x20 또는 +0x28이다. 이 window만으로
allocation base와 내부 vnode 포인터 관계 또는 모든 설치 writer를 완료 처리하지 않는다.
원본 nlist의 이름 검색이나 export 참조 목록은 이름 없는 표·간접 복사·동적 변경의 부재를
증명하지 않는다.

## +0x18 대상의 반환·변경 순서

### _spec_setattr / 0x13a27c

stack 인자는 vnode, attr, context다. data=[vnode+0x30], underlying=[data+0x38]이다.
underlying이 있으면 **attr+0x18을 0xffffffff로 덮은 뒤** underlying의 ops+0x18을
0x13a2b1에서 간접 호출한다. nonzero는 그대로 반환한다. 이 재위임 대상 집합은 아직
해결하지 않았다. underlying이 없으면 그 크기 요청 자체를 실행하지 않는다.

그 뒤 attr+0x28/+0x2c는 data+0x54/+0x58에, attr+0x20/+0x24는 data+0x4c/+0x50에
각 sentinel 조건에 따라 기록한다. 변경이 있으면 getthetime 결과를 data+0x5c/+0x60에
기록한다. 따라서 이 대상의 0 반환은 caller가 요청한 크기로 실제 backing이 바뀌었다는
뜻이 아니다. 입력 attr는 읽기 전용도 아니다.

### NFS 표 대상 FUN_00131a84

먼저 kalloc(0x48)을 호출하고 그 다음 attr 검사를 한다. WORD +0x14/+0x38,
DWORD +0x1c/+0x3c/+0x30/+0x34 중 sentinel이 아닌 값이 있으면 상태 0x16을 선택하고
공통 kfree 경로로 간다. 본문 자체에는 allocation NULL 검사가 없다. allocator의 실제
실패·대기 계약을 확인하지 않고 이것만으로 native 오류를 단정하지 않는다.

허용 인자이면 sync_vp(vnode)를 호출한다. 크기 sentinel이 아니면 mfs_trunc(vnode,size)를
호출하고, 그 nonzero 결과에는 sync_vp를 다시 호출한 뒤 계속 간다. 0x131afd에서
[*vnode+0x14]에 크기를 기록하고 binvalfree 이후 0x131b0c에서 [vnode+0x30]+0x98에도
크기를 기록한다. **두 기록 모두 0x131b87의 rfscall보다 앞선다.**

attr+0x28이 sentinel이 아니고 +0x2c는 sentinel인 특수 경우 getthetime으로 +0x20/+0x24,
+0x28을 채우고 +0x2c=0xf4240을 쓴다. vattr_to_sattr와 bcopy로 인자를 준비한 뒤
rfscall의 procedure 인자 2를 전달한다. 외부 프로토콜 소스로 그 번호를 해석하지 않았다.

transport 결과가 0일 때 reply 첫 DWORD를 상태로 사용한다. reply 상태 0이면
nfs_cache_check/nfs_attrcache를 호출한다. transport 또는 reply 오류에는 data+0xc0=0,
reply 0x46에는 btrash/nfs_invalidate_caches를 추가 호출한다. 공통 kfree(reply,0x48) 뒤
선택한 상태를 반환한다. **이 본문에는 앞서 기록한 크기의 rollback이 없다.** 하위 함수의
재조회·회복을 미검토한 상태이므로 파일시스템 전체가 회복하지 못한다고 확장하지 않는다.

### UFS 표 대상 FUN_001443d8

get_posix_proc를 호출한 후 attr를 검사한다. WORD +0x14/+0x38, DWORD +0x1c/+0x3c,
+0xc/+0x10/+0에 sentinel이 아니면 lock 전에 0x16을 반환한다.
그 외 data=[vnode+0x30]을 ilock하고 mode WORD+4, owner WORD+6/+8, 크기 DWORD+0x18,
시간 DWORD+0x20/+0x28 순서로 처리한다. 오류가 나면 앞선 변경을 되돌리는 자체 경로는 없다.

mode 경로는 data+0x64의 상위 type mask 0xf000을 유지하고 attr mode의 하위 0xfff를
합친다. context WORD+2, data WORD+0x68/+0x6a 및 groupmember 결과에 따른 mask 변경이
있다. **suser 반환을 통상적인 0=성공 관례로 읽으면 안 된다.** 여기서는 nonzero일 때
허용 경로로 가며, zero일 때 [global 0x1e875c]+0x68 BYTE를 부호 확장해 상태에 사용한다.
원본 suser 본문과 global writer의 전체 계약은 남겨 둔다.

크기가 sentinel이 아니면 (data WORD+0x64 & 0xf000)==0x4000에서 상태 0x15를 선택한다.
그 외 iaccess(data,0x80), itrunc(data,size)를 순서대로 호출하며 각각의 nonzero에서
공통 종료로 간다. 정상 진행에서는 **iunlock → mfs_fsync(vnode) → ilock** 순서이며
mfs_fsync의 결과를 검사하지 않는다. 크기 sentinel이어도 이 동기화 구간은 생략되지 않는다.

시간 변경은 context/owner 비교와 suser, 필요할 때 proc+0x18의 bit 1 및 iaccess를
검사한다. 그 보조 허용 경로는 오류 BYTE를 0으로 지운다. 시간 기록이 있으면 getthetime
결과를 data+0x84에 기록하고 data+0x44에 mask 8을 OR한다.
ilock 이후 공통 종료는 **iupdat(data,1) → iunlock(data) → 저장 상태 반환**이며
iupdat 결과도 반환 상태에 반영하지 않는다. sentinel-only caller에 대한 로컬 조건과
전체 권한·I/O 성공은 서로 다른 판정이다.

## +0x4c 대상의 정리 경계

FIFO의 FUN_001393d0은 stack+8의 vnode와 stack+0xc의 context를 사용한다.
sunsave(data) 다음 spec_fsync(vnode,context), data+0x38의 중첩 vn_rele 및 그 포인터
0 기록을 수행한다. 끝의 kfree는 **vnode+0x30을 다시 읽어** 크기 0x8c로 해제한다.
처음의 data snapshot과 재읽은 값이 같다는 불변식은 callee까지 확인해야 한다.
fsync 결과는 검사하지 않고 명시적으로 EAX=0을 반환한다.

SPEC의 FUN_0013a130도 context가 두 번째 stack 인자다. proc+0x18 BYTE에 mask 1을
OR하고 sunsave를 호출한다. data+0x38이 있을 때 spec_fsync를 호출하며, 이후 재조회한
+0x38이 여전히 있을 때만 vn_rele 후 0으로 지운다. data+0x3c의 추가 vn_rele도 이
분기 안에 있다. +0x3c 자체를 지우는 명령은 없다. 마지막에는 **proc+0x18에 0xfe를
AND**하고 kfree(data,0x68), EAX=0으로 끝난다. 이전 bit를 저장하지 않았으므로
원래 bit가 1인 경우의 원상 복원이 아니다. callee 변경이나 실제 중첩 진입의 도달성은
별도 분석이 필요하다.

위 두 함수의 Ghidra C는 `vnop_fsync_args *` 하나로 인자를 표시하고 spec_fsync 호출의
context를 누락한다. 원본은 별도 stack 인자를 읽고 두 값을 PUSH한다. 이 가져온 타입의
포인터 덧셈을 원본 byte offset이나 확정 ABI로 사용하지 않는다.

NFS의 FUN_00131d8c는 자신의 본문에서 vnode 인자만 사용한다. rp_rmhash 후 data+0x7c가
있으면 해당 객체를 rlock하고 setdiropargs/rfscall을 호출한다. procedure 인자는 0xa다.
transport nonzero 또는 reply 상태를 EBX에 보관한 뒤 **오류여도** runlock, vn_rele,
+0x7c=0, kfree(+0x78,0xff), +0x78=0, crfree(+0x74), +0x74=0을 수행한다.
항상 rfree(data)를 호출하고 보관 상태를 반환한다. vn_rele 자체는 이 결과를 검사하지 않는다.

UFS의 FUN_00144814는 iinactive([vnode+0x30])를 호출한 뒤 EAX를 0으로 덮는다.
iinactive의 실제 객체·저장소 정리는 이번 본문 검토 범위 밖이다.

## vnode_alloc: 선택 조건과 부분 초기화

global 0x1e7290을 signed로 비교한다. 1보다 크면 원형 목록 0x1e7288을 pass 0..3으로
조사한다. pass 0/1은 descriptor+0x2c가 nonzero여야 하고, pass 0/2는 vnode ops가
ufs 표여야 한다. **pass 1/3은 다른 ops를 배제하지 않는다.** 각 pass에서는
descriptor+0x18의 signed 값이 0에서 시작한 최고값을 엄격히 넘을 때만 후보를 갱신한다.
동률은 먼저 선택한 것을 유지하며, 후보를 얻은 첫 pass 뒤에는 후속 pass를 하지 않는다.
global count==1이면 표·flag·양수 free 검사 없이 목록 머리를 바로 선택한다.
따라서 이 함수만으로 pager의 backing vnode를 UFS/NFS로 제한할 수 없다.

후보가 없으면 0이다. 있으면 zalloc_noblock(vstruct_zone) 결과를 확인한다.
입력 크기를 page_mask/page_shift로 DWORD 반올림·shift하여 count를 pager+0x10에 저장한다.
count=0이면 +8=0이다. 그 외 DWORD count*4<=0x40이면 flat 배열, 아니면
(((count-1) DWORD >> 4)+1)*4바이트의 pointer 배열을 kalloc_noblock한다.
배열 실패에는 pager를 zfree하고 0을 반환한다.

**flat 배열은 각 DWORD의 하위 BYTE만 0으로 쓴다**(0x17daf3). 상위 bytes의 초기값은
이 본문이 보장하지 않는다. 이는 79차 dealloc이 하위 BYTE ID=0을 건너뛰는 계약과
연결되지만 모든 packed-record reader가 이 gate를 사용하는지는 남아 있다.
2단 배열은 pointer 배열 전체를 bzero하되 아직 child block을 할당하지 않는다.
예를 들어 count=17이면 pointer 배열은 8바이트지만 마지막 child의 나머지 슬롯 초기화는
이 함수로 증명할 수 없다. 큰 DWORD wrap 예제는 산술일 뿐 정상 입력 도달성 주장이 아니다.

pager+0, WORD+0xe, +0x14 vnode, BYTE+0xc의 mask 1, +4 descriptor를 설정하고
descriptor+0xc를 증가시킨다. 그 후 vstruct_lock 구간에서 WORD+0xe를 감소시킨다.
전체 pager bzero는 없고 후보 선택·descriptor count 갱신을 이 lock으로 감싸지도 않는다.
다른 계층의 직렬화를 아직 확인하지 않았으므로 무조건적인 경쟁 오류 주장은 하지 않는다.

## vnode_pager_create/setup: 인자 경계와 부수 효과

create는 zalloc 실패에 0을 반환한다. 성공하면 0x18바이트 bzero, pager 첫 DWORD=0,
WORD+0xe=1을 설정한다. `[*vnode]=pager`와 pager+0x14=vnode를 기록하고,
pager+0xc의 mask 1을 지우며 vnode+6 WORD를 증가시킨다. 이후 vstruct_lock 구간에서
pager WORD+0xe를 감소시키고 pager를 반환한다. vnode 참조 WORD overflow guard는 없다.

setup은 두 번째 인자가 nonzero이면 먼저 vnode+4에 mask 2를 OR한다. 이미 pager가
있으면 생성과 세 번째 인자 처리를 모두 건너뛰고 후단으로 간다. pager가 없고 descriptor
목록에 동일 vnode가 있으면 0을 반환하지만 앞선 mask 변경을 되돌리지 않는다.
그 외 create와 같은 inline 생성 과정을 거친다. allocation 실패도 세 번째 인자 검사로 간다.

세 번째 인자가 nonzero일 때 stack 순서는 다음과 같다. call/ret 주소 공간은 제외한
인자 영역만 표시했으며, 79차에서 확인한 실제 callee의 stack 인자 사용과 대조했다.

| 원본 위치 | stack 낮은 주소부터 | 의미 |
| --- | --- | --- |
| 0x17d28d, 0x17d293 이후 | pager, 1 | lookup에는 pager를 전달; 1은 남겨 둠 |
| 0x17d299 ADD ESP,4 이후 | 1 | lookup의 인자만 caller가 제거 |
| 0x17d29c 이후 | lookup 결과, 1 | cache_object의 두 인자 |
| 0x17d2a2 ADD ESP,8 이후 | 해당 인자 영역 없음 | 두 인자 제거 |

따라서 C 출력의 `vm_object_lookup(pager,1)` / `vm_object_cache_object(result)`는
인자 귀속이 잘못되었다. 원본 호출은 lookup(pager) 다음 cache_object(result,1)이다.
후자의 결과를 setup에서 검사하지 않는다.

후단에는 기존 pager 여부와 관계없이 zalloc(vstruct_zone) 후 그 반환값을
zfree(vstruct_zone,result)로 넘기는 구간이 있다. 자신의 본문에는 이 후단 allocation의
NULL 검사가 없다. 이 호출 쌍을 불필요하다고 제거하거나 동작을 추정하지 않는다.
마지막 반환값은 다시 읽은 `[*vnode]`다.

세 pager 함수의 spin 구간은 원본 LOAD 다음 TEST 자체로 되돌아가는 `75fc`와 XCHG를
포함한다. C의 반복 메모리 읽기와 lock=1 기록 생략을 원본과 동일하게 취급하지 않는다.
새 native 실행·scheduler 진행성 검증이나 독립 계획 교차검토는 수행하지 않았다.

## 판정

이번에 확정한 것은 원본의 선택 본문·정적 표 슬롯·제한된 참조 명령·로컬 인자 및 순서다.
스킬의 원본 대조 절차에 따라 buffer 크기, stack 인자 귀속, 가져온 타입, lock 표현의
차이를 보고서에 분리했고 원본 DB/export는 수정하지 않았다.
소스 복원·컴파일 검증·포팅은 현재 목표가 아니다. 모든 writer·간접 target·함수 경계·
미식별 영역·IDA 실패·native 경로가 완료된 것으로 판정하지 않는다.
