# 커널 소스 복원 작업계획 — 보관 §740–754

`02_plan/RECONSTRUCTION_PLAN.md` 의 §740–754(m68k M4 `locore.s`(D167·D168); §742–753 의 제목은 `## 계획 N:` 꼴)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-09, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 740. M4-207 조사 계획 — m68k `locore.s`([0x4000310, 0x4002284) 8052 B, 행 001–006)의 경계·자료·NeXTMach 대응과 첫 어셈블 진단 (07 변경 없음; 코딩 전, 2026-11-06)

고른 까닭: 사용자 선택(2026-11-06, AskUserQuestion)으로 남은 일 가운데 `locore.s` 를 합니다. §739 뒤 남은 행은 95 개·최소 80566 B 이고(python: 인벤토리·상태표), `locore.s` 는 정확한 행 004(3656 B)를 포함하며 NeXTMach `next/locore.s`(1985 행)가 참고 글이고 어셈블러 경로(D108; `nextdbgasm.s`·`libc.s`·`monitor.s` 선례)가 이미 있습니다.

사실(python: `06_reconstruction/m68k-functions.tsv`, 인벤토리 `m68k-m4-inventory.tsv`, 원본 `__text` 바이트):
- 단위 후보 [0x4000310, 0x4002284) 8052 B: 행 001–003(`_start` 8 B, `_intstacks` 데이터 표지 4268 B, `x86-intr` 18 B 최소), 행 004(`next/locore.s` 정확, [0x40013d6, 0x400221e) 3656 B), 행 005(`fpsp/skeleton.sa` 2 B, `fpsp_done`), 행 006(미배정, [0x4002220, 0x4002284) 100 B: `fpsp_frame_err`·`trace`·`_cache_push`·`_mon_exit`). 뒤의 `_rpause`(0x4002284, 행 007)는 NeXTMach `bsd/cmu_syscalls.c` 계열의 C 코드이고 `_table`·`_main` 등 BSD 가 이어지므로 단위는 0x4002284 에서 끝납니다(⚠️ 가설; 조사에서 확인).
- `_intstacks`(0x4000318)의 4268 B 는 4096 B 의 0 바이트(`[0x4000318, 0x4001318)`, NeXTMach `_intstack: .skip INTSTACK_SIZE` 와 같은 꼴)와 그 뒤 172 B 의 0 이 아닌 코드(`[0x4001318, 0x40013c4)`, 진입 `entry`)입니다(python: 0 아닌 바이트 151, 첫 0x4001318 마지막 0x40013c3). `_start` 는 `4ef9 04001318`(`jmp 0x4001318`)입니다.
- 함수 표 항목(0x4000310–0x4002284): `_start`, `_intstacks`, `_curipl` 18, `_pflush_super` 30, `_pflush_user` 30, `_tlb_update_read` 46, `_tlb_update_write` 46, `_pmove_crp` 42, `_pmove_tt1` 38, `__move_space` 100, `_move_space_fault` 28, `_cache_push_page` 26, `_cache_inval_page` 38, `_get_vbr` 12, `_set_vbr` 16, `_ALLOW_FAULT_START,_copyoutstr` 72, `_copyinstr` 72, `_copystr` 52, `_copyout,_copyoutmsg` 114, `_copyin,_copyinmsg` 114, `_copywithin` 234, `_FAULT_ERROR` 16, `_ALLOW_FAULT_END,_fast_setjmp` 18, `_setjmp` 16, `_longjmp` 16, `_probe_rb` 42, `_probe_rl` 42, `_simple_lock`·`_simple_lock_init`·`_simple_unlock` 2, `_simple_lock_try` 4, `_ovbcopy` 6, `_blkclr` 10, `__switch_context` 164, `__switch_context_discard` 158, `__switch_context0` 112, `__stack_handoff` 140, `__return_with_state` 22, `__stack_attach` 4, `_call_continuation` 14, `std_trap` 76, `ipl1`…`ipl7` 60·60·112·112·60·108·112, `_call_nmi` 36, `trap3` 170, `trap4` 58, `trap5` 16, `trap6` 16, `addrerr` 116, `buserr` 648, `fpsp_done` 2, `fpsp_frame_err` 18, `trace` 6, `_cache_push` 42, `_mon_exit` 34.
- NeXTMach `locore.s` 의 정의: 같은 이름의 정의가 `PROCENTRY (이름)`·`PROCENTRY(이름)`·`_이름:` 레이블로 있는 것과 없는 것이 섞여 있습니다(예: `PROCENTRY (curipl)` 337, `pflush_super` 355, `pflush_user` 374, `pmove_crp` 433, `pmove_tt1` 456, `move_space` 472, `cache_push_page` 490, `cache_inval_page` 502, `get_vbr` 517, `set_vbr` 521, `copyoutstr` 577, `copyinstr` 599, `copystr` 621, `copyout` 643, `copyin` 682, `copywithin` 726, `probe_rb` 866, `simple_*` 897–909; `_ALLOW_FAULT_START` 575, `_FAULT_ERROR` 824, `_ALLOW_FAULT_END` 833, `_fast_setjmp` 836, `_setjmp` 845, `_longjmp` 853, `_ovbcopy` 919, `_blkclr` 923, `_call_nmi` 1370). 이름이 NeXTMach 에 없는 것: `tlb_update_read`·`tlb_update_write`(NeXTMach 는 `pload_read`·`pload_write` 393·410), `move_space_fault`, `switch_context` 계열(NeXTMach 는 `save_context`·`load_context` 970·1005; Mach 3 continuation 꼴은 Mach4 `i386/kernel/i386/locore.S:591` 에 `call_continuation` 이, `i386/kernel/i386/pcb.c:208` 에 C 함수 `stack_handoff` 가 있어 참고 후보이며 `locore.S` 에는 `stack_handoff` 가 없음), `std_trap`, `probe_rl`, `mon_exit`, `fpsp_*`, `trace`, `rpause` 는 단위 밖. 이 대응은 이름 검색일 뿐이고 바이트 대조 전에는 같은 코드라고 하지 않습니다.
- NeXTMach `locore.s` 의 포함: `cpus.h`·`cputypes.h`·`iplmeas.h`·`eventmeter.h`·`mach_ldebug.h`(07 생성 머리에는 `iplmeas.h`·`eventmeter.h`·`mach_ldebug.h` 가 있고 `cpus.h`·`cputypes.h` 는 없음), `sys/kern_return.h`·`sys/errno.h`·`sys/reboot.h`, `next/cframe.h`·`vm_param.h`·`vmparam.h`·`cpu.h`·`psl.h`·`pcb.h`·`mmu.h`·`trap.h`·`spl.h`(07 `nextmach/next/` 에는 `cframe.h`·`cpu.h`·`mmu.h` 만). 조건부 99 줄(`NCPUS`·`NIPLMEAS`·`GDB`·`D25B`/`D43B`/`D50D`·`PTESTW_BUG`·`DEBUG`·`FIXME`·`MACH_LDEBUG`·`EVENTMETER`). 파일 첫 세 줄은 `#define D25B 1`·`D43B 1`·`D50D 0`.

방법(07 변경 없음; 조사와 첫 진단 계획):
1. 조사(읽기): 원본 [0x4000310, 0x4002284) 를 `m68k-linux-gnu-objdump -D`(`scratch/p688/odis.py` 꼴)로 `scratch/p740/original-objdump.txt` 에 보존하고, 함수마다 진입점·크기·외부 참조·자료 참조(`__data`·`__bss`·`__common` 주소)를 python 으로 모읍니다. 원본은 링크된 이미지이고 `__text` 에 재배치 레코드가 없으므로(`macho.json:87–88` 의 `relocation_offset`·`relocation_count` 0) 목표 이름은 "명령 피연산자 주소를 원본 심볼표(`symbols.tsv`)에 대응시킨 이름"과 "후보 객체의 재배치 이름"으로 구분해 적습니다. NeXTMach 와 짝이 있는 함수는 어셈블 뒤 바이트 대조로 가립니다.
2. 첫 어셈블 진단 A0: NeXTMach `next/locore.s` 를 그대로(조건부 값은 NCPUS 1·NIPLMEAS 0·EVENTMETER 0·DEBUG 없음, `D25B`·`D43B` 는 파일 값, `GDB` 는 생성 머리 `gdb.h` 의 1 그대로: 원본 `_curipl` 은 `link a6,#0`·`unlk a6` 가 있음) 어셈블해 보는 것이 목적입니다. NeXTMach 의 실제 조립 입력은 `assym.s`·`next/locore.s`·`next/scb.s` 를 이어 붙인 `locore.c`(`conf/Makefile.NeXT:59,64`)에 `cc -E -DLOCORE`(`conf/Makefile.template:338`)를 거친 것이므로, `next/locore.s` 자체에는 `assym` 포함이 없고 `THREAD_PCB`·`FPC_INT`·`R_SR` 같은 상수는 `next/genassym.c`(149·110·71 행)가 만듭니다. A0 는 `assym.s` 를 먼저 공급합니다: `genassym.c` 의 상수 80 개 가운데 `locore.s` 가 쓰는 것을 모아 1997 구조체 배치(07 `pcb.c`·`thread.h` 등)로 만든 진단용 `assym.s`(상수 값은 C 컴파일 결과 객체에서 python 으로 읽음)를 변형 `inc` 에 넣고, `scb.s` 는 A0 입력에서 제외하고(원본 [0x4000310, 0x4002284) 에 벡터표가 없는지 조사에서 확인) 뒤에 따로 판단합니다. 필요한 머리(`cpus.h`·`cputypes.h` 생성 머리, `next/pcb.h`·`psl.h`·`trap.h`·`vm_param.h`·`vmparam.h`·`spl.h`·`sys/kern_return.h` 등)는 NeXTMach 사본을 변형 `inc` 로 넣어 시험하고(공유 07 머리는 바꾸지 않음; 새 사본이 필요하면 구현 계획에서 D104 방식으로 정함), `next/cpu.h` 는 어셈블리 전용이라 쓸 수 있습니다(PROVENANCE `1114`). 컴파일 줄은 `nextdbgasm.s` 와 같은 틀(x86 `machdep/i386/start.s` 줄에 §429 치환과 `-DASSEMBLER`)입니다. 어셈블이 되면 객체 `__text` 와 원본 [0x4000310, 0x4002284) 를 `scratch/p730/cmpmove.py` 꼴(역어셈블 뒤 절대 주소 정규화, 별칭·표지 경계에 무관한 단위 전체 비교)로 비교하고, `m68k_funcbytes.py` 는 별칭이 없는 함수에만 보조로 씁니다(별칭 `_simple_lock`·`_simple_lock_init`·`_simple_unlock` 은 원본 표에서 2 B 한 구간이지만 도구는 객체 쪽을 0·0·2 B 로 나눠 길이 불일치로 처리하므로 같음·다름 판정에 쓰지 않음), 안 되면 오류(없는 머리·매크로)를 하나씩 기록합니다.
3. 판정(미리 정함): 이 계획은 조사이며 수락이 아닙니다. A0 가 어셈블되지 않으면 필요한 머리 목록과 오류를 보고하고 다음 계획을 세웁니다. 기준을 낮추지 않습니다. 구현 단계(07 `locore.s`)는 A0·A1… 로 바이트가 맞은 뒤 사용자 결정(이름·형·조건부 값·새 머리 사본)을 여쭙고 따로 계획합니다.

위험(미리 적음): (가) 1997 판이 Mach 3 continuation 으로 바뀌어 `switch_context` 계열은 NeXTMach 와 크게 다를 것(새 코드는 원본 바이트에서 어셈블리로 씀). (나) `_intstacks` 는 `.skip` 4096 B 와 `entry` 172 B 이고 어셈블러가 0 바이트를 같은 방식으로 냄을 확인해야 합니다. (다) 구조체 오프셋(`pcb`·`thread`)은 NeXTMach `genassym.c` 로 생성되므로 값을 python 으로 원본 바이트와 대조해야 합니다. (라) 행 005·006 의 `fpsp_*`·`trace` 는 FPSP 와의 경계라 단위 끝이 맞는지 따로 확인.

### 740.1 §740 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 계획 2387 행의 Mach4 `stack_handoff` 를 `locore.S` 에 있는 것처럼 적었습니다(실제는 `pcb.c:208` 의 C 함수이고 `locore.S` 에는 없음). (2) A0 의 `GDB 0` 은 원본과 맞지 않는 값이었습니다(원본 `_curipl` 은 `link`·`unlk` 를 가짐). (3) `assym.s` 를 어떻게 공급하는지 빠뜨렸습니다. (4) 별칭 경계에서 `m68k_funcbytes.py` 가 길이 불일치를 내는 것을 계획하지 않았습니다. (5) 재배치 이름과 심볼표 대응 이름의 증거 구분이 없었습니다. (6) codex 에 보낸 검사 요청에 `_start` 길이를 4 바이트라고 적은 것은 틀렸습니다(`jmp` 는 6 바이트이고 `_start` 구간 8 B 는 뒤 2 B 가 0 인 채움; 계획 본문은 8 B 로 맞게 적혀 있음).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Mach4 `locore.S:591` 에 `call_continuation`, `stack_handoff` 는 `pcb.c:208`; `locore.S` 에는 없음 | `grep -n call_continuation .../i386/locore.S` → 591 한 줄, `grep -c stack_handoff .../locore.S` → 0, `grep -rn stack_handoff` 의 i386 결과 → `pcb.c:203,208` | ✅ 본문 고침 |
| `m4_m68k_probe.py:222–224` 가 변형 `inc` 를 기존 `-I` 뒤에 넣음; 생성 `gdb.h` 는 `#define GDB 1` | 파일 210–232 행을 열어 `k = max(...-I...)`, `w.insert(k + 1, ...)` 확인; `cat 07_kernel/v183.34/m68k/generated/gdb.h` → `#define GDB 1`; `08_build/runs/tools/m0p739-a1-stage` 에도 `gdb.h` 있음 | ✅ `GDB` 는 1 그대로 |
| `cframe.h` 진입은 `defined(GDB)`(65–69), 종료는 `#if GDB`(72–79) 라 `GDB 0` 정의는 `link` 만 내고 `unlk` 를 뺌 | `cframe.h` 59–82 행을 열음: 65 `#if !defined(GPROF) && defined(GDB)`, 72 `#if GDB` | ✅ |
| 원본 [0x40013c4, 0x40013d6) 18 B 가 `4e560000 … 4e5e 4e75` | python 으로 `__text` 에서 읽음: `4e56000040c0e0880280000000074e5e4e75`, 앞 `4e560000`, 끝 `4e75` | ✅ |
| `image.txt:1067`·`:1071` 의 `linkw a6,#0x0`·`unlk a6` | `03_original/m68k/inventory/` 에는 `image.txt` 없음; `08_build/artifacts/m0p414/otool-V1/image.txt`·`otool-V10/image.txt` 의 1067·1071 행이 `040013c4 linkw a6,#0x0`·`040013d2 unlk a6` 로 열림(어느 이미지의 `otool` 인지는 열어 확인하지 않음) | ⚠️ 줄 인용은 사실이나 대상 이미지를 확인하지 않아 쓰지 않음(바이트 대조는 위 python 행을 근거로 함) |
| `assym.s` 공급 단계 누락; 조립 입력은 `assym.s`+`locore.s`+`scb.s`(`Makefile.NeXT:59,64`, `Makefile.template:338,339`) | 각 줄을 열음: 59 `LOCORE_DEPS= assym.s ../next/locore.s ../next/scb.s`, 64 `cat ${LOCORE_DEPS} >locore.tmp`, 338 `${CC} -E -DLOCORE -I../machine ${SFLAGS} locore.c`, 339 `${AS} ...`; `grep -n assym next/locore.s` → 0 줄 | ✅ 본문 고침(A0 에 진단용 `assym.s` 공급 단계) |
| `genassym.c` 가 `THREAD_PCB` 149, `FPC_INT` 110, `R_SR` 71 행 | `grep -n 'THREAD_PCB\|FPC_INT\|R_SR' next/genassym.c` → 71·110·149 | ✅ |
| `m68k_funcbytes.py` 가 별칭을 구간으로 나누고 원본 쪽은 첫 이름만(115·148–153·187–189) | 파일 100–200 행을 열음(`n.split(',')[0]`, `tsyms` 로 `end = tsyms[i+1][0]`, `if oe - v != e - a: rows.append(row); continue`); python 시뮬레이션: `_simple_lock` 0, `_simple_lock_init` 0, `_simple_unlock` 2 B 대 원본 0x40018c2–c4 2 B; TSV 30 행 `_simple_lock,_simple_lock_init,_simple_unlock` 2 B | ✅ 본문 고침(단위 전체 비교 사용) |
| `macho.json:87–88` 에 `relocation_offset` 0·`relocation_count` 0 | `macho.json` 83–90 행을 열음(87·88 행이 두 키) | ✅ 본문 고침(증거 구분) |
| `_start` 바이트열은 6 바이트 `4ef904001318` | python `rd(0x4000310,0x4000316)` → 6 B `4ef904001318`; `_start` 8 B 는 `4ef9040013180000` | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄이거나 제가 돌린 python·명령 출력입니다. `image.txt` 인용은 대상 이미지를 확인하지 못해 ⚠️ 로 남겼고 본문에 쓰지 않았습니다.

### 740.2 결과: 첫 어셈블 진단 A0/A0b 와 NeXTMach `locore.s` 대응 조사 (수락 아님; 07 변경 없음; 2026-11-06)

실행(모두 새 소문자 ID; 스테이지·기록은 `08_build/runs/` 아래, 명세는 `08_build/artifacts/m4p740/`; 진단 입력은 `scratch/p740/`):
- 원본 [0x4000310, 0x4002284) 역어셈블 `scratch/p740/original-objdump.txt`(`_start` 8 B, 0 영역 표지, [0x4001318, 0x4002284) 를 따로 역어셈블해 명령 경계를 맞춤; 명령 1083 줄, `.short` 7 개는 objdump 가 해석하지 못한 MMU 명령 `f039`·`f010`·`f028` 계열과 `040b`).
- `m4p740-p1`(A0: NeXTMach `next/locore.s` 그대로, 변형 `inc` 에 NeXTMach 머리 13 개 `next/{cframe,fpc,mmu,pcb,pmap,psl,reg,spl,trap,vm_param,vmparam}.h`·`sys/kern_return.h`·`machine/kern_return.h`): 머리 오류는 없고 어셈블러 오류만 났습니다 — `assym` 상수가 정의되지 않아 `_cnt+V_SWTCH`·`VM_PROT_READ+VM_PROT_WRITE` 등에서 "Can't relocate expression", 그리고 `INTRARG(ipl1, _softint_run, #0, softint_rtn)`(1361·1362 행)에서 "Missing operand". 객체는 만들어지지 않았습니다(상태 `00 1`).
- `m4p740-e1`(-E, `-traditional-cpp` 있음·없음 두 가지): 두 출력이 같고(`cmp` 같음, 30504 B) `ipl1` 확장에 `movl      ,sp@-` 가 있어, 이 cc 의 cpp 는 매크로 인자 `#0` 를 비웁니다. 본문 안 `\#` 는 `#` 가 되지만 인자의 `#0`·`\#0` 는 안 됩니다(`m4p740-p2` "Ignoring junk after expression", `-p3` 에서 `IMM0` 매크로 우회도 빈 인자).
- `m4p740-p4`(A0b: 진단용 입력 `scratch/p740/locore_A0b.s` = 자리표시 `assym` 73 상수(python: `genassym.c` 의 `printf("#define\t이름` 73 개, 중복 없음; 값은 비트 번호·`VM_PROT_*`·`AST_ZILCH` 만 NeXTMach 마스크에서 계산하고 나머지는 지어낸 값) + NeXTMach `locore.s`, 1361·1362 행의 인자만 `IMM0`·`IMM1`(= 0·1)로 바꿈): 어셈블되고 경고 0, 객체 `__text` 8682 B(원본 단위 8052 B), 객체 `__data` 148 B.

대조(`scratch/p740/cmp_a0b.py`; 원본 함수 58 항목을 객체의 같은 이름 심볼 구간과 견줌, "정규화"는 역어셈블에서 절대 주소·`#상수`·`(변위)` 를 가림; 객체 쪽 끝은 다음 원본 함수 이름이 객체에 있을 때만 믿을 수 있음; python 집계):
- 바이트가 같음 8 항목 138 B: `_curipl`, `_get_vbr`, `_copystr`, `_ALLOW_FAULT_END,_fast_setjmp`, `_setjmp`, `_longjmp`, `_simple_lock,_simple_lock_init,_simple_unlock`, `_simple_lock_try`.
- 크기가 같고 정규화하면 같음 12 항목 826 B: `_pflush_super`, `_pmove_crp`, `_cache_push_page`, `_cache_inval_page`, `_ALLOW_FAULT_START,_copyoutstr`, `_copyinstr`, `_copyout,_copyoutmsg`, `_copyin,_copyinmsg`, `_copywithin`, `_probe_rb`, `_ovbcopy`, `_call_nmi`. (정규화 같음은 자리표시 상수와 재배치 값에 대한 것이므로 바이트 같음이 아닙니다.)
- 객체에 같은 이름이 없음 18 항목 5316 B: `_intstacks`(4268 B)와 `_tlb_update_read`·`_tlb_update_write`·`__move_space`·`_move_space_fault`·`_probe_rl`·`__switch_context`·`__switch_context_discard`·`__switch_context0`·`__stack_handoff`·`__return_with_state`·`__stack_attach`·`_call_continuation`·`std_trap`·`fpsp_done`·`fpsp_frame_err`·`_cache_push`·`_mon_exit`(1048 B). 객체에는 `_move_space`·`_pload_read`·`_pload_write`·`_save_context`·`_load_context` 처럼 이름이 다른 NeXTMach 함수가 있으나 같은 코드인지는 따지지 않았습니다.
- 다름·끝을 믿을 수 없음 20 항목 1772 B: 합 138 + 826 + 5316 + 1772 = 8052 B. 이 가운데 `ipl1`–`ipl7`·`trap3`–`trap6`·`addrerr`·`buserr` 는 같은 이름이 있는데 다릅니다. 예: 원본 `ipl1` 은 `oriw #1792,%sr`·`lea %sp@(56),%fp`·`cmpal #0x4001318,%sp`(= `_eintstack` 가 `_intstacks` 의 4096 B 뒤 0x4001318)·`andiw #-3585,%sr`·`movel #0,%sp@-`·`jsr 0x4094080`·`addql #4,%sp`·`bral 0x40021d2` 인데 NeXTMach 확장은 `clrw`·`moveml`·`addl #1,a6` 꼴이어서 구조가 다릅니다(1985 판 대 1997 판).

읽는 법과 한계: (1) 위의 "같음"은 NeXTMach 텍스트가 그 구간 바이트를 낼 수 있다는 뜻이고 원본 소스가 그것이라는 증거는 아닙니다. (2) 자리표시 `assym` 때문에 구조체 변위·크기를 쓰는 함수(`trap3`·`buserr`·`__switch_context` 계열 등)는 이 단계에서 판정하지 않았습니다. 실제 `assym` 값은 1997 구조체 배치(07 `thread.h` 의 `struct pcb` 등)와 원본 바이트로 정하고 따로 계획합니다. (3) `_start` 는 NeXTMach 와 다르고(원본 `jmp` + 0 영역 + `entry` 172 B), `entry` 는 [0x4001318, 0x40013c4) 입니다. (4) `-O` 없이 `-g -O2` 줄이 쓰이지만 어셈블리 입력이므로 객체 코드에는 영향이 없다고 보이나 확인하지 않았습니다. (5) `scb.s` 는 A0·A0b 입력에서 제외했고 원본 단위 안 벡터표 여부는 아직 확인하지 않았습니다.

판정(미리 정한 것): 이 계획은 조사이며 수락이 아닙니다. 07 은 바뀌지 않았고 상태표·출처표도 그대로입니다. 구현 단계(07 `locore.s`)는 아래 결정이 필요해 따로 계획합니다: (가) `assym` 상수의 원천(1997 구조체 배치와 원본 바이트로 도출하는 방법), (나) 이름이 NeXTMach 와 다른 함수(`tlb_update_*`·`move_space` 계열·`switch_context` 계열·`std_trap` 등)의 새 어셈블리, (다) `INTRARG` 의 `#` 인자 문제를 어떻게 쓸지(원본 `ipl1` 이 NeXTMach 확장과 구조부터 다르므로 새 형), (라) `fpsp_*`·`trace`·`_cache_push`·`_mon_exit` 와 FPSP 경계.

## 741. M4-208 조사 계획 — `locore.s` 의 `assym` 상수 73 개가 1997 판에서 갖는 값(두 방법의 교차; 07 변경 없음; 코딩 전, 2026-11-06)

고른 까닭: §740.2 의 남은 결정 (가)입니다. §740.2 의 A0b 는 자리표시 상수로 어셈블했기 때문에 `assym` 상수를 쓰는 함수(`trap3`–`trap6`·`addrerr`·`buserr`·`save_context`·`load_context` 등)의 변위·크기를 판정하지 못했습니다("다름·끝 불확실" 20 항목 1772 B 안에는 `assym` 을 쓰지 않는 코드 구조 차이도 섞여 있음: 예 `_FAULT_ERROR`). 실제 값을 알면 같은 진단을 다시 돌려 NeXTMach 와 원본의 차이를 상수 때문인 것과 코드 구조 때문인 것으로 가릅니다. 이 계획은 조사이며 수락이 아닙니다.

사실(python: `01_resources/upstream/nextmach/mk-108.1/next/genassym.c` 의 `printf("#define\t이름 %d\n", 식)` 파싱, `scratch/p741/assym_list.tsv`): 상수 73 개(중복 없음), 그 가운데 `locore.s` 본문에 낱말로 나오는 것 54 개(주석 안의 낱말도 세므로 상한)이고 나머지 19 개는 안 나옵니다. 식 종류: 구조체 필드 주소(`&r->r_sp` 꼴), `sizeof(struct …)`, `bitnum(마스크)`, 상수 그대로(`VM_PROT_READ`·`AST_ZILCH` 등). 식이 같은 쌍이 셋 있습니다: `REGS`·`R_D0`(`&r->r_dreg[0]`, 67·68 행), `FMT`·`VOR`(`((int)&r->r_pc) + sizeof(int)`, 73·74 행), `FLAGS`·`AST`(`&pcb->pcb_flags`, 103·104 행). 끝의 `asm("\tU_ARG = %d")` 는 156 행에서 `uthread->uu_arg`(배열이므로 첫 원소 주소로 바뀜; `sys/user.h` 의 `int uu_arg[8]`)를 값으로 넘깁니다. 14 개는 `bitnum(마스크)`(런타임 함수 호출, 161–169 행)입니다. python 집계: 필드 주소 45·`bitnum` 14·`sizeof` 8·상수 6. 1997 쪽 자료: `m68k/reg.h`·`psl.h`·`mmu.h`·`cpu.h`·`vmparam.h` 가 스테이지(`m0p739-a1-stage`, `src/bsd/m68k/`)에 있고, 07 `v183.34/m68k/src/machdep/m68k/thread.h` 에 1997 `struct pcb`(`saved_regs` +0x048, `thread_user_reg` +0x050, `pcb_flags` +0x054, `mmu_tt1` +0x058, `pcb_fpc_i` +0x05c, `pcb_fpc_e` +0x134; 주석에 적힌 값이고 컴파일로 아직 확인하지 않음)가 있습니다.

방법(07 변경 없음; 이 절의 첫 판이 M2 를 "원본 바이트에서 값을 되돌리는 것"으로 쓴 것은 틀렸습니다 — §741.1 참조. M2 는 값을 도출하지 않고 M1 값을 원본 바이트로 검증하는 것으로 바꿉니다):
- M1 1997 머리 컴파일(값의 원천): `genassym.c` 의 식을 상수마다 진단 C 파일 한 개(`ga_이름.c`, 변형 하나씩)로 만들어 전역 `int ga_이름 = (int)(식);` 로 컴파일하고 객체 `__data` 에서 값을 python 으로 읽습니다. 원문의 `r`·`pcb` 등은 `main` 안의 지역 변수이므로 전역 초기화에서는 쓸 수 없고, 널 포인터 리터럴 형 `&((struct regs *)0)->r_sp`(및 `longbus`·`access` 보조 구조체는 원문과 같은 정의를 파일에 둠)으로 바꿉니다 — 이 형은 기존 기록(`08_build/runs/m0p412-abi1/src/c_layout.c` 의 `KR_OFF`)에서 같은 cc 가 `__data` 의 값으로 낸 증거가 있습니다. `bitnum(마스크)` 14 개는 전역 초기화가 안 되므로 마스크를 `int ga_이름_MASK = (int)(마스크);` 로 읽고 비트 번호는 원문 `bitnum` 과 같은 계산(가장 낮은 켜진 비트; 마스크 0 이면 원문 함수는 값 없이 끝나므로 0 인 마스크는 "미해결")을 python 으로 합니다. `sizeof(int)` 가 4 인지도 같은 파일로 확인합니다. 식 변환(원문 식 → 진단 식)은 python 으로 하고 상수별 대응을 `scratch/p741/ga_map.tsv` 에 남깁니다. `U_ARG` 는 원문 식 `uthread->uu_arg` 의 배열→포인터 변환을 보존해 `(int)((struct uthread *)0)->uu_arg` 로 시험합니다. 컴파일 줄은 §740 에서 `-DASSEMBLER` 를 뺀 것(C 용; `-g -O2 -c`)으로 하며 `-DASSEMBLER` 를 넣지 않습니다. 머리 집합은 `m68k/reg.h`·`psl.h`·`sys/proc.h`·`sys/vmmeter.h`·`sys/user.h`·`kern/thread.h`(07 `struct pcb`) 등 스테이지에서 찾는 것이고, 첫 실행은 머리만 포함한 파일 하나로 어떤 머리가 컴파일되는지 봅니다. 머리나 필드가 없는 상수는 지어내지 않고 "미해결"로 적습니다: 지금 확인된 것은 `FSIZE`(`&r->r_fsize`; 1997 `m68k/reg.h` 에 `r_fsize` 없음, `grep -an fsize` 결과 없음, NeXTMach `next/reg.h:191` 은 `r_fsize` 를 `r_evec.e_fsize` 별칭으로 가짐)입니다.
- M2 원본 바이트 검증: M1 로 얻은 값으로 A0c(= A0b 에서 자리표시를 M1 값으로 교체; `bitnum` 상수·`VM_PROT_*`·`AST_ZILCH` 도 M1 값; 미해결 상수는 자리표시로 남기고 표시)를 어셈블하고, 함수별로 **명령별 주소 모드·인코딩 길이·재배치/주소 대상**까지 맞추어 원본 [0x4000310, 0x4002284) 와 견줍니다(§740 의 "명령 수 같음·정규화 같음" 만으로는 부족: 그 정규화는 숫자·주소를 모두 가려 피연산자 의미를 검사하지 않습니다). 상수를 쓰는 함수가 이 비교에서 원본과 바이트가 같으면(재배치 값 제외) 그 함수가 쓰는 상수는 "원본 바이트로 검증됨", 같은 구조인데 변위만 다르면 그 자리를 기록하고 M1 값과 충돌하는 것으로 보고, 어느 함수와도 대응이 없는 상수는 "M1 만"으로 표시합니다. §740.2 의 일치 20 항목에는 `assym` 상수가 하나도 없어 검증 대상이 되지 못합니다(python: 항목별 본문 줄 범위에서 이름 0 개).
- 산출: `scratch/p741/assym_values.tsv`(이름·식·M1 값·검증 함수·판정)와 §741.2 결과 표, A0c 대조의 항목 분류 변화.

미리 정한 판정: M2 가 M1 값과 충돌하는 상수는 충돌로 보고하고 값을 채택하지 않습니다(M1 만 있는 값은 "검증 안 됨"으로 표시하며, 검증된 것처럼 쓰지 않습니다). 기준을 낮추지 않습니다. 이 조사의 값은 진단용이며 07 `locore.s` 의 상수 처리 방식(생성 머리 `assym.h`, D104 사본 등)은 구현 계획에서 사용자에게 여쭙습니다.

위험(미리 적음): (가) 1997 `struct user`·`utask`·`uthread`·`thread` 가 NeXTMach 와 달라 `U_*`·`UTHREAD`·`UTASK`·`THREAD_*` 식이 컴파일되지 않을 수 있음(상수별 따로 컴파일해 격리). (나) `assym` 상수를 쓰는 함수가 NeXTMach 와 구조부터 다르면(`trap3`·`buserr`·`switch_context` 계열 등) A0c 에서도 대응이 안 되어 M2 검증이 비는 상수가 많을 수 있음 — 그 경우 값은 "M1 만"이고 구조 재작성(구현 계획)에서 원본 바이트로 확인합니다. (다) 숫자 검색으로 피연산자의 출처를 되돌리지 않습니다: `R_D0` 의 자리표시 20 은 `addl #20,sp`(1458 행)의 글자 그대로의 20 과 겹쳤습니다. 출처는 소스 식·매크로 확장과 명령 위치로 연결합니다. 피연산자가 상수 단독이 아닌 경우(`_cnt+V_SWTCH` 심볼 가산값, `SSW+1`, `FAULTD_BIT-8`)도 구분합니다. (라) 자리표시 값은 56 개의 일반 상수에서만 유일하고(python: 충돌 없음) 비트·`VM_PROT_*` 에서 4 쌍(`FAULTD_BIT`·`RW_BIT` 8, `FAULTC_BIT`·`SR_TSINGLE_BIT` 15, `TRACE_AST_BIT`·`VM_PROT_WRITE` 2, `TRACE_USER_BIT`·`VM_PROT_READ` 1)이 겹칩니다 — A0c 는 자리표시를 쓰지 않으므로 영향이 없습니다. (마) 같은 식 쌍 `REGS`·`R_D0`, `FMT`·`VOR`, `FLAGS`·`AST` 는 값만으로 구분되지 않아 같은 값으로 적고 쓰임새는 소스에서 구분합니다. (바) 값이 127 을 넘는지가 모든 명령 길이를 바꾸는 것은 아닙니다(`An@(변위)` 는 워드 변위; 즉치는 명령 크기 지정자가 정함) — 길이는 명령별로 확인합니다.

### 741.1 §741 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) M2 의 전제가 틀렸습니다 — §740.2 의 일치 20 항목에는 `assym` 상수가 하나도 없어 거기서 값을 되돌릴 수 없고, 상수를 쓰는 함수는 NeXTMach 와 구조가 달라 일치 항목이 아니었습니다. (2) 같은 식 쌍에서 `REGS`·`R_D0` 를 빠뜨렸습니다. (3) `U_ARG` 의 원문 식에 없는 `&` 를 붙여 적었습니다(원문 `uthread->uu_arg`, 배열). (4) M1 의 "기계적 `int ga = 식`" 은 지역 변수 `r`·`pcb` 와 런타임 함수 `bitnum()` 때문에 그대로는 되지 않습니다. (5) 20 항목 1772 B 를 모두 상수 문제로 설명했으나 `_FAULT_ERROR` 처럼 `assym` 없는 구조 차이가 섞여 있습니다. (6) 1997 `reg.h` 에 없는 `r_fsize`(`FSIZE`)를 위험에 적지 않았습니다. (7) "명령 수 같음·정규화 같음" 을 검증 기준으로 썼으나 정규화가 숫자·주소를 모두 가려 부족합니다. (8) C 용 컴파일 줄에 `-DASSEMBLER` 를 쓰지 말아야 하는 점을 적지 않았습니다. 본문은 모두 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상수 73·중복 없음·`locore.s` 낱말 54 | python 으로 `printf("#define\t이름 %d\n", 식)` 파싱: `73 73 54` | ✅ |
| 같은 식 쌍은 `FMT/VOR`, `FLAGS/AST` 와 `REGS/R_D0` | python 식 묶음 출력 `[['REGS','R_D0'],['FMT','VOR'],['FLAGS','AST']]`; `genassym.c` 67·68·73·74·103·104 행을 열음 | ✅ 본문 고침 |
| `U_ARG` 원문 식은 `uthread->uu_arg`, 배열 | `genassym.c:156` 열음; `grep -an uu_arg` → NeXTMach `sys/user.h:67` 와 스테이지 `sys/user.h:70` 모두 `int uu_arg[8]` | ✅ 본문 고침 |
| 스테이지 `m68k/{reg,psl,mmu,cpu,vmparam}.h` 있음 | `ls` 에서 `cpu.h mmu.h psl.h reg.h vmparam.h` 확인(앞서 제가 `ls` 로도 확인) | ✅ |
| 07 `thread.h` 의 `struct pcb` 오프셋 주석 | 앞서 `sed -n 40,140p` 로 열어 `+0x048`·`+0x050`·`+0x054`·`+0x058`·`+0x05c`·`+0x134` 확인(codex 의 행번호 71–83 은 열어 대조하지 않고 쓰지 않음) | ✅ (주석 값이며 컴파일 확인 전) |
| 1997 `reg.h` 에 `r_fsize` 없음 | `grep -an fsize .../m68k/reg.h` → 출력 없음·종료 1; `grep -an e_fsize` 도 출력 없음; NeXTMach `next/reg.h:189–191` 열음(`#define r_fsize r_evec.e_fsize`) | ✅ 본문 고침 |
| `reg.h` 의 나머지 이름(`excp_*`·`SS_*`·`r_dreg`·`r_sp`·`r_sr`·`r_pc`·`e_ss`·`e_faultaddr`·`e_stagebaddr`·`SR_*`)은 있음 | 제가 `grep -al` 로 각 이름을 검색해 `reg.h`(`SR_*` 는 `psl.h`)에서 찾음 | ✅ |
| 자리표시 값은 일반 56 개에서 유일, 4 쌍 겹침 | python 은 `distinct values 69`, 충돌 4 쌍(`FAULTD_BIT/RW_BIT 8`, `FAULTC_BIT/SR_TSINGLE_BIT 15`, `TRACE_AST_BIT/VM_PROT_WRITE 2`, `TRACE_USER_BIT/VM_PROT_READ 1`) | ✅ (56 은 codex 집계; 73 − 14 − 3 = 56 으로 python 계산 일치) |
| M2 일치 항목에 `assym` 이름이 없음 | python 으로 `locore_A0b.s` 의 항목별 본문(주석 제거)에서 상수 이름 검색: 19 개 레이블 모두 `[]`, `_simple_lock` 묶음(`locore_A0b.s:962–966`)도 `[]` 로 따로 확인해 20 항목 전부 0 개 | ✅ 본문 고침(M2 재설계) |
| `R_D0 20` 과 `addl #20,sp` 가 겹침 | `locore_A0b.s` 6 행 `#define R_D0 20`, 1458 행 `addl #20,sp` 를 열음 | ✅ |
| `_FAULT_ERROR` 는 `assym` 없는 구조 차이 | `cmp_a0b.out:24` `SIZE 16 vs 12; insn 6 vs 6`; 원본 역어셈블 `movel 0x40ad96c,%d0; unlk; rts; clrl %d0; unlk; rts` 16 B; `locore_A0b.s:901–904` `_FAULT_ERROR: movl #EFAULT,d0; PROCEXIT` | ✅ 본문 고침 |
| `bitnum` 은 런타임 함수라 전역 초기화 불가, 14 개 | `genassym.c:161–169` 열음(`for … return (i)`); python 14 개 | ✅ 본문 고침 |
| 지역 `r`·`pcb` 는 전역에서 쓸 수 없고 널 리터럴 형이 같은 cc 에서 값으로 나온 선례가 있음 | `genassym.c:41–61` 은 `main` 안 선언; `08_build/runs/m0p412-abi1/src/c_layout.c:8` `KR_OFF`; python 으로 `out/m68k_O_c_layout.o` `__data` 읽음 `(1263684697,1,2,4,4,4,4,8)`, 재배치 0 | ✅ 본문 고침 |
| `scratch/p725/gccsrc` 의 "initializer element is not constant" 는 NeXT 수정판 증거가 아님 | 후보 글이라는 점은 이미 계획에 적혀 있음; 이 결론에 쓰지 않음 | ⏭️ (사실 주장 없음) |
| 일반 `An@(변위)` 는 127 초과해도 길이가 늘지 않음; 길이는 명령별로 확인 | codex 의 Capstone 출력은 열어 재현하지 않았고, `qemu disas/m68k.c` 줄도 대조하지 않음. 본문에는 "값이 127 을 넘는지가 모든 길이를 바꾸는 것은 아님"만 쓰고 명령별 확인을 조건으로 둠 | ⚖️ 조건만 채택(수치 주장은 쓰지 않음) |
| 정규화(`cmp_a0b.py:25`)가 숫자·주소·`<…>` 를 모두 가림 | 제가 `cmp_a0b.py` 의 `norm` 함수(0x…, `#숫자`, `(변위)`, `<…>` 치환)를 앞서 작성·열었음 | ✅ 본문 고침 |
| C 용 컴파일 줄에는 `-DASSEMBLER` 를 쓰지 말 것 | `spec_a0b.cmd` 에 `-DASSEMBLER` 가 있음을 §740 에서 확인; C 변형은 `defs` 없이 둠 | ✅ 본문 고침 |

2 차 자기검사: ✅ 행은 이번 세션에 제가 연 줄이거나 돌린 python·명령 출력입니다. ⚖️ 행은 codex 의 수치(Capstone 출력)를 열지 않았으므로 본문에 쓰지 않았습니다.

### 741.2 결과: `assym` 상수의 1997 값(M1)과 원본 바이트 대조(M2) (수락 아님; 07 변경 없음; 2026-11-06)

실행(새 소문자 ID; 명세·진단 입력 `08_build/artifacts/m4p741/`, 도구·표 `scratch/p741/`):
- `m4p741-p1`: 머리만 넣은 G0 에서 `vm/vm_prot.h` 가 없음(1997 은 `mach/vm_prot.h`). `-p2`: 머리 집합(`sys/types.h`·`sys/param.h`·`sys/buf.h`·`sys/vmmeter.h`·`sys/user.h`·`sys/proc.h`·`kern/task.h`·`kern/thread.h`·`sys/mbuf.h`·`sys/msgbuf.h`·`mach/vm_prot.h`·`m68k/reg.h`·`m68k/psl.h`)이 오류 없이 컴파일되고 `sizeof(int)` 4·`sizeof(struct regs)` 72·`sizeof(struct pcb)` 416(07 `thread.h` 머리 주석의 416 B 와 같음).
- `m4p741-p3`: 상수마다 한 파일(74 개 = `genassym.c` 73 + `asm` 줄의 `U_ARG`; `bitnum` 14 개는 마스크만 컴파일하고 비트 번호는 python 으로 계산; 원문의 지역 변수는 널 포인터 리터럴로 바꿈; 변환 대응 `scratch/p741/ga_map.tsv`) 148 명령(컴파일 74 + `-M` 74) 중 실패한 것은 컴파일 7 개. 객체 67 개의 `__data` 값을 python 으로 읽어 `scratch/p741/assym_values.tsv` 에 기록. 주요 값: `R_SP` 60, `R_SR` 64, `R_PC` 66, `FMT` 70, `SSW` 74, `SSW_040` 76, `FAULTADDR` 80, `TT1` 88, `FPC_INT` 92, `FPC_REGS` 308, `FPC_EXT` 404, `SAVED_REGS` 72, `THREAD_USER_REG` 80, `SIZEOF_PCB` 416, `THREAD_PCB` 36, `THREAD_RECOVER` 112, `THREAD_AST` 372, `SIZEOF_NORMAL6` 4·`SIZEOF_SHORTBUS` 24·`SIZEOF_LONGBUS` 84·`SIZEOF_ACCESS` 52.
- 미해결 7 개(머리·필드 없음): `FSIZE`(`structure has no member named r_fsize`), `PCB_TT1`·`AST_SCHED_BIT`·`TRACE_AST_BIT`·`TRACE_USER_BIT`(`PCB_TT1`·`AST_SCHEDULE`·`TRACE_AST`·`TRACE_USER` 마스크가 1997 머리에 없음), `UTHREAD`·`UTASK`(`struct thread` 에 `u_address` 없음). `locore.s` 가 쓰는 것은 `PCB_TT1` 을 뺀 6 개입니다.
- `m4p741-p4`(A0c: A0b 에서 자리표시를 M1 값 66 개로 교체, 위 6 개는 자리표시 유지): 어셈블 오류·경고 0. 엄격 대조(`scratch/p741/cmp_strict.py`: 함수 구간의 원본 바이트와 객체 바이트를 재배치 자리만 가리고 비교): A0b·A0c 모두 같음 23 항목 1020 B·객체에 같은 이름 없음 18·다름 17 — M1 값으로 바꿔도 같은 항목이 늘지 않았습니다. 즉 `assym` 을 쓰는 함수가 다른 이유는 상수보다 코드 구조입니다.

M2(원본 바이트 검증; `scratch/p741/m2.py`: 원본 [0x4001318, 0x4002284) 1050 명령과 A0c 객체 1243 명령을 숫자를 가린 꼴로 정렬해 모양이 같은 쌍 765, 그 가운데 숫자까지 같은 쌍 743, 다른 쌍 22 — 다른 쌍은 아래 사실): 
- 값을 직접 확인한 자리(원본 역어셈블 `scratch/p740/original-objdump.txt`): `ipl1` 의 `movel %a0,%sp@(60)`(`R_SP` 60); `_call_nmi` 의 `movew %a2@(64),%d0`·`movel %a2@(66),%sp@-`(`R_SR` 64·`R_PC` 66; NeXTMach 는 `IRSO` 가 `(16*4+4)`(`locore_A0b.s:1199–1200`)라 68·70 이고 원본은 `IRSO` 가 `16*4` 에 해당하므로 A0b 의 `_call_nmi` 는 2 바이트만 다름); `trap5`·`trap6` 의 `moveal %a0@(36),%a0`·`movel %a0@(80),%d0`(`THREAD_PCB` 36·`THREAD_USER_REG` 80; 앞 부분은 구조가 다름: NeXTMach 는 `active_threads` 배열을 `d0` 로 색인하고 원본은 `_active_threads` 한 칸 0x40b5648); `addrerr` 의 `bfextu %sp@(70),0,4,%d0`(`FMT` 70, 포맷 필드).
- 값만으로 짝지은 집계(값 16 이상, 숫자가 같은 자리): `R_SP` 15·`R_SR` 6·`R_PC` 2·`SSW` 7·`SSW_040` 5·`TT1` 2·`FPC_INT` 4·`FPC_REGS` 2·`FPC_EXT` 2·`THREAD_USER_REG` 3 등 18 개 상수가 "M1 값과 원본 숫자가 같은 자리 있음, 어긋남 0"(값이 같은 다른 상수와 구별되지 않는 것도 있음: `SSW_040`↔`FAULTADDR`/`THREAD_USER_REG`, `FAULTADDR_040`·`FLAGS`·`AST`·`SIZEOF_LONGBUS` 84 등 — 이 집계는 값의 일치이지 출처의 증명이 아닙니다). 어긋남이 섞인 것: `FMT`·`VOR`(70; 일치 4·어긋남 5 — 어긋난 자리는 `IRSO+2` 쪽이라 상수 자체의 충돌이 아님), `THREAD_PCB`(일치 3·어긋남 1: 원본 0x4002190 `moveal %a2@(60),%a0` 대 객체 `moveal %a0@(36),%a0` 로 `buserr` 안의 구조 차이).
- 자리가 없는 상수(`locore.s` 에서 쓰이고 값 16 이상, 원본과 정렬된 자리 없음): `FAKE_SIZE` 72·`SIZEOF_ACCESS` 52·`SIZEOF_PCB` 416·`SAVED_REGS` 72·`THREAD_RECOVER` 112·`THREAD_AST` 372 — "M1 만". 값이 16 미만인 21 개(`REGS`·`V_*`·비트 번호·`VM_PROT_*` 등)도 값으로 짝지을 수 없어 "M1 만". 분류 집계(python, `assym_values.tsv` 74 행): M1 만 27(미해결 6 포함하지 않음), `locore.s` 에서 쓰지 않음 20, M1 + 원본 숫자 18, 미해결 6, 섞임 3.
- `FSIZE`: 1997 `reg.h` 에 `r_fsize` 가 없고 원본 `addrerr` 에는 프레임 크기를 쓰는 `movw #…,sp@(…)` 가 없습니다(위 역어셈블에서 확인; 단위 전체에서 없다는 뜻은 아님).

한계: (1) 값만으로 상수를 짝지은 것은 출처의 증명이 아닙니다. (2) M1 은 1997 머리(참고 글)의 값이므로 원본에서 확인된 것과 확인되지 않은 것을 `assym_values.tsv` 의 `evidence` 칸에 구분해 두었습니다. (3) 미해결 6 개와 "M1 만" 은 구조 재작성 때 원본 바이트로 정해야 합니다. (4) 07 `locore.s` 의 상수 처리(생성 머리·사본)는 아직 정하지 않았습니다.

판정(미리 정한 기준대로): M2 가 M1 값과 충돌하는 상수는 없었습니다(`FMT`·`THREAD_PCB` 의 어긋남은 구조 차이이며 값 충돌이 아님을 위에서 확인). 이 계획은 조사이며 수락이 아닙니다. 구현 계획에서 사용자에게 여쭐 것: (가) `assym` 상수를 생성 머리로 둘지 `locore.s` 안 `#define` 으로 둘지, (나) 미해결 6 개의 이름·값(원본 바이트 우선), (다) §740.2 의 (나)·(다)·(라).

## 계획 742: m68k `locore` 단위의 자료(`.data`)와 `_scb` 조사 (조사·진단만; 07 변경 없음; 2026-11-06)

고른 까닭: 사용자 지시(2026-11-06, 같은 지시 반복)로 §741 뒤 남은 일 가운데 사용자 결정이 필요 없는 항목인 `scb.s`·벡터 표 확인을 합니다. §740·§741 은 단위의 `__text` 만 봤고, NeXTMach 의 조립 입력(`assym.s`+`locore.s`+`scb.s`)에는 `.data` 도 들어 있으므로 원본 자료 쪽을 확인합니다.

사실(원본 바이트·인벤토리를 직접 열어 얻음; python 은 `scratch/p742/scb_orig.py` 등):
- 원본 `_scb`(심볼표 `symbols.tsv` 2493 행, `0x40ada14`)는 `__data` 안 288 B(벡터 72 개)입니다. 근거: 바이트 [0x40ada14+0x120, …) 는 표가 아닌 자료(`0x4`, `0x12`, `0x80000`, …)이고, `0x40adb34` 는 코드가 `movel 0x40adb34,%fp@(-128)`(0x40027a2)·`cmpl 0x40adb34,%d3`(0x4095332)로 따로 읽는 변수이며 원본 심볼 `_dk_ndrive` 입니다. (`m68k-data-map.tsv` 의 `next_first` 는 상한이고 앞 구간 소유자는 `unmapped#287` 이므로 "다음 객체 시작"의 증거로 쓰지 않습니다.) 앞 쪽 [0x40ad964, 0x40ada14) 176 B 가 `locore` 자료의 나머지이므로 `locore.o` 의 `.data` 는 [0x40ad964, 0x40adb34) 464 B 로 추정합니다(⚠️ 객체 경계는 추정: `__data` 시작 = 첫 객체, 끝 = 다음 심볼 `_dk_ndrive`; 구간 안 자료는 `locore` 함수가 참조하는 항목과 전역 변수로 다른 객체도 쓰는 항목이며 이를 뒤집는 증거는 못 찾았으나 단일 객체임이 증명된 것은 아님).
- 원본 심볼표: `_cache` 0x40ad964, `_fpu_version` 0x40ad968, `_fault_error` 0x40ad96c, `_probe_recover` 0x40ad970, `_scb` 0x40ada14(전부 전역). 값: `_cache` 0, `_fpu_version` 1, `_fault_error` 0, `_probe_recover` 0.
- 그 뒤: 0x40ad974 부터 8 개 4 바이트 주소 [0x4001e78, …, 0x4001e6a](2 씩 감소; NeXTMach `argc_table` 의 `argc_0`..`argc_7`; 명령 `0x4001e56 lea 0x40ad974,%a1` 이 참조), 0x40ad994 `"addrerr: bad exception stack format"`(36 B), 0x40ad9b8 `"buserr: bad exception stack format"`(35 B), 패딩 1 B(0x40ad9db), 0x40ad9dc `"buserr: no fault indicated"`(27 B), 패딩 1 B, 0x40ad9f8 2 B 0(`mmu_status`; 명령 `0x4002132 pmove %psr,0x40ad9f8`·`0x400213a bfffo 0x40ad9f8,…` 이 참조), 0x40ad9fa `"fpsp: frame format error"`(25 B; `0x4002220 pea 0x40ad9fa`(`fpsp_frame_err`)이 참조; 문자열 길이는 종료 NUL 포함), 패딩 1 B, 0x40ada14 `_scb`.
- 이름이 있는 항목의 NeXTMach 대응: `_cache`(locore.s:106)·`_fpu_version`(185)·`_probe_recover`(862)·`argc_table`(1429)·문자열 3 개(1683·1705·1713)·`mmu_status`(1821) 가 있고, `fault_error` 는 NeXTMach `locore.s` 에 없습니다(원본 `_FAULT_ERROR` 가 `movel 0x40ad96c,%d0` 로 읽음; 07 `trap.c:171` 이 `extern int fault_error` 로 이미 선언). NeXTMach 의 `global_lock`(527 행 라벨, 528 행 `.byte 0`)은 원본 자료 [0x40ad964, 0x40ada14) 안에서 들어갈 자리가 없습니다(변수 4 개가 4 B 씩 이어지고 패딩은 문자열 뒤 3 곳뿐; 이름 없는 2 B 변수가 구간 밖에 있을 가능성까지 배제한 것은 아님). `fpsp: frame format error` 문자열은 NeXTMach `next/*.s`·`fpsp/*.sa` 에서 찾지 못했습니다(검색: `grep -rnai 'frame format' next/*.s next/*.c`; `fpsp/*.sa` 의 `frame format|frame_err` 도 출력 없음).
- `_scb` 항목(python: 72 개를 심볼표·함수 표로 대응): `std_trap` 49 개(0x000·0x004·0x010–0x028·0x030–0x060·0x080·0x084·0x09c–0x0bc·0x0e0–0x11c), `buserr`(0x008)·`addrerr`(0x00c)·`ipl1`–`ipl7`(0x064–0x07c)·`trap3`–`trap6`(0x08c–0x098), `fline`(0x02c, 0x40a0c94, FPSP 쪽 `m68k-347`), 0x088 = 0x400225a(심볼 없음; `jsr _cache_push; rte` 8 B(`jsr` 6 B + `rte` 2 B), 함수 표에서는 `_cache_push` 구간에 포함), FPSP 쪽 `bsun`·`inex`·`dz`·`unfl`·`operr`·`ovfl`·`snan`·`unsupp`(0x0c0–0x0dc). NeXTMach `scb.s` 는 256 항목이고 각 벡터마다 다른 이름(`STRAY`·`BADTRAP`·`KS(illegal)` …)과 `fpsp_bsun`·`real_inex`·`real_dz`·`fpsp_*` 이름을 씁니다.
- 실행 중 쓰기(역어셈블 `0x4094b24..0x4094b44` 확인): `bsrl 0x400157e` 가 돌려준 포인터(`%a0`; 출처 함수는 확인하지 않음)가 가리키는 두 값을 `_scb` 앞 두 항목(0x40ada14·0x40ada18)에 쓰고, `%a0@(180)` 을 0x40b57c8 에 저장한 뒤 `_scb+0xb4`(0x40adac8)에 0x4002262(`_mon_exit`)를 씁니다. 곧 디스크 이미지의 이 항목들 값은 링크 시점 값이며 실행 중 값이 아닙니다.

방법(07 변경 없음):
1. 진단 D0: `scratch/p742/locore_D0.s`(+ 명세 `08_build/artifacts/m4p742/spec_d0.json`)를 §741 과 같은 방식(`x86_rel` `machdep/i386/start.s`, 변형 이름 `D0`, `-DASSEMBLER`)으로 m68k VM 의 cc 로 어셈블합니다. 내용은 위 사실대로 `.data`(`_cache`·`_fpu_version`·`_fault_error`·`_probe_recover`·`argc_table`·문자열 3 개·`mmu_status`·`fpsp` 문자열·`_scb` 72 항목)이며, 핸들러 이름은 원본 심볼 이름을 정의 없이 씁니다(재배치 레코드로 이름이 남게). 실행 대상(`.text`)은 `argc_0`..`argc_7` 이 같은 객체에서 정의되도록 2 바이트 `nop` 8 개만 둡니다(자료 배치 진단용이며 코드가 아님).
2. 판정 기준(미리 정함; 낮추지 않음): (가) `__data` 크기 464 B. (나) 재배치 위치를 가린 바이트가 원본 [0x40ad964, 0x40adb34)과 같음. (다) 재배치가 있는 위치 = 원본에서 코드/FPSP 주소를 가진 포인터 위치 80 개(`argc` 8 + `_scb` 72; python 이 센 값이며 원본 `__data` 의 재배치 레코드는 0 개)와 정확히 같고, 각 재배치는 4 B 절대(pc 상대 아님)이며 가산값은 외부 이름 0·`argc_i` 는 (원본 값 − 0x4001e6a) 와 같음(가산값 오류를 거르기 위함). (라) 객체의 전역 심볼 5 개(`_cache`·`_fpu_version`·`_fault_error`·`_probe_recover`·`_scb`)의 `__data` 안 오프셋이 원본 값 − 0x40ad964 (0·4·8·12·0xb0). (마) `_scb` 재배치 이름이 python 이 심볼표에서 얻은 이름과 같고 72 항목이 위치별로 일치함(0x088 은 원본에 심볼이 없으므로 NeXTMach 이름 `trap2` 를 쓰되 "이름 미확인" 으로 표시). (바) `argc_0`..`argc_7` 이 항목 0..7 순서로 2 B 씩 감소하는 오프셋(`.text` 안 7·6·…·0 번째 2 B 칸)을 가리킴.
3. 한계(미리 적음): 객체 경계(464 B)는 추정입니다. 이 진단은 자료 배치만 보며 07 의 `locore.s`(텍스트)와 합쳐진 배치는 구현 단계에서 확인합니다. NeXTMach `scb.s` 는 참고 글이고 원본과 항목 수·이름이 달라 그대로 쓸 수 없습니다(결정 필요: 새 `scb` 표를 07 의 어느 파일에 두는지).

위험(미리 적음): (가) 객체 경계 오판 → `__data` 순서(전역 심볼 5 개 + `m68k-data-map.tsv`)로만 뒷받침. (나) `.even` 패딩 위치가 원본(0x40ad9db, 0x40ad9f7, 0x40ada13)과 어셈블러 출력이 다를 수 있음 → 기준 (나)가 잡음. (다) cc 의 어셈블러가 `.long 이름` 재배치를 외부 심볼로 남기지 않고 구간 상대로 바꿀 수 있음(정의된 이름만) → 핸들러는 정의 없는 이름만 써서 피하고, 같은 객체에서 정의하는 `argc_0`..`argc_7` 은 구간 상대 재배치와 가산값을 기준 (다)·(바)로 검사합니다(여전히 남는 위험).

### 742.1 §742 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) `0x088` 대상 `jsr _cache_push; rte` 를 6 B 로 적었습니다(실제 8 B). (2) NeXTMach 줄번호 4 곳이 한 줄씩 어긋났습니다(`global_lock` 527/528, `argc_table` 1429, 세 번째 문자열 1713, `mmu_status` 1821). (3) 코드 참조 주소를 명령 시작이 아니라 피연산자 위치로 적었습니다. (4) 판정 기준이 가산값·재배치 종류·`argc` 를 거르지 못했습니다. (5) "다음 객체 시작"은 `next_first` 가 상한이라 증거가 아닙니다. (6) `global_lock` 부재를 단정하는 투로 적었습니다. 이 가운데 `global_lock` 관련 문장은 처음 쓴 본문에 근거 없는 줄이 있어 제가 삭제했습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 288 B·72 항목·`std_trap` 49 개·묶음 6 개 | python: 72 항목 읽어 `49 [('0x0','0x4'),('0x10','0x28'),('0x30','0x60'),('0x80','0x84'),('0x9c','0xbc'),('0xe0','0x11c')]` | ✅ |
| 0x088 대상 8 B | `original-objdump.txt`: `400225a jsr 0x4002238`(6 B), `4002260 rte`(2 B); python `6+2` | ✅ 본문 고침 |
| 자료 배치·문자열 길이 36/35/27/25·패딩 주소 | python 으로 원본을 읽고 단언: `0x40ad9db`·`0x40ad9f7`·`0x40ada13` 패딩, `0x40ada14` `_scb`, 구간 464/176/288 | ✅ |
| 코드 참조는 명령 시작이 아님 | `original-objdump.txt` 에서 `4001e56 lea`·`4001f8a pea`·`4001fd0 pea`·`4001fdc pea`·`4002132 pmove`·`400213a bfffo`·`4002220 pea`·`400182c movel` 열음 | ✅ 본문 고침 |
| NeXTMach 줄번호 | `sed -n` 으로 106·185·527·528·862·1429·1683·1705·1713·1821 열음 | ✅ 본문 고침 |
| `fault_error`·`frame format` 부재 | `grep -anF fault_error locore.s` 종료 1; `grep -aniE 'frame format|frame_err' next/*.s next/*.c fpsp/*.sa` 종료 1 | ✅ |
| `global_lock` 부재 단정은 증명 아님 | 원본 자료에서 변수 4 개가 4 B 간격으로 이어지고 패딩은 문자열 뒤뿐임을 확인했으나 구간 밖은 보지 않음 | ⚖️ 본문을 "자리가 없음"으로 약화 |
| 판정 기준이 약함(가산값·`argc`·재배치 종류) | `.long std_trap+2` 가 같은 위치·이름이면 통과함을 논리로 확인 | ✅ 기준 (다)·(마)·(바) 보강 |
| 원본 `__data` 재배치 레코드 0 | `macho.json` 의 `__data` 재배치 개수 확인은 앞서 §740 에서 `__text` 만 했음 | ✅ (python: `macho.json` 의 `__data` `relocation_offset` 0·`relocation_count` 0, 모든 구간 0) |
| 단일 `locore.o` 귀속은 추정 | 구간 안 참조의 함수 소유 python 집계(`vars` 는 여러 객체, `argc`·문자열은 `locore` 함수, `scb` 는 `_m68k_init`) | ✅ 추정으로 표시 |

2 차 자기검사: 위 ✅ 행은 모두 이번 세션에 제가 연 파일·돌린 python 출력입니다.

### 742.2 결과: `locore` 자료 배치 진단 D0 (수락 아님; 07 변경 없음; 2026-11-06)

실행: `m4p742-p1`(명세 `08_build/artifacts/m4p742/spec_d0.json`, 소스 `scratch/p742/locore_D0.s` 66 행, 변형 `D0`; 첫 시도는 명세의 `inc` 키 누락으로 stage 단계에서 단언 실패(`inc: []` 로 고침)). 어셈블 오류·경고 0(종료 코드 `00 0`·`01 0`). 검사 도구 `scratch/p742/check_d0.py`(§742 의 미리 정한 기준을 그대로 구현):
- (가) `__data` 464 B 통과. (나) 재배치 위치를 가린 바이트가 원본 [0x40ad964, 0x40adb34) 와 같음(통과). (다) 재배치 80 개가 포인터 위치 80 개(argc 16–44, `_scb` 176–460)와 정확히 같고 모두 4 B 절대·pc 상대 아님·type 0(통과); 원본의 나머지 4 B 정렬 낱말 중 주소 범위 [0x4000310, 0x40b317c) 안의 값은 없음(통과). (라) 전역 자료 심볼 5 개 오프셋 0/4/8/12/176 통과. (마) `_scb` 72 재배치가 모두 외부 이름이고 이름이 원본 심볼표와 같으며 가산값 0(통과; 0x088 은 원본에 심볼이 없어 `trap2` 이름은 "미확인"). (바) `argc` 8 개는 `.text` 상대 재배치이고 가산값이 원본 값 − 0x4001e6a 와 같음(통과).
- 부정 대조: 객체의 문자열 1 바이트와 `_scb` 항목 0 의 가산값을 바꾼 사본은 (나)·(마)에서 실패함(검사가 실제로 거름).

판정(미리 정한 기준대로): 모두 통과. 곧 원본 `locore` 자료 배치는 다음 꼴의 어셈블리로 재현됩니다: `.data`에 `_cache`·`_fpu_version`(1)·`_fault_error`·`_probe_recover`·`argc_table`(`argc_0`..`argc_7`)·문자열 3 개와 `.even`·`mmu_status`(`.word 0`)·`fpsp` 문자열·`.even`·`_scb` 72 항목(대부분 `std_trap`). 한계: 이는 자료 배치만이며 단일 `locore.o` 귀속과 07 `locore.s` 텍스트와 합친 배치는 구현 단계에서 확인합니다. 새 `_scb` 표는 NeXTMach `scb.s`(256 항목·다른 이름)와 달라 새로 써야 하고, 쓰는 파일 위치는 사용자 결정 대상입니다. 07·상태표·출처표는 바뀌지 않았고 커밋하지 않았습니다.


## 계획 743: m68k `locore` 미해결 상수 6 개(`FSIZE`·`AST_SCHED_BIT`·`TRACE_AST_BIT`·`TRACE_USER_BIT`·`UTHREAD`·`UTASK`)를 원본 바이트로 정하기 (조사·진단만; 07 변경 없음; 2026-11-06)

고른 까닭: 사용자 결정 D167 ①이 "미해결 상수는 원본 바이트로 정한다"이므로 구현 전에 값(또는 "원본 단위에 쓰는 자리 없음")을 확정합니다. 사용자 지시(같은 지시 반복).

사실(python `scratch/p742/scan743b.py` 로 원본 [0x4000310, 0x4002284) 를 `m68k-linux-gnu-objdump -D -b binary -m m68k:68030` 으로 다시 역어셈블한 `scratch/p742/dis_68030.txt` 의 0x4001318 이후 행 1042 개를 훑음(행 수이며 명령 수가 아님: 데이터 표가 명령처럼 나오는 행이 섞임); 기본 `-m m68k` 와도 비교; 함수 소속은 `m68k-functions.tsv` 구간):
- 오프셋 84(`pcb_flags`) 비트 연산 8 곳: `bclr #6`·`bset #6` 쌍이 `__switch_context`(0x40018dc·0x40018ec)·`__switch_context_discard`(0x4001980·0x4001990)·`__stack_handoff`(0x4001a8e·0x4001a9e) 에, `btst #4,%a0@(84)` 가 `trap3`(0x4001e8c)·`buserr`(0x40021e8) 에 있습니다. `bset`/`bclr` 로 비트 2·3(`TRACE_*` 꼴)을 다루는 곳은 없습니다.
- `movew #imm,%sp@(d)`(NeXTMach 의 `FSIZE` 쓰는 꼴): 0 곳. 오프셋 372(`THREAD_AST`): 0 곳.
- 07 `v183.34/m68k/src/machdep/m68k/ast.h:14–15` 는 `0x10000000` 을 `aston`/`astoff` 로 두고(원본 바이트 기반이라는 머리 주석), `trap.c:122` 의 `TRACE_PENDING` 은 `0x08000000`(비트 3), `pmap.c:351` `PCB_TT1` 은 `0x80000000`(비트 7)입니다. `pcb_flags` 는 32 비트 `int`(`thread.h:76`)이고 원본 오프셋 84 의 첫 바이트가 최상위 바이트이므로 `btst #4` = `0x10000000` 입니다(python 으로 `1<<28 == 0x10000000` 확인 예정).
- `trap3` 끝(0x4001e82–0x4001eb4)의 체인: `%a1`=`0x40b5648` 에서 읽은 스레드, `moveal %a1@(36),%a0`(THREAD_PCB), `btst #4,%a0@(84)`, `moveal %a1@(12),%a1`, `moveal %a1@(48),%a1`, `moveal %a1@(0),%a1`, `tstb %a1@(23)`(P_CURSIG), `tstl %a1@(24)`(P_SIG). NeXTMach(`locore.s:1476–1477`)는 `movl a1@(UTASK),a1; movl a1@(U_PROCP),a1`(`a1` 에서 `UTASK` 까지 한 번, 그 위로 `U_PROCP` 한 번 = 두 번 역참조)이고 1997 은 `a1`(스레드)에서 `task`·`u_address`·`uu_procp` 세 번 역참조하는 꼴입니다. 체인 끝에서 `btst #4` 가 참이면 건너뛰지 않고 `jsr 0x409a2fe`(원본 심볼 `_check_for_ast`)를 부릅니다.
- 1997 머리(스테이지 `kern/thread.h`·`kern/task.h`): `thread.h:99` `task_t task`, `thread.h:171` `struct uthread *_uthread`, `task.h:96` `struct utask *u_address`, `task.h:97` `struct proc *proc`. `assym_values.tsv`: `U_PROCP`=0(`utask->uu_procp`), `THREAD_PCB`=36.

가설과 방법(07 변경 없음):
- H1: 원본 `%a1@(12)` = `thread->task`, `%a1@(48)` = `task->u_address`, `%a1@(0)` = `utask->uu_procp`(`U_PROCP`). 진단 M1(§741 기법: 널 포인터 리터럴 오프셋을 전역 초기화로 두고 객체 `__data` 에서 읽음): 변형 H1 `thread->task`, H2 `task->u_address`, H3 `thread->_uthread`(참고), 대조 H4 `thread->pcb`(기대 36). 소스 `08_build/artifacts/m4p743/src/`, 명세 `spec_h.json`, 실행 `scratch/p737/run.sh m4p743-p1`.
- H2: `AST_SCHED_BIT` = 4(원본 `btst #4`가 유일한 AST 시험이며 `ast.h` 의 `0x10000000` 과 일치).
- H3: `TRACE_AST_BIT`·`TRACE_USER_BIT`·`FSIZE`·`UTHREAD` 는 이 단위의 원본 바이트에 쓰는 자리가 없습니다(위 python 전수의 범위: 오프셋 84 비트 연산·`movew #imm,%sp@(d)`·스레드 필드 오프셋). `UTHREAD` 는 H3 진단으로 얻은 `thread->_uthread` 값이 원본 단위의 어떤 `%aN@(d)` 와도 같은 자리가 있는지 python 으로 한 번 더 봅니다.
- 판정 기준(미리 정함; 낮추지 않음): H1 은 `thread->task`·`task->u_address` 의 M1 값이 12·48 이고 앞서 §741 에서 얻은 `U_PROCP`(0)·`P_CURSIG`(23)·`P_SIG`(24)가 원본 체인과 같을 때만 "값이 맞음"(생성 머리 조건 `MACH_FIXPRI` 1·`MACH_SLOCKS` 0 은 스테이지에서 확인해 적음); 하나라도 다르면 H1 기각. H2 는 `btst #4` 두 곳과 `1<<28`(python)이 모두 `0x10000000` 일 때. H3 는 "자리 없음"이 python 전수에서 0 건으로 나올 때만(자리가 있으면 기각하고 따로 조사). 값이 정해져도 이름은 NeXTMach 의 상수 이름이 아니라 "원본 바이트가 정한 값 + 이 프로젝트의 이름"(D167)이며 증거 종류(바이트 일치 / 1997 머리 / 추정)를 표에 적습니다.

한계·위험(미리 적음): (가) 값이 같다는 것은 출처의 증명이 아니다(같은 값을 가진 다른 필드). (나) "자리 없음"은 이 단위 텍스트에 한정되며 07 에 쓸 코드가 그 상수를 쓰지 않는다는 보장이 아니다(NeXTMach 와 구조가 달라 쓰지 않는 것으로 읽힘). (다) 1997 머리는 후보 글이다.

### 743.1 §743 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 계획의 "1051 명령 전수"는 행 수였고, 기존 `original-objdump.txt` 는 일부 명령이 데이터와 섞여 나뉨(새 `-m m68k:68030` 덤프로 다시 훑음; 결과는 같음). (2) NeXTMach 체인을 "한 번 읽기"라 적었으나 두 번 역참조입니다. (3) H1 기준에 `uu_procp`·`p_cursig`·`p_sig` 와 생성 머리 조건이 빠졌습니다. (4) "FSIZE 에 해당하는 동작 없음"은 메모리 기록에 한한 말이며, 프레임 크기를 쓰는 동작(`0x40021a8–0x40021bc` 의 `%d0` 만큼 프레임을 옮김)은 있습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 오프셋 84 비트 연산 8 곳과 함수 소속 | python `scan743b.py`(68030·기본 두 디코더 모두 `bitop @(84)` 8 곳 같은 주소·명령); 소속은 앞서 python 으로 `__switch_context`·`_discard`·`__stack_handoff`·`trap3`·`buserr` | ✅ |
| `0x4001fea moveal %sp@(84),%a0` 는 PCB 접근 아님 | 새 덤프 `any 84 disp` 9 행에 포함, `original-objdump.txt:965` 근처에서 예외 스택 읽기(`7408 moveq #8,%d2` 다음)임을 열음 | ✅ (임의 별칭 부재까지는 단정 안 함) |
| `movew #imm,%sp@(d)`·스택에 대한 `clr` 0 곳 | `scan743b.py`: `movew/b/l #imm -> sp disp/ind` 는 `movel #n,%sp@-`(푸시) 4 곳뿐, `clr to sp` 0 | ✅ |
| 프레임 크기 사용은 있음 | `original-objdump.txt:1076–1086` 열음(`addal %d0,%a0`·`clrw %a0@(70)`); `trap.c:508` `return (rerun ? exframesize[r->r_format] : 0)` 와 `trap.c:160` 표 열음 | ✅ 본문 고침 |
| 체인 12·48·0·23·24 가 1997 머리 배치와 일치 | codex 의 계산은 열지 않음; §741 M1 값 `U_PROCP` 0·`P_CURSIG` 23·`P_SIG` 24(`assym_values.tsv`)는 컴파일로 얻음; 12·48 은 `m4p743-p1` H1·H2 로 측정(12·48) | ✅ |
| 조건에 따라 오프셋이 달라질 수 있음(lock·`NeXT`·`ibmrt`) | 스테이지 `generated/mach_fixpri.h` 가 `MACH_FIXPRI 1`; 스테이지 `generated` 에 `slock` 이름의 머리는 0 개; 오프셋은 실제 머리로 측정한 값(12·48·128·36)이 원본 피연산자와 같음 | ⚖️ 조건별 값 차이는 위험으로 남기고, 측정값이 원본과 같다는 것만 확정 |
| `1<<28 == 0x10000000` | python 출력 `True 0x10000000` | ✅ |
| NeXTMach 체인은 두 번 역참조 | `locore.s:1474–1478` 열음 | ✅ 본문 고침 |
| `UTHREAD`(`thread->_uthread`)=128 이고 원본에 `@(128)` 없음 | `scan743b.py`: `any @(128)` 0 (두 디코더); H3 측정값 128 | ✅ |
| `thread.h:99/171`·`task.h:96/97` 줄번호와 값 | 앞서 grep 으로 열음 | ✅ |
| H2·H3 기준이 약함 | `btst #4` 뒤에 `jsr 0x409a2fe`(`_check_for_ast`)가 이어짐을 함수 표·심볼표로 확인(`symbols.tsv` 317 행) | ✅ 증거 보강 |

2 차 자기검사: ✅ 행은 이번 세션에 연 파일·돌린 python 출력입니다.

### 743.2 결과: 미해결 상수 6 개와 새로 드러난 상수 (수락 아님; 07 변경 없음; 2026-11-06)

실행 `m4p743-p1`(명세 `08_build/artifacts/m4p743/spec_h.json`, 변형 H1–H4; 오류·경고 0, 종료 코드 모두 0; 값은 객체 `__data` 4 B, 재배치 0). 측정: `thread->task` 12(H1), `task->u_address` 48(H2), `thread->_uthread` 128(H3), 대조 `thread->pcb` 36(H4; 기대 36 통과).

| 상수 | 결과 | 증거 종류 |
|---|---|---|
| `AST_SCHED_BIT` | 4 (`btst #4,%a0@(84)` 2 곳: `trap3` 0x4001e8c·`buserr` 0x40021e8; `1<<28 == 0x10000000`) | 바이트 + 문맥(뒤에 `jsr _check_for_ast`) + 07 `ast.h:14–15` 의 `0x10000000` |
| `TRACE_AST_BIT`·`TRACE_USER_BIT` | 원본 단위에 쓰는 자리 없음(오프셋 84 비트 연산 8 곳은 비트 6 과 비트 4 뿐) → 07 `locore.s` 에 정의하지 않음 | python 전수(범위 한정) |
| `FSIZE` | 쓰는 자리 없음(스택에 대한 즉시값 `move`·`clr` 0 곳); 프레임 크기는 C 쪽 `exframesize`(07 `trap.c:160,508`)가 `%d0` 로 돌려주고 `0x40021a8–0x40021bc` 가 그만큼 옮김 | 바이트 + 07 `trap.c` |
| `UTHREAD` | 1997 값은 128(참고 정보); 원본 단위에 `%aN@(128)` 없음 → 정의하지 않음 | 측정 + python 전수 |
| `UTASK` | NeXTMach 식 한 상수가 아니라 1997 은 `THREAD_TASK` 12 → `TASK_U_ADDRESS` 48 → `U_PROCP` 0 로 세 번 역참조(`trap3` 0x4001e94·0x4001e98·0x4001e9c) | 바이트 + 측정 |

새로 드러난 `locore` 용 값(NeXTMach `assym` 에 없음): `THREAD_TASK` 12, `TASK_U_ADDRESS` 48(두 이름은 이 프로젝트의 것), `pcb_flags` 비트 6(`0x40000000`; `__switch_context`·`_discard`·`__stack_handoff` 가 `fsave` 뒤 상태 있음 표시로 `bclr`·`bset` — 의미는 `fsave` 표시 앞뒤 문맥에서 읽은 추정이며 이름은 구현 단계에서 사용자에게 여쭙기 전 가칭).

판정(미리 정한 기준대로): H1 통과(12·48 측정 + 앞서 얻은 0·23·24), H2 통과, H3 통과(범위: 이 단위의 `@(84)` 비트 연산·스택 즉시값·`@(128)`·`@(372)`). 한계: 값이 같다는 것은 출처의 증명이 아니고, 이름은 모두 이 프로젝트의 것입니다. 이 계획은 조사이며 07·상태표·출처표는 바뀌지 않았고 커밋하지 않았습니다.


## 계획 744: m68k `locore.s` 구현 1단계 — 후보 소스 생성기·자료 블록·소형 함수 6 개 (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: 사용자 결정 D167(① `assym` 은 `locore.s` 맨 위 `#define`, ② `_scb` 는 `locore.s` `.data` 끝, ③ `INTRARG` 의 `#` 인자는 `IMM0`/`IMM1` 류 이름)과 §743 의 상수 결과가 있으므로 구현에 들어갑니다. 단위가 8052 B 에 새로 써야 할 코드가 약 2936 B 라 한 번에 쓰지 않고 단계로 나눕니다(방법은 §737–739 `nextdbg.c` 와 같게: NeXTMach `next/locore.s` 를 바탕으로 원본 바이트가 정한 부분만 표시 구간으로 바꿈, D013·D024).

사실(python·원본·기존 객체; 객체는 §741 A0c `m4p741-p4`):
- 엄격 대조(`scratch/p741/cmp_strict.py`)로 58 항목 중 23 개(1020 B)가 NeXTMach 그대로 같고, 18 개(5316 B)는 A0c 객체에 같은 이름이 없으며(`NO-OBJ-NAME`; 예: 원본 `__move_space` 는 NeXTMach `_move_space`, 원본 `_tlb_update_*` 는 NeXTMach `pload_*` 와 이름만 다를 뿐 짝이 없다는 뜻은 아님) 17 개(1716 B)가 다릅니다. 새로 써야 할 바이트 합: 항목 크기 python 합 2936 B(`_intstacks` 의 4096 B 0 은 제외, `entry` 172 B 는 포함).
- 다른 17 개 가운데 소형 6 개의 차이(A0c 객체와 원본 역어셈블 비교): `_call_nmi` 는 `IRSO` 뿐(원본 `movew %a2@(64)`·`movel %a2@(66)`, NeXTMach `IRSO+0`·`IRSO+2` 로 A0c 에서는 68·70; 곧 원본 `IRSO` = `16*4`); `_FAULT_ERROR` 는 원본 `movel 0x40ad96c,%d0`(`_fault_error`) 로 시작하는 16 B 이고 NeXTMach 는 `movl #EFAULT,d0`; `trap5` 는 원본이 `moveal 0x40b5648,%a0`(`_active_threads`)로 직접 읽고 NeXTMach 는 `lea`·`CPU_NUMBER_d0`·색인 읽기(22 B 대 16 B); `trap6` 은 같은 직접 읽기에 더해 NeXTMach 의 앞 `movl d0,d1` 이 원본에 없고 마지막 저장이 `d1` 대신 `d0`(24 B 대 16 B); `trace` 는 원본 `jmp 0x4001b3e`(`std_trap`) 6 B 이고 NeXTMach 의 `trace` 는 `TRAP` 매크로; `_blkclr` 는 원본 10 B = `jmp 0x4092e12`(`_bzero`) 6 B + 4 B 0(`0x4001900 frestore 0x40018d4` 가 쓰는 널 프레임), A0c 에서는 `_set_cpu_number` 가 사이에 끼어 어긋남.
- NeXTMach 에만 있는 함수(A0c 객체): `_start_init`·`_thread_bootstrap`·`_bbcci`·`_bbssi`·`_set_cpu_number`·`_save_context`·`_load_context`·`_loadfpregs`·`stray`·`badtrap`·`illegal` … `mmu_access`(`TRAP` 매크로 열)·`trap0`·`syscall_*`·`trap2`(원본은 `_cache_push` 구간 안 8 B). 원본 벡터 표는 `std_trap` 하나로 모읍니다(§742).
- 원본 심볼(`symbols.tsv`): 0x4092e12 `_bzero`, 0x4092d2c `_bcopy`, 0x40b5648 `_active_threads`, 0x409382c `_nmi`, 0x4094afe `_m68k_init`, 0x40b56cc `_cpu_type`.

1단계 범위(후보 `scratch/p744/locore_C1.s`, 명세·산출물 `08_build/artifacts/m4p744/`; 07 에는 쓰지 않음):
1. 생성기 `scratch/p744/gen_locore.py`: NeXTMach `locore.s`(A0c 와 같은 머리·조건값·`GDB` 1·`NCPUS` 1·`NIPLMEAS` 0)에 아래 변경을 `plan 744 (D167, D024) BEGIN/END` 표시로 적용해 후보를 씁니다. 파일 머리에 `assym` `#define` 블록(§741 의 해결된 상수; §743 으로 `FSIZE`·`TRACE_AST_BIT`·`TRACE_USER_BIT`·`UTHREAD`·`UTASK` 는 원본 단위에 쓰는 자리가 없고 `AST_SCHED_BIT` 은 4; 아직 이 단계에서 지우지 않는 NeXTMach 텍스트가 쓰는 미결 상수는 "진단 자리표시"로 표시하고 뒤 단계에서 그 텍스트와 함께 없앰).
2. 변경(소형 함수 6 개와 `fpsp_done`(`rte` 2 B)·`fpsp_frame_err`(`pea 문자열; jsr _panic; bral 자기 자신` 18 B; 원본 `0x4002220`)를 더함): `_bbcci`·`_bbssi`·`_set_cpu_number` 삭제; `_call_nmi` 는 `IRSO` 를 `16*4` 로(이 함수에 한해 값을 원본에서 가져오며 `INTRARG` 쪽 `IRSO` 는 건드리지 않음); `_FAULT_ERROR` 는 `movl _fault_error,d0` 로 시작하는 원본 꼴로; `trap5`·`trap6` 은 `movl _active_threads,a0`; NeXTMach 의 `TRAP(trace, T_TRACE, 4)`(locore.s:1348) 호출을 `trace: jmp std_trap` 로 바꿈(`trace` 는 이 단계에서 정의되고 `std_trap` 만 뒤 단계에서 정의되므로 이 단계 객체에서는 정의 없는 이름으로 남음; 호출을 남긴 채 레이블을 더하면 중복 정의이므로 호출을 지움); `_set_cpu_number` 삭제로 `entry` 구역의 `jsr _set_cpu_number`(locore.s:224, A0c 텍스트 오프셋 4298 의 재배치)는 정의 없는 이름이 되며 어셈블 오류가 아님(`entry` 는 5 단계에서 새로 씀).
3. 자료: 통합 블록으로 옮기지 않고 NeXTMach 의 끼워 둔 `.data` 조각을 제자리에 두어 소스 순서가 원본 자료 순서와 같게 합니다(`_cache` 106 → `_fpu_version` 185 → [`global_lock` 526–528 삭제] → 새 `_fault_error`(`_FAULT_ERROR` 부근, 824 행 앞뒤; 소스 순서상 `_probe_recover` 862 보다 앞) → `_probe_recover` → `argc_table`(1428, `trap3` 본문 중간 그대로) → 문자열 3 개 → `mmu_status`(1820) → 새 `fpsp: frame format error`(`fpsp_frame_err` 곁) → `_scb`(72 항목, NeXTMach `scb.s` 자리 = 파일 끝)); NeXTMach 의 `_startup_pcb` 류 `FIXME`/`NCPUS>1` 조각은 조건 밖이라 나오지 않음. 같은 이름의 중복 정의가 생기지 않도록 새 조각은 해당 NeXTMach 정의를 지운 자리에만 둠.
4. 대조 도구 `scratch/p744/cmp_strict2.py`: §741 의 엄격 대조에 (가) 객체 재배치마다 원본 4 B 값 V 와 객체 가산값 A 로 `V − A`(pc 상대면 필드 주소 + 부호 있는 V)가 원본 심볼표의 이름과 같은지(가산값 오류를 거름; 정의 없는 지역 대상은 "이름 미확인"으로 따로 표시), (나) pc 상대 재배치는 분기 명령에서만 나오는지와 길이를 보고, (다) 객체 `__data` 검사 `scratch/p744/check_data.py`: §742 `check_d0.py` 를 그대로 쓸 수 없으므로(정의된 핸들러는 외부 재배치가 아니고 `argc` 가산값이 텍스트 위치에 따라 다름) 정의된 대상은 객체 심볼 이름으로 조회하고 정의 없는 대상은 외부 이름·가산값 0 으로 검사하며 `__data` 크기 464 B 를 포함합니다. 함수 크기(`extent`)는 이웃 함수가 모두 같은 이름으로 있을 때만 일치를 요구하고 아니면 보고만 합니다.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(§741 과 같은 `cc` 줄, `-DASSEMBLER`). (나) 엄격 대조 EQUAL 이 기존 23 개에 더해 `_FAULT_ERROR`·`_blkclr`·`_call_nmi`·`trap5`·`trap6`·`trace`·`fpsp_done`·`fpsp_frame_err` 8 개로 모두 31 개(목표 개수이며 달성 여부는 C1 실행 뒤 python 집계). (다) 위 31 개의 모든 재배치에서 `V − A` 가 가리키는 원본 심볼 이름이 객체 이름과 같음(이름 없는 대상은 따로 표시; 가산값 오류 시 실패). (라) `__data` 가 464 B 이고 `check_data.py` 기준 전부 통과. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) 단위 전체의 순서·크기 일치는 모든 단계가 끝난 뒤에 봅니다(1단계는 항목별 대조). (나) 지우는 NeXTMach 함수를 다른 코드가 참조해도 어셈블은 실패하지 않고 정의 없는 이름(재배치)이 되므로 오류로 드러나지 않음 → 삭제 뒤 남는 정의 없는 이름 목록을 python 으로 뽑아 보고하고, 이 단계에서 지운 이름(`_bbcci`·`_bbssi`·`_set_cpu_number`)이 목록에 나오는지 확인. 같은 이름의 중복 정의(예: `trace` 호출과 새 레이블, `argc_table` 이중 정의)는 어셈블 오류 또는 객체 심볼 중복으로 드러남. (다) `_blkclr` 의 널 프레임은 소스 레이블 이름이 원본에 없어 NeXTMach 의 `null_frame` 이름을 그대로 쓰며 "이름 미확인"입니다. (라) 재배치 대상 이름은 원본이 링크된 이미지라 "명령 피연산자 주소를 원본 심볼에 대응시킨 이름"이며 객체 재배치 이름과의 일치만 확인합니다.

### 744.1 §744 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) `trap6` 의 차이를 직접 읽기뿐이라고 적음(NeXTMach 의 `movl d0,d1` 과 저장 레지스터도 다름). (2) `_set_cpu_number` 삭제가 어셈블 오류로 드러난다고 적음(실제로는 정의 없는 이름이 되어 조용히 남음). (3) `trace` 를 "정의 없는 이름"이라 적어 EQUAL 목표와 모순(교체 대상은 `TRAP(trace…)` 호출). (4) D0 검사기를 그대로 쓸 수 있다고 적음(정의된 핸들러·`argc` 위치 때문에 불가). (5) 자료를 통합 블록으로 옮기는 듯 적음(NeXTMach 조각 제자리 유지가 원본 순서와 맞음). (6) `NO-OBJ-NAME` 을 "NeXTMach 에 짝이 없음"으로 과장. (7) 기존 비교기가 재배치 가산값·함수 끝을 보지 않는다는 점을 기준에 반영하지 않음.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 58·23·18·17·8052 B·2936 B | python: 함수 표 합 8052, `.strict` 집계 `Counter({'EQUAL-MOD-RELOC':23,'NO-OBJ-NAME':18,'DIFF':17})`, 비일치 7032 − 4096 = 2936 | ✅ |
| `NO-OBJ-NAME` 은 이름이 없다는 뜻일 뿐 | A0c 객체 라벨 목록에 `_move_space`(원본 `__move_space`)·`_pload_*` 가 있음을 열음 | ✅ 본문 고침 |
| `_call_nmi`·`trap5`·`trace`·`_blkclr`·`_FAULT_ERROR` 원본 바이트 | python 으로 원본에서 추출: `_FAULT_ERROR 2039040ad96c4e5e4e7542804e5e4e75`, `trap5 2079040b564820680024202800504e73`, `trace 4ef904001b3e`, `_blkclr 4ef904092e1200000000`, `frestore` 피연산자 0x40018d4 의 4 바이트 0 | ✅ |
| `trap6` 차이는 직접 읽기뿐이 아님 | `locore.s:1584–1591` 열음(`movl d0,d1`, `movl d1,a0@(THREAD_USER_REG)`); 원본 `trap6 2079040b564820680024214000504e73` | ✅ 본문 고침 |
| `_set_cpu_number` 삭제 뒤 `null_frame` 이 이어짐(조건: `notdef` 비정의) | codex 의 객체 계산은 열지 않음; `locore.s:922–967` 소스 순서와 A0c 객체 라벨(`_blkclr` 5770, `_set_cpu_number` 5776 크기 26, `null_frame` 5802)로 확인 | ✅ (26 B 삭제 시 6 B + 4 B) |
| `jsr _set_cpu_number`(224)가 활성 참조로 남음 | `locore.s:215–227` 열음; A0c 텍스트 재배치 `(4298,'ZERO_PHYS',local)` 확인 | ✅ 본문 고침 |
| `trace` 는 `TRAP(trace,T_TRACE,4)` 한 곳에서 정의 | `grep -an 'TRAP(trace' locore.s` → 1348 | ✅ 본문 고침 |
| 비교기가 가산값·함수 끝을 안 봄 | `cmp_strict.py` 24–38 행을 앞서 열었음(재배치 필드를 통째로 0 으로 가림, `extent` 는 출력만) | ✅ 기준 보강 |
| 원본 재배치 레코드가 0 이므로 종류 검증은 불가 | `macho.json` `relocation_count` 0(앞서 확인); A0c 텍스트에 pc 상대 재배치 62/187 개(python) | ✅ pc 상대 처리를 명시 |
| 미정의 `std_trap` 으로 어셈블이 실패한다는 주장은 틀림 | 제 계획에는 그런 주장이 없음(위험으로 적지 않았음); D0 객체의 외부 재배치 49 개는 §742 에서 확인 | ⏭️ |
| `argc_table` 은 `trap3` 본문 중간 `.data` 에 이미 정의됨 | `locore.s:1428` 열음 | ✅ 본문에 반영 |

2 차 자기검사: ✅ 행은 이번 세션에 열었거나 돌린 출력입니다. "codex 의 객체 계산은 열지 않음"은 제가 재현하지 않은 수치이며 본문에 쓰지 않았습니다.

### 744.2 결과: 1단계 후보 C1 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더, 07 은 그대로): 생성기 `scratch/p744/gen_locore.py`(NeXTMach `locore.s` + A0c 머리에 표시 구간 적용; 2077 행 후보 `scratch/p744/locore_C1.s`), 대조 도구 `scratch/p744/cmp_strict2.py`·`check_data.py`, 명세 `08_build/artifacts/m4p744/spec_c1.json`. 실행: `m4p744-p1`(`bral` 가 NeXT `as` 에 없는 표기라 오류 1 → 종료 코드 `00 1`), `-p2`(긴 분기 표기 4 종 비교: `jra`·`bra` 는 같은 바이트 `60ff fffffff2`, `jbra`·`bra:l` 은 오류), `-p3`(`jra` 로 오류 0), `-p4`(머리 심볼 정리), `-p5`(별칭 추가; 최종, 종료 코드 `00 0`·`01 0`, 오류·경고 0).

p5 로 바뀐 점(원본 바이트·심볼표가 요구): ① `_start` 뒤 `_intstacks`(원본 0x4000318 = `_start`+8)를 `.align 2` 로 맞추고 `_intstack`·`_eintstack`·`_start_text`·`_sdata` 전역 심볼을 없앰(원본 심볼표에 없음; `_eintstack` 는 지역 레이블로 남음). ② `_copyoutmsg`·`_copyinmsg`: 원본 `_copyout`·`_copyin` 과 같은 주소의 전역 별칭(심볼표; NeXTMach 에는 없음)을 `PROCENTRY` 앞에 둠. 두 가지는 새 전역 심볼 검사(아래)가 드러냄.

판정(미리 정한 기준대로):
- (가) 어셈블 오류·경고 0: 통과(p5).
- (나) 엄격 대조 EQUAL: 기존 23 + `_FAULT_ERROR`·`_blkclr`·`_call_nmi`·`trap5`·`trap6`·`trace`·`fpsp_done`·`fpsp_frame_err` 8 = 31 항목, 1140 B(python 집계 `EQUAL entries 31 bytes 1140`). 나머지: DIFF 12(`_intstacks`: `entry` 가 NeXTMach 그대로; `ipl1`–`ipl7`·`trap3`·`trap4`·`addrerr`·`buserr`: 뒤 단계 대상)·`NO-OBJ-NAME` 15.
- (다) 31 항목의 재배치: 이름 불일치 0, pc 상대 지역 분기의 변위 불일치 0, 대상 이름을 양쪽에서 알 수 있는 경우는 모두 일치; 원본에 이름이 없어 이름 대조를 못 한 지역 대상이 25 곳("unnamed"; 예: `_copy*` 의 `copy_inval`·`copy_exit` 분기)으로 이 부분은 이름 미확인입니다. 원본 `__text` 의 재배치 레코드는 0 개이므로 종류(pc 상대 여부)는 객체 쪽 값이며 원본과의 직접 비교는 아닙니다.
- (라) `__data` 464 B, `check_data.py`: 크기·재배치 위치 80 곳·4 B 절대·비재배치 바이트·전역 자료 심볼 5 개(`_cache`·`_fpu_version`·`_fault_error`·`_probe_recover`·`_scb`)·`_scb` 72 항목(외부 이름 58 + 정의된 지역 레이블 14)·`argc_table` 8 항목(레이블 이름과 간격) 모두 통과. 첫 실행(`-p3`)은 `_sdata` 전역 때문에 (라)가 실패했고 위 ① 로 고침(기준을 낮추지 않음).

새로 얻은 점(이 단계에서 추가한 검사): 객체의 정의된 전역 심볼은 모두 원본 심볼표에 있어야 하고(`defined globals 79 not in original symbols` 목록이 앞으로 0 이 되어야 함: 지금은 NeXTMach 전용 `_load_context`·`_save_context`·`_loadfpregs`·`_pload_*`·`_start_init`·`_thread_bootstrap`·`stray`·`badtrap`·`illegal`…`mmu_access`·`trap0` 등 뒤 단계에서 지울 것만 남음), 원본 단위의 심볼 중 객체에 없는 것 목록(지금 텍스트 17 개 → 별칭 추가 뒤 15: `__move_space`·`__switch_context*`·`__stack_*`·`__return_with_state`·`_call_continuation`·`_tlb_update_*`·`_move_space_fault`·`_probe_rl`·`std_trap`·`_cache_push`·`_mon_exit`; 자료 0 개)이 뒤 단계의 할 일입니다. 객체 `__text` 는 8516 B(원본 단위 8052 B; 뒤 단계에서 줄어듦).

한계: 단위 전체의 순서·크기 일치는 아직 보지 않았고(NeXTMach 텍스트가 남은 구간), 이 후보는 07 에 올리지 않았습니다. 이름이 모두 NeXTMach 이름 또는 원본 심볼이며 새 가칭은 `IRSO1997` 하나입니다.



## 계획 745: m68k `locore.s` 구현 2단계 — `std_trap`·`ipl1`–`ipl7` 과 `INTRARG`·`INTRSCAN`·`INTRPOLL` 1997 꼴 (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §744 의 1단계(31 항목 EQUAL)에서 남은 DIFF·`NO-OBJ-NAME` 중 서로 이어진 한 덩어리입니다. 원본 `std_trap`(0x4001b3e)과 `ipl1`–`ipl7`(0x4001b8a–0x4001dfa)은 연속 8 항목 700 B(python 합)이고, 모두 NeXTMach 의 `INTRARG`·`INTRSCAN`·`INTRPOLL` 매크로 꼴을 바탕으로 하되 1997 프레임으로 바뀐 것입니다. 이 단계가 끝나면 EQUAL 목표는 31 + 8 = 39 항목, 1140 + 700 = 1840 B 입니다(목표 수이며 달성 여부는 실행 뒤 python 집계). 결정 D167 ③(`INTRARG` 의 `#` 인자는 `IMM0`/`IMM1` 류 이름으로 바꿔 매크로 유지)을 여기서 구현합니다.

사실(원본 바이트, python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030` 역어셈블; 추출물 `scratch/p745/orig_ipl.bin` 736 B = 0x4001b3e–0x4001e1e):
1. `ipl1`–`ipl7` 은 모두 앞 36 B(`007c0700 48e7ffff 4e7a8800 2f48003c 4def0038 244f bffc04001318 6306 4ff904001318`; 처음 쓴 "32 B"는 제 오기이며 python 으로 36 B)가 같고(7 개 비교 True; `027c` 까지 포함한 최장 동일 접두부는 38 B), 그 뒤 `027c f?ff`(`andiw #…,%sr`)의 `?` 만 1–7 로 다릅니다. 곧 `oriw #1792,%sr`(IPL 7) → `moveml %d0-%sp,%sp@-` → `movc %usp,%a0` → `movel %a0,%sp@(60)` → `lea %sp@(56),%fp` → `moveal %sp,%a2` → `cmpal #0x4001318,%sp` → `blss +6` → `lea 0x4001318,%sp` → `andiw #0xf?ff,%sr` 입니다. `r_fsize` 워드(`clrw sp@-`)·`DO_ALIGNMENT`·`addl #1,a6` 는 없고 `lea sp@(56),fp` 가 대신 있습니다(스택 프레임의 `a6` 칸: `60` 이 `R_SP` 이므로 `a6` 는 56).
2. `ipl1`/`ipl2`(INTRARG 꼴, 각 60 B): 위 공통부 뒤 `movel #0|#1,%sp@-`(`2f3c` + 4 B 즉시값, 6 B) → `jsr 0x4094080`(`_softint_run`) → `addql #4,%sp` → `bral 0x40021d2`(`60ff`+4 B; 이 쓰임에서 `softint_rtn` 로 읽힘). 
3. `ipl3`·`ipl4`·`ipl6`·`ipl7`(INTRSCAN 꼴, 112·112·108·112 B): 공통부 뒤 `movw %a2@(64),%d0`(`d0` 지우지 않음) → `movel %d0,%sp@-` → `movel %a2@(66),%sp@-` → 루프: `moveal 0x40b56d4,%a0`(`_intrstat`; NeXTMach 의 `_slot_id` 더하기는 없음) → `movel %a0@,%d0` → `andl 0x40b56d0,%d0`(`_intr_mask`) → `bfffo %d0{18:12},%d1`(ipl3; ipl4 는 17:1, ipl6 은 2:12, ipl7 은 0:2) → `bnes +8` → `addql #8,%sp` → `jmp 0x40021cc`(`4ef9`; `intr_rtn` 로 읽힘) → `subil #start,%d1`(ipl6 은 `subql #2`) → `lea scanarg,%a0` → `moveal %a0@(0,%d1:w:4),%a1` → `lea scanlist,%a0` → `moveal %a0@(0,%d1:w:4),%a0` → `movel %a1,%sp@-` → `jsr %a0@` → `addql #4,%sp` → `bras` 루프 처음.
4. `ipl5`(INTRPOLL 꼴, 60 B): 공통부 뒤 `moveal #0x40b085c,%a4`(`_poll_intr` 주소) → `moveal %a4@+,%a1` → `jsr %a1@` → `tstl %d0` → `beqs` 위 `moveal` → `bral 0x40021cc`. NeXTMach 의 `a3` 저장·복원은 없고 레지스터는 `a4` 입니다.
5. `std_trap`(76 B): `moveml %d0-%sp,%sp@-` → `movc %usp,%a0` → `movel %a0,%sp@(60)` → `lea %sp@(56),%fp` → `movew %sp@(70),%d0`(`VOR`) → `andil #4095,%d0` → `moveal %sp,%a2` → `cmpal #0x4001318,%sp` → `blss` (아래 `movel %a2,%sp@-`) → `moveal 0x40b57cc,%a5`(`_stack_pointers`, 4 B COMMON; 색인 없음) → `cmpal %sp,%a5` → `bcss`(아래 `moveal 0x40b57cc,%sp`) → `subal #4084,%a5` → `cmpal %sp,%a5` → `bcss`(아래 `movel %a2,%sp@-`) → `moveal 0x40b57cc,%sp` → `movel %a2,%sp@-` → `subaw #12,%sp` → `movel %d0,%sp@-` → `bral 0x400217c`(`trap` 로 읽힘: 그 주소는 `addql #1,0x40b5654; jsr 0x40996b8` 로 시작). NeXTMach 에는 `std_trap` 이 없고 `TRAPVEC` 매크로 꼴에 스택 점검이 더해진 형태입니다(원본 벡터는 모두 이 한 곳으로 모임, §742). 점검의 의미("범위 밖이면 `_stack_pointers` 로 바꿈")는 바이트에서 읽은 추정이며 소스에는 바이트가 정한 형태만 씁니다.
6. 이 8 항목이 참조하는 지역 대상 4 곳: `0x4001318`(= `_intstacks` 0x4000318 + 0x1000 = `_eintstack`), `0x400217c`(`trap`), `0x40021cc`(`intr_rtn`), `0x40021d2`(`softint_rtn`). 이 세 개의 뒤 이름은 원본 심볼표에 없는 지역 대상이라 이름 대조가 안 되고(§744 와 같은 "이름 미확인"), 위치는 뒤 단계(`trap`·`intr_rtn`·`softint_rtn` 를 쓰는 때)와 단위 전체 대조에서 봅니다.

설계(후보 `scratch/p745/locore_C2.s`; 생성기 `scratch/p745/gen_locore2.py` = `scratch/p744/gen_locore.py` 에 아래를 더함; 07 에는 쓰지 않음; 모든 변경은 `/* plan 745 (D167, D024) BEGIN: … */ … /* plan 745 END */` 표시):
1. NeXTMach `INTRARG`·`INTRSCAN`·`INTRPOLL` 정의를 `#if GDB` 의 두 갈래(GDB·비 GDB)에서 모두 지우고(두 갈래의 `TRAP`·`TRAPVEC`·`IPL_INTR` 등은 이 단계에서 건드리지 않음), `#endif GDB` 뒤에 1997 꼴 세 매크로를 한 벌만 새로 씁니다(`IRSO1997 (16*4)` 정의는 `_call_nmi` 쪽에서 매크로 앞으로 옮김). 인자에 마스크를 더해 `INTRARG(name, mask, vector, arg, ra)`, `INTRSCAN(name, mask, scanlist, scanarg, start, len)`, `INTRPOLL(name, mask, vector)`. 본문은 위 사실 1–4 가 정한 순서: `orw \#0x700,sr; moveml \#0xffff,sp@-; movc usp,a0; movl a0,sp@(R_SP); lea sp@(R_A6),a6; movl sp,a2; cmpl \#_eintstack,sp; jls 1f; lea _eintstack,sp; 1: andw \#mask,sr;` 에 이어 각 꼴의 몸. `IPL_INTR`·`INTR_CALL_LIT` 는 쓰지 않음(원본에 `NIPLMEAS` 코드 없음; `INTR_CALL_LIT` 는 `\#` 를 붙이는 새 본문이 필요해 INTRARG 본문에 직접 `movl \#arg,sp@-; jsr vector; addql \#4,sp` 로 씀; `INTR_CALL_REG`·`INTR_CALL_REG0` 는 NeXTMach 그대로 사용). `R_A6`(56)은 이 프로젝트의 이름으로 파일 머리 `#define` 블록에 근거와 함께 더함.
2. D167 ③: `#define IMM0 0`·`#define IMM1 1`(머리 블록; A0c 에 있던 것) 을 되살리고 `INTRARG(ipl1, 0xf1ff, _softint_run, IMM0, softint_rtn)`·`ipl2` 는 `IMM1`·`0xf2ff` 로 부르며 INTRARG 본문이 `\#arg` 로 `#` 를 붙입니다(NeXT cc 의 cpp 가 `#` 로 시작하는 인자를 지우므로). 이 방식이 이 cpp 에서 `movel #0,%sp@-`(6 B)로 풀리는지는 실행으로 확인하며, 안 되면 인자 값 자체(`0`·`1`)를 쓰는 변형 C2A 와 비교해 그 결과를 사용자에게 보고합니다(결정 D167 ③ 은 바꾸지 않고 결과만 보고).
3. `std_trap` 을 `INTRARG(ipl1, …)` 바로 앞에 평문으로 씁니다(`.globl std_trap`; 원본 순서는 `_call_continuation` 다음이며 위치는 단위 전체 대조 때 맞춤). 레지스터 이름은 NeXTMach 식(`fp` 대신 `a6`), `subl #4084,a5` 와 `subw #12,sp` 는 `as` 가 주소 레지스터 대상에서 `suba` 로 짜는지를 실행으로 확인(`TRAPVEC` 의 `subw #12,sp` 가 A0c 객체에서 `9efc000c` 였는지도 먼저 확인).
4. 명령 철자 변형(바이트로 정함): 주 후보 C2 는 `orw`/`andw`, C2I 는 `oriw`/`andiw`(두 철자가 같은 `007c`·`027c` 를 내는지 확인). 둘 다 EQUAL 이면 NeXTMach 코드 철자에 더 가까운 쪽(`movw #…,sr` 류가 쓰는 `w` 접미 형)인 `orw`/`andw` 를 씁니다.
5. 변형 4 개를 한 번에 어셈블: C2(주), C2I(철자), C2A(인자 `0`·`1` 직접), C2N(음성 대조: C2 에서 `ipl3` 마스크만 `0xf2ff`). 명세 `08_build/artifacts/m4p745/spec_c2.json`(§744 의 `spec_c1.json` 과 같은 `inc`·`defs`, 변형만 4 개), 실행 `scratch/p737/run.sh m4p745-p1 …`(실행 ID 소문자·미사용 확인: `08_build/runs/REGISTRY` 마지막은 `m4p744-p5`).
6. 대조 도구: `scratch/p744/cmp_strict2.py` 를 이 단계용으로 복사(`scratch/p745/cmp3.py`)해 (가) 객체 `ipl1`–`ipl7`·`std_trap` 의 크기가 원본 항목 크기와 같은지(이웃 레이블이 연달아 있을 때), (나) 지역 재배치 대상의 **객체 쪽 레이블 이름**이 기대(원본 대상 주소 → 이름: 0x4001318→`_eintstack`, 0x400217c→`trap`, 0x40021cc→`intr_rtn`, 0x40021d2→`softint_rtn`; 각 주소의 원본 바이트는 python 으로 열어 확인)와 같은지 추가로 검사, (다) 기존 31 항목이 여전히 EQUAL 인지(퇴행 없음) 집계.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(C2·C2I·C2A·C2N 각각; 어셈블이 안 되는 변형은 그 이유를 보고). (나) 주 후보 C2 에서 `std_trap`·`ipl1`–`ipl7` 8 항목이 EQUAL(마스크한 재배치 위치 외 바이트 전부 같음)이고 `cmp3.py` 의 FAIL 표시 없음, 전체 EQUAL 39 항목·1840 B(기존 31 항목은 퇴행 없음). (다) 8 항목의 외부 재배치 이름이 원본 심볼 이름과 같음(`_stack_pointers`·`_softint_run`·`_intrstat`·`_intr_mask`·`_ipl3_arg`·`_ipl3_scan`…`_poll_intr`)이고 가산값 오류 0, 지역 재배치 대상의 객체 쪽 이름이 위 기대와 같음. (라) 음성 대조 C2N 에서는 `ipl3` 만 DIFF 이고 나머지 7 항목은 EQUAL(대조 도구가 한 바이트 차이를 잡는다는 증거). (마) `check_data.py` 전부 통과(자료 불변), 정의된 전역 심볼 중 원본 심볼표에 없는 것의 목록에 새 이름이 없음(지금 26 개 중 `stray`·`badtrap`… 뒤 단계에서 지울 것만), "원본 단위 심볼 중 객체에 없는 것"(텍스트)에서 `std_trap` 이 빠져 14 개가 됨. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) 이 단계의 객체에서 `trap`·`intr_rtn`·`softint_rtn` 은 NeXTMach 위치에 있어 분기 변위와 `jmp` 절대값이 원본과 다릅니다(재배치 위치를 가려서 비교하는 방식이므로 EQUAL 판정에는 영향 없으나 위치 일치는 확인되지 않음). (나) 원본에 `NIPLMEAS` 코드가 없다는 것은 이 8 항목 바이트에서만 확인한 것입니다. (다) `std_trap` 의 스택 점검 의미는 추정이며 이름·주석에 의미를 단정하지 않습니다(`4084` 는 바이트 값). (라) 새 이름은 `R_A6`(56) 하나와 매크로 인자 이름(`mask`)뿐이며 NeXTMach 의 `TRAP`·`TRAPVEC`·`IPL_INTR`·`INTR_CALL_LIT` 는 그대로 두므로 이 단계 후보에는 쓰이지 않는 정의가 남습니다(뒤 단계에서 정리). (마) 위 매크로 방식이 D167 ③ 의 의도(이름 `IMM0`/`IMM1` 로 `#` 문제를 피함)와 같은지는 결과를 보고 사용자가 판단합니다.

### 745.1 §745 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 사실 1 의 공통 앞부분을 "32 B"로 썼음(실제 36 B; 본문 고침). (2) 비교기의 약점을 계획 단계에서 보지 못함: 재배치 위치·폭·종류를 기대 목록과 대조하지 않고 객체가 준 범위를 그대로 가림, 외부 이름은 원본 심볼이 없으면 메모만 남기고 실패로 치지 않음, `extent_obj` 차이도 메모뿐, 검사 스크립트가 실패해도 종료 코드가 0(`cmp_strict2.py` 36–38·58–60·67–69 행과 `check_data.py` 끝줄을 이번에 다시 열어 확인). (3) 음성 대조가 바이트 한 곳(C2N)뿐이라 이름·가산값·지역 대상 오류를 잡는지 증명하지 못함.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 구간 0x4001b3e–0x4001e1e 736 B, 계획 사실 1–5 의 명령열 일치 | python 으로 원본 `__text` 에서 같은 구간을 추출(736 B, SHA-256 앞 12 자 `15e44c52b2b9`) + `m68k-linux-gnu-objdump -m m68k:68030` 로 제가 앞서 직접 읽은 열과 일치 | ✅ |
| 공통 앞부분 36 B(진입점 +36 에 `027cf?ff`), 최장 동일 접두부 38 B | python: 36 B 열이 계획 hex 와 같음 True, 7 개 `ipl` 접두부 비교 → 38 | ✅ 본문 고침 |
| `2f3c00000000`·`2f3c00000001`(0x4001bb2·bee), `9bfc00000ff4`(0x4001b6c), `9efc000c`(0x4001b7e), `287c040b085c`(0x4001d0a), `225c`(0x4001d10), `bfffo` 4 개(`edc0148c`·`edc01441`·`edc0108c`·`edc01002`; 0x4001c42·cb2·d5e·dca), `0481 00000000`(0x4001dd8)·`5581`(0x4001d6c) | python 으로 각 주소 바이트를 읽어 hex 비교: 전부 True | ✅ |
| 분기 길이: `631a`·`650a`·`6506`(0x4001b60·b6a·b74), 루프 `60c6`(0x4001d88)·`60c2`(0x4001c70), `67f8`(0x4001d16) → 0x4001d10 | 같은 python: 바이트 True, `67f8` 목표 0x4001d10 계산 | ✅ (`ipl5` 의 루프는 `a4@+` 읽기로 돌아감) |
| `_stack_pointers` 가 4 B COMMON 이라는 계획 문구는 심볼표만으로는 미확인 | 계획 문구의 근거는 `06_reconstruction/evidence/m68k-pcb.md:36`(COMMON `_stack_pointers` 4 B, D136; 앞서 열음); 심볼표만으로는 크기를 알 수 없다는 지적은 맞음 | ⚖️ 근거 파일을 계획에 명시 |
| 전처리: `-traditional-cpp` 가 `#0` 인자를 비우고 본문 `\#` 는 `#` 로 냄 | `08_build/runs/m4p744-p5/run.cmd` 에 `-traditional-cpp` 있음; `08_build/runs/m4p740-e1/stage/E740_trad.i:2678` 열음(`movl      ,sp@-`, `addql #4,sp`) | ✅ |
| `IMM0` 이름 인자와 본문 `\#arg` 의 결합은 증명되지 않음 | 맞음(위 .i 는 `#0` 직접 인자의 경우) → 실행에서 `-E` 출력과 객체 바이트를 둘 다 보존 | ✅ 채택(추가 `-E` 실행) |
| 숫자 레이블 반복은 오류 근거 없음, 분기 목표를 직접 확인할 것 | 기존 C1 의 INTRSCAN 확장이 같은 구조로 어셈블됨(p5); 함수 내부 분기 변위는 가리지 않고 비교하므로 EQUAL 판정이 목표 일치를 포함 | ⏭️ 별도 검사 불필요(EQUAL 이 포함) |
| `orw #0x700,sr` 철자·`subl #4084,a5` 결과는 미확인, 최종 바이트가 기준 | 동의; 변형 C2/C2I 와 최종 바이트 비교로 정함. `subw #12,sp` → `9efc000c` 는 1단계 객체 `stray` 에서 python 으로 확인(바이트열 `…0280 00000fff 9efc000c 2f00 60ff…`) | ✅ |
| `NIPLMEAS` 의존성이 남음(생성 헤더 값 0 이라는 전제) | C1 `locore_C1.s:288` 등 `#if NIPLMEAS` 열음; 전처리 .i 가 비 `NIPLMEAS` 쪽(`jsr _softint_run` 직접)을 보임(위 2678행); 생성 헤더에서 `NIPLMEAS` 정의를 grep 으로 찾지 못함(없으면 0) | ✅ 전제를 한계에 명시, `_intr_call`·`_ipl_intr` 정의 없는 이름이 객체에 없는지 검사 추가 |
| 비교기: 재배치 위치·폭·종류를 먼저 검증해야 함 | `cmp_strict2.py:37`(재배치 범위를 통째로 0 으로 가림) 열음 | ✅ 채택 |
| 외부 이름·가산값은 기대값으로 검사(원본 심볼이 없으면 메모만 남는 경로가 있음) | `cmp_strict2.py:58–60`(`unnamed-orig` 메모만, `ok` 안 바뀜) 열음 | ✅ 채택 |
| 크기는 다음 진입점으로, 기존 `extent_obj` 는 메모일 뿐 | `cmp_strict2.py:67–69`; 이번 구간은 객체 안에서 `std_trap → ipl1 … ipl7 → _call_nmi` 가 연속이어야 함 | ✅ 채택 |
| "FAIL 표시 없음"의 범위 모호(범위 밖 `_intstacks`·`trap3`·`trap4`·`addrerr`·`buserr` 가 FAIL) | `c1_p5.out` 의 `DIFF+FAIL` 12 개 목록과 일치 | ✅ 채택(적용 범위를 8 항목 + 기존 31 항목으로 명시) |
| C2N 은 재배치 검사를 검증하지 않음(`f3ff→f2ff` 는 한 바이트) | 동의(본문 변형 정의 확인) | ✅ 채택(음성 대조 추가) |
| 정의 없는 이름(`IMM0` 등)·검사 스크립트 종료 코드 | `check_data.py` 끝줄이 `print('ALL PASS' if ok …)` 뿐임 열음 | ✅ 채택 |
| 수치 700 B·736 B·1140+700=1840·39·26 개·15→14 | 제가 앞서 같은 값을 python 으로 얻음(700·1840·26 개 목록 세기·15 개 목록) | ✅ (목표치는 C2 실행 뒤 확인) |

2 차 자기검사: ✅ 행은 이번 세션에서 연 파일·돌린 python 출력입니다. "기존 31 항목 1140 B 재집계"는 codex 의 재집계를 제가 이번에 다시 하지는 않았고 §744.2 의 제 집계(`EQUAL entries 31 bytes 1140`)를 씁니다.

### 745.2 §745 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

변형을 6 개로 늘립니다: C2(주), C2I(`oriw`/`andiw`), C2A(`INTRARG` 인자 `0`·`1` 직접), 음성 대조 N1(C2 의 `ipl3` 마스크 `0xf2ff`), N2(C2 의 `ipl3` 가 `andl _intr_mask+4,d0`: 가산값 오류), N3(C2 의 `ipl5` 가 `jra softint_rtn`: 지역 대상 오류). 어셈블 뒤 전처리 출력 `-E`(C2·C2A; `08_build/artifacts/m4p740/e1/preproc.cmd` 와 같은 줄에 `-E` 만 바꿈)를 다른 실행(`m4p745-p2`)으로 보존해 `IMM0` 결합을 눈으로 확인합니다.

도구 `scratch/p745/cmp3.py`(종료 코드: 새 8 항목과 기존 31 항목에 FAIL 이 있으면 1): 새 8 항목은 원본 역어셈블에서 python 이 만든 **기대 재배치 목록**(주소 값이 `[0x4000310, 0x40d0000)` 안인 4 B 끝 피연산자와 `60ff` 의 변위; 위치·길이 4·pc 상대 여부·외부/지역·이름·가산값)과 객체의 재배치를 일대일로 대조(초과·누락·종류 불일치도 실패); 외부는 기대 이름과 가산값 0 이어야 하며 원본 심볼이 없는 경우도 실패; 지역은 객체 쪽 레이블 이름이 기대(0x4001318→`_eintstack`, 0x400217c→`trap`, 0x40021cc→`intr_rtn`, 0x40021d2→`softint_rtn`)와 같아야 함; 크기는 객체 레이블이 `std_trap, ipl1 … ipl7, _call_nmi` 순으로 연속이고 간격이 원본 항목 크기(76·60·60·112·112·60·108·112)와 같아야 함. `check_data.py` 는 실패 시 종료 코드 1. 정의 없는 이름 목록에 `IMM0`·`IMM1`·`_slot_id`·`_intr_call`·`_ipl_intr` 가 없어야 함.

추가 판정 기준: (바) N1·N2·N3 에서 `cmp3.py` 가 각각 `ipl3`(바이트)·`ipl3`(가산값)·`ipl5`(지역 대상)만 FAIL 로 잡고 다른 7 항목은 통과. (사) 위 정의 없는 이름 검사 통과. 기준 (가)–(마) 는 그대로입니다.

### 745.3 결과: 2단계 후보 C2 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p745/gen_locore2.py`(§744 의 `gen_locore.py` 를 실행한 뒤 §745 변경을 `plan 745 (D167, D024) BEGIN/END` 표시로 적용; 후보 6 개 `scratch/p745/locore_{C2,C2I,C2A,N1,N2,N3}.s`), 대조 도구 `scratch/p745/cmp3.py`(§745.2 의 기대 재배치 목록·이름·가산값 0·지역 레이블 이름·크기/순서·정의 없는 이름·기존 31 항목 퇴행 검사; 실패 시 종료 코드 1), 명세 `08_build/artifacts/m4p745/spec_c2.json`, 전처리 명령 `08_build/artifacts/m4p745/preproc.cmd`. 실행: `m4p745-p1`(6 변형 어셈블; 종료 코드 12 개 모두 0, 표준 오류 0 B; 표준 출력 6 개는 `-M` 의존 목록뿐), `m4p745-p2`(C2·C2A `-E` 출력 `E745_C2.i`·`E745_C2A.i`; 종료 코드 0·0).

변경 요약: NeXTMach `INTRARG`·`INTRSCAN`·`INTRPOLL` 을 `#if GDB` 두 갈래에서 지우고 `#endif GDB` 뒤에 1997 꼴 한 벌(`mask` 인자 추가; `orw #0x700,sr` → 프레임 저장·`lea sp@(R_A6),a6`·스택 전환 → `andw #mask,sr`; INTRSCAN 은 `_slot_id` 더하기 없이 `_intrstat` 직접; INTRPOLL 은 `a4` 사용·저장 복원 없음)을 씀. `std_trap` 평문 추가. `ipl1`·`ipl2` 는 `IMM0`·`IMM1`(머리 `#define IMM0 0`/`IMM1 1`)로 부르며 본문이 `\#arg` 로 `#` 를 붙임. 새 이름: `R_A6`(56), 매크로 인자 `mask`, 이미 있던 `IRSO1997` 정의를 매크로 앞으로 옮김.

판정(미리 정한 기준대로; 모두 python·도구 출력):
- (가) 어셈블 오류·경고: 6 변형 모두 0(표준 오류 0 B, 종료 코드 모두 0).
- (나) C2: `std_trap`·`ipl1`–`ipl7` 8 항목 EQUAL, `cmp3.py` FAIL 없음(종료 코드 0). `cmp_strict2.py` 집계 `Counter({'EQUAL': 39, 'NO-OBJ-NAME': 14, 'DIFF': 5})`, `EQUAL entries 39 bytes 1840`, 기존 31 항목 퇴행 없음(31/31). 독립 확인: 객체 `std_trap`–`_call_nmi` 직전 700 B 와 원본의 차이 144 B 는 전부 객체 재배치 필드(44 곳, 4 B) 안이며 필드 밖 차이 0, 가린 뒤 같음.
- (다) 8 항목의 재배치(`cmp3.py`): 위치·길이 4·pc 상대 여부가 기대 목록과 일치, 외부 이름은 원본 심볼 이름·가산값 0(`_stack_pointers`·`_softint_run`·`_intrstat`·`_intr_mask`·`_ipl3/4/6/7_arg/_scan`·`_poll_intr`), 지역 대상 레이블 이름이 기대(`_eintstack`·`trap`·`intr_rtn`·`softint_rtn`)와 같음.
- (라) 음성 대조: N1(`ipl3` 마스크 `0xf2ff`)은 `ipl3` 만 FAIL(`bytes differ at [38]`), N2(`ipl3` 의 `_intr_mask+4`)는 `ipl3` 만 FAIL(`@60 addend 4 expected 0`), N3(`ipl5` 의 `softint_rtn`)는 `ipl5` 만 FAIL(`local target ['softint_rtn'] expected intr_rtn`); 세 경우 모두 종료 코드 1(N1 로 확인), 나머지 항목·크기·정의 없는 이름·퇴행 검사 통과.
- (마) `check_data.py` `ALL PASS`(자료 불변); 정의된 전역 중 원본 심볼표에 없는 것 26 개로 이름 목록이 1단계와 같음(새 이름 없음; 정의된 전역 수 81 → 82 는 `std_trap` 추가); 원본 단위 심볼 중 객체에 없는 텍스트 14 개(1단계의 15 개에서 `std_trap` 이 빠짐: `__move_space`·`__return_with_state`·`__stack_attach`·`__stack_handoff`·`__switch_context`·`__switch_context0`·`__switch_context_discard`·`_cache_push`·`_call_continuation`·`_mon_exit`·`_move_space_fault`·`_probe_rl`·`_tlb_update_read`·`_tlb_update_write`); 정의 없는 이름에 `IMM0`·`IMM1`·`_slot_id`·`_intr_call`·`_ipl_intr` 없음.
- (바)·(사): 위와 같음.

D167 ③ 결과: `IMM0`/`IMM1` 이름 방식이 이 cpp 에서 동작합니다. `E745_C2.i` 가 `movl #  0  ,sp@-` 로 확장하고 객체는 `2f3c` + 4 B 즉시값(6 B)으로 원본과 같습니다. C2A(`0`·`1` 직접)·C2I(`oriw`/`andiw`)의 객체는 C2 와 SHA-256 앞 12 자(`9ae48a46180a`)까지 전체가 같아, 철자(`orw`↔`oriw`, `andw`↔`andiw`)와 인자 방식은 바이트에 영향이 없습니다(그래서 계획대로 `orw`/`andw` + `IMM` 방식을 씁니다).

정정: §745.1 판정표 중 "생성 헤더에서 `NIPLMEAS` 정의를 grep 으로 찾지 못함"은 제가 엉뚱한 폴더(스테이지 `stage/src`)를 찾은 것이었고, 실제 `08_build/runs/m4p745-p1/src/generated/iplmeas.h` 는 `#define NIPLMEAS 0` 입니다(열어 확인).

한계: (가) 이 객체에서 `trap`·`intr_rtn`·`softint_rtn` 는 NeXTMach 위치에 있어 지역 분기·`jmp` 값은 원본과 다르며 위치 일치는 단위 전체 대조에서 봅니다. (나) `std_trap` 스택 점검의 의미는 추정이고 소스에 의미를 단정하지 않았습니다. (다) 이 후보는 07 에 올리지 않았으며 `TRAP`·`TRAPVEC`·`IPL_INTR`·`INTR_CALL_LIT` 등 쓰이지 않게 된 NeXTMach 정의가 남아 있습니다(뒤 단계에서 정리). 남은 DIFF 5 개: `_intstacks`(`entry`)·`trap3`·`trap4`·`addrerr`·`buserr`.


## 계획 746: m68k `locore.s` 구현 3a 단계 — `trap3`·`trap4` (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §745.3 의 남은 DIFF 5 개 중 `trap3`·`trap4` 는 서로 이웃(0x4001e1e–0x4001f02, 170 + 58 = 228 B, python)이고 바깥 지역 대상을 쓰지 않아(`jmp`·분기 목표가 모두 함수 안) 한 단계로 닫을 수 있습니다. `addrerr`·`buserr`(116 + 648 B)는 `trap`·`trap_rtn`·`intr_rtn`·`softint_rtn` 와 68030 형식 판독·`ptest` 를 쓰는 훨씬 큰 새 코드이므로 3b·3c 로 따로 계획합니다. 이 단계가 성공하면 EQUAL 목표는 39 + 2 = 41 항목, 1840 + 228 = 2068 B 입니다(목표 수이며 달성 여부는 실행 뒤 python 집계).

사실(원본 바이트; python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030`; 전체 역어셈블 `scratch/p745/orig_stage3.txt`, 구간 [0x4001e1e, 0x400221e) 1024 B = 992 + 32(`trap5`·`trap6` 은 1단계에서 EQUAL)):
1. `trap3`·`trap4` 는 앞 30 B 가 같습니다(python 비교 True): `addql #1,0x40b5658`(`_cnt`+8; `_cnt` 는 0x40b5650, 0x40b5658 에는 심볼 없음) → `moveml %d0-%sp,%sp@-` → `movc %usp,%a0` → `movel %a0,%sp@(60)` → `lea %sp@(56),%fp` → `moveal %sp,%a2` → `moveal 0x40b57cc,%sp`(`_stack_pointers`). 끝 20 B 도 같습니다(처음 쓴 "12 B"는 제 오기; python 으로 20 B): `moveal %a2,%sp; moveal %sp@(60),%a0; movec %a0,%usp; moveml %sp@,%d0-%fp; addaw #64,%sp; rte`(`2e4a 206f003c 4e7b8800 4cd77fff defc0040 4e73`; 같음 True). `r_fsize` 워드(`subqw #4,sp`)는 없고 되돌아갈 때도 `addw #R_SR,sp`(64)입니다.
2. `trap3` 의 가운데: `tstl %d0; blts +0x22(→ moveq)` → `cmpl 0x40aff0c,%d0`(`_mach_trap_count`) → `bges` 같은 곳 → `lea 0x40afaac,%a0`(`_mach_trap_table`) → `lslw #4,%d0`(`e948`; NeXTMach 는 `a0@(d0:w:8)` 8 B 항목, 원본은 16 B 항목) → `lea %a0@(0,%d0:w),%a0`(`41f0 0000`) → `movel %a0@,%d0`(인자 개수) → `lea 0x40ad974,%a1`(`argc_table`) → `moveal %a1@(0,%d0:w:4),%a1`(`2271 0400`) → `jmp %a1@` → 나쁜 번호: `moveq #4,%d0`(`7004`) → `jmp 0x4001e7e`(`4ef9`; trap3 안 +96). 그 뒤 `argc_7`–`argc_1`(`movel %dN,%sp@-` 2 B 씩 7 개; 주소 0x4001e6a–0x4001e76, 간격 2 — §742 의 `argc_table` 값과 일치) → `argc_0`(0x4001e78): `moveal %a0@(4),%a0; jsr %a0@` → 0x4001e7e: `movel %d0,%a2@(0)`(`2540 0000`; 곧 프레임의 d0 칸; 인수를 되돌려 지우는 `lsll`·`addw` 는 없음) → `moveal 0x40b5648,%a1`(`_active_threads` 직접) → `moveal %a1@(36),%a0`(`THREAD_PCB`) → `btst #4,%a0@(84)`(`AST_SCHED_BIT`·`AST`) → `bnes` 아래 `7:` → `moveal %a1@(12),%a1` → `moveal %a1@(48),%a1` → `moveal %a1@(0),%a1`(§743 의 3 단 역참조) → `tstb %a1@(23)`(`P_CURSIG`) → `bnes 7` → `tstl %a1@(24)`(`P_SIG`) → `beqs 8` → `7: movel %a2,%sp@-; jsr 0x409a2fe`(`_check_for_ast`) → `8:` 공통 끝(위 1).
3. `trap4` 의 가운데: 공통 앞부분 뒤 `movel %a2,%sp@-; jsr 0x409a044`(`_unix_syscall`) 곧 공통 끝(`moveal %a2,%sp` …). 신호·AST 검사 코드가 없습니다(NeXTMach 는 `trap4` 에도 AST 처리가 있음).
4. 외부 참조: `_cnt`+8(두 함수 모두), `_stack_pointers`, `_mach_trap_count`, `_mach_trap_table`, `_active_threads`, `_check_for_ast`, `_unix_syscall`; 지역(자료): `argc_table`(0x40ad974); 지역(텍스트): `trap3` 안의 한 곳(`jmp` 목표 +96). `argc_0..7`(`trap3`+76…+90, 간격 2) 8 개 포인터는 §744 의 `check_data.py` 가 포인터→레이블 대응과 간격만 검사하며 텍스트의 `jmp` 목표는 검사하지 않으므로 새 비교기가 따로 검사합니다(python 집계: 기대 텍스트 재배치 11 곳 = `trap3` 8 + `trap4` 3).

설계(후보 `scratch/p746/locore_C3.s`; 생성기 `scratch/p746/gen_locore3.py` = §745 의 `gen_locore2.py` 실행 뒤 아래를 더함; 표시 `/* plan 746 (D167, D024) BEGIN: … */ … /* plan 746 END */`; 07 에는 쓰지 않음):
1. NeXTMach `trap3`·`trap4` 함수 본문을 위 사실 2·3 의 순서로 바꿔 씁니다. 바탕의 NeXTMach 주석 중 원본에도 맞는 것(`Save necessary state`, `Read in args and call handler`, 인자 밀어 넣기 앞 주석 등)은 그대로 두고, 맞지 않게 된 주석(`space for r_fsize`, `NOTE: … entry 8 bytes`, 서명 검사 문단 일부)과 `#if NIPLMEAS`·`#ifdef DEBUG` 조각(원본에 코드 없음)은 지웁니다. `.data argc_table` 조각은 `trap3` 안 제자리(§744 와 같게).
2. 머리 `#define` 블록에 `THREAD_TASK 12`·`TASK_U_ADDRESS 48`(둘 다 이 프로젝트의 가칭, §743; 07 로 올리기 전 사용자 확인)을 더하고, 쓰는 자리가 없어지는 NeXTMach 상수(`UTASK`·`THREAD_AST`·`AST_ZILCH`)는 아직 `trap0` 등 NeXTMach 텍스트가 쓰므로 지우지 않음(그 텍스트를 지울 때 함께 정리).
3. 어셈블러 철자는 바이트로 정합니다: `movl d0,a2@(R_D0)`(R_D0=0)가 `2540 0000` 인지(`a2@(0)` 최적화로 `2480` 이 될 수 있음), `lea a0@(d0:w),a0` 가 `41f0 0000` 인지, `movl #KERN_INVALID_ARGUMENT,d0` 가 `7004` 인지(`moveq`). 바이트가 다르면 철자를 바꿔 다시 어셈블하고(각 시도는 실행으로 기록) 바뀐 철자와 이유를 보고합니다.
4. 변형 4 개를 한 번에 어셈블: C3(주), 음성 대조 N1(`trap3` 의 `blt 3f` → `ble 3f`: 바이트), N2(`trap4` 의 `_cnt+V_SYSCALL` → `_cnt+V_INTR`: 가산값), N3(`trap3` 의 `jmp 5f` → `jmp 8f`: 함수 안 지역 대상). 명세 `08_build/artifacts/m4p746/spec_c3.json`(§745 와 같은 `inc`·`defs`), 실행 `scratch/p737/run.sh m4p746-p1 …`(`08_build/runs/REGISTRY` 에 `m4p746` 없음 확인함).
5. 대조 도구 `scratch/p746/cmp4.py`(§745 의 `cmp3.py` 를 일반화): 대상 목록을 인자로 받아 (가) 기대 재배치 목록(원본 역어셈블에서: 6 B 이상 명령의 끝 4 B 가 `[0x4000310, 0x40d0000)` 의 값이거나 `60ff` 변위)과 위치·길이·pc 상대·외부/지역이 일대일, (나) 외부 이름·가산값 대조: 원본 심볼이 있으면 이름·가산값 0, 심볼이 없는 주소는 명시 표(`0x40b5658` → `_cnt`+8)로만 허용, (다) 지역 대상: 자료 레이블은 이름(`argc_table`), 같은 항목 안 텍스트 대상은 "항목 시작에서의 거리"가 원본과 같음(`jmp` +96), (라) 객체 레이블 `trap3, trap4, trap5` 가 연속이고 간격이 170·58 B, (마) 정의 없는 이름 `IMM…`·`UTASK`·`THREAD_AST` 류 상수가 외부 심볼로 새어 나오지 않음(`_check_for_ast` 등 기대 외부 이름 외의 이 두 함수 영역 재배치는 모두 위 표와 일치해야 함), (바) 기존 39 항목 퇴행 없음(§745 의 `cmp_strict2.py` 집계 + `c2` 기준 39 목록), 실패 시 종료 코드 1.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(4 변형 각각). (나) C3 에서 `trap3`·`trap4` 가 EQUAL 이고 `cmp4.py` FAIL 없음, 전체 EQUAL 41 항목·2068 B, 기존 39 항목 퇴행 없음. (다) 두 함수의 재배치: 위치·종류·이름·가산값(`_cnt`+8)·`argc_table`·함수 안 목표 거리가 기대와 일치. (라) N1·N2·N3 가 각각 `trap3`(바이트)·`trap4`(가산값)·`trap3`(지역 대상)만 FAIL 이고 나머지 통과(종료 코드 1). (마) `check_data.py` `ALL PASS`(자료 불변: `argc_table` 포함); 정의된 전역 중 원본 심볼표에 없는 것의 이름 목록이 §745.3 과 같음(새 이름 없음), "원본 단위 심볼 중 객체에 없는 텍스트" 14 개 그대로. (바) 정의 없는 이름에 새 항목(예: `UTASK`)이 없음. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) `THREAD_TASK`·`TASK_U_ADDRESS` 이름은 가칭이고 값 12·48 은 바이트와 §743 의 측정(07 `thread`/`task` 구조)에서 왔을 뿐 출처 소스의 이름이 아님. (나) 원본 `trap3`·`trap4` 의 소스 의도(왜 AST 검사가 없는지, `_stack_pointers` 로 바꾸는 이유)는 바이트에서 읽은 것이며 주석에 단정하지 않음. (다) 여기서는 `trap`·`intr_rtn` 등 큰 함수 쪽 지역 레이블이 필요 없으므로 위치 일치(단위 전체 순서)는 뒤 단계에서 봄. (라) `argc_*` 8 개 레이블은 NeXTMach 이름을 그대로 쓰며 원본에는 이름이 없음("이름 미확인"). (마) 숫자 레이블(`3f`·`5f` 등)의 해소 대상은 자동으로 격리된다고 보지 않고 결과 바이트(함수 안 분기 변위·`jmp` 목표 거리)로 확인함(처음 쓴 "함수마다 따로 해석되므로 영향 없음"은 근거 없는 문장이라 지움).

### 746.1 §746 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 공통 끝을 "12 B"로 적음(실제 20 B; 본문 고침). (2) 사실 4 에서 `check_data.py` 가 텍스트 `jmp` 목표도 검사하는 듯 적음(포인터→레이블과 간격만; 본문 고침). (3) 번호 레이블이 함수마다 격리된다는 근거 없는 문장(삭제). (4) §745 의 기존 8 항목과 1단계 31 항목의 퇴행 검사를 `cmp_strict2.py` 에 맡기면 약하다는 점을 놓침: `cmp_strict2.py` 는 재배치 가산값 오류를 EQUAL 로 통과시킴(아래 재현). (5) `cmp3.py` 가 재배치 `type`·중복 위치·겹침을 검사하지 않음(`cmp3.py:56` `got[fo]=r` 로 덮어씀), `check_data.py` 에 실패 종료 코드 없음.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 공통 앞 30 B·공통 끝 20 B(0x4001eb4–0x4001ec8·0x4001eee–0x4001f02) | python: 최장 동일 접두부 30·접미부 20, 20 B 열이 계획 hex 와 같음 True, "마지막 12 B" 시작 0x4001ebc | ✅ |
| 주소·바이트: `e948`(0x4001e4e)·`41f00000`(e50)·`22710400`(e5c)·`7004`(e62)·`4ef904001e7e`(e64)·`25400000`(e7e)·`20690024`(e88)·`082800040054`(e8c)·`2269000c/30/00`(e94/98/9c)·`4a290017`(ea0)·`4aa90018`(ea6) | python 으로 각 주소 바이트를 읽어 hex 비교 전부 True | ✅ |
| 분기 `6d22`(e3e)·`6c1a`(e46)·`6618`(e92)·`6606`(ea4)·`6708`(eaa) 모두 짧은 형 | python 전부 True | ✅ |
| `argc_7..0` 주소 0x4001e6a–0x4001e78, trap3 기준 +76…+90, 길이 2 B(마지막 `argc_0` 6 B `2068 0004 4e90`) | python: 거리 `[76,78,…,90]`, `2f07`·`2f01`·`20680004`+`4e90` 바이트 True; 자료 `argc_table` 8 값이 0x4001e78 에서 0x4001e6a 로 내려감 | ✅ |
| `trap4` 가운데 `2f0a`(0x4001ee6)+`4eb90409a044`(ee8) | python True | ✅ |
| 수치 228·41·2068·30·1024=992+32 | python: 228, 41, 2068, 30, `0x400221e−0x4001e1e`=1024, 992+32=1024 | ✅ |
| 기대 텍스트 재배치 11 곳(trap3: 2·26·36·44·58·72·102·146, trap4: 2·26·34) | python 으로 역어셈블에서 4 B 끝 피연산자(범위 안 값)를 뽑아 같은 목록을 얻음 | ✅ |
| `movl d0,sp@(R_D0)`→`2f40 0000`, `movl #KERN_INVALID_ARGUMENT,d0`→`7004`, `a1@(U_PROCP)`→`2269 0000`; `a2@(R_D0)`·스케일 없는 `lea a0@(d0:w)` 는 정확한 선례 없음 | C2 객체 역어셈블(`scratch/p745/obj_trap3.bin`)에서 `2f40 0000`·`7004`·`2269 0000`·`41f0 0600`(`:8`) 직접 확인; `a2@(…)`·스케일 1 은 미확인으로 둠 | ⚖️ 철자는 실행으로 결정(계획 그대로) |
| `cmp3.py` 가 재배치 `type` 을 검사하지 않고 같은 위치 중복을 덮어씀; `check_data.py` 끝에 종료 코드 없음; `scratch/p745/check_data.py` 없음 | `grep -n "got\[fo\]=r\|r\['type'\]" scratch/p745/cmp3.py` → 56 행만; `tail scratch/p744/check_data.py` → `print('ALL PASS' …)` 로 끝; `ls scratch/p745/check_data.py` → 없음 | ✅ |
| `cmp_strict2.py` 가 기존 항목의 가산값 오류(`_intr_mask` +8)·지역 대상 변경을 EQUAL 로 통과 | 재현: C2 객체의 `ipl3` 의 `_intr_mask` 가산값을 메모리에서 +8 로 바꿔 `cmp_strict2.py` 실행 → `ipl3 EQUAL | … unnamed-orig@60 obj=_intr_mask` | ✅ (지역 대상 변경은 제가 재현하지 않았고 같은 코드 구조에서 나오는 말로 받음: `cmp_strict2.py` 의 지역 대상 이름 불일치는 양쪽 이름이 있을 때만 실패) |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. 지역 대상 변경 재현은 위 한 줄처럼 미재현으로 적었습니다.

### 746.2 §746 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. 새 비교기 `scratch/p746/cmp4.py` 를 `cmp3.py` 를 일반화해 만들되 (가) 재배치 `type` 0·`length` 2·비 scattered 를 검사하고, 한 항목 안 같은 위치의 중복 레코드·겹침·항목 경계 걸침을 실패로 하며, (나) 기대 재배치 목록은 원본 역어셈블에서 만든 목록과 위치별 일대일, (다) 외부 대상: 원본 심볼이 있으면 이름 일치·가산값 0, 심볼이 없는 주소는 명시 표(`0x40b5658` → `_cnt`+8, 그 밖에 나오는 주소는 조사 뒤 표에 추가하고 기록)에 있을 때만 이름·가산값을 요구, (라) 지역 대상: 대상 섹션(`__text`/`__data`)까지 일치, `argc_table` 은 `__data` 의 해당 레이블, 같은 항목 안 텍스트 대상은 "항목 시작에서의 거리"가 원본과 같음, (마) `argc_0..7` 레이블이 `trap3`+90 − 2i 에 놓임(고정 위치).
2. **기존 항목 퇴행 검사를 `cmp4.py` 로 한다**: 같은 규칙을 §745 의 8 항목과 1단계의 31 항목 모두에 적용하고, 먼저 지금의 C2 객체(`m4p745-p1`)에 돌려 그 결과를 계획·보고에 있는 그대로 적습니다(새 FAIL 이 나오면 1단계·2단계 결과의 정정 사유로 보고하며 그 단계 기준을 되돌려 완화하지 않음). 이름이 원본에 없는 지역 대상은 "이름 미확인"으로 개수만 보고.
3. `check_data.py` 를 복사한 `scratch/p746/check_data2.py` 는 실패 시 종료 코드 1. 자료를 틀린 입력(객체 `__data` 의 한 바이트를 바꾼 사본)으로 돌려 종료 코드 1 이 나옴을 확인.
4. 음성 대조 확장: N1(바이트)·N2(가산값)·N3(함수 안 지역 대상)에 더해 N4(외부 이름 오류: `trap4` 가 `jsr _unix_syscall_return`)·N5(`trap3` 의 `lea argc_table,a1` 가 다른 자료 대상을 가리킴 → 지역 자료 대상 오류는 만들기 어려우므로 `trap3` 의 `lea _mach_trap_table,a0` 를 `lea _mach_trap_count,a0` 로 바꾸는 외부 이름 오류 한 개로 대체 가능; 어느 쪽이든 실행 전에 N5 를 확정해 적음: N5 = `lea _mach_trap_count,a0`)를 추가. 재배치 구조(위치 누락·중복·종류·폭)는 객체 사본의 메모리 변형으로 `cmp4.py` 만 시험한다(어셈블 없음): 재배치 레코드 한 개 삭제·한 개 복제·`pcrel` 반전·`length` 변경 4 가지에서 모두 FAIL.
5. 판정 기준 추가: (사) `cmp4.py` 가 C2 객체의 39 항목에 대해 낸 결과(PASS 개수·FAIL 목록)를 먼저 기록하고, C3 의 41 항목은 모두 PASS 이어야 함(C2 에서 FAIL 이 있다면 그 항목 처리는 그 결과를 보고 사용자에게 보고하고 이 단계의 목표는 "C3 에서 새 항목 2 개 PASS + 기존 항목은 C2 와 같은 결과"로 둠 — 기준을 낮추는 것이 아니라 기존 항목의 정정은 별도 처리). (아) N1–N5 각각이 의도한 항목만 FAIL, 재배치 구조 변형 4 가지 모두 FAIL, 종료 코드 1.

### 746.3 결과: 3a 단계 후보 C3 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p746/gen_locore3.py`(§745 의 `gen_locore2.py` 를 실행한 뒤 `trap3`·`trap4` 를 `plan 746 (D167, D024) BEGIN/END` 표시로 바꿈; 후보 6 개 `scratch/p746/locore_{C3,N1,N2,N3,N4,N5}.s`), 비교기 `scratch/p746/cmp4.py`, 변형 시험 `scratch/p746/mutate_test.py`, 자료 검사 `scratch/p746/check_data2.py`, 항목 목록 `scratch/p746/ents39.json`·`ents41.json`, 명세 `08_build/artifacts/m4p746/spec_c3.json`. 실행: `m4p746-p1`(6 변형 어셈블; 종료 코드 12 개 모두 0, 표준 오류 0 B).

먼저 §746.2 의 2번대로 새 비교기를 **기존 C2 객체(`m4p745-p1`)의 39 항목**에 돌렸습니다: `PASS 39 FAIL 0`(unnamed 지역 대상 21 곳은 원본에 이름이 없는 대상의 개수). 곧 1단계·2단계 결과에 정정할 것은 없습니다. 비교기를 만들던 중 제 도구 오류 세 건을 고쳤습니다(역어셈블 한 줄 정규식이 뒤 공백 때문에 행을 버림; 숨겨진 0 행에 대한 단언; 항목 이름이 쉼표로 묶인 5 항목의 걸러내기). 비교기 시험(`mutate_test.py`, 메모리 사본, 파일 쓰기 없음): C2 객체에서 재배치 삭제·복제·`pcrel` 반전·`length` 변경·`type` 변경·외부 이름 변경·`_intr_mask` 가산값 +8(`cmp_strict2.py` 가 EQUAL 로 통과시킨 경우)·지역 `pcrel` 대상 변경·지역 대상 섹션 변경 9 가지가 모두 의도한 항목 하나만 FAIL(`ALL OK`; 처음 시험은 제 보조 함수가 항목 밖 재배치를 골라 틀렸고 항목 크기로 제한해 고침). `check_data2.py` 는 `__data` 한 바이트를 바꾼 사본에서 `FAIL (나)` 과 종료 코드 1 을 냅니다.

변경 요약: `trap3`·`trap4` 를 원본 순서로 새로 씀(`r_fsize` 없음; `lea sp@(R_A6),a6; movl sp,a2; movl _stack_pointers,sp`; `trap3` 은 `lslw #4,d0`·`lea a0@(d0:w),a0`, `argc_*` 뒤 `5: movl d0,a2@(R_D0)`, `_active_threads` 직접, `btst #AST_SCHED_BIT,a0@(AST)`, 세 단 역참조(`THREAD_TASK`·`TASK_U_ADDRESS`·`U_PROCP`), `_check_for_ast`, 공통 끝 `movl a2,sp … rte`; `trap4` 는 `movl a2,sp@-; jsr _unix_syscall` 후 공통 끝). NeXTMach 의 `NIPLMEAS`·`DEBUG` 조각과 맞지 않게 된 주석은 지움. 머리 `#define` 블록에 `THREAD_TASK` 12·`TASK_U_ADDRESS` 48(가칭)을 더함. 철자(`movl d0,a2@(R_D0)`→`2540 0000`, `lea a0@(d0:w),a0`→`41f0 0000`, `movl #KERN_INVALID_ARGUMENT,d0`→`7004`)는 첫 시도에서 모두 원본과 같아 바꾸지 않았습니다.

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(6 변형 모두, 종료 코드 12 개 0, 표준 오류 0 B).
- (나) C3: `trap3`·`trap4` EQUAL, `cmp4.py` `PASS 41 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 `Counter({'EQUAL': 41, 'NO-OBJ-NAME': 14, 'DIFF': 3})`·`EQUAL entries 41 bytes 2068`, 기존 31 항목 퇴행 없음(`cmp3.py` 31/31). 독립 확인: 객체 `trap3`–`trap5` 직전 228 B 와 원본의 차이 43 B 는 전부 재배치 필드 11 곳 안이며 필드 밖 차이 0.
- (다) 재배치: 위치(trap3: 2·26·36·44·58·72·102·146, trap4: 2·26·34)·종류·길이·외부 이름·가산값(`_cnt`+8)·`argc_table` 의 `__data` 레이블·`jmp` 목표 거리 96 이 기대와 일치(`cmp4.py`); 객체 레이블 `trap3`·`trap4`·`trap5` 간격 170·58 B.
- (라) 음성 대조: N1(`ble`) `trap3` 만 FAIL(`bytes differ at [32]`), N2(`_cnt+V_INTR`) `trap4` 만 FAIL(`_cnt+12 expected _cnt+8`), N3(`jmp 8f`) `trap3` 만 FAIL(`in-entry target distance 150 expected 96`), N4(`_unix_syscall_return`) `trap4` 만 FAIL, N5(`_mach_trap_count`) `trap3` 만 FAIL; 모두 종료 코드 1.
- (마) `check_data2.py` `ALL PASS`(11 개; 새 `(사)` 검사 `argc_i` 가 `trap3`+90−2i 포함, 종료 코드 0; C2 객체는 NeXTMach `trap3` 이라 이 검사가 실패한다는 것도 확인함); 원본 심볼표에 없는 정의된 전역 26 개로 이름 목록 불변; 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로.
- (바) 정의 없는 이름: C3 는 C2 보다 `_check_for_ast` 하나 늘었고(원본 외부 심볼), `UTASK`·`THREAD_AST`·`AST_ZILCH`·`IMM0`·`IMM1`·`_slot_id`·`_intr_call`·`_ipl_intr` 는 없음.
- (사)·(아): 위와 같음(C2 의 39 항목 PASS, C3 의 41 항목 PASS; N1–N5 와 재배치 구조 변형이 모두 의도한 항목만 FAIL).

한계: (가) `THREAD_TASK`·`TASK_U_ADDRESS` 는 가칭이며 07 로 올리기 전 사용자 확인이 필요합니다. (나) 원본에 이름이 없는 지역 대상(`argc_0..7` 의 레이블, 다른 항목의 지역 대상 21 곳)은 이름 미확인입니다. (다) 소스 의도(AST 검사가 없는 이유, 커널 스택 전환 이유)는 바이트에서 읽은 것이며 주석에 단정하지 않았습니다. (라) 이 후보는 07 에 올리지 않았고, 남은 DIFF 3 개는 `_intstacks`(`entry`)·`addrerr`·`buserr` 입니다.


## 계획 747: m68k `locore.s` 구현 3b 단계 — `addrerr` (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §746.3 의 남은 DIFF 3 개(`_intstacks`·`addrerr`·`buserr`) 중 `addrerr`(0x4001f22–0x4001f96, 116 B)는 NeXTMach 의 `addrerr` 에서 몇 줄만 빠지고 한 덩어리가 더해진 꼴이고, `buserr`(648 B)는 `trap`·`intr_rtn` 등 지역 레이블을 품은 큰 함수라 3c 로 따로 합니다. 이 단계가 성공하면 EQUAL 목표는 41 + 1 = 42 항목, 2068 + 116 = 2184 B 입니다(목표 수이며 달성 여부는 실행 뒤 python 집계).

사실(원본 바이트, python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030`; 역어셈블 `scratch/p745/orig_stage3.txt`):
1. 함수 안 명령 위치(함수 시작 기준, 합 116 B): 0 `moveml %d0-%sp,%sp@-` → 4 `movec %usp,%a0` → 8 `movel %a0,%sp@(60)` → 12 `lea %sp@(56),%fp` → 16 `bfextu %sp@(70){0:4},%d0`(`e9ef 0004 0046`, 6 B) → 22 `cmpil #2,%d0`(6 B) → 28 `bnes +2`(`6602`) → 30 `bras →3`(`6012`) → 32 `cmpil #10,%d0` → 38 `bnes`(`6602`) → 40 `bras →3`(`6008`) → 42 `cmpil #11,%d0` → 48 `bnes →4`(`6636`) → 50 `3:` 스택 점검 36 B → 86 `movel %a2,%sp@-` → 88 `subaw #12,%sp` → 92 `movel #12,%sp@-`(`2f3c 0000000c`) → 98 `bral 0x400217c`(`60ff 000001f6`) → 104 `4:` `pea 0x40ad994`(`4879`+4 B) → 110 `jsr 0x400bc66`(`_panic`; 함수의 끝 6 B).
2. NeXTMach 와 다른 점: (가) `subqw #4,sp`(`r_fsize` 칸)가 없음, (나) `movl sp,a6; addl #1,a6` 대신 `lea sp@(56),fp`, (다) 세 형식 분기에서 `movw #SIZEOF_*,sp@(FSIZE)` 3 줄이 없음(분기는 앞 두 비교가 `cmpl; bne; bra 3f` 꼴이고 셋째(`#11`)는 `bne 4f` 뒤에서 `3:` 으로 그대로 이어짐: 형식 2·10·11 = `EF_NORMAL6`(0x2)·`EF_SHORTBUS`(0xa)·`EF_LONGBUS`(0xb), `01_resources/upstream/nextmach/mk-108.1/next/reg.h:19,23,24`; `T_ADDRERR` 0xc `next/trap.h:20`; 원본 `movel #12` 와 일치), (라) `3:` 에 36 B 스택 점검(`movl sp,a2; cmpl #_eintstack,sp; jls …; movl _stack_pointers,a5; cmpl sp,a5; jcs …; subl #4084,a5; cmpl sp,a5; jcs …; movl _stack_pointers,sp`)이 더해지고 그 뒤 `movl a2,sp@-` 이 `subw #12,sp` 앞에 있음. 이 36 B 는 `std_trap`(0x4001b58–0x4001b7c)의 점검 블록과 **바이트가 같음**(python 비교 True; `244fbffc04001318631a2a79040b57ccbbcf650a9bfc00000ff4bbcf65062e79040b57cc`). 끝은 NeXTMach 와 같은 `pea 문자열; jsr _panic`(문자열 "addrerr: bad exception stack format" 36 B 는 0x40ad994, §744 에서 이미 자료 검사 통과).
3. 외부·지역 참조(python 의 기대 재배치 6 곳; 함수 시작 기준 위치→대상): 54→`_eintstack`(0x4001318, 지역), 62→`_stack_pointers`, 82→`_stack_pointers`, 100→`trap`(0x400217c, pc 상대 지역), 106→자료 0x40ad994(지역 자료, 이름 없음), 112→`_panic`.

설계(후보 `scratch/p747/locore_C4.s`; 생성기 `scratch/p747/gen_locore4.py` = §746 의 `gen_locore3.py` 실행 뒤 아래를 더함; 표시 `/* plan 747 (D167, D024) BEGIN: … */ … /* plan 747 END */`; 07 에는 쓰지 않음):
1. NeXTMach `addrerr` 본문에서 (가)–(라) 의 차이만 바꿉니다: `subqw #4,sp` 삭제; `movl sp,a6; addl #1,a6` → `lea sp@(R_A6),a6`; `movw #SIZEOF_*,sp@(FSIZE)` 3 줄 삭제; `3:` 뒤에 위 스택 점검(`std_trap` 과 같은 순서; 번호 레이블은 `1`–`4`·`1f`(문자열) 와 겹치지 않게 `5`·`6` 을 쓰되 `pea 1f` 의 `1f` 는 NeXTMach 그대로 뒤의 `.data 1:` 문자열을 가리키게 함). 나머지(`bfextu`·`cmpl`·`jra trap`·`pea 1f; jsr _panic`·`.data` 문자열)는 NeXTMach 그대로. 맞지 않게 된 NeXTMach 주석(`room for r_fsize`, `special fp for gdb`, `remember size of exception frame`)만 지웁니다.
2. 비교기 `scratch/p747/cmp5.py` = `scratch/p746/cmp4.py` 에 규칙 하나를 더함: 텍스트 재배치의 지역 자료 대상(`0x40ad964–0x40adb34`)은 이름이 없어도 객체 `__data` 안 거리가 `원본 주소 − 0x40ad964` 와 같아야 함(자료 배치는 `check_data2.py` 가 464 B 전체를 검사하므로 이 규칙과 합쳐 대상이 원본 문자열 위치인지 확인됨). 이 규칙을 넣은 뒤 먼저 C3 객체(`m4p746-p1`)의 41 항목에 다시 돌려 새 FAIL 이 있는지 보고하고(정정이 나오면 그대로 보고), `mutate_test.py` 에 "지역 자료 대상 거리 변경" 변형을 더해 시험합니다.
3. 변형 6 개를 한 번에 어셈블: C4(주), 음성 대조 N1(둘째 비교 `cmpl #EF_SHORTBUS` → `#EF_LONGBUS`: 바이트), N2(`jsr _panic` → `jsr _printf`: 외부 이름), N3(`jra trap` → `jra intr_rtn`: 지역 텍스트 레이블 이름), N4(`pea 1f` → `pea argc_table`: 지역 자료 대상 거리), N5(`subl #4084,a5` → `#4088`: 바이트). 명세 `08_build/artifacts/m4p747/spec_c4.json`, 실행 `scratch/p737/run.sh m4p747-p1 …`(`08_build/runs/REGISTRY` 에 `m4p747` 없음 확인함).
4. 철자 위험: `lea sp@(R_A6),a6`(§745 에서 같은 철자가 `4def 0038` 로 확인됨), `jcs`·`jls`·`subl #4084,a5`(§745 `std_trap` 에서 확인됨), `bfextu sp@(FMT){#0:#4},d0`(NeXTMach 철자; 이 후보 어셈블 결과의 바이트 `e9ef 0004 0046` 로 확인), `bne 1f; bra 3f` 의 짧은 분기 형(결과 바이트로 확인). 다르면 철자를 바꿔 다시 어셈블하고 각 시도를 기록합니다.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(6 변형 각각). (나) C4 에서 `addrerr` EQUAL, 새 비교기 `cmp5.py` 가 C4 의 42 항목에 `PASS 42 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 EQUAL 42 항목·2184 B, 기존 41 항목 퇴행 없음. (다) `addrerr` 의 재배치 6 곳이 기대와 위치·종류·길이·이름·가산값·지역 대상(`_eintstack`·`trap`·자료 거리)까지 일치. (라) N1–N5 각각이 `addrerr` 만 FAIL 이고 나머지 41 항목은 PASS(종료 코드 1). (마) `check_data2.py` `ALL PASS`(자료 불변); 원본 심볼표에 없는 정의된 전역 26 개 목록 불변; 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로; 정의 없는 이름에 새 항목 없음(C3 와 같은 집합). (바) 새 규칙을 넣은 `cmp5.py` 가 C3 의 41 항목에서도 `PASS 41`(아니면 그 결과를 정정 사유로 보고하며 기준은 되돌려 완화하지 않음). 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) 스택 점검 36 B 를 `std_trap` 과 `addrerr`(그리고 3c 의 `buserr`) 가 각각 따로 가지는 것으로 읽었을 뿐, 원본 소스에서 매크로였는지 직접 쓴 것인지는 바이트로 알 수 없습니다(소스 형태는 바이트가 정한 꼴만; 반복된 텍스트를 매크로로 묶는 것은 이 단계에서 하지 않음). (나) 의미(스택 범위 점검의 목적)는 추정이며 주석에 단정하지 않습니다. (다) `trap` 의 위치(0x400217c)는 3c 에서 `buserr` 와 함께 정해지므로 지금은 이름만 확인합니다. (라) `SIZEOF_*`·`FSIZE` 상수는 `buserr`(3c) 가 아직 NeXTMach 텍스트로 쓰므로 머리 블록에서 지우지 않습니다.

### 747.1 §747 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 사실 2 (다)에서 `cmpl; bne; bra 3f` 꼴이 세 분기 모두인 듯 적음(셋째 `#11` 은 `bne 4f` 뒤에서 `3:` 으로 이어짐; 본문 고침). (2) §746 의 `cmp4.py` 지역 자료 대상 검사가 이름 없는 대상의 거리·섹션 내부 여부를 보지 않음: 아래에서 재현(제가 §746 에서 "자료 거리"를 규칙으로 넣지 않았음). (3) `mutate_test.py` 가 `cmp4.py` 를 하드코딩해 새 비교기를 시험하지 못함, `scattered`·겹침·경계 침범 변형 시험이 없었음.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 짧은 분기 목표: 0x4001f3e `6602`→0x4001f42, f40 `6012`→f54, f48 `6602`→f4c, f4a `6008`→f54, f52 `6636`→f8a | python 으로 각 주소 바이트를 읽고 `주소+2+변위` 계산 | ✅ |
| 상수 `cmpil #2`·`#10`·`#11`, `movel #12,%sp@-`; `EF_NORMAL6` 0x2·`EF_SHORTBUS` 0xa·`EF_LONGBUS` 0xb(`reg.h:19,23,24`)·`T_ADDRERR` 0xc(`trap.h:20`) | python 바이트 `0c8000000002`·`0c800000000a`·`0c800000000b`·`2f3c0000000c`; grep 출력으로 상수 4 개 확인(이번 세션) | ✅ |
| 36 B 스택 점검 블록이 `addrerr`[0x4001f54,0x4001f78) 와 `std_trap`[0x4001b58,0x4001b7c) 에서 같음 | python 비교 True | ✅ |
| 기대 재배치 6 곳(54·62·82·100·106·112) | 앞서 `cmp4.expected()` 로 얻은 목록과 같음(python) | ✅ |
| 번호 레이블: 스택 점검의 참조와 정의를 함께 `5`·`6` 으로(`jls 5f`, `jcs 6f`, `jcs 5f`, `6:` 시작 +80, `5:` +86), `std_trap` 의 `1f`·`2f` 복사 금지 | 원본의 세 분기 목표(0x4001f78 `blss`, 0x4001f72 `bcss`, 0x4001f78 `bcss`; §747 의 역어셈블)와 비교해 맞음; 아래 §747.2 3 에 배치를 명시(`6:` 가 `movl _stack_pointers,sp` 앞, `5:` 가 `movl a2,sp@-` 앞) | ✅ §747.2 에 명시 |
| C3 객체 선례: `bra 3f` 가 짧은 `601e`·`600e`, `jra trap` 이 `60ff`, `pea 1f` 가 `__data` 거리 48 | 이번 세션에 `Q746__locore_C3.o` 의 `addrerr` 를 역어셈블해 `601e`·`600e`·`60ff 000001be`·`4879` 를 직접 확인(거리 48 은 codex 계산을 받음: 0x40ad994−0x40ad964=48 은 python 확인 가능한 산술) | ✅ |
| `cmp4.py` 가 이름 없는 자료 대상의 거리·섹션 내부 여부를 안 봄(150→152, 150→16, 150→464 모두 통과) | 제가 같은 변형을 직접 재현: C3 의 `fpsp_frame_err` 지역 자료 재배치 거리를 150→150·152·16·464 로 바꿔 `cmp4.run` → 모두 `[]`(FAIL 없음) | ✅ |
| 보강: `buserr − addrerr == 116`, 새 규칙의 음성 대조, `mutate_test.py` 가 새 비교기를 쓰게, `scattered`·겹침·경계 침범 전용 변형 | 위 재현과 `mutate_test.py:5` 하드코딩을 열어 확인 | ✅ 채택 |
| 최종 재배치 변위는 원본 `000001f6` 을 요구하면 안 됨(객체 변위는 `000001be`) | 맞음: `cmp4.py` 는 `pcrel` 지역 대상이 함수 밖이면 레이블 이름만 보고 변위는 보지 않음(C3 의 `addrerr` 가 이미 그렇게 통과) | ✅ 계획 그대로 |
| 수치 116·42·2184·36·6 | 앞서 python 으로 같은 값 | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. "거리 48"은 같은 산술을 계획에 이미 적었던 값입니다.

### 747.2 §747 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. `cmp5.py`(= `cmp4.py` + 규칙): 텍스트 재배치의 지역 자료 대상은 이름 유무와 관계없이 섹션 상대 거리 `T == 원본 대상 주소 − 0x40ad964` 이고 `T` 가 `__data` 크기 안에 있어야 함(기존 섹션·이름 검사는 유지). 먼저 C3 의 41 항목에 돌려 결과를 보고하고(새 FAIL 이 나오면 정정 사유로 보고), `mutate_test.py` 는 시험할 비교기 모듈 경로를 인자로 받게 고쳐 `cmp5.py` 로 §746 의 9 변형을 다시 돌리고, 새 변형 4 가지를 더함: (가) 이름 없는 지역 자료 대상 거리 +2, (나) `argc_table` 거리(16)로 변경, (다) 섹션 끝 밖(464)으로 변경, (라) `scattered` 표시, (마) 한 항목 안 겹치는 재배치 추가(위치+2), (바) 항목 끝에 걸치는 재배치. 모두 의도한 항목만 FAIL.
2. 판정 기준 추가: (사) C4 객체에서 `buserr − addrerr == 116`(객체 레이블 간격; 항목 끝의 여분 명령 배제). (아) 위 1 의 시험이 `cmp5.py` 로 모두 통과.
3. 스택 점검의 레이블 배치(소스): `3: movl sp,a2; cmpl #_eintstack,sp; jls 5f; movl _stack_pointers,a5; cmpl sp,a5; jcs 6f; subl #4084,a5; cmpl sp,a5; jcs 5f; 6: movl _stack_pointers,sp; 5: movl a2,sp@-` (`6:` 는 함수 시작 +80, `5:` 는 +86 이어야 함; `std_trap` 의 `1f`·`2f` 를 복사하지 않고 참조와 정의를 함께 `5`·`6` 으로 씀).

### 747.3 결과: 3b 단계 후보 C4 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p747/gen_locore4.py`(§746 의 `gen_locore3.py` 를 실행한 뒤 `addrerr` 를 `plan 747 (D167, D024) BEGIN/END` 표시로 바꿈; 후보 6 개 `scratch/p747/locore_{C4,N1,N2,N3,N4,N5}.s`), 비교기 `scratch/p747/cmp5.py`(§746 의 `cmp4.py` + 지역 자료 대상 거리 규칙), 변형 시험 `scratch/p747/mutate_test2.py`(비교기 모듈 경로를 인자로 받음; 변형 15 가지), 항목 목록 `scratch/p747/ents42.json`, 명세 `08_build/artifacts/m4p747/spec_c4.json`. 실행: `m4p747-p1`(6 변형 어셈블; 종료 코드 12 개 모두 0, 표준 오류 0 B).

사전 확인(§747.2 1): 새 규칙을 넣은 `cmp5.py` 를 C3 객체(`m4p746-p1`)의 41 항목에 돌림 → `PASS 41 FAIL 0`(정정할 것 없음). `mutate_test2.py` 를 `cmp5.py` 로 C3 에 돌림: §746 의 9 변형 + 새 6 변형(이름 없는 자료 대상 거리 +2·`argc_table` 거리 16·섹션 밖 464·`scattered`·겹침 추가·`trap5` 끝에 걸침) 모두 의도한 항목만 FAIL(`ALL OK`). `trap5` 끝에 걸치는 재배치는 `trap6` 의 시작도 덮으므로 두 항목이 모두 FAIL 하는 것을 기대값으로 함(처음 시험은 기대값이 `trap5` 하나라 BAD 로 나와 시험 기대값을 고침; 비교기 동작은 정당).

변경 요약: `addrerr` 에서 `subqw #4,sp` 와 `movw #SIZEOF_*,sp@(FSIZE)` 3 줄을 지우고, `movl sp,a6; addl #1,a6` 를 `lea sp@(R_A6),a6` 로 바꾸고, `3:` 뒤에 `std_trap` 과 같은 36 B 스택 점검(레이블 `5`·`6`; §747.2 3 의 배치)을 더함. `bfextu`·`cmpl`·`jra trap`·`pea 1f; jsr _panic`·`.data` 문자열은 NeXTMach 그대로. 철자는 첫 시도에서 모두 원본과 같아 바꾸지 않았습니다(두 `bra 3f` → `6012`·`6008`).

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(6 변형 모두, 종료 코드 12 개 0, 표준 오류 0 B).
- (나) C4: `addrerr` EQUAL, `cmp5.py` `PASS 42 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 `Counter({'EQUAL': 42, 'NO-OBJ-NAME': 14, 'DIFF': 2})`·`EQUAL entries 42 bytes 2184`, 기존 31 항목 퇴행 없음(`cmp3.py` 31/31). 독립 확인: 객체 `addrerr`–`buserr` 직전 116 B 와 원본의 차이 19 B 는 전부 재배치 필드 6 곳 안, 필드 밖 차이 0.
- (다) `addrerr` 재배치 6 곳(54·62·82·100·106·112)이 기대와 위치·종류·길이·이름·가산값·지역 대상(`_eintstack`·`trap`·자료 거리 48)까지 일치(`cmp5.py`).
- (라) N1(`EF_LONGBUS`) `bytes differ at [37]`, N2(`_printf`) `@112 extern _printf expected ['_panic']`, N3(`intr_rtn`) `@100 local label ['intr_rtn'] expected trap`, N4(`argc_table`) `@106 data target offset 16 expected 48`, N5(`#4088`) `bytes differ at [75]`: 모두 `addrerr` 만 FAIL, 종료 코드 1, 나머지 41 항목 PASS.
- (마) `check_data2.py` `ALL PASS`(11 개, 종료 코드 0); 원본 심볼표에 없는 정의된 전역 26 개 목록 불변; 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로; 정의 없는 이름 집합이 C3 와 같음(새 항목·사라진 항목 없음, 46 개).
- (바) `cmp5.py` 가 C3 의 41 항목에서 `PASS 41`.
- (사) 객체에서 `buserr − addrerr` = 116(python). (아) 위 변형 시험 `ALL OK`.

한계: (가) 스택 점검 36 B 가 `std_trap`·`addrerr`(3c 에서 `buserr`)에 반복되는 것을 매크로로 묶을지는 바이트로 알 수 없어 반복 텍스트로 두었습니다. (나) 스택 점검의 의미는 추정이며 주석에 단정하지 않았습니다. (다) `trap` 의 위치는 3c 에서 `buserr` 와 함께 정해지므로 지금은 이름만 확인했습니다(객체에서 `trap6`→`addrerr` 간격 160 B 는 NeXTMach `trap0` 등이 남은 자리; 단위 전체 순서는 뒤에서). (라) 이 후보는 07 에 올리지 않았습니다. 남은 DIFF 2 개는 `_intstacks`(`entry`)와 `buserr` 입니다.


## 계획 748: m68k `locore.s` 구현 3c 단계 — `buserr`(+ `trap`·`intr_rtn`·`softint_rtn` 구간) (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §747.3 의 남은 DIFF 2 개 중 `buserr`(0x4001f96–0x400221e, 648 B)는 원본 함수표에서 한 항목이며 NeXTMach 의 `buserr`·`badfault`·`access`·`short_bus`·`long_bus`·`inst_fault`·`data_fault`·`call_trap`·`not_mmu`·`mmu_type`·`trap`·`trap_rtn`·`intr_rtn`·`softint_rtn` 이 이어진 구간과 **같은 순서**입니다(NeXTMach 후보 소스 `scratch/p747/locore_C4.s` 의 `buserr:` 이후를 열어 비교). 따라서 새로 쓰는 것이 아니라 NeXTMach 텍스트에서 아래 차이만 바꿉니다. 이 단계가 성공하면 EQUAL 목표는 42 + 1 = 43 항목, 2184 + 648 = 2832 B 입니다(목표 수이며 달성 여부는 실행 뒤 python 집계). 남은 DIFF 는 `_intstacks`(`entry`) 하나가 됩니다.

사실(원본 바이트, python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030`; 역어셈블 `scratch/p745/orig_stage3.txt`; 함수 시작 0x4001f96 기준 거리는 python 계산):
1. 레이블 거리: `buserr` 0 → "bad exception stack format" `pea` +58 → `badfault`(`pea 0x40ad9dc; jsr _panic`) +70 → `access` +82 → `short_bus` +194 → `long_bus` +250 → `inst_fault` +298 → `data_fault` +322 → `call_trap` +342 → `not_mmu` +450 → `mmu_type`(텍스트 안 6 longs `0x400 0x404 0x408 0 0x40c 0x410`, 24 B) +462 → `trap` +486(0x400217c: `addql #1,0x40b5654; jsr 0x40996b8`) → (`trap_rtn` 에 해당하는 +498 은 원본에서 참조하는 곳이 없음: python 으로 텍스트 전체에서 0x4002188 의 절대·pc 상대 참조 0 곳) → `5:` +530 → `intr_rtn` +566 → `softint_rtn` +572 → 끝 +648(`fpsp_done` 시작).
2. NeXTMach 와 다른 점(역어셈블 비교로 읽음):
   (가) `buserr`: `subqw #4,sp` 없음, `lea sp@(56),fp`(R_A6); 분기는 `cmpil #7,%d0; beql access`·`#10 → short_bus`·`#11 → long_bus`(긴 조건 분기 `67ff`+4 B; `EF_ACCESS` 7).
   (나) `access`(+82): `movw #SIZEOF_ACCESS,sp@(FSIZE)` 없음; `moveq #8,%d2`(`T_BUSERR`)·`moveal %sp@(84),%a0`·`moveq #3,%d0` 이후 NeXTMach 와 같은 흐름이고, `movl #1040,d2`(`T_MMU_INVALID` 0x410, `243c`+4 B) 뒤 `2:` 에서 **스택 점검 36 B(앞의 `std_trap` 것과 같은 바이트) + `movel %a2,%sp@-`** 을 하고 그 뒤 `a0`·`d0`·`d1`·`d2` 를 밀어 넣고 `bral trap`.
   (다) `short_bus`·`long_bus`: `movw #SIZEOF_*,sp@(FSIZE)` 없음, 나머지 같은 분기(`bnel data_fault`·`beql badfault`·`bral inst_fault`, `FAULTD_BIT-8`=0 등은 `btst #0,%sp@(74)`·`#6`·`#7`).
   (라) `inst_fault`·`data_fault`: NeXTMach 와 같은 흐름(`moveq #1,%d2; moveq #2,%d1`(`FC_USERI`); `btst #5,%sp@(64)`; `moveq #6,%d1`(`FC_SUPERI`); `bfextu %sp@(75){0:2},%d2`).
   (마) `call_trap`: `2:` 뒤에 위 스택 점검 36 B + `movel %a2,%sp@-` 이 추가되고 이어 `a0`·`d0`·`d1` 을 밀고 `pmove %psr,mmu_status`(`f039 6200`+`040ad9f8`, 8 B)·`bfffo mmu_status{0:6},%d0`(`edf9 0006`+4 B)·`beql not_mmu`·`lea mmu_type,%a0`·`movel %a0@(0,%d0:w:4),%sp@-`·`bral trap`; `not_mmu: movel #8,%sp@-; bral trap`.
   (바) `trap`: `jsr _trap`(0x40996b8) 뒤 `addl #16,sp` 가 없음. 이어서 NeXTMach 의 `trap_rtn` 전체(`CPU_NUMBER`·AST 처리·`FSIZE`)가 없고 대신: `btst #5,%a2@(64); bnes →2; moveal %a2@(60),%a0; movec %a0,%usp; 2: tstl %d0; bnes →5; moveal %a2,%sp; moveml %sp@,%d0-%fp; addaw #64,%sp; rte; 5: moveal %a2,%a0; addal %d0,%a0; movel %a2@(66),%a0@(66); movew %a2@(64),%a0@(64); clrw %a0@(70); movel %a0,%a2@(60); moveal %a2,%sp; moveml %sp@,%d0-%sp; addaw #64,%sp; rte`(곧 `d0` 가 되돌아온 프레임 크기 차).
   (사) `intr_rtn`: `addql #1,0x40b565c`(`_cnt`+12 `V_INTR`)만(`EVENTMETER` 코드 없음). `softint_rtn`: `btst #5,%a2@(64); bnes →2; moveal 0x40b5648,%a0; tstl %a0; beqs →2; moveal %a0@(36),%a0; btst #4,%a0@(84); beqs →2; moveal 0x40b57cc,%sp; movel %a2,%d0; movel %d0,%sp@-; jsr 0x409a2fe(_check_for_ast); lea 0x4001318,%sp; moveal %a2@(60),%a0; movec %a0,%usp; 2: oriw #1792,%sr; moveal %a2,%sp; moveml %sp@,%d0-%fp; addaw #64,%sp; rte`(`movel %a2,%sp` 로 시작하지 않고 AST 검사에 `_active_threads` 직접·`tstl a0` 널 검사).
3. 기대 재배치(`cmp5.expected()` python 목록): 36 곳(pc 상대 지역 16 + 절대 지역 텍스트 4 + 지역 자료 4 + 외부 12) — pc 상대 지역 16 곳(위치 30·42·54 → `access`·`short_bus`·`long_bus`; 190·446·458 → `trap`; 202·258 → `data_fault`; 222·246·276 → `inst_fault`; 234·288 → `badfault`; 310·318 → `call_trap`; 430 → `not_mmu`), 절대 지역 텍스트 `_eintstack` 3 곳(146·372·620)과 `mmu_type`(436), 자료 필드 4 곳(60 → 0x40ad9b8, 72 → 0x40ad9dc, 416·424 → 0x40ad9f8 `mmu_status`; 대상 주소는 3 가지), 외부 `_panic`(66·78)·`_stack_pointers`(154·174·380·400·604)·`_trap`(494)·`_active_threads`(582)·`_check_for_ast`(614)와 `_cnt`+4(488)·`_cnt`+12(568). 원본 `__text` 재배치 레코드는 0 이므로 이것은 원본 명령에서 만든 기대 목록입니다.

설계(후보 `scratch/p748/locore_C5.s`; 생성기 `scratch/p748/gen_locore5.py` = §747 의 `gen_locore4.py` 실행 뒤 아래를 더함; 표시 `/* plan 748 (D167, D024) BEGIN: … */ … /* plan 748 END */`; 07 에는 쓰지 않음):
1. NeXTMach `buserr` 구간에서 (가)–(사) 의 차이만 바꿈: `subqw #4,sp`·`movw #SIZEOF_*,sp@(FSIZE)` 3 곳 삭제; `movl sp,a6; addl #1,a6` → `lea sp@(R_A6),a6`; `access` 와 `call_trap` 의 `2:` 뒤에 36 B 스택 점검(§747.2 3 의 레이블 배치; 이 두 곳은 번호 레이블 `1`·`2` 가 겹치지 않게 `5`·`6` 을 새로 정의하므로 각 곳의 참조와 정의를 함께 씀) 과 `movl a2,sp@-` 추가; `trap` 의 `addl #16,sp` 삭제와 `trap_rtn` 이하를 원본 순서로 새로 씀(레이블 `trap_rtn` 은 NeXTMach 이름 그대로 두되 원본 텍스트 전체에서 직접 참조(절대·pc 상대)가 0 곳인 레이블; 간접 계산에 의한 참조 여부는 미확인); `softint_rtn` 을 위 사실 (사)로 새로 씀. 맞지 않게 된 NeXTMach 주석(`room for r_fsize`, `remember size of exception frame`, `special fp for gdb`, `pop type, fcode, rw and faultaddr`, AST/`CPU_NUMBER` 설명)은 지우고 `#if NIPLMEAS`·`#if EVENTMETER` 조각은 원본에 코드가 없으므로 지움. 나머지(`bfextu`·`ptest` `.long` 두 개·`pmove` `.long`·`bfffo`·`mmu_type` 표·`.data` 문자열 3 개·`mmu_status` `.data`)는 NeXTMach 그대로. 의미는 단정하지 않음.
2. 머리 `#define` 블록: `SIZEOF_ACCESS`·`SIZEOF_SHORTBUS`·`SIZEOF_LONGBUS`·`FSIZE` 는 이 단계가 마지막 사용처를 지우므로 쓰는 자리가 없어짐 — 지울지는 단위 전체 정리 단계에서 한꺼번에 결정(이 단계에서는 그대로 둠; 어셈블러가 안 쓰는 `#define` 은 객체에 영향 없음).
3. 비교기 `scratch/p748/cmp6.py` = `cmp5.py` + (가) 함수 안 지역 대상도 이름이 알려진 것(`trap`·`intr_rtn`·`softint_rtn` 와 아래 내부 레이블 이름)이면 객체 쪽 레이블 이름이 같아야 함, (나) 객체 레이블 위치: `buserr` 기준 `badfault` +70·`access` +82·`short_bus` +194·`long_bus` +250·`inst_fault` +298·`data_fault` +322·`call_trap` +342·`not_mmu` +450·`mmu_type` +462·`trap` +486·`trap_rtn` +498·`intr_rtn` +566·`softint_rtn` +572 (이 이름들은 NeXTMach 소스 이름이며 원본에는 없음: "이름 미확인, 위치는 일치 검사"), (다) 객체에서 `addrerr`→`buserr` 116, `buserr`→`fpsp_done` 648. 먼저 C4 객체(`m4p747-p1`)의 42 항목에 돌려 새 FAIL 이 있는지 보고(정정이 나오면 그대로 보고).
4. 변형 10 개(C5 + 음성 대조 N1–N9)를 한 번에 어셈블: C5(주), 음성 대조 N1(`cmpl #EF_ACCESS,d0` → `#EF_SHORTBUS`: 바이트), N2(`jsr _trap` → `jsr _panic`: 외부 이름), N3(`short_bus` 의 `bne data_fault` → `bne call_trap`: 함수 안 지역 대상), N4(`.long mmu_status` → `.long argc_table`: 자료 대상 거리), N5(`intr_rtn:` 앞에 `nop` 한 줄: 함수 길이·레이블 위치 오류), N6(`softint_rtn` 의 마지막 `rte` 뒤 `nop`: 함수 끝 여분), N7(`call_trap` 의 스택 점검 `jcs 6f` → `jcs 5f`: 점검 분기 오류), N8(`access:` 정의와 `jeq access` 참조를 함께 `access_x` 로 바꿈: 코드·재배치 거리는 그대로이고 이름만 다름 → 내부 레이블 이름 검사 시험), N9(`trap_rtn:` 레이블을 첫 `btst` 다음 줄로 옮김: 코드는 그대로이고 레이블 위치만 다름 → 레이블 위치 검사 시험). 명세 `08_build/artifacts/m4p748/spec_c5.json`, 실행 `scratch/p737/run.sh m4p748-p1 …`(`08_build/runs/REGISTRY` 에 `m4p748` 없음 확인함).
5. 철자 위험(바이트로 확인): `jeq access`·`bne data_fault`·`beq badfault`·`bra inst_fault` 등 정의가 뒤에 오는 기호 레이블로의 분기가 NeXT `as` 에서 `67ff`/`66ff`/`60ff` 긴 형인지(NeXTMach 후보 객체에서 이미 긴 형으로 나옴: C3 객체 `addrerr` 가 `bral 0x210`; 조건 분기는 미확인), `movl a2,d0` → `200a`, `tstl a0` → `4a88`, `addl d0,a0` → `d1c0`, `movl a2,a0` → `204a`, `orw #0x700,sr` → `007c 0700`(§745 확인), `lea _eintstack,sp` → `4ff9`(§745 확인). 어긋나면 철자를 바꿔 다시 어셈블하고 각 시도를 기록.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(10 변형 각각). (나) C5 에서 `buserr` EQUAL, `cmp6.py` 가 C5 의 43 항목에 `PASS 43 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 EQUAL 43 항목·2832 B, 기존 42 항목 퇴행 없음. (다) `buserr` 의 재배치 36 곳이 기대와 위치·종류·길이·이름·가산값·지역 대상(내부 레이블 이름·함수 안 거리·`_eintstack`·`mmu_type`·자료 거리)까지 일치. (라) 객체 레이블 위치 검사(사실 1 의 거리 12 개 + `trap_rtn`)와 `addrerr`→`buserr` 116·`buserr`→`fpsp_done` 648 모두 일치. (마) N1–N9 각각이 `buserr` 만 FAIL(N5·N6 은 길이·레이블 위치 검사, N8 은 내부 레이블 이름 검사, N9 는 레이블 위치 검사에서; 종료 코드 1)이고 나머지 42 항목은 PASS. (바) `check_data2.py` `ALL PASS`(자료 불변: 문자열 3 개·`mmu_status`); 원본 심볼표에 없는 정의된 전역 26 개 목록 불변; 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로; 정의 없는 이름 집합이 C4 와 같음(새 항목은 없어야 하며 `_ipl_rte`·`_event_intr` 같은 NeXTMach 외부 이름이 사라지면 그 사라진 목록을 보고). (사) `cmp6.py` 가 C4 의 42 항목에서도 `PASS 42`. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) 스택 점검 36 B 가 `std_trap`·`addrerr`·`access`·`call_trap` 에서 반복되는 것은 바이트로 매크로 여부를 알 수 없어 반복 텍스트로 둡니다(소스 형태는 바이트가 정한 꼴만). (나) `trap`·`trap_rtn`·`intr_rtn` 등 내부 레이블 이름은 NeXTMach 이름이며 원본에는 이름이 없습니다(위치만 검사). (다) `d0` 의 의미(프레임 크기 차)·AST 검사 위치 등 의미는 바이트에서 읽은 추정이며 주석에 단정하지 않습니다. (라) `mmu_status` 자료와 `ptest`/`pmove` `.long` 두 형식은 NeXTMach 와 같은 바이트로 나온다고 읽었으나 원본의 소스 철자는 알 수 없습니다. (마) 이 후보는 07 에 올리지 않으며, `trap0`·`syscall_*` 등 NeXTMach 전용 텍스트는 객체에 남아 단위 전체 순서는 아직 원본과 다릅니다.

### 748.1 §748 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 사실 3 의 집계 오기: pc 상대 지역을 17 곳(실제 16), 자료를 3 곳(재배치 필드는 4 곳)으로 적음(본문 고침; python 집계 `Counter({'pcrel': 16, 'abs external': 12, 'abs data': 4, 'abs local text': 4})` = 36). (2) 변형 개수를 7 개로 적음(C5 와 음성 대조의 합이 8 개였고 이번 보강으로 10 개). (3) `trap_rtn` "참조 없음"을 직접 참조 검색 결과보다 넓게 단정(본문을 "직접 참조 0, 간접 계산 미확인"으로 고침). (4) §747 의 `cmp5.py` 결함: `scattered` 재배치에 `extern`·`symbolnum` 키가 없어 `KeyError` 가 남(재현은 아래), `mutate_test2.py` 의 `scattered` 변형은 일반 레코드에 플래그만 바꿔 이를 놓침. (5) 음성 대조가 새 이름 검사·위치 검사를 따로 시험하지 못함.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 레이블 거리 +58·70·82·194·250·298·322·342·450·462·486·498·530·566·572·632·648 | python 계산(앞서 같은 값) | ✅ |
| (바) `trap`→`trap_rtn` 이하·(사) `softint_rtn`·(나) `access`·(마) `call_trap`·`inst_fault`·`data_fault`·`not_mmu`·`mmu_type` 24 B 의 명령열·push 순서 | python 으로 각 주소 바이트를 hex 비교(`0x400217c`·`0x4002188`·`0x40021a8`·`0x40021cc`·`0x40021d2`·`0x400220e`·`0x4001fe8`·`0x400212a`·`0x4002158`·`0x40020c0`·`0x40020d8` 전부 True; `call_trap` 앞 한 줄은 제 시험 문자열 오타(`0822`; 실제 `0802 0001`)였고 바이트는 계획대로) | ✅ |
| 스택 점검 36 B 가 `access`(+142)·`call_trap`(+368) 에서 `std_trap`·`addrerr` 와 같음 | 앞서 `addrerr` 와 `std_trap` 의 36 B 를 python 비교(True); `access`·`call_trap` 의 36 B 는 `0x4001fe8`+60·`0x40020ec`+… 의 바이트를 이번 세션에 hex 비교한 범위(`0x4002106 244f`·`0x400212a 2f0a…`) 밖이라 이번 단계의 `cmp6.py` 실행 결과(재배치 위치 146·154·174, 372·380·400 와 바이트 일치)로 확인하기로 함 | ✅ (사후 python: `buserr`+142=0x4002024 와 +368=0x4002106 의 36 B 가 `std_trap` 블록과 같음 — 위 값 True) |
| 조건 분기 선례: C4 객체 `jeq access`→`67ff…`, `bne data_fault`→`66ff…`, `beq badfault`→`67ff ffff ff76`(앞에 정의된 것이므로 "뒤에 정의되는" 묶음에서 제외), `bra inst_fault`→`60ff…`, `f039 6200 0000 21d8` | 이번 세션에 C4 객체 `buserr` 를 역어셈블해 `beql`·`bnel`·`bral`·`beql 0x48`(뒤로)·`pmove`·`bfffo` 행을 직접 확인(`scratch/p747/obj_buserr.bin`) | ✅ (일반 규칙으로 확대하지 않음) |
| 기대 재배치 36 곳 위치·종류·대상, 8 B 명령 연속행 처리 | python `cmp5.expected()` 집계; objdump 연속행 병합은 §747 에서 쓰고 있었고 `+416`·`+424` 위치가 목록에 있음 | ✅ |
| `cmp5.py:71` 이 `scattered` 에 대해 오류를 적고도 `r['extern']` 을 읽어 `KeyError` | `macho_obj.relocs` 를 열어 `scattered=True` 레코드가 `address·type·length·pcrel·value` 만 가짐을 확인; `cmp5.py:71` 이 오류만 적고 계속 진행하는 것도 확인; 실제 레코드를 직렬화한 재현은 아래 `mutate_test3.py` 에서 | ✅ (재현은 실행에서) |
| 이름 검사·위치 검사 전용 음성 대조 필요, N6 유지, 구조 변형 시험을 새 비교기로 재실행, cmp6 의 새 규칙은 `buserr` 를 검사할 때만 적용 | 계획 본문과 C4 객체의 `buserr`→`fpsp_done` 650 B(python)를 확인 | ✅ 채택 |
| 수치 648·43·2832·36 | python | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. `access`·`call_trap` 의 36 B 동일성은 위 표의 ⚖️ 처럼 실행 결과로 확인하는 항목으로 남겼습니다.

### 748.2 §748 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. `cmp6.py` = `cmp5.py` + 규칙: (가) 내부 레이블 이름·위치(사실 1 의 거리)와 `addrerr`→`buserr` 116·`buserr`→`fpsp_done` 648 검사는 검사 대상 목록에 `buserr` 가 있을 때만 적용(C4 의 42 항목 회귀검사와 양립; 구조 오류는 `buserr` 결과에 귀속), (나) `scattered` 레코드는 오류를 적고 그 레코드를 건너뜀(`KeyError` 없음).
2. `mutate_test3.py`: `mutate_test2.py` 의 변형 15 가지를 `cmp6.py` 로 다시 돌리되 `scattered` 변형을 **실제 scattered 레코드를 객체 바이트로 직렬화해 다시 파싱**하는 방식으로 바꾸고, 새 변형 2 가지(내부 레이블 이름 변경·`trap_rtn` 위치 이동)를 더함. 모두 의도한 항목만 FAIL, 종료 코드는 해당 항목에서 1.
3. 판정 기준 추가: (아) 위 변형 시험 `ALL OK`(처음에 현재 `cmp5.py` 로 실제 scattered 레코드를 넣어 `KeyError` 가 나는 것을 재현해 기록한 뒤 `cmp6.py` 로 정상 FAIL 보고가 됨을 확인).

### 748.3 결과: 3c 단계 후보 C5 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p748/gen_locore5.py`(§747 의 `gen_locore4.py` 를 실행한 뒤 `buserr`–`softint_rtn` 구간을 `plan 748 (D167, D024) BEGIN/END` 표시로 바꿈; 후보 10 개 `scratch/p748/locore_{C5,N1…N9}.s`), 비교기 `scratch/p748/cmp6.py`(§747 의 `cmp5.py` + `scattered` 처리 + `buserr` 내부 레이블 이름·위치·함수 간격 규칙), 변형 시험 `scratch/p748/mutate_test3.py`, 항목 목록 `scratch/p748/ents43.json`, 명세 `08_build/artifacts/m4p748/spec_c5.json`. 실행: `m4p748-p1`(10 변형 어셈블; 종료 코드 20 개 모두 0, 표준 오류 0 B).

사전 확인(§748.2): (1) 현재 `cmp5.py` 에 실제 scattered 레코드(객체 바이트로 직렬화해 다시 파싱)를 넣으면 `KeyError: 'extern'` 이 나는 것을 C4 객체의 `ipl2` 로 재현했고, `cmp6.py` 는 같은 입력에서 `ipl2` 만 `bad type/length/scattered (0, 2, True)` 로 FAIL 보고합니다. (2) `cmp6.py` 를 C4 객체의 42 항목에 돌림 → `PASS 42 FAIL 0`(정정할 것 없음; `buserr` 규칙은 목록에 `buserr` 가 있을 때만 적용). (3) `mutate_test3.py` 를 C5 에 돌림: §747 의 15 변형(scattered 는 실제 레코드 방식으로 교체) + 새 2 변형(내부 레이블 이름 변경·`trap_rtn` 위치 이동) 모두 의도한 항목만 FAIL(`ALL OK`).

변경 요약(NeXTMach 텍스트에서 바이트가 요구한 부분만): `buserr` 의 `subqw #4,sp` 삭제와 `lea sp@(R_A6),a6`; `access`·`short_bus`·`long_bus` 의 `movw #SIZEOF_*,sp@(FSIZE)` 삭제; `access` 와 `call_trap` 의 `2:` 뒤에 36 B 스택 점검(레이블 `5`·`6`)과 `movl a2,sp@-`; `trap` 의 `addl #16,sp` 삭제와 `trap_rtn` 이하·`softint_rtn` 을 원본 순서로 새로 씀(`trap_rtn` 레이블은 NeXTMach 이름 그대로, 직접 참조 0 곳; `orw #0x700,sr`; `_cnt+V_INTR`). 나머지는 NeXTMach 그대로. 철자는 첫 시도에서 모두 원본과 같아 바꾸지 않았습니다(긴 조건 분기 `67ff`·`66ff`, `tstl a0`→`4a88`, `addl d0,a0`→`d1c0`, `movl a2,a0`→`204a` 등).

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(10 변형 모두, 종료 코드 20 개 0, 표준 오류 0 B).
- (나) C5: `buserr` EQUAL, `cmp6.py` `PASS 43 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 `Counter({'EQUAL': 43, 'NO-OBJ-NAME': 14, 'DIFF': 1})`·`EQUAL entries 43 bytes 2832`, 기존 31 항목 퇴행 없음(`cmp3.py` 31/31). 독립 확인: 객체 `buserr`–`fpsp_done` 직전 648 B 와 원본의 차이 74 B 는 전부 재배치 필드 36 곳 안이며 필드 밖 차이 0.
- (다) `buserr` 재배치 36 곳이 기대와 위치·종류·길이·이름·가산값(`_cnt`+4·+12)·지역 대상(내부 레이블 이름·함수 안 거리·`_eintstack`·`mmu_type`·자료 거리 148 등)까지 일치.
- (라) 객체 레이블 위치: `badfault` +70·`access` +82·`short_bus` +194·`long_bus` +250·`inst_fault` +298·`data_fault` +322·`call_trap` +342·`not_mmu` +450·`mmu_type` +462·`trap` +486·`trap_rtn` +498·`intr_rtn` +566·`softint_rtn` +572 모두 원본 거리와 같음; `addrerr`→`buserr` 116, `buserr`→`fpsp_done` 648.
- (마) 음성 대조(모두 `buserr` 만 FAIL, 종료 코드 1): N1(`EF_SHORTBUS`) `bytes differ at [27]`; N2(`jsr _panic`) `@494 extern _panic expected ['_trap']`; N3(`bne call_trap`) `@202 in-entry target distance 342 expected 322` + `internal label … expected data_fault`; N4(`.long argc_table`) `@416 data target offset 16 expected 148`; N5(`nop` 추가) 재배치 위치 불일치; N6(끝 `nop`) `fpsp_done-buserr = 650 expected 648`(앞 648 B 는 같아 길이 검사만 잡음); N7(`jcs 5f`) `bytes differ at [387]`; N8(`access_x`) `internal label ['access_x'] expected access; label access missing`; N9(`trap_rtn` +6) `label trap_rtn at +504 expected +498`. 나머지 42 항목은 모두 PASS.
- (바) `check_data2.py` `ALL PASS`(11 개, 종료 코드 0); 원본 심볼표에 없는 정의된 전역 26 개 목록 불변; 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로; 정의 없는 이름 집합이 C4 와 같음(46 개; 새 항목·사라진 항목 없음: `_ipl_rte`·`_event_intr` 는 `NIPLMEAS`·`EVENTMETER` 조건 밖이라 애초에 없음).
- (사) `cmp6.py` 가 C4 의 42 항목에서 `PASS 42`. (아) 변형 시험 `ALL OK`.
- §748.1 의 ⚖️ 항목(스택 점검 36 B 동일성)은 사후 python 으로 `buserr`+142·+368 의 36 B 가 `std_trap` 블록과 같음을 확인했고 C5 의 재배치 위치와 바이트 일치로도 확인됨.

한계: (가) 스택 점검 36 B 가 `std_trap`·`addrerr`·`access`·`call_trap` 4 곳에 반복 텍스트로 있음(매크로 여부는 바이트로 알 수 없음). (나) `trap`·`trap_rtn`·`intr_rtn`·`access` 등 내부 레이블 이름은 NeXTMach 이름이며 원본에는 이름이 없음(위치만 일치). (다) `d0` 의 의미(프레임 크기 차)·AST 검사 위치는 바이트에서 읽은 추정이며 주석에 단정하지 않았습니다. (라) 이 후보는 07 에 올리지 않았고, NeXTMach 전용 텍스트(`trap0`·`syscall_*`·`TRAP` 열 등)가 객체에 남아 단위 전체 순서는 아직 원본과 다릅니다. 남은 DIFF 는 `_intstacks`(`entry`) 하나입니다.


## 계획 749: m68k `locore.s` 구현 4 단계 — `entry`(`_intstacks` 항목)와 그 뒤 NeXTMach 전용 `_start_init`·`_thread_bootstrap` 삭제 (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §748.3 의 마지막 DIFF 가 `_intstacks` 항목(0x4000318–0x40013c4, 4268 B = 인터럽트 스택 4096 B 의 0 + `entry` 172 B)입니다. 앞 4096 B 는 1단계에서 `.align 2`·`.skip` 으로 맞췄으므로(§744) 남은 것은 0x4001318 의 `entry` 172 B 입니다. 현재 객체의 NeXTMach `entry` 는 208 B 이고 뒤에 NeXTMach 전용 `_start_init`(50 B)·`_thread_bootstrap`(102 B)가 이어져 `_curipl` 까지 360 B 인데(python: 객체 레이블 `entry` 4104, `_start_init` 4312, `_thread_bootstrap` 4362, `_curipl` 4464), 원본은 `entry` 바로 뒤가 `_curipl` 입니다(0x40013c4). 따라서 이 단계는 `entry` 를 원본 순서로 바꾸고 이 두 NeXTMach 전용 함수를 지웁니다(둘 다 §744.2 의 "원본 심볼표에 없는 정의된 전역" 목록에 있음). 성공하면 EQUAL 목표는 43 + 1 = 44 항목, 2832 + 4268 = 7100 B(python 합), 원본 심볼표에 없는 정의된 전역 26 → 24 개입니다(목표 수이며 달성 여부는 실행 뒤 python 집계).

사실(원본 바이트, python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030`; 추출물 `scratch/p748/orig_entry.bin` 172 B = 0x4001318–0x40013c4; 앞 4096 B(0x4000318–0x4001318)는 전부 0 임을 python 으로 확인):
1. `entry` 의 명령열(시작 0x4001318 기준 거리; python 으로 역어셈블에서 뽑은 목록): 0 `lea 0x4001318,%a0`(`41f9`+4 B; `_eintstack` 이며 `entry` 와 같은 주소) → 6 `movel %sp,%a0@-`(`210f`) → 8 `moveal %a0,%sp`(`2e48`) → 10 `moveal #0,%fp`(`2c7c 00000000`) → 16 `jsr 0x4094afe`(`_m68k_init`) → 22 `addqw #4,%sp`(`584f`) → 24 `cmpib #0,0x40b56cc`(`_cpu_type`; `MC68030` 0, `next/cpu.h:74`) → 32 `beqs`(→ +88) → 34 `moveq #0,%d0` → 36·40·44 `movec %d0,%tc`·`%itt1`·`%dtt1`(`4e7b 0003`·`0005`·`0007`) → 48 `f4d8` → 50 `f518` → 52 `movel 0x40b57c4,%d0`(`_m68k_kernel_mmu_rp`+4; 0x40b57c0+4 로 심볼 없음) → 58 `movec %d0,%srp`(`4e7b 0807`) → 62 `movel 0x40b57bc,%d0`(`_m68k_kernel_mmu_040_tt`) → 68·72 `movec %d0,%itt0`·`%dtt0`(`0004`·`0006`) → 76 `movel 0x40b57b8,%d0`(`_m68k_kernel_mmu_040_tc`) → 82 `movec %d0,%tc` → 86 `bras`(→ +112) → 88 `pmove 0x40b57b4,%tt0`(`f039 0800`+4 B; `_m68k_kernel_mmu_030_tt`) → 96 `pmove 0x40b57c0,%srp`(`f039 4800`; `_m68k_kernel_mmu_rp`) → 104 `pmove 0x40b57b0,%tc`(`f039 4000`; `_m68k_kernel_mmu_030_tc`) → 112 `movel 0x40ad964,%d0`(`_cache`) → 118 `movec %d0,%cacr`(`4e7b 0002`) → 122 `cmpib #1,0x40b56cc`(`MC68040` 1, `cpu.h:75`) → 130 `bnes`(→ +152) → 132 `frestore 0x40ad968`(`f379`) → 138 `fmovel 0x40ad968,%fp0`(`f239 4000`) → 146 `fsave 0x40ad968`(`f339`)(셋 다 `_fpu_version`) → 152 `jsr 0x4094202`(`_startup_early`) → 158 `jsr 0x404b970`(`_setup_main`) → 164 `movel %d0,%sp@-` → 166 `jsr 0x4096a70`(`_start_initial_context`) → 끝 +172. 기대 재배치 17 곳의 위치는 `entry` 기준 2·18·28·54·64·78·92·100·108·114·126·134·142·148·154·160·168 이고, `cmp6.expected()` 가 돌려주는 키는 `_intstacks` 기준(+4096)인 4098·4114·4124·4150·4160·4174·4188·4196·4204·4210·4222·4230·4238·4244·4250·4256·4264 입니다(원본 `__text` 재배치 레코드는 0 이므로 "17 곳"은 후보 객체에 요구하는 필드).
2. NeXTMach 와 다른 점: (가) 맨 앞에 `lea _eintstack,a0; movl sp,a0@-; movl a0,sp; movl #0,a6` 가 오고(인터럽트 스택으로 바꾸고 이전 sp 를 그 위에 저장), NeXTMach 는 이 둘을 캐시 설정 뒤(`lea _eintstack,sp`·`#if GDB movl #0,a6`)에 둠 — 원본에는 그 뒤쪽 두 줄이 없음; (나) `jsr _NeXT_init` → `jsr _m68k_init` 와 `addqw #4,sp`(이전 sp 를 인자로 넘기고 버림); (다) 이름: `_NeXT_kernel_mmu_*` → `_m68k_kernel_mmu_*`(5 개; 원본 심볼표에 `_m68k_kernel_mmu_030_tc`·`_030_tt`·`_040_tc`·`_040_tt`·`_rp` 가 있음); (라) 끝: NeXTMach 의 PCB 준비·`rte`·`jsr _main` 이 없고 `jsr _startup_early; jsr _setup_main; movl d0,sp@-; jsr _start_initial_context` 로 끝남; (마) `.data _fpu_version` 조각·`cmpb #MC68030`/`#MC68040` 분기·040 쪽 `.long` 형식은 NeXTMach 와 같음(§744 의 자료 검사가 `_fpu_version` 위치를 이미 확인).

설계(후보 `scratch/p749/locore_C6.s`; 생성기 `scratch/p749/gen_locore6.py` = §748 의 `gen_locore5.py` 실행 뒤 아래를 더함; 표시 `/* plan 749 (D167, D024) BEGIN: … */ … /* plan 749 END */`; 07 에는 쓰지 않음):
1. NeXTMach `entry:` 부터 `PROCENTRY (curipl)` 직전까지(`entry`·`_start_init`·`_thread_bootstrap` 와 `#if NCPUS > 1`·`#ifdef FIXME` 조각)를 새 `entry` 로 바꿈. 새 `entry` 는 위 사실 1 의 순서로, NeXTMach 의 040/030 MMU 설정 `.long` 줄과 `.data _fpu_version` 조각을 그대로 옮기되 이름만 `_m68k_…` 로 바꾸고, 맨 앞 네 줄과 끝 네 줄을 위 (가)(라) 대로 씀. `.data` 조각이 `.text` 로 돌아오는 위치도 NeXTMach 그대로.
2. `addqw #4,sp` 철자 위험: NeXTMach 코드는 `addql #4,sp`(long)을 씀. 원본은 `584f`(`addq.w`)이므로 주 후보는 `addqw #4,sp`, 변형 C6B 는 `addw #4,sp` 로 두 철자 중 어느 쪽이 `584f` 를 내는지 바이트로 정함(`addw #R_SR,sp` 는 `defc 0040` 의 `adda.w` 였음).
3. 비교기 `scratch/p749/cmp7.py` = `scratch/p748/cmp6.py` 에 (가) 표 `NOSYM` 에 `0x40b57c4 → _m68k_kernel_mmu_rp+4` 추가, (나) `_intstacks` 가 검사 목록에 있을 때만: 객체 레이블 `_eintstack`·`entry` 가 `_intstacks`+4096, `_curipl − entry` = 172, `_intstacks − _start` = 8 이고, 항목 안 지역 대상 `0x4001318` 의 객체 쪽 이름이 `_eintstack` 일 것. 먼저 C5 객체(`m4p748-p1`)의 43 항목에 돌려 새 FAIL 이 있는지 보고(정정이 나오면 그대로 보고).
4. 변형 8 개를 한 번에 어셈블: C6(주), C6B(`addw`), 음성 대조 N1(둘째 비교 `cmpb #MC68040,_cpu_type` → `#MC68030`: 바이트), N2(`jsr _m68k_init` → `jsr _startup_early`: 외부 이름), N3(`.long _m68k_kernel_mmu_030_tt` → `_030_tc`: `.long` 속 외부 이름), N4(`entry` 끝에 `nop`: 길이·`_curipl` 간격), N5(`lea _eintstack,a0` → `lea _intstacks,a0`: 지역 레이블 이름), N6(`_thread_bootstrap` 을 지우지 않음: `_curipl` 간격과 원본에 없는 전역). 명세 `08_build/artifacts/m4p749/spec_c6.json`, 실행 `scratch/p737/run.sh m4p749-p1 …`(`08_build/runs/REGISTRY` 에 `m4p749` 없음 확인함).

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(8 변형 각각). (나) C6 에서 `_intstacks` 항목 EQUAL, `cmp7.py` 가 C6 의 44 항목에 `PASS 44 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 EQUAL 44 항목·7100 B·DIFF 0, 기존 43 항목 퇴행 없음. (다) 재배치 17 곳이 기대와 위치·종류·길이·이름·가산값(`_m68k_kernel_mmu_rp`+4)·지역 대상(`_eintstack`·자료 거리: `_cache`·`_fpu_version`)까지 일치. (라) 객체 `entry`·`_eintstack` 가 `_intstacks`+4096, `_curipl − entry` = 172, `_intstacks − _start` = 8; 객체의 정의된 전역 중 원본 심볼표에 없는 것이 26 → 24 개(`_start_init`·`_thread_bootstrap` 이 빠짐; 이름 목록을 python 으로 대조). (마) N1–N6 각각이 `_intstacks` 만 FAIL(N6 은 간격 검사와 전역 목록)이고 나머지 43 항목은 PASS(종료 코드 1). (바) `check_data2.py` `ALL PASS`; 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로; 정의 없는 이름 집합이 C5 와 비교해 달라진 것(`_NeXT_init`·`_set_cpu_number`·`_main`·`_NeXT_kernel_mmu_*` 가 사라지고 `_m68k_init`·`_m68k_kernel_mmu_*`·`_start_initial_context` 가 생기는 것 등)을 python 으로 목록화해 보고. (사) `cmp7.py` 가 C5 의 43 항목에서도 `PASS 43`. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) `_m68k_init` 에 이전 sp 를 인자로 넘기는 의미와 인터럽트 스택 전환 순서는 바이트에서 읽은 추정이며 주석에 단정하지 않습니다. (나) `_start_init`·`_thread_bootstrap` 을 지우면 이를 참조하는 NeXTMach 텍스트가 있을 때 어셈블이 실패하지 않고 정의 없는 이름으로 남음 → 사라진 이름 목록과 새 정의 없는 이름 목록을 python 으로 대조해 보고. (다) `entry` 뒤 NeXTMach 전용 코드(`trap0`·`syscall_*`·`TRAP` 열 등)는 아직 객체에 남아 단위 전체 순서와 크기(8052 B)는 뒤 단계에서 봅니다. (라) 이 후보는 07 에 올리지 않습니다.

### 749.1 §749 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 처음 쓴 사실 1 의 거리 서술이 틀렸습니다(`bras` 를 +112·+86 으로 뒤섞어 적고 스스로 "서술 오기"라고 덧붙임). 코딩 전에 python 으로 역어셈블 목록을 뽑아 다시 썼고(`beqs` +32 → +88, `bras` +86 → +112, `bnes` +130 → +152), 오기 문장은 지웠습니다. (2) 기대 재배치 위치의 기준점(entry 기준과 `_intstacks` 기준)을 구별해 적지 않았음(본문 고침). (3) `cmp6.py` 가 항목 안 지역 대상의 이름 검사를 `INTERNAL` 표에 있는 이름에만 하므로 `_eintstack` 이름만 바꾼 입력을 통과시킴(`cmp6.py:101–105` 를 열어 확인; 재현은 C6 에서). (4) 음성 대조 N5 가 거리·주소도 바꿔 이름 검사만의 시험이 못 됨. (5) 정의 없는 이름 변화를 "보고만" 하도록 적음(실패 조건으로 바꿈).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 앞 4096 B 전부 0, 172 B, 4268 B; `_intstacks − _start` = 8 | python(앞서 같은 값: `K[…]==bytes(0x1000)` True; 172·4268 계산) | ✅ |
| 사실 1 의 명령 거리·바이트(`2c7c 00000000` +10, `584f` +22, `6736`→+88, `6018`→+112, `6614`→+152, `cmpib #0`·`#1`), `MC68030=0`·`MC68040=1`(`cpu.h:74,75`) | python 역어셈블 목록(`scratch/p748/orig_entry.bin`)과 `cpu.h` grep 출력(이번 세션) | ✅ |
| 원본 심볼 `_m68k_kernel_mmu_030_tc/_030_tt/_040_tc/_040_tt/_rp` = 0x40b57b0/b4/b8/bc/c0, `_start_initial_context` 0x4096a70, `_m68k_init` 0x4094afe, `_startup_early` 0x4094202, `_setup_main` 0x404b970 | `grep` 한 `symbols.tsv`(이번 세션) | ✅ |
| `addqw #4,sp`→`584f`, `movl #0,a6`→`2c7c 00000000` 의 C5 객체 선례 | C5 소스 `addqw #4,sp`(`locore_C5.s:1583`)·객체 `__text+0x1dbe` = `584f`, `__text+0x1076` = `2c7c 00000000`(python 으로 읽음) | ✅ (C6B 의 `addw #4,sp` 는 미확인으로 그대로 시험) |
| `.long _NeXT_kernel_mmu_*` 가 외부·absolute·non-pcrel·type 0·length 2·값 0 | C5 객체의 `entry`+74·82·90 재배치를 python 으로 읽음(`extern True, pcrel False, length 2, type 0`, 필드 0) | ✅ (새 이름의 C6 출력은 실행에서) |
| 삭제 범위의 `.data` 조각: `_fpu_version`(보존 필요), `foo_stack`(조건부) | C5 소스 265·382 행; 현재 객체에 `foo_stack`·`slave_start` 레이블 없음(앞서 레이블 목록) | ✅ (조건부 조각은 현재 구성에서 나오지 않음) |
| cmp6 은 4096 B 0 구간도 비교(숨겨진 `...` 행은 원본 0 검사 후 건너뜀) | `cmp6.py` 의 `expected()`(`rd(pos,a)==bytes(a-pos)` 단언)와 `check_entry` 의 전체 `n` 바이트 비교를 열어 확인 | ✅ (변형 시험은 C6 에서 직접) |
| 이름만 바꾼 `_eintstack` 가 통과 / cmp7 은 `_eintstack` 포함 여부(집합 일치 아님)와 필수 레이블 누락 FAIL 을 검사 | `cmp6.py:101–105` 열음(위 (3)) | ✅ 채택 |
| N5 불충분; 이름만 바꾸는 대조·0 구간 변형·`_rp+4→_rp+0`·`mutate_test` 의 cmp7 재실행·정의 없는 이름 변화의 실패 조건 필요 | 계획 N5 정의(주소도 바뀜) 확인 | ✅ 채택 |
| 정의 없는 이름 46 개 → 약 44 개(9 개 삭제, 7 개 추가) 예측 | C5 객체의 정의 없는 이름 46 개 확인; 삭제 후보는 `_NeXT_init`·`_NeXT_kernel_mmu_*` 5 개·`_main`·`_load_init_program` 8 개이고 `_set_cpu_number` 는 `locore_C5.s:1094` 가 쓰므로 남음 → 제 예측은 8 개 삭제·7 개 추가 → 45 개 | ⚖️ 예측일 뿐, C6 실측으로 확인(codex 의 9 와 다를 수 있음) |
| 수치 172·44·7100·17·360→172·50·102·26→24 | python | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 연 파일·돌린 python 입니다. 정의 없는 이름 개수는 예측이며 실측으로 대조합니다.

### 749.2 §749 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. `cmp7.py`: `_intstacks` 가 검사 목록에 있을 때 (가) `entry`·`_eintstack` 레이블이 없으면 FAIL, 둘 다 `_intstacks`+4096, (나) `_curipl − entry` = 172, `_intstacks − _start` = 8, (다) 항목 안 지역 대상 0x4001318 의 객체 쪽 이름 집합이 `_eintstack` 를 포함해야 함(`entry` 가 같은 위치에 있어도 집합 일치는 요구하지 않음; `lea entry,a0` 와 `lea _eintstack,a0` 의 객체 구별은 불가능하다는 한계를 적음), (라) `NOSYM` 에 `0x40b57c4 → _m68k_kernel_mmu_rp+4`.
2. `mutate_test4.py`: `mutate_test3.py` 의 17 변형을 `cmp7.py` 로 다시 돌리고 새 변형 3 가지를 더함: `_eintstack` 레이블 이름만 변경(코드·재배치 그대로)·앞 4096 B 의 0 구간 한 바이트 변경(0·2048·4095 위치)·`_m68k_kernel_mmu_rp` 가산값 4 → 0. 모두 `_intstacks` 만 FAIL.
3. 판정 기준 변경·추가: (바)의 "정의 없는 이름 변화 보고"를 실패 조건으로: C6 의 정의 없는 이름 집합에서 C5 에 없던 이름은 정확히 {`_m68k_init`, `_m68k_kernel_mmu_030_tc`, `_m68k_kernel_mmu_030_tt`, `_m68k_kernel_mmu_040_tc`, `_m68k_kernel_mmu_040_tt`, `_m68k_kernel_mmu_rp`, `_start_initial_context`} 이어야 하고, C5 에서 사라진 이름은 모두 삭제·교체한 소스 구간에 나오는 이름이어야 함(예측: `_NeXT_init`·`_NeXT_kernel_mmu_*` 5 개·`_main`·`_load_init_program`; python 으로 실제 대조). (아) N5 를 둘로 나눔: N5a(`lea _eintstack,a0` → `lea _intstacks,a0`; 주소·이름 모두 달라짐), N5b(위 mutate_test4 의 이름만 변경 변형; 코드는 그대로). (자) mutate_test4 `ALL OK`.

### 749.3 결과: 4 단계 후보 C6 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p749/gen_locore6.py`(§748 의 `gen_locore5.py` 를 실행한 뒤 `entry` 구간을 `plan 749 (D167, D024) BEGIN/END` 표시로 바꾸고 `_start_init`·`_thread_bootstrap` 을 지움; 후보 8 개 `scratch/p749/locore_{C6,C6B,N1,N2,N3,N4,N5A,N6}.s`), 비교기 `scratch/p749/cmp7.py`(§748 의 `cmp6.py` + `_intstacks`/`entry` 규칙·`NOSYM` 추가), 변형 시험 `scratch/p749/mutate_test4.py`, 항목 목록 `scratch/p749/ents44.json`, 명세 `08_build/artifacts/m4p749/spec_c6.json`. 실행: `m4p749-p1`(8 변형 어셈블; 종료 코드 16 개 모두 0, 표준 오류 0 B; 변형 이름 `N5a` 는 명세 규칙(`^[A-Z][A-Z0-9]*$`)에 맞지 않아 첫 시도가 단언 실패였고 `N5A` 로 바꿔 다시 했음 — 첫 시도는 준비 전 실패로 실행 기록 없음).

사전 확인(§749.2): `cmp7.py` 를 C5 객체의 43 항목에 돌림 → `PASS 43 FAIL 0`(정정할 것 없음). 변형 시험 `mutate_test4.py` 를 C6 에 돌림: `mutate_test3` 의 17 변형 + 새 5 변형 모두 의도한 항목만 FAIL(`ALL OK`): `_eintstack` 이름만 변경(0x4001318 을 가리키는 12 항목 `_intstacks`·`_start`·`addrerr`·`buserr`·`ipl1`–`ipl7`·`std_trap` 이 모두 FAIL; 처음 시험은 기대값을 `_intstacks` 하나로 적어 BAD 로 나와 시험 기대값을 "참조하는 모든 항목"으로 고침 — 비교기 동작은 정당), 0 구간 한 바이트 변경(위치 0·2048·4095), `_m68k_kernel_mmu_rp` 가산값 4→0.

변경 요약: `entry` 를 원본 순서로 새로 씀(`lea _eintstack,a0; movl sp,a0@-; movl a0,sp; movl #0,a6; jsr _m68k_init; addqw #4,sp`; NeXTMach 의 040/030 MMU 설정 줄과 `.data _fpu_version` 조각은 그대로, 이름만 `_NeXT_kernel_mmu_*` → `_m68k_kernel_mmu_*`(9 줄, 각각 표시); 캐시 설정 뒤의 `lea _eintstack,sp`·`movl #0,a6` 삭제; 끝은 `jsr _startup_early; jsr _setup_main; movl d0,sp@-; jsr _start_initial_context`). NeXTMach 의 PCB 준비·`rte`·`jsr _main`·`_start_init`·`_thread_bootstrap` 과 `NCPUS > 1`·`FIXME` 조각을 지움. 철자는 첫 시도에서 모두 원본과 같음; 변형 C6B(`addw #4,sp`)도 같은 `584f` 를 내 C6 와 객체가 같으므로(둘 다 PASS) 철자는 `addqw` 로 둡니다.

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(8 변형 모두, 종료 코드 16 개 0, 표준 오류 0 B).
- (나) C6: `_intstacks` 항목 EQUAL, `cmp7.py` `PASS 44 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 `Counter({'EQUAL': 44, 'NO-OBJ-NAME': 14})`(DIFF 0)·`EQUAL entries 44 bytes 7100`, 기존 31 항목 퇴행 없음(`cmp3.py` 31/31). 독립 확인: 객체 `_intstacks`–`_curipl` 직전 4268 B 와 원본의 차이 67 B 는 전부 재배치 필드 17 곳 안이며 필드 밖 차이 0.
- (다) 재배치 17 곳이 기대와 위치·종류·길이·이름·가산값(`_m68k_kernel_mmu_rp`+4)·지역 대상(`_eintstack`·자료 거리 `_cache`·`_fpu_version`)까지 일치(`cmp7.py`).
- (라) 객체: `entry`·`_eintstack` = `_intstacks`+4096, `_curipl − entry` = 172, `_intstacks − _start` = 8, 크기 360 B → 172 B; 정의된 전역 중 원본 심볼표에 없는 것 26 → 24 개(`_start_init`·`_thread_bootstrap` 이 빠짐; python 대조).
- (마) 음성 대조(모두 `_intstacks` 만 FAIL, 종료 코드 1): N1(`cmpb #MC68030`) `bytes differ at [4221]`; N2(`jsr _startup_early`) `@4114 extern _startup_early expected ['_m68k_init']`; N3(`.long …_030_tc`) `@4188 extern … expected ['_m68k_kernel_mmu_030_tt']`; N4(`nop`) `_curipl-entry = 174 expected 172`; N5A(`lea _intstacks,a0`) `@4098 in-entry target distance 0 expected 4096; internal label ['_intstacks'] expected _eintstack`; N6(`_thread_bootstrap` 유지) `_curipl-entry = 324 expected 172`.
- (바) `check_data2.py` `ALL PASS`(11 개); 원본 단위 심볼 중 객체에 없는 텍스트 14 개 그대로; 정의 없는 이름 46 → 44 개: C5 에 없던 새 이름이 정확히 {`_m68k_init`, `_m68k_kernel_mmu_030_tc`, `_m68k_kernel_mmu_030_tt`, `_m68k_kernel_mmu_040_tc`, `_m68k_kernel_mmu_040_tt`, `_m68k_kernel_mmu_rp`, `_start_initial_context`}(python 집합 일치 True), 사라진 이름 9 개 `_NeXT_init`·`_NeXT_kernel_mmu_*` 5 개·`_load_init_program`·`_main`·`_set_cpu_number` 가 모두 바뀐 소스 구간에 나오는 이름(True). (제 §749.1 예측은 `_set_cpu_number` 가 `locore_C5.s:1094` 때문에 남는다고 보아 8 개 삭제·45 개였으나 틀렸고, 실측은 9 개 삭제·44 개로 codex 의 예측과 같음: 1094 행은 조건 컴파일 안의 코드로 현재 구성에서 나오지 않음.)
- (사) `cmp7.py` 가 C5 의 43 항목에서 `PASS 43`. (아)·(자): 위와 같음.

한계: (가) `_m68k_init` 에 이전 sp 를 넘기는 의미·인터럽트 스택 전환 순서는 추정이며 주석에 단정하지 않았습니다. (나) `entry`·`_eintstack` 는 같은 주소의 소스 레이블로 원본 심볼표에는 둘 다 없습니다(객체만으로 `lea entry,a0` 와 `lea _eintstack,a0` 를 구별할 수 없음). (다) 이 후보는 07 에 올리지 않았고, NeXTMach 전용 텍스트가 객체에 남아 단위 전체 순서·크기(8052 B)는 아직 원본과 다릅니다. 이로써 이름이 있는 항목 44 개가 모두 EQUAL 이고 남은 것은 객체에 같은 이름이 없는 14 개 텍스트 심볼(`__move_space`·`_move_space_fault`·`_tlb_update_read/write`·`_probe_rl`·`__switch_context`·`__switch_context_discard`·`__switch_context0`·`__stack_handoff`·`__return_with_state`·`__stack_attach`·`_call_continuation`·`_cache_push`·`_mon_exit`)입니다.


## 계획 750: m68k `locore.s` 구현 5 단계 — `switch_context` 계열 7 항목과 NeXTMach 전용 `TRAP` 처리기 18 개 삭제 (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §749.3 에서 이름 있는 44 항목이 모두 EQUAL 이 되었고 객체에 같은 이름이 없는 원본 텍스트 심볼 14 개가 남았습니다. 그 중 7 개(0x40018d8–0x4001b3e, 164 + 158 + 112 + 140 + 22 + 4 + 14 = 614 B, python 합)는 서로 이어진 `switch_context` 계열이고 같은 세 조각(FPU 저장·복원·캐시)의 조합입니다. 현재 객체에서는 이 자리에 NeXTMach 의 `_save_context`·`_load_context`·`loadfpregs`(원본 심볼표에 없는 전역)가 있습니다. 또 `_call_continuation` 끝과 `std_trap` 사이에 NeXTMach 전용 `TRAPVEC(stray)`·`TRAPVEC(badtrap)`·`TRAP(illegal … mmu_access)` 18 개 처리기가 있어 그대로면 `_call_continuation` 의 크기를 이웃 레이블로 확인할 수 없으므로 이 단계에서 같이 지웁니다(같은 18 개가 §749.3 의 "원본에 없는 정의된 전역 24 개"에 있음). 성공하면 EQUAL 목표는 44 + 7 = 51 항목, 7100 + 614 = 7714 B, 원본에 없는 정의된 전역 24 → 24 − 3(`_save_context`·`_load_context`·`_loadfpregs`) − 18 = 3 개(`_pload_read`·`_pload_write`·`trap0`), 객체에 없는 원본 텍스트 심볼 14 → 7 개입니다(목표 수이며 달성 여부는 실행 뒤 python 집계).

사실(원본 바이트, python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030`; 역어셈블 `scratch/p749/orig_sw.txt` 156 행):
1. 세 조각(python 비교): ① SAVE 조각 46 B(`moveal %sp@(4),%a0`; `bclr #6,%a0@(84)`; `fsave %a0@(92)`; `tstb %a0@(92)`; `beqs`; `bset #6,%a0@(84)`; `fmovem` 두 개(`f228 bc00 0194`·`f228 f0ff 0134`); `nop`; `frestore 0x40018d4`) 는 `__switch_context`·`_discard`·`__stack_handoff` 의 시작 46 B 에서 재배치 필드(+42)를 가리고 **같음**(True). ② RESTORE 조각 68 B(`tstb %a0@(92)`; `beqs`; `fmovem`(`f228 9c00 0194`·`f228 d0ff 0134`); `nop`; `frestore %a0@(92)`; `tstb %a0@(92)`; `bnes`; `fmovel #128,%fpcr`(`f23c 9000 0000 0080`); `cmpib #0,0x40b56cc`; `beqs`; `movel %a0@(88),%d0`; `movec %d0,%itt1`·`%dtt1`; `bras`; `pmove %a0@(88),%tt1`(`f028 0c00 0058`)) 는 `__switch_context`·`_discard`·`__switch_context0` 에서 **같음**(재배치 +cpu_type 가림, True). ③ TAIL 조각 38 B(`movel %sp@(8),%a0@(0)`; `moveal %a0@(60),%sp`; `cmpib #0,0x40b56cc`; `bnes`; `movel 0x40ad964,%d0`(`_cache`); `movec %d0,%cacr`; `moveml %a0@(0),%d0-%fp`; `jmp %a1@`) 는 세 함수에서 **같음**(True).
2. 조합(python 바이트 비교 + 크기 합): `__switch_context`(164 B) = SAVE(46) + `moveal %sp@+,%a1`(2)·`moveml %d0-%sp,%a0@(0)`(6)·`moveal %sp@(4),%a0`(4) + RESTORE(68) + TAIL(38). `__switch_context_discard`(158 B) = SAVE + `addql #4,%sp`(2)·`moveal %sp@(4),%a0`(4) + RESTORE + TAIL(`jmp %a1@`; 이 `jmp` 는 직전 `moveml %a0@(0),%d0-%fp`(마스크 0x7fff 에 `a1` 포함, `a1` 슬롯 = a0+36)가 새 pcb 에서 복원한 `a1` 로 점프함). `__switch_context0`(112 B) = `addql #4,%sp`·`moveal %sp@(4),%a0`(6) + RESTORE + TAIL. `__stack_handoff`(140 B) = SAVE + `moveal %sp@(8),%a0`(4) + RESTORE + 캐시 조각(`cmpib #0,_cpu_type`; `bnes`; `movel _cache,%d0`; `movec %d0,%cacr`; 20 B) + `rts`(2). `__return_with_state`(22 B) = `moveal %sp@(4),%sp`; `moveal %sp@(60),%a0`; `movec %a0,%usp`; `moveml %sp@,%d0-%fp`; `addaw #64,%sp`; `rte`. `__stack_attach`(4 B) = `movel %d0,%sp@-`; `jsr %a2@`. `_call_continuation`(14 B) = `moveal %sp@(4),%a0`; `moveal 0x40b57cc,%sp`; `moveal %sp,%fp`; `jmp %a0@`.
3. 상수·주소: `AST`(84)·`FPC_INT`(92)·`FPC_EXT`(404)·`FPC_REGS`(308)·`TT1`(88)·`REGS`(0)·`R_SP`(60) 는 후보 머리 블록에 이미 있음(`grep` 확인); `bclr`/`bset #6,%a0@(84)` 의 비트 6 은 `pcb_flags` 의 fsave 표시 비트(§743; 이름은 아직 없음); `frestore 0x40018d4` 의 대상은 `_blkclr` 안 널 프레임 4 B(§744; 객체에서는 `null_frame` 레이블, `_blkclr`+6). 기대 재배치(`cmp7.expected()` python 목록): `__switch_context` +42(null_frame)·+100(`_cpu_type`)·+140(`_cpu_type`)·+148(`_cache`), `_discard` +42·+94·+134·+142, `__switch_context0` +48·+88·+96, `__stack_handoff` +42·+92·+122·+130, `_call_continuation` +6(`_stack_pointers`), 나머지 0 — 합 16 곳.

설계(후보 `scratch/p750/locore_C7.s`; 생성기 `scratch/p750/gen_locore7.py` = §749 의 `gen_locore6.py` 실행 뒤 아래를 더함; 표시 `/* plan 750 (D167, D024) BEGIN: … */ … /* plan 750 END */`; 07 에는 쓰지 않음):
1. NeXTMach `_save_context` 부터 `PROCENTRY(loadfpregs)` 끝(`//----traps----//` 직전)까지를 위 7 항목으로 바꿈. 각 항목은 NeXTMach 의 `_save_context`/`_load_context` 줄 형식을 따라 씀: FPU `.long 0xf228bc00; .word FPC_EXT`·`.long 0xf228f0ff; .word FPC_REGS`(저장)·`.long 0xf2289c00`·`0xf228d0ff`(복원)·`.long 0xf0280c00; .word TT1`·`.long 0x4e7b0005/0007`(`movc`)·`frestore null_frame`·`fsave a0@(FPC_INT)`·`frestore a0@(FPC_INT)` 는 NeXTMach 철자 그대로. 새로 쓰는 철자는 `bclr/bset #FSAVE_BIT,a0@(AST)`(머리 블록에 `FSAVE_BIT 6` 을 더함; 이 프로젝트의 가칭, §743; 07 로 올리기 전 사용자 확인), `fmovel #128,fpcr`(주 후보; 어셈블러가 모르면 변형 C7B 의 `.long 0xf23c9000; .long 128`), `movl sp@+,a1`·`addql #4,sp`·`movl sp@(8),a0@(R_D0)`·`jmp a1@`·`jsr a2@`·`movl sp,a6`. `null_frame` 레이블은 NeXTMach 위치(`_blkclr` 바로 뒤)에 그대로. 심볼은 원본 이름 `__switch_context`·`__switch_context_discard`·`__switch_context0`·`__stack_handoff`·`__return_with_state`·`__stack_attach`·`_call_continuation` 을 `.globl` 로 정의.
2. `TRAPVEC(stray)`·`TRAPVEC(badtrap)` 와 `TRAP(illegal, T_ILLEGAL, 0)` … `TRAP(mmu_access, T_MMU_ACCESS, 0)`(16 줄)을 지움(NeXTMach `TRAP`·`TRAPVEC` 매크로 정의는 이 단계에서 그대로: 쓰이지 않는 정의는 객체에 영향 없음). `TRAP(trace…)` 자리는 §744 의 표시 구간이므로 그대로.
3. 비교기 `scratch/p750/cmp8.py` = `scratch/p749/cmp7.py` 에 (가) `LOCAL[0x40018d4]='null_frame'`, (나) `__switch_context` 가 검사 목록에 있을 때만: 객체 레이블 `__switch_context … _call_continuation` 이 연속이고 간격이 164·158·112·140·22·4 B, `std_trap − _call_continuation` = 14, `null_frame − _blkclr` = 6, `__switch_context − null_frame` = 4. 먼저 C6 객체(`m4p749-p1`)의 44 항목에 돌려 새 FAIL 이 있는지 보고(정정이 나오면 그대로 보고).
4. 변형 9 개를 한 번에 어셈블: C7(주), C7B(`fmovel` → `.long`), 음성 대조 N1(`__switch_context` 의 `bclr #6` → `#5`: 바이트), N2(`__stack_handoff` 의 `movl _cache,d0` → `movl _cpu_type,d0`: 외부/자료 이름), N3(`_call_continuation` 의 `_stack_pointers` → `_active_threads`: 외부 이름), N4(`__switch_context0` 끝 `nop`: 간격), N5(`__stack_handoff` 의 `frestore null_frame` → `frestore a0@(FPC_INT)`: 바이트·재배치 위치), N6(TRAP 처리기를 지우지 않음: `std_trap − _call_continuation` 간격), N7(`__switch_context_discard` 의 `fmovel #128` → `#127`: 바이트). 명세 `08_build/artifacts/m4p750/spec_c7.json`, 실행 `scratch/p737/run.sh m4p750-p1 …`(`08_build/runs/REGISTRY` 에 `m4p750` 없음 확인함; 변형 이름은 `^[A-Z][A-Z0-9]*$`).
5. 변형 시험: `scratch/p750/mutate_test5.py` = `mutate_test4.py` 를 `cmp8.py` 로 돌리고 새 변형 2 가지: `null_frame` 레이블 이름만 변경(그 레이블을 가리키는 항목 3 개 `__switch_context`·`__switch_context_discard`·`__stack_handoff` 가 FAIL), `null_frame` 위치 이동은 레이블과 이를 가리키는 주소 필드를 함께 옮겨 이름 검사는 통과시키고 거리 검사만 FAIL 하게 함.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(9 변형 각각; C7 이 실패하면 철자 변형으로 가고 시도를 모두 기록). (나) C7 에서 7 항목 EQUAL, `cmp8.py` 가 C7 의 51 항목에 `PASS 51 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 EQUAL 51 항목·7714 B·DIFF 0, 기존 44 항목 퇴행 없음(`cmp3.py` 31/31 포함). (다) 재배치 16 곳이 기대와 위치·종류·길이·이름·가산값·지역 대상(`null_frame`·`_cache` 자료 거리)까지 일치. (라) 객체: 7 레이블 연속·간격 일치, `std_trap − _call_continuation` = 14, `null_frame − _blkclr` = 6; 원본에 없는 정의된 전역 24 → 3 개(이름 목록을 python 으로 대조: 남는 것이 `_pload_read`·`_pload_write`·`trap0`); 객체에 없는 원본 텍스트 심볼 7 개(`__move_space`·`_move_space_fault`·`_tlb_update_read/write`·`_probe_rl`·`_cache_push`·`_mon_exit`). (마) 음성 대조 N1–N7 각각이 해당 항목 하나만 FAIL(N4·N6 은 간격 검사; 종료 코드 1)이고 나머지 항목은 PASS. (바) `check_data2.py` `ALL PASS`(자료 불변); 정의 없는 이름 집합이 C6 의 부분집합(새로 생긴 정의 없는 이름 없음)이고 사라진 이름은 지운 소스 구간에 나오는 이름(python 대조). (사) `cmp8.py` 가 C6 의 44 항목에서도 `PASS 44`. (아) 변형 시험 `ALL OK`. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) 세 조각이 원본에서 매크로였는지 반복 텍스트였는지는 바이트로 알 수 없어 반복 텍스트로 둡니다(소스 형태는 바이트가 정한 꼴만). (나) `__switch_context_discard`·`__switch_context0` 의 `jmp a1@` 가 쓰는 `a1`(새 pcb 의 `a1` 슬롯)의 의미·호출 규약, `fmovel #128,%fpcr` 의 의미, fsave 표시 비트의 용도는 추정이며 주석에 단정하지 않습니다. (다) `__stack_attach`(4 B)와 `_call_continuation`(14 B)이 이어지는 것은 함수표의 경계에 따른 것이며 소스 상 경계는 바이트로 알 수 없습니다. (라) `FSAVE_BIT` 이름은 가칭입니다. (마) `TRAP` 처리기를 지워도 `_scb` 항목은 원본대로 `std_trap` 을 가리키므로(§744) 영향이 없다고 읽었지만 `_scb` 의 재배치 이름이 바뀌지 않는지는 `check_data2.py` 로 확인합니다. (바) 이 후보는 07 에 올리지 않으며 `trap0`·`_pload_*`·`_cache_push` 등 남은 NeXTMach 텍스트로 단위 전체 순서·크기(8052 B)는 아직 원본과 다릅니다.

### 750.1 §750 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 사실 2 와 한계에서 `__switch_context_discard`·`__switch_context0` 가 `a1` 를 "정하지 않는다"고 적었으나 이 두 함수의 `jmp %a1@` 앞 `moveml %a0@(0),%d0-%fp`(마스크 0x7fff)가 `a1` 를 새 pcb 의 슬롯(a0+36)에서 복원합니다(본문 고침). (2) `null_frame` 이름 변경의 예상 실패를 4 개로 적었으나 참조 항목은 3 개입니다(`__switch_context0` 에는 SAVE 가 없음; 본문 고침). (3) `null_frame` 위치만 옮기는 시험이 "위치 검사만 FAIL"한다고 적었으나 레이블만 옮기면 지역 대상 이름 검사도 실패합니다(레이블과 주소 필드를 함께 옮기도록 고침). (4) §749 의 `cmp7.py` 가 필수 항목 누락(`NO-OBJ-NAME`)을 SKIP 으로 두어 성공으로 끝납니다(코드를 열어 확인; 아래 보강). (5) RESTORE 조각이 `__stack_handoff` 에서도 같다는 점을 사실 1 에서 빠뜨림.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| SAVE 46 B(`0x40018d8`·`0x400197c`·`0x4001a8a`)·RESTORE 68 B(`0x4001912`·`0x40019b0`·`0x4001a20`·`0x4001abc`)·TAIL 38 B(`0x4001956`·`0x40019f4`·`0x4001a64`) 가 재배치 필드를 가리지 않아도 같음 | python 으로 원본 바이트를 직접 비교: 세 조각 모두 raw 동일 True(RESTORE 는 4 곳) | ✅ |
| 7 항목 조합·크기(164·158·112·140·22·4·14), `__return_with_state`·`__stack_attach`(`2f00 4e92`)·`_call_continuation`(`206f0004 2e79040b57cc 2c4f 4ed0`) | 앞서 python 비교 + `orig_sw.txt` 열음 | ✅ |
| `fmovel #128,%fpcr` = `f23c 9000 0000 0080`(0x4001930·0x40019ce·0x4001a3e·0x4001ada) | python 바이트 출력 4 곳 | ✅ |
| `jmp %a1@`(0x4001a18·0x4001a88) 앞 `moveml` 마스크 0x7fff 에 `a1`(비트 9, 슬롯 36) 포함 | python: `4ce8 7fff 0000`, 마스크 비트 9 True, 슬롯 `9*4`=36; `orig_sw.txt` 에서 `%a1` 가 나오는 줄이 `moveal %sp@+,%a1` 과 `jmp %a1@` 3 개뿐임을 확인 | ✅ 본문 고침 |
| 기대 재배치 16 곳과 오프셋·대상(`null_frame` 0x40018d4) | 앞서 `cmp7.expected()` python 출력(위치·대상 일치) | ✅ |
| 상수 `0054→84`·`005c→92`·`0194→404`·`0134→308`·`0058→88`·`003c→60` 가 머리 정의와 같음; 비트 6 의 용도는 추정 | 머리 블록 grep(앞서 `AST 84`·`TT1 88`·`FPC_INT 92`·`FPC_EXT 404`·`FPC_REGS 308`·`R_SP 60`) | ✅ |
| 철자 선례: `fsave a0@(92)`(C6 소스 898 행·객체 `f328 005c`), `bclr #4,a0@(84)`(`08a8 0004 0054`) 은 선례, `fmovel #128,fpcr` 는 미확인 | `grep -n "fsave\|fmovel\|bclr"`(이번 세션): 898 행 `fsave a0@(FPC_INT)`, 282 행 `fmovel _fpu_version,fp0`(즉값→FPCR 형식 아님), 1464 행 `bclr #AST_SCHED_BIT,a0@(AST)` | ✅ (`fmovel #128,fpcr` 는 실행으로 확인) |
| 삭제 범위에 외부에서 참조되는 레이블 없음; `_scb` 가 삭제 처리기를 가리키지 않음; `syscall_*`·`argc_table` 은 범위 밖 | 앞서 python: `_scb` 72 이름 중 삭제 대상 0, 삭제 이름의 정의 줄 외 코드 참조 0(이름이 같은 다른 낱말·주석 제외); `_save_context` 의 `.globl` 줄도 삭제 범위에 넣음 | ✅ |
| `cmp7.py` 가 `NO-OBJ-NAME` 을 SKIP 으로만 두어 필수 항목 누락이 성공 | `cmp7.py` 의 main 을 열어 `SKIP … continue` 와 FAIL 목록에 안 들어감을 확인 | ✅ 채택 |
| N4·N6 의 귀속, 필수 심볼 누락·MOVEM 마스크·잘못된 전방 해소 변형, 필수 레이블의 정의·전역·`__text`·중복 검사, C7 철자 후보 채택 조건 | 계획 본문 확인 | ✅ 채택 |
| 수치 614·51·7714·16·24→3·14→7 | python | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 연 파일·돌린 python 출력입니다.

### 750.2 §750 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. `cmp8.py`: 검사 목록에 있는 항목이 객체에 없으면 FAIL(SKIP 으로 두지 않음); 7 개 새 항목의 필수 레이블은 정의돼 있고 전역이며 `__text` 소속이고 이름이 한 번만 나와야 함; 거리 검사의 귀속: 이웃 레이블 간격이 틀린 항목에 귀속(`__switch_context0` 의 `nop` 은 그 항목, `std_trap − _call_continuation` 은 `_call_continuation`, `null_frame − _blkclr`·`__switch_context − null_frame` 은 `_blkclr`).
2. 변형을 12 개(C7·C7B + N1–N10)로: N8(`__switch_context` 의 `moveml a0@(REGS),#0x7fff` → `#0x7dff`: `a1` 제외 마스크), N9(`_call_continuation` 레이블 이름을 `_call_continuationx` 로: 필수 심볼 누락), N10(`__switch_context_discard` 의 `3:` 레이블 한 줄 삭제: `bne 3f` 가 다음 `3:` 로 잘못 해소되는 경우). N4 는 `__switch_context0`, N6 는 `_call_continuation`, N5 는 `__stack_handoff`, N9 는 `_call_continuation` 에 귀속됨을 기대값으로 적음.
3. 판정 기준 보강: (가)에서 C7 이 실패하고 C7B 를 채택한다면 채택 후보가 (나)–(아)를 모두 통과해야 하며, 둘 다 어셈블되면 `__text` 바이트와 재배치 표가 같은지(SHA-256 앞 12 자) 비교해 같은 코드임을 확인. (바)에 `_scb` 재배치(`check_data2.py`)와 정의 없는 이름 집합 불변(예측: C6 의 44 개와 같음)을 포함.

### 750.3 결과: 5 단계 후보 C7 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p750/gen_locore7.py`(§749 의 `gen_locore6.py` 를 실행한 뒤 `switch_context` 계열을 `plan 750 (D167, D024) BEGIN/END` 표시로 쓰고 NeXTMach `_save_context`·`_load_context`·`loadfpregs` 와 `TRAP` 처리기 18 개를 지움; 후보 12 개 `scratch/p750/locore_{C7,C7B,N1…N10}.s`), 비교기 `scratch/p750/cmp8.py`(§749 의 `cmp7.py` + 필수 항목 누락 FAIL + 계열 레이블·간격·`null_frame` 규칙), 변형 시험 `scratch/p750/mutate_test5.py`, 항목 목록 `scratch/p750/ents51.json`, 명세 `08_build/artifacts/m4p750/spec_c7.json`. 실행: `m4p750-p1`(12 변형 어셈블; 종료 코드 24 개 모두 0, 표준 오류 0 B).

사전 확인(§750.2): (1) `cmp8.py` 를 C6 객체의 44 항목에 돌림 → `PASS 44 FAIL 0`(정정할 것 없음). (2) 필수 항목 누락 규칙 시험: 같은 C6 객체에 51 항목 목록을 주면 새 7 항목이 모두 `required entry missing` 으로 FAIL(종료 코드 1). (3) `mutate_test5.py` 를 C7 에 돌림: §749 의 22 변형 + 새 4 변형 = 26 개 모두 의도한 항목만 FAIL(`ALL OK`). 시험 기대값을 두 번 고쳤습니다: `null_frame` 이름 변경은 그 레이블이 없어지므로 `_blkclr`(간격 규칙의 "레이블 없음")도 FAIL 해야 맞고, `null_frame` 이동 시험은 처음에 객체를 다시 파싱하면서 레이블 이동을 지워 버린 제 시험 오류로 이름 검사가 실패했던 것을 고쳤습니다(비교기는 정당).

변경 요약: NeXTMach `_save_context`~`loadfpregs` 구간을 SAVE(46 B)·RESTORE(68 B)·TAIL(38 B) 조각으로 조합한 7 항목으로 바꿈(조합은 §750 사실 2). `fmovel #128,fpcr`·`bclr/bset #FSAVE_BIT,a0@(AST)`·`fsave a0@(FPC_INT)` 철자는 첫 시도에서 원본과 같았고(`fmovel #128,fpcr` 가 `f23c 9000 0000 0080`), `.long` 철자의 변형 C7B 는 C7 과 `__text`·재배치 표·객체 전체가 같음(SHA-256 앞 12 자 `52a70069a589` 둘 다)이므로 `fmovel` 철자를 씁니다. 머리 `#define` 블록에 `FSAVE_BIT 6`(가칭)을 더함. `TRAPVEC`·`TRAP` 처리기 18 개를 지움(매크로 정의는 그대로).

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(12 변형 모두, 종료 코드 24 개 0, 표준 오류 0 B).
- (나) C7: 7 항목 EQUAL, `cmp8.py` `PASS 51 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 `Counter({'EQUAL': 51, 'NO-OBJ-NAME': 7})`(DIFF 0)·`EQUAL entries 51 bytes 7714`, 기존 44 항목 퇴행 없음(`cmp3.py` 31/31). 독립 확인: 객체 `__switch_context`–`std_trap` 직전 614 B 와 원본의 차이 61 B 는 전부 재배치 필드 16 곳 안, 필드 밖 차이 0.
- (다) 재배치 16 곳이 기대와 위치·종류·길이·이름·지역 대상(`null_frame`·`_cache` 자료 거리)까지 일치.
- (라) 객체: 7 레이블 연속·간격(164·158·112·140·22·4·14) 일치, `std_trap − _call_continuation` = 14, `null_frame − _blkclr` = 6, `__switch_context − null_frame` = 4; 원본 심볼표에 없는 정의된 전역 24 → 3 개(남은 것 `_pload_read`·`_pload_write`·`trap0`; python 대조); 객체에 없는 원본 텍스트 심볼 14 → 7 개(`__move_space`·`_move_space_fault`·`_tlb_update_read`·`_tlb_update_write`·`_probe_rl`·`_cache_push`·`_mon_exit`).
- (마) 음성 대조(각각 지정한 항목 하나만 FAIL, 종료 코드 1): N1(`bclr #5`) `__switch_context` `bytes differ at [7]`; N2(`_cpu_type`) `__stack_handoff` `@130 extern _cpu_type expected ['_cache']`; N3(`_active_threads`) `_call_continuation` `@6 extern _active_threads expected ['_stack_pointers']`; N4(`nop`) `__switch_context0` `__stack_handoff-__switch_context0 = 114 expected 112`; N5(`frestore a0@(FPC_INT)`) `__stack_handoff` 재배치 위치·바이트·간격 불일치; N6(TRAP 유지) `_call_continuation` `std_trap-_call_continuation = 706 expected 14`; N7(`#127`) `__switch_context_discard` `bytes differ at [89]`; N8(`#0x7dff`) `__switch_context` `bytes differ at [158]`; N9(`_call_continuationx`) `_call_continuation (required entry missing in the object)`; N10(`3:` 삭제) `__switch_context_discard` `bytes differ at [81]`.
- (바) `check_data2.py` `ALL PASS`(11 개; `_scb` 재배치 포함); 정의 없는 이름 집합 C6 과 같음(44 개; 새·사라진 이름 없음 — 예측 적중).
- (사) `cmp8.py` 가 C6 의 44 항목에서 `PASS 44`. (아) 변형 시험 `ALL OK`. C7B 채택 조건: 해당 없음(C7 통과).

한계: (가) SAVE·RESTORE·TAIL 조각이 원본에서 매크로였는지 반복 텍스트였는지는 바이트로 알 수 없어 반복 텍스트로 둠. (나) `jmp a1@` 가 쓰는 `a1`(새 pcb 의 `a1` 슬롯)의 의미·호출 규약, `fmovel #128,%fpcr` 의 의미, fsave 표시 비트의 용도는 추정이며 주석에 단정하지 않았습니다. (다) `__stack_attach`(4 B)와 `_call_continuation`(14 B)의 소스 상 경계는 함수표를 따랐을 뿐입니다. (라) `FSAVE_BIT` 이름은 가칭입니다. (마) 이 후보는 07 에 올리지 않았고 NeXTMach 전용 `trap0`·`_pload_read`·`_pload_write` 와 `syscall_*` 가 객체에 남아 있습니다.


## 계획 751: m68k `locore.s` 구현 6 단계 — 남은 텍스트 7 항목 `_tlb_update_read`·`_tlb_update_write`·`__move_space`·`_move_space_fault`·`_probe_rl`·`_cache_push`(+`trap2` 조각)·`_mon_exit` (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §750.3 에서 이름 있는 51 항목이 EQUAL 이고 객체에 같은 이름이 없는 원본 텍스트 심볼이 7 개 남았습니다. 이 7 개는 합 338 B(46 + 46 + 100 + 28 + 42 + 42 + 34, python)이고, 성공하면 단위 함수표 58 항목 전부(7714 + 338 = 8052 B = 단위 크기 0x4002284 − 0x4000310, python)가 항목별로 EQUAL 이 됩니다(목표 수이며 달성 여부는 실행 뒤 python 집계; 항목별 EQUAL 은 객체 안 순서·NeXTMach 전용 텍스트 삭제가 끝난 단위 전체 일치가 아닙니다). 7 개 중 4 개는 NeXTMach 텍스트와 거의 같고(`pload_*`→`tlb_update_*`, `probe_rb`→`probe_rl`, `trap2`→`_cache_push`) `__move_space`·`_move_space_fault`·`_mon_exit` 는 새로 씁니다.

사실(원본 바이트, python 으로 `__text` 에서 추출·`m68k-linux-gnu-objdump -m m68k:68030`; 현재 C7 객체 `08_build/runs/m4p750-p1/stage/Q750__locore_C7.o` 비교):
1. `_tlb_update_read`(0x4001412, 46 B)·`_tlb_update_write`(0x4001440, 46 B): 현재 객체의 NeXTMach `_pload_read`·`_pload_write`(각 46 B)와 python 으로 재배치 필드(+16 `_cpu_type`)를 가리고 비교하면 `_read` 는 **같고**(차이 0), `_write` 는 **한 바이트만 다름**(함수 안 +31: 원본 `f548`(`ptestw`)·NeXTMach `f568`(`ptestr`)). 곧 이름과 NeXTMach 의 `#define PTESTW_BUG 1`(→ 원본은 `#else` 쪽 `0xf548`)뿐입니다. 구조: `linkw %fp,#0`; `movel %fp@(8),%d0`; `moveal %fp@(12),%a0`; `cmpib #0,_cpu_type`; `beqs`; `movec %dfc,%d1`; `movec %d0,%dfc`; `.short 0xf568|0xf548`; `movec %d1,%dfc`; `bras`; `ploadr|ploadw %d0,%a0@`(`f010 2208`·`f010 2008`); `unlk %fp`; `rts`.
2. `_probe_rl`(0x4001898, 42 B): 이미 EQUAL 인 `_probe_rb`(0x400186e, 42 B)와 python 으로 비교하면 함수 안 +9(복구 주소 필드의 하위 바이트; 재배치 필드 안)와 +18(`moveb %a0@,%d0` `1010` → `movel %a0@,%d0` `2010`)만 다름. 곧 `probe_rb` 와 같은 꼴에 `movl a0@,d0`.
3. `__move_space`(0x40014be, 100 B): `linkw %fp,#0` → `moveml %d2/%a2-%a3,%sp@-`(`48e7 2030`) → `moveal 0x40b5648,%a2`(`_active_threads`) → `movel %a2@(112),%sp@-`(`THREAD_RECOVER` 112; 이미 머리 블록에 있음) → `movel #0x4001522,%a2@(112)`(`_move_space_fault`; `257c`+4 B+`0070`) → `moveal %fp@(8),%a0` → `movel %fp@(12),%d0` → `movec %dfc,%d2` → `movec %d0,%dfc` → `movel %fp@(20),%d0` → `cmpil #0,%fp@(16)`(`SIZE_LONG` 0) → `bnes 0x40014fc`(인코딩 변위 +6) → `movesl %d0,%a0@`(`0e90 0800`) → `bras →0x4001510` → `cmpil #2,%fp@(16)`(`SIZE_WORD` 2) → `bnes` → `movesw %d0,%a0@`(`0e50 0800`) → `bras →0x4001510` → `movesb %d0,%a0@`(`0e10 0800`) → 0x4001510 `clrl %d0` → **0x4001512** `movec %d2,%dfc` → `movel %sp@+,%a2@(112)`(`255f 0070`) → `moveml %sp@+,%d2/%a2-%a3`(`4cdf 0c04`) → `unlk %fp` → `rts`. NeXTMach 의 `move_space`(68 B)와 같은 뼈대(`movs*`·`SIZE_*` 분기)에 복구 주소 보존·`d2` 사용이 더해진 것입니다.
4. `_move_space_fault`(0x4001522, 28 B): `orl %fp@(12),%d0`(`80ae 000c`) → `moveal %fp@(24),%a3` → `movel %d1,%a3@` → `moveal %fp@(28),%a3` → `movel %a0,%a3@` → `moveal %fp@(32),%a3` → `movel %a1,%a3@` → `bral 0x4001512`(`60ff ffffffd8`; `__move_space` +84 의 `movec %d2,%dfc`). 즉 `a_p1`·`a_p4`·`a_p5`·`a_p6`(`a6@(0xc)`·`@(0x18)`·`@(0x1c)`·`@(0x20)`, `cframe.h:85–91`)을 쓰는 꼴입니다.
5. `_cache_push`(0x4002238, 42 B): `linkw %fp,#0` → `cmpib #0,_cpu_type` → `beqs` → `nop` → `.short 0xf4f8` → `bras` → `movel _cache,%d0` → `movec %d0,%cacr` → `unlk %fp` → `rts`(여기까지 34 B) → **0x400225a**(`_cache_push`+34) `jsr 0x4002238` → `rte`(8 B; `_scb` 항목 0x088 이 가리키는 곳, §742). NeXTMach `trap2`(`cmpb`·`beq`·`nop`·`cpusha`·`rte`·`movl _cache,d0`·`movc d0,cacr`·`rte`)와 같은 낱말이며 `PROCENTRY`/`PROCEXIT` 꼴로 바뀐 것입니다.
6. `_mon_exit`(0x4002262, 34 B; 단위의 마지막 항목): `movew %sp@,%d0` → `andiw #8192,%d0` → `bnes →0x4002276`(= +20) → `jsr 0x4007bd0`(`_suser`) → `tstl %d0` → `bnes →0x4002276`(= +20) → `rte` → 0x4002276 `movel 0x40b564c,%d0`(`_boot_action`) → `moveal 0x40b57c8,%a0`(`_reboot_vector`) → `jmp %a0@`. 원본 심볼표: `_mon_exit` 0x4002262, `_suser` 0x4007bd0, `_boot_action` 0x40b564c, `_reboot_vector` 0x40b57c8(`symbols.tsv`); 07 `m68k_init.c:229` 가 이것을 `scb.scb_trap[13]` 에 넣음(§ 앞선 계획).
7. 기대 재배치(`cmp8.expected()` python 목록): `_tlb_update_read`·`_write` +16(`_cpu_type`); `__move_space` +10(`_active_threads`)·+20(`_move_space_fault`); `_move_space_fault` +24(pc 상대 → 0x4001512); `_probe_rl` +6(0x40018b6 = 함수 안 +30)·+10·+22·+32(`_probe_recover`); `_cache_push` +8(`_cpu_type`)·+22(`_cache`)·+36(`_cache_push`); `_mon_exit` +10(`_suser`)·+22(`_boot_action`)·+28(`_reboot_vector`) — 합 15 곳.

설계(후보 `scratch/p751/locore_C8.s`; 생성기 `scratch/p751/gen_locore8.py` = §750 의 `gen_locore7.py` 실행 뒤 아래를 더함; 표시 `/* plan 751 (D167, D024) BEGIN: … */ … /* plan 751 END */`; 07 에는 쓰지 않음):
1. `PROCENTRY (pload_read)`·`PROCENTRY (pload_write)` 를 `PROCENTRY (tlb_update_read)`·`PROCENTRY (tlb_update_write)` 로 바꾸고 `#define PTESTW_BUG 1` 을 `0`(원본 `f548`)으로 바꿈(NeXTMach 의 `#else PTESTW_BUG` 쪽 `.word 0xf548` 이 쓰임). 이로써 `_pload_read`·`_pload_write` 정의가 사라짐.
2. `probe_rb` 바로 뒤에 `PROCENTRY (probe_rl)` 을 더함(`probe_rb` 와 같은 꼴에서 `movb a0@,d0` → `movl a0@,d0`; 복구 레이블 번호 `1:`/`2:` 는 그 함수 안에서 닫음).
3. NeXTMach `PROCENTRY (move_space)` 블록(`cache_push_page` 앞까지)을 새 `__move_space`(`.globl __move_space` + `__move_space:` 에 `link a6,#0`·`moveml #0x2030,sp@-`·… `unlk a6`; `rts`)와 `_move_space_fault` 로 바꿈. 사실 3·4 의 순서대로, 한 곳에서만 쓰이는 `clrl d0` 과 `movec d2,dfc` 의 두 번째 진입점을 위해 레이블 `3:`(두 `bra 3f`(`movsl`·`movsw` 뒤)의 목표 = `clrl d0` = `__move_space`+82; `movsb` 경로는 순차 진입)과 이름 있는 지역 레이블 `move_space_done`(= 0x4001512; 원본에 이름 없음, 이 프로젝트의 가칭)을 둠. `_move_space_fault` 의 마지막 분기는 `jra move_space_done`(원본이 긴 형 `60ff`; 뒤로 가는 `bra` 는 짧은 형이 될 수 있어 `jra`; §744 의 `jra` 규칙).
4. NeXTMach `trap2:` 블록을 `PROCENTRY (cache_push)` 꼴 함수(사실 5; `D25B || D43B` 의 `nop` 포함)와 바로 뒤 8 B `trap2:` 조각(`jsr _cache_push; rte`)으로 바꾸고, 그 뒤 `_mon_exit`(사실 6; `.globl _mon_exit`)를 씀. `_scb` 의 `trap2` 이름은 그대로 새 `trap2` 레이블(`_cache_push`+34)을 가리킴.
5. 비교기 `scratch/p751/cmp9.py` = `scratch/p750/cmp8.py` 에 (가) `INTERNAL[0x4001512]='move_space_done'`, `INTERNAL[0x400225a]='trap2'`(항목 안/밖 지역 대상 이름 검사에 쓰는 표; `0x4001512` 는 `_move_space_fault` 에서 보면 항목 밖이므로 `LOCAL` 표에도 같은 이름을 넣음), (나) 구조 검사: `move_space_done − __move_space` = 84, `trap2 − _cache_push` = 34, 객체 레이블 `_tlb_update_read`→`_tlb_update_write`→(`_pmove_crp`)… 은 기존 이웃 간격으로, `__move_space → _move_space_fault` = 100, `_move_space_fault → _cache_push_page` = 28, `_probe_rb → _probe_rl → _simple_lock` = 42·42, `_cache_push → _mon_exit` = 42, `_mon_exit` 크기 34(다음 레이블이 없으므로 `__text` 끝 − `_mon_exit` 이 NeXTMach 전용 뒤 텍스트까지 포함하는지 확인하고, 이 단계에서는 `_mon_exit` 바이트 34 B 를 비교하되 간격 검사는 NeXTMach 전용 텍스트를 지운 뒤로 미룸). 먼저 C7 객체의 51 항목에 돌려 새 FAIL 이 있는지 보고(정정이 나오면 그대로 보고).
6. 변형 11 개를 한 번에 어셈블: C8(주), 음성 대조 N1(`_tlb_update_write` 를 `PTESTW_BUG 1` 로 둠: 바이트), N2(`_probe_rl` 의 `movl a0@,d0` → `movb a0@,d0`: 바이트), N3(`__move_space` 의 `_move_space_fault` 대신 `_probe_recover`: 외부/자료 이름), N4(`_move_space_fault` 의 `jra move_space_done` → `jra _move_space_fault`: 지역 대상 이름·거리), N5(`_cache_push` 의 `nop` 제거: 바이트·길이), N6(`trap2` 조각을 `_cache_push` 안으로 옮겨 `rte` 대신 `rts`: 바이트), N7(`_mon_exit` 의 `_suser` → `_cache_push`: 외부 이름), N8(`move_space_done` 레이블 이름만 `move_space_end` 로: 이름 검사), N9(`__move_space` 의 `3:` 을 한 줄 아래로 옮김: 분기 목표 바이트), N10(`pload_*` 정의를 지우지 않음: `_tlb_update_*` 가 없어 필수 항목 누락 FAIL). 명세 `08_build/artifacts/m4p751/spec_c8.json`, 실행 `scratch/p737/run.sh m4p751-p1 …`(`08_build/runs/REGISTRY` 에 `m4p751` 없음 확인함; 변형 이름은 `^[A-Z][A-Z0-9]*$`).
7. 변형 시험: `scratch/p751/mutate_test6.py` = `mutate_test5.py` 를 `cmp9.py` 로 돌리고 새 변형 2 가지: `move_space_done` 이름만 변경(그 레이블을 가리키는 항목 `_move_space_fault` 와 `__move_space`(레이블 위치 검사) 가 FAIL), `trap2` 레이블 위치 이동(코드 그대로, 레이블과 `_scb` 쪽 항목은 따로; `_cache_push` 의 레이블 위치 검사만 FAIL).

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(11 변형 각각). (나) C8 에서 7 항목 EQUAL, `cmp9.py` 가 C8 의 58 항목에 `PASS 58 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 EQUAL 58 항목·8052 B·`NO-OBJ-NAME` 0·DIFF 0, 기존 51 항목 퇴행 없음(`cmp3.py` 31/31 포함). (다) 재배치 15 곳이 기대와 위치·종류·길이·이름·가산값·지역 대상(`move_space_done` 거리 +84·`trap2` +34·`_probe_rl` 복구 레이블 +30)까지 일치. (라) 객체 레이블 위치·간격 검사(위 5 (나))가 모두 일치; 원본에 없는 정의된 전역 3 → 1 개(`trap0` 만 남음; 이름 목록을 python 으로 대조); 객체에 없는 원본 텍스트 심볼 7 → 0 개. (마) 음성 대조 N1–N10 각각이 해당 항목 하나만 FAIL(N10 은 필수 항목 누락; 종료 코드 1)이고 나머지 항목은 PASS. (바) `check_data2.py` `ALL PASS`(자료 불변; `_scb` 의 `trap2` 항목 포함: `trap2` 레이블 위치가 바뀌어도 `_scb` 쪽 이름 검사가 통과함을 확인); 정의 없는 이름 집합이 C7 과 비교해 새로 생긴 것 `_suser`·`_boot_action`·`_reboot_vector` 만 늘고(예측) 그 외 변화는 python 으로 목록화해 보고; 사라지는 이름이 있으면 지운 구간에 나오는 이름이어야 함. (사) `cmp9.py` 가 C7 의 51 항목에서도 `PASS 51`. (아) 변형 시험 `ALL OK`. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) `move_space_done`·`3:` 등 새 지역 레이블 이름은 이 프로젝트의 것이며 원본에는 이름이 없습니다(위치만 일치). (나) `_move_space_fault` 의 `orl a_p1,d0`·`_mon_exit` 의 `andw #0x2000`(SR 의 상위 비트 검사)·`_suser` 호출·`_boot_action`·`_reboot_vector` 사용의 의미는 바이트에서 읽은 추정이며 주석에 단정하지 않습니다. (다) `_mon_exit` 는 단위의 마지막 항목이므로 객체 안에서 뒤에 NeXTMach 전용 텍스트(`trap0`·`syscall_*` 등)가 남으면 크기를 이웃 레이블로 확인할 수 없어 바이트 34 B 비교만 합니다(남은 NeXTMach 전용 텍스트 삭제 단계에서 확인). (라) 이 후보는 07 에 올리지 않으며 항목별 일치는 단위 전체 일치(순서·크기 8052 B·심볼 전부·자료)가 아닙니다. (마) `_scb` 의 `trap2` 항목은 원본 값이 `_cache_push`+34 인지 이 단계에서 `check_data2.py` 가 레이블 이름으로만 확인하므로 위치 일치는 `cmp9.py` 의 `trap2 − _cache_push` = 34 와 합쳐서 확인합니다.

### 751.1 §751 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 사실 6 의 `_mon_exit` 두 분기 목표를 "→+28"로 적음: 실제 목표는 둘 다 0x4002276(`_mon_exit`+20)이고 +28 은 마지막 주소 피연산자 내부(0x400227e)입니다(본문 고침). (2) 설계 3 에서 "세 `bra 3f`"라 적음: `bra 3f` 는 `movsl`·`movsw` 뒤 두 곳이고 `movsb` 경로는 `clrl d0` 으로 순차 진입합니다(`clrl` = `__move_space`+82, `movec d2,dfc` = +84; 본문 고침). `bnes +6` 은 인코딩 변위이므로 목표 주소로 적음. (3) `_mon_exit` 가 마지막 항목이라 크기 검사를 미룬다고 적었으나 C7 배치(`trap2` 뒤에는 `.data` 뿐)에서 `__text` 끝 − `_mon_exit` = 34 를 지금 검사할 수 있음. (4) 음성 대조 N8·N10 의 "하나만 FAIL" 기대와 N6·`trap2` 변형 명세가 모호했음. (5) `trap2` 를 `INTERNAL` 표에 넣는 것만으로는 `trap2` 로 향하는 텍스트 재배치가 없어 검사가 되지 않음(독립 위치 검사 필요).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_mon_exit` 분기 `660c`(0x4002268)·`6602`(0x4002272) 가 둘 다 0x4002276(+20) 으로 | python: 각 주소 바이트와 `주소+2+변위` 계산 | ✅ 본문 고침 |
| `__move_space` 분기 `6606`(0x40014f4)→0x40014fc, `6014`(0x40014fa)→0x4001510, `6606`(0x4001504)→0x400150c, `6004`(0x400150a)→0x4001510; `clrl` +82, `movec` +84 | python 바이트·목표 계산 | ✅ 본문 고침 |
| `80ae 000c` 는 `orl %fp@(12),%d0`, `60ff ffffffd8` → 0x4001512 | 앞서 python 바이트(`orig` 역어셈블) 목록과 계산(0x4001538+2−40) | ✅ |
| `_cache_push` +34 의 8 B(`jsr _cache_push; rte`), 원본 `_scb+0x88` = 0x0400225a | python: `_scb`+0x88 = 파일 오프셋 0xada9c 에서 0x400225a 읽음 | ✅ |
| `_pload_*`↔`_tlb_update_*`, `_probe_rb`↔`_probe_rl` 의 차이(+31 `f568`→`f548`; +9 복구 필드, +18 `10`→`20`) | 앞서 python 비교와 같은 값 | ✅ |
| C7 객체: `trap2` 8018, `__text` 8046 → 남은 28 B 가 전부 `trap2`; `trap0`·`syscall_*` 는 그보다 앞 | python: C7 객체 레이블 오프셋(`trap0` 7084, `trap2` 8018, 크기 8046) | ✅ |
| 철자 위험: `moveml #0x2030,sp@-`·`moveml sp@+,#0x0c04`·`movc dfc,d2`·`andw #0x2000,d0` 는 C8 에서 직접 확인(선례 없음), `jra` 후방 선례(C7 `jra fpsp_frame_err` `60ff ffff fff2`), `.globl __switch_context` 이중 밑줄 선례, `PTESTW_BUG` 는 `#if` 이므로 값 0 으로 바꾸면 됨 | 앞서 `grep`(C7 에 `moveml #0xfcfc,a0@(4)` 등만 있고 `sp@+` postincrement 없음)·`PTESTW_BUG` 위치(C7 373 행) 열음 | ✅ (철자 변형 추가) |
| 수치 338·58·8052·15·3→1·7→0 | python | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. `moveml` 의 비트 반전 여부는 C8 의 바이트로 확인하는 항목으로 남겼습니다.

### 751.2 §751 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. 철자 변형을 더함: C8R(`moveml #0x2030,sp@-`·`moveml sp@+,#0x0c04` 대신 레지스터 목록 `moveml d2/a2/a3,sp@-`·`moveml sp@+,d2/a2/a3`), C8A(`andw #0x2000,d0` 대신 `andiw #0x2000,d0`). C8 이 틀리면 통과하는 철자를 채택하고 시도를 모두 기록하며, 채택 후보가 (나)–(아)를 모두 통과해야 함.
2. `cmp9.py`: (가) 이웃 간격 검사: `__move_space`→`_move_space_fault` 100, `_move_space_fault`→`_cache_push_page` 28, `_probe_rb`→`_probe_rl` 42, `_probe_rl`→`_simple_lock` 42, `_tlb_update_read`→`_tlb_update_write` 46, `_tlb_update_write`→`_pmove_crp` 46, `_cache_push`→`_mon_exit` 42, **`__text` 끝 − `_mon_exit` = 34**(지금 가능; 지운 구간·남은 텍스트가 `_mon_exit` 뒤에 붙으면 FAIL), 각각 크기가 틀린 항목에 귀속; (나) 독립 위치 검사 `trap2 − _cache_push` = 34, `move_space_done − __move_space` = 84, `3:` 는 이름을 믿지 않고 두 `bra`(`6014`·`6004`)의 목표가 `__move_space`+82 의 `clrl` 이고 `movsb` 가 그곳으로 순차 진입하는 것을 바이트로 확인; (다) 새 7 항목의 필수 레이블이 정의돼 있고 전역·`__text` 소속·유일; (라) 필수 항목은 목록의 58 개 전부이고 누락은 FAIL; (마) 원본 심볼표에 없는 정의된 전역이 `trap0` 하나뿐이어야 함(그 외 FAIL); (바) `LOCAL[0x4001512]='move_space_done'`.
3. 변형을 17 개로(C8·C8R·C8A + 음성 대조 14): N1(`PTESTW_BUG 1`)→`_tlb_update_write`; N2(`movb`)→`_probe_rl`; N3(`_probe_recover`)→`__move_space`; N4(`jra _move_space_fault`)→`_move_space_fault`; N5(`_cache_push` 의 `nop` 제거)→`_cache_push`; N6(`trap2` 조각의 `rte`→`rts`)→`_cache_push`; N7(`_suser`→`_cache_push`)→`_mon_exit`; N8(`move_space_done` 정의와 참조를 함께 `move_space_end` 로)→`__move_space`·`_move_space_fault` 둘 다; N9(`3:` 를 `clrl` 아래로)→`__move_space`; N10A(`_pload_*` 이름 유지, `_tlb_update_*` 정의 없음)→필수 항목 `_tlb_update_read`·`_tlb_update_write` 누락 둘 다; N10B(`_tlb_update_*` 와 함께 옛 `_pload_read` 레이블도 정의)→원본에 없는 전역 FAIL(귀속은 `EXTRA-GLOBAL`); N11(`moveml #0x2038,sp@-`)→`__move_space`; N12(`_mon_exit` 의 `rte` 뒤 `nop`)→`_mon_exit`; N13(`_mon_exit` 의 `jmp a0@` 뒤 `nop`)→`_mon_exit`(끝 크기 36).
4. 변형 시험 `scratch/p751/mutate_test6.py`: `mutate_test5.py` + 새 변형: `move_space_done` 이름만 변경(`_move_space_fault`·`__move_space` 둘 다 FAIL), `move_space_done` 레이블과 `_move_space_fault` 의 변위 필드를 함께 +2 이동(이름 검사 통과, `__move_space` 위치 검사만 FAIL), `trap2` 레이블과 `_scb` 의 해당 주소 필드를 함께 +2 이동(`_cache_push` 위치 검사만 FAIL), `_mon_exit` 이름 누락(필수 항목 누락). 모두 지정한 항목만 FAIL.
5. 판정 기준 변경·추가: (마)는 위 변형별 귀속(N8 은 두 항목, N10A 는 두 항목 누락, N10B 는 `EXTRA-GLOBAL`)을 기대 집합으로 사용; (바)에서 undefined 이름 집합은 C7 에 비해 늘어난 이름이 정확히 {`_suser`, `_boot_action`, `_reboot_vector`} 이고 그 외 변화는 FAIL(사라진 이름은 지운 구간에 나오는 이름만 허용); `_scb` 가 `trap2` 레이블을 가리키는지는 `check_data2.py` 와 위 위치 검사를 함께 판정 근거로 씀; (사)는 C7 회귀(51 항목, 위 새 이웃 검사는 `_mon_exit` 가 목록에 있을 때만 적용)와 C8 필수항목 모드(58 항목)를 구분해 둘 다 실행.

### 751.3 결과: 6 단계 후보 C8 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p751/gen_locore8.py`(§750 의 `gen_locore7.py` 를 실행한 뒤 마지막 7 항목을 `plan 751 (D167, D024) BEGIN/END` 표시로 바꿈; 후보 17 개 `scratch/p751/locore_{C8,C8R,C8A,N1…N13,N10A,N10B}.s`), 비교기 `scratch/p751/cmp9.py`(§750 의 `cmp8.py` + 이웃 간격·`__text` 끝 크기·`trap2`/`move_space_done` 위치·`3:` 분기 바이트·원본에 없는 전역 규칙), 변형 시험 `scratch/p751/mutate_test6.py`, 항목 목록 `scratch/p751/ents58.json`, 명세 `08_build/artifacts/m4p751/spec_c8.json`. 실행: `m4p751-p1`(17 변형 어셈블; 종료 코드 34 개 모두 0, 표준 오류 0 B).

사전 확인(§751.2): (1) `cmp9.py` 를 C7 객체의 51 항목에 돌림 → `PASS 51 FAIL 0`(정정할 것 없음). (2) `mutate_test6.py` 를 C8 에 돌림: §750 의 26 변형 + 새 4 변형 = 30 개 모두 지정한 항목만 FAIL(`ALL OK`). 시험 기대값을 한 번 고쳤습니다: 필수 심볼 `_call_continuation` 이름 변경 시험에서 바뀐 이름이 원본에 없는 전역이기도 해서 새 `EXTRA-GLOBAL` 규칙이 `_mon_exit` 에도 FAIL 을 붙이는 것이 정당합니다(비교기 동작은 정당, 시험 기대값을 `[_call_continuation, _mon_exit]` 로 수정).

변경 요약: NeXTMach `pload_read`·`pload_write` 를 `tlb_update_read`·`tlb_update_write` 로 이름만 바꾸고 `PTESTW_BUG` 를 0 으로(원본 `f548`); `probe_rb` 뒤에 `probe_rl`(`movl a0@,d0`); NeXTMach `move_space` 를 `__move_space`(`link a6,#0`·`moveml #0x2030,sp@-`·`_active_threads`·`THREAD_RECOVER` 보존·`_move_space_fault`·`movsl/movsw/movsb`·`3: clrl d0`·`move_space_done:`·`moveml sp@+,#0x0c04`·`unlk a6; rts`)와 `_move_space_fault`(`orl a_p1,d0`·`a_p4/5/6` 에 `d1/a0/a1` 저장·`jra move_space_done`)로; NeXTMach `trap2` 를 `PROCENTRY (cache_push)` 와 `trap2: jsr _cache_push; rte`, 그리고 새 `_mon_exit`(`movw sp@,d0`·`andw #0x2000,d0`·`_suser`·`_boot_action`·`_reboot_vector`·`jmp a0@`)로. 철자는 첫 시도에서 모두 원본과 같았고(`moveml #0x2030,sp@-`·`moveml sp@+,#0x0c04`·`movc dfc,d2`·`andw #0x2000,d0`·`jra` 후방), 변형 C8R(레지스터 목록 `d2/a2/a3`)과 C8A(`andiw`)는 C8 과 객체 전체가 같음(SHA-256 앞 12 자 `d4b2d059064c` 셋 다).

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(17 변형 모두, 종료 코드 34 개 0, 표준 오류 0 B).
- (나) C8: 7 항목 EQUAL, `cmp9.py` `PASS 58 FAIL 0`(종료 코드 0), `cmp_strict2.py` 집계 `Counter({'EQUAL': 58})`·`EQUAL entries 58 bytes 8052`·DIFF 0·`NO-OBJ-NAME` 0, 기존 51 항목 퇴행 없음(`cmp3.py` 31/31). 독립 확인: 7 항목의 객체와 원본 차이는 전부 재배치 필드 15 곳 안(필드 밖 차이 0).
- (다) 재배치 15 곳이 기대와 위치·종류·길이·이름·가산값·지역 대상(`move_space_done` +84·`trap2` +34·`_probe_rl` 복구 레이블 +30)까지 일치.
- (라) 간격: `__move_space`→`_move_space_fault` 100, `_move_space_fault`→`_cache_push_page` 28, `_probe_rb`→`_probe_rl` 42, `_probe_rl`→`_simple_lock` 42, `_tlb_update_read`→`_tlb_update_write` 46, `_tlb_update_write`→`_pmove_crp` 46, `_cache_push`→`_mon_exit` 42, `__text` 끝 − `_mon_exit` = 34(객체 `__text` 8196 B, `_mon_exit` 끝 8196); `trap2 − _cache_push` = 34, `move_space_done − __move_space` = 84, `3:` 두 `bra` 가 `+82` 의 `clrl d0` 로; 원본에 없는 정의된 전역 3 → 1(`trap0` 만); 객체에 없는 원본 텍스트 심볼 7 → 0(`original unit symbols not defined in object (text): []`).
- (마) 음성 대조(지정 집합만 FAIL, 종료 코드 1): N1 `_tlb_update_write` `bytes differ at [31]`; N2 `_probe_rl` `bytes differ at [18]`; N3 `__move_space` `@20 local label ['_probe_recover'] expected ['_move_space_fault']`; N4 `_move_space_fault` `@24 local label ['_move_space_fault'] expected move_space_done`; N5 `_cache_push` 재배치 위치·간격 불일치; N6 `_cache_push` `bytes differ at [41]`; N7 `_mon_exit` `@10 local label ['_cache_push'] expected ['_suser']`; N8 `__move_space`(`label move_space_done missing`)·`_move_space_fault`(이름) 둘; N9 `__move_space`(`short branch at +60 does not reach +82`·바이트); N10A 필수 항목 `_tlb_update_read`·`_tlb_update_write` 누락 + `_mon_exit` 의 `EXTRA-GLOBAL`(`_pload_read`·`_pload_write` 가 정의된 전역; 계획 §751.2 5 에는 두 항목 누락만 적었으나 `_pload_*` 가 남는 것은 정당한 세 번째 FAIL); N10B `_mon_exit` `EXTRA-GLOBAL`(`_pload_read`); N11 `__move_space` `bytes differ at [7]`; N12 `_mon_exit` 재배치 위치·`__text` 끝 36; N13 `_mon_exit` `__text end - _mon_exit = 36 expected 34`.
- (바) `check_data2.py` `ALL PASS`(11 개; `_scb` 의 `trap2` 항목 포함); 정의 없는 이름 집합이 C7 의 44 개에서 정확히 {`_suser`, `_boot_action`, `_reboot_vector`} 만 늘어 47 개(사라진 이름 없음).
- (사) `cmp9.py` 가 C7 의 51 항목에서 `PASS 51`(회귀 모드), C8 의 58 항목에서 `PASS 58`(필수항목 모드). (아) 변형 시험 `ALL OK`. C8R·C8A 는 C8 과 객체가 같아 채택 조건 해당 없음.

한계: (가) `move_space_done`·`3:` 등 새 지역 레이블 이름은 이 프로젝트의 것(원본 이름 없음; 위치만 일치). (나) `orl a_p1,d0`·`andw #0x2000,d0`(SR 비트)·`_suser` 호출·`_boot_action`/`_reboot_vector` 사용·`THREAD_RECOVER` 보존의 의미는 바이트에서 읽은 추정이며 주석에 단정하지 않았습니다. (다) 이로써 단위 함수표 58 항목이 모두 항목별로 EQUAL 이지만 이것은 단위 전체 일치가 아닙니다: 객체 `__text` 는 8196 B(원본 단위 8052 B)로 NeXTMach 전용 `trap0`·`syscall_*`(144 B) 등이 남아 있고 객체 안 순서도 아직 원본과 다릅니다. (라) 이 후보는 07 에 올리지 않았습니다.


## 계획 752: m68k `locore.s` 구현 7 단계 — NeXTMach 전용 `trap0`·`syscall_*` 삭제와 단위 전체 대조 (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: §751.3 에서 단위 함수표 58 항목이 모두 항목별로 EQUAL 이 되었지만 객체 `__text` 는 8196 B(원본 단위 8052 B)입니다. python 으로 객체 레이블 오프셋을 원본 주소 − 0x4000310 와 비교하면 어긋나는 항목은 `addrerr`·`buserr`·`fpsp_done`·`fpsp_frame_err`·`trace`·`_cache_push`·`_mon_exit` 7 개이고 모두 +144 B 입니다. 그 144 B 는 NeXTMach 전용 `trap0`(객체 +7186)·`syscall_recover`(+7236)·`syscall_rtn`(+7250)·`syscall_fault`(+7322) 구간(+7186 ~ +7330)이며 `trap6` 와 `addrerr` 사이에 있습니다. 그 구간 밖에서 이 네 레이블을 쓰는 곳은 없습니다(후보 `scratch/p751/locore_C8.s` 를 `grep` 한 결과 구간 1571–1629 행 밖 참조 0 곳). 이 구간을 지우면 객체가 원본 단위의 크기·순서와 같아질 것으로 예측되므로, 이 단계는 그 삭제와 **단위 전체 대조**(항목별이 아니라 단위 전체)를 합니다. 07 에 쓰는 것은 아직 하지 않습니다(가칭 상수의 사용자 확인이 먼저).

사실(python; 원본 `__text`·심볼표·함수표·객체 `08_build/runs/m4p751-p1/stage/Q751__locore_C8.o`):
1. 함수표(`06_reconstruction/m68k-functions.tsv`)의 58 항목은 0x4000310 부터 0x4002284 까지 빈틈·겹침 없이 이어지고 크기 합이 8052 B 입니다(python: 연속 True).
2. 원본 심볼표에서 단위 안(텍스트 [0x4000310, 0x4002284))의 심볼은 64 개, 자료 단위([0x40ad964, 0x40adb34))의 심볼은 5 개(`_cache`·`_fault_error`·`_fpu_version`·`_probe_recover`·`_scb`)입니다.
3. C8 객체의 정의 없는 이름은 47 개이고 그 중 원본 심볼표에 없는 것은 `_old_syscall` 하나뿐입니다(삭제할 `trap0` 구간이 부르는 NeXTMach 전용 함수). 섹션은 `__text` 8196 B·`__data` 464 B 두 개입니다.
4. 원본 단위 텍스트 전체의 기대 재배치(§744 이후의 `expected()`; 원본에는 재배치 레코드가 없으므로 원본 명령 피연산자에서 만든 후보 객체 요구 목록)는 189 곳이고, 그 중 단위 밖 외부 대상의 별칭 집합은 36 개, 심볼 없는 기준 이름은 `_cnt`+{4,8,12}·`_m68k_kernel_mmu_rp`+4 입니다. `_scb` 의 72 항목은 서로 다른 이름 24 개입니다(§742 `scb_names.json`).

설계(후보 `scratch/p752/locore_C9.s`; 생성기 `scratch/p752/gen_locore9.py` = §751 의 `gen_locore8.py` 실행 뒤 `/* old UNIX syscall handler */` 부터 `/* exception handlers */` 직전까지(`trap0`·`syscall_recover`·`syscall_rtn`·`syscall_fault`)를 `/* plan 752 (D167, D024) BEGIN: … */ … /* plan 752 END */` 표시로 지움; 07 에는 쓰지 않음):
1. 이것 외의 소스 변경은 없음: 쓰이지 않게 된 NeXTMach 매크로(`TRAP`·`TRAPVEC`·`INTR_CALL_LIT`·`DO_ALIGNMENT`·`IPL_INTR` 등)와 머리 블록의 쓰지 않는 상수(`UTASK`·`THREAD_AST`·`FSIZE`·`SIZEOF_*` 등)와 조건 컴파일로 객체에 나오지 않는 NeXTMach 조각(`#if NCPUS > 1`·`#ifdef FIXME`·`NIPLMEAS` 등)은 이 단계에서 그대로 둠(객체에 영향이 없고, 정리 여부는 07 에 쓸 때 별도로 결정).
2. 단위 대조 도구 `scratch/p752/cmp_unit.py`(후보 객체 하나를 받아 항목별 검사 `cmp9.py` 의 58 항목 `PASS 58` 결과를 포함하고 아래를 더함; 하나라도 어긋나면 종료 코드 1):
   (U1) 섹션: `__text` 가 정확히 8052 B, `__data` 464 B, 다른 비어 있지 않은 섹션 없음.
   (U2) 함수표 연속·크기 합 8052 B(python 재확인).
   (U3) 위치: 함수표의 **모든 이름(별칭 포함)** 이 객체에 정의되어 있고 객체 오프셋이 `원본 주소 − 0x4000310` 과 정확히 같음(곧 단위의 순서·크기 전체 일치).
   (U4) 전역 심볼: 객체의 `__text` 정의 전역 이름과 오프셋이 원본 단위 텍스트 심볼 64 개와 정확히 같고(없는 것도 넘치는 것도 없음), `__data` 정의 전역이 원본 5 개와 오프셋까지 같음.
   (U5) 바이트: `__text` 8052 B 전체가 원본과 같음(재배치 필드 4 B 만 가림); 가리는 필드 집합이 단위 전체 `expected()` 의 189 곳과 정확히 같고 객체 `__text` 재배치 레코드 수가 189 개(중복·초과 0).
   (U6) 정의 없는 이름: 객체의 정의 없는 이름 집합이 (텍스트의 단위 밖 외부 대상 이름 + `_scb` 의 외부 이름 + 심볼 없는 기준 이름 `_cnt`·`_m68k_kernel_mmu_rp`) 에서 객체가 정의한 이름을 뺀 집합과 같음(별칭이 있는 주소는 별칭 하나가 있으면 충족; 모든 이름이 원본 심볼표에 있어야 하며 `_old_syscall` 처럼 원본에 없는 이름은 FAIL).
   (U7) 자료: `scratch/p746/check_data2.py` 의 `ALL PASS`(464 B·`_scb` 72 항목·`argc_table` 8 항목·전역 자료 5 개).
   (U8) 정보 출력(판정 아님): 함수표에 없는 객체 지역 레이블 목록.
3. 변형 7 개를 한 번에 어셈블: C9(주), 음성 대조 N1(`trap0` 구간을 지우지 않음 = C8 과 같은 소스: U1·U3 실패), N2(`_mon_exit` 의 `jsr _suser` → `jsr _suser2`: 정의 없는 이름이 원본에 없음; U6), N3(`.globl _extra_sym` 과 레이블을 `_mon_exit` 앞에 추가: 전역 집합 초과; U4), N4(`_probe_rb` 와 `_probe_rl` 소스 블록의 순서 바꿈: 레이블 위치·바이트; U3·항목별), N5(`_cache_push` 의 `nop` 제거: 크기 8050; U1·U3), N6(`_fpu_version` 을 `.long 2` 로: U7). 명세 `08_build/artifacts/m4p752/spec_c9.json`, 실행 `scratch/p737/run.sh m4p752-p1 …`(`08_build/runs/REGISTRY` 에 `m4p752` 없음 확인함; 변형 이름은 `^[A-Z][A-Z0-9]*$`).
4. 변형 시험: `scratch/p752/mutate_unit.py` — 메모리 사본으로 `cmp_unit.py` 만 시험: 레이블 한 개를 +2 이동·정의된 전역 한 개 삭제·정의된 전역 한 개 이름 변경·정의 없는 이름 추가(심볼 한 개를 `UNDF` 로 추가하거나 이름 변경)·`__text` 재배치 레코드 한 개 삭제·중복·`__text` 크기 필드 +4 의 6 가지. 모두 FAIL.

판정 기준(미리 정함; 낮추지 않음): (가) 어셈블 오류·경고 0(7 변형 각각). (나) C9 에서 `cmp_unit.py` 의 U1–U7 전부 통과(종료 코드 0), `cmp9.py` `PASS 58 FAIL 0`, `cmp_strict2.py` 집계 EQUAL 58·8052 B·DIFF 0, `check_data2.py` `ALL PASS`. (다) 객체 `__text` 가 8052 B 이고 7 개 어긋났던 항목의 오프셋이 원본과 같음(C9 의 `addrerr` 7186 등). (라) 원본에 없는 정의된 전역 0 개(`trap0` 제거), 정의 없는 이름이 모두 원본 심볼표에 있음(`_old_syscall` 제거; 정의 없는 이름 개수는 47 → 46 예측이며 U6 집합 일치로 판정). (마) N1–N6 각각이 지정한 검사(들)에서 FAIL(종료 코드 1)이고 다른 검사는 가능한 한 통과. (바) `mutate_unit.py` 의 6 가지가 모두 FAIL. 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) 이 대조는 원본 바이트에서 만든 기대 재배치와 원본 심볼표에 의존하며 원본 소스를 증명하지 않습니다(소스 형태·이름은 바이트가 정한 꼴만; 지역 레이블 이름은 NeXTMach 이름 또는 이 프로젝트의 이름). (나) 객체의 지역 레이블(`access`·`trap` 등)은 원본 심볼표에 없으므로 이름 일치가 아니라 위치 일치입니다. (다) 쓰이지 않는 NeXTMach 매크로·상수·조건 조각이 소스에 남는 것은 객체에 영향이 없지만 07 에 올리는 파일의 모습(NeXTMach 파일에서 바뀐 곳의 표시)에 영향이 있으므로 07 쓰기 단계의 결정 사항입니다. (라) 이 후보는 07 에 올리지 않습니다.

### 752.1 §752 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) §751 의 `cmp9.py` 가 원본에 없는 정의된 전역을 `['trap0']` 와 **정확히 같을 때만** 통과시키므로(`cmp9.py:194` `if extra != ['trap0']`) `trap0` 를 지운 C9 에서는 오히려 실패합니다(C9 모드와 C8 회귀 모드를 분리해야 함). (2) U6 의 "객체가 정의한 이름을 뺀다"는 계산이 외부 이름을 `ABS` 같은 잘못된 정의로 바꿔도 통과시킴(U6 에서 허용 정의를 검증된 단위 내부 이름으로만 제한해야 함). (3) U4 에서 중복 심볼 레코드를 사전·집합으로 만들기 전에 거부하지 않았고 외부 정의 종류(`N_SECT|N_EXT`)·섹션·섹션 기준 오프셋을 함께 비교한다고 적지 않음. (4) `mutate_unit` 의 "6 가지"는 삭제·중복을 따로 세면 7 개. (5) N1·N2 의 "다른 검사는 가능한 한 통과"는 정당한 연쇄 실패(N1 은 U4·U5·U6 도 실패)를 배제하는 기준으로 쓸 수 없음. (6) `_scb` 의 단위 밖 외부 이름은 24 종이 아니라 9 종(`bsun`·`dz`·`fline`·`inex`·`operr`·`ovfl`·`snan`·`unfl`·`unsupp`).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 위치가 다른 항목 정확히 7 개(`addrerr`·`buserr`·`fpsp_done`·`fpsp_frame_err`·`trace`·`_cache_push`·`_mon_exit`), 모두 +144; 원본 64 심볼 중 객체에 없는 것 0, 객체의 추가 전역은 `trap0` 뿐; 원본 단위 심볼 64 = 함수표 이름 64 | python(이번 세션): 불일치 이름 7 개와 차이 집합 `[144]`; `orig not defined global in object: []`; `object globals not in orig: ['trap0']`; 표 이름 64 개와 원본 심볼의 차집합 양쪽 `[]` | ✅ |
| C8 텍스트 재배치 195 개 중 삭제 구간 `[7186,7330)` 에 6 개, 남는 189 개의 위치를 144 이동하면 기대 위치 집합 189 와 같음 | python: 195·6 출력, `shifted == expected positions: True`(189) | ✅ |
| 삭제 구간 밖에 `trap0`·`syscall_*`·`_old_syscall` 참조 없음, `.globl trap0, _active_threads` 가 `_active_threads` 의 유일한 `.globl` | `grep -n`(이번 세션): 네 이름과 `_old_syscall` 의 출현 줄이 모두 1572–1627 행 안; `_active_threads` 는 `.globl` 선언 없이도 정의 없는 외부 심볼로 나오는 선례(`_suser`·`_panic`) | ✅ (C9 처리는 실행에서) |
| 정의 없는 이름 기대 집합 E = (단위 밖 텍스트 대상 이름 ∪ `_scb` 외부 이름 ∪ {`_cnt`, `_m68k_kernel_mmu_rp`}) = 46 개 = C8 의 47 개 − `_old_syscall`; `_scb` 외부 이름 9 종 | python: E 46 개, `E == C8 undefined − {_old_syscall}: True`, `_scb` 외부 `['bsun','dz','fline','inex','operr','ovfl','snan','unfl','unsupp']` | ✅ |
| 객체 `__text` 에 정렬 패딩이 붙지 않음(C8 `__text` 크기가 4 의 배수로 올림되지 않음: N5 8194 B·N12 8198 B) | python: N5 8194·N12 8198·N13 8198 | ✅ |
| 객체 머리: big-endian·cputype 6·`MH_OBJECT`(filetype 1), 섹션 이름 유일 | python: `{'endian':'big','cputype':6,'filetype':1,'ncmds':2,'flags':0}` | ✅ (U1 에 추가) |
| `_start_text`·`ZERO_PHYS` 는 객체 +6 지역 심볼로 U4 가 아니라 U8 에 출력 | 앞서 python 레이블 목록(`('_start_text', 6), ('ZERO_PHYS', 6)`) | ✅ |
| 수치 8052·58·64·5·189·36·144·7·47 | python | ✅ (`mutate_unit` 은 7 가지 이상으로 정정) |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. C9 의 실제 크기·심볼 처리는 아직 실행 전입니다.

### 752.2 §752 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. `scratch/p752/cmp10.py` = `cmp9.py` + 원본에 없는 정의된 전역의 허용 집합을 환경변수 `ALLOWED_EXTRA`(기본 빈 집합; C8 회귀 모드는 `trap0`)로 받는 정확 일치 규칙. 단위 모드(`cmp_unit.py`)는 빈 집합.
2. `cmp_unit.py` 의 보강: (U1) 객체 머리(big-endian·cputype 6·filetype 1)와 섹션 이름 유일을 포함; (U4) 심볼 레코드의 이름 중복(같은 이름의 둘 이상 레코드)을 사전 구성 전에 거부, 정의 전역은 `N_SECT|N_EXT`·올바른 섹션·섹션 기준 오프셋을 각각 비교(별칭은 이름마다 따로); (U5) 가리는 필드는 기대 위치(`expected()` 의 189 곳)로만 만들고 `cmp10.py` 의 항목별 종류·길이·pc 상대·외부 여부·이름·가산값·지역 대상 검사 결과를 그대로 요구; (U6) 기대 외부 집합 E(위 계산; 별칭이 생기면 주소별 허용 이름 집합으로 일반화)의 각 이름은 객체에서 `UNDF`·외부·값 0 이어야 하고, 객체 심볼 종류는 `SECT`·`UNDF` 만 허용(`ABS`·`COMMON`·`INDR` 등은 FAIL), 빼는 내부 정의는 검증된 단위 내부 이름(함수표 이름 64 + 자료 심볼 5 + `_scb` 가 가리키는 내부 레이블 `trap2` 등)으로만 제한; 객체의 `UNDF` 집합이 E 와 정확히 같고 모두 원본 심볼표에 있음.
3. 변형 시험 `scratch/p752/mutate_unit.py`(메모리 사본으로 `cmp_unit.py` 의 U1–U6 만; U7 은 `check_data2.py` 가 파일을 읽으므로 이미 `scratch/p746` 의 변형 시험으로 확인): 독립 실행 15 가지 — 레이블 한 개 +2 이동; 정의된 전역 하나 삭제; 정의된 전역 하나 이름 변경; 정의 없는 이름 하나 추가(원본 심볼표에 없는 이름); 정의 없는 이름 하나 추가(원본 심볼표에 있으나 기대 밖: 예 `_bzero`); `__text` 재배치 레코드 하나 삭제; 하나 복제; `__text` 크기 필드 +4; 별칭 `_copyoutmsg` 하나만 삭제; 같은 이름 심볼 레코드 복제; `_suser` 를 `UNDF` 에서 값 0 의 `ABS` 정의로; 마스크 밖 바이트 한 개 변경; 외부 재배치 가산값 변경(`_cnt`+8 → +12); 비어 있지 않은 추가 섹션 하나 추가; 객체 머리 `cputype` 변경. 모두 FAIL.
4. 판정 기준 변경·추가: (마) N1–N6 은 지정한 검사에서 FAIL 하면 되고 N1 의 U1·U3·U4·U5·U6 연쇄 실패, N2 의 U6·항목별 실패 같은 정당한 연쇄 실패는 허용(실패한 검사 목록을 모두 기록); (바) `mutate_unit.py` 15 가지 모두 FAIL; (사) C9 의 정의 없는 이름이 정확히 E(46 개)이고 모두 `UNDF`·외부·값 0 이며 `_active_threads` 도 그 안에 있음(없으면 `.globl _active_threads` 를 삭제 구간 밖에 두는 변형을 추가하고 이유를 기록); (아) C8 회귀: `cmp10.py` 를 `ALLOWED_EXTRA=trap0` 으로 C8 의 58 항목에 돌려 `PASS 58`(비교기 회귀 확인).

### 752.3 결과: 7 단계 후보 C9 — 단위 전체 대조 통과 (수락 아님; 07 변경 없음; 2026-11-06)

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p752/gen_locore9.py`(§751 의 `gen_locore8.py` 를 실행한 뒤 NeXTMach 전용 `trap0`·`syscall_recover`·`syscall_rtn`·`syscall_fault` 구간을 `plan 752 (D167, D024) BEGIN/END` 표시로 지움; 후보 7 개 `scratch/p752/locore_{C9,N1…N6}.s`), 항목별 비교기 `scratch/p752/cmp10.py`(§751 의 `cmp9.py` + 원본에 없는 전역 허용 집합 `ALLOWED_EXTRA` 환경변수), 단위 대조 `scratch/p752/cmp_unit.py`(U1–U8), 변형 시험 `scratch/p752/mutate_unit.py`, 명세 `08_build/artifacts/m4p752/spec_c9.json`. 실행: `m4p752-p1`(7 변형 어셈블; 종료 코드 14 개 모두 0, 표준 오류 0 B).

사전 확인(§752.2): (1) `cmp10.py` 를 `ALLOWED_EXTRA=trap0` 으로 C8 의 58 항목에 돌림 → `PASS 58 FAIL 0`(회귀 모드), 환경변수 없이 돌리면 C8 은 `EXTRA-GLOBAL … ['trap0']` 로 FAIL(정확 일치 규칙이 작동). (2) `cmp_unit.py` 를 C8 에 음성 대조로 돌림 → U1·U3·U4·U5·U6 FAIL(크기 8196·7 항목 +144·`trap0` 추가·재배치 195 대 189·`_old_syscall`), U2·U7 통과. (3) `mutate_unit.py`(독립 15 가지)를 C9 에 돌림: 모두 FAIL(`ALL OK`) — 레이블 +2·정의된 전역 삭제·이름 변경·원본에 없는 정의 없는 이름 추가·원본에 있으나 기대 밖인 `_printf` 추가·재배치 삭제·복제·`__text` 크기 +4·별칭 `_copyoutmsg` 하나 삭제·같은 이름 심볼 복제·`_suser` 를 `ABS` 정의로·마스크 밖 바이트 변경·외부 가산값 변경·추가 섹션·`cputype` 변경. 처음에는 `_bzero` 를 썼으나 이미 있는 정의 없는 이름과 겹쳐 U4(중복)로만 잡히던 것을 `_printf` 로 바꿔 U6 시험이 되게 고침. (4) 항목별 변형 시험 `mutate_test6.py` 를 `cmp10.py`(`ALLOWED_EXTRA` 빈 값)로 C9 에 돌림: 30 개 모두 `ALL OK`.

변경: NeXTMach 전용 `/* old UNIX syscall handler */`(`trap0`·`syscall_recover`·`syscall_rtn`·`syscall_fault`; 144 B)를 지움. 소스의 다른 변경 없음.

판정(미리 정한 기준대로; python·도구 출력):
- (가) 어셈블 오류·경고 0(7 변형 모두, 종료 코드 14 개 0, 표준 오류 0 B).
- (나) C9: `cmp_unit.py` U1–U7 전부 통과(`UNIT PASS`, 종료 코드 0): U1 big-endian·cputype 6·MH_OBJECT·섹션 `__text` 8052 B·`__data` 464 B·다른 비어 있지 않은 섹션 없음; U2 함수표 연속·합 8052; U3 함수표의 모든 이름(별칭 포함)이 원본 주소 − 0x4000310 에 정확히 위치; U4 정의 전역이 원본 단위 텍스트 심볼 64 개·자료 5 개와 이름·오프셋 모두 정확히 같고 중복 이름 없음; U5 `__text` 8052 B 전체가 원본과 같음(재배치 필드만 가림; 필드 189 곳 = 기대 189 곳 = 객체 재배치 레코드 189 개, 중복·초과 0, 항목별 `cmp10.py` 58 항목 PASS); U6 정의 없는 이름이 기대 집합 46 개와 정확히 같고 모두 `UNDF`·외부·값 0·원본 심볼표에 있음(`_active_threads` 포함), 심볼 종류는 `SECT`·`UNDF` 뿐; U7 `check_data2.py` `ALL PASS`. 독립 확인: `cmp_strict2.py` `Counter({'EQUAL': 58})`·`EQUAL entries 58 bytes 8052`·`defined globals 69 not in original symbols: []`·원본 단위 심볼 중 객체에 없는 것 텍스트 0·자료 0; python 직접 비교로 객체 `__text` 8052 B 와 원본 단위 8052 B 의 차이 536 B 는 전부 재배치 필드 189 곳 안(필드 밖 0).
- (다) 객체 `__text` 8052 B, 이전에 어긋났던 7 항목의 오프셋이 원본과 같음(U3). (라) 원본에 없는 정의된 전역 0 개(`trap0` 제거), 정의 없는 이름은 46 개(47 → 46; `_old_syscall` 제거; C8 의 정의 없는 이름에서 정확히 그것만 빠짐), 모두 원본 심볼표에 있음.
- (마) 음성 대조(실패한 검사 목록을 모두 기록; 연쇄 실패는 정당함): N1(구간 유지) U1·U3·U4·U5·U6; N2(`_suser2`) U5(항목별)·U6; N3(`_extra_sym`) U4·U5(항목별 `EXTRA-GLOBAL`); N4(`probe_rb`↔`probe_rl` 이름 교환) U3·U4·U5; N5(`nop` 제거) U1(8050 B)·U3·U4·U5; N6(`_fpu_version` `.long 2`) U7(`bytes outside reloc positions equal original [7]`). 모두 종료 코드 1.
- (바) `mutate_unit.py` 15 가지 모두 FAIL. (사) U6 의 46 개가 정확히 E 이고 `_active_threads` 가 그 안에 있음(`.globl` 선언을 지운 뒤에도 정의 없는 외부 심볼로 나옴; 별도 `.globl` 변형은 필요 없었음). (아) C8 회귀 PASS 58.

한계: (가) 이 대조는 원본 바이트에서 만든 기대 재배치와 원본 심볼표에 의존하며 원본 소스를 증명하지 않습니다(지역 레이블 이름은 NeXTMach 이름 또는 이 프로젝트의 이름이고 원본에는 이름이 없어 위치만 일치). (나) 이것은 candidates 가 원본 단위 [0x4000310,0x4002284)의 `__text` 8052 B 와 `__data` 464 B 를 **같은 바이트로** 만들어 낸다는 증거이고, 원본이 이 소스에서 컴파일되었다는 증거가 아닙니다. (다) 쓰이지 않는 NeXTMach 매크로·상수·조건 조각이 소스에 남아 있어(객체에는 영향 없음) 07 에 올리는 파일의 모습은 별도 결정 사항입니다. (라) 이 후보는 07 에 올리지 않았습니다. 남은 일: 07 반영(PROVENANCE·MODIFICATIONS·DECISIONS·상태표·근거 문서), 가칭 상수(`R_A6`·`THREAD_TASK`·`TASK_U_ADDRESS`·`FSAVE_BIT`) 사용자 확인, 소스 정리 범위 결정, 그리고 M5 컴파일 줄·원본 재배치 수락 절차에 맞춘 최종 수락 확인.


## 계획 753: m68k `locore.s` 07 반영 1 — 포함 헤더를 07 스테이징 꼴로 바꾼 후보 C10 과 확인 run (scratch 후보만; 07 변경 없음; 2026-11-06)

고른 까닭: C9 는 단위 전체 대조를 통과했지만(§752.3) 그 확인 run 은 진단 스테이지(`08_build/runs/tools/m4p752p1-stage`)에 NeXTMach 헤더 11 개를 `inc_locore_*/next/*.h` 로 얹어 컴파일한 것이어서, 07 에 올릴 파일의 `#import` 꼴(스테이징의 SDK·07 헤더로 풀리는 `<m68k/…>`)과 다릅니다. 이전 어셈블리(§512 `libc.s`: `<next/cframe.h>` → `<m68k/cframe.h>`, §514 `monitor.s`: `<m68k/cframe.h>`·`<next/cpu.h>`(어셈블리 전용)·`<m68k/spl.h>`)와 같은 방식(D104)으로 포함 줄을 07 꼴로 바꾸고, 그 결과가 C9 와 같은 객체를 내는지 확인하는 것이 이 단계입니다. 07 에 쓰는 것은 다음 계획(§754)입니다. 결정 D168(가칭 상수 이름 유지·표시, NeXTMach 잔여 텍스트 그대로)을 따릅니다.

사실(python; 후보 C9 소스·스테이징 `08_build/runs/m4p752-p1/src`·NeXTMach `mk-108.1`·07):
1. C9 의 `#import` 줄은 17 개: 설정 머리 5(`<cpus.h>`·`<cputypes.h>`·`<iplmeas.h>`·`<eventmeter.h>`·`<mach_ldebug.h>`), `<sys/kern_return.h>`·`<sys/errno.h>`·`<sys/reboot.h>`, NeXTMach 머리 9(`<next/cframe.h>`·`<next/vm_param.h>`·`<next/vmparam.h>`·`<next/cpu.h>`·`<next/psl.h>`·`<next/pcb.h>`·`<next/mmu.h>`·`<next/trap.h>`·`<next/spl.h>`). 소스가 머리 블록 밖에서 쓰는 대문자 식별자 41 개(헤더 유래만이 아니라 기능 매크로 34·구성 매크로 `GDB`/`MACH_LDEBUG`/`NCPUS`/`NIPLMEAS` 4·레이블 `ZERO_PHYS` 1·조건명 `DEBUG`/`FIXME` 2 를 포함; 소문자 `a_p0`–`a_p6` 은 별도) 중 헤더에서 오는 이름은: `PROCENTRY`·`PROCEXIT`(`cframe.h`), `I_IPL3/4/6/7_BASE/BITS`·`MC68030`·`MC68040`(`cpu.h`), `FC_SUPERI`·`FC_USERD`·`FC_USERI`·`SIZE_LONG`·`SIZE_WORD`(`mmu.h`), `EF_ACCESS`·`EF_LONGBUS`·`EF_NORMAL6`·`EF_SHORTBUS`·`SS_FCODE`·`SS_TM`(`reg.h`; C9 는 `pcb.h` 를 통해 들였음), `T_ADDRERR`·`T_BUSERR`·`T_MMU_*`·`T_STRAY`(`trap.h`), `INTSTACK_SIZE`(`vm_param.h`), `EINVAL`(`errno.h`), `KERN_INVALID_ARGUMENT`(`kern_return.h`). `VM_PROT_READ`·`VM_PROT_WRITE`(1·2)는 헤더가 아니라 C9 의 머리 `#define` 블록(46–47 행)이 이미 정의합니다.
2. 07 스테이징(M4/M5 기본 입력; `08_build/runs/m4p752-p1/src`)에는 이미 `src/bsd/m68k/{cframe,cpu,mmu,reg,psl,spl,vmparam}.h`, `src/bsd/next/cpu.h`(어셈블리 전용; `monitor.s` 용), `src/mach/m68k/vm_param.h`, `src/mach/kern_return.h`, `src/mach/vm_prot.h`, `src/bsd/sys/{errno,reboot}.h`, `src/generated/{iplmeas,…}.h` 가 있고, 위 식별자의 값은 python 으로 NeXTMach 와 모두 같습니다(`I_IPL*` 18/12·17/1·2/12·0/2, `MC68030` 0·`MC68040` 1, `FC_*`·`SIZE_*`, `EF_*`·`SS_*`, `INTSTACK_SIZE` 4096, `KERN_INVALID_ARGUMENT` 4, `VM_PROT_*` 1·2, `a_p0` `a6@(0x8)`).
3. `T_*` 는 SDK(`08_build/artifacts/m0p413/sdk-m68k`)에 헤더가 없고, 진단용 `inc_locore_*/next/trap.h`(NeXTMach 원문)와 i386 `trap.h` 를 제외한 스테이징 기본 입력에도 정의가 없습니다. 07 에서는 `src/machdep/m68k/trap.c:94–96,116…` 이 `T_BUSERR 0x08`·`T_ADDRERR 0x0c`·`T_MMU_BUSERR 0x400` … 7 개를 자기 안에서 정의하지만 `T_STRAY` 는 거기에도 없습니다(NeXTMach `next/trap.h:17` 의 `T_STRAY 0x00` 과 원본 `mmu_type` 표 항목 0x4002170 의 0 이 근거). 원본 바이트가 값을 줍니다: `movel #8,%sp@-`(`T_BUSERR`)·`movel #12,%sp@-`(`T_ADDRERR`)·`movel #1040,%d2`(`T_MMU_INVALID` 0x410)·`mmu_type` 표 `0x400 0x404 0x408 0 0x40c 0x410`(`T_MMU_BUSERR`·`LIMIT`·`SUPER`·`T_STRAY`·`WRITE`·`INVALID`; §748). 곧 `locore.s` 도 `trap.c` 처럼 머리 `#define` 블록에 `T_*` 8 개를 값과 근거를 붙여 둡니다.

설계(후보 `scratch/p753/locore_C10.s`; 생성기 `scratch/p753/gen_locore10.py` = §752 의 `gen_locore9.py` 실행 뒤 `#import` 구간을 `/* plan 753 (D104, D168, D024) BEGIN: … */ … /* plan 753 END */` 표시로 바꿈; 07 에는 쓰지 않음):
1. 포함 줄(주 후보 V1; D104 의 "NeXTMach `next/X.h` → 07 스테이징의 `m68k/X.h`"): 설정 머리 5 개와 `<sys/errno.h>`·`<sys/reboot.h>` 는 그대로, `<sys/kern_return.h>` → `<mach/kern_return.h>`, `<next/cframe.h>` → `<m68k/cframe.h>`, `<next/vm_param.h>` → `<mach/m68k/vm_param.h>`, `<next/vmparam.h>` → `<m68k/vmparam.h>`, `<next/cpu.h>` 그대로(어셈블리 전용; `monitor.s` 선례), `<next/psl.h>` → `<m68k/psl.h>`, `<next/mmu.h>` → `<m68k/mmu.h>`, `<next/spl.h>` → `<m68k/spl.h>`, 새로 `<m68k/reg.h>`(`pcb.h` 가 들이던 `EF_*`·`SS_*` 용), `<next/pcb.h>`·`<next/trap.h>` 는 지움(`trap.h` 는 위 3 의 `T_*` 정의가 대신; `pcb.h` 의 상수는 D167 의 머리 블록이 이미 정의). `VM_PROT_*` 는 C9 의 머리 블록이 정의하므로 `<mach/vm_prot.h>` 는 들이지 않음(스테이징 `vm_prot.h:78` 이 어셈블러로 가는 `typedef int vm_prot_t;` 와 `((vm_prot_t) 0x01)` 형 정의를 무조건 내므로 들이면 오히려 재정의·어셈블 오류).
2. 머리 `#define` 블록에 `T_*` 8 개를 근거 주석(`plan 753: value from the original bytes`; 7 개는 07 `trap.c` 와 같은 값, `T_STRAY` 는 NeXTMach `trap.h` 값)과 함께 더함(D168 의 "값의 근거는 원본 바이트 위치" 표시와 같은 방식).
3. 파일 머리: C9 의 첫 두 줄 후보 주석을 07 용 머리 주석으로 바꿈(NeXTMach 의 `#define D25B 1`… 설정 줄·`Copyright (c) 1987, 1988 NeXT, Inc.` 머리는 그대로; 새 머리 주석은 계획 번호·결정 번호·`this project's name` 표시 목록(`R_A6`·`THREAD_TASK`·`TASK_U_ADDRESS`·`FSAVE_BIT`)만 담고 어셈블 결과에 영향이 없음).
4. 변형: C10(V1), C10B(`<mach/m68k/vm_param.h>` 대신 `<mach/vm_param.h>`), 음성 대조 N1(`T_MMU_LIMIT` 값 0x405: `mmu_type` 표 바이트), N2(`<next/cpu.h>` 줄 삭제: `I_IPL*`·`MC68030` 미정의), N3(`<m68k/mmu.h>` 줄 삭제: `FC_*`·`SIZE_*` 미정의). 명세 `08_build/artifacts/m4p753/spec_c10.json`(`inc` 빈 목록: NeXTMach 헤더를 얹지 않고 스테이징의 헤더로만 풀림; `defs` `-DASSEMBLER`; 변형 이름 `^[A-Z][A-Z0-9]*$`), 실행 `scratch/p737/run.sh m4p753-p1 …`(`08_build/runs/REGISTRY` 에 `m4p753` 없음 확인함).
5. 객체 동일성 도구 `scratch/p753/cmp_obj.py OBJ REF`: stab 이 아닌 심볼(이름·종류·섹션·값·외부 여부), 각 섹션의 크기·바이트·재배치 표(전 필드), 정의 없는 이름 집합이 REF 와 완전히 같은지(디버그 stab 은 파일 이름이 달라 제외; 제외한 stab 개수는 보고). REF = C9 객체(`m4p752-p1` 의 `Q752__locore_C9.o`). 그리고 `cmp_unit.py` 가 C10 에서 `UNIT PASS`, `check_data2.py` `ALL PASS`.
6. 의존 목록(`-M`): 각 변형의 `.d` 목록에서 `inc_locore_*` 경로 0 개, NeXTMach 원문 경로 0 개, i386 경로 0 개이고 `next/` 는 `bsd/next/cpu.h` 뿐인지 python 으로 집계.

판정 기준(미리 정함; 낮추지 않음): (가) C10 어셈블 오류·경고 0(다른 변형이 실패하면 이유를 기록하고 채택 후보가 아래를 모두 통과해야 함). (나) 채택 후보의 객체가 C9 객체와 `cmp_obj.py` 로 완전히 같고(stab 제외) `cmp_unit.py` `UNIT PASS`·`check_data2.py` `ALL PASS`. (다) 채택 후보의 의존 목록에 진단용 헤더(`inc_locore_*`)·NeXTMach 원문·i386 이 없고 `next/` 헤더는 `bsd/next/cpu.h` 하나. (라) 음성 대조 N1–N3 가 각각 `cmp_obj.py` 또는 어셈블 오류로 달라짐(어셈블이 실패하는 경우도 "달라짐"으로 기록). (마) `T_*` 8 개의 값이 원본 바이트(`mmu_type` 표 0x4002164 부터·`movel #8`(0x4002158)·`movel #12`(0x4001f7e)·`movel #1040`(0x4002014))와 같고, 그 중 7 개(`T_STRAY` 제외)는 07 `trap.c` 의 정의 값과도 python 으로 같음. (바) 07 은 그대로(git status 로 확인). 하나라도 어긋나면 그 항목을 보고하고 다음 단계로 넘어가지 않습니다.

한계·위험(미리 적음): (가) SDK 의 `<mach/m68k/vm_param.h>`·`<m68k/mmu.h>`·`<m68k/reg.h>`·`<m68k/psl.h>` 가 어셈블리(`-DASSEMBLER`)에서 C 선언 때문에 어셈블 오류를 낼 수 있음(그러면 변형으로 우회하거나 해당 줄만 NeXTMach 머리로 두는 대안을 사용자에게 보고). (나) `reg.h` 를 더하면서 `pcb.h` 가 들이던 다른 이름이 빠져 객체가 달라질 수 있음(객체 동일성으로 판정). (다) 07 `trap.c` 와 `T_*` 가 중복 정의처럼 보이지만 서로 다른 번역 단위이고 값이 같음. (라) 이 후보는 07 에 올리지 않습니다.

### 753.1 §753 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 사실 1 에서 41 개 식별자가 모두 헤더 유래인 듯 적음(기능 매크로 34·구성 매크로 4·레이블 1·조건명 2 가 섞임; 본문 고침). (2) `VM_PROT_READ`·`VM_PROT_WRITE` 를 `vm_prot.h` 유래로 적고 `<mach/vm_prot.h>` 를 더한 변형 C10C 를 구제 대안으로 둠: 실제로는 C9 의 머리 블록(46–47 행)이 `1`·`2` 로 이미 정의하고, 스테이징 `vm_prot.h:78` 은 어셈블러로 흘러가는 C 선언을 무조건 내므로 C10C 는 부적합(본문 고치고 C10C 삭제). (3) 사실 3 의 "스테이징에 `trap.h` 없음"이 틀림: 진단용 `inc_locore_*/next/trap.h` 가 있고(그 파일은 진단 얹기이며 07 입력이 아님), `T_STRAY` 는 07 `trap.c` 에도 없음 → 7 개 일치·8 개는 바이트 일치로 고침. (4) "stab 은 파일 이름이 달라 제외"라고 적었으나 C9 객체는 `-g` 인데도 stab 이 0 개(python: 심볼 148 중 stab 0). (5) `-M` 의존 목록이 `-imacros src/generated/meta_features.h` 와 그 사슬(`cpus.h`·`gdb.h`·`cputypes.h`)을 보여 주지 않음. (6) 판정 (바)를 `git status` 만으로는 07 불변을 증명할 수 없음(07 에 이미 수정·미추적 파일이 있음).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `VM_PROT_*` 는 C9 머리 블록의 정의(1·2)이고 스테이징 `vm_prot.h:78` 이 `typedef int vm_prot_t;` 를 무조건 냄 | `grep -n "VM_PROT_READ\|VM_PROT_WRITE" locore_C9.s`: 46–47 행 `#define VM_PROT_READ 1`·`VM_PROT_WRITE 2`; `sed -n 76,82p` `vm_prot.h` | ✅ C10C 삭제 |
| `T_STRAY` 가 07 `trap.c` 에도 SDK 에도 없고 NeXTMach `trap.h:17` 에만 `0x00` | `grep -n T_STRAY trap.c`(출력 없음); `grep -rn define.T_STRAY 07_kernel 08_build/artifacts/m0p413`(없음); NeXTMach `next/trap.h:17` | ✅ |
| 원본 바이트: `0x4001f7e` `movel #12`·`0x4002158` `movel #8`·`0x4002014` `movel #1040`, `mmu_type` 표 | 앞서 §748·§751 의 python 바이트 출력과 같은 값 | ✅ |
| C9 객체: 심볼 148·stab 0·섹션 `__text`/`__data` 메타 | python: `symbols 148 stab 0`, `{'SECT': 102, 'UNDF': 46}`, 섹션 `('__text','__TEXT',0,2,1024)`·`('__data','__DATA',8052,1,0)` | ✅ |
| `-M` 출력(`_log/NN.out`)에 `cpus.h`·`gdb.h`·`meta_features.h` 가 없고 `-imacros` 입력은 별도 | python: `01.out` 의 헤더 목록에 세 파일 없음; run.cmd 2 행에 `-imacros src/generated/meta_features.h` | ✅ |
| 스테이징 헤더는 `-DASSEMBLER` 가 아니라 `__ASSEMBLER__` 가드를 쓰는 곳이 있고 `monitor.s` 의 S 변형이 `<m68k/spl.h>` 로 같은 바이트를 낸 선례 | 앞서 헤더 훑기(휴리스틱)와 §514 기록; 새 C10 결과는 실행에서 | ⚖️ 실행으로 확인 |
| 41·17·9·8 수치 | python(앞서) | ✅ (41 은 헤더 의존 전체가 아님) |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. 헤더 가드 해석은 읽은 코드 근거이고 실제 어셈블 결과를 판정으로 삼습니다.

### 753.2 §753 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. `cmp_obj.py` 는 심볼을 이름 사전으로 접지 않고 **목록 순서 그대로** 비교: 각 심볼의 원시 `n_type`·`n_sect`·`n_desc`·`n_value`·이름(문자열)·종류·외부 여부, 객체 머리(endian·cputype·cpusubtype·filetype·flags·명령 수), 각 섹션의 이름·세그먼트·주소·크기·정렬·flags·재배치 개수·바이트(재배치 필드를 가리지 않음)·재배치 표 전 필드(일반형과 scattered 형 모두, 순서·중복 보존)를 비교. stab 판정은 이름이 아니라 `n_type & N_STAB`; REF 의 stab 은 0 개이므로 후보에 stab 이 하나라도 있으면 종류·개수·문자열을 보고하고 실패로 침. 자기 비교 통과와 더불어 `cmp_obj` 자체의 검출력 시험(`selftest`): 비-stab 심볼의 `n_desc`·`n_type` 변경, 재배치 필드 변경, 섹션 정렬·flags 변경, 빈 섹션 추가, 심볼 중복, 재배치 순서 교환, 객체 머리 flags 변경 7 가지를 메모리 사본으로 만들어 모두 FAIL 임을 확인.
2. (가) 보강: 채택 후보의 컴파일 줄(`NN.err`)과 `-M` 줄의 종료 코드가 0 이고 모든 `.err` 파일 크기가 정확히 0 B(경고 포함)임을 python 으로 강제함.
3. (다) 보강: 의존 목록 경로가 금지 경로(`inc_locore_*`·NeXTMach 원문 `01_resources`·`i386`)에 없을 뿐 아니라, 목록의 각 헤더와 `-imacros src/generated/meta_features.h` 사슬(`cpus.h`·`gdb.h`·`cputypes.h` 등 `-M` 에 안 나오는 것도 `run.cmd` 의 `-imacros` 로 별도 추적)의 sha256 이 07 트리(`07_kernel/nextmach`·`07_kernel/include`·`07_kernel/generated` 등)·SDK(`08_build/artifacts/m0p413/sdk-m68k`)·기존 스테이징 기본 입력의 어느 파일과 같은지 python 으로 찾아 출처를 적고, 출처를 못 찾는 항목은 FAIL. `src/bsd/next/cpu.h` 는 `07_kernel/nextmach/next/cpu.h` 의 어셈블리 전용 사본이어야 함. 의존 목록은 활성 전처리 경로의 증거이며 비활성 조건부 포함의 증거가 아니라는 한계를 기록.
4. 음성 대조 N1–N3 는 **통과한 채택 후보에서** 각각 독립적으로 만듦(채택 후보가 C10B 이면 C10B 에서). N1 은 정상 어셈블 뒤 `cmp_obj.py`·`cmp_unit.py` 로 표 바이트 차이를 내야 하고, N2·N3 은 의도한 미정의 이름·재배치 변화 또는 해당 어셈블 오류(원인 줄을 기록)여야 하며 무관한 실행 실패는 음성 대조로 세지 않음.
5. (바)는 `07_kernel` 아래 추적·미추적 파일 경로 목록과 sha256 스냅샷(`scratch/p753/snap07.py`)을 실행 전후에 만들어 완전히 같음을 비교(scratch·`08_build` 제외).
6. 판정 (마) 는 위 본문의 "7 개는 07 `trap.c` 와 같고 8 개는 원본 바이트와 같음"으로, (나)의 채택 후보 이름은 고정하지 않고 REF 경로(`08_build/runs/m4p752-p1/stage/Q752__locore_C9.o`)와 sha256 을 기록.

### 753.3 결과: 07 스테이징 포함 꼴 후보 C10 — C9 와 같은 객체 (수락 아님; 07 변경 없음; 2026-11-06)

사용자 결정 D168(`02_plan/DECISIONS.md`; AskUserQuestion): 새 상수 4 개는 이름을 유지하고 "이 프로젝트의 이름(원본 소스 이름 아님), 값 근거는 원본 바이트"로 표시, NeXTMach 잔여 텍스트는 그대로 둠. 이 단계는 그 결정대로 C10 의 머리 블록 주석을 고쳤습니다(`R_A6`·`THREAD_TASK`·`TASK_U_ADDRESS`·`FSAVE_BIT`).

산출물(전부 scratch·산출물 폴더; 07 은 그대로): 생성기 `scratch/p753/gen_locore10.py`(§752 의 `gen_locore9.py` 를 실행한 뒤 `#import` 줄을 07 스테이징 꼴로 바꾸고 `T_*` 8 개를 머리 블록에 더하고 머리 주석을 07 용으로 바꿈; 후보 `scratch/p753/locore_{C10,C10B,N1,N2,N3}.s`), 객체 비교 `scratch/p753/cmp_obj.py`(selftest 포함), 의존 헤더 출처 `scratch/p753/deps_check.py`, 07 스냅샷 `scratch/p753/snap07.py`, 명세 `08_build/artifacts/m4p753/spec_c10.json`·`spec_n.json`(`inc` 빈 목록, 헤더는 스테이징 기본 입력으로만 풀림). 실행: `m4p753-p1`(C10·C10B; 종료 코드 4 개 0, 표준 오류 4 개 모두 0 B), `m4p753-p2`(음성 대조 N1–N3).

변경(주 후보 C10): `<sys/kern_return.h>` → `<mach/kern_return.h>`, `<next/cframe.h>` → `<m68k/cframe.h>`, `<next/vm_param.h>` → `<mach/m68k/vm_param.h>`, `<next/vmparam.h>` → `<m68k/vmparam.h>`, `<next/psl.h>` → `<m68k/psl.h>`, `<next/mmu.h>` → `<m68k/mmu.h>`, `<next/spl.h>` → `<m68k/spl.h>`, `<next/cpu.h>` 그대로(어셈블리 전용), 새로 `<m68k/reg.h>`, `<next/pcb.h>`·`<next/trap.h>` 삭제; `T_STRAY`·`T_BUSERR`·`T_ADDRERR`·`T_MMU_BUSERR`·`T_MMU_LIMIT`·`T_MMU_SUPER`·`T_MMU_WRITE`·`T_MMU_INVALID` 8 개를 머리 블록에 더함. C10B 는 `<mach/vm_param.h>` 변형.

사전 확인(§753.2): `cmp_obj.py --selftest`(REF = `Q752__locore_C9.o`, SHA-256 앞 16 자 `4d98fb13e4306625`): 비-stab 심볼 `n_desc`·`n_type` 변경, 재배치 필드 변경, 섹션 정렬·flags 변경, 빈 섹션 추가, 심볼 중복, 재배치 순서 교환, 객체 머리 flags 변경, 섹션 바이트(재배치 필드) 변경, stab 심볼 출현 11 가지 모두 DIFF(`SELFTEST ALL OK`). 실제 C9 객체는 `-g` 인데도 stab 0 개이고 심볼 148 개입니다.

판정(미리 정한 기준대로; python·도구 출력):
- (가) C10 어셈블 오류·경고 0: 컴파일 줄·`-M` 줄 종료 코드 4 개 모두 0, 모든 `.err` 0 B(C10·C10B 둘 다).
- (나) C10 과 C10B 모두 `cmp_obj.py` 로 C9 객체와 **완전히 같음**(`IDENTICAL`: 머리·섹션 메타·`__text` 8052 B·`__data` 464 B 바이트·재배치 표 189 + 80·심볼 148 개의 목록과 원시 필드·stab 0 대 0). 채택 후보는 주 후보 C10(포함 줄이 더 작음; C10B 와 객체 동일). C10 에서 `cmp_unit.py` U1–U7 `UNIT PASS`, `check_data2.py` `ALL PASS`.
- (다) 의존: C10 의 헤더 73 개(`-M` 목록 22 + `-imacros src/generated/meta_features.h` 사슬 51)가 모두 sha256 으로 07 트리(65)·SDK(8) 의 파일과 같고 출처 없음 0, 금지 경로(`inc_locore_*`·`01_resources`·i386) 0; `next/` 는 `src/bsd/next/cpu.h` 하나이며 `07_kernel/nextmach/next/cpu.h` 와 sha256 같음(`monitor.s` 선례). 한계: `-M` 은 활성 전처리 경로의 증거이며 비활성 조건부 포함이나 모든 매크로 정의의 증거는 아닙니다.
- (라) 음성 대조(채택 후보 C10 에서 독립 생성): N1(`T_MMU_LIMIT 0x405`) 정상 어셈블 뒤 `cmp_obj.py` DIFF 1(`__text` +7771)·`cmp_unit.py` U5 FAIL(`buserr` 의 `mmu_type` 표); N2(`<next/cpu.h>` 삭제) 어셈블 오류 8 줄(`Can't deal with expression "I_IPL3_BASE": defaulting to 0` … 종료 코드 1, 객체 없음); N3(`<m68k/mmu.h>` 삭제) 조용히 어셈블되지만 `cmp_obj.py` DIFF 8·`cmp_unit.py` U1·U3·U4·U5·U6 FAIL(`FC_SUPERI`·`FC_USERD`·`FC_USERI`·`SIZE_LONG`·`SIZE_WORD` 가 정의 없는 이름으로 샘).
- (마) `T_*` 8 개의 값이 원본 바이트와 같음: `mmu_type` 표(0x4002164) 6 개 `0x400 0x404 0x408 0 0x40c 0x410` = `T_MMU_BUSERR`·`LIMIT`·`SUPER`·`T_STRAY`·`WRITE`·`INVALID`, `movel #12`(0x4001f7e)·`movel #8`(0x4002158)·`movel #1040`(0x4002014); 그 중 7 개(`T_STRAY` 제외)는 07 `trap.c` 의 정의 값과 같고 `T_STRAY` 는 `trap.c` 에 없음.
- (바) 07 불변: 실행 전후 `07_kernel` 의 추적·미추적 파일 860 개의 경로·sha256 스냅샷이 완전히 같음(`snap07.py --compare` 종료 코드 0).

한계: (가) 이 확인은 07 스테이징의 헤더로 풀리는 `#import` 꼴이 진단 때와 같은 객체를 낸다는 것이며 수락이 아닙니다(M4 수락 절차·상태표·출처표는 §754). (나) 머리 블록의 `T_*`·가칭 상수 주석은 객체에 영향이 없습니다. (다) `T_STRAY` 의 값 근거는 NeXTMach `trap.h:17` 과 원본 표 항목입니다. (라) 07 에 쓰는 것은 다음 계획입니다.


## 754. M4-208 구현 계획 — 07 `src/machdep/m68k/locore.s`(단위 [0x4000310, 0x4002284) 8052 B + 자료 464 B, 행 m68k-001–006; 코딩 전, 2026-11-06)

고른 까닭: §752 에서 후보 C9 가 단위 전체 대조 U1–U7 을 통과했고(`__text` 8052 B·`__data` 464 B 가 원본과 같음, 정의 전역 64 + 자료 5 가 원본과 같은 오프셋), §753 에서 07 스테이징 헤더로 풀리는 `#import` 꼴 C10 이 C9 와 완전히 같은 객체(`Q753__locore_C10.o`, SHA-256 `4d98fb13…`)를 냈으며 사용자 결정 D167·D168 이 있습니다. 이 단계는 그 소스를 07 에 올리고 M4 수락 절차(HANDOFF §4 의 6·7 항)로 받아들입니다.

사실(python·읽은 파일):
1. `m4_m68k_probe.py compare`(읽기 전용; `08_build/artifacts/m4p753/spec_c10.json`·run `m4p753-p1`, 기록 `scratch/p753/probe_p1_record.json`)의 공식 판정이 C10 에 대해 `l1_verdict` **`OBJECT_MATCH`**(`l1_reasons` `[]`)·`full_span` 참·`text_size` 8052 = `expected_text_size`·`placed_text` 0x4000310·`missing_names`·`extra_names` 빈 목록·`undefined_not_in_original` `[]`·`judgement` `candidate` 입니다(C10B 와 `canon_equal`·`sig_equal` 참). 곧 `__data` 464 B(재배치 포함)도 L1 이 통과시킵니다.
2. 인벤토리 `06_reconstruction/m68k-m4-inventory.tsv` 에서 [0x4000310, 0x4002284) 와 겹치는 행은 정확히 여섯입니다: m68k-001(`x86-start`, 0x4000310–0x4000318, bytes_min 0), 002(`unassigned (run 1)`, 0x4000310–0x40013c4, 0), 003(`x86-intr`, 0x4000318–0x40013d6, 18), 004(`next/locore.s`, 0x40013d6–0x400221e, 3656 정확), 005(`fpsp/skeleton.sa`, 0x400221e–0x4002220, 2), 006(`unassigned (run 13)`, 0x4002220–0x4002284, 100). 모두 범위 안에 있고(`span()` 의 `rows` 조건), 함수표 경계: 범위의 lo=0x4000310 은 `_start` 항목 시작, hi=0x4002284 는 `_mon_exit` 항목 끝, 항목 사이 빈틈 없음. 자료 구간 [0x40ad964, 0x40adb34) 와 겹치는 인벤토리 행은 없음(python). 이미 받아들인 68 객체의 행·범위와 겹치지 않음(`m4_m68k_status.py` 의 "행 중복·범위 겹침 없음" 관문; 객체 `[0x4000310, …)` 와 겹치는 상태표 항목 0, python).
3. 등록 지점 4 곳(`stage_m68k.py`): docstring `--plan` 목록(9 행), `M4FILES[739]`(124 행)·`M4HEADERS[739]`(187 행)·`EXCEPTS[739]`(509 행). 07 `src/machdep/m68k/*.c|*.s` 는 `set().union(*M4FILES.values())`(627 행)에 하나라도 등록되어야 함(그래서 `locore.s` 를 `M4FILES[754]` 에 두면 앞 계획 재생성도 통과).
4. 새 스테이징 머리는 필요 없음: C10 의 포함 줄이 쓰는 `bsd/m68k/{cframe,vmparam,psl,mmu,reg,spl}.h`·`bsd/next/cpu.h`·`mach/m68k/vm_param.h`·`mach/kern_return.h`·`bsd/sys/{errno,reboot}.h`·생성 머리는 `m0p739-a1-stage` 에 이미 있음(§753 의 헤더 73 개 출처 검사: 07 65·SDK 8, 금지 경로 0).
5. 기대 상태(python; 상태 도구 출력으로 확인): 객체 68 → 69(`OBJECT_MATCH` 51 → 52), 덮은 행 93 → 99(여섯 행 모두 새로 덮임: 이미 덮인 행에 001–006 없음), 덮은 최소 바이트 135308 → 135308 + 3776(= 0 + 0 + 18 + 3656 + 2 + 100) = 139084, 객체 바이트 193004 → 193004 + 8052 = 201056.

방법(HANDOFF §4 6·7 항의 순서):
1. 소스: 생성기 `scratch/p754/gen_locore11.py`(§753 `gen_locore10.py` 를 실행한 뒤 머리 `#define` 블록(D167 의 assym 상수·`T_*`·`IMM0/IMM1`)을 `/* plan 754 (D167, D168, D024) BEGIN: assym constants … */ … /* plan 754 END */` 한 쌍으로 감쌈 → 표시 없는 바뀐 줄이 없게 함)로 F 를 만들고, F 에서 주석(`/* … */`·`//`, 문자열 밖)을 공백으로 비운 L 을 만듦. 07 파일 `07_kernel/src/machdep/m68k/locore.s` = F. 확인: (가) NeXTMach `next/locore.s` 와의 `difflib` 비교에서 바뀐 줄(추가·수정)이 모두 BEGIN/END 구역 안이거나 `plan 7NN`·`plan 7NN (…)` 표지가 든 줄이고 지운 줄은 표지 주석으로 적혔음(NeXTMach 머리 고지 `Copyright (c) 1987, 1988 NeXT, Inc.` 와 HISTORY 보존), (나) F = L 토큰(주석 제외), (다) F 의 주석을 뺀 토큰이 C10 의 주석을 뺀 토큰과 같음, (라) BEGIN/END 개수가 같음.
2. `stage_m68k.py`: `M4FILES[754] = list(M4FILES[739]) + ['locore.s']`, `M4HEADERS[754] = list(M4HEADERS[739])`, `EXCEPTS[754] = dict(EXCEPTS[739])`, docstring `--plan` 목록에 754(수정 전 사본 `08_build/artifacts/m4p754/stage_m68k.py.before754`). 회귀: `--plan 739 stage` 재생성이 보관 `m0p739-a1-stage.manifest.json` 과 같음; `--plan 754 stage m0p754-a1-stage` 와 739 매니페스트의 차이가 `src/machdep/m68k/locore.s` 한 파일(`m4_sources` 에 등록)뿐이고 그 SHA-256 이 07 파일과 같음.
3. x86 입력 불변: `L2_FORMS=06_reconstruction/l2_build_forms-s6p398.tsv L2_EXPECT=06_reconstruction/l2_expect-s6p398.json python3 10_tools/reconstruction/m4_x86_inputs.py s6ll OUT.json` 와 `stage_m68k.py --plan 754 x86gate DIR`(일곱 묶음 같음, v183 경로 0).
4. M5 205 줄 회귀(§739 와 같은 절차; `.s` 등록은 M5 줄 수를 늘리지 않음: `cmd` 는 고정된 기준 run 에서 `.c` 205 줄만 읽음, python): 순서 `--plan 739 cmd`·`--plan 754 cmd`(이전·새 명령 파일 `08_build/artifacts/m4p754/m5-739.cmd`·`m5-754.cmd`; 접두사 정규화 비교) → kr_run `prepare` → `launch` → `wait` → `collect`(`stage/` 를 `out/` 으로 옮기므로 `compare` 보다 먼저) → `stage_m68k.py --plan 754 compare m3p754-cc1 m0p754-a1-stage WORKDIR x86gate.json RECORD`(기록 `09_validation/reconstruction/m3-m68k-p754-compare-20261106.json`) `stage_m68k.py --plan 754 compare m3p754-cc1 m0p754-a1-stage WORKDIR x86gate.json RECORD` 의 `differ_unexpected`·`lost` 가 비어야 하고 객체 출력이 `m3p739-cc1` 의 것과 `run.json` 만 다르게 같아야 함.
5. 확인 run `m4p754-p1`(명세 `08_build/artifacts/m4p754/confirm/spec.json`: 변형 F(F 소스)·L(주석 비운 소스), `inc` 빈 목록, `defs` `-DASSEMBLER`, `x86_rel` `machdep/i386/start.s`, `m4_id` `{range: [0x4000310, 0x4002284], rows: [m68k-001 … m68k-006], basis}`)과 `-E` 토큰 run `m4p754-e1`(F 와 L 의 전처리 토큰이 같음). 관문: 컴파일·`-M` 종료 코드 0·표준 오류 0 B·i386 머리 0·정의 없는 이름이 원본에 있음, L1 `OBJECT_MATCH`·`full_span` 참·`candidate`, F 와 L 의 `canon`·`obj_sig` 같고 둘 다 §753 의 `Q753__locore_C10.o` 와 `cmp_obj.py` 로 완전히 같음(주석은 객체에 영향 없음). REF = L 객체.
6. 최종 run `m4p754-a1`(명세 `08_build/artifacts/m4p754/spec.json`: 변형 `F` = `{"src": "@machdep/m68k/locore.s", "inc": [], "defs": ["-DASSEMBLER"]}`, `refs` = L 객체와 SHA-256, `known_warnings` 없음, `bss_inferred` 없음). 관문: `gate.ok`(경고 0·i386 머리 0·`candidate`·REF 같음). python 확인 기록 `09_validation/reconstruction/m4-m68k-p754-checks-20261106.json`: 최종 객체 SHA-256 = REF, `cmp_unit.py` U1–U7, `cmp_obj.py` 로 C9 객체와 같음, 입력 사슬(소스 하나·머리), 의존 목록 출처(§753 `deps_check.py`), 옵션 = M5 줄 + `-DASSEMBLER`, 항목별 비교 `cmp10.py`(`ALLOWED_EXTRA` 빈 값; 58 항목 PASS)와 단위 대조 `cmp_unit.py`(실제 최종 객체 경로를 주어 U7 포함 U1–U7 전부 존재·참)를 수락 근거로 쓰고, `m68k_funcbytes.py` 는 제한을 적은 보조 기록으로만 남김(C10 객체에 돌린 결과 29/58 SAME·`bytes 0` 15·`len/absent` 14: 이 도구는 객체의 모든 텍스트 심볼을 경계로 삼고 별칭 첫 이름만 골라 `_start`(원본 8 B 대 객체 6 B)·`_intstacks`(4268 B 대 4096 B)·`buserr`(648 B 대 70 B) 같은 별칭·내부 레이블 항목을 쪼개므로 수락 조건이 아님).
7. 기록(근거 문서 먼저): `06_reconstruction/evidence/m68k-locore.md`(원본 사실·방법·결과·가칭 이름 표시·M7 의무)와 `m68k-locore.diff`(NeXTMach 대비) → 상태 도구 `ACCEPTED` 튜플(기록 경로·SHA-256; `OBJECT_MATCH` 이므로 zerofill 없음; 두 번 돌려 같고 앞 행 그대로, 상태표 행 수 확인) → PROVENANCE 한 행(일곱 칸, 중복 0) → MODIFICATIONS → DECISIONS(D167·D168 은 이미 있고 새 결정이 없으면 추가하지 않음; 수락 사실은 계획 결과 절에) → 계획 결과 절·HANDOFF·기억.

판정 기준(미리 정함; 낮추지 않음): (가) 07 파일 = F, 소스 검사 (가)–(라) 전부 통과. (나) 스테이징 회귀: 739 재생성 = 보관본, 754 − 739 = `locore.s` 하나. (다) x86 입력 불변·x86 gate 일곱 묶음 같음(`plan`·`tool_sha256` 외 차이 없음). (라) M5 205 회귀: `differ_unexpected`·`lost` 빈 목록이고, 직전 `m3p739-cc1` 의 출력·표준 오류와 객체 접두사를 정규화해 비교하면 617 개가 `run.json` 만 다름(`stage_m68k compare` 의 예외·오래된 기준 run 비교와 별도). (마) 확인 run·`-E` run 관문 전부 통과. (바) 최종 run `gate.ok`, 객체 = REF, L1 `OBJECT_MATCH`, python 확인 기록 `ok`(확인·`-E`·최종 run 의 모든 표준 오류 0 B, `cmp10.py` 58 항목 PASS, `cmp_unit.py` U1–U7 전부 존재·참, F·L·최종 객체가 §753 의 `Q753__locore_C10.o` 와 `cmp_obj.py` 로 완전히 같음, 07 파일의 NeXTMach 고지 보존이 `ok` 에 연결됨). (사) 상태 도구: 객체 69·`OBJECT_MATCH` 52·덮은 행 99·덮은 최소 바이트 139084·객체 바이트 201056 가 위 기대(python 계산)와 같고 앞 행이 그대로이며 두 번 돌린 출력이 같음. (아) PROVENANCE 행 수 1238 → 1239(경로 중복 0)·MODIFICATIONS 765 → 766. 하나라도 어긋나면 그 항목을 보고하고 기준을 낮추지 않고 멈춥니다.

위험(미리 적음): (가) 07 `locore.s` 가 NeXTMach 파일을 많이 바꾼 것이므로 PROVENANCE `changes` 칸과 MODIFICATIONS 가 길어집니다(요약만 쓰고 자세한 것은 증거 문서와 diff). (나) 주석을 비운 L 이 객체를 바꾸면(`//` 주석이 매크로 본문에 섞인 경우 등) 주석 영향 가능성을 보고하고 F 쪽 형태를 고쳐야 함. (다) M5 205 회귀는 실기 컴파일 205 개라 시간이 걸림(스테이징에 `.s` 한 개 추가는 `.c` 컴파일에 영향이 없다고 예상하지만 회귀로 확인). (라) 인벤토리 행 001·002 는 8 B, 002·003 은 4268 B 겹치고 001·003 은 경계에서 만나기만 함(반열림 구간, python). 상태 도구의 "행이 두 번 덮임" 관문은 행 ID 재사용을, 주소 겹침 관문은 객체 범위 사이를 보므로 한 객체 안 행끼리의 겹침은 거부하지 않음(코드 읽음; 수락 전 도구 출력으로 확인). (마) M7 의무: 이 객체가 정의하는 전역 심볼(`_start`·`_intstacks`·`_cache`·`_scb` 등 64 + 5)이 링크에서 다른 객체의 정의와 겹치지 않아야 하고 정의 없는 이름 46 개가 모두 해소되어야 함(링크 단계에서 확인).

### 754.1 §754 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 방법 6 과 판정 (바)에 `m68k_funcbytes.py` "58 항목 SAME"을 수락 근거로 적음: 이 도구는 객체의 모든 텍스트 심볼을 경계로 삼고 별칭 첫 이름만 골라 별칭·내부 레이블 항목을 쪼개므로 C10 객체에서 29/58 SAME(§740 에서 이미 알았던 한계를 다시 적음; 본문을 §752 의 `cmp10.py` 항목별 PASS 58 + `cmp_unit.py` U1–U7 로 고침). (2) 상태 도구의 "행이 두 번 덮임"과 주소 겹침 관문이 무엇을 보는지 읽지 않고 위험으로 적음(행 ID 재사용·객체 범위 사이만 봄). (3) 인벤토리 행의 겹침을 "001·002·003 이 서로 겹침"이라 적음: 반열림으로 001·002 8 B, 002·003 4268 B 겹치고 001·003 은 경계에서 만남(본문 고침). (4) 최종·확인·`-E` run 의 표준 오류 0 B 를 `gate.ok` 가 보장하지 않는다는 점을 판정에 넣지 않음. (5) F·L 동일성에 §739 의 C 토큰 검사기를 그대로 쓸 수 있는 듯 적음(어셈블리의 `@`·`$`·줄 경계·`\` 연속행에 맞지 않음; 어셈블리용으로 새로 씀).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| C10 객체에 `m68k_funcbytes.py` 를 돌리면 29/58 SAME(`_start` 8 B 대 6 B, `_intstacks` 4268 B 대 4096 B, `buserr` 648 B 대 70 B 등) | 이번 세션에 직접 실행: `python3 m68k_funcbytes.py 0x4000310 0x4002284 …/Q753__locore_C10.o`, `same 29`·`total 58`, 결과 분포 `SAME 29`·`len/absent 14`·`bytes 0 refs n` 15, `trap3 orig 170 obj 76`·`buserr orig 648 obj 70`·`_cache_push orig 42 obj 34` | ✅ 본문 고침 |
| 겹침 행: 001·002 8 B, 002·003 4268 B, 001·003 은 경계에서 만남 | python 반열림 계산(이번 세션) | ✅ |
| M5 `cmd` 는 `M4FILES` 를 순회하지 않고 205 줄 모두 `.c`; 순서에서 `collect` 가 `compare` 앞 | `m5-739.cmd` 열음: RUN 205 줄·`.c` 205(python); 도구 문서(`stage_m68k.py` docstring)와 HANDOFF §4-7 읽음 | ✅ |
| `bytes` 열은 텍스트 범위 길이라 자료 464 B 는 객체 바이트에 안 더함; 최소 바이트는 덮은 행 `bytes_min` 합 | 앞서 python(상태표 `bytes` 합 193004 + 8052 = 201056; 행 `bytes_min` 합 3776) | ✅ |
| 상태 도구의 겹침 관문은 행 ID 재사용·객체 범위 사이만 보고 자료 배치는 보지 않음; 자료는 L1 이 검증 | `m4_m68k_status.py` docstring(12–33 행)을 읽음; 공식 probe 기록에서 `l1_verdict OBJECT_MATCH` | ✅ (수락 전 도구 출력으로 확인) |
| `gate.ok` 가 stderr 0 B 를 보장하지 않음 | `m4_m68k_probe.py` 의 gate 가 `warning` 개수를 셈(읽음) | ✅ 판정에 명시 |
| PROVENANCE 일곱 칸·MODIFICATIONS 형식·행 수는 물리적 줄 수(1238→1239, 765→766); 기존 `locore.s` 행은 i386 경로뿐 | 앞서 `wc -l` 1238·765; PROVENANCE 머리(7 칸); `grep` 한 monitor.s·nextdbgasm.s 행 | ✅ |
| 등록 지점 4 곳·`known` 규칙(전 계획 합집합), `x86_rel`/`@…` 형식 | 앞서 grep(9·124·187·509·627 행) | ✅ |
| 확인되지 않은 것: F·L 동일성, 754 최종 객체의 U1–U7, M5 새 회귀, 링크 단계의 이름 해소 | — | ⏭️ 실행 단계에서 확인(미확인으로 둠) |

2 차 자기검사: ✅ 행은 이번 세션에 돌린 python·연 파일입니다. 확인하지 않은 것은 위 ⏭️ 행에 적었습니다.

### 754.2 §754 보강(codex 검토 반영; 기준은 낮추지 않고 더함)

1. 어셈블리용 검사기 `scratch/p754/asm_tokens.py`: 주석(`/* … */`·`//`, 문자열 밖)을 공백으로 비우되 줄바꿈·`\` 연속행·문자열·`@`·`$`·`#`·`{}`·`;`·`:` 를 보존하는 토큰화(줄 경계도 토큰). F = L(주석 제외), F 의 주석 제외 토큰 = C10 의 주석 제외 토큰, BEGIN/END 의 개수·순서·짝(중첩 없음, 미종결 없음). `-E` run 은 line marker 만 지우고 줄 경계·`#`·문자열을 보존해 F = L 비교.
2. 통합 확인 기록 `m4-m68k-p754-checks-20261106.json` 의 `ok` 에 연결: 07 파일의 NeXTMach 고지(`Copyright (c) 1987, 1988 NeXT, Inc.` 와 HISTORY 블록이 원문 바이트 그대로)·표시 없는 바뀐 줄 0·`cmp10.py`·`cmp_unit.py`(최종 객체 경로를 주어 U7 포함 U1–U7 전부 존재·참; 비교기·하위 검사기·원본 입력 해시, 명령·종료 코드·stdout·stderr 기록)·`cmp_obj.py`(C9·C10 객체와 완전히 같음)·표준 오류 크기(확인·`-E`·최종 run 모두 0 B)·`deps_check.py`(헤더 출처). 함수별 비교 `m68k_funcbytes.py` 는 보조 기록(수락 조건 아님).
3. 판정 (사) 의 상태 도구 확인에서 `partial_rows`·`tiled_rows` 처리를 읽은 대로 계산하고 출력과 같은지 봄.

### 754.3 결과: m68k `locore.s` 수락 (OBJECT_MATCH, 58 항목·8052 B + 자료 464 B; D167·D168; 2026-11-06)

먼저 제 잘못: (1) 새 어셈블리용 소스 검사(`chk_src.py`)가 §744 의 `trap6` 변경 한 줄(`movl d0,a0@(THREAD_USER_REG)`; NeXTMach 는 `d1`)이 표시 구간 밖에 있는 것을 잡았습니다(표시 없는 바뀐 줄 1). 생성기 `gen_locore11.py` 에서 그 줄과 이웃 두 줄을 `plan 754` 구간 하나로 묶어 07 에 올리기 전에 고쳤습니다. (2) 통합 확인 `checks.py` 첫 판에 항상 참이 되는 `… or True` 가 든 `07_file_equals_F` 와 항상 참인 옵션 항목이 있었고, 둘 다 고쳐(07 파일 SHA = F = 기록의 `source_sha256`; 옵션은 컴파일 줄에서 직접 계산) 다시 돌렸습니다. (3) x86 입력 확인을 처음 `s6ll` 접두사로 돌렸으나 §739 기록은 `s6ln` 이므로 같은 접두사·같은 `forms`·`expect` 로 다시 돌려 §739 기록과 모든 칸이 같음을 확인했습니다. (4) 상태 도구 확인에서 반열림 구간으로 행 겹침을 다시 계산해 계획의 "001·002·003 이 서로 겹침"을 고쳤습니다(§754.1).

결과(미리 정한 기준 (가)–(아) 대로, python·도구 출력):
- (가) 07 `src/machdep/m68k/locore.s`(1957 행, SHA-256 `5c27222a…`) = 생성기 F. 소스 검사 `chk_src.py` `ok`: F = L 토큰(8667 개; 주석 제외·줄 경계 보존), F = C10 토큰(빈 줄 제외), BEGIN/END 51 쌍·미종결 0, 표시 없는 비공백 줄 914 개 모두 NeXTMach 줄의 부분수열, 삭제·교체 hunk 에 표지 없는 것 0, NeXTMach 머리 고지·HISTORY 바이트 보존.
- (나) 스테이징: `--plan 739` 재생성(1024 파일)이 보관 `m0p739-a1-stage.manifest.json` 과 같고, 새 `m0p754-a1-stage`(1025)는 `src/machdep/m68k/locore.s` 한 파일만 늘며(SHA-256 이 07 파일과 같음, `m4_sources` 67 → 68) `plan` 외 칸 같음. `stage_m68k.py` 801 → 804 행(python: 이번 세션 수정 전 801 행, 수정 뒤 804 행)(수정 전 사본 `08_build/artifacts/m4p754/stage_m68k.py.before754`; 등록 4 곳).
- (다) x86 입력 `m4-x86-inputs-p754-20261106.json` `ok`·§739 기록과 모든 칸 같음; x86 gate 일곱 묶음 같음·v183 경로 0(`plan`·`tool_sha256` 만 §739 와 다름).
- (라) M5 205 줄 회귀 `m3p754-cc1`(`stage_m68k.py --plan 754 cmd` 의 새 명령 파일이 §739 것과 정규화 후 같음·`.c` 205 줄): 출력 617 개가 `m3p739-cc1` 과 `run.json` 만 다르고(표준 오류 411 개 모두 같음), `compare` 의 `differ_unexpected`·`lost` 빈 목록, 요약이 §739 와 같고 `stage_vs_test_stage` 에 `src/machdep/m68k/locore.s` 한 줄만 더해짐(`09_validation/reconstruction/m3-m68k-p754-compare-20261106.json`).
- (마) 확인 run `m4p754-p1`(F, L; 컴파일·`-M` 종료 코드 4 개 0, 표준 오류 4 개 0 B): 둘 다 `OBJECT_MATCH`·`full_span` 참·`candidate`, 객체 SHA-256 `4d98fb13…` 로 같고 §753 의 C10 객체와 `cmp_obj.py` 로 완전히 같음, F 의 `cmp_unit.py` `UNIT PASS`. `-E` run `m4p754-e1`(종료 코드 0·표준 오류 0 B): F·L 전처리 토큰 9490 개 같음(줄 경계 보존, line marker 72 개 제거). REF = L 객체.
- (바) 최종 run `m4p754-a1`(`gate`: `commands_ok`·`no_i386_headers`·`all_candidates`·`refs_equal`·`ok` 모두 참; 기록 `09_validation/reconstruction/m4-m68k-p754-final-20261106.json` SHA-256 `306f233f…`; L1 `OBJECT_MATCH`, `placed_text` 0x4000310; 표준 오류 0 B). 통합 확인 `m4-m68k-p754-checks-20261106.json` `ok`(13 항목 모두 참): 최종 객체 = REF = C10 = C9(`cmp_obj.py`), `cmp_unit.py` U1–U7 전부 존재·참(실제 객체 경로로 U7 포함), `cmp10.py` 58 항목 PASS, `check_data2.py` `ALL PASS`, `cmp_strict2.py` EQUAL 58·8052 B, 표준 오류 0 B, 소스 검사, 07 파일 SHA = F = 기록, `-E` 토큰, 의존 헤더 출처(07·SDK), 옵션 = M5 줄 + `-DASSEMBLER`(추가 하나뿐, 빠진 것 0). 보조 기록 `m4-m68k-funcbytes-p754-locore-a1-20261106.json` 은 29/58 SAME(별칭·내부 레이블 분할 한계; 수락 근거 아님).
- (사) 상태 도구(두 번 돌린 TSV 같음; JSON 은 `output` 칸만 다름): 객체 68 → 69, `OBJECT_MATCH` 51 → 52, 덮은 행 93 → 99, 덮은 최소 바이트 135308 → 139084(64.43%), 객체 바이트 193004 → 201056 — 미리 python 으로 계산한 기대와 같음; 기존 68 행은 그대로이고 새 행 `locore`(행 m68k-001…006, 0x4000310–0x4002284, 8052 B, `OBJECT_MATCH`/`OBJECT_MATCH`)만 더해짐(`09_validation/reconstruction/m4-m68k-status-p754-20261106.json`).
- (아) PROVENANCE 1238 → 1239 행(일곱 칸·경로 중복 0), MODIFICATIONS 765 → 766, 근거 문서 `06_reconstruction/evidence/m68k-locore.md`·`m68k-locore.diff`(1844 행). 새 커밋 대상 파일에 IP·계정·사이트 경로 0(python 정규식). `07_kernel` 스냅샷: 추가 `locore.s` 한 개, 변경 `PROVENANCE.tsv`·`MODIFICATIONS.md` 뿐.

판정: 관문을 모두 통과해 받아들였습니다. 결정은 D167·D168 이 이미 있어 새 결정을 더하지 않았습니다. 남은 것: M7 의무(64 + 5 전역 심볼이 다른 객체와 겹치지 않음·정의 없는 이름 46 개가 링크에서 해소됨·`next/cpu.h` 는 어셈블리 전용), 이름 없는 지역 레이블은 위치만 일치, 다른 후보(`zs.c`, ADB 구역(행 209, 소스 없음), FPSP, `snd_link`, `tty_pty` 꼬리). 커밋은 하지 않았습니다.
