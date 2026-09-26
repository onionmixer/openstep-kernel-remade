# 99차 — PCB·I/O bitmap·TSS 전파의 원본 계약

## 결과와 한계

OPENSTEP 원본에서 PCB/task 초기화, I/O bitmap 수정과 thread별 TSS 전파,
선택한 할당·해제·복사 함수 및 Objective-C caller를 대조했다.
첫 bitmap 확장의 kfree(0,0) 전달, TSS 복사 뒤 추가 요청 바이트,
실제 bit-loop의 범위 제한, selector stack 재사용과 C 표현 차이를 확인했다.
이는 지역 분석 결과이며 native 오류·안전성·전체 kernel 완료를 주장하지 않는다.

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Ghidra 스킬의 본문/호출/제어 흐름 대조를 기존 export와 원본 bytes에 적용했다.
다른 코드는 참고하지 않았고 계산·해시·재디코드는 Python으로 수행했다.
새 독립 계획 교차검토를 받지 않았으며 검토 통과로 표시하지 않는다.
원본·DB·export·기존 완료 보고서는 변경하지 않는다.

Python 집계: 일반 본문 13개와 fragment 1개, 총 14개 본문의 1,037개 명령/2,858바이트.
직접 분기 105개, 직접 CALL 53개, 간접 JMP 3개, 핵심 명령 128개,
memset static footprint 경로 46개, selector 참조 5개를 검사했다.
입력 48개와 기존 보존 경로 887개를 확인했다. export 경고 2행은 원본 결함 수가 아니다.

자료: [범위·계획](SCOPE.md), [원본·산식 증거](object-lifetime-evidence.json),
[C 표현 차이](DECOMPILER_ISSUES.md), [보존](preservation.json),
[체크포인트](checkpoint.json), [미완료](OPEN_ITEMS.md),
[이전 결과](../continuous-review-20260913-98/README.md).

## 1. 초기화와 필드 구분

A=task, K=`[A+0x40]`, T=thread, P=`[T+0x28]`, B=`[P]`로 표기한다.
K는 task machine state이며 앞선 PC shared state M과 다른 객체다.

`_pcb_common_init` 0x18d5c4는 kalloc(0x1c), lock_init(K+0x10,1)을 호출하고
K의 base/size를 기본 LDT 값으로, K+8 bitmap pointer와 K+0xc size를 0으로 쓴다.
K를 A+0x40에 게시한다. 이 본문 자체에는 할당 NULL 분기가 없다.

`_pcb_init` 0x18d520은 zalloc의 EAX를 P로 게시한 뒤 CLD/REP로
0x1d14ec의 0x3d DWORD template을 복사한다. Python으로 244바이트와 원본의 전부 0을 확인했다.
P에는 embedded TSS 주소 P+8, P+4에는 크기 0x68을 기록한다.
P+0x6e WORD에 0x68을 쓰므로 초기 B+0x66 I/O offset은 104다.
P+0xf0 ownership flag의 초기값은 template의 0이다.

별도 TSS 할당을 소유하게 되면 P+8/+0xc를 allocation pointer/size로 사용한다.
그러나 초기 embedded 상태에서는 P+8이 곧 TSS의 시작이다. 항상 같은 pointer 필드라고
해석하면 안 된다. 확장 경로는 기존 header를 먼저 복사한 뒤 소유 metadata를 쓴다.

## 2. task_map_io_ports의 검사·산식

`0x18d7d4`는 (A,start,count,mode)를 DWORD 인자로 소비한다.
end는 DWORD(start+count)이며 `0x18d7ec/0x18d7f2`에서 unsigned end<=0x10000만 허용한다.
초과하면 1, A+0x50이 nonzero면 bitmap 작업 없이 0,
task_hold 실패는 4를 반환한다.

필요 bitmap 크기 N=(end+7)>>3이며 이 gate 아래에서는 최대 8192바이트다.
K write lock을 얻고 기존 크기가 N보다 작을 때 다음을 수행한다.

1. kalloc(N) → memset(new,0xff,N).
2. memcpy(new,K+8,K+0xc).
3. kfree(K+8,K+0xc) → 새 pointer/size 게시.

이 본문에는 새 할당 NULL 검사와 기존 pointer/size의 0 검사 분기가 없다.
선택한 K 초기 상태에서 첫 확장이 도달하면 kfree 인자는 (0,0)이다.

실제 bit-loop는 unsigned start<end인 경우에만 진입하고 각 반복도 이 조건으로 제한된다.
따라서 실제 수정 port는 0..65535이고 bitmap index는 최대 8191, bit는 0..7이다.
원본의 signed 나눗셈 보정 분기는 이 loop 진입 조건 아래 음수 p를 받을 수 없다.
mode!=0은 BYTE OR(1<<bit), mode=0은 DWORD 0xfffffffe의 ROL 후 낮은 BYTE로 AND한다.
Python으로 bit별 mask 및 범위를 확인했다.

| start | count | DWORD end | gate | 수정 loop | N |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 통과 | 비어 있음 | 0 |
| 0xffff | 1 | 0x10000 | 통과 | 진입 | 8192 |
| 0xfffffff0 | 0x20 | 0x10 | 통과 | 비어 있음 | 2 |
| 0x10000 | 0 | 0x10000 | 통과 | 비어 있음 | 8192 |

wrapped 요청이 검사에 통과한다는 사실을 음수/OOB bit write로 바꾸어 주장하지 않는다.
빈 loop라도 bitmap 할당·전파가 일어날 수 있다는 것이 이 지역 경로의 차이다.

bitmap 변경은 task_dowait(A,1)보다 앞선다. 이후 0x18d610의 전파,
task_release, lock_done 순서이며 task_hold 뒤의 callee 오류를 검사하는 자체 분기는 없다.
98차의 현재 thread hold/wait 제외와 release 균형은 계속 미완료 계약이다.

## 3. TSS 확장·bitmap 복사와 추가 바이트

전파 `0x18d610`은 task lock 아래 다음 thread reference를 얻은 뒤 task lock을 풀고
이전 reference를 해제한다. 현재 thread의 PCB/TSS를 처리한 뒤 다시 task lock을 얻는다.
K의 bitmap N에 대해 desired=DWORD(N+0x69)를 계산하고 P+4가 작으면 새 TSS를 할당한다.
원본 `0x18d6b1/0x18d6b2/0x18d6b7`은 CLD와 REP DWORD로 기존 header 104바이트를 복사한다.
기존 별도 allocation 소유 flag가 있으면 이전 allocation을 해제하고,
P+8/+0xc 및 P+0/+4를 새 pointer/size로 게시하며 flag mask 4를 세운다.

현재 active T이면 TSS descriptor를 갱신하고 `0x18d766`에서 memory WORD selector로 LTR한다.
크기 확장 여부와 관계없이 B+0x66의 WORD offset을 읽어
`0x18d781`에서 memcpy(B+offset,K bitmap,N)를 호출한다.

초기/copied offset이 104이고 복사가 유효하게 전진한다는 조건에서:

| N | 요청 크기 | header 구간 | bitmap 구간 | 이 복사들이 쓰지 않는 추가 구간 |
|---|---|---|---|---|
| 0 | 105 | [0,104) | [104,104) | [104,105) |
| 1 | 106 | [0,104) | [104,105) | [105,106) |
| 8192 | 8297 | [0,104) | [104,8296) | [8296,8297) |

이 본문에는 추가 바이트를 명시적으로 채우는 store나 새 TSS 전체 memset이 없다.
그러나 allocator 초기값·다른 writer·실제 offset·실행 시점의 값은 미확인이므로
이를 확정적인 미초기화 값, 권한 오류, 정보 노출로 표현하지 않는다.

N=0이라도 전파는 초기 크기 104보다 큰 105를 요구하여 확장할 수 있다.
반면 bootstrap `0x18dce0`의 `0x18dd15`는 K size=0이면 bitmap 블록을 건너뛴다.
nonzero bootstrap은 같은 header 크기·요청 산식·offset memcpy 구조다.
task_map의 최대값을 모든 미검토 K writer까지 일반화하지 않는다.

## 4. 할당·해제 하위 계약

kalloc `0x15a75c`과 kfree `0x15a824`는 size class와 runtime maximum을 사용한다.
첫 class의 원본 file 값은 16이다. runtime max>=16이고 zone이 유효하면
kfree(0,0)는 첫 zone을 선택해 zfree에 NULL element를 전달하는 경로가 된다.
kfree 자체에 NULL/zero-size no-op 분기는 없다.

zfree `0x16b84c`는 lock/선택적 duplicate 검사 후 free-list 삽입을 수행한다.
`0x16b8d0`은 MOV DWORD [EDI],EAX이며 EDI는 element 인자다.
element NULL을 즉시 반환하는 자체 검사가 없으므로 위 조건에서는 주소 0을 목적지로 하는
store 경로가 존재한다. 실제 zone/lock/list, 호출 도달성, 주소 0의 runtime mapping을 확인하지
않았으므로 native crash/쓰기 결과를 확정하지 않는다. panic fallthrough fragment는
바이트 대조에 포함했지만 panic이 실제 돌아온다고 가정하지 않는다.

zalloc wrapper `0x16b790`의 C는 void지만 원본은 하위 0x16b364의 EAX를 보존해 반환한다.
그 하위 allocator는 아직 의미 검토를 완료하지 않았다.
kalloc의 large 경로는 kmem_alloc_wired가 실패하면 반환 local을 0으로 쓴다.
따라서 지역적으로 NULL 반환이 가능하며 이 본문에 zero-fill 보장은 없다.

kmem_alloc_wired `0x173d1c`의 자체 경로는 vm_map_find 실패를 EAX=1로 정규화한다.
backing helper 실패는 map 삭제 후 EAX=6이며, 성공 때만 output pointer를 쓰고 EAX=0이다.
성공 경로의 vm_map_pageable 결과는 자체 검사하지 않는다.
page/object/wire/ref 및 실제 초기값까지 확인한 것으로 취급하지 않는다.

## 5. memcpy·memset의 한정된 접근 범위

memcpy `0x1013e4`에는 CLD/STD/CALL이 없다. 길이 0이면 REP count=0으로 data access 없이
원래 destination을 반환한다. positive 길이의 전진 복사는 DF=0 전제가 필요하다.
signed 길이 <=15의 short 분기는 high-bit DWORD도 포함하므로 임의 길이를
표준 C 라이브러리 계약으로 치환하지 않는다.

Python으로 길이 0..8192와 source alignment의 산식 32,772개를 확인했다.
DF=0, 유효하고 겹치지 않는 nonwrapping buffer 조건에서 요청 길이 밖 terminator를 쓰지 않는다.
memset `0x101630`은 small table 31개, reachable alignment prefix 7개,
bulk reachable index 8개의 MOV 목적지 구간을 원본에서 정적으로 확인했다.
길이 0..8192와 destination alignment 산식 65,544개를 대조했다.
이는 CPU 실행·fault rollback 검사가 아니다. fill DWORD 생성은 입력을 먼저 BYTE로
mask하지 않으며, 이번 0xff caller의 결과와 임의 int 입력의 의미를 구분한다.

## 6. 원본 Objective-C caller

`kern_dev_map_port_com` 0x182190의 file-backed selector 참조는 deviceDescription,
resourcesForKey:, count, range, objectAt:이며 resource key는 I/O Ports다.
실제 runtime dispatch와 method 구현은 아직 확인하지 않았다.

range selector를 stack 아래에 미리 두고 objectAt: 호출 뒤 ADD ESP,0xc로 위 인자만 제거한다.
반환 receiver를 PUSH한 다음 호출은 남아 있던 range selector를 사용한다.
C는 이를 앞 호출의 추가 인자로 붙이고 다음 selector를 생략하여 호출 경계를 잘못 나타낸다.
다음 task_map_io_ports 호출에는 mode, EDX count, EAX start, task가 PUSH된다.
caller는 map 결과를 검사하지 않고 마지막에 EAX=0을 반환한다.
실제 range method의 반환 ABI·유효 입력·권한·상위 오류 처리까지 확정하지 않는다.
