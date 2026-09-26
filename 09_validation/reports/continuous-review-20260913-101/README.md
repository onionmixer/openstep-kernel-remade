# 101차: task/thread·PCB 생성, 복제, 종료와 지연 해제

OPENSTEP x86 원본과 기존 추출 자료만 대조했다. 다른 프로젝트의 소스, 복원 소스,
외부 문헌을 의미 판단에 사용하지 않았다. 이번 결과는 선택한 본문과 직접 호출의
정적 분석이며 전체 커널 분석 완료, 실행 안전성 또는 실제 누수의 증명이 아니다.

일반 본문 26개와 fallthrough fragment 6개에서 명령 2,058개/6,289바이트를
원본 재디코드했다. 직접 분기 215개, 직접 CALL 164개, 간접 전이 1개,
핵심 명령 215개를 대조했다. 모든 주소·크기·참조 수·비트 연산은 Python으로 계산했다.

## 객체 구분

| 표기 | 원본 포인터 관계 | 이번에 확인한 구분 |
| --- | --- | --- |
| A / K | task A, K=[A+0x40] | K는 task machine-state 블록이며 PC shared state가 아니다. |
| T / P | thread T, P=[T+0x28] | P는 PCB이며 T+0x70은 스케줄러 값, P+0x70은 별도 할당 포인터다. |
| U / S | U=[P+0x70], S=U+0x84 | U는 224바이트 할당, S는 그 안의 92바이트 사용자 저장 상태다. |
| W | W=[P+0xec] | PC wrapper이며 W+4에 별도로 보유한 map을 저장한다. |

## 생성과 실제 호출 ABI

`task_create` 0x165a20은 자체 본문에서 EBP+8/+0xc/+0x10의 세 인자를 읽는다.
원본 사용은 parent, inherit flag, 출력 포인터다. 디컴파일에 붙은 ledger 등을 포함한
다섯 인자 선언은 이 물리적 소비와 맞지 않는다. `kernel_task_create` 0x1659ac의
0x1659c0 호출도 세 인자를 PUSH한다. C의 추가 미정의 인자를 실제 입력으로 취급하지 않는다.

새 task는 A+4에 참조 수 2를 기록하고 A+0x40을 0으로 만든 뒤
`pcb_common_init` 0x18d5c4를 호출한다. 이 함수는 28바이트 K를 할당하고
K+8 bitmap 포인터와 K+0xc 크기를 0으로, LDT 관련 필드를 기본값으로 초기화한다.
inherit 분기는 VM map 복제를 선택하지만 자체 경로에는 부모 K/bitmap 복사가 없다.
하위 호출의 모든 alias writer까지 닫았다는 뜻은 아니다.

새 map 경로는 스택 인자를 나누어 해석해야 한다. map용 세 값이 먼저 놓인 상태에서
0을 PUSH하고 `pmap_create` 0x18f644를 호출한다. 0x165ab6의 `ADD ESP,4`는
pmap 인자만 제거한다. 반환 EAX를 다시 PUSH한 뒤 `vm_map_create` 0x1746a0가
네 인자를 소비한다. C가 앞선 pmap 호출에 map 인자까지 붙이고 다음 호출에서 누락한
표현은 원본 ABI가 아니다. map 하한은 DWORD `page_mask & ~page_mask`로 0이다.
pmap/map의 자체 초기화와 반환을 확인했으나 하위 VM 전체 계약은 미완료다.

`kernel_task_create`는 생성 뒤 task 참조를 하나 내리고 map을 교체하며
0x165a12에서 A+0x50을 1로 만든다. 기존 99차 I/O bitmap 함수의 A+0x50 조기 반환과
연결된다. 반환 직전 EAX에는 task 포인터가 남는데 C는 void로 표현한다.
초기 2→1은 중간 호출이 참조 수를 바꾸지 않는 전제 아래의 해석이다.

`thread_init` 0x166a8c의 thread template은 file-backed 데이터가 아닌 common 영역이다.
확인한 명시적 MOV 33개에는 참조 수 2, 상태 0x102, bootstrap continuation 0x18dce0가 있다.
이를 파일에 들어 있는 완성 template 값으로 보고하지 않는다.
`thread_create` 0x166c48은 CLD/REP로 396바이트를 복사하고 새 PCB를 만든다.
부모 task 참조 수와 thread 수를 증가시키고 목록에 연결한 뒤 A+8 active를 검사한다.
비활성이면 thread_terminate와 thread_deallocate를 호출하고 5를 반환한다.
이 분기에는 자체 output 게시와 정상 경로의 nthreads 증가가 없다.

## 사용자 저장 상태의 생성·복제

`pcb_init` 0x18d520은 파일의 244바이트 zero template을 복사한다.
P+0은 내장 TSS인 P+8을 가리키고 크기는 104, I/O offset WORD도 104다.
이 초기화 자체에는 할당 실패에 대한 NULL 검사가 없다.

`thread_user_state` 0x18dc54는 필요할 때 224바이트 U를 할당하여 P+0x70에 게시하고,
CLD/REP로 U+132부터 92바이트를 초기화한다. 이후 사용자 selector와 flags를 기록한다.
U의 앞 132바이트는 이 함수 자체의 초기화 대상이 아니다. 실제 미초기화 노출 여부나
그 영역의 전체 writer/reader를 확인한 것은 아니다.

`thread_dup` 0x18ea90은 필요하면 원본 thread 쪽 U도 할당한다. 복사 범위는
S의 92바이트이지 PCB 전체, TSS, bitmap 또는 FP 상태가 아니다.
0x18ebb5는 child task의 +0x3c 객체에서 +0x30 WORD를 부호 확장하고,
0x18ebb9에서 저장 EAX 슬롯 S+0x2c에 쓴다. 이 필드의 고수준 이름은 단정하지 않는다.
저장 EDX 슬롯 S+0x24에는 1을 쓰고 S+0x40 flags의 bit 0을 지운다.

## 참조 수와 최종 해제

`task_deallocate` 0x165bec은 참조 수 감소 결과가 정확히 0일 때만 최종 해제로 진행한다.
반면 `thread_deallocate` 0x166ea0과 interrupt 변형 0x167184는 감소 뒤 TEST/JLE로
DWORD 결과를 signed 비교한다. 비정상 참조 수에 대한 계산 예시는 증거에 있지만,
그 값이 실제 실행에서 발생했다는 주장은 하지 않는다.

일반 thread 해제는 첫 검사 뒤 참조 수를 임시 1로 설정하고 잠금을 풀었다가,
pset/task/list/thread 잠금을 얻은 상태에서 다시 감소·검사한다.
사이에 참조가 추가되어 두 번째 결과가 양수면 최종 해제를 중단한다.
단일 DEC만 보고 해제 시점을 판단하면 이 재검사를 놓친다.

최종 경로는 task 목록에서 thread를 제거한 뒤 상태를 검사한다.
조건은 `(state & 0xfffffeeb) == 2`이며 이를 막연한 ‘정지 상태’로 바꾸지 않는다.
0x167118의 task_deallocate가 stack/PCB 해제보다 먼저다.
이 순서만으로 use-after-free를 선언하지 않는다. PCdestroy는 task map을 직접 다시
읽는 대신 W+4의 별도 map을 사용한다. 그 map의 전체 참조 계약은 여전히 미완료다.

`pcb_terminate` 0x18ebd4의 순서는 FP 처리, 선택적 PCdestroy, U 해제,
소유 flag에 따른 외부 TSS 해제, T+0x28=0, PCB zone 반환이다.
0x18ec0f의 P+0xf0 BYTE bit 2가 외부 TSS 해제를 고르며 주소/크기는 P+8/+0xc다.
0x18ec28의 thread PCB 포인터 제거는 zfree보다 앞선다. PCB 내부 모든 필드의 scrub이나
CPU의 TSS 사용 종료, IRQ/타이머 정지는 이 순서만으로 보장되지 않는다.

`pcb_common_terminate` 0x18ec58은 `kfree([A+0x40], 0x1c)`만 호출한다.
자체 본문에는 K+8 bitmap 추적·해제, lock_done, A+0x40=0 기록이 없다.
task_deallocate와 task_terminate의 inline 최종 정리 모두 이 함수를 호출한다.
이는 지역적 해제 동작의 확인이며 실제 bitmap 누수 확정이 아니다.
다른 소유자·alias·상위 및 하위 호출의 정리를 확인해야 한다.

`fp_terminate` 0x18a800은 thread가 BSS의 FP owner와 일치하면 owner를 0으로 만들고
CR0에 bit 3을 설정한다. 0x18a81c는 실제 CR0 쓰기인데 C는 반환식처럼 표현한다.
BSS owner를 파일에서 읽은 초기 정수 값으로 보고하지 않는다.

## 종료 요청과 reaper

`task_terminate` 0x165cc0은 A+8을 0으로 만든 뒤 task_hold/task_dowait를 호출한다.
그 사이 재활성화가 없다면 `task_hold` 0x166094는 5를 반환하여 hold를 증가시키지 않는다.
종료 함수는 이 상태를 자체 검사하지 않는다. `task_dowait` 0x16610c에는 must_wait=1을
넘겨 inactive 상태에서도 목록을 처리한다. 성공한 hold를 전제로 종료 동기화를 설명하지 않는다.
task 목록의 다른 thread에는 force_terminate/deallocate를 반복한다.
현재 thread의 임시 목록 제거와 이후 재삽입·종료도 있지만 전체 참조 균형은 미완료다.

`thread_terminate` 0x16727c의 자기 자신 경로는 active를 지우고 AST 관련 비트를 설정한 뒤
0을 반환한다. 자체 경로에서 즉시 PCB를 해제하지 않는다. 다른 thread 경로는
thread_halt/IPC 종료/deallocate를 호출한다. `thread_force_terminate` 0x167424는
기존 active가 0이 아니었을 때만 해당 deallocate를 수행한다.
thread_halt 및 AST 소비의 실제 완료 계약은 이번에 닫지 않았다.

`thread_deallocate_interrupt` 0x167184는 최종 후보 참조를 1로 돌리고
T+0/+4 링크로 reaper queue에 넣어 깨운다. 이 함수에는 PCB 해제가 없다.
`reaper_thread_continue` 0x168564는 잠금 아래 dequeue하고 잠금을 푼 뒤 상태를 처리한다.
원본 0x168628의 14개 분기 표에서 low nibble 6은 rem_runq 경로,
7/0xb/0xe/0xf는 sleep·재검사 경로다. 이후 0x1686ce에서 일반 thread_deallocate를 호출한다.
queue 제거, 종료 요청, 실제 메모리 해제는 서로 다른 시점이다.

## 검증 한계와 산출물

기존 ASM 5,253개를 manifest와 대조한 지정 직접 caller 조사에서 25개 호출을 확인했다.
선택 본문 밖의 hit는 호출 edge만 확인한 것이며 해당 함수 전체 분석으로 세지 않는다.
register-only spin 45개와 C warning 13행도 별도 기록했다. 이는 각각 실제 deadlock 수나
독립 결함 수가 아니다. 신규 독립 Codex 계획 검토는 받지 않았고 구현 코드는 작성하지 않았다.
Ghidra 스킬의 본문·호출·제어 흐름 대조 절차를 기존 export/raw 비교에 적용했으며 DB는 수정하지 않았다.

[범위](SCOPE.md) · [디컴파일 주의점](DECOMPILER_ISSUES.md) · [남은 분석](OPEN_ITEMS.md)
· [원본 증거](object-lifetime-evidence.json) · [보존 해시](preservation.json) · [검증](checkpoint.json)
