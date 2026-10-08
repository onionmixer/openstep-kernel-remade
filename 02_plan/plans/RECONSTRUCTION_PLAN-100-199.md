# 커널 소스 복원 작업계획 — 보관 §100–199

`02_plan/RECONSTRUCTION_PLAN.md` 의 §100–199 를 절 번호·내용 그대로 옮긴 보관본(2026-10-03, D026). 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킨다. 아래는 원문 그대로다.

---

## 100. S5-P74 세부 계획 — vm_pageout 탐침 4 (코딩 전, 2026-10-02)

탐침 3 위에서(D014 R1·R2, NeXTMach D013):
- S2: :54 `int vm_page_free_min_sanity = 256*1024;` → `128*1024`(NeXTMach :75).
- S3: `pages_cleaned` 를 없앤다.
  - :71 선언을 지운다.
  - :131 `if ((vm_page_free_count + pages_cleaned) >= vm_page_free_target) {` → `if (vm_page_free_count >= vm_page_free_target) {`(NeXTMach :488 의 식).
  - :290 `pages_cleaned++;` 을 지운다. 탐침 3 에서 yield 블록을 지웠으므로 다른 참조는 없다(grep).
- 예측: scan 864 B, `__text` 1276(864+412) B, `__data` 일치. L1 O3c OBJECT_MATCH 2/2(배치되면). 남는 차이는 기록한다(scan 변형 2/3).

### 100.1 codex 교차검토(QS18) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| S2·S3 는 바이너리 근거와 맞음 | 99.2 | ✅ |
| :290 이 중괄호 없는 단독 문장이면 삭제가 빈 본문을 만듦 → 구조 확인 필요 | `cat -A` :276–295: :290 은 `if (vm_pager_put(…) == PAGER_SUCCESS) {` 블록(:285–291) 안에서 `pageout_succeeded = TRUE;` 다음 문장이다 | ✅ 삭제해도 온전(블록 유지) |
| 디버그 증가는 유지 | `#if MACH_VM_DEBUG`(:287–289)는 손대지 않음 | ✅ |

### 100.2 결과 (S5-P74, 2026-10-02) — 탐침 4: O3·O3c **OBJECT_MATCH 2/2**

- `s5p74-probe-1`(diff `x86-vm_pageout-probe4.diff`): O3 = O2 `4d60fe86…`, O3c `cd58704a…`, 두 `.i` 같음(`561f2de8…`).
- `__text` 1276 B = [0x179d44, 0x17a240). `_vm_pageout` 412 B 는 끝에 컴파일러 정렬 `90 90` 을 포함한다.
- L1:
  - O3: OBJECT_MATCH 2/2. `__text`·`__data`·`__common` 모두 심볼 배치이고, 바이트·참조 차이가 0 이다.
  - O3c: OBJECT_MATCH 2/2.
- cmd 머리 주석에 sed 치환 잔여가 섞였다("…;: probe 1 plus s…"). 실행 내용에는 영향이 없으며, 탐침별 diff 파일이 정확한 기록이다.

## 101. S5-P75 세부 계획 — `vm/vm_pageout.c` 채택 (코딩 전, 2026-10-02)

사실(Python):
- 객체 = [0x179d44, 0x17a240) 1276 B(objects.tsv 의 0x17a23e 끝은 마지막 `ret` 기준 추정). 원본 0x17a23e–0x17a23f `90 90` 은 이 객체 `__text` 의 일부다(빌드 바이트와 같음).
  - 앞: 0x179d41–0x179d43 `00×3` = 확정 vm_object 의 gap_after `3 x 00`.
  - 뒤: 0 B. 확정 `x86-vm_pager` 가 0x17a240 에서 시작한다.
  - `x86-vm_pager` 의 gap_before 칸 "2 x 90 (… value 90 not 00, see evidence)" 는 이제 "vm_pageout 객체 안의 정렬 채움" 으로 설명된다. 그 행을 정정할지는 아래 3 에서 정한다.
- common 2 개(`_vm_pages_needed` 4/4, `_vm_pages_needed_lock` 4/12)는 크기 ≤ 간격이다. O3 에서 이미 심볼로 배치되어 OBJECT_MATCH 다(36.1 의 대응 확인도 기록용으로 한다).
- `.i` 표지 93 개 중 07 에 없는 것은 대상 파일뿐이다.

절차:
1. `07_kernel/src/vm/vm_pageout.c` = 탐침 4 본문 + `Modified` 주석. 빌드 `s5p75-build-1` 의 예측은 O3 `4d60fe86…`·O3c `cd58704a…` 다.
2. 판정 **A**(경계 앞 3 B 최소 00, 뒤 0 B). 표: functions +2, objects_confirmed +1, PROVENANCE·MODIFICATIONS·증거·diff.
3. `x86-vm_pager` 의 gap_before 칸을 "0 bytes (x86-vm_pageout __text includes the 90 90 alignment, ends at 0x17a240)" 로 정정한다. 표 수정은 읽기→쓰기→행 수 확인으로 하고, 증거 파일에 정정 메모를 남긴다.

### 101.1 codex 교차검토(QS19) 판정과 추가 사실

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| A 등급과 vm_pager gap_before 정정은 근거 있음 | 100.2 의 L1 JSON, 원본 0x17a23e `90 90`(Python) | ✅ |

추가(내 확인): `x86-vm_pager.md:34–37` 은 이 `90 90` 을 "설명 안 됨" 으로 두고 vm_pager 를 **A\***("앞 경계 미증명")로 판정했다. 이제 앞 경계가 증명되었다. vm_pageout `__text` 의 끝이 0x17a240 이고, 그 2 B 는 vm_pageout 빌드 바이트와 같다. README:23 의 A 조건(OBJECT_MATCH + 앞뒤 경계 증명서)에 따라 vm_pager 를 **A 로 재판정**한다. 행 수정은 읽기→쓰기→행 수 확인, 증거 파일에 재판정 메모를 남긴다.

### 101.2 결과 (S5-P75, 2026-10-02) — `vm_pageout.c` **A**, `vm_pager` A* → **A**

- 빌드 `s5p75-build-1`: 예측 일치. O3 `4d60fe86…`·O3c `cd58704a…`, 두 `.i` 같음. L1 O3 OBJECT_MATCH 2/2(참조 99). `.i` 표지 93 개 모두 07 에 있다.
- 표:
  - functions +2.
  - objects_confirmed +1(vm_pageout A). `x86-vm_pager` 는 grade A*→A, gap_before 를 정정했다(행 수는 +1 만 늘어남 확인).
  - PROVENANCE +1, MODIFICATIONS +1, 증거 `x86-vm_pageout.md` 와 `x86-vm_pager.md` 재판정 메모.

## 102. S5-P76 세부 계획 — vm_kern 판단 보류, kern/ 미채택 파일 일괄 진단(채택 없음) (코딩 전, 2026-10-02)

vm_kern 판단(Python 호출 순서 비교, srcdefs):
- 원본 `_kmem_alloc` 계열은 `vm_map_find`·`vm_map_delete`·`vm_map_insert`·`lock_done`·static 도우미(`FUN_00173ebc`: `vm_page_alloc_sequential`·`thread_sleep`·`vm_page_zero_fill`)·`vm_map_pageable` 을 부른다. NeXTMach `kmem_alloc` 방식이다.
- 동시에 원본에는 Darwin 에만 있는 `kmem_realloc`·`kmem_alloc_wired`·`kmem_alloc_zone`·`copyinmap`·`copyoutmap` 이 있다. 즉 두 참조의 중간 판이다.
- 함수 여러 개에 걸친 혼합·작성이 필요해 위험도가 높다. 그래서 이번 연속 회차에서는 미룬다. vm_map 도 같은 계열(빌드 전용 `vm_map_find_entry`)이라 함께 미룬다.

진단 대상(91 절 목록 중 kern/, 07 에 없음, Darwin 후보): ast, exception, ipc_kobject, ipc_mig, kernel_stack, mach_clock(seq 170), mach_header, mach_net, mapfs, miniMon, ns_timer, power, kdp_udp, sched_prim, syscall_subr, syscall_sw, task, thread, zalloc. objects.tsv 행 하나에 후보가 하나인 C 등급 4 개(mach_init·mach_fat·mach_loader·kdp, 함수 1 개)도 넣는다.

설계(91.1 반영 방식 그대로):
- 스테이징 1 개를 쓰고, 파일마다 kr_run 실행 1 개(O3c 1 명령, ddm 템플릿 플래그)를 돌린다. 수집은 파일별로 한다.
- 컴파일된 파일마다 심볼 간격 비교와 L1 을 하고 요약을 남긴다.
- 실패는 첫 오류를 기록한다. 채택·판정은 없고, 다음 회차 후보 순위만 정한다.

### 102.1 codex 교차검토(QS20) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 91.1 의 "간격 차이는 간격 차이로, 빌드 전용 static 은 따로, 마지막 함수는 잠정" 이 102 에 명시되지 않음 | 102 절 본문 | ✅ 요약 JSON 에 `gap_diff`·`build_only`·`last_provisional` 칸을 둔다 |
| 파일마다 실행 ID·출력 분리 | kr_run 은 ID 마다 별도 디렉터리(`08_build/runs/<ID>`) | ✅ ID `s5p76-pre-<이름>` |
| mach_clock 은 seq 170 로 고정 | objects.tsv: seq 170 [0x15bc30,0x15c023), 182 [0x160714,0x160795) | ✅ 구간을 seq 로 고정 |
| ipc_mig·syscall_subr 의 이전 보류 이유 유지 | 계획 64·52 절 기록 | ✅ 요약에 "이전 보류 사유" 를 함께 적는다 |

### 102.2 결과 (S5-P76, 2026-10-02) — kern/ 23 파일 진단

실행 `s5p76-pre-<이름>`(miniMon 은 ID 규칙상 소문자 `s5p76-pre-minimon`). 요약 `09_validation/reconstruction/s5p76-pre-summary-20261002.json` 에는 간격 차이·빌드 전용·원본 전용·마지막 함수(잠정)·이전 보류 사유 칸이 있다. 파일별 L1 은 `s5p76-pre-l1-<이름>-O3c-20261002.json` 이다.

- 컴파일 실패 7:
  - exception(`norma_ipc.h`)
  - ipc_kobject(`ikm_sender` 멤버 없음)
  - kernel_stack(`mach_debug.h`)
  - mach_net(`mach_net.h`)
  - sched_prim·thread(`hw_footprint.h`)
- 컴파일 17 의 요약(빌드/원본 `__text`, 간격 같은 함수 수):

| 파일 | 크기 | 간격 같음 | 메모 | L1 |
|---|---|---|---|---|
| syscall_sw | 24/24 | 2/2 | `__data` 1124 B 에 바이트 차이 6, 참조 미검증 3 | `__text` 2 MATCH |
| syscall_subr | 1028/1481 | 9/10 | 원본 전용 `_map_fd`(이전 보류: 52 절, NeXTMach `map_fd` 의 BSD 의존) | 9 MATCH |
| ast | 568/580 | 1/2 | `_ast_check` 540/552 | 1 MATCH, 1 BOUNDARY |
| task | 4326/4342 | 18/21 | 3 함수 간격 차이 | 배치 안 됨 |
| power | 949/933 | 5/7 | `power_callout`·`power_init` 각 +8 | 배치 안 됨 |
| mach_header | 1375/1190 | 13/14 | 빌드 전용 2 | 배치 안 됨 |
| 그 밖 | — | — | 크기·구성 차이가 큼(mach_loader·kdp·mapfs·kdp_udp 등은 빌드가 훨씬 큼 = 객체 범위 추정 문제 가능) | — |

다음 우선순위는 syscall_sw(`__data` 6 B), ast, power, task 다.

## 103. S5-P77 세부 계획 — `kern/syscall_sw.c` 탐침(트랩 표 4 항목) (코딩 전, 2026-10-02)

사실(Python, `__data` 0x1df72c 원본 대 빌드, 16 B 항목 `{arg_count, function, stack, 0}`):
- 빌드 바이트 차이 6 곳(328·384·392·512·520·576)은 트랩 20·24·32·36 에 있다.
  - 트랩 20: 원본 `{4, _msg_send_trap, 0}`, 빌드 stack=1. Darwin :133 `MACH_TRAP_STACK(msg_send_trap, 4)` 다. 트랩 21·22 는 원본도 stack=1 이다(Python 디코드).
  - 트랩 24: 원본 `{0, _kern_invalid, 0}`, Darwin :142–143 `MACH_TRAP_STACK(mach_msg_simple_trap, 5)`.
  - 트랩 32: 원본 `_kern_invalid`, Darwin :152 `MACH_TRAP_STACK(mach_msg_overwrite_trap, 9)`.
  - 트랩 36: 원본 `_kern_invalid`, Darwin :156 `MACH_TRAP(_lookupd_port1, 1)`.
- `_mach_msg_simple_trap`·`_mach_msg_overwrite_trap`·`__lookupd_port1` 은 원본 심볼표에 없다(grep 0). `_lookupd_port1` 은 ipc_xxx 복원(62 절)에서 이미 지운 함수다. L1 의 미검증 참조 3 개가 이 셋이다.
- `__text` 24 B 는 2 MATCH 다.

탐침(스테이징만, D014 R1·R2):
- T1: :133 `MACH_TRAP_STACK(msg_send_trap, 4)` → `MACH_TRAP(msg_send_trap, 4)`(같은 파일의 매크로, 원본 stack=0). 주석은 유지한다.
- T2: :142–143 → `MACH_TRAP(kern_invalid, 0),\t\t/* 24 */`.
- T3: :152 → `MACH_TRAP(kern_invalid, 0),\t\t/* 32 */`.
- T4: :156 → `MACH_TRAP(kern_invalid, 0),\t\t/* 36 */`.
- 예측: `__data` 1124 B 바이트 차이 0, 참조 70 → 67(모두 검증). L1 OBJECT_MATCH. 크기는 그대로다.
- 일치하면 다음 회차에 채택한다. 경계 확인, `.i` 검사, `mach_trap_count` 확인을 한다.

### 103.1 codex 교차검토(QS21) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `MACH_TRAP` 은 같은 파일이 아니라 `kern/syscall_sw.h` 에 정의됨 | grep: `syscall_sw.h:70`(`MACH_TRAP`), `:72`(`MACH_TRAP_STACK`) | ✅ 103 절 표현 정정(동작 영향 없음) |
| :133 은 `#if MACH_IPC_COMPAT` 안이라 그 분기가 컴파일되는지 미확인 | `07_kernel/generated/mach_ipc_compat.h` = `#define MACH_IPC_COMPAT 1` | ✅ 그 분기가 컴파일된다 |
| 16 B 크기는 `boolean_t` 크기에 달림 | `syscall_sw.h:63` `boolean_t mach_trap_stack;`. 표 1120 B = 70 × 16, `_mach_trap_count` 가 1120 에 있다(빌드 심볼, Python) | ✅ |

### 103.2 결과 (S5-P77, 2026-10-02) — 탐침 1: **OBJECT_MATCH**

- `s5p77-probe-1`(diff `x86-syscall_sw-probe1.diff`): O2 = O3 = O3c `d99442d4…`(common 없음), 두 `.i` 같음.
- L1 O3·O3c OBJECT_MATCH 2/2: `__text` 24 B, `__data` 1124 B(심볼 배치, 바이트 차이 0).
- **예측 오류**: 참조 수를 67 로 예측했지만 70 이며 모두 검증되었다. 바꾼 항목도 `kern_invalid` 재배치를 가진다.

## 104. S5-P78 세부 계획 — `kern/syscall_sw.c` 채택 (코딩 전, 2026-10-02)

사실(Python, capstone):
- 원본 `__text` [0x16594c, 0x165964) 24 B: `_null_port`(`xor eax,eax`)·`_kern_invalid`(`mov eax,4`), 사이에 `90×3`.
- 앞 경계: 0x165948 `c3` 다음 0x165949–0x16594b `00×3` = 4 정렬 최소 채움 3. 그 `ret` 이 어느 Ghidra 함수의 끝인지는 위 출력으로 확인한다.
- 뒤 경계: 0 B. `_task_init` 0x165964 = Ghidra 함수 시작.
- `__data` 1124 B 는 `_mach_trap_table` 0x1df72c·`_mach_trap_count` 심볼로 배치된다.

절차: 07 = 탐침 본문 + `Modified` 주석. 빌드 `s5p78-build-1` 의 예측은 `d99442d4…` 3 판 동일이다. 이어서 L1, `.i` 검사, 경계를 확인하고 **A** 로 판정한다. 표 functions +2(high), objects_confirmed +1, PROVENANCE·MODIFICATIONS·증거·diff.

### 104.1 codex 교차검토(QS22) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 앞뒤 관찰을 경계 증명서로 기록하면 A 타당. syscall_subr 채택은 필요 없음 | README:23–24 | ✅ |
| `_map_fd` 의 끝은 Ghidra 해석이므로 원본 바이트·심볼 근거를 남길 것 | 원본 심볼 `_map_fd` 0x165784(symbols.tsv). Ghidra 몸체 조각 끝 0x165948 = capstone `ret`. 다음 원본 심볼 `_null_port` 0x16594c. 사이 `00×3` = 최소 채움(Python) | ✅ 증거 파일에 기록 |
| 출처·수정 4 곳을 PROVENANCE·MODIFICATIONS 에 | — | ✅ |

### 104.2 결과 (S5-P78, 2026-10-02) — `syscall_sw.c` **A**

- 빌드 `s5p78-build-1`: 예측 일치(3 판 `d99442d4…`). L1 OBJECT_MATCH.
- `.i` 표지 113 개 중 07 에 없던 헤더 3 개(`kern/syscall_subr.h`·`kern/syscall_sw.h`·`mach/mach_traps.h`)는 원문 그대로 채택했다(스테이징 사본과 SHA 같음). 원문 그대로라 07 우선 스테이징 바이트가 같으므로 회귀는 필요 없다.
- 표: functions +2, objects_confirmed +1(A), PROVENANCE +4, MODIFICATIONS +1, 증거·diff.

## 105. S5-P79 세부 계획 — `kern/task.c` 탐침 1 (u-area 복원) (코딩 전, 2026-10-02)

102.2 이후 확인(capstone 이름 붙임, grep):
- ast: `_ast_check` 차이는 BSD 신호 매크로(`SHOULDissignal`, proc 구조)와 스케줄 검사 구조다 → D020 영역이라 보류한다.
- power: 원본이 옛 callout API(`_calloutEntryAllocate`·`_calloutDeadlineFromInterval(0, 1010000000)`·`_calloutEntryDispatchDelayed`)를 쓰고 Darwin 은 `thread_call_*` 다. 이전 보류("callout API", PCtimers 와 같음) 그대로 둔다.
- task(원본 [0x165964, 0x166a5a) 4342 B, 21 함수, 18 간격 같음):
  - 원본 `_task_create` 0x165a4b–0x165a5b: `zalloc(_u_task_zone)` → `[task+0x38]`(07 `kern/task.h:96` `struct utask *u_address`), `call _utask_zero(task)`.
    - Darwin `task.c:83` 에 `extern zone_t u_task_zone; /* UNIX */` 선언만 남아 있다.
    - NeXTMach `task.c:204`·`:206` 은 `new_task->u_address = (struct utask *) zalloc(u_zone);` / `utask_zero(new_task);` 다.
    - 원본 심볼은 `_u_task_zone`(0x1e94ec)·`_utask_zero`(0x106de8)·`_utask_free`(0x106d44)다.
  - 원본 `_task_terminate`(인라인 `task_deallocate` 포함)·`_task_deallocate`: `pcb_common_terminate(task)` 다음 `utask_free(task->u_address)`, 그다음 `zfree(task_zone, task)`. NeXTMach `:301` 과 같은 순서다.
  - Darwin `task_terminate` :290–292 의 `if (task->proc) return KERN_FAILURE;`(주석 "Disallow termination of U**X proc tasks")가 원본에 없다. 원본 0x165cce–0x165cdc 에는 `!active` 검사만 있고 바로 `lea ecx,[esi+0x1c]` 다.

탐침 1(스테이징만):
- K1(복원 수정, NeXTMach :204·:206, 이름은 Darwin :83 과 원본 심볼 `_u_task_zone`): :150–151 `panic(...)` 블록 뒤에 `new_task->u_address = (struct utask *) zalloc(u_task_zone);` 와 `utask_zero(new_task);` 를 넣는다. `utask_zero` 원형이 없으면 함수 선언이 필요하다(암시적 int 선언으로도 같은 코드라면 추가 안 함, 빌드로 확인).
- K2(NeXTMach :301): :258 `pcb_common_terminate(task);` 와 :259 사이에 `utask_free(task->u_address);` 를 넣는다.
- K3(R1·R2): :290–292(주석 1 줄 + `if` 2 줄)를 지운다.
- 예측: task_create 444→460, task_deallocate 160→168, task_terminate 988→980(간격). 남는 차이(task_create 의 추가 필드 0 초기화 1 개 등)는 바이트로 기록한다.

### 105.1 codex 교차검토(QS23 지연 중단 → QS23b) 판정

내 확인(줄 출력): K1 삽입 위치는 :151 뒤, K2 는 :258 과 :259 사이, K3 는 :290–293(주석·`if`·`return`·빈 줄)이다. `struct utask` 는 07 `task.h:96` 에서 포인터로만 쓰인다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 정의 안 된 `struct utask` 로의 포인터 캐스트는 C89 에서 유효 | — | ✅ |
| `utask_zero`·`utask_free` 를 선언 없이 부르면 암시적 `int` 선언이 되고, 실제 `void` 면 호환 안 됨 → 선언 추가 | NeXTMach `kern/task.c` 도 선언 없이 부른다. 정의는 `bsd/kern_fork.c:320`·`:345`(K&R, 반환형 생략 = int). 이 번역 단위에는 충돌하는 선언이 없다 | ⚖️ 기각(선언 추가 안 함). 반환값을 쓰지 않으므로 코드가 같다. 바이트로 확인한다 |
| `utask_free` 를 두 해제 경로 모두에 | :245 의 다른 경로는 `#if NORMA_TASK` 안이고, `07_kernel/generated/norma_task.h` = 0 이다 | ⚖️ 컴파일되는 경로는 하나다 |
| `zalloc` 뒤 생성 실패 경로의 `u_address` 소유 | `zalloc(task_zone)` 실패는 `panic`(:150) 이다. `u_task_zone` 할당 실패 검사는 원본에도 없다(0x165a52–0x165a5b) | ✅ 원본과 같게 검사 없음 |

### 105.2 탐침 1 결과와 추가 계획(K4, 코딩 전)

- `s5p79-probe-1`(diff `x86-task-probe1.diff`): `__text` 4350/4342. `task_deallocate`·`task_terminate` 를 포함해 20 함수의 간격이 같아졌다. `_task_create` 만 468/460 이다.
- 정규화 diff: 빌드에만 `mov dword ptr [ebx+0x3c], 0` 이 있다. +0x3c 는 `proc`(07 `task.h:97`, `u_address` +0x38 다음)이고 Darwin `task.c:177` `new_task->proc = 0;` 이다. NeXTMach `kern/task.c` 에는 `->proc` 대입이 없다(grep). 나머지는 정렬 nop 1 개다.
- K4(D014 R1·R2): :177 을 지운다. 예측: `_task_create` 460, `__text` 4342, L1 OBJECT_MATCH(또는 bss/common 의존).

#### 105.2 codex 교차검토(QS24) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 남는 저장은 Darwin `new_task->proc = 0;` 과 일치, :177 삭제에 오류 없음 | `cat -A` :174–179(빈 줄 사이 단독 문장) | ✅ |
| `proc` 초기화를 빼면 미초기화 위험 → 원본과 대조 | 원본 `_task_create` 에 +0x3c 저장이 없다(정규화 diff). 재현 대상은 원본 동작이고, 런타임 의미는 주장하지 않는다 | ⚖️ 원본 그대로 재현(기록만) |
| 다시 빌드해 바이트 비교, 기록 | — | ✅ |

### 105.3 결과 (S5-P79, 2026-10-02) — 탐침 2: **OBJECT_MATCH 21/21**

- `s5p79-probe-2`(diff `x86-task-probe2.diff`): O3 `c7eabd7a…`, O3c `5af05a12…`, O2 `7f6a7a77…`(다름), 두 `.i` 같음(`c921df67…`).
- L1 O3·O3c OBJECT_MATCH 21/21. O3 는 `__text`·`__data`·`__common` 모두 심볼 배치이고 바이트·참조 차이가 0 이다.

## 106. S5-P80 세부 계획 — `kern/task.c` 채택 (코딩 전, 2026-10-02)

사실(Python):
- 객체 [0x165964, 0x166a5a) 4342 B, 21 함수.
  - 앞: 0 B. 확정 `x86-syscall_sw` 가 0x165964 에서 끝난다.
  - 뒤: 0x166a5a–0x166a5b `00 00` = 4 정렬 최소 채움 2 이고, 0x166a5c 는 Ghidra 함수 시작 `_stack_privilege` 다(원본 심볼은 위 grep 결과).
- O3 OBJECT_MATCH 이므로 common 은 심볼 배치까지 검증되었다. 36.1 대응은 기록용으로 한다.
- `.i` 표지 102 개 중 07 에 없는 것은 대상 파일뿐이다.
- 수정: K1(u_address 할당 + `utask_zero`, NeXTMach :204·:206, 이름 `u_task_zone` 은 Darwin :83·원본 심볼), K2(`utask_free`, NeXTMach :301), K3(`proc` 검사 삭제), K4(`proc = 0` 삭제). 새 텍스트는 NeXTMach 문장과 Darwin 선언 이름의 조합이라 작성(D016) 표시는 하지 않는다. 다만 K1 의 `u_task_zone` 은 NeXTMach `u_zone` 대신 쓴 이름이므로 MODIFICATIONS 에 명시한다.

절차: 07 = 탐침 2 본문 + `Modified` 주석. 빌드 `s5p80-build-1` 의 예측은 O3 `c7eabd7a…`·O3c `5af05a12…` 다. 이어서 L1 을 하고, 판정은 **A** 다. 표 functions +21, objects_confirmed +1, PROVENANCE·MODIFICATIONS·증거·diff.

### 106.1 codex 교차검토(QS25) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| A 타당 | 105.3 L1 JSON, 경계 Python(앞 0, 뒤 `00 00`, `_stack_privilege` 0x166a5c 원본 심볼) | ✅ |
| K1 의 식별자 치환은 authored 표시 불필요, MODIFICATIONS 에 명시 | 106 절 | ✅ |

### 106.2 결과 (S5-P80, 2026-10-02) — `task.c` **A**

- 빌드 `s5p80-build-1`: 예측 일치. L1 OBJECT_MATCH 21/21(참조 124). `.i` 102 개 모두 07 에 있다.
- 표: functions +21, objects_confirmed +1(A), PROVENANCE +1, MODIFICATIONS +1, 증거·diff.

## 107. S5-P81 세부 계획 — `kern/mach_header.c` 탐침 (코딩 전, 2026-10-02)

사실(102.2 요약, Python, grep):
- 원본 seq 172 [0x15c2fc, 0x15c7a2) 는 원본 심볼 14 개다. 마지막 `_getfakefvmseg` 는 `ret`(0x15c7a1) 뒤 `90 90` 이고, 다음 함수가 0x15c7a4 에서 시작한다(원본 바이트 `5e5f89ec5dc39090 5589e557`). 따라서 객체 끝은 0x15c7a4 로 추정되고, 간격 차이 240/238 은 끝 추정 문제다(91.1 의 "마지막 함수 잠정" 사례).
- Darwin 그대로 빌드 1375 B 에는 빌드 전용 `_getsegdatafromheader`(Darwin :112–135, 주석 포함)와 static `_getsizeofmacho`(:403–423, 주석 포함)가 있다. 둘 다 원본 심볼표에 없다(grep 0). Darwin 커널 안의 다른 사용은 `mach_header.h:56` 원형 하나뿐이다.

탐침(스테이징만, D014 R1·R2):
- H1: :112–136(주석·함수·뒤 빈 줄)을 지운다.
- H2: :403–423(주석·함수)을 지운다. :402 빈 줄과 :424 `#endif` 는 유지한다. 헤더 원형은 그대로 둔다(R2).
- 예측: `__text` = 원본 객체 0x15c7a4 − 0x15c2fc = 1192 B(끝 `90 90` 포함, Python 으로 계산해 기록). 14 함수가 MATCH 이고 L1 OBJECT_MATCH(또는 data 의존)다.

### 107.1 codex 교차검토(QS26) 판정 → H2 철회

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `getsizeofmacho` 는 같은 파일 :391(`getfakefvmseg` 안)에서 호출되고 :233 에 원형이 있음 → 107 절의 "다른 사용 없음" 은 틀림 | grep: :233 원형, :391 호출, :407 정의 | ✅ **내 오류**. 다른 파일만 grep 했다 |
| `getsegdatafromheader` 의 파일 안 다른 호출은 없음 | grep: :32 주석, :119 정의뿐 | ✅ |

추가 확인(capstone): 원본 `_getfakefvmseg` 의 호출은 `_strncmp`·`_strcmp`·**0x15c7a4**·`_strcpy` 다. 0x15c7a4 는 `90 90` 바로 뒤의 심볼 없는 함수이고, 이것이 원본의 static `getsizeofmacho` 다. 빌드도 같은 자리에서 지역 함수를 부른다. 따라서:
- objects.tsv seq 172 의 끝 0x15c7a2 는 짧다. 객체는 `getsizeofmacho` 까지 포함한다.
- H2 는 **철회**하고 H1(`getsegdatafromheader` 삭제)만 한다.
- 예측: `__text` 1375 − 52 = 1323 B, 객체 [0x15c2fc, 0x15c827) 다(Python). 끝은 L1 배치로 확인한다.

### 107.2 결과 (S5-P81, 2026-10-02) — 바이트 일치, `__mh_execute_header` 참조 16 개 미검증

- `s5p81-probe-1`(diff `x86-mach_header-probe1.diff`): `__text` **1323 B**(예측과 같음)·재배치 49, `__data` 131 B, O3 `__common` 4 B.
- L1 O3·O3c: 15 함수 바이트·참조 차이 0. 8 MATCH, 7 MATCH_UNVERIFIED. `__text` 는 0x15c2fc 심볼 배치, `__data` 는 0x1dee8c 에 L1d 검증, O3 common 은 심볼 배치다.
- 미검증 16 개는 모두 `symbol __mh_execute_header not in image` 다. 링커가 정의하는 심볼(Mach-O 헤더 주소)이라 원본 심볼표에 없다. 원본 load command(Python): `__TEXT` vmaddr 0x100000, fileoff 0. 따라서 헤더 주소는 0x100000 이다.

## 108. S5-P82 세부 계획 — `l1_compare.py --define-symbol` (링커 정의 심볼) (코딩 전, 2026-10-02)

설계:
- `--define-symbol NAME=ADDR`(반복 가능)을 추가한다. 이미지 심볼표에 NAME 이 없을 때만 그 값을 쓴다. 이미 있으면 오류로 멈춘다(가리기 금지).
- 결과 JSON 에 `defined_symbols: {NAME: ADDR}` 를 기록한다. 함수·섹션 판정에는 따로 표시하지 않고 참조 검증에만 쓴다.
- 쓰는 곳은 링커 정의 심볼뿐이다. 그 값의 근거(예: `__mh_execute_header` = fileoff 0 을 담은 세그먼트 `__TEXT` 의 vmaddr)는 계획·증거에 남긴다.
- 시험(`test_l1_compare.py` 확장 또는 새 시험):
  - 옵션 없이 결과가 이전과 같은지(mach_header 탐침 JSON 재현과 기존 확정 객체 몇 개의 L1 JSON 동일성).
  - 옵션을 주면 해당 참조가 verified 가 되는지.
  - 틀린 주소를 주면 refs_differ 가 되는지(음성 시험).
  - 이미지에 있는 이름을 주면 오류가 나는지.

### 108.1 codex 교차검토(QS27) 판정 → 설계 수정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 배치 계산 전에 정의하면 배치(그리고 L1d)가 바뀔 수 있음 | `placements_from_image` :437 이 `img.symbol` 을 쓴다 | ✅ 정의는 배치 계산 **뒤**에 적용 |
| 충돌 검사는 SECT 비-STAB 심볼만 봄 → 모든 이미지 심볼과 비교 | `Image.__init__` :45–48 | ✅ `o['symbols']` 전체 이름과 비교 |
| local·scattered 처리는 범위 밖이라 독립성 미확인 | grep `img.symbol`/`.symbol(`: :170(extern)·:437(배치)뿐 | ✅ local·scattered 는 영향 없음 |
| "fileoff 0 세그먼트" 는 `__PAGEZERO` 도 해당 → 파일 바이트를 가진 세그먼트로 | load command 출력: `__PAGEZERO` fileoff 0 filesize 0, `__TEXT` fileoff 0 filesize 892928 | ✅ `__mh_execute_header` = filesize>0 이고 fileoff 0 을 포함하는 `__TEXT` 의 vmaddr 0x100000 |

### 108.2 시험 중 발견 → 설계 교체(코딩 전 재계획)

- 시험 `test_l1_define.py` 에서 `--define-symbol __mh_execute_header=…` 가 "이미지에 이미 있는 이름" 으로 거부되었다. 원본 심볼표(Python, symbols.tsv:400)에 `__mh_execute_header` 가 **ABS 심볼**(type 3, 값 0x100000, 외부)로 **있다**.
- L1 의 `Image` 는 SECT 심볼만 색인한다(:45–48). 그래서 "not in image" 는 도구의 한계였다. 107.2·108 의 "원본 심볼표에 없다" 는 **내 오류**다.
- 원본 비-STAB ABS 심볼은 100 개(모두 외부)다. ObjC `.objc_class_name_*`·`.objc_category_name_*`(값 0)와 `__mh_execute_header` 이고, SECT 심볼과 이름이 겹치는 것은 0 이다.

교체 설계:
- `--define-symbol` 을 걷어낸다(코드·시험 삭제. 아직 기록된 결과에 쓰이지 않음).
- `Image` 에 `abs` 표(비-STAB ABS, 이름당 값 1 개)를 둔다. **extern 재배치 해석(:170)에서만** SECT 에 없을 때 ABS 값을 S 로 쓴다(링커 의미: 절대 심볼의 값). 근거 문자열은 `extern-abs NAME` 이다. 배치(:437)는 SECT 만 쓴다.
- 기본 동작이 바뀌는 범위는 "ABS 이름을 참조하는 extern 재배치" 뿐이다. 그런 재배치는 이전에 unverified 였다. 회귀 확인:
  - (a) 확정·부분 객체 빌드 산출물 전체를 훑어 ABS 이름을 참조하는 객체를 Python 으로 찾는다.
  - (b) 그 객체들과 위 9 개 대표 객체의 L1 을 옛/새 도구로 비교한다. 바뀌는 것은 해당 참조의 unverified → verified/differ 뿐이어야 한다.
- 시험: mach_header(16 참조 → 검증), 틀린 값 음성 시험(ABS 값을 바꾼 이미지 사본이 아니라 단위 시험으로 `Image.abs` 조작), 배치 불변.

### 108.3 codex 교차검토(QS28) 판정 → 최종 설계

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| ABS 값을 S 로 쓰는 것은 i386 VANILLA extern(pcrel 포함)에 맞음. pcrel 보정은 별도 확인 | `l1_compare.py:173` `exp = F + S - (dP if r['pcrel'] else 0)`(위 sed) | ✅ 기존 식 그대로 쓴다 |
| 값 0 인 ObjC ABS 심볼은 S=0 이라 F 가 그대로 맞아 MATCH 가 정보가 없음 | ABS 100 개 중 값 0 이 아닌 것은 `__mh_execute_header` 하나(108.2 Python) | ✅ **값 0 이 아닌 ABS 만** 해석한다. 값 0 인 것은 이전처럼 unverified 로 둔다 |
| 옛/새 비교만으로는 정당성이 증명되지 않음 → 독립 기대값 | mach_header 의 16 필드는 원본 바이트에서 `F + 0x100000` 이어야 한다. 이것을 따로 Python 으로 계산해 대조한다 | ✅ |
| 음성 시험은 `Image.abs` 조작이 아니라 ABS 값을 바꾼 이미지 사본으로 | — | ✅ nlist `n_value` 를 +4 바꾼 사본으로 시험 |

구현: `--define-symbol` 을 제거하고, `Image.abs`(값≠0 인 비-STAB ABS)를 :170 의 extern 해석에서만 쓴다. 결과의 재배치 근거 문자열은 `extern-abs NAME` 이다.

### 108.4 결과 (S5-P82, 2026-10-02) — ABS 해석, mach_header OBJECT_MATCH

- `l1_compare.py`: `Image.abs`(값≠0 인 비-STAB ABS)를 extern 재배치 해석에만 쓴다. 근거 문자열은 `extern-abs`. `--define-symbol` 은 걷어냈다(기록된 결과에 쓰인 적 없음).
- 회귀:
  - 모든 빌드 산출물(`08_build/runs/*/out/*.o`)에서 `__mh_execute_header` 를 참조하는 객체는 mach_header 3 판뿐이다(Python).
  - 대표 9 객체의 옛/새 L1 JSON 은 mach_header 를 빼고 모두 동일하다. mach_header 만 미검증 16 → 0, OBJECT_MATCH 로 바뀌었다.
- 시험 `test_l1_abs.py` 5/5:
  - 독립 기대값(원본 필드 = F + 0x100000, 16/16).
  - 심볼표 값을 +4 한 이미지 사본에서 참조 차이 16.
  - 값 0 인 ObjC 표식은 해석하지 않음.
  - 배치 불변.
- `test_sect_of` 7/7.
- mach_header(`s5p81-probe-1`, 새 도구): O3·O3c **OBJECT_MATCH 15/15**. `__data` 는 L1d, O3 common 은 심볼 배치다.

## 109. S5-P83 세부 계획 — `kern/mach_header.c` 채택 (코딩 전, 2026-10-02)

사실(Python):
- 객체 [0x15c2fc, 0x15c827) 1323 B, 15 함수(원본 심볼 14 + static `getsizeofmacho` 0x15c7a4).
  - 앞 0 B: 확정 `x86-mach_factor` 가 0x15c2fc 에서 끝난다(gap_after "0 (next object starts aligned)").
  - 뒤: 0x15c827 `00` 1 B = 최소 채움이고, `_setup_main` 0x15c828 이다.
- common `_fvm_seg` 4/4.
- `.i` 표지 108 개 중 07 에 없는 것: 대상 파일, Darwin `kern/mach_header.h`, 실기 SDK `nextdev/mach-o/loader.h`. SDK 쪽은 `nextdev/` 선례(D018)대로 실기 SHA 목록과 일치해야 하고, PROVENANCE 에 license TBD(D017)로 적는다.
- objects.tsv seq 172 의 끝 추정(0x15c7a2)은 짧았다(107.1). objects.tsv 는 자동 생성 후보표이므로 고치지 않고 증거에 적는다.

절차:
1. 07 = 탐침 본문 + `Modified` 주석. 헤더 2 개를 채택한다(SHA 확인).
2. 빌드 `s5p83-build-1`. 예측 O3·O3c = 탐침 해시.
3. 새 L1 로 OBJECT_MATCH 를 확인하고 **A** 로 판정한다. 표 functions +15(static `getsizeofmacho` 는 `(static getsizeofmacho; Ghidra …)` 표기 — Ghidra 함수 이름을 확인해 적는다), objects_confirmed +1, PROVENANCE +3, MODIFICATIONS +1, 증거.

### 109.1 codex 교차검토(QS29) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| A 타당 | 108.4 L1 JSON, 109 경계(Python) | ✅ |
| 남은 마감(헤더 채택·표·출처) 필요 | 109 절 절차 3 | ✅ 이번에 수행 |

추가 확인: static `getsizeofmacho` = Ghidra `FUN_0015c7a4`. SDK `mach-o/loader.h` sha256 `c2eb3796…` = 실기 목록이다(Python·sha256sum).

### 109.2 결과 (S5-P83, 2026-10-02) — `mach_header.c` **A**

- 빌드 `s5p83-build-1`: 예측 일치(탐침과 바이트 같음). L1 OBJECT_MATCH 15/15(참조 49). `.i` 108 개 모두 07 에 있다.
- 표: functions +15, objects_confirmed +1(A), PROVENANCE +3(`mach_header.c`, Darwin `kern/mach_header.h`, SDK `nextdev/mach-o/loader.h`), MODIFICATIONS +1, 증거·diff. 헤더는 원문 그대로라 회귀는 필요 없다.

## 110. S5-P84 세부 계획 — `kern/mach_init.c` 탐침 (코딩 전, 2026-10-02)

사실(capstone, 원본 `_setup_main` 0x15c828, 102.2 진단):
- 호출 순서: `_clock_timer_init`, `_rqinit`, `_sched_init`, `_vm_mem_init`, `_mach_clock_bootstrap`, `_init_timers`, `_init_timeout`, `_startup(virtual_avail)` → (`printf` 없음) → `machine_info` 대입 → `_uzone_init`, `_ipc_bootstrap`, `_cpu_up(master_cpu)`, **`_mach_net_init`**, `_task_init` … `_miniMonInit`. 앞의 다섯 호출은 인자가 없다(직전 push 없음).
- Darwin `mach_init.c`:
  - :82 `machine_clock_init();` 다(원본 심볼표에 `_machine_clock_init` 없음, `_clock_timer_init` 0x187a40 있음).
  - `rqinit()` 가 없다(NeXTMach `mach_init.c:64` 에 있음, 원본 `_rqinit` 0x10ab88).
  - `mach_clock_bootstrap()` 가 없다(원본 `_mach_clock_bootstrap` 0x15c024, 어느 참조에도 없음).
  - :91 `printf("minimum quantum …")` 가 있다(원본에 없음).
  - `mach_net_init()` 은 `#if MACH_NET`(:77–79, :108–110) 안에 있다.
- `MACH_NET` 은 config 표에 없다(`mach_net.h` 생성 안 됨). C/H 사용은 `#if` 뿐이다(`#ifdef`·`defined` grep 0). 사용 파일은 ipc_kmsg·ipc_kobject·mach_net·mach_init 이고 모두 미채택이다(07 없음, 표 0). 원본이 `_mach_net_init` 을 부르므로 이 객체에서는 1 이다.

탐침(스테이징만):
- M0: 스테이징 덧붙임 `generated/mach_net.h` = `#define MACH_NET 1`(SHA 기록).
- M1(작성 D016, 원본 심볼 이름): :82 `machine_clock_init();` → `clock_timer_init();`.
- M2(복원 수정, NeXTMach :64): `sched_init();` 앞에 `rqinit();`.
- M3(작성): `vm_mem_init();` 뒤에 `mach_clock_bootstrap();`.
- M4(R1·R2): :91 `printf(...)` 삭제.
- 선언: 암시적 선언으로 호출만 한다(반환값 미사용, NeXTMach 관행). `machine_clock_init` 의 extern 선언이 있으면 그대로 둔다(코드 영향 없음).
- 예측: `__text` 원본 [0x15c828, 0x15c945) = 285 B(+ 끝 채움). L1 은 `_setup_main` MATCH 또는 data 의존이다. 변형 1/3.
- 채택은 다음 회차에 한다. 채택하면 MACH_NET 을 config 에 `hypothesis` 1 로 올리고 회귀를 돌린다.

### 110.1 codex 교차검토(QS30) 판정

내 확인(줄 출력): M1 :82, M2 는 :83 앞, M3 은 :85 뒤, M4 는 :91 이다. MACH_NET 블록은 :77–79(extern)·:108–110(호출)이다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 암시적 int 선언은 `void` 정의와 호환되지 않으므로 증거로 시그니처를 정해 명시 선언 | 두 함수의 정의는 참조 소스 어디에도 없어(grep 0) 반환형 근거가 없다. 원본 호출부에서 반환값을 쓰지 않는다(호출 뒤 `eax` 사용 없음, capstone) | ⚖️ 기각. 근거 없는 `void` 선언을 지어내지 않고, 이 객체의 코드는 선언과 무관하게 같다. 105.1 의 `utask_*` 와 같은 처리다. 위험은 증거에 기록한다 |
| MACH_NET=1 은 :77–79 의 extern 선언도 켠다 → 예측에 포함 | 줄 출력 | ✅ 선언은 코드 영향 없음. :108–110 의 호출이 원본과 맞는 부분이다 |

### 110.2 탐침 1 결과와 스테이징 보정

- `s5p84-probe-1`: `__text` 280/285, L1 BOUNDARY. 빌드에 `call _mach_net_init` 이 없다. mach_init.c 는 `<mach_net.h>` 를 include 하지 않는다(grep 0). 옵션 매크로는 `-imacros generated/meta_features.h`(H-meta)로 들어오는데, 덧붙인 `mach_net.h` 를 거기서 import 하지 않았다. **내 탐침 설계 누락**이다.
- 보정(탐침 2, 소스 변경 없음): 스테이징 `generated/meta_features.h` 에 `#import <mach_net.h>` 를 더한다. 이것은 채택 때 `gen_config_headers.py` 가 만들 상태와 같다(이름 정렬 위치). SHA 를 기록한다.

### 110.3 결과 (S5-P84, 2026-10-02) — 탐침 2: 285 B, 남은 차이 2 B(버전 상수)

- `s5p84-probe-2`(스테이징 `meta_features.h` sha `3348ebd6…`, `mach_net.h` `28dab78a…`): `__text` **285 B**(원본과 같음), `call _mach_net_init` 이 원본 자리에 생겼다.
- 남은 바이트 차이 2 곳(오프셋 96·106)은 `machine_info.major_version`·`minor_version` 이다. 원본 4·0, 빌드 5·3 이다.
  - Darwin `bsd/sys/version.h:79–80` 은 5·3, 실기 SDK `bsd/sys/version.h:49–50` 은 **4·0**, NeXTMach 은 2·0(tags 기록)이다.
  - 두 판의 주석 아닌 줄 차이는 이 두 정의뿐이다(diff).
- `bsd/sys/version.h` 를 읽은 빌드는 지금까지 mach_init 탐침 둘뿐이다(모든 `.i` 검색, Python).

## 111. S5-P85 세부 계획 — `kern/mach_init.c` 채택(MACH_NET·SDK version.h 포함) (코딩 전, 2026-10-02)

1. config: `mach_net` 행(macro `MACH_NET`, header `mach_net.h`, 값 1, `hypothesis`)을 추가한다. 근거는 원본 `_setup_main` 의 `call _mach_net_init`(0x15c8ac)과 Darwin `conf/files:56`·`MASTER:133` 이다. 사용은 `#if` 뿐이고 사용 파일은 모두 미채택이다. `gen_config_headers.py` 를 다시 돌리고 `--check` 한다. `meta_features.h` 는 탐침 2 스테이징과 바이트가 같아야 한다.
2. 회귀: 확정·부분 80 객체(s5p64 73 + vm_policy·vm_fault·vm_resident·vm_pageout·syscall_sw·task·mach_header, 각 최종 빌드 명령)를 새 생성 헤더로 다시 빌드한다. 기준은 각 최종 빌드 산출물 해시이고, 바이트 동일을 기대한다.
3. 07:
   - `src/kern/mach_init.c` = 탐침 2 본문 + `Modified` 주석.
   - `src/bsd/sys/version.h` = 실기 SDK `bsd/sys/version.h` 원문. 실기 SHA 목록과 대조하고, PROVENANCE `nextdev-os42`, license TBD(D017)로 적는다. D020 의 "객체별·바이트 근거" 선택이며, 사용 객체는 mach_init 하나다.
4. 빌드 `s5p85-build-1`. 예측: 탐침 2 와 같은 `.i` 구조에서 버전 상수만 바뀐다. L1 OBJECT_MATCH 1/1(O3 common 은 심볼 배치 여부를 본다).
   - 경계: 앞은 확정 mach_header 끝 0x15c827 + `00` 1 B, 뒤는 0x15c945–0x15c947 `00×3`(최소 3) 다음 `_fatfile_getarch` 0x15c948.
5. 판정 **A**. 표: functions +1(`_setup_main`, authored 표시), objects_confirmed +1, config +1 행, PROVENANCE(+mach_init.c, version.h, mach_net.h), MODIFICATIONS, 증거.

### 111.1 codex 교차검토(QS31) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| SDK `version.h` 를 공유 경로에 두면 이후 객체 모두에 적용됨 → D020 은 객체별 판단을 요구하므로 객체별 치환을 쓰라 | 원본 커널은 하나의 빌드다. `KERNEL_MAJOR/MINOR_VERSION` 은 같은 헤더에서 오고 객체마다 다를 수 없다. 지금 이 헤더를 읽는 객체는 mach_init 뿐이다(110.3, 모든 `.i` 검색). Darwin 판은 07 에 채택된 적이 없다 | ⚖️ 기각(공유 경로에 둔다). 다만 07 README·PROVENANCE 에 "D020 근거 객체: mach_init. 이 헤더를 새로 읽는 객체는 채택 때 `.i` 와 바이트로 다시 확인" 을 명시한다 |
| MACH_NET=1 은 mach_init 에 대한 가설로서 충분, 전역 사실 확정은 아님 | config 표의 `hypothesis` 의미(선례 norma_ether 등) | ✅ `hypothesis` 로 둔다 |
| 기준선은 같은 명령·입력으로 만든 해시여야 함 | s5p64 회귀 기준 73 + 각 최종 빌드(같은 cmd 줄을 그대로 씀) | ✅ 각 객체의 최종 빌드 cmd 줄을 그대로 회귀 cmd 에 넣고 기준은 그 산출 해시다 |
| `__data` 가 비어도 객체 전체(섹션 크기·재배치·심볼·common 크기와 정렬·경계)를 기록 | — | ✅ 증거 파일에 섹션 표·common(크기·정렬·간격)을 남긴다 |

### 111.2 결과 (S5-P85, 2026-10-02) — `mach_init.c` **A**

- config `mach_net` 행을 추가했다(27 행, hypothesis 1). `gen_config_headers --check` 를 통과했고, `meta_features.h`·`mach_net.h` 는 탐침 2 스테이징과 바이트가 같다.
- 회귀 `s5p85-regress-1`: 80 객체 / 86 명령 **모두 동일**(기준 `s5p85-regress-baseline.json` = s5p64 기준 + 7 객체 최종 빌드).
- 07: `src/kern/mach_init.c`(탐침 2 + `Modified`), `src/bsd/sys/version.h`(실기 SDK 원문, SHA 목록 일치).
- 빌드 `s5p85-build-1`: L1 O3·O3c OBJECT_MATCH(참조 43). `.i` 110 개 모두 07 에 있다.
- 표: functions +1, objects_confirmed +1(A), PROVENANCE +3, MODIFICATIONS +1, 증거·diff.

## 112. S5-P86 세부 계획 — 옵션 `MACH_DEBUG`·`HW_FOOTPRINT`·`NORMA_IPC` 진단 (코딩 전, 2026-10-02)

사실(grep, Python, srcdefs):
- 컴파일이 막힌 kern 파일(102.2): exception(`norma_ipc.h`), kernel_stack·thread(`mach_debug.h`), sched_prim·thread(`hw_footprint.h`), mach_net(`mach_net.h` — 111 에서 생성됨).
- 세 옵션 모두 Darwin `conf/files`(:38 `hw_footprint`, :43 `mach_debug`, :77 `norma_ipc`)·`MASTER`(:117·:122·:135)에 있고, C/H 사용은 모두 `#if` 다(`#ifdef`·`defined` 0 건).
- `MACH_DEBUG` 쪽 근거:
  - `#if MACH_DEBUG` 안에 정의된 함수 가운데 원본 심볼표에 있는 것: thread.c `stack_usage`·`stack_init`·`stack_finalize`·`stack_statistics`·`host_stack_usage`·`processor_set_stack_usage`·`thread_stats`, zalloc.c `host_zone_info`·`host_zone_free_space_info`.
  - 없는 것: zalloc `host_zone_collect` 하나.
  - 전역 `_stack_check_usage`·`_stack_max_usage`·`_stack_usage_lock` 도 원본에 있다(thread.c:110–118 의 `#if MACH_DEBUG` 블록).
  - 그래서 값은 1 로 본다. zalloc 그대로 빌드가 5685/7475 로 작았던 것도 같은 방향이다.
- `HW_FOOTPRINT`(sched_prim:1313–1338, thread:571–593)와 `NORMA_IPC`(exception:475–477)는 바이트로 정해야 한다. 07 채택 파일 중 이 셋을 쓰는 것은 `ipc_notify.c:385`(`#if NORMA_IPC`) 하나이고, 미정의(0) 상태로 A 다. 따라서 NORMA_IPC 0 이 일관된다.

진단(스테이징만, 07·config 변경 없음):
- 스테이징 하나에 덧붙임 `generated/mach_debug.h`(1)·`norma_ipc.h`(0)를 두고, `meta_features.h` 에 두 import 를 더한다(정렬 위치).
- `hw_footprint.h` 는 두 판(0·1)으로 스테이징을 둘 만든다.
- 대상: exception, kernel_stack, mach_net, sched_prim, thread, zalloc(재진단). 파일마다 kr_run 실행을 하나씩, O3c 1 명령으로 돌린다.
- 관찰: 컴파일 여부, 심볼 간격 비교, L1(102 절 방식, 요약 JSON). HW_FOOTPRINT 판정은 sched_prim/thread 두 판의 해당 함수(`thread_setrun`·`thread_create`) 바이트로 한다.
- 다음 단계: 결과에 따라 옵션 행을 추가하고 회귀를 돌린 뒤 객체별 채택 계획을 세운다.

### 112.1 codex 교차검토(QS32) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 심볼이 있다는 것만으로 MACH_DEBUG=1 은 이름. 원본 위치를 확인할 것 | Python: `_stack_usage`·`_stack_init`·`_stack_finalize`·`_host_stack_usage`·`_processor_set_stack_usage`·`_thread_stats` 는 thread 객체 범위 [0x166a5c,0x168ed4) 안, `_host_zone_info`·`_host_zone_free_space_info` 는 zalloc 범위, `_stack_statistics` 는 kernel_stack 범위 안이다. 모두 각 파일 끝의 `#if MACH_DEBUG` 블록 위치와 같다 | ⚖️ 강한 정황으로 보고, 확정은 진단 빌드의 바이트로 한다. `host_zone_collect` 부재는 후대 추가 가능성으로 기록한다(zalloc 진단에서 확인) |
| 스테이징 `meta_features` import 는 진단용일 뿐 | — | ✅ 채택 때 생성기로 만든다 |
| HW_FOOTPRINT 는 두 판이 서로 다른 바이트를 내야 판별 가능 | — | ✅ 해당 구간을 원본과 직접 비교한다 |
| NORMA_IPC=0 은 일관성 관찰이지 원본 사실이 아님 | — | ✅ exception 의 :475 분기 바이트로 판정한다 |

### 112.2 진단 결과 (S5-P86, 2026-10-02)

| 파일 | 결과 |
|---|---|
| kernel_stack | 컴파일 ✅. `__text` 2408/2408. 13 함수 중 3 MATCH, 9 MATCH_UNVERIFIED(`__bss` 만), 1 DIFF(`_initKernelStacks`) |
| zalloc | 컴파일 ✅. 7788/7475. 원본 전용 `zone_gc`·`consider_zone_gc`·`zone_reclaim`, 빌드 전용 5 개(`host_zone_collect` 포함), `zone_init` 72/1112 → 판(版) 차이가 큼, 보류 |
| exception | ❌ `exception.c:420` `ikm_sender` 없음(07 `ipc_kmsg.h` 는 원본 배치로 복원된 판) |
| sched_prim (hw0·hw1) | ❌ `sched_prim.c:1193` `sleep_time` 없음(07 `thread.h` 복원판) |
| thread (hw0·hw1) | ❌ `kernobjc.h`·`kernel_stack.h` 경로 없음(:64·:129) |
| mach_net | ❌ `mach_net.c:206` `MCLGET` 인자 수(BSD mbuf 매크로 판 차이) |

- 결론: MACH_DEBUG=1 은 kernel_stack 에서 `stack_statistics`(원본 심볼, kernel_stack 범위 안)가 생기고 크기가 같아진 것으로 뒷받침된다. HW_FOOTPRINT·NORMA_IPC 는 아직 판정할 바이트가 없다(sched_prim·thread·exception 컴파일 실패).
- kernel_stack `_initKernelStacks` 차이(오프셋 42·52·57): 원본은 `kernelStackBlock = 0x1000`, `(page_size + 0xfff) >> 12`, 빌드는 `0x2000`, `0x1fff`, `>> 13` 이다.
  - Darwin `kernel_stack.h:63` `KERNEL_STACK_SIZE = KERNSTACK_SIZE - sizeof(struct _kernelStack)`, `mach/i386/vm_param.h:71` `KERNSTACK_SIZE (2*I386_PGBYTES)` 이다.
  - NeXTMach `kern/kernel_stack.h:34` 는 `(4096 - sizeof(struct _kernelStack))` 다.

## 113. S5-P87 세부 계획 — `kern/kernel_stack.c` 탐침(스택 크기) (코딩 전, 2026-10-02)

- `KERNEL_STACK_SIZE`/`KERNSTACK_SIZE` 사용처(grep): 07 에서는 `mach/i386/vm_param.h:71`(정의)·`kern/kernel_stack.h:63`(정의)뿐이다. Darwin 에서는 kernel_stack.c·thread.c·machdep/i386/pcb.c 가 쓰고, 모두 미채택이다.
- E1(D014, NeXTMach 값): 스테이징 사본의 `src/mach/i386/vm_param.h:71` `(2*I386_PGBYTES)` → `(I386_PGBYTES)` 다. 대안은 `kernel_stack.h:63` 을 NeXTMach :34 형태로 바꾸는 것인데, `KERNSTACK_SIZE` 를 그대로 두면 i386 정의가 원본과 어긋난 채 남으므로 vm_param 쪽을 고친다.
- 진단 옵션: 스테이징은 112 의 hw0 판(MACH_DEBUG 1 등)이다.
- 예측: `_initKernelStacks` MATCH, 나머지는 `__bss` 의존 MATCH_UNVERIFIED → zerofill_check 로 판정(reference-inferred 면 P, 섹션이 단일 참조면 D019).
- 채택하려면 MACH_DEBUG 를 config 에 올리고 회귀(81 객체)가 필요하다. 이번에는 탐침까지만 한다.

### 113.1 codex 교차검토(QS33) 판정과 추가 근거

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 한 함수의 일치만으로는 공유 헤더 값이 증명되지 않음 | 두 번째 독립 근거(capstone): 원본 `_stack_attach` 0x18d21c 와 `_switch_context` 0x18d3d1 이 `add edx, 0xff4` 를 쓴다. 이는 Darwin `pcb.c:87`·`:181` 의 `stack + KERNEL_STACK_SIZE` 이고, 0xff4 = 4096 − 12(`sizeof(struct _kernelStack)`)다. Darwin 판이면 0x1ff4 가 된다 | ✅ 값 4096 이 서로 다른 두 객체에서 확인되었다 |
| `KERNEL_STACK_SIZE` 로 간접 사용하는 곳까지 확인 | 회귀 스테이징(81 소스 닫힘) 전체 grep: 사용처는 `machdep/ppc/thread.h:89` 뿐이고 i386 빌드는 읽지 않는다. 07 에서도 정의 외 사용 0 | ✅ 회귀로도 확인한다 |
| `INTSTACK_SIZE` 등은 `I386_PGBYTES` 에 의존, 값 변화 없음 | vm_param.h :71–72 | ✅ |

### 113.2 탐침 결과 (S5-P87, 2026-10-02)

- `s5p87-probe-1`(MACH_DEBUG 1 덧붙임 + 스테이징 `vm_param.h` `KERNSTACK_SIZE (I386_PGBYTES)`, diff `x86-vm_param_h-probe1.diff`): O3c `__text` 2408 B 차이 0, `__data` 113 B 는 0x1ded68 에 L1d 검증. 13 함수 = 3 MATCH + 10 MATCH_UNVERIFIED(`__bss` 만).
- zerofill(known s5p58): 참조 83, Δ 1 개, 후보 [0x1e5b98, 0x1e5ba8), 음성 검출 → **reference-inferred**(`s5p87-zerofill-check-kernel_stack-pre-20261002.json`).
- 이 후보의 시작 0x1e5b98 은 kalloc `k_zone_name`(단일 참조, [0x1e5a98, 0x1e5b98))의 끝과 맞붙는다. `__text` 순서도 kalloc(…0x15ab9b) 바로 다음이 kernel_stack(0x15ab9c)이다. D019 의 "이웃 확정으로 위치가 독립 고정되면 재판정" 조건 중 **끝 쪽**이 이웃으로 뒷받침된다. 앞 쪽(0x1e5a98 앞)은 아직이라 kalloc 재판정은 하지 않고 기록만 한다.
- 경계: 앞 0 B(kalloc 의 뒤 채움 `00` 이 0x15ab9b), 뒤 0 B(`_simple_lock_alloc` 0x15b504, 원본 심볼·Ghidra 시작).

## 114. S5-P88 세부 계획 — `kern/kernel_stack.c` 채택(MACH_DEBUG·KERNSTACK_SIZE) (코딩 전, 2026-10-02)

1. config: `mach_debug` 행(1, hypothesis)을 추가한다.
   - 근거: 112.1 의 원본 위치 대조(thread·zalloc·kernel_stack 범위 안의 `#if MACH_DEBUG` 함수들)와 kernel_stack 의 `stack_statistics` 바이트 일치.
   - `gen_config_headers` 로 다시 만들고 `--check` 한다.
   - `norma_ipc`·`hw_footprint` 는 근거가 없으므로 넣지 않는다.
2. 07 `src/mach/i386/vm_param.h:71` 을 `(I386_PGBYTES)` 로 바꾼다(복원 수정 D014). 근거는 원본 kernel_stack `0x1000` 과 pcb `0xff4` 두 곳(113.1)이다. MODIFICATIONS·PROVENANCE(`none (verbatim)` → restoration edit)·diff 를 남긴다.
3. 회귀: 81 객체(s5p85 80 + mach_init)를 새 생성 헤더·새 vm_param 으로 빌드해 기준과 같은지 본다.
4. 07 `src/kern/kernel_stack.c` = Darwin 원문 그대로. `.i` 표지 중 없는 파일은 원문 채택한다.
5. 최종 빌드 `s5p88-build-1`: O3·O3c·O2·`.i` 두 개. L1, 36.1(common 이 있으면), zerofill(known s5p58)을 한다.
   - 판정 **P**(`__bss` reference-inferred). 함수는 3 개 high, 10 개 medium. 새 알려진 범위 파일 s5p88(+1)을 만든다.

### 114.1 codex 교차검토(QS34) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 계획 수준의 오류·누락 없음, 등급은 최종 확인 조건부 | README:21·24 | ✅ |
| kalloc 재판정은 아직 아님(시작 쪽 근거 없음) | 113.2 | ✅ |

### 114.2 결과 (S5-P88, 2026-10-02) — `kernel_stack.c` **P**

- config `mach_debug` 1(hypothesis), 28 행이다. `gen --check` 를 통과했다. 07 `mach/i386/vm_param.h` `KERNSTACK_SIZE (I386_PGBYTES)` 에는 `Modified` 주석과 diff 가 있다.
- 회귀 `s5p88-regress-1`: 81 객체 / 88 명령 동일.
- 최종 `s5p88-build-1`: O3c = 탐침(`ae61855d…`). L1 3 MATCH + 10 MATCH_UNVERIFIED(`__bss`). 36.1 성립. zerofill reference-inferred [0x1e5b98, 0x1e5ba8). `.i` 90 개 모두 07 에 있다.
- 표: functions +13(high 3, medium 10), objects_partial +1(P), PROVENANCE +2 와 vm_param 행 수정, MODIFICATIONS +1, 알려진 범위 s5p88(17 개), 증거.

## 115. S5-P89 세부 계획 — thread·sched_prim 진단 2 (코딩 전, 2026-10-02)

사실(grep):
- Darwin `conf/MASTER.i386:72` RELEASE 태그 = `[intel pc mach medium event vol pst gdb kernobjc libdriver fixpri simple_clock mdebug kernserv driverkit uxpr kernstack ipc_compat ipc_debug … nbc]`.
  - `mdebug`(MACH_DEBUG, 114 에서 1 로 둠)·`kernstack`(KERNEL_STACK, `MASTER:187`)·`kernobjc`(KERNOBJC, `:185`)가 들어 있다.
  - `hw_foot`·`norma_ipc` 는 없다. 그래서 RELEASE 사전값은 HW_FOOTPRINT 0, NORMA_IPC 0 이다(기존 config 행들의 "RELEASE prior" 관행).
- 사용처: `KERNEL_STACK` 은 thread.c 뿐이고, `KERNOBJC` 는 init_main.c·kern_server.c·ppc 파일(모두 미채택)이다. 둘 다 `#if`/`#import <…h>` 형식이다(`#ifdef`·`defined` 0).
- thread.c:64 `#import <kernobjc.h>`, :129 `#import <kernel_stack.h>`, :130 `#if KERNEL_STACK` 다.
- 07 `kern/thread.h` 는 원본 배치로 복원된 판이라 `sleep_time` 이 없다(MODIFICATIONS `src/kern/thread.h` 행). Darwin thread.c:397·:1641–1643, sched_prim.c:1193–1195 가 이 필드를 쓴다.

진단(스테이징만): 112 의 hw0 스테이징 위에 덧붙임 `generated/kernobjc.h`(1)·`generated/kernel_stack.h`(1)를 두고 `meta_features.h` import 를 더한다. thread.c·sched_prim.c 를 빌드한다(O3c).
- 예상: thread 는 `sleep_time` 에서 실패한다. 실패하면 그 오류 목록을 기록하고, 다음 계획에서 원본 바이트로 각 사용처를 판정한다(원본 `thread_template` 초기화·`thread_info` basic_info·`update_priority` 에 해당 저장이 있는지).

### 115.1 codex 교차검토(QS35) 판정: RELEASE 목록은 사전값으로만, 진단 설계 타당 — 내 계획과 같다(✅). 원본 `sleep_time` 배치는 바이트로 확인한다.

### 115.2 진단 결과와 116 계획(thread·sched_prim 탐침 1, 코딩 전)

- `s5p89-pre-thread`·`s5p89-pre-sched-prim`: 옵션 헤더 문제는 풀렸다. 남은 오류는 07 `thread.h` 에 없는 `sleep_time` 뿐이다(thread.c:397·:1643, sched_prim.c:1193·:1195).
- 참조:
  - Mach4 `kern/sched_prim.c:1131–` `update_priority` 에는 `sleep_time` 블록이 없다(:1140 `assert` 다음 바로 주석).
  - Mach4 `kern/thread.c:1544–1546`·NeXTMach `kern/thread.c:1823–1825` 의 `thread_info` 는 `basic_info->sleep_time = sched_tick - thread->sched_stamp;` 다.
  - 원본 thread 배치(07 thread.h 복원 근거)에 이 필드가 없으므로, 이것들이 원본과 맞는 판일 가능성이 높다. 바이트로 확인한다.

## 116. S5-P90 세부 계획 — thread.c·sched_prim.c 탐침 1 (코딩 전, 2026-10-02)

스테이징 `s5p89-pre-stage-1` 사본 위에서:
- S1(sched_prim, Mach4 형태, D014): :1192–1196(`if … sleep_time += …; else … = 0;` 와 뒤 빈 줄)을 지운다.
- T1(thread): :397 `thread_template.sleep_time = 0;` 을 지운다.
- T2(thread, Mach4 :1546·NeXTMach :1825): :1643 `basic_info->sleep_time = thread->sleep_time;` → `basic_info->sleep_time = sched_tick - thread->sched_stamp;`.
- 빌드는 O3c 두 파일이다. 관찰: 컴파일, 심볼 간격 비교(원본 sched_prim seq 190 35 함수, thread seq 194 42 함수), L1 이다. 다음 계획 후보 순위를 정한다(채택 없음).

### 116.1 codex 교차검토(QS36) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `sched_tick - sched_stamp` 는 누적 `sleep_time` 과 의미가 다를 수 있음 → 원본 동작으로 확인 | — | ✅ 의미 동등성은 주장하지 않는다. 탐침의 `_thread_info` 바이트가 판정한다 |
| `struct thread` 에 그 필드가 남아 있으면 템플릿 초기화 삭제는 오류 | `s5p89-pre-thread` 오류 "structure has no member named `sleep_time`"(thread.c:397) — 07 `thread.h` 에 필드가 없다 | ❌ 해당 없음(필드 자체가 없다) |

### 116.2 탐침 1 결과 (S5-P90, 2026-10-02)

- `s5p90-probe-thread`·`s5p90-probe-sched-prim` 모두 컴파일된다(diff `x86-thread-probe1.diff`·`x86-sched_prim-probe1.diff`).
  - thread: 9184/9336, 42 함수 중 간격 같은 것 36.
  - sched_prim: 10097/9725, 35 함수 중 27. `__data` 차이 135 B.
- thread 차이(정규화 diff, `08_build/…/scratchpad` 도구로 비교):
  - `_thread_init`: 원본은 템플릿 +0x7c·+0x80 에 0 을 더 저장한다. 07 thread.h 배치상 `tmp_address`·`tmp_object` 이고 NeXTMach `thread.c:590–591` 과 같다.
  - `_thread_create`: 원본은 u-area 할당 뒤 `call _uarea_zero(thread)`·`call _uarea_init(thread)` 를 한다(원본 심볼 0x106dcc·0x106db4). NeXTMach :710·:712 와 같다.
  - `_thread_deallocate`: 원본은 `tmp_address` 가 있으면 `kmem_free`, `tmp_object` 가 있으면 `vm_object_deallocate` 를 한다(NeXTMach :923–926). 원본에는 Darwin :715 `thread->depress_priority = -1;`(빌드 `mov [esi+0x64],-1`)이 없다.
  - `_reaper_thread` 12/24: 원본은 `reaper_thread_continue()` 만 부른다. Darwin :1809 `current_thread()->vm_privilege = TRUE;` 가 없다.
  - `_thread_info` 520/544: Darwin :1605–1611 `#if SIMPLE_CLOCK` 드리프트 보정(`* 1000000 / sched_usec`)이 원본에 없다.
  - `_thread_halt` 796/688: 구조 차이가 크다(다음 탐침 뒤 따로 본다).
- **SIMPLE_CLOCK 충돌**: config 는 `simple_clock 1 hypothesis` 다(근거: `_sched_usec_elapsed` 0x160714 존재, Darwin 은 그 함수를 `#if SIMPLE_CLOCK` 안에 둠). 반대 근거는 다음과 같다.
  - 원본 심볼표에 `_sched_usec` 가 없다(Darwin `sched_prim.c:99–101` 이 `#if SIMPLE_CLOCK` 아래 정의).
  - thread_info 에 보정이 없다.
  - sched_prim 의 `_sched_init` 228/168, `_recompute_priorities` 432/52 차이가 Darwin :226–228·:1146–1162 의 SIMPLE_CLOCK 블록과 맞아떨어질 가능성이 있다(탐침으로 확인).
  - 07 에서 SIMPLE_CLOCK 을 쓰는 곳은 `kern/sched.h:174–181` 의 extern 선언뿐이다(코드 영향 없음).

## 117. S5-P91 세부 계획 — thread·sched_prim 탐침 2 (SIMPLE_CLOCK 0 + NeXTMach 줄) (코딩 전, 2026-10-02)

탐침 1 스테이징 사본 위에서:
- C0: 스테이징 `generated/simple_clock.h` 를 `#define SIMPLE_CLOCK 0` 으로 둔다(07·config 는 그대로, 비교용).
- T3(NeXTMach :590–591): :391 `thread_template.vm_privilege = FALSE;` 뒤에 `thread_template.tmp_address = (vm_offset_t) 0;`·`thread_template.tmp_object = VM_OBJECT_NULL;`.
- T4(NeXTMach :710·:712): :494 `new_thread->_uthread = …zalloc(u_thread_zone);` 뒤에 `uarea_zero(new_thread);`·`uarea_init(new_thread);`(정확한 위치는 원본 호출 순서 — `zalloc` 결과 저장 직후 — 와 맞춘다).
- T5(NeXTMach :923–926): `thread_deallocate` 의 `pset_deallocate(pset);`(:737) 뒤, `task_unlock` 다음 자리에 tmp 정리 4 줄. 위치는 NeXTMach 순서를 따른다.
- T6(R1·R2): :715 `thread->depress_priority = -1;` 삭제.
- T7(R1·R2): :1809 `current_thread()->vm_privilege = TRUE;` 삭제.
- 예측: thread 의 `_thread_init`·`_thread_create`·`_thread_deallocate`·`_reaper_thread`·`_thread_info` 간격이 원본과 같아지고, `_thread_halt` 만 남는다. sched_prim 은 `_sched_init`·`_recompute_priorities` 차이가 줄어드는지 본다.

### 117.1 codex 교차검토(QS37) 판정 → 설계 보정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| C0 만 바꾼 비교를 먼저 해야 옵션 효과를 분리할 수 있음 | — | ✅ 탐침 2a(C0 만)와 2b(C0+T3–T7)로 나눈다 |
| `_sched_usec_elapsed` 존재는 SIMPLE_CLOCK=1 의 증명이 아님 | config 근거 칸에도 "body differs from Darwin" 이 있다 | ✅ config 값은 2a·2b 결과와 mach_clock 확인 전까지 그대로 둔다 |
| T4 는 NeXTMach 의 `u_address.uthread`/`utask` 선행 대입에 기댐 → 사전조건 확인 필요 | 탐침 스테이징 thread.c :494–497 에 Darwin 자신의 주석 처리된 줄이 있다: `new_thread->_uthread = … zalloc(u_thread_zone);` / `//	uarea_zero(new_thread);		/* XXX */` / `//	uarea_init(new_thread);`. 원본 호출 순서(zalloc → 저장 → `_uarea_zero` → `_uarea_init`)와 같다 | ⚖️ T4 를 "Darwin :496–497 의 주석 해제" 로 바꾼다(Darwin 판 텍스트, 출처가 더 가깝다). helper 의 의미는 주장하지 않는다 |
| T6·T7 근거는 제시 범위 밖이라 미확인, 예측이 과함 | T6 = Darwin :715(줄 출력), T7 = :1809(줄 출력). 근거는 원본 바이트(116.2) | ✅ 함수별 결과를 따로 기록한다 |

### 117.2 탐침 2a·2b 결과 (S5-P91, 2026-10-02)

- 2a(SIMPLE_CLOCK 0 만):
  - thread `_thread_info` 544 → 512(원본 520).
  - sched_prim `_sched_init` 228 → 220(원본 168), `_recompute_priorities` 432 → 396(원본 52).
  - 따라서 SIMPLE_CLOCK 블록은 원본에 없는 쪽과 맞는다. 다만 sched_prim 에는 그 밖의 차이가 남는다.
- 2b(2a + T3–T7): thread 42 함수 중 39 개 간격이 같다. 남은 것은 `_thread_deallocate` 732/740, `_thread_info` 512/520, `_thread_halt` 688/796 이다.
- **내 오류(T6)**: 원본 `_thread_deallocate` 에도 `reset_timeout` 뒤 `mov [esi+0x64], 0xffffffff`(`depress_priority = -1`)가 있다. 정규화 비교에서 큰 상수가 N 으로 가려져 있었다. 탐침 1 diff 에서 그 줄이 빌드 쪽에만 보인 것은 위치가 어긋났기 때문이다. T6 은 철회한다.
- `_thread_info`: 원본은 `policy == 2 || policy == 4` 를 검사한다. 07 `mach/policy.h` 에서 `POLICY_FIXEDPRI` 2, `POLICY_INTERACTIVE` 4 이고, NeXTMach `thread.c:1847–1851` 이 `#if NeXT` 아래 `|| thread->policy == POLICY_INTERACTIVE` 를 둔다(빌드에 `-DNeXT`).
- `_thread_halt`: 원본 호출에는 `_clear_wait` 뒤 `_mach_msg_interrupt`·`_splsched`·`_splx` 가 더 있다. 이는 Mach4 `thread.c:1071–1089` 의 continuation 정리 블록이다(Darwin 에서 지워짐).
  - 쓰는 이름은 모두 원본 심볼이다: `_mach_msg_continue` 0x153f34, `_mach_msg_receive_continue`, `_mach_msg_interrupt`, `_thread_exception_return`, `_thread_bootstrap_return`.
  - Darwin `ipc/mach_msg.h` 에는 `mach_msg_continue` 선언이 없다(Mach4 `ipc/mach_msg.h:56–57` 에 있음).

## 118. S5-P92 세부 계획 — thread 탐침 3 (코딩 전, 2026-10-02)

2b 스테이징 사본 위에서:
- T6 되돌림: `thread->depress_priority = -1;` 복원.
- T8(NeXTMach :1847–1851): Darwin :1670 `if (thread->policy == POLICY_FIXEDPRI) {` 를 NeXTMach 의 여러 줄 조건(`#if NeXT … #endif NeXT` 포함)으로 바꾼다.
- T9(Mach4 :1071–1089): `thread_halt` 의 `if (thread->state & TH_HALTED) { return KERN_SUCCESS; }` 뒤에 Mach4 블록(주석 포함)을 넣는다.
- H1(Mach4 `ipc/mach_msg.h:56–57`): 스테이징 `src/ipc/mach_msg.h` 의 `mach_msg_receive_continue();` 선언 뒤에 `extern void` / `mach_msg_continue();` 를 넣는다. 선언만 하므로 다른 객체 코드에는 영향이 없다(채택 때 회귀로 확인).
- 예측: thread 42/42 간격 같음, L1 은 data 의존을 빼면 MATCH 다. SIMPLE_CLOCK 0 은 스테이징 유지다(config 결정은 sched_prim 정리와 mach_clock 확인 뒤).

### 118.1 codex 교차검토(QS38) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| T9 이름(`THREAD_INTERRUPTED`·`AST_HALT`·`thread_ast_clear`)이 Darwin 쪽에 있는지 확인 | 07 `kern/sched_prim.h:72`, `kern/ast.h:76`·`:151` | ✅ |
| T8 `#if NeXT` 는 `-DNeXT` 로 참, 공유 헤더 선언 추가 무방(정의와 일치 확인) | Darwin `ipc/mach_msg.c:763` 이 `mach_msg_continue` 를 함수로 쓴다(원본 `_mach_msg_continue` 존재) | ✅ |
| 채택 때 바이트 대조·출처 기록 필요 | — | ✅ 채택 계획에서 |

### 118.2 탐침 3 결과 (S5-P92, 2026-10-02) — thread O3c **OBJECT_MATCH 42/42**

- `s5p92-probe-thread`(diff `x86-thread_c-probe3.diff`·`x86-mach_msg_h-probe3.diff`): `__text` 9336 B 차이 0, `__data` 심볼 배치 차이 0.
- 옵션(스테이징): MACH_DEBUG 1(config), KERNOBJC 1, KERNEL_STACK 1, **HW_FOOTPRINT 0**, **SIMPLE_CLOCK 0**, NORMA_IPC 0(thread 는 읽지 않음).
  - HW_FOOTPRINT 0 은 `_thread_create` 가 `#if HW_FOOTPRINT` 의 `last_processor` 대입 없이 일치한 것이 근거다.
  - SIMPLE_CLOCK 0 은 `_thread_info` 일치가 근거다(+117.2 의 sched_prim 방향).

## 119. S5-P93 세부 계획 — `kern/thread.c` 채택 (코딩 전, 2026-10-02)

사실: 객체 [0x166a5c, 0x168ed4) 9336 B, 42 함수.
- 앞 0 B: 확정 `x86-task` 의 gap_after `2 x 00` 다음이 0x166a5c 다.
- 뒤 0 B: `_swapper_init` 0x168ed4 다.

1. config:
   - 추가: `kernobjc` 1, `kernel_stack` 1, `hw_footprint` 0(모두 hypothesis, 근거 = 위 + RELEASE 태그).
   - 변경: `simple_clock` 1 → **0**(hypothesis). 근거는 원본 `_sched_usec` 부재, `_thread_info` 바이트, sched_prim 진단 방향이다. 반대 근거 `_sched_usec_elapsed` 존재는 "원본 mach_clock 판이 SIMPLE_CLOCK 과 무관하게 이 함수를 둔 것으로 보임(mach_clock 미채택, 그때 다시 확인)" 으로 기록한다.
   - `norma_ipc` 는 근거가 없어 넣지 않는다.
   - `gen --check` 를 한다.
2. 07:
   - `src/ipc/mach_msg.h` 는 Darwin 원문 + Mach4 `ipc/mach_msg.h:56–57` 선언 2 줄이다(복원 수정, CMU 고지 파일).
   - `src/kern/thread.c` 는 탐침 3 본문 + `Modified` 주석이다.
3. 회귀: 82 객체(s5p88 81 + kernel_stack O3/O3c). 기대는 전부 동일이다(SIMPLE_CLOCK 0 이 sched.h extern 선언만 바꾸는지 확인하는 것이 핵심).
4. 최종 빌드 `s5p93-build-1` 에서 L1 O3c 와 36.1(O3)을 확인한다. 경계는 0/0, `.i` 채택 검사. 판정은 **A**(조건 충족 시). 표: functions +42, objects_confirmed +1, PROVENANCE(thread.c·mach_msg.h·생성 헤더 3), MODIFICATIONS 2(thread.c 의 NeXTMach·Mach4 출처 줄 번호 포함), 증거.

### 119.1 codex 교차검토(QS39) 판정과 통제 탐침

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| SIMPLE_CLOCK 1→0 은 가설 갱신으로 정당, 사용자 결정은 불필요. 다만 양쪽 근거를 모두 남길 것 | — | ✅ config 근거 칸에 찬반을 모두 적는다 |
| KERNOBJC·KERNEL_STACK 은 값별 근거가 없음 | 통제 탐침 `s5p93-ctl-thread-ks0`(KERNEL_STACK 0): thread 가 10256 B 가 되고 빌드 전용 `_stack_alloc_try`·`_stack_alloc`·`_stack_free`·`_stack_collect`·`_stack_statistics` 가 생긴다(원본에서는 kernel_stack 객체에 있음, 113.2) | ✅ KERNEL_STACK 1 은 바이트 근거가 있다. KERNOBJC 는 thread.c 가 헤더를 import 만 하고 값을 쓰지 않으므로(grep) RELEASE 사전값 1, "바이트 근거 없음" 으로 적는다 |
| SIMPLE_CLOCK 의 sched_prim·mach_clock 영향은 회귀만으로 못 정함 | — | ✅ sched_prim(미채택)은 다음 작업으로, mach_clock 은 채택 때 다시 확인한다고 기록 |

### 119.2 결과 (S5-P93, 2026-10-02) — `thread.c` **A**

- config 31 행이다(kernobjc·kernel_stack·hw_footprint 추가, simple_clock 0 으로 변경, 찬반 근거 기록). `gen --check` 를 통과했다.
- 07: `kern/thread.c`(탐침 3 + `Modified`), `ipc/mach_msg.h`(Darwin + Mach4 선언).
- 회귀 `s5p93-regress-1`: 82 객체 / 90 명령 동일.
- 최종 `s5p93-build-1`: O3c = 탐침 3, L1 OBJECT_MATCH 42/42(참조 458), 36.1 성립, `.i` 110 개 모두 07 에 있다.
- 표: functions +42, objects_confirmed +1(A), PROVENANCE +5, MODIFICATIONS +2, 증거·diff.

## 120. S5-P94 세부 계획 — sched_prim 탐침 2 (Mach4 타이머 형태) (코딩 전, 2026-10-02)

사실(`s5p94-probe-sched-prim`: 현재 07 config + S1, capstone 이름 붙임):
- 35 함수 중 27 개 간격이 같다. 차이 8 개 가운데 셋은 원본 호출 구조로 설명된다.
  - `_recompute_priorities`(원본 52 B): `sched_tick++`, `set_timeout(&recompute_priorities_timer, hz)`, `if (sched_thread_id) clear_wait(sched_thread_id, 0, 0)`. Mach4 `kern/sched_prim.c:1098–1120` 과 같다(SIMPLE_CLOCK 0). Darwin 판은 static 틱 카운터 방식이다(:1145–1170).
  - `_sched_init`(원본 168 B):
    - `recompute_priorities_timer.fcn = recompute_priorities; .param = 0`(Mach4 :171–172).
    - `call _init_timeout_element(&recompute_priorities_timer)` — 참조에 없다.
    - `min_quantum = hz / 10`(Mach4 :174).
    - 그다음 wait_queue 초기화(인라인), `pset_sys_bootstrap`, action 큐, `sched_tick = 0`, `ast_init`.
    - Darwin :205–219 의 `default_preemption_rate` 계산이 원본에 없다.
  - `_thread_timeout_setup`(원본 72 B): 각 타이머의 fcn·param 대입 뒤 `init_timeout_element(&thread->timer)`·`init_timeout_element(&thread->depress_timer)` 를 부른다. 참조(Darwin·Mach4 :224–231)에는 대입만 있다.
- 원본 심볼: `_recompute_priorities_timer` 0x1f66e0 와 `_min_quantum` 이 있다. `_default_preemption_rate` 의 존재는 grep 결과로 판단한다(위 출력).
- 나머지 차이(`_thread_invoke`·`_sched_thread_continue`·`_do_runq_scan`·`_do_thread_scan`·`_thread_select`, `__data` 135 B)는 이번 탐침 뒤 따로 본다.

탐침 2(스테이징만):
- P1(Mach4 :86): `timer_elt_data_t recompute_priorities_timer;` 를 `min_quantum` 선언 뒤에 둔다.
- P2(Mach4 :171–174 + 작성): `sched_init` 의 :205–219 를 Mach4 두 줄 + `init_timeout_element(&recompute_priorities_timer);`(작성 D016, W3 표시) + `min_quantum = hz / 10;` 으로 바꾼다.
- P3(Mach4 :1098–1120): `recompute_priorities` 본문을 Mach4 형태로 바꾼다. static 카운터와 `recompute_priority_ticks = hz;` 를 지우고 `set_timeout(...)` 을 넣는다.
- P4(작성): `thread_timeout_setup` 의 각 타이머 대입 뒤에 `init_timeout_element(&thread->timer);`·`init_timeout_element(&thread->depress_timer);` 를 넣는다(W3).
- `default_preemption_rate` 정의(:93–94)는 원본 심볼 유무에 따라 남기거나 지운다. 지울 경우 `__data` 차이로 확인한다.
- 예측: 위 세 함수 간격 일치. 변형 1/3.

### 120.1 codex 교차검토(QS40) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| Darwin 의 `init_timeout_element` 는 `mach_clock.c` 안의 `static __inline__ void` 라 sched_prim 에서 부를 수 없음 → 보이는 선언 필요 | Darwin `mach_clock.c:232–233`(위 sed). 원본에는 전역 `_init_timeout_element` 0x15bda8 이 있다(mach_clock 범위, 미채택) | ✅ sched_prim.c 에 `extern void init_timeout_element(timer_elt_t);` 선언을 둔다(형은 Darwin 정의에서, `static __inline__` 대신 extern — 작성 D016, W3) |
| 호출 지점은 작성, helper 본문을 쓰면 별도 출처 기록 | 본문은 mach_clock 객체 몫이다(이번 범위 밖) | ✅ |

### 120.2 탐침 2 결과와 121 계획(sched_prim 탐침 3, 코딩 전)

- `s5p94-probe2-sched-prim`(diff `x86-sched_prim-probe2.diff`): `_sched_init`·`_thread_timeout_setup` 간격이 같아졌다. 재배치 밖 바이트까지 같은 함수는 29/35 이다(Python 비교).
- 남은 6 개:
  - `_recompute_priorities` 388/52: 빌드가 `clear_wait` 를 인라인한다. 원본은 `call _clear_wait` 다. `_clear_wait` 자체는 크기·바이트가 같다. 원인은 아직 모른다(GCC 인라인 판단) — 별도 조사.
  - `_sched_thread_continue` 184/196: 원본은 `if (sched_tick & 1) do_thread_scan();` 다(Mach4 `sched_prim.c` 의 같은 함수, 위 grep 줄).
  - `_do_runq_scan` 296/304: 원본은 `sched_tick - thread->sched_stamp > 1`(`sub; cmp 1; jbe`)이다. Mach4 와 같고, Darwin 은 `thread->sched_stamp != sched_tick` 다.
  - `_thread_select` 340/336: 원본은 `if (pset->runq.count == 0)` 만 검사한다. Darwin 의 `|| pset->runq.high < thread->sched_pri` 가 없다(Mach4 형태의 조건, 필드 이름은 Darwin 의 `high` 유지 — 다른 함수들이 Darwin run_queue 의미로 일치하므로).
  - `_thread_invoke`·`_do_thread_scan` 은 다음 탐침 뒤 다시 본다.

## 121. 탐침 3 편집(스테이징만, D014 R1·R2, Mach4 출처)

- S2: `|| pset->runq.high < thread->sched_pri` 를 지운다(조건을 `pset->runq.count == 0` 으로).
- S3: `do_thread_scan();` 앞에 `if (sched_tick & 1)` 을 둔다.
- S4: `thread->sched_stamp != sched_tick` → `sched_tick - thread->sched_stamp > 1`.
- 예측: 세 함수 간격이 같아진다.

### 121.1 codex 교차검토(QS41) 판정: S2 는 앞 줄 끝의 `||` 까지 두 줄을 바꿔야 함(✅, 줄 582–583 을 `if (pset->runq.count == 0) {` 로). S3·S4 오류 없음. 추가로 내가 확인: `thread->sched_stamp != sched_tick` 은 :598(thread_select, 대상 아님)과 :1940(do_runq_scan) 두 곳이고, S4 는 :1940 만 바꾼다.

### 121.2 탐침 3 결과와 122 계획(sched_prim 탐침 4, 코딩 전)

- `s5p95-probe-sched-prim`(diff `x86-sched_prim-probe3.diff`): `_thread_select`·`_do_runq_scan`·`_do_thread_scan` 의 간격이 같아졌다. 남은 것은 `_thread_invoke` 1016/1028, `_recompute_priorities` 388/52(인라인), `_sched_thread_continue` 192/196, `__data` 135 B 다.
- `_sched_thread_continue`: 원본은 `thread_invoke` 뒤 `splx` 다음에 `jmp` 로 처음으로 돌아간다. Mach4 의 `while (TRUE) { … }` 형태다. Darwin 은 끝에서 반환한다.
- `_thread_invoke`(capstone, 원본 0x1636cb·0x1639be):
  - 원본은 `stack_handoff` 직전과 `switch_context` 직전(`c_thread_invoke_csw++` 앞)에 `push esi; call _switch_unix_context` 를 둔다. 이 함수는 어느 참조에도 없고, 선례 `ipc_sched.c:350–351` 의 작성분과 같다.
  - `stack_handoff` 앞에 `old_thread->swap_func = continuation;`(Darwin :717)이 없다. Mach4 :684–685 처럼 `thread_lock(old_thread);` 뒤에 있다.
  - 원본 default 분기는 `panic("thread_invoke")` 만 한다(문자열 0x1df564, `printf` 없음 = Mach4 :735–736). Darwin :780–781 의 `printf` 가 없다.

## 122. 탐침 4 편집(스테이징만)

- S5(Mach4 형태): `sched_thread_continue` 본문을 `while (TRUE) { … }` 로 감싼다. 들여쓰기만 바꾸고 문장은 유지한다(Darwin 의 `thread_block_with_continuation(sched_thread_continue);` 그대로).
- S6(Mach4 :684–685): :717 `old_thread->swap_func = continuation;` 을 :729 `thread_lock(old_thread);` 뒤로 옮긴다.
- S7·S8(작성 D016, W3, 선례 ipc_sched): `stack_handoff(old_thread, new_thread);` 앞과 `counter_always(c_thread_invoke_csw++);` 앞에 `switch_unix_context(new_thread);`. 선언은 선례처럼 두지 않는다(암시적, 원본 함수 0x106e0c, 반환값 미사용).
- S9(Mach4 :735–736): :780–781 `printf(...)` 두 줄을 지운다.
- 예측: `_thread_invoke`·`_sched_thread_continue` 간격 일치. recompute 인라인과 `__data` 는 남는다.

### 122.1 codex 교차검토(QS42) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| S5 의 의미 동등 주장은 근거 없음(Mach4 는 `thread_block`, Darwin 은 `thread_block_with_continuation`) | 원본 `_sched_thread_continue` 에서 인라인된 블록 경로(`thread_select` → `thread_invoke` → `splx`) 뒤에 처음으로 가는 `jmp` 가 있다(121.2 diff) | ⚖️ 의미 주장은 하지 않는다. 목적은 원본 바이트 재현이며 탐침이 판정한다 |
| S6 은 동작을 바꿈(`stack_handoff` 뒤에 대입) | 원본 0x1636cb–0x1636d3 에서 `stack_handoff` 앞에 `[ebx+0x34]` 저장이 없다 | ✅ 원본 순서를 재현하는 의도된 변경이다(MODIFICATIONS 에 명시) |

### 122.2 탐침 4 결과와 123 계획(통제 탐침, 코딩 전)

- `s5p96-probe-sched-prim`(diff `x86-sched_prim-probe4.diff`): 35 함수 중 34 개 간격이 같다. 남은 것은 `_recompute_priorities` 388/52(`clear_wait` 인라인) 하나다.
- `__data` 차이는 1 바이트다(오프셋 0). 빌드는 `_default_preemption_rate`(=100, Darwin :94)를 오프셋 0 에 두는데, 원본 심볼표에는 그 이름이 없다(grep 0). 원본 0x1df51c–0x1df51f 는 `00×4` 이고 문자열 `assert_w…` 는 0x1df520 에서 시작한다(Python). 따라서 변수를 지우면 문자열·`_wait_shift`(오프셋 104→100, 원본 0x1df584)가 원본 위치와 맞는다. sched_init 복원(120) 뒤 이 변수의 사용처는 없다(grep).
- 인라인 가설: Darwin `conf/MASTER.i386:81` `makeoptions CCONFIGFLAGS = "-g -O3 -fno-omit-frame-pointer" # <gdb>` 이고, RELEASE 태그에 `gdb` 가 있다. GCC 2.7 의 인라인 판단은 RTL 크기(디버그 노트 포함)에 기대므로, `-g` 가 경계선의 `clear_wait` 인라인을 막았을 수 있다.

## 123. 통제 탐침 (스테이징 = 탐침 4 + S10)

- S10(R1·R2): :94 `int default_preemption_rate = DEFAULT_PREEMPTION_RATE;` 삭제(#define 은 유지).
- 같은 스테이징으로 두 명령을 돌린다. (a) 지금 플래그의 O3c, (b) 같은 플래그 + `-g` 의 O3c.
- 관찰: (a) 에서 `__data` 가 맞는지. (b) 에서 `_recompute_priorities` 가 52 B 가 되고 다른 함수가 바뀌지 않는지(재배치 밖 바이트 비교).
- (b) 가 맞으면, 확정 객체 전체(83 개)에 `-g` 를 넣은 회귀로 기존 일치가 유지되는지 따로 확인한다. 유지되지 않거나 일부만 맞으면 "원본 빌드 플래그" 결정이 필요하다 → 사용자 판단 대상일 수 있다.

### 123.1 통제 탐침 결과 (S5-P97, 2026-10-02) — `-g` 가 인라인 차이를 설명

- `s5p97-ctl-1`(S10 포함):
  - (a) `-g` 없음: `__data` 521 B 차이 0(S10 확인). `_recompute_priorities` 는 여전히 388 B 다.
  - (b) `-g`: `__text` **9725 B = 원본**. L1 은 34 MATCH + 1 DIFF(`_thread_select`, 92 B, 정렬 nop 위치만), `__data` 일치다.
- 해석:
  - `-g` 는 GCC 2.7 의 인라인 판단(RTL 크기)을 바꿔 `clear_wait` 를 인라인하지 않게 한다.
  - 원본 RELEASE 구성의 `gdb` 태그(`-g -O3 -fno-omit-frame-pointer`, `MASTER.i386:81`)와 맞는다.
  - 지금까지 확정된 객체는 모두 `-g` 없이 일치했으므로, `-g` 가 그 객체들을 바꾸지 않는지 확인해야 한다.
- `_thread_select` 차이: 앞부분 기본 블록 정렬 위치만 다르다. Darwin :558 은 `thread = current_thread()` 를 함수 시작에서 하고, Mach4 :514·:533 은 `count == 0` 분기 안에서 한다.

## 124. S5-P98 세부 계획 — `-g` 회귀와 thread_select 변형 2 (코딩 전, 2026-10-02)

1. `-g` 회귀: s5p93 회귀 명령 90 개(82 객체) + kernel_stack O3/O3c + thread O3/O3c 의 각 명령에 `-g` 를 넣고 다시 빌드한다. 기준은 각 최종 빌드다. 비교는 바이트 해시가 아니라 섹션 내용으로 한다(`-g` 는 stab 심볼·문자열이 늘어 파일 해시가 반드시 달라진다). 섹션별 크기·바이트·재배치가 같은지를 Python 으로 본다. 객체마다 "섹션 동일 / 다름" 을 기록한다.
   - 모두 동일하면 원본 빌드 플래그를 `-g -O3`(RELEASE `gdb`)로 보는 가설이 성립하고, sched_prim 은 `-g` 로 빌드한다.
   - 일부가 다르면 객체별 플래그가 갈린다는 뜻이고 **사용자 결정 사항**(빌드 플래그 기준)으로 보고한다.
2. thread_select 변형 2(Mach4 :514·:533): :558 을 `register thread_t thread;` 로 바꾸고, `if (pset->runq.count == 0) {` 블록의 주석 뒤에 `thread = current_thread();` 를 둔다. `-g` 판으로 빌드한다.

### 124.1 codex 교차검토(QS43) 판정 → 회귀 설계 보정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `-g` 가설이 그럴듯할 뿐 원본이 `gdb` 구성이었다는 증명은 아님 | `MASTER.i386:81–82` 는 `<gdb>`/`<!gdb>` 조건부다. RELEASE 태그에는 `gdb` 가 있다 | ✅ 가설로 기록한다 |
| 디버그 전용 섹션·stab 은 비교에서 빼고, 추가된 비디버그 섹션은 보고 | — | ✅ |
| 재배치는 `symbolnum` 이 아니라 해석된 대상(심볼 이름·섹션·오프셋)으로 비교 | — | ✅ extern=이름, local=섹션 번호, scattered=값과 PAIR 를 비교한다 |
| 차이가 곧 객체별 플래그를 뜻하지는 않음 → 달라진 객체는 원본과 L1 로 다시 판정, 필요 플래그가 객체 간 충돌할 때만 사용자 결정 | — | ✅ 트리거를 이렇게 좁힌다 |
| `gdb` 구성의 `-fno-omit-frame-pointer` 도 넣을 것 | `MASTER.i386:81` | ✅ 회귀 플래그는 `-g … -fno-omit-frame-pointer`(각 명령의 기존 -O 수준 유지) |

### 124.2 `-g` 회귀 결과 (S5-P98, 2026-10-02)

- `s5p98-gregress-1`: 83 객체 / 92 명령을 각 명령의 -O 수준 그대로 두고 `-g … -fno-omit-frame-pointer` 를 더해 빌드했다.
- 기준(각 최종 빌드)과 비교한 항목: 비디버그 섹션의 크기·바이트, 재배치(주소·폭·pcrel·유형·해석된 대상), 비-stab 심볼(이름·종류·값).
- 결과 **92/92 동일**(`09_validation/reconstruction/s5p98-gregress-compare-20261002.json`).
- 결론:
  - `-g -fno-omit-frame-pointer`(RELEASE `gdb` 구성)는 지금까지의 모든 확정 객체와 모순되지 않는다.
  - sched_prim 은 이 플래그로만 원본과 맞는다(123.1).
  - 그래서 "원본 빌드는 `gdb` 구성(-g)" 을 가설로 채택한다(08_build 기록 대상). 객체 간 플래그 충돌이 없으므로 사용자 결정 사항이 아니다(124.1 트리거 미충족).

### 124.3 탐침 5 결과 (S5-P98, 2026-10-02) — sched_prim **OBJECT_MATCH 35/35**(`-g`)

- `s5p98-probe-1`(thread_select 변형 2 = Mach4 :514·:533 배치, `-g … -fno-omit-frame-pointer`): `__text` 9725 B·`__data` 521 B 모두 차이 0, 35 MATCH.

## 125. S5-P99 세부 계획 — `kern/sched_prim.c` 채택과 표준 플래그에 `-g` 반영 (코딩 전, 2026-10-02)

사실(Python):
- 객체 [0x162d80, 0x16537d) 9725 B, 35 함수.
  - 앞: `_kdp_reset` 몸체 끝 `c3` 0x162d7d(Ghidra) 다음 `00 00` 2 B = 4 정렬 최소 채움이다.
  - 뒤: `00×3` 다음 `_swtch_continue` 0x165380 이다(최소 3).
- 수정 요약:
  - S1(sleep_time, Mach4), P1–P4(Mach4 타이머 + 작성 `init_timeout_element` 선언·호출 3), S2–S4(Mach4 조건), S5(Mach4 while 루프), S6(swap_func 위치, Mach4), S7·S8(작성 `switch_unix_context`), S9(printf 삭제, Mach4), S10(`default_preemption_rate` 삭제), thread_select 변형 2(Mach4).
  - 옵션은 config 그대로다(SIMPLE_CLOCK 0, HW_FOOTPRINT 0).

절차:
1. 표준 빌드 명령: 이후 최종 빌드는 `-g … -fno-omit-frame-pointer` 를 쓴다. 근거는 124.2 의 92/92 와 123.1 이다. `08_build/GCC27_COMPATIBILITY.md` 에 "원본 빌드 플래그 가설: RELEASE gdb 구성" 한 줄을 더하고, 템플릿 `08_build/runs/tools/s5p99-build.cmd` 를 새로 만든다.
2. 07 `src/kern/sched_prim.c` = 탐침 5 본문 + `Modified`. 헤더 변경이 없으므로 회귀는 필요 없다.
3. 최종 빌드 `s5p99-build-1`: O3·O3c(`-g`)·O2·`.i` 두 개. L1 O3c OBJECT_MATCH, 36.1(O3), `.i` 검사, 경계.
4. 판정 **A**. 표: functions +35, objects_confirmed +1, PROVENANCE +1, MODIFICATIONS +1(Mach4·작성 줄 출처), 증거.

### 125.1 codex 교차검토(QS44) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 이후 최종 빌드의 `-g` 전환은 정당, 단 "원본 = gdb 구성" 은 가설로 표기 | 124.2 | ✅ |
| 이미 채택된 객체의 build 칸은 실제 실행 명령 그대로 두고 메모로 충분 | — | ✅ 회귀 근거 파일을 메모에 연결 |
| A 는 최종 빌드·L1·`.i`·경계 확인 뒤에만 | — | ✅ |
| Mach4 에서 가져온 텍스트의 고지를 파일 안에 유지, 07 README 의 빌드 명령도 갱신 | Mach4 `kern/sched_prim.c` 고지는 Darwin 판과 같은 CMU 1993–1987 문안이다. Mach4 `kern/thread.c` 는 "1994-1987" 로 연도만 다르다(sed 비교). 07 README 에는 빌드 명령이 없고 GCC27 문서를 가리킨다 | ✅ 두 파일에 Mach4 출처·고지 주석을 넣는다(thread.c 는 주석만 추가 → 재빌드로 동일 확인). GCC27 문서 "툴체인 고정" 과 07 README 에 플래그 가설 한 줄을 넣는다 |

### 125.2 결과 (S5-P99, 2026-10-02) — `sched_prim.c` **A**

- 템플릿 `08_build/runs/tools/s5p99-build.cmd`(`-g … -fno-omit-frame-pointer`)를 만들었다. GCC27 문서와 07 README 에 플래그 가설을 기록했다.
- 최종 `s5p99-build-1`:
  - sched_prim O3c OBJECT_MATCH 35/35(참조 487), 36.1 성립. `.i` 114 개 중 없던 `kern/power.h`·`mach/error.h` 는 원문 그대로 채택했다.
  - thread(Mach4 고지 주석 추가)는 `-g` 판도 OBJECT_MATCH 42/42 다.
- 표: functions +35, objects_confirmed +1(A), PROVENANCE +3, MODIFICATIONS +2, 증거·diff.

## 126. S5-P100 세부 계획 — `-g` + 현재 config 로 미채택 후보 일괄 재진단(채택 없음) (코딩 전, 2026-10-02)

계기: `-g` 는 GCC 2.7 의 인라인 판단을 바꾼다(123.1). 지금까지 "크기 다름" 으로 남은 후보 중 일부는 인라인 차이였을 수 있다. 그 사이 config 도 바뀌었다(MACH_NET 1, MACH_DEBUG 1, KERNEL_STACK 1, SIMPLE_CLOCK 0 등).

대상(Darwin 원문, 07 우선 스테이징, 102·91 의 구간 seq 그대로):
- vm: vm_kern(206)·vm_map(207)·vm_unix(215).
- kern: ast(154)·exception(155)·ipc_kobject(158)·ipc_mig(159)·mach_clock(170)·mach_fat(174)·mach_loader(175)·mach_net(176)·mapfs(179)·miniMon(180)·ns_timer(181)·power(184)·kdp(188)·kdp_udp(189)·syscall_subr(191)·zalloc(198).

설계(102.1 규칙 유지):
- 파일마다 kr_run 실행 1 개(`s5p100-pre-<이름>`)를 돌린다. 명령은 s5p99 템플릿의 O3c 1 줄(`-g`)이다.
- 요약 JSON 에 간격 같음/다름, 빌드·원본 전용, 마지막 함수 잠정 표시, L1 판정, 이전 결과(102.2·91.2) 대비 변화를 적는다.
- 컴파일 실패는 첫 오류만 적는다.
- 판정·채택은 하지 않는다. 다음 대상은 "차이가 가장 적은 것" 순으로 고른다.

### 126.1 codex 교차검토(QS45) 판정: 이전 결과와의 차이를 `-g` 탓으로 돌릴 수 없음(config 도 바뀜, ✅ — 이번 진단은 후보 순위용이며 원인 귀속은 하지 않는다), O3c 만이라 다른 변형 결론은 아님(✅), 구간은 추정이므로 마지막 함수·간격은 잠정(✅, 102.1 과 같음).

### 126.2 재진단 결과 (S5-P100, 2026-10-02)

- `s5p100-pre-*`(`-g` O3c, 요약 `09_validation/reconstruction/s5p100-pre-summary-20261002.json`): 컴파일 15·실패 4(vm_unix `cputypes.h`, exception `norma_ipc.h`, ipc_kobject `ikm_sender`, mach_net `MCLGET` 인자). 102.2·91.2 와 간격 결과는 사실상 같다.
- static 이 많은 모듈(kdp·mach_loader·miniMon·kdp_udp·mach_fat·ns_timer·mapfs)은 원본 전역 심볼 하나로 `__text` 를 놓고(`--place`) L1 을 돌렸다(`s5p100-place-l1-*`). 함수 대부분이 DIFF 로, Darwin 판과 원본 판의 차이가 크다. 보류한다.
- vm_map(seq 207): 29 함수 중 25 간격이 같다.
  - 빌드 전용 `_vm_map_find_entry`·`_vm_map_reallocate`·`_host_vm_region` 은 원본 심볼표에 없다(grep 0).
  - `host_vm_region` 은 `#if MACH_DEBUG` 안이고, MACH_DEBUG 1 이라 생겼다. 원본의 다른 MACH_DEBUG 함수와 달리 없다 → 후대 추가로 본다.
  - `_vm_region` 688/1348: 원본 호출(`lock_read`·`lock_done`·`lock_read`·`vm_object_name`·`lock_done`·`vm_object_name`·`lock_done`)과 `kernel_map` 비교 없음이 NeXTMach `vm_map.c:2419–` 형태와 맞는다(서브맵 분기는 `*object_name = PORT_NULL`). Darwin 은 서브맵 재귀 블록과 `VM_OBJECT_NAME` 매크로를 둔다.
  - `_vm_map_find` 880/424: 원본은 `vm_map_insert` 를 인라인한다. `_vm_map_insert` 380/392 도 다르다(NeXTMach `temp_entry` 형태 후보).

## 127. S5-P101 세부 계획 — vm_map 탐침 1 (코딩 전, 2026-10-02)

스테이징(07 우선 + `-g` 템플릿)에서 Darwin `vm/vm_map.c` 를 고친다(D014 R1·R2, NeXTMach D013):
- V1: `vm_map_find_entry`(주석 :587 부터 `}` :744 와 뒤 빈 줄까지)를 지운다.
- V2: `vm_map_reallocate`(:1564–1671 과 뒤 빈 줄)를 지운다.
- V3(NeXTMach :2419–): `vm_region` 을 다음과 같이 바꾼다.
  - 지역 `inaddress` 와 `again_after_submap:` 레이블을 지운다.
  - `VM_OBJECT_NAME` 매크로·`#undef` 를 지우고 `vm_object_name(…)` 을 직접 쓴다.
  - 서브맵 분기를 NeXTMach 의 세 줄(`*is_shared = FALSE; *object_name = PORT_NULL; *offset_in_object = tmp_offset;`)로 바꾼다. 필드 이름은 Darwin(`vme_*`)을 유지한다.
- V4: `#if MACH_DEBUG` 의 `host_vm_region` 블록(`#include <kern/host.h>` 포함, 끝 `#endif` 는 Python 으로 확정)을 지운다.
- 예측: `_vm_region` 688. 빌드 전용 함수는 없어진다. `vm_map_insert`/`vm_map_find` 는 아직 다를 수 있다(다음 변형에서 NeXTMach `temp_entry` 형태).

### 127.1 codex 교차검토(QS46) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| V1–V4 범위 오류 없음. V3 은 매크로 연속줄(:2819)과 서브맵 분기의 `goto`·잠금 정리를 함께 바꿔야 | Darwin :2818–2819, :2839–2867 줄 출력 | ✅ 분기 전체를 바꾼다 |
| `host_vm_region` 은 MIG 서버 생성물이 참조할 수 있음 | 원본 심볼표에 `_host_vm_region` 이 없다(grep 0) → 원본 서버도 참조하지 않았다. MIG 서버는 아직 미채택 | ✅ 기록, 서버 채택 때 확인 |
| 다른 파일의 `vm_map_find_entry`/`vm_map_reallocate` 호출 | 07 전체 grep 0 건. Darwin `vm_kern.c:104·186`(미채택, 원본 vm_kern 은 `vm_map_find` 를 부름 — 102 절), `vm_user.c:200`(07 판에서 이미 제거) | ✅ |

### 127.2 탐침 1 결과와 128 계획(vm_map 탐침 2, 코딩 전)

- `s5p101-probe-vm-map`(diff `x86-vm_map-probe1.diff`): 15653/16833 B. `_vm_region` 은 688 로 같아졌다. 빌드 전용 함수는 없다. 남은 것은 `_vm_map_insert` 392/380, `_vm_map_find` 424/880, `_vm_map_copy` 3852/4588 이다.
- 호출 비교:
  - `vm_map_find`·`vm_map_copy` 의 원본 호출은 빌드의 `call _vm_map_insert` 자리에 `vm_map_lookup_entry`·`vm_object_coalesce`·`zalloc`·`panic` 이 오는 것을 빼면 같다. 즉 원본은 `vm_map_insert` 를 인라인한다.
  - `_vm_map_insert` 정규화 diff: 원본은 `prev_entry` 를 레지스터에 두고 스택은 4 B 만 쓴다(`sub esp,4`). 빌드는 8 B 다. NeXTMach `vm_map.c:321–350`(`register prev_entry`, 지역 `temp_entry` 로 조회한 뒤 `prev_entry = temp_entry;`)과 맞는다. Darwin 은 `&prev_entry` 로 주소를 넘긴다.

## 128. vm_map 탐침 2 편집(스테이징만, NeXTMach D013/D014)

- I1: `vm_map_insert` 의 지역 선언 두 줄을 NeXTMach :328–330(`register` 두 개 + `vm_map_entry_t temp_entry;`)으로 바꾼다.
- I2: `if (vm_map_lookup_entry(map, start, &prev_entry))` 를 `&temp_entry` 로 바꾸고, `return(KERN_NO_SPACE);` 뒤에 빈 줄과 `prev_entry = temp_entry;` 를 둔다(NeXTMach :347–350).
- 예측: `_vm_map_insert` 380, 그리고 인라인 판단이 바뀌어 `_vm_map_find` 880·`_vm_map_copy` 4588 이 될 수 있다. 다른 차이(VM_PROT_ALL 대 DEFAULT 등)는 바이트로 확인한다.

### 128.1 codex 교차검토(QS47) 판정: I1/I2 오류 없음(✅). 이후 `&prev_entry` 사용 여부는 범위 밖이라 미확인 → 내가 함수 전체를 grep 해 `vm_map_lookup_entry(map, start, &prev_entry)` 한 곳뿐임을 확인(위 출력)했다.

### 128.2 탐침 2 결과 (S5-P102, 2026-10-02)

- `s5p102-probe-vm-map`(diff `x86-vm_map-probe2.diff`): `__text` **16833 B = 원본**, 28 MATCH + 1 MATCH_UNVERIFIED. `__data` 161 B 는 0x1e0a73 에서 L1d 로 검증된다.
- 남은 미검증 1: `_vm_map_fork` 의 `_kprintf` 참조. 원본은 `call _printf`(0x177e2f)이고 원본 심볼표에 `_kprintf` 는 없다. NeXTMach `vm_map.c:1983` 이 같은 문장을 `printf(…)` 로 쓴다. Darwin 은 :2288 `kprintf(…)` 다.

## 129. S5-P103 세부 계획 — `vm/vm_map.c` 채택 (코딩 전, 2026-10-02)

- K1(NeXTMach :1983): Darwin :2288 `kprintf` → `printf`.
- 07 = 탐침 2 + K1 + `Modified` 주석. 머리말 아래에 NeXTMach 출처 메모를 둔다(NeXTMach `vm_map.c` 고지는 CMU 문안, 파일 머리 확인 후 그대로 인용).
- 최종 빌드 `s5p103-build-1`(s5p99 `-g` 템플릿). 예측: O3c OBJECT_MATCH 29/29.
- 경계: 앞 0x174600 은 확정 `x86-vm_kern`? — 아니다. vm_kern 은 미채택이다. 원본 바이트로 앞뒤 채움을 계산한다. 뒤는 0x1787c1–0x1787c3 `00×3`(최소 3), 다음은 확정 `x86-vm_mem_region` 0x1787c4 다.
- 판정·표: functions +29, objects_confirmed +1, PROVENANCE·MODIFICATIONS·증거.

### 129.1 codex 교차검토(QS48) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 앞 경계가 미계산 | Ghidra: `_kmem_free_wakeup` 몸체 `[0x1745b4, 0x1745ff]`, 0x1745ff 는 `c3`. 0x174600 은 4 정렬(Python) | ✅ 앞 0 B(직전 ret = `_kmem_free_wakeup` 끝, vm_kern 미채택)로 기록 |
| O3 의 36.1 과 `.i` 검사가 빠짐 | — | ✅ 최종 빌드에서 수행 |
| NeXTMach 고지는 CMU 문안과 별도로 1985 Tevanian/Young 저작권이 있음 | NeXTMach `vm_map.c:1–11` | ✅ 두 고지를 모두 파일 안에 인용 |

### 129.2 결과 (S5-P103, 2026-10-02) — `vm_map.c` **A**

- 07 = 탐침 2 + K1(`printf`) + `Modified` 주석 + NeXTMach 고지 두 개.
- 최종 `s5p103-build-1`(`-g`): O3c OBJECT_MATCH 29/29(참조 355), 36.1 성립, `.i` 50 개 모두 07 에 있다.
- 표: functions +29, objects_confirmed +1(A), PROVENANCE +1, MODIFICATIONS +1, 증거·diff.

## 130. 현황과 사용자 판단 요청 (2026-10-02)

이번 연속 작업(112–129)의 채택:
- kernel_stack(P).
- thread·sched_prim·vm_map(A).
- config: MACH_DEBUG 1, KERNOBJC 1, KERNEL_STACK 1, HW_FOOTPRINT 0, SIMPLE_CLOCK 1→0.
- 빌드 플래그 가설 `-g … -fno-omit-frame-pointer`(83 객체 회귀 동일).

남은 후보의 막힘(조사 결과):
1. **BSD 의존**(pcb·ast·unix_*·bsd/ 파일·exception 의 `ikm_sender`·mach_net 의 `MCLGET`): D020(BSD 기준 = NeXTMach)을 실제로 적용할 방식이 정해지지 않았다. 83.3 에서 본 대로 이름 단위 대체는 proc → user → types 로 번지고, 이미 채택된 Darwin 헤더(`sys/types.h` 등)와 부딪친다.
2. **대량 작성 필요**: vm_kern 의 static 도우미와 `kmem_alloc` 계열(참조에 없는 혼합 구조), kdp·kdp_udp·mach_loader·miniMon·ns_timer·mapfs(Darwin 판과 거의 모든 함수가 다름). W1 의 "최후 수단" 을 넓게 쓰게 된다.
3. 그 밖: zalloc(원본 전용 함수 3·빌드 전용 5), power(옛 callout API), ipc_mig(`mach_msg` 이식 필요).

사용자 판단이 필요한 것: 1 의 BSD 헤더 적용 방식, 2 의 대량 작성 허용 범위.

## 131. S5-P104 세부 계획 — D021(BSD 헤더 묶음 교체) 1 단계: 설계와 실현성 진단 (코딩 전, 2026-10-02)

사용자 결정 D021: BSD 헤더는 묶음째 NeXTMach/SDK 판으로 교체하고, 이후 기준은 NeXTMach/SDK 로 한다. Darwin 은 구조 참고용이다.

사실(Python):
- 실기 전처리 조사 `s5p104-preproc-1`: 확정·부분 객체 85 소스를 현재 플래그로 `-E` 했다. 그중 67 개가 `src/bsd/` 헤더 58 개를 읽는다(`09_validation/reconstruction/s5p104-bsd-header-use-20261002.json`).
  - 많이 쓰이는 것: `sys/cdefs.h` 67, `machine/ansi.h` 67, `sys/types.h`·`machine/types.h`·`i386/types.h`·`machine/endian.h`·`i386/endian.h`·`machine/byte_order.h` 66.
  - 나머지는 1–13 개 객체가 쓴다.
- 같은 이름이 있는 곳:
  - SDK(`/NextDeveloper/Headers/bsd/…`, include 계열은 `ansi/`): 44 개.
  - NeXTMach(`sys/`·`net/`·`netinet/`, machine 은 68k `next/`): 33 개.
  - **둘 다 없음 13 개**: `i386/param.h`, `i386/spl.h`, `libkern/libkern.h`, `libkern/strtol.c`, `machine/ansi.h`, `machine/byte_order.h`, `net/radix.h`, `sys/ioccom.h`, `sys/queue.h`, `sys/select.h`, `sys/syslimits.h`, `sys/ttycom.h`, `sys/ttydefaults.h`(Darwin/4.4BSD 쪽 이름).
- 이미 아는 제약(83.1): SDK 헤더 일부는 커널 부분이 빠져 있다(`sys/ux_exception.h`, `sys/callout.h` 의 `#if NeXT` 구조체, `sys/kernel.h` 의 `boottime` 등). NeXTMach 의 `machine` 은 68k `next/` 를 가리킨다.

설계 제안(이번 회차는 진단만, 07 변경 없음):
1. `stage_headers.py --bsd-set nextos`(새 옵션, `--nextdev` 필수): 논리 경로 `src/bsd/**` 를 Darwin·07 사본 대신 다음 순서로 해석한다.
   - (a) SDK `bsd/<경로>`(`include/X` 는 SDK `ansi/X`·`bsd/X`). machine 계열은 SDK `bsd/machine` → ARCH_INCLUDE → `bsd/i386`.
   - (b) SDK 판이 없거나 "커널 부분 누락" 목록에 있으면 NeXTMach `sys/`·`net/`·`netinet/`.
   - (c) 둘 다 없으면 **해석하지 않음**(Darwin 으로 돌아가지 않는다). 컴파일 실패로 드러나게 한다.
   - 실기 SHA 와 NeXTMach 커밋 대조는 `--subst` 와 같은 검증 함수를 재사용한다. 기본 동작은 그대로 두고 회귀로 확인한다.
   - "커널 부분 누락" 목록은 처음에는 83.1 의 세 파일로 시작해 진단 결과로 넓힌다. 각 항목에 근거를 남긴다.
2. 진단 실행: 85 소스를 이 모드로 O3c 컴파일한다(`-g` 템플릿). 결과를 세 가지로 나눈다.
   - (i) 컴파일되고 기존 최종 빌드와 비디버그 내용이 같은 객체.
   - (ii) 컴파일되나 내용이 다른 객체.
   - (iii) 컴파일 실패(첫 오류와 원인 헤더).
3. 다음 회차: (iii)·(ii) 의 원인별로 소스 쪽 include 정리(NeXTMach 구조 기준, Darwin 구조는 참고)나 헤더 선택 규칙 보정을 계획한다. 07 반영(묶음 교체)은 모든 확정 객체가 다시 일치하거나 그렇지 않은 객체의 처리가 정해진 뒤에 한다.

### 131.1 codex 교차검토(QS49) 판정 → 설계 보정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| SDK bsd 헤더가 `mach/`·`kernserv/`·`architecture/` 를 끌어오는데, 지금 해석기는 그 이름을 Darwin/07 에서 먼저 찾음 → 이름공간 정책과 `.i` 추적 필요 | SDK `bsd/**/*.h` 의 꺾쇠 include(Python): `sys` 129, 최상위 45, `bsd/` 28, `mach` 24, `architecture` 24, `kernserv` 13, `rpc` 10, `machine` 9 … | ✅ 정책 명시(아래) |
| SDK 파일을 `src/bsd` 논리 경로에 두면 인용 include 해석이 바뀔 수 있음 | SDK bsd 헤더 중 인용 include 를 쓰는 것은 `dev/hppa/BasicConsole.h` 하나(i386 빌드와 무관) | ⚖️ 사실상 영향 없음. 기록만 한다 |
| `#import` 의 한 번만 포함은 경로 기준이라, 같은 파일이 두 논리 이름(`src/bsd/X` 와 `nextdev/bsd/X`)으로 들어오면 중복 정의 위험 | SDK 헤더는 `<bsd/machine/…>` 처럼 `bsd/` 접두 이름도 쓴다(28 건) | ✅ 진단에서 중복 정의 오류를 별도 분류하고, `.i` 에서 같은 SHA 의 파일이 두 경로로 들어왔는지 Python 으로 검사 |
| 07 의 수정된 bsd 사본이 사라질 위험 | PROVENANCE: `07_kernel/src/bsd/` 58 행 모두 `none (verbatim)` | ❌ 해당 없음(복원 수정 0). 교체 때는 58 개 사본을 명시적으로 물리고 기록한다 |
| (i)/(ii)/(iii) 는 분류일 뿐, 원본 대비 판정·원인 기록이 필요 | — | ✅ (ii)·(iii) 는 원인별로 기록하고, (i)도 원본 L1 을 다시 돌린다 |

이름공간 정책(D021 범위):
- BSD 이름(`src/bsd/**` 논리 경로와 SDK 의 `bsd/…` 접두 이름)은 SDK → NeXTMach 순으로 해석한다. Darwin 이나 07 사본으로 되돌아가지 않는다.
- 비-BSD 이름(`mach/`·`kern/`·`vm/`·`ipc/`·`kernserv/`·`architecture/`·`machdep/`·`driverkit/`·생성 헤더)은 지금처럼 07(바이트로 확인된 판) → Darwin → SDK 순이다. SDK bsd 헤더가 이 이름을 include 하면 07 판이 쓰이고, 그 사실은 `.i` 표지와 manifest 로 남는다.
- D021 이 비-BSD 헤더까지 바꾸라는 뜻인지는 정하지 않는다. 이번에는 BSD 만 바꾼다. 비-BSD 의 SDK 교체가 필요해 보이면 그때 사용자에게 묻는다.

### 131.2 codex 교차검토(QS50) 판정 → 구현 규칙

- ✅ 정규화: `bsd/X`(SDK 접두 이름)와 `nextdev/bsd/X`(SDK bsd 루트로 찾은 이름)는 모두 논리 `src/bsd/X` 로 바꾼다. 실기 컴파일러도 `bsd/X` 를 `-Isrc/src` 아래 `src/src/bsd/X` 에서 찾으므로, 스테이징 위치와 컴파일러 해석이 같다.
- ✅ NeXTMach 대체는 `load_subst` 의 커밋 blob 대조를 함수로 떼어 재사용한다. manifest 에 커밋·경로·SHA 를 남긴다.
- ✅ 기본 동작 동일성: 옵션 없이 85 소스 스테이징을 옛/새 도구로 만들어 트리·manifest 를 비교한다.
- ✅ 해석 못 한 BSD 이름은 `unresolved` 에 `bsd_set: true` 로 따로 표시한다.

### 131.3 진단 2 결과(`s5p105-bsd-diag-2`, 2026-10-02)

명령 96 개(`08_build/runs/tools/s5p105-bsd-diag2.cmd`, 스테이징 `s5p105-bsd-stage-1`), 기록 `09_validation/reconstruction/s5p105-bsd-diag2-20261002.json`:
- (i) 86 개: 기존 최종 빌드(`s5p98-gregress-1`)와 비디버그 내용이 같다.
- (iii) 8 개 실패, 원인 3 가지:
  - 6 개(ddm·vm_pageout·mach_init 의 O3/O3c): SDK `bsd/machine/spl.h:11` 이 `ARCH_INCLUDE(bsd/, spl.h)` → `bsd/i386/spl.h` 를 찾는데 SDK 에 그 파일이 없다(SDK `bsd/i386/` 11 개 중 없음, 있는 것은 `kernserv/i386/spl.h`). NeXTMach 은 68k `next/spl.h` 뿐.
  - dma: `dma_inline.h:45` 의 `#import <bsd/i386/param.h>` — SDK·NeXTMach 모두 그 이름이 없다. OPENSTEP 4.2 SDK 에서 i386 의 같은 역할은 `bsd/i386/machparam.h`(`sys/param.h:48` → `machine/machparam.h`). `dma_inline.h` 가 거기서 쓰는 것은 `DELAY`(58 행) — SDK `machparam.h` 와 Darwin `param.h` 의 정의가 같다(`us_spin(n)`, `KERNEL` 일 때).
  - fp_support: `RB_NOFP` 미선언. SDK `bsd/i386/reboot.h` 는 "Empty file (publicly)" 주석만 남은 판이고, Darwin 판과 비교하면 저작권 머리말·끝 주석 외 차이는 `#ifdef KERNEL_PRIVATE` 블록(RB_POWERDOWN … RB_PRETTY 9 개) 하나뿐이다 → SDK 는 그 블록을 뺀 공개판으로 보인다. 원본 바이트: `0x18a333` `f6 05 36 26 1e 00 20` = `testb $0x20, _boothowto+2`(`_boothowto` 0x1e2634) → `RB_NOFP` = 0x00200000 확인.
- (ii) 2 개(`O3__vm_machdep.o`, `O3__kdp_machdep.o`): `__text`·`__const`·`__data` 바이트와 재배치는 기준과 같고, 새 `__DATA,__common` zero-fill 섹션(496 B, 934 B)과 그 정의 심볼(`_buf`, `_bufhash`, `_bfreelist`, `_swbuf` …; `_mbutl`, `_ifnet`, `_ipq`, `_mbstat` …)이 생겼다. 원인: SDK `bsd/sys/buf.h:110–120` 등이 커널 전역을 `extern` 없이(잠정 정의) 선언한다. NeXTMach `sys/buf.h:99–103` 도 같다. Darwin 판은 `extern`.
  - 원본에서 이 심볼들은 모두 `__DATA,__common`(섹션 6)에 있다(`_bfreelist` 0x1e8760, `_buf` 0x1e8870, `_bufhash` 0x1e8880, `_ifnet` 0x1e89e0, `_mbstat` 0x1e9160, `_swbuf` 0x1e8b0c …). `_nbuf` 만 `__data`(0x1e289c).

## 132. S5-P106 세부 계획 — D021 2 단계: 실패 3 원인 수정과 잠정 정의 처리 (코딩 전, 2026-10-02)

원칙(D021): NeXTMach/SDK 기준, Darwin 은 구조 참고. SDK·NeXTMach 둘 다 없는 비공개 이름은 **원본 바이트로 확인된 내용만** 작성(authored)하고 Darwin 문장을 들여오지 않는다.

1. 비공개 헤더 층 `07_kernel/nextdev_private/`(새 디렉터리): `--bsd-set nextos` 에서 BSD 이름을 찾을 때 **SDK 보다 먼저** 본다. 이 층의 파일은 모두 작성 파일이고 PROVENANCE 에 근거를 남긴다. 처음 두 개:
   - `bsd/i386/spl.h`: 가드 + `#import <kernserv/i386/spl.h>` 만(SDK `kernserv/i386/spl.h` 가 spl 함수 선언을 가진다; 구조는 Darwin `bsd/i386/spl.h` 와 같다고 기록). 함수 본문이 없으므로 바이트 근거는 "그 헤더를 쓰는 객체가 원본과 다시 일치" 로 대신한다.
   - `bsd/i386/reboot.h`: SDK 판 본문 + `#ifdef KERNEL_PRIVATE` 블록에 `RB_NOFP 0x00200000` **하나만**(원본 0x18a333). 나머지 8 개 플래그는 바이트 근거가 생길 때 넣는다.
2. `dma_inline.h:45` 의 `#import <bsd/i386/param.h>` → `#import <bsd/i386/machparam.h>`(OPENSTEP 4.2 SDK 이름). Darwin 트리 `bsd/i386/` 에는 `machparam.h` 가 없어(18 개 중 없음) 지금 07 을 고치면 기본 모드 빌드가 깨진다 → **07 은 이번에 고치지 않는다**. 진단 3 에서는 스테이징 사본에만 Python 으로 한 줄을 바꾸고(바꾸기 전·후 SHA 와 바뀐 줄을 기록) 07 반영은 묶음 교체 단계에서 MODIFICATIONS 와 함께 한다.
3. 잠정 정의(common) 문제 — 원본 빌드가 `-fno-common` 이었는지가 걸린다:
   - E1 실기 링크 실험(커널 무관, 작은 probe): `int x;` 를 둔 a.c·b.c 를 (a) `-static -fno-common`, (b) `-static`(common) 으로 컴파일하고 각각 `ld -static -r` 와 `ld -static -e _main`(최소 진입점) 으로 링크. (a) 가 "multiple definitions" 로 실패하면, SDK/NeXTMach 의 잠정 정의 헤더를 여러 객체가 쓰는 한 `-fno-common` 커널은 링크되지 않는다 → 원본은 common 빌드였다는 근거(Darwin 은 헤더를 `extern` 으로 바꾸고 `-fno-common` 을 넣었다).
   - E2: vm_machdep·kdp_machdep 를 SDK 헤더로 O3c(`-fno-common` 없음) 빌드 → 36.1 절차(O3c OBJECT_MATCH, common 크기 ≤ 원본 간격).
   - 최종 빌드 플래그에서 `-fno-common` 을 뺄지는 E1·E2 결과로 다음 회차에 판단한다(이번엔 기록만).
4. 진단 3: 1·2 를 반영한 스테이징으로 96 명령 + E2 2 개를 다시 돌려 (i)/(ii)/(iii) 를 다시 센다. 기대: (iii) 0.
5. 이번 회차에 07 의 Darwin bsd 사본 58 개는 건드리지 않는다(묶음 교체 반영은 다음 단계).

### 132.1 codex 교차검토(QS51) 판정 → 구현 규칙

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 덮어쓰기 층은 타당. `canonical()` 이 SDK 별칭을 `src/bsd/X` 하나로 모은다 | `stage_headers.py:100–107` 열어 확인 | ✅ |
| manifest 코드가 BSD 선택을 SDK 아니면 NeXTMach 로만 다룸 → 작성 파일이 `verify_nextmach` 로 감 | `stage_headers.py:332–342`: `hit[1]=='sdk'` 아니면 `verify_nextmach` | ✅ 'authored' 갈래 추가, SHA·근거 문서를 manifest 에 기록 |
| `#import` 중복 방지는 컴파일러 경로 기준 → `.i` 에서 실제 경로 확인 | 131.1 에서 같은 검사 규칙 채택됨 | ✅ 진단 3 에서 `-E` 표지로 `bsd/i386/spl.h`·`reboot.h` 가 한 경로로만 들어오는지 확인 |
| 07 소스의 상위 `RB_` 사용은 `fp_support.c` 의 `RB_NOFP` 뿐(그 밖은 `RB_HALT`) | `grep -rn "RB_[A-Z]*" 07_kernel/src`(bsd 제외): `fp_support.c:107`, `miniMonMachdep.c:164` 만(나머지는 `IMARB_NULL` 동명이인). `fp_support.c:68` 이 `#import <bsd/i386/reboot.h>` 를 직접 한다 — 내 첫 grep 이 놓친 것 | ✅ |
| SDK `buf.h` 잠정 정의 시작은 112 가 아니라 110 행 | `buf.h:105–121` 열어 확인: 110 `struct buf *buf;` | ✅ 131.3 정정 |
| E1 은 링커 동작 검사일 뿐 원본 플래그 증명은 아님. common+common, 정의+정의, 잠정+초기화(순서 둘 다) 를 시험하고 기호 형태도 볼 것 | 설계 판정형: 결론 과장 위험은 맞다 | ⚖️ 시험 조합 확대 채택. 결론은 "이 헤더·이 객체로는 `-fno-common` 링크 불가" 까지만 쓴다 |
| `kernserv/i386/spl.h` 는 비-BSD 이름이라 07/Darwin 판이 먼저 쓰일 수 있음 | `07_kernel/src/kernserv/i386/spl.h` 존재. Darwin 판과 SDK 판 차이: 머리말, `splsoftclock`/`splstatclock` 매크로 2 줄, 끝 일부 | ✅ 131.1 의 비-BSD 정책대로 07 판을 쓰고 manifest 로 기록. ddm/vm_pageout/mach_init 가 쓰는 `splhigh`·`splx`·`splimp`·`spl0`·`splvm`(grep 확인)은 양쪽 모두 선언 |
| 스테이징된 `dma_inline.h` 수정 뒤 manifest 의 SHA 가 컴파일된 바이트와 달라짐 | 설계상 맞음 | ✅ 수정 기록(전·후 SHA)을 진단 기록 JSON 에 별도로 남긴다 |
| 131.3 의 원본 명령 바이트 | codex 미확인. 내가 Python 으로 `0x18a333` 7 B = `f6 05 36 26 1e 00 20` 읽음 | ✅(내 확인) |

### 132.2 구현 기록(코드, 실기 실행 전)

- `07_kernel/nextdev_private/bsd/i386/reboot.h`(SDK 본문 + `RB_NOFP` 블록), `bsd/i386/spl.h`(가드 + `#import <kernserv/i386/spl.h>`) 작성. PROVENANCE 2 행 추가(372 → 374 행, 모두 7 열).
- `stage_headers.py`: `bsd_pick` 이 `07_kernel/nextdev_private/bsd/X` 를 먼저 본다(기호 링크 거부). manifest 는 'authored' 갈래로 기록. 기존 테스트 19/19. 옛/새 도구로 85 소스 `--prefer-07 --nextdev --list` 출력 동일(418 줄). `--bsd-set nextos` 에서는 3 줄만 다르다: `src/bsd/i386/reboot.h` 출처 → 작성판, `src/bsd/i386/spl.h`(작성판)·`src/kernserv/i386/spl.h`(07 판) 추가, 미해결 `bsd/i386/spl.h` 소멸.
- 진단 3 스테이징 `08_build/runs/tools/s5p106-bsd-stage-1`(403 파일, 미해결 15). 스테이징 사본 `dma_inline.h:45` 만 Python 으로 수정, 기록 `s5p106-bsd-stage-1.dma-edit.json`(전 02bf5175…, 후 e292fbc6…).
- 명령: `s5p106-bsd-diag3.cmd`(진단 2 의 96 + O3c vm_machdep·kdp_machdep 2 + `-E` 4 = 102), `s5p106-e1.cmd`(E1: a/b 잠정·c 초기화, C/N 컴파일 5 + 조합 8 × {`ld -r`, `ld -static -e _main`} 16 = 21). E1 은 일부 명령이 실패하는 것이 정상이므로 `collect` 대신 `stage/_log` 를 읽는다.

### 132.3 결과(진단 3 `s5p106-bsd-diag-3`, E1 `s5p106-e1-1`, 2026-10-02)

진단 3(102 명령, 모두 종료 0, `collect` 로 307 파일 게시):
- 기준 비교(`09_validation/reconstruction/s5p106-bsd-diag3-compare-20261002.json`; 섹션 바이트·정렬·재배치(외부 재배치는 심볼 이름으로)·비-stab 심볼): 기준 `s5p98-gregress-1` 이 있는 92 개 중 88 개 같음, 4 개 다름. 기준 없는 6 개 중 sched_prim O3/O3c 는 `s5p99-build-1`, vm_map O3/O3c 는 `s5p103-build-1` 과 같음.
  - 처음 비교에서 68 개가 "`__text` 다름" 으로 나왔는데, 원인은 재배치의 심볼 **번호**(stab 수가 달라 번호가 밀림)였다. 이름으로 바꿔 다시 비교한 것이 위 결과다.
- 다른 4 개는 **모두 SDK 헤더의 잠정 정의 심볼이 더해진 것뿐**이다(다른 섹션 바이트·재배치 차이 없음):
  - `O3__vm_machdep.o`·`O3__kdp_machdep.o`: 새 `__DATA,__common` 섹션(정의 심볼 10·16 개).
  - `O3__ddm.o`: 기존 `__common` 섹션에 buf 계열 10 개가 더해짐.
  - `O3c__ddm.o`: common 심볼 10 개만 더해짐.
- 진단 2 의 실패 8 건은 모두 해소(spl.h·reboot.h 작성판, dma 스테이징 수정).
- O3c(common 변형) L1: kdp_machdep OBJECT_MATCH(`s5p106-l1-kdp_machdep-O3c-20261002.json`), vm_machdep NOT_MATCH 이나 사유는 기존 P 등급과 같은 `__TEXT,__const` 4 B 미배치(`s5p48-build-l1-vm_machdep-O3c` 와 섹션 판정 동일).
- 36.1 (c): O3c ddm·vm_machdep·kdp_machdep 의 common 심볼 29 개 모두 크기 ≤ 원본에서 다음 심볼까지 간격(`s5p106-common-gap-20261002.json`). 원본 위치는 `__common` 26 개, `__data` 3 개(`_nbuf`, `_bufpages`, `_nmbclusters` — 어딘가에서 초기화 정의됨).

E1(`09_validation/reconstruction/s5p106-e1-20261002.json`, 21 명령 중 6 개 실패):
- common+common, common+`-fno-common`, common+초기화(두 순서) → `ld -r`·`ld -static -e _main` 모두 성공.
- `-fno-common`+`-fno-common`, `-fno-common`+초기화(두 순서) → 두 링크 모두 `multiple definitions of symbol _x` 로 실패(`__DATA,__common` 정의끼리, 또는 `__common` 과 `__data` 정의).
- 해석(이 헤더·이 도구 조합에 한정): SDK/NeXTMach `sys/buf.h` 는 `int nbuf;` 등을 잠정 정의하는데 원본의 `_nbuf` 는 `__data`(초기화 정의)에 있다. 그러므로 buf.h 를 쓰는 객체가 `-fno-common` 이면 링크가 실패한다. **SDK/NeXTMach 헤더를 쓰는 한, 그 객체들은 common(= `-fno-common` 없이) 으로 컴파일되어야 링크된다.** 원본이 다른 헤더를 썼을 가능성은 이 실험으로 배제되지 않는다.

## 133. S5-P107 세부 계획 — D021 3 단계: 07 반영(BSD 헤더 묶음 교체)과 최종 플래그 (코딩 전, 2026-10-02)

사실(Python, 진단 3 스테이징 manifest): 확정·부분 85 소스가 읽는 `src/bsd/**/*.h` 는 63 개 — SDK 59, NeXTMach 2(`sys/kernel.h`, `sys/callout.h`), 작성 2(`i386/reboot.h`, `i386/spl.h`). 07 의 `src/bsd/` 는 58 파일(.h 57 + `libkern/strtol.c`), 모두 PROVENANCE `none (verbatim)` 이고 git 미추적. 로컬 SDK 사본(`01_resources/local_mirrors/headers`)은 저장소 밖 심볼릭 링크라 공개 트리로 빌드하려면 쓰이는 SDK 헤더가 07 에 있어야 한다(D018 때 `07_kernel/nextdev/` 6 파일을 같은 이유로 둠).

1. 07 배치(출처별 배치 유지):
   - SDK 59 → `07_kernel/nextdev/bsd/<X>`(include 계열은 SDK 경로 `ansi/X` 그대로). 바이트 동일, 실기 SHA 목록과 대조.
   - NeXTMach 2 → `07_kernel/nextmach/sys/{kernel,callout}.h`(mk-108.1 경로). 바이트 동일, 고정 커밋 blob 과 대조, 원 notice 유지(D013).
   - 작성 2 → 이미 `07_kernel/nextdev_private/`.
   - PROVENANCE 61 행 추가.
2. Darwin 사본 은퇴: `07_kernel/src/bsd/` 의 .h 57 개를 지운다(`strtol.c` 는 BSD **소스**라 남김).
   - 지우기 전: 각 파일 SHA = Darwin 원문 SHA 확인(검증된 verbatim 이라 원문에서 재생성 가능), 목록(경로·SHA·원문) 을 `09_validation/reconstruction/` 기록으로 남기고, tar 사본을 스크래치에 둔다.
   - PROVENANCE 57 행 제거. 행 수 기대: 374 + 61 − 57 = 378(Python 으로 확인).
3. `stage_headers.py`: `--bsd-set nextos` + `--prefer-07` 이면 BSD 이름을 `nextdev_private` → `07_kernel/nextdev/bsd`(실기 SHA 일치 필수) → `07_kernel/nextmach`(커밋 blob 일치 필수) 순으로 찾고, 07 에 없으면 로컬 SDK/NeXTMach 사본으로 가되 manifest 에 'not adopted' 로 표시. 최종 빌드 판정 조건: 'not adopted' 0 건.
4. `07_kernel/src/machdep/i386/dma_inline.h:45` → `#import <bsd/i386/machparam.h>`. MODIFICATIONS·PROVENANCE 갱신.
5. 최종 플래그에서 `-fno-common` 제거 — 후보(근거: 132.3 E1 합성 실험과 36.1; 전체 커널 링크로 확인된 것은 아님). 템플릿 `08_build/runs/tools/s5p107-build.cmd`, `GCC27_COMPATIBILITY.md`·`07_kernel/README.md` 갱신. 역사적 사실로 확정한 것이 아니라 "이 헤더 묶음에서 링크 가능한 후보" 로 적는다.
6. 회귀(실기): 85 소스를 07 만으로 스테이징(위 3, 'not adopted' 0)하고 최종 플래그로 빌드.
   - 비교 1: 진단 3 의 O3c 출력이 있는 객체는 그것과 비-디버그 내용이 같아야 한다.
   - 비교 2: 나머지는 진단 3 의 O3(`-fno-common`) 출력과 같아야 한다. 다르면(미초기화 전역이 있는 객체) 36.1 절차(L1 + 간격)로 판정.
   - 등급 표(objects_confirmed/partial)의 build 칸은 바꾸지 않고, 회귀 기록과 이 절을 근거로 남긴다.
7. 이 단계가 끝나면 D021 의 BSD 범위는 완료. 비-BSD 이름(`mach/`·`kernserv/` 등)의 SDK 교체 여부는 사용자 결정 사항으로 남긴다(131.1).

### 133.1 codex 교차검토(QS52) 판정 → 계획 보정

내가 틀린 것: 133 의 "07 `src/bsd/` 58 파일 모두 Darwin verbatim" 은 틀렸다. `sys/version.h` 는 SDK 판이다(PROVENANCE 360 행 `nextdev-os42`, D020·111.1 원본 바이트로 선택). Darwin 사본은 .h 56 개다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 07 배치는 한 논리 경로 `src/bsd/X` 로 스테이징되는 한 일관. `include/X` 는 SDK `ansi/X` 로 명시 구현 필요 | `stage_headers.py:100–107`(canonical), `:115–118`(include → `ansi/X`·`bsd/X`). 진단 3 의 include 계열 6 개 모두 SDK `ansi/` 출처(Python) | ✅ include 계열 사본은 `07_kernel/nextdev/ansi/X` 에 둔다 |
| `standards.h` 가 두 논리 경로(`src/bsd/include/standards.h`, `nextdev/ansi/standards.h`)로 스테이징됨 → `#import` 중복 방지 일반 주장은 근거 없음 | manifest 에서 같은 SHA 가 두 경로인 쌍: 이것과 Darwin `kernserv/{ppc,i386}/us_timer.h`(무관) 뿐(Python). SDK `ansi/standards.h:3–4` 는 `#ifndef _STANDARDS_H` 가드. `-E` 4 개 출력엔 standards.h 없음 | ⚖️ 이번 경우는 가드로 무해. 회귀 때 같은 SHA 다중 경로 목록을 기록하고, 가드 없는 헤더가 나오면 따로 판정 |
| 57 개 삭제는 위험: 기본 모드는 07 → Darwin 순이라 `version.h` 가 Darwin 으로 되돌아감, SHA=Darwin 검사가 `version.h` 에서 실패 | PROVENANCE 360 행 확인, `stage_headers.py:141–147`(기본 모드 07 → Darwin) | ✅ `version.h` 는 지우지 않고 `07_kernel/nextdev/bsd/sys/version.h` 로 **옮긴다**(SDK 사본 위치). Darwin 56 개만 은퇴. 기본 모드는 이후 최종 소스를 대표하지 않는다고 README·도구 docstring 에 적는다 |
| `test_stage_headers_subst.py:97` 은 07 의 `sys/callout.h` 사본으로 shadow 오류를 시험 → 수정 필요 | 97 행 열어 확인 | ✅ 07 에 남는 `src/bsd/libkern/strtol.c` 를 키로 쓰도록 바꾸고 19/19 재확인 |
| `s5p99-build.cmd` 는 스테이징 방식에 의존 | 2–3 행: `src/src/bsd` -I 경로 사용(스테이징 결과에 의존) | ✅ 새 템플릿에 스테이징 명령(`--prefer-07 --nextdev --bsd-set nextos`)을 머리 주석으로 적는다 |
| `-fno-common` 제거는 "유일한 선택" 이 아니라 후보. E1 은 합성 객체 실험 | 132.3 해석 문장 자체가 한정을 둠; 133 의 5 항 문구는 과함 | ✅ 문구를 "후보(근거 E1·36.1)" 로 고침 |
| 6 항 회귀는 O3c 기준 없는 객체, `__bss`↔`__common` 변화, 정적 미초기화 데이터를 놓칠 수 있음 | 6 항은 O3 와 다르면 36.1 로 판정한다고 이미 적음. 다만 36.1 은 정적 데이터를 다루지 않음(1273 행 근처) | ⚖️ 비교 1·2 에서 **어떤 차이든** 나면 그 객체는 L1 전체를 다시 돌린다(섹션 이동 포함). 정적 데이터 차이는 L1 의 zero-fill 검사로 본다 |
| 374+61−57=378 은 줄 수, 헤더 제외 항목 수는 377 | 374 는 `grep -c ""`(헤더 포함 줄 수) | ✅ 보정: 줄 374 + 61 − 56(은퇴) = 379, version.h 는 경로만 바뀜. Python 으로 확인 |

보정된 단계:
1. SDK 59 중 `include/X` 6 개는 `07_kernel/nextdev/ansi/X`, 나머지 53 은 `07_kernel/nextdev/bsd/X`. 이 중 `sys/version.h` 는 기존 07 사본을 옮긴다(바이트 동일 확인). 새 PROVENANCE 행: SDK 58 + NeXTMach 2 = 60, version.h 행은 경로만 갱신.
2. 은퇴는 Darwin 사본 56 개(각 SHA = Darwin 원문 확인). 줄 수 기대: 374 + 60 − 56 = 378.

### 133.2 구현 기록(1–5 단계, 실기 회귀 전)

- 1: SDK 59(include 계열 6 개는 `07_kernel/nextdev/ansi/`, 나머지 `07_kernel/nextdev/bsd/`; `sys/version.h` 는 `07_kernel/src/bsd/sys/` 에서 옮김) + NeXTMach 2(`07_kernel/nextmach/sys/{kernel,callout}.h`) 배치. 모두 원본(실기 SHA 목록 / 고정 커밋 blob)과 바이트 동일 확인. 07 `nextdev`+`nextmach` 파일 67 개(기존 6 + 61).
- 2: Darwin 사본 .h 56 개 은퇴(각 SHA = Darwin 원문, PROVENANCE `darwin01` + `none (verbatim` 확인). 기록 `09_validation/reconstruction/s5p107-retired-07-bsd-20261002.json`, tar 사본은 스크래치(SHA cb95fae2…). `07_kernel/src/bsd/` 에는 `libkern/strtol.c` 만 남음. PROVENANCE 374 줄 − 56 + 60 = 378 줄, 모두 7 열.
- 3: `stage_headers.py` — `--bsd-set nextos --prefer-07` 이면 `nextdev_private` → `07_kernel/nextdev/<SDK 경로>`(실기 SHA 일치 필수) → `07_kernel/nextmach/<경로>`(blob 일치 필수) → 로컬 사본(manifest `bsd_not_adopted` 에 기록). docstring 에 기본 모드가 더 이상 복원 소스를 대표하지 않는다고 적음. 테스트 `test_stage_headers_subst.py` 의 shadow 사례 키를 `src/bsd/libkern/strtol.c` 로 바꿈, 19/19.
  - 85 소스를 07 만으로 스테이징(`s5p107-final-stage-1`, 403 파일): `bsd_not_adopted` 0, 진단 3 스테이징과 논리 경로 집합 같음, 바이트가 다른 파일은 `dma_inline.h` 하나, 미해결 include 는 `bsd/i386/param.h` 하나가 빠진 14.
- 4: `07_kernel/src/machdep/i386/dma_inline.h` 수정(수정 표시 주석 + `machparam.h`), diff `06_reconstruction/evidence/x86-dma_inline_h.diff`, PROVENANCE·MODIFICATIONS 갱신(객체 회귀는 6 단계 결과로 채움).
- 5: 템플릿 `08_build/runs/tools/s5p107-build.cmd`(최종 = O3c, O3 는 36.1 진단 변형). 문서(`GCC27_COMPATIBILITY.md`, `07_kernel/README.md`) 갱신은 회귀 결과 뒤.
- 6 준비: `s5p107-regress.cmd`(85 소스 × {F = 최종 플래그, N = `-fno-common`} = 170), 실행 디렉터리 `s5p107-regress-1` 준비 완료(실기 실행 대기).
  - 판정: N 은 진단 3 의 같은 출력과 비-디버그 내용이 같아야 한다(dma 는 07 수정판). F 는 진단 3 O3c 가 있으면 그것과, 없으면 N 과 같아야 한다. 다르면 그 객체는 L1 전체를 다시 돌린다.

### 133.3 회귀 결과(`s5p107-regress-1`, 170 명령 모두 종료 0, `collect` 511 파일)

기록 `09_validation/reconstruction/s5p107-regress-compare-20261002.json`, L1 `s5p107-l1-<객체>-F-20261002.json`.
- N(`-fno-common`) 85 개 모두 진단 3 의 같은 출력과 비-디버그 내용이 같다 — 07 의 `dma_inline.h` 수정은 객체를 바꾸지 않는다.
- F(최종) 85 개: 65 개는 기준(진단 3 O3c 13, N 52)과 같다. 20 개는 미초기화 전역이 `__common` 정의 → 이름 있는 common 으로 바뀌어 다르다(그에 따라 섹션 번호·정적 심볼의 섹션 번호도 바뀜).
- 20 개 L1: 등급 A 17 개(dbl_fault, dma_buf, host, ipc_entry, ipc_hash, ipc_marequest, ipc_notify, ipc_object, ipc_port, ipc_space, ipc_table, ipc_xxx, machine, processor, thread_swap, timer, vm_user) 모두 OBJECT_MATCH. 등급 P 3 개는 기존과 같은 판정:
  - dma: MATCH 7 / MATCH_UNVERIFIED 15, `__bss` inferred — `s5p45-build-l1-dma-O3c` 와 같음.
  - kern_notify: MATCH 4 / MATCH_UNVERIFIED 3, `__bss` inferred — `s5p25-pre-l1-kern_notify-O3c` 와 같음.
  - intr: MATCH 3 / MATCH_UNVERIFIED 30, `__bss` inferred, `__const` 4 B 미배치 — 증거 `x86-intr.md` 의 `-O3` 결과(3/30, 같은 사유)와 같음.
- 결론: BSD 헤더 묶음 교체(D021)와 최종 플래그 변경 후에도 확정·부분 85 소스의 등급은 그대로다. 등급 표는 바꾸지 않는다.
- 문서: `GCC27_COMPATIBILITY.md`(툴체인 고정에 D021·`-fno-common` 단락), `07_kernel/README.md`, MODIFICATIONS(dma 행 결과) 갱신.
- 남은 것: 비-BSD 이름(`mach/`·`kernserv/` 등)의 SDK 교체 여부(사용자 결정, 131.1), 큰 규모 작성 범위(130 2 항, 사용자 결정).

## 134. S5-P108 세부 계획 — D022(비-BSD 헤더 SDK 교체, Mach 내부는 Mach4 기본 참고) 1 단계 (코딩 전, 2026-10-02)

사용자 결정 D022: SDK 에 있는 비-BSD 이름은 SDK 판으로 바꾸고, SDK 에 없는 Mach 쪽 이름의 기본 참고는 Mach4, Darwin 은 구조 참고.

사실(Python, `s5p107-final-stage-1` manifest, 생성 헤더·`nextdev/`·`src/bsd/` 제외): 85 소스가 읽는 비-BSD 헤더 213 개.
- SDK 에 같은 이름이 있는 것 68 개: `mach/` 42, `architecture/` 11, `kernserv/` 9, `driverkit/` 6(`components/driverkit-1/driverkit/X` ↔ SDK `driverkit/X`).
  - 이 중 07 에서 복원 수정한 것 4 개: `mach/port.h`, `mach/notify.h`, `mach/mach_param.h`, `mach/i386/vm_param.h`(KERNSTACK_SIZE).
- SDK 에 없고 Mach4(`kernel/`·`include/`·`i386/` 아래 같은 경로)에 있는 것 57 개, 둘 다 없는 것 88 개(그중 22 개는 ppc 등 조건부 경로로 07 에도 없음).
- Mach4 는 Mach 3 계열이라 `kern/`·`ipc/`·`vm/` 내부 구조체가 OPENSTEP 과 다를 수 있다 → 2 단계는 진단부터 한다.

1 단계(이번): SDK 68 개.
1. `stage_headers.py --mach-set sdk`(새 옵션, `--nextdev` 필수): 논리 경로 `src/mach/X`, `src/kernserv/X`, `components/architecture/X`, `components/driverkit-1/driverkit/X` 의 이름이 SDK 에 있으면 SDK 판(`--prefer-07` 이면 `07_kernel/nextdev/<SDK 경로>` 먼저, 실기 SHA 일치 필수)을 읽는다. SDK 에 없는 이름은 지금 규칙(07 → Darwin)을 그대로 쓴다(2 단계에서 다룸).
   - SDK 별칭 정규화: `nextdev/mach/X` → `src/mach/X`, `nextdev/kernserv/X` → `src/kernserv/X`, `nextdev/architecture/X` → `components/architecture/X`, `nextdev/driverkit/X` → `components/driverkit-1/driverkit/X`(BSD 의 `canonical()` 과 같은 방식) — 한 헤더가 두 논리 경로로 스테이징되지 않게 한다.
   - manifest: SDK 출처 행 표시, SDK 로 바뀐 07 수정판 4 개는 따로 목록.
   - 기본 동작·`--bsd-set` 만 쓴 동작은 그대로(옛/새 도구 출력 비교).
2. 진단 4(실기): 85 소스를 `--prefer-07 --nextdev --bsd-set nextos --mach-set sdk` 로 스테이징, F(최종)·N(`-fno-common`) 170 명령. 133.3 의 같은 출력과 비교(비-디버그 내용), 다르면 원인별 분류, 실패는 첫 오류.
3. 결과에 따라 07 반영(SDK 사본을 `07_kernel/nextdev/` 에, 은퇴할 Darwin·수정판 기록)을 다음 회차에 계획한다. 수정판 4 개가 SDK 판으로 바뀌어도 객체가 같으면 SDK 판을 채택하고 수정 기록을 은퇴시킨다; 다르면 원인(원본 바이트)과 함께 보고한다.
4. 2 단계(Mach4) 는 1 단계 회귀 뒤 따로 계획: SDK 에 없는 57 개를 Mach4 판으로 바꿔 진단만 하고 결과를 보고한다(대규모 차이가 예상되므로 채택 방식은 결과를 보고 정한다).

### 134.1 codex 교차검토(QS53) 판정 → 구현 규칙

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `-I` 순서상 `src/src`·`components`·`components/architecture` 가 `src/nextdev` 보다 앞 → 정규화된 스테이징 위치를 컴파일러도 먼저 찾음 | `s5p107-regress.cmd:4` 의 `-I` 열(Python 아님, 출력 그대로): generated, src, src/bsd, src/bsd/include, src/machdep, components, components/architecture, nextdev, nextdev/bsd, nextdev/ansi. 도구 `ROOTS` `stage_headers.py:68–70` 같은 순서 | ✅ |
| 현 manifest 의 `nextdev/kernserv/printf.h`, `nextdev/architecture/ARCH_INCLUDE.h` 도 정규 경로로 옮겨야 함 | manifest `nextdev/` 행 14 개 중 위 2 개가 해당(나머지 objc·ansi·mach-o) | ✅ 정규화 대상에 포함, 진단에서 두 경로 스테이징 0 확인 |
| SDK `mach/machine/vm_param.h` 의 `ARCH_INCLUDE(mach/, vm_param.h)` 두 번째 홉은 인용 include 로 처리됨 | SDK 파일 9–11 행, 도구 `ARCH_INC` 처리 | ✅ |
| **SDK `kernserv/lock.h` 와 07 `kern/lock.h` 가 같은 가드 `_KERN_LOCK_H_`** 이고 `lock_t` 정의가 다름(`void *` vs `struct lock *`) → 포함 순서에 따라 한쪽이 조용히 빠짐 | SDK `kernserv/lock.h` 24–31 행(`typedef void *lock_t`), 07 `kern/lock.h:58–59,146` | ✅ 진단 전에 소스별 closure 로 두 헤더를 모두 읽는 소스를 찾고, 그 소스는 `-E` 로 실제 포함 순서를 기록. 객체 일치만으로 07 판 은퇴 근거로 삼지 않는다 |
| SDK `mach/port.h` 에 `mach_port_name_t` 등 07 판의 일부 타입이 없음(85 소스에서 실패는 미입증) | diff 로 확인(07 판에만 `mach_port_name_t`, `mach_port_limits_t` …) | ✅ 진단 컴파일 실패로 드러나게 둔다 |
| `MACH_SEND_SWITCH` 값이 다름(SDK 0x20000, 07 0x80000), 85 소스 사용 미발견 | 두 파일 grep(SDK 340, 07 455), `07_kernel/src` .c grep 0 건 | ✅ 기록. 원본이 쓰는 곳이 나오면 원본 바이트로 판정 |
| 수정판 4 개의 복원 값이 SDK 판에 모두 있음 | 직접 확인: SDK `vm_param.h:47` KERNSTACK 1 쪽, `mach_param.h` 4·16, `port.h:194–203`, `notify.h:90–122` | ✅ |
| 134 의 수(68 등)·85 소스·170 명령 맞음 | Python 재계산(134 정정 후) | ✅ |

### 134.2 구현과 사전 분류(코드, 실기 전)

- `stage_headers.py --mach-set sdk` 구현(`MACH_MAP`, `mach_pick`, `canonical()` 정규화, manifest `mach-set:` 행·`mach_replaced_07`·`mach_not_adopted`). 옛/새 도구 `--list` 출력 동일: 기본(419 줄), `--bsd-set`(417), `--bsd-set` 비-07(418). 테스트 19/19.
- 85 소스 closure 에서 SDK 로 바뀌는 이름 70 개(68 + 정규화된 `kernserv/printf.h`, `architecture/ARCH_INCLUDE.h`). 주석·공백을 뺀 본문 비교(Python, `difflib`): 같음 34, 다름 36.
  - 다른 36 개의 성격(내 판독):
    - 아키텍처 분기 표기만 다름(`#if __ppc__ … #include "mach/i386/X"` ↔ `ARCH_INCLUDE`), `#endif` 꼬리표 등: `mach/machine/*` 7, `kernserv/machine/us_timer.h`, `driverkit/machine/driverTypes.h`, `architecture/byte_order.h`, `kernserv/macro_help.h`, `mach/vm_policy.h` 등.
    - **공개판(커널 비공개 분기 삭제)**: `kernserv/lock.h`(KERNEL_PRIVATE 이면 `kern/lock.h` 를 쓰는 분기), `mach/mach_types.h`(`_KERNEL` 분기의 `kern/task.h`… import), `mach/std_types.h`(`ipc/ipc_port.h` import), `mach/mach_traps.h`(KERNEL_PRIVATE 선언), `kernserv/clock_timer.h`·`ns_timer.h`(KERNEL_PRIVATE 이면 `kern/clock.h`·`kern/time_stamp.h`), `kernserv/prototypes.h`(양쪽 모두 다름).
    - 판 차이: `mach/message.h`(308 줄; Darwin 판은 기술자(descriptor)형 메시지 추가, SDK 는 typed 메시지와 `msgh_kind`), `mach/port.h`, `mach/machine.h`, `mach/boolean.h`(TRUE/FALSE 형변환), `mach/notify.h`(`mach/ndr.h` import), `mach/mach_param.h`, `mach/error.h` 등.
  - 46 소스가 `kernserv/lock.h` 와 `kern/lock.h` 를 모두 closure 에 둔다(조건부 분기 포함 집계).
- 진단 4 는 **SDK 그대로**(공개판 포함) 돌려 실패·차이를 원인별로 센다. 공개판 처리(비공개 분기를 어떤 본문으로 되살릴지: Mach4 기본 참고, 원본 바이트로 확인)는 결과를 보고 다음 계획에서 정한다.

### 134.3 진단 4 결과(`s5p108-diag-4`, SDK 그대로, 2026-10-02)

기록 `09_validation/reconstruction/s5p108-diag4-compare-20261002.json`(기준 `s5p107-regress-1`). 170 명령: 같음 122, 다름 4, 실패 44(22 소스: PCemulatePROT, PCemulateREAL, PCinit, PCresume, catch, dbl_fault, dma_buf, fault_copy, fp_support, gdt, idt, intr, ipc_xxx, kdp_machdep, kern_notify, machine, sched_prim, syscall_sw, vm_policy, vm_resident, vm_synchronize, vm_user).
- 실패 첫 오류(빈도): `mach/mach_types.h` `task_t` 충돌 8, `TSS_SEL` 미선언 6, `ipc/ipc_types.h` `ipc_space_t` 충돌 4, `kern/kern_types.h` `task_t` 충돌 4, `BYTE_SIZE` 미선언 4, `KERNEL_LINEAR_BASE`·`KCS_SEL`·`PAGE_SIZE`·`thread_saved_state_t`·`task_by_pid` 미선언 각 2, 구문 오류 4 종 각 2.
  - `BYTE_SIZE`(SDK `mach/i386/vm_param.h:17` 에 있음), `PAGE_SIZE`(SDK `mach/vm_param.h` 는 07 판과 본문 동일) 등은 정의 자체는 SDK 에도 있다 → 원인은 **포함 경로가 끊긴 것**: 공개판 `mach/mach_types.h`·`std_types.h` 가 비공개 분기의 `kern/task.h`·`kern/thread.h`·`vm/vm_object.h`·`ipc/ipc_port.h` import 를 잃었다.
  - `task_by_pid` 는 공개판 `mach/mach_traps.h` 에서 KERNEL_PRIVATE 선언이 빠진 것.
- 다른 4 개: ddm(F·N) — SDK `kernserv/printf.h` 가 `sys/tty.h` 를 가져와 잠정 정의 `_tthiwat`·`_tthog`·`_ttlowat` 추가, 정적 지역 이름 번호(`_xxx.100` → `_xxx.86`) 변화, 섹션 바이트는 같음. dma(F·N) — `dma_xfer`·`dma_xfer_done` 이 20 B 씩 커짐: `pmap_phys_to_kern` 이 매크로(`machdep/i386/pmap.h:121`)가 아니라 함수 호출로 컴파일됨 → 같은 포함 경로 문제.

### 134.4 진단 5 계획 — 공개판 헤더를 빼고 SDK 교체 (코딩 전)

가설: 실패·차이는 비공개 분기가 빠진 공개판 헤더 몇 개에서 온다. 확인 방법: 공개판으로 판단한 7 개(`mach/mach_types.h`, `mach/std_types.h`, `mach/mach_traps.h`, `kernserv/lock.h`, `kernserv/clock_timer.h`, `kernserv/ns_timer.h`, `kernserv/prototypes.h`)를 `--mach-set` 에서 제외(현재 07 판 유지)하고 나머지 SDK 교체로 85 소스를 다시 빌드한다.
1. `stage_headers.py`: `MACH_KERNEL_STRIPPED`(BSD 의 `KERNEL_STRIPPED` 와 같은 구실) 목록을 두고, 그 이름은 `mach_pick` 이 고르지 않는다. 각 항목에 근거(134.2 diff) 기록.
2. 진단 5(실기 170 명령), 기준 `s5p107-regress-1` 과 비교.
3. 기대: 실패 0, 차이는 ddm 의 잠정 정의(printf.h → tty.h) 정도. 남는 차이가 있으면 원인별로 기록.
4. 진단 5 가 깨끗하면 남는 결정: 공개판 7 개의 비공개 분기를 어떤 본문으로 둘지(SDK 본문 + 비공개 분기 작성; 분기 내용의 참고 판). 사용자 결정 사항으로 보고한다.

### 134.5 codex 교차검토(QS54) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 원인 가설이 실패들과 맞음: `TSS_SEL`(seg.h ← machdep/i386/thread.h ← kern/thread.h ← 07 mach_types.h 비공개 분기), dbl_fault `thread_saved_state_t`, ipc_xxx(07 `std_types.h:64–66` 의 `ipc/ipc_port.h`), `task_by_pid`(공개판 mach_traps.h) | `grep` 으로 `seg.h` 를 import 하는 헤더는 `machdep/i386/thread.h` 뿐; `std_types.h:64–66` 열어 확인; `62.err` 1 행 = `dbl_fault.c:46: parse error before dbf_state` | ✅ 단, 개별 실패 모두를 증명한 것은 아님(진단 5 로 확인) |
| `PCpublic.h` 는 `!KERNEL` 일 때만 `mach/vm_param.h` 를 import → `BYTE_SIZE` 도 같은 끊긴 경로 | `PCpublic.h:36–38` 열어 확인 | ✅ |
| 7 개 목록은 "비공개 분기 삭제" 기준으로 완전해 보임; message.h·machine.h·kalloc.h·printf.h 는 커널 분기 유지, port.h 는 분기 없음 | 134.2 diff 와 일치(내 집계도 같은 7 개) | ✅ |
| 진단 5 가 깨끗해도 85 소스 범위의 결과일 뿐; Darwin `ipc_kmsg.c:288` 등은 SDK message.h 에 없는 descriptor 를 씀 | `ipc_kmsg.c:286–288` 확인. ipc_kmsg.c 는 07 에 없음(미복원) | ⚖️ 범위 한정을 기록. 원본은 typed 메시지 시대(SDK `message.h`)이므로 ipc_kmsg 복원 때는 SDK 판 + Mach4 `ipc_kmsg.c` 가 기준 후보가 된다(D022) |

### 134.6 진단 5 결과(`s5p108-diag-5`, 2026-10-02)

170 명령 모두 종료 0, `collect` 511 파일. 기준 `s5p107-regress-1` 과 170/170 비-디버그 내용 같음(`09_validation/reconstruction/s5p108-diag5-compare-20261002.json`). → 공개판 7 개를 뺀 SDK 63 개 교체는 85 소스(F·N)에 영향 없음. 진단 4 의 실패·차이는 모두 공개판 7 개에서 왔다는 가설과 일치(ddm 의 tty 잠정 정의도 사라짐 — SDK `prototypes.h` → `printf.h` 경로가 없어졌기 때문).
- 범위 한정(134.5): 85 소스에 대한 결과다.
- 공개판 7 개의 처리는 사용자 결정으로 보고한다(Mach4 에도 같은 구조가 있음: `include/mach/mach_types.h:56–85` `MACH_KERNEL` 분기, `std_types.h:44–46`, `mach_traps.h:36–38`).

## 135. S5-P109 세부 계획 — D022 SDK 63 개 07 반영 (코딩 전, 2026-10-02)

사실(Python, `s5p108-mach-stage-2.manifest.json`): `--mach-set` 이 SDK 판을 고른 논리 경로 63 개. 그중 07 에 같은 논리 경로 사본이 있던 것 60 개(PROVENANCE: Darwin verbatim 56, 복원 수정 4 — `mach/port.h`(darwin01+mach4), `mach/notify.h`, `mach/mach_param.h`, `mach/i386/vm_param.h`). 07 사본 없음 3 개(`kernserv/printf.h`, `architecture/ARCH_INCLUDE.h`(이미 `07_kernel/nextdev/` 에 있음), `kernserv/kalloc.h`). `mach_not_adopted` 62.

1. SDK 62 개를 `07_kernel/nextdev/<SDK 경로>` 에 복사(실기 SHA 일치 확인). PROVENANCE 62 행 추가.
2. 대체된 07 사본 60 개 은퇴:
   - verbatim 56: 각 SHA = Darwin 원문 확인 후 삭제, 목록 기록, tar 사본.
   - 복원 수정 4: SDK 판이 같은 값을 가짐(134.1 확인)과 진단 5 동일을 근거로 은퇴. 파일·diff 는 기록으로 남기고(tar + 기록 JSON), MODIFICATIONS 에 "2026-10-02 retired: SDK 판으로 대체(D022, 계획 135)" 행 추가(기존 행은 이력으로 유지).
   - PROVENANCE 60 행 제거. 줄 수 기대: 378 + 62 − 60 = 380(Python 으로 확인).
3. 확인(로컬): 같은 85 소스를 반영 뒤 07 로 스테이징 → `mach_not_adopted` 0, `bsd_not_adopted` 0, 스테이징 결과가 `s5p108-mach-stage-2` 와 논리 경로·SHA 모두 같음(비-BSD/Mach 의 Darwin·SDK 출처 파일은 그대로 남는다). 같으면 진단 5(170/170 동일)가 이 07 트리의 회귀 결과가 된다(실기 재실행 불필요). 다르면 실기 회귀를 요청한다.
4. 문서: 템플릿 머리 주석·README·GCC27 문서에 스테이징 명령 `--mach-set sdk` 추가, `stage_headers.py` docstring 에 기본 모드 한계 추가.
5. 공개판 7 개는 이번에 건드리지 않는다(07 판 유지, 사용자 결정 대기).

### 135.1 codex 교차검토(QS55) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 기본 모드(`--mach-set` 없음)는 07 사본을 읽으므로 은퇴 뒤 Darwin 으로 돌아감 | `stage_headers.py` select(07 → Darwin) | ✅ BSD 때와 같이 기본 모드는 복원 소스를 대표하지 않는다고 docstring·README 에 적는다 |
| 남기는 공개판 7 개(07 판)가 은퇴 대상 이름을 import(`mach_types.h` 가 `mach/port.h` 등) → `--mach-set` 에서는 SDK 판으로 해석 | 07 `mach_types.h` 89 행 `#import <mach/port.h>`(codex 의 85 행은 `host_info.h`; 줄 번호 틀림, 주장은 맞음) | ✅ 진단 5 가 이 조합을 이미 빌드함 |
| 과거 증거 파일이 옛 경로를 적고 있음(`x86-pagesize.files.json:3`) | 3 행 `07_kernel/components/architecture/i386/desc.h` 확인 | ✅ 이력 기록이므로 고치지 않는다. 은퇴 기록 JSON 이 옛 경로 → 새 출처를 잇는다 |
| `srcdefs.py`·`struct_compare.py` 는 이 07 사본에 직접 의존하지 않음 | 미확인(codex 인용만) | ⏭️ 행동 불변 — 이후 그 도구로 07 경로를 넘기면 오류로 드러남 |
| 수정판 4 개 은퇴는 85 소스에 대해 안전; `mach_port_name_t` 등 옛 판에만 있는 이름은 07 에서 옛 `port.h` 안에만 있음, 옛 `notify.h` 만 `mach/ndr.h` import | 내 grep 동일(다른 사용처 0), `notify.h:86` `#include <mach/ndr.h>`(codex 84 행은 `mach/port.h`; 줄 번호 틀림) | ✅ 이후 복원 코드가 이 이름을 쓰면 원본 바이트로 재검토 |
| 3 단계 판정은 같은 명령·플래그·도구일 때 객체 내용에 한해 이전된다 | — | ✅ 문구 보정 |
| 380 은 줄 수(헤더 포함), "07 만으로 스테이징" 은 과장 — 비-BSD/Mach 이름은 여전히 Darwin·SDK 에서 옴 | manifest 의 비-07 출처 행 존재(133.2 에서도 31 개) | ✅ 3 단계 조건을 "`bsd_not_adopted`·`mach_not_adopted` 0, 논리 경로·SHA 동일" 로 고친다 |

### 135.2 구현 기록(2026-10-02)

- 1: SDK 62 개를 `07_kernel/nextdev/` 에 복사(실기 SHA 일치), `07_kernel/nextdev` 파일 65 → 127.
- 2: 07 사본 60 개 은퇴(verbatim 56: SHA = Darwin 원문; 복원 수정 4: Darwin 원문 + evidence diff 로 `patch` 재현이 바이트 동일함을 확인). 기록 `09_validation/reconstruction/s5p109-retired-07-mach-20261002.json`, tar 사본 스크래치(SHA dbdfae89…). PROVENANCE 378 − 60 + 62 = 380 줄, 7 열. MODIFICATIONS 에 은퇴 행 4 개(62 → 66 줄).
  - 07 에 남은 Mach 쪽 헤더: `src/mach/{clock_types,features,mach_traps,mach_types,ndr,std_types}.h`, `src/kernserv/{clock_timer,lock,ns_timer,prototypes,kern_notify}.h`(+ `kern_notify.c`).
- 3: 반영 뒤 스테이징 `s5p109-final-stage-1`(393 파일): `bsd_not_adopted`·`mach_not_adopted`·`mach_replaced_07` 모두 0, `s5p108-mach-stage-2` 와 논리 경로·SHA·미해결 목록 동일 → 진단 5(170/170 동일)가 이 07 트리의 85 소스 회귀 결과다(같은 명령·도구, 객체 내용 한정).
- 4: 템플릿 `s5p107-build.cmd` 머리 주석, `07_kernel/README.md`, `GCC27_COMPATIBILITY.md`, `stage_headers.py` docstring 갱신. 테스트 19/19.
- 남은 결정(사용자): 공개판 7 개의 비공개 분기 본문.

## 136. S5-P110 세부 계획 — D023: 공개판 7 개의 비공개 분기 작성 (코딩 전, 2026-10-02)

사용자 결정 D023(A): SDK 본문은 그대로, 비공개 분기만 작성해 `07_kernel/nextdev_private/<SDK 경로>` 에 둔다. 분기 내용은 Mach4 구조를 기본 참고, 원본 바이트로 확인되는 최소만.

원칙: 각 파일 = SDK 파일 바이트를 그대로 두고 **분기 줄만 끼워 넣는다**(SDK 줄 삭제·수정 없음; 끼워 넣은 줄은 주석 `/* plan 136: … */` 로 표시). 분기 조건은 현재 07 판(=진단 5 에서 객체 동일이 확인된 동작)과 같게 한다. `MACH_USER_API` 는 Darwin `conf/Makefile.template:689–691` 에서 커널 안의 Mach 사용자 API 객체가 정의하므로 조건에서 뺄 수 없다.

| 헤더 | 끼워 넣을 비공개 분기(조건) | 참고 |
|---|---|---|
| `mach/mach_types.h` | SDK 의 typedef 14 줄과 `*_NULL` 5 줄을 `#else` 쪽에 두고, 앞에 `#if _KERNEL && !MACH_USER_API` + `kern/task.h`·`kern/thread.h`·`kern/processor.h`·`vm/vm_user.h`·`vm/vm_object.h` import + `typedef vm_map_t vm_task_t;` | Mach4 `include/mach/mach_types.h:56–85`(`MACH_KERNEL` 분기에 같은 3 import); vm 2 import 와 `vm_task_t` 는 현재 07 판 동작 |
| `mach/std_types.h` | 끝에 `#if _KERNEL && !MACH_USER_API` `#import <ipc/ipc_port.h>` | Mach4 `include/mach/std_types.h:44–46`(`MACH_KERNEL`) |
| `mach/mach_traps.h` | 끝에 `#if defined(KERNEL_PRIVATE)` 선언: `host_priv_self`, `device_master_self`, `_event_port_by_tag`, `_lookupd_port`, `task_by_pid`, `init_process`, `mach_swapon`, `kern_timestamp`(+ `kern/time_stamp.h` import). SDK 처럼 K&R 선언 | 8 개 모두 원본 심볼표에 있음(`symbols.tsv` grep); 07 판의 `_lookupd_port1` 은 원본에 없어(syscall_sw 수정 근거와 같음) 넣지 않음 |
| `kernserv/lock.h` | 전체를 `#ifdef KERNEL_PRIVATE` `#import <kern/lock.h>` `#else` … `#endif` 로 감쌈(`#warning` 은 넣지 않음) | 현재 07 판 구조; Mach4 는 `kern/lock.h` 만 있음 |
| `kernserv/clock_timer.h` | `ns_time_t` typedef 뒤의 SDK 공개 선언(chrono·`clock_types_t`·함수 3 개)을 `#else` 쪽에, 앞에 `#if KERNEL_PRIVATE` `#import <kern/clock.h>` — 07 `kern/clock.h` 가 같은 열거자 `Calendar`·`System` 을 정의하므로 둘 다 두면 충돌 | 현재 07 판 동작 |
| `kernserv/ns_timer.h` | 끝에 `#if KERNEL_PRIVATE` `#import <kern/time_stamp.h>` | 현재 07 판 구조 |
| `kernserv/prototypes.h` | `#ifdef KERNEL` 블록의 SDK 두 묶음(`kernserv/kalloc.h`·`mach/message.h` import 와 `assert_wait` … `thread_sleep`; `current_task` … `msg_send_from_kernel`)을 `#ifndef KERNEL_PRIVATE` 로 감쌈 | 현재 07 판 구조(KERNEL_PRIVATE 이면 두 묶음 없음) |

- SDK 쪽에만 있는 줄은 그대로 남는다(예: `prototypes.h` 의 `kernserv/printf.h` import → 진단 4 에서 ddm 에 tty 잠정 정의 3 개를 더했다; `std_types.h` 의 `EXPORT_BOOLEAN`; `mach_types.h` 의 `vm_region_t`·`vm_region_array_t`·`vm_page_data_t`; `HOST_NULL` 은 `#else` 쪽이라 커널에서는 꺼짐). 이 차이는 진단으로 판정한다.
1. 작성 7 개 + PROVENANCE 7 행(출처 SDK 파일 SHA, 끼워 넣은 줄 목록).
2. `stage_headers.py`: `MACH_KERNEL_STRIPPED` 이름은 `nextdev_private/<SDK 경로>` 가 있으면 그것을, 없으면 지금처럼 07 → Darwin. manifest 'authored' 표시.
3. 진단 6(실기, 170 명령) → 기준 `s5p107-regress-1`(= 진단 5) 과 비교. 다르면 원인 분석(특히 printf.h 경로).
4. 같으면 07 의 `src/mach/{mach_types,std_types,mach_traps}.h`, `src/kernserv/{lock,clock_timer,ns_timer,prototypes}.h` 7 개를 은퇴(135 와 같은 절차).

### 136.1 codex 교차검토(QS56) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `kernserv/lock.h` 의 KERNEL_PRIVATE 분기는 SDK 가드 `_KERN_LOCK_H_` **바깥(앞)** 에 둬야 한다 | 07 판도 바깥 구조; 안쪽이면 가드가 `kern/lock.h`(같은 가드)를 막음 | ✅ 바깥에 둔다 |
| `HOST_NULL` 은 `#else` 로 가면 커널에서 꺼지므로 "SDK 쪽에만 남는 줄" 예시와 모순 | 136 본문 확인 | ✅ 문구 정정(위). 07 `kern/host.h:70` 의 정의와 충돌 없음 |
| `prototypes.h` 첫 묶음에 `kernserv/kalloc.h`·`mach/message.h` import 도 들어가야 07 동작과 같음 | 07 판: 두 import 가 `#ifdef KERNEL_PRIVATE #else` 안 | ✅ 표 정정(위) |
| SDK `prototypes.h` 의 `printf.h` import 는 남아 tty 잠정 정의를 더함 | 진단 4 의 ddm 결과와 같음 | ✅ 진단 6 에서 판정(남기는 것이 SDK 본문 원칙) |
| `bcopy`/`bzero` 프로토타입이 libc `memcpy.c`·`memset.c` 의 `unsigned long` 과 충돌할 수 있음(포함 여부 미확인) | 두 파일에 include/import 0 건(grep) | ❌ 해당 없음 |
| `suser(void)` 는 현재 무인자 호출(`ipc_xxx.c:73` `if (!suser())`)과 맞고 07 판 2 인자 선언과는 안 맞음 | 73 행 확인 | ✅ 기록(SDK 판이 호출 형태와 일치) |
| `mach_traps.h` 공개 선언이 K&R 이고 07 판의 `mach/message.h` import 가 없음 | SDK·07 비교 | ✅ 진단 6 에서 판정 |
| 14·5 줄 수, `Makefile.template:689–691` 맞음 | Python 재계산·파일 확인 | ✅ |

### 136.2 구현과 진단 6 결과(2026-10-02)

- 작성 7 개 `07_kernel/nextdev_private/{mach/mach_types.h, mach/std_types.h, mach/mach_traps.h, kernserv/lock.h, kernserv/clock_timer.h, kernserv/ns_timer.h, kernserv/prototypes.h}`: SDK 파일 줄을 하나도 지우거나 바꾸지 않고(Python `difflib` 로 equal/insert 만 확인) 표시 주석과 분기 줄만 넣음(추가 줄 12·6·14·7·7·6·8). `#if`/`#endif` 균형 확인. `prototypes.h` 는 첫 생성에서 두 번째 묶음 닫는 줄이 빠져 지우고 다시 만들었다(배포 전 발견).
- `stage_headers.py`: `mach_pick` 이 `nextdev_private/<SDK 경로>` 를 먼저 본다; manifest `mach-set: authored …`. 테스트 19/19.
- 진단 6(`s5p110-diag-6`, 170 명령 모두 종료 0, `collect` 511): 기준 `s5p107-regress-1` 과 168 같음, 2 다름(`F__ddm.o`·`N__ddm.o`): SDK `prototypes.h` → `kernserv/printf.h` → `sys/tty.h` 의 잠정 정의 `_tthiwat`·`_tthog`·`_ttlowat`(64 B 씩) 추가, 섹션 바이트·재배치 같음(F). 원본에서 세 심볼은 `__data`(초기화 정의, 0x1dae6c·0x1daeec·0x1daeac, 간격 64 = 크기) → common + 초기화 정의는 링크됨(132.3 E1). ddm L1(F): 이전(`s5p107`)과 같은 판정(MATCH 4 / MATCH_UNVERIFIED 3, `__bss` inferred, `__const` 미배치 — 기존 P 사유). 기록 `09_validation/reconstruction/s5p110-diag6-compare-20261002.json`, `s5p110-l1-ddm-F-20261002.json`.
- 반영: 07 의 Darwin verbatim 사본 7 개 은퇴(SHA = Darwin 원문; 기록 `s5p110-retired-07-private-20261002.json`, tar 스크래치). `#ifdef m68k` 분기로만 닿는 SDK `bsd/dev/m68k/autoconf.h` 를 `07_kernel/nextdev/` 에 채택(스테이징이 07 밖 BSD 파일을 요구하지 않도록). PROVENANCE 380 − 7 + 8 = 381 줄, 7 열.
- 반영 뒤 스테이징 `s5p110-final-stage-1`: `bsd_not_adopted`·`mach_not_adopted`·`mach_replaced_07` 모두 0, 진단 6 스테이징과 경로·SHA·미해결 동일 → 진단 6 이 이 07 트리의 회귀 결과(객체 내용 한정).
- 07 에 남은 비-SDK Mach 쪽 헤더: `src/mach/{clock_types,features,ndr}.h`, `src/kernserv/kern_notify.h`(+ `.c`) — SDK 에 없는 이름.

## 137. S5-P111 세부 계획 — Mach4 기본 참고로 미복원 Mach 객체 후보 진단 (코딩 전, 2026-10-02)

배경: D022 — SDK 에 없는 Mach 쪽 이름의 기본 참고는 Mach4. 헤더 묶음은 SDK/NeXTMach/작성판으로 정리됨(133–136). 이제 미복원 객체를 Mach4 를 먼저 보는 방식으로 진단한다.

사실(Python, `06_reconstruction/objects.tsv` 362 개 중 확정·부분 86 개 제외): Mach4 `kernel/` 에 같은 이름 .c 가 있는 미복원 객체 중 크기 있는 Mach 쪽 12 개 —
ipc_kmsg(0x146f38–0x14a0d6), ipc_mqueue(0x14a634–0x14af42), mach_msg(0x1525a8–0x154b28), ast(0x156694–0x1568d8), exception(0x1568d8–0x157956), ipc_kobject(0x1581a8–0x15846a), ipc_mig(0x15846c–0x158fff), mach_clock(0x15bc30–0x15c023), queue(0x161e5c–0x161f4b), syscall_subr(0x165380–0x165949), zalloc(0x16a490–0x16c1c3), vm_kern(0x173ad4–0x174600). (vm_object·ipc_tt 의 작은 조각 행, cons·disk_label 은 제외.) 여러 개는 이전에 Darwin 판으로 시도해 판 차이로 보류됐다(예 ipc_mqueue 의 `ith_rcv_option`, plan 25.x).

1. `stage_headers.py --source-override LOGICAL=KIND:PATH`(진단 전용, 여러 번 가능): 소스 `src/<X>.c` 를 Mach4(`mach4:kernel/...`, 고정 커밋) 또는 NeXTMach(`nextmach:...`, 고정 커밋) 파일로 읽어 같은 논리 경로에 스테이징. 헤더는 지금 규칙(07·SDK·작성판) 그대로 — 즉 "소스 본문은 후보, 구조체는 검증된 헤더". manifest 에 override 기록. 기본 동작 불변(옛/새 출력 비교).
2. 진단 7(실기): 후보 3 벌 × 12 소스, 최종 플래그(F): Mach4 판 12, Darwin 판 12, NeXTMach 판 5(ast, queue, syscall_subr, zalloc, vm_kern — `objects.tsv` 후보에 NeXTMach 이 있는 것). 스테이징 3 개(후보별).
3. 판정: 컴파일 실패는 첫 오류와 원인(빠진 설정 헤더 등), 성공하면 L1(원본 구간은 위 범위, `--place-from-image`) 으로 후보별 MATCH 함수 수·바이트 차이 수를 표로. 이번 회차는 진단만 — 07 변경 없음. 결과로 객체별 채택 계획(어느 판을 바탕으로 할지)을 세운다.
4. Mach4 고유 설정 헤더(`mach_ipc_compat.h` 등)가 없어 실패하면 기록만 하고, 값 결정은 원본 바이트 근거와 함께 다음 회차에 `config_options.tsv` 로.

### 137.1 codex 교차검토(QS57) 판정 → 구현 규칙

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 인용 include 는 **스테이징된 논리 경로** 기준으로 해석(`stage_headers.py` closure) → Mach4 `ast.c` 의 `"cpu_number.h"` 는 07/Darwin `kern/cpu_number.h` 를 읽음 | Mach4 `kern/ast.c:44` `#include "cpu_number.h"`, Mach4 에도 `kern/cpu_number.h` 있음 | ✅ 의도한 동작(구조체·헤더는 검증된 07 판). manifest 로 기록 |
| Mach4 `vm_kern.c:38` `"vm_param.h"` 는 스테이징된 `vm/` 에 없음 | 38 행 확인; Mach4 `kernel/vm/vm_param.h` 도 없음(Mach4 빌드는 -I 경로로 찾음) | ✅ 실패하면 기록, 대응은 결과 뒤 |
| `norma_ipc.h` 가 없어 실패; `mach_ipc_compat.h`·`mach_kdb.h` 는 생성판 있음 | 12 소스의 include 집계(Python): `norma_ipc.h` 5 회, 07/생성/SDK/Darwin 어디에도 없음; codex 가 든 `ipc_kmsg.c:37` 은 실제로는 `#include <cpus.h>`(줄 번호 틀림) | ⚖️ 아래 설정 4 개 추가로 대응(실패를 숨기는 것이 아니라 원본 근거가 있는 값) |
| override 키·소스 경로를 고정 revision 으로 검증, 선택 파일·해시 기록 | `--subst` 검증은 BSD 전용(`load_subst`) | ✅ 별도 검증 함수 |
| 12 대상·범위 맞음, 확정/부분과 겹치지 않음; seq 161 ipc_tt·209 vm_object 는 **같은 시작 주소로 이미 확정**, 조각은 166·164 | `objects.tsv` 재확인(Python) — 내 앞선 설명("다른 시작 주소")이 틀렸고 codex 가 맞음 | ✅ 정정 |
| Darwin `kern/queue.c` 가 있는데 `objects.tsv` seq 187 후보에 빠짐 | Darwin 파일 존재 확인 | ✅ Darwin 후보도 빌드(표는 이번에 고치지 않고 기록) |
| L1 `--ranges` 는 심볼→구간 JSON 이고 OBJECT_MATCH 를 제한하지 않음; 정적 함수는 따로 봐야 함(zalloc·vm_kern) | `l1_compare.py` 사용법(지금까지 `cmpobj.py` 가 ghidra 함수 경계로 JSON 생성) | ✅ 표 구간은 포함 검사로만 쓰고, 정적 함수(build-only)는 `cmpobj` 의 gapdiff/build-only 출력으로 따로 기록 |
| NeXTMach `ast.c`·`zalloc.c` 는 m68k 쪽 헤더를 씀 | NeXTMach `ast.c:59` `#import <machine/cpu.h>`, `zalloc.c:154` `#import <sys/printf.h>`(codex 가 든 `machine/pcb.h`·`next/spl.h` 는 그 줄이 아님 — 줄 번호 틀림) | ⚖️ NeXTMach 후보 실패는 "i386 부적합" 일 수 있음을 판정에 반영 |

설정 4 개 추가(가설, `config_options.tsv`): `norma_ipc`(NORMA_IPC 0), `mach_pcsample`(0), `mach_ipc_test`(0), `mach_machine_routines`(0). 근거: 원본 심볼표에 `norma_*`(유일한 일치 `_timer_normalize` 는 무관)·`pc_sample`·`machine_routines`·`ipc_test` 0 건; Darwin 0.1 에 이 옵션 없음. 07·Darwin·Mach4 대상 소스에 `#ifdef`/`defined()` 사용 0 건 → `meta_features.h` 를 통해 모든 컴파일에 들어가도 기존 85 소스 동작 불변 예상 — 진단 7 에 85 소스 F 회귀(85 명령)를 함께 넣어 확인한다.

### 137.2 구현과 진단 7 결과(`s5p111-diag-7`, 2026-10-02)

- `stage_headers.py --source-override`(고정 커밋 blob 검증 `verify_pinned`, manifest `source_override`). 옵션 없을 때 옛/새 `--list` 출력 동일(기본 423 줄, `--bsd-set --mach-set` 411 줄), 테스트 19/19. 설정 4 개 추가로 생성 헤더 4 개 + `meta_features.h` 갱신(`gen_config_headers.py --check` 통과).
- 85 소스 F 회귀(같은 실행): `s5p110-diag-6` F 와 85/85 같음(`s5p111-regress-compare-20261002.json`) → 설정 4 개 추가는 기존 객체에 영향 없음.
- 후보 컴파일(`s5p111-diag7-candidates-20261002.json`): Darwin 12 중 5 성공(mach_clock, queue, syscall_subr, zalloc, vm_kern), 실패 7 은 Darwin 이후 메시지 형식(`mach_msg_descriptor_t`, `MACH_MSGH_BITS_OLD_FORMAT`, `mach_msg_trailer_t`, `MAX_TRAILER_SIZE`, `ikm_sender`)과 `sys/signalvar.h`. Mach4 12 중 1 성공(ipc_kobject); 실패는 함수 인자 수(`thread_block`, `ipc_kmsg_get`, `ipc_mqueue_receive`) 등 OPENSTEP 헤더와의 판 차이, 구조체 필드(`chain`, `type`), `IKM_BOGUS`, `device/device_types.h`, `vm_param.h`, `queue.h` 와 중복 정의. NeXTMach 5 중 1 성공(queue, 그러나 `__text` 0 B — m68k 쪽 조건).
- L1(`s5p111-l1-<객체>-<후보>-20261002.json`):
  - **queue (Darwin): OBJECT_MATCH**, 7 함수 MATCH, 239 B = 원본. Darwin `kern/queue.c` 는 `#define _KERN_QUEUE_FUNCTION_SCOPE_` + include 뿐이고 함수 본문은 이미 07 에 있는 `kern/queue.h` 에서 온다. Mach4 `queue.c` 는 같은 함수를 .c 에 정의해 07 `queue.h` 와 중복 정의.
  - **syscall_subr (Darwin)**: 9 함수 MATCH(1028 B), 원본 1481 B 에는 `_map_fd` 가 더 있다(빠진 함수 1 개).
  - ipc_kobject (Mach4): 694 vs 706 B, `_ipc_kobject_server` 516/500, `_ipc_kobject_destroy` 48/76 — 가까우나 다름.
  - mach_clock·zalloc·vm_kern (Darwin): 함수 구성·크기가 크게 다름(배치 실패).

## 138. S5-P112 세부 계획 — queue(A 후보)·syscall_subr(Darwin + NeXTMach `map_fd`) 채택 (코딩 전, 2026-10-02)

사실:
- queue: 진단 7 에서 Darwin `kern/queue.c`(본문은 `#define _KERN_QUEUE_FUNCTION_SCOPE_` + `#include <kern/queue.h>`, 함수 본문은 이미 07 에 있는 `kern/queue.h`) 가 OBJECT_MATCH(7 함수, 239 B). Mach4 판은 07 `queue.h` 와 중복 정의(137.2).
- syscall_subr: 원본 [0x165380, 0x165949) 1481 B = Darwin 9 함수(1028 B, 모두 MATCH, 같은 순서) + 마지막 `_map_fd` 0x165784 453 B(+ 채움 3 B). 원본 `_map_fd` 호출 순서(capstone): `_getf`, `_vm_allocate`, `_copyout`, `_vm_deallocate`, `_copyin`, `_vm_map_check_protection`, `_vnode_pager_setup`, `_pmap_create`, `_vm_map_create`, `_vm_allocate_with_pager`, `_vm_map_copy`, `_vm_deallocate`, `_vm_map_deallocate`, 끝에 `_active_u` 두 번 — NeXTMach `mk-108.1/kern/syscall_subr.c:637–` 의 `map_fd`(vnode·`vm_allocate_with_pager`·`crhold(u.u_cred)`)와 같은 순서. Darwin 의 `map_fd` 는 `bsd/kern/kern_mman.c`(다른 위치).
- `map_fd` 가 쓰는 BSD 정의는 SDK 에 있다: `bsd/sys/vnode.h:40` `vm_info`, `bsd/sys/file.h:59` `getf()`, `bsd/sys/ucred.h:29` `crhold`, `bsd/sys/user.h:350` `u` → `active_u[cpu_number()]`.

1. `07_kernel/src/kern/queue.c` = Darwin verbatim. 경계 검사(앞뒤 틈, 다른 확정 객체와 겹침 없음) 후 objects_confirmed A, functions 7 행, 증거 `x86-queue.md`.
2. `07_kernel/src/kern/syscall_subr.c` = Darwin 판 + 파일 끝에 NeXTMach `map_fd` 블록(같은 블록의 import 포함, 출처 줄 범위와 NeXTMach 저작권 표시 유지, D013). NeXTMach 의 import 중 우리 트리에 없는 이름은 같은 정의를 가진 이름으로 바꾼다(예: `sys/kern_return.h` → `mach/kern_return.h`, `vm/vm_param.h` → `mach/vm_param.h`) — 바꾼 줄은 MODIFICATIONS 에 기록. Darwin 9 함수는 손대지 않는다.
3. 빌드(실기): F/N, L1. 목표: OBJECT_MATCH. 다르면 함수별 diff 로 원인(헤더 판·인자 형태) 분석.
4. 통과하면 PROVENANCE(2 파일), MODIFICATIONS(syscall_subr), functions(10 행), objects_confirmed, 증거 문서·diff.

### 138.1 codex 교차검토(QS58) 판정 → 구현 규칙

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| queue A 는 경계 확인 뒤 타당: 앞 2 B `00 00`(processor 끝 0x161e5a), 뒤 0x161f4b 1 B 가 `_kdp_packet`(0x161f4c) 앞 채움인지 | 원본 바이트(Python): 0x161e58 `5d c3 00 00`, 0x161f4b `00` 뒤 0x161f4c `55 89 e5`; 심볼표 0x161e40 `_processor_set_threads` … 0x161f4c `_kdp_packet` | ✅ 두 틈을 행에 기록 |
| `map_fd` 는 453 B(456 은 다음 심볼까지) | Python `0x165949 − 0x165784 = 453`, 남는 3 B 는 채움 | ✅ 정정 — 내 오류 |
| NeXTMach 블록 import(620–635)만으론 `u`/`active_u` 를 주는 `sys/user.h`(NeXTMach 165 행)가 빠짐 | 165 행 `#import <sys/user.h>` 확인 | ✅ 추가 |
| `struct vm_info` 정의가 07 트리에 없음(SDK `vnode.h:40` 은 포인터만) | grep: 정의는 NeXTMach `kern/mfs.h:49–69` 에만. 원본 `_map_fd` 끝 0x16591f `cmp [eax+0x30],0` = `vm_info->cred`; 원본 심볼표에 `_mfs_get`·`_mfs_cache_trim` 등 mfs 함수 존재 | ✅ NeXTMach `kern/mfs.h` 를 07 에 verbatim 채택(D013), 블록에 `#import <kern/mfs.h>`(NeXTMach 170 행, `#if NeXT`) |
| `sys/file.h` 가 `kernserv/queue.h` 를 가져오며 `kern/queue.h` 와 가드 공유 가능 | SDK `file.h:35` 확인; 07 `kern/queue.h:59` 가드 `_KERN_QUEUE_H_` | ⚖️ 빌드 오류로 드러남 — 결과로 판정 |
| `map_fd` 반환형을 명시하라(SDK 선언 `kern_return_t`) | i386 `kern_return_t` = int | ❌ NeXTMach 본문 그대로(묵시 int 는 같은 코드). 저작 줄을 늘리지 않는다 |
| `vm_allocate_with_pager` 6 인자·`vm_map_copy` 7 인자는 07 구현과 같음 | `vm_user.c:83`, `vm_map.c:1618` | ✅ |

`vm/vm_param.h`(NeXTMach 전용 이름, 07/Darwin 에 없음)는 `mach/vm_param.h` 로 바꾼다(`round_page`·`trunc_page` 출처) — MODIFICATIONS 기록.

### 138.2 결과(2026-10-02)

- `s5p112-build-1`: syscall_subr 실패 — NeXTMach `sys/kern_return.h:57` 이 `machine/kern_return.h`(m68k 식) 요구 → 블록의 import 를 `mach/kern_return.h` 로 바꿈(138.1 의 `vm_param.h` 와 같은 처리).
- `s5p112-build-2`(F·N·`-E`, 6 명령 모두 0, collect 19 파일): queue F·N OBJECT_MATCH 7/7; syscall_subr F OBJECT_MATCH 10/10(1481 B), N 은 10 함수 MATCH 이나 `__data`·`__common` 미배치(최종 플래그 아님).
- 채택: `07_kernel/src/kern/queue.c`(Darwin verbatim), `src/kern/syscall_subr.c`(Darwin + NeXTMach `map_fd`), `src/kern/mfs.h`(NeXTMach verbatim). objects_confirmed 76 → 78 줄(A 2), functions 759 → 776 줄(17 행 high, id 중복 0), PROVENANCE 381 → 384, MODIFICATIONS 66 → 67. 증거 `x86-queue.md`, `x86-syscall_subr.md`, `x86-syscall_subr.diff`.
- 새로 안 사실: 원본에 NeXTMach 의 mapped-file 계층(`_mfs_get`, `_mfs_cache_trim`, `_mfs_fsync` … 원본 심볼표)이 있다 → NeXTMach `kern/mfs.c` 가 다음 후보.

## 139. S5-P113 세부 계획 — NeXTMach `kern/mfs_prim.c` 복원 (코딩 전, 2026-10-02)

사실:
- 원본 객체는 [0x15dfe4, 0x1600ca) — `objects.tsv` 의 seq 178 `mfs_prim.c`(…0x15fe6e)와 seq 179 `mapfs.c`(0x15fe70…)는 **한 객체**: 원본 함수 32 개(`_mfs_init` … `_vmp_push_all`, `_vm_info_free` … `_vm_set_error`)가 NeXTMach `mk-108.1/kern/mfs_prim.c` 의 정의 순서와 같고(Python 비교), 원본에만 2 개가 더 있다: `_mfs_fsync_invalidate`(0x15f78c, 308 B, `mfs_fsync` 뒤)와 `_vmp_push_all`(0x15fe70, 460 B, `vmp_push` 뒤). 둘은 NeXTMach·Mach4·SDK 에 없고 Darwin `kern/mapfs.c` 에 `mapfs_fsync_invalidate`(:1532)·`vmp_push_all`(:1930)로 있다(Darwin 은 mfs 를 mapfs 로 개명한 후대 판).
- 진단(`s5p113-diag-2`, 스테이징 사본만 수정 — `vm/vm_param.h` → `mach/vm_param.h`, `blkflush(vp, btodb(offset), bsize)` → `blkflush(vp, btodb(offset, VOP_DEVBLOCKSIZE(vp)))`, `-Isrc/components/driverkit-1` 추가): 컴파일 성공, 7330 B(원본 [0x15dfe4,0x15fe6e) 7818 B). 크기가 다른 함수 5 개(`_mfs_init` 180/208, `_mfs_io` 972/1164, `_mfs_fsync` 328/340, `_vmp_invalidate` 220/304, `_vmp_push` 528/534), 나머지는 크기 같음.
  - `blkflush` 형태 근거: 원본 0x15f378·0x15f41c 에서 `v_op` 의 +0x80(SDK `vnode.h:114` `vn_devblocksize`, `:160` `VOP_DEVBLOCKSIZE`) 호출 → `div` → 인자 2 개로 `_blkflush` 호출.

1. `07_kernel/src/kern/mfs_prim.c` = NeXTMach verbatim 에서 시작(notice 유지, D013). 수정은 모두 원본 바이트 근거와 함께 MODIFICATIONS 에 기록:
   - include 이름(`vm/vm_param.h` → `mach/vm_param.h`), `blkflush` 2 곳(원본 호출 형태).
   - 빠진 2 함수: Darwin `mapfs_fsync_invalidate`·`vmp_push_all` 본문을 후보로 같은 위치에 넣는다(이름은 원본 심볼 `mfs_fsync_invalidate`, `vmp_push_all`; Darwin 식 이름 변경분은 NeXTMach 이름으로 되돌림). Darwin 출처·APSL 표시.
   - 크기가 다른 5 함수는 함수별 disasm 비교로 원인을 찾아 최소 수정(NeXTMach → 원본 판 차이).
2. 빌드 셋: `--source-override` 대신 07 파일을 직접 스테이징(`--prefer-07`). 명령에 `-Isrc/components/driverkit-1` 포함(ddm 명령과 같은 -I 열).
3. 판정: L1 [0x15dfe4, 0x1600ca) 범위 OBJECT_MATCH 를 목표. 데이터·common 은 36.1 절차.
4. 단계마다 실기 빌드 → 함수 diff → 수정 반복. 각 반복의 수정과 근거를 기록.

### 139.1 codex 교차검토(QS59; 첫 요청은 900 s 시간 초과, 범위를 줄여 재요청) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| Darwin 두 함수의 NeXTMach 에 없는 식별자: `mapfs_fsync_invalidate`, `MFS_NOFLUSH`/`MFS_NOINVALID`(Darwin `mapfs.h:106–107` 값 1·2), `v_vm_info`(NeXTMach `vm_info`), 페이지 필드 `nfspagereq`·`dry_vp`, `SCRUBVM3`, `vm_page_completeio`, `vm_info` 필드 `nfsdirty`·`filesize`·`vnode`, `current_proc` | Darwin `mapfs.c:1526–1574`, `1928–2039` 직접 읽음; 07 `vm/vm_page.h:145` 에 `nfspagereq` 있음, `dry_vp` 는 `SCRUBVM3` 분기 안(미정의 → 꺼짐) | ✅ `vmp_push_all` 은 Darwin 판 `vm_info` 필드·4.4BSD `VOP_GETATTR` 를 써서 원본 판과 다를 가능성이 큼 → 원본 바이트로 별도 복원(마지막 단계) |
| 두 함수 모두 Darwin 에서 `#if 0`(dead code elimination) 안 | 1525·1927 행 | ✅ Darwin 에서는 죽은 코드, OPENSTEP 원본에는 살아 있음 |
| NeXTMach 의 `btodb(`/`blkflush(` 는 899 행 하나, `dbtob(`·`DEV_BSIZE` 없음 | 내 grep 동일 | ✅ 단 원본 `_mfs_io`(0x15efdc–0x15f468)에는 `_blkflush` 호출이 **두 곳**(0x15f38d, 0x15f430) → mfs_io 구조 차이(크기 972/1164)와 함께 분석 |

진행 순서: (1) NeXTMach + include·`blkflush` 형태 수정으로 07 파일 생성(진단 2 와 같은 내용), (2) 크기가 다른 5 함수를 Darwin `mapfs.c` 의 같은 함수와 원본 바이트로 비교해 최소 수정, (3) 빠진 2 함수.

### 139.2 결과(2026-10-02)

- 반복 `s5p113-it1`–`it6`(07 파일), 변형 `s5p113-v1`(7 형태), `s5p113-v2`(Darwin 식 3 형태). 수정 내용과 근거는 MODIFICATIONS·증거 문서. 요지:
  - 크기가 다른 5 함수: `mfs_fsync`(반환 위치), `vmp_invalidate`·`vmp_push`(Darwin 의 `nfspagereq`·`wire_count` 등), `mfs_init`(Darwin `mapfs_init` 의 `long long` 식만 바이트 동일), `mfs_io`(Darwin 의 `vmp->error = 0`, `blkflush` 3 인자, `nmfsbuf` 블록은 어느 참고 판에도 없어 바이트에서 작성).
  - 빠진 2 함수: Darwin `#if 0` 안의 `mapfs_fsync_invalidate`·`vmp_push_all` 을 원본에 없는 줄만 빼고 채택.
- 최종 `s5p113-it6`: OBJECT_MATCH 32/32(8422 B), common 8 개 간격 안. 등급 A.
- 기록: objects_confirmed 78 → 79 줄, functions 776 → 808 줄(32 행 high), PROVENANCE 384 → 385, MODIFICATIONS 67 → 68, 증거 `x86-mfs_prim.md`·`.diff`.
- 정정: 138 의 "원본 `blkflush` 인자 2 개" 판독은 틀렸다 — `bsize` 를 먼저 push 하는 3 인자 호출이다(139 반복 4 에서 발견).

## 140. S5-P114 세부 계획 — NeXTMach 후보 일괄 진단 (BSD 계층 포함, 코딩 전, 2026-10-02)

근거: D020(BSD 소스 기준 판 = NeXTMach), D021(BSD 헤더 = SDK/NeXTMach 묶음), D022(Mach 내부 기본 참고 = Mach4). 137–139 에서 "NeXTMach 바탕 + 원본 바이트로 확인한 최소 수정" 방식이 queue·syscall_subr·mfs_prim 에서 A 를 냈다.

사실(Python, `objects.tsv` 에서 확정·부분과 겹치지 않는 275 객체 중 후보에 NeXTMach 가 있는 것): 149 개(대부분 `bsd/`·`net/`·`netinet/`·`nfs/`·`rpc/`·`ufs/`·`specfs/`·`next/`).

1. 진단 8: NeXTMach 후보 파일이 하나로 정해지는 객체를 `--source-override src/<논리 경로>=nextmach:<경로>` 로 하나씩 스테이징(논리 경로는 Darwin 판이 있으면 그 경로, 없으면 `src/bsd/<NeXTMach 디렉터리>/<파일>`), 최종 플래그로 컴파일. `next/`(68k 기계 의존)는 제외하고, 여러 파일이 후보인 행(`a.c,b.c`)은 첫 진단에서 제외.
2. 성공한 것은 L1(원본 구간은 `objects.tsv` 의 text_start/text_end, 경계는 포함 검사로만 사용). 결과 표: 객체별 컴파일 여부·첫 오류·함수 수(빌드/원본)·MATCH 수·크기.
3. 07 변경 없음. 결과로 다음 회차의 객체별 채택 순서를 정한다(MATCH 비율이 높은 것부터). 같은 첫 오류가 여러 객체에 공통이면(예: 헤더 판 차이) 그 원인을 먼저 다룬다.

### 140.1 codex(QS60) 판정과 NeXTMach config 헤더

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| NeXTMach BSD 소스는 `"../h/x.h"` 가 아니라 `#import <...>`; `kern_xxx.c:64` `<cputypes.h>`·`<quota.h>`, `if.c:28` `<ether.h>` 같은 config 생성 헤더를 바로 씀 | 두 파일 줄 확인 | ✅ 아래 설정 추가 |
| NeXTMach `bsd/X.c` 를 `src/bsd/<dir>/X.c` 로 두면 `src/bsd/bsd/X.c` 가 됨 | 규칙 확인 | ✅ NeXTMach `bsd/X.c` 는 `src/bsd/kern/X.c`(Darwin 의 같은 역할 디렉터리)로 |

config 헤더(NeXTMach `conf/Makefile.template:459` 의 FEATURES 계열, `conf/MASTER.next` RELEASE 태그가 1차 후보, 원본 심볼로 확인; Python grep 결과):
- 1: `NFS_SERVER`(`_rfsdisptab`, `_nfs_svc`), `NFS_CLIENT`(`_nfs_vnodeops`, `_async_daemon`), `SUN_RPC`(`_svckudp*`, `_clntkudp*`), `NETHER`(`_arpinput`), `NLOOP`(`_loattach`), `NEN`(`_en_recv_pkt`, `_en_send_pkt`; 가설).
- 0: `QUOTA`(`_chkdq`·`_getinoquota`·`_quotactl` 0), `SUN_LOCK`(`_lockf`·`_klm_*` 0), `SECURE_NFS`(`_authdes*` 0), `NNFSMEAS`(0), `NIMP`(`_impopen` 0), `NHY`(0), `NOD`(`_odattach` 0), `DLI`(0), `GDB`(`_gdb*`/`_kgdb*` 0; i386 은 kdp — 가설).
- `NPTY` 32: `MASTER.next:118` 값(가설, `tty_pty` 복원 때 데이터 크기로 확인).
- `cputypes.h`: config 의 `cpu "i386"` 줄에서 생기는 헤더지만 생성 규칙 원문이 없다. 대상 BSD 파일에 cpu 매크로 조건이 없음(grep) → **빈 헤더**(가설). 생성기에 매크로 `-` = 정의 없는 헤더 허용.
- 07 의 기존 파일에서 이 이름들은 주석에만 나옴(grep: SDK `errno.h`·`signal.h`·`mbuf.h`·`if_arp.h` 의 주석) → 기존 객체 영향 없음 예상, 진단 8 에 85 소스 F 회귀 포함.

### 140.2 codex 교차검토(QS61) 판정 — 순서 기록: 설정 추가(140.1)는 이 검토 전에 코드에 반영했다(진단 실행 전). 이후로는 검토 뒤 반영을 지킨다.

내가 틀린 것: 140.1 의 심볼 근거 검색이 좁았다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `QUOTA=0` 은 원본 `_dquot`·`_dquotNDQUOT`(NeXTMach `conf/param.c:144–146` 의 `#if QUOTA`)과 충돌 | symbols.tsv grep: `_dquot` 0x1e8cc4, `_dquotNDQUOT` 0x1e8cc8, 더해 `_ndquot`·`_ndqb` 있음; quota 함수는 여전히 0 | ⚖️ 0 유지(가설)·반대 근거 기록. param.c 계열 객체를 다룰 때 판정 |
| `SUN_LOCK=0` 은 `_spec_lockctl`(NeXTMach `spec_vnodeops.c:732` `#if SUN_LOCK`)·`_lf_lockctl` 과 충돌 | grep: `_spec_lockctl` 0x13a4c4, `_lf_lockctl` 0x142008, `_lf_svnode_hash`, `_flock` | ✅ 1 로 정정 |
| `SECURE_NFS` 는 반증 없음(`_svcauth_des` 없음) | grep: `_xdr_des_block` 만 있음(xdr 기본 타입) | ✅ 0 유지 |
| 07 트리에 이 이름의 조건문 사용 0 | 내 grep 동일 | ✅ |

### 140.3 진단 8 결과(`s5p114-diag-8`, 2026-10-02)

- 201 명령: 85 소스 F 회귀 85/85 종료 0 이고 `s5p110-diag-6` 과 85/85 같음(설정 17 개 추가 영향 없음). NeXTMach 후보 116 소스 중 54 개 컴파일.
- 실패 첫 오류(상위): `bsd/i386/reg.h` 없음 12, `vm/vm_param.h` 6, `machine/boolean.h` 4, 구조체 필드/인자 차이 다수 — NeXTMach(68k·Mach 2.5)와 OPENSTEP 헤더 판 차이.
- L1(`09_validation/reconstruction/s5p114-diag8-l1-summary-20261002.json`, 개별 `s5p114-l1-*-NM-*.json`):
  - **NeXTMach 그대로 OBJECT_MATCH 8 개**: xdr_mbuf(11 함수), xdr_mem(9), kern_acct(3), subr_kudp(2), svc_auth(2), svc_auth_unix(2), uipc_pipe(1), clnt_perror(1). (in.c·tcp_debug 는 빌드 `__text` 0 B 라 판정에서 제외.)
  - 대부분 MATCH: netbuf 12/13, xdr 12/15, svc_kudp 8/11, rpc_prot 6/7, route 5/6 등 — 다음 회차 후보.
- 8 개 실제 경계(빌드 심볼 위치가 원본과 한 Δ 로 일관, Python): xdr_mbuf [0x138230,0x1385f3), xdr_mem [0x1385f4,0x138773)(objects.tsv 의 41 B 는 틀림 — 383 B), kern_acct [0x103088,0x10349c), subr_kudp [0x136c00,0x136dd9), svc_auth [0x137340,0x13739d), svc_auth_unix [0x1373a0,0x137528), uipc_pipe [0x114b8c,0x114bd4), clnt_perror [0x135dbc,0x135df1). 앞뒤는 정렬 채움 `00`(≤3 B, 2^2) 이거나 앞 함수 코드 끝.

### 140.4 채택(코딩) — 8 개 NeXTMach verbatim

1. NeXTMach 파일을 논리 경로 그대로 `07_kernel/src/...` 에 verbatim 복사(D013: 출처·notice 유지).
2. 07 만으로 다시 스테이징·빌드(실기, 최종 플래그) → 8 개 L1 OBJECT_MATCH 재확인(소스 override 없이).
3. 기록: PROVENANCE 8, functions 31, objects_confirmed 8(A), 증거 `x86-nextmach-batch1.md`.

### 140.5 채택 결과(2026-10-02)

- 8 개 NeXTMach 파일을 `07_kernel/src/bsd/{kern,rpc}/` 에 verbatim. 07 만으로 빌드한 `s5p114-adopt-1`(8 명령, collect 25 파일)에서 8/8 OBJECT_MATCH(`s5p114-adopt-l1-*-F-20261002.json`).
- 이 빌드가 07 밖에서 읽은 BSD 헤더 20 개(모두 SDK 판: `sys/{vnode,vfs,acct,socketvar,unpcb,syslog}.h`, `rpc/*` 13 개, `ansi/{stdio,stdarg}.h`)를 `07_kernel/nextdev/` 에 채택(실기 SHA 일치). 다시 스테이징하니 `bsd_not_adopted` 0, 스테이징 바이트 동일.
- common 심볼(acct·mbuf·route 계열) 모두 원본 간격 안.
- 기록: objects_confirmed 79 → 87 줄(A 8), functions 808 → 839 줄(31 행; 정적 함수는 `(static 이름)`), PROVENANCE 385 → 413 줄(헤더 20 + 소스 8), 증거 `x86-nextmach-batch1.md`.

## 141. S5-P115 세부 계획 — 근접 4 객체(af·netbuf·rpc_prot·rpc_callmsg)와 `-DINET`, 작성판 `rpc/types.h` (코딩 전, 2026-10-02)

사실(진단 8 L1, fndiff, 원본 바이트):
- netbuf `_nb_free`: 원본 `call _m_freem`(0x120a73), NeXTMach `net/netbuf.c:86` `m_free((struct mbuf *)nb)` → 빌드 `_m_free`. 나머지 12 함수 MATCH.
- rpc_prot `_xdr_replymsg`, rpc_callmsg `_xdr_callmsg`: 원본 `_kalloc`, 빌드 `_malloc`. 원인: SDK `bsd/rpc/types.h:36–41` 은 `mem_alloc` = `malloc`(공개판); NeXTMach `rpc/types.h:26–34` 는 `#ifndef KERNEL … #else #import <kern/kalloc.h> mem_alloc = kalloc, mem_free = kfree #endif`.
- af `afswitch` 데이터: 원본 0x1db790 의 34 워드 = 칸 2·3 `inet_hash/inet_netmatch`, 칸 6 `null_*`(NS 없음) → `INET` 정의, `NS` 미정의. 빌드는 `INET` 미정의라 참조 4 개 다름. NeXTMach·Darwin `conf/MASTER` 의 `options INET`(헤더 태그 없음 = config 가 `-DINET` 으로 넘기는 옵션).
- 07 의 기존 파일에 `INET` 조건 사용 0(grep).

1. 최종 빌드 플래그에 `-DINET` 추가(템플릿 `s5p107-build.cmd` 와 반복 스크립트). 근거 위 afswitch. 확정·부분 객체 전체(85 + 11) 회귀.
2. `07_kernel/nextdev_private/bsd/rpc/types.h`: SDK 본문 + `#ifndef KERNEL … #else #import <kern/kalloc.h> + kalloc/kfree 정의 #endif`(NeXTMach `rpc/types.h:26–34` 의 분기 줄; D023 방식, BSD 쪽은 NeXTMach 가 분기 출처). 이미 채택한 rpc 6 객체 회귀.
3. `07_kernel/src/bsd/net/netbuf.c` = NeXTMach + `nb_free` 의 `m_free` → `m_freem`(근거 0x120a73).
4. af.c·rpc_prot.c·rpc_callmsg.c 를 NeXTMach verbatim 으로 07 에 두고 빌드·L1·경계, 통과하면 기록.

### 141.1 codex 교차검토(QS62) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `netbuf.c:86` 은 `nb_free` 안의 유일한 `m_free` | 83–87 행 열어 확인 | ✅ |
| 07 에 `INET` 조건 직접 사용 0, 그래도 전역 `-DINET` 은 전체 회귀 필요 | 내 grep 동일 | ✅ 회귀 포함 |
| SDK `rpc/types.h` 35–41 행 블록 전체(`#include <stdlib.h>` 포함)를 감싸야 함 | 35–41 행 `cat -A` 확인 | ✅ 블록 전체를 `#ifndef KERNEL` 쪽에 둔다 |

### 141.2 결과(2026-10-02)

- `s5p115-build-1`(100 명령, `-DINET`): 기존 확정 96 객체 96/96 이전 최종 빌드와 같음; 새 4 객체(af, netbuf, rpc_prot, rpc_callmsg) 모두 OBJECT_MATCH, 경계 일관(rpc_callmsg 끝 = rpc_prot 시작 0x1365cc).
- 이 빌드의 07 밖 헤더 8 개 채택: SDK `sys/{dir,quota,file,mount,fcntl}.h`, `net/af.h`, `mach/thread_switch.h`, 그리고 `kernserv/queue.h` 는 SDK 판이 `KERNEL_PRIVATE` 분기 없는 공개판(Darwin 판과 diff: 분기 5 줄) → `lock.h` 와 같은 작성판을 `nextdev_private/` 에 두고 SDK 사본은 넣지 않음. 앞서 syscall_subr·mfs_prim 채택 때 이 헤더 확인을 빠뜨렸다(이번에 보완).
- `s5p115-build-2`(작성판 queue.h 반영): 100/100 이 build-1 과 같음.
- 기록: objects_confirmed 87 → 91 줄(A 4), functions 839 → 863 줄(24 행), PROVENANCE 413 → 426 줄, MODIFICATIONS 68 → 69(netbuf), 증거 `x86-nextmach-batch2.md`·`x86-netbuf.diff`. 템플릿 `s5p107-build.cmd`·README·GCC27 문서에 `-DINET`.

## 142. S5-P116 — 진단 9 결과와 3 객체 채택(140.4 와 같은 절차, 2026-10-02)

- 진단 9(`s5p116-diag-9`, 남은 NeXTMach 후보 103 소스, `-DINET`·작성판 `rpc/types.h` 반영): 42 컴파일. 새 OBJECT_MATCH: nfs_export(8 함수), xdr_array(1), xdr_reference(1) — 진단 8 에서는 `mem_alloc`(malloc/kalloc) 차이로 BOUNDARY·DIFF 였다. 요약 `09_validation/reconstruction/s5p116-diag9-l1-summary-20261002.json`.
- 채택 절차를 스크립트로 묶음(스크래치 `adopt_batch.py`; 07 배치 → 07 만으로 빌드 → 심볼 Δ 일관성·L1 OBJECT_MATCH 필수 → common 간격 → 07 밖 헤더 채택 → 재스테이징 동일 확인 → 기록). 실패 조건이면 기록하지 않고 멈춘다.
- 다음 근접 후보: xdr(12 MATCH + 3 MATCH_UNVERIFIED, `__bss` 추정), svc_kudp(3 DIFF), uipc_domain(1 DIFF), route(1 DIFF), tcp_timer·kern_subr·vfs_lookup·authunix_prot(BOUNDARY).

### 142.1 결과 / 143. 근접 3 객체 수정 채택 (2026-10-02)

- 142 채택(`s5p116-adopt-1`): nfs_export·xdr_array·xdr_reference 3/3 OBJECT_MATCH, SDK 헤더 3 개(`sys/pathname.h`, `nfs/nfs.h`, `nfs/export.h`) 채택, 재스테이징 동일. objects_confirmed 91 → 94, functions 863 → 873, PROVENANCE 426 → 432.
- 143 수정(모두 원본 바이트 근거, 파일에 `plan 143` 표시):
  - svc_kudp: `kmem_alloc`/`kmem_free` 7 곳 → `kalloc`/`kfree`(원본 `_svckudp_create`·`_svckudp_destroy`·`_svckudp_dupsave` 가 `_kalloc`/`_kfree` 호출; 남은 3 DIFF 의 전부).
  - uipc_domain `pfctlinput`: `(*pr->pr_ctlinput)(cmd, sa, (caddr_t)0)`(원본은 0 을 하나 더 push; Darwin `uipc_domain.c:226` 과 같은 형태).
  - route `rtrequest`: `register struct rtentry *rt = 0;`(원본 0x121db9 `xor esi,esi`, esi 는 이후 `rt = mtod(m, …)`).
- 절차는 142 의 스크립트(OBJECT_MATCH 아니면 기록 없이 멈춤).

### 143.1 결과(2026-10-02)

- `s5p117-adopt-1`: svc_kudp(11 함수, 실제 객체 1165 B — objects.tsv 1052 B 는 짧음), uipc_domain(6), route(6) 모두 OBJECT_MATCH, A. objects_confirmed 94 → 97.
- authunix_prot(`s5p117-adopt-2`): `xdr_authkern` 이 `time.tv_sec` 대신 `getthetime(&now)` 의 지역 `timeval` 을 인코딩(원본 0x1352b7 `_getthetime`, 프레임: groups −0x40, timeval −0x48, name −0x4c) → 지역 선언 위치와 호출 두 줄 수정으로 OBJECT_MATCH, A. objects_confirmed 97 → 98, functions 896 → 898.
- 스크립트 보완: 빌드·L1·common 검사 실패 시 07 에 복사한 파일을 지우고 멈춘다(기록 전).

## 144. S5-P118 — SDK 에 없는 i386 BSD 비공개 헤더 (2026-10-02)

사실(Python): SDK `bsd/machine/*.h` 가 `ARCH_INCLUDE(bsd/, X)` 로 찾는 `bsd/i386/X` 중 SDK 에 없는 것 5 개 — `spl.h`(132 에서 작성), `reg.h`, `psl.h`, `cons.h`, `unix_traps.h`. NeXTMach 은 68k `next/` 판뿐. Darwin 은 `reg.h`·`psl.h`·`spl.h` 를 가진다(모두 `KERNEL_PRIVATE` 전용).
- 진단 9 실패 1 위(12 건)가 `bsd/i386/reg.h`. → `07_kernel/nextdev_private/bsd/i386/{reg,psl}.h` 를 Darwin 본문 그대로(설명 주석 + `KERNEL_PRIVATE` 본문) 둔다 — SDK·NeXTMach 어디에도 i386 판이 없는 경우라 Darwin 을 쓰고 기록(D021 메모 원칙). 매크로를 쓰는 객체는 채택 때 원본 바이트로 확인.
- 진단 10(`s5p118-diag-10`, BSD kern 12 소스): reg.h 뒤 다음 오류는 `bsd/i386/psl.h` 6, NeXTMach 이름(`vm/vm_param.h`, `machine/vm_types.h`, `machine/exception.h`, `next/cons.h`) 4, 필드 차이 1. kern_time 은 컴파일되나 원본에 `getthetime`·`inittodr` 가 더 있고 6 함수 크기가 달라(판 차이 큼) 미룬다.
### 144.1 codex 교차검토(QS63; 순서 기록: 작성판 두 파일은 이 검토 전에 만들었다 — 진단 실행 전) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 두 파일의 `KERNEL_PRIVATE` 본문은 Darwin 과 바이트 동일 | 생성 스크립트가 Darwin 파일의 해당 부분을 그대로 이어 붙였음(`D[D.index(...):]`) | ✅ |
| import 대상 `machdep/i386/thread.h`(07), `architecture/i386/frame.h`(07 SDK 사본) 존재 | `ls` 확인 | ✅ |
| 07 소스·SDK 사본에서 `bsd/machine/reg.h`·`psl.h` include 0 → 확정 객체 영향 없음 | 다음 전체 회귀로 다시 확인 | ✅ |

### 144.2 진단 11 계획 — NeXTMach 이름 shim(진단 전용)

NeXTMach BSD 소스는 Mach 2.5 시절 이름(`vm/vm_param.h`, `machine/{vm_types,exception,boolean,kern_return}.h`)을 쓴다. 채택 때는 파일별 include 수정으로 처리하되(138·139 와 같음), 근접도 측정을 위해 **스테이징 사본에만** 다음 shim 을 넣는다: `src/vm/vm_param.h` → `<mach/vm_param.h>`, `src/machine/X.h` → `<mach/machine/X.h>`(X = vm_types, exception, boolean, kern_return). 07 에는 넣지 않는다. 남은 NeXTMach 후보 전체 재진단 + L1.

## 145. S5-P119 세부 계획 — `bsd/kern_time.c` 복원 (D024, 코딩 전, 2026-10-02)

사실(원본 [0x10abb0, 0x10b460) 13 함수, Python·capstone; NeXTMach `mk-108.1/bsd/kern_time.c` 진단 빌드 `s5p118-diag-10`):
- 크기 같음 5: `gettimeofday` 60, `settimeofday` 72, `itimerfix` 64, `itimerdecr` 132, `timevaladd`/`timevalsub` 32. (`timevalfix` 44/43 은 끝 채움 차이일 가능성.)
- 원본에만: `_getthetime` 0x10ac84(48 B) — `_mtime`(0x1dee50, 매핑된 시간 구조 포인터)의 seconds·microseconds·check_seconds 를 일치할 때까지 읽는 루프(Mach4 `kern/mach_clock.c` host_get_time 의 루프와 같은 구조) 후 `tv` 에 저장. `_inittodr` 0x10ad3c(368 B) — 문자열 5 개(`WARNING: preposterous time in file system` 등)와 흐름이 Darwin `bsd/kern/kern_time.c:227–293` 의 inittodr 와 같고, `time` 대신 지역 timeval(`microtime(&tv)`), `setthetime(&tv)` 가 두 곳에 인라인.
- `setthetime` 72→80: `suser()` → `getthetime(&now)` → `boottime.tv_sec += tv->tv_sec - now.tv_sec; boottime.tv_usec = 0` → `host_set_time(realhost.host_priv_self, *tv)`(`[realhost+4]`, 07 `kern/host.h:61–64` 두 번째 필드; 인자는 time_value 값 전달).
- `adjtime` 252→136: tickdelta 계산이 없어지고 `copyin` → `host_adjust_time(realhost.host_priv_self, atv, &oadj)` → `olddelta` 가 있으면 oadj 를 timeval 로 옮겨 `copyout`(Mach4 `mach_clock.c:432` host_adjust_time 이 tickdelta 계산을 맡음).
- `getitimer`·`setitimer`·`realitexpire`: NeXTMach 논리 그대로이되 전역 `time` 을 쓰던 곳이 인라인된 getthetime 의 지역 timeval 로 바뀜(각각 mtime 루프 1·3·1 회).

방법(D024 작성 범위, 파일에 `plan 145 (authored)` 표시, 근거 주소는 MODIFICATIONS):
1. `07_kernel/src/bsd/kern/kern_time.c` = NeXTMach 바탕. `getthetime` 을 `setthetime` 앞(원본 순서: setthetime 0x10ac34 → getthetime 0x10ac84 이므로 getthetime 은 setthetime **뒤**에 정의하고 앞에 선언) — 순서는 원본 주소 순서를 따른다: settimeofday, setthetime, getthetime, adjtime, inittodr, getitimer….
2. `inittodr` 는 Darwin 구조(문자열·분기 동일)로 작성, `time` → 지역 timeval.
3. 불확실한 C 형태(getthetime 루프의 저장 방식, setthetime·inittodr 의 boottime 재적재 등)는 진단 전용 변형 컴파일로 바이트 일치하는 형태를 고른다(139 의 mfs_init 와 같은 방법).
4. 목표 OBJECT_MATCH 13/13. 통과하면 adopt 스크립트로 기록(헤더 채택 포함).

### 145.1 codex 교차검토(QS64) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `mapped_time_value_t` 는 SDK `mach/time_value.h:107–` 에 seconds·microseconds·check_seconds 순서로 정의; `mtime` 선언은 헤더에 없음 → `extern mapped_time_value_t *mtime;` 필요 | 116–120 행 확인. 같은 헤더 주석(108–113 행)이 원본과 같은 읽기 루프(`secs`·`usecs` 지역, `check_seconds` 비교)를 적어 둠. 07 소스에 `mtime` 선언 0(grep) | ✅ 작성 선언 1 줄, 루프는 헤더 주석 형태 |
| `host_set_time` 둘째 인자는 time_value_t 값 전달; `struct timeval`(long)과 `time_value_t`(integer_t)는 다른 타입 → 변환 필요 | Mach4 `mach_clock.c:394–396` | ✅ 형태는 변형 컴파일로 결정(지역 time_value_t, 캐스트) |
| 145 의 "앞(… 뒤)" 표현 모순 — 주소 순서상 getthetime 은 setthetime 뒤, 호출 전 선언 | 145 본문 | ✅ 정정: 뒤에 정의, 앞에 선언 |
| `realhost.host_priv_self` 는 port 인데 Mach4 host_set_time 은 host_t — 원래 callee 타입 미확인 | 07 `kern/host.h:61–64`; 원본은 `[realhost+4]` 값을 넘김 | ⚖️ 프로토타입 없이 호출(K&R)하면 코드 같음. 바이트로 판정 |

### 145.2 결과(2026-10-02)

- 반복: it1(setthetime·adjtime·inittodr 크기 일치, getthetime 36/48) → 변형 `s5p119-v1`·`v2`(getthetime: `extern volatile mapped_time_value_t *mtime` + `time_value_t` 지역만 바이트 일치) → it2(13 MATCH, `__data` 차이: NeXTMach 의 `bigadj` 정의 — 원본에서 tickadj·tickdelta·timedelta·bigadj 는 0x1dee40–0x1dee4c 로 이 객체 데이터와 떨어져 있음) → it3 OBJECT_MATCH 14/14.
- 객체 [0x10abb0, 0x10b463)(objects.tsv 의 끝 0x10b460 은 3 B 짧음). A. objects_confirmed 98 → 99 줄, functions 898 → 912, PROVENANCE +2(파일, SDK `bsd/machine/reg.h`), MODIFICATIONS +1, 증거 `x86-kern_time.md`·`.diff`.
- 기록용 스크래치 스크립트 `record_object.py`: 07 파일이 이미 있는 객체를 OBJECT_MATCH·Δ 일관·common 간격·07 밖 헤더 채택·재스테이징 동일을 확인한 뒤 기록.

## 146. S5-P120 — `bsd/kern_subr.c`(2026-10-02)

사실: 원본 [0x10a384, …) 3 함수 uiomove 196·ureadc 144·uwritec 176, NeXTMach 진단 빌드 uwritec 155. 원본 uwritec 은 첫 panic 문자열 `"uwritec"`(0x1daa55, NeXTMach)와 `return (c & 0377)`(0x10a56f `movzx eax, dl`, NeXTMach)을 그대로 두고, switch 에 Darwin `kern_subr.c` 의 `default: c = 0; panic("uwritec: bogus uio_segflg");`(0x10a554–0x10a55b, 문자열 0x1daa5d)가 더해진 판. 수정 1 곳(Darwin 줄 출처 표시). 채택 스크립트로 빌드·L1·기록.

### 146.1 결과 / 147. `rpc/xdr.c` P 채택 계획 (2026-10-02)

- 146: kern_subr OBJECT_MATCH 3/3(`s5p120-adopt-1`), A. PROVENANCE 행에 Darwin 줄 출처 보완, 채택 스크립트에 `darwin_lines` 항목 추가.
- 147 사실(진단 11 L1): NeXTMach `rpc/xdr.c` 그대로 15 함수 크기·바이트 일치, `__TEXT,__text` 차이 0·참조 60 모두 일치, `__data` 412 B L1d 검증. 남은 것은 `__DATA,__bss` 16 B(정적 버퍼, 심볼 없음) 위치가 "inferred" 뿐이라 `_xdr_opaque`·`_xdr_bytes`·`_xdr_string` 이 MATCH_UNVERIFIED.
- 방법: 07 에 verbatim → 07 만으로 빌드(iter) → `zerofill_check.py`(known = `zerofill-known-s5p88`, 그 뒤 채택 객체에 `__bss` 없음 확인 — Python) → reference-inferred 면 등급 P(46 절·D019 규칙), 의존 3 함수 medium·나머지 high, known 목록 갱신.

### 147.1 결과(2026-10-02)

- `s5p121-it1`(07 의 verbatim xdr.c): L1 12 MATCH + 3 MATCH_UNVERIFIED(`__bss` 만). `zerofill_check` → reference-inferred [0x1e5a20, 0x1e5a30)(3 참조, Δ 1 개, 음성 검사 검출). 등급 P(objects_partial +1), functions 15 행(12 high, 3 medium), PROVENANCE +1, known 목록 `zerofill-known-s5p121-20261002.json`(18 개). 07 밖 헤더 없음.

## 148. S5-P122 — `bsd/subr_xxx.c` (2026-10-02)

사실: 원본 [0x10cca4, …) 9 함수(nodev, nulldev, errsys, nullsys, **nosys** 48 B, imin, imax, min, max), NeXTMach 진단 빌드는 nosys 없이 8 함수(크기 같음). 원본 `_nosys` 0x10ccd4: `u_signal[SIGSYS]` 가 1(SIG_IGN) 또는 3(SIG_HOLD) 이면 `u_error = 0x16`(EINVAL), 그리고 `_exception_from_kernel(5, 0x10000, 0)` — NeXTMach `next/trap.c:1072–1078` 의 nosys 와 같은 논리, 단 `thread_doexception(current_thread(), …)` 대신 `exception_from_kernel`(EXC_SOFTWARE=5, EXC_UNIX_BAD_SYSCALL=0x10000: NeXTMach `sys/ux_exception.h:45`).
방법: NeXTMach `bsd/subr_xxx.c` 에 nullsys 뒤로 nosys 를 옮겨 넣고(출처·변경 표시) mach/exception.h·sys/ux_exception.h import. 채택 스크립트.

### 148.1 첫 시도 실패와 `sys/ux_exception.h` 작성판 (2026-10-02)

- `s5p122-adopt-1` 실패: NeXTMach `sys/ux_exception.h`(KERNEL_STRIPPED 규칙으로 선택)가 Mach 2.5 `sys/port.h` → `mach_ipc_xxxhack.h` 를 요구. 스크립트가 07 사본을 지우고 멈춤(기록 없음).
- codex(QS65) 판정: 원본에 `_ux_exception_port` 있음, `_ux_handler_init_lock` 없음(✅, 단 없음은 추론), 07 `mach/port.h:225` 에 `port_t` 있음(✅), 07 에서 이 헤더를 include 하는 곳 0(✅ 기존 객체 영향 없음), `bsd_pick` 은 `nextdev_private` 를 KERNEL_STRIPPED 보다 먼저 봄(✅ `stage_headers.py` 160–173).
- 작성판 `07_kernel/nextdev_private/bsd/sys/ux_exception.h` = SDK 본문 + `#ifdef KERNEL` `#import <mach/port.h>` `extern port_t ux_exception_port;`(D023 방식). PROVENANCE +1. subr_xxx 재시도.

## 149. S5-P123 세부 계획 — 명령행 `-DMACH` (코딩 전, 2026-10-02)

사실:
- raw_usrreq `raw_input` 끝(원본 0x121640–0x121645): `push _soft_net_wakeup; call _wakeup` = SDK `bsd/net/netisr.h` 의 `#ifdef MACH` 분기 `setsoftnet() (wakeup((caddr_t)&soft_net_wakeup))`. 우리 빌드는 `MACH` 미정의라 `setsoftnet()` 가 암묵 함수 호출로 컴파일됨(인자 0 개). 원본 심볼 `_soft_net_wakeup` 0x1ea9e4, `_netisr` 0x1ea9e0.
- NeXTMach `rpc/svc_kudp.c:117–125, 153–161, 381–385` 는 `#if MACH` 분기에서 이미 `kalloc`/`kfree` 를 쓴다. 143 에서 내가 고친 `kmem_alloc` 줄은 `#else`(비-MACH) 분기였다 — `-DMACH` 이면 NeXTMach 원문 그대로가 원본과 같은 호출이 된다. **143 의 svc_kudp 수정은 잘못된 분기에 한 것**이다.
- `MACH` 는 생성 헤더가 없다(`<mach.h>` import 0; Darwin·NeXTMach `conf/MASTER` 의 `options MACH`) → config 가 명령행 `-DMACH` 로 넘기는 옵션(INET 과 같은 경우, 141).
- 07 에서 `MACH` 조건을 쓰는 파일(grep): svc_kudp.c(3 곳), SDK `sys/vnode.h:57–60`(`#if MACH` 이면 `v_text` 필드 없음 — 구조체 끝 필드), SDK `sys/vfs.h`(2 곳).

방법:
1. 최종 플래그에 `-DMACH`(템플릿·스크립트·문서).
2. svc_kudp.c 를 NeXTMach 원문 그대로로 되돌림(143 수정 철회, MODIFICATIONS 에 철회 기록).
3. 확정·부분 전 객체 회귀(현재 07 전체): 기존 빌드와 비-디버그 내용 비교, 다르면 L1. svc_kudp 은 verbatim 으로 OBJECT_MATCH 여야 함.
4. raw_usrreq 등 net 객체 재진단은 그다음.

### 149.1 codex 교차검토(QS66) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 07 에 `net/netisr.h` 없음 → SDK 판 사용, `MACH` 분기가 `setsoftnet() = wakeup(&soft_net_wakeup)` | 위 SDK 본문 출력(grep -v 주석) 확인 | ✅ |
| svc_kudp 의 `#if MACH` 3 곳은 kalloc/kfree, `#else` 에 내 143 수정 | 115–125·150–162·379–386 행 출력 확인 | ✅ 143 수정 철회 |
| `MACH` 는 `struct vnode` 끝 필드 `v_text` 와 `vfsops` 끝 `vfs_swapvp` 만 없앰 → 앞 필드 위치 불변, sizeof 는 바뀜 | vnode.h 55–61, vfs.h 98–114 출력 확인 | ✅ 전체 회귀로 확인 |
| SDK `nfs/rnode.h`·`sys/bootconf.h` 도 `MACH` 분기 — 현재 스테이징에 들어오는지는 미확인 | 07 에 둘 다 없음(지금 채택 객체 closure 밖) | ⚖️ 나중 객체에서 다룸 |

### 149.2 결과(2026-10-02)

- `s5p123-regress-1`(111 명령, `-DMACH`): 확정·부분 111 객체 모두 이전 최종 빌드와 비-디버그 내용 같음(`s5p123-regress-compare-20261002.json`). svc_kudp 는 NeXTMach 원문 그대로로도 같은 객체 → 143 수정 철회(PROVENANCE·functions·objects_confirmed·MODIFICATIONS 갱신).
- 템플릿 `s5p107-build.cmd`(6 줄), 스크래치 스크립트(iter·adopt_batch·variants)에 `-DMACH`. 문서(README·GCC27) 갱신은 아래.

### 149.3 진단 12 와 raw_usrreq 채택 (2026-10-02)

- 진단 12(`s5p123-diag-12`, `-DMACH`, 남은 NeXTMach 후보 92): 38 컴파일. raw_usrreq 가 NeXTMach 원문 그대로 OBJECT_MATCH(5 함수) — 진단 11 의 `raw_input` 차이는 `MACH` 미정의(`setsoftnet`) 때문이었다. 채택 스크립트로 기록.

## 150. S5-P124 세부 계획 — 명령행 `-DMULTICAST` 와 `net/raw_cb.c` (코딩 전, 2026-10-02)

사실:
- 원본 `_raw_detach`(raw_cb 객체, 0x121300– 범위)에는 NeXTMach `net/raw_cb.c` 에 없는 블록이 있다: `rcb_options` 해제 뒤 `if (so == ip_mrouter) ip_mrouter_done();`(0x121408–0x121410, `_ip_mrouter` 0x1dbf54) 와 `if (rp->rcb_proto.sp_family == AF_INET) ip_freemoptions(rp->rcb_moptions);`(`cmp word [ebx+0x2c],2`, `[ebx+0x50]`, 0x121420). `_raw_disconnect` 는 raw_detach 를 인라인해 같은 블록을 한 번 더 가짐(+32 B 씩).
- `rcb_moptions` 는 SDK `bsd/net/raw_cb.h:47–49` 의 `#ifdef MULTICAST` 필드이고, 오프셋 계산(next 0, prev 4, socket 8, faddr 0xc, laddr 0x1c, proto 0x2c, pcb 0x30, options 0x34, route 0x38(20 B), flags 0x4c, moptions 0x50)이 원본 0x50 과 맞는다. SDK BSD 헤더는 "MULTICAST 1.0" 패치판(`raw_cb.h:27`, `if.h:8`, `ip_var.h:17`).
- 원본 심볼에 `_ip_mrouter`, `_ip_mrouter_done`, `_ip_freemoptions` 존재. Darwin `conf/MASTER:148` `options MULTICAST`(헤더 태그 없음 → 명령행 `-D`). Darwin raw_cb.c(4.4)에는 이 블록이 없다 → 작성(D024).
- `MULTICAST` 조건을 쓰는 07 파일: SDK `net/raw_cb.h`(필드), `netinet/ip_var.h`(86–98, 118–120), `sys/ioctl.h`(주석뿐). `rcb_moptions` 뒤 필드 `rcb_cc`·`rcb_mbcnt` 는 NeXTMach 코드에서 쓰는 곳 0(grep) — raw_usrreq(149.3 채택) 영향 없음 예상.

방법:
1. 최종 플래그에 `-DMULTICAST`. 확정·부분 전 객체 회귀(112).
2. `07_kernel/src/bsd/net/raw_cb.c` = NeXTMach + raw_detach 의 위 블록(`#ifdef MULTICAST`, 작성 표시) + `extern struct socket *ip_mrouter;` 선언(SDK 헤더에 없음).
3. 빌드·L1·기록.

### 150.1 codex 교차검토(QS67) 판정

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `MULTICAST` 로 바뀌는 활성 분기는 `net/raw_cb.h`(rcb_moptions, 뒤 필드 이동·크기 변화)와 `netinet/ip_var.h`(struct ip_moptions·IP_MULTICASTOPTS 정의 추가, 기존 구조체 불변); `in_pcb.h` 의 `inp_moptions` 는 무조건, `if.h` 는 분기 없음 | 내 grep 결과와 같음(07 의 MULTICAST 조건 3 파일) | ✅ |
| raw_usrreq 가 쓰는 전역 `struct rawcb rawcb`(raw_cb.h:84–85)의 common 크기가 바뀜 → 전체 회귀 필요 | Python: 원본 `_rawcb` 0x1ea9f0, 다음 심볼까지 92 B; MULTICAST 이면 sizeof(rawcb) = 0x5c(92 B) | ✅ 회귀와 36.1 (c) 간격 검사 |
| rcb_moptions 0x50 은 SDK 필드·크기와 일치 | 위 Python 계산과 같음 | ✅ |
| SDK `netinet` 헤더에 ip_mrouter·ip_mrouter_done·ip_freemoptions 선언 없음 | 내 grep 0 건 | ✅ 선언 작성 |

### 150.2 결과(2026-10-02)

- raw_cb: it1 4 MATCH + `raw_attach` 1 B(수신 버퍼 예약 0x810 대 원본 0x824 = 2048 + 36 = `sizeof(struct raw_header)`, Python), it2 OBJECT_MATCH 5/5. A. 기록 `x86-raw_cb.md`·`.diff`.
- 회귀 `s5p124-regress-1`(112, `-DMULTICAST`): 111 같음, raw_usrreq 는 common `_rawcb` 크기만 88 → 92(원본 간격 92 B 와 일치). 템플릿·스크립트·README·GCC27 문서에 `-DMULTICAST`.

## 151. S5-P125 세부 계획 — `netinet/tcp_timer.c` (D024, 코딩 전, 2026-10-02)

사실(진단 13, fndiff 필터 없이): 원본 [0x12a8cc, …) 4 함수 중 tcp_fasttimo·tcp_slowtimo·tcp_canceltimers 크기 같음, `tcp_timers` 528/515. 차이:
1. 재전송 간격: 원본 `sar ax,3; cwde; add t_rttvar; imul tcp_backoff` = SDK `tcp_var.h:149` `TCP_REXMTVAL(tp)`(`(t_srtt >> TCP_RTT_SHIFT) + t_rttvar`) × backoff. NeXTMach 은 `((t_srtt >> 2) + t_rttvar) >> 1`.
2. 하한: 원본은 `t_rxtcur` 를 `[tp+0x64]`(`t_rttmin`, SDK `tcp_var.h:108`)와 비교, NeXTMach 은 `TCPTV_MIN`(2).
3. 원본은 cwnd 재설정 뒤 `mov word [ebx+0x16], 0`(`t_dupacks`, SDK `tcp_var.h:56`).
4. keepalive `tcp_respond` 에 원본은 인자 하나(`push 0`)가 더 있음 = 4.4/Reno 의 `(struct mbuf *)NULL` 인자.
이 네 형태는 Darwin `bsd/netinet/tcp_timer.c` tcp_timers 에 같은 모양으로 있다(4.4BSD, 구조 참고). 그 밖(losing 블록의 shift 등)은 빌드 결과로 확인.
방법: NeXTMach 바탕 + 위 4 곳 수정(작성 표시, 형태는 Darwin 줄을 참고) → iter 빌드 → L1 → 기록.

151 보충(직접 역어셈블 `objdump -D -b binary -mi386 --start-address=0x2a9fc --stop-address=0x2ac0c`, 파일 오프셋 = vaddr−0x100000):
- SDK 경로 정정: "SDK `tcp_var.h`" 는 실기 `/NextDeveloper/Headers/bsd/netinet/tcp_var.h`(스테이징 bsd-set nextos 가 가져오는 것, sha256 7d7dffbf…) — :56 `t_dupacks`, :108 `t_rttmin`, :132 `TCP_RTT_SHIFT 3`, :149 `TCP_REXMTVAL` 직접 열어 확인.
- losing 블록: 원본 `sar $0x2,%ax; add %ax,0x62(%ebx)` = NeXTMach :191 `t_srtt >> 2` 그대로(Darwin :383 의 `>> TCP_RTT_SHIFT` 아님). 바꾸지 않는다.
- TCPT_PERSIST: 원본은 `tcp_setpersist` → `t_force=1` → `tcp_output` → `t_force=0` 뿐 — Darwin :441 의 idle 초과 drop 검사 없음. NeXTMach 그대로.
- keepalive: push 순서 `0, snd_una-1, rcv_nxt(감소 없음), 0, t_template, tp` → `tcp_respond(tp, tp->t_template, (struct mbuf *)0, tp->rcv_nxt, tp->snd_una - 1, 0)`, 즉 NeXTMach `#else`(TCP_COMPAT_42 아님) 분기의 셋째 자리에 mbuf 인자. 두 분기 모두 같은 자리에 넣는다.

151 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| SDK tcp_var.h :56/:108/:149 | 실기 SDK 사본 grep (위 보충) | ✅ |
| t_dupacks 0x16, t_rttmin 0x64 | 역어셈블 `movw $0x0,0x16(%ebx)`, `mov 0x64(%ebx),%cx` | ✅ |
| losing 블록은 >>2 유지 | 역어셈블 `sar $0x2,%ax` | ✅ (이미 보충에 기재) |
| PERSIST 에 drop 검사 없음 | 역어셈블 case 1 → setpersist/t_force/output | ✅ |
| tcp_respond 6 인자, 셋째가 0 | 역어셈블 push 순서 | ✅ |
| 계획 경로 07_kernel/nextdev/bsd/netinet/tcp_var.h 없음 | `find` 0건 — 계획 본문이 아니라 codex 질의문의 내 오기 | ✅ (보충에서 정정) |

151 결과: run `s5p125-it1` 첫 빌드 OBJECT_MATCH(4/4 MATCH, 빌드 831 B / 원본 구간 832 B, 끝 0x12ac0b 의 `00` 은 객체 사이 패딩). 등급 A 로 기록(`06_reconstruction/evidence/x86-tcp_timer.md`, `.diff`). SDK `netinet/{tcp,tcp_fsm,tcp_seq,tcp_timer,tcp_var,tcpip}.h` 를 `07_kernel/nextdev` 로 채택(PROVENANCE 6 행). 절차 메모: iter.py 실행 전에 scratchpad 도구를 `10_tools/reconstruction/` 에 잘못 복사했다가(새 파일 2 개, 이전 존재 없음 확인) 지우고 scratchpad 에서 실행했다.

## 152. S5-P126 세부 계획 — `netinet/tcp_debug.c` (D024, 코딩 전, 2026-10-02)

진단 13 의 tcp_debug "OBJECT_MATCH" 는 공허한 일치다: NeXTMach 파일 전체가 `#if DEBUG`(:22–:138)라 빌드 텍스트 0 B 인데 원본 objects.tsv seq 84 는 [0x1284c0, 0x128579) `_tcp_trace` 를 갖는다.
사실(역어셈블 `--start-address=0x284c0 --stop-address=0x2857c`, 심볼 표 전수):
1. 원본 `tcp_trace` 는 기록부만: `td = &tcp_debug[tcp_debx++]`(항목 164 B = `lea` 41×4), `cmpl $0x64` → TCP_NDEBUG 100, `iptime()`(0x125d18), act/ostate/tcb, `*tp`(0x1b×4 = 108 B) 또는 `bzero(…,0x6c)`, `*ti`(0xa×4 = 40 B) 또는 `bzero(…,0x28)`, `td_req` 저장 후 반환. `tcpconsdebug` 검사와 printf 부분 없음.
2. 원본 심볼에 `_tanames`·`_tcpstates`·`_prurequests`·`_tcptimers`·`_tcpconsdebug` 없음(비디버그 3751 개 전수 0 건) → TANAMES/TCPSTATES/TCPTIMERS/PRUREQUESTS 정의 없이, tcpconsdebug 없이 빌드.
3. `_tcp_debug` 0x1ead50, `_tcp_debx` 0x1eed60(간격 0x4010 = 100 × 164), `_tcp_iss` 0x1eed64 — SDK `tcp_debug.h`:63–65(`TCP_NDEBUG 100`, 정의) 와 맞음(빌드에서는 SDK 헤더의 tentative 정의 → common).
이 형태는 Darwin `bsd/netinet/tcp_debug.c`(4.4, `#ifdef TCPDEBUG` 가 이름 표·tcpconsdebug·출력부를 감쌈) 와 같은 구조다(구조 참고).
방법: NeXTMach 바탕. 바깥 `#if DEBUG`/`#endif DEBUG` 를 없애고, `#define` 이름 표 넷과 `tcpconsdebug`, `if (tcpconsdebug == 0) return;` 이하 출력부를 `#ifdef TCPDEBUG` … `#endif` 로 감싼다(작성 표시). 함수 반환형 등 나머지는 NeXTMach 그대로. iter → L1 → 기록.

## 153. S5-P127 세부 계획 초안 — `net/netif.c` (D024, 코딩 전, 2026-10-02)

사실(원본 심볼 표·역어셈블):
1. objects.tsv seq 69 `netif.c` [0x120b98,0x120e14), seq 70 `if.c` [0x120e30,0x120ff3), seq 71 `netif.c` [0x120ff4,0x12125c) 는 한 객체로 본다: `if_detach`(0x120e30)가 0x12125c·0x121268 의 정적 함수 두 개(원본 심볼 없음)를 함수 포인터로 넣고, 이 둘이 `if_output_mbuf` 뒤 `netisr_thread_continue`(0x121274) 앞에 있다. 즉 netif 객체 = [0x120b98, 0x121274). seq 70 의 `if.c` 라벨은 이 객체의 일부(`if_detach`, `if_attach`)로 정정 대상(objects.tsv 는 분석 산출물이므로 정정은 기록으로 남김).
2. NeXTMach `net/netif.c` 순서에 원본은 넷이 더 있다: `if_class`(0x120d40, `if_mtu` 뒤; `mov 0x14(%eax)`), `iflist_first`(0x120e14; `mov ifnet`), `iflist_next`(0x120e20; `mov 0x5c(%eax)` = if_next), `if_detach`(0x120e30, `if_attach` 앞). 선언은 SDK `bsd/net/netif.h`:114,116,117,126.
3. `if_detach`: if_name·if_type(오프셋 0,4) ← 문자열 `"null"`(0x1d1271), 오프셋 8/0xa/0xc short ← 0, 0x28 ← 0, 0x30/0x34/0x38/0x3c ← 스텁 A(0x12125c: `return 5`), 0x40 ← 스텁 B(0x121268: `return 0`), 0x58 ← 0. 필드 이름은 SDK `net/if.h` 배치로 확정한다(코딩 전에 오프셋 계산).
4. `pingvirtuals` 는 원본 `if_attach` 안에 인라인(`call *%eax` 루프) — NeXTMach 그대로.
방법(초안): NeXTMach 바탕 + 네 함수와 스텁 둘 작성(작성 표시). 스텁 이름·문자열 정의 위치는 빌드 바이트로 확정. 하나씩 iter.
153 보충(오프셋은 SDK `net/if.h`:48–96 `struct ifnet` 을 python 으로 배치, 크기 0x60): `if_detach` 저장 = if_name(0)·if_type(4) ← `"null"`, if_unit(8)·if_mtu(0xa)·if_flags(0xc) ← 0, if_snd.ifq_maxlen(0x28) ← 0, if_init(0x30)·if_output(0x34)·if_control(0x38)·if_input(0x3c) ← 스텁 A(`return 5`), if_getbuf(0x40) ← 스텁 B(`return 0`), if_private(0x58) ← 0. 순서가 NeXTMach `if_attach`(:324–:335) 대입 순서와 같다. 두 스텁은 원본 심볼이 없는 static 이라 이름은 작성자가 정하고 바이트에 영향 없음(표시). `if_class` 0x14, `iflist_next` 0x5c(if_next), `iflist_first` = `ifnet`(0x1e89e0).

152 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 주소·크기·164/108/40·100·스텁 없음 | 역어셈블(계획 152 사실 1), symbols.tsv 전수 | ✅ |
| td_req 는 16 비트 저장 | 역어셈블 `mov %cx,0x34(%ebx)` | ✅ |
| _tcp_debug/_tcp_debx 는 `__common`(섹션 6) | macho.json :163–166 index 6 `__common` | ✅ |
| "0 B" 는 DEBUG 거짓일 때만 | NeXTMach tcp_debug.c :22 `#if DEBUG` | ✅(최종 플래그에 DEBUG 없음) |
| SDK tcp_debug.h 는 include·KERNEL 가드 없음 | grep 0 건 | ✅ — NeXTMach 의 include 순서를 유지 |
| NeXTMach tcp_debug.h 는 10 개·DEBUG 가드 | :31 `#if DEBUG`, :37 `TCP_NDEBUG 10` | ✅ — 스테이징이 SDK 헤더를 고르는지 manifest 로 확인한다 |
| GCC27 문서 :20 의 -fno-common 위험 | 해당 줄 확인 | ✅(최종 빌드는 -fno-common 없음) |
| Darwin `void` 는 :102 | :101 이 `void`, :102 는 `tcp_trace(` | ⚖️ 줄 오차. 반환형은 바이트로 정할 수 없으므로 NeXTMach 암묵 int 유지 |

152 결과: run `s5p126-it1` 첫 빌드 OBJECT_MATCH(1/1, 185 B; 0x128579–0x12857b 는 `00` 객체 사이 패딩). 스테이징 manifest 상 `netinet/tcp_debug.h` 는 실기 SDK 사본. 등급 A 로 기록(`06_reconstruction/evidence/x86-tcp_debug.md`, `.diff`), SDK `tcp_debug.h` 1 개를 `07_kernel/nextdev` 로 채택.

153 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 한 객체 [0x120b98,0x121274) 는 강한 추론이나 증명은 아님; if.c(seq 65 0x11edac–0x11f43a)에 if_attach/if_detach 없음 | 심볼 표 0x11f000–0x120ba0 목록, NeXTMach if.c :90–:128 `#if NeXT … #else` | ✅ (객체 경계는 추론으로 기록) |
| 네 함수·스텁 배치 | 역어셈블·심볼 주소 | ✅ |
| 스텁 정의 순서: return-5 다음 return-0, if_output_mbuf 뒤 | 0x12125c(`mov $5`), 0x121268(`xor eax`) | ✅ (선언 위치는 빌드로 시험) |
| `"null"` 은 `__cstring` 이 아니라 `__TEXT,__const`(0x1d10bc–) | macho.json `__const` 0x1d10bc 크기 0x58f4, `__cstring` 0x1d69b0; 0x1d1209–0x1d1284 바이트 덤프 | ✅ — 계획 153 사실 3 의 "문자열" 은 리터럴이 아니라 이름 없는(static) `const char` 배열로 정정 |
| 원본 IFCONTROL 상수 9 개(RCVPROMISCUOUS·RCVPROMISCOFF·ADDMULTICAST·RMVMULTICAST 추가) | symbols.tsv :115–:123, 바이트 `promiscuous-on`·`promiscuous-off`·`add-multicast`·`rmv-multicast` | ✅; SDK netif.h :58–:64 는 ADD/RMV 까지 7 개만 선언 |
| if_ioctl 에 SIOCADDMULTI/SIOCDELMULTI(0x80206931/2) → ADD/RMV, data 그대로 | 역어셈블 0x120be8–0x120cb8 | ✅; 본문 배치 순서 AUTOADDR·SIFADDR·GIFADDR·SIFFLAGS·ADD·DEL·default = 원문 case 순서 뒤에 두 case 추가 |
| if_ierrors_set 은 0x48(if_ierrors) 저장, NeXTMach :279 는 if_oerrors | 역어셈블 0x120df4, NeXTMach :279 | ✅ |
| if_attach 확장(분리 항목 재사용, metric·addrlist·통계 0, 새 항목만 삽입, REAL 일 때 hostid) | 역어셈블 0x120e8c–0x120ff3 | ✅; hostid 경로는 인라인된 `if_control()`(NULL → 건너뜀) 과 `ea[2]^=ea[0]; ea[3]^=ea[1]; hostid = ntohl(*(long *)&ea[2])` 꼴. 참고 원문에 같은 코드 없음(grep `hostid` 전수) → 작성 |
| if_output_mbuf 확장 루프는 인라인 가능, 변경 증거 아님 | 빌드로 확인 | ⏭️ 빌드 결과로 판정 |

153 방법(확정): NeXTMach 바탕. 작성(표시): IFCONTROL 상수 4 개 추가, `static const char` "null" 배열, if_ioctl 두 case, if_ierrors_set 필드 정정, if_class, iflist_first/next, if_detach, if_attach 재작성(위 구조), 스텁 둘(이름 작성). `hostid` 는 `extern long hostid;`. 결과에 따라 순서·형태 조정, OBJECT_MATCH 까지 반복. objects.tsv seq 69–71 정정은 기록(objects_confirmed 범위)으로 남긴다.

153 결과: run `s5p127-it1` 첫 빌드에서 `__text` 1753 B·`__TEXT,__const` 109 B 바이트 차이 0, 원본 31 함수 MATCH(2 개는 `__bss` 참조 때문에 MATCH_UNVERIFIED). `__DATA,__bss` 4 B(`if_dispatchers`)는 `zerofill_check.py` 로 0x1e58d8 참조 추정(`09_validation/reconstruction/s5p127-zerofill-check-netif-20261002.json`) → 등급 **P**(`objects_partial.tsv`). known 배치는 `zerofill-known-s5p127-20261002.json`(19 항목)으로 갱신. 기록 도구는 scratchpad `record_partial.py`(record_object.py 에서 판정·행 형식만 바꾼 사본).

## 154. S5-P128 세부 계획 — `net/netisr.c` (D024, 코딩 전, 2026-10-02)

사실(역어셈블 0x121274–0x1212fe, 심볼 표): 원본 객체 [0x121274, 0x1212fe) 는 `netisr_thread_continue`(0x121274) 다음 `netisr_thread`(0x1212d0).
1. `netisr_thread_continue`: `splnet()`; `while (netisr != 0)` 안에서 bit 4(NETISR_IP=2) → clear, `ipintr()`(0x126058); bit 1(NETISR_RAW=0) → clear, `rawintr()`(0x121654); 루프 뒤 `assert_wait(&soft_net_wakeup(0x1ea9e4), 0)`, `thread_block_with_continuation(netisr_thread_continue)`. IMP·NS·ARP 처리 없음.
2. `netisr_thread`: `current_thread()`(= `active_threads[0]` 0x1e8b54 읽기), `stack_privilege(self)`(0x166a5c), `thread_bind(self, master_processor(0x1ea9dc))`(0x163450), `thread_block_with_continuation(netisr_thread_continue)`. 우선순위 설정 없음.
3. NeXTMach `net/netisr.c`(:36–:91)는 continuation 이전 형태(우선순위 31, `master_cpu`, `thread_block` 루프). Darwin `bsd/net/netisr.c` 는 위 1·2 와 같은 continuation 구조(구조 참고; ARP·NETAT 등은 원본에 없음).
4. `netisr`·`soft_net_wakeup` 는 SDK `net/netisr.h`:65·:31 의 잠정 정의(원본 `__common`).
방법: NeXTMach 바탕. `netisr_thread` 본문을 두 함수(continue 먼저)로 다시 작성(작성 표시, Darwin 구조), NIMP/INET/NS 조건부와 RAW 처리 블록은 NeXTMach 형태 유지. `stack_privilege`·`thread_bind` 는 함수 안 `extern` 선언(07 헤더에 선언 없음: `grep` 0 건). iter → L1 → 기록.

154 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 주소·호출 대상·비트·우선순위 설정 없음 | 역어셈블·심볼 해석(계획 154 사실) | ✅ |
| `netisr` 는 volatile 아님으로 먼저 시도(비트마다 한 번 읽기) | 역어셈블 0x121285–0x121290 `mov netisr; test; and; mov` | ✅ — SDK 헤더 :65 `int netisr` 그대로 |
| `assert_wait` 는 `event_t`(void *) 인자 | 07 sched_prim.h :76 typedef, NeXTMach :61 `(int)` 캐스트 | ✅ — `(event_t)&soft_net_wakeup` 로 쓴다(작성) |
| master_processor 는 전역 포인터 | 07 processor.h :192 | ✅ |
| current_thread() = active_threads[0] | 07 thread.h :345, cpu_number.h :65, generated/cpus.h NCPUS 1 | ✅ |
| stack_privilege/thread_bind 형 | 07 thread.c :337, sched_prim.c :546 | ✅ |
| NIMP 0 | 07 generated/imp.h | ✅ |
| Darwin :58 volatile·추가 분기는 복사하지 말 것 | Darwin :58 `volatile int netisr;` | ✅ |

154 결과: it1(함수 안 `stack_privilege`/`thread_bind` 원형 선언)은 `netisr_thread` 45/46 B(`master_processor` 를 `%eax` 로 읽음, 원본 `%edx`). it2(그 선언 제거 → 암묵 int 선언) OBJECT_MATCH 2/2, 138 B. 등급 A 로 기록(`06_reconstruction/evidence/x86-netisr.md`, `.diff`). 원형 선언이 없었다는 것은 바이트로 확인된 사실(레지스터 선택)이며, 이후 같은 꼴의 호출에서 참고한다.

## 155. S5-P129 세부 계획 — 명령행 `-DPOSIX_KERN` 과 `kern/sys_socket.c` (코딩 전, 2026-10-02)

사실:
1. 원본 `_soo_rw`(0x10d850, 68 B; NeXTMach 빌드 44 B)는 호출 전에 `active_u[0].utask->uu_procp`(0x1e8758 → `+0`)의 `+0x16` 바이트 bit 2 와 `fp->f_flag & 0x2000` 을 검사하고, 둘 다 참이면 `uio->uio_fmode`(+0x10, 16 비트)에 `f_flag` 를 저장한다.
   - SDK `sys/proc.h` `struct proc`: 포인터 4 개(0x10) 뒤 char 6 개(p_usrpri…p_nice, 0x10–0x15), 0x16 의 비트필드 `p_debugger:1`, `p_posix:1` → bit 2 = `p_posix`.
   - 0x2000 = 020000 = SDK `sys/file.h`:85 `FPOSIX_PIPE` — `#if POSIX_KERN`(:74–:86) 안에서만 정의.
   - SDK `sys/uio.h` `uio_fmode`(short) 오프셋 0x10(iov 0, iovcnt 4, offset 8, segflg 0xc, fmode 0x10).
2. 원본 심볼에 SDK `proc.h` 의 `#if POSIX_KERN` 블록(:226–:281) 기능이 있다: `_pgfind` 0x1074d8, `_enterpgrp` 0x107504, `_leavepgrp` 0x10765c, `_setsid` 0x108474, `_setpgid` 0x1084d0, `_delete_posix_proc` 0x1079b8.
3. `POSIX_KERN` 을 쓰는 07 헤더: SDK `sys/{file,proc,tty,fcntl}.h`(grep). `tty.h`:179–182 는 `struct nty` 에 `t_session`·`t_posix_pgrp` 필드를 넣어 배치가 바뀐다. `proc.h` 는 별도 구조체·선언·플래그(SCTTY, SEXEC)만 추가하고 `struct proc` 배치는 바꾸지 않는다(코딩 전 확인). 참고 원문(NeXTMach mk-108.1, Darwin conf/MASTER)에는 `POSIX_KERN` 이 없다(grep 0 건) → 명령행 `-DPOSIX_KERN`(헤더 태그 없음, 값 1).
방법:
1. 최종 플래그에 `-DPOSIX_KERN`. 확정·부분 전 객체 회귀(`s5p124-regress.cmd` 112 + tcp_timer·tcp_debug·netif·netisr = 116). 비교는 직전 최종 빌드(`s5p124-regress-1` 과 s5p125–128 it 결과)와 비-디버그 내용(`nd_cmp`).
2. 다르면 원인을 분석해 사용자 결정 필요 여부 판단(객체 간 충돌이면 결정 사항).
3. 같으면 `bsd/kern/sys_socket.c`(NeXTMach `bsd/sys_socket.c`; objects.tsv seq 40 [0x10d850, 0x10daf0)) = NeXTMach + soo_rw 의 위 검사(작성, `#if POSIX_KERN`). 빌드·L1·기록. 템플릿·iter·README·GCC27 문서에 플래그 추가.

155 codex 검토 판정(코딩 전; 첫 질의는 900 s 시간 초과로 실패, 범위를 줄여 재질의):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| `#if POSIX_KERN` 7 블록, 구조체 배치 변화는 tty.h:179 `struct nty` 뿐, 잠정 정의 없음(proc.h 는 extern 선언 `pgrphash[]`·`posix_proc_hash[]`) | awk 로 07 sys/{proc,file,tty,fcntl}.h 블록 전수 출력 | ✅ |
| 07 src·nextdev_private·nextmach 사용 0 건 | 내 grep -rln 0 건 | ✅ → 기존 객체 비-디버그 내용 불변 예상 |
| p_posix = 0x16, 마스크 0x02 | proc.h :292 p_link, :313 p_debugger, :315 p_posix; Python 4×4+6 = 22 = 0x16, 1<<1 = 2 | ✅ |

## 156. S5-P130 세부 계획 초안 — `bsd/kern/tty_tty.c` (D024, `-DPOSIX_KERN` 전제, 코딩 전, 2026-10-02)

사실(역어셈블 0x113814–0x1138c5, 심볼): 객체 [0x113748, 0x113912) 5 함수 중 `syioctl` 만 다르다(원본 180 B / NeXTMach 빌드 136 B, 진단 13 NM 객체 함수 크기). 원본 `syioctl` 의 TIOCNOTTY(0x20007471) 처리:
1. `p = u.u_procp`(active_u[0].utask +0), `px = get_posix_proc(p->p_pid)`(0x107898, 인자 `movswl 0x30(p)`).
2. `px->p_posix_pgrp(+0x10)->pg_session(+8)->s_leader(+4) == p` 이면(SDK proc.h `SESS_LEADER`, `p_session` 매크로) `s_ttyp(+8) = 0`, `s_ttyd(+0xc, short) = 0`(같은 경로를 다시 읽음).
3. `p->p_flag(+0x28) &= ~SCTTY`(0xbfffffff = ~0x40000000, SDK proc.h:568).
4. `u.u_ttyp(utask +0x168) = 0`, `u.u_ttyd(+0x16c) = 0`, `return 0`. NeXTMach :74 `u.u_procp->p_pgrp = 0` 은 없다.
나머지(ENXIO 6, `cdevsw[major(u_ttyd)].d_ioctl` 호출)는 NeXTMach 와 같은 꼴.
방법(초안): NeXTMach 바탕, TIOCNOTTY 블록을 `#if POSIX_KERN` 형태로 작성(표시). `get_posix_proc` 선언은 SDK proc.h:277. 필드 오프셋은 코딩 전 Python 으로 SDK 구조체에서 계산해 확인한다. 회귀(155)가 같음일 때만 진행.
156 보충(Python, SDK sys/types.h :139 `pid_t` int, :121–:123 dev_t·gid_t·uid_t short): `struct posix_proc` p_pid 0, p_ruid 4, p_svuid 6, p_svgid 8, p_pgrpnxt 0xc, p_posix_pgrp 0x10; `struct pgrp` pg_session 8; `struct session` s_leader 4, s_ttyp 8, s_ttyd 0xc — 원본 오프셋과 모두 맞음.

### 155.1 회귀 결과(2026-10-02)

- `s5p129-regress-1`(116, `-DPOSIX_KERN`): 112 같음, 4 컴파일 실패(authunix_prot, ddm, kern_time, subr_xxx: SDK `proc.h`:246·258 `pid_t` 미정의 — SDK `sys/types.h`:136–:141 은 `_POSIX_SOURCE` 일 때만 `pid_t` 정의). collect 는 EXPECT 실패로 중단돼 `stage/` 의 객체로 비교(`09_validation/reconstruction/s5p129-regress-compare-20261002.json`).
- 진단 `s5p129-diaga-1`(116, `-DPOSIX_KERN -D_POSIX_SOURCE`): 116 모두 컴파일, 116/116 이전 최종 빌드와 비-디버그 내용 같음(`s5p129-diaga-compare-20261002.json`). 첫 시도는 실행 ID 대문자(`diagA`)로 `kr_run` 이 거부(ID 규칙 `^[a-z0-9][a-z0-9._-]{2,60}$`).
- 판단: 대안은 `nextdev_private/bsd/sys/types.h` 에 커널용 `pid_t` 분기를 작성하는 것(D023 방식)이나, SDK 본문 그대로 컴파일되는 쪽(전역 `-D_POSIX_SOURCE`)을 택한다. 근거: SDK `types.h` 가 `!KERNEL && _POSIX_SOURCE` 일 때만 `standards.h` 를 포함(커널에서 `_POSIX_SOURCE` 를 정의하는 경우를 전제한 형태), 객체 간 충돌 없음(124.1 트리거 미충족 → 사용자 결정 사항 아님). 역사적 사실로 확정된 것은 아니다(가설).
- 최종 플래그에 `-DPOSIX_KERN -D_POSIX_SOURCE`(iter 도구, README, GCC27 문서 갱신). 다음: 155 방법 3(sys_socket).
155 결과: `bsd/kern/sys_socket.c` run `s5p129-it1` 첫 빌드 OBJECT_MATCH 5/5(672 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-sys_socket.md`, `.diff`).

156 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| TIOCNOTTY = `_IO('t',113)` = 0x20007471 | ioctl.h :167 IOC_VOID, :292; Python 0x20000000\|('t'<<8)\|113 | ✅ |
| ~SCTTY = 0xbfffffff | proc.h :568, Python | ✅ |
| p_pid short +0x30, p_flag +0x28 | proc.h :325 p_flag, :328 short p_pid; 원본 `movswl 0x30`, `andl 0x28` | ✅(오프셋은 빌드로 재확인) |
| posix_proc/pgrp/session 오프셋 | 156 보충의 내 Python 계산 | ✅ |
| u_ttyp/u_ttyd = utask +0x168/+0x16c | user.h :178–:179 필드, :429–:430 매크로 확인; 오프셋은 직접 계산하지 않음 | ⚖️ 빌드 결과로 판정 |
| SESS_LEADER 매크로(KERNEL) | proc.h :253–:255 | ✅ |
| 제안 C(세션 저장 둘은 leader 분기 안, `px->p_session` 두 번 씀) | 원본 0x113837–0x11384f 재읽기 | 채택, 빌드로 판정 |
156 결과: run `s5p130-it1` 첫 빌드 OBJECT_MATCH 5/5(458 B) — utask 오프셋 0x168/0x16c 도 일치로 확인. 등급 A 로 기록(`06_reconstruction/evidence/x86-tty_tty.md`, `.diff`).

## 157. S5-P131 세부 계획 — `bsd/kern/vfs_pathname.c` (D024, 코딩 전, 2026-10-02)

사실(진단 13 NM 객체 함수 크기, 역어셈블 0x11c9a0–0x11ca33): 객체 [0x11c97c, 0x11cba8) 8 함수 중 `pn_get` 만 다르다(원본 148 B / NeXTMach 빌드 120 B; 나머지는 끝 패딩 차이뿐). 원본 `pn_get` 은 copyinstr/copystr 뒤, `pn_pathlen--` 앞에 다음 검사를 갖는다: `error == 0 && pnp->pn_pathlen == 0x400(MAXPATHLEN) && pnp->pn_path[0x3ff] != 0` 이면 `error = 0x3f`(63). 그 밖은 NeXTMach :69–:88 과 같은 꼴(pn_alloc 인라인, seg 분기, 실패 시 pn_free 0x11cb84).
방법: NeXTMach 바탕 + 위 검사(작성 표시, `ENAMETOOLONG`·`MAXPATHLEN` 이름은 SDK 값과 대조해 사용). 빌드·L1·기록.

157 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 조건 순서 error → pn_pathlen == 0x400 → pn_path[0x3ff] != 0, error = 0x3f | 역어셈블 0x11c9fc–0x11ca15 | ✅ |
| pn_buf/pn_path/pn_pathlen = +0/+4/+8, 색인은 pn_path | pathname.h :17–:20; 원본 `mov 0x4(%esi)` | ✅ |
| MAXPATHLEN 1024(param.h :251), ENAMETOOLONG 63(errno.h :141) | param.h :251 맞음; errno.h 정의는 :142(:141 은 `#if`) | ⚖️ 줄 오차 1 |
| 다른 명령 차이 없음 | 빌드로 판정 | ⏭️ |
157 결과: run `s5p131-it1` 첫 빌드 OBJECT_MATCH 8/8(553 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-vfs_pathname.md`, `.diff`).

## 158. S5-P132 세부 계획 — `bsd/rpc/auth_kern.c` (D024, 코딩 전, 2026-10-02)

사실(진단 13 NM 객체와 fndiff, 원본 [0x134f94, 0x1351d4)): 6 함수 중 `authkern_marshal` 만 다르다(원본 452 B / NeXTMach 빌드 440 B; authkern_destroy 의 20/18 은 끝 패딩). 차이:
1. 원본 프레임 `sub esp,0x28`(빌드 0x20) — 8 B(struct timeval) 지역 추가; gidlen·credsize 슬롯이 -0x24·-0x28 로 이동.
2. `ptr != NULL` 분기 첫머리에 `getthetime(&now)`(지역 -0x20), 세 번째 IXDR_PUT_LONG 이 전역 `time` 대신 `now.tv_sec`(-0x20) — NeXTMach :120 `time.tv_sec`.
같은 수정을 계획 143.1 `authunix_prot.c`(07 :58 선언, :72 호출)에서 이미 했다(getthetime 은 kern_time.c 의 작성 함수, 계획 145).
방법: NeXTMach 바탕 + `struct timeval now;` 지역 선언(위치는 슬롯 배치로 반복 확인)과 위 호출·인자 변경(작성 표시). 빌드·L1·기록.

158 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| `_authkern_marshal` 0x134fe4, 다음 0x1351a8, 452 B | symbols.tsv grep, Python 0x1351a8−0x134fe4 = 452 | ✅ |
| `ptr` 검사(0x13504d) 뒤, AUTH_UNIX put(0x135061) 앞에 `getthetime(-0x20)` | 역어셈블 0x13504d–0x135061 | ✅ |
| 세 번째 put 값만 바뀜 | fndiff(계획 158 사실 2) | ✅ |
| getthetime 선언 헤더 없음, 정의는 암묵 int(kern_time.c :135) | grep 07 nextdev·nextdev_private·nextmach 0 건, kern_time.c :135 | ✅ — 원형 추가 안 함(계획 154 에서 원형 유무가 레지스터를 바꾼 전례) |
| `now` 를 `ptr` 선언 뒤에 | 빌드로 판정 | 채택 |

### 158.1 결과 1 과 헤더 계획(코딩 전)

- it1(`s5p132-it1`): 5 MATCH, `authkern_marshal` 도 명령 순서 같음; `authkern_create` 1 바이트(오프셋 23): 원본 `movl $auth_kern_ops,0x20(%ebx)`, 빌드 `0x18(%ebx)`. `kalloc`/`bzero` 크기는 둘 다 0x28.
- 원인: SDK `rpc/auth.h`(07 nextdev 사본)의 `AUTH` 는 `#ifndef __NeXT__` 일 때만 `ah_key`(8 B) 를 `ah_ops` 앞에 두고, `__NeXT__` 이면 끝으로 옮긴다. NeXT cc 는 `__NeXT__` 를 미리 정의 → ah_ops 0x18. 원본 커널은 0x20 = NeXTMach `rpc/auth.h` 배치(ah_cred, ah_verf, ah_key, ah_ops, ah_private).
- 07 소스 중 AUTH 필드를 쓰는 것은 auth_kern.c 뿐(grep `ah_ops|ah_private|AUTH_DESTROY|AUTH_MARSHALL|auth->`).
- 방법(D023 A 와 같은 방식): `07_kernel/nextdev_private/bsd/rpc/auth.h` = SDK 본문 + 커널 분기 작성: `#ifndef __NeXT__` → `#if !defined(__NeXT__) || defined(KERNEL)`, `#ifdef __NeXT__` → `#if defined(__NeXT__) && !defined(KERNEL)`(작성 표시, PROVENANCE). 확정·부분 객체 중 이 헤더를 스테이징하는 것은 회귀로 확인.

158.1 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| SDK(__NeXT__) ah_ops 0x18, NeXTMach 0x20, 둘 다 0x28 B | 두 헤더 본문(위 158.1 사실), opaque_auth 12 B·des_block 8 B | ✅ |
| 0x134fa9 `movl $0x1dcd88,0x20(%ebx)` | 역어셈블(158.1 결과 1) | ✅ |
| 원본 0x13576a·0x1359f1·0x12eb41 도 +0x20 읽기 | 역어셈블 세 곳 `mov 0x20(%reg)` 확인; 포인터가 AUTH 인지는 직접 추적하지 않음 | ⚖️ 보강 근거로만 |
| rpc/auth.h 를 쓰는 07 소스 10 개, AUTH 의 ah_verf 뒤 필드 사용은 auth_kern 뿐 | grep -rln 10 건 | ✅ — 나머지 9 개는 회귀 |
| 두 조건을 짝으로 바꾸는 것이 types.h overlay 방식과 일치 | nextdev_private/bsd/rpc/types.h diff | ✅ |
158.1 결과: it2(`s5p132-it2`, overlay 사용) OBJECT_MATCH 6/6(574 B). rpc/auth.h 를 쓰는 나머지 9 확정 객체 회귀 `s5p132-rg-1` 9/9 같음(`09_validation/reconstruction/s5p132-rg-compare-20261002.json`). auth_kern 등급 A, overlay 는 PROVENANCE·MODIFICATIONS 에 기록.

## 159. S5-P133 세부 계획 — `bsd/kern/vfs_vnode.c` (D024, 코딩 전, 2026-10-02)

사실(진단 13 NM 객체 fndiff, 원본 [0x11de7c, 0x11eaa4)): 10 함수 중 `vn_rdwr` 만 다르다(원본 216 / 빌드 204; vn_open 616/612 는 끝 패딩과 재배치 표기 차이뿐). 원본 `vn_rdwr` 은 `MACH_NBC` 블록의 조건이 `vp->v_type == VREG`(`cmp [esi+0x28],1`) 다음에 `active_u[0].utask->uu_procp` 의 0x16 bit 2(`p_posix`, 계획 155) 가 0 일 때만 map_vnode/mfs_io/unmap_vnode 경로, 아니면 VOP_RDWR. NeXTMach :71 은 `if (vp->v_type == VREG)`.
방법: NeXTMach 바탕, :71 조건을 `#if POSIX_KERN` 아래 `(vp->v_type == VREG && !u.u_procp->p_posix)` 로(작성 표시), `struct proc` 정의를 위해 `#import <sys/proc.h>`(조건부). 빌드·L1·기록.

159 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| VREG == 1 | vnode.h :37 enum(VNON, VREG, …, VFIFO = 8) | ✅ |
| p_posix 검사 0x11ded3–0x11dede, 설정 시 0x11df08(VOP_RDWR) 로 | 역어셈블 0x11decd–0x11dede; vnode.h :124 VOP_RDWR | ✅ |
| 다음 심볼 `_vn_rele` 0x11df54 | symbols.tsv | ✅ |
| 헤더가 sys/proc.h 를 가져오지 않음 | grep user.h·vnode.h·vfs.h 0 건 | ✅ — 조건부 import |
| 그 밖 같음 | fndiff(계획 159 사실) | ✅ |

### 159.1 정정(it1 결과, 코딩 전)

- it1(`s5p133-it1`): vn_rdwr 216/216 일치, 그러나 객체 unplaced — `vn_open` 612/616(원본). 계획 159 의 "vn_open 차이는 끝 패딩뿐" 은 **틀렸다**(vn_open 은 마지막 함수가 아님).
- 원본 vn_open 은 truncate 의 VOP_SETATTR 뒤 `test ebx,ebx; jne` 로 `error == 0` 을 먼저 보고, 그 다음 `filemode & 0x40000000`(SDK fcntl.h:60 `O_NO_MFS`), `v_type == VREG` 일 때 map_vnode. NeXTMach :264 는 `(filemode & O_NO_MFS) == 0 && vp->v_type == VREG`.
- 수정: :264 조건 앞에 `error == 0 &&`(작성 표시).
159.1 codex 판정: error(ebx) → O_NO_MFS → VREG 순서(0x11e18a–0x11e19d), map_vnode 0x11e1a0 — 내 역어셈블과 같음 ✅; "그 밖 의미 차이 없음" — 빌드로 판정.

### 159.2 정정 2(it2 결과, 코딩 전)

- it2(`s5p133-it2`, vn_open 수정): 9 MATCH, `vn_create` 1 바이트(분기 거리 0x47 / 0x52) — 원본 0x11e2a0–0x11e2a4: `VFS_RDONLY` 이고 `*vpp == NULL` 이면 바로 `error = EROFS`(0x11e2ed); `*vpp` 가 VCHR/VBLK(`v_type−3 <= 1`) 이면 else 쪽(0x11e2f8); 그 밖이면 VN_RELE 뒤 EROFS. 빌드(NeXTMach :358 `&& *vpp != (struct vnode *)0 && …`)는 `*vpp == NULL` 이면 else 쪽.
- 수정: :358–:359 조건을 `&& (*vpp == (struct vnode *)0 || ((*vpp)->v_type != VCHR && (*vpp)->v_type != VBLK))` 로(작성 표시). 본문 `if (*vpp) VN_RELE(*vpp);` 는 그대로.
159.2 codex 판정: 세 경로(0x11e29a–0x11e2ea) — 내 역어셈블(위 0x11e29c–0x11e2f8 출력)과 같음 ✅, VBLK 3·VCHR 4(vnode.h :37) ✅.
159 결과: it3(`s5p133-it3`) OBJECT_MATCH 10/10(3110 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-vfs_vnode.md`, `.diff`). 교훈: 마지막이 아닌 함수의 크기 차이는 패딩이 아니다(fnsizes 의 "orig" 는 다음 원본 심볼까지).

## 160. S5-P134 세부 계획 — `bsd/kern/vfs_io.c` (D024, 코딩 전, 2026-10-02)

사실(진단 13 NM 객체 fndiff, 원본 [0x11b984, 0x11c0f8)): 8 함수 중 `vno_rw`(원본 208 / 빌드 192)·`vno_stat`(284 / 220) 이 다르다.
1. `vno_rw`: (a) iomode 계산 뒤 `vp->v_type == VFIFO`(8, vnode.h :37) 이면 `uiop->uio_fmode = fp->f_flag`(short 저장, uio +0x10) — 계획 155 의 soo_rw 와 같은 FIFO/POSIX 처리; (b) mfs_io 조건에 `!u.u_procp->p_posix`(0x16 bit 2) 추가: `v_type == VREG && vm_info->mapped && !p_posix`. 소스 위치·조건부(`#if POSIX_KERN`)는 빌드로 확정.
2. `vno_stat`(원본 0x11bc50, 역어셈블 0x11bd1e–0x11bd5c): NeXTMach :228 `st_spare4[0] = st_spare4[1] = 0`(0x3c, 0x38 순 저장) 뒤에
   - `vp->v_op == &ufs_vnodeops`(0x1de480) 이면 `st_spare4[0] = 0xfeedface`, `st_spare4[1] = VTOI(vp)->i_gen`(v_data +0xd0);
   - 아니고 `vp->v_op == &nfs_vnodeops`(0x1dca20) 이며 `rnode +0x4c == sb->st_ino`(stat +4) 이면 `st_spare4[0] = 0xfeedface`, `st_spare4[1] = rnode +0x50`.
   오프셋(Python, SDK 헤더): vnode `v_op` 0x1c·`v_type` 0x28·`v_data` 0x30·크기 0x34; inode `i_ic` 0x64 → `ic_gen` 0xd0(ufs/inode.h :133 "108"); rnode `r_vnode` 0xc → `r_fh` 0x40; NFS_SERVER(생성 헤더 1) 이면 `fhandle_t = struct svcfh`(nfs.h :115–:137): `fh_len` 0x48, `fh_data[10]` 0x4a; `(struct ufid *)&r_fh.fh_len`(ufs/inode.h :365–:368: len 0, ino 4, gen 8) → ino 0x4c, gen 0x50.
   참고 원문(NeXTMach, Darwin)에 0xfeedface 를 stat 에 쓰는 코드 없음(grep: MH_MAGIC 뿐) → 작성. 식의 꼴은 바이트로 정할 수 없어 위 이름으로 쓴다(표시).
방법: NeXTMach 바탕 + 1·2(작성 표시). 필요한 헤더: `<nfs_server.h>`, `<ufs/inode.h>`, `<nfs/nfs.h>`, `<nfs/rnode.h>`(스테이징 manifest 로 SDK 사본 확인), `extern struct vnodeops ufs_vnodeops, nfs_vnodeops;`. 빌드·L1·기록(헤더 추가가 잠정 정의를 끌어오면 common 간격 36.1 검사).

160 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| vno_rw: iomode 뒤 VFIFO→uio_fmode(0x11b9dc–0x11b9e2), 그 뒤 VREG→mapped→!p_posix(0x11b9e6–0x11b9ff) | 내 역어셈블 같은 구간 | ✅ |
| p_posix 는 0x16 의 마스크 0x02("bit 2" 표현 정정) | 155 의 Python(1<<1 = 2) | ✅ 표현 정정 |
| stat st_ino 4, st_spare4 0x38/0x3c, 0x3c 먼저 0 | 역어셈블 0x11bd10–0x11bd17, 160 사실 | ✅ |
| 0xd0·0x4c·0x50 경로 | 160 의 내 Python 계산 | ✅ |
| 헤더 추가 시 잠정 정의 2 개: inode.h :202 `inode_list`, :287 `iuniqtime` | SDK inode.h 두 줄 확인; 원본 `_inode_list` 0x1e978c·`_iuniqtime` 0x1e9790 섹션 6(__common) | ✅ — 기록 도구의 common 간격 검사로 확인 |
| ufs_vnodeops 는 inode.h :204 에 extern, nfs_vnodeops 는 선언 없음 | grep | ✅ |

### 160.1 결과와 추가 수정 계획(코딩 전)

- it1: `nfs/nfs.h` 가 `bool_t` 를 써 컴파일 실패 → `<rpc/types.h>` 를 nfs.h 앞에(nfs_export.c 와 같은 순서). it2(`s5p134-it2`): vno_rw·vno_stat 포함 7 MATCH, `vno_bsd_lock` DIFF(진단 13 에서도 같은 차이, 크기가 같아 목록에서 빠졌던 것).
- 원본 vno_bsd_lock(역어셈블): `priority` 를 [ebp-4] 에 두고 `if ((cmd & LOCK_EX) == 0) priority++` 를 읽기·inc·쓰기·다시 읽기로 수행. 빌드는 상수 0x24 를 바로 저장.
- 진단 변형(스테이징 사본만 수정): v1 `setjmp` → `set_label`(같은 주소 0x186f88 의 별칭; vno_ioctl 도 바뀌어 더 멀어짐) → 기각. v2 `register int priority` → `volatile int priority` → **OBJECT_MATCH 8/8**(`s5p134-v2`).
- 수정: 07 vfs_io.c 의 vno_bsd_lock 선언을 `volatile int priority;` 로(작성 표시). 그 뒤 빌드·기록.
160.1 codex 판정: priority 읽기·inc·쓰기·재읽기(0x11bef0–0x11bef7), sleep 인자 재읽기(0x11bf69) — volatile 과 일치 ✅(내 역어셈블 앞부분 비교, 0x11bf69 확인); set_label/setjmp 같은 주소 ✅(symbols.tsv). 바이트만으로 원래 선언이 정해지지는 않음(가설, 변형 v2 일치가 근거).
160 결과: it3(`s5p134-it3`) OBJECT_MATCH 8/8(1905 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-vfs_io.md`, `.diff`); SDK `ufs/inode.h`·`nfs/rnode.h` 07 nextdev 채택.

## 161. S5-P135 세부 계획 — `bsd/kern/uipc_usrreq.c` (D024, 코딩 전, 2026-10-02)

사실(원본 [0x118118, 0x118d54); 진단 13 NM 객체와 점프 테이블을 건너뛰는 비교 도구 scratchpad `jtdiff.py`): 16 함수 중 `uipc_usrreq`(1248 / 1232)·`unp_attach`(132 / 104) 가 다르다.
1. `uipc_usrreq` PRU_SENSE(원본 0x11856e–0x118589): `getthetime(&tv)`(지역 -8, 프레임 +8 B) 뒤 st_atime·st_mtime·st_ctime(+0x18/+0x20/+0x28) 에 `tv.tv_sec` — NeXTMach :260–:262 는 `time.tv_sec` 세 번(계획 143.1·158 과 같은 꼴).
2. `uipc_usrreq` PRU_ACCEPT: 원본은 주소가 있을 때 m_len 복사 뒤 공유 bcopy 꼬리로 jmp, 빌드는 PRU_PEERADDR 본문으로 통째로 jne(코드 공유 차이). 원본 PEERADDR 에 `m_len = 0` else 없음(Darwin 4.4 형태 아님). 1 을 고친 뒤 빌드 결과로 판단.
3. `unp_attach`: switch 에 `default:` 가 있어 `error = 0`(xor ebx) 뒤 `panic("unp_attack: bad so_type")`(원본 문자열 0x1db3ec, 오타 그대로); sb_hiwat 검사(Darwin :351) 없음. 시도: `int error = 0;` + `default: panic("unp_attack: bad so_type");`.
방법: NeXTMach 바탕 + 1·3(작성 표시), 빌드 후 2 판단·반복. 기록.

161 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| PRU_SENSE: getthetime(ebp-8) 뒤 +0x18/+0x20/+0x28 | 내 역어셈블 0x11856e–0x118589 | ✅ |
| ACCEPT 0x118248: 있으면 m_len 복사 후 공유 bcopy 꼬리 0x1185ad 로 jmp, 없으면 sun_noname; PEERADDR 0x118590 는 자기 검사 뒤 같은 꼬리로; else 없음 | 정규화 비교(161 사실 2), 0x1826f `movw $0x10` | ✅ — 1 수정 뒤 빌드로 판단, 안 되면 goto 시도 |
| unp_attach default: xor ebx, push 0x1db3ec, panic 0x10ca6c; 문자열 오타 | 내 역어셈블 0x118640–0x118647, 바이트 덤프 | ✅; `int error = 0` 인지 default 안 대입인지는 바이트로 미정 |
161 결과: it1 uipc_usrreq 일치(ACCEPT 배치는 PRU_SENSE 수정으로 해결 — goto 불필요), unp_attach 128/132(`int error = 0` 은 진입부로 올라감); it2 `default:` 안 `error = 0` → OBJECT_MATCH 16/16(3130 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-uipc_usrreq.md`, `.diff`).

## 162. S5-P136 세부 계획 — `bsd/kern/uipc_mbuf.c` (D024, 코딩 전, 2026-10-02)

사실(원본 [0x113b5c, 0x114b8c), 진단 13 NM 객체, jtdiff): 17 함수 중 `mbinit` 만 다르다(116 / 112). `mcldup` 196/176 은 원본에서 이름 없는 정적 함수(빌드의 `buffree` 19 B, kfree 호출)가 뒤에 붙어 커 보인 것 — 명령 차이 없음. 원본 mbinit(역어셈블 0x113b5c–0x113bce): initcl 계산·splimp 뒤 `ebx = ebx*9 + ebx`(×10)을 두 m_clalloc 호출(MPG_MBUFS 0, MPG_CLUSTERS 1) 모두의 첫 인자로 씀; panic 문자열 "mbinit"(0x1db1cc). NeXTMach :56·:58 은 `initcl`. Darwin `bsd/kern/uipc_mbuf.c`:115 는 `m_clalloc(max(4096/CLBYTES, 1) * 10, …)`(4.4 이후 형태, 구조 참고).
방법: NeXTMach 바탕, :56·:58 첫 인자를 `initcl * 10` 으로(작성 표시). 빌드·L1·기록.
162 codex 판정: mbinit ×10 과 두 호출 같은 값(0x113b90–0x113ba7) ✅(내 역어셈블); mcldup 뒤 0x114b78–0x114b8a 이름 없는 정적 함수 = NeXTMach :528 buffree(kfree) ✅(역어셈블·소스 줄 확인).
162 it1: `vm/vm_param.h` 가 스테이징에 없어 컴파일 실패 → 계획 138·139 와 같은 방식으로 `<mach/vm_param.h>` 로 바꿈(표시).
162 결과: it2(`s5p136-it2`) OBJECT_MATCH 18/18(4143 B, 정적 buffree 포함). 등급 A 로 기록(`06_reconstruction/evidence/x86-uipc_mbuf.md`, `.diff`).

## 163. S5-P137 세부 계획 — `netinet/tcp_usrreq.c` (D024, 코딩 전, 2026-10-02)

사실(원본 [0x12ac0c, …) objects.tsv seq 89; 진단 13 NM 객체, jtdiff 정규화 비교): 5 함수 중 `tcp_usrreq`(1108 / 1036)·`tcp_attach`(136 / 124) 가 다르다(`tcp_usrclosed` 116/114 는 마지막 함수 끝 패딩).
1. `tcp_usrreq`: 원본은 `ostate = tp->t_state`(지역 -8) 를 보관하고, `tp = tcp_disconnect/close/usrclosed/drop/timers(…)` 의 반환값을 ebx 에 받으며, PRU_SLOWTIMO 에서 `req |= (int)nam << 8`, 끝에서 `if (tp && (so->so_options & SO_DEBUG)) tcp_trace(TA_USER, ostate, tp, 0, req)`(push 2 = TA_USER). NeXTMach :321–:324 는 이 호출을 `#if DEBUG` 로 감싸 빌드에서 빠지고 ostate·tp 대입이 죽은 코드가 됨. 원본에 `_tcp_trace` 존재(계획 152 에서 tcp_debug.c 를 DEBUG 가드 없이 복원).
2. `tcp_attach`: soreserve 를 `if (so->so_snd.sb_hiwat == 0 || so->so_rcv.sb_hiwat == 0)`(원본 `cmp word [esi+0x3e]`, `[esi+0x26]`) 안에서만 — Darwin `bsd/netinet/tcp_usrreq.c`:493–:497 과 같은 꼴(구조 참고). NeXTMach :403–:405 는 무조건.
방법: NeXTMach 바탕, 1 은 `#if DEBUG`/`#endif` 를 없앰(작성 표시, 계획 152 와 같은 판단), 2 는 조건 추가(작성 표시). 빌드·L1·기록.

163 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 끝의 tcp_trace(TA_USER 2, ostate, tp, 0, req), tp·SO_DEBUG 조건(0x12b029–0x12b048) | 역어셈블 같은 구간, 정규화 비교 | ✅ |
| PRU_SLOWTIMO 의 tp = tcp_timers, req \|= nam << 8 | 정규화 비교의 `shl eax,8; or [ebp+0xc]` | ✅ |
| tcp_attach: snd(0x3e) → rcv(0x26) hiwat 검사 | 내 Python 배치(sockbuf 0x18, rcv.hiwat 0x26, snd.hiwat 0x3e) | ✅ |
| 그 밖 의미 차이 없음 | 빌드로 판정 | ⏭️ |
163 결과: 첫 빌드(`s5p137-it1`) OBJECT_MATCH 5/5(1686 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-tcp_usrreq.md`, `.diff`).

## 164. S5-P138 세부 계획 — `bsd/kern/vfs.c` (D024, 코딩 전, 2026-10-02)

사실(objects.tsv seq 53, 진단 13 NM 객체, 비교 도구 scratchpad `ndiff2.py`/`shapediff.py`): 20 함수 중 `smount`(1344 / 1212)·`vfs_mountroot`(604 / 592) 가 다르다.
1. `smount`(원본 역어셈블 0x118dbf–0x118e5e): NeXTMach :114–:148 의 검사들 뒤 VROOT 검사(:144)에서, VROOT 이고 M_REMOUNT 가 아니면 EBUSY(그대로); **VROOT 가 아니면** `error = VOP_ACCESS(vp, 0x80 = VWRITE(vnode.h :205), u.u_cred)`(v_op +0x1c = vn_access, vnode.h :88 여덟째) 를 부르고, 0 이 아니면 `VN_RELE(vp)`(vn_rele 0x11df54) 뒤 `u.u_error = error` 하고 반환. NeXTMach 에 없음.
2. `vfs_mountroot`(원본 0x119538–): 진입부 `xor esi,esi`(`error = 0` 초기화), `if (error)` 안에서 panic 전에 `printf("vfs_mountroot: error=%d\n", error)`(문자열 0x1db48d, _printf 0x10c0d8); NeXTMach :644–:646 은 panic 만.
방법: NeXTMach 바탕 + 1(VROOT 검사 뒤 `if (!(vp->v_flag & VROOT))` 블록, `error` 지역 추가 — 꼴은 빌드로 확정), 2(`register int error = 0;` 와 printf). 작성 표시. 빌드·L1·기록.
164 codex 판정: smount VROOT/M_REMOUNT 분기와 비-VROOT 의 VOP_ACCESS(vp, VWRITE, cred) 및 오류 경로(0x118e08–0x118e5e) ✅(내 역어셈블); vnode.h :88 vn_access 여덟째, :205 VWRITE ✅; vfs_mountroot xor esi·printf 문자열 ✅(내 바이트 덤프). 중첩 if 형태를 채택.

### 164.1 it2 결과와 추가 수정 계획(코딩 전)

- it1 `vm/vm_param.h` 컴파일 실패 → `<mach/vm_param.h>`(계획 138·139·162 와 같음). it2(`s5p138-it2`): vfs_mountroot 일치, smount 1280/1344, 객체 unplaced, `__data` 차이(문자열 추가 때문으로 예상).
- 원본 smount(역어셈블 0x119101–0x1191b2, 호출 목록): (a) 가상 마운트가 아닌 경로(else)에서도 ufs 잠금 검사 **전에** `strncpy(vfsp->vfs_name, pn.pn_path, MAXNAMLEN)`(0x119130–0x11913d, 0xff); (b) 두 경로가 합류한 뒤 `if (vfsp->vfs_name && strncmp(vfsp->vfs_name, "/Net/AppleShare", 15) == 0) vfsp->vfs_flag |= 0x100;`(0x119186–0x1191a1; 문자열 0x1db47d; `lea eax,[esi+0x20]; test eax` 은 배열 주소의 NULL 검사). 0x100 은 SDK vfs.h 에 이름이 없다(VFS_ 정의는 0x80 까지) → 숫자 그대로(작성). NeXTMach :328–:338 의 else 에 strncpy 없음, AppleShare 블록 없음.
- 수정: (a)·(b) 를 :329 앞·:339 뒤(nosuid 검사 앞)에 작성 표시로 넣고 빌드로 위치 확정.
164.1 codex 판정: (a) strncpy(0x119130–0x11913d) 가 ufs_vnodeops 비교(0x119148)·ILOCK 루프보다 앞 ✅, (b) AppleShare 블록(0x119186–0x1191a1) 이 vfs_uid 검사(0x1191a8) 앞 ✅ — 내 역어셈블과 같음. codex 의 "파일 오프셋 0x190130" 은 오기(0x19130) ⚖️.

### 164.2 it3 결과와 추가 수정(코딩 전)

- it3(`s5p138-it3`): smount 1336/1344. 남은 차이: 원본 0x119078 `movl $0x0,-0x1c(%ebp)` — 새 마운트(else, NeXTMach :296) 경로 첫머리, pn_get 앞. -0x1c 는 `saved_flag`(원본 0x119067 저장 = NeXTMach :280 `saved_flag = vfsp->vfs_flag`, 0x11925a 복원 = :390).
- 수정: :296 `} else {` 다음에 `saved_flag = 0;`(작성 표시).
164.2 codex 판정: -0x1c = saved_flag(0x119067 저장, 0x11925a 복원), 0x118f8b 의 M_REMOUNT 분기가 0x119078 로 — 내 역어셈블(위 출력)과 같음 ✅.
164 결과: it4(`s5p138-it4`) `__text` 3637 B·`__data` 차이 0, 20 함수 MATCH(2 개는 `__bss` 참조로 MATCH_UNVERIFIED). `__bss` 16 B(static devmap) 는 0x1e58c8 로 참조 추정(`s5p138-zerofill-check-vfs-20261002.json`) → 등급 **P**(`objects_partial.tsv`), known 배치 `zerofill-known-s5p138-20261002.json`(20 항목).

## 165. S5-P139 세부 계획 — `netinet/tcp_subr.c` (D024, 4.3-Reno 형태, 코딩 전, 2026-10-02)

사실(원본 [0x12a434, 0x12a8cc) objects.tsv seq 87; 진단 13 NM 객체, jtdiff/shapediff, 원본 역어셈블): 10 함수 중 tcp_init·tcp_template·tcp_drain·tcp_quench 는 같고 다음이 다르다. 형태는 4.3-Reno(Darwin `bsd/netinet/tcp_subr.c` 4.4 판을 구조 참고, 4.4 고유분은 원본에 없음).
1. `__data`: 원본 `_tcp_ttl` 0x1dbe8c(60), `_tcp_mssdflt` 0x1dbe90(512 = SDK tcp.h :82 TCP_MSS), `_tcp_rttdflt` 0x1dbe94(3 = TCPTV_SRTTDFLT(6)/PR_SLOWHZ(2)) — NeXTMach :49 는 tcp_ttl 만. Darwin :113–:114 와 같은 정의를 추가.
2. `tcp_respond`(0x12a504): 인자 `(tp, ti, m, ack, seq, flags)`(m = 셋째, 0x10(%ebp)); `if (m == 0)`(NeXTMach :88 `if (flags == 0)`) 에서 m_get·복사·`flags = TH_ACK`(0x1c(%ebp) 에 0x10); else 에서 `m = dtom(ti)` 없이 m_freem(m->m_next)…; tlen 0(TCP_COMPAT_42 없음); 끝의 `ip_output(m, 0, ro, 0, 0)` 5 인자(0x12a640–0x12a64b; MULTICAST 판의 ip_moptions 자리로 봄).
3. `tcp_newtcpcb`(0x12a65c): `t_maxseg = tcp_mssdflt`, `t_rttvar = tcp_rttdflt * PR_SLOWHZ << 2`(`shl $3`), `t_rttmin = TCPTV_MIN`(0x64 ← 2), t_rxtcur 0xc(Python ((0>>2)+(6<<2))>>1 = 12), `snd_cwnd = snd_ssthresh = TCP_MAXWIN`(0xffff, tcp.h :84) — NeXTMach 은 TCP_MSS, `TCPTV_SRTTDFLT << 2`, sbspace, 65535.
4. `tcp_drop`: `if (errno == ETIMEDOUT && tp->t_softerror) errno = tp->t_softerror;`(tcp_var.h :116 short) — Darwin 과 같은 줄.
5. `tcp_close`: 재조립 큐에서 `m = REASS_MBUF((struct tcpiphdr *)t->ti_prev)`(tcp_var.h :160, +0x14) — NeXTMach `dtom(t->ti_prev)`; soisdisconnected 뒤 `if (inp == tcp_last_inpcb) tcp_last_inpcb = &tcb;`(원본 `_tcp_last_inpcb` 0x1dbe44, SDK 선언 없음 → extern 작성).
6. `tcp_notify`(0x12a7d8): NeXT 오류 무시 블록 뒤 `((struct tcpcb *)inp->inp_ppcb)->t_softerror = error`(+0x6a, error = so_error, 블록 밖에서 먼저 읽음).
7. `tcp_ctlinput`(0x12a83c): Reno 형태 `tcp_ctlinput(cmd, sa, ip)`: notify = tcp_notify, PRC_QUENCH(4) 이면 tcp_quench, 아니면 `(unsigned)cmd > PRC_NCMDS(21) || inetctlerrmap[cmd] == 0` 이면 반환; ip 가 있으면 th = ip + ip_hl<<2, `in_pcbnotify(&tcb, sa, th->th_dport, ip->ip_src, th->th_sport, cmd, notify)`, 없으면 `(…, 0, zeroin_addr, 0, cmd, notify)`(_zeroin_addr 0x1eab2c). Darwin 의 PRC_IS_REDIRECT 검사 없음.
방법: NeXTMach 바탕 + 1–7 작성(표시). 호출 원형은 두지 않음(계획 154 교훈: 암묵 선언 유지). 빌드 반복·L1·기록.

165 codex 검토 판정(코딩 전): 7 항목 모두 원본 주소로 뒷받침(내 역어셈블: tcp_respond 0x12a504–0x12a659, tcp_newtcpcb, tcp_drop 0x12a70a–0x12a71b, tcp_close 0x12a74c–0x12a7a0, tcp_notify, tcp_ctlinput 0x12a83c–0x12a8ad 와 같음) ✅. 변경 없는 4 함수 ✅(진단 13 크기 같음). t_rttvar·t_rxtcur 식의 꼴과 ip_output 다섯째 인자 이름은 바이트로 미정 — Darwin/Reno 식을 쓴다.
165 결과: 첫 빌드(`s5p139-it1`) OBJECT_MATCH 10/10(1173 B, `__data` 일치). 등급 A 로 기록(`06_reconstruction/evidence/x86-tcp_subr.md`, `.diff`).

## 166. S5-P140 세부 계획 — `netinet/in_pcb.c` (D024, 4.3-Reno + MULTICAST 1.0 형태, 코딩 전, 2026-10-02)

사실(원본 [0x124e10, 0x125554) objects.tsv seq 79; 진단 13 NM 객체, shapediff, 원본 역어셈블; Reno 원문은 참고 자료에 없음 → 원본 바이트로 작성, Darwin `bsd/netinet/in_pcb.c`(4.4) 는 구조 참고): 11 함수 중 in_pcbbind·disconnect·setsockaddr·setpeeraddr·losing·rtchange 는 같고 다음이 다르다.
1. `insque`/`remque` 가 원본에서 인라인(in_pcballoc, in_pcbdetach) — 07 `kern/queue.h`:201·:213 의 인라인 함수와 같은 꼴(tcp_subr.c 는 이 헤더를 가져와 tcp_close 의 remque 가 인라인). → `#import <kern/queue.h>` 추가.
2. `in_pcbconnect`: (a) 진입부 `xor ebx,ebx` → `struct sockaddr_in *ifaddr = 0;`; (b) `if (ia == 0) {…}` 블록 뒤(0x125143–0x125182) MULTICAST 블록 — `IN_MULTICAST(ntohl(sin->sin_addr.s_addr)) && inp->inp_moptions` 이면 `imo = mtod(inp->inp_moptions, struct ip_moptions *)`(SDK in_pcb.h :40 `struct mbuf *inp_moptions`), `imo->imo_multicast_ifp`(ip_var.h :92) 가 있으면 in_ifaddr(0x1eaa60) 에서 ia_ifp 가 같은 ia 를 찾고 없으면 EADDRNOTAVAIL(49) — Darwin :444 이하와 같은 구조(Darwin 은 mtod 없음); (c) in_pcblookup 뒤(0x1251cc–0x1251fd) `if ((inp->inp_socket->so_proto->pr_flags & PR_CONNREQUIRED) && sin->sin_port == inp->inp_lport && (inp->inp_laddr.s_addr ? inp->inp_laddr.s_addr : ifaddr->sin_addr.s_addr) == sin->sin_addr.s_addr) return (ECONNREFUSED);`(61) — 참고 원문에 없음, 작성.
3. `in_pcbdetach`: rtfree 뒤 remque 앞 `ip_freemoptions(inp->inp_moptions)`(0x128190, MULTICAST).
4. `in_pcbnotify(head, dst, fport, laddr, lport, cmd, notify)`(0x125340): cmd > PRC_NCMDS 또는 dst 가 AF_INET 아님 또는 faddr ANY 면 반환; `PRC_IS_REDIRECT(cmd) || cmd == PRC_HOSTDEAD || cmd == PRC_ROUTEDEAD` 면 fport·lport·laddr 0, `cmd != PRC_HOSTDEAD` 면 notify = in_rtchange; errno = inetctlerrmap[cmd]; 루프(faddr·socket·lport·laddr·fport 검사) 에서 `if (errno) oinp->inp_socket->so_error = errno; if (notify) (*notify)(oinp);`(인자 1 개) — Reno 형태, Darwin 의 `(*notify)(oinp, errno)` 아님, PRC_ROUTEDEAD 추가는 원본 고유.
5. `in_pcblookup`: faddr 비교 쪽에서 `inp->inp_fport != fport || IN_MULTICAST(ntohl(inp->inp_faddr.s_addr)) || inp->inp_faddr.s_addr != faddr.s_addr` 이면 continue(0x1254f4–0x125511 순서) — multicast 제외는 원본 고유.
방법: NeXTMach 바탕 + 1–5 작성(표시). 빌드 반복·L1·기록.

## 167. 사용자 공간 libsys(libc·cthreads) 분석 준비 — 원본 수집 계획 (2026-10-02, 사용자 지시)

목적: 향후 cthreads·libsys 복원/분석을 위해 실기 OPENSTEP 4.2 의 시스템 라이브러리 원본과 헤더를 보존한다(코드 작성 아님).
조사(실기, gcds): libc 는 `/NextLibrary/Frameworks/System.framework/Versions/A/System`(3,643,932 B; `/lib/libsys_s.A.dylib` 링크 대상), 프로파일판 `System_profile`(`/lib/libsys_p.dylib`), 호환용 `/usr/shlib/libsys_s.B.shlib`(1,081,324 B). 시작 코드 `/lib/{crt0,crt1,gcrt0,gcrt1,dylib1,bundle1}.o`, `/lib/libcc.a`·`libcc_dynamic.a`, 동적 링커 `/usr/lib/dyld`. 프레임워크 Headers 는 `/NextDeveloper/Headers/{ansi,architecture,bsd,mach,mach-o,machkit,objc,remote,streams}` 링크(9 디렉터리 실기 파일 수 575 — 디렉터리별로 로컬 `ref/openstep/headers` 사본과 같은 수; 처음 적은 707 은 로컬 Headers 전체 수를 잘못 옮긴 것). `/NextDeveloper/Source` 에는 GNU 도구만 있고 libc 소스 없음.
방법: 실기에서 `cat 원본 > /ndrv/…`(cp -p 빈 파일 함정 회피)로 `03_original/x86/userland/binaries/<원 경로>` 에 복사, 실기 `krsha256` 와 호스트 sha256 이 같아야 채택. 해시·크기·원 경로·mtime 은 `03_original/x86/userland/inventory/` 에 기록(바이너리는 기존 규칙 `/03_original/**/binaries/*` 로 git 제외). 헤더는 실기 575 파일의 krsha256 을 로컬 사본과 전수 대조해 표로 남기고, 다르거나 없는 것만 실기에서 복사.
167 결과(2026-10-02): 바이너리 13 개 + cpp-precomp 헤더 5 개를 실기 krsha256 과 같은 해시로 `03_original/x86/userland/binaries/` 에 보존(`inventory/files.json`). 헤더 575 파일 대조: 같음 570, 다름 5(`ansi.p`, `bsd/libc.p`, `mach/cthreads.p`, `mach/mach.p`, `objc/Object.p`), 로컬에만 있는 `objc/hashtable.h` 는 양쪽 모두 `hashtable2.h` 링크(`inventory/headers-sha256.tsv`). `System`·`System_profile` 은 m68k·i386·SPARC universal → 조각별, `libsys_s.B.shlib`·`dyld` 와 함께 `inventory/<이름>/{macho.json,symbols.tsv,strings.tsv}`(System-i386: 섹션 33, nlist 5477, 외부 정의 2256). 실기 gcds 주의: `cd` 뒤 상대 경로 find 가 "bad status" 로 실패 — 절대 경로 사용.

166 codex 검토 판정(코딩 전; 첫 질의는 사용자 중지로 중단, 재질의):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| insque/remque 인라인(0x124e3a–, 0x1252b2–) | 내 역어셈블 in_pcbdetach 0x1252b2–0x1252bf | ✅ |
| ifaddr 0 초기화, MULTICAST 블록(0x125143–0x125190), 자기 연결 검사 순서 PR_CONNREQUIRED→포트→주소(laddr 0 이면 ifaddr->sin_addr 비교) | 내 역어셈블 0x125130–0x125204 | ✅ |
| detach: sofree, m_free(옵션), rtfree, **무조건** ip_freemoptions, remque, kfree | 내 역어셈블 0x12526c–0x1252c4 | ✅ |
| notify: 14–17·6·1, so_error 저장 **후** 반복자 이동, notify(oinp) 1 인자 | 내 역어셈블 0x125378–0x12540d | ✅ — 166 사실 4 의 "oinp->…so_error" 표현을 "이동 전 inp" 로 정정 |
| lookup: fport → IN_MULTICAST → faddr 순 | 내 역어셈블 0x1254f4–0x125511 | ✅ |
| 오프셋 inp_moptions 0x3c, so_proto 0xc, pr_flags 0xa, ia_ifp 0x20, ia_next 0x40 | 내 Python 배치(inpcb 크기 0x40, protosw, in_ifaddr) | ✅ |
| SDK in_var.h 가 07 nextdev 에 없음 | ls 확인 — 스테이징이 실기 SDK 사본(bsd-set nextos)에서 가져와 기록 시 채택 | ✅(조치: 기록 단계에서 채택) |

### 166.1 it1 결과와 변형(코딩 전)

- it1(`s5p140-it1`): 10 MATCH, `in_pcbnotify` 6 바이트 — fport·lport 레지스터가 서로 바뀜(원본 fport=cx, lport=di; 빌드 반대).
- 스테이징 사본 변형: v1 인자 선언 순서 `u_short lport, fport` → 같음(실패); v2 Darwin 꼴 `u_int fport_arg, lport_arg` + 지역 `u_short fport = fport_arg, lport = lport_arg` → 같음(실패); v3 `fport = 0; lport = 0;`(Darwin `bsd/netinet/in_pcb.c` in_pcbnotify 꼴) → **OBJECT_MATCH 11/11**; v4 `lport = fport = 0;` → OBJECT_MATCH 11/11.
- 선택: 바이트로 v3·v4 를 구분할 수 없으므로 구조 참고(Darwin)와 같은 v3 을 07 에 반영(가설).
166.1 codex 판정: v3 사본 차이가 대입 한 줄뿐, v3·v4 L1 OBJECT_MATCH, Darwin :611–:612 분리 대입 — 내 diff·sed 로 확인 ✅.
166 결과: it2(`s5p140-it2`, v3 반영) OBJECT_MATCH 11/11(1859 B). 등급 A 로 기록(`06_reconstruction/evidence/x86-in_pcb.md`, `.diff`); SDK `netinet/in_var.h` 07 nextdev 채택.

## 168. S5-P141 세부 계획 — `netinet/raw_ip.c` (D024, MULTICAST 1.0 형태, 코딩 전, 2026-10-03)

사실(원본 [0x128240, 0x1284c0) objects.tsv seq 83; 진단 13 NM 객체 크기 rip_input 68/68, rip_output 308/252, rip_ctloutput 264/183; 원본 역어셈블):
1. `rip_output`(0x128284):
   - 헤더를 만드는 조건이 `proto != IPPROTO_RAW && proto != IPPROTO_IGMP`(`cmp 0xff`, `cmp 2`; SDK in.h :48 IGMP 2).
   - 만드는 경로: 길이 합, m_get(MT_HEADER), m_off 0x68·m_len 0x14·m_next, ip_tos 0, ip_off 0, **`ip_p = proto`**(NeXTMach `proto ? proto : IPPROTO_RAW` 아님), ip_len, RAW_LADDR(`rcb_flags & 1`) 이면 family≠AF_INET → EAFNOSUPPORT(0x2f), 아니면 src = rcb_laddr 의 sin_addr, 없으면 src 0; dst = rcb_faddr 의 sin_addr; 마지막에 `ip_ttl = MAXTTL`(0xff).
   - 사용자 헤더 경로(RAW·IGMP): `ip = mtod(m)`; `ip->ip_src.s_addr` 가 0 이 아니면 `INADDR_TO_IFP(ip->ip_src, ifp)`(SDK in_var.h :66) 후 ifp 없으면 EADDRNOTAVAIL(0x31); dst = rcb_faddr.
   - `ip_output(m, rp->rcb_options, &rp->rcb_route, (so->so_options & SO_DONTROUTE) | IP_ALLOWBROADCAST | IP_MULTICASTOPTS, rp->rcb_moptions)`(0x22 = SO_BROADCAST 0x20 | IP_MULTICASTOPTS 0x2, ip_var.h :117–:121; rcb_moptions +0x50).
   - NeXTMach :68–:117 은 RAW_LADDR·dst 를 두 경로 공통으로 처리하고 4 인자 ip_output.
2. `rip_ctloutput`(0x1283b8): SETOPT 에서 IP_OPTIONS → `return ip_pcbopts(&rp->rcb_options, *m)`; IP_MULTICAST_IF..IP_DROP_MEMBERSHIP(3..7, in.h :202–:206) → `error = ip_setmoptions(optname, &rp->rcb_moptions, *m)`; 그 밖 → `error = ip_mrouter_cmd(optname, so, *m)`. GETOPT 에서 IP_OPTIONS 는 NeXTMach 그대로, 3..7 → `error = ip_getmoptions(optname, rp->rcb_moptions, m)`, 그 밖 EINVAL. 끝의 SETOPT m_free 는 그대로. `level != IPPROTO_IP` 검사(0x10(%ebp) ≠ 0 → EINVAL) 그대로.
방법: NeXTMach 바탕, 1·2 를 `#ifdef MULTICAST` 형태로 작성(표시). 구조 기준은 원본 바이트(MULTICAST 1.0 패치 원문은 참고 자료에 없음; Darwin 4.4 raw_ip.c 는 다른 형태).

168 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 헤더 경로 저장 순서 ip_p(0x1282fe)→ip_len→src→dst(0x128333)→ttl(0x128339), RAW·IGMP 제외 0x128299–0x1282a7 | 내 역어셈블(168 사실 1) | ✅ |
| 사용자 헤더 경로 src 검사(in_ifaddr 순회) 후 dst(0x128378) | 내 역어셈블 0x128340–0x12837b | ✅ |
| ip_output 5 인자, flags \| 0x22 | 내 역어셈블 0x12837e–0x12839a, ip_var.h :117–:121 | ✅ |
| rawcb 오프셋 | 계획 150 의 내 Python 계산 | ✅ |
| rip_ctloutput 분기·호출 인자 | 내 역어셈블(호출 이름 해석 포함) | ✅ |
| `#import <netinet/in_var.h>` 필요 | INADDR_TO_IFP 는 SDK in_var.h :66 | ✅ |

### 168.1 it1 결과와 변형(코딩 전)

- it1(`s5p141-it1`): rip_input·rip_ctloutput 크기 일치, rip_output 336/308(빌드가 `proto` 지역을 메모리에 두고 `ip` 를 스택으로 밀어냄; 원본은 `rp->rcb_proto.sp_protocol` 을 다시 읽음).
- 스테이징 사본 변형(07 미반영): v1 `proto` 지역 제거·`rp->rcb_proto.sp_protocol` 직접 사용 → 크기 일치, 33 B 차이; v2 `ifp` 를 블록 안으로 → 변화 없음; v3 v1 + `int len = 0` 함수 범위 → 11 B; v4 v1 + `len` 을 `rp` 앞에 → 3 B(인자 m 레지스터 edi/edx); v5 v4 + 인자 `register` 제거, v6 `m0` 함수 범위, v7 `register m0` → 모두 3 B; **v8 v4 + 인자를 `m0`, 작업 변수 `register struct mbuf *m`(길이 루프 `for (m = m0; …)`, 사용자 헤더 경로 `m = m0`) → OBJECT_MATCH 3/3**.
- 근거: 원본은 인자를 edi 에 두고 작업 `m` 을 edx 로 따로 움직임(0x12828a, 0x1282ad, 0x128340). 수정: 07 raw_ip.c 를 v8 과 같게(작성 표시).
168.1 codex 판정: diff 내용 ✅(내 diff 출력과 같음), v8 L1 OBJECT_MATCH ✅. **결함 지적 채택**: v8 의 `#else MULTICAST` 분기에서 IPPROTO_RAW 경로가 `m = m0` 없이 `mtod(m)` → m 미초기화(최종 빌드는 -DMULTICAST 라 바이트 비교에 안 나타남) — 내 원문 확인 후 07 에서 `} else { m = m0; ip = mtod(m, …); }` 로 고침. 레지스터 관찰은 "인자는 edi, 0x1282ad·0x128340 에서 edx 로 복사, 헤더 경로에서는 그 뒤 edi 를 ip 로 재사용" 으로 정정(⚖️).
168 결과: it2(`s5p141-it2`) OBJECT_MATCH 3/3(639 B); MULTICAST 없는 진단 컴파일 `s5p141-nomc` 종료 0·진단 없음. 등급 A 로 기록(`06_reconstruction/evidence/x86-raw_ip.md`, `.diff`).

## 169. S5-P142 세부 계획 — `netinet/udp_usrreq.c` (D024, 4.3-Reno + MULTICAST 1.0 형태, 코딩 전, 2026-10-03)

사실(원본 [0x12b2a4, 0x12bc2c) objects.tsv seq 90; 진단 13 NM 객체 크기 udp_init 28/28, udp_input 892/552, udp_notify 40/40, udp_ctlinput 108/124, udp_output 380/368, udp_usrreq 992/972; 원본 역어셈블):
1. `udp_input(m0, ifp)`(0x12b2c0): NeXTMach 흐름(pullup·ip_stripoptions·길이·`ip = *ui` 저장·udpcksum 검사) 뒤, `IN_MULTICAST(ntohl(ui_dst)) || in_broadcast(ui_dst)` 이면 udp_in(0x1dbef4) 에 sport·src 를 넣고 m_len −= 0x1c·m_off += 0x1c, `udb`(0x1eaae0) 를 순회하며 lport==dport, (laddr 가 있으면) laddr==dst, (faddr 가 있으면) faddr==src·fport==sport 인 소켓마다 이전 `last` 에 `m_copy(m, 0, M_COPYALL=1000000000)` 사본을 sbappendaddr(실패 시 m_freem, 성공 시 sorwakeup), `last = inp->inp_socket`, `last->so_options & SO_REUSEADDR`(socket +2 의 0x4) 가 없으면 중단; 끝에 last 가 없으면 bad, 있으면 m 을 sbappendaddr·sorwakeup 후 return(0x12b3bc–0x12b4fe). 소켓 없음 경로는 NeXTMach 의 브로드캐스트 검사 뒤 `*(struct ip *)ui = ip`(0x12b5b0 저장본 복원) 후 `icmp_error((struct ip *)ui, ICMP_UNREACH, ICMP_UNREACH_PORT, ifp, (struct in_addr)0?)` 5 인자(마지막 push 0; MULTICAST 1.0 icmp_error 형). 끝의 일반 경로는 NeXTMach 와 같음.
2. `udp_ctlinput(cmd, sa, ip)`(0x12b664): `cmd != PRC_ROUTEDEAD(1)` 이고 (`cmd > PRC_NCMDS` 또는 `inetctlerrmap[cmd] == 0`) 이면 반환; ip 가 있으면 uh = ip + ip_hl<<2, `in_pcbnotify(&udb, sa, uh->uh_dport, ip->ip_src, uh->uh_sport, cmd, udp_notify)`, 없으면 `(…, 0, zeroin_addr, 0, cmd, udp_notify)` — tcp_ctlinput(계획 165) 와 같은 Reno 꼴(quench 없음, ROUTEDEAD 예외는 원본 고유).
3. `udp_output`: 끝의 `ip_output(m, inp->inp_options, &inp->inp_route, (so_options & (SO_DONTROUTE|SO_BROADCAST)) | IP_MULTICASTOPTS, inp->inp_moptions)`(0x12b817–0x12b83a; `or al,2; and eax,0x32` 는 상수 결합). NeXTMach :307–:308 은 4 인자.
4. `udp_usrreq`: `s = splnet()` 를 PRU_CONTROL 처리 뒤, rights·inp 검사 **앞**으로(원본 splnet 호출 뒤 검사; NeXTMach 는 검사 실패 시 초기화 안 된 s 로 splx). 그 밖 차이는 빌드로 판정.
방법: NeXTMach 바탕 + 1–4 작성(표시, MULTICAST 부분은 `#ifdef MULTICAST`). 빌드 반복·L1·기록. icmp_error 5 번째 인자 형은 ip_icmp.c 복원 전이라 선언 없이 0 을 넘김.

169 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| udp_input 다중 전달 루프·조건 순서·마지막 전달, 헤더 저장(0x12b353)·복원(0x12b5b0) | 내 역어셈블(169 사실 1) | ✅ |
| icmp_error 5 번째 인자는 **포인터**(NULL) — 호출되는 쪽 0x125665 에서 역참조 | 역어셈블 0x125665 `mov 0x18(%ebp),%edi; mov (%edi),%edi` — NeXTMach :55 `struct in_addr dest`(값) 과 다름 | ✅ — 169 사실 1 의 "(struct in_addr)0?" 를 `(struct in_addr *)0` 으로 정정; ip_icmp(계획 170) 의 형도 포인터 |
| udp_ctlinput 조건·7 인자 | 내 역어셈블 0x12b664–0x12b6cc | ✅ |
| udp_output 5 인자 | 내 역어셈블 0x12b817–0x12b83a | ✅ |
| udp_output 에 `splimp()`/`splx` 를 MGET 주위에 **추가** 해야 함 | SDK mbuf.h :171–:179 `MGET` 매크로 안에 `int ms = splimp();` 가 이미 있음; 진단 13 NM 빌드도 앞부분 일치 | ❌ 기각(매크로 전개를 소스 차이로 오인) |
| udp_usrreq splnet 이 PRU_CONTROL 뒤·검사 앞, PRU_SEND 는 udp_output 인라인 | 내 호출 목록(0x12b875 in_control, 0x12b883 splnet …) | ✅ |
| icmp_error·in_broadcast 원형 없음 | 기존 계획 154 교훈대로 원형 추가 안 함 | ✅ |
169 결과: 첫 빌드(`s5p142-it1`) OBJECT_MATCH 6/6(2440 B); MULTICAST 없는 진단 컴파일 `s5p142-nomc` 종료 0·진단 없음. 등급 A 로 기록(`06_reconstruction/evidence/x86-udp_usrreq.md`, `.diff`).

## 170. S5-P143 세부 계획 — `netinet/ip_icmp.c` (D024, Reno + MULTICAST 1.0 + NeXT 형태, 코딩 전, 2026-10-03)

사실(원본 [0x125554, 0x125f54) objects.tsv seq 80; 진단 13 NM 크기 icmp_error 472/416, icmp_input 1188/1160, icmp_reflect·ifptoia·icmp_send·iptime 같음, 원본 `icmp_sendMaskPacket` 484 B ↔ NeXTMach `icmp_maskrequest`; 원본 역어셈블):
1. `icmp_error(oip, type, code, ifp, dest)`: (a) 다섯째 인자가 **포인터** — redirect 때 `icp->icmp_gwaddr = *dest`(0x125665–0x12566a 역참조; NeXTMach :55 `struct in_addr dest` 값); (b) m_get 앞(0x1255c4–0x1255e9)에 `if (IN_MULTICAST(ntohl(oip->ip_dst.s_addr)) || in_broadcast(oip->ip_dst)) goto free;`(MULTICAST 1.0). 원본 호출자: ip_dooptions·ip_forward·udp_input(계획 169 에서 NULL 전달).
2. `icmp_input`: protocol ctlinput 호출이 3 인자 `(*ctlfunc)(code, (struct sockaddr *)&icmpsrc, &icp->icmp_ip)`(0x1258f8–0x125902; NeXTMach :231 은 2 인자). pfctlinput 호출은 2 인자 그대로(0x125a96–0x125a9d). 그 밖 차이는 빌드로.
3. `icmp_sendMaskPacket(ifp, type, delay)`(0x125d70, 484 B; NeXTMach :479 `icmp_maskrequest(ifp)` 를 대신): `u_char type`(0xc(%ebp) 바이트), `int delay`. 순서: IFF_UP 아니거나 IFF_LOOPBACK 이면 0 반환 → `ifa = ifptoia(ifp)`(인라인 순회) 없으면 ENETUNREACH(0x33) → `m_get(M_WAIT, MT_HEADER)` 없으면 ENOBUFS → m_len 0x20·m_off 0x5c·bzero → m_len −0x14·m_off +0x14 → `type == ICMP_MASKREPLY(18)` 이면 icmp_type 18, `icmp_mask = htonl(ifa->ia_subnetmask)`(+0x34), 0 이면 EINVAL; 아니면 icmp_type ICMP_MASKREQ(17) → code·cksum·void 0, `icmp_cksum = in_cksum(m, 12)` → m_off −0x14·m_len +0x14 → ip_v/ip_hl(0x45), **`ip_id = htons(ip_id++)`**(NeXTMach 는 htons 없음), ttl MAXTTL, p ICMP, src = ia_addr, dst = INADDR_BROADCAST, `ip_len = htons(0x20)`, ip_sum 0 후 in_cksum(m, 20) → lsin(AF_INET, 0, BROADCAST) → `delay > 0` 이면 `timeout(wakeup, &ifa->ia_subnetmask, delay * hz); sleep(&ifa->ia_subnetmask, PZERO)` → `error = if_output_mbuf(ifp, m, &lsin); m = NULL` → `type == ICMP_MASKREQ` 이면 1×hz 기다림 → errout: m 이 있으면 m_freem, error 반환. 원본 호출자는 in_control(in.c) 두 곳.
방법: NeXTMach 바탕 + 1–3 작성(표시). icmp_maskrequest 는 원본에 없으므로 icmp_sendMaskPacket 으로 대체. 빌드 반복·L1·기록.

170 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| icmp_error 5 번째 인자 역참조, MULTICAST·broadcast 거부 | 내 역어셈블 0x125665, 0x1255c4–0x1255e9 | ✅ |
| icmp_sendMaskPacket 호출자 2 곳 | 내 call 스캔 0x123a41·0x123a84 | ✅ |
| sendMaskPacket 은 _ifptoia 호출 없이 in_ifaddr 순회(IFP_TO_IA, in_var.h :81) | 역어셈블 0x125da0–0x125db8(호출 없음); ifptoia 는 같은 파일 앞에서 정의돼 -O3 인라인도 같은 꼴 | ✅ 사실 / 식 꼴은 빌드로 |
| 오프셋 ia_subnetmask 0x34, ia_addr sin_addr +4, icmp_mask +8, `htons(ip_id++)`, 순서 | 내 역어셈블·Python 배치 | ✅ |
| **icmp_input 추가 차이**: MASKREQ 에 `ia_flags & IFA_NETMASK_AUTH`(0x1259af); MASKREPLY 에 `IFA_AWAITING_MASK`·mask≠0xffffffff·`(ntohl(mask) & 0xff000000) == 0xff000000`(0x125af6–0x125b16), 그 뒤 `ia_flags &= ~IFA_AWAITING_MASK`, loopback·`(ia_subnetmask \| ntohl(icmp_mask)) != ia_subnetmask`(NeXTMach 의 dst==ia_addr 검사 없음) | 역어셈블 0x125990–0x1259bf, 0x125ae0–0x125b3d; in_var.h :51–:53; 실패 시 0x125b8a = raw: | ✅ — 내 계획 170 에서 빠졌던 것(icmp_input 은 "빌드로" 로 미뤘음) |

### 170.1 수정 계획 보충

- icmp_input MASKREQ: `if (icmplen < ICMP_MASKLEN || (ia = ifptoia(ifp)) == 0 || (ia->ia_flags & IFA_NETMASK_AUTH) == 0) break;`
- icmp_input MASKREPLY: `if ((ia = ifptoia(ifp)) && (ia->ia_flags & IFA_AWAITING_MASK) && ntohl(icp->icmp_mask) != 0xffffffff && (ntohl(icp->icmp_mask) & 0xff000000) == 0xff000000) { ia->ia_flags &= ~IFA_AWAITING_MASK; if (!(ifp->if_flags & IFF_LOOPBACK) && (ia->ia_subnetmask | ntohl(icp->icmp_mask)) != ia->ia_subnetmask) { …NeXTMach 본문… } }`(묶음 꼴은 빌드로 조정).

### 170.2 it1 결과와 수정(코딩 전)

- it1(`s5p143-it1`): icmp_error·icmp_sendMaskPacket 등 6 함수 크기 일치, icmp_input 1204/1188(프레임 +4). 차이: MASKREPLY 의 성공 printf 에서 원본은 셋째 인자로 `ia->ia_subnetmask`(+0x34, 0x125b65 `mov 0x34(%ebx),%ecx`) 를, NeXTMach :337 은 `icp->icmp_mask` 를 넘김.
- 수정: 그 printf 인자를 `ia->ia_subnetmask` 로(작성 표시). 빌드로 프레임 차이까지 판정.
170.2 codex 판정: %x 인자 = ia->ia_subnetmask(0x125b65/0x125b68), 형식 문자열 일치 — 내 역어셈블과 같음 ✅.

### 170.3 it2·변형 결과와 수정(코딩 전)

- it2(`s5p143-it2`, printf 수정): icmp_input 여전히 1204/1188 — 빌드는 MASKREPLY 앞쪽 조건에서 ntohl 을 두 번 계산하고 ia_flags 를 스택([ebp-0xc])에 보관; 원본(0x125b02–0x125b16)은 ntohl 한 번(eax)을 −1·0xff000000 비교에 함께 씀.
- 스테이징 변형 v1(`s5p143-v1`): 앞쪽 조건을 `(mask = ntohl(icp->icmp_mask)) != 0xffffffff && (mask & 0xff000000) == 0xff000000`(지역 `u_long mask`) → icmp_input MATCH, 객체 크기 일치; 남은 차이는 `icmp_send` 의 ip_output 이 원본에서 5 인자(0x125cfe–0x125d09, push 0 하나 더; NeXTMach :458 은 4 인자 — 처음 적은 0x1257aa·:455 는 객체 오프셋을 주소로 잘못 옮긴 오기, codex 지적).
- 수정: 07 에 v1 꼴과 icmp_send 의 다섯째 인자 `(struct ip_moptions *)0`(`#ifdef MULTICAST`) 반영(작성 표시).
170.3 codex 판정: icmp_send 5 push(0x125cfe–0x125d09, Python 0x125554+0x7aa = 0x125cfe) ✅, MASKREPLY ntohl 한 번 ✅, v1 차이는 mask 임시 변수뿐 ✅(내 diff). 계획 오기 2 곳 정정.
170 결과: it3(`s5p143-it3`) OBJECT_MATCH 7/7(2560 B); MULTICAST 없는 진단 컴파일 `s5p143-nomc` 종료 0·진단 없음. 등급 A 로 기록(`06_reconstruction/evidence/x86-ip_icmp.md`, `.diff`).

## 171. S5-P144 세부 계획 — `netinet/in.c` (D024, MULTICAST 1.0 + NeXT 형태, 코딩 전, 2026-10-03)

사실(원본 [0x123440, 0x124154) objects.tsv seq 77; 진단 13 NM 크기 in_netof 136/112, in_lnaof 164/136, in_control 1020/912, in_ifinit 628/608, inet_ntoa 200/160, inet_queue 308/307(끝 패딩), 원본에만 in_addmulti 276·in_delmulti 128; 나머지 같음; 원본 역어셈블):
1. `in_netof`/`in_lnaof`: 클래스 C 다음 `else if (IN_CLASSD(i)) { net = i & IN_CLASSD_NET; [host = i & IN_CLASSD_HOST;] }`(원본 상수 0xe0000000, `and 0xfffffff`), 그 밖 `return (0)`/`return (i)`(in_lnaof 의 else 는 NeXTMach 그대로).
2. `inet_ntoa`(0x123dc4): 100 이상일 때 백의 자리 뒤 `if ((*p % 100) / 10 == 0) *b++ = '0';`(0x123dfc–0x123e22) — NeXTMach 의 0 누락 수정.
3. `in_control`: SIOCSIFNETMASK(0x123a24) = `ia->ia_flags &= ~(IFA_NETMASK_AUTH|IFA_AWAITING_MASK); ia->ia_subnetmask = ntohl(…); if (ia->ia_subnetmask) { ia->ia_flags |= IFA_NETMASK_AUTH; icmp_sendMaskPacket(ifp, ICMP_MASKREPLY, 0); } break;`; SIOCAUTONETMASK(0x123a4c) = `ia->ia_flags &= ~IFA_NETMASK_AUTH; if ((ifp->if_flags & IFF_UP) == 0) return (ENETDOWN); ia->ia_flags |= IFA_AWAITING_MASK; for (i = 0; i <= 4; i++) { error = icmp_sendMaskPacket(ifp, ICMP_MASKREQ, i > 5 ? 32 : (1 << i) >> 1); if (error) return (error); if ((ia->ia_flags & IFA_AWAITING_MASK) == 0) return (0); } return (ENETDOWN);`(0x32 = ENETDOWN). ioctl 이름 집합은 NeXTMach 와 같음(Python 으로 SDK ioctl.h 와 대조).
4. `in_ifinit`: 끝의 `ia->ia_flags |= IFA_ROUTE;` 뒤 `addr.s_addr = htonl(INADDR_ALLHOSTS_GROUP); in_addmulti(addr, ifp);`(0x123d23–0x123d33; 주소를 **값**으로, IFF_MULTICAST 검사 없음; in.h :172).
5. `in_addmulti(addr, ifp)`(0x123fc0)·`in_delmulti(inm)`(0x1240d4): MULTICAST 1.0 꼴 — 아래 메모의 순서(IN_LOOKUP_MULTI(in_var.h :121) → 참조 수 증가, 아니면 m_getclr(M_DONTWAIT, MT_IPMADDR) 로 in_multi(in_var.h :98) 만들고 ia_multiaddrs 에 연결, ifr(sin AF_INET) 로 `if_control` 있으면 `if_ioctl(ifp, SIOCADDMULTI, &ifr)`, 실패 시 해제·NULL, 성공 시 igmp_joingroup; 해제는 --refcount==0 이면 igmp_leavegroup, 목록에서 제거, if_ioctl(SIOCDELMULTI), m_free(dtom(inm))). splnet/splx 로 감쌈.
메모(scratchpad plan171_facts.md 그대로):
# plan 171 (in.c) facts gathered so far (scratch; not yet in the plan document)
- objects.tsv seq 77 [0x123440, 0x124154); NM sizes: in_netof 136/112, in_lnaof 164/136, in_control 1020/912, in_ifinit 628/608, inet_ntoa 200/160, inet_queue 308/307, original-only in_addmulti 276, in_delmulti 128.
- in_netof/in_lnaof: class C then class D (multicast) branch (shape diff), else 0.
- inet_ntoa (0x123dc4): in the `*p > 99` branch after emitting the hundreds digit, `if ((*p % 100) / 10 == 0) *b++ = '0';` (0x123dfc-0x123e22), then `*p %= 100`. NeXTMach drops the zero.
- in_control calls icmp_sendMaskPacket(ifp, ICMP_MASKREPLY, 0) at 0x123a41 (after `ia_flags |= 2`?, 0x3c(%ebx) orb 2) and icmp_sendMaskPacket(ifp, ICMP_MASKREQ, delay-or-0x20) at 0x123a84.
- in_addmulti(addr, ifp) 0x123fc0 (276 B): splnet; IN_LOOKUP_MULTI(addr, ifp, inm) inline (ia by ifp, then ia_multiaddrs +0x44 list by inm_addr, next +0x14); found -> ++inm_refcount (+0xc); else ia by ifp, m_getclr(M_DONTWAIT, MT_IPMADDR=0xf); fail -> splx, return 0; inm = mtod; inm_addr = *addr; inm_ifp = ifp; inm_refcount = 1; inm_ia = ia (+8); link at ia->ia_multiaddrs; ifr (local -0x20, sin family 2 at -0x10, addr at -0xc); if ifp->if_control (+0x38) == 0 or if_ioctl(ifp, SIOCADDMULTI, &ifr) != 0 -> unlink, m_free, inm = 0; else igmp_joingroup(inm); splx; return inm.
- in_delmulti(inm) 0x1240d4 (128 B): splnet; if (--inm_refcount == 0) { igmp_leavegroup(inm); unlink from inm_ia->ia_multiaddrs (pointer-to-pointer walk); ifr sin AF_INET addr; if_ioctl(inm_ifp, SIOCDELMULTI, &ifr); m_free(dtom(inm)); } splx.
- in_control (0x1236xx, 1020 B): compare sets 0x80206913, 0x8020690c, 0x8020690e, 0x80206922, 0x80206916, 0xc0206921 (first switch) and 0x80206922, 0x8020690e, 0x8020690c, 0x80206913, 0x80206916, 0xc020690f, 0xc020690d, 0xc0206912, 0xc0206915 (second); calls suser, panic(0x1dba9c), m_getclr, if_ioctl(SIOCSIFDSTADDR 0x8020690e), rtinit(0x8030720b/0x8030720a), in_ifinit, icmp_sendMaskPacket(REPLY,0) at 0x123a41 and (REQ, delay) at 0x123a84, if_ioctl at 0x123ac2. Needs SDK ioctl.h names and NeXTMach case mapping.
- in_control ioctl numbers decoded with Python against SDK sys/ioctl.h: same name set as NeXTMach (SIOCSIFBRDADDR 19, SIOCSIFADDR 12, SIOCSIFDSTADDR 14, SIOCAUTONETMASK 34, SIOCSIFNETMASK 22, SIOCAUTOADDR 33, SIOCGIFDSTADDR 15, SIOCGIFADDR 13, SIOCGIFBRDADDR 18, SIOCGIFNETMASK 21) -> differences are inside SIOCSIFNETMASK (mask reply) and SIOCAUTONETMASK (delay).

방법: NeXTMach 바탕 + 1–5 작성(표시, MULTICAST 는 `#ifdef MULTICAST`). 빌드 반복·L1·기록. igmp_joingroup/leavegroup 원형 없음 → 암묵 선언.

171 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1–5 모두 원본과 일치(주소 범위) | 내 역어셈블(171 사실) | ✅ |
| in_addmulti 의 addr 는 **값** — `inm_addr = addr`(메모의 `*addr` 정정) | 역어셈블 0x124059 `mov 0x8(%ebp),%edx; mov %edx,(%ebx)` | ✅ 메모 오기 정정 |
| 지연값 0,1,2,4,8; `i > 5` 분기는 도달 불가 | Python [(32 if i>5 else (1<<i)>>1) for i in 0..4] = [0,1,2,4,8] | ✅ |
| 추가는 if_control(+0x38) 검사 후 if_ioctl, 삭제는 검사 없이 if_ioctl | 역어셈블 0x124086–0x124096, 0x124124–0x124131 | ✅ |
| in_multi·ia_multiaddrs·ifreq 오프셋 | 내 Python 배치 | ✅ |
| in_delmulti 반환형·#ifdef 위치는 바이트로 미정 | — | ⏭️(NeXT 관례대로 암묵 int) |

### 171.1 it 결과

- it1: `ICMP_MASKREQ` 미정의 → `<netinet/in_systm.h>`·`<netinet/ip.h>`·`<netinet/ip_icmp.h>` import. it2(`s5p144-it2`): 13 MATCH, inet_ntoa MATCH_UNVERIFIED(static buf 의 `__bss`), in_addmulti DIFF — 원본은 `inm_refcount = 1`(+0xc) 을 `inm_ia = ia`(+8) 보다 먼저 저장(0x124064–0x12406b). 수정: 두 대입 순서 교환(codex 제안 C 의 순서를 바이트에 맞춤).
- it3(`s5p144-it3`, 순서 교환): in_addmulti 차이는 `lea eax,[ebp-0x20]`(&ifr) 위치뿐 — 원본은 ifr 필드 저장 전(0x124077), 빌드는 if_control 검사 뒤.
- 스테이징 변형: v1 연결 직후 `ifrp = (caddr_t)&ifr;` 를 받아 if_ioctl 에 넘김 → `__text` 차이 0(14 MATCH + inet_ntoa MATCH_UNVERIFIED), `__bss` 만 추정; v2 `error = …; if (error)` 꼴 → unplaced(실패). v1 을 가설로 채택해 07 에 반영(작성 표시). `__bss`(inet_ntoa 의 static buf) 는 zerofill 검사로 P 판정 예정.
171.1 codex 판정: diff 는 ifrp 뿐, v1 L1 텍스트 차이 0·`__bss` 만 미확인, 0x124077 lea 가 필드 저장·if_control 검사 앞, 의미 차이 없음 — 내 diff·역어셈블로 확인 ✅.
171 결과: it4(`s5p144-it4`, v1 반영) `__text` 3346 B·`__data` 차이 0, 15 함수 MATCH(inet_ntoa 는 `__bss` 참조로 MATCH_UNVERIFIED). `__bss` 20 B(inet_ntoa static buf) 0x1e58f4 참조 추정(원본 inet_ntoa 의 `mov $0x1e58f4` 와 일치) → 등급 **P**, known 배치 `zerofill-known-s5p144-20261002.json`(21 항목).

## 172. S5-P145 세부 계획 — `net/if.c` (D024, Reno + MULTICAST 1.0 + NeXT 형태, 코딩 전, 2026-10-03)

사실(원본 [0x11edac, 0x11f43c) objects.tsv seq 65; 원본 역어셈블; 진단 13 NM 객체):
1. `if_down`(0x11ef04): `ifp->if_flags &= ~(IFF_UP|IFF_RUNNING)`(andb 0xbe; if.h :98·:105 0x1·0x40), 주소마다 `pfctlinput(PRC_IFDOWN, &ifa->ifa_addr)`, 끝에 `if_qflush(&ifp->if_snd)`. NeXTMach :241–:249 는 IFF_UP 만, if_qflush 없음.
2. 원본에만 있는 `if_qflush(ifq)`(0x11ef3c, Reno 꼴): `n = ifq->ifq_head; while (m = n) { n = m->m_act; m_freem(m); } ifq->ifq_head = 0; ifq->ifq_tail = 0; ifq->ifq_len = 0;`(m_act +0x7c, SDK mbuf.h :103).
3. 원본에만 있는 `if_down_all()`(0x11ef78, NeXT): `s = splnet(); for (ifp = ifnet; ifp; ifp = ifp->if_next) if_down(ifp); splx(s);`(if_down 인라인).
4. `ifioctl`: 둘째 switch 에 `SIOCADDMULTI`/`SIOCDELMULTI`(0x80206931/0x80206932) → `if (!suser()) return (u.u_error); return (if_ioctl((netif_t)ifp, cmd, data));` 추가(MULTICAST). SIOCSIFFLAGS 의 if_down 은 1 의 새 꼴로 인라인. 그 밖 case 는 NeXTMach 와 같은 이름 집합(Python 대조, 아래 메모).
메모(scratchpad plan172_facts.md):
# plan 172 (net/if.c, objects.tsv seq 65 [0x11edac, 0x11f43c)) facts
- NM sizes: ifinit 8, ifa_ifwithaddr 120, ifa_ifwithdstaddr 100, ifa_ifwithnet 104, ifb_ifwithaf 12 equal; if_down 56/48; original-only if_qflush 60, if_down_all 92; ifunit 140 equal; ifioctl 684/612; ifconf 280 equal; address_known 24/22 (last, padding).
- if_down 0x11ef04: `ifp->if_flags &= ~(0x41)` (andb 0xbe at +0xc; IFF_UP|IFF_RUNNING?), for (ifa = ifp->if_addrlist(+0x18); ifa; ifa = ifa->ifa_next(+0x24)) pfctlinput(PRC_IFDOWN(0), &ifa->ifa_addr(=ifa)); if_qflush(&ifp->if_snd (+0x1c)).
- if_qflush(ifq) 0x11ef3c: n = ifq->ifq_head; while ((m = n) != 0) { n = m->m_act (+0x7c); m_freem(m); } ifq_head = ifq_tail = 0; ifq_len = 0.
- if_down_all 0x11ef78: s = splnet(); for (ifp = ifnet; ifp; ifp = ifp->if_next(+0x5c)) if_down(ifp) [inlined]; splx(s).
- ifioctl: to analyse (684/612).
- ifioctl (684/612): first switch (SIOCGIFCONF 0xc0086914 -> ifconf, ARP ioctls 0x80246920/0x8024691e/0xc024691f -> suser? + arpioctl), then ifunit-like name scan (bcmp), second switch over 0x8020697d, 0x80206918, 0x80206910 (SIOCSIFFLAGS), 0x80206932 (SIOCDELMULTI), 0x80206931 (SIOCADDMULTI), 0xc0206917, 0x8020697f, 0xc0206911, 0xc020697c, 0xc020697e; SIOCSIFFLAGS path: suser, splimp, if_down inline (pfctlinput, if_qflush), splx, if_ioctl; ADDMULTI/DELMULTI: suser then if_ioctl (MULTICAST); final default `call *%eax` (so_proto->pr_usrreq PRU_CONTROL?). Register/prologue order differs (NM loads cmd into edi first) -> check with build. Names: decode numbers against SDK ioctl.h with Python before writing the plan.
- ifioctl ioctl numbers (Python vs SDK sys/ioctl.h):
  0x80246920 W i 32 size 36 ('SIOCDARP', 'arpreq')
  0x8024691e W i 30 size 36 ('SIOCSARP', 'arpreq')
  0xc0086914 WR i 20 size 8 ('SIOCGIFCONF', 'ifconf')
  0xc024691f WR i 31 size 36 ('SIOCGARP', 'arpreq')
  0x8020697d W i 125 size 32 ('SIOCSIFASYNCMAP', 'ifreq')
  0x80206918 W i 24 size 32 ('SIOCSIFMETRIC', 'ifreq')
  0x80206910 W i 16 size 32 ('SIOCSIFFLAGS', 'ifreq')
  0x80206932 W i 50 size 32 ('SIOCDELMULTI', 'ifreq')
  0x80206931 W i 49 size 32 ('SIOCADDMULTI', 'ifreq')
  0xc0206917 WR i 23 size 32 ('SIOCGIFMETRIC', 'ifreq')
  0x8020697f W i 127 size 32 ('SIOCSIFMTU', 'ifreq')
  0xc0206911 WR i 17 size 32 ('SIOCGIFFLAGS', 'ifreq')
  0xc020697c WR i 124 size 32 ('SIOCGIFASYNCMAP', 'ifreq')
  0xc020697e WR i 126 size 32 ('SIOCGIFMTU', 'ifreq')
- NeXTMach if.c :241 if_down clears only IFF_UP and has no if_qflush; original clears 0x41 and calls if_qflush(&ifp->if_snd) (Reno form). ifioctl in NeXTMach already has SIOCSIFMTU/GIFMTU/ASYNCMAP and default PRU_CONTROL; original adds SIOCADDMULTI/SIOCDELMULTI (suser then if_ioctl) under MULTICAST.

방법: NeXTMach 바탕 + 1–4 작성(표시). 함수 순서는 원본 심볼 순서(if_down, if_qflush, if_down_all, ifunit, ifioctl, ifconf, address_known). 빌드 반복·L1·기록.
172 보충(내 역어셈블 0x11f2b0–0x11f2d5): ADD/DELMULTI 본문은 `if (!suser()) return (u.u_error); if (ifp->if_control == 0) return (EOPNOTSUPP); return (if_ioctl((netif_t)ifp, cmd, data));` — 172 사실 4 에 if_control 검사가 빠져 있었음(정정). SIOCSIFFLAGS(0x11f204–0x11f284) 는 새 if_down 인라인 외 NeXTMach 와 같음(IFF_CANTCHANGE 마스크 0xc852/0x37ad).

172 codex 검토 판정(코딩 전; 첫 작업 통지가 늦어 범위를 줄인 재질의도 실행, 두 회신 모두 판정):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| if_down 0x41 해제·pfctlinput·if_qflush(&if_snd) | 내 역어셈블 0x11ef04–0x11ef3b | ✅ |
| if_qflush m_act(+0x7c) 를 m_freem 전에 읽고 head/tail/len 0 | 내 역어셈블 0x11ef3c–0x11ef76 | ✅ |
| if_down_all splnet·ifnet 순회(if_next +0x5c)·if_down 인라인·splx | 내 역어셈블 0x11ef78–0x11efd0 | ✅ |
| MULTI case: suser → if_control 검사(EOPNOTSUPP, 반환 명령은 0x11f2e2) → if_ioctl | 내 역어셈블 0x11f2b0–0x11f2e7 | ✅(범위 정정 수용) |
| SIOCSIFFLAGS 는 새 if_down 인라인 외 같음, 그 밖 case 차이 없음 | 내 역어셈블 0x11f204–0x11f284 | ✅ |
172.1 it1(`s5p145-it1`): 11 MATCH, ifioctl DIFF — 원본은 MTU·ASYNCMAP 본문(0x11f29c)이 MULTI 본문(0x11f2b0)보다 앞; MULTI case 를 MTU 그룹 뒤(default 앞)로 옮김(바이트로 정해진 순서).
172 결과: it2(`s5p145-it2`) OBJECT_MATCH 12/12(1678 B); MULTICAST 없는 진단 컴파일 `s5p145-nomc` 종료 0. 등급 A 로 기록(`06_reconstruction/evidence/x86-if.md`, `.diff`).

## 173. S5-P146 세부 계획 — `netinet/if_ether.c` (D024, NeXTMach + MULTICAST 1.0 + NeXT 정렬 복사 형태, 코딩 전, 2026-10-03)

사실(원본 [0x1220b4, 0x123440) objects.tsv seq 76; 원본 역어셈블; 진단 13 NM 객체 `s5p124l1/out/NM__if_ether_76.o`):
0. 함수 크기(원본/NM): arptimer 128/128, arpwhohas 284/280, arpresolve 1148/1020, arpinput 152/140, in_arpinput 1156/1100, arptfree 68/68, arptnew 240/240, arpioctl 1044/1044, revarpinput 592/592, localetheraddr 116/116, ether_sprintf 76/76. shapediff 로 arptimer·arptnew·revarpinput·localetheraddr·ether_sprintf 는 재배치 값 말고 차이 없음.
1. `arpwhohas`(0x122134): `*((u_short *)&sa.sa_data[2*eat->arp_hln]) = sa.sa_family;` 자리에 `bcopy(&sa.sa_family, &sa.sa_data[2*hln], 2)`(0x122165–0x122177: push 2, dst esi+hln*2+2, src esi=&sa). 끝의 `if_output_mbuf(ifp, m, &sa)` 는 같은 esi(&sa) 재사용. arpresolve 안의 인라인 두 곳(0x12244b, 0x1225cc)도 같은 꼴.
2. `arpresolve`(0x122250): `*usetrailers = 0;` 다음에 MULTICAST 분기 — `IN_MULTICAST(ntohl(destip->s_addr))`(bswap, and 0xf0000000, cmp 0xe0000000) 이면 `ETHER_MAP_IP_MULTICAST(destip, desten); return (1);`(desten[0..2]=01 00 5e, [3]=((u_char *)destip)[1]&0x7f, [4],[5]; SDK `net/etherdefs.h:88`). 그 밖은 NeXTMach 와 같음(`sizeof(my_enaddr)`=4 그대로, 0x122334 push 4).
3. `arpinput`(0x1226cc): 8 바이트 지역 `struct arphdr` 에 `bcopy(mtod(m, caddr_t), &arh, sizeof arh)`(0x1226e8–0x1226f4) 하고 그 복사본에서 ar_pro(→esi)·ar_hrd 를 읽음. 프레임 8.
4. `in_arpinput`(0x122764): 첫머리 `mcopy = 0` 다음 28 바이트 지역 `struct ether_arp` 에 `bcopy(mtod(m), &eab, 0x1c)` 하고 `ea = &eab`(edi). isaddr·itaddr 는 `bcopy(&ea->arp_sha[hln], &isaddr, 4)`·`bcopy(&ea->arp_sha[2*hln+pln], &itaddr, 4)`(0x1227c1–0x1227f3). 중복 주소 경로의 `op == ARPOP_REQUEST` 에서 `at = 0` 뒤 reply 로(0x12287b xor esi). 대리 ARP(else) 가지의 둘째 bcopy 원천이 `at->at_enaddr`(0x122a98 lea esi+4; NeXTMach 는 my_enaddr). sa 의 형 기록은 1 과 같은 2 바이트 bcopy(0x122b0c). `eat == &arpethertempl` 비교는 남고 else(3Mb 교환 루프) 본문 없음(0x122b60–0x122b79). 그 뒤 `bcopy(ea, mtod(m), 0x1c)` 로 되돌려 쓰고 sa_family=0, if_output_mbuf. mcopy 쪽은 지역 ea 의 arp_pro 를 htons(ETHERTYPE_IPTRAILERS) 로 바꾸고 `bcopy(ea, mtod(mcopy), 0x1c)` 뒤 출력(0x122ba8–0x122bcd). hln/pln 의 16 비트 비교(0x1227b1)는 NM 빌드도 같은 꼴(GCC 가 합침).
5. `arpioctl`(0x122d1c): 첫머리 `xor ebx,ebx`(ifa=0, ebx 가 ifa), cmd 는 메모리([ebp+8]) 유지. NM 은 ebx=cmd, ifa 는 스택 → `struct ifaddr *ifa = 0;` 가설.
6. 데이터: `etherbroadcastaddr`(0x1db980) 바로 뒤 `ether_ipmulticast_min`(0x1db986, 01 00 5e 00 00 00)·`ether_ipmulticast_max`(0x1db98c, 01 00 5e 7f ff ff), 그 뒤 `useloopback`(0x1db994). NeXTMach 에 정의 없음(Darwin 0.1 `bsd/net/if_ethersubr.c:737–738` 에 같은 값 — 비교용, 글은 원본 바이트로 작성). SDK 헤더에는 extern 없음.

방법: NeXTMach `netinet/if_ether.c` 바탕 + 1–6 작성(D024 표시, MULTICAST 분기는 `#ifdef MULTICAST`). 정렬용 복사는 주석으로 근거(원본 주소) 표시. in_arpinput 의 지역 순서는 원본 프레임(eab -0x1c, sin -0x2c, sa -0x3c, isaddr -0x40, itaddr -0x44)에 맞춰 eab 를 sin 앞에 선언. 3Mb else 는 `#if NEN > 0` 으로 감쌈. 빌드 `iter.py s5p146-itN bsd/netinet/if_ether.c if_ether 1220b4 123440`, 차이는 스테이징 복사본 변형으로 확인 후 07 반영, nomc 진단 컴파일, 기록(등급은 __bss arptab 이 공통 기호로 맞으면 A).

173 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0 크기·불변 함수(재배치 제외 같음) | fnsizes·shapediff(NM 객체) | ✅ |
| arpwhohas 2 바이트 bcopy 0x122165–0x122177, 출력 호출이 &sa(esi) 재사용 0x12223b–0x122241, 인라인 0x12244b·0x1225cc | 내 역어셈블(odis 0x122230–0x122250, arpres.dis) | ✅ |
| arpresolve MULTICAST 분기 0x122265–0x1222a3, push 4 0x122334 | arpres.dis | ✅ |
| arpinput 8 바이트 지역 복사 0x1226e8–0x1226f4, 복사본에서 ar_pro·ar_hrd | 내 역어셈블 0x1226cc– | ✅ |
| in_arpinput 28 바이트 복사 0x122774–0x122786, xor esi 0x12287b, at_enaddr 0x122a98, 2 바이트 bcopy 0x122b0c, 되돌려 쓰기 0x122b79·0x122bb5, else 본문 없음 | odis 0x122774–0x122788, inarp.dis | ✅ |
| arpioctl xor ebx 0x122d2b, ifa_ifwithnet → ebx 0x122db5, cmd 는 [ebp+8] | arpioctl.dis | ✅(선언 꼴은 가설로 둠) |
| 데이터 배치, useloopback 앞 0x1db992–0x1db993 0 바이트 2 개 | Python 바이트 읽기(pad `00 00`) | ✅(보충: 정렬 패딩, int 정렬로 생김) |
| 놓친 차이 없음 | 전 범위 shapediff 와 내 대조 | ⚖️ — 빌드 L1 로 최종 판정 |
### 173.1 it 결과
- it1(`s5p146-it1`): arpinput·in_arpinput 등 9 함수 크기 일치, arpwhohas 288/284·arpresolve 1108/1148 — 원본은 &sa 를 esi 에 두고 마지막 if_output_mbuf 까지 재사용. 스테이징 변형(`s5p146-v1`): v1 arpwhohas 의 3Mb else 를 `#if NEN > 0` 으로 감쌈 → arpwhohas 차이 0, v2 조건 없이 교환만 → 6 바이트 차이. v1 을 가설로 채택(in_arpinput 과 같은 꼴, 작성 표시 `plan 173.1`).
173 결과: it2(`s5p146-it2`) `__text` 5004 B·`__data` 차이 0, 9 함수 MATCH(localetheraddr·ether_sprintf 는 `__bss` 참조로 MATCH_UNVERIFIED). `__bss` 24 B 는 0x1e58dc 로 참조 추정(`s5p146-zerofill-check-if_ether-20261002.json`, Delta 하나, in.c 의 0x1e58f4 바로 앞) → 등급 **P**, known 배치 `zerofill-known-s5p146-20261002.json`(22 항목, 겹침 0). MULTICAST 없는 진단 컴파일 `s5p146-nomc` 종료 0. 기록 `06_reconstruction/evidence/x86-if_ether.md`·`.diff`, functions.tsv 1165 행, objects_partial 17 행, PROVENANCE 492 행(SDK `netinet/if_ether.h`·`net/etherdefs.h` 채택 2 행 포함).

## 174. S5-P147 세부 계획 — `netinet/tcp_output.c` (D024, 4.3-Reno + MULTICAST 1.0 형태, 코딩 전, 2026-10-03)

사실(원본 [0x129d8c, 0x12a434) objects.tsv seq 86; 원본 역어셈블 0x129d8c–0x12a3bc; 진단 13 NM 객체 `s5p124l1/out/NM__tcp_output_86.o`; 필드는 SDK `netinet/tcp_var.h` struct tcpcb):
0. 크기(원본/NM): tcp_output 1584/1728, tcp_setpersist 120/117(마지막 함수, 패딩 포함).
1. 첫머리(0x129da1–0x129dc4): `idle = (snd_max == snd_una); if (idle && tp->t_idle >= tp->t_rxtcur) tp->snd_cwnd = tp->t_maxseg;`(+0x58 ≥ +0x14 → +0x54 ← +0x18).
2. again 이후 순서(0x129dc8–0x129e79): sendalot, off, win = MIN(snd_wnd, snd_cwnd), t_force 처리, **flags = tcp_outflags[t_state] 를 len 계산보다 먼저**(0x129e10), len = MIN(sb_cc, win) − off, len<0 처리, len>t_maxseg, SEQ_LT 이면 FIN 제거, win = sbspace(&so->so_rcv).
3. 보낼지 판정 순서(0x129ea0–0x129f7b, Reno): if (len) {maxseg; (idle||NODELAY)&&len+off≥sb_cc; t_force; len ≥ max_sndwnd/2; SEQ_LT(snd_nxt, snd_max)} → if (win > 0) { adv = win − (rcv_adv − rcv_nxt); adv ≥ 2*t_maxseg → send; 2*adv ≥ so_rcv.sb_hiwat → send } → TF_ACKNOW → SYN|RST → SEQ_GT(snd_up, snd_una) → FIN 조건(NeXTMach 는 FIN·ACKNOW·SYN·URG 를 len 판정 앞에 둠, 창 갱신 판정은 sb_cc==0 조건과 100*adv/hiwat≥35) → 지속 상태 진입(같음).
4. send(0x129f80–): `optlen = 0; hdrlen = sizeof (struct tcpiphdr);` SYN 이고 TF_NOOPT 아님 → optlen = 4, hdrlen += 4, `*(u_short *)(tcp_initopt + 2) = htons((u_short) tcp_mss(tp, 0))`(인자 2 개, 0x129faa). MGET(MT_HEADER) 인라인은 같음, `m->m_off = MMAXOFF - hdrlen; m->m_len = hdrlen;`(0x12a044–0x12a056).
5. len 이 있을 때: 통계 뒤 m_copy, `if (m->m_next == 0) len = 0; else if (off + len == so->so_snd.sb_cc) flags |= TH_PUSH;`(0x12a0b5 의 jmp 가 PUSH 검사를 건너뜀). 뒤쪽 PUSH 검사 없음.
6. 템플릿 복사·FIN 재전송 snd_nxt-- 같음. 옵션: `if (optlen) { bcopy(tcp_initopt, ti + 1, optlen); ti->ti_off = (sizeof (struct tcphdr) + optlen) >> 2; }`(m_get 으로 옵션 mbuf 를 붙이던 NeXTMach 코드 없음; 0x12a169–0x12a199).
7. 수신 창: hiwat/4·t_maxseg 검사 → **0xffff 상한을 먼저**(0x12a1cd) → rcv_adv − rcv_nxt 보다 작으면 올림(0x12a1dd). 긴급 포인터 같음. `if (optlen + len) ti_len = htons(sizeof (struct tcphdr) + optlen + len)`, `ti_sum = in_cksum(m, hdrlen + len)`.
8. 타이머·snd_max 부분 같음. tcp_trace 는 DEBUG 가드 없이 호출(0x12a2fc, plan 152·163 과 같은 꼴). ip_len = hdrlen + len, ttl TCP_TTL, `ip_output(m, inp_options, &inp_route, so_options & SO_DONTROUTE, 0)`(인자 5 개).
9. 오류: ENOBUFS → tcp_quench, return 0; `if ((error == EHOSTUNREACH || error == ENETDOWN) && TCPS_HAVERCVDSYN(tp->t_state)) { tp->t_softerror = error; return (0); }`(0x41/0x32, t_state > 2, +0x6a); return (error). 그 뒤 같음.
10. tcp_setpersist 는 NeXTMach 와 같은 꼴로 봄(빌드로 확인).

방법: NeXTMach `netinet/tcp_output.c` 바탕, tcp_output 을 1–9 대로 고쳐 씀(D024 표시). 지역: m0·opt 제거, `unsigned optlen, hdrlen`. 빌드 `iter.py s5p147-itN bsd/netinet/tcp_output.c tcp_output 129d8c 12a434`, 차이는 스테이징 변형으로, nomc 진단, 기록.

174 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 1–9 주소·순서 맞음(0x129da1, 0x129e10, 0x129ea4, 0x129f80–0x129fad, 0x12a0b5, 0x12a169, 0x12a1cd/0x12a1dd, 0x12a2f9/0x12a310, 0x12a32e–0x12a349, 0x12a355–0x12a379) | 내 역어셈블 `tcpout.dis` 전 구간 | ✅ |
| tcp_setpersist 117 B + 패딩 3 | 0x12a3bc+117 의 다음 심볼까지(fnsizes 120) | ✅ |
| ttl 0x3c(60) 은 NeXTMach `TCP_TTL` 30 과 다르고 SDK 의 NeXT 정의 60 과 맞음 | NeXTMach `tcp_timer.h:62`(30), SDK `tcp_timer.h:67`(60, `#if NeXT`), NM 빌드도 0x3c(스테이징이 SDK 헤더) | ⚖️ 사실, 코드 변경 없음(헤더가 이미 60) |
| tcp_trace 의 실행 시 SO_DEBUG 조건은 유지 | 0x12a2fc test [so+2],1 | ✅(계획 8 과 같음) |
| 통계 필드 이름 NeXTMach 와 같음 | tcpout.dis 의 _tcpstat+오프셋 | ✅ |
### 174.1 it 결과
- it1(`s5p147-it1`) 1576/1584: 원본은 snd_nxt 전진을 `if (flags & (TH_SYN|TH_FIN))` 로 한 번 더 감쌈(0x12a272), ip_len 은 `sizeof (struct tcpiphdr) + optlen + len`(0x12a318, optlen + 0x28). 반영.
- it2: 2 바이트(0x12a045, 0x12a04b) — m_off 가 `0x54 - optlen`, 즉 `MMAXOFF - sizeof (struct tcpiphdr) - optlen`. 반영(작성 표시 `plan 174.1`).
174 결과: it3(`s5p147-it3`) OBJECT_MATCH 2/2(1701 B). nomc 진단 `s5p147-nomc` 종료 0. 등급 A(`06_reconstruction/evidence/x86-tcp_output.md`, `.diff`), functions.tsv 1167·objects_confirmed 122·PROVENANCE 493 행.

## 175. S5-P148 세부 계획 — `netinet/ip_output.c` (D024, MULTICAST 1.x(4.3, mbuf 보관) + NeXT netbuf 형태, 코딩 전, 2026-10-03)

사실(원본 [0x127280, 0x12823f) objects.tsv seq 82; 원본 역어셈블 `ipout.dis`·`ipctl.dis`·`setmo.dis`·`getmo.dis`; 진단 NM 객체):
0. 함수(원본/NM): ip_output 1588/1280, ip_insertoptions 328/328, ip_optcopy 140/140, ip_ctloutput 264/184, ip_pcbopts 312/312, 원본에만 ip_setmoptions 1020·ip_getmoptions 204·ip_freemoptions 68·ip_mloopback 108(마지막, 패딩 1 포함 가능).
1. ip_output(m0, opt, ro, flags, mopts) 인자 5 개(mopts 는 struct mbuf *; `imo = mtod(mopts, struct ip_moptions *)`, 0x127458). 첫머리 hlen=20(−0x30)·`xor esi,esi`(함수 범위 ia = 0)·m=m0(−0x3c)·error=0(−0x58).
2. 경로 결정(0x12730f–0x127429)은 NeXTMach 와 같음(ROUTETOIF 의 ia 가 esi). 그 뒤 소스 주소 채움은 멀티캐스트 블록 다음(0x127544)으로 옮겨지고 같은 함수 범위 ia(esi)를 씀.
3. `#ifdef MULTICAST` 블록(0x12742c–0x127534): IN_MULTICAST(ntohl(ip_dst)) 이면 dst = &ro->ro_dst; (flags & IP_MULTICASTOPTS) && mopts 이면 imo=mtod, ip_ttl = imo_multicast_ttl, imo_multicast_ifp 가 있으면 ifp 로; 아니면 imo = NULL, ip_ttl = IP_DEFAULT_MULTICAST_TTL. ip_src 가 0 이면 ia 루프(ia_ifp == ifp 이면 src 채우고 break). 그 ia 로 그룹 조회(`ia == NULL` 이면 inm = NULL, 아니면 ia_multiaddrs(+0x44) 에서 inm_addr == ip_dst 까지, inm_next +0x14) — SDK IN_LOOKUP_MULTI 의 IFP_TO_IA 루프가 없음(src 가 이미 있으면 이전 ia 값을 씀, 원본 동작 그대로). inm && (imo == NULL || imo_multicast_loop) → ip_mloopback(ifp, m, dst); else if (ip_mrouter && !(flags & IP_FORWARDING)) { if (ip_mforward(ip, ifp)) { m_freem(m); goto done; } }; if (ip_ttl == 0 || ifp == loifp) { m_freem(m); goto done; } goto sendit;(sendit 은 broadcast 검사 뒤, `ip_len <= if_mtu` 앞).
4. 단편화(0x127618–0x127853): 헤더를 지역 `struct ip`(−0x28)에 만들고 bcopy 로 netbuf 에 넣음. 첫 조각: nb=if_getbuf, map=nb_map, mbuf_read(m, map, 0, hlen+len), 지역=*ip, ip_len=htons(hlen+len), ip_off=htons(ip_off|IP_MF), sum=0, bcopy(지역, map, 20), 지역 sum=in_cksum(nb, hlen), 체크섬 2 바이트를 map+10 에 바이트씩(0x1276bc–0x1276c8), if_output. 루프: 같은 꼴, map 을 두 변수(−0x4c, −0x34)에 둠, ip_optcopy(ip, map), ip_hl 은 지역에, nb_shrink_bot, mbuf_read(m, map+mhlen, off, len), bcopy(지역, −0x34, 20), 체크섬 바이트 저장(0x12781a–0x127828). 루프 끝은 bad 와 같은 m_freem(m0) 로 합쳐짐.
5. ip_ctloutput: SETOPT/GETOPT 모두 IP_MULTICAST_IF..IP_DROP_MEMBERSHIP(3–7) case 추가 — `error = ip_setmoptions(optname, &inp->inp_moptions, *m)`(+0x3c), `error = ip_getmoptions(optname, inp->inp_moptions, m)`.
6. ip_setmoptions(optname, imop, m) (0x127cc8): *imop 이 없으면 MGET(*imop, M_WAIT, MT_IPMOPTS) 인라인, 실패 ENOBUFS, 기본값(ifp NULL, ttl 1, loop 1, num 0); imo = mtod(*imop). switch: IF(m_len 4, INADDR_ANY → ifp NULL, 아니면 INADDR_TO_IFP, 없으면 EADDRNOTAVAIL; IFF_MULTICAST 검사 없음), TTL(m_len 1), LOOP(m_len 1, >1 EINVAL), ADD(m_len 8, IN_MULTICAST 아니면 EINVAL, 인터페이스 ANY 면 지역 route 로 rtalloc→rt_ifp, rtfree; 아니면 INADDR_TO_IFP; 없으면 EADDRNOTAVAIL; 중복 EADDRINUSE; 20 개면 ETOOMANYREFS; in_addmulti 실패 ENOBUFS; num++), DROP(ANY 면 ifp NULL; 찾기 실패 EADDRNOTAVAIL; in_delmulti; 뒤를 당김; num--), default EOPNOTSUPP. 끝: 모두 기본값(ifp NULL 이고 ttl·loop·num 의 4 바이트 == 0x101)이면 m_free(*imop), *imop = NULL.
7. ip_getmoptions(optname, mopts, mp): *mp = m_get(M_WAIT, MT_IPMOPTS); imo = mopts ? mtod : NULL; IF(m_len 4; IFP_TO_IA 로 주소 또는 INADDR_ANY), TTL·LOOP(m_len 1; imo 없으면 기본값 1); default EOPNOTSUPP.
8. ip_freemoptions(mopts): mopts 가 있으면 membership 마다 in_delmulti 후 m_free(mopts).
9. ip_mloopback(ifp, m, dst): copym = m_copy(m, 0, M_COPYALL); 있으면 ip_len·ip_off htons, sum 다시 계산(ip_hl<<2), looutput(ifp, copym, dst).

방법: NeXTMach `netinet/ip_output.c` 바탕. ip_output·ip_ctloutput 수정, 6–9 작성(D024 표시, 멀티캐스트 부분은 `#ifdef MULTICAST`). 형태가 불확실한 곳(ia 선언 위치, 지역 헤더 변수와 map 두 변수, 체크섬 2 바이트 저장 꼴, 0x101 비교 꼴)은 스테이징 변형으로 정함. 빌드 `iter.py s5p148-itN bsd/netinet/ip_output.c ip_output 127280 12823f`, nomc 진단, 기록.

175 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0 경계·크기, 점프 표 대상 5 개, 0x12823f 패딩 | Python 점프 표 읽기(0x127dc8,0x127e30,0x127e54,0x127e80,0x127fac), getmo.dis 0x12823e ret | ✅ |
| 사실 2 정정: 일반 경로의 소스 주소 채움은 옮겨진 것이 아니라 NeXTMach 와 같은 자리(경로 결정 뒤, broadcast 앞, 0x127544), 멀티캐스트 블록이 그 앞에 끼어듦 | ipout.dis 0x12742c–0x127563 와 NeXTMach `ip_output.c` :145–:157 순서 | ✅ 표현 정정(코드 영향 없음) |
| 사실 6 누락: DROP 도 IN_MULTICAST(ntohl(group)) 검사, 실패 EINVAL(0x127fbd–0x127fcb → 0x127fcd) | setmo.dis 0x127fac–0x127fd4 | ✅ 채택 — DROP 에 검사 추가 |
| 오류 코드 0x30/0x3b/0x31/0x37/0x2d 위치 | setmo.dis | ✅ |
| ip_insertoptions·ip_optcopy·ip_pcbopts 차이 없음 | shapediff(NM 객체) 세 함수 차이 0 | ✅ |
| ia=0 범위, IFP_TO_IA 부재, 지역 헤더·map 두 변수, 체크섬 바이트 저장, 0x101 비교는 C 꼴을 정하지 못함 | 계획에 이미 "스테이징 변형으로 정함" | ✅(가설로 둠) |
### 175.1 it 결과(진행 중, 기록 보류)
- it1(`s5p148-it1`): 8 함수 크기 일치, ip_output 1584/1588. 스택 슬롯이 원본(hlen −0x30, mhip −0x34, ifp −0x38)과 달라 선언 순서를 hlen → ip/mhip → ifp → ia → m 으로 바꿈(초기화 순서 hlen·ia·m·error 와도 맞음, 작성 표시 `plan 175.1`).
- it2(`s5p148-it2`): 슬롯 일치. ip_insertoptions·ip_optcopy·ip_ctloutput·ip_pcbopts·ip_setmoptions(점프 표 제외)·ip_getmoptions·ip_freemoptions·ip_mloopback 은 꼴 차이 0. 남은 차이는 ip_output 루프의 체크섬 2 바이트 저장 하나: 원본 `mov eax,[ebp-0x4c]; add eax,0xa; mov [eax],cl; mov [eax+1],cl`(0x12781a–0x127828), 빌드 `mov edi,[ebp-0x4c]; mov [edi+0xa],cl; mov [edi+0xb],cl`(첫 조각 0x1276bc 은 빌드와 같은 꼴) → 2 바이트 + 정렬 nop 2.
- 스테이징 변형(`s5p148-v1`–`v10`, 약 30 가지): `map[10]` 직접, `map + 10` 포인터(블록·함수 범위, 증가형), `&((struct ip *)map)->ip_sum`, mhip 기준, `(int)` 캐스트, `memcpy`(1580), 2 바이트 구조체 복사(1580), volatile, 2 회 루프(1596–1600), 인라인 도우미(-O3 자동 인라인, 크기 1588 이지만 pending stack adjust 위치가 바뀜), 분기 앞 포인터 계산(1592) — 모두 불일치. 원본은 주소를 별도 의사 레지스터로 남기는 원인이 소스에 있으나 아직 못 찾음.
- 07 파일은 두되 표(functions/objects/PROVENANCE)에는 넣지 않음. 다음 대상으로 넘어가고 나중에 다시 봄.
- (2026-10-07 덧붙임) 남은 체크섬 저장 차이는 plan 383(본 문서 RECONSTRUCTION_PLAN.md §383)에서 맞춤 — `s5p383-it1` OBJECT_MATCH, 등급 A 로 기록.

## 176. S5-P149 세부 계획 — `net/if_venip.c` (D024, NeXT MULTICAST 형태, 코딩 전, 2026-10-03)

사실(원본 역어셈블 `venip.dis`·`venip2.dis`; 진단 NM 객체 `s5p124l1/out/NM__if_venip_67.o`):
0. 객체 범위는 [0x11f560, 0x11fb84) — objects.tsv seq 67 의 text_end 0x11f97b 는 기호 있는 함수(venip_config)의 끝이고, 그 뒤 기호 없는 정적 함수 venip_attach(0x11f97c, venip_config 가 0x11f96d 에서 그 주소를 if_registervirtual 에 넘김), venip_output(0x11fa48), venip_getbuf(0x11fb48)가 이어지며 0x11fb84 는 `_SRHash`(다른 객체). attach 안에서 venip_control(0x11f9e8 에 0x11f5a8)·venip_input(0x11f9f7 에 0x11f704) 주소를 씀.
1. 원본 순서·크기: VENIP_PRIVATE 16, VENIP_ENADDRP 16, VENIP_IPADDR 20, VENIP_RIF 20, venip_control 348, venip_input 612(trailer_fix 인라인), venip_config 20, venip_attach 204, venip_output 256(패딩 포함), venip_getbuf 60(패딩 포함). NM: control 248 이고 순서가 input, config, attach, output, control, getbuf — 나머지 크기는 같음. control 이 커져 -O3 인라인 후보(지연 출력)에서 빠지면 정의 자리에서 출력되어 원본 순서가 된다고 봄(빌드로 확인).
2. venip_control 차이: (a) SETADDR 의 플래그를 `if_flags(ifp) | IFF_UP | IFF_RUNNING`(0x11f625 `or al,0x41`); (b) GDB 블록 없음(GDB 0); (c) SETADDR 다음에 `IFCONTROL_ADDMULTICAST`·`IFCONTROL_RMVMULTICAST`(0x1d1255/0x1d1263) 분기: data 를 struct ifreq 로 보고 `ifr_addr`(+0x10) 의 sin_family 가 AF_INET 아니면 EAFNOSUPPORT, `ETHER_MAP_IP_MULTICAST(&sin->sin_addr, 지역 6 바이트)`(0x11f6af–0x11f6cd, 지역 −8) 후 `return (if_control(rifp, command, &지역))`; 그 밖은 `if_control(rifp, command, data)`.

방법: NeXTMach `net/if_venip.c` 바탕 + 2 작성(D024 표시, 멀티캐스트 분기는 `#ifdef MULTICAST`; `net/if.h` import 필요 여부는 빌드로). 빌드 `iter.py s5p149-itN bsd/net/if_venip.c if_venip 11f560 11fb84`(cmpobj 범위에 정적 함수 포함), nomc 진단, 기록(objects 행의 범위는 실제 [0x11f560, 0x11fb84) 로 적고 objects.tsv 와 다른 이유를 남김).

176 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 범위 [0x11f560, 0x11fb84), getbuf ret 0x11fb80 뒤 0 바이트 3 개, 0x11fb84 프롤로그 | Python 바이트 `ec 5d c3 00 00 00 55 89 e5`(0x11fb7e–), venip2.dis | ✅ |
| attach 가 input/output/getbuf/control 주소를 if_attach 에 넘김 | venip.dis 참조 검색(0x11f9e8, 0x11f9f7) | ✅ |
| IFF_AUTOCONF = 0x4000(`ah & 0x40`) | SDK `net/netif.h:48` | ✅(NeXTMach 와 같은 이름, 값만 확인) |
| 멀티캐스트 분기: 명령 포인터 그대로 넘김, data+0x10 검사, data+0x15–0x17 | venip.dis 0x11f684–0x11f6ee | ✅(계획 2(c) 와 같음) |
| attach·output·getbuf·input 은 NeXTMach 와 같음 | NM 크기 일치(빌드로 최종 확인) | ⚖️ 빌드 L1 로 판정 |
### 176.1 it 결과
- it1: struct ifreq 미정의 → `net/if.h` import. it2: control 352/348 — 원본은 멀티캐스트 분기의 EAFNOSUPPORT 반환이 매핑·if_control 반환 뒤(0x11f6e0, 다른 두 AF_INET 검사도 같은 블록으로 합쳐짐) → `if (AF_INET) {...; return if_control(...);} return (EAFNOSUPPORT);`. it3: 함수 순서 원본과 같아짐(control 이 인라인 후보에서 빠짐), output 252/256. it4: 별도 형 변수(불일치). 원본 output 은 AF_UNSPEC 에서도 `ror ax,8`(0x11fa87→0x11fad1) — `eh.ether_type = htons(eh.ether_type);`(arpwhohas 의 "if_output will swap" 과 맞음).
176 결과: it5(`s5p149-it5`) OBJECT_MATCH 12/12, 객체 [0x11f560, 0x11fb81)(정적 함수 포함, 다음 기호 _SRHash 0x11fb84). nomc 진단 `s5p149-nomc` 종료 0. 등급 A(`06_reconstruction/evidence/x86-if_venip.md`, `.diff`), functions.tsv 1177·objects_confirmed 123·PROVENANCE 494 행.

## 177. S5-P150 세부 계획 — `bsd/vfs_lookup.c` (D024, NeXT POSIX 경로 처리, 코딩 전, 2026-10-03)

사실(원본 역어셈블 `lookuppn.dis` [0x11c13c, 0x11c760); 진단 NM 객체 `s5p124l1/out/NM__vfs_lookup_57.o`):
0. 객체: lookupname 68(같음), lookuppn 원본 0x11c13c–0x11c75d(+nop 3) 1572/NM 1484, 그 뒤 정적 getsymlink 0x11c760(540, NM 과 같은 크기; lookuppn 이 0x11c568 에서 호출). objects.tsv seq 57 의 text_end 0x11c75d 는 lookuppn 의 끝, 실제 범위는 [0x11c0f8, 0x11c97c).
1. begin: `component[0] = 0;` 뒤 `pn_peekchar(pnp) == '/'` 처리 다음에 `else if (pn_peekchar(pnp) == 0 && u.u_procp->p_posix) return (ENOENT);`(0x11c1d0–0x11c1e6; p_posix 는 SDK `sys/proc.h` 의 NeXT 비트필드, 오프셋 0x16 비트 1 → `test byte [eax+0x16],2`; Python 오프셋 계산: 포인터 4 개 0x10, 그 뒤 char 6 개, 비트필드 바이트 0x16). VN_RELE 없이 바로 반환(0x11c1e6 jmp 에필로그).
2. skip: `pn_pathleft(pnp) == 0` 검사 앞에 POSIX 꼬리 '/' 처리(0x11c5d4–0x11c614): `if (pn_pathleft(pnp) && u.u_procp->p_posix) { cp = pnp->pn_path; while (*cp == '/') cp++; if (*cp == 0 && cvp->v_type == VDIR) { *pnp->pn_path = 0; pnp->pn_pathlen = 0; } }`.
3. 그 밖(".." 처리, 가상 마운트 목록, VOP_LOOKUP, 심볼릭 링크, mloop, 끝 처리)은 NeXTMach 와 같은 흐름(역어셈블 0x11c278–0x11c75c 대조). pn_stripcomponent 는 SDK 매크로로 pn_getcomponent(…, PN_STRIP=0).

방법: NeXTMach `bsd/vfs_lookup.c` 바탕 + 1·2 작성(D024 표시, `#if POSIX_KERN` 안). 빌드 `iter.py s5p150-itN bsd/kern/vfs_lookup.c vfs_lookup 11c0f8 11c97c`(07 경로는 기존 배치 규칙 확인), 기록(objects 행의 범위는 실제 끝으로).

177 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 범위·getsymlink(0x11c760–0x11c97b, 0x11c568 호출) | rdiff(NM getsymlink 540 = 원본 540, 꼴 차이 0), 0x11c974 바이트 `… 5d c3 55 89 e5` | ✅ |
| ENOENT 경로는 vp 를 놓지 않음(0x11c1e1→0x11c1e6) | lookuppn.dis | ✅(계획 1 과 같음) |
| 꼬리 '/' 처리 순서(0x11c5d4–0x11c614) | lookuppn.dis | ✅ |
| MAXSYMLINKS 20/ELOOP, PVFS 27, strncmp 255, VOP_LOOKUP 인자 | lookuppn.dis 0x11c533, 0x11c3d4/0x11c4c0, 0x11c3ac, 0x11c423 | ✅ |
| `#if POSIX_KERN` 가드는 바이트로 정해지지 않음 | 계획에 이미 작성 꼴로 둠 | ⏭️(행동 변화 없음) |
### 177.1 it 결과
- it1: struct proc 미완성 → `sys/proc.h` import. it2: lookuppn 1596/1572(프레임 0x124 대 0x120, 임시 레지스터 ecx 대 edi). cp 선언·lookup_flags 변형(`s5p150-v1`–`v3`)은 차이 없음. 레지스터를 접은 비교로 원본이 mount point 통과(mloop, 0x11c4ac)를 심볼릭 링크 처리(0x11c510) 앞에 둔다는 점을 찾음(NeXTMach 는 반대) → 순서 바꿈(작성 표시 `plan 177.1`).
177 결과: it3(`s5p150-it3`) OBJECT_MATCH 3/3(2180 B, 정적 getsymlink 포함 [0x11c0f8, 0x11c97c)). POSIX_KERN 없는 진단 `s5p150-noposix` 종료 0. 등급 A(`06_reconstruction/evidence/x86-vfs_lookup.md`, `.diff`), functions.tsv 1180·objects_confirmed 124·PROVENANCE 497 행(SDK 헤더 채택 2 행 포함).

## 178. S5-P151 세부 계획 — `ufs/ufs_bmap.c` (D024, NeXT i386 빅엔디언 UFS 간접 블록, 코딩 전, 2026-10-03)

사실(원본 역어셈블 `bmap.dis` [0x13d830, 0x13de34); 진단 NM 객체 `s5p124l1/out/NM__ufs_bmap_129.o`):
0. bmap 원본 [0x13d830, 0x13de14) 1508 / NM 1447. 그 뒤 `_brelse_and_swap`(0x13de14, 32 B: `if (bp) { byte_swap_dir_block_out(bp); brelse(bp); }`)은 참조 소스에 없고 커널 안에서 부르는 곳이 없음(rel32 호출 0 건, 절대 주소는 기호 표 0x1f9c4c 하나). ufs_bmap.c 와 ufs_dir.c(seq 130, 0x13de34) 중 어느 쪽 소속인지 바이트로 정할 수 없어 이번 범위에서 뺌.
1. 간접 블록 항목은 빅엔디언으로 보관: `nb = NXSwapBigLongToHost(bap[i])`(0x13dce1–0x13dce6 bswap), `bap[i] = NXSwapHostLongToBig(nb)`(0x13dd98–0x13dda2), read-ahead `rablock = fsbtodb(fs, NXSwapBigLongToHost(bap[i+1]))`(0x13dde1–0x13dde5). 직접 블록(i_db)·i_ib 는 교환 없음.
2. 첫머리에서 i(−4)와 bap(−0x14)을 0 으로 초기화(0x13d83c, 0x13d843) — 선언 초기화로 봄(`register int i = 0`, `daddr_t *bap = 0`; 꼴은 빌드로).
3. MACH_NBC 의 `rwflg & B_XXX`(0x20) 처리는 있음(0x13d871), vno_flush 는 `!NeXT` 로 없음 — NeXTMach 와 같음. 그 밖 흐름(조각 확장, 직접 블록, 간접 단계 계산, EFBIG, alloc/bwrite/bdwrite 조건)은 NeXTMach 와 같음.

방법: NeXTMach `ufs/ufs_bmap.c` 바탕 + 1·2 작성(D024 표시, `architecture/byte_order.h` import). 빌드 `iter.py s5p151-itN ufs/ufs_bmap.c ufs_bmap 13d830 13de14`(07 경로 규칙 확인), 기록(범위 [0x13d830, 0x13de14), brelse_and_swap 미배정 사유 남김).

178 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| bmap 의 bswap 은 정확히 3 곳(0x13dce6, 0x13dd9a, 0x13dde5), i_db·i_ib·b_blkno·blkpref 인자·직접 블록 rablock 은 교환 없음 | bmap.dis `grep -c bswap` = 3, 위치 같음 | ✅ |
| 원본 blkpref(ufs_alloc.c, 0x13c0ac)도 간접 항목을 교환(0x13c0dc, 0x13c235) | odis 0x13c0ac–0x13c260 bswap 2 건 | ✅ 사실 — ufs_alloc.c(seq 128) 재구성 때 반영할 메모, 이번 객체 영향 없음 |
| 0 초기화 슬롯 −4 = i(0x13dcdb), −0x14 = bap(0x13dcba) | bmap.dis 해당 줄 | ✅ |
| 그 밖 흐름 차이 없음 | 내 대조(0x13d830–0x13dbb1) | ✅(빌드 L1 로 최종) |
| brelse_and_swap 직접 호출·절대 참조 없음(기호 표만) | 내 Python 검색(rel32 0 건, 절대 0x1f9c4c) | ✅ |
178 결과: it1(`s5p151-it1`) OBJECT_MATCH 1/1(1508 B). 등급 A(`06_reconstruction/evidence/x86-ufs_bmap.md`, `.diff`). `_brelse_and_swap` 미배정(ufs_dir.c 재구성 때 다시 봄), blkpref 의 교환은 ufs_alloc.c 메모.

## 179. S5-P152 세부 계획 — `bsd/vfs_syscalls.c` (D024, NeXT POSIX 형태, 코딩 전, 2026-10-03)

사실(원본 [0x11cba8, 0x11de7c) objects.tsv seq 59; 원본 역어셈블; 진단 NM 객체 `s5p124l1/out/NM__vfs_syscalls_59.o`; 36 함수 중 크기 다름 open 96/44, copen 252/204, lseek 312/220, 원본에만 `__utime`(C 이름 `_utime`, 0x11da80, 236), NM 에만 getdents 655):
1. open(0x11cce0): `px = get_posix_proc(u.u_procp->p_pid)`(p_pid +0x30), `px->p_posix_noctty = uap->fmode >> 4`(O_NOCTTY 020; 1 비트 필드 +0x18 비트 1, 0x11cd00–0x11cd14), copen 호출(인자 fmode − FOPEN), 뒤에 `px->p_posix_noctty = 0`(0x11cd32). posix_proc 는 SDK `sys/proc.h`(`#if POSIX_KERN`).
2. copen(0x11cd6c): 성공 경로에서 f_flag 설정 뒤 `if (u.u_procp->p_posix && vp->v_type == VREG) fp->f_flag |= O_NO_MFS|FNOSPC;`(0x40001000, 0x11ce07–0x11ce23), 끝에 `u.u_ofile[i] = fp;`(0x11ce4a–0x11ce58). 실패 경로는 NeXTMach 와 같음(free_file 포함).
3. lseek(0x11d558): POSIX 프로세스이면 결과 오프셋이 음수일 때 `u.u_error = EINVAL; return;` — L_INCR(f_offset + off, 0x11d5d0), L_XTND(off + va_size, 0x11d620), L_SET(off < 0, 0x11d644). 나머지(ESPIPE 처리, default EINVAL 후 r_off 설정)는 같음.
4. `_utime()`(utimes 와 truncate 사이): 지역 vattr(−0x40), tv(−0x48), times[2](−0x50) 순 선언; `px = get_posix_proc(…); getthetime(&tv); vattr_null(&vattr);` POSIX 이고 `uap->tptr == 0` 이면 `vattr.va_atime = vattr.va_mtime = tv; px->p_posix_utime = 1;` 아니면 `copyin(uap->tptr, times, 8)`(실패 시 return), `va_atime.tv_sec = times[0]; va_mtime.tv_sec = times[1]; va_atime.tv_usec = va_mtime.tv_usec = 0;` → `error = namesetattr(uap->fname, FOLLOW_LINK, &vattr); px->p_posix_utime = 0; u.u_error = (p_posix && error == EPERM && uap->tptr == 0) ? EACCES : error;`(0x11db35–0x11db5e).
5. getdents(NeXTMach :1084–:1262 의 두 정의)는 원본에 없음(기호 없음) → 제외.

방법: NeXTMach `bsd/vfs_syscalls.c` 바탕 + 1–5 작성(D024 표시, POSIX 부분은 `#if POSIX_KERN`). 빌드 `iter.py s5p152-itN bsd/kern/vfs_syscalls.c vfs_syscalls 11cba8 11de7c`, POSIX_KERN 없는 진단, 기록.

179 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| open 의 noctty 기록은 p_posix 검사 없이 무조건 | 역어셈블 0x11cce0–0x11cd36 | ✅(계획 1 과 같음, 명시) |
| copen: p_posix·VREG 뒤 OR(0x11ce1d), u_ofile 저장은 FIFO 처리 뒤(0x11ce58) | 역어셈블 0x11cdfc–0x11ce58 | ✅ |
| lseek: POSIX 검사는 f_offset 변경 전, EINVAL 반환(0x11d657)은 r_off 저장 건너뜀, default 는 r_off 저장까지 감 | 역어셈블 0x11d5d0–0x11d681 | ✅ |
| _utime 저장 순서(POSIX: mtime.sec, atime.sec, mtime.usec, atime.usec; copyin: atime.sec, mtime.sec, mtime.usec, atime.usec), copyin 실패 반환 0x11db09 | 역어셈블 0x11dacc–0x11db1e | ✅(계획 4 의 연쇄 대입 꼴과 맞음) |
| getdents: 이름·기호 없음, sysent 슬롯 174 = nosys, 156 = getdirentries, 180 = __utime(인자 2) | Python: sysent(0x1da034, 8 바이트 항목) 슬롯 174 `(0, 0x10ccd4 _nosys)`, 156 `(4, 0x11d1a4)`, 180 `(2, 0x11da80)` | ✅ 채택 — 표현을 "이름 있는 구현·핸들러 없음"으로; init_sysent.c 재구성 때 슬롯 174·180 반영 메모 |
| 그 밖 32 함수 동등 | NM 크기 일치(fnsizes) | ⚖️ 빌드 L1 로 판정 |
### 179.1 it 결과
- it1: lseek 의 음수 검사가 접혀 사라짐 — KERNEL 에서 off_t 가 u_long → `(long)` 캐스트(원본 js/jge). it2: `_utime` 240/236 — 변형 u1(필드 단위 연쇄 대입 sec·usec) 차이 0. it3: open 의 sar/shr(변형 o1 `(unsigned)` 시프트, o2 `(fmode & O_NOCTTY) ? 1 : 0` 둘 다 0 → o2 채택), lseek 은 case 마다 `{ u.u_error = EINVAL; return; }`(변형 l1, 0).
179 결과: it4(`s5p152-it4`) OBJECT_MATCH 36/36(4820 B). POSIX_KERN 없는 진단 `s5p152-noposix` 종료 0. 등급 A(`06_reconstruction/evidence/x86-vfs_syscalls.md`, `.diff`). init_sysent.c 메모: 슬롯 174 nosys, 180 `_utime`(인자 2).

## 180. S5-P153 세부 계획 — `bsd/uipc_syscalls.c` (D024, NeXT u_ofile 등록·POSIX pipe 형태, 코딩 전, 2026-10-03)

사실(원본 [0x116db4, 0x118116) objects.tsv seq 51; 원본 역어셈블; 진단 NM 객체 `s5p124l1/out/NM__uipc_syscalls_51.o`; 22 함수 중 크기 다름 socket 164/136, accept 496/492, socketpair 496/452, recvfrom 152/136, pipe 436/336, getsock 48/46(마지막, 패딩)):
1. falloc 이 디스크립터 표에 넣지 않는 꼴(vfs_syscalls 의 copen 과 같음): 성공 경로에서 `f_data` 설정 바로 뒤 `u.u_ofile[u.u_r.r_val1] = fp;` — socket(f_data 뒤), accept(f_data 뒤), socketpair(fp1·fp2 각각, sv[] 저장 위치는 NeXTMach 와 같음), pipe(rf·wf 각각; 0x117d53–0x117d67, 0x117da7–0x117dbb).
2. accept: NeXTMach 의 `if (ufalloc(0) < 0) { splx(s); return; }` 없음(falloc 바로 호출).
3. recvfrom(0x11771c): `if (uap->fromlenaddr) u.u_error = copyin(fromlenaddr, &len, sizeof (len)); else msg.msg_namelen = 0;`(0x11772b–0x117750) 뒤 `if (u.u_error) return;` 그리고 NeXTMach 그대로 `msg.msg_namelen = len`(else 의 0 은 덮어씀 — 원본 동작 그대로).
4. pipe(0x117cac): rf `f_flag = FREAD` 뒤 `if (u.u_procp->p_posix) rf->f_flag = FREAD|FPOSIX_PIPE;`(0x2001), wf 도 `FWRITE|FPOSIX_PIPE`(0x2002). FPOSIX_PIPE 는 SDK `sys/file.h` 020000.

방법: NeXTMach `bsd/uipc_syscalls.c` 바탕 + 1–4 작성(D024 표시, POSIX 부분 `#if POSIX_KERN`). 빌드 `iter.py s5p153-itN bsd/kern/uipc_syscalls.c uipc_syscalls 116db4 118118`, POSIX 없는 진단, 기록.

180 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| socket·accept·socketpair 의 u_ofile 저장은 f_data 뒤, accept 에 ufalloc 없음 | shapediff(NM 대비: socket·accept·socketpair 의 추가 저장, accept 의 ufalloc 블록 삭제) | ✅ |
| recvfrom else 는 msg_namelen(−0x14)에 0, 뒤에서 len(−0x1c)으로 덮어씀 | 역어셈블 0x11771c–0x1177ab | ✅ |
| pipe 순서(r 저장 → flag → POSIX 대체 → type/ops/data → u_ofile, r_val2/r_val1 은 뒤) | 역어셈블 0x117cac–0x117e5e | ✅ |
| 나머지 17 함수 차이 없음 | fnsizes 크기 일치 | ⚖️ 빌드 L1 로 판정 |
180 결과: it1(`s5p153-it1`) OBJECT_MATCH 22/22(4962 B). POSIX_KERN 없는 진단 `s5p153-noposix` 종료 0. 등급 A(`06_reconstruction/evidence/x86-uipc_syscalls.md`, `.diff`), functions.tsv 1239·objects_confirmed 127·PROVENANCE 502 행.

## 181. S5-P154 세부 계획 — `bsd/subr_log.c` (D024, NeXT callout·스레드 select 형태, 코딩 전, 2026-10-03)

사실(원본 [0x10bd48, 0x10c0d8) objects.tsv seq 36; 원본 역어셈블 `subrlog.dis`; NM 객체 `s5p124l1/out/NM__subr_log_36.o`):
0. 원본 함수: logopen 140, logclose 112, logread 224(NM 과 같음), logselect 80, logwakeup 0x10bf74(28), 기호 없는 정적 log_wakeup 0x10bf90(128), logioctl 200(NM 199 + 패딩). logsoftc 는 4 필드(sc_state +0, sc_selp +4, sc_pgrp +8, 새 sc_callout +0xc).
1. logopen: `log_open` 검사(EBUSY) 뒤 `sc_selp = 0; sc_pgrp = u.u_procp->p_pgrp; sc_callout = calloutEntryAllocate(log_wakeup, 0); log_open = 1;`(0x10bd60–0x10bd8b) 그 다음 msgbuf 초기화(같음).
2. logclose: `log_open = 0; ce = sc_callout; sc_callout = 0; calloutEntryRemove(ce); calloutEntryFree(ce); sc_state = 0; s = splhigh(); th = sc_selp; sc_selp = 0; splx(s); if (th) thread_deallocate(th); sc_pgrp = 0;`(0x10bdd8–0x10be30).
3. logselect: FREAD 이고 읽을 것이 없으면 `selthreadcache(&logsoftc.sc_selp)`(0x10bf54; NeXTMach 의 current_thread 대입 대신).
4. logwakeup: `if (log_open) calloutEntryDispatch(logsoftc.sc_callout);`(softint_sched 대신). 정적 log_wakeup: `if (!log_open) return; s = splhigh(); th = sc_selp; sc_selp = 0; splx(s); if (th) { selwakeup(th, 0); thread_deallocate_interrupt(th); }` 뒤 ASYNC(gsignal SIGIO)·RDWAIT(wakeup pmsgbuf, 비트 해제)는 같음.
5. logread·logioctl 은 NeXTMach 와 같음.

방법: NeXTMach `bsd/subr_log.c` 바탕 + 1–4 작성(D024 표시). sc_selp 형은 thread_t(빌드로 확인), 외부 함수는 암묵 선언 유지(필요하면 매개변수 없는 extern 선언). 빌드 `iter.py s5p154-itN bsd/kern/subr_log.c subr_log 10bd48 10c0d8`, 기록.

181 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| logsoftc 16 B(+0 state, +4 selp, +8 pgrp, +0xc callout) | subrlog.dis 의 0x1e97c0–0x1e97cc 접근 | ✅ |
| logopen·logclose·logselect·logwakeup·0x10bf90 순서와 인자(calloutEntryAllocate(0x10bf90, 0), selwakeup(th, 0), gsignal(pgrp, 0x17)) | subrlog.dis | ✅ |
| 0x10bf90 은 기호 없음, `static` 은 가설 | symbols.tsv 에 없음, 0x10bd7c push 하나 | ✅(가설로 표시) |
| logread·logioctl 은 동작 같음 | jtdiff(재배치 값 외 차이 없음), logioctl 199+패딩 | ✅ |
| pmsgbuf 는 __data(초기값 있음), log_open·logsoftc 는 common | symbols.tsv 섹션 값, pmsgbuf 바이트 | ⚖️ L1 로 확인(NeXTMach 선언이 common 이면 초기화 꼴 조정) |
### 181.1 it 결과
- it1: thread_t 미선언 → `struct thread *`. it2: logwakeup 이 edx 로 적재(원본 eax). 변형 `s5p154-v1`(void 반환, int 형) 불일치, `s5p154-v2` p1(calloutEntryDispatch 를 void 프로토타입)·p3(calloutEntry* 전체 프로토타입) 차이 0 → p3 채택(작성 표시 `plan 181.1`).
181 결과: it3(`s5p154-it3`) OBJECT_MATCH 7/7(911 B). 등급 A(`06_reconstruction/evidence/x86-subr_log.md`, `.diff`).

## 182. S5-P155 세부 계획 — `bsd/sys_generic.c` (D024, NeXT continuation select·스레드 캐시 형태, 코딩 전, 2026-10-03)

사실(원본 [0x10cd54, 0x10d84f) objects.tsv seq 39; 원본 역어셈블 `sysgen.dis`; NM 객체 `s5p124l1/out/NM__sys_generic_39.o`; 참조 소스(NeXTMach·Darwin 0.1·Mach4)에 selcont/selthreadcache 없음 → 바이트로 작성):
0. 함수(원본/NM): read·readv·write·writev·ioctl·seltrue 같음; rwuio 420/404; select 352/992; selscan 288/316; selwakeup 108/89; 원본에만 selcont 548·selthreadcache 112·selthreadclear 52; NM 의 unselect 없음.
1. rwuio: `on_master` 가 스택에 남아 증가(0x10cebb 등) — 스테이징 변형(`s5p155-v1` r1 `volatile int on_master = 0`) 차이 0.
2. select(0x10d290): `sel = &u.u_select`(uthread+0x88, SDK `sys/user.h` 의 `uu_state.ss_select`: ibits[3]·obits[3]·atv(+0xc0)·poll(+0xc8)·error(+0xcc)); `*sel` 을 0 으로 채운 208 B 정적 상수(0x1d10dc, __TEXT)로 복사(rep movsd); nd > NOFILE(256) 이면 NOFILE; ni = howmany(nd, 32); in/ou/ex 각각 copyin 결과를 sel->error 에(실패 시 selcont 로); tv 가 있으면 copyin(&atv)·itimerfix(EINVAL)·0 이면 poll = 1, 아니면 `getthetime(&now); timevaladd(&sel->atv, &now)`; 끝은 `selcont()` 호출.
3. selcont(0x10d3f0): `if (sel->error < 0)`(잠에서 돌아옴) `thread_wait_result()` 가 2·3(THREAD_INTERRUPTED·THREAD_SHOULD_TERMINATE) 이면 EINTR, 아니면 0; `if (sel->error > 0) goto done;` retry: ncoll = nselcoll, p->p_flag |= SSEL(0x400000), r_val1 = selscan(sel->ibits, sel->obits, uap->nd), sel->error = u.u_error; error·r_val1·poll 이면 done; splhigh; tv 이면 getthetime(&now) 뒤 now ≥ atv 이면 splx, done; SSEL 해제됐거나 nselcoll 바뀌면 SSEL 해제·splx·retry; SSEL 해제; `sel->error = -1`; tv 이면 `sleep_with_continuation_and_deadline(&selwait, PZERO+1, selcont, &sel->atv)` 아니면 `sleep_with_continuation(&selwait, PZERO+1, selcont)`; done: ni 계산, error 가 0 이면 obits copyout 3 개(결과를 sel->error 에), error 면 u.u_error = error, `unix_syscall_return(sel->error)`.
4. selscan(0x10d614): flag 는 정적 표 `{FREAD, FWRITE, 0}`(0x1daca8, __data) 에서; 루프는 NeXTMach 와 같되 `fd >= u.u_ofile_cnt`(utask+0x15c) 이면 break(fd ≥ nfd 검사 뒤) 추가.
5. selthreadcache(threadp)(0x10d740): splhigh; `*threadp` 가 있고 `thread->active`(+0x178) 이며 `thread->wait_event == &selwait`(+0x3c) 이면 splx, return 1(충돌); 아니면 `*threadp = 0; splx; thread_deallocate(thread)`(없으면 splx 만); 그 뒤 `thread = current_thread(); thread_reference(thread); *threadp = thread; return 0`.
6. selthreadclear(threadp)(0x10d7b0): `if (threadp == 0) panic("selthreadclear not passed an address\n"); if (*threadp) thread_deallocate_interrupt(*threadp); *threadp = 0;`.
7. selwakeup(thread, coll)(0x10d7e4): coll 처리 같음; `if (thread && thread->active) { s = splhigh(); if (thread->wait_event == &selwait) clear_wait(thread, THREAD_AWAKENED, TRUE); if (thread->task->proc) thread->task->proc->p_flag &= ~SSEL; splx(s); }`.
8. unselect 와 NeXTMach select 의 timeout/setjmp 경로는 없음.

방법: NeXTMach `bsd/sys_generic.c` 바탕, 1·4·7 수정, 2·3·5·6 작성(D024 표시). 0 템플릿은 `static const struct _select` 로 시험, 형태 불확실한 곳(sel 포인터와 u.u_select 직접 접근 혼용, 템플릿 꼴)은 스테이징 변형으로. 빌드 `iter.py s5p155-itN bsd/kern/sys_generic.c sys_generic 10cd54 10d850`, 기록.

182 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 템플릿은 __TEXT,__const, 0x1d10dc–0x1d11ab 전부 0 | Python 바이트(208 B 모두 0) | ✅(섹션 이름 보충) |
| sel->error(+0x154, 32 비트)와 u.u_error(+0x68, 바이트) 구분, selcont 가 u_error 를 부호 확장해 옮김(0x10d471) | sysgen.dis 0x10d469–0x10d47a | ✅ 보충 |
| copyout 은 앞선 실패와 무관하게 3 개 모두 시도, 마지막 값이 u_error 로 | sysgen.dis 0x10d572–0x10d5fb | ✅ 보충(NeXTMach putbits 와 같은 꼴) |
| rwuio volatile 은 후보 | 변형 r1 결과 | ✅(가설로 둠) |
| selscan 의 u_ofile_cnt 경계는 EBADF 없이 break, NULL fp 만 EBADF | sysgen.dis 0x10d697–0x10d6ba | ✅ 보충 |
| 나머지 사실 0–8 | sysgen.dis 대조 | ✅ |
### 182.1 it 결과
- it1(`s5p155-it1`): 11 함수 MATCH, select 는 select_zero 가 __bss 라 MATCH_UNVERIFIED, selcont 는 대기 결과 검사 꼴(원본 `add eax,-2; cmp eax,1; ja`)이 다름. 변형 `s5p155-v2`(u.u_select 직접 접근 — 호출 뒤 다시 읽어 556 B) 불일치, `s5p155-v3` t1(부호 없는 범위 검사)·t3(두 값 비교 if) 차이 0 → t3 채택.
182 결과: it2(`s5p155-it2`, t3 와 `static const struct _select select_zero = { 0 }`) OBJECT_MATCH 14/14(2811 B, __TEXT,__const 208 B 포함). 등급 A(`06_reconstruction/evidence/x86-sys_generic.md`, `.diff`).

## 183. S5-P156 세부 계획 — `bsd/tty_subr.c` (D024, 4.3-Reno 꼴 quote 비트 cblock, 코딩 전, 2026-10-03)

사실(원본 [0x112db0, 0x113746) objects.tsv seq 44; 원본 역어셈블 `ttysubr.dis`; NM 객체 `s5p124l1/out/NM__tty_subr_44.o`; SDK `sys/clist.h`(cblock: c_next, c_quote[CBQSIZE=8], c_info[CBSIZE=52]), `sys/param.h`(CBLOCK 64, CROUND 0x3f, isset/setbit), `sys/tty.h`(TTY_QUOTE 0x100)):
0. 함수(원본/NM): getc 252/188, q_to_b·ndqb·ndflush·nextc 같음, putc 256/168, b_to_q 260/224, 원본에만 nextc3 108(0x113390), unputc 260/196, catq 584/815.
1. 공통: quote 비트 위치 = `(int)cp & CROUND`, 비트맵 = `((struct cblock *)((int)cp & ~CROUND))->c_quote`(isset/setbit 의 부호 있는 /8·%8 꼴, 0x112df3–0x112e1a).
2. getc: `c = *p->c_cf & 0377;` 뒤 quote 비트가 있으면 `c |= TTY_QUOTE`, 그 다음 `p->c_cf++`(0x112de8–0x112e23); 나머지(cblock 반환·cwaiting wakeup)는 같음.
3. putc: 새 cblock(c_cl 없음·c_cc < 0) 할당 때 `bp->c_next = NULL` 뒤 `bzero(bp->c_quote, CBQSIZE)`(0x1131ad), 이어지는 cblock 은 bzero 없음; 쓰기 전 `if (c & TTY_QUOTE) setbit(…, (int)cp & CROUND)`(0x113202–0x113238).
4. b_to_q: 두 할당 자리 모두 `cfreecount -= CBSIZE` 다음 `bzero(bp->c_quote, CBQSIZE)` 뒤 `bp->c_next = NULL`(0x1132af, 0x1132f5).
5. nextc3(p, cp, c): `if (p->c_cc && ++cp != p->c_cl) { if (((int)cp & CROUND) == 0) cp = ((struct cblock *)cp)[-1].c_next->c_info; *c = *cp; quote 이면 *c |= TTY_QUOTE; return (cp); } return (0);`(*c 는 부호 있는 char 값).
6. unputc: `c = *--p->c_cl`(부호 있는 char) 뒤 quote 이면 `c |= TTY_QUOTE`; 두 번째 조건이 `p->c_cl == ((struct cblock *)((int)p->c_cl & ~CROUND))->c_info`(0x11349c–0x1134a9; NeXTMach 의 `== sizeof(bp->c_next)` 대신); 나머지 같음.
7. catq: `to->c_cc == 0` 이면 통째 이동(같음), 아니면 `splx(s); while ((c = getc(from)) >= 0) putc(c, to);`(getc·putc 인라인, NeXTMach 의 bbuf/q_to_b/b_to_q 대신).

방법: NeXTMach `bsd/tty_subr.c` 바탕 + 1–7 작성(D024 표시, nextc3 는 nextc 뒤). 빌드 `iter.py s5p156-itN bsd/kern/tty_subr.c tty_subr 112db0 113748`, 기록.

183 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| getc·putc·b_to_q·nextc3·unputc·catq 의 순서·부호(getc unsigned 0x112deb, nextc3·unputc signed 0x1133b5·0x113430), bzero 위치, unputc 경계 비교, catq 의 인라인 getc/putc | ttysubr.dis 대조 | ✅ |
| q_to_b·ndqb·ndflush·nextc 는 NM 과 같음 | fnsizes 크기 일치(빌드 L1 로 최종) | ✅ |
| 크기는 패딩 포함 범위, catq 는 0x113745 ret, 의미 범위 끝 0x113746 | ttysubr.dis 끝 | ✅ |
183 결과: it1(`s5p156-it1`) OBJECT_MATCH 10/10(2454 B). 등급 A(`06_reconstruction/evidence/x86-tty_subr.md`, `.diff`).

## 184. S5-P157 세부 계획 — `bsd/vfs_dnlc.c` (D024, 인라인 큐 조작·NeXT 심볼릭 링크 캐시 수정, 코딩 전, 2026-10-03)

사실(원본 역어셈블 `dnlc.dis` [0x11b28c, 0x11b984); NM 객체 `s5p124l1/out/NM__vfs_dnlc_55.o`; SDK `sys/dnlc.h`):
0. 원본 범위: 기호 있는 9 함수(init 144, enter 428, lookupSymLink 80, enterSymLink 248, lookup 224, remove 100, purge 88, purge_vp 76, purge1 56) 뒤 기호 없는 정적 함수 dnlc_rm(0x11b830, 172)·dnlc_search(0x11b8dc, 168), 다음 기호 _vno_rw 0x11b984. objects.tsv seq 55 의 text_end 0x11b830 은 purge1 의 끝. 원본에는 insque2/remque2 함수가 없고 `_insque`/`_remque` 호출도 없음.
1. SDK `sys/dnlc.h`: NC_NAMLEN 32(NeXT), INS_LRU/RM_LRU 매크로 없음, INS_HASH/RM_HASH 는 insque/remque. 원본의 ncache 오프셋(name +0x19, cred +0x3c, symLink +0x40, symLinkValid +0x44, symLinkLength +0x46, 크기 0x48)은 SDK 와 맞음.
2. 큐 조작은 모두 인라인: INS_LRU 는 insque2 의미(ncp3 = ncp1->lru_next; ncp1->lru_next = ncp2; ncp2->lru_next = ncp3; ncp3->lru_prev = ncp2; ncp2->lru_prev = ncp1; 0x11b2b7–0x11b2c8), RM_LRU 는 remque2 의미, INS_HASH 는 insque 의미(e->next = p->next; e->prev = p; p->next->prev = e; p->next = e; 0x11b488–0x11b4ac), RM_HASH 는 remque 의미(0x11b3ca–0x11b3d7).
3. dnlc_enterSymLink: `nameLength = pnp->pn_pathlen;` 이 0 이면 바로 return(0x11b524–0x11b52c); 기존 링크 교체 때 `kfree(ncp->symLink, ncp->symLinkLength)`(인자 2 개, 0x11b5a4–0x11b5ad; NeXTMach 는 1 개). lookupSymLink 는 인라인.
4. dnlc_rm·dnlc_search 는 정적(기호 없음)이고 정의 위치(파일 끝 쪽)는 NeXTMach 와 같음.
5. 그 밖(enter·lookup·remove·purge*)은 NeXTMach 흐름과 같음(assert 는 빈 매크로).

방법: NeXTMach `bsd/vfs_dnlc.c` 바탕. 큐 조작은 파일 앞쪽에 정의한 정적 함수(insque2/remque2 와 해시용)로 두고 매크로를 다시 정의해 -O3 인라인을 받게 함(형태는 빌드·변형으로 확정), 3·4 작성(D024 표시). 빌드 `iter.py s5p157-itN bsd/kern/vfs_dnlc.c vfs_dnlc 11b28c 11b984`, 기록(범위 실제 끝).

184 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 함수 범위 11 개, 0x11b830·0x11b8dc 의 호출처가 dnlc_rm·dnlc_search 와 맞음 | dnlc.dis(호출 0x11b381, 0x11b565, 0x11b673 등) | ✅ |
| _insque/_remque·insque2/remque2 호출 없음, 큐 조작 인라인 | dnlc.dis call 목록 | ✅ |
| 해시 삽입 인용 끝은 0x11b4b2(마지막 저장 포함) | dnlc.dis 0x11b4ac 저장 | ✅ 정정(인용 범위만) |
| enterSymLink 의 0 길이 반환·kfree 인자 2 개 | dnlc.dis 0x11b524–0x11b5ad | ✅ |
| ncache 오프셋 SDK 와 맞음, NeXTMach dnlc.h 의 NC_NAMLEN 은 15 | SDK dnlc.h, NeXTMach sys/dnlc.h 비교(diff) | ✅ |
| static 은 가설, 헬퍼는 인라인 후 남지 않아야 함 | 수용 기준에 추가 | ✅ |
### 184.1 it 결과
- it1: 큐 조작은 인라인됨, assert() 가 함수 호출로 컴파일(스테이징에 정의 없음) → `kern/assert.h` import(빈 매크로).
184 결과: it2(`s5p157-it2`) OBJECT_MATCH 11/11(1782 B, 정적 dnlc_rm·dnlc_search 포함), 헬퍼 함수 기호 없음. 등급 A(`06_reconstruction/evidence/x86-vfs_dnlc.md`, `.diff`).

## 185. S5-P158 세부 계획 — `nfs/nfs_xdr.c` (D024, 정적 XDR 보조 루틴, 2026-10-03)

절차 메모: 이 객체는 원인 확인용 스테이징 변형(`s5p158-v1`, `s5p158-v2`)이 07 수정과 빌드(`s5p158-it1`)까지 이어져, 계획·codex 검토가 코딩 뒤가 됨(절차 위반). 기록은 이 계획의 codex 검토와 재검증을 마친 뒤에 함.

사실(원본 [0x13412c, 0x134f94) objects.tsv seq 100; 다음 기호 _authkern_create 0x134f94):
1. 원본 기호는 17 개(xdr_fhandle … xdr_statfs)뿐이고, 나머지 코드는 기호 없는 함수: 0x1341f8(696 B, writeargs 뒤 — xdr_fattr 자리), 0x134924(60 B, diropres 뒤 — xdr_timeval 자리), statfs 뒤 0x134c88(68)·0x134ccc(112)·0x134d3c(300)·0x134e68(48)·0x134e98(228)·0x134f7c(23).
2. NeXTMach 에서 xdr_fattr·xdr_rrok·xdr_sattr·xdr_srok·xdr_drok·xdr_timeval·xdr_fsok 를 static 으로 하면 -O3 에서 큰 xdr_fattr·xdr_timeval 은 정의 자리, 작은 것은 파일 끝으로 지연 출력되고 xdr_sattr 는 인라인됨. 원본의 지연 출력 순서(drok, fsok, rrok, srok, rrokfree, rrokwakeup)는 앞쪽 static 선언의 순서(알파벳순)로 재현됨(변형 a1·a2).
3. 함수 본문은 NeXTMach 와 같음(바이트 비교).

방법·결과: NeXTMach `nfs/nfs_xdr.c` 바탕, 7 개를 static 으로, 파일 앞에 `static bool_t xdr_drok(), xdr_fattr(), xdr_fsok(), xdr_rrok(), xdr_sattr(), xdr_srok(), xdr_timeval();`(작성 표시). it1 OBJECT_MATCH 25/25(3687 B). codex 검토 뒤 기록.

185 codex 검토 판정:
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 기호 없는 8 함수의 대응(fattr, timeval, drok, fsok, rrok, srok, rrokfree, rrokwakeup)과 범위 | 빌드 배치(`s5p158-it1` 기호 순서·크기)가 원본 경계와 같음 | ✅ |
| xdr_sattr 는 saargs·creatargs·slargs 안에 인라인 | 빌드 객체에 xdr_sattr 기호 없음, 세 함수 크기·바이트 일치 | ✅ |
| 범위 밖 직접 호출 없음, 함수 포인터는 __data 표 5 곳(0x1dcd3c–0x1dcd7c) | 내 Python 검색(rel32 호출 모두 범위 안, 절대 참조 0x1dcd3c/4c/5c/6c/7c) | ✅ 보충(포인터 표는 static 과 모순 아님) |
| 소스 차이는 주석·static 선언·static 정의뿐 | diff 출력 | ✅ |
185 결과: it1(`s5p158-it1`) OBJECT_MATCH 25/25(3687 B). 등급 A(`06_reconstruction/evidence/x86-nfs_xdr.md`, `.diff`). 절차 메모는 위에 남김.

## 186. S5-P159 세부 계획 — `nfs/nfs_subr.c` (D024, 정적 보조 함수·NeXT 수정, 코딩 전, 2026-10-03)

사실(원본 역어셈블; 함수 시작은 정렬된 `55 89 e5` 로 찾음; NM 객체 `s5p124l1/out/NM__nfs_subr_97.o`; 스테이징 변형 `s5p159-v1` 은 static 배치 확인용):
0. 실제 범위 [0x12ea98, 0x12fd1c): objects.tsv seq 97 의 text_start 0x12ed7c 앞 0x12ea98(740 B)이 clget(authkern_create·clntkudp_create 호출; authget 인라인), 다음 기호 _rlock_timeout 0x12fd1c. 원본 순서·크기: clget 740, nfs_netboot_prealloc 192, clfree 184, rfscall 1168, vattr_to_sattr 124, setdiropargs 44, setdirgid 60, setdirmode 36, 새 rnode_cache_clear 96(0x12f48c), makenfsnode 428, rp_addhash 136, rp_rmhash 176, rm_free 80, rinactive 36, rfree 100, rfind 328, rinval 424, rflush 96, newname 136, rlock 76, runlock 80. 기호 없는 함수: clget, clfree, rp_addhash, rm_free, rfind → authget·authfree·clget·clfree·rm_free 를 static 으로(rp_addhash·rfind·add_free 는 이미 static) 하면 배치가 원본과 같음(`s5p159-v1`).
1. clfree(0x12ee3c): authfree(cl->cl_auth) 인라인 뒤 `clntkudp_freecred(cl);`(0x12eeac) 추가, 그 다음 `cl->cl_auth = NULL` 과 chtable 루프.
2. vattr_to_sattr(0x12f384): `sa_mode = (va_mode == (u_short)-1) ? -1 : va_mode; sa_uid = (va_uid == (uid_t)-1) ? -1 : va_uid; sa_gid` 같은 꼴(0x12f38e–0x12f3d5), 나머지 같음.
3. rnode_cache_clear()(0x12f48c, 새 전역): `while ((rp = rpfreelist) != NULL) { rpfreelist = rp->r_freef; rm_free(rp); rp_rmhash(rp); rinactive(rp); mfs_uncache(rtov(rp)); zfree(vm_info_zone, rtov(rp)->vm_info); zfree(rnode_zone, rp); }`.
4. makenfsnode: `nfs_cache_check(vp, attr->na_mtime, attr->na_size, 0)`(인자 4 개, 0x12f663–0x12f678).
5. rinval(0x12f9f0): restart 없이 `rpnext = rp->r_hash` 를 먼저 저장, 일치하면 rp_rmhash·VN_HOLD·binvalfree·dnlc_purge_vp 뒤 `if (vp->v_count > 1) rp_addhash(rp);` 그리고 VN_RELE, `rp = rpnext`.
6. newname: `getthetime(&tv); newnum = tv.tv_sec & 0xffff`(0x12fc2d–; 전역 time 대신).
7. 그 밖(rfscall, netboot_prealloc, setdir*, rp_rmhash, rinactive, rfree, rfind, rflush, rlock, runlock)은 NeXTMach 와 같음(빌드 L1 로 확인).

방법: 07 의 NeXTMach 사본에 0–6 작성(D024 표시). 빌드 `iter.py s5p159-itN bsd/nfs/nfs_subr.c nfs_subr 12ea98 12fd1c`, 기록(범위 실제 시작).

186 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 기호 없는 5 함수 범위·정체, 0x12ea98 은 nfs_server 가 아님(netboot 0x12eda6·rfscall 0x12ef44 가 호출) | 프롤로그 경계 Python 목록, `s5p159-v1` 배치 | ✅ |
| 사실 1–6(freecred, -1 처리, rnode_cache_clear 순서, nfs_cache_check 4 인자, rinval, getthetime) | 해당 역어셈블 | ✅ |
| 사실 7 보충: rfscall 원본은 인라인된 clfree 의 freecred 호출(0x12f1fd, 0x12f301) 때문에 NM 과 다름 — clfree 수정의 결과 | 빌드로 확인 예정 | ✅(사실 7 문구 보충) |
| nfs_client.c 의 nfs_cache_check 는 NeXTMach 2 인자 → 그 객체 재구성 때 4 인자 꼴 반영 | NeXTMach nfs_client.c:120 정의 | ✅ 메모 |
### 186.1 it 결과
- it1(`s5p159-it1`): vattr_to_sattr 116/124(삼항식 → if/else 문으로), rfscall 1184/1168 — 원본은 실패 경로에서 CLNT_GETERR 를 부르지 않음(0x12f0ce–0x12f0db; `#else NeXT` 로 옮김). it3: rnode_cache_clear 92/96 — `rpfreelist = rpfreelist->r_freef`(다시 읽음). 
186 결과: it4(`s5p159-it4`) __text 4739 B 차이 0(20 MATCH, newname 은 static newnum 의 __bss 때문에 MATCH_UNVERIFIED). __bss 4 B 는 0x1e59b0 로 참조 추정(`s5p159-zerofill-check-nfs_subr-20261002.json`) → 등급 P, known 배치 `zerofill-known-s5p159-20261002.json`(23 항목, 겹침 0). 기록 `06_reconstruction/evidence/x86-nfs_subr.md`.

## 187. S5-P160 세부 계획 — `bsd/uipc_socket2.c` (D024, 스레드 select 캐시, 코딩 전, 2026-10-03)

배경: 진단 13 의 NeXTMach 컴파일 실패 54 건(`s5p124-diag-13/stage/_log`)은 대부분 OPENSTEP 헤더·API 차이다. 그중 select 관련(uipc_socket2 의 sbselqueue, fifo_vnodeops 의 fifo_select, tty_pty 의 ptcselect)은 plan 182 의 새 select 모델(selthreadcache/selthreadclear)과 이어진다.

사실(원본 [0x116120, 0x116db4) objects.tsv seq 50, 24 함수; 원본 역어셈블):
1. sbselqueue(0x1163f8): `if (selthreadcache(&sb->sb_sel)) sb->sb_flags |= SB_COLL;`(sb_sel +0x10, SB_COLL 0x10). NeXTMach 의 thread_t 캐스트·wait_event 비교·current_thread 대입 대신(이것이 진단 13 컴파일 실패 원인 — thread_t 미선언).
2. sbwakeup(0x116430): `s = splimp(); if (sb->sb_sel) { selwakeup(sb->sb_sel, sb->sb_flags & SB_COLL); selthreadclear(&sb->sb_sel); sb->sb_flags &= ~SB_COLL; } splx(s);` 그 뒤 SB_WAIT·nfs_wakeup_one_nfsd 처리는 NeXTMach 와 같음.
3. 나머지 22 함수는 컴파일 뒤 원본과 대조(차이는 it 결과에 기록).

방법: NeXTMach `bsd/uipc_socket2.c` 바탕 + 1·2 작성(D024 표시). 빌드 `iter.py s5p160-itN bsd/kern/uipc_socket2.c uipc_socket2 116120 116db4`, 기록.

187 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 내 누락: sbrelease 가 sbflush·hiwat/mbmax 0 뒤 `s = splimp(); if (sb->sb_sel) selthreadclear(&sb->sb_sel); splx(s);`(0x1165e6–0x116603), SB_COLL 은 지우지 않음 | 역어셈블 0x1165cc–0x116610, NeXTMach :402–:408 | ✅ 채택 — 사실 3 추가 |
| 사실 1·2(오프셋 sb_sel +0x10, sb_flags +0x14, SB_COLL 0x10, SB_WAIT 4; sbwakeup 의 splimp 범위) | 역어셈블 0x1163f8–0x11649a | ✅ |
| 나머지 21 함수 문장 차이 없음, sowakeup 은 고친 sbwakeup 인라인 | 빌드 L1 로 판정 | ⚖️ |
### 187.1 it 결과
- it1(`s5p160-it1`): soqinsque 56/92 — 원본은 원형 큐의 꼬리까지 가서 넣음(0x116313–0x116326). it2: for 루프 꼴(88). it3: `prev = head` 를 분기 앞에서 한 번, while 순회 → 일치(작성 표시 `plan 187.1`).
187 결과: it3(`s5p160-it3`) OBJECT_MATCH 24/24(3217 B). 등급 A(`06_reconstruction/evidence/x86-uipc_socket2.md`, `.diff`).

## 188. S5-P161 세부 계획 — `specfs/fifo_vnodeops.c` (D024, 스레드 select 캐시·vn_devblocksize, 코딩 전, 2026-10-03)

사실(원본; objects.tsv seq 122 는 기호 있는 `_fifosp` 0x1394f0 만 표시, 실제 범위는 정적 함수 포함 [0x138ad0, 0x1395d8) — 앞 0x138a90 `_xdr_fhstatus` 64 B 는 mountxdr, 다음 기호 `_bdevvp` 0x1395d8):
0. 원본 함수(정렬된 프롤로그): fifo_open 300, fifo_close 344, fifo_rdwr 1388, fifo_getattr 112, fifo_select 160, fifo_inactive 80, fifo_cmp 24, fifo_invalop 12, fifo_badop 20, fifo_bufalloc 152, fifosp 112, fifo_buffree 108, 새 정적 함수 0x1395cc(12 B, `return 0x400`). 순서는 NeXTMach 와 같음.
1. fifo_select(0x139330): FREAD — `fn_size != 0` 이면 1, 아니면 `if (selthreadcache(&fp->fn_rsel)) fp->fn_flag |= FIFO_RCOLL;` FWRITE — `fn_size < PIPE_BUF && fn_rcnt > 0` 이면 1, 아니면 fn_wsel/FIFO_WCOLL; 0 — `fn_rcnt == 0` 이면 1, 아니면 **fn_xsel**/FIFO_XCOLL(NeXTMach 는 fn_wsel 을 검사). 진단 13 의 컴파일 실패 원인(struct thread 불완전)이 이 함수.
2. fifo_vnodeops 표(0x1dd4b4)에 33 번째 항목 0x1395cc(SDK `sys/vnode.h` 의 NeXT `vn_devblocksize`); vn_prepagein·vn_apageout 은 0. SUN_LOCK 자리는 spec_lockctl.
3. 0x1395cc 는 표에서만 참조(rel32 호출 0) → 정적 `fifo_devblocksize()` 로 작성, 반환값 0x400(DEV_BSIZE 512 와 다름 — 이름 없는 상수로).
4. 나머지 함수(특히 select 깨움이 있는 fifo_rdwr·fifo_close·fifo_inactive)는 컴파일 뒤 대조(selwakeup 뒤 selthreadclear 꼴 가능성).

방법: NeXTMach `specfs/fifo_vnodeops.c` 바탕 + 1–3 작성(D024 표시). 빌드 `iter.py s5p161-itN bsd/specfs/fifo_vnodeops.c fifo_vnodeops 138ad0 1395d8`, 기록(범위 실제 시작).

188 codex 검토 판정(코딩 전) — 내 계획이 놓친 차이 다수:
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| fifo_close: 마지막 reader 닫을 때 fn_xsel 을 selwakeup 뒤 thread_deallocate·0, 이어 fn_wsel·fn_rsel 도 있으면 thread_deallocate·0(깨우지 않음) | 역어셈블 0x138c57–0x138cb6 | ✅ 채택 |
| fifo_rdwr: 쓰기 쪽 selwakeup 뒤 fn_rsel thread_deallocate·0(0x138fe4–0x138ff9), 읽기 쪽 FIFO_WBLK 해제 때 wakeup(&fn_wcnt)(0x139243–0x139251) 와 fn_wsel selwakeup·thread_deallocate·0(0x13926b–0x139280) | 역어셈블 해당 구간 | ✅ 채택 |
| fifo_rdwr: 비차단 빈 읽기는 p_posix 이면 EAGAIN(11) 아니면 EWOULDBLOCK(35)(0x139066–0x13908e) | 역어셈블, SDK errno.h :44/:88 | ✅ 채택 |
| fifo_bufalloc 는 kmem_alloc_wired(0x1394d9) | 역어셈블 | ✅ 채택(NeXTMach 의 kmem_alloc 대신) |
| fifosp: kalloc(0x8c) 뒤 bzero(fp, 0x8c)(0x139507–0x13950d) | 역어셈블 | ✅ 채택 |
| selthreadclear 가 아니라 직접 thread_deallocate | 역어셈블(selthreadclear 호출 없음) | ✅(사실 4 정정) |
| 0x400 의 이름은 정할 수 없음(DIRBLKSIZ 1024 는 뜻이 다름; NeXT 분기에는 DEV_BSIZE 없음) | SDK param.h :218–:226 | ✅ 상수로 |

### 188.1 it 결과
- it1(`s5p161-it1`): fifo_rdwr 1456 vs 1388, fifo_bufalloc 140 vs 152, 나머지 일치.
- it2: 쓰기 쪽 FNDELAY 분기에서 ocnt 검사 제거(원본은 공유 EWOULDBLOCK/EAGAIN 블록으로 바로 감), `kmem_alloc_wired(kernel_map, &addr, ...)`.
- 변형 `s5p161-v1`(w1: `count = uio_resid` 를 루프 앞에서 읽고 wrloop 에서만 다시 읽음) 채택; `s5p161-v2`(EAGAIN 꼴 t1 삼항 / t2 if-else) 두 꼴 모두 차이 0 → 진단 13 형식에 가까운 t2 채택.
- it3: bufalloc 차이 남음 → 반환 순서.
- it4(`s5p161-it4`): `fp->fn_nbuf++` 뒤 `return addr` → OBJECT_MATCH 13/13(2824 B, `__data` 의 fifo_vnodeops 33 항목 포함).

### 188.2 확인
- POSIX_KERN·_POSIX_SOURCE 없는 진단 컴파일(`s5p161-noposix`) 종료 0.

188 결과: it4 OBJECT_MATCH 13/13. 등급 A(`06_reconstruction/evidence/x86-fifo_vnodeops.md`, `.diff`). `_fifo_devblocksize` 는 D024 작성(이름 미복원).

## 189. S5-P162 세부 계획 — `bsd/kern/tty_pty.c` (D024, pty 표 지연 할당·스레드 select 캐시·POSIX, 코딩 전, 2026-10-03)

사실(원본 [0x111c00, 0x112db0), objects.tsv seq 43; 앞 0x111bf4 `_nullioctl` 은 tty_conf, 다음 0x112db0 `_getc` 는 tty_subr; 역어셈블 `odis.py 111c00 112db0`):
0. 함수(크기, B): pty_init 20, pty_alloc 112, ptsopen 304, ptsclose 80, ptsread 396, ptswrite 64, ptsselect 44, ptsstart 64, ptcwakeup 176, ptcopen 244, ptcclose 236, ptcread 576, ptsstop 264, ptcselect 240, ptcwrite 560, ptyioctl 1148. NeXTMach 의 `pts_process_putc`·`ptsputc`·`ptsputcbuf` 는 없음(기호·코드 없음). `_npty`·`_pt_tty`·`_pt_ioctl` 기호 없음.
1. 고정 배열 pt_tty/pt_ioctl/pt_soft 대신 기호 없는 `__bss` 표 0x1e56c8(16 B × 32; minor >= 0x20 이면 ENXIO, generated `pty.h` NPTY 32): +0 `dev_t` slavedev, +4 flags(PS_OPEN 1), +8 `struct tty *`, +0xc `struct pt_ioctl *`. 정적 배열 `pt_soft[NPTY]` 로 둠(필드 이름 미복원 → `ps_tty`·`ps_ioctl`).
2. `pty_init()`: `lock_init(&pty_alloc_lock, TRUE)`; `_pty_alloc_lock` 은 `__common`(0x1e98c0) → 초기화 없는 전역 `lock_data_t pty_alloc_lock;`.
3. `pty_alloc(dev)`(전역, ptsopen·ptcopen 에 인라인): psp=&pt_soft[minor(dev)]; ps_tty 있으면 psp 반환; 아니면 lock_write → 다시 검사 → `ps_tty = kalloc(sizeof (struct tty)=0x88); bzero; ps_ioctl = kalloc(sizeof (struct pt_ioctl)=0x10); bzero` → lock_done → psp 반환.
4. ptsopen: ENXIO 검사 뒤 psp=pty_alloc(dev); tp=psp->ps_tty; `psp->ps_slavedev = dev`; 나머지 NeXTMach 와 같음(성공 시 `ps_flags |= PS_OPEN`, ptcwakeup(tp, FREAD|FWRITE)).
5. ptsclose: psp=&pt_soft[minor]; tp=psp->ps_tty; 나머지 같음. ptswrite·ptsselect: tp=pt_soft[minor].ps_tty, 본문 같음.
6. ptsread: PF_REMOTE 경로의 백그라운드 검사가 POSIX 꼴 — `p=u.u_procp; while (tp == u.u_ttyp && p->p_pgrp != tp->t_pgrp)` 안에서 `if (p->p_posix) { px=get_posix_proc(p->p_pid); if (sigignore&TTIN || sigmask&TTIN || px->p_posix_pgrp->pg_jobc == 0) return EIO; } else if (sigignore||sigmask||p_flag&SVFORK) return EIO;` 뒤 gsignal(u.u_procp->p_pgrp, SIGTTIN); sleep(&lbolt, TTIPRI). `TS_NBIO` 빈 canq 는 p_posix 이면 EAGAIN 아니면 EWOULDBLOCK.
7. ptsstart·ptcwakeup·ptsstop: pti=pt_soft[minor(tp->t_dev)].ps_ioctl 뒤 **`tp->t_dev == 0` 이면 바로 반환**(16 비트 `test dx,dx`). ptcwakeup: FREAD 면 `s=spltty(); if (pti->pt_selr) { selwakeup(pti->pt_selr, pt_flags&PF_RCOLL); selthreadclear(&pti->pt_selr); pt_flags &= ~PF_RCOLL; } splx(s); wakeup(&t_outq.c_cf);` FWRITE 도 같은 꼴(pt_selw, PF_WCOLL, &t_rawq.c_cf). pt_selr/pt_selw 형은 thread 포인터(`struct thread *`). ptsstop 는 ptcwakeup 인라인.
8. ptcopen: ENXIO 뒤 tp=pty_alloc(dev)->ps_tty; t_oproc 있으면 EIO; 나머지 NeXTMach 와 같고, 끝에 pti(=pt_soft[minor].ps_ioctl 재조회) `pt_flags=0; pt_send=0; pt_ucntl=0; pt_selw=0; pt_selr=0;`.
9. ptcclose: l_modem(tp,0); PS_OPEN 이면 forceclose(ps_slavedev)·ptsclose(ps_slavedev)(인라인); 그 뒤 새로 `s=spltty(); if (pti->pt_selr) selthreadclear(&pti->pt_selr); if (pti->pt_selw) selthreadclear(&pti->pt_selw); splx(s);` `t_oproc = 0;` 그리고 `ttynty(tp)->t_session = 0`(nty +8, POSIX_KERN 필드).
10. ptcread: NeXTMach 와 같되 PF_NBIO 는 POSIX EAGAIN/EWOULDBLOCK, 끝 t_wsel 깨움은 `selwakeup(tp->t_wsel, t_state&TS_WCOLL); thread_deallocate(tp->t_wsel); tp->t_wsel = 0; t_state &= ~TS_WCOLL;`.
11. ptcselect: NeXTMach 의 wait_event 비교 대신 `if (selthreadcache(&pti->pt_selr)) pt_flags |= PF_RCOLL;`(FREAD·0) 와 pt_selw/PF_WCOLL(FWRITE). 나머지 같음.
12. ptcwrite: 첫머리에서 `iov = uio->uio_iov` 를 읽음(원본 0x11271d), 비차단 반환은 cnt==0 이면 POSIX EAGAIN/EWOULDBLOCK. 나머지 같음(edi=0 초기화의 원천은 반복에서 확인).
13. ptyioctl: TIOCEXT(인자 하나 ptcwakeup(tp) 그대로)·l_kind·UIOCCMD 같음. 바뀐 점 — ptc 전용 switch 의 큐 비우기에 TIOCSETA/TIOCSETAW/TIOCSETAF(0x80247414–16) 추가; EXTPROC·PF_PKT 의 TIOCPKT_IOCTL 대상에도 같은 셋 추가; `stop` 계산에 `(ttynty(tp)->t_pflags & TP_IXON)` 추가(`stop=0` 뒤 조건 만족 시 1).
14. 이 객체에 `__data` 없음; `__bss` 표(1)는 zerofill 검사로 배치 판단.

방법: NeXTMach `bsd/tty_pty.c` 를 `07_kernel/src/bsd/kern/tty_pty.c` 로 들여와 1–13 을 D024 표시로 작성(`ptsputc`·`pts_process_putc` 는 `#if 0`/제거 근거 기록). 빌드 `iter.py s5p162-itN bsd/kern/tty_pty.c tty_pty 111c00 112db0`, POSIX 없는 진단 컴파일, 기록.

189 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–13 의 함수 경계·표 배치·POSIX·select·ioctl 목록 확인 | 같은 역어셈블(`pty.dis`) 을 내가 이미 읽어 사실을 적음; ioctl 값은 SDK `ioctl.h:183–350` 매크로로 python 재계산(TIOCSETA* = 0x80247414–16, termios 36 B) | ✅(새 내용 없음) |
| ptcwrite 의 l_rint 인자는 movzx(0 확장) — `char *cp` 와 맞지 않음 | `pty.dis` 0x112897 `movzx edx, byte ptr [edi]`; 같은 파일의 t_line 은 movsx(부호 있는 char) | ✅ → darwin01 `tty_pty.c:602,604` 의 `register u_char *cp = NULL; u_char locbuf[BUFSIZ];` 꼴로 작성(D024, 선언 형태만 참고). 이 꼴은 0x112725 `xor edi,edi`(cp = NULL) 도 설명 |
| `xor edi,edi` 는 원천 불명 | 위 행 | ⚖️ 원천을 내가 찾음(cp = NULL) — 빌드로 확인 |
| ptsopen 에서 ps_slavedev 저장(0x111d0a)이 열림 검사보다 앞 | `pty.dis` 0x111d07–0x111d0a | ✅(사실 4 와 같음) |
| t_dev 가드는 `== 0` 반환/`if (t_dev)` 블록 구별 불가 | 0x112013·0x112055·0x11252b `test dx,dx` | ✅ — 빌드로 꼴 선택 |
| selthreadcache 는 오래된 스레드를 내부에서 놓음 | 의미 설명, 행동 안 바뀜 | ⏭️ |
| 사실 0·14 의 "없음" 은 링크된 이미지만으로 객체 수준 증명 불가 | 맞는 한정(기호 없는 정적 자료 가능) — OBJECT_MATCH 대조에서 `__data` 가 생기지 않으면 일치로 판단 | ⚖️ 문구 한정 |
| 할당 실패 검사 없음 | 0x111c48–0x111c68 kalloc 뒤 바로 bzero | ✅(작성 시 검사 넣지 않음) |

### 189.1 it 결과
- it1(`s5p162-it1`): 16 함수 중 13 크기 일치. ptcclose 232 vs 236(원본은 pti 를 psp 보다 먼저 표에서 직접 읽음), ptsstop 268 vs 264(인라인 ptcwakeup 의 두 방향이 각자 `s` 를 가져야 둘째가 esi), ptyioctl 1145 vs 1148 은 객체 끝 정렬 3 B.
- it2(`s5p162-it2`): `pti = pt_soft[minor(dev)].ps_ioctl` 선언 초기화, 방향별 `int s = spltty();` → 16 함수 모두 MATCH_UNVERIFIED(기호 없는 `__bss` 참조만 남음), L1 사유 `__DATA,__bss: unverified` 하나.
- zerofill: reference-inferred [0x1e56c8, 0x1e58c8) 512 B, 참조 25, Delta 하나(0x1e4518), 음성 검사 검출(`09_validation/reconstruction/s5p162-zerofill-check-tty_pty-20261002.json`); 알려진 배치 24 건(`zerofill-known-s5p162-20261002.json`).
- POSIX_KERN 없는 진단 컴파일(`s5p162-noposix`) 종료 0.

189 결과: 등급 P(`__bss` 만 참조 추론; `06_reconstruction/evidence/x86-tty_pty.md`, `.diff`). darwin01 은 ptcwrite 의 `u_char *cp = NULL`·`u_char locbuf` 선언 꼴만 참고(MODIFICATIONS 에 기록).

## 190. S5-P163 세부 계획 — `bsd/rpc/pmap_kgetport.c`·`bsd/rpc/pmap_prot.c` (커널용 `rpc/pmap_prot.h`, 코딩 전, 2026-10-03)

사실:
0. 진단 13 실패 원인(`08_build/runs/s5p124-diag-13/stage/_log/66.err`, `67.err`): `struct portmap` 불완전형. `--bsd-set nextos` 는 SDK `Headers/bsd/rpc/pmap_prot.h` 를 읽는데, 그 사본에는 사용자용 `struct pmap` 만 있고 NeXTMach `rpc/pmap_prot.h:63–85` 의 `#ifdef KERNEL struct portmap` 분기가 없음(두 파일 diff 로 확인; 나머지는 주석 차이).
1. 원본 pmap_kgetport [0x135df4, 0x1360c0): `_pmap_kgetport` 284 B, `_getport_loop` 432 B(pmap_kgetport 인라인); pmap_prot [0x1360c0, 0x136114): `_xdr_pmap` 84 B(그 뒤 0x136114 `_xdr_rmtcall_args` 는 pmap_rmt). 역어셈블(`odis.py 135df4 136114`)은 NeXTMach 본문과 문장 단위로 같아 보임: cred 초기화(cr_ref 0 이면 NGROUPS 16 개 NOGROUP, 역순 루프), tmpaddr 복사, htons(PMAPPORT 111), clntkudp_create(.., 100000, 2, 4, &cred), CLNT_CALL(3, xdr_pmap, xdr_u_short, tottimeout), 오류 1/-1, AUTH_DESTROY·CLNT_DESTROY; getport_loop 의 ISSIG·printf 세 개.
2. `static struct ucred cred` 는 기호 없는 `__bss`(0x1e59f0 부근) → zerofill 검사 대상; `tottimeout` 은 `__data`.
3. 07 의 다른 소스 중 `rpc/pmap_prot.h` 를 쓰는 것은 없음(전수 grep: NeXTMach 의 pmap_prot.c·pmap_krmt.c·pmap_kgetport.c·pmap_rmt.c·nfs/nfs_vfsops.c 만) → 규칙 변경이 기록된 객체에 영향 없음.

방법:
a. `rpc/pmap_prot.h` 를 `stage_headers.py` 의 `KERNEL_STRIPPED`(SDK 사본에 커널 부분이 없는 이름, plan 83.1 선례)에 넣고, NeXTMach `mk-108.1/rpc/pmap_prot.h` 를 `07_kernel/nextmach/rpc/pmap_prot.h` 로 그대로 들임(PROVENANCE 기록).
b. 두 소스는 NeXTMach 그대로 07 로 들여 빌드(`iter.py s5p163-itN bsd/rpc/pmap_kgetport.c pmap_kgetport 135df4 1360c0`, `... bsd/rpc/pmap_prot.c pmap_prot 1360c0 136114`). 차이가 나면 그때 원본 바이트로 고침.

190 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 66.err 에는 struct portmap 외에 :137 ISSIG 오류 둘과 :85 clntkudp_create 경고가 더 있음 | `66.err` 전문을 엶: `:137 invalid type argument of '->'` ×2, `:85 warning: assignment makes pointer from integer` | ✅ 사실 0 정정. ISSIG 는 SDK `sys/param.h` NeXT 분기의 `current_thread()->_uthread` 때문 → `#import <kern/thread.h>` 추가(같은 import 가 NeXTMach `nfs/nfs_subr.c:59`, 07 netisr.c:33·sys_generic.c:61 에 있음). 경고는 암묵 선언 int 반환이라 코드는 같음 → 그대로 둠 |
| ISSIG 전개는 SDK 의 `issig(0)` 와 맞음(0x136071 push 0) | SDK param.h NeXT 분기 `issig(0)` 를 엶; `pmap.dis` 0x13606f `push 0` | ✅ (SDK 헤더로 빌드하므로 그대로) |
| 문자열·{1,0}·ucred(+0xa, 16 개)·인자 순서 일치 | python 으로 0x1dd0d8–0x1dd13d 바이트, 0x1e59fa = cred+0xa 확인 | ✅ |
| `__bss` 초기값은 파일 오프셋으로 알 수 없음 | 맞음(내 계획은 초기값을 주장하지 않음) | ⏭️ |
| KERNEL_STRIPPED 는 전역이라 nfs_vfsops·pmap_krmt·pmap_rmt 에도 적용 | NeXTMach 의 그 파일들은 `struct portmap` 을 쓰는 커널 소스(전수 grep 결과 같음) → 오히려 필요한 쪽 | ⚖️ 영향은 인정, 그 객체들 작업 때 다시 확인 |
| pmaplist·xdr_pmaplist 선언 차이는 검증 안 됨 | 이 두 객체는 그 이름을 쓰지 않음 | ⏭️ |

### 190.1 결과
- `stage_headers.py` `KERNEL_STRIPPED` 에 `rpc/pmap_prot.h` 추가; `07_kernel/nextmach/rpc/pmap_prot.h` 는 NeXTMach 원문 그대로(SHA-256 52606bbb…, PROVENANCE 행 추가).
- pmap_prot(`s5p163-p1`): NeXTMach 원문 그대로 OBJECT_MATCH 1/1 → 등급 A.
- pmap_kgetport(`s5p163-it1`): `#import <kern/thread.h>` 만 추가, 두 함수와 `__data` 일치, L1 사유 `__bss: unverified` 하나; zerofill reference-inferred [0x1e59f0, 0x1e5a1a) 42 B(= sizeof (struct ucred), python), 참조 8, Delta 하나, 음성 검사 검출; 알려진 배치 25 건(`zerofill-known-s5p163-20261002.json`) → 등급 P.

190 결과: pmap_prot A, pmap_kgetport P.

## 191. S5-P164 세부 계획 — `bsd/rpc/clnt_kudp.c` (D024, cred 참조 계수·getthetime, 코딩 전, 2026-10-03)

사실(원본 [0x135330, 0x135dbc), 코드 끝 0x135dba; objects.tsv seq 103; 다음 0x135dbc `_clnt_sperrno` 는 clnt_perror):
0. 진단 13 실패(`65.err`): `current_thread()->allocInProgress` 에서 struct thread 불완전형(:213, :275, :280) → `#import <kern/thread.h>`(SDK kern/thread.h:247 `allocInProgress`). kfree 경고는 코드에 영향 없음.
1. 진단 빌드 `s5p164-d2`(07 아님: NeXTMach 원문 + 스테이징 사본에만 import 한 줄): once 32, interruptable 40, realloc 56, callit_addr 1584, callit 48, ckuwakeup 28, error 36, freeres 40, abort 8, control 12, destroy 48 은 크기 일치. 차이: clntkudp_create 404 vs 384, clntkudp_init 64 vs 60, `_clntkudp_freecred` 36(원본에만). 정적 bindresvport 216·noop 8·buffree 38 은 원본 0x135cb4·0x135d8c·0x135d94 의 정렬 프롤로그(크기 216, 8, 40=38+채움)와 순서·크기 일치(python).
2. clntkudp_create: `if (!clntkudpxid)` 안이 `time.tv_usec` 대신 지역 timeval 에 `getthetime(&tv)` 뒤 `clntkudpxid = tv.tv_usec`(0x1353eb–0x1353f7); bad 경로는 `kfree(cku_outbuf, UDPMSGSIZE)` 뒤 **`crfree(p->cku_cred)`**, 그 뒤 `kfree(p, sizeof *p)`(0x135519–0x135533).
3. clntkudp_init: `p->cku_cred = cred;` 뒤 **`crhold(cred)`**(0x135581 근처 `inc word ptr [ecx]`), 그 뒤 flags 마스크.
4. 새 전역 `clntkudp_freecred(h)`(0x135584, init 과 callit_addr 사이): `p = htop(h); crfree(p->cku_cred); p->cku_cred = (struct ucred *)0xefefefef;`(독 값, 이름 미복원). nfs_subr 의 clfree 가 이것을 부름(plan 186).
5. clntkudp_destroy 는 NeXTMach 와 같음(soclose, kfree 두 번; crfree 없음).

방법: NeXTMach `rpc/clnt_kudp.c` 를 07 로 들여 import 추가와 2–4 를 D024 표시로 작성. 빌드 `iter.py s5p164-itN bsd/rpc/clnt_kudp.c clnt_kudp 135330 135dbc`, 기록.
6. 절차 기록: 첫 진단 실행 `s5p164-d1`(REGISTRY 500 행)은 import 한 kern/thread.h 가 스테이징되지 않아 컴파일 실패(로그만 있음)했고, 재실행하려고 내가 그 실행 디렉터리 `08_build/runs/s5p164-d1/` 를 지웠음(ID 는 재사용되지 않아 재실행은 `s5p164-d2`). 지운 것은 실패 로그뿐이며 결과에 쓰이지 않음.

191 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 계획에 없는 문장 차이 없음; 같은 크기 14 함수는 비재배치 바이트·재배치 일치 | 내 rdiff(모양 비교) 14 함수 모두 차이 0; 상수까지는 최종 cmpobj 로 확인 | ⚖️ 모양은 확인, 상수는 빌드 대조로 |
| init: 0x135571 cku_cred 저장, 0x135574 `inc word ptr [ecx]` | `odis.py 135544 135584` 같은 주소 확인(계획의 "0x135581 근처" 는 부정확 → 0x135574 로 정정) | ✅ |
| crhold 는 `ucred.h:27` | 연 결과 :29(`#define crhold(cr) (cr)->cr_ref++`), :27 은 빈 줄 | ⚖️ 사실은 맞고 줄번호 틀림(:29) |
| callit_addr 에 getthetime·time 읽기 없음 | 패턴 검색 1 건은 0x135b18 `push 0x1e8df0 ; _lbolt`(time 은 0x1dee38) | ✅ |
| create 의 getthetime·bad 경로 crfree, freecred, destroy 무변경 | 사실 2·4·5 와 같은 주소(내 역어셈블) | ✅ |

191 결과: it1(`s5p164-it1`) OBJECT_MATCH 17/17(`__data` 포함). 등급 A(`06_reconstruction/evidence/x86-clnt_kudp.md`, `.diff`).

## 192. S5-P165 세부 계획 — `bsd/rpc/svc.c` (커널용 `rpc/svc.h`, 기록 객체 6 개 회귀 확인, 코딩 전, 2026-10-03)

사실:
0. 진단 13 실패(`68.err`): svc.c:510–511 `xprt->xp_sock` — SDK `Headers/bsd/rpc/svc.h:48` 은 `int xp_sock;`(정수라 `->` 불가), NeXTMach `rpc/svc.h` 는 `#ifdef KERNEL struct socket *xp_sock; #else int xp_sock; #endif`(같은 4 B 자리). [정정: 처음에 SDK 쪽을 `xp_fd` 로 잘못 적음 — 스테이징 사본 `s5p165-b0-stage/src/bsd/rpc/svc.h:48` 을 열어 확인] 그 밖의 차이는 주석과 `#ifndef KERNEL` 로 감싼 사용자용 선언들, 커널 쪽 `extern SVCXPRT *svckudp_create();`(diff 로 확인).
1. 진단 빌드 `s5p165-d1`(SDK svc.h): 같은 오류 재현. `s5p165-d2`(스테이징 사본의 svc.h 만 NeXTMach 것으로 바꿈, 07·도구 무변경): 컴파일 성공, 13 함수(기호 없는 정적 svc_find 0x136e88 포함) 모양 차이 0, 크기 일치(fnsizes 의 unregister 132 는 뒤따르는 svc_find 60 을 합친 값, python 72+60).
2. 원본 [0x136ddc, 0x137340): 다음 0x137340 `__authenticate` 는 svc_auth. `static SVCXPRT **xports`·`svc_head` 는 기호 없는 `__bss`(0x1e5a1c 등) → zerofill 검사.
3. 07 의 155 개 .c 를 `stage_headers.py --list`(현재 옵션)로 훑은 결과 `rpc/svc.h` 를 폐포에 넣는 기록 객체는 6 개: nfs/nfs_export.c, rpc/rpc_callmsg.c, rpc/rpc_prot.c, rpc/svc_auth.c, rpc/svc_auth_unix.c, rpc/svc_kudp.c. (같은 훑기로 `rpc/pmap_prot.h` 는 pmap_kgetport·pmap_prot 둘뿐 — plan 190 사실 3 재확인.)

방법:
a. `KERNEL_STRIPPED` 에 `rpc/svc.h` 추가, NeXTMach `rpc/svc.h` 를 `07_kernel/nextmach/rpc/svc.h` 로 그대로 들임(PROVENANCE).
b. 사실 3 의 6 객체를 새 규칙으로 다시 빌드해 각자의 기록 등급(OBJECT_MATCH 또는 `__bss` 만 미검증)이 유지되는지 확인. 하나라도 깨지면 규칙 변경을 되돌리고 대안(07_kernel/nextdev_private 의 작성 헤더)을 사용자 결정 없이 고르지 않고 원인부터 기록.
c. svc.c 는 NeXTMach 원문 그대로 07 로 들여 `iter.py s5p165-itN bsd/rpc/svc.c svc 136ddc 137340`, zerofill, 기록.
- 기준선(규칙 변경 전) `s5p165-b0`: 현재 규칙으로 svc_kudp 재빌드 OBJECT_MATCH 11/11(`__data` 포함) — svc_kudp 는 `xp_sock` 을 대입·인자로만 써서 int 로도 컴파일됨.

192 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| SDK svc.h:48 은 `int xp_sock` (xp_fd 아님) | 스테이징 사본·07_kernel/nextdev 사본 :48 을 엶 | ✅ (codex 회신 전에 내가 이미 정정) |
| xports 는 `#else KERNEL` 쪽이라 커널에 저장소 없음; `__bss` 는 svc_head(0x1e5a1c) 하나 | NeXTMach svc.c:25–48 을 엶(:41 `#else KERNEL`, :47 xports, :48 `#endif`) | ✅ 사실 2 정정 |
| rqcred_head·Rpccnt 는 기호 있음 | symbols.tsv `_Rpccnt` 0x1ef1e0, `_rqcred_head` 0x1ef1e4 | ✅ |
| 진단 객체는 원본과 비재배치 바이트·재배치 대상 일치 | 내 rdiff 13 함수 모양 0; 상수까지는 07 빌드 대조로 | ⚖️ |
| KERNEL 에서 숨는 선언들은 6 객체에서 안 쓰임 | 내 python 훑기(숨는 9 이름 × 6 파일 사용 0) | ✅ (회귀 빌드로 확정) |
| 수용 조건: 6 객체 기록 결과 유지 + 스테이징 manifest 가 07 NeXTMach 헤더를 골랐는지 | 방법 b 에 추가 | ✅ 채택 |

### 192.1 결과
- `KERNEL_STRIPPED` 에 `rpc/svc.h` 추가, `07_kernel/nextmach/rpc/svc.h` NeXTMach 원문(SHA-256 e10fdcb5…, PROVENANCE).
- 회귀(새 규칙): svc_auth `s5p165-r1`, svc_auth_unix `r2`, rpc_prot `r3`, rpc_callmsg `r4`, nfs_export `r5`, svc_kudp `r6` 모두 OBJECT_MATCH; 여섯 스테이징의 svc.h SHA-256 이 모두 e10fdcb5…(07 NeXTMach 사본).
- svc(`s5p165-it1`): NeXTMach 원문 그대로, 13 함수 일치, L1 사유 `__bss: unverified` 하나; zerofill reference-inferred [0x1e5a1c, 0x1e5a20) 4 B(svc_head), 참조 5, Delta 하나, 음성 검사 검출; 알려진 배치 26 건(`zerofill-known-s5p165-20261002.json`). 기록 도구가 폐포의 `nextmach/sys/features.h`·SDK `rpc/pmap_clnt.h` 를 들임(PROVENANCE).

192 결과: svc 등급 P.

## 193. S5-P166 세부 계획 — `bsd/nfs/nfs_common.c` (D024, NFSTSIZE·-1 uid/gid, 코딩 전, 2026-10-03)

사실(원본 [0x12c808, 0x12c8ec), objects.tsv seq 94; 다음 0x12c8ec `_exportfs` 는 nfs_export):
0. 진단 13 실패(`58.err`): ECTSIZE·IETSIZE 미정의 — SDK `nfs/nfs.h:26–33` 의 NeXT 분기는 `#define NFSTSIZE 8192` 만 두고 ECTSIZE/IETSIZE 는 `#else` 쪽.
1. `_nfstsize`(12 B, 0x12c808): `mov eax, 0x2000; ret` — 루프 없이 NFSTSIZE(8192 = 0x2000, python) 반환.
2. `_vattr_to_nattr`(216 B, 0x12c814): 저장 순서는 NeXTMach 와 같음(type, mode, uid, gid, fsid, nodeid, nlink, size, atime, mtime, ctime, rdev, blocks, blocksize, VFIFO 면 NA_SETFIFO). 다른 점은 mode·uid·gid: va_mode == 0xffff 이면 na_mode = -1 아니면 0 확장(0x12c822–0x12c83e); va_uid == -1 이면 -1 아니면 부호 확장(0x12c841–0x12c857); va_gid 같음(0x12c85a–0x12c873). plan 186 의 vattr_to_sattr(07 nfs_subr.c:638–656)와 같은 꼴.
3. dprint 는 `#ifdef NFSDEBUG` 라 없음.

방법: NeXTMach `nfs/nfs_common.c` 를 07 로 들여 nfstsize 를 `#if NeXT return (NFSTSIZE); #else ... #endif`, vattr_to_nattr 의 mode/uid/gid 를 nfs_subr 의 vattr_to_sattr 꼴로 작성(D024 표시). 빌드 `iter.py s5p166-itN bsd/nfs/nfs_common.c nfs_common 12c808 12c8ec`, 기록.

193 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–3 맞음, 저장 순서 맞음 | 내 역어셈블(`odis.py 12c808 12c8ec`)과 같음 | ✅ |
| nlink(0x12c882)·rdev(0x12c8b3) 는 16 비트 부호 확장 | vnode.h:188 `short va_nlink`, types.h:121 `typedef short dev_t` → NeXTMach 대입문 그대로의 C 의미 | ⏭️ 차이 아님 |
| uid/gid 의 -1 검사는 결과값을 바꾸지 않음(signed short 의 (int) 캐스트와 같은 값) | 맞는 의미 분석이나 코드 꼴(분기)은 원본에 있음 → 분기 꼴로 작성 | ⚖️ |

193 결과: it1(`s5p166-it1`) OBJECT_MATCH 2/2. 등급 A(`06_reconstruction/evidence/x86-nfs_common.md`, `.diff`).

## 194. S5-P167 세부 계획 — `bsd/kern/vfs_xxx.c` (D024, ustat 블록 단위 상수, 코딩 전, 2026-10-03)

사실(원본 [0x11eaa4, 0x11eb50) `_ustat` 하나, objects.tsv seq 61):
0. 진단 13 실패(`37.err`): vfs_xxx.c:67 DEV_BSIZE 미정의 — SDK `sys/param.h:218–224` 는 `#if NeXT` 에서 btodb/dbtob 두 인자 꼴만 두고 DEV_BSIZE/DEV_BSHIFT 는 `#else NeXT` 쪽(`dir.h:93` 은 `!KERNEL` 일 때만).
1. 원본 ustat 은 NeXTMach 본문과 같은 순서(vafsidtovfs(dev & 0xffff) — 0x11eab9 movzx, VFS_STATFS, bzero(usb, 0x14), copyout 0x14)이고, f_tfree 는 `(f_bavail * f_bsize + 511) / 512` 의 부호 있는 나눗셈(0x11eb0d–0x11eb24: +0x1ff, 음수면 +0x3fe, sar 9; 511·1022·512 python 확인). 즉 상수 512 를 씀. 이름은 복원 불가.
2. 그 밖의 차이 없음(역어셈블 전체를 NeXTMach 본문과 대조).

방법: NeXTMach `bsd/vfs_xxx.c` 를 07 로 들여 `howmany(..., DEV_BSIZE)` 를 `#if NeXT howmany(..., 512) #else ... #endif` 로 작성(D024 표시, 상수 이름 미복원). 빌드 `iter.py s5p167-itN bsd/kern/vfs_xxx.c vfs_xxx 11eaa4 11eb50`, 기록.

194 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–2 맞음, 문장 단위 일치(f_bavail +0x10, f_bsize +0x4, f_ffree +0x18, usb 0x14) | 내 역어셈블(`odis.py 11eaa4 11eb50`)과 같음 | ✅ |
| SDK `sys/stat.h:195` `STAT_BSIZE 512`(_NEXT_SOURCE, 빌드 플래그에 있음) 가 후보 이름 | stat.h:195 를 엶; s5p166-it1.cmd 에 `-D_NEXT_SOURCE` | ⚖️ 사실이나 vfs_xxx.c 는 sys/stat.h 를 import 하지 않음 → 증거 없는 import 를 더하지 않고 상수 512 로 작성, STAT_BSIZE 는 가능한 이름으로 기록 |

194 결과: it1(`s5p167-it1`) OBJECT_MATCH 1/1. 등급 A(`06_reconstruction/evidence/x86-vfs_xxx.md`, `.diff`).

## 195. S5-P168 세부 계획 — `bsd/kern/kern_xxx.c` (D024, RB_COMMAND·command 초기화, 코딩 전, 2026-10-03)

사실(원본 [0x10b600, 0x10b7cc), objects.tsv seq 32; 다음 0x10b7cc `_ptrace`; 앞 0x10b464 `_uname` 은 이 객체 범위 밖):
0. 진단 13 실패(`13.err`): kern_xxx.c:175 RB_COMMAND 미정의. SDK `bsd/i386/reboot.h` 는 "Empty file (publicly)" 이고, 07 의 작성 헤더 `07_kernel/nextdev_private/bsd/i386/reboot.h`(plan 132)는 "원본 바이트로 값이 증명된 플래그만" 두며 지금은 RB_NOFP 하나. 같은 SDK 의 `bsd/m68k/reboot.h:23` 에 `#define RB_COMMAND 0x00100000 /* new boot command specified */`.
1. 원본 reboot(0x10b76c): `test byte ptr [opt+2], 0x10`(0x10b787) = opt & 0x100000(python) → RB_COMMAND 값 증명.
2. 진단 빌드 `s5p168-d1`(NeXTMach `bsd/kern_xxx.c` 원문, 스테이징 사본 reboot.h 에만 RB_COMMAND 한 줄; 07·도구 무변경): gethostid 24, sethostid 36, gethostname 56, sethostname 96, getdomainname 56, setdomainname 96 크기·모양 일치(sethostname·setdomainname 의 `[eax + hostname]` 대 `[eax]` 는 재배치 표기). reboot 92 vs 96 — 원본은 첫머리에 `mov byte ptr [ebp-0x40], 0`(0x10b772) = `command[0] = 0`.
3. COMPAT 함수들은 `#ifdef COMPAT` 밖이라 없음.

방법:
a. 작성 헤더 `nextdev_private/bsd/i386/reboot.h` 의 KERNEL_PRIVATE 부분에 `#define RB_COMMAND 0x00100000`(이름·값은 SDK m68k reboot.h:23, x86 값 증명 0x10b787) 추가, PROVENANCE 행 갱신. 07 의 다른 소스는 RB_COMMAND 를 쓰지 않음(grep 0 건) → 기존 기록 영향 없음.
b. NeXTMach `bsd/kern_xxx.c` 를 07 로 들여 reboot 에 `command[0] = '\0';`(D024 표시). 빌드 `iter.py s5p168-itN bsd/kern/kern_xxx.c kern_xxx 10b600 10b7cc`, 기록.

195 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 6 함수 일치, reboot 는 0x10b772 `c6 45 c0 00`(command[0]=0) 하나 차이, 0x10b787 은 0x00100000 만 검사 | 내 진단 `s5p168-d1` rdiff 와 역어셈블이 같음 | ✅ |
| 작성 헤더에 RB_COMMAND 추가는 07 소스와 충돌 없음, SDK m68k reboot.h:23 같은 이름·값 | `grep -rn RB_COMMAND 07_kernel/src` 0 건; m68k reboot.h:23 을 엶 | ✅ |
| `_uname` 소속은 인접성만으로 단정 불가 | 맞음 — 사실 문구를 "이 객체 범위 밖(소속 미정)" 으로 읽음 | ⚖️ |

195 결과: 작성 헤더 `nextdev_private/bsd/i386/reboot.h` 에 RB_COMMAND 추가(PROVENANCE 250 행 갱신, SHA-256 e23574be…); it1(`s5p168-it1`) OBJECT_MATCH 7/7. 등급 A(`06_reconstruction/evidence/x86-kern_xxx.md`, `.diff`).

## 196. S5-P169 세부 계획 — `bsd/kern/mach_signal.c` (thread 의 uthread 필드 이름, 코딩 전, 2026-10-03)

사실(원본 [0x10b9e8, 0x10ba60) `_thread_psignal` 하나, objects.tsv seq 34):
0. 진단 13 실패(`15.err`): mach_signal.c:69 `structure has no member named 'u_address'`. 이 빌드의 `kern/thread.h:171`(스테이징 사본) 에는 `struct uthread *_uthread;` 가 있고, SDK `sys/param.h` 의 NeXT ISSIG 도 `current_thread()->_uthread` 를 씀.
1. 원본: sig > 0x20(NSIG) 이면 반환; mask = 1 << (sig-1); threadmask 0x1ef8 검사 실패면 printf·panic; p = sig_thread->task->proc([esi+0xc]→[+0x3c]); p_sigignore & mask 이고 STRC 아니면 반환; sig_lock_simple(p)(+0x70 스핀·xchg); `[esi+0x84]`→`[+0x7c] |= mask` = `sig_thread->_uthread->uu_sig |= mask`; sig_unlock. NeXTMach 본문과 같은 순서이고 다른 것은 uthread 를 얻는 필드뿐.

방법: NeXTMach `bsd/mach_signal.c` 를 07 로 들여 `sig_thread->u_address.uthread` 를 `#if NeXT sig_thread->_uthread #else ... #endif` 로 작성(표시). 빌드 `iter.py s5p169-itN bsd/kern/mach_signal.c mach_signal 10b9e8 10ba60`, 기록.

196 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 문장 단위 일치, 차이는 0x10ba48 의 `_uthread`(thread+0x84) 하나 | 내 역어셈블과 같음 | ✅ |
| 문자열 두 개 바이트 일치, threadmask 0x1ef8 | python 으로 0x1dabca·0x1dabd7 문자열 읽음; SDK signal.h:41–81 번호(4,5,6,7,8,10,11,12,13)로 0x1ef8 재계산 | ✅ |
| 필드 오프셋(task +0xc, proc +0x3c, p_sigignore +0x20, p_flag +0x28, lock +0x70, uu_sig +0x7c) | 역어셈블 주소와 같음; 빌드 대조로 확정 | ⚖️ |

196 결과: it1(`s5p169-it1`) OBJECT_MATCH 1/1(`__data` 포함). 등급 A(`06_reconstruction/evidence/x86-mach_signal.md`, `.diff`).

## 197. S5-P170 세부 계획 — `bsd/kern/mach_process.c` (import 경로·`_uthread`, 코딩 전, 2026-10-03)

사실(원본 [0x10b7cc, 0x10b9e8) `_ptrace` 하나, objects.tsv seq 33):
0. 진단 13 실패(`14.err`): `vm/vm_prot.h` 없음. 이 트리에서는 `mach/vm_prot.h`·`mach/vm_param.h`(07 vm_pager.c:47, uipc_mbuf.c:31 plan 162, vfs.c:46 plan 164 선례).
1. 진단 빌드(07 아님, NeXTMach 원문의 스테이징 사본만 수정): `s5p170-d1` vm/vm_param.h 없음, `s5p170-d2` import 두 줄을 mach/ 로 바꾸자 :164·:171·:174 `u_address` 없음, `s5p170-d3` 세 곳을 `_uthread`(plan 196 과 같은 필드)로 바꾸자 컴파일 성공 — 원본 540 B 대비 539 B(끝 채움), 비재배치 바이트 차이 0(python).

방법: NeXTMach `bsd/mach_process.c` 를 07 로 들여 import 두 줄을 `mach/` 로, `thread->u_address.uthread` 세 곳을 `#if NeXT` 아래 `thread->_uthread` 로(표시). 빌드 `iter.py s5p170-itN bsd/kern/mach_process.c mach_process 10b7cc 10b9e8`, 기록.

197 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 스테이징 사본은 NeXTMach 와 import 두 줄·`_uthread` 세 곳만 다름; ptrace 비재배치 바이트 전부 일치, 539 vs 540 은 0x10b9e7 채움 | 내 python 비교(비재배치 차이 0, 539/540)와 같음 | ✅ |
| 요청별 필드·오류값(ESRCH 3, EINVAL 22, EIO 5, SIGSTOP 17) | 바이트 일치로 함께 확인됨 | ✅ |

197 결과: it1(`s5p170-it1`) OBJECT_MATCH 1/1. 등급 A(`06_reconstruction/evidence/x86-mach_process.md`, `.diff`).

## 198. S5-P171 세부 계획 — `kern/ast.c` (D024, NeXTMach 기준 + Mach 3 식 ast_on, 코딩 전, 2026-10-03)

사실(원본 [0x156694, 0x1568d8), objects.tsv seq 154; 다음 0x1568d8 `_exception_with_continuation`):
0. 원본 함수는 `_ast_init`(28 B)·`_ast_check`(552 B) 둘뿐이고 `_ast_taken` 기호는 커널 어디에도 없음. 같은 구성은 NeXTMach `kern/ast.c`(ast_init·ast_check); Mach4·Darwin 0.1 판은 ast_taken 을 가짐(Mach4 진단 빌드 `s5p171-d1` 은 ast_taken 의 thread_block 인자·`rq->low` 로 실패).
1. 진단 13 실패(`80.err`, NeXTMach 판): `hw_ast.h`·`machine/pcb.h` 없음, `aston` 인자 없음 — 이 트리의 `kern/ast.h`(07, darwin01 원문)는 `aston(mycpu)`·`ast_on(mycpu, reasons)`·`volatile ast_t need_ast[]`·AST_UNIX 0x20·AST_BLOCK 0x4 를 둠.
2. ast_init(0x156694): `for (i = 0; i < NCPUS; i++) need_ast[i] = 0;`(NCPUS 1).
3. ast_check(0x1566b0) 순서: thread = current_thread()(0x1566bb) → s = splsched() → myprocessor = cpu_to_processor(mycpu) → switch(state): OFF_LINE·IDLE·DISPATCHING(0 과 2·3) 은 아무것도 안 함, RUNNING(1), 그 밖은 `panic("ast_check: Bad processor state")`(0x1deb22 문자열, python 으로 읽음) → splx(s).
4. RUNNING: (a) 신호 검사가 맨 앞 — p = u.u_procp(active_u); p 가 있으면 `p->p_cursig`(+0x17) 이 0 이 아니거나, thread 가 있고 SHOULDissig(p, thread->_uthread)(+0x84, uu_sig +0x7c, p_sig +0x18, STRC, sigignore·sigmask) 이면 `ast_on(mycpu, AST_UNIX)`(0x156731–0x156741); (b) `ast_propagate(thread, mycpu)`(thread->ast +0x17c), `if (ast_needed(mycpu)) break;`; (c) `thread->state & TH_SUSP`(+0x4c, 2) 이거나 `myprocessor->runq.count > 0`(+0x108) 이면 ast_on(AST_BLOCK); (d) MACH_FIXPRI: processor_set->policies & POLICY_FIXEDPRI(+0x168, 2) 이면 csw_needed 전개(0x15679e–0x1567f6) 후 thread->policy == FIXEDPRI 면 first_quantum = TRUE, 아니면 runq high 힌트 갱신(rq->high, simple_lock 스핀·xchg, i 를 내려가며) 후 `rq->high >= thread->sched_pri` 이면 ast_on(AST_BLOCK).
5. NeXTMach 판과 다른 점: aston() 대신 ast_on(mycpu, 이유), splsched/splx 가 함수 전체를 감쌈, 신호 검사 위치와 꼴(u.u_procp, p_cursig, `_uthread`), default panic.

방법: NeXTMach `kern/ast.c` 를 07 로 들여 머리말·ast_init 은 유지(HW_AST 대신 이 트리 kern/ast.h 의 MACHINE_AST 조건), ast_check 본문을 사실 3–4 대로 작성(D024 표시; Mach4·Darwin 은 구조 참고만, 문장 복사 없음). `hw_ast.h`·`machine/pcb.h` import 는 이 트리 헤더로 대체하거나 제거하고 근거 기록. 빌드 `iter.py s5p171-itN kern/ast.c ast 156694 1568d8`, 반복, 기록.

198 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0x15679e–0x1567f6 은 policy 별 판정 = NeXTMach `kern/sched.h:140–197` 의 `_csw_needed`(TIMESHARE: first_quantum==0 && count>0 && high>=pri; 그 밖: count>0 && (high>pri \|\| (high==pri && first_quantum==0))) | NeXTMach sched.h:140–197 을 엶; 역어셈블 0x1567bf–0x1567f6 의 policy 1/2 분기와 맞음; 07 `kern/sched.h:103` 은 Darwin 매크로(policy 검사 없음) | ✅ 사실 4 정정 — 이 트리 헤더로는 재현 불가 |
| first_quantum = TRUE 는 fixedpri 허용 집합에서 block 이 아니고 thread->policy == FIXEDPRI 일 때만; 힌트 경로에서는 first_quantum 이 진입 조건 | 0x1567fc–0x156809, 0x15677f·0x15681d | ✅ |
| 신호 검사는 앞쪽 하나뿐(NeXTMach 의 뒤쪽 검사 없음), p_cursig 와 thread 확인 뒤 SHOULDissig | 0x1566fc–0x156741 | ✅ 사실 5 보강 |
| need_ast 는 `__common` 0x1e90ac; 이 트리 ast.h 는 `extern volatile ast_t need_ast[]` 라 NeXTMach 의 `int need_ast[NCPUS];` 는 충돌 → `volatile ast_t need_ast[NCPUS];` | 07 ast.h:100 을 엶 | ✅ |

### 198.1 수정된 방법
- 07 `kern/sched.h`(darwin01 원문) 의 csw_needed 를 `#if NeXT` 로 감싸 NeXTMach `kern/sched.h:140–197` 의 `csw_needed`·`static inline _csw_needed` 문장을 넣고 `#else` 에 기존 매크로(출처: NeXTMach 커밋·줄, MODIFICATIONS 기록).
- 영향: 07 의 161 개 .c 중 69 개가 kern/sched.h 를 폐포에 넣음(`--list` 훑기). csw_needed 사용처는 sched_prim.c:934 하나이고 `#if FAST_TAS`(꺼짐) 안. 쓰이지 않는 static inline 이 GCC 2.7(cc-744.13) -O3 에서 출력되지 않는지 실측: 대표 기록 객체(sched_prim, thread, host)를 새 헤더로 재빌드해 OBJECT_MATCH·`_csw_needed` 기호 부재 확인. 출력된다면 이 방법을 버리고 ast.c 안의 지역 정의로 바꿈(근거 기록).
- ast.c: NeXTMach 판 기준, `volatile ast_t need_ast[NCPUS];`, ast_check 는 사실 3–4 와 위 판정대로 작성.

198.1 codex 검토 판정:
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| `_csw_needed` 본문에 POLICY_* 가 필요 → `#if NeXT` 안에 mach/policy.h import; boolean_t 는 kern/lock.h 경유 | 07 sched.h:63–88 import 목록을 엶(policy.h 없음); nextdev/mach/policy.h:70–72 | ✅ |
| FAST_TAS 는 정의 없음(= 0), csw_needed 사용은 sched_prim.c:934 뿐 | grep 결과 같음 | ✅ |
| 쓰이지 않는 static inline 은 출력되지 않을 것이나 cc-744.13·-g 에서는 재빌드로 확인해야 함 | 계획의 탐침과 같음 | ✅ |
| MACH_FIXPRI 1 | generated/mach_fixpri.h:1 | ✅ |

### 198.2 결과
- 07 `kern/sched.h` 에 `#if NeXT` NeXTMach csw_needed(141–200행) + `mach/policy.h` 추가(PROVENANCE 32 행·MODIFICATIONS 갱신). 탐침 `s5p171-p1`(sched_prim)·`p2`(thread)·`p3`(host) OBJECT_MATCH, `_csw_needed` 기호 없음.
- ast it1(`s5p171-it1`): ast_check 560 vs 552 — 힌트 첫 읽기 꼴; it2: `q = rq->runq + *(volatile int *)&rq->high;` → OBJECT_MATCH 2/2(`__data` 포함).

198 결과: 등급 A(`06_reconstruction/evidence/x86-ast.md`, `.diff`).

### 198.3 kern/sched.h 회귀
- 메모리 원칙(헤더 변경 뒤 회귀)에 따라 kern/sched.h 를 폐포에 넣는 나머지 기록 객체 66 개(탐침 3 개 제외, sched.h 변경 전에 기록한 mach_signal·mach_process·clnt_kudp·pmap_kgetport 포함)를 `s5p171-g00`–`g65` 로 재빌드.
- 결과: 등급 A 는 모두 OBJECT_MATCH(사유 없음), 등급 P 는 기록된 사유와 같음 — `__bss` 만(대부분), ddm·fp_support·intr·PCresume·vm_machdep 는 기록 당시부터의 `__TEXT,__const` 미참조 4/12 B 포함(objects_partial.tsv unverified_sections 열과 대조). 변화 0.

## 199. S5-P172 세부 계획 — `bsd/nfs/nfs_client.c` (D024, flag 인자·getthetime·NBC 크기, 코딩 전, 2026-10-03)

사실(원본 [0x12c204, 0x12c808), objects.tsv seq 93; 앞 0x12c1f8 `_ip_mforward` 는 다른 객체, 다음 0x12c808 `_nfstsize` 는 nfs_common):
0. 진단 13 실패(`57.err`): SDK `nfs/nfs_clnt.h:92` 의 CACHE_VALID 는 인자 3 개(rp, mtime, fsize). 원본 함수: validate_caches 32, invalidate_caches 52, purge_caches 56, cache_check 104, attrcache 60, attrcache_va 76 + 기호 없는 정적 set_attrcache_time(0x12c380, 124), getattr_otw 188, nfsgetattr 524, nattr_to_vattr 324(python 으로 경계 계산). nfs_getattr_cache 기호 없음 — nfsgetattr 안에 인라인(정적·사용 전 정의).
1. 넷째 인자 `flag`: `sync_vp_invalidate(vp, flag)`(0x1337f8)는 `mfs_fsync_invalidate(vp, flag)`(07 mfs_prim.c:1031) 로 넘김. nfs_purge_caches(vp, flag) — 원본은 `sync_vp_invalidate(vp, flag)` 를 **먼저**, 그 뒤 vnode_uncache, PURGE_ATTRCACHE, dnlc_purge_vp, binvalfree(0x12c258–0x12c283). nfs_cache_check(vp, mtime, fsize, flag): `if (!CACHE_VALID(vtor(vp), mtime, fsize)) nfs_purge_caches(vp, flag)`(인라인). nfs_validate_caches(vp, cred, flag): `return nfsgetattr(vp, &va, cred, flag)`. nfsgetattr(vp, vap, cred, flag). 호출자: nfswrite 쪽 0x131a72·0x131c26 은 flag 0, nfs_subr 0x12f663 은 cache_check(..., 0)(plan 186).
2. set_attrcache_time: `time` 대신 지역 timeval 에 `getthetime(&tv)` 후 r_attrtime = tv, delta = (tv.tv_sec - mtime) >> 4; 비교는 부호 없는 jb/jbe(mi_ac*min/max 형에 따름).
3. nfsgetattr(0x12c4b8): (a) 인라인 getattr_cache — getthetime(&tv), timercmp(&tv, &rp->r_attrtime, <) 이면 *vap = r_attr, va_fsid = 0xff00 | mi_mntno, MACH_NBC 크기 보정(`va_size < vm_info->vnode_size && (vm_info->dirty \|\| (r_flags & RDIRTY))` 이면 vnode_size), error 0; (b) 아니면 인라인 getattr_otw(kalloc 0x48, rfscall, nattr_to_vattr, fsid kludge, ESTALE(70) 이면 btrash 뒤 nfs_invalidate_caches 인라인, kfree); (c) error 0 이면 인라인 cache_check(vap->va_mtime, vap->va_size, flag) 와 attrcache_va; (d) 모든 경로 끝에서 `vap->va_size = vtor(vp)->r_size`(0x12c6a5–0x12c6b1).
4. getattr_otw(별도 함수, 188 B): (b) 와 같음(PURGE_STALE_FH 전개 앞에 btrash).
5. nattr_to_vattr: MACH_NBC 크기 분기가 `if (na_size < vnode_size && (vm_info->dirty \|\| (r_flags & RDIRTY))) va_size = vnode_size; else va_size = na_size;` 꼴(0x12c72f–0x12c753) 이고 r_size 갱신은 NeXTMach 와 같음. 나머지 저장은 NeXTMach 와 같은 순서.
6. 진단 빌드 `s5p172-d1`(07 아님, 스테이징 사본에 CACHE_VALID·purge/cache_check 인자만 반영): invalidate·cache_check·attrcache·getattr_otw 크기 일치, 나머지는 위 1–5 의 차이.

방법: NeXTMach `nfs/nfs_client.c` 를 07 로 들여 1–5 를 D024 표시로 작성(nfs_getattr_cache·set_attrcache_time 은 static 으로, 사용 전 정의 순서는 원본 배치에 맞춤). 빌드 `iter.py s5p172-itN bsd/nfs/nfs_client.c nfs_client 12c204 12c808`, 반복, 기록.

199 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 경계·크기 맞음; purge 는 sync_vp_invalidate 먼저(0x12c25f–0x12c264) | 내 역어셈블과 같음(사실 1 에 이미 적음) | ✅ |
| set_attrcache_time 의 delta 는 int 유지(sar), 비교는 u_int mi_ac* 와의 혼합 부호 | nfs_clnt.h:67–70 u_int 를 엶 | ✅ |
| 마지막 `va_size = r_size` 는 캐시 적중·원격 성공·원격 오류 모두에서(0x12c543·0x12c5ff→0x12c6a5), 원격 성공 시 cache_check·attrcache_va 는 그 전의 va_size 를 씀 | nfsgetattr 역어셈블 0x12c53c–0x12c6b1 을 다시 읽음 | ✅ 사실 3 보강 |
| nfs_getattr_cache 를 static 으로 두는 것은 재구성 선택(원 선언 증명 아님) | 맞음 — 기호 없음·별도 본문 없음만 증거 | ⚖️ |
| 진단 객체는 크기만 같고 바이트 동일 증명 아님 | 맞음 — 07 빌드 대조로 판정 | ✅ |
| 호출자 flag 0(0x131a72·0x131c26·0x133ae5), sync_vp_invalidate 는 0x133804 에서 mfs_fsync_invalidate 로 넘김 | 내 역어셈블과 같음 | ✅ |

199 결과: it1(`s5p172-it1`) OBJECT_MATCH 10/10. 등급 A(`06_reconstruction/evidence/x86-nfs_client.md`, `.diff`). 뒤의 nfs_vnodeops 등은 nfsgetattr·nfs_validate_caches·nfs_purge_caches 의 flag 인자(대개 0)를 맞춰야 함.

