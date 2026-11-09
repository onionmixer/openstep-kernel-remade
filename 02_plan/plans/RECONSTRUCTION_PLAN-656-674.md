# 커널 소스 복원 작업계획 — 보관 §656–674

`02_plan/RECONSTRUCTION_PLAN.md` 의 §656–674(m68k M4 `sf_access.c`(D152), `sd.c`·공유 `scsireg.h`(D153), `scsi.c`(D154), `sc.c`·공유 `scvar.h`(D155), `zscom.c`(D156); §664·§671 은 절 제목이 없고 §663·§670 안의 결과로 적혀 있음)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-01, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 656. M4-162 세부 계획 — m68k `sf_access.c`(행 240 일부) 진단 A1·A2(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: 같은 SCSI 묶음에서 가장 작고, 앞(`sd` 쪽 0x407f358–0x407f3c4 항목)과 뒤(받아들인 `sg`, 0x407f612)의 경계가 뚜렷합니다.

확인한 사실(이번 세션; 원본 풀이 scratchpad `sfa.dis` = `scsi_all.dis` 의 [0x407f3c4, 0x407f612), 수는 python):
- 범위 [0x407f3c4, 0x407f612) 590 B, 이어진 세 항목 `_sfa_arbitrate` 206·`_sfa_relinquish` 242·`_sfa_abort` 142(`m68k-functions.tsv` 2826–2828 행), 모두 외부 이름. 풀이 줄의 바이트 590 B 가 Mach-O 바이트와 모두 같음(python, 불일치 0).
- 참고 글: NeXTMach mk-108.1 `nextdev/sf_access.c`(238 행, SHA-256 `3ea513aa…`, ASCII)의 정의 차례 `sfa_arbitrate`(20)·`sfa_relinquish`(89)·`sfa_abort`(183). 머리 `nextdev/sf_access.h` 는 07 `nextmach/nextdev/sf_access.h` 가 NeXTMach 그대로(SHA `ce252d6d…`, 같음 확인; §570, D128)이고 스테이지 `m0p655-a1-stage` 의 `src/bsd/nextdev/sf_access.h`.
- 행: 인벤토리 행 `m68k-240`(`nextdev/sf_access.c`, `exact` 0, 시작 0x407e5de–0x407f3c4·끝 0x407f612–0x407f70e, `bytes_min` 590)은 이 범위보다 넓어 `rows` 에 넣을 수 없습니다. `span()` 은 `{"range": ["0x407f3c4", "0x407f612"], "rows": [], "partial": ["m68k-240"], …}` 만 받습니다(python 으로 셋 시험: `rows` 에 240 → `row outside range`, `partial` 에 239 를 더함 → 멈춤). 행 240 은 `exact` 가 아니라 `tiled_rows`(D145)에도 들지 않으므로, 받아들여도 덮은 행·바이트는 그대로입니다(미리 정한 규칙; 바꾸지 않음).
- 원본에서 읽은 것(NeXTMach 와 대조): 구조체 칸 자리는 07 `sf_access.h` 배치와 맞음(`sfah_wait_cnt` `u_char` +4 — `addqb`·`subqb`·`tstb`; `sfah_q` +6; `sfah_flags` +14; `sfah_last_dev` +18; `sfah_excl_q` +22; `sfah_busy` +26; `sfad_start` +0·`sfad_arg` +4·`sfad_link` +8·`sfad_flags` +16). `simple_lock`·`simple_unlock` 은 코드가 없음(스테이지 `kern/lock.h:102–103` 빈 매크로), `spldma()` 는 0x2600(`movew #9728,%sr`), `splx` 는 `movew %d1,%sr`. `sfa_arbitrate` 의 panic 은 0x40aba88 문자열 하나. `sfa_relinquish` 의 `last_device != SF_LD_NONE` 는 `tstl`(0), 처음 큐가 비면 spl 을 되돌리지 않고 나가는 갈래(0x407f4ec)까지 NeXTMach 흐름과 같아 보임. `sfa_abort` 는 `bsrl 0x407f492`(`sfa_relinquish`). 읽은 범위에서 NeXTMach 와 다른 곳을 찾지 못했습니다.
- 문자열: 이 객체 몫 [0x40aba88, 0x40abaae) 38 B = `"sfa_arbitrate: onwer changed priority"` + NUL(python; 끝이 `sg` 몫 0x40abaae 와 맞닿음). `__data` 는 없을 것으로 봄(`sf_access_head[]` 는 NeXTMach `scsiconf.c:96`).
- 컴파일 줄(M5 줄 = `08_build/artifacts/m4p655/m5-655.cmd`)에 `-DDEBUG` 없음(grep 0) → `XPR_SFA` 와 `#ifdef DEBUG` 의 `printf` 는 빈 꼴.
- include: NeXTMach 다섯 줄 중 `<next/spl.h>` 만 스테이지에 없습니다. C 파일 선례는 `<machine/spl.h>`(07 `bsd/ufs/ufs_dsort.c:49` plan 206, `machdep/m68k/snd_reply.c:44` plan 554·D104); 어셈블리 `monitor.s:23` 은 `<m68k/spl.h>`(D109). 스테이지 `bsd/machine/spl.h` 는 `ARCH_INCLUDE(bsd/, spl.h)` 로 `bsd/m68k/spl.h` 에 닿음. 나머지 넷(`sys/types.h`·`kern/queue.h`·`kern/xpr.h`·`nextdev/sf_access.h`)은 스테이지에 있음.

방법(진단; 07 은 바꾸지 않음; 원천 scratchpad `p656/gen_p656.py` 가 NeXTMach 글(SHA 단언)에서 만듦 → `08_build/artifacts/m4p656/src/`):
- 변형 A1: NeXTMach 글에서 17 행 `<next/spl.h>` 만 `<machine/spl.h>` 로(C 파일 선례).
- 변형 A2: 17 행만 `<m68k/spl.h>` 로(대조; include 철자가 바이트로 가려지는지).
- 진단 머리(`inc`) 없음(`[]`). 명세 `08_build/artifacts/m4p656/spec.json`: 바탕 `08_build/runs/tools/m0p655-a1-stage`, `m5_line` 은 §653 과 같은 `08_build/artifacts/m5p494/final.cmd`, 객체 `sf_access`, 위 명시 구간(basis: `_sfa_arbitrate` 0x407f3c4 앞은 `sd` 쪽 항목, 0x407f612 는 받아들인 `sg` 시작), `x86_rel` `machdep/i386/dkbad.c`(§653 과 같은 자리 채움). run `m4p656-p1`(REGISTRY 에 없음 확인), 기록 `m4-m68k-probe-p656-p1-20261031.json`, funcbytes `m4-m68k-funcbytes-p656-<변형>-20261031.json`(이름 대응 불필요).
- 측정: 종료 상태·경고, 함수별 길이·바이트·재배치 대상, 절(`__text` 590 목표, `__data` 없음, `__cstring` 38 B 를 원본 0x40aba88 과 내용으로), 바깥 정의 셋이 원본 자리, COMMON·미정의가 원본 이름인지(D136), 지역 기호 없음. 단언 스크립트 scratchpad `p656/chk_p656.py`(§653 `chk_p653.py` 꼴).
- 예상: A1·A2 모두 3/3, 서로 바이트가 같음.

판정(미리 정함; 07 은 바꾸지 않음): A1 이 3/3 이고 절·문자열·기호 단언이 맞으면 구현 계획(§657)을 세웁니다. A1 과 A2 가 같으면 include 철자는 C 파일 선례(`<machine/spl.h>`)를 따르고 묻지 않습니다(바이트가 가리지 않는 꼴이나 이미 선례가 둘 있음). 다른 함수가 있으면 원본 바이트로 원인을 찾아 다음 진단에서 고치고, 컴파일이 안 되면 원인을 적고 최소로 고친 꼴로 다시 돌립니다.

### 656.1 교차검토(codex `gpt-6.1-sol`, task kgxfgpi1k) 판정과 계획 수정

먼저 제 잘못 둘: ① `DEBUG` 가 꺼졌다는 근거를 컴파일 줄의 `-DDEBUG` 부재로만 적었습니다(스테이지 안 `#define DEBUG` 여부를 보지 않음). ② A2 를 "include 철자가 바이트로 가려지는지" 보는 대조라고 적었으나, `bsd/m68k/spl.h` 는 17 행보다 먼저 `kern/xpr.h` 사슬로 이미 들어오므로 A2 는 그보다 약한 시험입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A1 을 바꿀 바이트 차이 없음(0x407f426 넣기, 0x407f51e 빼기, 0x407f5fc 다음 칸, 0x407f5a4 호출; 0x407f4ec → 0x407f57a 는 spl 을 되돌리지 않고 나감 = `sf_access.c:136` 뒤 빈 고리) | 이번 세션 `sfa.dis` 전체를 읽음(위 자리 모두), NeXTMach 글 136–175 행 | ✅ 다만 판정은 run 이 함 |
| 크기 206·242·142(590), 238 행, 정의 20·89·183, SHA `3ea513aa…`·`ce252d6d…`, 문자열 38 B(`"onwer"` 철자 그대로) | `m68k-functions.tsv:2826–2828`, `cat -n` 출력, `sha256sum` 출력, python(0x40aba88 + 38 = 0x40abaae) | ✅ |
| 칸 자리·spl 관찰이 맞음; 빈 lock 은 `lock.h:66–103`; 정렬 2 B(`m0-abi-m68k-20261009.json:564`) | `lock.h` 66 행 `MACH_SLOCKS`·102–103 행 빈 매크로, ABI 기록 563–565 행 `alignof int/long` 2 | ✅ |
| `span()`·덮음 결과(76 행·73258 B·33.94%, 객체 54·OM 45·`object_bytes` 100794) | 이번 세션 python 으로 `P.span` 셋 시험, `m4_m68k_status.py:98–110`(103 행 `exact` 검사), python 으로 100204 + 590 | ✅ |
| `DEBUG` 결론은 컴파일 줄만으로 부족; 실제 매크로 상태(`DEBUG` 없음, `ASSERT` 빈 꼴, lock 빈 꼴, `NIPLMEAS` 0)를 적을 것 | 스테이지 전체 grep `define DEBUG` 0 건, 생성 `iplmeas.h:1` `#define NIPLMEAS 0`, `sf_access.h:101–108` | ⚖️ 사실 확인을 계획에 적음; `-DDEBUG=0` 은 컴파일 줄에 없으므로 해당 없음. 실제 상태는 바이트(XPR·`printf` 코드 없음)와 `__cstring` 38 B 단언으로도 봄 |
| `kern/xpr.h` 가 17 행 전에 `bsd/m68k/spl.h` 를 들임 → A1·A2 같음은 SPL 머리 동치의 증명이 아님 | 사슬을 열어 봄: `kern/xpr.h:119` → `machdep/machine/xpr.h:8` → `machdep/m68k/xpr.h:44` → `machdep/m68k/eventc.h:38` `#import <bsd/m68k/spl.h>` | ✅ A2 는 "이 include 차례에서 바이트가 같은지"만 보는 대조로 고침 |
| 관문을 따로 단언할 것: 진단 비교는 `refs` 가 없으면 실패하지 않고(`m4_m68k_probe.py:381–383` `diag_gate` 만 기록), funcbytes 도 다름을 적기만 함(`m68k_funcbytes.py:245–250`) | 그 줄들을 읽음 | ✅ `chk_p656.py` 가 변형마다 `diag_gate` 둘, `OBJECT_MATCH`·사유 없음·`full_span`·`candidate`, funcbytes `same == total == 3`·`object_only` 빔·객체 SHA 일치, A1–A2 `canon_equal`·`sig_equal`, 절이 `__text`·`__cstring` 뿐(`__data`·`__bss` 없음), STABS 를 뺀 지역 기호 0 을 단언하고 하나라도 어긋나면 종료 1 |
| 명세는 아직 없음; `m4_id` 를 `rows: []`·`partial`·비지 않은 `basis` 로 다 적을 것; 명령은 `x86_rel` 줄에서 오고 `m5_line` 은 선택지 비교용 | `m4_m68k_probe.py:159`(`basis` 단언)·`194–207`(`x86_line`, `D` 의 선택지 비교) | ✅ 계획대로; 기록의 `options` 에서 차이 없음(`true`)을 단언에 더함 |
| `#import` 는 그대로, 경로만 바꿈; `-traditional-cpp` 와 `#endif DEBUG` 꼬리 토큰은 그대로 | 계획이 이미 17 행 경로만 바꿈; 같은 머리를 들인 `fd_io` 최종 기록(`m4-m68k-p573-final-20261030.json`)의 컴파일 종료 0·경고 0, 의존 목록에 `sf_access.h` 있음(python) | ✅ |

계획 수정: A2 의 목적을 "같은 include 차례에서 바이트가 같은지 보는 대조"로 낮추고, 판정의 include 철자는 C 파일 선례(`<machine/spl.h>`)를 따르는 근거로 선례만 씁니다. 실제 매크로 상태(스테이지 `define DEBUG` 0 건, `NIPLMEAS` 0, `simple_lock` 빈 꼴)를 확인한 사실에 더하고, `chk_p656.py` 의 단언 목록을 위 표대로 정합니다.

2차 자기검사: ✅ 행의 근거는 모두 이번 세션에 연 줄·돌린 python·명령 출력입니다.

### 656.2 결과(run `m4p656-p2`, 2026-10-31)

- 먼저 제 잘못: 첫 run `m4p656-p1` 을 `kr_run wait` 뒤 `collect` 까지 돌려 게시했습니다(`stage` → `out`). `m4_m68k_probe.py compare` 는 게시되지 않은 run 만 받으므로(`run_checks`, `run was published`) 거부했습니다. 게시된 run 은 고치지 않고 그대로 두며 쓰지 않습니다. 같은 스테이지 `08_build/runs/tools/m4p656p1-stage`·같은 `probe.cmd` 로 새 ID `m4p656-p2` 를 돌렸습니다. 두 run 의 A1·A2 객체 SHA 가 같습니다(`55c5d1a3…`·`a2b1613b…`; p1 `collect` 는 명령 넷 종료 0·출력 매니페스트 일치를 확인함).
- 명령 4 개 종료 0·경고 0, 의존 목록 i386 0, 원본에 없는 미정의 0, M5 줄과 선택지 차이 없음(`m4-m68k-probe-p656-p2-20261031.json`).
- **A1·A2 모두 OBJECT_MATCH**(L1 사유 없음, 자리 0x407f3c4, `full_span`, `candidate`), funcbytes **3/3**(`m4-m68k-funcbytes-p656-A1/A2-20261031.json`; `_sfa_arbitrate` 206·`_sfa_relinquish` 242·`_sfa_abort` 142 모두 같음, 재배치 대상 차이 없음). A1 과 A2 는 canon·`obj_sig` 까지 같음.
- 단언(scratchpad `p656/chk_p656.py`; 기록 `m4-m68k-p656-diagchecks-20261031.json`, `ok`): 절은 `__text` 590·`__cstring` 38 뿐(`__data`·`__bss` 없음), `__cstring` 38 B 가 원본 0x40aba88 의 바이트와 같음, 바깥 정의 셋이 원본 자리(0x407f3c4·0x407f492·0x407f584), STABS 를 뺀 지역 기호 0, COMMON 0, 미정의는 `_panic` 하나(원본 이름).

판정(미리 정한 대로): NeXTMach 글에 include 한 줄만 바꾼 꼴이 원본과 같습니다. include 철자는 C 파일 선례 `<machine/spl.h>` 를 따르고(A2 와 바이트 같음; 묻지 않음), 구현 계획 §657 을 세웁니다.

## 657. M4-163 D152 구현 계획 — 07 `src/machdep/m68k/sf_access.c`(명시 구간 [0x407f3c4, 0x407f612), 부분 행 240, OBJECT_MATCH; 코딩 전, 2026-10-31)

이번 단위에는 바이트로 가려지지 않으면서 선례가 없는 꼴이 없어 여쭐 것이 없습니다: 글은 NeXTMach 그대로(D013·D024), include 는 OPENSTEP 경로(D104; `<next/spl.h>` → `<machine/spl.h>` 는 C 파일 선례 `ufs_dsort.c`·`snd_reply.c`, §656.2 에서 A2 와 바이트 같음), 머리 `nextdev/sf_access.h` 는 이미 있는 07 사본(§570, D128; 바꾸지 않음), 07 자리는 D103(`src/machdep/m68k/`), 공유 머리 COMMON 규칙(D136; 이 객체는 COMMON 0). 결정 기록은 D152(상태 `확정`, 사용자 결정 아님 — 앞선 결정을 따른 받아들임)로 적습니다.

확인한 사실(이번 세션): 07 `src/machdep/m68k/sf_access.c` 와 스테이지 `m0p655-a1-stage` 의 `sf_access.c` 는 없음, PROVENANCE 에 `sf_access.c` 행 0. 구성 머리 없음(NeXTMach 글이 `#import "…"` 구성 머리를 들이지 않음). 상태 기대(python, §656 앞에서 계산): 객체 53 + 1 = 54(OBJECT_MATCH 45, CODE+BSS_INFERRED 9), 행 76/188 그대로, 덮은 바이트 73258(33.94%) 그대로, `object_bytes` 100204 + 590 = 100794, `partial_rows` 는 그대로(`m68k-240` 이 `sg`·`sf_access` 둘의 부분 행; `exact` 0 이라 `tiled_rows` 아님).

1. 07 `sf_access.c`: scratchpad `p656/gen_p657.py --write`(이미 있으면 멈춤) — NeXTMach `sf_access.c`(SHA `3ea513aa…` 단언)의 12 행(머리 주석 끝) 뒤에 머리 주석 덩이(plan 657, 원본 범위, include 한 줄만 바꿈, 나머지 NeXTMach 그대로)를 넣고, 17 행을 `#import <machine/spl.h>\t/* plan 657 (D104): NeXTMach <next/spl.h> */` 로. 단언: F 와 진단 A1(§656.2 기록 `m4-m68k-probe-p656-p2-20261031.json` 의 A1 `source_sha256` 에 묶음)의 토큰이 같음; L(주석을 지운 꼴, 주석만 있던 줄은 §655 처럼 `/* plan 657 confirm L: alignment */`, `08_build/artifacts/m4p657/src/sf_access_L.c`)과 F 의 토큰·토큰 줄이 같음; 표시 없는 바뀐 줄 0(§655 의 lexer·`strip_comments` 를 그대로 씀).
2. `stage_m68k.py`: `M4FILES[657] = list(M4FILES[655]) + ['sf_access.c']`, `EXCEPTS[657] = dict(EXCEPTS[655])`, 머리말 목록에 657. `M4HEADERS` 는 그대로(가장 큰 키 ≤ 계획 = 655).
3. 회귀: `--plan 655` 재생성(`m0p655-r657-stage`)은 보관본 `m0p655-a1-stage` 와 매니페스트가 같아야 함(바뀐 07 파일 없음; 다르면 멈춤); 새 스테이지 `m0p657-a1-stage` 는 그것과 `sf_access.c`(키 `files`·`m4_sources`·`plan`)만 다르고 트리 어긋남 0; `m5-655.cmd` 는 §655 보관본과 같고 `m5-657.cmd` 는 계획 번호만 다름; M5 205(run `m3p657-b655`·`m3p657-cc1`) 객체·출력 같음, `compare` 둘의 `differ_unexpected`·`lost` 빔; x86 `m4_x86_inputs.py s6ln` `ok`(기록 `m4-x86-inputs-p657-20261031.json`)·`--plan 657 x86gate` 일곱 같음.
4. 확인 run `m4p657-p1`(명세 `08_build/artifacts/m4p657/spec-p1.json`, 바탕 `m0p657-a1-stage`, §656 의 명시 구간): F = `@machdep/m68k/sf_access.c`, L. 판정: 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 3/3(`m4-m68k-funcbytes-p657-F/L-20261031.json`), F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx` 뿐). `-E` run `m4p657-e2`(F·L·A1; 기록 `m4-m68k-p657-e2-20261031.json`): `#` 줄 뺀 토큰 F = L = A1, stderr 0(`_log`), i386 0. 이번에는 `wait` 뒤 `collect` 를 돌리지 않고 probe `compare` 로 갑니다(§656.2 의 제 잘못); `-E` run 은 §655 처럼 `collect` 뒤 `out/_log` 를 읽습니다.
5. 최종 run `m4p657-a1`(명세 `08_build/artifacts/m4p657/spec.json`, F 만, `refs` = p1 L 과 SHA; 기록 `m4-m68k-p657-final-20261031.json`): `gate.ok`, funcbytes 3/3(`-p657-a1-`). 확인 기록 `m4-m68k-p657-checks-20261031.json`: §656.1 단언 전부(`chk_p656.py`)를 최종 객체 SHA 에 묶고 + 컴파일 줄 = M5 줄, 의존 i386 0·SHA 사슬(`sf_access.h` 포함), `e2` ok, 07 파일 SHA = 스테이지 SHA.
6. 상태: 근거 `06_reconstruction/evidence/m68k-sf_access.md` 와 diff `m68k-sf_access.diff` 를 먼저 쓰고 `ACCEPTED` 에 한 줄; 상태 도구 두 번(`m4-m68k-status-p657-20261031.json`), 기대는 위 값.
7. 기록: PROVENANCE 한 행(`sf_access.c` nextmach+authored — URL·커밋·경로·바뀐 줄; 1209 → 1210, 일곱 칸), MODIFICATIONS 한 행(744 → 745), DECISIONS D152(155 → 156 행, 결정 행 151 → 152), 계획·HANDOFF·메모리. M7 의무: `sf_access_head[]` 정의(NeXTMach `scsiconf.c:96`)와 `_panic` 은 다른 객체.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, `e2`·확인 기록 `ok`, 최종 funcbytes 3/3, 상태 도구가 멈추지 않고 기대 값과 같음. 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 657.1 교차검토(codex `gpt-6.1-sol`, task ky48gp9vp) 판정과 계획 수정

먼저 제 잘못: 처음 쓴 §657 에 DECISIONS 를 "154 → 155 데이터 행" 으로 적었습니다(실제 155 행, 결정 행 151; python). codex 에 보내기 전에 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상태 기대 54·45·9, 76/188, 73258, 33.94%, 100794 와 `partial_rows` 그대로; 기록 행 수 1209→1210·744→745·155→156(결정 151→152) | 이번 세션 python(상태 p655 기록 요약 + 590, `wc -l`, DECISIONS 행 셈), `m4_m68k_status.py:103` | ✅ |
| "구성 머리 없음" 은 "새 구성 머리 없음" 으로: spl 이 생성 `iplmeas.h` 를 들임 | 스테이지 `bsd/m68k/spl.h:23` `#import <iplmeas.h>` | ✅ 문구 고침(이미 스테이지에 있는 생성 머리이고 바뀌지 않음) |
| 머리·원천은 가장 큰 키 ≤ 계획, 명령 입구와 비교는 `EXCEPTS` 정확한 키 → `M4FILES[657]`·`EXCEPTS[657]` 로 충분 | `stage_m68k.py:563`·`582`(max 키), `677`·`738`(`EXCEPTS[PLAN]`, `int(a[1]) in EXCEPTS`), `580`(`known` 은 모든 계획의 합) | ✅ |
| 메모리에서 다시 만든 `--plan 655` 매니페스트가 보관본과 바이트 같음(994 파일), 명령 205·411 행 같음 | codex 의 메모리 재현은 근거로 쓰지 않음 | ⚖️ 3 단계에서 실제로 다시 만들어 비교함(계획 그대로) |
| 확인 기록 파일 이름을 적을 것 | 1486 행에 이름 없음 | ✅ `m4-m68k-probe-p657-p1-20261031.json` |
| `-E` 명령 파일의 `EXPECT` 줄을 둘 것; 확인 run 의 단언은 종료 상태와 따로 강제할 것(`m4_m68k_probe.py:381`, `m68k_funcbytes.py:245`) | 1419 행(§655.2 의 `EXPECT` 누락 기록), §656.1 에서 그 두 줄을 읽음 | ✅ `-E` 명령 파일은 `EXPECT` 셋을 넣고, p1 에는 `chk_p656.py` 의 단언(변형 F·L, 둘의 canon·`obj_sig`)을 그대로 돌림 |
| D152 `확정` 이 관례와 맞음(인용 `DECISIONS.md:5·8·12`) | 5 행 D001 `확정`; 8 행은 D004 `잠정`, 12 행은 D008 `사용자 확정` | ⚖️ 결론은 맞음(`확정` 행 D001·D002·D003·D007 이 사용자 결정과 구분됨), 인용 둘은 `확정` 의 예가 아님 |

계획 수정: 확정 기록 이름 `m4-m68k-probe-p657-p1-20261031.json` 을 더하고, p1 결과에 `chk_p656.py` 단언(F·L)을 돌려 `m4-m68k-p657-p1checks-20261031.json` 으로 남깁니다. `-E` 명령 파일에 `EXPECT` 셋. "구성 머리 없음" → "새 구성 머리 없음(스테이지의 생성 `iplmeas.h` 는 그대로)".

2차 자기검사: ✅ 행은 이번 세션에 연 줄·돌린 python 입니다.

### 657.2 결과(2026-10-31)

먼저 제 잘못(모두 기록이나 run 을 남기기 전에, 또는 남긴 것을 바로잡고 고침):
- `m4_x86_inputs.py s6ln` 을 §655 와 달리 `L2_FORMS`·`L2_EXPECT`(s6p398) 없이 돌려 `ok` 거짓 기록이 생겼습니다. 그 파일은 scratchpad(`m4-x86-inputs-p657-noenv.json`)로 옮기고 두 환경 변수를 주어 다시 돌렸습니다.
- 기준 M5 run `m3p657-b655` 를 `--plan 657 compare` 로 비교해 `O657__` 파일을 찾다 멈췄습니다(기록은 쓰이지 않음). 선례(§655 의 `--plan 652 compare m3p655-b652`)대로 `--plan 655` 로 다시 돌렸습니다.
- 확인하려던 명령에 `stage_m68k.py --plan 657 x86gate /dev/null` 이 섞여 실행되었습니다. 첫 줄 `os.makedirs` 에서 `FileExistsError` 로 멈추므로 아무것도 쓰지 않았습니다(같은 명령을 다시 돌려 확인).
- `-E` 기록 스크립트의 `exec` 이름 공간을 잘못 줘 첫 실행이 `NameError` 로 멈췄습니다(기록 쓰기 전). 고쳐 다시 돌렸습니다.
- 생성기 초안의 머리 주석에 D024(함수 단위 작성)를 넣었다가, 바꾼 함수가 없어 07 에 쓰기 전에 뺐습니다.

- 1 07 `src/machdep/m68k/sf_access.c` 245 행, SHA `9ccff8be…`(scratchpad `p656/gen_p657.py --write`; NeXTMach SHA·F = A1 토큰·F = L 토큰과 토큰 줄·바뀐 줄 하나이고 표시됨을 단언). L 은 `08_build/artifacts/m4p657/src/sf_access_L.c`. 바뀐 NeXTMach 줄은 17(include), 넣은 자리는 12 뒤(머리 주석; diff `06_reconstruction/evidence/m68k-sf_access.diff`).
- 2 `stage_m68k.py` 754 → 756 행(`M4FILES[657]`·`EXCEPTS[657]`·머리말 목록).
- 3 회귀: `--plan 655` 재생성(`m0p655-r657-stage`, 994 파일)의 매니페스트가 보관본과 바이트까지 같음; 새 스테이지 `m0p657-a1-stage`(995 파일)는 그것과 `sf_access.c`(키 `files`·`m4_sources`·`plan`)만 다르고 두 트리 모두 어긋남 0. `m5-655.cmd` 는 §655 보관본과 같고 `m5-657.cmd` 는 412 줄 중 411 줄이 계획 번호만 다름(RUN 205). M5 205(run `m3p657-b655`·`m3p657-cc1`): 객체 205 와 다른 출력 같음(`run.json` 만 다름), `compare` 둘(`m3-m68k-p657-b655-compare-20261031.json`·`m3-m68k-p657-compare-20261031.json`)의 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 `sf_access.c` 뿐(§655 기록과도 그것뿐). x86 `m4-x86-inputs-p657-20261031.json` `ok` 이고 p655 기록과 모든 키가 같음; `--plan 657 x86gate` 일곱 같음(관문 기록은 `plan` 과 도구 SHA 만 다름).
- 4 확인 run `m4p657-p1`(`m4-m68k-probe-p657-p1-20261031.json`; 명세 `spec-p1.json`): 명령 4 개 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 3/3(`-F/L-`), §656.1 단언 F·L 모두 `ok`(`m4-m68k-p657-p1checks-20261031.json`), F = L(canon·`obj_sig`; 문자열 표 앞 차이 253 B 는 모두 `n_strx`, 문자열 표 크기 같음). `-E` run `m4p657-e2`(`m4-m68k-p657-e2-20261031.json`, `ok`; 명령 파일 `e2/preproc.cmd` 에 `EXPECT` 셋): F = L = A1 2919 토큰, stderr 0(`_log` 셋), i386 0; 함수 몸통의 `-E` 출력에 남은 이름은 `panic` 하나(`XPR`·lock·`printf`·`ASSERT` 0).
- 5 최종 run `m4p657-a1`(`m4-m68k-p657-final-20261031.json`, SHA `d13dd411…`): `gate.ok`, 3/3(`-p657-a1-`). 확인 `m4-m68k-p657-checks-20261031.json`(`ok` 참; scratchpad `p656/checks_p657.py`): 절 `__text` 590·`__cstring` 38(원본 바이트와 같음), 바깥 정의 셋이 원본 자리, 지역 0·COMMON 0·미정의 `_panic`, 텍스트 재배치 3, 컴파일 줄 = M5 줄, 의존 39 개 SHA 사슬 문제 없음(`sf_access.h`·생성 `iplmeas.h` 포함)·i386 0, 07 파일 SHA = 스테이지 SHA. 객체 SHA `49f2203a…`(p1 의 F 와 같음).
- 6 상태(`m4-m68k-status-p657-20261031.json`, 표 55 → 56 행; scratchpad 에 두 번 돌려 같음): 객체 54(OBJECT_MATCH 45, CODE+BSS_INFERRED 9), 행 76/188, 73258 B(33.94%), `object_bytes` 100794, `partial_rows`·`rows_tiled` 그대로 — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-sf_access.md`.
- 7 기록: PROVENANCE 1209 → 1210 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 744 → 745, DECISIONS D152(155 → 156 행, `확정`), 계획 "현재 상태와 다음 일" 고침.

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D152).

## 658. M4-164 세부 계획 — m68k `sd.c`(행 238·239, 행 237·240 일부) 진단 A1(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: 같은 SCSI 묶음에서 `sg`·`sf_access` 다음으로 경계가 정해진 덩어리입니다(뒤는 받아들인 `sf_access` 0x407f3c4, 앞은 `_scsi_sensemsg` 끝 0x407c574). 크고(11856 B, 42 항목) 1997 바뀜이 있을 것이므로, 첫 진단은 NeXTMach 글이 어디까지 맞는지 재는 데만 씁니다.

확인한 사실(이번 세션; 원본 풀이 scratchpad `sd.dis` = `scsi_all.dis` 의 [0x407c574, 0x407f3c4), 바이트 11856 B 가 Mach-O 와 모두 같음; 수는 python):
- 범위 [0x407c574, 0x407f3c4) 11856 B, 이어진 42 항목. 외부 이름은 `_sdopen`·`_sdclose`·`_sdsize`·`_sdread`·`_sdwrite`·`_sdstrategy`·`_sdioctl`·`_sdchecklabel` 여덟 함수(원본 기호표에는 그 밖에 자료 `_sd_sd`·`_sd_sdd`·`_sd_sdsw`)이고 나머지 34 는 이름 없음.
- 참고 글: NeXTMach mk-108.1 `nextdev/sd.c`(3044 행, SHA-256 `464fdb80…`, ASCII), 머리 `nextdev/sdvar.h`(271 행, SHA `fcf76f3c…`; NeXTMach 에만 있음 — 07·SDK·Darwin 에 같은 이름 없음, 파일 이름으로 찾음). 원본에 없는 바깥 이름 `sd_xpr_*`(NeXTMach 79–87 행)는 `#ifdef DEBUG` 아래이고, `sd_new_sv`·`sd_thread_timer` 는 앞쪽 선언(184·193 행)이 `static` 이라 원본과 맞음.
- 이름 대응(정의 차례와 크기; `_sd_sdsw` 로 다섯 확인): `__data` 0x40b208c `_sd_sdsw` 26 B = `"sd"`(0x40ab656)·0·0·0x407c574·0x407c58e·0x407c844·0x407d41e·0x407d6fc = NeXTMach `sd.c:142–151` 의 `sdgetsdp`·`sdslave`·`sdattach`·`sdstart`·`sdintr`. 앞 11 항목 0x407c574 `sdgetsdp` 26·0x407c58e `sdslave` 694·0x407c844 `sdattach` 80·0x407c894 `sdattach2` 510·0x407ca92 `sdsetbratio` 254·0x407cb90 `sdwake` 18·0x407cba2 `sdinquiry` 108·0x407cc0e `sdmodesen` 108·0x407cc7a `sdspinup` 116·0x407ccee `sdtestrdy` 110·0x407cd5c `sd_eject` 304; 가운데 `_sdopen`·`_sdclose` 뒤에 NeXTMach 에 없는 `_sdsize` 64 B, `_sdstrategy` 뒤 다섯 0x407d376 `sd_vstart` 168·0x407d41e `sdstart` 734·0x407d6fc `sdintr` 1480·0x407dcc4 `sd_err_info` 176·0x407dd74 `sddone` 274(NeXTMach `delay_biodone` 1750 행은 `#ifdef OD_SIMULATE` 아래로 보임 — A1 이 판정); `_sdioctl` 뒤 0x407e348 `sdgetlabel` 348·0x407e4a4 `sdwritelabel` 206·0x407e572 `sdreadcapacity` 108, `_sdchecklabel`, 그 뒤 15 0x407e678 `sdcmd_srq` 394·0x407e802 `sd_new_sv` 182·0x407e8b8 `sd_free_sv` 72·0x407e900 `sd_assign_sv` 52·0x407e934 `sd_vol_check` 1658·0x407efae `sd_vc_timeout` 32·0x407efce `sd_compare_vol` 116·0x407f042 `sd_copy_vol` 102·0x407f0a8 `sd_vc_assign` 150·0x407f13e `sd_alert_panel` 176·0x407f1ee `sd_vol_panel_abort` 98·0x407f250 `sd_volume_notify` 148·0x407f2e4 `sd_thread_timer` 76·0x407f330 `sd_volume_done` 40·0x407f358 `sdd_init` 108.
- 자료: 이 객체의 `__data` 는 [0x40b207c, 0x40b20a6) 42 B — 앞 16 B 가 1000000·0·0·0(= NeXTMach `sd.c:108–111` 의 `sd_vc_delay = SD_VC_DELAY_NORM`(`sdvar.h:226` 1000000)·`sd_thread_init`·`sd_num_drives`·`sd_num_removables`), 뒤 26 B 가 `_sd_sdsw`. 가장 가까운 원본 기호로는 `_scsi_sdswlist+16..+28`(그 기호의 몫은 NeXTMach `scsiconf.c`). 정적 bss 는 0x40b4fde 부터(참조 26 곳; 크기는 다른 bss 객체처럼 zerofill 기록으로 정할 것 — 받아들이면 CODE+BSS_INFERRED 꼴로 예상).
- 문자열: 이 객체 몫은 [0x40ab656, 0x40aba88) 1074 B(`"sd"` 부터 `"sd%d"` 까지; 끝이 `sf_access` 몫 0x40aba88 과 맞닿음)로 보이고, 앞쪽 공용 문자열 일곱(0x40a6047 `"."`·0x40a6049 `"\n"`·0x40a62e7 `""`·0x40aa17b·0x40aa1b9·0x40aa548·0x40aa56f)은 다른 객체 것과 합쳐진 것으로 보임(A1 의 `__cstring` 과 대조해 정함).
- 구성: `_sd_sd` 0x40c5bf8–0x40c5e78 = 640 B = 8 × 80(`sdgetsdp` 가 첨자 × 80, 0x407c578–0x407c584) → `sd_sd[NSD+1]`(NeXTMach `scsiconf.c:43`)에서 NSD 7. 생성 `sd.h` 는 이미 `#define NSD 7`(구성 행 `hypothesis`, D138). `_sd_sdd` 는 다음 기호까지 1552 B(`sizeof(struct scsi_disk_drive)` 는 A1 이 잼).
- 1997 꼴로 이미 보인 것: `sdslave` 가 `sc_lunmask[target][lun]` 을 1 늘림(0x407c6a6 `addqb #1`; NeXTMach 281 행 `sc_lunmask[sd_target] |= 1 << sd_lun` 은 1997 2 차원 표(D149)에서 컴파일되지 않음); 장치 이름 출력이 `"%s Rev %s as "`(0x40ab659; NeXTMach 277 행 `"%s as "`).
- include: NeXTMach `#import` 36 줄(36–75 행; `sd.h` 는 생성 머리, `sys/callout.h` 는 `OD_SIMULATE` 아래) 중 스테이지에 없는 것은 선례대로 바꿈 — `next/psl.h`→`m68k/psl.h`, `next/cpu.h`→`m68k/cpu.h`(D110), `next/printf.h`→`kernserv/printf.h`, `next/eventc.h`→`machdep/m68k/eventc.h`(`clock.c:55`, plan 535), `nextdev/disk.h`→`dev/disk.h`, `nextdev/busvar.h`→`dev/busvar.h`, `nextdev/scsireg.h`→`dev/m68k/scsireg.h`, `nextdev/scsivar.h`→`dev/m68k/scsivar.h`(D113), `nextdev/insertmsg.h`→`kernserv/insertmsg.h`, `nextdev/voldev.h`→`dev/voldev.h`(둘 다 `fd_subr.c:46–47`, plan 570). `next/event_meter.h`·`next/kernel_pmon.h`·`nextdev/dma.h`·`nextdev/screg.h`·`nextdev/scvar.h` 는 07 사본이 스테이지에 있음. `nextdev/sdvar.h` 만 없음.

방법(진단; 07 은 바꾸지 않음; 원천 scratchpad `p658/gen_p658.py` 가 NeXTMach 글(SHA 단언)에서 만듦 → `08_build/artifacts/m4p658/src/`):
- 변형 A1: 위 include 바꿈 열, `DMA_ALIGN(` → `DMA_BEGINALIGN(`(2281–2282 행; sg 와 같은 까닭), `sdslave` 의 `sc_lunmask` 줄만 `sdp->sd_scp->sc_lunmask[sdp->sd_target][sdp->sd_lun]++;`(바이트 0x407c6a6 이 정한 꼴; 컴파일을 위한 최소 고침이기도 함). 그 밖은 NeXTMach 그대로. 바꾼 줄마다 `plan 658 diagnostic A1` 주석.
- 진단 머리(`inc`): `nextdev/sdvar.h`(NeXTMach 그대로의 사본). `sd.h` 는 스테이지 생성 머리.
- 컴파일이 안 되면: 오류를 적고, 원본 바이트가 꼴을 보이면 그 꼴로, 아니면 최소 고침으로 A1b 를 만들어 새 run ID 로 다시 돌립니다(고친 줄마다 근거를 적음).
- 명세 `08_build/artifacts/m4p658/spec.json`: 바탕 `08_build/runs/tools/m0p657-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `sd`, 명시 구간 `{"range": ["0x407c574", "0x407f3c4"], "rows": ["m68k-238", "m68k-239"], "partial": ["m68k-237", "m68k-240"], …}`(python 으로 `span()` 시험: 받아들임; 238 을 `partial` 에 두거나 240 을 빼면 멈춤), `x86_rel` `machdep/i386/dkbad.c`. run `m4p658-p1`(REGISTRY 에 없음), 기록 `m4-m68k-probe-p658-p1-20261031.json`, funcbytes `m4-m68k-funcbytes-p658-A1-20261031.json`(이름 없는 34 의 대응은 위 목록). 진단 run 은 `kr_run wait` 뒤 `collect` 없이 probe `compare`(§656.2).
- 측정: 종료 상태·경고, 함수별 길이·바이트·재배치 대상, 객체에만 있는 함수(`delay_biodone` 등)와 원본에만 있는 함수(`_sdsize`), 절 크기(`__text` 11856·`__data` 42·`__cstring` 목표), `__data` 를 재배치 풀어 원본 0x40b207c 와, `__cstring` 을 원본 몫과 내용으로, `sizeof(struct scsi_disk_drive)`·`sizeof(struct scsi_disk_volume)`(디버그 정보 또는 `-E` 없이 객체의 상수에서), COMMON·미정의가 원본 이름인지, bss 크기.
- 예상: 컴파일은 될 것(sg A1 과 같은 머리); 다른 함수가 여럿 나올 것(`sdslave` 의 출력 문자열, 새 `_sdsize` 와 그것을 부르는 곳, 1997 `kmem_alloc` 꼴 등). 몇 개가 같을지는 미리 정하지 않습니다.

판정(미리 정함; 07 은 바꾸지 않음): A1 결과를 기록하고, 다른 함수마다 원본 바이트를 읽어 바뀜을 적은 뒤 진단 B 계획(§659)을 세웁니다. 원본 바이트로 정해지지 않는 꼴이 나오면 구현 전에 여쭙니다. `sdvar.h` 의 1997 배치가 다르면(구조체 크기·칸 자리) 진단 B 전에 따로 조사합니다.

### 658.1 교차검토(codex `gpt-6.1-sol`, task k9b8w1q6v) 판정과 계획 수정

먼저 제 잘못: ① include 줄 수를 34 로 적었다가 python 으로 세어 36 으로 고쳤습니다(codex 에 보내기 전). ② `next/cpu.h` 를 "스테이지에 없는 것" 에 넣었으나 스테이지에 있습니다(`src/bsd/next/cpu.h` = 07 `nextmach/next/cpu.h`, D109 의 어셈블리 전용 사본); C 파일은 선례(D110)대로 `<m68k/cpu.h>` 로 씁니다. ③ A1 이 컴파일될 것이라 적었으나 `sdvar.h:27` 의 `<sys/time_stamp.h>` 가 스테이지에 없어 그대로는 멈춥니다. ④ `DMA_ALIGN` 자리를 둘로 적었으나 셋입니다(3032 행 더).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·42 항목(이름 8·없음 34)·대응·`_sd_sdsw`·`__data` 42 B 와 앞 16 B·문자열 1074 B·NSD 7·0x407c6a6 `addqb`·`"%s Rev %s as "` 가 맞음; `addqb` 는 1 늘림을 보일 뿐 `++` 철자는 아님 | 이번 세션 python(함수 표, Mach-O 에서 `_sd_sdsw`·앞 16 B·문자열), `sd.dis` | ✅ 철자는 바이트가 정하지 않음을 적음(sg·st 와 같은 처지) |
| `next/cpu.h` 는 스테이지에 있음 | 스테이지 매니페스트 python 조회 | ✅ 위 ② |
| `span()` 은 맞으나 실제 명세에 `basis` 를 넣을 것 | `m4_m68k_probe.py:159` | ✅ (계획의 `…` 자리; 명세에 씀) |
| `sdvar.h:27` `<sys/time_stamp.h>` 는 스테이지에 없음 → `kern/time_stamp.h`(선례 `fd_vars.h:28`) | 두 줄을 읽음 | ✅ 진단 사본에서 그 한 줄을 바꿈 |
| `DMA_ALIGN` 셋째 자리 `sd.c:3032` | grep: 2281·2282·3032 | ✅ 셋 모두 `DMA_BEGINALIGN(` |
| `kmem_alloc`(1916 행)은 컴파일은 되나 1997 꼴과 인자·반환이 다름(`vm_kern.h:66` 원형 없음, `vm_kern.c:199` 은 주소를 돌려받는 꼴) | 세 곳을 읽음 | ✅ A1 은 NeXTMach 그대로 두고 `sdioctl` 차이로 잼(B 에서 D150 꼴) |
| 다른 SCSI 칸·볼륨 API 막힘 없음, `EVENTMETER` 0, `OD_SIMULATE` 주석 처리 | `sdvar.h:30–31`(`#ifdef DEBUG` 안의 주석), 생성 `eventmeter.h` | ⚖️ 컴파일로 판정(사실관계는 읽은 곳까지 맞음) |
| funcbytes 는 이름 없는 원본 자료를 묶어야 다른 기호로 풀리지 않음 | `m68k_funcbytes.py:108–126`(`ADDR=_name` 이 범위 밖이면 자료 기준점 `dmap`) | ✅ `0x40b207c=_sd_vc_delay`·`0x40b2080=_sd_thread_init`·`0x40b2084=_sd_num_drives`·`0x40b2088=_sd_num_removables` 를 줌. bss 는 원본 기준점이 없으므로 첫 funcbytes 는 bss 참조가 다르게 나옴을 그대로 적고, A1 객체의 bss 배치가 원본 참조 26 주소와 한 기준으로 모두 맞을 때만 그 기준으로 둘째 funcbytes(`-A1m-`)를 돌림 |
| 1997 볼륨 구조체가 다름: 0x407e80a·0x407e82c `0xd6`(214 B), 라벨 원래 포인터 +206·맞춘 포인터 +210(0x407e85c–0x407e868); NeXTMach `sdvar.h:85` 는 포인터 하나 | `sd.dis` 0x407e802–0x407e8b6 를 읽음(`erp` +198 = `(sdvp+149)&-16`, `crp` +202 = `(sdvp+190)&-16`), `sdvar.h:80–86` | ✅ 측정에 A1 의 `sizeof(struct scsi_disk_volume)`·칸 자리와 원본 214·198·202·206·210 의 대조를 더함; 다르면 진단 B 전에 배치 조사(계획대로) |
| 공용 문자열 일곱은 116 B; bss 는 서로 다른 주소 26·명령 69 | python(116; 69·26, 0x40b4fde–0x40b507c) | ✅ 문구 고침 |
| 진단 관문을 따로 단언(`m4_m68k_probe.py:381`) | §656.1 에서 읽음 | ✅ `chk_p658.py` 가 `diag_gate` 둘을 단언 |

계획 수정: 진단 머리 `nextdev/sdvar.h` 는 NeXTMach 사본에서 27 행만 `<kern/time_stamp.h>` 로(진단 표시). 변형 A1 의 `DMA_ALIGN(` → `DMA_BEGINALIGN(` 은 세 자리. funcbytes 에 `__data` 기준점 넷. 측정에 볼륨 구조체 크기·칸 자리 대조. 컴파일이 다른 곳에서 멈추면 미리 정한 대로 A1b.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·돌린 python·풀이입니다.

### 658.2 결과 1(run `m4p658-p1`, 2026-10-31) — A1 컴파일 실패, A1b 로

- A1 컴파일 종료 1(경고 8), 의존 명령은 종료 0(`m4-m68k-probe-p658-p1-20261031.json`; 객체 없음). 오류: ① `sd.c:202` `extern void *kalloc(int size);` 가 스테이지 `kern/kalloc.h:58` `extern vm_offset_t kalloc(vm_size_t size);` 와 충돌 ② `DEV_BSIZE` 없음(486·805·825·2140 행) — 스테이지 `bsd/sys/param.h:219–224` 는 `#if NeXT` 이면 `DEV_BSIZE` 를 정의하지 않음(fd 단위 §570·§576 에서도 1997 글에 그 검사가 없었음). 경고: `kfree` 첫 인자 넷(410·2300·2301·2429 행, 포인터 → 정수), `checksum_16` 선언 형 둘(1872·2115 행).
- 미리 정한 대로 A1b(run `m4p658-p2`): A1 에서 ① 202 행을 진단 주석 한 줄로 바꿈(지움; 줄 수 그대로), ② include 뒤에 `#define DEV_BSIZE 512`(진단 전용 — 원본이 그 검사를 하는지는 다른 함수의 바이트로 B 에서 정함). 경고는 그대로 둠(진단). 그 밖·명세·측정은 §658·§658.1 과 같음(변형 이름 `A1B` — 이름 규칙 `^[A-Z][A-Z0-9]*$`(`m4_m68k_probe.py:70`) 때문에 대문자, 기록 `m4-m68k-probe-p658-p2-20261031.json`, funcbytes `-p658-A1B-`).

### 658.2 결과 2(run `m4p658-p2`, 변형 A1B, 2026-10-31)

먼저 제 잘못 셋: ① A1B 첫 실행에서 변형 이름 `A1b` 가 이름 규칙(`m4_m68k_probe.py:70`)에 걸려 스테이지 단계가 멈췄는데, 명령을 `;` 로 이어 둔 탓에 준비되지 않은 run 을 `kr_run wait` 가 기다렸습니다. 배경 작업을 멈췄고(run 디렉터리·REGISTRY 행·기록 없음, `LOCK` 없음 — `LOCK.owner` 는 `m4p658-p1` 이 설계대로 남긴 것, `kr_run.py:228`), 이름을 `A1B` 로 고쳐 `set -eo pipefail` 로 다시 돌렸습니다. ② 첫 funcbytes 가 static bss 기준점이 없어 멈춘 뒤, 객체의 bss 배치가 원본 참조 26 주소와 "한 기준으로 맞지 않는다" 고 판단했으나 틀렸습니다 — 첫 칸 오프셋만 견준 탓이고, 원본 0x40b507c 는 `sd_vc_bd` 통째 복사가 만든 `&sd_vc_bd + 42` 였습니다(A1B 도 `lea 0x3360` = 0x3336 + 42 같은 꼴). 다시 대 보니 기준 0x40b4fde(`sd_free_sv` 의 `sd_volume_p[...] = NULL`, 0x407e8d2)로 26 주소가 모두 A1B 배치 안에 맞습니다. ③ 그 사이 재배치 대상을 보지 않는 비교(scratchpad `p658/sd_cmp.py`, 기록 `m4-m68k-p658-A1B-maskedcmp-20261031.json`)를 따로 돌렸습니다 — 결과는 아래 funcbytes 와 같습니다.

- A1B 컴파일 종료 0, 경고 12(`kfree` 첫 인자 넷, `kalloc` 대입 넷(2262·2273·2368·2954 행), `checksum_16` 선언 넷), 의존 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p658-p2-20261031.json`). `__text` 11616 B(원본 11856), `__data` 42 B(원본과 같은 크기), `__cstring` 1335 B, `__bss` 158 B. `_sdsize` 없음. COMMON 은 공유 머리의 버퍼 이름들(D136 검사는 B 에서).
- funcbytes(함수 34·`__data` 넷·bss 아홉 기준점, `m4-m68k-funcbytes-p658-A1Bm-20261031.json`): **23/42 같음**. bss 기준점은 A1B 배치를 0x40b4fde 에 놓은 것: `sd_volume_p` +0(72 B = `NUM_SDVP` 18 × 4; 원본 +68 은 `sd_volume_p[SVC_VOLUME]`)·`sd_blk_major` +72·`sd_raw_major` +76·`sd_abort_q` +80·`sd_eject_q` +88·`sd_eject_freeq` +96·`sd_vc_event` +104·`sd_open_lock` +108·`sd_vc_bd` +116(42 B, 끝 +158).
- 길이 같고 바이트 다른 일곱(`sdstart`·`sd_err_info`·`sdwritelabel`·`sd_free_sv`·`sd_compare_vol`·`sd_copy_vol`·`sd_alert_panel`, 재배치 대상 차이 0)은 모두 하나의 1997 배치 차이: `sdv_dlp` 가 원본 +210, A1B +206; `sd_free_sv` 의 `kfree` 크기 0x1c58·0xd6(A1B 0x1c48·0xd2). 원본 `sd_new_sv`(0x407e802–0x407e8b6)는 볼륨 0xd6 = 214 B 를 받고, 라벨을 `kalloc(0x1c58)`(= `sizeof(struct disk_label)` 0x1c48 + 16) 해 그 원래 포인터를 +206 에, `(p + 15) & -16` 을 +210 에 두고 그 값으로 실패를 검사함. +206 을 쓰는 곳은 `sd_new_sv`(쓰기)와 `sd_free_sv`(`kfree`) 둘뿐. → 1997 `struct scsi_disk_volume` 는 `sdv_dlp` 앞에 포인터 칸 하나가 더 있음(이름은 바이트로 정해지지 않음).
- `struct scsi_disk_drive` 크기는 같음(194 B: 원본·A1B 모두 첨자 × (3·32 + 1) · 2, 0x407c5aa–0x407c5c0; 194 × 8 = 1552 = `_sd_sdd` 폭).
- 길이가 다른 열하나(§659.1 에서 "열넷" 을 고침)와 원본에만 있는 함수 하나: `sdslave` 694/664, `sdattach2` 510/480, `sdsetbratio` 254/302, `sdread` 138/128, `sdwrite` 136/126, `sdstrategy` 364/336, `sdintr` 1480/1452, `sdioctl` 1218/1134, `sdgetlabel` 348/318, `sdchecklabel` 154/192, `sd_new_sv` 182/170(위 배치), 그리고 원본에만 있는 `_sdsize` 64.

판정(미리 정한 대로): 07 은 바꾸지 않습니다. 1997 볼륨 배치가 다르므로, 진단 B 전에 길이가 다른 함수들과 `_sdsize` 를 원본 바이트로 읽어 바뀜을 모은 조사(§659)를 먼저 합니다.

## 659. M4-165 조사 결과와 세부 계획 — `sd.c` 진단 B(1997 바뀜 열하나; 07 변경 없음; 코딩 전, 2026-10-31)

조사(이번 세션; 원본 `sd.dis` 와 A1B 풀이 scratchpad `p658/sdA1B.dis` 를 `p658/fdiff658.py`(주소·상수를 기호로 바꾼 명령 diff)·`p658/ocalls.py`(호출 목록)·`p658/orng.py` 로 견줌). 바뀜마다 원본 자리:
- ① 볼륨 구조체(§658.2): `sdv_dlp` 앞에 포인터 칸 하나(+206, 이름은 바이트가 정하지 않음); `sd_new_sv` 는 `kalloc(sizeof(struct disk_label) + DMA_BEGINALIGNMENT)`(0x1c58)을 그 칸에, `DMA_BEGINALIGN` 한 값을 `sdv_dlp`(+210)에 두고 `sdv_dlp` 로 실패 검사(0x407e856–0x407e870); `sd_free_sv` 는 그 칸을 같은 크기로 `kfree`(0x407e8dc–0x407e8ea). 볼륨 214 B = NeXTMach 210 + 4.
- ② `sdslave`(0x407c602–0x407c620): inquiry 첫 바이트의 위 3 비트가 0 이 아니면 실패, 아래 5 비트가 0·4·5·7 이면 받아들임 — 1997 SDK `bsd/dev/scsireg.h:500–501` 의 `ir_qual:3, ir_devicetype:5` 와 `DEVTYPE_CDROM` 5·`DEVTYPE_OPTICAL` 7(`:589·591`)과 맞음(07 `nextmach/nextdev/scsireg.h:241` 은 `u_char ir_devicetype` 통째). 출력은 `ir_revision` 뒤(+36)를 0 으로 막고 `printf("%s Rev %s as ", ir_vendorid, ir_revision)`(0x407c670–0x407c688). SDK 판 `inquiry_reply` 와 NeXTMach 판은 크기 65 B·`ir_revision` +32 가 같음(python).
- ③ `sdattach2`: inquiry 형이 5(CDROM)이면 `sdv_flags |= SVF_WP`(`oriw #2048,+10`)하고 mode sense 를 건너뜀; mode sense 버퍼는 `kalloc(sizeof(struct mode_sel_data) + 16)`(0x4c; NeXTMach 0x3c)을 `(p + 15) & -16` 로 맞춰 씀; NeXTMach 의 `"\tUNABLE TO READ DISK LABEL\n"` 출력 없음(원본 문자열에 없음).
- ④ `sdsetbratio`: NeXTMach 의 `DEV_BSIZE` 검사 덩이(486–492 행) 없음(fd `fd_setbratio` 와 같은 1997 바뀜, §570).
- ⑤ `sdread`·`sdwrite`: 블록 크기는 live 파티션이거나 `!(sdv_flags & SVF_LABELVALID)` 이면 `sdv_crp->cr_blklen`, 아니면 `sdv_dlp->dl_secsize`(NeXTMach `DEV_BSIZE`).
- ⑥ 새 `sdsize(dev_t dev)`(0x407d0b8, 64 B): `sd_volume_p[SD_VOLUME(dev)]`, 볼륨 > 15 또는 NULL 이면 −1, 라벨 무효면 `sdv_crp->cr_blklen`, 아니면 `sdv_dlp->dl_secsize`. 자리는 `sdclose` 와 `sdread` 사이.
- ⑦ `sdstrategy`: `bp->b_sort_key = bno;` 뒤에 `if (!(bp->b_flags & B_READ) && (sdvp->sdv_flags & SVF_WP)) { bp->b_error = EROFS; goto bad; }`(0x407d25a–0x407d270).
- ⑧ `sdintr`: `"Target %d: %s ERROR; block %XH retry %d\n"` 의 `%s` 가 감지 키 3 이면 `"MEDIA"` 아니면 `"HARDWARE"`(0x407db96–0x407dbba) — NeXTMach `case SENSE_MEDIA:`(1469 행)에 `SENSE_HARDWARE` 가 함께 오는 꼴로 보임(점프 표가 다름); 호출 목록은 두 쪽이 같음.
- ⑨ `sdioctl`: 새 갈래 `DKIOCBLKSIZE`(`*(int *)data = sdv_crp->cr_blklen`, 0x407e328)·`DKIOCNUMBLKS`(`sdv_crp->cr_lastlba + 1`, 0x407e332)(스테이지 `dev/disk.h:126–127`; fd §576 의 새 `DKIOC*` 와 같은 처지); `kmem_alloc` → `kmem_alloc_wired`(호출 목록 대조; D150 꼴).
- ⑩ `sdgetlabel`: 블록 길이 0 이면 `printf("ERROR: Invalid device block length of zero\n")` 뒤 inquiry 형 5 이면 2048, 아니면 512(0x407e38a–0x407e3d4).
- ⑪ `sdchecklabel`: `"Bad disk label magic number"` 출력과 `DEV_BSIZE` 검사가 없음(0x407e5ec–0x407e66a).
- 바이트가 같은 23 함수와 `sd_vstart`·`sdstart`·`sddone` 등은 NeXTMach 그대로(① 의 칸 자리 차이만).

방법(진단; 07 은 바꾸지 않음; scratchpad `p658/gen_p659.py` 가 A1B 원천(SHA 단언)에서 만듦 → `08_build/artifacts/m4p659/`):
- 변형 B: A1B 에 ①–⑪. A1B 의 진단 고침 둘 중 `DEV_BSIZE` 정의는 뺌(④⑤⑪ 로 쓰는 곳이 없어짐을 컴파일로 확인), `kalloc` 선언 지움은 둠. 진단 머리: `nextdev/sdvar.h` 에 ① 의 칸(진단 이름 `sdv_dlp_alloc`), `dev/m68k/scsireg.h` 는 07 사본의 진단 사본에서 `struct inquiry_reply` 만 SDK 1997 큰 엔디언 꼴로, `DEVTYPE_CDROM`·`DEVTYPE_OPTICAL` 더함(이름은 SDK). 바뀐 줄마다 `plan 659 diagnostic B`.
- 경고(`kfree`·`kalloc` 형)는 B 에서는 그대로 두고 따로 셈(구현 전에 꼴을 정함).
- 명세 `08_build/artifacts/m4p659/spec.json`(바탕 `m0p657-a1-stage`, §658 의 명시 구간), run `m4p659-p1`(REGISTRY 확인), 기록 `m4-m68k-probe-p659-p1-20261031.json`, funcbytes `-p659-B-`(§658.2 의 함수·`__data`·bss 기준점; `sdsize` 는 이름 있음). 진단 run 은 `wait` 뒤 `collect` 없이 probe `compare`, 명령 사슬은 `set -eo pipefail`.
- 측정: §658 과 같음 + `__cstring` 을 원본 몫 1074 B 와 공용 일곱(116 B)으로 대조, 볼륨 `sizeof` 214.
- 예상: 바뀐 열하나가 같아지고, 남는 것이 있으면 `fdiff658.py` 로 다시 읽음.

판정(미리 정함; 07 은 바꾸지 않음): 42/42 이고 절·자료·문자열이 맞으면 구현 전에 바이트가 정하지 않는 꼴을 여쭙니다 — ① 칸 이름과 사본 머리에 둘지, ② `inquiry_reply` 1997 꼴을 공유 07 `scsireg.h` 에 넣을지(그러면 그 머리를 쓰는 받아들인 객체를 다시 받아들임) 파일 안에서 바이트를 직접 볼지, `DEVTYPE_*` 이름 자리, 경고 꼴. 남는 함수가 있으면 다음 진단에서 고칩니다.

### 659.1 교차검토(codex `gpt-6.1-sol`, task kdt9ubc6m) 판정과 계획 수정

먼저 제 잘못: ① §658.2 에 "길이가 다른 열넷" 이라 적었으나 열하나(+ 원본에만 있는 `_sdsize`)입니다(python: 42 − 23 − 7 = 12). 고쳤습니다. ② B 설계에서 진단 `scsireg.h` 사본은 스테이지 판에 가려집니다(아래). ③ 점프 표를 python 으로 처음 풀 때 항목을 2 B 로 읽어 틀린 값을 냈습니다 — objdump 풀이(4 B 절대 주소)로 판정했습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 진단 `-I` 는 기존 `-I` 뒤에 붙어(`m4_m68k_probe.py:222–224`) 진단 `scsireg.h` 사본이 가려짐; `sdvar.h` 는 스테이지에 없어 됨 | 그 줄과 `m4p658-p2/run.cmd` 의 `-I` 차례(`…-Isrc/src/m4probe/inc_sd_A1B` 맨 뒤) | ✅ B 는 머리 사본을 쓰지 않음(아래) |
| ①·② 가 맞음(0xd6, +206 원래·+210 맞춘 포인터, 실패 검사는 맞춘 값, 해제는 +206·0x1c58; `& 0xe0` 거부·0/4/5/7; +36 은 늘 지우고 출력은 조건부) | 이번 세션 `sd.dis` 0x407e802–0x407e8b6·0x407e8b8–0x407e8fe·0x407c602–0x407c688 | ✅ |
| ③ CDROM 이면 WP 뒤 mode sense 건너뜀; 아니면 WP 지우고 0x4c 를 받아 맞춘 포인터로 `sdmodesen(…, 0x3c)`, 원래 포인터를 0x4c 로 `kfree` | A1B diff(0x4c·0x3c·`(p+15)&-16`)와 원본 0x407c99e–0x407c9e4 | ✅ B 에 그대로 |
| ④–⑦ 이 맞음; `sdsize` 는 live 파티션 갈래 없음, 볼륨 포인터를 검사 전에 읽음; EROFS 는 일반 버퍼 길 안 | `sd.dis` 0x407d0b8–0x407d0f6·0x407d248–0x407d274 | ✅ |
| ⑧ 원본 점프 표(0x407dae2)에서 감지 키 3·4 가 같은 0x407db5c, A1B 는 4 가 default | objdump 풀이 0x407dae2–0x407daf2(키 0·1 0x407db52, 2 0x407db02, 3·4 0x407db5c, 5 0x407dc32, 6 0x407dbea) | ✅ `case SENSE_MEDIA:` 앞에 `case SENSE_HARDWARE:`(철자·차례는 바이트로 가려지지 않음) |
| ⑨ 할당은 세 인자 + 상태 검사(D150 꼴); ⑩ CDROM 2048 은 용량 읽기 성공 뒤 블록 길이 0 일 때만; ⑪ 마법 수 검사는 남고 출력만 빠짐 | 원본 0x407e370–0x407e3d4·0x407e5ec–0x407e66a, 호출 목록(`_kmem_alloc_wired`) | ✅ |
| 다른 차이 없음(SAME 23 의 재배치 196 모두 같음, `__data` 같음); 문자열 차이가 조사로 다 설명됨; B 의 `__cstring` 내용 합 1190 B(1074 + 116) | 이번 세션 문자열 집합 대조(원본에만 다섯·A1B 에만 열다섯 — 공용 일곱 포함), python 1074 + 116 | ✅ 196 은 B 의 funcbytes 로 다시 셈 |
| 경고를 두면 `diag_gate.commands_ok` 는 거짓; 판정에 컴파일 실패와 "42/42 이지만 함수 밖 검사 실패" 를 넣을 것 | `m4_m68k_probe.py:381` | ✅ |

계획 수정(B):
- ② 는 07 `scsireg.h` 를 바꾸지 않고, NeXTMach 의 통째 바이트 `ir_devicetype` 을 파일 안에서 `& 0xe0`(위 3 비트)·`& 0x1f`(형)로 봄; `DEVTYPE_CDROM` 5·`DEVTYPE_OPTICAL` 7 은 진단 파일 안 `#define`(SDK 이름). 머리를 1997 꼴로 바꾸는 꼴은 바이트가 같은지 따로 보지 않고, 구현 전에 여쭐 선택지로 둠(그 꼴을 고르면 그때 진단).
- 진단 머리는 `nextdev/sdvar.h` 하나(A1B 사본 + ① 의 칸, 진단 이름 `sdv_dlp_alloc`). `-M` 의존 목록에서 그 경로가 진단 사본인지 단언.
- 판정: 컴파일 실패면 원인을 적고 고친 꼴로 다시; 42/42 이고 절·`__data`(재배치 풀어)·`__cstring`(1190 B 내용과 원본 몫 차례)·COMMON·미정의·bss(158 B)·볼륨 214 B 가 모두 맞을 때만 구현 질문으로; 함수가 42/42 여도 함수 밖 검사가 하나라도 어긋나면 진단을 이어감. 경고 수는 따로 적고, 구현 전에 꼴을 정함.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·풀이·python 입니다.

### 659.2 결과(run `m4p659-p1`, 2026-10-31)

- B 컴파일 종료 0, 경고 11(`kfree` 첫 인자 넷, `kalloc` 대입 셋, `checksum_16` 선언 넷 — §660.1 에서 고침 — `kalloc`·`kfree` 형 경고는 구현 전에 꼴을 정함), 의존 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p659-p1-20261031.json`). `__text` 11856 B, 자리 0x407c574, `full_span`, `missing_names`·`extra_names` 빔. L1 은 `__TEXT,__text` 의 재배치 대상 여섯이 달라 NOT_MATCH.
- funcbytes(§658.2 기준점, `m4-m68k-funcbytes-p659-B-20261031.json`): **39/42**. 남은 셋은 길이가 같음(scratchpad `p658/sdB.dis` 를 `fdiff658.py` 로 견줌):
  - `sdattach2`: 원본은 `cmpib #5; beqs` 로 CDROM 일 때 먼 쪽(`oriw #2048`)으로 뛰고 가까운 쪽이 mode sense 갈래; B 는 반대(가까운 쪽이 `oriw`) — 같은 조건의 `if/else` 를 뒤집은 꼴(`!= DEVTYPE_CDROM` 이면 mode sense, 아니면 WP)로 보임. 재배치 대상 셋은 이 차례 차이로 생긴 문자열 참조 어긋남으로 보임(C 에서 확인).
  - `sdsize`: 원본은 `SVF_LABELVALID` 가 서면 먼 쪽(`sdv_dlp->dl_secsize`)으로 뛰고 가까운 쪽이 `cr_blklen`; B(`if (!(…)) return crp; return dlp;`)는 반대.
  - `sdgetlabel`: 원본은 첫머리에 `sdvp->sdv_sddp` 를 `%a4` 에 받아 두고(0x407e35c) CDROM 검사에서 `%a4@(178)` 를 씀; B 는 그 자리에서 `sdvp->sdv_sddp` 를 읽음 → 지역 `sd_drive_t sddp = sdvp->sdv_sddp;` 꼴로 보임. 그 밖 바이트는 같음.

판정(미리 정한 대로): 07 은 바꾸지 않고 남은 셋의 꼴을 다음 진단(§660)에서 가립니다.

## 660. M4-166 세부 계획 — `sd.c` 진단 C1–C3(갈래 차례 둘과 지역 변수; 07 변경 없음; 코딩 전, 2026-10-31)

변형(모두 B 원천에서 세 함수만 바꿈; 머리·명세·측정은 §659 와 같음, 진단 머리 `incB`):
- 공통: `sdattach2` 를 `if((sddp->sdd_irp->ir_devicetype & 0x1f) != DEVTYPE_CDROM) { …mode sense… } else sdvp->sdv_flags |= SVF_WP;` 로(조건·갈래만 뒤집음); `sdgetlabel` 에 지역 `sd_drive_t sddp = sdvp->sdv_sddp;`(선언 첫 자리) 두고 CDROM 검사에서 `sddp->sdd_irp` 를 씀(다른 `sdvp->sdv_sddp->…` 줄은 그대로).
- `sdsize` 꼴만 다름: C1 `if (sdvp->sdv_flags & SVF_LABELVALID) return(dlp->dl_secsize); return(crp->cr_blklen);` · C2 `return((sdvp->sdv_flags & SVF_LABELVALID) ? … : …);` · C3 지역 `int blocksize;` 에 `if (!(…LABELVALID)) blocksize = crp…; else blocksize = dlp…;` 뒤 `return(blocksize);`(`sdread` 와 같은 꼴).
- 생성 scratchpad `p658/gen_p660.py`(B 원천 SHA 단언, 바꿀 글 정확히 한 번) → `08_build/artifacts/m4p660/`. run `m4p660-p1`(REGISTRY 확인), 기록 `m4-m68k-probe-p660-p1-20261031.json`, funcbytes `-p660-<변형>-`. 진단 run 은 `wait` 뒤 `collect` 없이 `compare`, `set -eo pipefail`.
- 측정: §659.1 의 판정 항목 전부(42/42, `__data` 재배치 풀어, `__cstring` 1190 B 내용·원본 몫 차례, COMMON·미정의 원본 이름, bss 158 B, 볼륨 214 B, `-M` 에서 `sdvar.h` 가 진단 사본) — 단언 scratchpad `p658/chk_p660.py`.

판정(미리 정함): 42/42 이고 함수 밖 단언이 모두 맞는 변형이 있으면, 바이트로 가려지지 않는 꼴(§659 의 질문들 + `sdsize` 꼴이 둘 이상 맞으면 그 선택)을 구현 전에 여쭙니다. 아니면 원인을 적고 다음 꼴을 계획합니다.

### 660.1 교차검토(codex `gpt-6.1-sol`, task ktmcgpi27) 판정과 계획 수정

먼저 제 잘못: §659.2 의 경고 내역을 "`kfree` 다섯" 으로 적었으나 넷입니다(python 으로 B stderr 를 셈: 경고 줄 11 = `kfree` 4 + 대입 3 + `checksum_16` 관련 4). 고쳤습니다. 또 `sdattach2` 의 재배치 대상 차이를 "문자열 참조 어긋남" 으로 짐작했으나 호출 셋(`kalloc`·`sdmodesen`·`kfree`)입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `sdattach2`·`sdsize`·`sdgetlabel` 진단이 맞음; 원본 `sdgetlabel` 은 0x407e35c 에서 `%a4` 에 받고 0x407e3a0 에서 씀, 0x407e40a 부터 `%a4` 를 다시 씀 | 이번 세션 `sd.dis`·`p658/sdB.dis` 대조(§659.2 의 diff) | ✅ |
| 다른 재배치 대상 여섯은 갈래가 옮겨져 자리가 어긋난 것(`sdattach2` 호출 셋, `sdgetlabel` 은 `sdreadcapacity`·문자열·`printf`) | funcbytes 기록의 `refs_differ`: 원본 쪽이 모두 `_traptrace` + 큰 오프셋(같은 자리에 재배치가 없음) | ✅ C 의 funcbytes 로 다시 봄 |
| B 의 경고 내역은 4·3·4 | python 셈 | ✅ 위 |
| `sdsize` 는 C3(`sdread` 와 같은 대입 꼴)이 가장 가까운 선례, C1 도 근거 있음, C2 는 예측 어려움 | B 의 `sdread`(같은 갈래 차례가 원본과 같음, 39/42 안) | ⏭️ run 이 판정 |
| 판정에 `full_span`·빠진/더한 함수 없음·텍스트 재배치 대상 차이 0 을 명시; 공통 바뀜이 실패해도 함수별 결과를 적음; 경고를 고치면 다시 바이트 비교 | 계획 문구 | ✅ `chk_p660.py` 에 넣음 |

계획은 그대로 C1–C3 을 돌립니다.

2차 자기검사: ✅ 행은 이번 세션의 대조·python 셈입니다.

### 660.2 결과(run `m4p660-p1`, 2026-10-31)

- 명령 6 개 종료 0, 컴파일마다 경고 11(B 와 같은 내역), 의존 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p660-p1-20261031.json`).
- funcbytes(`-p660-C1/C2/C3-`): C1·C3 **41/42**, C2 40/42. `sdattach2` 는 셋 모두 같아짐(뒤집은 `if/else`). `sdsize` 는 C1(조건이 참이면 먼저 돌려줌)·C3(지역 `blocksize` 대입) 같음, C2(삼항)는 다름.
- `sdgetlabel` 은 셋 모두 6 바이트 다름(재배치 대상 차이 0): 원본은 `lea %fp@(-162),%a3`(`c10p = &sr.sr_cdb.cdb_c10`) 다음에 `moveal %a2@,%a4`(`sddp = sdvp->sdv_sddp`), C 는 그 둘이 뒤바뀜 — `sddp` 선언을 첫 자리에 둔 탓으로, `c10p` 선언 뒤에 두면 원본 차례가 될 것으로 보임.
- 42/42 가 아니므로 함수 밖 단언은 다음 진단에서 돌립니다(미리 정한 판정대로).

## 661. M4-167 세부 계획 — `sd.c` 진단 D1·D2(`sdgetlabel` 의 `sddp` 선언 자리; 07 변경 없음; 코딩 전, 2026-10-31)

변형(모두 C1 에서 `sdgetlabel` 의 `sd_drive_t sddp = sdvp->sdv_sddp;` 한 줄의 자리만 옮김; `sdsize` 는 C1 꼴, C3 꼴과는 바이트로 가려지지 않으므로 구현 전 질문에 둠): D1 `struct cdb_10 *c10p = …;` 바로 뒤, D2 `int tries, error, nblk;` 뒤. 생성 scratchpad `p658/gen_p661.py`(C1 원천 SHA 단언) → `08_build/artifacts/m4p661/`, run `m4p661-p1`, 기록 `m4-m68k-probe-p661-p1-20261031.json`, funcbytes `-p661-D1/D2-`. 42/42 인 변형에 §659.1·§660.1 의 함수 밖 단언 전부(scratchpad `p658/chk_p661.py`: `full_span`·빠진/더한 함수 없음·텍스트 재배치 대상 차이 0, `__data` 42 B 를 재배치 풀어 원본 0x40b207c 와, `__cstring` 내용 1190 B 를 원본 몫 1074 B(차례까지)와 공용 일곱 116 B 로, COMMON·미정의가 원본 이름, bss 158 B, 볼륨 214 B(객체의 `kalloc(0xd6)`), `-M` 의존 목록에서 `nextdev/sdvar.h` 가 진단 사본, i386 0)을 돌립니다.

판정(미리 정함): 42/42 이고 단언이 모두 맞으면 구현 전에 바이트로 가려지지 않는 꼴을 여쭙니다(§659 의 칸 이름·`inquiry_reply` 자리·`DEVTYPE_*`, `sdsize` C1/C3, `sddp` 자리 D1/D2 가 둘 다 맞으면 그것도, 경고 꼴). 아니면 원인을 적고 다음 꼴을 계획합니다.

### 661.1 교차검토(codex `gpt-6.1-sol`, 동기 회신) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `sdgetlabel` 의 차이는 원본 `47ee ff5e 2852`(`lea` 다음 `moveal`) 대 C1 `2852 47ee ff5e` 뿐, 재배치 여섯은 같은 대상 | 원본 0x407e348–0x407e360 풀이(scratch `p658/orng.py`), §660.2 의 C1 diff | ✅ |
| D1·D2 는 같은 바이트일 수 있음; 대안 D3 = `sd_drive_t sddp;` 선언 뒤 첫 문장으로 `sddp = sdvp->sdv_sddp;` | — | ✅ D3 을 더함(run 이 판정) |
| 함수 밖 단언에 더할 것: 절 목록(넷뿐)·크기, 비디버그 기호의 묶임·절·자리(`_sd_sdsw` 는 `__data`+16 외부, bss 기준점 아홉의 자리), COMMON 의 크기, 재배치 전수(`__data` 6, `__cstring`·`__bss` 0), STABS 제외 | C1 객체를 python 으로 읽음: `__text` 11856(재배치 457)·`__data` 42(6)·`__cstring` 1190(0)·`__bss` 158(0); 지역 `__data` 넷 +0·+4·+8·+12, `_sd_sdsw` +16 외부, bss 아홉 +0…+116; COMMON 14(공유 머리의 버퍼·tty 이름) | ⚖️ 모두 단언에 넣되, COMMON 크기는 원본에 객체별 크기가 없으므로 "원본 기호 간격 이하" 로만 봄 |

계획 수정: 변형 D3 을 더함. `chk_p661.py` 단언에 위 항목을 더함.

2차 자기검사: ✅ 행은 이번 세션의 풀이·python 입니다.

### 661.2 결과(run `m4p661-p1`, 2026-10-31)

- 명령 6 개 종료 0, 컴파일마다 경고 11(B 와 같은 내역; 그래서 `diag_gate.commands_ok` 거짓), 의존 i386 0, 원본에 없는 미정의 0, M5 줄과 선택지 차이 없음(`m4-m68k-probe-p661-p1-20261031.json`).
- **D1·D2·D3 모두 funcbytes 42/42**(`-p661-D1/D2/D3-`; 재배치 대상 차이 0, 객체에만 있는 함수 없음). 셋은 canon·`obj_sig` 가 서로 같음 — `sddp` 의 선언 자리(`c10p` 뒤·`int` 줄 뒤·선언 뒤 대입)는 바이트로 가려지지 않음.
- L1: 자리 0x407c574, `full_span`, 빠진/더한 이름 없음, 사유는 `__DATA,__bss: unverified` 하나(`judgement` `provisional`) — 받아들이면 다른 정적 bss 객체처럼 CODE+BSS_INFERRED(zerofill 기록, D113 꼴).
- 함수 밖 단언(scratch `p658/chk_p661.py`; 기록 `m4-m68k-p661-diagchecks-20261031.json`, 셋 모두 `ok`): 절은 `__text` 11856(재배치 457)·`__data` 42(6)·`__cstring` 1190(0)·`__bss` 158(0) 넷뿐; `__data` 는 재배치 여섯(`"sd"` 와 정적 함수 다섯)을 풀면 원본 0x40b207c 의 42 B 와 같음; `__cstring` 은 원본 몫 1074 B 의 문자열이 차례까지 같고 나머지가 공용 일곱(116 B)과 같음; 바깥 정의 아홉(`_sd_sdsw` `__data`+16 = 0x40b208c 와 함수 여덟)이 원본 자리; 지역 기호 `__text` 34 가 원본 항목 시작, `__data` 넷이 +0·+4·+8·+12, `__bss` 아홉이 §658.2 기준점; COMMON 14(공유 머리의 버퍼·tty 이름) 모두 원본 이름이고 크기가 원본 기호 간격 이하; 미정의 모두 원본 이름; 의존 목록의 `nextdev/sdvar.h` 는 진단 사본(`m4p659/incB`), i386 0. 볼륨 214 B·라벨 0x1c58 은 `sd_new_sv`·`sd_free_sv` 바이트가 같음으로 확인.
- (제 잘못: 단언 스크립트에 지역 함수 수를 33 으로 넣어 첫 실행이 거짓 — 42 − 외부 8 = 34 로 고쳐 다시 돌림.)

판정(미리 정한 대로): 바이트로 가려지지 않는 꼴을 구현 전에 여쭙니다.

## 662. M4-168 사용자 결정(D153 으로 적을 것)과 세부 계획 — `sd.c` 진단 E(공유 `scsireg.h` 의 1997 `inquiry_reply`; 07 변경 없음; 코딩 전, 2026-10-31)

사용자 결정(AskUserQuestion, 다섯): ① 볼륨 구조체의 새 칸은 `sdv_dlp_alloc`(`caddr_t`, 07 `nextmach/nextdev/sdvar.h` 사본; 추천안) ② inquiry 첫 바이트는 "공유 scsireg.h 를 1997 꼴로"(추천안 "파일 안 마스크" 가 아님): 07 `nextmach/nextdev/scsireg.h` 의 `struct inquiry_reply` 를 SDK 1997 꼴(`ir_qual:3, ir_devicetype:5` …, 크기 65 B 같음)로, `DEVTYPE_*` 도 그 머리에 ③ 경고 11 줄은 "1990 글 그대로 + known_warnings"(D121·D123 선례; 추천안) ④ `sdsize` 는 지역 `blocksize` 대입 꼴(C3; 추천안) ⑤ `sdgetlabel` 의 `sddp` 는 `c10p` 선언 바로 뒤(D1; 추천안).

확인한 사실(이번 세션): 07 `nextmach/nextdev/scsireg.h`(462 행, NeXTMach 그대로, PROVENANCE 1127 행; 스테이지 `src/bsd/dev/m68k/scsireg.h`)는 가드 `_SCSIREG_`(23·462 행). 이를 들이는 07 원천은 `autoconf.c:52`·`sg.c:64`(그리고 의존 목록으로 `st`); 받아들인 객체 중 의존 목록에 이 머리가 든 것은 `autoconf`(p649)·`st`(p652)·`sg`(p655). `inquiry_reply` 칸을 쓰는 07 원천은 없고 `stvar.h:22·45` 가 포인터와 `sizeof` 만 씀(65 B 그대로). `DEVTYPE_READONLY`·`DEVTYPE_NOTPRESENT` 를 쓰는 07 원천 없음(grep 0).

머리 바꿈의 꼴(구현에서 쓸 것, 진단 사본에 먼저): `struct inquiry_reply` 를 SDK `bsd/dev/scsireg.h:500–533`(496 행 `typedef struct inquiry_reply {`, 498 행 `#if __BIG_ENDIAN__`)의 칸 차례 그대로(이 07 사본은 m68k 에만 스테이징되므로 `#if` 없이), 이름은 `struct inquiry_reply`(SDK 의 `typedef … inquiry_reply_t` 는 더하지 않음 — 쓰는 곳 없음); `DEVTYPE_CDROM 0x05`·`DEVTYPE_OPTICAL 0x07` 두 줄을 더함(SDK `:589·591`; 기존 NeXTMach 줄은 둠 — 바이트가 요구하는 것만). 바꾼 줄마다 표시.

방법(진단; 07 은 바꾸지 않음; scratch `p658/gen_p662.py` → `08_build/artifacts/m4p662/`):
- 진단 머리: `diag662/scsireg.h` = 07 사본 + 위 바꿈(다른 경로라 스테이지 판에 가려지지 않음; 가드가 같아 스테이지 판이 뒤에 들어와도 빈 꼴).
- 변형 E1: D1 원천 + ④(C3 꼴 `sdsize`) + `#import <dev/m68k/scsireg.h>` 를 `#import <diag662/scsireg.h>` 로 + 파일 안 `DEVTYPE_*` `#define` 둘을 지우고, 검사를 비트필드로 — `sdslave` `if (error || irp->ir_qual || ((irp->ir_devicetype != DEVTYPE_DISK) && (… != DEVTYPE_WORM) && (… != DEVTYPE_CDROM) && (… != DEVTYPE_OPTICAL)))`, `sdattach2`·`sdgetlabel` `(… ->sdd_irp->ir_devicetype != / == DEVTYPE_CDROM)`.
- run `m4p662-p1`(REGISTRY 확인; `wait` 뒤 `collect` 없이 `compare`, `set -eo pipefail`), 기록 `m4-m68k-probe-p662-p1-20261031.json`, funcbytes `-p662-E1-`, 단언 `chk_p661.py`(E1 판: `sdvar_from` 은 `incB`, 더해 의존 목록에서 `diag662/scsireg.h` 가 쓰였음) → `m4-m68k-p662-diagchecks-20261031.json`. `-E` 를 따로 돌리지 않고, 비트필드 꼴이 쓰였음은 바이트 판정(42/42)과 의존 목록으로 봄.

판정(미리 정함): E1 이 42/42 이고 단언이 맞으면 구현 계획(§663: 07 `scsireg.h` 바꿈과 `autoconf`·`st`·`sg` 다시 받아들이기, `sd.c`·`sdvar.h` 사본, 구성 행 `sd` 의 `hypothesis` → `confirmed`(`_sd_sd` 640 B = 8 × 80), CODE+BSS_INFERRED zerofill)을 세웁니다. 비트필드 꼴이 다른 바이트를 내면 원인을 적고, 머리 꼴을 지키면서 맞는 꼴을 찾되 못 찾으면 여쭙니다.

### 662.1 교차검토(codex `gpt-6.1-sol`, task kava79vl6) 판정과 계획 수정

먼저 제 잘못(중대): §662 의 "`inquiry_reply` 칸을 쓰는 07 원천은 없음" 은 틀렸습니다. 07 `st.c:235` 가 `irp->ir_devicetype != DEVTYPE_TAPE` 를, 241–246 행이 `ir_revision`·`ir_vendorid` 를 씁니다. 그 grep 은 UTF-8 로케일에서 `st.c`(확장 ASCII 바이트가 있음, `file` 결과 "Non-ISO extended-ASCII")를 이진으로 보고 아무것도 내지 않았습니다(`grep -a`·python 으로는 찾힘). 이 잘못된 사실 위에서 사용자께 머리 자리를 여쭈었으므로, 결정에 필요한 사실(아래)을 갖춘 뒤 다시 여쭙니다. 이번 단위의 다른 "없음" 주장은 python 으로 07 전체를 다시 훑어 확인함: `DEVTYPE_READONLY`·`DEVTYPE_NOTPRESENT` 사용 0, `scsireg.h` 를 들이는 m68k 원천은 `autoconf.c:52`·`st.c:91`·`sg.c:64`(그 밖은 x86 의 다른 머리), m68k 에서 `inquiry_reply` 칸을 쓰는 곳은 `st.c` 뿐, `sd.h` 를 들이는 것은 `swapgeneric.c:91` 뿐.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 진단 경로(`diag662/scsireg.h`)는 스테이지 판에 가려지지 않음; `sd.c` 의 scsireg import 앞에 그 머리를 들이는 스테이지 머리 없음; 같은 가드라 먼저 들어온 정의가 이김 | `m4_m68k_probe.py:218–224`, python 으로 07 의 import 전수 조사(위) | ✅ 가드 동작은 E1 이 `ir_qual` 로 컴파일되는 것으로 확인됨(경로만으로 `#import` 동일성을 단정하지 않음) |
| SDK 칸 차례·태그·상수가 맞고 크기 65·vendor/product/revision 자리 같음; 사라지거나 바뀌는 칸 `ir_zero1`·`ir_zero2`·`ir_zero3[3]`·`ir_revision[32]`(→ `[4]` + `ir_misc[28]`) | SDK 496–533 행, python 셈(§659 에서 65·+32) | ✅ |
| `st.c:235` 가 `ir_devicetype` 을 견주고 244 행이 `ir_revision[4]` 를 씀; 원본은 첫 바이트 통째를 1 과 견줌 | `st.c` 230–246 행, 원본 `st.dis` 0x40884b8 `cmpib #1,%a2@` | ✅ 위 잘못. 1997 꼴 머리에서는 `st.c:235` 를 바꿔야 원본과 같을 것 |
| 새 선언에서 `ir_revision[4]` 는 형식상 범위 밖(주소는 `ir_misc[0]`) | SDK `ir_revision[4]` | ✅ `st.c:244`·`sd.c` 의 같은 줄 — 바이트는 같으나 글을 정할 때 고려(질문에 넣음) |
| 다시 받아들일 것은 `autoconf`(649)·`st`(652)·`sg`(655); M5 205 와 x86 은 회귀로 확인 | 의존 목록 조사(이번 세션 python, §662 의 최종 기록 셋) | ✅ |
| `compare` 는 `refs` 없이 실패하지 않으므로 단언이 필요; 공유 머리 관문(소비 객체 재수락·회귀)을 판정에 넣을 것 | `m4_m68k_probe.py:381` | ✅ |

계획 수정(진단 E; 07 은 바꾸지 않음): 같은 run 에 객체 둘 — `sd`(E1, §662 그대로)와 `st`(§652 명시 구간, `x86_rel` 같음): S0 = 07 `st.c` 에서 scsireg import 만 `diag662` 로(바꾸지 않으면 달라짐을 보이는 대조), S1 = S0 + `if (error || irp->ir_qual || irp->ir_devicetype != DEVTYPE_TAPE)`(위 3 비트까지 보는 1997 SDK 꼴 — GCC 가 같은 바이트의 두 비트필드 비교를 한 바이트 비교로 합칠지 봄), S2 = S0 + `if (error || *(u_char *)irp != DEVTYPE_TAPE)`. funcbytes 는 §652 기록의 대응(`m4-m68k-funcbytes-p652-a1-20261031.json` 의 `mapping`)으로. 판정: E1 42/42·단언 `ok` 이고 S1 또는 S2 가 26/26 이면, 사실(머리 바꿈이 `st.c` 의 받아들인 글을 바꾸게 함, 맞는 꼴)을 갖춰 머리 자리 결정을 다시 여쭙니다(선택지: 공유 머리 1997 꼴 + `st.c` 고침 / 파일 안 마스크로 되돌림). 둘 다 아니면 그 사실로 여쭙니다.

### 662.2 결과(run `m4p662-p1`, 2026-10-31)

- 명령 8 개 종료 0; `sd` E1 경고 11(같은 내역), `st` S0–S2 경고 0; 의존 i386 0; 의존 목록에서 `scsireg.h` 는 진단 사본(`m4p662/incE/diag662/scsireg.h`)만 — 스테이지 판은 들어오지 않음(`m4-m68k-probe-p662-p1-20261031.json`).
- `sd` E1(1997 비트필드 꼴 `irp->ir_qual`·`irp->ir_devicetype`, `sdsize` C3, `sddp` D1): **funcbytes 42/42**, 함수 밖 단언 `ok`(`chk_p661.py`; 두 객체 run 이라 `options` 단언을 "`sd` 항목 차이 없음" 으로 고침 — D1 기록으로 다시 돌려 그대로 `ok`).
- `st`(§652 명시 구간, §652 funcbytes 의 대응): S0(07 `st.c` 그대로, 머리만 1997 꼴) **25/26** — `stslave` 가 250 B(원본 244)로 달라짐 → 머리를 바꾸면 `st.c:235` 를 고쳐야 함. S1(`irp->ir_qual || irp->ir_devicetype != DEVTYPE_TAPE`)·S2(`*(u_char *)irp != DEVTYPE_TAPE`) 모두 **26/26**, 둘은 canon·`obj_sig` 까지 같고, 받아들인 §652 객체(`m4p652-a1` F)와 canon 이 같음(`obj_sig` 는 디버그 정보의 형·경로 때문에 다름). GCC 가 같은 바이트의 두 비트필드 비교를 원본처럼 한 바이트 `cmpib #1` 로 합침.
- 기록 `m4-m68k-p662-diagchecks-20261031.json`(`ok`).

판정(§662.1 에서 정한 대로): 사실을 갖춰 머리 자리 결정을 다시 여쭙니다 — 공유 머리를 1997 꼴로 하면 받아들인 `st.c` 의 235 행이 바뀌고(S1 또는 S2), `autoconf`·`st`·`sg` 를 다시 받아들여야 하며, `ir_revision[4]` 쓰기(`st.c:244`, `sd.c` 같은 줄)는 새 선언에서 형식상 배열 밖(바이트는 같음).

## 663. M4-169 D153 구현 계획 — 공유 07 `scsireg.h` 1997 `inquiry_reply`, `st.c` 한 줄, `sd.c`·`sdvar.h` 사본, `autoconf`·`st`·`sg` 다시 받아들이기(코딩 전, 2026-10-31)

사용자 결정(다시 여쭌 답, D153 에 적을 것; §662 의 ①③④⑤ 는 그대로): ② 공유 07 `nextmach/nextdev/scsireg.h` 를 1997 꼴로 하고 `st.c:235` 를 고침(추천안 "파일 안 마스크" 가 아님; 이번에는 `st.c` 가 그 칸을 쓴다는 사실과 진단 결과를 알린 뒤의 답) ⑥ `st.c:235` 는 S1 `if (error || irp->ir_qual || irp->ir_devicetype != DEVTYPE_TAPE)`(추천안) ⑦ `irp->ir_revision[4] = '\0'` 는 그대로(`st.c:244`·`sd.c`; 추천안). 바이트가 정한 것: §658–§662 의 1997 바뀜, NSD 7(`_sd_sd` 640 B = 8 × 80).

1. 07 머리 `nextmach/nextdev/scsireg.h`(scratch `p663/gen_p663h.py --write`; 바꾸기 전 SHA `d0b16295…` 단언): `struct inquiry_reply` 몸통을 SDK `bsd/dev/scsireg.h:500–533` 그대로, `DEVTYPE_READONLY` 뒤에 `DEVTYPE_CDROM 0x05`·`DEVTYPE_OPTICAL 0x07` — 진단 사본 `m4p662/incE/diag662/scsireg.h` 와 바뀐 자리·내용이 같고 표시만 `plan 663 (D153)`(python 으로 표시를 뺀 토큰이 같음을 단언).
2. 07 `st.c`: 235 행만 S1 꼴(표시 `plan 663 (D153)`), latin-1 바이트 그대로 다른 줄 같음 단언; 머리 주석 덩이에 한 줄(1997 `inquiry_reply` 와 이 줄).
3. 07 `nextmach/nextdev/sdvar.h`: NeXTMach 사본에서 27 행 `<sys/time_stamp.h>` → `<kern/time_stamp.h>`(D104, `fd_vars.h:28` 선례) 와 `sdv_dlp_alloc` 칸(D153, 표시); 진단 `m4p659/incB` 사본과 토큰이 같음 단언.
4. 07 `src/machdep/m68k/sd.c`(scratch `p663/gen_p663.py --write`): NeXTMach `sd.c`(SHA `464fdb80…`) + 머리 주석 덩이(바뀜 목록, 바이트가 정하지 않은 꼴은 이 프로젝트의 선택이라고) + include 열(OPENSTEP 경로, D104/D110/D113; `scsireg.h` 는 `<dev/m68k/scsireg.h>`) + §658–§662 의 1997 바뀜(표시 `plan 663`), `extern void *kalloc(int size);` 지움, `DEV_BSIZE` 정의 없음, `DEVTYPE_*` 파일 안 정의 없음. 단언: 진단 E1 과 토큰이 같음(그 import 한 줄만 `diag662/` ↔ `dev/m68k/`); L(주석 지운 꼴, `08_build/artifacts/m4p663/src/sd_L.c`)과 F 의 토큰·토큰 줄 같음; 표시 없는 바뀐 줄 0.
5. 구성: `config_options-m68k.tsv` 의 `sd NSD` 행 `hypothesis` → `confirmed`(근거에 plan 658: `_sd_sd` 640 B = 8 × 80, `sdgetsdp` × 80); 생성 `sd.h` 는 그대로(`#define NSD 7`) — `gen_config_headers.py --check`(x86·m68k) 종료 0.
6. `stage_m68k.py`: `M4FILES[663] = list(M4FILES[657]) + ['sd.c']`, `M4HEADERS[663] = list(M4HEADERS[655]) + [('nextdev/sdvar.h', 'src/bsd/nextdev/sdvar.h')]`, `EXCEPTS[663] = dict(EXCEPTS[657])`, 머리말 목록.
7. 회귀: `--plan 657` 재생성(`m0p657-r663-stage`)은 보관 `m0p657-a1-stage` 와 `src/bsd/dev/m68k/scsireg.h`·`src/machdep/m68k/st.c` 해시 둘만 다름(키 `files`); 새 `m0p663-a1-stage` 는 그것과 `sd.c`·`sdvar.h`(키 `files`·`m4_headers`·`m4_sources`·`plan`)만 다름, 트리 어긋남 0. `m5-657.cmd` 는 보관본과 같고 `m5-663.cmd` 는 계획 번호만 다름. M5 205(run `m3p663-b657` 은 `--plan 657 compare`, `m3p663-cc1` 은 `--plan 663 compare`): 객체·출력 같음, `differ_unexpected`·`lost` 빔. x86 `m4_x86_inputs.py s6ln`(`L2_FORMS`·`L2_EXPECT` s6p398) `ok`·`--plan 663 x86gate` 일곱 같음.
8. 확인 run `m4p663-p1`(명세 `08_build/artifacts/m4p663/confirm/spec.json`, 바탕 `m0p663-a1-stage`): 객체 넷 — `autoconf`(F = 07, L = `m4p526/src/autoconf_L.c`), `st`(F, L = 새 `m4p663/src/st_L.c` = 07 `st.c` 의 주석을 지운 꼴), `sg`(F, L = `m4p655/src/sg_L.c`), `sd`(F, L). 판정: 종료 0·i386 0, 경고는 `sd` 11 줄(진단 E1 과 같은 글)·나머지 0; funcbytes 각 26/26·14/14·42/42(`autoconf` 는 §649 처럼 L1 사유 `__DATA,__bss: unverified` 하나·`full_span`); F = L(canon·`obj_sig`); `autoconf`·`st`·`sg` 의 F 는 받아들인 앞 객체(§649·§652·§655)와 canon 같음(`obj_sig` 는 디버그 형이 바뀌어 다를 수 있음 — 다르면 STABS 만 다름을 python 으로 보임). `-E` run `m4p663-e2`(`sd` F·L·E1, `st` F·L·S1; `EXPECT` 줄; `collect` 뒤 `out/_log`): 토큰 F = L = 진단(진단 쪽은 그 import 한 줄을 바꿔 견줌), stderr 는 `sd` 경고만, i386 0. `sd` 의 함수 밖 단언 `chk_p661.py`(F).
9. 최종 run 둘(같은 바탕): `m4p663-a1`(명세 `08_build/artifacts/m4p663/spec.json`, `st`·`sg`, `refs` = p1 L) → OBJECT_MATCH 둘; `m4p664-a1`(명세 `08_build/artifacts/m4p664/spec.json`, `autoconf`·`sd`, `refs` = p1 L, `bss_inferred` 둘, `known_warnings` 는 `sd` 컴파일의 stderr 11 줄 + "In function" 줄 그대로) → 둘 다 `provisional`. zerofill `objs`(기록 `m4-m68k-zerofill-p664-20261031.json`, 출력 디렉터리 `08_build/artifacts/m4p664/zerofill` — 절대 경로 금지): `autoconf:<최종>:<§649 객체>`·`sd:<최종>:<p1 L>`, 둘 다 `reference-inferred(-single)`, 후보 겹침 없음, `autoconf` 후보는 §649 와 같음, `sd` 후보는 [0x40b4fde, 0x40b507c) 를 덮음.
10. 상태: `ACCEPTED` 의 §649(autoconf)·§652(st)·§655(sg) 줄을 §663·§664 줄로 바꾸고 `sd` 를 더함; 근거 문서(`m68k-sd.md` 새, `m68k-sd.diff`·`m68k-sdvar_h.diff`·`m68k-scsireg_h.diff` 새, `m68k-st.md`·`m68k-sg.md`·`m68k-autoconf.md` 에 plan 663 절, `m68k-st.diff` 는 새 07 로 다시 만듦)를 먼저; 상태 도구 두 번, 기대(python): 객체 55(OBJECT_MATCH 45, CODE+BSS_INFERRED 10), 행 78/188, 78566 B(36.39%), `object_bytes` 112650.
11. 기록: PROVENANCE(`scsireg.h` 1127 행 nextmach → nextmach+authored·새 SHA, `st.c` 행에 plan 663 줄, `autoconf.c`·`sg.c` 행에 재수락, 새 `sd.c`·`sdvar.h` 행; 일곱 칸·경로 겹침 없음), MODIFICATIONS, DECISIONS D153, 계획·HANDOFF·메모리. M7: `_sd_sd`·`_sd_sdd`(NeXTMach `scsiconf.c:43–44`), 호출 대상들은 다른 객체.

관문: 명령 종료 0, 경고는 `sd` 의 known_warnings 와 같음·나머지 0, i386 0, 회귀 같음, 확인·최종·zerofill·단언 모두 `ok`, 상태 도구가 멈추지 않고 기대와 같음. 하나라도 어긋나면 07 머리·`st.c` 를 바꾸기 전 사본으로 되돌리고 알립니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 663.1 교차검토(codex `gpt-6.1-sol`, task kkgv9i8uz) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 최종 기록 둘(§663 두 칸 튜플 `st`·`sg`, §664 네 칸 튜플 `autoconf`·`sd` + zerofill 하나)이 상태 도구로 됨; 명세는 F 만·객체마다 `refs`·`plan` 일치; 옛 튜플(§649·§652·§655)은 빼야 중복 이름 단언에 걸리지 않음 | `m4_m68k_status.py:141–150`(튜플 길이 2·4, zf 는 튜플 단위), 180 행대(중복 이름), `m4_m68k_probe.py:57–62` | ✅ |
| `known_warnings` 는 E1 이 아니라 p1 F 의 stderr 그대로(경로·줄 번호·"In function" 줄) — E1 stderr 는 17 줄(경고 11) | `wc -l` 17 | ✅ |
| 7 단계 차이·`--plan` 번호·`L2_*` 환경 변수가 맞음; b657 은 보관 657 스테이지·명령 | §657.2 와 같은 방법 | ✅ |
| 앞 객체와의 비교는 canon 같음 + `obj_sig` 의 `header`·`sections`·`symbols` 같음, `stabs` 수만 다를 수 있음; F/L·최종/REF 는 `obj_sig` 전부 같음 | `l2_prefix_diff.py:47–52`(`obj_sig` 는 그 넷), python: S1 대 §652 는 `stabs` 1462 → 1469 만 다름 | ✅ |
| `st`·`sg` 는 OBJECT_MATCH·사유 없음·`full_span`·funcbytes 를 명시; 경고가 있어 `diag_gate.commands_ok` 는 거짓이므로 따로 단언; `-E` stderr 는 0(형 경고는 `-E` 에 안 나옴); `chk_p661.py` 는 머리 출처를 진단 사본이 아닌 스테이지 07 로 요구하게 | 계획 문구; `-E` 는 전처리만 | ✅ |
| 상태 수 55·45·10·78/188·78566·36.39%·112650 이 맞음 | 이번 세션 python(§663 앞) | ✅ |
| 최종 객체 SHA 에 묶인 확인 기록(§655 꼴), PROVENANCE 의 생성 `sd.h` 행(1186, 아직 hypothesis)도 고칠 것; `sd.h` 에는 주석이 없으니 더하지 말 것 | PROVENANCE 1186 행 읽음, `generated/sd.h` 내용 `#define NSD 7` 뿐 | ✅ |
| zerofill `objs` 는 P464 와 이번 객체끼리만 겹침을 보므로 받아들인 모든 bss 자리와 따로 대조 | `m5_m68k_zerofill.py:148–150` | ✅ 상태 전에 `ACCEPTED` 의 zerofill 기록 전부의 후보와 python 으로 대조 |

계획 수정: 위 ✅ 를 그대로 단계에 넣음(8·9·10·11). 확인 기록은 `m4-m68k-p663-checks-20261031.json`(st·sg)·`m4-m68k-p664-checks-20261031.json`(autoconf·sd).

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 663.2 결과(2026-11-01)

먼저 제 잘못(모두 기록이나 run 을 남기기 전에, 또는 바로잡고 적음): ① PROVENANCE `st.c` 행에 NeXTMach 줄 번호를 확인 없이 213 으로 적었다가 python 으로 214 로 고침. ② `sd` 단언 스크립트가 객체 넷 run 에서 변형 이름만으로 골라 `autoconf` 의 L1 을 읽음 — 객체 이름도 보게 고쳐 다시 돌림. ③ 최종 명령 파일을 `final.cmd` 로 만들어 probe 가 읽는 `probe.cmd.opts.json` 이 그 폴더에 없었고, 그래서 최종 기록 둘의 `options` 칸이 비어 있음(`null`) — 같은 내용의 `final.cmd.opts.json` 으로 확인 기록에서 단언함(상태 도구는 이 칸을 쓰지 않음).

- 1 07 `nextmach/nextdev/scsireg.h` 462 → 484 행, SHA `acad0fed…`(scratch `p663/gen_p663h.py --write`; 바꾸기 전 SHA·진단 사본과 주석 뺀 토큰 같음 단언); 2 07 `st.c` 1301 → 1304 행(238 행 S1 꼴 + 머리 주석 세 줄), SHA `a90aa6bc…`.
- 3·4 07 `nextmach/nextdev/sdvar.h` 272 행(SHA `ac01dd73…`), 07 `src/machdep/m68k/sd.c` 3109 행(SHA `2919cd16…`), L `08_build/artifacts/m4p663/src/sd_L.c`(scratch `p663/gen_p663.py --write`; F = E1 토큰(import 한 줄만 바꿈)·`sdvar.h` = 진단 사본 토큰·F = L 토큰과 토큰 줄·표시 없는 바뀐 줄 0 — 처음 실행에서 들여쓰기만 바뀐 `cr_blklen = 512;` 한 줄이 표시 없이 걸려 표시를 더함).
- 5 구성 `sd NSD` 행 `confirmed`(22 행 그대로), `gen_config_headers.py --check` 둘 종료 0, 생성 `sd.h` SHA 그대로(`50e922ef…`). 6 `stage_m68k.py` 756 → 759 행.
- 7 회귀: `--plan 657` 재생성(`m0p657-r663-stage`, 995)은 보관본과 `scsireg.h`·`st.c` 둘만(키 `files`), `m0p663-a1-stage`(997)는 그것과 `sd.c`·`sdvar.h`만(키 `files`·`m4_headers`·`m4_sources`·`plan`), 어긋남 0. `m5-657.cmd` 는 보관본과 같고 `m5-663.cmd` 는 411/412 줄이 계획 번호만 다름. M5 205(`m3p663-b657` 보관 657 스테이지, `m3p663-cc1`): 객체·출력 같음(`run.json` 만), `compare` 둘 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 `sd.c`·`sdvar.h` 뿐. x86 `m4-x86-inputs-p663-20261031.json` `ok`(p657 과 같음), `--plan 663 x86gate` 일곱 같음.
- 8 확인 run `m4p663-p1`(명령 16 종료 0; `sd` 경고 11·나머지 0; `m4-m68k-p663-p1checks-20261031.json` `ok`): funcbytes `autoconf` 11/11·`st` 26/26·`sg` 14/14·`sd` 42/42(F·L); F = L(canon·`obj_sig`); 앞 객체(§649·§652·§655)와 canon 같고 `obj_sig` 는 `stabs` 수만 다름(1092→1099, 1462→1469, 1058→1065); 머리 출처는 스테이지 07 `scsireg.h`(`sd` 는 07 `sdvar.h` 도); `sd` 함수 밖 단언 F·L `ok`(scratch `p663/chk_p663.py`). `-E` run `m4p663-e2`(`m4-m68k-p663-e2-20261031.json` `ok`): `sd` F = L = E1 27658 토큰, `st` F = L = S1 16150, stderr 0, i386 0.
- 9 최종 run `m4p663-a1`(`st`·`sg`, `m4-m68k-p663-final-20261031.json`, SHA `7a8e10a8…`)·`m4p664-a1`(`autoconf`·`sd`, `bss_inferred`, `sd` 의 `known_warnings` 17 줄, `m4-m68k-p664-final-20261031.json`, SHA `4fd08194…`): 둘 다 `gate.ok`; funcbytes 26/26·14/14·11/11·42/42. zerofill `m4-m68k-zerofill-p664-20261031.json`(SHA `e8717a3c…`): `autoconf` [0x40b4f4e, 0x40b4f52)(§649 와 같음)·`sd` [0x40b4fde, 0x40b507c), 둘 다 `reference-inferred`, 경로에 계정·절대 경로 없음. 확인 `m4-m68k-p663-checks-20261031.json`·`m4-m68k-p664-checks-20261031.json`(`ok`; 의존 SHA 사슬에 새 `scsireg.h`·`sdvar.h`, 07 = 스테이지, 받아들인 모든 bss 자리 10 개와 겹침 없음).
- 10 상태(`m4-m68k-status-p664-20261031.json`, 표 56 → 57 행; scratch 에 두 번 돌려 같음): 객체 55(OBJECT_MATCH 45, CODE+BSS_INFERRED 10), 행 78/188, 78566 B(36.39%), `object_bytes` 112650, 부분 행에 `m68k-237` 더함 — 미리 계산한 값과 같음. 근거 `m68k-sd.md`(새)·`m68k-sd.diff`·`m68k-sdvar_h.diff`·`m68k-scsireg_h.diff`(새), `m68k-st.diff` 다시 만듦, `m68k-st.md`·`m68k-sg.md`·`m68k-autoconf.md` 에 plan 663 절.
- 11 기록: PROVENANCE 1210 → 1212 행(`scsireg.h` nextmach → nextmach+authored, `st.c`·`autoconf.c`·`sg.c`·생성 `sd.h` 행 고침, 새 `sd.c`·`sdvar.h`; 일곱 칸·겹침 없음), MODIFICATIONS 745 → 749, DECISIONS D153(156 → 157 행).

판정(미리 정한 대로): 관문을 모두 통과해 `sd` 를 받아들이고 `autoconf`·`st`·`sg` 를 다시 받아들였습니다(D153).

## 665. M4-170 세부 계획 — m68k `scsi.c`(행 237 일부) 진단 A1(07 변경 없음; 코딩 전, 2026-11-01)

고른 까닭: 같은 SCSI 묶음에서 `sd` 바로 앞이고 작으며(2008 B), 끝이 받아들인 `sd`(0x407c574)와 맞닿습니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p665/scsi.dis` = `scsi_all.dis` 의 [0x407bd9c, 0x407c574), 바이트 2008 B 가 Mach-O 와 모두 같음; 수는 python; 07 원천 찾기는 python/`grep -a`):
- 범위 [0x407bd9c, 0x407c574) 2008 B, 이어진 15 항목: 외부 이름 13(`_scsi_init` 38·`_scsi_probe` 160·`_scsi_slave` 334·`_scsi_attach` 72·`_scsi_dstart` 82·`_scsi_docmd` 42·`_scsi_cintr` 282·`_scsi_reselect` 146·`_scsi_restart` 98·`_scsi_ioctl` 76·`_scsi_timeout` 54·`_scsi_msg` 94·`_scsi_sensemsg` 86)과 이름 없는 둘(0x407c04a 38 B, 0x407c2f4 406 B). 앞쪽 0x407bb06 `_scminphys` 와 그 뒤 넷은 NeXTMach `sc.c` 의 끝 함수들(`scminphys` 1519 행 뒤 `scmsgin`·`scmsgout`·`screset`·`scioctl`)로 보여 이 단위에 넣지 않음.
- 참고 글: NeXTMach mk-108.1 `nextdev/scsi.c`(770 행, SHA-256 `503816ce…`, ASCII). 함수 정의 21 중 다섯(`scsi_rejectcmd`·`scsi_expectintr`·`scsi_gotintr`·`scsi_expectreselect`·`scsi_gotreselect`, 433–446·602–628 행)은 `#ifndef SCSI_MACROS` 아래이고 07 `scsivar.h:200` 이 `SCSI_MACROS 1` 이라 컴파일되지 않음. 남는 16 가운데 `scsi_pollcmd`(327 행)는 원본 기호표에 없음(`_scsi_pollcmd` 0 건, 문자열 `"scsi_pollcmd: timeout"` 도 원본에 없음) → 1997 에서 빠진 것으로 봄. 나머지 15 가 정의 차례대로 대응: 이름 없는 둘은 static `scsi_cstart`(394 행) = 0x407c04a, static `scsi_timer`(633 행) = 0x407c2f4.
- 자료: 정적 bss [0x40b4fca, 0x40b4fde) 20 B(참조 다섯; NeXTMach static `scsi_timer_running`·`scsi_timer_interval`·`scsi_ctrl_list`(8 B)·`scsi_init_flag` = 4 + 4 + 8 + 4; 끝이 받아들인 `sd` bss 시작과 맞닿음) — 받아들이면 CODE+BSS_INFERRED 로 예상. COMMON `_scsi_ndevices`(NeXTMach 70 행 `int scsi_ndevices;`). 이 객체의 `__data` 는 없음으로 보임(참조는 `_hz`·`_scsi_sdswlist` 뿐).
- 문자열: 이 객체 몫 [0x40ab52a, 0x40ab656) 300 B(앞은 `sc.c` 의 `"scmsgin: no FUNCCMPLT"`, 뒤는 `sd` 의 `"sd"`), 문자열 열. NeXTMach 의 `"scsi: compiler alignment problems"`(206 행, 상수 조건이라 죽은 코드)는 원본에 없음.
- 1997 바뀜으로 이미 보인 것(D149 의 2 차원 `sc_lunmask`): `scsi_probe` 는 `sc_target = 7` 을 먼저 두고 `bzero(scp->sc_lunmask, 0x40)` 뒤 `sc_lunmask[sc_target][s] = 1`(s 0–7) 을 셈(0x407bdda–0x407be06; NeXTMach 213–216 행의 `sc_lunmask[s] = 0`·`= -1` 은 1997 표에서 컴파일되지 않음); `scsi_slave` 의 두 검사는 `sc_lunmask[target][lun]` 바이트 검사(`tstb`, 0x407bf0a·0x407bf50; NeXTMach 261·276 행).
- 구간: `span()` 은 `{"range": ["0x407bd9c", "0x407c574"], "rows": [], "partial": ["m68k-237"], …}` 만 받음(python 셋 시험). 행 237 은 정확한 행이 아니라 받아들여도 덮은 행·바이트는 그대로.
- include: NeXTMach 19 줄(42–61 행) 중 스테이지에 없는 넷을 선례대로 — `next/printf.h`→`kernserv/printf.h`, `next/psl.h`→`m68k/psl.h`, `nextdev/busvar.h`→`dev/busvar.h`, `nextdev/disk.h`→`dev/disk.h`(D104); `nextdev/scsireg.h`·`scsivar.h` → `dev/m68k/…`(D113). `machine/spl.h`·`machine/cpu.h`·`nextdev/dma.h`·`screg.h`·`scvar.h` 는 스테이지에 있음.

방법(진단; 07 은 바꾸지 않음; scratch `p665/gen_p665.py` 가 NeXTMach 글(SHA 단언)에서 만듦 → `08_build/artifacts/m4p665/src/`):
- 변형 A1: include 바꿈 여섯 + `sc_lunmask` 를 쓰는 넷을 위 바이트 꼴로(`scsi_probe`: `scp->sc_target = 7; bzero(scp->sc_lunmask, sizeof(scp->sc_lunmask)); for (s = 0; s < SCSI_NLUNS; s++) scp->sc_lunmask[scp->sc_target][s] = 1;`; `scsi_slave`: `if (scp->sc_lunmask[sdp->sd_target][sdp->sd_lun])` 두 곳) + `scsi_pollcmd` 를 지운 꼴 A1 과 그대로 둔 꼴 A2(둘의 차이로 원본에 없는 함수가 객체에 더해지는지 봄). 바뀐 줄마다 `plan 665 diagnostic`.
- 명세 `08_build/artifacts/m4p665/spec.json`: 바탕 `08_build/runs/tools/m0p663-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `scsi`, 위 구간(`basis` 적음), `x86_rel` `machdep/i386/dkbad.c`. run `m4p665-p1`(REGISTRY 0 건 확인; `wait` 뒤 `collect` 없이 `compare`, `set -eo pipefail`), 기록 `m4-m68k-probe-p665-p1-20261101.json`, funcbytes `m4-m68k-funcbytes-p665-<변형>-20261101.json`(이름 없는 둘: `0x407c04a=_scsi_cstart`·`0x407c2f4=_scsi_timer`; bss 기준점은 A1 객체 배치가 원본 참조 다섯 주소와 한 기준으로 맞을 때만 그 배치로 줌 — §658.2 와 같은 규칙).
- 측정: 종료 상태·경고, 함수별 길이·바이트·재배치 대상, 객체에만 있는 함수, 절(`__text` 2008·`__data` 0·`__cstring` 300 목표·`__bss` 20), 문자열 내용·차례, 바깥 정의 13 이 원본 자리, 지역 기호, COMMON·미정의가 원본 이름. 단언은 따로(scratch 스크립트; `diag_gate` 만 믿지 않음).

판정(미리 정함; 07 은 바꾸지 않음): 다른 함수가 있으면 원본 바이트로 바뀜을 읽어 다음 진단(§666)을 세움; 15/15 이고 함수 밖 단언이 맞으면 바이트로 가려지지 않는 꼴을 구현 전에 여쭘. 컴파일이 안 되면 원인을 적고, 원본 바이트가 꼴을 보이면 그 꼴로, 아니면 최소 고침으로 새 변형을 만들어 새 run ID 로.

### 665.1 교차검토(codex `gpt-6.1-sol`, task kdx0ayi46) 판정과 계획 수정

먼저 제 잘못: ① 인용 둘(정렬 검사 `panic` 201 행 → 206 행, `sc_lunmask` 덩이 212–216 → 213–216)을 codex 에 보내기 전에 python 으로 고침. ② `"scsi_pollcmd: timeout"` 이 원본에 없다는 것을 `scsi_pollcmd` 가 빠진 근거로 적었으나, 그 출력은 `#ifdef SCSI_TRACE`(354–356 행) 아래라 근거가 아님 — 근거는 원본 기호표의 `_scsi_pollcmd` 0 건과 15 항목의 대응뿐이고, "1997 에서 빠짐" 은 추정입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 15 항목·크기, 이름 없는 둘의 대응, bss 20 B(정적 넷: 0x40b4fca·0x40b4fce·0x40b4fd2(+0x40b4fd6)·0x40b4fda), COMMON `_scsi_ndevices`, `__data` 없음, 문자열 300 B, 정렬 `panic` 문자열 없음 | 이번 세션 python(함수 표, 참조 주소 다섯, 문자열), `scsi.dis` | ✅ "참조 다섯" 은 서로 다른 주소 다섯 |
| `scsi_pollcmd` 문자열 없음은 근거가 아님(`SCSI_TRACE`) | `scsi.c:354–356` | ✅ 위 ② |
| `sc_lunmask` 밖의 차이는 보이지 않음(`scsi_docmd` 는 전역 `scsi_ndevices == 1` 검사, 0x407c07c–0x407c086) | `scsi.dis` 0x407c070–0x407c090 읽음 | ⏭️ A1 이 판정(사실관계는 읽은 곳까지 맞음) |
| A1 은 스테이지 머리와 맞아 컴파일될 것으로 보임 | — | ⏭️ run 이 판정 |
| 단언에 절 목록·비디버그 기호의 묶임·절·자리·bss 넷 자리·COMMON 크기·재배치 대상(점프 표 포함)·의존 성공과 머리 출처·i386 0·경고 기준을 넣을 것; A1 이 후보, A2 는 `_scsi_pollcmd` 가 객체에만 있음을 보이는 음성 대조; bss 소유는 추정으로 남김 | `m4_m68k_probe.py:381` | ✅ scratch `p665/chk_p665.py` 에 넣음 |

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 665.2 결과(run `m4p665-p1`, 2026-11-01)

- 명령 4 개 종료 0·경고 0, 의존 i386 0, 원본에 없는 미정의 0, M5 줄과 선택지 차이 없음(`m4-m68k-probe-p665-p1-20261101.json`).
- A1(`scsi_pollcmd` 없음): `__text` 2008 B, **funcbytes 15/15**(`m4-m68k-funcbytes-p665-A1-20261101.json`; 이름 없는 둘과 bss 기준점 넷 — A1 의 bss 배치(`scsi_timer_running` +0·`scsi_timer_interval` +4·`scsi_ctrl_list` +8·`scsi_init_flag` +16, 20 B)가 원본 참조 다섯 주소와 기준 0x40b4fca 하나로 맞음). A2(그대로 둠): `__text` 2206 B, 15/15 이고 `_scsi_pollcmd` 가 객체에만 있음(음성 대조대로).
- 절: A1 은 `__text` 2008(재배치 57)·`__cstring` 334·`__bss` 20, `__data` 없음. `__cstring` 은 원본 몫 300 B 의 열 문자열이 차례까지 같고, 그 밖에 `"scsi: compiler alignment problems"`(34 B) 하나가 더 있음 — NeXTMach 204–206 행의 `sizeof` 상수 조건 `panic` 은 코드가 없어지지만 문자열은 남음. 원본에는 그 문자열이 없음(§665).

판정(미리 정한 대로): 07 은 바꾸지 않고, 그 검사문을 뺀 꼴을 다음 진단(§666)에서 봅니다.

## 666. M4-171 세부 계획 — `scsi.c` 진단 B(정렬 검사문 없음; 07 변경 없음; 코딩 전, 2026-11-01)

- 변형 B: A1 에서 `scsi_probe` 의 `if (sizeof(struct cdb_6) != 6 || … ) panic("scsi: compiler alignment problems");`(NeXTMach 204–206 행)만 지움(진단 주석 한 줄로). 생성 scratch `p665/gen_p666.py`(A1 SHA 단언) → `08_build/artifacts/m4p666/`, run `m4p666-p1`, 기록 `m4-m68k-probe-p666-p1-20261101.json`, funcbytes `-p666-B-`.
- 측정·단언(scratch `p665/chk_p665.py`; §665.1 목록): 15/15·재배치 대상 차이 0·객체에만 있는 함수 없음; 절은 `__text` 2008·`__cstring` 300·`__bss` 20 셋뿐(`__data` 없음); `__cstring` 열 문자열이 원본 0x40ab52a 의 300 B 와 바이트까지 같음; 바깥 정의 13 이 원본 자리, 지역 함수 둘이 원본 항목 시작, bss 지역 넷이 기준점 자리; COMMON 이 원본 이름이고 크기가 원본 기호 간격 이하(`_scsi_ndevices` 4 B 포함); 미정의 모두 원본 이름; 의존 종료 0·i386 0·`scsivar.h`/`scsireg.h` 출처가 스테이지 07; 경고 0; L1 사유가 `__DATA,__bss: unverified` 하나·`full_span`.
- 판정(미리 정함): 모두 맞으면 바이트로 가려지지 않는 꼴(`scsi_pollcmd` 를 지우는 방식 — 함수째 지움 / `#if 0` 등, 그리고 그 선언 07 `scsivar.h:179` 를 둘지; 정렬 검사문을 지우는 방식)을 구현 전에 여쭙니다. 어긋나면 원인을 적고 다음 꼴.

### 666.1 교차검토(codex `gpt-6.1-sol`, task kh95vjfce) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 남는 초기화 내용 차이는 그 문자열 하나(나머지 300 B 가 원본과 같고, 그 문자열은 원본 어디에도 없음); 지우면 명령·기호·재배치 대상은 그대로이나 문자열·bss 참조의 저장 주소(원시 바이트)는 옮겨짐 | 이번 세션 python(문자열 대조: 원본 몫 열이 차례까지 같고 객체에만 그 하나) | ✅ B 의 단언은 정규화한 재배치 대상으로 보고 A1 원시 바이트와의 같음은 요구하지 않음 |
| 다른 후보 꼴(전처리로 뺌, 음수 배열 typedef 같은 컴파일 시점 검사)도 있을 수 있음 | — | ⏭️ 구현 질문의 선택지로 둠(바이트로 가려지지 않으면) |
| 비디버그 기호는 외부 `__text` 13·지역 `__text` 2·지역 `__bss` 4·COMMON 14·미정의 7(`_bzero`·`_hz`·`_panic`·`_printf`·`_scsi_sdswlist`·`_strcmp`·`_timeout`) | A1 객체 python 셈 | ✅ 단언을 정확한 목록으로 |
| bss 는 절 기준 오프셋으로 보고, 원본 참조 다섯(0x40b4fd6 = `scsi_ctrl_list`+4 포함)을 대조 | §665.2 | ✅ |
| COMMON 크기 ≤ 원본 다음 기호 간격은 상한 검사일 뿐 | — | ✅ 문구로 적음 |
| L1 은 문자열 절을 통째로 비교하지 않음(`l1_compare.py:307`) — 문자열 바이트 같음은 따로 단언 | 계획에 이미 따로 있음 | ✅ |
| 07 전체에서 `scsi_pollcmd` 는 `scsivar.h:66`(주석)·`:179`(선언)뿐 | python 바이트 검색(07 전체) | ✅ 구현 질문에 선언을 둘지 넣음 |
| `sizeof(scp->sc_lunmask)` 와 숫자 0x40 은 바이트로 가려지지 않음 | — | ✅ 구현 질문에 넣음 |

2차 자기검사: ✅ 행은 이번 세션 python 입니다.

### 666.2 결과(run `m4p666-p1`, 2026-11-01)

- 명령 2 개 종료 0·경고 0, 의존 i386 0(`m4-m68k-probe-p666-p1-20261101.json`). funcbytes **15/15**(`-p666-B-`, 재배치 대상 차이 0, 객체에만 있는 함수 없음).
- 단언(scratch `p665/chk_p665.py`; 기록 `m4-m68k-p666-diagchecks-20261101.json`, `ok`): 절은 `__TEXT,__text` 2008(재배치 57)·`__TEXT,__cstring` 300(0)·`__DATA,__bss` 20(0) 셋뿐; `__cstring` 300 B 가 원본 0x40ab52a 의 바이트와 같음; 외부 `__text` 13 이 원본 자리, 지역 `scsi_cstart`·`scsi_timer` 가 원본 항목 시작, bss 지역 넷이 절 기준 +0·+4·+8·+16; COMMON 14 모두 원본 이름이고 크기 ≤ 원본 기호 간격(`_scsi_ndevices` 4 B; 상한 검사일 뿐); 미정의는 정확히 `_bzero`·`_hz`·`_panic`·`_printf`·`_scsi_sdswlist`·`_strcmp`·`_timeout`; L1 사유 `__DATA,__bss: unverified` 하나·`full_span`; 머리 출처는 스테이지 07 `scsireg.h`·`scsivar.h`.

판정(미리 정한 대로): 구현 전에 바이트로 가려지지 않는 꼴을 여쭙니다.

## 667. M4-172 D154 구현 계획 — 07 `src/machdep/m68k/scsi.c`(명시 구간 [0x407bd9c, 0x407c574), 부분 행 237, CODE+BSS_INFERRED; 코딩 전, 2026-11-01)

사용자 결정(D154 로 적을 것; AskUserQuestion 넷): ① `scsi_pollcmd()` 는 함수를 지우고 그 자리에 표시 주석(추천안) ② 공유 07 `scsivar.h` 의 그 선언(179 행)과 주석(66 행)은 그대로(추천안; 머리를 바꾸지 않아 다시 받아들일 객체 없음) ③ 정렬 검사문은 지우고 표시 주석(추천안) ④ `bzero` 크기는 `SCSI_NTARGETS * SCSI_NLUNS`(07 `scsireg.h:343–344`; 추천안 `sizeof(scp->sc_lunmask)` 가 아님 — 진단에 쓴 꼴이 아니므로 확인 run 에서 바이트로 봄). 앞선 결정 그대로: include OPENSTEP 경로(D104·D113), 2 차원 `sc_lunmask`(D149). (제 잘못: 첫 질문 문구에 "07 sd.c" 라고 적음 — `scsi.c` 의 오기.)

1. 07 `scsi.c`(scratch `p665/gen_p667.py --write`): NeXTMach `scsi.c`(SHA `503816ce…`) + 머리 주석 덩이(NeXTMach 머리 주석 뒤; 바뀜 목록·바이트가 정하지 않은 꼴은 D154 의 선택) + include 여섯(표시 `plan 667 (D104[, D113])`) + `scsi_probe`(`sc_target = 7` 먼저, `bzero(scp->sc_lunmask, SCSI_NTARGETS * SCSI_NLUNS)`, 자기 target 의 lun 을 1 로)·`scsi_slave` 검사 둘(`plan 667 (D149, D154)`), 정렬 검사문과 `scsi_pollcmd()` 를 지운 자리에 표시 주석. 단언: 진단 B 와 토큰이 같음(`bzero` 둘째 인자만 `sizeof ( scp -> sc_lunmask )` ↔ `SCSI_NTARGETS * SCSI_NLUNS`); L(`08_build/artifacts/m4p667/src/scsi_L.c`)과 F 의 토큰·토큰 줄 같음; 표시 없는 바뀐 줄 0.
2. `stage_m68k.py`: `M4FILES[667] = list(M4FILES[663]) + ['scsi.c']`, `EXCEPTS[667] = dict(EXCEPTS[663])`, 머리말 목록. `M4HEADERS` 는 그대로.
3. 회귀: `--plan 663` 재생성(`m0p663-r667-stage`)은 보관 `m0p663-a1-stage` 와 매니페스트가 바이트까지 같음; `m0p667-a1-stage` 는 그것과 `scsi.c`(키 `files`·`m4_sources`·`plan`)만 다름, 어긋남 0; `m5-663.cmd` 는 보관본과 같고 `m5-667.cmd` 는 계획 번호만 다름; M5 205(`m3p667-b663` 은 보관 663 스테이지·`--plan 663 compare`, `m3p667-cc1` 은 `--plan 667 compare`) 객체·출력 같음, `differ_unexpected`·`lost` 빔; x86 `m4_x86_inputs.py s6ln`(`L2_FORMS`·`L2_EXPECT` s6p398) `ok`, `--plan 667 x86gate` 일곱 같음.
4. 확인 run `m4p667-p1`(명세 `08_build/artifacts/m4p667/confirm/spec.json`; F = `@machdep/m68k/scsi.c`, L): 종료 0·경고 0·i386 0, F·L 15/15, F = L(canon·`obj_sig`), F 와 진단 B 객체가 canon 같음(`bzero` 꼴이 바이트로 같음을 보임); `chk_p665.py` 단언 F·L `ok`. `-E` run `m4p667-e2`(F·L; `EXPECT`; `collect` 뒤 `out/_log`): 토큰 F = L, stderr 0, i386 0.
5. 최종 run `m4p667-a1`(명세 `08_build/artifacts/m4p667/spec.json`, F 만, `refs` = p1 L, `bss_inferred` [`scsi`]; 기록 `m4-m68k-p667-final-20261101.json`): `gate.ok`, 15/15. zerofill `objs`(출력 `08_build/artifacts/m4p667/zerofill`, 기록 `m4-m68k-zerofill-p667-20261101.json`): `scsi:<최종>:<p1 L>`, `reference-inferred`, 후보 [0x40b4fca, 0x40b4fde), 받아들인 모든 bss 자리와 겹침 없음(python). 확인 기록 `m4-m68k-p667-checks-20261101.json`(최종 객체 SHA 에 묶음: L1·funcbytes·선택지 = M5 줄(`final.cmd.opts.json`)·의존 SHA 사슬·07 = 스테이지·e2·p1 단언·zerofill).
6. 상태: 근거 `06_reconstruction/evidence/m68k-scsi.md`·`m68k-scsi.diff` 를 먼저; `ACCEPTED` 에 네 칸 튜플 하나; 상태 도구 두 번, 기대(python): 객체 56(OBJECT_MATCH 45, CODE+BSS_INFERRED 11), 행 78/188 그대로(행 237 은 부분 행 — 이미 `sd` 의 부분 행), 78566 B(36.39%) 그대로, `object_bytes` 114658.
7. 기록: PROVENANCE 새 행(`scsi.c` nextmach+authored), MODIFICATIONS, DECISIONS D154, 계획·HANDOFF·메모리. M7: COMMON `_scsi_ndevices` 의 정의 자리, 정적 bss 자리, `scsi_sdswlist`(NeXTMach `scsiconf.c`)·호출 대상은 다른 객체.

관문: 명령 종료 0·경고 0·i386 0, 회귀 같음, 확인·`-E`·최종·zerofill·확인 기록 `ok`, 상태 도구가 기대와 같음. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 667.1 교차검토(codex `gpt-6.1-sol`, task k5h98pt5g) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계 차례·기대 수(56·45·11, 78/188, 78566, 36.39%, 114658)가 맞음; `ACCEPTED` 는 네 칸; bss 는 남은 자리 모두와 따로 대조 | 이번 세션 python(§667 앞), `m4_m68k_status.py:143` | ✅ |
| `bzero` 꼴: 토큰 단언은 글 차이만 보이고, 바이트 같음은 F 와 B 객체의 canon 같음으로 보임(원본 0x407bde0 `pea 0x40` = 8 × 8) | `scsi.dis` 0x407bde0 | ✅ 확인 run 에서 F/B canon 과 `obj_sig` 의 header·sections·symbols 도 대조 |
| 기록 이름을 다 적고, 명세 둘의 바탕 `m0p667-a1-stage` 를 명시; B 원천·객체를 p666 기록 SHA 에 묶음 | §667 문구 | ✅ 아래 |
| 스테이지 F 는 `chk_p665.py` 에 접미어 `/machdep/m68k/scsi.c` 를 줘야 함(기본 `/scsi_<변형>.c`) | `chk_p665.py:12` | ✅ |
| M7 에 공유 머리 COMMON 14 의 합침 의무 전부 | §666.2(COMMON 14) | ✅ |

계획 수정: 기록 이름 — 확인 `m4-m68k-probe-p667-p1-20261101.json`·funcbytes `m4-m68k-funcbytes-p667-F/L/a1-20261101.json`·확인 단언 `m4-m68k-p667-p1checks-20261101.json`·`-E` `m4-m68k-p667-e2-20261101.json`; 확인·최종 명세의 바탕은 `08_build/runs/tools/m0p667-a1-stage`.

2차 자기검사: ✅ 행은 이번 세션의 줄·python 입니다.

### 667.2 결과(2026-11-01)

- 1 07 `src/machdep/m68k/scsi.c` 748 행, SHA `b55a7eb1…`, L `08_build/artifacts/m4p667/src/scsi_L.c`(scratch `p665/gen_p667.py --write`; 진단 B 와 토큰이 `bzero` 둘째 인자만 다름·F = L 토큰과 토큰 줄·표시 없는 바뀐 줄 0 단언). 2 `stage_m68k.py` 759 → 761 행.
- 3 회귀: `--plan 663` 재생성 매니페스트가 보관본과 바이트까지 같음; `m0p667-a1-stage`(998)는 `scsi.c` 만 더함(키 `files`·`m4_sources`·`plan`), 어긋남 0. `m5-663.cmd` 는 보관본과 같고 `m5-667.cmd` 는 411/412 줄이 계획 번호만 다름. M5 205(`m3p667-b663`·`m3p667-cc1`) 객체·출력 같음(`run.json` 만), `compare` 둘 `differ_unexpected`·`lost` 빔, 요약 차이는 `scsi.c` 뿐. x86 `m4-x86-inputs-p667-20261101.json` `ok`(p663 과 같음), `--plan 667 x86gate` 일곱 같음.
- 4 확인 run `m4p667-p1`(`m4-m68k-p667-p1checks-20261101.json` `ok`): F·L 15/15·경고 0, `chk_p665.py` 단언 F·L `ok`, F = L, F 와 진단 B 객체가 canon·`obj_sig` 까지 같음(`bzero` 크기 꼴이 바이트로 같음). `-E` `m4p667-e2`(`ok`): F = L 11645 토큰, stderr 0.
- 5 최종 run `m4p667-a1`(`m4-m68k-p667-final-20261101.json`, SHA `29e2ca90…`): `gate.ok`, 15/15. zerofill(`m4-m68k-zerofill-p667-20261101.json`, SHA `2c2f8bde…`): `reference-inferred`, [0x40b4fca, 0x40b4fde), 남은 받아들인 bss 자리 10 개와 겹침 없음. 확인 `m4-m68k-p667-checks-20261101.json`(`ok`; 의존 104·SHA 사슬·선택지 = M5 줄(`final.cmd.opts.json`)·07 = 스테이지). 객체 SHA `84162b84…`.
- 6 상태(`m4-m68k-status-p667-20261101.json`, 표 57 → 58 행; scratch 에 두 번 같음): 객체 56(OBJECT_MATCH 45, CODE+BSS_INFERRED 11), 행 78/188, 78566 B(36.39%), `object_bytes` 114658 — 미리 계산한 값과 같음. 근거 `m68k-scsi.md`·`m68k-scsi.diff`.
- 7 기록: PROVENANCE 1212 → 1213 행(일곱 칸, 겹침 없음), MODIFICATIONS 749 → 750, DECISIONS D154(157 → 158 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D154).

## 668. M4-173 세부 계획 — m68k `sc.c`(행 235·236·237 일부) 진단 A1(07 변경 없음; 코딩 전, 2026-11-01)

고른 까닭: 같은 SCSI 묶음의 마지막 파일이고, 끝이 받아들인 `scsi`(0x407bd9c)와 맞닿습니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p668/sc.dis` = `scsi_all.dis` 의 [0x407aae0, 0x407bd9c), 바이트 4796 B 가 Mach-O 와 모두 같음; 수는 python; 07 원천 찾기는 python):
- 시작: 0x407aa4c–0x407aae0 의 `_od_panel_abort`·이름 없는 하나(110 B)·`_oddump`·`_odsize` 는 1997 `od.c` 의 끝(NeXTMach `od.c` 는 `od_eject`(5318 행)로 끝나지만 `oddump`·`odsize` 는 5052·5054 행에 있음 — 1997 판에서 차례가 다름)으로 보여, `sc.c` 는 `_odsize` 다음 0x407aae0 부터. 끝은 `_scsi_init` 0x407bd9c.
- 범위 [0x407aae0, 0x407bd9c) 4796 B, 17 항목: 외부 이름은 `_scminphys`(42 B) 하나, 나머지 16 은 이름 없음. NeXTMach mk-108.1 `nextdev/sc.c`(1763 행, SHA-256 `0ea59566…`, ASCII)의 함수 18 가운데 `scshowstatus`(1724 행)는 `#if DEBUG || XPR_DEBUG`(1722–1755 행) 아래라 빠지고, 남는 17 이 정의 차례대로 대응: 0x407aae0 `scinit` 134·0x407ab66 `scprobe` 600·0x407adbe `scsetup` 222·0x407ae9c `scslave` 40·0x407aec4 `scattach` 52·0x407aef8 `scstart` 254·0x407aff6 `sc_dostart` 262·0x407b0fc `scgo` 130·0x407b17e `scdmaintr` 60·0x407b1ba `scintr` 1760·0x407b89a `scfsm` 368·0x407ba0a `scdmastart` 252·0x407bb06 `_scminphys` 42·0x407bb30 `scmsgin` 342·0x407bc86 `scmsgout` 48·0x407bcb6 `screset` 220·0x407bd92 `scioctl` 10. 뒷받침: `__data` `_scdriver`(0x40b202e) 의 함수 포인터 0x407ab66·0x407ae9c·0x407aec4·0x407b0fc·0x407aae0 = NeXTMach `sc.c:146–151` 의 `scprobe`·`scslave`·`scattach`·`scgo`·`scinit`, `_sc_scsw`(0x40b2060) 의 0x407aef8·0x407bd92·0x407bcb6 = `scstart`·`scioctl`·`screset`(153–157 행).
- 자료: `__data` [0x40b202e, 0x40b206c) 62 B(`scdriver` 50 B + `sc_scsw` 12 B; 앞은 받아들인 `dma` 의 `_dma_recover_wl`, 뒤는 `_scsi_sdswlist`); 정적 bss [0x40b4fc2, 0x40b4fca) 8 B — 0x40b4fc2 는 `scintr` 의 `static int old_s5c_state`(723 행; 첫 참조 0x407b276), 0x40b4fc6 은 `sc_bcp[NSC]`(141 행; `scdriver` 가 가리킴) → `sc_bcp` 4 B 이므로 NSC 1(생성 `sc.h` 는 이미 `NSC 1`, 구성 행 `hypothesis` — plans 571–573, D129). 끝이 받아들인 `scsi` bss 와 맞닿음. 받아들이면 CODE+BSS_INFERRED 로 예상.
- 문자열: 이 객체 몫은 `"sc"`(0x40ab30a)부터 0x40ab52a 까지 544 B 로 보임(앞은 `od` 의 볼륨 안내, 뒤는 `scsi` 몫). `"dma error"`·`"scsi bus parity error during dma"`(0x40ab3cf·0x40ab3d9)도 그 안에 있음(§668.1 에서 고침: `movel #` 로 참조됨, 0x407b550·0x407b55c).
- COMMON 참조: `_sc_sc`·`_sf_access_head`·`_fd_controller`·`_disr_shadow`·`_slot_id`·`_slot_id_bmap`·`_dma_chip`·`_machine_type`·`_intrstat`(정의는 다른 객체 또는 공유 머리; D136 검사는 A1 에서).
- 구간: `span()` 은 `{"range": ["0x407aae0", "0x407bd9c"], "rows": [], "partial": ["m68k-235", "m68k-236", "m68k-237"], …}` 만 받음(python 시험: 236 을 `rows` 에 두면 멈춤). 덮은 행·바이트는 그대로.
- include: NeXTMach `#import` 30 줄(42–73 행) 중 스테이지에 없는 것과 선례 — `next/psl.h`→`m68k/psl.h`·`next/printf.h`→`kernserv/printf.h`·`nextdev/disk.h`→`dev/disk.h`(D104), `next/cpu.h`→`m68k/cpu.h`(D110), `nextdev/scsireg.h`·`scsivar.h`→`dev/m68k/…`(D113), `next/scr.h` 는 스테이지에 없음(07 사본도 없음; `autoconf.c` 는 이것을 뺐음, plan 526) — A1 은 빼고 컴파일해 무엇이 모자라는지 봄. `next/autoconf.h`·`nextdev/dma.h`·`sf_access.h`·`odreg.h`·`screg.h`·`scvar.h`·`fd_reg.h`·`next/kernel_pmon.h`·생성 `sc.h` 는 스테이지에 있음.

방법(진단; 07 은 바꾸지 않음; scratch `p668/gen_p668.py` → `08_build/artifacts/m4p668/src/`):
- 변형 A1: 위 include 바꿈과 `next/scr.h` 뺌(진단 표시). 그 밖은 NeXTMach 그대로. 컴파일이 안 되면 미리 정한 대로 원인을 적고, 원본 바이트가 꼴을 보이면 그 꼴로, 아니면 최소 고침으로 A1B 를 만들어 새 run ID 로(변형 이름은 대문자만, `m4_m68k_probe.py:70`).
- 명세 `08_build/artifacts/m4p668/spec.json`: 바탕 `08_build/runs/tools/m0p667-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `sc`, 위 구간(`basis` 적음), `x86_rel` `machdep/i386/dkbad.c`. run `m4p668-p1`(REGISTRY 확인; `wait` 뒤 `collect` 없이 `compare`, `set -eo pipefail`), 기록 `m4-m68k-probe-p668-p1-20261101.json`, funcbytes `-p668-<변형>-`(이름 없는 16 의 대응은 위; `__data` 기준점 `0x40b202e=_scdriver`·`0x40b2060=_sc_scsw` 는 원본 기호, bss 기준점은 A1 배치가 원본 참조와 한 기준으로 맞을 때만).
- 측정: 종료 상태·경고, 함수별 길이·바이트·재배치 대상, 객체에만 있는 함수, 절(`__text` 4796·`__data` 62·`__cstring` 544 목표·`__bss` 8), `__data` 를 재배치 풀어 원본과, 문자열 내용·차례, 기호·COMMON·미정의. 차이가 나는 함수는 scratch `p658/fdiff658.py` 꼴의 도구로 원본과 견줌.

판정(미리 정함; 07 은 바꾸지 않음): A1(또는 A1B) 결과를 적고, 다른 함수마다 원본 바이트로 바뀜을 읽어 다음 진단을 세움. 17/17 이고 함수 밖 단언이 맞으면 바이트로 가려지지 않는 꼴을 구현 전에 여쭘.

### 668.1 교차검토(codex `gpt-6.1-sol`, task k1bl1ltwx) 판정과 계획 수정

먼저 제 잘못: ① 문자열 둘(`"dma error"`·`"scsi bus parity error during dma"`)을 "직접 참조 없음" 으로 적었으나 0x407b550·0x407b55c 의 `movel #` 로 참조됩니다(제 참조 수집이 `pea`·`lea` 만 보지 않았는데도 놓친 것은 숫자 꼴(`#67810265`)로 풀린 즉치를 뽑지 않았기 때문). ② `od.c` 의 끝을 `od_eject` 로 적었으나 NeXTMach 는 그 뒤에 `od_panel_abort`(5341 행) 등이 있음 — 경계 0x407aae0 은 그대로. ③ include 줄 수 31 → 30(python).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 17 항목·대응·크기, `__data` 62 B, 문자열 544 B, bss 넷 해석(NSC 1)이 맞음; bss 소유·크기는 추정으로 둠 | 이번 세션 python·`_scdriver`/`_sc_scsw` 풀이 | ✅ |
| 0x407aa4c–0x407aae0 은 `od.c` 함수(이름 없는 0x407aa5c 는 `od_dma_init` 로 보임) | NeXTMach `od.c` 5341 행 이후 읽음(`od_panel_abort` 등) | ⚖️ 경계는 이름 있는 `_odsize` 로 정해짐; 이름 없는 함수의 정체는 이 단위 밖 |
| 두 문자열이 0x407b550·0x407b55c 에서 참조됨; `_sc_s5c` 도 바깥 자료 목록에 | `sc.dis` 0x407b54c–0x407b55c | ✅ 위 ① |
| 바이트로 보이는 1997 차이: 게이트 어레이 제어 비트(0x02/0x00/0x20 대 NeXTMach 0x82/0x80/0xa0), `scsetup` 의 `dma_chip == 313` 갈래, `scprobe` 의 레지스터 주소 `&` 둘, `scstart`·`scdmastart` 의 정렬 거부 없음, `scgo` 의 `max(sd_timeout, 10)`, `scintr` 의 `s5c_dmastatus` 없음·313 이면 8 번 읽기, `scminphys` 의 313 이면 8192 아니면 65536 | — | ⏭️ A1 이 판정(사실관계는 진단 B 를 세울 때 원본 바이트로 다시 읽음) |
| A1 은 `scr.h` 를 빼면 `NeXT_CUBE`, `next/cpu.h` 를 `m68k/cpu.h` 로 바꾸면 `slot_id_bmap`·`I_SCSI_DMA`·`I_SCSI`·`I_IPL`·`I_BIT`·`P_SCSI_CSR`·`P_DISK` 가 모자람; 선례는 `fd_io.c:28–39`(이름 블록), `snd_dspdev.c:113`(`I_BIT`) | `sc.c` 에서 그 이름들의 쓰임을 python 으로 셈(`NeXT_CUBE` 3·`I_SCSI_DMA` 2·`I_SCSI` 3·`I_IPL` 1·`I_BIT` 1·`P_SCSI_CSR` 1·`slot_id_bmap` 1; `P_DISK` 는 `odreg.h` 쪽), 두 선례 줄을 읽음 | ✅ A1 에 그 블록을 넣음 |
| 단언을 §665–666 처럼 명시(절 목록·기호 자리·COMMON 크기·미정의·재배치 대상(점프 표 포함)·`__data` 재배치 풀어 전체·문자열 바이트·의존 출처·객체에만 있는 함수 없음) | `m4_m68k_probe.py:381` | ✅ scratch `p668/chk_p668.py`(17/17 일 때) |

계획 수정: 변형 A1 = include 바꿈 + `next/scr.h` 뺌 + 파일 안 이름 블록(`fd_io.c:29–39` 그대로 + `snd_dspdev.c:113` 의 `I_BIT`; 진단 표시). 그 밖은 NeXTMach 그대로.

2차 자기검사: ✅ 행은 이번 세션의 풀이·python 입니다.

### 668.2 결과(run `m4p668-p1`, 2026-11-01)

- A1(include 바꿈 + `next/scr.h` 뺌 + `fd_io.c` 꼴 이름 블록) 컴파일 종료 0·경고 0, 의존 i386 0(`m4-m68k-probe-p668-p1-20261101.json`). 절 `__text` 4668(원본 4796)·`__data` 62(재배치 11)·`__cstring` 566·`__bss` 8. bss 는 `old_s5c_state`(함수 안 static, 기호 `_old_s5c_state.44`) +0·`sc_bcp` +4 로 원본 0x40b4fc2·0x40b4fc6 과 한 기준으로 맞음(처음 판정 스크립트가 기호 이름의 `.44` 를 몰라 거짓으로 냄 — 제 잘못, 이름을 고쳐 기준점으로 씀).
- funcbytes(`m4-m68k-funcbytes-p668-A1-20261101.json`): **5/17**. 길이가 같고 바이트만 다른 넷(`sc_dostart`·`scfsm`·`scmsgin`·`screset`)은 거의 모두 `struct scsi_5390_ctrl` 의 자리 차이: 원본은 `mulsw #592`(A1 594), `s5c_cursdp` 이후 칸이 원본에서 2 B 앞(550/552 …). A1 의 STABS 로 뽑은 칸 자리와 원본의 칸 접근 수(python)를 견주면 +534–+549 칸은 쓰는 횟수까지 같고, A1 에만 +550 바이트 쓰기(`s5c_dmastatus` 저장, `sc.c:737`)가 한 번 있으며 그 뒤 칸은 모두 2 B 밀림 → 1997 `struct scsi_5390_ctrl` 에는 `u_char s5c_dmastatus`(07 `scvar.h:48`)가 없음(그 칸은 포인터 앞의 아홉째 바이트라, 빼면 정렬로 뒤가 정확히 2 B 앞당겨짐).

## 669. M4-174 조사 결과와 세부 계획 — `sc.c` 진단 B(1997 바뀜; 07 변경 없음; 코딩 전, 2026-11-01)

조사(원본 `sc.dis` 와 A1 풀이 scratch `p668/scA1.dis` 를 일반 도구 scratch `fdiff.py` 로 견줌; 원본 자리):
- ① `struct scsi_5390_ctrl` 에 `s5c_dmastatus` 없음(위). `scvar.h` 를 의존 목록에 가진 받아들인 객체는 `sd`(p664)·`st`·`sg`(p663)·`scsi`(p667)(python), 07 에서 `s5c_dmastatus` 는 머리 선언(`scvar.h:48`)에만 있음(python 바이트 검색; 07 에는 아직 `sc.c` 가 없음 — §669.1 에서 고침).
- ② 칩 제어 바이트: 원본 0x02(재설정)·0x00(멈춤)·0x20(보통)·0x30/0x38(DMA) — NeXTMach `S5RDMAC_NOINTRBITS` = `S5RDMAC_20MHZ`(0x80, `sc.c:101`) 이면 0x82·0x80·0xa0·0xb0/0xb8. → 1997 `S5RDMAC_NOINTRBITS` 는 0(이름·철자는 바이트가 정하지 않음).
- ③ `scsetup`(0x407adf8–0x407ae70): 클록 변환과 선택 시간 초과를 `dma_chip == 313` 이면 20 MHz, 아니면 25 MHz 로 계산(5000000/6250000, 나눗수 32768/40960 = `S5RCLKCONV_FACTOR` 4/5 × 8192) — `S5R_CLOCKFREQ`(`sc.c:103`, NeXTMach 20)가 `((dma_chip == 313) ? 20 : 25)` 꼴이면 `screg.h:119·129` 의 매크로가 원본처럼 접힐 것으로 봄.
- ④ `scprobe`: `probe_rb(&s5rp->s5r_cmd)`·`probe_rb(&s5rp->s5r_fifoflags)` 처럼 주소를 넘김(+3·+7, 0x407ac5a·0x407ac66); NeXTMach 368 행은 `&` 가 없음.
- ⑤ `scstart`: 버퍼 정렬 거부(`! DMA_BEGINALIGNED(sdp->sd_addr) ||`, `sc.c:547–551`)가 없음(링크 비트 검사만).
- ⑥ `scgo`: `sc_s5c[bc_ctrl].s5c_cursdp->sd_timeout` 과 10 중 큰 값으로 `scsi_expectintr`(0x407b11c·0x407b148–0x407b154; NeXTMach 679 행은 10 고정).
- ⑦ `scintr`: `s5c_dmastatus` 저장(737 행) 없음; 읽기 비우기 되풀이가 `dma_chip == 313` 이면 8 번, 아니면 1 번(0x407b1fe–0x407b23e; NeXTMach `DMA_ENDALIGNMENT / S5RDMA_FIFOALIGNMENT` = 4).
- ⑧ `scdmastart`: 정렬 거부(`! DMA_BEGINALIGNED(s5cp->s5c_curaddr)`, 1499–1502 행; 그 문자열 `"unaligned DMA segment"` 는 원본 커널 어디에도 없음 — python)가 없음.
- ⑨ `scminphys`(0x407bb0e–0x407bb28): 상한이 `dma_chip == 313` 이면 8192, 아니면 0x10000(NeXTMach `maxphys`).
- 그 밖(`scslave`·`scattach`·`scdmaintr`·`scmsgout`·`scioctl`)은 A1 에서 같고, `sc_dostart`·`scfsm`·`scmsgin`·`screset` 은 ①·② 로 설명됨.

방법(진단; 07 은 바꾸지 않음; scratch `p668/gen_p669.py` 가 A1 원천(SHA 단언)에서 만듦 → `08_build/artifacts/m4p669/`):
- 진단 머리 `diag669/scvar.h`: 07 `scvar.h` 사본에서 `s5c_dmastatus` 줄만 뺌(가드 `_SCVAR_` 그대로; 다른 경로라 스테이지 판에 가려지지 않음 — `sc.c` 앞의 머리가 `scvar.h` 를 먼저 들이는지 `-M` 으로 확인).
- 변형 B: A1 + `sc.c` 의 `#import <nextdev/scvar.h>` → `<diag669/scvar.h>`, ②(`#define S5RDMAC_NOINTRBITS 0`), ③(`#define S5R_CLOCKFREQ ((dma_chip == 313) ? 20 : 25)`), ④–⑨(⑤ 는 바깥 조건에서 정렬 항을 빼고 안쪽 `if (!DMA_BEGINALIGNED…) EPRINTF(…)` 도 뺌, ⑥ 은 지역 `s5cp`·`sdp` 를 첫머리에, ⑦ 은 `i < ((dma_chip == 313) ? 8 : 1)`, ⑨ 는 지역 `maxlen` 에 0x10000 을 두고 313 이면 8192). 바뀐 줄마다 `plan 669 diagnostic B`.
- run `m4p669-p1`(REGISTRY 확인; `wait` 뒤 `collect` 없이 `compare`, `set -eo pipefail`), 기록 `m4-m68k-probe-p669-p1-20261101.json`, funcbytes `-p669-B-`(§668 대응·기준점). 남는 함수는 `fdiff.py` 로 다시 읽음.

판정(미리 정함; 07 은 바꾸지 않음): 17/17 이고 함수 밖 단언(절·`__data` 재배치 풀어 원본과·문자열 544 B·기호·bss·COMMON·미정의·의존 출처)이 맞으면 구현 전에 여쭙니다 — 공유 07 `scvar.h` 에서 `s5c_dmastatus` 를 뺄지(그러면 `sd`·`st`·`sg`·`scsi` 를 다시 받아들임), ②·③·⑦ 의 이름·철자, ⑤ 의 꼴 등. 남는 함수가 있으면 다음 진단에서 고칩니다.

### 669.1 교차검토(codex `gpt-6.1-sol`, task k53lvzh80) 판정과 계획 수정

먼저 제 잘못: §669 ① 에 "`s5c_dmastatus` 를 쓰는 07 원천은 `sc.c` 뿐" 이라 적었으나 07 에는 아직 `sc.c` 가 없고, 그 이름은 머리 선언에만 있습니다(고침).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| ①–⑨ 가 원본 바이트와 맞고 17 함수에서 다른 차이는 없음(`scintr`·`scfsm`·`scmsgin` 점프 표 12/8/12 항목이 대응 블록을 가리킴, `scprobe` 는 차례가 아니라 크기·주소식 차이) | §668.2–§669 의 diff(이번 세션) | ⏭️ 진단 B 가 판정 |
| 클록 식은 `screg.h:119·129` 매크로 안에서 동적으로 둘 것(미리 계산한 상수로 바꾸면 갈래가 사라짐) | 계획이 이미 그 꼴 | ✅ |
| `scgo` 는 소문자 `max`(함수)가 아니라 `MAX` 매크로나 부호 있는 삼항; `scminphys` 의 지역은 부호 있는 `int` | 스테이지 `sys/param.h:275` `#define MAX(a,b) (((a)>(b))?(a):(b))`, `sc.c:49` 가 `sys/param.h` 를 들임 | ✅ B 는 `MAX(sdp->sd_timeout, 10)`, `int maxlen` |
| 진단 머리 바꿈이 통함(먼저 들이는 머리 없음) | A1 의 `-M` 출력 차례(이번 세션: `scvar.h` 는 151 번째, 앞 머리들의 import 목록에 없음) | ✅ B 의 의존 목록에서 진단 경로만 있고 스테이지 `nextdev/scvar.h` 가 없음을 단언 |
| 판정에 컴파일·의존 성공·경고 0·i386 0·선택지·객체에만 있는 함수 없음·재배치 대상(점프 표 포함) 같음을 명시, 해시에 묶음 | `m4_m68k_probe.py:381` | ✅ |
| 공유 머리를 바꾸게 되면 `sc_s5c` 를 할당하는 NeXTMach `scsiconf.c:95` 도 새 배치를 씀을 기록 | `scsiconf.c:93–96` 읽음 | ✅ M7 의무에 적음 |

2차 자기검사: ✅ 행은 이번 세션의 줄·풀이입니다.

### 669.2 결과(run `m4p669-p1`, 2026-11-01)

- B 컴파일 종료 0·경고 0, 의존 i386 0(`m4-m68k-probe-p669-p1-20261101.json`). funcbytes **17/17**(`m4-m68k-funcbytes-p669-B-20261101.json`, 재배치 대상 차이 0, 객체에만 있는 함수 없음).
- 단언(scratch `p668/chk_p668.py`; 기록 `m4-m68k-p669-diagchecks-20261101.json`, `ok`): 절은 `__text` 4796(재배치 173)·`__data` 62(11)·`__cstring` 544(0)·`__bss` 8(0) 넷뿐; `__data` 는 재배치 열하나(함수 여덟·`"sc"`·`"SEE bus_device"`·`sc_bcp`)를 풀면 원본 0x40b202e 의 62 B 와 같음; `__cstring` 544 B 가 원본과 바이트까지 같음; 바깥 정의 `_scdriver`·`_sc_scsw`·`_scminphys` 가 원본 자리, 지역 `__text` 16 이 원본 항목 시작, bss 지역 둘(`old_s5c_state` 0x40b4fc2·`sc_bcp` 0x40b4fc6); COMMON 14 원본 이름·크기 ≤ 간격; 미정의 37 모두 원본 이름; L1 사유 `__DATA,__bss: unverified` 하나·`full_span`; 의존 목록의 `scvar.h` 는 진단 사본만(스테이지 `nextdev/scvar.h` 없음), `screg.h`·`scsireg.h`·`scsivar.h` 는 스테이지 07.

판정(미리 정한 대로): 바이트로 가려지지 않는 꼴과 공유 머리 바꿈을 구현 전에 여쭙니다.

### 669.3 사용자 답(일부)과 공유 `scvar.h` 대안 조사(2026-11-01)

사용자 답(AskUserQuestion): `S5RDMAC_NOINTRBITS` 는 `S5RDMAC_10MHZ`(추천안 `0` 이 아님; 값 0x00 같음), 클록은 `S5R_CLOCKFREQ` 삼항 매크로(추천안), 비우기 되풀이는 "sc.c 안 매크로로"(추천안 루프 조건 삼항이 아님 — 확인 run 에서 바이트를 봄), 공유 `scvar.h` 는 "다른 방법을 먼저 검토".

조사(이번 세션, python):
- 참고 트리에서 같은 이름 찾기: `scvar.h` 는 NeXTMach `mk-108.1/nextdev/scvar.h` 와 그 07 사본뿐, `screg.h` 는 NeXTMach 둘과 07 사본; 1997 SDK 머리·Darwin 0.1 에는 `scvar.h` 도 `struct scsi_5390_ctrl`·`s5c_dmastatus` 도 없음(`grep -rlas` 0 건). 1997 배치의 글 근거는 원본 바이트뿐.
- `scvar.h` 를 들이는 받아들인 넷(`sd`·`st`·`sg`·`scsi`)의 쓰임: `sc_s5c[0].s5c_state` 를 `XDBG`/`XSDBG` 디버그 매크로 안에서만 씀(`sd.c:1106`, `st.c:665`, `sg.c:288`, `scsi.c:387·406·448·506`)과 `extern struct reg_values s5c_state_values[]` 선언뿐 — 디버그가 꺼진 빌드에서는 코드가 없고, `s5c_state`(+542)는 빠질 칸(+550)보다 앞. 그러니 칸을 빼도 네 객체의 코드·자료 바이트는 그대로이고 디버그 정보(STABS 의 형)만 바뀜(§663 과 같은 처지).

대안:
- A. 공유 07 `scvar.h` 에서 `s5c_dmastatus` 를 빼고 `sd`·`st`·`sg`·`scsi` 를 다시 받아들임(§649·§663 의 절차; 넷은 canon·`obj_sig` 의 header·sections·symbols 가 같고 STABS 수만 다를 것). 트리 안 `struct scsi_5390_ctrl` 정의가 하나로 남고, `sc_s5c` 를 할당할 `scsiconf.c`(NeXTMach `scsiconf.c:95`)도 같은 배치를 씀.
- B. 공유 `scvar.h` 는 NeXTMach 그대로 두고 `sc.c` 전용 1997 사본(다른 경로)을 둠 — 다시 받아들일 객체는 없으나 같은 이름의 구조체가 두 배치로 공존(`sc_s5c` 의 정의 객체가 어느 쪽을 쓰느냐에 따라 형이 어긋남; M7 에서 합칠 때 문제가 될 수 있음).
- C. 공유 머리에 조건부(`#if` 로 칸을 감춤) — 머리가 바뀌므로 다시 받아들이기는 A 와 같고, 프로젝트 매크로가 하나 늚.
- D. 받아들인 네 원천에서 "debug only" import 를 빼서 의존을 끊음 — 그 원천들이 바뀌므로 역시 다시 받아들여야 하고, 바이트가 정하지 않은 바뀜이 늚.
- E. `sc.c` 를 이번에는 받아들이지 않고 미룸.

제 추천은 A 입니다(정의가 하나로 남고, 다시 받아들이기는 바이트가 같을 것으로 정해진 기계적 절차). 비우기 되풀이 매크로 이름도 함께 여쭙니다.

## 670. M4-175 D155 구현 계획 — 공유 07 `scvar.h`(1997 `scsi_5390_ctrl`), 07 `sc.c`, `sd`·`st`·`sg`·`scsi`(와 기록을 함께 쓰는 `autoconf`) 다시 받아들이기(코딩 전, 2026-11-01)

사용자 결정(D155 로 적을 것; AskUserQuestion 세 번): ① 공유 07 `nextmach/nextdev/scvar.h` 에서 `u_char s5c_dmastatus` 를 빼고 그 머리를 쓰는 받아들인 객체를 다시 받아들임(대안 조사 §669.3 뒤의 답, 추천안 A) ② `S5RDMAC_NOINTRBITS` 는 `S5RDMAC_10MHZ`(추천안 `0` 이 아님) ③ `S5R_CLOCKFREQ` 는 `((dma_chip == 313) ? 20 : 25)`(추천안) ④ 비우기 되풀이는 파일 안 `#define S5RDMA_FLUSHCOUNT ((dma_chip == 313) ? 8 : 1)` 과 `i < S5RDMA_FLUSHCOUNT`(추천안 루프 조건 삼항이 아님) ⑤ `scgo` 는 `MAX(sdp->sd_timeout, 10)`(추천안) ⑥ `scstart` 의 정렬 검사는 바깥 항과 안쪽 `EPRINTF` 둘 다 지우고 표시(추천안). 앞선 결정·선례 그대로: include OPENSTEP 경로(D104·D110·D113), NeXTMach `next/cpu.h`·`next/scr.h` 이름은 파일 안 블록(`fd_io.c:29–39`·`snd_dspdev.c:113` 꼴, D113·D121), `next/scr.h` import 는 지움(`autoconf.c`·`fd_io.c` 선례). 바이트가 정한 것: §669 ①–⑨, NSC 1(`sc_bcp` 4 B).

1. 07 `nextmach/nextdev/scvar.h`(scratch `p668/gen_p670h.py --write`; 바꾸기 전 SHA 단언): 48 행 `s5c_dmastatus` 줄을 지우고 그 자리에 표시 주석(`plan 670 (D155)`); 진단 사본 `m4p669/incB/diag669/scvar.h` 와 주석을 뺀 토큰이 같음 단언.
2. 07 `src/machdep/m68k/sc.c`(scratch `p668/gen_p670.py --write`): NeXTMach `sc.c`(SHA `0ea59566…`) + 머리 주석 덩이 + include(표시 `plan 670`) + 이름 블록 + ②–⑥ + §669 ④–⑨ 의 나머지(`scprobe` `&` 둘, `scdmastart` 정렬 검사 없음, `scintr` 의 `s5c_dmastatus` 저장 없음, `scminphys` 의 `int maxlen`). 단언: 진단 B 와 토큰이 같음(바뀌는 곳은 import 경로·`S5RDMAC_NOINTRBITS` 값 토큰·`S5RDMA_FLUSHCOUNT` 정의와 루프 조건뿐 — 대응을 정해 바꾼 뒤 같음); L(`08_build/artifacts/m4p670/src/sc_L.c`)과 F 의 토큰·토큰 줄 같음; 표시 없는 바뀐 줄 0.
3. 구성: `config_options-m68k.tsv` 의 `sc NSC` 행 `hypothesis` → `confirmed`(근거: `sc_bcp[NSC]` 4 B = 0x40b4fc6–0x40b4fca, `_scdriver` 가 가리킴); 생성 `sc.h` 그대로(`--check` 둘 종료 0).
4. `stage_m68k.py`: `M4FILES[670] = list(M4FILES[667]) + ['sc.c']`, `EXCEPTS[670] = dict(EXCEPTS[667])`, 머리말 목록(`M4HEADERS` 그대로 — `scvar.h` 는 이미 `nextdev/scvar.h` 로 스테이징).
5. 회귀: `--plan 667` 재생성(`m0p667-r670-stage`)은 보관본과 `src/bsd/nextdev/scvar.h` 해시 하나만 다름; `m0p670-a1-stage` 는 그것과 `sc.c` 만(키 `files`·`m4_sources`·`plan`); `m5-667.cmd` 보관본과 같음, `m5-670.cmd` 는 계획 번호만; M5 205(`m3p670-b667` 보관 667 스테이지·`--plan 667 compare`, `m3p670-cc1`·`--plan 670`) 객체·출력 같음; x86 입력(`L2_*` s6p398) `ok`·`--plan 670 x86gate` 일곱 같음.
6. 확인 run `m4p670-p1`(명세 `08_build/artifacts/m4p670/confirm/spec.json`, 바탕 `m0p670-a1-stage`): 객체 여섯 — `sc`(F, L), `sd`·`st`·`sg`·`scsi`(F, L = 각 단위의 L 텍스트), `autoconf`(F, L = `m4p526/src/autoconf_L.c`). 판정: 종료 0, 경고는 `sd` 11 줄(그 known_warnings 와 같은 글)·나머지 0, i386 0; funcbytes `sc` 17·`sd` 42·`st` 26·`sg` 14·`scsi` 15·`autoconf` 11; F = L(canon·`obj_sig`); `sc` F 와 진단 B 객체는 canon 같음과 `obj_sig` 의 header·sections·symbols 같음; 다시 받아들이는 다섯은 앞 객체(`sd`·`autoconf` §664, `st`·`sg` §663, `scsi` §667)와 canon 같음·`obj_sig` 는 `stabs` 수만 다름; 머리 출처는 스테이지 07(`scvar.h` 새 SHA); `sc` 의 함수 밖 단언 `chk_p668.py`(F·L, `scvar` 출처 07). `-E` run `m4p670-e2`(`sc` F·L, 다섯 F·L; `EXPECT`): 토큰 F = L, stderr 0, i386 0.
7. 최종 run 둘(바탕 같음): `m4p670-a1`(명세 `08_build/artifacts/m4p670/spec.json`, `st`·`sg`, `refs` = p1 L) → OBJECT_MATCH; `m4p671-a1`(명세 `08_build/artifacts/m4p671/spec.json`, `autoconf`·`sd`·`scsi`·`sc`, `bss_inferred` 넷, `known_warnings` 는 `sd` 의 p1 F stderr 그대로) → `provisional`. zerofill `objs`(기록 `m4-m68k-zerofill-p671-20261101.json`, 출력 `08_build/artifacts/m4p671/zerofill`): `autoconf`·`sd`·`scsi` 는 REF = 앞 받아들인 객체, `sc` 는 REF = p1 L; 모두 `reference-inferred(-single)`, 후보는 앞과 같고 `sc` 는 [0x40b4fc2, 0x40b4fca); 남은 받아들인 bss 자리 모두와 겹침 없음(python). 확인 기록 `m4-m68k-p670-checks-20261101.json`·`m4-m68k-p671-checks-20261101.json`.
8. 상태: `ACCEPTED` 에서 §663(st·sg)·§664(autoconf·sd)·§667(scsi) 튜플을 빼고 §670(두 칸)·§671(네 칸) 을 넣음 — `sd` 가 `autoconf` 와 같은 기록에 있어 둘을 함께 옮김. 근거 `m68k-sc.md`·`m68k-sc.diff`·`m68k-scvar_h.diff`(새), `m68k-sd.md`·`m68k-st.md`·`m68k-sg.md`·`m68k-scsi.md`·`m68k-autoconf.md` 에 plan 670 절. 상태 도구 두 번, 기대(python): 객체 57(OBJECT_MATCH 45, CODE+BSS_INFERRED 12), 행 78/188, 78566 B(36.39%) 그대로, `object_bytes` 119454.
9. 기록: PROVENANCE(`scvar.h` nextmach → nextmach+authored·새 SHA, 새 `sc.c`, 생성 `sc.h` 행 상태, `sd.c`·`st.c`·`sg.c`·`scsi.c`·`autoconf.c` 행에 재수락), MODIFICATIONS, DECISIONS D155, 계획·HANDOFF·메모리. M7: `sc_s5c`·`sc_sc`·`sf_access_head` 의 정의(NeXTMach `scsiconf.c:93–96`, 새 `scvar.h` 배치), COMMON 합침, 정적 bss 자리, 호출 대상들.

관문: 명령 종료 0, 경고 기준, i386 0, 회귀 같음, 확인·`-E`·최종·zerofill·확인 기록 `ok`, 상태 도구가 기대와 같음. 하나라도 어긋나면 07 `scvar.h` 를 바꾸기 전 사본으로 되돌리고 알립니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 670.1 교차검토(codex `gpt-6.1-sol`, task kbcri2akx) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `scvar.h` 를 의존 목록에 가진 받아들인 객체는 정확히 `sd`(p664)·`st`·`sg`(p663)·`scsi`(p667); `autoconf` 는 소비자가 아니나 `sd` 와 같은 기록이라 함께 옮김; 뺄 튜플은 p663·p664·p667 | 이번 세션 python(같은 조사, §669.3) | ✅ |
| 상태 기대 57·45·12·78/188·78566·36.39%·119454; 부분 행에 `m68k-235`·`m68k-236` 이 더해짐 | python(§670 앞) | ✅ 기대에 부분 행 둘을 더함 |
| 회귀 설계·`--plan` 번호·x86 이 맞음 | §663·§667 선례 | ✅ |
| 앞 객체 비교(canon + header·sections·symbols, `stabs` 는 달라도 됨)와 `sc` F 대 B 비교가 충분; F/L·최종/REF 는 `obj_sig` 전부 같아야 함 | §663.1 과 같은 기준 | ✅ |
| `sd` 의 `known_warnings` 는 stderr 17 줄 그대로 | §663.2(p1 F stderr 17 줄) | ✅ |
| 최종 명세 둘 모두 새 p1 L 을 REF 로; zerofill REF 는 앞 객체 가능 | `m5_m68k_zerofill.py:137`(STABS 수 제외) | ✅ |
| §663·§667 에서 최종 기록의 `options` 가 빈 일을 되풀이하지 말 것 | §663.2 ③·§667 | ✅ 최종 명령 파일을 명세 폴더의 `probe.cmd` 로 만들어 probe 가 `probe.cmd.opts.json` 을 읽게 함 |

2차 자기검사: ✅ 행은 이번 세션의 python·기록입니다.

### 670.2 결과(2026-11-01)

먼저 제 잘못과 계획과 다르게 한 점: ① 1 단계의 `p668/gen_p670h.py` 를 따로 만들지 않고 `scvar.h` 바꿈을 `p668/gen_p670.py` 하나에 넣음(바꾸기 전 SHA 단언·진단 사본과 토큰 같음 단언은 그대로). ② 최종 확인 스크립트에 `autoconf` 의 핵심 07 머리 수 기대를 1 로 잘못 적어 첫 실행이 거짓으로 나옴 — `autoconf.c` 는 `scsireg.h`·`scsivar.h` 둘을 들임(52 행 등); 미리 정한 관문(의존 SHA 사슬에 문제 없음)이 아니라 제 스크립트의 기대값이라 2 로 고쳐 다시 돌림. ③ 현재 상태 줄(799 행)의 "reference-inferred 9" 가 §667 앞부터 맞지 않던 옛 수였음(45 + 9 ≠ 56) — 상태 도구 값 12 로 고침.

- 1–2 07 `nextmach/nextdev/scvar.h` 95 행(48 행 → 표시 주석, SHA `b011e3d2…`), 07 `src/machdep/m68k/sc.c` 1794 행(SHA `b45e01a7…`; NeXTMach 머리 주석 끝(40 행) 뒤에 머리 주석 덩이), L `08_build/artifacts/m4p670/src/sc_L.c`(`13e90425…`). 단언: 진단 B 와 토큰이 `S5RDMAC_NOINTRBITS` 값·`S5RDMA_FLUSHCOUNT` 정의와 루프 조건만 다름, F = L 토큰·토큰 줄, 표시 없는 바뀐 줄 0.
- 3 구성 `sc NSC` 행 `confirmed`(`wc -l` 21 행 그대로 — §674.1 에서 고침: 22 는 끝 빈 조각까지 센 수), `gen_config_headers.py --check`(m68k·x86) 종료 0. 4 `stage_m68k.py` 761 → 763 행.
- 5 회귀: `--plan 667` 재생성(`m0p667-r670-stage`, 998)은 보관본과 `src/bsd/nextdev/scvar.h` 하나만(키 `files`), `m0p670-a1-stage`(999)는 그것과 `sc.c` 만(키 `files`·`m4_sources`·`plan`). `m5-667.cmd` 보관본과 같고 `m5-670.cmd` 는 411/412 줄이 계획 번호만. M5 205(`m3p670-b667`·`m3p670-cc1`) 접두어를 맞추면 객체·출력 모두 같음(`run.json` 만), `m3p670-b667` 은 `m3p667-cc1` 과 같음; `compare` 둘 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 `sc.c` 뿐. x86 `m4-x86-inputs-p670-20261101.json` `ok`(p667 과 같음), `--plan 670 x86gate` 는 p667 과 `plan`·도구 해시만 다름.
- 6 확인 run `m4p670-p1`(`m4-m68k-p670-p1checks-20261101.json` `ok`): 여섯 객체 F·L 모두 함수 바이트 같음(`sc` 17·`sd` 42·`st` 26·`sg` 14·`scsi` 15·`autoconf` 11), 경고는 `sd` 11 뿐, i386 0, F = L; `scvar.h` 는 다섯 사용자 모두 스테이지 07(새 SHA); `sc` F 와 진단 B 객체가 canon·`obj_sig` 전부 같음(②·④ 의 꼴이 바이트로 같음); 다시 받아들이는 다섯은 앞 객체와 canon·`obj_sig` header·sections·symbols 같음(STABS 수는 `scsi` 만 953 → 952); `chk_p668.py` F·L `ok`. `-E` `m4p670-e2`(`ok`): 여섯 F = L(`sc` 19473, `sd` 27658 → 27655·`scsi` 11645 → 11642 토큰 — 빠진 `u_char s5c_dmastatus ;` 셋), stderr 0, `s5c_dmastatus` 토큰 0.
- 7 최종 run `m4p670-a1`(`st`·`sg`, `m4-m68k-p670-final-20261101.json` SHA `87ac3d78…`)·`m4p671-a1`(`autoconf`·`sd`·`scsi`·`sc`, `m4-m68k-p671-final-20261101.json` SHA `62263642…`): 둘 다 `gate.ok`, 기록의 `options` 가 채워짐(명령 파일을 명세 폴더의 `probe.cmd` 로). funcbytes 모두 같음. zerofill(`m4-m68k-zerofill-p671-20261101.json`, SHA `91f08d15…`): 넷 `reference-inferred`, `autoconf`·`sd`·`scsi` 후보는 §664·§667 과 같고 `sc` 는 [0x40b4fc2, 0x40b4fca); 빼는 두 기록을 뺀 남은 받아들인 자리 12 와 겹침 없음. 확인 `m4-m68k-p670-checks-20261101.json`·`m4-m68k-p671-checks-20261101.json` `ok`(의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지). `sc` 객체 SHA `20c5b154…`.
- 8 상태(`m4-m68k-status-p670-20261101.json`, 표 58 → 59 행; scratch 에 두 번 같음): 객체 57(OBJECT_MATCH 45, CODE+BSS_INFERRED 12), 행 78/188, 78566 B(36.39%), `object_bytes` 119454, 부분 행에 `m68k-235`·`m68k-236` 이 더해짐 — 미리 계산한 값과 같음. 근거 `m68k-sc.md`·`m68k-sc.diff`·`m68k-scvar_h.diff`, 다섯 근거 문서에 plan 670–671 절.
- 9 기록: PROVENANCE 1213 → 1214 행(일곱 칸, 겹침 없음; `scvar.h` `nextmach+authored`), MODIFICATIONS 750 → 752, DECISIONS D155(158 → 159 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D155).

## 672. M4-176 세부 계획 — m68k `zscom.c`(행 258·259 일부) 진단 A1(07 변경 없음; 코딩 전, 2026-11-01)

고른 까닭: 남은 행 가운데 NeXTMach 글이 바로 있고 이름이 모두 풀리는 가장 작은 단위입니다(행 258 `nextdev/zscom.c`, 이름 4/4; 정확한 행이 아님). 큰 단위(`od.c` 행 234 24544 B, `km.c` 행 223·226, `zs.c` 행 256, `if_en.c` 행 260, `pmap.c` 행 310–312)는 뒤로 둡니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p672/zscom.dis`(scratch `odis.py`, 원본 바이트); 수는 python):
- 범위 [0x408d706, 0x408d9aa) 676 B, 다섯 항목 모두 외부 이름: `_zsacquire` 56·`_zsrelease` 94·`_zsint` 232·`_zsnullintr` 76·`_zsintsetup` 218 — NeXTMach mk-108.1 `nextdev/zscom.c`(159 행, SHA-256 `08885e0c…`, ASCII)의 다섯 함수(33·45·59·114·123 행)와 차례가 같음. 앞 0x408d686 `_zstrygetc` 는 NeXTMach 에 없는 이름(`zs.c` 쪽으로 봄), 뒤 0x408d9aa·0x408d9d4 의 이름 없는 둘은 `if_bus.c` 의 정적 `enbuf_put`(`splimp` 꼴, `en_bufs` 0x40b244a·`enbuf_free` 0x40b2452 를 씀)·`enbuf_alloc`(NeXTMach `nextif/if_bus.c:41·53`).
- 구간: `span()` 은 `{"range": ["0x408d706", "0x408d9aa"], "rows": [], "partial": ["m68k-258", "m68k-259"], …}` 를 받음(python 시험: `partial` 이 258 만이면 259 때문에, 257 을 더하면 257 때문에 멈춤). 덮은 행·바이트는 그대로.
- 자료: `__data` [0x40b242e, 0x40b244a) 28 B = `_zi_null`(12 B, 0x408d884 `zsnullintr` 셋) + `_zs_com`(16 B, `{0, &zi_null}` 둘) — NeXTMach 26–30 행과 같은 꼴. 앞 0x40b2422 의 포인터 셋은 `zs.c` 쪽, 뒤 0x40b244a 부터는 `if_bus.c` 자료. bss·문자열 없음(문자열 참조 없음; `XDBG` 는 `notdef`, `ASSERT` 는 끔).
- 참조(원본 기호): `_slot_id_bmap` 0x40c32f8, `_dma_chip` 0x40c32d0, `_delay` 0x409237a, `_machine_type` 0x40b61ac(`tstb`), `_board_rev` 0x40c6ecc(`moveb`), `_console_i`·`_console_o`, `_install_polled_intr` 0x4065f50(인수 0x1150 = `I(5,0,17)` = NeXTMach `next/cpu.h:240` `I_SCC`).
- 바이트로 보이는 1997 차이(A1 이 판정): ① `zsrelease` 가 두 저장 앞에서 `zsnullintr` 와 같은 꼴로 채널 레지스터 1 에 0 을 씀(`ZSWRITE`, unit 0 이면 `P_SCC+1`) ② `zsintsetup` 첫머리에서 `slot_id_bmap + 0x2018004`(NeXTMach `next/cpu.h:161` `P_SCC_CLK`)에 `dma_chip == 313` 이면 0x0a, 아니면 0x30 을 씀(SDK `architecture/m68k/zsreg.h` 의 `PCLK_10_MHZ` 0x30, 0x0a = `PCLK_3684_MHZ|SCLKB_4_MHZ|SCLKA_4_MHZ` — NeXTMach `zs.c:783` 의 값). 나머지 셋은 NeXTMach 꼴로 보임(`zsint` 의 비트 차례 3·0·5·2·4·1, `console_*` 검사는 범위 비교로 접힘).
- 머리: NeXTMach import 9 줄(6–16 행). 스테이지(`m0p670-a1-stage`)에 없는 것: 생성 `zs.h`(구성 행 없음; NeXTMach `conf/MASTER.next:166` `pseudo-device zs 2`), NeXTMach 전용 `nextdev/zscom.h`, `nextdev/zsreg.h`(1997 SDK 는 `architecture/m68k/zsreg.h` 가 스테이지에 있으나 그것이 들이는 `architecture/zs85C30.h` 가 스테이지에 없음 — 실기 목록 `s4c-nextdev-headers-20261002.json` 에 SHA-256 `9ee61ac3…` 로 있고, `01_resources` 로컬 미러 사본이 같은 SHA), `next/scr.h`. `next/cpu.h` 의 이름 가운데 SDK `m68k/cpu.h` 에 있는 것은 `machine_type`·`board_rev`(`u_char`)·`dma_chip`(`u_short`); `SLOT_ID_BMAP`·`P_SCC`·`I()`·`I_SCC`·`NeXT_CUBE` 는 선례대로 파일 안 블록(D110·D113·D121; SDK `architecture/m68k/intr.h` 에도 `I()`·`I_SCC` 가 있으나 받아들인 07 파일 가운데 쓰는 것이 없음).

방법(진단; 07 은 바꾸지 않음; scratch `p672/gen_p672.py` → `08_build/artifacts/m4p672/`):
- 변형 A1: NeXTMach `zscom.c` + include 바꿈 — `next/cpu.h` → `m68k/cpu.h` + 파일 안 이름 블록, `next/scr.h` 뺌, `nextdev/zsreg.h` → `architecture/m68k/zsreg.h`(SDK; D104), `next/spl.h` → `machine/spl.h`(§657 선례). 진단 `inc`: `zs.h`(`#define NZS 2`, MASTER 값), `nextdev/zscom.h`(NeXTMach 사본), `architecture/zs85C30.h`(실기 목록과 SHA 가 같은 미러 사본). 그 밖은 NeXTMach 그대로. 바뀐 줄마다 진단 표시.
- 명세 `08_build/artifacts/m4p672/spec.json`: 바탕 `m0p670-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `zscom`, 위 구간(`basis` 적음), `x86_rel` `machdep/i386/dkbad.c`. run `m4p672-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`, `set -eo pipefail`), 기록 `m4-m68k-probe-p672-p1-20261101.json`, funcbytes `-p672-A1-`(이름이 모두 있어 대응표 없음, `__data` 기준점 `0x40b242e=_zi_null`·`0x40b243a=_zs_com`).
- 측정: 종료·경고, 함수별 바이트·재배치 대상, 객체에만 있는 함수, 절(`__text` 676·`__data` 28 목표, `__cstring`·`__bss` 없음), `__data` 를 재배치 풀어 원본과, 기호·COMMON(D136)·미정의, 의존 머리 출처(i386 0).

판정(미리 정함; 07 은 바꾸지 않음): 컴파일이 안 되면 원인을 적고 최소 고침의 새 변형을 새 run 으로. 되면 다른 함수마다 원본 바이트로 바뀜을 읽어 진단 B 를 세움. 5/5 이고 함수 밖 단언이 맞으면 바이트로 가려지지 않는 꼴(①·② 의 쓰는 꼴과 이름, `zs.h` 구성 값, `zscom.h`·`zs85C30.h` 를 07 에 두는 자리)을 구현 전에 여쭙니다.

### 672.1 교차검토(codex `gpt-6.1-sol`, task kqasuqihj) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 다섯 함수 크기 56·94·232·76·218(합 676), `__data` 28 B 의 일곱 낱말 `{zsnullintr ×3, 0, &zi_null, 0, &zi_null}`, 0x408d9aa 는 `enbuf_put` 꼴(이름은 추정) | python 크기 계산·원본 `__data` 덤프(이번 세션), `m68k-functions.tsv:3071`, `odis` 0x408d9aa–0x408d9d2 | ✅ |
| 1997 차이 둘(`zsrelease` 의 레지스터 1 쓰기, `zsintsetup` 첫머리 클록 바이트 쓰기 0x0a/0x30)과 나머지 셋이 NeXTMach 와 같은 동작; `zsint` 비트 3·0·5·2·4·1 이 A/B 상태·수신·송신 | `zscom.dis` 와 SDK `zs85C30.h:67–72`, NeXTMach `zscom.h:14–22` | ✅ |
| A1 은 계획한 include 로 컴파일될 것: `slot_id_bmap` extern 과 `P_SCC` 가 필요(`zsreg.h:29–30`), `IPLSCC`·`splscc` 는 `kernserv/m68k/spl.h:88·101`, `MACH_ASSERT 0` 이면 `ASSERT` 가 빔(`generated/mach_assert.h:1`, `kern/assert.h:65`), `intr.h` 는 닿지 않음 | 줄을 열어 확인; `zscom.c` 가 `kern/assert.h` 까지 닿는지는 확인 못 함 | ⚖️ 줄 인용은 맞음; 닿는지와 컴파일 여부는 A1 의 `-M`·종료로 판정(호스트 전처리는 근거로 쓰지 않음) |
| 스테이지에 `zs.h`·`zscom.h`·`zs85C30.h` 없음 → 진단 사본이 가려지지 않음; 미러 SHA 가 실기 목록과 같음(`s4c…json:3360–3362`) | `find`(이번 세션), 그 줄 열어 봄, python SHA | ✅ |
| 판정 문구: A1 은 바뀐 두 함수를 그대로 두므로 676 B·5/5 는 A1 의 기대가 아니라 목표; `__bss` 와 함께 자기 `__common` 도 없어야 함; B 에서 바이트 쓰기 너비·지연 차례·클록 쓰기 위치를 지킬 것; NZS 2 는 가설(`zscom.c` 가 들이기만 함) | 계획 본문(A1 기대 문구), D136(공유 머리의 COMMON 은 이름이 원본에 있으면 통과) | ⚖️ A1 기대를 3/5(`zsacquire`·`zsint`·`zsnullintr`)로 적음; COMMON 은 "없음" 이 아니라 D136 규칙(이름이 원본에 있고 크기 ≤ 원본 기호 간격)으로 봄 — codex 안을 받으면 미리 정한 규칙을 바꾸는 것이라 받지 않음; 나머지는 받음 |

계획 수정: A1 기대 = 컴파일 0·경고 0, 3/5(`zsrelease`·`zsintsetup` 은 짧음), `__text` 는 676 보다 작음, `__data` 28 B 가 재배치 풀어 원본과 같음, `__cstring`·`__bss` 없음, COMMON 은 D136, 의존 목록에 `zs.h`·`zscom.h`·`zs85C30.h` 는 진단 사본, i386 0.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 출력입니다.

### 672.2 결과(run `m4p672-p1`, 2026-11-01)

- A1 컴파일 종료 0·경고 0, 의존 146(i386 0; `zs.h`·`nextdev/zscom.h`·`architecture/zs85C30.h` 는 진단 사본, `zsreg.h` 는 실기 SDK, `kern/assert.h` 를 거치나 `MACH_ASSERT 0`)(`m4-m68k-probe-p672-p1-20261101.json`). 절 `__text` 580(원본 676)·`__data` 28 둘뿐.
- funcbytes(`m4-m68k-funcbytes-p672-A1-20261101.json`): **3/5** — `zsacquire`·`zsint`·`zsnullintr` 같음, `zsrelease` 32(원본 94)·`zsintsetup` 184(원본 218) 짧음. 예측(§672.1)과 같음.
- 함수 밖 단언(scratch `p672/chk_p672.py`; 기록 `m4-m68k-p672-diagchecks-20261101.json`, `ok`): `__data` 는 재배치 다섯(`zsnullintr` 셋·`&zi_null` 둘)을 풀면 원본 0x40b242e 의 28 B 와 같음; 바깥 정의 일곱(함수 다섯·`_zi_null`·`_zs_com`, 자료 둘은 원본 자리); 지역 없음; COMMON 일곱(`_alert_key`·`_km`·`_km_coni`·`_master_cpu`·`_tthiwat`·`_tthog`·`_ttlowat`, 공유 머리에서 옴) 모두 원본 이름·크기 ≤ 간격(D136); 미정의 일곱 모두 원본 이름.

## 673. M4-177 세부 계획 — `zscom.c` 진단 B(1997 바뀜 둘; 07 변경 없음; 코딩 전, 2026-11-01)

조사(원본 `zscom.dis`, A1 풀이; 원본 자리):
- ① `zsrelease`(0x408d73e–0x408d79c): `zcp = &zs_com[unit]`(a4)을 먼저 구하고, unit 0 이면 `P_SCC+1`(`ZSADDR_A`), 아니면 `P_SCC`(`ZSADDR_B`)를 a3 에 두고 `DELAY(1); *zsaddr = 1; DELAY(1); *zsaddr = 0`(SDK `ZSWRITE(zsaddr, 1, 0)`, `zsreg.h` 의 매크로), 그 뒤 `zc_user = ZCUSER_NONE`·`zc_intrsw = &zi_null`. `zsnullintr`(NeXTMach 114–120 행)의 몸통과 같은 꼴.
- ② `zsintsetup`(0x408d8d8–0x408d8fa; §673.1 에서 끝을 고침): 첫머리에서 `*(u_char *)(slot_id_bmap + 0x02018004)` 에 `dma_chip == 313` 이면 0x0a, 아니면 0x30 을 쓰고 그 뒤 `install_polled_intr(I_SCC, zsint)`. NeXTMach `next/cpu.h:161` `P_SCC_CLK`, SDK `zsreg.h` 의 `PCLK_10_MHZ`(0x30)·`PCLK_3684_MHZ|SCLKB_4_MHZ|SCLKA_4_MHZ`(0x0a; NeXTMach `zs.c:783·1609` 의 꼴).

방법(진단; 07 은 바꾸지 않음; scratch `p672/gen_p673.py` 가 A1 원천(SHA 단언)에서 만듦 → `08_build/artifacts/m4p673/`):
- 변형 B: A1 + 이름 블록에 `#define P_SCC_CLK (SLOT_ID_BMAP+0x02018004)`(NeXTMach `next/cpu.h:161` 그대로), ① `zsrelease` 에 지역 `register volatile struct zsdevice *zsaddr;` 와 `zsaddr = (unit == 0) ? ZSADDR_A : ZSADDR_B; ZSWRITE(zsaddr, 1, 0);` 를 두 저장 앞에(`zsnullintr` 꼴), ② `zsintsetup` 의 `install_polled_intr` 앞에 `*(u_char *) P_SCC_CLK = (dma_chip == 313) ? PCLK_3684_MHZ | SCLKB_4_MHZ | SCLKA_4_MHZ : PCLK_10_MHZ;`(NeXTMach `zs.c:783` 의 쓰기 꼴). 바뀐 줄마다 `plan 673 diagnostic B`. 같은 `inc`.
- run `m4p673-p1`(REGISTRY 확인), 기록 `m4-m68k-probe-p673-p1-20261101.json`, funcbytes `-p673-B-`, 단언 `chk_p672.py`(`__text` 676, 5/5, L1 `OBJECT_MATCH`·`full_span`).

판정(미리 정함; 07 은 바꾸지 않음): 5/5 이고 단언이 맞으면 바이트로 가려지지 않는 꼴을 구현 전에 여쭙니다 — ② 의 쓰는 꼴(삼항·`if`/`else`)과 값 이름(SDK 이름 조합 또는 숫자), `P_SCC_CLK` 이름, ① 의 꼴, 생성 `zs.h` 의 `NZS` 값(바이트가 보이지 않음; MASTER 2), `zscom.h`(NeXTMach 사본 → 07 `nextmach/nextdev/`)·`zs85C30.h`(실기 사본 → 07 `nextdev/architecture/`, `M4HEADERS` 뿌리 `07_kernel/nextdev`, §535 `video.h` 선례) 자리. 남는 함수가 있으면 원본 바이트로 다시 읽어 다음 변형(새 run ID).

### 673.1 교차검토(codex `gpt-6.1-sol`, task kl6as9bca) 판정과 계획 수정

먼저 제 잘못: ② 의 구간 끝을 0x408d8f6 으로 적었으나 그 자리는 마지막 바이트 저장의 시작이고, 끝(배타)은 0x408d8fa 입니다(고침).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `zsrelease`: 0x408d750 에서 `zcp` 를 a4 로 먼저, 0x408d754 `bne` 는 0x408d746 의 `movel` 플래그를 씀(`lea` 는 플래그를 바꾸지 않음), 주소 a3·`&delay` a2(0x408d774), 바이트 저장 0x408d77c·0x408d786 뒤에 두 저장; A1 의 첫 초기화 꼴을 두고 선언을 문장 앞에 | `zscom.dis` 그 줄들 | ✅ B 는 A1 의 `zcp` 초기화를 그대로 두고 `zsaddr` 선언을 그 뒤, 문장 앞에 둠 |
| `zsintsetup`: a0·a1·0x30 먼저·`cmpiw #313`·같으면 0x0a·바이트 저장(0x408d8d8–0x408d8f6); 삼항이 거짓 값을 먼저 싣는 꼴과 맞음; `if/else` 등은 같을 수도 다를 수도; `volatile` 여부는 바이트로 안 보임 | `zscom.dis`; SDK `m68k/cpu.h:48` `u_short dma_chip` | ✅(꼴이 바이트로 가려지는지는 B 이후 여쭐 때 변형으로 봄) |
| 클록 쓰기 일곱 명령 6+6+4+8+2+4+4 = 34 B = 218 − 184; `zsrelease` 는 52 + 저장 4 + 복원 6 = 62 B = 94 − 32 | python(이번 세션) | ✅ |
| 클록 블록을 빼고 재배치를 풀면 A1 의 나머지 184 B 가 같음 | 직접 재지 않음 | ⚖️ B 의 funcbytes 가 판정 |
| 구간 끝을 0x408d8fa 로 고칠 것 | 위 python | ✅ 고침 |
| 컴파일 뒤 `zsrelease` 의 레지스터 배치·플래그 재사용·저장 차례를 따로 볼 것 | `m68k_funcbytes.py` 는 함수 바이트 전체와 재배치 대상을 견줌 | ❌ 따로 볼 필요 없음 — 함수 바이트가 같으면 레지스터·차례도 같음(반증: 바이트 같음이 그것들을 포함) |

2차 자기검사: ✅ 행은 이번 세션의 풀이 줄·python 출력입니다.

### 673.2 결과(run `m4p673-p1`, 2026-11-01)

- B 컴파일 종료 0·경고 0, 의존 i386 0(`m4-m68k-probe-p673-p1-20261101.json`). funcbytes **5/5**(`m4-m68k-funcbytes-p673-B-20261101.json`, 재배치 대상 차이 0, 객체에만 있는 함수 없음). L1 `OBJECT_MATCH`·사유 없음·`full_span`(bss 가 없어 OBJECT_MATCH 로 받을 수 있는 단위).
- 단언(`m4-m68k-p673-diagchecks-20261101.json`, `ok`): 절 `__text` 676(재배치 32)·`__data` 28(5) 둘뿐, `__data` 가 원본과 같음, 바깥 정의 일곱이 원본 자리, 지역 없음, COMMON 일곱 D136 통과, 미정의 여덟(A1 + `_dma_chip`) 모두 원본 이름.

판정(미리 정한 대로): 바이트로 가려지지 않는 꼴을 구현 전에 여쭙니다.

## 674. M4-178 D156 구현 계획 — 07 `src/machdep/m68k/zscom.c`, 07 `zscom.h`·`zs85C30.h`, 구성 `zs NZS 2`(코딩 전, 2026-11-01)

사용자 결정(D156 으로 적을 것; AskUserQuestion 넷, 모두 추천안): ① 클록 쓰기는 `*(u_char *) P_SCC_CLK = (dma_chip == 313) ? PCLK_3684_MHZ | SCLKB_4_MHZ | SCLKA_4_MHZ : PCLK_10_MHZ;`(SDK 이름 삼항; `P_SCC_CLK` 는 NeXTMach `next/cpu.h:161` 이름을 파일 안 블록에) ② `zsrelease` 는 `zsnullintr` 꼴(지역 `zsaddr`, `ZSWRITE(zsaddr, 1, 0)` 을 두 저장 앞에) ③ 구성 `zs NZS zs.h 2 hypothesis`(NeXTMach `conf/MASTER.next:166`; `zscom.c` 는 값을 쓰지 않음) ④ `zscom.h` 는 07 `nextmach/nextdev/zscom.h`(NeXTMach 사본, D104), `zs85C30.h` 는 07 `nextdev/architecture/zs85C30.h`(실기 SDK 사본, 로컬 전용·D017, §535 `video.h` 선례), 둘 다 `M4HEADERS` 로 m68k 에만. 앞선 선례: include 는 OPENSTEP 경로(D104), `next/cpu.h` 이름은 파일 안 블록(D110·D113·D121), `next/scr.h` import 는 지움, `next/spl.h` → `machine/spl.h`(§657).

1. 07 머리(scratch `p672/gen_p674.py --write`): `07_kernel/nextmach/nextdev/zscom.h` = NeXTMach `nextdev/zscom.h`(SHA `be16ef7a…`) 바이트 그대로; `07_kernel/nextdev/architecture/zs85C30.h` = 로컬 미러 사본, SHA-256 이 실기 목록(`s4c-nextdev-headers-20261002.json`) 의 `9ee61ac3…` 와 같음 단언. 둘 다 없던 파일(덮어쓰지 않음 단언).
2. 07 `src/machdep/m68k/zscom.c`(같은 생성기): NeXTMach `zscom.c`(SHA `08885e0c…`) + NeXTMach 머리 주석(1–5 행) 뒤에 머리 주석 덩이(바뀜 목록·사용자 결정) + include 넷·이름 블록(표시 `plan 674 (D…)`) + ①·② (표시 `plan 674 (D024, D156)`). 단언: 진단 B 와 주석을 뺀 토큰이 같음; L(`08_build/artifacts/m4p674/src/zscom_L.c`, 주석을 비운 F)과 F 의 토큰·토큰 줄 같음; 표시 없는 바뀐 줄 0.
3. 구성: `config_options-m68k.tsv` 에 `zs NZS zs.h 2 hypothesis <근거>` 한 행(`wc -l` 21 → 22 행; 다른 행 그대로; §674.1 에서 고침), `gen_config_headers.py --arch m68k` 로 `07_kernel/v183.34/m68k/generated/zs.h`(`#define NZS 2`, 진단 사본과 바이트 같음 단언), 다른 생성 머리 그대로; `--check`(m68k·x86) 종료 0.
4. `stage_m68k.py`: `M4FILES[674] = list(M4FILES[670]) + ['zscom.c']`, `M4HEADERS[674] = list(M4HEADERS[663]) + [('nextdev/zscom.h', 'src/bsd/nextdev/zscom.h'), ('architecture/zs85C30.h', 'components/architecture/zs85C30.h', '07_kernel/nextdev')]`, `EXCEPTS[674] = dict(EXCEPTS[670])`, 머리말 목록.
5. 회귀: `--plan 670` 재생성(`m0p670-r674-stage`)은 보관 `m0p670-a1-stage` 와 `generated/zs.h` 하나만 다름(매니페스트 키 `added`·`files`; 생성 머리는 모든 계획에 들어감, §517·§573 선례); `m0p674-a1-stage` 는 그것과 `zscom.c`·`zscom.h`·`zs85C30.h` 만(키 `files`·`m4_headers`·`m4_sources`·`plan`); `m5-670.cmd` 보관본과 같음, `m5-674.cmd` 는 계획 번호만; M5 205(`m3p674-b670` 보관 670 스테이지·`--plan 670 compare`, `m3p674-cc1`·`--plan 674`) 객체·출력 같음, `differ_unexpected`·`lost` 빔; x86 입력(`L2_*` s6p398) `ok` 이고 p670 과 같음·`--plan 674 x86gate` 일곱 같음.
6. 확인 run `m4p674-p1`(명세 `08_build/artifacts/m4p674/confirm/spec.json`, 바탕 `m0p674-a1-stage`): F·L 종료 0·경고 0·i386 0, 5/5, L1 `OBJECT_MATCH`·`full_span`, F = L(canon·`obj_sig`), F 와 진단 B 객체는 canon 같음·`obj_sig` header·sections·symbols 같음(STABS 는 줄 차이로 달라도 됨), `chk_p672.py`(676, 5) F·L `ok`, 의존 머리 출처는 07(`zscom.h` nextmach·`zs85C30.h` nextdev·`zs.h` 생성)과 실기 `zsreg.h`. `-E` run `m4p674-e2`(F·L·B): 토큰 F = L = B(`#` 줄 뺌), stderr 0, i386 0.
7. 최종 run `m4p674-a1`(명세 `08_build/artifacts/m4p674/spec.json`, F 만, `refs` = p1 L, 명령 파일 `probe.cmd`): `gate.ok`, OBJECT_MATCH. funcbytes 5/5. 확인 기록 `m4-m68k-p674-checks-20261101.json`(의존 SHA 사슬·선택지 = M5 줄·07 = 스테이지·e2·p1 `ok`).
8. 상태: `ACCEPTED` 에 두 칸 하나를 더함. 근거 `06_reconstruction/evidence/m68k-zscom.md`·`m68k-zscom.diff`(새) 를 먼저. 상태 도구 두 번, 기대(python): 객체 58(OBJECT_MATCH 46, CODE+BSS_INFERRED 12), 행 78/188, 78566 B(36.39%) 그대로, `object_bytes` 120130, 부분 행에 `m68k-258`·`m68k-259` 가 더해짐.
9. 기록: PROVENANCE(새 `zscom.c`·`zscom.h`·`zs85C30.h`·생성 `zs.h` 네 행), MODIFICATIONS, DECISIONS D156, 계획·HANDOFF·메모리. M7: `_zi_null`·`_zs_com` 을 쓰는 `zs.c`, COMMON 합침, 호출 대상(`delay`·`install_polled_intr`).

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, 확인·`-E`·최종·확인 기록 `ok`, 상태 도구가 기대와 같음. 어긋나면 멈추고 알립니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 674.1 교차검토(codex `gpt-6.1-sol`, task ks4ym3zzq) 판정과 계획 수정

먼저 제 잘못: 구성 표의 줄 수를 "22 → 23" 으로 적었으나 `wc -l` 은 21 입니다(끝 빈 조각까지 센 수; §670.2 의 "22 행 그대로" 도 같은 잘못이라 함께 고침).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `M4HEADERS` 셋째 칸 `07_kernel/nextdev` 와 `components/` 아래 대상은 스테이지 코드가 받음; `-Isrc/components` 로 풀림; 상태 도구는 의존 경로의 `src/` 를 떼고 매니페스트 키로 대응 | `stage_m68k.py:572–583`, `m4_m68k_status.py:112–131`, 컴파일 줄 `-Isrc/components`(`m5p494/final.cmd:2`) | ✅ |
| 재생성 670 스테이지는 `generated/zs.h` 만 다르나 매니페스트 키는 `added`·`files` 둘이 바뀜 | §573 보관본 221 행 | ✅ 기대를 고침 |
| x86 일곱 닫힘에 `zs85C30.h` 가 없고 `m4_x86_inputs` 를 메모리에서 돌려 p670 과 같았음 | 재지 않음(`stage_headers.py:289` 의 `--prefer-07` 가 닿으면 고른다는 줄만 열어 봄) | ⚖️ 회귀 단계의 실제 `m4_x86_inputs`·`x86gate` 가 판정 |
| 상태 기대 58·46·12·78/188·78566·36.39%·120130, 부분 행 + 258·259; `object_bytes` 는 텍스트 구간만 | `m4_m68k_status.py:198`(`bytes=hi - lo`), python 119454 + 676 | ✅ |
| F 대 B 의 canon + header·sections·symbols, `-E` 토큰 F = L = B 는 타당; 다만 새 스테이지에서는 진단 `-I` 가 뒤에 붙어 B 도 스테이지 사본(`nextdev/zscom.h` 등)을 먼저 고름 | `m4_m68k_probe.py:222` | ✅ `-E` 기록에 B 의 의존 출처를 함께 적고, F = B 는 "같은 머리에서 원천 토큰이 같음" 의 뜻으로만 씀 |
| `.gitignore` 는 이미 `/07_kernel/nextdev/` 를 뺌; 생성 `zs.h` 의 PROVENANCE 는 `sc.h` 행 꼴(hypothesis); `chk_p672.py` 의 `zs_from` 이 `ok` 에 들지 않음 | `.gitignore:72`, `PROVENANCE.tsv:1167`, `chk_p672.py:61` | ✅ `chk_p672.py` 에 기대 출처 인수를 더해 `ok` 에 넣음 |

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 674.2 결과(2026-11-01)

- 1–2 07 `nextmach/nextdev/zscom.h`(NeXTMach 그대로, `be16ef7a…`), 07 `nextdev/architecture/zs85C30.h`(실기 목록 SHA `9ee61ac3…`, 로컬 전용), 07 `src/machdep/m68k/zscom.c` 186 행(SHA `5163e385…`), L `08_build/artifacts/m4p674/src/zscom_L.c`(scratch `p672/gen_p674.py --write`; 진단 B 와 토큰 같음·F = L 토큰과 토큰 줄·표시 없는 바뀐 줄 0 단언).
- 3 구성 `zs NZS zs.h 2 hypothesis`(`wc -l` 21 → 22), 생성 `zs.h` 가 진단 사본과 바이트 같음, 다른 생성 머리 19 개는 670 스테이지 사본과 같음, `--check`(m68k·x86) 종료 0. 4 `stage_m68k.py` 763 → 767 행.
- 5 회귀: `--plan 670` 재생성(`m0p670-r674-stage`, 1000)은 보관본과 `generated/zs.h` 하나만(키 `added`·`files`), `m0p674-a1-stage`(1003)는 거기에 `zscom.c`·`zscom.h`·`zs85C30.h` 만(키 `files`·`m4_headers`·`m4_sources`·`plan`). `m5-670.cmd` 보관본과 같고 `m5-674.cmd` 는 계획 번호만. M5 205(`m3p674-b670`·`m3p674-cc1`) 접두어를 맞추면 객체·출력 모두 같음(`run.json` 만), `m3p674-b670` 은 `m3p670-cc1` 과 같음; `compare` 둘 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 새 네 파일뿐. x86 `m4-x86-inputs-p674-20261101.json` `ok`(p670 과 같음), `--plan 674 x86gate` 는 `plan`·도구 해시만 다름.
- 6 확인 run `m4p674-p1`(`m4-m68k-p674-p1checks-20261101.json` `ok`): F·L 5/5·경고 0·OBJECT_MATCH·`full_span`, `chk_p672.py`(머리 출처 단언 포함) F·L `ok`, F = L, F 와 진단 B 객체가 canon·`obj_sig` 전부 같음. `-E` `m4p674-e2`(`ok`): F = L = B 12680 토큰(이 스테이지에서 B 도 스테이지 사본을 읽음), stderr 0.
- 7 최종 run `m4p674-a1`(`m4-m68k-p674-final-20261101.json`, SHA `3e536447…`): `gate.ok`, 5/5, `options` 채워짐. 확인 `m4-m68k-p674-checks-20261101.json`(`ok`; 의존 146·SHA 사슬(`zscom.h`·`zs85C30.h`·`zs.h`)·선택지 = M5 줄·07 = 스테이지). 객체 SHA `a2c37423…`.
- 8 상태(`m4-m68k-status-p674-20261101.json`, 표 59 → 60 행; scratch 에 두 번 같음): 객체 58(OBJECT_MATCH 46, CODE+BSS_INFERRED 12), 행 78/188, 78566 B(36.39%), `object_bytes` 120130, 부분 행에 `m68k-258`·`m68k-259` — 미리 계산한 값과 같음. 근거 `m68k-zscom.md`·`m68k-zscom.diff`.
- 9 기록: PROVENANCE 1214 → 1218 행(일곱 칸, 겹침 없음), MODIFICATIONS 752 → 753, DECISIONS D156(159 → 160 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D156).
