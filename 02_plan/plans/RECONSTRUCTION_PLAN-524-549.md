# 커널 소스 복원 작업계획 — 보관 §524·§539–549

`02_plan/RECONSTRUCTION_PLAN.md` 의 §524(`np.c` 진단 — 1997 `nextdev/dma.h` 결정을 기다리던 절로, §543–549 에서 끝남)와 §539–549(m68k M4: `machine_clock`(D118), 1997 `nextdev/dma.h` 배치(D119), `dma.c`(D120), `np.c`(D121))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-30, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 본문은 `---` 아래부터입니다.

---

## 524. M4-30 세부 계획 — `nextdev/np.c` 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션, python):
- 남은 NeXTMach 후보 가운데 정확 경계·대응률 100% 인 C 단위는 `snd_device`(1602 B)·`autoconf`(1904 B)·`fd_subr`(6728 B)·`np`(9116 B)입니다.
  - `snd_device` 는 원본 함수 목록이 NeXTMach 1990 판과 다릅니다(`_snd_device_vol_set`·`_snd_dev_intr` 가 외부 기호, `snd_device_reset`·`set_ramp` 없음, `snd_device_def_dmasize` 등 새 함수). 나중 판이라 뒤로 미룹니다.
  - `np.c` 는 NeXTMach 의 함수 정의 순서(`np_send` 288 … `np_attach`)가 원본 37 진입점 순서와 같습니다. 이름 없는 하나는 정적 `np_ioctl_common_top`(193 선언, 1797 정의) 자리입니다.
- 행 `m68k-233`: [0x40726d0, 0x4074a6c), 9116 B, 정확 경계(받아들인 `nbic` 바로 뒤).
- 머리(§498 표):
  - `"np.h"` 는 구성 머리(`NNP`, `conf/files.NeXT:51`)이고 스테이징에 없습니다.
  - `nextdev/npio.h` 는 SDK `bsd/dev/m68k/npio.h` 와 내용이 같고 include 가드만 더 있습니다(diff). 그러나 m68k 스테이징의 SDK 목록(42 파일)에는 없습니다.
  - `nextdev/npreg.h`·`next/scr.h` 는 NeXTMach 에만 있습니다. 셋 다 다른 머리를 들이지 않습니다.
  - 나머지는 스테이징의 다른 경로에 있습니다(§498 표의 후보 열). `next/printf.h` 의 `reg_values`·`reg_desc` 는 스테이징 `kernserv/printf.h` 에 있습니다.

방법(진단; 명세 `08_build/artifacts/m4p524/spec.json`, run `m4p524-p1`, 바탕 `m0p523-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`(§496; x86 짝 없음), `m4_id` `m68k-233`):
- 변형 A: NeXTMach `np.c` 에서 include 줄만 스테이징 경로로 바꿈(D104 꼴, 본문 그대로).
  - `"np.h"` → `<np.h>` 이고, `inc` 의 진단 대역 `np.h`(`#define NNP 1`)로 공급
  - `<sys/boolean.h>` → `<mach/boolean.h>`
  - `<kern/mach_types.h>` → `<mach/mach_types.h>`, `<sys/message.h>` → `<mach/message.h>`, `<sys/notify.h>` → `<mach/notify.h>`
  - `<vm/vm_param.h>` → `<mach/vm_param.h>`(D107 과 같음)
  - `<next/autoconf.h>` → `<dev/m68k/autoconf.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`, `<nextdev/dma.h>` → `<dev/m68k/dma.h>`
  - `<next/printf.h>` → `<kernserv/printf.h>`
  - `<nextdev/npio.h>`·`<nextdev/npreg.h>`·`<next/scr.h>` 는 그대로 두고 NeXTMach 사본을 `inc` 로 둠
  - `<next/cpu.h>` 는 그대로 두어 스테이징의 07 nextmach 사본(D109, 어셈블리 전용)을 진단에만 씁니다. C 에서 생기는 COMMON 은 기록합니다.
- 측정:
  - `compare`(`diag_gate`, 옵션, `full_span`, L1(`__data`·`__cstring` 포함), 정의·COMMON 이름·크기, 미정의)
  - `m68k_funcbytes.py`(진단 대응: 원본 이름 없는 진입점 → `_np_ioctl_common_top`)
  - 컴파일이 실패하면 첫 오류와 종류를 적습니다.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음): 함수별 같음 표와 자료 결과를 적습니다. 결과에 따라 07 꼴(`next/cpu.h`·`scr.h` 대신 파일 안 매크로, `NNP` 구성, `npio.h` 를 SDK 에서 들일지)을 사용자께 여쭙고 다음 계획을 세웁니다.

### 524.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 스테이징 `dev/m68k/dma.h` 에는 `struct dma_chan`·`DMACSR_WRITE`·`DMACHAN_*` 가 없어 A 는 `np_softc`(np.c:105)에서 실패할 것 | 스테이징 grep 0 건, NeXTMach `dma.h:116,158` 읽음 | ✅ A 는 실패 진단으로 남기고 변형 B 추가 |
| B: `<nextdev/dma.h>` 를 그대로 두고 NeXTMach 사본을 `inc`; 그 안의 `<vm/vm_param.h>` 는 스테이징에 없음 | NeXTMach `dma.h:23` 읽음, 스테이징 `src/vm/vm_param.h` 없음 | ✅ `inc` 에 진단 별칭 `vm/vm_param.h`(`#import <mach/vm_param.h>`, §509 과 같은 꼴) |
| `compare` 의 정의 기호는 외부 기호만이고, `m68k_funcbytes.py` 는 자료 내용을 따로 보지 않음 → 지역 기호 포함 기호표·섹션·크기·초기 바이트를 기록. `DEBUG` 미정의와 `DEBUG=0` 은 `#ifdef DEBUG` 때문에 다름 | `m4_m68k_probe.py:340` 읽음, `np.c:218–222` 읽음 | ✅ 객체 기호표(지역 포함) 기록과 원본 자료 기호(`_np_copyright` `__data` 0x40b1bce, `_npdriver` `__data` 0x40b1bde, `_np_dinfo`·`_np_softc` `__common`)와의 대조를 측정에 더함 |
| `next/cpu.h` 를 C 에 두면 `_disk_chip`, `scr.h` 는 `_scr1`·`_scr2` 를 더함(원본에 `_disk_chip`·`_scr1` 없음). 진단 오염으로만 기록 | D109 | ✅ |
| `first_error` 는 "error"·"No such file" 줄만 잡음 → 컴파일 `.err` 전체를 보존·확인 | `m4_m68k_probe.py:277` 읽음 | ✅ |
| 함수 순서·이름 없는 진입점(0x4073b56, 132 B = `np_ioctl_common_top`)·경계·include 해석 | 계획의 사실과 같음 | ✅ |

### 524.2 결과(2026-10-26)

- run `m4p524-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p524-20261026.json`): A·B 모두 컴파일 실패입니다(`.err` 전체 보존).
  - A: 예상대로 `np_softc` 의 `sc_dc` 필드 형이 불완전합니다(스테이징 `dma.h` 에 `struct dma_chan` 없음).
  - B: NeXTMach `dma.h:72` 의 `NeXT_MIN_PAGE_SIZE` 가 선언되지 않았습니다(NeXTMach `next/vm_param.h:60` 에만 있음).
- run `m4p524-p2`: 진단 별칭 `vm/vm_param.h` 에 `#define NeXT_MIN_PAGE_SIZE 8192`(NeXTMach `next/vm_param.h:60`)만 더한 변형 B2 입니다. 머리 공급만 바꾼 진단이라 §524 의 범위로 기록합니다(기록 `m4-m68k-probe-p524-p2-20261026.json`).
  - 컴파일 종료 0 이고 경고 6 줄입니다. `assert_wait` 인수 형, `thread_wakeup_prim` 의 `volatile`, 포인터·정수 비교로, 1997 머리의 API 와 1990 본문이 어긋난 흔적입니다.
  - `__text` 9006/9116 B, `NOT_MATCH` 입니다. 오염 COMMON 은 `_disk_chip`·`_scr1`·`_scr2` 등으로 기록에 있습니다.
- 함수별(`m4-m68k-funcbytes-p524-B2-20261026.json`, 진단 대응 0x4073b56 = `_np_ioctl_common_top`):
  - 37 가운데 11 개가 바이트까지 같습니다: `np_send`·`np_recv`·`np_nap`·`np_gpiwait_timeout`·`np_open`·`nps_open`·`np_ioctl`·`nps_ioctl`·`np_ioctl_common_top`·`np_select`·`nps_select`.
  - 20 개는 길이가 같고 바이트 몇 개만 다릅니다(예: `np_setmask` 3 B).
  - 6 개는 길이가 다릅니다: `np_setstate` 212/192, `np_startdata` 272/212, `np_close` 106/40, `np_select_common` 166/204, `np_write` 1890/1884, `np_probe` 92/96.
  - 길이가 같은 함수의 차이는 구조체 필드 오프셋입니다. 예: `np_setmask` 원본 `moveb a0@(0x11c)`, B2 `a0@(0x108)`(0x14 = 20 B). `_np_softc` 크기도 원본 332 B(다음 기호까지, 0x14c)에 대해 B2 는 312 B 입니다. `np_softc` 안의 `struct dma_chan`(NeXTMach 1990 `dma.h:158`) 쪽이 1997 판에서 20 B 더 큰 것으로 보입니다.
  - 1997 판 `struct dma_chan` 정의는 07·Darwin 0.1·SDK 사본 어디에도 없습니다(grep 0 건).
- 판정: 미리 정한 대로 기록하고 멈춥니다. `np.c`(그리고 같은 `dma.h` 를 쓰는 m68k 드라이버 `sd`·`od`·`fd`·`snd`·`np`)를 진행하려면 1997 m68k `nextdev/dma.h` 의 배치를 원본 바이트로 정하는 작업(D024 작성)이 먼저 필요합니다. 사용자께 방향을 여쭙니다.


## 539. M4-45 세부 계획 — m68k 시계·타이머 단위(행 267–269) 첫 작성본 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유: "현재 상태와 다음 일" 의 `dma.h` 와 무관한 후보 가운데 참고 글이 가장 많은 단위입니다(x86 07 `machdep/i386/machine_clock.c` 의 짜임, NeXTMach `next/us_timer.c` 의 `timer_set`·`delay`, m68k `eventc.h` 덮어쓰기의 인라인).

확인한 사실(이번 세션; 원본 목록 `otool-V1/image.txt` 0x4091e18–0x4092436, 기호표, python):
- 행 `m68k-267`(bracket `x86-machine_clock`)·`268`(unassigned)·`269`(`next/us_timer.c`)는 모두 정확 경계이고 이어집니다: [0x4091e18, 0x4092436), 1566 B, 진입점 15 개. 앞은 `clock.c`(§535) 끝, 뒤는 `cons.c`(§502) 시작입니다. 이것이 한 객체라는 것은 가설입니다(§532.3); 한 파일로 컴파일해 15 함수와 자료 배치가 맞는지로 시험합니다.
- 원본 순서와 동작:
  1. 이름 없는 정적 함수(0x4091e18, 138 B): `*timer_csr` 를 읽고(값 버림), `eventc.h` 의 `event_sync()` 꼴(비트 19 만 쓰여 `m`·`l` 바이트 값은 버려짐), 정적 함수 포인터(0x40b55bc)가 있으면 받은 세 인수 그대로 부름. `clock_timer_init` 이 `install_scanned_intr(0x1d60 = I(6,0,29) = I_TIMER, 이 함수, 0)` 로 등록합니다.
  2. `hardclock_init`(72 B): `next = clock_value(1) + ns_per_tick`(전역 `_ns_per_tick` `__common` 8 B, 인수는 쓰지 않음; 호출자 07 m68k `kern/ns_timer.c:176` 은 `hardclock_init(ns_per_tick)`), `ns_abstimeout(m68k_hardclock, 0, next, 1)`.
  3. `statclock_init`(8 B): 빈 함수.
  4. `m68k_hardclock`(216 B): `s = splclock()`(0x2300, `IPLCLOCK` 3), `clock_interrupt(tick, USERMODE(hardclock_ps), BASEPRI(hardclock_ps))`(스테이징 `bsd/m68k/machparam.h:48–49`), `hardclock(hardclock_pc, hardclock_ps)`, `splx(s)`, `next += ns_per_tick`, `clock_value(1) > next` 인 동안 `next += ns_per_tick`, `ns_abstimeout(m68k_hardclock, 0, next, 1)`.
  5. `clock_timer_init`(224 B): `startrtclock()`, 정적 64 비트(0x40b55ac) = 0, `time = rtc_get()`(전역 `_time`), 0x40b55ac = `timeval_to_ns_time(&time) - clock_value(1)`, `s = splusclock()`(0x2600), `dma_chip == 0x139` 이면 `*scr2 &= ~0x8000`(NeXTMach `SCR2_TIMERIPL7`), `install_scanned_intr(I_TIMER, 1 의 함수, 0)`, NeXTMach `timer_set(0xffff)` 의 일곱 쓰기(`TIMER_ENABLE|TIMER_UPDATE` = 0xc0), `splx(s)`.
  6. `clock_value`(292 B): `event_set_ts(&ts)` 꼴(안에서 `splusclock`), `ts.high_val`·`ts.low_val` 로 64 비트를 만들어 1000 을 곱함(시프트·덧셈), `which` 가 0(`Calendar`, 스테이징 `kernserv/clock_timer.h:29–30`)이면 정적 0x40b55ac 를 더하고, 1(`System`)이면 그대로, 그 밖이면 0.
  7. `set_clock`(100 B): `which == Calendar` 이면 `s = splusclock(); 0x40b55ac = ns - clock_value(System); splx(s); ns_time_to_timeval(ns, &tv); rtc_set(&tv);`
  8. `clock_attributes`(38 B): 0 → `__const` 0x40ad8da, 1 → 0x40ad8ca, 그 밖 0(x86 07 판과 같은 `switch`).
  9. `timer_attributes`(22 B): 0 이면 0x40ad8ea, 아니면 0.
  10. `set_timer_expire_func`(16 B): 정적 0x40b55c0 = 둘째 인수(x86 판과 달리 조건 없음).
  11. `_set_timer_expire_func`(16 B): 정적 0x40b55bc = 둘째 인수.
  12. `set_timer`(62 B): `ns_untimeout(0x40b55c0, 0)`, `ns_timeout(0x40b55c0, 0, interval, 0)`(`which` 를 보지 않음).
  13. `_set_timer`(166 B): 인수 `interval` 을 1000 으로 나눠 그 자리에 다시 씀(64 비트를 `divull`·`divul` 두 번으로), `which == 0` 이면 `t = (unsigned)interval` 을 500 이상 0xffff 이하로 잘라 NeXTMach `timer_set(t)` 일곱 쓰기.
  14. `clear_timer`(8 B): 빈 함수.
  15. `delay`(188 B): NeXTMach `us_timer.c:501` 의 `delay` 그대로의 꼴(`event_get`·`event_delta` 인라인).
- 자료: `__const` 48 B = 16 B 기록 셋(python): 0x40ad8ca·0x40ad8da = {최대 0xffffffffffffffff, 해상도 1000}, 0x40ad8ea = {65535000, 500000}(곧 0xffff µs, 500 µs). `__bss` 정적 24 B: 0x40b55ac(8, 달력 오프셋), 0x40b55b4(8, 다음 hardclock 시각), 0x40b55bc(4, 인터럽트 함수), 0x40b55c0(4, 타이머 만료 함수). 전역: `_tick`·`_time`(`__data`), `_ns_per_tick`·`_hardclock_pc`·`_hardclock_ps`·`_timer_csr`·`_timer_high`·`_timer_low`·`_eventc_*`·`_dma_chip`·`_scr2`(`__common`), `_event_high`·`_event_middle`(`__data`).

방법(진단; 명세 `08_build/artifacts/m4p539/spec.json`, run `m4p539-p1`, 바탕 `m0p538-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` [`m68k-267`, `m68k-268`, `m68k-269`]):
- 첫 작성본 A(`08_build/artifacts/m4p539/src/machine_clock_A.c`): 위 15 함수를 그 순서로, include `<mach/mach_types.h>`·`<kernserv/clock_timer.h>`·`<kernserv/ns_timer.h>`·`<sys/time.h>`·`<machdep/m68k/eventc.h>`(m68k 덮어쓰기)·`<m68k/machparam.h>`(`USERMODE`·`BASEPRI`)·`<m68k/cpu.h>`(D110), 파일 안 `I`·`I_TIMER`·`SCR2_TIMERIPL7`·`TIMER_ENABLE`·`TIMER_UPDATE`, `extern volatile u_char *timer_csr, *timer_high, *timer_low;`·`extern volatile int *scr2;`, NeXTMach `timer_set` 를 `static inline` 으로, `__const` 기록은 x86 07 판의 `struct mc_attributes` 꼴(값은 위 python), 정적 넷은 주소 순으로 선언. 이름 없는 1 은 x86 판 이름 `system_timer_dispatch` 를 진단용으로 씀. `clock_value` 의 64 비트 조립은 `((ns_time_t)ts.high_val << 32) | ts.low_val` 로 시작합니다.
- 측정: `compare`(`diag_gate` 단언, `full_span`, L1, 미정의), `m68k_funcbytes.py 4091e18 4092436 4091e18=_system_timer_dispatch` 와 정적·상수 대응(0x40b55ac·0x40b55b4·0x40b55bc·0x40b55c0·0x40ad8ca·0x40ad8ea 를 A 의 이름으로), `__const` 48 B 바이트 대조, `__bss` 크기·지역 기호 거리, 정의·COMMON 을 원본 기호표와 대조.

판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음 표와 자료 결과를 적습니다. 다른 함수는 원본과 실기 목록을 대조해 다음 계획의 변형 근거로 씁니다. 15/15 이고 자료 조건이 맞으면 07 꼴(파일 이름과 자리, 정적 이름, 머리)을 사용자께 여쭙습니다.
관문: 명령 종료 상태 기록(실패면 `.err` 보존), i386 머리 0, 옵션 = M5 줄.

### 539.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `KERNEL_PRIVATE` 에서는 `clock_timer.h` 가 `kern/clock.h` 를 들여 `clock_value` 선언이 빠짐; `m68k_hardclock` 은 주소를 쓰기 전에 선언; `time`·`ns_per_tick`·`hardclock_pc`·`hardclock_ps` 선언 필요; `hardclock_init` 의 인수가 전역을 가리지 않게 | 스테이징 `kernserv/clock_timer.h:15–45`, `kern/clock.h` grep(선언 없음), 07 m68k `ns_timer.c:66,135–137`, `bsd/sys/kernel.h:69` 읽음 | ✅ 파일 안 `extern`·선언, `hardclock_init(void)` |
| `rtc_get` 은 `struct timeval` 을 돌려주므로 선언 필요 | 원본 0x4091fea–0x4091ff0 이 d0·d1 을 `_time` 에 저장 | ✅ `extern struct timeval rtc_get();` |
| 콜백 형: `ns_timeout`·`ns_abstimeout` 은 `func`(= `int (*)(void *)`) | 스테이징 `kernserv/ns_timer.h:14–16`, `bsd/sys/callout.h:33` | ✅ 만료 함수는 `func`, 세 인수로 부르는 인터럽트 함수는 `int (*)()`, `m68k_hardclock` 은 `(func)` 로 넘김 |
| `_set_timer` 의 나눗셈 꼴을 정할 것; 07 m68k `ns_timer.c` 의 `ns_div`(§468, D024, `divull`·`divul`)가 같은 꼴 | 그 함수 본문 읽음 | ✅ A = `ns_div` 꼴의 인라인(이 파일 안 사본), A2 = `interval /= 1000;` 두 변형 |
| 한 객체 가설은 맞아도 "들어맞는 재구성" 일 뿐 역사적 경계 증명은 아님; 진입점 상대 위치·객체에만 있는 함수 0·자료 절별 배치 하나를 요구할 것 | 도구 읽음 | ✅ 판정에 더함 |
| 자료 소유는 추정; 머리가 만드는 `_master_cpu` COMMON 도 기록 | 스테이징 `kern/cpu_number.h:61` | ✅ |

### 539.2 결과(2026-10-26)

- run `m4p539-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p539-20261026.json`): 네 명령 종료 0·경고 0(`.err` 모두 0 B), `diag_gate` 참, i386 머리 0, 원본에 없는 미정의 0, 이름 빠짐·더함 0.
- A(`_set_timer` 에 `ns_div` 인라인): `__text` 1556/1566 B, 섹션 `__const` 48·`__bss` 24 B, 함수별(`m4-m68k-funcbytes-p539-A-20261026.json`, 대응: 이름 없는 진입점과 정적 넷·상수 둘) 15 가운데 14 개 같음. 다른 것은 `clock_value`(282/292 B) 하나입니다.
- A2(`interval /= 1000`): `_set_timer` 도 다름(150/166 B). 곧 원본은 `ns_div` 의 두 번 나누는 꼴입니다.
- `clock_value` 차이(실기 목록 `08_build/artifacts/m4p539/machine_clock_A.otool.txt` 와 원본 0x40920aa–0x40921cc 대조): 원본은 `event_set_ts` 뒤에 `ts.high_val`·`ts.low_val` 을 지역 64 비트 변수의 메모리(`a6@(-16)`·`a6@(-12)`)에 낱말로 쓰고 다시 읽은 뒤 1000 을 곱합니다. A 의 `((ns_time_t)high << 32) | low` 는 레지스터로 조립합니다. 07 m68k `ns_timer.c:374–375` 의 `((unsigned int *)&ll)[0]`·`[1]` 관용구(§468, D024)와 같은 성질의 꼴로 보입니다.
- L1 사유는 `__text`·`__const`·`__bss` 미확인(함수 하나가 달라 배치가 안 정해짐)입니다.

## 540. M4-46 세부 계획 — `clock_value` 의 64 비트 조립 꼴 진단(07 변경 없음; 코딩 전, 2026-10-26)

방법(명세 `08_build/artifacts/m4p540/spec.json`, run `m4p540-p1`, 바탕·줄 틀·`m4_id` 는 §539 와 같음). §539 A 에서 `clock_value` 의 조립 한 줄만 바꾼 꼴:
- B1: `((unsigned int *)&now)[0] = ts.high_val; ((unsigned int *)&now)[1] = ts.low_val;`
- B2: `msw = &((unsigned int *)&now)[0]; lsw = &((unsigned int *)&now)[1]; *msw = ts.high_val; *lsw = ts.low_val;`(07 m68k `ns_timer.c` 의 포인터 꼴)
- B3: `now = ((ns_time_t)ts.high_val << 32) + ts.low_val;`(`|` 대신 `+`)
- B4: 공용체 `union { ns_time_t ns; struct { unsigned int hi, lo; } w; } u; u.w.hi = ts.high_val; u.w.lo = ts.low_val; now = u.ns;`
- 측정: §539 와 같음(`compare`, 함수별 대응 같음, `__const` 48 B 원본 대조, `__bss` 지역 기호 거리, COMMON).

판정(미리 정함): 15/15 이고 L1 사유가 `__DATA,__bss: unverified` 하나뿐이며 `__const` 48 B 가 원본과 같은 꼴이 있으면, `__bss` 자리를 zerofill 로 보고 같은 객체를 내는 꼴들과 07 꼴(파일 이름·자리, 정적·인터럽트 함수 이름)을 사용자께 여쭙니다. 없으면 차이를 적고 멈춥니다.

### 540.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §539.2 는 차이를 줄여 말함: 원본 `linkw #-16` 대 A `#-8`, 곱 결과와 오프셋 덧셈 뒤 값을 원본은 `now` 메모리에 다시 씀, `switch` 의 갈래 배치·반환 레지스터 이동도 다름(같은 동작) | A 목록과 원본 0x40920aa–0x40921cc 를 함께 읽음(이번 세션, 앞부분) | ✅ 제 설명이 모자랐습니다. 모두 `now` 의 주소를 쓰는지(메모리에 있는지)에서 올 수 있는 차이로 보고, 시험으로 확인 |
| B2·B4 는 선언을 블록 앞에 둬야 함 | 계획 문장 | ✅ |
| 더할 꼴: 주소를 쓰는 별도 64 비트 임시 변수; `now = now * 1000` 꼴 | — | ✅ B5(임시 `t` 에 낱말로 쓰고 `now = t * 1000`), B6(B1 + `now = now * 1000`) |
| 판정에 `full_span`·진입점 위치·참조 대상 같음을 명시; bss 는 크기·정렬·기호 거리·배치를 보고 zerofill 로 판단; 맞아도 역사적 원문·경계 증명은 아님 | 도구 읽음 | ✅ |

### 540.2 결과(2026-10-26)

- run `m4p540-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p540-20261026.json`): 12 명령 종료 0·경고 0, `diag_gate` 참.
- 여섯 꼴 모두 14/15 이고 `clock_value` 만 다릅니다: B1·B2·B6 302 B, B3·B5 282 B(A 와 같음), B4 274 B, 원본 292 B.
- B1 의 실기 목록(`08_build/artifacts/m4p540/B1.otool.txt`)을 원본과 숫자를 가려 대조하면(python, 원본 95 명령 대 96), `ts` 를 낱말로 64 비트 메모리에 옮기고 1000 을 곱해 `now` 에 다시 쓰는 부분까지는 같습니다. 남은 차이는 `switch` 입니다: 원본은 `which == 0` 을 먼저 시험하고, `default` 에서 `now` 에 쓰지 않고 `moveq #0,d0; moveq #0,d1` 로 바로 돌아갑니다. B1 은 `default` 에서 `now = 0` 을 메모리에 쓰고 다시 읽습니다.
- 판정: 미리 정한 둘째 갈래(맞는 꼴 없음)입니다. 기록하고 멈춥니다. `switch` 의 꼴은 §541 에서 시험합니다.

## 541. M4-47 세부 계획 — `clock_value` 의 `switch` 꼴 진단(07 변경 없음; 코딩 전, 2026-10-26)

방법(명세 `08_build/artifacts/m4p541/spec.json`, run `m4p541-p1`, 바탕·줄 틀·`m4_id`·대응은 §539·§540 과 같음). B1 에서 `switch` 만 바꾼 꼴:
- C1: `case Calendar: now += calendar_offset; break; case System: break; default: return (0);` 뒤 `return (now);`
- C2: `case System: return (now); case Calendar: now += calendar_offset; return (now); default: return (0);`
- C3: `if (which == Calendar) now += calendar_offset; else if (which != System) return (0); return (now);`
- 측정·판정: §540 과 같음(15/15, `full_span`, 진입점 위치·참조 대상 같음, L1 사유가 bss 하나, `__const` 48 B 원본과 같음; 맞으면 bss 를 zerofill 로 보고 07 꼴을 여쭘; 없으면 기록하고 멈춤).

### 541.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §540.2 는 꼬리 차이를 덜 적음: 둘 다 `which == 0` 을 먼저 시험하지만 갈래 극성과 블록 자리가 다르고, B1 은 모든 길에서 `now` 를 다시 읽어 `d0/d1` 에 넣음 | §540.2 의 python 대조 출력(이번 세션) | ✅ 사실 줄을 이 표로 보탬 |
| C1–C3 은 바른 꼴; 더 가까운 후보는 `case System: break; case Calendar: now += calendar_offset; break; default: return (0);` | 원본 갈래 배치 | ✅ C4 로 더함 |

### 541.2 결과(2026-10-26)

- run `m4p541-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p541-20261026.json`): 여덟 명령 종료 0·경고 0, `diag_gate` 참.
- C2(`case System: return (now); case Calendar: now += calendar_offset; return (now); default: return (0);`): `__text` 1566 B, `full_span`, 15/15(`m4-m68k-funcbytes-p541-C2-20261026.json`), L1 사유 `__DATA,__bss: unverified` 하나(`provisional`). `__const` 48 B 가 원본 0x40ad8ca 의 48 B 와 같음(`clock_attrs` +0, `timer_attrs` +32). `__bss` 24 B 의 정적 넷이 +0·+8·+16·+20(원본 0x40b55ac·b4·bc·c0 의 차례). zerofill(`m4-m68k-zerofill-p541-C2-20261026.json`): `reference-inferred`, 후보 [0x40b55ac, 0x40b55c4), 문제 0; 이전에 받아들인 m68k 배치 30 개와 겹침 0(python). 외부 정의는 모두 원본에 있고, COMMON 은 머리(`kern/cpu_number.h`)가 만든 `_master_cpu` 하나(원본에 있음, 소유는 정하지 않음).
- C1·C3(298 B)·C4(302 B)는 `clock_value` 가 다름.
- 판정: 미리 정한 첫 갈래입니다. 같은 바이트를 내는 꼴은 시험한 것 가운데 C2 하나입니다(맞아도 역사적 원문·객체 경계의 증명은 아님). 07 꼴을 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): 파일 `src/machdep/m68k/machine_clock.c`(x86 07 판과 같은 이름); 이름 없는 정적 인터럽트 함수는 NeXTMach `us_timer.c` 의 이름 `us_timer_int`, 정적 변수 넷은 진단 이름(`calendar_offset`·`hardclock_next`·`timer_intr`·`timer_expire`).

## 542. M4-48 D118 구현 계획 — 07 `src/machdep/m68k/machine_clock.c`(코딩 전, 2026-10-26)

1. 꼴 L(`08_build/artifacts/m4p542/src/machine_clock_L.c`) = §541 C2 에서 `system_timer_dispatch` 를 `us_timer_int` 로 바꾸고 진단 머리 주석을 뺀 글. C2 와의 차이는 그 이름과 주석뿐(python).
2. 07 `src/machdep/m68k/machine_clock.c`(D103) = L + 머리 주석(이 프로젝트 작성 D024; 원본 구간 [0x4091e18, 0x4092436)·`__const` 48 B·`__bss` 24 B; 짜임은 x86 07 `machdep/i386/machine_clock.c`(이 프로젝트, D024); NeXTMach mk-108.1 `next/us_timer.c` 에서 온 것: `timer_set`(110–119 행)·`delay`(501–507 행)의 글, 이름 `us_timer_int`; 07 m68k `kern/ns_timer.c` 의 `ns_div`(§468, D024)를 이 파일에 둠; `eventc.h` 의 인라인을 씀; 맞춘 꼴: `ns_div`·낱말 조립·`switch` 의 이른 `return`(§539–541)) + 함수별 출처 주석. 주석을 뺀 토큰 = L.
3. `stage_m68k.py`: `M4FILES[542]` = 538 목록 + `machine_clock.c`, `M4HEADERS[542]` = 538, `EXCEPTS[542]` = 538. 회귀: `--plan 538` 재생성 = `m0p538-a1-stage`, `--plan 542 stage m0p542-a1-stage` 와의 차이는 이 파일 하나(M5 205 줄은 새 `src/machdep/m68k/` 파일을 읽지 않음). x86 `machdep/i386/machine_clock.c` 는 바꾸지 않음.
4. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시 `m4_x86_inputs.py s6ll`, `--plan 542 x86gate`).
5. 확인 run `m4p542-p1`(F = `@machdep/m68k/machine_clock.c`, L): F·L `provisional`(사유 bss 하나), canon·`obj_sig` 같음, 15/15(대응: `4091e18=_us_timer_int` 와 정적·상수), §541 C2 와 섹션 바이트 같음; run `m4p542-e1` `-E` 토큰 F = L.
6. 최종 run `m4p542-a1`(REF = L, `bss_inferred` [`machine_clock`]): `gate.ok`; zerofill `objs`(REF = L) `ok`; python 확인: `__const` 48 B 원본과 같음, `__bss` 24 B 기호 거리 0·8·16·20, 외부 정의 = 원본 진입점 14 개(이름 없는 하나 빼고), COMMON 은 `_master_cpu` 하나, 원본에 없는 미정의 0, 입력 사슬, L1 0x4091e18 사유 bss 하나, 15/15, 이전에 받아들인 배치 30 개와 겹침 0, `diag_gate` 단언.
7. 기록: 근거 문서 먼저(`m68k-machine_clock.md`), diff(x86 07 판 대비 `m68k-machine_clock.diff`), 상태표(CODE+BSS_INFERRED; 두 번 실행 같음, 앞 19 행 그대로), PROVENANCE(`authored+nextmach`; NeXTMach URL·커밋·경로·줄), MODIFICATIONS, DECISIONS D118, M7 의무(bss 배치, `_ns_per_tick`·`_hardclock_pc`·`_hardclock_ps`·`_timer_*`·`_scr2`·`_master_cpu` 의 정의 객체).
관문: 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 542.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| D013 에 따라 NeXTMach `us_timer.c` 의 고지(1 행 SCCS 줄, 4 행 저작권)를 보존할 것; `delay` 는 주석 포함이면 498–507 | NeXTMach `us_timer.c:1–6,497–507` 읽음 | ✅ 07 파일 머리에 두 줄을 그대로 두고, 출처 줄 범위를 498–507 로 |
| `timer_set` 110–119, `us_timer_int` 226; `obj_sig` 는 지역 이름을 포함하므로 C2 와는 섹션 바이트로만 비교(계획대로); `ns_div` 는 07 m68k `ns_timer.c:73–93` 의 그대로 사본(D024) | 그 줄 읽음 | ✅ |

### 542.2 결과(2026-10-26)

- 1–2: L(`08_build/artifacts/m4p542/src/machine_clock_L.c`)은 §541 C2 와 `us_timer_int` 이름·진단 주석만 다릅니다(이름을 바꾼 C2 와 토큰 같음). 07 `src/machdep/m68k/machine_clock.c`(259 행, SHA-256 `1fb5e527…`)는 주석을 뺀 토큰 1080 개가 L 과 같습니다. 머리에 NeXTMach `us_timer.c` 의 고지 두 줄(1·4 행)을 그대로 두었습니다.
- 3: `stage_m68k.py` 649 → 654 행. `--plan 538` 재생성 = `m0p538-a1-stage`(모든 키), `--plan 542 stage m0p542-a1-stage`(924 파일)와의 차이는 `machine_clock.c` 하나.
- 4: x86 입력 불변(`m4-x86-inputs-p542-20261026.json` ok; `--plan 542 x86gate` 일곱 묶음 `same`, v183 경로 0); i386 `machine_clock.c` 그대로(git).
- 5: run `m4p542-p1`(`m4-m68k-probe-p542-20261026.json`, `diag_gate` 참): F·L `provisional`(사유 bss 하나), canon·`obj_sig` 같음, C2 와 `__text`·`__const`·`__bss` 바이트 같음, 15/15. run `m4p542-e1`: `-E` 토큰 9580 개 같음.
- 6: run `m4p542-a1`(REF = p1 L `d6521683…`, `bss_inferred` [`machine_clock`]; `m4-m68k-p542-final-20261026.json`): `gate` 모두 참, 객체 SHA-256 `12cd3d03…`. zerofill `m4-m68k-zerofill-p542-20261026.json`: `reference-inferred`, 후보 [0x40b55ac, 0x40b55c4), 이전 배치 30 개와 겹침 0. python 확인(`m4-m68k-p542-checks-20261026.json`, `ok` 참): 섹션 `__text` 1566·`__const` 48(원본과 같음)·`__bss` 24(정적 넷 +0·+8·+16·+20), 외부 정의 = 원본 이름 있는 진입점 14 개, COMMON 은 `_master_cpu` 하나, 원본에 없는 미정의 0, 입력 사슬, L1 0x4091e18 사유 bss 하나, 15/15, i386·`next/cpu.h` 없음.
- 7: 상태표 20 객체(OBJECT_MATCH 17, CODE+BSS_INFERRED 3), 덮은 행 42/188, 18944 B(8.78%), 부분 행 306, 앞 19 행 그대로, 두 번 돌린 출력 같음(`m4-m68k-status-p542-20261026.json`; `m4_m68k_status.py` 148 → 150 행). PROVENANCE 1135 → 1136 행(경로 중복 0), MODIFICATIONS 681 → 682 행, DECISIONS D118(121 → 122 행), 근거 `06_reconstruction/evidence/m68k-machine_clock.md`, diff(i386 판 대비) `m68k-machine_clock.diff`(425 행).

## 543. M4-49 세부 계획 — 1997 m68k `nextdev/dma.h` 의 `struct dma_chan` 배치 진단(07 변경 없음; 코딩 전, 2026-10-26)

사용자 지시(2026-10-26): "1997 dma.h 배치를 원본 바이트로 정하는 작업" 을 진행. §524 에서 `np.c` 가 1997 `struct dma_chan`(NeXTMach 보다 20 B 큼) 때문에 멈췄습니다.

확인한 사실(이번 세션; 원본 목록, 기호표, python):
- 원본의 `dma.c` 는 행 `m68k-212`(unassigned, 정확 경계) [0x4066410, 0x40678ce), 5310 B 입니다. 진입점은 `_dma_init`, `_dma_close`, 이름 없는 하나(0x40664ee), `_dma_enqueue`, `_dma_dequeue`, `_dma_list`, `_dma_start`, `_dma_cleanup`, `_dma_abort`, `_dma_intr`, `_cache_flush`, `_nitro_cache_flush`, `_vcopy` 입니다. NeXTMach `nextdev/dma.c` 와 순서·구성이 다릅니다(예: `dma_start` 가 `dma_cleanup` 앞, `dma_va_list`·`pcopy`·`pfill` 없음, `vcopy` 새로).
- NeXTMach 1990 `struct dma_chan`(python, 낱말 4 B): `dc_queue` 0x0·0x4, `dc_current` 0x8, `dc_dmaintr` 0xc, `dc_handler` 0x10, `dc_hndlrarg` 0x14, `dc_hndlrpri` 0x18, `dc_ddp` 0x1c, `dc_direction` 0x20, `dc_state` 0x24, `dc_next` 0x28, `dc_flags` 0x2c, `dc_tailstart` 0x30, `dc_taillen` 0x34, `dc_tail` 0x38, `dc_ptail` 0x3c, `dc_tailbuf[160]` 0x40, `dc_sectchain` 0xe0, 크기 228.
- 1997 원본에서 읽은 배치:
  - `_dma_init`: `dc_flags` 0x2c 에서 `BUSY|CHAINING|ERROR` 를 지움(`andw #0x8fff`), `dc_ddp` 0x1c 에 `DMACMD_RESET` 만 씀(0x100000; NeXTMach 은 `RESET|INITBUF`), `install_scanned_intr(device, dma_intr, dcp)` 를 먼저 부름, 꼬리 포인터 = `(dcp + 0x53) & -16` = 0x44 의 `dc_tailbuf` 를 16 으로 올림 → 0x3c 에 저장, 쪽 경계를 넘으면 `kalloc(0x110)` 을 0x38 에 두고 다시 맞춤(그래도 넘으면 +0x80), 0x40 = `pmap_resident_extract(pmap_kernel(), 0x3c)`, `dc_current` 0x8 = 0.
  - `_dma_close`: 0x38 이 있으면 `kfree(0x38, 0x110)` 하고 0 으로.
  - `_dma_cleanup`: `dma_abort`, 음수 `resid` 면 panic, `dc_flags & 0x8000` 이면 0xe4·0xe8·0xec·0xf0·0xf4 다섯 필드로 `vcopy` 를 부르고(둘째 호출은 남은 길이가 양수일 때만) 0x8000 을 지움; 아니면 NeXTMach 처럼 `dc_taillen`(0x34) > `resid` 일 때 `bcopy(dc_tail(0x3c), dc_tailstart(0x30), …)`.
  - `_dma_list`·`_dma_cleanup` 만 0xe4–0xf4 를 쓰고, `_dma_intr` 은 0x2c 넘는 필드를 쓰지 않습니다(1990 의 `dc_sectchain` 호출 없음).
  - 따라서 1997 배치 후보: 0x0–0x34 는 1990 과 같음, 0x38 새 포인터(할당한 꼬리 버퍼), 0x3c `dc_tail`, 0x40 `dc_ptail`, 0x44 `dc_tailbuf[160]`, 0xe4–0xf4 새 낱말 다섯, 크기 0xf8 = 248(1990 보다 20 B 큼; python). §524 의 `_np_softc` 332 B 대 B2 312 B 의 차이 20 B 와 맞습니다.
- `struct dma_hdr` 는 28 B(1990 과 같음; `_dma_list` 의 증가 폭 `addaw #0x1c`·`#0xffe4`).

방법(진단; 명세 `08_build/artifacts/m4p543/spec.json`, run `m4p543-p1`, 바탕 `m0p542-a1-stage`, 대상과 `m4_id`·대응은 §524 와 같음):
- 진단 머리 D97(`08_build/artifacts/m4p543/inc/nextdev__dma.h`, 07 아님): NeXTMach `nextdev/dma.h` 에서 `struct dma_chan` 만 위 후보로 바꿈(새 필드는 진단 이름 `dc_x38`, `dc_xe4`…`dc_xf4`; `dc_sectchain` 뺌). 다른 내용은 그대로.
- 변형 B3: §524 B2(`np_B.c` + 같은 `inc`)에서 `nextdev/dma.h` 만 D97 로.
- 측정: `compare`(`diag_gate` 단언), `m68k_funcbytes.py`(§524 와 같은 범위·대응), `_np_softc` COMMON 크기, 함수별로 B2 대비 무엇이 바뀌었는지.

판정(미리 정함; 07 은 바꾸지 않음):
- B2 에서 길이가 같고 오프셋만 달랐던 함수들이 같아지고 `_np_softc` 가 332 B 이면, 후보 배치가 `np` 가 쓰는 필드에 대해 맞다고 적습니다. 남는 차이(길이가 다른 함수 등)는 `np.c` 본문의 1997 바뀜으로 따로 다룹니다.
- 다음 계획: 새 필드의 뜻(이름)은 `dma.c`(행 212)의 `_dma_list`·`_dma_cleanup`·`_vcopy` 에서 읽고, 1997 `dma.h` 의 07 꼴(이름, 자리, `07_kernel/nextmach` 사본을 고칠지 등)을 사용자께 여쭙니다.
- 그렇지 않으면 차이를 적고 멈춥니다.
관문: 명령 종료 0·경고는 B2 와 같은 줄(1990 본문 대 1997 머리의 경고)만, i386 머리 0, 옵션 = M5 줄.

### 543.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_dma_cleanup` 의 둘째 `vcopy` 는 남은 길이가 양수일 때만(`tstl d2; ble`) | 원본 0x4067008–0x406700c 읽음 | ✅ 제 오기입니다. 사실 줄을 고침 |
| 이더넷이 채널마다 0xf8 B 를 지움 → 크기 248 B 를 따로 뒷받침 | 원본 0x408dd08 `pea 0xf8` + `bsr` 읽음 | ✅ |
| `_np_attach` 가 `sc+0x48` 에서 0xa0 B 를 지움(`sc_dc` 는 `sc+4` → `dc+0x44`, 160 B) → `dc_tailbuf` 160 을 뒷받침, 176 이면 `_np_attach` 가 어긋남 | 원본 0x4074a42–0x4074a4a 읽음 | ✅ |
| `np` 의 `sc_gpimask`·`sc_gpin`·`sc_cflags` 가 정확히 0x14 씩 밀림 | §524 B2 목록과 원본 대조(codex 의 python) | ⏭️ B3 결과로 확인 |
| 이 시험은 배치의 호환성을 보이며 역사적 선언 그 자체(공용체 등)를 증명하지는 않음 | — | ✅ 판정 문장에 그대로 둠 |

### 543.2 결과(2026-10-26)

- run `m4p543-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p543-20261026.json`): 두 명령 종료 0, 경고 6 줄은 §524 B2 와 줄 번호를 뺀 내용이 같음(1990 `np.c` 본문 대 1997 머리; `diag_gate.commands_ok` 는 이 경고 때문에 거짓), i386 머리 0.
- B3(D97 머리): `np` 37 함수 가운데 32 개가 같음(`m4-m68k-funcbytes-p543-B3-20261026.json`). B2 에서 길이가 같고 오프셋만 달랐던 20 함수와 길이가 달랐던 `np_probe` 가 모두 같아졌고, `_np_softc` COMMON 은 332 B(원본 다음 기호까지 0x14c)입니다. 남은 다섯(`np_setstate` 192/212, `np_startdata` 212/272, `np_close` 40/106, `np_select_common` 204/166, `np_write` 1884/1890)은 길이가 달라 `np.c` 본문의 1997 바뀜입니다.
- 판정: 미리 정한 대로, 후보 배치(0x0–0x34 는 1990 과 같음, 0x38 새 포인터, 0x3c `dc_tail`, 0x40 `dc_ptail`, 0x44 `dc_tailbuf[160]`, 0xe4–0xf4 새 낱말 다섯, 248 B)가 `np` 가 쓰는 필드에 대해 맞습니다. 이것은 배치의 호환성이며 역사적 선언 그 자체의 증명은 아닙니다.
- 새 필드의 뜻(원본 `_dma_list` 0x4066634–0x40666d4, `_dma_cleanup`, `_dma_init`·`_dma_close` 에서 읽음):
  - 0x38: `_dma_init` 이 꼬리 버퍼가 쪽 경계를 넘을 때 `kalloc(0x110)` 한 포인터(`_dma_close` 가 `kfree(…, 0x110)` 하고 0 으로).
  - `_dma_list`: 시작 가상 주소 `va` 가 16 B 정렬이 아니면 `dc_flags |= 0x8000`(새 플래그), 0xe4 = `va`, 0xf4 = `pmap`(인수), 0xe8 = `16 - (va & 15)`, 0xec = (길이 − 0xe8)를 0 쪽으로 16 의 배수로 자른 값(§545.1), 0xf0 = 나머지 길이; 방향 인수가 0 이면 `vcopy` 로 나머지를 꼬리 버퍼(0x3c)로, 본문을 `va` 에서 `va + 0xe8` 로 옮김(§545.1 에서 방향을 고침; 원본 0x40666b0–0x40666c6); 뒤의 목록은 정렬된 `va` 로 만듦.
  - `_dma_cleanup`: 0x8000 이 서 있으면 이 다섯 필드로 `vcopy` 해 되돌리고 0x8000 을 지움.
  - 곧 다섯 필드는 "정렬 안 된 버퍼를 옮겨 DMA 하기" 상태(원래 `va`, 앞 어긋남, 정렬된 길이, 나머지 길이, `pmap`)입니다. 이름은 원본에 없으므로 작성해야 합니다(D024).
- 사용자 결정(2026-10-26, AskUserQuestion): 머리 꼴은 "NeXTMach 사본 고침 + SDK 공개판 import"; 새 이름은 뜻을 담은 이름(0x38 `dc_tailalloc`, 0xe4 `dc_alignva`, 0xe8 `dc_alignoff`, 0xec `dc_alignlen`, 0xf0 `dc_alignrem`, 0xf4 `dc_alignpmap`, 플래그 0x8000 `DMACHAN_UNALIGNED`).

## 544. M4-50 D119 구현 계획 — 07 `07_kernel/nextmach/nextdev/dma.h`(1997 배치; 코딩 전, 2026-10-26)

1. 07 `07_kernel/nextmach/nextdev/dma.h` = NeXTMach `nextdev/dma.h`(고지·HISTORY 그대로)에서 다음만 바꿈(표시 `plan 544`):
   - `#import <vm/vm_param.h>`(스테이징에서 풀리지 않음) → `#import <mach/vm_param.h>`(D107 과 같음)와, `NDMAHDR` 가 쓰는 `NeXT_MIN_PAGE_SIZE` 를 `#ifndef` 로 8192(NeXTMach `next/vm_param.h:60`). `NDMAHDR` 의 1997 값은 바이트로 아직 확인하지 못했다는 단서를 주석에 둠.
   - 정렬 매크로 덩이(`MAX_DMA_LEN` … `DMA_ENDALIGNED`)를 빼고 `#import <dev/m68k/dma.h>`(SDK 1997 공개판: `MAX_DMA_LEN`, `MAX_CHAIN_LEN`, `DMA_BEGINALIGNMENT` 16, `DMA_ENDALIGNMENT` 16, `DMA_LONGALIGNMENT`, `DMA_BEGINALIGN`·`DMA_ENDALIGN`·`…ALIGNED`)로. NeXTMach 의 `DMA_ALIGN` 이름은 SDK 의 `DMA_BEGINALIGN` 으로 바뀌었으므로 따로 두지 않음.
   - `struct dma_chan` 을 §543 배치로: 0x34 `dc_taillen` 뒤 `char *dc_tailalloc;`(0x38), `dc_tail`(0x3c), `dc_ptail`(0x40), `dc_tailbuf[DMA_MAXTAIL+2*DMA_ENDALIGNMENT]`(0x44, 160), `char *dc_alignva`(0xe4), `long dc_alignoff`(0xe8), `long dc_alignlen`(0xec), `long dc_alignrem`(0xf0), `struct pmap *dc_alignpmap`(0xf4; §544.1); `dc_sectchain` 뺌. 형은 쓰임새로 고른 작성(D024; 바이트에는 크기만 보임).
   - `DMACHAN_UNALIGNED 0x8000` 을 상태 플래그 자리에 더함.
2. `stage_m68k.py`: `M4HEADERS[544]` = 542 목록 + (`nextdev/dma.h` → `src/bsd/nextdev/dma.h`), `M4FILES[544]` = 542, `EXCEPTS[544]` = 542. 회귀: `--plan 542` 재생성 = `m0p542-a1-stage`, `--plan 544 stage` 와의 차이는 그 머리 하나. 그 자리를 들이는 스테이징 소스는 지금 없음(grep 0 건); 그래도 새 스테이징 머리이므로 M5 205 줄 회귀(§535 와 같은 절차: 205 객체·stderr 같음, `compare` 의 `differ_unexpected`·`lost` 빔).
3. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시, `--plan 544 x86gate`).
4. 검증 run `m4p544-p1`(바탕 `m0p544-a1-stage`): §524 의 `np_B.c` 를 `inc` 에서 `nextdev/dma.h`·`vm/vm_param.h` 진단 별칭 없이(07 머리 사용) 컴파일한 변형 B4. 기대: §543 B3 과 같은 32/37, `_np_softc` 332 B, 경고는 B2·B3 과 같은 줄. B4 와 B3 의 `__text` 가 같은지(canon)도 봄.
5. 기록: PROVENANCE(`nextmach+authored`; NeXTMach URL·커밋·경로; SDK 공개판 import), MODIFICATIONS, DECISIONS D119, 근거 `06_reconstruction/evidence/m68k-dma_h.md`, diff(NeXTMach 대비) `m68k-dma_h.diff`. 상태표에는 넣지 않음(객체가 아님). M7·다음 일: `dma.c`(행 212)·`np.c` 남은 다섯 함수 등에서 이 머리를 씀.
관문: 명령 종료 0, i386 머리 0, 회귀 같음(M5 포함), x86 입력 불변.

### 544.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 머리 안에서 `pmap_t` 가 정의되지 않음(`mach/vm_param.h`·`kern/xpr.h` 사슬에 없음); B4 는 `np_B.c` 가 먼저 들이는 `kern/task.h` 사슬 때문에 이 결함을 가림 | 스테이징 `machdep/m68k/pmap.h:45–52` 읽음 | ✅ `dc_alignpmap` 의 형을 `struct pmap *` 로 씀(새 include 없이 같은 4 B 포인터) |
| 형·크기는 §543 배치를 그대로 냄(`int`·`long`·포인터 4 B, 정렬 2 B; 160·0x38…0xf4·248) | 이 세션 §543 B3 결과(`_np_softc` 332), ABI 기록은 codex 가 인용 | ⏭️ 아래 머리 단독 확인으로 직접 잼 |
| 매크로 충돌 없음(`DMA_BEGINALIGNMENT` 4 대 16 만 다르고 그 덩이를 뺌); `NDMAHDR`·`dc_tailbuf` 는 SDK 이름으로 풀림 | NeXTMach `dma.h:31–45`, SDK `dma.h:28–44` 읽음(이번 세션) | ✅ |
| 머리를 맨 먼저 들이는 단독 컴파일로 크기·오프셋을 확인할 것 | — | ✅ 4 에 더함: `#import <nextdev/dma.h>` 만 먼저 들이고, `sizeof`·각 필드 오프셋 크기의 `char` 배열(COMMON)로 값을 객체 기호표에서 읽는 진단 파일 |

### 544.2 결과(2026-10-26)

- 1: 07 `07_kernel/nextmach/nextdev/dma.h`(233 행, SHA-256 `72c2d061…`): NeXTMach 사본(227 행)에서 `plan 544` 표시 줄과 머리 주석 한 덩이만 바뀜(diff `06_reconstruction/evidence/m68k-dma_h.diff` 78 행). `dc_alignpmap` 은 `struct pmap *`(§544.1).
- 2: `stage_m68k.py` 654 → 657 행. `--plan 542` 재생성 = `m0p542-a1-stage`(모든 키), `--plan 544 stage m0p544-a1-stage`(925 파일)와의 차이는 `src/bsd/nextdev/dma.h` 하나. M5 205 줄: run `m3p544-b542`·`m3p544-cc1` 각 205 명령 종료 0, 205 객체 모두 바이트 같음, stderr 205 개 모두 같음(비어 있지 않은 것 52 개); `compare`(`m3-m68k-p544-compare-20261026.json`, `-b542-`)의 `differ_unexpected`·`lost` 빔, 요약 항목 모두 같음.
- 3: x86 입력 불변(`m4-x86-inputs-p544-20261026.json` ok; `--plan 544 x86gate` 일곱 묶음 같음, v183 경로 0).
- 4: run `m4p544-p1`(기록 `m4-m68k-probe-p544-20261026.json`): B4 는 종료 0, 경고 6 줄이 B3 과 같음, i386 머리 0, 32/37(`m4-m68k-funcbytes-p544-B4-20261026.json`; 다른 다섯은 B3 과 같은 `np_setstate`·`np_startdata`·`np_close`·`np_select_common`·`np_write`), `_np_softc` 332 B, B3 객체와 canon·`obj_sig` 같음(`__text` 9002·`__data` 66·`__cstring` 531 B 바이트 같음).
- 4(머리 단독): 제 설계 오류 — 처음 진단 H(같은 run)는 오프셋을 `OFF + 1` 크기의 배열로 읽었는데, 홀수 COMMON 크기가 짝수로 올림되어 값이 `OFF + 2` 로 나왔습니다(예상 배치와는 맞지만 읽기가 모호). 배열을 `2 * OFF + 2`(늘 짝수)로 고친 H2 를 run `m4p544-p2` 로 다시 돌렸고(`char[3]` 는 4 로 올림됨을 같이 확인), 종료 0·경고 0·`diag_gate` 참: `sizeof (struct dma_chan)` 248, `struct dma_hdr` 28, `dc_tailbuf` 160, `dc_alignpmap` 4, `DMACHAN_UNALIGNED` 0x8000, `DMA_BEGINALIGNMENT` 16, `NDMAHDR` 10, 필드 오프셋 22 개가 §543 배치(0x0…0xf4)와 모두 같음.
- 5: python 확인 `m4-m68k-p544-checks-20261026.json`(`ok` 참; 07 = 스테이지 = 두 run 사본). 근거 `06_reconstruction/evidence/m68k-dma_h.md`, PROVENANCE 1136 → 1137 행, MODIFICATIONS 682 → 683 행, DECISIONS D119(122 → 123 행). 상태표는 바꾸지 않음(머리).
- 남은 일: `NDMAHDR` 의 1997 값은 바이트로 확인하지 않았습니다(`dma.c` 에서 볼 일). 다음은 `np.c` 의 남은 다섯 함수와 `dma.c`(행 212)입니다.

## 545. M4-51 세부 계획 — m68k `dma.c`(행 212) 첫 작성본 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유: 07 `nextdev/dma.h`(§544, D119)를 쓰는 가장 기본 단위입니다. `NDMAHDR` 는 `dma_list` 가 인수로 받을 뿐이라 여기서는 정해지지 않습니다(§545.1; 호출하는 드라이버에서 확인).

확인한 사실(이번 세션; 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt` 0x4066410–0x40678ce 1536 명령, 기호표, 원본 `__cstring`, python):
- 행 `m68k-212`(unassigned, 정확 경계) [0x4066410, 0x40678ce), 5310 B, 13 함수(합 5310 B, 이어짐; python): `dma_init` 182, `dma_close` 40, 이름 없는 정적 108(0x40664ee; 문자열로 `dma_prep`), `dma_enqueue` 130, `dma_dequeue` 56, `dma_list` 758, `dma_start` 1668, `dma_cleanup` 202, `dma_abort` 158, `dma_intr` 1300, `cache_flush` 174, `nitro_cache_flush` 294, `vcopy` 240.
- 참고 글: NeXTMach mk-108.1 `nextdev/dma.c`(863 행) 하나. 그 `dma_sync_cache`·`pcopy`·`pfill`·`dma_va_list`(`#if 0`)는 원본에 없고(기호표 0 건), `cache_flush`·`nitro_cache_flush`·`vcopy`·`dma_prep` 는 어느 참고 트리에도 정의가 없음(`01_resources`·`07_kernel` grep). NeXTMach 판은 07 머리에서 빠진 멤버 `dc_sectchain` 을 써서(NeXTMach `dma.c:610,669,696`) 07 머리로는 컴파일되지 않습니다(`DMACHAN_SECTCHAIN`·`DMADH_SECTCHAIN` 은 07 머리에 남아 있음; §545.1).
- `__cstring`(원본 0x40a9eeb–0x40aa03c, 337 B, 10 개): `dma_prep: bad DMA buffer alignment`, `dma_list: zero pfnum`, `dma_list: dma_list_t overflow`, `attempted DMA outside of memory space`, `dma_cleanup: negative resid`, `spurious DMA interrupt: channel 0x%x\n`, `spurious DMA interrupt: state 0x%x channel 0x%x\n`, `bad dma csr read, ddp=0x%x\n`, `dma_intr: DMA buffer not cache flushed`(코드에서 참조 0 건), `cache_flush: page not resident`.
- 자료: 정적 낱말 둘이 `__bss` 0x40b4f52·0x40b4f56(`nitro_cache_flush` 의 초기화 표시와 캐시 크기; 이름 없음 → bss 자리는 reference-inferred 후보, D113); 외부 `_cache`(`__data`), `_ncc_chip`(`__common`), `_dma_chip`·`_slot_id`·`_slot_id_bmap`·`_machine_type`·`_m68k_page_size`·`_m68k_page_mask`.
- 함수별 1997 동작(NeXTMach 대비):
  - 머리 매크로 `DMA_W`: 범위 검사는 `P_MAINMEM`·`P_MEMSIZE`(§510 `mem.c` 와 같은 식)이고 panic 문자열이 `attempted DMA outside of memory space`, 다시 쓰기 반복은 `dma_chip == 313` 일 때만(`do { reg = val; } while (dma_chip == 313 && reg != val)` 꼴). `get_dma_state` 는 NeXTMach 인라인과 같음(313: 0 이 아닐 때까지 읽고 `& 0xb000000`, 그 밖 `& 0x1b000000`).
  - `dma_init`: 플래그 지움(`andw #0x8fff`), `dd_csr = DMACMD_RESET` 만, `install_scanned_intr` 먼저, `dc_tail = (dc_tailbuf + 15) & -16`, 쪽 경계까지 남은 바이트가 `DMA_MAXTAIL`(128) 미만이면 `dc_tailalloc = kalloc(0x110)`·다시 16 으로 맞춤·그래도 모자라면 +0x80, `dc_ptail = pmap_resident_extract(pmap_kernel(), dc_tail)`, `dc_current = 0`.
  - `dma_close`: `dc_tailalloc` 이 있으면 `kfree(…, 0x110)` 하고 0.
  - `dma_prep(dcp, dhp)`(정적): `dh_flags & 1` 이 아니면 `dh_start & 15`, 맞으면 `dh_start & 3` 이 0 이 아니면 panic; `cache_flush(dh_start, dh_stop, dc_direction)`; `dh_flags |= 2`.
  - `dma_enqueue`: `dh_state = 0; dh_link = 0;` 다음 `(dc_flags & (AUTOSTART|BUSY|ERROR)) != AUTOSTART` 이면 `dma_prep` 먼저, 그 뒤 NeXTMach 와 같은 큐 넣기와 `dma_start`(`spldma` = `0x2600`).
  - `dma_dequeue`: NeXTMach 와 같은 흐름(`DMADQ_DONE` = 0).
  - `dma_list(dcp, fdhp, vaddr, bcount, pmap, direction, ndmahdr, before, after)`(인수 `secsize`·`rathole_va` 없음): 시작이 16 정렬이 아니면 §543 의 `DMACHAN_UNALIGNED`·`dc_align*` 설정과 `direction == 0`(쓰기)일 때 `vcopy` 둘; 페이지 순회에서 `sectchain` 없음, 정렬 안 된 경우 꼬리 버퍼 조각(`dc_alignrem`, `DMACHAN_PAD` 면 +0x20)을 마지막에 붙임; 이어 붙이기는 `dma_chip == 313` 이고 길이 < 0x2000 일 때만; 끝 처리는 `DMACHAN_UNALIGNED` 가 아닐 때, 읽기 판정은 `direction == 0x40000`; 넘침 검사는 `(dhp - fdhp) >= ndmahdr`(28 B 나눗셈 곱수 `0xb6db6db7`); `fdhp->dh_flags = 4`, `dma_chip == 313` 이고 `dc_ddp == P_PRINTER_CSR`(slot + 0x2000090) 이면 `|= 1`.
  - `dma_start`: `dc_direction` 저장, 사슬의 모든 `dhp` 에 `dma_prep`, `spldma`; 313: `dd_csr = RESET|direction`, `dh_flags & 4` 면 `dd_next_initbuf` 아니면 `dd_next`; 그 밖: `dd_csr = direction | (dh_flags & 4 ? 0x900000 : RESET)`, `dd_next`; `dd_limit`; `DMACHAN_ENETX` 면 313 은 `dd_saved_next`·`dd_saved_limit`, 그 밖은 `dd_start`; 313 이 아니고 `DMACHAN_ENETR` 면 `P_ENETX_CSR`(slot + 0x2000110) 채널의 `dd_stop` 에 `dh_start`; 나머지는 NeXTMach 와 같은 사슬 시작(`0x30000`·`CHAINING`, 또는 `SETENABLE`), `BUSY`, `splx`. `DMA_W` 펼침이 대부분입니다.
  - `dma_cleanup`: §543 의 `DMACHAN_UNALIGNED` 되돌림(`min`·`vcopy` 둘, `dc_direction` 이 0 이 아니면 `resid` 를 뺌) 또는 NeXTMach 의 `bcopy`(`dc_taillen > resid`).
  - `dma_abort`: `BUSY` 면 `dc_state = get_dma_state`, `dc_next = dd_next`, `dc_current` 가 있으면 그 `dh_state = get_dma_state`·`dh_next = dd_next`(NeXTMach 는 `dc_current->dh_next` 만); 그 뒤 `dd_csr = RESET`(NeXTMach 의 RESET 이 `dc_next` 읽기 앞이던 순서가 바뀜), 플래그 지움.
  - `dma_intr`: `BUSY` 가 아니거나 `dc_current == 0` 이면 `printf("spurious DMA interrupt: channel 0x%x\n", ddp)` 와 RESET; 상태가 SINGLE·CHAINING 이면 다시 읽고 그래도면 `printf(state, ddp)` 후 return, 아니면 `printf("bad dma csr read…")`(NeXTMach `#ifdef DEBUG` 덩이가 늘 켜진 꼴); `1STDONE` 처리에서 `ENETR` 면 `dh_next` 를 313 은 `dd_saved_limit`, 그 밖은 `P_DISK_CSR`(slot + 0x2000050) 채널의 `dd_next` 에서; 다음 `dhp` 의 `dh_flags` 를 읽지만 쓰지 않음(문자열 `dma_intr: DMA buffer not cache flushed` 만 남음); `sectchain`·`event_meter` 없음; `softint_sched` 대신 `callout_dispatch`(원본에는 `_softint_sched` 도 있음); 끝의 `ENETR` 이고 313 이 아니면 `dh_next = dd_next + (P_ENET(slot_id_bmap + 0x2006000) 의 바이트 7 | -16)`; 자동 시작 조건은 `(dma_chip == 313 || !(state & BUSEXC)) && (dc_flags & AUTOSTART) && (ndhp = dhp->dh_link) != 0`(§545.1); `srtoipl`·`SPLD_MACRO` 부분은 NeXTMach 와 같은 꼴.
  - `cache_flush(start, stop, direction)`: 313 이면 두 주소 `& 0x3fffffff`; 쪽 단위로 `pmap_resident_extract(pmap_kernel(), va)`(0 이면 panic), `direction == 0` 이면 `cache_push_page`, 아니면 `cache_inval_page` 와 `ncc_chip` 이면 `nitro_cache_flush(pa, len)`.
  - `nitro_cache_flush(pa, len)`: `cache` 가 0 이면 끝; 처음 한 번(정적 표시) `slot + 0x2210000` 레지스터가 `& 0x11e` 이 0 이면 크기 0x20000 과 레지스터에 0x10c 쓰기, 아니면 다시 읽어 `& 0x18` 로 크기(0→0x10000, 8→0x20000, 0x10→0x40000, 0x18→0x80000)를 정하고, `slot + 0x3e00000` 줄을 크기만큼 32 B 씩 지운 뒤 레지스터를 다시 읽어 `| 1` 로 씀; 그 뒤 `(pa & (size - 1))` 부터 32 B 줄 `(len + 31) >> 5` 개를 지움(§545.1).
  - `vcopy(src_va, src_pmap, dst_va, dst_pmap, len)`: `dst < src` 이면 앞에서, 아니면 뒤에서 쪽 단위로 `pmap_resident_extract` 두 번과 `bcopy`.

방법(진단; 명세 `08_build/artifacts/m4p545/spec.json`, run `m4p545-p1`, 바탕 `m0p544-a1-stage`, `m4_id` `m68k-212`, 컴파일 줄 틀 `machdep/i386/dkbad.c`(§496)):
- 변형 A1(`08_build/artifacts/m4p545/src/dma_A1.c`, 07 아님): 위 사실로 쓴 첫 작성본. 짜임·주석·남는 줄은 NeXTMach `nextdev/dma.c`, include 는 D104 경로(`<m68k/cpu.h>` 등), `P_MAINMEM`·`P_MEMSIZE`·`P_*_CSR`·`P_ENET` 는 파일 안 매크로(§510·§526 과 같은 식), 1997 `DMA_W` 는 진단을 위해 파일 안에서 `#undef` 뒤 다시 정의(07 머리를 고칠지는 결과 뒤 사용자께 여쭘), 정적 둘은 진단 이름. NeXTMach 판(N)은 위 이유로 컴파일하지 않습니다.
- 측정: `m4_m68k_probe.py compare`(경고 0 단언 없이 기록), `m68k_funcbytes.py 4066410 40678ce`(대응 `40664ee=_dma_prep`·정적 둘), `__cstring` 10 개·순서, bss 크기, COMMON·미정의 기호가 원본에 있는지.
- 더함(§545.1): 길이가 다른 함수는 `m68k_funcbytes.py` 가 바이트를 비교하지 않으므로 실기 `otool -tv` 와 `m4_m68k_probe.py funcs` 로 명령 단위 비교를 기록; 객체 함수 순서·외부/지역(`dma_prep` 지역)을 원본 순서와 python 으로 대조; 섹션별 크기(`__data`·`__const` 가 없음), 정의 기호·COMMON 이름과 크기를 python 으로 확인; `refs` 없는 `compare` 는 관문을 단언하지 않으므로 관문 값은 python 으로 따로 확인.

판정(미리 정함; 07 은 바꾸지 않음):
- 함수별로 같음/다름을 적고, 다른 함수는 차이(길이·첫 차이 자리)를 기록해 다음 계획에서 꼴을 바꿔 시험합니다. 13 함수가 모두 같아지기 전에는 07 을 만들지 않습니다.
- `dma_intr` 의 쓰이지 않는 문자열과 `dh_flags` 읽기, 바이트로 정해지지 않는 이름(`dma_prep` 말고 정적 둘, 0x900000 의 이름, 0x1·0x2·0x4 `dh_flags` 비트 이름)은 결과와 함께 사용자께 여쭙니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 545.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 오류: §543.2 에 `dma_list` 가 "본문을 `va + 0xe8` 에서 `va` 로 옮김" 이라 적었는데 방향이 반대입니다. 원본 0x40666b0–0x40666c6 의 둘째 `vcopy` 는 `(va, pmap, va + dc_alignoff, pmap, dc_alignlen)` 이고, `vcopy` 의 인수는 (src, src_pmap, dst, dst_pmap, len)입니다. codex 회신 전에 다시 읽다가 찾았고 codex 도 같은 지적을 했습니다. §543.2 를 고쳤습니다. 또 §545 에 "07 머리에서 빠진 `DMACHAN_SECTCHAIN`" 이라 쓴 것도 틀렸습니다(아래 첫 행).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `DMACHAN_SECTCHAIN`(07 `dma.h:198`)·`DMADH_SECTCHAIN`(`:65`)은 남아 있고 빠진 것은 멤버 `dc_sectchain` 뿐; NeXTMach `dma.c:610,669,696` 이 그 멤버를 씀 | 07 머리 65·198 행과 `grep sectchain` 읽음 | ✅ 제 오기. §545 문장을 고침 |
| `nitro_cache_flush`: `& 0x11e` 이 0 이면 크기 0x20000 과 레지스터에 0x10c 쓰기(0x40676e8–0x40676f2, 0x4067746–0x4067750), 줄 지운 뒤 레지스터 `\| 1`(0x406777e–0x4067792) | 원본 목록 0x40676b8–0x40677dc 읽음(`orl d4,d0` 의 d4 = 1) | ✅ 사실 줄에 더함(codex 의 "bit 1" 은 값 1 = 비트 0 입니다) |
| 자동 시작 조건에 `AUTOSTART` 와 다음 `dhp` 가 있는지도 들어감(0x4067514–0x406753c) | 원본 목록 읽음 | ✅ 고침 |
| `dma_list` 의 둘째 `vcopy` 방향은 `va` → `va + alignoff` | 원본 0x406668e–0x40666c6 읽음, `vcopy` 0x40677e6–0x40677fc 의 인수 사용 | ✅(위 제 오류) |
| `dc_alignlen` 의 16 맞춤은 음수를 0 쪽으로 자름(0x4066670–0x406667c) | 원본 읽음, python 으로 `((x+15) if x<0 else x) & -16` = `int(x/16)*16` 확인(-17→-16, -1→0) | ✅ §543.2 문장 고침 |
| "원본에 없음" 은 기호표만으로는 정적·인라인을 배제하지 못함 | — | ⚖️ 받음. 이 객체 범위를 다 읽어 별도 함수가 없음을 함께 근거로 듦 |
| `dma_init` 은 내장 버퍼 경로에서 `dc_tailalloc` 을 0 으로 두지 않음 | 원본 0x4066444–0x40664b8 읽음(0x38 쓰기는 `kalloc` 경로뿐) | ✅ 작성본에 반영 |
| `dma_prep` 은 비트 2 가 이미 서 있어도 건너뛰지 않음 | 원본 0x40664f6–0x406654a 읽음 | ✅ |
| `dma_list` 의 넘침 검사가 `fdhp->dh_flags = 4` 앞(0x40668ac–0x40668d4; NeXTMach 은 반대) | 원본 읽음 | ✅ 작성본에 반영 |
| 정렬 안 된 꼬리 조각은 `+0x20` 뒤 16 으로 올림(0x4066758–0x406677c) | 원본 읽음 | ✅ |
| `vcopy` 비교는 부호 없음(`bcc`), 같으면 뒤에서; 목적지 변환이 먼저(인수 오른쪽부터 평가), 변환 실패 panic 없음 | 원본 0x40677fa–0x406784e 읽음 | ✅ |
| `DMA_W` 꼴은 행동이 맞지만 추정한 글이며, 상한은 313·형 3 은 slot+0x6000000, 313 그 밖은 +0x8000000, 그 밖 칩은 +0xc000000(`& 0x0fffffff`) | 원본 0x4066a64–0x4066ac6·0x4066acc–0x4066ae0 읽음; §510 `mem.c:57` 식과 같음 | ✅ |
| 채널 주소(P_PRINTER·P_ENETX `dd_stop`·P_DISK `dd_next`·P_ENET 바이트 7) 모두 맞음 | 원본 해당 주소, NeXTMach `next/cpu.h:134,136,139,151` 읽음 | ✅ |
| `__cstring` 10 개 337 B, 순서 맞음; 0x40a9ff6 은 직접 참조 없음 | `strings.tsv:3241–3250` 읽음; python: 이진 파일에서 `040a9ff6` 0 건, `image.txt` 0 건 | ✅ 문구를 "직접 참조 0 건" 으로 둠 |
| `dma_intr` 0x40671fe 의 `dh_flags` 읽기는 버려짐(볼래타일 접근, 단언·panic 조건의 증거는 아님) | 원본 0x40671f0–0x4067202 읽음 | ✅ |
| `callout_dispatch`(`symbols.tsv:304`)와 `_softint_sched`(`:2701`) | 해당 줄 읽음 | ✅ |
| `m68k_funcbytes.py` 는 길이가 다르면 바이트 비교를 건너뜀(168–170 행)·이름으로 짝지음 | 도구 125–170 행 읽음 | ✅ 방법에 `otool`·`funcs` 비교와 함수 순서 대조를 더함 |
| probe 의 미정의 검사는 이름만(342 행), COMMON 은 기록만(363–364), `refs` 없으면 관문을 단언하지 않음(382–401) | 도구 해당 행 읽음 | ✅ 방법에 python 확인을 더함 |
| bss 후보 [0x40b4f52, 0x40b4f5a) 8 B; 크기만으로는 자리 증명이 아님(zerofill·겹침 절차와 D113 단서) | 원본 0x40676ca–0x406779e 읽음 | ✅ 07 단계에서 적용(이 진단은 크기만 봄) |
| `NDMAHDR` 는 `dma_list` 가 인수로 받을 뿐 이 객체로 정해지지 않음(0x40668bc) | 원본 읽음 | ✅ 첫 문장 고침 |
| `_cache` 는 외부 `__data`, `_ncc_chip` 은 `__common` | `symbols.tsv` 읽음(이번 세션) | ✅ |

### 545.2 진행(2026-10-29, 멈춤)

- 진단 작성본 A1 `08_build/artifacts/m4p545/src/dma_A1.c`(§545·§545.1 사실대로; 이름 없는 값은 진단 이름 `DH_LONGALIGN` 0x1·`DH_FLUSHED` 0x2·`DH_INITBUF` 0x4·`DMACSR_X800000`·`NITRO_*`, 정적 `nitro_init`·`nitro_size`, `dma_intr` 의 버려지는 읽기는 `(ndhp->dh_flags & DH_FLUSHED) == 0 && dma_debug`(0) 꼴로 시험)와 명세 `spec.json` 을 썼고, 스테이지 `m4p545p1-stage`(926 파일, 바탕 + 1)와 run `m4p545-p1`(명령 2)을 준비했습니다.
- 실행은 못 했습니다: `kr_run.py launch` 가 "launch failed"(gcds `next: no response`). 실기는 ping·telnet(23)·gcdsd(9910) 모두 응답이 없습니다(2026-10-29). 재부팅·데몬 기동은 사용자 몫이라(AGENTS.md) 여기서 멈춥니다. run `m4p545-p1` 은 대상에서 시작되지 않았으므로, 실기가 돌아오면 같은 ID 로 `launch` 부터 이어 갑니다.

### 545.3 결과(2026-10-29)

- 실기 환경(재부팅 뒤): 호스트 gnfsd 는 사용자가 기동(`sudo ./tools/serve-src.sh`), `nx-mount.sh` 로 `/ndrv` 마운트, `nx-daemon.sh start` 로 gcdsd 기동, `gcds` 응답·`cc` 확인.
- run `m4p545-p1`(A1): 종료 0·경고 0, `__text` 5308 B, 13 함수 중 8 개 같음(`dma_init`·`dma_close`·`dma_prep`·`dma_enqueue`·`dma_dequeue`·`dma_cleanup`·`dma_abort`·`cache_flush`). 다른 다섯은 실기 `otool -tv` 로 명령 단위 비교(§545.1 의 방법 보완).
- 꼴 시험(모두 07 아님, `08_build/artifacts/m4p545/src/`; 기록 `09_validation/reconstruction/m4-m68k-probe-p545-p2…p9-20261029.json`, 함수별 `08_build/artifacts/m4p545/fb-*`):
  - run `m4p545-p2`(B1–B6): `vcopy` 는 `if (src > dst)` 로, `dma_start` 는 `P_ENETX_CSR` 채널 쓰기를 `volatile` 없는 `(struct dma_dev *)` 로 맞음(B4, 10/13).
  - run `m4p545-p3`(C1–C6): `dma_intr` 는 P_ENET 의 바이트 7 을 `u_char` 구조체 필드(변위 7)로, `nitro_cache_flush` 는 `if (CSR & 0x11e) switch (u_int) { case 0x18 … case 0x00 } else { … }` 와 지역 변수 `off`·두 루프에 같은 `i` 로 맞음(C1, 12/13).
  - run `m4p545-p4`–`p8`(D·E·F·G, 각 6 개)과 `m4p545-p6`(선언 순서 순열 120 개): `dma_list` 만 남음. 선언 순서는 영향 없음(120 개 모두 756/758). G1 에서 `dcp->dc_alignrem = during - dcp->dc_alignlen;` 과 `vcopy(…, dcp->dc_alignrem)` 이 원본의 레지스터 흐름(`subl d0,d4; movel d4,d0`)과 같아짐.
  - run `m4p545-p9`(H1–H6): **H3**(G1 + `dcp->dc_alignlen -= dcp->dc_alignlen % DMA_ENDALIGNMENT;`)가 13/13 같음. 나머지 다섯은 아님.
- H3 판정(run `m4p545-p9`, probe 기록 위): 종료 0·경고 0, `__text` 5310 B·`full_span` 참, L1 사유는 `__DATA,__bss: unverified` 하나(`provisional`), 원본에 없는 미정의 0, 빠진·남는 이름 0, `__cstring` 337 B 가 원본 0x40a9eeb–0x40aa03c 와 바이트로 같음(쓰이지 않는 `dma_intr: DMA buffer not cache flushed` 포함; `(ndhp->dh_flags & DH_FLUSHED) == 0 && dma_debug`(0) 꼴), `__bss` 8 B(정적 둘 +0·+4 = 원본 0x40b4f52·0x40b4f56 의 거리), 지역 기호 `_dma_prep`·정적 둘, COMMON `_master_cpu` 4 B(머리에서; 원본에 있음).
- 판정(미리 정한 대로): 13 함수가 모두 같아졌으므로 07 꼴을 정할 수 있습니다. 바이트로 정해지지 않는 것은 사용자께 여쭙니다(§545 판정): `DMA_W` 의 1997 꼴을 07 `dma.h` 에 둘지, `dh_flags` 비트 0x1·0x2·0x4 와 0x800000·정적 둘·P_ENET 바이트 7 의 이름, `dma_intr` 의 죽은 검사 꼴.
- 원본의 다른 근거(이번 세션, 원본 목록): 원본 `en` 이 `dh_flags` 에 4(`_enattach` 0x408de60, `_en_rx_grabbufs` 0x408e086, `_en_rx_dmaintr` 0x408e458)와 5(`_enstart` 0x408e73e)를 씁니다. 1997 머리의 INITBUF 가 0x4 이고 0x1 은 SDK `dev/m68k/dma.h` 주석의 "sound and enet tx channels support long alignment" 에 맞는 표시로 봅니다(바이트: `dma_prep` 의 4 B 정렬 검사, `dma_list` 의 printer 채널).
- 사용자 결정(2026-10-29, AskUserQuestion): ① "07 dma.h 를 1997 값으로": `DMA_W` 의 1997 꼴과 `DMADH_INITBUF` 0x4·새 비트 0x1·0x2 를 07 `nextmach/nextdev/dma.h` 에 둠 ② "뜻을 담은 이름": `DMADH_LONGALIGN` 0x1, `DMADH_FLUSHED` 0x2, `DMACSR_INITBUF_TURBO` 0x800000, 정적 `nitro_init`·`nitro_size`, P_ENET 바이트 7 은 파일 안 구조체 필드 `en_x7`(u_char), `NITRO_CSR`·`NITRO_CACHE` ③ 죽은 검사는 "다른 꼴도 시험" 뒤 다시 여쭘(§546).

## 546. M4-52 세부 계획 — `dma_intr` 의 죽은 검사 꼴 진단(07 변경 없음; 코딩 전, 2026-10-29)

사용자 지시(2026-10-29): 죽은 검사(쓰이지 않는 문자열 `dma_intr: DMA buffer not cache flushed` 와 버려지는 `dh_flags` 읽기)를 내는 다른 꼴도 시험.

확인한 사실: H3 의 꼴 `if ((ndhp->dh_flags & DH_FLUSHED) == 0 && dma_debug) panic(…);`(`#define dma_debug 0`)이 원본과 같음(§545.3). 원본은 0x40671fe 에서 `ndhp->dh_flags`(volatile)를 읽고 버리며, 문자열은 `__cstring` 에 남고 직접 참조 0 건(§545.1). 스테이징에서 `ASSERT` 정의를 찾음(이번 세션 grep 결과를 결과 절에 적음).

방법(진단; 명세 `08_build/artifacts/m4p545/spec-p10.json`, run `m4p545-p10`, 바탕 `m0p544-a1-stage`): H3 에서 그 한 문장만 바꾼 변형.
- K1 `… == 0 && 0)`(숫자 0 직접), K2 `!(ndhp->dh_flags & DH_FLUSHED) && dma_debug`, K3 `(ndhp->dh_flags & DH_FLUSHED) == 0 && DEBUG_X`(머리 값 없는 이름을 `#if` 없이 `#define DEBUG_X 0`), K4 `if (dma_debug && (ndhp->dh_flags & DH_FLUSHED) == 0)`(대조: 읽기가 사라질 것으로 예상), K5 `static int dma_debug;`(변수, 대조: 메모리 읽기가 생길 것으로 예상), K6 `if (((ndhp->dh_flags & DH_FLUSHED) == 0) & 0)`(비트 and).
- 측정: `m68k_funcbytes.py`(13/13 여부), `__cstring` 바이트가 원본과 같은지, `__bss`·기호.
판정(미리 정함): H3 와 함께 13/13·`__cstring` 같음·`__bss` 8 B 인 꼴을 모두 적고 사용자께 여쭙니다. 하나뿐이면 그 꼴을 결과와 함께 알립니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 546.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| H3 의 꼴은 `dma_H3.c:56`(`#define dma_debug 0`)·`:458`(검사) | 두 줄 읽음 | ✅ |
| 원본 0x40671fe 의 `movel a2@(0xc:w),d0` 뒤 그 값은 검사되지 않고 0x4067202 에서 `d1` 로 주소 검사가 시작됨(`image.txt:130815`) | 해당 줄 읽음 | ✅ |
| K4 는 단락 평가로 읽기가 사라짐; K6 의 비트 `&` 는 피연산자를 평가함; K5 의 변수 읽기 여부는 컴파일러 결과로만 정할 일 | C 의미(단락·volatile)로 확인 | ✅ K5 의 기대를 "관찰만" 으로 고침 |
| K5 는 기존 `#define dma_debug 0` 을 없애야 함(남기면 `static int 0;`) | H3 56 행 확인 | ✅ K5 는 그 정의를 바꿔 씀 |
| 문자열 유지는 따로 재야 함; K4 는 읽기는 없어도 문자열이 남을 수 있음 | — | ✅ 모든 변형에 `__cstring` 비교와 그 문자열을 가리키는 재배치 0 건 확인을 더함 |
| 더 시험할 꼴: K7 `if (A) { if (0) panic(S); }`, K8 `if (0) { if (A) panic(S); }`(읽기 사라짐 예상), K9 메시지를 받는 매크로 `DMA_ASSERT(e, msg)`(`do { if (!(e) && DMA_DEBUG) panic(msg); } while (0)`) | — | ✅ 더함(K9 는 역사적 글이 아닌 가설 꼴로 적음) |
| 스테이징 `ASSERT` 는 꺼져 있으면 아무것도 남기지 않고, 켜지면 다른 문자열(`assertion failed` 등)을 남김; 스테이징 `MACH_ASSERT` 는 0 | `kern/assert.h:46–66`, `kernserv/prototypes.h:93–102`, `generated/mach_assert.h:1` 읽음 | ✅ ASSERT 는 이 꼴의 설명이 아님 |
| `m68k_funcbytes.py` 는 길이가 다르면 비교를 건너뜀(168–170 행) → 다른 변형은 실기 `otool -tv` 로 해당 자리의 명령(읽기 유무·검사·호출)을 기록 | 도구 168–170 행 읽음 | ✅ 방법에 더함 |
| 하나만 맞아도 "시험한 꼴 중 하나" 일 뿐 역사적 글의 증명이 아님; 마스크 값·조건 방향은 바이트에서 사라짐; bss 는 여전히 추정 | — | ✅ 판정 문장에 그대로 둠 |

### 546.2 결과(2026-10-29)

- run `m4p545-p10`(K1–K9, 18 명령 모두 종료 0·경고 0; probe 기록 `09_validation/reconstruction/m4-m68k-probe-p546-20261029.json`, 측정 `m4-m68k-p546-forms-20261029.json`). 측정: `m68k_funcbytes.py`, `__cstring` 337 B 가 원본과 같은지, `__text` 재배치 중 그 문자열 주소를 가리키는 것의 수, `__bss` 크기, 실기 `otool -tv` 의 `dma_intr` 에서 `movel a5@,a2` 뒤 다섯 명령.
- 원본과 같은 꼴(13/13, 버려지는 `movel a2@(0xc:w),d0`, 문자열 같음·참조 0, bss 8 B): H3(`A && dma_debug`, `#define dma_debug 0`), K1(`A && 0`), K2(`!(flags & DH_FLUSHED) && dma_debug`), K3(`A && DEBUG_X`), K6(`(A) & 0`), K7(`if (A) { if (0) panic(…); }`), K9(`DMA_ASSERT(e, msg)` = `do { if (!(e) && DMA_DEBUG) panic(msg); } while (0)`). 여기서 A = `(ndhp->dh_flags & DH_FLUSHED) == 0`.
- 대조(예상대로 다름): K4(`dma_debug && A`)·K8(`if (0) { if (A) … }`)는 읽기가 사라져 `dma_intr` 1296 B; K5(`static int dma_debug;`)는 `btst #1` 검사와 문자열 참조 1 건, bss 12 B, `dma_intr` 1328 B.
- 판정(미리 정한 대로): 같은 바이트를 내는 꼴이 일곱이라 사용자께 여쭙니다. 어느 것도 역사적 글의 증명은 아닙니다(마스크 값·조건 방향은 바이트에서 사라짐; §546.1).
- 사용자 결정(2026-10-29, AskUserQuestion): 죽은 검사는 "이름 있는 0 매크로"(H3: `if ((ndhp->dh_flags & DMADH_FLUSHED) == 0 && dma_debug) panic(…);`, 파일에 `#define dma_debug 0`).

## 547. M4-53 D120 구현 계획 — 07 `src/machdep/m68k/dma.c` 와 07 `nextdev/dma.h` 의 1997 값(코딩 전, 2026-10-29)

확인한 사실(이번 세션): 스테이징에서 `DMADH_*` 나 `nextdev/dma.h` 를 쓰는 파일은 그 머리 하나뿐(grep: `src/bsd/nextdev/dma.h` 1 건), §524 의 `np_B.c` 도 `DMADH_*` 를 쓰지 않음(grep 0). 07 머리의 `DMA_W` 는 NeXTMach 처럼 `P_MAINMEM`·`P_MEMSIZE` 를 쓰기만 하고 정의하지 않음(`dma.h:96–97`).

1. 07 `nextmach/nextdev/dma.h`(D119 판을 고침, 표시 `plan 547`):
   - `DMA_W` 를 1997 꼴로: panic 문자열 `attempted DMA outside of memory space`, `do { (reg) = (val); } while (dma_chip == 313 && (reg) != (val));`. `P_MAINMEM`·`P_MEMSIZE` 는 NeXTMach 처럼 쓰는 파일이 정의함(머리에 두지 않음; §510 `mem.c`·§526 `autoconf.c` 와 같은 식을 `dma.c` 에).
   - `dh_flags` 비트: `DMADH_LONGALIGN` 0x0001, `DMADH_FLUSHED` 0x0002, `DMADH_INITBUF` 0x0004(1990 0x0001); 1990 `DMADH_SECTCHAIN` 0x0002 는 값이 겹치고 1997 에 없으므로 뺌(머리 주석에 적음). `DMACHAN_SECTCHAIN` 은 근거가 없어 그대로 둠(D119).
   - csr 비트에 `DMACSR_INITBUF_TURBO` 0x00800000 을 더함.
   - 머리 주석의 plan 544 문단에 plan 547 바뀜을 이어 적음.
2. 꼴 L(`08_build/artifacts/m4p547/src/dma_L.c`) = H3 에서 진단 이름을 머리 이름으로(`DH_LONGALIGN`→`DMADH_LONGALIGN`, `DH_FLUSHED`→`DMADH_FLUSHED`, `DH_INITBUF`→`DMADH_INITBUF`, `DMACSR_X800000`→`DMACSR_INITBUF_TURBO`)·파일 안 `#undef DMA_W` 덩이와 진단 비트 정의를 빼고 진단 머리 주석을 뺀 글. 07 머리로 컴파일해 H3 와 같은 객체(canon·`obj_sig`)인지 확인.
3. 07 `src/machdep/m68k/dma.c`(D103) = NeXTMach `nextdev/dma.c` 의 첫 줄 고지와 HISTORY 를 그대로 두고, 본문은 L(이 프로젝트가 원본 바이트로 쓴 1997 본문, D024; 함수마다 NeXTMach 에서 온 줄과 바이트로 쓴 줄을 머리 주석으로 구분) + 주석. 주석을 뺀 토큰 = L.
4. `stage_m68k.py`: `M4FILES[547]` = 542 + `dma.c`, `M4HEADERS[547]` = 544, `EXCEPTS[547]` = 544. 회귀: `--plan 542` 재생성 = `m0p542-a1-stage`; `--plan 544` 재생성은 머리 SHA 하나만 다름(이번 머리 고침, 예상); `--plan 547 stage` 와 `--plan 544` 재생성의 차이는 `dma.c` 하나. M5 205 줄 회귀(§544 절차: `m0p544-a1-stage` 대 `m0p547-a1-stage`).
5. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시, `--plan 547 x86gate`).
6. 확인 run `m4p547-p1`(F = `@machdep/m68k/dma.c`, L, 그리고 §524 `np_B.c` 를 새 머리로 B5): F·L `provisional`(사유 bss 하나), canon·`obj_sig` 같음, H3 와 같음, 13/13; B5 는 §544 B4 와 canon·`obj_sig`·경고 줄(경로 이름 빼고)이 같아야 함(§547.1). run `m4p547-e1`: `-E` 토큰 F = L.
7. 최종 run `m4p547-a1`(REF = L, `bss_inferred` [`dma`]): `gate.ok`; `m5_m68k_zerofill.py`(후보 [0x40b4f52, 0x40b4f5a), 정적 `nitro_init` +0·`nitro_size` +4)와 받아들인 모든 배치와의 겹침 0(python); python 확인: 섹션 `__text` 5310·`__cstring` 337(원본과 같음)·`__bss` 8, 외부 정의 = 원본 이름 12 개, 지역 `_dma_prep`, COMMON 은 `_master_cpu`, 원본에 없는 미정의 0, 그 문자열 참조 0, 입력 사슬(07 = stage = run), i386 머리 0.
8. 기록: 근거 문서 먼저(`m68k-dma.md`; `m68k-dma_h.md` 에 plan 547 바뀜 덧붙임), diff(`m68k-dma.diff` NeXTMach 대비, `m68k-dma_h.diff` 다시 만듦), 상태표(CODE+BSS_INFERRED; 두 번 실행 같음, 기존 20 행은 이름으로 대조해 그대로 — 주소순이라 `dma` 는 `bus` 뒤 넷째 행; §547.1), PROVENANCE(`dma.c` 새 행, `dma.h` 행은 그 자리에서 고침), MODIFICATIONS, DECISIONS D120, M7 의무(bss 배치, `_cache`·`_ncc_chip`·`_slot_id_bmap` 등 정의 객체).
관문: 명령 종료 0, F·L 경고 0(B5 는 B4 와 같은 경고 줄), i386 머리 0, 회귀 같음(M5 포함), x86 입력 불변.

### 547.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상태 도구는 주소순으로 정렬(`m4_m68k_status.py:126`)하므로 "앞 20 행 그대로" 는 위치로는 성립하지 않음; `dma`(0x4066410)는 `bus`(행 211)와 `mem`(행 227) 사이 | 도구 126 행, 상태표 5·6 행 읽음 | ✅ 이름 대조로 고침 |
| B5 는 진단 `np_B.c` 라 경고 6 줄이 있음 → 경고 0 관문은 F·L 에만, B5 는 B4 와 같은 경고 | §544.2 기록 | ✅ 고침 |
| `np_B.c` 는 `DMA_W`·`DMADH_*` 를 쓰지 않으므로 B5 는 B4 와 같아야 함(받아들임 조건) | `np_B.c` grep 0(이번 세션) | ✅ 고침 |
| H3 의 진단 정의(39–42 행)·`DMA_W`(46 행 이후)를 머리로 옮겨도 펼침이 같음; `P_MAINMEM`·`P_MEMSIZE`(30–31 행)는 쓰일 때 펼쳐지므로 머리 뒤 정의로 됨; 파일 안 `#undef DMA_W` 를 남기면 머리 정의가 사라지므로 덩이째 뺄 것 | H3 19·30–31·39–46 행 읽음 | ✅ 2 의 "덩이를 뺌" 그대로; 펼침 같음은 L 컴파일(H3 와 canon 같음)로 확인 |
| 메모리 매크로를 `dma.c` 에 두는 것은 D107·D113 과 `mem.c:54`·`autoconf.c:76` 선례에 맞음 | 해당 줄(이번 세션 grep) | ✅ |
| 스테이징에서 `DMADH_`·`nextdev/dma.h` 를 담은 파일은 머리 하나 | 이번 세션 grep 1 건 | ✅ |
| `en` 의 `dh_flags` 쓰기 네 곳(0x408de60 4, 0x408e086 4, 0x408e458 4, 0x408e73e 5)이 맞고, 나중 `_enstart` 는 `DMADH_INITBUF | DMADH_LONGALIGN` 이 필요 | 원본 0x408de5e·0x408e084·0x408e456·0x408e73c 의 `moveq` 와 앞 python 검색(`movel …,aN@(0xc:w)`) | ✅ (codex 의 `image.txt` 줄 번호는 `moveq` 줄이며 저장은 그다음 줄) |
| `--plan 544` 재생성의 머리 SHA 차이는 예상; 역사 스테이지는 보존; PROVENANCE 의 머리 행(1137 행)은 그 자리에서 SHA·바뀐 매크로·새 확인을 고치고 D119 결과와 구분 | PROVENANCE 1137 행 읽음 | ✅ 8 그대로 |

### 547.2 결과(2026-10-29)

- 1: 07 `nextmach/nextdev/dma.h` 233 → 240 행(SHA-256 `d0fb71f0…`), 바뀐 줄은 모두 `plan 547` 표시.
- 2–3: 꼴 L(`08_build/artifacts/m4p547/src/dma_L.c`) = H3 에서 진단 이름 8 곳·0x800000 이름 1 곳을 머리 이름으로 바꾸고 파일 안 `DMA_W` 덩이·진단 비트·`dbug` 정의를 뺀 글(+ NeXTMach 2 행 `#define CHAIN_READ 0`). 07 `src/machdep/m68k/dma.c`(709 행, SHA-256 `d0bd7144…`)는 주석을 뺀 토큰 4073 개와 지시문 줄이 L 과 같음.
- 4: `stage_m68k.py` 657 → 660 행. `--plan 542` 재생성 = `m0p542-a1-stage`(모든 키); `--plan 544` 재생성은 `src/bsd/nextdev/dma.h` 하나만 다름(예상); `m0p547-a1-stage`(926 파일)와의 차이는 `src/machdep/m68k/dma.c` 하나. M5 205 줄: run `m3p547-b544`·`m3p547-cc1` 각 205 명령 종료 0, 205 객체 바이트 같음, stderr 205 개 같음(비어 있지 않은 것 52), `compare`(`m3-m68k-p547-compare-20261029.json`, `-b544-`) `differ_unexpected`·`lost` 빔, 요약 같음.
- 5: x86 입력 불변(`m4-x86-inputs-p547-20261029.json` ok; `--plan 547 x86gate` 일곱 묶음 같음, v183 경로 0; i386 07 변경 0).
- 6: run `m4p547-p1`(`m4-m68k-probe-p547-p1-20261029.json`): F·L 경고 0, `provisional`(사유 bss 하나), 13/13, F = L = H3(canon·`obj_sig`); np B5 = §544 B4(canon·`obj_sig`), 경고 6 줄 같음(`diag_gate.commands_ok` 는 이 경고 때문에 거짓). run `m4p547-e1`: `-E` 토큰 15095 개 F = L.
- 7: run `m4p547-a1`(REF = L `2b5db9f3…`, `bss_inferred` [`dma`]; `m4-m68k-p547-final-20261029.json`): `gate` 모두 참, 객체 SHA-256 `f65e3321…`. zerofill `m4-m68k-zerofill-p547-20261029.json`: `reference-inferred`, 후보 [0x40b4f52, 0x40b4f5a), 이전 배치 31 개와 겹침 0. python 확인 `m4-m68k-p547-checks-20261029.json`(`ok` 참; 항목은 근거 문서).
- 명세 자리: 상태 도구가 최종 명세를 `08_build/artifacts/m4p547/spec.json` 에서 읽으므로(§542 관례) 확인용 명세를 `m4p547/confirm/` 로, 최종 명세를 `m4p547/` 로 옮겼습니다(내용 같음, 두 기록의 `spec_sha256` 과 일치 확인). 처음 상태 도구를 인수 없이 불러 아무것도 쓰지 않고 끝난 일이 있었습니다(제 실수, 표 그대로).
- 8: 근거 `06_reconstruction/evidence/m68k-dma.md`(새), `m68k-dma_h.md`(plan 547 절 덧붙임), diff `m68k-dma.diff`(1098 행), `m68k-dma_h.diff`(다시 만듦, 116 행). 상태표 `m4-m68k-status-p547-20261029.json`: 21 객체(OBJECT_MATCH 17, CODE+BSS_INFERRED 4), 덮은 행 43/188, 24254/215874 B(11.24%), 두 번 실행 같음, 기존 20 행은 이름으로 대조해 그대로(`dma` 는 넷째 행). PROVENANCE 1137 → 1138 행(머리 행은 그 자리에서 고침), MODIFICATIONS 683 → 685 행, DECISIONS D120(123 → 124 행).
- 남은 일·M7: bss 배치; `_cache`·`_ncc_chip` 등 정의 객체; 다음 후보는 `np.c` 남은 다섯 함수, `en`(원본이 `DMADH_INITBUF | DMADH_LONGALIGN` 을 씀), `sd`·`od`·`fd`·`snd`.

## 548. M4-54 세부 계획 — `np.c`(행 233) 남은 다섯 함수와 머리 꼴 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유: §524 에서 멈춘 `np.c` 는 07 `dma.h`(§544·§547)로 37 함수 가운데 32 개가 같고(§547.2 B5 = §544 B4), 남은 다섯은 본문 바뀜입니다.

확인한 사실(이번 세션; 원본 목록, 기호표, 실기 `otool -tv` 로 B5(`08_build/artifacts/m4p548/otool/np_B5.txt`)와 명령 비교):
- 원본 다섯(진입점·크기): `np_setstate` 0x4072efa 212, `np_startdata` 0x4073532 272, `np_close` 0x4073aa6 106, `np_select_common` 0x407415e 166, `np_write` 0x4074204 1890. B5 는 각각 192·212·40·204·1884.
- 1997 바뀜(원본에서 읽음):
  - `np_select_common`: `sc_wsel`(0x11e)·`sc_esel`(0x122) 검사가 `if (selthreadcache(&sc->sc_wsel)) sc->sc_flags |= PF_WSELCOLL;`(쓰기)·`&sc->sc_esel`·`PF_ESELCOLL`(예외) 꼴(0x40741aa `pea a2@(0x11e)` + `bsr _selthreadcache` + `tstl d0`; NeXTMach 의 `wait_event == &selwait` 비교와 `current_thread()` 대입 없음). `_selthreadcache`(0x400c80a)는 07 x86 `sys_generic.c:500` 에도 있음.
  - `np_setstate`: PS_READY 에서 `selwakeup`·플래그 지움 뒤 `thread_deallocate_interrupt(sc->sc_wsel)`(0x4072f58), 그 뒤 `sc_wsel = 0`; PS_ERROR·PS_OFF 에서 `selwakeup(sc->sc_esel, …)`·플래그 지움 뒤 **`thread_deallocate_interrupt(sc->sc_wsel)`**(0x4072f90 `movel a2@(0x11e:w),sp@-` — `sc_esel` 이 아닌 `sc_wsel`), 그 뒤 `sc_esel = 0`. 원본 바이트 그대로 옮깁니다(뜻으로는 원본의 잘못으로 보이나 고치지 않음).
  - `np_close`: `s = splprinter();`(0x2300) 아래에서 `sc_wsel`·`sc_esel` 을 지역에 받고, `sc_flags &= ~PF_OPEN`(0x106, `& -3`), 둘을 0 으로, `splx(s)` 뒤 각각 0 이 아니면 `thread_deallocate(…)`(0x4052a96), `return 0`.
  - `np_startdata`: `np_send(np, NP_DATA_OUT, firstlword)` 뒤 `dh_start += 4` 는 `dma_chip == 313` 일 때만; `dma_start` 뒤 `lpr_csr_or` 를 0x20(`DMAOUT_OVR>>24`)·0x80(`DMAOUT_DMAEN>>24`)·0x20 순서로 세 번(NeXTMach: 0x80·0x20 두 번); `dma_chip != 313` 이면 네 번 `lpr_csr_or(0x01); delay(1);`(0x40735ce–0x40735ec; 0x01 은 NeXTMach `npreg.h` 비트필드에서 `dmain_ovr` 다음의 예약 비트 자리, 이름 없음); 그 뒤는 NeXTMach 와 같음.
  - `np_write`: DMA 목록 할당이 `kmem_alloc_wired(kernel_map, (vm_offset_t *)&sc->sc_dl, size)`(0x40744b4 `pea a3@(0xfc)` + `bsr _kmem_alloc_wired` 0x405d6cc, 반환값 버림); 다른 두 차이(0x40746be·0x40748c2 의 `addqw #8,sp`)는 이 3 인수 호출에 따른 스택 정리 합침으로 봅니다(결과로 확인).
- 머리: `np_B.c` 가 NeXTMach `next/cpu.h` 에서 쓰는 이름은 `I`·`I_PRINTER`(I(3,2,11))·`I_PRINTER_DMA`(I(6,5,24))·`P_PRINTER_CSR`(SLOT_ID+0x02000090)·`slot_id` 뿐이고 `next/scr.h` 의 이름은 쓰지 않습니다(python, 주석 뺀 글의 낱말과 두 머리의 정의 이름 교집합). 진단 머리 때문에 B5 에 원본에 없는 COMMON `_disk_chip`·`_scr1` 이 생깁니다(§524.1).

방법(진단; 명세 `08_build/artifacts/m4p548/spec.json`, run `m4p548-p1`, 바탕 `m0p547-a1-stage`, `m4_id` `m68k-233`, 대응 `4073b56=_np_ioctl_common_top`):
- C1 = `np_B.c`(§544 B4·§547 B5 의 `inc` 그대로: `np.h`·`nextdev/npio.h`·`nextdev/npreg.h`·`next/scr.h`, `nextdev/dma.h` 는 스테이징의 07 판; §548.1)에 위 다섯 함수의 1997 본문만 넣은 글. 새로 부르는 `selthreadcache`(int)·`thread_deallocate_interrupt`(void)는 들이는 머리에 선언이 없으므로 파일 안에 K&R 꼴 `extern` 선언을 둠(07 x86 `sys_generic.c:500`·`kern/thread.c:811` 의 정의와 같은 형); `thread_deallocate`·`kmem_alloc_wired` 는 이미 선언됨; `dma_chip` 은 C1 에서는 진단 `next/cpu.h`, C2 에서는 `<m68k/cpu.h>` 가 선언.
- C2 = C1 에서 `<next/cpu.h>`→`<m68k/cpu.h>`(D110)와 파일 안 `SLOT_ID`·`P_PRINTER_CSR`·`I`·`I_PRINTER`·`I_PRINTER_DMA`·`extern int slot_id;`(D107·D113 선례), `<next/scr.h>` 뺌.
- 측정: `m68k_funcbytes.py 40726d0 4074a6c`(37 함수), 다른 함수는 실기 `otool -tv` 명령 비교; COMMON 이름·크기가 원본 기호표에 있는지; `__data` 66 B·`__cstring` 바이트를 원본(`_np_copyright` 0x40b1bce 부터, 문자열 자리)과 비교; 경고 줄; i386 머리 0.
판정(미리 정함; 07 은 바꾸지 않음): C2 가 37/37 이고, 원본에 없는 COMMON 이 없고, `__data` 66 B(재배치 대상 포함, L1)·`__cstring` 531 B 가 원본과 같으면 07 꼴(`np.h`·`npio.h`·`npreg.h` 의 공급, 0x01 의 이름, 경고를 남기는 1990 글을 1997 머리에 맞출지)을 사용자께 여쭙고 구현 계획을 세웁니다. 아니면 차이를 적고 꼴을 더 시험합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 548.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 다섯 함수의 1997 바뀜이 모두 원본과 맞음(`selthreadcache` 0x40741aa–0x40741e8; ERROR/OFF 에서 0x4072f90 이 `sc_wsel` 을 넘기고 0x4072f9a 가 `sc_esel` 을 지움; `np_close` 0x4073ac0–0x4073b02; `np_startdata` 0x407358a–0x40735ec; `np_write` 0x40744b2–0x40744be) | 이번 세션에 원본 목록을 직접 읽음(위 사실 절) | ✅ |
| `np_write` 의 다른 두 차이는 재시도 가지(0x40744ce 로 가는)의 스택 정리 합침 | 원본 0x40746be·0x40748c2 와 B5 0x1d8e–0x1d90 읽음 | ✅ 결과로 다시 확인 |
| ERROR/OFF 의 `sc_wsel` 해제는 바이트 사실로 적고, "잘못" 은 추론으로만 둠; `thread_deallocate_interrupt` 는 NULL 을 받아들임(0x4052cba) | — | ✅ 문구를 "뜻으로는 원본의 잘못으로 보이나" 그대로 둠(추론임을 밝힘) |
| 필드 오프셋(`sc_dc` 0x4, `sc_dl` 0xfc, `sc_flags` 0x106, `sc_wsel` 0x11e, `sc_esel` 0x122, `sc_state` 0x126)과 `np_softc` 332 B; 원본 `np_probe` 가 0x14c 를 `bzero` 에 넘김(0x4074986) | 원본 0x4074986 읽음; 오프셋은 위 원본 명령들이 쓰는 값과 같음 | ✅ |
| 계획의 "§524 의 inc 그대로" 는 B2 의 `nextdev/dma.h` 1990 사본 별칭까지 뜻할 수 있어 틀림 → B4·B5 의 `inc`(그 별칭 없음) | `m4p524/spec-b2.json:30–31`, `m4p547/confirm/spec.json` 의 `dma.h` 0 건 | ✅ 제 문구 오류. 고침 |
| 받아들임 조건에 `__data`(재배치 대상 포함)·`__cstring` 확인을 넣을 것 | — | ✅ 고침. 미리 확인: B5 `__cstring` 531 B 가 원본 [0x40aa6e1, 0x40aa8f4) 와 같음(python); `__data` 원시 바이트는 재배치 칸 때문에 다르므로 L1 로 봄 |
| `selthreadcache`·`thread_deallocate_interrupt` 는 들이는 머리에 선언이 없음 | 07 `src` 의 `.h` grep 0 건; 정의 `sys_generic.c:500`(K&R, int)·`kern/thread.c:811`(void) 읽음 | ✅ 파일 안 K&R 선언을 둠(원형이 없어 `volatile` 한정자 문제도 없음) |
| `dma_chip` 의존이 새로 생김 | — | ✅ 적음 |
| COMMON 크기는 기호표 주소로 추정하지 말 것 | — | ⚖️ 받음: 원본에 그 이름이 있는지만 판정에 쓰고, 크기는 기록만 함 |
| 렉시컬 검사로는 `I(` 직접 호출이 없고 `I`·`SLOT_ID` 는 펼침에서 필요 | — | ✅ 사실 문구는 그대로(필요한 이름 목록은 같음) |

### 548.2 결과(2026-10-30)

- run `m4p548-p1`(C1·C2; 기록 `09_validation/reconstruction/m4-m68k-probe-p548-20261030.json`): 둘 다 종료 0, 경고 4 줄(1990 글의 `assert_wait((int)&…)` 둘·`thread_wakeup(&volatile …)` 둘; §524 의 포인터·정수 비교 두 줄은 `selthreadcache` 꼴로 사라짐), `__text` 9116 B, 36/37 — `np_setstate` 의 재배치 하나만 다름(원본 `_callout_dispatch`, 변형 `_softint_sched`; PS_NEEDSINIT 가지). C1 은 원본에 없는 COMMON `_disk_chip`·`_scr1`, C2 는 0. `__cstring` 531 B 는 둘 다 원본과 같음.
- run `m4p548-p2`(C3 = C2 + `softint_sched` → `callout_dispatch`(파일 안 K&R 선언); `m4-m68k-probe-p548-p2-20261030.json`): 37/37, L1 `OBJECT_MATCH`(`__data` 66 B 재배치 포함·`__cstring` 같음), `candidate`, 원본에 없는 COMMON·미정의 0, 지역 기호 `_np_ioctl_common_top` 하나. 경고는 위 4 줄.
- run `m4p548-p3`(C4 = C3 + 그 넷에 `(event_t)` 캐스트; `m4-m68k-probe-p548-p3-20261030.json`): 경고 0, `diag_gate` 참, 37/37, `OBJECT_MATCH`, C3 와 canon·`obj_sig` 같음.
- 판정(미리 정한 대로): C2 계열이 37/37·원본에 없는 COMMON 0·`__data`·`__cstring` 같음을 만족하므로 07 꼴을 사용자께 여쭙니다. `np_setstate` 의 ERROR/OFF 가지가 `sc_wsel` 을 해제하는 것은 바이트대로 둡니다.
- 사용자 결정(2026-10-30, AskUserQuestion): ① 경고 4 줄은 "1990 글 그대로 + known_warnings"(C3; §500 `vm_unix` 선례) ② 머리는 "npio.h 는 SDK 판": `np.h` 는 m68k 구성 생성 머리(`NNP 1`), `npio.h` 는 SDK `bsd/dev/m68k/npio.h` 사본(`<dev/m68k/npio.h>`, D116 `video.h` 선례), `npreg.h` 는 NeXTMach 사본(`07_kernel/nextmach/nextdev/`, D104) ③ 0x01 은 "숫자 그대로"(주석에 뜻 모름을 적음); `next/cpu.h` 이름은 파일 안 매크로(C2, D113 선례), `next/scr.h` 는 뺌.

## 549. M4-55 D121 구현 계획 — 07 `src/machdep/m68k/np.c`, 머리 둘, 구성 `NNP`(코딩 전, 2026-10-30)

확인한 사실(이번 세션): `NNP` 는 바이트가 1 로 정함(`np_select_common` 0x407417e `cmpw #0x1,d1` = `minor(dev) > NNP`). `np_probe` 의 `mulsl #0x14c`(0x4074976)·`bzero(…, 0x14c)`(0x4074986)는 구조체 한 칸 크기(332 B)를 보일 뿐 배열 전체 크기의 근거는 아님(§549.1). 로컬 SDK 사본 `../ref/openstep/headers/NextDeveloper/Headers/bsd/dev/m68k/npio.h` 의 SHA-256 `6e427136…` 은 실기 목록(`s4c-nextdev-headers-20261002.json`)과 같음. 구성 생성은 §517 절차(`gen_config_headers.py --arch m68k`, `--check`; 생성 머리는 모든 m68k 스테이징에 들어가므로 M5 205 줄 회귀). PROVENANCE 선례: `generated/od.h`(1118 행), `nextdev/bsd/dev/m68k/video.h`(1134 행). NeXTMach `np.c` 와 §524 `np_B.c` 의 차이는 include 줄 9 개(diff, 이번 세션).

1. 구성: `06_reconstruction/config_options-m68k.tsv` 에 `np NNP np.h 1 confirmed`(근거: 위 바이트; NeXTMach `conf/files.NeXT:51` `nextdev/np.c optional np`) 한 행을 덧붙이고 `gen_config_headers.py --arch m68k` 로 `07_kernel/v183.34/m68k/generated/np.h`(`#define NNP 1`)를 씀; `--check` 통과, 기존 m68k 생성 머리는 그대로.
2. 머리: `07_kernel/nextdev/bsd/dev/m68k/npio.h` = 로컬 SDK 사본 그대로(SHA 같음 확인), 스테이징 `src/bsd/dev/m68k/npio.h`(뿌리 `07_kernel/nextdev`); `07_kernel/nextmach/nextdev/npreg.h` = NeXTMach 그대로, 스테이징 `src/bsd/nextdev/npreg.h`.
3. 꼴 L(`08_build/artifacts/m4p549/src/np_L.c`) = C3 에서 `#import <nextdev/npio.h>` → `#import <dev/m68k/npio.h>`, 진단 주석을 뺀 글. 스테이징 머리만으로(`inc` 없이) 컴파일해 C3 와 canon·`obj_sig` 같음을 확인.
4. 07 `src/machdep/m68k/np.c`(D103) = NeXTMach `nextdev/np.c`(고지·HISTORY 그대로) + include 줄 D104 고침(§524 의 9 줄, `<dev/m68k/npio.h>`, `<m68k/cpu.h>`, `<next/scr.h>` 뺌) + 파일 안 `SLOT_ID`·`P_PRINTER_CSR`·`I`·`I_PRINTER`·`I_PRINTER_DMA`·`extern int slot_id;` + K&R 선언 셋(`callout_dispatch`·`selthreadcache`·`thread_deallocate_interrupt`) + 다섯 함수의 1997 바뀜(§548) + `np_setstate` 의 `callout_dispatch`; 바뀐 줄은 `plan 549` 표시, 머리 주석에 출처·ERROR/OFF 의 `sc_wsel` 해제가 원본 바이트대로임을 적음. 주석을 뺀 토큰 = L.
5. `stage_m68k.py`: `M4FILES[549]` = 547 + `np.c`, `M4HEADERS[549]` = 547 + (`nextdev/npreg.h`→`src/bsd/nextdev/npreg.h`) + (`bsd/dev/m68k/npio.h`→`src/bsd/dev/m68k/npio.h`, 뿌리 `07_kernel/nextdev`), `EXCEPTS[549]` = 547. 회귀: 보관된 `m0p547-a1-stage` 대 `--plan 547` 재생성의 차이는 생성 머리 `generated/np.h` 하나(모든 m68k 스테이징에 덧씌움); `--plan 547` 재생성 대 `m0p549-a1-stage` 의 차이는 `np.c`·머리 둘(§549.1). M5 205 줄 회귀(`m0p547-a1-stage` 대 `m0p549-a1-stage`).
6. x86 입력 불변(`L2_FORMS`/`L2_EXPECT`, `--plan 549 x86gate`; x86 구성 표는 바뀌지 않음).
7. 확인 run `m4p549-p1`(F = `@machdep/m68k/np.c`, L): 종료 0, stderr 는 C3 의 8 줄(경고 4 + 함수 줄 4)과 경로·줄 번호를 뺀 내용이 같음, 37/37, `OBJECT_MATCH`, F = L = C3(canon·`obj_sig`); run `m4p549-e1` `-E` 토큰 F = L.
8. 최종 run `m4p549-a1`(F 만 컴파일, REF = 확인 run 의 L 객체; `known_warnings["np"]` 는 확인 run 의 F stderr 8 줄 전체를 그대로 적음 — 도구는 경로·줄 번호까지 정확히 비교, `m4_m68k_probe.py:296,387`): `gate.ok`; python 확인: 섹션 `__text` 9116·`__data` 66·`__cstring` 531(원본 [0x40aa6e1, 0x40aa8f4) 와 같음), L1 `OBJECT_MATCH`, 외부 정의 = 원본 이름 36 개 + `_np_copyright`·`_npdriver`, 지역 `_np_ioctl_common_top`, COMMON 이름이 모두 원본 기호표에 있음(`_np_softc` 332·`_np_dinfo` 4 등, 크기는 기록만), 원본에 없는 미정의 0, 입력 사슬(07 = stage = run; 소스와 머리 셋), i386 머리·`next/cpu.h`·`next/scr.h` 0.
9. 기록: 근거 문서 먼저(`m68k-np.md`), diff(`m68k-np.diff` NeXTMach 대비), 상태표(OBJECT_MATCH; 두 번 실행 같음, 기존 21 행은 이름 대조), PROVENANCE(`np.c` nextmach+authored, `npreg.h` nextmach, `npio.h` nextdev-os42 license TBD D017, `generated/np.h` generated), MODIFICATIONS, DECISIONS D121, M7 의무(`_np_softc`·`_np_dinfo` COMMON 등).
관문: 명령 종료 0, F·L 의 stderr 는 정한 꼴뿐(최종 run 은 `known_warnings` 와 정확히 같음), i386 머리 0, 회귀 같음(M5 포함), x86 입력 불변.

### 549.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `known_warnings` 는 stderr 를 `splitlines()` 한 목록과 정확히 비교(경로·줄 번호·함수 줄·순서); C3 stderr 는 8 줄(경고 4) | 도구 294–298 행 읽음; p548-p2 기록에서 compile `err_lines` 8 줄·`warnings` 4 | ✅ 7·8 을 "8 줄 전체" 로 고침 |
| 허용은 객체 이름 단위라 F·L 을 한 run 에서 함께 관문에 걸 수 없음 → 최종 run 은 F 만, REF 는 확인 run 의 L(§547 꼴) | §547 최종 명세(`m4p547/spec.json`)가 F 하나·REF 꼴임 | ✅ 8 에 명시 |
| `NNP=1` 은 0x407417e `cmpw #0x1,d1` 로 직접 정해짐 → `confirmed` 가 표의 관례에 맞음; 그러나 `0x14c` 곱·`bzero` 는 한 칸 크기일 뿐 배열 전체 크기가 아님 | 원본 0x407417e·0x4074976·0x4074986 읽음, python `0x14c` = 332 | ✅ 사실 문장 고침 |
| 생성 머리는 모든 m68k 스테이징에 덧씌워지므로(`stage_m68k.py:504`) 회귀 차이를 정확히 적을 수 있음 | 도구 500–508 행 읽음(덧씌움 뿌리에 `generated/`) | ✅ 5 고침 |
| NeXTMach·SDK `npio.h` 는 include 가드와 빈 줄만 다름; SDK SHA = 실기 목록 | 앞서 SHA `6e427136…` 와 s4c 기록 대조(이번 세션); 내용 차이는 L 컴파일로 확인 | ⚖️ 사실은 받고 L 컴파일을 관문으로 둠 |
| `-Isrc/src/bsd` 로 `<dev/m68k/npio.h>` 가 풀리고 두 목적지는 비어 있음; M5 에 `np.h`·`NNP` 를 쓰는 곳 없음 | 이번 세션 grep(스테이징에 `npio.h` 없음; `NNP` 는 `np_C3.c` 만) | ✅ M5 회귀는 그대로 함 |
| m68k 생성은 `meta_features.h` 를 쓰지 않음(`gen_config_headers.py:63` `with_meta=False`) | 해당 행 읽음 | ✅ |
| PROVENANCE 는 `od.h`(1118)·`video.h`(1134) 꼴, 구성 표 자체의 행은 관례에 없음 | 두 행 읽음 | ✅ |

### 549.2 결과(2026-10-30)

- 1: `config_options-m68k.tsv` 11 → 12 행(`np NNP np.h 1 confirmed`), `gen_config_headers.py --arch m68k` 로 `07_kernel/v183.34/m68k/generated/np.h`(`#define NNP 1`)를 씀; `--arch m68k --check`·x86 `--check` 모두 종료 0, 생성 디렉터리의 새 파일은 `np.h` 하나(git).
- 2: `07_kernel/nextdev/bsd/dev/m68k/npio.h`(로컬 SDK 사본, SHA `6e427136…` 같음; 로컬 전용), `07_kernel/nextmach/nextdev/npreg.h`(NeXTMach 와 SHA 같음).
- 3–4: L(`08_build/artifacts/m4p549/src/np_L.c`) = C3 에서 `npio.h` include 와 진단 주석만 바꾼 글. 07 `src/machdep/m68k/np.c`(2864 행, SHA-256 `110e81c0…`)는 NeXTMach 원문에서 만들었고 주석을 뺀 토큰 11201 개와 지시문 줄이 L 과 같음.
- 5: `stage_m68k.py` 660 → 664 행. 보관 `m0p547-a1-stage` 대 `--plan 547` 재생성: `generated/np.h` 하나 더함; 재생성 대 `m0p549-a1-stage`(930 파일): `np.c`·`npreg.h`·`npio.h` 셋 더함. M5 205 줄: run `m3p549-b547`·`m3p549-cc1` 각 205 명령 종료 0, 205 객체 바이트 같음, stderr 205 개 같음(비어 있지 않은 것 52), `compare`(`m3-m68k-p549-compare-20261030.json`, `-b547-`) `differ_unexpected`·`lost` 빔, 요약 같음.
- 6: x86 입력 불변(`m4-x86-inputs-p549-20261030.json` ok; `--plan 549 x86gate` 일곱 묶음 같음, v183 경로 0).
- 7: run `m4p549-p1`(`confirm/spec.json`, 기록 `m4-m68k-probe-p549-p1-20261030.json`): F·L 종료 0, `OBJECT_MATCH`·`candidate`, 37/37, F = L = C3(canon·`obj_sig`), stderr 각 8 줄이 C3 와 경로·줄 번호를 뺀 내용이 같음. run `m4p549-e1`: `-E` 토큰 26577 개 F = L.
- 8: run `m4p549-a1`(F 만, REF = L `ab6c7794…`, `known_warnings["np"]` = 확인 run F 의 stderr 8 줄; `m4-m68k-p549-final-20261030.json`): `gate` 모두 참, 객체 SHA-256 `17ef20d1…`. python 확인 `m4-m68k-p549-checks-20261030.json`(`ok` 참; 항목은 근거 문서).
- 9: 근거 `06_reconstruction/evidence/m68k-np.md`, diff `m68k-np.diff`(192 행). 상태표 `m4-m68k-status-p549-20261030.json`: 22 객체(OBJECT_MATCH 18, CODE+BSS_INFERRED 4), 덮은 행 44/188, 33370/215874 B(15.46%; python 다시 계산 같음), 두 번 실행 같음, 기존 21 행은 이름 대조로 그대로. PROVENANCE 1138 → 1142 행(`np.c`·`npreg.h`·`npio.h`·`generated/np.h`), MODIFICATIONS 685 → 689 행, DECISIONS D121(124 → 125 행).
- §524(멈춘 절)는 이것으로 닫힙니다.
- 다음 후보: `en`(원본이 `DMADH_INITBUF | DMADH_LONGALIGN` 을 씀), `sd`·`od`·`fd`·`snd`, 행 305·306 나머지, 행 276, `tty_pty` 꼬리.

