# 커널 소스 복원 작업계획 — 보관 §437–457(§448 제외)

`02_plan/RECONSTRUCTION_PLAN.md` 의 §437–447·§449–457 을 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-15, D026 방식, 사용자 지시 “완료된 내용은 정리”). §448(`ns_timer`, 멈춤·사용자 결정 대기)은 끝나지 않아 본문에 남겼습니다. 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킵니다. 아래는 원문 그대로입니다.

---

## 437. M3-13 세부 계획 — m68k `_panic` 의 ROM Monitor 줄을 덮어쓰기 소스로 시험(x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §436 에서 m68k `_panic` 이 원본보다 30 B 짧은 원인 후보는 NeXTMach `bsd/subr_prf.c:515-516` 의 `printf ("NeXT ROM Monitor %d.%d v%d\n", mg->mg_major, mg->mg_minor, mg->mg_seq);` 입니다. 07 `subr_prf.c:543` 은 i386 원본에 맞춰(계획 220) 그 줄을 뺐습니다. 이것은 아키텍처 차이이므로 D068 덮어쓰기 트리에 둡니다.

확인한 사실(이번 세션, 읽기 전용):
- 원본 m68k `_panic`(0x400bc66)은 다음과 같이 동작합니다(§436 덩어리).
  - `movel @_mon_global,a3` 로 시작합니다.
  - `movew a3@(0x30c)`·`a3@(0x30a)`·`a3@(0x312)` 를 차례로 넣고 `printf` 를 부릅니다(문자열 0x40a62ad "NeXT ROM Monitor %d.%d v%d\n").
  - `moveml d2/a2/a3` 로 레지스터를 보존합니다.
- 원본 기호표에 `_mon_global`(0x40b69bc, section 6)이 있습니다.
- NeXTMach `panic` 은 `#if NeXT` 안에서 `extern struct mon_global *mon_global; struct mon_global *mg = mon_global;` 를 선언하고(484–490 행), 머리는 `#import <mon/global.h>`(117 행)입니다.
- NeXTMach `mon/global.h:99-101` 의 순서는 `short mg_minor, mg_seq; int (*mg_anim_run)(); short mg_major;` 입니다.
  - m68k 에서 0x30a 부터 놓으면 0x30a·0x30c·(0x30e 포인터)·0x312 가 되어 원본 변위와 상대 위치가 맞습니다(python).
  - 그 머리는 `mon/` 7 개와 `next/cpu.h`·`next/machparam.h` 를 가져와 닫힘이 큽니다.
- 07·m68k 스테이징에는 `mon/` 경로가 없습니다(find 0).

방법:
1. 07 덮어쓰기 `07_kernel/v183.34/m68k/src/bsd/kern/subr_prf.c` = 07 본 파일에 표시된 줄만 끼운 것입니다(지우거나 고치는 줄 없음).
   - `#endif NeXT`(114 행) 앞에 `#import <mon/global.h>` 를 넣습니다.
   - `panic` 의 `int bootopt` 다음에 NeXTMach 484–490 행 꼴의 두 선언을 넣습니다.
   - 543 행 앞에 NeXTMach 515–516 행의 `printf` 두 줄을 넣습니다.
   - 끼운 줄마다 끝에 `/* plan 437 (m68k) */` 를 붙입니다.
2. 07 덮어쓰기 `07_kernel/v183.34/m68k/src/mon/global.h`: 프로젝트 작성 부분 머리(D024)입니다.
   - `struct mon_global` 에 앞부분 채움 `char mg_pad0[0x30a]` + NeXTMach 이름의 네 멤버만 둡니다(원본 바이트 근거: `_panic` 의 변위).
   - NeXTMach 저작권 줄을 넣고(식별자 출처), 머리 주석에 "M4 에서 NeXTMach 전체 머리로 바꿀 후보" 를 적습니다.
   - 전체 머리를 지금 들이지 않는 이유는 위의 큰 닫힘과, 커널 공통부에서 쓰는 곳이 `panic` 하나뿐이라는 점입니다.
3. `stage_m68k.py` 의 파생 검사를 일반화합니다.
   - 등록된 표시(`plan 435 (D070)`·`plan 437 (m68k)`)가 붙은 줄을 모두 빼면 07 본 파일과 바이트까지 같아야 합니다.
   - D070 표시는 지금처럼 하나만, `#import <sys/param.h>` 바로 다음에만 허용합니다.
   - 기존 줄 끝에 붙은 표시는 그 줄을 빼면 본 파일과 달라지므로 거부됩니다.
   - 음성 시험을 다시 합니다.
4. 새 스테이징, 205 재컴파일(새 run), 미리 정한 기준:
   - `x86-subr_prf` 외 204 는 §435 run 과 비 STABS 절이 같습니다.
   - `x86-subr_prf` 는 `_panic` 구간이 같아지고 OBJECT_MATCH 가 됩니다(146 → 147). 잃은 것은 0, 미정의 기호 가운데 원본에 없는 것도 0 입니다.
   - 다르면 진단만 하고 07 을 그대로 둡니다(덮어쓰기 파일은 시험 결과와 함께 기록).
   - x86 관문(7 스테이징 불변)도 확인합니다.
5. PROVENANCE·MODIFICATIONS 에 행을 덧붙이고, diff `06_reconstruction/evidence/m68k-subr_prf.diff` 를 만듭니다. 기록은 `09_validation/reconstruction/m3-m68k-panic-20261009.json` 입니다.

### 437.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_panic`: `moveml d2/a2/a3` → `clrl d2`(bootopt) → `movel 0x40b69bc,a3`(mg, 선언 순서) … `movew a3@(0x30c/0x30a/0x312)` 를 오른쪽 인자부터 넣음(seq·minor·major) → `printf` | §414 원본 목록(`otool-V10/image.txt`) 0x400bc66–0x400bd0c 를 awk 로 읽음 | ✅ 초기화 꼴(`struct mon_global *mg = mon_global;`)이 a3 의 이른 적재와 맞음 |
| `addaw #0x20` vs `#0x1c` 와 `pea ""` 차이는 ROM 줄로 생긴 대기 스택 조정 차이(GCC 2.7 `calls.c` 의 32 B 기준) | 원본에 `pea 0x40a62e7`(빈 문자열 후보)·`addaw #0x20` 있음 확인; GCC 내부 설명은 미검증 | ⚖️ 설명은 가설, 판정은 실행 |
| 원본에 `mach_ldebug` 없음 → NeXTMach 484–486·509–511 은 넣지 않음 | §434.1 에서 `_mach_ldebug` 부재 확인(x86 표 17 행 근거와 같음) | ✅ |
| printf 는 542(`#if NeXT`)와 543 사이에 넣어야 함; 선언 둘을 `#if NeXT` 로 감쌀지 밝힐 것 | 07 540–545 행 읽음 | ✅ printf 두 줄은 542 와 543 사이, 선언 둘은 감싸지 않음(이 파일은 m68k 전용 덮어쓰기, `NeXT` 정의됨) |
| `<mon/global.h>` 는 `-Isrc/src` 로 덮어쓰기 `src/mon/global.h` 에 닿고 충돌 없음; `ddm.c` 는 다른 파일(`mon/mon_global.h`)이고 205 명령에 없음; `version` 은 `sys/systm.h:52` 에 선언 | 스테이징 `systm.h:52` 읽음, `cc.cmd` 의 `ddm` 0 건, §437 사실의 find 0 | ✅ |
| 채움 구조체: 0x30e 포인터·0x312 는 정렬 ≤ 2 에서만 성립 — m68k 최대 정렬 2(계획 412) | MULTIARCH 표준 275 행 "정렬 최대 2 바이트" 읽음 | ✅ 머리 주석에 `mg_pad0` 은 작성 이름, `sizeof` 는 원본과 다름, 다른 멤버 없음(쓰면 컴파일 오류)을 적음 |
| 파생 검사 일반화: D070 표시는 0 또는 1 개(있으면 `sys/param.h` 다음), 덮어쓰기 `.c` 마다 등록 표시 1 개 이상, 07 본 파일에는 표시 문자열 없음, 이어지는 줄에도 표시, 음성 시험(437 표시를 기존 줄 끝에 붙임·섞임) | 현재 `check_derived` 는 D070 정확히 1 개를 요구(읽음); 07 `src` 에 "plan 437" 0 건(grep) | ✅ 모두 반영. 위치 검사는 하지 않으므로 diff 파일이 위치 근거 |
| `--plan 437` 은 `EXCEPTS` 에 437 이 있어야 받음; 미리 정할 값: differ `['x86-subr_prf']`, same_non_stabs 204, byte_identical 87, object_match [146, 147], gained `['x86-subr_prf']`, lost [], stage_vs_test_stage 19 | `stage_m68k.py` main 의 `int(a[1]) in EXCEPTS` 읽음 | ✅ 그대로 미리 정함 |
| "원본에 없는 미정의 기호 0" 은 지금 `compare` 가 계산하지 않음(`_spl*` 만) | 도구 읽음 | ✅ 객체마다 원본 기호표에 없는 미정의 기호를 세고, 기준 객체에 없던 것만 "새로 생김" 으로 집계(기대 {}) |
| 새 문자열은 원본처럼 "panic: (Cpu" 와 "panic: %s" 사이(0x40a6299 < 0x40a62ad < 0x40a62c9) | 원본 목록의 `pea` 세 주소 읽음 | ✅ 실행 뒤 `__cstring` 순서 확인 |

### 437.2 실행 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-panic-20261009.json`

07 덮어쓰기 파일:
- `v183.34/m68k/src/bsd/kern/subr_prf.c`: 07 본 파일에 `plan 437 (m68k)` 표시 줄 5 개를 끼웠습니다.
  - 114 행 `#import <mon/global.h>`
  - `panic` 안에 NeXTMach 488–489 행의 선언 둘
  - 542 와 543 사이에 515–516 행의 `printf` 두 줄
  - diff 는 `06_reconstruction/evidence/m68k-subr_prf.diff` 입니다.
- `v183.34/m68k/src/mon/global.h`: 작성 부분 머리(채움 + 네 멤버).
- PROVENANCE 1069 → 1071, MODIFICATIONS 593 → 595(덧붙이기만).

`stage_m68k.py`:
- `--plan 437` 와 예외(`x86-subr_prf`)를 더했습니다.
- 파생 검사를 일반화했습니다.
  - 등록된 표시마다 허용 파일과 표시 줄 수를 정합니다(D070: `subr_kudp`·`if_venip` 각 1, 437: `subr_prf` 5).
  - 표시 줄을 빼면 07 본 파일과 같아야 하고, 07 본 파일에는 표시 문자열이 없어야 합니다.
  - D070 줄은 `sys/param.h` 다음에만 허용합니다.
  - 정상판 3 개는 통과하고 음성 시험 10 개는 모두 거부합니다.
- 비교 요약에 "원본에 없는 새 미정의 기호" 를 더했습니다.
  - 첫 계산은 STABS 기호까지 세는 제 오류가 있었고, `stab` 을 빼도록 고쳐 비교만 다시 돌렸습니다(재컴파일 없음).
  - 도구 해시는 `08_build/artifacts/m3p437/tools-pre.sha` 에 있고, 마지막 판(d013ad1d…)이 기록과 같습니다.
  - 스테이징·명령은 그 앞 판으로 만들었으며, 바뀐 것은 `compare` 부분뿐입니다.

결과:
- 스테이징 `m0p437-stage` 는 888 파일(덮어쓰기 바꿈 13·더함 10)입니다. x86 관문에서 7 스테이징이 모두 같습니다.
- run `m3p437-cc1` 은 205 명령이 모두 종료 0 이고 616 파일을 게시했습니다.
- 미리 정한 값과 모두 같습니다.
  - 비 STABS 절이 같은 것 **204**, 다른 것은 `x86-subr_prf` 하나입니다.
  - 바이트까지 같은 것 87 입니다.
  - OBJECT_MATCH 는 **146 → 147** 이고(얻은 것 `x86-subr_prf`, 잃은 것 0), 미정의 `_spl*` 는 0 입니다.
  - 원본에 없는 새 미정의 기호는 0 입니다(새 미정의 `_mon_global` 은 원본에 있음).
  - 시험 스테이징 대비 다른 파일은 19 입니다.
- 객체 `__cstring` 순서 "panic: (Cpu"(24) < "NeXT ROM Monitor"(44) < "panic: %s"(72) 는 원본 순서와 같습니다.

해석:
- m68k `_panic` 은 NeXTMach 의 ROM Monitor 줄과, 원본 변위로 정한 `struct mon_global` 부분 정의로 원본과 같아집니다.
- 이 줄은 m68k 전용 차이입니다. i386 은 계획 220 그대로 둡니다.

## 438. M3-14 세부 계획 — m68k 구성 값 전체 재확인과 `KERNOBJC 0` 시험(x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §434 의 m68k 덮어쓰기 표에는 4 값만 있고, 나머지 49 옵션은 x86 값을 그대로 씁니다. M3 를 닫기 전에 x86 표의 옵션마다 m68k 원본으로 같은 값이 맞는지 봅니다.

확인한 사실(이번 세션, 읽기 전용, python):
- x86 표 근거 칸에 적힌 `_` 기호를 m68k 기호표와 대조했습니다. 갈리는 옵션은 다음과 같습니다.
  - `simple_clock`·`driverkit`: 이미 덮어씀.
  - `pc_support`: `_PCcreate` 등 3 개가 m68k 에 없음.
  - `uxpr`: `_uxprGlobal` 등 3 개가 없음.
  - `xpr_debug`: 근거 `_IOMalloc`·`_IOAddDDMEntry` 가 없음(DriverKit 이 없어서).
  - `en`: `_en_recv_pkt`·`_en_send_pkt` 가 없음.
  - `od`: `_odattach` 가 m68k 에만 있음.
- 그 매크로를 쓰는 곳(m68k 스테이징, i386 디렉터리 제외 grep):
  - `PC_SUPPORT`·`NOD`·`DLI`·`FP_EMUL` 은 생성 머리뿐입니다.
  - `UXPR` 은 `kern/xpr.h:125` 인데 `#if XPR_DEBUG`(0) 안이라 효과가 없습니다.
  - `NEN` 은 `if_ether.c`, `NPTY` 는 `tty_pty.c`(둘 다 비청정), `MAXUSERS` 는 `conf/param.c`(205 밖), `MACH_LDEBUG` 는 `kern/lock.h`(DRIVERKIT 0 이면 MACH_SLOCKS 0) 입니다.
  - `KERNOBJC` 는 `kernserv/kern_server.c:604-607·834-837` 의 `objc_registerModule`·`objc_unregisterModule` 호출입니다. `kern/thread.c` 는 머리만 가져옵니다.
- §431 진단: `kern_server` 의 다른 구간은 `_kern_serv_load_objc`·`_kern_serv_shutdown` 둘이고, 각각 객체에만 `_objc_registerModule`·`_objc_unregisterModule` 호출이 있습니다(CALL 덩어리 하나씩).
- m68k 원본에는 그 두 기호가 없고(python), `__OBJC` 절도 없습니다(§423). mk-108.1 `conf/MASTER.next:88` RELEASE 에 `kernobjc` 가 없습니다(grep 0).

방법:
1. 새 도구 `10_tools/reconstruction/m3_m68k_config_review.py` 로 옵션마다 표를 만듭니다. 기록은 `09_validation/reconstruction/m3-m68k-config-review-20261009.json` 입니다.
   - 표의 열: 매크로, x86 값, m68k 덮어쓰기 값, 근거 기호의 x86·m68k 유무, m68k 스테이징에서 매크로를 쓰는 파일(i386 디렉터리 제외), 205 객체 가운데 그 파일을 소스로 가진 것, 판정.
   - 판정은 다음 넷 중 하나입니다: "같음(근거 같음)", "덮어씀", "m68k 후보값 있음 — 쓰는 객체가 아직 없어 미룸", "근거 없음".
   - 매크로 사용 검사는 grep 기준입니다(전처리 닫힘이 아님 — 한계로 적음).
2. `KERNOBJC 0` 을 `06_reconstruction/config_options-m68k.tsv` 에 덧붙입니다(hypothesis → 시험 뒤 판정). `gen_config_headers.py --arch m68k` 로 `v183.34/m68k/generated/kernobjc.h` 를 생성하고 PROVENANCE·MODIFICATIONS 에 행을 덧붙입니다.
3. 새 스테이징과 205 재컴파일(`stage_m68k.py --plan 438`, 예외 `x86-kern_server`)을 합니다. 미리 정한 기준은 다음과 같습니다.
   - `kern_server` 만 이전 run 과 달라지고 OBJECT_MATCH 가 됩니다(147 → 148).
   - `thread` 는 그대로입니다. 잃은 것 0, 원본에 없는 새 미정의 기호 0 입니다.
   - x86 관문은 불변입니다.
   - 다르면 표 행을 hypothesis 로 남기지 않고 되돌린 뒤 진단만 합니다.
4. 다른 후보값(`pc_support` 0, `uxpr`, `en`, `od`, `cputypes`, `maxusers`, `pty`, `mach_ldebug`)은 지금 205 객체의 코드에 영향이 없거나 쓰는 객체가 비청정이라, 바꾸지 않고 표에 "미룸" 으로 기록합니다. M4·M5 에서 그 객체를 만들 때 정합니다.

### 438.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 사실 목록이 불완전: `pc_support` 는 4 기호(`_PCresume` 포함), `od` 는 `_odopen` 도, `mach_debug` 의 `_stack_usage_lock` 은 x86 에만(MACH_SLOCKS 0 이면 `decl_simple_lock_data` 가 비어 정상) | 근거 칸 원문과 두 기호표 python 대조: `_PCresume`·`_PCcallMonitor`·`_stack_usage_lock` x86 만, `_odopen`·`_odattach` m68k 만 | ✅ **내 오류**: 예비 조사 정규식 `(?<![\w/.])` 이 `/` 뒤 기호를 빠뜨림 — 도구에서는 `/` 를 허용 |
| 205 컴파일 모두 `-imacros meta_features.h` 로 `KERNOBJC` 를 봄(`meta_features.h:17`), 그러나 `#if KERNOBJC` 는 `kern_server.c` 의 두 곳뿐 | `meta_features.h:17` 읽음; §438 사실의 grep(같은 결과) | ✅ |
| 크기: 객체 3846 B, 원본 구간 3804 B, 차 42 = 지워질 두 호출 덩어리(24 + 18); 원본 `_kern_serv_load_objc` 10 B | 실행 결과로 확인(재컴파일 뒤 크기 비교) | ⏭️→ 실행으로 |
| **도구가 `--plan 438` 을 받지 못함**(`EXCEPTS` 에 438 없음) | `stage_m68k.py:40-43` 읽음 | ✅ `EXCEPTS[438]` 추가 |
| **비교는 기준 run(`m3p429-cc2`·`m3p432-int`)과 하므로 예외는 누적돼야 함** — 438 예외 = `x86-subr_prf`(§437) + `x86-kern_server` | `cmd_compare` 가 `REFS` 와 비교함(읽음) | ✅ 계획 정정; 기준: differ = 두 객체, same_non_stabs 203, object_match [146, 148], gained 두 객체 |
| 바이트 동일은 기준이 아님(STABS 줄 번호) — `sections_differ` 기준 | §433 이후 그대로 씀 | ✅(기존 기준 유지) |
| 미루는 옵션 가운데 205 에 영향 없는 것: `NEN` 은 `if_ether.c:98-102` 가 `#else vax` 에서 0 으로 재정의, `NPTY` 는 `tty_pty.c:70-73` 이 1 일 때만 바꿈, `mach_ldebug.h` 는 undetermined 라 생성되지 않음 | 세 곳 읽음, `generated/mach_ldebug.h` 없음 | ✅ 표에 "소스가 재정의"·"생성 안 됨" 으로 따로 적음 |
| `cputypes.h`: CMU config 는 cpu 줄마다 `#define <cpu> 1`; `MASTER.next:96 cpu "NeXT"` → `#define NeXT 1` = 컴파일 줄의 `-DNeXT` 와 같음 | `MASTER.next` 96 행은 실행 때 도구로 읽어 기록; mkmakefile 설명은 미검증 | ⚖️ "같은 효과로 보임(미검증 부분 있음)" 으로 기록, 바꾸지 않음 |
| grep 방법의 한계: 머리 닫힘 아님, 다른 매크로를 거친 시험(MACH_SLOCKS·PRI_SHIFT 등), 지역 재정의·주석·`#ifdef` 도 사용으로 셈, `machdep/ppc` 도 셈 | 설계 | ✅ 도구가 `#if`/`#ifdef`/`#define`/주석을 나눠 세고 `machdep/{i386,ppc,hppa,sparc}` 를 빼며, 한계를 기록에 적음 |
| 미루는 옵션이 OBJECT_MATCH 객체에 쓰이는 경우(STAT_TIME·KERNEL_STACK·MACH_DEBUG 등)는 지금 값으로 이미 일치 — 바꿀 근거 없음 | 147 일치 사실 | ✅ "현재 값으로 일치하는 객체가 있음" 열을 둠 |

### 438.2 실행 결과(2026-10-09) — 기록 `m3-m68k-kernobjc-20261009.json`(재컴파일), `m3-m68k-config-review-20261009.json`(옵션 표)

**`KERNOBJC 0`**
- `06_reconstruction/config_options-m68k.tsv` 에 행을 덧붙였고, `generated/kernobjc.h` 를 `gen_config_headers.py --arch m68k` 로 생성했습니다.
  - 기존 m68k 머리 4 개는 바이트가 그대로입니다(SHA 확인). x86 `--check` 는 종료 0 입니다.
  - PROVENANCE 1071 → 1072, MODIFICATIONS 595 → 596(덧붙이기만).
- `stage_m68k.py` 에 `EXCEPTS[438]` 를 넣었습니다(§437 의 `x86-subr_prf` + `x86-kern_server`, 기준 run 과 비교하므로 누적).
- 실기 run `m3p438-cc1` 은 205 명령이 모두 종료 0 이고, 스테이징 888 파일, x86 관문 7 스테이징이 같습니다. 도구 해시는 실행 전후가 같습니다(`08_build/artifacts/m3p438/tools-pre.sha`).
- 미리 정한 값과 모두 같습니다.
  - 비 STABS 절이 같은 것 203, 다른 것은 `x86-kern_server`·`x86-subr_prf` 입니다.
  - OBJECT_MATCH 는 **146(기준 run) → 148**(얻은 것 두 객체, 잃은 것 0)입니다.
  - 미정의 `_spl*` 0, 원본에 없는 새 미정의 기호 0 입니다.
- 결과에 따라 표 행의 상태를 confirmed 로 고쳤습니다(오늘 쓴 행, 행 수 그대로). 생성 머리는 바뀌지 않습니다(`--check` 종료 0).

**옵션 표**
- 도구 `10_tools/reconstruction/m3_m68k_config_review.py`(11d2afb3…)로 x86 표 53 옵션을 판정했습니다.
  - 근거 같음 27, 덮어씀 4(`simple_clock`·`driverkit`·`kernobjc`·`gdb`; `iplmeas` 는 x86 표에 없음), 생성 안 됨 3(`new_vm_code`·`mach_vm_debug`·`mach_ldebug`), 기호 근거 없음 13, **근거가 갈려 미룸 6**입니다.
- 미룬 6 개와 이유:
  - `pc_support`·`od`: 값을 시험하는 파일이 스테이징에 없습니다(i386 전용·m68k 전용 장치는 M4).
  - `uxpr`·`xpr_debug`: 시험이 `kern/xpr.h`·`driverkit/ddm.c` 뿐이고, `#if XPR_DEBUG`(0) 안이거나 205 밖입니다.
  - `en`: `if_ether.c:98-102` 가 non-vax 에서 `NEN 0` 으로 다시 정의하므로 생성값이 효과가 없습니다.
  - `mach_debug`: `_stack_usage_lock` 이 m68k 에 없는 것은 `MACH_SLOCKS 0`(DRIVERKIT 0)에서 `decl_simple_lock_data` 가 비기 때문이고, 값 1 로 `thread`·`zalloc`·`ipc_kobject` 가 일치하므로 바꿀 근거가 없습니다.
- 한계(기록에 적음): 전처리 닫힘이 아닌 문자열 검사입니다. 다른 매크로를 거친 시험과 머리를 통한 사용은 객체에 연결하지 않았습니다. `cputypes.h`(빈 머리)가 `MASTER.next:96 cpu "NeXT"` 의 config 출력과 같은 효과라는 점은 검토 의견일 뿐 미검증입니다.

해석: x86 값을 그대로 쓰는 m68k 옵션 가운데, 지금 컴파일하는 205 객체에 영향을 주면서 근거가 갈리는 것은 남지 않았습니다. 미룬 6 개는 그 값을 쓰는 객체를 M4·M5 에서 만들 때 정합니다.

## 439. M3-15 세부 계획 — 다시 만든 m68k 객체로 §418 의 미결정 경계 판정(07 변경 없음; 표는 새 판으로; 코딩 전, 2026-10-09)

배경: §418 경계 326 개 가운데 미결정은 11 개입니다. 그중 양쪽 객체를 m68k 로 다시 만든 것은 셋입니다(k=130 `ufs_vfsops`|`ufs_vnodeops`, k=191 `kern_notify`|`kern_server_handler`, k=193 `kern_server_reply_user`|`exc_server`). 나머지 8 개는 대응 없는 구간·SCSI·`.word` 행과 맞닿아 있어 이번 대상이 아닙니다.

확인한 사실(이번 세션, python):
- k=191: OBJECT_MATCH 인 `kern_server_handler` 의 L1 자리는 0x40576ce 이고, 이는 하한과 같습니다(구간 [0x40576ce, 0x4057d74]). `kern_notify` 의 L1 끝도 0x40576ce 입니다.
- k=193: OBJECT_MATCH 인 `exc_server` 의 자리는 0x4058090 이고 하한과 같습니다. `kern_server_reply_user`(OBJECT_MATCH)의 끝도 0x4058090 입니다.
- k=130 은 [0x403a04c, 0x403a056] 입니다.
  - `ufs_vnodeops` 객체 첫 36 B 가 0x403a056 에서 같습니다(§436).
  - `ufs_vfsops` 는 결정된 k=129 의 0x4039568 에서 첫 32 B 중 3 B 만 다릅니다(재배치 필드로 보임).
  - 원본 범위 [0x4039568, 0x403a056) 는 2798 B 로 객체 2884 B 보다 86 B 짧습니다. 후보 원인은 §430 에 기록된 i386 `_byte_swap_*` 호출입니다.
  - `ufs_vfsops` 의 L1 자리 0x403952e("외부 기호 기준") 에서는 첫 32 B 가 모두 달라, §436 의 `ufs_vnodeops` 와 같은 자리 오류입니다.

방법(새 도구 `10_tools/reconstruction/m2_m68k_boundaries_built.py`; 입력 §418 표·기록, run `m3p438-cc1` 객체와 L1 기록):
1. 판정 규칙은 다음과 같습니다(미리 정함).
   - b 쪽이 OBJECT_MATCH 이면 그 L1 `__text` 자리를 경계로 봅니다.
   - a 쪽이 OBJECT_MATCH 이면 자리 + 크기를 경계로 봅니다.
   - 둘 다 아니면 b 객체 `__text` 첫 64 B(재배치 필드를 가림)가 [하한, 상한] 안의 짝수 주소 가운데 정확히 한 곳에서 같을 때 그 주소를 경계로 봅니다.
   - 어느 경우든 값이 [하한, 상한] 안이어야 합니다. 두 근거가 함께 있으면 서로 같아야 합니다.
2. k=130 의 a 쪽 정합 확인을 합니다. 실기 `otool -tv`(읽기 전용)로 `ufs_vfsops` 객체를 풀고, §436 도구 방식으로 [0x4039568, 0x403a056) 와 전체 정규화 비교를 합니다. 86 B 차이가 모두 `_byte_swap_*` 관련 덩어리여야 합니다. 아니면 k=130 을 결정하지 않습니다.
3. 산출:
   - 새 표 `06_reconstruction/m68k-text-boundaries-built.tsv` 는 §418 표 326 행 전체를 그대로 옮기고 열 `decided_439`·`boundary_439`·`basis_439` 를 더합니다. §418 표는 바꾸지 않습니다.
   - 기록은 `09_validation/reconstruction/m2-m68k-boundaries-built-20261009.json` 입니다.
   - §423 객체 목록의 "정확 경계" 수가 몇 개 늘어나는지 python 으로 셉니다(표는 다시 만들지 않고 기록만 합니다).
4. 음성 시험: 첫 64 B 대조를 경계 ±2·±4 로 옮겨 맞지 않음을 보입니다. 또 이미 결정된 경계 가운데 양쪽이 다시 만든 객체인 것 전부에 같은 규칙을 적용해, §418 값과 어긋남이 0 인지 봅니다.

### 439.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| k=191·193 의 L1 자리·끝 값 맞음; 단 `kern_notify` 는 NOT_MATCH 라 규칙 1.2 의 a 쪽 근거가 못 됨(정합 확인일 뿐) | §439 사실의 python 출력 | ✅ 규칙에 "a 쪽 근거는 OBJECT_MATCH 일 때만" 명시 |
| `ufs_vfsops` 의 0x4039568 차이 바이트는 27–29·51 이고, 각각 외부 pc 상대 재배치(offset 26, 4 B)와 지역 pc 상대 재배치(offset 48) 안 | python: 첫 64 B 차이 offset [27, 28, 29, 51], 재배치 (48, len 2, pcrel, local)·(26, len 2, pcrel, extern) | ✅ |
| 0x403a04c 의 10 B 진입점 = 객체 마지막 함수 `_ufs_badvfsop`(offset 2874; 2874 − 86 = 2788 = 0x403a04c − 0x4039568) — 하한 쪽 미해결 진입점은 a 쪽 함수 | python: 원본 0x403a04c 10 B 와 객체 끝 10 B 가 같음(`48562c4f70164e5e4e75`), 마지막 기호 `_ufs_badvfsop` 2874 | ✅ k=130 의 결정 근거는 a 쪽 전체 비교(관문)로 둠 |
| 같은 10 B 꼴이 `__text` 에 여러 번(11) 나타나므로 b 쪽 첫 바이트만으로는 k=130 을 정할 수 없음 | 도구에서 셈 | ⏭️→ 도구 기록 |
| 첫 64 B 규칙은 MIG 머리말 반복 때문에 유일하지 않을 수 있음(k=191 에서 3 곳) → 둘 다 OBJECT_MATCH 아닐 때만 쓰고, 후보는 [하한, 상한] 안의 **진입점**, 여럿이면 판정 보류 | 설계(도구에서 다시 셈) | ✅ |
| 재배치 가림: scattered PAIR 항목은 건너뛰고 나머지는 `1 << r_length` 바이트 | `l1_compare` 관례(검토 의견), 도구에 구현 | ✅ |
| 모든 205 객체 `__text` 정렬 2^1·크기 짝수 → 채움 없음; 결정된 경계 195 개(양쪽 재빌드) 중 OBJECT_MATCH 쪽 확인 모두 일치 | 도구에서 다시 셈 | ⏭️→ 음성 시험에 포함 |
| **음성 시험 설계가 무의미**: 결정된 경계는 하한 = 상한이라 "구간 안 유일" 이 자명 → 창을 (a_last, b_first] 로 넓혀 시험 | §418 표의 결정 행 lower = upper 확인(k=129 등) | ✅ 창 (a_last, b_first] 의 진입점으로 규칙 1.3 을 시험: 틀린 판정 0 이어야 함(놓침·보류는 허용, 수를 기록) |
| 6 객체(`m68k-123`·`124`·`184`–`187`)가 정확해져 300 → 306, 정확 바이트 76.70 % → 78.89 % | 도구에서 다시 셈 | ⏭️→ 도구 기록 |
| 2 단계의 합격 기준을 미리 정할 것; L1 의 잘못된 자리 대신 0x4039568·0x403a056 을 강제로 씀 | 설계 | ✅ 기준: (a) 객체 − 원본 바이트 차 합 = 86, (b) 객체에만 있는 호출은 `_byte_swap_*` 뿐, (c) 원본에만 있는 호출 0, (d) 그 밖의 덩어리는 바이트 차 0. 하나라도 어긋나면 k=130 은 결정하지 않음 |

### 439.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-boundaries-built-20261009.json`, 표 `06_reconstruction/m68k-text-boundaries-built.tsv`

도구 `10_tools/reconstruction/m2_m68k_boundaries_built.py`.
- 첫 실행은 §423 표의 `data-only` 행(시작 칸이 빔)에서 멈췄고, 고친 뒤 다시 돌렸습니다. 해시는 `08_build/artifacts/m3p439/tool-pre.sha` 에 있고, 마지막 판(f9564bab…)이 기록과 같습니다.
- `ufs_vfsops` 의 실기 `otool -tv` 목록은 `08_build/artifacts/m3p439/otool/` 에 두었고, 객체 SHA 를 실기 `krsha256` 과 대조했습니다.

결과:
- **k=191 → 0x40576ce**(규칙 1: `kern_server_handler` OBJECT_MATCH 자리), **k=193 → 0x4058090**(규칙 1 + 2 일치)로 결정했습니다.
- **k=130 은 결정하지 않았습니다**(미리 정한 a 쪽 관문 불통과).
  - 규칙 3 은 [하한, 상한] 안의 진입점 가운데 0x403a056 한 곳에서만 맞았습니다.
  - 관문에서 객체 − 원본 바이트 차의 합이 86 이 아니라 82 였습니다. 정규화로 같다고 본 분기도 길이가 다를 수 있어 4 B 가 덩어리 밖에 남은 것으로 보입니다(미검증).
  - 객체에만 있는 호출에 `_byte_swap_superblock`·`_byte_swap_ints` 말고도 `_copyin` 이 있고, 원본에만 `_copyinmsg` 가 있습니다(`ufs_mount`, 07·NeXTMach `ufs_vfsops.c:124` 는 `copyin`).
  - `bwrite` 정렬 덩어리 쌍(−8·+10)이 있었습니다.
  - `mountfs` 의 프레임 변위가 4 B 다릅니다(`linkw #0xffb0` 대 `#0xffb4`; 바이트 차 0 인 D-frame 13 개).
  - 0x403a04c 진입점의 10 B 는 `ufs_vfsops` 객체의 마지막 함수 `_ufs_badvfsop` 과 같습니다(§439.1). 따라서 경계가 0x403a056 이라는 근거는 강하지만, 미리 정한 기준이 아니어서 이번에는 결정하지 않습니다.
- 음성 시험(양쪽이 다시 만든 객체인 결정 경계 195 개)은 모두 통과했습니다.
  - 규칙 1 확인 142·규칙 2 확인 143, 어긋남 0.
  - 규칙 3 을 넓은 창 (a_last, b_first] 로 돌리면 맞음 179·놓침 14·모호 2·**틀림 0**.
  - ±2·±4 이동 거짓 일치 0.
- 새 표는 §418 표 326 행에 `decided_439`·`boundary_439`·`basis_439` 를 더한 것입니다(§418 표는 그대로). 결정된 것은 315 + 2 = 317 입니다.
- §423 객체 목록에 미치는 효과(표는 다시 만들지 않음):
  - 정확한 객체가 300 → 304(`m68k-184`–`187` = `kern_notify`·`kern_server_handler`·`kern_server_reply_user`·`exc_server`)입니다.
  - 정확 바이트는 520,436 → 524,384(`__text` 678,510 B 의 76.70 % → 77.28 %)입니다.
  - 검토자가 예상한 6 개 가운데 `m68k-123`·`124`(k=130) 는 들지 않았습니다.

새 M5 후보:
- `ufs_vfsops` `ufs_mount` 에서 원본은 `copyinmsg` 를 부릅니다.
- `mountfs` 의 지역 변수 4 B 차이가 있습니다(바이트 교환 외).

## 440. M3-16 세부 계획 — 경계 규칙 4(a 쪽 끝 함수 + b 쪽 첫 바이트의 맞닿음)로 k=130 다시 판정(사용자 지시 "진행합니다"; 07 변경 없음; 코딩 전, 2026-10-09)

배경: §439 에서 k=130 은 미리 정한 a 쪽 전체 비교 관문을 통과하지 못해 미결정으로 남았습니다(바이트 차 82 ≠ 86, `ufs_mount` 의 원본 `copyinmsg`, `mountfs` 프레임 4 B). 그 관문은 a 객체 전체가 바이트 교환 말고는 같아야 한다는 강한 조건이었습니다. 경계를 정하는 데 필요한 것은 "a 가 어디서 끝나고 b 가 어디서 시작하는가" 입니다. 그래서 끝과 시작이 맞닿는지만 보는 규칙을 새로 정하고, 이번에도 결과를 보기 전에 미리 정합니다.

확인한 사실(이번 세션, python):
- `ufs_vfsops` 객체의 마지막 함수(offset 2874, 10 B, 재배치 없음)와 같은 바이트열은 원본 `__text` 에 11 번 나옵니다(0x403a04c 포함).
- k=130 의 [하한, 상한] 안 진입점은 0x403a04c·0x403a056 두 개입니다.
- §439: `ufs_vnodeops` 의 가린 첫 64 B 는 그 안에서 0x403a056 에만 맞습니다.

규칙 4(미리 정함; 양쪽 다 다시 만든 객체이고 둘 다 OBJECT_MATCH 가 아닐 때만):
1. a 객체 `__text` 의 마지막 함수(마지막 기호부터 끝까지, 길이 L)를 재배치 필드를 가려 원본 진입점 e_a 와 대조합니다. e_a 의 범위는 [a_last, 상한] 안의 진입점입니다.
2. b 객체 첫 min(크기, 64) B 를 가려 진입점 c 와 대조합니다(§439 규칙 3 과 같은 방법). c 의 범위는 [하한, 상한] 입니다.
3. e_a + L = c 인 짝이 **정확히 하나**이면 c 를 경계로 정합니다. 없거나 둘 이상이면 보류합니다.
4. c 는 [하한, 상한] 안이어야 합니다.

음성 시험(미리 정함):
- 양쪽을 다시 만든 결정 경계 195 개에 규칙 4 를 넓은 창으로 적용합니다(e_a 는 [a_last, b_first] 진입점, c 는 (a_last, b_first] 진입점). **틀린 판정 0** 이어야 하고, 맞음·보류 수를 기록합니다.
- k=130 에서 c 를 ±2·±4 로 옮기면 짝이 성립하지 않아야 합니다.
- 하나라도 틀리면 규칙 4 를 쓰지 않습니다.

방법: §439 도구 `m2_m68k_boundaries_built.py` 에 `--plan 440`(규칙 4 추가, 규칙 1–3·관문은 그대로)을 더합니다. 표 `06_reconstruction/m68k-text-boundaries-built.tsv` 를 같은 열로 다시 만들고(근거 칸에 `rule4 (plan 440)`), 기록은 `09_validation/reconstruction/m2-m68k-boundaries-built4-20261009.json` 입니다. §439 기록은 그대로 둡니다. §423 객체 정확 수의 효과도 다시 셉니다.

해석 한계: 규칙 4 는 두 객체가 맞닿는다는 것만 보입니다. a 객체 안쪽의 차이(`copyinmsg`·프레임)는 M5 항목으로 남습니다.

### 440.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **"미리 정함" 은 k=130 에 대해 정직하지 않음**: 규칙의 두 입력(0x403a04c 의 10 B, 0x403a056 의 b 머리)을 이미 안 뒤에 정했으므로 k=130 에는 사전 등록 시험이 아님; 독립 근거는 음성 시험뿐 | §440 본문을 다시 읽음(사실 목록에 두 입력이 있음) | ✅ **내 오류** — 기록 문구를 "§439 결과를 본 뒤 사용자 지시로 정한 규칙; k=130 에는 사후 판정, 독립 근거는 음성·특이성 시험" 으로 고침 |
| 끝 함수 10 B 는 식별력이 없음(같은 꼴 11 곳; 다른 객체의 끝 함수와도 거짓 짝 25 / 39,780) → 고정 길이 a 꼬리(마지막 min(크기, 64) B, 가림)가 c 에서 끝나야 한다는 꼴이 더 강함 | 11 곳은 §440 사실의 python 출력; 거짓 짝 수는 도구에서 다시 셈 | ✅ 규칙 4 를 "a 꼬리 64 B" 로 바꿈 |
| 규칙 4 는 규칙 3(b 머리)을 포함하므로, 음성 시험의 힘은 규칙 3 이 모호했던 경계에서만 생김 | 설계 확인 | ✅ 기록에 "규칙 4 ⊂ 규칙 3 의 제한" 이라고 적고, 교차 짝 특이성 시험을 더함(아래) |
| 구조 근거: 객체 기호 `_getmdev`·`_ufs_vget`·`_ufs_badvfsop` 을 −86 옮기면 원본 진입점 0x4039f30·0x4039fae·0x403a04c 에 놓임 | python: 세 기호만 −86 에서 진입점과 일치(앞쪽 3 개는 0 에서, `_ufs_unmount`–`_sbupdate` 는 어느 쪽도 아님) | ✅ 보조 근거로 기록 |
| `e_a ≥ 하한` 조건은 일반적으로 틀림(결정 경계는 하한 = 상한) | 설계 확인 | ✅ 넣지 않음 |
| "마지막 함수" 의 정의를 밝힐 것 | — | ⏭️ 꼬리 꼴로 바꿔 필요 없음 |

고친 규칙 4(이 판정표 뒤, 실행 전에 고정):
- 양쪽 다 다시 만든 객체이고 둘 다 OBJECT_MATCH 가 아닐 때만 씁니다.
- a 객체 `__text` 의 마지막 min(크기, 64) B(재배치 필드 가림)가 원본에서 c 바로 앞에서 끝나고, b 객체 첫 min(크기, 64) B(가림)가 c 에서 시작하는 진입점 c 가 [하한, 상한] 안에 **정확히 하나** 일 때 c 로 정합니다.

시험:
- (i) 결정 경계 195 개에 넓은 창 (a_last, b_first] 로 적용합니다. **틀림 0** 이어야 하고, 맞음·보류 수를 기록합니다.
- (ii) 교차 짝 특이성: 결정 경계마다 참 경계 c 에서 다른 모든 다시 만든 객체의 a 꼬리, 그리고 다른 모든 객체의 b 머리가 성립하는 거짓 짝 수를 셉니다(판정 관문이 아니라 기록용).
- (iii) k=130 에서 c ±2·±4 를 확인합니다.
- (i) 에서 틀림이 하나라도 있으면 k=130 을 정하지 않습니다.

### 440.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-boundaries-built4-20261009.json`, 표 `06_reconstruction/m68k-text-boundaries-built.tsv`(다시 만듦)

도구는 `m2_m68k_boundaries_built.py --plan 440`(84feae6b…, `08_build/artifacts/m3p439/tool-pre.sha`)입니다. 규칙 1–3 과 관문은 §439 와 같습니다.

**정직성 표시**: 규칙 4 는 §439 결과(k=130 의 두 사실)를 본 뒤 사용자 지시로 정했습니다. 따라서 k=130 에 대해서는 사후 판정이고, 독립 근거는 아래 시험들입니다. 규칙 4 는 규칙 3(b 머리)에 a 꼬리 조건을 더한 제한입니다.

결과:
- **k=130 → 0x403a056(규칙 4)** 입니다.
  - [하한, 상한] 진입점 가운데 짝이 성립하는 곳은 0x403a056 하나입니다.
  - c ±2·±4 는 모두 불성립입니다.
  - 다시 만든 다른 객체의 64 B 꼬리 가운데 0x403a056 에서 끝나는 것은 없습니다(검토자가 짚은 10 B 끝 함수의 `spec_vfsops` 거짓 짝은 64 B 꼬리에서 사라짐).
  - 보조 근거: 객체 기호 `_getmdev`·`_ufs_vget`·`_ufs_badvfsop` 을 −86 옮기면 원본 진입점에 놓입니다(§440.1).
- 시험 (i): 결정 경계 195 개(양쪽 다시 만든 객체)에 넓은 창으로 규칙 4 를 적용했습니다. **맞음 172·틀림 0**·보류 23(모두 짝 없음)입니다.
- 시험 (ii), 교차 짝 특이성(기록용): 참 경계에서 다른 객체의 꼬리가 성립한 것 20 건, 다른 객체의 머리가 성립한 것 6 건입니다.
  - 그래서 꼬리나 머리 하나만으로는 식별력이 완전하지 않습니다.
  - 판정은 둘이 함께 맞고 창 안에서 하나일 때만 합니다.
- 표: §439 판과 비교하면 k=130 행의 덧붙인 세 열만 바뀌었습니다(`1`, `0x403a056`, `rule4 (plan 440)`). 앞 13 열과 다른 행은 같습니다(diff). 결정 경계는 318/326 입니다.
- §423 객체 효과(표는 다시 만들지 않음):
  - 정확한 객체가 300 → **306** 입니다(`m68k-123` `ufs_vfsops`·`124` `ufs_vnodeops`·`184`–`187`).
  - 정확 바이트는 520,436 → 535,278 B, `__text` 의 76.70 % → **78.89 %** 입니다.
- §439 기록(`m2-m68k-boundaries-built-20261009.json`)은 그대로 두었습니다.

## 441. M3-17 세부 계획 — m68k `need_ast` 의 정의 자리와 `_hardclock` 의 `_clock_value` 경로(조사·결정 대기; 07 변경 없음, 2026-10-09)

확인한 사실(이번 세션, python·grep):
- 원본 m68k `_need_ast` 는 `__common`(section 6) 0x40b6064 이고 크기는 4 B(다음 기호까지)입니다. 바로 앞이 `_last_hardclock`(0x40b605c), 바로 뒤가 `_file_zone`(0x40b6068) 입니다.
- 다시 만든 m68k 객체(run `m3p438-cc1`) 가운데 `_need_ast` 를 언급하는 7 개(`kern_clock`·`kern_sig`·`ast`·`ipc_sched`·`sched_prim`·`task`·`thread`)는 모두 미정의(UNDF)로만 참조합니다.
  - 07 `kern/ast.c:74-76` 이 `#ifndef MACHINE_AST` 일 때만 정의하는데, m68k 는 §432 부터 `MACHINE_AST` 입니다.
  - 이대로면 M7 링크에서 미정의 기호가 됩니다.
- B2-1 규칙(§397·§399: `__common` 순서 = 링크 순서에서 처음 언급(UNDF·COMMON 가리지 않음)한 객체, 그 안에서는 기호표 순) 으로 보면 다음과 같습니다.
  - 다시 만든 객체 가운데 처음 언급자는 링크 순서상 첫째인 `kern_clock`(원본 0x40033d2)입니다.
  - 원본 m68k `_hardclock` 은 `_last_hardclock` 에 쓰고 `ast` 를 검사하므로, `_last_hardclock`·`_need_ast` 가 이어 놓인 것과 맞습니다.
  - 뒤의 `_file_zone` 을 처음 언급하는 객체는 다음 객체 `kern_descrip` 입니다.
- NeXTMach mk-108.1 에서 `need_ast` 를 정의하는 곳은 `kern/ast.c:76`(`int need_ast[NCPUS];`, 조건 없음) 하나입니다. `next/` 기계 의존부에는 언급이 없습니다(grep).
- 따라서 정의(COMMON)는 `kern_clock` 과 같거나 뒤의 어느 객체에 있어도 원본 배치와 같습니다. 바이트만으로는 정의 파일을 정할 수 없습니다(x86 B5 의 `_master_cpu` 등과 같은 경우 — 그때도 사용자에게 물었습니다).
- `_hardclock` 의 `_clock_value` 경로:
  - 원본 m68k `_hardclock` 은 `pea 1; bsr _clock_value; lea _last_hardclock` 꼴로 `clock_value(1)` 를 `last_hardclock` 과 함께 씁니다(§431 덩어리).
  - `_clock_value` 는 m68k `__text` 0x40920aa 에 있는 함수입니다(기계 의존부로 보임).
  - 07 `kern_clock.c` 의 `hardclock` 은 x86 원본에서 작성한 판(계획 233)이고, NeXTMach `bsd/kern_clock.c:169-210` 은 `usec_elapsed` 꼴이라 둘 다 이 꼴이 아닙니다.
  - 이것은 m68k(또는 183.34) 전용 소스 블록이라 **M5 작성 항목**으로 넘깁니다(이번에는 고치지 않음).

결정이 필요한 것(사용자):
- `need_ast` 를 어디서 정의할지 정해야 합니다.
- 후보 (가): m68k 덮어쓰기 `kern/ast.c` 에 NeXTMach `kern/ast.c:76` 자리처럼 조건 없는 `volatile ast_t need_ast[NCPUS];` 를 둡니다(표시 줄 방식, `#ifndef MACHINE_AST` 는 초기화 고리에만 남김).
  - `ast` 는 `kern_clock` 뒤이므로 배치가 바뀌지 않습니다.
  - `ast` 객체의 `__text` 는 그대로일 것으로 예측합니다(COMMON 은 절 바이트를 바꾸지 않음).
- 후보 (나): M7 링크 때까지 미룹니다.

### 441.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **NeXTMach `kern/ast.c:75-77` 은 조건 없음이 아님**: `#if !HW_AST` 안이고 RELEASE 는 `hw_ast` → NeXTMach next 커널은 `need_ast` 를 정의하지 않음. 조건 없는 `volatile ast_t need_ast[NCPUS];` 는 Mach4 `kernel/kern/ast.c:58`·Darwin `kern/ast.c:82`(둘 다 초기화 고리만 `#ifndef MACHINE_AST`) | NeXTMach 72–88 행, Mach4 ast.c grep(58·63–68), Darwin ast.c grep(82·87–92) 읽음 | ✅ **내 오류**(앞선 grep 결과를 잘못 읽음) — 후보 (가) 의 출처를 Mach4 `kern/ast.c:58`(D022 기본 참고)로 고침 |
| 원본 `__text` 가 0x40b6064 를 17 번 참조하고, 그중 2 곳(0x4099e66, 0x409a328)은 trap 쪽 기계 의존 객체 → 원본 언급 객체는 9 개 | python 으로 `__text` 에서 4 B 값 검색: 17 곳, 주소 목록 일치 | ✅ trap 두 곳은 링크 순서상 뒤라 배치에 영향 없음; M5 에서 언급자로 더함 |
| `kern_clock` 앞의 객체(다시 만든 것·안 만든 것 모두)는 `need_ast` 를 언급하지 않음(원본 바이트에 0x400344e 아래 참조 없음; B2-1 로도 그렇다면 kern_acct 공통 기호 앞에 놓였을 것) | 위 17 곳 중 최소 주소 0x400344e(= `_hardclock` 안) 확인 | ✅ |
| `_hardclock` 은 `need_ast` 를 "검사" 가 아니라 `ast_on(AST_UNIX)` 꼴로 씀 | 원본 목록(§431 덩어리 `orl d6,d0`) | ✅ 문구 정정 |
| 덮어쓰기 파생 검사는 끼운 표시 줄만 허용 → (가) 는 07 `ast.c:76` 뒤에 표시 줄 하나 `volatile ast_t need_ast[NCPUS];` 를 끼우는 꼴이고, `MARKERS` 에 `{'src/kern/ast.c': 1}` 을 더해야 함 | `stage_m68k.py` `check_derived` 읽음(§437 에서 작성) | ✅ |
| 형은 07 `kern/ast.h:102` 의 `extern volatile ast_t` 와 같아야 함(NeXTMach `int` 는 충돌) | 07 `ast.h:102` grep(§441 사실) | ✅ |
| 07 `kern/ast.h:123-142` 가 `need_ast` 를 조건 없이 쓰므로, 07 `ast.c` 의 정의 가드(계획 198)는 Mach4 의 `MACHINE_AST` 뜻(aston/astoff 만 바꿈)과 맞지 않음 — (가) 를 뒷받침 | `ast.h` 123–142 행은 §441 grep 출력에 있음 | ✅ |
| `_last_hardclock`(8 B, 64 비트 산술 → `ns_time_t`)은 `kern_clock` 의 잠정 정의로 보이며, 다시 만든 `kern_clock` 은 아직 언급하지 않음(M5) | 원본 크기 8 확인(§441) | ✅ M5 항목에 더함 |
| 정의 파일은 바이트로 정해지지 않음(trap 등도 가능) → 사용자 결정 | — | ✅ |

고친 후보 (가):
- m68k 덮어쓰기 `kern/ast.c` 는 07 본 파일 76 행(`#endif MACHINE_AST`) 뒤에 `volatile ast_t\tneed_ast[NCPUS];\t/* plan 441 (m68k): Mach4 kern/ast.c:58 */` 한 줄을 끼웁니다.
- 출처는 Mach4 `kernel/kern/ast.c:58`(Darwin `kern/ast.c:82` 도 같은 줄)입니다. 07 `ast.c` 에는 CMU 고지가 이미 있지만 Mach4 판(Utah 포함) 고지 여부를 기록합니다.
- 예측: `ast` 객체는 기호 하나만 UNDF → COMMON(4) 으로 바뀌고 절 바이트는 그대로이며, 205 의 OBJECT_MATCH 는 그대로입니다.

### 441.2 사용자 결정 D071 과 구현 계획(코딩 전)

- 사용자 결정 **D071**: "ast.c 덮어쓰기 (Recommended)".
- 덮어쓰기 `07_kernel/v183.34/m68k/src/kern/ast.c` 는 07 본 파일 76 행 뒤에 다음을 끼웁니다.
  - 계획 404(`vm/vm_kern.c`) 선례대로 Mach4 고지(Mach4 `kernel/kern/ast.c` 1–28 행)를 먼저 넣습니다.
  - 그 뒤에 Mach4 58 행과 같은 정의 줄을 넣습니다.
- 여러 줄 고지에는 줄마다 표시를 달 수 없으므로 `stage_m68k.py` 의 파생 검사에 **묶음 표시**를 더합니다.
  - `plan 441 (m68k) begin` 이 있는 줄부터 `plan 441 (m68k) end` 가 있는 줄까지가 끼운 줄로 셈해집니다.
  - 표시별 줄 수는 등록합니다(등록 수 = 묶음 전체 줄 수).
  - 묶음이 닫히지 않거나 겹치면 거부합니다. 음성 시험을 다시 합니다.
- `EXCEPTS[441]` 은 §438 과 같습니다(`x86-subr_prf`·`x86-kern_server`). 기준 run 과 비교하므로 `ast` 는 비 STABS 절이 같아야 합니다.
- 미리 정한 기준(새 run)은 다음과 같습니다.
  - 비 STABS 절이 같은 것 203, 다른 것은 위 두 예외뿐입니다.
  - OBJECT_MATCH 148 은 그대로입니다.
  - `ast` 객체의 `_need_ast` 는 COMMON(값 4) 입니다.
  - 원본에 없는 새 미정의 기호 0, x86 관문은 불변입니다.
- 기록: PROVENANCE·MODIFICATIONS 에 행을 덧붙입니다. 출처는 nextmach(본 파일) + mach4 `kernel/kern/ast.c:58`(revision 은 PROVENANCE 의 기존 mach4 행과 같은 것)입니다. diff `06_reconstruction/evidence/m68k-ast.diff`, 기록 `09_validation/reconstruction/m3-m68k-need-ast-20261009.json` 입니다.

### 441.3 실행 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-need-ast-20261009.json`

07 덮어쓰기와 기록:
- `v183.34/m68k/src/kern/ast.c` 는 07 본 파일 76 행 뒤에 32 줄 묶음(`plan 441 (m68k) begin`…`end`)을 끼운 것입니다.
  - 묶음은 Mach4 `kernel/kern/ast.c:1-28` 고지와 58 행 정의 줄입니다.
  - diff 는 `06_reconstruction/evidence/m68k-ast.diff` 입니다.
- PROVENANCE 1072 → 1073, MODIFICATIONS 596 → 597(덧붙이기만).

`stage_m68k.py`:
- 묶음 표시를 지원합니다(시작 줄부터 끝 줄까지 셈, 닫히지 않음·겹침·다른 표시 섞임 거부). `MARKERS` 에 `ast.c: 32`, `EXCEPTS[441]` 를 더했습니다.
- 정상판 4 개는 통과했습니다.
- 음성 시험은 모두 거부했습니다. 대상은 묶음 미종결, 시작 없는 끝, 묶음 안 줄 추가·삭제, 묶음 밖 수정, 표시 없음, 묶음 둘, 묶음 안 다른 표시, 그리고 이전 경우들입니다.
  - 처음 두 경우는 바꿀 줄을 07 본문 머리에서 잘못 골랐습니다(같은 문장이 2 행에도 있음). 묶음 안 줄로 다시 시험했습니다.

결과:
- 스테이징 `m0p441-stage` 는 888 파일이고, x86 관문 7 스테이징이 같습니다.
- run `m3p441-cc1` 은 205 명령이 모두 종료 0 입니다. 도구 해시는 실행 전후가 같습니다.
- 미리 정한 값과 같습니다.
  - 비 STABS 절이 같은 것 203 이고, 다른 것은 예외 둘(`kern_server`·`subr_prf`)뿐입니다.
  - OBJECT_MATCH 148 은 그대로입니다. 잃은 것 0, 원본에 없는 새 미정의 기호 0 입니다.
  - `ast` 객체의 `_need_ast` 는 **COMMON(4)** 입니다(나머지 6 객체는 UNDF 그대로).
- 남은 M5 항목(§441·441.1):
  - m68k `_hardclock` 의 `clock_value(1)`·`last_hardclock`(`ns_time_t`, `kern_clock` 의 잠정 정의로 보임) 블록 작성.
  - 기계 의존 trap 두 객체의 `need_ast` 참조.

## 442. M3-18 세부 계획 — m68k 커널 비공개 레지스터 색인(`PC`·`SP`·`PS`·`R0`·`R1`)과 남은 컴파일 실패 3 개(조사·결정 대기; 07 변경 없음, 2026-10-09)

배경: §430 부터 m68k 에서 컴파일되지 않는 공통부 C 가 3 개 있습니다.
- `bsd/kern/mach_process.c:170` 과 `bsd/kern/kern_exec.c:482` 는 `PC` 가 선언되지 않았습니다(`SP` 도 씀).
- `kern/ns_timer.c:43·47·147·150` 은 i386 인라인 어셈블리 `divl` 를 씁니다.

확인한 사실(이번 세션):
- 두 소스는 `#import <machine/reg.h>` 로 SDK `bsd/machine/reg.h` → `bsd/m68k/reg.h` 를 읽습니다. m68k SDK `bsd/m68k/reg.h` 에는 `excp_frame` 등만 있고 `u_ar0` 색인이 없습니다(공개판).
- NeXTMach mk-108.1 `next/reg.h:198-203` 에는 "offset definitions into u.u_ar0 for machine independent code" 로 `R0 0`·`R1 1`·`SP 15`·`PS 17`·`PC 17` 이 있습니다.
- 원본 m68k 바이트는 이 색인과 맞습니다(python: 15×4 = 0x3c, 17×4 = 0x44).
  - `_execve`(0x40048fc) 범위에서 `movel a3,a0@(0x3c)`, `movel a0@(0x3c),d0`/`movel d0,a0@(0x3c)`(SP − NBPW), `movel d0,a0@(0x44)`(PC = entry point) 를 씁니다.
  - `_ptrace`(0x400ad9a) 범위에서 `orl d0,a3@(0x44)`(PS 비트) 를 씁니다.
- x86 선례: 같은 문제(SDK 공개판에 색인 없음)를 `07_kernel/nextdev_private/bsd/i386/reg.h`(설명 주석 + Darwin 의 `KERNEL_PRIVATE` 본문, 계획 144)로 풀었습니다. `07_kernel/nextdev_private/` 와 SDK 사본 `07_kernel/nextdev/` 는 통째로 git 무시 대상입니다(`.gitignore:72-73`; D017 SDK 라이선스 미정).
- `ns_timer.c` 의 `divl` 는 i386 전용 소스 블록입니다. m68k 원본의 해당 함수를 읽어 m68k 판을 작성해야 하는 **M5 작성 항목**이며, 이번 범위에서 뺍니다.

결정이 필요한 것(사용자): m68k 레지스터 색인을 어디에 둘지.
- (가) x86 선례대로 로컬 전용 `07_kernel/nextdev_private/bsd/m68k/reg.h` 에 둡니다.
  - 내용은 SDK m68k 본문 + NeXTMach `next/reg.h:198-203` 색인 블록(`#ifdef KERNEL_PRIVATE`)입니다.
  - `stage_m68k.py` 가 SDK 사본 뒤에 `nextdev_private` 의 m68k 파일을 덮어 놓습니다.
  - 커밋되지 않습니다(SDK 본문 때문).
- (나) 공개되는 m68k 덮어쓰기 트리에 SDK 본문 없이 작성 머리 `src/machdep/m68k/reg_private.h`(NeXTMach 색인 6 줄, D013)를 두고, 두 소스의 m68k 판이 `#import` 합니다(D070 꼴 표시 줄).
- (다) SDK 본문 + 색인을 공개 덮어쓰기 `src/bsd/m68k/reg.h` 에 둡니다(SDK 본문이 공개됨 — D017 과 충돌 가능).

시험(결정 뒤): 새 스테이징으로 205 + 두 객체 = 207 개를 컴파일합니다.
- 미리 정한 기준:
  - 두 객체가 컴파일되어야 합니다.
  - 다른 205 개는 이전 run 과 비 STABS 절이 같아야 합니다(예외 누적 2 개).
  - 원본에 없는 새 미정의 기호가 0 이어야 합니다.
- 두 객체의 원본 대조 결과(OBJECT_MATCH 여부)는 측정합니다. 판정 관문은 아닙니다(소스 쪽 차이가 더 있을 수 있음).

### 442.1 교차검토(Opus 5.5 서브에이전트) 판정과 결론 — 계획의 중심 사실이 틀림

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **SDK m68k `bsd/m68k/reg.h:195-200` 에 이미 `R0 0`·`R1 1`·`SP 15`·`PS 16`·`PCH 16`·`PCL 17` 이 있음; 없는 것은 `PC` 뿐** | SDK 사본 190–202 행 읽음 | ✅ **내 오류**: 예비 조사에서 `grep -v … \| head -60` 으로 잘린 출력만 보고 "색인 없음" 이라 적음 |
| 컴파일 실패는 `PC` 하나(`SP` 는 정의됨) | §430 진단 기록(검토자 인용)과 위 SDK 행 | ✅ |
| 원본 `_ptrace` 는 `PC` 를 둘로 나눠 OR: 0x400aee4–aee8 `swap; extl; orl d0,a3@(0x40)`(슬롯 16 = PCH), 0x400aeec–aef4 `swap; clrw; orl d0,a3@(0x44)`(슬롯 17 = PCL) — §442 의 "0x44 = PS 비트" 해석은 틀림; PT_STEP 은 0x400af3a–af40 `moveq #9; cmpl a2@; bne; bset #7,a3@(0x40)` = `PS 16` 에 `PSL_T`(= `SR_TSINGLE << 16`, `psl.h:43`) | 원본 목록 0x400aee0–0x400af44 읽음, `psl.h:43` grep | ✅ **내 오류**(해석) 정정 |
| 원본 `_execve` 의 PC 쓰기도 나뉨: 0x4005044 `movew a6@(0xff78),a0@(0x42)`(상위 반), 0x4005052–505e `swap; clrw; orw a0@(0x46),d0; movel d0,a0@(0x44)` | 원본 목록 0x4005040–0x4005062 읽음 | ✅ `u.u_ar0[PC] = entry` 한 줄로는 이 바이트가 나오지 않음 |
| NeXTMach `next/reg.h` 의 `PC 17`·`PS 17` 은 다른 `struct regs`(`short pad`) 기준이라 1997 바이트와 맞지 않음; `PC 17` 을 더하면 SDK 틀에서 형식 낱말을 덮어쓰는 틀린 코드 | 위 두 사실(원본은 0x40/0x42/0x44/0x46 을 나눠 씀) | ✅ 선택지 가·나·다(머리에 `PC` 정의)는 모두 버림 |
| x86 선례(`nextdev_private/bsd/i386/reg.h`)는 SDK 에 i386 reg.h 가 아예 없어서였고, m68k 는 SDK 파일이 있고 맞음 | x86 PROVENANCE 행 설명(§442 사실) | ✅ |
| NeXTMach 에 `PCH`/`PCL` 을 쓰는 C 코드 없음 | `grep -rn 'PCH\|PCL'` — `next/reg.h` 밖 결과는 모두 다른 이름(`TS_HUPCLS`·`PCLK_*` 등) | ✅ → m68k 판 두 소스는 원본 바이트에서 작성(D024) |
| `ns_timer.c` 는 무조건 i386 `divl` 인라인 어셈블리; m68k 원본 `_ns_time_to_timeval`(0x404e712)은 68020 `divull`·`divul` 두 단계 나눗셈 | 07 소스 43–50·147–150 행은 §430 기록, 원본 주소는 검토자 인용(미검증) | ⚖️ M5 작성 항목으로 둠(문구 "무조건 i386 asm") |
| `machine/reg.h` 를 들이는 스테이징 소스 14 개; `PS`·`R0`·`R1` 은 `kern_xxx.c` 의 `#ifdef COMPAT`(정의 안 됨) 안에서만 | 검토자 grep 인용 | ⏭️ 머리를 바꾸지 않으므로 영향 없음 |

결론:
- 결정할 머리 자리는 없습니다(SDK 가 맞음). 사용자 질문은 하지 않습니다.
- 남은 세 컴파일 실패는 모두 **M5 작성 항목**입니다.
  - `mach_process.c`·`kern_exec.c` 의 m68k 판: SDK `PCH`/`PCL` 로 PC 를 나눠 쓰는 블록을 원본 바이트에서 작성하고, 표시 묶음으로 끼웁니다.
  - `ns_timer.c` 의 m68k 판: `divull`/`divul` 꼴의 m68k 인라인 어셈블리.
- M3 범위(머리·구성·생성물)는 이 셋에 대해 더 할 일이 없습니다. 07 은 바꾸지 않았습니다.

## 443. M3-19 세부 계획 — M3 끝 조건 점검: 덮어쓰기 구조체 오프셋 탐침과 근거 집계(07 변경 없음; 코딩 전, 2026-10-09)

배경: MULTIARCH 표준 M3 의 끝 조건은 두 가지입니다.
- "M0-3 probe 와 원본의 구조체 오프셋 근거가 맞음"
- "생성 코드가 GCC 2.7 규칙을 만족"

148 OBJECT_MATCH 객체가 쓰는 구조체 변위는 바이트 일치로 이미 확인되었습니다. 그러나 프로젝트가 작성한 m68k 머리(§430–441)의 구조체는 "원본 변위를 내도록 썼다" 는 주장뿐이고, 그 변위가 실제 컴파일러로 나오는지 따로 잰 적이 없습니다.

방법:
1. 탐침 객체를 만듭니다(새 도구 `10_tools/reconstruction/m3_m68k_offsets.py`).
   - 스테이징 `m0p441-stage` 를 복사하고 `src/probe/m68k_offsets.c` 하나를 더합니다(SHA 매니페스트).
   - 탐침은 `int off[] = { ((int)&((struct X *)0)->m), …, sizeof(…) }` 를 `__data` 에 둡니다.
   - 컴파일 명령은 run `m3p441-cc1` 의 `kern/ast.c` 줄과 같은 플래그(`-arch m68k … -g -O2 -c`)이고, 소스·출력만 바꿉니다.
2. 미리 정한 기대값(원본 바이트 근거)은 다음과 같습니다.
   - `struct pcb`(`machdep/m68k/thread.h`): `pcb_regs` 0x48, `pcb_regs_valid` 0x4c(`_init_task` 의 USER_REGS, §430), `pcb_flags` 0x54(aston/astoff `bset/bclr #4,…@(0x54)`, §431–432).
   - `struct pmap`(`machdep/m68k/pmap.h`): `stats.resident_count` 0x10(`_task_info`, §430).
   - `struct mon_global`(`mon/global.h`): `mg_minor` 0x30a, `mg_seq` 0x30c, `mg_anim_run` 0x30e, `mg_major` 0x312(`_panic`, §437).
   - SDK `struct regs`(`bsd/m68k/reg.h`): `r_evec` 0x40, `r_pc`(`r_evec.e_pc`) 0x42. 이것은 `_execve`·`_ptrace` 의 0x40/0x42/0x44/0x46 쓰기(§442.1) 근거이며 M5 작성의 바탕이 됩니다.
   - 탐침 값이 기대와 하나라도 다르면 해당 머리를 고치기 전에 진단만 합니다.
3. 실기 run 을 새 ID 로 돌리고, 실행 전후 도구 해시를 남깁니다. `macho_obj` 로 `__data` 를 읽어 대조합니다(big-endian 4 B).
4. 근거를 집계합니다(기록 `09_validation/reconstruction/m3-m68k-closure-20261009.json`).
   - M0-3 ABI 탐침 기록(§412).
   - §431·§436 명령 수준 진단의 구조체 변위(D-struct) 덩어리 수.
   - 생성물: `gen_config_headers.py` x86·m68k `--check` 종료값, §434 MIG 24/24.
   - 현재 m68k 수치: 205 중 148, 정확 객체 306.
   - M4·M5 로 넘긴 항목 목록.
5. 끝 조건 판정 문단은 MULTIARCH 표준에 적습니다.

### 443.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 기대 변위의 원본 근거 확인: `_init_task` 0x4002dec `tstl a0@(0x4c)`·0x4002df2 `movel a0@(0x48)`, 0x4049464–6e `bset #4,a0@(0x54)`(0x40494ae `bclr`), `_task_info` 0x4052588 `movel a0@(0x10),d3`, `_panic` 0x400bcb8–c4 | §430–437 기록과 이번 세션 원본 목록 확인(`_panic` 줄은 §437.1 에서 읽음) | ✅ 주소를 기록에 인용 |
| `mg_anim_run`(0x30e)의 근거는 `_panic` 이 아니라 0x408a490·0x408acaa·0x40946e6 의 `movel aN@(0x30e),d0`(4 B) | 원본 목록 세 주소 grep: 셋 다 `movel a1/a4@(0x30e:w),d0` | ✅ 근거 인용 |
| 정렬 4 라도 pcb·pmap 은 같은 변위 → 컴파일러 ABI 를 실제로 시험하는 것은 mon_global·regs 뿐 | 설계 확인 | ✅ 기록에 적음 |
| **작성하지 않은 Mach 구조체도 원본 바이트로 대조**: `sizeof(struct task)` 0x80(`_task_init` 0x4051ddc `pea 0x80`, zinit), `sizeof(struct thread)` 0x184(`_thread_init` 0x40527ec `pea 0x184`), `offsetof(thread, pcb)` 0x24, `offsetof(task, map)` 0x8, `offsetof(vm_map, pmap)` 0x20 | 원본 목록 0x4051dc8–ddc·0x40527e0–ec grep(`pea 0x80`·`pea 0x184` 가 zinit 인자 자리) | ✅ 탐침에 더함(진짜 "탐침 대 원본" 대조) |
| `reg.h:174 #if MONITOR` — 0x40 은 MONITOR 미정의일 때만; 스테이징·명령에 정의 없음 | grep: `reg.h` 174·186 행, generated·cc.cmd 0 건 | ✅ 가정으로 적음 |
| 선례 탐침 `probes/c_layout.c` 의 `KR_OFF` 매크로·표시 낱말·비정적 전역을 씀 | 파일 1–20 행 읽음 | ✅ |
| 머리는 명시 경로로(`<machdep/m68k/thread.h>`·`<machdep/m68k/pmap.h>`·`<mon/global.h>`·`<bsd/m68k/reg.h>`), 비트필드 주소 대신 `sizeof(struct excp_frame)` 8·`sizeof(struct regs)` 0x48 | 설계(빌드로 확인) | ✅ |
| diag3 에는 `d_struct_blocks` 키가 없음 → 도구가 종류를 직접 셈; X·R 덩어리는 "구조체 아님" 의 증명이 아님 | diag2 키 확인(§443 사실 출력), diag3 요약 형태 확인 | ✅ 기록 문구에 한계 명시 |
| "생성 코드 GCC 2.7 규칙" 은 `--check`·MIG 일치만으로는 부족 → 그것을 실제로 쓴 m68k 컴파일 run(cc-744.13, `m3p441-cc1`)과 `08_build/GCC27_COMPATIBILITY.md` 규칙 대조를 인용 | 설계 | ✅ 기록에 run 과 해당 문서 절 인용 |
| 원본 `sizeof(struct pcb)`·`sizeof(struct mon_global)` 은 비교 불가 | 설계 | ✅ "비교 안 함" 으로 표시 |
| 스테이징 경로는 `src/probe/…`, 명령 줄 경로는 `src/src/probe/…`(run 의 src 아래) | `cc.cmd` 의 `src/src/kern/ast.c` 꼴 | ✅ 둘 다 명시 |

고친 탐침 목록(실행 전 고정): 표시 `KRM3`…`END!` 사이에 다음 순서로 둡니다.
- pcb 3, pmap 1, mon_global 4
- regs: `r_evec`·`r_pc`·`sizeof(struct excp_frame)`·`sizeof(struct regs)`
- task·thread: `sizeof(struct task)`·`sizeof(struct thread)`·`offsetof(struct thread, pcb)`·`offsetof(struct task, map)`·`offsetof(struct vm_map, pmap)`

기대값은 위 근거대로입니다(`sizeof` 둘은 원본 근거 없음 — 기록만).

### 443.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-closure-20261009.json`

도구는 `10_tools/reconstruction/m3_m68k_offsets.py`(0848118…) 입니다. 실행 전후 해시가 같습니다(`08_build/artifacts/m3p443/tools-pre.sha`).
- 스테이징 `m0p443-stage` = `m0p441-stage` + `src/probe/m68k_offsets.c` 이고, 889 파일입니다.
- run `m3p443-pr1` 은 1 명령이 종료 0 이고 게시되었습니다. 명령은 `kern/ast.c` 와 같은 플래그(cc-744.13 `-arch m68k … -g -O2`)입니다.

탐침 결과: 원본 근거가 있는 **15/15 가 기대값과 같습니다**.

| 항목 | 탐침 값 | 원본 근거 |
|---|---|---|
| `pcb.pcb_regs`·`pcb_regs_valid`·`pcb_flags` | 0x48·0x4c·0x54 | `_init_task` 0x4002df2·0x4002dec, aston 0x404946e |
| `pmap.stats.resident_count` | 0x10 | `_task_info` 0x4052588 |
| `mon_global` `mg_minor`·`mg_seq`·`mg_anim_run`·`mg_major` | 0x30a·0x30c·0x30e·0x312 | `_panic` 0x400bcbe·cb8·cc4, 0x408a490 등 |
| `regs.r_evec`·`r_pc` | 0x40·0x42 | `_ptrace` 0x400aee8·0x400af40, `_execve` 0x4005044 |
| `sizeof(struct task)`·`sizeof(struct thread)` | 0x80·0x184 | `_task_init` 0x4051ddc·`_thread_init` 0x40527ec 의 zinit 인자 |
| `thread.pcb`·`task.map`·`vm_map.pmap` | 0x24·0x8·0x20 | `_init_task`·`_task_info` |

- 기록만 하는 값은 `sizeof(struct excp_frame)` 8, `sizeof(struct regs)` 0x48 입니다(원본 근거 없음).
- pcb·pmap 은 정렬 2·4 어느 쪽이든 같으므로, 컴파일러 ABI(정렬 2)를 실제로 시험한 것은 `mon_global`·`regs` 입니다(§443.1).

근거 집계:
- 명령 수준 진단의 덩어리 종류:
  - §431: CALL 31·X 48·D-frame 20·R 167·INS 37·IMM 6·DEL 7.
  - §436: INS 3·R 58·X 17·CALL 3·DEL 2.
  - 두 진단 모두 **D-struct(구조체 변위만 다른 덩어리) 0** 입니다. X·R 은 구조체 차이가 없다는 증명이 아닙니다.
- 생성물: `gen_config_headers.py` x86·m68k `--check` 종료 0, MIG 24/24(§434). 이 머리·출력을 실제로 쓴 m68k 컴파일은 cc-744.13 run `m3p441-cc1`(205 명령 종료 0)입니다.
- 현재 m68k 수치: 205 중 OBJECT_MATCH 148, 정확 객체 306(`__text` 78.89 %).

**M3 끝 조건 판정**
- (1) 구조체 오프셋: M0-3 ABI 탐침(§412, 정렬 2)과 이번 탐침이 원본 바이트 근거 15/15 와 맞고, 진단 D-struct 0 입니다. → **충족**.
- (2) 생성 코드: 구성 머리는 표와 명령으로, MIG 는 재생성 해시가 일치하며, 둘 다 cc-744.13 m68k 로 컴파일되었습니다. → 머리·생성물 범위에서 **충족**.
- `08_build/GCC27_COMPATIBILITY.md` "완료 판정" 3–5(전체 번역 단위 컴파일·링크·부팅 입력)는 M4–M8 에서 채웁니다.
- 따라서 **M3 를 닫습니다.** 넘기는 항목은 다음과 같습니다.
  - M5(공통부 소스): `mach_process`·`kern_exec` PCH/PCL, `ns_timer` m68k 나눗셈, `_hardclock` `clock_value`·`last_hardclock`, `kern_uname`, PMON, `spldma`, `_byte_swap_*`·`_us_spin`·ObjC 호출 제거, `in_pcb`·`ip_output`·`ip_icmp`·`tcp_input`·`vfs_dnlc` 소스 꼴, `ufs_vfsops` `copyinmsg`·프레임, 비청정 30.
  - M4(기계 의존부): m68k 전용 파일 후보 106·묶음 4·미배정 33·자료만 16, trap 의 `need_ast` 참조, `mon/global.h` 전체판.
  - 구성 미룸 6(§438).

## 444. M5-1 세부 계획 — m68k `mach_process.c`·`kern_exec.c` 의 PC 쓰기를 SDK `PCH`/`PCL` 로 작성(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §442.1 에서 두 소스가 m68k 에서 컴파일되지 않는 이유가 `PC` 하나임을 확인했습니다. SDK m68k `reg.h` 에는 `PS 16`·`PCH 16`·`PCL 17` 이 있고, 원본은 PC 를 둘로 나눠 씁니다. NeXTMach 에 이 꼴의 코드가 없으므로 원본 바이트에서 작성합니다(D024).

확인한 사실(원본 목록 직접 읽음):
- `_ptrace` 0x400aed0–0x400aef4(07 `mach_process.c:162-170` PT_STEP/PT_CONTINUE):
  - `locr0`(a3) = `thread->_uthread->uu_ar0` 이고, `movel a2@(0x8),d0`(uap->addr), `moveq #1; cmpl; beq`(addr != 1) 입니다.
  - `swap d0; extl d0; orl d0,a3@(0x40)` → `locr0[PCH] |= (int)uap->addr >> 16`
  - `movew a2@(0xa),d0; swap d0; clrw d0; orl d0,a3@(0x44)` → `locr0[PCL] |= (int)uap->addr << 16`
  - 지우는 `andl` 이 없으므로 대입이 아니라 OR 입니다.
- `_execve` 0x400503c–0x400505e(07 `kern_exec.c:482`):
  - `movel u,a0; movel a0@,a0`(u.u_ar0)·`movew a6@(0xff78),a0@(0x42)` → PCH 슬롯의 하위 반에 `entry_point` 의 상위 반을 씁니다.
  - 다시 `u.u_ar0` 를 읽어 `movel a6@(0xff78),d0; swap; clrw; orw a0@(0x46),d0; movel d0,a0@(0x44)` → `u.u_ar0[PCL] = (entry << 16) | (u.u_ar0[PCL] & 0xffff)` 꼴입니다.
  - 첫 줄의 C 꼴은 후보 `u.u_ar0[PCH] = (u.u_ar0[PCH] & 0xffff0000) | ((unsigned)entry >> 16)` 입니다(GCC 가 하위 반 `movew` 로 바꾸는지는 실행이 판정).
- 기계 판별: §430 시험 스테이징의 Darwin 배정 머리 `#elif defined (__m68k__)` 가 m68k 가지를 골랐으므로 cc-744.13 `-arch m68k` 는 `__m68k__` 를 정의합니다.

방법:
1. 덮어쓰기 두 소스는 07 본 파일에 표시 묶음(`plan 444 (m68k) begin`…`end`)을 끼웁니다. 원래 줄은 지우지 않고 `#else` 가지에 남깁니다(파생 검사는 끼우기만 허용).
   - `mach_process.c`: 169 행 `if` 뒤에 `#ifdef __m68k__` + `{ locr0[PCH] |= …; locr0[PCL] |= …; }` + `#else` 를 끼우고, 170 행 뒤에 `#endif` 를 끼웁니다.
   - `kern_exec.c`: 482 행 앞에 `#ifdef __m68k__` + 두 줄 + `#else` 를 끼우고, 뒤에 `#endif` 를 끼웁니다.
   - 묶음은 파일마다 둘(시작·끝 위치가 갈림)입니다. `MARKERS` 에 줄 수를 등록합니다.
2. `stage_m68k.py --plan 444`(예외는 §441 과 같음)로 스테이징합니다. 시험 run 은 이 두 객체만 컴파일합니다(§430 `cc.cmd` 의 두 줄, 접두 `P444__`).
   - 스테이징 차이가 이 두 `.c` 뿐임을 매니페스트로 확인합니다. 그러면 다른 205 객체는 입력이 같으므로 다시 컴파일하지 않습니다.
3. 비교(미리 정한 기준):
   - 두 객체가 컴파일되어야 합니다.
   - 원본에 없는 새 미정의 기호 0 이어야 합니다.
   - 외부 구간 `_ptrace`·`_execve` 의 해당 덩어리(§436 도구 방식 진단)에서 PC 쓰기 부분이 원본과 같아야 합니다.
   - 객체 전체 OBJECT_MATCH 여부와 그 밖의 차이는 측정·진단합니다(다른 소스 차이가 있을 수 있음 — 관문 아님).
   - PC 쓰기 부분이 원본과 다르면 C 꼴을 바꿔 새 run 으로 다시 시험합니다(시도마다 기록).
4. 기록: PROVENANCE·MODIFICATIONS(작성 줄, D024), diff `06_reconstruction/evidence/m68k-pc-split.diff`, `09_validation/reconstruction/m5-m68k-pc-split-20261009.json`.

### 444.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 판독은 맞고(OR, `andl` 없음), 구조체 `->r_pc` 꼴은 제외: 같은 원본 `_sendsig` 0x409488a·`_sigreturn` 0x409495c 는 `r_pc` 를 `movel …,a2@(0x42)` 한 번으로 씀 | 원본 목록 두 주소 grep | ✅ 후보 (c) 제외 |
| `_execve` 는 두 문장(0x400504a 에서 `u` 를 다시 읽음); PCH 줄은 짧은 낱말 대입 꼴 `((short *)&u.u_ar0[PCH])[1] = entry >> 16` 이 가장 그럴듯, 그다음 and/or 꼴 | 판독은 §444 사실과 같음; 순위는 미검증 의견 | ⚖️ 후보를 모두 시험 컴파일로 판정 |
| `_ptrace` 의 PCL 쪽은 `movew a2@(0xa)`(하위 반만 읽기)라 `(int)uap->addr << 16` 이 아니라 `& 0xffff` 또는 `(u_short)` 꼴일 가능성(같은 컴파일러가 `_execve` 에서는 `movel` 로 읽음) | `_execve` 0x4005052 `movel a6@(0xff78),d0` 와 `_ptrace` 0x400aeec `movew a2@(0xa),d0` 비교 | ✅ 후보에 더함 |
| 시도마다 run 을 돌리지 말고 후보 꼴을 한 run 에서 탐침 파일로 컴파일(§443 선례) | 설계 | ✅ 변형 파일 방식으로 바꿈 |
| 기계 판별은 07 관례대로 `#if m68k`(`kern/time_stamp.c:55·68`, `kern_sig.c:181 #ifdef i386`) | 두 파일 grep | ✅ `#if m68k` 사용 |
| 한 파일에 같은 표시 묶음 여럿 가능; 한 줄짜리 `#endif` 는 묶음이 아닌 단순 표시 줄 | `check_derived` 설계(§441) | ✅ |
| `EXCEPTS[444]` 가 없으면 `--plan 444` 거부 | §438 경험 | ✅ 도구 변경에 넣음 |
| 원본 `_execve` 에는 PMON 호출(0x4005150–516c `btst #4,0x40b60c0` … `bsr _pmonlogexec`)이 있고 07 에는 없음 → `kern_exec` 은 PC 가 맞아도 OBJECT_MATCH 아님 | 원본 목록 0x4005150–516c 읽음, `_pmonlogexec` 0x4092b56 | ✅ 예측에 넣음 |
| D024 는 객체마다 OBJECT_MATCH 를 조건으로 함 → `kern_exec` 은 PMON 전까지 "중간 상태" 로 기록 | DECISIONS 28 행 읽음 | ✅ |
| 비교 기록을 쓰는 도구를 명시할 것 | — | ✅ 새 도구 `m5_m68k_pc.py` |

고친 방법(실행 전 고정):
1. **변형 시험 run**(새 도구 `10_tools/reconstruction/m5_m68k_pc.py`)
   - 스테이징 `m0p441-stage` 를 복사하고, `src/probe/pc/` 에 07 본 파일 + 후보 블록인 변형 소스를 둡니다.
   - `mach_process` 변형:
     - P1 `|= (int)uap->addr >> 16` / `|= (int)uap->addr << 16`
     - P2 PCL `|= ((int)uap->addr & 0xffff) << 16`
     - P3 PCL `|= (u_short)(int)uap->addr << 16`
   - `kern_exec` 변형:
     - E1 PCH and/or 꼴 + PCL `& 0xffff`
     - E2 PCH 짧은 낱말 대입 + PCL `& 0xffff`
     - E3 짧은 낱말 + PCL `(u_short)`
     - E4 and/or + PCL `(u_short)`
   - §430 `cc.cmd` 의 두 줄과 같은 플래그로 컴파일합니다(접두 `P444__`).
2. 실기 `otool -tv`(읽기 전용)로 변형 객체를 풉니다. 원본의 PC 쓰기 명령열과 비교합니다(주소·`a6` 변위는 가리고 명령·레지스터·나머지 피연산자는 그대로).
   - `_ptrace` 기준: 0x400aeda–0x400aef4 의 10 명령
   - `_execve` 기준: 0x400503c–0x400505e 의 8 명령
   - 같은 변형이 정확히 하나면 그 꼴을 고릅니다. 없으면 진단만 하고 멈춥니다.
3. 고른 꼴을 07 덮어쓰기 두 소스에 `#if m68k` 묶음으로 끼웁니다(`plan 444 (m68k)`). `MARKERS`·`EXCEPTS[444]` 를 더하고, 덮어쓰기 스테이징으로 두 객체를 컴파일합니다(스테이징 차이 = 두 `.c` 확인, x86 관문 포함).
   - 기준: 컴파일 성공, 원본에 없는 새 미정의 기호 0, PC 쓰기 명령열이 원본과 같음.
   - `mach_process` OBJECT_MATCH 여부와 `kern_exec` 의 PMON 차이는 측정해 기록합니다(`kern_exec` 은 중간 상태).

### 444.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pc-variants-20261009.json`(변형), `m5-m68k-pc-split-20261009.json`(최종)

변형 시험(run `m5p444-var1`, 7 명령 종료 0, 실기 otool 목록 SHA 대조):
- 원본 PC 쓰기 명령열과 모양이 같은 것은 P2·P3·E1·E2·E3·E4 입니다.
- P1(`(int)uap->addr << 16`)은 원본의 `movew a2@(0xa)` 대신 `movel a2@(0x8)` 로 읽어 다릅니다(검토 예측대로).
- P2·P3 끼리, E1–E4 끼리는 비 STABS 객체 전체가 같아 바이트로 구별되지 않습니다.
- 미리 정한 "정확히 하나" 규칙은 성립하지 않았고, 사용자 결정 **D072** 로 단순 꼴(P2·E1)을 골랐습니다.

07 덮어쓰기와 기록:
- `v183.34/m68k/src/bsd/kern/mach_process.c` 는 `#if m68k` 묶음 7 줄, `kern_exec.c` 는 5 줄입니다. 07 줄은 `#else` 에 남겼습니다.
- diff 는 `06_reconstruction/evidence/m68k-pc-split.diff` 입니다.
- `MARKERS` 와 `EXCEPTS[444]` 를 더했습니다. 덮어쓰기 `.c` 6 개는 파생 검사를 모두 통과했습니다.
- PROVENANCE 1073 → 1075, MODIFICATIONS 597 → 599(덧붙이기만).

최종 run `m5p444-fin1`:
- 스테이징 `m0p444-stage` 는 888 파일이고, `m0p441-stage` 대비 다른 파일은 두 `.c` 뿐입니다. 그래서 다른 205 객체는 입력이 같아 다시 컴파일하지 않았습니다. x86 관문 7 스테이징은 같습니다.
- 2 명령이 종료 0 입니다. 맨 `m68k` 가 미리 정의돼 있음이 컴파일 성공으로 확인되었습니다(아니면 `#else` 의 `PC` 에서 실패).
- 두 객체 모두 PC 쓰기 명령열이 원본과 같고(각 1 곳), 원본에 없는 미정의 기호는 0 입니다.
- **`x86-mach_process` 는 OBJECT_MATCH** 입니다.
- `x86-kern_exec` 은 NOT_MATCH(`_execve` 만 다름; 객체 2218 B 대 원본 2258 B) 입니다.
  - 덩어리는 PMON 블록 하나입니다: 원본에만 `btst #4,_pmon_flags` → `bsr _pmonlogexec`(0x400514c–, `kern_exec.c:537` 근처)와 그 앞뒤 스택 정리(X 1·DEL 1)가 있습니다.
  - D024 조건(객체 OBJECT_MATCH)을 아직 채우지 못한 **중간 상태** 로 둡니다(PMON 항목에서 마무리).
- 도구 해시: 변형 run 뒤 `cmd2`·`final` 명령을 더해 도구가 바뀌었습니다. 첫 판 해시(026cd263…)는 변형 run 기록, 마지막 판(4d0b7761…)은 최종 기록과 같습니다(`08_build/artifacts/m5p444/tools-pre.sha`).
- m68k 누계: 이름 대응 공통부 C 208 중 **207 컴파일**(`ns_timer` 만 남음), OBJECT_MATCH **149**.

## 445. M5-2 세부 계획 — m68k PMON 1: `kern_exec` 의 `pmonlogexec` 호출(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: 원본 m68k 공통부에서 PMON 호출은 세 객체에만 있습니다(python 으로 원본 목록 전체 검색).
- `kern_exec`: `_pmonlogexec` 1 회(0x400516c)
- `vm_fault`: `_pmonlogcontextflush`·`_pmonlogevent` 각 1 회(0x405cf38·0x405cf82)
- `vm_pageout`: 같은 쌍 2 회(0x40604e0·0x4060522·0x40605f6·0x4060638)

세 곳 모두 `_pmon_flags`(`__common` 0x40b607c, 160 B = int 40 개)의 `+0x44`(= `[17]`)를 검사합니다. x86 원본에는 PMON 기호가 없습니다. NeXTMach 1990 `next/kernel_pmon.h` 는 `DEBUG` 전용 인라인 `pmon_log_event` 이고, 소스 번호·사건 값(`next/pmon_targets.h`)이 1997 원본의 17·0x10000000 등과 맞지 않습니다. 그래서 원본 바이트에서 작성합니다(D024). 이 절은 가장 단순한 `kern_exec` 만 하고, `vm_fault`·`vm_pageout` 은 인자 계산을 따로 분석한 뒤 다음 절에서 다룹니다.

확인한 사실(원본 목록 0x4005134–0x400517e):
- `bcopy(pn.pn_buf, utask->uu_comm, pn_pathlen + 1)` 에서 `lea a4@(0x8),a2` 로 `&utask->uu_comm` 을 a2 에 둡니다.
- 바로 다음이 `btst #4,_pmon_flags+0x44; beq` → `movel a2,sp@-; movel _active_threads,sp@-; movel #0x10000000,sp@-; pea 0x11; bsr _pmonlogexec; addqw #8; addqw #8` 입니다.
- 그 뒤가 `movel a4@,a0; bset #7,a0@(0x28)` = 07 `kern_exec.c:532` `utask->uu_procp->p_flag |= SEXEC` 입니다.
- `btst #4` 는 바이트 +0x44 의 비트 4 = int `[17]` 의 0x10000000 입니다(§431 의 aston 과 같은 변환).
- 따라서 C 꼴은 `if (pmon_flags[17] & 0x10000000) pmonlogexec(17, 0x10000000, current_thread(), utask->uu_comm);` 입니다.

방법:
1. 07 덮어쓰기 `kern_exec.c`(§444 판)의 532 행 앞에 `#if m68k` 묶음(`plan 445 (m68k)`)을 끼웁니다.
   - 블록 안에 `extern int pmon_flags[]; extern void pmonlogexec();` 를 둡니다(새 머리를 만들지 않음).
   - 값은 숫자로 씁니다. 1997 이름은 알 수 없어 지어내지 않습니다.
2. `MARKERS`·`EXCEPTS[445]`(= 444) 를 더합니다. 스테이징 차이 = `kern_exec.c` 하나를 확인하고 x86 관문을 봅니다. 객체 하나를 컴파일합니다.
3. 미리 정한 기준:
   - `x86-kern_exec` OBJECT_MATCH
   - 원본에 없는 새 미정의 기호 0(`_pmon_flags`·`_pmonlogexec` 는 원본에 있음)
   - 아니면 진단만 합니다.
4. `pmon_flags` 의 정의(COMMON)는 이번에 넣지 않습니다(UNDF). §441 과 같은 B2-1 판단이 필요하며, 링크(M7) 전에 정합니다.
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-pmon-exec.diff`, `09_validation/reconstruction/m5-m68k-pmon-exec-20261009.json`.

### 445.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 판독 확인(인자 순서·`_active_threads`·`_pmonlogexec`·`[17]`·0x10000000); `SEXEC` 는 0x80000000(`proc.h:569`)이고 `p_flag` 는 int 라 `bset #7,…@(0x28)` | `proc.h` grep(569 행), F444 목록 663 행 `bset #7,a0@(0x28:w)` | ✅ (내 질문의 0x80 은 틀림 — 판독에는 영향 없음) |
| F444 와 원본 `_execve` 의 차이는 0x400513c 부근뿐(원본 `lea a4@(8),a2; movel a2,sp@-` 대 객체 `pea a4@(8)`, SEXEC 줄 위치, PMON 블록 없음) → 끼울 자리가 맞음 | §444.2 의 덩어리 진단(X 1·CALL 1·DEL 1)과 같은 내용 | ✅ |
| CSE 로 `&uu_comm` 이 a2 에 남는지는 컴파일로만 확인 가능(위험 낮음–중간) | — | ⏭️ 실행이 판정 |
| C89 에서 문장 뒤의 블록 범위 `extern` 은 `{ … }` 안에 있어야 함 | C89 규칙 | ✅ 중괄호 포함(줄 수에 셈) |
| `pmon_flags`·`pmonlogexec` 는 07·스테이징 어디에도 없음(충돌 없음); `current_thread()` = `active_threads[cpu_number()]`, `cpu_number()` = 0 | grep 0 건, 스테이징 `kern/thread.h:345` | ✅ |
| `MARKERS` 에 `plan 445` 항목(`kern_exec.c`: 묶음 전체 줄 수), `EXCEPTS[445]` 필요; 444 항목은 유지 | `check_derived` 설계 | ✅ |
| 한 객체 컴파일·비교 도구가 계획에 없음(`m5_m68k_pc.py` 는 444·`F444__`·두 파일 고정) | 도구 읽음 | ✅ `cmd2`·`final` 을 절 번호·대상 파일 인자로 일반화(444 기록은 그대로) |
| `pmon_flags` 참조는 `__text` 세 곳(+0x44)뿐이고 처음 언급자는 `kern_exec`; `__common` 에서 `kern_exec` 의 COMMON(`_init_exec_args`·`_vm_info_zone`) 사이에 놓임 → 정의 미룸은 B2-1 상 문제없음 | §445 사실(python 검색)과 같음 | ✅ |
| 끼울 자리는 덮어쓰기 판 **537 행**(532 는 07 본 파일 번호) | 덮어쓰기 파일 grep: 537 행 | ✅ **내 오류** 정정 |
| §444 의 `kern_exec` 중간 상태 기록은 445 결과로 갱신된다고 밝힐 것 | — | ✅ |

### 445.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pmon-exec-20261009.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_exec.c` 의 537 행(SEXEC) 앞에 9 줄 묶음(`plan 445 (m68k)`, `#if m68k` 안에 중괄호 블록·블록 범위 `extern` 둘·`if … pmonlogexec(…)`)을 끼웠습니다.
  - diff 는 `06_reconstruction/evidence/m68k-pmon-exec.diff`(07 본 파일 대비, §444 묶음 포함)입니다.
  - PROVENANCE 의 이 파일 행(§444 에서 오늘 쓴 행)을 갱신했고(행 수 1075 그대로), MODIFICATIONS 는 599 → 600 입니다.
- 도구:
  - `stage_m68k.py` 에 `MARKERS`(`plan 445`: `kern_exec.c` 9)·`EXCEPTS[445]` 를 더했습니다. 덮어쓰기 `.c` 파생 검사는 통과했습니다.
  - `m5_m68k_pc.py` 의 `cmd2`·`final` 을 절 번호·대상 파일 인자로 일반화했습니다.
  - 첫 `final` 실행은 내 코드의 변수 이름 겹침(`names`)으로 멈췄고, 고쳐 다시 실행했습니다. 해시는 `08_build/artifacts/m5p445/tools-pre.sha` 에 있고 마지막 판이 기록과 같습니다.
- 스테이징 `m0p445-stage` 는 `m0p444-stage` 대비 `kern_exec.c` 하나만 다릅니다. x86 관문 7 스테이징은 같습니다.
- run `m5p445-fin1` 은 1 명령 종료 0 이고, 실기 otool 목록 SHA 를 대조했습니다.
- 결과: **`x86-kern_exec` OBJECT_MATCH**(외부 구간 모두 같음). PC 쓰기 명령열(§444)도 그대로이고, 원본에 없는 새 미정의 기호는 0 입니다.
  - §444 의 "중간 상태" 는 해소되었습니다(D024 조건 충족).
- `pmon_flags` 정의(COMMON)는 미룹니다(§445.1; `kern_exec`·`vm_fault`·`vm_pageout` 은 UNDF 로 참조).
- m68k 누계: 207 컴파일, **OBJECT_MATCH 150**.

## 446. M5-3 세부 계획 — m68k PMON 2: `vm_fault` 의 사건 마스크 누적과 `pmonlogevent`(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §431 진단에서 `_vm_fault` 의 차이는 다음 셋입니다.
- PMON 사건 마스크(d5)를 함수 곳곳에서 쌓는 덩어리 8 개(INS)
- `pmap_enter` 앞의 기록 블록(CALL)
- 그에 따른 레지스터·프레임 차이(R 48·D-frame 11·X 8)

1997 PMON API 는 NeXTMach 1990 과 다릅니다(§445).

확인한 사실(원본 목록 `_vm_fault` 0x405c43c–0x405d07e, python 으로 분기 대상 조사):
- 시작: `movel #0x2000000,d5` 가 `vm_stat.faults++`(`addql #1,0x40c2404`, 07 114 행) 앞에 있습니다 → `int pmon_event = 0x2000000;` 선언 초기화.
- 마스크 누적 7 곳(`moveq #N,d4; orl d4,d5`):

| 원본 | 값 | 07 자리 | 블록 |
|---|---|---|---|
| 0x405c5a4 | 8 | 331(`first_m = VM_PAGE_NULL`)과 332(`vm_page_zero_fill(m)`) 사이 | — |
| 0x405c656 | 1 | 372(`vm_stat.reactivations++`) 뒤, `if (m->inactive)` 블록 안 | 0x405c626 의 분기가 `orl` 뒤로 감 |
| 0x405c6c0 | 2 | 392(`vm_stat.reactivations++`) 뒤, `if (m->free)` 블록 안 | 0x405c690 의 분기가 `orl` 뒤로 감 |
| 0x405c73c | 16 | 473(`#if NeXT`)과 474(`rc = vm_pager_get(…)`) 사이 | 앞 `if` 블록 뒤 공통 경로 |
| 0x405c86c | 8 | 563(`vm_page_zero_fill(m)`)과 564(`zero_fill_count++`) 사이 | 호출 뒤 |
| 0x405c8ce | 32 | 625(`vm_page_copy(m, first_m)`) 앞 | 쓰기 경로 |
| 0x405c98a | 64 | 693–695 블록 선언 뒤, 697 주석·`if ((fault_type & VM_PROT_WRITE) == 0)` 앞 | `first_object->copy != NULL` 블록 안 |

- `pmap_enter`(07 1140 행) 앞의 기록 블록(0x405cef0–0x405cf88):
  - `if (prot & VM_PROT_WRITE) pmon_event |= 0x100;`(`btst #1,a6@(0xfff3)` = `prot` 의 하위 바이트).
  - `vmstat = (vmlog_send++ & 1) ? vm_page_free_count : (vm_page_inactive_count | 0x8000);`(`moveq #1; andl _vmlog_send; addql #1,_vmlog_send; tstl`). `_vmlog_send` 는 원본 `__common` 0x40c2c28 이고 x86 에는 없습니다.
  - `if (pmon_flags[17] & 0x01000000) pmonlogcontextflush(17, 0x01000000);`(`btst #0` = 상위 바이트 비트 0).
  - `if (pmon_flags[17] & pmon_event) pmonlogevent(17, pmon_event, (atop(vaddr) << 16) | atop(VM_PAGE_TO_PHYS(m)), (pmap_resident_count(map->pmap) << 16) | vmstat, current_thread());`(`lsrl _page_shift` = `atop`, `mach/vm_param.h:118`).

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/vm/vm_fault.c` 를 만들고, 위 자리마다 `#if m68k` 묶음(`plan 446 (m68k)`)을 끼웁니다.
   - 선언 1 개, 누적 7 개, 기록 블록 1 개입니다.
   - 기록 블록 안의 블록 범위 `extern int pmon_flags[], vmlog_send; extern void pmonlogevent(), pmonlogcontextflush();` 와 지역 `int vmstat;` 는 중괄호 블록 안에 둡니다.
   - 값은 숫자로 씁니다.
2. 컴파일 → 실기 otool → 원본 `_vm_fault` 와 전체 정규화 비교(§436 방식, 덩어리 목록)를 합니다.
   - 미리 정한 기준: 최종적으로 `x86-vm_fault` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0.
   - 첫 시도에서 덩어리가 남으면 덩어리별로 원인을 적고 C 꼴을 고쳐 새 run 으로 다시 시험합니다(시도마다 기록; 같은 덩어리가 두 번 연속 줄지 않으면 멈추고 보고).
3. `vmlog_send`·`pmon_flags` 정의(COMMON)는 미룹니다(§445 와 같음).
4. `vm_pageout` 은 다음 절(§447)입니다.
5. 기록: PROVENANCE·MODIFICATIONS, diff, `09_validation/reconstruction/m5-m68k-pmon-fault-20261009.json`.

### 446.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 시작 초기화·누적 7 곳의 07 자리와 블록 소속이 모두 맞음(호출 대상 0x4061846 `_vm_page_zero_fill`, 0x406185e `_vm_page_copy`; 0x405c5a4 는 호출 앞, 0x405c86c 는 호출 뒤) | 기호표 grep(두 주소), §446 분기 대상 조사 출력 | ✅ |
| 기록 블록 판독(`prot` = a6@(0xfff0), `vmlog_send` 짝수면 inactive\|0x8000, flush 비트 0x01000000, 인자 순서, `phys_addr` +0x22, `map->pmap` +0x20, `atop`) 맞음 | `_vmlog_send` 0x40c2c28 기호, §446 판독과 같음 | ✅ |
| 블록 자리는 1128(panic) 뒤 — 1130 `vm_object_unlock(object)` 앞이든 뒤든 사이에 명령 없음; 1130 뒤 권고 | 07 1115–1132 행 읽음 | ✅ 1130 뒤에 둠 |
| 비 PMON 덩어리는 모두 레지스터·프레임 효과(copy_offset 가 레지스터→프레임으로 밀림, `_vm_page_free` 주소 끌어올림·꼬리 합치기 차이) — PMON 변수 하나로 함께 풀릴 가능성(미검증) | §431 덩어리 목록 | ⏭️ 실행이 판정 |
| `movel #pmon_flags+0x44,d3` 를 두 번 쓰는 꼴이 나올지는 미검증 | — | ⏭️ |
| 선언은 지역 변수 끝(112 행 `next_object` 뒤)에 `int` 로 먼저; R 덩어리가 남으면 `register`·선언 순서 변형을 별도 run 으로 | 설계 | ✅ |
| 64 비트 자리의 기준 줄은 700(`if ((fault_type & VM_PROT_WRITE) == 0)`), 697 은 주석 | 07 690–701 행 읽음 | ✅ 695 행(`vm_page_t copy_m;`) 뒤·697 주석 앞에 끼움 |
| `0x100`·`0x8000` 은 `orw`, 작은 값은 `moveq;orl` 로 나오는지는 미검증 | — | ⏭️ |
| 멈춤 기준에 "R 만 남으면 선언 변형을 별도 run 으로" 추가 | 설계 | ✅ |

### 446.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pmon-fault-20261009.json`, 진단 `08_build/artifacts/m5p446/a1-diag.json`

- 07 덮어쓰기 `v183.34/m68k/src/vm/vm_fault.c`(새 파일)는 07 본 파일(출처 darwin01, APSL·CMU 고지 그대로)에 `#if m68k` 묶음 9 개(46 줄, `plan 446 (m68k)`)를 끼운 것입니다.
  - 선언은 112 행 뒤, 누적 7 곳은 331·372·392·473·563·624(빈 줄, 625 `vm_page_copy` 앞)·695 행 뒤, 기록 블록은 1130 행 뒤입니다.
  - diff 는 `06_reconstruction/evidence/m68k-pmon-fault.diff` 입니다. PROVENANCE 1075 → 1076, MODIFICATIONS 600 → 601 입니다.
- 도구:
  - `stage_m68k.py` 에 `MARKERS`(`plan 446`: `vm_fault.c` 46)·`EXCEPTS[446]` 를 더했습니다. 파생 검사는 통과했습니다.
  - `m5_m68k_pc.py` 에 `vm_fault` 와 구간 진단 명령 `diag`(§436 방식)를 더했습니다.
- 스테이징 `m0p446-a1-stage` 는 `m0p445-stage` 대비 `vm_fault.c` 하나만 다릅니다. x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p446-a1`, 1 명령 종료 0, 실기 otool SHA 대조)에서 이미 `_vm_fault` 구간 3138 B 가 원본과 같습니다(덩어리 0).
  - 객체 L1 은 **OBJECT_MATCH** 입니다(외부 구간 `_vm_fault`·`_vm_fault_wire`·`_vm_fault_unwire`·`_vm_fault_copy_entry`·`_vm_fault_wire_fast` 모두 같음). 원본에 없는 새 미정의 기호는 0 입니다.
  - §431 의 비 PMON 덩어리(레지스터 R 48·프레임·`_vm_page_free` 호출 꼴)는 PMON 변수가 레지스터 하나를 차지하면서 모두 함께 풀렸습니다(§446.1 의 예측대로).
  - `final` 기록의 "shape" 항목은 §444 의 PC 쓰기 기준이므로 `vm_fault` 와 무관합니다(0 은 정상).
- `pmon_flags`·`vmlog_send` 정의(COMMON)는 미룹니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 151**.

## 447. M5-4 세부 계획 — m68k PMON 2b: `vm_pageout_scan` 의 두 기록 자리(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

확인한 사실(원본 `_vm_pageout_scan` 0x4060422–0x406070c 읽음; 07 `vm/vm_pageout.c` 는 darwin01 출처):
- 구조는 07 과 같습니다. `MACH_SLOCKS 0` 이라 `vm_object_lock_try` 는 상수가 되어 사라집니다.
- 원본에만 PMON 이 있습니다. 루프 앞에서 `lea _pmon_flags+0x44,a4` 로 `&pmon_flags[17]` 을 끌어올립니다.
- 자리 A(0x40604d0–0x406052c, clean 경로):
  - 앞뒤 문맥은 `did_work = TRUE`(`moveq #1,d4`)·`m->busy = TRUE`(`orb #0x80,a2@(0x20)`) 뒤, `pmap_remove_all`(0x4097e9c) 앞입니다.
  - 문장 1: `if (pmon_flags[17] & 0x01000000) pmonlogcontextflush(17, 0x01000000);`
  - 문장 2: `if (pmon_flags[17] & 0x04000001) pmonlogevent(17, 0x04000001, atop(VM_PAGE_TO_PHYS(m)), (vm_page_inactive_count << 16) | (vm_page_free_count & 0xffff), current_thread());`
  - `orw 0x40c2c0e` 는 `vm_page_free_count` 의 하위 반입니다. §444 E1 처럼 `& 0xffff` 가 `orw mem+2` 로 나옴을 이미 봤습니다.
- 자리 B(0x40605e6–0x4060642, dirty 경로): pager 를 마련하는 `if` 블록 뒤, `pageout_succeeded = FALSE`(`clrl d2`) 앞입니다. 같은 꼴이며 사건 값은 0x04000002 입니다.
- §431 의 비 PMON 덩어리(저장 레지스터 집합에 a4 추가, d2/d3 교대, 끝의 루프 조건 꼴)는 PMON 포인터가 a4 를 차지하는 데서 오는 것으로 봅니다(미검증, 실행이 판정).

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/vm/vm_pageout.c` 를 만듭니다.
   - 자리 A: 07 의 clean 블록 `vm_page_unlock_queues();` 뒤(`pmap_remove_all` 앞)에 둡니다.
   - 자리 B: pager `if` 블록의 닫는 중괄호 뒤(`pageout_succeeded = FALSE;` 앞)에 둡니다.
   - 각 자리에 `#if m68k` 묶음(`plan 447 (m68k)`, 블록 범위 `extern` 은 중괄호 안)을 끼웁니다.
2. `MARKERS`·`EXCEPTS[447]`·`m5_m68k_pc.py` 의 `FILES` 에 `vm_pageout` 을 더합니다. 컴파일 → otool → `_vm_pageout_scan` 진단 → `final` 순으로 합니다.
3. 미리 정한 기준:
   - `x86-vm_pageout` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0.
   - 아니면 덩어리별로 진단해 다시 시도합니다(§446 의 멈춤 기준 같음).
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-pmon-pageout.diff`, `09_validation/reconstruction/m5-m68k-pmon-pageout-20261009.json`.

### 447.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 자리 A·B 의 원본 순서와 07 줄(172 뒤 / 282 의 `}` 뒤·284 앞) 맞음; 호출 대상 0x4097e9c `_pmap_remove_all`·0x406093c `_vm_pager_allocate`·0x405ffea `_vm_object_setpager` | 기호표 grep 세 주소, 07 280–285 행 읽음 | ✅ |
| `vm_page_unlock_queues()` 는 `simple_unlock` 이고 `MACH_SLOCKS 0` 에서 빈 매크로 → 172 앞뒤 어디든 같은 코드 | 스테이징 `vm/vm_page.h:393`, `kern/lock.h:103-104` 읽음 | ✅ |
| 인자 판독(17, 0x4000001/2, `atop(phys)`, `(inactive << 16) \| low16(free)`, `current_thread()`) 맞음 | §447 사실과 같음 | ✅ |
| `& 0xffff` 는 §444 처럼 `(u_short)` 과 바이트로 구별되지 않을 수 있는 꼴 → D072(단순 꼴)를 인용 | §444.2 기록 | ✅ |
| 루프 앞 `lea …,a4` 는 두 자리의 `pmon_flags[17]` 을 루프 불변으로 끌어올린 것으로 보임(미검증); 비 PMON 덩어리(루프 끝 조건·d2/d3·a2 대 d2)는 그 결과로 설명 가능, 함수 끝(331–353)에 따로 소스 차이 없음 | §431 덩어리 목록(INS 1·CALL 2 외는 R·X·D-frame) | ⏭️ 실행이 판정 |
| 덮어쓰기는 새 파일이고 darwin01 APSL·CMU 고지를 그대로 유지; `MARKERS` 줄 수와 PROVENANCE(1076 → 1077)·MODIFICATIONS(601 → 602) 기대값을 적을 것 | — | ✅ |

### 447.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pmon-pageout-20261009.json`, 진단 `08_build/artifacts/m5p447/a1-diag.json`

- 07 덮어쓰기 `v183.34/m68k/src/vm/vm_pageout.c`(새 파일, darwin01 APSL·CMU 고지 그대로)는 172 행 뒤(자리 A)와 282 행 뒤(자리 B)에 `#if m68k` 묶음 둘(26 줄, `plan 447 (m68k)`)을 끼운 것입니다.
  - 꼴은 D072 의 단순 꼴(`& 0xffff`)입니다.
  - diff 는 `06_reconstruction/evidence/m68k-pmon-pageout.diff` 입니다. PROVENANCE 1076 → 1077, MODIFICATIONS 601 → 602(미리 적은 기대값과 같음)입니다.
- 도구: `MARKERS`(`vm_pageout.c` 26)·`EXCEPTS[447]`, `m5_m68k_pc.py` `FILES` 에 `vm_pageout` 을 더했습니다. 실행 전후 해시가 같습니다(`08_build/artifacts/m5p447/tools-pre.sha`).
- 스테이징 차이는 `vm_pageout.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p447-a1`)에서 `_vm_pageout_scan` 748 B 가 원본과 같습니다(덩어리 0).
  - 객체 L1 은 **OBJECT_MATCH** 이고, 원본에 없는 새 미정의 기호는 0 입니다.
  - §431 의 비 PMON 덩어리(저장 레지스터 a4·d2/d3·루프 끝 조건)도 함께 풀렸습니다.
- PMON 정리: 원본 공통부의 PMON 호출 세 객체(`kern_exec`·`vm_fault`·`vm_pageout`)가 모두 OBJECT_MATCH 입니다. 남은 것은 `pmon_flags`·`vmlog_send` 의 정의(COMMON, 링크 전)와 기계 의존부의 PMON 함수(`_pmonlogevent` 등, M4)입니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 152**.

## 449. M5-6 세부 계획 — m68k `ufs_vnodeops`·`ufs_inode` 에서 i386 바이트 교환 빼기(NeXTMach 꼴 복원; x86 트리 변경 없음; 코딩 전, 2026-10-10)

배경: §448 은 멈췄고(사용자 선택 없음), 근거가 분명한 i386 전용 코드 제거(M5)로 넘어갑니다. 07 의 두 파일은 x86 원본에 맞춰 리틀엔디언 디스크 형식용 바이트 교환을 넣은 것입니다(계획 215·217). m68k(빅엔디언) 원본에는 그 호출이 없습니다.

확인한 사실:
- `ufs_vnodeops` §436:
  - 원본 대비 차이는 `_rwip` 의 `byte_swap_dir_block_in`/`_out` 호출과 그 조건(07 `ufs_vnodeops.c:399-400`·`402-403`, "plan 217") 및 그에 딸린 `movel d1,d0` 하나뿐입니다(원본 시작 0x403a056, 54 B).
  - NeXTMach `ufs/ufs_vnodeops.c` 에는 그 줄이 없습니다(grep `byte_swap` 0 건).
- `ufs_inode` §431:
  - `_iget` 에서 원본은 `lea a3@(0x62),a2; pea 0x80; …; bsr _bcopy` 이고, 07 은 `bsr _byte_swap_inode_in` 입니다.
  - `_iupdat` 에서 원본은 `pea 0x80; …; pea a3@(0x62); bsr _bcopy` 이고, 07 은 `_byte_swap_inode_out` 입니다.
  - 나머지 덩어리는 레지스터(R 45)·프레임(원본에만 `movel a1,a6@(0xfffc)`, `linkw #0xfffc`) 입니다.
  - 07 `ufs_inode.c:471`(`byte_swap_inode_in(dp, ip);`, plan 215)·`646`(`byte_swap_inode_out(ip, dp);`) 은 NeXTMach `ufs/ufs_inode.c:431` `ip->i_ic = dp->di_ic;`·`606/616` `dp->di_ic = ip->i_ic;`(구조체 대입) 을 바꾼 것입니다.
  - 128 B 구조체 대입은 GCC 가 `_bcopy` 호출로 내는 것으로 봅니다(미검증, 실행이 판정).

방법:
1. 07 덮어쓰기 두 파일(새 파일, NeXTMach 출처 고지 그대로)을 만듭니다.
   - `ufs_vnodeops.c`: 399·400 과 402·403 을 각각 `#ifndef m68k` … `#endif` 로 감쌉니다(끼운 줄 4 개, `plan 449 (m68k)`).
   - `ufs_inode.c`: 471 행 앞에 `#if m68k` + `ip->i_ic = dp->di_ic;` + `#else` 를, 뒤에 `#endif` 를 끼웁니다. 646 행도 같은 꼴로 `dp->di_ic = ip->i_ic;` 을 끼웁니다(NeXTMach 줄).
2. `MARKERS`·`EXCEPTS[449]`·`m5_m68k_pc.py` `FILES` 에 두 파일을 더하고, 두 객체를 컴파일합니다. 스테이징 차이 = 두 `.c`, x86 관문.
3. 미리 정한 기준:
   - 두 객체 OBJECT_MATCH, 원본에 없는 새 미정의 기호 0(바이트 교환 기호가 빠짐).
   - 아니면 구간 진단을 하고 두 시도 연속 줄지 않으면 멈춥니다.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-byteswap.diff`, `09_validation/reconstruction/m5-m68k-ufs-byteswap-20261010.json`.

### 449.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_iget`(0x4037588) 0x4037854–0x403786a: `lea a3@(0x62),a2; pea 0x80; movel a2,sp@-; …; movel d0,sp@-; bsr _bcopy` = `bcopy(dp, &ip->i_ic, 128)`; `_iupdat`(0x4037c0c) 0x4037d08 은 `bcopy(&ip->i_ic, dp, 128)` | 기호표 grep 세 기호, 원본 0x4037850–0x403786c 읽음 | ✅(`_iupdat` 쪽은 §431 덩어리와 검토자 인용) |
| `icommon` 128 B, `i_ic` +0x62 | 검토자 인용(SDK `inode.h:101-135`) + 원본 `pea 0x80` | ✅ |
| 128 B 구조체 대입이 `_bcopy` 로 나오는지는 컴파일러 원본으로 확인 불가 | — | ⏭️ 실행이 판정 |
| 07 642–658 행 = NeXTMach 601–617 행; 646 은 NeXTMach 606(`#if NeXT` 안), 657 은 `#else` 의 죽은 사본 → 되살릴 것은 606 하나 | 두 범위 나란히 읽음 | ✅ "606/616 짝" 은 **내 문구 오류** |
| 07 의 다른 x86 동기 줄(`architecture/byte_order.h` 가져오기, `NXSwapHostLongToBig` 2 줄 등)은 빅엔디언에서 항등이고 `_iupdat` 진단에 차이 없음 → 남기되 기록 | 07 652–654 행 읽음(`NXSwapHostLongToBig`) | ✅ MODIFICATIONS 에 "남김" 명시 |
| `ufs_vnodeops` 덩어리 4 개는 모두 `_rwip`, 크기 합 54 = 8150 − 8096 | §436.2 기록과 같음 | ✅ |
| 표시 줄은 모두 `plan 449 (m68k)` 를 달고, `begin`/`end` 묶음을 쓸 거면 `#else` 줄에서 닫아야 원래 줄이 묶음에 먹히지 않음; 등록 수 `ufs_vnodeops.c` 4·`ufs_inode.c` 8 | `check_derived` 규칙(§437–441) | ✅ 묶음 없이 줄마다 표시 |
| `EXCEPTS[449]`·`FILES` 등록 | — | ✅ |
| `ufs_dir.c` 에도 바이트 교환 호출 12 곳(다음 대상, 링크 전 필요) | 검토자 grep 인용 | ⏭️ 다음 항목 |

### 449.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-byteswap-20261010.json`

- 07 덮어쓰기(새 파일 둘, NeXTMach 고지 그대로)와 기록:
  - `v183.34/m68k/src/bsd/ufs/ufs_vnodeops.c` 는 표시 줄 4 개입니다(`#ifndef m68k`/`#endif` 두 쌍).
  - `ufs_inode.c` 는 표시 줄 8 개입니다(`#if m68k` 구조체 대입·`#else`·`#endif` 두 벌).
  - diff 는 `06_reconstruction/evidence/m68k-ufs-byteswap.diff` 입니다. PROVENANCE 1077 → 1079, MODIFICATIONS 602 → 604 입니다.
  - 남긴 x86 동기 줄(`NXSwapHostLongToBig` 등, 빅엔디언에서 항등)은 MODIFICATIONS 에 적었습니다.
- 도구: `MARKERS`(`plan 449`: 4·8)·`EXCEPTS[449]`(이전 둘 + 두 ufs 객체), `m5_m68k_pc.py` `FILES` 에 두 파일을 더했습니다. 실행 전후 해시가 같습니다.
- 스테이징 차이는 두 `.c` 이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p449-a1`, 2 명령 종료 0, 실기 otool SHA 대조): **`x86-ufs_vnodeops`·`x86-ufs_inode` 모두 OBJECT_MATCH** 이고, 원본에 없는 새 미정의 기호는 0 입니다.
  - 128 B 구조체 대입은 `_bcopy` 호출로 나왔습니다(§449 의 미검증 예측 확인).
  - `_iget` 의 레지스터·프레임 차이도 함께 풀렸습니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 154**.
- 다음 바이트 교환 후보: `ufs_vfsops`(바이트 교환 + `copyinmsg`·프레임, §439), `ufs_alloc`·`ufs_dir`(i386 도우미 함수 `_verify_and_swap_cg`·`_brelse_and_swap`).

## 450. M5-7 세부 계획 — m68k `ufs_vfsops`: i386 바이트 교환 7 문장 빼기와 `mountfs` 프레임 자리 메움 크기(x86 트리 변경 없음; 코딩 전, 2026-10-10)

확인한 사실:
- §439 a 쪽 관문 기록(`m2-m68k-boundaries-built-20261009.json` k=130)의 덩어리:
  - 바이트 교환 7 문장(07 `ufs_vfsops.c` 257–258·308·329·337·416·691·715, 모두 "plan 216")이고, 크기는 14·10·8·8·14·10·16 = 80 B 입니다(python).
  - `bwrite` 정렬 쌍(−8·+10)이 있습니다.
  - `mountfs` 프레임 차이(`linkw` 80 대 76, 지역 변위 +6 이동, python)가 있습니다.
  - 257 행 `fsp = tp->b_un.b_fs;` 도 원본 m68k 에 없습니다(덩어리 14 B = `movel a4@(0x20),a2` 4 B 포함).
- **§439 해석 정정**: `_copyin` 과 `_copyinmsg` 는 원본 m68k 에서 같은 주소(0x40016d0)의 별칭입니다(python: 두 이름 모두 호출 56 곳, 같은 함수 목록). §439 의 "`ufs_mount` 의 원본 `copyinmsg`" 는 진단 도구의 기호 이름 고르기에서 생긴 것이라 실제 차이가 아닙니다.
- 07 `mountfs` 의 `char unused[64];`(206–207 행)는 x86 원본 프레임(0x40 더 큼)에 맞춰 넣은 자리 메움입니다(계획 216.1, "이름·자리 추정"). m68k 원본은 이 크기가 다른 것으로 보입니다.

방법:
1. 변형 시험(한 run): 07 본 파일에서 바이트 교환 7 문장을 뺀 판에 `unused` 크기 64(바꾸지 않음)·62·60·58·56 을 시험합니다(새 도구 `10_tools/reconstruction/m5_m68k_vfsops.py`). 외부 구간 비교로 `mountfs` 를 담은 구간·`_ufs_mount`·`_sbupdate` 가 원본과 같은 크기를 고릅니다.
   - 같은 결과의 크기가 여럿이면 D072 처럼 사용자에게 묻습니다.
   - 하나도 없으면 진단 뒤 멈춥니다.
2. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_vfsops.c` 를 만듭니다(새 파일).
   - 바이트 교환 줄은 `#ifndef m68k`/`#endif` 로 감쌉니다.
   - `unused` 는 `#if m68k` + `char unused[N];` + `#else` 로 감싸 07 줄을 `#else` 에 남깁니다.
   - 표시는 `plan 450 (m68k)` 입니다.
3. 미리 정한 기준: `x86-ufs_vfsops` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-vfsops.diff`, `09_validation/reconstruction/m5-m68k-ufs-vfsops-20261010.json`.

### 450.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_copyin`·`_copyinmsg` 같은 주소 → §439 의 차이는 이름 산물 | 기호표 grep: 둘 다 0x40016d0 | ✅ |
| 바이트 교환 7 덩어리의 크기·줄이 계획과 같고 합 80; 257 행도 원본에 없음(REMOUNT 경로는 NeXTMach 245–247 행처럼 `bp = mp->m_bufp; goto modify_now;` 만) | §450 사실의 python 합과 같음; REMOUNT 판독은 검토자 인용 | ✅(판독은 실행으로 확인) |
| `unused` 는 207 행 하나(206 은 `{`) | 07 206–207 행 읽음 | ✅ 문구 정정 |
| 프레임은 4 의 배수로 올림(원본 `linkw` 828 개 모두 4 의 배수) → 크기 57·58 이 프레임 76·변위 +6 모두와 맞음; `devbsize` 는 레지스터라 무관 | python: `linkw` 828 개 중 4 의 배수 828 | ✅ |
| 크기로는 고를 수 없음(변위 길이가 같음) → **바이트 일치(OBJECT_MATCH)로 고를 것**; 시험에 57 을 더할 것 | 설계 | ✅ 후보 64·62·60·58·57·56 |
| 그 밖의 덩어리(D-frame +6·스택 조정 합치기·`bwrite` 자리·분기 `.w`/`.b` 4 B)는 제거·프레임의 부수 효과 | §439 덩어리 목록 | ⏭️ 실행이 판정 |
| 표시 줄 18(`#ifndef`/`#endif` 7 쌍 + `unused` 4 줄), `EXCEPTS[450]`·`--plan` 목록 | 설계 | ✅ |
| 한 크기로 두 아키텍처를 맞출 수 없음(x86 64, m68k 57/58) → `#if m68k` 분기 필요; 실제 지역 변수는 아키텍처마다 배치가 다른 것(구조체 등)일 수 있음(미검증) | — | ✅ 기록 |

고친 고르기 규칙(실행 전 고정): 객체 OBJECT_MATCH 인 크기가 하나면 그 크기를 씁니다. 여럿이고 그 객체들이 비 STABS 로 서로 같으면, D072 와 같은 경우로 보고 사용자에게 묻습니다.

### 450.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-vfsops-variants-20261010.json`(변형), `m5-m68k-ufs-vfsops-20261010.json`(최종)

변형 시험(도구 `10_tools/reconstruction/m5_m68k_vfsops.py`, run `m5p450-var1`, 6 명령 종료 0, 실행 전후 해시 같음):
- 바이트 교환 7 문장을 뺀 판에서 `unused` 크기 64·62·60·58·57·56 을 시험했습니다.
- **58·57 만 OBJECT_MATCH** 이고 두 객체는 서로 같습니다. 나머지는 불일치입니다.
- 미리 정한 규칙대로 사용자에게 물었고 결정은 **D073 = 58** 입니다.

07 덮어쓰기와 기록:
- `v183.34/m68k/src/bsd/ufs/ufs_vfsops.c`(새 파일)는 표시 줄 18 개입니다(`#ifndef m68k`/`#endif` 7 쌍, `#if m68k char unused[58]` / `#else` 07 줄 / `#endif`).
- diff 는 `06_reconstruction/evidence/m68k-ufs-vfsops.diff` 입니다. PROVENANCE 1079 → 1080, MODIFICATIONS 604 → 605 입니다.
- 도구: `MARKERS`(18)·`EXCEPTS[450]`·`FILES`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.

최종 run `m5p450-a1`:
- **`x86-ufs_vfsops` OBJECT_MATCH**(시험 변형 N=58 과 비 STABS 같음)이고, 원본에 없는 새 미정의 기호는 0 입니다.
- 외부 구간 비교에서 `_sbupdate` 만 "다름" 으로 나옵니다. 이는 객체의 마지막 외부 함수라 원본 쪽 구간이 다음 외부 기호(`ufs_vnodeops` 의 `_rdwri`, 0x403b6a2)까지 이어진 측정 산물입니다. 객체 쪽은 2798 B 에서 끝나고, 객체 L1 은 OBJECT_MATCH 입니다.
- §439 의 차 82 대 86 의 남은 4 B 는 분기 `.w`/`.b` 두 개였고(검토 의견), 이번에 함께 맞았습니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 155**.

## 451. M5-8 세부 계획 — m68k `ufs_dir`: 디렉터리 바이트 교환을 매크로로 지우고 NeXTMach `brelse()` 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-10)

확인한 사실:
- 07 `ufs_dir.c` 는 x86 원본에 맞춰 다음을 넣었습니다(계획 355·370).
  - 도우미 `brelse_and_swap(bp)`(78–91 행: `if (bp) { byte_swap_dir_block_out(bp); brelse(bp); }`)
  - 단독 문장 `byte_swap_dir_block_out(…)` 9 곳과 `byte_swap_dir_block_in(…)` 1 곳(1406 행)
  - NeXTMach `brelse(x)` 를 바꾼 `brelse_and_swap(x)` 8 곳
- NeXTMach `ufs/ufs_dir.c` 와 07 의 diff: `brelse_and_swap` 자리는 모두 NeXTMach 에서 그냥 `brelse(x)` 이고, 교환 문장은 NeXTMach 에 없습니다(diff grep).
- 교환 문장은 모두 조건이 없는 단독 문장입니다(10 곳 문맥 읽음; 1587 행은 `if (bp) { … }` 블록 안 첫 문장).
- §429: `x86-ufs_dir` 은 등급 A·i386 조각 OBJECT_MATCH 이고, m68k 에서는 외부 구간 0/5 가 같으며 원본에 없는 `_brelse_and_swap` 이 있습니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_dir.c`(새 파일)를 만듭니다.
   - 도우미 정의(주석 포함 78–91 행)를 `#ifndef m68k`/`#endif` 로 감쌉니다.
   - 그 뒤에 `#if m68k` 묶음으로 매크로 셋을 둡니다: `#define brelse_and_swap(bp) brelse(bp)`, `#define byte_swap_dir_block_out(bp)`, `#define byte_swap_dir_block_in(addr, n)`.
   - 전처리 뒤 함수 본문은 NeXTMach 문장과 같고(빈 문장 `;` 만 남음), 줄을 하나하나 고치지 않습니다. 표시는 `plan 451 (m68k)` 입니다.
2. 등록·스테이징·컴파일은 앞 절들과 같습니다(`MARKERS`·`EXCEPTS[451]`·`FILES`, 스테이징 차이 = 이 `.c`, x86 관문).
3. 미리 정한 기준:
   - 원본에 없는 새 미정의 기호 0(`_brelse_and_swap`·`_byte_swap_*` 사라짐).
   - `x86-ufs_dir` OBJECT_MATCH. 아니면 구간 진단을 하고, 다른 x86 동기 수정(계획 355·370 의 비 교환 줄)이 원인인지 가립니다(두 시도 연속 줄지 않으면 멈춤).
4. `ufs_alloc` 은 교환 외에도 x86 동기 수정이 많아(계획 214: `getthetime`·`VOP_DEVBLOCKSIZE`·`NXSwapBigLongToHost`·레지스터 변형) 다음 절에서 따로 다룹니다.
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-dir.diff`, `09_validation/reconstruction/m5-m68k-ufs-dir-20261010.json`.

### 451.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `brelse_and_swap` 호출 8 곳(169·270·491·544·633·857·1367·1607)은 NeXTMach 에서 모두 `brelse(x)`; 매크로로 `brelse(` 가 NeXTMach 의 12 개가 됨; 원본 m68k 객체의 `_brelse` 호출도 12 | python: 호출 줄 목록, NeXTMach `brelse(` 12, 원본 [0x40354be, 0x4036d3e) 에서 `bsr 0x4017aec` 12 | ✅ |
| `_out` 는 도우미 밖 8 곳(+ 도우미 안 88 행), `_in` 1 곳(1406) — 계획의 "9 곳" 은 88 행 포함 | python 목록 | ✅ 문구 정정 |
| 비 교환 차이(`#ifdef QUOTA`→`#if QUOTA`, `dirrename` 의 `EISDIR`, `dircheckforname` 분기 반전, 초기화 두 줄)는 m68k 바이트와도 맞음(원본 주소 인용) | 검토자 판독(일부 미검증) | ⏭️ 실행이 판정 |
| 매크로는 91 행 뒤에 둬야 함(앞 프로토타입 `void byte_swap_dir_block_in();` 가 펼쳐지지 않게); 빈 문장 `;` 은 모든 자리에서 무해 | 75–76·78–91 행 위치(§451 사실), 자리 문맥 읽음 | ✅ |
| 표시 줄 7(`#ifndef`·`#endif`·`#if`·`#define` 3·`#endif`); `EXCEPTS[451]` 는 450 의 다섯 + `x86-ufs_dir` | 설계 | ✅ |
| 계획 1489 행 근처의 "바이트 교환 호출 12 곳" 은 낡은 문구 | §449.1 표 마지막 줄(검토 인용) | ✅ 기록(덮어쓰지 않음) |

### 451.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-dir-20261010.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_dir.c`(새 파일)는 표시 줄 7 개입니다.
  - 도우미 정의를 `#ifndef m68k` 로 뺐습니다.
  - 91 행 뒤 `#if m68k` 에 매크로 셋을 두었습니다.
  - diff 는 `06_reconstruction/evidence/m68k-ufs-dir.diff` 입니다. PROVENANCE 1080 → 1081, MODIFICATIONS 605 → 606 입니다.
- 도구:
  - `MARKERS`(7)·`EXCEPTS[451]`·`FILES` 를 더했습니다.
  - `m5_m68k_pc.py cmd2` 가 §429 run(`m3p429-cc2`)의 컴파일 줄도 찾도록 고쳤습니다(`ufs_dir` 은 88 쪽). 고른 줄이 `-c` 컴파일 줄인지 확인했습니다.
  - 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p451-a1`): **`x86-ufs_dir` OBJECT_MATCH** 이고, 원본에 없는 새 미정의 기호는 0 입니다(`_brelse_and_swap`·`_byte_swap_*` 사라짐).
  - 비 교환 차이(`#if QUOTA`·`EISDIR`·분기 반전·초기화)는 m68k 에도 맞았습니다.
  - 외부 구간 비교의 `_blkatoff` "다름" 은 마지막 외부 함수라 원본 구간이 다음 객체까지 이어진 측정 산물입니다. 객체 끝 6272 B = 원본 0x4036d3e, 원본 쪽 구간은 0x4037142 까지입니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 156**.

## 452. M5-9 세부 계획 — m68k `ufs_alloc`: 실린더 그룹 바이트 교환과 `blkpref` 의 큰 끝 읽기를 빼고 NeXTMach 검사 꼴 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-10)

확인한 사실:
- 원본 m68k 기호표에 `verify_and_swap`·`byte_swap` 이 든 이름이 없습니다(grep 0).
- 07 `ufs_alloc.c`(1414 행)와 NeXTMach `mk-108.1/ufs/ufs_alloc.c` 의 차이(계획 214·214.1·397)는 다음과 같습니다.
  - 바이트 교환 관련: 도우미 `verify_and_swap_cg`(121–142 행), 그 호출 다섯 곳(817·878·1118·1206·1303 행; 878·1118 은 뒤따르는 `nbfree`/`nifree` 검사 블록과 함께), 단독 `byte_swap_cylgroup(…)` 문장들, `blkpref` 의 `prevblk`·`NXSwapBigLongToHost`(666·669–676·685·688·709–716 행).
  - 바이트 교환과 무관: `getthetime(&tv)`, `btodb(…, VOP_DEVBLOCKSIZE(ITOV(ip)))` 세 곳, `fsfull` 의 `register` 와 `cmesg = umesg = 0`, `free_block` printf 의 `bno`(214.1), `ufs_alloc_const_4`(397), `#import <architecture/byte_order.h>`.
- 원본 m68k 함수 판독(이미지 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, python):
  - `_fragextend`·`_alloccg`·`_ialloccg`·`_free_block`·`_ifree` 는 각각 `btst #2,aN@(0x3)`(B_ERROR 0x4) 1 개와 `cmpl #0x90255,aM@(0x3d4)`(CG_MAGIC) 1 개, `_getthetime`(0x400a360) 호출 1 개를 가집니다. 검사 직후 실패하면 바로 `_brelse` 로 가므로 NeXTMach 의 합친 조건 꼴과 맞습니다.
  - `_blkpref` 는 호출이 없고 `bap[indx - 1]` 을 `movel a2@(-4,d3:l:4),d0` 로 두 번(0x4033df4·0x4033e14) 직접 읽습니다. `bap && indx > 0` 검사는 없습니다 → NeXTMach 꼴입니다.
  - `_fsfull` 의 패닉 앞 `clrl d3; clrl d2`(0x403376e) → `cmesg = umesg = 0` 은 m68k 에도 있습니다.
  - `_free_block` 의 "freeing free block" printf 는 `d5`(dtogd 뒤 `bno`)를 넣습니다(0x40349ba) → 214.1 의 `bno` 와 맞습니다.
  - `_alloc` 1 곳, `_realloccg` 2 곳의 `a0@` 간접 호출은 `VOP_DEVBLOCKSIZE` 로 보입니다(실행이 판정).
- 이 객체의 컴파일 줄은 §429 run(`m3p429-cc2/run.cmd`)에 있고, 같은 파일의 `-M` 의존성 줄(144 행)도 있습니다. `m5_m68k_pc.py cmd2` 는 지금 두 줄 다 고르게 되어 있어 `-c` 줄만 고르도록 고쳐야 합니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_alloc.c`(새 파일, 표시 `plan 452 (m68k)`)를 만듭니다. 07 본 파일에 표시 줄만 끼워 넣습니다(64 줄).
   - 도우미 121–142 행과 `prevblk` 선언(666 행)은 `#ifndef m68k`/`#endif` 로 감쌉니다.
   - 142 행 뒤에 `#if m68k` `#define byte_swap_cylgroup(cgp)`(빈 매크로) `#endif` 를 둡니다. 단독 교환 문장은 빈 문장이 됩니다.
   - `blkpref` 네 자리(669–676·685·688·709–716)와 호출 다섯 자리(817–818·878–884·1118–1124·1206–1207·1303–1304)는 `#if m68k` + NeXTMach 줄 + `#else` + 07 줄 + `#endif` 로 둡니다. 넣는 줄은 NeXTMach 634·643·646·667–671·771–774·830–834·1061–1065·1144–1147·1240–1243 행과 같은 글입니다(`time.tv_sec` 줄은 넣지 않음; `getthetime` 은 07 줄 유지).
   - 바이트 교환과 무관한 차이는 07 그대로 둡니다(원본 판독과 맞음).
2. 도구:
   - `stage_m68k.py`: `MARKERS['plan 452 (m68k)'] = {'src/bsd/ufs/ufs_alloc.c': 64}`, `EXCEPTS[452]` = 451 의 여섯 + `x86-ufs_alloc`, `--plan` 목록에 452.
   - `m5_m68k_pc.py`: `FILES['ufs_alloc']`, `cmd2` 는 `-c` 가 있는 줄만 고릅니다(§451 까지의 결과는 바뀌지 않음: 고른 줄이 같음을 확인).
3. 스테이징 `--plan 452`, x86 관문, 스테이징 차이 = 이 `.c` 하나, `cmd2 452 ufs_alloc`, kr_run, otool, `final`.
4. 미리 정한 기준:
   - 원본에 없는 새 미정의 기호 0(`_verify_and_swap_cg`·`_byte_swap_cylgroup`·`_NXSwap*` 없음).
   - `x86-ufs_alloc` OBJECT_MATCH. 아니면 구간 진단(`diag`)으로 원인을 가리고, 두 시도 연속 줄지 않으면 멈춥니다.
   - `ufs_alloc_const_4`(`__TEXT,__const` 4 B)가 m68k 원본과 맞지 않아 불일치가 나면, 이를 따로 보고하고 바꾸지 않습니다(근거 없는 제거 금지).
5. 기록: PROVENANCE·MODIFICATIONS 덧붙임, diff `06_reconstruction/evidence/m68k-ufs-alloc.diff`, `09_validation/reconstruction/m5-m68k-ufs-alloc-20261010.json`.

### 452.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **`cmd2` 의 `-M` 줄 문제는 없음**: 조건 `' src/src/%s '` 는 파일명 뒤 공백이 필요하고, `-M` 줄(run.cmd 144 행)은 파일명 뒤가 줄바꿈이라 걸리지 않음 | python: 9 개 파일 모두 고른 줄이 하나이고(`ufs_alloc` 은 296 번째 줄 = run.cmd 56 행), `' -c '` 를 더 걸어도 같음 | ✅ **제 오류 정정** — 도구는 고치지 않고 `FILES['ufs_alloc']` 만 더함 |
| 바이트 교환 관련 차이를 모두 다루고, 빈 문장이 되는 교환 10 곳은 모두 중괄호 안 또는 `bdwrite` 앞이라 흐름이 NeXTMach 와 같음 | 07 824·847·889·908·922·928·941·1169·1267·1325 행 문맥(§452 준비 중 읽음)과 넣은 30 줄 = NeXTMach 줄(python 일치) | ✅ |
| m68k 쪽 전처리 결과는 NeXTMach 와 유지한 차이(getthetime·btodb·fsfull·bno·const·import)만 다르며, 빈 줄 하나가 늘어남(120·143 행) | python: 07 120·143 행 모두 빈 줄 | ✅ (`__text` 무관) |
| 원본 판독(검사·getthetime 각 1, blkpref 직접 읽기, fsfull `clrl`, printf `d5`) 맞음; `_realloccg` 에도 `btst #2` 2 개(0x4033a30·0x4033b6e)가 있으나 `bread` 오류 검사 | python grep | ✅ |
| 표시 줄 64, 두 표시가 한 줄에 없음 | 생성기 출력 `marked 64`, 스테이징 검사가 다시 판정 | ✅ |
| `#define byte_swap_cylgroup` 자리 안전(헤더에 선언 없음) | §452 준비 중 `grep -rn byte_swap_cylgroup 07_kernel/src --include=*.h` 0 건 | ✅ |
| 기존 §429 객체에서 외부 구간 11 개가 이미 같고, 다른 것은 손대는 6 함수뿐이며 `_verify_and_swap_cg` 는 원본에 없음; 간접 호출 `a0@` 는 `VOP_DEVBLOCKSIZE` | python `compare_object`: 같음 11(`_alloc` … `_realloccg`), 다름 6(`_alloccg`·`_blkpref`·`_fragextend`·`_free_block`·`_ialloccg`·`_ifree`), 없음 1 | ✅ (간접 호출 판독은 같은 구간 일치로 갈음) |
| `ufs_alloc_const_4` 의 m68k 일치 여부는 미확인 | — | ⏭️ 실행이 판정(§452 기준 4 그대로) |

### 452.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-alloc-20261010.json`(최종), `m5-m68k-ufs-alloc-const-20261010.json`(상수 배치)

- 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_alloc.c`(새 파일, 1478 행)는 표시 줄 64 개입니다.
  - diff 는 `06_reconstruction/evidence/m68k-ufs-alloc.diff` 입니다. PROVENANCE 1081 → 1082, MODIFICATIONS 606 → 607 입니다.
- 도구: `stage_m68k.py` 의 `MARKERS`(64)·`EXCEPTS[452]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['ufs_alloc']` 만 더했습니다(`cmd2` 는 고치지 않음, §452.1). 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p452-a1`, 1 명령):
  - `__TEXT,__text` 바이트 차이 0, 참조 167 개 모두 같음, 외부 구간 17/17 같음, 원본에 없는 새 미정의 기호 0 입니다.
  - 기본 L1(`--place-from-image`) 판정은 **NOT_MATCH, 이유는 `__TEXT,__const: unverified` 하나**입니다. 기호가 없는 static 상수 `ufs_alloc_const_4`(4 B)는 이미지에서 자리를 찾지 못합니다(x86 에서도 같은 원인이었고, 계획 397·398 에서 명시 배치로 확인했습니다).
- 상수 배치 확인(소스 변경 없음, 측정만):
  - 원본 m68k `__TEXT,__const`(0x40ace76, 2796 B)에서 `"swapfs\0"`(0x40acfdb–0x40acfe1) 바로 뒤 0x40acfe2 에 큰 끝 정수 4(`00 00 00 04`, 2 B 정렬)가 있고, 바로 뒤가 `_kern_serv_proto`(0x40acfe6)입니다. x86 의 순서(swapfs 0x1d1276 → ufs_alloc 0x1d1280 → kern_server)와 같습니다.
  - `--place __TEXT,__const=0x40acfe2` 에서 **OBJECT_MATCH**(상수 바이트 차이 0)입니다. 대조 자리 0x40acfe6·0x40acfde 는 불일치(차이 1·4)입니다.
- 판정: 미리 정한 기준 1(새 미정의 기호 0)은 충족합니다. 기준 2 는 기본 L1 로는 NOT_MATCH(상수 미배치만)이고, x86 선례와 같은 명시 배치로는 OBJECT_MATCH 입니다. 기준 4 의 "상수가 맞지 않으면" 경우는 일어나지 않았습니다(상수는 원본과 같음).
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 156 이고, 명시 배치 하나(`ufs_alloc` 0x40acfe2)를 넣으면 157 입니다.

## 453. M5-10 세부 계획 — m68k `kern_shutdown`: `boot()` 의 `us_spin` 을 SDK `DELAY` 로(x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- §441 객체 `O441__L2_168__kern_shutdown.o`(run `m3p441-cc1`)의 L1 은 NOT_MATCH 이고, 사유는 `__TEXT,__text` 참조 1 개 미검증뿐입니다. 외부 구간 5 개(`_boot`·`_unmount_all`·`_kill_tasks`·`_proc_shutdown`·`_fd_shutdown`)는 모두 같습니다(python `compare_object`). 미검증 참조는 원본 m68k 에 없는 `_us_spin` 입니다(§436 기록).
- 07 `bsd/kern/kern_shutdown.c` 106 행은 `us_spin(40000 * iter);` 입니다(계획 229 에서 x86 원본에 맞춰 작성).
- 원본 m68k `_boot`(0x400843e) 는 같은 자리에서 `mulsl #0x9c40,d6`(40000) 뒤 `bsr 0x409237a`(`_delay`, 기호표) 를 부릅니다(0x4008502–0x400850c).
- 참고 코드의 같은 루프는 `DELAY(40000 * iter);` 입니다: NeXTMach `mk-108.1/next/machdep.c:1268`, Darwin 0.1 `kernel/bsd/kern/kern_shutdown.c:128`.
- 실기 SDK 머리 `bsd/m68k/machparam.h:51–52` 는 `KERNEL`·`STANDALONE` 일 때 `#define DELAY(n) delay(n)` 이고, `bsd/i386/machparam.h:50–51` 은 `#define DELAY(n) us_spin(n)` 입니다. 컴파일 줄에 `-DKERNEL` 이 있습니다. `sys/param.h:48` 이 `<machine/machparam.h>` 를 가져옵니다.
  - 즉 원래 소스가 `DELAY(40000 * iter)` 였다면 i386 에서는 `us_spin`, m68k 에서는 `delay` 가 되어 두 원본 모두와 맞습니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_shutdown.c`(새 파일, 표시 `plan 453 (m68k)`)를 만듭니다. 106 행을 `#if m68k` / `DELAY(40000 * iter);` / `#else` / 07 줄 / `#endif` 로 감쌉니다(표시 줄 4).
   - `delay(40000 * iter);` 를 직접 써도 전처리 뒤 같은 글이 됩니다. 참고 코드 두 곳과 SDK 매크로가 `DELAY` 이므로 `DELAY` 꼴을 씁니다.
   - x86 07 줄(`us_spin`)은 바꾸지 않습니다(x86 트리 변경 없음, D064).
2. 도구: `stage_m68k.py` 의 `MARKERS['plan 453 (m68k)'] = {'src/bsd/kern/kern_shutdown.c': 4}`, `EXCEPTS[453]` = 452 의 일곱 + `x86-kern_shutdown`, `--plan` 목록; `m5_m68k_pc.py` 의 `FILES['kern_shutdown']`.
3. 스테이징 `--plan 453`, x86 관문, 스테이징 차이 = 이 `.c` 하나, `cmd2 453 kern_shutdown`(§430 `cc.cmd` 의 `-c` 줄 1 개), kr_run, otool, `final`.
4. 미리 정한 기준: `x86-kern_shutdown` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0(`_us_spin` 사라짐). 아니면 진단 뒤 멈춥니다.
5. 기록: PROVENANCE·MODIFICATIONS 덧붙임, diff `06_reconstruction/evidence/m68k-kern-shutdown.diff`, `09_validation/reconstruction/m5-m68k-kern-shutdown-20261015.json`.

### 453.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 07 106 행 = `us_spin(40000 * iter);` | `sed -n 106p … \| cat -A` | ✅ |
| 원본 `_boot` 0x4008500–0x400850c: `d3`(iter) → `d6`, `mulsl #0x9c40`, 넣고 `bsr 0x409237a` = `_delay`; 0x9c40 = 40000 | 이미지 목록 `_boot` 전체 읽음, 기호표 `_delay 0x409237a`, python `0x9c40` = 40000 | ✅ |
| NeXTMach `next/machdep.c:1268`·Darwin `kern_shutdown.c:128` 이 `DELAY(40000 * iter);`; NeXTMach 는 둘레 루프(`obusy`)까지 같고 Darwin 은 `B_INVAL` 검사·`obusy` 없음 | 두 파일 해당 줄 읽음(NeXTMach 1250–1270, Darwin 112–130) | ✅ (계획의 근거는 NeXTMach 줄로 둠) |
| SDK `bsd/m68k/machparam.h` `DELAY(n) delay(n)`(조건 `KERNEL`·`STANDALONE`), i386 은 `us_spin(n)`; `machine/machparam.h` 는 `ARCH_INCLUDE(bsd/, machparam.h)` 로 대상 아키텍처를 고름 | 스테이징 두 머리 44–58 행, `bsd/machine/machparam.h:9–11`, `components/architecture/ARCH_INCLUDE.h:25–30` 읽음 | ✅ |
| `sys/param.h` 를 37 행에서 가져오므로 106 행에서 `DELAY` 가 정의됨 | 07 37 행 읽음 | ✅ |
| `delay` 원형(`kernserv/m68k/us_timer.h`)은 이 번역 단위에 보이지 않음(`kernserv/prototypes.h:31` 경로로만 들어옴); 보여도 부호 있는 곱셈 뒤 변환이라 코드 같음 | `prototypes.h:31` 확인; 보이는지는 직접 확인하지 않음 | ⏭️ 컴파일이 판정 |
| 기존 객체의 L1 문제는 `_us_spin` 미검증 참조 하나 | python: 미정의 기호 목록에 `_us_spin` 있음, 앞서 `run_l1` = NOT_MATCH(`__text` 참조 1 미검증), 외부 구간 5/5 같음 | ✅ |
| 그 밖의 `_boot` 차이 없음(`md_*`·`vn_rele`·`sync`·`unmount_all`·`if_down_all`) | 외부 구간 `_boot` 같음(python) | ✅ |
| 표시 줄 4 로 `check_derived` 통과 | 후보 생성 출력 `339 4 True`; 스테이징이 다시 판정 | ✅ |

### 453.2 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-kern-shutdown-20261015.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_shutdown.c`(새 파일, 339 행)는 표시 줄 4 개입니다.
  - diff 는 `06_reconstruction/evidence/m68k-kern-shutdown.diff` 입니다. PROVENANCE 1082 → 1083, MODIFICATIONS 607 → 608 입니다.
- 도구: `stage_m68k.py` 의 `MARKERS`(4)·`EXCEPTS[453]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['kern_shutdown']`. 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p453-a1`, 1 명령, 종료 0): **`x86-kern_shutdown` OBJECT_MATCH** 이고, 외부 구간 5/5 같음, 원본에 없는 새 미정의 기호 0 입니다(`_us_spin` 사라지고 `_delay` 참조).
  - 컴파일 경고 하나(`proc_shutdown` 의 `thread_wakeup_prim` 인자)는 §441 run 에도 있던 것입니다(07 313 행 → 덮어쓰기 317 행).
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 157 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 158 입니다.

## 454. M5-11 세부 계획 — m68k `init_main`: Objective-C·`kmEnableAnimation`·`autoconf`·`setconf` 빼기, `ns_timer_init`·`softint_th` 스레드 넣기(x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- §441 객체 `O441__L2_171__init_main.o`(run `m3p441-cc1`):
  - L1 은 NOT_MATCH(`__TEXT,__text` 미검증)입니다.
  - 외부 구간 7 개 중 `_main`(객체 1146 B, 원본 1136 B)과 `_cinit`(84 대 74)만 다릅니다.
  - 원본에 없는 미정의 기호는 `__objcInit`·`_objc_setClassHandler`·`_kmEnableAnimation`·`_autoconf` 넷입니다(python).
- 원본 m68k `_main`(0x4002958) 호출 순서(이미지 목록, 기호 이름으로 바꿔 읽음)와 07 `main()` 의 차이는 다음과 같습니다.
  - `_kmem_suballoc` 뒤, `_ns_hardclock_init` 앞에 `bsr _ns_timer_init`(0x4002b52)이 있습니다. 07 에는 없습니다.
  - `kernel_thread(…, netisr_thread, 0)` 바로 뒤가 `bsr _loattach`(0x4002cba)입니다. 07 의 `_objcInit(); objc_setClassHandler(classHandler); kmEnableAnimation(); autoconf(); setconf();`(382–386 행) 가 원본에 없습니다. 기호표에 `_autoconf`·`_kmEnableAnimation`·`__objcInit` 은 없고, `_setconf`(0x4099184)는 있으나 `_main` 에서 부르지 않습니다.
  - `vfs_mountroot` 와 `u.u_rpause` 쓰기(0x4002cd6) 뒤에 `kernel_thread(kernel_task, softint_th, 0)`(3 인자: `clrl sp@-`·`pea _softint_th`·`movel _kernel_task,sp@-`; `jsr a2@`)를 부르고 결과를 `_softint_thread` 에 넣습니다(0x4002cdc–0x4002cec). 그 뒤 `_file_init` 입니다.
- 참고 코드 NeXTMach `mk-108.1/bsd/init_main.c` 에 같은 꼴이 있습니다.
  - 257–258 행: `extern thread_t softint_thread;`, `extern void softint_th(void);`(`#if NeXT`)
  - 413 행: `u.u_rpause` 뒤에 `softint_thread = kernel_thread(kernel_task, (int(*)())softint_th);`(인자 2 개)
  - 07 의 `kernel_thread` 호출은 모두 셋째 인자 `0` 을 줍니다(377–380 행), 원본 m68k 도 셋째 인자 0 을 넣습니다.
- 원본 `_cinit`(0x4002fa2)는 74 B(0x4002fec 까지)이고, 바로 다음이 `_sysacct`(다음 객체)입니다. 객체의 `_cinit` 구간 84 B 는 static `classHandler`(10 B) 를 포함합니다(python 84 − 74 = 10). m68k 원본에는 `classHandler` 가 없습니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/init_main.c`(새 파일, 표시 `plan 454 (m68k)`, 표시 줄 16)를 만듭니다. 07 본 파일에 표시 줄만 끼워 넣습니다.
   - 251 행 `static int classHandler();` 를 `#ifndef m68k` 로 감싸고, 그 뒤 `#if m68k` 에 NeXTMach 257–258 행의 두 `extern` 을 둡니다.
   - 329 행 `ns_hardclock_init();` 앞에 `#if m68k` `ns_timer_init();` 를 둡니다(참고 코드 없음, 원본 바이트로 작성, D024).
   - 382–386 행을 `#ifndef m68k` 로 감쌉니다.
   - 398 행(`u.u_rpause = …`) 뒤에 `#if m68k` `softint_thread = kernel_thread(kernel_task, (int(*)())softint_th, 0);` 를 둡니다(NeXTMach 413 행에 이 파일의 셋째 인자 `0` 을 더함).
   - `classHandler` 정의(주석 포함 539–547 행)를 `#ifndef m68k` 로 감쌉니다.
2. 도구: `stage_m68k.py` 의 `MARKERS['plan 454 (m68k)'] = {'src/bsd/kern/init_main.c': 16}`, `EXCEPTS[454]` = 453 의 여덟 + `x86-init_main`, `--plan` 목록; `m5_m68k_pc.py` 의 `FILES['init_main']`.
3. 스테이징 `--plan 454`, x86 관문, 스테이징 차이 = 이 `.c` 하나, `cmd2 454 init_main`(§430 `cc.cmd` 의 `-c` 줄 1 개), kr_run, otool, `final`.
4. 미리 정한 기준: `x86-init_main` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0. 아니면 `diag` 로 `_main` 구간을 진단하고, 두 시도 연속 줄지 않으면 멈춥니다.
5. 기록: PROVENANCE·MODIFICATIONS 덧붙임, diff `06_reconstruction/evidence/m68k-init-main.diff`, `09_validation/reconstruction/m5-m68k-init-main-20261015.json`.

### 454.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_main` 호출 순서와 07 의 차이는 계획의 넷(`ns_timer_init` 추가, ObjC·애니메이션·`autoconf`·`setconf` 제거, `softint_th` 스레드 추가, `classHandler` 제거)뿐이고, 저장·루프 범위(rlimit 0–5, 해시 0–63, 그룹 1–15)는 같음 | 이미지 목록 `_main` 전체를 기호 이름으로 바꿔 읽음(§454 준비), 07 239–434 행 대조 | ✅ |
| 그 밖의 명령 차이는 스택 정리 위치(원본 0x4002cf2 `addaw #0x24`, 0x4002d12 `pea 1`, 0x4002d5c/60)뿐이며, 인자 수가 바뀐 데 따른 결과로 보임 | 원본 해당 주소 읽음; 객체 쪽은 검토자 인용 | ⏭️ 컴파일이 판정 |
| `ns_timer_init` 암묵 선언·`(int(*)())softint_th` 형변환·셋째 인자 0 은 원본 0x4002cdc–0x4002cec 와 맞음; `kernel_thread()` 는 원형 없음(`kern/thread.h:311`) | 원본 명령 읽음, `07_kernel/src/kern/thread.h:311` grep | ✅ (경고·바이트는 컴파일이 판정) |
| `_cinit` 74 B·`classHandler` 10 B·미정의 넷·`_setconf` 0x4099184·`_ns_timer_init`·`_softint_th`·`_softint_thread` 존재 | §454 준비 중 python 출력과 기호표 grep | ✅ |
| NeXTMach 257·258·413 행 글 | §454 준비 중 읽음 | ✅ |
| `main()` 은 434 행에서 끝남(계획의 "239–437" 이 아니라) | `sed -n 432,437p` | ✅ 정정(계획 본문은 범위를 쓰지 않았고, 검토 요청문의 오기) |
| `__data` 32 B·`__cstring` 17 B 는 원본과 같음 | 기존 객체 L1: `__data` 바이트 차이 0, `__cstring` 은 내용 대조 | ✅ |
| 표시 줄 16, `check_derived` 통과 | 생성기 출력 `563 16 True`, 스테이징이 다시 판정 | ✅ |
| `stage_m68k.py` 의 새 미정의 검사는 기준 객체의 미정의를 빼므로 기존 넷이 사라졌는지 증명하지 못함 → 전체 미정의 − 원본 기호로 확인할 것 | `stage_m68k.py:271–273`(기준 빼기) 확인; 그러나 이 절의 판정 도구 `m5_m68k_pc.py:194` 는 전체 미정의 − 원본 기호로 계산 | ⚖️ 사실이나 이 절의 기준은 이미 전체 기준; `_classHandler` 부재도 함께 확인함 |

### 454.2 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-init-main-20261015.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/init_main.c`(새 파일, 563 행)는 표시 줄 16 개입니다.
  - diff 는 `06_reconstruction/evidence/m68k-init-main.diff` 입니다. PROVENANCE 1083 → 1084, MODIFICATIONS 608 → 609 입니다.
- 도구: `stage_m68k.py` 의 `MARKERS`(16)·`EXCEPTS[454]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['init_main']`. 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p454-a1`, 1 명령, 종료 0, 경고 없음): **`x86-init_main` OBJECT_MATCH** 입니다.
  - 외부 구간 7/7 같음, 원본에 없는 미정의 기호 0(전체 미정의 − 원본 기호; ObjC·`_kmEnableAnimation`·`_autoconf` 사라짐), `classHandler` 기호 없음, `_ns_timer_init`·`_softint_th`·`_softint_thread` 참조가 있습니다.
  - 검토가 짚은 스택 정리 차이도 함께 사라졌습니다(OBJECT_MATCH).
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 158 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 159 입니다.

## 455. M5-12 세부 계획 — m68k `kern_clock`: `hardclock` 의 `SIMPLE_CLOCK` 블록(`clock_value`·`last_hardclock`·64 비트 나눗셈, `tick` → `myticks`)(x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- §441 객체 `O441__L2_172__kern_clock.o`(run `m3p441-cc1`):
  - L1 은 NOT_MATCH(`__TEXT,__text` 미검증)입니다.
  - 외부 구간 8 개 중 `_hardclock` 만 다릅니다(객체 356 B, 원본 418 B, 차 62).
  - 원본에 없는 미정의 기호는 없습니다.
- 원본 m68k `_hardclock`(0x40033d2, `linkw a6,#-28`)의 첫머리(0x40033e4–0x400342a)는 다음 순서입니다.
  1. `clock_value(1)` 를 부릅니다. 1 은 `System` 입니다(07 `kern/clock.h:77–80` 의 열거 `Calendar, System`).
  2. 결과 `d0:d1` 에서 `_last_hardclock` 를 64 비트로 뺍니다(`subl`·`subxl`). 차는 프레임 `a6@(-12)`·`a6@(-8)` 에 둡니다.
  3. `clrl d2; divull #0x3e8,d2:d5`(상위 워드, 몫을 `a6@(-12)` 에 되씀) 뒤 `divul #0x3e8,d2:d3`(하위 워드, 몫 `d3`)을 합니다. 0x3e8 = 1000 입니다.
  4. `_last_hardclock` 에 `d0:d1` 을 씁니다.
  - 뒤의 두 `_itimerdecr` 호출(0x4003480·0x400352e)은 07 의 `tick` 자리에 `d3` 을 넘깁니다.
  - 나머지(`USERMODE`·`ast_on`·rlimit·`psignal`·`gatherstats`)는 07 과 같은 꼴입니다(§441 의 비교에서 차이는 이 블록 둘레).
- `_last_hardclock` 은 원본 `__common`(0x40b605c, 8 B 자리)에 있고, 이를 참조하는 함수는 `_hardclock` 하나입니다(이미지 목록 python 검색). 정의 파일은 객체 바이트로 정해지지 않습니다.
- 참고 코드:
  - NeXTMach `mk-108.1/bsd/kern_clock.c:169–210·380–382`: `#if SIMPLE_CLOCK || NeXT` 안에서 `#define tick myticks`, `register int myticks;`, `myticks = usec_elapsed(&hardclock_usec_mark);`, 함수 뒤 `#undef tick`. 
  - Darwin 0.1 `kernel/bsd/kern/kern_clock.c:129–171`: `#if SIMPLE_CLOCK` 안에 `tvalspec_t last_hardclock[NCPUS];`(파일 전역), `new_hardclock = clock_get_counter(System); … myticks = …; last_hardclock[cpu_number()] = new_hardclock;`.
  - 원본 m68k 는 둘 중 Darwin 쪽 구조(전역 `last_hardclock`, `System` 시계, 새 값 저장)에 `ns_time_t` 와 1000 나눗셈을 쓴 꼴로 보입니다. 참고 원문을 그대로 옮기지 않고 원본 바이트로 작성합니다(D024).
- 07 `kern_clock.c` 는 `<simple_clock.h>`(61 행)를 가져오고, m68k 생성 구성은 `SIMPLE_CLOCK 1`, x86 은 0 입니다.
- 나눗셈 꼴은 07 `kern/ns_timer.c` 의 `ns_div_val` 과 같은 모양입니다. m68k 판(§448 의 `divull`/`divul`, 콜론 꼴)은 `m5_m68k_ns.py` 의 `m68k_funcs`·`reorder`(입력 순서 A·B·C·D)에 있습니다. §448 에서는 `ns_timer.c` 안에서 둘째 나눗셈의 레지스터 배정이 맞지 않았으므로, 여기서도 순서 변형을 함께 시험합니다.
- `clock_value` 의 원형은 07 머리에 없고, 07 `ns_timer.c:19`·`generalFuncs.c:99` 는 `extern ns_time_t clock_value();` 를 파일 안에 둡니다. `ns_time_t` 는 `<kernserv/clock_timer.h>` 에 있습니다.

방법:
1. **변형 시험**(새 도구 `10_tools/reconstruction/m5_m68k_clock.py`, 07 변경 없음): 07 본 파일에 아래 블록을 넣은 판을 입력 순서 A·B·C·D 네 가지로 컴파일합니다.
   - 99 행(`#import <mach/boolean.h>`) 뒤, `#if SIMPLE_CLOCK` 안:
     - `#import <kernserv/clock_timer.h>`
     - `extern ns_time_t clock_value();`
     - `ns_time_t last_hardclock;`
     - m68k `static inline unsigned int ns_div_val(ll, divisor)`(`m5_m68k_ns.m68k_funcs(':')` 의 글, 순서만 다름)
   - `hardclock` 의 `register thread_t thread;` 뒤 `#if SIMPLE_CLOCK`: `ns_time_t new_hardclock;`, `unsigned int myticks;`, `#define tick myticks`.
   - `thread = current_thread();` 뒤 `#if SIMPLE_CLOCK`: `new_hardclock = clock_value(System);`, `myticks = ns_div_val(new_hardclock - last_hardclock, 1000);`, `last_hardclock = new_hardclock;`.
   - `hardclock` 의 닫는 괄호(169 행) 뒤 `#if SIMPLE_CLOCK` `#undef tick`.
   - 판정: L1·외부 구간·원본에 없는 미정의 기호, 변형끼리 비 STABS 같음 묶음. 프레임(`linkw` −28)과 나눗셈 레지스터(`d2:d5`, `d2:d3`)를 봅니다.
2. 고르기 규칙(실행 전 고정):
   - OBJECT_MATCH 인 변형이 하나면 그 꼴을 씁니다.
   - 여럿이고 서로 같으면 D072·D073 처럼 사용자에게 묻습니다.
   - 하나도 없으면 `diag` 로 진단하고, 두 시도 연속 줄지 않으면 멈춥니다.
3. **`last_hardclock` 정의 자리**는 바이트로 정해지지 않으므로(D071 과 같은 경우) 사용자에게 묻습니다. 추천은 Darwin 처럼 `kern_clock.c` 입니다(유일한 사용처이고, M7 링크에서 `__common` 주소로 다시 확인 가능).
4. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_clock.c`(새 파일, 표시 `plan 455 (m68k)`)를 만들고, 도구 등록(`MARKERS`·`EXCEPTS[455]`·`FILES['kern_clock']`), 스테이징·x86 관문·`cmd2`·`final` 은 앞 절과 같습니다.
5. 미리 정한 기준: `x86-kern_clock` OBJECT_MATCH, 원본에 없는 미정의 기호 0.
6. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-kern-clock.diff`, `09_validation/reconstruction/m5-m68k-kern-clock-variants-20261015.json`·`m5-m68k-kern-clock-20261015.json`.

### 455.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기 356·418(차 62), 0x3e8 = 1000, `linkw` −28, `clock_value(1)`·`System` = 1, 참고 줄 범위, `_last_hardclock` 0x40b605c `__common`·사용처 `_hardclock` 하나 | §455 준비 중 python 출력·이미지 목록·기호표·참고 파일 읽음 | ✅ |
| **0x4003480·0x400352e 는 `d3` 을 넣는 명령이고, `_itimerdecr` 호출은 0x4003490·0x400353e** | 이미지 목록 grep(네 주소) | ✅ **제 문구 정정**: "두 호출이 `d3` 을 넘김(넣기 0x4003480·0x400352e, 호출 0x4003490·0x400353e)" |
| 계획한 C 의 순서(차 → 프레임 사본 → 나눗셈 → 새 값 저장)는 원본과 맞고, §448 `P448__V4` 의 `_sched_usec_elapsed` 가 같은 순서로 컴파일됨 | `08_build/artifacts/m5p448-var2/otool/P448__V4.txt` 238–2a6 읽음 | ✅ (레지스터는 컴파일이 판정) |
| 빈 4 B 는 인라인 도우미 자체로 설명됨(`P448__V4` `_sched_usec_elapsed` 도 `linkw #-12` 에 8 B 사본) | 같은 목록 `linkw a6,#0xfff4`, 사본 −12·−8 | ✅ 따로 변수를 꾸며 넣을 필요 없음 |
| `ns_div_val` m68k 글의 `*msw = quo;` 가 원본의 −12 되쓰기와 맞고, `[0]` 이 상위 워드(빅엔디언) | `m5_m68k_ns.py:42–48` 읽음, 원본 0x4003418 `movel d5,a6@(-12)` | ✅ |
| 지금 `kern_clock.c` 에는 `System`·`ns_time_t` 가 보이지 않음; `<kernserv/clock_timer.h>` 는 `KERNEL_PRIVATE` 에서 `kern/clock.h` 만 가져와 열거가 하나뿐; `extern ns_time_t clock_value();` 필요 | 스테이징 `kernserv/clock_timer.h` 전체 읽음(18–40 행), 07 `kern/clock.h:77–80` | ✅ |
| 공통 정의는 L1 을 해치지 않지만 L1 이 크기·주인을 검증하지 않으므로 `_last_hardclock` 이 COMMON(8) 인지 따로 확인할 것 | §441 `ast` 객체 `_need_ast` = COMMON 4(python) | ✅ 기준에 더함 |
| §448 에서 입력 순서는 효과가 없었으므로 **출력 순서 변형**(§448 (가))을 더할 것 | §448 결과(계획 1439–1449 행) 읽음 | ✅ 변형 E 추가 |
| 별도 `delta` 변수·`int myticks` 변형도 시험 가능 | 설계 | ✅ 변형 F·G 추가(작은 비용) |
| 도우미가 인라인되어 바깥 함수가 생기지 않아야 함 | 설계 | ✅ 기준에 더함(외부 구간 8 개 그대로, 정적 함수 없음) |

수정한 방법 1(실행 전 고정): 변형 A–D(입력 순서), E(출력 순서: `"=d" (rem), "=d" (quo)`, 템플릿 `%0:%1`, 입력은 A 순서), F(A + 별도 `ns_time_t delta_hardclock` 변수), G(A + `int myticks`). 미리 정한 기준에 `_last_hardclock` COMMON 8, 정적 함수 없음을 더합니다.

### 455.2 시도 1 결과와 시도 2 계획(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-kern-clock-variants-20261015.json`

시도 1(run `m5p455-var1`, 도구 `m5_m68k_clock.py`, 7 명령 모두 종료 0·경고 없음, 실행 전후 해시 같음):
- 일곱 변형 모두 NOT_MATCH 이고, 다른 외부 구간은 `_hardclock` 하나뿐입니다. 원본에 없는 미정의 기호 0, `_last_hardclock` COMMON 8, 정적 함수 없음(도우미 인라인됨)입니다.
- 비 STABS 로 A·B·C·D·F·G 가 같고, E 만 다릅니다(입력 순서·별도 `delta`·`int` 는 효과 없음).
- 실기 otool 목록과 원본의 명령 꼴 비교(주소·분기 대상 가림, python `difflib`):
  - **E 는 원본처럼 `clrl d2` 를 상위 워드 적재보다 먼저 합니다**(A 는 반대). §448 의 "원본은 `clrl` 을 값 적재보다 먼저" 와 같은 차이이며, 출력 피연산자 순서가 원인이었습니다.
  - 모든 변형에 남은 차이: 원본은 `lea _last_hardclock,a0` 로 주소를 레지스터에 두고 `a0@`·`a0@(4)` 로 네 번(읽기 둘, 쓰기 둘) 접근합니다. 다시 만든 객체는 절대 주소를 네 번 씁니다(원본 113 명령, A 112 명령).

시도 2(같은 도구에 변형 추가, 07 변경 없음):
- H: E + Darwin 꼴 배열 `ns_time_t last_hardclock[NCPUS];` 와 `last_hardclock[cpu_number()]`(07 `kern_clock.c` 는 `<cpus.h>` 를 가져옴, `cpu_number()` 는 `(0)`).
- I: H + 별도 `delta_hardclock` 변수.
- J: E + 함수 안 포인터 `register ns_time_t *lastp = &last_hardclock;` 로 읽고 씀(참고 근거 없음; 주소 레지스터 원인 확인용).
- 고르기 규칙은 §455 그대로입니다(하나면 채택, 같은 것이 여럿이면 사용자에게, 없으면 진단; 두 시도 연속 줄지 않으면 멈춤).

### 455.3 시도 2 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-kern-clock-variants2-20261015.json`

- run `m5p455-var2`(3 명령 모두 종료 0·경고 없음, 실행 전후 해시 같음). 도구에 변형 목록 인자를 더했고, A–G 의 글은 시도 1 스테이징 파일과 같음을 확인했습니다(python).
- **H·I OBJECT_MATCH**(외부 구간 8/8 같음, 원본에 없는 미정의 기호 0, `_last_hardclock` COMMON 8, 정적 함수 없음)이고, 두 객체는 비 STABS 로 서로 같습니다. J(포인터)는 `_hardclock` 이 다릅니다.
  - 원본의 `lea _last_hardclock,a0` 는 Darwin 꼴 배열 `last_hardclock[NCPUS]` 와 `[cpu_number()]` 접근에서 나옵니다.
- 미리 정한 규칙대로, 바이트가 같은 H(차를 인자에 바로 씀)·I(Darwin 처럼 `delta_hardclock` 변수를 둠)는 사용자에게 묻습니다. `last_hardclock` 정의 자리(§455 방법 3)도 함께 묻습니다.

### 455.4 결정과 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-kern-clock-20261015.json`

- 사용자 결정: **D074** = 변형 I(`delta_hardclock` 변수, Darwin 구조), **D075** = `last_hardclock[NCPUS]` 를 `kern_clock.c` 에 정의.
- 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_clock.c`(새 파일, 422 행 = 347 + 75)는 표시 줄 75 개이고, 모두 `plan 455 (m68k)` begin/end 묶음 안에 있습니다.
  - 코드 줄(주석·빈 줄 제외)은 변형 I 와 같습니다(python).
  - 넣은 줄 가운데 Darwin 0.1 원문과 글자가 같은 실질 줄은 `last_hardclock[cpu_number()] = new_hardclock;`(Darwin `kern_clock.c:171`) 하나라서(python 대조; `#define tick myticks`·`#undef tick` 은 NeXTMach 182·381 행에도 있음), D061 선례대로 파일 머리에 고지(Darwin 파일 1–23 행 APSL 고지)와 그 줄의 `plan 455 (Darwin)` 표시를 넣었습니다.
  - diff `06_reconstruction/evidence/m68k-kern-clock.diff`, PROVENANCE 1084 → 1085(출처 `nextmach+darwin01`), MODIFICATIONS 609 → 610.
- 도구: `stage_m68k.py` 의 `MARKERS`(75)·`EXCEPTS[455]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['kern_clock']`. 실행 전후 해시가 같습니다.
  - 표시 줄 수를 처음에 27 로 잘못 등록했습니다(생성기가 도우미 함수 글을 한 항목으로 셈). 스테이징 검사가 46 을 세어 멈췄고, 그 중단 스테이징 `m0p455-a1-stage`(manifest 없음)는 지우지 않고 남겼습니다. 고지를 넣은 뒤 최종 75 입니다.
  - 고지 없는 판의 run `m5p455-a2` 도 OBJECT_MATCH 였습니다(기록 파일은 최종 run 으로 덮어씀).
- 스테이징 `m0p455-a3-stage` 의 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **최종 run `m5p455-a3`**(1 명령, 종료 0, 경고 없음): **`x86-kern_clock` OBJECT_MATCH**, 외부 구간 8/8 같음, 원본에 없는 미정의 기호 0, `_last_hardclock` COMMON 8, 변형 I 객체와 비 STABS 같음.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 159 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 160 입니다.
- 참고: 출력 피연산자 순서(E 꼴)가 `clrl` 순서 차이를 없앴으므로, §448 `ns_timer` 의 남은 나눗셈 차이도 같은 꼴로 풀릴 가능성이 있습니다(그 객체는 콜아웃 큐 작성이 먼저 필요).

## 456. M5-13 세부 계획 — m68k `kern_uname`: `machine` 필드를 `machine_type` 점프 표로(x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- §441 객체 `O441__L2_174__kern_uname.o`(run `m3p441-cc1`; 컴파일 줄은 §429 `m3p429-cc2/run.cmd`):
  - L1 은 NOT_MATCH(`__TEXT,__text` 바이트 차이 186, 참조 차이 9)입니다.
  - 외부 함수는 `_uname` 하나이고, 객체 464 B, 원본 562 B 입니다(원본 0x400a968–0x400ab9a, 바로 뒤가 `_gethostid`). 차는 98 입니다(python).
  - 원본에 없는 미정의 기호는 없습니다.
- 07 `bsd/kern/kern_uname.c`(77 행, 계획 237 작성, x86 원본 기준)는 마지막에 `switch (machine_slot[0].cpu_subtype)` 로 "386 AT"·"486 AT"·"486SX AT"·"586 AT"·"586SX AT"·"Unknown AT" 를 고릅니다(51–76 행).
- 원본 m68k `_uname`(이미지 목록, 기호 이름으로 바꿔 읽음):
  - 앞부분(`"NEXTSTEP"`·`hostname`·`sprintf(buf, "%d", 0)`·`"%d", 4` 와 `copyoutstr` 넷, `u_error` 검사)은 07 과 같은 꼴입니다. `_ALLOW_FAULT_START` 는 `_copyoutstr` 과 같은 주소(0x400159a)의 별칭입니다(기호표).
  - 그 뒤 `clrl d0; moveb _machine_type,d0`(0x400aa60; `_machine_type` 은 원본 `__common` 0x40b61ac), `moveq #9,d1; cmpl d0,d1; bcs` 기본(§456.1 정정)으로, 그리고 4 B 주소 10 개의 점프 표(0x400aa7c)로 갑니다.
  - 점프 표(원본 바이트를 python 으로 읽음): 0 → 0x400aaa4 `"NeXT_CUBE"`, 1 → `"NeXT_WARP9"`, 2 → `"NeXT_X15"`, 3 → `"NeXT_WARP9C"`, 4 → `"NeXT_Turbo"`, 5 → `"NeXT_TurboC"`, 6·7 → 기본(0x400ab6a `"Unknown"`), 8 → `"NeXT_TurboCube"`, 9 → `"NeXT_TurboCubeC"`.
  - 각 경우는 `copyoutstr(문자열, uap->name->machine(+0x80), 0x20, &len)` 의 인자를 넣고 공통 꼬리(`bsr`, `u_error` 저장)로 갑니다. 본문은 주소 순으로 0·1·2·3·4·5·8·9·기본입니다.
- `machine_type` 은 실기 SDK `bsd/m68k/cpu.h:51` 의 `extern u_char machine_type; /* see scr.h for values */` 입니다. NeXTMach `next/scr.h:34–37` 은 0–3 의 이름(`NeXT_CUBE`·`NeXT_WARP9`·`NeXT_X15`·`NeXT_WARP9C`)만 정의하고, 4·5·8·9 의 이름은 참고 코드(NeXTMach·Darwin·Mach4)에 없습니다(grep).

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_uname.c`(새 파일, 표시 `plan 456 (m68k)`, 표시 줄 44)를 만듭니다.
   - 33 행(`extern char hostname[];`) 뒤 `#if m68k` 에 `extern u_char machine_type;`(SDK 선언과 같음)을 둡니다.
   - 51–76 행 앞에 `#if m68k`(begin) 묶음으로 `switch (machine_type)` 와 `case 0`…`case 9`(원본 순서 0·1·2·3·4·5·8·9) + `default: "Unknown"` 을 두고, `#else`(end) 뒤에 07 줄을 그대로 두고, `#endif` 로 닫습니다.
   - `case` 는 숫자로 씁니다. 이름이 없는 값(4·5·8·9)의 상수 이름을 지어내지 않고, 0–3 만 NeXTMach 이름을 쓰려면 `scr.h` 를 새로 들여야 하므로(M4 범위) 이번에는 숫자로 둡니다. 바이트는 같으므로 결과 뒤 사용자에게 확인합니다.
2. 도구: `MARKERS['plan 456 (m68k)'] = {'src/bsd/kern/kern_uname.c': 44}`, `EXCEPTS[456]`(455 의 열 + `x86-kern_uname`), `--plan` 목록, `FILES['kern_uname']`.
3. 스테이징 `--plan 456`, x86 관문, 스테이징 차이 = 이 `.c` 하나, `cmd2 456 kern_uname`(§429 run 의 `-c` 줄 1 개), kr_run, otool, `final`.
4. 미리 정한 기준: `x86-kern_uname` OBJECT_MATCH(`__cstring` 내용 포함), 원본에 없는 미정의 기호 0. 아니면 진단 뒤 멈춥니다(두 시도 연속 줄지 않으면).
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-kern-uname.diff`, `09_validation/reconstruction/m5-m68k-kern-uname-20261015.json`.

### 456.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기 562·464(차 98), `_gethostid` 이어짐, 점프 표 10 개와 각 경우의 문자열, 본문 순서, `+0x80`·`0x20`, 별칭·`__common` 주소, `cpu.h:51`, `scr.h:34–37`, 4·5·8·9 이름 없음 | §456 준비 중 python(원본 바이트에서 점프 표 직접 읽음, `__cstring` 읽음)·기호표·grep | ✅ |
| **"`cmpl #9`" 는 틀린 서술 — 원본은 `moveq #9,d1; cmpl d0,d1; bcs 기본`** | 이미지 목록 0x400aa60–0x400aa6c 읽음 | ✅ **제 문구 정정**(범위 검사의 뜻은 같음) |
| 앞부분(07 26–50 행)은 원본과 뜻이 같고 프레임 −36(`len` −36, `buf` −32) | 원본 `linkw #-36`, `pea a6@(-36)`, `lea a6@(-32)` 읽음 | ✅ |
| `u_char` 는 `sys/param.h:193` → `sys/types.h:88` 로 보임 | 스테이징 두 줄 읽음 | ✅ |
| 문자열을 처음 나오는 순서로 모으면 원본 [0x40a61d4, 0x40a6248) 116 B 와 같음; L1 은 문자열 **내용**만 보고 순서는 보지 않음(`l1_compare.py` 문자열 절 처리) | `l1_compare.py:300–310` 읽음(문자열 절은 "references checked by content"), python 116 | ✅ 기준에 `__cstring` 바이트 직접 대조를 더함 |
| 표시 줄 44(묶음 40 + 개별 4), `check_derived` 통과 | 생성기 출력 `77 → 121`, 스테이징이 다시 판정 | ✅ |
| `m5_m68k_pc.py` 의 모양 비교는 `FILES` 에 넣어도 `kern_exec` 기준으로 비교함(135 행) | 135 행 읽음 | ⚖️ 사실. 이 모양 비교는 §444 의 PC 쓰기 전용 진단이고 §446 이후 기준이 아니었음(결과의 `[0]`). 이 절의 기준에 넣지 않음을 명시 |
| 생성 코드(점프 표·꼬리 합치기)는 컴파일 전에는 미확인 | — | ⏭️ 컴파일이 판정 |

추가한 기준(실행 전 고정): 객체 `__cstring` 바이트 = 원본 [0x40a61d4, 0x40a6248) 116 B, `_uname` 외부 구간 같음(원본 562 B).

### 456.2 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-kern-uname-20261015.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_uname.c`(새 파일, 121 행)는 표시 줄 44 개입니다.
  - diff 는 `06_reconstruction/evidence/m68k-kern-uname.diff` 입니다. PROVENANCE 1085 → 1086, MODIFICATIONS 610 → 611 입니다.
- 도구: `stage_m68k.py` 의 `MARKERS`(44)·`EXCEPTS[456]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['kern_uname']`. 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p456-a1`, 1 명령, 종료 0, 경고 없음): **`x86-kern_uname` OBJECT_MATCH**, `_uname` 외부 구간 같음(원본 562 B), 원본에 없는 미정의 기호 0 입니다.
  - 추가 기준: 객체 `__cstring` 116 B 가 원본 [0x40a61d4, 0x40a6248) 와 바이트까지 같습니다(기록의 `cstring_check`).
- `case` 를 숫자로 쓴 꼴과, 0–3 에 NeXTMach `scr.h` 이름을 쓰는 꼴은 바이트가 같습니다. 이름 쪽은 `scr.h` 를 들여야 하므로(M4) 숫자 꼴로 두었고, 사용자에게 확인합니다.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 160 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 161 입니다.

### 456.3 D076 에 따른 고침 계획(코딩 전, 2026-10-15)

확인한 사실:
- 사용자는 처음에 "0–3 만 scr.h 이름" 을 골랐습니다. 그런데 NeXTMach `next/scr.h`(119 행)는 115–117 행에서 `volatile struct scr1 *scr1; volatile int *scr2; volatile u_char *brightness;` 를 정의합니다(초기값 없는 정의 → 공통 기호).
- 원본 m68k 기호표에는 `_scr2`(0x40b651c)·`_brightness`(0x40b6120)만 `__common` 에 있고 `_scr1` 은 없습니다(grep). 그대로 들이면 원본에 없는 기호가 생기고 `kern_uname` 객체가 공통 기호 셋을 갖게 됩니다(D059 의 첫 언급 순서 배치에도 영향 가능).
- 이를 알리고 다시 물어 **D076** = 이름 네 줄만 복사로 정했습니다.

방법:
1. 덮어쓰기 `kern_uname.c` 의 10 행(`#import <mach/machine.h>`) 뒤에 `#if m68k`(begin) 묶음으로 NeXTMach `scr.h` 1 행(출처 줄 `@(#)scr.h … (c) 1986 NeXT`)과 34–37 행(`#define NeXT_CUBE 0` … `#define NeXT_WARP9C 3`)을 글자 그대로 두고 `#endif`(end)로 닫습니다(7 줄).
2. `case 0`–`case 3` 을 `case NeXT_CUBE` … `case NeXT_WARP9C` 로 바꿉니다(4·5·8·9 는 숫자 그대로).
3. 표시 줄 44 → 51(python: 77 → 128 행). 도구 `MARKERS` 값만 고칩니다.
4. 스테이징(새 이름 `m0p456-a2-stage`)·x86 관문·컴파일(run `m5p456-a2`)·`final`·`__cstring` 대조를 다시 합니다. 기준은 §456 과 같고, 시도 1 객체와 비 STABS 가 같아야 합니다.
5. 기록: PROVENANCE 행 출처에 `mk-108.1/next/scr.h:1,34–37` 을 더하고(D013), diff·MODIFICATIONS 를 새로 덧붙입니다(시도 1 행은 그대로 두고 새 행).

#### 456.3.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `scr.h` 1·34–37·115–117 행 내용, 후보가 1·34–37 행을 글자 그대로 복사 | 생성기가 `scr.h` 1·34–37 행을 assert 로 대조(통과) | ✅ |
| 원본 `_scr2`·`_brightness` 는 `__common`, `_scr1` 0 건 | 기호표 grep(`_scr1` 0) | ✅ |
| 후보는 설치본과 7 줄 묶음·case 이름 넷만 다르고, 스테이징 머리에 `NeXT_CUBE` 등 정의·충돌 없음 | `diff` 출력, 스테이징 전체 `grep -rnw`(문자열 상수만 걸림) | ✅ |
| x86 쪽은 본 파일과 같고 표시 줄 51 로 `check_derived` 통과 | 생성기 출력 77 → 128 | ✅ |
| 파일 머리 "No reference text was used" 가 복사 블록과 맞지 않음 | 07 1–5 행 읽음 | ✅ 채택: 5 행 뒤에 표시 줄 하나(복사 범위와 D024 를 밝힘)를 더해 표시 줄 52(77 → 129 행) |

### 456.4 D076 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-kern-uname-d076-20261015.json`

- 덮어쓰기 `kern_uname.c` 를 D076 꼴로 바꿨습니다(129 행, 표시 줄 52). `MARKERS` 값만 52 로 고쳤고, 실행 전후 도구 해시가 같습니다.
- 스테이징 `m0p456-a2-stage`(차이 = 이 `.c` 하나, x86 관문 7 같음), run `m5p456-a2`(종료 0, 경고 없음):
  - **`x86-kern_uname` OBJECT_MATCH**, 원본에 없는 미정의 기호 0, `__cstring` 116 B 원본과 같음, 공통 기호 없음(`scr.h` 의 전역은 들어오지 않음).
  - 시도 1(숫자 꼴, run `m5p456-a1`) 객체와 비 STABS 가 같습니다.
- 기록:
  - diff `06_reconstruction/evidence/m68k-kern-uname.diff` 를 최종본으로 다시 만들었습니다.
  - PROVENANCE 는 대상 경로마다 한 행이라(중복 0, python), 계획(§456.3 의 5)과 달리 새 행을 덧붙이지 않고 오늘 덧붙인 맨 끝 행(1086 행)을 그 자리에서 갱신했습니다(출처 `authored+nextmach`, `next/scr.h:1,34–37`). 행 수는 1086 그대로입니다.
  - MODIFICATIONS 는 변경 기록이므로 한 행을 덧붙였습니다(611 → 612).
  - 시도 1 기록 `m5-m68k-kern-uname-20261015.json` 은 그대로 둡니다.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 160 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 161 입니다.

## 457. M5-14 세부 계획 — m68k `ufs_dsort`: 고전 `disksort` 빼기와 NeXTMach `spldma()` 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- §441 객체 `O441__L2_149__ufs_dsort.o`(run `m3p441-cc1`; 컴파일 줄은 §430 `cc.cmd`):
  - L1 은 NOT_MATCH(`__TEXT,__text` fail)입니다.
  - 외부 구간: `_disksort_first`·`_disksort_remove` 가 다르고, `_disksort_enter`·`_enter_head`·`_enter_tail`·`_init`·`_free` 는 같습니다.
  - 객체의 `_disksort` 구간(1190 B)은 원본에서 짝이 없습니다. 원본 기호표에 `_disksort` 가 없습니다(grep).
  - 원본에 없는 미정의 기호는 없습니다.
- 07 `bsd/ufs/ufs_dsort.c`(735 행)와 NeXTMach `mk-108.1/ufs/ufs_dsort.c` 의 차이(계획 206·206.1, x86 원본 기준):
  - 55 행: NeXTMach 의 `#if NeXT` / `#else NeXT`(고전 `disksort` 를 NeXT 에서 뺌)를 `#if 1` 로 바꿔 고전 `disksort` 를 넣었습니다(x86 원본 0x13f90c 에 있음). 134 행 `#endif NeXT` 로 닫힙니다.
  - 391–395·596–600·631–635 행: NeXTMach 의 `s = spldma();` 를 `#if NeXT s = splbio(); #else NeXT s = spldma(); #endif NeXT` 로 바꿨습니다(x86 원본이 `_splbio` 를 부름).
  - 그 밖(`machine/spl.h` 경로, `disksort_enter` 의 `th` 검사)은 m68k 에서도 이미 같습니다(`_disksort_enter` 구간 같음).
- 원본 m68k:
  - 객체의 정적 함수 영역 [0x4036d3e, 0x4037142) 은 1028 B 이고, 함수 시작 6 개(0x4036d3e·d9e·e20·e8c·f4a·f96)입니다. 객체 `_disksort` 구간 1190 B 에서 1028 B 를 빼면 162 B 로, 고전 `disksort` 의 크기와 맞습니다(python).
  - `ds_enter_common`(0x4036f96, 0x4036fac)·`_disksort_first`(0x4037250)·`_disksort_remove`(0x40372ae)는 `movew #0x2600,sr` 입니다.
  - SDK `kernserv/m68k/spl.h`: `IPLDMA 6`·`spldma() SPLU_MACRO(IPLDMA)`, `IPLBIO 3`·`splbio() SPLU_MACRO(IPLBIO)` 이고, `ipltospl(ipl) = SR_SUPER | ((ipl) << 8)` 이므로 0x2600 은 `spldma()` 입니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_dsort.c`(새 파일, 표시 `plan 457 (m68k)`, 표시 줄 14):
   - 55 행 앞 `#ifndef m68k`, 134 행 뒤 `#endif` 로 고전 `disksort` 를 뺍니다.
   - 세 spl 자리 앞에 `#if m68k` / `s = spldma();` / `#else`, 뒤에 `#endif` 를 둡니다(NeXTMach 꼴).
2. 도구: `MARKERS['plan 457 (m68k)'] = {'src/bsd/ufs/ufs_dsort.c': 14}`, `EXCEPTS[457]`(456 의 열하나 + `x86-ufs_dsort`), `--plan` 목록, `FILES['ufs_dsort']`.
3. 스테이징 `--plan 457`, x86 관문, 차이 = 이 `.c` 하나, `cmd2 457 ufs_dsort`, kr_run, otool, `final`.
4. 미리 정한 기준: `x86-ufs_dsort` OBJECT_MATCH, 원본에 없는 미정의 기호 0, 객체 `__text` 의 정적 함수 영역이 원본 1028 B 와 같은 크기. 아니면 진단 뒤 멈춥니다(두 시도 연속 줄지 않으면).
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-dsort.diff`, `09_validation/reconstruction/m5-m68k-ufs-dsort-20261015.json`.

### 457.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 구간 결과, `_disksort` 원본에 없음, 1190 = 고전 `disksort` 162 + 정적 1028, 함수 시작 6 개 | §457 준비 중 python·grep | ✅ |
| 고전 `disksort` 뒤 객체 전체에서 원본과 다른(재배치 아닌) 바이트는 0x4036fae·0x4037252·0x40372b0 세 곳뿐이고 모두 0x23 대 0x26 | python: O441 `__text` 162 B 뒤 1702 B 와 원본 0x4036d3e 부터 같은 길이 비교, 재배치 자리 제외 → 정확히 세 곳 | ✅ |
| `movew #0x2600,sr` 주소는 0x4036fac·0x4037250·0x40372ae(0x4036f96 은 함수 시작) | 이미지 목록 | ✅ (계획의 "`ds_enter_common`(0x4036f96, 0x4036fac)" 은 시작·명령 두 주소를 적은 것) |
| 바이트는 IPL 6 만 정하고 철자는 정하지 않음 — `splusclock()` 도 IPL 6 | SDK `kernserv/m68k/spl.h:87·99` | ✅ 철자 `spldma()` 는 NeXTMach 원문(392·590·621 행의 `s = spldma();`)이 근거임을 명시 |
| 계획의 "NeXTMach 와 같음" 은 지나친 표현 — `disksort_enter` 의 `th` 검사는 07(계획 206) 쪽이며 원본 0x4037176/0x4037178 `tstl a3; beq` 가 이를 뒷받침 | 이미지 목록 0x4037174–0x403717a 읽음 | ⚖️ 계획은 이미 "`th` 검사는 m68k 에서도 같음(유지)" 으로 적었음; 덮어쓰기도 그 줄을 바꾸지 않음 |
| 표시 줄 14, `check_derived` 통과, 비 m68k 판 = 본 파일 | 생성기 출력 735 → 749, 14 | ✅ |
| 다른 m68k 객체·원본에 `_disksort` 참조 없음 | 기호표에 `_disksort` 없음(grep); 객체 검색은 검토자 결과 | ✅(원본) / ⏭️(객체 검색) |
| `final` 의 모양 비교는 `kern_exec` 기준이라 무관; 기준은 OBJECT_MATCH 전체 | §456.1 과 같음 | ✅ 기준은 L1 OBJECT_MATCH(크기 같음은 보조) |

### 457.2 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-ufs-dsort-20261015.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_dsort.c`(새 파일, 749 행)는 표시 줄 14 개입니다.
  - diff 는 `06_reconstruction/evidence/m68k-ufs-dsort.diff` 입니다. PROVENANCE 1086 → 1087, MODIFICATIONS 612 → 613 입니다.
- 도구: `stage_m68k.py` 의 `MARKERS`(14)·`EXCEPTS[457]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['ufs_dsort']`. 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p457-a1`, 1 명령, 종료 0): **`x86-ufs_dsort` OBJECT_MATCH**, 외부 구간 7/7 같음, 원본에 없는 미정의 기호 0, `_disksort` 기호 없음입니다.
  - 객체 `__text` 1702 B = 원본 [0x4036d3e, 0x40373e4) 1702 B(python)입니다.
  - 컴파일 경고 둘(`bucket_alloc`·`bucket_free` 의 `kalloc`/`kfree` 형)은 §441 run 에도 있던 것입니다(07 198·212 행 → 덮어쓰기 200·214 행).
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 161 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 162 입니다.
