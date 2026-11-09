# 커널 소스 복원 작업계획 — 보관 §643–655

`02_plan/RECONSTRUCTION_PLAN.md` 의 §643–655(m68k M4 `snd_stream.c`(D147)·`snd_unix.c`(D148), `st.c` 첫 진단과 1997 `struct scsi_ctrl` 조사·공유 `scsivar.h`(D149), `st.c`(D150), `sg.c`(D151))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-01, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 643. M4-149 세부 계획 — m68k `snd_stream.c`(행 252 일부) NeXTMach 글 진단 A(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: 다음 후보 가운데 참고 글이 바로 있고 경계가 기호로 정해지는 단위입니다. `nextdbg`(행 304–306)는 1997 이름 대부분(`m68k_dbginit`·`dbg_dispatch`·`dbg_process`·`gdb_from_trap`·`SENDEXC` 등)이 참고 트리에 없어(`grep -rIl` 0 건) 큰 바이트 작성이 필요하고, `tty_pty` 꼬리(행 036)는 M5 에서 받아들인 `x86-tty_pty` 객체 [0x4010140, 0x40110a0) 와 x86 공유 07 파일을 다시 열어야 해(1997 pty 표를 쓰는 NeXTMach `pts_process_putc`·`ptsputc` 꼴) 계정 처리 결정이 먼저 필요합니다. 이벤트 드라이버(행 213–218)는 1997 이름 일부(`evsetup_screens`·`AnimateWaitCursor`·`evdispatch`·`evretry`)가 참고 글에 없습니다(`_evinit`·`_evioctl`·`_process_kbd_event`·`_process_mouse_event` 는 NeXTMach `nextdev/ev*.c` 에 있음; §643.1).

확인한 사실(이번 세션; 원본 풀이 scratchpad `sndstream.dis`(로컬 `m68k-linux-gnu-objdump`), 기호표, 수는 python):
- 범위 [0x4087272, 0x408833a) 4296 B, 이어진 16 항목(`m68k-functions.tsv`, 합 4296): 이름 있는 아홉 `_snd_stream_init` 22·`_reset` 8·`_queue_init` 102·`_queue_reset` 70·`_enqueue_region` 402·`_abort` 142·`_pause` 150·`_resume` 170·`_await` 130 과 이름 없는 일곱 0x408771e 1156·0x4087ba2 502·0x4087d98 390·0x4087f1e 192·0x4087fde 154·0x4088078 226·0x408815a 480. NeXTMach mk-108.1 `nextdev/snd_stream.c`(1223 행, SHA-256 `de898305…`)의 정의 차례(111·122·126·143·160·233·271·314·364, 그 뒤 정적 423 `snd_stream_thread`·752 `snd_desc_completion`·882 `snd_stream_start`·967 `snd_deactivate_pages`·1023 `snd_wire_page`·1052 `snd_reg_complete`·1116 `snd_split_region`)와 같은 수·차례라, 이름 없는 일곱을 이 정적 일곱으로 봅니다(차례에서 나온 가설; 진단의 funcbytes 가 확인). NeXTMach 의 `snd_stream_thread1`·`snd_stream_thread2` 는 `#if DEBUG`(425–438) 안이라 비 DEBUG 에서는 없고, 1997 기호에도 없습니다.
- 경계: 앞은 `snd_server`(`_snd_server_loop` 0x40859d6, `_snd_get_owner` 0x4085cc0 와 이름 없는 정적들이 0x4087272 까지), 뒤는 `_snd_unix_ioctl`(0x408833a, NeXTMach `snd_unix.c` 의 함수). 사운드 파일의 링크 차례(`snd_reply`·`snd_server`·`snd_stream`·`snd_unix`·`st`)와 맞습니다.
- 행: 명시 구간 `{"range": ["0x4087272", "0x408833a"], "rows": [], "partial": ["m68k-252", "m68k-253"], "basis": …}` 를 `m4_m68k_probe.span` 이 받아들입니다(python; `partial` 이 252 하나면 `('rows', ['m68k-253'])`, 251 을 더하면 `('rows', ['m68k-251'])` 로 멈춤). 부분 행이라 받아들여도 덮은 행·백분율은 그대로입니다.
- 자료: 이 구간이 글자 그대로 가리키는 자기 `__data`·`__bss` 주소는 없습니다(python 전수; 계산 주소는 배제 못 함). `__cstring` 은 0x40abe14 `"snd_wire_page: addr not in map!"`(32 B, NUL 포함) 하나이고, 앞 문자열은 `snd_server` 의 `"sound: wierd notification …"`, 뒤는 `"st"` 입니다. `__common` 참조: `_snd_var` +36(5 곳 — objdump 가 십진수로 찍은 즉시값 두 곳 포함, §643.1)·+40(4)·+48(1)·+52(10), `_active_threads`(2), `_page_mask`(12); `__data` `_page_size`(10).
- 부르는 것(원본, 바로 호출): `curipl` 1·`panic` 1·`kalloc` 2·`kfree` 3·`lock_init` 1·`lock_write` 5·`lock_done` 5·`assert_wait` 2·`thread_wakeup_prim` 6·`thread_block` 2·`thread_terminate` 1·`thread_halt_self` 1·`kernel_thread` 1·`vm_fault` 2·`vm_map_lookup_entry` 1·`vm_page_deactivate` 1·`vm_allocate` 1·`vm_deallocate` 4·`vm_copy` 1·`snd_link_pause`·`snd_link_resume`·`snd_reply_recorded_data`·`_overflow`·`_started`·`_completed`·`_aborted`·`_paused`·`_resumed` 각 1·`snd_stream_abort` 1·`bcopy` 1·`callout_dispatch` 1·`pmap_extract` 1·`pmap_resident_extract` 2, 그리고 이름 없는 정적 다섯(0x4087d98 2·0x4087f1e 3·0x4087fde·0x4088078·0x408815a 각 1). libDriver 고리(`___NXAudio*`)는 부르지 않습니다(`snd_link` 를 미룬 까닭과 다름).
- 원본 바이트로 확인한 1997 바뀜(§643.1): ① NeXTMach 871 `softint_sched(CALLOUT_PRI_SOFTINT1, thread_wakeup, (int)q)` → `callout_dispatch`(0x4087d78; §556·§563·§566 과 같은 꼴); ② `snd_deactivate_pages` 의 셋째 인자 2 는 "`clean` 을 건드리지 않음"(0x4087f62–0x4087f78: `dirty != 2` 일 때만 `m->clean = !dirty`; NeXTMach 992 는 늘 대입), 부르는 쪽은 `snd_stream_thread` 첫 곳이 기록이면 1 아니면 2(0x40877f6–0x4087804; NeXTMach 494–496 은 `== SND_DIR_RECORD`), 둘째 곳이 기록이면 0 아니면 2(0x40878d8–0x40878e6; NeXTMach 551–553 은 `FALSE`), `snd_reg_complete` 가 기록이면 0 아니면 2(0x40880a0–0x40880aa; NeXTMach 1063–1064 는 `== SND_DIR_RECORD`); ③ `vm_fault` 두 곳에 다섯째 인자 0(0x4087f7c·0x408803c; 07 `vm/vm_fault.c:78` 의 `int *error`, 다른 07 호출 `vm_fault.c:1206` 과 같은 꼴; NeXTMach 1002·1041 은 넷). `bcopy`(0x4088190, 길이 0x3e = 62)는 NeXTMach 1125 `*new_reg = *reg` 의 구조체 대입이 낳는 꼴로 보이며 바뀜이 아닙니다(진단이 확인).
- 머리: NeXTMach 은 `<sound.h>`(스테이지 생성 `generated/sound.h`, §551), `<sys/param.h>`, `<sys/callout.h>`, `<sys/buf.h>`, `<vm/vm_param.h>`, `<vm/vm_map.h>`, `<vm/vm_page.h>`, `<nextdev/busvar.h>`, `<nextdev/snd_var.h>`, `<nextdev/snd_snd.h>`, `<nextdev/snd_dsp.h>`, `<kern/xpr.h>`, `<kern/kalloc.h>`, `<machine/spl.h>` 를 들입니다. 스테이지(`m0p642-a1-stage`)에 `kern/kalloc.h`·`vm/vm_map.h`·`vm/vm_page.h` 가 있습니다.

방법(진단; 07 은 바꾸지 않음):
- 변형 A(scratchpad `p643/snd_stream_A.c` → `08_build/artifacts/m4p643/src/`): NeXTMach 글에서 include 두 줄만 바꿈 — `<vm/vm_param.h>` → `<mach/vm_param.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`(D104, `snd_dspqueue`·`snd_device` 와 같음). 본문은 그대로(`softint_sched` 그대로 — 미정의 `_softint_sched` 가 생기지만 원본 0x4093e66 에 있는 이름이라 `undefined_not_in_original` 로는 드러나지 않음; 호출 대상은 funcbytes 의 재배치 비교로 봄).
- 변형 B(scratchpad `p643/snd_stream_B.c`): A 에 위 ①–③ 을 넣은 꼴 — `callout_dispatch(CALLOUT_PRI_SOFTINT1, thread_wakeup, (int)q)` 와 `extern void callout_dispatch();`(D124 꼴), `if (dirty != 2) m->clean = !dirty;`, 부르는 세 곳의 셋째 인자 `… == SND_DIR_RECORD ? 1 : 2`·`? 0 : 2`·`? 0 : 2`, `vm_fault(…, TRUE, 0)` 두 곳. 바뀐 곳마다 `plan 643 diagnostic B` 주석.
- 명세 `08_build/artifacts/m4p643/spec.json`: 바탕 `08_build/runs/tools/m0p642-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `snd_stream`(위 명시 구간), `x86_rel` `machdep/i386/dkbad.c`, 변형 A·B. run `m4p643-p1`(REGISTRY 에 없음을 확인), 기록 `m4-m68k-probe-p643-p1-20261031.json`, funcbytes(변형마다) `m68k_funcbytes.py 0x4087272 0x408833a OBJ m4-m68k-funcbytes-p643-<변형>-20261031.json 0x408771e=_snd_stream_thread 0x4087ba2=_snd_desc_completion 0x4087d98=_snd_stream_start 0x4087f1e=_snd_deactivate_pages 0x4087fde=_snd_wire_page 0x4088078=_snd_reg_complete 0x408815a=_snd_split_region`(객체의 정적 기호 이름은 결과에서 확인; 이 대응은 도구가 찾는 것이 아니라 넣어 주는 것이며, 근거는 §643.1 의 바이트 대조).
- 측정: 종료 상태·경고(JSON 칸을 python 으로 읽음), 함수별 길이·바이트·재배치 대상(길이가 다른 함수는 funcbytes 가 건너뛰므로 디스어셈블 비교), 절 크기(원본 목표 `__text` 4296·`__cstring` 32, A 는 위 바뀜 때문에 다를 것), 지역 기호(정적 자료가 없는지), `__cstring` 내용, COMMON 이름·크기(`defined_symbols`), 원본에 없는 정의·미정의.

판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고, 다른 함수는 다음 계획에서 원본 바이트로 1997 꼴을 시험합니다. 모두 같으면 구현 계획을 세웁니다. 관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록합니다(`diag_gate.commands_ok` 는 경고가 하나라도 있으면 거짓이므로 종료 상태·경고·의존 결과를 따로 봅니다; 예상 경고 자리는 §643.1).

### 643.1 교차검토(codex `gpt-6.1-sol`, task kpysjyel7) 판정과 계획 수정

내가 틀린 것: ① "`_softint_sched` 는 원본에 없는 미정의로 나올 것" 은 틀렸습니다 — 원본 0x4093e66 에 있습니다(`symbols.tsv:2701`). ② `_snd_var+36` 은 3 곳이 아니라 5 곳입니다(objdump 가 `cmpal #67923628`·`movel #67923628` 처럼 십진수로 찍은 두 곳을 제 16 진 검색이 놓침). ③ 원본에서 이미 보이는 1997 바뀜 둘(`snd_deactivate_pages` 의 dirty 표지, `vm_fault` 다섯째 인자)을 놓쳤습니다. ④ 이벤트 드라이버 문장이 너무 넓었습니다. 모두 고쳤고, 확인된 바뀜을 넣은 변형 B 를 같은 run 에 더했습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_softint_sched` 는 원본 0x4093e66 에 있음 | `symbols.tsv:2701` 을 읽음(색인 2699, 값 0x4093e66, `_softint_sched`) | ✅ 채택(위 ①) |
| `_snd_var+36` 은 5 곳 | python 으로 원본 4296 B 에서 0x40c6eac 를 4 바이트로 찾음: 5; `hex(67923628)` = `0x40c6eac` | ✅ 채택(위 ②); 나머지 수(+40 4·+48 1·+52 10·`_active_threads` 2·`_page_mask` 12·`_page_size` 10·문자열 1)도 같은 방법으로 같음 |
| `snd_deactivate_pages` 는 셋째 인자 2 면 `clean` 을 건드리지 않고, 부르는 세 곳이 기록 ? 1 : 2, ? 0 : 2, ? 0 : 2 를 넘김 | `sndstream.dis` 0x4087f62–0x4087f78, 0x40877f6–0x4087804, 0x40878d8–0x40878e6, 0x40880a0–0x40880aa 를 읽음; NeXTMach 494–496·551–553·992·1063–1064 를 읽음 | ✅ 채택(위 ③, 변형 B) |
| `vm_fault` 두 곳이 다섯 인자(…, `VM_PROT_NONE`, `TRUE`, 0) | `sndstream.dis` 0x4087f7c–0x4087f8c·0x408803c–0x4088048 를 읽음; 07 `vm/vm_fault.c:78–83`(`int *error`), 다른 07 호출 `vm_fault.c:1206`; 스테이지 `vm/vm_fault.h:81` 은 인자 없는 선언이라 A 도 컴파일됨 | ✅ 채택(변형 B) |
| `_evinit`·`_evioctl`·`_process_kbd_event`·`_process_mouse_event` 는 NeXTMach 에 있음 | 원본 기호표에서 네 이름의 주소(0x40678ce·0x4068710·0x4068fa2·0x406a0d0), NeXTMach `nextdev/ev.c`·`ev_ioctl.c`·`ev_kbd.c` 등 `grep -lw`; `evsetup_screens`·`AnimateWaitCursor`·`evdispatch`·`evretry` 는 0 건 | ✅ 문장을 고침 |
| `bcopy` 는 1997 바뀜이 아니라 NeXTMach 1125 `*new_reg = *reg` 의 구조체 복사(62 B) | `sndstream.dis` 0x4088162–0x4088190(`kalloc(0x3e)` 뒤 `bcopy(reg, new, 0x3e)`) | ⚖️ 부분 채택 — 바뀜 목록에서 빼고, 같은 꼴이 나오는지는 진단이 판정 |
| `snd_link_pause/resume` 인자는 NeXTMach 와 같음, `snd_var_t` 오프셋은 이미 맞음(+36·+40 `new_thread_q`, +48 `task`, +52 `task_map`) | 스테이지 `nextdev/snd_var.h:115–130` 을 읽고 칸 크기로 셈 | ✅ (바꾸지 않음) |
| 일곱 정적 함수 대응은 차례뿐 아니라 바이트(호출 그래프, panic 문자열, `kernel_thread` 인자 등)로도 뒷받침됨 | `kernel_thread` 인자가 0x408771e 임과 panic 문자열이 0x4087fde 안에 있음을 `sndstream.dis` 에서 봄 | ✅ (계획의 "가설" 표현은 그대로 두고 근거를 더함) |
| A 는 컴파일될 것이나 경고 아홉 자리(457·731·1101·1173·152·717·225·741·874)가 있을 수 있음; `diag_gate` 는 경고가 있으면 거짓 | `m4_m68k_probe.py:381–382` 를 읽음; 경고 자리는 미확인 | ⏭️ 경고는 run 이 판정, 판정 문구만 고침 |
| 앞의 이름 없는 정적들을 모두 `snd_server` 로 본 것은 미확인 귀속 | 이번 단위 범위 밖 | ⏭️ 문장은 그대로("…로 봄"), 범위 결정에 쓰지 않음 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 python 입니다.

### 643.2 결과(run `m4p643-p1`, 2026-10-31)

- 명령 4 개 종료 0, 의존 목록 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p643-p1-20261031.json`). 컴파일 경고는 A·B 각 9 개로 §643.1 에서 짚은 자리와 종류 그대로입니다(`assert_wait`·`thread_wakeup_prim` 인자 정수→포인터 5, 지역 대입 1, `kfree` 인자 포인터→정수 3; NeXTMach 글 그대로의 경고라 `diag_gate.commands_ok` 는 거짓).
- A: `__text` 4258 B(원본 4296), NOT_MATCH, funcbytes 11/16(`m4-m68k-funcbytes-p643-A-20261031.json`): 공개 아홉과 `snd_stream_start`·`snd_split_region` 이 같고, 다섯이 다름 — `snd_stream_thread` 1134(원본 1156), `snd_deactivate_pages` 184(192), `snd_wire_page` 152(154), `snd_reg_complete` 220(226), `snd_desc_completion` 은 바이트 같고 재배치 대상 하나(`softint_sched` 대 `callout_dispatch`) 다름. 모두 §643 ①–③ 자리입니다.
- **B: OBJECT_MATCH**, `__text` 4296 B, `full_span`, `candidate`, funcbytes **16/16**(`m4-m68k-funcbytes-p643-B-20261031.json`). 절은 `__text` 4296·`__cstring` 32 뿐이고 `__cstring` 이 원본 0x40abe14 의 32 B 와 같음. 지역 기호는 정적 함수 일곱(`_snd_stream_thread`…`_snd_split_region`, §643 의 대응과 같은 이름이 같은 자리에서 바이트까지 같음)뿐이고 정적 자료는 없음. 미정의 38 개 모두 원본에 있음. COMMON 은 공유 머리에서 온 열하나(`_bfreelist` 272·`_bufhash` 192·`_buf`·`_buffers`·`_bufpages`·`_master_cpu`·`_nbuf`·`_nswbuf`·`_swbuf`·`_swbuf_cleanlist`·`_swbuf_freelist`)로 모두 원본에 있는 이름(D136).
- `bcopy`(0x4088190)는 NeXTMach 1125 `*new_reg = *reg` 그대로에서 나왔습니다(A·B 의 `snd_split_region` 이 같음).

판정(미리 정한 대로): B 의 꼴로 구현 계획을 세웁니다. 바이트로 가려지지 않는 꼴은 구현 전에 여쭙니다.

## 644. M4-150 D147 구현 계획 — 07 `src/machdep/m68k/snd_stream.c`(명시 구간 [0x4087272, 0x408833a), OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(D147 로 적음): `snd_deactivate_pages` 의 셋째 인자 값 2("`m->clean` 을 건드리지 않음")는 파일 안 매크로 `#define SND_DIRTY_KEEP 2`(이 프로젝트 이름, "파일 안 매크로 이름")로 쓰고 네 곳(정의 안 비교 하나, 부르는 세 곳)에서 씁니다. 앞선 결정을 그대로 따르는 것(묻지 않음): NeXTMach 글 + 표시한 1997 바뀜(D013·D024), include 줄 OPENSTEP 경로(D104), `callout_dispatch` 와 `extern void callout_dispatch();`(D124 꼴), NeXTMach 글 그대로의 경고는 `known_warnings` 로(§554·§566 선례), 공유 머리의 COMMON 은 원본에 이름이 있으면 통과(D136). 바이트가 정한 것: §643 ①–③(B, 16/16).

확인한 사실(이번 세션):
- 07 `src/machdep/m68k/` 에 `snd_stream.c` 는 없습니다. `stage_m68k.py` 는 원천·머리 표를 계획 번호 이하 최댓값으로 고르므로(550·569 행; `--plan` 은 `EXCEPTS` 에 있어야 함, 725 행) `M4FILES[644]` 한 줄과 `EXCEPTS[644]` 면 됩니다. 사운드 머리는 `M4HEADERS[551]`·`[554]`·`[556]` 부터 들어 있습니다.
- 생성 초안(scratchpad `gen_p644.py`, 결과 `p644/snd_stream.c` 1247 행, `p644/snd_stream_L.c`): NeXTMach 글(SHA `de898305…` 를 assert)에 머리 주석 덩이, include 두 줄, `callout_dispatch` 선언과 `SND_DIRTY_KEEP` 정의, 바뀐 곳 일곱(표시 `plan 644`)만 더하거나 바꿈. lexer(문자열·복합 연산자)로 F·L 토큰과 토큰 줄이 같고, F 에서 `# define SND_DIRTY_KEEP 2` 를 빼고 그 이름 네 곳을 2 로 읽으면 컴파일한 B(§643 기록의 `source_sha256` 에 묶음)의 토큰과 같음을 assert 합니다.
- 상태 기대(python): 객체 49 + 1 = 50(OBJECT_MATCH 41, CODE+BSS_INFERRED 9), 행 75/188 과 덮은 바이트 71204(32.98%)는 그대로(부분 행 252·253 은 `exact` 0 이라 세지 않음), `object_bytes` 88406 + 4296 = 92702, `partial_rows` 에 `m68k-252`·`m68k-253` 이 더해짐.

1. 도구: `stage_m68k.py` 에 `M4FILES[644] = list(M4FILES[642]) + ['snd_stream.c']`, `EXCEPTS[644] = dict(EXCEPTS[642])`, 머리말 계획 목록에 644.
2. 07 파일: `gen_p644.py --write`(이미 있으면 멈춤).
3. 회귀: `--plan 642` 재생성(`m0p642-r644-stage`)의 manifest 가 보관본과 바이트까지 같음; 새 스테이지 `m0p644-a1-stage` 는 이 파일과 키 `plan`·`m4_sources`·`files` 만 다름; `--plan 642 cmd` 가 `m4p642/m5-642.cmd` 와 같고 `m5-644.cmd` 는 계획 번호만 다름; M5 205(run `m3p644-b642`·`m3p644-cc1`) 객체·출력 같음, `compare`(`m3-m68k-p644-compare-20261031.json`·`-b642-`) `differ_unexpected`·`lost` 빔; x86 `m4-x86-inputs-p644-20261031.json` `ok`·`--plan 644 x86gate` 일곱 묶음 같음.
4. 확인 run `m4p644-p1`(바탕 `m0p644-a1-stage`, 객체 `snd_stream`, m4_id 는 §643 의 명시 구간, `x86_rel` `machdep/i386/dkbad.c`): F = `@machdep/m68k/snd_stream.c`, L = `08_build/artifacts/m4p644/src/snd_stream_L.c`. 판정: 종료 0·i386 0, 경고는 F·L 각 아홉(stderr 15 줄 = 경고 9 + 함수 문맥 6; §643.2 와 같은 종류·함수, 줄 번호는 F 의 것), F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 16/16(정적 일곱 이름 대응은 §643 과 같음), F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx` 와 문자열 표 크기뿐). `-E` run `m4p644-e2`(F·L 과 §643 의 B 를 같은 스테이지에 넣은 별도 명세, `-c` → `-E`): `#` 줄을 뺀 토큰이 F = L = B(매크로가 펼쳐져 차이 없어야 함), stderr 0, i386 0.
5. 최종 run `m4p644-a1`(명세 `08_build/artifacts/m4p644/spec.json`: F 만, `refs` = p1 의 L 객체와 SHA, `known_warnings["snd_stream"]` = 확인 run F 의 stderr 줄 그대로): `gate.ok`. 확인 기록 `m4-m68k-p644-checks-20261031.json`: 절은 `__text` 4296·`__cstring` 32 뿐이고 `__cstring` 이 원본 0x40abe14 32 B 와 같음, 재배치 대상(funcbytes 16/16), 바깥 정의 아홉이 원본 주소에, 지역 기호는 정적 함수 일곱뿐이고 각자 원본 자리, COMMON 은 모두 원본에 있는 이름, 미정의가 모두 원본에 있음, 컴파일 줄이 M5 줄과 같음, 의존 파일에 i386 머리 없음, 의존 파일마다 스테이지·run·manifest·07 원본의 SHA 사슬이 같음(§566 과 같은 방식).
6. 상태: 근거 `06_reconstruction/evidence/m68k-snd_stream.md` 와 NeXTMach 대비 diff `m68k-snd_stream.diff` 를 먼저 쓰고 `ACCEPTED` 에 한 줄. 상태 도구 두 번, 기대는 위 python 값.
7. 기록: PROVENANCE 한 행(일곱 칸, `nextmach+authored`; D013 대로 저장소 URL·커밋·경로:줄과 바꾼 함수·식별자), MODIFICATIONS, DECISIONS D147, 계획·HANDOFF·메모리. M7 의무: COMMON 합침(공유 머리의 `_bfreelist` 등, D136), 부르는 함수들(`snd_link_*`·`snd_reply_*`·`callout_dispatch` 등)은 다른 객체.

관문: 명령 종료 0, i386 0, 회귀 같음, 상태 도구가 멈추지 않음. 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 644.1 교차검토(codex `gpt-6.1-sol`, task k2bdtr769) 판정과 계획 수정

내가 틀린 것: `stage_m68k.py` 의 줄 번호 548·567 은 §642 에서 두 줄을 넣기 전 번호였습니다. 지금은 550(머리 표)·569(원천 표)입니다. 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 고르는 식은 550·569 행, `--plan` 은 725 행의 `EXCEPTS` 검사 | `grep -n` 출력(550·569·725) | ✅ 채택(위) |
| 경고는 "9 줄" 이 아니라 stderr 15 줄(경고 9 + 함수 문맥 6)이고 `known_warnings` 는 `err_lines` 전체를 글자 그대로 비교 | B 의 `02.err` 줄 수 15·`warning:` 9(python/`wc`), `m4_m68k_probe.py:384–388` 을 읽음 | ✅ 단계 4 문구를 고침; 단계 5 는 이미 F 확인 run 의 stderr 를 씀 |
| 머리 주석이 첫 호출의 기록 값(1)을 빠뜨림; "원본에 이름이 없음" 은 "원본 바이트는 2 를 담음" 으로 | `sndstream.dis` 0x40877f6–0x4087804(기록 1·재생 2)·0x40878d8–0x40878e6(0·2)·0x40880a0–0x40880aa(0·2)는 §643.1 에서 읽음 | ✅ 생성기 머리 주석을 고침(F 1247 행; assert 그대로 통과) |
| 확인·최종 명세는 명시 구간 사전(`partial` 252·253)을 써야 함; `-E` run 에 B 를 넣는 방법을 적을 것; `#` 줄은 빼고 비교 | §643 에서 `span()` 시험(252 하나면 멈춤) | ✅ 단계 4 를 고침 |
| 의존 파일의 SHA 사슬을 확인 기록에 남길 것(§566 방식) | §642 확인 기록이 같은 방식(`chain_key`)을 씀 | ✅ 단계 5 에 더함 |
| 생성기 assert 통과, F·L 토큰·줄 같음(4932), F·B 정규화 같음(4928), HEAD 주석 문법 문제 없음, 고지·HISTORY 그대로, B 기록·해시·16/16·정적 대응·머리 등록·M5 명령 재생성·상태 셈은 맞음 | 생성기 실행 출력(assert 통과), 앞 단계 python | ✅ (토큰 수는 따로 세지 않음 — 행동 바뀌지 않음) |
| F 와 B 의 객체 전체 같음을 요구하지 말 것(원천 경로·줄 정보가 다름) | 판정은 원본 대비와 F = L 로 함 | ✅ 이미 그렇게 짬 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 명령입니다.

### 644.2 결과(2026-10-31)

- 1 도구: `stage_m68k.py` 741 → 743 행(`M4FILES[644]`·`EXCEPTS[644]`, 머리말 목록에 644), `m4_m68k_status.py` 200 → 201 행(`ACCEPTED` 한 줄).
- 2 07: `src/machdep/m68k/snd_stream.c` 1247 행, SHA `e24c02a7…`(scratchpad `gen_p644.py --write`; NeXTMach SHA·F = L·F 와 B 의 정규화 토큰을 assert).
- 3 회귀: `--plan 642` 재생성(`m0p642-r644-stage`)의 manifest 가 보관본과 바이트까지 같고 트리 어긋남 0; `m0p644-a1-stage`(985 파일, 트리 어긋남 0)는 새 파일 하나와 키 `plan`·`m4_sources`·`files` 만 다름. `--plan 642 cmd` 가 `m4p642/m5-642.cmd` 와 같고 `m5-644.cmd` 는 411 줄 모두 642→644 만 다름. M5 205(run `m3p644-b642`·`m3p644-cc1`): 객체 205 같음, 나머지 출력도 같고 `run.json` 만 다름; `compare`(`m3-m68k-p644-compare-20261031.json`·`-b642-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 새 파일 하나. x86: `m4-x86-inputs-p644-20261031.json` `ok`, `--plan 644 x86gate` 일곱 묶음 같음·`v183.34` 경로 0.
- 4 확인 run `m4p644-p1`(`m4-m68k-probe-p644-p1-20261031.json`): 명령 4 개 종료 0·i386 0, F·L 경고 각 9(stderr 15 줄), F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 16/16(`-F/L-`), F = L(canon·`obj_sig`); 문자열 표 앞 차이는 `n_strx` 와 문자열 표 크기 칸뿐, 기호 이름은 원천 경로를 바꿔 넣으면 같음. `-E` run `m4p644-e2`(`m4-m68k-p644-e2-20261031.json`, `ok`): F = L = B 18316 토큰, stderr 0, i386 0.
- 5 최종 run `m4p644-a1`(`m4-m68k-p644-final-20261031.json`, SHA `b768d45f…`; `known_warnings["snd_stream"]` = F 의 stderr 15 줄): `gate.ok`, 16/16(`m4-m68k-funcbytes-p644-a1-20261031.json`). 확인 `m4-m68k-p644-checks-20261031.json`(`ok` 참): 절 `__text` 4296·`__cstring` 32 뿐이고 `__cstring` 이 원본과 같음, 텍스트 재배치 115, 바깥 정의 아홉이 원본 주소에, 지역 기호는 정적 함수 일곱뿐이고 각자 원본 자리, COMMON 열하나 모두 원본 이름(D136), 미정의 38 개 모두 원본에 있음, 컴파일 줄이 M5 줄과 같음, 의존 124 개의 SHA 사슬 문제 없음·i386 0.
- 6 상태(`m4-m68k-status-p644-20261031.json`, 표 51 → 52 행; 두 번 돌려 같음): 객체 50(OBJECT_MATCH 41, CODE+BSS_INFERRED 9), 행 75/188, 덮은 바이트 71204(32.98%), `object_bytes` 92702, `partial_rows` 에 `m68k-252`·`m68k-253` — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-snd_stream.md`, diff `m68k-snd_stream.diff`.
- 7 기록: PROVENANCE 1199 → 1200 행(일곱 칸, 경로 겹침 없음, `nextmach+authored`; 바뀐 NeXTMach 줄은 diff 에서 python 으로 뽑은 71·74·495·553·871–872·992·1002·1041·1064 — 처음에 호출문 범위로 넓게 적은 것을 고침), MODIFICATIONS 735 → 736 행, DECISIONS D147(150 → 151 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D147).

## 645. M4-151 세부 계획 — m68k `snd_unix.c`(행 253 일부) 진단 A·AF·T·P·B·C(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: §644 바로 뒤의 작은 단위(276 B, 함수 하나)이고 NeXTMach mk-108.1 `nextdev/snd_unix.c`(76 행, SHA-256 `5aad6001…`)가 있습니다.

확인한 사실(이번 세션; 원본 풀이 scratchpad `sndunix.dis`, 기호표, 수는 python):
- 범위 [0x408833a, 0x408844e) 276 B 는 `_snd_unix_ioctl`(0x408833a, 276 B) 하나입니다. 뒤의 이름 없는 항목들(0x408844e 26 B·0x4088468 244 B·…·0x4088588 140 B, `_stopen` 0x4088614 앞까지)은 `_st_sd`(0x40c66d0, 80 B 항목 셈 — `lea a0@(a0:l:4)` 뒤 `asll #4`)·`_st_std`(0x40c6770, 358 B 항목 `mulsw #358`)를 다루므로 `st.c` 의 정적 함수로 봅니다(행 254 `st.c` 의 `start_lo` 가 0x408833a). 그래서 `snd_unix` 의 끝은 0x408844e 로 둡니다(가설; 바이트로 뒷받침).
- 행: 명시 구간 `{"range": ["0x408833a", "0x408844e"], "rows": [], "partial": ["m68k-253", "m68k-254"], …}` 을 `span()` 이 받아들입니다(253 하나면 `('rows', ['m68k-254'])` 로 멈춤). 부분 행이라 덮은 행·백분율은 그대로입니다.
- 자료: 글자 그대로의 참조는 `__common` `_snd_var` +44(`dev_port`)·+48(`task`)·+56(`task_space`, D123)·+60(`task_port`), `_active_threads`(2 곳), `__data` `_kernel_task` 뿐이고 문자열·`__bss` 참조는 없습니다(python 4 바이트 전수).
- 원본과 NeXTMach 글의 차이 후보(원본 목록에서 읽음): ① `thread_start(snd_th, snd_server_loop)` 인자 둘(0x4088380–0x408838a; 1997 `kern/thread.c:1774` 의 두 인자 꼴; NeXTMach 49 행은 `THREAD_SYSTEMMODE` 까지 셋); ② `port_deallocate` 첫 인자가 IPC 공간 — `current_task()` 의 +0x7c(0x408841e–0x4088428, 1997 `task->itk_space`, `kern/task.h:126`)와 `snd_var.task_space`(0x4088438; NeXTMach 69–70 은 `current_task()`·`snd_var.task`; 1997 `port_deallocate(space, name)` 은 `ipc/mach_port.c:1894`); ③ `if (!snd_var.task_port)` 안의 `snd_var.task_port = PORT_NULL;`(NeXTMach 46) 저장이 원본에 없음(0x4088356–0x4088366: `tstl a2@; bnes` 뒤 바로 `task_create`). 나머지(`SOUNDIOCDEVPORT` 0x20004108, `EINVAL` 22, `task_create`·`thread_create`·`thread_resume`·`assert_wait`·`thread_block`, `object_copyin` 둘(`MSG_TYPE_PORT` 6), 메시지 칸, `SND_MSG_RET_DEVICE` 303, `msg_send_from_kernel`)은 NeXTMach 와 같은 차례로 보입니다.
- 원본에는 `_port_deallocate`(0x4046e9e)와 `_port_deallocate_EXTERNAL`(0x40a55ea)이 둘 다 있어, 머리의 이름 바꿈 매크로(`kern/mach_user_internal.h:42`)가 끼어들어도 `undefined_not_in_original` 로는 드러나지 않습니다. 호출 대상은 funcbytes 의 재배치 비교로 봅니다.
- 머리: NeXTMach 이 들이는 `<sound.h>`·`<sys/param.h>`·`<sys/ioctl.h>`·`<sys/errno.h>`·`<kern/kern_port.h>`·`<nextdev/snd_var.h>`·`<sys/user.h>` 가 스테이지(`m0p644-a1-stage`)에 모두 있습니다.

방법(진단; 07 은 바꾸지 않음): 바뀜 하나씩을 가르도록 차례로 쌓은 변형 — A(NeXTMach 글 그대로; `THREAD_SYSTEMMODE` 가 스테이지 어디에도 없어 컴파일 실패가 예상되는 대조, §645.1), AF(A 에 진단 정의 `-DTHREAD_SYSTEMMODE=1`, 값은 NeXTMach `kern/thread_modes.h:37`), T(A 에 ① `thread_start(snd_th, snd_server_loop);` 만), P(T 에 ② 의 앞쪽 `port_deallocate(current_task()->itk_space, …)` 만), B(P 에 ② 의 뒤쪽 `port_deallocate(snd_var.task_space, lport)`), C(B 에서 ③ 의 저장 줄을 뺌 — 저장이 원본에 없는 것은 기계어 관찰이고, 컴파일러가 0 검사 뒤의 같은 값 저장을 지웠을 수도 있어 B 와 C 를 함께 봄). 글은 scratchpad `p645/snd_unix_{A,T,P,B,C}.c` → `08_build/artifacts/m4p645/src/`(AF 는 A 글에 `defs` 만 더한 명세 항목). 명세 `08_build/artifacts/m4p645/spec.json`(바탕 `m0p644-a1-stage`, `m5_line` 같음, 객체 `snd_unix`, 위 명시 구간, `x86_rel` `machdep/i386/dkbad.c`), run `m4p645-p1`, 기록 `m4-m68k-probe-p645-p1-20261031.json`, 변형마다 funcbytes `m4-m68k-funcbytes-p645-<변형>-20261031.json`.

측정: 종료 상태·경고(JSON 칸; A 의 실패는 예상된 결과로 적고, A 객체가 없으면 funcbytes 를 돌리지 않음; run 은 실패 명령이 있어도 나머지를 돌리므로 `collect` 대신 `P compare` 로 봄), 함수 길이·바이트·재배치 대상(funcbytes 는 길이가 다르면 재배치 비교를 건너뛰므로, 객체마다 재배치 대상 이름을 따로 뽑아 `port_deallocate`·`object_copyin` 등이 `_EXTERNAL` 이 아닌지 봄; 스테이지의 이름 바꿈 머리 `kern/mach_user_internal.h` 는 이 파일의 include 닫힘에 닿지 않는 것으로 보임 — 미확인), 절(`__text` 276 목표, 다른 절 없음 예상), 지역 기호, COMMON 이름(원본에 있는지), 원본에 없는 정의·미정의.

판정(미리 정함; 07 은 바꾸지 않음): 맞는 변형이 있으면 구현 계획을 세우고, 바이트로 가려지지 않는 꼴은 구현 전에 여쭙니다. 하나도 맞지 않으면 차이를 적고 다음 진단에서 고칩니다.

### 645.1 교차검토(codex `gpt-6.1-sol`, task kwex6wvwt) 판정과 계획 수정

내가 틀린 것: 변형 A(NeXTMach 글 그대로)가 컴파일될 것으로 보았지만, NeXTMach 49 행의 `THREAD_SYSTEMMODE` 는 스테이지 어디에도 없습니다(`grep -rl` 0 건; NeXTMach 은 `kern/thread_modes.h:37` 에서 1). 또 A → B 는 바뀜 둘(①·② 둘)을 한꺼번에 넣어 원인을 가르지 못했습니다. 대조 변형 AF·T·P 를 더했습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A 는 `THREAD_SYSTEMMODE` 가 없어 컴파일 실패할 것 | 스테이지 `src`·`generated` 전체 `grep -rl THREAD_SYSTEMMODE` 0 건; NeXTMach `kern/thread_modes.h:37` `#define THREAD_SYSTEMMODE 1` | ✅ 채택(위) |
| 변형마다 `defs` 를 줄 수 있음(AF) | `m4_m68k_probe.py:72–75`(`{'src','inc','defs'}`, `-D…` 꼴 검사) | ✅ AF 를 더함 |
| T·P 로 바뀜 하나씩 가를 것 | — | ✅ 더함; python 으로 B 가 P 에 `task_space` 한 줄만 더한 것임을 확인(주석 빼고 같음) |
| 저장 줄이 없는 것은 기계어 관찰일 뿐 — 컴파일러가 지웠을 수 있음 | 원본 0x4088356–0x4088366 은 §645 에서 읽음 | ✅ 방법 문장에 적음(B·C 를 함께 봄) |
| funcbytes 는 길이가 다르면 재배치 비교를 건너뜀; 없는 A 객체로 funcbytes 를 돌리지 말 것; 실패한 명령이 있어도 run 은 계속(`kr_run.py:245–253`), 진단은 `collect` 대신 비교로 | `m68k_funcbytes.py:184–186`(§640.1 에서 읽음), `kr_run.py:245–253` 을 읽음(명령마다 상태를 적고 다음으로) | ✅ 측정 문장을 고침 |
| `object_copyin` 은 1997 에도 첫 인자가 task(`kern/ipc_xxx.c:167–178`)라 바꾸지 말 것 | 원본 0x40883be–0x40883c4(`active_threads[0]->task`), 0x40883e0(`snd_var.task`) | ✅ (변형은 이미 그대로) |
| `snd_var` 오프셋·`itk_space`(+0x7c)·`current_task()` 펼침·상수·`span()`·자료 목록·이어지는 항목이 `st.c` 의 `stgetsdp`…`stinit` 으로 보임 | 오프셋·상수·`span()`·자료는 §645 에서 python 으로; `st.c` 이름 대응은 열지 않음 | ⚖️ 계획의 사실은 그대로(같음), `st.c` 대응은 이번 단위 범위 밖이라 ⏭️ |
| 이름 바꿈 머리는 이 파일의 include 닫힘에 닿지 않음 | 확인하지 않음 | ⏭️ run 의 재배치 대상 이름으로 확인 |
| `assert_wait((int)&…)` 경고 예상 | — | ⏭️ run 이 판정 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 명령입니다.

### 645.2 결과(run `m4p645-p1`, 2026-10-31)

- 명령 12 개: A 컴파일만 종료 1(`THREAD_SYSTEMMODE' undeclared`, 49 행 — 예상한 대조), 나머지 종료 0, 의존 목록 i386 0(`m4-m68k-probe-p645-p1-20261031.json`). AF·T·P·B·C 는 각각 경고 하나(`assert_wait` 첫 인자 정수→포인터, NeXTMach 52 행 그대로).
- 길이와 funcbytes(`m4-m68k-funcbytes-p645-<변형>-20261031.json`): AF 274·T 268·P 272 B 는 원본 276 과 달라 NOT_MATCH; **B·C 는 276 B, OBJECT_MATCH, `candidate`, 같음**. B 와 C 는 canon·`obj_sig` 까지 같습니다 — NeXTMach 46 행 `snd_var.task_port = PORT_NULL;` 저장은 컴파일러가 지우므로 바이트로 가려지지 않습니다.
- 바뀜 하나씩(①·② 앞·② 뒤)을 모두 넣어야 길이가 맞습니다(T → P → B). 다섯 객체 모두 재배치 대상 이름은 `_port_deallocate`·`_object_copyin` 등 내부 이름이고 `_EXTERNAL` 은 없습니다(재배치 표를 python 으로 읽음).
- B: 절은 `__text` 276 뿐, 지역 기호 없음, COMMON 은 공유 머리의 `_master_cpu`(4, 원본에 있음; D136) 하나, 원본에 없는 미정의 0.

판정(미리 정한 대로): B 와 C 가 바이트로 같으므로, 저장 줄을 남길지 여쭌 뒤 구현 계획을 세웁니다.

## 646. M4-152 D148 구현 계획 — 07 `src/machdep/m68k/snd_unix.c`(명시 구간 [0x408833a, 0x408844e), OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(D148 로 적음): NeXTMach 46 행 `snd_var.task_port = PORT_NULL;` 은 남김("NeXTMach 줄 남김 (B)"; B·C 가 바이트·`obj_sig` 까지 같음). 바이트가 정한 것: §645 ①·②(T → P → B 에서 하나씩 길이가 맞아 감). 앞선 결정 그대로: NeXTMach 글 + 표시한 1997 바뀜(D013·D024), `snd_var.task_space`(D123), NeXTMach 글 그대로의 경고(`assert_wait` 하나)는 `known_warnings`, 공유 머리 COMMON `_master_cpu`(D136). include 줄은 바꾸지 않음(스테이지에 모두 있음).

확인한 사실(이번 세션):
- 07 `src/machdep/m68k/` 에 `snd_unix.c` 는 없습니다. `M4FILES[646]`·`EXCEPTS[646]` 두 줄이면 됩니다(`stage_m68k.py` 552·571·727 행 — §644 에서 두 줄을 넣어 밀린 번호, §646.1).
- 생성 초안(scratchpad `gen_p646.py`, 결과 `p646/snd_unix.c` 87 행, `p646/snd_unix_L.c`): NeXTMach 글(SHA `5aad6001…` 를 assert)에 머리 주석 덩이와 바뀐 세 줄(표시 `plan 646`)만. lexer 로 F·L 토큰과 토큰 줄이 같고, F 와 B(§645 기록의 `source_sha256` 에 묶음)의 토큰이 같음을 assert 합니다.
- 상태 기대(python): 객체 51(OBJECT_MATCH 42, CODE+BSS_INFERRED 9), 행 75/188·덮은 바이트 71204(32.98%) 그대로, `object_bytes` 92702 + 276 = 92978, `partial_rows` 에 `m68k-254`.

1. 도구: `stage_m68k.py` 에 `M4FILES[646] = list(M4FILES[644]) + ['snd_unix.c']`, `EXCEPTS[646] = dict(EXCEPTS[644])`, 머리말 목록에 646.
2. 07 파일: `gen_p646.py --write`(이미 있으면 멈춤).
3. 회귀: `--plan 644` 재생성(`m0p644-r646-stage`)의 manifest 가 보관본과 바이트까지 같음, `m0p646-a1-stage` 는 이 파일과 키 `plan`·`m4_sources`·`files` 만 다름; `--plan 644 cmd` 가 `m4p644/m5-644.cmd` 와 같고 `m5-646.cmd` 는 계획 번호만 다름; M5 205(run `m3p646-b644`·`m3p646-cc1`) 객체·출력 같음, `compare`(`m3-m68k-p646-compare-20261031.json`·`-b644-`) `differ_unexpected`·`lost` 빔; x86 `m4-x86-inputs-p646-20261031.json` `ok`·`--plan 646 x86gate` 일곱 묶음 같음.
4. 확인 run `m4p646-p1`(바탕 `m0p646-a1-stage`, 객체 `snd_unix`, §645 의 명시 구간, `x86_rel` `machdep/i386/dkbad.c`): F = `@machdep/m68k/snd_unix.c`, L = `08_build/artifacts/m4p646/src/snd_unix_L.c`. 판정: 종료 0·i386 0, 경고 F·L 각 하나(stderr 2 줄: 함수 문맥 + `assert_wait`), F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 1/1, 재배치 대상 이름에 `_EXTERNAL` 없음, F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx` 와 문자열 표 크기뿐). `-E` run `m4p646-e2`(F·L·B 를 넣은 별도 명세, `-c` → `-E`): `#` 줄 뺀 토큰 F = L = B, stderr 0, i386 0.
5. 최종 run `m4p646-a1`(명세 `08_build/artifacts/m4p646/spec.json`: F 만, `refs` = p1 의 L 객체와 SHA, `known_warnings["snd_unix"]` = F 확인 run 의 stderr 줄 그대로): `gate.ok`. 확인 기록 `m4-m68k-p646-checks-20261031.json`: 절은 `__text` 276 뿐, 재배치 대상(funcbytes 1/1 과 이름), 바깥 정의 `_snd_unix_ioctl` 이 원본 주소에, 지역 기호 없음, COMMON 은 원본 이름뿐, 미정의 모두 원본에 있음, 컴파일 줄 = M5 줄, 의존 파일 i386 0·SHA 사슬 문제 없음.
6. 상태: 근거 `06_reconstruction/evidence/m68k-snd_unix.md` 와 NeXTMach 대비 diff `m68k-snd_unix.diff` 를 먼저 쓰고 `ACCEPTED` 에 한 줄. 상태 도구 두 번, 기대는 위 값.
7. 기록: PROVENANCE 한 행(`nextmach+authored`; 저장소 URL·커밋 `f6bdb9c3…`·`mk-108.1/nextdev/snd_unix.c` — 고지·HISTORY 1–12, `snd_unix_ioctl` 31–73 바탕, 바뀐 줄 49·69·70, D148 로 남긴 46 행, 원본 바이트 근거·최종 기록·diff; MODIFICATIONS 에도 같은 내용), MODIFICATIONS, DECISIONS D148, 계획·HANDOFF·메모리. M7 의무: `_master_cpu` COMMON 합침, 부르는 함수들은 다른 객체.

관문: 명령 종료 0, i386 0, 회귀 같음, `e2` 기록 `ok`, 확인 기록 `ok`, 최종 객체(SHA 를 확인 기록에 묶음)의 funcbytes 1/1, 상태 도구가 멈추지 않음(상태 도구는 근거 문서가 있는지만 보므로 앞의 셋을 따로 요구). 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 646.1 교차검토(codex `gpt-6.1-sol`, task krg0n7qz0) 판정과 계획 수정

내가 틀린 것: `stage_m68k.py` 줄 번호를 또 옛 번호(550·569·725)로 적었습니다. §644 에서 두 줄을 넣어 지금은 552·571·727 입니다. 고쳤습니다(앞으로 도구 줄 번호는 인용 직전에 `grep -n` 으로 다시 뽑음).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 고르는 식은 552·571·727 행 | `grep -n` 출력 | ✅ 채택(위) |
| `gate.ok` 와 상태 도구는 `e2`·확인 기록·최종 funcbytes 를 강제하지 않으니 관문에 명시할 것 | `m4_m68k_probe.py:384–391`(§644.1 에서 읽은 gate 칸), `m4_m68k_status.py:159–161`(근거 문서 존재만 assert, §642.1 에서 읽음) | ✅ 관문 문장을 고침 |
| D013: 바뀐 줄뿐 아니라 함수 전체의 출처(31–73)와 고지(1–12), 남긴 46 행을 PROVENANCE·MODIFICATIONS 에 | NeXTMach `snd_unix.c:31–35·73` 을 읽음; `DECISIONS.md:17`(§642.1 에서 읽음) | ✅ 단계 7 을 고침 |
| 생성기 assert 통과, F·L 87 행, 바뀐 줄 49·69·70 뿐, 46 행 남음, B 의 stderr 2 줄(경고 1), 상태 기대(51·42·9·75·71204·32.98%·92978), 새 구간이 `snd_stream` 끝에 빈틈 없이 붙고 겹침 없음, 부분 행 253 공유는 문제없음 | 생성기 실행 출력(assert 통과), `diff` 출력(49·69–70), B `04.err` 2 줄(§645.2), python 상태 셈(앞 단계) | ✅ (B·C 재배치 적용 비교·토큰 수 324 는 따로 하지 않음 — 행동 바뀌지 않음) |
| F 의 바이트는 컴파일 전에는 미확인; F 와 B 의 객체 전체 같음은 요구하지 말 것 | 판정은 원본 대비와 F = L 로 함 | ✅ 이미 그렇게 짬 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 명령입니다.

### 646.2 결과(2026-10-31)

- 1 도구: `stage_m68k.py` 743 → 745 행(`M4FILES[646]`·`EXCEPTS[646]`, 머리말 목록에 646), `m4_m68k_status.py` 201 → 202 행(`ACCEPTED` 한 줄).
- 2 07: `src/machdep/m68k/snd_unix.c` 87 행, SHA `e2f702d7…`(scratchpad `gen_p646.py --write`; NeXTMach SHA·F = L·F 와 B 토큰을 assert).
- 3 회귀: `--plan 644` 재생성(`m0p644-r646-stage`)의 manifest 가 보관본과 바이트까지 같고 트리 어긋남 0; `m0p646-a1-stage`(986 파일, 트리 어긋남 0)는 새 파일 하나와 키 `plan`·`m4_sources`·`files` 만 다름. `--plan 644 cmd` 가 `m4p644/m5-644.cmd` 와 같고 `m5-646.cmd` 는 411 줄 모두 644→646 만 다름. M5 205(run `m3p646-b644`·`m3p646-cc1`): 객체 205 같음, 나머지 출력도 같고 `run.json` 만 다름; `compare`(`m3-m68k-p646-compare-20261031.json`·`-b644-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 새 파일 하나. x86: `m4-x86-inputs-p646-20261031.json` `ok`, `--plan 646 x86gate` 일곱 묶음 같음·`v183.34` 경로 0.
- 4 확인 run `m4p646-p1`(`m4-m68k-probe-p646-p1-20261031.json`): 명령 4 개 종료 0·i386 0, F·L 경고 각 하나(stderr 2 줄, F 63 행 `assert_wait`), F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 1/1(`-F/L-`), F = L(canon·`obj_sig`); 문자열 표 앞 차이는 `n_strx` 와 문자열 표 크기 칸뿐, 기호 이름은 원천 경로를 바꿔 넣으면 같음. `-E` run `m4p646-e2`(`m4-m68k-p646-e2-20261031.json`, `ok`): F = L = B 11542 토큰, stderr 0, i386 0.
- 5 최종 run `m4p646-a1`(`m4-m68k-p646-final-20261031.json`, SHA `42656cb5…`; `known_warnings["snd_unix"]` = F 의 stderr 2 줄): `gate.ok`, 1/1(`m4-m68k-funcbytes-p646-a1-20261031.json`, 최종 객체 SHA 에 묶음). 확인 `m4-m68k-p646-checks-20261031.json`(`ok` 참): 절 `__text` 276 뿐, 텍스트 재배치 17(대상 이름에 `_EXTERNAL` 없음), `_snd_unix_ioctl` 이 원본 주소에, 지역 기호 없음, COMMON `_master_cpu`(원본 이름), 미정의 13 개 모두 원본에 있음, `e2` ok, 컴파일 줄 = M5 줄, 의존 132 개의 SHA 사슬 문제 없음·i386 0.
- 6 상태(`m4-m68k-status-p646-20261031.json`, 표 52 → 53 행; 두 번 돌려 같음): 객체 51(OBJECT_MATCH 42, CODE+BSS_INFERRED 9), 행 75/188, 덮은 바이트 71204(32.98%), `object_bytes` 92978, `partial_rows` 에 `m68k-254` — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-snd_unix.md`, diff `m68k-snd_unix.diff`.
- 7 기록: PROVENANCE 1200 → 1201 행(일곱 칸, 경로 겹침 없음, `nextmach+authored`; 바뀐 줄 49·69·70 은 diff 에서 python 으로 확인), MODIFICATIONS 736 → 737 행, DECISIONS D148(151 → 152 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D148).

## 647. M4-153 세부 계획 — m68k `st.c`(행 254 일부) NeXTMach 글 진단 A(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: 남은 두 후보 가운데 `snd_server`([0x4085920, 0x4087272), 12 항목)는 NeXTMach 에 없는 1997 함수 `_snd_audio_not_loaded`·`_snd_get_owner` 와 새 정적 여럿이 섞여 있어 바이트 작성 몫이 큽니다. `st.c` 는 원본 25 항목이 NeXTMach 정의 차례와 맞습니다.

확인한 사실(이번 세션; 원본 풀이 scratchpad `st.dis`, 기호표, 수는 python):
- 범위 [0x408844e, 0x4089786) 4920 B, 이어진 26 항목(`m68k-functions.tsv`; 처음에 25·20 으로 잘못 셈, §647.1). 외부 이름은 `_stopen` 282·`_stclose` 84·`_stread` 26·`_stwrite` 28·`_stioctl` 610 뿐이고 나머지 21 은 이름 없음. NeXTMach mk-108.1 `nextdev/st.c`(1279 행, SHA-256 `81239ef5…`; 바이트 0x80 이 섞여 있어 latin-1 로 읽음)의 정의 차례 `stgetsdp`(185)·`stslave`(191)·`stattach`(240)·`stattach2`(246)·`stwake`(257)·`stinit`(264)·`stopen`(281)·`stclose`(347)·`stinquiry`·`sttestrdy`·`stclosefile`·`strewind`·`streqsense`·`stmodesel`·`stmodesen`(366–485)·`stread`(505)·`stwrite`(511)·`st_rw`(517)·`ststart`(613)·`stintr`(680)·`stdone`(840)·`stioctl`(879)·`st_mtop`(1014)·`st_fixed`(1106)·`stcmd_int`(1145)·`stcmd`(1183) — 26 개 — 와 견주면, 원본 26 항목은 크기 차례(26·244·18·8·18·140 / 282·84 / 104·86·88·88·104·106·104 / 26·28 / 580·248·678·182 / 610 / 438·156·124·350)로 26 정의와 하나씩 대응합니다(빠진 것 없음; 0x408856e 8 B 는 비 DEBUG 에서 빈 `stattach2` — `stattach` 0x4088564 와 `stopen` 0x408865a 가 부름).
- 뒷받침: `__data` 0x40b2268 의 `_st_sdsw`(26 B = 이름 4 + 바이트 둘 + 함수 포인터 다섯, `scsivar.h:79–88`)가 `"st"`(0x40abe34)와 0x408844e·0x4088468·0x408855c·0x4088ca4·0x4088d9c 를 담음 = NeXTMach 초기값(`st.c:142–151`)의 `stgetsdp`·`stslave`·`stattach`·`ststart`·`stintr`. 0x408844e 는 `_st_sd` 를, 0x4088468·0x4088588 은 `_st_std`(358 B 항목)를 셈.
- 경계: 앞은 `_snd_unix_ioctl`(§646, 끝 0x408844e), 뒤는 `_vidopen`(0x4089786, `video.c`). 명시 구간은 걸치는 행 셋 — `{"range": ["0x408844e", "0x4089786"], "rows": [], "partial": ["m68k-253", "m68k-254", "m68k-255"], …}` — 이어야 `span()` 이 받아들임(python: 하나나 둘이면 남은 행 이름으로 멈춤).
- 자료: `__data` 는 `_st_sdsw` 26 B(그 뒤 0x40b2282 부터는 `video` 쪽 함수 주소가 이어짐). `__common` 참조 `_st_sd`(1)·`_st_std`(9)·`_active_u`+4(2)·`_kernel_map`(9) — `_st_sd`·`_st_std` 는 NeXTMach `scsiconf.c:55–56` 이 정의하고 `st.c` 는 `stvar.h:118–119` 의 `extern` 으로만 씀. `NST` = 2(python: `_st_std` 자리 716 = 2 × 358, `_st_sd` 160 = 2 × 80). `__cstring` 참조 10 곳: 이 객체 쪽 [0x40abe34, 0x40abf00)(`"st"` 와 `ststart`·`stintr`·`stdone` 의 문자열 일곱)과 다른 객체와 합쳐진 공용 문자열 `"%s Rev %s as "`(0x40ab659)·`"ERROR"`·`"PANIC"`.
- 부르는 것(원본, 레지스터 간접 호출 포함): `scsi_msg` 6·`scsi_dstart` 3·`scsi_docmd`·`scsi_timeout`·`scsi_cintr`, `bzero` 10, `kmem_alloc_wired` 4·`kmem_free` 5·`pmap_kernel` 2, `copyin(msg)`·`copyout(msg)` 각 2(원본에서 두 이름이 같은 주소), `delay` 2, `sleep` 1·`wakeup` 2, `panic` 3·`printf` 4(처음 수는 간접 호출을 빼고 셈, §647.1).
- 머리: NeXTMach 이 들이는 것 가운데 `<st.h>`(구성, 스테이지에 없음), `<nextdev/screg.h>`·`<nextdev/scvar.h>`·`<nextdev/stvar.h>`(NeXTMach 전용, 07·스테이지에 없음) 밖은 스테이지(`m0p646-a1-stage`)에 모두 있음(직접 include 28 개 중 24 있음, 없는 넷이 이 넷; §647.1). `next/*`·`nextdev/*` 는 D104·D110 경로로.

방법(진단; 07 은 바꾸지 않음):
- 진단 머리(`inc`): `st.h`(`#define NST 2`, 위 근거를 주석으로), `nextdev/stvar.h`·`nextdev/screg.h`·`nextdev/scvar.h`(NeXTMach 그대로 — 바꿀 include 없음; `scvar.h:24` 의 `<nextdev/sf_access.h>` 는 스테이지 `src/bsd/nextdev/sf_access.h`).
- 변형 A(scratchpad `p647/st_A.c` → `08_build/artifacts/m4p647/src/`): NeXTMach 글에서 include 일곱 줄만 — `<next/psl.h>` → `<m68k/psl.h>`, `<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<next/printf.h>` → `<kernserv/printf.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`, `<nextdev/disk.h>` → `<dev/disk.h>`, `<nextdev/scsireg.h>` → `<dev/m68k/scsireg.h>`, `<nextdev/scsivar.h>` → `<dev/m68k/scsivar.h>`(D104; `autoconf.c:50–53` 과 같은 꼴). `<nextdev/dma.h>` 는 07 사본(§544) 그대로.
- 명세 `08_build/artifacts/m4p647/spec.json`: 바탕 `m0p646-a1-stage`, `m5_line` 같음, 객체 `st`(위 명시 구간), `x86_rel` `machdep/i386/dkbad.c`. run `m4p647-p1`(REGISTRY 에 없음), 기록 `m4-m68k-probe-p647-p1-20261031.json`, funcbytes `m4-m68k-funcbytes-p647-A-20261031.json`(이름 없는 20 의 대응은 결과 객체의 지역 기호 차례를 보고 정함 — 원본 크기와 차례로 맞추되 `stattach2` 자리를 결과에서 확인).
- 측정: 종료 상태·경고(JSON 칸), 함수 수·길이·바이트·재배치 대상(길이가 다른 함수는 디스어셈블 비교), 절 크기(`__text` 4920·`__data` 26 목표), `__data` 내용(재배치 풀어 원본과), `__cstring`(이 객체 몫의 내용), 지역 기호, COMMON·정의·미정의(원본 이름인지).

판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고 다음 계획에서 1997 꼴을 시험합니다. 컴파일이 안 되면 원인을 적고 머리·글을 최소로 고친 꼴로 다시 돌립니다. 머리 공급(07 사본 위치)과 `st.h` 구성 값은 구현 전에 정합니다(D104·D121 선례).

### 647.1 교차검토(codex `gpt-6.1-sol`, task kubt3l8jx) 판정과 계획 수정 — 진단을 돌리기 전에 멈춤

내가 틀린 것: ① 항목 수를 25(이름 없는 것 20)로 적고 "`stattach2` 가 빠진 꼴" 이라 했으나, python 으로 다시 세니 26(21)이고 빠진 함수는 없습니다. ② 호출 수에서 레지스터 간접 호출(`lea _kmem_alloc_wired,a2; jsr a2@` 등)을 빼고 셌습니다. ③ 머리 수를 25 라 적었으나 직접 include 는 28(있음 24·없음 4)입니다. ④ 진단 A 가 컴파일될 것으로 보았지만 `DMA_ALIGN`(NeXTMach `st.c:270`)이 1997 머리에 없고(07 `nextdev/dma.h:45–47` 이 지움, 공개 머리에는 `DMA_BEGINALIGN`), `st_rw` 가 선언 전에 불리고(507·513) 뒤의 프로토타입 정의(517)가 `dev_t`(`short`, `sys/types.h:121`)를 받아 충돌합니다. 위 ①–③ 은 §647 본문을 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 26 항목·21 이름 없음, 26 정의와 하나씩 대응(빠진 것 없음) | python 재셈(26·4920·21); `st.dis` 0x4088564·0x408856e(빈 함수) | ✅ 채택(위 ①) |
| 간접 호출 포함 호출 수(`kmem_alloc_wired` 4·`kmem_free` 5·`printf` 4) | `st.dis` 의 `lea _kmem_alloc_wired,a2`(0x4088ac2)·`jsr a2@` 두 번(0x4088ac8·0x4088ae8), python 으로 함수 주소 `lea` 셈(셋 각 1) | ✅ 채택(위 ②) |
| 직접 include 28·있음 24 | 이번 세션의 존재 검사(25 경로 중 정본 머리 24 + 07 `dma.h`)와 없는 넷 | ✅ 문구 고침 |
| `DMA_ALIGN` 이 스테이지에 없음 | 스테이지 전체 `#define DMA_ALIGN` 0 건; `nextdev/dma.h:45–47` 주석, `dev/m68k/dma.h:37` `DMA_BEGINALIGN` | ✅ 진단 A 는 컴파일되지 않음 |
| `st_rw` 암묵 선언 뒤 `dev_t`(short) 프로토타입 정의 충돌 | NeXTMach `st.c:507·513·517`, 스테이지 `sys/types.h:121` `typedef short dev_t;` | ✅ (진단 꼴은 나중에 정함) |
| **1997 `struct scsi_ctrl` 배치가 다름**: `stslave` 가 `controller+24+target*8+lun` 바이트를 늘리고, `stcmd` 가 `sc_ipl` 을 +89 에서 읽음(NeXTMach `scsivar.h` 의 `sc_lunmask[8]` 다음이면 +33) | `st.dis` 0x408851a–0x408852c(`asll #3`·`addal a4@(24)`·`addqb #1,a0@(24,d1)`), 0x4089652–0x4089656(`moveb a0@(89),d0`), 07 `nextmach/nextdev/scsivar.h:50–62` | ✅ — 1997 은 8×8 바이트 표(+24, 64 B) 다음 `sc_target` +88·`sc_ipl` +89 로 보임(이름은 미정) |
| `st_rw`·`stioctl`·`st_mtop` 의 할당은 1997 `kmem_alloc_wired(map, &addr, size)` 꼴이고 `st_rw` 는 첫 할당 실패를 먼저 검사·둘째 실패 때 첫째를 풂; NeXTMach 은 `kmem_alloc` 포인터 반환 | `st.dis` 0x4088ab4–0x4088aee(인자 `0x52`·`&fp-4`·`_kernel_map`, `tstl d0; beq`, 실패면 12) | ✅ 1997 바뀜 후보로 적음 |
| `stslave` 는 `"%s Rev %s as "`(0x40ab659)와 36 자리에서 끝맺음 | `st.dis` 0x40884e0–0x40884fa | ✅ 1997 바뀜 후보 |
| `st_rw` 의 가변 블록 읽기에서 `STF_SIL` 검사 없이 SIL 을 켬 | NeXTMach `st.c:565`; 원본 0x4088b88–0x4088b9e 는 읽지 않음 | ⏭️ 진단이 판정 |
| `stinit` 은 16 바이트 맞춤(`-16`)과 358 B `bzero` | `st.dis` 의 `stinit` 은 읽지 않음 | ⏭️ 진단이 판정 |
| 그 밖의 사실(SHA·1279 행·`st_sdsw` 26 B·`NST` 2·COMMON 참조 수·`span()`) 은 맞음; `__data` 0x40b2282 뒤 첫 포인터는 0x40b228c | 이번 세션 python 출력 | ✅ |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 명령입니다.

판정: 진단 A 를 그대로 돌리지 않습니다. 1997 `struct scsi_ctrl` 은 공유 07 머리 `07_kernel/nextmach/nextdev/scsivar.h`(받아들인 `autoconf` 가 들임; 앞으로 `sd`·`sg`·`scsi`·`sc` 도 씀)를 넓히는 일이라, §620–622(1997 `struct pcb`, D142)처럼 배치 조사부터 할지 사용자에게 여쭙니다.

## 648. M4-154 세부 계획 — 1997 m68k `struct scsi_ctrl` 배치 조사(07·도구·표 변경 없음; 코딩 전, 2026-10-31)

사용자 결정(이 절에서 여쭘): `st.c` 에 앞서 "scsi_ctrl 배치 조사부터" — §620(1997 `struct pcb`, D142)와 같은 절차. 공유 머리를 넓히는 꼴과 칸 이름은 이 조사 뒤 따로 계획하고 여쭙니다.

목적: `st.c`(§647)·`sd`·`sg`·`scsi`·`sc` 의 공통 전제인 1997 `struct scsi_ctrl` 의 칸 배치를 원본 바이트에서 모으고, NeXTMach `nextdev/scsivar.h:50–62`(07 사본 `07_kernel/nextmach/nextdev/scsivar.h`, 스테이지 `src/bsd/dev/m68k/scsivar.h`)와 대조합니다.

확인한 사실(이번 세션; 원본 풀이, `symbols.tsv`·`m68k-m4-inventory.tsv`, python):
- 원본 `__common` `_sc_sc`(0x40c5b90)는 다음 기호 `_scsi_ndevices` 까지 100 B 자리입니다(구성 `NSC` 1, §573 의 가설 D129 와 함께 보면 구조체 하나의 자리 — 크기 자체는 자리일 뿐 확정 아님). NeXTMach 배치는 `sc_dis_q` 8·`sc_ctrl_list` 8·`sc_bcp` 4·`sc_scswp` 4·`sc_lunmask[8]` 8(+24)·`sc_target`(+32)·`sc_ipl`(+33)·`sc_active`·`sc_expectintr`·`sc_timer`(int)·`sc_disc_cnt` 입니다.
- 1997 접근 두 곳(§647.1): `stslave` 0x408851a–0x408852c 가 `sd_scp`(+24 of `scsi_device`; 07 `scsivar.h:94–100` 의 배치와 같음 — `sd_target` +28·`sd_lun` +29 도 원본과 같음)에서 얻은 `scsi_ctrl` 의 `+24 + target*8 + lun` 바이트를 1 늘리고, `stcmd` 0x4089652–0x4089656 이 +89 바이트를 `spl` 값으로 읽음(NeXTMach 이면 `sc_ipl` +33). 8×8 바이트 표가 +24 에 있고 그 뒤가 56 B 밀린 꼴로 보입니다(가설).
- SCSI 파일의 원본 범위(인벤토리 행 235–241, `_scminphys` 0x407bb06 앞의 `sc.c` 부분 포함): 대략 [0x407aa4c, 0x407ff14) — `sc`·`scsi`(`_scsi_init` 0x407bd9c … `_scsi_sensemsg`)·`sd`(`_sdopen` 0x407ce8c …)·`sf_access`·`sg`(`_sgopen` 0x407f70e …) — 와 `st` [0x408844e, 0x4089786). 이 구조체를 쓰는 받아들인 07 파일은 `autoconf.c` 뿐이고 칸은 쓰지 않습니다(grep: `scsivar.h` 를 들이지만 `sc_*`·`scsi_ctrl` 칸 사용 0).
- 원본 `__data` 에는 `_sc_scsw`(12 B)·`_scsi_sdswlist`(32 B)·`_sd_sdsw`·`_sg_sdsw`(각 26 B), `__common` 에는 `_sc_s5c` 592 B·`_sd_sd` 640·`_sd_sdd` 1552·`_sg_sd` 320·`_sg_sgd` 264 가 있습니다(다음 기호까지의 자리).

방법(분석만; §648.1 에서 고침 — §620 최종본(`plans/RECONSTRUCTION_PLAN-615-622.md:323`)처럼 함수 단위 읽기를 주로 하고, 실기 탐침은 뺌):
1. 후보 목록: codex 가 낸 접근 장부(§648.1; 함수·주소·오프셋·크기·읽기/쓰기, 112 곳 + 64 B 지우기)를 "검증할 후보" 로만 받습니다. scratchpad `scsictrl_survey.py` 가 후보마다 원본 풀이(scratchpad `scsi_all.dis`·`st.dis`, 로컬 `m68k-linux-gnu-objdump`)의 그 주소 명령을 읽어 변위·크기·읽기/쓰기가 맞는지 기계로 대조하고, 기준 레지스터가 `scsi_ctrl` 인지(어디서 왔는지)는 함수마다 원본 풀이를 읽어 확인한 결과를 기록에 적습니다(맞지 않거나 출처를 못 댄 후보는 "미확인" 으로 남김).
2. 놓친 접근 찾기: SCSI 범위의 모든 명령에서 변위 88–99 와 `+24` 를 지닌 색인 접근(`@(24,…)`)을 뽑아 장부에 없는 것을 따로 적고, 하나씩 출처를 읽어 분류합니다(다른 구조체의 같은 오프셋은 "무관" 으로 적음).
3. 크기 사실: 원본의 컨트롤러 간격 98(`scgo`·0x407aeae `mulsw #98`, 0x407ab88–0x407ab98 `((1+2)·16+1)·2`)과 `_sc_sc` 자리 100, `scsi_probe` 의 64 B `bzero`(0x407bde0–0x407bde8)를 python 으로 적습니다.
4. NeXTMach 배치는 python 으로 셉니다(큐·포인터·바이트·int 만 있는 구조체이고 m68k ABI 의 2 바이트 맞춤은 `09_validation/reconstruction/m0-abi-m68k-20261009.json:1326`). 대조표: 원본 오프셋마다 근거와 NeXTMach 칸(뜻), 확정/추정을 나눔.

판정(미리 정함): 07·공유 머리·도구는 바꾸지 않습니다. 결과로 (a) 1997 배치에서 확정된 칸, (b) NeXTMach 와 뜻이 같은 칸, (c) 근거가 없는 칸을 나누어 적고, 공유 머리를 넓히는 꼴(칸 이름 포함)을 다음 계획에서 여쭙니다.

관문: 원본·참고 파일의 SHA-256 을 기록에 둡니다.

### 648.1 교차검토(codex `gpt-6.1-sol`, task k3kym7boa) 판정과 계획 수정

내가 틀린 것: ① 직선 근사 수집기(주소 레지스터만 따라감)를 주 방법으로 적었는데, §620 최종본은 이미 함수 단위 읽기로 바꾸고 실기 탐침을 뺐습니다(`plans/RECONSTRUCTION_PLAN-615-622.md:323`). 옛 판을 따랐습니다. ② 크기 근거로 100 B 자리만 적었고, 원본이 컨트롤러를 98 B 간격으로 색인한다는 더 강한 사실을 놓쳤습니다. 방법을 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본은 컨트롤러를 98 B 간격으로 색인(0x407aeae `mulsw #98`, 0x407ab88–0x407ab98) | scratchpad `scsi_all.dis` 98–103·330–331 행을 읽음; python `((1+2)*16+1)*2` = 98 | ✅ 채택 |
| `scsi_probe` 가 +16(`bus_ctrl`)·+20(`scsw`)·+88(=7) 을 쓰고 +24 부터 64 B 를 지운 뒤 자기 target 행의 lun 8 칸에 1, +90·+91 지움, +89 ← 인자, +96 지움, +0/+4 큐 초기화 | `scsi_all.dis` 0x407bdca–0x407be1e 를 읽음 | ✅ |
| NeXTMach `sizeof(scsi_ctrl)` 은 42(44 아님 — 다만 나는 크기를 적지 않았음) | python 배치는 4 단계에서 셈 | ⏭️ 4 단계에서 확인 |
| 직선 근사는 데이터 레지스터 별칭(`scintr` d3, `scdmastart` d2)·`scsi_5390_ctrl.s5c_scp`·호출 뒤 레지스터 무효·분기 합류를 놓침; `+24` 시드에는 출처가 필요 | — | ✅ 방법을 함수 단위 읽기로 바꿈(1·2 단계) |
| 112 곳 접근 장부와 1997 배치 표(+0…+23 NeXTMach 그대로, +24–87 8×8 표, +88 target·+89 ipl·+90 active·+91 expectintr·+92 timer(int)·+96 disc_cnt, +97 은 채움으로 보임) | 표본: 0x407bdce–0x407be1e(위), 0x407aeae 를 읽음; 나머지는 미확인 | ⚖️ 후보로만 받음 — 1 단계가 하나씩 기계 대조 |
| SCSI 첫 범위는 `od` 꼬리(`_od_panel_abort`·`_oddump`·`_odsize`)를 포함하고 `sc.c` 는 0x407aae0 부터로 보임 | 확인하지 않음 | ⏭️ 찾는 범위로만 쓰므로 그대로(과포함 표시) |
| 자리(span)를 `sizeof` 로 올리지 말 것(`_scsi_sdswlist` 32 B 자리 중 16 B 만 목록) | — | ✅ 기록에 "자리" 로 적음 |
| python 배치로 충분, 실기 탐침은 원본 배치를 증명하지 못함 | §620 최종본과 같음 | ✅ 탐침을 뺌 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 python 입니다.

### 648.2 결과(2026-10-31; 기록 `09_validation/reconstruction/m68k-scsictrl-survey-p648-20261031.json`)

- 후보 112 곳(codex 장부) 모두 원본 명령과 변위·크기가 맞습니다(scratchpad `scsictrl_survey.py`; 원본 풀이 `scsi_all.dis` [0x407aa4c, 0x407ff14)·`st.dis`). 기준 레지스터의 출처를 함수마다 원본 풀이에서 읽었습니다: `scsi_*` 의 `scsi_ctrl *` 인자(`fp@(8)`/`fp@(12)`; NeXTMach `scsivar.h:171–184`), `scsi_device` 의 `sd_scp`(+24), `sc.c` 함수의 `scsi_5390_ctrl` 첫 칸 `s5c_scp`(NeXTMach `scvar.h:30–31`; `scintr` 의 d3·`scdmastart` 의 d2 별칭 포함), `scgo` 의 `_sc_sc + 98 × 번호`, `scsi_timer` 의 컨트롤러 목록 머리 0x40b4fd2(+8 로 다음). 장부 밖에서 변위 88–99·`+24` 색인으로 걸린 24 곳은 모두 `sd` 쪽 다른 구조체(기준이 `x@(210)`·`a4@(4)` 등)라 `scsi_ctrl` 이 아닙니다.
- 크기: 컨트롤러 간격 98(0x407aeae `mulsw #98`; 0x407ab88–0x407ab98 `((1+2)·16+1)·2`), `_sc_sc` 자리 100, `scsi_probe` 의 `bzero(scp+24, 0x40)`(0x407bde0–0x407bde8).
- 1997 배치(원본 바이트로 확정한 오프셋·크기; 이름은 NeXTMach 의 뜻으로 추정): +0 `sc_dis_q`(8)·+8 `sc_ctrl_list`(8)·+16 `sc_bcp`·+20 `sc_scswp` — NeXTMach 그대로; **+24 8×8 바이트 표**(`[target][lun]`; 장치 slave 가 늘리고 `sgclose`·`sgsettl` 이 줄이며 `scsi_slave` 가 0 인지 보고 `scsi_probe` 가 지운 뒤 자기 target 행을 1 로 채움 — NeXTMach 의 lun 비트마스크 `sc_lunmask[8]` 자리); +88 `sc_target`·+89 `sc_ipl`·+90 `sc_active`·+91 `sc_expectintr`·+92 `sc_timer`(int)·+96 `sc_disc_cnt`; +97 은 접근 없음(채움). python 배치: NeXTMach 은 크기 42(표 +24 8 B, `sc_target` +32 … `sc_disc_cnt` +40), 표만 64 B 로 넓힌 꼴은 크기 98 이고 위 오프셋 전부와 같습니다(m68k 2 바이트 맞춤, `m0-abi-m68k-20261009.json:1326`).
- 새 칸은 필요 없고, 바뀐 것은 표의 차원(그리고 쓰임이 비트마스크에서 개수로 바뀐 것)뿐입니다. 이 구조체를 쓰는 받아들인 07 은 `autoconf.c` 이고 칸을 쓰지 않습니다.

판정(미리 정한 대로): 07·공유 머리·도구는 바꾸지 않았습니다. 공유 머리를 넓히는 꼴(표의 이름·선언)을 다음 계획 전에 여쭙니다.

## 649. M4-155 D149 구현 계획 — 공유 07 머리 `nextmach/nextdev/scsivar.h` 의 `struct scsi_ctrl` 를 1997 배치로(코딩 전, 2026-10-31)

사용자 결정(D149 로 적음): 표는 NeXTMach 이름을 두고 차원만 늘림 — `u_char sc_lunmask[SCSI_NTARGETS][SCSI_NLUNS];`("NeXTMach 이름 유지"), 표시 주석에 1997 쓰임(대상·lun 마다 붙은 장치 수, +24, 64 B)을 적음. 다른 칸은 NeXTMach 그대로.

확인한 사실(이번 세션):
- 07 파일 `07_kernel/nextmach/nextdev/scsivar.h` 361 행, SHA `5ab5020a…`, 바꿀 줄은 55 행 `u_char	sc_lunmask[SCSI_NTARGETS]; /* bitmask of attached luns */`. `SCSI_NLUNS`·`SCSI_NTARGETS` 는 07 `nextmach/nextdev/scsireg.h:321–322`(8·8)이고, 이 머리를 들이는 글은 그 앞에 `scsireg.h` 를 들입니다(07 `autoconf.c:52–53`, NeXTMach `st.c` 의 차례). PROVENANCE 1128 행·MODIFICATIONS 674 행이 이 파일을 적습니다.
- 이 머리를 들이는 컴파일 객체: 받아들인 M4 51 객체 가운데 `autoconf` 하나(최종 run 의 의존 목록을 python 으로 모두 읽음: `m4p526-a1` `01.out`), M5 205 객체 가운데 0 으로 보임(§649.1: `m3p646-cc1` 에는 의존 목록 명령이 없어 이 근거는 틀렸음 — M5 객체의 STABS 에 `scsivar.h` 가 없고 이 머리를 들이는 글이 M5 컴파일 목록에 없다는 것까지만 확인). `autoconf.c` 는 `scsi_ctrl` 칸을 쓰지 않으므로 STABS 밖 바이트는 그대로일 것으로 예상합니다.
- 1997 배치는 §648.2(기록 `m68k-scsictrl-survey-p648-20261031.json`)이고, python 배치로 이 한 줄 바꿈이 원본 오프셋 전부와 크기 98 을 냅니다.

1. 07 파일을 scratchpad `gen_p649.py` 로 고칩니다(먼저 사본, 바꾸기 전 SHA 단언): 55 행만 `u_char	sc_lunmask[SCSI_NTARGETS][SCSI_NLUNS];` 와 표시 주석 `/* plan 649 (D149): 1997 count of attached devices per target and lun (+24, 64 B; NeXTMach: bitmask of attached luns, [SCSI_NTARGETS]) */`. 다른 줄은 그대로(python 으로 줄 하나만 다름을 단언). 표시 줄의 `*/` 뒤에 글이 없음.
2. `stage_m68k.py`: `M4FILES[649] = list(M4FILES[646])`, `EXCEPTS[649] = dict(EXCEPTS[646])`, 머리말 목록에 649(07 머리가 바뀌었으므로 새 스테이지 번호로 기록). 머리 표는 그대로.
3. 회귀(§622 와 같은 술어: `canon` 같음 + `obj_sig` 의 `header`·`sections`·`symbols` 같음; STABS 수 차이는 따로 적음):
   - 스테이지: `m0p649-a1-stage` 와 보관 `m0p646-a1-stage` 의 매니페스트 차이는 키 `plan` 과 `files` 의 `src/bsd/dev/m68k/scsivar.h` 한 줄(해시)뿐, 스테이지 파일 내용 차이도 그 머리 하나; `--plan 646` 재생성(`m0p646-r649-stage`)은 보관본과 그 머리 한 줄만 다름(python 단언).
   - M5: `--plan 649 cmd` 와 `m4p646/m5-646.cmd` 의 차이는 계획 번호뿐; run `m3p649-cc1` 의 205 객체·stderr 가 `m3p646-cc1` 과 바이트까지 같음(이 머리를 들이는 M5 객체가 없으므로); `--plan 649 compare` 의 `differ_unexpected`·`lost` 빔.
   - M4: `autoconf` 하나를 새 스테이지로 다시 컴파일(run `m4p649-r1`, 명세 `08_build/artifacts/m4p649/r1/spec.json`: §526 의 명세에서 바탕만 `m0p649-a1-stage`, `refs` = 받아들인 객체 `m4p526-a1` 의 F 와 그 SHA, `bss_inferred` 그대로): 종료 0, 경고 기준과 같음, i386 0, L1 사유가 받아들일 때와 같음(`__DATA,__bss: unverified` 만), 받아들인 객체와 술어를 채움(python). 탐침의 `refs_equal` 은 STABS 수까지 보므로 거짓일 수 있고 그 경우 까닭을 적음(§622 와 같음).
   - x86: `m4_x86_inputs.py s6ln` `ok`, `--plan 649 x86gate` 일곱 같음·`v183.34` 경로 0.
   - 상태 도구 두 번: 상태표가 지금(§646) 표와 같음(받아들인 객체 기록을 다시 검사하므로 바뀌지 않아야 함).
4. 기록: PROVENANCE 1128 행을 고침(일곱 칸; 바뀐 SHA, plan 649 의 한 줄과 D149, 근거 §648 조사 기록), MODIFICATIONS 새 행, DECISIONS D149, 근거 문서 `06_reconstruction/evidence/m68k-autoconf.md` 에 plan 649 절(머리 바뀜과 회귀), 계획 결과, HANDOFF·메모리.

판정(미리 정함): 3 이 모두 맞으면 받아들입니다. 하나라도 어긋나면 07 파일을 사본으로 되돌리고 사용자에게 알립니다.

관문: 명령 종료 0, 경고·stderr 기준과 같음, i386 머리 0, 회귀 단언 통과.

### 649.1 교차검토(codex `gpt-6.1-sol`, task km1y34h42) 판정 — 코딩 전에 멈춤

내가 틀린 것: ① M5 에 이 머리를 쓰는 객체가 없다는 근거로 `m3p646-cc1` 의 의존 목록을 댔지만, 그 run 은 컴파일 명령 205 개뿐이고 의존 목록 명령이 없습니다(codex; `stage_m68k.py` 의 M5 명령 생성도 컴파일만). ② 상태 도구가 "지금 표와 같음" 이 될 것이라 적었지만, 상태 도구는 받아들인 기록마다 그 스테이지 매니페스트의 `m4_headers` 전부를 지금 07 파일과 대조하므로(`m4_m68k_status.py:129–132`), 머리를 고치면 이 머리를 실제로 쓰지 않는 객체의 기록까지 멈춥니다. §622 의 `thread.h` 는 덮어쓰기라 `m4_headers` 에 없어서 이 문제가 없었습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상태 도구는 기록마다 `m4_headers` 전부의 해시를 검사 | `m4_m68k_status.py:112–132` 를 열어 읽음 | ✅ |
| `scsivar.h` 를 `m4_headers` 에 가진 받아들인 기록 29·객체 37 | python: `ACCEPTED` 41 기록의 명세 바탕 매니페스트를 모두 읽음 → 29 기록, 객체 37(`autoconf` … `snd_unix`) | ✅ — 머리를 고치면 이 37 객체 기록이 상태 검사에서 멈춤 |
| 이 머리를 실제로 들이는 받아들인 객체는 `autoconf` 하나(51 객체 최종 run 의존 목록) | 이번 세션 python(최종 run 의 `_log/*.out` 전부에서 `scsivar.h` 를 찾음: `m4p526-a1` `01.out` 하나) | ✅ |
| `m3p646-cc1` 에는 의존 목록이 없음 | 위 python 에서 `m3p646-cc1/out/_log/*.out` 의 `scsivar.h` 0 건이 빈 출력 때문임을 codex 가 짚음; 이 run 의 명령은 컴파일 205 | ✅ 위 ① |
| 탐침은 `refs_equal`(STABS 수 포함)이 거짓이면 종료 1 — "종료 0" 관문과 어긋남 | `m4_m68k_probe.py:384–400`(§644.1 에서 읽음) | ✅ 관문 문장을 고칠 것 |
| 기준 객체는 그대로 `m4p526-a1` 의 F(SHA `ff79ac49…`); §622 회귀 객체와도 비 STABS 같음 | 상태표의 `autoconf` 행(기록 `m4-m68k-p526-final-20261026.json`, SHA `ff79ac49…`) | ✅ |
| 한 줄 바꿈이 조사 배치(오프셋 전부, 크기 98)를 냄; 07 에 `sc_lunmask` 를 쓰는 곳은 선언뿐 | §648.2 python 배치; `grep sc_lunmask` 07 은 선언 하나 | ✅ |

판정: 머리를 고치기 전에, 상태 도구의 머리 검사를 어떻게 다룰지 여쭙니다(검사를 바꾸는 것은 미리 정한 기준을 바꾸는 일이므로).

### 649.2 고친 구현 계획(사용자 결정 반영, 코딩 전, 2026-10-31)

사용자 결정(D149 에 더함): 상태 도구의 머리 검사를 "의존 머리로 좁힘" — 받아들인 기록마다 스테이지 `m4_headers` 전부가 아니라, 그 객체의 최종 run 의존 목록(해시로 묶인 `-M` 출력)에 나오는 `m4_headers` 만 지금 07 파일과 대조합니다. `autoconf` 는 새 머리로 다시 받아들입니다(§554.3·§560 선례).

1. 도구(머리 바꾸기 전, 지금 07 로 회귀):
   a. `m4_m68k_status.py`: 기록마다 `run.cmd` 에서 그 객체 원천의 의존 명령(`-M`) 번호를 찾고, `08_build/runs/<run>/stage/_log/NN.out` 의 SHA 를 그 run 의 `output.manifest` 와 대조한 뒤, 출력의 `src/…` 경로(앞의 `src/` 를 뗀 것이 스테이지 매니페스트 키)와 `m4_headers` 의 교집합만 해시를 검사합니다. 의존 출력이 없거나 해시가 다르면 멈춥니다. 머리말에 plan 649 규칙을 적습니다.
   b. 회귀(python): 지금 07 로 상태 도구를 돌려 상태표(tsv)가 §646 표와 같고 요약이 같음; 기록마다 옛 검사와 새 검사가 둘 다 통과; 메모리 안 모의(07 파일은 건드리지 않고 `sha()` 를 바꿔치기)로 (i) `scsivar.h` 해시가 다르다고 하면 옛 검사는 29 기록에서, 새 검사는 `autoconf`(§526) 기록 하나에서만 멈춤, (ii) `m4_headers` 38 개 각각에 대해 해시가 다르다고 하면 새 검사가 멈추는 기록이 그 머리를 의존 출력에 가진 기록과 정확히 같음, (iii) 의존 출력이 없거나 해시가 틀리거나 원천 파일이 의존 목록 첫 항목에 없거나 경로가 매니페스트 키로 풀리지 않거나 의존 명령의 `-D`·`-I` 가 컴파일 명령과 다르면 멈춤. 의존 명령 번호는 `RUN` 줄만 0 부터 셈. `-imacros src/generated/meta_features.h` 는 `-M` 출력에 나오지 않지만 그 닫힘은 생성 구성 머리뿐이라 `m4_headers` 에 닿지 않음(§649.3).
2. 07 머리: §649 의 1 그대로(55 행 한 줄, `gen_p649.py`).
3. `stage_m68k.py`: `M4FILES[649] = list(M4FILES[646])`, `EXCEPTS[649] = dict(EXCEPTS[646])`, 머리말 목록에 649.
4. 회귀:
   - 스테이지: `m0p649-a1-stage` 와 보관 `m0p646-a1-stage` 의 차이는 키 `plan` 과 `src/bsd/dev/m68k/scsivar.h` 한 줄(해시)뿐, 스테이지 파일 내용 차이도 그 머리 하나; `--plan 646` 재생성(`m0p646-r649-stage`)은 보관본과 그 머리 한 줄만 다름.
   - M5: `m5-649.cmd` 와 `m5-646.cmd` 의 차이는 계획 번호뿐; run `m3p649-b646`(옛 명령·옛 스테이지)·`m3p649-cc1`(새 명령·새 스테이지)의 205 객체와 다른 출력이 같음(M5 명령은 컴파일만이라 이것이 M5 의존 근거가 됨); `compare` 의 `differ_unexpected`·`lost` 빔.
   - x86: `m4_x86_inputs.py s6ln` `ok`, `--plan 649 x86gate` 일곱 같음·`v183.34` 경로 0.
5. `autoconf` 재수락(§560 꼴):
   - 확인 run `m4p649-p1`(명세 `08_build/artifacts/m4p649/confirm/spec.json`: 바탕 `m0p649-a1-stage`, 객체 `autoconf` `m68k-210`, F = `@machdep/m68k/autoconf.c`, L = `08_build/artifacts/m4p526/src/autoconf_L.c`): 종료 0, 경고 0, i386 0, F·L 의 L1 사유가 `__DATA,__bss: unverified` 하나, `full_span`, F = L(canon·`obj_sig`), F 와 받아들인 §526 객체(`m4p526-a1` F, SHA `ff79ac49…`)가 canon·`obj_sig` 의 `header`·`sections`·`symbols` 같음(STABS 수만 다를 수 있음; python).
   - 최종 run `m4p649-a1`(명세 `08_build/artifacts/m4p649/spec.json`: F 만, `refs` = p1 L 과 SHA, `bss_inferred` [`autoconf`]): `gate.ok`.
   - zerofill: `m5_m68k_zerofill.py objs` 로 `autoconf:<최종 F>:<§526 F>`(기록 `09_validation/reconstruction/m4-m68k-zerofill-p649-20261031.json`): `ok`, 후보가 §526 과 같은 bss 자리.
   - `ACCEPTED` 의 §526 넷 묶음을 §649 넷 묶음으로 바꿈. 상태 도구 두 번: 상태표가 §646 표와 `autoconf` 행의 plan·record·obj_sha256 만 다르고, 요약(객체 51, 행 75/188, 71204 B, `object_bytes` 92978)이 같음.
6. 기록: PROVENANCE 1128 행(`scsivar.h`; 바뀐 SHA·D149·원 선언 `mk-108.1/nextdev/scsivar.h:54`·근거 §648 조사 기록)과 `autoconf.c` 행(재수락 기록), MODIFICATIONS 새 행, DECISIONS D149, 근거 `m68k-autoconf.md` 에 plan 649 절(머리 바뀜·재수락; 조사 기록과 구분), `m68k-autoconf.diff` 는 역사 판으로 두고 새 diff 를 만들지 않음(`autoconf.c` 는 바뀌지 않음), 계획 결과, HANDOFF·메모리.

관문: 컴파일·의존 명령 종료 0, 경고·stderr 기준과 같음, i386 0, 위 단언 모두 통과. 최종 run `m4p649-a1` 은 새 p1 L 을 기준으로 하므로 `gate.ok` 가 참이어야 합니다(STABS 수 차이 허용은 §526 객체와의 python 비교에만 적용). 하나라도 어긋나면 07 머리를 사본으로 되돌리고 알립니다.

### 649.3 교차검토(codex `gpt-6.1-sol`, task keoi4h53d) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 41 기록·51 객체 모두 의존 명령 하나·해시로 묶인 출력·매니페스트 키로 풀리는 경로를 가짐; 어느 객체도 기대지 않는 `m4_headers` 는 없음 | 이번 세션 python(같은 검사: problems 0, 쓰이지 않는 머리 0) | ✅ |
| `-imacros src/generated/meta_features.h` 는 `-M` 출력에 빠지지만 그 닫힘에 `m4_headers` 가 없음 | `m4p512-a1` `01.out` 에 `meta_features` 0 건; 스테이지 `generated/meta_features.h` 를 읽음(생성 구성 머리만 `#import`) | ✅ 1b 에 적음 |
| 1b 는 이번 머리 하나의 모의뿐이니 모든 머리·나쁜 입력(없음·해시 틀림·원천 없음·풀리지 않는 경로·플래그 다름)도 시험할 것 | — | ✅ 1b 를 고침 |
| 최종 run 은 p1 L 기준이라 `gate.ok` 가 참이어야 하고, STABS 허용은 §526 객체 비교에만 | `m4_m68k_status.py:124`(`gate.ok` 단언, 이번 세션 112–132 행을 읽음) | ✅ 관문 문장을 고침 |
| `autoconf_L.c` 는 07 과 import·코드가 같고 줄은 16 행 어긋남(§526 에서도 F = L) | 확인하지 않음 | ⏭️ 확인 run 이 판정 |
| zerofill `objs` 는 STABS 수를 빼고 대조, 후보 [0x40b4f4e, 0x40b4f52) | `m5_m68k_zerofill.py` 머리말(이번 세션 읽음: STABS 수 제외) | ✅ |
| PROVENANCE 행은 `autoconf.c` 1125·`scsivar.h` 1128 | `grep -n` 출력 | ✅ |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 명령입니다.

### 649.4 결과(2026-10-31)

- 1 도구: `m4_m68k_status.py` 202 → 228 행(`dep_headers`: 객체마다 최종 run 의 `-M` 출력(해시를 `output.manifest` 와 대조, 원천이 첫 항목, 모든 경로가 스테이지 매니페스트 키, `-D`·`-I` 가 컴파일 줄과 같음)에 나오는 `m4_headers` 만 검사; 머리말 규칙). 회귀: 지금 07 로 돌린 상태표가 §646 표와 바이트까지 같고 요약 같음. 모의(`m4-m68k-p649-statuscheck-20261031.json`): (i) `scsivar.h` 해시가 다르면 옛 검사 29 기록, 새 검사 §526 기록 하나에서 멈춤; (ii) 38 머리 × 41 기록에서 "멈춤 = 그 머리가 의존 출력에 있음"(따로 짠 파서로 셈) 어긋남 0; (iii) 의존 출력 없음(파일 없음 예외로 멈춤)·해시 틀림·원천이 첫 항목 아님·풀리지 않는 경로·옵션 다름 모두 멈춤.
- 2 07 머리: `nextmach/nextdev/scsivar.h` 55 행 한 줄(scratchpad `gen_p649.py --write`, 바꾸기 전 SHA 단언, 다른 줄 같음 단언), SHA `5ab5020a…` → `92bf1be4…`, 361 행 그대로.
- 3 `stage_m68k.py` 745 → 747 행(`M4FILES[649]`·`EXCEPTS[649]`, 머리말 목록).
- 4 회귀: `m0p649-a1-stage`·`--plan 646` 재생성 `m0p646-r649-stage` 모두 보관 `m0p646-a1-stage` 와 `src/bsd/dev/m68k/scsivar.h` 한 줄만 다르고(키 `files`, 새 스테이지는 `plan` 도) 트리 어긋남 0. `--plan 646 cmd` 가 `m5-646.cmd` 와 같고 `m5-649.cmd` 는 411 줄 모두 계획 번호만 다름. M5 205(run `m3p649-b646`·`m3p649-cc1`): 객체 205 와 다른 출력 모두 같음(`run.json` 만 다름), `compare` 두 기록의 요약이 같고 `differ_unexpected`·`lost` 빔. x86 `m4-x86-inputs-p649-20261031.json` `ok`, `--plan 649 x86gate` 일곱 같음·`v183.34` 경로 0.
- 5 `autoconf` 재수락: 확인 run `m4p649-p1`(`m4-m68k-probe-p649-p1-20261031.json`): 명령 4 개 종료 0·경고 0, F·L 모두 1904 B·L1 사유 `__DATA,__bss: unverified` 하나·`full_span`·`provisional`, F = L(canon·`obj_sig`); F 와 §526 받아들인 객체는 canon·`obj_sig` 의 `header`·`sections`·`symbols` 같고 STABS 만 다름(python). 최종 run `m4p649-a1`(`m4-m68k-p649-final-20261031.json`, SHA `a6a7e8f3…`): `gate.ok`(REF = p1 L). zerofill `objs`(`m4-m68k-zerofill-p649-20261031.json`, REF = §526 객체): ok, 후보 [0x40b4f4e, 0x40b4f52) 로 §526 과 같음. `ACCEPTED` 의 §526 묶음을 §649 묶음으로 바꿈. 상태(`m4-m68k-status-p649-20261031.json`, 두 번 돌려 같음): 표가 §646 표와 `autoconf` 행의 plan·record·obj_sha256 만 다르고 요약 같음(객체 51, 75/188, 71204 B 32.98%, 92978).
- 6 기록: PROVENANCE 1125(`autoconf.c` 재수락)·1128(`scsivar.h`) 행을 고침(행 수 1201 그대로, 일곱 칸), MODIFICATIONS 737 → 738, DECISIONS D149(152 → 153), 근거 `m68k-autoconf.md` 에 plan 649 절(조사 기록과 구분; `m68k-autoconf.diff` 는 §526 판).

- 고침(비밀 정보 검사에서 찾음): 첫 zerofill 기록은 출력 디렉터리를 scratchpad 절대 경로로 줘서 계정 이름이 든 경로가 기록에 들어갔습니다. §560 처럼 `08_build/artifacts/m4p649/zerofill` 로 다시 돌려 기록을 바꿨고(요약·후보 같음, 경로에 계정 이름 0), `ACCEPTED` 의 그 해시를 고친 뒤 상태 도구를 두 번 돌려 표가 앞과 같음을 확인했습니다.

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D149). 이제 `st.c`(§647)는 1997 `scsi_ctrl` 로 진단할 수 있습니다. 남은 진단 전제: `DMA_ALIGN`(1997 공개 머리는 `DMA_BEGINALIGN`), `st_rw` 선언 차례, 1997 `kmem_alloc_wired` 꼴, `stslave` 의 `"%s Rev %s as "`(§647.1).

## 650. M4-156 세부 계획 — m68k `st.c` 진단 A1(1997 `scsi_ctrl` 위; 07 변경 없음; 코딩 전, 2026-10-31)

바탕: §647(사실·머리 공급)과 §647.1(차이 후보), §649(D149, 1997 `scsi_ctrl` 이 든 스테이지 `m0p649-a1-stage`). §647 의 진단 A 는 컴파일되지 않으므로, 컴파일을 막는 셋만 최소로 고친 A1 로 함수별 차이를 봅니다.

확인한 사실(이번 세션; NeXTMach `nextdev/st.c` 를 latin-1 로 읽음, 스테이지 머리):
- 컴파일을 막는 곳: ① `DMA_ALIGN`(NeXTMach `st.c:270–273`; NeXTMach `nextdev/dma.h:36` 의 매크로, `DMA_BEGINALIGNMENT` 4) — 1997 공개 머리 `dev/m68k/dma.h:37` 는 같은 꼴의 `DMA_BEGINALIGN`(`DMA_BEGINALIGNMENT` 16; 원본 `stinit` 의 `-16` 맞춤, §647.1)이고 07 `nextdev/dma.h` 는 `DMA_ALIGN` 을 지움; ② `stslave` 의 `sc_lunmask[target] |= 1 << lun`(230 행) — 2 차원 표(D149)에서는 배열 대입이라 컴파일 오류; 원본은 `[target][lun]` 바이트를 1 늘림(0x408851a–0x408852c); ③ `st_rw` 는 507·513 행에서 선언 없이 불리고 517 행 정의가 `dev_t`(short) 프로토타입 — 원본 0x4088a60 은 이름 없음(정적)이고, NeXTMach 은 `st_mtop`(179 행)처럼 다른 정적 함수에는 선언을 두지만 `st_rw` 에는 없음.

방법(진단; 07 은 바꾸지 않음):
- 변형 A1(scratchpad `p647/st_A1.c` → `08_build/artifacts/m4p650/src/`): §647 의 A 에 위 셋만 — `DMA_ALIGN(` → `DMA_BEGINALIGN(` 네 곳, 230 행 `sdp->sd_scp->sc_lunmask[sdp->sd_target][sdp->sd_lun]++;`, 179 행 뒤에 `static int st_rw(dev_t dev, struct uio *uiop, int rw_flag);`. 진단 머리(`inc`)는 §647 과 같음(`st.h` `NST 2`, NeXTMach `stvar.h`·`screg.h`·`scvar.h`).
- 변형 A2(scratchpad `p647/st_A2.c`): A1 에서 `#import <nextdev/scvar.h>` 를 `<dev/m68k/scsivar.h>` 뒤로 옮긴 것 — `scvar.h:90` 의 `extern struct scsi_ctrl sc_sc[];` 가 `struct scsi_ctrl` 정의 전에 오면 원소 형이 불완전한 배열 선언이라, A1 이 이 때문에 컴파일되지 않을 때를 대비한 대조(§650.1; NeXTMach 의 차례는 A1 과 같음).
- 명세 `08_build/artifacts/m4p650/spec.json`: 바탕 `m0p649-a1-stage`, 객체 `st`(변형 A1·A2), 명시 구간 `{"range": ["0x408844e", "0x4089786"], "rows": [], "partial": ["m68k-253", "m68k-254", "m68k-255"], …}`, `x86_rel` `machdep/i386/dkbad.c`. run `m4p650-p1`(REGISTRY 에 없음), 기록 `m4-m68k-probe-p650-p1-20261031.json`, funcbytes `m4-m68k-funcbytes-p650-<변형>-20261031.json`(이름 없는 21 의 대응은 §647.1 표: `0x408844e=_stgetsdp … 0x4089628=_stcmd`; 결과 객체의 지역 기호 이름으로 확인).
- 측정: 종료 상태·경고(JSON 칸), 함수별 길이·바이트·재배치 대상(길이가 다르면 디스어셈블 비교), 절(`__text` 4920·`__data` 26 목표)·`__data` 내용(재배치 풀어 원본과)·`__cstring`(이 객체 몫을 내용으로), 지역 기호, COMMON·미정의(원본 이름인지; `_st_sd`·`_st_std` 는 UNDF 여야 함), `sizeof(struct scsi_tape_device)`(`stinit` 의 `bzero` 크기, 원본 358).
- 예상 차이(§647.1, 원본 바이트): `stslave`(`"%s Rev %s as "`, 36 자리 끝맺음), `st_rw`·`stioctl`·`st_mtop`(1997 `kmem_alloc_wired(map, &addr, size)` 꼴과 실패 갈래), `st_rw`(SIL 조건). 그 밖은 진단이 가름.

판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고, 다른 함수는 다음 계획에서 원본 바이트로 1997 꼴을 시험합니다. 컴파일이 안 되면 원인을 적고 최소로 고친 꼴로 다시 돌립니다. 바이트로 가려지지 않는 꼴(셋째 고침의 선언 자리 등)은 구현 전에 여쭙니다.

### 650.1 교차검토(codex `gpt-6.1-sol`, task kq7lyn9tm) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A1 은 `scvar.h`(70 행)를 `scsivar.h`(72 행)보다 먼저 들여 `scvar.h:90` `extern struct scsi_ctrl sc_sc[];` 가 불완전한 원소 형의 배열 선언이 됨 — 받아들여질지 미확인 | `p647/inc/nextdev/scvar.h:88–92`, A1 의 import 줄(70·72 행)을 읽음 | ✅ 대조 변형 A2(차례만 바꿈)를 같은 run 에 더함 |
| 남은 `sc_lunmask` 의 옛 쓰임 없음, `kmem_alloc` 은 인자 없는 선언이라 옛 꼴로도 조용히 컴파일됨(원본에 `_kmem_alloc` 도 있어 미정의 검사로 안 잡힘) | 스테이지 `vm/vm_kern.h:66` 은 §647.1 에서 codex 가 인용, 이번에 열지 않음 | ⏭️ 재배치 대상 비교로 봄 |
| 세 고침이 맞음: `DMA_BEGINALIGN` 이 원본 `stinit` 의 더하기(+230·+149·+271·+294)와 `-16` 맞춤을 냄, `++` 는 원본 `addqb #1` 과 같은 효과(앞·뒤 증가는 바이트로 가려지지 않음) | 확인하지 않음(진단이 판정) | ⏭️ |
| 26 함수 가운데 차이 넷 예상(`stslave`·`st_rw`·`stioctl`·`st_mtop`), 나머지 22 는 같을 후보 | — | ⏭️ run 이 판정 |
| `sizeof(struct scsi_tape_device)` 358 은 칸 오프셋까지 봐야 함; `st_sdsw` 는 26 B 를 재배치 풀어 대조; 합쳐진 문자열은 내용·덧붙임으로 | — | ✅ 측정 항목 그대로(§650) |
| 함수 시작 주소와 호출 자리 혼동 주의(0x4088564 는 `stattach` 안, 0x408865a 는 `stopen` 안) | `st.dis` 에서 §647.1 표를 만들 때 이미 그렇게 적음 | ✅ |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄입니다.

### 650.2 결과(run `m4p650-p1`, 2026-10-31)

- 명령 4 개 종료 0·경고 0, 의존 목록 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p650-p1-20261031.json`). A1 과 A2 는 canon·`obj_sig` 까지 같음 — `scvar.h:90` 의 불완전 원소 형 선언은 이 컴파일러에서 문제가 아니었고, A2 는 필요 없었습니다.
- A1: `__text` 4794 B(원본 4920), L1 NOT_MATCH(`__TEXT,__text: unverified`, `__DATA,__data` 의 함수 포인터 다섯이 지역 기호라 unverified). funcbytes 22/26(`m4-m68k-funcbytes-p650-A1-20261031.json`; 정적 21 이름 대응 §647.1): 다른 넷 — `stslave` 234(원본 244), `st_rw` 508(580), `stioctl` 594(610), `st_mtop` 410(438). §650.1 의 예측과 같습니다.
- 원본에서 읽은 넷의 1997 꼴(scratchpad `st.dis`): ① `stslave` — 공백을 걷어낸 뒤 `irp->ir_revision[4]` 를 0 으로(0x40884e8; `inquiry_reply` 의 `ir_revision` +32, 07 `scsireg.h:253`), `printf("%s Rev %s as ", irp->ir_vendorid, irp->ir_revision)`(0x40884f4–0x4088500, 문자열 0x40ab659). ② `st_rw` — `kmem_alloc_wired(kernel_map, &srp, 82)`(지역 fp−4) 가 0 이 아니면 `ENOMEM`, `kmem_alloc_wired(kernel_map, &dmap, iov_len)`(fp−8) 가 0 이 아니면 `kmem_free(kernel_map, srp, 82)` 뒤 `ENOMEM`(0x4088ab4–0x4088b08; 1997 `vm/vm_kern.h:68` `kmem_alloc_wired`), 가변 블록 읽기는 `STF_SIL` 을 보지 않고 `C6OPT_SIL` 을 켬(0x4088b88–0x4088b9e). ③ `stioctl` `MTIOCSRQ` — `kmem_alloc_wired(kernel_map, &ap, sr_dma_max)`(0x4089284–0x40892a6). ④ `st_mtop` — `kmem_alloc_wired(kernel_map, &srp, 82)`(0x4089378–0x4089396).

판정(미리 정한 대로): 07 은 바꾸지 않고, 넷의 1997 꼴을 다음 진단(§651)에서 시험합니다.

## 651. M4-157 세부 계획 — `st.c` 진단 B(1997 꼴 넷; 07 변경 없음; 코딩 전, 2026-10-31)

변형 B(scratchpad `p647/st_B.c` → `08_build/artifacts/m4p651/src/`): A1 에 §650.2 ①–④ 를 넣은 꼴(바뀐 곳마다 `plan 650 diagnostic B` 주석) — `irp->ir_revision[4] = '\0';` 과 `printf("%s Rev %s as ", irp->ir_vendorid, irp->ir_revision);`; `st_rw` 의 `if (kmem_alloc_wired(kernel_map, (vm_offset_t *)&srp, sizeof(*srp)) != KERN_SUCCESS) return(ENOMEM);`·둘째 할당 실패 때 `kmem_free(kernel_map, (vm_offset_t)srp, sizeof(*srp)); return(ENOMEM);`·`if(rw_flag == SR_DMA_RD) cdbp->c6s_opt |= C6OPT_SIL;`; `stioctl` 과 `st_mtop` 의 같은 꼴 할당. 머리·명세·측정은 §650 과 같음(바탕 `m0p649-a1-stage`, 같은 명시 구간·진단 머리), run `m4p651-p1`, 기록 `m4-m68k-probe-p651-p1-20261031.json`, funcbytes `-p651-B-`. 원본에 `_kmem_alloc` 과 `_kmem_alloc_wired` 가 둘 다 있으므로 재배치 대상 이름을 따로 봅니다.

판정(미리 정함; 07 은 바꾸지 않음): 26/26 이고 `__text` 4920·`__data`(`st_sdsw` 26 B, 재배치 풀어 원본과)·`__cstring`(내용) 이 맞으면 구현 계획을 세우고, 바이트로 가려지지 않는 꼴(`&srp` 의 캐스트 유무, `!= KERN_SUCCESS` 표기, `st_rw` 선언 자리 등)은 그 전에 여쭙니다. 다른 함수가 남으면 다음 진단에서 고칩니다.

### 651.1 교차검토(codex `gpt-6.1-sol`, task kx4wix3xk) 판정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| B 의 네 바뀜이 원본의 인자 차례·지역 자리(fp−4·fp−8)·실패 갈래(`u.u_error` 를 건너뜀)와 맞고, 남은 차이는 읽히지 않음 | §650.2 에서 원본 0x40884e8–0x4088500·0x4088ab4–0x4088b9e·0x4089284–0x40892a6·0x4089378–0x4089396 을 읽음 | ⏭️ run 이 판정(계획은 그대로) |
| `&srp` 등은 지역을 스택에 두게 하며 원본도 `fp@(-4)` 에서 다시 읽음 | 원본 0x4088b60·0x4088bbc·0x4088c26(`moveal %fp@(-4),…`) 을 §650.2 에서 읽음 | ✅ |
| `stioctl` 의 `u.u_error` 저장, `st_mtop` 의 `moveaw #22,a2` 는 A1 에서 이미 같음 | A1 funcbytes 는 길이가 달라 그 함수 바이트를 비교하지 않았으므로 확인 못 함 | ⏭️ run 이 판정 |
| `kmem_alloc_wired`·`kmem_free` 는 인자 없는 선언이라 컴파일 성공이 인자 수를 보장하지 않음 | 스테이지 `vm/vm_kern.h:68·71`(이번 세션 읽음) | ✅ 재배치·바이트 비교로 봄 |

계획은 바꾸지 않습니다.

### 651.2 결과(run `m4p651-p1`, 2026-10-31)

- 명령 2 개 종료 0·경고 0, 의존 목록 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p651-p1-20261031.json`).
- **B: OBJECT_MATCH**(L1 사유 없음), `__text` 4920 B, funcbytes **26/26**(`m4-m68k-funcbytes-p651-B-20261031.json`). 절은 `__text` 4920·`__data` 26·`__cstring` 230. `__data`(`_st_sdsw`)는 재배치 여섯(`"st"` 와 정적 함수 다섯)을 원본 자리로 풀면 원본 0x40b2268 의 26 B 와 같음. `__cstring` 230 B 는 원본의 이 객체 몫 [0x40abe34, 0x40abf00) 204 B 의 문자열 여덟(차례까지 같음)에 링크 때 다른 객체의 것과 합쳐진 셋(`"%s Rev %s as "` 0x40ab659·`"ERROR"` 0x40ab775·`"PANIC"` 0x40ab88d, 26 B)을 더한 것(python). 바깥 정의 여섯(`_st_sdsw`·`_stopen`·`_stclose`·`_stread`·`_stwrite`·`_stioctl`), 지역 21(정적 함수), 미정의 20 개 모두 원본에 있고 `_st_sd`·`_st_std` 는 UNDF. COMMON 은 공유 머리의 14 개(`_bfreelist` … `_ttlowat`), 모두 원본 이름(D136).

판정(미리 정한 대로): 구현 계획을 세우기 전에 바이트로 가려지지 않는 꼴을 여쭙니다.

## 652. M4-158 D150 구현 계획 — 07 `src/machdep/m68k/st.c`, NeXTMach 머리 셋, 구성 `st.h`(명시 구간 [0x408844e, 0x4089786), OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(D150 으로 적음): 1997 할당 호출 네 곳은 "캐스트 + `!= KERN_SUCCESS`" — `kmem_alloc_wired(kernel_map, (vm_offset_t *)&지역, 크기) != KERN_SUCCESS`(진단 B 그대로; 07 `kern/mach_clock.c:374` 의 캐스트 꼴, `kern/kalloc.c:201–202` 의 비교 꼴). 앞선 결정 그대로(묻지 않음): NeXTMach 글 + 표시한 1997 바뀜(D013·D024), include OPENSTEP 경로(D104; `<next/cpu.h>` → `<m68k/cpu.h>` D110; `scsireg.h`·`scsivar.h` 는 §526 의 `<dev/m68k/…>` 꼴 D113), NeXTMach 전용 머리는 `07_kernel/nextmach/` 사본(D104), 구성 값은 생성 머리(§612 선례), 공유 머리 COMMON(D136), 1997 `scsi_ctrl`(D149). 바이트가 정한 것: §650.2 ①–④(진단 B 26/26), `DMA_BEGINALIGN`(원본 `stinit` 의 `-16`), `st_rw` 정적.

확인한 사실(이번 세션):
- 07 `src/machdep/m68k/st.c` 와 `07_kernel/nextmach/nextdev/{stvar,screg,scvar}.h` 는 없습니다. NeXTMach 머리 셋(SHA `11e08f74…`·`c20fa6f5…`·`89c60cf4…`; 143·172·95 행)은 바꿀 include 가 없습니다(`scvar.h:24` `<nextdev/sf_access.h>` 는 스테이지 `src/bsd/nextdev/sf_access.h`). 진단 A1 과 A2(차례만 바꿈)가 같아 `scvar.h` 를 들이는 차례는 NeXTMach 그대로 둡니다.
- 구성 `NST`: x86 표(`config_options.tsv`)에 없고, NeXTMach `conf/MASTER.next:88` RELEASE 에 `st`, `:147–148` `st0`·`st1`. 원본은 `_st_std` 자리 716 = 2 × 358·`_st_sd` 160 = 2 × 80, `st_rw` 의 `unit >= NST` 가 `moveq #1; cmpl d1,d5; bges`(0x4088a8a–0x4088a8e; `1 >= unit` 이면 넘어가므로 `unit >= 2` 를 거부)이고, 진단 B(NST 2)가 26/26 — 구성 행은 `confirmed`. 지금 스테이지에서 `st.h` 를 들이는 글은 없습니다.
- 생성 초안(scratchpad `gen_p652.py`, `p652/st.c` 1301 행, `p652/st_L.c`): NeXTMach `st.c`(SHA `81239ef5…` 단언, latin-1 로 읽고 써서 0x80 바이트 하나를 그대로 둠)에 머리 주석 덩이, include 일곱, `st_rw` 정적 선언, `DMA_BEGINALIGN` 넷, `sc_lunmask` 증가, 1997 바뀜 넷(표시 `plan 652`). lexer 로 F·L 토큰·토큰 줄이 같고(L 은 주석을 줄바꿈만 남기고 지운 꼴), F 와 진단 B(§651 기록 `source_sha256` 에 묶음)의 토큰이 같음을 단언합니다.
- 상태 기대(python): 객체 51 + 1 = 52(OBJECT_MATCH 43, CODE+BSS_INFERRED 9), 행 75/188·덮은 바이트 71204(32.98%) 그대로(부분 행 253·254·255 는 `exact` 0), `object_bytes` 92978 + 4920 = 97898, `partial_rows` 에 `m68k-255`.

1. 구성: `06_reconstruction/config_options-m68k.tsv` 에 `st NST st.h 2 confirmed <근거>` 한 행(여섯 칸); `gen_config_headers.py --arch m68k` 로 `07_kernel/v183.34/m68k/generated/st.h`(`#define NST 2`); `--check` 둘(x86·m68k) 종료 0.
2. 07 머리 셋: NeXTMach 사본을 바이트 그대로 `07_kernel/nextmach/nextdev/` 에(`cmp` 같음).
3. 07 `st.c`: `gen_p652.py --write`(이미 있으면 멈춤).
4. `stage_m68k.py`: `M4FILES[652] = list(M4FILES[649]) + ['st.c']`, `M4HEADERS[652] = list(M4HEADERS[639]) + [('nextdev/stvar.h', 'src/bsd/nextdev/stvar.h'), ('nextdev/screg.h', 'src/bsd/nextdev/screg.h'), ('nextdev/scvar.h', 'src/bsd/nextdev/scvar.h')]`, `EXCEPTS[652] = dict(EXCEPTS[649])`, 머리말 목록에 652. (`stage_m68k.py` 줄 번호는 인용 직전에 `grep -n` 으로 다시 뽑음.)
5. 회귀: `--plan 649` 재생성(`m0p649-r652-stage`)은 보관본과 생성 `st.h` 하나만 다름(생성 머리는 모든 m68k 스테이지에 들어감, §612 선례); `--plan 649` 재생성의 차이 키는 `added`·`files`; 새 스테이지 `m0p652-a1-stage` 는 보관본과 `st.c`·머리 셋·생성 `st.h` 와 키 `added`·`files`·`m4_headers`·`m4_sources`·`plan` 만 다름(생성 머리는 덮어쓰기 고리로 들어가 `added` 에 붙음, §612.1); `m5-652.cmd` 는 `m5-649.cmd` 와 계획 번호만 다름; M5 205(run `m3p652-b649`·`m3p652-cc1`) 객체·출력 같음, `compare` `differ_unexpected`·`lost` 빔; x86 `m4_x86_inputs.py s6ln` `ok`·`--plan 652 x86gate` 일곱 같음; 상태 도구(머리 검사는 의존 머리만, D149)가 그대로 통과.
6. 확인 run `m4p652-p1`(바탕 `m0p652-a1-stage`, 객체 `st`, §650 의 명시 구간): F = `@machdep/m68k/st.c`, L = `08_build/artifacts/m4p652/src/st_L.c`. 판정: 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 26/26, F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx`·문자열 표 크기뿐). `-E` run `m4p652-e2`(F·L·B, B 는 §651 의 진단 머리 `inc` 와 함께): `#` 줄 뺀 토큰 F = L = B, stderr 0, i386 0.
7. 최종 run `m4p652-a1`(명세 `08_build/artifacts/m4p652/spec.json`: F 만, `refs` = p1 L 과 SHA): `gate.ok`. 확인 기록 `m4-m68k-p652-checks-20261031.json`: 절 `__text` 4920·`__data` 26·`__cstring` 230; `__data` 는 재배치를 풀어 원본 0x40b2268 의 26 B 와 같음; `__cstring` 은 원본 이 객체 몫 여덟(차례까지)과 합쳐진 공용 셋; funcbytes 26/26(최종 객체 SHA 에 묶음); 바깥 정의 여섯이 원본 주소, 지역 21 이 원본 자리; COMMON·미정의 모두 원본 이름, `_st_sd`·`_st_std` UNDF; 컴파일 줄 = M5 줄; 의존 i386 0·SHA 사슬(생성 `st.h`·머리 셋 포함) 문제 없음; `e2` ok.
8. 상태: 근거 `06_reconstruction/evidence/m68k-st.md` 와 NeXTMach 대비 diff `m68k-st.diff` 를 먼저 쓰고 `ACCEPTED` 에 한 줄; 상태 도구 두 번, 기대는 위 값.
9. 기록: PROVENANCE 다섯 행(`st.c` nextmach+authored — URL·커밋·경로:줄·바뀐 줄; 머리 셋 nextmach; 생성 `st.h` generated), MODIFICATIONS, DECISIONS D150, 계획·HANDOFF·메모리. M7 의무: COMMON 합침, `_st_sd`·`_st_std` 정의(NeXTMach `scsiconf.c:55–56`)와 `scsi_*`·`kmem_*` 는 다른 객체.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, `e2`·확인 기록 `ok`, 최종 funcbytes 26/26, 상태 도구가 멈추지 않음. 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 652.1 교차검토(codex `gpt-6.1-sol`, task kafgjxsyi) 판정과 계획 수정

내가 틀린 것: ① `NST` 근거에서 원본이 "2 와 비교" 한다고 적었지만, 원본은 1 과 비교하고 `bges` 로 `1 >= unit` 일 때 넘어갑니다(곧 `unit >= 2` 를 거부; `st.dis` 0x4088a8a–0x4088a90). ② 새로 쓴 줄 몇 개(`st_rw` 둘째 할당 실패 덩이의 `kmem_free`·`return`·닫는 괄호, 첫 할당의 `return`, `stioctl`·`st_mtop` 할당의 둘째 줄)에 표시가 없었습니다. ③ 생성기 주석이 실제와 다른 토큰 차이를 말했고, 머리 주석이 `st_rw` 선언 자리(이 프로젝트의 선택)를 바이트가 정한 것처럼 읽혔습니다. 모두 고쳤습니다(F 1301 행 — 머리 주석 한 줄 늘어남, 토큰 단언 통과).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `NST` 비교는 1 과 `bges` | `st.dis` 0x4088a8a–0x4088a90 을 다시 읽음 | ✅ 채택(위 ①) |
| 매니페스트 차이 키에 `added` 가 반드시 있음(생성 머리는 덮어쓰기 고리로 `added` 에) | §612.1(`plans/RECONSTRUCTION_PLAN-601-614.md:667`)의 선례 | ✅ 5 단계 문구를 고침(실제 차이는 회귀가 판정) |
| 표시 빠진 줄 | `p652/st.c` 566–573·991–994·1048–1051 행을 읽음 | ✅ 채택(위 ②) |
| 생성기 주석·머리 주석 문구 | `gen_p652.py` 124–128 행을 읽음 | ✅ 채택(위 ③) |
| 머리 셋 SHA·행 수, F 의 0x80 바이트 보존(주석 안), F = B = L 토큰, B 의 26/26·`__data`·문자열·기호 수, 스테이지 경로 충돌 없음, 상태 기대 52·43·9·75·71204·32.98%·97898, 근거 문서 이름 `m68k-st.md` | 이번 세션의 `sha256sum`·`wc`·생성기 단언·§651.2 python | ✅ |
| 구성 행은 탭 여섯 칸, x86 은 `--check`(인자 없음) | §612 선례 | ✅ 그대로 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 명령입니다.

### 652.2 결과(2026-10-31)

- 1 구성: `config_options-m68k.tsv` 19 → 20 행(`st NST st.h 2 confirmed`), `gen_config_headers.py --arch m68k` 로 생성 `st.h`(`#define NST 2`, SHA `686348ee…`); `--check`(m68k·x86) 종료 0. 다른 생성 머리는 내용 그대로(스테이지 회귀).
- 2 07 머리 셋: NeXTMach 사본 `07_kernel/nextmach/nextdev/{stvar,screg,scvar}.h`(`cmp` 같음).
- 3 07 `src/machdep/m68k/st.c` 1301 행, SHA `47a4a294…`(scratchpad `gen_p652.py --write`; NeXTMach SHA·F = L·F = B 토큰 단언; 바뀐 NeXTMach 줄 63–67·71–72·224·230·270–273·546–549·565–566·970–971·1027–1029 은 diff 에서 python 으로 뽑음).
- 4 `stage_m68k.py` 747 → 751 행(`M4FILES[652]`·`M4HEADERS[652]`·`EXCEPTS[652]`·머리말 목록).
- 5 회귀: `--plan 649` 재생성(`m0p649-r652-stage`)은 보관본과 `generated/st.h` 하나(키 `added`·`files`), 새 스테이지 `m0p652-a1-stage`(991 파일)는 그것과 `st.c`·머리 셋(키 `added`·`files`·`m4_headers`·`m4_sources`·`plan`)만 다르고 트리 어긋남 0. `--plan 649 cmd` = `m5-649.cmd`, `m5-652.cmd` 는 411 줄 모두 계획 번호만 다름. M5 205(run `m3p652-b649`·`m3p652-cc1`): 객체 205 와 다른 출력 같음(`run.json` 만 다름), `compare` 요약 차이는 `stage_vs_test_stage` 에 다섯 파일뿐, `differ_unexpected`·`lost` 빔. x86 `m4-x86-inputs-p652-20261031.json` `ok`, `--plan 652 x86gate` 일곱 같음.
- 6 확인 run `m4p652-p1`(`m4-m68k-probe-p652-p1-20261031.json`): 명령 4 개 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 26/26(`-F/L-`), F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx`·크기 칸뿐). `-E` run `m4p652-e2`(`m4-m68k-p652-e2-20261031.json`, `ok`): F = L = B 16063 토큰, stderr 0, i386 0; B 의 진단 머리는 07 사본과 바이트 같음.
- 7 최종 run `m4p652-a1`(`m4-m68k-p652-final-20261031.json`, SHA `da10807a…`): `gate.ok`, 26/26. 확인 `m4-m68k-p652-checks-20261031.json`(`ok` 참): 절 `__text` 4920·`__data` 26·`__cstring` 230, `__data` 는 재배치 여섯을 풀면 원본과 같음, 이 객체 몫 문자열 여덟이 원본과 차례까지 같고 나머지 셋은 합쳐진 공용 문자열, 텍스트 재배치 139, 바깥 정의 여섯·지역 21 이 원본 자리, COMMON 14·미정의 20 모두 원본 이름(`_st_sd`·`_st_std` UNDF), 컴파일 줄 = M5 줄, 의존 119 개 SHA 사슬 문제 없음·i386 0.
- 8 상태(`m4-m68k-status-p652-20261031.json`, 표 52 → 53 행; 두 번 돌려 같음): 객체 52(OBJECT_MATCH 43, CODE+BSS_INFERRED 9), 행 75/188, 71204 B(32.98%), `object_bytes` 97898, `partial_rows` 에 `m68k-255` — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-st.md`, diff `m68k-st.diff`.
- 9 기록: PROVENANCE 1201 → 1206 행(일곱 칸, 경로 겹침 없음: `st.c`·머리 셋·생성 `st.h`), MODIFICATIONS 738 → 741, DECISIONS D150(153 → 154).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D150).

## 653. M4-159 세부 계획 — m68k `sg.c`(행 241, 행 240 일부) 진단 A1·B·B7(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: 1997 `struct scsi_ctrl`(D149)이 들어갔으므로 같은 SCSI 묶음에서 가장 작고 경계가 뚜렷한 `sg.c` 를 먼저 합니다. 끝은 받아들인 `snd_device`(0x407ff14) 시작과 맞닿습니다.

확인한 사실(이번 세션; 원본 풀이 scratchpad `sg.dis` = `scsi_all.dis` 의 [0x407f612, 0x407ff14), 기호표, 수는 python):
- 범위 [0x407f612, 0x407ff14) 2306 B, 이어진 14 항목(`m68k-functions.tsv`). 외부 이름은 `_sgopen` 92·`_sgclose` 116·`_sgioctl` 244 뿐이고 나머지 11 은 이름 없음. NeXTMach mk-108.1 `nextdev/sg.c`(642 행, SHA-256 `6b13a27c…`, ASCII)의 정의 차례 `sggetsdp`(132)·`sgslave`(138)·`sgattach`(154)·`sgattach2`(162)·`sgwake`(172)·`sginit`(179)·`sgopen`(195)·`sgclose`(212)·`sgstart`(231)·`sgintr`(293)·`sgdone`(419)·`sgioctl`(461)·`sgsettl`(513)·`sgcmd`(531) — 14 개 — 과 원본 크기 차례 26·62·24·18·18·104·92·116·220·552·162·244·180·488 이 하나씩 대응합니다. 뒷받침: 호출(0x407f63e·0x407f68a → 0x407f6a6 `sginit`, 0x407f672·0x407f742 → 0x407f682 `sgattach2`, 0x407fa8e → 0x407fae2 `sgdone`, `sgioctl` 의 0x407fbf0 → 0x407fc78 `sgsettl`·0x407fbfe → 0x407fd2c `sgcmd`), `__data` 0x40b20a6 `_sg_sdsw` 26 B = `"sg"`(0x40abaae)·0·0·0x407f612·0x407f62c·0x407f66a·0x407f7de·0x407f8ba(NeXTMach `sg.c:110–119` 의 `sggetsdp`·`sgslave`·`sgattach`·`sgstart`·`sgintr`).
- 행: `span()` 은 `{"range": ["0x407f612", "0x407ff14"], "rows": ["m68k-241"], "partial": ["m68k-240"], …}` 만 받아들입니다(python 으로 넷을 시험: `partial` 에 241 을 넣거나 하나만 두면 멈춤).
- 구성: `sgopen`·`sgclose` 는 `unit > 3` 이면 `ENXIO`(0x407f72c·0x407f786 `moveq #3; cmpl; blts`), `_sg_sd` 는 0x40c6488–0x40c65c8 = 320 B = 4 × 80, `_sg_sgd` 는 0x40c65c8–0x40c66d0(`_st_sd`) = 264 B = 4 × 66(python) → NSG 4. NeXTMach `conf/MASTER.next:153` 은 `sg0` 하나. `sg.h` 를 들이는 07 파일은 없음(grep 0).
- 문자열: 이 객체 몫 [0x40abaae, 0x40abb34) 134 B(`"sg"`·`"Generic SCSI Device as "`·`"sgstart() called with empty sgd_io_q"`·`"sgintr: bad sd_state"`·`"sdintr: bad sgd_state"`·`"sgdone: no buf on sgd_io_q"`)와 다른 객체 것과 합쳐진 셋(`"ERROR"` 0x40ab775·`"PANIC"` 0x40ab88d·`"sdintr: bad sd_state"` 0x40ab80a).
- 원본에서 읽은 NeXTMach 와의 차이(scratchpad `sg.dis`):
  - ① 장치 번호: `sgopen`·`sgclose`·`sgioctl` 이 `minor(dev)` 바이트(`fp@(11)`)를 밀지 않고 그대로 씀 — NeXTMach `sgvar.h:42` `SG_UNIT(dev)` 는 `minor(dev) >> 3`.
  - ② `sginit`: `(sgdp + 24 + 15) & -16`(0x407f6d4–0x407f6dc) = `DMA_BEGINALIGN`(16; NeXTMach `DMA_ALIGN`, 07 `nextdev/dma.h` 에 없음); `bzero` 66 B = `sizeof(struct scsi_generic_device)`(`sgd_erbuf` 26 + 16 − 1 = 41 B, +24).
  - ③ `sgopen`: 이미 열려 있으면 `EBUSY`(16, 0x407f75c; NeXTMach 은 `ENXIO` 와 한 조건), 연 뒤 `sgd_autosense = 0`(0x407f74e).
  - ④ `sgclose`: `sd_target != 0xff` 일 때만 `sc_lunmask[target][lun]` 을 1 줄이고(0x407f7ba `subqb #1`) target·lun 을 −1 로(NeXTMach 은 늘 −1, 표는 건드리지 않음).
  - ⑤ `sgsettl`: `sa_target > 7` 또는 `sa_lun > 7` 이면 `EINVAL`(0x407fc88–0x407fc96, 부호 없는 비교), 쓰던 target·lun 이 있으면 ④ 와 같이 놓아 주고, 새 칸이 0 이 아니면 `suser()` 아니면 `EACCES`, 그 칸을 1 늘림(0x407fd0c `addqb #1`) 뒤 target·lun 대입.
  - ⑥ `sgioctl`: 0x40047307 = `_IOR('s', 7, int)` 갈래가 더 있음 — `*(int *)data = sgd_autosense`(부호 늘림, 0x407fc16–0x407fc1c). 07 판 `<dev/m68k/scsireg.h>`(= NeXTMach `nextdev/scsireg.h` 사본, D113)에는 이 이름(1997 공개 머리의 `SGIOCGAS`)이 없음. case 몸통 자리 차례는 `SGIOCSTL`·`SGIOCREQ`·`SGIOCENAS`·`SGIOCDAS`·이 갈래·`SGIOCRST`·default(0x407fbec·…·0x407fc68).
  - ⑦ `sgcmd`: `kmem_alloc_wired(kernel_map, &ap, sr_dma_max)`(지역 fp−12, 0x407fd66–0x407fd7e; 실패면 `SR_IOST_MEMALL`·`ENOMEM`) — §650.2 ② 와 같은 1997 꼴.
  - 그 밖(`sggetsdp`·`sgslave`·`sgattach`·`sgattach2`·`sgwake`·`sgstart`·`sgintr`·`sgdone`)은 읽은 범위에서 NeXTMach 과 같아 보임(`sgstart` 의 `scsi_rejectcmd` 는 07 `scsivar.h:243` 매크로 꼴: `sd_state = 9` 뒤 `scsi_cintr(sd_scp)`, 0x407f89c–0x407f8a8). `sgcmd` 의 `if(...CHKSV);` 빈 문은 NeXTMach 그대로(원본도 비교 없이 늘 복사, 0x407fec0).

방법(진단; 07 은 바꾸지 않음; 원천 scratchpad `p653/gen_p653.py` 가 NeXTMach 글에서 만듦 → `08_build/artifacts/m4p653/src/`):
- 공통: §652 와 같은 include 줄 바꿈(`next/psl.h`→`m68k/psl.h`, `next/cpu.h`→`m68k/cpu.h`, `next/printf.h`→`kernserv/printf.h`, `nextdev/busvar.h`→`dev/busvar.h`, `nextdev/disk.h`→`dev/disk.h`, `nextdev/scsireg.h`→`dev/m68k/scsireg.h`, `nextdev/scsivar.h`→`dev/m68k/scsivar.h`), `DMA_ALIGN(` → `DMA_BEGINALIGN(`. 진단 머리(`inc`): `sg.h`(`#define NSG 4`), `nextdev/sgvar.h`. `screg.h`·`scvar.h` 는 바탕 스테이지의 07 사본(§652).
- 변형 A1: 위에 더해 컴파일을 막는 `sgsettl` 의 `sc_lunmask[target] & (1 << lun)` 만 `sc_lunmask[target][lun]` 로; `sgvar.h` 는 NeXTMach 사본 그대로.
- 변형 B: A1 에 ①–⑦ — `sgvar.h` 의 `SG_UNIT(dev)` 를 `minor(dev)` 로(진단 사본), ③·④·⑤ 의 꼴, ⑥ 은 `case SGIOCGAS:`(파일 안 `#define SGIOCGAS _IOR('s', 7, int)`; 진단용), ⑦ 은 D150 과 같은 `kmem_alloc_wired(kernel_map, (vm_offset_t *)&ap, srp->sr_dma_max) != KERN_SUCCESS`, ⑤ 의 한계는 `>= SCSI_NTARGETS`·`>= SCSI_NLUNS`(07 `scsireg.h:321–322`, 8). 바뀐 곳마다 `plan 653 diagnostic B` 주석.
- 변형 B7: B 에서 ⑤ 의 한계만 숫자 `> 7` 로(바이트로 가려지는지 보는 대조).
- 명세 `08_build/artifacts/m4p653/spec.json`: 바탕 `08_build/runs/tools/m0p652-a1-stage`, 객체 `sg`, 위 명시 구간, `x86_rel` `machdep/i386/dkbad.c`. run `m4p653-p1`(REGISTRY 에 없음), 기록 `m4-m68k-probe-p653-p1-20261031.json`, funcbytes `m4-m68k-funcbytes-p653-<변형>-20261031.json`(이름 없는 11 의 대응: 0x407f612 `_sggetsdp`, 0x407f62c `_sgslave`, 0x407f66a `_sgattach`, 0x407f682 `_sgattach2`, 0x407f694 `_sgwake`, 0x407f6a6 `_sginit`, 0x407f7de `_sgstart`, 0x407f8ba `_sgintr`, 0x407fae2 `_sgdone`, 0x407fc78 `_sgsettl`, 0x407fd2c `_sgcmd`).
- 측정: 종료 상태·경고, 함수별 길이·바이트·재배치 대상, 절(`__text` 2306·`__data` 26 목표)·`__data`(재배치 풀어 원본 0x40b20a6 과)·`__cstring`(이 객체 몫 134 B 를 내용과 차례로), 지역 기호, COMMON·미정의(원본 이름인지; `_sg_sd`·`_sg_sgd`·`_scsi_ndevices` 는 UNDF 여야 함), `sizeof(struct scsi_generic_device)` 66.
- 예상: A1 은 ①·③–⑦ 이 걸린 `sgopen`·`sgclose`·`sgioctl`·`sgsettl`·`sgcmd` 다섯이 다르고 나머지 아홉이 같음; B·B7 은 14/14 이고 서로 바이트가 같음.

판정(미리 정함; 07 은 바꾸지 않음): B 가 14/14 이고 `__text`·`__data`·`__cstring` 이 맞으면 구현 계획을 세우되, 바이트로 가려지지 않는 꼴(① 을 머리에서 고칠지 파일에서 `minor(dev)` 로 쓸지, ⑥ 의 이름을 07 공유 `scsireg.h` 에 더할지 파일 안에 둘지, ⑤ 의 한계 표기, ⑦ 의 꼴, ④·⑤ 의 같은 풀어 주기 글을 두 번 쓸지)은 그 전에 여쭙니다. 다른 함수가 남으면 다음 진단에서 고칩니다. 컴파일이 안 되면 원인을 적고 최소로 고친 꼴로 다시 돌립니다.

### 653.1 교차검토(codex `gpt-6.1-sol`, task kjcpnn9xy) 판정과 계획 수정

먼저 제 잘못: 처음 쓴 인용 둘이 틀렸습니다(`sg.c:111–120` → `110–119`, `sgvar.h:44` → `42`). 쓴 뒤 python 으로 줄을 열어 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 14 대응과 이름 없는 11 의 이름이 맞음 | `m68k-functions.tsv` 의 14 항목 크기(python), `sg.dis` 의 호출 여섯과 `_sg_sdsw` 26 B(python 으로 Mach-O 에서 읽음) | ✅ |
| ①–⑤·⑦ 이 맞음(⑤ 는 놓아 준 뒤 `EACCES` 가 나는 차례까지) | `sg.dis` 0x407f716·0x407f770·0x407fb94, 0x407f6c6–0x407f6dc, 0x407f72c–0x407f75c, 0x407f79a–0x407f7ce, 0x407fc88–0x407fd18, 0x407fd66–0x407fd88 을 이번 세션에 읽음 | ✅ |
| ⑥ 의 부호화·몸통 자리는 맞으나 매크로 이름과 소스 case 차례를 증명하지 않음 | 0x407fbe2·0x407fc16–0x407fc1c 읽음 | ⚖️ 이름은 바이트로 가려지지 않는 꼴로 둠(구현 전에 여쭘); case 차례는 진단 B 가 판정 |
| `sgintr` 두 switch 에 빠진 차이 없음 | 점프 표 0x407f912 아홉 목적지와 0x407fa3a–0x407fab2 를 07 `scsivar.h:149–159`·`scsireg.h:435–453` 값과 대조 | ✅ |
| 문자열: 134 B 는 이 객체만의 덩어리이고 합쳐진 셋까지 NUL 포함 167 B | python(134 + 셋의 길이 + NUL) = 167 | ✅ 측정에 두 수를 따로 적음 |
| B 는 컴파일될 것: `minor()` 는 `_NEXT_SOURCE` 아래, 명령에 `-D_NEXT_SOURCE` 가 있음 | 스테이지 `sys/types.h:73–84`, `m4p652/final.cmd` 에서 `-D_NEXT_SOURCE` grep | ✅ (`KERN_SUCCESS` 는 같은 꼴의 st 진단 B 가 이미 컴파일됨, §651.2) |
| A1 의 고침은 진단용으로만 맞음, A1 예측(다섯 다름)은 run 이 판정 | — | ⏭️ |
| funcbytes·probe compare 는 기대값으로 실패하지 않으므로 관문을 따로 단언할 것 | 이전 단위(§651.2)에서도 절·`__data`·`__cstring` 을 따로 셈 | ✅ scratchpad `p653/chk_p653.py` 가 B·B7 에 대해 14/14·객체에만 있는 함수 없음·`__data` 26 B(재배치 풀어)·`__cstring` 문자열 아홉(134 + 33 B)·UNDF `_sg_sd`·`_sg_sgd`·`_scsi_ndevices` 를 단언 |
| `sg.dis` 2306 B 가 Mach-O 바이트와 같음 | python 으로 대조: 처음엔 이어진 줄(0x407f87a)을 놓쳐 둘이 비었으나 정규식을 고쳐 0 불일치 | ✅ |

2차 자기검사: ✅ 행의 근거는 모두 이번 세션에 연 줄·돌린 python 입니다. 계획의 방법은 그대로 두고 측정 단언 스크립트만 더합니다.

### 653.2 결과(run `m4p653-p1`, 2026-10-31)

- 명령 6 개 종료 0·경고 0, 의존 목록 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p653-p1-20261031.json`). B 와 B7 은 canon·`obj_sig` 까지 같음 — ⑤ 의 한계 표기(`>= SCSI_NTARGETS` 와 `> 7`)는 바이트로 가려지지 않습니다.
- A1: `__text` 2134 B(원본 2306), funcbytes 9/14(`m4-m68k-funcbytes-p653-A1-20261031.json`) — 다른 다섯은 예측대로 `sgopen` 84(원본 92)·`sgclose` 80(116)·`sgioctl` 232(244)·`sgsettl` 84(180)·`sgcmd` 468(488).
- B: `__text` 2306 B, 자리 0x407f612 에 놓임(`full_span`), funcbytes 12/14(`-p653-B-`). 다른 둘은 길이가 같고 바이트 하나씩: `sgclose` +0x38(0x407f7a2)·`sgsettl` +0x2c(0x407fca4). 둘 다 `cmpib #-1,%d0` 의 즉치 확장 낱말이 원본 `ffff`, B `00ff` 입니다(scratchpad `p653/sgB.dis`, `objdis.py` 로 풂). 같은 함수 `sgcmd` 의 NeXTMach `sd_target == 0xff`(0x407fd40, 메모리 비교)는 원본도 `00ff` 이고 B 와 같습니다.
- 원본 전체 `__text` 에서 `cmpi.b` 의 확장 낱말이 `ffff` 인 곳은 넷뿐(python): `_vfs_getnum` 0x401759a, `_od_spiral` 0x4079814, 위 둘. `_vfs_getnum` 은 07 `bsd/kern/vfs.c:1050` `if (*mp != (char)0xff)`(`char *mp`) — 부호 있는 바이트를 −1 과 견주는 꼴이 `ffff` 를 냅니다(이 객체는 M5 에서 바이트까지 같음). 한편 원본 두 곳은 견준 뒤 같은 값을 `andil #255` 로 넓혀 첨자로 씀(부호 없는 `sd_target`).

판정(미리 정한 대로): 07 은 바꾸지 않고, 비교 꼴을 다음 진단(§654)에서 가립니다.

## 654. M4-160 세부 계획 — `sg.c` 진단 C1·C3(풀어 주기 비교 꼴; 07 변경 없음; 코딩 전, 2026-10-31)

변형(모두 B 에서 ④·⑤ 의 풀어 주기 머리 줄 두 곳만 바꿈; 머리·명세·측정은 §653 과 같음, 변형마다 `incB`):
- C1: `if ((char)sgdp->sgd_sdp->sd_target != -1) {` — 부호 있는 바이트로 바꿔 −1 과 견줌(`vfs.c:1050` 과 같은 RTL 갈래 예상).
- C3: `{ char target = sgdp->sgd_sdp->sd_target; if (target != -1) { … } }` 처럼 `char` 지역에 받아 견줌(첨자는 그대로 `sd_target`).
- 생성 scratchpad `p653/gen_p654.py`(B 원천의 SHA 를 단언하고 두 곳을 정확히 한 번씩 바꿈) → `08_build/artifacts/m4p654/src/`. 명세 `08_build/artifacts/m4p654/spec.json`(바탕 `m0p652-a1-stage`, §653 의 명시 구간), run `m4p654-p1`(REGISTRY 에 없음), 기록 `m4-m68k-probe-p654-p1-20261031.json`, funcbytes `-p654-<변형>-`.

판정(미리 정함; 07 은 바꾸지 않음): 14/14 인 변형이 있으면 그 꼴로 `__data`·`__cstring`·기호 단언(§653.1 의 `chk_p653.py`)을 돌리고, 둘 다 14/14 이면 둘이 같은지 적고 구현 전에 여쭙니다(바이트로 가려지지 않는 꼴들과 함께). 둘 다 아니면 원인을 적고 다음 꼴을 계획합니다.

### 654.1 교차검토(codex `gpt-6.1-sol`, task khwtcv4ie) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 풀어 쓴 `#-1` 은 두 부호화 모두에 같게 찍히므로 증거는 확장 낱말뿐 | `sg.dis:139·518` 과 `p653/sgB.dis` 의 같은 자리(둘 다 `cmpib #-1,%d0`, 낱말 `ffff`/`00ff`) | ✅ §653.2 도 낱말로 적음 |
| 어느 GCC 단계(`shorten_compare`·`simplify_comparison`·`print_operand`)인지는 cc-744.13 소스 없이 단정 못 함 | 단정하지 않음 | ✅ 계획에 단계 이름을 쓰지 않음 |
| C1 이 원본 차례를 낼 강한 후보; 이 컴파일러는 `char` 가 부호 있음 | `m0-abi-m68k-20261009.json:939` `"char_is_signed": 1` | ✅ |
| C3 도 같은 바이트를 낼 것(최적화로 지역이 사라짐) | — | ⏭️ run 이 판정 |
| `(signed char)t != -1`·`(char)t != (char)0xff` 도 같은 후보; `t != (u_char)-1` 은 B 와 같은 `00ff` 쪽; 캐스트 없는 `t != -1`·`~0`·`t + 1 != 0` 은 늘 참이라 안 맞음 | `types.h:88` `u_char` = `unsigned char`, B `sg_B.c:228`·`:566` | ⚖️ 사실관계는 받음; `(signed char)` 는 이 컴파일러에서 `char` 와 같은 형이라 따로 돌리지 않고, 둘 이상 맞으면 여쭐 때 선택지로 둠 |
| `_od_spiral` 0x4079814 `0c14 ffff` 는 NeXTMach `od.c:4541` `d->d_spiral_time == KT_BUSY`(`char`, `od.c:400`; `KT_BUSY` −1, `od.c:450`) | 원본을 objdump 로 풀고(0x40797f2–0x407985c) `od.c` 세 줄을 읽음 | ✅ 두 번째 직접 증거로 적음 |
| `-S` 출력·RTL 덤프를 남길 것 | 이 단위의 판정 기준은 바이트(funcbytes)이고 probe 도구는 `-S` 를 내지 않음 | ❌ 계획에 넣지 않음(바이트 비교로 충분) |
| 맞는 꼴은 바이트 호환이지 원래 철자의 증명이 아님 | — | ✅ 구현 전 질문에 그대로 적음 |

2차 자기검사: ✅ 행은 이번 세션에 연 줄·풀어 본 바이트입니다. 계획은 그대로 둡니다.

### 654.2 결과(run `m4p654-p1`, 2026-10-31)

- 명령 4 개 종료 0·경고 0, 의존 목록 i386 0, 원본에 없는 미정의 0(`m4-m68k-probe-p654-p1-20261031.json`).
- **C1·C3 모두 OBJECT_MATCH**(L1 사유 없음, `full_span`, `candidate`), funcbytes **14/14**(`m4-m68k-funcbytes-p654-C1/C3-20261031.json`). 둘은 canon 이 같고 `obj_sig` 만 다름(C3 의 지역 `target` 디버그 기호). 비교 자리는 둘 다 원본처럼 `0c00 ffff` 입니다.
- 단언(scratchpad `p653/chk_p653.py`; 기록 `m4-m68k-p654-diagchecks-20261031.json`, C1·C3 모두 `ok`): 절 `__text` 2306·`__data` 26·`__cstring` 167; `__data` 는 재배치 여섯(`"sg"` 0x40abaae 와 정적 함수 다섯 0x407f612·0x407f62c·0x407f66a·0x407f7de·0x407f8ba)을 풀면 원본 0x40b20a6 의 26 B 와 같음; `__cstring` 문자열 아홉 = 원본 이 객체 몫 여섯(차례까지 같음) + 합쳐진 셋(`"ERROR"`·`"PANIC"`·`"sdintr: bad sd_state"`); 바깥 정의 넷(`_sg_sdsw`·`_sgopen`·`_sgclose`·`_sgioctl`)과 지역 11 이 원본 자리; COMMON 14(공유 머리, 모두 원본 이름, D136); 미정의 23 모두 원본 이름이고 `_sg_sd`·`_sg_sgd`·`_scsi_ndevices` 는 UNDF.

판정(미리 정한 대로): 구현 계획 전에 바이트로 가려지지 않는 꼴을 여쭙니다 — ① `SG_UNIT` 을 07 `sgvar.h` 사본에서 고칠지 `sg.c` 에서 `minor(dev)` 로 쓸지, ⑥ `SGIOCGAS` 를 파일 안에 둘지 07 공유 `scsireg.h` 에 더할지, 풀어 주기 비교 꼴(C1·C3, 바이트 같음), ⑤ 의 한계 표기(B·B7, 바이트 같음). ⑦ 은 D150 과 같은 꼴(캐스트 + `!= KERN_SUCCESS`)을 따릅니다.

## 655. M4-161 D151 구현 계획 — 07 `src/machdep/m68k/sg.c`, `sgvar.h` 사본, 구성 `sg.h`(명시 구간 [0x407f612, 0x407ff14), OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(D151 로 적음, AskUserQuestion 넷 모두 추천안): ① `SG_UNIT(dev)` 는 새 07 `nextmach/nextdev/sgvar.h`(NeXTMach 사본)에서 `minor(dev)` 로 고치고 `sg.c` 는 NeXTMach 의 `SG_UNIT(dev)` 그대로 ② `SGIOCGAS` 는 `sg.c` 안 `#ifndef SGIOCGAS` / `#define SGIOCGAS _IOR( 's', 7, int)`(공유 `scsireg.h` 는 그대로) ③ 풀어 주기 비교는 C1 `(char)sgdp->sgd_sdp->sd_target != -1`(`sgclose`·`sgsettl` 두 곳에 같은 글) ④ 한계는 `>= SCSI_NTARGETS`·`>= SCSI_NLUNS`. 앞선 결정 그대로(묻지 않음): NeXTMach 글 + 표시한 1997 바뀜(D013·D024), include OPENSTEP 경로(D104·D110·D113, §652 와 같은 일곱), NeXTMach 전용 머리는 `07_kernel/nextmach/` 사본(D104), 구성 값은 생성 머리(§612·§652 선례), 공유 머리 COMMON(D136), 1997 `scsi_ctrl`(D149), 할당 꼴은 D150 과 같음(캐스트 + `!= KERN_SUCCESS`). 바이트가 정한 것: §653 ①–⑦ 과 §654 의 부호 있는 비교(진단 C1 14/14).

확인한 사실(이번 세션): 07 `src/machdep/m68k/sg.c`·`nextmach/nextdev/sgvar.h`·`v183.34/m68k/generated/sg.h` 는 없고, 스테이지 `m0p652-a1-stage` 에 `sg.c`·`sg.h`·`sgvar.h` 이름의 파일도 없습니다. 구성 `NSG`: x86 표에 없음, NeXTMach `MASTER.next:88` RELEASE 에 `sg`·`:153` `sg0`; 원본 `_sg_sd` 320 = 4 × 80·`_sg_sgd` 264 = 4 × 66, `sgopen`·`sgclose` 가 `unit > 3` 을 거부; 진단 C1(NSG 4) 14/14 → `confirmed`. 상태 기대(python): 객체 52 + 1 = 53(OBJECT_MATCH 44, CODE+BSS_INFERRED 9), 행 75 + 1 = 76/188(행 241 은 `rows`, `exact` 0 이지만 범위 안에 통째로 듦), 덮은 바이트 71204 + 2054(행 241 `bytes_min`) = 73258(33.94%), `object_bytes` 97898 + 2306 = 100204, `partial_rows` 에 `m68k-240`.

1. 구성: `config_options-m68k.tsv` 에 `sg NSG sg.h 4 confirmed <근거>` 한 행(여섯 칸, 20 → 21 행); `gen_config_headers.py --arch m68k` 로 `generated/sg.h`(`#define NSG 4`); `--check` 둘(x86·m68k) 종료 0.
2. 07 `nextmach/nextdev/sgvar.h`: NeXTMach 사본에서 42 행 `SG_UNIT` 만 `minor(dev)` 로(표시 `plan 655 (D151)`); 다른 줄은 바이트 그대로(python 으로 한 줄 차이 단언). 진단 `incB/nextdev/sgvar.h` 와 토큰이 같음을 단언.
3. 07 `sg.c`: scratchpad `p653/gen_p655.py --write`(이미 있으면 멈춤) — NeXTMach `sg.c`(SHA `6b13a27c…` 단언)에 머리 주석 덩이(바뀜 목록, 바이트가 정하지 않은 꼴 ②–④ 는 이 프로젝트의 선택이라고 적음), include 일곱, `DMA_BEGINALIGN`, §653 ③–⑦·§654 C1(바뀐·더한 줄마다 `plan 655` 표시). lexer 로 F 와 진단 C1(§654 기록의 `source_sha256` 에 묶음) 토큰이 같고, L(주석을 줄바꿈만 남기고 지운 꼴, `08_build/artifacts/m4p655/src/sg_L.c`)과 F 의 토큰·토큰 줄이 같음을 단언.
4. `stage_m68k.py`: `M4FILES[655] = list(M4FILES[652]) + ['sg.c']`, `M4HEADERS[655] = list(M4HEADERS[652]) + [('nextdev/sgvar.h', 'src/bsd/nextdev/sgvar.h')]`, `EXCEPTS[655] = dict(EXCEPTS[652])`, 머리말 목록에 655(줄 번호는 인용 직전에 다시 뽑음).
5. 회귀: `--plan 652` 재생성(`m0p652-r655-stage`)은 보관본과 생성 `sg.h` 하나만 다름(키 `added`·`files`); 새 스테이지 `m0p655-a1-stage` 는 그것과 `sg.c`·`sgvar.h`(키 `added`·`files`·`m4_headers`·`m4_sources`·`plan`)만 다르고 트리 어긋남 0; `m5-655.cmd` 는 `m5-652.cmd` 와 계획 번호만 다름; M5 205(run `m3p655-b652`·`m3p655-cc1`) 객체·출력 같음, `compare` `differ_unexpected`·`lost` 빔; x86 `m4_x86_inputs.py s6ln` `ok`·`--plan 655 x86gate` 일곱 같음.
6. 확인 run `m4p655-p1`(바탕 `m0p655-a1-stage`, 객체 `sg`, §653 의 명시 구간): F = `@machdep/m68k/sg.c`, L. 판정: 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 14/14, F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx`·크기뿐). `-E` run `m4p655-e2`(F·L·C1, C1 은 §654 의 진단 머리와 함께): `#` 줄 뺀 토큰 F = L = C1, stderr 0, i386 0.
7. 최종 run `m4p655-a1`(F 만, `refs` = p1 L 과 SHA): `gate.ok`. 확인 기록 `m4-m68k-p655-checks-20261031.json`: `chk_p653.py` 의 단언 전부(절·`__data`·`__cstring`·기호·UNDF·funcbytes 14/14 를 최종 객체 SHA 에 묶음) + 컴파일 줄 = M5 줄, 의존 i386 0·SHA 사슬(생성 `sg.h`·`sgvar.h` 포함), `e2` ok.
8. 상태: 근거 `06_reconstruction/evidence/m68k-sg.md` 와 diff `m68k-sg.diff`·`m68k-sgvar_h.diff` 를 먼저 쓰고 `ACCEPTED` 에 한 줄; 상태 도구 두 번, 기대는 위 값.
9. 기록: PROVENANCE 세 행(`sg.c` nextmach+authored — URL·커밋·경로:줄·바뀐 줄; `sgvar.h` nextmach+authored; 생성 `sg.h` generated), MODIFICATIONS, DECISIONS D151, 계획·HANDOFF·메모리. M7 의무: COMMON 합침, `_sg_sd`·`_sg_sgd` 정의(NeXTMach `scsiconf.c:67–68`)와 `scsi_*`·`kmem_*`·`suser` 등은 다른 객체.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, `e2`·확인 기록 `ok`, 최종 funcbytes 14/14, 상태 도구가 멈추지 않음. 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 655.1 교차검토(codex `gpt-6.1-sol`, task kg7fkv73g) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 6 단계 `-E` 에서 C1 의 진단 머리는 기존 `-I` 뒤에 붙어(`m4_m68k_probe.py:222–224`) 새 스테이지의 `sg.h`·`sgvar.h` 에 가려짐 | 그 줄을 읽음 | ⚖️ 사실. `-E` 의 F = L = C1 은 `sg.c` 글의 같음만 보이므로, 머리의 같음은 2 단계에서 07 `sgvar.h` 와 진단 `incB/nextdev/sgvar.h` 의 토큰 같음(python)으로 따로 단언하고 기록에 적습니다(§652 의 B 와 같은 처지) |
| 4 단계 경로·키 조회가 맞고 충돌 없음 | `stage_m68k.py:560–587` 을 읽음(`known` 은 모든 계획 `M4FILES` 의 합) | ✅ |
| 구성 행은 탭 여섯 칸, x86 짝 없음 | §652 선례(`config_options-m68k.tsv` 20 행) | ✅ |
| 행 241 은 `exact` 0 이어도 명시 구간 안이라 덮인 행, 2054 B 더함 | `m4_m68k_probe.py:158–178`(이번 세션 python 으로 `span()` 시험), `m4_m68k_status.py:195–212` 읽음 | ✅ |
| 기대 53·44·9·76·73258·33.94%·100204 | python(§655 앞에서 계산) | ✅ |
| 옛 스테이지에는 생성 `sg.h` 만 들어감; 이를 들이는 파일 없음 | `stage_m68k.py:560·579`, §655 의 grep 0 | ✅ M5 회귀로 다시 봄 |
| C1 의 `#ifndef SGIOCGAS` 덩이와 `SG_UNIT(dev) minor(dev)` 를 토큰까지 같게 둘 것; 진단 머리는 NeXTMach 와 42 행만 다름 | `sg_C1.c:49–51`, `diff` NeXTMach `sgvar.h` 대 `incB` 사본(42 행 하나) | ✅ |
| 주석 지우기는 문자열을 알고 겹치지 않게(18 행의 `/*` 가 든 주석); 빈 `if(...);` 를 둠 | `sg_C1.c:18` 읽음; §652 의 lexer·`strip_comments` 를 그대로 씀 | ✅ |
| 산출물 이름을 적을 것(특히 `08_build/artifacts/m4p655/spec.json` — 상태 도구가 읽음) | `m4_m68k_status.py:152` | ✅ 아래에 적음 |
| PROVENANCE 종류와 인용(`scsiconf.c:67–68`·`MASTER.next:88,153`·`sgvar.h:42`)이 맞음 | 이번 세션에 그 줄을 읽음 | ✅ |
| 머리 주석에 ①(머리에서 고친 자리)과 D150 할당 꼴도 이 프로젝트의 선택이라고 적을 것 | — | ✅ 채택 |

계획 수정: 산출물 — 명세 `08_build/artifacts/m4p655/spec.json`, 확인 기록 `m4-m68k-probe-p655-p1-20261031.json`·funcbytes `m4-m68k-funcbytes-p655-F/L-20261031.json`, `-E` 기록 `m4-m68k-p655-e2-20261031.json`, 최종 `m4-m68k-p655-final-20261031.json`·funcbytes `-p655-a1-`·확인 `m4-m68k-p655-checks-20261031.json`, 상태 `m4-m68k-status-p655-20261031.json`. 머리 주석은 ①–④ 와 할당 꼴을 이 프로젝트의 선택(바이트 호환이지 원래 철자의 증명이 아님)으로 적습니다.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·돌린 python 입니다.

### 655.2 결과(2026-10-31)

- 1 구성: `config_options-m68k.tsv` 20 → 21 행(`sg NSG sg.h 4 confirmed`), `gen_config_headers.py --arch m68k` 로 생성 `sg.h`(`#define NSG 4`, SHA `4bf61838…`); 다른 생성 머리는 스테이지 `m0p652-a1-stage` 와 바이트 같음; `--check`(m68k·x86) 종료 0.
- 2 07 `nextmach/nextdev/sgvar.h`(SHA `eace5073…`, 62 행): NeXTMach 와 42 행 하나만 다르고 진단 `incB` 사본과 토큰이 같음(python 단언).
- 3 07 `src/machdep/m68k/sg.c` 684 행, SHA `550bc343…`(scratchpad `p653/gen_p655.py --write`; NeXTMach SHA·F = C1 토큰·F = L 토큰과 토큰 줄·표시 없는 바뀐 줄 0 단언). L 은 `08_build/artifacts/m4p655/src/sg_L.c`. 바뀐 NeXTMach 줄은 diff 에서 python 으로 뽑음(35–39·43–44·185·202–203·222–223·519–520·557–558, 넣은 자리 17·48·204·206·495·516·524 뒤).
- 4 `stage_m68k.py` 751 → 754 행(`M4FILES[655]`·`M4HEADERS[655]`·`EXCEPTS[655]`·머리말 목록).
- 5 회귀: `--plan 652` 재생성(`m0p652-r655-stage`, 992 파일)은 보관본과 생성 `sg.h` 하나(키 `added`·`files`), 새 스테이지 `m0p655-a1-stage`(994 파일)는 그것과 `sg.c`·`sgvar.h`(키 `files`·`m4_headers`·`m4_sources`·`plan`)만 다르고 두 트리 모두 매니페스트와 어긋남 0. `m5-652.cmd` 는 보관본과 같고 `m5-655.cmd` 는 411 줄 모두 계획 번호만 다름. M5 205(run `m3p655-b652`·`m3p655-cc1`): 객체 205 와 다른 출력 같음(`run.json` 만 다름), `compare` 둘의 `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 `sg.c`·`sgvar.h` 뿐(§652 기록과는 `generated/sg.h` 만 더함). x86 `m4-x86-inputs-p655-20261031.json` `ok`, `--plan 655 x86gate` 일곱 같음.
- 6 확인 run `m4p655-p1`(`m4-m68k-probe-p655-p1-20261031.json`; 명세 `08_build/artifacts/m4p655/spec-p1.json`): 명령 4 개 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, 14/14(`-F/L-`), F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx` 뿐 — 문자열 표 크기도 같음). `-E` run `m4p655-e2`(`m4-m68k-p655-e2-20261031.json`, `ok`): F = L = C1 12876 토큰, stderr 0(`_log` 셋), i386 0. (처음 만든 `-E` 명령 파일에 `EXPECT` 줄이 없어 `kr_run prepare` 가 거부함 — run ID 는 등록되지 않았고 `EXPECT` 셋을 더해 같은 ID 로 돌림; 처음 쓴 e2 기록은 stderr 를 `_log` 에서 찾지 못해 `ok` 거짓이었고, 같은 기록을 `_log` 의 크기로 고쳐 씀.)
- 7 최종 run `m4p655-a1`(`m4-m68k-p655-final-20261031.json`, SHA `df54374b…`): `gate.ok`, 14/14(`-p655-a1-`). 확인 `m4-m68k-p655-checks-20261031.json`(`ok` 참; scratchpad `p653/checks_p655.py`): 절 `__text` 2306·`__data` 26·`__cstring` 167, `__data` 는 재배치 여섯을 풀면 원본과 같음, 이 객체 몫 문자열 여섯이 원본과 차례까지 같고 나머지 셋은 합쳐진 공용 문자열, 텍스트 재배치 73, 바깥 정의 넷·지역 11 이 원본 자리, COMMON 14·미정의 23 모두 원본 이름(`_sg_sd`·`_sg_sgd`·`_scsi_ndevices` UNDF), 컴파일 줄 = M5 줄, 의존 116 개 SHA 사슬 문제 없음·i386 0. 객체 SHA `baa32bf0…`.
- 8 상태(`m4-m68k-status-p655-20261031.json`, 표 54 → 55 행; 두 번 돌려 같음): 객체 53(OBJECT_MATCH 44, CODE+BSS_INFERRED 9), 행 76/188, 73258 B(33.94%), `object_bytes` 100204, `partial_rows` 에 `m68k-240` — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-sg.md`, diff `m68k-sg.diff`·`m68k-sgvar_h.diff`.
- 9 기록: PROVENANCE 1206 → 1209 행(일곱 칸, 경로 겹침 없음: `sg.c`·`sgvar.h`·생성 `sg.h`), MODIFICATIONS 741 → 744, DECISIONS D151(154 → 155).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D151).
