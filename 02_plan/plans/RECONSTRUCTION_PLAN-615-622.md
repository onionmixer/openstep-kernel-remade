# 커널 소스 복원 작업계획 — 보관 §615–622

`02_plan/RECONSTRUCTION_PLAN.md` 의 §615–622(m68k M4 `pagemove`·함수 표 나눔(D140–D141), `trap.c` 첫 진단 N1, 1997 `struct pcb` 조사와 공유 머리 `thread.h`(D142))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-31, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 615. M4-121 다음 단위 후보 검토(07·도구·표 변경 없음; 2026-10-30)

확인한 사실(이번 세션; scratchpad `odis.py`·python·grep):
- `pagemove`(행 323 일부):
  - 원본 함수는 [0x409aaf6, 0x409ab9c), 166 B(0x409ab9a 의 `rts`)입니다. 뒤의 112 B 는 FPSP 상수 표입니다.
  - 몸통은 NeXTMach `next/vm_machdep.c:23–45` 와 차례가 같습니다(`page_size` 나머지 검사, `panic("pagemove")`, `pmap_pte`·`pmap_expand_kernel` 고리, `pflush_user` 두 번, 걸음 `m68k_page_size`).
  - 그러나 함수 표 `06_reconstruction/m68k-functions.tsv:3367` 은 이 자리를 한 항목 [0x409aaf6, 0x409ac0c) 278 B("unreached bytes")로 둡니다. 행 `m68k-324`(fpsp `bindec`)도 0x409aaf6 에서 시작합니다.
  - 탐침의 명시 구간 규칙(`m4_m68k_probe.py:150–180`, 범위 끝은 함수 표 항목 끝)으로는 166 B 객체를 받아들일 수 없습니다. 함수 표는 도구 여섯(`m4_m68k_probe.py`·`m68k_funcbytes.py`·`m4_m68k_inventory.py` 등)이 읽는 공유 표라, 항목을 나누려면 따로 계획이 필요합니다.
  - 그 밖에 07 m68k `pmap.h`(M5 덮어쓰기)에 `pte_t`·`PTE_ENTRY_NULL`·`pmap_pte` 가 없어 파일 안 정의가 필요합니다.
- (§636 에서 받아들임, D144) 1997 `trap.c`(행 315–320, [0x40996b8, 0x409a8ba) 4610 B): `trap` 2444·`unix_syscall` 466·`unix_syscall_return` 198·`do_trace` 34·`check_for_ast` 428·`traceback` 202·`do_writeback` 390·`move_space` 240·`bmap_parity_error` 208 B 입니다. NeXTMach `next/trap.c` 에는 `trap`·`unix_syscall`·`traceback`·`do_writeback` 이 있고, 1997 x86 07 `machdep/i386/trap.c` 에는 `unix_syscall`·`unix_syscall_return`·`check_for_ast` 가 있습니다. 큰 단위이고 `trap` 하나가 2444 B 입니다.
- (§622·§627 에서 처리함, D142·D143) `pcb.c`(행 308–309)는 공유 07 `thread.h` 의 `struct pcb` 를 넓혀야 하고, 그 머리를 쓰는 M5 객체를 다시 받아들여야 합니다.
- 64 비트 보조 함수(행 264·291·322)는 참고 글이 없습니다(§422).

판단: 모든 남은 후보가 공유 표·공유 머리의 변경이나 큰 작성을 요구합니다. 그래서 사용자에게 다음 방향을 묻습니다.

- 사용자 결정(2026-10-30, AskUserQuestion): 다음 단위는 "pagemove + 함수 표 나눔" 입니다.

## 616. M4-122 세부 계획 — 함수 표 `m68k-functions.tsv` 의 `_pagemove` 항목 나눔(도구·표 변경; 07 변경 없음; 코딩 전, 2026-10-30)

확인한 사실(이번 세션):
- 함수 표는 `10_tools/reconstruction/m2_m68k_functions.py`(plan 424)가 만듭니다. 지금 도구를 다시 돌린 결과(scratchpad `funcs_regen.tsv`)는 저장소 표와 `cmp` 같습니다.
- 항목은 plan 418 의 `D418.main(extend=True)['entries']` 이고, 항목 수 단언은 3570(`m2_m68k_functions.py:219`)입니다. 각 항목의 범위는 다음 항목까지이고, 첫 줄이 무효이거나 0 낱말이면 `data label` 입니다(`:181–190`).
- `_pagemove` 항목은 [0x409aaf6, 0x409ac0c) 278 B, `confirmed` 0, 사유 "unreached bytes" 입니다(`m68k-functions.tsv:3367`). 원본은 0x409ab9a 의 `rts` 뒤 0x409ab9c–0x409ac0c(112 B)가 FPSP 상수 표입니다(§615).
- 표를 읽는 도구 가운데 받아들임에 쓰이는 것은 `m4_m68k_probe.py`(`span` 은 범위 안 항목만 봄)와 `m68k_funcbytes.py`(범위 안 항목만 봄)입니다.
  - 상태 도구는 기록의 `inputs` 해시를 다시 검사하지 않고(`m4_m68k_status.py:88–135`), 지금 표로 각 객체의 `span` 을 계산합니다.
  - 받아들인 39 객체 가운데 [0x409aaf6, 0x409ac0c) 와 겹치는 것은 없습니다(python).
- 재고 표 `m68k-m4-inventory.tsv`(plan 495)는 저장된 파일이고, 이번에 다시 만들지 않습니다. 행 323·324 의 경계는 그대로이고, 명시 구간에서 둘 다 부분 행으로 씁니다.

방법:
1. `m2_m68k_functions.py`: 이름 붙인 상수 `EXTRA_ENTRIES = {0x409ab9c: 'plan 616: FPSP constant table after the rts of _pagemove (0x409ab9a); user decision'}` 를 두고, `entries |= set(EXTRA_ENTRIES)` 를 더합니다. 항목 수 단언을 `3570 + len(EXTRA_ENTRIES)` 로 바꾸고, 머리말에 plan 616 줄을 더합니다.
2. 표를 다시 만들어 저장소 표를 바꿉니다(기록 `09_validation/reconstruction/m2-m68k-functions-p616-20261030.json`; 옛 기록 `m2-m68k-functions-20261009.json` 은 그대로 둡니다).
   - python 단언: 옛 표와의 차이는 `_pagemove` 행 하나(끝 0x409ab9c·166 B·`confirmed`·사유 바뀜)와 새 행 0x409ab9c(끝 0x409ac0c, 112 B, `data label` 기대) 하나뿐입니다.
   - 다른 3569 행은 모든 칸이 같아야 합니다.
3. 영향 확인:
   - 상태 도구를 새 표로 두 번 돌려 §614 표와 `cmp` 같아야 합니다.
   - 받아들인 객체 가운데 바뀐 구간과 겹치는 것이 없음을 기록합니다.
   - 탐침 `span` 이 받아들인 39 객체의 `m4_id` 를 새 표로 모두 같은 범위로 푸는지 python 으로 봅니다.
4. 기록: 계획 결과, DECISIONS D140(표 나눔), 근거는 다음 `pagemove` 근거 문서에 함께 둡니다.

판정(미리 정함): 2·3 이 모두 맞으면 다음 계획(§617)에서 `pagemove` 진단을 합니다. 아니면 표를 되돌리고(저장소 표는 바꾸기 전 사본을 scratchpad 에 둠) 사용자에게 알립니다.

관문: 생성기 종료 0, 차이 단언, 상태 도구 표 같음.

### 616.1 codex 교차검토(task k3j8be78t, gpt-6.1-sol, read-only) 판정

회신은 "막는 문제 없음" 이었습니다. 모든 주장을 이번 세션에서 다시 확인했습니다. 시뮬레이션은 생성기 사본(scratchpad `p616/m2_sim.py`: `entries |= {0x409ab9c}`, 단언 3571)을 `PYTHONPATH=10_tools/reconstruction` 로 돌려 scratchpad 에만 썼고, 저장소 파일은 바꾸지 않았습니다. 같은 때 고치지 않은 생성기의 출력은 저장소 표와 `cmp` 같았습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0x409ab9a 가 `4e75 rts` | 로컬 `m68k-linux-gnu-objdump`(scratchpad `odis.py 0x409ab90 0x409aba0`): `409ab9a: 4e75 rts`, 다음 `409ab9c: .short 0x3ffd`; 생성기 `Text.word(0x409ab9a,2)` = 0x4e75, 목록 줄 `rts` | ✅ |
| 뒤 112 B 가 `fpsp/bindec.sa:143–155` 의 `LOG2`…`RBDTBL` 과 같음 | `bindec.sa` 143(`LOG2`)·144·147–150(`FONE`…`F4933`)·152–155(`RBDTBL`) 줄을 열고 `dc.l`/`dc.b` 값을 python 으로 바이트로 만들어 원본 [0x409ab9c, 0x409ac0c) 와 비교: 112 B, 같음 | ✅ |
| `_pagemove` 안에서 상수 표를 가리키는 곳 없음; FPSP 코드가 읽음(예 0x409acd0 `fmulx 0x409ab9c,fp0`, `image.txt:194376`); 제어 흐름 대상 없음 | 목록 `08_build/artifacts/m0p414/otool-V10/image.txt` 전체를 python 으로 훑어 [0x409ab9c, 0x409ac0c) 안 `0x…` 피연산자: 14 곳, 모두 0x409acb0 이후의 `fmulx`·`fmoves`·`fmuls`·`fdivs`·`fsubs`·`lea` 이고 분기·호출은 0; 194376 행 = `0409acd0 fmulx 0x409ab9c:l,fp0` | ✅ |
| 만든 행: `_pagemove` 끝 0x409ab9c·166 B·function candidate·confirmed 1·사유 없음; 새 행 0x409ab9c 끝 0x409ac0c·112 B·data label·0·`data label`; 둘 다 `object_id` 빈칸; 다른 3569 행 같음 | 시뮬레이션 표와 고치지 않은 표를 python 으로 행마다 비교: 바뀐 행 1·새 행 1·없어진 행 0, 나머지 3569 행 모든 칸 같음. 새 행이 data label 인 까닭은 첫 줄이 `movew <bad ef>,<bad ef>`(무효 줄)이기 때문 | ✅ |
| 검증 181 함수 모두 confirmed; drop 3308·split 6959 시도, 실패 0; entries 3571·data label 29·confirmed 3339·confirmed_bytes 625294·92.16%; IDA 같은 시작·끝 2956 | 두 실행의 요약 JSON 을 python 으로 칸마다 비교한 차이: data label 28→29, confirmed 3338→3339, confirmed_bytes 625128→625294, pct 92.13→92.16, entries 3570→3571, ida.same_start_end 2955→2956, 사유 `data label` 28→29·`unreached bytes` 63→62, 단일 사유 `data label` 25→26·`unreached bytes` 13→12, drop 3307→3308, split 6957→6959; validation 181/181/181, wrong 0, passed true | ✅ |
| 받아들인 39 객체 가운데 겹침 없음; 상태 도구를 새 표로 두 번 돌리면 상태 표가 같음 | 상태 표의 `start`·`end` 로 겹침 python 검사: 0 객체. `P.FUNCS` 를 시뮬레이션 표로 바꿔 `m4_m68k_status.main` 을 두 번 돌림: 두 출력 모두 `06_reconstruction/m68k-m4-status.tsv` 와 `cmp` 같음. `P.span` 을 감싸 두 표에서 39 객체의 결과를 기록: 39·39, 같음 | ✅ |
| funcbytes 비교는 같고 기록의 `FUNCS` 입력 해시만 달라짐(`m68k_funcbytes.py:109–119,246–249`) | `m68k_funcbytes.py:109` 가 표를 읽고 `:248` 이 `inputs` 에 `FUNCS` 해시를 넣는 것을 grep 으로 확인. 범위 안 항목만 쓰므로 위 겹침 0 과 함께 받아들인 객체의 비교는 바뀌지 않음 | ✅ |
| 명시 구간 `{"range":["0x409aaf6","0x409ab9c"],"rows":[],"partial":["m68k-323","m68k-324"],...}` 은 통과하고 부분 행 하나를 빼면 실패 | `P.span` 을 직접 불러 봄: 새 표에서 두 부분 행 → `(0x409aaf6, 0x409ab9c, [])`; `m68k-323` 만 → `('rows', ['m68k-324'])`; `m68k-324` 만 → `('rows', ['m68k-323'])`; 지금 표에서는 셋 다 `range not on entry boundaries`. 재고 표 127–128 행: 두 행 모두 `exact` 0 | ✅ |
| 재고 표를 다시 만들면 3570 단언(`m4_m68k_inventory.py:146–147`)에 걸림 | `:146` 의 `len(F) == 3570` 과 `:147` 의 바이트·개수 튜플을 열어 확인 | ✅(§616 은 재고 표를 다시 만들지 않음; 그대로) |
| 머리 도구는 이름 붙은 항목을 쓰므로 바뀌지 않음(`m4_m68k_headers.py:168`) | `:168` 이 `object_id` 로 고른 행의 `names` 를 모음을 확인; 새 행은 이름·`object_id` 가 빈칸이고 `_pagemove` 의 이름·`object_id`(빈칸)는 그대로 | ✅ |
| diag 는 대상 밖 주소 표시만 바뀜(`m3_m68k_diag.py:23,92–97`); boundaries-built 는 후보가 하나 늘지만 결정된 창에 들지 않음(`m2_m68k_boundaries_built.py:110–144`) | `:23`(대상 4 객체)·`:92–97`(`img_func`)·`:110–144`(`entries`, 규칙 3 창)을 열어 읽음. 두 도구 모두 §616 에서 다시 돌리지 않으므로 결과 주장은 실행으로 확인하지 않음 | ⏭️(행동 안 바뀜; 문서에 결과 주장을 옮기지 않음) |

내가 놓쳤던 것: 없습니다. codex 가 들지 않은 것 하나를 더 찾았습니다. `m2_m68k_objects.py:161` 에도 `3570` 단언이 있지만, 이 도구는 함수 표가 아니라 plan 418 의 `res['entries']`(`:85`)를 직접 쓰므로 이번 바꿈의 영향을 받지 않습니다. 함수 표를 읽는 도구는 `grep -l m68k-functions` 로 생성기 밖 여섯(`m2_m68k_boundaries_built`·`m3_m68k_diag`·`m4_m68k_headers`·`m4_m68k_inventory`·`m4_m68k_probe`·`m68k_funcbytes`)이고, 상태 도구는 탐침의 `span` 을 거쳐 읽습니다.

채택: 계획에 명시 구간 사양(위 표)과 기대 요약 차이(위 표)를 더합니다. 구현 단계 2 의 단언에 요약 차이 12 칸을 넣습니다. 판정 기준은 바꾸지 않습니다.

### 616.2 결과(2026-10-30)

- 생성기 `10_tools/reconstruction/m2_m68k_functions.py`(SHA-256 앞 8자 `0897da63`): 머리말에 plan 616 줄, 상수 `EXTRA_ENTRIES = {0x409ab9c: ...}`, `entries |= set(EXTRA_ENTRIES)`, 단언 `3570 + len(EXTRA_ENTRIES)` 를 더했습니다. 바꾸기 전 사본은 scratchpad `p616/m2_before_p616.py`, 바꾸기 전 표는 `p616/functions_before_p616.tsv` 입니다.
- 다시 만든 표 `06_reconstruction/m68k-functions.tsv`(`d2c2f8cf`, 3571 행)와 기록 `09_validation/reconstruction/m2-m68k-functions-p616-20261030.json`(`28df334a`; 기록의 `outputs`·`tool_sha256` 이 두 파일의 해시와 같음을 python 으로 확인). 옛 기록 `m2-m68k-functions-20261009.json` 은 그대로 둡니다. 생성기 종료 0, validation passed(181/181).
- 차이 단언(python, 모두 통과): 헤더 같음; 바뀐 행은 `0x409aaf6` 하나(`0x409ac0c 278 … 0 unreached bytes` → `0x409ab9c 166 _pagemove function candidate 1 (사유 없음)`); 새 행은 `0x409ab9c 0x409ac0c 112 (이름 없음) data label 0 data label`; 없어진 행 0; 나머지 3569 행 같음; 항목 차례 정렬됨. 요약 차이는 옛 기록과 비겨 §616.1 의 12 칸과 정확히 같습니다. 새 표는 §616.1 시뮬레이션 표와 `cmp` 같습니다.
- 영향: 상태 도구를 새 표로 두 번 돌린 출력이 둘 다 `06_reconstruction/m68k-m4-status.tsv` 와 `cmp` 같습니다(39 객체, 상태 그대로). 받아들인 객체와 바뀐 구간 [0x409aaf6, 0x409ac0c) 의 겹침은 0 입니다. 명시 구간 `{"range": ["0x409aaf6", "0x409ab9c"], "rows": [], "partial": ["m68k-323", "m68k-324"], ...}` 을 `P.span` 이 (0x409aaf6, 0x409ab9c, []) 로 풉니다(166 B, python 변환).
- 재고 표·머리·diag·boundaries-built 결과는 다시 만들지 않았습니다(재고 표 생성기의 3570 단언은 그대로 둠, §616.1).

판정: 미리 정한 관문(생성기 종료 0, 차이 단언, 상태 표 같음)을 모두 통과했습니다. 결정 D140 으로 기록하고, 다음 계획 §617 에서 `pagemove` 진단을 합니다.

## 617. M4-123 세부 계획 — m68k `pagemove`(행 323 일부, NeXTMach `next/vm_machdep.c`) 진단 A1(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: 사용자 결정(§615) "pagemove + 함수 표 나눔" 의 둘째 부분입니다. 함수 표 나눔은 §616 에서 끝났습니다(D140).

확인한 사실(이번 세션; scratchpad `odis.py`·`symbols.tsv`·python):
- 원본 범위는 [0x409aaf6, 0x409ab9c), 166 B(python)이고 함수는 `_pagemove` 하나입니다. 앞은 행 322(`__udivdi3`·`__umoddi3`), 뒤는 FPSP 상수 표(§616)입니다. 원본 기호표에 `_kernacc` 는 없습니다(x86 07 `machdep/i386/vm_machdep.c` 에는 `pagemove`·`kernacc` 가 있음).
- 몸통(원본 풀이, 호출·자료 주소는 `symbols.tsv` 로 이름 붙임):
  - 인자 `from`→d3, `to`→d2, `size`→d4. `divull _page_size(0x40b06d0),d0:d1` 뒤 나머지가 0 이 아니면 `panic("pagemove")`(문자열 0x40ace6d).
  - `_kernel_map`(0x40b5dbc)을 읽어 그 +32 를 d5(`pmap`)로 둡니다.
  - `size <= 0` 이면 끝. 아니면 `lea _pflush_user(0x40013f4),a3` 뒤 고리: `_pmap_pte(pmap, from)`(0x4096e20) 결과가 음수인 동안 `_pmap_expand_kernel(from, fpte)`(0x40988b0); `to` 도 같은 꼴; `*tpte = *fpte`(`movel a2@,a0@`); `fpte` 의 낱말 0(`clrl a2@`); `jsr a3@` 두 번; `_m68k_page_size`(0x40b6538)를 `from`·`to` 에 더하고 `size` 에서 뺌; `size > 0` 이면 되풀이.
- 이 차례는 NeXTMach `next/vm_machdep.c:23–46` 과 같습니다(§615 의 "23–45" 는 46 행의 닫는 `}` 를 빠뜨린 제 오기입니다). 다른 점은 걸음이 `NeXT_page_size` 대신 `m68k_page_size` 인 것입니다(1997 이름; 스테이지 `mach/m68k/vm_param.h:22–23` 의 `extern int m68k_page_size`).
- 원본 `__cstring` 에서 `"pagemove"` 의 앞은 `trap` 의 `bmap_parity_error` 문자열(0x40ace33), 뒤는 `__const` 의 시작(0x40ace76)입니다(§617.1). 이 객체의 문자열은 이것 하나로 봅니다(9 B, python; 추론).
- 스테이지(`m0p614-a1-stage`) 머리:
  - `vm/vm_kern.h:77` 에 `kernel_map`, `vm/vm_map.h:190` 에 `pmap` 칸, `:442` 에 `vm_map_pmap(map)`, `mach/vm_param.h:108·138` 에 `PAGE_SIZE`→`page_size`(`vm_size_t`) 가 있습니다.
  - 07 m68k `machdep/m68k/pmap.h`(M5 덮어쓰기, 58 행)에는 `pte_t`·`PTE_ENTRY_NULL`·`pmap_pte` 가 없습니다. NeXTMach `vm/vm_param.h`·`next/pmap.h` 경로도 스테이지에 없습니다.
  - M5 컴파일 줄에는 `-W` 선택이 없습니다(grep 0).

방법(진단; 명세 `08_build/artifacts/m4p617/spec.json`, run `m4p617-p1`, 바탕 `08_build/runs/tools/m0p614-a1-stage`, 진단 객체 이름 `vm_machdep`, `x86_rel` `machdep/i386/vm_machdep.c`; scratchpad `gen_p617.py`):
- `m4_id` 는 명시 구간 `{"range": ["0x409aaf6", "0x409ab9c"], "rows": [], "partial": ["m68k-323", "m68k-324"], "basis": "plan 616 (D140): _pagemove ends at the rts at 0x409ab9a; FPSP constants follow"}` 입니다(§616.2 에서 `P.span` 이 이 꼴로 풀림).
- A1 은 NeXTMach `next/vm_machdep.c` 를 바탕으로 한 진단 글입니다.
  - NeXTMach 고지 머리와 HISTORY 를 그대로 둡니다.
  - import 는 `<sys/types.h>`·`<mach/vm_param.h>`·`<vm/vm_kern.h>`·`<vm/pmap.h>` 입니다(NeXTMach `vm/vm_param.h`·`next/pmap.h` 는 스테이지에 없음).
  - 파일 안에 NeXTMach `next/pmap.h` 의 `struct pt2_030_entry`·`struct pt3_040_entry`·`union pte`·`pte_t`·`PTE_ENTRY_NULL`·`pmap_pte()` 선언 줄을 그대로 옮깁니다(진단 표시 주석).
  - 몸통은 NeXTMach 23–46 행 그대로이고, `NeXT_page_size` 셋만 `m68k_page_size` 로 바꿉니다.

측정:
- 종료·경고·i386 0, 컴파일 명령 = M5 줄
- `__text` 166, L1 `OBJECT_MATCH`·`full_span`, funcbytes 1/1(`m68k_funcbytes.py 0x409aaf6 0x409ab9c`), 다르면 `rawdiff.py`
- 섹션 목록(`__text`·`__cstring` 9 B 기대, `__data`·`__bss` 없음 기대), 문자열이 원본과 같은지
- 외부 정의(`_pagemove` 하나 기대), 원본에 없는 미정의, COMMON 이름·크기(D136), 지역 정의

판정(미리 정함; 07 은 바꾸지 않음): 맞으면 바이트로 가를 수 없는 꼴(파일 이름, 반환형 암묵 `int`/`void`, 파일 안 `pte` 정의를 NeXTMach 그대로 둘지 최소로 둘지 등)을 사용자에게 묻고 07 구현 계획을 씁니다. 아니면 차이를 적고 다음 진단으로 갑니다.

관문: 컴파일 명령 = M5 줄, i386 0 입니다. 종료·경고는 기록합니다.

### 617.1 교차검토(codex `gpt-6.1-sol`, task k8j6tdu0u) 판정과 계획 수정

먼저 제 잘못입니다: 계획을 쓰며 NeXTMach 몸통을 "23–45 행" 으로 적었으나 23–46 행입니다(46 행 = 닫는 `}`; python 으로 46 행을 읽어 확인). codex 검토 전에 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 사실(166 B, 0x409ab9a `4e75`, 인자 레지스터, `divull`, `kernel_map+32`, 부호 있는 시험, 고리, 걸음)이 계획과 같음; 이름은 `symbols.tsv:1417·1573·2118·2121·2126·2143·2176·2191` | 로컬 objdump(`odis.py`)로 범위 전체를 풀어 읽음(이번 세션); `sed -n` 으로 그 여덟 줄을 열어 `_kernel_map`·`_m68k_page_size`·`_page_size`·`_pagemove`·`_panic`·`_pflush_user`·`_pmap_expand_kernel`·`_pmap_pte` 확인 | ✅ |
| `"pagemove\0"` 9 B 바로 뒤가 `__const` 의 시작 | `macho.json` 섹션을 python 으로 읽음: `__cstring` [0x40a5d7e, 0x40ace76), `__const` 는 0x40ace76 에서 시작; 0x40ace6d+9 = 0x40ace76 | ✅ 사실 줄의 "뒤는 0 바이트" 를 "뒤는 `__const` 의 시작" 으로 고칩니다(0 바이트는 `__const` 의 내용) |
| "이 객체의 문자열은 이것 하나" 는 추론임 | — | ✅ 근거 문서에 추론으로 적습니다 |
| 스테이지 `vm_map` 의 `pmap` 은 +32(락 8 + 머리 24) | `vm/vm_map.h:185–190`(`lock_data_t lock; struct vm_map_header hdr; pmap_t pmap`)과 `kern/lock.h:66`(`MACH_SLOCKS`)·`:127–137`(`struct lock`: 포인터 + 비트 칸 32 비트 + `:0`)을 열어 읽음. `vm_map_header` 크기는 열지 않음 | ⚖️ 머리글은 맞아 보이나, A1 객체의 `movel a0@(32)` 로 측정해 확정합니다 |
| 네 import 가 풀리고, 옮긴 이름이 스테이지 머리와 부딪치지 않음 | A1 컴파일(종료 0)로 측정 | ⏭️ run 에서 측정 |
| `MACH_ASSERT 0` 이라 `kern/assert.h` 의 `panic` 원형이 꺼짐 → `panic` 도 암묵 선언 | 스테이지 `kern/assert.h:46`(`#if MACH_ASSERT`)과 `generated/mach_assert.h`(`#define MACH_ASSERT 0`)를 엶 | ✅ |
| `refs` 가 없으면 탐침 `compare` 의 종료 상태가 결과를 강제하지 않음; funcbytes 도 다를 때 0 이 아닌 값으로 끝나지 않음 | `m4_m68k_probe.py:382–392`(`gate` 는 `if 'refs' in s` 안에서만), `m68k_funcbytes.py:245–260`(출력만, `sys.exit` 없음)을 엶 | ✅ 판정에 python 단언을 더합니다 |
| 옮긴 `pte` 조각에는 NeXTMach `next/pmap.h` 의 고지(1987–1990)를 따로 둘 것 | `next/pmap.h:1–3` 을 엶(`Copyright (c) 1987, 1988, 1989, 1990 NeXT, Inc.`); AGENTS.md 의 고지 보존 규칙 | ✅ A1 에 더합니다 |
| 반환형 암묵 `int`/`void` 는 측정 전에는 "가를 수 없을 수도" 임 | — | ✅ 변형 A2(`void pagemove`, 나머지 A1 과 같음)를 같은 run 에서 잽니다 |
| 업스트림 `struct pmap`/`pmap_t` 까지 옮기면 부딪침 | 계획은 그것을 옮기지 않음(생성기 `gen_p617.py` 의 행 목록 86–97·102–118·123–129·147·169) | ⏭️ 행동 안 바뀜 |

계획 수정:
- A1 머리에 `next/pmap.h:1–3` 고지를 옮긴 조각 앞에 둡니다. 변형 A2 = A1 에서 `pagemove` 앞에 `void` 만 더한 것입니다.
- 판정(미리 정함)을 좁힙니다. 각 변형에 대해 python 으로 단언합니다: 컴파일·의존 명령 종료 0, 객체 있음, L1 `OBJECT_MATCH`·`full_span`, funcbytes `same == total == 1` 이고 `object_only` 빔, `__text` 166. 경고는 줄째로 적고, 미정의 기호는 전체 집합을 적습니다.

### 617.2 결과(run `m4p617-p1`, 2026-10-30)

- 명세 `08_build/artifacts/m4p617/spec.json`(생성 scratchpad `gen_p617.py`: NeXTMach 줄은 원문 파일에서 행 번호로 옮기고 python 단언으로 줄 내용을 확인), 스테이지 `08_build/runs/tools/m4p617p1-stage`(975 파일, 더한 파일 2).
- 명령 4 개(A1·A2 의 컴파일과 의존 목록) 모두 종료 0·경고 0, i386 머리 0, 컴파일 명령의 선택지 차이는 M5 줄과 0 입니다(기록 `09_validation/reconstruction/m4-m68k-probe-p617-20261030.json`).
- A1·A2 모두: `__text` 166 B, L1 `OBJECT_MATCH` 사유 없음, `full_span`, `candidate`, 원본에 없는 미정의 0, 외부 정의 `_pagemove` 하나입니다. funcbytes 1/1, `object_only` 빔입니다(`m4-m68k-funcbytes-p617-A1-20261030.json`·`-A2-`). 미리 정한 판정 단언(python)이 모두 통과했습니다.
- 섹션은 `__text` 166·`__cstring` 9 뿐이고, 문자열은 `"pagemove\0"` 으로 원본 0x40ace6d 의 것과 같습니다. 미정의 전체 집합은 `_kernel_map`·`_m68k_page_size`·`_page_size`·`_panic`·`_pflush_user`·`_pmap_expand_kernel`·`_pmap_pte` 이고, COMMON 은 없습니다.
- `vm_map` 의 `pmap` +32 는 바이트가 같은 것으로 확인되었습니다(§617.1 ⚖️ 행).
- A1(암묵 `int`)과 A2(`void`)는 탐침 비교에서 `canon_equal`·`sig_equal` 이 모두 참입니다. 반환형은 바이트로 가를 수 없습니다.

바이트로 가를 수 없는 것(사용자에게 물음):
- 07 파일 이름(원본은 정하지 않음; x86 짝과 NeXTMach 의 이름은 `vm_machdep.c`)
- 반환형(암묵 `int` = NeXTMach·x86 07 / `void`)
- 파일 안 `pte` 정의를 NeXTMach `next/pmap.h` 조각 그대로 둘지(A1) 최소로 줄일지

- 사용자 결정(2026-10-30, AskUserQuestion): ① 파일 이름 "`vm_machdep.c`"(NeXTMach·x86 짝과 같음) ② 반환형 "`void`"(진단 A2 꼴) ③ 파일 안 `pte` 정의는 "NeXTMach 조각 그대로"(A1·A2 꼴, 공유 `pmap.h` 는 바꾸지 않음).

## 618. M4-124 D141 구현 계획 — 07 `src/machdep/m68k/vm_machdep.c`(행 323 일부, OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §617.2 결과와 위 결정입니다. A2 는 1/1·`OBJECT_MATCH` 이고 자료·bss 가 없어 OBJECT_MATCH 객체(`ACCEPTED` 둘 묶음)입니다. 스테이지 `m0p614-a1-stage` 에 `src/machdep/m68k/vm_machdep.c` 는 없고, 있는 것은 x86 `src/machdep/i386/vm_machdep.c` 입니다(find). PROVENANCE 에 그 경로 행은 없습니다(grep 0).

1. 07 `src/machdep/m68k/vm_machdep.c`(D103)를 A2 글에서 scratchpad `gen_p618.py` 로 만듭니다.
   - 머리 고지는 NeXTMach `next/vm_machdep.c:1–13`(고지와 HISTORY) 그대로입니다(D013). `pte` 조각 앞에는 NeXTMach `next/pmap.h:1–3` 고지를 그대로 둡니다(§617.1).
   - 설명 주석은 plan 618 덩이로 둡니다. 내용: 원본 범위 [0x409aaf6, 0x409ab9c), 몸통은 NeXTMach `next/vm_machdep.c:19–46` 그대로이고 바꾼 것은 `NeXT_page_size` → `m68k_page_size` 셋(1997 이름)과 `void`(사용자 결정); import 넷은 스테이지 경로(NeXTMach `vm/vm_param.h`·`next/pmap.h` 는 없음); `pte` 조각은 `next/pmap.h:86–97·102–118·123–129·147·169`; x86 짝의 `kernacc` 는 m68k 원본에 없음.
   - 표시: 바뀐 넷 줄(`void`, 걸음 세 줄)과 `pte` 조각 머리 줄에 `plan 618 (D141)` 표시를 답니다. 진단 표시는 모두 plan 618 로 바꿉니다.
   - 주석 뺀 토큰이 A2 와 같아야 하고, 표시 줄에 `*/` 뒤 글이 없어야 합니다(python).
2. `stage_m68k.py`: `M4FILES[618] = list(M4FILES[614]) + ['vm_machdep.c']`, `EXCEPTS[618] = dict(EXCEPTS[614])`, 머리말 plan 목록에 618 을 더합니다.
3. 회귀:
   - `--plan 614` 재생성(`m0p614-r618-stage`) = 보관본(`m0p614-a1-stage`)이어야 합니다.
   - `m0p618-a1-stage` 와 보관 614 의 차이는 그 파일 하나(973 → 974)와 키 `plan`·`m4_sources`·`files` 여야 합니다(python assert).
   - M5 205 줄(`m5-614.cmd` 가 §614 것과 `cmp` 같음; run `m3p618-b614`·`m3p618-cc1`, 객체·stderr 205 같음, `compare` 의 `differ_unexpected`·`lost` 빔)과 x86(`m4_x86_inputs.py s6ln`·`--plan 618 x86gate`)은 §614 와 같은 조건입니다.
4. 확인 run `m4p618-p1`: F = `@machdep/m68k/vm_machdep.c`, L = A2 글에 맞춤 주석 줄을 같은 자리에 넣은 꼴입니다(줄마다 주석 뺀 토큰 같음).
   - 판정: 종료 0·경고 0·i386 0, F = L(canon·`obj_sig` 모든 칸), L = A2(canon), 1/1, `OBJECT_MATCH` 사유 없음·`full_span`·`candidate` 이어야 합니다.
   - F·L 바이트 차이는 문자열 표·`n_strx` 뿐이어야 합니다.
5. 최종 run `m4p618-a1`(명세 `08_build/artifacts/m4p618/spec.json`: F 만, 바탕 `m0p618-a1-stage`, 객체 `vm_machdep`, `m4_id` 는 §617 의 명시 구간 그대로, `x86_rel` `machdep/i386/vm_machdep.c`, `m5_line` 그대로, `refs["vm_machdep"]` = [p1 L 객체, SHA-256], `known_warnings` 없음): `gate.ok`, 1/1 이어야 합니다.
   - python 확인 `m4-m68k-p618-checks-20261030.json`: 섹션(`__text` 166·`__cstring` 9, 문자열 `"pagemove"` 이 원본 0x40ace6d 와 같음), 외부 정의는 `_pagemove` 하나이고 원본 자리, 지역 없음, COMMON 없음, `__text` 재배치 수(측정)와 모든 참조가 원본 대상과 같음(funcbytes), 미정의 일곱이 모두 원본에 있음, 컴파일 명령 = M5 줄, 의존 i386 0, 입력 사슬 전수.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-vm_machdep.md` 를 먼저 쓰고 `ACCEPTED` 에 둘 묶음 한 줄을 더합니다. 도구를 두 번 돌리고 §614 표와 대조합니다(더한 것 `vm_machdep` 하나).
   - 기대(python 으로 계산해 실행 전에 적음): 객체 40(OBJECT_MATCH 31, CODE+BSS_INFERRED 9), 덮은 행 63/188 그대로(이 객체는 통째 행이 없음), 덮은 바이트 63146 그대로, `partial_rows` 에 `m68k-323`·`m68k-324` 가 더해짐, `object_bytes` 80182 + 166 = 80348(python), `rows_unassigned_before` 그대로입니다.
7. 기록:
   - diff `m68k-vm_machdep.diff`: NeXTMach `next/vm_machdep.c` 전체(1–46 행)와 `next/pmap.h` 의 옮긴 줄(1–3·86–97·102–118·123–129·147·169)을 이름 붙인 발췌로 만들고, 07 파일과 비교합니다.
   - PROVENANCE 새 행(일곱 칸, `nextmach`: `https://github.com/johnsonjh/NeXTMach.git` 커밋 `f6bdb9c3…`, `mk-108.1/next/vm_machdep.c:1–46`·`next/pmap.h:1–3·86–97·102–118·123–129·147·169`, 고지 둘, D141)
   - MODIFICATIONS, DECISIONS D141, 계획 결과와 현재 상태, HANDOFF, 메모리
   - 근거 문서에: 객체 경계는 함수 표 나눔(D140)과 `__cstring` 차례(앞 `trap`, 뒤 `__const`)로 지지되는 가설; 문자열이 하나뿐이라는 것은 추론; `lea _pflush_user,a3; jsr a3@` 는 함수 주소 CSE 로 생긴 것으로 원본 글에 함수 포인터 변수가 있었다는 증거가 아님; 미정의 일곱은 M7 에서 정의자와 맞춰 볼 의무.

관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 618.1 교차검토(codex `gpt-6.1-sol`, task kt2dcded6) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상태 기대값(객체 40·31·9, 63/188, 63146/215874, 29.25%, `object_bytes` 80348, `partial_rows` 에 323·324 더함, `rows_unassigned_before` 그대로)이 맞고, 통째 행이 없어 걸리는 단언은 없음 | §616.1 에서 `P.span` 이 `(0x409aaf6, 0x409ab9c, [])` 를 냄(이번 세션); `m4_m68k_status.py:85–174` 를 열어 `ids` 가 빈 목록일 때 `rows`·`groups`·`kinds` 는 빈 문자열, `seen_rows` 고리는 돌지 않고, `bytes_covered` 는 `seen_rows` 로만 셈을 확인; `object_bytes` 80182+166=80348, `partial_rows` 합집합(python) | ✅ |
| 받아들임 조건: 최종 기록 해시, 컴파일 줄, L1 경로 `08_build/artifacts/m4p618/m4p618-a1/l1-vm_machdep-F.json`, 근거 이름 `m68k-vm_machdep.md` | `m4_m68k_status.py` 의 `l1p`·`ev` 식(같은 범위에서 읽음) | ✅ |
| `M4FILES` 는 `src/machdep/m68k/` + 이름으로 놓으므로 i386 짝과 경로가 다름; M5 줄은 `REFS` 의 고정 run 에서 옴; 머리·x86·덮어쓰기 빼기는 `max(k <= PLAN)` 로 물려받음; `--plan` 은 `EXCEPTS` 에 있어야 함 | `stage_m68k.py:533–538`(`OVLDROP`·`M4HEADERS` 의 `max`), `:439–441`(`X86`), `:546–552`(`M4FILES`), `:595–600`(`ref_lines` 가 `REFS` 의 `run.cmd` 를 읽음), `:707–709`(`int(a[1]) in EXCEPTS`)를 엶 | ✅ |
| 바뀐 import 줄에도 표시를 다는 편이 `next_exception.c:16` 과 맞음 | `next_exception.c:16–18` 을 엶(`#import <mach/boolean.h>\t/* plan 602 (D104): NeXTMach <sys/boolean.h> */` 꼴); NeXTMach `next/pmap.h` 머리가 `#import <sys/types.h>` 를 가짐(§617 에서 엶) | ✅ 1 에 더합니다: `<sys/types.h>`(NeXTMach `next/pmap.h` 가 import 하던 것), `<mach/vm_param.h>`(NeXTMach `<vm/vm_param.h>`), `<vm/pmap.h>`(NeXTMach `<next/pmap.h>`) 셋 |
| 두 고지가 원문과 바이트가 같음 | `gen_p617.py` 의 단언(`head[0]`·`head[-1]`, `P[0..2]`)과 §617 에서 연 `vm_machdep.c:1–13`·`pmap.h:1–3` | ✅ |
| PROVENANCE·MODIFICATIONS 둘 다에 커밋·경로·줄 범위·고지·바뀐 것을 둘 것 | AGENTS.md 의 NeXTMach 규칙(이 대화 머리의 프로젝트 지시); PROVENANCE 1188 행 선례(이번 세션에 엶) | ✅ 7 에 이미 있음; MODIFICATIONS 에도 같은 항목을 둡니다 |
| `-E` 토큰 run 이 HANDOFF 4 절 6.5 에 있으나 §618 에 없음 | `HANDOFF.md:69` 를 엶; 선례 §600 의 run `m4p600-e1`(`08_build/artifacts/m4p600/confirm/preproc.cmd`: 확인 run 의 컴파일 줄에서 `-c` 를 `-E` 로, 출력 `.i`)을 엶; §602–614 의 보관 계획에는 `-E` run 이 없음(grep 0) — F·L 이 주석만 다를 때 빠졌던 것 | ✅ 4 에 run `m4p618-e1` 을 더합니다: F·L 의 `-E` 출력에서 `#` 줄을 뺀 토큰이 같아야 함 |
| x86 조건을 글로 적을 것(`L2_FORMS`·`L2_EXPECT`, 앞붙임 `s6ln`, `ok`, 일곱 같음, `v183.34` 경로 0) | `m4-x86-inputs-p614-20261030.json:6–10`(forms·expect·prefix `s6ln`)을 엶 | ✅ 3 에 적습니다 |
| M5 `compare` 는 결과를 종료 상태로 강제하지 않으니 `differ_unexpected == lost == []` 를 단언할 것 | `stage_m68k.py:679–685` 를 엶(요약을 쓰기만 함) | ✅ python 단언으로 둡니다 |
| 기록 이름을 미리 적고, `ACCEPTED` 는 최종 기록을 해시할 것 | §614.2 의 이름 꼴 | ✅ 아래에 적습니다 |
| run ID `m3p618-b614`·`m3p618-cc1`·`m4p618-p1`·`m4p618-a1` 은 쓰이지 않음 | `08_build/runs/REGISTRY` grep 0, `08_build/runs` 목록 grep 0(이번 세션) | ✅ 준비 직전에 다시 봅니다 |
| A2 의 `__text` 참조는 10 | `08_build/artifacts/m4p617/m4p617-p1/l1-vm_machdep-A2.json:11`(`"references": 10`)을 엶 | ✅ 확인 기록에 측정값으로 적습니다 |

계획 수정(기록 이름): 확인 `m4-m68k-probe-p618-p1-20261030.json`, funcbytes `m4-m68k-funcbytes-p618-F/L-20261030.json`·`-a1-`, `-E` 비교 `m4-m68k-p618-e1-20261030.json`, 최종 `m4-m68k-p618-final-20261030.json`, 확인 `m4-m68k-p618-checks-20261030.json`, M5 `m3-m68k-p618-compare-20261030.json`·`-b614-`, x86 `m4-x86-inputs-p618-20261030.json`, 상태 `m4-m68k-status-p618-20261030.json`.

### 618.2 결과(2026-10-30)

- 1·2: 07 `src/machdep/m68k/vm_machdep.c`(106 행, SHA `f7df683a…`)를 scratchpad `gen_p618.py` 로 A2 에서 만들었습니다. 주석 뺀 토큰이 A2 와 같고 L(`08_build/artifacts/m4p618/src/vm_machdep_L.c`)과 줄마다 같으며, 표시 줄 일곱(import 셋, `void`, 걸음 셋)과 `pte` 조각 머리 줄의 `*/` 뒤에 글이 없습니다(python 단언). `stage_m68k.py` 723 → 725 행(`M4FILES[618]`·`EXCEPTS[618]`·머리말 목록)입니다.
- 3: `--plan 614` 재생성(`m0p614-r618-stage`) = 보관본(매니페스트와 973 파일 해시)입니다. `m0p618-a1-stage`(974 파일)와 보관 614 의 차이는 그 파일 하나와 키 `files`·`m4_sources`·`plan` 입니다(python assert). M5: `m5-614.cmd` 가 §614 것과 `cmp` 같고, `m5-618.cmd` 와의 차이는 계획 번호 614 → 618 뿐입니다. run `m3p618-b614`·`m3p618-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p618-compare-20261030.json`, `-b614-`) `differ_unexpected`·`lost` 빔(python 단언), 요약 차이는 `stage_vs_test_stage` 에 새 파일 하나입니다. x86 `m4-x86-inputs-p618-20261030.json` `ok`(forms `l2_build_forms-s6p398.tsv`, expect `l2_expect-s6p398.json`, `s6ln`), `--plan 618 x86gate` 일곱 같음·`v183.34` 경로 0 입니다.
- 4: run `m4p618-p1`(`m4-m68k-probe-p618-p1-20261030.json`): F·L 종료 0·경고 0·i386 0·`OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 1/1(`m4-m68k-funcbytes-p618-F/L-20261030.json`)입니다. F = L(canon·`obj_sig` 모든 칸), L = A2(canon)이고, 바이트 차이 8440 은 모두 문자열 표(8158)·`n_strx`(282)에 있습니다. run `m4p618-e1`(`m4-m68k-p618-e1-20261030.json`, `ok`): F·L 의 `-E` 출력에서 `#` 줄을 뺀 토큰 3724 개가 같고, i386 경로 0, stderr 빔입니다.
- 5: run `m4p618-a1`(`m4-m68k-p618-final-20261030.json`, SHA `2e3a6a90…`): `gate.ok`, 1/1(`m4-m68k-funcbytes-p618-a1-20261030.json`)입니다. 확인 `m4-m68k-p618-checks-20261030.json`(`ok` 참): 섹션 166·9, 문자열이 원본과 같음, `__text` 재배치 10·참조 10 모두 원본과 같음, 외부 정의 `_pagemove` 하나가 원본 자리, 지역·COMMON 없음, 미정의 일곱 모두 원본에 있음, 컴파일 명령 = M5 줄, 의존 53 파일 사슬 문제 0·i386 0 입니다.
- 6: 근거 `06_reconstruction/evidence/m68k-vm_machdep.md`(상태 도구 전)와 diff `m68k-vm_machdep.diff`(NeXTMach 발췌 대비 51 행). `ACCEPTED` 에 한 줄을 더했습니다(`m4_m68k_status.py` 175 → 176 행). 상태 도구 두 번 실행이 같고, 상태표 41 → 42 행(더한 것 `vm_machdep` 하나, 머리 줄의 `updated plan` 614 → 618)이며, 요약은 미리 계산한 값과 python 으로 같습니다: 40 객체(OBJECT_MATCH 31, CODE+BSS_INFERRED 9), 덮은 행 63/188, 63146/215874 B(29.25%), `partial_rows` 에 323·324, `object_bytes` 80348, `rows_unassigned_before` 그대로입니다(`m4-m68k-status-p618-20261030.json`).
- 7: PROVENANCE 1188 → 1189 행(일곱 칸, 경로 겹침 없음), MODIFICATIONS 723 → 724 행, DECISIONS D141(144 → 145 행), "현재 상태와 다음 일" 을 고쳤습니다(받아들인 객체 40, 다음 후보 줄의 낡은 `m68k_init` 문구도 고침).

판정: 미리 정한 관문(명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음)을 모두 통과했습니다.

## 619. M4-125 세부 계획 — m68k `trap.c`(행 315–320) 조사와 첫 진단 N1(07 변경 없음; 코딩 전, 2026-10-30)

고른 까닭: 사용자 결정(2026-10-30, AskUserQuestion) "trap.c (행 315–320)". 함께 확인한 사실: 64 비트 보조 함수의 `__bdiv`·`__lshldi3` 는 Darwin `objc/spec_sys:1490·1498·2901·2913` 의 "GNU library"(`libc/shlib_obj/bdiv.o`·`lshldi3.o`)에 있으나, 그 소스는 `01_resources` 여섯 갈래(파일 이름·내용 grep)와 실기 `/NextDeveloper/Source`(gcds `find`, 읽기만)에 없습니다. 실기에서 나온 것은 관계없는 `GNU/gcc/config/m68k/fpgnulib.c` 하나였습니다. §615 의 "참고 글 없음" 은 §422 의 mk-108.1 검색만 근거로 한 것이었고, 이번에 범위를 넓혀 다시 확인했습니다.

확인한 사실(이번 세션; 함수 표·재고 표·`symbols.tsv`·`macho.json`·otool 목록을 python 으로 읽음):
- 원본 범위 [0x40996b8, 0x409a8ba) 4610 B, 함수 9 개(모두 confirmed): `_trap` 2444(행 315), `_unix_syscall` 466·`_unix_syscall_return` 198·`_do_trace` 34·`_check_for_ast` 428(행 316), `_traceback` 202(행 317), `_do_writeback` 390(행 318), `_move_space` 240(행 319, 재고 표는 NeXTMach `next/locore.s` 로 분류), `_bmap_parity_error` 208(행 320). 여섯 행 모두 정확 행입니다.
- 참고 글:
  - NeXTMach `next/trap.c`(1346 행)에는 `trap`(197)·`unix_syscall`(865)·`traceback`(1113)·`do_writeback`(1152)이 있고, `dotrace`(1083)는 1997 의 `do_trace` 와 이름이 다릅니다.
  - NeXTMach 에만 있는 `syscall_trace`·`mach_syscall_trace`·`old_syscall`·`fp_trace` 는 원본 기호표에 없습니다(grep 0). `nosys` 는 원본에 있으나 0x400beda(다른 객체)입니다.
  - NeXTMach 에서 `move_space` 는 `next/locore.s:472` 의 어셈블리입니다. 1997 `_move_space` 는 C 범위 안에 있고 `__move_space`(0x40014be)와 `_exception_from_kernel`(0x40476d4)을 부릅니다. `_move_space_fault`(0x4001522)는 `_trap` 안의 비교 상수입니다(목록 192909 행 `cmpl #0x4001522`; §619.1).
  - `unix_syscall_return`·`check_for_ast` 는 x86 07 `machdep/i386/trap.c:722·771` 에 i386 판이 있습니다. `bmap_parity_error` 는 어떤 참고 트리에도 없습니다.
- 자료(원본에서 이 범위가 가리키는 곳):
  - `__data` `_trap_type` [0x40b2c10, 0x40b2cba) 170 B(두 표를 합친 구간이고, C 배열 하나의 크기로 확정된 것은 아님). 앞 138 B 는 NeXTMach `trap.c:161–188` 의 `trap_type[]` 22 항목과 끝 항목이 차례·이름까지 같습니다(항목 6 B: `short` + 포인터, 2 바이트 정렬). 뒤 32 B 는 이름 없는 `short` 16 개(0, 0, 4, 4, -1, -1, -1, 0x34, -1, 0xc, 0x18, 0x54, -1, -1, -1, -1)이고 `trap` 이 0x4099980·0x409a02a 에서 `lea 0x40b2c9a` 로 읽습니다. 예외 틀 형식별 크기 표로 보이나 추론입니다.
  - COMMON: `_traceback_jb`·`_traceback_recursive`·`_traptrace`(원본 섹션 6). NeXTMach `trap.c:157–159` 의 `int nsysent, traptrace; volatile int traceback_recursive; label_t traceback_jb[2];` 와 맞습니다(`_nsysent` 는 원본 `__data` 0x40ae114).
  - 그 밖에 `__common` 피연산자 주소 16 개(이름 15; `_active_u+4` 가 겹침), `__data` 의 `_sysent`·`_nsysent`·`_fault_error`·`_probe_recover`·`_tick` 을 읽습니다. 다른 객체의 것입니다.
- 문자열: `trap_type` 이름 22 개를 포함해 [0x40acb10, 0x40ace6d) 861 B 가 이 객체 차례에 있습니다(앞은 `swapgeneric` 의 `initrootnet` 문자열, 뒤는 `"pagemove"`). `"parity error"`(0x40ac42b)는 다른 객체 차례에 있습니다. 원본 `__cstring` 의 flags 가 0x2(`S_CSTRING_LITERALS`)이므로 링커가 같은 문자열을 합친 것으로 봅니다(추론).
- 범위 밖 `__text` 주소 피연산자 26 개(회복 표지 포함) 가운데 직접 호출 대상은 22 개이고 모두 다른 객체입니다(`printf` 는 직접 호출 6·주소 적재 2, `panic` 3, `vm_fault`, `exception*`, `thread_*`, `issig`·`psig`, `setjmp`·`longjmp`, `gdb_from_trap` 등).
- NeXTMach `do_writeback` 의 `static struct { … } wb;`(1157 행)에 해당하는 bss 참조는 원본 범위에 없습니다.
- 1997 스테이지(`m0p618-a1-stage`)에서 NeXTMach `trap.c` import 32 개(python) 가운데 그대로 풀리지 않는 것: `bsd/syscalls.c`, `sys/thread_status.h`·`sys/exception.h`·`sys/kern_return.h`(1997 은 `mach/`), `vm/vm_param.h`(`mach/`), `next/trap.h`·`next/scr.h`·`next/cframe.h`(없음), `next/psl.h`·`next/reg.h`·`next/vmparam.h`·`next/spl.h`(1997 은 `bsd/m68k/`·`machine/`). `next/cpu.h`·`next/event_meter.h` 는 스테이지 `bsd/next/` 에 있습니다.

방법(진단 N1; 명세 `08_build/artifacts/m4p619/spec.json`, run `m4p619-p1`, 바탕 `m0p618-a1-stage`, 진단 객체 이름 `trap`, `m4_id` 는 행 여섯 `["m68k-315", …, "m68k-320"]`(정확 행이 이어짐), `x86_rel` `machdep/i386/trap.c`; scratchpad `gen_p619.py`):
- N1 = NeXTMach `next/trap.c` 를 그대로 두고 import 줄만 1997 경로로 바꾼 글입니다: `sys/thread_status.h`→`mach/thread_status.h`, `sys/exception.h`→`mach/exception.h`, `sys/kern_return.h`→`mach/kern_return.h`, `vm/vm_param.h`→`mach/vm_param.h`, `next/psl.h`→`m68k/psl.h`, `next/reg.h`→`m68k/reg.h`, `next/vmparam.h`→`m68k/vmparam.h`, `next/spl.h`→`machine/spl.h`(D104). `next/cframe.h` 는 스테이지 `bsd/m68k/cframe.h` 와 바이트가 같으므로 `<m68k/cframe.h>` 로 바꿉니다(§619.1). `next/trap.h`·`next/scr.h`·`bsd/syscalls.c` 는 변형 `inc` 로 NeXTMach mk-108.1 사본을 줍니다(진단 전용, 07 아님). 스테이지의 `next/cpu.h`(`bsd/next/`)를 쓰면 원본에 없는 COMMON 이 생길 수 있으므로(§505·§507) COMMON 을 따로 셉니다.
- 목적은 받아들임이 아니라 측정입니다: 컴파일이 어디서 멈추는지(첫 오류와 그 종류), 되면 함수별 크기·funcbytes 와 원본 차이입니다. 결과로 다음 진단(1997 판 함수별 작성)의 범위를 정합니다.

측정: 종료·경고·첫 오류(줄·종류), i386 머리 0, 컴파일 명령 = M5 줄; 객체가 생기면 함수 목록·크기·funcbytes(`m68k_funcbytes.py 0x40996b8 0x409a8ba`)·섹션·자료 크기·COMMON·원본에 없는 미정의.

판정(미리 정함; 07 은 바꾸지 않음): 결과를 적고 다음 진단을 계획합니다. N1 이 받아들임 조건을 채울 것은 기대하지 않습니다.

관문: 컴파일 명령 = M5 줄 + 변형 `inc` 의 `-I` 하나, i386 0 입니다(객체가 생긴 경우). 종료·오류·경고는 기록합니다.

### 619.1 교차검토(codex `gpt-6.1-sol`, task kcqo8rlie) 판정과 계획 수정

먼저 제 잘못입니다: (1) `_move_space` 가 `_move_space_fault` 를 부른다고 적었으나, 부르는 것은 `__move_space` 와 `_exception_from_kernel` 이고 `_move_space_fault` 는 `_trap` 의 비교 상수입니다. (2) "호출 대상 26" 은 범위 밖 `__text` 주소 피연산자 수였고, 직접 호출 대상은 22 개입니다. (3) "`__common` 16 이름" 은 주소 16 개·이름 15 개입니다. 위 사실 줄을 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 아홉 함수 크기 합 4610, 여섯 행이 정확·이어짐, 목록 `span()` 통과 | python(이번 세션, 함수 표 awk 출력과 재고 표 행 314–321) | ✅ |
| `_move_space` 는 `__move_space`·`_exception_from_kernel` 을 부르고, `_move_space_fault` 는 `_trap` 안 비교 | 목록 192907–192910 행(`cmpl #0x4001522,a0@(0x70:w)`), 193984–193990 행(`bsr 0x40014be`), 193996 행(`bsr 0x40476d4`)을 엶 | ✅ 고침 |
| 직접 호출 대상 22, `printf` 직접 6·주소 적재 2 | python 으로 범위 안 `bsr`/`jsr` 절대 대상을 셈: 22 개(이름 목록 확인), `printf` 직접 6·그 밖 참조 2 | ✅ 고침 |
| `__common` 은 주소 16·이름 15(`_active_u+4`) | 앞의 python 출력(`_active_u`·`_active_u+4` 따로) | ✅ 고침 |
| 170 B 는 두 표를 합친 구간이지 배열 크기로 확정된 것이 아님 | — | ✅ 문구 고침 |
| 원본 범위에 `__bss` 피연산자 없음(정적 `wb` 직접 참조 없음); 간접 접근은 배제하지 못함 | `macho.json` 섹션 목록(`__bss` 0x40b317c, 9420 B)과 앞의 참조 집계(섹션별로 `__bss` 0 건) | ✅ |
| `S_CSTRING_LITERALS` 는 합침 이력·객체 소유를 증명하지 않음 | — | ✅ 이미 "추론" 으로 적음 |
| import 32 가운데 20 은 그대로 풀리고 12 는 안 풀림; 고친 여덟은 모두 풀림 | 이번 세션의 스테이지 `find` 결과(위 사실 줄과 같음) | ✅ |
| `next/cframe.h` 는 스테이지 `m68k/cframe.h` 와 바이트가 같아 `inc` 대신 고쳐 쓸 수 있음 | `cmp` NeXTMach `next/cframe.h` 와 스테이지 `src/bsd/m68k/cframe.h`: 같음 | ✅ N1 을 `<m68k/cframe.h>` 로 고침 |
| `inc` 넷은 앞선 include 뿌리에 없어 스테이지 파일을 가리지 않음 | `find` 로 `next/trap.h`·`next/scr.h`·`bsd/syscalls.c` 가 스테이지에 없음을 확인(이번 세션) | ✅ |
| 머리가 풀려도 API 가 달라 컴파일이 막힐 것: `thread->pcb->saved_regs`(NeXTMach `trap.c:399`), `thread->u_address`(518·539·656) | `trap.c:397–401`·`518`·`539`·`656` 을 엶; 스테이지 `machdep/m68k/thread.h`·`kern/thread.h` 에서 `saved_regs`·`u_address` grep 0 | ✅ N1 은 첫 오류를 재는 진단으로 둡니다 |
| funcbytes 는 길이가 다르면 바이트 비교를 건너뜀 | `m68k_funcbytes.py:180–186` 을 엶(`if oe - v != e - a: … continue`) | ✅ 측정에 짝 없는 함수와 길이 다른 함수를 따로 적습니다 |
| 컴파일 명령은 `inc` 의 `-I` 하나만 더해진 M5 줄이어야 함 | `m4_m68k_probe.py` 의 `inc` 처리(`:223`, 기존 `-I` 뒤에 더함) | ✅ 관문 문구를 "M5 줄 + 변형 `inc` 의 `-I` 하나" 로 고칩니다 |

계획 수정: 측정에 전처리 조건(`DEBUG`·`NCPUS` 등의 값), 의존 파일의 출처, COMMON 이름·크기(`_nsysent` 포함), 지역 bss 기호, NeXTMach 이름과 짝이 없는 원본 함수(다섯: `unix_syscall_return`·`do_trace`·`check_for_ast`·`move_space`·`bmap_parity_error`)를 더합니다. N1 이 객체를 내지 못하면 다음 계획에서 함수 하나씩(`traceback`·`do_writeback` 등)의 작은 진단으로 나눕니다.

### 619.2 결과(run `m4p619-p1`, 2026-10-30)

- 명세 `08_build/artifacts/m4p619/spec.json`(생성 scratchpad `gen_p619.py`: NeXTMach 글에서 import 아홉 줄만 바꾸고 줄마다 진단 표시; `inc` 는 NeXTMach `next/trap.h`·`next/scr.h`·`bsd/syscalls.c`), 스테이지 `08_build/runs/tools/m4p619p1-stage`(978 파일, 더한 파일 4). 탐침의 선택지 비교는 M5 줄과 차이 없음으로 나왔습니다.
- 컴파일은 종료 1, 객체 없음입니다(기록 `09_validation/reconstruction/m4-m68k-probe-p619-20261030.json`). 의존 목록은 종료 0 입니다. stderr 36 줄(python 집계): 선언 없는 이름 12 줄, 없는 구조체 칸 16 줄(`saved_regs` 6·`u_address` 10), 경고 2 줄(`sysent` 암묵 extern, `do_writeback` switch 앞 도달 못 하는 코드).
  - 선언 없는 이름: `TRACE_PENDING`·`AST_CLR`·`TRACE_AST`·`TRACE_USER` 는 NeXTMach `next/pcb.h` 에만 있고 스테이지에는 없습니다. `FC_SUPERI`·`FC_SUPERD`·`SIZE_BYTE`·`SIZE_WORD`·`SIZE_LONG` 은 NeXTMach `next/mmu.h` 에 있고 스테이지 `bsd/m68k/mmu.h` 에도 있습니다(N1 은 그 머리를 import 하지 않음).
  - 없는 칸: `thread->pcb->saved_regs`(`trap`·`old_syscall`·`unix_syscall`), `thread->u_address`(같은 함수들).
  - 오류가 없는 함수: `traceback`(1113–1150 행)에는 오류 줄이 없습니다.
- 원인: 스테이지의 m68k `struct pcb`(`07_kernel/v183.34/m68k/src/machdep/m68k/thread.h`, M5 덮어쓰기)는 `pcb_head[0x48]`·`pcb_regs`(+0x48)·`pcb_regs_valid`(+0x4c)·`pcb_pad50`·`pcb_flags`(+0x54)만 둔 부분 배치입니다. 1997 `trap`·`unix_syscall`·`check_for_ast` 가 쓰는 pcb 칸과 NeXTMach `next/pcb.h` 의 `TRACE_*`·`AST_*` 는 이 머리에 없습니다. 따라서 이 객체의 받아들임은 §615 의 `pcb.c` 와 같은 전제(공유 m68k `thread.h` 의 `struct pcb` 를 1997 배치로 넓힘, 그 머리를 쓰는 M5 객체 회귀)에 걸립니다.

판정(미리 정한 대로): 결과를 적었습니다. pcb 에 기대지 않는 함수(`traceback`·`do_writeback`·`move_space`·`bmap_parity_error`)는 함수별 진단을 할 수 있으나, 객체 전체의 받아들임에는 `struct pcb` 결정이 필요하므로 다음 방향을 사용자에게 묻습니다.

- 사용자 결정(2026-10-30, AskUserQuestion): "struct pcb 배치 조사".

## 620. M4-126 세부 계획 — 1997 m68k `struct pcb` 배치 조사(07·도구·표 변경 없음; 코딩 전, 2026-10-30)

목적: `pcb.c`(행 308–309)와 `trap.c`(행 315–320)의 공통 전제인 1997 m68k `struct pcb` 의 칸 배치를 원본 바이트에서 모으고, NeXTMach `next/pcb.h` 와 대조합니다. 공유 머리 `07_kernel/v183.34/m68k/src/machdep/m68k/thread.h` 를 어떻게 넓힐지는 이 조사 뒤 따로 계획하고 사용자에게 묻습니다.

확인한 사실(이번 세션; scratchpad `odis.py` 로 원본 0x4096924–0x4096a70 을 풀어 읽음, `symbols.tsv`·`macho.json`):
- 원본에는 STABS 가 없습니다(`symbols.tsv` 의 `debug` 칸 3809 행 모두 0). m68k SDK 목록(`08_build/artifacts/m0p413/sdk-m68k.target-sha.txt`)에 pcb 머리는 없습니다(grep: `mach/m68k/thread_status.h` 하나만 걸림). 배치 근거는 원본 바이트와 참고 글뿐입니다.
- `thread->pcb` 는 +36(0x24)입니다(`_thread_user_state` 0x409695e `moveal %a0@(36),%a2`; 스테이지 `kern/thread.h:110` 의 `struct pcb *pcb`).
- `_pcb_init`(0x4096924): `_zalloc`(0x4055b56, 인자 `_pcb_zone` 0x40c9780)의 결과를 `thread+36` 에 두고, `_bzero`(0x4092e12)로 0x1a0 = 416 B 를 지웁니다. 1997 `struct pcb` 는 416 B 로 보입니다(추론: bzero 크기).
- `_thread_user_state`(0x4096952): `pcb+0x4c` 가 0 이면 크기 312(`_cpu_type` 바이트가 0 아닐 때 580)를 `_kalloc`(0x404a200)으로 할당해 `pcb+0x4c` 에 두고, 그 끝에서 0x48 앞 주소를 `pcb+0x48` 에 둔 뒤 0x48 B 를 지우고 돌려줍니다. 아니면 `pcb+0x48` 을 돌려줍니다. 따라서 +0x4c 는 지연 할당되는 저장 영역의 포인터이고 +0x48 은 그 안의 사용자 레지스터 틀(72 B) 포인터입니다. 스테이지 머리는 +0x4c 를 `int pcb_regs_valid` 로 두었으나, 바이트로는 포인터입니다(값의 0 여부만 시험하므로 M5 객체의 바이트는 같았던 것으로 봅니다).
- Darwin 0.1 `machdep/i386/thread.h:126` 의 `struct pcb` 도 "saved user state is external to the pcb, and is created lazily"(`save_area`)인 꼴입니다. NeXTMach `next/pcb.h` 의 `struct pcb` 는 `struct regs pcb_r`(첫 칸)·`saved_regs`·`pcb_szpt`·`mmu_tt1`·`pcb_fpc_i`·`pcb_fpc_e`·`thread_user_reg`·`u_char pcb_flags` 이고, `AST_SCHEDULE`·`TRACE_AST`·`TRACE_USER`·`TRACE_PENDING`·`AST_CLR` 를 정의합니다.
- 스테이지 부분 배치의 `pcb_flags` 는 +0x54 `int` 입니다(M5 덮어쓰기의 주석).

방법(분석만; scratchpad `pcb_survey.py`, 기록 `09_validation/reconstruction/m68k-pcb-survey-p620-20261030.json`):
0. 도구(2026-10-30 사용자 허락 "네 허락합니다" 뒤 더함): Ghidra 디컴파일 결과 `05_ida/exports/m68k/ghidradec-functions/functions/<주소>.c`(3156 함수)를 대상 함수의 읽기 안내로 씁니다. IDA 는 작업 DB `05_ida/databases/m68k-os42j.i64`(SHA-256 `61298ed3…`)의 scratchpad 사본을 MCP 로 읽기 전용(자동 분석 끔)으로 열어 교차 참조만 씁니다. 이 IDA 에서는 Hex-Rays 를 쓸 수 없습니다(`init_hexrays` 실패, `decompiler-capability.json` 의 `plugin_initialized: false` 와 같음). 원본 작업 DB 의 해시는 연 뒤에도 같습니다(`sha256sum -c`). 두 도구의 출력은 해석이므로, 칸 하나하나를 원본 목록의 명령으로 확인한 것만 기록에 근거로 씁니다. 예: `_thread_user_state` 의 Ghidra 출력(`04096952.c`)은 위 사실 줄(+0x24·+0x4c·0x138/0x244·+0x48)과 같습니다.
1. 원본 접근 모으기(python, otool 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`):
   - 범위 안 함수마다, `aX@(36)` 를 주소 레지스터 `aY` 로 읽는 줄(`moveal …@(36),aY`)을 찾고, 같은 함수 안에서 `aY` 가 다시 정의되기 전까지 `aY@(d)`·`aY@`(d=0) 꼴 접근을 칸 오프셋 d·크기(`b`/`w`/`l`)·읽기/쓰기로 적습니다. 분기를 따라가지 않는 직선 근사이므로, 대상 함수의 결과는 사람이 원본 풀이로 하나씩 확인합니다.
   - 대상: `pcb.c` 후보 행 308–309 의 함수 18 개, `trap.c` 범위의 함수 9 개, 그리고 `__text` 전체(+36 칸을 가진 다른 구조체가 섞이므로 전체 결과는 "후보" 로만 적음).
   - `_active_threads`(0x40b5648) 에서 읽은 레지스터로 시작하는 접근은 "thread 확실" 로 따로 표시합니다.
2. 크기 사실: `_pcb_init` 의 0x1a0, `_thread_user_state` 의 312/580·0x48, `pcb_zone` 의 원소 크기(`zinit` 호출을 `_pcb_module_init` 에서 찾음)를 모읍니다.
3. NeXTMach 배치 측정: NeXTMach `struct pcb` 각 칸의 오프셋과 하위 구조체(`struct regs`, `NeXT_saved_state`, `mmu_030_tt`/`mmu_040_tt` union, `fpc_internal`, `fpc_external`)의 크기를 python 손계산이 아니라 실기 `cc-744.13` 의 `cc -S` 로 잽니다. 탐침 파일(scratchpad 생성, `08_build/artifacts/m4p620/src/pcb_offsets.c`)은 NeXTMach 트리(`01_resources/upstream/nextmach/mk-108.1`)를 include 뿌리로 하고 `int off[] = { (int)&((struct pcb *)0)->칸, … , sizeof(…) }` 꼴 초기값을 둡니다. run `m4p620-s1`(`-arch m68k -S`), 출력 `.s` 의 `.long` 값을 python 으로 읽습니다. 컴파일이 안 되면 오류를 적고, 그 경우에만 python 손계산(2 바이트 정렬, ABI 기록 `m0-abi-m68k-20261009.json`)으로 대신하되 그렇게 적습니다.
4. 대조표: 원본 오프셋마다 접근 근거(함수·주소·명령)와 NeXTMach 후보 칸(오프셋이 같은 것), 맞지 않는 것을 적습니다.

판정(미리 정함): 07·공유 머리·도구는 바꾸지 않습니다. 결과로 (a) 1997 배치에서 확정된 칸, (b) NeXTMach 와 같은 칸, (c) 근거가 없는 칸을 나누어 적고, 공유 머리를 넓히는 꼴을 다음 계획에서 사용자에게 묻습니다.

관문: 원본·참고 파일의 SHA-256 을 기록에 둡니다. 실기 run 은 종료 0 이어야 측정값으로 씁니다.

### 620.1 교차검토(codex `gpt-6.1-sol`, task k3870xy2z) 판정과 계획 수정

먼저 제 잘못입니다: (1) 1 단계의 찾는 꼴을 `moveal …@(36),aY` 로 적었으나, 이 otool 목록의 꼴은 `movel …@(0x24:w),aY` 입니다. (2) 검증 중 "staged pcb 구조체 STABS 를 가진 객체" 를 `pcb:T` 로 세어 M5 105·M4 18 을 얻었으나, `inpcb:T` 가 섞인 값이었습니다(`in_bootp` 는 `inpcb:T` 만 있음). 정의 `pcb:T…=s88` 로 다시 세면 M5 92·M4 17 로 codex 값과 같습니다. (3) 직선 근사는 locore 처럼 인자로 받은 pcb 를 쓰는 곳을 놓칩니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `thread->pcb` +0x24(목록 189168) | 목록 189168–189170 행을 엶(`movel a0@(0x24:w),a2`) | ✅ |
| `_pcb_module_init` 이 `zinit` 첫 인자로 0x1a0 을 줌(189139–189145) — 할당 크기와 지우는 크기 모두 416 B | 189139–189145 행(`pea 0x1a0:w`, `bsr 0x4054fe2`, 결과를 `0x40c9780` 에)과 189153–189158 행을 엶 | ✅ 사실 줄에 더함 |
| `_pcb_terminate` 가 +0x4c 를 `_kfree` 꼴 호출에 크기와 함께 넘김(189548–189557) | 그 줄을 엶(`movel a2@(0x4c:w),d1`, 크기 0x138/0x244, `bsr 0x404a2c4`) | ✅ +0x4c 는 포인터 |
| +0x48 은 늘 할당 블록 안이 아니라 바뀌는 "현재 저장 상태" 포인터: `_check_for_ast` 가 잠시 바꿨다 되돌림(193627–193629, 193744–193745) | 그 줄을 엶(`movel a0@(0x48:w),d5; movel a5,a0@(0x48:w)` … `movel d5,a0@(0x48:w)`) | ✅ 사실 줄을 고침 |
| locore `__switch_context` 는 `sp@(4)` 로 받은 pcb 에서 +0x54·+0x58·+0x5c·+0x134·+0x194 를 씀(1480–1516); `__stack_handoff` 도 같음; C `_switch_context`·`_stack_handoff` 는 pcb 를 인자로 넘김(189125–189132, 189093–189095) | 목록 1478–1518 행과 1582–1621 행, 189093–189095·189125–189132 행을 엶. 더해 읽은 것: +0x00 에서 `moveml d0–a7`(16 낱말), `a0@(0x3c)` 가 sp, +0x54 의 바이트 비트 6, +0x58 은 `tt1`(`pmove`/`movec`), +0x5c 는 `fsave`/`frestore`, +0x134 는 `fmovemx fp0–fp7`, +0x194 는 `fmoveml fpc/fps/fpi` | ✅ 1 단계를 바꿈 |
| `__return_with_state` 는 pcb 가 아니라 저장 상태 포인터를 받음 | 1615–1621 범위의 0x4001b16 `movel sp@(0x4:w),sp` 를 엶 | ✅ 포인터 종류를 나눔 |
| NeXTMach 배치(python, `MONITOR` 0): `regs` 0x4c, `pcb_r` 0·`saved_regs` 0x4c·`pcb_szpt` 0x50·`mmu_tt1` 0x54·`pcb_fpc_i` 0x58·`pcb_fpc_e` 0x130·`thread_user_reg` 0x19e·`pcb_flags` 0x1a2, 합 0x1a4 = 420 | 제가 python 으로 다시 계산(`excp_frame` 10 B 는 `reg.h` 의 정의를 열어 셈, 정렬은 ABI 기록 `m0-abi-m68k-20261009.json:1320–1335` 의 `alignof int` 2·`alignof struct{char}` 2 를 엶): 같은 값 | ✅ 3 단계를 python 계산으로 바꿈 |
| 컴파일러 탐침은 `-I mk-108.1` 만으로는 안 됨: `lock.h:111–116`(`cpus.h`·`mach_ldebug.h`·`mach_ipc_tcache.h`), `mmu.h:12–15`(`gdb.h`), `NeXT_saved_state` 는 `next/thread_status.h:65–68` 의 `KERNEL` 안 | 세 곳을 엶 | ✅ 탐침은 이번 계획에서 빼고, 계산이 python 임을 기록에 적음 |
| 스테이지 `struct pcb` 정의 STABS 를 가진 객체: M5(`m3p618-cc1`) 92, 받아들인 M4 17 | python 재집계(정의 꼴 `pcb:T…=s88`): M5 92, M4 17(`vm_unix`·`autoconf`·`dma`·`fd_cmds`·`fd_driver`·`fd_io`·`fd_subr`·`np`·`snd_device`·`snd_dspcmd`·`snd_dspdev`·`snd_dspqueue`·`snd_rcv`·`snd_reply`·`APM`·`machine_clock`·`machdep`) | ✅ 기록에 둠(머리를 넓히면 이 객체들의 STABS 가 바뀜) |
| 칸을 실제로 쓰는 M5 객체: `init_main`(`USER_REGS`), AST 매크로(`m68k/ast.h:14–15`, `pcb_flags \|= 0x10000000`) | `ast.h` 10–17 행과 `init_main.c:454` 를 엶 | ✅ 기록에 둠 |
| 접근 너비와 C 칸 형을 따로 적고, 풀지 못한 접근 목록을 두고, `thread->u_address` 는 따로 다룰 것 | — | ✅ 방법에 더함 |

계획 수정(1 단계를 바꿈):
- 주 방법은 함수 단위 읽기입니다. 대상은 pcb.c 후보 18 함수, trap 범위 9 함수, 그리고 이들이 부르는 locore 어셈블리(`__switch_context`·`__switch_context_discard`·`__stack_handoff`·`__return_with_state` 등)입니다. 함수마다 thread·pcb·`pcb+상수`·할당 블록·저장 상태 포인터를 따로 따라가고, Ghidra 출력은 읽기 안내로만 씁니다. 칸마다 (오프셋, 접근 너비·명령, 함수·주소, 포인터 종류) 를 적고, 판단하지 못한 접근은 따로 적습니다.
- `__text` 전체의 `@(0x24:w)` 찾기는 빠뜨린 함수를 찾는 보조로만 씁니다.
- 3 단계: NeXTMach 배치는 위 python 계산을 씁니다(컴파일러 탐침 run `m4p620-s1` 은 하지 않음).
- 기록에 머리를 넓힐 때의 영향 범위(M5 92·M4 17 객체의 STABS, 칸을 쓰는 객체)를 둡니다.

### 620.2 결과(2026-10-30)

- 조사 도구 scratchpad `pcb_survey.py`(대상 31 함수의 변위 접근 줄, Ghidra 출력의 pcb 변수 오프셋, `_active_threads` 에서 시작하는 직선 후보)와 수동 분류를 기록 `09_validation/reconstruction/m68k-pcb-survey-p620-20261030.json` 에 두었습니다. 표의 근거 명령은 모두 원본 목록에 그 글자가 있는지 python 으로 단언했습니다. IDA 사본은 이번 조사에서 열기만 했고(교차 참조는 쓰지 않음), Ghidra 출력은 읽기 안내로만 썼습니다.
- 1997 m68k `struct pcb`(416 B) 원본 배치:

| 오프셋 | 원본에서 본 쓰임(근거 예) | NeXTMach 대응 |
|---|---|---|
| 0x000–0x03f | d0–d7/a0–a7 저장(`__switch_context` 0x4001908 `moveml …,a0@(0x0:w)`, 0x400195c `a0@(0x3c:w),sp`; `_stack_attach` 의 +0x24·+0x28·+0x38·+0x3c) | `pcb_r`(`struct regs`) 앞 0x40 |
| 0x040–0x047 | pcb 포인터로 접근하는 곳 없음. 다음 칸이 0x48 이고 저장 상태가 0x48 B(`_thread_user_state` 0x4096994 `pea 0x48`)이므로 `pcb_r` 를 0x48 B 로 봄(추론) | NeXTMach `struct regs` 는 0x4c(pad + 10 B `excp_frame`); SDK `m68k_thread_state_regs` 는 0x48(`pad0`·`sr`·`pc`) |
| 0x048 | 저장 사용자 상태 포인터(`_thread_user_state` 가 정함; `_trap`·`_check_for_ast`·`_move_space` 가 저장·교체·복원; `USER_REGS`) | `saved_regs`(NeXTMach 에서는 0x4c) |
| 0x04c | 지연 할당 저장 영역 포인터(`_kalloc` 312/580, `_pcb_terminate` 에서 해제, `USER_REGS` 의 0 시험) | 없음(Darwin i386 `save_area` 와 같은 생각) |
| 0x050 | 스레드별 사용자 레지스터(`trap5` 0x4001f0c 읽기, `trap6` 0x4001f1c 쓰기; `thread_setstatus`/`getstatus`) | `thread_user_reg`(NeXTMach 에서는 0x19e) |
| 0x054 | 플래그: 바이트 비트 연산만 보임 — 비트 6 FPU 상태 저장(locore), 비트 4 AST(스케줄러 `bset`/`bclr` 다수, `_trap` 0x4099e80), 비트 3(`_trap` 0x4099746 `bset #3` 으로 켬, `_unix_syscall_return` 0x409a2b0 `btst #3` 으로 시험). 같은 `_trap`·`_check_for_ast` 의 `movel …@(0x54:w)` 읽기(0x4099eee·0x409a446)는 pcb 가 아닌 포인터(`_check_for_ast` 에서는 thread 인 `a3`)의 칸이라 넣지 않음 | `u_char pcb_flags`; 스테이지는 `int pcb_flags` 와 `aston` 비트 0x10000000(= 바이트 0x54 의 비트 4) |
| 0x058 | MMU tt1 값(`pmove a0@(0x58),tt1`, `_cpu_type` 이면 `movec` 로 itt1/dtt1) | `mmu_tt1`(4 B) |
| 0x05c–0x133 | `fsave`/`frestore` 틀 216 B | `pcb_fpc_i`(`fpc_internal` 216 B) |
| 0x134–0x193 | fp0–fp7(8 × 12 B) | `pcb_fpc_e.regs` |
| 0x194–0x19f | fpcr/fpsr/fpiar(`thread_setstatus`/`getstatus` 의 0x194·0x198·0x19c) | `pcb_fpc_e` 의 cr·sr·iar. 그 뒤 `u_char state`(그리고 SDK 68882 의 `int state`)는 0x1a0 안에 들어가지 않음 |

- 정리: 1997 배치는 NeXTMach 의 칸들을 새로 늘어놓은 꼴입니다. `pcb_r` 가 4 B 짧아졌고, `saved_regs` 뒤에 저장 영역 포인터가 새로 생겼으며, `thread_user_reg`·`pcb_flags` 가 앞으로 왔고, FPU 외부 상태에서 `state` 가 빠졌습니다. 오프셋은 원본이 정하지만, 칸 이름과 C 형(특히 0x54 의 바이트/int, 0x134 이후의 구조체 형)은 바이트로 정해지지 않습니다.
- 영향 범위(§620.1): 스테이지 `struct pcb` 정의 STABS 를 가진 객체는 M5 92·받아들인 M4 17 이고, 칸을 실제로 쓰는 것은 M5 `init_main`(`USER_REGS`)과 `m68k/ast.h` 매크로를 쓰는 객체들입니다. 머리를 넓히면 이들의 STABS 가 바뀌므로, 받아들임 기준(비 STABS 섹션)과 회귀 절차를 다음 계획에서 정해야 합니다.
- 풀지 못한 것: 0x40–0x47 의 내용, 0x54 의 C 형, FPU 영역의 구조체 형, `thread->u_address`(§619.2, pcb 와 따로).

판정(미리 정한 대로): 07·공유 머리·도구는 바꾸지 않았습니다. 공유 머리를 넓히는 꼴은 사용자에게 묻습니다.

- 사용자 결정(2026-10-30, AskUserQuestion): 공유 머리의 `struct pcb` 는 "NeXTMach 이름 재배치" 꼴로 넓힙니다(NeXTMach `next/pcb.h` 의 칸 이름·형을 1997 오프셋 차례로 두고, 새 칸 +0x4c 는 표시한 작성 이름; 바이트로 갈리는 형은 회귀로 정함).

## 621. M4-127 세부 계획 — 공유 m68k `struct pcb` 를 1997 배치로 넓힘(공유 머리 변경; 코딩 전, 2026-10-30)

목적: 사용자 결정 "NeXTMach 이름 재배치" 에 따라 `07_kernel/v183.34/m68k/src/machdep/m68k/thread.h` 의 `struct pcb` 를 §620.2 의 1997 배치(416 B)로 넓힙니다. 이미 받아들인 객체의 바이트(비 STABS)는 바뀌지 않아야 합니다.

확인한 사실(이번 세션):
- 스테이지 SDK `bsd/m68k/reg.h:168–192` 의 `struct regs` 는 `r_dreg[8]`·`r_areg[8]` 뒤에 `struct excp_frame r_evec`(`e_sr` 2·`e_pc` 4·비트 칸 2 = 8 B)이고, `MONITOR` 는 정의되지 않습니다(grep). 따라서 0x40 + 8 = 0x48 B 로 원본 `pcb_r` 크기와 같습니다(python). 같은 머리 195–200 행에 `R0`·`R1`·`SP`·`PS`·`PCH`·`PCL` 매크로가 있습니다.
- MMU tt 구조체는 스테이지 `bsd/m68k/mmu.h:58·73`(07 `nextmach/next/mmu.h` 사본)에 있습니다. NeXTMach `fpc_internal`·`fpc_external` 은 스테이지에 없습니다. SDK `mach/m68k/thread_status.h` 의 `m68k_thread_state_68882` 는 `int state` 를 포함해 112 B 라 0x134 에서 0x1a0 까지(108 B)에 들어가지 않습니다(python).
- 지금 머리를 쓰는 07 줄: `thread.h` 의 `USER_REGS`(`pcb_regs`·`pcb_regs_valid`), `machdep/m68k/ast.h:14–15`(`pcb_flags |= / &= ~0x10000000`), `init_main.c:454`(`USER_REGS`). 스테이지 정의 STABS 를 가진 객체는 M5 92·받아들인 M4 17 입니다(§620.1).
- `m3_m68k_diag.canon` 은 섹션 내용과 재배치만 비교하므로(`m3_m68k_diag.py:34–43`) STABS 가 바뀌어도 같고, `l2_prefix_diff.obj_sig` 는 STABS 수를 비교합니다(`:48–53`). 상태 도구는 저장된 객체를 다시 검사하므로(새로 컴파일하지 않음) 기존 받아들임 기록에는 영향이 없습니다.

방법:
1. 새 `struct pcb`(진단 먼저, 07 은 회귀 뒤):
   - +0x00 `struct regs pcb_r`(SDK `<m68k/reg.h>`), +0x48 `saved_regs`(NeXTMach 이름; 형은 `struct regs *` 와 NeXTMach 꼴 `struct NeXT_saved_state *` 가운데 바이트로 갈리지 않으면 사용자에게 물음), +0x4c 새 칸(작성 이름, 표시), +0x50 `int thread_user_reg`, +0x54 `pcb_flags`, +0x58 `union { struct mmu_030_tt tt1_030; struct mmu_040_tt tt1_040; } mmu_tt1`(`<m68k/mmu.h>`), +0x5c `pcb_fpc_i`(NeXTMach `fpc_internal` 꼴 216 B), +0x134 `pcb_fpc_e`(NeXTMach `fpc_external` 의 `regs[8]`·`cr`·`sr`·`iar`, 108 B; `state` 없음 — 작성 표시). 각 칸 오프셋은 python 이 아니라 컴파일 결과(STABS 의 칸 오프셋)로 확인합니다.
   - `pcb_flags` 의 형은 두 꼴을 잽니다: (a) 지금처럼 `int`(`aston` 비트 0x10000000), (b) NeXTMach 처럼 `u_char`(+0x54, 비트 0x10)와 채움. `ast.h` 를 그에 맞춥니다.
   - `USER_REGS` 는 새 이름(+0x4c 시험, +0x48 반환)으로 바꿉니다.
2. 진단 회귀(07 바꾸기 전): 스테이지 `stage_m68k.py --plan 618` 의 사본에 새 머리 후보를 덮은 진단 스테이지를 만들어 M5 205 줄을 컴파일하고, 지금 스테이지의 객체와 `canon`(비 STABS)으로 비교합니다. 받아들인 M4 40 객체의 최종 명세도 같은 진단 스테이지에서 다시 컴파일해 저장된 객체와 `canon` 이 같은지 봅니다. 컴파일 오류(특히 `reg.h` 의 `SP`·`PS` 등 매크로 충돌)와 stderr 차이를 적습니다.
3. 판정(미리 정함): M5 205·M4 40 이 모두 `canon` 같고 새 오류·경고가 없으면, 그 꼴로 07 머리를 고치는 구현 계획(새 D 번호)을 씁니다. 다르면 다른 객체가 무엇인지 적고 꼴을 다시 고르거나 사용자에게 묻습니다. STABS 차이는 받아들임 기준(L1 은 비 STABS 섹션, 원본에 STABS 없음)에 들지 않으므로 허용하되, 수를 기록합니다.

관문: 진단 run 들의 명령 종료 0, `canon` 비교 결과 기록, x86 입력 불변(이 머리는 m68k 덮어쓰기만).

### 621.1 교차검토(codex `gpt-6.1-sol`, task kl760h4q9) 판정과 계획 수정

먼저 제 잘못입니다: 1 단계에서 `pcb_flags` 의 `u_char` 꼴을 새로 재겠다고 적었으나, 이 비교는 plan 432 에서 이미 음성 대조로 했습니다(`m3_m68k_ast.py` 의 `headers('uchar')`, 기록 `m3-m68k-ast-20261009.json` 의 `negative_control_ast_spans_equal` 이 AST 함수 7 곳에서 false). 계획을 쓰기 전에 보관 계획을 찾아보지 않았습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| SDK `struct regs` 0x48, tt 구조체 4 B, `fpc_internal` 216 B, SDK 68882 상태 112 B, 남은 FPU 칸 108 B | §621 사실 줄의 python 계산과 `reg.h:168–192` 를 이번 세션에 엶 | ✅ |
| `u_char` 꼴은 원본과 다른 코드: `U432__…ipc_sched.o` 의 0x372·0x3b2 는 `00 28 00 10 00 54`(`ori.b`)·`02 28 00 ef 00 54`(`andi.b`), 지금 객체는 `08 e8 00 04 00 54`(`bset`)·`08 a8 00 04 00 54`(`bclr`)이고 원본 0x404946e 는 `bset #4` | 두 객체의 그 바이트를 python 으로 읽음; 목록 93146 행을 엶; `m3_m68k_ast.py:31–37` 과 기록 45–60 행을 엶 | ✅ (b) 를 뺌. `int` 를 둡니다(원본 C 형이 `int` 였다는 증명은 아님) |
| `bsd/sys/user.h:43` 의 import 는 `#else NeXT` 안이라 쓰이지 않음 | 스테이지 `user.h:38–46` 을 엶 | ✅ 경로는 `kern/thread.h:82` 하나 |
| `SP`·`PS`·`PCH`·`PCL`·`R0`·`R1` 을 쓰는 곳은 `kern_exec.c`·`mach_process.c`(이미 `machine/reg.h`), `kern_xxx.c`(`COMPAT` 안), `machdep.c`(이미 `m68k/reg.h`) | 스테이지 전체(i386·ppc 빼고) 주석 뺀 토큰 검색(python, 이번 세션): 같은 파일들만 나옴. `kern_exec`·`mach_process` 는 M5 명령 파일에 없음(grep 0) | ✅ |
| 헤더 치환 옵션은 없음; 진단은 `stage_m68k` 를 불러 `OVL` 끝에 scratch 덮어쓰기 뿌리를 더한 감싸개로 만들 수 있음 | `stage_m68k.py:47`(`OVL`), `:518`(`cmd_stage`), `:560–575`(덮어쓰기 차례대로 적용·기록)을 엶; 탐침 `inc` 는 기존 `-I` 뒤(`:223`) | ✅ 방법으로 씀 |
| 받아들인 기록 35 개에 객체 40 개 | `m4_m68k_status.ACCEPTED` 를 불러 셈(python) | ✅ |
| `pcb_synch`(kern_core·kern_sig), `pcb_common_init/terminate`(task) 매크로를 지킬 것 | grep: `07_kernel/src/bsd/kern/kern_core.c`·`kern_sig.c`, `07_kernel/src/kern/task.c` | ✅ |
| `canon` 은 STABS 와 비디버그 기호·섹션 정렬·헤더도 보지 않음 → `canon` + 비 STABS 메타데이터 같음을 진단 판정으로; 역사적 받아들임 기준은 약하게 하지 않음 | `m3_m68k_diag.py:34–43`, `l2_prefix_diff.py:48–53` 을 이번 세션에 엶 | ✅ |
| 상태 도구는 다시 컴파일하지 않음 | `m4_m68k_status.py` main(이번 세션에 엶) | ✅ |
| SDK `regs` 의 `r_sr`·`r_pc` 는 0x40·0x42, 내보내는 thread state 의 `sr`·`pc` 는 0x42·0x44 — 크기가 같아도 배치는 다를 수 있음 | `reg.h` 의 `excp_frame`(`e_sr` 2·`e_pc` 4)과 `thread_status.h:41–47`(`pad0`·`sr`·`pc`)을 엶; 원본 `_thread_dup` 0x4096d3a `andw #0x3ffe,a2@(0x40:w)`(저장 상태의 sr)·`_thread_entrypoint` 0x4096dc2 `a1@(0x44:w)`(thread state 의 pc)와도 맞음 | ✅ 0x40–0x47 은 계속 미확정으로 둠 |
| x86 스테이징에는 `v183.34` 출처가 없음 | §618 x86gate 의 `v183_paths` 0(이번 세션) | ✅ x86 관문은 그대로 둠 |
| `-E` 출력도 비교할 것 | — | ⚖️ 매크로 치환이 코드를 바꾸면 비 STABS 바이트 비교가 잡고, 바꾸지 않으면 결과에 영향이 없으므로 받아들임에는 바이트 비교로 충분합니다. 다만 새 머리가 끌어오는 의존 파일 목록은 기록합니다 |

계획 수정(§621 방법을 바꿈):
1. 후보 머리는 하나입니다: §620.2 배치에 NeXTMach 이름을 둔 `struct pcb`(`pcb_flags` 는 `int`, `ast.h` 는 그대로), `USER_REGS` 는 새 칸 이름으로, `pcb_synch`·`pcb_common_*` 와 `thread_user_state` 선언은 그대로 둡니다. `saved_regs` 의 형은 진단에서 `struct regs *` 로 두고, 07 전에 사용자에게 묻습니다.
2. 진단 스테이지: scratch 감싸개(`stage_m68k` 를 불러 `PLAN = 618`, `OVL` 끝에 scratch 뿌리)를 두고, 새 스테이지 `08_build/runs/tools/m3p621-d1-stage` 를 만듭니다. 매니페스트가 `m0p618-a1-stage` 와 `src/machdep/m68k/thread.h` 한 줄(출처·해시)만 다른지 python 으로 단언합니다. 07·도구 파일은 바꾸지 않습니다.
3. M5: `stage_m68k.py --plan 618 cmd` 로 만든 명령 파일을 진단 스테이지에서 돌리고(run `m3p621-d1`), 기준은 §618 의 `m3p618-cc1` 객체입니다.
4. M4: `ACCEPTED` 의 35 기록에서 객체 40 개의 최종 변형을 모은 합친 명세 두 개(바탕 `m0p618-a1-stage` 와 진단 스테이지)를 만들어 run `m4p621-b1`(기준 재현)·`m4p621-d1` 을 돌립니다. 기준 재현이 저장된 객체와 `canon`·`obj_sig` 모두 같아야 진단 결과를 해석합니다.
5. 진단 판정 술어(이 계획 전용): 객체마다 `canon` 같음 + `obj_sig` 의 `header`·`sections`·`symbols` 같음(STABS 수만 다를 수 있음). STABS 수 차이와 stderr 차이를 따로 적습니다. 새 객체의 STABS 에서 `pcb` 칸 오프셋(컴파일러가 낸 값)을 읽어 §620.2 표와 대조합니다.
6. 판정(미리 정함): 205 + 40 객체가 모두 술어를 채우고, 명령이 모두 종료 0 이며 stderr 가 기준과 같으면 07 구현 계획을 씁니다. 하나라도 어긋나면 그 객체와 차이를 적고 사용자에게 묻습니다.

### 621.2 결과(2026-10-30)

- 후보 머리 D1(scratch `08_build/artifacts/m4p621/ovl/src/machdep/m68k/thread.h`, 생성 scratchpad `gen_p621.py`, SHA `ced9a599…`): `#import <sys/types.h>`·`<m68k/reg.h>`·`<m68k/mmu.h>`, NeXTMach `next/fpc.h:34–42` 의 `struct fpc_internal` 과 `:21–27` 의 `struct fpc_external`(`u_char state` 뺌), `struct pcb { struct regs pcb_r; struct regs *saved_regs; void *pcb_save_area; int thread_user_reg; int pcb_flags; union { mmu_030_tt; mmu_040_tt } mmu_tt1; struct fpc_internal pcb_fpc_i; struct fpc_external pcb_fpc_e; }`, `USER_REGS` 는 새 이름으로. 생성 중 제 줄 번호 실수(fpc.h 의 `fpc_external` 범위) 두 번을 생성기 단언이 잡았고, 내용으로 줄을 찾게 고쳤습니다.
- 진단 스테이지 `08_build/runs/tools/m3p621-d1-stage`(감싸개 scratchpad `stage_p621.py`: `stage_m68k` 를 불러 `PLAN = 618`, `OVL` 끝에 scratch 뿌리). 매니페스트는 `m0p618-a1-stage` 와 키 `files`·`overlays`·`replaced` 만 다르고, 파일은 `src/machdep/m68k/thread.h` 한 줄(출처 scratch)만 다릅니다(python 단언). 07·도구 파일은 바꾸지 않았습니다.
- 컴파일러가 낸 배치(새 객체 `ipc_sched` 의 STABS `pcb:T…=s416`): `pcb_r` 0x0·72, `saved_regs` 0x48, `pcb_save_area` 0x4c, `thread_user_reg` 0x50, `pcb_flags` 0x54, `mmu_tt1` 0x58, `pcb_fpc_i` 0x5c·216, `pcb_fpc_e` 0x134·108, 합 416 — §620.2 표와 모두 같습니다(python 단언).
- M5(run `m3p621-d1`, 명령 `08_build/artifacts/m4p618/m5-618.cmd`, 기준 `m3p618-cc1`): 205 객체 모두 `canon` 같음 + `obj_sig` 의 `header`·`sections`·`symbols` 같음, 바이트까지 같은 것 113, STABS 수가 바뀐 것 92(pcb 정의를 가진 92 와 같은 수), stderr 205 파일 모두 같음.
- M4(받아들인 35 기록의 40 객체를 합친 명세, `refs` = 저장된 받아들인 객체):
  - 기준 재현 run `m4p621-b1`(바탕 `m0p618-a1-stage`, 기록 `m4-m68k-p621-b1-20261030.json`): `gate.ok` — 40 객체 모두 저장된 객체와 `canon`·`obj_sig`(STABS 수 포함)가 같습니다.
  - 진단 run `m4p621-d1`(바탕 진단 스테이지, 기록 `m4-m68k-p621-d1-20261030.json`): 명령 80 개 종료 0, 경고는 알려진 목록과 같고, stderr 80 파일이 b1 과 같습니다. 40 객체 모두 `canon`·비 STABS 메타데이터가 같고, STABS 수가 바뀐 것은 예상한 17 객체(`vm_unix`·`autoconf`·`machine_clock`·`dma`·`np`·`snd_*` 여섯·`fd_*` 넷·`machdep`·`APM`)뿐입니다. 탐침 `gate.refs_equal` 이 거짓인 까닭은 이 STABS 수 차이입니다(역사적 받아들임 기준은 약하게 하지 않았고, 이 계획의 진단 술어로만 판정함).
  - 새로 의존하게 된 머리는 `bsd/m68k/reg.h`·`bsd/m68k/mmu.h` 둘이고(17 객체의 의존 목록), 빠진 의존은 없습니다.

판정(미리 정한 대로): 205 + 40 객체가 모두 진단 술어를 채우고, 명령이 모두 종료 0 이며 stderr 가 기준과 같습니다. 07 머리 구현 계획(§622)으로 갑니다. 그 전에 바이트로 갈리지 않는 이름·형을 사용자에게 묻습니다.

- 사용자 결정(2026-10-31, AskUserQuestion): ① `saved_regs` 는 "`struct regs *`" ② +0x4c 이름은 "`pcb_save_area`" ③ FPU 외부 상태 형은 "`fpc_external` 이름 유지"(`state` 줄을 빼고 표시). 모두 진단 D1 꼴입니다.

## 622. M4-128 D142 구현 계획 — 07 공유 머리 `v183.34/m68k/src/machdep/m68k/thread.h` 의 `struct pcb` 를 1997 배치로(코딩 전, 2026-10-31)

확인한 사실(이번 세션): §621.2 의 진단 결과와 위 결정입니다. 지금 07 파일은 57 행(SHA `e472f042…`)이고 PROVENANCE 1062 행(일곱 칸, `authored+nextmach+darwin01`)·MODIFICATIONS 586 행이 이 파일을 적습니다. 근거 문서는 `06_reconstruction/evidence/m68k-overlay.md` 입니다.

1. 07 파일을 scratchpad `gen_p622.py` 로 고칩니다(먼저 읽고 바꿈; 사본은 scratchpad).
   - 내용은 D1 과 토큰이 같아야 합니다(주석 뺀 토큰 비교, python). 바뀌는 것은 주석뿐입니다: 머리 설명을 plan 430–433·620–622 의 근거(§620.2 배치와 원본 근거 주소, D142 결정)로 고치고, "plan 621 diagnostic D1" 표시를 `plan 622 (D142)` 로 바꾸며, 새 줄마다 출처 표시를 답니다(`fpc_internal`: NeXTMach `next/fpc.h:34–42`; `fpc_external`: `:21–27` 에서 `state` 뺌; 칸 이름: NeXTMach `next/pcb.h`; `pcb_save_area`: 작성). NeXTMach `next/fpc.h` 고지(그 파일의 저작권 줄)를 옮긴 줄 앞에 둡니다.
   - 표시 줄은 `*/` 뒤에 글이 없어야 합니다(python).
2. `stage_m68k.py`: `M4FILES[622] = list(M4FILES[618])`, `EXCEPTS[622] = dict(EXCEPTS[618])`, 머리말 plan 목록에 622 를 더합니다(07 덮어쓰기 파일이 바뀌었으므로 새 스테이지 번호로 기록).
3. 회귀(§621 과 같은 진단 술어: `canon` 같음 + `obj_sig` 의 `header`·`sections`·`symbols` 같음; STABS 수 차이는 따로 적음):
   - 새 스테이지 `m0p622-a1-stage` 와 진단 스테이지 `m3p621-d1-stage` 의 매니페스트 차이는 키 `plan`·`overlays`·`replaced` 와 `files` 의 `src/machdep/m68k/thread.h` 한 줄(출처·해시)뿐이고, 그 머리 말고 스테이지 파일 내용은 같아야 합니다. 보관 `m0p618-a1-stage` 와의 차이는 키 `plan` 과 그 머리 한 줄뿐이어야 합니다. `--plan 618` 재생성(`m0p618-r622-stage`)은 보관본과 그 머리 한 줄만 달라야 합니다(§622.1).
   - M5: `--plan 622 cmd` 명령 파일과 §618 의 `m5-618.cmd` 의 차이가 계획 번호뿐인지 보고, run `m3p622-cc1` 의 205 객체를 `m3p618-cc1` 과 술어로 비교합니다(stderr 같음). `stage_m68k.py --plan 622 compare` 의 `differ_unexpected`·`lost` 가 비어야 합니다(python 단언).
   - M4: §621 의 합친 명세를 바탕 `m0p622-a1-stage` 로 바꾼 run `m4p622-r1` 의 40 객체가 저장된 객체와 술어를 채우고, 명령·경고·stderr 가 `m4p621-b1` 과 같아야 합니다.
   - x86: `m4_x86_inputs.py s6ln`(forms `l2_build_forms-s6p398.tsv`, expect `l2_expect-s6p398.json`) `ok`, `--plan 622 x86gate` 일곱 같음·`v183.34` 경로 0.
   - 상태 도구를 두 번 돌려 상태표가 §618 표와 같음(머리 줄 포함)을 확인합니다. 저장된 객체를 다시 검사하므로 바뀌지 않아야 합니다.
4. 기록: PROVENANCE 1062 행을 고침(일곱 칸; 출처에 `next/fpc.h:21–27·34–42`·`next/pcb.h` 칸 이름 더함, 바뀐 SHA, D142), MODIFICATIONS 새 행, DECISIONS D142, 근거 문서 `m68k-overlay.md` 에 plan 622 절, 계획 결과, HANDOFF·메모리.

판정(미리 정함): 3 이 모두 맞으면 받아들입니다. 하나라도 어긋나면 07 파일을 사본으로 되돌리고 사용자에게 알립니다.

관문: 명령 종료 0, 경고·stderr 기준과 같음, i386 머리 0, 회귀 단언 통과.

### 622.1 교차검토(codex `gpt-6.1-sol`, task k33rw0vby) 판정과 계획 수정

먼저 제 잘못입니다: 3 의 "새 스테이지와 진단 스테이지의 차이는 머리의 출처·해시뿐" 은 틀렸습니다. 진단 스테이지 매니페스트는 `plan` 618·덮어쓰기 뿌리 하나 더·`replaced` 한 줄 더를 가집니다(§621.2 에서 제가 직접 단언한 키 `files`·`overlays`·`replaced` 와 같은 사실). 또 "앞 계획 스테이지를 다시 만들면 보관본과 같다" 는 관례는 덮어쓰기 머리가 바뀐 이번에는 맞지 않습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §621.2 의 수치(M5 205/205·STABS 92·stderr 205, M4 40/40·STABS 17·stderr 80, `ipc_sched` STABS 의 칸 오프셋) | 제가 이번 세션에 같은 함수로 직접 잰 값(§621.2)과 같음 | ✅ |
| 진단 스테이지 대비 기대 차이는 `plan`·`overlays`·`replaced`·`files` 한 줄 | §621.2 의 매니페스트 단언 출력(`keys differ ['files','overlays','replaced']`; `plan` 은 두 쪽 모두 618 이라 그때는 같았고, 새 스테이지는 622) | ✅ 3 을 고침: 진단 스테이지 대비 `overlays`·`replaced`·`plan`·`files`(그 머리 한 줄), 보관 618 대비 `plan`·`files`(그 머리 한 줄) |
| 덮어쓰기는 모든 계획에 지금 뿌리를 쓰므로(`stage_m68k.py:565`) 618 을 다시 만들면 보관본과 그 머리 한 줄이 달라짐 | `stage_m68k.py:560–575` 를 이번 세션에 엶 | ✅ 3 에 "`--plan 618` 재생성 = 보관본 + 그 머리 한 줄 차이" 단언을 더함 |
| 받아들인 35 기록의 매니페스트 어디에도 이 머리는 `m4_headers` 에 없어 상태 도구가 다시 해시하지 않음(`m4_m68k_status.py:108`) | python 으로 35 매니페스트를 읽음: 0 건; `:104–110` 을 엶 | ✅ |
| `fpc.h` 의 고지는 1 행; 옮기는 줄 34–42·21–27·32, 뺀 줄 28–31; pcb 칸 이름은 `pcb.h:23–33` | python 으로 그 줄들을 읽음(`fpc.h:1` = `/*\t@(#)fpc.h\t1.0\t03/12/87\t(c) 1987 NeXT\t*/`, 28 = `u_char state`, 31 = `FPC_BUSY`, 32 = `};`; `pcb.h:23` = `pcb_r`, 33 = `pcb_flags`) | ✅ 1 에 반영 |
| 파일 머리의 "authored" 와 "otherwise the same as Darwin" 문구가 이제는 맞지 않음 | 지금 07 파일 1–16 행(이번 세션에 엶) | ✅ 1 에서 고침 |
| PROVENANCE 1062 행의 저장소·커밋·분류는 두고 원 경로·라이선스·바뀜 칸을 넓힐 것; MODIFICATIONS 에도 같은 출처 | 1062 행 일곱 칸을 이번 세션에 엶 | ✅ 4 에 반영 |

### 622.2 결과(2026-10-31)

- 1: 07 `v183.34/m68k/src/machdep/m68k/thread.h` 를 scratchpad `gen_p622.py` 로 D1 에서 만들었습니다(57 → 92 행, SHA `9c2b3e04…`; 바꾸기 전 사본 scratchpad `thread.h.before622`, SHA `e472f042…` 단언). 주석 뺀 토큰이 D1 과 같고, `plan 622` 표시 줄의 `*/` 뒤에 글이 없습니다(python). 머리 설명을 plan 620–622 의 근거로 고치고, `fpc.h:1` 고지 줄을 fpc 줄 앞에 두었습니다.
- 2: `stage_m68k.py` 725 → 727 행(`M4FILES[622]`·`EXCEPTS[622]`·머리말 목록).
- 3:
  - 스테이지: `m0p622-a1-stage` 와 진단 `m3p621-d1-stage` 의 매니페스트 차이는 키 `files`·`overlays`·`plan`·`replaced` 이고 파일은 그 머리 한 줄뿐, 스테이지 파일 내용 차이도 그 머리 하나입니다. 보관 `m0p618-a1-stage` 와는 키 `files`·`plan`(그 머리 한 줄), `--plan 618` 재생성 `m0p618-r622-stage` 와 보관본은 그 머리 한 줄만 다릅니다(python 단언).
  - x86: `m4-x86-inputs-p622-20261031.json` `ok`(`s6ln`), `--plan 622 x86gate` 일곱 같음·`v183.34` 경로 0.
  - M5: `m5-622.cmd` 와 `m5-618.cmd` 의 차이는 계획 번호뿐입니다. run `m3p622-cc1` 205 객체가 `m3p618-cc1` 과 진단 술어를 모두 채우고(바이트까지 같은 것 113), STABS 수가 바뀐 것은 92, stderr 205 같음입니다. `--plan 622 compare`(`m3-m68k-p622-compare-20261031.json`)의 `differ_unexpected`·`lost` 는 비었고 요약은 §618 기록과 같습니다.
  - M4: run `m4p622-r1`(합친 명세 `08_build/artifacts/m4p622/r1/spec.json`, 기록 `m4-m68k-p622-r1-20261031.json`): 명령 80 종료 0, 경고는 알려진 목록과 같음, i386 0, 40 객체 모두 저장된 받아들인 객체와 술어를 채움, STABS 수가 바뀐 것은 17, stderr 80 이 `m4p621-b1` 과 같음입니다. 탐침 종료 1 은 `refs_equal`(STABS 수 포함)이 거짓이기 때문이고 §621 의 d1 과 같은 까닭입니다.
  - 상태 도구 두 번: 둘 다 `06_reconstruction/m68k-m4-status.tsv` 와 `cmp` 같음.
- 4: 근거 문서 `m68k-overlay.md` 24 → 39 행(표 줄 고침, plan 622 절), PROVENANCE 1062 행을 고침(행 수 1189 그대로, 일곱 칸), MODIFICATIONS 724 → 725 행, DECISIONS D142(145 → 146 행).

판정(미리 정한 대로): 3 이 모두 맞아 받아들였습니다(D142). 이제 `trap.c`(§619) 와 `pcb.c`(행 308–309)는 1997 `struct pcb` 칸 이름으로 진단할 수 있습니다. `trap.c` 에는 `thread->u_address`(§619.2)라는 따로인 전제가 남아 있습니다.
