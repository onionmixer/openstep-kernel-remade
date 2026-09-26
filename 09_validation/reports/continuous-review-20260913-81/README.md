# 81차 — OPENSTEP 원본 vnode 설치·재사용과 pager 기록 확장

80차의 서로 다른 표 저장 offset을 내부 vnode 포인터와 연결했다. pager 확장에서는
새 하위 블록의 전체 ID 슬롯 초기화를 확인했다. 동시에 실패 전 부수 효과, 기록 교체,
원형 목록 sentinel 처리에 관한 추가 원본 검증 과제를 식별했다. 전체 분석 완료는 아니다.

## 근거와 검증 경계

원본 SHA-256:
`33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
이전 checkpoint SHA-256:
`5b14112a16249a99d31e94ad41e01e016973124cf251445bc92b87ea84d3e7b5`.

16개 선택 본문의 전체 ASM/C를 읽고 1,854 instruction head, 5,590바이트를 Python으로
원본 file-backed Mach-O에 매핑·재디코딩했다. 직접 분기 212곳, 직접 CALL 86곳,
간접 호출 7곳, C 경고 10개가 포함된다. 별도 window 2개는 7개 head다.
입력 59개와 이전 보존 파일 777개, 주요 operand 42곳을 검증했다.
주소·개수·폭·bit·해시·유한 예제는 모두 Python 계산이다.

[원본 근거](object-lifetime-evidence.json)는 선택 함수의 원본 bytes/offset/decode와
주소별 근거, 문자열, 산술을 보존한다. `raw_order_anchors`의 주소는 같은 JSON의
`functions[].instructions`를 가리킨다. [범위](SCOPE.md)와 [미해결 목록](OPEN_ITEMS.md)을
분리했다. 다른 코드·복원 소스·외부 구조체 정의는 참고하지 않았다.

## 표 offset과 내부 vnode

B는 할당/검색이 반환한 저장소 base, V는 여기서 사용되는 내부 vnode 주소다.

| 원본 경로 | V | ops 저장 위치 | 참조 WORD | data 역포인터 |
| --- | --- | --- | --- | --- |
| makenfsnode | B+0xc | B+0x28 = V+0x1c | B+0x12 = V+6 | B+0x3c = V+0x30 |
| specvp/makespecvp, FIFO 포함 | B+4 | B+0x20 = V+0x1c | B+0xa = V+6 | B+0x34 = V+0x30 |
| new_inode/iget 내부 vnode | B+0xc | B+0x28 = V+0x1c | B+0x12 = V+6 | B+0x3c = V+0x30 |

NFS/SPEC 생성 API는 내부 V를 반환하지만 new_inode/iget는 B를 반환한다.
fifosp 역시 B를 반환하고 이를 받은 specvp가 최종 V를 만든다. 이 차이를 지우면
80차의 vnode+0x1c/+0x30/+6 접근과 잘못 연결된다. UFS에서 vm_info_init에 전달하는
B+0xc와 B+0x3c의 자기 역포인터가 내부 vnode 관계를 뒷받침한다. 모든 외부 caller의
B→V 변환이나 다른 writer의 불변성까지 이번에 증명한 것은 아니다.

### NFS 생성·검색·재사용

`_makenfsnode`(0x12f4ec)는 FUN_0012f8a8(filehandle,mount)에서 기존 B를 찾는다.
없으면 free-list와 signed `_rnew`/`_nrnode` 조건에 따라 재사용하거나 zone 할당한다.
재사용은 목록 head를 먼저 바꾼 뒤 FUN_0012f7d0, rp_rmhash, rinactive를 호출한다.
새 할당은 B+0xc를 0으로 만든 뒤 vm_info_init(B+0xc)를 호출한다. 새 allocation의
NULL을 자신의 본문에서 검사하지 않는다. allocator 실패 계약은 별도다.

두 경로는 B+0xc의 vm_info 포인터를 저장하고 B를 0xc8바이트 bzero한 뒤 그 포인터를
복원한다. mfs_uncache(V) 후 vm_info 첫 DWORD=0 및 +0x14를 B+0x98에서 기록하고,
handle을 B+0x40에 복사한다. WORD B+0x12=1, B+0x28=nfs_vnodeops, V+0x30=B,
V+0x24=mount를 설정하고 hash 삽입 helper와 mount+0x128의 +0x18 증가를 수행한다.
선택 attr가 있으면 원본 type 값 4와 +0x1c sentinel 조합을 type 8/WORD 0으로 바꾸는
특수 분기가 있다. 실제 enum 의미는 외부 코드로 보충하지 않았다.

기존 B 또는 생성한 B 모두 0x12f654에서 V=B+0xc를 만들고 반환한다. 기존 객체에
attr가 있으면 nfs_cache_check를 먼저, 그 뒤 nfs_attrcache를 호출한다. 기존 객체에
ops를 다시 쓰는 경로는 없다. callee에 의한 변경을 포함한 재사용 불변식은 여전히 남는다.

FUN_0012f8a8은 handle의 선택 BYTE XOR와 mask 0x3f로 bucket을 고르고,
bcmp(B+0x40,handle,0x20)==0 및 B+0x30==mount를 검사한다. hit는 B+0x12 WORD를
증가시킨다. old WORD=0이면 free-list에서 분리하고 mount 관련 count를 증가시킨다.
이후에도 B 첫 DWORD가 nonzero인지 다시 검사해 남은 free-list 연결을 분리한다.
일치 실패는 B+8 hash-next를 따라가며, 반환은 V가 아니라 B다. 자신의 lock이나
WORD overflow guard는 없다. 부분 레지스터 AL로 hash를 만들지만 AND EAX,0x3f가
상위 bit를 제거하므로 미정 EAX 상위값을 bucket 범위에 포함해서는 안 된다.

### SPEC/FIFO 생성과 기존 객체 조회

`_fifosp`(0x1394f0)는 B를 0x8c바이트 할당·bzero하고 B+0x20=fifo_vnodeops를 기록한다.
입력 vnode의 ops+0x14를 `(vnode, EBP-0x40, active context)`로 호출한다. **결과 EAX를
검사하지 않고** 지역 attr의 시간 쌍을 B+0x4c..+0x60에 복사한 뒤 B를 반환한다.
callee 실패에도 attr가 채워지는지는 아직 증명하지 않았다.

`_specvp`(0x139648)는 FUN_00139a30(dev,underlying,type)에서 B를 찾는다. 없으면
underlying type==8일 때 fifosp, 그 외 kalloc/bzero(0x68)와 spec_vnodeops 설치를 한다.
SPEC의 ops+0x14 호출은 FIFO와 달리 결과가 0일 때만 시간 쌍을 복사한다.
B+0x38=underlying, WORD+0xa=1, B+0x34=B 등을 설정한다. underlying이 있으면 그
V+6 참조를 증가시키고 type/mount를 복사한다. type==3이면 specvp(0,dev,3)를 호출해
B+0x3c에 별도 V를 연결한다. underlying이 없으면 type=3, mount=0, B+0x3c=B+4다.
즉 그 경우 +0x3c는 자기 내부 vnode다. 80차 SPEC inactive가 underlying 분기 안에서만
+0x3c를 release하는 점과 연결되지만 전역 참조 수명 전체는 아직 완료하지 않는다.

후단에는 WORD dev를 8bit shift한 index와 `_nblkdev`를 signed 비교하고,
base 0x1e2d04의 stride 24 callback을 호출하는 경로가 있다. 원본 SHR DX,8 뒤의
index 범위는 0..255이며 부호 확장해도 음수가 되지 않는다. callback 결과가 -1이면
B+0x48=0, 그 외 값을 저장하고 조건부로 연결 data의 +0x48도 채운다. 이 callback의
전체 target 집합은 미해결이다. 마지막 반환은 B+4다.

FUN_00139a30은 dev 상·하 BYTE 합 & 0xf로 bucket을 고르고 WORD B+0x42와 B+0x2c를
비교한다. underlying이 같으면 hit, 서로 다른 non-NULL이면 ops가 같은 경우에만
ops+0x6c `(stored_underlying, requested_underlying)` 결과 nonzero를 hit로 받는다.
두 underlying이 모두 NULL인 경로도 hit다. hit에서 WORD B+0xa를 증가시키고 B를
반환한다. callee 후 B+0x38 재읽기 및 목록 순회는 보존해야 한다. 동등성 callback이나
hash 삽입·제거를 여기서 전역 완료 처리하지 않는다.

`_makespecvp`(0x1397b0)는 같은 조회 helper를 사용한다. 기존 B의 WORD+0x40 mask 1이
있으면 mask 0x10을 세우고 **sleep(B,0xa)** 후 조회부터 재시작한다. Ghidra C는 두 번째
stack 인자를 생략하지만 원본 PUSH 및 sleep의 EBP+0xc 읽기로 확인된다.
lookup이 증가시킨 참조를 이 재시도 본문에서 감소시키지는 않는다. 실제 대기·재진입 시
참조 수를 누가 균형 맞추는지는 후속 과제다. 새 객체 경로는 spec 표·역포인터·WORD 참조를
설정하고 최종 B+4를 반환한다.

## UFS inode 생성·iget와 디스크 복사 범위

`_new_inode`(0x1405ec)는 zalloc 실패 시 0을 반환한다. 성공하면 B를 0xe8바이트 지우고
자기 hash 연결, free 연결 0, B+0x3c=B, B+0x28=ufs_vnodeops를 기록한다.
vm_info_init(B+0xc) 뒤 그 vm_info+0x38의 mask 4를 지우며 inode_list에 연결하고 B를
반환한다. `_iget`(0x140798)의 새 inode 할당 부분도 같은 관계를 설치한다.

iget는 getmp와 fs 포인터 일치를 먼저 검사한다. 실패 문자열은 원본의 `iget: bad dev`,
`iget: bad fs`다. hash는 (inode number + sign-extended device WORD)&0x1ff,
bucket stride 8, base 0x1f5100이다. hit의 WORD B+0x44 mask 1이면 wait mask를 세우고
sleep(B,0xa) 후 처음부터 재조회한다. 다른 hit 경로는 필요 시 free-list에서 빼고
mask 0x100/1을 설정하며 WORD B+0x12를 증가시켜 B를 반환한다.

miss는 free head를 쓰거나 새 inode를 만든다. 할당도 안 되면 dnlc_purge1 결과가 1인 동안
재시도하고, free head가 생기면 첫 조회로 돌아가며 없으면 원본 out-of-inode-space panic이다.
free head 제거 시 **0x140980의 next+0x60 역연결 기록이 0x140987의 head 기록보다 먼저**다.
C 출력은 head를 먼저 바꾼 것으로 표현한다. 원본 동시성/직렬화 계약 없이 두 순서를
같다고 취급하지 않는다.

재사용 B에서는 mfs_uncache(V), WORD flags=0x100 후 mask 1을 세우고 참조 WORD=0을
검사한다. 기존 hash에서 분리해 새 bucket에 붙이고 dev·mount 관련 값·inode number·fs를
설정한다. 그 뒤 원본 DWORD DIV/IMUL/SHL로 bread 인자를 만든다.
inode number를 fs+0xb8로 나눈 quotient/remainder, fs+0xbc/+0x1c/+0x18/+0x10,
fs+0x78/+0x60/+0x64가 사용된다. Python 예제는 비영 divisor를 가정한 주소 산술이며
실제 디스크 geometry나 I/O 검증이 아니다. 본문 자체의 divisor-zero 검사는 없다.

bread 결과 첫 BYTE mask 4가 있으면 brelse 후 hash를 제거하고 자기 연결로 되돌린다.
inode number·참조 WORD를 지우고 필요 시 wakeup, flags를 지운 뒤 free-list 꼬리에
다시 연결해 EAX=0을 반환한다. 할당 저장소를 zfree하는 경로가 아니다.

정상 읽기는 (inode number % fs+0x78)*0x80 + buffer+0x20에서 byte_swap_inode_in을 호출한다.
참조 WORD=1과 vnode 관련 필드를 설정하고, B+0x64 WORD>>0xd로 원본 type 표를 읽는다.
inode number==2의 flag와 mount+0x124에 따른 WORD identity 대체가 있으며 원래 값을
B+0xe4/+0xe6에 남긴다. brelse 이후 vm_info 첫 DWORD=0과 size(+0x14)=B+0x6c를
기록하고 B를 반환한다.

`_byte_swap_inode_in`(0x1930b8)의 직접 destination과 조건부 bcopy 지정 범위는
**B+0x64..B+0xe3, 128바이트**다. ops가 있는 B+0x28과 겹치지 않는다. source+0xc와
+8의 DWORD는 각각 B+0x6c/+0x70으로 가므로 단순한 연속 memcpy가 아니다.
source+0x64의 byte-swapped 값 bit 1에 따라 source+0x28의 0x3c바이트를 그대로 복사하거나
DWORD 단위로 swap한다. 나머지 WORD/DWORD mapping은 JSON에 보존했다. 이 범위
검증만으로 iget의 모든 callee가 vnode 필드를 보존한다고 주장하지 않는다.

`_vm_info_init`(0x15e0b4)은 V의 첫 DWORD가 nonzero이면 그 저장소를 재사용하고, 아니면
vm_info_zone에서 할당한다. 선택 필드만 0으로 만들고 BYTE+0x38은 `(old|4)&0xec`로
바꾼다. lock_init(info+0x18,1) 뒤 info+0x24=0, 마지막에 *V=info를 기록한다.
전체 구조체 bzero가 아니며 자신의 allocation NULL 검사는 없다. 기존 B+0xc를 보존해
재사용하는 생성 경로와 연결되지만 allocator·lock_init의 전체 계약은 남겨 둔다.

## pagerfile 등록과 bit 초기화

`_vnode_pager_file_init`(0x17d588)은 먼저 *out=0, mfs_uncache(vnode)를 수행한다.
vm_info+0x38 mask 0x10이면 상태 0x10을 반환한다. 그 외 원본 ops+0x14로 attr를
가져오지만 **그 getter의 EAX를 검사하지 않고** attr+0x18 크기를 사용한다.
요청 최소 크기가 그보다 작으면 vattr_null 후 size를 바꿔 ops+0x18을 호출하고,
이 setter의 nonzero는 반환한다. 여기에도 80차와 같은 64바이트 buffer 분할 문제가 있다.

그 후 vm_info size 기록, kalloc(0x40), vnode 참조 WORD 증가, credential 첫 WORD 증가,
vm_info+0x30 credential 기록을 수행한다. descriptor+0x1c는 요청 크기를 page 단위로
올림한 값이다. 최대 크기 인자가 0이면 mount의 표+0xc callback으로 얻은 두 DWORD의
곱을 사용한다. 이 callback 오류 시 descriptor만 kfree(0x40)하고 반환한다.
**이 본문은 앞서 증가한 vnode/credential 참조나 size/context 기록을 되돌리지 않는다.**
외부 호출자의 오류 정리가 없다는 뜻으로 확대하지 않는다.

최대 크기를 page_shift로 내린 값을 descriptor+0x14 총량과 +0x18 free 수에 기록하고,
ceil(total/8)의 bitmap 저장소를 할당한다. 전체 bzero 대신 **유효 page bit만 하나씩 clear**한다.
마지막 BYTE의 범위 밖 padding bit는 이전 값을 유지한다. +0x20 high-water=-1,
+0x24 hint=0, +0x2c=0, lock_init(+0x34,1)을 설정한다.

목록 끝에 descriptor를 연결하고 0x17d743에서 tail을 기록한 **다음** count를 증가시킨다.
C 출력은 이 count/tail 순서를 바꿨다. 증가한 DWORD count를 descriptor+0x30과
0x1e7294[count]에 사용한다. 본문에 count 상한이나 BYTE ID 범위 검사는 없다.
등록 함수의 caller 제한·실제 배열 capacity·해제 및 재등록을 더 확인해야 한다.

`_vnode_pager_init`(0x17e1a4)은 vstruct zone을 만들고 vstruct_lock=0, list prev/next를
sentinel 0x1e7288로 쓴다. 이 본문이 인접 ID table이나 global count까지 지우지는 않는다.
관련 주소는 원본 __bss 영역이며 file bytes를 런타임 초기값 0의 증거로 사용하지 않았다.

## bitmap page 할당과 findpage의 순회 경계

`_vnode_pager_allocpage`(0x17c9b0)는 descriptor+0x34를 lock_write한다. free==0이면
lock_done 후 -1이다. 그 외 hint를 signed truncation 방식으로 BYTE 위치로 바꾸고,
ceil(total/8)까지 0xff가 아닌 BYTE를 찾는다. 그 BYTE의 bit 0부터 첫 0을 고르므로
같은 BYTE 안에서 hint보다 작은 bit를 고를 수 있다. 앞 BYTE로 wrap하는 탐색은 없다.
후보 index가 signed total 미만인지 검사하고 아니면 panic한다. 음수 index에 대한 별도
하한 검사는 없다. 정상 범위 전제와 모든 hint/count writer를 아직 완료하지 않았다.

성공은 high-water를 필요할 때 올리고 bitmap bit를 OR, free--, hint=index 후 unlock한다.
bit가 이미 clear인지 확인하는 것과 free count가 전역적으로 정확하다는 증명은 다르다.

`_vnode_pager_findpage`(0x17cabc)는 위 할당 동작을 inline으로 포함한다. 성공 후 lock을
푼 다음 descriptor+0x30의 **하위 BYTE ID**를 out에 쓰고 `(index<<8)|id_byte` DWORD로
완성하여 0을 반환한다. ID=0이나 index 상위 손실에 대한 own guard는 없다.
예를 들어 DWORD ID 0x100의 하위 BYTE는 0이지만 실제 등록 가능성을 이 산술만으로
단정하지 않는다. 일반 실패 상태는 5이며, 실패에서 out을 0으로 초기화하지 않는다.

중요한 미해결 순서: 실패한 현재 노드가 sentinel이면 0x17cc09에서 head를 읽는다.
그 외에는 0x17cc14에서 next를 읽고 시작 노드와 비교한 뒤 0x17cb00으로 돌아간다.
따라서 마지막 descriptor의 next가 sentinel이고 시작 노드와 다르면, **다음 반복은
sentinel을 descriptor처럼 lock/free 검사한 뒤에야 sentinel 분기로 오는 구조**다.
단순히 모든 반복에서 sentinel을 먼저 건너뛰는 순회로 바꾸어 설명하면 원본과 다르다.

Python 주소 산술상 sentinel+0x18은 ID table[3], sentinel+0x34는 ID table[10] 주소다.
이 주소들은 __bss이며 실제 값·등록 수·외부 직렬화·lock_done/lock_write의 모든 경로를
검토하지 않았으므로 native 충돌이나 재현 가능한 오류로 판정하지 않았다.
등록 상한 및 실제 호출 경로와 함께 우선 후속 검토해야 하는 원본 제어 흐름이다.

## packed 기록과 flat/2단 배열 확장

`_pagerfile_pager_create`(0x17cc30)는 주어진 descriptor와 size로 pager를 만든다.
80차 vnode_alloc과 달리 후보 목록을 선택하지 않는다. page count를 계산해 flat 배열의
각 DWORD 하위 BYTE를 0으로 쓰거나 2단 pointer 배열 전체를 bzero한다. pager 필드를
설정하고 descriptor+0xc 증가 후 vstruct_lock 구간에서 transient WORD를 감소시킨다.
전체 pager bzero와 vnode 참조 증가를 추가로 수행하는 함수로 해석하지 않는다.

FUN_0017cd58의 stack 인자는 `(pager, byte_offset, mode, out_record)`다.
offset을 page_shift로 내린 index가 count 안에 있고, flat 또는 해당 child의 ID BYTE가
nonzero이면 out에 DWORD 기록을 복사한다. mode==1은 그 hit 여부만 0/5로 반환한다.
miss일 때 out의 기존 값을 지우지 않는다.

그 외 mode에서 기존 기록이 있으면 ID table의 descriptor와 index를 얻는다.
index<=descriptor+0x24이면 0을 반환하고 기존 기록을 유지한다. 그보다 크면 descriptor를
잠가 범위를 확인하고 bitmap bit를 지우며 free 수를 증가시킨 뒤 unlock한다.
**pager 배열의 이전 packed 기록을 여기서 지우지 않고 다음 findpage 성공 뒤에 덮는다.**
그 다음 findpage가 5를 반환하는 경로에는 이전 기록 무효화/bitmap rollback이 없다.
단, 이 실패가 실제 실행에서 가능한지는 다른 할당자·lock과 caller 계약까지 확인해야 한다.
기존 기록 hit는 이미 count 안에 있으므로 이를 무관한 array 성장 실패와 혼동하지 않는다.

필요한 new_count=index+1이 기존보다 크면 원본은 다음처럼 처리한다.

| 성장 분기 | 준비 | 기존 배열 처리 |
| --- | --- | --- |
| 새 count가 flat 범위 | 새 flat 할당, 기존 DWORD 복사, 추가 슬롯의 ID BYTE만 0 | old_count>0이면 옛 flat 해제 |
| old count=0, 새 count는 2단 | 새 pointer 배열 할당·전체 0 | 옛 배열 없음 |
| 기존 2단, pointer 수 동일 | 배열 교체 없음 | count만 갱신 |
| 기존 2단, pointer 수 증가 | 새 pointer 배열 전체 0, 기존 pointer 복사 | 옛 pointer 배열만 해제 |
| 기존 flat→2단 | 새 pointer 배열 전체 0, 첫 child 64바이트 할당, 기존 DWORD 복사, 남은 ID BYTE 0 | 옛 flat 해제 |

flat→2단에서 첫 child 할당 실패는 새 pointer 배열을 해제하고 5를 반환하며 원래 배열은
아직 교체하지 않는다. 반면 pointer 배열/count를 게시한 뒤 요청 child 할당이나 findpage가
실패하면 이미 성공한 성장 자체를 rollback하지 않는다. 실패를 모두 같은 원자적 동작으로
요약해서는 안 된다. count/곱은 DWORD이며 wrap 예제의 실제 입력 도달성은 별도다.

요청 child가 NULL이면 kalloc_noblock(0x40) 결과를 **0x17d0e1에서 pointer slot에 먼저
기록**하고 NULL 여부를 확인한다. 성공하면 0x17d101의 BYTE 기록을 index 0..15 모두에
적용한 뒤 findpage를 호출한다. 따라서 이 경로는 실제 사용 count 밖의 마지막 child
슬롯에도 ID=0을 설정한다. 상위 bytes를 0으로 만든다는 뜻은 아니다.

flat→2단 첫 child도 기존 유효 DWORD를 복사한 뒤 old_count..15의 ID BYTE를 0으로 만든다.
예: old_count=3에서 index=16을 요청하면 pointer 배열 8바이트, 첫 child에는 기존 3개
DWORD와 나머지 ID 0, 요청 child에도 16개 ID 0이 준비된다. 기존 count=17에서 index=23은
pointer 배열 크기를 바꾸지 않으며, index=32는 pointer 배열을 12바이트로 늘린다.
이들은 유한 layout 계산이며 실제 allocator 실행 예제가 아니다.

이 선택 생성/확장 경로만 보면 79차 dealloc의 모든 child 슬롯 ID 검사와 초기화 계약이
연결된다. 그러나 **child pointer가 ID 초기화보다 먼저 공개**되고 배열 교체 자체를 감싸는
own lock은 없으므로 caller의 배타성, truncate 및 다른 writer까지 검증하기 전에는
모든 중간 상태에서 안전하다는 전역 결론을 내리지 않는다.

## 디컴파일/fragment 검토와 최종 판정

0x17ce51의 음수 보정은 index가 logical SHR 8에서 왔고 lock_write가 ordinary return에서
EBX를 보존한다는 원본 근거하에 로컬로 도달하지 않는다. Ghidra의 제거 경고를 그대로
성공/실패로 세지 않고 79차 lock_write의 저장·복원 bytes와 Python 상한 계산으로 확인했다.

0x17ce3d..0x17ce3f는 panic CALL 뒤의 **ADD ESP,4**이며 NOP/padding이 아니다.
보존 metadata가 `noreturn_fallthrough_fragment`로 분류한 합성 entry다. 그 C 출력은
후속 부모 함수 경로를 따라가면서 인자 없는 호출 등을 보여 주지만, 그 자체를 별도
정상 ABI 함수나 원래 커널의 호출 가능한 API로 취급하지 않는다. 현재 부모의 ordinary
분기는 fragment 다음 0x17ce40으로 직접 온다. panic이 돌아오지 않는다는 전제와 다른
진입점의 완전성은 전역 분석 과제로 남는다.

Ghidra 스킬의 원본 대조 절차가 내부 pointer 관계, 생략된 sleep 인자, list 게시 순서,
부분 초기화와 합성 fragment의 해석을 구분하는 데 반영되었다. 원본 DB/export는 변경하지
않았다. 새 독립 계획 검토·동적 실행·구현·빌드·포팅은 수행하지 않았다.
선택한 16개 본문 검토를 전체 커널의 의미·ABI·writer·native 경로 완료로 승격하지 않는다.
