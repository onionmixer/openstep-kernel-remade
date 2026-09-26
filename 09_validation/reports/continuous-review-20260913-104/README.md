# 104차 — 스택 공급·회수·pageable 전환과 최초 문맥

원본 OPENSTEP x86 mk-183.34.4만 분석했다. 다른 커널 코드, 복원 소스, 외부 문서는
참조하지 않았다. 스택의 header/실제 사용 구간, cache와 VM 호출의 경계,
최초 context 진입을 원본 명령으로 연결했다. 실제 경쟁 상태·page fault·부팅 성공이나
전체 커널 분석 완료를 입증한 보고서는 아니다.

## 검증 범위와 증거

선택한 일반 본문 26개와 기존 분석 fragment 1개에서 명령 head 1,124개,
본문 3,450바이트를 원본 파일에서 Python/Capstone으로 다시 해독했다.
본문 byte 집합·head·직접 분기 목적지를 대조했고 직접 분기 107개, CALL 64개,
간접 이동 4개, Ghidra 경고 14줄을 보존했다. 핵심 명령 156개에 별도 assertion을 적용했다.
이는 이번 선택 범위의 검증량이지 전체 커널 coverage 증가량이 아니다.

원본 SHA-256:
`33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
103차 checkpoint와 기존 보존 경로 922개를 재검사했다. 현재 입력은 89개이며,
다른 소스가 포함되는 과거 항목은 다시 열지 않고 제외 이유를 기록했다.
계산·해시·주소 변환·집계는 모두 Python으로 수행했다.

[원본 명령·수치 증거](object-lifetime-evidence.json), [검증 checkpoint](checkpoint.json),
[기존 자료 보존](preservation.json), [범위·방법](SCOPE.md),
[디컴파일 주의점](DECOMPILER_ISSUES.md), [남은 분석](OPEN_ITEMS.md).

## 1. 슬롯 header와 실제 스택 구간

이 문서의 `H`는 cache header, `S=H+0xc`는 반환하는 스택 주소이다.
H+0/H+4는 목록 링크, H+8은 DWORD 상태다. 원본의 상태 쓰기/검사에 따른 분석상 표기는
0=free/cache 후보, 2=사용 중인 wired 상태 표시, 1=swapout 상태 표시이다.
특히 1/2를 실제 물리 페이지 residency의 증명으로 해석하지 않는다.

`initKernelStacks` 0x15ab9c는 head/tail을 0x1e5b98 sentinel로 설정하고,
cache lock 0x1f63d0을 초기화한다. 0x15abbf에서 stride=0x1000,
0x15abce/0x15abd3에서 DWORD `(page_size+0xfff)>>12`를 계산한다.
cache count·사용 통계·waiter flag를 자체적으로 다시 0으로 만드는 함수는 아니다.

파일에 실제 있는 count 0x1ded68=0, retention threshold 0x1ded6c=8,
waiter flag 0x1ded70=0을 확인했다. head/tail/stride/slot count는 __bss,
lock/stackStats/page_mask/kernel_map 등은 __common이다. 이들 zerofill 영역에 대해
겹쳐 보이는 파일 바이트를 읽어 초기값이라고 주장하지 않았다.

0x18ab2b의 원본 `page_size=0x2000` 쓰기도 재검사했다. 다음은 이 값이 유지되고
page_mask=0x1fff이며 VM 반환 주소 B가 페이지 정렬이라는 **조건부** 계산이다.
페이지 설정의 모든 실행 경로·writer와 하위 VM 정렬 보장은 이번에 완결하지 않았다.

| 항목 | Python 계산 결과 |
|---|---:|
| VM 페이지 크기 | 8192바이트 |
| 슬롯 간격 | 4096바이트 |
| 페이지당 슬롯 | 2개 |
| header 크기 | 12바이트 |
| 실제 스택 구간 | 4084바이트 = 0xff4 |
| kmem_alloc_wired 요청 / 반올림 | 4096 / 8192바이트 |

H=B 또는 B+0x1000이며, 각 S+0xff4는 정확히 H+0x1000이다.
이는 `stack_attach` 0x18d208이 TSS의 EBP/ESP에 넣는 S+0xff4와 연결된다.
슬롯마다 별도 guard page가 있다는 근거는 이 함수들에서 확인되지 않았다.
하위 매핑·보호 속성 전체를 검토하지 않았으므로 guard 부재 전체 증명도 아니다.

## 2. 새 할당, cache 재사용, 고갈 후 대기

`newStack` 0x15ad60은 cache를 먼저 꺼내지 않고 `kmem_alloc_wired`를 호출한다.
실패 상태는 0 반환, 성공하면 page 통계를 증가시키고 첫 H+8=2,
사용 통계를 증가시킨 뒤 S에 stack_init을 호출한다. 남는 슬롯은 각각 stack_init 후
H+8=0으로 tail에 게시하고 cache count와 cached 통계를 증가시킨다.

`allocStack` 0x15ae5c는 cache lock 아래에서 count가 0이 아니면 head를 제거하고,
H+8=2, S=H+0xc, cached 감소/used 증가 후 반환한다. **이 재사용 경로에는
stack_init이나 자체 scrub이 없다.** cache가 없을 때만 wired 할당을 시도하며,
성공 시 첫 슬롯/나머지 슬롯 처리는 newStack과 같은 형태다.

count가 0이 아닌데 head가 sentinel인 경우 0x15ae9c에서 EBX=0으로 만든 뒤
0x15aeb3의 `[EBX+8]=2`로 실제 연결된다. 0x15b398 stack_alloc_try에도 같은 형태가 있다.
이는 count/list 일치가 필요한 조건부 경로이며, 정상 실행에서 그 불일치가 생긴다거나
실제 NULL 접근이 발생했다고 단정하지 않는다. 103차의 redundant dequeue 비교와 달리
여기에는 해당 경로를 바로 앞 비교만으로 배제할 근거가 없다.

wired 할당 실패 시 최초에는 고갈 메시지를 표시한다. cache lock을 잡아 count를
다시 검사하고, 여전히 비었으면 0x15b03f에서 assert_wait(head,0),
0x15b044에서 waiter flag=1, 0x15b053에서 unlock 후 thread_block을 호출한다.
이후 active thread+0x44의 대기 결과를 EDI로 가져와 할당 루프를 재시도한다.

**대기 결과가 0이 아니라고 즉시 실패 반환하는 것은 아니다.** cache 획득과 새 wired
할당을 다시 시도한 뒤에도 실패하여, 이미 메시지를 표시했고 EDI가 0이 아닐 때
0x15afe1→0x15b08a에서 0을 반환한다. cache가 재검사 때 생겼다면 EDI를 0으로
만들고 재시도한다. 유한 시간 내 성공/해제나 전체 waiter 동시성은 미확정이다.
상위 `stack_alloc` 0x15b43c는 0 반환에 panic을 호출하고 성공 시 attach한다.
panic 뒤 0x15b455는 기존 fragment로 보존했으며 실제 panic 복귀를 주장하지 않는다.

## 3. freeStack: cache 보존, 페이지 해제, pageable 전환을 구분

`freeStack` 0x15abe0의 원본 순서는 다음과 같다.

1. 0x15abe9에서 used 통계 감소 — cache lock 획득보다 앞선다.
2. H=S-0xc, cache lock 획득, H+8=0, tail 게시, count/cached 통계 증가.
3. **0x15ac42에서 cache lock 해제.** 이후 waiter flag를 지우고 wakeup할 수 있다.
4. signed count<=threshold면 반환. 초과할 때만 H가 속한 페이지의 슬롯 상태를 검사한다.
5. 전부 0이면 각 header를 cache에서 제거하고 count/cached 감소, stack_finalize 호출,
   kmem_free 후 page 통계 감소. 전부 0이 아니면 canSwap을 검사하여 doSwapout하거나 반환.

**0x15ac42 이후 페이지 상태 검사·header 제거·회수 전에 자체 cache lock 재획득은 없다.**
doSwapout도 자체 cache lock 호출이 없다. 이는 정확한 함수 내부 경계이지,
호출자의 IRQ/상위 직렬화 전제나 실제 경쟁 상태/UAF의 확정이 아니다.
freeStack 전체에서 확인한 해당 lock CALL은 획득 0x15abfa, 해제 0x15ac42뿐이다.

페이지 해제 시 0x15ad40의 인자는 페이지 기준 주소를 저장한 local이 아니라
원래 H를 유지한 EDI다. 즉 `kmem_free(kernel_map,H,stride)`이다.
하위 `kmem_free` 0x173e90은 start=H&~mask,
end=DWORD(H+size+mask)&~mask로 만든 뒤 0x173eb0에서 vm_map_remove를 호출한다.
위의 페이지 조건에서는 H가 어느 슬롯이든 정확히 B..B+0x2000의 같은 페이지로
반올림된다. 원래 H를 넘긴다는 이유만으로 잘못된 반쪽 해제라고 판정하지 않는다.
입력 NULL·wrap·전역 설정 오류에 대한 자체 검사는 이 wrapper에 없다.

## 4. swapout/swapin의 상태와 VM 호출 경계

`canSwap` 0x15b098은 페이지 슬롯 중 H+8==2가 하나라도 있으면 0,
없으면 1을 반환한다. 모든 슬롯이 0이어야 하는 freeStack의 해제 조건과 다르다.

`doSwapout` 0x15b0dc는 상태 0인 슬롯을 cache에서 제거하고 통계를 감소시킨 뒤,
페이지 기준 주소의 첫 DWORD를 0xfeedface로 표시한다. 0x15b186에서
vm_map_pageable(kernel_map,base,rounded_end,1)을 호출하고 바로 pageable 통계를 증가시킨다.
자체 lock 획득이나 VM 반환 상태 검사는 없다.

`swapoutStack` 0x15b19c는 swapped 통계를 증가시키고 cache lock 아래에서 H+8=1을
쓴다. 같은 페이지에 상태 2가 남으면 unlock하고 끝난다. 없으면 doSwapout과 같은
cache 제거/marker/VM 처리를 내부에서 수행한다. **0x15b292의 VM 호출 동안에는 이
함수가 잡은 cache lock을 아직 유지하며**, 0x15b2a5에서 해제한다.
freeStack→doSwapout의 lock 경계와 혼동하지 않는다.

`swapinStack` 0x15b2b4는 S로부터 페이지 기준 주소를 계산하고 swapped 통계를 감소시킨다.
0x15b2ee에서 vm_map_pageable(...,0)을 **cache lock 획득 전**에 호출한다.
VM 상태를 자체 검사하지 않고 lock 획득 후 H+8=2로 게시한다.
페이지 첫 DWORD가 0xfeedface이면 marker를 지우고 pageable 통계를 감소시키며,
상태 0인 나머지 슬롯을 cache tail에 다시 게시한다. 그렇지 않으면 이 복구 루프를 건너뛴다.
marker와 실제 VM wire/unwire 성공·물리 페이지 상태의 동치는 아직 입증하지 않았다.

`kmem_alloc_wired` 0x173d1c 자체도 하위 vm_map_pageable의 상태를 검사하지 않고
출력 주소를 쓴 뒤 EAX=0으로 반환한다. map_find 실패는 EAX를 0/1로 정규화하고,
하위 0x173ebc 할당 실패 경로는 map 삭제 후 EAX=6이다. 디컴파일의 undefined1 반환형을
호출 ABI로 확정하지 않는다. 하위 VM allocation/fault/remove/rollback 계약은 남아 있다.

지정 직접 CALL 조사에서 newStack/swapoutStack/swapinStack/stack_collect의 CALL은
검출되지 않았다. 간접 호출·주소 테이블·함수 밖 코드를 닫지 않았으므로 미사용 함수라고
분류하지 않는다. 검출 여부와 별개로 위 설명은 각 본문의 조건부 동작이다.

## 5. 사용량 표시, 통계, reserve의 실제 역할

`stack_init` 0x168b28은 stack_check_usage가 0이면 아무것도 채우지 않는다.
활성화된 경우에만 S부터 index 0..0x3fc의 DWORD에 0xdeadbeef를 쓴다.
Python으로 1021개 DWORD, 4084바이트, 정확히 S..S+0xff4임을 확인했다.
파일의 stack_check_usage 0x1dfbc4와 stack_max_usage 0x1dfbc8은 모두 0이다.
런타임 변경 가능성을 배제한 결과는 아니다.

`stack_usage` 0x168afc는 선두의 연속 magic DWORD 수를 n이라 할 때 0xff4-4*n을
반환한다. 모든 값이 magic이면 0이며, 첫 DWORD가 다르면 4084다.
이 함수 자체는 enable flag를 확인하지 않는다. 사용 흔적이 magic과 우연히 같을 수 있으므로
실제 최대 stack 깊이의 무손실 측정이나 overflow 검출 보장으로 보지 않는다.

`stack_finalize` 0x168b50은 enable된 경우 같은 방식으로 사용량을 계산하고
max 통계를 갱신할 뿐, 자체 메모리 해제/zeroing을 하지 않는다.
물리적인 입력은 `[EBP+8]`의 스택 주소다. C의 추가 EAX regparm 인자를 필수 인자로
인정하지 않는다. lock 대기 0x168b8a의 `75fc`는 0x168b88 TEST로 돌아가며,
0x168b80의 메모리 load를 다시 수행하지 않는다. NOP를 허용하여 검사한 이 패턴을
별도 증거로 남겼다. 디버그 조건·동시 호출·IRQ까지 닫은 실제 hang 판정은 아니다.

`stack_statistics` 0x15b49c는 cache read lock 아래에서, debug가 켜졌으면 각 cached
스택 사용량과 **호출자가 전달한 두 번째 출력의 기존 값**을 unsigned 비교하여 큰 값만 쓴다.
그 출력을 자체적으로 0으로 초기화하지 않는다. 첫 번째 출력에는 cache count를 쓴다.
debug가 꺼지거나 cache가 비면 두 번째 출력은 그대로일 수 있다. 호출자 0x168bb8의
초기값/통계 계약 전체는 후속 항목이다.

`stack_collect` 0x15b494의 본문은 prologue/epilogue/RET뿐이다.
이 이름만으로 주기적인 스택 GC나 cache 비우기를 추론하지 않는다.

`stack_privilege` 0x166a5c는 대상이 active thread가 아니면 panic을 호출한다.
대상 T+0x30이 0일 때만 active_stacks 값을 복사한다. **자체적으로 새 스택을 할당하거나
복사하는 함수가 아니다.** stack_free 0x15b470는 detach 결과가 이 reserve 값과 같으면
freeStack을 건너뛰고, stack_alloc_try는 cache가 없으면 reserve를 사용할 수 있다.
reserve의 모든 소유권 변경·최종 해제는 아직 닫지 않았다.

## 6. 최초 context의 실제 CPU 명령과 cookie

103차 후속 항목의 0x18e0e4는 원본 심볼/최종 export에서
`_start_initial_context`이다. 여기서는 그 이름을 사용한다.
T=입력 thread, P=T+0x28의 객체, B=P[0]인 저장 문맥으로 표기한다.

0x18e0f0에서 `ldt_init` 0x18cbcc를 호출한 뒤 task/map/pmap 경로의 +0x18을 1로
표시하고, active_threads=T, active_stacks=T+0x2c,
stack_pointers=(T+0x2c)+0xff4를 게시한다. 0x18e128의 **CR3=B+0x1c 쓰기는
기존 CR3와 비교 없이 수행**된다. 일반 switch_context와 구분해야 한다.

P+0x74/+0x78을 사용해 GDT의 LDT descriptor를 만들고
0x18e16e에서 `[0x1d14ea]`의 WORD를 LLDT한다. 다음에는 B+0xc0000000의
DWORD 결과를 base로, P+4에서 1을 뺀 값을 limit로 사용해 TSS descriptor를 만든다.
access=0x89, flag-byte는 기존 값의 일부를 보존하고 limit high nibble을 합친다.
0x18e1b6은 `[0x1d14e8]`의 WORD를 LTR한다. 파일 selector 값은 각각 0x20/0x18이며,
메모리 operand라는 사실을 상수 표현으로 대체하지 않는다.

0x18e1bd/0x18e1c0/0x18e1c2는 CR0을 읽어 bit 0x8을 합친 뒤 **실제로 CR0에 쓴다**.
CR3/CR0 쓰기는 이 함수의 디컴파일 C에서 누락된다.
이후 물리 PUSH 순서는 0(cookie), B, 0(old-save)이며 0x18e1cc에서
__switch_tss 0x186f20으로 들어간다. 이 호출 지점 C에는 세 인자가 표시되지만,
helper 자체의 C와 실제 스택 ABI는 따로 대조해야 한다.

old-save=0이므로 helper는 이전 문맥 저장을 건너뛰고 return-address를 POP한다.
새 B에서 레지스터와 ESP/EIP를 읽어 JMP하며 EAX에는 세 번째 인자 0이 남는다.
B의 EIP/EBX가 stack_attach로 설정된 첫 진입인 경우, 0x186f74 trampoline은
그 EAX cookie를 PUSH하고 복원된 EBX를 CALL한다. EBX가 thread_continue 0x1639ec인
경우 cookie=0이므로 이전 thread_dispatch 호출을 건너뛰고 active T+0x34 continuation을
호출한다. **B의 모든 writer와 최초 thread 준비·continuation 선택을 완결했다는 뜻은 아니다.**
helper의 JMP와 trampoline의 CALL/HLT 경계를 정상 C return으로 바꾸지 않았다.

`ldt_init`은 원본 `_ldt` 포인터가 가리키는 descriptor +8/+0x10의 base를 0으로,
access를 0xfa/0xf2로 쓴다. low limit WORD는 각각 0xffff이고 high nibble은 0xb/0xf이다.
Python 계산상 encoded 20-bit limit는 0xbffff/0xfffff다. flag-byte는 기존 high bit 일부를
보존하므로 descriptor 전체를 0에서 재작성한다고 해석하지 않는다.
GDTR/base/descriptor 유효성, 실제 CPU privilege/IRQ/TLB/FPU 동작은 별도 미완료다.

## 7. 조사 한계와 판정

manifest에 일치하는 ASM 5,253개에서 지정 CALL 20개와 literal write 69개를 찾아
해당 명령을 원본으로 다시 해독했다. initKernelStacks 호출 0x166c0d,
start_initial_context 호출 0x18612f, stack_statistics 호출 0x168c08,
reserve caller들과 active globals의 지정 쓰기를 보존했다. 이는 직접 CALL와 명시 주소의
쓰기 조사이지 모든 alias/간접 호출/메모리 초기화/함수 밖 코드에 대한 완결된 xref가 아니다.

Ghidra 스킬의 원본 대조 원칙을 기존 export와 raw-file 검증에 적용했다.
기존 DB/ASM/C/바이너리/확정 보고서는 수정하지 않았다. 신규 독립 Codex 계획 검토는
받지 않았으며 반복 요청이나 대체 agent로 우회하지 않았다. 이 제한 아래 새 분석기 파일이나
커널 코드는 만들지 않고, inline Python 검증과 이번 보고서만 추가했다.

이번 선택 범위의 정적 검증은 통과했다. **전체 원본 분석은 미완료**이며,
후속은 lock/IRQ·waiter·reserve/통계 caller와 하위 VM wire/remove 계약을 우선 연결한다.
