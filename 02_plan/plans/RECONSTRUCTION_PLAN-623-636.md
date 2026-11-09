# 커널 소스 복원 작업계획 — 보관 §623–636

`02_plan/RECONSTRUCTION_PLAN.md` 의 §623–636(m68k M4 `pcb.c`(D143), `trap.c`(D144))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-31, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 623. M4-129 세부 계획 — m68k `pcb.c`(행 308–309) 첫 진단 A1(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: D142 로 1997 `struct pcb` 가 공유 머리에 들어가, pcb 칸을 이름으로 쓰는 `pcb.c` 를 진단할 수 있게 되었습니다.

확인한 사실(이번 세션; 함수 표·재고 표·`symbols.tsv`·otool 목록 python 집계, Ghidra 출력은 읽기 안내):
- 범위 [0x40967be, 0x4096e20) 1634 B(python), 정확 행 둘: 308(`unassigned`, 358 B, 함수 5)·309(`next/pcb.c`, 1276 B, 함수 13). 함수 18 개는 차례대로 `stack_attach` 52·`stack_detach` 20·`stack_handoff` 108·`switch_context` 136·`pcb_module_init` 42·`pcb_init` 46·`thread_user_state` 98·`thread_bootstrap_return` 14·`thread_exception_return` 64·`thread_syscall_return` 68·`thread_set_syscall_return` 42·`start_initial_context` 56·`thread_setstatus` 296·`thread_getstatus` 274·`thread_dup` 120·`thread_userstack` 72·`thread_entrypoint` 42·`pcb_terminate` 84 B 입니다.
- 이 차례는 Darwin 0.1 `machdep/i386/pcb.c` 와 x86 07 `machdep/i386/pcb.c`(75·94·107·160·219·232·594·627·650·667·688·703·748·930 행)의 차례와 같습니다. 몸통은 m68k 판입니다(i386 의 tss·ldt·io_bmap·v86 함수 없음). NeXTMach `next/pcb.c` 에는 `pcb_init`·`pcb_terminate`·`thread_setstatus`·`thread_getstatus`·`thread_dup` 가 있습니다(61·101·152·235·328 행).
- 원본이 이 범위에서 가리키는 것: 문자열 `"pcb"`(0x40ac96a, `zinit` 이름) 하나 — 앞은 `"wrmem: bad size\n"`, 뒤는 `"pmap"`; COMMON `_pcb_zone`(정의 객체 후보)·`_active_threads`·`_active_stacks`·`_stack_pointers`·`_cpu_type`·`_kernel_pmap`; 직접 호출 15(`_zinit`·`_zalloc`·`_zfree`·`_kalloc`·`_kfree`·`_bzero`·`_bcopy`·`_check_for_ast`·`_thread_start`·`_pmove_crp`·locore `__switch_context`·`__switch_context0`·`__switch_context_discard`·`__stack_handoff`·`__return_with_state`).
- 1997 m68k 특유: 커널 스택 꼭대기 `stack + 0xff4`(`_stack_attach`·`_switch_context`·`_start_initial_context`), 주소 공간 전환은 `pmap != kernel_pmap` 이면 `pmove_crp(pmap)`(스테이지 `machdep/m68k/pmap.h:52` 의 `PMAP_ACTIVATE` 는 빈 매크로), `thread->swap_func`(+0x30) 에 continuation 을 두고 locore 의 `__switch_context`/`__switch_context_discard` 를 부름, 저장 영역 312/580 B(`_cpu_type`), thread state 꼴은 SDK `mach/m68k/thread_status.h` 의 `m68k_thread_state_regs`(18 낱말)·`_68882`(28)·`_user_reg`(1) — `thread_getstatus` 의 `THREAD_STATE_FLAVOR_LIST` 꼴(1·18·2·28·3·1)과 맞습니다.

방법(진단 A1; 명세 `08_build/artifacts/m4p623/spec.json`, run `m4p623-p1`, 바탕 `08_build/runs/tools/m0p622-a1-stage`, 객체 이름 `pcb`, `m4_id` `["m68k-308", "m68k-309"]`, `x86_rel` `machdep/i386/pcb.c`; 생성 scratchpad `gen_p623.py`):
- A1 은 작성 글(D024)입니다: x86 07 `machdep/i386/pcb.c` 의 차례·시그니처·지역 이름을 틀로 하고, 몸통은 원본 바이트(목록)를 따라 m68k 로 씁니다. `pcb_init`·`pcb_terminate`·`thread_setstatus`·`thread_getstatus`·`thread_dup` 는 NeXTMach `next/pcb.c` 의 같은 함수와 줄 단위로 대조해 맞는 줄은 그대로 씁니다. pcb 칸은 D142 이름으로 씁니다.
- 스테이지에 없는 이름(예: 빈 `PMAP_ACTIVATE` 대신 원본의 `pmove_crp` 조건, `KERNEL_STACK_SIZE` 에 맞는 상수)은 파일 안에 진단 표시로 둡니다. 공유 머리는 바꾸지 않습니다.

측정: 종료·경고·i386 0, 컴파일 명령 = M5 줄; `__text` 1634·L1·`full_span`; funcbytes(`m68k_funcbytes.py 0x40967be 0x4096e20`) 함수별 같음/다름과 길이, 다르면 scratchpad `rawdiff.py`; 섹션(`__cstring` `"pcb"` 4 B 기대), 외부 정의 18 개가 원본 자리인지, COMMON 이름·크기(`_pcb_zone` 등), 원본에 없는 미정의.

판정(미리 정함; 07 은 바꾸지 않음): 모든 함수가 같으면 바이트로 가를 수 없는 꼴을 사용자에게 묻고 07 구현 계획을 씁니다. 다른 함수가 있으면 차이를 적고 B 진단으로 고칩니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 623.1 교차검토(codex `gpt-6.1-sol`, task kmtmlf2hy) 판정과 계획 수정

먼저 제 잘못입니다: (1) "함수 차례가 Darwin·x86 07 과 같다" 는 틀렸습니다. 원본은 `thread_getstatus → thread_dup → thread_userstack → thread_entrypoint → pcb_terminate` 이고, x86 07 은 `thread_userstack`(1124 행)·`thread_entrypoint` 뒤에 `thread_dup`(1196 행)을 둡니다. (2) `pmove_crp` 조건을 `pmap != kernel_pmap` 로만 적었으나 `new->task != old->task` 도 함께입니다. (3) "`KERNEL_STACK_SIZE` 에 맞는 상수를 파일 안에" 는 필요 없습니다(스테이지 `kern/kernel_stack.h` 의 정의가 4096 − 12 = 0xff4).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `span(["m68k-308","m68k-309"])` = [0x40967be, 0x4096e20), 함수 18, 크기 합 1634 | 재고 표 두 행(이번 세션 awk: 둘 다 정확), python 합 1634 | ✅ |
| 원본 차례에서 `thread_dup` 은 `thread_getstatus` 바로 뒤; x86 07 은 1124·1158 뒤 1196 | 함수 표(이번 세션 출력)와 x86 07 `pcb.c:1120–1124`·`1194–1197` 을 엶 | ✅ 고침: A1 은 원본 차례 |
| `pmove_crp` 는 task 가 다르고 pmap 이 `kernel_pmap` 이 아닐 때, 인자는 pmap; thread+0xc → task+0x8 → map+0x20 | Ghidra `04096806.c`·`04096872.c` 와 목록 189068 행 이후(이번 세션), 진단 STABS 로 `task.map` +0x8·`kernel_privilege` +0x44 확인 | ✅ 고침 |
| `0xff4` = `KERNEL_STACK_SIZE`(4096 − sizeof(`struct _kernelStack`) 12) | 스테이지 `kern/kernel_stack.h:54–57·63`, `mach/m68k/vm_param.h:77` 을 엶 | ✅ 고침 |
| COMMON 정의 후보는 `pcb_zone`·`stack_pointers`(+ 공유 머리 `master_cpu`); `active_threads`·`active_stacks` 는 `kern/thread.c:105–106` 정의; `empty_stacks` 는 원본에 없음 | `symbols.tsv` grep(`_pcb_zone`·`_stack_pointers`·`_master_cpu` 섹션 6, `_empty_stacks` 없음), `thread.c:105–106` 을 엶 | ✅ A1 에 반영(정의는 초기값 없이) |
| 함수별 사실(첫 `stack_attach` 의 +0x24 는 a1 칸, `stack_detach` 는 `vm_offset_t`, `switch_context` 는 `thread_t` 돌려줌, `pcb_init` 은 인자 하나, `thread_dup` 의 `& 0x3ffe`·a7 조건, `thread_userstack` 기본값 0x04000000, `thread_entrypoint` 는 0 도 복사 등) | Ghidra 출력 열한 함수와 세 큰 함수(이번 세션에 읽음)와 같은 내용; 바이트 대조는 A1 측정에서 함 | ⚖️ 작성 안내로 씀(바이트로 확정은 run 에서) |
| 스테이지에 `pmove_crp`·locore `_switch_context*` 원형이 없음 | 스테이지 grep(`pmove_crp\|thread_start`: 머리에 없음) | ✅ A1 에서 파일 안 extern 선언(진단 표시) |
| 측정 더하기: 기호마다 원본 자리·차례, 모든 섹션 | — | ✅ 측정에 더함 |

계획 수정: A1 은 원본 차례로 쓰고, 위 사실을 따릅니다. COMMON 은 `pcb_zone`·`stack_pointers[NCPUS]` 를 초기값 없이 정의하고, `master_cpu` 는 공유 머리 것(D136)입니다.

### 623.2 결과(run `m4p623-p1`, 2026-10-31)

- A1(`08_build/artifacts/m4p623/src/pcb_A1.c`, 생성 scratchpad `gen_p623.py`, 원본 차례 18 함수): 컴파일·의존 종료 0, 경고 1(`pcb_terminate` 의 `kfree` 첫 인자 포인터→정수), i386 0, 선택지 차이 0(기록 `m4-m68k-probe-p623-p1-20261031.json`). `__text` 1624 B(원본 1634), L1 `NOT_MATCH`(`__TEXT,__text: unverified`), 원본에 없는 미정의 0.
- funcbytes(`m4-m68k-funcbytes-p623-A1-20261031.json`): 15/18 같음. 다른 셋:
  - `stack_attach`(52 = 52, 12 바이트 다름): 원본은 `thread->pcb` 를 `kernel_stack` 저장보다 먼저 a1 에 읽고, +56(`r_fp`)을 +60(`r_sp`)보다 먼저 씁니다. A1 은 그 반대입니다(x86 의 `tss->esp = tss->ebp = …` 꼴이 원본 차례).
  - `thread_user_state`(원본 98, A1 88): 원본은 pcb 를 a2, 크기를 d2(312/580)에 두고, `lea -72(a0,d2)` 결과를 d2 에 다시 담아 `saved_regs` 에 쓰고 `bzero` 에 넘긴 뒤 d2 를 돌려줍니다(지역 변수 하나에 저장 상태 포인터를 담아 반환). A1 은 `pcb->saved_regs` 를 다시 읽어 반환하고 크기를 주소 레지스터에 둡니다.
  - `start_initial_context`(56 = 56, 23 바이트·참조 3 다름): 원본은 처음에 `thread->pcb` 를 d0 에 읽어 두고(x86 의 `struct pcb *pcb = thread->pcb;` 꼴), 스택 포인터 계산을 주소 레지스터로 합니다. A1 은 마지막에 `thread->pcb` 를 읽습니다.

## 624. M4-130 세부 계획 — `pcb.c` B1 진단(세 함수의 글 꼴; 07 변경 없음; 코딩 전, 2026-10-31)

방법: B1 = A1 에서 세 함수만 바꾼 글입니다(생성기가 A1 에서 바꿈, 나머지 15 함수 글은 그대로).
- `stack_attach`: `struct pcb *pcb = thread->pcb;` 를 선언 초기화로 두고(x86 의 지역 꼴), `pcb->pcb_r.r_sp = pcb->pcb_r.r_fp = stack + KERNEL_STACK_SIZE;`(x86 `tss->esp = tss->ebp` 차례).
- `thread_user_state`: x86 07 꼴처럼 `struct pcb *pcb = thread->pcb;`, 저장 영역이 없으면 `int size = cpu_type ? 580 : 312;`, `pcb->pcb_save_area = (void *)kalloc(size);`, `saved_state = (struct regs *)((vm_offset_t)pcb->pcb_save_area + size - sizeof (struct regs));`(또는 같은 값을 내는 지역 포인터 꼴), `pcb->saved_regs = saved_state; bzero(saved_state, sizeof (*saved_state)); return (saved_state);`, 아니면 `return (pcb->saved_regs);`.
- `start_initial_context`: `struct pcb *pcb = thread->pcb;` 를 두고 마지막에 `_switch_context0(0, pcb, 0);`(x86 07 703 행의 지역 꼴).
- run `m4p624-p1`(바탕 `m0p622-a1-stage`, 같은 `m4_id`·`x86_rel`). 첫 꼴이 맞지 않는 함수가 있으면 같은 run 에 꼴 변형(B2…)을 함께 둡니다: `thread_user_state` 의 `size` 를 `vm_size_t`/`int`, 크기 선택을 `if` 꼴/삼항 꼴.

측정: §623 과 같음(funcbytes 18 함수, 섹션, 외부 정의 자리, COMMON, 경고).

판정(미리 정함; 07 은 바꾸지 않음): 18/18 이 되는 변형이 있으면 그 꼴로 07 구현 계획을 쓰고, 바이트로 가를 수 없는 꼴을 묻습니다. 아니면 차이를 적고 다음 진단을 계획합니다.

### 624.1 교차검토(codex `gpt-6.1-sol`, task kq946e6ku) 판정과 계획 수정

먼저 제 잘못입니다: `stack_attach` 의 선언 초기화를 "x86 의 지역 꼴" 이라 적었으나, x86 07 은 `tss` 를 초기화 없이 선언하고 `kernel_stack` 을 쓴 뒤에 대입합니다(`pcb.c:81–86`). 선언 초기화는 원본 차례에서 나온 작성 꼴입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §623.2 의 세 차이 설명이 맞음(레지스터·저장 차례·pcb 읽는 자리) | 목록 189050–189056·189257–189266 행을 엶; rawdiff 출력(이번 세션) | ✅ |
| 스테이지 `cpu_type` 은 `extern u_char` 이라 A1 도 이미 `tstb` 를 냄; 삼항/`if` 는 너비 문제가 아님 | `m4p623-p1` 의 `bsd/m68k/cpu.h:53`(`extern u_char cpu_type;`)을 엶; rawdiff 에 `tstb` 차이 없음 | ✅ |
| x86 은 `tss` 를 `kernel_stack` 저장 뒤에 대입 | x86 07 `pcb.c:79–86` 을 엶 | ✅ 문구 고침 |
| 같은 run 에 꼴 변형을 더 둘 것(`stack_attach` 따로 저장, `thread_user_state` 의 `if` 꼴·바이트 포인터 꼴, `start_initial_context` 의 커널 스택 두 번 읽기 유지) | — | ✅ B2·B3 를 더함 |

변형(모두 A1 에서 세 함수만 바꿈):
- B1: §624 방법 그대로(`stack_attach` 선언 초기화 + `r_sp = r_fp = …`; `thread_user_state` 블록 안 `int size = cpu_type ? 580 : 312;` 과 지역 `saved_state` 반환; `start_initial_context` 선언 초기화 `pcb`).
- B2: `stack_attach` 는 선언 초기화 + `r_fp`·`r_sp` 따로 두 문장(fp 먼저); `thread_user_state` 는 `int size = 312; if (cpu_type) size = 580;`; `start_initial_context` 는 B1 과 같음.
- B3: `thread_user_state` 만 B1 과 달리, 함수 범위 `struct regs *saved_state` 와 `char *save_area = (char *)kalloc(size)`·`saved_state = (struct regs *)(save_area + size) - 1` 꼴; 나머지는 B1 과 같음.

### 624.2 결과(run `m4p624-p1`, 2026-10-31)

- B1·B2·B3 모두 컴파일 종료 0·경고 1(A1 과 같은 `kfree`)·i386 0, 각각 17/18 입니다(기록 `m4-m68k-probe-p624-p1-20261031.json`, `m4-m68k-funcbytes-p624-B1/B2/B3-20261031.json`).
  - `stack_attach`·`start_initial_context` 는 세 변형 모두 같습니다. `stack_attach` 의 두 꼴(`r_sp = r_fp = …` 한 문장, `r_fp`·`r_sp` 두 문장)이 같은 바이트를 냅니다 — 바이트로 가를 수 없는 꼴입니다.
  - `thread_user_state` 는 세 변형 모두 90 B(원본 98)입니다. 원본은 a2(pcb)·d2 두 레지스터만 저장하고, `size` 와 저장 상태 값을 같은 d2 에 차례로 담습니다(`lea -72(a0,d2),a0; movel a0,d2`). B1 은 a2–a4 셋을 저장하고 `size` 를 a3, 저장 상태 포인터를 a2 에 둡니다. 포인터 형 지역 변수가 주소 레지스터로 간 것이 차이입니다.

## 625. M4-131 세부 계획 — `thread_user_state` C 진단(지역 변수 형; 07 변경 없음; 코딩 전, 2026-10-31)

방법: B1 에서 `thread_user_state` 만 바꾼 변형 셋(run `m4p625-p1`, 바탕·`m4_id`·`x86_rel` 같음):
- C1: `vm_size_t size = cpu_type ? 580 : 312; vm_offset_t saved_state;` 를 블록 안에 두고, `pcb->pcb_save_area = (void *)kalloc(size); saved_state = (vm_offset_t)pcb->pcb_save_area + size - sizeof (struct regs); pcb->saved_regs = (struct regs *)saved_state; bzero((void *)saved_state, sizeof (struct regs)); return ((void *)saved_state);`.
- C2: C1 과 같되 `vm_offset_t save_area = kalloc(size); pcb->pcb_save_area = (void *)save_area; saved_state = save_area + size - sizeof (struct regs);`.
- C3: C1 과 같되 `size` 를 `int`, 크기 선택을 `if` 꼴로.

측정·판정은 §624 와 같습니다(18/18 이 되는 변형이 있으면 07 구현 계획으로, 바이트로 가를 수 없는 꼴은 사용자에게 물음).

### 625.1 교차검토(codex `gpt-6.1-sol`, task k0shdyi5l) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §624.2 의 관찰은 맞고, "포인터형 지역 변수 때문" 은 가설 | rawdiff 출력(이번 세션: 원본 `movel a2/d2` 저장, B1 `moveml a2-a4`, `lea -72(a3,a2)`) | ✅ 원인은 가설로 둠 |
| B1·B2 는 삼항/`if` 꼴에서 같은 바이트 → C3 은 부호만 바꿀 것 | §624.2 의 funcbytes(B1·B2 의 `thread_user_state` 모두 90 B, 세 변형 바이트 같음) | ✅ C3 을 "`int size`, 삼항 그대로" 로 고침 |
| `size` 변수에 저장 상태 값을 덮어쓰는 누산 꼴(C4)이 d2 재사용을 가장 바로 나타냄 | — | ✅ C4 를 더함 |
| `kalloc` 은 `vm_offset_t kalloc(vm_size_t)`(스테이지 `kern/kalloc.h:58`), 두 형 모두 `unsigned int`; `bzero` 원형은 B1 의존에 없음 — 원형을 들이지 말 것 | `kalloc.h:58` 을 엶 | ✅ 머리를 더하지 않음 |

변형(run `m4p625-p1`): C1·C2 는 §625 그대로, C3 = C1 에서 `size` 를 `int`(삼항 그대로), C4 = `vm_offset_t size = cpu_type ? 580 : 312; pcb->pcb_save_area = (void *)kalloc(size); size += (vm_offset_t)pcb->pcb_save_area - sizeof (struct regs); pcb->saved_regs = (struct regs *)size; bzero((void *)size, sizeof (struct regs)); return ((void *)size);`.

### 625.2 결과(run `m4p625-p1`, 2026-10-31)

- C1–C4 모두 컴파일 종료 0·경고 1·i386 0, 17/18(`m4-m68k-probe-p625-p1-20261031.json`, `m4-m68k-funcbytes-p625-C1..C4-20261031.json`). `thread_user_state` 는 C1–C3 90 B, C4 92 B 입니다.
  - C1: `size` 는 a3(`moveaw #312,a3`), 저장 상태는 a2, `lea -72(a3,a2.l)`(size 가 base). 정수형으로 바꿔도 주소 레지스터로 갑니다.
  - C4: `size`(같은 변수에 저장 상태를 덮어씀)는 a2, pcb 는 a3, `lea -72(a0,a2.l)` — base·index 자리는 원본과 같아졌으나 레지스터가 d2 가 아니고, 저장 레지스터가 a2·a3 둘입니다(원본 a2·d2).
- 실기 GCC 소스(`/NextDeveloper/Source/GNU/gcc/config/m68k/m68k.h`, 읽기만)에는 `REG_ALLOC_ORDER` 가 없습니다(grep 0). 따라서 레지스터 번호 차례(d0–d7, a0–a7)이고, 원본이 d2 를 쓴 것은 그 값의 선호 클래스가 주소 레지스터가 아니었다는 뜻으로 봅니다(추론).

## 626. M4-132 세부 계획 — `thread_user_state` D 진단(글 꼴 여러 개를 한 run 에; 07 변경 없음; 코딩 전, 2026-10-31)

방법: B1 에서 `thread_user_state` 만 바꾼 변형 여섯(run `m4p626-p1`, 바탕·`m4_id`·`x86_rel` 같음):
- D1: `vm_size_t size;` 를 초기화 없이 두고 `if (cpu_type) size = 580; else size = 312;`, `struct regs *saved_state = (struct regs *)((char *)pcb->pcb_save_area + size) - 1;` 꼴.
- D2: `char *save_area = (char *)kalloc(size); pcb->pcb_save_area = save_area; pcb->saved_regs = saved_state = (struct regs *)(save_area + size - sizeof (struct regs));`.
- D3: 크기 먼저 쓰는 식 `saved_state = (struct regs *)(size - sizeof (struct regs) + (vm_offset_t)pcb->pcb_save_area);`.
- D4: `size`·`saved_state` 를 함수 범위에 두고(초기화 없음) 블록 안에서 대입.
- D5: x86 07 `thread_user_state`(594 행) 꼴을 따름: `void *save_area = pcb->pcb_save_area;` 로 읽고 `if (save_area == 0)` 를 시험, `pcb->pcb_save_area = save_area = (void *)kalloc(size);`, `saved_state = (struct regs *)((vm_offset_t)save_area + size) - 1;`.
- D6: D5 에서 크기를 `unsigned int` 로.

측정·판정은 §624 와 같습니다. 맞는 꼴이 없으면 결과를 적고, 이 함수 하나를 남긴 채 사용자에게 다음 방향을 묻습니다.

### 626.1 교차검토(codex `gpt-6.1-sol`, task kymugozuh) 판정과 계획 수정

먼저 제 잘못입니다: §625.2 에서 C1–C3 이 a2–a4 셋을 저장한다는 점(pcb 가 a4)을 빠뜨렸습니다. 또 "원본이 데이터 레지스터를 선호했다" 는 추론은 너무 강합니다 — 일반 레지스터 클래스여도 번호 차례로 d2 가 나올 수 있습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| C1–C3 은 pcb a4·size a3·저장 상태 a2·저장 a2–a4, C4 는 pcb a3·size/상태 a2·저장 a2/a3 | §625.2 의 rawdiff 출력(이번 세션: C1 `moveml %a2-%a4`, C4 `movel %a3,%sp@-`·`moveal %a0@(36),%a3`) | ✅ 고침 |
| D6 은 겹침: `vm_size_t` 는 `natural_t` = `unsigned int` | 스테이지 `mach/m68k/vm_types.h` grep(아래 출력) | ✅ D6 을 뺌 |
| D5 가 가장 볼 만하고, D1–D4 는 대조로 둠; 더할 꼴: 두 갈래가 같은 반환으로 모이는 꼴, `size = cpu_type; if (size) …` 꼴, `int` 식 캐스트 꼴 | — | ✅ D7·D8·D9 를 더함 |
| `.lreg`/`.greg` 덤프로 할당 이유를 볼 것 | — | ⏭️ 컴파일 명령에 선택지를 더하는 일이라 이번 run 에서는 하지 않음(맞는 꼴이 없으면 다음 진단에서 따로 계획) |

변형(run `m4p626-p1`): D1–D5 는 §626 그대로, D7 = D5 에 `struct regs *saved_state;` 를 두 갈래에서 대입하고 끝에서 한 번 `return (saved_state);`, D8 = D5 에서 `size = cpu_type; if (size) size = 580; else size = 312;`, D9 = D5 에서 `saved_state = (struct regs *)(int)((vm_offset_t)save_area + size - sizeof (struct regs));`.

### 626.2 결과(run `m4p626-p1`, 2026-10-31)

- 여덟 변형 모두 컴파일 종료 0·경고 1(`pcb_terminate` 의 `kfree` 첫 인자)·i386 0(`m4-m68k-probe-p626-p1-20261031.json`).
- **D5·D8·D9 는 18/18** 입니다(`m4-m68k-funcbytes-p626-D5/D8/D9-20261031.json`): `__text` 1634 B, L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate`, 원본에 없는 미정의 0. D5 객체: 섹션 `__text` 1634·`__cstring` 4(`"pcb\0"`), 외부 정의 18 개가 모두 원본 자리, 지역 정의 없음, COMMON `_master_cpu`·`_pcb_zone`·`_stack_pointers`(각 4 B; 셋 다 원본에서 섹션 6 COMMON — D136).
- 나머지: D1·D3·D4 90 B, D2 94 B, D7 98 B(9 바이트 다름) — 맞지 않음.
- 맞은 셋의 공통점은 x86 07 `thread_user_state`(594 행)처럼 `void *save_area = pcb->pcb_save_area;` 를 읽어 그 지역 변수를 시험하고 `pcb->pcb_save_area = save_area = (void *)kalloc(size);` 로 대입하는 꼴입니다. D8(크기를 `cpu_type` 값으로 시작)·D9(`int` 캐스트)는 바이트가 같으므로 가를 수 없습니다.

바이트로 가를 수 없는 것(사용자에게 물음): `thread_user_state` 의 꼴(D5·D8·D9), `stack_attach` 의 꼴(한 문장 `r_sp = r_fp = …`, 두 문장), 07 파일 이름, `kfree` 경고를 남길지(캐스트를 바꾸면 새 진단으로 바이트를 다시 확인해야 함).

- 사용자 결정(2026-10-31, AskUserQuestion): ① `thread_user_state` 는 "D5" ② `stack_attach` 는 "두 문장"(`r_fp`, `r_sp` 차례; B2 꼴) ③ 파일 이름 "`pcb.c`" ④ `kfree` 경고는 "캐스트를 고침"(`(vm_offset_t)`; 07 전에 진단으로 바이트 확인).

## 627. M4-133 D143 구현 계획 — 07 `src/machdep/m68k/pcb.c`(행 308–309, OBJECT_MATCH; 코딩 전, 2026-10-31)

확인한 사실(이번 세션): §626.2 와 위 결정입니다. 07 `src/machdep/m68k/pcb.c` 는 없고(ls), 스테이지에는 x86 `src/machdep/i386/pcb.c` 만 있습니다; PROVENANCE 에 그 경로 행은 없습니다(grep 0). 글의 틀인 x86 07 `machdep/i386/pcb.c` 는 Apple APSL 고지(1–22 행)와 NeXT 1992 고지(26 행)를 가지고, NeXTMach `next/pcb.c` 는 "Copyright (c) 1987, 1988 NeXT, Inc."(1–2 행)입니다.

0. 진단 E1(run `m4p627-e1`, 07 전): E1 = D5 에서 `stack_attach` 를 두 문장 꼴로, `pcb_terminate` 의 `kfree` 첫 인자를 `(vm_offset_t)pcb->pcb_save_area` 로 바꾼 글입니다. 판정: 컴파일 종료 0·경고 0·i386 0, 18/18, L1 `OBJECT_MATCH`·`full_span`, D5 객체와 `canon` 같음. 아니면 멈추고 사용자에게 알립니다.
1. 07 `src/machdep/m68k/pcb.c`(D103)를 E1 글에서 scratchpad `gen_p627.py` 로 만듭니다.
   - 머리: x86 07 `pcb.c` 의 APSL 고지(1–23 행)와 NeXT 1992 고지·HISTORY(25–34 행), 날짜 붙은 수정 표시 줄, NeXTMach `next/pcb.c:1–2` 고지 줄을 둡니다(D013; 섞인 출처는 `miniMonMachdep.c`·`shutdown.c` 선례처럼 머리 설명에서 함수별 출처를 밝힘).
   - 설명 주석(plan 627): 원본 범위, 함수별 출처(x86 07 틀·NeXTMach `thread_setstatus`/`getstatus`/`thread_dup` 줄·원본 바이트로 쓴 몸통), 바이트로 정한 1997 m68k 특유(`KERNEL_STACK_SIZE` 0xff4, `pmove_crp` 조건, 저장 영역 312/580, flavor 꼴), 사용자 결정(D143).
   - 진단 표시는 모두 `plan 627 (D143)` 표시로 바꾸고, 작성 몸통 함수 줄에 `plan 627 (D024, D143)` 표시를 답니다(`*/` 뒤 글 없음, python). 주석 뺀 토큰이 E1 과 같아야 합니다.
2. `stage_m68k.py`: `M4FILES[627] = list(M4FILES[622]) + ['pcb.c']`, `EXCEPTS[627] = dict(EXCEPTS[622])`, 머리말 plan 목록에 627.
3. 회귀: `--plan 622` 재생성 = 보관본(이번에는 07 덮어쓰기 변경 없음); `m0p627-a1-stage` 와 보관 622 의 차이는 새 파일 하나(974 → 975)와 키 `plan`·`m4_sources`·`files`; M5 205(`m5-622.cmd` = §622 것, run `m3p627-b622`·`m3p627-cc1`, 객체·stderr 같음, `compare` 의 `differ_unexpected`·`lost` 빔); x86(`m4_x86_inputs.py s6ln`·`--plan 627 x86gate`).
4. 확인 run `m4p627-p1`: F = `@machdep/m68k/pcb.c`, L = E1 글에 맞춤 주석 줄을 넣은 꼴. 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = E1(canon), 18/18, `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`; F·L 바이트 차이는 문자열 표·`n_strx` 뿐. 그리고 `-E` 토큰 run `m4p627-e2`(F·L, `#` 줄 빼고 토큰 같음).
5. 최종 run `m4p627-a1`(명세 `08_build/artifacts/m4p627/spec.json`: F 만, 바탕 `m0p627-a1-stage`, 객체 `pcb`, `m4_id` `["m68k-308","m68k-309"]`, `x86_rel` `machdep/i386/pcb.c`, `refs["pcb"]` = p1 L): `gate.ok`, 18/18. 확인 기록 `m4-m68k-p627-checks-20261031.json`: 섹션 1634·4, 문자열이 원본과 같음, 외부 정의 18 개 원본 자리, 지역 없음, COMMON `_master_cpu`·`_pcb_zone`·`_stack_pointers`(각 4, 원본 COMMON — D136), 원본에 없는 미정의 없음, 재배치·참조 원본과 같음(funcbytes), 의존 i386 0, 입력 사슬.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-pcb.md` 를 먼저 쓰고 `ACCEPTED` 에 한 줄. 기대(python 으로 계산해 적음): 객체 41(OBJECT_MATCH 32, CODE+BSS_INFERRED 9), 덮은 행 63 + 2 = 65/188, 덮은 바이트 63146 + 358 + 1276 = 64780(python, 30.01%), `object_bytes` 80348 + 1634 = 81982(python), `rows_unassigned_before` 에 `m68k-308` 더함.
7. 기록: diff(x86 07 `pcb.c` 대비, NeXTMach 발췌 대비), PROVENANCE 새 행(일곱 칸, `darwin01+nextmach+authored`), MODIFICATIONS, DECISIONS D143, 계획·HANDOFF·메모리. M7 의무: `pcb_zone`·`stack_pointers`·`master_cpu` COMMON 합침, locore 함수 원형.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 627.1 교차검토(codex `gpt-6.1-sol`, task k94w78hhu) 판정과 계획 수정

먼저 제 잘못입니다: x86 07 고지 범위를 1–22·24–33 행으로 적었으나 닫는 줄까지 1–23·25–34 행입니다(23·34 행이 ` */`).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상태 기대: 41/32/9, 65/188, 64780/215874, 30.01%, 81982, `rows_unassigned_before` 에 `m68k-308` 만 더함 | python: 64780/215874 → 30.01; 행 308 `bytes_min` 358·309 1276(§623 의 재고 표 출력) | ✅ 6 에 30.01 더함 |
| x86 07 `pcb.c` 는 PROVENANCE 638 행 `darwin01`; 고지 1–23·25–34 행; NeXTMach 고지; 날짜 붙은 수정 표시 줄(`miniMonMachdep.c:25` 꼴) | 638 행 앞 세 칸을 엶; `pcb.c:23–35` 를 엶 | ✅ 1 을 고침 |
| D030 예외는 해당 없음(machdep 코드, NeXTMach 짝 있음) | AGENTS.md 의 D030 문구(이 대화 머리의 프로젝트 지시) | ✅ |
| NeXTMach 출처 범위는 `pcb.c:152–228·235–314·328–345`, "Major hack" 주석(340–342)도 옮겨짐 | §623 에서 NeXTMach `pcb.c:150–349` 를 읽음(이번 세션) | ✅ 기록에 둠 |
| `kfree` 는 `extern void kfree(vm_offset_t, vm_size_t)`(스테이지 `kern/kalloc.h:62`) — 캐스트는 바이트를 바꾸지 않을 것(예측) | `kalloc.h:62` 를 엶 | ✅ E1 로 확인 |
| `()` 선언은 원형이 아님; `thread_start` 정의는 `(thread_t, continuation_t)`(스테이지 `kern/thread.c:1773–1776`)이고 A1 은 정수 `pc` 를 넘김; 공유 머리로 원형을 옮기지 말 것 | `thread.c:1773–1776` 을 엶 | ✅ 파일 안 선언을 유지(형 원형을 새로 만들지 않음) |
| M5 `differ_unexpected`·`lost` 를 python 으로 단언; `-E` run 판정(stderr 빔·i386 0·`#` 줄 뺀 토큰 같음); 최종 `refs` 경로·SHA 와 `m5_line`; 기록 이름 미리 적기; run ID 미사용 | REGISTRY grep(이번 세션 각 run 직전에 다시 봄) | ✅ 아래에 적음 |

기록 이름: `m4-m68k-probe-p627-e1-20261031.json`·`m4-m68k-funcbytes-p627-E1-`, `m4-m68k-probe-p627-p1-`·`m4-m68k-funcbytes-p627-F/L-`, `m4-m68k-p627-e2-`, `m4-m68k-p627-final-`·`m4-m68k-funcbytes-p627-a1-`, `m4-m68k-p627-checks-`, `m3-m68k-p627-compare-`·`-b622-`, `m4-x86-inputs-p627-`, `m4-m68k-status-p627-`(모두 `20261031.json`). 재생성 스테이지 이름 `m0p622-r627-stage`.

### 627.2 결과(2026-10-31)

- 0: 진단 E1(run `m4p627-e1`, `m4-m68k-probe-p627-e1-20261031.json`): 컴파일 종료 0·경고 0·i386 0, 18/18(`m4-m68k-funcbytes-p627-E1-20261031.json`), L1 `OBJECT_MATCH`·`full_span`, D5 객체와 `canon` 같음 — `kfree` 캐스트와 `stack_attach` 두 문장은 바이트를 바꾸지 않습니다.
- 1·2: 07 `src/machdep/m68k/pcb.c`(568 행, SHA `fbb300ce…`)를 scratchpad `gen_p627.py` 로 E1 에서 만들었습니다(x86 07 `pcb.c:1–23·25–34` 고지, 수정 표시 줄, NeXTMach `pcb.c:2` 고지, plan 627 설명, 함수 18 줄의 출처·원본 주소 표시). 주석(그리고 `//` 주석) 뺀 토큰이 E1 과 같고 L(`08_build/artifacts/m4p627/src/pcb_L.c`)과 줄마다 같습니다(python). `stage_m68k.py` 727 → 729 행.
- 3: `--plan 622` 재생성(`m0p622-r627-stage`) = 보관본(매니페스트·파일 해시), `m0p627-a1-stage`(975 파일)와 보관 622 의 차이는 새 파일 하나와 키 `files`·`m4_sources`·`plan` 입니다. M5: `m5-622.cmd` 가 §622 것과 `cmp` 같고 `m5-627.cmd` 와는 계획 번호만 다름; run `m3p627-b622`·`m3p627-cc1` 205 객체 바이트 같음·stderr 205 같음; `compare`(`m3-m68k-p627-compare-20261031.json`, `-b622-`) `differ_unexpected`·`lost` 빔(python 단언), 요약 차이는 `stage_vs_test_stage` 의 새 파일뿐. x86 `m4-x86-inputs-p627-20261031.json` `ok`, `--plan 627 x86gate` 일곱 같음·`v183.34` 0.
- 4: run `m4p627-p1`(`m4-m68k-probe-p627-p1-20261031.json`): F·L 종료 0·경고 0·i386 0·`OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 18/18(`-F/L-`). F = L(canon·`obj_sig` 모든 칸), L = E1(canon), 바이트 차이 27212 은 모두 문자열 표·`n_strx` 입니다. run `m4p627-e2`(`m4-m68k-p627-e2-20261031.json`, `ok`): `-E` 토큰 11781 같음, i386 0, stderr 빔.
- 5: run `m4p627-a1`(`m4-m68k-p627-final-20261031.json`, SHA `f2dee8e4…`): `gate.ok`, 18/18(`-a1-`). 확인 `m4-m68k-p627-checks-20261031.json`(`ok` 참): 섹션 1634·4, 문자열 원본과 같음, `__text` 재배치 49·참조 49 원본과 같음, 외부 정의 18 원본 자리, 지역 없음, COMMON `_master_cpu`·`_pcb_zone`·`_stack_pointers`(각 4, 원본 섹션 6), 원본에 없는 미정의 없음, 의존 118 파일 사슬 문제 0·i386 0, 객체 SHA `fbc27720…`.
- 6: 근거 `06_reconstruction/evidence/m68k-pcb.md`(상태 도구 전), diff `m68k-pcb.diff`(x86 07 대비)·`m68k-pcb-nextmach.diff`(NeXTMach 발췌 1–2·150–228·231–314·328–345 대비). `ACCEPTED` 한 줄(`m4_m68k_status.py` 176 → 177 행). 상태 도구 두 번 같음, 상태표 42 → 43 행(더한 것 `pcb` 하나), 요약은 미리 계산한 값과 python 으로 같음: 41 객체(OBJECT_MATCH 32, CODE+BSS_INFERRED 9), 덮은 행 65/188, 64780/215874 B(30.01%), `object_bytes` 81982, `rows_unassigned_before` 에 `m68k-308` 더함(`m4-m68k-status-p627-20261031.json`).
- 7: PROVENANCE 1189 → 1190 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 725 → 726 행, DECISIONS D143(146 → 147 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D143).

## 628. M4-134 세부 계획 — m68k `trap.c`(행 315–320) 진단 A1(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: D142(`struct pcb`)·D143(`pcb.c`)로 §619.2 의 pcb 전제가 풀렸습니다. 남은 `thread->u_address` 는 1997 스테이지에서 `thread->_uthread`(`kern/thread.h:171`)·`task->u_address`(`kern/task.h:96`)·`u` = `active_u[cpu_number()]`(`bsd/sys/user.h:350`)로 바뀐 이름입니다.

확인한 사실(이번 세션; Ghidra 출력 `05_ida/exports/m68k/ghidradec-functions/functions/040996B8.c` 등 아홉은 읽기 안내):
- 1997 `trap()`(2444 B)은 NeXTMach `trap()` 과 구조가 다릅니다. 사용자 모드(저장 SR 의 S 비트 0)이면 `u` 의 `ru_stime` 저장, `active_u` 의 둘째 칸 저장·교체, pcb `saved_regs` 교체, 벡터별 switch(버스·주소 오류, 0x34·0x18·0xc·0x24 trace → `do_trace`, MMU 오류 0x404·0x40c·0x410 → `vm_fault`·`tlb_update_*`·`do_writeback`, F-line 등 → `exception_with_continuation(코드, …)`), 그 뒤 `CHECK_SIGNALS`·`issig`·`psig`·`csw_needed`·`thread_block`·`ru_nivcsw` 고리, 프로파일(`addupc`), 끝에 복원과 예외 틀 크기 표(`trap_type` 뒤 32 B, `lea 0x40b2c9a`) 값을 돌려줍니다. 커널 모드이면 `vm_fault`(사용자/커널 map)·`thread->recover`(+0x70)·`copyoutstr`..`fast_setjmp` 범위의 `FAULT_ERROR`·`probe_recover`·`bmap_parity_error`·`"unexpected kernel page fault failure"`·`gdb_from_trap`·`printf` 세 줄·`traceback`(setjmp `traceback_jb`)·`trap_type` 찾아 `panic` 입니다. 이 흐름은 x86 07 `machdep/i386/trap.c` 의 `user_trap`(95)·`kernel_trap`(221)과 같은 계열입니다(x86 07 은 PROVENANCE 639 행 `darwin01`).
- `unix_syscall`(466 B)·`unix_syscall_return`(198 B)·`check_for_ast`(428 B)는 x86 07 `unix_syscall`(664)·`unix_syscall_return`(722)·`check_for_ast`(771)와 같은 흐름에 m68k 레지스터 꼴(d0/d1, SR 의 C 비트, pc −2)입니다.
- `do_trace`(34 B): 저장 SR `&= 0x3fff` 뒤 `exception_with_continuation(6, 0, 0, 0)`. NeXTMach `dotrace`(1083)와 다릅니다.
- `traceback`(202 B)·`do_writeback`(390 B)은 NeXTMach `trap.c:1113·1152` 를 바탕으로 비교합니다(`do_writeback` 의 정적 `wb` 는 원본 범위에서 bss 참조 없음, §619.1).
- `move_space`(240 B)는 1997 C 함수(NeXTMach 는 `locore.s:472` 어셈블리)로 `__move_space`·`exception_from_kernel` 을 부르고 `saved_regs` 를 저장·교체·복원합니다(§620.2).
- `bmap_parity_error`(208 B): `bmap_chip+8 |= 0x80`, 메모리 크기(`dma_chip == 0x139`·`machine_type == 3`·`num_regions`)로 SIMM 소켓 번호를 계산해 `printf("parity error at address 0x%x, SIMM memory sockets %d%s%d\n", …)`·`panic("parity error")`.
- 자료: `__data` `trap_type`(NeXTMach `trap.c:161–188` 의 22 항목 + 끝, 138 B)과 바로 뒤 이름 없는 `short` 16 개(32 B). COMMON `traceback_jb`·`traceback_recursive`·`traptrace`(§619).

방법(진단 A1; 명세 `08_build/artifacts/m4p628/spec.json`, run `m4p628-p1`, 바탕 `08_build/runs/tools/m0p627-a1-stage`, 객체 `trap`, `m4_id` 행 315–320, `x86_rel` `machdep/i386/trap.c`; 생성 scratchpad `gen_p628.py`):
- 원본 차례 아홉 함수의 작성 글(D024): `unix_syscall`·`unix_syscall_return`·`check_for_ast` 와 `trap` 의 사용자/커널 갈래는 x86 07 `trap.c` 를 틀로 하고 m68k 부분을 원본 바이트로 씁니다. `trap_type`·`traceback`·`do_writeback` 은 NeXTMach 글을 쓰고, `do_trace`·`move_space`·`bmap_parity_error` 는 원본 바이트로 씁니다. pcb 칸은 D142 이름, uthread 는 `thread->_uthread`, 32 B 표는 파일 안 정적 `short` 배열(진단 이름)로 `trap_type` 바로 뒤에 둡니다.
- 머리는 스테이지에 있는 것만 씁니다(§619.2 의 `next/trap.h`·`next/scr.h` 처럼 없는 것은 파일 안 진단 정의).

측정: 종료·경고·i386 0, 컴파일 명령 = M5 줄; `__text` 4610·L1; funcbytes(`m68k_funcbytes.py 0x40996b8 0x409a8ba`) 함수별 같음/길이; `__data` 170 B 가 원본 [0x40b2c10, 0x40b2cba) 와 같은지(재배치 대상 포함); `__cstring` 이 원본 [0x40acb10, 0x40ace6d) 와 같은지("parity error" 는 합쳐진 문자열 — §619); 외부 정의·COMMON·원본에 없는 미정의.

판정(미리 정함; 07 은 바꾸지 않음): 결과를 적고 다른 함수를 B 진단으로 고칩니다. 큰 함수(`trap`)는 여러 차례가 걸릴 수 있습니다.

관문: 컴파일 명령 = M5 줄, i386 0. 종료·경고는 기록합니다.

### 628.1 교차검토(codex `gpt-6.1-sol`, task k9bxh5llr) 판정과 계획 수정

먼저 제 잘못입니다: (1) 사실 줄에서 "0x34·0x18·0xc·0x24 trace → `do_trace`" 는 틀린 묶음입니다. `do_trace` 를 부르는 벡터는 0x24 하나이고, 0x34 는 기본(`EXC_BAD_INSTRUCTION`) 갈래입니다. (2) "`active_u` 의 둘째 칸 저장·교체" 는 그 칸이 가리키는 uthread 의 `uu_ar0` 를 저장·교체하는 것입니다. (3) x86 07 함수와의 대응은 구조 참고일 뿐입니다 — m68k `trap()` 은 값을 돌려주고, 시스템 호출 인자 처리와 AST 인터럽트 처리도 다릅니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 사용자 벡터별 동작(0x24 만 `do_trace`, 0x34 기본) | 목록 193611–193616 행(`do_trace`: `andw #0x3fff`, `exception_with_continuation(6,0,0,0)`)을 엶; 나머지 벡터 표는 Ghidra `040996B8.c` 의 switch 와 같음 | ⚖️ `do_trace` 는 확인, 나머지는 `trap()` 진단(다음 계획)에서 바이트로 확인 |
| `uu_ar0` 저장·교체·복원(0x40b57d4 = `active_u` 둘째 칸) | 목록 193045–193050 행 근처(0x4099b36 `movel 0x40b57d4:l,a0; movel a0@,…; movel …,a0@`)를 엶 | ✅ 고침 |
| `thread->recover` +0x70, PC 범위는 `copyoutstr < pc < fast_setjmp` | 목록 192879 행 근처(0x40998be `movel a0@(0x70:w),…`)를 엶; Ghidra 의 `<`·`<` 비교 | ⚖️ +0x70 확인, 경계는 `trap()` 진단에서 |
| `traceback` 출력 형식은 원본에 `0x` 접두가 있음; NeXTMach 1131 행에는 없음 | NeXTMach `trap.c:1124·1131` 을 grep; 원본 문자열 0x40acdd5 `called from pc 0x%08x fp 0x%08x …`(§619) | ✅ |
| COMMON 크기: `traceback_jb` 104 B, `traceback_recursive`·`traptrace` 4 | `symbols.tsv:3055–3059`(python: 0x40c9900 − 0x40c9898 = 104) | ✅ |
| `sysent[63]` = 0x40add4c | python (0x40add4c − 0x40adb54)/8 = 63 | ✅ |
| 스테이지에 있는 매크로(`CHECK_SIGNALS`·`thread_should_halt`·`csw_needed`·`need_ast`/`ast_*`·`aston`·`USER_REGS`·`NORMALRETURN`/`RESTARTSYS`)와 uthread/utask 오프셋 | — | ⚖️ 작성 안내로 쓰고, 컴파일·바이트로 확인 |
| `do_writeback` 은 NeXTMach 와 크게 다름(상태 `& 0x98 == 0x80`, `move_space` 다섯째 인자, 첫 0 아닌 결과 유지) | — | ⚖️ 작성 안내로 씀 |
| `"parity error"` 는 합쳐진 문자열이라 객체의 `__cstring` 은 861 + 13 = 874 B 일 수 있음 — 바이트 수를 고정하지 말 것 | §619 의 문자열 집계 | ✅ 측정은 문자열 내용·참조로 |
| `trap()` 을 다음 진단으로 떼고, 나머지 여덟(2166 B)부터 | python 4610 − 2444 = 2166 | ✅ 방법을 고침 |

계획 수정: A1 은 `trap()` 을 뺀 여덟 함수와 자료(`trap_type`, 32 B 표)만 씁니다(`trap()` 은 §629 이후). 측정은 funcbytes 함수별(여덟 개; `_trap` 은 "없음" 으로 나옴), `__data` 내용·재배치 대상, 문자열 내용, COMMON(`traceback_jb` 104·`traceback_recursive` 4·`traptrace` 4)과 머리가 낳는 COMMON 을 따로 셉니다. `__text` 전체 크기·L1 판정은 이 진단에서 판정 기준으로 쓰지 않습니다.

### 628.2 결과(run `m4p628-p1`·`p2`, 2026-10-31)

- `m4p628-p1`: 컴파일 종료 1 — 제 선언 실수(`fspause` 를 다시 선언, `dma_chip`·`machine_type` 를 스테이지 `bsd/m68k/cpu.h:48–51` 과 다른 형으로 선언, `struct bmap_chip` 을 들이지 않음, `unix_syscall_return` 원형 없음). 고친 글로 run `m4p628-p2`(`m4-m68k-probe-p628-p2-20261031.json`): 종료 0·경고 0·i386 0.
- funcbytes(`m4-m68k-funcbytes-p628-A1-20261031.json`): `unix_syscall_return`·`do_trace`·`do_writeback` 같음. 다른 것:
  - `move_space`(240 = 240, 10 바이트): 원본은 `regs->r_pc` 를 `u.u_procp` 보다 먼저 읽습니다.
  - `traceback`(원본 202, A1 206): 원본은 첫 `printf` 뒤에 `interrupt_stack[cpu]`·그 +4096 을 주소 레지스터(a3·a5)에 두고 고리에서 비교합니다(고리 밖 지역 변수 꼴로 보임). A1 은 고리마다 다시 읽습니다.
  - `bmap_parity_error`(원본 208, A1 194): 원본은 `addr`(부호 있는 `int`, d3)에서 `addr - (slot_id + 0x4000000)` 를 먼저 d2 에 두고, 메모리 크기를 정한 뒤 몫을 늘 계산하고(`divsll` 둘), `socket` 을 4/2 로 정한 뒤 `socket + 1`/`socket + 3` 을 접지 않습니다.
  - `check_for_ast`(원본 428, A1 412): 원본은 `ast_off(mycpu, reasons)` 도 `splhigh()`/`splx()` 로 감싸고, 저장한 SR 을 부호 확장 없이 주소 레지스터에 둡니다(`moveaw`; 스테이지 `spl_t` 는 `int` — `machspl.h:36`).
  - `unix_syscall`(원본 466, A1 348): 원본은 `setjmp` 가 두 번째로 돌아온 뒤(0x409a16a–0x409a1b2) 함수 처음의 초기화(`regs` 복사·`thread`·`uthread`(+0x80)·`utask`(task+0x30)·`code`·`callp`)를 다시 계산하고, 처음에 `utask->uu_ru.ru_stime`(+0x16e/+0x172)을 지역에 저장합니다. `setjmp` 때문에 지역이 모두 스택에 있습니다. 원인은 아직 모릅니다.

## 629. M4-135 세부 계획 — `trap.c` B 진단(다섯 함수의 글 꼴; 07 변경 없음; 코딩 전, 2026-10-31)

방법: A1(고친 글)에서 함수만 바꾼 변형(run `m4p629-p1`, 바탕·`m4_id`·`x86_rel` 같음):
- B1(모두 함께): `move_space` 는 `int pc = regs->r_pc;` 를 `p` 보다 먼저 선언; `traceback` 은 첫 `printf` 뒤 `stackbot = (struct frame *)interrupt_stack[cpu_number()]; stacktop = (struct frame *)(interrupt_stack[cpu_number()] + INTSTACK_SIZE);` 를 대입하고 고리에서 씀; `bmap_parity_error` 는 `int addr` 인자·`offset`·`memsize`·`bank` 를 먼저 계산하는 꼴; `check_for_ast` 는 `short s` 와 `ast_off(mycpu, reasons)` 둘레의 `splhigh`/`splx`; `unix_syscall` 은 x86 07 꼴에 `struct utask *utask = thread->task->u_address;`·`struct timeval syst = utask->uu_ru.ru_stime;` 등 모든 지역을 선언 초기화로 두는 꼴(원본의 재계산이 컴파일러 동작인지 보는 시험).
- B2: B1 에서 `unix_syscall` 만 A1 꼴로 되돌림(대조).

측정·판정은 §628 과 같습니다(함수별 funcbytes; 같아진 함수는 다음 변형에서 고정).

### 629.1 교차검토(codex `gpt-6.1-sol`, task kjkpx66ml) 판정과 계획 수정

먼저 제 잘못입니다: (1) `unix_syscall` 의 재계산 원인을 "모름" 으로 두었으나, NeXTMach `next/trap.c` 의 `unix_syscall` 이 `INIT_VARS` 매크로(851–862 행)를 함수 처음(880 행)과 `fast_setjmp` 이 0 아닌 값을 돌려준 갈래(926 행)에서 두 번 씁니다 — 1997 원본은 이 NeXTMach `unix_syscall` 을 고친 글입니다. A1 을 x86 07 틀로 쓴 것이 틀린 출발점이었습니다. (2) `check_for_ast` 의 `moveaw` 는 그 자체로 부호 확장을 합니다. "부호 확장 없이" 는 "따로 `extl` 이 없음" 으로 고칩니다. (3) `move_space` 는 `pc` 를 `thread` 보다도 먼저 읽습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 두 74 B 덩이 [0x409a050, 0x409a09a)·[0x409a16a, 0x409a1b4) 가 같은 초기화 | python: 두 길이 74·74; §628.2 의 원본 풀이 | ✅ |
| NeXTMach `INIT_VARS`(851) 를 880·926 행에서 씀; 1997 의 `syst` 복사·`p` 시험·간접 호출(`r_dreg[1]`·`&r_dreg[2]`)도 NeXTMach 꼴 | NeXTMach `trap.c:845–935` 를 엶; 원본 0x409a102–0x409a10a(`movel a0@,d0`·`addqw #8,a1`) | ✅ `unix_syscall` 을 NeXTMach 바탕으로 다시 씀 |
| `check_for_ast` 의 둘째 `splhigh`/`splx` 는 프로세스·신호 덩이 뒤에서 `ast_off(mycpu, reasons)` 만 감쌈(0x409a3e2–0x409a412); `short s` | §628.2 rawdiff(0x409a3e2 `movew %sr,%d0`…0x409a412) | ✅ |
| `traceback` 은 첫 `printf` 뒤 한 번 읽어 a3, `lea 0x1000(a3),a5` | §628.2 rawdiff(0x409a4fa·0x409a500) | ✅ `stacktop = (struct frame *)((char *)stackbot + INTSTACK_SIZE)` |
| `move_space` 차례는 `pc` → `thread` → `p` | §628.2 rawdiff(원본은 0x409a712 에서 pc 를 먼저 읽음) | ✅ |
| `bmap_parity_error` 는 `int addr`·부호 있는 몫 둘·무조건 몫·인자 차례 | §628.2 의 원본 풀이(0x409a7f2–0x409a894) | ✅ |

변형(run `m4p629-p1`):
- B1: 네 함수 수정(위) + `unix_syscall` 을 NeXTMach `unix_syscall`(865–1010 행)에서 m68k 1997 꼴로 고친 글(`INIT_VARS` 두 번, `struct regs *regs` 인자, `thread->_uthread`·`thread->task->u_address`, `p` 가 0 이면 `exception(EXC_SOFTWARE, EXC_UNIX_BAD_SYSCALL, 0)`(반환 없음), `syst` 복사, `uu_ar0`·`saved_regs`·`uu_error`, 간접 호출, `bcopy`, `r_val1 = 0`, `setjmp`, 두 번째 갈래는 `INIT_VARS` 뒤 `uu_error`/`uu_eosys` 시험만(NeXTMach 의 `unix_reset`·halt 고리 없음), 정상 갈래는 x86 07 과 같은 `uu_eosys`·`uu_rpswhich`·`uu_rpsfs`·호출, 끝에 `unix_syscall_return(error)`).
- B2: B1 에서 `unix_syscall` 만 지역 변수를 선언 초기화로 두고 `INIT_VARS` 를 쓰지 않는 꼴(대조).

### 629.2 결과(run `m4p629-p1`, 2026-10-31)

- B1·B2 모두 컴파일 종료 0·경고 0·i386 0(`m4-m68k-probe-p629-p1-20261031.json`). 생성기 줄 하나를 제 실수로 깨뜨려(셸 heredoc 이 `\n` 을 줄바꿈으로 바꿈) 한 번 고쳐 돌렸습니다(run 은 그 뒤 한 번만).
- funcbytes(`m4-m68k-funcbytes-p629-B1/B2-20261031.json`): 여덟 함수 가운데 다섯이 같습니다 — A1 의 셋에 더해 `traceback`(첫 `printf` 뒤 `stackbot`/`stacktop` 지역)·`move_space`(`pc` 를 먼저 읽음)가 맞았습니다.
- 남은 셋:
  - `unix_syscall`: B1(NeXTMach `INIT_VARS` 두 번) 370 B, B2(선언 초기화) 336 B, 원본 466 B — `INIT_VARS` 꼴이 원본에 더 가깝지만 아직 96 B 모자랍니다.
  - `check_for_ast`(424/428): 원본은 저장 SR 값을 주소 레지스터 a1 에 두고(`moveaw`; 따로 `extl` 없음) d2–d6 만 저장합니다. B1 의 `short s` 는 d2 에 들어가 d7 까지 저장합니다. 원본은 `spl_t`(= `int`) 값이 주소 레지스터에 할당된 꼴로 보입니다(추론).
  - `bmap_parity_error`(200/208): (a) 원본은 `slot_id + 0x4000000` 을 먼저 계산해 `addr` 에서 빼는데, B1 은 GCC 가 `(addr − 0x4000000) − slot_id` 로 다시 묶고 `addr` 를 a2 에 둡니다. (b) B1 에서는 GCC 가 `machine_type == 3` 두 시험 사이를 이어(jump threading) `socket + 3` 을 7 로 접었는데, 원본은 잇지 않았습니다.

판정: 남은 셋은 레지스터 할당과 식 변형의 차이라 꼴 시험이 더 필요합니다. 다음 계획(§630)에서 함수별 변형을 한 run 에 여럿 두고 잽니다. `trap()` 은 그 뒤입니다.

## 630. M4-136 세부 계획 — `trap.c` C 진단(`unix_syscall`·`check_for_ast`·`bmap_parity_error` 변형; 07 변경 없음; 코딩 전, 2026-10-31)

확인한 사실(이번 세션, B1 rawdiff): 원본 `unix_syscall` 은 `linkw #-52` 로 지역을 모두 스택 칸에 둡니다(`r`·`thread`·`uthread`·`utask`·`syscode`·`callp`·`params`·`error`·`syst`). B1 은 `linkw #-28` 이고 `r`(a2)·`utask`(a3)를 레지스터에 둡니다 — B1 은 NeXTMach 처럼 지역을 `register` 로 선언했습니다. `setjmp` 를 부르는 함수에서 GCC 는 `register` 가 아닌 자동 변수를 스택에 둔다고 봅니다(추론; 측정으로 확인).

변형(run `m4p630-p1`; 모두 B1 에서 세 함수만 바꿈; 함수별 funcbytes 로 판정하므로 한 변형에 여러 함수의 시험을 함께 둠):
- V1: `unix_syscall` 의 지역에서 `register` 를 모두 뺌(U1). `check_for_ast` 는 `int s;` 를 함수 범위에(C1). `bmap_parity_error` 는 `membase = slot_id + 0x4000000; offset = addr - membase;` 두 문장(P1).
- V2: U1. `check_for_ast` 는 고리 안 `register int s;`(C2). `bmap_parity_error` 는 파일 안 진단 매크로로 `machine_type`·`slot_id` 를 `volatile` 로 읽음(P2: 원본이 `machine_type` 시험을 잇지 않고 `slot_id + 0x4000000` 을 먼저 계산하는 것이 휘발 읽기 때문인지 시험).
- V3: U1. `check_for_ast` 는 `int s;` 를 고리 안에 두고 `mycpu` 를 함수 범위에(C3). `bmap_parity_error` 는 `machine_type` 만 `volatile` 로(P3).
- V4: U1 과 같되 `unix_syscall` 의 간접 호출 갈래만 B2 의 한 줄 삼항 꼴(U2; 대조). `check_for_ast`·`bmap_parity_error` 는 B1 그대로(대조).

측정·판정은 §628 과 같습니다(함수별 funcbytes, 같아진 꼴은 고정). 진단 매크로(P2·P3)는 원인 확인용이고, 맞더라도 07 꼴은 따로 사용자에게 묻습니다.

### 630.1 교차검토(codex `gpt-6.1-sol`, task kcandoizt) 판정과 계획 수정

먼저 제 잘못입니다: (1) "`setjmp` 를 부르는 함수에서 GCC 는 `register` 아닌 지역을 스택에" 는 GCC 2.7 `c-decl.c` 에서 `flag_traditional` 조건 아래의 경로이고, 이 컴파일 줄의 `-traditional-cpp` 와는 다른 선택지라 그대로 단정할 수 없습니다(측정으로 확인). (2) U1 은 NeXTMach 가 선언만 하고 쓰지 않는 `int s`·`int opc` 를 빠뜨려, 원본 틀 52 B 를 설명하지 못합니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 칸: −4 `r`, −8 `params`, −12 `callp`, −16 `error`, −20 `uthread`, −24 `utask`, −28 `p`, −32 쓰이지 않음, −36 `thread`, −40 쓰이지 않음, −48/−44 `syst`, −52 `syscode` | §629.2 의 원본 풀이(0x409a04c `clrl fp@(-16)`, 0x409a054 `fp@(-4)`, 0x409a05e `fp@(-36)`, 0x409a062 `fp@(-20)`, 0x409a06c `fp@(-24)`, 0x409a074 `fp@(-52)`, 0x409a08c `fp@(-12)`, 0x409a0a0 `fp@(-28)`, 0x409a0c8/cc `fp@(-48)/(-44)`, 0x409a0f2 `fp@(-8)`) | ✅ |
| NeXTMach 선언 차례(`r`, `params`, `callp`, `error`, `uthread`, `utask`, `p`, `s`, `thread`, `opc`, `syst`, `syscode`)로 두면 그 칸·틀 52 B 가 나옴; `s`·`opc` 를 빼면 44 B | python: 위 차례로 칸 −4…−52·틀 52, 둘을 빼면 44; NeXTMach `trap.c:865–880` 선언을 이번 세션에 엶 | ✅ U3 을 더함 |
| `check_for_ast` 원본 레지스터 지도(s a1, reasons d2, mycpu d4, saved_regs d5, 임시 d6; p a2·thread a3·AST 기준 a4·regs a5); B1 은 s d2·reasons d3·mycpu d5·saved d6·임시 d7 | §629.2 rawdiff(원본 `moveml %d2-%d6/%a2-%a5`, `moveaw %d0,%a1`, d4 `clrl`, d5 `fp`; B1 `moveml %d2-%d7/…`, `movew %d0,%d2`) | ✅ |
| `bmap_parity_error`: 휘발 읽기는 이어지지 않은 `machine_type` 시험은 설명할 수 있으나, `slot_id + 0x4000000` 묶음까지 설명하지는 않음; 다른 07 파일은 `extern int slot_id`, 스테이지는 `extern u_char machine_type` | `m68k_init.c:107`·`autoconf.c:58`·스테이지 `cpu.h:51` 을 이번 세션에 grep | ✅ 두 가설을 따로 시험 |
| `.lreg` 덤프나 NeXT 컴파일러 소스는 확인 못 함 | — | ⏭️ |

변형(run `m4p630-p1`, B1 에서 세 함수만 바꿈):
- V1: U3(NeXTMach 선언 차례, `register` 없음, `int s`·`int opc` 포함) + C0(고리 안 `int s`, 선언 차례 `reasons`·`mycpu`·`s`) + P1(`membase = slot_id; membase += 0x04000000; offset = addr - membase;`)
- V2: U1(`register` 만 뺌) + C2(고리 안 `register int s`) + P2(각 시험에서 `*(volatile u_char *)&machine_type`, `*(volatile int *)&slot_id`)
- V3: U3 + C1(`int s` 를 함수 범위, `saved_regs` 바로 뒤) + P3(`machine_type` 시험만 `volatile` 읽기)
- V4: U3 + C3(`mycpu` 선언만 함수 범위, 대입은 고리 안 자리) + P4(`if (bank && machine_type == 3)`)

### 630.2 결과(run `m4p630-p1`, 2026-10-31)

- V1–V4 모두 컴파일 종료 0·경고 0·i386 0(`m4-m68k-probe-p630-p1-20261031.json`, funcbytes `-V1..V4-`).
- **`unix_syscall`**: U3(NeXTMach 선언 차례, `register` 없음, 쓰이지 않는 `int s`·`int opc` 포함)이 V1·V3·V4 에서 같습니다(466 B). U1(`register` 만 뺌, V2)은 466 B 이지만 11 바이트 다릅니다(칸 자리) — 쓰이지 않는 두 지역이 칸 배치를 정합니다.
- **`check_for_ast`**: C0(고리 안 `int s`)·C1(함수 범위 `int s`)·C3(`mycpu` 선언을 함수 범위)이 모두 같습니다(428 B) — 바이트로 가를 수 없는 꼴입니다. C2(`register int s`)도 V2 에서 같습니다.
- **`bmap_parity_error`**: 아직 다릅니다. V1(P1: `membase` 지역 두 문장) 200 B 는 앞부분(`slot_id + 0x4000000` 을 먼저 계산, `addr` 를 d3)이 맞았고, 남은 차이는 (a) 원본은 `memsize / num_regions` 를 d0 자리에서 나누고 몫을 d1 에 두는데(오프셋 d2 유지) V1 은 d1 로 복사해 나눈 뒤 오프셋 자리 d2 에 몫을 둠, (b) V1 은 `machine_type == 3` 두 시험을 이어 `socket + 3` 을 7 로 접음. V2(휘발 둘) 230 B·V3(휘발 `machine_type`) 226 B 는 더 멀어집니다 — 원본은 휘발 읽기가 아닌 것으로 봅니다. V4(P4: `bank` 먼저 시험) 206 B 는 접기가 사라졌으나 시험 차례가 원본과 반대입니다.

따라서 여덟 함수 가운데 일곱이 맞았고(U3 + C0/C1/C3), `bmap_parity_error` 하나와 `trap()` 이 남았습니다.

## 631. M4-137 세부 계획 — `bmap_parity_error` D 진단(07 변경 없음; 코딩 전, 2026-10-31)

방법: V1(U3·C0·P1) 바탕에서 `bmap_parity_error` 만 바꾼 변형(run `m4p631-p1`):
- Q1: `memsize /= num_regions; bank = offset / memsize;`
- Q2: `socket = (machine_type == 3 && bank) ? 2 : 4;`
- Q3: Q1 + Q2
- Q4: `if (machine_type == 3 && bank) socket = 2; else socket = 4;`
- Q5: Q1 + Q4
- Q6: Q1 + 마지막 인자를 `socket + ((machine_type == 3) ? 1 : 3)` 로.

측정·판정은 §628 과 같습니다.

### 631.1 교차검토(codex `gpt-6.1-sol`, task k505y6j31) 판정과 계획 수정

먼저 제 잘못입니다: §630.2 에서 V4 를 "시험 차례만 바꾼 것" 처럼 적었으나, V4 는 P1(`membase`)이 없는 B1 바탕이라 두 가지가 섞인 대조입니다(생성기 `gen_p630.py` 의 V4 = U3·C3·P4).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| V1 과 원본의 차이는 나눗셈(+2 B)과 `socket` 덩이(−10 B) 둘뿐, 합 200 vs 208 | §630.2 rawdiff(0x409a840–0x409a84a, 0x409a864–0x409a88a); python 208 − 200 = 8 | ✅ |
| V4 는 P1 이 없는 혼합 대조 | `gen_p630.py` 의 `V4: (U3, 'C3', 'P4')` | ✅ |
| `thread_jumps` 는 두 비교의 RTL 꼴이 같을 때 잇고, 사이에 남는 대입이 있으면 막힘; `else socket = 4`·삼항·중첩 조건이 후보 | — | ⚖️ 측정으로 확인 |
| 나눗셈은 `memsize /= num_regions; bank = offset / memsize;`(Q1)과 `bank = offset; bank /= memsize;`(Q8)를 함께 볼 것 | — | ✅ Q8 더함 |
| 중첩 조건 `if (machine_type == 3) socket = bank ? 2 : 4; else socket = 4;`(Q7), P1 + `bank` 먼저(Q9 대조) 를 더할 것 | — | ✅ 더함 |
| `-da` 덤프로 통과 과정을 볼 것 | — | ⏭️ 컴파일 선택지를 바꾸는 일이라 이번에는 하지 않음 |

변형(run `m4p631-p1`, 모두 V1 바탕): Q1–Q6(§631), Q7(Q1 + 중첩 조건), Q8(Q8 나눗셈 + Q4), Q9(P1 + `if (bank && machine_type == 3)` 대조).

### 631.2 결과(run `m4p631-p1`, 2026-10-31)

- Q1–Q9 모두 컴파일 종료 0·경고 0, 나머지 일곱 함수는 계속 같음(`m4-m68k-probe-p631-p1-20261031.json`, funcbytes `-Q1..Q9-`). `bmap_parity_error` 크기: Q1 198, Q2 210, **Q3 208**, Q4 210, **Q5 208**, Q6 198, Q7 214, **Q8 208**, Q9 206.
- Q3(Q1 나눗셈 + 삼항)·Q5(Q1 + `else socket = 4`)·Q8(`bank = offset; bank /= memsize;` + `else`)는 원본과 크기가 같고 11 바이트만 다릅니다. `machine_type` 두 시험의 이음(`socket + 3` 접기)은 `else`/삼항 꼴로 사라졌습니다.
- 남은 차이는 나눗셈의 레지스터 하나입니다: 원본은 `memsize` 를 d0 에 두고 그 자리에서 `num_regions` 로 나눈 뒤 `move.l d2,d1; divsll d0,d1,d1`(몫 d1, 오프셋 d2 그대로), Q3/Q5/Q8 은 `memsize` 를 d1 에, 몫을 d2(오프셋 자리)에 둡니다.

## 632. M4-138 세부 계획 — `bmap_parity_error` E 진단(나눗셈 레지스터; 07 변경 없음; 코딩 전, 2026-10-31)

방법: Q5 바탕(run `m4p632-p1`):
- R1: 선언 차례 `int membase, offset, memsize, bank, socket;`
- R2: 선언 차례 `int socket, bank, memsize, offset, membase;`
- R3: 선언 차례 `int memsize, bank, offset, membase, socket;`
- R4: `regionsize` 지역: `regionsize = memsize / num_regions; bank = offset / regionsize;`(Q5 의 `memsize /=` 대신)
- R5: R4 + R1 선언 차례
- R6: Q5 에서 `offset`·`bank` 를 따로 선언(`int offset; int bank;`)하고 나머지는 Q5 와 같음(같은 선언문 안 차례의 영향 대조)

측정·판정은 §628 과 같습니다.

### 632.1 교차검토(codex `gpt-6.1-sol`, task ks6ox9yv8) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `divsll num_regions,d0,d0; move.l d2,d1; divsll d0,d1,d1`, Q5 `divsll num_regions,d1,d1; divsll d1,d2,d2; move.l d2,d1`, 11 바이트 차이 | §631.2 rawdiff(0x409a840·0x409a848·0x409a84a 와 Q5 0x7fc·0x804) | ✅ |
| `divmodsi4` 꼴은 몫과 피제수 자리를 함께 쓰고 `d0` 를 고르지는 않음; 선언 차례가 레지스터를 보장하지 않음; R4·R5 가 가장 볼 만하고 R1–R3 은 약함, R6 은 선언 차례를 지켜야 대조가 됨 | — | ⚖️ 측정으로 확인(R6 은 차례 `offset, memsize, bank, socket, membase` 를 지켜 나눔) |
| "이름 없는 중간 제수" `bank = offset / (memsize / num_regions)` 를 더할 것 | Q4 가 바로 그 나눗셈 꼴(+ `else`)이고 210 B 였음(§631.2) | ❌ 이미 잰 꼴이라 더하지 않음 |
| 복사한 제수(R8), 몫을 바로 참/거짓으로(R9), 진단용 `&& offset`(R10) 을 더할 것 | — | ✅ 더함(R10 은 원인 확인용) |
| VM 이미지 안의 GCC 소스를 열었다는 주장(`local-alloc.c` 등 줄 번호) | — | ⏭️ 확인하지 않음; 판정 근거로 쓰지 않음 |

변형(run `m4p632-p1`, Q5 바탕): R1–R6(§632), R8(`regionsize = memsize; regionsize /= num_regions; bank = offset / regionsize;`), R9(`bank = (offset / memsize) != 0;` — Q1 의 `memsize /=` 뒤), R10(Q5 + 조건 `machine_type == 3 && bank && offset`).

### 632.2 결과(run `m4p632-p1`, 2026-10-31)

- 아홉 변형 모두 종료 0·경고 0, 나머지 일곱 함수 같음(`m4-m68k-probe-p632-p1-20261031.json`, funcbytes `-R1..R10-`). `bmap_parity_error`: R1·R2·R3·R6 은 Q5 와 같은 208 B·11 바이트 차이(선언 차례·선언 나눔은 영향 없음), R4·R5·R8 210 B, R9 214 B, R10 212 B — 맞는 꼴 없음.

## 633. M4-139 세부 계획 — `bmap_parity_error` F 진단(변수 하나를 두 값에; 07 변경 없음; 코딩 전, 2026-10-31)

가설: 원본은 `slot_id + 0x4000000`(d0)과 메모리 크기(d0)를 같은 레지스터에 둡니다. 원 글이 한 변수를 두 값에 다시 쓴 꼴이면(예: 메모리 기준 주소를 담은 변수에 메모리 크기를 다시 대입) 같은 의사 레지스터가 되어 d0 이 그대로 이어집니다(추론).

변형(run `m4p633-p1`, Q5 바탕; `membase` 를 없애고 `memsize` 한 변수로):
- S1: `memsize = slot_id; memsize += 0x04000000; offset = addr - memsize;` 그 뒤 Q5 와 같음(`memsize = …` 갈래, `memsize /= num_regions; bank = offset / memsize;`, `else socket = 4`).
- S2: S1 에서 나눗셈만 `bank = offset; bank /= memsize;`(Q8 꼴).
- S3: S1 에서 `socket` 을 삼항(Q3 꼴).
- S4: S1 에서 첫 대입을 `memsize = slot_id + 0x04000000;` 한 문장으로.

측정·판정은 §628 과 같습니다.

### 633.1 교차검토(codex `gpt-6.1-sol`, task kzk2gvqt6) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 레지스터 쓰임은 가설과 맞지만, 수명이 겹치지 않는 다른 두 변수도 d0 을 함께 쓸 수 있음 — "같은 변수 ⇒ d0" 은 너무 강함 | §631.2·§630.2 의 원본 풀이(0x409a808–0x409a816, 0x409a840–0x409a84a) | ✅ 가설로 둠 |
| S4 는 두 문장(`memsize = slot_id; memsize += 0x04000000;`)을 함께 한 문장으로 바꿀 것 | 계획 문구를 다시 읽음 | ✅ 그렇게 만듦 |
| S5: S1 + `bank = offset / (memsize / num_regions);` | — | ✅ 더함 |

### 633.2 결과(run `m4p633-p1`, 2026-10-31)

- S1–S5 모두 종료 0·경고 0, 나머지 일곱 함수 같음(`m4-m68k-probe-p633-p1-20261031.json`, funcbytes `-S1..S5-`). `bmap_parity_error`: S1–S4 208 B·14 바이트 다름, S5 210 B.
- S1 은 한 변수가 기준 주소와 크기를 모두 담아 같은 레지스터를 쓰게 되었으나 그 레지스터가 d1 이고(원본 d0), 몫은 여전히 오프셋 자리(d2)에서 계산합니다. Q5(11 바이트)보다 멀어졌습니다.
- 원본은 `offset`(d2)을 복사(`move.l d2,d1`)한 뒤 그 복사본을 나눕니다. 나눗셈 피제수가 형 바꿈으로 새 값이 되면 이런 복사가 생길 수 있습니다(추론).

## 634. M4-140 세부 계획 — `bmap_parity_error` G 진단(오프셋 형; 07 변경 없음; 코딩 전, 2026-10-31)

변형(run `m4p634-p1`, Q5 바탕):
- T1: `offset` 을 `vm_offset_t` 로 따로 선언하고 `bank = (int)offset / memsize;`
- T2: T1 + `membase` 도 `vm_offset_t`
- T3: T1 + `addr` 를 `vm_offset_t` 인자로(`offset = addr - membase` 는 부호 없는 셈, 나눗셈은 `(int)` 캐스트)
- T4: Q5 에서 `bank = (int)(offset / memsize);`(캐스트 위치 대조; `offset`·`memsize` 는 `int`)
- T5: T1 에서 `memsize /= num_regions;` 대신 `bank = (int)offset / (int)(memsize / num_regions);`

측정·판정은 §628 과 같습니다.

### 634.1 교차검토(codex `gpt-6.1-sol`, task kbs74a2y3) 판정과 계획 수정

먼저 제 잘못입니다: codex 를 부를 때 `cwd` 에 셸 꼬리(`&& echo`)를 붙여 한 번 실행되지 않았습니다(`spawn codex ENOENT`). 바로잡아 다시 맡겼습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §633.2 의 나눗셈 순서와 S1 의 d1 쓰임, Q5 11·S1–S4 14 바이트 | §633.2 rawdiff 출력(이번 세션) | ✅ |
| 같은 너비의 `unsigned`→`int` 캐스트는 그 자체로 복사 명령을 만들지 않음 — 가설은 약함 | — | ⚖️ 가설로만 두고 측정 |
| T4 는 Q5 와 같을 것으로 보는 음성 대조, T5 는 Q4 와 견줄 것 | §631.2(Q4 210 B) | ✅ |
| R10 은 오프셋을 살려 두면 복사가 생김을 보였으나 맞지는 않음 | §632.2(R10 212 B) | ✅ |
| 더할 것: `unsigned int bank`(T6), `long bank = (long)offset / memsize`(T7), `int dividend` 임시(T8) | — | ✅ 더함 |

변형(run `m4p634-p1`, Q5 바탕): T1–T5(§634), T6, T7, T8.

### 634.2 결과(run `m4p634-p1`, 2026-10-31)

- T1–T8 모두 종료 0·경고 0, 나머지 일곱 함수 같음(`m4-m68k-probe-p634-p1-20261031.json`, funcbytes `-T1..T8-`). `bmap_parity_error`: T5 210 B, 나머지 일곱은 모두 Q5 와 같은 208 B·11 바이트 — 오프셋·몫의 형과 캐스트, 임시 변수는 나눗셈 레지스터 배정을 바꾸지 않습니다.
- 지금까지 이 함수에 잰 꼴(§629–634)은 서른 남짓이고, 가장 가까운 것은 Q5 계열(크기 같음, 나눗셈의 레지스터 둘이 다름, 11 바이트)입니다. 남은 후보는 메모리 크기를 삼항 식 하나로 정하는 꼴 등 식 구조의 차이입니다.

판정: `bmap_parity_error` 는 Q5 계열의 11 바이트 차이를 남긴 채, 다음 계획에서 `trap()` 진단과 함께 남은 꼴 몇 개를 더 잽니다.

## 635. M4-141 세부 계획 — `trap()` 진단 A(07 변경 없음; 코딩 전, 2026-10-31)

확인한 사실(이번 세션; NeXTMach `trap.c:197–565` 를 읽음, Ghidra `040996B8.c` 는 읽기 안내):
- 1997 `trap()` 의 바탕은 NeXTMach `trap()` 입니다: 커널 모드(`!USERMODE`)면 T_TRACE → pcb `TRACE_PENDING`; MMU(0x404·0x40c·0x410) → `u.u_error` 저장·0, map 고르기(`fcode & ~3`, `kernel_vm_space`·`kernel_map`), `vm_fault` 두 번까지, 성공이면 `pload_*`(1997 `tlb_update_read/write`)·`do_writeback`; T_BUSERR → `thread->recover`·`ALLOW_FAULT`·`probe_recover`·P_MON 재시도; Default → `printf` 셋·`traceback`·`trap_type` panic. 사용자 모드면 `u` 저장(`syst`, `u_ar0`), `saved_regs` 교체, 벡터별 예외 종류, `dotrace`, halt 고리, 예외, `out:` 의 신호·`csw_needed`·`thread_block`·`goto out`, 프로파일, 복원.
- 1997 에 바뀐 것(Ghidra 와 원본 풀이에서): (1) `vm_fault` 가 다섯째 인자를 받음(사용자 0, 커널은 지역의 주소 — 오류 값); (2) 회복 범위가 `copyoutstr < pc < fast_setjmp` 이고 그때 `FAULT_ERROR` 와 함께 `fault_error = 오류 ? 오류 : EFAULT`; (3) T_BUSERR 앞에서 `bmap_chip` 패리티 비트(+8 의 0x80·0x40)면 `bmap_parity_error(faultaddr)`; (4) P_MON 재시도는 `dma_chip == 0x139` 일 때 [`slot_id + 0x200e000`, `+0x200e00c`)·[`+0x200f000`, `+0x200f00c`); (5) 회복 뒤 `thread->recover == move_space_fault` 이면 `r_dreg[0]`·`r_dreg[1]`·`r_areg[0]`·`r_areg[1]` 에 예외 정보; (6) 돌려주는 값은 0 또는 예외 틀 크기 표(`trap_type` 뒤 32 B)의 형식 칸 값(`TRAP_RERUN`/`TRAP_NORERUN` 이 아님); (7) 사용자 갈래는 `thread_doexception` 대신 `exception_with_continuation(종류, 코드, 부코드, 0)`, halt 고리는 `thread_halt_self_with_continuation(0)`; (8) FP 벡터(0xc0–0xdc)는 신호 처리를 미루고 `need_ast |= AST_BLOCK` 꼴과 `aston`; (9) Default 앞에 `gdb_from_trap(r, r_sr, r_pc, faultaddr)`; (10) `USER` 비트를 쓰지 않음(사용자 switch 도 벡터 그대로); (11) 사용자 갈래는 `u_ar0` 를 저장·복원.

방법(진단 A; run `m4p635-p1`, 바탕 `m0p627-a1-stage`; 생성 scratchpad `gen_p635.py`):
- A = V1(§630; 일곱 함수 맞음) + Q5 꼴 `bmap_parity_error` + NeXTMach `trap()` 을 위 1997 바뀜대로 고친 `trap()` + 예외 틀 크기 표(파일 안 정적 `short` 16, 진단 이름)를 `trap_type` 바로 뒤에.
- 같은 run 에 `bmap_parity_error` 꼴 둘을 더 둠(A2: 메모리 크기를 삼항 식 하나로; A3: A2 + `bank = offset / memsize` 앞 `memsize /= num_regions` 대신 삼항 결과를 바로 나눔).

측정: 함수별 funcbytes(아홉), `__data` 170 B 가 원본과 같은지(재배치 대상 포함), `__cstring` 문자열 내용, COMMON, 원본에 없는 미정의.

판정(미리 정함; 07 은 바꾸지 않음): 결과를 적고 다른 부분을 다음 진단으로 고칩니다.

### 635.1 교차검토(codex `gpt-6.1-sol`, task kqtxg1114) 판정과 계획 수정

먼저 제 잘못입니다: 계획에 다섯째 인자가 포인터라는 ABI 차이(NeXTMach 는 `struct regs regs` 를 값으로 받음; 원본은 `fp+0x18` 을 지역 `r` 로 복사)와, 사용자 MMU 갈래의 다른 흐름(성공 뒤 `do_writeback` 결과가 0 아니면 `out`, 실패 때는 결과를 버리고 `rw` 가 읽기가 아니면 `out`), 사용자 DMA 재시도가 공통 복원으로 가는 점을 빠뜨렸습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 틀 `linkw #0xff9c`(지역 100 B), `r` 은 fp−8, `vm_fault` 다섯째 인자는 fp−4 의 주소(오류 값, 처음에 0) | 목록 192734–192752 행(`linkw a6,#0xff9c`, `movel a6@(0x18:w),a6@(0xfff8:w)`, `clrl a6@(0xfffc:w)`)과 0x40997c0 `lea a6@(0xfffc:w),a2; movel a2,sp@-` | ✅ |
| 커널 MMU 성공 뒤 `fault_result = do_writeback(r)` 를 비트 30 먼저(→ BUSERR), 그다음 음수(→ Default), 아니면 0 반환; 실패면 (1, 결과, va) 를 두고 BUSERR 로 떨어짐 | 목록 0x4099856–0x409988a(`btst #30,d0; bne 0x4099890; tstl d0; blt 0x40999e8`, `moveq #1,d5; movel d5,a6@(0xffb8:w)` …) | ✅ |
| 사용자 MMU: 성공이면 `do_writeback` 결과가 0 아니면 `out`(0x4099e1c), 0 이거나 `cpu_type` 0 이면 복원(0x409a000); 실패면 `cpu_type` 일 때 `do_writeback` 결과를 버리고 `rw != 1` 이면 `out`, 아니면 예외 (1, 결과, va) | 목록 0x4099caa–0x4099d2a 를 엶 | ✅ 방법에 넣음 |
| 나머지 열한 항목의 세부(경계 엄격·부호 없음, 패리티 비트 둘, DMA 범위 둘(사용자는 첫째만), `move_space_fault` 고침 칸과 깃발 값, 반환 규칙, FP 벡터 여덟, `gdb_from_trap` 인자, `USER` 비트 없음, `u_ar0` 저장·복원), 원본 틀 지도(−4 오류, −8 `r`, −0xc 안 씀, −0x10 `save_error`, … −0x58 `u_ar0` 저장, −0x5c 깃발, −0x60/−0x64 프로파일) | 위 줄들과 Ghidra 출력이 서로 맞음; 전부를 줄 단위로 열지는 않음 | ⚖️ 작성 안내로 쓰고 바이트로 확인 |
| 선언: `tlb_update_*`·`gdb_from_trap`·`copyoutstr`·`fast_setjmp`·`thread_halt_self_with_continuation` 은 함수, `FAULT_ERROR`·`move_space_fault` 는 주소만 쓰는 표지, `fault_error` 는 `int` 자료, `probe_recover` 는 값을 읽는 `vm_offset_t`, `need_ast` 는 `kern/ast.h` 의 배열 | `kern/ast.h:125`(`ast_on`), `kern/thread.h:163`(`recover`), `bsd/m68k/machparam.h:48`(`USERMODE`) 를 grep | ✅ |
| 예외 틀 크기 표 값 0,0,4,4,−1,−1,−1,52,−1,12,24,84,−1,−1,−1,−1, 지표는 `r_format` | §619 의 python 해독과 같음 | ✅ |

### 635.2 결과(run `m4p635-p1`·`p2`, 2026-10-31)

- p1(A·A2·A3; 모두 종료 0·경고 0; `m4-m68k-probe-p635-p1-20261031.json`, funcbytes `-p635-A`·`-A2`·`-A3-`): 일곱 함수 같음. `bmap_parity_error` 는 A·A2 가 Q5 와 같은 11 바이트 차이, **A3 이 같음**(메모리 크기를 따로 정하지 않고 `bank = offset / (((dma_chip == 0x139) ? ((machine_type == 3) ? 0x2000000 : 0x4000000) : 0x8000000) / num_regions)`). `trap()` 은 2448 B(원본 2444 B)로, 재배치 대상 말고 다른 곳은 세 군데였습니다: (1) 0x40998f4 `fault_error` 를 원본은 if/else 로 정함(`beq`·`bra`·`moveq #14,d6`); 이 때문에 0x4099940 의 `d5`/`d6` 배정도 달라짐; (2) 0x4099b44·0x409a000 원본은 `saved_regs` 를 지역 `pcb`(fp−0x3c)로 다룸(`thread->pcb` 가 아님); (3) 0x4099eac–0x4099ec2 둘째 halt 검사는 원본이 위에서 검사하고, 호출한 뒤 `out:`(0x4099e1c)으로 되돌아감(우리는 고리를 돌린 꼴). 그 뒤의 `csw_needed` 부분(0x4099ed4–)은 (3) 때문에 `thread` 를 a2 에 둔 데서 생긴 차이였습니다.
- p2(A3 바탕; B1 = (1) `if (error) fault_error = error; else fault_error = EFAULT;` + (2) `pcb->saved_regs` 셋 + (3) `if (thread_should_halt(thread)) { thread_halt_self_with_continuation(0); goto out; }`; B2 = B1 의 (3) 을 `while (…) { …; goto out; }` 로; B3 = B1 에서 `bmap_parity_error` 의 쓰지 않는 `memsize` 선언을 뺌; 모두 종료 0·경고 0; `m4-m68k-probe-p635-p2-20261031.json`, funcbytes `-B1`·`-B2`·`-B3-`):
  - **B1·B3: `l1_verdict` OBJECT_MATCH**, 아홉 함수 중 여덟이 바이트·재배치 대상까지 같고, `trap()` 은 바이트 차이 0·재배치 대상 둘(오프셋 714·2420)만 이름이 다름. 이 둘은 예외 틀 크기 표로, 우리 오브젝트는 정적 기호 `_exframesize`, 원본은 `_trap_type+138` 로 풀립니다. 원본 기호표에는 외부 기호(유형 `0xf`·`0x3`)만 있고 정적 기호가 하나도 없으며(`symbols.tsv` 유형 집계), 우리 `__data` 에서도 표는 `_trap_type` 뒤 138 B(0x128c − 0x1202, python)에 있고 `__data` 크기 170 = 138 + 16×2 입니다. 그러므로 이름 차이는 정적 기호가 지워진 데서 오며, 위치는 같습니다.
  - B1 과 B3 은 canon·sig 가 같음 → 쓰지 않는 `memsize` 선언은 바이트로 가릴 수 없습니다.
  - B2 는 4 B 길어 NOT_MATCH → (3) 은 `while` 이 아니라 `if … goto out` 꼴로 가려집니다.

판정: `trap.c` 아홉 함수 모두 진단에서 맞았습니다(B1/B3). 바이트로 가릴 수 없는 꼴(쓰지 않는 `memsize` 선언 여부, 표의 이름, 진단 매크로 이름 등)을 정리해 사용자 결정을 받은 뒤, 다음 계획에서 07 `trap.c` 구현 계획을 세우고 codex 검토를 거쳐 만듭니다.

## 636. M4-142 D144 구현 계획 — 07 `src/machdep/m68k/trap.c`(행 315–320, OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(AskUserQuestion, §635.2 뒤): ① 벡터 상수와 `TRACE_PENDING` 은 **파일 안 NeXTMach 조각**(쓰는 `T_*` 줄만 `next/trap.h` 그대로, `TRACE_PENDING` 은 NeXTMach `next/pcb.h:53` 이름에 1997 값); ② 예외 틀 크기 표 이름 **`exframesize`**(이 프로젝트가 지은 이름이라고 표시); ③ `bmap_parity_error` 의 쓰지 않는 `memsize` 선언을 **뺌**(B3); ④ `check_for_ast` 는 **C0**(고리 안 `int s`).

확인한 사실(이번 세션):
- 07 `src/machdep/m68k/trap.c` 는 없고(ls), PROVENANCE 에 `m68k/trap` 행이 없습니다(grep 0). 스테이지에는 x86 `src/machdep/i386/trap.c` 만 있습니다.
- B3 가 정의하는 `T_*` 26 개는 모두 쓰이고(python), NeXTMach `next/trap.h` 18–32·43–48·51–55 행에 같은 값으로 있습니다(50 행은 MMU 의사 벡터 주석). `MC68030` 은 스테이지 `bsd/m68k/cpu.h:58` 에 있어 진단의 같은 값 재정의는 지웁니다.
- x86 07 `machdep/i386/trap.c` 는 APSL 고지 1–23 행, NeXT 1992 고지·HISTORY 25–34 행("Intel386 Family:\tTrap handlers."), NeXTMach `next/trap.c` 는 1–2 행 "Copyright (c) 1987, 1988 NeXT, Inc."; `INIT_VARS`(`XXX 172 -> 63` 주석 포함)는 NeXTMach `next/trap.c:851–` 입니다.
- 상태 기대(python): 행 315–320 의 `bytes_min` 합 4610(2444 + 1126 + 202 + 390 + 240 + 208), 덮은 행 65 + 6 = 71/188, 덮은 바이트 64780 + 4610 = 69390(32.14%), `object_bytes` 81982 + 4610 = 86592, `rows_unassigned_before` 에 `m68k-317`·`m68k-320` 더함; 객체 42(OBJECT_MATCH 33, CODE+BSS_INFERRED 9).

0. 진단 F1(run `m4p636-f1`, 07 전): F1 = B3 에서 (a) 진단 `#define` 덩이를 NeXTMach `next/trap.h` 18–32·43–48·50–55 행 그대로로 바꾸고, (b) `TRACE_PENDING` 줄 하나와 (c) 진단 `MC68030` 줄을 지운 글. 판정: 종료 0·경고 0·i386 0, 9/9 함수(재배치 대상은 표 이름 둘만 다름 — §635.2), L1 `OBJECT_MATCH`·`full_span`, B3 객체와 `canon` 같음. 아니면 멈추고 사용자에게 알립니다.
1. 07 `src/machdep/m68k/trap.c`(D103)를 F1 글에서 scratchpad `gen_p636.py` 로 만듭니다.
   - 머리: x86 07 `trap.c` 의 APSL 고지(1–23 행)와 NeXT 1992 고지·HISTORY(25–34 행), 날짜 붙은 수정 표시 줄, NeXTMach `next/trap.c:1–2` 고지 줄(D013; `pcb.c` 선례).
   - 설명 주석(plan 636): 원본 범위 [0x40996b8, 0x409a8ba) 4610 B, 아홉 함수와 출처(NeXTMach `trap()`·`unix_syscall`·`INIT_VARS`·`traceback`·`do_writeback`·`trap_type`, x86 07 `check_for_ast`·`unix_syscall_return`·`move_space` 틀, 원본 바이트로 쓴 몸통 D024), 바이트로 정한 1997 바뀜(§635 의 열한 항목 요약, `exframesize` 표, `TRACE_PENDING` 값), 사용자 결정(D144).
   - 진단 표시는 모두 `plan 636 (D144)` 표시로 바꾸고(`plan 628 diagnostic` 등), 작성 몸통 함수 줄에 `plan 636 (D024, D144)` 표시를 답니다(`*/` 뒤 글 없음, python). 주석 뺀 토큰이 F1 과 같아야 합니다.
2. `stage_m68k.py`: `M4FILES[636] = list(M4FILES[627]) + ['trap.c']`, `EXCEPTS[636] = dict(EXCEPTS[627])`, 머리말 plan 목록에 636.
3. 회귀: `--plan 627` 재생성 = 보관본(07 덮어쓰기 변경 없음); 새 스테이지와 보관 627 의 차이는 새 파일 하나와 키 `plan`·`m4_sources`·`files`; M5 205(`m5-627.cmd` 가 있으면 그것, 없으면 §627 과 같은 줄; 두 run 과 `compare` 의 `differ_unexpected`·`lost` 빔); x86(`m4_x86_inputs.py s6ln`·`--plan 636 x86gate`).
4. 확인 run `m4p636-p1`: F = `@machdep/m68k/trap.c`, L = F1 글에 맞춤 주석 줄을 넣은 꼴. 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = F1(canon), 9/9(표 이름 둘 말고), `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`; F·L 바이트 차이는 문자열 표·`n_strx` 뿐. `-E` 토큰 run `m4p636-e2`(F·L, `#` 줄 빼고 토큰 같음).
5. 최종 run `m4p636-a1`(명세 `08_build/artifacts/m4p636/spec.json`: F 만, 바탕 `m0p627-a1-stage`, 객체 `trap`, `m4_id` `m68k-315`…`m68k-320`, `x86_rel` `machdep/i386/trap.c`, `refs["trap"]` = p1 L): `gate.ok`. 확인 기록 `m4-m68k-p636-checks-20261031.json`: 섹션 `__text` 4610·`__data` 170·`__cstring` 874, `__data` 바이트(포인터 재배치 포함)와 `__cstring` 이 원본과 같음, 외부 정의 9 함수 + `_trap_type` 원본 자리, 지역 기호는 `_exframesize` 하나(원본은 정적 기호를 지움 — 위치는 `_trap_type+138`), COMMON `_bmap_chip`·`_master_cpu`·`_traceback_jb`(104)·`_traceback_recursive`·`_traptrace` 가 원본에 있는지(D136), 원본에 없는 미정의 없음, 재배치(funcbytes), 입력 사슬.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-trap.md` 를 먼저 쓰고 `ACCEPTED` 에 한 줄. 기대는 위 python 값.
7. 기록: diff(x86 07 `trap.c` 대비, NeXTMach `next/trap.c` 발췌 대비), PROVENANCE 새 행(일곱 칸, `darwin01+nextmach+authored`), MODIFICATIONS, DECISIONS D144, 계획·HANDOFF·메모리. M7 의무: COMMON 합침(`traceback_jb`·`traceback_recursive`·`traptrace`), locore 표지(`FAULT_ERROR`·`move_space_fault`·`probe_recover`·`fault_error`) 선언.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 636.1 교차검토(codex `gpt-6.1-sol`, task ky8uw0l60) 판정과 계획 수정

먼저 제 잘못이 둘 있습니다. (1) 0 단계 (b) 에서 `TRACE_PENDING` 줄을 지운다고 적었습니다. B3 은 166·565 행에서 이 이름을 쓰고, 스테이지 머리에는 정의가 없습니다(grep 0). 그래서 줄을 남기고 주석만 고칩니다. (2) 4·5 단계의 바탕을 옛 `m0p627-a1-stage` 로 적었습니다. 하지만 `@` 원천은 바탕 매니페스트에 있어야 합니다(`m4_m68k_probe.py:132–134`, `assert vrel(o, v) in have`). §627 도 새 스테이지 `m0p627-a1-stage` 를 썼으므로, 바탕은 3 단계에서 만드는 새 스테이지 `m0p636-a1-stage` 입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `next/trap.h` 18–32·43–48·51–55 행 = B3 의 `T_*` 26 개, 값 같음, 빠진 것 없음 | §636 앞 python 출력(정의 26·사용 26·줄별 값) | ✅ |
| `MC68030` 은 스테이지 `bsd/m68k/cpu.h` 의 `#if KERNEL \|\| STANDALONE` 안에 `0` 으로 있고 명령에 `-DKERNEL` 이 있음 | `cpu.h:45·57–59` 를 엶; `m5-627.cmd` 명령 줄에 `-DKERNEL` | ✅ |
| 상태 기대 4610·71/188·69390·32.14%·86592·42/33/9·미배정 317·320 | §636 앞 python 출력 | ✅ |
| 확인 항목을 분명히 할 것: `__data` 2 바이트 정렬, `trap_type` 항목 6 B(23 × 6 = 138), `__data` 포인터 재배치 22 개가 같은 `__cstring` 내용을 가리킴, 문자열 풀은 원본의 이어진 한 구역이 아니라 내용으로 같음, COMMON 다섯 원본 섹션 6, 미정의 43 개 모두 원본에 있음 | COMMON 다섯은 `symbols.tsv` 에서 유형 `0xf`·섹션 6 확인; `traceback_jb` 104 B(0x40c9900 − 0x40c9898, python); 138 = 표 오프셋(§635.2 python). 재배치 22·미정의 43 은 아직 세지 않음 | ⚖️ 5 단계 확인 기록에 항목으로 넣고 최종 객체에서 python 으로 셈(수는 그때 기록) |
| 바탕은 새 636 스테이지여야 함 | `m4_m68k_probe.py:132–134` 를 엶; §627.2 3·5 단계 | ✅ 고침 |
| `m5-627.cmd` 있음, `compare` 는 `O%d__` 접두와 `EXCEPTS[PLAN]` 을 씀 → 636 명령을 만들어 636 으로 비교; 객체·stderr 같음도 단언 | `ls` 와 `stage_m68k.py:652–653` 을 엶; §627.2 3 단계가 같은 꼴(이전 명령 run + 새 명령 run, 바이트·stderr 같음) | ✅ §627 꼴대로: `m5-627.cmd`(기준 run `m3p636-b627`) + `m5-636.cmd`(run `m3p636-cc1`) |
| `TRACE_PENDING` 은 남기고 1997 값 0x08000000 을 문서로 둘 것 | 위 grep 과 B3:58·166·565 | ✅ 0 단계 고침 |
| B3 머리의 낡은 문구("eight of nine", "trap() follows later")는 바꿀 것 | B3:2–3 을 엶 | ✅ 1 단계 설명 주석이 머리 진단 주석을 대신함 |
| `trap.h`·`pcb.h` 조각의 출처도 기록할 것 | — | ✅ PROVENANCE·MODIFICATIONS 에 `next/trap.h:18–32·43–48·50–55`, `next/pcb.h:53`(이름만) 을 적음 |

고친 단계:
- 0: F1 = B3 에서 (a) 진단 `#define` 덩이를 `next/trap.h` 18–32·43–48·50–55 행 그대로로 바꾸고, (b) `TRACE_PENDING 0x08000000` 줄은 남기며, (c) 진단 `MC68030` 줄을 지운 글입니다.
- 3: 새 스테이지 이름은 `m0p636-a1-stage` 이고, `--plan 627` 재생성 이름은 `m0p627-r636-stage` 입니다. M5 는 `m5-627.cmd`(run `m3p636-b627`)와 `m5-636.cmd`(run `m3p636-cc1`)로 돌립니다. 205 객체 바이트와 stderr 가 같아야 하고, `compare` 결과는 `m3-m68k-p636-compare-20261031.json` 에 남깁니다.
- 4·5: 바탕은 `m0p636-a1-stage` 입니다.

기록 이름(모두 `20261031.json`): `m4-m68k-probe-p636-f1-`·`m4-m68k-funcbytes-p636-F1-`, `m4-m68k-probe-p636-p1-`·`-F/L-`, `m4-m68k-p636-e2-`, `m4-m68k-p636-final-`·`m4-m68k-funcbytes-p636-a1-`, `m4-m68k-p636-checks-`, `m3-m68k-p636-compare-`·`-b627-`, `m4-x86-inputs-p636-`, `m4-m68k-status-p636-`.

### 636.2 결과(2026-10-31)

- 0: 진단 F1(run `m4p636-f1`, `m4-m68k-probe-p636-f1-20261031.json`): 컴파일 종료 0·경고 0·i386 0, `OBJECT_MATCH`·`full_span`, B3 객체와 `canon`·sig 같음, 8/9 + `trap` 바이트 같음(재배치 이름 둘; `m4-m68k-funcbytes-p636-F1-20261031.json`).
- 1·2: 07 `src/machdep/m68k/trap.c`(858 행, SHA `0c158514…`)를 scratchpad `gen_p636.py` 로 F1 에서 만들었습니다(x86 07 `trap.c:1–23·25–34` 고지, 수정 표시 줄, NeXTMach `trap.c:2` 고지, plan 636 설명, 아홉 함수 줄의 출처·원본 주소 표시, extern 줄마다 선언 출처). extern 표시 문구는 스테이지 머리 전수 grep 으로 정했습니다(`thread_halt_self` 는 `kern/thread.h:310`, `num_regions` 는 들어오는 `vm/pmap.h:210` 에도 있음; 나머지는 들어오는 머리에 선언 없음). 주석 뺀 토큰이 F1 과 같고, L(`08_build/artifacts/m4p636/src/trap_L.c`)과 줄마다 같습니다(python). `stage_m68k.py` 730 → 732 행.
- 3: `--plan 627` 재생성(`m0p627-r636-stage`) = 보관본(매니페스트·파일 해시). `m0p636-a1-stage`(976 파일)와 보관 627 의 차이는 새 파일 하나와 키 `files`·`m4_sources`·`plan` 입니다. M5: 새 `m5-627.cmd` 가 §627 것과 `cmp` 같고, `m5-636.cmd` 와는 계획 번호만 다릅니다. run `m3p636-b627`·`m3p636-cc1` 은 205 객체 바이트가 같고 stderr 205 개도 같습니다. `compare`(`m3-m68k-p636-compare-20261031.json`, `-b627-`)의 `differ_unexpected`·`lost` 는 비었고(python 단언), 요약 차이는 `stage_vs_test_stage` 의 새 파일뿐입니다. x86 `m4-x86-inputs-p636-20261031.json` `ok`, `--plan 636 x86gate` 일곱 같음·`v183.34` 0.
- 4: run `m4p636-p1`(`m4-m68k-probe-p636-p1-20261031.json`): F·L 종료 0·경고 0·i386 0·`OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 8/9 + `trap` 바이트 같음(`-F/L-`). F = L(canon·`obj_sig` 모든 칸), L = F1(canon). 처음 단언(F·L 파일 길이 같음)은 실패했습니다. F·L 은 48016·48020 B 로 다르고, 그 차이는 문자열 표뿐입니다. 원천 경로가 23·24 자로 달라 채움이 4 B 바뀐 것으로, §627 에서는 22·23 자라 채움이 같았습니다. 그래서 검사를 고쳐 다시 돌렸습니다. 문자열 표 앞까지의 바이트 차이 1134 개는 `n_strx` 와 기호표 문자열 크기 칸뿐이고, 기호 이름은 경로를 바꿔 넣으면 모두 같습니다(경로를 담은 기호 19). 미리 정한 판정 대상(canon·sig·F1 같음)은 그대로이고, 바이트 분류 방법만 경로 길이에 맞췄습니다. run `m4p636-e2`(`m4-m68k-p636-e2-20261031.json`, `ok`): `-E` 토큰 13578 같음, i386 0, stderr 빔.
- 5: run `m4p636-a1`(`m4-m68k-p636-final-20261031.json`, SHA `4e540401…`): `gate.ok`, 8/9 + `trap` 바이트 같음(`-a1-`). 확인 `m4-m68k-p636-checks-20261031.json`(`ok` 참): 섹션 `__text` 4610·`__data` 170(정렬 2)·`__cstring` 874; `__data` 는 포인터 재배치 22 개 밖의 바이트가 원본과 같고, 22 개 모두 원본 포인터와 같은 문자열을 가리킴; `__cstring` 문자열 37 개 모두 원본 `__cstring` 에 있음(내용으로 셈); `__text` 재배치 150·참조 150; 외부 정의 10 개(함수 9 + `_trap_type`) 원본 자리; 지역 `_exframesize` 하나(`__data`+138); COMMON 다섯(`_traceback_jb` 104, 나머지 4, 모두 원본 섹션 6); 미정의 43 개 모두 원본에 있음; 의존 109 파일 사슬 문제 0·i386 0; 객체 SHA `af63132c…`.
- 6: 근거 `06_reconstruction/evidence/m68k-trap.md`(상태 도구 전), diff `m68k-trap.diff`(x86 07 대비)·`m68k-trap-nextmach.diff`(NeXTMach `trap.c` 발췌, `trap.h`·`pcb.h` 발췌 대비). `ACCEPTED` 한 줄(`m4_m68k_status.py` 177 → 178 행). 상태 도구를 두 번 돌려 같았고, 상태표는 44 → 45 행(더한 것 `trap` 하나)입니다. 요약은 미리 계산한 값과 python 으로 같습니다: 42 객체(OBJECT_MATCH 33, CODE+BSS_INFERRED 9), 덮은 행 71/188, 69390/215874 B(32.14%), `object_bytes` 86592, `rows_unassigned_before` 에 `m68k-317`·`m68k-320` 더함(`m4-m68k-status-p636-20261031.json`).
- 7: PROVENANCE 1190 → 1191 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 726 → 727 행, DECISIONS D144(147 → 148 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D144).
