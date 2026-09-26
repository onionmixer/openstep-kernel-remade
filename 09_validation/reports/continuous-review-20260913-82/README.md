# 82차 — pager 등록·종료, I/O 실패, transient 참조와 잠금

OPENSTEP 원본 x86 바이너리만 분석했다. 외부 소스와 복원 코드는 참고하지 않았다.
등록 caller의 검사, 종료 호출 순서, packed 기록 사용자의 실패 처리, lock_done의 깨우기
조건을 원본 명령어로 연결했다. 실제 실행에서의 도달성·배타성·전체 수명은 아직 미완료다.

## 검증 범위와 산출물

[계획과 범위](SCOPE.md), [기계 판독 증거](object-lifetime-evidence.json),
[이전 파일 보존](preservation.json), [최종 재검증](checkpoint.json),
[남은 분석](OPEN_ITEMS.md).

전체 본문 ASM/C를 읽고 Python의 별도 x86 디코더로 원본 바이트를 대조한 함수는
`vnode_pager_shutdown`, `vnode_pager_truncate`, `lock_done`, `lock_init`,
`mach_swapon`, `vswap_allocate`, `unmount_all`, `vnode_pagein`, `vnode_pageout`,
`vnode_has_page`, `vnode_pager_vput`, `vnode_pager_vget`이다.

- 본문 12개, 명령어 head 710개, 본문 바이트 1,960개.
- 직접 분기 95개, 직접 CALL 36개, 간접 CALL 3개, export 경고 2개.
- 제한적 연결 window 6개·68 head, 정적 vnodeops 슬롯 8개, 문자열 8개.
- 선택 numeric target에 대한 export 참조 64행·서로 다른 명령어 60개.
- 입력 57개 fingerprint, 이전 보존 파일 783개 재검증, 핵심 피연산자 42개 명시 대조.

숫자는 모두 Python으로 계산했다. 본문 바이트는 export body의 합집합이며 entry와 마지막
RET 사이의 단순 span이 아니다. 원본 file mapping·명령어 길이·본문 범위·직접 분기/CALL을
검증했지만, 별도 디코더가 모든 C 해석이나 전체 커널 동작을 증명하는 것은 아니다.
이번에 IDA/Hex-Rays 독립 재분석이나 native 실행을 수행하지 않았다.

## 등록 caller와 종료 경로

### mach_swapon — 0x17d7e0

원본 stack 인자는 경로, flags, 최소 크기, 최대 크기 순서다. `suser` 반환이 **0이 아니어야**
계속하며 0이면 0xd를 반환한다. `pn_get(path,0,&local)` 실패는 0x16으로 바꿔 반환한다.
이 숫자에 외부 헤더의 errno 이름을 붙이지 않는다.

경로 길이+1만큼 kalloc, 길이만큼 strncpy, 마지막 BYTE 0 기록 후
`lookuppn(&local,1,0,&vnode)`를 호출한다. lookuppn 후에는 pn_free를 호출한다.
반환 0일 때 vnode+0x28이 1인지 검사하고, 등록 list에서 descriptor+8과 vnode의
포인터 동일성을 검사한다. 종류 불일치는 0x16, 중복은 0x10이다.
이 list 순회는 진입 전과 다음 노드로 이동한 뒤 모두 sentinel을 검사한다.

`0x17d8c8`의 file_init 성공 후 descriptor+0x2c에는 flags의 low bit만,
descriptor+0x28에는 복사한 이름을 게시하고 EDI=0으로 이름 소유권을 넘긴다.
공통 정리에서는 vnode가 비NULL이면 `0x17d8ef`에서 vn_rele를 한 번 호출하고,
이름이 남아 있으면 `0x17d900`에서 kfree한다.

이 본문에는 등록 수·packed BYTE ID 상한 검사가 없다. kalloc 반환 NULL을 검사하는
명령도 없다. 그러나 이를 모든 상위 진입 조건의 부재나 실제 할당 실패로 확대하지 않는다.
81차 file_init은 후속 mount callback 실패 전에 vnode/credential WORD를 증가시켰다.
현재 caller에는 추가 crfree나 명시적 등록 취소가 없다. lookup 참조와 file_init 증가분의
최종 균형은 실제 lookup·credential·callback 계약까지 연결해야 하며, 누수로 확정하지 않는다.

### vnode_pager_shutdown — 0x17d778

list가 비어 있지 않으면 head descriptor의 vnode를 `0x17d792`에서 vn_rele한다.
**그 호출 뒤에** descriptor의 next/previous를 다시 읽어 양방향 링크와 head/tail을
수정하고 `0x17d7c6`에서 전역 count를 감소시킨다. 다음 반복은 전역 head를 다시 읽는다.

전체 본문에는 descriptor·bitmap·이름을 해제하는 kfree, ID table 지우기,
credential crfree, transient 참조의 0 대기 또는 별도 잠금이 없다.
명시적 메모리 writer는 링크 변경과 count 감소다. vn_rele 이하의 간접 효과까지
없다는 뜻은 아니며, dangling pointer나 use-after-free가 실제 발생한다고 판정하지 않는다.
Ghidra C의 합쳐진 전역 대입을 실제 모든 경로의 store로 세지 않는다.

### unmount_all — 0x108ca0

원본 직접 호출 순서는 다음과 같다.

`proc_shutdown → kill_tasks → mfs_cache_clear → vm_object_cache_clear → fd_shutdown → vm_object_shutdown → vnode_pager_shutdown`

그 뒤 rootvfs의 연결 list를 순회한다. `0x108ce2`에서 next를 저장한 후 dounmount를
호출하며, 실패를 출력해도 다음 노드로 계속한다. 마지막에는 rootdir의 vn_rele 후 rootvfs를
dounmount한다. 종료 순서를 확인한 것이며 각 선행 함수가 모든 pager 사용자를 중지시켰다는
증명은 아니다. 따라서 shutdown의 ID table 미삭제를 일반 동작 중 제거와 동일시하지 않는다.

## descriptor 선택과 sentinel 잠금 겹침

`vswap_allocate`(0x17d914)는 count가 signed 1보다 크면 다음 우선순위로 descriptor를
찾는다. 첫 후보를 얻은 pass에서 끝나고, pass 내부에서는 signed free 값이 현재 최대보다
엄격히 클 때만 바꾸므로 동률은 먼저 만난 후보를 유지한다.

| pass | descriptor+0x2c 비0 필요 | vnodeops=원본 UFS 표 필요 |
| --- | --- | --- |
| 0 | 예 | 예 |
| 1 | 예 | 아니오 |
| 2 | 아니오 | 예 |
| 3 | 아니오 | 아니오 |

각 pass의 후보 free 값은 초기 최대값 0보다 커야 한다. count=1이면 이 조건들을
검사하지 않고 head를 반환한다. 그 밖의 count<=1이면 NULL이다.
이 함수는 descriptor 포인터만 선택한다. 본문에는 페이지 할당, 예약, 카운터 증가,
명시적 메모리 store 또는 잠금이 없다.

81차 findpage의 실패 후 next 이동은 다음 노드가 sentinel이어도 시작 노드가 아니면
`0x17cb00`으로 돌아간다. 그곳은 free count 확인보다 먼저 lock_write를 호출한다.
sentinel `0x1e7288`을 descriptor로 해석했을 때 lock 위치를 Python으로 계산하면:

| 가상 lock 필드 | 절대 주소 | 원본 ID table과의 겹침 |
| --- | --- | --- |
| +0 owner DWORD | 0x1e72bc | table[10] |
| +4 reader WORD | 0x1e72c0 | table[11] 하위 WORD |
| +6 flags/recursion WORD | 0x1e72c2 | table[11] 상위 WORD |
| +8 spin DWORD | 0x1e72c4 | table[12] |

따라서 free==0 검사 자체가 이 가상 lock 접근보다 앞선 보호 장치인 것은 아니다.
이 주소들이 원본 __bss의 zero-fill 선언에 속함은 확인했지만, loader 실행이나 현재 값이
0임은 확인하지 않았다. 실제 등록 수, 주소 값, 동시 실행, 그 경로의 도달성은 미완료다.

## lock_init, lock_done과 transient 참조

`lock_init`(0x15b54c)은 bzero(lock,0xc) 후 spin DWORD=0, reader WORD=0,
owner DWORD=0xffffffff를 쓴다. +6 WORD의 최종 값은 두 번째 인자의 low bit가
0이면 0, 1이면 8이다. 초기화 범위는 12바이트이며 바깥 구조 전체의 초기화가 아니다.

`lock_done`(0x15b73c)은 +8 spin을 잡은 뒤 다음 순서로 필드를 바꾼다.

1. +4 reader WORD가 비0이면 이를 감소시킨다.
2. reader=0이고 +6 WORD의 0xfff0 부분이 비0이면 그 부분에서 0x10을 빼며 low bits를 보존한다.
3. 아니면 +6 BYTE의 mask 0x1이 있으면 그것을, 없으면 mask 0x2를 지운다.

그 뒤 `[lock+4] DWORD & 0x4ffff == 0x40000`이면 +6의 mask 0x4를 지우고
`thread_wakeup_prim(lock,0,0)`을 `0x15b7bd`에서 호출한다. **spin 해제 XCHG는
그 뒤 `0x15b7c4`**다. 깨우기 조건은 reader WORD와 mask 0x4를 검사하며,
writer/upgrader 또는 recursion 전체가 0인지 검사하는 조건이 아니다.
예컨대 reader=1, flags=6이라는 가정에서는 감소 후 reader=0, flags=6으로 깨우기를
호출하고 flags=2가 남는다. 이는 유한 비트 계산이며 그 입력 상태의 native 도달성은 별도다.
owner 검사·owner 재설정도 이 본문에는 없다.

`vnode_pager_vget`(0x17c978)은 전역 vstruct_lock 아래 pager+0xe WORD를 증가시키고,
**잠금을 해제한 뒤** pager+0x14를 읽어 반환한다. `vput`(0x17c944)은 같은 WORD를
감소시킨다. 자체 overflow/underflow 검사, 0이 되었을 때의 wakeup/free는 없다.
vput·lock_done의 마지막 EAX에는 해제 XCHG의 이전 spin 값이 남는다. 이 값을
새로운 오류 코드 계약으로 간주하지 않는다.

선택 본문의 spin 8곳은 `LOAD EAX → TEST EAX → JNZ TEST`이며 짧은 backedge는
`75fc`다. 반복마다 메모리를 다시 읽는 C while과 같다고 취급할 수 없다.
pagein/pageout/vget의 C는 일부 XCHG의 lock=1 및 재시도 표현을 생략했다.
vput C의 해제 전 단순 read도 원본의 atomic XCHG 반환과 구분한다.

## packed 기록 caller와 I/O 후처리

`FUN_0017cd58`의 원본 mode caller는 다음과 같다. 함수 이름은 원본 심볼이 없어
Ghidra 주소 이름을 유지한다.

| caller와 CALL | mode | 기록 함수가 5를 반환한 경우 |
| --- | --- | --- |
| pagein, 0x17d32b | 1 | 1 반환; I/O 및 optional output 갱신 생략 |
| pageout, 0x17d443 | 0 | transient WORD 감소·unlock 후 2 반환 |
| has_page, 0x17d55c | 1 | 0 반환; 그 외에는 1 |

### vnode_pagein — 0x17d2d0

page+0x14의 object에서 pager(+0x28)를 얻고, vstruct_lock 아래 pager+0xe WORD를
증가시킨 후 잠금을 해제한다. byte offset은 page+0x18과 object+0x2c의 DWORD 합이다.
pager+0xc의 mask 0x1이 있으면 mode=1로 packed 기록을 조회한다.
성공 기록에서는 low BYTE로 ID table을 찾고, 상위 부분을 page_shift만큼 왼쪽 이동해
backing offset을 만든다.

missing이 아니면 `ops+0x74(vnode,page,offset)`을 호출하고 원본 반환값을 유지한다.
optional output이 비NULL이면 **callback 결과가 오류여도** `[[vnode]+0x34]`를
output에 쓴다(0x17d385). missing 경로만 이 쓰기를 건너뛴다.
마지막 transient WORD 감소는 다시 전역 spin 아래 수행한다. 이 잠금이 조회와 I/O
전체를 감싼다고 해석하면 안 된다.

### vnode_pageout — 0x17d3bc

마찬가지로 transient WORD만 잠깐 잠그고 증가시킨다. 비파일 pager 분기(mask 0x1이
없는 분기)에서는 offset+page_size의 **DWORD 합과 unsigned 비교**로 길이를 줄인다.
EOF와 같거나 넘어선 offset의 보통 예에서는 길이가 0이 될 수 있다. overflow 예에서는
합이 작아져 길이가 그대로 유지될 수도 있으나, 그 입력의 실제 도달성은 확인하지 않았다.
`0x17d435`에서 pager flag를 다시 읽으므로 첫 번째 읽기를 고정한 단일 조건으로 줄이지 않는다.

mode=0 기록 함수가 5를 반환하면 `0x17d46b`에서 transient WORD를 감소시키고
unlock 후 2를 반환한다. 81차에 확인한 기존 backing bitmap 선해제와 기록 교체 실패에 대해,
**이 caller 본문은 packed 기록·bitmap·배열 증가를 복구하지 않는다.**
배열 증가 실패와 기존 기록 교체 실패는 서로 다른 경로이며 합쳐 설명하지 않는다.

기록을 얻으면 backing vnode/offset을 다시 정하고 필요한 vm_info+0x14 크기를
`0x17d4b1`에서 **I/O 전에** 증가시킨다. 길이가 비0일 때만
`ops+0x78(vnode,[page+0x24],length,offset)`을 호출한다. 이 caller는 callback 실패 후에도
앞선 크기/기록 변경을 되돌리지 않고 실패를 출력한 뒤 transient 참조를 정리해 반환한다.

길이가 0이면 callback 없이 status=0으로 진행한다. 따라서 I/O를 하지 않아도
`page+0x1e BYTE |= 0x20`과 `pmap_clear_modify([page+0x24])` 호출을 수행한다.
외부 정의에서 page flag 이름을 가져오거나 이것만으로 저장 성공을 단정하지 않는다.

### vnode_has_page — 0x17d530

NULL pager 또는 mask 0x1이 없는 pager는 원본 panic 호출로 간다. 정상 경로는 mode=1
조회 결과가 5인지 여부를 0/1로 바꾼다. 자체 transient 참조 증가나 잠금은 없다.
상위 caller가 수명과 배타성을 확보하는지는 별도 검토 대상이다.

## vnode_pager_truncate — 0x17db54

인자는 pager 포인터나 배열 길이가 아니라 **packed DWORD 기록**이다. low BYTE로
ID table을 조회하고 descriptor+8의 vnode를 잠금 전에 저장한다. packed 상위 index보다
descriptor+0x20 high-water가 signed 비교로 크거나 swapfs_enabled가 비0이면 돌아간다.

lock_write 후 index-1부터 bitmap의 설정 비트를 아래로 검색한다. 비트를 발견한 경우에만
high-water를 그 index로 바꾼다(0x17dbf4). 찾지 못하면 기존 high-water를 유지한다.
이 함수에는 bitmap bit clear, free count 증가, packed 배열 length 감소 또는 buffer free가 없다.

후보 pages=high-water+1이며 minimum(+0x1c)이 비0이고 후보가 signed 비교로 minimum보다
엄격히 크고, 후보의 DWORD byte 크기가 vm_info+0x14 이하일 때만 setter를 호출한다.
이름만 보고 항상 backing file이 줄어든다거나 마지막 page를 해제한다고 해석하지 않는다.
예컨대 빈 bitmap에서도 old high-water가 유지되므로 후보 크기가 기존 크기와 같을 수 있다.

vattr_null의 이전 원본 body를 다시 대조했다. 실제 속성 버퍼는 EBP-0x40부터 64바이트이고
크기는 EBP-0x28, 즉 버퍼+0x18에 쓴다. C의 `local_44[24]` 표기는 실제 쓰기 범위를
충분히 나타내지 않지만, 해당 64바이트가 현재 local frame 밖으로 넘는 것은 아니다.

active_u+0x1c를 저장하고 vnode의 vm_info+0x30으로 교체한 뒤
`ops+0x18(vnode,attr,cred)`을 `0x17dc39`에서 호출한다. 일반 반환이 오류여도 출력 후
현재 active_u를 다시 읽어 저장한 credential을 복구하고 lock_done한다.
fault/non-return/context 교체 시까지 복구를 보장한다는 뜻은 아니다.
bitmap 주소 산술의 음수 보정 `0x17dba2`는 바로 앞 TEST/JL와 TEST/JGE 및 backedge JNS
때문에 이 본문의 정상 로컬 제어 흐름으로는 실행되지 않는다.

## 참조 조사와 후속 연결

선택 target에 대한 full-pass5 references.tsv의 모든 numeric 행을 보존했다. 같은 명령의
서로 다른 operand 행은 그대로 유지하고 명령어 head 개수는 별도로 계산했다.
표의 DATA 태그만으로 읽기·쓰기를 판정하지 않는다. 예컨대 `0x17d75d`의 ID table
indexed MOV는 DATA로 표시되지만 원본은 store다.

export상 file_init 직접 caller는 mach_swapon, pager_shutdown 직접 caller는 unmount_all,
findpage 직접 caller는 FUN_0017cd58이다. pageout 상위 직접 CALL은
`vmp_push`(0x15fdce), `vmp_push_all`(0x15ffa6), `vm_pager_put`(0x17a2b1)에서 발견했다.
pagein은 vm_pager_get의 0x17a279, has_page는 vm_pager_has_page의 0x17a32a와 연결된다.
caller의 CALL 한 명령 확인을 caller 전체 의미 검증으로 확대하지 않는다.
직접 참조가 없는 함수도 dead code 또는 외부 호출 불가로 판정하지 않는다.

원본 vnodeops의 +0x74/+0x78 슬롯을 읽어 다음 target을 확보했다.

| 원본 표 | +0x74 | +0x78 |
| --- | --- | --- |
| NFS | 0x1338c0 | 0x133de4 |
| FIFO | 0x139444 | 0x139444 |
| SPEC | 0x139b14 (_spec_badop) | 0x139b14 (_spec_badop) |
| UFS | 0x145848 | 0x145bbc |

이것은 정적 table 연결이며 실제 모든 vnode의 runtime target 집합이나 각 함수 동작을
확정한 것이 아니다. 후속 원본 분석은 [미완료 목록](OPEN_ITEMS.md)에 유지한다.

## 판정

선택한 원본 본문·피연산자·호출 순서 검토는 완료했다. 독립 계획 교차검토를 새로
수신하지 않았으며 성공했다고 기록하지 않는다. Ghidra 스킬은 기존 export의 전체 본문과
참조를 원본과 대조하는 데 적용했고, DB 수정·외부 코드 비교·구현을 유발하지 않았다.
전역 분석 목표는 완료되지 않았다. sentinel의 실제 전제, 오류의 상위 처리,
I/O target, lock/wakeup·종료 수명 및 전역 누락/경고/실패 검토를 계속해야 한다.
