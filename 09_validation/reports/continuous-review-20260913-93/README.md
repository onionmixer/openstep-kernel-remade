# 93차 — 원본 trap 복구 소비자·저장 프레임·VM fault 반환 경로

현재 범위는 OPENSTEP 원본 kernel 분석뿐이다. 외부 코드를 참고하거나 구현하지 않았다.
직전 범위 확인 응답 자체는 분석 진전이 아니므로, 이번에는 미완료 trap consumer를
원본 바이트로 추적했다. 전체 kernel 분석은 아직 완료되지 않았다.

## 이번에 확인한 핵심

- `thread +0x74`는 실제로 `0x1924a0`에서 소비된다. nonzero이면 저장 EIP를 슬롯 값으로,
  CS의 하위 WORD를 8로 바꾸고 저장 EFLAGS의 DF 비트만 지운 뒤 슬롯을 0으로 만든다.
  helper 자체에는 fault EIP의 copy 범위 검사·슬롯 목적지 검증·저장 EBP/ESP 교체가 없다.
- 일반 trap 경로는 `0x186d20 → catch_trap → kernel_trap → 0x1924a0`이며,
  일반 복귀는 원래 저장 프레임을 복원한 뒤 `IRETD`다. `0x186e3c`는 이름이 비슷하지만
  `0x192698`을 호출하는 별도 진입부이며 이 경로와 혼동하지 않는다.
- `0x186d20`을 향한 export 참조 64개가 `UNCONDITIONAL_CALL`로 표시되지만,
  각 원본 명령은 모두 `E9` direct JMP다. CALL처럼 반환 주소를 쌓는다고 해석하면 틀린다.
- `vm_fault`의 0 반환에는 최종 `pmap_enter`를 거치지 않는 대기 종료 경로가 있다.
  0 반환만으로 새 매핑 또는 wiring 완료를 증명할 수 없다. 이 경로의 실제 발생 조건은
  scheduler/wait 계약 검토가 더 필요하다.

## 증거·검증 범위

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
Python으로 선택 본문 13개, 6,929바이트, 명령 2,371개를 원본에서 다시 디코딩했다.
직접 branch 329개, CALL 136개, 간접 jump 2개와 중요 operand 158개를 대조했다.
간접 jump의 원본 dispatch table 2개·34개 항목도 검증했다.
참조 82개 중 위 64개 진입 JMP의 분류 차이를 따로 보존했다.
입력 46개와 이전 보존 파일 849개를 재확인했으며, 92차 copy 본문/복구 조각 4개의
원본 명령도 재디코딩했다. 후자는 이번 본문 합계에 중복 포함하지 않았다.

선택 body의 byte 경계 검증과 전체 의미 검증은 다르다. 특히 `vm_fault`의 전체 본문
바이트는 대조했지만, 이번 의미 검토는 반환·대기 분기·재조회·최종 매핑 경로에 한정한다.
COW/shadow/pager의 전체 상태 전이까지 검증했다고 주장하지 않는다.

기계 판독 증거는 [원본 대조 자료](object-lifetime-evidence.json),
보존 해시는 [preservation](preservation.json), 재검증 기록은 [checkpoint](checkpoint.json)에 있다.
[검토 범위](SCOPE.md), [미완료 목록](OPEN_ITEMS.md),
[이전 원본 copy/wiring 분석](../continuous-review-20260913-92/README.md)을 함께 보존한다.

## 1. CALL로 보이는 trap 진입 간선은 원본에서 JMP

`_trp_divr 0x186138`은 `PUSH 0; PUSH 0; JMP 0x186d20`이다.
`_flt_prot 0x1861c4`는 `PUSH 0xd; JMP`, `_flt_page 0x1861cc`는 `PUSH 0xe; JMP`다.
앞의 0은 error용 소프트웨어 슬롯이고 뒤 push는 trap 번호로 해석되는 위치에 놓인다.
fault stub에서 error 슬롯은 stub 자체가 만들지 않는다. 실제 하드웨어 진입의 error 생성,
IDT selector/type/present/DPL 및 초기화가 맞는지는 이번 검토만으로 확정하지 않는다.

위 세 stub의 전체 ASM/C와 경계를 읽었다. 나머지 진입 참조도 JMP opcode/길이/목적지를
각각 확인했지만, 이를 나머지 모든 stub의 push·IDT 계약까지 검증한 것으로 확대하지 않는다.
디컴파일 C의 `FUN_00186d20(); return;`은 하드웨어 진입 ABI를 표현하지 못한다.
원본 export/DB는 수정하지 않았으며 분류 차이는 이 보고서에 별도로 남겼다.

## 2. 정상 trap 저장 프레임과 복귀

`0x186d20`은 PUSHAD와 DS/ES/FS/GS push 후 DS=ES=0x10, FS=0x50, GS=0을 설정하고
`CLD`한다. EBX에는 저장 프레임 시작 F, EBP에는 F+0x18을 둔다.
`empty_stacks`가 nonzero이면 CLI 후 `stack_pointers`로 실행 스택을 옮기고
`empty_stacks=0; STI`한 뒤 원래 F를 인자로 `catch_trap`을 호출한다.

복귀에서는 CLI, ESP=EBX, `empty_stacks=ESI`, STI 후 GS/FS/ES/DS와 PUSHAD 저장값을
복원한다. `ADD ESP,8`로 trap/error 슬롯을 건너뛰고 `IRETD`한다.
Python으로 도출한 F 상대 위치는 다음과 같다.

| 필드 | F 상대 offset | 근거 |
|---|---|---|
| GS/FS/ES/DS | 0 / 4 / 8 / 0xc | 역순 segment push/pop |
| EDI/ESI/EBP | 0x10 / 0x14 / 0x18 | PUSHAD/POPAD |
| PUSHAD의 ESP 저장 슬롯 | 0x1c | POPAD에서 복원 대상으로 쓰지 않는 슬롯 |
| EBX/EDX/ECX/EAX | 0x20 / 0x24 / 0x28 / 0x2c | PUSHAD/POPAD |
| trap/error | 0x30 / 0x34 | stub 및 복귀 ADD ESP,8 |
| EIP/CS/EFLAGS | 0x38 / 0x3c / 0x40 | IRETD 직전 프레임 및 소비자 operand |

이 레이아웃은 원본 명령의 32-bit stack-slot 계약이다. 실제 descriptor 상태·특권 전이·
중첩 trap·STI 후 타이밍·전역 stack/active-thread의 안정성까지 증명하는 것은 아니다.

`catch_trap 0x187068`은 F+0x42의 BYTE mask 0x2가 설정되거나 CS 하위 2비트가 3인 경우 user 경로를
선택한다. 전자는 Python 환산으로 저장 EFLAGS의 mask 0x20000이다.
둘 다 아니면 F를 `kernel_trap`에 전달한다. user 경로의 PCexception/bitmap/user_trap
전체 의미는 아직 미검토이며 kernel 경로의 증거와 분리한다.

## 3. 복구 슬롯을 소비하는 정확한 동작

`kernel_trap`은 S=F+0x34를 사용한다. `0x1924a0(S)`는 현재 active thread를 읽고
그 +0x74가 0이면 EAX=0으로 반환한다. nonzero이면 순서대로:

1. `[S+4]` DWORD에 슬롯 값 저장: 저장 EIP를 교체한다.
2. `[S+8]` WORD에 8 저장: 저장 CS의 하위 WORD만 교체한다.
3. `[S+0xc] &= 0xfffffbff`: Python 보수 계산상 DF mask 0x400만 지운다.
4. active-thread 전역을 다시 읽고 그 thread +0x74를 0으로 만든다.
5. EAX=1을 반환한다.

슬롯을 읽은 thread와 지우는 thread는 전역을 각각 읽는다. 같은 thread라는 전제는
별도 scheduler/IRQ 계약이다. helper 자체에는 NULL active-thread 검사도 없다.
RF mask 0x10000은 이 AND로 지워지지 않는다. 이것은 해당 명령의 효과일 뿐,
하드웨어 IRETD를 포함한 전체 RF 동작을 증명했다는 뜻은 아니다.

저장 CS 상위 WORD는 보존된다. 예를 들어 초기 DWORD 0xa5a5001b는 WORD store 후
0xa5a50008이 된다. 이 예는 Python 폭 계산이며 실제 CS 값의 관측이 아니다.

현재 EIP·error 종류·copy 범위·슬롯 목적지를 검사하는 명령은 helper 안에 없으며,
저장 EBP/ESP·FS/ES도 바꾸지 않는다. 정상 trap 복귀에서 POPAD로 fault 시점 EBP가
복원되므로, copy 실행 중 발생한 fault라면 복구 조각은 그 copy의 기존 프레임을 사용한다.
92차 원본을 재확인한 결과 copyin 복구 `0x189b18`은 EAX=0xe 후 `0x189b29`의
`LEA ESP,[EBP-0xc]`로, copyout 복구 `0x189e70`은 EAX=0xe 후 `0x189e81`의
`LEA ESP,[EBP-0x14]`로 이어진다. 독립 함수처럼 새 프레임을 만들지 않는다.

따라서 **짧은 copy 정상 반환 후 남은 슬롯을 helper 자체가 만료·범위 검사로 거르지는
않는다**. 그러나 이후 적합한 fault가 실제 발생하고 슬롯이 다른 경로에서 지워지지 않으며
원래 copy 프레임이 이미 끝났다는 일련의 runtime 조건은 아직 증명하지 않았다.
이 단계에서 실제 오복귀·취약점·재현 성공으로 단정하지 않는다.

## 4. 모든 trap이 즉시 복구 슬롯을 쓰는 것은 아님

첫 jump table은 `(trap-1)`의 unsigned 범위를 검사한다.
trap 1/3은 debug helper, 7은 그대로 epilogue, 16은 FP helper 후 epilogue다.
trap 10은 저장 flags mask 0x4000 조건에서 상태 변환 후 thread_exception_return을 호출한다.
11/12/13은 error BYTE의 `&6 ==4` 조건에서 상태 변환·exception 전달·thread return 경로다.
그 외 default는 recovery helper를 호출하고 실패하면 alert/printf/backtrace/KDP/panic으로 간다.
panic 및 thread_exception_return의 실제 nonreturn 계약은 호출명만으로 확정하지 않았다.

trap 14는 CR2를 저장한다. active-thread가 nonzero이면 전역 0x1e875c가 가리키는
문맥의 error BYTE +0x68을 보존하고 0으로 만든다. VM fault 호출 뒤 active-thread 전역을
다시 검사해 BL을 복원한다. 전후 문맥 동일성은 별도 전제다.

- CR2 <= 0xbfffffff: 현재 thread→+0xc→+0xc map, `CR2 & ~page_mask`,
  error mask 0x2에 따라 prot 1 또는 3, 나머지 두 인자 0으로 vm_fault를 호출한다.
- CR2 > 0xbfffffff: `0x1923e0(CR2,S)`를 호출한다. helper는 active-thread map의
  +0x24가 kernel_pmap이면 그 map을 쓰고, 아니거나 thread가 없으면 kernel_map을 쓴다.
  VA 인자는 DWORD wrap의 `(CR2+0x40000000) & ~page_mask`다.
  page_mask=0xfff라는 가정에서는 0xc0001003이 0x1000으로 전달된다.

`0x1923e0`의 C는 void처럼 나오지만 원본 CALL 뒤 MOV ESP/POP EBP/RET는 EAX를
덮지 않는다. kernel_trap은 이 EAX를 상태로 사용한다. C signature만 믿으면 이 반환을 놓친다.

VM 상태가 0이면 recovery helper를 건너뛰고 반환한다. 이 경로는 슬롯과 저장 flags를
해당 helper로 지우지 않는다. entry의 CLD는 handler 실행 flags에 대한 조치이지 저장
EFLAGS를 무조건 바꾸는 명령이 아니다.
상태가 nonzero이면 recovery helper를 먼저 호출하고, 성공하면 반환한다.
복구 실패·낮은 VA이면 exception 전달로, 높은 VA이면 default로 간다.
default에는 recovery helper 호출이 다시 존재한다.

두 번째 jump table은 alert 이후의 KDP exception 인자 선택용이며 IDT가 아니다.
table 바이트와 target head를 검증한 사실을 실제 하드웨어 trap 도달성으로 확대하지 않는다.

## 5. debug·double-fault·상태 변환 경로 구분

`0x192438`은 DR6=0을 먼저 수행한다. trap 1이고 저장 EIP가 0x186e9c/0x186e3c/
0x186ddc 중 하나이면 thread+0x28가 가리키는 객체의 BYTE +0xf0에 mask 0x1을 설정하고
저장 flags의 mask 0x100을 지운다. 이 TF 처리와 copy 복구의 DF 처리는 다른 명령이다.
그 외는 KDP 호출이며 디컴파일 C에는 DR6 쓰기가 표현되지 않는다.

`_dbf_handler 0x1899d0`도 kernel_trap을 호출하지만, 전역 dbf_state에 trap8/error 및
별도 저장 상태의 register/segment 값을 옮겨 전달한다. kernel_trap이 돌아오면
`0x1899e8`로 되돌아가 이 프레임을 다시 채운다. 이 함수의 복귀를 일반 IRETD 경로처럼
해석할 수 없다. dbf caller/TSS/실제 double-fault 진입 조건은 미완료다.

`0x1924e0`은 thread+0x28→+0x70이 nonzero이면 그 +0x84, 아니면 thread_user_state
결과를 목적지로 택한다. F+0x34 DWORD를 옮긴 뒤 F+0x44와 목적지+0xc/+8/+4/0의
unsigned 비교로 register/segment 복사 범위를 고른다. 이는 전체 trap frame의 memcpy가
아니며 EIP/CS/EFLAGS 전체를 이 helper가 복사한다고 가정하지 않는다.
목적지 객체의 유효성·중첩 및 이 비교가 필요한 native 배치는 후속 검토 사항이다.

## 6. vm_fault 반환값과 wiring 연결 — 이번에는 반환 계약 부분 검토

원본 `vm_fault 0x172038`의 RET는 `0x173589`이며 공통 epilogue는 `0x173580`이다.
Python으로 직접 epilogue 분기와 직전 EAX 생산점을 대조했다.

| EAX 생산점 | 반환값 | 확인한 경로 |
|---|---|---|
| 0x17207a | 첫 vm_map_lookup 상태 | 첫 조회 실패 |
| 0x1721de | 10 | page BYTE +0x20의 mask0x40 경로 cleanup |
| 0x172376 | 0 | busy page 대기 결과가 0/4 외의 값 |
| 0x172572 | 10 | page DWORD +0x28과 요청 prot 교집합 nonzero |
| 0x172922 | 10 | vm_pager_get 결과 2의 cleanup |
| 0x172d13 | 0 | copy page 대기 결과 nonzero |
| 0x1731fe | 두 번째 vm_map_lookup 상태 | map 재조회 실패 cleanup |
| 0x17357e | 0 | 최종 매핑·page 상태 변경·cleanup 후 |

busy-page 경로는 wanted bit를 켜고 `assert_wait(page, wirechange==0)` 후 필요한
map lookup을 해제하고 object lock을 풀어 thread_block한다. 돌아온 thread +0x44가
4이면 cleanup 후 초기 map lookup으로, 0이면 현재 object의 page 조회로 돌아간다.
그 외 값이면 cleanup 후 0 반환한다. 이 반환 경로에는 최종 pmap_enter가 없다.

copy-page busy 경로 역시 `assert_wait(...,wirechange==0)`를 사용한다. held page의
busy/queue/object 상태와 map lookup을 정리한 뒤 thread_block하고, 결과가 0이면
처음부터 다시 조회하며 nonzero이면 0을 반환한다. 각 cleanup의 전체 alias/lifetime
보장은 별도의 COW/object 분석이 필요하다.

92차 vm_fault_wire는 fast 실패 후 `vm_fault(map,va,0,1,0)`의 EAX를 검사하지 않고
다음 page로 간다. 반면 이번 kernel_trap은 vm_fault의 EAX=0을 검사한 뒤 반환한다.
두 caller의 wirechange 값과 wait 인자가 다르므로, trap에서 가능한 대기 종료가
wiring에서도 같은 조건으로 발생한다고 단정하지 않는다.

최종 매핑 경로는 object lock을 풀고 pmap_enter를 호출한다. 전달 인자는 순서대로
map의 DWORD +0x24 값, VA, page의 DWORD +0x24 값,
page의 DWORD +0x28 값을 반전한 값과 effective_prot의 AND, 조회된 wired 값이다.
CALL 결과 EAX는 검사되지 않고 다음 lock load에서 덮인다.
이후 wirechange=0이면 page_activate, nonzero이면 조회된 wired 값에 따라
page_wire 또는 page_unwire를 호출한다. busy clear/wanted wake, paging WORD 감소,
필요한 top placeholder 정리, lookup_done/object_deallocate 후 0으로 반환한다.
이 ordering 확인은 pmap_enter의 실제 PTE/TLB/PV 성공 또는 전체 범위 rollback 보장이 아니다.

## 7. 디컴파일 경고와 여전히 남은 검토

`vm_fault`의 `0x1731e5` unreachable 경고를 원본 누락으로 처리하지 않았다.
해당 명령과 lookup_done 호출은 원본/ASM에 존재한다. 진입의 `0x1730a3`는 local -0x34가
0인 경우만 재조회로 보내고, 실패 cleanup의 `0x1731df`가 같은 local을 검사한다.
이는 통상적인 local 보존 전제 아래 분기 제거를 설명하지만, 전체 CFG·모든 alias·callee
영향을 검증한 결과는 아니다. 원본 명령을 삭제하거나 전체 경고를 해결 처리하지 않았다.

선택 vm_fault 본문에서 register만 재시험하는 `75fc` 루프 58개도 원본으로 확인했다.
이는 decompiler의 메모리 재조회 루프 표현과 별개이며, native lock 진행성 증명이 아니다.
전체 COW/shadow/pager·map/page/object 수명, context 전환과 recovery slot writer,
IDT/TSS/descriptor/RF/DF/FS 계약 및 전체 kernel 누락·경계·ABI 검토는 계속 남는다.

모든 계산은 Python으로 수행했다. Ghidra 스킬은 함수·C/ASM·참조·제어 흐름을 나누어
대조하는 절차에 적용했으며 live DB를 변경하지 않았다. 새 계획 교차검토는 수신하지
못했으므로 통과로 간주하지 않았고, 실패한 요청을 재시도하거나 우회하지 않았다.
