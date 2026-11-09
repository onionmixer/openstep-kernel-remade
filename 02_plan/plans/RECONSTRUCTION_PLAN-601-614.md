# 커널 소스 복원 작업계획 — 보관 §601–614

`02_plan/RECONSTRUCTION_PLAN.md` 의 §601–614(m68k M4 `miniMonMachdep`·`next_exception`(D135), `APM`(D136), `m68k_init`(D137), `swapgeneric`·`sd.h`·`rd.h`·funcbytes 의 `__cstring` scattered 비교(D138), `shutdown`(D139))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-30, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 601. M4-107 세부 계획 — m68k `miniMonMachdep`(행 300)과 `next_exception`(행 301) 진단(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: `machdep` 다음 자리의 정확 행 둘로, 크기가 작고 참고 글이 바로 있습니다. 1997 이벤트 드라이버(행 213–218)는 1997 이름(`evsetup_screens`·`AnimateWaitCursor`·`MoveTheCursor`·`evdispatch`·`evretry`)이 참고 코드 어디에도 없어(전수 grep 0) 뒤로 미룹니다. `pcb.c`(행 308–309, 18 함수 1634 B)는 Darwin i386 `pcb.c` 틀을 따른 작성이 필요해 더 큰 일입니다. `tty_pty` 꼬리(행 036)는 받아들인 M5 객체와 x86 공유 파일을 건드립니다.

확인한 사실(이번 세션; 원본은 scratchpad `odis.py`(로컬 `m68k-linux-gnu-objdump`)로 풀었습니다):
- 행 300 [0x4094a7c, 0x4094ab2) 54 B(python), 정확 행이고 종류는 `x86`(x86 원천 `machdep/i386/miniMonMachdep.c`)입니다. 진입점 여섯은 x86 07 판과 같은 차례(`miniMonReboot`·`miniMonHalt`·`miniMonGdb`·`miniMonTryGetchar`·`miniMonGetchar`·`miniMonPutchar`)입니다. 앞의 셋은 `pea a6@; movel sp,a6; clrl d0; unlk a6; rts`(10 B), 뒤의 셋은 `pea a6@; movel sp,a6; unlk a6; rts`(8 B)입니다.
- 원본 `__data` 0x40b2b92 의 `_miniMonMDCommands` 는 12 B(python, 다음 기호 `_event_high` 0x40b2b9e 까지) 모두 0 입니다. 이는 `miniMonCommand_t`(07 `kern/miniMonPrivate.h:34–38`, 포인터 셋) 하나, 곧 x86 표의 끝 항목 `{0,0,0}` 하나만 있는 꼴입니다. 자료 지도(`06_reconstruction/m68k-data-map.tsv` 의 `seq` 112, 파일 115 행)도 이 자리를 `x86-miniMonMachdep` 으로 둡니다(12 B 는 다음 기호까지의 간격이고, 객체 자료 크기는 가설입니다).
- 행 301 [0x4094ab2, 0x4094afe) 76 B 는 `machine_exception` 하나입니다. 바이트의 갈래(2→4, 3→8, 4→7, 그 밖은 0 반환)는 NeXTMach `next/next_exception.c` 의 `EXC_BAD_INSTRUCTION`→`SIGILL`, `EXC_ARITHMETIC`→`SIGFPE`, `EXC_EMULATION`→`SIGEMT` 와 같습니다(스테이지 `mach/exception.h:72·75·78`, `bsd/sys/signal.h:41·58·62` 의 값).
- NeXTMach 가 들이는 `<sys/boolean.h>`·`<sys/exception.h>`·`<sys/kern_return.h>` 는 스테이지에 없고, `mach/` 아래에 있습니다(find).

방법(진단; 명세 `08_build/artifacts/m4p601/spec.json`, run `m4p601-p1`, 바탕 `m0p600-a1-stage`; scratchpad `gen_p601.py`):
- `miniMonMachdep` M1(`machdep/i386/dkbad.c` 의 컴파일 줄, `m4_id` `m68k-300`)은 D115 의 꼴을 따릅니다. x86 07 `miniMonMachdep.c` 의 APSL 고지와 NeXT 1993 머리 주석, `#import <kern/miniMonPrivate.h>`, `miniMonCommand_t miniMonMDCommands[] = { {0,0,0} };`, 그리고 x86 시그니처 여섯으로 이루어집니다. 몸통은 `miniMonReboot`·`miniMonHalt`·`miniMonGdb` 는 `return FALSE;`, 나머지 셋은 빈 몸통입니다.
- `next_exception` N1(`m4_id` `m68k-301`)은 NeXTMach `next/next_exception.c` 글 그대로이고, include 셋만 `<mach/boolean.h>`·`<mach/exception.h>`·`<mach/kern_return.h>` 로 바꿉니다(D104).

측정: 종료·경고(빈 몸통의 `int` 함수는 GCC 2.7 `-Wall` 에서 경고가 날 수 있어 기록합니다)·i386 0·옵션이 M5 줄과 같은지, `__text` 크기(54·76 기대), funcbytes(6/6·1/1), L1(`OBJECT_MATCH` 와 그 사유), 섹션 목록, `__data` 12 B 가 원본과 같은지, 원본에 없는 미정의 기호를 봅니다.

판정(미리 정함; 07 은 바꾸지 않음):
- 둘 다 맞으면 07 구현 계획을 씁니다.
- 바이트로 가를 수 없는 꼴(머리와 include, 빈 `int` 몸통의 경고 처리)은 그 전에 사용자에게 묻습니다.
- 맞지 않으면 차이를 적고 다음 진단으로 갑니다.

관문: 종료 0, i386 0, 옵션 = M5 줄입니다. 경고는 기록합니다.

### 601.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다: "자료 지도 112 행" 은 파일 줄이 아니라 `seq` 112 이고, 파일에서는 115 행입니다. 그리고 "12 B" 는 다음 이름 있는 기호(`_event_high`)까지의 간격일 뿐, 원본 객체가 가진 자료 크기로 확인된 값은 아닙니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 바이트 사실(54·76 B, 명령 꼴, 갈래 2→4·3→8·4→7, `_event_high` 0x40b2b9e) 맞음; 0x40b2b92 부터 24 B 가운데 처음 12 B 만 0, 그 뒤는 `040b55c4`·`040b55c8`·`00002000` | scratchpad `odis.py` 출력과 python 자료 읽기(이번 세션), `symbols.tsv` 635·1761 행(`sed -n` 으로 엶; 첫 열 색인은 633·1759) | ✅ |
| 12 B 는 기호 간격일 뿐 원본 객체 자료 크기로 정해진 값이 아님; 자료 지도 `next_first` 는 위 한계일 뿐; L1·상태 도구는 나온 자료만 비교하므로 원본의 더 많은 자료를 빠뜨려도 잡지 못함 | 자료 지도 머리 줄(이번 세션 읽음: "next_first is only an upper bound"), `l1_compare.py:407–418`(객체에 있는 섹션만 검사) | ⚖️ 계획 문구를 "기호 간격 12 B, 객체 자료 크기는 가설" 로 고침. `_event_high`·`_event_middle`·`_default_page_size` 는 x86 판 `miniMonMachdep.c` 에 없는 이름이라 다른 객체의 것으로 봅니다 |
| 자료 지도 줄은 `seq` 112, 파일 115 행 | `sed -n 115p`(이번 세션) | ✅ 고침 |
| KDP 의 빈 비-void 함수는 `48562c4f4e5e4e75` 이고 경고 0 | `m4-m68k-probe-p530-20261026.json:49–58`(rc 0, warnings 0) | ✅ |
| M5 줄은 `-g -O2`, `-Wall` 없음 | `final.cmd` 2 행(이번 세션) | ✅ |
| L1 은 `__data` 바이트와 재배치를 비교함 | `l1_compare.py:407–418`(비지 않은 섹션마다 `ok` 가 아니면 사유) | ✅ 측정에 `__data` 주소·크기·차이 0 을 명시함 |
| `diag_gate` 는 명령·경고·i386 만 봄 — `full_span`·`candidate`·funcbytes 를 따로 요구할 것; `defined_symbols` 는 외부 정의만 담으니 지역 정의·COMMON 도 따로 볼 것 | `m4_m68k_probe.py:360–364`(이번 세션) | ✅ 측정에 더함 |
| 옵션 보고는 `-D`·`-I` 만 비교함 | `m4_m68k_probe.py:204–206`(이번 세션) | ✅ python 으로 `-c`·`-o` 를 뺀 전체 명령 비교를 더함 |
| `pcb` 는 Darwin 틀이 "필요" 하다는 말은 지나침 — 후보 구조일 뿐 | — | ✅ 문구를 "Darwin i386 `pcb.c` 틀이 후보" 로 받아들임 |

계획 수정(측정): 두 객체 모두 `full_span`·`judgement` `candidate`·L1 `OBJECT_MATCH` 사유 없음, funcbytes 6/6·1/1, 섹션 목록(`miniMonMachdep` 은 `__text` 54·`__data` 12 기대, `next_exception` 은 `__text` 76 만 기대), `__data` 12 B 가 원본 0x40b2b92 와 같고 재배치 0, 지역 정의·COMMON 목록, 원본에 없는 미정의 없음, `-c`·`-o` 를 뺀 전체 컴파일 명령이 M5 줄과 같음(python)을 봅니다.

### 601.2 결과(run `m4p601-p1`, 2026-10-30)

- 두 변형 모두 종료 0, 경고 0, i386 0 입니다. 옵션 보고에 차이가 없고, `-c`·`-o` 를 뺀 전체 컴파일 명령도 M5 줄과 같습니다(python; `-M` 줄은 소스 경로만 다름). 기록은 `09_validation/reconstruction/m4-m68k-probe-p601-20261030.json`·`m4-m68k-p601-checks-20261030.json` 입니다.
- `miniMonMachdep` M1: `__text` 54(기대와 같음), `__data` 12 B 가 원본 0x40b2b92 와 바이트가 같고 재배치 0 입니다. 6/6(`m4-m68k-funcbytes-p601-M1-20261030.json`), L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate` 입니다. 지역 정의·COMMON·미정의 기호는 없습니다.
- `next_exception` N1(NeXTMach 글 + include 셋): `__text` 76, 섹션은 그것 하나, 1/1(`m4-m68k-funcbytes-p601-N1-20261030.json`), L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate` 입니다. 지역 정의·COMMON·미정의 기호는 없습니다.
- 계획 밖 run 하나를 더합니다(관문 기준은 그대로): run `m4p601-p2` 에서 M2 = M1 + x86 07 판의 나머지 import 둘(`<sys/reboot.h>`, `<kern/thread.h>`)을 컴파일합니다. 목적은 07 꼴을 사용자에게 물을 때 "import 를 x86 판처럼 둘지" 가 바이트를 바꾸는지 미리 아는 것입니다. 판정: M1 과 canon 이 같으면 바이트로 가를 수 없는 선택지로 묻고, 다르면 그 차이를 적습니다.

### 601.3 결과(run `m4p601-p2`, 2026-10-30)

- M2: 종료 0, 경고 0, i386 0, L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate` 입니다(`m4-m68k-probe-p601-p2-20261030.json`). M1 과 canon 이 같고, `obj_sig` 차이는 기호(COMMON `_master_cpu` 하나가 더해짐 — 원본 기호표에 있는 이름)와 STABS 53 → 439 뿐입니다. 따라서 x86 판 import 를 둘지는 바이트로 가를 수 없습니다.
- 다음: 07 꼴을 사용자에게 묻습니다(`miniMonMachdep` 의 머리·import 꼴). `next_exception` 은 NeXTMach 글 그대로에 include 셋을 D104 로 바꾼 꼴이며, 바이트가 맞으므로 따로 묻지 않습니다. 그 뒤 07 구현 계획(§602)을 씁니다.

- 사용자 결정(2026-10-30, AskUserQuestion): `miniMonMachdep` 은 "x86 머리+시그니처"(D115 꼴, 진단 M1 — import 는 `<kern/miniMonPrivate.h>` 하나), `machine_exception` 은 "NeXTMach 그대로"(`next/next_exception.c`, include 셋만 D104).

## 602. M4-108 D135 구현 계획 — 07 `src/machdep/m68k/miniMonMachdep.c`, `src/machdep/m68k/next_exception.c`(행 300·301, OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §601.2–601.3 결과와 위 결정입니다. 두 객체 모두 진단에서 원본과 같았습니다(6/6·1/1, L1 `OBJECT_MATCH` 사유 없음, 자료 12 B 같음). 스테이지 `m0p600-a1-stage` 에는 두 경로(`src/machdep/m68k/miniMonMachdep.c`·`next_exception.c`)가 없습니다(아래 1 에서 python 으로 확인).
1. 07 파일 둘(D103)을 scratchpad `gen_p602.py` 로 만듭니다.
   - `miniMonMachdep.c` = 진단 M1 글입니다. APSL 고지 뒤에 "Modified 2026-10-30: see 07_kernel/MODIFICATIONS.md" 한 줄을 넣습니다(§531 의 `kdp_machdep.c` 꼴). NeXT 1993 머리 뒤에는 m68k 설명 주석 덩이 하나를 넣습니다. 그 내용은 원본 진입점과 자료, 몸통과 표가 바이트에서 온 것, 그리고 x86 판에서 뺀 것(`miniMonBacktrace`·`ishex`·`xx`·`xtoi`·`miniMonDump`, `<sys/reboot.h>`·`<kern/thread.h>`)입니다. 진단 표시는 `plan 602 (D135, D115, D024)` 로 바꿉니다.
   - `next_exception.c` = 진단 N1 글입니다. 표시는 `plan 602 (D104)` 로 바꿉니다(NeXTMach 고지·HISTORY 그대로, D013). 머리 뒤에 plan 602 설명 주석 덩이 하나를 넣습니다.
   - 두 파일 모두 주석을 뺀 토큰이 M1·N1 과 같아야 하고, 표시 줄에 `*/` 뒤 글이 없어야 합니다(python).
2. `stage_m68k.py`: `M4FILES[602] = list(M4FILES[600]) + ['miniMonMachdep.c', 'next_exception.c']`, `EXCEPTS[602] = dict(EXCEPTS[600])`, 머리말 plan 목록에 602 를 더합니다. `M4HEADERS`·`OVLDROP`·`X86` 은 그대로입니다(최대 키 600·583·559).
3. 회귀:
   - `--plan 600` 재생성(`m0p600-r602-stage`)이 보관 `m0p600-a1-stage` 와 모든 키·파일이 같아야 합니다.
   - `m0p602-a1-stage` 와 보관 600 의 차이는 두 파일(965 → 967)과 키 `plan`·`m4_sources`·`files` 뿐이어야 합니다(python assert).
   - M5 205 줄: `m5-600.cmd` 가 §600 것과 `cmp` 같아야 합니다. run `m3p602-b600`·`m3p602-cc1` 의 객체 205 개와 stderr 205 개가 같아야 합니다. `compare` 두 기록의 `differ_unexpected`·`lost` 는 비어야 하고, 요약 차이는 `stage_vs_test_stage` 에 두 파일이 더해진 것뿐이어야 합니다.
   - x86: `m4_x86_inputs.py s6ln`·`--plan 602 x86gate` 일곱이 같아야 합니다.
4. (07 파일은 p1 전에 고정합니다) 확인 run `m4p602-p1`(`08_build/artifacts/m4p602/confirm/spec.json`, 바탕 `m0p602-a1-stage`)을 돌립니다.
   - F = `@machdep/m68k/miniMonMachdep.c`·`@machdep/m68k/next_exception.c` 입니다.
   - L = M1·N1 글에 F 와 같은 주석 줄을 같은 자리에 넣어 모든 줄 위치를 F 와 맞춘 꼴입니다(§579.3 교훈; python 으로 줄마다 주석 뺀 토큰이 같음을 확인).
   - 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = M1·N1(canon), 6/6·1/1(`m4-m68k-funcbytes-p602-F/L-…`), `OBJECT_MATCH`·`full_span`·`candidate` 이어야 합니다.
5. 최종 run `m4p602-a1`(명세 `08_build/artifacts/m4p602/spec.json`; F 만, `m4_id` `m68k-300`·`m68k-301`, `refs` = p1 L 객체와 SHA-256, 경고가 없으므로 `known_warnings` 는 없음; 기록 `m4-m68k-p602-final-20261030.json`)을 돌립니다.
   - 관문: `gate.ok`, 6/6·1/1 입니다.
   - python 확인 `m4-m68k-p602-checks-20261030.json`: 섹션(`__text` 54·`__data` 12 / `__text` 76), `__data` 가 원본 0x40b2b92 와 같고 재배치 0, 외부 정의 = 구간 안 원본 이름(+ `_miniMonMDCommands`), 지역·COMMON·미정의 없음, L1 사유 없음, `-c`·`-o` 를 뺀 컴파일 명령이 M5 줄과 같음, 의존 목록 i386 0, 입력 사슬(전수)입니다.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-miniMonMachdep.md`·`m68k-next_exception.md` 를 먼저 쓰고 `ACCEPTED` 에 한 줄(한 기록에 두 객체)을 더합니다. 도구를 두 번 돌리고 §600 표와 이름을 대조합니다(더한 것 둘뿐).
   - 기대(python 으로 미리 계산): 객체 35(OBJECT_MATCH 28), 덮은 행 59/188, 덮은 바이트 59590 + 54 + 76 = 59720, `object_bytes` 76626 + 54 + 76 = 76756 입니다. 백분율은 도구 출력을 씁니다.
7. 기록:
   - diff: `m68k-miniMonMachdep.diff`(x86 07 `miniMonMachdep.c` 대비), `m68k-next_exception.diff`(NeXTMach 대비).
   - PROVENANCE 새 행 둘(일곱 칸): `miniMonMachdep.c` 는 `darwin01+authored`(x86 07 판 = Darwin 0.1 그대로, D029; APSL), `next_exception.c` 는 `nextmach`(커밋 `f6bdb9c3…`, D013)입니다.
   - MODIFICATIONS, DECISIONS D135, 계획 결과와 현재 상태, HANDOFF, 메모리를 고칩니다.
   - M7 의무: `miniMonMDCommands` 를 쓰는 x86 공유 `kern/miniMon.c` 는 M5 객체이고, `_event_high` 이후 자료는 다른 객체의 것입니다.

관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 602.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 스테이지 키 변화는 `plan`·`m4_sources`·`files` 셋, 파일 965 → 967, `EXCEPTS[602]` 필요 | §600.2 의 같은 꼴 결과와 `stage_m68k.py` 표 규칙(§600.1 에서 확인) | ✅ (run 에서 assert) |
| F·L 객체의 바이트 비교(`cmp`)와 차이 설명을 §600 처럼 더할 것 — canon + `obj_sig` 는 STABS 수만 봄 | `l2_prefix_diff.py:48–52`(§600.1 에서 엶) | ✅ 4 에 더합니다: 바이트가 다르면 다른 바이트가 문자열 표·`n_strx` 에만 있음을 python 으로 확인 |
| 최종 명세는 두 객체(`m68k-300`·`m68k-301`, `x86_rel` 그대로, 변형 F)이고 `refs` 에 두 이름 모두 | `m4_m68k_probe.py` 명세 규칙(§600 최종 명세가 같은 꼴로 통과) | ✅ 5 를 그렇게 씁니다 |
| 한 기록에 두 객체를 담은 `ACCEPTED` 한 줄의 선례는 p497·p559 | 상태표의 기록 열 집계(이번 세션: p497·p559 가 각 세 객체) | ✅ |
| 기대 수치 35·28·59/188·59720·76756 맞음; `rows_unassigned_before` 에 `m68k-301` 이 더해짐; `object_bytes` 는 `__text` 구간 크기의 합 | `m4_m68k_status.py:146–152`(이번 세션), python 계산 | ✅ 6 에 더함 |
| D029 는 i386 machdep 에 관한 결정이므로, 출처 근거는 D135 와 D115 로 적을 것 | `DECISIONS.md` 33 행(D029: "i386 machdep 파일") | ✅ 7 의 출처 칸에 D135·D115 를 적고, x86 07 판이 Darwin 그대로임(D029)은 사실로만 적습니다 |
| N1 은 NeXTMach 와 include 9–11 행만 다름 | `diff`(이번 세션) | ✅ |
| 새 경로 둘을 더해도 받아들인 기록(M5 `kern/miniMon.c` 포함)은 영향이 없을 것 — 회귀로 확인 | 3 의 M5 205 줄 회귀와 상태 도구 재실행 | ⏭️ 실행으로 확인 |

### 602.2 결과(2026-10-30)

- 1·2: 07 `src/machdep/m68k/miniMonMachdep.c`(89 행, SHA `84084cad…`)와 `next_exception.c`(54 행, SHA `8605f15d…`)를 scratchpad `gen_p602.py` 로 만들었습니다. 두 파일 모두 주석을 뺀 토큰이 M1·N1 과 같고, L 과 줄마다 토큰이 같으며, 표시 줄에 `*/` 뒤 글이 없습니다(python). `miniMonMachdep.c` 의 설명 주석은 처음 "Lines marked plan 602 are not in the i386 file" 로 썼다가, 표시한 `{0,0,0}` 줄이 i386 판에도 있어 "differ from the i386 file" 로 고쳤습니다. `stage_m68k.py` 713 → 715 행입니다.
- 3: `--plan 600` 재생성(`m0p600-r602-stage`)이 보관본과 모든 키·파일이 같습니다. `m0p602-a1-stage`(967 파일)와 보관 600 의 차이는 두 파일과 키 `files`·`m4_sources`·`plan` 입니다(python assert). M5: `m5-600.cmd` 가 §600 것과 `cmp` 같고, run `m3p602-b600`·`m3p602-cc1` 종료 0, 객체 205 개 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p602-compare-20261030.json`, `-b600-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 두 파일이 더해진 것뿐입니다. x86 `m4-x86-inputs-p602-20261030.json` `ok`, `--plan 602 x86gate` 일곱 같음·`v183_paths` 0 입니다.
- 4: run `m4p602-p1`(`m4-m68k-probe-p602-p1-20261030.json`): 네 변형 모두 종료 0·경고 0·i386 0·`OBJECT_MATCH`·`full_span`·`candidate`, 6/6·1/1(`m4-m68k-funcbytes-p602-mm/ne-F/L-20261030.json`)입니다. F = L(canon·`obj_sig` 모든 칸, STABS 53·87), L = M1·N1 입니다. F·L 객체 바이트는 문자열 표와 `n_strx` 칸에서만 다릅니다(python, 소스 파일 이름).
- 5: run `m4p602-a1`(`m4-m68k-p602-final-20261030.json`, SHA `df9e2ff4…`; REF = p1 L 둘, `known_warnings` 없음): `gate.ok`, 6/6·1/1(`m4-m68k-funcbytes-p602-mm/ne-a1-20261030.json`)입니다. 확인 `m4-m68k-p602-checks-20261030.json`(`ok` 참): 섹션 54·12 / 76, 자료가 원본과 같고 재배치 0, 외부 정의 = 원본 이름(+ `_miniMonMDCommands`), 지역·COMMON·미정의 없음, 컴파일 명령 = M5 줄, 의존 6·22 파일 사슬 문제 0·i386 0 입니다. 객체 SHA `764a79b3…`·`56b13b30…` 입니다.
- 6: 근거 `m68k-miniMonMachdep.md`·`m68k-next_exception.md`(상태 도구 전). `ACCEPTED` 에 한 줄을 더했습니다. 상태표 35 → 37 행·`m4-m68k-status-p602-20261030.json`: 35 객체(OBJECT_MATCH 28, CODE+BSS_INFERRED 7), 덮은 행 59/188, 59720/215874 B(27.66%), `object_bytes` 76756 — 미리 계산한 객체·행·바이트 수와 같습니다. `rows_unassigned_before` 에 `m68k-301` 이 더해졌고, 두 번 실행이 같으며, §600 표와 이름 대조로 더한 것은 둘뿐·바뀐 것은 없습니다.
- 7: diff `m68k-miniMonMachdep.diff`(208 행)·`m68k-next_exception.diff`(22 행), PROVENANCE 1180 → 1182 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 717 → 719 행, DECISIONS D135(138 → 139 행), "현재 상태와 다음 일" 을 고쳤습니다.

## 603. M4-109 세부 계획 — m68k `PM*` 전원 관리 빈 함수(행 263) 진단(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: 후보 둘을 먼저 살폈습니다.
- `m68k_init`(행 302, 1774 B 한 함수)는 NeXTMach `next/next_init.c` 의 `NeXT_init` 의 1997 판입니다. 근거는 자료 `_event_high` → `&event_junk_h`(bss 0x40b55c4), `_event_middle`, `_default_page_size` 0x2000 입니다. 그러나 1997 판은 인자로 구조체 포인터 하나를 받고, 새 호출(`probe_rl`·`getlastaddr`·`km_send`·`en_bufalloc`·`gets`·`inet_aton`·`kdbg_connect`)을 하며, 0x40b2baa 의 8 항목 표를 씁니다. NeXTMach 의 `bzero`·`set_cpu_number` 호출은 이 함수에 없습니다(scratchpad `odis.py` 출력). 진단이 길어질 일이라 뒤로 둡니다.
- 행 263 은 참고 글이 바이트와 바로 맞아 보이는 작은 단위입니다.

확인한 사실(이번 세션; 원본은 scratchpad `odis.py` 로 풀었습니다):
- 행 263 [0x4090c8a, 0x4090d00) 은 118 B(python)이고, 정확 행·종류 `x86`(x86 원천 07 `machdep/i386/APM_i386.c`, D024 작성 파일)입니다. 진입점 아홉의 차례는 `PMConnect`·`PMDisconnect`·`PMSetCpuState`·`PMSetPowerState`·`PMGetPowerEvent`·`PMGetPowerStatus`·`PMSetPowerManagement`·`PMRestoreDefaults`·`PMUpdateClock` 입니다.
- 진입점 몸통:
  - 0 반환: 다섯(`clrl d0`)
  - `PMSetPowerState`: 0x03e80060 반환
  - `PMGetPowerEvent`: 0x03e80080 반환
  - `PMGetPowerStatus`: 인자 포인터에 255·255·0 을 쓰고 0 반환
  - `PMUpdateClock`: 빈 몸통
- 스테이지 `kern/power.h:37` 의 `pm_err(errno) = err_kern|err_sub(4000)|errno` 와 `mach/error.h:104·105·117` 로 python 계산하면 `PM_R_BAD_STATE` = `pm_err(0x60)` = 0x3e80060, `PM_R_NO_EVENT` = `pm_err(0x80)` = 0x3e80080 입니다. `PMPowerStatus`(`kern/power.h:115–118`)는 `lineStatus`·`batteryStatus`·`batteryLife` 차례이고, `PM_LINE_UNKNOWN`·`PM_BATT_UNKNOWN` 은 0xFF 입니다(`:104·112`).
- Darwin 0.1 `kernel/machdep/ppc/APM.c`(SHA-256 `dd1f283d…`, APSL; NeXT 1994 고지)는 같은 차례의 아홉 함수입니다. 몸통도 위와 같아 보입니다: `PM_R_SUCCESS` 다섯, `PM_R_BAD_STATE`, `PM_R_NO_EVENT`, 상태 셋을 채움, 빈 `PMUpdateClock`. 이 파일은 Darwin `kernel/machdep` 안의 파일이므로 D030 예외에 들지 않습니다. 쓰려면 APSL 고지와 출처 기록이 있어야 합니다(AGENTS).
- 자료 지도에 이 객체에 매긴 자료는 없습니다(grep `APM` 0). 지도는 추정이므로 원본 자료가 없다는 증명은 아닙니다.

방법(진단; 명세 `08_build/artifacts/m4p603/spec.json`, run `m4p603-p1`, 바탕 `m0p602-a1-stage`; scratchpad `gen_p603.py`): 변형 P1 은 Darwin 0.1 `ppc/APM.c` 글 그대로입니다(`m4_id` `m68k-263`, `x86_rel` `machdep/i386/dkbad.c`). 07 판은 아직 정하지 않습니다.

측정(§601.1 의 강화한 꼴):
- 종료·경고·i386 0
- `-c`·`-o` 를 뺀 전체 컴파일 명령이 M5 줄과 같음(python)
- 섹션(`__text` 118 만 기대)
- funcbytes 9/9
- L1 `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`
- 외부 정의 = 원본 이름 아홉, 지역·COMMON·미정의 없음

판정(미리 정함; 07 은 바꾸지 않음):
- 맞으면, 07 꼴(Darwin ppc 글 그대로를 m68k 파일로 둘지, 다른 꼴로 둘지와 파일 이름)을 사용자에게 묻습니다. 그 뒤 구현 계획(§604)을 씁니다.
- 맞지 않으면 차이를 적고 다음 진단으로 갑니다.

관문: 종료 0, 경고 0(있으면 기록하고 판정을 보류합니다), i386 0, 옵션 = M5 줄입니다. 성공 조건은 9/9, L1 `OBJECT_MATCH`·사유 없음, `full_span`, `candidate`, 재배치 0, 지역·COMMON·미정의 없음입니다. 의존 목록과 소스 해시도 기록합니다.

### 603.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다:
- "인자로 구조체 하나를 받고" 는 부정확했습니다. 원본은 `a6@(8)` 을 `a4` 에 읽고(0x4094b06) `a4@(4)` 등을 읽으므로 "구조체 포인터 하나" 입니다.
- "NeXTMach 호출(`bzero`·`set_cpu_number`)은 없습니다" 는 `m68k_init` 안의 호출을 말한 것입니다. `_bzero` 자체는 원본에 있습니다.
- `m68k_init` 이 `NeXT_init` 의 1997 판이라는 것과 bss 0x40b55c4·0x40b55c8 이 `event_junk_*` 라는 것은 자료 값과 NeXTMach 글에서 끌어낸 추정입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 바이트 사실(118 B, 차례, 0x03e80060·0x03e80080, 255/255/0 이 +0/+4/+8, 빈 `PMUpdateClock`) 맞음; 행 264 는 바로 뒤 `__ashldi3` 에서 시작 | `odis.py` 출력과 python 계산(이번 세션), `symbols.tsv` 의 0x4090d00 `__ashldi3` | ✅ |
| ppc `APM.c` 의 정의는 스테이지 원형과 맞고 값으로 넘기는 구조체 인자는 문제 없을 것 — 바이트는 P1 이 정함 | — | ⏭️ 진단으로 |
| 라이선스 진술 맞음(AGENTS 6 행, D030 은 Darwin `kernel/machdep` 밖만); D029 는 i386, D115 는 개별 선례일 뿐이고, x86 APM 의 작성 출처는 ppc 글에 옮겨지지 않음 | `DECISIONS.md` 33·34 행(이번 세션) | ✅ 07 꼴은 사용자에게 묻습니다 |
| `m68k_init` 미룸 사유: 구조체 포인터, 새 호출, 0x40b2baa 표 `[16,20,25,33,40,50,66,80]`, `bzero`·`set_cpu_number` 호출 없음(NeXTMach `next_init.c:134·371`) | 원본 풀이 0x4094b06, python 표 값, NeXTMach 134·371 행(이번 세션) | ✅ 문구를 고칩니다(위) |
| `diag_gate` 는 경고 0 을 요구함 — "경고는 기록" 과 맞출 것 | `m4_m68k_probe.py:382–383`(이번 세션) | ✅ 관문을 "경고 0(있으면 기록하고 판정 보류)" 로 고칩니다 |
| 성공 조건에 `OBJECT_MATCH`·사유 없음·`full_span`·`candidate`·9/9 를 명시하고, 재배치 0·지역·COMMON·미정의·의존과 소스 해시를 볼 것 | — | ✅ 측정에 더합니다 |
| 자료 지도에 없다는 것은 "지도에 자료가 없다" 일 뿐, 원본 자료가 없다는 증명은 아님 | 자료 지도 머리 줄(§601.1 에서 읽음) | ✅ 문구를 고칩니다 |

### 603.2 결과(run `m4p603-p1`, 2026-10-30)

- P1(Darwin 0.1 `ppc/APM.c` 그대로, SHA-256 `dd1f283d…`): 종료 0, 경고 0, i386 0 입니다. `-c`·`-o` 를 뺀 컴파일 명령은 M5 줄과 같고(python), 의존 98 파일입니다. 기록은 `09_validation/reconstruction/m4-m68k-probe-p603-20261030.json` 입니다.
- `__text` 118 하나(재배치 0), 9/9(`m4-m68k-funcbytes-p603-P1-20261030.json`), L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate` 입니다. 외부 정의는 원본 이름 아홉과 같고, 지역·미정의는 없습니다.
- 미리 정한 성공 조건 가운데 "COMMON 없음" 만 맞지 않습니다. COMMON `_master_cpu` 하나가 있습니다. 출처는 07 `kern/cpu_number.h` 의 임시 정의(plan 400, Mach4 `kern/cpu_number.h:36` 꼴)이고, 원본 `__common` 0x40b59d4 에 있는 이름입니다. 지금까지 받아들인 객체는 모두 "COMMON 이 모두 원본에 있음" 으로 판정했습니다(예: `machdep` 52 개). §603.1 에서 조건을 "없음" 으로 적은 것은 그보다 엄격했습니다. 정한 기준을 결과를 본 뒤 제가 늦추지 않고 사용자에게 묻습니다.

- 사용자 결정(2026-10-30, AskUserQuestion): COMMON 기준은 "'COMMON 없음' 유지", 07 꼴은 "Darwin ppc APM.c 그대로, `APM.c`" 입니다.
- 두 결정이 함께 성립하지 않음을 확인했습니다(python 으로 의존 목록에서 include 고리를 따라감): `APM.c` → `kern/power.h` → `mach/mach_types.h` → `mach/std_types.h` → `ipc/ipc_port.h` → `ipc/ipc_mqueue.h` → `ipc/ipc_kmsg.h` → `kern/cpu_number.h:61` 의 `int master_cpu;`(plan 400, x86·M5 가 함께 쓰는 07 머리)입니다. 글을 그대로 두면 이 COMMON 은 공유 머리를 고치지 않고는 없앨 수 없습니다. 공유 머리를 고치면 x86 바이트 같음과 M5 객체(§441·§467 의 207 개 가운데 97 개가 이 COMMON 을 가짐)에 영향이 갑니다. 받아들인 M4 객체 35 개 가운데 15 개에도 이 COMMON 이 있습니다(python). 그래서 사용자에게 다시 묻습니다.
- 사용자 결정(2026-10-30, AskUserQuestion 다시): "이 COMMON 은 통과로" 입니다. `APM.c` 는 Darwin 글 그대로 둡니다. 공유 머리가 내는 COMMON 가운데 이름이 원본에 있는 것(`_master_cpu`)은 통과로 보고, 합치는 일은 M7 의무로 둡니다. 앞의 "'COMMON 없음' 유지" 는 이 객체에 대해 이 결정으로 바뀌었습니다.

## 604. M4-110 D136 구현 계획 — 07 `src/machdep/m68k/APM.c`(행 263, OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §603.2 결과와 위 결정입니다. 스테이지 `m0p602-a1-stage` 에 `src/machdep/m68k/APM.c` 는 없습니다(1 에서 python 으로 확인).
1. 07 `src/machdep/m68k/APM.c`(D103) = Darwin 0.1 `kernel/machdep/ppc/APM.c` 그대로입니다(SHA-256 `dd1f283d…`, `cmp` 같음). 고지(APSL·NeXT 1994)를 포함해 바꾼 줄이 없으므로 "Modified" 줄과 표시는 두지 않습니다.
2. `stage_m68k.py`: `M4FILES[604] = list(M4FILES[602]) + ['APM.c']`, `EXCEPTS[604] = dict(EXCEPTS[602])`, 머리말 plan 목록에 604 를 더합니다. 나머지 표는 그대로 둡니다.
3. 회귀(§602 와 같은 꼴):
   - `--plan 602` 재생성(`m0p602-r604-stage`) = 보관본이어야 합니다.
   - `m0p604-a1-stage` 와 보관 602 의 차이는 `src/machdep/m68k/APM.c` 하나(967 → 968)와 키 `plan`·`m4_sources`·`files` 여야 합니다.
   - M5 205 줄(`m5-602.cmd` 가 §602 것과 `cmp` 같음; run `m3p604-b602`·`m3p604-cc1`): 객체·stderr 205 같음, `compare` 의 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 `APM.c` 가 더해진 것뿐이어야 합니다.
   - x86: `m4_x86_inputs.py s6ln`·`--plan 604 x86gate` 일곱이 같아야 합니다.
4. 확인 run `m4p604-p1`(바탕 `m0p604-a1-stage`): F = `@machdep/m68k/APM.c`, L = P1 글(같은 글이므로 줄 위치도 같음)입니다. 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = P1(canon), 9/9, `OBJECT_MATCH`·`full_span`·`candidate` 이어야 합니다. F·L 객체 바이트 차이는 문자열 표·`n_strx` 에만 있어야 합니다(python).
5. 최종 run `m4p604-a1`(명세 `08_build/artifacts/m4p604/spec.json`: F 만, `m4_id` `m68k-263`, `refs["APM"]` = p1 L 객체·SHA-256, `known_warnings` 없음; 기록 `m4-m68k-p604-final-20261030.json`)을 돌립니다.
   - 관문: `gate.ok`, 9/9 입니다.
   - python 확인 `m4-m68k-p604-checks-20261030.json`: `__text` 118 만·재배치 0, 외부 정의 = 원본 이름 아홉, 지역·미정의 없음, COMMON 은 `_master_cpu` 하나이고 원본에 있음(D136), L1 사유 없음, 컴파일 명령 = M5 줄, 의존 i386 0, 입력 사슬 전수, 07 파일 = Darwin 원문(`cmp`)입니다.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-APM.md` 를 먼저 쓰고 `ACCEPTED` 에 한 줄을 더합니다. 도구를 두 번 돌리고 §602 표와 이름을 대조합니다.
   - 기대(python): 객체 36(OBJECT_MATCH 29), 덮은 행 60/188, 덮은 바이트 59720 + 118 = 59838, `object_bytes` 76756 + 118 = 76874 입니다. 백분율은 도구 출력을 씁니다.
7. 기록:
   - PROVENANCE 새 행(일곱 칸): `darwin01`, `kernel-1.tar.gz` SHA-256, `darwin01/kernel/machdep/ppc/APM.c`, APSL(`07_kernel/LICENSES/APSL-1.0.txt`), "none (verbatim)", 파일 SHA, 최종 기록, `M4FILES[604]`.
   - MODIFICATIONS 에 한 행을 더합니다.
   - DECISIONS D136: 07 꼴(Darwin ppc 글 그대로, `APM.c`)과 COMMON 판정(이 객체는 원본에 있는 COMMON 통과)을 적습니다.
   - 계획 결과와 현재 상태, HANDOFF, 메모리를 고칩니다. diff 는 Darwin 원문과 같으므로 만들지 않고, 그 사실을 근거 문서에 적습니다.
   - M7 의무: `_master_cpu` COMMON 합침, PM 함수를 부르는 쪽은 다른 객체입니다.

관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 604.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1–7 은 §602 꼴과 같고, 확인·최종 명세는 `name` `APM`·`x86_rel` `machdep/i386/dkbad.c`·`m5_line` 을 진단 명세처럼 둘 것; 기대 수치 36·29·60/188·59838·76874, 스테이지 967 → 968 | python 계산(이번 세션), `m4p603/spec.json` | ✅ |
| "Modified" 줄·표시 없이 그대로 두는 것은 AGENTS 6 행과 PROVENANCE 174 행(`miniMonMachdep.c` i386, "none (verbatim; file SHA-256 …)")의 꼴과 맞음; 파일 이름 `APM.c` 는 사용자 결정이고, Darwin `ppc` 경로는 출처일 뿐 원본 파일 이름의 증거가 아님 | PROVENANCE 174 행(§601 에서 읽음), 위 사용자 결정 | ✅ 근거 문서에 "파일 이름은 원본 바이트로 정해지지 않음" 을 적음 |
| 관문·상태 도구는 "COMMON 이 원본에 있음" 을 스스로 요구하지 않음 — 기록 파일에서 단언할 것; `obj_sig` 의 REF 비교에는 COMMON 이름·종류·크기가 들어감 | `m4_m68k_probe.py:363–364`(외부 정의와 COMMON 을 기록할 뿐 판정하지 않음), `l2_prefix_diff.py:48–52` | ✅ 5 그대로(확인 기록에서 단언) |
| 스테이지에 다른 APM 파일은 `src/machdep/i386/APM_i386.c` 뿐, M5 줄에 APM 없음 | find·grep(이번 세션) | ✅ |

### 604.2 결과(2026-10-30)

- 1·2: 07 `src/machdep/m68k/APM.c` = Darwin 원문(`cmp` 같음, SHA `dd1f283d…`). `stage_m68k.py` 715 → 717 행입니다.
- 3: `--plan 602` 재생성(`m0p602-r604-stage`) = 보관본입니다. `m0p604-a1-stage`(968 파일)와 보관 602 의 차이는 `APM.c` 하나와 키 `files`·`m4_sources`·`plan` 입니다(python assert). M5: `m5-602.cmd` 가 §602 것과 `cmp` 같고, run `m3p604-b602`·`m3p604-cc1` 종료 0, 객체·stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p604-compare-20261030.json`, `-b602-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 `APM.c` 가 더해진 것뿐입니다. x86 `m4-x86-inputs-p604-20261030.json` `ok`, `--plan 604 x86gate` 일곱 같음입니다.
- 4: run `m4p604-p1`(`m4-m68k-probe-p604-p1-20261030.json`): F·L 종료 0·경고 0·i386 0·`OBJECT_MATCH`·`full_span`·`candidate`, 9/9(`m4-m68k-funcbytes-p604-F/L-20261030.json`)입니다. F = L(canon·`obj_sig` 모든 칸, STABS 548), L = P1 이고, F·L 바이트는 문자열 표·`n_strx` 에서만 다릅니다(python).
- 5: run `m4p604-a1`(`m4-m68k-p604-final-20261030.json`, SHA `dec87ebb…`; REF = p1 L, `known_warnings` 없음): `gate.ok`, 9/9(`m4-m68k-funcbytes-p604-a1-20261030.json`)입니다. 확인 `m4-m68k-p604-checks-20261030.json`(`ok` 참): `__text` 118 만·재배치 0, 외부 정의 = 원본 아홉, 지역·미정의 없음, COMMON `_master_cpu` 하나(원본에 있음, D136), 컴파일 명령 = M5 줄, 의존 98 파일 사슬 문제 0·i386 0, 07 파일 = Darwin 원문입니다. 객체 SHA `c1fe22d4…` 입니다.
- 6: 근거 `06_reconstruction/evidence/m68k-APM.md`(상태 도구 전). `ACCEPTED` 에 한 줄을 더했습니다. 상태표 37 → 38 행·`m4-m68k-status-p604-20261030.json`: 36 객체(OBJECT_MATCH 29, CODE+BSS_INFERRED 7), 덮은 행 60/188, 59838/215874 B(27.72%), `object_bytes` 76874 — 미리 계산한 값과 같고, 두 번 실행이 같으며, 더한 것은 `APM` 뿐·바뀐 것은 없습니다.
- 7: PROVENANCE 1182 → 1183 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 719 → 720 행, DECISIONS D136(139 → 140 행), "현재 상태와 다음 일" 을 고쳤습니다. 07 이 Darwin 원문과 같으므로 diff 파일은 만들지 않았습니다.

## 605. M4-111 세부 계획 — m68k `m68k_init`(행 302, NeXTMach `next/next_init.c`) 첫 진단 A1(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: 남은 이웃 후보를 견주었습니다.
- 행 264·291(`__ashldi3`·`__bdiv`·`__lshldi3`·`__lshrdi3`)은 §422 에서 "libcc 구성원이 아닌 출처 미상 구현" 으로 정했고 참고 글이 없습니다.
- `pcb.c`(행 308–309)는 Darwin i386 `pcb.c` 와 대부분의 함수가 같은 차례이지만(`thread_dup` 자리는 다름), m68k `struct pcb` 전체가 필요합니다. 그런데 M5 객체가 쓰는 07 `v183.34/m68k/src/machdep/m68k/thread.h` 는 `pcb_head[0x48]` 로 앞부분만 둡니다. 공유 머리를 고치는 일이 따릅니다.
- `nextdbg`(행 304–306)는 1997 새 함수(`dbg_process` 1810 B·`gdb_from_trap`·`dbg_from_ether`)가 많습니다.
- `m68k_init` 은 NeXTMach 바탕이고, 자료가 NeXTMach 와 맞는 닻이 있습니다.

확인한 사실(이번 세션; scratchpad `odis.py`·python):
- 행 302 [0x4094afe, 0x40951ec) 는 1774 B 의 함수 `_m68k_init` 하나입니다. 다음 객체 `next_table`(§508 받아들임)이 0x40951ec 에서 시작합니다.
- 원본 `__data` [0x40b2b9e, 0x40b2bca) 44 B 는 다음과 같습니다.
  - `_event_high` = 0x040b55c4, `_event_middle` = 0x040b55c8: 둘 다 bss 안을 가리키며, NeXTMach `next_init.c` 의 `static unsigned int event_junk_h, event_junk_m;` 과 `*event_high = &event_junk_h` 꼴로 봅니다(추정).
  - `_default_page_size` = 0x2000: NeXTMach `= 8192`.
  - 이름 없는 4 B 항목 여덟 `[16, 20, 25, 33, 40, 50, 66, 80]`: `m68k_init` 이 0x4094b9a·0x4094c4e 에서 `lea 0x40b2baa` 후 `moveb a0@(3,d0:l:4)` 로 읽습니다.
  - 그 뒤 0x40b2bca 는 `_pmap_gc`(다음 객체) 입니다. 그래서 이 객체의 자료는 44 B 로 봅니다(가설).
- 1997 판은 NeXTMach `NeXT_init(ra, mg, cons_i, …)` 의 여러 인자 대신 구조체 포인터 하나(`a6@(8)`)를 받습니다. 새 호출(`probe_rl`·`getlastaddr`·`km_send`·`en_bufalloc`·`gets`·`inet_aton`·`kdbg_connect`)이 있고, NeXTMach 의 `bzero`·`set_cpu_number` 호출은 없습니다. `dma_chip = 313` 꼴(0x139)과 slot·`P_EVENTC` 꼴의 주소 계산은 남아 있습니다.

방법(진단; 명세 `08_build/artifacts/m4p605/spec.json`, run `m4p605-p1`, 바탕 `m0p604-a1-stage`, `m4_id` `m68k-302`; scratchpad `gen_p605.py`): A1 = NeXTMach `next/next_init.c` 에 다음만 바꾼 글입니다(진단 표시).
- include 를 §580–600 의 `machdep` 꼴로 바꿉니다: `vm/vm_param.h`·`vm/vm_prot.h` → `mach/`, `next/cpu.h` → `m68k/cpu.h`, `next/vm_param.h` → `mach/m68k/vm_param.h`, `next/cons.h` → `m68k/cons.h`, `next/eventc.h` → `machdep/m68k/eventc.h`, `nextdev/snd_dspreg.h`·`nextdev/monreg.h` → `dev/m68k/`, `next/bmap.h` → `m68k/bmap.h`.
- `next/pcb.h`·`next/scr.h` 는 들이지 않습니다(`machdep` 과 같은 까닭).
- 함수 이름을 `NeXT_init` → `m68k_init` 으로 바꿉니다(원본 기호).
- 표시 주석은 `*/` 뒤에 글이 남지 않게 python 으로 확인합니다.

측정: 컴파일이 실패하면 오류 목록(없는 이름 분류)을 봅니다. 컴파일되면 섹션 크기·funcbytes(0/1 이면 `fdiff3.py` 꼴의 명령 비교)·자료·COMMON 을 봅니다. A1 은 출발점이며, 맞기를 기대하지 않습니다.

판정(미리 정함; 07 은 바꾸지 않음): 결과를 적고, 다음 진단(B 계열)에서 바이트로 1997 꼴을 차례로 채웁니다. 바이트로 가를 수 없는 꼴은 07 전에 사용자에게 묻습니다.

관문: 컴파일 명령이 M5 줄과 같음, i386 0. 종료·경고는 기록합니다(진단).

### 605.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다: `pcb.c` 를 "Darwin i386 `pcb.c` 와 함수 차례가 같다" 고 적었으나, 원본은 `thread_dup` → `thread_userstack` → `thread_entrypoint` 이고 Darwin 은 `thread_userstack`(1124 행) → `thread_entrypoint`(1158) → `thread_dup`(1196) 입니다. "대부분의 함수가 같은 차례" 로 고칩니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 바이트 사실(1774 B, 자료 44 B 값, 표 읽기 0x4094b9a·0x4094c4e, `a6@(8)` → `a4`, 새 호출, `dma_chip` 313 at 0x4094bec·0x4094c0a, `_pmap_gc` 0x40b2bca, 사건 포인터가 bss 안) 맞음 | scratchpad `m68k_init.ann`(기호 붙인 풀이, 이번 세션)과 python 자료 읽기·전체 참조 검색 | ✅ |
| include 경로는 모두 있으나 선언이 모자랄 것: `NeXT_page_size`·`NeXT_trunc_page`(SDK `mach/m68k/vm_param.h` 는 `m68k_` 로 바꿈), `P_*`·`slot_id` 등 `next/cpu.h` 이름, `scr1`·`scr2`·`brightness`·`MACHINE_TYPE`·`BOARD_REV`, CACR 이름(스테이지 `bsd/m68k/mmu.h:119·127·128` 에 있으나 들이지 않음), `struct bootp`(`mon/global.h` 에서 `tftp.h` 를 뺀 뒤 `mon/bootp.h` 미스테이지), `REGION_MEM`·`region_type`(스테이지 `vm/pmap.h:167–178` 에 없음) | 스테이지 머리 6–12 행·`mmu.h`·`global.h:47–51`·`pmap.h:167–178`(이번 세션) | ✅ 측정에 "예상 실패 목록" 을 적고, A1 은 그 확인용으로 돌립니다 |
| 44 B 자료 소유는 합당한 가설(표 참조는 `m68k_init` 두 곳뿐, pmap 참조 없음)이나 자료 지도와는 다르게 묶임 — 그 구분을 둘 것 | 원본 `__text` 전체 4 B 값 검색(이번 세션: 0x40b2baa 는 `m68k_init` 의 0x4094b9c·0x4094c50 뿐) | ✅ 가설로 둡니다 |
| 원본 진입점 0x4094afe 를 부르는 곳은 0x4001328 하나 | — | ⏭️ 판정에 쓰지 않음 |
| 0x4094bbe–0x4094be6 은 40 B 의 switch 표 — 명령 비교에서 빼야 함 | python 0x4094be6 − 0x4094bbe = 40 | ✅ 비교 때 뺍니다 |
| 측정에 더할 것: 재배치를 고려한 호출·자료 참조 차이, 부트 인자 구조체 필드 자리, `pmap_bootstrap` 인자 꼴, COMMON 이름과 크기, 사건 포인터의 bss 자리, 실패해도 `-M` 의존 출처 기록 | — | ✅ 측정에 더합니다 |

계획 수정(측정): A1 이 컴파일에 실패하면 오류를 위 예상 목록과 대조해 분류하고, `-M` 결과(성공 시)의 의존 출처를 기록합니다. 컴파일되는 진단부터는 funcbytes(1 함수)·`fdiff3.py` 꼴 명령 비교(0x4094bbe–0x4094be6 switch 표 제외)·재배치 대상·COMMON 이름과 크기·자료 44 B·bss 를 봅니다.

### 605.2 결과(run `m4p605-p1`, 2026-10-30)

- A1(`next_init_A1.c`, 386 행): 컴파일 실패(종료 1). `-M` 은 성공(i386 0)입니다. 기록은 `09_validation/reconstruction/m4-m68k-probe-p605-20261030.json` 입니다.
- 예상한 오류(§605.1):
  - `slot_id`·`slot_id_bmap`·`disk_chip`·`scr1`·`P_SCR1`·`NeXT_CUBE` 등 기계 이름
  - `P_BMAP`
  - CACR 셋
  - `intrmask`·`P_INTRMASK`·`P_INTRSTAT`·`intr_mask`·`P_EVENTC`·`scr2`·`P_SCR2`·`SCR2_EKG_LED`·`brightness`·`P_BRIGHTNESS`·`P_TIMER_CSR`·`P_TIMER`
  - `NeXT_page_size`
  - `region_type`·`REGION_MEM`
  - `struct bootp` 크기 미정(95 행)
- 예상하지 못한 오류: `#import <nfs/nfs.h>`(73 행)가 `fsid_t` 를 몰라 `nfs.h:121·130` 에서 구문 오류를 냅니다. 원본 기호표에는 `_bootp`(0x40c95a0)·`_boot_dev`·`_boot_file`·`_boot_info`·`_etheraddr`·`_mon_global`·`_disr_shadow`·`_eventc_h` 가 있습니다(grep).
- 원본 풀이에서 찾은 사실(scratchpad `m68k_init.ann`): 1997 판이 `a4`(=`a6@(8)`)로 읽는 자리는 NeXTMach 인자 차례와 하나하나 맞습니다. +4 `mg`(`mon_global`·`a5`), +8 `cons_i`, +12 `cons_o`, +16 `dev`(`boot_dev` 8 B 복사), +20 `args`, +28 `sid`(`slot_id`·`slot_id_bmap`), +36 `mon_nr`(`num_regions`), +40 `mon_rp`(+0·+4 를 8 B 걸음으로), +44 `clientetheraddr`(6 B 복사), +48 `file`(`boot_file` 0x40 B 복사)입니다. 곧 같은 모니터 인자를 인자 덩이의 포인터로 읽는 꼴입니다.
- 다음: 진단 B1 을 따로 계획합니다(§606). 1997 판의 차례를 원본 풀이대로 세우고, NeXTMach 줄을 바이트에 맞춰 고칩니다.

## 606. M4-112 세부 계획 — `m68k_init` 의 1997 꼴 진단 B1(07 변경 없음; 코딩 전, 2026-10-30)

목적: 원본 풀이(scratchpad `m68k_init.ann`)의 차례대로 1997 `m68k_init` 을 세우고, NeXTMach 줄은 바이트에 맞게 고쳐 처음으로 컴파일되는 진단을 얻습니다. 그다음 함수 바이트 차이를 좁혀 갑니다.

원본에서 읽은 1997 꼴(주소는 원본, 값은 python 으로 16 진 환산):
1. 인자: 인자 덩이 포인터 하나(`a6@(8)`)를 받습니다. 필드 자리는 NeXTMach 인자 차례 그대로입니다(§605.2). 진단 이름은 `struct m68k_init_args`(작성 이름 — 07 전에 사용자에게 묻습니다)이고, `ra`·`mg`·`cons_i`·`cons_o`·`dev`·`args`·`info`·`sid`·`mon_pagesize`·`mon_nr`·`mon_rp`·`clientetheraddr`·`file` 를 각 4 B 로 둡니다.
2. `bzero` 호출이 없습니다. `slot_id = slot_id_bmap = sid`(둘 다 인자에서 다시 읽음)입니다.
3. SCB(0x4094b1e–0x4094b4a): `mon_scb = get_vbr()` 다음에 `scb_issp`·`scb_ipc` 를 복사합니다. 이어 `reboot_vector = mon_scb->scb_trap[13]`(+180, 07 `next/scb.h` 의 `scb_trap` 는 +0x80) 와 `scb.scb_trap[13] = 0x4002262 의 함수` 를 둡니다(그 기호 이름은 원본 기호표에서 찾음). 마지막으로 `set_vbr(&scb)` 입니다. `GDB` 갈래는 없습니다.
4. 기계 판별(0x4094b50–0x4094c7e):
   - `scr1` 낱말을 `slot_id + 0x0200c000` 에서 읽습니다. 비트 필드 [16,8) 의 위 4 비트가 4 면 `slot_id + 0x02200000` 에서 다시 읽습니다.
   - `cpu_rev` = 그 8 비트, `machine_type` = 위 4 비트, `board_rev` = 아래 4 비트, `cpu_clk` = 8 항목 표[비트 [29,3)] 의 낮은 바이트입니다(표는 파일의 정적 자료 — 이름·형은 묻습니다).
   - `switch (machine_type)`(0–9, 표 점프)의 갈래:
     - 0: `cpu_type = 0`, `dma_chip = 313`
     - 1–3: `cpu_type = 1`, `slot_id_bmap += 0x00100000`, `dma_chip = 313`, `bmap_chip = slot_id + 0x020c0000`
     - NeXTMach 의 `disk_chip = 310`·`bmap_chip = 0`·`scr1 = …` 대입은 1997 판에 없습니다.
   - 그 밖: `cpu_type = 1`, `dma_chip` = `slot_id + 0x0200c001` 의 바이트, `cpu_clk` = 표[비트 ^ 4], `if (probe_rl(slot_id + 0x02210000)) { ncc_chip = 1; cpu_clk = 40; }`
5. `cache = cpu_type ? 0x80008000 : 0x1919` 입니다(NeXTMach `CACR_*` 꼴, 이름은 스테이지 `bsd/m68k/mmu.h` 를 들여 씀).
6. 레지스터 포인터: `intrmask`·`intrstat` 는 `slot_id` 기준이고, `eventc_*`·`brightness`·`timer_*` 는 `slot_id_bmap` 기준입니다. `*scr2 &= 0x7ffffffe` 를 합니다. 값은 원본과 같게 둡니다(이름은 NeXTMach `next/cpu.h`·`next/scr.h` 의 것을 파일 안에, `machdep` 꼴).
7. `mon_global = mg`, `bcopy(clientetheraddr, etheraddr, 6)`, `hostid` 계산, `strncpy` 둘(8·0x40 B)은 NeXTMach 와 같습니다.
8. 인자 읽기 고리는 `strncmp("pagesize=", …, 9)`·`("mem=", …, 4)` 로 NeXTMach 와 같습니다. 페이지 크기는 4096·8192 만 받고(2048 없음) `m68k_page_size` 를 씁니다(SDK `mach/m68k/vm_param.h` 이름).
9. 영역 고리는 NeXTMach 의 두 고리를 하나로 합친 꼴입니다(0x4094e9e–0x4094f4c). `skip` 이면 첫·끝 주소와 크기를 0 으로 둡니다. 크기 제한 조건은 `if (mem && !skip && mem_size + size >= mem)`(무부호, 0x4094f00 의 `cmpl d0,d4; bhi`)이고, 고리 비교는 부호 있음입니다. 그리고 `pmsgbuf = m68k_trunc_page(mon_rp[i].last_phys_addr) + 256`(조건은 `mon_rp[i].first_phys_addr`)을 둡니다. `mem_region` 은 OPENSTEP `vm/pmap.h` 의 꼴(+20 `first_phys_addr`, +24 `last_phys_addr`, 28 B)이고 `region_type` 은 없습니다.
10. 콘솔 두 `switch` 는 NeXTMach 와 같습니다(`#if 0` 갈래 없음). `see_msgs` 와 `kminit`·`kmpopup` 도 같습니다.
11. `boot_args = args; getargs(args, 0);` 다음에 `printf("NeXT ROM Monitor %d.%d v%d\n", …)`, `tick`·`tickadj`, `mon_reset()` 입니다.
12. 1997 에 새로 더해진 부분:
    - `if (dma_chip != 313) { km_send(0xc5, 0xf0000000); mon_rev = (slot_id + 0x0200e008 의 32 비트 낱말 >> 16) 의 낮은 바이트; }`
    - `master_cpu = 0;` 과 `machine_slot[master_cpu].running = TRUE;`
    - NCPUS 고리: `is_cpu = TRUE`, `cpu_type = 6`, `cpu_subtype = machine_type ? 2 : 1`, `clock_freq = cpu_clk`, `interrupt_stack[i] = 0x4000318 + i*4096`(그 기호는 원본에서 찾음)
    - `mem_region[0].first_phys_addr = getlastaddr();`
    - `pmap_bootstrap(mem_region, num_regions, &virtual_avail, &virtual_end, (vm_offset_t)pmsgbuf - 256)` 의 인자 꼴을 풀이에 맞춤
    - `en_bufalloc(0)`
    - `if (breakpoint) { if (kdb_ipaddr == 0) { 지역 버퍼 32 B 에 do { printf("ip address? "); gets(buf, buf); } while (!inet_aton(buf, &addr)); kdb_ipaddr = addr; } printf("Waiting for connection from debugger\n"); while (kdb_net 의 +8 필드(32 비트) == 0) kdbg_connect(0); }`(0x40951ce 의 `bras` 가 첫 호출 전에 검사로 감)
    - `kdb_net` 의 형은 모르므로 진단에서는 필드 하나를 가진 구조체 extern 으로 둡니다.
13. `set_cpu_number`·`_nextdbginit`·`mallocdebuginit` 호출, `struct bootp bootp` 정의, `rpc/types.h`·`nfs/nfs.h` import 는 뺍니다(원본 기호 `_bootp` 는 COMMON 일 수 있어 측정에서 봄).
14. 파일 범위 자료는 원본 자료 44 B 의 차례(`event_high`·`event_middle`·`default_page_size`·표)를 따릅니다. NeXTMach 의 다른 전역(`eventc_*`·`mem_size` 등)은 정의 꼴 그대로 두고, COMMON 으로 나오는지 봅니다.

방법(진단; 명세 `08_build/artifacts/m4p606/spec.json`, run `m4p606-p1`, 바탕 `m0p604-a1-stage`; scratchpad `gen_p606.py`): B1 = A1 에 위 1–14 를 반영한 글입니다(모든 바꾼 줄에 진단 표시, `*/` 뒤 글 없음 확인).

측정:
- 종료·경고·i386 0
- `__text` 크기(1774 기대)·funcbytes(1 함수)
- 명령 비교: `fdiff3.py` 꼴로 하되 0x4094bbe–0x4094be6 switch 표 40 B 는 뺍니다.
- 재배치 대상, `__data` 44 B 와 기호 자리, bss(사건 쓰레기 둘)
- COMMON 이름과 크기, 원본에 없는 미정의
- `-M` 의존 출처

판정(미리 정함; 07 은 바꾸지 않음): 맞지 않는 자리를 적고 다음 진단(B2…)에서 바이트로 고칩니다. 맞으면 바이트로 가를 수 없는 꼴·이름을 사용자에게 묻습니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 606.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다: 디버거 기다림을 `do … while` 로 적었으나, 원본은 0x40951ce 에서 바로 검사(0x40951da)로 가므로 `while (…) kdbg_connect(0);` 입니다. 영역 제한 조건도 NeXTMach 의 `>` 가 아니라 무부호 `>=` 입니다. 위 계획 4·9·12 를 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 인자 자리, `slot_id`·`slot_id_bmap` 따로 읽기, SCB 복사, `scb_trap[13]` = `_mon_exit`(0x4002262), `reboot_vector` | `m68k_init.ann` 0x4094b06–0x4094b4a, 기호표 0x4002262 `_mon_exit`(이번 세션) | ✅ |
| 기계 판별: 비트 필드, 형 4 이면 다시 읽기, 시계 색인 = 낱말 & 7, 표 +4i+3 바이트; switch 0→0x4094be6, 1–3→0x4094bf8, 4–9 와 9 초과→0x4094c26 | python 으로 표 10 항목 읽음(이번 세션), 풀이 0x4094bb0 `bcss` | ✅ |
| NeXTMach 의 `disk_chip`·`bmap_chip = 0`·`scr1` 대입은 없음 | 풀이 0x4094b50–0x4094c7e 에 그 저장 없음 | ✅ 계획 4 에 적음 |
| `scr2` 는 `slot_id` 기준(+0x0200d000), 나머지 레지스터 기준은 계획대로 | 풀이 0x4094d3e–0x4094d4a | ✅ |
| 영역 고리 조건은 무부호 `>=`, 고리 비교는 부호 있음, `pmsgbuf` 는 원래 모니터 영역 값 | 풀이 0x4094ea8·0x4094f00–0x4094f02·0x4094f20–0x4094f36 | ✅ 계획 9 고침 |
| `printf` 인자는 `mg_major`(786)·`mg_minor`(778)·`mg_seq`(780) 차례 | 07 `mon/global.h:109·111`, `mon/assym.h` `MG_seq 780`(이번 세션) | ✅ |
| `mon_rev` = (`slot_id + 0x0200e008` 낱말 >> 16) 의 낮은 바이트 | 풀이 0x40950b0–0x40950c4(`swap`·`extl`·`moveb`) | ✅ 계획 12 고침(C 꼴은 진단이 정함) |
| 고리는 0 번만 돌고(NCPUS 1), 스택 기준은 `_intstacks`(0x4000318) | 기호표(이번 세션), 풀이 0x4095132–0x4095136 | ✅ |
| 디버거 기다림은 `while` 꼴, `kdb_net` +8 의 32 비트 읽기 | 풀이 0x40951c2–0x40951e0 | ✅ 계획 12 고침 |
| `_bootp` 가 COMMON 이라는 것만으로는 어느 객체가 정의했는지 모름 | — | ✅ 측정에서만 봅니다 |

### 606.2 결과(run `m4p606-p1`·`p2`, 2026-10-30)

- B1(`next_init_B1.c`, 432 행): 컴파일 실패입니다. 오류는 `master_cpu` 미선언 하나뿐입니다(`kern/cpu_number.h` 가 이 include 닫힘에 없음).
- 계획 밖 변형 B1A(관문 기준은 그대로) = B1 + `#import <kern/cpu_number.h>`(plan 400 공유 머리)입니다. run `m4p606-p2` 에서 종료 0·경고 0 입니다(기록 `m4-m68k-probe-p606-p2-20261030.json`).
- `__text` 1726 B(원본 1774), 0/1(`m4-m68k-funcbytes-p606-B1A-20261030.json`), L1 사유는 `__text: fail`·참조 차이·`__bss: unverified` 입니다.
- 명령 비교(scratchpad `rawdiff.py`: 객체 `__text` 를 로컬 objdump 로 풀어 원본과 difflib 로 맞춤, switch 표 0x4094bbe–0x4094be6 제외): 명령 424 대 423, 일치율 0.9563 입니다. 재배치 자리(0 대 주소)를 빼면 실제 차이는 셋입니다.
  1. 원본 `switch (machine_type)` 는 0–9 의 표 점프(4–9 와 9 초과가 기본 갈래)인데, B1A 는 비교 사슬입니다. 그 결과 1–3 갈래에서 원본은 `slot_id` 를 다시 읽고(`a3`), B1A 는 앞의 `a1` 을 다시 씁니다. 표 점프가 되면 함께 풀릴 것으로 봅니다.
  2. 기본 갈래 `dma_chip` 저장: 원본은 `clrl d0; moveb; movew` 이고, B1A 는 `clrb dma_chip; moveb d0,dma_chip+1` 입니다(식의 형이 다름).
  3. `mon_rev`: 원본은 `P_MON` 을 먼저 만들고 `a0@(8)` 을 읽는데, B1A 는 `0x0200e008` 를 한꺼번에 더합니다. 스테이지 `dev/m68k/monreg.h:15–46` 의 `struct monitor` 는 +8 이 `mon_km_data` 입니다.
- 크기 차이 48 B 는 python 계산으로 이 셋과 맞습니다: 표 점프 +46, `dma_chip` −4, `slot_id` 다시 읽기 +6.

## 607. M4-113 세부 계획 — `m68k_init` 의 남은 세 차이 진단 B2(07 변경 없음; 코딩 전, 2026-10-30)

방법(진단; 명세 `08_build/artifacts/m4p607/spec.json`, run `m4p607-p1`, 바탕 `m0p604-a1-stage`; scratchpad `gen_p607.py`): B1A 에서 다음을 바꿉니다.
1. `switch (machine_type)` 에 `case 4:`…`case 9:` 를 명시하고 기본 갈래와 몸통을 같이 씁니다. 이름은 진단 작성 이름 `NeXT_TURBO`(4)와 숫자를 씁니다. 1997 이름은 바이트로 정해지지 않으므로 07 전에 묻습니다.
2. `mon_rev = ((volatile struct monitor *) P_MON)->mon_km_data >> 16;` 로 씁니다.
3. 기본 갈래 `dma_chip` 은 두 꼴을 변형으로 시험합니다:
   - B2A: `((struct scr1 *) P_SCR1)->s_dma_rev`(volatile 없음)
   - B2B: `*((volatile u_char *) P_SCR1 + 1)`

측정: §606 과 같습니다(`rawdiff.py`, `__text` 크기, funcbytes, 재배치, `__data` 44 B, bss, COMMON 이름·크기, 원본에 없는 미정의).

판정(미리 정함; 07 은 바꾸지 않음): 1/1 이 되는 변형이 있으면 자료·bss·COMMON 을 보고 바이트로 가를 수 없는 꼴을 정리합니다. 아니면 남은 차이를 적고 다음 진단으로 갑니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 607.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 세 자리가 재배치 말고 모든 차이이고, 크기 차이는 +46 +6 −4 +0 = 48 B | `rawdiff.py` 출력(§606.2)과 python 계산(이번 세션: 46 − 4 + 6 = 48) | ✅ |
| GCC 2.7.2 는 같은 목적지의 이웃 case 를 묶어 셈하므로 B1A 는 셈 3 이고, 4–9 를 더하면 5 가 되어 표 점프 문턱을 넘음; 명시 label 이나 `case 4 ... 9:` 범위 꼴 둘 다 가능 — 원본 철자는 바이트로 정해지지 않음 | — | ⏭️ 컴파일로 확인(B2E 를 더함) |
| 9 초과 값은 0x4094bae–0x4094bb0 의 무부호 `bcs` 로 0x4094c26 으로 감; 표 4–9 도 같은 주소 | python 표 읽기(§606.1) | ✅ |
| `dma_chip`: B2A·B2B 에 더해 volatile 없는 바이트 읽기 `*((u_char *)P_SCR1 + 1)` 를 대조군으로 둘 것 | — | ✅ B2C 를 더함 |
| `struct monitor` +8 `mon_km_data`(부호 있는 `int`)는 `swap; extl` 과 맞음 | `monreg.h:15–46`(이번 세션) | ✅ |
| B1A 의 `dma_chip` 식을 그대로 두고 switch·monitor 만 바꾼 대조군을 둘 것(제어 흐름만으로 풀리는지) | — | ✅ B2D 를 더함 |

계획 수정: 변형은 B2A·B2B·B2C(volatile 없는 바이트)·B2D(B1A 의 `dma_chip` 식)·B2E(B2B 에서 `case 4 ... 9:` 범위 꼴) 다섯입니다. 모두 switch·monitor 바뀜을 담고, 한 run 으로 돌립니다.

### 607.2 결과(run `m4p607-p1`, 2026-10-30)

- 다섯 변형 모두 종료 0·경고 0 입니다(기록 `m4-m68k-probe-p607-20261030.json`). 모두 0–9 표 점프가 되었습니다. 명시 `case 4:`…`case 9:`(B2A–D)와 GNU 범위 `case NeXT_TURBO ... 9:`(B2E) 둘 다 표 점프를 내므로, 철자는 바이트로 가를 수 없습니다.
- `__text` 크기: B2A·B2C 1774(원본과 같음), B2B·B2D·B2E 1778 입니다. funcbytes 는 모두 0/1 입니다(`m4-m68k-funcbytes-p607-B2A…E-20261030.json`).
- `dma_chip`(기본 갈래): volatile 없는 비트 필드 `((struct scr1 *) P_SCR1)->s_dma_rev`(B2A)만 원본의 `clrl d0; moveb a0@(1,a1:l),d0; movew d0,dma_chip` 과 같습니다. 다른 꼴은 다릅니다: B2B·B2E(volatile 바이트)와 B2D(B1A 꼴)는 `clrb; moveb` 나눠 저장, B2C(volatile 없는 바이트)는 `clrw d0` 와 합친 주소입니다(`rawdiff.py`).
- 1–3 갈래의 `slot_id` 다시 읽기는 표 점프로 풀렸습니다(예측대로).
- B2A 의 남은 차이(`rawdiff.py`, 원본·객체 switch 표 둘 다 제외; 명령 424 대 424, 일치율 0.9788): 재배치 자리 말고는 `mon_rev` 주소 하나입니다. 원본은 `moveal slot_id,a0; addal #0x0200e000,a0; movel a0@(8),d0` 이고, B2A 는 `moveal slot_id,a1; moveal #0x0200e000,a0; movel a0@(8,a1:l),d0` 입니다(크기 같음).

## 608. M4-114 세부 계획 — `mon_rev` 주소 꼴 진단 B3(07 변경 없음; 코딩 전, 2026-10-30)

방법(진단; 명세 `08_build/artifacts/m4p608/spec.json`, run `m4p608-p1`, 바탕 `m0p604-a1-stage`; scratchpad `gen_p608.py`): B2A 에서 `mon_rev` 문장만 바꾼 변형 셋입니다.
- B3A: `if` 덩이 안 지역 포인터 `volatile struct monitor *mon = (struct monitor *) P_MON;` 다음 `mon_rev = mon->mon_km_data >> 16;`
- B3B: 함수 머리의 `register volatile struct monitor *mon;` 에 덩이 안에서 대입하고 같은 식
- B3C: `mon_rev = (*(volatile int *) ((int) P_MON + 8)) >> 16;`(주소를 정수로 먼저 더하는 꼴)

측정: §607 과 같습니다(`rawdiff.py` 에 객체 표 제외 `oc0-e8`). 1/1 이 되면 `__data` 44 B·bss·COMMON 이름과 크기·미정의를 봅니다.

판정(미리 정함; 07 은 바꾸지 않음):
- 1/1 이고 L1 사유가 bss(사건 쓰레기 둘)뿐이면, 바이트로 가를 수 없는 꼴과 작성 이름을 사용자에게 묻고 07 구현 계획을 씁니다.
- 아니면 남은 차이를 적습니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 608.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| B2A 의 재배치·표 말고 차이는 `mon_rev` 세 명령뿐(1774 B, 명령 424 대 424) | `rawdiff.py`(§607.2, 이번 세션) | ✅ |
| B3A·B3B(지역·`register` 포인터)는 한 번 쓰이면 같은 색인 읽기로 사라질 수 있고, B3C 는 `+8` 이 상수로 접힐 수 있음 | — | ⏭️ 컴파일로 확인 |
| `intrmask`·`scr2` 가 원본과 같은 것은 전역에 저장한 뒤 역참조하기 때문 — 한 번 쓰는 지역 포인터의 근거는 아님 | B2A 257–266 행과 원본 0x4094cda–0x4094d58(§606.1) | ✅ |
| 더할 변형: 바이트 포인터 바탕(B3D), 필드 주소 포인터(B3E), 따로 둔 부호 있는 값(B3F); `slot_id` 읽기는 `km_send` 뒤에 둘 것 | — | ✅ 변형을 더함 |
| 바꾸면 함수 다른 곳의 레지스터 배정이 바뀔 수 있으니 함수 전체를 비교할 것 | `rawdiff.py` 는 함수 전체를 비교함 | ✅ |

계획 수정: 변형은 B3A–B3F 여섯입니다.

### 608.2 결과(run `m4p608-p1`, 2026-10-30)

- 여섯 변형 모두 종료 0·경고 0 입니다(기록 `m4-m68k-probe-p608-20261030.json`).
- B3A(덩이 안 지역 포인터)와 B3B(함수 머리의 `register` 포인터)는 서로 canon 이 같습니다. `rawdiff.py` 로 재배치 말고는 원본과 다른 명령이 없습니다.
  - `__text` 1774, `full_span` 이고, L1 사유는 `__DATA,__bss: unverified` 하나입니다(정적 `event_junk_h`·`event_junk_m` 8 B).
  - 정적 표 대응 `40b2baa=_cpu_clock_table` 을 주면 1/1 입니다(`m4-m68k-funcbytes-p608-B3A-map-` · `-B3B-map-20261030.json`). 대응 없이는 0/1 입니다(기록 `-B3A…F-`).
- B3C·B3D·B3F 는 주소를 한꺼번에 더하는 꼴이 남고, B3E 는 1772 B 입니다. 넷 다 원본과 다릅니다.
- B3A 객체:
  - 섹션 `__text` 1774(재배치 150)·`__data` 44(재배치 2)·`__cstring` 94·`__bss` 8 입니다.
  - `__data` 44 B 는 앞 두 낱말(bss 를 가리키는 재배치 자리) 말고 원본 [0x40b2b9e, 0x40b2bca) 와 바이트가 같습니다. 기호 자리도 `event_high` +0·`event_middle` +4·`default_page_size` +8·`cpu_clock_table` +12 로 원본 차례와 같습니다.
  - 지역 기호는 `_event_junk_h`·`_event_junk_m`(bss)·`_cpu_clock_table`(data) 입니다.
  - COMMON 33 개는 모두 원본에 있습니다. 그 가운데 `_tthiwat`·`_tthog`·`_ttlowat` 는 원본에서 `__data` 정의입니다(머리 임시 정의, §579 와 같은 M7 의무).
  - 원본에 없는 미정의는 없습니다.
- 바이트가 정한 꼴: `dma_chip` 은 volatile 없는 비트 필드(B2A), `switch` 는 0–9 표 점프, `mon_rev` 는 포인터 변수를 거친 읽기(B3A·B3B)입니다.
- 바이트로 가를 수 없는 것(사용자에게 물음):
  - 작성 이름: `struct m68k_init_args`·`ap0`·`cpu_clock_table`·`P_SCR1_TURBO`·`P_NCC`·`NeXT_TURBO`·`kdb_net` 의 형, 1997 `struct scr1` 의 필드 이름
  - case 4–9 의 철자(명시 label / GNU 범위)
  - `mon` 포인터의 자리(B3A / B3B)

- 사용자 결정(2026-10-30, AskUserQuestion 두 번):
  - ① 작성 이름은 "진단 이름 그대로"(`struct m68k_init_args`·`ap0`·`cpu_clock_table`·`P_SCR1_TURBO`·`P_NCC`·`NeXT_TURBO`·`kdb_net` 의 형·1997 `struct scr1` 필드 이름)
  - ② case 4–9 는 "명시 label"
  - ③ `mon` 포인터는 "if 덩이 안 지역"(B3A)
  - ④ 파일 이름은 "`m68k_init.c`"(1997 함수 이름과 x86 `i386_init.c` 에 맞춤)

## 609. M4-115 D137 구현 계획 — 07 `src/machdep/m68k/m68k_init.c`(행 302, CODE+BSS_INFERRED; 코딩 전, 2026-10-30)

확인한 사실(이번 세션):
- §608.2 결과와 위 결정입니다. B3A 는 함수 1/1(정적 표 대응 `40b2baa=_cpu_clock_table`)이고, L1 사유는 bss 8 B 하나입니다.
- 정적 bss 가 있으므로 받아들임 꼴은 §570(`fd_subr`, D128)·§526(`autoconf`, D113)과 같은 CODE+BSS_INFERRED 입니다.
- 스테이지 `m0p604-a1-stage` 에 `src/machdep/m68k/m68k_init.c` 는 없습니다(2 에서 확인).

1. 07 `src/machdep/m68k/m68k_init.c`(D103)를 B3A 글(`next_init_B3A.c`)에서 scratchpad `gen_p609.py` 로 만듭니다.
   - NeXTMach 고지·HISTORY 는 그대로 둡니다(D013).
   - 그 뒤 plan 609 머리 주석 덩이를 둡니다. 내용은 1997 바뀜 목록(§606·606.1 의 1–14), 바이트가 정한 꼴(`dma_chip` 비 volatile 비트 필드, 0–9 표 점프, `mon` 지역 포인터), 사용자 결정 ①–④, 작성 이름 목록입니다.
   - 진단 표시 `plan 60x diagnostic` 은 뜻에 따라 바꿉니다. include 바뀜은 `plan 609 (D104)`(CPU 는 D110, `bmap.h` 는 D105), 그 밖은 `plan 609 (D137, D024)` 입니다.
   - 주석 뺀 토큰이 B3A 와 같아야 하고, 표시 줄에 `*/` 뒤 글이 없어야 합니다(python).
2. `stage_m68k.py`: `M4FILES[609] = list(M4FILES[604]) + ['m68k_init.c']`, `EXCEPTS[609] = dict(EXCEPTS[604])`, 머리말 plan 목록에 609 를 더합니다.
3. 회귀(§604 꼴):
   - `--plan 604` 재생성(`m0p604-r609-stage`) = 보관본이어야 합니다.
   - `m0p609-a1-stage` 와 보관 604 의 차이는 그 한 파일(968 → 969)과 키 `plan`·`m4_sources`·`files` 여야 합니다.
   - M5 205 줄(`m5-604.cmd` 가 §604 것과 `cmp` 같음; run `m3p609-b604`·`m3p609-cc1`): 객체·stderr 같음, `compare` 의 `differ_unexpected`·`lost` 빔, 요약 차이는 새 파일 하나뿐이어야 합니다.
   - x86: `m4_x86_inputs.py s6ln`·`--plan 609 x86gate` 일곱이 같아야 합니다.
4. 확인 run `m4p609-p1`: F = `@machdep/m68k/m68k_init.c`, L = B3A 글에 F 와 같은 줄 수의 맞춤 주석을 같은 자리에 넣은 꼴입니다(줄마다 주석 뺀 토큰 같음, python).
   - 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = B3A(canon), 1/1(대응 포함), L1 사유는 bss 하나(`provisional`) 이어야 합니다.
   - F·L 바이트 차이는 문자열 표·`n_strx` 에만 있어야 합니다.
5. 최종 run `m4p609-a1`(명세 `08_build/artifacts/m4p609/spec.json`: F 만, `m4_id` `m68k-302`, `refs` = p1 L, 객체 이름 `m68k_init`(진단의 `next_init` 대신 파일 이름에 맞춤), `bss_inferred` [`m68k_init`], `known_warnings` 없음; 기록 `m4-m68k-p609-final-20261030.json`): `gate.ok`, 1/1 이어야 합니다.
6. zerofill: `m5_m68k_zerofill.py objs`(§570 꼴, 기록 `m4-m68k-zerofill-p609-20261030.json`)이 `reference-inferred` 이고 후보가 [0x40b55c4, 0x40b55cc) 여야 합니다(사건 포인터가 가리키는 자리와 같음). 이전 bss 배치 기록(§464 + `"plan464_record"` 기록, 진단·대체된 것 뺌)과 겹침 0 을 python 으로 확인합니다.
7. python 확인 `m4-m68k-p609-checks-20261030.json`:
   - 섹션(`__text` 1774·`__data` 44·`__cstring` 94·`__bss` 8)
   - `__data` 44 B 가 재배치 두 낱말 말고 원본과 같고, 재배치 대상이 bss 두 자리(+0·+4)
   - 기호 자리 넷이 원본 차례와 같음
   - 문자열이 모두 원본에 있음
   - 외부 정의는 정확히 넷(`_m68k_init` 0x4094afe·`_event_high` 0x40b2b9e·`_event_middle` 0x40b2ba2·`_default_page_size` 0x40b2ba6)이고 원본 자리와 같음
   - 지역 셋(`_event_junk_h`·`_event_junk_m`·`_cpu_clock_table`)
   - COMMON 33 이름이 모두 원본에 있음(D136 기준)
   - 원본에 없는 미정의 없음
   - 컴파일 명령 = M5 줄, 의존 i386 0, 입력 사슬 전수
8. 상태표: 근거 `06_reconstruction/evidence/m68k-m68k_init.md` 를 먼저 쓰고, `ACCEPTED` 에 넷 묶음 한 줄(최종·zerofill)을 더합니다. 도구를 두 번 돌리고 §604 표와 대조합니다.
   - 기대(python): 객체 37(OBJECT_MATCH 29, CODE+BSS_INFERRED 8), 덮은 행 61/188, 덮은 바이트 59838 + 1774 = 61612, `object_bytes` 76874 + 1774 = 78648 입니다. 백분율은 도구 출력을 씁니다.
9. 기록:
   - diff(NeXTMach `next/next_init.c` 대비 `m68k-m68k_init.diff`)
   - PROVENANCE 새 행(일곱 칸, `nextmach+authored`: 고지·전역 정의·콘솔과 인자 읽기 등 NeXTMach 줄, 1997 바뀜은 원본 바이트로 작성(D024), 사용자 결정 D137)
   - MODIFICATIONS, DECISIONS D137, 계획 결과와 현재 상태, HANDOFF, 메모리
   - M7 의무: COMMON 33 개와 원본 `__data` 정의 `_tthiwat`·`_tthog`·`_ttlowat` 합침, `_bootp`·`mem_region` 등의 정의 객체, 정적 이름 `event_junk_*` 의 bss 자리

관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 609.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `bmap.h` 표시는 §600 처럼 D105 | §600 의 07 `machdep.c` 표시(이번 세션 앞서 확인) | ✅ 1 고침 |
| `refs`·`bss_inferred` 의 객체 이름은 `m68k_init` 으로 같아야 함 | `m4_m68k_probe.py:59–62` | ✅ (계획에 이미 적음) |
| 기대 수치 37·29·8·61/188·61612·78648 맞음 | python(이번 세션) | ✅ |
| zerofill 은 모든 섹션의 재배치를 봐서 `__data` 의 두 포인터로 후보 [0x40b55c4, 0x40b55cc) 를 찾음 | `zerofill_check.py:60–66`(이번 세션 읽음); 실행은 최종 run 뒤 | ⏭️ 실행으로 확인 |
| `objs` 는 §464 와 그 호출에 넘긴 객체끼리만 겹침을 봄 — 따로 이전 배치 전수 겹침 검사를 둘 것(기대 18 기록·35 배치) | `m5_m68k_zerofill.py:146–150`(이번 세션 읽음) | ✅ 6 그대로(수는 실행 뒤 python 으로 셈) |
| 7 의 외부 정의를 넷으로 못박을 것 | — | ✅ 7 고침 |
| COMMON 33·`_tthiwat`·`_tthog`·`_ttlowat` 는 §570 처럼 M7 의무로 적음 | `06_reconstruction/evidence/m68k-fd_subr.md` 의 M7 줄(§570 에서 씀) | ✅ |
| `event_junk_h/m` 은 NeXTMach 이름(작성 이름 아님) | NeXTMach `next_init.c:83`(이번 세션) | ✅ 출처 기록에 그렇게 적음 |
| PROVENANCE·D137 에 저장소·커밋·경로·`next/cpu.h`·`next/scr.h` 이름 출처·결정 ①–④·바이트가 정한 꼴·`kdb_net` 형의 불확실성을 적을 것 | — | ✅ 9 에서 적음 |

### 609.2 결과(2026-10-30)

- 1·2: 07 `src/machdep/m68k/m68k_init.c`(470 행, SHA `68d4c7e8…`)를 scratchpad `gen_p609.py` 로 B3A 에서 만들었습니다. 주석 뺀 토큰이 B3A 와 같고, 맞춤 L 과 줄마다 토큰이 같으며, 표시 줄에 `*/` 뒤 글이 없습니다(python). `stage_m68k.py` 717 → 719 행입니다.
- 3: `--plan 604` 재생성(`m0p604-r609-stage`) = 보관본입니다. `m0p609-a1-stage`(969 파일)와 보관 604 의 차이는 그 파일 하나와 키 `files`·`m4_sources`·`plan` 입니다(python assert). M5: `m5-604.cmd` 가 §604 것과 `cmp` 같고, run `m3p609-b604`·`m3p609-cc1` 종료 0, 객체·stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p609-compare-20261030.json`, `-b604-`) `differ_unexpected`·`lost` 빔, 요약 차이는 새 파일 하나뿐입니다. x86 `m4-x86-inputs-p609-20261030.json` `ok`, `--plan 609 x86gate` 일곱 같음입니다.
- 4: run `m4p609-p1`(`m4-m68k-probe-p609-p1-20261030.json`): F·L 종료 0·경고 0·i386 0·`provisional`(L1 사유 bss 하나)이고, 1/1 입니다(대응 `40b2baa=_cpu_clock_table`; `m4-m68k-funcbytes-p609-F/L-20261030.json`). F = L(canon·`obj_sig` 모든 칸, STABS 810), L = B3A 이고, F·L 바이트는 문자열 표·`n_strx` 에서만 다릅니다(python).
- 5·6: run `m4p609-a1`(`m4-m68k-p609-final-20261030.json`, SHA `fac41bbe…`; REF = p1 L, `bss_inferred` [`m68k_init`]): `gate.ok`, 1/1(`m4-m68k-funcbytes-p609-a1-20261030.json`)입니다. zerofill `m4-m68k-zerofill-p609-20261030.json`(SHA `031c62e2…`)은 `reference-inferred`, 후보 [0x40b55c4, 0x40b55cc) 입니다.
- 7: 확인 `m4-m68k-p609-checks-20261030.json`(`ok` 참):
  - 섹션 1774·44·94·8
  - 자료가 재배치 두 낱말 말고 원본과 같고, 기호 넷이 원본 차례
  - 이전 bss 배치 18 기록·35 배치와 겹침 0, 그들끼리도 겹침 0
  - 문자열 5 개가 원본에 있음
  - 외부 정의 넷이 원본 자리, 지역 셋
  - COMMON 33 모두 원본에 있음, 원본에 없는 미정의 없음
  - 컴파일 명령 = M5 줄, 의존 109 파일 사슬 문제 0·i386 0
  - 객체 SHA `8a74ea14…`
- 8: 근거 `06_reconstruction/evidence/m68k-m68k_init.md`(상태 도구 전). `ACCEPTED` 에 넷 묶음 한 줄을 더했습니다. 상태표 38 → 39 행·`m4-m68k-status-p609-20261030.json`: 37 객체(OBJECT_MATCH 29, CODE+BSS_INFERRED 8), 덮은 행 61/188, 61612/215874 B(28.54%), `object_bytes` 78648 — 미리 계산한 값과 같고, 두 번 실행이 같으며, 더한 것은 `m68k_init` 뿐·바뀐 것은 없습니다.
- 9: diff `m68k-m68k_init.diff`(481 행), PROVENANCE 1183 → 1184 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 720 → 721 행, DECISIONS D137(140 → 141 행), "현재 상태와 다음 일" 을 고쳤습니다.

## 610. M4-116 세부 계획 — m68k `swapgeneric`(행 314, NeXTMach `next/swapgeneric.c`) 첫 진단 A1(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: 행 264·291(64 비트 보조 함수)은 참고 글이 없습니다. `pcb.c` 는 공유 07 `thread.h` 를 고쳐야 합니다. 반면 행 314 는 NeXTMach `next/swapgeneric.c` 의 네 함수와 이름·문자열이 맞습니다.

확인한 사실(이번 세션; scratchpad `odis.py`·python):
- 행 314 [0x4099184, 0x40996b8) 는 1332 B 이고, 정확 행·종류 `x86` 입니다(x86 원천 07 `machdep/i386/swapgeneric.m`, Darwin 바탕).
- 함수 넷의 차례와 크기: `setconf` 754, `gets` 166, `getfsname` 58, `initrootnet` 354 B.
- 원본이 참조하는 문자열은 NeXTMach 글의 것과 같습니다("root device? "·"root on %s\n"·"bad partition number\n"·"%s%s%%d"·"no suitable root\n"·"%s key [%s]: "·"initrootnet: …" 넷·"primary network interface: %s [%s]\n"·"nfs"·"4.3"·"-h").
- `__data` [0x40b2bde, 0x40b2c10) 50 B 는 10 B 항목 다섯입니다: `scdriver`·"sd"·0x0600, `ocdriver`·"od"·0x0200, `fcdriver`·"fd"·0x0100, `endriver`·"en"·0xffff, 끝 0. NeXTMach `genericconf[]` 에서 `rd` 만 없는 꼴입니다. 원본에 `_genericconf` 기호가 없어 1997 판은 static 으로 봅니다(가설). 다음 기호 `_trap_type`(0x40b2c10)은 다음 객체입니다.
- `__bss` 의 마지막 낱말 0x40b5644 에 함수들이 14 번 접근합니다(읽기 8·쓰기 6). NeXTMach `static struct genericconf *gc;` 로 봅니다.
- NeXTMach 전역 `rootdevice`·`dumplo` 는 원본 `__common` 에 있습니다. `dmmin`·`dmmax`·`dmtext` 는 원본에 없습니다(grep 0).
- 구성 머리: `en.h`(NEN 1)는 스테이지에 있습니다(07 `generated/en.h`). `sd.h`·`rd.h` 는 m68k 에 없습니다. NeXTMach `conf/MASTER.next:88` RELEASE 에는 `sd`·`en` 이 있고 `rd` 는 없으며, `:136–142` 는 `sd0`–`sd6` 입니다.
- `nextdev/busvar.h` 는 스테이지에서 `dev/busvar.h` 입니다(D104; `fd_subr` 와 같음).

방법(진단; 명세 `08_build/artifacts/m4p610/spec.json`, run `m4p610-p1`, 바탕 `m0p609-a1-stage`, `m4_id` `m68k-314`; scratchpad `gen_p610.py`):
- A1 = NeXTMach `next/swapgeneric.c` 에 `<nextdev/busvar.h>` → `<dev/busvar.h>` 하나만 바꾼 글(진단 표시)입니다.
- 진단 머리(명세 `inc`): `sd.h` 는 `#define NSD 7`(MASTER 의 `sd0`–`sd6`), `rd.h` 는 `#define NRD 0` 입니다. 값은 07 구성 행 전에 사용자에게 묻습니다.

측정:
- 종료·경고·i386 0, 컴파일 명령 = M5 줄(`-c`·`-o` 뺌)
- `__text` 크기(1332 기대), funcbytes 4 함수(필요하면 정적 대응), `rawdiff.py`
- `__data` 50 B 와 기호(`genericconf` 의 정적/외부), `__bss`
- 문자열이 모두 원본에 있는지
- COMMON 이름(`dmmin` 등이 나오는지)·원본에 없는 미정의

판정(미리 정함; 07 은 바꾸지 않음): 차이를 적고 다음 진단에서 바이트로 고칩니다. 맞으면 바이트로 가를 수 없는 꼴과 구성 값을 사용자에게 묻습니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 610.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다: `initrootnet:` 문자열은 다섯이 아니라 넷이고, `gc` 접근 14 번은 모두 읽기가 아니라 읽기 8·쓰기 6 입니다. 위 사실 줄을 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기(1332 = 754+166+58+354)와 표 50 B(10 B 항목 다섯, +0 드라이버·+4 이름·+8 2 B 장치) | python(이번 세션) | ✅ |
| `_genericconf`·`_gc`·`_dmmin`·`_dmmax`·`_dmtext` 는 원본 기호표에 없음; static 은 추정 | `symbols.tsv` grep(이번 세션) | ✅ 가설로 둡니다 |
| `gc` 접근은 읽기 8·쓰기 6 | `swapg.ann` 에서 셈(이번 세션: 쓰기 6, 읽기 8) | ✅ 고침 |
| `setconf` 는 NeXTMach 의 마지막 "단위 0 찾기" 고리(189–200 행)가 없음 — "root on %s0\n" 참조 없음 | python: 원본 커널 전체에 그 문자열 0 회 | ✅ |
| `initrootnet` 의 거르기가 반대: `gc_root != NODEV` 이면 건넘(0x409959a `cmpiw #-1,a1@(8); bnes`), 안쪽 비교는 여전히 `gc->gc_driver` | `swapg.ann` 0x4099594–0x40995cc(이번 세션) | ✅ |
| `gets`·`getfsname` 은 바뀜 없어 보임; `"nfs"`·`"4.3"` 은 `strcpy` 를 펼친 꼴 | — | ⏭️ 진단으로 |
| x86 판의 바뀜(버스 찾기·`*` 처리·망 고리 없음)은 m68k 에 옮기지 말 것 — m68k 는 `*` 고쳐 쓰기(0x409922c)와 망 고리를 가짐 | — | ✅ 옮기지 않습니다 |
| NSD 7·NRD 0 은 진단 값으로 합당; 이 객체에서 NSD 의 양수 값은 바이트에 드러나지 않음 | NeXTMach 74·93 행(`#if NSD > 0` 뿐) | ✅ 07 구성 값은 사용자에게 묻습니다 |
| 측정에 더할 것: 정적 대응 `40b2bde=genericconf`·`40b5644=gc`, 버스 걸음 42·`bd_unit`/이름/`bd_alive` 자리 4/22/26, ioctl 0xc0206921, 문자열 참조 단위 비교, 진단 include 경로 예외 기록 | — | ✅ 측정에 더합니다 |

계획 수정: 같은 run 에 B1 을 더합니다. B1 은 A1 + 위에서 확인한 두 바뀜(마지막 찾기 고리 지움, `initrootnet` 거르기 조건 반대)과 `static struct genericconf genericconf[]` 입니다(진단 표시). A1 은 출발점 기록용입니다.

### 610.2 결과(run `m4p610-p1`, 2026-10-30)

- A1·B1 모두 종료 0·경고 0·i386 0 입니다(기록 `m4-m68k-probe-p610-20261030.json`).
- A1: `__text` 1456 B, L1 사유 `__text`·`__data`·`__bss` unverified 입니다. funcbytes 2/4(`m4-m68k-funcbytes-p610-A1-20261030.json`)입니다.
- B1(A1 + 마지막 찾기 고리 지움 + `initrootnet` 거르기 반대 + `static` `genericconf`):
  - `__text` 1332 B(원본과 같음), `__data` 50·`__cstring` 367·`__bss` 4 입니다.
  - L1 사유는 `__DATA,__bss: unverified` 하나입니다. `__text` 와 `__data` 는 바이트·참조가 검증되었습니다.
  - `rawdiff.py` 로 보면 명령 368 대 368, 차이는 재배치 값뿐입니다.
- funcbytes 는 B1 에서 멈췄습니다: "scattered relocation at 0x28a: no symbol at r_value 0x616". 0x616 은 객체 `__cstring`(0x566–0x6d5) 안이고, 원본도 0x40a66b2+k("nfs"·"4.3" 의 바이트 하나하나)를 가리킵니다. `strcpy` 를 펼친 바이트 복사의 scattered 재배치이고, 도구는 기호가 있는 앵커만 받습니다.
- 기호: COMMON 20 개 가운데 `_dmmin`·`_dmmax`·`_dmtext` 셋은 원본에 없습니다(NeXTMach `int dmmin, dmmax, dmtext;`). 나머지 17 개는 원본에 있습니다. 원본에 없는 미정의는 없습니다.

## 611. M4-117 세부 계획 — `swapgeneric` B2 와 funcbytes 의 `__cstring` scattered 재배치(07 변경 없음; 코딩 전, 2026-10-30)

1. 진단 B2(명세 `08_build/artifacts/m4p611/spec.json`, run `m4p611-p1`): B1 에서 `int dmmin, dmmax, dmtext;` 정의를 지우고 표시 주석만 둡니다(원본 기호표에 세 이름 없음). `long dumplo;` 는 그대로 둡니다(원본 `__common`).
2. 도구 `10_tools/reconstruction/m68k_funcbytes.py`: scattered 재배치의 `r_value` 가 객체 `__cstring` 안이고 그 자리에 기호가 없으면, 그 재배치를 내용으로 비교합니다.
   - 객체 쪽은 `('cstring', r_value 의 NUL 끝 문자열, 유효 대상 − r_value)` 입니다.
   - 원본 쪽은 원본 대상 `iva` 에서 같은 덧수를 뺀 자리의 문자열과 덧수입니다.
   - 둘이 같으면 같음으로 봅니다. 그 밖의 경우(앵커 없음 + `__cstring` 아님)는 지금처럼 멈춥니다.
   - 도구 머리말에 plan 611 줄을 더합니다.
   - 회귀: 이미 받아들인 최종 객체의 funcbytes(`p579-a1`·`p585-a1`·`p600-a1`·`p602-mm-a1`·`p602-ne-a1`·`p604-a1`·`p609-a1`)를 새 도구로 다시 돌립니다. 각 `functions`·`same`·`total` 이 보관 기록과 같아야 합니다(python; 도구 SHA 만 다름).
3. 측정(B2): §610 과 같습니다. 더해서 새 funcbytes(대응 `40b2bde=_genericconf 40b5644=_gc`)로 4/4 인지, COMMON 이 모두 원본에 있는지 봅니다.

판정(미리 정함; 07 은 바꾸지 않음): B2 가 4/4 이고 L1 사유가 bss 하나이며 COMMON·미정의가 원본에 있으면, 구성 값(NSD·NRD 의 07 구성 행)과 바이트로 가를 수 없는 꼴을 사용자에게 묻고 07 구현 계획을 씁니다.

관문: 컴파일 명령 = M5 줄, i386 0, 도구 회귀 같음입니다.

### 611.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| B1 의 scattered 재배치는 여섯이고, 앵커는 0x616("nfs")·0x61a("4.3"), 덧수 +1..+3, 원본 대상 0x40a66b3..0x40a66b9 | `macho_obj` 로 B1 `__text` 재배치 목록(이번 세션: 0x28a·0x294·0x29e→0x616, 0x2b4·0x2be·0x2c8→0x61a) | ✅ |
| 새 규칙은 경계가 있어야 안전함: 두 앵커 모두 `__cstring` 안, NUL 로 끝나는 문자열, 0 ≤ 덧수 ≤ 문자열 길이(NUL 포함); 꼬리 공유(`"nfs"`+1 과 `"fs"`+0)는 다르게 봄; 음수·NUL 넘는 덧수는 거부 | — | ✅ 2 를 이렇게 고칩니다 |
| 받아들인 37 객체 가운데 scattered 재배치가 있는 것은 `machargs`(2)·`machine_clock`(10)·`snd_reply`(71)·`snd_device`(2)·`snd_dspqueue`(15)·`fd_io`(2)·`clock`(1) 이고, 모든 앵커가 이름이 있으며 `__cstring` 밖 — 회귀는 이들 모두를 포함할 것 | python 으로 37 객체를 셈(이번 세션: 같은 일곱과 수) | ✅ 회귀를 37 객체 전부로 넓힙니다 |
| `dmmin`·`dmmax`·`dmtext` 만 원본에 없는 COMMON; 지우면 섹션 내용은 같고 기호 표·재배치 기호 번호는 바뀔 수 있음 | §610.2 의 python 결과 | ✅ 3 에 B1→B2 섹션 바이트 같음과 재배치 의미 비교를 더합니다 |

계획 수정:
- 2 의 규칙을 위 경계로 고칩니다. 규칙 함수에 대한 python 단위 시험(경계 안 접미, 꼬리 공유, NUL 자리 덧수, 음수, NUL 넘음)을 scratchpad 에서 돌리고, 결과를 기록 `m4-m68k-funcbytes-tool-p611-20261030.json` 에 둡니다.
- 회귀: 고치기 전 도구 사본(scratchpad `m68k_funcbytes_old.py`)과 새 도구를 받아들인 37 최종 객체에 같은 인자로 돌립니다. 인자는 구간 = 상태표 `start`·`end`, 대응 = 그 객체 SHA 의 기존 funcbytes 기록 대응(없으면 없음)입니다. `functions`·`same`·`total`·`object_only`·종료 상태가 모두 같아야 합니다(python). 결과는 같은 기록에 둡니다.
- B2 기록 이름은 `m4-m68k-probe-p611-20261030.json`·`m4-m68k-funcbytes-p611-B2-20261030.json` 입니다.

### 611.2 결과(2026-10-30)

- 도구: `m68k_funcbytes.py` 232 → 260 행. `cstr_at`·`cstr_ref_same` 두 도움 함수를 더했고, scattered 갈래는 앵커 기호가 없고 `r_value` 가 객체 `__cstring` 안일 때만 경계 규칙으로 비교합니다. 머리말에 plan 611 줄을 더했습니다.
- 단위 시험 9 건이 모두 맞습니다: 문자열 읽기 셋, 같음 둘, 꼬리 공유 다름, 음수, NUL 넘음, 원본 없음.
- 회귀: 고치기 전 사본과 새 도구를 받아들인 37 최종 객체에 같은 인자로 돌렸습니다. `functions`·`same`·`total`·`object_only`·종료 상태가 모두 같습니다. scattered 재배치가 있는 일곱 객체도 같습니다(기록 `09_validation/reconstruction/m4-m68k-funcbytes-tool-p611-20261030.json`).
  - 첫 회귀 시도는 옛 사본이 scratchpad 에서 `macho_obj` 를 들이지 못해 모두 종료 1 이었습니다. 비교로 쓰지 않고, `PYTHONPATH=10_tools/reconstruction` 으로 다시 돌린 것을 기록했습니다.
- B2(B1 − `int dmmin, dmmax, dmtext;`, run `m4p611-p1`, 기록 `m4-m68k-probe-p611-20261030.json`): 종료 0·경고 0·i386 0 입니다.
  - `__text` 1332, L1 사유 `__DATA,__bss: unverified` 하나, `full_span`, `provisional` 입니다.
  - 새 funcbytes(대응 `40b2bde=_genericconf 40b5644=_gc`)로 4/4 입니다(`m4-m68k-funcbytes-p611-B2-20261030.json`).
  - B1 과 섹션 넷의 내용이 같고(python), COMMON 은 셋이 빠졌을 뿐 더해진 것이 없으며 모두 원본에 있습니다.
- 바이트·기호가 정한 꼴: 마지막 찾기 고리 없음, `initrootnet` 거르기 반대, `genericconf` static(원본에 기호 없음), `dmmin`·`dmmax`·`dmtext` 없음, `rd` 항목 없음(NRD 0).
- 바이트로 가를 수 없는 것: `NSD` 의 양수 값(이 객체는 `#if NSD > 0` 만 씀). 사용자에게 묻습니다.

- 사용자 결정(2026-10-30, AskUserQuestion): ① `NSD` 는 "7"(NeXTMach `conf/MASTER.next:88` RELEASE 의 `sd`, `:136–142` `sd0`–`sd6`; hypothesis) ② 07 꼴은 NeXTMach `next/swapgeneric.c` 에 바이트가 정한 바뀜을 표시해 넣은 `src/machdep/m68k/swapgeneric.c`(지운 줄은 그 자리에 표시 주석, D128 꼴).

## 612. M4-118 D138 구현 계획 — 07 `src/machdep/m68k/swapgeneric.c`, 구성 `sd.h`·`rd.h`(행 314, CODE+BSS_INFERRED; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §611.2 결과와 위 결정입니다. B2 는 4/4 이고 L1 사유는 bss(정적 `gc` 4 B) 하나입니다. 절차는 §570(생성 구성 머리 `fd.h`)·§573(`sc.h`)·§609(CODE+BSS_INFERRED)와 같습니다.
1. 구성: `06_reconstruction/config_options-m68k.tsv` 에 두 행(여섯 칸)을 더합니다.
   - `sd NSD sd.h 7 hypothesis`: 근거는 MASTER RELEASE 와 `sd0`–`sd6`, 원본 `genericconf` 의 `sd` 항목이고, `swapgeneric` 은 `NSD > 0` 만 씁니다.
   - `rd NRD rd.h 0 confirmed`: 근거는 원본 `genericconf` 50 B 에 `rd` 항목이 없음(0x40b2bde–0x40b2c10)과 RELEASE 에 `rd` 없음입니다.
   - `gen_config_headers.py --arch m68k` 로 `07_kernel/v183.34/m68k/generated/sd.h`·`rd.h` 를 만들고, `--check` 둘(x86·m68k)이 종료 0 이어야 합니다.
2. 07 `src/machdep/m68k/swapgeneric.c`(D103)를 B2 글에서 scratchpad `gen_p612.py` 로 만듭니다.
   - NeXTMach 고지·HISTORY 는 그대로 둡니다(D013).
   - plan 612 머리 주석 덩이에 바뀜 다섯(include 한 줄 D104, `genericconf` static, `dmmin`·`dmmax`·`dmtext` 지움, 마지막 찾기 고리 지움, `initrootnet` 거르기 반대)을 적습니다.
   - 진단 표시는 `plan 612 (D138, D024)`·`plan 612 (D104)` 로 바꿉니다.
   - 주석 뺀 토큰이 B2 와 같아야 하고, 표시 줄에 `*/` 뒤 글이 없어야 합니다(python).
3. `stage_m68k.py`: `M4FILES[612] = list(M4FILES[609]) + ['swapgeneric.c']`, `EXCEPTS[612] = dict(EXCEPTS[609])`, 머리말 plan 목록에 612 를 더합니다.
4. 회귀(§573 꼴):
   - 생성 머리 둘은 모든 m68k 스테이지에 들어갑니다. 그래서 `--plan 609` 재생성(`m0p609-r612-stage`)은 보관본과 `generated/sd.h`·`generated/rd.h` 둘만 달라야 합니다(키 `added`·`files`).
   - `m0p612-a1-stage` 와 보관 609 의 차이는 그 둘과 `src/machdep/m68k/swapgeneric.c`, 키 `plan`·`m4_sources`·`added`·`files` 여야 합니다(python assert).
   - M5 205 줄(`m5-609.cmd` 가 §609 것과 `cmp` 같음; run `m3p612-b609`·`m3p612-cc1`): 객체·stderr 205 같음, `compare` 의 `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로뿐이어야 합니다.
   - x86: `m4_x86_inputs.py s6ln`·`--plan 612 x86gate` 일곱이 같아야 합니다.
5. 확인 run `m4p612-p1`: F = `@machdep/m68k/swapgeneric.c`, L = B2 글에 F 와 같은 자리에 맞춤 주석 줄을 넣은 꼴입니다(줄마다 주석 뺀 토큰 같음, python). 진단 `inc` 는 없습니다(생성 머리를 씀).
   - 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig`), L = B2(canon), 4/4(대응 `40b2bde=_genericconf 40b5644=_gc`), `provisional`(사유 bss 하나)이어야 합니다.
   - F·L 바이트 차이는 문자열 표·`n_strx` 에만 있어야 합니다.
6. 최종 run `m4p612-a1`(명세 `08_build/artifacts/m4p612/spec.json`: 객체 `swapgeneric`, `m4_id` `m68k-314`, `refs` = p1 L, `bss_inferred` [`swapgeneric`]): `gate.ok`, 4/4 이어야 합니다.
   - zerofill `objs`(`m4-m68k-zerofill-p612-20261030.json`)이 `reference-inferred` 이고 후보가 [0x40b5644, 0x40b5648) 이어야 합니다.
   - 이전 bss 배치(§464 + `"plan464_record"` 기록, 진단·대체된 것 뺌, §609 포함 — 기대 19 기록·36 배치)와 겹침 0 을 python 으로 확인합니다.
7. python 확인 `m4-m68k-p612-checks-20261030.json`:
   - 섹션(`__text` 1332·`__data` 50·`__cstring` 367·`__bss` 4)
   - L1 은 `__data` 바이트·참조를 검증했고, 사유는 bss 하나
   - 외부 정의는 정확히 넷(`_setconf` 0x4099184·`_gets` 0x4099476·`_getfsname` 0x409951c·`_initrootnet` 0x4099556), 지역은 `_genericconf`·`_gc`
   - COMMON 17 모두 원본에 있음(D136 기준), 문자열 참조가 원본과 같음(funcbytes), 원본에 없는 미정의 없음
   - 컴파일 명령 = M5 줄, 의존 i386 0, 입력 사슬 전수(생성 `sd.h`·`rd.h` 포함)
8. 상태표: 근거 `06_reconstruction/evidence/m68k-swapgeneric.md` 를 먼저 쓰고 `ACCEPTED` 에 넷 묶음 한 줄을 더합니다. 도구를 두 번 돌립니다.
   - 기대(python): 객체 38(OBJECT_MATCH 29, CODE+BSS_INFERRED 9), 덮은 행 62/188, 덮은 바이트 61612 + 1332 = 62944, `object_bytes` 78648 + 1332 = 79980 입니다. 백분율은 도구 출력을 씁니다.
9. 기록:
   - diff(NeXTMach 대비 `m68k-swapgeneric.diff`)
   - PROVENANCE 새 행 셋: `swapgeneric.c` `nextmach`, 생성 `sd.h`·`rd.h` `generated`
   - MODIFICATIONS, DECISIONS D138, 계획 결과와 현재 상태, HANDOFF, 메모리
   - 도구 바뀜(§611)도 MODIFICATIONS 가 아니라 계획·근거에 적습니다(도구는 07 이 아님).
   - M7 의무: 정적 `gc` 의 bss 자리, COMMON 17 의 정의 객체

관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 612.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 확인 L 은 줄 수만이 아니라 줄마다 주석 뺀 토큰이 같아야 하고, `obj_sig` 모든 칸(STABS 수 포함) | §609 1 의 조건 | ✅ 5 고침 |
| 구성 행은 탭 여섯 칸; `NSD 7 hypothesis`·`NRD 0 confirmed` 적절; 근거에 원본 바이트·B2 기록과 MASTER·D138 을 적을 것; 생성기는 두 상태를 받음 | `gen_config_headers.py:30–34`(이번 세션: `undetermined` 만 건넘) | ✅ |
| 스테이지·07 어디에도 `sd.h`·`rd.h` include 나 `NSD`·`NRD` 사용이 없음 | grep(이번 세션: 0 건) | ✅ |
| 609 재생성은 생성 머리 둘과 키 `added`·`files` 만 다름; 612 는 더해 `plan`·`m4_sources`·`swapgeneric.c`(소스는 `added` 에 들지 않음), `m4_headers` 그대로 | §573 의 같은 꼴 결과 | ✅ (실행에서 assert) |
| 섹션 1332/50/367/4, COMMON 17 모두 원본에, bss 참조 14 가 [0x40b5644, 0x40b5648), 이전 배치 19 기록·36 배치 겹침 0, 상태 수치 38/29/9/62/62944/79980 | §611.2 python 결과와 python 계산 | ✅ |
| §609 표와 이름 대조로 더한 것이 `swapgeneric` 하나인지 볼 것 | — | ✅ 8 에 더함 |
| x86 기본 `--check` 는 x86 표만 읽음; x86 07 에 `sd.h`·`rd.h` 없음 | `gen_config_headers.py:26–27·54–58`, `ls 07_kernel/generated`(이번 세션) | ✅ |
| 기록: 생성 머리 PROVENANCE 는 1164 행 꼴, `swapgeneric.c` 는 저장소·커밋·경로·함수별 바뀜, D138 은 사용자 선택과 바이트 사실을 나눔, §611 도구 바뀜은 기록·도구 SHA 와 함께 계획·근거에 | PROVENANCE 1164 행(§573 에서 읽음) | ✅ 9 에서 지킴 |

### 612.2 결과(2026-10-30)

- 1: `config_options-m68k.tsv` 17 → 19 행(여섯 칸), 생성 `sd.h`(`#define NSD 7`, SHA `50e922ef…`)·`rd.h`(`#define NRD 0`, SHA `58827bc3…`), `--check` 둘 종료 0, 다른 생성 파일은 바뀌지 않았습니다.
- 2·3: 07 `src/machdep/m68k/swapgeneric.c`(356 행, SHA `ea6e49fd…`)를 scratchpad `gen_p612.py` 로 B2 에서 만들었습니다. 주석 뺀 토큰이 B2 와 같고, L 과 줄마다 같습니다. 처음 생성본의 진단 말("static in B1 (below)")을 표시 말로 고쳤습니다. `stage_m68k.py` 719 → 721 행입니다.
- 4: `--plan 609` 재생성(`m0p609-r612-stage`)은 보관본과 `generated/sd.h`·`rd.h` 둘(키 `added`·`files`)만 다릅니다. `m0p612-a1-stage`(972 파일)는 그 둘과 `swapgeneric.c`(키 `added`·`files`·`m4_sources`·`plan`)가 다릅니다(python assert). M5: `m5-609.cmd` 가 §609 것과 `cmp` 같고, run `m3p612-b609`·`m3p612-cc1` 종료 0, 객체·stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p612-compare-20261030.json`, `-b609-`) `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로 셋뿐입니다. x86 `m4-x86-inputs-p612-20261030.json` `ok`, `--plan 612 x86gate` 일곱 같음입니다.
- 5: run `m4p612-p1`: F·L 종료 0·경고 0·`provisional`(bss 하나), 4/4(`m4-m68k-funcbytes-p612-F/L-20261030.json`), F = L(canon·`obj_sig` 모든 칸, STABS 544), L = B2 이고, 바이트 차이는 문자열 표·`n_strx` 뿐입니다.
- 6: run `m4p612-a1`(`m4-m68k-p612-final-20261030.json`, SHA `18d00a7a…`): `gate.ok`, 4/4 입니다. zerofill `m4-m68k-zerofill-p612-20261030.json`(SHA `7ee8f907…`) `reference-inferred`, [0x40b5644, 0x40b5648) 입니다.
- 7: 확인 `m4-m68k-p612-checks-20261030.json`(`ok` 참):
  - 섹션 1332·50·367·4
  - 이전 bss 19 기록·36 배치와 겹침 0
  - 외부 정의 넷이 원본 자리, 지역 `_genericconf`·`_gc`
  - COMMON 17 모두 원본에, 원본에 없는 미정의 없음
  - 컴파일 명령 = M5 줄, 의존 72 파일(생성 `sd.h`·`rd.h` 는 07 출처) 사슬 문제 0·i386 0
  - 객체 SHA `3ef9996b…`
- 8: 근거 `06_reconstruction/evidence/m68k-swapgeneric.md`(상태 도구 전). `ACCEPTED` 에 넷 묶음 한 줄을 더했습니다. 상태표 39 → 40 행·`m4-m68k-status-p612-20261030.json`: 38 객체(OBJECT_MATCH 29, CODE+BSS_INFERRED 9), 덮은 행 62/188, 62944/215874 B(29.16%), `object_bytes` 79980 — 미리 계산한 값과 같고, 두 번 실행이 같으며, §609 표 대비 더한 것은 `swapgeneric` 뿐입니다.
- 9: diff `m68k-swapgeneric.diff`(88 행), PROVENANCE 1184 → 1187 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 721 → 722 행, DECISIONS D138(141 → 142 행), "현재 상태와 다음 일" 을 고쳤습니다.

## 613. M4-119 세부 계획 — m68k `md_*` 끄기 고리 셋(행 313) 진단 A1(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: 행 313 [0x40990ba, 0x4099184) 은 202 B 의 정확 행(종류 `unassigned`)입니다. 함수 셋 `md_prepare_for_shutdown` 16·`md_shutdown_devices` 50·`md_do_shutdown` 136 B 이고, 원본 풀이(scratchpad `odis.py`)로 보면 NeXTMach `next/machdep.c` 의 `boot()` 뒷부분(1272–1328 행)을 나눈 꼴입니다. 그 `boot()` 는 §598 에서 원본 `machdep` 객체에 없어 뺐습니다. 07 m68k `kern_shutdown.c`(plan 229·453)가 이 셋을 부릅니다.

확인한 사실(이번 세션, 원본 풀이와 python):
- `md_prepare_for_shutdown`: `adb_watchdog(0)` 하나입니다(NeXTMach 에 없음).
- `md_shutdown_devices`: `machine_type` 이 0 또는 2 이면 `od_update()`, 그리고 `(howto & 0x80000) && kernel_task` 이면 `od_eject()` 입니다. NeXTMach(1278–1280 행)도 꺼내기에 `RB_EJECT && kernel_task` 조건을 두므로, 1997 에 더해진 것은 기계 형 조건뿐입니다.
- `md_do_shutdown`:
  - `howto & 0x10000` 이면 `rtc_power_down()`, 그다음 `splhigh` 꼴 인라인(`movew sr; movew #0x2700,sr`)입니다.
  - `howto & 8` 이면 `printf("halting...\n\n")`(NeXTMach 는 `\n` 하나)·`mon_call("-h")` 입니다.
  - 아니면 `printf("rebooting Mach...\n\n")` 후, `howto & 0x100000` 이면 `mon_call(command)`, 아니면 `mon_boot(howto & 2 ? "-s" : 0)` 입니다.
  - 마지막에 `splx` 꼴 인라인입니다. `RB_PANIC` 의 빈 덩이는 코드를 내지 않습니다.
- 비트 값은 스테이지 SDK `bsd/m68k/reboot.h:19·22·23`(`RB_POWERDOWN`·`RB_EJECT`·`RB_COMMAND`)과 `sys/reboot.h`(`RB_SINGLE` 2·`RB_HALT` 8)의 것과 같습니다(python 으로 비트 위치 환산).
- 참고 글: NeXTMach `next/machdep.c:1272–1328`(`boot` 의 `od_update`·`od_eject`·`rtc_power_down`·`splhigh`·`mon_call`·`mon_boot`). x86 07 `machdep/i386/machdep.c:233–281` 과 Darwin ppc `machdep.c:100` 의 `md_*` 는 몸통이 달라 시그니처(`paniced, howto, command`)만 같습니다.

방법(진단; 명세 `08_build/artifacts/m4p613/spec.json`, run `m4p613-p1`, 바탕 `m0p612-a1-stage`, 진단 객체 이름 `md_shutdown`, `m4_id` `m68k-313`; scratchpad `gen_p613.py`):
- A1 은 작성 글입니다(NeXTMach `boot()` 줄을 바이트 차례로 나눔): NeXTMach 고지 머리, `#import <sys/param.h>`·`<sys/reboot.h>`·`<kern/task.h>`·`<m68k/cpu.h>`·`<machine/spl.h>`, `extern` 선언들, 그리고 위 몸통의 K&R 함수 셋입니다.
- `machine_type` 의 0·2 는 진단 이름 `NeXT_CUBE`·`NeXT_X15`(NeXTMach `next/scr.h:34·36`)로 씁니다.

측정:
- 종료·경고·i386 0, 컴파일 명령 = M5 줄
- `__text` 202·함수 크기, funcbytes 3/3, `rawdiff.py`
- 섹션 목록(`__data`·`__bss` 없음 기대), 문자열이 원본과 같은지
- 외부 정의 셋, 원본에 없는 미정의·COMMON

판정(미리 정함; 07 은 바꾸지 않음): 맞으면 바이트로 가를 수 없는 꼴(파일 이름·머리·이름)을 사용자에게 묻고 07 구현 계획을 씁니다. 아니면 차이를 적고 다음 진단으로 갑니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 613.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

먼저 제 잘못입니다: `md_shutdown_devices` 를 "NeXTMach 는 조건 없이 부름" 이라 적었으나, NeXTMach 1278–1280 행도 `od_eject` 를 `(howto & RB_EJECT) && kernel_task` 로 감쌉니다. 1997 에 더해진 것은 `machine_type` 0·2 조건뿐입니다. 위 사실 줄을 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기 202 = 16+50+136, 몸통·호출 대상·문자열(`"halting...\n\n"` 0x40ac996, `"rebooting Mach...\n\n"` 0x40ac9a3, `"-h"` 0x40ac6e6, `"-s"` 0x40ac9b7)이 계획과 같음 | python 과 기호 붙인 풀이(이번 세션) | ✅ |
| NeXTMach 1278–1280 행도 꺼내기 조건을 둠 | NeXTMach 1276–1281 행(이번 세션) | ✅ 고침 |
| 목록의 머리에는 `NeXT_CUBE`·`NeXT_X15` 가 없으니 진단 정의 0·2 를 둘 것(`next/scr.h:34·36`) | §605 진단에서 같은 이름을 파일 안에 둔 꼴 | ✅ A1 에 더함 |
| `splhigh`·`splx` 는 `bsd/machine/spl.h` → `bsd/m68k/spl.h` → `kernserv/m68k/spl.h:45–57·98` 의 매크로 | `kernserv/m68k/spl.h` 45–58·96–99 행(이번 세션) | ✅ |
| `s` 는 `int`(0x409911a–1c `movew d0,d3; extl d3`) | 원본 풀이 | ✅ |
| 반환형(`void`/암묵 `int`)은 바이트로 가를 수 없음 — 부르는 쪽도 결과를 쓰지 않음 | — | ✅ A1 은 x86 07·Darwin 처럼 `void` 로 두고, 07 전에 사용자에게 묻습니다 |
| 객체 경계(따로 객체)는 합당한 가설이나 증명은 아님: 자료·bss 를 내지 않으므로 그 차례로는 `pmap` 꼬리나 `swapgeneric` 머리를 배제하지 못함; `__cstring` 차례(pmap → 끄기 → swapgeneric)는 지지함 | — | ✅ 근거 문서에 가설로 적습니다 |
| 측정에 더할 것: L1 `OBJECT_MATCH`·`full_span`, 호출·전역·문자열 피연산자 전수(funcbytes), 의존 경로·해시, COMMON 이름·크기, 지역 정의 | — | ✅ 측정에 더합니다 |

### 613.2 결과(run `m4p613-p1`, 2026-10-30)

- A1(작성 글, NeXTMach `boot()` 1272–1328 행을 바이트 차례로 나눔): 종료 0·경고 0·i386 0 입니다(기록 `m4-m68k-probe-p613-20261030.json`).
  - `__text` 202 B, L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate` 이고, 3/3 입니다(`m4-m68k-funcbytes-p613-A1-20261030.json`).
  - 섹션은 `__text`·`__cstring` 39 B 뿐입니다(자료·bss 없음). 지역 정의는 없고, COMMON 은 `_master_cpu` 하나(공유 머리, 원본에 있음 — D136)입니다. 원본에 없는 미정의는 없습니다.
- 바이트로 가를 수 없는 것(사용자에게 물음):
  - 파일 이름(원본은 정하지 않음; 객체 차례는 `pmap` → 이것 → `swapgeneric`)
  - 반환형(`void`/암묵 `int`)
  - 기계 형 이름 `NeXT_CUBE`·`NeXT_X15` 를 파일 안에 둘지

- 사용자 결정(2026-10-30, AskUserQuestion): ① 파일 이름 "`shutdown.c`"(객체 차례 `pmap.c` → `shutdown.c` → `swapgeneric.c` 의 알파벳 차례에도 맞음) ② 반환형 "`void`"(x86 07·Darwin ppc 의 `md_*` 와 같음).

## 614. M4-120 D139 구현 계획 — 07 `src/machdep/m68k/shutdown.c`(행 313, OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §613.2 결과와 위 결정입니다. A1 은 3/3·`OBJECT_MATCH` 이고, 자료·bss 가 없어 OBJECT_MATCH 객체(`ACCEPTED` 둘 묶음)입니다. 스테이지 `m0p612-a1-stage` 에 `src/machdep/m68k/shutdown.c` 는 없습니다(2 에서 확인).
1. 07 `src/machdep/m68k/shutdown.c`(D103)를 A1 글에서 scratchpad `gen_p614.py` 로 만듭니다.
   - 머리 고지는 NeXTMach `next/machdep.c` 의 "Copyright (c) 1987, 1988, 1989 NeXT, Inc." 그대로입니다(D013).
   - 설명 주석은 plan 614 덩이로 둡니다. 내용은 NeXTMach `boot()` 1272–1328 행에서 옮긴 줄, 1997 바뀜(`adb_watchdog(0)`, `machine_type` 0·2 조건, 끝줄 `\n\n`, `RB_PANIC` 빈 덩이 없음), 사용자 결정(파일 이름·`void`)입니다.
   - 파일 안 `NeXT_CUBE`·`NeXT_X15` 는 `plan 614 (D139, D113)` 표시(`next/scr.h:34·36`)를 답니다. 함수 정의 줄마다 `plan 614 (D024)` 표시(원본 바이트로 쓴 몸통, NeXTMach `boot()` 줄을 옮김)를 답니다(`kern_machdep.c:32` 꼴). 진단 표시는 모두 plan 614 로 바꿉니다.
   - 주석 뺀 토큰이 A1 과 같아야 하고, 표시 줄에 `*/` 뒤 글이 없어야 합니다(python).
2. `stage_m68k.py`: `M4FILES[614] = list(M4FILES[612]) + ['shutdown.c']`, `EXCEPTS[614] = dict(EXCEPTS[612])`, 머리말 plan 목록에 614 를 더합니다.
3. 회귀:
   - `--plan 612` 재생성(`m0p612-r614-stage`) = 보관본이어야 합니다.
   - `m0p614-a1-stage` 와 보관 612 의 차이는 그 파일 하나(972 → 973)와 키 `plan`·`m4_sources`·`files` 여야 합니다.
   - M5 205 줄(`m5-612.cmd` 가 §612 것과 `cmp` 같음; run `m3p614-b612`·`m3p614-cc1`)과 x86(`m4_x86_inputs.py s6ln`·`--plan 614 x86gate`)은 §612 와 같은 조건입니다.
4. 확인 run `m4p614-p1`: F = `@machdep/m68k/shutdown.c`, L = A1 글에 맞춤 주석 줄을 같은 자리에 넣은 꼴입니다(줄마다 주석 뺀 토큰 같음).
   - 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = A1(canon), 3/3, `OBJECT_MATCH` 사유 없음·`full_span`·`candidate` 이어야 합니다.
   - F·L 바이트 차이는 문자열 표·`n_strx` 뿐이어야 합니다.
5. 최종 run `m4p614-a1`(명세 `08_build/artifacts/m4p614/spec.json`: F 만, 바탕 `m0p614-a1-stage`, 객체 `shutdown`, `m4_id` `m68k-313`, `x86_rel` `machdep/i386/dkbad.c`, `m5_line` 그대로, `refs["shutdown"]` = [p1 L 객체, SHA-256], `known_warnings` 없음): `gate.ok`, 3/3 이어야 합니다.
   - python 확인 `m4-m68k-p614-checks-20261030.json`: 섹션(`__text` 202·`__cstring` 39), 문자열 참조가 원본과 같음(funcbytes), 외부 정의는 정확히 셋이고 원본 자리, 지역 없음, COMMON `_master_cpu`(크기 4) 하나가 원본에 있음(D136), `__text` 재배치 15 개가 모두 원본 대상과 같음(funcbytes·L1), 원본에 없는 미정의 없음, 컴파일 명령 = M5 줄, 의존 i386 0, 입력 사슬 전수.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-shutdown.md` 를 먼저 쓰고 `ACCEPTED` 에 둘 묶음 한 줄을 더합니다. 도구를 두 번 돌리고 §612 표와 대조합니다(더한 것 `shutdown` 하나).
   - 기대(python): 객체 39(OBJECT_MATCH 30, CODE+BSS_INFERRED 9), 덮은 행 63/188, 덮은 바이트 62944 + 202 = 63146, `object_bytes` 79980 + 202 = 80182 입니다. 백분율은 도구 출력을 씁니다.
7. 기록:
   - diff: NeXTMach `next/machdep.c` 의 고지(1–3 행)와 `boot()` 1272–1328 행을 옮긴 발췌를 이름 붙여 만들고, 그것과 07 파일을 비교한 `m68k-shutdown.diff` 를 둡니다. 새 머리·include·매크로는 근거 문서에 따로 적습니다.
   - PROVENANCE 새 행(일곱 칸, `nextmach+authored`: NeXTMach `next/machdep.c:1272–1328`·`next/scr.h:34·36`, 커밋 `f6bdb9c3…`, 고지, 작성 부분 D024, D139)
   - MODIFICATIONS, DECISIONS D139, 계획 결과와 현재 상태, HANDOFF, 메모리
   - 객체 경계(따로 객체)는 `__cstring` 차례로 지지되는 가설로 근거 문서에 적습니다. 상태 기대에 `rows_unassigned_before` 에 `m68k-313` 이 더해짐을 둡니다. M7 의무: `_master_cpu` COMMON 합침. 옮기지 않은 NeXTMach 덩이(`NOC`·`NCPUS` 조건, `sync`·`unmount_all` 등 앞부분)는 근거 문서에 적습니다.

관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 614.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 스테이지 키는 `plan`·`m4_sources`·`files`(`added` 그대로), 파일 972 → 973, 기대 수치 39/30/9/63/63146/80182 | §604 의 같은 꼴 결과, python 계산(이번 세션) | ✅ |
| A1 의 진단 표시는 매크로에만 있어, 작성 함수에도 범위를 밝힌 표시를 달 것(`kern_machdep.c:32` 꼴) | `kern_machdep.c` 14–40 행(이번 세션) | ✅ 1 고침 |
| 확인 run 에 `full_span`·`candidate`·사유 없음을 명시 | §602 4 | ✅ 4 고침 |
| 최종 명세에 F 만·바탕·`refs["shutdown"]`·`x86_rel`·`m5_line` 명시 | `m4p613/spec.json` | ✅ 5 고침 |
| `__text` 재배치는 15 개(APM 의 0 이 아님), `_master_cpu` 크기 4 를 기록 | `macho_obj` 로 셈(이번 세션: `__text` 15, `__cstring` 0) | ✅ 5 고침 |
| 고지는 NeXTMach `machdep.c:1–3` 과 바이트가 같음; 섞인 출처 파일의 선례(`kern_machdep.c`, PROVENANCE 1129 행)대로 그 고지만 두고 작성 부분을 주석에서 밝히면 됨 | NeXTMach 1–3 행(이번 세션) | ✅ |
| diff 를 빼는 까닭으로 "파일 이름이 다름" 은 약함(`m68k_init.diff` 도 다른 이름끼리 비교) — 이름 붙인 NeXTMach 발췌와의 diff 를 둘 것 | `m68k-m68k_init.diff` 머리 줄(§609) | ✅ 7 고침 |
| 기록에 함수별 옮김/작성, 저장소·커밋, 고지 1–3 행·매크로 `scr.h:34·36` 출처, 해시, M7 의무, 옮기지 않은 `NOC`·`NCPUS` 덩이, `rows_unassigned_before` 의 `m68k-313` 을 둘 것 | — | ✅ 7 고침 |

### 614.2 결과(2026-10-30)

- 1·2: 07 `src/machdep/m68k/shutdown.c`(75 행, SHA `7a78c50a…`)를 scratchpad `gen_p614.py` 로 A1 에서 만들었습니다. 주석 뺀 토큰이 A1 과 같고, L 과 줄마다 같습니다. 처음 생성본의 머리 문장 "Lines marked plan 614 are not NeXTMach text" 는 표시 없는 줄도 NeXTMach 글이 아니어서 부정확했고, "Only the notice and the lines of the boot() tail are NeXTMach text" 로 고쳤습니다. `stage_m68k.py` 721 → 723 행입니다.
- 3: `--plan 612` 재생성(`m0p612-r614-stage`) = 보관본입니다. `m0p614-a1-stage`(973 파일)와 보관 612 의 차이는 그 파일 하나와 키 `files`·`m4_sources`·`plan` 입니다(python assert). M5: `m5-612.cmd` 가 §612 것과 `cmp` 같고, run `m3p614-b612`·`m3p614-cc1` 종료 0, 객체·stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p614-compare-20261030.json`, `-b612-`) `differ_unexpected`·`lost` 빔, 요약 차이는 새 파일 하나뿐입니다. x86 `m4-x86-inputs-p614-20261030.json` `ok`, `--plan 614 x86gate` 일곱 같음입니다.
- 4: run `m4p614-p1`(`m4-m68k-probe-p614-p1-20261030.json`): F·L 종료 0·경고 0·`OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 3/3(`m4-m68k-funcbytes-p614-F/L-20261030.json`)입니다. F = L(canon·`obj_sig` 모든 칸, STABS 391), L = A1 이고, 바이트 차이는 문자열 표·`n_strx` 뿐입니다.
- 5: run `m4p614-a1`(`m4-m68k-p614-final-20261030.json`, SHA `14fec4a5…`): `gate.ok`, 3/3(`m4-m68k-funcbytes-p614-a1-20261030.json`)입니다. 확인 `m4-m68k-p614-checks-20261030.json`(`ok` 참): 섹션 202·39, `__text` 재배치 15·참조 15 모두 원본과 같음, 외부 정의 셋이 원본 자리, 지역 없음, COMMON `_master_cpu`(4) 하나, 원본에 없는 미정의 없음, 의존 73 파일 사슬 문제 0·i386 0, 객체 SHA `ca258039…` 입니다.
- 6: 근거 `06_reconstruction/evidence/m68k-shutdown.md`(상태 도구 전). `ACCEPTED` 에 한 줄을 더했습니다. 상태표 40 → 41 행·`m4-m68k-status-p614-20261030.json`: 39 객체(OBJECT_MATCH 30, CODE+BSS_INFERRED 9), 덮은 행 63/188, 63146/215874 B(29.25%), `object_bytes` 80182, `rows_unassigned_before` 에 `m68k-313` — 미리 계산한 값과 같고, 두 번 실행이 같으며, 더한 것은 `shutdown` 뿐입니다.
- 7: diff `m68k-shutdown.diff`(NeXTMach 발췌 1–3·1272–1328 행 대비, 119 행), PROVENANCE 1187 → 1188 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 722 → 723 행, DECISIONS D139(142 → 143 행), "현재 상태와 다음 일" 을 고쳤습니다.
