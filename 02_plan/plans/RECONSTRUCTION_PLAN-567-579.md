# 커널 소스 복원 작업계획 — 보관 §567–579

`02_plan/RECONSTRUCTION_PLAN.md` 의 §567–579(m68k M4 floppy: `fd_subr`·`fd_vars.h`·Darwin `fd_extern.h`·`fd.h`(D128), `fd_io`·`odreg.h`·`sc.h`(D129), `fd_driver`(D130), `fd_cmds`(D131))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-30, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 567. M4-73 세부 계획 — m68k `fd_subr.c`(행 222) NeXTMach 글 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): 사운드 다음 후보 `snd_link`(행 246 나머지 [0x40842fe, 0x408503e) 3392 B)는 1997 판이 NeXTMach 과 크게 다름 — 원본에 새 `_snd_link_abort`(14 B), 외부 `_snd_link_snd_complete`, `__data` 의 libDriver 오디오 고리 변수(`___NXAudioInitLinkedStream`·`___NXAudioPlayStream` 등) 간접 호출, `snd_get_owner`·`_sound_active`·새 문자열 둘이 있고, 참고 트리(NeXTMach·Darwin 0.1·07)에 이 꼴의 글이 없음(`snd_link*` 파일은 NeXTMach 하나, `NXAudioInitLinkedStream` 은 어디에도 없음; grep). 본문 대부분을 원본 바이트로 새로 써야 하므로 뒤로 미루고, 받아들이지 않은 행 가운데 정확 경계이고 NeXTMach 이름이 모두 맞는(29/29) `fd_subr.c`(행 222, 6728 B; 받아들이면 덮은 행이 하나 늘어남)를 먼저 봅니다. 같은 floppy 묶음(`fd_driver` 220·`fd_io` 221·`fd_cmds` 219)의 머리 공급을 여기서 정하게 됩니다.

확인한 사실(이번 세션; 원본 목록 138526–140589 행(주소 붙은 줄 2036), 기호표, `m68k-m4-headers.tsv` 행 194–200, python):
- 행 `m68k-222`(정확) [0x406d6b6, 0x406f0fe), 6728 B, 42 항목(합 6728 B, 이어짐; 이름 있는 29·이름 없는 13). NeXTMach mk-108.1 `nextdev/fd_subr.c`(2254 행, SHA-256 `471e5170…`)의 정의 42 개와 차례가 같고, 이름 없는 13 은 NeXTMach 정적 13 개의 자리: 0x406db14 76 `fd_log_error`, 0x406dc10 176 `fd_setup_rw_req`, 0x406dcc0 214 `fd_gen_rw_cmd`, 0x406e192 70 `fd_gen_recal`, 0x406e234 82 `fd_log_2_phys`, 0x406ec7c 120 `vol_check_assign`, 0x406ecf4 134 `vc_compare_vol`, 0x406ee4e 42 `dens_to_capacity`, 0x406eeb4 84 `fd_copy_vol`, 0x406ef08 206 `fd_disk_eject`(NeXTMach 65 행이 정적 선언), 0x406efd6 124 `fd_alert_panel`, 0x406f052 80 `fd_vol_panel_abort`, 0x406f0a2 92 `fd_sectsize_max`(마지막 문자열 `fd_sectsize_max` 와 맞음).
- 자료: 이 파일이 정의하는 자료는 `fd_sectsize_max` 안의 `static u_int sectsize_max;`(NeXTMach 2240 행) 하나 — 원본 `__bss` 0x40b4fba(쓰임 5 번) → bss 자리는 reference-inferred(D113). `__data` 정의 없음. 쓰는 외부 자료는 다른 객체의 것(`_vol_check_delay`·`_fc_thread_init`·`_fd_polling_mode`·`_fd_density_sectsize`·`_fd_density_info`·`_fd_return_values` `__data`, `_fd_drive`·`_fd_volume_p`·`_fd_controller`·`_vol_abort_q`·`_vol_check_*`·`_disk_eject_q`·`_fd_*_major`·`_fd_*_retry`·`_dk_busy`·`_dk_bps`·`_eventc_*` COMMON, `_hz`·`_kernel_task`·`_event_high`·`_event_middle`). `__cstring` 문자열 21 개(0x40a5ff6 `%d ` — 다른 객체와 함께 쓰는 문자열 — 와 [0x40aa416, 0x40aa5f1) 475 B).
- 부르는 것(원본): `fd_command` 6·`panic` 6·`printf` 5·`bzero` 8·`disksort_first` 4 등(기록에 전체), `fc_start`·`fd_attach_com`·`fdstrategy`·`sdchecklabel`·`vol_panel_*`·`vol_notify_dev`·`kernel_thread_noblock`·`us_timeout`·`update` 와 주소로 `_fc_thread`·`kalloc`·`kfree`·`printf`.
- 머리(`m68k-m4-headers.tsv:194–200` 과 이번 세션 스테이지 확인): NeXTMach 은 `"fd.h"`(따옴표; 구성 머리 `NFD`, m68k 생성 머리 없음), `<sys/time_stamp.h>`(스테이지 `src/kern/time_stamp.h`), `<nextdev/disk.h>`(스테이지 `src/bsd/dev/disk.h`), `<next/psl.h>`·`<next/machparam.h>`(SDK `src/bsd/m68k/`), `<nextdev/dma.h>`(07 사본, §544), `<nextdev/insertmsg.h>`(스테이지 `src/kernserv/insertmsg.h`), `<nextdev/voldev.h>`(스테이지 `src/bsd/dev/voldev.h`)를 들이고, NeXTMach 에만 있는 `<nextdev/fd_extern.h>`(537 행)·`<nextdev/fd_vars.h>`(600 행)·`<next/pmon.h>`(→ `next/pmon_ipc.h`)·`<next/pmon_targets.h>`·`<next/kernel_pmon.h>` 를 들임. `kernel_pmon.h` 는 `DEBUG` 가 아니면 `pmon_log_event` 를 빈 매크로로 둠(NeXTMach `kernel_pmon.h:13·61–66`). Darwin 0.1 `bsd/dev/fd_extern.h` 는 나중 판(1994 `FD_MAX_CAP_LIST` 더함, include 다름) — 구조 대조용.
- 이 범위는 정확 행 하나라 받아들이면 덮은 행 49/188, 백분율이 6728 B 만큼(python 3.12 %p) 늘어날 것(지금 계산이 아니라 기대; 도구 출력이 기준).

방법(진단; 명세 `08_build/artifacts/m4p567/spec.json`, run `m4p567-p1`, 바탕 `m0p566-a1-stage`, `m4_id` `m68k-222`, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 진단 머리(`inc`, 모두 NeXTMach 사본에서 include 줄만 스테이지 경로로): `fd.h`(`#define NFD 1`, `#define NFC 1` — `NFC` 는 `fd_subr.c:1313·1463` 이 씀; 원본 0x406e60c–0x406e616 의 고리가 `i <= 0` 일 때만 되풀이 → 1, 가설), `nextdev/fd_extern.h`(`<next/pmap.h>` → `<vm/pmap.h>`), `nextdev/fd_vars.h`(`<sys/time_stamp.h>` → `<kern/time_stamp.h>`, `<kern/mach_types.h>` → `<mach/mach_types.h>`, `<next/printf.h>` → `<kernserv/printf.h>`, `<nextdev/disk.h>` → `<dev/disk.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`, `<nextdev/ldd.h>` → `<dev/ldd.h>`; 421 행 `static int fd_attach_com(…)` 의 `static` 을 뺌 — 원본 `_fd_attach_com` 은 `fd_driver` 쪽 외부 기호 0x406b7dc, `fd_subr.c:1733` 이 부름), `nextdev/fd_reg.h`·`nextdev/sf_access.h`(그대로; `fd_vars.h:36·39` 가 들임), `next/pmon.h`(`<sys/message.h>` → `<mach/message.h>`, `<sys/boolean.h>` → `<mach/boolean.h>`), `next/pmon_ipc.h`(`<sys/message.h>`·`<sys/time_stamp.h>` 같은 식), `next/pmon_targets.h`(그대로), `next/kernel_pmon.h`(`<sys/time_stamp.h>` → `<kern/time_stamp.h>`, `<next/eventc.h>` → `<machdep/m68k/eventc.h>`).
- 변형 A(`08_build/artifacts/m4p567/src/fd_subr_A.c`): NeXTMach 글에서 include 줄만 — `"fd.h"` → `<fd.h>`(도구가 따옴표 include 를 받지 않음), `<sys/time_stamp.h>` → `<kern/time_stamp.h>`, `<nextdev/disk.h>` → `<dev/disk.h>`, `<next/psl.h>` → `<m68k/psl.h>`, `<next/machparam.h>` → `<m68k/machparam.h>`, `<nextdev/insertmsg.h>` → `<kernserv/insertmsg.h>`, `<nextdev/voldev.h>` → `<dev/voldev.h>`; `<nextdev/dma.h>`·pmon 셋·fd 둘은 그대로(진단 머리).
- 측정: `m4_m68k_probe.py compare`(경고 기록), `m68k_funcbytes.py 406d6b6 406f0fe OBJECT.o RECORD.json` + 이름 없는 13 대응(`406db14=_fd_log_error 406dc10=_fd_setup_rw_req 406dcc0=_fd_gen_rw_cmd 406e192=_fd_gen_recal 406e234=_fd_log_2_phys 406ec7c=_vol_check_assign 406ecf4=_vc_compare_vol 406ee4e=_dens_to_capacity 406eeb4=_fd_copy_vol 406ef08=_fd_disk_eject 406efd6=_fd_alert_panel 406f052=_fd_vol_panel_abort 406f0a2=_fd_sectsize_max`) + 결과 지역 이름으로 `40b4fba=<sectsize_max>`; 섹션 크기, `__cstring` 바이트·차례와 원본, 정의 기호, COMMON 이름·크기(`fd_vars.h`·`fd_extern.h` 는 자료를 `extern` 으로만 선언; COMMON 은 스테이지 `sys/buf.h:110–120`·`kern/cpu_number.h:61` 의 임시 정의에서 옴 — 원본 이름인지 확인, `_nbuf`·`_bufpages` 는 원본 `__data`), 원본에 없는 미정의. 다른 함수는 실기 `otool -tv` 비교.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고 다음 계획에서 1997 꼴을 시험합니다. 컴파일이 안 되면 원인을 적고 머리·글을 최소로 고친 꼴로 다시 돌립니다(§564 와 같은 식).
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록(예상: `kalloc` 대입 형 경고 964·1219·1229·1386·2225 행, `kfree` 인자 301·1004·1248·1251·1692·2181 행; `diag_gate.commands_ok` 는 경고가 있으면 거짓).

### 567.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `fd_vars.h` 가 다시 들이는 `nextdev/disk.h`·`busvar.h`·`fd_reg.h`·`ldd.h`·`sf_access.h` 가 풀리지 않음 | NeXTMach `fd_vars.h:30–39` 읽음; 스테이지 `src/bsd/dev/busvar.h`·`ldd.h` 있음(ls); `fd_reg.h`·`sf_access.h` 의 import 는 스테이지에 있는 머리뿐(grep) | ✅ 제 누락. 진단 머리에 더함 |
| `NFC` 도 필요(`fd_subr.c:1313·1463`), 원본 고리가 1 을 뜻함 | grep, 원본 0x406e5e6–0x406e616 읽음(`addql #1,d3; tstl d3; ble`) | ✅ 제 누락. `fd.h` 에 더함(가설) |
| `fd_vars.h:421` 의 `static int fd_attach_com` 은 원본의 외부 기호와 어긋남 | `fd_vars.h:419–423`·`fd_subr.c:1731–1735` 읽음, 기호표 `_fd_attach_com` 0x406b7dc(섹션 1, 외부) | ✅ 진단 사본에서 `static` 을 뺌(07 꼴은 나중에 정함) |
| `fd_vars.h`·`fd_extern.h` 는 자료를 `extern` 으로만 선언; COMMON 은 스테이지 머리의 임시 정의 | — | ⏭️ 진단 결과의 COMMON 목록으로 확인(문구는 고침) |
| `kalloc`·`kfree` 형 경고 예상(줄 목록) | 스테이지 `kern/kalloc.h` 를 열지 않음 | ⏭️ 진단 결과로 확인 |
| `snd_link` 미룸의 근거 사실은 맞음; "대부분 다시 씀" 은 추정 | 이번 세션 python 출력 | ⚖️ 문구는 추정으로 둠 |
| 42 항목·대응 13·bss 0x40b4fba(5 번)·문자열 21 은 맞음; 마지막 문자열은 0x40aa5e1 에서 시작하고 무리는 0x40aa5f1 에서 끝남(475 B), `%d ` 는 공유 | python `0x40aa5f1-0x40aa416` = 475(이번 세션) | ✅ 문구 고침 |
| `inc` 머리에는 따옴표 include 검사가 없음; 진단 `-I` 는 스테이지 `-I` 뒤 | `m4_m68k_probe.py:125·136·223–225`(§563 에서 읽음) | ✅ |

### 567.2 결과(2026-10-30)

- run `m4p567-p1`(A, 기록 `m4-m68k-probe-p567-20261030.json`): 컴파일 종료 1 — `fd_setbratio` 1596 행 `DEV_BSIZE` 미선언: 1997 머리 `sys/param.h:219–223` 은 `#if NeXT` 갈래에 `DEV_BSIZE` 가 없음(NeXTMach `sys/param.h:206` 은 1024). 원본 `fd_setbratio`(0x406e794–0x406e83a)에는 NeXTMach 의 `DEV_BSIZE` 검사 덩이와 그 문자열 둘이 없음. 경고는 §567.1 예상과 같음(`kfree`·`kalloc` 대입, 그리고 `assert_wait` 인자 1487 행 — 예상에 없던 하나).
- run `m4p567-p2`(A2 = A + 진단 `#define DEV_BSIZE 1024` 한 줄; 명세 `spec-p2.json`, 기록 `m4-m68k-probe-p567-p2-20261030.json`): 종료 0, 경고 12, i386 머리 0, 옵션 차이 없음. 섹션 `__text` 6762(원본 6728)·`__cstring` 541·`__bss` 4(`_sectsize_max.112`). COMMON 은 스테이지 머리의 임시 정의(`sys/buf.h`·`_master_cpu`)와 `_tthiwat`·`_tthog`·`_ttlowat`(원본에서는 `__data` 기호 — `_nbuf` 와 같은 M7 합침 의무), 원본에 없는 미정의 0.
- **38/42**(`m4-m68k-funcbytes-p567-A2-20261030.json`, 대응 13 + bss 하나). 실기 `otool -tv`(`08_build/artifacts/m4p561/otool/fd_subr_A2.txt`)와 원본의 비교:
  - `v2d_map`(바이트 6·참조 2)·`fc_thread_timer`(바이트 1): 명령 같고 `struct fd_controller` 오프셋만 다름 — 배열 간격 0x266 → 0x262(0x406e3fe·0x406e402·0x406e60c), A(NeXTMach 배치)의 `holding_q` 0x25a·`holding_q`+4 0x25e → 원본 0x256·0x25a(0x406e4d2–0x406e4fc: `holding_q` 에 넣기; 처음 적은 "0x25a/0x256 → 0x256/0x252" 는 제 오기) → 1997 `struct fd_controller` 는 `holding_q` 앞에서 4 B 작음. `_fd_controller` 에서 다음 기호 `_vol_abort_lock` 까지의 간격은 0x264(크기 증명이 아님; 명령이 보이는 간격은 0x262, §568.1 고침). 원본의 `_fd_controller` 절대 주소 참조는 +0·+0x25·+0x256·+0x25a 뿐이라 어느 필드가 빠졌는지는 이것만으로 정해지지 않음.
  - `fd_setbratio`(168 대 208): `DEV_BSIZE` 검사 덩이(NeXTMach 1592–1604 행)가 없고, `fvp->bdp` 가 NULL 이면 `dk_bps` 계산을 건너뜀(0x406e7e6–0x406e7ec; §568.1 고침 — 처음엔 덩이 없음만 적었음).
  - `volume_check`(1088 대 1082): `vc_fvp->format_info.flags = 0;`(0x406e946) 다음에 `+0xc ← fdp+0x14`(0x406e94a) 한 줄 — NeXTMach `fd_vars.h:223–235` 로 드라이브 +0x14 는 `bdp`, `fd_volume` +0xc 는 `bdp`(원본 `fd_setbratio` 0x406e7e6 이 `fvp->bdp->bd_dk` 로 씀) → `vc_fvp->bdp = fdp->bdp;`.
- 판정(미리 정한 대로): 07 은 바꾸지 않고 다음 계획에서 1997 꼴을 시험합니다.

## 568. M4-74 세부 계획 — `fd_subr.c` 1997 꼴 진단과 `struct fd_controller` 오프셋 표(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p568/spec.json`, run `m4p568-p1`, 바탕 `m0p566-a1-stage`, `m4_id` `m68k-222`):
- 오프셋 진단 O(따로 명세 `08_build/artifacts/m4p568/spec-off.json`, run `m4p568-o1`, `08_build/artifacts/m4p568/src/fdoff_O.c`, 객체 `fdoff`; §567 진단 머리, NeXTMach 배치 그대로): `struct fd_controller` 의 필드마다 `int off_<필드> = (int)&((struct fd_controller *)0)-><필드>;` 와 `sizeof`, `struct fd_drive`·`struct fd_volume` 의 `bdp` 오프셋. 기호마다 실제 섹션과 바이트 순서로 python 이 읽어 표로 적음(§544 와 같은 식). 범위·L1 판정은 쓰지 않음(진단 기록만).
- 변형 B1(`fd_subr_B1.c`): A2 에서 진단 `DEV_BSIZE` 줄을 빼고, `fd_setbratio` 의 `DEV_BSIZE` 덩이(NeXTMach 1592–1602 행)를 지우고, `volume_check` 의 `vc_fvp->format_info.flags = 0;` 다음에 `vc_fvp->bdp = fdp->bdp;` 를 더함. 진단 머리 `nextdev/fd_vars.h` 는 B1 용 사본에서 `struct fd_controller` 의 `sczfst` 를 뺌(§568.1: 원본 `fd_io` `fc_probe` 0x406c774 가 SCSI 주소를 +0x236 에 하나만 저장하고 `sfahp` +0x23a·`sfad` +0x23e(0x406c77c–0x406c780), `fd_cmds` `fc_send_cmd` 의 `dma_list` +0x11e·`dma_chan` +0x26(0x406ae48·0x406ae4e)은 그대로 — 4 B 필드 하나를 빼는 꼴 가운데 이것과 맞는 것은 `sczfst` 뿐; NeXTMach `fd_io.c:186–187` 은 `sczctl`·`sczfst` 를 둘 다 정함). `fd_setbratio` 는 덩이를 지우고 `if (fvp->bdp && (dk = fvp->bdp->bd_dk) >= 0)` 로.
- 측정: §567 과 같음(funcbytes 대응 13 + bss, `otool -tv`), `__cstring` 바이트를 원본 [0x40aa416, 0x40aa5f1) 과 `%d ` 와 대조, bss 4 B.
판정(미리 정함; 07 은 바꾸지 않음): B1 이 42/42 이고 문자열·bss 가 원본과 맞으면 바이트로 정해지지 않는 것(빠진 필드의 정체, `NFD`·`NFC` 구성 값, NeXTMach 전용 머리 여섯의 07 공급 꼴, `fd_attach_com` 의 `static`, `DEV_BSIZE` 덩이 처리, `kfree`·`kalloc`·`assert_wait` 경고)을 사용자께 여쭙니다. 남으면 차이를 적고 꼴을 바꿔 다시 시험합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 568.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 빠진 필드는 `holding_lock` 이 아니라 `sczfst`: 원본 `fc_probe` 가 +0x236 에 SCSI 주소 하나, `sfad` +0x23e·`sfahp` +0x23a; `fc_send_cmd` 는 `dma_list` +0x11e·`dma_chan` +0x26; `sfad_flags` +0x24e | 원본 0x406c74e–0x406c79e·0x406ae30–0x406ae54·0x406c5ca–0x406c5e0 읽음, NeXTMach `fd_io.c:178–192`(`sczctl`·`sczfst` 둘을 정함) 읽음 | ✅ 제 가설 오류(`fd_subr` 바이트만 보고 정함). B1 고침 |
| `fc_send_cmd` 의 `pea 0xa`(0x406ae38)는 `NDMAHDR` 10 | 원본 0x406ae38 읽음; 07 `dma.h:77` 은 `howmany(MAX_DMA_LEN, NeXT_MIN_PAGE_SIZE)+2` | ⚖️ 인자 10 은 확인; `NDMAHDR` 값 확인은 D119 의 남은 의무로 근거 문서에 적음 |
| `fd_setbratio` 는 `bdp` NULL 검사를 더함(0x406e7e6–0x406e7ec); 지울 덩이는 1592–1604 행; 몫은 같은 나눗셈에서 | 원본 0x406e7e2–0x406e832(§567.2 를 쓸 때 이미 읽었는데 놓침), NeXTMach 1590–1606 행 읽음 | ✅ 제 누락. B1 고침 |
| `volume_check` 의 `vc_fvp->bdp = fdp->bdp;` 해석은 맞음(a5 = `fd_new_fv` 결과, a4 = `fd_drive` 포인터) | §567.2 에서 읽은 줄과 `fd_vars.h:123·235` | ✅ 그대로 |
| `v2d_map`·`fc_thread_timer` 의 차이는 간격·`holding_q` 오프셋뿐 | §567.2 비교 출력 | ✅ |
| 0x264 는 다음 기호까지의 간격이지 크기 증명이 아님 | 기호표 `_fd_controller` 0x40c376c·`_vol_abort_lock` 0x40c39d0 | ✅ 문구 고침 |
| 오프셋 진단은 따로 명세가 깔끔(같은 명세면 `refs` 판정에 섞임) | `m4_m68k_probe.py:327·384`(§563·§566 에서 읽음) | ✅ 따로 명세·run |

### 568.2 결과(2026-10-30)

- run `m4p568-o1`(O, 명세 `spec-off.json`, 기록 `m4-m68k-probe-p568-o1-20261030.json`): NeXTMach 배치(07 `dma.h` 1997 `dma_chan`)의 `struct fd_controller` 오프셋 `fcrp` 0·`bcp` 4·`req_lock` 8·`req_q` 0xc·`flags_lock` 0x14·`flags` 0x18·`fdiop` 0x1c·`fdiop_i` 0x20·`ipl` 0x24·`flpctl_sh` 0x25·`dma_chan` 0x26·`dma_list` 0x11e·`sczfst` 0x236·`sczctl` 0x23a·`sfahp` 0x23e·`sfad` 0x242·`holding_lock` 0x256·`holding_q` 0x25a·`last_dens` 0x262·크기 0x266; `fd_drive.bdp` 0x14·`fd_volume.bdp` 0xc(객체 `__data` 낱말, python).
- 빠진 필드는 바이트로 `sczfst`: 원본 `fc_probe` 0x406c768–0x406c774 가 +0x236 에 저장하는 값은 `slot_id_bmap + 0x2014020` = `SDC_ADDRS`(NeXTMach `fd_reg.h:160`; `SFS_ADDRS` 는 0x2014021, 176 행)이므로 남은 것은 `sczctl`(NeXTMach `fd_io.c:186–187` 이 둘을 정하고, `sczctl` 은 `fd_io.c:703–709`·`fd_cmds.c:377–381` 이 씀; `sczfst` 는 정할 뿐 쓰지 않음).
- run `m4p568-p1`(B1, 기록 `m4-m68k-probe-p568-20261030.json`): 종료 0, 경고는 A2 와 같은 종류(`kfree`·`kalloc` 대입·`assert_wait`), i386 머리 0, 옵션 차이 없음. **42/42**(`m4-m68k-funcbytes-p568-B1-20261030.json`), L1 사유 `['__DATA,__bss: unverified']` 하나(`provisional`), 원본에 없는 이름 0. 확인 `m4-m68k-p568-checks-20261030.json`(`ok` 참): 섹션 `__text` 6728·`__cstring` 479·`__bss` 4(`_sectsize_max.112`); 문자열 21 개 가운데 이 파일 몫 20 개(475 B)가 원본 [0x40aa416, 0x40aa5f1) 과 같은 바이트·차례, `%d ` 는 링커가 합친 공유 문자열(원본 0x40a5ff6); 외부 함수 29 = 원본 이름; COMMON 모두 원본 이름; 원본에 없는 미정의 0. 객체 SHA `8e773522…`.
- 구성 값은 바이트로 정해짐: `NFC` 1(0x406e60c–0x406e616), `NFD` 1(`volume_check` 0x406eae4–0x406eaee 의 드라이브 고리, 간격 40 B = `_fd_drive` 다음 기호까지 0x28).
- 판정(미리 정한 대로): 42/42 이고 문자열·bss 가 맞으므로 바이트로 정해지지 않는 것을 여쭙니다. 앞선 결정을 그대로 따를 것(묻지 않음): NeXTMach 전용 머리는 `07_kernel/nextmach/<경로>` 사본 + include 줄 OPENSTEP 경로(D104), `fd.h` 는 m68k 구성 생성 머리(`NFD`·`NFC` 는 바이트로 확인된 값이라 `confirmed`, D121 `NNP` 선례), 경고는 글 그대로 + `known_warnings`, bss 는 CODE+BSS_INFERRED(D113). 바이트가 정한 1997 바뀜: `sczfst` 뺌, `fd_attach_com` 의 `static` 뺌(원본 외부 기호), `fd_setbratio` 의 `DEV_BSIZE` 덩이 없음과 `bdp` 검사, `volume_check` 의 `bdp` 복사. 여쭐 것: ① pmon 머리 넷(`pmon.h`·`pmon_ipc.h`·`pmon_targets.h`·`kernel_pmon.h`)의 공급 ② `fd_extern.h` 의 바탕(NeXTMach / Darwin 0.1 의 나중 판) ③ `sczfst` 줄의 꼴.
- 사용자 결정(2026-10-30, AskUserQuestion): ① pmon 머리 넷은 "NeXTMach 사본 넷"(D104) ② `fd_extern.h` 는 "Darwin 0.1 판"(제 추천은 NeXTMach 사본) ③ `sczfst` 는 "줄을 지우고 표시 주석".

## 569. M4-75 세부 계획 — Darwin 0.1 `fd_extern.h` 로 `fd_subr` 진단(07 변경 없음; 코딩 전, 2026-10-30)

결정 ② 의 Darwin 0.1 `bsd/dev/fd_extern.h`(722 행, APSL)는 NeXTMach 판과 다름(이번 세션 diff): include 가 `<mach/boolean.h>`·`<mach/vm_param.h>`(NeXTMach `<next/pmap.h>`·`<vm/vm_map.h>`), `fd_ioreq` 의 `pmap`·`map` 이 `struct pmap *`·`struct vm_map *`, `fdIoReq_t`·`FD_MAX_CAP_LIST`·`struct fd_cap_list`·`FDIOCGCAPLIST`·`FDR_ALIGN/DMA/SPURIOUS`·`FD_DENS_DEFAULT`(i386 아니면 `FD_DENS_4`)·`FD_MID_DEFAULT`(i386·hppa) 를 더하고, 명령 구조체 비트필드를 `__LITTLE_ENDIAN__`/`__BIG_ENDIAN__` 갈래로 나누고 둘 다 아니면 `#error`. 바이트로 같은 객체가 되는지 시험한 적이 없음.
방법(명세 `08_build/artifacts/m4p569/spec.json`, run `m4p569-p1`, 바탕 `m0p566-a1-stage`, `m4_id` `m68k-222`):
- 변형 B2 = §568 B1 글 그대로, 진단 머리 가운데 `nextdev/fd_extern.h` 만 Darwin 0.1 판 사본(내용 그대로; 이 판의 include 넷은 스테이지에 있음 — `sys/types.h`·`sys/ioctl.h`·`mach/boolean.h`·`mach/vm_param.h`)으로 바꿈. 나머지 진단 머리는 §568 B1 과 같음.
- 측정: §568 과 같음(funcbytes·문자열·bss·COMMON·미정의; 기록 `m4-m68k-probe-p569-20261030.json`·`m4-m68k-funcbytes-p569-B2-20261030.json`·`m4-m68k-p569-checks-20261030.json`), 그리고 B1 객체(`08_build/runs/m4p568-p1/stage/Q568__fd_subr_B1.o`, SHA `8e773522…`)와 canon 비교 및 `obj_sig` 의 `header`·`sections`·`symbols`·`stabs` 를 나눠 기록(STABS 수 차이만으로는 기각하지 않음). 큰 끝 갈래가 골라졌는지는 `#error` 가 안 나는 것만으로는 부족하므로(`__LITTLE_ENDIAN__` 을 먼저 봄), `fd_gen_rw_cmd` 가 쓰는 `fd_rw_cmd` 비트필드(`mt`·`mfm`·`opcode`·`hds`, NeXTMach `fd_subr.c:829–832`)의 바이트가 B1·원본과 같은 것으로 확인(갈래가 바뀌면 비트 위치가 바뀜).
판정(미리 정함; 07 은 바꾸지 않음): B2 가 42/42 이고 B1 과 canon 같으면 07 의 자리(`07_kernel/src/bsd/dev/fd_extern.h` — Darwin 경로, x86 이 읽지 않음을 x86 입력 검사로 확인 / `07_kernel/nextmach/nextdev/fd_extern.h` 자리에 Darwin 글)와 구현 계획을 사용자께 여쭙니다. 다르면 차이를 적고 결정 ② 를 다시 여쭙습니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 569.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Darwin 판의 import 넷은 스테이지에서 풀림 | §569 사실 줄(이번 세션 스테이지 확인)과 같음 | ✅ |
| `__BIG_ENDIAN__` 은 컴파일러 미리 정의로 보이나(스테이지 `sys/wait.h:12–14` 등) `#error` 없음만으로는 큰 끝 갈래 선택을 보이지 못함 | `sys/wait.h:10–14` 읽음 | ✅ 측정 고침(비트필드를 쓰는 `fd_gen_rw_cmd` 의 바이트로 확인; 829–832 행 grep) |
| 공유 구조체·비트필드(큰 끝 갈래)·상수·ioctl 은 NeXTMach 와 같고, `fd_ioreq` 의 `pmap_t`/`vm_map_t` → `struct pmap *`/`struct vm_map *` 는 같은 형 | 제가 줄 단위로 따로 비교하지 않음 | ⏭️ B2 의 바이트 결과로 확인 |
| Darwin 판에는 `fd_sense_drive_status_cmd` 도 더 있음(제 목록에 빠짐) | Darwin `fd_extern.h:490` 읽음 | ✅ 사실 보충(쓰이지 않음) |
| 빠진 import(`<next/pmap.h>`·`<vm/vm_map.h>`)는 `fd_subr.c:29`·`fd_vars.h:32` 의 `<vm/vm_map.h>` 가 공급 | B1 의 import 줄(§568 생성기)과 같음 | ✅ |
| `obj_sig` 에는 STABS 수가 들어감 → 칸별로 기록; 한 변형 명세는 B1 과 자동 비교하지 않음; 기록 이름을 적을 것 | `l2_prefix_diff.py` `obj_sig` 의 `stabs` 칸 grep | ✅ 측정 고침 |

### 569.2 결과(2026-10-30)

- run `m4p569-p1`(B2 = B1 글 + Darwin 0.1 `fd_extern.h` 그대로, 명세 `08_build/artifacts/m4p569/spec.json`, 기록 `m4-m68k-probe-p569-20261030.json`): 종료 0(`#error` 없음), 경고 12(B1 과 같은 종류), i386 머리 0, 옵션 차이 없음. **42/42**(`m4-m68k-funcbytes-p569-B2-20261030.json`), L1 사유 bss 하나(`provisional`), 원본에 없는 이름 0 — `fd_gen_rw_cmd` 의 비트필드 바이트가 같으므로 큰 끝 갈래가 골라짐.
- B1 과 비교(`m4-m68k-p569-checks-20261030.json`, `ok` 참): canon 같음, `obj_sig` 의 `header`·`sections`·`symbols` 같음, STABS 2054 → 2060(Darwin 판이 더한 형). B2 SHA `39fa4595…`.
- x86 쪽: 07(`src`·`nextdev`·`nextdev_private`)과 x86 forms·`s6ln-g1a` 스테이지에 `fd_extern.h` 쓰임 0(grep).
- 판정(미리 정한 대로): Darwin 판으로 같은 객체이므로 07 자리와 include 꼴을 여쭙고 구현 계획을 세웁니다.
- 사용자 결정(2026-10-30, AskUserQuestion): Darwin 0.1 판 `fd_extern.h` 는 "07 `nextmach/nextdev` + 경로 그대로" — `07_kernel/nextmach/nextdev/fd_extern.h` 에 Darwin 글(APSL 고지 그대로), include 줄은 NeXTMach `<nextdev/fd_extern.h>` 그대로(제 추천은 `07_kernel/src/bsd/dev` + `<dev/fd_extern.h>`).

## 570. M4-76 D128 구현 계획 — 07 `src/machdep/m68k/fd_subr.c`, floppy·pmon 머리 여덟, 구성 `fd.h`(CODE+BSS_INFERRED; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §567–569 결과와 결정. NeXTMach `conf/MASTER.next:129–130`(`controller fc0`·`disk fd0 at fc0`, 둘 다 `<fd>`)과 `fd_subr.c` 가 `"fd.h"` 하나로 `NFD`·`NFC` 를 씀; `gen_config_headers.py` 는 같은 머리의 행을 한 파일로 묶음(`render`, 30–45 행). `stage_m68k.py` 의 `M4HEADERS` 는 07 뿌리 `nextmach` 를 기본으로 받음(500–502 행). 07 머리를 새로 두기만 하므로 받아들인 기록의 plan 506 검사에 영향 없음.
1. 07 머리(D104, 스테이징 `M4HEADERS[570]`):
   - `07_kernel/nextmach/nextdev/fd_extern.h` = Darwin 0.1 `kernel/bsd/dev/fd_extern.h` 그대로(722 행, APSL 고지 그대로; 결정 §569); 스테이지 `src/bsd/nextdev/fd_extern.h`.
   - `07_kernel/nextmach/nextdev/fd_vars.h` = NeXTMach 사본 + include 줄 여섯(`<kern/time_stamp.h>`·`<mach/mach_types.h>`·`<kernserv/printf.h>`·`<dev/disk.h>`·`<dev/busvar.h>`·`<dev/ldd.h>`, D104) + `sczfst` 줄을 지우고 표시 주석(결정 §568) + `fd_attach_com` 원형의 `static` 을 뺌(원본 외부 기호 `_fd_attach_com`; D024) — 모두 표시 plan 570; 스테이지 `src/bsd/nextdev/fd_vars.h`.
   - `07_kernel/nextmach/nextdev/fd_reg.h`·`sf_access.h` = NeXTMach 그대로; 스테이지 `src/bsd/nextdev/`.
   - `07_kernel/nextmach/next/pmon.h`(`<mach/message.h>`·`<mach/boolean.h>`)·`pmon_ipc.h`(`<mach/message.h>`·`<kern/time_stamp.h>`)·`pmon_targets.h`(그대로)·`kernel_pmon.h`(`<kern/time_stamp.h>`·`<machdep/m68k/eventc.h>`) — 결정 §568 ①; 스테이지 `src/bsd/next/`.
   위 여덟은 §569 명세의 진단 머리(Darwin `fd_extern.h`, §568 `incB/fd_vars.h`, 나머지 §567 사본)에서 옮기고, 주석 뺀 토큰이 같아야 함(python; 진단 주석을 표시 주석으로 바꾼 것만 다름).
2. 구성: `config_options-m68k.tsv` 에 `fd NFD fd.h 1 confirmed`·`fc NFC fd.h 1 confirmed`(근거: §568.2 의 원본 고리 둘), `gen_config_headers.py --arch m68k` → `07_kernel/v183.34/m68k/generated/fd.h`(`#define NFD 1`·`#define NFC 1`), `--check` 둘(x86·m68k).
3. 07 `src/machdep/m68k/fd_subr.c`(D103) = NeXTMach `nextdev/fd_subr.c` + 머리 주석(1997 바뀜·함수별 출처) + include 줄(`"fd.h"` 는 NeXTMach 그대로 둠 — `@` 소스는 따옴표 include 검사를 받지 않음(§570.1); `<kern/time_stamp.h>`·`<dev/disk.h>`·`<m68k/psl.h>`·`<m68k/machparam.h>`·`<kernserv/insertmsg.h>`·`<dev/voldev.h>`, D104) + 1997 본문 셋(`fd_setbratio` 의 `DEV_BSIZE` 덩이 없음과 `bdp` 검사, `volume_check` 의 `vc_fvp->bdp = fdp->bdp;`; 표시 plan 570, D128, D024). 주석 뺀 토큰이 §568 B1 글(= §569 B2 글)과 `"fd.h"`/`<fd.h>` 한 자리만 다르고 나머지는 같아야 함(python).
4. `stage_m68k.py`: `M4FILES[570]` = 566 + `fd_subr.c`, `M4HEADERS[570]` = 556 + 위 여덟, `EXCEPTS[570] = dict(EXCEPTS[566])`, 머리말 목록에 570.
5. 회귀: 생성 `fd.h` 는 모든 m68k 스테이지에 들어가므로 `--plan 566` 재생성(`m0p566-r570-stage`)은 보관본과 `generated/fd.h` 하나만 다름(§559 의 `dsp.h` 와 같음); `m0p570-a1-stage` 와 보관 566 의 차이는 `generated/fd.h`·`fd_subr.c`·머리 여덟. M5 205 줄(`m3p570-b566`·`m3p570-cc1`): 객체·stderr 같음, `compare` 두 기록 `differ_unexpected`·`lost` 빔·요약 차이는 새 경로뿐. x86: `gen_config_headers.py --check`, `m4_x86_inputs.py s6ln`(`L2_FORMS`·`L2_EXPECT`)·`--plan 570 x86gate`.
6. (07 파일은 p1 전에 고정) 확인 run `m4p570-p1`(`confirm/spec.json`, 바탕 `m0p570-a1-stage`, 진단 `inc` 없음): F = `@machdep/m68k/fd_subr.c`, L = §568 B1 글 그대로(스테이지의 07 머리로 컴파일). 종료 0, 경고는 B2 와 같은 열두 개(stderr 21 줄, 함수 문맥 줄 포함; 경로·줄 번호는 다를 수 있음), i386 머리 0, F = L(canon·`obj_sig`), `provisional`(사유 bss 하나), 42/42; F 와 §569 B2 객체 canon 같음(STABS 차이는 기록). run `m4p570-e1`: F·L `-E` 토큰 같음(`#` 줄 빼고).
7. 최종 run `m4p570-a1`(명세 `08_build/artifacts/m4p570/spec.json`: F 만, REF = p1 L, `known_warnings["fd_subr"]` = p1 F 의 stderr 줄 그대로(`splitlines()` 전체), `bss_inferred` [`fd_subr`], `m4_id` `m68k-222`): `gate.ok`, 옵션 차이 없음; zerofill `objs`(`m4-m68k-zerofill-p570-20261030.json`) `reference-inferred` 이고 후보 [0x40b4fba, 0x40b4fbe); 이전 bss 배치(§464 + `"plan464_record"` 기록, 진단 `-D-`·`-D1-`·`-C2-`·대체된 §556·이번 것 뺌; §566 포함 — 기대 17 기록)와 겹침 0(python, 경로·SHA 기록); funcbytes 42/42; python 확인 `m4-m68k-p570-checks-20261030.json`: §568 확인 항목(섹션·문자열 475 B 와 `%d `·bss·외부 함수 29 = 원본·COMMON(`_tthiwat` 등은 원본 `__data` — M7 합침)·미정의), L1 0x406d6b6 사유 bss 하나, 의존 목록 i386 0, 입력 SHA 사슬 07 = 스테이지 = run(`fd_subr.c`, 생성 `fd.h`, 머리 여덟, `nextdev/dma.h`·`dev/m68k/dma.h`·`sys/callout.h`·`dev/busvar.h`)과 SDK = 스테이지 = run(`m68k/psl.h`·`m68k/machparam.h`), 07 m68k 덮어쓰기 = 스테이지 = run(`machdep/m68k/eventc.h`). 기록 이름: `m4-m68k-probe-p570-p1-20261030.json`·`m4-m68k-funcbytes-p570-F/L/a1-20261030.json`·`m4-m68k-p570-final-20261030.json`·`m4-m68k-zerofill-p570-20261030.json`·`m4-m68k-p570-checks-20261030.json`·`m3-m68k-p570-compare-20261030.json`(`-b566-`)·`m4-x86-inputs-p570-20261030.json`·`m4-m68k-status-p570-20261030.json`.
8. 상태표: 근거 `06_reconstruction/evidence/m68k-fd_subr.md` 를 먼저 쓰고 `ACCEPTED` 에 넷 묶음 한 줄; 도구 두 번 실행·§566 표와 이름 대조(더한 것 `fd_subr` 뿐). 기대: 정확 행 `m68k-222` 를 덮으므로 덮은 행 49/188, 바이트가 6728 B 늘어남(수치는 도구 출력만 적음).
9. 기록: diff(NeXTMach 대비 `fd_subr.c`·`fd_vars.h`·pmon 머리 셋; `fd_extern.h` 는 Darwin 그대로), PROVENANCE 새 행(일곱 칸 모두: `fd_subr.c` — 함수별 출처, 파일 SHA, 최종·zerofill 기록, `M4FILES[570]`; 머리 여덟 — `M4HEADERS[570]` 스테이지 자리; `fd_extern.h` 는 자리가 `nextmach` 이어도 출처 `darwin01` `kernel/bsd/dev/fd_extern.h`, 보관 SHA, APSL(`07_kernel/LICENSES/APSL-1.0.txt`), 고지 그대로 — D030 은 NeXTMach 대응이 있어 해당 없음; 생성 `fd.h`), MODIFICATIONS, DECISIONS D128, 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: bss 자리, `_nbuf`·`_bufpages`·`_tthiwat`·`_tthog`·`_ttlowat` 합침, `fd_attach_com` 등 다른 floppy 객체의 함수.
관문: 명령 종료 0, 정한 경고뿐, i386 머리 0, 회귀 같음, 겹침 0, 상태 도구가 멈추지 않음.

### 570.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `@` 소스는 따옴표 include 검사를 받지 않음 — "도구가 받지 않음" 은 틀린 근거 | `m4_m68k_probe.py:128–137` 읽음(`p.startswith('@')` 면 `continue`) | ✅ 제 오류. `"fd.h"` 를 NeXTMach 그대로 두고 토큰 비교는 그 한 자리를 허용 |
| `known_warnings` 는 stderr 21 줄 전체(경고 12 + 함수 문맥 9) | `m4p569-p1/stage/_log/00.err` `wc -l` = 21 | ✅ 6·7 고침 |
| 07 머리는 §569 명세의 진단 입력(Darwin `fd_extern.h`, §568 `incB/fd_vars.h`, 나머지 §567)에서 옮길 것 | §569 `spec.json` 의 `inc` 출력(이번 세션) | ✅ 1 고침 |
| 입력 사슬에 `sys/callout.h`·`dev/busvar.h`, SDK `m68k/psl.h`·`machparam.h`, 덮어쓰기 `eventc.h` 를 출처별로 | §566 확인 기록의 사슬 꼴 | ✅ 7 고침 |
| 이전 bss 배치는 기대 17 기록·34 배치(§566 포함, §556 뺌) | 수는 최종 run 뒤 python 으로 다시 셈 | ⏭️ 실행 결과로 |
| 상태 기대(49/188·21.32 % 등) | — | ⏭️ 수치는 도구 출력만 적음 |
| `M4HEADERS` 튜플·뿌리·스테이지 자리 충돌 없음, 생성기는 같은 머리 행을 묶음(여섯 칸), 회귀의 차이 파일 예상과 매니페스트 키(`added`·`files`) | `stage_m68k.py:500–502`, `gen_config_headers.py:30–45`(이번 세션 읽음) | ✅ 5 의 "모든 키 같음" 은 쓰지 않음(§559 와 같음) |
| PROVENANCE 일곱 칸; Darwin `fd_extern.h` 는 `darwin01` 출처·보관 SHA·APSL | PROVENANCE 의 `darwin01` 행 꼴(`revision_or_sha256` 에 보관 SHA, 라이선스 칸 `07_kernel/LICENSES/APSL-1.0.txt`) | ✅ 9 고침 |

### 570.2 결과(2026-10-30)

- 1: 07 머리 여덟(`07_kernel/nextmach/`): `nextdev/fd_extern.h`(Darwin 0.1 그대로, `cmp` 같음, SHA `a40c0e64…`)·`nextdev/fd_vars.h`(SHA `8b9e56bb…`, 바꿈 여덟 줄 표시)·`nextdev/fd_reg.h`·`nextdev/sf_access.h`·`next/pmon_targets.h`(NeXTMach 그대로, `cmp` 같음)·`next/pmon.h`·`next/pmon_ipc.h`·`next/kernel_pmon.h`(include 두 줄씩 표시) — 모두 §569 진단 입력과 주석 뺀 토큰이 같음(python). diff `m68k-fd_vars_h.diff`(44 행)·`m68k-pmon_h.diff`(40 행).
- 2: `config_options-m68k.tsv` 14 → 16 행(여섯 칸, `confirmed`), 생성 `07_kernel/v183.34/m68k/generated/fd.h`(`#define NFD 1`·`#define NFC 1`, SHA `c0b05642…`), `--check` 둘(x86·m68k) 종료 0.
- 3: 07 `src/machdep/m68k/fd_subr.c`(2255 행, SHA `a4021916…`): 주석 뺀 토큰 8956 개가 §568 B1 과 `"fd.h"`/`<fd.h>` 한 자리만 다름(python). diff `m68k-fd_subr.diff`(78 행).
- 4: `stage_m68k.py` 681 → 687 행(`M4FILES[570]`·`M4HEADERS[570]`·`EXCEPTS[570]`·머리말 목록).
- 5: `--plan 566` 재생성(`m0p566-r570-stage`)은 보관본과 `generated/fd.h` 하나만 다름(매니페스트 키 `added`·`files`); `m0p570-a1-stage`(952 파일)와 보관 566 의 차이는 `generated/fd.h`·`fd_subr.c`·머리 여덟(python assert). M5: `m5-566.cmd` 가 §566 것과 `cmp` 같음, run `m3p570-b566`·`m3p570-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p570-compare-20261030.json`, `-b566-`) `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로 열뿐. x86 `m4-x86-inputs-p570-20261030.json` `ok`, `--plan 570 x86gate` 일곱 같음·`v183_paths` 0.
- 6: run `m4p570-p1`(`m4-m68k-probe-p570-p1-20261030.json`): F·L 종료 0, 경고 12 개씩(stderr 21 줄), `provisional`(사유 bss 하나), 42/42(`m4-m68k-funcbytes-p570-F/L-20261030.json`), F = L(canon·`obj_sig`), F = §569 B2(canon, `obj_sig` 모든 칸, STABS 2060). run `m4p570-e1`: `-E` 토큰 22923 개 F = L, 둘 다 `src/generated/fd.h` 를 들임, i386 머리 0.
- 7: run `m4p570-a1`(`m4-m68k-p570-final-20261030.json`, SHA `a8343381…`): `gate.ok`, 옵션 차이 없음, 42/42(`m4-m68k-funcbytes-p570-a1-20261030.json`); zerofill `m4-m68k-zerofill-p570-20261030.json`(SHA `0f5a2ce7…`) `reference-inferred`, 후보 [0x40b4fba, 0x40b4fbe); 확인 `m4-m68k-p570-checks-20261030.json`(`ok` 참): 이전 bss 배치 기록 17 개(§464 + 16)의 배치 34 와 겹침 0·서로 겹침 0, 문자열 475 B 원본과 같음, 외부 함수 29 = 원본, 의존 167 파일·i386 0, 입력 사슬 열일곱(07·SDK·m68k 덮어쓰기 출처별). 객체 SHA `9bc5523e…`.
- 8: 근거 `06_reconstruction/evidence/m68k-fd_subr.md`(상태 도구 전). `ACCEPTED` 에 넷 묶음 한 줄. 상태표 30 → 31 행·`m4-m68k-status-p570-20261030.json`: 29 객체(OBJECT_MATCH 22, CODE+BSS_INFERRED 7), 덮은 행 49/188, 46024/215874 B(21.32%; python, +6728 B), `object_bytes` 60212, 두 번 실행 같음, §566 표와 이름 대조로 더한 것 `fd_subr` 뿐·바뀐 것 없음.
- 9: PROVENANCE 1154 → 1164 행(일곱 칸; `fd_extern.h` 는 `darwin01`·보관 SHA·APSL), MODIFICATIONS 705 → 709 행, DECISIONS D128(131 → 132 행), "현재 상태와 다음 일" 고침.

## 571. M4-77 세부 계획 — m68k `fd_io.c`(행 221) NeXTMach 글 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): floppy 묶음 가운데 행 221(정확, [0x406c55c, 0x406d6b6) 4442 B)은 원본 22 항목이 NeXTMach mk-108.1 `nextdev/fd_io.c`(1311 행, SHA-256 `9b02d171…`)의 정의 22 개와 차례가 같음. 행 220 `fd_driver` 는 NeXTMach 에 없는 `_fdsize`(0x406ba5a, 70 B)가 있어 본문을 바이트로 새로 써야 하므로 다음으로 미룸. §570 의 07 머리(`fd_vars.h`·`fd_extern.h`·`fd_reg.h`·`sf_access.h`, 생성 `fd.h`)가 스테이지에 있음.

확인한 사실(이번 세션; 원본 목록 137169–138524 행(주소 붙은 줄 1342, 안쪽 라벨 14), 기호표, 원본 `__data`·`__cstring`, python):
- 22 항목(합 4442 B): 이름 있는 열다섯(`fc_probe` 610 … `fc_flags_bclr` 46)과 이름 없는 일곱 — NeXTMach 정적의 자리: 0x406cd48 304 `fc_intr`, 0x406cfe8 154 `fc_wait_pio`, 0x406d0c0 146 `fc_update_stat`, 0x406d3e2 148 `fc_dmaintr`, 0x406d476 344 `fc_wait_sf_access`, 0x406d5ce 96 `fc_perpend`(39 행 앞 선언, 1247 행 정의), 0x406d62e 46 `fc_grant_sf_access`. 원본에서 0x406cd48·0x406d3e2·0x406d62e 는 주소로 쓰임(인터럽트 처리기·DMA 처리기·`sfa` 콜백 자리).
- 자료: `__data` [0x40b14a6, 0x40b14b2) 12 B = `cf2_fifo_value` 8(`CF2_FIFO_DEFAULT`, 07 `fd_extern.h:377`)·`cf2_efifo` 0·`clear_dma_on_int` 1(NeXTMach 983·984·1111 행과 같은 초깃값); 다음 기호 `_ohlfs12`. `__bss` 없음. 문자열 참조 8: 0x40aa2ab `Bad Controller Phase`(`fd_global.c` 의 `_fd_return_values` 표 0x40b13f6 의 낱말 0x40b144a 도 이것을 가리킴 — 링커가 합친 공유 문자열; `Seek Error`…`SUCCESS` 는 그 표의 문자열)와 이 파일 몫 일곱 [0x40aa349, 0x40aa416) 205 B. 진단 객체의 `__cstring` 은 공유 21 B 를 더한 226 B 로 예상.
- 부르는 것(원본): `fc_send_cmd` 3·`thread_wakeup_prim` 5·`printf` 4·`fd_intr` 3·`fd_thread_block` 3·`bzero` 3·`sfa_relinquish` 3·`install_scanned_intr` 2·`uninstall_scanned_intr` 2·`v2d_map` 2 등(기록에), 주소로 `_delay`·`_dma_intr`·`_fc_thread_timer`·`_probe_rb`. 자료: `_fd_polling_mode` 17·`_machine_type` 5·`_slot_id_bmap` 4·`_dma_chip` 2·`_disr_shadow` 2·`_fd_controller`(+0·+0x25) 등.
- 원본에서 이미 본 1997 바뀜: `fc_intr` 의 DMA FIFO 비우기 고리가 `dma_chip == 313` 이면 8 번, 아니면 1 번(0x406cd7e–0x406cdc2; NeXTMach 702 행은 늘 8 번; §571.1). `fc_probe` 는 `sczfst` 를 정하지 않고(07 `fd_vars.h` 에 그 필드 없음) `sczctl = slot_id_bmap + SDC_ADDRS`(0x406c768–0x406c774; NeXTMach 186 행은 `SDC_ADDRS` 만).
- 머리: NeXTMach 은 `"fd.h"`, `<next/cpu.h>`(D109: 어셈블리 전용 — 이 파일이 쓰는 이름은 `I`·`I_IPL`·`I_SCSI`·`I_SCSI_DMA`·`I_PHONE`·`P_SCSI_CSR` 와 `slot_id_bmap`; `machine_type` 은 SDK `m68k/cpu.h`), `<kern/lock.h>`, `<sys/time.h>`, `<sys/callout.h>`, `<sys/dk.h>`, `<next/psl.h>`, `<kern/mach_types.h>`, `<next/machparam.h>`, `<nextdev/dma.h>`·`fd_extern.h`·`fd_reg.h`·`fd_vars.h`·`sf_access.h`(§570 07), `<nextdev/odreg.h>`(NeXTMach 에만 있음; 쓰는 이름은 `OMD_SDFDA` 0x02 하나), `<next/scr.h>`(스테이지에 없음; 쓰는 이름은 `NeXT_CUBE` 하나), `"sc.h"`(구성 머리; 이 파일에서 `NSC` 를 쓰지 않음 — grep 0, 생성 머리 없음)를 들임.

방법(진단; 명세 `08_build/artifacts/m4p571/spec.json`, run `m4p571-p1`, 바탕 `m0p570-a1-stage`, `m4_id` `m68k-221`, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 진단 머리(`inc`): `sc.h`(빈 진단 머리 — 쓰이지 않음).
- 변형 A(`08_build/artifacts/m4p571/src/fd_io_A.c`): NeXTMach 글에서 include 줄만 — `"fd.h"`·`"sc.h"` → `<fd.h>`·`<sc.h>`(진단 소스는 따옴표 include 를 받지 않음), `<next/cpu.h>` → `<m68k/cpu.h>` + 진단 이름 덩이(`extern int slot_id, slot_id_bmap;`, `SLOT_ID`·`SLOT_ID_BMAP`·`I`·`I_IPL`·`I_SCSI`·`I_SCSI_DMA`·`I_PHONE`·`P_SCSI_CSR`·`P_DISK`(`fd_reg.h:155` 의 `DISR_ADDRS` 가 씀, `fd_io.c:1222`), 값은 `07_kernel/nextmach/next/cpu.h:96·98·132·155·213·215·228·252·257`), `<kern/mach_types.h>` → `<mach/mach_types.h>`, `<next/psl.h>`·`<next/machparam.h>` → `<m68k/…>`, `<nextdev/odreg.h>`·`<next/scr.h>` 는 빼고 덩이에 `#define OMD_SDFDA 0x02`·`#define NeXT_CUBE 0`. 그리고 `fc_probe` 의 `fcp->sczfst = (u_char *)SFS_ADDRS;`(187 행)를 뺌 — 07 `fd_vars.h` 에 그 필드가 없어 컴파일이 안 되고, 원본에도 없음(진단 표시).
- 측정: `m4_m68k_probe.py compare`(경고 기록), `m68k_funcbytes.py 406c55c 406d6b6 OBJECT.o RECORD.json 406cd48=_fc_intr 406cfe8=_fc_wait_pio 406d0c0=_fc_update_stat 406d3e2=_fc_dmaintr 406d476=_fc_wait_sf_access 406d5ce=_fc_perpend 406d62e=_fc_grant_sf_access`; 섹션(`__text` 4442·`__data` 12·`__cstring`), `__data` 바이트와 원본, 문자열(이 파일 몫 205 B 와 공유 `Bad Controller Phase`), 정의 기호(외부 함수 열다섯·`_cf2_fifo_value`·`_cf2_efifo`·`_clear_dma_on_int`), COMMON, 원본에 없는 미정의. 다른 함수는 실기 `otool -tv` 비교.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고 다음 계획에서 1997 꼴을 시험합니다(`fc_probe` 의 `slot_id_bmap` 과 `fc_intr` 의 FIFO 고리는 다를 것으로 예상; `__text` 4442 는 원본 크기이지 A 에 요구하는 값이 아님). 컴파일이 안 되면 원인을 적고 최소로 고친 꼴로 다시 돌립니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 571.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A 는 `P_DISK` 가 없어 컴파일되지 않음(`fd_io.c:1222` → `DISR_ADDRS` → `P_DISK`) | 07 `fd_reg.h:155`·`next/cpu.h:155` 읽음, NeXTMach `fd_io.c` grep(1222 행) | ✅ 제 누락. 진단 덩이에 더함 |
| `fc_intr` 의 FIFO 비우기 고리가 `dma_chip == 313` 일 때만 8 번 | 원본 0x406cd78–0x406cdcc 읽음, NeXTMach 698–712 행 읽음 | ✅ 제 누락. 사실·판정에 더함 |
| 0x40aa2ab 는 `fd_global` 의 `_fd_return_values` 표(0x40b144a 낱말)도 가리키는 공유 문자열; 진단 객체 `__cstring` 은 226 B | python 으로 0x40b144a 의 낱말 `040aa2ab`, 기호표 `_fd_return_values` 0x40b13f6 | ✅ 문구 고침(226 B 는 결과로 확인) |
| 22 항목·대응 일곱·주소 쓰임·`__data` 12 B·`__bss` 없음·문자열 여덟·호출 수는 맞음 | 이번 세션 python 출력 | ✅ |
| 그 밖의 include·이름은 스테이지에서 풀림(`ldd.h` → `kernserv/prototypes.h` 의 `probe_rb` 등, `install_scanned_intr` 은 SDK `dev/m68k/autoconf.h:28`), i386 머리 없음, COMMON 은 `fd_subr` 과 같은 열네 이름 | 제가 따로 다 열어 보지 않음 | ⏭️ 진단 컴파일·의존 목록·기호로 확인 |
| `fd_subr` 의 경고(`kalloc` 대입 등)를 이 파일에 기대하지 말 것 | — | ✅ 경고는 실제 stderr 로만 적음 |

### 571.2 결과(2026-10-30)

- run `m4p571-p1`(A, 기록 `m4-m68k-probe-p571-20261030.json`): 종료 0, **경고 0**, i386 머리 0, 옵션 차이 없음. 섹션 `__text` 4410(원본 4442)·`__cstring` 226(§571.1 예상과 같음)·`__data` 12(`_cf2_fifo_value` +0·`_cf2_efifo` +4·`_clear_dma_on_int` +8, 외부), `__bss` 없음; COMMON 은 `fd_subr` 과 같은 열네 이름; 원본에 없는 미정의 0; L1 사유는 `__TEXT,__text: unverified` 하나(`__data` 는 맞음).
- **20/22**(`m4-m68k-funcbytes-p571-A-20261030.json`, 대응 일곱). 실기 `otool -tv`(`08_build/artifacts/m4p561/otool/fd_io_A.txt`)와 원본의 비교로 다른 둘:
  - `fc_probe`(610 대 602): `fcp->sczctl = slot_id_bmap + SDC_ADDRS`(0x406c768–0x406c774: `movel _slot_id_bmap,d4; addl #0x2014020,d4`; A 는 `SDC_ADDRS` 상수만).
  - `fc_intr`(304 대 280): FIFO 비우기 고리가 되풀이마다 `dma_chip` 을 다시 봄 — 처음 `i = 0` 에서 `dma_chip == 313` 이면 몸통으로, 아니면 `i > 0` 검사(0x406cd80–0x406cd8c); 몸통 뒤 `i++` 다음 `dma_chip != 313` 이면 그 검사로, 313 이면 `i <= 7` 이면 몸통(0x406cdb4–0x406cdc2) → `for (i = 0; i < ((dma_chip == 313) ? 8 : 1); i++)` 꼴. 그 밖은 레지스터 배정(a3/a2)과, 원본이 `delay` 주소를 고리 안(0x406cd9a)에서 싣는 것(A 는 고리 앞)뿐(§572.1 고침 — 처음엔 레지스터 배정뿐이라고 적었음).
- 판정(미리 정한 대로): 07 은 바꾸지 않고 다음 계획에서 1997 꼴을 시험합니다.

## 572. M4-78 세부 계획 — `fd_io.c` 1997 꼴 진단(07 변경 없음; 코딩 전, 2026-10-30)

방법(명세 `08_build/artifacts/m4p572/spec.json`, run `m4p572-p1`, 바탕 `m0p570-a1-stage`, `m4_id` `m68k-221`, 진단 머리 `sc.h` 는 §571 과 같음):
- 변형 B1(`fd_io_B1.c`): A 에서 둘만 — `fc_probe` 186 행 `fcp->sczctl = (u_char *)SDC_ADDRS;` → `fcp->sczctl = (u_char *)(SLOT_ID_BMAP + SDC_ADDRS);`, `fc_intr` 702 행 `for(i=0; i<8; i++)` → `for(i=0; i<((dma_chip == 313) ? 8 : 1); i++)`.
- 변형 B2: B1 에서 `fc_intr` 고리 조건만 `(dma_chip == 313) ? (i < 8) : (i < 1)` 꼴(§572.1).
- 측정: §571 과 같음(funcbytes, `__data` 12 B 바이트와 원본, 문자열 이 파일 몫 205 B 와 공유 21 B, COMMON, 미정의, 외부 정의 = 원본 이름), B1·B2 canon 비교. 둘 다 22/22 면 두 꼴을 함께 여쭙고, 하나만이면 그 꼴로 정함.
판정(미리 정함; 07 은 바꾸지 않음): 22/22 이고 자료가 원본과 같으면 바이트로 정해지지 않는 것(`slot_id_bmap` 덧셈의 꼴·이름, 진단 이름 덩이의 07 공급 꼴 — `next/cpu.h`·`next/scr.h`·`odreg.h` 이름, `"sc.h"` 의 공급, 지운 `sczfst` 줄의 꼴)을 사용자께 여쭙니다. 남으면 차이를 적고 꼴을 바꿔 다시 시험합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 572.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `fc_probe` 의 차이는 `sczctl` 대입 하나뿐, `d4` 는 뒤에서 다시 쓰이지 않음(다른 지역 변수의 흔적 없음) | §571.2 diff 출력(이번 세션: `fc_probe` 차이는 그 세 명령뿐) | ✅ |
| `fc_intr` 의 흐름(초기 검사·되풀이마다 `dma_chip` 다시 읽기·경계)은 B1 꼴과 뜻이 같음; 같은 명령인지는 컴파일로 | 원본 0x406cd7e–0x406cdc2(이번 세션 읽음) | ✅(바이트는 진단) |
| B2 는 덧셈 차례보다 고리 조건 꼴 `(dma_chip == 313) ? (i < 8) : (i < 1)` 이 더 유익 | 판단 — 덧셈 차례는 같은 바이트일 공산이 크고, 고리 꼴은 컴파일러 출력이 갈릴 수 있음 | ✅ B2 바꿈 |
| 원본은 `delay` 주소를 고리 안에서 실음(0x406cd9a), A 는 고리 앞 — "레지스터 배정뿐" 은 부정확 | §571.2 diff 출력(O 0x406cd9a `lea …,a2` / A 0x81c `lea …,a3`) | ✅ 제 문구 오류. 고침 |
| 나머지 스무 함수는 고칠 것 없음, 크기 차이 8 + 24 = 32 B 로 맞음 | python `4442-4410` = 32, funcbytes 차이 610-602 = 8·304-280 = 24 | ✅ |

### 572.2 결과(2026-10-30)

- run `m4p572-p1`(B1·B2, 기록 `m4-m68k-probe-p572-20261030.json`): 종료 0, 경고 0, i386 머리 0, 옵션 차이 없음. **둘 다 22/22**(`m4-m68k-funcbytes-p572-B1/B2-20261030.json`), L1 `OBJECT_MATCH`(사유 없음), `candidate`, 원본에 없는 이름 0; B1 = B2(canon·`obj_sig`) — 고리 조건의 두 꼴은 같은 객체.
- python 확인(`m4-m68k-p572-checks-20261030.json`, `ok` 참): 섹션 `__text` 4442·`__cstring` 226·`__data` 12; `__data` 바이트가 원본 [0x40b14a6, 0x40b14b2) 과 같음(재배치 0, 세 기호의 자리도 원본과 같음); 문자열 여덟 가운데 이 파일 몫 일곱(205 B)이 원본과 같고 `Bad Controller Phase` 는 공유; 외부 함수 열다섯 = 원본 이름; COMMON 모두 원본 이름; 원본에 없는 미정의 0. B1 SHA `47c86c2e…`.
- `nextdev/odreg.h`(NeXTMach 79 행)는 구조체·매크로뿐이고 include·임시 정의가 없음(grep) — 07 사본으로 들여도 COMMON 이 생기지 않음.
- 판정(미리 정한 대로): 22/22·자료 같음이므로 바이트로 정해지지 않는 것을 여쭙니다. 앞선 결정을 따를 것(묻지 않음): `next/cpu.h`·`next/scr.h` 이름은 파일 안(D113·D121; `P_DISK` 포함), include 줄 OPENSTEP 경로(D104), `sczfst` 대입 줄은 지우고 표시(D128 과 같은 꼴), `slot_id_bmap` 덧셈은 시험한 꼴 `(u_char *)(SLOT_ID_BMAP + SDC_ADDRS)`. 여쭐 것: ① `fc_intr` 고리 조건의 꼴(B1/B2) ② `odreg.h` 의 공급 ③ `"sc.h"` 의 처리.
- 사용자 결정(2026-10-30, AskUserQuestion): ① 고리 조건은 "`i < (dma_chip == 313 ? 8 : 1)`"(B1) ② `odreg.h` 는 "07 NeXTMach 사본"(D104) ③ `"sc.h"` 는 "구성 행 `NSC 1` hypothesis"(NeXTMach include 줄 그대로).

## 573. M4-79 D129 구현 계획 — 07 `src/machdep/m68k/fd_io.c`, `nextmach/nextdev/odreg.h`, 구성 `sc.h`(OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §571–572 결과와 결정. bss 정적이 없어 OBJECT_MATCH 객체(`ACCEPTED` 둘 묶음, §563 과 같은 절차). 07 머리는 새로 두기만 함(받아들인 기록의 plan 506 검사에 영향 없음).
1. 07 `07_kernel/nextmach/nextdev/odreg.h` = NeXTMach `nextdev/odreg.h` 그대로(79 행); 스테이지 `src/bsd/nextdev/odreg.h`(`M4HEADERS[573]`).
2. 구성: `config_options-m68k.tsv` 에 `sc NSC sc.h 1 hypothesis`(여섯 칸; 근거: NeXTMach `conf/files.NeXT` 의 `nextdev/sc.c`, 원본 행 `m68k-236` `nextdev/sc.c` 자리; `fd_io.c` 는 `NSC` 를 쓰지 않음), `gen_config_headers.py --arch m68k` → `07_kernel/v183.34/m68k/generated/sc.h`(`#define NSC 1`), `--check` 둘.
3. 07 `src/machdep/m68k/fd_io.c`(D103) = NeXTMach `nextdev/fd_io.c`(고지·HISTORY 그대로) + 머리 주석 + include 줄(`"fd.h"`·`"sc.h"`·`<nextdev/odreg.h>` 는 그대로; `<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<kern/mach_types.h>` → `<mach/mach_types.h>`, `<next/psl.h>`·`<next/machparam.h>` → `<m68k/…>`(D104), `<next/scr.h>` 는 빼고 표시) + 파일 안 이름(D113·D121: `extern int slot_id, slot_id_bmap;`, `SLOT_ID`·`SLOT_ID_BMAP`·`P_SCSI_CSR`·`P_DISK`·`I`·`I_IPL`·`I_SCSI_DMA`·`I_SCSI`·`I_PHONE`(값 `07_kernel/nextmach/next/cpu.h:96·98·132·155·213·215·228·252·257`)·`NeXT_CUBE` 0(`next/scr.h:34`)) + 1997 본문 셋(표시 plan 573, D129, D024): `fc_probe` 의 `sczctl = (u_char *)(SLOT_ID_BMAP + SDC_ADDRS)`, `sczfst` 대입 줄을 지우고 표시 주석(D128 과 같은 꼴), `fc_intr` 의 `for(i=0; i<((dma_chip == 313) ? 8 : 1); i++)`. 주석 뺀 토큰과 §572 B1 글의 차이는 `"fd.h"`·`"sc.h"` 의 따옴표, `<nextdev/odreg.h>` import 와 B1 의 `OMD_SDFDA` 정의뿐이어야 함(python).
4. `stage_m68k.py`: `M4FILES[573]` = 570 + `fd_io.c`, `M4HEADERS[573]` = 570 + `('nextdev/odreg.h', 'src/bsd/nextdev/odreg.h')`, `EXCEPTS[573] = dict(EXCEPTS[570])`, 머리말 목록에 573.
5. 회귀: 생성 `sc.h` 는 모든 m68k 스테이지에 들어감 → `--plan 570` 재생성(`m0p570-r573-stage`)은 보관본과 `generated/sc.h` 하나만 다름(매니페스트 키 `added`·`files`); `m0p573-a1-stage` 와 보관 570 의 차이는 `generated/sc.h`·`fd_io.c`·`odreg.h`. M5 205 줄(`m3p573-b570`·`m3p573-cc1`): 객체·stderr 같음, `compare` 두 기록 `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로뿐. x86 `m4_x86_inputs.py s6ln`(`L2_FORMS`·`L2_EXPECT`)·`--plan 573 x86gate`·`gen_config_headers.py --check`.
6. (07 파일은 p1 전에 고정) 확인 run `m4p573-p1`(`confirm/spec.json`, 바탕 `m0p573-a1-stage`, 진단 `inc` 없음): F = `@machdep/m68k/fd_io.c`, L = §572 B1 글 그대로(진단 `sc.h` 대신 생성 `sc.h` 를 들임). 종료 0, 경고 0, i386 머리 0, F = L(canon·`obj_sig`), `OBJECT_MATCH`·22/22(`m4-m68k-funcbytes-p573-F/L-20261030.json`); F 와 §572 B1 객체 canon 같음(STABS 차이는 기록). run `m4p573-e1`: F·L `-E` 토큰은 `odreg.h` 가 더하는 `struct od_regs` 선언(NeXTMach `odreg.h:12–72`)만 F 에 더 있고, 그것을 뺀 나머지가 같아야 함(`#` 줄 빼고).
7. 최종 run `m4p573-a1`(명세 `08_build/artifacts/m4p573/spec.json`: F 만, REF = p1 L, `m4_id` `m68k-221`, 경고가 없으므로 `known_warnings` 없음; 기록 `m4-m68k-p573-final-20261030.json`): `gate.ok`, 옵션 차이 없음, 22/22(`m4-m68k-funcbytes-p573-a1-20261030.json`); python 확인 `m4-m68k-p573-checks-20261030.json`: §572 확인 항목(섹션·`__data` 12 B 바이트와 기호 자리·문자열 205 B 와 공유 하나·외부 함수 열다섯·COMMON·미정의), L1 0x406c55c `OBJECT_MATCH` 사유 없음, 의존 목록 i386 0, 입력 사슬: 최종 `-M` 출력의 모든 파일에 대해 매니페스트 출처와 SHA 가 스테이지 = run 이고, 출처가 07 이면 07 파일과도 같음(전수); 그 가운데 `fd_io.c`, 생성 `fd.h`·`sc.h`, `odreg.h`·`fd_vars.h`·`fd_extern.h`·`fd_reg.h`·`sf_access.h`·`nextdev/dma.h`, `dev/m68k/dma.h`, `sys/callout.h`, `dev/busvar.h`, m68k 덮어쓰기 `eventc.h`, SDK `m68k/cpu.h`·`psl.h`·`machparam.h` 는 따로 적음.
8. 상태표: 근거 `06_reconstruction/evidence/m68k-fd_io.md` 를 먼저 쓰고 `ACCEPTED` 에 (최종 기록, SHA) 한 줄; 도구 두 번 실행·§570 표와 이름 대조(더한 것 `fd_io` 뿐). 기대: 정확 행 `m68k-221` 을 덮어 덮은 행 50/188, 바이트 +4442(수치는 도구 출력만).
9. 기록: diff(NeXTMach 대비 `m68k-fd_io.diff`), PROVENANCE 새 행(일곱 칸: `fd_io.c` — 함수별 출처, 파일 안 이름의 출처 `mk-108.1/next/cpu.h:96·98·132·155·213·215·228·252·257`(NeXT·UCB 고지)·`next/scr.h:34`, 파일 SHA, 최종 기록, `M4FILES[573]`; `odreg.h` — `M4HEADERS[573]`; 생성 `sc.h`), MODIFICATIONS, DECISIONS D129, 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: `_nbuf`·`_bufpages`·`_tthiwat`·`_tthog`·`_ttlowat` 합침, 다른 floppy 객체(`fd_cmds`·`fd_driver`·`fd_global`)의 함수·자료.
관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 573.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| F 는 `odreg.h` 의 `struct od_regs` 선언이 `-E` 에 더해지므로 L(B1) 과 `-E` 토큰이 그대로는 같을 수 없음 | NeXTMach `odreg.h:12–14` 읽음(구조체 선언), B1 은 `OMD_SDFDA` 매크로만 | ✅ 제 오류. 6 고침(그 선언만 빼고 비교) |
| 사슬에 `dev/busvar.h`·m68k 덮어쓰기 `eventc.h` 가 빠짐; 손으로 쓴 목록은 전수가 아님(`sys/kernel.h` 등) | §570 확인 기록의 사슬(같은 둘이 있음) | ✅ 7 고침(`-M` 출력 전수 대조 + 주요 파일 따로) |
| PROVENANCE 에 파일 안 이름의 출처(`next/cpu.h` 줄·고지, `next/scr.h:34`) | §563 `snd_dspdev.c` 행 꼴 | ✅ 9 고침 |
| 스테이징 선택·`EXCEPTS[573]`·생성 `sc.h` 가 다른 `sc.h` 와 겹치지 않음·`"fd.h"`/`"sc.h"` 는 `-Isrc/generated` 로 풀림·`OMD_SDFDA` 는 07 이름 덩이에 두지 않음·`known_warnings` 없음 | §570 의 `-E` 증거(`"fd.h"` → `src/generated/fd.h`), 계획 3 의 꼴 | ✅ 그대로 |

### 573.2 결과(2026-10-30)

- 1·2: 07 `nextmach/nextdev/odreg.h`(NeXTMach 그대로, SHA `acb635c0…`), `config_options-m68k.tsv` 16 → 17 행(`sc NSC sc.h 1 hypothesis`, 여섯 칸), 생성 `sc.h`(`#define NSC 1`, SHA `faa2d84d…`), `--check` 둘 종료 0.
- 3: 07 `src/machdep/m68k/fd_io.c`(1336 행, SHA `2d30b500…`): 주석 뺀 토큰이 §572 B1 과 `"fd.h"`·`"sc.h"` 의 따옴표, `<nextdev/odreg.h>` import, B1 의 `OMD_SDFDA` 정의만 다름(python). 처음 생성본은 이름 덩이를 include 끝에 두어 B1 과 차례가 달랐으므로 시험한 차례(`<m68k/cpu.h>` 바로 뒤)로 옮겨 다시 만듦. diff `m68k-fd_io.diff`(75 행).
- 4: `stage_m68k.py` 687 → 690 행(`M4FILES[573]`·`M4HEADERS[573]`·`EXCEPTS[573]`·머리말 목록).
- 5: `--plan 570` 재생성(`m0p570-r573-stage`)은 보관본과 `generated/sc.h` 하나만 다름; `m0p573-a1-stage`(955 파일)와 보관 570 의 차이는 `generated/sc.h`·`odreg.h`·`fd_io.c`. M5: `m5-570.cmd` 가 §570 것과 `cmp` 같음, run `m3p573-b570`·`m3p573-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p573-compare-20261030.json`, `-b570-`) `differ_unexpected`·`lost` 빔, 요약 차이는 새 경로 셋뿐. x86 `m4-x86-inputs-p573-20261030.json` `ok`, `--plan 573 x86gate` 일곱 같음·`v183_paths` 0.
- 6: run `m4p573-p1`: F·L 종료 0·경고 0·OBJECT_MATCH, F = L canon·머리·섹션·기호 같으나 STABS 1584 대 1578(F 만 `odreg.h` 의 `struct od_regs` 형을 가짐) — 최종 관문의 REF 비교(`obj_sig` 전체)를 통과할 수 없어 계획에서 벗어나 run `m4p573-p2` 를 더함: L2 = B1 글에서 진단 `OMD_SDFDA` 줄을 빼고 `#import <nextdev/odreg.h>` 를 둔 꼴(07 파일과 같은 머리 집합). F = L2(canon·`obj_sig` 모든 칸, STABS 1584), L2 = B1(canon), p1·p2 의 F 객체 바이트 같음, 22/22(`m4-m68k-funcbytes-p573-F/L2-20261030.json`). run `m4p573-e1`: F·L2 `-E` 토큰 20012 개 같음(§573.1 의 "`od_regs` 만 빼고 비교" 대신 L2 와 바로 같음을 봄), `fd.h`·`sc.h`·`odreg.h` 를 들임, i386 0.
- 7: run `m4p573-a1`(`m4-m68k-p573-final-20261030.json`, SHA `1abd0cc6…`; REF = L2, `known_warnings` 없음): `gate.ok`, 옵션 차이 없음, 22/22(`m4-m68k-funcbytes-p573-a1-20261030.json`); 확인 `m4-m68k-p573-checks-20261030.json`(`ok` 참): 섹션·`__data` 12 B 와 기호 자리·문자열 205 B·외부 함수 열다섯·COMMON·미정의 원본과 맞음, L1 0x406c55c OBJECT_MATCH 사유 없음, 의존 161 파일 전수 사슬 문제 0·i386 0(주요 열여섯은 출처별로 기록). 객체 SHA `92ca6548…`.
- 8: 근거 `06_reconstruction/evidence/m68k-fd_io.md`(상태 도구 전). `ACCEPTED` 에 둘 묶음 한 줄. 상태표 31 → 32 행·`m4-m68k-status-p573-20261030.json`: 30 객체(OBJECT_MATCH 23, CODE+BSS_INFERRED 7), 덮은 행 50/188, 50466/215874 B(23.38%; python, +4442 B), `object_bytes` 64654, 두 번 실행 같음, §570 표와 이름 대조로 더한 것 `fd_io` 뿐·바뀐 것 없음.
- 9: PROVENANCE 1164 → 1167 행(일곱 칸), MODIFICATIONS 709 → 712 행, DECISIONS D129(132 → 133 행), "현재 상태와 다음 일" 고침.

## 574. M4-80 세부 계획 — m68k `fd_driver.c`(행 220) 첫 작성본 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션, python): floppy 묶음의 정확 행 가운데 남은 것. 원본 12 항목 가운데 11 개가 NeXTMach mk-108.1 `nextdev/fd_driver.c`(1114 행, SHA-256 `ba50ecd5…`)의 정의 11 개와 같은 차례이고, `_fdsize`(0x406ba5a, 70 B)만 NeXTMach 에 없음(참고 트리의 `fdsize` 는 Mach4 i386 `fd.c` 의 빈 함수뿐, grep). §570·§573 의 07 머리를 그대로 씀.

확인한 사실(이번 세션; 원본 목록 135903–137167 행(주소 붙은 줄 1255, 안쪽 라벨 10), 기호표, 원본 `__cstring`, python):
- 행 `m68k-220`(정확) [0x406b546, 0x406c55c), 4118 B, 12 항목: `fd_slave` 420, `fd_attach` 242, `fd_attach_com` 638, `fdsize` 70, `fdopen` 274, `fdclose` 166, `fdread` 136, `fdwrite` 134, 이름 없는 0x406bd66 30(NeXTMach 정적 `fdminphys`, 588 행; 원본에서 주소로 둘 쓰임 — `physio` 인자), `fdstrategy` 376, `fdioctl` 1428, `fd_command` 204. `fdsize` 는 `fd_attach_com` 과 `fdopen` 사이.
- `fdsize`([0x406ba5a, 0x406baa0)): `volume = FD_VOLUME(dev)`(`bfextu` 로 minor 의 위 5 비트), `fvp = fd_volume_p[volume]`(0x40c3738) 를 먼저 읽음; `volume == 8`(`FVP_CONTROLLER`) 이면 0; `8 < volume` 이거나 `fvp == NULL` 이면 -1; `fvp+0x179` 비트 1(`format_info.flags` 의 `FFI_LABELVALID` 0x2, 07 `fd_extern.h:655`)이 꺼져 있으면 `fvp+0x186`(`format_info.sectsize_info.sect_size`), 켜져 있으면 `fvp->labelp`(+0x14)의 +0x5c(`dl_secsize`, 스테이지 `dev/disk_label.h`; §568 `fd_setbratio` 와 같은 오프셋)를 돌려줌. 07 `fd_vars.h:302–321`(`NUM_FV` 8, `FVP_CONTROLLER`, `FD_VOLUME`), NeXTMach `fdopen`(409–420 행)의 같은 꼴. 스테이지 `sys/conf.h:45` 의 `bdevsw` 에 `d_psize` 자리가 있음.
- 자료: 이 파일이 정의하는 자료 없음(NeXTMach 에도 없음; `extern int nchrdev, nblkdev;`), `__bss` 참조 없음. 문자열 12 개, [0x40aa0d8, 0x40aa1d7) 255 B 가 이어짐(앞은 `fd_cmds` 의 `: DMA byte count > 64K\n`, 뒤는 `fc`·`fd`·`FDR_VOLUNAVAIL` 등 다른 객체).
- 부르는 것(원본): `fd_*`(subr) 여럿, `copyinmsg`·`copyoutmsg` 3 씩, `disksort_enter`·`_head`·`_tail`, `physio` 2, `suser` 2, `lock_write`·`lock_done` 2 씩, `checksum_16`, `sdchecklabel`, `kalloc` 2, `kfree`, `sleep`, `wakeup`, `printf` 6(바로 4 + `jsr a2@` 2, 0x406ba08·0x406ba34), `sprintf`, `strcat`, `update`, `volume_notify`, `biodone`, `biowait`, `pmap_kernel`. 자료: `_bdevsw`·`_cdevsw`·`_nblkdev`·`_nchrdev`·`_fd_*`·`_active_u`·`_eventc_*`(pmon 시각)·`_event_high/middle`.
- 원본에 이미 보이는 1997 바뀜(진단 해석용; §574.1): `fd_attach_com` 이 라벨을 못 읽으면 `fd: UNABLE TO READ DISK LABEL` 을 찍지 않음(0x406b9ec 가 출력 덩이를 건너뜀; NeXTMach 402–403), `fdclose` 의 `fvp == NULL` 검사(0x406bbe0), `fdread`·`fdwrite` 는 live 파티션이 아니면 `FFI_LABELVALID` 일 때만 `labelp->dl_secsize`, 아니면 `ENXIO`(0x406bc7c–0x406bc9e; NeXTMach 556·582 행 `DEV_BSIZE`), `fdstrategy` 의 볼륨·NULL 검사가 `labelp` 읽기 앞(0x406bdaa–0x406bdb4), `fdioctl` 의 `fvp == NULL` 검사가 첫 `switch` 앞(0x406bf20), `fdioctl` 의 새 갈래 셋(0x406c298–0x406c2b0: `format_info.flags & 1`, `sect_size`, +0x192 — 스테이지 `dev/disk.h:125–127` 의 `DKIOCGFORMAT`·`DKIOCBLKSIZE`·`DKIOCNUMBLKS` 로 보임), `FDIOCREQ` 의 맞춤 할당(진단에서 확인). `FDIOCRRW` 의 `if(!flags & FFI_FORMATTED)`(1008 행)는 원본도 같은 꼴(고치지 말 것).
- 머리: NeXTMach 은 `"fd.h"`, `<sys/types.h>`, `<sys/uio.h>`, `<sys/buf.h>`, `<kern/queue.h>`, `<sys/errno.h>`, `<sys/user.h>`, `<sys/dk.h>`, `<sys/fcntl.h>`, `<nextdev/disk.h>`, `<next/psl.h>`, `<next/cpu.h>`(이 파일이 쓰는 `next/cpu.h` 이름 없음 — grep), `<next/pmon.h>`·`pmon_targets.h`·`kernel_pmon.h`(§570 07), `<sys/conf.h>`, `<nextdev/fd_extern.h>`·`fd_vars.h`(§570 07)를 들임.

방법(진단; 명세 `08_build/artifacts/m4p574/spec.json`, run `m4p574-p1`, 바탕 `m0p573-a1-stage`, `m4_id` `m68k-220`, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- 변형 A1(`fd_driver_A1.c`): NeXTMach 글에서 include 줄만 — `"fd.h"` → `<fd.h>`(진단 소스), `<nextdev/disk.h>` → `<dev/disk.h>`, `<next/psl.h>` → `<m68k/psl.h>`, `<next/cpu.h>` → `<m68k/cpu.h>`, 진단 `#define DEV_BSIZE 1024`(1997 머리 `sys/param.h` 의 `#if NeXT` 갈래에 없음 — 556·582 행; §567 A2 와 같은 방식) — 그리고 `fd_attach_com` 과 `fdopen` 사이에 바이트로 쓴 첫 작성본 `int fdsize(dev_t dev) { int volume = FD_VOLUME(dev); fd_volume_t fvp = fd_volume_p[volume]; if(volume == FVP_CONTROLLER) return(0); if((volume > FVP_CONTROLLER) || (fvp == NULL)) return(-1); if(fvp->format_info.flags & FFI_LABELVALID) return(fvp->labelp->dl_secsize); else return(fvp->format_info.sectsize_info.sect_size); }`(진단 표시).
- 변형 A2: A1 에서 마지막 `if` 만 `if(!(fvp->format_info.flags & FFI_LABELVALID)) return(sect_size); return(labelp->dl_secsize);` 차례(원본 분기 차례에 더 가까운 꼴).
- 측정: `m4_m68k_probe.py compare`(경고 기록), `m68k_funcbytes.py 406b546 406c55c OBJECT.o RECORD.json 406bd66=_fdminphys`; 섹션(`__text` 4118 은 원본 크기)·`__cstring` 바이트(255 B)와 원본, 정의 기호(외부 함수 열하나 = 원본 이름), COMMON, 원본에 없는 미정의. 다른 함수는 실기 `otool -tv` 비교.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고 다음 계획에서 1997 꼴을 시험합니다. 컴파일이 안 되면 원인을 적고 최소로 고친 꼴로 다시 돌립니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 574.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A1 은 `DEV_BSIZE`(556·582 행) 때문에 컴파일되지 않음(1997 `sys/param.h` 의 `#if NeXT` 갈래에 없음) | NeXTMach grep(556·582), §567.2 에서 같은 원인 확인 | ✅ 제 누락. 진단 정의 한 줄을 더함 |
| 원본에 이미 보이는 1997 바뀜 일곱(`fd_attach_com` 출력 빠짐, `fdclose`·`fdstrategy`·`fdioctl` 의 NULL 검사, `fdread`/`fdwrite` 의 블록 크기, 새 `DKIOC*` 갈래, `FDIOCREQ` 맞춤 할당) | 원본 136253–136281·136410–136422·136464–136482·136555–136566·136676–136684·136938–136950 행 읽음, NeXTMach 398–406·500–514·548–560 행 읽음; `FDIOCREQ` 는 아직 안 읽음 | ✅ 여섯은 확인해 사실 줄에 더함, `FDIOCREQ` 는 ⏭️ 진단으로 |
| `printf` 는 6 곳(`jsr a2@` 2) | 원본 0x406ba02–0x406ba34 읽음 | ✅ 고침 |
| `fdsize` 해석·오프셋·두 초안의 뜻은 맞음; 끝은 0x406baa0(배타), `disk_label` 은 `dev/disk_label.h` | 원본 0x406ba5a–0x406ba9e(이번 세션), 함수 표 70 B | ✅ 문구 고침 |
| `FDIOCRRW` 의 `!flags & FFI_FORMATTED` 는 원본도 같은 꼴 | 원본 0x406c3ae 부근(제가 아직 안 읽음) | ⏭️ 진단 바이트로 확인 |
| `fd_attach_com`·`fdminphys`·`fd_init_notify` 의 연결은 문제 없음; COMMON 은 `fd_subr` 과 같은 열네; 경고는 `kfree` 둘(994·1040 행) 정도 | — | ⏭️ 진단 결과로 확인 |
| A1 의 `__cstring` 은 NeXTMach 의 `UNABLE TO READ DISK LABEL` 31 B 가 더해 286 B 로 예상 | python `255 + 31` | ⏭️ 진단 결과로 확인 |

### 574.2 결과(run `m4p574-p1`, 2026-10-30)

- 컴파일: A1·A2 모두 종료 0, i386 머리 0, 경고 둘씩(`fdioctl` 의 `kfree` 첫 인자 포인터→정수, A1 1011·1057 행). 진단 관문 `commands_ok` 는 거짓(경고를 `known_warnings` 에 두지 않았기 때문; 기록 `09_validation/reconstruction/m4-m68k-probe-p574-20261030.json`).
- `__text` 3978 B(원본 4118, python 차 140), `__cstring` 286 B(255 + `fd: UNABLE TO READ DISK LABEL\n` 31, 예상과 같음). 외부 함수 열하나 = 원본 이름, 원본에 없는 미정의 없음.
- 함수별(`m4-m68k-funcbytes-p574-A1/A2-20261030.json`): A1 6/12 같음 — `fd_slave`, `fd_attach`, `fdsize`(첫 작성본 그대로 같음), `fdopen`, `fdminphys`, `fd_command`. A2 는 5/12(`fdsize` 13 바이트 다름 — A2 의 분기 차례는 버림).
- 다른 여섯(원본/A1 크기, python 차): `fd_attach_com` 638/656(-18), `fdclose` 166/162(+4), `fdread` 136/110(+26), `fdwrite` 134/108(+26), `fdstrategy` 376/372(+4), `fdioctl` 1428/1330(+98); 합 140 = `__text` 차.
- 다른 곳을 원본 목록(`otool-V10/image.txt`)과 A1 목록(`m4p561/otool/fd_driver_A1.txt`)으로 읽은 1997 꼴(이번 세션):
  - `fd_attach_com`: `fd_get_label` 이 0 이 아니면 0x406b9ec `bne 0x406ba3a` 로 `FFI_WRITEPROTECT` 검사로 곧장 감 — NeXTMach 402–403 행의 `else printf("fd: UNABLE TO READ DISK LABEL\n");` 이 없음.
  - `fdclose`: `volume == 8` 이면 0; `8 < volume` 이면 0x406bbe4 `ENXIO`; 이어 `tstl a2`(fvp) 가 0 이면 같은 `ENXIO`(0x406bbe0–0x406bbe2).
  - `fdread`·`fdwrite`(같은 꼴): `7 < volume` 또는 `fvp == NULL` 이면 `ENXIO`(NeXTMach 그대로); live 파티션(`dev & 7 == 1`)이면 `sect_size`(+0x186), 아니면 `format_info.flags`(+0x176 의 낱말, `btst` 는 그 낮은 바이트 +0x179 의 비트 1)의 `FFI_LABELVALID` 가 켜져 있을 때 `labelp->dl_secsize`(+0x14 → +0x5c), 꺼져 있으면 `ENXIO`(0x406bc7c–0x406bca2). NeXTMach 의 `DEV_BSIZE` 가 없어짐. `physio` 의 `&fd_volume_p[volume]->rio_buf` 는 원본에서 배열을 다시 읽음(0x406bcb6–0x406bcc0, NeXTMach 글 그대로).
  - `fdstrategy`: `rtn = 0` 다음 `10 < volume` 이거나 `fvp == NULL` 이면 0x406be0e(`b_error = 6`, `bad`); 그 뒤에 `labelp` 를 읽음(0x406bdb4) — NeXTMach 은 선언에서 `dlp = fvp->labelp` 를 먼저 읽고 `fvp` 검사는 `ASSERT` 뿐.
  - `fdioctl`: (1) 첫 `switch` 앞에서 `fvp == NULL` 이면 `ENXIO`(0x406bf20–0x406bf22; `cp = *(caddr_t *)data`, `error = 0` 다음). (2) 새 갈래 셋, 몸은 `FDIOCGFORM`(0x406c276) 다음 `DKIOCEJECT`(0x406c2b4) 앞에 이 차례: 0x40046417 → `*(int *)data = format_info.flags & 1`(0x406c298), 0x40046418 → `sect_size`(+0x186, 0x406c2a4), 0x40046419 → +0x192(0x406c2ac; `DKIOCINFO` 의 `sprintf` 인자 `total_sects` 와 같은 자리). python: `_IOR('d',23/24/25,int)` = 0x40046417/18/19, 스테이지 `dev/disk.h` 의 `DKIOCGFORMAT`·`DKIOCBLKSIZE`·`DKIOCNUMBLKS`; `fd_format_info` 는 +0x168 에서 46 B(`FDIOCGFORM` 의 크기 0x2e), `flags` +14, `sect_size` +30, `total_sects` +42. (3) `FDIOCREQ`([0x406c310, 0x406c3c4)): `kalloc(byte_count + 16)` 결과(d2)와 `(d2 + 15) & ~15`(d5)를 따로 둠; 결과 0 검사는 맞춤 계산 다음(0x406c338); `kalloc` 인자는 `byte_count` 를 a5 로 옮겨 `pea a5@(0x10)`(0x406c320–0x406c322), 끝의 크기도 `pea a0@(0x10)`(0x406c3bc); `copyin`·`fdiop->addrs`·`copyout` 은 d5, 끝의 `kfree` 는 d2 와 `byte_count + 16`(0x406c3b2–0x406c3c0 → 0x406c464). 1997 머리 `dev/m68k/dma.h:31·37–39` 의 `DMA_BEGINALIGNMENT` 16·`DMA_BEGINALIGN` 이 이 계산과 같음. (4) `FDIOCRRW` 는 NeXTMach 그대로(`kfree(ap, byte_count)`, `!flags & FFI_FORMATTED` 는 `tstl` 한 번, 0x406c3d0), `FDIOCREQ`·`FDIOCRRW` 에 `suser` 없음(NeXTMach 35 행 `FD_ALLOW_IOC 1` 그대로). 나머지 차이는 레지스터 번호(d5→d6, 저장 레지스터 7→9 개, 틀 24 B 같음)와 비교 나무.
  - §574.1 의 ⏭️ 셋: `FDIOCRRW` 꼴 — 위 (4)로 확인; COMMON·연결 — 원본에 없는 미정의 0; 경고 — `kfree` 둘(1011·1057 행).

## 575. M4-81 세부 계획 — m68k `fd_driver.c` 1997 꼴 진단 B(07 변경 없음; 코딩 전, 2026-10-30)

방법(진단; 명세 `08_build/artifacts/m4p575/spec.json`, run `m4p575-p1`, 바탕 `m0p573-a1-stage`, `m4_id` `m68k-220`, 컴파일 줄 틀 `machdep/i386/dkbad.c`; 소스는 scratchpad `gen_p575.py` 가 A1 에서 만듦):
- 변형 B1(`fd_driver_B1.c`, SHA-256 `c5c22f8a…`): A1 에서 진단 `DEV_BSIZE` 줄을 빼고 §574.2 의 1997 꼴을 넣음 —
  - `fd_attach_com`: `else printf("fd: UNABLE TO READ DISK LABEL\n");` 두 줄을 뺌.
  - `fdclose`: `if(volume > FVP_CONTROLLER) return(ENXIO);` 다음에 `if(fvp == NULL) return(ENXIO);`(NeXTMach `fdread` 와 같은 꼴).
  - `fdread`·`fdwrite`: `else blocksize = DEV_BSIZE;` → `else if(fvp->format_info.flags & FFI_LABELVALID) blocksize = fvp->labelp->dl_secsize; else return(ENXIO);`.
  - `fdstrategy`: `struct disk_label *dlp;`(초기값 없음), `if ((volume > NUM_FVP) || (fvp == NULL)) {`(몸 그대로), `ASSERT(fvp != NULL);` 다음에 `dlp = fvp->labelp;`.
  - `fdioctl`: `caddr_t alloc_p;` 를 `caddr_t ap;` 다음에 선언; `XCDBG` 다음에 `if(fvp == NULL) return(ENXIO);`; `FDIOCGFORM` 다음에 `case DKIOCGFORMAT: *(int *)data = fvp->format_info.flags & FFI_FORMATTED; break;`, `case DKIOCBLKSIZE: … sectsize_info.sect_size; break;`, `case DKIOCNUMBLKS: … total_sects; break;`; `FDIOCREQ` 는 `alloc_p = (caddr_t)kalloc(fdiop->byte_count + DMA_BEGINALIGNMENT); ap = DMA_BEGINALIGN(caddr_t, alloc_p); if(alloc_p == 0) {…}`, 끝 `kfree(alloc_p, fdiop->byte_count + DMA_BEGINALIGNMENT);`(`ap` 는 그대로 DMA 버퍼).
- 변형 B2(`3aac13dd…`): B1 에서 `FDIOCREQ` 의 두 변수 역할만 바꿈(`ap` = `kalloc` 결과, `alloc_p` = 맞춘 버퍼; `copyin`·`addrs`·`copyout` 은 `alloc_p`, `kfree(ap, …)`) — 레지스터 배정(d2/d5)이 어느 쪽에서 원본과 같은지 봄.
- 변형 B3(`bfe0e13f…`): B1 에서 바이트로 가를 수 없을 수 있는 다른 꼴 셋 — `fdclose` 는 `if((volume > FVP_CONTROLLER) || (fvp == NULL))` 한 줄, `fdread`·`fdwrite` 는 `else { if(!(… & FFI_LABELVALID)) return(ENXIO); blocksize = …; }`, `fdstrategy` 는 `volume` 검사 뒤 따로 `if (fvp == NULL) { bp->b_error = ENXIO; goto bad; }`. 한 함수에 바뀜 하나씩이라 함수별로 가를 수 있음.
- `fdsize` 는 A1 꼴(6/12 에서 같음). 이름 `alloc_p` 는 바이트에 없음(프로젝트가 고른 이름; 원본에 지역 기호 없음).
- 측정: §574 와 같음(`m4_m68k_probe.py compare`, `m68k_funcbytes.py 406b546 406c55c OBJECT.o RECORD.json 406bd66=_fdminphys`, 섹션·`__cstring` 바이트 255 B 와 원본, 외부 함수·COMMON·미정의); 다르면 실기 `otool -tv` 로 함수 비교.
판정(미리 정함; 07 은 바꾸지 않음): 12/12 이고 `__text` 4118·`__cstring` 원본과 같은 변형이 있으면 그 꼴로 07 구현 계획(§576)을 씁니다. 같은 결과의 꼴이 여럿이면 사용자 결정으로 묻습니다. 12/12 가 아니면 다른 함수를 읽고 다음 진단을 계획합니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록(A1 과 같은 `kfree` 둘이 예상).

### 575.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §574.2 의 1997 꼴(`fd_attach_com`, `fdclose`, `fdread`/`fdwrite`, `fdstrategy`, `fdioctl` (1)–(4))은 원본과 맞음 | 원본 0x406b9a0–0x406ba58, 0x406bbb2–0x406bcde, 0x406bd84–0x406bdcc, 0x406befc–0x406c48e 를 이번 세션에 읽고 A1 과 함수 diff | ✅ (제 확인과 같음) |
| `flags` 낱말은 +0x176, +0x179 는 `btst` 가 보는 낮은 바이트 | `fd_format_info` +0x168 + `flags` 14 = 0x176(python, §574.2), 원본 0x406c29a `andl a4@(0x176)` | ✅ 문구 고침 |
| `kalloc` 인자에서 `byte_count` 를 a5 로 옮겨 `pea a5@(0x10)` 하는 것을 적지 않음; B 셋 모두 이것을 낼 수 있음 | 원본 0x406c320–0x406c322·0x406c3bc 읽음 | ⚖️ 사실은 적음; B 가 같은 레지스터를 내는지는 진단 결과로 확인 |
| B1/B2/B3 의 바뀜은 §575 에 적은 것뿐(나머지는 주석) | `diff` A1–B1, B1–B2, B1–B3(이번 세션 출력) | ✅ |
| 새 이름이 보임: `dev/disk.h:125–127`, `fd_vars.h:33` → `nextdev/dma.h:49` → `dev/m68k/dma.h:31·37–39`; `kfree` 경고는 B1 1032·1078 행 | 각 줄을 엶(`fd_vars.h:33` `#import <nextdev/dma.h>`, `dma.h:49` `#import <dev/m68k/dma.h>`, 스테이지 `kern/kalloc.h:62` `kfree(vm_offset_t …`), B1 789·994–996·1032·1078 행 | ✅ |
| `FDIOCREQ` 범위 끝 0x406c3c2 는 0x406c3c0 의 `bra …:w`(4 B) 안 — [0x406c310, 0x406c3c4) | 원본 목록 0x406bffa `beq 0x406c3c4:w`(`FDIOCRRW` 시작), 0x406c3c0 `bra 0x406c464:w` | ✅ 제 오기, 고침 |
| funcbytes 기록의 `"plan": 521` 은 낡은 값 | `m68k_funcbytes.py:218` `rec = dict(plan=521, …` | ✅ 사실(도구 상수; 계산에 쓰이지 않음, 바꾸지 않음) |

### 575.2 결과(run `m4p575-p1`, 2026-10-30)

- 컴파일: B1·B2·B3 모두 종료 0, i386 머리 0, 옵션 = M5 줄, 경고 둘씩(`fdioctl` 의 `kfree` 첫 인자 포인터→정수; B1·B2 1032·1078 행, B3 1036·1082 행). `commands_ok` 거짓은 §574.2 와 같은 까닭(경고가 `known_warnings` 에 없음). 기록 `09_validation/reconstruction/m4-m68k-probe-p575-20261030.json`.
- B2: `__text` 4118(원본과 같음), `__cstring` 255 B 이고 바이트가 원본 [0x40aa0d8, 0x40aa1d7) 과 같음(python), COMMON 14, 원본에 없는 미정의 없음, L1 `OBJECT_MATCH`(이유 없음), 함수별 12/12(`m4-m68k-funcbytes-p575-B2-20261030.json`).
- B1·B3: `__text` 4126, 11/12 — `fdioctl` 만 1436 B(원본 1428; `FDIOCREQ` 에서 `kalloc` 결과를 맞춘 버퍼 변수로 쓴 꼴). B1 = B3(canon 같음): `fdclose`·`fdread`·`fdwrite`·`fdstrategy` 의 두 꼴은 바이트로 가를 수 없음.
- 그래서 1997 `FDIOCREQ` 는 `ap = (caddr_t)kalloc(fdiop->byte_count + DMA_BEGINALIGNMENT);` 를 받고 다른 변수에 `DMA_BEGINALIGN(caddr_t, ap)` 을 두어 `copyin`·`fdiop->addrs`·`copyout` 에 쓰며 `kfree(ap, fdiop->byte_count + DMA_BEGINALIGNMENT)` 로 돌려줌(B2). 맞춘 버퍼 변수의 이름은 바이트에 없음. 원본의 a5·`pea a5@(0x10)` 도 B2 가 그대로 냄(12/12).
- 남은 선택(바이트로 가를 수 없음; 사용자 결정): `fdclose`·`fdread`/`fdwrite`·`fdstrategy` 를 B1 꼴로 할지 B3 꼴로 할지, 맞춘 버퍼 변수의 이름, 맞춤을 `DMA_BEGINALIGN`/`DMA_BEGINALIGNMENT` 로 쓸지(시험함) 숫자 16 으로 쓸지(시험 안 함).

## 576. M4-82 D130 구현 계획 — 07 `src/machdep/m68k/fd_driver.c`(OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §574–575 결과와 사용자 결정(D130): `fdclose`·`fdread`/`fdwrite`·`fdstrategy` 는 B1 꼴, `FDIOCREQ` 는 B2 의 역할(`ap` = `kalloc` 결과)에 `DMA_BEGINALIGN`/`DMA_BEGINALIGNMENT` 매크로, 맞춘 버퍼 변수 이름은 `aligned_ap`. bss 가 없어 OBJECT_MATCH 객체(`ACCEPTED` 둘 묶음, §573 과 같은 절차). 새 07 머리·구성 행 없음(생성 `fd.h` 는 §570 것) — 받아들인 기록의 plan 506 검사에 영향 없음.
1. 07 `src/machdep/m68k/fd_driver.c`(D103) = NeXTMach `nextdev/fd_driver.c`(고지·HISTORY 그대로, D013) + 머리 주석(1997 바뀜 목록과 근거) + include 줄(`"fd.h"`·`<next/pmon.h>`·`<next/pmon_targets.h>`·`<next/kernel_pmon.h>`·`<nextdev/fd_extern.h>`·`<nextdev/fd_vars.h>` 는 그대로 — §570 의 07 사본이 그 경로에 스테이지됨; `<nextdev/disk.h>` → `<dev/disk.h>`, `<next/psl.h>` → `<m68k/psl.h>`(D104), `<next/cpu.h>` → `<m68k/cpu.h>`(D110; 이 파일은 그 이름을 쓰지 않음)) + 1997 본문(표시 plan 576, D130, D024): `fdsize`(바이트로 쓴 새 함수, `fd_attach_com` 과 `fdopen` 사이), `fd_attach_com` 의 `else printf(…)` 두 줄을 지우고 표시 주석, `fdclose`·`fdread`·`fdwrite`·`fdstrategy`·`fdioctl` 의 B1/B2 꼴(§575). 진단 문구는 뺌. 주석 뺀 토큰과 §575 B2 글의 차이는 `"fd.h"` 의 따옴표와 이름 `alloc_p` → `aligned_ap` 뿐이어야 함(python).
2. `stage_m68k.py`: `M4FILES[576]` = 573 + `fd_driver.c`, `EXCEPTS[576] = dict(EXCEPTS[573])`, 머리말 plan 목록에 576; `M4HEADERS`·`X86` 은 그대로(576 은 573 의 것과 s6ln).
3. 회귀: `--plan 573` 재생성(`m0p573-r576-stage`)이 보관 `m0p573-a1-stage` 와 모든 키가 같음; `m0p576-a1-stage` 와 보관 573 의 차이는 `src/machdep/m68k/fd_driver.c` 하나(python assert). M5 205 줄: `m5-573.cmd` 가 §573 것과 `cmp` 같음, run `m3p576-b573`(보관 573 스테이지)·`m3p576-cc1`(576 스테이지) 객체 205 바이트 같음·stderr 205 같음, `compare` 두 기록의 `differ_unexpected`·`lost` 빔, 요약은 `stage_vs_test_stage` 에 `src/machdep/m68k/fd_driver.c` 가 더해진 것 말고 같음. x86 `m4_x86_inputs.py s6ln`(환경 변수 `L2_FORMS`·`L2_EXPECT`)·`--plan 576 x86gate` 일곱 같음.
4. (07 파일은 p1 전에 고정) 확인 run `m4p576-p1`(`08_build/artifacts/m4p576/confirm/spec.json`, 바탕 `m0p576-a1-stage`, 진단 `inc` 없음): F = `@machdep/m68k/fd_driver.c`, L = §575 B2 글 그대로. 종료 0, 경고는 `kfree` 둘(함수 문맥 줄 포함 세 줄)씩, i386 머리 0, F = L(canon·`obj_sig` 모든 칸 — 실제 비교로 확인; 지역 변수 이름은 `obj_sig` 에 들지 않음), `OBJECT_MATCH`·12/12(`m4-m68k-funcbytes-p576-F/L-20261030.json`). run `m4p576-e1`: F·L 의 `-E` 토큰은 `alloc_p`/`aligned_ap` 자리만 다르고(`#` 줄 빼고) 둘 다 `src/generated/fd.h` 를 들임.
5. 최종 run `m4p576-a1`(명세 `08_build/artifacts/m4p576/spec.json`: F 만, REF = p1 L, `m4_id` `m68k-220`, `refs["fd_driver"]` = [p1 L 객체, SHA-256], `known_warnings["fd_driver"]` = p1 F 의 stderr 줄 그대로(경로·행 번호 포함); 기록 `m4-m68k-p576-final-20261030.json`): `gate.ok`, 옵션 차이 없음, 12/12(`m68k_funcbytes.py 406b546 406c55c … 406bd66=_fdminphys`, `m4-m68k-funcbytes-p576-a1-20261030.json`); python 확인 `m4-m68k-p576-checks-20261030.json`: 섹션(`__text` 4118, `__cstring` 255, `__data`·`__bss` 없음), 문자열 255 B 가 원본 [0x40aa0d8, 0x40aa1d7) 과 같음, 외부 함수 열하나 = 원본 이름(`fdminphys` 는 지역), COMMON 이름이 원본에 있음, 원본에 없는 미정의 없음, L1 0x406b546 `OBJECT_MATCH` 사유 없음, 의존 목록 i386 0, 입력 사슬: 최종 `-M` 출력의 모든 파일에 대해 매니페스트 출처와 SHA 가 스테이지 = run 이고, 출처가 07 이면 07 파일과도 같음(전수); 주요 파일(`fd_driver.c`, 생성 `fd.h`, `fd_vars.h`·`fd_extern.h`·`fd_reg.h`·`sf_access.h`·`nextdev/dma.h`, `dev/m68k/dma.h`, `dev/disk.h`, pmon 머리 넷)은 따로 적음.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-fd_driver.md` 를 먼저 쓰고 `ACCEPTED` 에 (최종 기록, SHA) 한 줄; 도구 두 번 실행·§573 표와 이름 대조(더한 것 `fd_driver` 뿐). 기대: 정확 행 `m68k-220` 을 덮어 덮은 행 51/188, 바이트 +4118(수치는 도구 출력만).
7. 기록: diff(NeXTMach 대비 `m68k-fd_driver.diff`), PROVENANCE 새 행(일곱 칸: NeXTMach 저장소·커밋 `f6bdb9c3…`·`mk-108.1/nextdev/fd_driver.c`, 고지(D013), 함수별로 NeXTMach 그대로 다섯(`fd_slave`·`fd_attach`·`fdopen`·`fdminphys`·`fd_command`)·바이트로 고친 여섯·바이트로 쓴 `fdsize`(D024, 프로젝트 작성), 파일 SHA·최종 기록·`M4FILES[576]`), MODIFICATIONS, DECISIONS D130, 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: `_nbuf`·`_bufpages`·`_tthiwat`·`_tthog`·`_ttlowat` 합침(§570 과 같음), 다른 객체의 `fd_*`·`fc_*`·`disksort_*` 등.
관문: 명령 종료 0, 정한 경고뿐, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 576.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| M5 `compare` 요약은 같을 수 없음 — `stage_vs_test_stage` 에 새 경로가 더해짐 | `stage_m68k.py:655–658`(시험 스테이지 매니페스트와 SHA 가 다른 경로 목록), §573.2 "요약 차이는 새 경로 셋뿐" | ✅ 제 오류. 3 고침 |
| `M4FILES[576]`·`EXCEPTS[576]` 만 필요; `M4HEADERS`·`X86` 은 PLAN 이하 최대 키, `--plan` 은 `EXCEPTS` 의 정확한 키 | `stage_m68k.py:413·507·523·674` 를 엶 | ✅ 계획 그대로 |
| `"fd.h"` 와 `<fd.h>` 는 같은 생성 머리로 풀림 | `m0p573-a1-stage.manifest.json` 의 `fd.h` 경로는 `generated/fd.h` 하나(python), 컴파일 줄 `-Isrc/generated`(§574 `probe.cmd`) | ✅ |
| 토큰 차이는 따옴표와 `alloc_p` → `aligned_ap` 뿐 | B2 789·994 행(§575 diff 출력) | ✅ 작성 뒤 python 으로 확인 |
| `obj_sig` 는 STABS 이름이 아닌 수만 봄; "머리가 같으므로" 는 근거로 약함 | `l2_prefix_diff.py:48–53` 를 엶 | ✅ 4 문구 고침(실제 비교로 확인) |
| 최종 명세에 `refs["fd_driver"]` = [경로, SHA]; `known_warnings` 는 F stderr 그대로 | `m4_m68k_probe.py:63–66·378–386` 을 엶, B2 stderr(`_log/02.err`) 세 줄 | ✅ 5 에 적음 |
| funcbytes 명령에 `406bd66=_fdminphys` 를 적을 것 | §574·§575 명령 | ✅ 5 에 적음 |
| 기대 덮은 행 51/188, +4118 B | §573.2 의 50/188 | ⏭️ 수치는 도구 출력으로 적음 |

### 576.2 결과(2026-10-30)

- 1: 07 `src/machdep/m68k/fd_driver.c`(1170 행, SHA `a261cd8c…`): 주석 뺀 토큰이 §575 B2 와 `"fd.h"` 의 따옴표와 `aligned_ap`/`alloc_p` 다섯 자리만 다름(python, 4942 토큰). 처음 생성본은 `copyin` 줄 바꿈이 어색해(빈 줄 끝 공백) 생성기를 고쳐 07 에 쓰기 전에 다시 만듦. diff `m68k-fd_driver.diff`(209 행).
- 2: `stage_m68k.py` 690 → 692 행(`M4FILES[576]`·`EXCEPTS[576]`·머리말 목록).
- 3: `--plan 573` 재생성(`m0p573-r576-stage`)은 보관본과 모든 키가 같음; `m0p576-a1-stage`(956 파일)와 보관 573 의 차이는 `src/machdep/m68k/fd_driver.c` 하나. M5: `m5-573.cmd` 가 §573 것과 `cmp` 같음, run `m3p576-b573`·`m3p576-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p576-compare-20261030.json`, `-b573-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 `fd_driver.c` 뿐. x86 `m4-x86-inputs-p576-20261030.json` `ok`, `--plan 576 x86gate` 일곱 같음·`v183_paths` 0.
- 4: run `m4p576-p1`(`m4-m68k-probe-p576-p1-20261030.json`): F·L 종료 0, `kfree` 경고 둘씩(F 1050·1096 행), OBJECT_MATCH·12/12(`m4-m68k-funcbytes-p576-F/L-20261030.json`), F = L·F = B2(canon·`obj_sig` 모든 칸, STABS 1530). run `m4p576-e1`: `-E` 토큰 19740 개, 차이는 `aligned_ap`/`alloc_p` 다섯 자리뿐, 둘 다 `src/generated/fd.h`, i386 0.
- 5: run `m4p576-a1`(`m4-m68k-p576-final-20261030.json`, SHA `4dd53115…`; REF = p1 L, `known_warnings` 세 줄): `gate.ok`, 옵션 차이 없음, 12/12(`m4-m68k-funcbytes-p576-a1-20261030.json`); 확인 `m4-m68k-p576-checks-20261030.json`(`ok` 참): `__text` 4118·`__cstring` 255(원본 바이트와 같음), 외부 함수 열하나 = 원본 이름·`_fdminphys` 지역, COMMON 14 모두 원본에 있음, 원본에 없는 미정의 없음, L1 0x406b546 OBJECT_MATCH 사유 없음, 의존 165 파일 전수 사슬 문제 0·i386 0(주요 열여섯은 출처별로 기록). 객체 SHA `efee906d…`.
- 6: 근거 `06_reconstruction/evidence/m68k-fd_driver.md`(상태 도구 전). `ACCEPTED` 에 둘 묶음 한 줄. 상태표 32 → 33 행·`m4-m68k-status-p576-20261030.json`: 31 객체(OBJECT_MATCH 24, CODE+BSS_INFERRED 7), 덮은 행 51/188, 54584/215874 B(25.29%; python, +4118 B), `object_bytes` 68772, 두 번 실행 같음, §573 표와 이름 대조로 더한 것 `fd_driver` 뿐·바뀐 것 없음.
- 7: PROVENANCE 1167 → 1168 행(일곱 칸), MODIFICATIONS 712 → 713 행, DECISIONS D130(133 → 134 행), "현재 상태와 다음 일" 고침. §574 의 "부르는 것" 줄의 `copyinmsg`·`copyoutmsg` 는 원본 기호표에서 `copyin`·`copyout` 과 같은 주소(0x40016d0, 0x400165e)이고 객체는 `_copyin`·`_copyout` 을 부름(근거 문서에 적음).

## 577. M4-83 세부 계획 — m68k `fd_cmds.c`(행 219, 명시 구간) 첫 진단(07 변경 없음; 코딩 전, 2026-10-30)

다음 대상을 고른 이유(이번 세션): floppy 묶음에서 남은 코드 행. 행 `m68k-219` 는 정확 행이 아님(시작 0x406a992–0x406aa70, 끝 0x406b546, 2774–2996 B; 인벤토리).

확인한 사실(이번 세션; 원본 목록 `otool-V10/image.txt`, 함수 표, 기호표, python):
- 0x406a992–0x406aa70 의 세 항목(`_evretry` 66 B, 이름 없는 56 B·100 B)은 셋 다 `_evdispatch`(0x406a86a, 행 218)를 부르거나(0x406a9b8, 0x406a9fe) 이벤트 자료(0x40c362c·0x40c36c8·0x40c3640·0x40c3610·0x40c36ca·0x40c3630)를 다루는 이벤트 코드라 `fd_cmds` 가 아님. 그래서 `fd_cmds` 는 [0x406aa70, 0x406b546) 2774 B(python), 11 항목: `fc_cmd_xfr` 522, `fc_eject` 198, `fc_motor_on` 84, `fc_motor_off` 40, `fc_send_cmd` 1304, 이름 없는 셋 114·68·190, `fc_start_timer` 146, `fc_timeout` 56, `fc_stop_timer` 52. 0x406b546 은 `fd_driver` 의 `_fd_slave`(§576).
- NeXTMach mk-108.1 `nextdev/fd_cmds.c`(1046 행, SHA-256 `f7fbd78b…`): 외부 함수 여덟은 같은 차례; `DEBUG` 가 없으면 정적 함수는 `fc_dma_init`·`dma_bytes_moved`·`fc_enable_interrupt`·`fc_wait_intr` 넷(`fc_log_bad_phase` 는 `#ifdef DEBUG`, 971–987 행) — 원본은 셋.
- 원본이 부르는 것(목록의 주소 참조, 기호표): `printf`, `us_timeout`, `us_untimeout`, `thread_wakeup_prim`, `dma_list`, `dma_start`, `dma_cleanup`, `dma_abort`, `fc_send_byte`·`fc_get_byte`·`fc_flpctl_bset`·`fc_flpctl_bclr`·`fc_configure`·`fc_specify`·`fc_flags_bset`·`fc_flags_bclr`(`fd_io`), `fd_gen_seek`·`fd_thread_block`(`fd_subr`), `delay`, `bzero`, `pmap_kernel`; 자료 `_fd_polling_mode`, `_fd_drive_info`, `_event_high`·`_event_middle`·`_eventc_h/l/m/latch`, `_dma_chip`. `panic` 참조 없음.
- 문자열: 원본 커널 안에서 `fd: DMA byte count > 64K\n` 하나(0x40aa0be, 26 B, `fd_driver` 의 255 B 바로 앞)만 이 구간이 가리킴; `Unaligned DMA`·`dma_bytes_moved` 문자열은 원본 커널 어디에도 없음(python `count` 0) — NeXTMach 272 행의 `printf("fd: Unaligned DMA\n")` 와 886 행의 `panic` 은 1997 판에 없음(진단에서 확인).

방법(진단; 명세 `08_build/artifacts/m4p577/spec.json`, run `m4p577-p1`, 바탕 `m0p576-a1-stage`, 컴파일 줄 틀 `machdep/i386/dkbad.c`):
- `m4_id` 는 명시 구간(§537·§561 꼴): `{"range": ["0x406aa70", "0x406b546"], "rows": [], "partial": ["m68k-219"], "basis": …}` — 행 219 를 나누므로 부분 행(상태 도구는 덮은 행으로 세지 않음).
- 변형 A1(`fd_cmds_A1.c`, SHA-256 `cfc76143…`): NeXTMach 글에서 include 줄만 — `<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<kern/mach_types.h>` → `<mach/mach_types.h>`, `<next/psl.h>` → `<m68k/psl.h>`, `<next/machparam.h>` → `<m68k/machparam.h>`(D104); 나머지(`<nextdev/dma.h>`·`fd_extern.h`·`fd_reg.h`·`fd_vars.h`·`sf_access.h`·pmon 셋)는 §543·§570 의 07 머리로 풀림.
- 측정: `m4_m68k_probe.py compare`(명세에 `refs` 가 없으므로 각 명령의 종료 코드와 경고 줄을 따로 봄), `m68k_funcbytes.py 406aa70 406b546 OBJECT.o RECORD.json 406b2d4=_fc_dma_init 406b346=_fc_enable_interrupt 406b38a=_fc_wait_intr`(이름 없는 셋은 몸으로 정함, §577.1), 섹션·`__cstring`·외부 함수·COMMON·원본에 없는 미정의; 다른 함수는 실기 `otool -tv` 로 원본과 비교해 1997 꼴을 적음.
판정(미리 정함; 07 은 바꾸지 않음): 함수별 같음/다름과 차이를 적고 다음 계획에서 1997 꼴을 시험합니다. 컴파일이 안 되면 원인을 적고 최소로 고친 꼴로 다시 돌립니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 577.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0x406a992–0x406aa70 은 이벤트 코드, 구간·크기 2774 B·차례가 맞음; `span()` 이 명세를 받아들임(행 218 은 하한에서 끝나 겹치지 않음) | 원본 목록 읽음(이번 세션), python 0x406b546−0x406aa70 = 2774, 인벤토리 행 218 끝 0x406aa70 | ✅ (`span()` 은 run 의 stage 명령에서 다시 확인됨) |
| 부르는 것·자료·문자열(0x406ae0a → 0x40aa0be, 26 B, `Unaligned DMA`·`dma_bytes_moved` 없음) 맞음 | python 주소 참조·기호표·`count`(이번 세션) | ✅ |
| 이름 없는 셋은 몸으로 정해짐: 0x406b2d4 = `fc_dma_init`(`dma_list`·`dma_start`·`delay`·`dma_abort`), 0x406b346 = `fc_enable_interrupt`(sr 0x2300, flags `&= ~0x40`, `|= 0x80`, +0x20 에 fdiop), 0x406b38a = `fc_wait_intr`(`fd_polling_mode` 고리, `fc_start_timer`·`fd_thread_block`·`fc_stop_timer`); `dma_bytes_moved` 는 없고 원본은 0x406b0f2 에서 요청 바이트 수를 옮긴 바이트 수에 바로 씀 | 원본 0x406b2d4–0x406b446·0x406b0e0–0x406b0fe 읽음, `m68k_funcbytes.py:95–96`(대응 인자) | ✅ 측정 명령에 대응 셋을 적음 |
| A1 의 머리 16 개가 스테이지에서 풀림, `KP_SCSI_*`·`DMACSR_READ`·`NDMAHDR`·`func`·`CALLOUT_PRI_SOFTINT0` 있음 | — | ⏭️ 컴파일 결과로 확인 |
| 원본 `fc_dma_init` 의 `dma_list` 는 인자 9 개(NeXTMach 11 개의 `secsize`·`rathole_va` 없음), `NDMAHDR` 10 = 원본 `#0xa` | 원본 0x406b2e8–0x406b310(인자 push 9 개), 07 `dma.c:206–212` 의 1997 `dma_list` 매개변수 9 개, 07 `dma.h:235` 옛 선언(인자 검사 없음) | ✅ 1997 꼴 후보로 기록 |
| 명세에 `refs` 가 없으면 `compare` 는 컴파일 실패에도 종료 0 일 수 있고 `commands_ok` 는 경고도 거부함 | §574.2·§575.2 의 `commands_ok` 거짓(경고 때문) | ✅ 측정 줄에 적음 |

### 577.2 결과(run `m4p577-p1`, 2026-10-30)

- 컴파일: A1 종료 0, 경고 0, i386 머리 0(의존 161), `span()` 이 명시 구간을 받아들임(`partial_rows` `m68k-219`). 기록 `09_validation/reconstruction/m4-m68k-probe-p577-20261030.json`.
- `__text` 3072 B(구간 2774, python 차 298), `__cstring` 79 B(`fd: Unaligned DMA\n`·`fd: DMA byte count > 64K\n`·`dma_bytes_moved: DMA buf overflow`). 외부 함수 여덟 = 원본 이름, 원본에 없는 미정의 없음(A1 의 `_panic` 도 원본에 있음); 원본이 쓰는 `_dma_chip` 은 A1 에 없음.
- 함수별(`m4-m68k-funcbytes-p577-A1-20261030.json`, 대응 셋): 9/11 같음 — `fc_cmd_xfr`, `fc_eject`, `fc_motor_on`, `fc_motor_off`, `fc_enable_interrupt`, `fc_wait_intr`, `fc_start_timer`, `fc_timeout`, `fc_stop_timer`. 다름: `fc_send_cmd` 1304/1450(+146), `fc_dma_init` 114/118(+4); 객체에만 `_dma_bytes_moved`.
- 원본 목록과 A1 목록(`m4p561/otool/fd_cmds_A1.txt`, 실기 `otool -tv`)으로 읽은 1997 꼴(이번 세션):
  - `fc_send_cmd` 앞부분(0x406adfc–0x406ae1c): 읽기/쓰기의 정렬 검사와 `printf("fd: Unaligned DMA\n")`(NeXTMach 268–275 행)가 없고 바로 `> 0x100000` 검사(0x40aa0be 문자열).
  - `dma_list` 인자 아홉(0x406ae34–0x406ae54: `dma_after`·0·`NDMAHDR` 10·`direction`·`fdiop->pmap`·바이트 수·`addrs`·`dma_list`·`dma_chan`) — NeXTMach 의 `secsize`·`rathole_va` 0 둘이 없음(07 `dma.c:206` 의 1997 `dma_list` 매개변수 아홉). `fc_dma_init`(0x406b2e8–0x406b310)도 같음.
  - FIFO 비우기 고리(0x406b006–0x406b04a): `dma_chip`(u_short, 스테이지 `m68k/cpu.h:48`)이 313 일 때만 8 번, 아니면 1 번 — §573 `fc_intr` 와 같은 꼴(NeXTMach 432 행 `i<8`).
  - DMA 마무리(0x406b0e0–0x406b12c): `fc_flags_bclr(fcp, FCF_DMAING)` 다음 `fdiop->bytes_xfr = fdiop->byte_count`(0x406b0f2, 쓰기/EOCYL 조건과 `dma_bytes_moved` 없음), `bytes_xfr > byte_count` 자르기는 그대로, `FCF_DMAERROR` 면 `FDR_MEMFAIL`, 읽기/정렬 갈래 없이 `dma_cleanup(&fcp->dma_chan, 0)`(0x406b114–0x406b11a), `dma_enable = FALSE`, `fc_dma_init(fcp)`. 정적 `dma_bytes_moved` 는 없음.
  - 나머지 차이는 위 바뀜에 따른 컴파일 결과(레지스터 배정 d4/a5, 명령 선택 — 예: 원본 0x406ae32 `addl d1,d4` 대 A1 0x3e6–0x3e8 `addqw #0x8,a5` 둘 —, 분기 폭, 스택 정리, `switch` 점프표의 오프셋)로 보임; 다른 동작 덩이의 더함/뺌은 찾지 못함.

## 578. M4-84 세부 계획 — m68k `fd_cmds.c` 1997 꼴 진단 B(07 변경 없음; 코딩 전, 2026-10-30)

방법(진단; 명세 `08_build/artifacts/m4p578/spec.json`(§577 과 같은 명시 구간), run `m4p578-p1`, 바탕 `m0p576-a1-stage`; 소스는 scratchpad `gen_p578.py` 가 A1 에서 만듦):
- 변형 B1(`fd_cmds_B1.c`, SHA-256 `e39e8aee…`; §578.1 에서 고쳐 다시 만듦): A1 에 §577.2 의 다섯 바뀜 — (1) `fc_send_cmd` 의 정렬 검사 `if` 덩이(A1 268–275 행)를 뺌, (2)·(3) `fc_send_cmd`·`fc_dma_init` 의 `dma_list` 끝 인자 `0, 0`(`secsize`·`rathole_va`)을 뺌, (4) FIFO 고리 `for(i=0; i<((dma_chip == 313) ? 8 : 1); i++)`, (5) DMA 마무리를 `fdiop->bytes_xfr = fdiop->byte_count;` 와 `dma_cleanup(&fcp->dma_chan, 0);` 로 바꾸고(쓰기/EOCYL 조건, 읽기 꼬리 갈래, `dma_abort` 둘을 뺌) 정적 `dma_bytes_moved` 의 원형과 정의를 뺌. 주석은 진단 표시만.
- 측정: §577 과 같음(`m68k_funcbytes.py 406aa70 406b546 … 406b2d4=_fc_dma_init 406b346=_fc_enable_interrupt 406b38a=_fc_wait_intr`, 섹션·`__cstring` 26 B 를 원본 0x40aa0be 와 바이트 비교, 외부 함수·COMMON·미정의); 다르면 실기 `otool -tv`.
판정(미리 정함; 07 은 바꾸지 않음): 11/11 이고 `__text` 2774·`__cstring` 원본과 같으면 그 꼴로 07 구현 계획(§579)을 씀; 같은 결과의 꼴이 여럿이면 사용자 결정; 아니면 남은 차이를 읽고 다음 진단.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄; 경고는 기록.

### 578.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| B1 760 행 `/* plan 578 diagnostic */ dma_bytes_moved removed` 는 주석 밖 낱말이 있어 컴파일되지 않음 | B1 760 행을 엶 | ✅ 제 생성기 오류. `/* plan 578 diagnostic: dma_bytes_moved removed */` 로 고쳐 B1 을 다시 만듦(SHA `df9192d8…` → `e39e8aee…`, 표시 줄 일곱만 바뀜) |
| A1→B1 차이는 다섯 바뀜뿐; 정렬 검사 삭제·`dma_list` 인자 아홉(두 곳)·FIFO 고리·DMA 마무리 차례(`bclr` → `bytes_xfr` → 자르기 → `DMAERROR` → `dma_cleanup(…, 0)` → `dma_enable` → `fc_dma_init`)가 원본과 같음 | §577.2 에서 원본 0x406adbc–0x406aea0·0x406afe8–0x406b130·0x406b2d4–0x406b344 를 읽음, diff A1–B1(이번 세션) | ✅ |
| 함수 전체 비교에서 다른 동작 덩이 차이 없음(명령 전송, DMA 방향, 상태 수집, 시간 제한 `0x2710`·`timeout*1000`/`*2000`, 점프표 대응, `out:` 경로) | — | ⏭️ 진단 바이트(11/11 여부)로 확인 |
| 577.2 의 "나머지는 레지스터 배정과 점프표" 는 과소 서술 — 명령 선택·분기 폭·스택 정리도 다름 | 원본 0x406ae2c–0x406ae34, A1 목록 0x3e0–0x3ee 를 엶(`addl d1,d4` 대 `addqw #0x8,a5` 둘) | ✅ 문구 고침 |
| 쓰지 않는 변수(`do_pad`, `dma_start_addrs`)는 A1 에서 물려받음, `dma_chip` 은 스테이지 `m68k/cpu.h:48`, `out:` 은 계속 쓰임 | 스테이지 `m68k/cpu.h:48` `extern u_short dma_chip;`(이번 세션 grep) | ✅ (나머지는 컴파일 결과로 확인) |

### 578.2 결과(run `m4p578-p1`, 2026-10-30)

- B1(`e39e8aee…`): 종료 0, 경고 0, i386 머리 0(의존 161), `__text` 2774(구간과 같음), `__cstring` 26 B 이고 바이트가 원본 0x40aa0be 와 같음(python), COMMON 14, 원본에 없는 미정의 없음, L1 `OBJECT_MATCH`(이유 없음, 0x406aa70 에 놓임, `full_span`), 함수별 11/11(`m4-m68k-funcbytes-p578-B1-20261030.json`). 기록 `09_validation/reconstruction/m4-m68k-probe-p578-20261030.json`.
- 사용자 결정(2026-10-30, AskUserQuestion): ① FIFO 고리는 "fd_io 와 같은 꼴" `for(i=0; i<((dma_chip == 313) ? 8 : 1); i++)`(D129 와 같음) ② 1997 판에 없는 NeXTMach 코드는 "지우고 표시 주석"(D128·D129 와 같은 꼴, 머리 주석에 목록).

## 579. M4-85 D131 구현 계획 — 07 `src/machdep/m68k/fd_cmds.c`(명시 구간, OBJECT_MATCH; 코딩 전, 2026-10-30)

확인한 사실(이번 세션): §577–578 결과와 결정. bss·`__data` 가 없어 OBJECT_MATCH 객체(`ACCEPTED` 둘 묶음). 새 07 머리·구성 행 없음. 명시 구간 [0x406aa70, 0x406b546) 은 행 `m68k-219` 를 나누는 부분 행이라 상태 도구는 덮은 행·바이트·백분율을 늘리지 않고 객체 수와 `object_bytes` 만 늘림(§563 `snd_dspdev` 와 같음).
1. 07 `src/machdep/m68k/fd_cmds.c`(D103) = NeXTMach `nextdev/fd_cmds.c`(고지·HISTORY 그대로, D013) + 머리 주석(1997 바뀜과 지운 코드 목록·근거) + include 줄(`<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<kern/mach_types.h>` → `<mach/mach_types.h>`, `<next/psl.h>` → `<m68k/psl.h>`, `<next/machparam.h>` → `<m68k/machparam.h>`(D104); 나머지 그대로) + 1997 본문(표시 plan 579, D131, D024): §578 의 다섯 바뀜. 지운 덩이(정렬 검사, 쓰기/EOCYL 조건과 `dma_bytes_moved` 호출, 읽기 꼬리 갈래, 정적 `dma_bytes_moved` 의 원형과 정의)는 그 자리에 한 줄 표시 주석; 지운 덩이에 딸린 NeXTMach 주석도 함께 지움. 주석 뺀 토큰이 §578 B1 과 같아야 함(python; include 꼴도 같음).
2. `stage_m68k.py`: `M4FILES[579]` = 576 + `fd_cmds.c`, `EXCEPTS[579] = dict(EXCEPTS[576])`, 머리말 plan 목록에 579; `M4HEADERS`·`X86` 은 그대로.
3. 회귀: `--plan 576` 재생성(`m0p576-r579-stage`)이 보관 `m0p576-a1-stage` 와 모든 키가 같음; `m0p579-a1-stage` 와 보관 576 의 차이는 `src/machdep/m68k/fd_cmds.c` 하나(python assert). M5 205 줄: `m5-576.cmd` 가 §576 것과 `cmp` 같음, run `m3p579-b576`·`m3p579-cc1` 객체 205 바이트 같음·stderr 205 같음, `compare` 두 기록의 `differ_unexpected`·`lost` 빔, 요약은 `stage_vs_test_stage` 에 `fd_cmds.c` 가 더해진 것 말고 같음. x86 `m4_x86_inputs.py s6ln`(환경 변수 `L2_FORMS`·`L2_EXPECT`)·`--plan 579 x86gate` 일곱 같음.
4. (07 파일은 p1 전에 고정) 확인 run `m4p579-p1`(`08_build/artifacts/m4p579/confirm/spec.json`, 바탕 `m0p579-a1-stage`, §577 명시 구간): F = `@machdep/m68k/fd_cmds.c`, L = §578 B1 글 그대로(`08_build/artifacts/m4p579/src/fd_cmds_L.c`, `cmp` 로 확인). 종료 0, 경고 0, i386 머리 0, F = L(canon·`obj_sig` 모든 칸 — 실제 비교), `OBJECT_MATCH`·11/11(`m4-m68k-funcbytes-p579-F/L-20261030.json`, 대응 셋). run `m4p579-e1`: F·L 의 `-E` 토큰이 같음(`#` 줄 빼고), i386 0.
5. 최종 run `m4p579-a1`(명세 `08_build/artifacts/m4p579/spec.json`: F 만, `m4_id` 는 §577 의 명시 구간 사전 그대로(상태 도구가 최종 명세의 `m4_id` 를 읽음), `refs["fd_cmds"]` = [p1 L 객체, SHA-256], 경고가 없으므로 `known_warnings` 없음; 기록 `m4-m68k-p579-final-20261030.json`): `gate.ok`, 옵션 차이 없음, 11/11(`m4-m68k-funcbytes-p579-a1-20261030.json`, 대응 셋); python 확인 `m4-m68k-p579-checks-20261030.json`: 섹션(`__text` 2774, `__cstring` 26, `__data`·`__bss` 없음), 문자열 26 B 가 원본 0x40aa0be 와 같음, 외부 함수 여덟 = 구간 안 원본 이름, 지역 셋(`_fc_dma_init`·`_fc_enable_interrupt`·`_fc_wait_intr`), COMMON 이름이 원본에 있음, 원본에 없는 미정의 없음, L1 0x406aa70 `OBJECT_MATCH` 사유 없음, 의존 목록 i386 0, 입력 사슬(최종 `-M` 출력 전수: 매니페스트 출처·SHA 가 스테이지 = run, 07 출처면 07 파일과도 같음; 주요 파일 따로).
6. 상태표: 근거 `06_reconstruction/evidence/m68k-fd_cmds.md` 를 먼저 쓰고 `ACCEPTED` 에 (최종 기록, SHA) 한 줄; 도구 두 번 실행·§576 표와 이름 대조(더한 것 `fd_cmds` 뿐, 바뀐 것 없음). 기대: 객체 32(OBJECT_MATCH 25), `object_bytes` 71546(python 68772 + 2774), 덮은 행 51/188·바이트 그대로, `partial_rows` 에 `m68k-219` 가 더해짐(수치는 도구 출력만).
7. 기록: diff(NeXTMach 대비 `m68k-fd_cmds.diff`), PROVENANCE 새 행(일곱 칸: NeXTMach 저장소·커밋 `f6bdb9c3…`·`mk-108.1/nextdev/fd_cmds.c`, 고지(D013), 함수별로 NeXTMach 그대로 아홉·바이트로 고친 둘(`fc_send_cmd`·`fc_dma_init`)·지운 정적 하나·`DEBUG` 전용 `fc_log_bad_phase` 는 NeXTMach 그대로(컴파일되지 않아 바이트 검증 없음), 파일 SHA·최종 기록·`M4FILES[579]`), MODIFICATIONS, DECISIONS D131, 계획 결과·현재 상태, HANDOFF, 메모리. M7 의무: COMMON 임시 정의 합침(§570 과 같음), 다른 객체의 `fc_*`·`fd_*`·`dma_*`·`us_timeout` 등과 0x406a992–0x406aa70 의 이벤트 코드(행 218·219 의 남은 부분)는 다른 객체의 일.
관문: 명령 종료 0, 경고 0, i386 머리 0, 회귀 같음, 상태 도구가 멈추지 않음.

### 579.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 최종 명세에 명시 구간 `m4_id` 를 그대로 둘 것 — 상태 도구는 최종 명세의 `m4_id` 를 읽음 | `m4_m68k_status.py` 95–116 행(`spec = …m4p%d/spec.json`, `P.span(inv, o['m4_id'])`) | ✅ 5 에 적음 |
| 스테이지 키·회귀·확인·`refs`·`known_warnings` 없음은 §576·§563 과 같음; funcbytes 마다 대응 셋 | §576.2, `m68k_funcbytes.py:95–96` | ✅ 5 에 대응 셋을 적음 |
| 07 의 주석 뺀 토큰은 B1 과 같음 — 쓰지 않는 변수(`dma_start_addrs`·`do_pad`)와 남은 코드는 지우지 말 것 | 계획 1 은 바뀜 다섯과 지운 덩이만 다룸; 작성 뒤 python 토큰 비교 | ✅ (작성 때 지킴) |
| 기대 상태: 32 객체(OBJECT_MATCH 25), `object_bytes` 71546, 덮은 행·바이트 그대로 | python 68772 + 2774 = 71546 | ✅ 6 에 적음 |
| `DEBUG` 전용 `fc_log_bad_phase` 는 NeXTMach 그대로이나 컴파일되지 않음 — 출처 기록에 바이트 검증 없이 적을 것 | B1 843–846 행(`#ifdef DEBUG`) | ✅ 7 에 적음 |

### 579.2 중간 결과와 계획 밖 run(2026-10-30)

- 1·2: 07 `src/machdep/m68k/fd_cmds.c`(932 행, SHA `6b7fcbdc…`): 주석 뺀 토큰 3346 개가 §578 B1 과 같음(python). `stage_m68k.py` 692 → 694 행.
- 3: `--plan 576` 재생성(`m0p576-r579-stage`)은 보관본과 모든 키가 같음; `m0p579-a1-stage`(957 파일)와 보관 576 의 차이는 `fd_cmds.c` 하나. M5: `m5-576.cmd` 가 §576 것과 `cmp` 같음, run `m3p579-b576`·`m3p579-cc1` 종료 0, 객체 205 바이트 같음, stderr 205 같음(52 비지 않음), `compare`(`m3-m68k-p579-compare-20261030.json`, `-b576-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 의 `fd_cmds.c` 뿐. x86 `m4-x86-inputs-p579-20261030.json` `ok`, `--plan 579 x86gate` 일곱 같음·`v183_paths` 0.
- 4: run `m4p579-p1`: F·L 종료 0·경고 0, 둘 다 `OBJECT_MATCH`·11/11(`m4-m68k-funcbytes-p579-F/L-20261030.json`), F = L·F = B1 canon 같음. 그러나 `obj_sig` 의 STABS 수가 1300 대 1301: 차이는 `N_SLINE` 하나 — L 은 0x1f2(`fc_cmd_xfr` 끝)에 B1 118 행(`}`)과 122 행 둘을 적고 F 는 140 행 하나만 적음. 두 글의 그 자리는 글자가 같고(F 는 머리 주석 17 행과 원형 표시 1 행으로 18 행 밀림), run `m4p579-e1` 의 `-E` 토큰 17144 개도 같음(i386 0). 최종 관문의 REF 비교(`obj_sig` 모든 칸)를 통과할 수 없으므로 §573.2 와 같이 계획에서 벗어나 run 을 더함(관문 기준은 그대로):
  - run `m4p579-p2`(`confirm/spec-p2.json`): L2 = B1 글에 F 와 같은 머리 주석(17 행)과 `dma_bytes_moved` 원형 자리 표시 1 행을 더해 처음 부분의 줄 위치를 F 와 맞춘 꼴(토큰은 B1 과 같음). 가설: 줄 위치만 맞추면 `N_SLINE` 수가 F 와 같아짐. 판정: F = L2 가 canon 과 `obj_sig` 모든 칸에서 같고 L2 = B1 canon 이면 L2 를 최종 REF 로 씀; 아니면 원인을 더 읽고 사용자에게 물음.

### 579.3 결과(2026-10-30)

- run `m4p579-p2`(`m4-m68k-probe-p579-p2-20261030.json`): F·L2 종료 0·경고 0·OBJECT_MATCH, F = L2(canon·`obj_sig` 모든 칸, STABS 1300), L2 = B1(canon), 11/11(`m4-m68k-funcbytes-p579-L2-20261030.json`), p1·p2 의 F 객체 바이트 같음 — 가설대로 STABS 차이는 줄 위치에서 옴.
- 5: run `m4p579-a1`(`m4-m68k-p579-final-20261030.json`, SHA `2f66b8c7…`; 명시 구간 `m4_id`, REF = p2 L2, `known_warnings` 없음): `gate.ok`, 옵션 차이 없음, 11/11(`m4-m68k-funcbytes-p579-a1-20261030.json`, 대응 셋); 확인 `m4-m68k-p579-checks-20261030.json`(`ok` 참): `__text` 2774·`__cstring` 26(원본 바이트와 같음), 외부 함수 여덟 = 구간 안 원본 이름, 지역 셋, COMMON 14 모두 원본에 있음, 원본에 없는 미정의 없음, L1 0x406aa70 OBJECT_MATCH 사유 없음·부분 행 `m68k-219`, 의존 162 파일 전수 사슬 문제 0·i386 0. 객체 SHA `6aa35924…`.
- 6: 근거 `06_reconstruction/evidence/m68k-fd_cmds.md`(상태 도구 전). `ACCEPTED` 에 둘 묶음 한 줄. 상태표 33 → 34 행·`m4-m68k-status-p579-20261030.json`: 32 객체(OBJECT_MATCH 25, CODE+BSS_INFERRED 7), 덮은 행 51/188·54584/215874 B(25.29%) 그대로, `partial_rows` 에 `m68k-219` 가 더해짐, `object_bytes` 71546(python 68772 + 2774), 두 번 실행 같음, §576 표와 이름 대조로 더한 것 `fd_cmds` 뿐·바뀐 것 없음.
- 7: diff `m68k-fd_cmds.diff`(249 행), PROVENANCE 1168 → 1169 행(일곱 칸), MODIFICATIONS 713 → 714 행, DECISIONS D131(134 → 135 행), "현재 상태와 다음 일" 고침.
- 교훈: 같은 토큰의 글이라도 줄 위치가 다르면 GCC 의 줄 번호 기록(`N_SLINE`) 수가 하나 달라질 수 있음 — 확인 run 의 L 은 07 과 줄 위치까지 맞춘 꼴로 두는 편이 안전함.
