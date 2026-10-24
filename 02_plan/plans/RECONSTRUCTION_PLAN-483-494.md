# 커널 소스 복원 작업계획 — 보관 §483–494

`02_plan/RECONSTRUCTION_PLAN.md` 의 §483–494(m68k M5 마무리: `kdp_udp`·`callout`·`tty`, `nfs_client`(보류)·`swapfs`(부분 개선, D102))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-24, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 본문은 `---` 아래부터입니다.

---

## 483. M5-40 세부 계획 — m68k `kdp_udp`: `kdp_handler`·`kdp_connection_wait`·`kdp_send_exception` 를 인라인하지 않는 꼴(07 변경 없음; 코딩 전, 2026-10-23)

남은 다섯 객체 가운데, §479–482 에서 본 "x86 `-O3` 와 m68k `-O2` 의 인라인 차이" 와 같은 꼴로 보이는 것입니다.

확인한 사실(§470 기록, 원본 목록·기호표, 07·Darwin·보관 계획을 직접 읽음):
- §470 기록: 객체 텍스트 2166 B, 원본 범위 [0x404fd9a, 0x4050658) 2238 B 로 −72 B 입니다. L1 사유는 `__TEXT,__text`·`__DATA,__data`·`__DATA,__bss: unverified` 입니다.
- 함수 시작과 크기(앞 명령이 `rts` 이고 `pea`/`linkw` 로 시작하는 자리; python):
  - 원본: 524·480·288·230·240·198·234(`_kdp_raise_exception`)·44(`_kdp_reset`)
  - 우리: 524·480·288·830(`_kdp_raise_exception`)·44
- 원본 함수의 대응(호출 대상으로 판별; python):
  - 0x404fd9a = `kdp_reply`, 0x404ffa6 = `kdp_send`, 0x4050186 = `kdp_poll`
  - 0x40502a6 = `kdp_handler`(`kdp_poll`·`_kdp_packet`·`kdp_reply` 호출)
  - 0x405038c = `kdp_connection_wait`(`_kmtrygetc`·`_kdp_reboot`)
  - 0x405047c = `kdp_send_exception`(`_kdp_exception`·`_kdp_exception_ack`·`_kdp_us_spin`)
  - `_kdp_raise_exception` 이 세 정적 함수를 `bsr` 로 부릅니다. 원본 m68k 는 셋을 인라인하지 않았습니다.
  - 순서는 07 정의 순서와 같습니다.
- 07 `kern/kdp_udp.c`(465 행, 작성 파일 D024·D027, PROVENANCE 617 행):
  - 75 행 `static inline void kdp_handler(void *);`(전방 선언)
  - 283·326·376 행의 세 정의가 `static inline void` 입니다.
  - 작은 `enaddr_copy`(77 행)·`ip_sum`(87 행)도 `static inline` 입니다. 원본 m68k 에서도 이 둘은 따로 나오지 않습니다(앞 세 함수 크기가 우리와 같음).
- 계획 257(보관 `plans/RECONSTRUCTION_PLAN-245-320.md` 338 행): x86 에서 `inline` 없이 컴파일하면 handler·connection_wait 가 따로 나와 원본과 달랐고, 그래서 `inline` 을 붙였습니다(it2 4130 B → it3).
- Darwin 0.1 `kern/kdp_udp.c` 는 세 함수를 `static`(인라인 아님, 125·366·414·464 행)으로, `enaddr_copy`·`ip_sum` 을 `static inline`(132·142 행)으로 둡니다.
- 컴파일 옵션: m68k `-O2`(`08_build/artifacts/m3p430/cc.cmd:115`), x86 `-O3`(`s6l5-g1a.cmd`). m68k·x86 스테이징 사본은 07 과 SHA-256 이 같습니다(`1d34869a…`).

가설:
- m68k 원본은 세 함수를 인라인하지 않는 꼴(`static`)로 컴파일했습니다. x86 원본은 인라인된 꼴입니다(계획 257). 그러므로 조건 없이 `inline` 을 빼면 x86 이 달라질 것으로 예상합니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p482-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_351__kdp_udp.o`, run `m5p483-k1`; 명세 `08_build/artifacts/m5p483/spec-kdp_udp.json`):
- `N`: 75·283·326·376 행에서 `inline` 을 뺍니다.
- `X`: 같은 네 자리를 `#if m68k` / `static void …` / `#else m68k` / 지금 줄 / `#endif m68k` 로 감쌉니다(07 본 파일 후보).
- 판정: 맞는 꼴은 m68k L1 사유가 `[]` 또는 `['__DATA,__bss: unverified']` 이고, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같고, 컴파일 경고가 K 보다 늘지 않아야 합니다.
- 관문: 명령 종료 0, 객체 있음, m68k K 와 `control_ref` 의 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5, 변형 K·N·X): 07 본 파일 후보는 x86 K 와 비 STABS 로 같아야 합니다. N 은 다를 것으로 예상합니다.
- 고르기(미리 정함): 07 본 파일 후보는 두 아키텍처 모두 통과한 꼴, 덮어쓰기 후보는 m68k 만 통과한 꼴입니다. 후보가 하나뿐이면 그 꼴과 자리로 정하고, 둘 이상이면 묻습니다. 맞는 꼴이 없으면 기록만 하고 남은 차이를 함수 안에서 다시 적습니다.
- 구현은 §482.3 과 같습니다(07 본 파일이면 x86 재빌드 접두어 `s6li`·링크 `s6p483-ln1`, final run `m5p483-a1`, `bss_records` 는 §482 까지 일곱).

### 483.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·대응·순서·인용 줄·옵션·스테이징 해시가 맞음 | §483 작성 때 python·grep·sha256sum 으로 직접 확인한 값과 같음 | ✅ |
| 세 함수와 `kdp_raise_exception` 본문에 다른 소스 차이는 보이지 않음; 바이트는 시험으로만 정해짐 | 설계 판단 | ⏭️ 시험이 판정 |
| `__DATA,__data: unverified` 는 텍스트가 자리를 못 잡은 데서 오는 것이고, 28 B 표 내용은 맞음 | 검토자의 배치 시험(기록 `l1place-x86-kdp_udp.json`) | ⏭️ 맞는 꼴의 L1 사유로 확인 |
| bss 는 따로 추정 관문(zerofill)이 필요 | `m5_m68k_final.py` 머리글 | ✅ 기존 규칙 |
| X 는 토큰상 맞음; `#else m68k` 꼬리 토큰은 경고를 낼 수 있음 | 07 의 같은 꼴(`ufs_subr.c`·`mach_net.c`, §478.1 확인) | ⚖️ 대상 컴파일러에서 경고 수를 K 와 비교 |
| 전방 선언과 정의의 `inline` 을 함께 바꿔야 함 | 명세가 네 자리를 함께 바꿈 | ✅ |
| N 이 x86 에서 달라지는 것은 그럴듯하나 확실하지 않음(계획 257 은 다른 빌드) | 설계 판단 | ✅ 시험으로 정함 |
| 도구 요약은 관문을 다 보지 않음 → 직접 확인; `summary.match` 로 고르지 말 것 | §479.1 부터 같은 규칙 | ✅ |
| N(덮어쓰기)·X(본 파일) 둘 다 후보가 될 수 있고, 덮어쓰기 구현 절차는 따로 필요 | 설계 | ✅ 그 경우 묻고, 덮어쓰기를 고르면 새 절에서 계획 |
| `bss_records` 일곱(§482 까지) | 기록 목록 | ✅ |

### 483.2 변형 시험 결과(2026-10-23)

- m68k run `m5p483-k1`·x86 run `m5p483-xk1`(각 3 명령)은 모두 종료 0 이고, 경고는 모든 변형에서 0 줄입니다.
- 관문: m68k K 는 `control_ref` 와 obj_sig 가 같고, x86 K 는 `control_equals_ref` true 입니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-kdp-udp-variants-p483-20261023.json`):
  - **N·X 는 같은 객체이고, 사유가 `['__DATA,__bss: unverified']` 하나입니다.**
  - 텍스트는 원본 범위 시작 0x404fd9a, `__DATA,__data` 는 0x40af984, bss 는 0x40b39c6 에 놓입니다(L1 `placements`). 함수별 바이트 차이는 0 입니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같습니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-kdp-udp-variants-p483-20261023.json`):
  - **N 도 x86 K 와 같습니다**(canon·절·비 STABS 기호). 지금의 x86 `-O3` 빌드는 `inline` 없이도 세 함수를 인라인합니다.
  - 계획 257 의 "inline 이 없으면 따로 나온다" 는 관찰은 그때의 빌드에 대한 것으로, 지금의 한 파일 컴파일에서는 재현되지 않았습니다(§483.1 의 검토 지적과 같음).
  - X 도 같습니다.
- 고르기(§483 규칙): 07 본 파일 후보는 N(조건 없음, Darwin 0.1 과 같은 `static`)과 X(`#if m68k`) 둘입니다. 꼴을 사용자에게 묻습니다.

사용자 결정 D099(2026-10-23): 꼴 "N: inline 빼기 (Recommended)", 자리는 07 본 파일.

### 483.3 D099 구현 계획(07 본 파일 `kdp_udp.c` + x86 전체 재빌드 s6li; 코딩 전, 2026-10-23)

§482.3 의 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p483-k1/out/P483__N.o`(SHA-256 `200c58dd…`, 변형 기록과 대조)를 REF 로 씁니다.
1. 07 편집(`kern/kdp_udp.c`; 고치기 전 파일을 `08_build/artifacts/m5p483/kdp_udp.c.main.before` 로 먼저 옮겨 둠):
   - 변형 N 의 네 바꿈을 넣습니다.
   - 네 줄 끝에 `/* plan 483 (D099): not inline, as the m68k original */` 를 붙입니다.
   - python 으로 주석을 뺀 토큰이 N 과 같은지 확인합니다(N 은 고치기 전 파일에서 다시 만들고 run 의 스테이징 사본과 대조). 파일은 465 행 그대로입니다.
2. x86 전체 재빌드 s6li 와 check 관문(§480.3 과 같음).
3. prefixdiff s6lh↔s6li(plan 483): 스테이징 차이는 `src/kern/kdp_udp.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-kdp_udp']`, 비 STABS 같음.
4. 링크 `l2_link.py prepare s6p483-ln1 s6li` → `kr_run.py` → `l2_compare.py` → `cmp`.
5. `stage_m68k.py`: `X86[483] = 's6li'`, `EXCEPTS[483] = dict(EXCEPTS[482], **{'x86-kdp_udp': …})`, 문서 줄 셋(9·12·21 행). `--plan 483 stage m0p483-a1-stage`·`--plan 483 x86gate 08_build/artifacts/m5p483/x86gate`; `m0p482-a1-stage` 와의 파일 항목 차이는 `src/kern/kdp_udp.c` 하나.
6. final(run `m5p483-a1`): 기대 사유 `['__DATA,__bss: unverified']`, `bss_records` 는 §482 까지 일곱. zerofill 결과를 `09_validation/reconstruction/m5-m68k-p483-zerofill-20261023.json` 으로 복사하고 SHA-256 을 대조합니다.
7. 기록:
   - PROVENANCE 617 행(`authored`)을 그 자리에서 갱신합니다(changes 칸과 새 파일 SHA-256).
   - MODIFICATIONS 한 행, DECISIONS D099, diff `06_reconstruction/evidence/x86-kdp_udp-plan483.diff`, `x86-kdp_udp.md` 에 절을 덧붙입니다.
   - `functions.tsv` 의 kdp_udp 인용 다섯(2022–2026 행: 113·176·231·412·460)은 행 수가 바뀌지 않으므로 옮기지 않습니다. 옛·새 줄 내용이 같은지만 assert 합니다.
   - 집계: "코드 검증 + bss 추정" 25 → 26, 코드 검증 203 → 204/208(98.1%), 코드 차이가 남은 객체 5 → 4(nfs_client, tty, callout, swapfs)입니다(python).

### 483.4 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계·관문에 빠진 것 없음 | §482.3–482.5(보관본)와 나란히 읽음 | ✅ |
| N 과 표시 붙인 N 은 465 행, 주석 뺀 토큰 같음; 바꿀 글은 앞뒤 문맥까지 넣어야 한 번만 나옴(`static inline void` 줄만으로는 넷) | 명세 작성 때 네 글이 각 1 번임을 assert; 구현에서 다시 확인 | ✅ |
| kdp_udp 인용은 `functions.tsv` 2022–2026 행 다섯뿐, 옮길 필요 없음 | grep(§483.3 작성 때 출력) | ✅ 구현에서 줄 내용 assert |
| `stage_m68k.py` 482 항목과 문서 줄 9·12·21 | grep | ✅ |
| `bss_records` 일곱과 기대 사유 | §482.5, `l1-m5p483-k1-N.json` | ✅ |
| 집계 26·204/208(98.1%)·4, 그리고 "현재 상태와 다음 일" 절도 갱신할 것 | python | ✅ 7 에 더함 |

### 483.5 D099 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p483-final-20261023.json`

- 07 편집: 본 파일 `kern/kdp_udp.c` 는 465 행 그대로입니다. 주석을 뺀 토큰이 변형 N 과 같고, N 은 run 의 스테이징 사본과 같습니다(python). `functions.tsv` 의 인용 다섯 줄(113·176·231·412·460)은 내용이 그대로입니다(assert). 고치기 전 파일은 `08_build/artifacts/m5p483/kdp_udp.c.main.before` 입니다.
- x86 전체 재빌드 s6li: 명령 804 개 모두 종료 0, 402 행 1–402 연속, 모두 기준과 같거나 기대대로, problem·deps 차이 0 입니다. prefixdiff s6lh↔s6li 는 스테이징 차이 `src/kern/kdp_udp.c` 하나이고 `sha_differ_not_rid_only` 는 `[]`(x86 객체가 STABS 까지 그대로)입니다. 링크 `s6p483-ln1` 은 `identical file: True`, `cmp` 같음, 공통 기호 417 / 417 입니다.
- m68k: `stage_m68k.py` 에 `X86[483] = 's6li'`·`EXCEPTS[483]` 을 등록하고 문서 줄 셋을 고쳤습니다(537 → 538 행). stage·x86gate(일곱 모두 같음)를 거쳤고, `m0p482-a1-stage` 와의 차이는 `src/kern/kdp_udp.c` 하나입니다. final `m5p483-a1` 은 REF 와 서명이 같고 사유는 bss 하나, 미정의 0 입니다. zerofill(`m5-m68k-p483-zerofill-20261023.json`, 복사본 SHA-256 같음)은 reference-inferred [0x40b39c6, 0x40b45b4) 3054 B 이고 이전 일곱 기록과 겹침 0 입니다.
- 집계(python): OBJECT_MATCH 177(+ 명시 배치 1), "코드 검증 + bss 추정" 26, 공통부 208 중 204(98.1%) 코드 검증. 코드 차이가 남은 객체는 4 개(nfs_client, tty, callout, swapfs)입니다.
- 기록: PROVENANCE 617 행 그 자리 갱신(1099 행, 중복 0), MODIFICATIONS 642 행, DECISIONS D099, diff `06_reconstruction/evidence/x86-kdp_udp-plan483.diff`, `x86-kdp_udp.md` 절.

## 484. M5-41 세부 계획 — m68k `callout`: 인라인하지 않는 도우미 셋의 자리와 `callout_thread` 의 자리(07 변경 없음; 코딩 전, 2026-10-23)

남은 넷(nfs_client, tty, callout, swapfs) 가운데, §483 과 같은 인라인·순서 꼴로 보이는 것입니다.

확인한 사실(§470 기록, 원본 목록·기호표, 07·Darwin 을 직접 읽음):
- §470 기록: 객체 텍스트 3128 B, 원본 범위 [0x4053ef8, 0x4054aaa) 2994 B 로 +134 B 입니다. L1 사유는 `__TEXT,__text`·`__DATA,__data`·`__DATA,__bss: unverified` 입니다.
- 함수 크기(python; 기호가 없는 것은 호출 관계로 이름을 붙임):
  - 원본: `calloutInitialize` 164 → 정적 118·140·134 → `calloutDeadlineFromInterval` 42 … `calloutEntryRemove` 184 → 정적 86·256·26·110·26·300
  - 우리: `calloutInitialize` 164 → `calloutDeadlineFromInterval` 42 … `calloutEntryRemove` 130 → 정적 86·256·110·26·318·26
  - 외부 함수 가운데 `calloutDispatchDelayed`(322/234)·`calloutRemove`(198/72)·`calloutRemoveAll`(234/66)·`calloutEntryDispatchDelayed`·`…WithArgumentDelayed`(246/156)·`calloutEntryRemove`(130/184)가 다릅니다.
- 원본 정적 함수의 대응(호출 대상; python):
  - 0x4053f9c(118 B): `_clock_value`·`_timer_attributes`·`_set_timer` 호출. 07 `delayed_entry_set_timer`(154 행)입니다. 부르는 곳은 `calloutDispatchDelayed`·`calloutEntryDispatch(WithArgument)Delayed`·`callout_delayed_interrupt` 입니다.
  - 0x4054012(140 B)·0x405409e(134 B): `calloutRemove`·`calloutRemoveAll` 이 부릅니다. 07 `remove_from_pending_queue`(173 행)·`remove_from_delayed_queue`(204 행)입니다.
  - 뒤쪽 원본 순서는 `callout_wakeup`(86) · `callout_thread_continue`(256) · `callout_thread`(26, `stack_privilege` 뒤 0x40547dc 호출) · `callout_activate_continue`(110) · `callout_activate_thread`(26) · `callout_delayed_interrupt`(300)입니다.
  - 07 은 `callout_thread` 를 파일 끝(699–705 행)에 둡니다.
- 07 `kern/callout.c`(705 행, 작성 D024·D027, PROVENANCE 615 행):
  - 도우미 아홉(70–234 행)이 모두 `static __inline__` 이고 `calloutInitialize`(235 행) 앞에 있습니다.
  - 세 도우미를 부르는 곳은 모두 357 행 이후입니다(grep). 옮겨도 전방 선언이 필요 없습니다.
- Darwin 0.1 `kern/thread_call.c`(07 의 구조 참고본):
  - `thread_call_init`(134 행)을 도우미들(173 행~)보다 앞에 둡니다.
  - `_remove_from_pending_queue`·`_remove_from_delayed_queue` 는 `static`(358·410 행)이고, `_set_delayed_call_timer` 는 `static __inline__`(335 행)입니다.
  - `_call_thread`(964 행)를 `_call_thread_continue`(905 행) 바로 뒤에 둡니다.
- 컴파일 옵션: m68k `-O2`(`08_build/artifacts/m3p430/cc.cmd:114`), x86 `-O3`. 스테이징 사본은 07 과 SHA-256 이 같습니다(`0c7c58ef…`).

가설:
- m68k `-O2` 는 `__inline__` 함수만 인라인하고 일반 `static` 함수는 소스 자리에 냅니다.
- 원본 소스는 세 도우미를 `calloutInitialize` 뒤에 일반 `static` 으로 정의했고, `callout_thread` 를 `callout_thread_continue` 바로 뒤에 두었습니다.
- 다른 여섯 도우미는 `__inline__` 으로 모두 인라인되어 원본에 따로 나오지 않습니다.
- `calloutEntryRemove`·`callout_delayed_interrupt` 의 크기 차이도 세 도우미의 인라인에서 따라 나온 것으로 봅니다. 이 부분은 시험으로 확인합니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p483-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_350__callout.o`, run `m5p484-c1`; 명세 `08_build/artifacts/m5p484/spec-callout.json`):
- 진단:
  - `I`: 세 도우미에서 `__inline__` 만 뺍니다(자리 그대로).
  - `M`: 세 도우미(150–234 행, 주석 포함)를 `calloutInitialize` 뒤로 옮기기만 합니다.
  - `MI`: M + I.
  - `T`: `callout_thread` 를 `callout_thread_continue` 바로 뒤로 옮깁니다.
- 후보:
  - `ALL` = MI + T.
  - `ALL2` = 도우미 아홉(70–234 행)을 모두 `calloutInitialize` 뒤로 옮기고, 세 도우미의 `__inline__` 을 빼고, T 를 더합니다(Darwin 의 구조).
  - `XALL` = ALL 이되 `__inline__` 은 `#if m68k` 에서만 뺍니다(x86 이 달라질 때를 대비한 07 본 파일 후보).
- 판정: 맞는 꼴은 m68k L1 사유가 `[]` 또는 `['__DATA,__bss: unverified']`, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같고, 경고가 K 보다 늘지 않아야 합니다.
- 관문: 명령 종료 0, 객체 있음, m68k K 와 `control_ref` 의 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5, 같은 여덟 변형): 07 본 파일 후보는 x86 K 와 비 STABS 로 같아야 합니다.
- 고르기(미리 정함): 07 본 파일 후보는 두 아키텍처 모두 통과한 꼴입니다. 후보가 하나뿐이면 그대로 정하고, 둘 이상이면 묻습니다. 맞는 꼴이 없으면 기록만 하고 남은 차이를 함수 안에서 다시 적습니다.
- 구현은 §483.3 과 같습니다(x86 재빌드 접두어 `s6lj`·링크 `s6p484-ln1`, final run `m5p484-a1`, `bss_records` 는 §483 까지 여덟).

### 484.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §484 의 가설은 세 도우미만으로 차이를 설명하려 했습니다. 원본을 다시 읽으니 두 가지가 더 있습니다.
- 원본 `remove_from_pending_queue`(0x4054012–0x405409c)는 `d0` 을 0 으로 두고 지우면 1 로 바꾼 뒤, `remove_all` 이면 계속 돌다가 `d0` 을 그대로 돌려줍니다(`return removed;`). 07(과 Darwin)의 `return (!remove_all ? removed : FALSE);` 와 다릅니다. 지금 부르는 쪽(`calloutRemove` 는 `FALSE`, `calloutRemoveAll` 은 결과를 버림)에서는 차이가 드러나지 않아, x86(인라인) 바이트로는 정해지지 않았던 것으로 봅니다.
- 원본 `callout_delayed_interrupt` 끝(0x4054a3e–0x4054a98)에는 `callout_wakeup` 의 본문(`thread_wakeup_prim` 두 번)이 인라인되어 있습니다. 반면 앞쪽 함수들은 0x4054786 의 `callout_wakeup` 을 부릅니다(목록 출력). `callout_wakeup` 이 `__inline__` 이면 이렇게 됩니다. 정의보다 앞의 호출은 호출로 남아 그 자리에 함수가 나오고, 정의 뒤의 `callout_delayed_interrupt` 에는 인라인됩니다. 이 기제는 가설이며 시험으로 확인합니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·순서·대응이 맞음(§470 의 556·952/988 은 정적 함수를 포함한 구간 크기) | python 크기 표와 같음 | ✅ |
| 인용 줄·명세 적용·Darwin 꼴이 맞음 | §484 작성 때 직접 확인 | ✅ |
| 바뀌지 않는 외부 함수 본문은 이미 같음 | §470 구간 `masked_equal` | ✅ |
| 두 제거 도우미의 반환 꼴이 다름 | 원본 0x4054026 `clrl d0`·0x4054084 `moveq #1,d0`·0x4054086 `tstl d2; beq` 끝 | ✅ 위 제 오류; 진단 R 을 더함 |
| `calloutEntryRemove` 는 꼬리 합치기·레지스터 배정 차이(130 + 46 + 8 = 184)이고, 세 도우미와 무관 | 나란히 비교(우리는 `clrl a1@(0x1c)` 이하를 두 갈래가 함께 씀, 원본은 둘째 갈래를 a2 로 따로 둠); python 130 + 46 + 8 = 184 | ✅ 원인은 아직 모름. 이번 변형으로 안 풀리면 다음 절에서 다룸 |
| `callout_delayed_interrupt` 는 `callout_wakeup` 의 인라인이 더 필요함 | 원본 목록 출력(위) | ✅ 진단 W 를 더함 |
| 데이터 4 B(`callout_initialized`)·bss 2088 B 예상 | 검토자 L1 출력 | ⏭️ final 에서 확인 |
| x86 관문은 XALL 에도 필요; 도구 요약으로 고르지 말 것 | 같은 규칙 | ✅ |
| 구현 때 인용 옮김은 callout 인용(`functions.tsv` 1989–2008 행)으로 | grep | ✅ 구현 계획에 적음 |

계획 수정(실행 전 고정): 변형 = K·I·R·M·MI·T·W(진단)와 ALL·ALL2·XALL(후보).
- `R` = 두 제거 도우미의 반환을 `return (removed);` 로 바꿉니다.
- `W` = `callout_wakeup` 정의를 `static __inline__ void` 로 바꿉니다(전방 선언은 그대로).
- `ALL` = MI(세 도우미를 옮기고 `__inline__` 빼기) + R + T + W
- `ALL2` = 도우미 아홉을 모두 옮기고, 세 도우미 `__inline__` 빼기 + R + T + W
- `XALL` = ALL 이되 `__inline__` 빼기를 `#if m68k` 로만
- 기대: ALL 에서 `calloutEntryRemove` 를 뺀 함수들이 원본과 같아야 합니다. `calloutEntryRemove` 가 남으면 맞는 꼴이 아니므로, 기록만 하고 다음 절에서 다룹니다.

### 484.2 변형 시험 결과(2026-10-23)

- m68k run `m5p484-c1`·x86 run `m5p484-xc1`(각 10 명령)은 모두 종료 0 입니다.
- 관문: m68k K 는 `control_ref` 와 obj_sig 가 같고, x86 K 는 `control_equals_ref` true 입니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-callout-variants-p484-20261023.json`):
  - ALL·ALL2·XALL 은 같은 객체입니다. 텍스트가 원본 범위에 자리를 잡았고(L1 사유 `__TEXT,__text: fail` 로 바뀜), 외부 함수 구간 14 개 가운데 13 개가 원본과 같습니다(재배치를 가린 비교).
  - 남은 것은 `calloutEntryRemove` 구간입니다. 이 구간에는 뒤쪽 정적 함수 여섯도 들어 있습니다. `calloutEntryRemove` 가 원본보다 54 B 짧아(꼬리 합치기, §484.1) 뒤 함수들이 밀리므로, L1 의 함수별 바이트 차이(`callout_wakeup` 61 … `callout_delayed_interrupt` 237)는 그 밀림을 함께 셉니다.
  - 단독 변형(I·R·M·MI·T·W)은 모두 텍스트가 자리를 못 잡아 판정에 쓸 수 없습니다(진단으로만 둠).
  - W 를 넣은 변형(W·ALL·ALL2·XALL)은 경고 한 줄이 생깁니다: "`callout_wakeup' declared inline after being called"(`_log/08.err`·`00.err`). §484.1 의 기제 가설과 맞는 경고지만, 미리 정한 기준(경고가 K 보다 늘지 않음)에 걸립니다.
  - 원본에 없는 미정의 0, COMMON 은 K 와 같습니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-callout-variants-p484-20261023.json`): 열 변형 모두 x86 K 와 canon·절·비 STABS 기호가 같습니다.
- 고르기(§484.1 규칙): 맞는 꼴은 없습니다. 07 은 바꾸지 않고 기록만 합니다.
  - 다음 절에서 두 가지를 다룹니다. 하나는 `calloutEntryRemove` 의 꼬리 합치기이고, 다른 하나는 W 와 같은 코드를 경고 없이 내는 꼴(예: 전방 선언에 `__inline__`)입니다.

## 485. M5-42 세부 계획 — m68k `callout` 남은 둘: `calloutEntryRemove` 의 꼬리 합치기와 경고 없는 `callout_wakeup` 인라인(07 변경 없음; 코딩 전, 2026-10-23)

§484.2 의 ALL 을 바탕(B0)으로, 남은 `calloutEntryRemove` 구간과 경고를 다룹니다.

확인한 사실(§484 기록·원본 목록·07·Darwin 을 직접 읽음):
- 원본 `calloutEntryRemove`(0x40546ce, 184 B)는 시작에서 `movel a1,a2` 로 `entry` 를 a2 에 복사해 두고, PENDING 갈래는 a1, DELAYED 갈래는 a2 로 각자 `status = IDLE`·`callout_entry_release` 를 합니다. 우리(130 B)는 두 갈래의 끝(`clrl a1@(0x1c)` 이하 46 B)을 하나로 합쳤고, a2 저장·복원(8 B)이 없습니다. 130 + 46 + 8 = 184(python).
- Darwin 0.1 `kern/thread_call.c` 는 대응하는 공개 함수 여섯(660·697·723·763·795·838 행)에서 모두 `_thread_call_t call = _call;` 로 매개변수의 지역 사본을 씁니다. 838 행 `thread_call_cancel` 이 `calloutEntryRemove` 에 대응합니다. 07 은 사본 없이 매개변수 `entry` 를 바로 씁니다(533–552 행).
- §484.2 의 W 는 경고 "`callout_wakeup' declared inline after being called" 를 냈습니다. 07 의 전방 선언은 63 행 `static void callout_wakeup(void);` 입니다.

가설:
- 매개변수의 지역 사본이 있으면 `entry` 가 두 레지스터에 놓여 꼬리 합치기가 일어나지 않을 수 있습니다. 또는 `switch` 꼴이 갈래 구조를 바꿀 수 있습니다.
- 전방 선언에 `__inline__` 을 두면 같은 코드를 경고 없이 낼 수 있습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `m0p483-a1-stage`, 대조 K = 07, `control_ref` = §470 객체, run `m5p485-c1`; 명세 `08_build/artifacts/m5p485/spec-callout2.json`). 모든 꼴은 §484 ALL 의 바꿈을 포함합니다(B0 의 글이 §484 ALL 과 같음을 python 으로 확인).
- `B0` = §484 ALL(대조)
- `F1` = B0 + 63 행 전방 선언을 `static __inline__ void callout_wakeup(void);` 로
- `F2` = F1 에서 정의의 `__inline__` 을 빼고 전방 선언에만 둠
- `C` = B0 + `calloutEntryRemove(callout_entry_t _entry)` 와 `callout_entry_t entry = _entry;`(Darwin 의 사본 꼴)
- `S` = B0 + `calloutEntryRemove` 의 `if … else if` 를 `switch (entry->status)` 로
- `F1C`·`F1S`·`F2C`·`F2S` = 위 둘씩의 조합
- 판정·관문·고르기: §484.1 과 같습니다(사유 `[]` 또는 bss 하나, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같음, 경고가 K 보다 늘지 않음, x86 K 와 비 STABS 같음). B0 은 §484 `P484__ALL.o` 와 canon·obj_sig 가 같아야 합니다(관문).
- 맞는 꼴이 둘 이상이면 묻고, 없으면 기록만 합니다.

### 485.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): "a2 저장·복원(8 B)" 는 틀렸습니다. 8 B 는 a2 복사(2) + 저장(2) + 복원(4)이고, 저장·복원만은 6 B 입니다. 184 − 130 = 46 + 2 + 2 + 4 = 54 입니다(python).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 명령 사실(복사·한 번 읽기·1 다음 2 비교·갈래마다 따로)이 맞음 | §484 의 나란히 출력 | ✅ |
| 바이트 분해 46 + 2 + 2 + 4 | python | ✅ 위 제 오류 |
| 뒤쪽 정적 함수 여섯은 54 B 밀린 것을 빼면 원본과 같음 | 검토자 비교(재배치 가림) | ⏭️ 맞는 꼴의 L1 이 판정 |
| C 는 사본이 곧 쓰이지 않게 되어 합쳐질 수 있어 약함; Darwin 은 `void *` 공개 형을 형 있는 지역 변수로 바꾸는 꼴 | Darwin `thread_call.h`·838 행; 07 `calloutEntryFree`(415–418 행)가 이미 `void *e` → `callout_entry_t entry = CE(e);` 꼴(plan 256); 바깥 선언 `subr_log.c:64` 은 `calloutEntryRemove(void *)` | ✅ V 를 더함 |
| S 는 꼬리 합치기를 막는다는 보장이 없음 | 설계 판단 | ⏭️ 진단으로 둠 |
| 갈래별 지역 변수(D)와 `register`(DR)를 진단으로 더할 것 | 설계 판단 | ✅ 더함 |
| F1(전방 선언에 `__inline__`)은 경고 없이 같은 자리·같은 인라인을 낼 것으로 예상; Darwin 107 행도 같은 꼴 | Darwin `thread_call.c:107` | ⏭️ 시험이 판정 |
| 다른 공개 함수는 지금 꼴로 같으므로 바꾸지 않음 | §484.2(13 구간 같음) | ✅ |
| 도구 요약은 관문을 다 보지 않음; 명령 수준(복사·a2·갈래) 확인과 전체 L1 을 요구할 것 | 같은 규칙 | ✅ L1 사유와 함수별 바이트 차이 0 을 요구 |
| B0·C·S 는 W 의 경고를 그대로 가지므로 진단으로만 | §484.2 | ✅ |

계획 수정(실행 전 고정): 변형 = K·B0·F1·F2·C·S·F1C·F1S·F2C·F2S 에 더해
- `F1V` = F1 + `calloutEntryRemove(void *e)` 와 `callout_entry_t entry = CE(e);`(07 `calloutEntryFree` 와 같은 꼴)
- `F1D` = F1 + `callout_entry_t delayed_entry = entry;` 를 두고 DELAYED 갈래가 그것을 씀(진단)
- `F1DR` = F1D 에서 `register` 선언(진단)
- 후보가 될 수 있는 꼴은 경고가 없는 F1·F2 계열입니다. 맞는 꼴의 조건은 L1 사유가 `[]` 또는 bss 하나이고 함수별 바이트 차이가 0 인 것입니다.

### 485.2 변형 시험 결과(2026-10-23)

- m68k run `m5p485-c1`·x86 run `m5p485-xc1`(각 13 명령)은 모두 종료 0 입니다.
- 관문:
  - m68k K 는 `control_ref` 와 obj_sig 가 같습니다.
  - B0 은 §484 `P484__ALL.o` 와 canon·obj_sig 가 같습니다.
  - x86 K 는 `control_equals_ref` true 입니다.
- 경고: B0·C·S 만 "declared inline after being called" 한 줄이고, F1·F2 계열은 모두 0 줄입니다(오류 파일의 파일 이름으로 변형을 대조).
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-callout-variants-p485-20261023.json`):
  - **C·F1C·F2C·F1V·F1D·F1DR 은 같은 객체이고, 사유가 `['__DATA,__bss: unverified']` 하나, 함수별 바이트 차이 0 입니다.** `calloutEntryRemove` 에서 매개변수와 갈래별 사본이 따로 놓여 꼬리 합치기가 일어나지 않는 꼴입니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같습니다.
  - F1·F2 는 B0 과 같은 객체입니다. 전방 선언의 `__inline__` 은 코드를 바꾸지 않고 경고만 없앱니다.
  - S·F1S·F2S(`switch`)는 `calloutEntryRemove` 가 그대로 남습니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-callout-variants-p485-20261023.json`):
  - B0·C·F1·F1C·F1V·F2·F2C 는 x86 K 와 같습니다.
  - F1D·F1DR·S·F1S·F2S 는 다릅니다.
- 고르기(§485.1 규칙):
  - 07 본 파일 후보는 경고가 없고 두 아키텍처에서 맞는 F1C·F1V·F2C 셋입니다. 셋은 m68k 객체가 같아 원본 바이트로 구별되지 않습니다.
  - F1·F2 의 차이는 정의에도 `__inline__` 을 두는지 여부입니다. C·V 의 차이는 매개변수 형입니다. C 는 `callout_entry_t _entry`, V 는 07 `calloutEntryFree` 와 같은 `void *e` + `CE(e)` 입니다.
  - 꼴을 사용자에게 묻습니다.

사용자 결정 D100(2026-10-23): 꼴 "F1V (Recommended)"(전방 선언·정의 모두 `static __inline__` 인 `callout_wakeup`, `calloutEntryRemove(void *e)` + `callout_entry_t entry = CE(e);`), 옮길 범위 "아홉 모두 옮김 (Darwin 구조)"(§484 ALL2 의 바탕), 자리는 07 본 파일.

### 485.3 D100 구현 계획(07 본 파일 `callout.c` + x86 전체 재빌드 s6lj; 코딩 전, 2026-10-23)

고른 꼴 G(= §484 ALL2 + F1 의 전방 선언 + V)는 아직 컴파일하지 않았으므로, 먼저 기준 객체를 만들고 대조합니다. 그 뒤는 §483.3 의 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 객체(run `m5p485-g1`·x86 `m5p485-xg1`, 명세 `08_build/artifacts/m5p485/spec-callout3.json`, 변형 K·G·F1V):
   - m68k G 는 사유가 `['__DATA,__bss: unverified']` 하나이고, 함수별 바이트 차이 0, 경고 0, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
   - G 는 같은 run 의 F1V 와 canon·obj_sig 가 같아야 합니다(도우미 여섯의 자리가 코드를 바꾸지 않음).
   - x86 G 는 x86 K 와 비 STABS 로 같아야 합니다.
   - 통과하면 `P485__G.o` 를 REF 로 씁니다.
1. 07 편집(`kern/callout.c`; 고치기 전 파일을 `08_build/artifacts/m5p485/callout.c.main.before` 로 먼저 옮겨 둠):
   - G 의 바꿈을 넣습니다.
   - 표시 `/* plan 485 (D100): … */` 를 붙입니다. 옮긴 도우미 묶음 앞과 `callout_thread` 앞에는 독립 줄 하나씩, 바뀐 줄(세 도우미의 `static`, 두 `return (removed);`, `callout_wakeup` 의 전방 선언·정의, `calloutEntryRemove` 의 매개변수·사본 줄)에는 줄 끝 주석입니다.
   - python 으로 주석을 뺀 토큰이 G 와 같은지 확인합니다(G 는 고치기 전 파일에서 다시 만들고 run 의 스테이징 사본과 대조). 행 수는 706 행 + 독립 표시 줄 수입니다.
2. x86 전체 재빌드 s6lj 와 check 관문.
3. prefixdiff s6li↔s6lj(plan 485): 스테이징 차이는 `src/kern/callout.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-callout']`, 비 STABS 같음.
4. 링크 `l2_link.py prepare s6p485-ln1 s6lj` → `kr_run.py` → `l2_compare.py` → `cmp`.
5. `stage_m68k.py`: `X86[485] = 's6lj'`, `EXCEPTS[485] = dict(EXCEPTS[483], **{'x86-callout': …})`, 문서 줄 셋. `--plan 485 stage m0p485-a1-stage`·`--plan 485 x86gate 08_build/artifacts/m5p485/x86gate`; `m0p483-a1-stage` 와의 파일 항목 차이는 `src/kern/callout.c` 하나.
6. final(run `m5p485-a1`): 기대 사유 `['__DATA,__bss: unverified']`, `bss_records` 는 §483 까지 여덟. zerofill 결과를 `09_validation/reconstruction/m5-m68k-p485-zerofill-20261023.json` 으로 복사하고 SHA-256 을 대조합니다.
7. 기록:
   - PROVENANCE 615 행(`authored`)을 그 자리에서 갱신합니다.
   - MODIFICATIONS·DECISIONS D100·diff `06_reconstruction/evidence/x86-callout-plan485.diff`·`x86-callout.md` 절을 적습니다.
   - `functions.tsv` 의 callout 인용(1989–2008 행)을 옛 줄 내용으로 새 줄을 찾아 옮깁니다. 같은 내용의 줄이 둘 이상이면 멈춥니다. 매개변수 줄이 바뀐 `calloutEntryRemove` 는 함수 이름 줄로 맞춥니다.
   - 집계: "코드 검증 + bss 추정" 26 → 27, 코드 검증 204 → 205/208(98.6%), 코드 차이가 남은 객체 4 → 3(nfs_client, tty, swapfs)입니다(python). "현재 상태와 다음 일" 절도 고칩니다.

### 485.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계 순서는 맞음 | §483.3–483.5 와 나란히 읽음 | ✅ |
| 0 단계에 관문을 더할 것: 새 F1V 가 `m5p485-c1` 의 F1V 와 같음, 명령 종료 0, K↔`control_ref`, x86 K, G 의 SHA-256 고정 | 설계 | ✅ 아래 고정 |
| G = ALL2 + 전방 선언 inline + F1V 의 매개변수 바꿈, 706 행, 정의 순서 | 명세 작성 때 python 으로 만든 글(행 수 706)과 같음 | ✅ |
| 독립 표시 줄 둘로 708 행 | python(706 + 2) | ✅ 1 의 행 수를 708 로 고정 |
| 인용은 `functions.tsv` 1989–2008 행 스물뿐이고 모두 G 에서 한 번씩 나옴; 바뀌는 줄(63·154·173·201·204·232·534·558)은 인용되지 않음, `calloutEntryRemove` 인용은 이름 줄(533) | 구현에서 줄 내용으로 옮기며 하나씩만 맞는지 assert | ✅ "이름 줄로 맞춤" 예외는 필요 없음 |
| `stage_m68k.py` 483 항목, `bss_records` 여덟 | grep, 기록 목록 | ✅ |
| 집계 27·205/208(98.6%)·3 | python | ✅ |

### 485.5 0 단계 결과(2026-10-23) — 관문 하나가 걸려 멈춤

- run `m5p485-g1`·`m5p485-xg1`(각 3 명령)은 모두 종료 0 이고, 경고는 0 줄입니다.
- 통과한 관문:
  - K↔`control_ref` 는 canon·obj_sig 가 같습니다.
  - 새 F1V 는 `m5p485-c1` 의 F1V 와 canon·obj_sig 가 같습니다.
  - G 는 사유 `['__DATA,__bss: unverified']` 하나이고, 함수별 바이트 차이 0, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같습니다.
  - x86 G 는 x86 K 와 같습니다.
- **걸린 관문: G↔F1V 는 canon 은 같지만 obj_sig 가 다릅니다.**
  - 다른 칸은 STABS 수 하나입니다(G 1471, F1V 1470). Mach-O 머리·절 머리·비 STABS 기호는 같습니다.
  - 더 있는 항목은 `queue.h` 에 속한 줄 항목(N_SLINE, type 68) 하나입니다(python, 변형 파일 이름 차이는 뺌). 도우미 여섯의 자리가 바뀌어 인라인된 `queue.h` 줄의 디버그 기록이 하나 늘어난 것으로 봅니다.
  - final 검사(`m5_m68k_final.py`)와 x86 prefixdiff 는 STABS 를 빼고 비교하지만, 이 절의 0 단계 기준은 "canon·obj_sig 같음" 으로 정했습니다. 결과를 본 뒤 기준을 완화하지 않으므로 여기서 멈추고 사용자에게 묻습니다.
- G 의 SHA-256 은 `8edad9fa…`(`08_build/runs/m5p485-g1/out/P485__G.o`)입니다.

사용자 결정(2026-10-23, D100 에 덧붙임): "STABS 빼고 비교, G로 진행 (Recommended)". 0 단계의 G↔F1V 관문은 canon + Mach-O 머리·절 머리·비 STABS 기호(final·prefixdiff 와 같은 범위)로 판정합니다. G 는 이 기준에서 F1V 와 같으므로 `P485__G.o`(SHA-256 `8edad9fa…`)를 REF 로 씁니다. 기준을 바꾼 것은 사용자 결정이며 기록에 그대로 남깁니다.

### 485.6 D100 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p485-final-20261023.json`

- 07 편집:
  - 본 파일 `kern/callout.c` 는 705 → 708 행입니다(G 706 행 + 독립 표시 줄 둘).
  - 주석을 뺀 토큰이 G 와 같고, G 는 run 의 스테이징 사본과 같습니다(python).
  - 고치기 전 파일은 `08_build/artifacts/m5p485/callout.c.main.before` 이고, REF 는 `P485__G.o`(`8edad9fa…`)입니다.
- x86 전체 재빌드 s6lj:
  - 명령 804 개 모두 종료 0, 402 행 1–402 연속, 모두 기준과 같거나 기대대로, problem·deps 차이 0 입니다.
  - prefixdiff s6li↔s6lj: 스테이징 차이는 `src/kern/callout.c` 하나이고, `sha_differ_not_rid_only` 는 `['x86-callout']`(STABS 만)입니다.
  - 링크 `s6p485-ln1` 은 `identical file: True`, `cmp` 같음, 공통 기호 417 / 417 입니다.
- m68k:
  - `stage_m68k.py` 에 `X86[485] = 's6lj'`·`EXCEPTS[485]` 를 등록했습니다(538 → 539 행).
  - stage·x86gate(일곱 모두 같음)를 거쳤고, `m0p483-a1-stage` 와의 차이는 `src/kern/callout.c` 하나입니다.
  - final `m5p485-a1` 은 REF 와 canon·머리·절·기호가 같고, 사유는 bss 하나, 미정의 0 입니다.
  - zerofill(`m5-m68k-p485-zerofill-20261023.json`, 복사본 SHA-256 같음)은 reference-inferred [0x40b45b4, 0x40b4ddc) 2088 B 이고, 이전 여덟 기록과 겹침 0 입니다.
- 집계(python): OBJECT_MATCH 177(+ 명시 배치 1), "코드 검증 + bss 추정" 27 로, 공통부 208 중 205(98.6%)가 코드 검증되었습니다. 코드 차이가 남은 객체는 3 개(nfs_client, tty, swapfs)입니다.
- 기록:
  - PROVENANCE 615 행 그 자리 갱신(1099 행, 중복 0), MODIFICATIONS 643 행, DECISIONS D100
  - diff `06_reconstruction/evidence/x86-callout-plan485.diff`, `x86-callout.md` 절
  - `functions.tsv` 의 callout 인용 스물을 줄 내용으로 옮김(파일 4763 행 그대로)

## 486. M5-43 세부 계획 — m68k `tty`: `ttyblkin` 의 문자 인자 꼴과 `ttread` 의 `TS_TBLOCK` 시험 꼴(07 변경 없음; 코딩 전, 2026-10-23)

남은 셋(nfs_client, tty, swapfs) 가운데 크기 차이가 가장 작은 객체입니다.

확인한 사실(§470 기록, 원본 목록, §470 객체 목록, 07·NeXTMach 를 직접 읽음):
- §470 기록: 객체 텍스트 13714 B, 원본 범위 [0x400cbbe, 0x4010140) 13698 B 로 +16 B 입니다. L1 사유는 `__TEXT,__text`·`__DATA,__bss: unverified` 입니다.
- 함수별 크기는 `ttyblkin`(396/398)과 `ttread`(1008/990)만 다릅니다(python, 객체·원본의 `rts` 경계; `ttread` 는 안에 `rts` 가 여럿이라 한 함수로 셈).
- `ttysetspec`·`ttyinput`·`ttcooked`·`ttyretype` 는 크기가 같고, 숫자를 가린 명령 열도 원본과 같습니다. 차이는 피연산자 숫자뿐입니다. 뒤쪽 함수 자리가 밀린 데서 오는 참조 차이로 봅니다.
- `ttyblkin`(원본 0x400e014):
  - 원본은 끝 고리 앞에서 `clrl d2` 를 한 번 하고, 고리 안에서 `moveb a3@+,d0; moveb d0,d2; movel d2,sp@-` 로 `ttcooked` 의 인자를 넘깁니다. 바이트를 읽은 뒤 0 으로 확장하는 꼴입니다.
  - 우리는 `clrl d0; moveb a3@+,d0; movel d0,sp@-` 입니다. 이 때문에 원본은 레지스터 하나(d4)를 더 쓰고, 나머지 d2/d3 차이가 따라옵니다.
  - 07 1117 행은 `ttcooked(*cp++ & 0377, np);`(계획 245, x86 에 맞춤)이고, NeXTMach mk-108.1 `bsd/tty.c` 는 `ttcooked(*cp++, tp);` 입니다.
- `ttread`(원본 0x400ec0a):
  - 끝의 입력 막힘 풀기 시험이 다릅니다. 원본은 `movel a3@(0x3e:w),d0; btst #10,d0; beq …; btst #24,d0; bne …` 로 두 번 시험합니다. 우리는 `andl #0x1000400,d0; cmpl #0x400,d0` 입니다.
  - `TS_TBLOCK` 은 0x400, `TS_INPUTAVAIL` 은 0x01000000 입니다(스테이징 `bsd/sys/tty.h:131·147`).
  - 07 1809 행은 `(tp->t_state&(TS_TBLOCK|TS_INPUTAVAIL)) == TS_TBLOCK` 입니다. NeXTMach(1508 행)는 `(tp->t_state&TS_TBLOCK)` 만 봅니다.
  - 그 밖에 레지스터 배정이 다릅니다. 원본은 `timing`(`restart:` 뒤 `clrl d4`)을 d4 에 두고 `uio` 를 프레임에서 다시 읽습니다. 우리는 `timing` 을 스택(a6@(−0x20))에, `uio` 를 d7 에 둡니다. 원인은 아직 모르며, 위 두 꼴을 고친 뒤 남는지 봅니다.
- 컴파일 옵션: m68k `-O2`(`08_build/artifacts/m3p430/cc.cmd`), x86 `-O3`. 스테이징 사본은 07 과 SHA-256 이 같습니다(`f6bac0cc…`).

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p485-a1-stage`, 대조 K = 07, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_345__tty.o`, run `m5p486-t1`; 명세 `08_build/artifacts/m5p486/spec-tty.json`):
- `B1`: 1117 행을 `ttcooked((u_char)*cp++, np);` 로 바꿉니다.
- `T1`: 1809 행을 `(tp->t_state&TS_TBLOCK) && (tp->t_state&TS_INPUTAVAIL) == 0 &&` 로 바꿉니다.
- `T2`: 1809 행을 `(tp->t_state&TS_TBLOCK) && !(tp->t_state&TS_INPUTAVAIL) &&` 로 바꿉니다.
- `BT1` = B1 + T1, `BT2` = B1 + T2.
- 판정: 맞는 꼴은 m68k L1 사유가 `[]` 또는 `['__DATA,__bss: unverified']` 이고 함수별 바이트 차이 0, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같고, 경고가 K 보다 늘지 않아야 합니다.
- 관문: 명령 종료 0, 객체 있음, m68k K↔`control_ref` 의 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5, 같은 여섯 변형): 07 본 파일 후보는 x86 K 와 비 STABS 로 같아야 합니다.
- 고르기(미리 정함): 07 본 파일 후보는 두 아키텍처 모두 통과한 꼴입니다. 하나뿐이면 그대로, 둘 이상이면 묻습니다. 맞는 꼴이 없으면 기록만 하고, `ttread` 의 레지스터 배정을 다음 절에서 다룹니다.

### 486.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- "`ttread` 는 안에 `rts` 가 여럿" 은 틀렸습니다. 원본 범위 [0x400ec0a, 0x400efe8) 의 `rts` 는 끝의 하나뿐입니다(python). 제 함수 경계 판별이 `bra` 뒤를 함수 시작으로 잘못 보았습니다. 크기(990/1008)는 한 함수의 크기로 맞습니다.
- "크기 차이가 가장 작은 객체" 는 틀렸습니다. `nfs_client` 는 크기 차이가 0 입니다(§470). `tty` 는 남은 셋 가운데 다룰 근거가 있는 객체로 고친 것입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·줄 번호·플래그 값·명세 적용이 맞음 | §486 작성 때 직접 확인 | ✅ |
| `ttread` 차이 목록: 프레임 28→32 B, `uio` 를 d7 에 둠, `timing` 스택, `t_flags`·마스크·임시 레지스터 바뀜, EOF 비교의 0 확장, 막힘 풀기 시험 | 원본·객체 목록 출력(막힘 풀기 시험·`clrl d3` 위치 직접 확인) | ✅ |
| EOF 비교: 원본은 고리 밖에서 `clrl d3`(0x400eecc), 안에서 `moveb a3@(0x52),d3; cmpl d2,d3`(0x400ef56); 우리는 쓸 때마다 `clrl d0; moveb` | 원본 목록 출력 | ✅ `ttyblkin` 과 같은 꼴(0 확장의 지우기를 고리 밖으로 뺌) |
| VMIN/VTIME 부분의 산술·흐름은 같음 | 검토자 비교 | ⏭️ 시험 결과로 확인 |
| 레지스터 배정의 원인은 가설이고, T1/T2 가 그것을 바꾼다는 보장은 없음 | 설계 판단 | ✅ 가설로 둠 |
| B1 말고도 `u_char *cp`·`u_char` 지역 변수 등이 가능 | 설계 판단 | ⚖️ 이번에는 B1 만 시험하고, 0 확장 꼴이 소스 꼴인지 최적화 차이인지부터 가립니다 |
| `ttysetspec`·`ttyinput`·`ttcooked`·`ttyretype` 은 재배치·밀린 주소만 다름 | 숫자를 가린 나란히 비교(§486) | ✅ |
| 관문은 도구 요약이 아니라 직접 확인(obj_sig·경고·COMMON); 구현 단계는 따로 계획 | §479.1 부터 같은 규칙 | ✅ |

판단: 두 함수의 0 확장 차이가 같은 꼴입니다. 따라서 소스 꼴(B1) 대신 최적화 단계의 차이일 가능성도 있습니다. 이번 시험(B1·T1·T2·BT1·BT2)으로 어느 쪽인지 보고, 남은 차이는 다음 절에서 다룹니다.

### 486.2 변형 시험 결과(2026-10-23)

- m68k run `m5p486-t1`·x86 run `m5p486-xt1`(각 6 명령)은 모두 종료 0, 경고 0 입니다. m68k K↔`control_ref` obj_sig 같음, x86 K `control_equals_ref` true 입니다.
- m68k(기록 `09_validation/reconstruction/m5-m68k-tty-variants-p486-20261023.json`): 맞는 꼴은 없습니다. 다섯 변형 모두 L1 사유가 `__TEXT,__text: unverified` 입니다(텍스트가 자리를 못 잡음).
- 실기 `otool -tv` 로 K·B1·T1·BT1 의 목록을 받아(`08_build/artifacts/m5p486/otool/`) 원본과 나란히 비교했습니다.
  - **B1 은 `_ttyblkin` 을 원본과 완전히 같게 합니다**(124 줄 모두 같음). `(u_char)` 변환이 "고리 밖에서 지우고 레지스터를 거쳐 0 확장" 하는 원본 꼴을 냅니다.
  - **T1(=T2, 같은 객체)은 막힘 풀기 시험을 원본의 `btst #10`·`btst #24` 꼴로 바꿉니다.**
  - 남은 것은 `_ttread` 입니다. 원본과 달리 `uio` 를 d7 에 두고 `timing` 을 스택(a6@(−0x20))에 두며, 이에 따라 t_flags·마스크·임시 레지스터가 바뀝니다.
  - `ttbreakc` 매크로(07 972–975 행) 안의 비교도 남았습니다. 원본은 `t_eofc` 비교에서만 고리 밖에서 지운 d3 을 쓰고(0x400eecc `clrl d3`, 0x400ef56 `moveb a3@(0x52),d3`), `t_brkc` 비교는 그 자리에서 `clrl d0; moveb`(0x400ef5e) 합니다. 우리는 둘 다 그 자리에서 합니다.
- x86(기록 `09_validation/reconstruction/m5-x86-tty-variants-p486-20261023.json`): 여섯 변형 모두 x86 K 와 같습니다.
- 07 은 바꾸지 않습니다. 다음 절(§487)에서 `ttbreakc` 의 0 확장 꼴과 `timing` 의 `register` 선언을 BT1 위에서 시험합니다.

## 487. M5-44 세부 계획 — m68k `tty` `ttread`: `ttbreakc` 의 0 확장 꼴과 `timing` 의 레지스터 배정(07 변경 없음; 코딩 전, 2026-10-23)

확인한 사실(§486.2 의 목록, 07·NeXTMach 를 직접 읽음):
- 07 972–975 행의 `ttbreakc` 매크로는 계획 245 에서 x86 바이트로 작성한 것입니다. 내용은 `((c) == '\n' || (((c) == ((tp)->t_eofc&0377) || (c) == ((tp)->t_brkc&0377)) && (c) != 0377))` 입니다. NeXTMach mk-108.1 은 `ttbreakc` 를 함수로 둡니다(1913 행).
- `ttbreakc` 는 `ttcooked`(1395 행)와 `ttread`(1796 행)에서 쓰입니다. `ttcooked` 는 지금 원본과 같습니다.
- §486 B1 에서 `(u_char)x` 는 원본의 "고리 밖 지우기" 꼴을, `x & 0377` 은 "그 자리 지우기" 꼴을 냈습니다(같은 컴파일러, 같은 옵션).
- 원본 `ttread` 는 `timing` 을 d4 에 둡니다(`restart:` 뒤 `clrl d4`). 07 은 `int timing, lastcc;`(1622 행, `register` 없음)입니다.

가설(시험으로만 가림):
- (가) `ttbreakc` 의 `t_eofc` 비교는 `(u_char)` 꼴입니다. `t_brkc` 비교는 `(u_char)` 이면서 레지스터 사정으로 고리 밖에 나가지 않았거나, `&0377` 꼴입니다.
- (나) `timing` 은 `register` 로 선언되었습니다.
- 레지스터 배정 차이(`uio`·`timing`)는 (가)·(나) 가운데 하나에서 따라 나올 수 있습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `m0p485-a1-stage`, 대조 K = 07, `control_ref` = §470 객체, run `m5p487-t1`; 명세 `08_build/artifacts/m5p487/spec-tty2.json`). 모든 꼴은 §486 BT1(B1 + T1)을 포함합니다.
- `BT1`(대조)
- `E1` = BT1 + `ttbreakc` 의 두 비교를 `(c) == (u_char)(tp)->t_eofc`·`(c) == (u_char)(tp)->t_brkc` 로
- `E2` = BT1 + `t_eofc` 만 `(u_char)`, `t_brkc` 는 `&0377` 그대로
- `R` = BT1 + `register int timing; int lastcc;`
- `E1R`·`E2R` = 조합
- 판정·관문·고르기는 §486 과 같습니다. 변형마다 실기 `otool -tv` 목록으로 `_ttread`·`_ttcooked` 를 원본과 나란히 비교해, 남은 차이를 명령 단위로 적습니다.

### 487.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §486.2 결과가 맞음; 다만 "T1=T2 같은 객체" 는 canon·비 STABS 기준이고, B1 의 `_ttyblkin` 은 재배치를 가린 명령 비교 기준 | 기록과 목록 비교 방법 | ✅ 표현을 그렇게 한정함 |
| 남은 `_ttread` 차이는 프레임(28/32 B), `uio` 를 d7 에 둠, `timing` 스택, 레지스터 바꿈, EOF 0 확장 다섯뿐이고, 크기 차 16 B 는 `timing` 줄들에서 나옴 | BT1 목록과 원본 나란히 비교(§486.2 출력) | ✅ |
| 원본 `_ttcooked` 의 `ttbreakc` 는 두 비교 모두 그 자리 꼴(0x400e7d4·0x400e7de)이고 BT1 이 그것을 재현함 | 원본 목록 출력(위) | ✅ E 변형이 `_ttcooked` 를 깨면 맞지 않는 꼴로 판정 |
| R 은 선언 묶기와 `register` 를 함께 바꾸므로 나누기만 한 대조가 필요 | 설계 | ✅ S·E2S 를 더함 |
| `uio` 쓰임 꼴·다른 변수의 `register` 도 후보 | 설계 판단 | ⏭️ 이번 결과를 본 뒤 |
| 관문: 새 BT1 = §486 BT1, 목록을 객체 해시에 묶음, x86 도 모든 변형, 객체 전체의 L1 로 판정 | 설계 | ✅ |

계획 수정(실행 전 고정): 변형 = K·BT1·E1·E2·R·S·E1R·E2R·E2S(`S` = BT1 + `int timing;` / `int lastcc;` 로 나누기만 함). 관문에 "BT1 이 §486 `P486__BT1.o` 와 canon·obj_sig 같음" 을 더합니다. 맞는 꼴은 객체 전체 L1 사유가 `[]` 또는 bss 하나여야 하고 함수별 바이트 차이 0 이어야 합니다.

### 487.2 변형 시험 결과(2026-10-23)

- m68k run `m5p487-t1`·x86 run `m5p487-xt1`(각 9 명령)은 모두 종료 0, 경고 0 입니다.
- 관문: m68k K↔`control_ref` 는 obj_sig 가 같고, BT1 은 §486 `P486__BT1.o` 와 canon·obj_sig 가 같습니다. x86 K 는 `control_equals_ref` true 입니다.
- m68k(기록 `09_validation/reconstruction/m5-m68k-tty-variants-p487-20261023.json`):
  - E2·R·S·E2R·E2S 는 BT1 과 같은 객체입니다. 이 꼴들은 코드를 바꾸지 않습니다.
  - **E1(=E1R)은 텍스트가 원본 자리에 놓입니다**(사유 `__TEXT,__text: fail`). 실기 목록(`08_build/artifacts/m5p487/otool/E1.txt`)에서 `_ttread` 는 990 B, `_ttcooked` 는 1872 B 로, 숫자를 가린 명령 열이 원본과 같습니다. `uio`·`timing` 의 레지스터 배정과 EOF 0 확장도 원본과 같아졌습니다.
  - E1 의 남은 바이트 차이는 모두 `cmpb #0xff,dN` 의 즉시값 워드입니다. 원본은 `00ff`, 우리는 `ffff` 입니다(0x400cbf4 `0c0100ff` 대 객체 0x36 `0c01ffff` 등, python 으로 원본·객체 바이트를 읽음). `_ttysetspec` 11·`_ttyinput` 2·`_ttyblkin` 2·`_ttcooked` 17·`_ttread` 3·`_ttyretype` 1 곳입니다(L1 `diff_offsets`).
  - 07 의 `(char)0377` 비교 일곱 자리(171·967·1010·1060·1113·1810·2197 행)는 상수 −1 이라 위 바이트가 1 로 채워집니다. 원본은 255 꼴(부호 없는 비교)로 봅니다. x86 은 바이트 즉시값이 1 B 라 이 차이가 드러나지 않습니다.
- x86(기록 `09_validation/reconstruction/m5-x86-tty-variants-p487-20261023.json`): 아홉 변형 모두 x86 K 와 같습니다.
- 07 은 바꾸지 않습니다. 다음 절(§488)에서 E1 위에 `0377` 비교의 부호 없는 꼴을 시험합니다.

## 488. M5-45 세부 계획 — m68k `tty`: `0377` 비교의 부호 없는 꼴(07 변경 없음; 코딩 전, 2026-10-23)

확인한 사실(§487.2):
- E1(§486 B1 + T1 + `ttbreakc` 의 두 `(u_char)`)에서 남은 텍스트 차이는 `cmpb #0xff,dN` 즉시값 워드의 위 바이트뿐입니다(원본 `00ff`, 우리 `ffff`). 36 곳입니다(L1 `diff_offsets`: `_ttysetspec` 11·`_ttyinput` 2·`_ttyblkin` 2·`_ttcooked` 17·`_ttread` 3·`_ttyretype` 1).
- 07 의 `(char)0377` 비교는 일곱 자리입니다(python). 171 행 `SETSPEC` 앞 시험, 967 행 `CCEQ` 매크로의 첫 비교, 1010·1060·1113 행 `t_stopc`, 1810 행 `t_startc`, 2197 행 `t_rprntc` 입니다.
- 해석(가설): `(char)0377` 은 바이트 상수 −1 이라 어셈블러가 즉시값 워드를 `ffff` 로 채우고, 255 로 나오는 꼴이면 `00ff` 가 됩니다. 원본은 부호 없는 비교 꼴로 봅니다. x86 은 `cmpb $0xff` 의 즉시값이 1 B 라 구별하지 못합니다.

방법(`m5_m68k_srcvar.py`, 바탕 `m0p485-a1-stage`, 대조 K = 07, `control_ref` = §470 객체, run `m5p488-t1`; 명세 `08_build/artifacts/m5p488/spec-tty3.json`):
- `E1`(대조, §487 과 같은 글)
- `U` = E1 + 일곱 자리의 `x != (char)0377` 를 `(u_char)x != 0377` 로(CCEQ 의 첫 비교는 `(u_char)(c) != 0377`)
- `U2` = E1 + 같은 자리를 `(x & 0377) != 0377` 로
- 판정: 맞는 꼴은 m68k L1 사유가 `[]` 또는 `['__DATA,__bss: unverified']`, 함수별 바이트 차이 0, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같고, 경고가 K 보다 늘지 않아야 합니다.
- 관문: 명령 종료 0, 객체 있음, m68k K↔`control_ref` canon·obj_sig 같음, E1 이 §487 `P487__E1.o` 와 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- x86(같은 넷): 07 본 파일 후보는 x86 K 와 비 STABS 로 같아야 합니다.
- 고르기(미리 정함): U·U2 가 둘 다 맞으면 묻고, 하나면 그 꼴로 정합니다. 그때 E1 의 바꿈(B1·T1·E1)과 함께 07 본 파일에 넣을지도 묻습니다. T1·T2 가 바이트로 구별되지 않은 것(§486.2)도 함께 묻습니다. 둘 다 맞지 않으면 기록만 합니다.

### 488.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): "36 곳 모두 `cmpb #0xff`" 는 틀렸습니다. 35 곳이 `0377` 비교이고, 한 곳(객체 0x1a2e, 원본 0x400e5ea 의 `cmpb #0x8e,d2`: 원본 `0c02008e`, 우리 `0c02ff8e`)은 07 1320 행 `(char)c != (char)0216`(EUC SS2)입니다. 검토를 맡긴 뒤 제 python 검사(즉시값 워드 위 바이트, 원본 0x00·우리 0xff 를 36 곳 모두 대조)에서 찾아, 명세 U·U2 에 이 자리(`(u_char)c != 0216`, `(c & 0377) != 0216`)를 더했습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 36 곳은 모두 즉시값 워드의 위 바이트이고, 35 곳이 `0377`, 1 곳이 `0216` | python(원본·E1 객체 바이트와 앞 워드 `0c0n` 확인) | ✅ 위 제 오류 |
| 자리별 대응: `SPEC` 11, `CCEQ` 18, 직접 비교 6, EUC 1 | 검토자 표; 일곱 자리 + 1320 행이 모두 명세에 들어 있음(python, 바뀐 글에 `(char)0377`·`(char)0216` 0 건) | ✅ |
| 이미 같은 `cmpl #255` 세 곳(1188 행, `ttbreakc` 975 행)은 그대로 둘 것 | 명세가 그 줄을 바꾸지 않음 | ✅ |
| `(u_char)x`·`x & 0377` 가 `cmpb #255` 를 낸다는 것은 기대일 뿐 | 설계 판단 | ✅ 시험으로 정함 |
| 의미는 두 꼴 모두 바뀌지 않음(8 비트 대상) | 설계 판단 | ✅ |
| 위 바이트는 원본 소스 철자를 증명하지 않음 | 설계 판단 | ✅ 맞는 꼴은 "바이트로 맞는 재구성 꼴" 로 적음 |
| x86 도 새로 빌드해 비 STABS 전체 비교 | 계획 그대로 | ✅ |
| 관문은 직접 확인; otool 은 `00ff`·`ffff` 를 같게 보이므로 바이트로 확인 | 설계 | ✅ L1 함수별 바이트 차이 0 을 요구 |

### 488.2 변형 시험 결과(2026-10-23)

- m68k run `m5p488-t1`·x86 run `m5p488-xt1`(각 4 명령)은 모두 종료 0, 경고 0 입니다.
- 관문: m68k K↔`control_ref` 는 obj_sig 가 같고, E1 은 §487 `P487__E1.o` 와 canon·obj_sig 가 같습니다. x86 K 는 `control_equals_ref` true 입니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-tty-variants-p488-20261023.json`):
  - **U 는 사유가 `['__DATA,__bss: unverified']` 하나이고, 함수별 바이트 차이 0 입니다.** 텍스트는 원본 범위 시작 0x400cbbe, 데이터는 0x40ae25e, bss 는 0x40b3180 에 놓입니다. 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같습니다.
  - U2(`& 0377` 꼴)는 텍스트가 자리를 못 잡습니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-tty-variants-p488-20261023.json`): U 는 x86 K 와 같고, U2 는 다릅니다.
- 고르기(§488 규칙): 맞는 꼴은 U 하나입니다. U 는 다음을 모두 포함합니다.
  - §486 B1(`ttcooked((u_char)*cp++, np)`)
  - T1(`(tp->t_state&TS_TBLOCK) && (tp->t_state&TS_INPUTAVAIL) == 0`)
  - §487 E1(`ttbreakc` 의 두 `(u_char)`)
  - 여덟 자리의 부호 없는 비교
- T1 과 T2(`!(…)`)는 §486.2 에서 바이트로 구별되지 않았으므로 꼴을 사용자에게 묻습니다. 자리(07 본 파일, x86 같음)도 함께 묻습니다.

사용자 결정 D101(2026-10-23): 막힘 풀기 조건 "T1: == 0 꼴 (Recommended)". 꼴은 §488 U(B1 + T1 + E1 + 여덟 자리의 부호 없는 비교)이고, 자리는 지금까지와 같이 07 본 파일입니다(모든 변형에서 x86 원본과 같음).

### 488.3 D101 구현 계획(07 본 파일 `bsd/kern/tty.c` + x86 전체 재빌드 s6lk; 코딩 전, 2026-10-23)

§483.3 의 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p488-t1/out/P488__U.o`(SHA-256 `ea30383b…`, 변형 기록과 대조)를 REF 로 씁니다.
1. 07 편집(`bsd/kern/tty.c`; 고치기 전 파일을 `08_build/artifacts/m5p488/tty.c.main.before` 로 먼저 옮겨 둠):
   - 변형 U 의 바꿈 열한 줄을 넣습니다. 171·967·974·1010·1060·1113·1117·1320·1809·1810·2197 행입니다.
   - 바뀐 줄 끝에 `/* plan 488 (D101): … */` 를 붙입니다. 매크로 줄(967·974)은 주석을 줄 끝(이어짐 `\` 앞)에 둡니다. 주석이 이미 있는 줄(1010)은 그 뒤에 덧붙입니다.
   - python 으로 주석을 뺀 토큰이 U 와 같은지 확인합니다(U 는 고치기 전 파일에서 다시 만들고 run 의 스테이징 사본과 대조). 행 수는 2754 그대로입니다.
2. x86 전체 재빌드 s6lk 와 check 관문.
3. prefixdiff s6lj↔s6lk(plan 488): 스테이징 차이는 `src/bsd/kern/tty.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-tty']`, 비 STABS 같음.
4. 링크 `l2_link.py prepare s6p488-ln1 s6lk` → `kr_run.py` → `l2_compare.py` → `cmp`.
5. `stage_m68k.py`: `X86[488] = 's6lk'`, `EXCEPTS[488] = dict(EXCEPTS[485], **{'x86-tty': …})`, 문서 줄 셋. `--plan 488 stage m0p488-a1-stage`·`--plan 488 x86gate 08_build/artifacts/m5p488/x86gate`; `m0p485-a1-stage` 와의 파일 항목 차이는 `src/bsd/kern/tty.c` 하나.
6. final(run `m5p488-a1`): 기대 사유 `['__DATA,__bss: unverified']`, `bss_records` 는 §485 까지 아홉. zerofill 결과를 `09_validation/reconstruction/m5-m68k-p488-zerofill-20261023.json` 으로 복사하고 SHA-256 을 대조합니다.
7. 기록:
   - PROVENANCE 605 행(`nextmach`, 작성 줄 포함)을 그 자리에서 갱신합니다.
   - MODIFICATIONS·DECISIONS D101·diff `06_reconstruction/evidence/x86-tty-plan488.diff`·`x86-tty.md` 절을 적습니다.
   - `functions.tsv` 의 tty 인용 40 곳(전부 "edited file" 꼴)은 행 수가 같으므로 옮기지 않습니다. 바뀌는 열한 줄은 어느 인용과도 겹치지 않습니다(python). 인용 줄의 내용이 그대로인지 assert 합니다.
   - 집계: "코드 검증 + bss 추정" 27 → 28, 코드 검증 205 → 206/208(99.0%), 코드 차이가 남은 객체 3 → 2(nfs_client, swapfs)입니다(python). "현재 상태와 다음 일" 절도 고칩니다.

### 488.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계·관문은 §483.3–483.5 와 같음 | 나란히 읽음 | ✅ |
| U 는 열한 줄만 바꾸고 2754 행 그대로; REF 해시 맞음 | 명세 작성 때 python; 구현에서 다시 확인 | ✅ |
| 매크로 줄 표시는 토큰을 붙이지 않게 둘 수 있으나, 가장 안전한 것은 위 설명 주석(965·970 행)에 덧붙이는 것; 1320 행 `EUC SS2` 주석도 보존 | `-traditional-cpp` 는 주석을 공백 없이 지울 수 있음(GNU 문서); 965–975 행 출력 | ✅ 매크로 줄에는 주석을 넣지 않고 965·970 행 설명에 덧붙임 |
| tty 인용 40 곳은 "edited file" 34 + 명시 경로 6 이고, 바뀌는 줄과 겹치지 않음 | python(§488.3 작성 때 "edited" 만 셌음) | ✅ 표현을 고침; 구현에서 두 꼴 모두 줄 내용을 assert |
| `stage_m68k.py` 485 항목, `bss_records` 아홉, PROVENANCE 605 행 | grep·기록 목록 | ✅ |
| 집계 28·206/208(99.0%)·2 | python | ✅ |

### 488.5 D101 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p488-final-20261023.json`

- 07 편집:
  - 본 파일 `bsd/kern/tty.c` 는 2754 행 그대로입니다. 주석을 뺀 토큰이 변형 U 와 같고, U 는 run 의 스테이징 사본과 같습니다(python).
  - 매크로 줄(967·974)에는 주석을 넣지 않고 위 설명 줄(965·970)에 덧붙였습니다.
  - `functions.tsv` 의 tty 인용 40 곳은 줄 내용이 그대로입니다(assert).
  - 고치기 전 파일은 `08_build/artifacts/m5p488/tty.c.main.before` 이고, REF 는 `P488__U.o`(`ea30383b…`)입니다.
- x86 전체 재빌드 s6lk:
  - 명령 804 개 모두 종료 0, 402 행 1–402 연속, 모두 기준과 같거나 기대대로, problem·deps 차이 0 입니다.
  - prefixdiff s6lj↔s6lk: 스테이징 차이는 `src/bsd/kern/tty.c` 하나이고, `sha_differ_not_rid_only` 는 `[]`(x86 객체가 STABS 까지 그대로)입니다.
  - 링크 `s6p488-ln1` 은 `identical file: True`, `cmp` 같음, 공통 기호 417 / 417 입니다.
- m68k:
  - `stage_m68k.py` 에 `X86[488] = 's6lk'`·`EXCEPTS[488]` 을 등록했습니다(539 → 540 행).
  - stage·x86gate(일곱 모두 같음)를 거쳤고, `m0p485-a1-stage` 와의 차이는 `src/bsd/kern/tty.c` 하나입니다.
  - final `m5p488-a1` 은 REF 와 서명이 같고, 사유는 bss 하나, 미정의 0 입니다.
  - zerofill(`m5-m68k-p488-zerofill-20261023.json`, 복사본 SHA-256 같음)은 reference-inferred [0x40b3180, 0x40b3184) 4 B 이고, 이전 아홉 기록과 겹침 0 입니다.
- 집계(python): OBJECT_MATCH 177(+ 명시 배치 1), "코드 검증 + bss 추정" 28 로, 공통부 208 중 206(99.0%)이 코드 검증되었습니다. 코드 차이가 남은 객체는 2 개(nfs_client, swapfs)입니다.
- 기록: PROVENANCE 605 행 그 자리 갱신(1099 행, 중복 0), MODIFICATIONS 644 행, DECISIONS D101, diff `06_reconstruction/evidence/x86-tty-plan488.diff`, `x86-tty.md` 절.

## 489. M5-46 세부 계획 — m68k `nfs_client` `nfs_attrcache_va`: `void` 로 선언된 `bcopy` 의 명시 호출(07 변경 없음; 코딩 전, 2026-10-23)

§477 에서 미뤘던 객체입니다. §482(`miniMon`)의 결과를 새 근거로 다시 시험합니다.

확인한 사실(원본·§470 객체 목록, 07, 보관 계획을 직접 읽음):
- 차이는 한 곳뿐입니다. 구조체 대입 `vtor(vp)->r_attr = *va;`(07 `bsd/nfs/nfs_client.c:165`, 58 B → `_bcopy` 0x4092d2c)의 대상 주소를 원본은 d0(0x40262d8–0x40262de `moveq #124,d0; addl a2@(0x2e:w),d0; movel d0,sp@-`)에, 우리는 d1 에 계산합니다. 나머지 명령은 같습니다(나란히 출력).
- 같은 객체의 `nfs_attrcache`(보통 함수 `nattr_to_vattr` 호출)는 원본·우리 모두 같은 계산을 d1 에 합니다.
- 이미 시험한 꼴: §465 B(명시 `bcopy((caddr_t)va, (caddr_t)&…, sizeof (struct vattr))`; 텍스트 1220 B 로 4 B 줄어 자리를 못 잡음)·D, §475 R·R1·R2·O·L·Q·S, §477 V·W(반환형). 모두 맞지 않았습니다.
- 새 근거(§482.2): 같은 컴파일러에서 호출하는 함수의 선언 형만 바꿔도 이웃 임시 값의 레지스터가 바뀌었습니다. `prf` 를 `void` 로 선언하면 d0, `int` 로 선언하면 d1 이었습니다.
- `bcopy` 의 `void` 원형은 SDK `kernserv/prototypes.h:37` 에 있습니다. `nfs_client.c` 가 가져오는 머리(27–44 행)가 이 원형을 보는지는 확인하지 않았습니다. 보지 못하면 §465 B 는 암묵 `int` 호출입니다.

가설(시험으로만 가림): 원본은 구조체 대입 대신 `void` 로 선언된 `bcopy` 를 직접 불렀습니다. 그래서 대상 주소가 d0 에 놓였습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `m0p488-a1-stage`, 대조 K = 07, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_142__nfs_client.o`, run `m5p489-n1`; 명세 `08_build/artifacts/m5p489/spec-nfs_client.json`):
- `B`: §465 B 와 같은 글(대조)
- `BV1`: B + 44 행 뒤 `extern void bcopy();`
- `BV2`: BV1 이되 인자 변환 없이 `bcopy(va, &vtor(vp)->r_attr, sizeof (struct vattr));`
- `BV3`: BV1 이되 크기를 `sizeof *va` 로
- 판정·관문: §486 과 같습니다(m68k L1 사유 `[]` 또는 bss 하나, 함수별 바이트 차이 0, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같고, 경고가 K 보다 늘지 않음; K↔`control_ref` canon·obj_sig; x86 K `control_equals_ref`). 맞지 않는 꼴도 실기 `otool -tv` 로 `_nfs_attrcache_va` 를 원본과 나란히 비교해 남은 차이를 적습니다.
- x86(같은 다섯): 07 본 파일 후보는 x86 K 와 비 STABS 로 같아야 합니다. 명시 호출은 x86 `-O3` 의 구조체 복사와 다를 수 있습니다. 다르면 `#if m68k` 꼴을 다음 절에서 다룹니다.
- 고르기(미리 정함): 맞는 꼴이 하나면 그 꼴, 둘 이상이면 묻습니다. 없으면 기록만 합니다.

### 489.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): 구조체 대입의 07 줄을 164 행으로 적었으나 165 행입니다(고침).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| d0/d1 차이와 이웃 `nfs_attrcache` 의 d1 은 맞음 | §489 나란히 출력 | ✅ |
| §465 B 는 암묵 `int` 호출(이 파일이 가져오는 머리에 `bcopy` 선언 없음) | 검토자 머리 추적; `kernserv/prototypes.h:37` 은 이 번역 단위가 가져오지 않음 | ⚖️ 선언 유무는 KD·BP 로 시험 |
| §465 B 가 4 B 줄어든 것은 `bsr _bcopy` 뒤 스택 정리 두 줄(`addqw #8`·`addqw #4`)이 빠졌기 때문; 명시 호출은 정리를 미루고, 구조체 복사의 라이브러리 호출은 미루지 않음 | `P465__B.o` 와 K 의 바이트: B 는 `…61ff fffffea6 2553…`, K 는 `…61ff fffffea6 504f 584f`; B 도 `727c`(d1) | ✅ 원본은 바로 정리하므로 명시 호출만으로는 맞지 않음 |
| `extern void bcopy();` 는 원형이 아님; SDK 원형으로도 시험할 것 | 설계 | ✅ BP 를 더함 |
| 정리를 미루지 않는 꼴(문장 식 `({ … })`)·`__builtin_memcpy` 도 진단 후보 | 설계 판단 | ✅ SE·SEI·BM 을 더함(GNU 확장이라 진단용) |
| 선언만 둔 대조(KD)가 필요 | 설계 | ✅ |
| 이 객체에는 bss 가 없으므로 OBJECT_MATCH 를 요구할 것(§477 과 같음) | §470 사유(`__TEXT,__text: fail` 하나) | ✅ |
| 도구 요약이 아니라 관문을 직접 확인 | 같은 규칙 | ✅ |

계획 수정(실행 전 고정): 변형 = K·KD·B·BV1·BP·SE·SEI·BM.
- `KD` = K + `extern void bcopy();`
- `BP` = 명시 호출 + `extern void bcopy(const void *, void *, int);`
- `SE` = BP 의 원형 + `({ bcopy(…); });`
- `SEI` = SE 이되 원형 없음
- `BM` = `__builtin_memcpy(&vtor(vp)->r_attr, va, sizeof (struct vattr));`
- BV2·BV3 은 뺍니다.
- 맞는 꼴은 OBJECT_MATCH 여야 합니다. 이번 절은 원인을 가리는 진단입니다. 맞는 꼴이 GNU 확장(SE·BM)뿐이면, 07 에 넣을지와 그 꼴은 따로 묻습니다.

### 489.2 변형 시험 결과(2026-10-23)

- m68k run `m5p489-n1`·x86 run `m5p489-xn1`(각 8 명령)은 모두 종료 0 입니다. 경고는 모든 변형이 K 와 같은 한 줄입니다. m68k K↔`control_ref` obj_sig 같음, x86 K `control_equals_ref` true 입니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-nfs-client-variants-p489-20261023.json`): 맞는 꼴이 없습니다. 객체 바이트로 확인했습니다(python, `pea 0x3a:w` 부터 24 B).
  - 원본: `4878003a 707c d0aa002e 2f00 2f0b 61ff… 504f 584f`(d0)
  - K·KD·SE·SEI·BM: `… 727c d2aa002e 2f01 2f0b 61ff… 504f 584f`(d1, 바로 정리). 다섯은 같은 묶음입니다.
  - B·BV1·BP: `… 727c d2aa002e 2f01 2f0b 61ff… 2553 0028`(d1, 정리를 미뤄 텍스트 1220 B)
  - `bcopy` 의 선언 유무·원형·명시 호출·문장 식·`__builtin_memcpy` 는 대상 주소의 레지스터를 바꾸지 못합니다. §489 의 가설은 반증되었습니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-nfs-client-variants-p489-20261023.json`): K·KD·BM 은 x86 K 와 같고, B·BP·BV1·SE·SEI 는 다릅니다.
- 07 은 바꾸지 않습니다. `nfs_client` 는 §465·§475·§477·§489 네 차례 시험한 꼴(명시 `bcopy` 와 그 선언 꼴, 앞선 선언, `register`, 지역 변수, 조건 나누기, 매개변수 순서, 반환형, 문장 식, 내장 함수)로 풀리지 않았습니다.
  - 남은 차이는 같은 함수의 d0/d1 레지스터 하나이고, 이웃 함수는 같은 계산을 d1 에 둡니다.
  - 새 근거가 생기기 전에는 다시 시험하지 않습니다.
  - 코드 차이가 남은 객체는 그대로 2 개(nfs_client, swapfs)입니다.

## 490. M5-47 세부 계획 — m68k `swapfs` 1 차 진단: `static inline` 열 개를 일반 `static` 으로(07 변경 없음; 코딩 전, 2026-10-23)

남은 둘(nfs_client 보류, swapfs) 가운데 마지막 객체입니다. 차이가 커서, 이 절은 원인을 나누는 진단만 합니다.

확인한 사실(§470 기록, 원본 목록·기호표, 07 을 직접 읽음):
- §470 기록: 객체 텍스트 3762 B, 원본 범위 [0x40326ac, 0x40335f0) 3908 B 로 −146 B 입니다. L1 사유는 `__TEXT,__text`·`__TEXT,__const`·`__DATA,__data`(40 unverified)·`__DATA,__bss: unverified` 입니다.
- 함수 수(앞 명령이 `rts` 인 자리; python): 원본은 29 개, 우리는 18 개입니다. 원본 크기는 126·40·158·130·396·116·88·76·54·56·62·192·238·100·94·206·230·624·30·18·30·626·32·42·64·10·10·14·46 B 입니다.
- 원본 정적 함수의 대응(호출 관계; python): `swapfs_alloc`(0x4032872, 396 B)이 0x403272a(40 B)·0x40327f0(130 B)를 부릅니다.
  - 0x4032aca(76 B, `sleep`)·0x4032b16(54 B, `wakeup`)은 잠금 둘로 봅니다.
  - pagein 으로 보이는 0x4032e32(206 B)는 0x4032752(158 B, `panic`·`printf`)·잠금 둘·0x4032bc2·`_uncompress_data_to_phys` 를 부릅니다.
  - pageout 으로 보이는 0x4032fe6(624 B)는 alloc·잠금·0x4032b4c·0x4032b84·0x4032c82·0x4032f00·`_compress_data_from_phys`·`_logswap` 을 부릅니다.
  - mount 로 보이는 0x40332a4(626 B)는 0x4033286(30 B)·0x40335c2(46 B, `copyout`)를 부릅니다.
  - 원본은 이 도우미들을 따로 둔 함수로 부르고, 그 순서가 07 의 정의 순서와 다른 곳이 있습니다(예: 0x4032752 가 `swapfs_fit` 뒤에, 0x40335c2 가 파일 끝에).
- 07 `bsd/swapfs/swapfs.c`(778 행, 작성 D024, PROVENANCE 1026 행)는 도우미 열을 `static inline` 으로 둡니다. `swapfs_fit`·`findblock`·`write`·`lock`·`unlock`·`getmap`·`rcache`·`wcache`·`invalidate`·`grow` 입니다. m68k `-O2` 는 `inline` 함수를 인라인하므로, 우리 객체는 함수 수가 적습니다(§483 `kdp_udp` 와 같은 꼴).
- 컴파일 옵션: m68k `-O2`(`08_build/artifacts/m3p430/cc.cmd:121`), x86 `-O3`. 스테이징 사본은 07 과 SHA-256 이 같습니다(`a38fecac…`).

방법(`m5_m68k_srcvar.py`, 바탕 `m0p488-a1-stage`, 대조 K = 07, `control_ref` = §470 객체 `O470__L2_384__swapfs.o`, run `m5p490-s1`; 명세 `08_build/artifacts/m5p490/spec-swapfs.json`):
- `N`: 열 개의 `static inline` 을 `static` 으로 바꿉니다.
- 판정: 이 절은 진단입니다. N 의 실기 `otool -tv` 목록으로 함수마다 이름(객체의 지역 기호)과 크기를 원본 함수와 맞대어 표를 만듭니다. 이 표로 순서·본문 차이를 나누고, 다음 절에서 고칠 꼴을 계획합니다. 맞는 꼴이 나오면(사유 bss 하나·함수별 바이트 차이 0) 구현 계획으로 갑니다.
- 관문: 명령 종료 0, 객체 있음, m68k K↔`control_ref` canon·obj_sig 같음, x86 K `control_equals_ref` true. x86 N 이 K 와 같은지도 적습니다(§483 에서 `-O3` 는 `inline` 없이도 인라인했음).

### 490.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

검토자는 원본 29 함수를 07 함수에 대응시킨 표를 냈습니다. 그 가운데 계획에 영향을 주는 주장은 아래와 같고, 모두 N 의 목록으로 함수마다 직접 확인한 뒤에만 씁니다(지금은 ⏭️).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·함수 수·호출 관계 사실은 맞음 | §490 작성 때 python 출력 | ✅ |
| 0x403272a(40 B)는 `swapfs_fit` 이 아니라 조각 해제(07 에 따로 없는 함수); `swapfs_fit` 은 원본에서 따로 나오지 않음 | §490 의 제 대응("swapfs_fit 로 봄")은 추정이었음 | ⏭️ N 목록으로 확인 |
| 0x4032752 = `swapfs_getmap`, 0x40327f0 = `swapfs_findblock` | 같음 | ⏭️ |
| 0x4033286(30 B)는 07 에 따로 없는 sysent 설정 함수이고, 0x40335c2 는 mount 가 주소를 넘기는 `swapfs_getstats` | 원본 목록에서 `pea 0x40335c2` 꼴인지 | ⏭️ |
| 원본 순서는 07 정의 순서와 여러 곳이 다름(getmap 이 findblock 앞, invalidate 가 write 앞, getattr·setattr 가 pagein 앞, getstats 가 끝 등) | 같음 | ⏭️ |
| `rcache`·`wcache` 의 매개변수 순서가 07 과 다름 | 같음 | ⏭️ |
| `compress_data` 는 `cmpl d0,d5` 대 `cmpl d5,d0` 두 바이트만 다름; `uncompress_data` 는 같음 | 같음 | ⏭️ |
| `__data` 200 B 는 배치하면 같고, `__const` "swapfs" 는 0x40acfdb 후보 | 같음 | ⏭️ |
| N 은 진단일 뿐이며 원본의 함수 구성을 그대로 만들지는 못함 | 설계 판단 | ✅ 계획 그대로(진단) |
| m68k obj_sig·x86 N=K 는 직접 확인 | 같은 규칙 | ✅ |

### 490.2 진단 결과(2026-10-23)

- m68k run `m5p490-s1`·x86 run `m5p490-xs1`(각 2 명령)은 모두 종료 0 입니다. m68k K↔`control_ref` obj_sig 같음, x86 K `control_equals_ref` true 입니다. **x86 N 은 x86 K 와 같습니다**(`-O3` 가 `inline` 없이도 인라인).
- 실기 `otool -tv` 로 N 의 목록(`08_build/artifacts/m5p490/otool/N.txt`)을 받았습니다. 객체의 지역 기호로 함수를 나누고, 원본 29 함수와 숫자를 가린 명령 열로 맞댔습니다(python, difflib).
- **명령 열이 원본과 똑같은 함수(18)**:
  - 원본 앞쪽: `logswap`=0x40326ac, `swapfs_getmap`=0x4032752, `uncompress_data`=0x4032a72, `swapfs_lock`=0x4032aca, `swapfs_invalidate`=0x4032b4c, `swapfs_write`=0x4032b84
  - vnode 함수: `swapfs_getattr`=0x4032d70, `swapfs_setattr`=0x4032dd4
  - 뒤쪽: `swapfs_grow`=0x4032f00, `swapfs_inactive`=0x4033256, `swapfs_nlinks`=0x4033274, `swapfs_unmount`=0x4033516, `swapfs_root`=0x4033536, `swapfs_statfs`=0x4033560, `swapfs_sync`=0x40335a0, `swapfs_invalop`=0x40335aa, `swapfs_devblocksize`=0x40335b4, `swapfs_getstats`=0x40335c2
- **거의 같은 함수(7)와 차이**(나란히 비교):
  - `compress_data`(0x40329fe): 원본 `cmpl d0,d5`, 우리 `cmpl d5,d0` 하나
  - `swapfs_unlock`(0x4032b16): `andb #0xfc` 의 레지스터(d1/d0)
  - `swapfs_rcache`(0x4032bc2): 원본은 같은 값을 둘째 인자(a6@(0xc))에서, 우리는 넷째(a6@(0x14))에서 읽음 → 매개변수 순서
  - `swapfs_wcache`(0x4032c82): 원본 셋째(a6@(0x10)), 우리 다섯째(a6@(0x18)) → 매개변수 순서
  - `swapfs_pagein`(0x4032e32): `rcache` 호출의 인자 순서와 레지스터, 스택 정리 자리
  - `swapfs_pageout`(0x4032fe6): `logswap` 호출 인자에서 우리만 `extbl d0` 네 번(07 `logswap` 의 `char` 매개변수 원형), 인자 넣는 자리 하나
  - `swapfs_mount`(0x40332a4): 원본은 sysent 설정을 따로 둔 함수 0x4033286(30 B)으로 부르고, 우리는 그 자리에서 씀; 원본은 `&…->0x32` 를 프레임에 저장해 씀; 레지스터 d6/d7 바뀜
- **할당 묶음**(원본 목록 직접 판독):
  - 0x403272a(40 B)는 `sd->sd_bitmap[block] |= ((1 << nfrag) - 1) << pos;` 만 하는 정적 함수입니다. 07 은 이 식을 `swapfs_alloc`(186 행) 안에 둡니다.
  - 0x40327f0(130 B)는 `swapfs_findblock` 이고, `swapfs_fit` 의 고리가 그 안에 인라인되어 있습니다.
  - 원본 `swapfs_alloc`(0x4032872, 396 B)은 이 둘만 부르므로, 힌트 경로의 `swapfs_fit` 도 인라인입니다. 원본에서는 `swapfs_fit` 만 `inline` 입니다.
- **원본 함수 순서**(29): logswap · 조각 해제 · getmap · findblock · alloc · compress_data · uncompress_data · lock · unlock · invalidate · write · rcache · wcache · getattr · setattr · pagein · grow · pageout · inactive · nlinks · sysent 설정 · mount · unmount · root · statfs · sync · invalop · devblocksize · getstats. 07 의 정의 순서와 여러 곳이 다릅니다.
- `__data` 200 B·`__const` "swapfs" 의 배치는 텍스트가 맞은 뒤 L1 로 확인합니다.
- 다음: §491 에서 이 표대로 07 의 구조를 맞춥니다. 함수 순서, `inline`(fit 만 남김), 조각 해제·sysent 설정 함수 두 개 추가, `rcache`·`wcache` 매개변수 순서, `compress_data` 비교 순서, `logswap` 의 매개변수 형을 다루고, 남은 레지스터 차이(`unlock`·`mount`)는 그 결과를 보고 다룹니다.

## 491. M5-48 세부 계획 — m68k `swapfs` 구조 맞추기: 함수 순서·`inline`·새 정적 함수 둘·매개변수 순서·비교 꼴(07 변경 없음; 코딩 전, 2026-10-23)

§490.2 의 대응표를 바탕으로 07 의 함수 구역을 원본 구성에 맞춥니다.

확인한 사실(원본 목록 직접 판독; §490.2 에 더해):
- 원본 sysent 설정 함수(0x4033286, 30 B)는 `(sp, narg, parallel, call)` 을 받아 `sy_narg`(word)·`sy_parallel`(word)·`sy_call`(long)에 저장합니다. mount 는 이것을 `(0x40adbfc, 1, 0, 0x40335c2)`, 곧 `(&sysent[21], 1, 0, swapfs_getstats)` 로 부릅니다(0x40334d8–0x40334ea). `struct sysent` 는 스테이징 `bsd/sys/systm.h:95–100` 의 short·short·함수 포인터입니다.
- 원본 `pagein` 은 `rcache` 를 `(sd, &src, csize, foff, fragoff)` 로 부릅니다(0x4032e9a–0x4032eaa). `rcache` 본문은 0x8·0xc·0x14·0x18 만 읽습니다(셋째 인자 csize 는 안 씀).
- 원본 `pageout` 은 `wcache` 를 `(sd, sd->sd_cbuf, csize, foff, fragoff)` 로 부릅니다(0x4033226–0x4033236).
- 원본 `compress_data` 0x4032a48 `cmpl d0,d5` 는 `size − (out − dst)` 입니다(우리 `cmpl d5,d0`).
- 원본 `swapfs_unlock` 은 첫 저장값 d1(`flags & ~SD_LOCKED`)에서 `andb #0xfc,d1` 를 합니다(우리는 d0 = `flags` 에서).
- 원본 `pageout` 의 `logswap` 호출에는 `extbl` 이 없습니다. 우리는 `char` 매개변수 원형 때문에 네 번 부호 확장합니다. `logswap` 의 선언·호출은 이 파일 안에만 있습니다(grep).

방법(`m5_m68k_srcvar.py`, 바탕 `m0p488-a1-stage`, 대조 K = 07, `control_ref` = §470 객체 `O470__L2_384__swapfs.o`, run `m5p491-s1`; 명세 `08_build/artifacts/m5p491/spec-swapfs2.json`). 변형은 함수 구역(`logswap` 정의부터 `struct vfsops` 앞까지)을 통째로 바꿉니다. 만드는 스크립트는 scratchpad 의 `swbuild.py` 입니다(함수 덩어리로 나눈 뒤 다시 엮으면 원래 글과 같음을 확인).
- `S`(바탕):
  - 함수를 원본 순서(§490.2)로 엮습니다. `swapfs_fit` 은 `swapfs_findblock` 바로 앞에 둡니다.
  - `static inline` 은 `swapfs_fit` 만 남깁니다.
  - `static void swapfs_release(struct swapfs_data *sd, u_long block, int nfrag, int pos)` 를 `logswap` 뒤에 새로 두고, `swapfs_alloc` 의 비트맵 식을 `swapfs_release(sd, oblock, onfrag, opos);` 로 바꿉니다.
  - `static void swapfs_setsysent(struct sysent *sp, int narg, int parallel, int (*call)())` 를 mount 앞에 새로 두고, mount 의 sysent 세 줄을 `swapfs_setsysent(&sysent[21], 1, 0, swapfs_getstats);` 로 바꿉니다.
  - 두 새 함수의 이름은 원본에 남아 있지 않아 작성한 것입니다(D024).
- `S2`: S 이되 `swapfs_alloc` 의 지역 변수 셋을 없애고 인자에 식을 바로 씁니다(인자 계산 꼴 진단).
- `SP` = S + `rcache(sd, srcp, size, block, off)`·`wcache(sd, src, size, block, off)` 로 매개변수 순서를 바꾸고 두 호출을 맞춥니다.
- `SPC` = SP + `compress_data` 의 `if (out - dst == size)`
- `SPCU` = SPC + `swapfs_unlock` 의 둘째 저장을 `sd->sd_flags &= ~(SD_LOCKED|SD_WANTED);` 로
- `ALL` = SPCU + `logswap` 을 K&R 정의(`char nfrag, pos;`)로
- 판정: 이 절은 구조 단계입니다. 맞는 꼴의 조건은 사유 `[]` 또는 bss 하나(그리고 `__const`·`__data` 가 자리를 잡음)이고 함수별 바이트 차이 0 이며, 경고가 K 보다 늘지 않는 것입니다. 맞지 않으면 각 변형의 실기 목록을 원본 함수와 다시 맞대어 남은 차이를 적고, 다음 절에서 `swapfs_mount` 등 남은 것을 다룹니다.
- 관문: 명령 종료 0, 객체 있음, m68k K↔`control_ref` canon·obj_sig 같음, x86 K `control_equals_ref` true. x86 은 같은 일곱 변형을 비 STABS 로 비교합니다.

### 491.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): 원본 `swapfs_alloc` 은 새 쪽 경로(`sm_nfrag == 0`)에서도 `bitmap[page] = 0xff` 대신 조각 해제 함수를 `(sd, page, 8, 0)` 으로 부릅니다(0x40328aa `clrl sp@-` · `pea 0x8:w` · `movel d5,sp@-` · `movel a2,sp@-` · `bsr 0x403272a`). §491 은 이것을 빠뜨렸습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 새 쪽 경로도 조각 해제 함수를 부름 | 원본 목록 0x40328aa–0x40328b4 출력 | ✅ 위 제 오류; 바탕 S 에 `swapfs_release(sd, page, 8, 0);` 를 더함 |
| ALL 의 정의 순서가 §490.2 와 같고 `swapfs_fit` 만 `inline` | 제 스크립트의 `grep` 출력(정의 순서), `inline` 1 건 | ✅ |
| 조각 해제 함수의 인자 순서·본문, sysent 설정 함수의 형·저장 순서가 원본과 맞음 | 원본 0x403272a·0x4033286 목록; 원본 alloc 의 둘째 호출이 `(sd, block, nfrag, pos)` 순(0x40328d4–0x40328e6, 4 번째 인자 = 하위 4 비트, 3 번째 = `bfextu {24,4}`) | ✅ 바이트는 시험으로 |
| `rcache`·`wcache` 매개변수 순서가 맞음 | §491 의 원본 출력 | ✅ |
| `compress`·`unlock`·`logswap`(K&R) 꼴은 해 볼 만함 | 설계 판단 | ✅ 시험으로 |
| 자료 정의의 상대 순서는 바뀌지 않음(`swpgotcha` 는 `__data`) | 스크립트가 자료 줄을 함수 덩어리 앞에 붙여 옮기며 다른 자료와의 순서를 지킴 | ✅ L1 로 확인 |
| `mount` 는 `bzero` 뒤 `&sn->sn_data` 를 프레임(a6@(−0x14))에 저장하고, 나중에 `sd_fragsize` 를 그 포인터로 씀; 레지스터 d6/d7 도 바뀜 | 원본 0x403333e–0x4033342, 0x40333d2–0x40333d6 출력 | ✅ M1·M2 를 더함 |
| x86 은 고른 꼴 자체로 비 STABS 같음을 요구할 것 | 같은 규칙 | ✅ 받아들임 조건으로 둠 |
| 관문은 직접 확인(obj_sig·경고·지역 함수 단위) | 같은 규칙 | ✅ |

계획 수정(실행 전 고정): 바탕 S 에 새 쪽 경로의 `swapfs_release(sd, page, 8, 0)` 를 더합니다. 변형 = K·S·S2·SP·SPC·SPCU·ALL·ALLM1·ALLM2 입니다.
- `ALLM1` = ALL + mount 에 `struct swapfs_data *sd;` 를 두고, `bzero` 뒤 `sd = &sn->sn_data;`, `sd->sd_fragsize = page_size / 8;`
- `ALLM2` = ALLM1 이되 `sn->sn_data.` 18 곳을 모두 `sd->` 로
- 맞는 꼴의 조건은 m68k 와 x86 모두에서 맞는 것입니다.

### 491.2 변형 시험 결과(2026-10-23)

- m68k run `m5p491-s1`·x86 run `m5p491-xs1`(각 9 명령)은 모두 종료 0, 경고 0 입니다. m68k K↔`control_ref` obj_sig 같음, x86 K `control_equals_ref` true 입니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-swapfs-variants-p491-20261023.json`): 아홉 변형 모두 x86 K 와 같습니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-swapfs-variants-p491-20261023.json`): 맞는 꼴은 아직 없습니다. 텍스트는 ALL 3892 B, ALLM1·ALLM2 3902 B 로 원본 3908 B 에 가까워졌고, 텍스트가 자리를 잡습니다(사유 `fail`).
- ALLM1 의 실기 목록(`08_build/artifacts/m5p491/otool/ALLM1.txt`)을 원본 29 함수와 맞대었습니다(python).
  - **25 함수가 원본과 같습니다**: `swapfs_release`·`findblock`·`rcache`·`wcache`·`pageout`·`mount`(M1 의 `sd` 로 레지스터까지) 등.
  - 남은 넷:
    - `swapfs_alloc` 은 조각 해제 호출의 인자 계산 순서가 다릅니다. 원본은 인자 식을 오른쪽부터 바로 계산합니다. S2(식을 인자에 바로 씀)에서는 이 함수가 차이 목록에 없었습니다.
    - `swapfs_unlock` 은 d0/d1 이 그대로입니다. U 는 효과가 없습니다(SPC = SPCU).
    - `swapfs_pagein` 에서는 원본이 `VOP_PAGEIN` 뒤 스택을 정리하고(`addqw #8`·`addqw #4`) 공통 꼬리로 `bra` 합니다. 우리는 정리를 미룹니다.
    - `swapfs_setsysent` 에서는 원본이 `parallel` 을 먼저 d0 에 읽습니다. 우리는 메모리에서 메모리로 옮깁니다.
  - L(`logswap` K&R)로 `pageout` 의 `extbl` 이 사라졌습니다(ALL ≠ SPCU, `pageout` 같음).
- 07 은 바꾸지 않습니다. 남은 넷은 §492 에서 다룹니다.

## 492. M5-49 세부 계획 — m68k `swapfs` 남은 넷(`alloc` 인자 꼴·`pagein` 꼬리·`unlock`·`setsysent`) 진단(07 변경 없음; 코딩 전, 2026-10-23)

방법(명세 `08_build/artifacts/m5p492/spec-swapfs3.json`, run `m5p492-s1`; 만드는 스크립트는 scratchpad `swbuild.py` 와 같은 덩어리 방식):
- `B`(바탕) = §491 ALLM1 + `swapfs_alloc` 의 S2 꼴(`swapfs_release(sd, sd->sd_map[page].sm_block, sd->sd_map[page].sm_nfrag, sd->sd_map[page].sm_pos);`, 지역 변수 셋 없앰)
- `pagein` 꼴(원본은 공통 꼬리 `swapfs_unlock(vp); return (error);` 를 `rcache` 오류 경로 바로 뒤에 두고, 성공 경로를 그 뒤에 따로 둠):
  - `BP1`: VOP 경로 끝을 `goto out;` 으로, `rcache` 오류 블록 안에 `out:` 라벨
  - `BP2`: `if (csize == page_size) {…VOP…} else if ((error = swapfs_rcache(…)) == 0) {…성공…return (0);}` 뒤 공통 꼬리
  - `BP3`: 두 경로 모두 `goto out;`, `out:` 을 함수 끝에
- `unlock` 꼴: `BU2` = `sd->sd_flags &= ~SD_LOCKED; if (flags & SD_WANTED) { sd->sd_flags &= ~SD_WANTED; …`, `BU3` = `flags` 변수 없이 `sd->sd_flags` 를 읽어 시험
- `setsysent` 꼴: `BSY1` = K&R 정의(`int narg, parallel;`), `BSY2` = K&R `short narg, parallel;`, `BSY3` = 원형 `short narg, short parallel`
- 각 변형은 서로 다른 함수만 건드리므로, 함수별 결과로 꼴을 고릅니다. 실기 목록으로 남은 함수를 원본과 다시 맞댑니다.
- 판정·관문은 §491 과 같습니다. 맞는 꼴들을 합친 꼴은 다음 단계에서 한 번 더 컴파일해 확인합니다.

### 492.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §491.2 의 25 함수 같음·넷 다름이 맞고, 6 B 부족은 `pagein` 4 B + `setsysent` 2 B | python 비교(§491.2) | ✅ "같음" 은 숫자를 가린 명령 비교이고, L1 전체 같음이 아님을 밝혀 둠 |
| 명세의 각 변형은 의도한 함수만 바꿈 | 스크립트가 바탕 B 의 한 덩어리만 바꿈 | ✅ |
| 명시 점프는 미룬 스택 정리를 내보내고, return 은 버릴 수 있음(그 뒤 꼬리 합치기는 되살리지 못함) | 설계 판단 | ✅ 설명을 그렇게 고침 |
| BP1 이 원본 배치(오류 꼬리 다음 성공 경로)에 가장 가까움 | 설계 판단 | ⏭️ 시험이 판정 |
| `unlock` 에는 "첫 줄 `&= ~SD_LOCKED`, 저장한 flags 로 시험, 둘째 `&= ~(LOCKED|WANTED)`" 조합이 빠짐 | 원본 0x4032b36 `andb #0xfc,d1` | ✅ BU4 를 더함 |
| `setsysent`: BSY1 은 설명력이 약하고 BSY2·BSY3 이 그럴듯함 | 설계 판단 | ⏭️ 시험이 판정 |
| `alloc` S2 꼴은 원본의 인자 순서를 재현함(§491 S2 객체) | §491.2 의 S2 결과(`swapfs_alloc` 이 차이 목록에 없음) | ✅ 바탕 B 에 넣음 |
| x86·관문·지역 함수 전체 비교는 합친 꼴에서 다시 | 같은 규칙 | ✅ |

### 492.2 변형 시험 결과(2026-10-24)

- m68k run `m5p492-s1`·x86 run `m5p492-xs1`(각 11 명령)은 모두 종료 0, 경고 0 입니다.
- m68k(기록 `09_validation/reconstruction/m5-m68k-swapfs-variants-p492-20261024.json`; 실기 목록 `08_build/artifacts/m5p492/otool/`, 원본 29 함수와 맞댐):
  - B 는 §491 ALLM1 에서 `swapfs_alloc` 이 원본과 같아졌습니다. 남은 것은 `unlock`·`pagein`·`setsysent` 셋입니다.
  - **BP1 은 `swapfs_pagein` 을 원본과 같게 합니다.** BP2·BP3 은 여전히 다릅니다(꼬리 배치).
  - **BSY2·BSY3 은 `swapfs_setsysent` 를 원본과 같게 하고, 두 객체는 같습니다.** BSY1(K&R `int`)은 B 와 같습니다.
  - BU2·BU3·BU4 는 B 와 같은 객체입니다. `swapfs_unlock` 의 d0/d1 은 그대로입니다.
- x86(기록 `09_validation/reconstruction/m5-x86-swapfs-variants-p492-20261024.json`):
  - B·BU*·BSY* 는 x86 K 와 같습니다.
  - **BP1·BP2·BP3 은 다릅니다.** 명시 `goto` 꼴은 x86 `-O3` 출력도 바꿉니다.
- 07 은 바꾸지 않습니다. 다음 절(§493)에서 `unlock` 의 다른 꼴들과 `pagein` 의 `#if m68k` 꼴(BP1 을 m68k 에만)을 시험합니다.

## 493. M5-50 세부 계획 — m68k `swapfs`: `pagein` 의 `#if m68k` 꼴, `unlock` 의 다른 꼴, 합친 꼴(07 변경 없음; 코딩 전, 2026-10-24)

명세 `08_build/artifacts/m5p493/spec-swapfs4.json`, run `m5p493-s1`(바탕 = §492 B):
- `BP1X`: BP1 의 `goto out;`(VOP 경로 끝)과 `out:`(`rcache` 오류 블록 머리)을 `#if m68k … #else m68k … #endif m68k` 안에만 둡니다. x86 은 전처리 뒤 B 와 같은 글입니다.
- `unlock`: `BU5` = `int flags`, `BU7` = `sd->sd_flags = flags &= ~SD_LOCKED;` 와 `sd->sd_flags = flags & ~(SD_LOCKED|SD_WANTED);`, `BU9` = `u_char flags;` 와 `flags = sd->sd_flags;` 로 나눔
- `ALLX` = BP1X + BSY2(K&R `short`) — 합친 꼴 확인용
- 판정: 함수별로 원본과 맞댑니다(실기 목록). ALLX 에서 `unlock` 만 남으면, 그 결과를 사용자에게 보고하고 꼴(BSY2/BSY3)·자리를 묻습니다.
- 관문: §492 와 같고, x86 은 BP1X·ALLX 가 x86 K 와 비 STABS 로 같아야 합니다.

### 493.1 결과와 진단 추가(2026-10-24)

- 제 절차 오류(먼저 밝힘): §493 은 codex 교차검토 없이 바로 실행했습니다. 07 을 고치지 않는 진단 컴파일이지만, 계획 → 교차검토 → 실행 순서를 건너뛰었습니다. 구현 계획(07 편집) 전에는 교차검토를 거칩니다.
- m68k run `m5p493-s1`·x86 run `m5p493-xs1`(각 7 명령)은 모두 종료 0, 경고 0 입니다.
- **ALLX(BP1X + BSY2)는 `swapfs_unlock` 하나만 원본과 다릅니다**(실기 목록, 원본 29 함수와 맞댐). L1 사유는 `__TEXT,__text: fail`·`__TEXT,__const: unverified`·`__DATA,__bss: unverified` 입니다. `__DATA,__data` 는 자리를 잡았습니다. x86 의 ALLX·BP1X 는 x86 K 와 같습니다.
- `unlock`:
  - BU9 는 B 와 같습니다.
  - BU7 은 d0 만 씁니다.
  - **BU5(`int flags`)는 `andb #0xfc,d1` 로 원본처럼 d1 에서 계산합니다.** 다만 첫머리에 `clrl d0`(u_char→int 0 확장)이 하나 더 있습니다.
  - `flags` 의 형이 레지스터 선택을 정한다는 단서입니다.
- 진단 추가(같은 바탕 B, run `m5p493-s2`): `flags` 의 형을 `char`(BU10)·`short`(BU11)·`u_short`(BU12)·`unsigned`(BU13)·`long`(BU14)로 바꿔 봅니다. 고르기는 맞는 꼴이 나온 뒤 묻습니다.
- 결과(run `m5p493-s2`, 경고 0): BU10(`char`)은 B 와 같은 꼴(d0)입니다. BU11–BU14(`short`·`u_short`·`unsigned`·`long`)는 BU5 와 같이 d1 에서 계산하지만 첫머리 확장이 한 줄 더 있습니다.
- 진단 추가(run `m5p493-s3`): BU15 = 지운 값을 `u_char nflags = flags & ~SD_LOCKED;` 로 따로 두고 둘째 저장을 `nflags & ~(SD_LOCKED|SD_WANTED)` 로, BU22 = `register u_char flags`.
- 결과(run `m5p493-s3`, 경고 0): BU15·BU22 는 B 와 같은 꼴(d0)입니다.

### 493.2 정리(2026-10-24)

- 지금까지 가장 가까운 꼴은 **ALLX**(§492 B + BP1X + BSY2)입니다.
  - m68k 원본 29 함수 가운데 28 개가 숫자를 가린 명령 열로 같고, x86 은 원본과 같습니다(비 STABS).
  - 남은 차이는 다음 둘입니다.
    - `swapfs_unlock` 의 레지스터 하나(원본은 두 번째 마스크를 첫 저장값 d1 에서, 우리는 원래 값 d0 에서 계산; 3 B)
    - `__TEXT,__const`("swapfs" 7 B)의 자리 확인
- `swapfs_unlock` 에서 시험한 꼴(`flags` 의 형 일곱 가지, `&=`/대입 조합 다섯 가지, `register`, 별도 변수)은 맞지 않았습니다. 바이트 형은 d0 꼴, 더 넓은 형은 d1 꼴이지만 0 확장이 한 줄 더 생깁니다.
- 07 은 바꾸지 않습니다. §482(`miniMon`)와 같은 규칙으로, ALLX 를 07 에 넣을지(텍스트 3 B 를 뺀 나머지가 원본과 같아지는 부분 개선)는 사용자에게 묻습니다. 이 경우 `swapfs` 는 집계에서 코드 차이가 남은 객체로 둡니다.
- 바이트로 구별되지 않는 꼴도 함께 묻습니다. `setsysent` 의 BSY2(K&R `short`)·BSY3(원형 `short`), 그리고 BP1X 의 `#if m68k` 표기입니다.

사용자 결정 D102(2026-10-24): `swapfs` 는 "넣음(부분 개선) (Recommended)", `swapfs_setsysent` 는 "원형 short (Recommended)". 꼴 G = §493 ALLX 에서 `swapfs_setsysent` 선언만 원형 `short`(§492 BSY3)로 바꾼 것입니다(python diff 로 차이가 그 줄뿐임을 확인).

## 494. M5-51 D102 구현 계획 — m68k `swapfs` 부분 개선(07 본 파일 `swapfs.c` + x86 전체 재빌드 s6ll; 코딩 전, 2026-10-24)

§488.3 의 절차를 따르되, 맞는 꼴이 아니라 부분 개선이므로 m68k 받아들임 조건을 바꿉니다(미리 정함).
0. 기준 객체(run `m5p494-g1`·x86 `m5p494-xg1`, 명세 `08_build/artifacts/m5p494/spec-swapfs-g.json`, 변형 K·G·ALLX):
   - 관문: 명령 종료 0·경고 0, m68k K↔`control_ref` canon·obj_sig 같음, x86 K `control_equals_ref` true.
   - m68k G 는 같은 run 의 ALLX 와 canon·Mach-O 머리·절 머리·비 STABS 기호가 같아야 합니다(§492 에서 BSY2·BSY3 이 같았음).
   - x86 G 는 x86 K 와 비 STABS 로 같아야 합니다.
   - 통과하면 `P494__G.o` 를 REF 로 고정합니다(SHA-256 기록).
1. 07 편집(`bsd/swapfs/swapfs.c`; 고치기 전 파일을 `08_build/artifacts/m5p494/swapfs.c.main.before` 로 먼저 옮김):
   - 함수 구역을 G 의 글로 바꿉니다.
   - 표시는 주석만 씁니다. 함수 구역 머리(첫 정의 앞)에 `/* plan 494 (D102): … */` 설명 한 덩이를 두어 m68k 원본의 순서·`inline`·두 새 함수·매개변수 순서를 적습니다. 바뀐 줄 끝에는 짧은 `/* plan 494 (D102) */` 를 답니다.
   - python 으로 주석을 뺀 토큰이 G 와 같은지 확인합니다(G 는 고치기 전 파일에서 다시 만들고 run 스테이징 사본과 대조).
2. x86 전체 재빌드 s6ll(접두어 미사용)과 check 관문(§480.3 과 같음).
3. prefixdiff s6lk↔s6ll(plan 494): 스테이징 차이는 `src/bsd/swapfs/swapfs.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-swapfs']`, 비 STABS 같음.
4. 링크 `l2_link.py prepare s6p494-ln1 s6ll` → `kr_run.py` → `l2_compare.py` → `cmp`.
5. `stage_m68k.py`: `X86[494] = 's6ll'`, `EXCEPTS[494] = dict(EXCEPTS[488], **{'x86-swapfs': …})`, 문서 줄 셋. `--plan 494 stage m0p494-a1-stage`·`--plan 494 x86gate 08_build/artifacts/m5p494/x86gate`; `m0p488-a1-stage` 와의 파일 항목 차이는 `src/bsd/swapfs/swapfs.c` 하나.
6. m68k 확인(부분 개선; `m5_m68k_final.py check` 는 사유가 `[]`·bss 하나만 받으므로 쓰지 않음):
   - `m5_m68k_final.py cmd` 로 컴파일 줄을 만들고(run `m5p494-a1`), 07 로 컴파일한 객체가 REF 와 canon·머리·절·비 STABS 기호가 같음을 python 으로 확인합니다.
   - L1 사유를 그대로 기록합니다. 예상은 `__TEXT,__text: fail`·`__TEXT,__const: unverified`·`__DATA,__bss: unverified` 입니다.
   - 실기 목록으로 29 함수 가운데 28 이 원본과 같고 `swapfs_unlock` 만 다른지 다시 확인합니다.
7. 기록:
   - PROVENANCE 1026 행(`authored`) 그 자리 갱신
   - MODIFICATIONS·DECISIONS D102·diff `06_reconstruction/evidence/x86-swapfs-plan494.diff`·`x86-swapfs.md` 절
   - `functions.tsv` 의 swapfs 인용 18 곳(4728–4745 행)은 줄 내용으로 새 줄을 찾아 옮깁니다. 글이 바뀐 `logswap` 정의 줄(122 행)은 새 정의의 이름 줄로 맞춥니다. 같은 내용 줄이 둘 이상이면 멈춥니다.
   - 집계는 바뀌지 않습니다(206/208, 코드 차이가 남은 객체 2). "현재 상태와 다음 일" 절에 `swapfs` 의 남은 차이(`unlock` 3 B)를 적습니다.

### 494.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 순서는 §488 과 같고, D102 가 부분 개선을 허락함 | 나란히 읽음 | ✅ |
| REF 같음은 승인된 부분 결과의 보존일 뿐 원본과 같다는 증명이 아님; "28/29 같음" 은 숫자를 가린 비교 | 같은 규칙 | ✅ 표현을 한정 |
| 6 은 컴파일 종료 0·경고 0·REF 해시 재확인·원본에 없는 미정의 0·L1 사유가 **정확히** 세 가지여야 함(기록만으로는 기준이 약해짐) | `m5_m68k_final.py` 62–84 행이 하던 관문 | ✅ 아래에 고정 |
| `m5_m68k_final.py cmd` 도 `load()` 의 사유 검사 때문에 세 사유 명세를 받지 않음 | `m5_m68k_final.py:32–43` | ✅ 컴파일 줄 생성에만 사유 `[]` 명세를 씀(검사 단계는 쓰지 않음) |
| G 는 ALLX 와 `setsysent` 선언만 다름; 07 대비 함수별 바꿈 표 | 제 python diff(§D102 아래) | ✅ |
| 인용 18 곳은 G 에서 한 번씩 나오고 `logswap` 만 0 번(새 정의 이름 줄로) | 구현에서 표시를 넣은 뒤 다시 줄 내용으로 맞춤 | ✅ |
| `stage_m68k.py` 488 항목·PROVENANCE 1026 행 | grep·출력 | ✅ |
| 표시 주석은 토큰을 바꾸지 않고 STABS 줄 번호만 바꿈; `__const` 자리 문제는 그대로 | 설계 | ✅ |

계획 수정(실행 전 고정): 6 의 받아들임 조건은 다음을 모두 만족하는 것입니다.
- 컴파일 종료 0, 경고 0
- REF(`P494__G.o`) 해시가 0 단계 기록과 같음
- 07 로 컴파일한 객체가 REF 와 canon·Mach-O 머리·절 머리·비 STABS 기호가 같음
- 원본에 없는 미정의 0
- L1 사유가 정확히 `['__TEXT,__text: fail', '__TEXT,__const: unverified', '__DATA,__bss: unverified']`
- 실기 목록에서 숫자를 가린 비교로 29 함수 중 `swapfs_unlock` 만 다름

컴파일 줄은 `m5_m68k_final.py cmd` 에 사유 `[]` 를 둔 명세로 만듭니다(생성 전용). 하나라도 어긋나면 멈추고 보고합니다.

### 494.2 결과 — 0 단계(기준 객체)

- run `m5p494-g1`(m68k)·`m5p494-xg1`(x86): 명령 종료 셋 다 0, 경고 0.
- m68k K↔`control_ref` canon·obj_sig 같음. G↔ALLX canon 같고 머리·절·비 STABS 기호 같음. G·ALLX 의 L1 사유는 `['__TEXT,__text: fail', '__TEXT,__const: unverified', '__DATA,__bss: unverified']`, 원본에 없는 미정의 `[]`.
- x86 `same_as_ref` 가 `["ALLX", "G", "K"]`(K `control_equals_ref` true).
- 기록 `09_validation/reconstruction/m5-m68k-swapfs-g-p494-20261024.json`, `m5-x86-swapfs-g-p494-20261024.json`.
- REF `08_build/runs/m5p494-g1/out/P494__G.o` SHA-256 `d08914789ecda4054f66f009f618934318fc5de06604aea2fc7f5d615026fc60`.

### 494.3 결과 — 1~7 단계(2026-10-24)

- 1: 07 `src/bsd/swapfs/swapfs.c` 를 고치기 전 파일(778 행, SHA-256 `a38fecac…`)을 `08_build/artifacts/m5p494/swapfs.c.main.before` 로 옮겼습니다. 함수 구역을 G 의 글로 바꾸고 주석 표시를 더했습니다.
  - 표시: 설명 덩이 하나(함수 구역 머리), 줄 끝 `/* plan 494 (D102) */` 16 곳, 파일 머리의 계획 번호.
  - 결과는 812 행, SHA-256 `ef33dddeddf76fc5d2521bd5df1ce80ed8032ccc718402550250e7d02c76ce08` 입니다.
  - 주석을 뺀 토큰(4574 개)이 G 와 같습니다. G 는 고치기 전 파일에서 다시 만들었고 run 스테이징 사본 `p494_G.c` 와 같았습니다(python).
- 2: x86 전체 재빌드 s6ll. 일곱 묶음 모두 problems 0 이고, 묶음별 요약 줄이 s6lk 와 같습니다.
- 3: prefixdiff s6lk↔s6ll(`09_validation/reconstruction/s6-l2-prefixdiff-s6lk-s6ll-20261024.json`):
  - 스테이징 차이는 `src/bsd/swapfs/swapfs.c` 하나이고, 키·명령 차이는 없습니다.
  - `sha_differ_not_rid_only` 는 `['x86-swapfs']`(STABS 줄 번호), `differing_non_stabs_equal` true 입니다.
- 4: 링크 `s6p494-ln1`(`09_validation/reconstruction/s6-l2-link-s6p494-ln1.json`). `cmp` 로 원본 `mach_kernel` 과 같습니다(SHA-256 `33469393…`).
- 5: `stage_m68k.py` 에 `X86[494] = 's6ll'`·`EXCEPTS[494]` 와 문서 줄 셋을 고쳤습니다(540 → 541 행).
  - `--plan 494 stage m0p494-a1-stage`: 888 파일이고, `m0p488-a1-stage` 와의 파일 항목 차이는 `src/bsd/swapfs/swapfs.c` 하나입니다.
  - `x86gate`: 일곱 묶음 모두 `same` true, v183 경로 0 입니다.
- 6: m68k run `m5p494-a1`(컴파일 줄은 사유 `[]` 생성 전용 명세 `08_build/artifacts/m5p494/final-cmdgen-spec.json` 로 만듦; 기록 `09_validation/reconstruction/m5-m68k-p494-final-20261024.json`, `ok` true):
  - 명령 종료 0, 경고 0.
  - REF 해시가 0 단계와 같고, 객체가 REF 와 canon·머리·절·비 STABS 기호까지 같습니다.
  - 원본에 없는 미정의 `[]`.
  - L1 `NOT_MATCH`, 사유가 정확히 `['__TEXT,__text: fail', '__TEXT,__const: unverified', '__DATA,__bss: unverified']`.
  - 실기 `otool -tv`(`08_build/artifacts/m5p494/otool/F494.txt`)를 원본 [0x40326ac, 0x40335f0) 과 숫자를 가린 명령 열로 맞댔습니다. 29 함수가 서로 다른 원본 함수 29 개에 대응하고, 28 개가 같으며 `_swapfs_unlock` 만 다릅니다(비율 0.875). 같은 run 의 ALLX 목록과 대응 결과가 같습니다.
  - 이것은 미리 정한 부분 일치이고, 원본과 같다는 증명이 아닙니다.
- 7: 기록.
  - PROVENANCE 1026 행을 그 자리에서 갱신했습니다(1098 행, 경로 중복 0).
  - MODIFICATIONS 644 → 645 행, DECISIONS D102(105 → 106 행).
  - diff `06_reconstruction/evidence/x86-swapfs-plan494.diff`(486 행), `x86-swapfs.md` 절.
  - `functions.tsv` 의 swapfs 인용 18 곳을 줄 내용으로 찾아 옮겼습니다(모두 한 줄씩 대응; `logswap` 122 → 134 새 정의 이름 줄). 저장소에서 추적되는 다른 `swapfs.c:N` 인용은 없습니다(`git grep` 0 건).
  - 집계는 그대로입니다(206/208; 코드 차이가 남은 객체 `nfs_client`·`swapfs`).

