# 커널 소스 복원 작업계획 — 보관 §550–566

`02_plan/RECONSTRUCTION_PLAN.md` 의 §550–566(m68k M4 사운드: `snd_rcv`(D122), `snd_reply`·1997 `snd_var_t`·x86 07 `snd_msgs.h`(D123), `snd_device`(D124), `snd_dspcmd`·1997 `snd_stream_msg_t`·`dsp.h`(D125), `snd_dspdev`(D126), `snd_dspqueue`(D127))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-30, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 본문은 `---` 아래부터입니다.

---

## 550. M4-56 세부 계획 — `snd_rcv.c`(행 247) 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유: 남은 후보 가운데 가장 작은 정확 경계 C 단위이고(더 작은 정확 항목은 `fpsp/skeleton.sa` 2 B 와 이름 없는 16 B 구간), 미뤄 둔 이유(`snd_var.h` 가 `nextdev/dma.h` 를 들임, §530)가 07 `dma.h`(§544·§547)로 풀렸습니다. `if_en.c`(행 260)는 경계가 정확하지 않고 이름 있는 원본 함수 23 개 가운데 16 개만 대응돼 뒤로 둡니다.

확인한 사실(이번 세션; 원본 목록, 기호표, python):
- 행 `m68k-247`(정확) [0x408503e, 0x4085056), 24 B, 함수 1 개 `_snd_rcv_alloc_msg_frame`: `movel #0x2000,0x40c6ed8`(= `_snd_rcv_msg` 0x40c6ed4 + 4) 후 `movel #0x40c6ed4,d0` 반환. NeXTMach `nextdev/snd_rcv.c`(33 행) 본문과 같은 동작(`msg_size` 는 옛 IPC `msg_header_t` 의 오프셋 4, `sizeof(snd_rcv_msg)` = `MSG_SIZE_MAX` 8192 = 0x2000).
- `_snd_rcv_msg` 는 `__common`(sect 6) 0x40c6ed4, 다음 기호 `_boot_info` 까지 8192 B(python). 원본 함수 목록(`m68k-functions.tsv`)은 이 함수를 앞 행의 `_snd_link_snd_complete` 끝으로 묶지 않고 기호표에 진입점이 있음(0x408503e).
- 스테이징 `mach/message.h` 에 옛 IPC 정의 `msg_header_t`(`msg_size` 둘째 낱말)·`MSG_SIZE_MAX 8192` 가 있음(503 행). `kern/mach_types.h`·`sys/message.h` 는 스테이징에 없음.
- NeXTMach `snd_rcv.c` 는 `<sound.h>`(구성 `NSOUND`, `files.NeXT:66` `optional sound`)와 `<nextdev/snd_var.h>`(→ `kern/thread.h`, `nextdev/dma.h`, `nextdev/snd_msgs.h` → `kern/mach_types.h`, `sys/message.h`)를 들임. 원본 `_sound_dinfo`(`sound_dinfo[NSOUND]`, NeXTMach `snd_device.c:73`)·`_dsp_dinfo` 다음 기호까지 각 4 B(1 칸과 맞음; 크기의 증명은 아님).

방법(진단; 명세 `08_build/artifacts/m4p550/spec.json`, run `m4p550-p1`, 바탕 `m0p549-a1-stage`, `m4_id` `m68k-247`, 줄 틀 `machdep/i386/dkbad.c`):
- N1: NeXTMach `snd_rcv.c` 의 include 를 `<sound.h>` 그대로(`inc` 진단 대역 `#define NSOUND 1`), `<nextdev/snd_var.h>`·`<nextdev/snd_msgs.h>` 는 NeXTMach 사본을 `inc` 로, `kern/mach_types.h`·`sys/message.h` 는 `inc` 진단 별칭(`#import <mach/mach_types.h>`·`#import <mach/message.h>`).
- N2: N1 에서 `<nextdev/snd_var.h>` 대신 `<mach/message.h>` 만 들인 꼴(본문 같음).
- 측정: `compare`(종료·경고·i386 머리·L1), `m68k_funcbytes.py 408503e 4085056`(재배치 대상 `_snd_rcv_msg+4` 저장·`_snd_rcv_msg+0` 반환), 객체의 정의 기호 전체(외부·지역·COMMON 이름·크기, 섹션 목록; `_snd_rcv_msg` COMMON 8192 기대, 그 밖의 COMMON 이 생기면 원본에 이름이 있더라도 따로 적음), 원본에 없는 미정의 0. STABS 수는 기록만(N1·N2 의 `obj_sig` 같음은 요구하지 않음; §550.1).
판정(미리 정함; 07 은 바꾸지 않음): N1·N2 가운데 1/1·`OBJECT_MATCH`·원본에 없는 COMMON 0 인 꼴을 적고, 07 꼴(머리 공급: `sound.h` 구성 생성 머리·`snd_var.h`/`snd_msgs.h` 사본 여부)을 사용자께 여쭙니다. 컴파일이 실패하면 오류를 적고 머리를 고친 진단 꼴을 더 시험합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 550.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 24 B 의 바이트·동작(`_snd_rcv_msg+4` 에 8192, `_snd_rcv_msg` 반환), 기호·행 경계, `_snd_rcv_msg` 다음 기호까지 8192 B(간격일 뿐 크기 증명은 아님) | 이번 세션 원본 목록·기호표·python | ✅ |
| 미룬 근거는 §531 이 아니라 §530(보관본 273 행) | 보관본 273 행과 §530·§531 제목 읽음 | ✅ 제 인용 오류. 고침 |
| "가장 작은 정확 단위" 는 C 단위로 한정(`fpsp/skeleton.sa` 2 B 등이 더 작음) | — | ✅ 고침 |
| N1 머리 사슬의 형(`port_name_t`·`msg_type_t`·`vm_address_t`·`struct dma_hdr`·`howmany`)은 스테이징에서 풀릴 것으로 예상 | 정적 예측 | ⏭️ 컴파일 결과로 확인 |
| `snd_var.h` 는 `snd_var_t` typedef 로 끝나고 전역 `snd_var` 는 `snd_server.c:86` 이 정의 → N1 이 `_snd_var` COMMON 을 내면 안 됨; 원본에 이름이 있다는 것만으로 받지 말 것 | `snd_var.h:110–124`(이번 세션 grep), `snd_server.c:86` 읽음 | ✅ 측정에 정의 기호 전체 기록을 더함 |
| 재배치 대상 둘을 확인하고, STABS 는 따로 기록(`obj_sig` 가 STABS 수를 포함) | — | ✅ 고침 |
| `inc` 는 기존 `-I` 뒤에 붙어 스테이징 파일을 덮지 못함(`m4_m68k_probe.py:223–225`) | 해당 행 읽음 | ✅ |

### 550.2 결과(2026-10-30)

- run `m4p550-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p550-20261030.json`, `diag_gate` 참): N1·N2 모두 종료 0·경고 0·i386 머리 0, `__text` 24 B, 1/1(`m4-m68k-funcbytes-p550-N1/N2-20261030.json`; 재배치 둘 다 `_snd_rcv_msg`), L1 `OBJECT_MATCH`(사유 없음), `candidate`, 원본에 없는 미정의 0. N1 과 N2 는 canon 같음, `obj_sig` 는 STABS 수(618 대 98)와 N1 의 COMMON `_master_cpu` 때문에 다름(§551.1 에서 고침).
- 정의 기호: N1 = `_snd_rcv_alloc_msg_frame`(외부), COMMON `_snd_rcv_msg` 8192·`_master_cpu` 4(머리 사슬 `kern/thread.h` 쪽 임시 정의; 원본에 이름 있음); N2 = 함수와 `_snd_rcv_msg` 8192 만. `_snd_var` 는 어느 쪽도 내지 않음(§550.1 예측과 같음). 섹션은 둘 다 `__text` 하나.
- 판정(미리 정한 대로): 두 꼴이 같은 코드를 내므로 07 꼴(머리 공급)을 사용자께 여쭙니다.
- 사용자 결정(2026-10-30, AskUserQuestion): "NeXTMach 그대로 + 사운드 머리 사본"(N1 꼴).

## 551. M4-57 D122 구현 계획 — 07 `src/machdep/m68k/snd_rcv.c`, 사운드 머리 둘, 구성 `NSOUND`(코딩 전, 2026-10-30)

확인한 사실(이번 세션): 스테이징에서 `<sound.h>`·`NSOUND`·`nextdev/snd_var.h`·`nextdev/snd_msgs.h` 를 쓰는 곳은 받아들인 `machargs.c`(52–56·166–170 행, 둘 다 `#if DEBUG` 안)와 `driverkit/snd_reply.c`(`"snd_msgs.h"` 따옴표 꼴, x86 경로; M5 205 줄에 없음, grep 0) 뿐; `DEBUG` 는 m68k 빌드에서 정의되지 않으므로(M5 명령 줄에 `-DDEBUG` 없음, 스테이징 생성·머리에 `#define DEBUG` 0 건; 이번 세션 grep) `#if DEBUG` 는 거짓이고 `machargs.c` 는 영향을 받지 않음. 스테이징 `src/bsd/nextdev/` 에는 `dma.h`·`npreg.h` 만 있음. N1 은 `snd_var.h` 를 고치지 않고 컴파일됨(§550.2).

1. 구성: `06_reconstruction/config_options-m68k.tsv` 에 `sound NSOUND sound.h 1 hypothesis`(근거: 원본에 `_snd_rcv_alloc_msg_frame` 이 있으므로 `NSOUND > 0`; `_sound_dinfo`(`sound_dinfo[NSOUND]`) 다음 기호까지 4 B; `files.NeXT:66`) 한 행; `gen_config_headers.py --arch m68k` 로 `generated/sound.h`, `--check` 두 표.
2. 머리: `07_kernel/nextmach/nextdev/snd_var.h` = NeXTMach 그대로, 스테이징 `src/bsd/nextdev/snd_var.h`; `07_kernel/nextmach/nextdev/snd_msgs.h` = NeXTMach 에서 `#import <kern/mach_types.h>` → `<mach/mach_types.h>`, `#import <sys/message.h>` → `<mach/message.h>` 두 줄만(표시 plan 551, D104), 스테이징 `src/bsd/nextdev/snd_msgs.h`.
3. 07 `src/machdep/m68k/snd_rcv.c`(D103) = NeXTMach `nextdev/snd_rcv.c` 그대로(바이트 같음; 고칠 줄 없음). 꼴 L = 같은 글(`08_build/artifacts/m4p551/src/snd_rcv_L.c`).
4. `stage_m68k.py`: `M4FILES[551]` = 549 + `snd_rcv.c`, `M4HEADERS[551]` = 549 + (`nextdev/snd_var.h`, `nextdev/snd_msgs.h` → `src/bsd/nextdev/…`), `EXCEPTS[551]` = 549. 회귀: 보관 `m0p549-a1-stage` 대 `--plan 549` 재생성 = `generated/sound.h` 하나 더함; 재생성 대 `m0p551-a1-stage` = `snd_rcv.c`·머리 둘. M5 205 줄 회귀(`m0p549-a1-stage` 대 `m0p551-a1-stage`).
5. x86 입력 불변(`--plan 551 x86gate`).
6. 확인 run `m4p551-p1`(F = `@machdep/m68k/snd_rcv.c`, L): 종료 0·경고 0, 1/1, `OBJECT_MATCH`, F = L(canon·`obj_sig`), §550 N1 과 canon 같음; run `m4p551-e1` `-E` 토큰 F = L.
7. 최종 run `m4p551-a1`(F 만, REF = L): `gate.ok`; python 확인: 섹션 `__text` 24 하나, 외부 정의 `_snd_rcv_alloc_msg_frame` 하나, COMMON `_snd_rcv_msg` 8192·`_master_cpu` 4 뿐(이름이 원본에 있음), 원본에 없는 미정의 0, L1 `OBJECT_MATCH` 0x408503e, 입력 사슬(소스·머리 둘·`sound.h`·`dma.h`), i386 머리 0.
8. 기록: 근거 `m68k-snd_rcv.md`(먼저; `snd_rcv.c`·`snd_var.h` 는 NeXTMach → 07 → 스테이지 → run 의 SHA-256 이 같음을 적음, `dkbad` 선례), diff(`snd_msgs.h` 두 줄; 소스·`snd_var.h` 는 "차이 없음" 을 적음), 상태표(OBJECT_MATCH, 기존 22 행 이름 대조), PROVENANCE(`snd_rcv.c` nextmach "m68k copy, NeXTMach text unchanged"(함수 출처 `nextdev/snd_rcv.c:27`; 07 파일에 표시 주석을 넣지 않음), `snd_var.h` nextmach, `snd_msgs.h` nextmach 고친 사본, `generated/sound.h`), MODIFICATIONS, DECISIONS D122.
관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음(M5 포함), x86 입력 불변.

### 551.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §550.2 의 `obj_sig` 차이 설명이 모자람: STABS 수와 함께 N1 의 COMMON `_master_cpu` 도 `obj_sig` 의 기호 목록에 들어감 | `l2_prefix_diff.py:48–53`(`symbols` 에 STABS 아닌 기호 전부) 읽음 | ✅ 제 설명 누락. §550.2 고침 |
| 고치지 않은 사본(`snd_rcv.c`·`snd_var.h`)은 SHA 사슬과 "차이 없음" 을 적고, PROVENANCE·MODIFICATIONS 는 "m68k copy, NeXTMach text unchanged"(07 파일에 표시 주석을 넣으면 바이트 같음과 어긋남) | PROVENANCE 1101 행(`dkbad.c`)·`m68k-dkbad.md:9` 읽음 | ✅ 8 고침 |
| `snd_msgs.h` 는 include 두 줄만 고치면 됨(N1 이 두 별칭만으로 종료 0·stderr 빔) | §550.2 결과(이번 세션) | ✅ |
| 소비자·M5 영향 없음, `-DDEBUG` 없음 | 이번 세션 grep | ✅ |
| `NSOUND 1` 은 `hypothesis` 가 맞음(함수 존재는 양수만, 4 B 간격은 크기 증명이 아님) | — | ✅ 그대로 |
| F = L 은 같은 머리를 쓰므로 canon·`obj_sig` 같음을 요구해도 됨(STABS 문자열은 `obj_sig` 에 없고 수만 있음); N1 과는 canon 만 | `obj_sig` 정의 읽음 | ✅ 6 그대로 |

### 551.2 결과(2026-10-30)

- 1: `config_options-m68k.tsv` 12 → 13 행(`sound NSOUND sound.h 1 hypothesis`); `generated/sound.h`(`#define NSOUND 1`), `--check` 두 표 종료 0, 새 생성 파일은 `sound.h` 하나.
- 2–3: `07_kernel/nextmach/nextdev/snd_var.h`(NeXTMach 와 `cmp` 같음), `snd_msgs.h`(두 줄만 다름, diff 13 행), 07 `src/machdep/m68k/snd_rcv.c`(NeXTMach 와 `cmp` 같음); L 은 같은 글의 사본.
- 4: `stage_m68k.py` 664 → 668 행. 보관 `m0p549-a1-stage` 대 `--plan 549` 재생성: `generated/sound.h` 하나 더함; 재생성 대 `m0p551-a1-stage`(934 파일): `snd_rcv.c`·`snd_var.h`·`snd_msgs.h` 셋. M5 205 줄: run `m3p551-b549`·`m3p551-cc1` 각 205 명령 종료 0, 205 객체 바이트 같음, stderr 205 개 같음(비어 있지 않은 것 52), `compare`(`m3-m68k-p551-compare-20261030.json`, `-b549-`) `differ_unexpected`·`lost` 빔, 요약 같음.
- 5: x86 입력 불변(`m4-x86-inputs-p551-20261030.json` ok; `--plan 551 x86gate` 일곱 묶음 같음, v183 경로 0).
- 6: run `m4p551-p1`(`m4-m68k-probe-p551-p1-20261030.json`, `diag_gate` 참): F·L 경고 0, `OBJECT_MATCH`, 1/1, F = L(canon·`obj_sig`), F = §550 N1(canon; STABS 618 같음). run `m4p551-e1`: `-E` 토큰 9551 개 F = L.
- 7: run `m4p551-a1`(F 만, REF = L `b5282cd7…`; `m4-m68k-p551-final-20261030.json`): `gate` 모두 참, 객체 SHA-256 `2180992a…`. python 확인 `m4-m68k-p551-checks-20261030.json`(`ok` 참).
- 8: 근거 `06_reconstruction/evidence/m68k-snd_rcv.md`, diff `m68k-snd_rcv.diff`. 상태표 `m4-m68k-status-p551-20261030.json`: 23 객체(OBJECT_MATCH 19, CODE+BSS_INFERRED 4), 덮은 행 45/188, 33394/215874 B(15.47%; python 같음), 두 번 실행 같음, 기존 22 행은 이름 대조로 그대로. PROVENANCE 1142 → 1146 행, MODIFICATIONS 689 → 693 행, DECISIONS D122(125 → 126 행).
- 다음 후보: `snd_*` 나머지(이번 머리를 씀; `snd_device` 는 1997 판이 NeXTMach 와 함수 구성이 다름, §524), `fd_subr`(정확, 29/29), `en`(경계 부정확), 행 305·306 나머지, 행 276, `tty_pty` 꼬리.

## 552. M4-58 세부 계획 — `snd_reply.c`(행 248) 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): 남은 정확 경계 C 행 가운데 `fd_subr.c`(행 222, 6728 B)는 `fd_vars.h` 구조체 배치·PMON·`time_stamp` 머리 사슬·1997 본문(`disksort_first`)이 얽혀 크고, 여러 행에 걸친 `next/machdep.c`·`pmap.c`·`trap.c` 는 한 객체 가설이 먼저 필요합니다. `snd_reply.c` 는 §551 의 사운드 머리를 그대로 쓰고 x86 07 판(`07_kernel/src/driverkit/snd_reply.c`, plan 290, `audio_snd_reply_*` 계열)이 1997 메시지 정의를 담고 있어 비교가 쉽습니다.

확인한 사실(이번 세션; 원본 목록, 기호표, python):
- 행 `m68k-248`(정확) [0x4085056, 0x4085920), 2250 B, 21 함수(합 2250 B). 순서는 NeXTMach `nextdev/snd_reply.c`(521 행)와 같고, 이름 없는 0x408510e(104 B)는 정적 `snd_reply_with_tag` 자리; NeXTMach 에 없는 `_snd_reply_ret_formats`(0x40854bc, 146 B)가 `ret_volume` 과 `dsp_msg` 사이에 있음.
- 정적 자료(템플릿)는 `__data` 0x40b21d8(`_dspdriver`+0x46)부터: 머리 템플릿 24 B(0x40b21d8–0x40b21f0), ool 템플릿(0x40b21f0–), int 템플릿(0x40b21fc). `msg_send` 는 0x4048bba.
- 1997 바뀜(원본에서 읽음): `snd_reply_ret_samples` 는 인수 셋(셋째를 +0x20 에 씀, 메시지 크기 0x24 = 36); `snd_reply_ret_formats(port, rates, low, high, encodings, chans)` 는 `msg_id` 0x140(= `SND_MSG_KERN_BASE`(300)+20), 크기 0x30, int 템플릿의 `msg_type_number` 를 5 로(0x408550c–0x4085518) 하고 다섯 값을 담아 `msg_send(…, SEND_TIMEOUT(1), 0)`. 공개 함수 18 개의 인수 수는 07 `snd_msgs.h` 의 원형과 같고, 정적 `snd_reply_with_tag` 의 셋은 파일 안 선언과 같음(python; §552.1).
- x86 07 `driverkit/snd_msgs.h`(plan 290)는 NeXTMach 에 include 두 줄, `snd_ret_samples_t` 의 `timeStamp`, `snd_ret_stream_formats_t`, `SND_MSG_RET_STREAM_FORMATS` 를 더한 판(차이 20 줄)이고 함수 원형은 1990 그대로. §551 의 m68k 사본(`07_kernel/nextmach/nextdev/snd_msgs.h`)은 include 두 줄만 고친 1990 판이며 가드 `_SND_MSGS_` 를 씀.
- NeXTMach `snd_reply.c` 는 `<sound.h>`, `<kern/xpr.h>`, `<next/cpu.h>`(쓰는 이름 없음, python), `<nextdev/snd_var.h>`, `<nextdev/snd_dsp.h>`(NeXTMach 만; `<nextdev/snd_var.h>` 하나를 들임), `<next/spl.h>`(`splx` 만)를 들임.

방법(진단; 명세 `08_build/artifacts/m4p552/spec.json`, run `m4p552-p1`, 바탕 `m0p551-a1-stage`, `m4_id` `m68k-248`, 대응 `408510e=_snd_reply_with_tag`):
- A: NeXTMach `snd_reply.c` 에서 `<next/cpu.h>`→`<m68k/cpu.h>`(D110), `<next/spl.h>`→`<machine/spl.h>` 만 바꾸고, `nextdev/snd_dsp.h` 는 NeXTMach 사본을 `inc` 로. 1990 머리 그대로라 `ret_samples`·`ret_formats` 가 다를 것으로 예상.
- B: A 에서 맨 앞에 진단 머리 `<snd_msgs97.h>`(`inc`; §551 m68k 사본 + plan 290 의 1997 추가분 + 원형 `snd_reply_ret_samples(…, int timeStamp)`·`snd_reply_ret_formats(port_t, u_int ×5)`; 같은 가드라 스테이징 1990 판은 건너뜀)를 들이고, `ret_samples` 에 셋째 인수 `timeStamp`(int 템플릿은 그대로 개수 1), `ret_formats` 를 원본 바이트에서 씀(`ret_volume` 짜임, x86 07 판의 필드 이름, `Type.msg_type_number = 5`). 또 진단 머리 `<snd_var97.h>`(`inc`; 07 `snd_var.h` 에 `task` 앞 진단 낱말 둘을 넣어 `task` 를 +0x30 으로; 같은 가드 `_SND_VAR_`)를 먼저 들임 — DSP 응답 넷이 `_snd_var+0x30` 을 `task` 로 씀(§552.1). 이 낱말 둘의 자리·이름은 진단일 뿐이고, 1997 `snd_var_t` 배치는 따로 정함.
- 측정: `compare`(경고·i386 머리·L1, `__data` 포함), `m68k_funcbytes.py 4085056 4085920 408510e=_snd_reply_with_tag 40b21d8=_snd_reply_header_template 40b21f0=_snd_type_ool_template 40b21fc=_snd_type_int_template 40b2200=_snd_type_inline_template`(정적 자료 대응; §552.1), 다른 함수는 실기 `otool -tv` 명령 비교, 정의 기호 전체(외부·지역·COMMON·섹션), `__data` 템플릿 52 B 가 원본 [0x40b21d8, 0x40b220c) 와 같은지(지역 기호 목록은 따로 기록; `compare` 의 정의 기호는 외부만).
판정(미리 정함; 07 은 바꾸지 않음): B 가 21/21·`__data` 같음이면 07 꼴(1997 `snd_msgs.h` 를 m68k 사본에 넣을지, x86 07 판을 함께 쓸지 등)을 사용자께 여쭙고 구현 계획을 세움. 아니면 차이를 적고 꼴을 더 시험.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 552.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 놓친 1997 바뀜: DSP 응답 넷(`dsp_msg` 0x408560a, `dsp_err` 0x4085710, `dsp_regs` 0x4085816, `dsp_cond_true` 0x40858e0)이 `_snd_var+0x30`(0x40c6eb8)을 `object_copyin` 의 task 로 넘김; 1990 `snd_var_t` 의 `task` 는 +0x28 | 원본 네 주소와 0x4085602–0x4085610 읽음; 07 `snd_var.h:110–124` 읽음; python 0x40c6eb8−0x40c6e88 = 0x30 | ✅ 제 누락. B 에 진단 배치를 더하고, 1997 배치는 따로 정함 |
| `_snd_var` 다음 기호까지 68 B(1990 구조체 56 B) — 원본 전체에서 `_snd_var` 의 +0x0–0x40 칸 사용처 | python 으로 원본 전체의 0x40c6e88–0x40c6ecc 접근을 함수별로 셈(+0x20·+0x24·+0x28·+0x2c·+0x30·+0x34·+0x38·+0x3c·+0x40 을 `snd_server`·`snd_stream`·`dspq`·`snd_reply` 등이 씀) | ✅ 1997 배치 결정은 다음 계획 |
| `m68k_funcbytes.py` 에 정적 자료 대응(템플릿 넷)을 주지 않으면 원본 쪽이 `_dspdriver+…` 로 풀려 거짓 차이가 남 | 도구 98·113 행 대응 규칙(이번 세션 읽음, §525 이래) | ✅ 측정 명령 고침 |
| 템플릿 구간은 [0x40b21d8, 0x40b220c) 52 B(머리 24·ool 12·int 4·inline 12), 다음 기호 `__NXAudioSndoutDevice` 0x40b220c | python 으로 원본 52 B 읽음(`00000001 00000018 …`), 기호표 0x40b220c 확인 | ✅ |
| `ret_formats` 의 `andw #0x5f; orw #0x50` 은 `msg_type_number = 5`(비트필드, 플래그 보존); `ret_samples` 는 셋째 인수를 +0x20 에 쓰고 int 템플릿 개수는 1 그대로 | 원본 0x408550c–0x4085518, 0x4085324–0x4085332 읽음 | ✅ B 문구에 반영 |
| 인수 수 문장은 "공개 함수 18 개 + 정적 하나" 로 좁힐 것 | — | ✅ 고침 |
| 가드 기법(다른 이름의 사본이 같은 `_SND_MSGS_` 를 정의하면 스테이징 판 본문이 건너뜀)은 논리적으로 맞음; 실제 컴파일로 확인할 것 | `snd_msgs.h` 가드(이번 세션 읽음) | ⏭️ 컴파일로 확인 |
| `funcs` 의 `same_masked` 는 16 진 피연산자를 가려 오프셋·ID 를 증명하지 못함 | — | ✅ 함수 판정은 `m68k_funcbytes.py`(바이트·재배치)로 함 |

### 552.2 결과(2026-10-30)

- run `m4p552-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p552-20261030.json`): A·B 종료 0, i386 머리 0, 경고 각 1 줄(`snd_reply_recorded_data` 의 `kfree((caddr_t) msg, msgsize)` — 1997 원형은 `vm_offset_t`).
- A(1990 머리): `__text` 2098 B, 15/21. 다른 것: `ret_samples` 106/112, `ret_formats` 없음, DSP 넷은 바이트 같고 `_snd_var` 재배치 하나만 다름(+40 대 원본 +48).
- B(진단 1997 `snd_msgs97.h`·`snd_var97.h` + `ret_samples` 셋째 인수 + `ret_formats`): `__text` 2250 B, **21/21**(`m4-m68k-funcbytes-p552-B-20261030.json`, 템플릿 대응 포함), L1 `OBJECT_MATCH`(사유 없음; `__data` 52 B 가 원본 [0x40b21d8, 0x40b220c) 와 바이트 같음), 원본에 없는 미정의 0, 지역 기호는 템플릿 넷과 `_snd_reply_with_tag`, COMMON `_master_cpu` 4.
- 판정(미리 정한 대로): B 가 21/21·`__data` 같음이므로 07 꼴을 사용자께 여쭙니다. 남은 결정: 1997 `snd_var_t` 배치(진단은 `task` 앞 낱말 둘로 +0x30 만 맞춤; 원본 전체에서 +0x20–0x40 칸을 `snd_server`·`snd_stream`·`dspq` 등이 1990 과 다르게 씀, 크기 0x44), 1997 `snd_msgs.h`(타임스탬프·형식 응답·원형), `kfree` 경고.
- 사용자 결정(2026-10-30, AskUserQuestion): ① 1997 `snd_var_t` 는 "배치를 원본 바이트로 먼저 정함"(§543–544 `dma.h` 와 같은 절차; snd_reply 07 은 그 뒤) ② 1997 `snd_msgs.h` 는 "x86 07 판을 함께 씀": `07_kernel/src/driverkit/snd_msgs.h` 를 m68k 에도 스테이징하고 m68k 가 쓰는 원형 둘(`ret_samples` 셋째 인수, `ret_formats`)을 그 파일에 더함 — x86 입력이 바뀌므로 x86 재빌드·비교가 필요 ③ `kfree` 경고는 "1990 글 그대로 + known_warnings"(D121 과 같음).

## 553. M4-59 세부 계획 — 1997 m68k `snd_var_t` 배치 진단(07 변경 없음; 코딩 전, 2026-10-30)

사용자 결정(§552 끝): 1997 `snd_var_t` 배치를 원본 바이트로 먼저 정함.

확인한 사실(이번 세션; 원본 목록 전체에서 `_snd_var` [0x40c6e88, 0x40c6ecc) 접근을 python 으로 모음 — 기록 `09_validation/reconstruction/m4-m68k-sndvar-uses-p553-20261030.txt`(117 줄 = 절대 주소 117 번 출현, 명령 114 곳; 세 명령이 같은 주소를 두 번 담음); NeXTMach `nextdev/snd_server.c:135–186·214·228` 과 원본 `_snd_server_loop` 0x40859d6–0x4085c76 대조):
- `_snd_var` 는 `__common` 0x40c6e88, 다음 기호 `_board_rev` 까지 0x44 = 68 B(간격이며 `sizeof` 의 증명은 아님); 1990 `snd_var_t`(07 `snd_var.h:110–124`)는 56 B.
- 1997 뒷부분(원본에서 읽음): +0x20 = `port_set_allocate` 의 결과·받는 포트(1990 `portset` +0x18); +0x24/+0x28 = `snd_stream_init` 의 `queue_init`(1990 `new_thread_q` +0x1c); +0x2c = `port_allocate` 의 결과·`msg_local_port` 비교(1990 `dev_port` +0x24); +0x30 = `current_task()`(1990 `task` +0x28); +0x34 = `current_task()->map`(1990 `task_map`); +0x38 = `task->(+0x7c)`, `port_set_allocate`·`port_allocate`·`port_set_add` 의 첫 인수(1990 에 없음; 1990 은 `snd_var.task` 를 넘김); +0x3c = `task_self()`, `thread_wakeup(&+0x3c)`(1990 `task_port`); +0x40 = `object_copyout(task, ipc_port_copy_send(realhost.host_priv_self), MSG_TYPE_PORT, &+0x40)`(1990 `host_priv_self`).
- 1997 앞부분: `_snd_server_loop` 가 +0x4/+0x8 과 +0xc/+0x10 을 각각 `queue_init`; +0x0 은 DSP 쪽(행 243·244 이름 없는 함수들, `snd_link_init`, `snd_reply_dsp_regs` 등)과 0x4085e66 이 씀; +0x14 는 0x4085e66 이 셋; +0x18·+0x1c 를 직접 주소로 쓰는 명령은 0 건(구조체 포인터·변위로 쓰는 경우는 아직 안 봄). 1990 앞부분은 owner·negotiation 포트 여섯(+0x0–+0x14)과 `portset`(+0x18).
- 앞부분을 쓰는 함수: 이름 없는 0x4085e66(1894 B)·0x408667a(2624 B)·0x40870ba(440 B)(함수 목록에서 객체 행이 정해지지 않은 사운드 서버 쪽; 0x4085946 은 +0x20·+0x38 만 씀, §553.1), `_snd_link_init`(0x40842fe, 798 B, 행 246), 행 243·244 의 이름 없는 함수들.

방법(진단; 07 은 바꾸지 않음):
1. 위 함수들의 `_snd_var` 접근을 원본 목록에서 읽어 각 칸의 쓰임(형·크기·짝을 이루는 호출)을 적고, NeXTMach `snd_server.c`·`snd_stream.c`·`snd_link.c`·`snd_dspcmd.c`·`snd_dspdev.c` 의 같은 자리와 대조함. `_snd_var` 를 레지스터에 둔 뒤 변위로 쓰는 경우(`lea 0x40c6e88,aN` 뒤 `aN@(d)`)도 python 으로 찾아 넣음.
2. 1997 배치 후보를 표로 씀(0x0–0x40, 68 B). 이름이 바이트로 정해지지 않는 칸은 1990 이름을 이어 쓸지 사용자께 여쭐 목록에 둠.
3. 확인: 진단 머리(07 `snd_var.h` 에 후보 배치)로 §552 B 의 `snd_reply` 를 다시 컴파일해 21/21 이 그대로인지, 머리 단독 진단(§544 의 `2*OFF+2` 배열)으로 오프셋·크기가 후보와 같은지 봄.
판정(미리 정함): 모든 칸의 오프셋·크기가 원본 접근과 모순 없이 정해지고 `snd_reply` 가 21/21 이면, 07 `snd_var.h` 의 꼴과 이름을 사용자께 여쭙고 구현 계획(§552 의 `snd_msgs.h` 결정 포함)을 세웁니다. 정해지지 않는 칸이 남으면 그 범위와 근거를 적고 멈춥니다.
관문: 진단 run 은 명령 종료 0, i386 머리 0.

### 553.1 교차검토(codex `gpt-6.1-sol`) 판정, 원본 판독 결과와 계획 수정

codex 회신 전에 저도 원본 0x4085e66 의 앞부분 칸 쓰임을 읽었고(0x4085f12–0x4086594), 회신과 같은 결론이었습니다. 1997 배치 후보(이름은 작성 후보; python 으로 오프셋·크기 계산, 합 68 B):

| 오프셋 | 후보 | 원본 근거(주소) | 1990 |
|---|---|---|---|
| 0x00 | `port_name_t dspowner` | 0x4086248 저장(SET_DSPOWNER), 0x4085fa0 비교, 0x40870d2 지움, DSP 쪽 0x4080a14·0x4080bb2·0x4080fa6·0x4081004·0x40818ce, 0x4087246 `tstl a0@(-4)`(a0 = `&sndin_q`) | `dspowner` 0x00 |
| 0x04 | `queue_head_t` sndin owner 큐 | 0x4085a36–0x4085a42 `queue_init`, `snd_get_owner(&+4, port)` 0x4085f16, `__NXAudioSndinDevice` 와 짝 0x4086276–0x4086284 | `sndinowner` 0x04(4 B → 8 B 큐) |
| 0x0c | `queue_head_t` sndout owner 큐 | 0x4085a28–0x4085a34 `queue_init`, 0x4085f50·0x40862fa | `sndoutowner` 0x08 |
| 0x14 | `port_name_t dspnegotiation` | 0x4086250 저장, 0x40861f6 `snd_reply_illegal_msg` 첫 인수, 0x4086548–0x4086554 | `dspnegotiation` 0x0c |
| 0x18 | 8 B, 쓰임 없음 | 절대 주소·상수에서 이어지는 레지스터 추적 모두 0 건(codex 53 곳 추적; 제 간접 검색도 0) | (`sndinnegotiation`·`sndoutnegotiation` 0x10·0x14 가 밀린 자리일 수 있으나 증거 없음) |
| 0x20 | `port_set_name_t portset` | 0x4085a44–0x4085a4c `port_set_allocate(…, &+0x20)`, 0x4085ba8 받는 포트 | `portset` 0x18 |
| 0x24 | `queue_head_t new_thread_q` | `snd_stream_init` 0x4087276–0x4087282 | 0x1c |
| 0x2c | `port_t dev_port` | 0x4085b2c `port_allocate(…, &+0x2c)`, 0x4085be6 비교 | 0x24 |
| 0x30 | `task_t task` | 0x40859de–0x40859ea, `snd_reply` DSP 넷 | 0x28 |
| 0x34 | `vm_map_t task_map` | 0x4085a16–0x4085a20, 0x4080828 | 0x2c |
| 0x38 | IPC 공간 포인터(새 칸; 형 후보 `struct ipc_space *`) | 0x40859fa–0x4085a06 `= task->(+0x7c)`, `port_*` 첫 인수 0x4085a4a·0x4085a6a·0x4085ae8·0x4085b32·0x4085b48 | 없음 |
| 0x3c | `port_name_t task_port` | 0x4085a0a–0x4085a10 `task_self()`, 0x4085b66 `thread_wakeup(&+0x3c)` | 0x30 |
| 0x40 | `port_name_t host_priv_self` | 0x4085b08–0x4085b26 `object_copyout(…, ipc_port_copy_send(realhost.host_priv_self), 6, &+0x40)` | 0x34 |

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 위 배치(0x00–0x40)와 근거 주소 | 원본 0x40859d6–0x4085c76(이번 세션 전체 읽음), 0x4085e66 의 해당 자리(앞뒤 4 명령 포함 읽음), 0x408722c–0x4087246, `snd_server.c:142–186·214·228` 읽음 | ✅ 제 판독과 같음 |
| 간접 접근 0x4087246 `tstl a0@(-4)` 는 같음 갈래에서 `a0 = &sndin_q` 이므로 `snd_var+0` | 원본 0x408722c–0x408724a 읽음 | ✅ 제 변위 검색(`lea`→`aN@(d)`)으로는 못 잡던 자리 |
| +0x18–+0x1f 는 쓰임이 확인되지 않음; 이름을 억지로 붙이지 말 것 | 접근 기록 0 건, 간접 검색 0 건 | ✅ 07 이름은 사용자께 여쭘(1990 이름을 이을지, 예비 칸으로 둘지) |
| 다음 기호 간격 68 B 는 `sizeof` 의 독립 증명이 아님 | — | ✅ 사실 문장에 단서를 둠 |
| `snd_reply` 21/21 은 `task`(+0x30)만 시험; 배열 오프셋 진단은 후보 선언을 컴파일러로 확인할 뿐 원본 선언을 되찾지는 못함 | — | ✅ 판정 문장에 그대로 둠 |
| 0x4085946 은 앞부분을 쓰지 않음(+0x20·+0x38 만) | 원본 0x4085946–0x40859d6 의 `_snd_var` 접근 3 곳 읽음 | ✅ 제 목록 오기. 고침 |
| 객체 행이 정해지지 않은 함수를 "행 249–253 쪽" 이라 쓴 것은 확정이 아님 | — | ✅ 고침 |
| `scratchpad/sndvar_uses.txt` 는 저장소에 없음 | — | ✅ `09_validation` 기록으로 옮김 |

### 553.2 결과(2026-10-30)

- run `m4p553-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p553-20261030.json`; 진단 머리 `08_build/artifacts/m4p553/inc/snd_var97c.h` = 07 `snd_var.h` 에 §553.1 후보 배치, 진단 이름 `sndin_owners`·`sndout_owners`·`diag_x18`·`diag_x1c`·`diag_space`): 두 명령 종료 0, i386 머리 0.
- B2(§552 B 의 `snd_var97.h` 를 후보 머리로 바꾼 꼴): 21/21(`m4-m68k-funcbytes-p553-B2-20261030.json`), L1 `OBJECT_MATCH`, §552 B 와 canon 같음, 경고는 같은 `kfree` 한 줄.
- H(후보 머리만, `2 * OFF + 2` 배열): `sizeof (struct snd_var)` 68, 14 칸 오프셋이 모두 후보와 같음(`m4-m68k-p553-layout-20261030.json`, `ok` 참).
- 판정(미리 정한 대로): 모든 칸의 오프셋·크기가 원본 접근과 모순 없이 정해짐(+0x18–+0x1f 는 쓰임이 없는 8 B). 07 `snd_var.h` 의 꼴과 이름을 사용자께 여쭙니다. 이 시험은 배치의 호환성을 보이며 원본 선언(이름·형) 자체의 증명은 아닙니다.
- 사용자 결정(2026-10-30, AskUserQuestion): 07 `snd_var.h` 의 이름은 "뜻을 담은 이름 + 1990 이름 이음": `queue_head_t sndin_owners`(+0x04)·`sndout_owners`(+0x0c)(작성, D024), +0x18·+0x1c 는 1990 `sndinnegotiation`·`sndoutnegotiation` 그대로(1997 원본에서 쓰임 없음을 주석에), +0x38 은 `struct ipc_space *task_space`(작성).

## 554. M4-60 D123 구현 계획 — 07 `src/machdep/m68k/snd_reply.c`, 1997 `snd_var.h`, x86 07 `snd_msgs.h` 원형 + x86 전체 재빌드(코딩 전, 2026-10-30)

확인한 사실(이번 세션):
- 진단 `snd_msgs97.h`(§552 B·§553 B2 가 쓴 것)와 x86 07 `07_kernel/src/driverkit/snd_msgs.h` 는 주석을 뺀 토큰으로 `snd_reply_ret_samples` 원형의 `int timeStamp` 와 `snd_reply_ret_formats` 원형만 다름(python 토큰 비교 1794 대 1769).
- x86 에서 `driverkit/snd_msgs.h` 를 들이는 소스는 `07_kernel/src/driverkit/snd_reply.c`(`#import "snd_msgs.h"`) 하나이고(grep), 이 파일은 `snd_reply_ret_samples`·`snd_reply_ret_formats` 를 부르지도 정의하지도 않음(정의는 `audio_snd_reply_*`). `libDriver/Kernel/*.m` 둘은 다른 머리 `<bsd/dev/snd_msgs.h>` 를 들임.
- x86 전체 재빌드 절차(§480.3·§494): L2_FORMS·L2_EXPECT 를 두고 일곱 묶음(G1:g1a … G6:g6a)마다 `l2_rebuild.py prepare G RID` → `kr_run.py prepare/launch/wait/collect` → `l2_rebuild.py check G RID 09_validation/reconstruction/s6-l1-G-RID.json`; `l2_prefix_diff.py OLD NEW RECORD PLAN`; `l2_link.py prepare LINK NEW` → kr_run → `l2_compare.py` → `cmp`; `stage_m68k.py` 의 `X86[N]`. 마지막 접두어는 s6ll(§494); 새 접두어 `s6lm` 은 REGISTRY·tools 에 없음.
- `stage_m68k.py` 의 `M4HEADERS` 뿌리는 `07_kernel/nextmach`·`07_kernel/nextdev` 만 받음(487 행 assert).

1. 07 `nextmach/nextdev/snd_var.h`: `struct snd_var` 를 §553.1 배치로(이름은 §553 결정: `sndin_owners`·`sndout_owners`·`sndinnegotiation`·`sndoutnegotiation`(1997 쓰임 없음을 주석에)·`task_space`), 표시 plan 554, 머리 주석에 근거.
2. x86 07 `driverkit/snd_msgs.h`: `snd_reply_ret_samples` 원형에 `int timeStamp` 와 `snd_reply_ret_formats` 원형을 더함(표시 plan 554). 진단 `snd_msgs97.h` 와 주석 뺀 토큰이 같음을 확인.
3. x86 전체 재빌드 `s6lm` 과 check 관문(일곱 묶음 problems 0, 명령 모두 종료 0, 요약 줄 s6ll 과 같음). prefixdiff s6ll↔s6lm(plan 554): 스테이징 차이는 `driverkit/snd_msgs.h` 를 담은 묶음의 그 파일 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-snd_reply']`(그때 비 STABS 같음). 링크 `s6p554-ln1` → `l2_compare.py` → `cmp` 로 원본과 같음. `stage_m68k.py` 에 `X86[554] = 's6lm'`.
4. m68k 머리: `stage_m68k.py` 의 `M4HEADERS` 뿌리에 `07_kernel/src` 를 더함(plan 554). `M4HEADERS[554]` = 551 에서 (`nextdev/snd_msgs.h` 사본) 항목을 (`driverkit/snd_msgs.h` → `src/bsd/nextdev/snd_msgs.h`, 뿌리 `07_kernel/src`)로 바꾸고 (`nextdev/snd_dsp.h`, NeXTMach 그대로 사본 `07_kernel/nextmach/nextdev/snd_dsp.h`)를 더함. §551 의 m68k 사본 `07_kernel/nextmach/nextdev/snd_msgs.h` 는 지우지 않고 plan 551 입력으로 그대로 둠(`--plan 551` 재생성 가능); plan 554 부터 스테이징하지 않음을 PROVENANCE 그 행(그 자리 고침)·근거 문서에 적음(§554.1). 도구의 뿌리 assert(487 행)도 함께 고침.
5. 07 `src/machdep/m68k/snd_reply.c`(D103) = NeXTMach `nextdev/snd_reply.c` + `<m68k/cpu.h>`(D110)·`<machine/spl.h>` + `snd_reply_ret_samples` 셋째 인수 + 새 `snd_reply_ret_formats`(표시 plan 554; §552 B 의 글). `M4FILES[554]` = 551 + `snd_reply.c`, `EXCEPTS[554]` = 551 에 x86 변화 없음 표시.
6. 회귀: `--plan 551` 재생성 = 보관 `m0p551-a1-stage`(x86 바탕이 s6ll 이므로 그대로); 보관 551 대 `m0p554-a1-stage` 의 파일 차이는 x86 바탕(s6lm g1a)에서 온 `src/driverkit/snd_msgs.h`(SHA)와 `src/bsd/nextdev/snd_msgs.h`(출처·SHA)·`src/bsd/nextdev/snd_var.h`(SHA)·`src/bsd/nextdev/snd_dsp.h`·`src/machdep/m68k/snd_reply.c` 뿐(python assert). M5 205 줄 회귀(§551 과 같은 절차). x86 입력: `m4_x86_inputs.py s6lm`(forms·명령·소스 목록; 내용 바이트는 보지 않음)과 `--plan 554 x86gate`(s6lm 기준 일곱 묶음 같음); 내용 바뀜은 3 의 prefixdiff 와 x86 `snd_msgs.h` diff·SHA 로 기록. `snd_rcv` 재확인: `@machdep/m68k/snd_rcv.c` 를 새 스테이지에서 컴파일해 §551 최종 객체와 canon 같음·L1 OBJECT_MATCH.
7. 확인 run `m4p554-p1`(F = `@machdep/m68k/snd_reply.c`, L = §552 B 글에서 진단 include 를 뺀 꼴): 21/21, `OBJECT_MATCH`, F = L, F 와 §553 B2 canon 같음, stderr 는 `kfree` 경고 2 줄(함수 줄 + 경고 줄; 경로·줄 번호 뺌)이 §553 B2 와 같음. run `m4p554-e1` `-E` 토큰 F = L.
8. 최종 run `m4p554-a1`(F 만, REF = L, `known_warnings["snd_reply"]` = 확인 run F 의 stderr 줄 목록 그대로 — 경로·줄 번호·순서까지 정확히 비교됨): `gate.ok`; python 확인: `__text` 2250·`__data` 52(원본과 같음)·`__cstring`(있으면 원본과), 외부 정의 = 원본 이름 20 개, 지역 = 템플릿 넷·`_snd_reply_with_tag`, COMMON 이름이 원본에 있음, 원본에 없는 미정의 0, 입력 사슬(소스·머리 넷), i386 머리 0.
9. 기록: 근거 `m68k-snd_reply.md`(먼저), diff(NeXTMach 대비 `snd_reply.c`·`snd_var.h`, x86 `snd_msgs.h` 의 plan 554 줄), 상태표(OBJECT_MATCH), PROVENANCE(`snd_reply.c`·`snd_dsp.h` 새 행, `snd_var.h`·x86 `snd_msgs.h`·m68k `snd_msgs.h`(plan 554 부터 스테이징 안 함) 행 그 자리 고침), MODIFICATIONS, DECISIONS D123, `snd_rcv` 근거 문서에 머리 바뀜 절 덧붙임.
관문: 명령 종료 0, F·L stderr 는 정한 꼴뿐, i386 머리 0, x86 링크 `cmp` 같음, 회귀 같음(M5·`snd_rcv` 포함).

### 554.1 교차검토(codex; `gpt-6.1-sol` 은 "at capacity" 로 실패해 `gpt-6-luna`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| x86 에서 그 머리를 들이는 것은 forms 207 행(`x86-snd_reply`, 파일 208 행) 하나; 매니페스트에서 `src/driverkit/snd_msgs.h` 는 g1a 에만, g5a 는 다른 `src/bsd/dev/snd_msgs.h` | forms grep(208 행), python 으로 s6ll 일곱 매니페스트 검색 | ✅ |
| 원형 더함은 코드는 그대로일 것이나 `-g` 라 STABS 가 바뀔 수 있어 바이트 같음은 미리 단정 못 함 → prefixdiff 에서 바뀐 객체가 `x86-snd_reply` 뿐이고 비 STABS·canon 같음을 요구 | 계획 3 의 기대가 이미 그 꼴 | ✅ 그대로 |
| §551 사본을 지우면 `M4HEADERS[551]`(`stage_m68k.py:106–107`) 재생성이 깨지고 PROVENANCE 1145 행·MODIFICATIONS 692 행이 맞지 않게 됨 → 남겨 두고 plan 554 부터 쓰지 않음을 적는 것이 안전 | `stage_m68k.py:104–107` 읽음 | ✅ 4·9 고침(지우지 않음) |
| m68k 바탕은 x86 g1a 스테이지를 복사하므로 `X86[554] = 's6lm'` 이면 `src/driverkit/snd_msgs.h` 가 새 내용으로 따라옴 → 예상 차이에 넣을 것; 뿌리 assert(487 행)도 고칠 것 | `stage_m68k.py:470–495` 읽음(이번 세션) | ✅ 6 고침 |
| `known_warnings` 는 `splitlines()` 정확 비교 → stderr 줄 전체를 그대로 | `m4_m68k_probe.py:296`(§549.1 에서 읽음) | ✅ 7·8 고침 |
| `m4_x86_inputs.py` 는 forms·명령·소스 목록만 보고 내용 바이트는 보지 않음 → 내용 바뀜은 prefixdiff 와 diff·SHA 로 | `m4_x86_inputs.py:20–40` 읽음 | ✅ 6 고침 |
| `snd_dsp.h` 는 `<nextdev/snd_var.h>` 를 들이므로 실제 컴파일 의존 목록으로 경로를 확인 | NeXTMach `snd_dsp.h:28`(이번 세션 grep) | ✅ 8 의 입력 사슬에 의존 목록 확인을 넣음 |

### 554.2 결과(1–8, 2026-10-30)

- 1·2·5: 07 `snd_var.h`(171 → 177 행, SHA `2e082af9…`), x86 07 `driverkit/snd_msgs.h`(원형 둘, 619 행, SHA `ea13002d…`; 진단 `snd_msgs97.h` 와 주석 뺀 토큰 같음), 07 `src/machdep/m68k/snd_reply.c`(564 행, SHA `62ffc5b3…`; L 과 토큰 2095 개 같음). diff `06_reconstruction/evidence/m68k-snd_reply.diff`(89 행)·`m68k-snd_var_h.diff`(36 행)·`m68k-snd_msgs_h.diff`(26 행).
- 3: x86 `s6lm` 일곱 묶음 problems 0(`s6-l1-G*-s6lm-*.json`); prefixdiff(`s6-l2-prefixdiff-s6ll-s6lm-20261030.json`): 스테이징 차이 g1a 의 `src/driverkit/snd_msgs.h` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` `[]`(15 객체가 run 경로만 다르고 비 STABS 같음; `x86-snd_reply` 는 바이트 같음); 링크 `s6p554-ln1` 이 `03_original/x86/binaries/mach_kernel` 과 `cmp` 같음(SHA `33469393…`, 이번 세션 다시 `cmp`).
- 4·6: `m0p554-a1-stage` 936 파일; 보관 551 대비 차이는 계획대로 다섯 경로뿐; `--plan 551` 재생성은 `snd_var.h`(그 자리 고침) 만 다름. M5 205 줄: run `m3p554-b551`·`m3p554-cc1` 객체 205 개 바이트 같음, stderr 205 개 같음(비어 있지 않은 것 52); `compare`(`m3-m68k-p554-compare-20261030.json`, `-b551-`) `differ_unexpected`·`lost` 빔, 요약 같음, 새 경로는 `snd_dsp.h`·`driverkit/snd_msgs.h`·`snd_reply.c` 뿐. x86 입력(`m4-x86-inputs-p554-20261030.json`) ok, `x86gate` 일곱 같음.
- 6 `snd_rcv` 재확인(run `m4p554-p1` R): `OBJECT_MATCH`, 1/1, §551 최종 객체와 canon·머리·섹션·비 STABS 기호 같음. STABS 618 → 621: 숫자를 가린 비교에서 다른 것은 `snd_ret_samples_t` 의 `timeStamp`, 새 `snd_ret_stream_formats_t`(셋), 1997 `snd_var` 배치뿐(`m4-m68k-p554-checks-20261030.json` 의 `snd_rcv_recheck`).
- 7: run `m4p554-p1`(`m4-m68k-probe-p554-p1-20261030.json`): F·L 종료 0, `OBJECT_MATCH`·`candidate`, 21/21, F = L(canon·`obj_sig`), F = §553 B2(canon), stderr 는 `kfree` 경고 2 줄로 B2 와 경로·줄 번호를 뺀 내용이 같음. run `m4p554-e1`: `-E` 토큰 12355 개 F = L, i386 머리 0.
- 8: run `m4p554-a1`(명세 `08_build/artifacts/m4p554/spec.json`, REF = L `4793d03a…`, `known_warnings["snd_reply"]` = p1 F stderr 2 줄; 기록 `m4-m68k-p554-final-20261030.json`): `gate.ok`. python 확인(`m4-m68k-p554-checks-20261030.json`, `ok` 참): `__text` 2250·`__data` 52(원본 [0x40b21d8, 0x40b220c) 와 바이트 같음), `__cstring` 없음, 외부 정의 20 = 원본 이름, 지역 = 템플릿 넷·`_snd_reply_with_tag`(원본 기호표에 없는 정적; funcbytes 대응으로 맞춤), COMMON `_master_cpu`(원본에 있음), 원본에 없는 미정의 0, L1 `OBJECT_MATCH` 0x4085056 사유 없음, 21/21(`m4-m68k-funcbytes-p554-a1-20261030.json`), stderr = `known_warnings`, 의존 111 파일·i386 0, 07 = 스테이지 = run SHA 사슬(`snd_reply.c`·`snd_var.h`·`snd_msgs.h`·`snd_dsp.h`).
- 9(일부): 근거 `06_reconstruction/evidence/m68k-snd_reply.md`(새), `m68k-snd_rcv.md` 에 plan 554 절 덧붙임.
- 제 계획 누락: 상태표 도구 `m4_m68k_status.py` 의 plan 506 검사(받아들인 기록마다 바탕 스테이지 매니페스트의 `m4_headers` 07 출처 해시가 지금과 같은지, 86–89 행)가 `snd_var.h` 를 그 자리 고친 탓에 §551 기록(`snd_rcv`)에서 멈춤(`AssertionError: ('header changed', '07_kernel/nextmach/nextdev/snd_var.h')`; 출력은 scratchpad, 저장소 기록은 쓰지 않음). python 으로 확인: `m0p551-a1-stage` 의 18 머리 중 `src/bsd/nextdev/snd_var.h` 하나만 다르고, `m0p547`·`m0p549`·`m0p554` 바탕은 모두 같음. 계획 6 은 canon 재확인만 적었고 이 검사를 넣지 않았습니다.

### 554.3 보완 계획 — `snd_rcv` 를 새 머리로 다시 받아들임(코딩 전, 2026-10-30)

검사는 느슨하게 하지 않습니다(plan 506 의 뜻: 받아들인 객체는 지금의 07 머리로 만들어진 것이어야 함). 대신 `snd_rcv` 를 plan 554 머리로 다시 만들어 받아들입니다.
1. a1 명세를 `08_build/artifacts/m4p554/spec-a1.json` 으로 그대로 복사해 둠(a1 기록의 `spec_sha256` 과 같음을 python 으로 확인; a1 기록은 받아들인 기록 목록에 넣지 않고 이력으로 남김).
2. `08_build/artifacts/m4p554/spec.json` 을 두 객체로 다시 씀: `snd_reply`(F, REF = p1 L, `known_warnings` 그대로)와 `snd_rcv`(`m4_id` `m68k-247`, F = `@machdep/m68k/snd_rcv.c`, REF = run `m4p554-p1` 의 R 객체 `Q554__snd_rcv_R.o` 와 그 SHA; 경고 없음). 바탕은 그대로 `m0p554-a1-stage`.
3. 최종 run `m4p554-a2`(새 ID; REGISTRY 0 건 확인) → `compare` 기록 `m4-m68k-p554-final-a2-20261030.json`: `gate.ok`, 두 객체 `OBJECT_MATCH`·`candidate`, `snd_reply` 객체가 a1 과 canon·`obj_sig` 같음, `snd_rcv` 가 §551 최종 객체와 canon 같음. funcbytes 둘(`snd_reply` 템플릿 대응 포함 21/21, `snd_rcv` 1/1). python 확인을 `m4-m68k-p554-checks-20261030.json` 에 같은 꼴로 다시 씀(a2 객체 기준, `snd_rcv` 항목 더함: 섹션 `__text` 24, 정의 `_snd_rcv_alloc_msg_frame`·COMMON `_snd_rcv_msg` 8192·`_master_cpu` 4, 원본에 없는 미정의 0, 입력 사슬 `snd_rcv.c`·`snd_var.h`·`snd_msgs.h`·`sound.h`·`dma.h`).
4. `m4_m68k_status.py` 의 `ACCEPTED`: §551 줄을 plan 554 a2 기록 줄로 바꿈(주석에 plan 554 가 §551 을 대신함과 그 까닭). 도구의 검사 코드는 바꾸지 않음. 상태표 기대: 24 객체(OBJECT_MATCH 20, CODE+BSS_INFERRED 4), 행 46/188(`m68k-248` 더함); 바이트·백분율은 python 출력 그대로 적음.
5. 기록: 근거 문서 둘(최종 run 이름 a2 로), `m68k-snd_rcv.md` 의 plan 554 절에 다시 받아들임을 적음. 그다음 계획 9 의 나머지(PROVENANCE·MODIFICATIONS·DECISIONS D123·상태표).
관문: a2 명령 종료 0, i386 머리 0, 위 같음 조건 모두, 상태표 도구가 멈추지 않음.

### 554.3.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| status 는 기록의 객체마다 돌고, 컴파일 줄 유일성은 객체별 소스·출력 이름으로 봄(`-M` 줄은 `-c` 가 없어 빠짐) | `m4_m68k_status.py:90–94` 읽음 | ✅ |
| `known_warnings` 는 객체 이름의 부분집합이면 되고 `refs` 는 모든 객체를 담아야 함(`[경로, SHA]`); REF 가 따로 만든 사본이어야 한다는 검사는 없음 | `m4_m68k_probe.py:63–67`·`365–366`·`384–392` 읽음 | ✅ |
| L1 은 `08_build/artifacts/m4p554/<run>/l1-<name>-<V>.json` 에 객체마다 쓰이고 status 가 같은 경로를 읽음; 근거 문서 둘이 있음 | `m4_m68k_probe.py:324`·`343`, `m4_m68k_status.py:106`·`119–120` 읽음; `ls` | ✅ |
| §551 줄을 남기면 이름·행 `m68k-247`·범위가 겹치므로 바꿔야 함; 예상 집계 24 객체 · 46/188 · 35644 B · 16.51 % | `m4_m68k_status.py:121–124` 읽음; 수치는 받지 않음 | ⚖️ 바꿈은 채택. 수치는 도구 출력으로만 적음 |
| 다른 받아들인 기록은 이번 머리 바뀜으로 멈추지 않음 | python: ACCEPTED 21 기록의 바탕 매니페스트 `m4_headers` 해시를 모두 다시 셈 → 551 의 `src/bsd/nextdev/snd_var.h` 하나만 다름 | ✅ |
| `snd_rcv` 객체에도 `x86_rel` 이 필수; 두 객체 명세로 stage·cmd 를 새로 만들어야 함 | `m4_m68k_probe.py:69` 읽음 | ✅ 3 에 적음(`x86_rel` 은 §551 과 같은 `machdep/i386/dkbad.c`) |
| a1 을 다시 만들려면 명세만이 아니라 `probe.cmd`·`probe.cmd.opts.json`(compare 가 명세와 같은 디렉터리에서 읽음)도 보관해야 하고, a1 확인 기록도 덮어쓰지 말 것 | `m4_m68k_probe.py:235`(cmd 가 `out + '.opts.json'` 을 씀)·`378`(compare 가 `dirname(spec)/probe.cmd.opts.json` 을 읽음) 읽음 | ✅ 1·3 고침 |
| `snd_rcv` REF 를 §551 최종 객체로 두면 `obj_sig`(STABS 수 포함) 가 달라 실패하므로 p1 R 이 맞음 | `l2_prefix_diff.py:48–53` 읽음, STABS 618 대 621(이번 세션 python) | ✅ |

계획 고침: 1 → a1 의 `spec.json`·`probe.cmd`·`probe.cmd.opts.json` 을 `08_build/artifacts/m4p554/a1/` 로 복사(a1 기록의 `spec_sha256` 과 같음을 확인; 그 디렉터리에서 compare 를 다시 돌릴 수 있음). 3 → 두 객체 명세로 `stage`(`08_build/runs/tools/m4p554a2-stage`)·`cmd` 를 새로 만들고, a1 확인 기록 `m4-m68k-p554-checks-20261030.json` 은 그대로 두고 a2 확인은 `m4-m68k-p554-checks-a2-20261030.json` 에 씀.

### 554.4 결과(554.3 과 9, 2026-10-30)

- 1: a1 의 `spec.json`·`probe.cmd`·`probe.cmd.opts.json` 을 `08_build/artifacts/m4p554/a1/` 로 복사(명세 SHA 가 a1 기록의 `spec_sha256` 과 같음, 나머지 둘도 같음; python assert).
- 2·3: 두 객체 명세(`snd_rcv` REF = p1 R `8a29e728…`), 스테이지 `m4p554a2-stage` 936 파일, 명령 넷(옵션 차이 없음). run `m4p554-a2`(기록 `m4-m68k-p554-final-a2-20261030.json`): `gate.ok`, 두 객체 `OBJECT_MATCH`·`candidate`·사유 없음, 원본에 없는 미정의 0; funcbytes `snd_reply` 21/21(템플릿 대응)·`snd_rcv` 1/1. 확인 `m4-m68k-p554-checks-a2-20261030.json`(`ok` 참): `snd_reply` 는 a1 객체와 바이트 같음(a1 확인 항목 모두 다시 참); `snd_rcv` 는 `__text` 24 하나, `_snd_rcv_alloc_msg_frame`, COMMON `_master_cpu` 4·`_snd_rcv_msg` 8192(원본에 있음), 입력 사슬 다섯(`snd_rcv.c`·`snd_var.h`·`snd_msgs.h`·`sound.h`·`dma.h`) 07 = 스테이지 = run, 의존 109 파일·i386 0, §551 최종 객체와 canon·비 STABS 같음(STABS 618 대 621), 객체는 p1 R 과 같음.
- 4: `m4_m68k_status.py` 의 `ACCEPTED` 에서 §551 줄을 a2 기록(SHA `864e8e1a…`)으로 바꿈(주석 둘). 상태표 `06_reconstruction/m68k-m4-status.tsv`(25 → 26 행)·기록 `m4-m68k-status-p554-20261030.json`: 24 객체(OBJECT_MATCH 20, CODE+BSS_INFERRED 4), 덮은 행 46/188, 35644/215874 B(16.51%; python 같음, §551 보다 2250 B 더함). 두 번 실행 같음. §551 표와 이름 대조: 더한 것 `snd_reply`, 다른 것은 `snd_rcv` 의 plan·record·obj_sha256 뿐, 나머지 22 그대로.
- 9: 근거 `m68k-snd_reply.md`(29 행)·`m68k-snd_rcv.md`(plan 554 절), diff 셋, PROVENANCE 1146 → 1148 행(새 `snd_reply.c`·`snd_dsp.h`; 그 자리 고침 x86 `driverkit/snd_msgs.h`·`snd_rcv.c`·`snd_var.h`·m68k `snd_msgs.h`; 한 줄 한 경로, 7 칸), MODIFICATIONS 693 → 698 행, DECISIONS D123(126 → 127 행), "현재 상태와 다음 일" 고침.

## 555. M4-61 세부 계획 — m68k `snd_device.c`(행 242) 첫 작성본 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): 받아들이지 않은 정확 경계 행 55 개 가운데 참고 글(NeXTMach)과 이름이 모두 맞고(13/13) §551–554 의 사운드 머리를 그대로 쓰는 단위입니다. 이보다 작은 정확 행은 FPSP(사용자 결정 대기), 이름 없는 행, x86 이름 행, 그리고 여러 행에 걸친 `next/pmap.c`·`next/trap.c`·`next/machdep.c`·`next/locore.s` 의 조각(한 객체 가설이 먼저 필요, §552 와 같은 이유)과 x86 과 함께 쓰는 `bsd/tty_pty.c` 꼬리입니다.

확인한 사실(이번 세션; 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt` 0x407ff14–0x4080556(462 줄), 기호표, 원본 `__data`·`__cstring`, python):
- 행 `m68k-242`(정확) [0x407ff14, 0x4080556), 1602 B, 15 함수(합 1602 B, 이어짐): `snd_device_init` 172, `snd_device_set_parms` 120, `snd_device_get_parms` 42, `snd_device_set_volume` 64, `snd_device_get_volume` 42, 이름 없는 0x40800cc 674(호출 자리와 짜임으로 NeXTMach 정적 `snd_vol_set`), `snd_device_vol_set` 26, 이름 없는 0x4080388 98(정적 `snd_vol_save`), `snd_device_vol_save` 26, `snd_dev_intr` 106(1997 은 외부 기호; NeXTMach 는 정적), `snd_device_probe` 28, `snd_device_attach` 132, `snd_device_def_dmasize` 26, `snd_device_def_high_water` 22, `snd_device_def_low_water` 24.
- 참고 글: NeXTMach mk-108.1 `nextdev/snd_device.c`(929 행) 하나(`01_resources`·`07_kernel` 에서 같은 이름 파일 검색). NeXTMach 의 `snd_device_reset`·`snd_device_set_ramp`·`snd_dma_intr`·`snd_ovr`·`snd_device_start`·`snd_start`·`snd_shutdown`·`mon_send_nodma`·`snd_ramp` 는 원본 기호표에 없고 범위 안에도 없음 — 1997 판의 이 범위에는 NeXTMach 의 DMA 구현이 없음(그 기능이 어디로 갔는지는 이 사실로 정해지지 않음; 원본에 `__NXAudioSndinDevice`·`_snd_audio_not_loaded` 같은 이름이 있음).
- 자료: `__data` [0x40b20c0, 0x40b20fa) 58 B = `vol_r`·`vol_l`(둘 다 0xffffffff)·`sounddriver`(`struct bus_driver` 50 B, 스테이지 `src/bsd/dev/busvar.h:121–134`: `{snd_device_probe, 0, snd_device_attach, 0, 0, snd_dev_intr, 0, 0, "sound", sound_dinfo}` 와 0 인 `br_cname`·`br_cinfo`·`br_flags`, NeXTMach 와 같은 꼴); 다음 외부 기호 `_dspdriver` 는 0x40b2192(§555.1 고침). `__cstring` 0x40abb34 `sound`, 0x40abb3a `SoundDSP: snd_dev_intr called!\n`(NUL 포함 6·32 B). `__bss` [0x40b507c, 0x40b5090) 20 B 의 이름 없는 정적 다섯(쓰임으로 NeXTMach 의 `mon`, `ni_spkren`, `ni_lowpass`, `ni_vol_r`, `ni_vol_l` 순; bss 자리는 reference-inferred 후보, D113). COMMON `_gpflags`(0x40c36f4), `_ll_snd_var`(0x40c6a3c, 다음 기호 `_sound_dinfo` 까지 700 B; 코드가 +0x2b1 바이트를 `ll_snd_var.gpflags` 로 씀), `_sound_dinfo`(4 B). 새 이름 `_mon_rev`(0x40c36f0, COMMON; 0x40950c4 에서 바이트로 쓰고 0x4068eee·0x4080158 에서 바이트로 읽음; 참고 트리 어디에도 없음).
- 부르는 것: `_nvram_check`·`_nvram_set`·`_mon_send`·`_mon_csr_and`·`_mon_csr_or`·`_delay`(`DELAY(n)` = `delay(n)`, 스테이지 `src/bsd/m68k/machparam.h:52`)·`_printf`·`_install_scanned_intr`(0x835, SDK `dev/m68k/autoconf.h:28` 선언)·`_callout_dispatch`(0x4093e80; `_softint_sched` 0x4093e66 은 따로 있으나 부르지 않음, §549 `np.c` 와 같음); `_slot_id`, `_page_size`.
- 함수별 1997 동작(NeXTMach 대비):
  - `snd_device_init(direction)`: NeXTMach 의 첫 부분만(`direction == SND_DIR_PLAY && vol_r == -1` 이면 `nvram_check` → `vol_r`·`vol_l`·`ni_vol_r = ni_vol_l = -1`·`gpflags` 와 `ni_spkren`·`ni_lowpass` → `snd_vol_set()`); 큐 초기화·`ramp_buf` 없음.
  - `set_parms`: ZEROFILL·`mon_send(MON_SNDOUT_CTRL…)` 없음; SPEAKER(반대 뜻)·LOWPASS 와 `ll_snd_var.gpflags != gpflags` 이면 `snd_vol_set(); snd_vol_save();`. `get_parms`: LOWPASS·SPEAKER 만(ZEROFILL 없음). `set_volume`·`get_volume`: NeXTMach 와 같음(`VOLUME_MAX` 0x2b).
  - `snd_vol_set`(정적): NeXTMach 의 앞부분 다음, 볼륨이 바뀐 경우 `vol_r &= 0x3f; vol_l &= 0x3f;` 뒤에 새 갈래: `mon_rev`(바이트)가 0 이 아니면 `mon_send(MON_GP_OUT, ll_snd_var.gpflags << 24); delay(200);` 그리고 `vol_r == vol_l` 이면 `mon_send(0xc2, (vol_r << 24) | 0xc0000000)`, 아니면 `mon_send(0xc2, (vol_r << 24) | 0x80000000); delay(200); mon_send(0xc2, (vol_l << 24) | 0x40000000)`, 그다음 `delay(200); ni_vol_r = vol_r; ni_vol_l = vol_l;` 뒤 같은 `while` 검사로 합류(return 아님); 0 이면 NeXTMach 처럼 `flags = ll_snd_var.gpflags << 24`(같은 경로와 새 갈래는 `flags` 를 정하지 않음, NeXTMach 와 같음). 이어지는 `while` 고리(비트 11 개를 내보냄)는 NeXTMach 와 같은 흐름. 명령 0xc2 의 이름은 07 `monreg.h` 에 없음.
  - `snd_device_vol_set`·`snd_device_vol_save`: `callout_dispatch(CALLOUT_PRI_THREAD, snd_vol_set|snd_vol_save, 0)`. `snd_vol_save`: NeXTMach 와 같음.
  - `snd_dev_intr`(외부): `printf("SoundDSP: snd_dev_intr called!\n")` 다음 `snd_device_attach` 와 같은 CSR·`mon_send` 차례(`mon_csr_and(~(DMAOUT_DMAEN>>24))`, `mon_csr_or(DMAOUT_OVR>>24)`, `mon_csr_and(~(DMAIN_DMAEN>>24))`, `mon_csr_or(DMAIN_OVR>>24)`, `mon_send(MON_SNDIN_CTRL(0), 0)`, `mon_send(MON_SNDOUT_CTRL(0), 0)`, `mon_send(MON_GP_OUT, 0xff)`).
  - `snd_device_probe`: NeXTMach 와 같음. `snd_device_attach`: `mon = P_MON`(slot + 0x200e000), 위 차례, DMA 채널 설정 없음, `install_scanned_intr(I_SOUND_OVRUN, snd_dev_intr, 0)`, `return 0`. `def_*`: NeXTMach 와 같은 값(0xc0000·0x10000·0x80000·0xc000 이 `snd_var.h:44–50` 의 식과 같음, python).

방법(진단; 명세 `08_build/artifacts/m4p555/spec.json`, run `m4p555-p1`, 바탕 `m0p554-a1-stage`, `m4_id` `m68k-242`, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 진단 머리: NeXTMach `nextdev/snd_snd.h` 에서 `<nextdev/busvar.h>` 만 `<dev/busvar.h>`(§549 와 같은 SDK 판)로 바꾼 사본을 `inc` 로(`nextdev/snd_snd.h` 는 스테이지에 없음).
- 변형 A1(`08_build/artifacts/m4p555/src/snd_device_A1.c`, 07 아님): 위 사실로 쓴 첫 작성본. 짜임·고지·HISTORY·남는 줄은 NeXTMach, include 는 D104 경로(`<m68k/cpu.h>`, `<dev/m68k/monreg.h>`, `<mach/vm_param.h>` 등), `P_MON`·`I()`·`I_SOUND_OVRUN` 은 파일 안 매크로(§549 와 같은 식), `mon_rev` 는 `extern char mon_rev;`(진단), 0xc2 는 숫자 그대로(진단), `snd_dev_intr` 는 외부 함수(앞 선언), `callout_dispatch` 는 K&R 선언(§549).
- 측정: `m4_m68k_probe.py compare`, `m68k_funcbytes.py 407ff14 4080556 OBJECT.o RECORD.json 40800cc=_snd_vol_set 4080388=_snd_vol_save 40b507c=_mon 40b5080=_ni_spkren 40b5084=_ni_lowpass 40b5088=_ni_vol_r 40b508c=_ni_vol_l`, 길이가 다른 함수는 실기 `otool -tv` 명령 비교; 섹션 크기(`__data` 58·`__cstring` 38(두 문자열과 순서)·bss 20), `__data` 바이트(재배치 빼고)와 원본 대조 및 `__data` 재배치 다섯(함수 셋·문자열·`sound_dinfo`)의 대상·가산값, 정의 기호(외부·지역·COMMON 이름과 크기; `ll_snd_var` 의 COMMON 크기와 +0x2b1), 원본에 없는 미정의 기호.

판정(미리 정함; 07 은 바꾸지 않음):
- 15 함수가 모두 같아지기 전에는 07 을 만들지 않습니다. 다른 함수는 차이를 적고 꼴을 바꿔 시험합니다.
- 15/15 이면 바이트로 정해지지 않는 것(0xc2 의 이름, `mon_rev` 의 선언 꼴·자리, `snd_snd.h` 의 07 공급 꼴)을 결과와 함께 사용자께 여쭙고 구현 계획을 세웁니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 555.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `__data` 는 48 B 가 아니라 58 B [0x40b20c0, 0x40b20fa): `struct bus_driver` 에 `br_cname`·`br_cinfo`·`br_flags` 가 더 있음 | 스테이지 `src/bsd/dev/busvar.h:121–134` 읽음, python 7×4+4×5+2 = 50; 원본 0x40b20f0–0x40b20f8 이 0(이번 세션 python 덤프) | ✅ 제 오류. 사실 줄과 측정 고침 |
| `_dspdriver` 는 0x40b2192 | `symbols.tsv:554` 읽음, python `hex(67838354)` | ✅ 제 오기. 고침 |
| 함수 15 개 길이·합 1602 B, 함수별 동작(init·set/get_parms·set/get_volume·`snd_vol_set` 의 같음 경로·`mon_rev` 갈래·`while` 고리·`snd_vol_save`·wrapper·`snd_dev_intr`·probe·attach·`def_*`) | 원본 목록 0x407ff14–0x4080554 전체를 이번 세션 읽음; python 함수 합 | ✅ |
| `mon_rev` 갈래는 return 하지 않고 `ni_vol_r`→`ni_vol_l` 저장 뒤 `while` 검사로 합류; 같음 경로·새 갈래는 `flags` 를 정하지 않음 | 원본 0x40801ea–0x4080208·0x4080342–0x4080360 읽음 | ✅ 사실 줄에 적음 |
| `ll_snd_var.gpflags` 는 0x2b1, `sizeof` 698 B; 700 B 는 다음 기호 간격일 뿐 | python(snd_queue 62, ll_snd_dma 344), `Q554__snd_reply_L.o` STABS `s62`·`s248`·`s28` | ✅(사실 줄의 700 B 는 간격으로 적어 둠) |
| `I(3,5,8)` = 0x835, `P_MON` = slot + 0x200e000 | `07_kernel/nextmach/next/cpu.h:153·213·256` 읽음, python | ✅ |
| `m68k_funcbytes.py` 명령에 `OBJECT.o RECORD.json` 이 빠짐 | 도구 1–8 행 사용법 읽음 | ✅ 고침 |
| `__data` 는 재배치 대상·가산값도 봐야 함(funcbytes 는 `__text` 만) | — | ✅ 측정에 더함 |
| `m5_m68k_zerofill.py objs` 의 겹침 검사는 §464 후보와 그 호출의 후보만 봄 → 앞서 받아들인 M4 bss 후보(`autoconf`·`nextdbgasm`·`machine_clock`·`dma`)와의 겹침은 따로 확인 | 도구 148–150 행 읽음 | ✅ bss 판정 단계(구현 계획)에서 python 으로 따로 확인하도록 적음 |
| "1997 은 DMA 를 이 파일에서 뺐음" 은 행선지를 입증하지 않음 | — | ✅ 문구 고침 |
| `mon_rev` 의 부호·`volatile`·정의 파일은 바이트로 정해지지 않음 | 원본 0x40950c4·0x4068eee·0x4080158 이 모두 바이트 접근 | ✅ 사용자께 여쭐 목록에 있음 |

### 555.2 결과(2026-10-30)

- run `m4p555-p1`(A1·A2, 기록 `m4-m68k-probe-p555-20261030.json`): 두 컴파일 모두 종료 1 — `conflicting types for 'mon_rev'`: 스테이지 SDK `src/bsd/m68k/cpu.h:54` 가 이미 `extern u_char mon_rev;` 를 선언함(제 사실 수집 누락: 참고 트리만 찾고 스테이지 SDK 머리를 찾지 않았음). 따라서 `mon_rev` 의 선언 꼴은 1997 공개 머리로 정해짐(바이트 접근과 맞음); 이 파일에서는 선언하지 않습니다.
- run `m4p555-p2`(B1·B2 = A1·A2 에서 `extern char mon_rev;` 한 줄만 뺌; 명세 `08_build/artifacts/m4p555/spec-p2.json`, 기록 `m4-m68k-probe-p555-p2-20261030.json`): 명령 종료 0, 경고 0, i386 머리 0(`diag_gate` 참), 옵션 차이 없음.
- B1·B2 모두 **15/15**(`m4-m68k-funcbytes-p555-B1/B2-20261030.json`, 정적 함수 둘·bss 정적 다섯 대응), L1 `NOT_MATCH` 사유 `['__DATA,__bss: unverified']` 하나(판정 `provisional`), 원본에 없는 이름 0. B1 = B2(canon·`obj_sig`): `mon_rev` 갈래의 상수를 숫자(B1)로 쓰든 `(VOLUME_RCHAN|VOLUME_LCHAN|vol_r)<<24` 꼴(B2)로 쓰든 같은 객체.
- python 확인(`m4-m68k-p555-checks-20261030.json`, `ok` 참): 섹션 `__text` 1602·`__data` 58·`__cstring` 38·`__bss` 20; `__data` 의 재배치 아닌 바이트가 원본 [0x40b20c0, 0x40b20fa) 와 같고 재배치 다섯(`__text` 의 probe·attach·`snd_dev_intr`, `__cstring+0`, `_sound_dinfo`)의 대상이 원본 낱말과 같음; `__cstring` 38 B 가 원본 0x40abb34 와 같음; bss 정적 순서 `mon`·`ni_spkren`·`ni_lowpass`·`ni_vol_r`·`ni_vol_l`(+0…+16, 원본 0x40b507c… 와 같은 차례); COMMON `_gpflags` 4·`_ll_snd_var` 698(원본 다음 기호 간격 700)·`_sound_dinfo` 4 와 `sys/buf.h` 의 임시 정의(`_buf`·`_bufhash` 등, `_master_cpu`) 모두 원본에 있는 이름(`_bufpages`·`_nbuf` 는 원본 `__data` — M7 합침 의무, §506 과 같음); 미정의 12 개 모두 원본에 있음.
- 판정(미리 정한 대로): 15/15 이므로 바이트로 정해지지 않는 것을 사용자께 여쭙고 구현 계획을 세웁니다. 여쭐 것: ① 0xc2 명령과 `mon_rev` 갈래 상수의 꼴(숫자 그대로 / `VOLUME_*<<24` 식 / 새 매크로 이름) ② `nextdev/snd_snd.h` 의 07 공급 꼴(NeXTMach 사본 + include 한 줄, 또는 1997 에 없는 함수 원형 정리 등) ③ NeXTMach 의 쓰이지 않는 줄(`extern int sound_active;`·`extern snd_var_t snd_var;`, 지운 함수의 정적 원형·`SO_JUMP_WAIT`) 처리. bss 자리는 구현 계획에서 `m5_m68k_zerofill.py objs` 로 reference-inferred 를 보고, 앞서 받아들인 M4 bss 후보와의 겹침을 python 으로 따로 확인(§555.1).
- 사용자 결정(2026-10-30, AskUserQuestion): ① "숫자 + VOLUME 매크로": 0xc2 는 숫자 그대로(뜻 모름을 주석에), 채널 비트는 NeXTMach 이름으로 `(VOLUME_RCHAN|VOLUME_LCHAN|vol_r)<<24` 꼴(B2) ② `snd_snd.h` 는 "NeXTMach 사본 + include 한 줄"(D104; 1997 에 없는 함수 원형은 그대로) ③ 남는 줄은 "진단과 같음": 두 `extern` 은 NeXTMach 글대로 두고, 지운 함수에만 쓰이던 정적 원형과 `SO_JUMP_WAIT` 는 지우고 머리 주석에 적음(D113 선례).

## 556. M4-62 구현 계획 — 07 `src/machdep/m68k/snd_device.c`, `nextmach/nextdev/snd_snd.h`(코딩 전, 2026-10-30)

확인한 사실(이번 세션): §555.2 결과와 결정. `stage_m68k.py` 는 `M4FILES`·`M4HEADERS`·`X86` 을 "PLAN 이하의 가장 큰 키"로 고르고(489·505·395 행), `EXCEPTS` 는 `EXCEPTS[PLAN]` 을 바로 씀(595 행), `--plan N` 은 `EXCEPTS` 에 N 이 있어야 받음(656 행). `m5_m68k_zerofill.py objs OUTDIR RECORD.json PLAN OBJECT:OBJ:REF`(도구 7 행).
1. 07 `nextmach/nextdev/snd_snd.h` = NeXTMach 사본 + `<nextdev/busvar.h>` → `<dev/busvar.h>`(표시 plan 556, D104).
2. 07 `src/machdep/m68k/snd_device.c`(D103) = §555 B2 의 글에 머리 주석(1997 바뀜·지운 줄 목록·근거)과 표시 plan 556 을 단 것; 진단 문구는 빼고, `mon_rev` 는 SDK `<m68k/cpu.h>` 선언을 씀(이 파일에서 선언 안 함), 0xc2 에 주석. 본문 토큰은 B2 와 같아야 함(python, 주석 뺀 토큰 비교).
3. `stage_m68k.py`: `M4FILES[556]` = 554 + `snd_device.c`, `M4HEADERS[556]` = 554 + (`nextdev/snd_snd.h` → `src/bsd/nextdev/snd_snd.h`), `EXCEPTS[556] = dict(EXCEPTS[554])`, 머리 목록에 556; `X86` 은 그대로(556 은 s6lm 을 씀; x86 이 읽는 07 변경 없음).
4. 회귀: `--plan 554` 재생성 = 보관 `m0p554-a1-stage`(모든 키); `m0p556-a1-stage` 와 보관 554 의 차이는 `src/machdep/m68k/snd_device.c`·`src/bsd/nextdev/snd_snd.h` 둘뿐(python assert). M5 205 줄(`m3p556-b554`·`m3p556-cc1`)과 `compare`(`differ_unexpected`·`lost` 빔, 요약 같음, 새 경로는 위 둘). x86 입력 `m4_x86_inputs.py s6lm`·`--plan 556 x86gate`.
5. 확인 run `m4p556-p1`(F = `@machdep/m68k/snd_device.c`, L = §555 B2 글 그대로): 종료 0·경고 0, `provisional`(사유 bss 하나), 15/15, F = L(canon·`obj_sig`), F = §555 B2 객체(canon). run `m4p556-e1`: `-E` 토큰 F = L.
6. 최종 run `m4p556-a1`(F 만, REF = L, `bss_inferred` [`snd_device`]): `gate.ok`; zerofill `objs`(`m4-m68k-zerofill-p556-20261030.json`): `reference-inferred` 이고 후보가 [0x40b507c, 0x40b5090); 앞서 받아들인 M4 bss 후보(`autoconf`·`nextdbgasm`·`machine_clock`·`dma` 의 zerofill 기록)와 이번 후보의 겹침 0 을 python 으로 따로 확인(§555.1). python 확인: §555 확인 항목(섹션, `__data` 바이트·재배치, `__cstring`, bss 정적 순서, COMMON 이름, 미정의), 외부 정의 = 원본 이름 13 개, 지역 `_snd_vol_set`·`_snd_vol_save`·bss 정적 다섯, L1 0x407ff14 사유 bss 하나, 15/15, 입력 사슬(`snd_device.c`·`snd_snd.h`·`snd_var.h`·`snd_msgs.h`·`dma.h`·`monreg.h`·`nvram.h`), i386 머리 0.
7. 기록: 근거 `m68k-snd_device.md`(먼저), diff(NeXTMach 대비 둘), 상태표(`ACCEPTED` 에 zerofill 기록과 함께; CODE+BSS_INFERRED), PROVENANCE(새 행 둘), MODIFICATIONS, DECISIONS D124, 계획 결과·현재 상태, HANDOFF, 메모리.
관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 556.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 겹침 검사 범위가 §547 보다 좁음: §464 후보뿐 아니라 그 뒤 M5 기록(§467–488)과 받아들인 M4 기록 모두와 비교해야 함 | `m4-m68k-p547-checks-20261029.json` 의 `bss.prior` 31 읽음; `"plan464_record"` 를 담은 기록을 grep(17 개; 진단 셋 `-D-`·`-D1-`·`-C2-` 뺌 → 14 기록), python 으로 §464 16 + 14 기록의 후보 = 배치 32, 이름 겹침·구간 겹침 0, 새 후보 [0x40b507c, 0x40b5090) 와 겹침 0 | ✅ 6 고침. 제 첫 glob(`m*-m68k-zerofill-*`)이 `m5-m68k-ns_timer-zerofill` 꼴 이름을 놓쳤음 |
| 이전 M4 zerofill 기록은 최상위 `candidates` 가 없고 `summary.candidates` 가 16 진 문자열 | 위 python 에서 그 꼴로 읽음 | ✅ |
| "외부 정의 = 원본 이름 13 개" 는 `__text` 외부 함수로 한정해야 함(외부 자료 `_sounddriver`·`_vol_l`·`_vol_r` 이 더 있음) | §555 p2 기록의 정의 기호 목록(이번 세션 출력) | ✅ 6 고침 |
| `gate.ok` 는 M5 줄과의 옵션 차이를 보지 않음 → 옵션 차이 없음을 따로 확인 | `m4_m68k_probe.py` 384–392 행(gate 구성, §554 에서 읽음), `cmd` 출력 `option differences` | ✅ 관문에 더함 |
| 최종 명세는 `08_build/artifacts/m4p556/spec.json`, `bss_inferred` 는 `refs` 가 필요, REF = p1 L | `m4_m68k_probe.py:57–67`·`m4_m68k_status.py:83–85`(이번 세션 읽음) | ✅ 6 에 적음(확인 명세는 `confirm/`) |
| `ACCEPTED` 는 (최종 기록, SHA, zerofill 기록, SHA) 넷; 상태 도구는 다른 기록의 bss 구간을 다시 비교하지 않음 | `m4_m68k_status.py` 30–55·72–80 행(이번 세션 읽음) | ✅ 7 에 적음 |
| 상태표 재현성(두 번 실행 같음·기존 객체 이름 대조)을 관문에 넣을 것 | §554.4 에서 한 방식 | ✅ 더함 |
| M7 의무(bss 최종 배치, `_bufpages`·`_nbuf` 의 임시 정의와 원본 `__data` 합침)를 기록에 | §555.2 | ✅ 7 에 더함 |
| 함수별 출처(NeXTMach 그대로 / 줄 지움 / 바이트로 씀)를 머리 주석·근거 문서에 함수별로 | AGENTS.md 출처 요구, §547 방식 | ✅ 2·7 에 더함 |
| `X86` 은 PLAN 이하 최대 키라 556 은 s6lm; 다른 556 등록은 `M4FILES`·`M4HEADERS`·`EXCEPTS`·머리 목록이면 됨 | `stage_m68k.py:395·489·505·595·656`(이번 세션 grep) | ✅ |
| M5 205 줄은 새 객체 검증을 대신하지 않는 추가 회귀; `compare` 는 assert 하지 않으므로 `differ_unexpected`·`lost` 와 새 경로를 python 으로 봄 | §554 에서 같은 방식으로 python 확인 | ✅ 그대로 |
| 새 경로만 더하므로 plan 506 검사 때문에 기존 기록을 다시 받아들일 필요 없음 | 기존 07 머리를 고치지 않음(새 파일 `snd_snd.h` 만) | ✅ 상태 도구 실행으로 확인 |
| 머리 원형 `snd_device_def_dma_size` 와 정의 `snd_device_def_dmasize` 의 이름 차이(NeXTMach 그대로) | NeXTMach `snd_snd.h:74`·`snd_device.c:912` | ⏭️ 사용자 결정(머리 그대로)에 따름; 근거 문서에 적음 |

### 556.2 결과(2026-10-30)

- 1·2: 07 `nextmach/nextdev/snd_snd.h`(79 행, SHA `1a8ad14c…`; NeXTMach 대비 include 한 줄), 07 `src/machdep/m68k/snd_device.c`(393 행, SHA `8e587fbe…`; §555 B2 와 주석 뺀 토큰 1486 개 같음, python). diff `06_reconstruction/evidence/m68k-snd_device.diff`(847 행)·`m68k-snd_snd_h.diff`(11 행).
- 3: `stage_m68k.py` 672 → 675 행(`M4FILES[556]`·`M4HEADERS[556]`·`EXCEPTS[556]`·머리 목록).
- 4: `--plan 554` 재생성(`m0p554-r556-stage`)이 보관 `m0p554-a1-stage` 와 모든 키가 같음; `m0p556-a1-stage`(938 파일)와 554 의 차이는 `snd_device.c`·`snd_snd.h` 둘(python assert). M5 205 줄: `m5-554.cmd` 가 §554 의 것과 `cmp` 같음, run `m3p556-b554`·`m3p556-cc1` 종료 0, 객체 205 개 바이트 같음, stderr 205 개 같음(비어 있지 않은 것 52); `compare`(`m3-m68k-p556-compare-20261030.json`, `-b554-`) `differ_unexpected`·`lost` 빔, 요약 같음, 새 경로는 위 둘뿐. x86: `m4-x86-inputs-p556-20261030.json` `ok`, `--plan 556 x86gate` 일곱 같음·`v183_paths` 0. 제 실수: `m4_x86_inputs.py` 를 처음에 `L2_FORMS`·`L2_EXPECT` 없이 불러 기본 forms 표와 비교해 `ok` 거짓이 나왔고(잘못된 기록은 scratchpad 로 옮김), 사용법(도구 4 행)대로 다시 불러 `ok` 참.
- 5: run `m4p556-p1`(`confirm/spec.json`, `m4-m68k-probe-p556-p1-20261030.json`): F·L 종료 0·경고 0, `provisional`(사유 bss 하나), 15/15, F = L = §555 B2(canon·`obj_sig`). run `m4p556-e1`: `-E` 토큰 11988 개 F = L, i386 머리 0.
- 6: run `m4p556-a1`(명세 `08_build/artifacts/m4p556/spec.json`, REF = L `e6e7e608…`, `bss_inferred` [`snd_device`]; `m4-m68k-p556-final-20261030.json`): `gate.ok`, 옵션 차이 없음. zerofill `m4-m68k-zerofill-p556-20261030.json`: `reference-inferred`, 후보 [0x40b507c, 0x40b5090). python 확인 `m4-m68k-p556-checks-20261030.json`(`ok` 참; 항목은 근거 문서): 받아들인 배치 32 개와 겹침 0, 의존 123 파일·i386 0, 입력 사슬 일곱.
- 7: 근거 `06_reconstruction/evidence/m68k-snd_device.md`; 상태표 `06_reconstruction/m68k-m4-status.tsv`(26 → 27 행)·`m4-m68k-status-p556-20261030.json`: 25 객체(OBJECT_MATCH 20, CODE+BSS_INFERRED 5), 덮은 행 47/188, 37246/215874 B(17.25%; python 같음, +1602 B), 두 번 실행 같음, §554 표와 이름 대조로 더한 것 `snd_device` 뿐·바뀐 것 없음. `m4_m68k_status.py` `ACCEPTED` 에 넷 묶음 한 줄. PROVENANCE 1148 → 1150 행, MODIFICATIONS 698 → 700 행, DECISIONS D124(127 → 128 행).

## 557. M4-63 세부 계획 — m68k `snd_dspcmd.c`(행 243) NeXTMach 글 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): 남은 사운드 행(243–246·249–253)은 경계가 정확하지 않으나, [0x4080556, 0x408103e) 의 14 함수가 NeXTMach `nextdev/snd_dspcmd.c` 의 정의 순서와 같고(이름 있는 넷 `snd_dsp_cmd_port_msg`·`snd_dspcmd_def_dmasize`·`_def_high_water`·`_def_low_water` 가 그 자리) 바로 뒤 0x408103e 가 NeXTMach `snd_dspdev.c` 의 첫 외부 함수 `dsp_dev_init` 입니다. §551–556 의 사운드 머리를 그대로 씁니다.

확인한 사실(이번 세션; 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt` 0x4080556–0x408103e(819 줄; 다음 라벨 빼고), 기호표, 원본 `__data`, python):
- 함수 14 개(합 2792 B = 범위 길이, python): `snd_dsp_cmd_port_msg` 154, 이름 없는 42(`dspq_check_param`)·96(`dspq_setup_user_chan`)·1204(`snd_dspcmd_msg`)·184(`snd_dspcmd_event`)·286(`snd_dspcmd_chandata`), `snd_dspcmd_def_dmasize` 54, `snd_dspcmd_def_high_water` 30, `snd_dspcmd_def_low_water` 32, 이름 없는 246(`snd_dspcmd_dma_out`)·266(`snd_dspcmd_dma_in`)·10(`snd_dspcmd_abortdma`)·94(`snd_dspcmd_req_msg`)·94(`snd_dspcmd_req_err`) — 괄호는 NeXTMach 정의 순서(`snd_dspcmd.c:76·103·122·146·485·516·554·562·574·589·714·831·839·874`)에 맞춘 대응(바이트로 아직 확인 안 함).
- 행: `m68k-243`(정확 아님, [0x4080556, 0x4080d58–0x408103e))는 범위 안에 있고, `m68k-244`(`snd_dspdev.c`, 시작 0x4080d58–0x408103e)가 범위와 겹침 → probe 명시 범위 `{"range": ["0x4080556", "0x408103e"], "rows": ["m68k-243"], "partial": ["m68k-244"], "basis": …}`(§537–538 방식; `basis` 는 필수, §557.1).
- 자료: `__data` [0x40b20fa, 0x40b2192) 152 B = 함수 안 정적 `static struct dsp_dma_out M`(0x50 B, `dma_out` 의 0x4080d9e 가 참조)와 `static struct dsp_dma_in M`(0x48 B, 0x4080e92 가 참조)(NeXTMach `snd_dspcmd.c:599·724`); 다음 외부 기호 `_dspdriver` 0x40b2192. 문자열 참조 0. 외부 자료 `_dsp_var`(+0xf8, +0x156–+0x188)·`_snd_var`(+0x0, +0x34)·`_page_size`·`_page_mask`·`_kernel_map`. 부르는 것: `kalloc`·`bcopy`·`vm_allocate`·`vm_map_copy`·`vm_map_pageable`·`vm_deallocate`·`snd_stream_queue_init`·`dspq_execute`·`dspq_enqueue`·`dspq_free_msg`·`dspq_start_simple`·`dspq_start_complex`(주소로)·`msg_send`·`snd_reply_dsp_msg`·`snd_reply_dsp_err`·`dsp_dev_loop`.
- 머리: NeXTMach 은 `<dsp.h>`(`NDSP`; m68k 생성 머리 없음, `config_options-m68k.tsv` 에 행 없음), `<vm/vm_param.h>`, `<vm/vm_kern.h>`, `<next/cpu.h>`, `<nextdev/snd_var.h>`, `<nextdev/snd_dsp.h>`, `<nextdev/snd_dspreg.h>`(07 사본 D107, 스테이지 `src/bsd/dev/m68k/snd_dspreg.h`) 를 들임.

방법(진단; 명세 `08_build/artifacts/m4p557/spec.json`, run `m4p557-p1`, 바탕 `m0p556-a1-stage`, 위 명시 범위, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 진단 머리 `dsp.h`(`#define NDSP 1`, `inc` 로; 스테이지에 없음).
- 변형 A(`08_build/artifacts/m4p557/src/snd_dspcmd_A.c`): NeXTMach 글에서 include 만 D104/D110 경로(`<mach/vm_param.h>`, `<m68k/cpu.h>`, `<dev/m68k/snd_dspreg.h>`)로 바꾼 꼴.
- 측정: `m4_m68k_probe.py compare`(경고 기록), `m68k_funcbytes.py 4080556 408103e OBJECT.o RECORD.json` + 이름 없는 열 함수 대응(`40805f0=_dspq_check_param 408061a=_dspq_setup_user_chan 408067a=_snd_dspcmd_msg 4080b2e=_snd_dspcmd_event 4080be6=_snd_dspcmd_chandata 4080d78=_snd_dspcmd_dma_out 4080e6e=_snd_dspcmd_dma_in 4080f78=_snd_dspcmd_abortdma 4080f82=_snd_dspcmd_req_msg 4080fe0=_snd_dspcmd_req_err`)과 `__data` 정적 둘(`40b20fa`·`40b214a`; 대응 이름은 컴파일러가 붙이는 지역 이름을 결과에서 확인 후), 길이가 다른 함수는 실기 `otool -tv` 명령 비교; `__data` 152 B 바이트·재배치와 원본, 섹션, 정의 기호, 원본에 없는 미정의.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이(길이, 첫 차이, `dsp_var` 오프셋)를 적고 다음 계획에서 1997 꼴을 시험합니다. 14/14 이고 `__data` 가 같으면 `dsp.h` 구성 행과 07 꼴을 사용자께 여쭙니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄.

### 557.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 14 함수 대응(switch·`kalloc(0x54)`+`snd_stream_queue_init`·정적 M 복사·`abortdma` 10 B 등)에 틀린 것 없음 | 원본 목록 이번 세션 추출·읽음(대응 표의 함수 경계), `m68k-functions.tsv` python 합 2792 | ✅(바이트 같음은 진단으로 봄) |
| 명시 범위는 `span()` 을 만족하나 계획 JSON 에 필수 `basis` 가 빠짐 | `m4_m68k_probe.py:159` 읽음; 제 `span()` 시험은 `basis` 를 넣고 돌려 이 누락을 못 봄 | ✅ 제 누락. 고침 |
| 원본 M 은 80·72 B 인데 NeXTMach 선언으로는 72·64 B(`snd_stream_msg_t` 32 + play 40 / record 32); 원본은 `msg_size` 가 8 크고 템플릿 +0x20 에 0 바이트 8 개가 더 있는 꼴 | 원본 0x40b20fa 낱말 `…0050` 과 복사 길이 `pea 0x50`(0x4080d98)·`pea 0x48`(0x4080e8a) 읽음, NeXTMach `snd_dspcmd.c:595–600` 의 구조체(mh + pd) 읽음 | ✅ 사실 줄·판정에 더함(+0x20 의 8 B 가 어떤 필드인지는 진단에서 봄; 1997 `snd_stream_msg_t` 가 커졌을 가능성) |
| 템플릿 메시지 형 값(INTEGER_32·PORT·longform INTEGER_8 등)은 NeXTMach 초기화와 부합 | 원본 덤프(이번 세션)와 NeXTMach 초기화 읽음 | ✅ |
| `dsp_var` 접근 오프셋(+0xf8 `chan` … +0x188 `flags`)은 07 머리(1997 `dma_chan` 248 B)와 맞음 | 진단 컴파일 객체의 재배치로 확인할 항목 | ⏭️ 진단 결과로 확인(이 줄은 아직 사실로 적지 않음) |
| `<dsp.h>`·`#if NDSP > 0` 이 파일 전체; `next/cpu.h` 이름 쓰임 없음 | NeXTMach `snd_dspcmd.c:27–28·906`(이번 세션 읽음) | ✅ |
| `dma_in` 에 NeXTMach 에 없는 초기화: `priority = 2`(0x4080f2a), `atomic = 0`(0x4080f30), `sequence = 0`(0x4080f34) | 원본 0x4080ef8–0x4080f66 읽음, 07 `snd_dsp.h:105–107` 읽음, NeXTMach `snd_dspcmd.c:810–822` 읽음 | ✅ 사실에 더함(1997 본문 차이 후보) |
| switch 표(0x408057a, 0x40806f4)는 자료이므로 명령 비교에서 가를 것 | — | ✅ 측정에 더함 |
| NeXTMach 의 `!dsp_var.flags & F_MODE_C_DMA`(108·668·788)와 `bcopy` 의 값 넘김(494)을 고치지 말 것(원본도 같은 꼴) | NeXTMach 줄 읽음 | ✅ 진단 A 는 NeXTMach 글 그대로이므로 해당 없음; 다음 계획의 원칙으로 둠 |
| `refs` 없는 `compare` 의 종료 0 은 일치가 아님; `diag_gate` 는 경고도 실패로 셈 | `m4_m68k_probe.py` 382·399 행(§554 에서 읽음) | ✅ 판정은 funcbytes·L1 로 함 |
| 목록 줄 수는 819(820 은 다음 라벨 포함) | 제 추출이 `0408103e` 줄 앞까지라 `_dsp_dev_init:` 라벨이 들어감 | ✅ 고침 |

판정 보충(미리 정함): A 는 `__data` 가 136 B(원본 152 B)로 다를 것으로 예상합니다(1997 메시지 구조체 차이). A 의 결과로 1997 메시지 배치(+0x20 의 8 B)를 따로 진단하는 계획을 세웁니다.

### 557.2 결과(2026-10-30)

- run `m4p557-p1`(A, 기록 `m4-m68k-probe-p557-20261030.json`): 종료 0, 경고 0, i386 머리 0, 옵션 차이 없음. `__text` 2776 B(원본 2792), `__data` 136 B(원본 152 B; 정적 `_M.44`·`_M.47`).
- **12/14**(`m4-m68k-funcbytes-p557-A-20261030.json`): `snd_dsp_cmd_port_msg`·`dspq_check_param`·`dspq_setup_user_chan`·`snd_dspcmd_msg`(1204 B)·`event`·`chandata`·`def_*` 셋·`abortdma`·`req_msg`·`req_err` 가 NeXTMach 글 그대로 같음 — 따라서 `dsp_var` 접근(+0xf8 … +0x188)은 07 머리 배치와 맞음(§557.1 의 ⏭️ 확인). 다른 것: `snd_dspcmd_dma_out`(길이 같음, 바이트 14·참조 1 다름), `snd_dspcmd_dma_in`(원본 266 대 250). L1 `NOT_MATCH`(`__text` 실패, `__data` 미검증).
- 원인 후보(이번 세션 읽음): ① 1997 `snd_stream_msg_t` 는 `data_tag` 뒤에 8 B 가 더 있는 배치(원본 바이트가 보이는 것은 공간·초깃값·오프셋뿐이고, 이름 `ownerType`·`streamOwner` 는 참고 글에서 온 호환 해석; §558.1) — Darwin 0.1 `bsd/dev/snd_msgs.h:295–301`, 이 프로젝트의 `07_kernel/nextdev_private/bsd/dev/snd_msgs.h:253–259`(x86 libDriver 가 씀); 원본 M 의 +0x20 0 바이트 8 개와 `msg_size` 0x50·0x48 이 이것과 맞음. 스테이지의 `snd_msgs.h`(x86 07 `driverkit/snd_msgs.h:251–255`)와 NeXTMach 에는 없음. ② `dma_in` 의 1997 줄: `dmsg->priority = 2`(`DSP_MSG_LOW`, `driverkit/snd_msgs.h:412`), `atomic = 0`, `sequence = 0`(`DSP_MSG_ONLY`) — 원본 저장 차례는 priority(+0x20)·atomic(+0x22)·sequence(+0x21)(0x4080f2a–0x4080f34), NeXTMach 다른 곳(`snd_dspcmd.c:189–191`)의 글 차례는 priority·sequence·atomic.

## 558. M4-64 세부 계획 — `snd_dspcmd.c` 1997 꼴 진단(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p558/spec.json`, run `m4p558-p1`, 바탕 `m0p556-a1-stage`, §557 명시 범위):
- 진단 머리 `snd_msgs97s.h`(`inc`): 스테이지의 `snd_msgs.h`(= x86 07 `driverkit/snd_msgs.h`) 사본에서 `snd_stream_msg_t` 의 `data_tag` 뒤에 Darwin 0.1 의 두 줄(`ownerType`·`streamOwner`)만 더한 것; 같은 가드 `_SND_MSGS_` 라 진단 소스가 맨 앞에서 들이면 스테이징 판 본문은 건너뜀(§552 의 방법).
- 변형 B1: A + 맨 앞 `#import <snd_msgs97s.h>` + `dma_in` 에 `dmsg->priority = DSP_MSG_LOW; dmsg->sequence = DSP_MSG_ONLY; dmsg->atomic = FALSE;`(NeXTMach 다른 곳의 글 차례), `dmsg->datafollows = 0;` 앞.
- 변형 B2: B1 에서 세 줄 차례를 priority·atomic·sequence 로(원본 저장 차례).
- 측정: §557 과 같음(funcbytes 대응에 `__data` 정적 둘은 결과의 지역 이름으로 `40b20fa`·`40b214a` 를 더함), `__data` 152 B 바이트·재배치를 원본과 python 대조, 두 정적의 순서.
- 더함(§558.1): run `m4p558-e1` 로 B1·B2 의 `-E` 를 내어 `snd_stream_msg_t` 정의가 한 번뿐이고 두 필드가 들어 있음을 확인(가드 방법의 증거).
판정(미리 정함): 14/14 이고 `__data` 가 원본과 같은 꼴이 있으면, 1997 `snd_stream_msg_t` 를 07 에서 어떻게 공급할지(x86 07 `driverkit/snd_msgs.h` 에 두 줄 → x86 재빌드와 이 머리를 쓰는 받아들인 m68k 객체 셋(`snd_rcv`·`snd_reply`·`snd_device`)의 재수락 필요 / m68k 전용 머리 사본을 새로 두고 `M4HEADERS` 매핑을 바꿈 → 바뀐 매핑을 쓰는 다음 계획부터만 적용, 기존 받아들인 기록은 그대로)와 `dsp.h` 구성 행, `dma_in` 줄의 꼴을 사용자께 여쭙니다. 아니면 차이를 적고 멈춥니다.
관문: 명령 종료 0, 경고 0, i386 머리 0, 옵션 = M5 줄.

### 558.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `dma_out` 의 바이트 차이 14 개는 구조체 72 → 80(프레임·복사 길이·스택 변위)로 다 설명되고, 참조 1 개는 정적 `_M.44` 대응이 없어서 생긴 것 | B 진단의 funcbytes(정적 대응 포함)로 직접 확인할 항목 | ⏭️ 진단 결과로 확인 |
| `dma_in` 의 16 B 는 세 저장 14 B + 분기 확장 2 B(0x4080ee8 `bne …:w`); `m.rd.nbytes` 계산은 같음 | 원본 0x4080ee8 `bne 0x4080f6e:w` 읽음(이번 세션); 나머지는 진단으로 | ⚖️ 분기 꼴은 확인, 나머지는 진단으로 |
| A 의 두 템플릿 +0x20 에 0 바이트 8 개를 넣고 `msg_size` 를 72→80·64→72 로 하면 원본 152 B 와 같음 | B 의 `__data` 를 원본과 python 대조할 항목 | ⏭️ 진단 결과로 확인 |
| 필드 이름(`ownerType`·`streamOwner`)과 저장 순서로 원래 글 순서를 단정하지 말 것 | — | ✅ 문구 고침(B1·B2 두 차례를 모두 시험) |
| 가드 방법은 성립(`snd_var.h` → `nextdev/snd_msgs.h`, `snd_dsp.h` 는 `snd_var.h` 경유) | 07 `snd_var.h` 의 import 줄 grep(이번 세션), 스테이지 `snd_msgs.h:23–24` 가드(§554 에서 읽음) | ✅ + `-E` 확인을 더함 |
| 공용 머리를 고치면 영향받는 받아들인 m68k 객체는 셋; x86 직접 사용자는 `driverkit/snd_reply.c` 하나(libDriver 의 둘은 다른 private 머리) | §554 에서 확인한 사실과 같음(forms 208 행, `snd_server.m:20`·`audio_kern_server.m:42` grep) | ✅ |
| 관문에 경고 0 을 명시 | `m4_m68k_probe.py:382` | ✅ 고침 |
| "다른 공급" 을 m68k 전용 머리 사본 + `M4HEADERS` 매핑으로 구체화(기존 기록을 건드리지 않음) | `stage_m68k.py` 의 `M4HEADERS` 선택 규칙(PLAN 이하 최대 키, §556 에서 확인) | ✅ 여쭐 선택지에 적음 |

### 558.2 결과(2026-10-30)

- run `m4p558-p1`(기록 `m4-m68k-probe-p558-20261030.json`): B1·B2 종료 0·경고 0, i386 머리 0(`diag_gate` 참), 옵션 차이 없음. 두 객체 모두 `__text` 2792·`__data` 152, `__data` 바이트가 원본 [0x40b20fa, 0x40b2192) 와 같음(재배치 0, 정적 `_M.44` +0·`_M.47` +0x50).
- **B2 = 14/14**(`m4-m68k-funcbytes-p558-B2-20261030.json`, 정적 함수 열과 `40b20fa=_M.44`·`40b214a=_M.47` 대응), L1 `OBJECT_MATCH`(사유 없음), `candidate`, 원본에 없는 이름 0. B1 = 13/14: `dma_in` 이 바이트 2 개 다름(저장 차례) → 원본은 priority·atomic·sequence 차례의 글과 같음(B1 ≠ B2 canon, `obj_sig` 는 같음). 따라서 `dma_out` 의 차이(§557)는 구조체 크기와 정적 대응만이었음(§558.1 ⏭️ 확인).
- run `m4p558-e1`: B1·B2 의 `-E` 에서 `snd_stream_msg_t` 정의는 한 번, 필드 `header`·`data_tagType`·`data_tag`·`ownerType`·`streamOwner`; 스테이징 `snd_msgs.h` 는 들어갔으나 본문은 가드로 건너뜀(가드 방법 확인).
- 판정(미리 정한 대로): 14/14·`__data` 같음이므로 사용자께 여쭙니다: ① 1997 `snd_stream_msg_t`(+8 B)의 07 공급 ② `dsp.h` 구성 행(`NDSP 1`) ③ `dma_in` 세 줄의 꼴.
- 사용자 결정(2026-10-30, AskUserQuestion): ① 1997 `snd_stream_msg_t` 는 "x86 07 파일에 두 줄"(`07_kernel/src/driverkit/snd_msgs.h`, D123 과 같은 방향; x86 전체 재빌드와 받아들인 `snd_rcv`·`snd_reply`·`snd_device` 재수락) ② `dsp.h` 는 "`NDSP 1` hypothesis"(`config_options-m68k.tsv` 새 행, `sound.h` 와 같은 처리) ③ `dma_in` 세 줄은 "NeXTMach 상수 이름"(`DSP_MSG_LOW`·`FALSE`·`DSP_MSG_ONLY`, 차례 priority·atomic·sequence).

## 559. M4-65 구현 계획 — 07 `snd_dspcmd.c`, x86 07 `snd_msgs.h` 1997 `snd_stream_msg_t`, `dsp.h` 구성 + x86 재빌드, `snd_rcv`·`snd_reply` 재수락(코딩 전, 2026-10-30)

확인한 사실(이번 세션): §557–558 결과와 결정. 상태 도구는 계획마다 최종 명세 하나(`08_build/artifacts/m4p<plan>/spec.json`)를 읽고(`m4_m68k_status.py:83–85`), 넷 묶음(zerofill) 항목은 그 기록의 모든 객체를 CODE+BSS_INFERRED 로 봄(77·112 행) → OBJECT_MATCH 객체와 bss 추정 객체를 한 계획의 기록에 섞을 수 없음. 그래서 `snd_device` 재수락은 §560 으로 나눔. `gen_config_headers.py --arch m68k [--check]`(도구 5–6 행).
1. x86 07 `driverkit/snd_msgs.h`: `snd_stream_msg_t` 의 `data_tag` 뒤에 `msg_type_t ownerType;`·`port_t streamOwner;`(이름은 Darwin 0.1 `bsd/dev/snd_msgs.h:299–300` 과 같은 호환 해석, plan 290 과 같은 방식; 표시 plan 559, D125, D024). 진단 `snd_msgs97s.h` 와 주석 뺀 토큰이 같음을 확인.
2. x86 전체 재빌드 `s6ln`(§554 와 같은 절차; L2_FORMS·L2_EXPECT 를 둠): 일곱 묶음 problems 0; prefixdiff s6lm↔s6ln(plan 559): 스테이징 차이 g1a 의 `src/driverkit/snd_msgs.h` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` `[]` 또는 `['x86-snd_reply']`(그때 비 STABS 같음); 링크 `s6p559-ln1` → `l2_compare.py` → `cmp` 로 원본과 같음; `stage_m68k.py` 의 `X86[559] = 's6ln'`.
3. `config_options-m68k.tsv` 에 `dsp NDSP dsp.h 1 hypothesis` 행(근거: `snd_dspcmd` 가 `#if NDSP > 0` 안, §558 OBJECT_MATCH), `gen_config_headers.py --arch m68k` 로 `07_kernel/v183.34/m68k/generated/dsp.h`, `--check` 둘(x86·m68k) 통과.
4. 07 `src/machdep/m68k/snd_dspcmd.c`(D103) = NeXTMach + include 세 줄(D104·D110·D107) + `dma_in` 세 줄(표시 plan 559) + 머리 주석. 본문 토큰은 §558 B2 에서 진단 include 를 뺀 것과 같아야 함.
5. `stage_m68k.py`: `M4FILES[559]` = 556 + `snd_dspcmd.c`(07 파일을 둘 때 함께 등록 — `stage_m68k.py:506–507` 이 등록 안 된 `.c` 를 거부), `M4HEADERS[559]` = 556 그대로, `EXCEPTS[559] = dict(EXCEPTS[556])`, `X86[559] = 's6ln'`, 머리 목록에 559.
6. 회귀: `--plan 556` 재생성은 보관 `m0p556-a1-stage` 와 `generated/dsp.h`(새)·`src/bsd/nextdev/snd_msgs.h`(그 자리 고침)만 다름(python, 다른 차이 0); `m0p559-a1-stage` 와 보관 556 의 차이는 그 둘 + `src/driverkit/snd_msgs.h`(s6ln g1a)·`src/machdep/m68k/snd_dspcmd.c` 뿐. M5 205 줄(`m3p559-b556`·`m3p559-cc1`): 객체·stderr 같음, `compare` `differ_unexpected`·`lost` 빔, 요약 같음. x86 입력 `m4_x86_inputs.py s6ln`(환경 변수와 함께)·`--plan 559 x86gate`.
7. 확인 run `m4p559-p1`: `snd_dspcmd` F(07)·L(§558 B2 글에서 진단 import `snd_msgs97s.h` 한 줄을 뺀 사본; `<dsp.h>` 는 생성 머리로 남음), `snd_reply` R·`snd_rcv` R·`snd_device` R(모두 `@machdep/m68k/…`): 종료 0, 경고는 `snd_reply` 의 `kfree` 2 줄만(경로·줄 번호 빼고 §554 와 같음), `snd_dspcmd` F = L·14/14·`OBJECT_MATCH`; 세 R 은 받아들인 객체(§554 a2·§556 a1)와 canon 같음, 비 STABS 같음(STABS 수 차이는 기록), 함수 수 같음. run `m4p559-e1` `-E` 토큰 `snd_dspcmd` F = L.
8. 최종 run `m4p559-a1`(명세 `m4p559/spec.json`: `snd_dspcmd` F(REF = L)·`snd_reply` F(REF = p1 R, `known_warnings` = p1 R 의 stderr 줄 그대로)·`snd_rcv` F(REF = p1 R); 명시 범위는 §557): `gate.ok`; funcbytes 셋(14/14·21/21 템플릿 대응·1/1); python 확인(섹션·`__data` 152 B 원본과 같음·정적 `_M.44`·`_M.47`·지역 열 함수·외부 정의 = 원본 이름 넷·원본에 없는 미정의 0·입력 사슬(`snd_dspcmd.c`·`dsp.h`·`snd_var.h`·`snd_msgs.h`·`snd_dsp.h`·`snd_dspreg.h`·`dma.h`)·i386 0; `snd_reply`·`snd_rcv` 는 §554.4 항목 반복).
9. 상태표: `ACCEPTED` 의 §554 a2 줄을 §559 a1 줄로 바꿈(§556 줄은 §560 에서 바꿈 — 그 사이 상태 도구는 §556 기록에서 멈추므로 §559 와 §560 을 마친 뒤 한 번에 돌림). 기록: 상태 도구를 돌리기 **전에** 근거 `m68k-snd_dspcmd.md` 를 씀(도구가 근거 문서의 존재를 단언, §559.1); 그 뒤 diff(NeXTMach 대비 `snd_dspcmd.c`, x86 `snd_msgs.h` 의 plan 559 줄), PROVENANCE(새 행 `snd_dspcmd.c`·생성 `dsp.h`; 그 자리 고침 x86 `driverkit/snd_msgs.h`·`snd_rcv.c`·`snd_reply.c`·`snd_device.c` 의 받아들인 기록), MODIFICATIONS, DECISIONS D125, 근거 `m68k-snd_reply.md`·`m68k-snd_rcv.md`·`m68k-snd_device.md` 에 plan 559/560 절(새 머리 SHA·새 기록·객체 SHA; 이전 결과는 이력으로 둠).
관문: 명령 종료 0, 정한 경고뿐, i386 머리 0, x86 링크 `cmp` 같음, 회귀 같음.

## 560. M4-66 구현 계획 — `snd_device` 를 §559 머리로 다시 받아들임(코딩 전, 2026-10-30)

1. 최종 run `m4p560-a1`(명세 `m4p560/spec.json`: `snd_device` F, REF = §559 p1 R, `bss_inferred` [`snd_device`], 바탕 `m0p559-a1-stage`); `stage_m68k.py` 에 `EXCEPTS[560] = dict(EXCEPTS[559])`(`EXCEPTS` 는 정확한 키로 고름)·`M4FILES/M4HEADERS` 는 559 를 이음(PLAN 이하 최대 키), `X86` 그대로.
2. `gate.ok`; zerofill `objs`(`m4-m68k-zerofill-p560-20261030.json`) `reference-inferred` 후보 [0x40b507c, 0x40b5090); §556 과 같은 python 확인(받아들인 배치와 겹침 0 — 이때 §556 후보는 같은 객체이므로 빼고 셈), §556 최종 객체와 canon·비 STABS 같음, 15/15.
3. 상태표: `ACCEPTED` 의 §556 줄을 §560 넷 묶음으로 바꾸고, 상태 도구 두 번 실행·§556 표와 이름 대조(객체 수 26, 더한 것 `snd_dspcmd`, 바뀐 것은 `snd_reply`·`snd_rcv`·`snd_device` 의 plan·record·obj_sha256 뿐이어야 함).
4. 기록(§559 의 9 와 함께).
관문: §559 와 같음, 상태 도구가 멈추지 않음.

### 559.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| L 은 B2 에서 진단 import `snd_msgs97s.h` 한 줄만 빼야 함(`<dsp.h>` 는 남음) | B2 의 import 줄 grep(이번 세션) | ✅ 제 오기. 고침 |
| 상태 도구가 근거 문서 존재를 단언하므로 `m68k-snd_dspcmd.md` 를 도구 실행 전에 | `m4_m68k_status.py:119–120`(§554 에서 읽음) | ✅ 9 고침 |
| 구성 행은 탭 여섯 칸(마지막 근거 칸 채움), 값 1 은 hypothesis | `config_options-m68k.tsv` 머리 줄(이번 세션 읽음) | ✅ 구현 때 그 꼴로 |
| `EXCEPTS` 는 정확한 키로 고르므로 559·560 을 명시 | `stage_m68k.py:595·656`(§556 에서 읽음) | ✅ 5·§560 고침 |
| PROVENANCE·근거 문서 갱신 대상 열거 | PROVENANCE 해당 행들(§554·§556 에서 씀) | ✅ 9 고침 |
| 559/560 분리, 사이에 §556 기록에서 멈춤, `snd_device` 는 교체, 스테이지 차이 예상, M5 회귀, `s6ln` 미사용, 생성 변화는 `dsp.h` 뿐 | 상태 도구 77·112 행, `stage_m68k.py` OVL(47 행)·506–530 행 읽음, REGISTRY grep 0 건(이번 세션) | ✅ 그대로 |
| x86 재빌드 판정은 problems 0 만이 아니라 §554 의 요약 비교와 실제 `cmp` | §554 절차(같은 비교를 했음) | ✅ 그대로 |
| 예상 집계(객체 26·행 48/188·39296 B·18.20 %) | — | ⏭️ 수치는 받지 않음; 도구 출력만 적음 |

### 559.2·560.2 결과(2026-10-30)

- 1: x86 07 `driverkit/snd_msgs.h` 619 → 621 행(SHA `f85492cd…`; 이전판 `08_build/artifacts/m4p559/snd_msgs.h.x86.before`), 진단 `snd_msgs97s.h` 와 주석 뺀 토큰 1798 개 같음.
- 2: x86 `s6ln` 일곱 묶음 problems 0, 요약 줄이 `s6lm` 과 같음(로그 비교); prefixdiff(`s6-l2-prefixdiff-s6lm-s6ln-20261030.json`): 스테이징 차이 g1a `src/driverkit/snd_msgs.h` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` `['x86-snd_reply']`(canon·머리·섹션·비 STABS 기호 같음, STABS 수 982 같음); 링크 `s6p559-ln1` `cmp` 원본과 같음(SHA `33469393…`).
- 3: `config_options-m68k.tsv` 13 → 14 행(탭 여섯 칸), 생성 `dsp.h`(`#define NDSP 1`, SHA `e47e758c…`), `--check` 둘 종료 0, 다른 생성 파일 변화 없음(git).
- 4·5: 07 `snd_dspcmd.c`(920 행, SHA `8afb8534…`; 토큰 4260 개가 L 과 같음), `stage_m68k.py` 675 → 677 행(`M4FILES[559]`·`EXCEPTS[559]`·`X86[559]`·머리 목록). §560 은 바탕을 `m0p559-a1-stage` 로 써서 `stage_m68k.py --plan 560` 을 부르지 않으므로 계획에 적은 `EXCEPTS[560]` 은 두지 않았습니다(쓰이지 않는 등록).
- 6: `--plan 556` 재생성(`m0p556-r559-stage`)은 보관본과 `generated/dsp.h`·`src/bsd/nextdev/snd_msgs.h` 만 다름(키 `added` 에 `dsp.h` 가 더해짐); `m0p559-a1-stage`(940 파일)는 보관 556 과 그 둘 + `src/driverkit/snd_msgs.h`·`snd_dspcmd.c` 만 다름(python assert). M5: `m5-556.cmd` 가 §556 것과 `cmp` 같음, run `m3p559-b556`·`m3p559-cc1` 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare` `differ_unexpected`·`lost` 빔, 요약 같음, 새 경로는 `generated/dsp.h`·`snd_dspcmd.c`. x86 입력 `m4-x86-inputs-p559-20261030.json` `ok`, `x86gate` 일곱 같음.
- 7: run `m4p559-p1`(`m4-m68k-probe-p559-p1-20261030.json`): 명령 다섯 종료 0, 경고는 `snd_reply` 의 `kfree` 2 줄(§554 `known_warnings` 와 같은 줄); `snd_dspcmd` F = L = §558 B2(canon·`obj_sig`), 14/14; R: `snd_reply` 21/21·`snd_rcv` 1/1·`snd_device` 15/15, 각각 받아들인 객체와 canon·비 STABS 같고 STABS 수도 같음(1016·621·908). run `m4p559-e1`: `-E` 토큰 16447 개 F = L, `snd_stream_msg_t` 정의 한 번.
- 8: run `m4p559-a1`(`m4-m68k-p559-final-20261030.json`): `gate.ok`, 셋 OBJECT_MATCH; funcbytes 14/14·21/21·1/1; 확인 `m4-m68k-p559-checks-20261030.json`(`ok` 참; 항목은 근거 문서).
- §560: run `m4p560-a1`(`m4-m68k-p560-final-20261030.json`): `gate.ok`, 15/15; zerofill `m4-m68k-zerofill-p560-20261030.json` `reference-inferred` [0x40b507c, 0x40b5090); 확인 `m4-m68k-p560-checks-20261030.json`(`ok` 참): 받아들인 배치 32 개(§556 자기 것 뺌)와 겹침 0, §556 객체와 canon·비 STABS 같음.
- 9: 근거 `06_reconstruction/evidence/m68k-snd_dspcmd.md`(새, 상태 도구 전), diff `m68k-snd_dspcmd.diff`(46 행)·`m68k-snd_msgs_h.diff`(35 행; 554·559 줄 함께로 다시 씀), `m68k-snd_reply.md`·`m68k-snd_rcv.md`·`m68k-snd_device.md` 에 plan 559–560 절. `ACCEPTED`: §554 a2 줄 → §559, §556 넷 묶음 → §560. 상태표(27 → 28 행)·`m4-m68k-status-p560-20261030.json`: 26 객체(OBJECT_MATCH 21, CODE+BSS_INFERRED 5), 덮은 행 48/188, 37246 → 39296/215874 B(18.20%; 행 243 의 최소 바이트 2050 B 만큼 늘고, 객체 바이트는 40492 B), 부분 행 `m68k-244`·`m68k-306`, 두 번 실행 같음, §556 표와 이름 대조로 더한 것 `snd_dspcmd`, 바뀐 것은 `snd_reply`·`snd_rcv`·`snd_device` 의 plan·record·obj_sha256 뿐. PROVENANCE 1150 → 1152 행, MODIFICATIONS 700 → 703 행, DECISIONS D125(128 → 129 행).

## 561. M4-67 세부 계획 — m68k `snd_dspdev.c`(행 244 나머지) NeXTMach 글 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): §557 이 행 244 의 앞 경계를 0x408103e(`_dsp_dev_init`)로 정했고, 그 뒤 14 항목이 NeXTMach mk-108.1 `nextdev/snd_dspdev.c`(1418 행, SHA-256 `936602ce…`)의 정의 순서와 같으며 끝이 `snd_dspqueue.c` 의 첫 외부 함수 `_dspq_init_lmsg`(0x4082764) 앞입니다. §551–560 의 사운드 머리와 생성 `dsp.h` 를 그대로 씁니다.

확인한 사실(이번 세션; 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt` 162768–164515 행(명령 1743 줄 + 안쪽 라벨 5), `03_original/m68k/inventory/symbols.tsv`, `macho.json` 섹션, 원본 `__data`·`__cstring`, python):
- 범위 [0x408103e, 0x4082764), 5926 B, 이어진 14 항목(`m68k-functions.tsv`): `dsp_dev_init` 78, `dsp_dev_reset` 106, `dsp_dev_new_proto` 1748, `dsp_dev_reset_hard` 20, `dsp_dev_reset_chip` 214, 이름 없는 0x40818b4 354, 0x4081a16 238, `dsp_dev_loop` 1782, 이름 없는 0x40821fa 164, 0x408229e 542, 0x40824bc 322, 0x40825fe 204, 0x40826ca 28, 0x40826e6 126. 이름 없는 여덟은 NeXTMach 정의 순서(`snd_dspdev.c:546·629·1093·1157·1235·1342·1389·1402`)로 `dsp_dev_intr`·`dsp_dma_intr`·`dsp_dma_init`·`dsp_dma`·`dsp_dma_cleanup`·`dsp_probe`·`dsp_attach`·`dsp_interrupt` 에 대응. 뒷받침: `_dspdriver` 의 probe·attach·intr 낱말이 0x40825fe·0x40826ca·0x40818b4; 원본 안쪽 호출 수 0x40821fa 2·0x408229e 2·0x40824bc 1·0x40817de 3·0x40826e6 8 이 NeXTMach 의 `dsp_dma_init`(758·855)·`dsp_dma`(833·863)·`dsp_dma_cleanup`(699)·`dsp_dev_reset_chip`(514·602·1358)·`dsp_interrupt`(175·206·375·433·619·659·1223·1359) 호출 수와 같음.
- 행: 범위와 겹치는 행은 `m68k-244`(정확 아님, `start_lo`–`start_hi` 0x4080d58–0x408103e, `end_lo`–`end_hi` 0x4081b04–0x4082764)와 `m68k-245`(`snd_dspqueue.c`, `start_lo`–`start_hi` 0x4081b04–0x4082764) 둘이고 둘 다 범위 밖으로 걸침 → probe 명시 범위 `{"range": ["0x408103e", "0x4082764"], "rows": [], "partial": ["m68k-244", "m68k-245"], "basis": …}`(§537 규칙: `rows` 가 비어도 됨; `m4_m68k_probe.py` `span()` 의 조건을 python 으로 미리 확인). 상태 도구는 부분 행을 덮은 행으로 세지 않으므로(`m4_m68k_status.py` 머리말 "Plan 537"), 이 객체를 받아들여도 덮은 행 수와 백분율은 그대로이고 객체 바이트만 늘어납니다(행 244 는 `snd_dspcmd` 와 이 객체 둘에 걸친 부분 행). 이 셈 규칙을 바꾸는 것은 이 계획에 넣지 않습니다.
- 자료: `__data` [0x40b2192, 0x40b21c8) 54 B = `_dspdriver`(`struct bus_driver` 50 B: `dsp_probe`, 0, `dsp_attach`, 0, 0, `dsp_dev_intr`, 0, 8(`sizeof(struct dsp_regs)`), `"dsp"`(0x40abb5a), `_dsp_dinfo`(0x40c6ed0), 나머지 0 — NeXTMach `snd_dspdev.c:117–120` 꼴) + 0x40b21c4 의 4 B 0xffffffff(`dsp_dev_loop` 의 0x4081b24·0x4081b36·0x40821e8 이 읽고 씀 = NeXTMach 함수 안 `static int dev_loop_ipl = -1;`, 669 행); 0x40b21c8 부터는 다음 객체 몫(외부 기호 없음, 다음 외부 기호 `__NXAudioSndoutDevice` 0x40b220c). `__cstring` [0x40abb5a, 0x40abc23) 201 B: `"dsp"` 와 다섯 문자열 `DSP ABORTED\n`(0x40abb5e)·`DSP DMA write truncated by early complete interrupt!\n`·`dsp_dma: Timed out waiting for TRDY!\n`·`Attempt to use broken 32-bit unpacked DSP DMA\n`·`dsp_dma_cleanup: DSP_hc_HOST_WD looks hung!\n`. `__bss` 정적 없음(NeXTMach 에 초기화 없는 정적 없음). `__common`: `_dsp_var`(0x40c6cfc, 다음 기호 `_snd_var` 까지 396 B), `_dsp_dinfo`(0x40c6ed0). 머리에서 오는 임시 정의 `sys/buf.h:110–120`(`_buf`·`_buffers`·`_nbuf`·`_bufpages`·`_bufhash`·`_bfreelist`·`_swbuf*`·`_nswbuf`)·`kern/cpu_number.h:61` `_master_cpu`·`m68k/bmap.h:55` `_bmap_chip` 은 모두 원본 이름(`_nbuf`·`_bufpages` 는 원본 `__data` — M7 합침 의무, `snd_device` 와 같음).
- 원본에 보이는 1997 바뀜 후보(NeXTMach 대비, 진단에서 확인): ① `dsp_dev_reset` 이 `install_scanned_intr(0xe40 = I_DSP_4, dsp_dev_intr, 0)` 을 부름(0x40810ec; NeXTMach 는 `dsp_attach` 에서만) ② `dsp_dev_loop` 의 0x40820a8 `callout_dispatch(4, snd_reply_dsp_err | snd_reply_dsp_msg, port)`(0x408207c–0x40820a8; 0x4085648·0x408554e 는 `_snd_reply_dsp_err`·`_snd_reply_dsp_msg`) — NeXTMach 은 `softint_sched(CALLOUT_PRI_THREAD, …)`(992–994·1010–1012; §561.1 고침) ③ 문자열: NeXTMach 의 `TREQ GOT CLEARED DURING DMA!`(1273)·`write to DSP looks hung!`(1279)은 `#if DEBUG`(1261–1284) 안이라 원본에 없는 것이 1997 삭제를 뜻하지 않음; 원본의 `dsp_dma: Timed out waiting for TRDY!` 는 NeXTMach 에 없는 새 기다림(0x4082316–0x4082364: 10 번 `delay(1)` 뒤 `printf`). A 의 `__cstring` 은 163 B(원본 201 B)로 예상 ④ `dsp_dev_intr` 첫머리의 `isr` 검사(0x40818c6–0x40818ca, 비트 7 이 0 이면 돌아감; NeXTMach 553 은 소유자·상태 검사부터) ⑤ `dsp_dev_reset_chip`: `dma_chip == 0x139` 에 따라 `*scr2` 비트 0x20 을 켜거나 끄는 갈래 두 쌍, `icr` 를 맨 끝에 지움(0x40817de–0x40818a4; NeXTMach 530–539 는 `icr = 0` 이 처음) ⑥ `dsp_dma_intr` 의 TRDY 기다림이 200 번 `delay(2)`(0x4081a34–0x4081a62; NeXTMach 640–641 은 10 번 `DELAY(1)`) ⑦ `dsp_interrupt` 는 `dma_chip == 0x139` 일 때만 `*scr2` 를 고침(0x40826fc–0x408273e; NeXTMach 1407–1414 는 늘). `dsp_dma` 의 차례 바뀜 여부는 진단에서 봄.
- 부르는 것(원본): `delay` 6·`printf` 5·`dma_abort` 2·`dma_dequeue` 4·`dma_enqueue` 2·`dma_init` 2·`install_scanned_intr` 2·`kalloc` 1·`kfree` 3·`softint_run` 1·`callout_dispatch` 1·`snd_link_init` 2·`snd_link_shutdown` 2·`snd_stream_queue_reset` 3·`dspq_*` 12 개 이름·호출 18 곳(`bsr` 16 + `dspq_enqueue_cond` 의 `jsr a2@` 2, 0x4082592·0x40825a6)·`curipl`(0x40013c4, `jsr a2@`). 외부 자료: `_dsp_var` 136·`_slot_id_bmap` 50(`P_DSP`)·`_scr2` 17·`_dma_chip` 8·`_bmap_chip` 4·`_board_rev`·`_machine_type`·`_intrstat` 각 2·`_cpu_type`·`_slot_id`·`_snd_var` 각 1, 함수 주소로 `dspq_start_complex`·`dspq_start_simple`·`dspq_enqueue_cond`·`snd_reply_dsp_err`·`snd_reply_dsp_msg`.
- 머리: NeXTMach 은 `<dsp.h>`(스테이지 생성 `NDSP 1`, §559), `<kern/xpr.h>`, `<sys/buf.h>`, `<sys/param.h>`, `<kern/thread.h>`, `<sys/callout.h>`(07 사본), `<sys/machine.h>`(스테이지에 없음; §529 `kern_machdep.c` 는 `<mach/machine.h>`), `<vm/vm_param.h>`, `<next/autoconf.h>`(07 사본, 스테이지 `src/bsd/next/autoconf.h`; `autoconf.c`·`dma.c` 가 그대로 씀), `<next/cpu.h>`(D109: 어셈블리 전용), `<next/pmap.h>`, `<next/scr.h>`(스테이지에 없음), `<next/bmap.h>`, `<nextdev/snd_var.h>`, `<nextdev/snd_dsp.h>`, `<nextdev/snd_dspreg.h>`, `<machine/spl.h>` 를 들임. `next/cpu.h` 이름 `P_DSP`(`SLOT_ID_BMAP+0x02008000`)·`P_DSP_CSR`(`SLOT_ID+0x020000d0`)·`I()`·`I_BIT()`·`I_DSP_DMA`(`I(6,9,20)`)·`I_DSP_4`(`I(4,0,14)`)는 `07_kernel/nextmach/next/cpu.h:138·152·213·216·234·246`, `NeXT_CUBE` 0 은 NeXTMach `next/scr.h:34`; `machine_type`·`board_rev`·`cpu_type`·`dma_chip`·`MC68030` 은 SDK `m68k/cpu.h`(스테이지 `src/bsd/m68k/cpu.h:48–58`). 원본 `dsp_dev_init` 의 `dc_ddp = slot_id + 0x20000d0`(0x4081042–0x408104e)이 `P_DSP_CSR` 와 맞음.

방법(진단; 명세 `08_build/artifacts/m4p561/spec.json`, run `m4p561-p1`, 바탕 `m0p559-a1-stage`, 위 명시 범위, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 변형 A(`08_build/artifacts/m4p561/src/snd_dspdev_A.c`, 07 아님): NeXTMach 글에서 include 줄만 바꾼 꼴 — `<sys/machine.h>` → `<mach/machine.h>`(§529), `<vm/vm_param.h>` → `<mach/vm_param.h>`, `<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<next/pmap.h>` → `<vm/pmap.h>`(§556), `<next/bmap.h>` → `<m68k/bmap.h>`(D105), `<nextdev/snd_dspreg.h>` → `<dev/m68k/snd_dspreg.h>`(D107), `<next/scr.h>` 는 뺌; 파일 안에 진단 이름 덩이 하나(`extern int slot_id, slot_id_bmap;`, 매크로 여덟 `SLOT_ID`·`SLOT_ID_BMAP`·`P_DSP_CSR`·`P_DSP`·`I`·`I_BIT`·`I_DSP_DMA`·`I_DSP_4`(값은 `07_kernel/nextmach/next/cpu.h`), `#define NeXT_CUBE 0`; 스테이지 `dma.c:72–79` 와 같은 식). `<next/autoconf.h>` 는 그대로. 본문은 NeXTMach 그대로(`curipl`·`softint_run` 은 NeXTMach 처럼 선언 없이).
- 측정: `m4_m68k_probe.py compare`(경고 기록), `m68k_funcbytes.py 408103e 4082764 OBJECT.o RECORD.json 40818b4=_dsp_dev_intr 4081a16=_dsp_dma_intr 40821fa=_dsp_dma_init 408229e=_dsp_dma 40824bc=_dsp_dma_cleanup 40825fe=_dsp_probe 40826ca=_dsp_attach 40826e6=_dsp_interrupt` 과 `40b21c4=<결과의 dev_loop_ipl 지역 이름>`; 섹션 크기(`__text` 5926·`__data` 54·`__cstring` 201·`__bss` 0), `__data` 의 재배치 아닌 바이트와 원본 대조 및 재배치 다섯(`__text` 의 probe·attach·`dsp_dev_intr`, `__cstring+0`, `_dsp_dinfo`)의 대상, `__cstring` 바이트·순서, COMMON 이름과 크기(`_dsp_var` 의 크기와 396 B 간격), 원본에 없는 정의·미정의 기호. 다른 함수는 실기 `otool -tv` 명령 비교로 첫 차이와 원인을 적음.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고(funcbytes 는 `__text` 만 보므로 14/14 만으로는 부족, 자료 확인을 함께), 다른 함수는 다음 계획에서 원본 바이트로 1997 꼴을 써서 시험합니다(위 ①–③ 은 다를 것으로 예상). 14/14 이고 자료가 같으면 바이트로 정해지지 않는 것(이름 공급 꼴, include 꼴)을 사용자께 여쭙니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄. 경고는 기록만 함(`diag_gate.commands_ok` 는 경고 0 을 요구하므로 경고가 있으면 거짓으로 나오며, 이를 결과에 그대로 적음; `refs` 없는 `compare` 의 종료 0 은 일치가 아님, `m4_m68k_probe.py:382–383`).

### 561.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 진단 덩이에 `SLOT_ID`·`SLOT_ID_BMAP` 이 없으면 `P_DSP`·`P_DSP_CSR` 가 풀리지 않음; "일곱" 은 실제 여섯 | `07_kernel/nextmach/next/cpu.h:96·98·138·152`(이번 세션 grep), 스테이지 `src/machdep/m68k/dma.c:72–79` 읽음 | ✅ 제 누락. 매크로 여덟을 이름으로 적음 |
| NeXTMach 은 `snd_reply_dsp_*` 를 바로 부르지 않고 `softint_sched(CALLOUT_PRI_THREAD, …)` 에 넘김; 원본은 `callout_dispatch(4, …)` | NeXTMach `snd_dspdev.c:988–1013` 읽음, 원본 0x4082072–0x40820b2 읽음 | ✅ 제 오기(grep 줄 번호만 보고 적음). ② 고침 |
| 없는 두 문자열은 `#if DEBUG` 안; A 문자열 163 B 예상 | NeXTMach 1258–1285 읽음, python 4+13+54+47+45 = 163, 원본 201 | ✅ ③ 고침 |
| 더 보이는 차이: `dsp_dev_intr` 첫 `isr` 검사, `reset_chip` 의 `dma_chip` 갈래와 끝의 `icr` 지움, `dma_intr` 200×`DELAY(2)`, `dsp_dma` 의 기다림, `dsp_interrupt` 의 `dma_chip == 313` | 원본 0x40818b4–0x40818d4, 0x40817de–0x40818a4, 0x4081a34–0x4081a64(python `~55 & 0xff` = 200), 0x4082310–0x4082366, 0x40826e6–0x4082740 읽음; NeXTMach 546–556·521–540·636–645·1402–1415 읽음 | ✅ ④–⑦ 로 더함 |
| `dsp_dma` 의 enqueue·레지스터 설정 차례도 바뀜 | 원본 해당 구간을 아직 NeXTMach 과 줄 단위로 대조하지 않음 | ⚖️ 진단 결과로 확인(사실 줄에는 "진단에서 봄") |
| COMMON: `sys/buf.h` 임시 정의·`_master_cpu`·`_bmap_chip` 도 생기며 모두 원본 이름; `_nbuf`·`_bufpages` 는 원본 `__data` | 스테이지 `sys/buf.h:110–120`, `kern/cpu_number.h:61`, `m68k/bmap.h:55` 읽음, `symbols.tsv` grep(섹션 4·6) | ✅ 사실 줄에 더함 |
| `_dsp_var` 396 B·`_dsp_dinfo` 4 B 는 머리 배치의 예측; 원본 기호표는 크기를 증명하지 않음 | 계획은 "다음 기호까지 간격" 으로 적었음 | ✅ 그대로(측정은 COMMON 크기와 간격 비교) |
| funcbytes 는 `__text` 만 봄 → 자료 확인 따로; `diag_gate` 는 경고 0 을 요구 | `m4_m68k_probe.py:382–383` 읽음 | ✅ 판정·관문 문구 고침 |
| `dspq_*` 는 12 이름·18 곳(간접 `jsr a2@` 2 포함) | python(`bsr` 16, 12 이름), 원본 0x408258c–0x40825a6 읽음 | ✅ 고침 |
| 행 경계는 `start_lo/start_hi`·`end_lo/end_hi` 로 적을 것 | `m2_m68k_objects.py:9–12` 읽음 | ✅ 고침 |
| 경계·크기·이름 없는 여덟 대응·`__data` 54 B·`__cstring` 201 B·`install_scanned_intr(0xe40…)`·`span()`·상태 도구 셈은 맞음 | 이번 세션 python 과 목록(위 사실 줄의 방법) | ✅(제 확인과 같음) |
| `xprflags`·`ASSERT`·`func`·`bus_*`·`spl*`·DMA 선언·CPU 전역은 스테이지에서 풀리고 i386 머리를 끌어오지 않음 | `generated/xpr_debug.h:1`(`XPR_DEBUG 0`) 읽음, M5 줄에 `-W` 없음(grep); 나머지 사슬은 진단의 실제 컴파일·의존 목록으로 확인 | ⚖️ 진단 컴파일·의존 목록이 판정 |

### 561.2 결과(2026-10-30)

- run `m4p561-p1`(A, 기록 `09_validation/reconstruction/m4-m68k-probe-p561-20261030.json`): 컴파일·의존 목록 종료 0, i386 머리 0, 옵션 차이 없음. 경고 3 줄(`dsp_dev_new_proto` 의 `kfree` 인자 형, 370·462·486 행; `snd_reply` 와 같은 꼴)이라 `diag_gate.commands_ok` 는 거짓. 섹션 `__text` 5730(원본 5926)·`__data` 54·`__cstring` 163(§561.1 예상과 같음), `__bss` 없음. `__data` 안 차례 `_dspdriver` +0·지역 `_dev_loop_ipl.40` +0x32(원본과 같은 차례). COMMON `_dsp_var` 396(원본 간격과 같음)·`_dsp_dinfo` 4 와 머리 임시 정의(`_buf`·`_bufhash`·`_master_cpu`·`_bmap_chip` 등), 원본에 없는 미정의 0.
- **5/14**(`m4-m68k-funcbytes-p561-A-20261030.json`, 대응 여덟 + `40b21c4=_dev_loop_ipl.40`): 같은 것 `dsp_dev_init`·`dsp_dev_reset_hard`·`dsp_dma_cleanup`·`dsp_probe`·`dsp_attach`. 실기 `otool -tv`(`08_build/artifacts/m4p561/otool/snd_dspdev_A.txt`)와 원본 목록의 명령 비교로 본 다른 아홉(원본 주소):
  - `dsp_dev_reset`(106 대 88): 끝에 `install_scanned_intr(I_DSP_4, dsp_dev_intr, 0)`(0x40810e0–0x40810ec).
  - `dsp_dev_new_proto`(1748 대 1676): TXD 덩이가 `s = splhigh()` … `splx(s)` 안(0x408170c–0x4081778)이고, 켤 때·끌 때 각각 `dma_chip != 313` 이면 `*scr2` 비트 23(0x00800000)을 켜거나 끈 뒤 NeXTMach 의 `bmap_chip` 줄. 비트 23 은 NeXTMach `next/scr.h:68–90` 의 `struct scr2` 에서 `s_dram_256K` 칸이고 07·SDK 머리에 이름 없음.
  - `dsp_dev_reset_chip`(214 대 166): 처음의 `regs->icr = 0` 이 `splx` 앞 끝으로(0x4081898–0x40818a4); `DSP_SCR2_MEMEN` 두 곳이 `if (dma_chip == 313) 켬/끔 else 반대`(0x4081810–0x4081834·0x4081872–0x4081896).
  - `dsp_dev_intr`(354 대 346): 첫머리 `if (!(regs->isr & ISR_HREQ)) return;`(0x40818c6–0x40818ca, `bge` 로 공통 끝 0x4081a0e).
  - `dsp_dma_intr`(238 대 236): `for (i = 200; …; i--) DELAY(2);`(0x4081a34 `moveq #55; notb` = 200, 0x4081a44 `pea 0x2`).
  - `dsp_dev_loop`(같은 길이, 참조 1): `softint_sched` 대신 `callout_dispatch`(0x40820a8; 인자 `CALLOUT_PRI_THREAD`(4)·함수·포트는 같음).
  - `dsp_dma_init`(바이트 1): `dma_chip <= 313` → `dma_chip == 313`(0x4082258 `bne`; A 는 `bhi`).
  - `dsp_dma`(542 대 514): "Blammo" `regs->icr = 0` 없음; `dh_flags` 다음에 `if ((mode == DSP_MODE8 || mode == DSP_MODE16) && direction == DMACSR_WRITE)`(0x4082304–0x4082312) 안에서 `for (n = 10; n && !(regs->isr & ISR_TRDY); n--) DELAY(1);` → `n == 0` 이면 `printf("dsp_dma: Timed out waiting for TRDY!\n")` → MODE8 이면 `txh = 0; txm = 0;`, MODE16 이면 `txh = 0;`(0x4082316–0x408239a); 그다음 `s = spldsp(); dsp_interrupt(DSP_INT_DISABLE); dma_enqueue(&dsp_var.dma_chan, &ddp->hdr);`(0x408239e–0x40823ba), 이어 `switch (mode)` 각 갈래에서 `regs->icr` 를 한 번만(`preinit|ICR_HM0|ICR_HM1`·`preinit|ICR_HM1`·`preinit|ICR_HM0`; `init` 쓰기 없음, `txh`·`txm` 지움 없음; MODE24·32 의 `splhigh` 덩이는 NeXTMach 처럼 조건 없음, MODE32 의 `printf` 만 `dma_chip == 313` 일 때(0x408247e; NeXTMach `<= 313`); §562.1 고침), 끝에 `regs->icr |= ICR_HF1; splx(s);`(두 번째 `spldsp()` 없음).
  - `dsp_interrupt`(126 대 106): `*scr2` 를 켜고 끄는 줄이 `dma_chip == 313` 일 때만(0x40826fc–0x408273e).
- 판정(미리 정한 대로): 07 은 바꾸지 않고, 다른 아홉의 1997 꼴을 다음 계획에서 원본 바이트로 써서 시험합니다.

## 562. M4-68 세부 계획 — `snd_dspdev.c` 1997 꼴 진단(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p562/spec.json`, run `m4p562-p1`, 바탕 `m0p559-a1-stage`, §561 명시 범위):
- 변형 B1·B2(`08_build/artifacts/m4p562/src/snd_dspdev_B1.c`·`_B2.c`): §561 A 에 §561.2 의 아홉 함수 바뀜만 원본 바이트대로 넣은 것. 그 밖의 줄은 A(= NeXTMach + include 줄 + 진단 이름 덩이) 그대로. 꼴:
  - `dsp_dev_reset`: `dsp_interrupt(DSP_INT_DISABLE);` 뒤 `install_scanned_intr(I_DSP_4, (func)dsp_dev_intr, 0);`(NeXTMach `dsp_attach` 의 줄과 같은 꼴).
  - `dsp_dev_new_proto`: `if (bmap_chip) { … }` 를 `s = splhigh(); if (new_proto&SND_DSP_PROTO_TXD) { if (dma_chip != 313) *scr2 |= 0x00800000; if (bmap_chip) bmap_chip->bm_dsp_txd_int = 1; } else { if (dma_chip != 313) *scr2 &= ~0x00800000; if (bmap_chip) bmap_chip->bm_dsp_txd_int = 0; } splx(s);` 로(비트는 숫자 그대로, 이름은 나중에 여쭘). 함수의 기존 변수는 `int s, s1;`(A 228 행)이고 앞의 `splx(s)`(NeXTMach 480 행) 뒤라 어느 쪽을 썼는지 글로는 정해지지 않으므로 B1 은 `s1`, B2 는 `s` 를 씀(그 밖은 B1 과 같음; §562.1).
  - `dsp_dev_reset_chip`: 위 §561.2 차례(`regs->icr = 0;` 을 `splx(s)` 앞으로, MEMEN 두 곳을 `dma_chip == 313` 갈래로).
  - `dsp_dev_intr`: 함수 첫 문장으로 `if (!(regs->isr & ISR_HREQ)) return;`.
  - `dsp_dma_intr`: `i = 200`, `DELAY(2)`.
  - `dsp_dev_loop`: `softint_sched` 두 곳을 `callout_dispatch` 로, 파일 안에 `extern void callout_dispatch();`(§556 `snd_device.c` 와 같은 K&R 선언; 진단).
  - `dsp_dma_init`: `dma_chip <= 313` → `dma_chip == 313`.
  - `dsp_dma`: §561.2 차례대로(`int init` 선언은 NeXTMach 그대로 두어 쓰이지 않음; `regs->icr` 읽기는 `preinit` 에서 한 번), MODE8/16 의 `txh`·`txm` 지움은 기다림 덩이 안 `if (mode == DSP_MODE8) {…} else if (mode == DSP_MODE16) …` 꼴.
  - `dsp_interrupt`: `*scr2` 줄 둘을 `if (dma_chip == 313)` 안으로.
- 측정: §561 과 같음(`m4_m68k_probe.py compare`, funcbytes 같은 대응(지역 이름은 결과에서), `otool -tv` 비교, 섹션·`__data` 바이트와 재배치 다섯·`__cstring` 201 B 와 원본 바이트·COMMON·미정의).
판정(미리 정함; 07 은 바꾸지 않음): 14/14 이고 `__data`·`__cstring` 이 원본과 같으면 바이트로 정해지지 않는 것(비트 23 의 이름, `callout_dispatch` 선언 꼴, `dsp_dma` 의 쓰이지 않는 `init`, `next/cpu.h`·`next/scr.h` 이름과 `next/autoconf.h` 의 공급 꼴, `kfree` 경고 처리)을 사용자께 여쭙니다. 다른 함수가 남으면 차이를 적고 꼴을 바꿔 다시 시험합니다(B2…).
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록(A 와 같은 `kfree` 3 줄 밖의 경고가 생기면 원인을 적음).

### 562.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `dsp_dma` 의 MODE24·32 `splhigh` 덩이(0x4082418–0x408247a)는 칩 검사 없이 늘 실행, `cmpw #0x139` 는 0x408247e 의 `printf` 앞 하나뿐 | 원본 0x4082410–0x4082494 의 `cmpw`·`movew`·`bsr` 줄 추출(이번 세션) | ✅ 제 문구 오류. §561.2 고침 |
| `dsp_dev_new_proto` 의 변수는 `register int s` 가 아니라 `int s, s1;` | A 228 행 읽음, `s`·`s1` 쓰임(281·383–444·490 행) grep | ✅ 제 오기. B1(`s1`)·B2(`s`) 로 나눔 |
| `new_proto` 의 새 임계 구역(0x408170e `0x2700`)은 앞의 LINKIN 처리 뒤, `splx` 는 0x4081778 이고 그 뒤 RREQ 처리는 구역 밖 | 원본 0x40816f2–0x408178c 읽음(이번 세션) | ✅ 계획 꼴과 같음 |
| `dsp_dma` 의 MODE8/16 쓰기 조건, TRDY 기다림(10·`DELAY(1)`), `txh`→`txm` 지움, `spldsp`→`dsp_interrupt(1)`→`dma_enqueue`, 갈래당 `icr` 한 번, 두 번째 `spldsp` 없음 | 원본 0x408229e–0x40824ba 전체 읽음(이번 세션) | ✅ 계획 꼴과 같음 |
| `reset_chip` 끝은 `icr = 0`(0x40818a4) 다음 `splx`(0x40818aa) | 원본 0x40818a4–0x40818b2 읽음 | ✅ |
| `dsp_dev_reset`·`dsp_dev_intr`·`dsp_dma_intr`·`dsp_dev_loop`·`dsp_dma_init`·`dsp_interrupt` 의 꼴은 원본과 맞음 | §561.2 를 쓸 때 읽은 원본 줄(이번 세션)과 같음; 바이트 같음은 B 진단으로 | ✅(바이트는 진단으로) |

### 562.2 결과(2026-10-30)

- run `m4p562-p1`(B1·B2, 기록 `m4-m68k-probe-p562-20261030.json`): 종료 0, i386 머리 0, 옵션 차이 없음, 경고는 A 와 같은 `kfree` 3 줄씩. 둘 다 `__text` 5926. B1(`s1`) 12/14: `dsp_dev_new_proto`(바이트 75·참조 6)·`dsp_dma`; B2(`s`) 13/14: `dsp_dma` 만(길이 같음, 바이트 36·참조 2) → `new_proto` 의 새 구역은 `s` 를 씀.
- B2 의 `dsp_dma` 차이(실기 `otool -tv` `08_build/artifacts/m4p561/otool/snd_dspdev_p562B2.txt`)는 레지스터 배정뿐: 원본은 TRDY 기다림의 셈(0x4082316 `movew #0xa,a2`)과 MODE24·32 의 `splhigh` 값(0x408241e·0x4082452 `movew d0,a2`)이 같은 a2, `s` 는 a5 → 기다림 고리가 `n` 이 아니라 `i` 를 쓴 꼴. §562 판정(꼴을 바꿔 다시)에 따라 B3 = B2 에서 기다림 변수만 `i` 로(`08_build/artifacts/m4p562/src/snd_dspdev_B3.c`, 명세 `spec-p2.json`).
- run `m4p562-p2`(B3, 기록 `m4-m68k-probe-p562-p2-20261030.json`): 종료 0, 경고 `kfree` 3 줄, i386 머리 0, 옵션 차이 없음. **14/14**(`m4-m68k-funcbytes-p562-B3-20261030.json`), L1 `OBJECT_MATCH`(사유 없음), `full_span` 참, `candidate`, 원본에 없는 이름 0.
- python 확인(`m4-m68k-p562-checks-20261030.json`, `ok` 참): 섹션 `__text` 5926·`__data` 54·`__cstring` 201(`__bss` 없음); `__data` 의 재배치 아닌 바이트가 원본 [0x40b2192, 0x40b21c8) 와 같고 재배치 다섯(probe 0x40825fe·attach 0x40826ca·`dsp_dev_intr` 0x40818b4·`"dsp"` 0x40abb5a·`_dsp_dinfo` 0x40c6ed0)이 원본 낱말과 같음; `__cstring` 201 B 가 원본과 같음; COMMON 14 개 모두 원본 이름(`_dsp_var` 396 = 원본 간격); 미정의 39 개 모두 원본에 있음; 지역 함수 여덟·지역 자료 `_dev_loop_ipl.40`, 외부 정의 일곱(함수 여섯 + `_dspdriver`).
- 판정(미리 정한 대로): 14/14 이고 자료가 같으므로, 바이트로 정해지지 않는 것을 사용자께 여쭙니다. 앞선 결정을 그대로 따를 것(묻지 않음): `next/cpu.h`·`next/scr.h` 이름은 파일 안(D113·D121), include 줄은 OPENSTEP 경로(D104·D105·D107·D110), `callout_dispatch` 는 K&R `extern` 선언(D124 `snd_device.c`). 여쭐 것: ① `*scr2` 비트 23(0x00800000)의 꼴 ② `kfree` 경고 3 줄의 처리 ③ `<next/autoconf.h>` 의 공급(07 NeXTMach 사본 그대로 / SDK `<dev/m68k/autoconf.h>`) ④ `dsp_dma` 에서 1997 에 쓰이지 않게 된 `int init` 선언.
- 사용자 결정(2026-10-30, AskUserQuestion): ① 비트 23 은 "파일 안 매크로 이름"(질문에 보인 예 `DSP_SCR2_TXDEN` 0x00800000; 이름은 작성(D024), 뜻은 바이트로 확인되지 않음) ② `kfree` 경고는 "글 그대로 + known_warnings" ③ `<next/autoconf.h>` 는 "NeXTMach 사본 그대로" ④ `int init` 은 "NeXTMach 그대로 둠"(1997 에 쓰이지 않는다는 주석).

## 563. M4-69 D126 구현 계획 — 07 `src/machdep/m68k/snd_dspdev.c`(코딩 전, 2026-10-30)

확인한 사실(이번 세션): §561–562 결과와 결정. `stage_m68k.py` 는 `M4FILES`·`M4HEADERS`·`X86` 을 PLAN 이하 최대 키로, `EXCEPTS` 는 정확한 키로 고름(§556·§559 에서 확인); 등록 안 된 `.c` 를 거부. 이 계획은 07 머리를 고치지 않으므로 받아들인 기록의 plan 506 검사에 영향 없음.
1. 07 `src/machdep/m68k/snd_dspdev.c`(D103) = NeXTMach `nextdev/snd_dspdev.c`(고지·HISTORY 그대로) + 머리 주석(1997 바뀜 아홉의 목록과 근거·지운 include) + include 줄(D104·D105·D107·D110 의 경로, `<next/scr.h>` 는 뺌, `<next/autoconf.h>` 는 그대로) + 파일 안 이름 덩이(`next/cpu.h`·`next/scr.h` 이름: `slot_id`·`slot_id_bmap` 선언, `SLOT_ID`·`SLOT_ID_BMAP`·`P_DSP_CSR`·`P_DSP`·`I`·`I_BIT`·`I_DSP_DMA`·`I_DSP_4`·`NeXT_CUBE`; 새 `DSP_SCR2_TXDEN` 0x00800000 은 작성 이름이라는 주석) + `extern void callout_dispatch();` + B3 의 아홉 함수 바뀜(표시 plan 563, D126, D024) + `dsp_dma` 의 `init` 에 주석. 진단 문구는 빼고, 본문은 B3 와 `0x00800000` → `DSP_SCR2_TXDEN` 둘만 다름(python: 주석 뺀 토큰 비교에서 새 `#define DSP_SCR2_TXDEN` 줄을 뺀 뒤 그 두 자리만 다름; `-E` 비교는 `#` 줄 지시를 뺌).
2. `stage_m68k.py`: `M4FILES[563]` = 559 + `snd_dspdev.c`, `EXCEPTS[563] = dict(EXCEPTS[559])`, 머리말 plan 목록에 563; `M4HEADERS`·`X86` 은 그대로(563 은 559 의 것과 s6ln).
3. 회귀: `--plan 559` 재생성(`m0p559-r563-stage`)이 보관 `m0p559-a1-stage` 와 모든 키가 같음; `m0p563-a1-stage` 와 보관 559 의 차이는 `src/machdep/m68k/snd_dspdev.c` 하나(python assert). M5 205 줄: `m5-559.cmd` 가 §559 것과 `cmp` 같음, run `m3p563-b559`(보관 559 스테이지)·`m3p563-cc1`(563 스테이지) 객체 205 바이트 같음·stderr 205 같음, `compare` 두 기록의 `differ_unexpected`·`lost` 빔과 요약 같음. x86 입력 `m4_x86_inputs.py s6ln`(환경 변수 `L2_FORMS`·`L2_EXPECT`)·`--plan 563 x86gate` 일곱 같음.
4. (07 파일은 p1 전에 고정; `known_warnings` 는 p1 F 의 stderr 네 줄 — 함수 문맥 줄 포함 — 을 그대로) 확인 run `m4p563-p1`(`08_build/artifacts/m4p563/confirm/spec.json`, 바탕 `m0p563-a1-stage`): F = `@machdep/m68k/snd_dspdev.c`, L = §562 B3 글 그대로. 종료 0, 경고는 `kfree` 3 줄씩, i386 머리 0, F = L(canon·`obj_sig`)·14/14·`OBJECT_MATCH`. run `m4p563-e1`: F·L 의 `-E` 토큰이 같음(매크로가 펼쳐지므로).
5. 최종 run `m4p563-a1`(명세 `08_build/artifacts/m4p563/spec.json`: F 만, REF = p1 L, `known_warnings["snd_dspdev"]` = p1 F 의 stderr 줄 그대로, §561 명시 범위): `gate.ok`, 옵션 차이 없음(따로 확인); funcbytes 14/14; python 확인 `m4-m68k-p563-checks-20261030.json`: §562 확인 항목(섹션·`__data` 바이트와 재배치 다섯·`__cstring`·COMMON·미정의·지역/외부 정의), L1 0x408103e `OBJECT_MATCH` 사유 없음, 의존 목록 i386 0, 입력 SHA-256 사슬 07 = 스테이지 = run(`07_kernel/src/machdep/m68k/snd_dspdev.c`, `07_kernel/nextmach/nextdev/snd_var.h`, `07_kernel/src/driverkit/snd_msgs.h`(스테이지 `src/bsd/nextdev/snd_msgs.h`), `07_kernel/nextmach/nextdev/snd_dsp.h`, `07_kernel/nextmach/nextdev/snd_dspreg.h`, `07_kernel/nextmach/nextdev/dma.h`, `07_kernel/nextdev/bsd/dev/m68k/dma.h`(앞 머리가 들임), `07_kernel/nextmach/next/autoconf.h`(plan 526 의 07 사본), `07_kernel/nextmach/sys/callout.h`, `07_kernel/nextmach/next/bmap.h`, 생성 `07_kernel/v183.34/m68k/generated/dsp.h`).
6. 상태표(예상 보충: `object_match` 도 하나 늘고 `partial_rows` 에 `m68k-245` 가 더해짐): 근거 `06_reconstruction/evidence/m68k-snd_dspdev.md` 를 먼저 쓰고 `ACCEPTED` 에 (최종 기록, SHA) 한 줄; 상태 도구 두 번 실행·§560 표와 이름 대조(더한 것 `snd_dspdev` 뿐, 바뀐 것 없음). 예상: 부분 행 `m68k-244`·`m68k-245` 라 덮은 행 수·바이트·백분율은 그대로이고 객체 수와 `object_bytes` 만 늘어남(수치는 도구 출력만 적음).
7. 기록: diff(NeXTMach 대비 `m68k-snd_dspdev.diff`), PROVENANCE 새 행(§559 `snd_dspcmd.c` 행 꼴: NeXTMach 저장소·커밋 `f6bdb9c3…`·`mk-108.1/nextdev/snd_dspdev.c`, 고지(D013), 함수별로 NeXTMach 그대로 다섯·바이트로 고친 아홉, 파일 안 이름의 출처 `mk-108.1/next/cpu.h:138·152·213·216·234·246`(NeXT 1986·UCB 고지)·`next/scr.h:34`, 작성 이름 `DSP_SCR2_TXDEN`, 파일 SHA·받아들인 기록·`M4FILES[563]`), MODIFICATIONS, DECISIONS D126, 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: `_nbuf`·`_bufpages` 임시 정의와 원본 `__data` 합침(§556 과 같음), 다른 객체의 `dspq_*`·`snd_link_*`·`snd_reply_dsp_*`·`callout_dispatch`·`curipl`·`softint_run`.
관문: 명령 종료 0, 정한 경고뿐, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 563.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| PROVENANCE 행에 저장소·커밋·경로·고지·함수별 출처·파일 안 이름의 출처(`next/cpu.h` 의 NeXT·UCB 고지, `next/scr.h:34`)를 적을 것 | `PROVENANCE.tsv:1` 머리·1151 행(`snd_dspcmd.c`) 읽음, `np.c`·`autoconf.c` 행의 파일 안 이름 기록 grep, NeXTMach `next/cpu.h:1·23` 읽음 | ✅ 7 고침 |
| 사슬의 `dma.h` 는 둘(`nextmach/nextdev/dma.h` → `nextdev/bsd/dev/m68k/dma.h`), `snd_msgs.h` 의 출처는 `07_kernel/src/driverkit/snd_msgs.h` | 스테이지 `snd_var.h:24`·`nextdev/dma.h:49` 읽음, `m0p559-a1-stage.manifest.json` 의 출처 열 출력 | ✅ 5 고침 |
| 토큰 비교에서 새 `#define` 줄을 빼고, `-E` 비교에서 줄 지시를 뺄 것 | — | ✅ 1 고침 |
| `M4HEADERS` 는 556 을, `X86` 은 559 를 이음; `EXCEPTS[563]` 필요 | `stage_m68k.py` `M4HEADERS[` grep(마지막 556), 395 행 `X86` | ✅ 그대로 |
| `known_warnings` 는 stderr 네 줄(함수 문맥 줄 포함) 그대로; 07 파일은 p1 전에 고정 | `m4p562-p2/stage/_log/00.err` 네 줄(이번 세션 `wc -l` 4) | ✅ 4 고침 |
| 상태: 덮은 행·백분율 그대로, `object_match` +1, `partial_rows` 에 `m68k-245` | `m4_m68k_status.py` 집계 줄(이번 세션 읽음) | ✅ 6 보충(수치는 도구 출력만 적음) |

### 563.2 결과(2026-10-30)

- 1: 07 `src/machdep/m68k/snd_dspdev.c`(1476 행, SHA `daff1b93…`): B3 와 주석 뺀 토큰 6518 개 가운데 `DSP_SCR2_TXDEN`/`0x00800000` 두 자리만 다름(새 `#define` 줄 뺀 비교, python). diff `06_reconstruction/evidence/m68k-snd_dspdev.diff`(294 행).
- 2: `stage_m68k.py` 677 → 679 행(`M4FILES[563]`·`EXCEPTS[563]`·머리말 목록).
- 3: `--plan 559` 재생성(`m0p559-r563-stage`)이 보관 `m0p559-a1-stage` 와 모든 키·파일이 같음; `m0p563-a1-stage`(941 파일)와 보관 559 의 차이는 `snd_dspdev.c` 하나(키는 `plan`·`m4_sources`). M5: `m5-559.cmd` 가 §559 것과 `cmp` 같음, run `m3p563-b559`·`m3p563-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p563-compare-20261030.json`, `-b559-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 새 경로 `snd_dspdev.c` 뿐. x86 `m4-x86-inputs-p563-20261030.json` `ok`, `--plan 563 x86gate` 일곱 같음·`v183_paths` 0.
- 4: run `m4p563-p1`(`confirm/spec.json`, `m4-m68k-probe-p563-p1-20261030.json`): F·L 종료 0, `kfree` 경고 3 개(stderr 4 줄)씩, OBJECT_MATCH, F = L = §562 B3(canon·`obj_sig`), 14/14(`m4-m68k-funcbytes-p563-F/L-20261030.json`). run `m4p563-e1`: `-E` 토큰 19356 개 F = L, i386 머리 0.
- 5: run `m4p563-a1`(`m4-m68k-p563-final-20261030.json`, SHA `9ffd1ba3…`): `gate.ok`(경고는 `known_warnings` 네 줄과 같음), 옵션 차이 없음, 14/14(`m4-m68k-funcbytes-p563-a1-20261030.json`); 확인 `m4-m68k-p563-checks-20261030.json`(`ok` 참; 항목은 근거 문서): 의존 124 파일·i386 0, 입력 사슬 열하나. 객체 SHA `c96da82a…`.
- 6: 근거 `06_reconstruction/evidence/m68k-snd_dspdev.md`(상태 도구 전). `ACCEPTED` 에 한 줄. 상태표 28 → 29 행·`m4-m68k-status-p563-20261030.json`: 27 객체(OBJECT_MATCH 22, CODE+BSS_INFERRED 5), 덮은 행 48/188, 39296/215874 B(18.2%; python `round(100*39296/215874, 2)` = 18.2), 부분 행 `m68k-244`·`m68k-245`·`m68k-306`, `object_bytes` 40492 → 46418(+5926, python), 두 번 실행 같음, §560 표와 이름 대조로 더한 것 `snd_dspdev` 뿐·바뀐 것 없음.
- 7: PROVENANCE 1152 → 1153 행(7 칸), MODIFICATIONS 703 → 704 행, DECISIONS D126(129 → 130 행), "현재 상태와 다음 일" 고침.

## 564. M4-70 세부 계획 — m68k `snd_dspqueue.c`(행 245 나머지) NeXTMach 글 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): §563 이 행 245 의 앞 경계를 0x4082764(`_dspq_init_lmsg`)로 정했고, 그 뒤 22 항목이 NeXTMach mk-108.1 `nextdev/snd_dspqueue.c`(1571 행, SHA-256 `51bd9e36…`)의 비인라인 정의 순서와 같으며, 끝 0x40842fe 가 `_snd_link_init`(NeXTMach `snd_link.c` 의 첫 외부 함수) 입니다. §551–563 의 사운드 머리를 그대로 씁니다.

확인한 사실(이번 세션; 원본 목록 164517–166572 행(주소 붙은 줄 2042 — switch 표가 명령처럼 풀린 줄 포함 — 과 안쪽 라벨 14), 기호표, 원본 `__data`, python):
- 범위 [0x4082764, 0x40842fe), 7066 B, 이어진 22 항목(`m68k-functions.tsv`, 합 7066 = 범위 길이): 이름 있는 열다섯(`dspq_init_lmsg` 126, `dspq_reset_lmsg` 172, `dspq_enqueue_hc` 86, `_hm` 208, `_syscall` 210, `_hf` 90, `_cond` 90, `_state` 142, `dspq_enqueue` 324, `dspq_check` 718, `dspq_execute` 2378, `dspq_free_msg` 474, `dspq_awaited_conditions` 250, `dspq_start_simple` 214, `dspq_start_complex` 308)과 이름 없는 일곱: 0x408288e 80·0x40828de 88·0x4082936 88·0x408298e 86·0x4083a7a 118·0x4083cca 88·0x4084026 728 → NeXTMach 정의 순서(`snd_dspqueue.c:255·268·282·297·1135·1275·1460`)로 정적 `dspq_hc`·`dspq_data`·`dspq_condition`·`dspq_hf`·`dspq_reply_rdata`·`dspq_msg_send`·`dspq_output_stream`. 뒷받침: 원본 안쪽 호출 수 0x408288e 3·0x40828de 2·0x4082936 3·0x408298e 1·0x4084026 1 이 NeXTMach 호출 줄 수(321·350·373 / 343·377 / 339·368·414 / 397 / 1128)와 같고, 0x4083cca 는 주소로 둘(0x40831c2·0x408385a; NeXTMach 772·1003 은 `softint_sched` 인자), 0x4083a7a 는 주소 하나 + 호출 하나(0x4083912·0x408392a; NeXTMach 1046·1052). 인라인 `xmit`·`recv`·`dspq_alloc_lmsg`·`dspq_free_lmsg` 는 따로 항목 없음.
- 행: 겹치는 행 `m68k-245`(`start_lo`–`start_hi` 0x4081b04–0x4082764, `end_lo`–`end_hi` 0x4083ef2–0x40842fe)·`m68k-246`(`snd_link.c`, `start_lo`–`start_hi` 0x4083ef2–0x40842fe) 둘 다 범위 밖으로 걸침 → 명시 범위 `{"range": ["0x4082764", "0x40842fe"], "rows": [], "partial": ["m68k-245", "m68k-246"], "basis": …}`(`span()` 통과를 python 으로 확인). 부분 행이라 받아들여도 덮은 행·백분율은 그대로(§563 과 같음).
- 자료: `__data` [0x40b21c8, 0x40b21d0) 8 B 가 0xffffffff 둘 — `dspq_execute` 가 0x40b21c8 을(0x4083144·0x4083156·0x4083a68), `dspq_output_stream` 이 0x40b21cc 를(0x4084040·0x4084052·0x40842e6) 읽고 씀 = NeXTMach 함수 안 `static int execute_ipl = -1;`(732)·`output_ipl = -1;`(1468). `__bss` [0x40b5090, 0x40b50a0) 16 B(피연산자로 0x40b5090 32·0x40b5094 11·0x40b5098 6(5 줄)·0x40b509c 4 번; 0x4082764 부근의 큐 초기화가 차례를 정함)는 NeXTMach 파일 정적 `queue_head_t lmsgq, msg_free_q;`(191–192) 자리 → bss 자리는 reference-inferred(D113, `snd_device` 와 같은 처리; §556 의 bss [0x40b507c, 0x40b5090) 바로 뒤). 문자열 참조 0. `__common` 참조: `_dsp_var`(+0 은 `dma_enqueue` 인자 0x4083e62, +0xf8 … +0x188)·`_snd_var`·`_slot_id_bmap` 75(`P_DSP`)·`_cpu_type` 12·`_kernel_map`·`_page_mask`·`_active_threads`(0x4083a86, `dspq_reply_rdata` 안 — NeXTMach 1153 행 `current_task()` 가 스테이지 `kern/thread.h:345·350` 과 `kern/cpu_number.h:63` 으로 `active_threads[0]->task` 로 펼쳐진 것, 1997 바뀜 아님; §564.1).
- 부르는 것(원본): `callout_dispatch` 호출 명령 6(NeXTMach `softint_sched` 8 곳: 772·800·1003·1028·1045·1199·1370·1450 — 공통 꼬리로 합쳐질 수 있어 수 차이만으로 지운 호출을 뜻하지 않음), `curipl` 7(바로 3 + `a2` 간접 4), `delay` 10(NeXTMach `DELAY` 5 곳이 인라인으로 늘어남), `dspq_execute` 바로 1 + 주소 2, `dspq_free_msg` 바로 6 + 주소 1, `dma_enqueue`, `dsp_dev_loop`, `dsp_dev_new_proto`, `dsp_dev_reset_chip`, `kalloc`, `kfree` 2(원본 세 곳 249·1237·1261 이 공통 꼬리를 씀), `msg_send_from_kernel`, `object_copyin` 2, `port_release`, `port_set_add`, `port_set_remove`, `snd_reply_recorded_data`, `vm_deallocate`, `vm_map_pageable`; 주소로 `snd_reply_dsp_cond_true`·`snd_reply_dsp_regs`.
- 원본에 보이는 1997 바뀜 후보(NeXTMach 대비, 진단에서 확인; §564.1): ① 인라인 `xmit` 의 기다림이 50 번 `delay(2)`(0x40832e8–0x4083304; NeXTMach 99–100 은 25 번 `DELAY(1)`; `recv` 는 25·`delay(1)` 그대로) ② `dspq_check` 의 condition 갈래가 ISR 을 같은 값이 두 번 읽힐 때까지 다시 읽음(0x4082fce–0x4082fe0; NeXTMach 624 는 한 번) ③ `dspq_execute` 의 `ret_regs` 가 `cpu_type != MC68030`(0 아님)일 때 바이트 읽기(0x408389c `tstb; beq`; NeXTMach 1020 은 `!= MC68040`) ④ `dspq_start_simple` 의 기록 갈래 `dh_flags = 4`(`DMADH_INITBUF`, 0x4083e58; NeXTMach 1357 은 0) ⑤ `dspq_start_complex` 가 `ICR_RREQ` 를 켜지 않는 상태에 `dmaout`(6, 스테이지 `snd_dsp.h:35–43`)을 더함(0x4083f88–0x4083f9c; NeXTMach 1432 는 `penddmain1`·`dmain`) ⑥ `softint_sched` → `callout_dispatch`(§563 과 같은 바뀜일 것).
- 머리: NeXTMach 은 `<dsp.h>`, `<kern/xpr.h>`, `<sys/buf.h>`, `<sys/param.h>`, `<kern/thread.h>`, `<sys/callout.h>`, `<vm/vm_param.h>`, `<vm/vm_kern.h>`, `<next/pmap.h>`, `<nextdev/busvar.h>`, `<nextdev/snd_var.h>`, `<nextdev/snd_dsp.h>`, `<nextdev/snd_dspreg.h>`, `<machine/spl.h>`. `P_DSP`·`cpu_type`·`MC68030`·`MC68040` 은 NeXTMach 에서 `snd_dspreg.h` 가 들이던 `next/cpu.h` 에서 왔으나 07 사본은 그 import 를 뺐음(D107, `07_kernel/nextmach/nextdev/snd_dspreg.h:12`); `cpu_type`·`MC68030`·`MC68040` 은 SDK `m68k/cpu.h`(스테이지 `src/bsd/m68k/cpu.h:53·58–59`).

방법(진단; 명세 `08_build/artifacts/m4p564/spec.json`, run `m4p564-p1`, 바탕 `m0p563-a1-stage`, 위 명시 범위, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 변형 A(`08_build/artifacts/m4p564/src/snd_dspqueue_A.c`, 07 아님): NeXTMach 글에서 include 줄만 바꿈 — `<vm/vm_param.h>` → `<mach/vm_param.h>`, `<next/pmap.h>` → `<vm/pmap.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`(D104), `<nextdev/snd_dspreg.h>` → `<dev/m68k/snd_dspreg.h>`(D107); 그 뒤 진단 덩이 하나: `#import <m68k/cpu.h>`(D110, `cpu_type`·`MC680x0`), `extern int slot_id_bmap;`·`#define SLOT_ID_BMAP slot_id_bmap`·`#define P_DSP (SLOT_ID_BMAP+0x02008000)`(`07_kernel/nextmach/next/cpu.h:98·152`), `typedef struct kern_obj *kern_obj_t;`(1156 행 `&(kern_obj_t)reply_port` 용; NeXTMach `kern/kern_obj.h:66–72` 의 형 이름, 1997 SDK·스테이지에는 없음 — 07 꼴은 나중에 정함; `<m68k/cpu.h>` 는 `kern/xpr.h` 경로로 이미 들어오므로 겹쳐도 무해). 본문은 NeXTMach 그대로(`softint_sched` 그대로).
- 측정: §561 과 같음 — `m4_m68k_probe.py compare`(경고 기록), `m68k_funcbytes.py 4082764 40842fe OBJECT.o RECORD.json 408288e=_dspq_hc 40828de=_dspq_data 4082936=_dspq_condition 408298e=_dspq_hf 4083a7a=_dspq_reply_rdata 4083cca=_dspq_msg_send 4084026=_dspq_output_stream` 과 결과 객체의 지역 이름(컴파일러 접미사 포함)으로 `40b21c8=<execute_ipl>`·`40b21cc=<output_ipl>`·`40b5090=<lmsgq>`·`40b5098=<msg_free_q>` 를 같은 호출에; 섹션 크기(`__text` 7066·`__data` 8·`__bss` 16·`__cstring` 0), `__data` 바이트와 원본, bss 정적의 순서, COMMON 이름과 크기, 원본에 없는 정의·미정의. 다른 함수는 실기 `otool -tv` 와 원본 목록의 명령 비교로 차이를 적음.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고(길이가 다른 함수는 funcbytes 가 바이트 비교를 건너뛰므로 명령 비교로), 다른 함수는 다음 계획에서 원본 바이트로 1997 꼴을 시험합니다(위 ①–⑥ 은 다를 것으로 예상). `kfree` 형 경고 3 개(249·1237·1261 행)를 예상. funcbytes 는 `__text` 만 보므로 자료 확인을 함께 합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록(`diag_gate.commands_ok` 는 경고가 있으면 거짓).

### 564.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A 는 `kern_obj_t` 가 없어 컴파일되지 않음(1156 행 `&(kern_obj_t)reply_port`) | NeXTMach 1150–1158·`kern/kern_obj.h:66–72` 읽음; 스테이지 grep 에서 `kern_obj_t` 는 `vm_unix.c`·`ux_exception.c` 의 주석뿐(정의 0) | ✅ 제 누락. 진단 덩이에 typedef 더함 |
| `_active_threads` 는 1997 바뀜이 아니라 `current_task()` 의 펼침 | NeXTMach 1153, 스테이지 `kern/thread.h:345·350`, `kern/cpu_number.h:63` 읽음 | ✅ 제 오판. 고침 |
| 1997 바뀜 후보 다섯 더(xmit 50·`delay(2)`, ISR 다시 읽기, `ret_regs` 의 CPU 조건 반대, `dh_flags = 4`, `dmaout` 상태 더함) | 원본 165345–165362·165118–165132·165772–165782·166208–166214·166293–166316 행 읽음; NeXTMach 96–135·620–626·1018–1022·1355–1358·1428–1440 행, 스테이지 `snd_dsp.h:35–43`(`dmaout` = 6) 읽음 | ✅ 사실 줄 ①–⑤ 로 더함 |
| 호출 수 해석: `curipl` 7(간접 4), `dspq_execute`·`dspq_free_msg` 의 주소 피연산자, `delay` 10 은 인라인, `callout_dispatch`·`kfree` 는 공통 꼬리 | 제 python 집계(바로 호출만 셈)와 원본 줄 | ⚖️ 수는 받아 적고, 공통 꼬리 여부는 진단의 명령 비교로 확인 |
| `0x40b5098` 은 5 줄에 6 번; `_dsp_var` +0 참조(0x4083e62) 빠짐; "명령 2042" 는 주소 붙은 줄 | python 으로 5 줄·6 번, 원본 166214 행 읽음 | ✅ 문구 고침 |
| 경계·크기·이름 없는 일곱 대응·`__data` 8 B·bss 16 B 차례·`span()`·상태 셈은 맞음 | 이번 세션 python·목록 | ✅(제 확인과 같음) |
| funcbytes 에 자료 넷을 결과 지역 이름으로 같은 호출에 넣을 것; 길이 다른 함수는 바이트 비교를 건너뜀 | `m68k_funcbytes.py` 의 동작(§561–563 에서 씀) | ✅ 측정·판정 문구 고침 |
| `kfree` 형 경고 셋(249·1237·1261) 예상 | `ipc/ipc_kmsg.h:93` 의 `kfree(vm_offset_t, …)` 는 §563 와 같은 경고 원인 | ⏭️ 진단 결과로 확인 |

### 564.2 결과(2026-10-30)

- run `m4p564-p1`(A, 기록 `m4-m68k-probe-p564-20261030.json`): 컴파일 종료 1 — 1162 행 `invalid lvalue in unary '&'`(`&(kern_obj_t)reply_port`): 1997 머리의 `port_t` 는 `port_name_t`(정수, 스테이지 `mach/port.h:95·225`)라 다른 형으로의 캐스트를 lvalue 로 쓸 수 없음. 제 계획 단계 확인 누락(형 이름만 보고 캐스트의 lvalue 성질을 보지 않음). 원본 0x4083a98 은 지역 변수 주소 `pea a6@(-4)` 를 그대로 넘김.
- run `m4p564-p2`(A2 = A 에서 `&(kern_obj_t)reply_port` → `&reply_port`, 진단 `typedef` 뺌; 명세 `spec-p2.json`, 기록 `m4-m68k-probe-p564-p2-20261030.json`): 종료 0, 경고 `kfree` 3 개(§564 예상과 같은 줄), i386 머리 0, 옵션 차이 없음. 섹션 `__text` 7034(원본 7066)·`__data` 8·`__bss` 16; 지역 `_execute_ipl.62` +0·`_output_ipl.77` +4(`__data`), `_lmsgq` +0·`_msg_free_q` +8(`__bss`) — 원본과 같은 차례. COMMON `_dsp_var` 396 와 머리 임시 정의, 원본에 없는 미정의 0.
- **15/22**(`m4-m68k-funcbytes-p564-A2-20261030.json`, 대응 일곱 + 자료 넷). 실기 `otool -tv`(`08_build/artifacts/m4p561/otool/snd_dspqueue_A2.txt`)와 원본의 명령 비교:
  - `dspq_enqueue`·`dspq_free_msg`: 명령 같음, 참조 1·2 다름 — `port_set_remove`(0x4082e2e)·`port_set_add`(0x4083cac)의 첫 인자가 `snd_var` +0x38(`task_space`, D123 의 1997 필드; NeXTMach `snd_var.task` +0x30)이고, `dspq_free_msg` 는 여기에 `softint_sched` → `callout_dispatch`(0x4083b88)(§565.1 고침: 처음엔 둘 다 `callout_dispatch` 로 적었음).
  - `dspq_check`(718 대 694): condition 갈래의 68040 경로에서 ISR 을 같은 값이 될 때까지 다시 읽음(0x4082fce–0x4082fe0); 그 밖은 레지스터 배정과 switch 표 오프셋뿐.
  - `dspq_execute`(2378 대 2380): 인라인 `xmit` 네 곳이 50(0x40832e8·0x40833a4·0x408346c·0x4083528), `ret_regs` 가 `tstb cpu_type`(0x408389c; A 는 `cmpb #1`) → `cpu_type != MC68030`.
  - `dspq_start_simple`(214 대 212): `dh_flags = 4`(0x4083e58). `dspq_start_complex`(308 대 300): `dsp_var.state != dmaout` 검사 더함(0x4083f96–0x4083f9c). `dspq_output_stream`(바이트 4): 인라인 `xmit` 두 곳이 50(0x40840f6·0x4084232)과 `DELAY(2)`.
- 판정(미리 정한 대로): 07 은 바꾸지 않고 다음 계획에서 1997 꼴을 시험합니다. `&reply_port` 의 꼴(바이트로 정해지지 않음)은 나중에 여쭙니다.

## 565. M4-71 세부 계획 — `snd_dspqueue.c` 1997 꼴 진단(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p565/spec.json`, run `m4p565-p1`, 바탕 `m0p563-a1-stage`, §564 명시 범위):
- 변형 B1(`08_build/artifacts/m4p565/src/snd_dspqueue_B1.c`): §564 A2 에 §564.2 의 바뀜만 원본 바이트대로 넣음:
  - 인라인 `xmit`(104–105 행): `for (cnt = 50; …; cnt--) { DELAY(2); }`(`recv` 는 그대로).
  - `dspq_check` condition 갈래 68040 경로(629 행 `lregs.r_struct.isr = regs->isr;`): `do lregs.r_struct.isr = regs->isr; while (lregs.r_struct.isr != regs->isr);`.
  - `dspq_execute` `ret_regs`(1025 행): `cpu_type != MC68040` → `cpu_type != MC68030`.
  - `dspq_start_simple`(1362 행): `ddp->hdr.dh_flags = 0;` → `= DMADH_INITBUF;`(스테이지 `nextdev/dma.h:71`, 0x4; §563 `dsp_dma` 와 같은 이름).
  - `dspq_start_complex`(1437 행): `&& dsp_var.state != dmaout` 를 더함.
  - `softint_sched` 여덟 곳(777·805·1008·1033·1050·1204·1375·1455 행) → `callout_dispatch`(인자 그대로: `CALLOUT_PRI_THREAD` 4 여섯·`CALLOUT_PRI_SOFTINT1` 1 둘; 원본은 호출 명령 여섯을 함께 씀), 파일 안 `extern void callout_dispatch();`(D124 꼴).
  - `dspq_enqueue` 552 행 `port_set_remove(snd_var.task, …)`·`dspq_free_msg` 1274 행 `port_set_add(snd_var.task, …)` → `snd_var.task_space`(§565.1).
- 변형 B2: B1 에서 ISR 다시 읽기만 `lregs.r_struct.isr = regs->isr; while (lregs.r_struct.isr != regs->isr) lregs.r_struct.isr = regs->isr;` 꼴.
- 측정: §564 와 같음(funcbytes 의 자료 넷은 결과 지역 이름으로), 다른 함수는 `otool -tv` 비교.
판정(미리 정함; 07 은 바꾸지 않음): 22/22 이고 `__data`·bss 차례가 원본과 같은 꼴이 있으면, 바이트로 정해지지 않는 것(`&reply_port` 의 꼴, include·`P_DSP` 이름 공급, `callout_dispatch` 선언, ISR 다시 읽기 꼴이 둘 다 같으면 그 꼴, `kfree` 경고 처리)을 사용자께 여쭙니다. 남으면 차이를 적고 꼴을 바꿔 다시 시험합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록(A2 와 같은 `kfree` 3 개 밖의 것이 생기면 원인을 적음).

### 565.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `port_set_remove`(A2 552)·`port_set_add`(A2 1274)의 첫 인자가 원본은 `snd_var` +0x38(`task_space`) | A2 550–554·1272–1276 읽음, 원본 0x4082e20–0x4082e34·0x4083c9e–0x4083cb2 읽음, python `0x40c6ec0 - 0x40c6e88` = 0x38, 스테이지 `snd_var.h:125·127`(`task`·`task_space`); 범위 안 0x40c6eb8(`task`) 참조는 0x4083a8c·0x4083ce6 둘뿐 | ✅ 제 누락. B 에 더하고 §564.2 문구 고침 |
| `xmit` 여섯 곳 모두 50·`DELAY(2)`, `recv` 한 곳은 25·`DELAY(1)`, 출력 앞 기다림 40·`DELAY(1)` 그대로 | 원본 0x40832e8·0x40833a4·0x408346c·0x4083528·0x40840f6·0x4084232(`moveq #50`, 이번 세션 diff 출력); 지연 인자와 나머지는 B 진단의 funcbytes 로 | ⚖️ 횟수는 확인, 지연 인자는 진단으로 |
| ISR 다시 읽기는 지역 `lregs.r_struct.isr` 의 바이트 비교 고리; B1·B2 모두 뜻이 같음 | 원본 0x4082fce–0x4082fe0 읽음 | ✅(어느 꼴이 같은 바이트인지는 진단) |
| `ret_regs` 는 0 아닐 때 바이트 읽기 → `!= MC68030` | 원본 0x408389c 와 diff 출력 | ✅ |
| `dh_flags = 4` 는 기록(RECORD) 갈래, `=` 이지 `|=` 아님 | 원본 0x4083e52–0x4083e5a 읽음, NeXTMach 1355–1358(`SND_DIR_RECORD` 갈래 `= 0`) | ✅ |
| `start_complex` 의 기록 갈래에서 상태 1·2·6 이면 `ICR_RREQ` 건너뜀 | 원본 0x4083f80–0x4083fb2 읽음 | ✅ |
| 여덟 곳 모두 `callout_dispatch`, 인자 그대로(우선순위 4 여섯·1 둘), 호출 명령 여섯을 함께 씀 | 스테이지 `sys/callout.h:56–59`(이번 세션 §563 에서 58–59 읽음); 호출 자리는 B 진단의 funcbytes 로 | ⚖️ 바이트 같음은 진단으로 |
| 그 밖의 차이는 재배치 값·분기/표 주소·레지스터 배정뿐 | A2 diff 출력(이번 세션) | ⚖️ 진단으로 확인 |

### 565.2 결과(2026-10-30)

- run `m4p565-p1`(B1·B2, 기록 `m4-m68k-probe-p565-20261030.json`): 종료 0, 경고 `kfree` 3 개씩(A2 와 같은 줄), i386 머리 0, 옵션 차이 없음.
- **B1 = 22/22**(`m4-m68k-funcbytes-p565-B1-20261030.json`, 대응 일곱 + 자료 넷), L1 `NOT_MATCH` 사유 `['__DATA,__bss: unverified']` 하나(판정 `provisional`), 원본에 없는 이름 0. B2(`while` 꼴) 21/22: `dspq_check` 742 B(원본 718) → ISR 다시 읽기는 `do … while` 꼴로 바이트가 정해짐.
- python 확인(`m4-m68k-p565-checks-20261030.json`, `ok` 참): 섹션 `__text` 7066·`__data` 8·`__bss` 16; `__data` 8 B 가 원본 [0x40b21c8, 0x40b21d0) 과 같음(재배치 0, `_execute_ipl.62` +0·`_output_ipl.77` +4); bss `_lmsgq` +0·`_msg_free_q` +8(원본 0x40b5090·0x40b5098 차례); 외부 함수 15 = 원본 이름; COMMON 12 개 모두 원본 이름(`_dsp_var` 396); 원본에 없는 미정의 0. 객체 SHA `e28a4a85…`.
- 판정(미리 정한 대로): 22/22 이고 자료가 같으므로 바이트로 정해지지 않는 것을 여쭙니다. 앞선 결정을 그대로 따를 것(묻지 않음): include 경로(D104·D107), `P_DSP`·`SLOT_ID_BMAP`·`slot_id_bmap` 는 파일 안 이름(D113·D121), `callout_dispatch` 는 K&R `extern`(D124), `kfree` 경고는 글 그대로 + `known_warnings`(D121·D123·D126), bss 정적 둘은 CODE+BSS_INFERRED(D113; 최종 run 에서 zerofill 과 받아들인 배치와의 겹침을 python 으로). 여쭐 것: ① `object_copyin` 의 마지막 인자 꼴(NeXTMach `&(kern_obj_t)reply_port` 는 1997 머리에서 컴파일되지 않음) ② `cpu_type`·`MC68030` 을 위한 `#import <m68k/cpu.h>` 줄(NeXTMach 은 `snd_dspreg.h` → `next/cpu.h` 로 얻었고, 지금은 `kern/xpr.h` 경로로 이미 들어옴).
- 사용자 결정(2026-10-30, AskUserQuestion): ① `object_copyin` 의 마지막 인자는 "`&reply_port`"(캐스트 없음, B1 과 같은 글; NeXTMach 줄을 고친 것으로 표시) ② `<m68k/cpu.h>` 는 "직접 import 함"(NeXTMach 은 `next/cpu.h` 경유였음을 표시 주석에).

## 566. M4-72 D127 구현 계획 — 07 `src/machdep/m68k/snd_dspqueue.c`(CODE+BSS_INFERRED; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §564–565 결과와 결정. bss 정적이 있는 객체라 `snd_device`(§556·§560)와 같은 절차: 최종 명세에 `bss_inferred`, `m5_m68k_zerofill.py objs`, `ACCEPTED` 넷 묶음(이 계획의 최종 기록에는 이 객체 하나). 07 머리를 고치지 않으므로 받아들인 기록의 plan 506 검사에 영향 없음.
1. 07 `src/machdep/m68k/snd_dspqueue.c`(D103) = NeXTMach `nextdev/snd_dspqueue.c`(고지·HISTORY 그대로) + 머리 주석(1997 바뀜 목록·함수별 출처) + include 줄(`<mach/vm_param.h>`·`<vm/pmap.h>`·`<dev/busvar.h>` D104, `<dev/m68k/snd_dspreg.h>` D107) + `#import <m68k/cpu.h>`(D127, NeXTMach 은 `next/cpu.h` 경유) + 파일 안 이름(`extern int slot_id_bmap;`·`SLOT_ID_BMAP`·`P_DSP`, D113·D121; 값 `07_kernel/nextmach/next/cpu.h:98·152`) + `extern void callout_dispatch();`(D124) + B1 의 바뀜(표시 plan 566, D127, D024): `xmit` 50·`DELAY(2)`, `dspq_check` ISR `do … while`, `ret_regs` `!= MC68030`, `dh_flags = DMADH_INITBUF`, `!= dmaout`, `callout_dispatch` 여덟, `task_space` 둘, `&reply_port`. 진단 문구는 빼고, 주석 뺀 토큰이 B1 과 같아야 함(python).
2. `stage_m68k.py`: `M4FILES[566]` = 563 + `snd_dspqueue.c`, `EXCEPTS[566] = dict(EXCEPTS[563])`, 머리말 plan 목록에 566.
3. 회귀: `--plan 563` 재생성(`m0p563-r566-stage`)이 보관 `m0p563-a1-stage` 와 모든 키·파일이 같음; `m0p566-a1-stage` 와 보관 563 의 차이는 `src/machdep/m68k/snd_dspqueue.c` 하나(키는 `plan`·`m4_sources`). M5 205 줄(`m3p566-b563`·`m3p566-cc1`): 객체·stderr 같음, `compare` 두 기록 `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로뿐. x86 `m4_x86_inputs.py s6ln`(`L2_FORMS`·`L2_EXPECT`)·`--plan 566 x86gate`.
4. (07 파일은 p1 전에 고정; `known_warnings` 는 p1 F 의 stderr 다섯 줄 — 함수 문맥 둘 + 경고 셋 — 그대로) 확인 run `m4p566-p1`(`confirm/spec.json`, 바탕 `m0p566-a1-stage`): F = `@machdep/m68k/snd_dspqueue.c`, L = §565 B1 글 그대로. 종료 0, `kfree` 경고 3 개씩, i386 머리 0, F = L = B1(canon·`obj_sig`), `provisional`(사유 bss 하나), 22/22. run `m4p566-e1`: F·L 의 `-E` 토큰 같음(`#` 줄 빼고).
5. 최종 run `m4p566-a1`(명세 `08_build/artifacts/m4p566/spec.json`: F 만, REF = p1 L, `known_warnings["snd_dspqueue"]` = p1 F 의 stderr 줄 그대로, `bss_inferred` [`snd_dspqueue`], §564 명시 범위): `gate.ok`, 옵션 차이 없음(따로); zerofill `objs`(`m4-m68k-zerofill-p566-20261030.json`): `reference-inferred` 이고 후보가 [0x40b5090, 0x40b50a0); 받아들인 bss 배치(§464 후보 + `"plan464_record"` 를 담은 기록들, 진단 `-D-`·`-D1-`·`-C2-` 와 대체된 §556 기록, 이 계획 기록은 뺌)와 겹침 0(python); funcbytes 22/22; python 확인 `m4-m68k-p566-checks-20261030.json`: §565 확인 항목(섹션·`__data` 8 B·bss 차례·외부 함수 15 = 원본·COMMON·미정의), L1 0x4082764 사유 bss 하나, 의존 목록 i386 0, 입력 SHA 사슬 07 = 스테이지 = run(`snd_dspqueue.c`, 생성 `dsp.h`, `nextmach/nextdev/snd_var.h`, `src/driverkit/snd_msgs.h`, `nextmach/nextdev/snd_dsp.h`, `nextmach/nextdev/snd_dspreg.h`, `nextmach/nextdev/dma.h`, `nextdev/bsd/dev/m68k/dma.h`, `nextmach/sys/callout.h`, `nextmach/nextdev/busvar.h`(스테이지 `src/bsd/dev/busvar.h`)) 와 SDK `m68k/cpu.h`(실기 SDK 출처 = 스테이지 = run; 07 출처 없음). 이전 bss 배치 기록 경로와 SHA 를 확인 기록에 남김.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-snd_dspqueue.md` 를 먼저 쓰고 `ACCEPTED` 에 넷 묶음 한 줄; 도구 두 번 실행·§563 표와 이름 대조(더한 것 `snd_dspqueue` 뿐). 예상: 부분 행 245·246 이라 덮은 행·백분율은 그대로, 객체 수·`code_bss_inferred`·`object_bytes` 가 늘고 `partial_rows` 에 `m68k-246` 이 더해짐(수치는 도구 출력만).
7. 기록: diff(NeXTMach 대비 `m68k-snd_dspqueue.diff`), PROVENANCE 새 행(NeXTMach 저장소·커밋·경로, 고지 D013, 함수별 출처: 글이 바뀐 일곱(`dspq_enqueue`·`dspq_check`·`dspq_execute`·`dspq_reply_rdata`(`&reply_port`, 사용자 결정)·`dspq_free_msg`·`dspq_start_simple`·`dspq_start_complex`)과 인라인 `xmit`(그래서 `dspq_execute`·`dspq_output_stream` 의 코드가 바뀜; `dspq_output_stream` 의 글은 그대로), 글 그대로 열다섯(`dspq_output_stream` 포함), 파일 안 이름의 출처 `mk-108.1/next/cpu.h:97·98·152`(NeXT·UCB 고지), 파일 SHA·최종 기록·zerofill 기록·`M4FILES[566]`), MODIFICATIONS, DECISIONS D127, 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: bss 자리, `_nbuf`·`_bufpages` 합침, 다른 객체의 함수들.
관문: 명령 종료 0, 정한 경고뿐, i386 머리 0, 회귀 같음, 겹침 0, 상태 도구가 멈추지 않음.

### 566.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 사슬에 `busvar.h`(출처 `07_kernel/nextmach/nextdev/busvar.h`)가 빠짐 | B1 59 행 `#import <dev/busvar.h>`, `m0p563-a1-stage.manifest.json` 의 출처 열 출력 | ✅ 제 누락. 5 고침 |
| 글이 바뀐 함수는 `dspq_reply_rdata` 를 포함한 일곱, `dspq_output_stream` 은 글 그대로이고 인라인 `xmit` 때문에 코드만 바뀜 | §565 B1 생성기의 바꿈 목록(이번 세션, `xmit` 은 104–105 행, `output_stream` 본문 바꿈 없음)과 §564 A2 의 `&reply_port` | ✅ 제 분류 오류. 7 고침 |
| `known_warnings` 는 다섯 줄(문맥 둘 + 경고 셋) | `m4p565-p1/stage/_log/00.err` `wc -l` = 5 | ✅ 4 에 적음 |
| SDK `m68k/cpu.h` 는 07 출처가 없으므로 SDK = 스테이지 = run 으로 기록 | manifest 출처 `real machine /NextDeveloper/Headers/bsd/m68k/cpu.h` | ✅ 5 고침 |
| PROVENANCE 에 `slot_id_bmap` 선언 출처 `next/cpu.h:97` 과 SHA·기록·`M4FILES[566]` | `07_kernel/nextmach/next/cpu.h:95–98` 읽음(mk-108.1 과 90–100 행 같음, diff) | ✅ 7 고침 |
| 이전 bss 배치: §464 후보 + `"plan464_record"` 기록 15 개(진단·§556·이번 것 뺌), 배치 33, 서로 겹침 0, 새 후보와 겹침 0 | 최종 run 뒤 python 으로 다시 셈(이번 계획 5) | ⏭️ 수는 받지 않고 실행 결과로 적음 |
| 후보 [0x40b5090, 0x40b50a0) 는 원본 `__bss` [0x40b317c, 0x40b5648) 안이고 `snd_device` 후보 끝에서 바로 시작; 원본 기호표에 `__bss` 기호 없음 | §564 사실 줄(§556 후보 끝 0x40b5090)과 같음; 기호표 섹션 5 기호 0 은 최종 확인에서 python 으로 | ⚖️ 최종 확인에서 셈 |
| 도구 동작(선택 규칙·`EXCEPTS` 정확 키·`bss_inferred` 는 `refs` 필요·`provisional` 조건·zerofill 의 겹침 검사 범위·상태 도구 넷 묶음)은 계획과 맞음 | §556·§560·§563 에서 같은 도구로 같은 절차를 실행함 | ✅ 그대로 |

### 566.2 결과(2026-10-30)

- 1: 07 `src/machdep/m68k/snd_dspqueue.c`(1605 행, SHA `27fec1ad…`): 주석 뺀 토큰 8087 개가 §565 B1 과 같음(python). diff `06_reconstruction/evidence/m68k-snd_dspqueue.diff`(207 행).
- 2: `stage_m68k.py` 679 → 681 행(`M4FILES[566]`·`EXCEPTS[566]`·머리말 목록).
- 3: `--plan 563` 재생성(`m0p563-r566-stage`)이 보관본과 모든 키·파일이 같음; `m0p566-a1-stage`(942 파일)와 보관 563 의 차이는 `snd_dspqueue.c` 하나(키는 `plan`·`m4_sources`). M5: `m5-563.cmd` 가 §563 것과 `cmp` 같음, run `m3p566-b563`·`m3p566-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p566-compare-20261030.json`, `-b563-`) `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로 `snd_dspqueue.c` 뿐. x86 `m4-x86-inputs-p566-20261030.json` `ok`, `--plan 566 x86gate` 일곱 같음·`v183_paths` 0.
- 4: run `m4p566-p1`(`m4-m68k-probe-p566-p1-20261030.json`): F·L 종료 0, `kfree` 경고 3 개씩(stderr 5 줄), `provisional`(사유 bss 하나), F = L = §565 B1(canon·`obj_sig`), 22/22(`m4-m68k-funcbytes-p566-F/L-20261030.json`). run `m4p566-e1`: `-E` 토큰 23096 개 F = L, i386 머리 0.
- 5: run `m4p566-a1`(`m4-m68k-p566-final-20261030.json`, SHA `c440277e…`): `gate.ok`, 옵션 차이 없음, 22/22(`m4-m68k-funcbytes-p566-a1-20261030.json`); zerofill `m4-m68k-zerofill-p566-20261030.json`(SHA `e95fab15…`) `reference-inferred`, 후보 [0x40b5090, 0x40b50a0); 확인 `m4-m68k-p566-checks-20261030.json`(`ok` 참): 이전 bss 배치 기록 16 개(§464 + 뒤 기록 15, 경로·SHA 기록)의 배치 33 과 겹침 0·서로 겹침 0, 후보는 원본 `__bss` [0x40b317c, 0x40b5648) 안(원본 `__bss` 기호 0), 의존 123 파일·i386 0, 입력 사슬 열하나(SDK `m68k/cpu.h` 포함). 객체 SHA `acbc69cf…`.
- 6: 근거 `06_reconstruction/evidence/m68k-snd_dspqueue.md`(상태 도구 전). `ACCEPTED` 에 넷 묶음 한 줄. 상태표 29 → 30 행·`m4-m68k-status-p566-20261030.json`: 28 객체(OBJECT_MATCH 22, CODE+BSS_INFERRED 6), 덮은 행 48/188, 39296/215874 B(18.2%), 부분 행 `m68k-244`·`m68k-245`·`m68k-246`·`m68k-306`, `object_bytes` 46418 → 53484(+7066, python), 두 번 실행 같음, §563 표와 이름 대조로 더한 것 `snd_dspqueue` 뿐·바뀐 것 없음.
- 7: PROVENANCE 1153 → 1154 행(7 칸), MODIFICATIONS 704 → 705 행, DECISIONS D127(130 → 131 행), "현재 상태와 다음 일" 고침.

