# 커널 소스 복원 작업계획 — 보관 §580–600

`02_plan/RECONSTRUCTION_PLAN.md` 의 §580–600(m68k M4 `next/machdep.c`: 전체 `mon/global.h`(D132·D133), `clock` 재수락, 진단 A1–B13, 07 `machdep.c`·`nextmach/next/scb.h`(D134))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-30, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 580. M4-86 세부 계획 — m68k `next/machdep.c`(행 294–299, 명시 구간) 첫 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): floppy 묶음이 끝났고, 남은 행 가운데 이어진 정확·준정확 행 294–299 가 한 객체로 보임. 원본 [0x40936a4, 0x4094a7c) 5080 B 의 23 항목(이름 있는 22)이 NeXTMach mk-108.1 `next/machdep.c`(1570 행)의 정의 차례 — `mon_boot`, `mon_call`, `halt_thread`, `reboot_mach`, `nmi`, `mini_mon`, `nmi_prf`, `softint_sched`, `softint_th`, `softint_run`, `startup_early`, `startup`, `as_tune`, `sendsig`, `sigreturn`, `halt_cpu`, `light_on`, `light_off`, `addupc` — 를 따르고, 1997 에 더해진 것은 `kernel_thread_noblock`(NeXTMach 은 `kern/thread.c:2027`)·`callout_dispatch`·`callout_remove`·이름 없는 0x4093792(26 B)뿐. 행 298(`x86-unix_startup`, `startup_early`·`startup`)도 이 차례 안에 있음. 다른 후보(`ev*`·`km`·`pcb`·`pmap`)는 1997 판이 NeXTMach 과 이름이 많이 다름(인벤토리 coverage, 이번 세션 목록).

확인한 사실(이번 세션; 원본 목록, 함수 표, 기호표, `macho.json`, python):
- 구간 [0x40936a4, 0x4094a7c) 5080 B(23 항목 합과 같음): `mon_boot` 190, `mon_call` 48, 0x4093792 26, `kernel_thread_noblock` 28, `halt_thread` 30, `reboot_mach` 70, `nmi` 330, `mini_mon` 1236, `nmi_prf` 28, `softint_sched` 26, `callout_dispatch` 312, `callout_remove` 134, `softint_th` 66, `softint_run` 386, `startup_early` 304, `startup` 1062, `as_tune` 102, `sendsig` 288, `sigreturn` 160, `halt_cpu` 18, `light_on` 40, `light_off` 40, `addupc` 156. 앞은 `machargs`(§517, 0x40936a4 에서 끝), 뒤 0x4094a7c 는 `_miniMonReboot`(행 300).
- 행: 294(시작 0x40936a4, 끝 0x4093762–0x40937ac)·295(0x4093762–0x40937ac 에서 0x40937c8)·296·297·298·299 가 모두 구간 안, 293·300 은 겹치지 않음 — 명시 구간 `{"range": ["0x40936a4", "0x4094a7c"], "rows": [294…299], "basis": …}` 를 `span()` 이 받아들임(python, `m4_m68k_probe.span`).
- `__data`: [0x40b2b82, 0x40b2b92) 16 B = `_nbuf` 0, `_nmfsbuf` 0, `_bufpages` 0, `_nsoftint` 50(python 큰 끝 정수) — NeXTMach 은 `nbuf`·`bufpages`(`NBUF`·`BUFPAGES` 없으면 0)·`nrnode` 0·`nsoftint = 100`(531 행); `nmfsbuf` 는 NeXTMach 에 없음(07 `kern/mfs_prim.c:834` 가 extern 으로 씀); `_nrnode` 는 이 묶음에 없고 원본의 다른 자리 0x40aedd8(값 0)에 있음(§580.1). 앞 기호는 0x40b28ee `_kernargs`(machargs), 뒤 0x40b2b92 `_miniMonMDCommands`.
- 원본이 가리키는 `__text` 주소 42 개(`_zsopen` 은 비교만, 0x40939e8; `printf`·`panic`·`kmpopup`·`kernel_thread`·`kmem_suballoc`·`vm_map_*`·`configure`·`ns_callout_init`·`adb_*`·`vid*`·`zsopen`·`zstrygetc`·`kmtrygetc`·`rtc_intr`·`resynctime`·`kdbg_connect`·`gets`·`getargs` 등), `__data` 15 기호(`_nbuf` 10 곳, `_bufpages` 7, `_nsoftint` 3, `_nmfsbuf` 2, `_hz`, `_page_size`, `_ncallout`, `_nclist`, `_nmbclusters`, `_ncsize`, `_kernel_task`, `_cdevsw`, `_pmsgbuf`, `_fpu_version`, `_version`), COMMON 56 자리(`_softint*`, `_nmi_*`, `_astune_*`, `_boot_*`, `_buffer_map`, `_reboot_how`, `_scr2` 등), 문자열 29 곳(대부분 [0x40ac3dc, 0x40ac790] 묶음, 몇은 공유).

방법(진단; 명세 `08_build/artifacts/m4p580/spec.json`, run `m4p580-p1`, 바탕 `m0p579-a1-stage`, 컴파일 줄 틀 `machdep/i386/dkbad.c`; scratchpad `gen_p580.py`):
- 변형 A1(`machdep_A1.c`): NeXTMach 글에서 include 줄만 — `<vm/vm_param.h>` → `<mach/vm_param.h>`, `<next/vmparam.h>` → `<m68k/vmparam.h>`, `<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<next/reg.h>` → `<m68k/reg.h>`, `<next/psl.h>` → `<m68k/psl.h>`, `<next/cons.h>` → `<m68k/cons.h>`, `<next/us_timer.h>` → `<kernserv/m68k/us_timer.h>`, `<next/bmap.h>` → `<m68k/bmap.h>`(§506 07), `<nextdev/monreg.h>` → `<dev/m68k/monreg.h>`(§556 과 같음), `<nextdev/video.h>` → `<dev/m68k/video.h>`(D116), `<nextdev/snd_dspreg.h>` → `<dev/m68k/snd_dspreg.h>`(D107), 1200 행 `<sys/machine.h>` → `<mach/machine.h>`. 나머지 머리는 스테이지에 있음(python 대조).
- `<next/pcb.h>` 는 들이지 않음(진단 표시): 스테이지의 `mach/mach_types.h` → … → 07 `machdep/m68k/thread.h:42` 가 이미 `struct pcb` 를 정의함(§580.1). A1 SHA-256 `329e5480…`.
- 진단 머리(`inc`, NeXTMach 사본; 1997 스테이지에 없음): `next/scb.h`·`next/scr.h`(그대로; `scr.h` 는 원본에 없는 COMMON 을 낼 수 있음 — §505·§507, 진단에서는 기록만), `nextdev/kmreg.h`(따옴표 include 넷을 `<…>` 로).
- 측정: `m4_m68k_probe.py compare`(각 명령 종료 코드·경고 줄을 따로 봄), 컴파일되면 `m68k_funcbytes.py 40936a4 4094a7c OBJECT.o RECORD.json 4093792=<진단 이름>`(이름 없는 하나는 몸을 읽고 정함), 섹션·`__data` 16 B·문자열·외부 함수·COMMON·원본에 없는 미정의; 실기 `otool -tv` 로 다른 함수 비교.
판정(미리 정함; 07 은 바꾸지 않음): 컴파일이 안 되면 첫 오류의 원인을 적고 최소로 고친 꼴(A2…)로 다시 돌림(고친 것은 모두 진단 표시). 컴파일되면 함수별 같음/다름과 1997 꼴을 적고 다음 진단을 계획함. 큰 객체이므로 여러 계획에 걸침.
관문: 명령 종료 0(진단 고침 뒤), i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 580.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 구간 함수는 NeXTMach 차례를 따르나, NeXTMach 의 `setregs`·`boot`·`unmount_all`·`kill_tasks`·`physstrat`(조건 없음)와 `vmtime`(`PGINPROF`)·`cpu_number`(MP)·`dumpsys`(`#if 0`)는 구간에 없음 — A1 은 그 글을 그대로 가짐 | 원본 구간 23 항목 목록(이번 세션)에 그 이름 없음, NeXTMach 정의 줄(이번 세션 grep: 1033·1045·1210·1333·1367·1421·1477·1498) | ✅ 진단 결과에서 객체에만 있는 함수로 기록 |
| 경계·크기 맞음; 앞은 `_machparam`, 뒤는 `_miniMonReboot`; `span()` 은 경계만 검사함 | python(이번 세션), 함수 표 | ✅ |
| 0x4093792 는 `kernel_thread(kernel_task, arg, 0)` 를 부르는 도움 함수, `kernel_thread_noblock` 은 `callout_dispatch(4, 0x4093792, start)` 로 그것을 부름(task 인자는 쓰지 않음) | 원본 0x4093792–0x40937c6 읽음 | ✅ NeXTMach `kern/thread.c` 와 다른 1997 꼴 — 진단에서 이름을 정함 |
| `_nrnode` 는 1997 에도 있음(0x40aedd8, 0) — "1997 에 없음" 은 틀림; `waittime` 은 0x40ae23a | 기호표 grep(1950·3483 행) | ✅ 제 오류. 사실 줄 고침 |
| 정적 `softint_th_lock` 은 이 스테이지에서 저장소가 없음(원본 0x4094066 이 NULL 자물쇠를 넘김), `mini_mon` 의 `xpr_hdr` 는 `XPR_DEBUG` 안 | — | ⏭️ 진단 객체의 기호로 확인 |
| 직접 import 는 모두 풀림, `<kernserv/m68k/us_timer.h>` 는 맞는 SDK 경로 | §580 의 python 대조(이번 세션) | ✅ |
| `next/pcb.h` 사본은 `struct pcb` 를 두 번 정의하게 함(07 `machdep/m68k/thread.h:42`) | 스테이지 `machdep/m68k/thread.h:40–44` 와 사본 `pcb.h:20–23` 을 엶 | ✅ A1 에서 `next/pcb.h` 를 빼고(진단 표시) `fpc.h` 사본도 뺌; A1 SHA `329e5480…` |
| `P_MON`·`P_DSP`·`I_BIT`·`I_POWER`, `us_callout`/`us_callfree` 선언, `MG`·`mg_as_tune` 등이 1997 머리에 없음 | — | ⏭️ 컴파일 오류로 확인(계획대로 최소 고침) |
| `scr.h`·`kmreg.h` 사본이 `scr1`·`scr2`·`brightness`·`km`·`alert_key`·`km_coni` COMMON 을 낼 수 있음 | — | ⏭️ 진단 객체 기호로 기록 |
| 주소 42 개 가운데 `_zsopen` 은 비교만(0x40939e8), `_nmfsbuf` 가 자료 목록에서 빠짐(0x40942fe) | 원본 0x40939e8 `cmpl #0x408b300`, 0x40942fe `tstl 0x40b2b86` | ✅ 문구 고침 |

### 580.2 결과(run `m4p580-p1`, 2026-10-30)

- A1(`329e5480…`): 컴파일 종료 1(기록 `09_validation/reconstruction/m4-m68k-probe-p580-20261030.json`, 의존 명령은 종료 0). 오류(`_log/00.err`, 23 행): `P_MON`(237 행 `nmi`), `I_POWER`(290 행 `mini_mon`), `P_DSP`(593 행 `softint_sched`), `us_callout`·`us_callfree`(757·961 행 `startup_early`·`startup`), `CONS_O_BITMAP` 와 983 행의 문법 오류(`MG(short*, MG_seq)` — `MG` 매크로 없음), `mg_as_tune`(1017–1018 행 `as_tune`), `TRACE_AST`(1140 행 `sendsig`); 경고 둘(600·619 행, `thread_wakeup_prim`·`thread_sleep` 첫 인자).
- 원인(이번 세션에 NeXTMach 와 스테이지를 엶): `P_MON`·`P_DSP`·`I`·`I_BIT`·`I_POWER` 는 NeXTMach `next/cpu.h:152·153·213·216·262`(1997 C 머리에 없음, D109·D113·D121 꼴로 파일 안에 둘 이름); `us_callout`·`us_callfree` 는 NeXTMach `next/us_timer.h:18`; `CONS_O_BITMAP`·`MG`·`MG_seq`·`MG_anim_run`·`mg_as_tune` 은 NeXTMach `mon/global.h:109·118` 등 — 스테이지의 `mon/global.h` 는 07 부분 머리(`07_kernel/v183.34/m68k/src/mon/global.h`, plan 437, D068: M5 `subr_prf.c` 의 `panic` 이 쓰는 세 칸만, "M4 가 전체 머리를 들일 때 바꿀 후보"라고 적힘)이고 07 `clock.c`(§535)도 그것을 들임; `TRACE_AST` 는 NeXTMach `next/pcb.h:51`(1997 스테이지의 `struct pcb` 는 07 `machdep/m68k/thread.h` 의 부분 배치).
- 판단: `machdep` 는 머리 공급(전체 `mon/global.h`, `struct pcb`·`pcb_flags`, `us_timer` 이름, `kmreg.h`·`scr.h`)을 정해야 하는 큰 객체라 사용자 결정이 필요함(아래 결정 뒤 §581 을 씀).

- 사용자 결정(2026-10-30, AskUserQuestion): `machdep` 진행 방법은 "전체 mon/global.h 로 바로 교체" — 07 부분 `mon/global.h` 를 NeXTMach 전체 머리로 바꾸고 M5 회귀·`clock` 재수락을 먼저 함.

## 581. M4-87 세부 계획 — 전체 `mon/global.h` 공급 진단(07 변경 없음; 코딩 전, 2026-10-30)

목적: §580.2 결정을 안전하게 하기 위해, 07 머리를 바꾸기 전에 NeXTMach 전체 `mon/global.h` 와 그 닫힘(closure)이 1997 머리에서 컴파일되는지, `struct mon_global` 배치가 원본과 맞는지, 그 머리를 쓰는 받아들인 객체(M5 `subr_prf`, M4 `clock`)가 바뀌는지를 봅니다.

확인한 사실(이번 세션):
- 지금 머리: 07 `07_kernel/v183.34/m68k/src/mon/global.h`(plan 437, D068·D024; 부분 머리 — `mg_pad0[0x30a]` 다음 `mg_minor`·`mg_seq` +0x30a·+0x30c, `mg_major` +0x312 는 원본 `_panic` 이 읽는 오프셋(0x400bcb8·0x400bcbe·0x400bcc4); `mg_anim_run` +0x30e 는 NeXTMach 차례에서 미룬 자리로 바이트 근거가 아님). 이것을 들이는 07 파일은 `v183.34/m68k/src/bsd/kern/subr_prf.c:114`(M5, `panic` 이 세 칸을 씀)와 `src/machdep/m68k/clock.c:58`(§535, 이 머리의 이름을 쓰지 않음; grep).
- NeXTMach `mon/global.h`(128 행): `struct mon_global`(51–121 행)과 `MG` 매크로(34–35 행, `<mon/assym.h>`), `CONS_*`, `MGF_*`; 들이는 머리: `mon/assym.h`·`nvram.h`(07 `nextmach/mon/nvram.h` 가 스테이지에 있음)·`region.h`·`tftp.h`(망 머리 열하나·`sys/errno.h`·`sys/time.h`·`rpc/types.h`·`nfs/nfs.h` 는 스테이지에 있음, `mon/bootp.h` 는 없어 진단 사본으로 둠)·`sio.h`(`<nextdev/disk.h>`)·`animate.h`·`mon/kmreg.h`(따옴표 include 다섯, `nextdev/kmreg.h` 를 들임)·`next/cpu.h`(C 에서는 쓰지 않음, D109; `N_SIMM` 4 가 `next/cpu.h:59` 에 있음)·`next/machparam.h`. `nextdev/kmreg.h` 는 COMMON `km`·`alert_key`·`km_coni` 를 낼 수 있음(원본에 `_km` 0x40b68d0·`_alert_key` 0x40b67f4·`_km_coni` 0x40b693c 가 있음, 기호표).

방법(진단; 명세 `08_build/artifacts/m4p581/spec.json`, run `m4p581-d1`, 바탕 `m0p579-a1-stage`; scratchpad `gen_p581.py`). 스테이지의 `src/mon/global.h`(부분)가 `-I` 앞쪽에서 먼저 찾히므로 진단 전체 머리는 `monfull/global.h` 라는 다른 경로로 둠:
- 진단 머리(`inc`, NeXTMach 사본): `monfull/global.h`(= `mon/global.h`; `<next/cpu.h>` → `<m68k/cpu.h>` + `N_SIMM` 4 진단 정의, `<next/machparam.h>` → `<m68k/machparam.h>`), `mon/assym.h`·`region.h`·`tftp.h`·`bootp.h`·`animate.h`(그대로), `mon/sio.h`(`<nextdev/disk.h>` → `<dev/disk.h>`), `mon/kmreg.h`·`nextdev/kmreg.h`(따옴표 include 를 `<…>` 로).
- 객체 셋(모두 컴파일 줄은 M5 줄과 같은 틀; `m4_id` 는 L1 계산용으로 `m68k-266` 을 씀 — `subr_prf`·`mgoff` 의 L1 은 뜻 없음):
  - `mgoff` O1: `struct mon_global` 의 66 칸 오프셋과 `sizeof` 를 초기값 있는 `int` 로 둠(§568 꼴).
  - `clock` C0(07 `clock.c` 그대로)·C1(그 import 만 `<monfull/global.h>`).
  - `subr_prf` S0(07 `subr_prf.c` 그대로)·S1(그 import 만 `<monfull/global.h>`).
- 측정: 명령 종료 코드·경고; `-M` 의존 목록에서 진단 머리가 `inc` 사본에서 왔는지(출처); O1 `__data` 값(python); C0 대 C1·S0 대 S1 의 canon·`obj_sig`(섹션·기호·STABS 수), COMMON 이름과 크기, 새 COMMON 이 원본 기호표에 있는지; S0·C0 가 받아들인 객체(M5 `08_build/runs/m3p579-cc1/out/O579__L2_159__subr_prf.o`, §535 `08_build/runs/m4p535-a1/stage/Q535__clock_F.o`)와 canon·`obj_sig`·COMMON 이 같은지.
판정(미리 정함; 07 은 바꾸지 않음): (1) 닫힘이 컴파일되고 (2) O1 의 `mg_minor`·`mg_seq`·`mg_major` 가 0x30a·0x30c·0x312 이고(`mg_anim_run` 은 값만 기록) (3) S1·C1 이 S0·C0 와 canon 같으면(새 COMMON 은 모두 원본에 있음) 다음 계획(§582)에서 07 머리를 바꾸는 구현 계획을 씀(STABS 차이는 재수락으로 다룸). (2) 가 다르면 NeXTMach 배치가 1997 과 다르므로 멈추고 사용자에게 물음. (1)·(3) 이 안 되면 원인을 적고 다음 진단을 계획함.
관문: i386 머리 0, 옵션 = M5 줄; 컴파일 실패·경고는 기록.

### 581.1 교차검토(codex `gpt-6-luna` — `gpt-6.1-sol` 이 이번 호출에서 "not supported" 로 거부되어 메모리의 대체 모델을 씀) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `monfull/global.h` 는 스테이지에 없는 이름이라 진단 사본이 쓰이고, `inc` 디렉터리는 기존 `-I` 뒤에 붙음; 어느 사본이 쓰였는지는 `-M` 출처로 확인해야 함 | §580 에서 `m4_m68k_probe.py:223–225` 확인(이번 세션) | ✅ 측정에 `-M` 출처를 더함 |
| `sio.h` 는 `struct device` 를 스스로 정의함; `MONITOR` 조건·끝 쉼표는 컴파일로만 판단 | 사본 `mon/sio.h` 를 엶(이번 세션 sed, `struct sio` 앞뒤) | ⏭️ 컴파일 결과로 |
| `tftp.h` 닫힘 문구가 부정확(`bootp.h` 는 스테이지에 없음) | §581 명세의 `inc` 목록 | ✅ 문구 고침 |
| `nextdev/kmreg.h` 의 COMMON(`km`·`alert_key`·`km_coni`)은 이름과 크기를 볼 것 | — | ✅ 측정에 크기를 더함 |
| 원본 `_panic` 은 +0x30c·+0x30a·+0x312 만 읽음; +0x30e(`mg_anim_run`)는 바이트 근거가 아님 | 원본 0x400bca0–0x400bcca 읽음(`movew a3@(0x30c)`, `a3@(0x30a)`, `a3@(0x312)`) | ✅ 제 오류(근거 구분). 사실 줄과 판정 (2) 고침 |
| `canon` 은 섹션·재배치만 비교 — 받아들인 객체와의 비교에 `obj_sig`·COMMON 크기도 볼 것; `clock` 기준은 `m4p535-a1` 의 `Q535__clock_F.o` | `ls` 로 그 객체 있음, §535 최종 기록의 `source` 가 `src/machdep/m68k/clock.c` | ✅ 측정에 경로와 비교 항목을 적음 |
| 세 객체가 `m68k-266` 을 함께 써도 됨 | — | ⏭️ run 의 stage 명령으로 확인 |

### 581.2 결과(run `m4p581-d1`, 2026-10-30)

- C0·S0(07 글 그대로): 종료 0; C0 = §535 `Q535__clock_F.o`, S0 = M5 `O579__L2_159__subr_prf.o` — canon·`obj_sig`·COMMON(이름·크기) 모두 같음(python) → 대조군으로 씀. 기록 `09_validation/reconstruction/m4-m68k-probe-p581-d1-20261030.json`.
- O1·C1·S1(전체 머리): 셋 다 종료 1 — 같은 원인: `mon/tftp.h:20` → 스테이지 `nfs/nfs.h:121` 의 `fsid_t` 를 모름(1997 `fsid_t` 는 `sys/vfs.h:30` 의 형인데 `nfs/nfs.h` 는 그것을 들이지 않음). 판정 (1) 실패 → 다음 진단(§582).

## 582. M4-88 세부 계획 — 전체 `mon/global.h` 닫힘 두 꼴 진단(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p582/spec.json`, run `m4p582-d1`, 바탕 `m0p579-a1-stage`; scratchpad `gen_p582.py`; 소스는 §581 의 O1·C1·S1 그대로): §581 진단 머리를 두 꼴로 —
- a(`inca/`): `mon/tftp.h` 사본에서 `<nfs/nfs.h>` 앞에 `#import <sys/vfs.h>` 한 줄(진단 표시).
- b(`incb/`): `monfull/global.h` 사본에서 `#import <mon/tftp.h>` 를 뺌(진단 표시; `struct mon_global` 은 `tftp.h` 의 이름을 쓰지 않음 — 51–121 행), `tftp.h`·`bootp.h` 사본 없음.
- 변형: OA·OB(오프셋), CA·CB(`clock`), SA·SB(`subr_prf`) — 끝 글자가 꼴(a/b); 도구가 변형 이름에 대문자만 받으므로 대문자로 씀.
- 측정: §581 과 같음(종료 코드·경고, `-M` 출처, O 값, C·S 를 C0·S0 대조군과 canon·`obj_sig`·COMMON 이름과 크기로 비교, 새 COMMON 의 원본 기호표 대조).
판정(미리 정함; 07 은 바꾸지 않음): §581 의 (1)–(3) 을 꼴마다 봄((1) 은 종료 0 — 경고는 기록만). 둘 다 넘거나 하나만 넘으면 넘은 꼴들을 보여 주고 구현 꼴(머리를 어디에 어떤 글로 둘지, `tftp.h` 를 둘지)을 사용자 결정으로 묻고 §583 구현 계획을 씀. 둘 다 못 넘으면 원인을 적고 다음 진단. (2) 가 다르면 멈추고 물음.
관문: i386 머리 0, 옵션 = M5 줄; 실패·경고는 기록.

### 582.1 교차검토(codex `gpt-6-luna`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 581.2 의 원인은 맞음(`nfs.h:121·130` 은 `NFS_SERVER` 안의 `fsid_t`, `sys/vfs.h:28–30` 정의, `nfs.h` 는 그것을 들이지 않음); a 는 그 오류를 넘을 것 | 스테이지 `nfs.h:115–122`·`vfs.h:30` 을 엶(이번 세션) | ✅ (넘는지는 run 으로) |
| `struct mon_global` 은 `tftp.h`·`bootp.h` 이름을 쓰지 않음 | NeXTMach `global.h:51–121` 을 읽음(이번 세션) | ✅ |
| `inca`·`incb` 는 적은 대로만 다름, 명세 일치 | `diff -r`(이번 세션; `incb` 의 남은 `tftp.h`·`bootp.h` 파일은 지움) | ✅ |
| 한 꼴만 넘는 경우와 경고 처리를 판정에 적을 것 | — | ✅ 판정 문구 고침 |

### 582.2 결과(run `m4p582-d1`, 2026-10-30)

- 여섯 변형 모두 종료 0·경고 0, i386 머리 0(기록 `09_validation/reconstruction/m4-m68k-probe-p582-d1-20261030.json`).
- OA = OB(66 칸 오프셋·크기 같음): `mg_minor` 0x30a, `mg_seq` 0x30c, `mg_major` 0x312 — 원본 `_panic` 이 읽는 자리와 같음(판정 (2) 넘음); `mg_anim_run` 0x30e, `mg_console_o` 0x31c, `km_coni` 0x324, `mg_as_tune` 0x3aa, `mg_flags2` 0x3ae, `sizeof` 0x3b2(python).
- CA·CB·SA·SB 를 받아들인 객체(§535 `Q535__clock_F.o`, M5 `O579__L2_159__subr_prf.o`)와 비교: canon(섹션·재배치) 모두 같음. `obj_sig` 는 기호와 STABS 수가 다름 — 새 COMMON 은 모두 원본 기호표에 있는 이름:
  - a(`tftp.h` 들임): `clock` STABS 994 → 1429, 새 COMMON 17(`_km` 106·`_km_coni` 128·`_alert_key` 4, 망 자료 `_ifnet`·`_ipq`·`_ipstat`·`_ip_id`·`_rawintrq`·`_rthost`·`_rtnet`·`_rtstat`·`_udb`·`_udpstat`·`_etherbroadcastaddr`, tty `_tthiwat`·`_tthog`·`_ttlowat`); `subr_prf` 691 → 1026, 새 COMMON 14.
  - b(`tftp.h` 뺌): `clock` 994 → 1203, 새 COMMON 6(`_km`·`_km_coni`·`_alert_key`·`_tthiwat`·`_tthog`·`_ttlowat`); `subr_prf` 691 → 802, 새 COMMON 3(`_km`·`_km_coni`·`_alert_key`).
- 판정: 두 꼴 모두 (1)–(3) 을 넘음 → 구현 꼴을 사용자에게 물음. 어느 꼴이든 07 머리를 바꾸면 `clock`(M4)은 새 머리로 다시 받아들여야 하고(§554.3 과 같은 까닭), M5 `subr_prf` 는 섹션·재배치가 같아 `stage_m68k.py compare` 는 통과할 것이나 객체 바이트(기호표·STABS)는 달라짐.

- 사용자 결정(2026-10-30, AskUserQuestion): ① `mon/tftp.h` 는 "그대로 둠"(꼴 a: NeXTMach 글대로 `tftp.h`·`bootp.h` 를 07 에 두고 `tftp.h` 에 `#import <sys/vfs.h>` 한 줄) ② `N_SIMM` 은 "global.h 안에 정의"(D113·D121 꼴, 값 `next/cpu.h:59`). 같은 날 사용자 지시: codex 모델은 당분간 `gpt-6-luna`.

## 583. M4-89 D132 구현 계획 — 07 전체 `mon/global.h` 와 닫힘 머리, 스테이징의 overlay 뺌, `clock` 재수락(코딩 전, 2026-10-30)

확인한 사실(이번 세션): §581–582 결과와 결정. 지금 `src/mon/global.h` 는 07 overlay `07_kernel/v183.34/m68k/src/mon/global.h`(부분 머리)에서 오고, overlay 는 모든 plan 의 스테이지에 들어감(`stage_m68k.py` 의 overlay 고리, 538–550 행); `M4HEADERS` 는 overlay 와 같은 경로를 받지 않음(518 행 `dst not in ovl`). 받아들인 객체 가운데 `mon/global.h` 를 쓰는 것은 `clock`(§535 최종 기록의 의존 목록) 하나이고, M5 에서는 `subr_prf.c` 하나(스테이지 grep: `clock.c`·`subr_prf.c`·`global.h` 자신). 07 overlay 를 그 자리에서 고치면 옛 plan 의 재생성 스테이지가 닫힘 머리 없이 전체 머리를 받아 컴파일되지 않으므로, overlay 파일은 그대로 두고 plan 583 부터만 빼는 꼴을 씀.
1. 07 새 머리(`07_kernel/nextmach/`, D104; NeXTMach mk-108.1 사본, 고지 그대로, D013):
   - `mon/global.h`: NeXTMach 글 + 표시 줄(plan 583, D132): `<next/cpu.h>` → `<m68k/cpu.h>`(D109·D110), 그 뒤 `#define N_SIMM 4`(`next/cpu.h:59`, 사용자 결정), `<next/machparam.h>` → `<m68k/machparam.h>`(D104). 머리 주석 한 덩이.
   - `mon/tftp.h`: NeXTMach 글 + `<nfs/nfs.h>` 앞 `#import <sys/vfs.h>`(표시; 1997 `nfs/nfs.h:121·130` 의 `fsid_t`, §581.2·사용자 결정).
   - `mon/sio.h`: `<nextdev/disk.h>` → `<dev/disk.h>`(표시, D104).
   - `mon/assym.h`·`mon/region.h`·`mon/bootp.h`·`mon/animate.h`·`mon/kmreg.h`·`nextdev/kmreg.h`: NeXTMach 그대로(`kmreg.h` 둘의 따옴표 include 도 그대로 — 따옴표는 그 파일의 디렉터리를 먼저 찾고 없으면 `-I` 차례로 찾으므로 §582 의 `<…>` 꼴과 같은 파일로 풀림; 확인은 3 의 `-M` 출처).
2. `stage_m68k.py`: 새 표 `OVLDROP`(PLAN 이하 최대 키; 583 전에는 빈 목록) = `{583: ['src/mon/global.h']}` — 그 overlay 경로를 복사하지 않고 `M4HEADERS` 의 overlay 충돌 검사에서도 뺌; 매니페스트에 `overlays_dropped` 키를 PLAN ≥ 583 일 때만 둠(옛 plan 매니페스트는 그대로). `M4HEADERS[583]` = 573 + `('mon/global.h','src/mon/global.h')`, `('mon/assym.h','src/mon/assym.h')`, `('mon/region.h','src/mon/region.h')`, `('mon/tftp.h','src/mon/tftp.h')`, `('mon/bootp.h','src/mon/bootp.h')`, `('mon/animate.h','src/mon/animate.h')`, `('mon/sio.h','src/mon/sio.h')`, `('mon/kmreg.h','src/mon/kmreg.h')`, `('nextdev/kmreg.h','src/bsd/nextdev/kmreg.h')`; `M4FILES` 는 그대로(579 의 것), `EXCEPTS[583] = dict(EXCEPTS[579])`, 머리말 plan 목록에 583. 07 overlay `v183.34/m68k/src/mon/global.h` 는 바꾸지 않음(옛 plan 과 옛 기록을 위해).
3. 회귀: `--plan 579` 재생성(`m0p579-r583-stage`)이 보관 `m0p579-a1-stage` 와 모든 키·파일이 같음; `m0p583-a1-stage` 와 보관 579 의 차이는 `src/mon/global.h`(출처·SHA)와 새 머리 여덟, 매니페스트 키(`plan`·`m4_headers`·`overlays_dropped`·`files`). M5 205 줄(`m5-579.cmd` 가 §579 것과 `cmp` 같음; run `m3p583-b579`·`m3p583-cc1`): 객체 204 개 바이트 같음, 다른 하나는 `subr_prf` 이고 b579 와 canon 같음, `obj_sig` 는 §582 SA 객체와 같음(새 COMMON 14 개 모두 원본 기호표에 있음), stderr 205 같음; `compare` 두 기록의 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 새·바뀐 경로뿐. `subr_prf` 의 `-M`(cc1 run 의 의존 출력)에서 새 머리가 07 nextmach 출처. x86 `m4_x86_inputs.py s6ln`(환경 변수)·`--plan 583 x86gate` 일곱 같음.
4. `clock` 재수락(§554.3 꼴): 확인 run `m4p583-p1`(`08_build/artifacts/m4p583/confirm/spec.json`, 바탕 `m0p583-a1-stage`): R = `@machdep/m68k/clock.c`(07 파일 그대로). 종료 0, 경고는 §535 와 같음(경로·줄 같음), i386 0; R 이 §535 `Q535__clock_F.o` 와 canon 같고 `obj_sig` 는 §582 CA 와 같음(새 COMMON 17 개 모두 원본에 있음); L1 `OBJECT_MATCH`; `m68k_funcbytes.py 40910d6 4091e18 …` 22/22.
5. 최종 run `m4p583-a1`(명세 `08_build/artifacts/m4p583/spec.json`: `clock` F 만, `m4_id` `m68k-266`, `refs["clock"]` = [p1 R 객체, SHA], `known_warnings` 는 p1 stderr 가 있으면 그대로; 기록 `m4-m68k-p583-final-20261030.json`): `gate.ok`, 22/22; python 확인 `m4-m68k-p583-checks-20261030.json`: §535 확인 항목(정의·`__data`·`__cstring`·L1)이 같고, COMMON 이 §535 의 것 + 새 17 개(모두 원본에 있음), 의존 목록 전수 사슬(07 출처면 07 파일과 같음; 새 머리 아홉과 `global.h` 가 07 nextmach 출처) 문제 0, i386 0.
6. 상태표: `ACCEPTED` 의 §535 줄을 plan 583 기록 줄로 바꿈(주석에 까닭); 도구 두 번 실행, §579 표와 이름 대조(바뀐 것은 `clock` 의 plan·기록·SHA 뿐, 수치 그대로: 32 객체, 51/188, 54584 B, `object_bytes` 71546 — 같은 크기). 근거 문서 `06_reconstruction/evidence/m68k-clock.md` 에 plan 583 절을 먼저 더함.
7. 기록: 새 근거 `06_reconstruction/evidence/m68k-mon_global.md`·diff(NeXTMach 대비 `m68k-mon_global_h.diff` — 고친 셋 `global.h`·`tftp.h`·`sio.h`), PROVENANCE 새 행 아홉(일곱 칸)과 `clock.c` 행의 최종 기록 갱신, MODIFICATIONS, DECISIONS D132, 계획 결과·현재 상태, HANDOFF, 메모리. M5 `subr_prf` 는 받아들임 기록이 따로 없으므로(M5 는 205 줄 회귀로 관리) 회귀 기록에 그 차이를 적음.
관문: 명령 종료 0, 정한 경고뿐, i386 머리 0, 회귀 같음(`subr_prf` 의 기호표·STABS 차이만), 상태 도구가 멈추지 않음.

### 583.1 교차검토(codex `gpt-6-luna`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `OVLDROP` 는 `M4HEADERS` 의 `ovl` 집합(508–522 행)과 overlay 복사 고리(537–550 행)에서만 쓰고 `overlay_files()` 는 그대로 둘 것(M4SRC 감사에도 씀); 매니페스트(555–561 행)에 583 부터 키를 더함; 다른 소비자 없음 | `stage_m68k.py` 518·538–550·553–561 행을 엶(이번 세션) | ✅ 그대로 구현 |
| 낙후 후 `compare` 의 overlay 보고는 `src/mon/global.h` 를 nextmach `M4` 머리로 보게 됨 | — | ⏭️ 회귀 기록에서 확인 |
| 상태 도구는 기록·명세 SHA, 07 소스의 현재 SHA, 매니페스트 `m4_headers` 출처의 현재 SHA 만 검사(전체 `-M` 사슬은 아님); p535 줄을 빼고 p583 줄로 바꾸면 됨 | `m4_m68k_status.py` 88–110 행을 엶 | ✅ (최종 확인의 전수 사슬 검사는 그대로 함) |
| `obj_sig` 는 STABS 의 수만 보므로 §582 객체와의 같음은 뜻이 제한됨; canon·비 STABS 기호·COMMON 크기·`-M` 사슬을 함께 볼 것 | `l2_prefix_diff.py:48–53`(§576.1 에서 확인) | ✅ 3·4 의 기준에 COMMON 이름·크기와 `-M` 출처를 함께 둠 |
| 따옴표 include 는 같은 파일로 풀릴 것이나 진단은 `<…>` 꼴이었으므로 `-M` 출처로 확인할 것 | — | ✅ 3·5 의 `-M` 확인으로 |
| 줄 번호·경로·개수 맞음("새 머리 여덟" 은 `global.h` 를 뺀 수) | — | ✅ |

### 583.2 결과(2026-10-30)

- 1: 07 새 머리 아홉(`07_kernel/nextmach/mon/{global,assym,region,tftp,bootp,animate,sio,kmreg}.h`, `nextmach/nextdev/kmreg.h`): `global.h`(137 행, SHA `dee63a54…`)·`tftp.h`·`sio.h` 는 표시 줄만 다르고(diff `06_reconstruction/evidence/m68k-mon_global_h.diff` 50 행) 나머지 여섯은 NeXTMach 과 `cmp` 같음.
- 2: `stage_m68k.py` 694 → 707 행(`M4HEADERS[583]`·`OVLDROP`·`M4FILES[583]`·`EXCEPTS[583]`, overlay 두 자리의 뺌, 매니페스트 `overlays_dropped`; `python3 -c ast.parse` 통과).
- 3: `--plan 579` 재생성(`m0p579-r583-stage`)이 보관 `m0p579-a1-stage` 와 모든 키·파일이 같음(옛 plan 불변). `m0p583-a1-stage`(965 파일)와 보관 579 의 차이: `src/mon/global.h`(출처 `07_kernel/v183.34/m68k/…` → `07_kernel/nextmach/mon/global.h`)와 새 머리 여덟, 키 `added`·`files`·`m4_headers`·`overlays_dropped`·`plan`. M5: `m5-579.cmd` 가 §579 것과 `cmp` 같음, run `m3p583-b579`·`m3p583-cc1` 종료 0, 객체 204 개 바이트 같음, 다른 하나 `subr_prf` 는 canon 같고 `obj_sig`·COMMON 이 §582 SA 와 같음(새 COMMON 14 개, 모두 원본 기호표에 있음), stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p583-compare-20261030.json`, `-b579-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 새 머리 여덟뿐. x86 `m4-x86-inputs-p583-20261030.json` `ok`, `--plan 583 x86gate` 일곱 같음·`v183_paths` 0.
- 4: run `m4p583-p1`(`m4-m68k-probe-p583-p1-20261030.json`): R 종료 0·경고 0·OBJECT_MATCH, §535 객체와 canon 같음, `obj_sig`·COMMON 이 §582 CA 와 같음(새 COMMON 17, 모두 원본에 있음); `-M` 에서 `src/mon/*.h`·`src/bsd/nextdev/kmreg.h` 가 07 nextmach 출처(따옴표 include 도 같은 파일로 풀림). 함수별: 처음 돌린 `m68k_funcbytes.py`(`-R-` 기록)는 §535 의 정적 자료 대응을 빠뜨려 21/22(`sec_to_tm` 의 `_dmsize`/`_dayyr+24` 거짓 차이 — 오늘 §535 객체에 같은 명령을 돌려도 21/22) — 제 실수; 대응 `40b28aa=_dmsize 40b28c2=_ly_dmsize` 를 붙여 22/22(`m4-m68k-funcbytes-p583-R2-20261030.json`).
- 5: run `m4p583-a1`(`m4-m68k-p583-final-20261030.json`, SHA `52c84b95…`; REF = p1 R, `known_warnings` 없음): `gate.ok`, 옵션 차이 없음, 22/22(대응 포함, `m4-m68k-funcbytes-p583-a1-20261030.json`); 확인 `m4-m68k-p583-checks-20261030.json`(`ok` 참): §535 객체와 canon·정의·미정의·섹션 크기 같음, §535 COMMON 유지 + 새 17, L1 0x40910d6 OBJECT_MATCH 사유 없음, 의존 123 파일 전수 사슬 문제 0·i386 0. 객체 SHA `542787e9…`.
- 6: 근거 `m68k-clock.md` 에 plan 583 절, 새 근거 `m68k-mon_global.md`. `ACCEPTED` 의 §535 줄을 plan 583 줄로 바꿈. 상태표(34 행 그대로)·`m4-m68k-status-p583-20261030.json`: 수치 그대로(32 객체, OBJECT_MATCH 25, 51/188, 54584 B 25.29%, `object_bytes` 71546), 바뀐 것은 `clock` 의 plan·기록·객체 SHA 뿐, 두 번 실행 같음.
- 7: PROVENANCE 1169 → 1178 행(새 아홉, `clock.c`·옛 `v183.34/m68k/src/mon/global.h` 행 갱신; 일곱 칸), MODIFICATIONS 714 → 715 행, DECISIONS D132(135 → 136 행), "현재 상태와 다음 일" 고침.

## 584. M4-90 세부 계획 — `next/machdep.c` 진단 A2(바탕 plan 583; 07 변경 없음; 코딩 전, 2026-10-30)

목적: §580 의 A1 이 걸린 이름을 채워 첫 컴파일을 얻고 원본과 함수별로 비교함(§580 판정 규칙 그대로: 컴파일이 안 되면 첫 오류를 적고 최소 진단 고침으로 다시).

확인한 사실(이번 세션):
- §583 으로 스테이지에 전체 `mon/global.h` 가 있어 A1 의 `MG`·`MG_seq`·`MG_anim_run`·`CONS_O_BITMAP`·`mg_as_tune` 오류는 사라질 것; `nextdev/kmreg.h` 도 07 사본이 스테이지에 있음(§583) → 진단 사본에서 뺌.
- A1 이 쓰고 SDK `m68k/cpu.h` 에 없는 NeXTMach `next/cpu.h` 이름(python, 주석 뺀 식별자 대조): `I_BIT`·`I_POWER`·`P_DSP`·`P_MON`(그 정의가 쓰는 `SLOT_ID`·`SLOT_ID_BMAP`·`I`, `slot_id`·`slot_id_bmap` 선언) — 값은 NeXTMach `next/cpu.h:96·98·152·153·213·216·262`. SDK `m68k/cpu.h` 는 `slot_id` 를 선언하지 않음(grep 0).
- `us_callout`·`us_callfree` 는 NeXTMach `next/us_timer.h:18` 의 `extern struct callout *us_callfree, *us_callout, us_calltodo;`(A1 은 SDK `kernserv/m68k/us_timer.h` 를 들임). 원본 구간은 `_ns_callout_init`·`_ns_callout` 을 가리키므로 1997 판은 다를 것(진단 비교로 봄).
- 원본 `sendsig`([0x40947be, 0x40948de), `rts` 0x40948dc)에는 `current_thread()->pcb->pcb_flags & TRACE_AST` 와 `SR_TSINGLE` 검사가 없음(목록을 읽음: `active_u`(0x40b57d0)·0x40b57d4 를 쓰는 몸에 그런 비교 없음) → NeXTMach 1140–1143 행 덩이는 바이트에 없는 코드.
방법(명세 `08_build/artifacts/m4p584/spec.json`, run `m4p584-p1`, 바탕 `m0p583-a1-stage`, §580 명시 구간 그대로; scratchpad `gen_p584.py`):
- 변형 A2(`machdep_A2.c`, SHA-256 `dd5a59f0…`): A1 + 진단 셋 — (1) `<m68k/cpu.h>` 뒤에 위 `next/cpu.h` 이름 덩이, (2) `<kernserv/m68k/us_timer.h>` 뒤에 `extern struct callout *us_callfree, *us_callout;`, (3) `sendsig` 의 `TRACE_AST` 덩이 넉 줄을 뺌(바이트 근거). 진단 머리는 `next/scb.h`·`next/scr.h` 사본만(§580 과 같음).
- 측정: 종료 코드·경고(각 명령), 컴파일되면 `m68k_funcbytes.py 40936a4 4094a7c OBJECT.o RECORD.json`(A2 에는 0x4093792 에 해당하는 도움 함수가 없으므로 대응 없이; 원본에만 있는 `kernel_thread_noblock`·`callout_dispatch`·`callout_remove`·0x4093792 와 객체에만 있는 `setregs`·`boot`·`unmount_all`·`kill_tasks`·`physstrat` 를 따로 적음), 섹션, 자료는 기호마다 이름·값·저장 꼴로 비교(원본 [0x40b2b82, 0x40b2b92) 의 `nbuf`·`nmfsbuf`·`bufpages`·`nsoftint` 와 다른 자리의 `_nrnode` 0x40aedd8·`_waittime` 0x40ae23a; A2 는 `nsoftint = 100`·`nmfsbuf` 없음), `__cstring`, 정의된 외부 함수 이름(구간의 원본 정의 이름 22 와 대조)·COMMON·원본에 없는 미정의; 실기 `otool -tv` 로 함수 비교를 시작함.
판정(미리 정함; 07 은 바꾸지 않음): 컴파일이 안 되면 첫 오류의 원인을 적고 최소 진단 고침(A3…)으로 다시(모두 진단 표시, 고친 것과 근거를 결과에 적음). 컴파일되면 함수별 같음/다름과 차이를 적고 다음 계획을 세움.
관문: 종료 0(진단 고침 뒤), i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 584.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A2 138–145·154 행의 진단 정의는 NeXTMach 값과 같고 A1 의 오류 이름을 덮음; `MG`·`MG_seq`·`CONS_O_BITMAP`·`mg_as_tune` 은 스테이지 전체 `mon/global.h`·`mon/assym.h` 가 줌 | A2 diff(이번 세션), NeXTMach `next/cpu.h:96·98·152·153·213·216·262`(이번 세션 grep) | ✅ (나머지는 컴파일로) |
| 다른 이름(`scr2`·`SCR2_*`, `km`·`KMF_*`, `r_*`, `u_*`, `sc_*`, `valloc`, `ncallout`)은 스테이지·진단 사본에 있어 새 오류는 없을 것; 600·610·627 행 경고는 남을 것 | — | ⏭️ 컴파일 결과로 |
| `PGINPROF`·`NCPUS>1` 갈래는 이 구성에서 꺼짐(`generated/cpus.h:1` `NCPUS 1`) | — | ⏭️ |
| 원본 `sendsig` 에 `TRACE_AST`·`SR_TSINGLE` 검사 없음; 끝은 0x40948de(배타, `rts` 0x40948dc) — 제가 적은 0x40948d6 은 틀림 | 함수 표 `_sendsig` 0x40947be–0x40948de(이번 세션 awk), 원본 목록 0x40947be–0x40948d4 읽음 | ✅ 제 오기. 고침 |
| 0x4093792 대응은 A2 에 없으니 빼고, 원본에만·객체에만 있는 함수를 적을 것 | `m68k_funcbytes.py:95–96`(대응 인자) | ✅ 측정 줄 고침 |
| 자료는 기호마다 비교할 것(A2 는 `nsoftint = 100`, `nmfsbuf` 없음, `nrnode`·`waittime` 은 원본에서 다른 자리) | A2 173·175·541·1215 행 grep, 기호표(§580.1) | ✅ 측정 줄 고침 |
| "원본 22 이름" 은 정의 이름이지 외부 참조가 아님; 명세 `basis` 의 "follows machargs" 는 `_machparam` 이 정확 | §580 사실 줄(정의 이름 22, 외부 `__text` 주소 42) | ⚖️ 측정 문구는 고침; `basis`(machargs 객체가 0x40936a4 에서 끝남, §517)는 사실이라 그대로 |

### 584.2 결과(run `m4p584-p1`, 2026-10-30)

- A2(`dd5a59f0…`): 컴파일 종료 1(기록 `09_validation/reconstruction/m4-m68k-probe-p584-20261030.json`). §580 의 이름 오류(`P_MON`·`I_POWER`·`P_DSP`·`us_callout`·`MG`·`mg_as_tune`·`TRACE_AST`)는 모두 사라짐. 새 오류: `src/mon/tftp.h:13` → `netinet/ip.h:98·107·117` 문법 오류. 경고는 A1 과 같은 둘(610·629 행).
- 원인(이번 세션에 엶): 스테이지 `src/ipc/ipc_port.h:148` 의 `#define ip_timestamp data.timestamp`(Mach IPC 포트 매크로)가 `netinet/ip.h:98` 의 `struct ip_timestamp` 와 부딪힘. `machdep.c` 는 Mach 머리(`kern/task.h` 등)로 `ipc_port.h` 를 먼저 들인 뒤 `mon/global.h` → `mon/tftp.h` → `netinet/ip.h` 를 들임. §581–582 의 진단 객체(`clock`·`subr_prf`)는 `ipc_port.h` 를 들이지 않아 이 충돌이 드러나지 않았음 — D132 의 "`tftp.h` 그대로 둠" 결정 때 없던 정보.
- 판단: `tftp.h` 를 두는 꼴(D132)이면 `ipc_port.h` 와 `mon/global.h` 를 함께 들이는 07 파일마다 우회가 필요함. 사용자에게 다시 물음.

- 사용자 결정(2026-10-30, AskUserQuestion): `ip_timestamp` 충돌에 대해 "global.h 에서 tftp.h 빼기" — D132 의 `tftp.h` 부분을 바꿈(§582 꼴 b).

## 585. M4-91 D133 구현 계획 — 07 `mon/global.h` 에서 `tftp.h` 를 뺌, `clock` 재수락(코딩 전, 2026-10-30)

확인한 사실(이번 세션): §584.2 의 원인과 결정. §582 꼴 b(`tftp.h` 를 뺀 전체 머리)는 컴파일되고 배치가 같으며(OB = OA), `clock`·`subr_prf` 는 받아들인 객체와 canon 같고 새 COMMON 이 각각 6·3 개(모두 원본에 있음)였음. 상태 도구는 받아들인 기록마다 명세 바탕 매니페스트의 `m4_headers` 출처 SHA 가 지금과 같은지 검사함(`m4_m68k_status.py:99–102`) → 07 `mon/global.h` 를 고치면 plan 583 기록(`clock`)이 그 검사에 걸리므로 다시 받아들임(§554.3 꼴).
1. 07 `07_kernel/nextmach/mon/global.h`: `#import <mon/tftp.h>` 줄을 지우고 그 자리에 표시 주석(plan 585, D133: NeXTMach import 를 뺀 까닭 — `struct mon_global` 은 `tftp.h` 의 이름을 쓰지 않고, `tftp.h` → `netinet/ip.h` 의 `struct ip_timestamp` 가 07 `ipc/ipc_port.h:148` 의 매크로와 부딪힘), 머리 주석에 한 줄. `mon/tftp.h`·`mon/bootp.h` 07 파일은 그대로 둠(plan 583 스테이지의 이력).
2. `stage_m68k.py`: `M4HEADERS[585]` = 583 에서 `mon/tftp.h`·`mon/bootp.h` 를 뺀 목록, `M4FILES[585] = list(M4FILES[579])`, `EXCEPTS[585] = dict(EXCEPTS[583])`, 머리말 plan 목록에 585; `OVLDROP` 은 583 의 것을 그대로 씀(최대 키).
3. 회귀: `--plan 583` 재생성(`m0p583-r585-stage`)은 보관 `m0p583-a1-stage` 와 `src/mon/global.h` 의 SHA 하나만 다름(07 파일을 고쳤으므로; 매니페스트 키는 같음 — python assert); `--plan 579` 재생성은 보관본과 모든 키·파일이 같음. `m0p585-a1-stage` 와 보관 583 의 차이: `src/mon/global.h`(SHA), 없어진 `src/mon/tftp.h`·`src/mon/bootp.h`(파일 963 개), 키는 `plan`·`m4_headers`·`files` 셋(`added` 는 overlay 의 것이라 그대로). M5 205 줄(`m5-583.cmd` 가 §583 것과 `cmp` 같음; run `m3p585-b583`(보관 583 스테이지)·`m3p585-cc1`): 객체 204 개 바이트 같음, `subr_prf` 는 b583 과 canon 같고 `obj_sig`·COMMON 이 §582 SB 와 같음(§579 대비 새 COMMON `_km`·`_km_coni`·`_alert_key` 셋), stderr 205 같음; `compare` 두 기록 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 경로(빠진 `tftp.h`·`bootp.h`)뿐. x86 `m4_x86_inputs.py s6ln`·`--plan 585 x86gate`.
4. `clock` 재수락: 확인 run `m4p585-p1`(R = `@machdep/m68k/clock.c`): 종료 0·경고 0, §535 객체와 canon 같음, `obj_sig`·COMMON 이 §582 CB 와 같음(새 COMMON 6), `-M` 에 `tftp.h`·망 머리 없음, L1 OBJECT_MATCH, 22/22(대응 `40b28aa=_dmsize 40b28c2=_ly_dmsize`). 최종 run `m4p585-a1`(명세 `08_build/artifacts/m4p585/spec.json`: `clock` F, `refs` = p1 R; 기록 `m4-m68k-p585-final-20261030.json`): `gate.ok`, 22/22; 확인 `m4-m68k-p585-checks-20261030.json`(§583 과 같은 항목, 새 COMMON 6, 사슬 전수).
5. 상태표: `ACCEPTED` 의 plan 583 줄을 plan 585 줄로 바꿈; 두 번 실행, 바뀐 것은 `clock` 의 plan·기록·SHA 뿐(수치 그대로).
6. 기록: `m68k-mon_global.md`·`m68k-clock.md` 에 plan 585 절, diff 새로 만듦(`m68k-mon_global_h.diff` 를 덮지 않고 `m68k-mon_global_h-p585.diff`), PROVENANCE(`global.h` 행 갱신, `tftp.h`·`bootp.h` 행에 "plan 583 에서만 스테이지", `clock.c` 행에 plan 585 재수락), MODIFICATIONS, DECISIONS D133(D132 의 `tftp.h` 부분을 바꿈), 계획·HANDOFF·메모리. 그 뒤 §584 의 A2 를 새 스테이지로 다시 돌리는 진단은 따로 계획함.
관문: 명령 종료 0, `clock` run 경고 0(M5 는 stderr 가 b583 과 같음), i386 머리 0, 회귀 같음(`subr_prf` 의 기호표·STABS 차이만), 상태 도구가 멈추지 않음.

### 585.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 584.2 원인 맞음; `tftp.h` 를 빼면 A2 에서 `netinet/ip.h` 에 닿는 길은 없어짐(A2 를 다시 돌릴 때 `-M` 으로 확인) | 07 `ipc_port.h:148`, 실패 기록 `00.err` 첫 줄(이번 세션) | ✅ (A2 재실행 때 `-M` 확인) |
| 받아들인 기록 가운데 `m4_headers` 에 `src/mon/global.h` 가 있는 것은 p583 하나; 그 줄을 바꾸면 충분 | `m4_m68k_status.py:99–102`(§583.1 에서 엶) | ✅ 상태 도구 실행으로 확인 |
| p583 을 그대로 두면 `('header changed', '07_kernel/nextmach/mon/global.h')` 로 멈춤 | 같은 줄 | ✅ |
| 재생성 583 은 `global.h` 내용과 `files` 의 SHA 만 다르고 키는 같음; p585 대 583 의 키는 `plan`·`m4_headers`·`files`(`added` 그대로), 파일 963 | `stage_m68k.py` 의 `added` 는 overlay 고리에서만 채워짐(이번 세션 읽음 546–553 행) | ✅ 3 고침(수는 run 에서 확인) |
| CB/SB 의 `obj_sig` 기대는 합당(STABS 내용은 보지 않음); canon·의존 출처는 따로 | §583.2 에서 p583 객체 = CA/SA 확인 | ✅ |
| PROVENANCE `clock.c` 행 갱신을 적고, 경고 0 관문은 `clock` run 에만 | — | ✅ 6·관문 고침 |

### 585.2 결과(2026-10-30)

- 1·2: 07 `nextmach/mon/global.h` 137 → 138 행(SHA `d80db409…`; `tftp.h` import 줄을 표시 주석으로, 머리 주석 한 줄 더함), diff `06_reconstruction/evidence/m68k-mon_global_h-p585.diff`(35 행). `stage_m68k.py` 707 → 710 행(`M4HEADERS[585]`·`M4FILES[585]`·`EXCEPTS[585]`·머리말 목록).
- 3: `--plan 579` 재생성(`m0p579-r585-stage`) = 보관본(모든 키·파일); `--plan 583` 재생성(`m0p583-r585-stage`)은 보관본과 `src/mon/global.h` 하나·키 `files` 만 다름; `m0p585-a1-stage`(963 파일)와 보관 583 의 차이는 `src/mon/global.h`·`tftp.h`·`bootp.h`, 키 `files`·`m4_headers`·`plan`(python assert). M5: `m5-583.cmd` 가 §583 것과 `cmp` 같음, run `m3p585-b583`·`m3p585-cc1` 종료 0, 객체 204 개 바이트 같음, `subr_prf` 는 b583 과도 §579 객체와도 canon 같고 `obj_sig`·COMMON 이 §582 SB 와 같음(§579 대비 새 COMMON `_km`·`_km_coni`·`_alert_key`, 모두 원본에 있음), stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p585-compare-20261030.json`, `-b583-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에서 `tftp.h`·`bootp.h` 가 빠진 것뿐. x86 `m4-x86-inputs-p585-20261030.json` `ok`, `--plan 585 x86gate` 일곱 같음.
- 4: run `m4p585-p1`(`m4-m68k-probe-p585-p1-20261030.json`): R 종료 0·경고 0·OBJECT_MATCH, §535 객체와 canon 같음, `obj_sig`·COMMON 이 §582 CB 와 같음(새 COMMON 6, 모두 원본에 있음), `-M` 에 `tftp.h`·`bootp.h`·`netinet` 없음, 22/22(대응 포함). run `m4p585-a1`(`m4-m68k-p585-final-20261030.json`, SHA `f514b1c7…`; REF = p1 R): `gate.ok`, 22/22; 확인 `m4-m68k-p585-checks-20261030.json`(`ok` 참, 의존 100 파일 사슬 문제 0). 객체 SHA `9c02e1de…`.
- 5: `ACCEPTED` 의 plan 583 줄을 plan 585 줄로 바꿈; 상태표·`m4-m68k-status-p585-20261030.json`: 수치 그대로(32 객체, 51/188, 54584 B 25.29%, `object_bytes` 71546), 바뀐 것은 `clock` 의 plan·기록·SHA 뿐, 두 번 실행 같음.
- 6: 근거 `m68k-clock.md`·`m68k-mon_global.md` 에 plan 585 절; PROVENANCE 1178 행 그대로(`global.h`·`tftp.h`·`bootp.h`·`clock.c` 행 갱신, 일곱 칸), MODIFICATIONS 715 → 716 행, DECISIONS D133(136 → 137 행), "현재 상태와 다음 일" 고침.

## 586. M4-92 세부 계획 — `next/machdep.c` 진단 A2 를 plan 585 바탕으로 다시(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p586/spec.json` = §584 명세에서 `plan`·`base`(`m0p585-a1-stage`)·`basis` 의 plan 번호만 바꿈, run `m4p586-p1`): 변형 A2 는 §584 의 `machdep_A2.c`(SHA `dd5a59f0…`)와 진단 머리(`next/scb.h`·`next/scr.h` 사본) 그대로.
- 측정·판정: §584 와 같음(§584.1 에서 고친 측정 줄: 대응 없는 funcbytes, 원본에만·객체에만 있는 함수 목록, 자료 기호별 비교, 정의 이름 22 대조). 더해 `-M` 에 `mon/tftp.h`·`netinet/ip.h` 가 없음을 확인(§585.1).
판정(미리 정함; 07 은 바꾸지 않음): 컴파일이 안 되면 첫 오류의 원인을 적고 최소 진단 고침(A3…)으로 다시 — 고침은 모두 진단 표시, 결과에 근거를 적음. 컴파일되면 함수별 같음/다름과 차이를 적고 다음 계획을 세움.
관문: 종료 0(진단 고침 뒤), i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 586.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 명세는 §584 것에서 `plan`·`base`·`basis` 번호만 다름; 새 바탕에 `tftp.h`·`bootp.h` 없음, `ip.h` 로 가는 길 없음 | 명세 생성 스크립트(이번 세션), §585.2 의 매니페스트 비교 | ✅ (`-M` 확인은 run 에서) |
| 다음 확정 오류는 찾지 못함(이름 제공처를 읽음); `vm_map_find`(873·917 행)는 선언이 닿지 않으나 암묵 선언으로 넘어갈 수 있음 — 미정의 기호로 볼 것 | — | ⏭️ 컴파일 결과와 미정의 대조로 |
| 610·629 행 경고는 남음; 도구 `commands_ok` 는 경고만으로 거짓이 됨 — 컴파일 실패와 구분할 것 | §574.2 등에서 같은 현상 | ✅ 결과에 구분해 적음 |

### 586.2 결과(run `m4p586-p1`, 2026-10-30)

- A2: 컴파일 종료 0, 경고 둘(610·629 행 `thread_wakeup_prim`·`thread_sleep` 첫 인자 — §584 와 같음; 도구 `commands_ok` 는 이 경고 때문에 거짓이며 컴파일 실패가 아님), i386 0, `-M` 183 파일에 `tftp.h`·`netinet` 없음. 기록 `09_validation/reconstruction/m4-m68k-probe-p586-20261030.json`.
- 섹션: `__text` 5332 B(원본 구간 5080, python 차 252), `__data` 20 B(`nbuf` 0·`bufpages` 0·`nrnode` 0·`nsoftint` 100·`waittime` -1 — 원본 [0x40b2b82, 0x40b2b92) 16 B 는 `nbuf`·`nmfsbuf`·`bufpages` 0·`nsoftint` 50, `nrnode`·`waittime` 은 원본에서 다른 자리), `__cstring` 1002 B. COMMON 55 개 가운데 `_scr1` 만 원본에 없음(진단 `next/scr.h` 사본 — §505·§507 과 같음). 원본에 없는 미정의: `_callfree`·`_us_callfree`·`_us_callout`(원본은 `_ns_callout*`).
- 이름: 객체에만 `_boot`·`_kill_tasks`·`_physstrat`·`_setregs`·`_unmount_all`, 원본에만 `_callout_dispatch`·`_callout_remove`·`_kernel_thread_noblock`(와 0x4093792).
- 함수별(`m4-m68k-funcbytes-p586-A2-20261030.json`): 8/23 같음 — `mon_boot`, `nmi_prf`, `softint_th`, `sendsig`(TRACE_AST 덩이를 뺀 꼴 그대로 같음), `sigreturn`, `halt_cpu`, `light_on`, `light_off`. `as_tune` 은 길이 같고 31 바이트 다름. 길이가 다른 것(원본/A2): `mon_call` 48/24, `halt_thread` 30/24, `reboot_mach` 70/64, `nmi` 330/114, `mini_mon` 1236/1120, `softint_sched` 26/342(원본은 짧은 감싸개 — `callout_dispatch` 로 옮긴 것으로 보임), `softint_run` 386/306, `startup_early` 304/246, `startup` 1062/1190, `addupc` 156/138.
- 판단: 1997 `machdep.c` 는 softint 를 `callout_dispatch`/`callout_remove` 로 바꾸고 `nmi`·`mini_mon`·`startup` 등을 크게 고친 판임. 남은 일은 함수 묶음별로 원본 바이트에서 1997 꼴을 읽어 진단하는 것(작은 것부터: `mon_call`·`halt_thread`·`reboot_mach`·`as_tune`·`addupc`, 그다음 softint/callout 묶음, `nmi`·`mini_mon`, `startup_early`·`startup`), 자료 묶음(`nmfsbuf` 새로, `nsoftint` 50, `nrnode`·`waittime` 은 다른 객체)도 함께 정함.

## 587. M4-93 세부 계획 — `machdep.c` 작은 함수 다섯의 1997 꼴 진단 B1(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; 원본 목록, A2 목록 `08_build/artifacts/m4p561/otool/machdep_A2.txt`(실기 `otool -tv`), 스테이지 머리):
- `mon_call`([0x4093762, 0x4093792) 48 B): `action` 을 d2 에 받고 `adb_watchdog(0)`(0x4064792), `boot_action = action`(0x40b564c), `trap #13`, `adb_watchdog(1)` — NeXTMach 의 `asm("movl _boot_action, d0")` 없음, `adb_watchdog` 두 호출이 더해짐.
- `halt_thread`(0x40937c8 30 B): `boot(1, reboot_how, "")` — 셋째 인자 `pea 0x40a62e7`(빈 문자열, 원본 `__cstring`); `reboot_mach`(0x40937e6 70 B): `kernel_task` 가 있으면 `reboot_how = how; kernel_thread_noblock(kernel_task, halt_thread)`, 없으면 `boot(1, how | 4, "")`(`RB_NOSYNC` 4). NeXTMach 의 `boot` 정의는 인자 셋(`machdep.c:1210`)이나 이 두 호출자는 둘만 넘김.
- `as_tune`(0x4094758 102 B): `mg->mg_seq`(+0x30c)를 `cmpw #0x3b; ble` 로 봄 → `mg_seq >= 60`(python 0x3b+1 = 60; NeXTMach 46), 그다음 `mg_as_tune`(+0x3aa) 검사, 그 안에서만 `splhigh()`(sr 0x2700)·호출·`splx` — NeXTMach 은 `splhigh` 를 조건 밖에서 함. 뒤의 `timeout(as_tune, calls, astune_rate*hz)` 는 같은 꼴.
- `addupc`([0x40949e0, 0x4094a7c) 156 B): `pr` 목록을 +4 로 따라 돎(`movel a0@(0x4),a0`), 칸 +8·+0xc·+0x10·+0x14 = 1997 `struct uuprof`(스테이지 `sys/user.h:190–199`, `NeXT` 일 때 `pr_next` 가 더해진 배치)의 `pr_base`·`pr_size`·`pr_off`·`pr_scale`; 맞는 버퍼 하나에서 `copyin`/`copyout` 뒤 끝냄, `copyin` 실패면 첫 버퍼(인자 `pr`, a3)의 `pr_scale = 0` — 07 x86 `machdep/i386/machdep.c:162–186`(plan 241, 원본 x86 바이트로 쓴 1997 꼴)과 같은 꼴.
방법(진단; 명세 `08_build/artifacts/m4p587/spec.json`(§586 과 같은 바탕·구간), run `m4p587-p1`; scratchpad `gen_p587.py`):
- 변형 B1(`machdep_B1.c`, SHA-256 `79076180…`): A2 + 다섯 바뀜(진단 표시): `mon_call`(위 꼴), `halt_thread`·`reboot_mach`(`boot` 셋째 인자 `""`), `as_tune`(`>= 60`, `splhigh` 를 조건 안으로), `addupc`(07 x86 글 그대로).
- 측정: §586 과 같음(funcbytes 대응 없이, 함수별 같음/다름); 이 다섯 함수가 같아지는지와 다른 함수가 A2 와 그대로인지(같았던 여덟이 그대로 같은지).
판정(미리 정함; 07 은 바꾸지 않음): 다섯이 원본과 같으면 그 꼴을 남은 진단의 바탕으로 씀; 다르면 차이를 읽고 다음 진단. 남은 함수(`nmi`·`mini_mon`·softint/callout·`startup*`)는 다음 계획.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 587.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 다섯 함수 모두 B1 글이 원본 바이트를 낼 만함(레지스터는 컴파일로 확인); `mon_call` 의 `lea …,a2; jsr a2@` 재사용, `splx` 의 `movew sr,d0` 은 매크로 몫 | 원본 다섯 함수 목록을 읽음(이번 세션) | ⏭️ 진단 바이트로 확인 |
| `RB_BOOT` 1·`RB_NOSYNC` 4, 0x40a62e7 은 빈 문자열 | §580 에서 0x40a62e7 문자열을 python 으로 읽음(`b''`) | ✅ (값은 컴파일로) |
| `struct uuprof` 오프셋 +4/+8/+0xc/+0x10/+0x14, `copyin` 실패 때 대상은 인자 `pr`(a3) | 스테이지 `sys/user.h:190–199` 를 엶(이번 세션) | ✅ |
| B1 의 바뀜은 다섯 함수뿐; `boot` 정의는 이미 인자 셋(1219–1221 행) | A2→B1 diff(이번 세션) | ✅ |
| "NeXTMach `boot` 은 인자 둘" 은 틀림 — 정의(`machdep.c:1210`)는 셋, 호출자가 둘을 넘김 | NeXTMach `machdep.c:1210–1212` 를 엶 | ✅ 제 오기. 사실 줄 고침 |

### 587.2 결과(run `m4p587-p1`, 2026-10-30)

- B1(`79076180…`): 종료 0, 경고 둘(611·630 행, A2 와 같은 두 경고 — 줄은 하나씩 밀림), i386 0. 기록 `09_validation/reconstruction/m4-m68k-probe-p587-20261030.json`.
- 함수별(`m4-m68k-funcbytes-p587-B1-20261030.json`): 13/23 같음 — §586 의 여덟에 `mon_call`·`halt_thread`·`reboot_mach`·`as_tune`·`addupc` 다섯이 더해짐(판정: 다섯 꼴을 남은 진단의 바탕으로 씀). 남은 열: 원본에만 있는 `kernel_thread_noblock`·0x4093792·`callout_dispatch`·`callout_remove`, 길이가 다른 `nmi` 330/114·`mini_mon` 1236/1120·`softint_sched` 26/342·`softint_run` 386/306·`startup_early` 304/246·`startup` 1062/1190; 객체에만 `boot`·`kill_tasks`·`physstrat`·`setregs`·`unmount_all`.
- 다음: softint/callout 묶음(`kernel_thread_noblock`·0x4093792·`softint_sched`·`callout_dispatch`·`callout_remove`·`softint_run`, `__data` 의 `nsoftint`·`nmfsbuf`)을 원본에서 읽어 진단 B2 를 계획함.

## 588. M4-94 세부 계획 — `machdep.c` softint/callout 묶음의 1997 꼴 진단 B2(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; 원본 목록 0x4093792–0x40937c6·0x4093e66–0x4094200, 원본 `__cstring`·분기표를 python 으로 읽음, 스테이지 `sys/callout.h:55–61`(`CALLOUT_PRI_SOFTINT0` 0 … `CALLOUT_PRI_NOW` 5, `N_CALLOUT_PRI` 6), `kern/thread.h:311–312`(`kernel_thread`·`kernel_thread_noblock` 옛 선언)):
- 0x4093792(26 B, 이름 없음): `kernel_thread(kernel_task, arg, 0)`; `kernel_thread_noblock`(0x40937ac 28 B): `callout_dispatch(4, 0x4093792, start)`(task 인자는 쓰지 않음).
- `softint_sched`(0x4093e66 26 B): 인자 셋을 그대로 `callout_dispatch` 에 넘김.
- `callout_dispatch`(0x4093e80 312 B) = NeXTMach `softint_sched` 몸: `level` 무부호 비교 `> 5` 면 `printf("callout_dispatch(%d, 0x%x, %d)\n", …)`(0x40ac6f0)·`panic("callout_dispatch")`(0x40ac710); `level == 5` 면 바로 호출; `spldma`(sr 0x2600); 중복 검사; `softint_free` 없으면 `panic("out of softints")`(0x40ac721); 꼬리 붙이기·`RETRACE` 면 `vidInterruptEnable(softint_run, 2)`; `switch` — 0·1 `*scr2 |= (level+1)<<24`, 3 `P_DSP` `icr |= 2`(`slot_id_bmap + 0x2008000`), 4 는 `curipl()` 검사 없이 `callout_dispatch(0, thread_wakeup, softint_thread)`(자기 호출, 0x4093fa4).
- `callout_remove`(0x4093fb8 134 B, 새): `spldma` 아래 단계 0–5 의 목록에서 `si_proc == proc && si_arg == arg` 인 칸을 찾아 떼고(머리면 `*head = next`·이전 칸 0, 아니면 이전 칸에 이음; `*tail == si` 면 `*tail = 이전 칸`), `softint_free` 에 돌려주고 1 을 돌려줌; 없으면 0.
- `softint_th`(0x409403e)는 §586 에서 이미 같음.
- `softint_run`(0x4094080 386 B): `nmi_big` 이면 `callout_dispatch(4, km_big, 0)`; 분기표(0x40940c4, python: 0·1 → 0x40940d8, 2 → 0x4094150, 3·4 → 0x40940fc). 0·1 은 `scr2` ack 뒤 큐 고리로, 3·4 는 큐 고리(NeXTMach 와 같은 꼴). 2(RETRACE)는 새 꼴: `head`·`tail` 주소를 먼저 구하고 `spldma` 아래에서 목록 전체를 떼어(`lhead = *head; ltail = *tail; *tail = 0; *head = 0`), 각 칸을 부르고 0 을 돌려준 칸은 떼어 `softint_free` 로(떼는 칸이 첫 칸이면 `lhead` 를 옮기고 비면 `ltail = 0`, 아니면 이전 칸에 잇고 `ltail` 을 고침), 끝에 `spldma` 아래에서 `*head` 가 비었으면 `*head = lhead; *tail = ltail`, 아니면 `ltail->si_next = *head; *head = lhead`.
방법(진단; 명세 `08_build/artifacts/m4p588/spec.json`, run `m4p588-p1`; scratchpad `gen_p588.py`):
- 변형 B2(`machdep_B2.c`, SHA-256 `e2110f3d…`): B1 + 위 꼴(진단 표시): `mon_call` 뒤에 도움 함수(진단 이름 `knb_start`, 원본에 이름 없는 정적)와 `kernel_thread_noblock`; `softint_sched` 감싸개와 NeXTMach 몸을 옮긴 `callout_dispatch`(문자열 두 줄, `THREAD` 갈래); 그 뒤 `callout_remove`; `softint_run` 의 `nmi_big` 호출과 RETRACE 갈래. 진단 소스의 표시 주석이 모두 주석 안에 있음을 python 으로 확인함(처음 생성본의 한 줄을 고침).
- 측정: §587 과 같음(funcbytes `0x4093792` 는 객체 이름 `_knb_start` 에 대응 `4093792=_knb_start`), 함수별 같음/다름; §587 에서 같던 열셋이 그대로인지.
판정(미리 정함; 07 은 바꾸지 않음): 새로 같아진 함수의 꼴을 다음 진단의 바탕으로 씀; 다른 것은 차이를 읽어 다음 진단. 남은 것은 `nmi`·`mini_mon`·`startup*`·자료와 객체에만 있는 함수.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 588.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 여섯 함수 모두 문장 차례·제어 흐름이 원본과 맞음; 레지스터 배정은 컴파일로 확인할 것(`callout_remove` 의 head/tail 주소 계산 차례, 아래쪽 `level <= 5` 검사, RETRACE 의 `lhead` 첫 검사와 0x409418c 의 a0 넘김) | 원본 0x4093792–0x4094200 을 읽음(이번 세션) | ⏭️ 진단 바이트로 |
| `level` 무부호 검사는 B1 의 NeXTMach 식이 이미 같은 바이트(`7a05ba826422`)로 컴파일됨 | — | ⏭️ (B2 결과로 같이 봄) |
| 표시 주석은 모두 닫혀 있고 `int km_big();` 은 C89 블록 선언으로 됨; `knb_start` 의 형은 `callout.h:33` 의 `func` 와 다르나 옛 선언 호출이라 진단되지 않음 | 표시 줄 python 검사(이번 세션) | ✅ |
| §588 의 수·주소는 맞음; 도움 함수가 `static` 이었다는 것은 바이트가 정하지 않음 | 원본 기호표에 0x4093792 기호 0 개(이번 세션 grep) | ⚖️ 바깥 기호가 없으므로 링크 단위 밖에 이름이 없는 함수(`static`)로 봄 — 계획 문구는 그대로 |

### 588.2 결과(run `m4p588-p1`, 2026-10-30)

- B2(`e2110f3d…`): 종료 0, 경고 하나(684 행 `thread_sleep` 첫 인자 — `softint_sched` 의 `thread_wakeup_prim` 경고는 THREAD 갈래가 바뀌어 없어짐), i386 0. 기록 `09_validation/reconstruction/m4-m68k-probe-p588-20261030.json`.
- 함수별(`m4-m68k-funcbytes-p588-B2-20261030.json`, 대응 `4093792=_knb_start`): 18/23 같음 — §587 의 열셋에 `knb_start`·`kernel_thread_noblock`·`softint_sched`·`callout_dispatch`·`callout_remove` 다섯이 더해짐. `softint_run` 은 길이가 같고 2 바이트(+0x124) 다름: 실기 `otool -tv`(`m4p561/otool/machdep_B2.txt`) 대조로 원본 0x40941a4 `cmpl a4,a2` 대 B2 `cmpl a2,a4` — RETRACE 의 `if (si == ltail)` 비교 피연산자 차례(분기표 다섯 낱말은 재배치로 같은 대상). 남은 다른 것: `nmi`·`mini_mon`·`startup_early`·`startup`.

## 589. M4-95 세부 계획 — `softint_run` 비교 차례 진단 B3(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p589/spec.json`, run `m4p589-p1`): B3(`machdep_B3.c`, SHA-256 `43816312…`) = B2 에서 RETRACE 의 `if (si == ltail)` 를 `if (ltail == si)` 로만 바꿈(진단 표시). 측정: §588 과 같음. 판정(미리 정함): `softint_run` 이 같고 다른 열여덟이 그대로면 B3 꼴을 바탕으로 씀; 아니면 차이를 적고 다음 진단.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 589.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 재배치를 맞춘 뒤의 차이는 +0x124 의 `cmpl` 하나(원본 `b5cc`, B2 `b9ca`); 날 바이트 차이 74 는 재배치 칸 | funcbytes 기록 `byte_differences` 2·`refs_differ` 빔, 목록 diff(이번 세션) | ✅ "2 바이트" 는 재배치를 맞춘 뒤의 수로 읽음 |
| 피연산자를 바꾸면 차례가 바뀔 수 있으나 보장은 없음 — 전체 출력으로 확인 | — | ⏭️ 진단으로 |
| B3 = B2 + 그 한 줄, 명세 일치, SHA 앞자리 맞음 | diff(이번 세션) | ✅ |

### 589.2 결과(run `m4p589-p1`, 2026-10-30)

- B3(`43816312…`): 종료 0, i386 0, 경고는 B2 와 같은 하나. 기록 `09_validation/reconstruction/m4-m68k-probe-p589-20261030.json`.
- 함수별(`m4-m68k-funcbytes-p589-B3-20261030.json`): 19/23 같음 — `softint_run` 이 같아짐(`ltail == si` 꼴), 다른 열여덟 그대로. 남은 넷: `nmi` 330/114, `mini_mon` 1236/1120, `startup_early` 304/246, `startup` 1062/1190; 객체에만 `boot`·`kill_tasks`·`physstrat`·`setregs`·`unmount_all`; 자료(`nmfsbuf`·`nsoftint` 50, `nrnode`·`waittime` 은 다른 객체).
- 다음: `nmi`·`mini_mon` 묶음(진단 B4)을 원본에서 읽어 계획함.

## 590. M4-96 세부 계획 — `machdep.c` `nmi` 의 1997 꼴 진단 B4(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; 원본 [0x409382c, 0x4093976) 330 B 를 읽음, 원본 `__cstring` 을 python 으로 읽음, B2 목록의 `_nmi`(NeXTMach 꼴 114 B), NeXTMach `next/cpu.h:188·221`):
- 처음에 `mon = P_MON`(`slot_id + 0x200e000`)을 구하고 두 지역 플래그(d3·d4)를 0 으로 둠.
- `dma_chip != 313` 이고 `*(SLOT_ID + 0x02200020)` 의 비트 0 이 켜져 있으면 그 낱말을 0 으로 쓰고 첫 플래그(미니 모니터)를 켬(0x4093846–0x4093866); 아니면 NeXTMach 의 키보드 판정(`ke.data = mon->mon_km_data`, `km_clr_nmi = 1`, `up_down` 이 1 이 아니면 command 두 키 → 첫 플래그, command_left 가 0 → 둘째 플래그(재시작)) — B2 의 NeXTMach 식이 같은 명령(`tstb`·`bfextu d0{#16,#8}`·`andb #0x18`·`btst #3`)을 냄.
- 이어서 `dma_chip != 313` 이고 `*intrstat` 의 비트 30(NeXTMach `I_PFAIL` = `I(7,1,30)`)이면: `*(SLOT_ID + 0x02200004) = 0` 두 번, `simm = (*(SLOT_ID + 0x02200008) − P_MAINMEM) / (0x8000000 / num_regions)`(`divsl` 로 나누는 수, `divul` 로 몫 — 무부호), `printf("parity error at address 0x%x, SIMM memory sockets %d and %d (%s)\n", *(SLOT_ID + 0x02200008), simm & ~1, (simm & ~1) | 1, simm & 1 ? "back" : "front")`(0x40ac3e9; 주소 낱말을 다시 읽음), `panic("parity error")`(0x40ac42b). `P_MAINMEM` = `SLOT_ID + 0x04000000`(NeXTMach `cpu.h:188`).
- 끝에 첫 플래그면 `mini_mon("nmi", "NMI Mini-Monitor (type \"?\" for help)", ksp, usp, isp, pc, sr)`, 아니고 둘째면 `mini_mon("restart", "Restart/Power-Off")`.
- 0x02200004·0x02200008·0x02200020 은 NeXTMach·SDK 머리에 이름이 없음(grep 0) — 진단에서는 숫자로 쓰고, 07 에서의 이름은 나중에 사용자 결정.
방법(진단; 명세 `08_build/artifacts/m4p590/spec.json`, run `m4p590-p1`; scratchpad `gen_p590.py`): B4(`machdep_B4.c`, SHA-256 `7e8a2edc…`; §590.1 에서 고쳐 다시 만듦) = B3 에서 `nmi` 몸만 위 꼴로 바꿈(지역 `do_mon`·`do_restart`, 함수 안 `extern int *intrstat;` — 같은 파일 `mini_mon` 의 NeXTMach 선언과 같은 꼴, 비트는 `I_BIT(I(7,1,30))`). 측정: §589 와 같음. 판정(미리 정함): `nmi` 가 같고 다른 열아홉이 그대로면 바탕으로 씀; 아니면 차이를 적고 다음 진단. 다음은 `mini_mon`.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 590.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 수·SHA·문자열·상수(`P_MON`·`P_MAINMEM`·`I(7,1,30)` = 0x40000000)는 맞음 | §590 의 python 문자열 읽기(이번 세션), NeXTMach `cpu.h:153·188·213·221` | ✅ |
| 처음 계산 차례·`dma_chip` 두 번 읽기·`slot_id` 다시 읽기·`printf` 인자 계산·저장 레지스터(d2–d5/a2)는 C 가 강제하지 않음 — 컴파일로 확인 | — | ⏭️ 진단 바이트로 |
| 나눗셈 부호(`divsl` 뒤 `divul`)와 레지스터 읽기·쓰기 횟수는 C 와 맞음 | 원본 0x40938b8–0x409390a 읽음 | ✅ |
| `nmi` 의 `extern volatile int *intrstat;` 는 같은 파일 `mini_mon` 의 `extern int *intrstat;`(306 행)와 형이 어긋남 | B4 grep(267·306 행) | ✅ 제 오류. `nmi` 도 `extern int *intrstat;` 로 고쳐 B4 를 다시 만듦(`549f1d5f…` → `7e8a2edc…`) |
| `union kybd_event`·`struct monitor` 칸, `u_int` 은 스테이지에 있음 | — | ⏭️ 컴파일로 |

### 590.2 결과(run `m4p590-p1`, 2026-10-30)

- B4(`7e8a2edc…`): 종료 0, 경고 하나(704 행, 앞과 같은 `thread_sleep`), i386 0. 기록 `09_validation/reconstruction/m4-m68k-probe-p590-20261030.json`. 함수별(`m4-m68k-funcbytes-p590-B4-20261030.json`): 19/23 그대로, `nmi` 는 원본 330 대 B4 326 B.
- 실기 `otool -tv`(`m4p561/otool/machdep_B4.txt`)로 본 `nmi` 의 차이 둘: (1) 원본 0x40938a4 `movel a0@,d0; btst #30,d0`(낱말 전체를 읽음) 대 B4 `btst #6,a0@`(바이트 하나) — `*intrstat` 를 volatile 로 읽은 꼴로 보임; 원본 `mini_mon` 은 같은 변수를 0x4093af6 `btst #2,a0@(0x3)` 로 읽으므로 `nmi` 에서만 volatile. (2) 원본은 `0x2200008` 을 a2 에 두고(0x40938c0) `P_MAINMEM` 을 `movel #0x4000000,a0; addal a1,a0` 로 만든 뒤 `subl a0,d0` 로 뺌; B4 는 `addl #0xfc000000,d0; subl a1,d0` 로 상수를 접음.

## 591. M4-97 세부 계획 — `nmi` 의 남은 두 차이 진단 B5(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p591/spec.json`, run `m4p591-p1`; scratchpad `gen_p591.py`; 모두 B4 에서 `nmi` 의 한두 줄만 바꿈, 진단 표시):
- B5A(`1b308971…`): `nmi` 의 함수 안 선언을 `extern volatile int *intrstat;` 로(같은 파일 `mini_mon` 의 `extern int *intrstat;` 와 형이 다른 블록 선언 — §590.1 의 codex 지적; GCC 2.7 이 받는지와 경고를 봄).
- B5B(`a7380d11…`): 선언은 그대로 두고 검사만 `*(volatile int *)intrstat & …`.
- B5C(`30ef476b…`): B5A + 빼기를 `(u_int)((caddr_t)*(volatile u_int *)(… 0x02200008) − (caddr_t)(SLOT_ID + 0x04000000))`.
- B5D(`93b352ec…`): B5A + `… − (u_int)(caddr_t)(SLOT_ID + 0x04000000)`.
- B5E(`2e20064b…`): B5A + 지역 `caddr_t mainmem = (caddr_t)(SLOT_ID + 0x04000000);`(선언 때) 를 빼는 꼴.
- B5F(§591.1 에서 더함): B5B + 빼기를 포인터 산술로 `(u_int)(*(volatile caddr_t *)(SLOT_ID + 0x02200008) − ((caddr_t)0x04000000 + SLOT_ID))`.
- 측정: 변형마다 종료 코드·경고, `m68k_funcbytes.py`(대응 `4093792=_knb_start`), `nmi` 의 목록 대조.
판정(미리 정함; 07 은 바꾸지 않음): `nmi` 가 원본과 같은 변형이 있으면 그 꼴을 바탕으로 씀(같은 결과의 꼴이 여럿이면 07 단계에서 사용자 결정); 없으면 차이를 적고 다음 진단. 형이 다른 블록 선언(B5A 꼴)이 컴파일되지 않으면 그 사실을 적음.
관문: 종료 0(B5A 계열은 컴파일 여부 자체가 측정), i386 0, 옵션 = M5 줄; 경고는 기록.

### 591.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 590.2 의 두 차이는 맞고, 그에 딸려 `printf` 의 다시 읽기도 원본 a2·B4 a0 으로 다름; 다른 차이는 없음 | B4 목록 diff(이번 세션: 0x409390a 대 0x262) | ✅ |
| "`nmi` 에서만 volatile" 은 추정 — 원본 선언은 바이트로 정해지지 않음 | — | ✅ 추정으로 읽음(판정에 쓰지 않음) |
| B5A/C/D/E 의 블록 선언은 C89 에서 서로 맞지 않는 형(정의되지 않은 동작); GCC 2.7 은 경고하고 받을 것 — 컴파일로 확인 | — | ⏭️ 진단으로 |
| B5D·B5E 는 접힘이 남을 것, B5C 는 해 볼 만함; B5B 바탕의 포인터 산술 꼴(`(caddr_t)0x04000000 + SLOT_ID`)을 더할 것 | — | ✅ B5F 를 더함(SHA `3327ada8…`), 나머지는 ⏭️ |
| 수·SHA·명세 맞음 | — | ✅ |

### 591.2 결과(run `m4p591-p1`, 2026-10-30)

- 여섯 변형 모두 종료 0, i386 0. B5A·B5C·B5D·B5E 는 경고 둘이 더해짐: `mini_mon` 306(B5E 307) 행 "type mismatch with previous external decl" 과 267 행 "previous external decl of `intrstat'" — GCC 2.7 은 형이 다른 블록 선언을 경고만 하고 받음(§591.1 의 예측과 같음). B5B·B5F 는 앞과 같은 경고 하나. 기록 `09_validation/reconstruction/m4-m68k-probe-p591-20261030.json`.
- 함수별(`m4-m68k-funcbytes-p591-B5?-20261030.json`): 모두 19/23; `nmi` 는 B5A·B5B·B5C·B5D·B5F 가 328 B(volatile 읽기로 `movel a0@,d0; btst #30,d0` 가 원본과 같아지며 2 B 늘어남), B5E 가 330 B 이나 32 B 다름.
- 목록(`m4p561/otool/machdep_B5E.txt`·`machdep_B5F.txt`): B5F 는 B4 와 같은 상수 접기(`addl #0xfc000000`), B5E 는 원본처럼 `movel #0x4000000,a1; addal a2,a1` 로 기준을 만들고 `subl a1,d0` 로 빼지만 그 계산이 두 번의 0 쓰기 앞에 놓여(지역 초기값) 레지스터가 바뀜 — 원본은 두 쓰기와 `movel #0x2200008,a2` 뒤에 기준을 만듦.

## 592. M4-98 세부 계획 — `nmi` 기준 주소 계산 위치 진단 B6(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p592/spec.json`, run `m4p592-p1`): 지역 `caddr_t mainmem;`(초기값 없음)을 두고 두 번의 0 쓰기 뒤에 `mainmem = (caddr_t)(SLOT_ID + 0x04000000);` 한 뒤 `simm = (*(volatile u_int *)(… 0x02200008) − (u_int)mainmem) / (0x08000000 / num_regions)`(진단 표시). 변형 둘:
- B6A(`6b91b292…`): B5B 바탕(`*(volatile int *)intrstat` 꼴, 블록 선언 충돌 없음).
- B6B(`976f22a0…`): B5A 바탕(블록 `extern volatile int *intrstat;`, 경고는 둘 더해 모두 셋).
- B6C(`86e28208…`, §592.1 에서 더함): B6A 에서 레지스터 값을 먼저 `simm` 에 읽고 그다음 `mainmem` 을 구해 `simm = (simm − (u_int)mainmem) / …`.
측정: §591 과 같음. 판정(미리 정함): `nmi` 가 같아진 변형이 있으면 바탕으로 씀(둘 다 같으면 07 단계에서 사용자 결정); 아니면 차이를 적고 다음 진단.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 592.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 591.2 의 경고(B5A/C/D/E 는 모두 셋)·크기·B5E 레지스터 이야기 맞음; `commands_ok` 거짓은 경고 때문 | 기록·목록(이번 세션) | ✅ B6B 경고 문구 고침 |
| 대입을 옮겨도 원본 차례가 보장되지는 않음; 값을 먼저 읽는 꼴이나 오류 레지스터 포인터 꼴을 따로 시험할 만함 | — | ✅ B6C(값 먼저)를 더함; 포인터 꼴은 결과를 보고 |
| 해시·명세 일치 | — | ✅ |

### 592.2 결과(run `m4p592-p1`, 2026-10-30)

- 셋 모두 종료 0, i386 0(B6B 는 블록 선언 경고 둘이 더해짐). 기록 `09_validation/reconstruction/m4-m68k-probe-p592-20261030.json`. 모두 19/23, `nmi` 는 셋 다 330 B: B6A·B6B 12 B 다름, B6C 10 B 다름(`m4-m68k-funcbytes-p592-B6?-20261030.json`).
- 목록(`m4p561/otool/machdep_B6A.txt`·`machdep_B6C.txt`): B6A 는 원본과 명령이 모두 같고 `movel #0x2200008,a2` 하나의 자리만 다름(원본은 `mainmem` 계산 앞, 0x40938c0; B6A 는 뒤); B6C 는 레지스터 값 읽기 `movel a2@(a1),d0` 가 `mainmem` 계산 앞에 놓임(원본은 뒤, 0x40938ce). 원본 차례: 오류 레지스터 상수 → `mainmem` → 값 읽기 → 빼기.

## 593. M4-99 세부 계획 — `nmi` 명령 차례 진단 B7(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p593/spec.json`, run `m4p593-p1`; 바탕 B6A, 진단 표시):
- B7A(`bab0fc65…`): `simm = (*(volatile u_int *)(SLOT_ID + 0x02200008) − (u_int)(mainmem = (caddr_t)(SLOT_ID + 0x04000000))) / …` — 대입을 식 안으로.
- B7B(`192033ff…`): `mainmem` 대입 뒤 `simm = (u_int)((caddr_t)*(volatile u_int *)(… 0x02200008) − mainmem) / …`(포인터 빼기).
- B7C(`6a9b7bfe…`): 지역 `volatile u_int *perr = (volatile u_int *)0x02200008`(상수 바탕)을 `mainmem` 앞에 두고 두 읽기를 `*(volatile u_int *)((caddr_t)perr + SLOT_ID)` 로.
측정·판정·관문: §592 와 같음.

### 593.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 592.2 의 읽기 맞음(재배치를 가린 비교에서 B6A 는 상수 자리, B6C 는 값 읽기 자리만 다름) | B6A·B6C 목록 diff(이번 세션) | ✅ |
| B7A 는 이른 값 읽기 위험, B7B 는 B6A 와 비슷할 것, B7C 가 가장 겨냥한 꼴이나 상수 전파로 사라질 수 있음 — 예측일 뿐 | — | ⏭️ 진단으로 |
| B7C 는 새 컴파일 문제 없음; 더 깔끔한 꼴로 `perr = (volatile u_int *)(SLOT_ID + 0x02200008)` 전체 주소 포인터도 있음 | — | ⏭️ 결과를 보고 |
| 해시·명세 일치 | — | ✅ |

### 593.2 결과(run `m4p593-p1`, 2026-10-30)

- 셋 모두 종료 0, i386 0, 경고는 앞과 같은 하나. 기록 `09_validation/reconstruction/m4-m68k-probe-p593-20261030.json`.
- 함수별(`m4-m68k-funcbytes-p593-B7?-20261030.json`): B7A·B7C 는 20/23 — `nmi` 가 원본과 같음; B7B 는 19/23(`nmi` 12 B 다름, B6A 와 같은 꼴 — 예측대로).
- 따라서 1997 `nmi` 의 바이트를 내는 꼴은 둘 이상(§591–593): `*intrstat` 를 volatile 로 읽기(캐스트 꼴 — 블록 선언 꼴은 같은 바이트를 내되 경고 둘), 기준 주소를 식 안 대입(B7A) 또는 상수 바탕 포인터 `perr`(B7C)로 둠(B7A·B7C 객체는 canon 같고 `obj_sig` 는 다름 — `perr` 변수의 STABS, python). 07 에 쓸 꼴은 객체 전체가 맞은 뒤 사용자 결정으로 묻음(레지스터 이름 0x02200004·0x02200008·0x02200020 과 함께).
- 남은 셋: `mini_mon` 1236 대 1120, `startup_early` 304 대 246, `startup` 1062 대 1190; 자료와 객체에만 있는 함수 다섯. 다음: `mini_mon`(B8).

## 594. M4-100 세부 계획 — `machdep.c` `mini_mon` 의 1997 꼴 진단 B8(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; 원본 [0x4093976, 0x4093e4a) 1236 B 를 모두 읽음, 원본 문자열을 python 으로 읽음, B7A 목록과의 diff `scratchpad/minimon_diff.txt`):
- 처음: `restart`(d2)·`panic`(d6) 다음 새 플래그(d5) = `cdevsw[major(cons_tp->t_dev)].d_open == zsopen`(`cons_tp`+0x38 의 높은 바이트, `cdevsw` 0x40b0ac0 의 44 B 칸 첫 낱말을 0x408b300 `_zsopen` 과 비교, 0x40939ca–0x40939f6).
- 팝업 조건에 `&& !serial` 이 더해짐(0x40939f8–0x4093a10). `panic` 갈래는 `strcmp` 대신 `panic` 플래그(d6)를 보고, `kmioctl(0, KMIOCDUMPLOG, 0, 0)` 뒤 `RB_DEBUG`(ksp 비트 18)가 없으면 레지스터만 되돌리고 나감(0x4093e40, `splx` 없음 — NeXTMach `return` 과 같음), 있으면 `printf("\n")`(0x400b358).
- 그 뒤 `adb_watchdog(0)`(0x4093a7c), 끝(`resynctime` 뒤, `splx` 앞)에 `adb_watchdog(1)`(0x4093e30).
- 두 입력 고리에서 문자는 `serial ? zstrygetc(cons_tp->t_dev) : kmtrygetc()`(0x4093aa4–0x4093ac4, 0x4093bc8–0x4093be8).
- 명령 고리: `kdbg_connect(1)`(인자 1, 0x4093bea); 줄바꿈이면 `nmi_prf("\n")` 뒤 `line[0] = 0`(0x4093c1e); 도움말 첫 문자열에 `"\tkdb_ipaddr=n - set default ip address\n"` 이 `gdb` 줄 뒤에 더해짐(0x40ac4f2; 둘째 문자열 0x40ac571 은 NeXTMach 과 같은 글); gdb 갈래는 `trap #15`(0x4093b2a; NeXTMach `trap #14`).
- 나머지(`nmi_big`·`nmi_cont`·`nmi_mon`·`nmi_halt`·`nmi_reboot`·`nmi_msg` 갈래와 `out:`)는 NeXTMach 차례와 같음.
방법(진단; 명세 `08_build/artifacts/m4p594/spec.json`, run `m4p594-p1`; scratchpad `gen_p594.py`): B8(`machdep_B8.c`, SHA-256 `ba1529d5…`) = B7A + 위 바뀜(진단 표시, 표시 줄이 모두 주석 안임을 python 으로 확인): 지역 `serial`, 함수 안 `extern int zsopen();`, 팝업 조건, `panic` 갈래, `adb_watchdog` 둘, 입력 두 곳, `kdbg_connect(1)`, `line[0] = 0`, 도움말 한 줄, `trap #15`.
- B8R(`eb6cc35c…`, §594.1 에서 더함): B8 에서 팝업 갈래의 NeXTMach `restart = 1;` 을 뺌(원본은 `restart` 를 다시 쓰지 않고 `kmpopup` 호출 하나를 함께 씀, 0x4093a16–0x4093a34).
측정: §593 과 같음. 판정(미리 정함): `mini_mon` 이 같아지면 바탕으로 씀; 아니면 차이를 적고 다음 진단. 다음: `startup_early`·`startup`.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 594.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| B8 의 `restart = 1;`(320 행)은 원본에 없는 대입 — 원본은 인자만 고르고 `kmpopup` 호출 하나를 함께 씀(0x4093a16–0x4093a34), B7A 는 `moveq #1,d2` 와 호출 둘 | 원본 0x4093a12–0x4093a3a 읽음(이번 세션) | ✅ B8R 을 더함 |
| `saved`(a4)·`s`(a5, 스택 넘김) 등 레지스터 배정은 컴파일로 확인 | — | ⏭️ |
| 그 밖(첫 차례·팝업 조건·panic 갈래·`printf`/`nmi_prf`·watchdog·입력·도움말·명령 고리·메시지 덤프·`out:`)은 원본과 맞음; `cdevsw` 44 B·`t_dev` +0x38·`KMIOCDUMPLOG` 0x20006b03·`RB_DEBUG` 0x40000 확인 | 원본 0x40939ca–0x40939f6(44 B 칸 계산) 읽음 | ✅ (값은 컴파일로) |
| §594 의 수는 맞음(watchdog·kdbg 주소는 인자 준비 자리) | — | ✅ |

### 594.2 결과(run `m4p594-p1`, 2026-10-30)

- B8·B8R: 종료 0, i386 0, 경고는 앞과 같은 하나. 기록 `09_validation/reconstruction/m4-m68k-probe-p594-20261030.json`.
- 함수별: B8 20/23(`mini_mon` 1246 B — `restart = 1` 이 남아 10 B 김), B8R 21/23 — `mini_mon` 이 원본과 같음(`m4-m68k-funcbytes-p594-B8R-20261030.json`). §594.1 의 codex 지적(직접 확인)이 맞았음.
- 남은 둘: `startup_early` 304 대 246, `startup` 1062 대 1190; 자료와 객체에만 있는 함수 다섯. 다음: `startup_early`·`startup`(B9).

## 595. M4-101 세부 계획 — `machdep.c` `startup_early` 의 1997 꼴 진단 B9(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; 원본 [0x4094202, 0x4094332) 304 B 를 읽음, 기호표, python):
- `v = firstaddr = mem_region[0].first_phys_addr`(0x40c2c40) 뒤 `valloc` 넷: `cfree`(0x40b5b38, `nclist` × 64 B), `ns_callout`(0x40c2428, `ncallout` × 24 B — 07 `kern/ns_timer.c:123–129` 의 `struct ns_callout` 크기), `softint`(0x40c9564, `nsoftint` × 12 B), `ncache`(0x40b6d70, `ncsize` × 70 B). NeXTMach 의 `callout`·`us_callout` 둘 대신 `ns_callout` 하나.
- `bufpages == 0` 이면 `mulul #0xcccccccd` 높은 낱말 `>> 4`(python: 무부호 32 비트에서 `x / 20` 과 같음, 표본 20 만 개와 경계값) → `>> page_shift`(`atop`) → `& ~1` → `bufpages`(0x40b2b8a).
- `nbuf == 0` 이면 `nbuf = bufpages`, 16 보다 작으면 16; 그 뒤 늘 `nbuf > 254` 면 254(0x40942b2). `bufpages > nbuf * (0x2000 / page_size)` 면 줄임(무부호 비교 `bcc`, NeXTMach 과 같은 꼴). `valloc(buf, struct buf, nbuf)`(0x40b58e8, 68 B) 뒤 `nmfsbuf == 0`(0x40b2b86)이면 `nmfsbuf = nbuf / 2`(부호 있는 나눗셈). 끝은 NeXTMach 과 같음(`bzero`, `first_phys_addr = v`).
방법(진단; 명세 `08_build/artifacts/m4p595/spec.json`, run `m4p595-p1`; scratchpad `gen_p595.py`): B8R 에서 `startup_early` 만 바꿈(진단 표시): 앞에 07 `ns_timer.c` 와 같은 `struct ns_callout` 정의와 `extern struct ns_callout *ns_callout; extern int nmfsbuf;`(진단 — 07 에서의 공급은 나중 결정), `valloc` 줄, `nbuf`·`nmfsbuf` 규칙. `bufpages` 식 두 꼴:
- B9A(`a5c5e757…`): `atop(mem_size / 20) & ~1`.
- B9B(`bb9096d6…`): `(atop(mem_size / 20) / 2) * 2`.
측정: §594 와 같음. 판정(미리 정함): `startup_early` 가 같아진 꼴을 바탕으로 씀; 아니면 차이를 적고 다음 진단. 다음: `startup`.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 595.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 할당 차례와 칸 크기(64/24/12/70/68), 무부호 `/20`·`atop`·`& ~1`, `nbuf` 규칙(254 는 블록 밖), 무부호 `bufpages` 비교, `nmfsbuf = nbuf / 2`, 끝 부분이 B9A 와 맞음 | 원본 0x4094202–0x4094330 을 읽음(이번 세션), python `/20` 확인 | ✅ (바이트는 진단으로) |
| `mem_size / 10 / 2` 와 `/20` 은 무부호에서 같아 바이트로 가를 수 없음; B9B 도 같은 값 | — | ✅ 같은 결과의 꼴은 07 단계에서 사용자 결정 |
| 진단 `struct ns_callout` 은 스테이지 머리와 부딪히지 않음(`func`·`ns_time_t` 보임) | — | ⏭️ 컴파일로 |
| 비교가 무부호임을 적을 것 | — | ✅ 사실 줄 고침 |

### 595.2 결과(run `m4p595-p1`, 2026-10-30)

- B9A·B9B: 종료 0, i386 0, 경고는 앞과 같은 하나(진단 `struct ns_callout` 은 문제없이 컴파일). 기록 `09_validation/reconstruction/m4-m68k-probe-p595-20261030.json`. 둘 다 21/23, `startup_early` 306 B(원본 304; B9A = B9B 같은 길이).
- 목록(`m4p561/otool/machdep_B9A.txt`): 차이는 `nbuf` 기본값 자리 하나 — 원본 0x4094298–0x40942a6 은 `bufpages` 를 d0 에 한 번 읽어 `nbuf` 에 쓰고 d0 를 16 과 비교; B9A 는 메모리에서 메모리로 옮기고(`movel bufpages,nbuf`) 메모리 `bufpages` 를 비교.

## 596. M4-102 세부 계획 — `startup_early` 의 `nbuf` 기본값 꼴 진단 B10(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p596/spec.json`, run `m4p596-p1`; 바탕 B9A, 진단 표시):
- B10A(`8bf99260…`): `if ((nbuf = bufpages) < 16) nbuf = 16;`
- B10B(`13b4d3d7…`): `nbuf = bufpages; if (bufpages < 16) nbuf = 16;`
측정·판정·관문: §595 와 같음.

### 596.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 595.2 의 읽기 맞음(유일한 명령 꼴 차이, 304 대 306 B; 원본은 `moveq #15,d2; cmpl d0,d2; blt`) | B9A 목록 diff(이번 세션) | ✅ |
| B10A 가 더 유력, B10B 는 B9A 와 같을 것; 둘 다 안 되면 지역 `register int n` 꼴 | — | ⏭️ 진단으로 |
| 해시·명세 일치; `commands_ok` 거짓은 경고 정책 때문 | — | ✅ |

### 596.2 결과(run `m4p596-p1`, 2026-10-30)

- B10A·B10B: 종료 0, i386 0, 경고는 앞과 같은 하나. 기록 `09_validation/reconstruction/m4-m68k-probe-p596-20261030.json`.
- B10A 22/23 — `startup_early` 가 원본과 같음(`if ((nbuf = bufpages) < 16)` 꼴; `m4-m68k-funcbytes-p596-B10A-20261030.json`); B10B 21/23(306 B, 예측대로).
- 남은 하나: `startup` 1062 대 1190; 자료(`nmfsbuf`·`nsoftint` 50 정의, 진단 `extern`), 객체에만 있는 함수 다섯, `struct ns_callout` 공급. 다음: `startup`(B11).

## 597. M4-103 세부 계획 — `machdep.c` `startup` 의 1997 꼴 진단 B11(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; 원본 [0x4094332, 0x4094758) 1062 B 를 모두 읽음, 원본 문자열 넷을 python 으로 읽음):
- 앞부분(`km_switch_to_vm`·`panic_init`·`printf(version)`·FPU·물리 메모리 출력, `round_page`·`vm_map_find`·`vm_map_remove`, `buffers` 할당·`base`/`residual`(`divsll`), `kmem_suballoc`·`vm_map_find`, 버퍼 고리, 두 출력)은 NeXTMach 차례와 같아 보임.
- callout 초기화: NeXTMach 의 `callout`·`us_callout` 고리 둘 대신 `bsr 0x404e3a8`(`_ns_callout_init`) 한 번(0x409464a). 그다음 softint 초기화는 같은 꼴.
- 부팅 애니메이션(0x40946c4–0x40946fc): `(km.flags & KMF_SEE_MSGS) == 0 && console_o == 0 && mg->mg_seq > 23(cmpw #0x17,a4@(0x30c); ble) && mg->mg_anim_run(a4@(0x30e))` 이면 `callout_dispatch(2, mg->mg_anim_run, 0)` — `mg` 를 입구에서 a4 에 둠(0x409433a; `mg->` 칸과 `MG()` 매크로는 둘 다 `mg` 를 쓰므로 바이트로 가르지 못함 — §597.1), `<= 99` 검사 없음, `softint_sched` 대신 `callout_dispatch`.
- 끝: `bmap_chip` 이면 `as_tune` timeout(같은 꼴), 그다음 `dma_chip != 313` 이면 `adb_initialize()`(0x4064216), `configure()`.
방법(진단; 명세 `08_build/artifacts/m4p597/spec.json`, run `m4p597-p1`; scratchpad `gen_p597.py`): B11(`machdep_B11.c`, SHA-256 `33db003b…`) = B10A 에서 `startup` 의 세 곳만 바꿈(진단 표시): callout 고리 둘 → `ns_callout_init();`, 애니메이션 조건 → `mg->mg_seq >= 24 && mg->mg_anim_run` 과 `callout_dispatch(CALLOUT_PRI_RETRACE, mg->mg_anim_run, 0)`, `configure()` 앞 `if (dma_chip != 313) adb_initialize();`.
- B11M(`822755c9…`, §597.1 에서 더함): B11 + `mb_map` 크기를 NeXTMach `ptoa(nmbclusters)` 대신 `nmbclusters * MCLBYTES`(원본 0x409469a–0x40946a2 `asll #10` — `MCLBYTES` 1024, 스테이지 `sys/mbuf.h:42`).
측정: §596 과 같음(23 함수, 객체에만 있는 함수). 판정(미리 정함): `startup` 이 같아지면 함수 23/23 — 그다음 자료·객체에만 있는 함수·이름 결정으로 감; 아니면 차이를 적고 다음 진단.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 597.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 남은 확정 차이: `mb_map` 크기 — 원본 0x409469a–0x40946a2 는 `nmbclusters << 10`, B11 은 `ptoa(nmbclusters)`(`page_shift` 변수) | 원본 그 자리를 읽음(이번 세션 목록), 스테이지 `sys/mbuf.h:40–44`(`MCLBYTES` 1024) | ✅ 제 누락. B11M 을 더함 |
| 앞부분(0x4094332–0x4094644)은 NeXTMach 꼴과 명령 모양 244 개가 같음 | — | ⏭️ 진단 바이트로 |
| `msize`·소수 계산·FPU 바이트 읽기·`firstaddr`·`size`·고리·`ns_callout_init` 자리·`as_tune` 덩이·`adb_initialize` 는 맞음 | 원본을 읽음(이번 세션) | ✅ (바이트는 진단으로) |
| 애니메이션 조건에서 `mg->` 와 `MG()` 는 바이트로 가르지 못함 — §597 의 단정은 과함 | 스테이지 `mon/global.h:43–44` 의 `MG` 가 `mg` 를 씀(§581 진단 사본에서 확인) | ✅ 사실 줄 고침 |
| `ns_callout_init`·`adb_initialize` 는 암묵 선언(진단이라 컴파일로 확인), 콜백 형은 문제없음 | — | ⏭️ |
| §597 의 수는 맞음 | — | ✅ |

### 597.2 결과(run `m4p597-p1`, 2026-10-30)

- B11·B11M: 종료 0, i386 0, 경고는 앞과 같은 하나(암묵 선언 `ns_callout_init`·`adb_initialize` 는 경고 없음). 기록 `09_validation/reconstruction/m4-m68k-probe-p597-20261030.json`.
- B11 22/23(`startup` 1066 B), B11M 23/23 — 원본 구간의 23 함수가 모두 같음(`m4-m68k-funcbytes-p597-B11M-20261030.json`, 대응 `4093792=_knb_start`). §597.1 의 codex 지적(`mb_map` 크기, 직접 확인)이 맞았음.
- 남은 것(함수 밖): 객체에만 있는 `boot`·`kill_tasks`·`physstrat`·`setregs`·`unmount_all`(원본 구간에 없음 — 1997 판에서 다른 객체로 갔거나 없어짐), 자료(원본 [0x40b2b82, 0x40b2b92) 의 `nbuf`·`nmfsbuf`·`bufpages`·`nsoftint` 50; `nrnode`·`waittime` 은 다른 자리), `__cstring`·COMMON 대조, 진단 `extern`/`struct ns_callout`·`next/scr.h`·`next/scb.h` 사본(원본에 없는 COMMON `_scr1`)의 정리. 다음: 이것들을 맞추는 진단 B12, 그다음 바이트로 가를 수 없는 꼴과 이름을 사용자에게 묻고 07 구현 계획.

## 598. M4-104 세부 계획 — `machdep.c` 함수 밖 맞추기 진단 B12(07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션; B11M 객체를 python 으로 원본 기호표·`__cstring` 과 대조):
- B11M: `__text` 5912(원본 구간 5080), `__data` 20 B — `nbuf` 0·`bufpages` 0·`nrnode` 0·`nsoftint` 100·`waittime` -1(원본 [0x40b2b82, 0x40b2b92) 16 B 는 `nbuf`·`nmfsbuf`·`bufpages` 0·`nsoftint` 50; `_nrnode` 0x40aedd8·`_waittime` 0x40ae23a 는 다른 자리), COMMON 55 개 가운데 원본에 없는 것 `_scr1` 하나(진단 `next/scr.h` 사본의 `volatile struct scr1 *scr1;`), 원본에 없는 미정의 없음, 문자열 37 개 가운데 원본 커널에 없는 셋(`halting...\n`·`rebooting Mach...\n`·`unmounting /%s ... ` — `boot`·`unmount_all` 의 것).
- 객체에만 있는 함수 다섯: `setregs`, `boot`(앞의 `waittime`), `unmount_all`(앞의 `#import <sys/vfs.h>`), `kill_tasks`, `physstrat`. `vmtime`(`PGINPROF`)·`cpu_number`(`NCPUS > 1`)·`dumpsys`(`#if 0`)는 컴파일되지 않음.
- 쓰는 `next/scr.h` 이름은 `SCR2_LOCALINT`·`SCR2_EKG_LED`·`scr2` 뿐(grep); 07 `clock.c:63–70`(D116·D121)의 선례는 파일 안 정의와 `extern volatile int *scr2;`. `next/scb.h` 이름은 쓰지 않음(grep: import 줄뿐).
방법(진단; 명세 `08_build/artifacts/m4p598/spec.json`, run `m4p598-p1`, 진단 머리 없음; scratchpad `gen_p598.py`): B12(`machdep_B12.c`, SHA-256 `9b523844…`) = B11M 에서(모두 진단 표시): `next/scr.h` import 대신 세 이름을 파일 안에(값은 사본 `scr.h` 의 것), `next/scb.h` import 뺌, `nbuf` 다음 `int nmfsbuf = 0;`, `nrnode` 정의 뺌, `nsoftint = 50`, 진단 `extern int nmfsbuf;` 뺌, 다섯 함수(와 `waittime`, `sys/vfs.h` import)를 빼고 그 자리에 한 줄 표시.
측정: §597 과 같음 + 섹션 크기(`__text` 5080 기대, python), `__data` 16 B 를 원본 [0x40b2b82, 0x40b2b92) 와 바이트·기호 자리로, `__cstring` 의 모든 문자열이 원본 커널에 있는지, COMMON 이 모두 원본에 있는지, 원본에 없는 미정의, L1(`full_span`·`OBJECT_MATCH` 여부와 사유).
판정(미리 정함; 07 은 바꾸지 않음): 23/23 이고 섹션·자료·문자열·COMMON 이 맞으면(L1 사유가 bss/문자열 공유 등으로 남으면 그 사유를 적음) 바이트로 가를 수 없는 꼴과 이름을 사용자에게 묻고 07 구현 계획을 씀; 아니면 차이를 적고 다음 진단.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 598.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 다섯 함수(와 `waittime`·`sys/vfs.h`)만 빠지고 괄호·조건 지시문이 맞음; `vmtime`·`dumpsys`·`cpu_number` 는 꺼져 있음 | B11M→B12 diff 와 grep(이번 세션) | ✅ |
| `__data` 는 `nbuf`·`nmfsbuf`·`bufpages`·`nsoftint` 50 차례 16 B 가 될 것(원본 바이트 `00…0032`) | §580 의 python 원본 읽기 | ✅ (바이트는 진단으로) |
| 값과 형이 사본 `scr.h:92·97·116` 과 같음; `scr.h` 를 빼면 `_brightness` COMMON 도 없어져 COMMON 이 52 개가 될 것; `_scr2` 는 미정의(다른 객체가 저장소) — 원본 `__common` 자리만으로는 어느 객체가 잡았는지 모름 | — | ✅ 측정에서 COMMON 수 52 를 봄 |
| `halt_thread`·`reboot_mach` 의 `boot` 호출은 바깥 기호가 되어 재배치가 바뀌나 대상은 원본 `_boot`(0x400843e)와 같음 | 원본 0x40937dc·0x409381e `bsr 0x400843e` | ✅ |
| 빼는 함수 크기 합 832 B, 기대 `__text` 5080 | python 5912 − 832 = 5080 | ✅ |

### 598.2 결과(run `m4p598-p1`, 2026-10-30)

- B12(`9b523844…`): 종료 0, 경고 하나(712 행 `thread_sleep` — NeXTMach 글 그대로), i386 0(의존 180). 기록 `09_validation/reconstruction/m4-m68k-probe-p598-20261030.json`.
- **객체 전체가 원본과 맞음**: `__text` 5080 B(구간과 같음), L1 `OBJECT_MATCH` 이유 없음·`full_span`·0x40936a4 에 놓임, 함수 23/23(`m4-m68k-funcbytes-p598-B12-20261030.json`, 대응 `4093792=_knb_start`), `__data` 16 B 가 원본 [0x40b2b82, 0x40b2b92) 와 바이트 같음(재배치 0)·기호 넷(`nbuf` +0·`nmfsbuf` +4·`bufpages` +8·`nsoftint` +0xc)이 원본 자리, `__cstring` 1045 B 의 문자열 29 개가 모두 원본 커널에 있음, COMMON 52 개 모두 원본에 있음(예측대로), 원본에 없는 미정의 없음(python).
- 다음: 바이트로 가를 수 없는 꼴과 작성 이름을 사용자에게 물은 뒤(§599 결정), 07 구현 계획(§600): 07 `src/machdep/m68k/machdep.c`(NeXTMach `next/machdep.c` + 1997 바뀜), 받아들임(행 294–299 덮음).

- 사용자 결정(2026-10-30, AskUserQuestion 두 번): ① `*intrstat` volatile 읽기는 "캐스트 꼴" ② 패리티 기준 주소는 "식 안 대입" ③ 레지스터 셋은 "파일 안 작성 이름"(선택지에 적은 `P_NMI_STAT`·`P_PERR_CLR`·`P_PERR_ADDR`) ④ 도움 함수 이름 "`kernel_thread_noblock_start`" ⑤ `struct ns_callout` 은 "machdep.c 안에 같은 정의" ⑥ `bufpages` 는 "`atop(mem_size / 10 / 2) & ~1`"(시험 안 한 꼴) ⑦ `next/scb.h` 는 "07 NeXTMach 사본" ⑧ 애니메이션 조건은 "`MG()` 매크로 꼴"(시험 안 한 꼴).

## 599. M4-105 세부 계획 — 결정한 꼴·이름의 진단 B13(07 변경 없음; 코딩 전, 2026-10-30)

목적: 위 결정 가운데 아직 시험하지 않은 꼴(⑥ `/ 10 / 2`, ⑧ `MG()`, ⑦ `scb.h` 사본)과 이름(③ 작성 이름 매크로, `P_MAINMEM`·`I_PFAIL` 의 NeXTMach 이름, ④)이 B12 와 같은 바이트를 내는지 07 작성 전에 확인함.
방법(진단; 명세 `08_build/artifacts/m4p599/spec.json`, run `m4p599-p1`; scratchpad `gen_p599.py`): B13(`machdep_B13.c`, SHA-256 `d938c0be…`) = B12 + (진단 표시) `bufpages = atop(mem_size / 10 / 2) & ~1`; 애니메이션 `*MG(short*, MG_seq) >= 24 && *MG(int*, MG_anim_run)` 과 `callout_dispatch(CALLOUT_PRI_RETRACE, *MG(int*, MG_anim_run), 0)`(NeXTMach 줄에서 `<= 99` 만 빼고 호출 이름만 바꾼 꼴); `#import <next/scb.h>` 를 되살리고 진단 머리 `next/scb.h`(NeXTMach 사본 그대로 — `cmp` 같음); 파일 안 `P_MAINMEM`(NeXTMach `next/cpu.h:188`)·`I_PFAIL`(`:221`)·작성 이름 `P_NMI_STAT`·`P_PERR_CLR`·`P_PERR_ADDR` 과 그 사용; 도움 함수 이름 `kernel_thread_noblock_start`. 매크로 정의 줄의 표시 주석이 모두 닫혀 있음을 python 으로 확인(처음 생성본에서 주석 밖 낱말을 잡아 고침). 같은 이름 `P_MAINMEM`·`I_PFAIL` 은 스테이지 `bsd/next/cpu.h:188·221`(C 에서 들이지 않는 어셈블리용 NeXTMach 사본, D109)에 정의되어 있고 `nextdev/dma.h:102–103`·`nextdev/kmreg.h:235` 의 매크로 몸에서 `P_MAINMEM` 만 쓰임(펼칠 때만 필요) — 작성 이름 셋은 grep 0. 값은 `next/cpu.h` 의 것과 같게 둠.
측정: §598 과 같음(섹션·자료·문자열·COMMON·미정의·L1, funcbytes 대응 `4093792=_kernel_thread_noblock_start`), 그리고 B12 객체와 canon·`obj_sig` 비교(명세에 `refs` 가 없으므로 python 으로 따로 하고 결과를 기록 `m4-m68k-p599-checks-20261030.json` 에 둠).
판정(미리 정함; 07 은 바꾸지 않음): B12 와 canon 같고 23/23·`OBJECT_MATCH` 면 이 꼴로 07 구현 계획(§600)을 씀; 아니면 다른 자리를 적고 사용자에게 다시 물음.
관문: 종료 0, i386 0, 옵션 = M5 줄; 경고는 기록.

### 599.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| B13 = B12 + 결정한 바뀜뿐, 매크로·주석 문제 없음 | diff(이번 세션)와 표시 줄 python 검사 | ✅ |
| `/ 10 / 2` 와 `/ 20` 은 무부호에서 같은 값 — 같은 명령인지는 진단이 정함; `MG()` 꼴도 마찬가지 | — | ⏭️ 진단으로 |
| `scb.h` 사본은 저장소·COMMON 을 더하지 않음 | 사본 `scb.h` 를 엶(구조체와 `extern struct scb scb;` 뿐) | ✅ |
| `dma.h`·`kmreg.h` 매크로는 `P_MAINMEM` 만 씀 — 제 문구가 부정확 | grep 출력(이번 세션) | ✅ 고침 |
| 명세에 `refs` 가 없어 B12 와의 비교가 저절로 되지 않음 — 따로 하고 기록할 것 | `m4_m68k_probe.py` 의 비교 조건(§576.1 에서 확인) | ✅ 측정 줄 고침 |

### 599.2 결과(run `m4p599-p1`, 2026-10-30)

- B13(`d938c0be…`): 종료 0, 경고 하나(717 행 `thread_sleep`), i386 0. 기록 `09_validation/reconstruction/m4-m68k-probe-p599-20261030.json`. 23/23(`m4-m68k-funcbytes-p599-B13-20261030.json`, 대응 `4093792=_kernel_thread_noblock_start`), L1 `OBJECT_MATCH` 이유 없음·`full_span`, 섹션 `__text` 5080·`__data` 16·`__cstring` 1045.
- B12 와 비교(`m4-m68k-p599-checks-20261030.json`, python): canon 같음; `obj_sig` 차이는 지역 기호 이름(`_knb_start` → `_kernel_thread_noblock_start`, 같은 자리 +238)과 STABS 1825 → 1834(`scb.h` 를 들임)뿐. 결정한 꼴(`/ 10 / 2`, `MG()`, `scb.h` 사본)과 이름이 모두 원본과 같은 바이트를 냄 → §600 에서 07 을 씀.

## 600. M4-106 D134 구현 계획 — 07 `src/machdep/m68k/machdep.c`, `nextmach/next/scb.h`(명시 구간, OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §598–599 결과와 사용자 결정 ①–⑧. B13 객체는 `__text` 5080·`__data` 16·`__cstring` 1045, 23/23, L1 `OBJECT_MATCH` 이유 없음입니다(`m4-m68k-p599-checks-20261030.json`). 명시 구간 [0x40936a4, 0x4094a7c) 은 재고 행 `m68k-294`–`m68k-299` 를 모두 안에 둡니다(행 294·295 는 `exact` 0 이지만 구간 안; python: 최소 시작 0x40936a4, 최대 끝 0x4094a7c, `bytes_min` 합 5006). 스테이지 `m0p585-a1-stage` 에는 `src/machdep/m68k/machdep.c` 와 `src/bsd/next/scb.h` 가 없고, `next/scb.h` 를 들이는 스테이지 파일도 없습니다(find·grep 0). 07 `nextmach` 의 NeXTMach 사본은 그대로 둔 것(`mon/region.h`, PROVENANCE "none (verbatim)")과 줄을 고치고 표시한 것(`next/pmon.h`)이 있습니다.
1. 07 `src/machdep/m68k/machdep.c`(D103) = B13 글(`d938c0be…`)에서 python 으로 만듭니다(scratchpad `gen_p600.py`):
   - NeXTMach 머리(고지·HISTORY, 1–83 행)는 그대로 두고(D013), 그 뒤 `#import <cpus.h>` 앞에 plan 600 머리 주석(1997 바뀜·지운 함수·작성 이름과 결정 번호)을 넣습니다.
   - B13 이 바꾼 include 줄 열둘에 줄 끝 표시를 붙입니다(기존 07 꼴: `<m68k/cpu.h>` 는 D110, `<m68k/bmap.h>` 는 D105, `<dev/m68k/video.h>` 는 D116, 나머지는 D104).
   - B13 의 진단 표시 `plan NNN diagnostic` 은 모두 `plan 600 (D134, D024)` 로 바꾸고 설명은 둡니다; `next/scb.h` import 줄 표시는 07 사본을 가리키게 씁니다.
   - 진단에만 쓴 `extern struct callout *us_callfree, *us_callout;`(plan 584; NeXTMach `next/us_timer.h:18` 의 선언, 1997 `startup_early` 는 `ns_callout` 만 씀)는 원본 바이트가 요구하지 않으므로 지우고 같은 줄에 한 줄 표시만 둡니다(줄 위치 유지).
   - 표시 주석이 모두 닫혀 있는지(주석 밖 낱말 없음) python 으로 확인합니다(세 번 겪은 생성기 함정).
   - 주석 뺀 토큰이 B13 에서 위 extern 선언 토큰만 빠진 것과 같아야 합니다(python).
2. 07 `07_kernel/nextmach/next/scb.h` = NeXTMach `mk-108.1/next/scb.h` 그대로(`cmp` 같음, SHA-256 `9eb29632…`; 사용자 결정 ⑦).
3. `stage_m68k.py`: `M4FILES[600] = list(M4FILES[585]) + ['machdep.c']`, `M4HEADERS[600] = list(M4HEADERS[585]) + [('next/scb.h', 'src/bsd/next/scb.h')]`, `EXCEPTS[600] = dict(EXCEPTS[585])`, 머리말 plan 목록에 600을 더합니다; `OVLDROP`·`X86` 은 그대로 둡니다(최대 키 583·559 를 씀).
4. 회귀: `--plan 585` 재생성(`m0p585-r600-stage`)이 보관 `m0p585-a1-stage` 와 모든 키·파일이 같아야 합니다. `m0p600-a1-stage` 와 보관 585 의 차이는 파일 `src/machdep/m68k/machdep.c`·`src/bsd/next/scb.h` 둘(파일 963 → 965)과 키 `plan`·`m4_headers`·`files` 뿐이어야 합니다(python assert). M5 205 줄: `m5-585.cmd` 가 §585 것과 `cmp` 같고, run `m3p600-b585`(보관 585 스테이지)·`m3p600-cc1` 의 객체 205 개 바이트 같음·stderr 205 같음, `compare` 두 기록의 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 두 파일이 더해진 것뿐이어야 합니다. x86 `m4_x86_inputs.py s6ln`·`--plan 600 x86gate` 일곱 같음.
5. (07 파일은 p1 전에 고정합니다) 확인 run `m4p600-p1`(`08_build/artifacts/m4p600/confirm/spec.json`, 바탕 `m0p600-a1-stage`, 명시 구간 그대로, `inc` 없음 — `next/scb.h` 는 스테이지에 있음): F = `@machdep/m68k/machdep.c`; L = B13 글에 F 와 같은 plan 600 머리 주석 줄만 넣어 줄 위치를 F 와 맞춘 꼴(`08_build/artifacts/m4p600/src/machdep_L.c`; §579.3 교훈). L 은 진단 extern 을 그대로 두므로 F = L 이면 extern 을 지운 것이 바이트에 영향이 없음을 함께 보입니다. 판정: F·L 종료 0, 경고는 `thread_sleep` 하나씩(NeXTMach 글 그대로), i386 머리 0; F = L(canon·`obj_sig` 모든 칸), L = B13(canon, python), 둘 다 `OBJECT_MATCH`·23/23(대응 `4093792=_kernel_thread_noblock_start`; `m4-m68k-funcbytes-p600-F/L-20261030.json`). run `m4p600-e1`: F·L 의 `-E` 토큰 차이는 extern 선언 토큰뿐(`#` 줄 빼고), i386 0.
6. 최종 run `m4p600-a1`(명세 `08_build/artifacts/m4p600/spec.json`: F 만, `m4_id` 는 §580 의 명시 구간 사전 그대로, `refs["machdep"]` = [p1 L 객체, SHA-256], `known_warnings["machdep"]` = p1 F 의 경고 두 줄 그대로(함수 줄과 경고 줄); 기록 `m4-m68k-p600-final-20261030.json`): `gate.ok`, 옵션 차이 없음, 23/23(`m4-m68k-funcbytes-p600-a1-20261030.json`, 대응 포함). python 확인 `m4-m68k-p600-checks-20261030.json`: 섹션(`__text` 5080·`__data` 16·`__cstring` 1045), `__data` 바이트와 기호 넷이 원본 [0x40b2b82, 0x40b2b92) 와 같음, `__cstring` 문자열이 모두 원본 커널에 있음, COMMON 이 모두 원본에 있음, 원본에 없는 미정의 없음, 외부 함수가 구간 안 원본 이름과 같음, L1 0x40936a4 `OBJECT_MATCH` 이유 없음, 의존 목록 i386 0, 입력 사슬(최종 `-M` 출력 전수: 매니페스트 출처·SHA 가 스테이지 = run, 07 출처면 07 파일과도 같음).
7. 상태표: 근거 `06_reconstruction/evidence/m68k-machdep.md` 를 먼저 쓰고 `ACCEPTED` 에 (최종 기록, SHA) 한 줄을 더합니다; 도구를 두 번 돌리고 §585 표와 이름을 대조합니다(더한 것 `machdep` 뿐, 바뀐 것 없음). 기대(python 으로 미리 계산): 객체 33(OBJECT_MATCH 26), 덮은 행 57/188, 덮은 바이트 54584 + 5006 = 59590, `object_bytes` 71546 + 5080 = 76626; 백분율은 도구 출력만 씁니다.
8. 기록: diff(NeXTMach 대비 `06_reconstruction/evidence/m68k-machdep.diff`), PROVENANCE 새 행 둘(일곱 칸: `machdep.c` — NeXTMach 저장소·커밋 `f6bdb9c3…`·`mk-108.1/next/machdep.c`, 고지(D013), 함수별로 NeXTMach 그대로·바이트로 고친 것·1997 에만 있는 것(`kernel_thread_noblock_start`·`kernel_thread_noblock`·`callout_dispatch`·`callout_remove`)·지운 다섯(`setregs`·`boot`·`unmount_all`·`kill_tasks`·`physstrat`)과 컴파일되지 않는 셋(`vmtime`·`cpu_number`·`dumpsys`), 파일 SHA·최종 기록·`M4FILES[600]`; `nextmach/next/scb.h` — "none (verbatim)", SHA, `M4HEADERS[600]`), MODIFICATIONS, DECISIONS D134(사용자 결정 ①–⑧ 과 바이트가 정한 1997 바뀜), 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: COMMON 임시 정의 합침(§570 과 같음), `nrnode`·`waittime` 과 지운 함수들은 다른 객체의 일입니다.
관문: 명령 종료 0, 경고는 `known_warnings` 의 것뿐, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 600.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다: B13 836 행 진단 표시(plan 595)의 "07 kern/ns_timer.c:123-129" 는 본 나무 파일이 아니라 m68k 덮어쓰기 `07_kernel/v183.34/m68k/src/kern/ns_timer.c:123–129` 를 가리켜야 했습니다(본 나무 123 행은 `ticks_to_ns_time` 근처 다른 코드입니다). 07 표시에서 바로잡습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 4 의 바뀌는 매니페스트 키에 `m4_sources` 가 빠짐 — 새 소스가 그 목록에 더해짐 | `stage_m68k.py:547`(`m4.append(dst)`)·`:569–570`(`man['m4_sources'] = m4`); 583 대 585 매니페스트 python 비교(키 열둘, 585 의 `m4_sources` 31 개) | ✅ 4 를 `plan`·`m4_sources`·`m4_headers`·`files` 넷으로 고칩니다 |
| `us_callfree`·`us_callout` 은 B13 162 행에만 있음; 할당은 `ns_callout`(869)·초기화는 `ns_callout_init()`(1070) | grep(이번 세션): 162 행 하나 | ✅ |
| B13 객체의 보통 기호·STABS 에 두 이름이 없음 — 지워도 영향 없을 것으로 보이나 증명은 아님, 확인 run 유지 | python 으로 객체 바이트 검색: `us_callout`·`us_callfree` 0 건(`callout:T183` 은 `struct callout` 형 정의로, 들이는 머리에서 옴) | ✅ 확인 run 그대로 |
| `obj_sig` 는 보통 기호와 STABS **수**만 비교함 — canon + `obj_sig` 같음이 객체 전체 바이트 같음은 아님 | `l2_prefix_diff.py:48–52` | ✅ 5 에 F·L 객체 바이트 비교(`cmp`)를 더하고, 다르면 차이 자리를 적습니다 |
| 바꾼 include 줄은 정확히 열둘(표의 NX·B13 줄); `en.h`·`od.h`·`sys/vfs.h` 는 지운 함수와 함께 사라짐 | NX·B13 의 import 줄 diff(이번 세션); `en.h`·`od.h` 는 NX 1249·1272(`boot` 안), `sys/vfs.h` 는 1331 | ✅ 머리 주석에 함께 적습니다 |
| 표시 결정 번호(cpu D110, bmap D105, video D116, 나머지 D104)는 기존 07 과 같음 | 07 m68k include 표시 grep(이번 세션: `clock.c`·`snd_dspdev.c`·`fd_cmds.c` 등) | ✅ |
| 표 조회: M4FILES·M4HEADERS 는 최대 키, EXCEPTS 는 정확한 키라 `[600]` 필요; 스테이지에 `scb.h` 를 쓰는 파일 없음 | 요약의 도구 규칙과 `stage_m68k.py:549`(OVLDROP 최대 키); 스테이지 find·grep 0(이번 세션) | ✅ |
| F·L 줄 맞춤은 조건부로 맞음 — python 으로 줄 위치 단언을 더할 것 | — | ✅ 1·5 에 더합니다: 머리 주석 뒤 F·L 줄 수가 같고, 각 줄의 주석 뺀 토큰이 extern 줄 하나 말고 같음 |
| 기대 상태 수치 33·26·57/188·59590·76626 맞음 | python(이번 세션): 현재 32·25·71546, 상태 기록 p585 요약, 합 계산 | ✅ |
| 함수 분류: NX 그대로 컴파일 일곱(`mon_boot`·`nmi_prf`·`softint_th`·`sigreturn`·`halt_cpu`·`light_on`·`light_off`), 고친 열둘(`mon_call`·`halt_thread`·`reboot_mach`·`nmi`·`mini_mon`·`softint_sched`·`softint_run`·`startup_early`·`startup`·`as_tune`·`sendsig`·`addupc`) | scratchpad `fgroups.py` 로 함수별 주석 뺀 토큰 비교(이번 세션): 같은 결과(추출기가 낸 `decl_simple_lock_data` "changed" 는 매크로 줄을 잘못 자른 것이라 뺍니다), NX 에만 다섯, B13 에만 넷, 컴파일되지 않는 셋은 같음 | ✅ 8 에 적습니다 |
| 1997 에만 있는 넷은 "NX `next/machdep.c` 에 없는 것"으로 적을 것 — `kernel_thread_noblock` 은 NX `kern/thread.c:2027` 에 있고, `callout_dispatch` 는 NX `softint_sched` 몸을 대부분 이어받음 | NX `kern/thread.c:2027`(reaper 꼴 정의)을 엶; B13 611 행과 NX 543 행 이후 비교는 §588 에서 한 것 | ✅ 8 의 표현을 고칩니다 |
| PROVENANCE 일곱 칸·그대로 사본 관례 맞음 | PROVENANCE 1172 행(`mon/region.h` "none (verbatim)") | ✅ |

계획 수정: 4 의 키를 넷으로 고칩니다. 1 에 ns_callout 표시 경로를 바로잡는 것을 더합니다. 5 에 python 줄 위치 단언과 F·L 객체 `cmp` 를 더합니다. 8 의 함수 분류를 위 표대로 적고, 1997 에만 있는 넷은 "NX `next/machdep.c` 에 없음(`kernel_thread_noblock` 은 NX `kern/thread.c` 의 reaper 꼴, `callout_dispatch` 는 NX `softint_sched` 몸에서 옴)"으로 적습니다.

### 600.2 결과(2026-10-30)

- 1·2: 07 `src/machdep/m68k/machdep.c`(1487 행, SHA `a2618d9f…`)를 scratchpad `gen_p600.py` 로 B13 에서 만들었습니다. 주석 뺀 토큰 6952 개가 B13(6961 개)에서 extern 선언 토큰 아홉을 뺀 것과 같고, 머리 주석 36 행 뒤 줄 위치가 L 과 같으며 토큰이 다른 줄은 extern 자리 198 행 하나입니다(python). 표시 줄 가운데 `*/` 뒤에 글이 남은 줄은 없습니다. 07 `nextmach/next/scb.h` 는 NeXTMach 사본(`cmp` 같음, `9eb29632…`)입니다. `stage_m68k.py` 710 → 713 행입니다.
- 3·4: `--plan 585` 재생성(`m0p585-r600-stage`)이 보관본과 모든 키·파일이 같습니다. `m0p600-a1-stage`(965 파일)와 보관 585 의 차이는 두 파일과 키 `files`·`m4_headers`·`m4_sources`·`plan` 입니다(python assert). M5: `m5-585.cmd` 가 §585 것과 `cmp` 같고, run `m3p600-b585`·`m3p600-cc1` 종료 0, 객체 205 개 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p600-compare-20261030.json`, `-b585-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 두 파일이 더해진 것뿐입니다. x86 `m4-x86-inputs-p600-20261030.json` `ok`, `--plan 600 x86gate` 일곱 같음·`v183_paths` 0 입니다.
- 5: run `m4p600-p1`(`m4-m68k-probe-p600-p1-20261030.json`): F·L 종료 0, 경고는 753 행 `thread_sleep` 하나씩(B13 717 행 + 머리 36 행), i386 0, 둘 다 `OBJECT_MATCH`·23/23(`m4-m68k-funcbytes-p600-F/L-20261030.json`). F = L(canon·`obj_sig` 모든 칸, STABS 1834), L = B13(canon·`obj_sig`). F·L 객체는 바이트가 같지 않으나, python 으로 다른 바이트가 모두 문자열 표와 `n_strx` 칸(소스 파일 이름 `src/src/machdep/m68k/machdep.c` 대 `src/src/m4probe/src/machdep_L.c`)에만 있고 섹션과 기호 1989 개는 같음을 확인했습니다 — extern 을 지운 것은 객체에 영향이 없습니다. run `m4p600-e1`: F 의 `-E` 토큰(21527)은 L(21536)에서 extern 선언을 뺀 것과 같고 i386 0 입니다.
- 6: run `m4p600-a1`(`m4-m68k-p600-final-20261030.json`, SHA `8b8c7c0d…`; REF = p1 L, `known_warnings` 두 줄): `gate.ok`, 옵션 차이 없음, 23/23(`m4-m68k-funcbytes-p600-a1-20261030.json`); 확인 `m4-m68k-p600-checks-20261030.json`(`ok` 참): 섹션 5080·16·1045, `__data` 가 원본과 바이트 같음·재배치 0·기호 넷이 원본 자리, 비지 않은 문자열 28 개(빈 문자열 하나 더해 29)가 모두 원본에 있음, 외부 함수 22 = 구간 안 원본 이름, 지역 `_kernel_thread_noblock_start` 하나, COMMON 52 모두 원본에 있음, 원본에 없는 미정의 없음, L1 OBJECT_MATCH 이유 없음·`full_span`, 의존 182 파일 사슬 문제 0·i386 0. 객체 SHA `550fb3b2…`(p1 F 와 같음).
- 7: 근거 `06_reconstruction/evidence/m68k-machdep.md`(상태 도구 전). `ACCEPTED` 에 한 줄을 더했습니다. 상태표 34 → 35 행·`m4-m68k-status-p600-20261030.json`: 33 객체(OBJECT_MATCH 26, CODE+BSS_INFERRED 7), 덮은 행 57/188, 59590/215874 B(27.6%), `object_bytes` 76626 — 미리 계산한 값과 같고, 두 번 실행 같음, §585 표와 이름 대조로 더한 것 `machdep` 뿐·바뀐 것 없음.
- 8: diff `m68k-machdep.diff`(921 행), PROVENANCE 1178 → 1180 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 716 → 717 행, DECISIONS D134(137 → 138 행), "현재 상태와 다음 일" 고침.
