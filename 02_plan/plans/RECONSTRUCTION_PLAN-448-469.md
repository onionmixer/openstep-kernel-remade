# 커널 소스 복원 작업계획 — 보관 §448·§458–469

`02_plan/RECONSTRUCTION_PLAN.md` 의 §448·§458–469(m68k M5: `ns_timer` 의 멈춘 절과 그 뒤 §458–469)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-16, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 에서 완료된 내용은 정리합니다”). §448 은 §468·§469 로 끝났습니다. 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킵니다. 아래는 원문 그대로입니다.

---

## 448. M5-5 세부 계획 — m68k `ns_timer.c`: `ns_div`·`ns_div_val` 의 68020 나눗셈 판(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: 이름 대응 공통부 C 208 가운데 m68k 에서 컴파일되지 않는 마지막 하나가 `kern/ns_timer.c` 입니다. 07 판은 x86 원본에서 작성한 것(계획 234, D024)이고, `static inline` `ns_div`·`ns_div_val` 이 i386 `divl` 인라인 어셈블리와 리틀엔디언 낱말 순서(`lsw = [0]`, `msw = [1]`)를 씁니다.

확인한 사실(원본 m68k 객체 m68k-166 [0x404e420, 0x404eaae), 함수 19 개 기호 순서는 07 과 같음):
- `_ns_time_to_timeval`(0x404e712) 은 다음과 같습니다.
  - `a1 = &ll[0]`(빅엔디언 상위)·`a0 = &ll[1]` 입니다.
  - `clrl d0; movel a1@,d3; divull #1000000000,d0,d3`(32 비트 나눗셈, 나머지 d0)·`movel d3,a1@`(`*msw = quo`) 입니다.
  - `movel d0,d4; movel a0@,d3; divul #1000000000,d4,d3`(64 비트 피제수 d4:d3, 나머지 d4) 뒤 `*remain = d4`, `*lsw = d3` 입니다.
  - 곧 x86 판과 같은 두 단계 나눗셈을 m68k 낱말 순서로 한 것입니다.
- `_sched_usec_elapsed`(0x404e85c) 의 `ns_div_val` 펼침은 첫 몫을 다시 `*msw` 에 씁니다(`movel d2,a6@(0xfff4)`). 이 점이 x86 판(쓰지 않음)과 다르고, 둘째 나눗셈의 몫을 돌려줍니다.
- NeXTMach 의 1990 도구 역어셈(`stand/ot`)은 `divsll …,d1:d2` 처럼 쌍점 꼴(MIT 문법)입니다. 1997 otool 출력은 쉼표 꼴이므로 어셈블러가 받는 꼴은 시험으로 정합니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/kern/ns_timer.c` 를 만듭니다. 두 `static inline` 함수 앞에 `#if m68k` 판을 끼우고, 07 i386 판은 `#else`…`#endif` 로 남깁니다(끼우기만, `plan 448 (m68k)` 묶음).
   - `ns_div`(m68k):
     - `msw = &((unsigned int *)ll)[0]; lsw = …[1];`
     - `asm("divull %2,%1:%0" : "=d" (quo), "=d" (rem) : "dmi" (divisor), "0" (*msw), "1" (0)); *msw = quo;`
     - `asm("divul %2,%1:%0" : "=d" (quo), "=d" (*remain) : "dmi" (divisor), "0" (*lsw), "1" (rem)); *lsw = quo;`
   - `ns_div_val`(m68k): 같은 두 단계에 `*msw = quo` 를 넣고 둘째 몫을 돌려줍니다.
2. 변형 시험(한 run)을 합니다.
   - V1 은 쌍점 꼴 `%1:%0`, V2 는 쉼표 꼴 `%1,%0` 입니다.
   - 어셈블러가 받고 원본과 같은 쪽을 고릅니다. 둘 다 받고 결과가 같으면 1990 NeXT 문법인 쌍점 꼴을 씁니다.
3. 고른 꼴로 덮어쓰기를 확정하고 컴파일한 뒤 객체 전체를 비교합니다(외부 구간 19 개).
   - 미리 정한 기준: `x86-ns_timer` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0. 아니면 구간별 진단 후 다시 시도합니다.
   - 참고: §423 은 이 객체 둘레의 정적 참조 다리(run 172)를 미결로 두었습니다.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ns_timer.diff`, `09_validation/reconstruction/m5-m68k-ns_timer-20261009.json`. 이것으로 이름 대응 공통부 C 208 이 모두 m68k 로 컴파일됩니다.

### 448.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정 — 범위를 좁힘

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 인라인 나눗셈 자리는 넷(`ns_time_to_timeval`·`ns_time_to_tsval`·`get_calendar_time_value` 의 `ns_div`, `sched_usec_elapsed` 의 `ns_div_val`)이고 모두 계획한 C 꼴과 맞음(첫 나눗셈 32/32·나머지 0 입력·`*msw = quo`, 둘째 64/32); `microtime`·`microboot` 는 `bsr 0x404e712` | §448 사실의 두 함수 목록 읽음, 나머지는 검토자 판독(확장 낱말 해독 포함) | ⚖️ 둘은 확인, 둘은 실행으로 확인 |
| 제수 제약은 `"dmi"`(NeXT gcc-2.7.2 `longlong.h:436-441` `udiv_qrnnd` 와 같음); MIT 꼴은 `divu%.l %4,%1:%0` → `divul ea,Dr:Dq` | 검토자 인용(직접 미확인) | ⏭️ 변형 시험이 판정 |
| **m68k `ns_timer.c` 는 다른 구현(콜아웃 큐)**: `_ns_timeout` 이 `_ns_abstimeout(proc, arg, 64 비트 시각, pri)` 를 부름, `_ns_timer_init` 이 정적 처리기 0x404e458 을 `__set_timer_expire_func` 에 등록, 공통 기호 `_ns_callfree`·`_ns_callout`·`_ns_calltodo`·`_hardclock_pc`·`_hardclock_ps` 는 m68k 에만 있음 | 원본 0x404e53a–0x404e57e·0x404e3f8–0x404e41e 읽음, 두 기호표 grep(x86 에는 0 건) | ✅ |
| 객체 범위는 [0x404e3a8, 0x404eaae)(`_ns_callout_init`·`_ns_timer_init` 포함), 외부 함수 19 + 정적 1; 함수 크기: `ns_abstimeout` 230·`ns_untimeout` 106 B 등 | 기호 사이 거리 python 계산 출력 | ✅ "19 개 07 과 같음" 은 **내 오류** |
| 참고 코드 없음: Darwin `kern/ns_timer.c` 는 `ns_abstimeout` 이름만 같고 큐·`set_timer_expire_func` 없음 | Darwin 파일 grep(이름 줄만), NeXTMach grep 0 건 | ✅ 큐 구현은 원본 바이트에서 작성해야 함(D024) |
| 끼우기 묶음 꼴(`#if m68k … #else` + `#endif`)은 파생 검사와 맞음 | §444 선례 | ✅ |
| `ns_sleep` 의 pri 1(원본 `pea 0x1`) 등 그 밖의 차이 | 미확인 | ⏭️ 진단 대상 |

고친 범위(실행 전 고정):
- **§448(이번)**: `ns_div`·`ns_div_val` 의 m68k 판만 넣어 `ns_timer.c` 를 m68k 로 **컴파일**되게 합니다(이름 대응 공통부 C 208/208).
- 미리 정한 기준(변경):
  - 컴파일 성공, 원본에 없는 새 미정의 기호 수를 기록합니다(`_calloutDispatchDelayed`·`_calloutRemove` 는 원본에 없을 것으로 예상 — 큐 구현 전의 알려진 차이).
  - 인라인 자리 네 함수의 외부 구간이 원본과 같아야 합니다.
  - 객체 OBJECT_MATCH 는 이번 목표가 아닙니다.
- 어셈블러 꼴: 변형 V1(쌍점)·V2(쉼표) 를 한 run 에서 시험합니다.
- **다음 절**: m68k 콜아웃 큐(`ns_callout_init`·`ns_timer_init`·정적 처리기·`ns_timeout`·`ns_abstimeout`·`ns_untimeout`·`ns_sleep` pri, 공통 기호 정의 자리)를 원본에서 작성합니다.

### 448.2 결과(2026-10-09) — 미리 정한 기준 불성립, 멈춤(07 변경 없음)

도구 `10_tools/reconstruction/m5_m68k_ns.py`(변형 생성·컴파일 명령·구간 비교). 해시는 `08_build/artifacts/m5p448/tools-pre.sha` 에 있습니다(둘째 run 전에 도구를 고쳐 둘째 줄 추가; 처음 고친 판은 `reorder` 개수 검사가 틀려 실행 전에 바로잡음).
- 시도 1(run `m5p448-var1`): V1(쌍점 `%1:%0`)·V2(쉼표 `%1,%0`) 를 시험했습니다.
  - 둘 다 어셈블되었고 객체도 같습니다(STABS 제외, `canon` 비교).
  - 외부 구간 17 가운데 `set_calendar_time_value`·`ticks_to_ns_time`·`timeval_to_ns_time` 셋만 원본과 같습니다. 인라인 나눗셈 네 함수는 다릅니다.
  - 원본에 없는 미정의 기호는 0 입니다(`_calloutDispatchDelayed`·`_calloutRemove` 도 원본에 있음).
- 시도 2(run `m5p448-var2`): 입력 피연산자 순서 B·C(NeXT gcc-2.7.2 `longlong.h:436-441` `udiv_qrnnd` 꼴)·D 를 시험했습니다. 세 변형 모두 V1 과 같은 명령열이었습니다.
- 남은 차이(`_ns_time_to_timeval`, 실기 otool 목록):
  - 원본은 `clrl d0` 을 값 적재(`movel a1@,d3`)보다 먼저 합니다.
  - 둘째 나눗셈에서 원본은 나머지 d4·몫 d3(`divul #…,d4,d3`)인데, 다시 만든 객체는 나머지 d3·몫 d4 입니다.
  - 즉 asm 출력 피연산자 쪽의 레지스터 배정 차이이고, 입력 순서로는 바뀌지 않습니다.
- 판정:
  - 같은 덩어리가 두 시도 연속 줄지 않았으므로 §446 의 멈춤 기준에 따라 멈춥니다.
  - `ns_timer` 덮어쓰기는 07 에 넣지 않았습니다(컴파일은 되지만 인라인 자리 기준 불성립).
  - 콜아웃 큐(§448.1) 때문에 객체 OBJECT_MATCH 는 어차피 다음 절의 작성 뒤에야 가능합니다.
- 다음 후보(사용자 확인):
  - (가) 출력 순서 바꾸기(`"=d" (rem), "=d" (quo)` 와 `%0:%1`)·`register` 변수 묶기 등 asm 꼴 변형을 한 run 에 더 시험합니다.
  - (나) 먼저 m68k 콜아웃 큐를 원본에서 작성하고 나눗셈은 그 뒤에 다룹니다.


## 458. M5-15 세부 계획 — m68k `in_pcb`: MULTICAST 블록의 `ifp` 꼴(작성 블록의 소스 꼴)과 범용 변형 시험 도구(x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- 남은 소스 꼴 문제 여섯 객체의 지금 상태(§441 run 객체, python `compare_object`; 원본에 없는 미정의 기호는 모두 0):

| 객체 | L1 | 다른 외부 구간(객체/원본 B) |
|---|---|---|
| `in_pcb` | NOT_MATCH(`__text` 미검증) | `_in_pcbconnect` 568/570 |
| `ip_output` | 같음 | `_ip_output` 1318/1326 |
| `ip_icmp` | NOT_MATCH(`__text` fail, 참조 13 다름) | `_icmp_sendMaskPacket` 452/454 |
| `tcp_input` | NOT_MATCH(미검증) | `_tcp_input` 4092/4096, `_tcp_mss` 290/288 |
| `vfs_dnlc` | 같음 | `_dnlc_init` 130/138, `_dnlc_enter` 362/392, `_dnlc_enterSymLink` 170/196, `_dnlc_lookup` 206/234, `_dnlc_purge1` 374/402 |
| `vm_kern` | 같음 | `_kmem_alloc` 56/60, `_kmem_alloc_wired` 36/40, `_kmem_alloc_zone` 36/40 |

- 이번 절은 `in_pcb` 만 다룹니다. §436 진단(보관 §436.2): `_in_pcbconnect` 의 차이는 덩어리 둘입니다.
  - 원본에만 `movel d0,a0`(0x401fba2)이 있습니다(07 247–249 행).
  - 원본은 `cmpl a2@(0x20),a0`, 객체는 `cmpl a2@(0x20),d0` 입니다(250 행).
- 원본 m68k(0x401fb92–0x401fbae): `movel a5@(0x38),a0; tstl a0; beq; addal a0@(4),a0`(`mtod`), `movel a0@,d0; beq`(`imo_multicast_ifp` 시험), `movel d0,a0`(`ifp` 를 주소 레지스터로), 루프 `cmpl a2@(0x20),a0`.
- 07 `bsd/netinet/in_pcb.c`(479 행) 236–258 행은 계획 166 의 작성 블록(x86 원본 기준)이고, 247–248 행은 `ifp = imo->imo_multicast_ifp;` / `if (ifp) {` 입니다.
- 참고 코드: Darwin 0.1 `kernel/bsd/netinet/in_pcb.c:450–451` 은 `if (imo->imo_multicast_ifp != NULL) {` / `ifp = imo->imo_multicast_ifp;` 입니다(값을 먼저 시험하고 그다음 `ifp` 에 넣음). NeXTMach `mk-108.1/netinet/in_pcb.c` 와 net2 에는 이 블록이 없습니다(grep 0).
  - 이 꼴이면 시험한 값(d0)을 다시 쓰면서 `ifp` 를 주소 레지스터에 옮길 수 있어 원본의 `movel d0,a0` 과 맞을 것으로 봅니다.
- 07 `in_pcb.c` 에는 Darwin 고지가 없습니다(grep 0). Darwin 과 글자가 같은 줄을 넣으면 D061 선례대로 고지가 필요합니다.
- 컴파일 줄은 §429 `m3p429-cc2/run.cmd` 에 있습니다.

방법:
1. **범용 변형 시험 도구**(새 파일 `10_tools/reconstruction/m5_m68k_srcvar.py`, 07 변경 없음):
   - 입력: JSON 명세(대상 파일, 바탕 스테이징, 변형마다 "07 본 파일의 정확한 글 → 바꿀 글" 목록).
   - `stage`: 바탕 스테이징을 manifest 로 검사해 복사하고, 변형 소스 `p<plan>_<V>.c` 를 같은 디렉터리에 둡니다(바꿀 글이 정확히 한 번 나오는지 검사).
   - `cmd`: §430 `cc.cmd` 또는 §429 run 의 `-c` 줄에서 입력·출력만 바꿉니다.
   - `compare`: L1·외부 구간·원본에 없는 미정의 기호·공통 기호·비 STABS 같음 묶음.
   - 다음 객체들(`ip_output` 등)에도 이 도구를 씁니다.
2. 변형(07 247–248 행만 바꿈):
   - `K`: 바꾸지 않음(대조, §441 객체와 비 STABS 같아야 함)
   - `D`: Darwin 꼴 `if (imo->imo_multicast_ifp != NULL) {` / `ifp = imo->imo_multicast_ifp;`
   - `A`: `if (imo->imo_multicast_ifp) {` / `ifp = imo->imo_multicast_ifp;`(Darwin 과 글자가 다름)
3. 고르기 규칙(실행 전 고정): OBJECT_MATCH 인 변형이 하나면 그 꼴. D·A 가 둘 다 맞고 서로 같으면 사용자에게 묻습니다(Darwin 꼴은 고지 필요). 없으면 진단 뒤 멈춥니다.
4. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/netinet/in_pcb.c`(247–248 행을 `#if m68k` … `#else` 07 줄 `#endif`), 도구 등록, 스테이징·x86 관문·`cmd2`·`final`.
5. 미리 정한 기준: `x86-in_pcb` OBJECT_MATCH, 원본에 없는 미정의 기호 0.
6. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-in-pcb.diff`, `09_validation/reconstruction/m5-m68k-in-pcb-variants-20261015.json`·`m5-m68k-in-pcb-20261015.json`.

### 458.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 여섯 객체의 크기·미정의 0 은 맞으나, 표의 "같음" 은 "위와 같은 NOT_MATCH(미검증)" 이고 OBJECT_MATCH 가 아님 | §458 준비 중 python 출력: 다섯은 `__text: unverified`, `ip_icmp` 만 `fail`·참조 13 | ✅ **제 표기 정정**(아래 표 대신 이 줄이 기준: 여섯 모두 NOT_MATCH) |
| `in_pcb` 덩어리 둘·원본 명령·07 247–248 행·Darwin 450–451 행·NeXTMach·net2 에 없음 | §458 준비 중 확인(진단 기록, 이미지 목록, `grep -c` 0) | ✅ |
| 생성 코드는 미확인; 대안 변형으로 `register` 선언, 바깥 `ifp` 재사용(안쪽 선언 없앰), `for` 머리에 조건 합치기를 미리 정할 것 | 07 190 행에 바깥 `struct ifnet *ifp;` 있음(읽음), 244 행이 안쪽 선언 | ✅ 변형 R·O·DO·F 추가 |
| 범용 도구: 명세·본 파일·바탕 manifest·컴파일 줄·도구 해시 기록, 정확히 한 번 바꾸기·겹침 금지, `-c` 줄 정확히 하나(§430 에는 `in_pcb` 없음 → §429), 새 run ID, K 재현 필수 | §430 `cc.cmd` 에 `in_pcb.c` 0 건(grep), 설계 | ✅ 도구 요건에 넣음 |
| 시험 전용 스테이징은 x86 관문 불필요, 최종 덮어쓰기에서만 | 앞 절들과 같음 | ✅ |
| A 꼴도 Darwin 451 행의 대입 줄과 같은 글을 담음 — 고지 면제 근거 없음 | 07 247 행 `ifp = imo->imo_multicast_ifp;` 는 이미 계획 166 작성 줄로 07 에 있음(들여쓰기만 다름) | ⚖️ D·A 어느 쪽이든 맞으면 고지 여부를 사용자에게 함께 물음 |
| 받아들임 기준: K 불일치면 고르기 중단, 고른 변형은 OBJECT_MATCH + 새 미정의 0, 맞는 변형이 여럿이고 서로 다르면 처리 규칙, 공통 기호·기호 정의 확인, 최종 덮어쓰기 객체 = 고른 변형(비 STABS) | 설계 | ✅ 아래 규칙으로 고정 |

수정한 방법(실행 전 고정):
- 변형: `K`(그대로) · `D`(Darwin 꼴) · `A`(`!= NULL` 없음) · `R`(K + `register struct ifnet *ifp;`) · `O`(K + 안쪽 선언 244 행 없앰, 바깥 `ifp` 사용) · `DO`(D + O) · `F`(K 의 루프를 `for (ia = in_ifaddr; ia && ia->ia_ifp != ifp; ia = ia->ia_next) ;` 로).
- 도구 `m5_m68k_srcvar.py` 요건: 명세 JSON·07 본 파일·바탕 manifest·컴파일 줄·도구의 SHA-256 을 기록에 남김; 바탕 스테이징 manifest 전 항목 해시 검사; 바꿀 글은 정확히 한 번, 바꿈끼리 겹치지 않음; `-c` 줄 정확히 하나; 결과에 객체 SHA·종료 상태·L1·외부 구간·원본에 없는 미정의 기호·공통 기호·외부 정의 기호·비 STABS 같음 묶음.
- 고르기: K 가 §441 객체와 비 STABS 로 같지 않으면 고르지 않고 멈춤. OBJECT_MATCH + 새 미정의 0 인 변형이 하나면 그 꼴. 여럿이면(서로 같든 다르든) 사용자에게 묻고, Darwin 글이 들어가는 꼴은 고지가 필요함을 함께 알림. 없으면 진단 뒤 멈춤.
- 최종: 덮어쓰기 객체가 고른 변형과 비 STABS 로 같아야 함, 공통 기호 없음 확인. 등록은 `MARKERS['plan 458 (m68k)']`(고지 줄 포함 수), `EXCEPTS[458]`(457 의 열둘 + `x86-in_pcb`), `--plan` 목록, `FILES['in_pcb']`.

### 458.2 결과(2026-10-15) — 기록 `09_validation/reconstruction/m5-m68k-in-pcb-variants-20261015.json`(변형), `m5-m68k-in-pcb-20261015.json`(최종)

변형 시험(새 도구 `10_tools/reconstruction/m5_m68k_srcvar.py`, 명세 `08_build/artifacts/m5p458/spec.json`(무시 대상, 기록에는 해시만), run `m5p458-var1`, 7 명령 모두 종료 0, 실행 전후 해시 같음):
- 대조 K 는 §441 객체와 비 STABS 같음(통과)입니다.
- **OBJECT_MATCH 는 DO 하나**(Darwin 꼴 시험 + 안쪽 `ifp` 선언 없음)입니다. 원본에 없는 미정의 기호 0, 공통 기호는 K 와 같습니다.
- 비 STABS 같음 묶음: {A, D, F, K, R}, {DO}, {O}. 즉 Darwin 꼴만으로도(D), 바깥 `ifp` 만으로도(O) 맞지 않고 둘이 함께일 때만 맞습니다.
  - Darwin 0.1 은 안쪽 `struct ifnet *ifp;` 를 선언하지만(447 행), 원본 m68k 는 그 선언이 없는 꼴과 맞습니다.
  - A 와 바깥 `ifp` 의 조합(`!= NULL` 없음)은 시험하지 않았습니다(미리 정한 변형 밖). D 와 A 가 같은 바이트였으므로 그 조합도 같을 가능성이 높습니다. 고른 꼴은 시험에서 유일하게 맞은 DO 입니다.
- 경고(`insque`·`remque` 형)는 대조 K 와 같은 기존 경고입니다.

07 덮어쓰기와 최종:
- `v183.34/m68k/src/bsd/netinet/in_pcb.c`(새 파일, 515 행, 표시 줄 36):
  - 244 행 안쪽 선언을 `#ifndef m68k` 로 뺐습니다.
  - 247–248 행은 `#if m68k` 묶음에 Darwin 450–451 행(줄마다 `plan 458 (Darwin)` 표시)을 두고 `#else` 에 07 줄을 둡니다.
  - Darwin 과 글자가 같은 두 줄이 있으므로, §455 선례대로 6 행 뒤에 Darwin 파일 1–23 행 APSL 고지를 넣었습니다.
  - m68k 쪽 코드 줄은 변형 DO 와 같습니다(python).
- 도구 등록: `MARKERS`(36)·`EXCEPTS[458]`·`--plan` 목록·`FILES['in_pcb']`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 은 같습니다.
- **run `m5p458-a1`**(종료 0, 대조 K 와 같은 경고): **`x86-in_pcb` OBJECT_MATCH**, 외부 구간 11/11 같음, 원본에 없는 미정의 기호 0, 변형 DO 와 비 STABS·공통 기호 같음입니다.
- 기록: diff `06_reconstruction/evidence/m68k-in-pcb.diff`, PROVENANCE 1087 → 1088(출처 `nextmach+darwin01`), MODIFICATIONS 613 → 614.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 162 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 163 입니다.

## 459. M5-16 세부 계획 — m68k `ip_output`: 레지스터 배정 차이의 소스 꼴 찾기(변형 시험; x86 트리 변경 없음; 코딩 전, 2026-10-15)

확인한 사실:
- §441 객체 `O441__L2_314__ip_output.o`(컴파일 줄 §429 run): NOT_MATCH(`__text` 미검증), 외부 구간 9 개 중 `_ip_output` 만 다름(객체 1318 B, 원본 1326 B), 원본에 없는 미정의 기호 0.
- §436 진단(`m3-m68k-diag3-20261009.json`, 덩어리 71 = R 57·X 12·DEL 1·INS 1, 호출 차이 0)은 모두 레지스터 배정에서 나옵니다.
  - 원본: `ro`(셋째 인자) → d4(데이터 레지스터; 쓸 때마다 `movel d4,a1`), `mopts`(다섯째 인자) → a4, `imo = mtod(mopts, …)` 를 `addal a4@(4),a4` 로 **같은 a4 에서** 계산, `imo = NULL` 은 `subal a4,a4`, 198 행 `tstl a4`·`tstb a4@(5)`, `ifp` → a5, `error` → d2, `map = nb_map(nb)` → a4(뒤쪽; §459.1 정정).
  - 객체: `ro` → a5, `mopts` → d2, `imo` → d1(`movel d2,d1; movel d2,a1; addl a1@(4),d1`, `clrl d1`), `ifp` → a4, `error` → d3, `map` → a2.
  - 크기 차 8 B 는 주로 `imo` 를 데이터 레지스터에 두어 생긴 옮김(`movel d1,a1`)과 `ro` 쪽 차이의 합입니다.
- 07 `bsd/netinet/ip_output.c` 의 해당 부분은 계획 175 작성(x86 원본 기준)입니다: 다섯째 인자 `struct mbuf *mopts;`(67 행), 함수 범위 `struct ip_moptions *imo;`(78–80 행 `#ifdef MULTICAST`), 164–170 행 `if ((flags & IP_MULTICASTOPTS) && mopts != NULL) { imo = mtod(mopts, …); … } else { imo = NULL; … }`, 198 행 `(imo == NULL || imo->imo_multicast_loop)`.
- 참고 코드: NeXTMach 에는 이 MULTICAST 블록이 없고, Darwin 0.1 `ip_output.c:108–113` 은 다섯째 인자 자체가 `struct ip_moptions *imo` 입니다(mbuf 가 아님; 220 행 `if (imo != NULL)`).
- 원본의 "같은 레지스터에서 `mtod`" 는 다섯째 인자와 `imo` 가 한 변수(또는 같은 레지스터로 묶인 두 변수)였음을 시사합니다.

방법:
1. `m5_m68k_srcvar.py` 로 변형 시험(07 변경 없음, 명세 `08_build/artifacts/m5p459/spec.json`, 바탕 `m0p458-a1-stage`):
   - `K`: 그대로(대조, §441 객체와 비 STABS 같아야 함)
   - `R1`: 78–80 행의 `imo` 를 `register struct ip_moptions *imo;`
   - `R2`: 67 행 `register struct mbuf *mopts;`
   - `R3`: R1 + R2
   - `B1`: 함수 범위 `imo` 선언(78–80 행)을 없애고 MULTICAST 블록 안(156 행 `struct in_multi *inm;` 뒤)에 `struct ip_moptions *imo;`
   - `B2`: B1 + `register`
   - `P`: 다섯째 인자를 `imo` 한 변수로(Darwin 의 인자 이름): 머리 `ip_output(m0, opt, ro, flags, imo)`, 67 행 `struct ip_moptions *imo;`, 함수 범위 선언 없앰, 164–165 행 `if ((flags & IP_MULTICASTOPTS) && imo != NULL) { imo = mtod((struct mbuf *)imo, struct ip_moptions *);`
2. 고르기 규칙(실행 전 고정, §458 과 같음): K 불일치면 멈춤; OBJECT_MATCH + 새 미정의 0 이 하나면 그 꼴; 여럿이면 사용자에게; 없으면 같은 레지스터 표(진단)로 가장 가까운 변형을 기록하고, 다음 시도 변형을 다시 계획합니다(두 시도 연속 줄지 않으면 멈춤).
3. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/netinet/ip_output.c`, 도구 등록(`MARKERS['plan 459 (m68k)']`, `EXCEPTS[459]` = 458 의 열셋 + `x86-ip_output`, `--plan`, `FILES['ip_output']`), 스테이징·x86 관문·`cmd2`·`final`, 고른 변형과 비 STABS 같음 확인.
4. 미리 정한 기준: `x86-ip_output` OBJECT_MATCH, 원본에 없는 미정의 기호 0.
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ip-output.diff`, `09_validation/reconstruction/m5-m68k-ip-output-variants-20261015.json`·`m5-m68k-ip-output-20261015.json`.

### 459.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §435·§441 객체는 같음; `ro`·`mopts`·`imo`·`ifp`·`error` 배정과 제자리 `addal`·`subal` 은 맞음 | python SHA(둘 다 `0ff65c0b…`), §459 준비 중 진단 덩어리·목록 읽음 | ✅ |
| **뒤쪽 a4/a2 는 `m` 이 아니라 `map = nb_map(nb)`(07 304 행); `m` 은 `a6@(-48)`** | 07 303–306 행, 객체 목록 0x326 `movel d0,a2`(305 행 자리) | ✅ **제 오류 정정** |
| 하나의 전역 레지스터 치환으로는 설명되지 않음(값마다 다른 대응); 대응을 따르면 남는 모양 차이 12 곳(`ro` 를 a1 로 다시 옮기는 7 곳, `lea` 대 `moveq;addl`, `mtod` 제자리, `clrl` 대 `subal`, 198 행 임시 복사, 324 행 `addl` 대 `addal`), 호출·분기는 모두 대응, 크기 차는 `ro` +16·`imo` −8 | 진단 덩어리 목록과 맞음(위 표의 X 12) | ✅ (해석은 검토자 계산, 실행이 판정) |
| R1·R2·R3 는 약한 탐침(-O2 에서 `register` 는 보장 없음), B1·B2 도 보장 없음, P 가 "제자리 재사용" 을 가장 직접 표현 | 설계 판단 | ⏭️ 실행이 판정 |
| P 의 `mtod((struct mbuf *)imo, …)` 는 C89 로 맞음(스테이징 `bsd/sys/mbuf.h:75` `mtod(x,t) ((t)((int)(x) + (x)->m_off))`); 다만 인자는 여전히 mbuf 주소이므로 형만 Darwin 과 같음 | `mbuf.h:75` 읽음 | ✅ 채택 시 이 점을 기록 |
| 추가 변형 넷: `register struct route *ro;` 만, `imo` 선언을 `hlen` 앞으로, B1+R2, 형을 바꾸지 않는 제자리 재사용(`mopts = (struct mbuf *)mtod(mopts, …); imo = (struct ip_moptions *)mopts;`) | 설계 | ✅ RO·O1·B1R2·Q 추가 |
| `struct mbuf *mopts;` 는 두 번 나옴 → 바꿀 글에 앞뒤 문맥을 넣을 것 | `grep -n`: 67·945 행(995 행은 `register` 판) | ✅ |
| "가장 가까움" 을 미리 수로 정할 것; 컴파일 성공·공통 기호·외부 정의 같음도 기준 | 설계 | ✅ 아래 |

수정한 방법(실행 전 고정):
- 변형 11 개: K·R1·R2·R3·B1·B2·P·RO·O1·B1R2·Q. 바꿀 글은 문맥을 넣어 파일에서 한 번만 나오게 합니다(도구가 검사).
- 받아들임: 컴파일 종료 0, OBJECT_MATCH, 원본에 없는 미정의 0, 공통 기호와 외부 정의 기호가 K 와 같음.
- 맞는 것이 없을 때의 "가까움" 수치: 실기 `otool -tv` 목록에서 `_ip_output` 의 (1) 원본 1326 B 와의 바이트 길이 차 절댓값, (2) 주소·분기 대상을 가린 명령열의 `difflib` 불일치 명령 수(원본 쪽 + 객체 쪽). (2) 가 작은 순, 같으면 (1) 이 작은 순. 다음 시도는 가장 가까운 변형에서 다시 계획합니다(두 시도 연속 (2) 가 줄지 않으면 멈춤).

### 459.2 시도 1 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-output-variants-20261016.json`

- run `m5p459-var1`(11 명령 모두 종료 0, 실행 전후 해시 같음). 대조 K 는 §441 객체와 같음(통과).
- **OBJECT_MATCH 없음.** 비 STABS 같음 묶음은 {B1, B1R2, B2, K, O1, Q, R1, R2, R3, RO} 와 {P} 둘뿐입니다. `register`·선언 자리·형 그대로의 제자리 재사용(Q)은 객체를 바꾸지 못했습니다(검토 예상과 같음).
- 미리 정한 가까움 수치(실기 `otool -tv`, `_ip_output` 첫 명령부터 `_ip_insertoptions` 앞까지):

| | 명령 수 | 불일치 명령 수 | 길이(마지막 명령 주소) | 프레임 |
|---|---|---|---|---|
| 원본 | 421 | — | 1324 | −52 |
| K | 416 | **189** | 1316 | −52 |
| P | 423 | 220 | 1324 | −48 |

- 해석:
  - P 는 원본의 두 특징을 재현합니다. `ro` 가 데이터 레지스터(d5, 원본 d4)에 있고, `imo` 가 한 주소 레지스터에서 제자리 `addal a5@(4),a5`·`subal a5,a5` 로 계산됩니다(원본 a4).
  - 그러나 원본·K 가 단편화 쪽 `mhip`(= `map`, §459.3.1 정정)을 스택 −52 에 내려놓는 것과 달리(원본 0x4021e54·0x4021f08, K 0x3d4·0x488), P 는 레지스터가 하나 남아 `mhip` 을 내려놓지 않고 프레임이 4 B 작습니다. 레지스터 번호도 하나씩 밀립니다(d5/d4, a5/a4, d3/d2).
  - 미리 정한 1 순위 수치(불일치 명령 수)는 레지스터 이름까지 세므로 K 가 더 가깝게 나옵니다.
- 미리 정한 규칙대로라면 다음 시도의 바탕은 K 입니다. 결과를 본 뒤 바탕을 P 로 바꾸는 것은 규칙을 고치는 일이라 사용자에게 묻습니다.

### 459.3 사용자 결정과 시도 2 계획(코딩 전, 2026-10-16)

- 사용자 선택: **"규칙대로 K 바탕 2차"**. 다음 시도는 K(지금 07 꼴: 다섯째 인자 `struct mbuf *mopts`, 함수 범위 `struct ip_moptions *imo`)를 바탕으로 하고, 인자 형이나 변수 구성을 P 처럼 바꾸지 않습니다.
- 시도 1 에서 알게 된 것(K 바탕 설계의 근거):
  - `register`·선언 자리·같은 형의 제자리 재사용(Q)은 객체를 바꾸지 못했습니다.
  - 원본은 `mopts`·`imo`(그리고 뒤쪽 `map`)를 a4 하나에, `ro` 를 d4 에 둡니다. K 는 `mopts` d2·`imo` d1·`ro` a5 입니다. 프레임과 `map` 의 −52 내림은 원본과 K 가 같습니다.
- 후보 변형은 codex 검토에서 K 바탕 제안을 받아 직접 검토한 뒤 확정합니다(검토 전에는 실행하지 않음). 조건:
  - 07 의 인자 형과 변수 구성(두 변수)을 유지합니다.
  - 식과 문장의 꼴(대입·검사 순서, 식 묶음, 같은 뜻의 다른 표현)만 바꿉니다.
  - 기능을 더하지 않습니다.
- 가까움 수치와 멈춤 규칙은 §459.1 그대로입니다. 시도 2 의 가장 작은 불일치 명령 수가 K 의 189 보다 작지 않으면 멈춥니다.

#### 459.3.1 교차검토(codex `gpt-6.1-sol`) 판정과 시도 2 후보 확정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §459.2 표의 수(421/416/423, 189/220, 1324/1316/1324, −52/−52/−48)는 재현됨; 단 불일치 수는 `difflib` `autojunk=False` 일 때 값이고, "길이" 는 마지막 명령의 주소(실제 바이트 길이는 +2: 1326/1318/1326) | 계산 스크립트(scratchpad `close.py` 20 행 `autojunk=False`), 원본 바이트 길이 1326 은 §459 사실과 같음 | ✅ 기록 방식 보충: 불일치 수 = 주소(`0x…:l`)와 분기 대상 가림 + `SequenceMatcher(autojunk=False)` 의 비일치 명령 양쪽 합; 길이 열 = 마지막 명령 주소 |
| **−52 에 저장되는 것은 `map` 이 아니라 `mhip = (struct ip *)map`(07 331 행; 350 행 `bcopy` 에서 다시 읽음)** | 07 324–334·350 행 읽음 | ✅ **제 서술 정정**(§459.2 의 "`map` 을 내려놓음" → "`mhip` 을 내려놓음") |
| P 의 핵심은 들어온 포인터와 바꾼 포인터를 한 변수로 묶어 수명이 이어진 것; 단편화 쪽 `off` 도 원본 a2·K/P d2 로 다름 | 검토자 표(목록 인용); `off` 는 §459 진단의 324 행 덩어리(`addal` 대 `addl`)와 맞음 | ✅(해석은 RTL 없이 추론) |
| K 바탕 후보 A–F(두 변수·형 유지, 뜻 같음): A 시험 전에 `imo` 에 복사, B 함수 첫머리에서 `imo` 에 복사, C 단락 시험 안에서 대입, D 성공 가지 안에서 복사 뒤 제자리 변환, E 가지 순서 뒤집기, F 변환 뒤 `mopts` 로 접근 | 각 `before` 글을 07 에서 읽어 확인(85–88 행, 164–172 행), 도구가 한 번만 나옴·겹침 없음을 검사 | ✅ 시도 2 = K(대조) + A–F |
| 멈춤 비교는 유효 후보(컴파일 0·미정의 0·공통/외부 정의가 K 와 같음)에만, K 는 대조로 유지 | 설계 | ✅ |

### 459.4 시도 2 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-output-variants2-20261016.json`

- run `m5p459-var2`(7 명령 모두 종료 0, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p459/spec2.json`). 대조 K 는 §441 객체와 같음(통과).
- **OBJECT_MATCH 없음.** 모든 변형이 원본에 없는 미정의 0, 공통 기호는 K 와 같습니다. 비 STABS 같음 묶음: {A}, {B}, {C}, {D, F, K}, {E}.
- 가까움(불일치 명령 수, 낮을수록 가까움): **C 187**, A 188, K 189, E 195, B 264(프레임 −48 로 P 와 비슷), D·F = K.
  - A·C 는 `mopts` 를 함수 첫머리에서 레지스터에 싣지 않게 바뀌었으나(`moveq #20,d6` 이 앞당겨짐), `ro` 는 여전히 a5 이고 원본의 배정(`ro` d4, `mopts`/`imo` a4)에는 이르지 못했습니다.
- 멈춤 규칙: 시도 2 의 가장 작은 수(187)가 K(189)보다 작으므로 규칙상 멈춤 조건은 아닙니다. 다만 줄어든 폭이 2 명령뿐이고, 레지스터 배정 원인을 바꾸지 못했습니다.
- 07 은 바꾸지 않았습니다. 다음(시도 3 을 C 바탕으로 할지, `ip_output` 을 보류할지)은 사용자에게 묻습니다.

### 459.5 사용자 결정과 시도 3 계획(코딩 전, 2026-10-16)

- 사용자 선택: **"C 바탕 3차"**. 바탕은 C(164 행을 `if ((flags & IP_MULTICASTOPTS) && (imo = (struct ip_moptions *)mopts) != NULL) { imo = mtod((struct mbuf *)imo, …);` 로 바꾼 꼴)이고, 두 변수·형을 유지하는 조건(§459.3)은 그대로입니다.
- 관찰(실기 목록, `_ip_output` 첫머리와 −52):
  - 원본: 첫머리에서 `ro` → d4, `mopts` → a4 를 싣습니다. −52 에는 a4(`mhip`)를 저장합니다.
  - K: `ro` → a5, `mopts` → d2 를 싣습니다. −52 저장은 같습니다.
  - P: `ro` → d5, 인자 → a5 를 싣고, −52 는 쓰지 않습니다.
  - C: 첫머리에 `ro` → a5 만 싣고, `mopts` 는 MULTICAST 블록에서야 d1 로 읽습니다(0x18c). −52 저장은 같습니다.
  - 원본의 단편화 루프는 `off` 를 a2(주소 레지스터; 324 행 `addal a6@(-44),a2`)에 두지만, K·P·C 는 d2 입니다.
- 후보 변형은 codex 검토에서 C 바탕 제안을 받아 직접 검토한 뒤 확정합니다. 가까움 수치·멈춤 규칙은 §459.1·§459.3 그대로이며, 시도 3 의 가장 작은 수가 C 의 187 보다 작지 않으면 멈춥니다.

#### 459.5.1 교차검토(codex `gpt-6.1-sol`) 판정과 시도 3 후보 확정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §459.5 관찰(첫머리 적재, −52 저장, C 의 늦은 적재 0x18c, `off` a2 대 d2·324 행 `addal`/`addl`)은 맞음; "−52 저장 같음" 은 같은 자리·같은 값(`mhip`)이라는 뜻이고 레지스터는 다름(원본 a4, K·C a2) | 네 목록의 첫머리·−52 줄 grep(이번 절 준비) | ✅ 문구 보충 |
| C 와 원본의 남은 배정 차이: `ro` d4/a5, 옵션 a4(첫머리)/d1(늦게), `ifp` a5/a4, `map` a4/a2, `off` a2/d2, `mhlen` d3/d4, `nb`·`error` d2/d3 | 검토자 표(목록 인용); 앞 줄들과 일치 | ✅(해석) |
| **B 는 두 변수·형을 지키면서 `ro` 를 데이터 레지스터(d5)에, 옵션을 a5(+0x1c)에 두고 제자리 `addal a5@(4),a5`(+0x1a2)를 함** — 다만 프레임 −48·`mhip` 레지스터 | B 목록 첫 9 줄과 0x1a2 grep | ✅ |
| C + S1(함수 첫머리 `imo = (struct ip_moptions *)mopts;`) + S2(검사를 `imo != NULL` 로) = B | spec2 의 B 바꿈과 같음(대조) | ✅ |
| 추가 변경 R(`ro` 기본값 대입을 `bzero` 인자 안으로), L(`off = hlen;` 을 먼저 두고 `for (off += len; …)`), M(`mhip` 을 먼저, `map = (char *)mhip;`) — 변수를 더하지 않고 뜻이 같음 | 07 106–109 행·323–325 행·330–331 행 읽음; 각 글이 한 번만 나옴은 도구가 검사 | ✅ |
| `off` 는 정수로 둘 것(포인터 임시 변수 불필요) | 설계 | ✅ |

확정한 시도 3 변형(실행 전 고정, 명세 `08_build/artifacts/m5p459/spec3.json`):
- 대조: `K`(07 그대로), `C`(시도 2 의 C).
- C 바탕 넷: `CR`·`CL`·`CM`·`CLM`(C + R / L / M / L+M). 사용자 선택 "C 바탕" 을 그대로 따르는 묶음입니다.
- B 바탕 넷: `BR`·`BL`·`BM`·`BLM`(C + S1 + S2 = B 에 R / L / M / L+M). 검토 제안이며, B 는 C 에서 두 줄을 더 바꾼 꼴입니다.
- 가까움 수치는 §459.1·§459.3.1 그대로입니다. 보조로 첫머리 적재·변환 레지스터·`ro`·`off`·−52 를 함께 적습니다.
- 멈춤 규칙: 가장 작은 불일치 수가 C 의 187 보다 작지 않으면 멈춥니다.

### 459.6 시도 3 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-output-variants3-20261016.json`

- run `m5p459-var3`(10 명령 모두 종료 0, 실행 전후 해시 같음). 대조 K 는 §441 객체와 같음(통과). 모든 변형이 원본에 없는 미정의 0, 공통 기호 K 와 같음.
- OBJECT_MATCH 는 아직 없습니다. 비 STABS 같음 묶음: {BL, BLM}, {BM}, {BR}, {C, CM}, {CL, CLM}, {CR}, {K}.
- 가까움(불일치 명령 수): **CL 2**·CLM 2, BL 56·BLM 56, C·CR·CM 187, K 189, BR·BM 264. 프레임은 BR·BM 만 −48, 나머지 −52.
  - **L(`off = hlen;` 을 먼저 두고 `for (off += len; …)`)이 단편화 쪽 배정을 원본과 같게 만들었습니다.**
  - **CL 의 남은 차이는 하나입니다.** 원본은 다섯째 인자를 함수 첫머리에서 a4 에 싣고(0x4021a8a `movel a6@(0x18),a4`), CL 은 MULTICAST 블록에서 싣습니다(+0x19a, `tstl a4` 바로 앞). 그 밖의 명령·레지스터 이름은 모두 같습니다(python `difflib` 블록 둘: 원본 쪽 1 명령 삭제, 객체 쪽 1 명령 삽입).
  - 해석: C 의 시험 꼴 `(imo = (struct ip_moptions *)mopts) != NULL` 이 인자 적재를 늦춘 것으로 보입니다. K 꼴처럼 시험에서 `mopts` 를 직접 쓰면 첫머리에서 싣습니다(K·B 목록).
- 멈춤 규칙: 187 → 2 로 줄었으므로 계속합니다. 다음 시도의 바탕은 가장 가까운 CL 입니다.

### 459.7 시도 4 계획(CL 바탕; 코딩 전, 2026-10-16)

- 바탕 CL(= C + L). 남은 차이는 다섯째 인자를 싣는 때 하나뿐입니다. L 은 그대로 두고, MULTICAST 블록의 시험·대입 꼴만 이미 시험한 꼴들로 바꿉니다(새 꼴을 만들지 않음). 두 변수·형 유지, 기능 추가 없음.
- 변형(명세 `08_build/artifacts/m5p459/spec4.json`):
  - 대조: `K`, `CL`(시도 3 과 같은 글).
  - `KL` = 07 그대로의 시험(`(flags & IP_MULTICASTOPTS) && mopts != NULL` / `imo = mtod(mopts, …)`) + L
  - `AL` = A + L, `DL` = D + L, `EL` = E + L, `FL` = F + L, `QL` = Q + L(Q 는 시도 1 의 같은 형 제자리 재사용)
- 예상: 시험에서 `mopts` 를 직접 쓰는 꼴(KL·DL·EL·FL·QL)은 인자를 첫머리에서 싣습니다(K·B 목록). 그때 `imo` 가 같은 a4 를 쓰는지가 관건입니다.
- 고르기: OBJECT_MATCH + 새 미정의 0 + 공통 기호 K 와 같음이 하나면 그 꼴. 여럿이면 사용자에게 묻습니다. 없으면 가까움 수치로 기록하고, CL 의 2 보다 작지 않으면 멈춥니다.

#### 459.7.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| CL 과 원본의 차이는 옮겨진 명령 하나(원본 0x4021a8a ↔ CL +0x19a, 둘 다 `movel a6@(0x18),a4`)뿐; 재배치 31·분기 변위 5 를 맞추면 함수 1326 B 가 같음 | 제 `difflib` 출력(블록 둘: 원본 쪽 1 삭제·CL 쪽 1 삽입, §459.6); 바이트 대조는 검토자 계산 | ✅(바이트 대조는 ⏭️) |
| BL 56, CLM = CL·BLM = BL(비 STABS) | 시도 3 기록의 같음 묶음과 수 | ✅ |
| KL·AL·DL·EL·FL·QL 은 바꾸지 않은 07 에 대한 바꿈을 이어 붙여 만들고 L 과 겹치지 않음; 이미 시험한 꼴 중 빠진 것 없음(B+L = BL, C+L = CL) | 도구가 바꾼 글이 한 번만 나오는지·겹침을 검사(아래 실행), 명세는 이어 붙이기로 만듦 | ✅ |
| 제안 꼴들은 뜻이 같음(flags 먼저 단락 검사, 실패 경로마다 `imo = NULL`, FL·QL 은 이후 쓰지 않는 지역 `mopts` 만 덮어씀, L 은 첫 단편 위치와 증가가 같음) | 07 164–172·323–325 행 읽음 | ✅ |
| 받아들임 기준을 다시 적을 것: 컴파일 0, K 와 CL 재현, 외부 정의·공통 기호 같음, 새 미정의 0, OBJECT_MATCH(참조 포함), 최종 해시·대조 방법 기록 | 설계 | ✅ 그대로 적용 |

### 459.8 시도 4 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-output-variants4-20261016.json`

- run `m5p459-var4`(8 명령 모두 종료 0, 실행 전후 해시 같음). 대조 K 는 §441 객체와 같음, CL 은 시도 3 의 CL 과 비 STABS 같음(둘 다 통과).
- **OBJECT_MATCH: KL·DL·FL·QL**(넷 모두 원본에 없는 미정의 0, 외부 정의·공통 기호 K 와 같음). 넷은 비 STABS 로 서로 같습니다. AL·CL·EL 은 불일치입니다.
- 뜻: 07 의 MULTICAST 꼴(계획 175)은 m68k 에서도 맞고, 원인은 단편화 루프의 `off` 초기화 꼴 하나였습니다. KL 은 07 에서 L(323–325 행) 만 바꾼 꼴입니다. 시도 1–3 의 `imo`·`mopts` 변형은 L 이 없어서 맞지 않았던 것입니다.
- 미리 정한 규칙대로, 바이트가 같은 넷 가운데 무엇을 쓸지 사용자에게 묻습니다(추천: 바꾸는 줄이 가장 적은 KL).

### 459.9 결정과 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-output-20261016.json`

- 사용자 결정 **D077** = KL(07 의 MULTICAST 꼴은 그대로, 단편화 루프의 `off` 초기화만 L).
- 07 덮어쓰기 `v183.34/m68k/src/bsd/netinet/ip_output.c`(새 파일, 1040 행, 표시 줄 6): 323–324 행 앞에 `#if m68k`(begin) `off = hlen;` / `mhlen = sizeof (struct ip);` / `for (off += len; …) {` `#else`(end), 뒤에 `#endif`. m68k 쪽 글은 변형 KL 과 같습니다(python).
- 도구 등록: `MARKERS`(6)·`EXCEPTS[459]`·`--plan` 목록·`FILES['ip_output']`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 은 같습니다. 실행 전후 해시가 같습니다.
- **run `m5p459-a1`**(종료 0, 경고 없음): **`x86-ip_output` OBJECT_MATCH**, 외부 구간 9/9 같음, 원본에 없는 미정의 기호 0, 변형 KL 과 비 STABS·공통 기호 같음입니다.
- 기록: diff `06_reconstruction/evidence/m68k-ip-output.diff`, PROVENANCE 1088 → 1089, MODIFICATIONS 614 → 615, DECISIONS D077.
- 교훈: 레지스터 배정 차이의 원인은 차이가 많이 보인 곳(MULTICAST 블록)이 아니라 다른 곳(단편화 루프)의 변수 하나였습니다. 시도 1–3 의 `imo`·`mopts` 변형은 L 없이는 효과를 볼 수 없었습니다.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 163 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 164 입니다.

## 460. M5-17 세부 계획 — m68k `vm_kern`: `kmem_alloc_prim` 의 넷째 인자 `find_space`(x86 트리 변경 없음; 코딩 전, 2026-10-16)

확인한 사실:
- §441 객체 `O441__L2_175__vm_kern.o`(컴파일 줄 §430 `cc.cmd`): NOT_MATCH(`__text` 미검증). 외부 구간 13 개 중 `_kmem_alloc`(56/60 B)·`_kmem_alloc_wired`(36/40)·`_kmem_alloc_zone`(36/40)만 다르고, 원본에 없는 미정의 기호 0.
  - 객체 첫 316 B(정적 `kmem_alloc_prim` 하나, §460.1 정정)는 외부 구간 밖이라 그 비교에 들어가지 않았습니다. 원본은 정적 함수 시작 0x405d448 부터 `_kmem_alloc` 0x405d592 까지 330 B 입니다(python).
- 원본 m68k 정적 함수(0x405d448, 이름 없음, `linkw #-4`):
  - 인자가 6 개입니다: `a6@(8)` map → a2, `(0xc)` addrp → a4, `(0x10)` size → a3, **`(0x14)` → d2**, `(0x18)` object → d3, `(0x1c)` canblock.
  - `clrl d4`(offset = 0)를 합니다. 이어서 `tstl d2; beq` 로 가지를 나눠, 참이면 `addr = map->min_offset`(`a2@(0x10)`), 거짓이면 `addr = *addrp`(`a4@`)입니다. 그다음 `size = round_page(size)` 입니다.
  - `vm_map_find(map, object != kernel_object ? object : 0, d4(offset 변수), &addr, size, d2)` 를 부릅니다. 07 은 셋째 인자가 상수 `(vm_offset_t) 0`(`clrl sp@-`), 여섯째가 `TRUE`(`pea 1`)입니다.
  - 그 뒤(실패 처리, `kernel_object` 다시 넣기, `kmem_alloc_pages` 검사와 순서, `vm_map_pageable`, `*addrp = addr`, 실패 시 `KERN_RESOURCE_SHORTAGE`(6))는 §430 객체 목록(`M430__L2_175__vm_kern.txt` 0x54–0x132)과 같은 꼴입니다.
- 원본 호출 세 곳은 모두 넷째 인자에 1 을 넣습니다: `_kmem_alloc`(0x405d5b4 `pea 1`, 다섯째 = `vm_object_allocate` 결과, 여섯째 `pea 1`), `_kmem_alloc_wired`(0x405d6da), `_kmem_alloc_zone`(0x405da04, 여섯째 = `canblock`).
- 참고 코드: Darwin 0.1 `vm/vm_kern.c:90` 의 `kmem_alloc_prim` 은 인자 5 개(07·x86 과 같음)입니다. NeXTMach·Mach4 에는 `kmem_alloc_prim` 이 없습니다. 넷째 인자는 `vm_map_find` 의 마지막 인자로 그대로 넘어가고, NeXTMach `vm/vm_map.c:534–540` 은 그 매개변수 이름이 `find_space` 이며 `if (find_space)` 로 씁니다. 이름은 이를 따릅니다(이름은 바이트로 정해지지 않음).

방법:
1. `m5_m68k_srcvar.py` 변형 시험(명세 `08_build/artifacts/m5p460/spec.json`, 바탕 `m0p459-a1-stage`, 07 변경 없음):
   - `K`: 그대로(대조)
   - `F1`: 정의 머리 `kmem_alloc_prim(map, addrp, size, find_space, object, canblock)` + `boolean_t find_space;`(size 선언 뒤), `addr = vm_map_min(map);` → `if (find_space) addr = vm_map_min(map); else addr = *addrp;`, `vm_map_find` 의 `(vm_offset_t) 0` → `offset`, `TRUE)` → `find_space)`, 호출 세 곳에 넷째 인자 `TRUE`.
   - `F2`: F1 의 `if/else` 대신 `addr = find_space ? vm_map_min(map) : *addrp;`
   - `F3`: F1 에서 `vm_map_find` 셋째 인자는 `(vm_offset_t) 0` 그대로(offset 변수 쓰임이 필요한지 가림)
2. 고르기 규칙: K 불일치면 멈춤; OBJECT_MATCH + 새 미정의 0 + 공통 기호·외부 정의 K 와 같음이 하나면 그 꼴; 여럿이고 서로 같으면 사용자에게; 없으면 진단 뒤 멈춤(두 시도 연속 줄지 않으면).
3. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/vm/vm_kern.c`(바뀌는 줄을 `#if m68k` / `#else` 07 줄 / `#endif`), 도구 등록(`MARKERS`·`EXCEPTS[460]` = 459 의 열넷 + `x86-vm_kern`·`--plan`·`FILES['vm_kern']`), 스테이징·x86 관문·`cmd2`·`final`, 고른 변형과 비 STABS 같음.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-vm-kern.diff`, `09_validation/reconstruction/m5-m68k-vm-kern-variants-20261016.json`·`m5-m68k-vm-kern-20261016.json`.

### 460.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 정적 함수의 인자·레지스터·가지·`vm_map_find` 인자 순서와 호출 세 곳의 넣기는 계획대로 | §460 준비 중 원본 목록 0x405d448–0x405d590·호출 세 곳 읽음 | ✅ |
| [0x405d448, 0x405d592) 330 B 는 그 정적 함수 하나; 객체 첫 316 B 도 `_kmem_alloc_prim` 하나(다른 정적 `_kmem_alloc_pages` 는 0x316) — "등" 은 빼야 함 | python: O441 지역 기호 `_kmem_alloc_prim` 0x0, `_kmem_alloc_pages` 0x316 | ✅ 문구 정정 |
| 원본의 `bsr 0x405d448` 은 정확히 셋; 그 밖의 차이는 `canblock` 변위 0x18 → 0x1c 뿐이고 나머지는 M430 0x54 부터와 재배치를 가리면 같음 | grep 3; 나머지 대응은 검토자 계산 | ✅(대응은 ⏭️ 실행이 판정) |
| `vm_map_min(map)` = `(map)->min_offset`(07 `vm/vm_map.h:435`), 변위 0x10; F1–F3 는 뜻이 같은 C | 435 행 읽음 | ✅ |
| `find_space` 이름은 NeXTMach `vm_map_find` 매개변수에서 온 추정; 07 안 호출처는 셋뿐(정적) | `grep` 4 건(정의 1 + 호출 3) | ✅ |
| "K 불일치면 멈춤" 은 "K 가 §441 객체를 재현하지 못하면" 이라는 뜻; 도구의 `summary.match` 는 공통 기호·외부 정의를 거르지 않으므로 따로 확인할 것 | 도구 코드(`m5_m68k_srcvar.py` compare 의 `match`) 확인 | ✅ 판정 때 K 와 공통 기호·외부 정의 비교를 따로 함 |

### 460.2 변형 시험 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-vm-kern-variants-20261016.json`

- run `m5p460-var1`(4 명령 모두 종료 0, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p460/spec.json`). 대조 K 는 §441 객체를 재현했습니다(통과).
- **F1·F2 OBJECT_MATCH**(외부 구간 13/13 같음, 원본에 없는 미정의 0, 공통 기호·외부 정의 K 와 같음)이고, 두 객체는 비 STABS 로 서로 같습니다.
- F3(`vm_map_find` 셋째 인자를 상수 0 그대로)는 NOT_MATCH 입니다. 원본의 `movel d4,sp@-` 는 `offset` 변수를 넘긴 결과입니다.
- 경고(`assert_wait`·`thread_wakeup_prim` 인자 형)는 대조 K 에도 있는 기존 경고입니다.
- 미리 정한 규칙대로, 바이트가 같은 F1(`if/else`)·F2(삼항식) 가운데 무엇을 쓸지 사용자에게 묻습니다.

### 460.3 결정과 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-vm-kern-20261016.json`

- 사용자 결정 **D078** = F1(`if (find_space) addr = vm_map_min(map); else addr = *addrp;`).
- 07 덮어쓰기 `v183.34/m68k/src/vm/vm_kern.c`(새 파일, 738 행, 표시 줄 30): 정의 머리·`find_space` 선언·`addr` 고르기·`vm_map_find` 의 `offset`/`find_space`·호출 세 곳을 `#if m68k` 로 두고 07 줄은 `#else` 에 둡니다. m68k 쪽 코드는 변형 F1 과 같습니다(차이는 주석 하나, python).
- 도구 등록: `MARKERS`(30)·`EXCEPTS[460]`·`--plan` 목록·`FILES['vm_kern']`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 은 같습니다. 실행 전후 해시가 같습니다.
- **run `m5p460-a1`**(종료 0, 대조 K 와 같은 기존 경고): **`x86-vm_kern` OBJECT_MATCH**, 외부 구간 13/13 같음, 원본에 없는 미정의 기호 0, 변형 F1 과 비 STABS·공통 기호 같음입니다.
- 기록: diff `06_reconstruction/evidence/m68k-vm-kern.diff`, PROVENANCE 1089 → 1090, MODIFICATIONS 615 → 616, DECISIONS D078.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 164 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 165 입니다.

## 461. M5-18 세부 계획 — m68k `ip_icmp`: `icmp_sendMaskPacket` 의 마스크 대입·시험 꼴(x86 트리 변경 없음; 코딩 전, 2026-10-16)

확인한 사실:
- §441 객체 `O441__L2_119__ip_icmp.o`(컴파일 줄 §429 run): NOT_MATCH(`__text` fail, 바이트 차이 231, 참조 차이 13). 외부 구간 7 개 중 `_icmp_sendMaskPacket`(객체 452 B, 원본 454 B)만 다르고, 원본에 없는 미정의 기호 0.
- 실기 `otool -tv`(이번에 §441 객체를 풀어 `08_build/artifacts/m3p441-cc1/otool/` 에 둠)와 원본 목록을 주소·분기 대상을 가려 `difflib`(`autojunk=False`)로 비교하면, 차이는 덩어리 하나입니다.
  - 원본 0x40207fc–0x4020800: `movel a5@(0x34),d0; movel d0,a2@(8)`(값을 레지스터에 싣고 저장, 뒤 `bne` 는 그 값으로 판정)
  - 객체 0x8b4: `movel a5@(0x34),a2@(8)`(메모리에서 메모리로)
  - 참조 차이 13 과 바이트 차이는 이 2 B 밀림의 결과로 봅니다(실행이 판정).
- 07 `bsd/netinet/ip_icmp.c` 539–540 행(계획 170 작성, x86 원본 기준)은 `icp->icmp_mask = htonl(ifa->ia_subnetmask);` / `if (icp->icmp_mask == 0) {` 입니다.
- 참고 코드: Darwin 0.1 `kernel/bsd/netinet/ip_icmp.c:744` 은 `if ((icp->icmp_mask = htonl(ifa->ia_subnetmask)) == 0) {`(대입한 값을 시험)입니다. 07 `ip_icmp.c` 에는 Darwin 고지가 없습니다(grep 0). m68k 에서 `htonl` 은 값 그대로입니다.

방법:
1. `m5_m68k_srcvar.py` 변형 시험(명세 `08_build/artifacts/m5p461/spec.json`, 바탕 `m0p460-a1-stage`, 07 변경 없음, 539–540 행만 바꿈):
   - `K`: 그대로(대조, §441 객체 재현)
   - `D`: Darwin 744 행 꼴 `if ((icp->icmp_mask = htonl(ifa->ia_subnetmask)) == 0) {`
   - `N`: `if (!(icp->icmp_mask = htonl(ifa->ia_subnetmask))) {`(Darwin 과 글자가 다른 같은 뜻)
2. 고르기 규칙: K 가 §441 객체를 재현하지 못하면 멈춤; OBJECT_MATCH + 새 미정의 0 + 공통 기호·외부 정의 K 와 같음이 하나면 그 꼴(D 면 D061 선례대로 Darwin 고지와 `(Darwin)` 표시); D·N 이 둘 다 맞고 같으면 사용자에게(고지 필요 여부 포함); 없으면 진단 뒤 멈춤.
3. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/netinet/ip_icmp.c`, 도구 등록(`MARKERS`·`EXCEPTS[461]` = 460 의 열다섯 + `x86-ip_icmp`·`--plan`·`FILES['ip_icmp']`), 스테이징·x86 관문·`cmd2`·`final`, 고른 변형과 비 STABS 같음.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ip-icmp.diff`, `09_validation/reconstruction/m5-m68k-ip-icmp-variants-20261016.json`·`m5-m68k-ip-icmp-20261016.json`.

### 461.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 목록의 객체가 §441 객체와 같음(SHA `8f30eee6…`), 명령 차이는 덩어리 하나 | `objects.sha` 와 `sha256sum` 비교; 제 `difflib` 출력(덩어리 하나) | ✅ |
| 참조 차이 13(`_in_cksum`·`_ip_id`·`_hz`·`_wakeup`·`_timeout`·`_sleep`·`_if_output_mbuf`·`_m_freem`)과 분기 변위 4 는 모두 그 덩어리 뒤의 2 B 밀림 결과 | 검토자 계산(밀림을 반영하면 454 B 모두 같음) | ⏭️ 실행이 판정 |
| 나머지 외부 함수 6 개는 같고, 외부 구간 7 개가 객체 `__text` 2520 B 를 모두 덮음(정적 함수 영역 없음) | §441 객체 비교(이번 절 준비: 다른 구간은 하나) | ✅ |
| D·N 은 K 와 뜻이 같음; 스테이징 m68k `bsd/m68k/endian.h` 에서 `htonl(x)` 는 `(x)`(빅엔디언 가지) | `endian.h:71–88` 의 `#if BYTE_ORDER == BIG_ENDIAN` 가지 읽음 | ✅ |
| Darwin 함수와 07 의 다른 차이(`MGETHDR`, `m_data`, `if_output` 간접 호출 등)는 바이트가 요구하지 않으므로 바꾸지 않음 | 객체의 나머지가 원본과 같음 | ✅ |
| D 를 고르면 D061 선례(덮어쓰기 `in_pcb.c` 머리)대로 Darwin 고지·`(Darwin)` 표시·출처 기록; N 은 철자만 달라 고지 문제를 따로 풀지 못함 | `v183.34/m68k/src/bsd/netinet/in_pcb.c` 머리 읽음 | ✅ |

### 461.2 변형 시험 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-icmp-variants-20261016.json`

- run `m5p461-var1`(3 명령 모두 종료 0, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p461/spec.json`). 대조 K 는 §441 객체를 재현했습니다(통과).
- **D·N 둘 다 OBJECT_MATCH**(외부 구간 7/7 같음, 원본에 없는 미정의 0, 공통 기호·외부 정의 K 와 같음)이고, 두 객체는 비 STABS 로 서로 같습니다. 참조 차이 13 도 함께 사라졌습니다(2 B 밀림의 결과였음).
- 미리 정한 규칙대로 사용자에게 묻습니다: D(Darwin 0.1 `ip_icmp.c:744` 와 같은 글, D061 선례대로 고지 필요) 또는 N(철자가 다른 같은 뜻).

### 461.3 결정과 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ip-icmp-20261016.json`

- 사용자 결정 **D079** = D(Darwin 꼴 + 고지).
- 07 덮어쓰기 `v183.34/m68k/src/bsd/netinet/ip_icmp.c`(새 파일, 624 행, 표시 줄 33): 13 행(첫 고지 주석 끝) 뒤에 Darwin 0.1 `ip_icmp.c` 1–23 행 APSL 고지 묶음, 539–540 행 앞에 `#if m68k`(begin) Darwin 744 행 꼴(`plan 461 (Darwin)` 표시) `#else`(end), 뒤에 `#endif`. m68k 쪽 코드는 변형 D 와 같습니다(python).
- 도구 등록: `MARKERS`(33)·`EXCEPTS[461]`·`--plan` 목록·`FILES['ip_icmp']`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 은 같습니다. 실행 전후 해시가 같습니다.
- **run `m5p461-a1`**(종료 0): **`x86-ip_icmp` OBJECT_MATCH**, 외부 구간 7/7 같음, 원본에 없는 미정의 기호 0, 변형 D 와 비 STABS·공통 기호 같음입니다.
- 기록: diff `06_reconstruction/evidence/m68k-ip-icmp.diff`, PROVENANCE 1090 → 1091(출처 `nextmach+darwin01`), MODIFICATIONS 616 → 617, DECISIONS D079.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 165 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 166 입니다.

## 462. M5-19 세부 계획 — m68k `vfs_dnlc`: 큐 도우미 넷을 `static inline` 으로(x86 트리 변경 없음; 코딩 전, 2026-10-16)

확인한 사실:
- §441 객체 `O441__L2_130__vfs_dnlc.o`(컴파일 줄 §429 run, `-O2`): NOT_MATCH(`__text` 미검증), 외부 구간 중 `_dnlc_init` 130/138·`_dnlc_enter` 362/392·`_dnlc_enterSymLink` 170/196·`_dnlc_lookup` 206/234·`_dnlc_purge1` 374/402 B 가 다르고, 원본에 없는 미정의 기호 0.
- 실기 `otool -tv`(이번에 §441 객체를 풀어 `08_build/artifacts/m3p441-cc1/otool/` 에 둠)와 원본을 비교하면, 차이는 **큐 조작을 원본은 펼쳐 놓고(인라인) 객체는 정적 함수로 부르는 것**입니다.
  - 예: `_dnlc_init` 원본은 LRU 삽입을 `movel …,a0@(8)` 등으로 펼침, 객체는 `bsr`(정적 `insque2`).
  - `_dnlc_enter` 는 원본이 해시·LRU 넣기·빼기를 펼치고, 객체는 `bsr` 4 번입니다.
  - 그 결과의 레지스터 저장 차이(`d2` 추가 등)도 있습니다.
  - 정적 도우미 호출은 모두 14 번입니다(§462.1 정정).
- 객체 지역 기호: `_insque2` 0x0, `_remque2` 0x2a, `_nc_insque` 0x4a, `_nc_remque` 0x6e(합 136 B), 그 뒤 `_dnlc_init` 0x88; 끝쪽에 `_dnlc_rm` 0x588, `_dnlc_search` 0x61c. 객체 `__text` 1736 B.
- 원본 m68k `vfs_dnlc` 는 `_dnlc_init`(0x40185a2)에서 바로 시작하고 길이 1720 B(§423 표 `m68k-048`, 진입 11 중 이름 없음 2 = `dnlc_rm`·`dnlc_search`)입니다. 앞에 도우미 함수가 없습니다(0x40185a0 은 앞 객체의 `rts`).
- 07 `bsd/kern/vfs_dnlc.c` 의 도우미 넷(55·71·82·92 행의 `static` + 함수)은 계획 184 작성으로, x86 원본(`-O3`)에서 자동 인라인되도록 사용 전에 둔 것입니다. NeXTMach `bsd/vfs_dnlc.c:441–466` 의 `insque2`·`remque2` 는 파일 끝의 일반 함수이고, 해시 쪽은 SDK `sys/dnlc.h:46–47` 의 외부 `insque`/`remque` 입니다.
- §414 기록: m68k 플래그는 `-O2` 이고, `vfs_dnlc` 만 `-O2`·`-O3` 로 맞는 함수가 섞여 "원 소스의 `inline` 같은 소스 요인" 으로 남겨 두었습니다.
- `inline` 은 GNU 확장이나, 07 에 이미 `static inline`(`kern/ns_timer.c:31·136`)이 있고, m68k 덮어쓰기 `kern_clock.c`(§455)의 `static inline` 도 이 컴파일러에서 OBJECT_MATCH 였습니다(`08_build/GCC27_COMPATIBILITY.md` 의 "확인한 형태만").

방법:
1. `m5_m68k_srcvar.py` 변형 시험(명세 `08_build/artifacts/m5p462/spec.json`, 바탕 `m0p461-a1-stage`, 07 변경 없음):
   - `K`: 그대로(대조)
   - `I`: 도우미 넷 모두 `static` → `static inline`
   - `IL`: LRU 둘(`insque2`·`remque2`)만 `static inline`
   - `IH`: 해시 둘(`nc_insque`·`nc_remque`)만 `static inline`
2. 고르기 규칙: K 가 §441 객체를 재현하지 못하면 멈춤; OBJECT_MATCH + 새 미정의 0 + 공통 기호·외부 정의 K 와 같음이 하나면 그 꼴; 여럿이고 서로 같으면 사용자에게; 없으면 진단 뒤 멈춤.
3. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/vfs_dnlc.c`(`static` 줄을 `#if m68k` `static inline` `#else` `static` `#endif`), 도구 등록(`MARKERS`·`EXCEPTS[462]` = 461 의 열여섯 + `x86-vfs_dnlc`·`--plan`·`FILES['vfs_dnlc']`), 스테이징·x86 관문·`cmd2`·`final`, 고른 변형과 비 STABS 같음, 객체 `__text` = 1720 B.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-vfs-dnlc.diff`, `09_validation/reconstruction/m5-m68k-vfs-dnlc-variants-20261016.json`·`m5-m68k-vfs-dnlc-20261016.json`.

### 462.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·지역 기호·1736/1720 B·원본이 `_dnlc_init` 에서 바로 시작·이름 없는 정적 둘(`dnlc_rm` 0x4018afe, `dnlc_search` 0x4018bae) | §462 준비 중 python·목록 | ✅ |
| **"`bsr` 5 번" 은 틀림 — 정적 도우미 호출은 14 번**(객체 `bsr` 전체 39, 원본 25) | python: 재배치(외부)가 걸린 `bsr` 를 빼고 도우미 주소로 가는 것을 셈 → `insque2` 5·`remque2` 4·`nc_remque` 3·`nc_insque` 2 = 14 | ✅ **제 오류 정정**(앞의 5 는 세 함수의 덩어리만 센 수) |
| NeXTMach 범위는 441–466(`remque2` 본문 포함) | `sed -n 461,467p` | ✅ 정정 |
| 열한 함수를 모두 비교하면 차이는 인라인된 큐 조작과 그 결과(인자 준비·스택 정리·레지스터)뿐이고, 원본의 펼친 저장 순서는 07 도우미 본문과 같음 | 검토자 비교(목록 인용) | ⏭️ 실행이 판정 |
| `static inline` 은 K&R 정의에서도 문제없음(§455 선례), 다만 모두 펼쳐지고 따로 내보내지지 않는지는 측정해야 함; 실패하면 원형 변형을 진단으로 | 설계 | ✅ |
| 받아들임: 열한 함수 본문 모두, `__text` 1720 B 전체, 도우미 지역 기호 넷이 없음, 공통 기호·외부 정의 같음(도구 요약이 거르지 않음) | 설계 | ✅ 판정 때 따로 확인 |

### 462.2 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-vfs-dnlc-variants-20261016.json`(변형), `m5-m68k-vfs-dnlc-20261016.json`(최종)

변형 시험(run `m5p462-var1`, 4 명령 모두 종료 0, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p462/spec.json`):
- 대조 K 는 §441 객체를 재현했습니다(통과).
- **OBJECT_MATCH 는 I(넷 모두 `static inline`) 하나**입니다. `__text` 1720 B(원본과 같음), 지역 기호는 `_dnlc_rm`·`_dnlc_search` 뿐(도우미 넷 없음), 공통 기호·외부 정의는 K 와 같습니다.
- IL(1764 B)·IH(1700 B)는 불일치이고, 각각 인라인하지 않은 도우미 둘이 남습니다.
- 고르기 규칙(하나면 채택)에 따라 I 를 씁니다.

07 덮어쓰기와 최종:
- `v183.34/m68k/src/bsd/kern/vfs_dnlc.c`(새 파일, 522 행, 표시 줄 16): 55·71·82·92 행의 `static` 을 `#if m68k` `static inline` `#else` `static` `#endif` 로 둡니다. m68k 쪽 글은 변형 I 와 같습니다(python).
- 도구 등록: `MARKERS`(16)·`EXCEPTS[462]`·`--plan` 목록·`FILES['vfs_dnlc']`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 은 같습니다. 실행 전후 해시가 같습니다.
- **run `m5p462-a1`**(종료 0, 경고 없음): **`x86-vfs_dnlc` OBJECT_MATCH**, 외부 구간 모두 같음, 원본에 없는 미정의 기호 0, `__text` 1720 B, 지역 기호 `_dnlc_rm`·`_dnlc_search`, 변형 I 와 비 STABS·공통 기호 같음입니다.
- 기록: diff `06_reconstruction/evidence/m68k-vfs-dnlc.diff`, PROVENANCE 1091 → 1092, MODIFICATIONS 617 → 618.
- 이로써 §414 에서 남겨 둔 "`vfs_dnlc` 는 `-O2`·`-O3` 로 맞는 함수가 섞임" 의 원인이 소스의 `inline` 으로 확인되었습니다(m68k 는 `-O2` 한 벌).
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 166 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 167 입니다.

## 463. M5-20 세부 계획 — m68k `tcp_input`: `ti_len` 의 `htons` 재대입과 `tcp_mss` 의 `offer` 비교 꼴(x86 트리 변경 없음; 코딩 전, 2026-10-16)

확인한 사실:
- §441 객체 `O441__L2_306__tcp_input.o`(컴파일 줄 §429 run): NOT_MATCH(`__text` 미검증), 외부 구간 6 개 중 `_tcp_input`(4092/4096 B)·`_tcp_mss`(290/288 B)가 다르고, 원본에 없는 미정의 기호 0.
- 실기 `otool -tv`(이번에 §441 객체를 풀어 `08_build/artifacts/m3p441-cc1/otool/` 에 둠, SHA 대조)와 원본 비교(주소·분기 대상 가림, `difflib` `autojunk=False`):
  - `_tcp_input`: 원본에만 `movew a2,a5@(0xa)` 가 하나 더 있습니다(0x4022de4·0x4022de8, `ti_len` 에 같은 값을 두 번 저장). 그 밖의 "차이" 는 점프 표 두 개(0x4023656·0x4023bec)를 `otool` 이 명령으로 잘못 푼 것으로, 4 B 밀림의 결과입니다.
  - `_tcp_mss`: 원본은 `tstw d3; beq; clrl d0; movew d3,d0; cmpl d2,d0; bge; movel d0,d2`(0x4023fac–0x4023fb8, 0 확장한 `offer` 를 d0 에 두고 그 값을 대입), 객체는 대입 때 `clrl d2; movew d3,d2` 로 다시 확장합니다.
- 07 `bsd/netinet/tcp_input.c`:
  - 260–261 행 `ti->ti_len = (u_short)tlen;` / `HTONS(ti->ti_len);`(net2 꼴). 스테이징 m68k `bsd/m68k/endian.h` 의 빅엔디언 가지에서 `HTONS(x)` 는 `(x)`(코드 없음), 그 밖의 가지에서는 `(x) = htons((u_short)x)` 입니다.
  - NeXTMach `mk-108.1/netinet/tcp_input.c:228–229` 는 `ti->ti_len = (u_short)tlen;` / `ti->ti_len = htons((u_short)ti->ti_len);` 입니다(m68k 에서 `htons` 는 값 그대로라 저장이 한 번 더 생김).
  - 1464–1465 행 `if (offer && mss > offer)` / `mss = offer;`(계획 368 작성, x86 원본 기준). net2 `tcp_input.c:1448–1449` 와 Darwin 0.1 `:1846–1847` 은 `if (offer)` / `mss = min(mss, offer);` 이지만, 원본 m68k `_tcp_mss` 의 `_min` 호출 셋(0x4023fa2·0x4023fe6·0x402401a)은 다른 자리이고 `offer` 비교는 인라인입니다. `sys/param.h:272` 에 `MIN(a,b)` 가 있습니다.

방법:
1. `m5_m68k_srcvar.py` 변형 시험(명세 `08_build/artifacts/m5p463/spec.json`, 바탕 `m0p462-a1-stage`, 07 변경 없음):
   - `K`: 그대로(대조)
   - `H`: 261 행을 NeXTMach 229 행 `ti->ti_len = htons((u_short)ti->ti_len);` 로
   - `HM1`: H + 1464–1465 행을 `if (offer)` / `mss = MIN(mss, offer);` 로
   - `HM2`: H + 1464 행을 `if (offer && offer < mss)` 로
2. 고르기 규칙: K 가 §441 객체를 재현하지 못하면 멈춤; OBJECT_MATCH + 새 미정의 0 + 공통 기호·외부 정의 K 와 같음이 하나면 그 꼴; 여럿이고 서로 같으면 사용자에게; 없으면 H 의 `_tcp_input` 결과를 기록하고 `_tcp_mss` 를 진단해 다음 시도를 다시 계획(두 시도 연속 줄지 않으면 멈춤).
3. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/netinet/tcp_input.c`, 도구 등록(`MARKERS`·`EXCEPTS[463]` = 462 의 열일곱 + `x86-tcp_input`·`--plan`·`FILES['tcp_input']`), 스테이징·x86 관문·`cmd2`·`final`.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-tcp-input.diff`, `09_validation/reconstruction/m5-m68k-tcp-input-variants-20261016.json`·`m5-m68k-tcp-input-20261016.json`.

### 463.1 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 실제 차이는 둘뿐(`_tcp_input` 의 두 번째 `movew a2,a5@(0xa)`, `_tcp_mss` 의 대입 꼴); 나머지 "차이" 는 점프 표 둘을 `otool` 이 잘못 푼 것이고 표 값은 자리만 다름; 나머지 외부 함수 넷도 같음 | 제 `difflib` 출력(진짜 명령 차이 둘); 표 바이트 대조는 검토자 계산 | ✅(표 대조는 ⏭️) |
| 스테이징 m68k `endian.h` 의 빅엔디언 가지에서 `htons(x)`·`HTONS(x)` 는 `(x)`; NeXTMach 228–229 행 글 | §462 에서 같은 머리 읽음, NeXTMach grep | ✅ |
| H·HM1·HM2 는 뜻이 같음(`offer` 는 부호 있는 `int` 로 승격); 추가 변형 `if (offer) mss = MIN((int)offer, mss);` 제안 | 설계 | ✅ HM3 추가 |
| 원본 `_min` 호출 셋은 07 1454·1481·1491 행 | `sed -n` 세 줄 읽음 | ✅ |
| 받아들임: 객체 `__text` 5270 B, 공통 기호·외부 정의 같음(도구 요약이 거르지 않음), H 의 NeXTMach 출처 기록 | §423 표 `x86-tcp_input` 5270 B, 지금 객체 5268 B(python) | ✅ |

### 463.2 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-tcp-input-variants-20261016.json`(변형), `m5-m68k-tcp-input-20261016.json`(최종)

변형 시험(run `m5p463-var1`, 5 명령 모두 종료 0, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p463/spec.json`):
- 대조 K 는 §441 객체를 재현했습니다(통과).
- H 는 `_tcp_input` 을 맞혔습니다(NeXTMach 229 행 꼴이 두 번째 저장을 만듦). `_tcp_mss` 는 HM1 에서만 맞았습니다.
- **OBJECT_MATCH 는 HM1 하나**(`if (offer) mss = MIN(mss, offer);`)이고, `__text` 5270 B(원본과 같음), 공통 기호·외부 정의 K 와 같습니다. HM2·HM3(`MIN((int)offer, mss)`)은 `_tcp_mss` 가 다릅니다.
- 고르기 규칙(하나면 채택)에 따라 HM1 을 씁니다.

07 덮어쓰기와 최종:
- `v183.34/m68k/src/bsd/netinet/tcp_input.c`(새 파일, 1518 행, 표시 줄 9): 261 행과 1464–1465 행을 `#if m68k` / `#else` 07 줄 / `#endif` 로 둡니다. m68k 쪽 글은 변형 HM1 과 같습니다(python).
- 도구 등록: `MARKERS`(9)·`EXCEPTS[463]`·`--plan` 목록·`FILES['tcp_input']`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 은 같습니다. 실행 전후 해시가 같습니다.
- **run `m5p463-a1`**(종료 0, 경고 넷(`insque`·`remque` 인자 형)은 대조 K 와 같은 기존 경고 — 처음에 "경고 없음" 으로 잘못 적어 고침): **`x86-tcp_input` OBJECT_MATCH**, 외부 구간 6/6 같음, 원본에 없는 미정의 기호 0, `__text` 5270 B, 변형 HM1 과 비 STABS·공통 기호 같음입니다.
- 기록: diff `06_reconstruction/evidence/m68k-tcp-input.diff`, PROVENANCE 1092 → 1093, MODIFICATIONS 618 → 619.
- 이로써 소스 꼴 문제 여섯(`in_pcb`·`ip_output`·`ip_icmp`·`tcp_input`·`vfs_dnlc`·`vm_kern`)을 모두 맞췄습니다.
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 167 이고, `ufs_alloc` 명시 배치(§452)를 넣으면 168 입니다.

## 464. M5-21 세부 계획 — 코드가 맞은 m68k 16 객체의 bss 자리: `zerofill_check.py` 를 m68k 로 넓혀 "reference-inferred" 판정(07 변경 없음; 코딩 전, 2026-10-16)

확인한 사실:
- §441 전체 컴파일에서 그 뒤 고친 20 객체를 빼면 NOT_MATCH 가 39 개입니다(python). 그중 **16 개는 L1 사유가 `__DATA,__bss: unverified` 하나뿐**이고 `__TEXT,__text` 는 검증되었습니다: `xdr`·`in`·`if_ether`·`tty_pty`·`svc`·`spec_vfsops`·`ip_input`·`kern_notify`·`kernel_stack`·`vfs`·`pmap_kgetport`·`ux_exception`·`power`·`vnode_pager`·`nfs_vnodeops`·`vol`. 나머지 23 개는 코드 차이가 있습니다.
  - 이 16 개 가운데 외부 구간 비교에서 "다름" 이 보이는 `tty_pty`·`spec_vfsops`·`kern_notify` 는 마지막 외부 함수 구간이 다음 객체까지 이어진 측정 산물입니다(L1 의 `__text` 는 검증됨).
- L1(`l1_compare.py`)은 설계상 zero-fill 절(bss)을 바이트로 비교할 수 없어, 자리를 주어도 "미검증" 으로 둡니다(도구 머리 13 행, 318–319 행). 예: `xdr` 에 코드 참조로 계산한 bss 자리 0x40b359a 를 주면 `__text` 참조가 모두 맞고(차이 0), 2 B 어긋난 자리(0x40b3598)는 참조 1 개가 다릅니다. 판정은 둘 다 NOT_MATCH 이며, 사유는 0x40b359a 가 `__DATA,__bss: unverified` 하나, 0x40b3598 은 여기에 `__TEXT,__text` fail·참조 1 다름이 더해집니다(§464.1 정정).
- x86 에서는 같은 경우를 `zerofill_check.py`(계획 46·84·302, D019·D025)로 "reference-inferred" 라 판정해 등급 P 로 두고(`objects_partial.tsv` 의 `unverified_sections`), 링크 배치로 따로 증명했습니다(§408, D063).
- `zerofill_check.py` 는 i386 전용입니다: `require_i386`(130–131 행, 계획 411), i386 재배치 이름표 `TYPE`, 필드·이미지 읽기의 `'little'`(88·163 행). `l1_compare.py` 는 §411 에서 `types_of(obj)`·객체의 `endian` 으로 아키텍처별 처리를 이미 갖추었습니다.
- x86 기존 기록 `09_validation/reconstruction/*zerofill-check*.json` 은 78 개이고, 입력 파일이 모두 남아 있습니다(python, 아래 실행 전 확인).

방법:
1. `zerofill_check.py` 를 넓힙니다(도구 변경, 07·x86 표 변경 없음):
   - `require_i386` 두 줄 대신 객체와 이미지의 `cputype`·`endian` 이 같은지 검사합니다(`l1_compare.py:273–275` 와 같은 방식).
   - 재배치 이름은 `L.types_of(obj)`, 필드와 이미지 읽기의 바이트 순서는 `obj['endian']` 을 씁니다.
   - 그 밖의 판정 규칙(정렬, 이미지 같은 이름 절 안, 이미지 기호 없음, 겹침, 음성 검사 +4, D019·D025)은 그대로입니다.
2. **x86 회귀 관문**(실행 전 고정): 기존 x86 기록 모두를 기록된 명령으로 다시 돌려 `conclusion`·`candidate`·`distinct_deltas`·`references`·`checks`·`negative_check` 가 같아야 합니다(`tool_sha256`·`command`·출력 경로 제외). 시험 `test_zerofill_conclude.py` 도 통과해야 합니다.
3. m68k 16 객체 실행: `--image` 원본 m68k, `--obj` §441 객체, `--section __DATA,__bss`, `--symbols 03_original/m68k/inventory/symbols.tsv`, `--place-from-l1` 그 객체의 L1 기록(입력 SHA 검사됨). 첫 판에서는 `--known` 없이 돌리고, 16 결과의 후보 범위가 서로 겹치지 않는지 따로 검사합니다.
4. 판정: 객체마다 `conclusion` 이 `reference-inferred`(또는 D019 의 `-single`)면 "코드 검증 + bss 자리 reference-inferred" 로 기록합니다. 이것은 OBJECT_MATCH 가 아니며, x86 의 등급 P 와 같은 자리매김입니다(링크 배치 증명은 M7). `fail` 은 사유를 기록합니다.
5. 기록: `09_validation/reconstruction/m5-m68k-zerofill-20261016.json`(16 객체 요약·후보·겹침 검사), x86 회귀 결과 `m5-m68k-zerofill-x86regress-20261016.json`. m68k 누계 표기는 "OBJECT_MATCH n + 코드 검증·bss 추정 m" 으로 나눠 적습니다.

### 464.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 남은 NOT_MATCH 39 개와 bss 만 미검증인 16 개는 맞음(§441 의 NOT_MATCH 57 중 18 이 고친 객체, `kern_exec`·`mach_process` 는 §441 집합 밖) | §464 준비 중 python 목록 | ✅ |
| **`xdr` 0x40b3598 은 사유에 `__text` fail·참조 1 다름이 더해짐** — 계획의 "둘 다 사유 `__DATA,__bss: unverified`" 는 틀림 | §464 준비 중 L1 출력(0x40b3598: `__TEXT,__text: fail`, `1 refs differ`) | ✅ **제 문구 정정** |
| 넓힘이 불완전: 좁은 필드(16 비트)·PC 상대·VANILLA 가 아닌 형이 bss 를 가리키면 지금 계산은 맞지 않음 → 명시적으로 거부할 것; `L.types_of(obj)` 를 항상 불러 지원 안 되는 CPU 거부 | `zerofill_check.py` 66–110 행 읽음 | ✅ 단, x86 회귀를 바이트 그대로 지키려고 새 거부는 i386 이 아닌 객체에만 적용 |
| 16 객체의 bss 참조 176 개는 모두 `__text` 의 4 B 절대 VANILLA(일반 156·scattered 20), 좁은 필드·PC 상대·`__data` 참조 없음 | python: 객체별 재배치 집계(종류·길이·pcrel) | ✅ |
| x86 회귀 관문을 넓힐 것: `records`·`problems`·`section`·`source_section_deltas`·`delta_source`·`base_offsets`·`field_target_offsets`·`scattered_addends` 도 비교, 옛 기록에 없는 필드는 없는 대로, 입력 해시 확인, 다시 돌린 출력은 기록과 다른 곳에 | 설계 | ✅ |
| `xdr` 는 참조 1 개라 D019 의 `reference-inferred-single` 이 됨 — 따로 적을 것 | `xdr` 참조 1(위 집계) | ✅ |
| 등급 P 정의(`06_reconstruction/README.md:26`)는 경계 증명과 다른 파일 기반 절의 검증도 요구; 후보 겹침은 실패 조건으로 | 16 객체의 L1 사유는 bss 하나뿐(다른 절은 검증됨); 경계: §423 표에서 15 개 정확, `kern_notify` 는 §439 경계 표(k=191, rule1)에서 0x40576ce 로 정해짐(1170 B = 객체 크기, python) | ✅ 겹침은 실패로, 링크 배치 증명은 M7 대기로 적음 |

### 464.2 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-zerofill-x86regress-20261016.json`(x86 회귀), `m5-m68k-zerofill-20261016.json`(m68k 16 객체)

도구:
- `zerofill_check.py` 를 고쳤습니다(212 → 226 행; 고치기 전 SHA-256 `f620e8da…`, 사본은 세션 scratchpad).
  - 객체·이미지의 `cputype`·`endian` 같음 검사가 `require_i386` 을 대신합니다.
  - 재배치 이름은 `l1_compare.types_of`, 읽기 바이트 순서는 객체의 `endian` 입니다.
  - i386 이 아닌 CPU 에서는 bss 를 가리키는 VANILLA 4 B 절대가 아닌 기록을 문제로 둡니다.
- 새 도구 `10_tools/reconstruction/m5_m68k_zerofill.py`(`x86replay`·`m68k`). `test_zerofill_conclude.py` 는 8/8 통과입니다. 실행 전후 도구 해시가 같습니다.

x86 회귀 관문:
- **미리 정한 관문(기록과 같아야 함)은 성립하지 않았습니다.** 78 기록 중 모든 필드가 같은 것은 18 개입니다.
  - 다른 필드는 `delta_source`·`field_target_offsets`·`scattered_addends`·`source_section_deltas`, 그리고 `kalloc-pre` 하나의 `conclusion` 입니다.
- 원인: 78 기록은 모두 이번 변경 전 도구판(`f620e8da…`)이 아니라 더 오래된 도구판 다섯(`b95598f8…` 22·`3e74e37e…` 17·`b7276c75…` 15·`fd594447…` 14·`efd3382a…` 10)으로 만든 것입니다. 그래서 차이는 그 뒤의 도구 변경(계획 302·339 의 `delta_source`, D025 의 필드 대상 등)에서 온 것이고, 이 관문은 이번 변경의 효과를 가려낼 수 없었습니다.
- 대신 같은 78 명령을 **이번 변경 전 도구와 변경 후 도구로 각각 다시 돌린 결과는 78 개 모두 모든 필드가 같습니다**(차이 0). 즉 이번 변경은 x86 동작을 바꾸지 않았습니다.
- 결과를 본 뒤 관문을 바꾸는 일이므로, "변경 전·후 다시 돌림이 같음" 을 관문으로 받아들일지 사용자에게 묻습니다. 그때까지 m68k 결과는 잠정입니다.

m68k 16 객체(잠정):
- **16 개 모두 `reference-inferred`**(`xdr` 는 참조 1 개라 D019 의 `reference-inferred-single`)입니다. 실패 0, 후보 범위 겹침 0, L1 사유는 모두 `__DATA,__bss: unverified` 하나뿐입니다.
- 후보 bss 범위(주소 순): `tty_pty` 0x40b3184(448 B) … `vol` 0x40b4e80(14 B). `if_ether`→`in`→`ip_input`, `svc`→`xdr`→`spec_vfsops`, `kern_notify`→`ux_exception`→`vnode_pager`→`vol` 는 빈틈 없이 이어집니다(링크 순서와 맞는 모양; 귀속 증명은 아님).
- 판정: 이 16 개는 OBJECT_MATCH 가 아니라 x86 의 등급 P 와 같은 자리매김("코드 검증 + bss 자리 reference-inferred, 링크 배치 증명은 M7")입니다.
- m68k 누계 표기: OBJECT_MATCH 167(+ 명시 배치 `ufs_alloc` 1) + 코드 검증·bss 추정 16(잠정).

### 464.3 사용자 결정(2026-10-16)

- **D080**: x86 회귀 관문을 "이번 변경 전·후 도구로 다시 돌린 결과가 같음"(78/78)으로 정했습니다. 미리 정한 관문이 성립하지 않은 사유(기록이 모두 옛 도구판)는 §464.2 와 D080 에 남깁니다. 옛 x86 기록은 고치지 않습니다.
- 따라서 §464.2 의 m68k 결과를 확정합니다: 16 객체 모두 "코드 검증 + bss 자리 reference-inferred"(`xdr` 는 `-single`), 링크 배치 증명은 M7 에서 합니다.
- m68k 누계: OBJECT_MATCH 167(+ 명시 배치 `ufs_alloc` 1) + 코드 검증·bss 추정 16. 남은 코드 차이 객체는 23 개(`netif`·`miniMon`·`igmp`·`vm_pager`·`time_stamp`·`mfs_prim`·`nfs_client`·`kern_fork`·`cmu_syscalls`·`ufs_subr`·`kern_exit`·`kdp`·`ipc_mig`·`kalloc`·`kern_proc`·`mach_clock`·`tty`·`callout`·`kdp_udp`·`mach_net`·`nfs_subr`·`nfs_vfsops`·`swapfs`)와 컴파일 안 되는 `ns_timer` 입니다.

## 465. M5-22 세부 계획 — 코드 차이가 작은 m68k 4 객체(`kern_fork`·`kalloc`·`vm_pager`·`nfs_client`)의 소스 꼴 변형 시험(07 변경 없음; 코딩 전, 2026-10-16)

확인한 사실(§441 객체를 실기 `otool -tv` 로 풀어 `08_build/artifacts/m3p441-cc1/otool/`(23 객체, SHA 기록 `objects.sha`)에 두고, 원본의 같은 구간과 주소·분기 대상을 가려 `difflib`(`autojunk=False`)로 비교):
- **`kern_fork`**(`switch_unix_context`, 07 `bsd/kern/kern_fork.c:513–518`): 원본은 `movel a0@(0x80),0x40b57d4` / `movel a0@(0x30),_active_u` 로 전역 `active_u`(0x40b57d0, `__common`)에 절대 주소로 두 번 저장하고, 객체는 `lea _active_u+4,a1` 로 주소를 레지스터에 묶어 `a1@`·`a1@(-4)` 로 저장합니다. 객체는 `active_u` 를 431 행에서 정의합니다(COMMON 8; 계획 400·D059, "자리 근거 없음"). SDK `user.h` 의 `u` 는 `active_u[cpu_number()]`, m68k SDK `user.h` 는 비어 있습니다.
- **`kalloc`**(`realloc`, 07 `kern/kalloc.c:300–318`, Darwin 0.1 파일; malloc 계열은 NeXTMach 에서 오고 NULL 처리·복사 길이는 작성, §465.1 정정): 원본은 `cmpl d0,a4; bcc` 로 `size - *sizep` 를 비교해 `size >= *sizep` 이면 `*sizep`, 아니면 `size` 를 `bcopy` 셋째 인자로 넣고(0x404a3c2–0x404a3ca), 객체는 `cmpl a4,d0; bls`(07 `if (size < *sizep) bcopy(…size) else bcopy(…*sizep)`). NeXTMach `kern/kalloc.c:356–368` 의 `realloc` 은 `size` 만 복사합니다.
- **`vm_pager`**(`vm_pager_deallocate`, 07 `vm/vm_pager.c`(Darwin 을 바탕으로 한 작성, §465.1 정정) `if (pager->is_device) device_dealloc(pager); else vnode_dealloc(pager);`): 원본은 `tstl a2@; bne` 로 `device_dealloc`(0x4062190)을 분기 쪽, `vnode_dealloc`(0x406362e)을 이어지는 쪽에 둡니다(객체는 반대: `beq`). NeXTMach `vm/vm_pager.c:432–440` 은 `if (pager->is_device) return(device_dealloc(pager)); return(vnode_dealloc(pager));`(반환형 `boolean_t`).
- **`nfs_client`**(`nfs_attrcache_va`, 07 `bsd/nfs/nfs_client.c`): 구조체 대입 `vtor(vp)->r_attr = *va;`(58 B → `_bcopy`)의 대상 주소를 원본은 d0, 객체는 d1 에 계산합니다(0x40262d8–0x40262de). 그 밖은 같습니다. 07 은 137 행에 정적 함수의 앞선 선언 `static set_attrcache_time();` 을 두었습니다(원본 m68k 에도 그 기호 없음).

방법(도구 `m5_m68k_srcvar.py`, 객체마다 명세 하나, 바탕 `m0p463-a1-stage`, 07 변경 없음):
- `kern_fork`: `K`; `E` = 431 행 정의를 없앰(`active_u` 는 SDK `user.h` 의 `extern` 선언만 남음 — 코드 생성 확인용, 정의 자리는 맞으면 따로 결정).
- `kalloc`: `K`; `T` = `bcopy(addr, new+2, size < *sizep ? size : *sizep);`; `R` = `if (size >= *sizep) bcopy(…*sizep) else bcopy(…size)`.
- `vm_pager`: `K`; `N` = `if (!pager->is_device) vnode_dealloc(pager); else device_dealloc(pager);`; `Z` = `if (pager->is_device == 0) vnode_dealloc(pager); else device_dealloc(pager);`.
- `nfs_client`: `K`; `B` = 대입을 `bcopy((caddr_t)va, (caddr_t)&vtor(vp)->r_attr, sizeof (struct vattr));` 로; `D` = 137 행 앞선 선언을 없앰.
- 고르기 규칙(객체마다): K 가 §441 객체를 재현하지 못하면 그 객체 멈춤; OBJECT_MATCH + 새 미정의 0 + 공통 기호·외부 정의 K 와 같음(`kern_fork` 의 E 는 `_active_u` COMMON 이 빠지는 것이 예상이므로 "그 하나만 다름" 을 허용하고 정의 자리를 사용자에게 물음)이 하나면 그 꼴, 여럿이면 사용자에게, 없으면 기록하고 다음 절에서 다시 계획.
- 맞은 객체는 앞 절들처럼 07 덮어쓰기·도구 등록·스테이징·x86 관문·`cmd2`·`final` 로 마무리합니다(절 번호를 나눠 기록).

### 465.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 네 객체 모두 정적 함수까지 포함한 전체 `__text` 에서 차이는 계획에 적은 덩어리뿐(`kern_fork` 둘, 나머지 하나씩) | 제 비교 스크립트 출력(§465 준비)과 같음 | ✅ |
| **Darwin `vm_pager_deallocate` 는 장치 쪽에서 `panic` 을 부름**(계획의 "Darwin 꼴 `if (is_device) device_dealloc …`" 은 틀림) | Darwin `vm/vm_pager.c:86–94` 읽음; 07 92–101 행은 `device_dealloc`/`vnode_dealloc` | ✅ **제 문구 정정**(07 꼴은 Darwin 을 바탕으로 한 작성) |
| **`kalloc` 의 `realloc` 은 통째 작성이 아님** — PROVENANCE 210 행: malloc 계열은 NeXTMach, 작성은 NULL 처리·복사 길이 | PROVENANCE 210 행 읽음 | ✅ **제 문구 정정** |
| `kalloc` 은 정적 bss 256 B 로 L1 이 이미 `__DATA,__bss: unverified` — `realloc` 을 고쳐도 OBJECT_MATCH 불가 → 기준은 "코드 검증 + §464 식 bss 추정" | 이번 세션 L1 기록: 사유 `__TEXT,__text: fail`·`__DATA,__bss: unverified` | ✅ 기준 고침 |
| `kern_fork` 추가 변형: 정의를 `switch_unix_context` 아래로 옮김(공통 기호는 유지) | 설계 | ✅ 변형 `M` 추가 |
| `E` 는 `_active_u` 의 유일한 정의를 없앰(§441 객체 중 64 개가 참조) → 맞더라도 정의 자리는 D059 를 고치는 결정으로 사용자에게 | 설계 | ✅ |
| `nfs_client` `D` 는 앞선 선언 없이 뒤에 `static` 정의 → 깨끗한 C89 연결이 아님, 진단용으로만 | 설계 | ✅ |
| 도구의 `summary.match` 는 공통 기호·외부 정의를 거르지 않음 → 따로 비교 | §458 부터 판정 때 따로 함 | ✅ |

수정한 변형(실행 전 고정): `kern_fork` = K·E·M, `kalloc` = K·T·R, `vm_pager` = K·N·Z, `nfs_client` = K·B·D. `kalloc` 의 받아들임은 "`__text` 검증(L1 사유가 bss 하나) + `zerofill_check` reference-inferred" 입니다.

### 465.2 변형 시험 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-{kern-fork,kalloc,vm-pager,nfs-client}-variants-20261016.json`

- run `m5p465-kern-fork-v1`·`-kalloc-v1`·`-vm-pager-v1`·`-nfs-client-v1`(각 3 명령, 모두 종료 0, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p465/spec-*.json`). 네 대조 K 모두 §441 객체를 재현했습니다.
- **`vm_pager`: N·Z OBJECT_MATCH**(원본에 없는 미정의 0, 공통 기호·외부 정의 K 와 같음), 두 객체는 비 STABS 로 서로 같습니다. `_vm_pager_has_page` 의 "다름" 은 마지막 외부 구간의 측정 산물입니다. 미리 정한 규칙대로 사용자에게 묻습니다.
- **`kern_fork`: E·M·K 가 비 STABS 로 모두 같습니다.** `active_u` 정의의 있고 없음·자리는 이 주소 지정 차이의 원인이 아닙니다(E 는 `_active_u` COMMON 만 빠짐). 다른 원인을 다음에 찾습니다.
- **`kalloc`: 맞는 꼴 없음.** T(조건식)는 `__text` 가 754 B 로 줄어(원본·K 764 B) 자리를 못 잡은 것("unverified" 는 일치가 아님), R 은 K 와 다른 불일치입니다.
- **`nfs_client`: 맞는 꼴 없음.** B(명시 `bcopy`)도 `__text` 가 1220 B 로 줄어(원본·K 1224 B) 자리를 못 잡았고, D 는 K 와 같습니다.
- `kern_fork`·`kalloc`·`nfs_client` 는 07 을 바꾸지 않고 기록만 남깁니다(다음 시도는 따로 계획).

### 465.3 `vm_pager` 결정과 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-vm-pager-20261016.json`

- 사용자 결정 **D081** = Z(`if (pager->is_device == 0) vnode_dealloc(pager); else device_dealloc(pager);`).
- 07 덮어쓰기 `v183.34/m68k/src/vm/vm_pager.c`(새 파일, 표시 줄 7): 97–100 행을 `#if m68k` Z 꼴 `#else` 07 줄 `#endif`. m68k 쪽 글은 변형 Z 와 같습니다(python).
- 도구 등록: `MARKERS`(7)·`EXCEPTS[465]`·`--plan` 목록·`FILES['vm_pager']`. 스테이징 차이는 이 `.c` 하나, x86 관문 7 같음, 실행 전후 해시 같음.
- **run `m5p465-a1`**(종료 0, 경고 없음): **`x86-vm_pager` OBJECT_MATCH**, 원본에 없는 미정의 0, 변형 Z 와 비 STABS 같음. `_vm_pager_has_page` 의 구간 "다름" 은 마지막 외부 구간 측정 산물입니다.
- 기록: diff `06_reconstruction/evidence/m68k-vm-pager.diff`, PROVENANCE 1093 → 1094, MODIFICATIONS 619 → 620, DECISIONS D081.
- m68k 누계: OBJECT_MATCH 168(+ 명시 배치 `ufs_alloc` 1) + 코드 검증·bss 추정 16. 코드 차이 남음 22(+ `ns_timer`).

## 466. M5-23 세부 계획 — m68k `kdp`: `kdp_regions` 응답의 영역 상수(07 변경은 m68k 덮어쓰기; 코딩 전, 2026-10-16)

확인한 사실:
- 남은 코드 차이 22 객체를 L1(`l1_compare.py`, 첫 외부 기호로 자리를 직접 줌)으로 다시 재고, §423 표의 원본 객체 크기와 비교했습니다(python). 크기가 같은 것은 `nfs_client`·`kern_fork`·`kalloc`·`nfs_subr`(§465 의 셋 + 하나), 나머지는 크기가 다릅니다.
- `kdp`: 객체 1316 B, 원본 1320 B(차 4).
- 원본 `kdp_regions`(0x404fc62–0x404fc9a)는 `clrl a1@(8)`(`nregions = 0`) 뒤 `movel #0x10000000,a1@(0xc)`, `movel #0x4000000,a1@(0x10)`, `movel d1,a1@(0x14)`(d1 = 7)입니다.
  - 07 `kern/kdp_protocol.h:181–190` 에서 응답의 `regions` 는 +0xc, `kdp_region_t` 는 `address`(+0)·`nbytes`(+4)·`protection`(+8)이므로, 원본은 `address = 0x10000000`, `nbytes = 0x4000000`, `protection = 7(VM_PROT_ALL)` 입니다.
- 07 `kern/kdp.c:374–375`(계획의 작성, D024, x86 원본 기준)는 `r->address = (void *) 0;` / `r->nbytes = 0x40000000;` 입니다. 객체는 `clrl a1@(0xc)`(4 B)이고 원본은 `movel #imm32,…`(8 B)라서 크기 차 4 와 맞습니다.
- 앞서 쓴 비교 스크립트는 `0x…:l` 를 가려 `nbytes` 차이를 숨겼습니다. 이번 판정은 L1 로 합니다.

방법:
1. 변형 시험(`m5_m68k_srcvar.py`, 명세 `08_build/artifacts/m5p466/spec.json`, 바탕 `m0p465-a1-stage`): `K` 그대로, `C` = 374–375 행을 `r->address = (void *) 0x10000000;` / `r->nbytes = 0x4000000;` 로.
2. 고르기: K 가 §441 객체를 재현하지 못하면 멈춤; C 가 OBJECT_MATCH + 새 미정의 0 + 공통 기호·외부 정의 K 와 같으면 채택(상수라 다른 꼴을 묻지 않음); 아니면 남은 차이를 진단해 기록하고 멈춤.
3. 채택하면 07 덮어쓰기 `v183.34/m68k/src/kern/kdp.c`(374–375 행을 `#if m68k` / `#else` / `#endif`), 도구 등록(`MARKERS`·`EXCEPTS[466]` = 465 의 열아홉 + `x86-kdp`·`--plan`·`FILES['kdp']`), 스테이징·x86 관문·`cmd2`·`final`.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-kdp.diff`, `09_validation/reconstruction/m5-m68k-kdp-variants-20261016.json`·`m5-m68k-kdp-20261016.json`.

### 466.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 명령·머리 배치·값(주소 0x10000000, 크기 0x4000000, 보호 7) | §466 준비 중 목록·`kdp_protocol.h` 읽음 | ✅ |
| 크기 차 4 는 이 변경으로 다 설명되고, 그 밖의 차이(분기 변위·점프 표 항목·PC 상대 변위)는 모두 4 B 밀림의 결과 | 검토자 계산 | ⏭️ 실행이 판정 |
| **Darwin 0.1 `kern/kdp.c:438–439`(처음에 436–438 로 적었다가 §466.3 에서 python 으로 줄을 세어 바로잡음) 은 `(vm_offset_t)r->address = VM_MIN_KERNEL_ADDRESS;` / `r->nbytes = VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS;`; m68k 머리 `mach/m68k/vm_param.h:71–72` 는 0x10000000·0x14000000** | Darwin 425–445 행, 스테이징 머리 71–72 행 읽음; python 0x14000000 − 0x10000000 = 0x4000000 | ✅ 매크로 꼴 후보 추가 |
| (내 확인) i386 머리 `mach/i386/vm_param.h:44–45` 는 0·0x40000000 → 같은 매크로 꼴이 x86 07 의 상수(0·0x40000000)와도 같음 | 07 `nextdev/mach/i386/vm_param.h:44–45` 읽음 | ✅ 한 소스 꼴로 두 원본이 설명됨 |
| 덮어쓰기 주석의 "첫 기가바이트" 는 m68k 에 맞지 않음; 함수 시작은 0x404fc5a | 이미지 목록 | ✅ 주석 고침 |

수정한 변형(실행 전 고정): `K`, `C`(상수), `M`(`r->address = (void *) VM_MIN_KERNEL_ADDRESS;` / `r->nbytes = VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS;`), `MD`(Darwin 글 그대로, 대입 왼쪽 형변환). 맞는 꼴이 여럿이면 사용자에게 묻고, 매크로 꼴이 맞으면 "x86 07 본 파일도 같은 꼴로 바꿀지(x86 재빌드 확인 필요) 또는 m68k 덮어쓰기에만 둘지" 도 함께 묻습니다.

### 466.2 변형 시험 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-kdp-variants-20261016.json`

- run `m5p466-var1`(4 명령 모두 종료 0, 경고 없음, 실행 전후 해시 같음, 명세 `08_build/artifacts/m5p466/spec.json`). 대조 K 는 §441 객체를 재현했습니다(통과).
- **C·M·MD 모두 OBJECT_MATCH**(원본에 없는 미정의 0, 공통 기호·외부 정의 K 와 같음)이고, 셋은 비 STABS 로 서로 같습니다. K 의 `__DATA,__data` 참조 차이 2(점프 표)도 함께 사라졌습니다.
- 미리 정한 규칙대로 사용자에게 묻습니다.
  - 꼴: C(상수)·M(매크로, 둘째 줄은 Darwin 439 행과 같은 글)·MD(Darwin 438–439 행 그대로, 대입 왼쪽 형변환은 GNU 확장).
  - 자리: m68k 덮어쓰기만, 또는 x86 07 본 파일도 매크로 꼴로(i386 에서 0·0x40000000 이 되어 같은 바이트일 것이나 x86 재빌드 확인 필요).

### 466.3 D082 구현 계획(07 본 파일 변경 + x86 전체 재빌드·재링크 확인 + m68k 바탕 갱신; 코딩 전, 2026-10-16)

바로잡음: Darwin 0.1 `kernel/kern/kdp.c` 의 해당 줄은 438–439 행입니다(python 으로 줄을 셈: 437 `#if !defined(ppc)`, 438 `(vm_offset_t)r->address = VM_MIN_KERNEL_ADDRESS;`, 439 `r->nbytes = VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS;`). §466.1 표·§466.2·D082 의 줄 번호(436–438, 437)를 고쳤습니다. 고지는 같은 파일 1–23 행입니다.

확인한 사실:
- 07 `kern/kdp.c` 는 438 행이고(처음에 439 로 적음; `wc -l` 로 바로잡음, §466.4), 373–375 행이 `/* one region: the kernel's first gigabyte */` / `r->address = (void *) 0;` / `r->nbytes = 0x40000000;` 입니다. 지금 파일 SHA-256 은 `cf9292ef…`(PROVENANCE 616 행에 적힌 값)입니다.
- x86 빌드에서 kdp 는 G1 묶음(312 객체, `l2_rebuild.py groups`)의 forms 행 181 이고(`L2_181__kdp.o`), `-g -O3` 로 컴파일됩니다. s6l4 의 `cc -M` 기록(`08_build/runs/s6l4-g1a/out/_log/360.out`)에 `mach/vm_param.h`·`mach/machine/vm_param.h`·`mach/i386/vm_param.h` 가 이미 있으므로 매크로가 x86 에서도 보입니다(새 `#import` 불필요). 스테이징 원천은 `07_kernel/nextdev/mach/i386/vm_param.h` 이고 44–45 행이 `((vm_offset_t) 0x00000000)`·`((vm_offset_t) 0x40000000)` 입니다.
- 마지막 x86 전체 재빌드는 s6l4-*(plan 404, 고지 주석을 넣은 뒤)이고, 링크 run `s6p404-ln1` 의 결과가 원본과 같습니다(SHA-256 `33469393…`, 이번에 `sha256sum` 으로 다시 확인). s6l0–s6l1 의 kdp 객체는 `50055d3f…`, s6l2–s6l4 는 `5a3d0c43…` 입니다.
- 선례: plan 404 는 고지 주석만 더한 뒤 402 객체 재빌드(s6l4) → 링크·strip(s6p404-ln1) → 원본과 같음을 확인했습니다. 이번에도 같은 절차를 따릅니다.
- m68k 쪽은 `m0_m68k_l1.py:44` `BASE_STAGE = s6l4-g1a-stage` 를 바탕으로 쓰고(`stage_m68k.py` 의 `stage` 가 이를 복사), `x86gate` 는 `s6l4-g*-stage` 매니페스트가 다시 만든 것과 같아야 통과합니다. 07 을 고치면 s6l4 바탕에는 옛 kdp.c 가 남고 x86gate 는 실패합니다.

방법(각 단계가 실패하면 멈추고 보고; 기준은 완화하지 않음):
1. **07 편집**(`07_kernel/src/kern/kdp.c`):
   - 머리 주석(1–10 행) 뒤에 machdep.c(plan 404) 꼴의 고지 묶음: `The line marked "plan 466 (Darwin)" is the same as Darwin 0.1 kernel/kern/kdp.c:439 (kernel-1), whose notice is:` + Darwin 1–23 행 그대로.
   - 373–375 행: 주석을 `/* one region: the kernel's range, VM_MIN_KERNEL_ADDRESS to VM_MAX_KERNEL_ADDRESS */` 로, `r->address = (void *) VM_MIN_KERNEL_ADDRESS;\t/* plan 466 (D082) */`, `r->nbytes = VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS;\t/* plan 466 (Darwin): Darwin 0.1 kern/kdp.c:439 */`.
   - 코드 글은 §466.2 의 변형 M 과 같아야 합니다(python 으로 변형 M 의 해당 두 줄과 비교; 주석만 다름).
2. **x86 전체 재빌드**(HOWTOCOMPILE 5 절, `L2_FORMS=…-s6p398.tsv`, `L2_EXPECT=…-s6p398.json`): 접두어 `s6l5`, 일곱 묶음(g1a·g2aa·g2ba·g3a·g4a·g5a·g6a). 통과 조건: 각 `check` 기록에서 problem 0, 모든 행이 same_as_baseline 또는 expected_ok, `deps_not_from_07` 비어 있음, group-vs-singleton 차이 0.
3. **s6l5 ↔ s6l4 비교**(python, 새 도구 `10_tools/reconstruction/l2_prefix_diff.py`, 기록 `09_validation/reconstruction/s6-l2-prefixdiff-s6l4-s6l5-20261016.json`): (a) 일곱 스테이징 매니페스트의 차이가 `src/kern/kdp.c` 항목 하나뿐; (b) 402 객체 중 SHA 가 다른 것은 `L2_181__kdp.o` 하나뿐; (c) 그 kdp 두 객체의 비 STABS 절 바이트·재배치가 같음(`m3_m68k_diag.canon`).
4. **링크**(HOWTOCOMPILE 6–7 절): `l2_link.py prepare s6p466-ln1 s6l5` → kr_run → `l2_compare.py` → `cmp` 로 원본과 같음(SHA `33469393…`). 같지 않으면 멈추고 07 을 되돌릴지 사용자에게 묻습니다.
5. **m68k 바탕 갱신**: `stage_m68k.py` 에서 `--plan 466` 이상이면 바탕을 `08_build/runs/tools/s6l5-g1a-stage`, x86gate 를 `s6l5-g*-stage` 매니페스트로 하고(465 이하는 지금대로 s6l4; `m0_m68k_l1.py` 는 고치지 않음), 바탕 매니페스트 해시 검사는 같은 방식으로 합니다. `EXCEPTS[466]` = 465 의 열아홉 + `x86-kdp`, `--plan` 목록에 466. MARKERS 는 그대로(덮어쓰기 없음). `m5_m68k_pc.py` `FILES['kdp'] = 'kern/kdp.c'`.
6. **m68k 확인**: `--plan 466 stage 08_build/runs/tools/m0p466-a1-stage` → `x86gate`(일곱 개 모두 같음, v183 경로 0) → 스테이징 차이를 `m0p465-a1-stage` 와 python 으로 비교(파일 차이는 `src/kern/kdp.c` 하나뿐이어야 함) → `m5_m68k_pc.py cmd2 … 466 kdp` → run `m5p466-a1` → `otool` → `final`(OBJECT_MATCH, 원본에 없는 미정의 0) → 변형 M 객체(`08_build/runs/m5p466-var1/out/P466__M.o`)와 비 STABS 같음.
7. **기록**: PROVENANCE 616 행을 그 자리에서 갱신(authored → authored+darwin01, Darwin kernel-1 tarball SHA·`darwin01/kernel/kern/kdp.c:439`·APSL 고지·새 파일 SHA), MODIFICATIONS 에 한 행 덧붙임, diff `06_reconstruction/evidence/x86-kdp-plan466.diff`, `x86-kdp.md` 에 plan 466 문단 덧붙임, 검증 기록(`s6-l1-*-s6l5-*.json` 일곱, `s6-l2-link-s6p466-ln1.json`, prefixdiff, `m5-m68k-kdp-20261016.json`). 행 수 확인(PROVENANCE 1094 유지, MODIFICATIONS +1).

### 466.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| x86 컴파일에 vm_param.h 세 개가 이미 들어옴(360.out:24–25), 원천은 07 nextdev i386 머리 | 360.out 24–25 행, s6l4-g1a 매니페스트 4827–4831 행 읽음 | ✅ |
| m68k 머리 71–72 행이 0x10000000·0x14000000; 변형 M 은 그 글로 OBJECT_MATCH | 스테이징 머리 71–72 행, `p466_M.c:374–375` 읽음, 변형 기록(M OBJECT_MATCH) | ✅ |
| `address` 는 `void *`, `nbytes` 는 `unsigned`, `vm_offset_t` 는 `unsigned int` → x86 코드 변화 없음 예상 | `kdp_protocol.h:182–184`, nextdev `i386/vm_types.h:86,101` 읽음 | ✅ 예상일 뿐, 판정은 재빌드 |
| M 은 Darwin 의 왼쪽 형변환을 쓰지 않음 | D082 와 `p466_M.c` 두 줄 읽음 | ✅ |
| Darwin 437 `#if`, 438 address, 439 nbytes | python 줄 세기(이번 세션) | ✅ |
| Darwin 1–23 행이 APSL 고지 전체, 25 행부터 NeXT 저작권 | 22–27 행 읽음 | ✅ |
| l2_link 는 접두어 glob 기록만 읽고 일곱 묶음이 다 있는지 따로 보지 않음; 행이 이어지는지만 검사 | `l2_link.py:64–73` 읽음 | ✅ 링크 전 python 으로 402 행·일곱 기록 확인 |
| `L2_FORMS`·`L2_EXPECT` 를 prepare·check 모두에 줘야 함 | `l2_rebuild.py` 머리(27–37 행) 읽음 | ✅ |
| kdp 는 forms 행 181(TSV 182 행); `_log` 번호는 실행 순서 | s6l4 객체 이름 `L2_181__kdp.o`, TSV 182 행 | ✅ |
| 다시 돌린 기록이 같은 glob 에 겹치면 assert 실패 | `l2_link.py:68` 읽음 | ✅ 재시도는 새 접두어로 |
| `check` 는 실패해도 종료 0, 링크는 deps 경고를 거부하지 않음 | HOWTOCOMPILE 5 절 본문 | ✅ 단계 2 의 json 검사 유지 |
| 나머지 401 객체 동일은 기대일 뿐, kdp 는 s6l2–s6l4 에서 같은 SHA | `sha256sum`(이번 세션), s6l4 기록 2563–2566 행 | ✅ |
| 주 소스 디렉터리 STABS 를 내지 않음(`nextstep.h:293–296`) → RID 가 바뀌어도 내장 경로는 그대로 | 290–297 행 읽음 | ⚖️ 주 디렉터리는 맞으나, 헤더 인라인의 N_SOL 등은 실기 절대 경로(RID 포함)를 담음 — §466.5 에서 결과로 드러남(처음 ✅ 는 제 검증 부족) |
| vers.c 의 날짜는 고정 글 | `conf/vers.c:1–11` 읽음 | ✅ |
| kdp 는 STABS 만 다르고 `canon` 은 절 바이트·재배치만 비교 | `m3_m68k_diag.py:34–43` 읽음 | ✅ |
| `strip -x` 가 STABS 를 없앰 | python: s6p404 `.sys` 기호 400,614·STABS 394,087, strip 결과 기호 3,751·STABS 0 | ✅ |
| `stage_m68k.py` 는 바탕을 세 자리(325 매니페스트 검사, 328 복사, 357 기록)에서 씀 → 한 도우미로 바꿔야 함 | 325–357 행 읽음 | ✅ 계획 수정 |
| 다른 s6l4 참조(m3_m68k_wide, m0_slice_l1, l2_place)는 옛 기록용이라 그대로 | grep `s6l4` 다섯 파일, 해당 줄 읽음 | ✅ |
| 465 이하 x86gate 는 07 을 고친 뒤 실패함 | 383–408 행(지금 07 로 다시 스테이징) | ✅ 기록에 적음 |
| `cmd2` 의 kdp 줄은 cc.cmd 81 행 하나뿐 | grep: cc.cmd 1, m3p429 run.cmd 0; 81 행 | ✅ |
| x86gate 의 `all()` 은 빈 목록이면 통과 | 383–408 행 assert 읽음 | ✅ 일곱 개 이름 assert 추가 |
| `otool` 기본 접두어 `P444__`, `final` 은 `466 kdp` 를 줘야 함 | 91–100·262–271 행 읽음 | ✅ |
| `final` 의 shape 는 등록 안 된 이름이면 kern_exec 참조와 비교(무의미) | `cmd_compare` 133 행 `(MP if … else KE)` | ✅ kdp 판정에 쓰지 않음 |
| `canon` 은 COMMON·외부 정의를 보지 않음; M 에는 COMMON 4 개 | 변형 기록(M: `_ifnet` 4, `_kdp` 26, `_master_cpu` 4, `_rawintrq` 20; 외부 정의 1) | ✅ 비교 추가 |
| 머리 주석의 "structure only" 를 고치고 "바이트로 구별 안 됨" 유지 | `kdp.c:4–9`, PROVENANCE 616 읽음 | ✅ |
| 07 kdp.c 는 438 행(439 아님) | `wc -l` 438, 438 행 `}` | ✅ 제 오류, 고침 |
| 실패 시 증거 보존 후 되돌림, run ID 재사용 금지 | 기존 규칙 | ✅ |

계획 수정:
- 단계 1: 머리 주석 4–9 행의 "consulted for structure only" 뒤에 "except the line marked plan 466 (Darwin)" 를 덧붙입니다.
- 단계 3 뒤·4 앞: `s6-l1-*-s6l5-*.json` 이 일곱 개이고 행이 1–402 인지 python 으로 확인합니다.
- 단계 5: `stage_m68k.py` 에 바탕 도우미(PLAN ≥ 466 → s6l5-g1a-stage)를 두어 매니페스트 검사·복사·기록 세 자리에 씁니다. x86gate 는 PLAN ≥ 466 이면 s6l5, 아니면 s6l4 를 쓰고, 이름 일곱 개(g1a·g2aa·g2ba·g3a·g4a·g5a·g6a)가 모두 있어야 합니다.
- 단계 6: `otool m5p466-a1 … F466__`, `final … 466 kdp`. shape 결과는 판정에 쓰지 않습니다. 변형 M 과 비교할 때 COMMON·외부 정의·미정의 집합도 같아야 합니다.

### 466.5 x86 재빌드 결과(2026-10-16)와 단계 3 기준 어긋남

- s6l5 일곱 묶음(run `s6l5-g1a`·`g2aa`·`g2ba`·`g3a`·`g4a`·`g5a`·`g6a`)이 모두 DONE 이고, 실패한 명령은 없습니다. 기록은 `09_validation/reconstruction/s6-l1-G*-s6l5-*.json` 일곱 개이며, 402 행이 1–402 로 이어집니다. 결과는 problem 0, 기준선과 같음 377·기대와 맞음 25, `deps_not_from_07` 0, group-vs-singleton 0 입니다(python). kdp(행 181)는 OBJECT_MATCH 이고 기준선과 같습니다.
- 단계 3(`l2_prefix_diff.py s6l4 s6l5`, 기록 `09_validation/reconstruction/s6-l2-prefixdiff-s6l4-s6l5-20261016.json`):
  - (a) 스테이징 차이는 `src/kern/kdp.c` 하나이고, 명령 파일은 RID 만 다릅니다. **통과**입니다.
  - (c) kdp 의 비 STABS(절 바이트·재배치·절 머리·비 STABS 기호·Mach-O 머리)는 같습니다. **통과**입니다.
  - (b) "SHA 가 다른 객체는 kdp 하나뿐"은 **맞지 않습니다**. kdp 말고도 15 객체(NXSpinLock, NXConditionLock, EventDriver, EventInput, IOTokenRing, SCSIDisk, IODiskPartition, SCSIDiskThread, InputStream, hashtable, except, HashTable, IOVPCodeDisplay, IOEthernetDebugger, IOEISADirectDevice)의 SHA 가 다릅니다.
- 원인(python): 이 15 객체의 헤더 인라인 STABS 에 실기 절대 경로 `/ndrv/…/08_build/runs/<RID>/src/…` 가 들어 있습니다. 새 객체에서 `/08_build/runs/s6l5-` 를 `/08_build/runs/s6l4-` 로 바꾸면 15 개 모두 옛 객체와 바이트가 같습니다(바뀐 곳은 객체마다 1–11 곳). 같은 15 객체는 s6l3→s6l4 비교(plan 404 때 RID 만 바뀜)에서도 SHA 가 달랐습니다. 이는 07 소스 때문이 아니라 빌드 경로에서 생기는 차이입니다.
- 미리 정한 기준이 어긋났으므로 링크(단계 4) 전에 멈추고 사용자에게 묻습니다. 물을 것은 단계 3 (b) 를 "kdp 밖의 SHA 차이는 RID 경로 문자열뿐(바꿔 넣으면 바이트 동일)"로 판정해 링크로 넘어갈지입니다.
- 사용자 결정 D083(2026-10-16): "RID 정규화로 판정, 링크 진행 (Recommended)". `l2_prefix_diff.py` 에 `rid_normalized_equal` 을 더해 기록을 다시 만들었습니다. 결과는 `sha_differ_not_rid_only` = [`x86-kdp`] 이고, kdp 는 비 STABS 가 같습니다. 단계 4 로 넘어갑니다.

### 466.6 결과(2026-10-16) — 기록 `09_validation/reconstruction/s6-l2-link-s6p466-ln1.json`(x86 링크), `m5-m68k-kdp-20261016.json`(m68k)

- 07 `kern/kdp.c` 를 고쳤습니다. 새 SHA-256 은 `4e343962…`, 467 행입니다. 고지 묶음(머리)과 표시 두 줄이 들어갔고, 코드 두 줄은 변형 M 과 같습니다(python). diff 는 `06_reconstruction/evidence/x86-kdp-plan466.diff` 입니다.
- x86: 링크 run `s6p466-ln1`(명령 넷 모두 종료 0; 링크 명령은 s6p404-ln1 과 RID 만 다름) → **원본과 바이트 단위로 같음**(`cmp` 차이 0, SHA-256 `33469393…`). l2_compare 결과는 머리·로드 명령 같음, 외부 기호 3,751 같음, 공통 417/417 같음입니다.
- m68k:
  - `stage_m68k.py --plan 466 stage` → `m0p466-a1-stage`(바탕 s6l5-g1a-stage). `m0p465-a1-stage` 와의 파일 차이는 `src/kern/kdp.c` 하나입니다.
  - x86gate 는 s6l5 일곱 개가 모두 같고 v183 경로 0 입니다(`08_build/artifacts/m5p466/x86gate/x86gate.json`).
  - run `m5p466-a1`(종료 0, 경고 없음) → **OBJECT_MATCH**, 원본에 없는 미정의 0 입니다. 변형 M 객체와 비 STABS·COMMON·외부 정의·미정의·절 머리가 모두 같습니다(python). otool SHA 는 실기 krsha256 과 같습니다.
  - `final` 의 외부 구간 `_kdp_packet` 은 `equal` False 입니다. 원본에는 정적 함수 기호가 없어 이미지 구간이 3,280 B 로 객체 구간 1,320 B 보다 길기 때문입니다. 마스크한 앞부분은 같고(`masked_equal_prefix` True), 변형 C·M·MD 에서도 똑같이 나왔습니다. shape 결과는 §466.4 대로 판정에 쓰지 않았습니다.
- 기록: PROVENANCE 616 행을 그 자리에서 갱신했습니다(authored+darwin01; 1094 행 유지, 대상 경로 중복 0). MODIFICATIONS 는 1 행을 덧붙여 621 행, `x86-kdp.md` 에는 plan 466 절을 덧붙였습니다.
- 집계: m68k OBJECT_MATCH 169(+ 명시 배치 ufs_alloc 1), 코드 차이가 남은 객체는 21 + 컴파일 안 되는 ns_timer 입니다.
- 도구 변경: `l2_prefix_diff.py`(새로 만듦), `stage_m68k.py`(--plan 466 바탕·x86gate 를 s6l5 로, 일곱 묶음 assert, `EXCEPTS[466]`), `m5_m68k_pc.py`(`FILES['kdp']`).
- 465 이하 계획의 x86gate 는 이제 07 kdp.c 가 바뀌었으므로 s6l4 매니페스트와 맞지 않습니다(§466.4 에서 예상한 대로이고, 옛 기록은 그대로 둡니다).

## 467. M5-24 세부 계획 — m68k `nfs_subr`(함수 순서)·`nfs_vfsops`(쓰이지 않는 static `hostpath`): -O2/-O3 출력 차이(코딩 전, 2026-10-16)

확인한 사실(§441 객체 `O441__L2_355__nfs_subr.o`·`O441__L2_356__nfs_vfsops.o` 의 otool 목록과 원본 이미지 목록 `08_build/artifacts/m0p414/otool-V10/image.txt` 를 원본 자리에 맞춰 비교):
- **nfs_subr**(원본 0x402872e–0x40297da, python 4268 B = 객체 4268 B):
  - 두 함수의 순서만 다릅니다. 원본은 0x40296f8 에 짧은 함수(`addql #1` 카운터, 인자가 0 이 아니면 `bsr` wakeup)를 두고, 0x4029716 에 `pea 0x40296f8:l` 로 그 주소를 timeout(0x40035e0)·untimeout(0x4003618)에 넘기는 함수를 둡니다. 우리 객체는 `_rlock_timeout`(0xfca) 뒤에 `_rlock_awaken`(0x108e)이 옵니다.
  - 07 `bsd/nfs/nfs_subr.c` 는 1138 행 `static void rlock_awaken();`(전방 선언), 1141 행 `rlock_timeout`, 1170–1177 행 `rlock_awaken` 정의 순서입니다(plan 280, x86 원본 0x12fd1c 뒤 0x12fdd0 순서에 맞춤).
  - 0x494 부근 목록 차이(`subb`/`orb`)는 점프 표의 재배치된 절대 주소입니다(0x402872e+0x45e = 0x4028b8c, +0x4c4 = 0x4028bf2 로 원본 값과 같음). 차이가 아닙니다.
- **nfs_vfsops**(원본 0x40297da–0x402a9f6, python 4636 B; 객체 4696 B, 차 60):
  - 객체에는 `_itoa` 와 `_addr_to_str` 사이에 `_hostpath`(0x11b6–0x11f2, python 60 B)가 있고, 원본에는 없습니다(원본 itoa 끝 0x402a98e 바로 뒤 0x402a990 이 addr_to_str 꼴). 이 밖의 명령 차이는 없습니다(마스크 비교 블록 1 개).
  - 07 `nfs_vfsops.c:1243` `static hostpath(…)	/* plan 281: static */`. 부르는 곳은 360·392 행뿐이고 둘 다 `#if !MACH`(308–405 행) 안이라 컴파일되지 않습니다. 우리 m68k 객체에도 hostpath 를 부르는 명령이 없습니다.
  - NeXTMach mk-108.1 `nfs/nfs_vfsops.c:1218` 은 전역 `hostpath(name, shostname, path)` 입니다(부르는 곳 339·371 행은 `#if !MACH` 287–384 행 안). Darwin 0.1 `bsd/nfs/nfs_vfsops.c` 에는 `hostpath` 가 없습니다(grep 0 건).
- 설명 가설(실행으로 확인 필요; 바이트가 맞아도 원래 소스 꼴을 증명하지는 않음): x86 은 `-O3`(`-finline-functions`)라 GCC 2.7 이 인라인 후보 static 함수를 미뤄 두었다가 필요하면 파일 끝에 내고, 쓰이지 않으면 버립니다. m68k 는 `-O2` 라 static 함수를 소스 순서대로, 쓰이지 않아도 냅니다. 그렇다면 원래 소스는 `rlock_awaken` 을 `rlock_timeout` 보다 앞에 정의했고, `hostpath` 는 m68k 에서 출력되지 않는 꼴(예: `#if !MACH` 안 또는 `static inline`)이었을 것입니다.

방법:
1. m68k 변형 시험(`m5_m68k_srcvar.py`, 바탕 `m0p466-a1-stage`, 명세 `08_build/artifacts/m5p467/spec-nfs_subr.json`·`spec-nfs_vfsops.json`):
   - nfs_subr: `K` 그대로; `A` = `rlock_awaken` 정의(주석 줄 포함)를 `rlock_timeout` 앞(전방 선언 뒤)으로 옮김; `B` = A + 전방 선언 1138 행 삭제.
   - nfs_vfsops: `K` 그대로; `M` = `hostpath` 정의를 `#if !MACH` / `#endif !MACH` 로 감쌈; `I` = `static hostpath` → `static inline hostpath`; `G` = NeXTMach 꼴 전역(`static` 없앰, 대조용: 원본에 기호가 없으므로 맞지 않아야 함).
   - 대조 K 가 §441 객체를 재현하지 못하면 멈춤.
2. x86 확인(07 본 파일에 둘 수 있는지): 새 도구 `10_tools/reconstruction/m5_x86_srcvar.py` 로 같은 명세의 변형을 `s6l5-g1a-stage` 위에서 x86 forms 줄(`s6l5-g1a.cmd` 의 해당 `-c` 줄, 출력만 바꿈)로 컴파일하고, s6l5 객체(`L2_355__nfs_subr.o`·`L2_356__nfs_vfsops.o`)와 비 STABS(`m3_m68k_diag.canon`)·절 머리·비 STABS 기호가 같은지 봅니다.
3. 고르기(미리 정함): m68k OBJECT_MATCH + 원본에 없는 미정의 0 + 공통 기호·외부 정의 K 와 같음. 맞는 꼴이 여럿이거나, 자리(07 본 파일: x86 같음 확인된 것만 / m68k 덮어쓰기)를 정해야 하면 사용자에게 묻습니다. 맞는 꼴이 없으면 진단을 기록하고 멈춥니다.
4. 결정 뒤 구현: 07 본 파일이면 §466 절차(x86 전체 재빌드 s6l6 + 링크·`cmp` + m68k 바탕 갱신), 덮어쓰기이면 §458 이후 절차(`plan 467 (m68k)` 표시, `stage_m68k.py` 등록, `m5_m68k_pc.py` final).
5. 기록: 변형 기록 `09_validation/reconstruction/m5-m68k-nfs-{subr,vfsops}-variants-20261016.json`, x86 기록 `m5-x86-nfs-{subr,vfsops}-variants-20261016.json`.

### 467.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 두 객체 모두 `__bss` 가 L1 에서 unverified 라 OBJECT_MATCH 는 나올 수 없음 → bss 만 남고 zerofill 추정으로 판정해야 함 | §441 L1 기록 `l1-x86-nfs_subr.json`·`l1-x86-nfs_vfsops.json` 의 이유 출력, scratchpad L1 요약 | ✅ 기준 고침 |
| nfs_subr 의 bss 는 `static unsigned int newnum`(4 B, 1089 행) | 1089 행 읽음, L1 bss size 4 | ✅ (후보 주소 0x40b352c 는 zerofill 로 확인) |
| nfs_vfsops bss 52 B(`nfs_minmap` 82 행, `bootparam_addr` 455 행, `nfslock` 1204 행), L1 추정 자리 0x40b3530 | 세 줄 읽음, L1 bss 주소 67843376 = python 0x40b3530 | ✅ |
| 크기 4268·4636·4696·60 | python(§467 작성 때) | ✅ |
| 원본은 콜백이 앞, 07·객체는 반대(0xfca, 0x108e) | 목록·소스 읽음 | ✅ |
| 점프 표 `subb`/`orb` 는 표 데이터 | python 재배치 값 계산 | ✅ |
| nfs_mount 의 addr_to_str 호출 변위(객체 0x11f2, 원본 0x402a990)도 hostpath 제거의 결과 | 객체 목록 859 행 `bsr 0x11f2:l`, 이미지 52750 행 `bsr 0x402a990:l`(codex 인용 857·52748 은 2 행 어긋남) | ⚖️ 사실, 인용 줄은 틀림 |
| `__data`(133·36 B) 참조 차이 0 | L1 기록 data 절 | ✅ |
| cstring 내용은 원본에 있음 | 검토자 계산 | ⏭️ L1 이 판정 |
| `hostpath` 호출은 `#if !MACH` 안이고 두 아키텍처 모두 `-DMACH` | 07 308·360·392·405 행, m68k cc.cmd 118 행 `-DMACH -O2 -traditional-cpp` | ✅ |
| NeXTMach 1218 전역 정의, Darwin 에 없음 | python 줄 확인, grep -c 0 | ✅ |
| scratch `gccsrc/toplev.c` 2969·3010·3016·3070·3733 행, 끝 처리(2525–2600 행): 인라인 후보를 미루고 참조되면 낸다; `c-decl.c` 는 없음 | 해당 줄 읽음, `ls gccsrc`(toplev.c 만, c-decl 없음) | ✅ 가설은 그럴듯하나 실행이 판정 |
| `static inline` 이 -O2 에서 빠지는지는 보장 안 됨 | 위 toplev.c 조건 | ✅ 실험으로 둠 |
| 바이트가 맞아도 원래 소스 꼴을 증명하지 않음 | 프로젝트 원칙 | ✅ 문구 고침 |
| 두 명세가 같은 디렉터리라 `p467_K.c`·`P467__K.o` 가 겹침 | srcvar `vfile`(68–69 행)·`cmd`(116 행) | ✅ 명세마다 스테이징·run 따로 |
| x86 명령은 입력(-c)과 출력(-o)을 모두 바꿔야 함 | srcvar `cmd_cmd` 114–116 행 | ✅ 계획 문구 고침 |
| x86 도구는 바탕·대조 참조를 x86 것으로 | 설계 | ✅ |
| `canon` 만으로는 부족 → 머리·절 머리·비 STABS 기호(COMMON·UNDF 포함) | `canon` 34–43 행, `l2_prefix_diff.obj_sig` | ✅ |
| 실행 상태·누락·해시를 기록 | srcvar 기록 꼴 | ✅ |
| 덮어쓰기는 줄 삽입만 가능(옮기기는 `#if` 삽입으로) | `stage_m68k.check_derived` | ✅ |
| final 의 shape 는 판정에 쓰지 않음 | §466.4 | ✅ |
| 본 파일 변경이면 x86 전체 재빌드 + RID 정규화 기준(D083) + 바탕 s6l6 | §466 | ✅ |
| 기록 목록 보강 | — | ✅ |

계획 수정:
- 고르기: m68k 변형 L1 이유가 `__DATA,__bss: unverified` 하나뿐(텍스트·데이터 통과) + 원본에 없는 미정의 0 + 공통 기호·외부 정의 K 와 같음 → 그 뒤 `zerofill_check.py`(§464 방식)로 bss 자리 추정.
- 명세·스테이징·run 을 객체마다 따로: nfs_subr `m0p467-s-stage`/run `m5p467-s1`, nfs_vfsops `m0p467-v-stage`/run `m5p467-v1`.
- x86 도구 `m5_x86_srcvar.py`: 같은 명세의 변형을 `s6l5-g1a-stage` 복사본에 넣고 `s6l5-g1a.cmd` 의 해당 `-c` 줄에서 입력·출력을 바꿔 컴파일; 각 변형을 s6l5 객체와 비교(`canon`, Mach-O 머리, 절 머리, 비 STABS 기호 전체); 대조 K 는 s6l5 객체와 같아야 함; 상태·해시 기록. run `m5p467-xs1`·`m5p467-xv1`.
- 덮어쓰기로 갈 경우 옮기기는 `#if m68k` 삽입 꼴로.
- 기록 추가: 최종 m68k·zerofill 기록, 고른 변형과의 동일성, diff·PROVENANCE·MODIFICATIONS, 본 파일이면 x86 재빌드·링크 기록.

### 467.2 변형 시험 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-nfs-{subr,vfsops}-variants-20261016.json`, `m5-x86-nfs-{subr,vfsops}-variants-20261016.json`

- m68k(run `m5p467-s1`·`m5p467-v1`, 명령 모두 종료 0, 경고는 변형마다 같은 수의 기존 경고):
  - 대조 K 는 두 객체 모두 §441 객체를 재현했습니다.
  - nfs_subr: **A·B 가 비 STABS 로 같고**, L1 이유는 `__DATA,__bss: unverified` 하나뿐입니다. 원본에 없는 미정의 0, 공통 기호·외부 정의는 K 와 같습니다.
  - nfs_vfsops: **M·I 가 같고**, 이유는 bss 하나뿐입니다. G(전역)는 K 와 같은 텍스트 차이에 외부 기호 `_hostpath` 가 더해져 맞지 않습니다(예상대로).
  - (srcvar 의 외부 구간 `equal` False 는 §466.6 과 같은 정적 함수 구간 한계입니다.)
- x86(새 도구 `m5_x86_srcvar.py`, run `m5p467-xs1`·`m5p467-xv1`, 바탕 s6l5): A·B·K 와 I·M·K 가 s6l5 객체와 비 STABS·Mach-O 머리·절 머리·비 STABS 기호 모두 같습니다. 대조 K 도 같습니다. G 는 다릅니다.
- bss(§464 방식, `08_build/artifacts/m5p467/zerofill/`): 네 변형 모두 reference-inferred 이고, problem 은 없습니다.
  - nfs_subr 은 [0x40b352c, 0x40b3530) 4 B, nfs_vfsops 는 [0x40b3530, 0x40b3564) 52 B 입니다.
  - §464 의 16 후보와 겹침 0 이고, 앞뒤가 ip_input → nfs_subr → nfs_vfsops → nfs_vnodeops 로 이어집니다(python).
- 바이트로 구별되지 않는 꼴이 둘씩이고 자리(07 본 파일 / m68k 덮어쓰기)도 정해야 하므로 사용자에게 묻습니다.

### 467.3 D084·D085 구현 계획(07 본 파일 두 개 + x86 전체 재빌드 s6l6 + m68k 바탕 갱신; 코딩 전, 2026-10-16)

§466.3–§466.6 의 절차(§466.4 판정과 D083 RID 정규화 기준 포함)를 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
1. **07 편집**
   - `bsd/nfs/nfs_subr.c`: 변형 A 와 같은 코드로 고칩니다. 옮긴 정의 앞에 `/* plan 467 (D084): defined before rlock_timeout, as in the m68k original */` 주석을 붙입니다.
   - `bsd/nfs/nfs_vfsops.c`: 변형 M 과 같은 코드로 고칩니다. `#if\t!MACH` 줄에는 `/* plan 467 (D085): hostpath is used only by nfs_swapvp */` 주석을 붙입니다.
   - python 으로 주석을 뺀 코드가 변형 A·M 과 같은지 확인합니다.
2. **x86 전체 재빌드** s6l6(일곱 묶음, `L2_FORMS`/`L2_EXPECT` s6p398). 통과 조건: problem 0, 모든 행 same_as_baseline 또는 expected_ok, deps 경고 0, 기록 일곱 개, 행 1–402.
3. **s6l5↔s6l6** `l2_prefix_diff.py`:
   - 스테이징 차이는 `src/bsd/nfs/nfs_subr.c`·`src/bsd/nfs/nfs_vfsops.c` 둘뿐이어야 합니다.
   - `sha_differ_not_rid_only` 는 `x86-nfs_subr`·`x86-nfs_vfsops` 둘뿐이고, 둘 다 비 STABS 가 같아야 합니다.
4. **링크** `s6p467-ln1` → `l2_compare` → `cmp` 로 원본과 같아야 합니다.
5. **도구**
   - `stage_m68k.py`: `X86[467] = 's6l6'`, `EXCEPTS[467]` = 466 의 스물 + `x86-nfs_subr`·`x86-nfs_vfsops`, `--plan` 목록에 467 을 넣습니다.
   - `m5_m68k_pc.py`: `FILES` 에 `nfs_subr`·`nfs_vfsops` 를 넣습니다.
   - `m5_x86_srcvar.py`: 기본 `X86` 은 그대로 s6l5 로 둡니다(이번 시험 기록 재현용).
   - `m5_m68k_zerofill.py`: 주어진 객체에 같은 절차를 돌리고 §464 후보와의 겹침을 보는 `objs` 모드를 더합니다.
6. **m68k**
   - `--plan 467 stage m0p467-a1-stage` → x86gate(s6l6 일곱) → `m0p466-a1-stage` 와의 파일 차이 둘 확인.
   - `cmd2 … 467 nfs_subr,nfs_vfsops` → run `m5p467-a1` → `otool … F467__` → `final … 467 nfs_subr,nfs_vfsops`.
   - 통과 조건: 두 객체 L1 이유가 bss 하나뿐, 원본에 없는 미정의 0, `P467__A`·`P467__M` 과 비 STABS·머리·절 머리·비 STABS 기호 같음, zerofill reference-inferred·겹침 0.
7. **기록**
   - PROVENANCE 두 행(07 nfs_subr.c·nfs_vfsops.c)을 그 자리에서 갱신하고, MODIFICATIONS 에 두 행을 덧붙입니다.
   - diff `06_reconstruction/evidence/x86-nfs_subr-plan467.diff`·`x86-nfs_vfsops-plan467.diff` 를 만들고, evidence md 두 개에 plan 467 문단을 덧붙입니다.
   - 검증 기록: s6l6 일곱, prefixdiff, link, `m5-m68k-nfs-20261016.json`(final), zerofill 기록.
   - 집계: 코드 차이 21 → 19 이고, 두 객체는 "코드 검증 + bss 추정"(§464 의 16 과 같은 등급)입니다.

### 467.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| nfs_subr 편집은 전방 선언을 두고 정의(이름 주석 포함)를 앞으로 옮기면 A 와 같음 | 명세 A 를 만들 때 python 으로 만든 diff | ✅ |
| nfs_vfsops 는 hostpath 만 감싸고 addr_to_str 는 밖 | 명세 M 의 바꿀 글(정의 본문만) | ✅ |
| `#if` 줄 뒤 주석·독립 주석은 토큰을 바꾸지 않음; STABS 는 바뀔 수 있어 객체 비교가 필요 | 컴파일 줄(m68k cc.cmd 117·118 행 `-traditional-cpp -O2`, x86 s6l5-g1a.cmd 583 행 `-O3`) 확인 | ✅ |
| `X86[467]` 하나로 바탕·매니페스트·x86gate 가 바뀜; `EXCEPTS[467]` 는 22 개 | `stage_m68k.py` 도우미(§466 에서 씀), python 20+2 = 22 | ✅ |
| MARKERS 등록 불필요 | `check_derived` 는 덮어쓰기 .c 만 검사 | ✅ |
| `FILES` 두 줄은 cc.cmd 117·118 행에 하나씩 | grep(이번 세션: 각 1, m3p429 0) | ✅ |
| 07 을 고치면 `m5_x86_srcvar.py stage` 는 "base differs from the 07 main file" assert 로 실패하므로, 다시 돌리려면 고치기 전 소스가 필요 | 도구 65 행 | ✅ 기록에 적음(옛 기록은 해시로 재현성 판단) |
| prefixdiff 는 `stage_keys_differ`·`cmd_differ` 빈 것과 `differing_non_stabs_equal` 도 요구해야 함 | `l2_prefix_diff.py` 요약 키 | ✅ 기준 추가 |
| 함수를 옮기면 비 STABS 가 바뀔 수 있으나 이번 x86 A 는 같음 | `m5-x86-nfs-subr-variants` 기록(A canon·머리·절·기호 같음) | ✅ |
| final 비교는 `P467__A`·`P467__M` 과 canon + 머리·절 머리·비 STABS 기호(STABS 수 제외) | 설계 | ✅ |
| `final` 은 성공을 강제하지 않으므로 명시 검사기가 필요 | `m5_m68k_pc.cmd_final`(178 행~) 은 기록·출력만 함 | ✅ zerofill 도구의 새 모드에서 검사 |
| `objs` 모드는 §441 객체 선택을 거치지 않고 경로를 받아야 함; 겹침은 §464 후보 + 새 후보 전체로 | `m5_m68k_zerofill.m68k`(64–93 행) | ✅ |
| PROVENANCE 는 645·648 행, 출처 분류(nextmach)는 그대로 | 두 행 첫 두 칸 확인 | ✅ |
| 기록 꼴: `l2_prefix_diff.py` 는 plan=466, zerofill 도구는 plan=464 를 박아 둠 | grep 94·58·94 행 | ✅ 인자로 받게 함 |
| 고른 변형 L1 은 `NOT_MATCH` + bss 하나 | `l1-m5p467-s1-A.json`·`l1-m5p467-v1-M.json` 출력 | ✅ |

계획 수정:
- `l2_prefix_diff.py` 에 선택 넷째 인자 PLAN(기본 466)을 둡니다. 단계 3 통과 조건에 `stage_keys_differ == []`, `cmd_differ == []`, `differing_non_stabs_equal == true` 를 더합니다.
- `m5_m68k_zerofill.py` 에 `objs OUTDIR RECORD.json PLAN OBJ=REF …` 모드를 더합니다. 객체마다 다음을 모두 검사(assert)하고 기록합니다.
  - 컴파일 결과 존재
  - L1 이유가 정확히 `['__DATA,__bss: unverified']`
  - 원본에 없는 미정의 0
  - REF 와 canon·머리·절 머리·비 STABS 기호 같음
  - zerofill 종료 0, reference-inferred, problems 빈 것
  - §464 후보와 새 후보를 합친 집합에서 겹침 0

### 467.5 결과(2026-10-16) — 기록 `09_validation/reconstruction/s6-l2-link-s6p467-ln1.json`(x86 링크), `m5-m68k-nfs-20261016.json`(m68k final), `m5-m68k-nfs-zerofill-20261016.json`(검사·bss)

- 07 편집:
  - `nfs_subr.c` 는 1179 행, SHA `38199a58…` 입니다. `nfs_vfsops.c` 는 1275 행, SHA `e54ff25a…` 입니다.
  - 고치기 전 SHA 는 PROVENANCE 에 적힌 `219ea0e0…`·`98e15bf6…` 와 같았습니다.
  - 주석을 뺀 코드는 시험한 변형 A·M 과 같습니다(python).
- x86:
  - s6l6 일곱 묶음은 명령 804 개(python 으로 status 줄 집계)가 모두 종료 0 입니다. check 결과 402 행이 1–402 로 이어지고, problem 0, 기준선과 같음 377, 기대와 맞음 25, deps 경고 0 입니다.
  - prefixdiff(s6l5↔s6l6, plan 467): 스테이징 차이는 두 nfs 파일뿐이고 `stage_keys_differ`·`cmd_differ` 는 비어 있습니다. SHA 가 다른 17 객체 중 RID 경로 말고도 다른 것은 `x86-nfs_subr`·`x86-nfs_vfsops` 둘이고, 둘 다 비 STABS 가 같습니다(`differing_non_stabs_equal` true).
  - 링크 run `s6p467-ln1`(명령 넷 종료 0, s6p466-ln1 과 RID 만 다름) → **원본과 바이트 단위로 같음**(`cmp`, SHA `33469393…`).
- m68k:
  - `m0p467-a1-stage` 는 바탕 s6l6 이고, `m0p466-a1-stage` 와의 차이는 두 nfs 파일뿐입니다. x86gate 는 s6l6 일곱 모두 같고 v183 경로 0 입니다.
  - run `m5p467-a1` 은 두 명령 종료 0 이고, 경고는 변형 시험과 같은 수의 기존 경고입니다. otool SHA 는 실기 krsha256 과 같습니다.
  - final: 두 객체 모두 L1 이유가 `__DATA,__bss: unverified` 하나뿐이고, 원본에 없는 미정의는 0 입니다.
  - 검사 모드(`objs`, assert 통과): `F467__nfs_subr` = `P467__A`, `F467__nfs_vfsops` = `P467__M` 입니다(canon·머리·절 머리·비 STABS 기호). zerofill 은 reference-inferred 로 [0x40b352c, 0x40b3530)·[0x40b3530, 0x40b3564) 이고, §464 후보를 포함한 겹침은 0 입니다.
- 기록:
  - PROVENANCE 645·648 행을 그 자리에서 갱신했습니다(1094 행 유지, 중복 0). MODIFICATIONS 에 두 행을 덧붙여 623 행입니다.
  - diff 두 개를 만들고, evidence md 두 개에 plan 467 절을 덧붙였습니다.
- 집계: 코드 차이가 남은 객체는 19 + ns_timer 이고, "코드 검증 + bss 추정" 은 18 입니다(§464 의 16 + 이번 둘). 등급 P 이며 OBJECT_MATCH 는 아니고, 링크 증명은 M7 에서 합니다.
- 465 이하·466 계획의 x86gate 와 `m5_x86_srcvar.py stage`(s6l5) 는 07 이 바뀌었으므로 이제 다시 돌리면 실패합니다(§467.4). 옛 기록은 그대로 둡니다.

## 468. M5-25 세부 계획 — m68k `ns_timer`: 콜아웃 큐 작성(사용자 선택 "(나)", §448.2; 코딩 전, 2026-10-16)

사용자 선택(2026-10-16, §448.2 의 다음 후보): **"(나)"** — 먼저 m68k 콜아웃 큐를 원본에서 작성하고, 나눗셈은 그 뒤에 다룹니다.

제 오류(먼저 밝힘): §448.1 판정표의 "참고 코드 없음: … NeXTMach grep 0 건" 은 틀렸습니다. `ns_` 이름으로만 찾았기 때문에, 같은 구조의 마이크로초 판인 NeXTMach mk-108.1 `next/us_timer.c` 와 `next/machdep.c` 의 초기화 고리를 놓쳤습니다. 이번에 `hardclock_pc` 로 찾다가 발견했습니다. NeXTMach 저장소 `https://github.com/johnsonjh/NeXTMach.git` 커밋 `f6bdb9c3268f0eadc545d41bcc0564453b17001e` 입니다.

확인한 사실(원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, 기호표 `03_original/m68k/inventory/symbols.tsv`, 거리는 python):
- 객체 [0x404e3a8, 0x404eaae) 1798 B 이고, 큐 부분은 [0x404e3a8, 0x404e712) 874 B 입니다.
  - `_ns_callout_init` 80 B, `_ns_timer_init` 40 B, `_ns_hardclock_init` 56 B, 이름 없는 정적 처리기(0x404e458) 226 B, `_ns_timeout` 68 B, `_ns_abstimeout` 230 B, `_ns_untimeout` 106 B, `_ns_sleep` 68 B.
  - 정적 처리기는 기호표에 없어 `_ns_hardclock_init` 의 구간(282 B)에 들어갑니다. `_ns_timer_init` 이 `pea 0x404e458:l` 로 주소를 넘깁니다.
- 공통 기호(절 6): `_hardclock_pc` 0x40c241c, `_hardclock_ps` 0x40c2420, `_ns_callfree` 0x40c2424, `_ns_callout` 0x40c2428, `_ns_calltodo` 0x40c242c(다음 기호 `_ns_per_tick` 0x40c2444 까지 24 B), `_ns_per_tick`.
  - 앞은 `_miniMonState`, 뒤는 `_min_quantum` 이고, 여섯은 이름 순으로 붙어 있습니다. 여섯 모두 ns_timer.o 의 공통 기호라는 가설과 맞습니다. 링크 증명은 M7 에서 합니다.
- 바깥에서 쓰는 곳(목록 grep):
  - `_main` 이 `_ns_timer_init` 을 부릅니다(§454 덮어쓰기). `_startup` 은 `_ns_callout_init` 을 부르고, `_startup_early` 는 `_ns_callout` 에 값을 씁니다.
  - `_timeout`·`_untimeout`·`_set_timer` 가 `_ns_timeout`·`_ns_untimeout` 을, `_hardclock_init`·`_m68k_hardclock` 이 `_ns_abstimeout` 을 부릅니다.
  - `_m68k_hardclock` 은 `_hardclock_pc`·`_hardclock_ps` 를 읽어 `_hardclock` 에 넘기고, 자기 자신을 `ns_abstimeout(m68k_hardclock, 0, …, 1)` 로 다시 등록합니다.
  - `_evintr` 는 `_ns_callfree` 를 시험합니다. `_ns_sleep` 은 `_proc_shutdown`·`_zsopen`·`_zsselect` 가 씁니다.
- 항목 24 B: +0 다음, +4 시각(64 비트), +0xc 인자, +0x10 함수, +0x14 우선순위.
- 함수별 판독:
  - `_ns_callout_init`: `ns_callfree = ns_callout`; i 를 1 부터 `i < ncallout` 인 동안 **부호 없는 비교(bls/bhi)** 로 돌며 앞 항목의 다음을 뒤 항목으로 잇고, 마지막 항목의 다음을 0 으로 둡니다.
  - `_ns_timer_init`: `splusclock()`(0x2600) 뒤 Mach-O `__set_timer_expire_func`(C 이름 `_set_timer_expire_func`, §468.1)를 `(0, 처리기)` 로 부르고 `splx`.
  - 처리기(인자 셋, 첫째 안 씀):
    - `now = clock_value(System)` 뒤, 머리 항목의 시각이 now 보다 작은 동안 처리합니다.
    - 함수가 `_m68k_hardclock` 이면 `hardclock_ps = 셋째 인자`, `hardclock_pc = 둘째 인자` 를 씁니다.
    - `callout_dispatch(pri, func, arg)` 를 부르고, 머리에서 떼어 `ns_callfree` 에 돌려줍니다.
    - 남은 머리가 있으면 now 와 다시 비교해 지났으면 머리 읽기부터 다시 합니다(now 는 다시 읽지 않음, §468.1). 아니면 `delta = 시각 - now` 를 `timer_attributes(0)` 의 첫 64 비트 값으로 자릅니다.
    - 비었으면 delta 는 그 값 자체입니다. `_set_timer(0, delta)` 하고 0 을 돌려줍니다.
  - `_ns_timeout`: `clock_value(System)` 을 **먼저** 부르고, pri 를 넣은 **뒤** 64 비트 덧셈을 하여 `_ns_abstimeout(proc, arg, time+now, pri)` 를 부릅니다.
  - `_ns_abstimeout`:
    - `splusclock()` 하고, `ns_callfree` 가 0 이면 `panic("ns_abstimeout table overflow")` 합니다(문자열 0x40a8bfd, python 으로 읽음).
    - pri → arg → func 순으로 쓴 뒤 시각 순서 자리에 끼웁니다.
    - 새 항목이 머리이면 `now = clock_value(System)`, `delta = now < deadline ? deadline - now : 0` 을 위와 같이 자르고 `_set_timer(0, delta)` 합니다. 끝에 `splx`.
  - `_ns_untimeout`: `splusclock()` 하고, func·arg 가 같은 항목을 떼어 `ns_callfree` 에 돌려준 뒤 `splx`, TRUE 를 돌려줍니다. 없으면 `splx` 뒤 `callout_remove(proc, arg)` 의 값을 돌려줍니다.
  - `_ns_sleep`: x86 판과 같고 다른 점은 ns_timeout 의 pri 가 **1**(`pea 0x1:w`; x86 판은 `clrl`)이라는 것뿐입니다. §448 객체 `P448__V1.o` 의 otool 목록(`08_build/artifacts/m5p468/otool/`)과 비교했습니다.
- m68k spl: `splusclock` = 0x2600, `splnet` = 0x2200(스테이징 `kernserv/m68k/spl.h`).
- NeXTMach 대응(줄은 직접 읽음):
  - `us_timer.c:63-64`(`hardclock_ps`·`hardclock_pc`), `:73`(`us_callfree`·`us_callout`·`us_calltodo`).
  - `:226-291` `us_timer_int`: `again:` 고리, `hardclock_ps = ps; hardclock_pc = pc;` 순서, `softint_sched(p1->c_pri, p1->c_func, p1->c_arg)`, 떼어 돌려주기, `if (p1) { … goto again; } else interval = TIMER_MAX;`.
  - `:309-368` `us_abstimeout`: panic, pri·arg·func 순서, 끼우기 고리, 머리이면 타이머 다시 걸기.
  - `:373-396` `us_untimeout`, `machdep.c:961-964` 초기화 고리(`startup` 의 `register unsigned int i;` 는 800 행).
  - ns 판은 이것을 ns_time_t 로 옮긴 꼴로 보입니다. 다른 점은 시각 비교, `callout_dispatch`·`timer_attributes`·`_set_timer`, ns_untimeout 의 `callout_remove` 대체입니다.
- 이번 범위 밖(§448 V1 목록에서 본 차이; 기록만 합니다):
  - 나눗셈 네 자리(§448.2)와 `microtime` 의 비교 꼴입니다.
  - `microboot`·`us_timeout`·`us_abstimeout`: 원본은 안쪽 호출을 먼저 하고 인자를 넣습니다. 우리 컴파일러는 중첩 호출을 미리 계산하지 않으므로 임시 변수 꼴로 보입니다. 다음 절에서 다룹니다.

방법:
1. 새 도구 `10_tools/reconstruction/m5_m68k_nsq.py`(stage / cmd / compare)를 만듭니다.
   - 명세 `08_build/artifacts/m5p468/spec.json`(git 무시)에 둡니다. `common` 치환을 07 본 파일 `kern/ns_timer.c` 에 적용한 뒤 변형별 치환을 그 위에 적용합니다. 옛 글은 정확히 한 번 나와야 합니다.
   - 대조 `R` = `m5_m68k_ns.variant_text(':')`(§448 V1 글)입니다. `P448__V1.o` 와 `canon` 이 같아야 스테이징·컴파일 줄이 같다는 확인이 됩니다.
   - stage: 바탕 `m0p467-a1-stage` 를 manifest(경로 집합·SHA-256)로 확인한 뒤 복사하여 `08_build/runs/tools/m0p468-q-stage` 를 만들고, `src/kern/q468_<V>.c` 를 씁니다.
   - cmd: `08_build/artifacts/m3p430/cc.cmd` 의 `kern/ns_timer.c` 줄 하나에서 `-c`·`-o` 만 바꿉니다(`stage/Q468__<V>.o`).
   - compare: 변형마다 다음을 기록합니다.
     - 실행 상태, SHA-256, L1 판정·이유
     - **원본 m68k 외부 함수 19 개** 구간 비교(`m0_m68k_cause.compare_object`, 이름 목록은 기호표의 객체 범위에서 뽑음)
     - 원본에 없는 미정의 기호, COMMON 기호(이름·크기), 지역 텍스트 기호, `canon` 같은 묶음, 대조 R 의 재현 여부
2. 변형(run `m5p468-q1`):
   - 공통 글(N):
     - m68k 블록: 항목 구조체 `struct ns_callout`(필드 이름은 NeXTMach `c_` 꼴), 여섯 공통 기호의 잠정 정의, 바깥 함수 선언, `timer_attributes` 결과 구조체(07 `kern/callout.c` 의 선언 방식).
     - 위 판독대로 작성한 일곱 함수(처리기 이름 `ns_timer_int`, NeXTMach `us_timer_int` 를 따름). ns_timeout 은 T1(임시 변수 `now`), ns_abstimeout 의 delta 는 A1(`now < deadline ? deadline - now : 0`), 처리기 재시도는 H1(`if (p1->c_time < now) goto again;`)입니다.
     - 나눗셈: 컴파일되게 하려고 §455 에서 07 에 넣은 `kern_clock.c` 의 m68k `ns_div_val` 글을 그대로 쓰고, `ns_div` 는 같은 꼴에 `*remain` 출력을 둡니다. 이번 절에서 나눗셈 꼴을 고르지는 않습니다. 네 자리의 결과는 기록만 합니다.
   - 한 곳만 바꾼 변형:
     - `H2`: `if (now > p1->c_time) goto again;`
     - `T2`: x86 꼴 `time += clock_value(System);`(V1 으로 다름이 확인됨, 대조용)
     - `T3`: 중첩 호출 `ns_abstimeout(proc, arg, time + clock_value(System), pri)`
     - `A2`: `deadline > now ? … : 0`
     - `I`: 초기화의 `register int i`(부호 있는 비교가 되어 달라야 하는 음성 대조)
   - 대조 `R` 을 함께 돌립니다.
3. 고르기(미리 정함):
   - 큐 일곱 구간이 모두 원본과 같아야 합니다. 일곱 구간은 `_ns_callout_init`·`_ns_timer_init`·`_ns_hardclock_init`(정적 처리기 포함)·`_ns_timeout`·`_ns_abstimeout`·`_ns_untimeout`·`_ns_sleep` 입니다.
   - 원본에 없는 미정의 기호가 0 이어야 합니다.
   - COMMON 이 정확히 `_hardclock_pc` 4·`_hardclock_ps` 4·`_ns_callfree` 4·`_ns_callout` 4·`_ns_calltodo` 24·`_ns_per_tick` 8 이어야 합니다.
   - 대조 R 이 `P448__V1.o` 를 재현해야 합니다. 재현하지 못하면 멈춥니다.
   - 나머지 12 구간과 L1 객체 판정(NOT_MATCH 예상)은 판정에 넣지 않습니다.
   - 맞는 변형이 `canon` 으로 한 묶음이고 그 안에 꼴이 여럿이면, 바이트로 구별되지 않으므로 사용자에게 묻습니다. 맞는 꼴이 하나면 그대로 채택합니다.
   - 맞는 변형이 없으면 구간별로 진단해 2 차 run 을 같은 기준으로 돌립니다. 두 run 연속 다른 구간 수가 줄지 않으면 멈추고 사용자에게 묻습니다(§446).
4. `ns_sleep` 의 pri:
   - `1` 과 `CALLOUT_PRI_SOFTINT1`(SDK `bsd/sys/callout.h`; NeXTMach `us_timer.c` 도 이 이름을 씀)은 전처리 뒤 같으므로 바이트로 구별되지 않습니다.
   - 매크로 꼴 줄은 Darwin 0.1 `kernel/kern/ns_timer.c` 의 `ns_sleep` 줄과 글자가 같아 D061 고지가 붙습니다. 07 반영 전에 사용자에게 묻습니다.
5. 07 반영(3 의 기준 통과 뒤): m68k 덮어쓰기 `07_kernel/v183.34/m68k/src/kern/ns_timer.c` 를 07 본 파일에 줄을 끼우는 꼴로 만듭니다(`stage_m68k.check_derived`).
   - 파일 머리에 `plan 468 (m68k) begin … end` 묶음을 두고, NeXTMach 고지 줄(`us_timer.c:4`, `machdep.c:2`)과 출처 문장을 넣습니다(`unix_signal.c` 선례). 4 에서 매크로를 고르면 Darwin APSL 고지도 넣습니다.
   - `ns_hardclock_init` 앞에는 m68k 선언·`ns_callout_init`·`ns_timer_init` 을 `#if m68k … #endif` 로 끼웁니다. 원본에서는 이 둘이 `ns_hardclock_init` 보다 앞이고, -O2 는 소스 순서대로 냅니다.
   - 그 뒤에는 처리기와 네 함수를 `#if m68k` 로 두고, 본 파일 60–96 행은 `#else … #endif` 로 남깁니다.
   - `ns_div`·`ns_div_val` 앞에 m68k 판을 `#if m68k … #else` 로 넣고, i386 판 뒤에 `#endif` 를 둡니다.
   - 도구 변경:
     - `stage_m68k.py`: `MARKERS['plan 468 (m68k)']` 를 줄 수와 함께 등록하고 `EXCEPTS[468] = EXCEPTS[467]` 를 둡니다. ns_timer 는 205 개 대조 줄에 없습니다. 이 둘과 `--plan` 문서만 고칩니다.
     - `m5_m68k_pc.py`: `FILES['ns_timer']` 를 더합니다.
     - 고치기 전 사본은 `08_build/artifacts/m5p468/*.before` 에 둡니다.
   - 검사:
     - x86gate(07 본 파일 변경 없음): 일곱 묶음이 그대로여야 합니다.
     - 스테이징 `m0p468-a1-stage` 에서 덮어쓰기 파생 검사를 통과해야 합니다.
     - final run `m5p468-a1`(`m5_m68k_pc.py cmd2/final`, `F468__ns_timer.o`)의 객체가 고른 변형과 비 STABS·Mach-O 머리·절 머리·비 STABS 기호가 같고, 큐 일곱 구간이 원본과 같아야 합니다. 이 검사는 assert 로 강제합니다.
6. 기록:
   - 변형 기록 `09_validation/reconstruction/m5-m68k-ns_timer-queue-variants-20261016.json`, 최종 기록 `m5-m68k-ns_timer-20261016.json`
   - diff `06_reconstruction/evidence/m68k-ns_timer.diff`, PROVENANCE(덮어쓰기 경로 한 행: authored D024 + nextmach 출처 경로:줄), MODIFICATIONS
   - DECISIONS 에 사용자 선택 "(나)" 와 4 의 결정을 적습니다.

### 468.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §468 은 등록 함수를 C 로 `__set_timer_expire_func(0, 처리기)` 라고 적었습니다. 이것은 Mach-O 기호 이름입니다. C 이름은 밑줄을 하나 뺀 `_set_timer_expire_func` 이고, 그대로 두었다면 미정의 `___set_timer_expire_func` 가 생겼을 것입니다. `_set_timer(0, delta)` 는 C 이름으로 맞습니다(Mach-O `__set_timer` 0x40922cc). Mach-O `_set_timer`(0x409228e)는 다른 함수입니다(symbols.tsv 100·2557 행 직접 읽음).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 항목 배치 +4/+8 시각, +0xc arg, +0x10 func, +0x14 pri, 간격 0x18 | §468 작성 때 목록 판독(0x404e3c8–0x404e3d0, 0x404e488–0x404e4b4) | ✅ |
| 초기화는 부호 없는 엄격 비교, `i < ncallout`(ncallout 제외) | 목록 `cmpl d0,d1; bls`·`bhi`; 스테이징 `bsd/sys/callout.h` `extern int ncallout` | ✅ 문구 고침 |
| 등록 인자 `(0, 처리기)`; C 이름은 `_set_timer_expire_func` | symbols.tsv 101 행 `__set_timer_expire_func`; C 이름에 `_` 가 붙는 규칙 | ✅ 위 제 오류 |
| 처리기 둘째 인자 → d7 → `hardclock_pc`, 셋째 → d6 → `hardclock_ps`, ps 먼저 저장 | 목록 0x404e460–0x404e4a6 | ✅ |
| `callout_dispatch(pri, func, arg)`, 떼기 전에 부름 | 목록 0x404e4ac–0x404e4c6 | ✅ |
| 처리 조건은 엄격 `시각 < now`(같으면 처리 안 함), ns_time_t 는 unsigned long long | 목록 `subl d5,d1; subxl d4,d0; bcc`; `kernserv/clock_timer.h` typedef | ✅ |
| 재시도는 `now` 를 다시 읽지 않음 → `again:` 은 `clock_value` 호출 뒤 | `clock_value` 호출은 0x404e46c 하나뿐, `bhi 0x404e478` | ✅ 초안도 그 자리 |
| 최대값 꼬리 공유(0x404e518) | 목록 0x404e508–0x404e522 | ✅ |
| `_ns_timeout`: 호출 → pri 넣기 → 덧셈 | 목록 0x404e556–0x404e568 | ✅ |
| `_ns_abstimeout`: 같은 시각 앞에 끼움, delta 기본 0, panic 문자열 | 목록, python 으로 문자열 읽음 | ✅ |
| `_ns_untimeout` 판독 | 목록 0x404e664–0x404e6cc | ✅ |
| `_ns_sleep` 차이는 pri 1 뿐; 목록 길이 66/68 B | `P448__V1.txt` 59–79 행과 원본 비교 | ⚖️ 사실. 길이 수치는 쓰지 않음 |
| NeXTMach 와 다른 점: 처리기는 재시도 전에 시각을 다시 읽음(`us_timer.c:282`), `us_untimeout` 은 다음 항목 조정(382–383)·FALSE(395) | `us_timer.c` 직접 읽음 | ✅ 문구 보탬 |
| a3 = &ns_calltodo 는 `ns_calltodo.c_next` 꼴로 설명 가능 | 판정은 컴파일이 함 | ⏭️ 실험 |
| 자르기는 `timer_attributes` 를 두 번 부르는 꼴이어야 함(lea + `jsr a2@` 두 번) | 목록 0x404e4f2–0x404e50c | ✅ 초안이 그 꼴 |
| `movew d0,a3` 는 short 변수 증거가 아님 | `spl.h` 매크로가 short 를 돌려줌 | ✅ `int s` 유지 |
| T1 은 마지막 식까지 고정(`time + now` 를 인자에) | 설계 | ✅ |
| §455 나눗셈 꼴 재사용은 컴파일용; kern_clock 에서 맞았다고 여기서 맞는다는 보장 없음 | `kern_clock.c` m68k 덮어쓰기 읽음 | ✅ 기록만 함(§468) |
| 대조 R 은 공통 치환을 거치지 않아야 함 | 설계 | ✅ |
| `compare_object` 는 객체에 없는 이름을 조용히 빠뜨림 | `m0_m68k_cause.py:92`(`n in ext_names` 인 객체 기호만) 읽음 | ✅ 후보는 19 이름 모두 나와야 함(assert) |
| 처리기는 `_ns_hardclock_init` 구간 안에서 비교됨 | `ext_spans`(87–98 행): 다음 외부 기호까지, 정적 함수 포함 | ✅ |
| 가린 구간 비교만으로는 호출 대상·전역·처리기 주소를 못 봄 | `compare_object` 122·133 행(재배치 자리 제외) | ✅ 아래 L1 자리 지정으로 보강 |
| `m5_m68k_pc.py final` 은 x86 외부 이름을 쓰고 PC 모양 비교(135 행 대체 경로)를 부름 → 이 객체에 맞지 않음 | 179–201·128–140 행 읽음 | ✅ `m5_m68k_pc.py` 는 쓰지 않음 |
| `canon` 은 절 바이트·재배치만 봄(머리·기호 정의 없음) | `m3_m68k_diag.py:34-43` 읽음 | ✅ 머리·절 머리·비 STABS 기호 따로 비교 |
| 덮어쓰기는 삽입만, 표시 줄 수 등록, 표시 줄을 빼면 본 파일 | `stage_m68k.py:310-347` 읽음 | ✅ |
| ns_timer 는 205 대조 줄에 없음, plan 468 의 x86 접두는 s6l6 | `X86` 표 269 행, `x86_prefix()` 의 `max(k <= PLAN)` | ✅ |
| COMMON 검사는 후보 검사이지 원본 소유 증명이 아님 | 원본 기호는 링크 뒤 절 정의 | ✅ 문구 그대로(M7) |
| 크기·주소 수치 | §468 작성 때 python 출력과 같음 | ✅ |
| NeXTMach 줄·커밋 | `machdep.c:800`, 961–964 직접 읽음; PROVENANCE 의 기존 nextmach 행 커밋 | ✅ |
| `us_timer.c:1` 의 `(c) 1987 NeXT` 도 고지 | 1 행 직접 읽음 | ✅ 고지에 넣음 |
| Darwin `ns_timer.c:110` 이 매크로 꼴 `ns_sleep` 줄 | 110 행 직접 읽음 | ✅ |
| "이 컴파일러는 중첩 호출을 미리 계산하지 않는다" 는 일반화가 과함 | `microboot` 한 사례만 봄 | ✅ 문구를 "이 자리에서는" 으로 좁힘 |

계획 수정:
- C 이름: `_set_timer_expire_func(0, ns_timer_int)`, `_set_timer(0, delta)`.
- `again:` 은 `now = clock_value(System);` 뒤에 둡니다. NeXTMach 와 다른 점 셋(재시도 때 시각 다시 읽지 않음, 다음 항목 조정 없음, 못 찾으면 `callout_remove`)을 대응 설명에 붙입니다.
- 이 객체의 판정 도구는 `m5_m68k_nsq.py` 하나로 합니다. `m5_m68k_pc.py` 는 고치지 않습니다.
  - `stage`·`cmd`·`compare`(변형)와 `cmdf`(07 덮어쓰기 컴파일, `F468__ns_timer.o`, 같은 cc.cmd 줄)·`final` 을 둡니다.
- 큐 판정에 L1 자리 지정을 더합니다.
  - `l1_compare.py --place __TEXT,__text=0x404e3a8` 를 씁니다. 큐는 객체 앞쪽이라 맞으면 원본과 같은 주소에 놓입니다.
  - 이 L1 은 재배치 대상(바깥 기호, 처리기 주소, 문자열)을 링커처럼 다시 계산합니다. L1 함수 판정에서 `_ns_callout_init`·`_ns_timer_init`·`_ns_hardclock_init`·정적 처리기·`_ns_timeout`·`_ns_abstimeout`·`_ns_untimeout`·`_ns_sleep` 여덟이 모두 `MATCH` 여야 합니다.
  - `MATCH_UNVERIFIED` 는 기준 미달로 보고 진단합니다.
- 후보 기준(§468 의 3 을 대체):
  - 원본 외부 이름 19 개가 객체에 모두 있어야 합니다.
  - 큐 일곱 구간이 같고, 위 L1 여덟 함수가 MATCH 여야 합니다.
  - 원본에 없는 미정의 0, COMMON 이 정확히 여섯(이름·크기), 외부 텍스트 정의가 원본 19 이름과 같은 집합이어야 합니다.
  - 대조 R 은 자기 기대(`P448__V1.o` 와 `canon`·머리·절 머리·비 STABS 기호가 같음)로 따로 판정합니다.
- `final`(assert):
  - 덮어쓰기 객체가 고른 변형과 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같아야 합니다.
  - 위 후보 기준을 모두 만족해야 합니다.
  - 덮어쓰기 파생 검사는 `stage_m68k.py --plan 468 stage` 가 이미 assert 합니다.
- 고지: 덮어쓰기 머리에 NeXTMach `us_timer.c:1`(`(c) 1987 NeXT`)·`:4`, `machdep.c:2` 의 고지를 넣습니다. PROVENANCE 에는 함수·식별자별 대응(경로:줄)을 적습니다.

### 468.2 변형 시험 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-ns_timer-queue-variants-20261016.json`(1 차)·`m5-m68k-ns_timer-queue-variants2-20261016.json`(2 차)

새 도구 `10_tools/reconstruction/m5_m68k_nsq.py` 로 시험했습니다(§468.1 기준).
- 실행 전 기준 바로잡음(후보 결과를 보기 전입니다):
  - §448 객체 `P448__V1.o` 로 도구를 미리 돌려 보니 COMMON 에 `_master_cpu`(4 B)가 있었습니다.
  - 출처는 `kern/cpu_number.h:61` 의 잠정 정의(plan 400)이고, §441·§467 객체 207 개 가운데 97 개에 있습니다. 원본에서도 공통 기호(0x40b59d4)입니다.
  - 그래서 기대 COMMON 을 "여섯 + `_master_cpu` 4" 로 바로잡았습니다.
- 1 차 run `m5p468-q1`(명령 7 개 모두 종료 0; 스테이징 `m0p468-q-stage`, 명세 `08_build/artifacts/m5p468/spec.json`):
  - 대조 R 은 `P448__V1.o` 와 같습니다.
  - 기준을 통과한 변형은 없습니다.
  - `canon` 묶음은 {A2, N, T2}, {H2}, {I}, {T3}, {R} 입니다.
  - N 은 `_ns_hardclock_init`(처리기)·`_ns_abstimeout` 두 구간이 달랐습니다. H2 는 처리기가 맞고 `_ns_abstimeout` 하나만 달랐습니다.
  - I(부호 있는 i)는 `_ns_callout_init` 이 달라 음성 대조로 작동했습니다. T3(중첩 호출)은 `_ns_timeout` 이 다릅니다.
  - 제 오류: §468 은 T2(x86 꼴 `time += clock_value(System);`)를 "V1 으로 다름이 확인됨" 이라 적었는데, T2 는 N 과 바이트가 같았습니다. V1 은 부르는 함수와 인자 수가 달라 비교가 되지 않는 경우였습니다.
- H2 의 `_ns_abstimeout` 차이(otool `08_build/artifacts/m5p468/otool/Q468__H2.txt` 와 원본 목록 비교):
  - 차이는 한 곳입니다. `clock_value` 호출 뒤 스택 정리 `addqw #0x4,sp` 가 원본은 `moveq #0,d2; moveq #0,d3` **뒤**이고, 우리 객체는 **앞**입니다.
  - 그래서 `delta = 0;` 을 따로 둔 문장 뒤에 `if` 를 두는 꼴을 2 차에서 시험했습니다.
  - 다른 구간 수가 2(N) → 1(H2)로 줄어 §446 멈춤 조건에 해당하지 않습니다.
- 2 차 run `m5p468-q2`(명령 4 개 모두 종료 0; 스테이징 `m0p468-q2-stage`, 명세 `spec2.json`):
  - H2 는 1 차 H2 와 `canon` 이 같습니다(재현).
  - **HA3**(`delta = 0; if (now < deadline) delta = deadline - now;`)와 **HA4**(`… if (deadline > now) …`)가 기준을 모두 통과했습니다.
    - 원본 외부 이름 19 개가 모두 있습니다.
    - 큐 일곱 구간이 같고, `--place __TEXT,__text=0x404e3a8` L1 에서 큐 여덟 함수(정적 `_ns_timer_int` 포함)가 모두 MATCH 입니다.
    - 미정의 0, COMMON 은 기대와 같고, 외부 텍스트 정의는 19 이름입니다.
  - HA3·HA4 는 `canon` 이 같습니다.
- 범위 밖 함수의 결과(기록만):
  - 자리 지정 L1 에서 `_ns_time_to_timeval`·`_timeval_to_ns_time`·`_ns_time_to_tsval`·`_ticks_to_ns_time` 은 MATCH 입니다(나눗셈 두 자리는 §455 꼴로 맞음).
  - `_sched_usec_elapsed` 는 구간이 다릅니다. 그 뒤 함수들은 주소가 밀려 L1 판정을 쓸 수 없습니다.
  - 구간 비교로는 `_get_calendar_time_value`·`_set_calendar_time_value` 가 같고, `_sched_usec_elapsed`·`_microtime`·`_microboot`·`_us_timeout`·`_us_abstimeout`·`_us_untimeout` 이 다릅니다.
- 바이트로 구별되지 않는 꼴이 셋이라 사용자에게 묻습니다.
  - `ns_timeout`: T1(임시 변수 `now`, `time + now`)과 T2(07 본 파일의 `time += clock_value(System);`)입니다.
  - `ns_abstimeout` 비교: HA3 `now < deadline` 과 HA4 `deadline > now` 입니다.
  - `ns_sleep` pri: `1` 과 `CALLOUT_PRI_SOFTINT1` 입니다. 매크로 꼴은 Darwin `kern/ns_timer.c:110` 과 같은 줄이라 D061 고지가 붙습니다.

### 468.3 결정과 구현(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-ns_timer-20261016.json`

- 사용자 결정은 D086(순서 "(나)")과 D087(바이트로 구별되지 않는 꼴 셋: T2, HA3, 매크로 + Darwin 고지)입니다.
- 07 m68k 덮어쓰기 `07_kernel/v183.34/m68k/src/kern/ns_timer.c` 를 새로 만들었습니다.
  - 488 행이고, 본 파일 236 행에 `plan 468 (m68k)` 표시 줄 252 개를 끼운 꼴입니다(python).
  - 07 본 파일 `kern/ns_timer.c` 는 바꾸지 않았습니다.
- 도구:
  - 새로 만듦: `m5_m68k_nsq.py`
  - 고침: `stage_m68k.py`(`MARKERS['plan 468 (m68k)']` 252, `EXCEPTS[468] = EXCEPTS[467]`, `--plan` 문서). 고치기 전 사본은 `08_build/artifacts/m5p468/stage_m68k.py.before` 입니다.
  - `m5_m68k_pc.py` 는 고치지 않았습니다(§468.1).
- 검사:
  - 스테이징 `m0p468-a1-stage` 는 덮어쓰기 파생 검사를 통과했고, 스테이징 파일이 덮어쓰기와 같습니다(`cmp`).
  - x86gate(`08_build/artifacts/m5p468/x86gate/x86gate.json`): s6l6 일곱 묶음 모두 manifest 가 같고, v183.34 경로는 0 입니다.
  - final run `m5p468-a1`(명령 1 개, 종료 0)의 `F468__ns_timer.o` 는 `m5_m68k_nsq.py final` 의 assert 를 통과했습니다.
    - 고른 변형 `Q468__HA3.o` 와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같습니다. 07 의 T2 꼴이 HA3 의 T1 꼴과 같은 객체임도 여기서 확인됩니다.
    - 큐 일곱 구간이 같고, 자리 지정 L1 에서 큐 여덟 함수가 MATCH 입니다.
    - 미정의 0, COMMON 은 기대와 같습니다.
- 남은 차이(다음 절): `_sched_usec_elapsed`(나눗셈 자리)·`_microtime`·`_microboot`·`_us_timeout`·`_us_abstimeout`·`_us_untimeout` 구간입니다. 객체 L1 은 NOT_MATCH 입니다.
- 집계:
  - 이름 대응 공통부 C 208 개가 이제 모두 m68k 로 컴파일됩니다(§448 의 마지막 하나).
  - 코드 차이가 남은 객체는 19 개 + `ns_timer`(이제 컴파일됨, 여섯 구간 차이)입니다.
- 기록:
  - diff `06_reconstruction/evidence/m68k-ns_timer.diff`
  - PROVENANCE 1095 행(새 경로 한 행, 중복 0), MODIFICATIONS 624 행, DECISIONS D086·D087
  - 변형 기록 둘(§468.2), 최종 기록

## 469. M5-26 세부 계획 — m68k `ns_timer` 남은 여섯 함수: `sched_usec_elapsed`(나눗셈)·`microtime`·`microboot`·`us_timeout`·`us_abstimeout`·`us_untimeout`(코딩 전, 2026-10-16)

확인한 사실(§468 final 객체 `F468__ns_timer.o` 의 otool 목록 `08_build/artifacts/m5p468/otool/F468__ns_timer.txt` 와 원본 목록을 함수별로 비교, 크기는 python):
- `_sched_usec_elapsed`(원본 130 B, 우리 126 B): 차이는 둘째 나눗셈의 레지스터뿐입니다.
  - 원본: `clrl d0; … divull #0x3e8:l,d0,d2; movel d2,a6@(0xfff4:w); movel d0,d1; movel a6@(0xfff8:w),d3; divul #0x3e8:l,d1,d3; movel d3,d0` 뒤에 `last` 저장을 합니다.
  - 우리: 나머지가 d1 이고 `divul #0x3e8:l,d1,d0` 로 몫을 바로 d0 에 둡니다.
  - 원본은 첫 나눗셈의 나머지(d0)를 **다른 레지스터(d1)로 옮겨** 둘째 나눗셈에 넣고, 몫(d3)을 d0 으로 옮깁니다. 두 나눗셈의 나머지가 **서로 다른 변수(의사 레지스터)** 인 꼴로 보입니다.
  - 원본 `_hardclock`(§455 에서 맞은 kern_clock 꼴)은 두 나눗셈에서 나머지 d2 를 그대로 이어 씁니다(이미지 목록 3346·3349 행). 그래서 ns_timer.c 의 `ns_div_val` 은 kern_clock.c 의 것과 다른 글이었다고 봅니다(가설).
  - `ns_div_val` 을 쓰는 곳은 `sched_usec_elapsed` 하나이고, 덮어쓰기의 `#if m68k` 묶음 안에 있습니다.
- `_microtime`(116 B): 첫 비교(`last_time > now`)의 빼기 방향만 다릅니다.
  - 원본은 `now - last_time` 에 `bcc` 이고, 우리는 `last_time - now` 에 `bls` 이며 레지스터 복사가 두 개 더 있습니다.
  - 둘째 비교(`last_time - now < NSEC_PER_SEC`, 상수 0x3b9ac9ff)는 같습니다.
- `_microboot`(원본 40 B, 우리 34 B):
  - 원본은 `tvp` 를 d2 에 먼저 넣고 `clock_value(System)` 을 부른 **뒤** d2 를 넣습니다.
  - 우리는 `tvp` 를 먼저 넣고 부릅니다(중첩 호출을 그 자리에서 계산).
  - 임시 변수 꼴(`now = clock_value(System); ns_time_to_timeval(now, tvp);`)로 보입니다.
- `_us_timeout`·`_us_abstimeout`(각 56 B): 원본은 proc·arg·pri 를 d4·d3·d2 에 넣고 `timeval_to_ns_time(tvp)` 를 **먼저** 부른 뒤 pri·시각·arg·proc 를 넣습니다. 우리는 pri 를 먼저 넣습니다. 임시 변수 꼴로 보입니다.
- `_us_untimeout`(22 B): 명령은 원본과 같습니다.
  - 구간 비교가 다른 까닭은 원본에서 다음 기호 `_power_callout` 이 0x404eb90 이라 이미지 쪽 구간이 248 B 이기 때문입니다. 원본 객체는 0x404eaae 에서 끝나고, 그 자리에서 다음 객체의 이름 없는 함수(`linkw a6,#0xfffc`)가 시작합니다(python).
  - 이 함수는 객체 전체 L1 로 판정합니다.
- 정적 변수: `microtime` 의 `last_time = 0` 은 `__data`(원본 0x40af93c), `sched_usec_elapsed` 의 `last` 는 `__bss`(원본 0x40b39ba)입니다. 우리 객체에도 `__data` 8 B·`__bss` 8 B 가 있습니다.
- `microtime`·`microboot`·`us_*` 의 본문은 x86 과 같이 쓰는 글입니다(07 본 파일, 덮어쓰기 `#if m68k` 밖). x86 원본은 지금 글로 맞습니다(-O3).

방법:
1. 변형 시험은 `m5_m68k_srcvar.py` 로 합니다.
   - 도구를 조금 넓힙니다. 명세 선택 키 `source` 를 두어 변형의 바탕 글을 07 본 파일 대신 m68k 덮어쓰기 파일로 하고, 기록에 그 경로·SHA-256 을 남깁니다. 키가 없으면 지금과 같습니다.
   - 명세 `08_build/artifacts/m5p469/spec.json`: source 는 `07_kernel/v183.34/m68k/src/kern/ns_timer.c`, 바탕 스테이징은 `m0p468-a1-stage` 입니다.
   - 대조 K 는 덮어쓰기 그대로이고, `control_ref` 는 `08_build/runs/m5p468-a1/out/F468__ns_timer.o` 입니다.
   - 스테이징 `m0p469-v-stage`, run `m5p469-v1` 입니다.
2. 변형(한 곳씩):
   - `MT`: `if (now < last_time && last_time - now < NSEC_PER_SEC)`
   - `MB`: `microboot` 를 `ns_time_t now; now = clock_value(System); ns_time_to_timeval(now, tvp);` 로 씁니다. `MBI` 는 선언 초기화 꼴 `ns_time_t now = clock_value(System);` 입니다(07 `get_calendar_time_value` 의 꼴).
   - `UT`: `us_timeout`·`us_abstimeout` 둘 다 `ns_time_t time; time = timeval_to_ns_time(tvp);` 뒤에 부릅니다. `UTI` 는 선언 초기화 꼴입니다.
   - 나눗셈(덮어쓰기의 m68k `ns_div_val` 만):
     - `D1`: 둘째 asm 의 나머지 출력을 새 변수 `junk` 로 합니다.
     - `D2`: x86 꼴처럼 둘째 asm 의 출력을 몫 하나로 하고 나머지는 입력 `"d" (rem)` 로만 둡니다.
     - `D3`: 선언 순서 `unsigned int rem, quo;`
     - `D4`: 둘째 asm 의 몫 출력을 새 변수로 하고 그것을 돌려줍니다.
     - `D6`: `ns_div` 를 불러 쓰는 꼴(`ns_div(&ll, divisor, &junk); return (((unsigned int *)&ll)[1]);`). 저장이 생겨 달라질 것으로 보는 대조입니다.
   - `ALL` 은 넣지 않습니다. 합친 꼴은 결정 뒤 final 에서 봅니다.
3. x86 확인(07 본 파일에 둘 수 있는지): `m5_x86_srcvar.py` 로 같은 명세의 변형을 x86 로 컴파일합니다.
   - 바탕은 `s6l5-g1a-stage` 입니다. ns_timer.c 본 파일은 s6l5·s6l6 사이에 바뀌지 않았습니다.
   - 스테이징 `m0p469-xv-stage`, run `m5p469-xv1` 입니다. 대조 K(덮어쓰기 글을 x86 로 컴파일)는 s6l5 객체와 같아야 합니다. 덮어쓰기의 x86 길이 본 파일과 같다는 확인도 됩니다.
4. 고르기(미리 정함):
   - 함수마다 해당 구간(`m0_m68k_cause.compare_object`, 재배치 자리 가림)이 원본과 같아야 합니다. MT 는 `_microtime`, MB·MBI 는 `_microboot`, UT·UTI 는 `_us_timeout`·`_us_abstimeout`, D* 는 `_sched_usec_elapsed` 입니다.
   - 대조 K 와 비교해 원본에 없는 미정의 0, COMMON·외부 정의 같음, 다른 구간은 K 와 같음이어야 합니다.
   - 대조 K 가 `F468__ns_timer.o` 를 재현하지 못하면 멈춥니다.
   - 같은 함수에 맞는 꼴이 여럿이고 `canon` 으로 구별되지 않으면 사용자에게 묻습니다. 공유 본문의 자리(07 본 파일: x86 같음이 확인된 것만 / m68k 덮어쓰기)도 사용자에게 묻습니다.
   - D* 가 하나도 맞지 않으면 진단을 기록하고 2 차를 같은 기준으로 돌립니다. 두 run 연속 줄지 않으면 멈추고 묻습니다(§446).
5. 결정 뒤 구현과 최종 검사:
   - 덮어쓰기와(또는) 07 본 파일을 고칩니다. 본 파일이면 §467 절차를 따릅니다(x86 전체 재빌드 s6l7, prefixdiff, 링크 `cmp`, m68k 바탕 갱신).
   - final run 의 객체가 다음을 만족해야 합니다(assert).
     - L1(`--place-from-image`)의 이유가 정확히 `['__DATA,__bss: unverified']` 입니다(텍스트·`__cstring`·`__data` 통과).
     - 원본에 없는 미정의 0, COMMON 은 §468 과 같습니다.
     - `zerofill_check.py` 결론이 reference-inferred(-single)이고 문제는 없습니다.
     - bss 후보는 §464 기록 후보와 겹치지 않아야 합니다(`m5_m68k_zerofill.py objs`). §467 nfs 후보 [0x40b352c, 0x40b3564)와도 python 으로 겹침을 봅니다.
   - 그러면 ns_timer 는 "코드 검증 + bss 추정" 등급이 됩니다.
6. 기록: 변형 기록 `09_validation/reconstruction/m5-m68k-ns_timer-tail-variants-20261016.json`, x86 기록 `m5-x86-ns_timer-tail-variants-20261016.json`, 최종 기록, diff·PROVENANCE(같은 행 그 자리 갱신)·MODIFICATIONS·DECISIONS 입니다.

### 469.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- §469 는 `_sched_usec_elapsed` 의 차이를 "둘째 나눗셈의 레지스터뿐" 이라 적었습니다. 그런데 첫 나눗셈도 다릅니다. 원본은 `clrl d0; … divull #0x3e8:l,d0,d2` 이고, 우리는 `clrl d1; … divull #0x3e8:l,d1,d2` 입니다.
- 우리 객체의 크기도 적지 않았습니다. F468 은 `_sched_usec_elapsed` 126·`_microtime` 120·`_microboot` 34·`_us_timeout` 58·`_us_abstimeout` 58·`_us_untimeout` 22 B 이고, 원본은 130·116·40·56·56·22 B 입니다(python, 객체 기호 사이 거리). 텍스트는 1796 B 이고, 원본 객체 구간은 1798 B 입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| F468 크기 126·120·34·58·58·22, 원본 130·116·40·56·56·22 | python(F468 기호 거리, §469 원본 거리) | ✅ 위 제 오류 |
| 첫 나눗셈도 다름(d0 vs d1) | otool 목록 나란히 비교(§469 작성 때 diff 출력) | ✅ |
| `microtime`: 원본은 `now - last_time`·`bcc`, 우리는 복사 둘 뒤 `last_time - now`·`bls`; 둘째 비교는 같음 | 같은 diff 출력 | ✅ |
| `microboot`: 원본은 d2 저장·복원, `addqw` 없음 | 같은 diff 출력 | ✅ |
| `us_timeout`·`us_abstimeout`: 원본은 `moveml d2/d3/d4` 셋 저장, `addqw` 없음 | 같은 diff 출력 | ✅ |
| `us_untimeout` 구간: 이미지 구간 248 B, 다음 기호 `_power_callout` 0x404eb90 | `compare_object` 출력(object_span 22, image_extent 248), symbols.tsv 2252 행 | ✅ |
| "두 나머지가 다른 변수" 는 가설(한 asm 안의 맞춤 제약은 asm 사이 레지스터 동일성을 정하지 않음) | gcc 동작 설명; 실험이 판정 | ✅ 문구를 가설로 |
| hardclock 관찰은 사실이나 "다른 helper 글" 의 증명은 아님 | 이미지 3346·3349 행 | ✅ 가설로 |
| D1(둘째 나머지 출력을 새 변수)이 가장 직접적; D1+D4 와 출력 순서 바꾸기도 후보 | 판단; 실험이 판정 | ✅ D14·D5 추가 |
| D2 는 템플릿 번호를 다시 매겨야 함(`divul %1,%2:%0`, 입력 `"dmi"(divisor), "d"(rem), "0"(*lsw)`) | 연산자 번호 직접 셈 | ✅ |
| D6 는 저장이 생길 것(`_ns_time_to_tsval` 의 `ns_div` 펼침에 저장 있음) | F468 목록 | ⏭️ 대조로 둠 |
| MT·MB·UT 는 근거가 강함 | 판단; 실험이 판정 | ⏭️ |
| `source` 키는 지금 도구에 없음(`variant_text` 가 07 본 파일만 읽음) → 기본값을 두고 넣고, 기록에 경로·SHA 를 더함; x86 도구 기록에도 | `m5_m68k_srcvar.py:53-54` 읽음 | ✅ |
| `cc_line` 은 ns_timer 줄 하나(cc.cmd) | 실행: `SV.cc_line({'rel':'kern/ns_timer.c'})` | ✅ |
| 일반 비교의 외부 이름은 x86 17 개라 `_ns_callout_init`·`_ns_timer_init` 이 빠짐 | §468 `check` 출력(spans_missing 2) | ✅ 원본 19 이름 사용 |
| "다른 구간은 K 와 같음" 은 지금 도구에 없음(원본과의 참거짓만 기록) → 재배치를 푼 K 대비 함수 비교 필요 | `m5_m68k_srcvar.py:150-158` 읽음 | ✅ 새 비교 작성 |
| 일반 대조 관문은 `canon` 만 보고 assert 하지 않음 | 167–168 행 | ✅ 강한 관문(assert) |
| 시험 중 L1 은 자리를 못 잡아 쓸모없음(F468 `placements` 모두 None, 함수 0) | `l1-F468.json` 읽음(python) | ✅ 시험 판정에 쓰지 않음 |
| x86 stage 의 assert 는 본 파일끼리 비교라 덮어쓰기 바탕과 충돌 없음; s6l5·s6l6 본 파일·객체 같음 | 세 SHA-256 앞 16 자리 같음(3eaee9a59d88e53e), 두 객체 `canon`·머리·절·기호 같음(python) | ✅ |
| 바꿀 글의 고정점은 겹치지 않게(덮어쓰기에 `unsigned int\tquo, rem;` 4 번) | python count 4 | ✅ m68k `ns_div_val` 묶음 전체로 치환 |
| 원본 텍스트 1798 B 이므로 최종 텍스트도 1798 이어야 함 | python | ✅ |
| 최종 "bss 만 unverified" 는 가능함(L1 의 zerofill 처리) | `l1_compare.py` 구조(§467 선례) | ⏭️ final 이 판정 |
| 원본 0x40af93c 의 8 B 는 0(우리 `__data` 와 같음) | python 으로 읽음 | ✅ |
| `objs` 는 REF 와 같아야 함 → 합친 후보 객체가 필요 | `m5_m68k_zerofill.py:137-146` | ✅ 합친 run 추가 |
| bss 예상 [0x40b39ba, 0x40b39c2) 는 §464 후보·§467 nfs 와 겹치지 않음 | python 겹침 [] | ✅ |
| final 컴파일 경로가 계획에 없음 | `m5_m68k_pc.py` FILES 에 ns_timer 없음, `m5_m68k_nsq.py cmdf` 는 plan 468 고정 | ✅ 새 도구에 `cmdf` |

계획 수정:
- 도구:
  - `m5_m68k_srcvar.py`: 명세 선택 키 `source` 를 받게 합니다(없으면 07 본 파일). 쓰는 경로·SHA-256 을 기록하고, 다른 동작은 바꾸지 않습니다.
  - `m5_x86_srcvar.py`: 기록에 `source`·`source_sha256` 을 더합니다.
  - 새 도구 `m5_m68k_nst.py`(plan 469) 를 만듭니다. 스테이징·명령은 `m5_m68k_srcvar.py` 의 `stage`/`cmd` 를 그대로 씁니다. `compare`·`cmdf`·`final` 을 둡니다.
    - 모든 명령이 종료 0 이고 객체가 다 있어야 합니다(assert).
    - 대조 K 가 `F468__ns_timer.o` 와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 모두 같아야 합니다(assert).
    - 원본 19 이름의 구간 비교를 합니다.
    - **함수별 K 대비 비교**: 객체 텍스트 기호(정적 포함)마다 재배치 자리를 0 으로 가린 바이트와 재배치 목록을 비교합니다. 재배치 목록은 함수 안 위치, 폭, pc 상대 여부, extern 여부, 형식, scattered 여부, 대상입니다. 대상은 extern 이면 기호 이름, 지역이면 대상 주소를 "그 주소를 담은 기호 + 차이" 또는 "절 + 차이" 로 풀어 적습니다.
    - 도구 자체 시험: K 대 K, K 대 F468 은 모든 함수가 같아야 합니다. K 의 pc 상대 지역 `bsr` 대상은 모두 기호 시작이어야 합니다.
    - 원본에 없는 미정의, COMMON·외부 텍스트 정의가 K 와 같은지 봅니다.
  - 명세에 `targets`(변형마다 바뀌어도 되는 함수 이름)를 둡니다. 통과 조건은 targets 구간이 원본과 같고, targets 밖 모든 함수가 K 와 같고, 기호 조건을 만족하는 것입니다.
- 변형 보탬:
  - `D14` = D1 + D4
  - `D5` = 둘째 asm 의 출력 순서를 몫 먼저로 하고 템플릿·맞춤 제약 번호를 맞춤
  - D* 는 덮어쓰기의 m68k `ns_div_val` 묶음 전체를 바꿉니다.
- 합친 꼴: 사용자 결정 뒤 run 2 에서 `ALL`(고른 꼴을 모두 합침)을 같은 도구로 시험합니다. 19 구간(`_us_untimeout` 은 도구 한계라 제외)이 같아야 하고, L1(`--place-from-image`) 이유가 정확히 `['__DATA,__bss: unverified']` 여야 합니다. 이 객체를 final 의 REF 로 씁니다.
- final: 07 반영 뒤 `cmdf` 로 `F469__ns_timer.o` 를 만듭니다. 다음은 `final` 의 assert 로 강제합니다.
  - `ALL` 과 서명이 같음
  - L1 이유가 bss 하나
  - `m5_m68k_zerofill.py objs`(REF=ALL)를 통과함
  - §467 nfs 후보와 겹침 0
- 문구: "다른 변수" 와 "다른 helper 글" 은 가설로 고쳐 적습니다(이 절이 대신함).

### 469.2 함수별 K 대비 비교 설계의 2 차 교차검토(codex `gpt-6.1-sol`) 판정

제 오류(먼저 밝힘): §469.1 의 설계는 extern 재배치의 대상을 "기호 이름" 만으로 적었습니다. 그러면 가산값이 달라져도(예: 0x48c `_ns_per_tick` + 4 → + 0) 같다고 나옵니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| pc 상대 지역: 대상 = P + signed(F)(P = 절 주소 + r_address), 더할 값 없음; 0x64a → 0x36a | python: F −736, F+P 0x36a; 0x6fc → 0x2bc `_ns_untimeout` 도 직접 계산 | ✅ |
| 절대 지역: 필드 = 대상 VM 주소(가산값 포함); 0x60 → 0xb0(정적 처리기) | python: F 0xb0 | ✅ |
| scattered: `r_value` 는 기준, 가산값 = F − V(0x604: 0x722 / 0x726 → 4) | python | ✅ (기준, 가산값) 으로 적음 |
| extern 은 (이름, 가산값)으로 적어야 함(0x48c `_ns_per_tick` F = 4) | python | ✅ 위 제 오류 |
| 재배치는 67 개 모두 VANILLA, 폭 4(지역 8·9, extern 27·17, scattered 6) | python Counter 출력 | ✅ 다른 형식·폭은 거부(assert) |
| 파서 필드(address, symbolnum, value, length, pcrel, extern, scattered, type); scattered 에는 extern·symbolnum 없음 | 재배치 dict 키 출력 | ✅ |
| 같은 주소 기호 묶기, 양방향 기호 집합 비교, 필드가 구간 경계를 넘으면 거부, R_ABS·절 밖 대상 거부 | 설계 | ✅ assert 로 넣음 |
| 텍스트 밖(문자열·데이터 바이트, 절 속성, bss 크기, 기호 목록)도 비교해야 "목표 함수만 바뀜" 을 말할 수 있음 | 설계 | ✅ 넣음 |
| 정적 변수 기호 `_last.46`·`_last_time.53` 이 데이터 절에 있음 | python 기호 목록 | ✅ 변형 대 K 비교에서는 `.숫자` 꼬리를 떼고 비교(꼬리는 컴파일러 번호). final 대 ALL 은 그대로 |
| 원본 정적 처리기는 기호가 없어 `_ns_hardclock_init` 구간 안; 우리 객체는 따로 | §468 | ✅ K 비교는 객체 기호, 원본 비교는 기존 구간 |
| 명시 자리 L1 은 이동 뒤 함수에 쓸 수 없음 | 판단(§469.1) | ✅ |
| 음성 자체 시험(가산값을 메모리에서 바꾸면 달라야 함) 필요 | 설계 | ✅ 도구 `selftest` 로 넣음 |

### 469.3 변형 시험 결과와 사용자 결정(2026-10-16)

- m68k 1 차 run `m5p469-v1`(명령 13 개 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-ns_timer-tail-variants-20261016.json`):
  - 도구 자체 시험(`m5_m68k_nst.py selftest`)을 먼저 했습니다. F468 에서 재배치 다섯 종류의 가산값이나 평범한 바이트 하나를 메모리에서 바꾸면 서명이 모두 달라졌고, K 의 pc 상대 지역 대상은 모두 기호 시작이었습니다. 같은 코드인 F468·HA3 는 서명이 같았고, H2 는 실제 차이인 `_ns_abstimeout` 하나만 다르게 나왔습니다.
  - 대조 K 는 F468 과 서명이 모두 같습니다.
  - 통과한 꼴은 다음과 같습니다. 목표 함수만 K 와 다르고 목표 구간은 원본과 같으며, 비텍스트·기호가 K 와 같고 미정의는 0 입니다.
    - `sched_usec_elapsed`: **D1·D14**(`canon` 같음). 둘째 asm 의 나머지 출력을 새 변수로 둔 꼴입니다. 가설이 맞는 쪽으로 나왔습니다.
    - `microtime`: **MT** 하나입니다.
    - `microboot`: **MB·MBI**(같음)입니다.
    - `us_timeout`·`us_abstimeout`: **UT·UTI**(같음)입니다.
  - D3·D4·D5 는 K 와 같았고, D2·D6 은 목표 구간이 다릅니다.
- x86 run `m5p469-xv1`(`m5_x86_srcvar.py`, 바탕 s6l5, 명령 13 개 모두 종료 0; 기록 `m5-x86-ns_timer-tail-variants-20261016.json`):
  - 13 변형 모두 s6l5 객체와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같습니다.
  - 대조 K(덮어쓰기 글을 x86 로 컴파일)도 같습니다.
- 합친 꼴 run `m5p469-v2`(D1+MT+MB+UT; 명세 `spec2.json`; 기록 `m5-m68k-ns_timer-tail-all-20261016.json`):
  - 결정 전에 미리 확인했습니다(순서만 앞당김, 기준은 같음).
  - 목표 다섯 구간이 원본과 같고, 다른 함수는 K 와 같습니다.
  - L1(`--place-from-image`, `08_build/artifacts/m5p469/l1-m5p469-v2-ALL.json`)의 이유는 `['__DATA,__bss: unverified']` 하나이고, 텍스트 1798 B 가 원본 객체 자리에 놓였습니다.
- 사용자 결정 **D088**(바이트로 구별되지 않음):
  - 나눗셈은 "D14 junk + val" 입니다.
  - 임시 변수는 "따로 대입하는 꼴"(MB·UT)입니다.
  - `microtime`·`microboot`·`us_timeout`·`us_abstimeout` 의 자리는 "07 본 파일" 입니다. 나눗셈은 m68k 전용이라 덮어쓰기에 둡니다.

### 469.4 D088 구현 계획(07 본 파일 + 덮어쓰기 + x86 전체 재빌드 s6l7 + m68k 바탕 갱신; 코딩 전, 2026-10-16)

§467.3 절차(§466.4 판정과 D083 RID 정규화 기준 포함)를 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. **고른 꼴 그대로의 기준 객체**
   - 07 을 고치기 전에 명세 `spec3.json`(K 와 `CHOSEN` = D14 + MT + MB + UT)을 run `m5p469-v3` 로 컴파일합니다.
   - `m5_m68k_nst.py compare` 를 통과해야 하고, L1 이유는 bss 하나여야 합니다. 이 `P469__CHOSEN.o` 를 final 의 REF 로 씁니다.
   - D1 로 만든 ALL 객체는 정적 기호 꼬리 번호 같은 것이 다를 수 있어 REF 로 쓰지 않습니다.
1. **07 편집**
   - 본 파일 `kern/ns_timer.c` 에 MT·MB·UT 와 같은 코드를 넣고, 줄 끝에 `/* plan 469 (D088): … */` 주석을 붙입니다.
   - 덮어쓰기 `v183.34/m68k/src/kern/ns_timer.c` 에는 같은 본 파일 줄을 넣고(표시 없는 줄), plan 468 묶음 안의 m68k `ns_div_val` 을 D14 로 바꿉니다.
     - 묶음 시작 줄 설명에 "plan 469, D088" 을 적되, 새 표시 키(`plan 469 (m68k)`)는 만들지 않습니다. 묶음 줄 수가 같으므로 표시 줄 수 252 를 유지합니다.
   - python 으로 확인합니다. 두 파일에서 `plan 469` 주석을 빼면, 본 파일은 덮어쓰기에서 표시 줄을 뺀 것과 같아야 합니다(파생 검사). 덮어쓰기는 `spec3` 의 `CHOSEN` 글과 같아야 합니다.
2. **x86 전체 재빌드** s6l7(일곱 묶음 g1a·g2aa·g2ba·g3a·g4a·g5a·g6a, `L2_FORMS=06_reconstruction/l2_build_forms-s6p398.tsv`, `L2_EXPECT=06_reconstruction/l2_expect-s6p398.json`; prepare·check 모두에 줌).
   - 통과 조건: check 기록 일곱에서 problem 0, 모든 행 same_as_baseline 또는 expected_ok, deps 경고 0, 행 1–402 연속, 모든 명령 종료 0(python 집계).
3. **s6l6↔s6l7** `l2_prefix_diff.py s6l6 s6l7 RECORD 469`:
   - 스테이징 차이는 `src/kern/ns_timer.c` 하나여야 하고, `stage_keys_differ`·`cmd_differ` 는 비어 있어야 합니다.
   - `sha_differ_not_rid_only` 는 `x86-ns_timer` 하나이고, 비 STABS 가 같아야 합니다.
4. **링크** `l2_link.py prepare s6p469-ln1 s6l7` → kr_run → `l2_compare.py` → `cmp` 로 원본과 같아야 합니다.
5. **m68k**:
   - `stage_m68k.py`: `X86[469] = 's6l7'`, `EXCEPTS[469] = dict(EXCEPTS[468])`, `--plan` 문서를 고칩니다.
   - `--plan 469 stage m0p469-a1-stage` → x86gate(s6l7 일곱) → `m0p468-a1-stage` 와의 파일 차이는 `src/kern/ns_timer.c` 하나여야 합니다.
   - `m5_m68k_nst.py cmdf` → run `m5p469-a1` → `final m5p469-a1 P469__CHOSEN.o` 의 assert 를 통과해야 합니다. 조건은 REF 와 서명 같음, L1 이유가 bss 하나, 미정의 0, zerofill objs 통과, §467 nfs 와 겹침 0 입니다.
6. **기록**:
   - PROVENANCE 두 행(07 본 파일 594 행·덮어쓰기 행)을 그 자리에서 갱신하고, MODIFICATIONS 에 두 행을 덧붙입니다.
   - diff `06_reconstruction/evidence/x86-ns_timer-plan469.diff` 를 새로 만들고 `m68k-ns_timer.diff` 를 다시 만듭니다. `x86-ns_timer.md` 에 plan 469 문단을 덧붙입니다.
   - DECISIONS D088 과 검증 기록(s6l7 일곱, prefixdiff, link, final, zerofill)을 남깁니다.
   - 집계: ns_timer 가 "코드 검증 + bss 추정" 이 되어 그 등급은 19 개가 되고, 코드 차이가 남은 객체는 19 개(ns_timer 제외)입니다.

### 469.5 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 같은 줄(주석 포함)을 덮어쓰기에 넣고 plan 468 묶음 안을 같은 줄 수로 바꾸면 파생 검사 통과; `plan 469` 글은 표시 키와 겹치지 않음 | 표시 키 목록(`stage_m68k.py` MARKERS)에 `plan 469` 없음; 구현 뒤 실제 `stage` 가 판정 | ✅ 주석까지 같은 줄로 복사 |
| ns_timer 는 forms 338 행(TSV 339 행)·G1, L2_EXPECT 대상 아님 → 기준선 구조 비교 | TSV 339 행 읽음, expect 에 338 없음(python), s6l6 G1 기록의 338 행 `same_as_baseline` True | ✅ |
| 묶음 이름 G1·G2a·G2b·G3–G6 과 RID 접미 g1a…g6a, 합 402 | §467 기록 이름(s6-l1-G2a-s6l6-g2aa 등) | ✅ |
| check 는 실패해도 종료 0 → 기록 JSON 으로 관문 | s6l6 기록 필드(`same_as_baseline`·`deps_*`) 확인 | ✅ python 관문 |
| prefixdiff 에 `differing_non_stabs_equal == true` 도 요구 | `l2_prefix_diff.py` summary 필드 | ✅ 추가 |
| 링크 기록의 `identical` 과 `cmp` 성공을 요구; 링크 전 402 행·일곱 기록 확인 | §466 절차 | ✅ |
| `X86[469]`·`EXCEPTS[469]` 로 --plan·바탕·x86gate 가 s6l7 을 고름 | `x86_prefix()` 와 `main()` 의 `in EXCEPTS` 읽음(§468) | ✅ |
| final 은 정적 기호 꼬리를 정규화하지 않음(엄격) | `m5_m68k_nst.py` final 코드 | ✅ 의도대로(같은 소스이면 같아야 함) |
| 단계 0 은 CHOSEN 통과를 따로 확인해야 함 | compare 출력 `ok ['CHOSEN']`, L1 이유 bss 하나(`l1-m5p469-v3-CHOSEN.json`), CHOSEN 대 ALL 서명 모두 같음 | ✅ 확인함 |
| `m5p469-v3` 가 잠금 상태였다 | 지금 `DONE` 있음, collect 로 출력 7 개 게시됨 — 검토 시점에 실행 중이었음 | ❌ 지금은 사실 아님 |
| CHOSEN 글을 편집 전 것으로 고정해 비교(편집 뒤 다시 만들면 고정점이 없어 실패) | `variant_text` 동작 | ✅ 저장된 `m0p469-v3-stage/src/kern/p469_CHOSEN.c` 와 비교 |
| 편집 뒤 `m5_x86_srcvar.py stage`(s6l5)는 본 파일 비교 assert 로 실패 | 65 행 | ✅ 알려진 한계로 기록 |
| final 기록 이름은 §468 것과 다르게; zerofill objs 기록도 증거로 | 설계 | ✅ `m5-m68k-ns_timer-tail-final-20261016.json`, zerofill 기록 복사 |
| PROVENANCE 594·1095 행 그 자리 갱신 | 두 행 읽음(§468) | ✅ |

### 469.6 D088 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-ns_timer-tail-final-20261016.json`

- 07 편집:
  - 본 파일 `kern/ns_timer.c`(236 → 245 행)와 덮어쓰기(488 → 497 행; 표시 줄 252 그대로)를 고쳤습니다.
  - 덮어쓰기에서 `plan 469` 주석을 정규화하면 편집 전에 고정한 `m0p469-v3-stage/src/kern/p469_CHOSEN.c` 와 같습니다(python). 파생 검사를 통과했고, 본 파일에 표시 문자열은 없습니다.
- x86 전체 재빌드 s6l7(일곱 묶음, 명령 804 개 모두 종료 0 — python 집계):
  - check 기록 일곱, 402 행 연속, 기준선과 같음 377·기대와 맞음 25, problem 0, deps 경고 0 입니다. ns_timer(338 행)는 기준선과 같습니다.
- prefixdiff s6l6↔s6l7(`s6-l2-prefixdiff-s6l6-s6l7-20261016.json`, plan 469):
  - 스테이징 차이는 `src/kern/ns_timer.c` 하나이고, 키·명령 차이는 없습니다.
  - SHA 가 다른 16 객체 가운데 RID 경로 말고도 다른 것은 `x86-ns_timer` 하나이고, 모두 비 STABS 가 같습니다.
- 링크 `s6p469-ln1`: `l2_compare` 결과 머리·명령·기호 3751·공통 417 이 같고, `identical: true` 입니다. `cmp` 로 원본과 같습니다(SHA-256 `33469393…`).
- m68k:
  - `--plan 469 stage m0p469-a1-stage` 는 파생 검사를 통과했고, x86gate(s6l7 일곱)는 모두 같으며 v183 경로는 0 입니다. `m0p468-a1-stage` 와의 차이는 `src/kern/ns_timer.c` 하나입니다.
  - final run `m5p469-a1`(명령 1 개, 종료 0)의 `F469__ns_timer.o` 는 `final` 의 assert 를 통과했습니다.
    - `P469__CHOSEN.o` 와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같습니다.
    - L1 이유는 `['__DATA,__bss: unverified']` 하나이고, 미정의는 0 입니다.
    - zerofill 은 reference-inferred(8 B, problem 0)이고, 후보 [0x40b39ba, 0x40b39c2)는 §464 후보·§467 nfs 와 겹침 0 입니다(`m5-m68k-ns_timer-zerofill-20261016.json`).
- 알려진 한계: 07 본 파일이 바뀌었으므로 `m5_x86_srcvar.py stage`(s6l5)는 본 파일 비교 assert 로 이제 실패합니다. 옛 기록은 그대로 둡니다.
- 집계:
  - ns_timer 가 "코드 검증 + bss 추정" 이 되어 그 등급은 19 개(§464 16 + §467 2 + ns_timer)입니다.
  - 코드 차이가 남은 객체는 19 개이고, ns_timer 를 포함한 m68k 이름 대응 공통부 C 208 개가 모두 컴파일됩니다.
- 기록:
  - PROVENANCE 594·1095 행을 그 자리에서 갱신했습니다(1095 행, 중복 0). MODIFICATIONS 는 626 행, DECISIONS 에 D088 을 적었습니다.
  - diff `x86-ns_timer-plan469.diff`(새로 만듦)·`m68k-ns_timer.diff`(다시 만듦)를 만들고, `x86-ns_timer.md` 에 plan 469 절을 덧붙였습니다.
  - 도구: 새로 만듦 `m5_m68k_nst.py`, 고침 `m5_m68k_srcvar.py`(`source` 키, 옛 명세 16 개 결과 동일 확인)·`m5_x86_srcvar.py`(기록 필드)·`stage_m68k.py`(plan 469). 고치기 전 사본은 `08_build/artifacts/m5p469/*.before` 입니다.

