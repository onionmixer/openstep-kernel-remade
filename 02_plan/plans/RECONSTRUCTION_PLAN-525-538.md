# 커널 소스 복원 작업계획 — 보관 §525–538

`02_plan/RECONSTRUCTION_PLAN.md` 의 §525–538(m68k M4: `autoconf`(별도 분류 `CODE+BSS_INFERRED`), `kern_machdep`, `kdp_machdep`, `clock`(SDK `video.h` 스테이징, 함수별 도구의 산재 재배치), `nextdbgasm`(행 일부를 덮는 명시 구간); 결정 D113–D117. §524(`np.c`, 사용자 결정 대기)는 본문에 남김)을 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-26, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 본문은 `---` 아래부터입니다.

---

## 525. M4-31 세부 계획 — `next/autoconf.c` 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션):
- §524 의 `np.c` 는 1997 `nextdev/dma.h` 배치가 정해져야 진행할 수 있고, 그 작업 여부는 사용자 결정을 기다립니다. 그래서 `dma.h` 가 필요 없는 단위를 먼저 합니다.
- §524 의 남은 후보 가운데 `fd_subr.c` 는 `nextdev/dma.h` 를 들이고(NeXTMach 31 줄), `snd_device` 는 나중 판입니다. `next/autoconf.c` 는 `dma.h` 를 들이지 않습니다(include 11 줄, `scsireg.h`·`scsivar.h` 도 `dma.h` 를 들이지 않음).
- 행 `m68k-210`: [0x4065bbc, 0x406632c), 1904 B, 정확 경계, 대응률 10/10.

확인한 사실(이번 세션; 원본 목록 `08_build/artifacts/m0p414/otool-V1/image.txt`, 기호표, NeXTMach `next/autoconf.c` 417 줄; 계산은 python):
- 원본 11 진입점은 NeXTMach 의 정의 순서와 같습니다: `configure` 70 B, 이름 없는 776 B(0x4065c02, 정적 `bus_find` 자리), `intr_spurious` 70, `install_polled_intr` 96, `install_scanned_intr` 176, `uninstall_polled_intr` 120, `uninstall_scanned_intr` 182, `map_addr` 160, `dev_find` 124, `ioaccess` 116, `swapconf` 14.
- NeXTMach 의 `slave_config`(`#if MACH`)는 원본에 없습니다(`_slave_config`·`_set_cpu_number` 기호 없음). 컴파일 줄에는 `-DMACH` 가 있습니다.
- `configure`(0x4065bbc): `nbic_configure` 호출, `intr_mask |= 0x38003`, `*intrmask |= 0x18003`(NeXTMach 의 `I_BIT` 식과 같은 값, python), `bus_find(bus_cinit, bus_dinit)`, `setconf`, `swapconf` 뒤 바로 돌아갑니다. NeXTMach 의 `master_cpu = 0;`, `set_cpu_number()`, `printf("master cpu at slot %d.\n")`, `machine_slot[]` 설정이 없습니다. 원본 `__cstring` 의 이 파일 문자열 묶음(0x40a9e13–0x40a9ee4)에도 "master cpu" 문자열이 없습니다.
- `map_addr`(0x406618e):
  - 아래 경계는 `slot_id`(`P_EPROM` = `SLOT_ID+0`)이고, 위 경계는 §510 `mem.c` 와 같은 1997 식입니다: `slot_id + 0x04000000` 을 먼저 구하고, `dma_chip == 0x139` 이면 `machine_type == 3` 에 따라 `slot_id + 0x06000000` 또는 `(slot_id + 0x04000000) + 0x04000000` = `slot_id + 0x08000000`, 아니면 `slot_id + 0x0c000000`.
  - `kmem_alloc_pageable(kernel_map, &reg, size)` 의 1997 꼴입니다(`pea a6@(-4)`, 반환값이 0 이 아니면 `panic("map_addr: no memory for device")`). NeXTMach 은 반환값을 주소로 받습니다.
- `ioaccess`(0x40662aa): `pmap_enter_mapping(pmap_kernel(), va, pa, 3, 0, 0, 1)` 로 인수가 일곱입니다(`addaw #0x1c,sp`; NeXTMach 은 여섯). 고리 뒤 `pflush_super()` 호출이 없습니다. 끝의 마스크는 `_m68k_page_mask`(0x40c32f0)입니다(NeXTMach `NeXT_page_mask`; 스테이징 `mach/m68k/vm_param.h:24` 에 `m68k_page_mask`).
- 자료: `_dkn`·`_bus_hd`·`_ipl{3,4,6,7}_{scan,arg}` 는 `__common`, `_poll_intr` 는 `__data`(0x40b085c), 정적 `intr_spurious_count` 는 `__bss` 0x40b4f4e(이름 없음)입니다. 배열 크기는 `I_IPL3_BITS` 12·`I_IPL4_BITS` 1·`I_IPL6_BITS` 12·`I_IPL7_BITS` 2 와 맞습니다(python).
- 머리(§498 표 114–124 행):
  - `next/autoconf.h`: 스테이징 `dev/m68k/autoconf.h` 는 1991 년에 공개·비공개로 나뉜 공개 판이라 `busvar.h` 를 들이지 않고 `extern`·원형 대부분이 없습니다.
  - `nextdev/busvar.h`: 스테이징 `dev/busvar.h` 와 NeXTMach 글이 같습니다(diff 0).
  - `next/cpu.h`: 스테이징에는 07 nextmach 사본(D109, 어셈블리 전용)이 있습니다. `I_BIT`·`I_IPL`·`I_INDEX`·`I_IPL*_BITS`·`P_EPROM` 은 여기에만 있습니다. C 에서 들이면 원본에 없는 COMMON `_disk_chip` 이 생깁니다.
  - `next/scr.h`·`nextdev/scsireg.h`·`nextdev/scsivar.h` 는 NeXTMach 에만 있습니다. `SCSI_TARGET`·`SCSI_LUN` 은 `scsivar.h:164–165` 에 있습니다. `scr.h` 는 `scr1`·`scr2`·`brightness` 를 임시 정의합니다.
  - `vm/vm_param.h` 는 스테이징에서 풀리지 않습니다(§509.1). `next/spl.h` 는 스테이징 `machine/spl.h` 입니다.

방법(진단; 명세 `08_build/artifacts/m4p525/spec.json`, run `m4p525-p1`, 바탕 `m0p523-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`(§496; x86 짝 없음), `m4_id` `m68k-210`):
- 변형 N1: NeXTMach `next/autoconf.c` 에서 다음만 바꿉니다(본문은 컴파일에 필요한 이름 하나만).
  - `<vm/vm_param.h>` → `<mach/vm_param.h>`(D107 과 같음), `<next/spl.h>` → `<machine/spl.h>`
  - `<next/autoconf.h>` 는 그대로 두고 NeXTMach 사본을 `inc` 로 둡니다. 그 안의 `<kern/mach_types.h>`(스테이징에 없음)는 진단 별칭(`#import <mach/mach_types.h>`), `<nextdev/busvar.h>` 는 진단 별칭(`#import <dev/busvar.h>`)으로 공급합니다.
  - `<next/scr.h>`·`<nextdev/scsireg.h>`·`<nextdev/scsivar.h>` 는 그대로 두고 NeXTMach 사본을 `inc` 로 둡니다(`scsivar.h` 안의 `<nextdev/busvar.h>` 도 같은 별칭).
  - `<next/cpu.h>` 는 그대로 두어 스테이징의 07 nextmach 사본을 진단에만 씁니다(오염 COMMON 은 기록).
  - 본문: `ioaccess` 의 `NeXT_page_mask` → `m68k_page_mask`(1997 머리의 이름; 없으면 컴파일이 안 됨).
- 변형 D: N1 에 원본 바이트가 요구하는 본문 바뀜만 더합니다.
  - `configure`: `master_cpu = 0;` 과 `swapconf();` 뒤의 줄(`set_cpu_number` … `switch`)을 뺍니다.
  - `map_addr`: `reg` 를 `register` 없는 지역 변수로 두고 `if (kmem_alloc_pageable (kernel_map, &reg, size) != KERN_SUCCESS) panic (...)`; 위 경계 식은 `(caddr_t) (P_MAINMEM + (dma_chip == 313 ? (machine_type == 3 ? 0x02000000 : 0x04000000) : 0x08000000))`(§510 의 `P_MEMSIZE` 식을 그 자리에 씀; 07 의 꼴은 나중에 정함).
  - `ioaccess`: `pmap_enter_mapping` 에 일곱째 인수 `1` 을 더하고, `pflush_super();` 를 뺍니다.
  - `slave_config` 의 `#if MACH` 덩이를 뺍니다.
- 측정(§524 와 같음):
  - `compare`(`diag_gate`, 옵션, `full_span`, L1(`__data`·`__cstring` 포함), 정의·COMMON 이름·크기, 미정의)
  - `m68k_funcbytes.py 4065bbc 406632c`(진단 대응: 원본 이름 없는 진입점 0x4065c02 → `_bus_find`)
  - 객체 기호표(지역 기호 포함)와 원본 자료 기호(`_poll_intr` `__data` 32 B, `__common` 의 `_dkn`·`_bus_hd`·`_ipl*`)의 대조
  - 컴파일이 실패하면 `.err` 전체를 보존하고 첫 오류와 종류를 적습니다.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- D 가 `__text` 1904 B 이고 11 함수 모두 같으면, 바이트로 정해지지 않는 꼴(머리를 `next/cpu.h`·`scr.h`·`scsivar.h` 에서 들일지 파일 안 매크로로 둘지, `!= KERN_SUCCESS` 와 그냥 참 검사, 위 경계 식의 이름, 일곱째 인수의 표기)을 사용자께 여쭙고 구현 계획을 씁니다.
- 아니면 함수별 차이를 적고 멈춥니다(이번 run 에 변형을 더하지 않음). 다른 함수(`bus_find` 등)의 차이는 다음 계획에서 따로 봅니다.

관문(어긋나면 멈춤): 명령 종료 상태 기록, i386 머리 0, 옵션이 M5 줄과 같음(사전형 `-I` 만 더해짐), 경고는 기록.

### 525.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `m68k_funcbytes.py` 는 원본의 이름 없는 `__bss` 주소(0x40b4f4e)를 가장 가까운 기호(`_version`+7733)로 풀고, 객체 쪽은 지역 기호 이름으로 풀어, 정적 `intr_spurious_count` 참조가 옳아도 다르다고 냄 | 원본 목록 0x4065f10·0x4065f18 읽음; 도구 95–102 행(`orig_target`)·182 행(비교) 읽음; 기호표 python(0x40b4f4e 의 가장 가까운 기호 `_version` 0x40b3119) | ✅ 도구에 진단 자료 대응을 더함(아래). 줄번호는 codex 의 목록 줄(129571)이 실제(129581)와 달라 옮기지 않음 |
| `map_addr` 의 둘째 갈래를 "`+ 0x04000000`" 으로 적은 것은 틀림; `slot_id + 0x08000000` | 원본 0x40661a8–0x40661d0(`movel #0x4000000,a1; addal a0,a1` … `movel a1,d0; addl #0x4000000,d0`) 읽음 | ✅ 제 오기입니다. 사실 줄을 고쳤습니다(D 의 식은 그대로 맞음) |
| NeXTMach `scsivar.h:265–270` 의 `extern struct reg_values …[]` 는 `struct reg_values` 정의가 없어 불완전 원소 배열이 됨. 정의는 스테이징 `kernserv/printf.h`; `kern/assert.h` 의 조건 import 는 `MACH_ASSERT 0` 으로 꺼짐 | `scsivar.h:265` 읽음, 스테이징 `kern/assert.h:41–47`·`generated/mach_assert.h:1` 읽음 | ✅ N1·D 에 진단 줄 `#import <kernserv/printf.h>`(§524 의 `next/printf.h` 대응과 같은 머리)를 `scsireg.h` 앞에 둠. GCC 2.7 이 이를 받는지는 시험하지 않음 |
| 성공 판정이 자료 결과(`_poll_intr` 초기값, COMMON 크기)를 보지 않음; `diag_gate.commands_ok` 는 경고 0 을 요구 | `m4_m68k_probe.py:359–360` 읽음 | ✅ 판정에 더함(아래) |
| `ioaccess` 바뀜 문장이 "둘 다 뺌" 으로 읽힘 | 계획 문장 읽음 | ✅ "일곱째 인수 `1` 을 더하고 `pflush_super();` 를 뺌" 으로 고침 |
| `bus_find` 에 더 바꿀 곳 없음, 다른 이름은 풀림 | 원본 0x4065c02–0x4065f08 을 NeXTMach 101–186 행과 필드 접근 순서로 대조(이번 세션); 나머지는 컴파일로 확인 | ⏭️ 컴파일 결과로 판정 |

계획 수정:
- 도구 `m68k_funcbytes.py`: `ADDR=NAME` 의 ADDR 이 [LO, HI) 밖이면 진단 자료 대응으로 씁니다. 원본 주소 va 가 ADDR 이상이고 ADDR 다음의 원본 기호보다 작으면 (NAME, va − ADDR) 로 풉니다. 대응을 주지 않으면 출력은 이전과 같아야 합니다(받아들인 객체 일곱으로 다시 확인). 이번 진단의 대응은 `40b4f4e=_intr_spurious_count`(원본에서 이 주소를 쓰는 곳은 `_intr_spurious` 의 증가 코드; 객체의 지역 기호 이름과 맞는지로만 확인).
- N1·D: `<nextdev/scsireg.h>` 앞에 진단 줄 `#import <kernserv/printf.h>` 를 둡니다.
- 판정의 첫 갈래(구현 계획으로 감)는 다음을 모두 요구합니다: D 의 컴파일 종료 0·경고 0(`diag_gate`), `__text` 1904 B, 11 함수 모두 같음, `_poll_intr` 가 `__data` 32 B 이고 첫 낱말이 `_intr_spurious` 를 가리키며 나머지가 0, 정의·COMMON 이 원본과 같은 이름·크기(머리가 만든 오염 `_disk_chip`·`_scr1`·`_scr2`·`_brightness` 등은 이름을 적어 따로 셈). 하나라도 어긋나면 기록하고 멈춥니다.

### 525.2 결과(2026-10-26)

- 도구 변경(§525.1): `m68k_funcbytes.py` 에 진단 자료 대응을 더했습니다. 대응 없이 돌린 기존 기록 일곱(`p521-H`·`X`, `p522-M`, `p523-F`·`L`·`a1`, `p524-B2`)이 함수 표·같음 수까지 이전과 같고, 받아들인 객체 일곱(`vm_unix` 24/24, `mem` 5/5, `nbic` 2/2, `cons` 7/7, `in_cksum` 2/2, `machargs` 5/5, `next_table` 2/2)도 모두 같음입니다.
- run `m4p525-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p525-20261026.json`): 네 명령 모두 종료 0·경고 0, i386 머리 0, 옵션은 M5 줄과 같음(`diag_gate` 통과).
- N1(`m4-m68k-funcbytes-p525-N1-20261026.json`): `__text` 1958/1904 B. 11 함수 가운데 8 개가 같고, `configure`(172/70)·`map_addr`(96/160)·`ioaccess`(118/116)가 다릅니다. `_slave_config` 이 더 있고 원본에 없는 미정의 `_set_cpu_number` 가 있습니다.
- D(`m4-m68k-funcbytes-p525-D-20261026.json`): `__text` 1904 B, `full_span`, 11/11 함수가 바이트와 참조 대상까지 같습니다(`_intr_spurious` 의 정적 카운터 참조는 진단 대응 `40b4f4e=_intr_spurious_count` 로 객체의 지역 기호와 맞음). L1 은 `__DATA,__bss: unverified` 하나 때문에 `NOT_MATCH` 입니다(객체 `__bss` 4 B = 정적 `intr_spurious_count`).
- D 의 자료(python): `__data` 32 B = `_poll_intr`, 첫 낱말은 `__text` 안 `_intr_spurious`(지역 재배치)이고 나머지 28 B 는 0 입니다. 원본 0x40b085c 의 32 B 도 `0x4065f0a`(`_intr_spurious`) 뒤에 0 입니다.
- D 의 정의·COMMON: 외부 정의 함수 10 개와 `_poll_intr` 는 원본 이름과 같습니다. COMMON 36 개 가운데 34 개는 원본에 있고 크기가 같습니다(2 B 인 `_board_rev`·`_cpu_type`·`_dma_chip`·`_machine_type` 은 원본에서 다음 기호까지 4 B, 정렬). 원본에 없는 것은 머리가 만든 `_disk_chip`(`next/cpu.h`)·`_scr1`(`next/scr.h`) 둘입니다. `_nbuf`·`_bufpages`·`_tthiwat` 등은 원본에서 `__data` 에 있어 다른 객체의 정의와 합쳐집니다(M7).
- 판정: 미리 정한 첫 갈래입니다. 바이트로 정해지지 않는 꼴을 사용자께 여쭙고 구현 계획을 씁니다. 오염 COMMON 둘 때문에 07 에서는 `next/cpu.h`·`next/scr.h` 를 C 에 들일 수 없습니다(D109·§505·§507).
- 사용자 결정(2026-10-26, AskUserQuestion): 머리는 NeXTMach 사본 추가(`next/autoconf.h`·`nextdev/scsireg.h`·`nextdev/scsivar.h` 를 `07_kernel/nextmach/` 에 두고, `next/cpu.h` 이름은 파일 안 매크로), `kmem_alloc_pageable` 검사는 `!= KERN_SUCCESS`, 원본에 없는 NeXTMach 줄은 지우고 머리 주석에 적음, `pmap_enter_mapping` 일곱째 인수는 숫자 `1`.
- 추가 진단(07 변경 없음): D 는 정적 `intr_spurious_count`(`__bss` 4 B) 때문에 probe 판정이 `provisional` 이고, 지금까지 M4 에서 받아들인 객체는 모두 OBJECT_MATCH 였습니다. M5 의 같은 경우(§464)와 같은 도구 `m5_m68k_zerofill.py objs` 를 D 에 돌렸습니다(기록 `09_validation/reconstruction/m4-m68k-zerofill-p525-D-20261026.json`; 표지 이름은 도구 꼴 때문에 `x86-autoconf`). L1 사유는 `__DATA,__bss: unverified` 하나, `reference-inferred`, 후보 [0x40b4f4e, 0x40b4f52), 참조 2, 문제 0, §464 후보와 겹침 0 입니다.
- M4 의 받아들임 기준은 지금까지 OBJECT_MATCH 였으므로, 이런 객체를 어떻게 셀지 사용자께 여쭙습니다(기준을 결과를 본 뒤 제가 넓히지 않음).
- 사용자 결정(2026-10-26, AskUserQuestion): 이런 객체는 M5 §464 와 같이 "코드 검증 + bss 자리 reference-inferred" 라는 별도 분류로 받고, 상태표에서 OBJECT_MATCH 와 따로 셉니다(링크 배치 증명은 M7).

## 526. M4-32 D113 구현 계획 — 07 `src/machdep/m68k/autoconf.c` 와 NeXTMach 머리 셋, 별도 분류(코딩 전, 2026-10-26)

사용자 결정(D113, §525.2): NeXTMach `next/autoconf.c` 바탕 m68k 파일(D103). 머리는 NeXTMach 사본을 더하고 `next/cpu.h` 이름은 파일 안 매크로, `!= KERN_SUCCESS`, 원본에 없는 줄은 지우고 머리 주석에 적음, 일곱째 인수 `1`, 받아들임은 별도 분류.

1. 07 머리 사본(`07_kernel/nextmach/`, NeXTMach mk-108.1 에서):
   - `next/autoconf.h`: import 두 줄만 바꿈(`<kern/mach_types.h>` → `<mach/mach_types.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`, 표시 `plan 526 (D113)`). 스테이징 `src/bsd/next/autoconf.h`(D109 의 `next/cpu.h` 와 같은 자리; 스테이징의 SDK `dev/m68k/autoconf.h` 는 그대로).
   - `nextdev/scsireg.h`: 그대로. 스테이징 `src/bsd/dev/m68k/scsireg.h`.
   - `nextdev/scsivar.h`: `<nextdev/busvar.h>` → `<dev/busvar.h>`, 그리고 `struct reg_values` 를 위해 `#import <kernserv/printf.h>`(§524·§525.1; NeXTMach `next/printf.h` 의 자리)를 더함(표시). 스테이징 `src/bsd/dev/m68k/scsivar.h`.
2. 꼴 L(`08_build/artifacts/m4p526/src/autoconf_L.c`) = §525 D 에서:
   - include: `<next/cpu.h>` → `<m68k/cpu.h>`(D110 과 같음; `dma_chip`·`machine_type` 의 `extern`), `<next/scr.h>` 줄을 뺌, `<nextdev/scsireg.h>`·`<nextdev/scsivar.h>` → `<dev/m68k/scsireg.h>`·`<dev/m68k/scsivar.h>`, 진단 줄 `<kernserv/printf.h>` 를 뺌. `<next/autoconf.h>` 는 그대로(1 의 사본).
   - 파일 안(표시 `plan 526 (D113)`, 값은 NeXTMach `next/cpu.h`): `extern volatile int *intrmask; extern int intr_mask; extern int slot_id;`, `I`·`I_INDEX`·`I_IPL`·`I_BIT`, `I_IPL7_BITS`·`I_IPL6_BITS`·`I_IPL4_BITS`·`I_IPL3_BITS`, `I_SCC`·`I_REMOTE`·`I_BUS`·`I_SOFTINT1`·`I_SOFTINT0`, `SLOT_ID`·`P_EPROM`·`P_MAINMEM`, 그리고 `P_MEMSIZE` 는 §510 `mem.c` 와 같은 1997 식. `map_addr` 의 비교는 NeXTMach 글 `P_MAINMEM + P_MEMSIZE` 로 되돌림.
   - 먼저 run `m4p526-p1`(바탕 `m0p523-a1-stage`, 1 의 머리 셋은 `inc` 로)에서 L 을 컴파일해, §525 의 자료 조건(11/11, `_poll_intr`, 정의·COMMON 이 원본에 있음, 원본에 없는 COMMON 0)을 확인합니다. 어긋나면 기록하고 멈춥니다. L 의 COMMON 목록을 기대값으로 고정합니다.
3. 07 `src/machdep/m68k/autoconf.c` = L + 설명 주석 한 덩이(NeXTMach 바탕, 원본 주소, 뺀 줄 넷: `configure` 의 `master_cpu = 0;` 과 `set_cpu_number` 이후 덩이, `ioaccess` 의 `pflush_super();`, `slave_config` 덩이, `next/scr.h` import; 바꾼 줄: `map_addr` 의 `kmem_alloc_pageable`, `ioaccess` 의 일곱째 인수·`m68k_page_mask`; D024·D103·D113) + 표시 주석. 주석을 뺀 토큰 = L(python).
4. 도구:
   - `m4_m68k_probe.py`: 선택 키 `bss_inferred`(객체 이름 목록). 그 객체의 관문은 `candidate` 대신 `provisional`(L1 사유가 정확히 `__DATA,__bss: unverified` 하나, `full_span`)을 요구합니다. 키가 없으면 출력이 같아야 합니다(§523 최종 명세로 `compare` 를 다시 돌려 기록의 판정·관문 필드가 같음).
   - `m5_m68k_zerofill.py objs`: 이름이 `x86-` 로 시작하지 않으면 그대로 씀(기존 이름은 변화 없음).
   - `m4_m68k_status.py`: `ACCEPTED` 항목에 선택 셋째 값(zerofill 기록 경로, SHA-256). 그 객체는 L1 판정 `NOT_MATCH` 이고 사유가 정확히 `__DATA,__bss: unverified` 하나, `__text` 가 범위 시작에 놓임, zerofill 기록의 행이 같은 객체 SHA-256 이고 `ok`, `reference-inferred(-single)` 이어야 합니다. 열 `acceptance`(`OBJECT_MATCH` 또는 `CODE+BSS_INFERRED`)를 더하고, 요약에 둘을 나눠 셉니다. 회귀: 기존 12 기록만으로 돌린 출력이 지금 표와 새 열 말고 같음.
5. `stage_m68k.py`: `M4FILES[526]` = 523 목록 + `autoconf.c`, `M4HEADERS[526]` = 517 목록 + 1 의 셋, `EXCEPTS[526]` = 523.
   - 회귀: `--plan 523` 재생성 매니페스트 = `m0p523-a1-stage`; `--plan 526 stage` 와의 차이는 네 파일(`autoconf.c` 와 머리 셋).
   - M5 205 줄: 새 머리 셋의 스테이징 경로는 전에 없던 자리라 기존 줄이 읽을 수 없습니다. 스테이징 소스 전체에서 세 경로를 들이는 줄을 grep 해 0 건(새 `autoconf.c` 제외)임을 기록합니다.
6. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시 `m4_x86_inputs.py s6ll`, `--plan 526 x86gate`).
7. 확인 run `m4p526-p2`(바탕 `m0p526-a1-stage`, F = `@machdep/m68k/autoconf.c`, L(inc 없이), `m4_id` `m68k-210`): F·L `provisional`, 서로 canon·obj_sig 같음, `diag_gate` 참, `m68k_funcbytes.py` 11/11(대응 `4065c02=_bus_find`·`40b4f4e=_intr_spurious_count`); run `m4p526-e1` 에서 `-E` 토큰 F = L.
8. 최종 run `m4p526-a1`(REF = L 객체, `bss_inferred` [`autoconf`]): `gate.ok`. `m5_m68k_zerofill.py objs` 를 최종 객체에 돌려 `ok`. python 확인: 정의(함수 10 + `_poll_intr` + 고정한 COMMON 목록), 원본에 없는 정의 0, `_poll_intr` 32 B, 입력 사슬 07 = 스테이징 = run 사본(소스와 머리 셋), L1 `__text` 1904 B 가 0x4065bbc 에 놓이고 사유는 bss 하나, 후보 [0x40b4f4e, 0x40b4f52)가 기존 zerofill 기록의 후보들과 겹치지 않음, `next/cpu.h` 를 C 가 들이지 않음(`-M` 목록).
9. 기록: 상태표(`ACCEPTED` p526 + zerofill 기록; 객체·행·바이트·분류별 수는 python), PROVENANCE(`autoconf.c`, 머리 셋), MODIFICATIONS, DECISIONS D113, 근거 `m68k-autoconf.md`, diff(NeXTMach 대비) `m68k-autoconf.diff`, M7 의무(COMMON 합침, bss 배치, `intr_mask`·`intrmask`·`slot_id` 정의 객체).
관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 526.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `objs()` 는 행 `ok` 를 겹침 검사 전에 정하고, 기록을 쓴 뒤에 전체 assert 를 하므로, 겹침으로 실패한 명령의 기록에도 행 `ok` 가 참일 수 있음 | `m5_m68k_zerofill.py:144–157` 읽음(`json.dump` 153, `assert` 157) | ✅ 상태표 도구는 행 조건에 더해 `summary.not_ok`·`summary.overlaps` 가 비었음을 요구 |
| "기존 zerofill 기록의 후보" 는 진단 기록 `m4-m68k-zerofill-p525-D` 자신과 겹침 | 그 기록의 후보 [0x40b4f4e, 0x40b4f52) | ✅ 비교 대상을 m68k 의 받아들인 배치 기록(`m5-m68k-zerofill-20261016.json` 의 `candidates`, `m5-m68k-{nfs,ns_timer,p471,p474,p479,p480,p482,p483,p485,p488}-zerofill-*.json` 의 `summary.candidates`)으로 한정하고 `autoconf` 자신의 진단 기록은 뺌 |
| 회귀가 성공 경로만 봄; 거부 경로(목록에 없는 provisional, L1 사유 추가, zerofill 객체 SHA 불일치, 겹침 실패 요약)와 `x86-` 이름 재현, 상태표 두 번 실행·앞 행 보존(§523)을 명시할 것 | §523.2 의 7(두 번 돌린 출력 같음, 앞 13 행 그대로) 읽음 | ✅ 단계 4 에 거부 시험(임시 사본, 저장소 밖)과 §464 `objs` 재현을 더하고, 9 에 두 번 실행·앞 14 행 보존을 더함 |
| L 의 선언 형이 D 와 같음(`volatile int *intrmask` 등), 남은 본문은 `master_cpu`·`scr.h` 이름이 필요 없음, 새 머리 자리는 비어 있음 | `07_kernel/nextmach/next/cpu.h:66–106`·스테이징 `m68k/cpu.h:48,51` 읽음(이번 세션) | ✅ 계획 그대로; 같은 코드인지는 run `m4p526-p1` 로 확인 |

계획 수정:
- 4: 거부 시험(저장소 밖 임시 사본): probe — `bss_inferred` 에 없는 `provisional` 객체의 `gate` 거짓, L1 사유가 둘이면 거짓; 상태표 — zerofill 기록의 객체 SHA 불일치, `summary.overlaps` 가 빈 목록이 아님, L1 사유 추가 각각에서 멈춤. `m5_m68k_zerofill.py` 는 `x86-` 이름의 기존 입력으로 `m68k` 모드(§464) 출력이 기록과 같음.
- 8: 겹침 비교는 위의 받아들인 m68k 배치 기록과만.
- 9: 상태표를 두 번 돌려 출력이 같고, 앞 14 행이 새 열 말고 그대로임.

### 526.2 결과(2026-10-26)

- 1: 07 머리 사본 셋(`07_kernel/nextmach/next/autoconf.h` SHA-256 `d78100f6…`, `nextdev/scsireg.h` 그대로 `d0b16295…`, `nextdev/scsivar.h` `5ab5020a…`). NeXTMach 대비 차이는 표시한 import 줄뿐입니다(diff).
- 2: run `m4p526-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p526-p1-20261026.json`): 두 명령 종료 0·경고 0. L 은 `__text` 1904 B 로 D 와 바이트가 같고(재배치 목록은 기호 번호가 달라 다름), 11/11 함수(`m4-m68k-funcbytes-p526-p1-L-20261026.json`), `_poll_intr` 조건 충족, COMMON 24 개 모두 원본에 있음(원본에 없는 정의 0). 이 24 개를 기대값으로 고정했습니다.
- 3: 07 `src/machdep/m68k/autoconf.c`(426 행, SHA-256 `b6e4c0af…`)는 주석을 뺀 토큰 2156 개가 L 과 같습니다.
- 4: 도구.
  - `m4_m68k_probe.py`(456 → 462 행) `bss_inferred`: §523 최종 run 을 다시 `compare` 한 기록이 `tool_sha256` 말고 같고 L1 파일도 바이트가 같습니다. 거부 시험(저장소 밖 임시 명세): 목록에 없는 `provisional` → `all_candidates` 거짓, 목록에 있지만 L1 사유가 둘인 N1 → 거짓, 목록에 있는 L → 참.
  - `m5_m68k_zerofill.py`(173 행) 이름 처리: `x86-` 이름의 기존 `objs` 기록 셋(p483·p485·p488)을 다시 돌려 요약·행이 같습니다. 계획의 "`m68k` 모드 재현" 대신, 바뀐 줄을 실제로 지나는 `objs` 재현으로 했습니다.
  - `m4_m68k_status.py`(116 → 140 행): 기존 12 기록으로 돌린 표가 새 열 말고 같고 두 번 돌린 출력이 같습니다. 거부 시험(임시 사본): zerofill 행의 객체 SHA 불일치, `summary.overlaps` 가 비지 않음, 결론 `fail`, zerofill 기록 없이 등록, L1 사유 추가가 모두 멈추고, 참 기록만 받아들입니다.
- 5: `stage_m68k.py` 623 → 628 행. `--plan 523` 재생성 매니페스트가 `m0p523-a1-stage` 와 모든 키에서 같고, `--plan 526 stage m0p526-a1-stage`(916 파일)와의 차이는 네 파일(`autoconf.c` 와 머리 셋)입니다. 스테이징 전체에서 새 머리 셋을 들이는 줄은 `autoconf.c` 말고 0 건입니다.
- 6: x86 입력 불변(`m4-x86-inputs-p526-20261026.json` ok; `--plan 526 x86gate` 일곱 묶음 `same`, v183 경로 0).
- 7: run `m4p526-p2`(4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `m4-m68k-probe-p526-20261026.json`): F·L 모두 `provisional`(사유 bss 하나), 서로 canon·obj_sig 같음, 함수별 11/11(F·L), p1 의 L 과도 같음. run `m4p526-e1`: `-E` 토큰 14172 개가 같습니다.
- 8: run `m4p526-a1`(REF = p2 L `69279999…`, `bss_inferred` [`autoconf`]; 기록 `m4-m68k-p526-final-20261026.json`): `gate` 모두 참, 객체 SHA-256 `ff79ac49…`. zerofill(`m4-m68k-zerofill-p526-20261026.json`): `reference-inferred`, 후보 [0x40b4f4e, 0x40b4f52), 참조 2(`_intr_spurious` 안), 문제 0. python 확인(`m4-m68k-p526-checks-20261026.json`, `ok` 참): 정의(함수 10 + `_poll_intr` + COMMON 24)가 기대값과 같고 원본에 없는 정의 0, `_poll_intr` 32 B, 입력 사슬 07 = 스테이징 = run 사본(소스와 머리 셋), L1 `__text` 가 0x4065bbc 에 놓이고 사유는 bss 하나, 함수별 11/11, 받아들인 m68k 배치 28 개와 겹침 0, `-M` 목록에 `next/cpu.h`·`next/scr.h`·i386 없음.
- 9: 상태표 15 객체(OBJECT_MATCH 14, CODE+BSS_INFERRED 1), 행 35/188, 13660 B(6.33%; 도구 출력, python), 앞 14 행은 새 열 말고 그대로, 두 번 돌린 출력 같음(기록 `m4-m68k-status-p526-20261026.json`). PROVENANCE 1124 → 1128 행(경로 중복 0), MODIFICATIONS 670 → 674 행, DECISIONS D113(116 → 117 행), 근거 `06_reconstruction/evidence/m68k-autoconf.md`, diff `m68k-autoconf.diff`(174 행).
- 순서 오류(제 것): 상태표 도구를 근거 문서보다 먼저 돌려 "근거 문서 없음" 으로 멈췄습니다. 도구는 쓰기 전에 멈추므로 표는 바뀌지 않았고(cmp), 문서를 쓴 뒤 다시 돌렸습니다.

## 527. M4-33 세부 계획 — `next/kern_machdep.c` 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션, python): 남은 153 행 가운데 `nextdev/dma.h` 를 들이지 않고 경계가 정확한 작은 C 단위는 `snd_rcv`(24 B)·`kern_machdep`(84 B)·`us_timer`(188 B)입니다. `kern_machdep` 은 함수 둘뿐입니다.

확인한 사실(이번 세션; 원본 목록 `otool-V1/image.txt`, 기호표):
- 행 `m68k-275`(x86 이름 대응 `x86-kern_machdep`): [0x40929c6, 0x4092a1a), 84 B, 정확 경계. 함수 `_check_cpu_subtype` 38 B, `_grade_cpu_subtype` 46 B(이 순서). 앞 행 274(`kdp_machdep` 자리 13 개 8 B), 뒤 행 276(`kpmon_null`·`pmonlog*`).
- 0x40b5dd0 = `_machine_slot`(0x40b5dc8, `__common`) + 8 = `machine_slot[0].cpu_subtype`(스테이징 `mach/machine.h:156` 의 `struct machine_slot`: `is_cpu`, `cpu_type`, `cpu_subtype` …). 명령은 `machine_slot[0].cpu_subtype` 을 바로 읽습니다(`cpu_number()` 가 0 으로 접힌 것과 맞지만, 원문에 `[0]` 이라 쓴 것과도 같은 바이트일 수 있음).
- `_check_cpu_subtype`: 인수가 1 이거나 -1 이거나 `machine_slot[0].cpu_subtype` 과 같으면 1, 아니면 0(그 순서로 비교).
- `_grade_cpu_subtype`: 인수가 1 이거나 -1 이면 1, `machine_slot[0].cpu_subtype` 과 같으면 2, 아니면 0. `d2` 를 저장합니다.
- 스테이징 `mach/machine.h:215,255`: `CPU_SUBTYPE_MULTIPLE` = -1, `CPU_SUBTYPE_MC680x0_ALL` = 1(`CPU_SUBTYPE_MC68030` 도 1, 호환).
- 참고 글(같은 이름 파일 전부): NeXTMach `next/kern_machdep.c`(1990, `check_cpu_subtype` 만, 68030/68040 비교), x86 07 `machdep/i386/kern_machdep.c`(Darwin 0.1 i386 판, i386 switch, `grade_cpu_subtype` 1991 추가), Darwin 0.1 `machdep/ppc/kern_machdep.c`(1998 PowerPC). 어느 것도 1997 m68k 본문과 같지 않습니다. 본문은 원본 바이트로 씁니다(D024).

방법(진단; 명세 `08_build/artifacts/m4p527/spec.json`, run `m4p527-p1`, 바탕 `m0p526-a1-stage`, 줄 틀은 `machdep/i386/dkbad.c` 의 x86 줄(§496; §527.1 참조), `m4_id` `m68k-275`):
- 공통: NeXTMach 파일의 머리 주석, include 는 `<sys/types.h>`, `<mach/machine.h>`(NeXTMach `<sys/machine.h>`; x86 07 과 같음), `<m68k/cpu.h>`(NeXTMach `<next/cpu.h>`, D110; `cpu_number()`), K&R 정의 `check_cpu_subtype (cpu_subtype) cpu_subtype_t cpu_subtype;` 와 같은 꼴의 `grade_cpu_subtype`, 지역 `struct machine_slot *ms = &machine_slot[cpu_number()];`.
- 변형 A(if 꼴):
  - check: `if (cpu_subtype == CPU_SUBTYPE_MC680x0_ALL || cpu_subtype == CPU_SUBTYPE_MULTIPLE || cpu_subtype == ms->cpu_subtype) return (TRUE); return (FALSE);`
  - grade: `if (cpu_subtype == CPU_SUBTYPE_MC680x0_ALL || cpu_subtype == CPU_SUBTYPE_MULTIPLE) return 1; if (cpu_subtype == ms->cpu_subtype) return 2; return 0;`
- 변형 B(switch 꼴, x86 07 의 짜임에 가까움):
  - check: `switch (cpu_subtype) { case CPU_SUBTYPE_MC680x0_ALL: case CPU_SUBTYPE_MULTIPLE: return (TRUE); } if (cpu_subtype == ms->cpu_subtype) return (TRUE); return (FALSE);`
  - grade: `switch (cpu_subtype) { case CPU_SUBTYPE_MC680x0_ALL: case CPU_SUBTYPE_MULTIPLE: return 1; } if (cpu_subtype == ms->cpu_subtype) return 2; return 0;`
- 변형 N(기준): NeXTMach 글에 include 대응만(`<mach/machine.h>`·`<m68k/cpu.h>`). 원본과 다름을 기록하는 용도입니다.
- 측정: `compare`(`diag_gate`, 옵션, `full_span`, L1, 정의·COMMON 이 원본에 있음, 미정의), `m68k_funcbytes.py 40929c6 4092a1a`, 객체 기호표.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- A·B 가운데 `__text` 84 B, 2/2 함수 같음, `candidate`(OBJECT_MATCH), 원본에 없는 정의 0 인 꼴이 있으면, 같은 객체를 내는 꼴들을 사용자께 보여 드리고 07 꼴(파일 자리 D103, 꼴)을 여쭙니다.
- 없으면 함수별 차이를 적고 멈춥니다(이번 run 에 변형을 더하지 않음).
관문(어긋나면 멈춤): 명령 종료 상태 기록, i386 머리 0(N·A·B 모두 `<m68k/cpu.h>`), 옵션이 M5 줄과 같음, 경고 기록.

### 527.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| x86 `machdep/i386/kern_machdep.c` 줄은 `-g -O2 -fno-omit-frame-pointer` 이고 `-Isrc/components/driverkit-1` 이 없어, `x86_line()` 의 `-O3` 조건에서 멈춤 | `s6l4-g1a.cmd:5` 에서 `-O2`·`driverkit-1` 0 건 확인, `m4_m68k_probe.py:179–184` 읽음 | ✅ 제 오류입니다. 줄 틀을 §496 의 `dkbad.c` 로 바꿈 |
| 행의 `x86_source` 는 있을 필요가 없음(`span` 은 경계만, 변형은 주어진 경로) | §524·§525 에서 x86 짝 없이 `dkbad.c` 틀로 돌린 선례 | ✅ |
| "`cpu_number()` 가 0 으로 접힘" 은 원문에 대한 추정; 바이트 사실은 `machine_slot[0].cpu_subtype` 직접 접근 | 원본 0x40929da `cmpl 0x40b5dd0:l,d0` | ✅ 문장을 고침 |
| `TRUE`/`FALSE` 는 `mach/machine.h` → `mach/boolean.h`, `cpu_number()` 는 `NCPUS 1` 이라 `(0)`, i386 머리·COMMON 없음 | 스테이징 `bsd/m68k/cpu.h:34–75`·`generated/cpus.h` 읽음 | ✅ 계획 그대로(컴파일로 확인) |
| 조건식·직접 불리언 반환 같은 다른 꼴도 있을 수 있고, B 의 비교 순서는 컴파일로만 정해짐 | 시험 전이라 확인할 수 없음 | ⏭️ A·B 결과를 본 뒤, 같은 객체를 내는 꼴만 여쭘 |

### 527.2 결과(2026-10-26)

- run `m4p527-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p527-20261026.json`): 여섯 명령 종료 0·경고 0, i386 머리 0, 옵션 = M5 줄(`diag_gate` 참).
- A(if 꼴): `__text` 84 B, L1 `OBJECT_MATCH`, `candidate`, 2/2 함수 같음(`m4-m68k-funcbytes-p527-A-20261026.json`). 정의는 두 함수뿐이고 COMMON·원본에 없는 미정의 0 입니다.
- B(switch 꼴): `__text` 92 B, `check_cpu_subtype` 46/38 B, `grade_cpu_subtype` 는 길이가 같고 2 B 다름. 원본과 다릅니다.
- N(NeXTMach 글): `check_cpu_subtype` 58 B, `grade_cpu_subtype` 없음.
- 판정: 미리 정한 첫 갈래입니다. 같은 객체를 내는 꼴은 시험한 것 가운데 A 하나입니다. 07 꼴을 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): "다른 꼴도 더 시험" — 같은 바이트가 될 수 있는 꼴을 더 시험한 뒤 다시 여쭙니다(§528).

## 528. M4-34 세부 계획 — `kern_machdep` 의 다른 꼴 진단(07 변경 없음; 코딩 전, 2026-10-26)

방법(명세 `08_build/artifacts/m4p528/spec.json`, run `m4p528-p1`, 바탕·줄 틀·`m4_id` 는 §527 과 같음; 머리 주석·include·K&R 정의는 §527 공통과 같음). 대조로 A 를 다시 넣고, 아래 다섯 꼴을 더합니다. 각 꼴은 두 함수를 같은 결로 씁니다.
- C(불리언 식 반환): check `return (cpu_subtype == CPU_SUBTYPE_MC680x0_ALL || cpu_subtype == CPU_SUBTYPE_MULTIPLE || cpu_subtype == ms->cpu_subtype);`; grade 는 A 의 첫 `if` 뒤 `return (cpu_subtype == ms->cpu_subtype) ? 2 : 0;`
- D(조건식): check `return (… || … || …) ? TRUE : FALSE;`; grade `return (… || …) ? 1 : ((cpu_subtype == ms->cpu_subtype) ? 2 : 0);`
- E(지역 `ms` 없음): A 와 같은 `if` 짜임에서 `ms->cpu_subtype` 대신 `machine_slot[cpu_number()].cpu_subtype`.
- F(낱낱 `if`): check `if (== ALL) return (TRUE); if (== MULTIPLE) return (TRUE); if (== ms->cpu_subtype) return (TRUE); return (FALSE);`; grade 도 `ALL`·`MULTIPLE` 을 따로 `if`.
- H(`default` 가 있는 switch): `switch (cpu_subtype) { case ALL: case MULTIPLE: return …; default: if (cpu_subtype == ms->cpu_subtype) return …; return …; }`(§527 B 에 `default` 를 더한 꼴).
- 이름 표기(`CPU_SUBTYPE_MC680x0_ALL` 대신 `CPU_SUBTYPE_MC68030` 이나 숫자 `1`, `-1`)는 전처리 뒤 같은 형·값이라 시험하지 않고, 07 꼴을 여쭐 때 함께 보입니다.
- 측정: §527 과 같음(`compare`, `m68k_funcbytes.py`, 꼴마다 A 와의 canon·obj_sig 같음).

판정(미리 정함; 07 은 바꾸지 않음): A 와 같은 객체(canon·obj_sig)를 내는 꼴을 모두 적고, 그 꼴들 가운데 07 꼴을 사용자께 여쭙니다. 다른 꼴은 함수별 차이만 적습니다.
관문: §527 과 같음.

### 528.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `obj_sig` 는 STABS 수를 포함하므로(`-g`), 실행 바이트가 같아도 문장 배치가 다르면 "같은 객체" 에서 떨어질 수 있음 | `l2_prefix_diff.py:48–53` 읽음(`stabs=` 합) | ✅ 같음 판정은 canon(섹션 바이트·재배치) + `obj_sig` 의 header·sections·symbols(STABS 수 제외) + L1 `OBJECT_MATCH` + 함수별 같음으로 함 |
| 비교 순서 바꿈, 피연산자 뒤집기(`ms->cpu_subtype == cpu_subtype`), `register` 선언, 명시 `int` K&R, ANSI 정의, `[0]` 직접 색인도 대표 꼴로 시험할 것 | 계획에 없었음(읽음) | ✅ 꼴 I·J·K·R·S·Z 를 더함 |
| 두 함수를 같은 결로 묶으면 한 함수만 맞는 꼴이 가려짐 → 함수별로 적고, 고른 조합은 따로 컴파일해 확인 | `m68k_funcbytes.py` 는 함수별 결과를 냄 | ✅ 결과는 함수별 표로 적고, 사용자가 고른 조합은 구현 계획에서 컴파일로 확인 |
| `CPU_SUBTYPE_MC68030`·숫자 `1`·`-1` 은 같은 형·값(`cpu_subtype_t` = `integer_t` = `int`) | 스테이징 `mach/machine.h:148,215,255`·`mach/m68k/vm_types.h:95` 읽음 | ✅ 계획 그대로(전처리 토큰은 다름) |

더한 꼴(각 꼴은 A 에서 그 점만 바꿈, 두 함수 모두에 적용):
- I: 피연산자 뒤집기(`CPU_SUBTYPE_MC680x0_ALL == cpu_subtype`, `ms->cpu_subtype == cpu_subtype` 등).
- J: `||` 의 순서를 `MULTIPLE` 먼저로(grade 의 특별값 우선은 유지).
- K: `register struct machine_slot *ms` 와 `register cpu_subtype_t cpu_subtype`.
- R: 명시 반환형 `int` 의 K&R 정의.
- S: ANSI 정의 `int check_cpu_subtype(cpu_subtype_t cpu_subtype)`.
- Z: 지역 `ms` 없이 `machine_slot[0].cpu_subtype`.

### 528.2 결과(2026-10-26)

- run `m4p528-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p528-20261026.json`, 함수별 `m4-m68k-funcbytes-p528-{A,…,Z}-20261026.json`, 표 `m4-m68k-p528-forms-20261026.json`): 24 명령 종료 0·경고 0, i386 머리 0, 옵션 = M5 줄. 대조 A 는 §527 A 와 canon·서명이 같습니다.
- 꼴별(“같음” = A 와 canon 같음, STABS 수를 뺀 `obj_sig` 같음, L1 `OBJECT_MATCH`; 함수 칸은 원본과의 함수별 비교, 다르면 객체/원본 길이):

| 꼴 | `__text` | 같음 | STABS | check | grade |
|---|---|---|---|---|---|
| A if 묶음 | 84 | 기준 | 98 | 같음 | 같음 |
| C 불리언 식 반환 | 88 | 아님 | 93 | 42/38 | 46/46(바이트 다름) |
| D 조건식 | 88 | 아님 | 91 | 42/38 | 46/46(바이트 다름) |
| E `machine_slot[cpu_number()]` 직접 | 84 | 같음 | 92 | 같음 | 같음 |
| F 낱낱 if | 92 | 아님 | 103 | 46/38 | 같음 |
| H default 있는 switch | 92 | 아님 | 101 | 46/38 | 46/46(바이트 다름) |
| I 피연산자 뒤집기 | 84 | 같음 | 98 | 같음 | 같음 |
| J `MULTIPLE` 먼저 | 84 | 아님 | 98 | 38/38(바이트 다름) | 46/46(바이트 다름) |
| K `register` | 84 | 같음 | 98 | 같음 | 같음 |
| R 명시 `int` K&R | 84 | 같음 | 98 | 같음 | 같음 |
| S ANSI 정의 | 84 | 같음 | 98 | 같음 | 같음 |
| Z `machine_slot[0]` 직접 | 84 | 같음 | 92 | 같음 | 같음 |

- 정해진 것(원본 바이트): 비교 순서(`MC680x0_ALL`, `MULTIPLE`, `cpu_subtype` 순; J 는 다름)와 `check` 의 `||` 묶음 `if`(C·D·F·H 는 다름).
- 바이트로 정해지지 않는 것: `grade` 의 묶음/낱낱 `if`(A·F), `ms` 지역 사용(A)·`machine_slot[cpu_number()]`(E)·`machine_slot[0]`(Z), 피연산자 순서(A·I), `register`(K), 정의 꼴(K&R 암시 `int` A, 명시 `int` R, ANSI S), 이름 표기(`MC680x0_ALL`·`MC68030`·숫자). 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): 정의는 ANSI(S), `machine_slot` 접근은 지역 `ms`(A), `grade` 의 특별값 검사는 낱낱 `if`(F 의 grade), 표기는 `CPU_SUBTYPE_MC680x0_ALL`·`CPU_SUBTYPE_MULTIPLE` 에 변수 왼쪽, `register` 없음(A). 이 조합은 아직 컴파일하지 않았습니다(§528.1).

## 529. M4-35 D114 구현 계획 — 07 `src/machdep/m68k/kern_machdep.c`(코딩 전, 2026-10-26)

1. 꼴 L(`08_build/artifacts/m4p529/src/kern_machdep_L.c`) = §528 S 에서 `grade_cpu_subtype` 본문을 F 의 낱낱 `if` 로 바꾼 글. S 대비 차이는 그 본문뿐이어야 합니다(python diff).
2. 07 `src/machdep/m68k/kern_machdep.c`(D103) = L + 설명 주석 한 덩이(NeXTMach `next/kern_machdep.c` 의 머리 주석은 그대로; include 셋은 OPENSTEP 이름 `<mach/machine.h>`·`<m68k/cpu.h>`(D104·D110); 두 함수 본문은 원본 바이트로 씀(D024; NeXTMach·x86 07·Darwin 0.1 ppc 와 다름), `machine_slot[0].cpu_subtype` 은 0x40b5dd0, 비교 순서) + 표시 주석 `plan 529`. 주석을 뺀 토큰 = L(python).
3. `stage_m68k.py`: `M4FILES[529]` = 526 목록 + `kern_machdep.c`, `M4HEADERS[529]` = 526 목록, `EXCEPTS[529]` = 526. 회귀: `--plan 526` 재생성 매니페스트 = `m0p526-a1-stage`; `--plan 529 stage m0p529-a1-stage` 와의 차이는 `kern_machdep.c` 하나. M5 205 줄은 이 파일을 읽지 않습니다(새 `src/machdep/m68k/` 파일; §520.1 과 같은 이유).
4. x86 입력 불변(`m4_x86_inputs.py s6ll`, `--plan 529 x86gate`). x86 의 `src/machdep/i386/kern_machdep.c` 는 바꾸지 않습니다.
5. 확인 run `m4p529-p1`(바탕 `m0p529-a1-stage`, F = `@machdep/m68k/kern_machdep.c`, L, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` `m68k-275`): F·L `candidate`, F·L canon 같음과 STABS 수를 뺀 `obj_sig` 같음, `diag_gate` 참, `m68k_funcbytes.py` 2/2. L 이 `candidate` 가 아니면 기록하고 멈춥니다(사용자께 다시 여쭘). run `m4p529-e1` 에서 `-E` 토큰 F = L.
6. 최종 run `m4p529-a1`(REF = L 객체): `gate.ok`. python 확인(`m4-m68k-p529-checks-20261026.json`): 정의는 `_check_cpu_subtype`·`_grade_cpu_subtype` 뿐(COMMON 0), 원본에 없는 미정의 0, 입력 사슬 07 = 스테이징 = run 사본, L1 `__text` 84 B 가 0x40929c6 에 놓이고 사유 없음, 함수별 2/2, `-M` 목록에 `next/cpu.h`·i386 없음.
7. 기록: 상태표 `ACCEPTED` p529(예상 16 객체, OBJECT_MATCH 15; 행·바이트는 python; 두 번 실행 같음, 앞 15 행 그대로), PROVENANCE(`nextmach+authored`: 머리 주석은 NeXTMach, 본문은 D024), MODIFICATIONS, DECISIONS D114, 근거 `m68k-kern_machdep.md`, diff(NeXTMach 대비) `m68k-kern_machdep.diff`.
관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 529.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 4 에 `L2_FORMS`/`L2_EXPECT` 를 명시하지 않음 | §523·§526 의 단계 읽음, `m4-x86-inputs-p526-20261026.json` | ✅ 제 누락입니다. §526 과 같은 두 파일로 명시 |
| PROVENANCE 는 URL·커밋·경로·고지·함수별 출처를 갖추고, NeXTMach 에서 온 `ms` 선언 줄(`next/kern_machdep.c:21`)을 밝힐 것 | NeXTMach `:21` 읽음 | ✅ |
| 고른 글의 `ms` 선언은 Darwin 0.1 `ppc/kern_machdep.c:58`·`i386/kern_machdep.c:48` 과, `if (cpu_subtype == ms->cpu_subtype)` 는 `ppc:109` 와 같은 줄 → D027 표기 | 세 줄 읽음, `DECISIONS.md:31`(D027) 읽음 | ✅ PROVENANCE·MODIFICATIONS·근거 문서에 "몇 줄은 Darwin 0.1 과 같은 꼴(D027), 원본 바이트로 씀" 을 적음 |
| 이름 충돌 없음, F·L 은 주석만 달라 STABS 수까지 같을 것 | 계획 3 의 회귀로 확인 예정 | ⏭️ 5 에서 STABS 를 포함한 `obj_sig` 도 같음을 요구 |

### 529.2 결과(2026-10-26)

- 1–2: L(`08_build/artifacts/m4p529/src/kern_machdep_L.c`)은 §528 S 와 `grade_cpu_subtype` 본문만 다릅니다(diff). 07 `src/machdep/m68k/kern_machdep.c`(55 행, SHA-256 `2cc1afc2…`)는 주석을 뺀 토큰 137 개가 L 과 같습니다.
- 3: `stage_m68k.py` 628 → 632 행. `--plan 526` 재생성 매니페스트 = `m0p526-a1-stage`(모든 키), `--plan 529 stage m0p529-a1-stage`(917 파일)와의 차이는 `kern_machdep.c` 하나입니다.
- 4: x86 입력 불변(`m4-x86-inputs-p529-20261026.json` ok, `L2_FORMS`/`L2_EXPECT` 명시; `--plan 529 x86gate` 일곱 묶음 `same`, v183 경로 0). x86 `machdep/i386/kern_machdep.c` 는 바뀌지 않았습니다(git).
- 5: run `m4p529-p1`(4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `m4-m68k-probe-p529-20261026.json`): F·L 모두 `candidate`, 서로 canon·`obj_sig`(STABS 수 포함) 같음, 함수별 2/2. 고른 조합은 처음 컴파일한 것인데 원본과 같습니다. run `m4p529-e1`: `-E` 토큰 563 개가 같습니다.
- 6: run `m4p529-a1`(REF = p1 L `e7393fc6…`; 기록 `m4-m68k-p529-final-20261026.json`): `gate` 모두 참, 객체 SHA-256 `ac391604…`. python 확인(`m4-m68k-p529-checks-20261026.json`, `ok` 참): 정의는 두 함수뿐(COMMON 0), 원본에 없는 미정의 0, 입력 사슬 07 = 스테이징 = run 사본, L1 `__text` 84 B 가 0x40929c6 에 놓이고 사유 없음, 2/2, `-M` 에 `next/cpu.h`·i386 없음.
- 7: 상태표 16 객체(OBJECT_MATCH 15, CODE+BSS_INFERRED 1), 행 36/188, 13744 B(6.37%; 도구 출력, python), 앞 15 행 그대로, 두 번 돌린 출력 같음(`m4-m68k-status-p529-20261026.json`; `m4_m68k_status.py` 140 → 141 행). PROVENANCE 1128 → 1129 행(경로 중복 0), MODIFICATIONS 674 → 675 행, DECISIONS D114(117 → 118 행), 근거 `06_reconstruction/evidence/m68k-kern_machdep.md`, diff `m68k-kern_machdep.diff`(58 행).

## 530. M4-36 세부 계획 — 행 274 `kdp_machdep` 자리 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션): 남은 작은 단위 가운데 `snd_rcv`(24 B)는 NeXTMach `nextdev/snd_var.h` 가 `nextdev/dma.h` 를 들여(python 으로 include 사슬을 따라감) 보류 중인 `dma.h` 결정과 엮이므로 미룹니다. 행 274 는 `dma.h` 와 무관합니다.

확인한 사실(이번 세션; 원본 목록, 기호표, python):
- 행 `m68k-274`(x86 이름 대응 `x86-kdp_machdep`): [0x409295e, 0x40929c6), 104 B, 정확 경계, 진입점 13 개 모두 8 B 이고 모두 `pea a6@; movel sp,a6; unlk a6; rts` 입니다(값을 돌려주는 함수에도 `d0` 설정 없음; 빈 몸통과 맞는 바이트이지만, 원문 몸통·시그니처 자체는 바이트로 정해지지 않음).
- 순서: `kdp_exception`, `kdp_exception_ack`, `kdp_machine_read_regs`, `kdp_machine_write_regs`, `kdp_machine_hostinfo`, `kdp_panic`, `kdp_reboot`, `kdp_intr_disbl`, `kdp_intr_enbl`, `kdp_en_send_pkt`, `kdp_en_recv_pkt`, `kdp_us_spin`, `kdp_flush_cache`.
- 같은 이름 파일(전부): 07 x86 `machdep/i386/kdp_machdep.c`(Darwin 0.1 i386 바탕 + 이 프로젝트가 원본 바이트로 쓴 `kdp_en_send_pkt`·`kdp_en_recv_pkt` 래퍼, APSL; i386 상태 함수 `kdp_getstate`·`kdp_setstate`(외부 연결)를 빼면 정의 순서가 m68k 13 개와 같음), Darwin 0.1 `machdep/i386/kdp_machdep.c`(래퍼 둘 없음), Darwin 0.1 `machdep/ppc/kdp_machdep.c`(순서·함수 다름). NeXTMach 에는 없습니다.
- 원형: 스테이징 `kern/kdp_internal.h:63–130` 에 열한 함수(래퍼 둘은 없음). x86 07 정의의 반환형은 `kdp_machine_read_regs`·`kdp_machine_write_regs` 가 `kdp_error_t`, `kdp_intr_disbl` 이 `int`, 나머지는 `void` 입니다.

방법(명세 `08_build/artifacts/m4p530/spec.json`, run `m4p530-p1`, 바탕 `m0p529-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` `m68k-274`):
- 변형 P(원형 꼴): `#import <mach/boolean.h>`, `#import <kern/kdp_internal.h>` 와 13 정의. 시그니처는 x86 07 판과 같고 몸통은 비움(래퍼 둘의 시그니처도 x86 07 판 그대로).
- 변형 K(최소 K&R 꼴): include 없이 13 개를 `kdp_exception() {}` 처럼 암시 `int` 빈 함수로.
- 측정: `compare`(`diag_gate`, 옵션, `full_span`, L1, 정의·COMMON 이 원본에 있음, 미정의), `m68k_funcbytes.py 409295e 40929c6`, 객체 기호표(COMMON 이 생기면 이름·크기).

판정(미리 정함; 07 은 바꾸지 않음): P·K 가운데 `__text` 104 B, 13/13 함수 같음, `candidate`, 원본에 없는 정의 0 인 꼴이 있으면 07 꼴(파일 자리, 머리 주석과 출처: x86 07 판 머리(APSL)를 가져갈지, 이 프로젝트 작성 머리로 할지, 시그니처 꼴)을 사용자께 여쭙니다. 없으면 차이를 적고 멈춥니다.
관문: 명령 종료 0, i386 머리 0, 옵션 = M5 줄, 경고 기록.

### 530.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `kern/kdp_internal.h:38` 이 `boolean_t` 를 쓰지만 그 import 사슬(`kdp.h`, `kdp_protocol.h` → `mach/vm_prot.h`)에 정의가 없어 P 는 실패함 | 스테이징 `kdp_internal.h:32–46`, `kdp_protocol.h:43` 읽음 | ✅ P 에 `<mach/boolean.h>` 를 먼저 둠 |
| x86 07 의 `kdp_getstate`·`kdp_setstate` 는 정적이 아님 | x86 07 `kdp_machdep.c:70–71,99–100` 읽음(`void` 만, `static` 없음) | ✅ 제 오기입니다. 사실 줄을 고침 |
| `compare` 는 정의·COMMON 이 원본에 있는지를 강제하지 않음; `diag_gate` 는 모든 명령의 경고 0 을 요구하므로 변형별 자격과 전체 관문을 나눌 것 | `m4_m68k_probe.py:324–345,364` 읽음 | ✅ 정의 기호(지역 포함)를 원본 기호표와 python 으로 대조하고, 변형별로 종료 상태·경고를 따로 적음 |
| "몸통이 빈 함수" 는 추론 | 원본 목록 읽음 | ✅ 사실 줄을 고침 |
| 원본의 kdp 자료 기호는 `__common` 의 `_kdp` 하나이고 x86 은 `kern/kdp.c:87` 에서 정의; `kdp_internal.h:46` 은 `extern` | 기호표 awk(이번 세션), `kdp_internal.h:46` 읽음 | ✅ m68k `kdp_machdep` 객체가 자료를 정의할 근거 없음 |

### 530.2 결과(2026-10-26)

- run `m4p530-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p530-20261026.json`): 네 명령(P·K 의 컴파일과 `-M`) 모두 종료 0·경고 0, i386 머리 0, 옵션 = M5 줄.
- P·K 모두 `__text` 104 B, L1 `OBJECT_MATCH`, `candidate`, 13/13 함수 같음(`m4-m68k-funcbytes-p530-{P,K}-20261026.json`). 정의는 외부 함수 13 개뿐이고(지역 정의·COMMON·자료 0), 모두 원본 기호표에 있습니다(python). P·K 는 canon(섹션 바이트·재배치)이 같고, `obj_sig` 차이는 STABS 수뿐입니다.
- 판정: 미리 정한 첫 갈래입니다. 07 꼴(머리 주석과 출처, 시그니처 꼴)을 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): x86 판 머리·시그니처 + 빈 몸통(선택지 "x86 판 머리·시그니처 + 빈 몸통").

## 531. M4-37 D115 구현 계획 — 07 `src/machdep/m68k/kdp_machdep.c`(코딩 전, 2026-10-26)

1. 꼴 L(`08_build/artifacts/m4p531/src/kdp_machdep_L.c`): x86 07 `machdep/i386/kdp_machdep.c`(SHA-256 `da5772be…`, 커밋 `7d3f5b51…`; 1–23 행 APSL 고지는 Darwin 0.1 `machdep/i386/kdp_machdep.c`(SHA-256 `0736699f…`)와 같음)에서:
   - 1–23 행 APSL 고지 그대로, 25 행 변경 표시는 `/* Modified 2026-10-26: see 07_kernel/MODIFICATIONS.md */`, NeXT 1993 머리 주석(27–38 행) 그대로;
   - m68k 설명 주석 한 덩이(plan 531, D024·D103·D115: 1997 m68k 원본 0x409295e–0x40929c6 의 13 함수는 모두 8 B 의 `pea a6@; movel sp,a6; unlk a6; rts` 이고(원문 몸통·시그니처는 바이트로 정해지지 않으며 빈 몸통은 고른 재구성), 순서는 x86 판의 i386 상태 함수 둘을 뺀 정의 순서와 같음, 시그니처는 x86 판 그대로, 몸통은 비움);
   - include 는 `<mach/boolean.h>`(표시 plan 531; §530.1)와 x86 판의 `<kern/kdp_internal.h>` 둘;
   - 13 함수는 x86 판 시그니처 줄 그대로에 빈 몸통 `{` `}`. x86 판의 나머지(i386 include, `dprintf`, `extern`, `kdp_getstate`·`kdp_setstate`, 몸통)는 넣지 않습니다.
   - L 은 §530 P 와 토큰이 다른 것은 주석뿐이어야 합니다(python, 주석 뺀 토큰 = P 의 토큰).
2. 07 `src/machdep/m68k/kdp_machdep.c`(D103) = L.
3. `stage_m68k.py`: `M4FILES[531]` = 529 목록 + `kdp_machdep.c`, `M4HEADERS[531]` = 529, `EXCEPTS[531]` = 529. 회귀: `--plan 529` 재생성 = `m0p529-a1-stage`, `--plan 531 stage m0p531-a1-stage` 와의 차이는 이 파일 하나.
4. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시 `m4_x86_inputs.py s6ll`, `--plan 531 x86gate`); x86 `kdp_machdep.c` 는 바꾸지 않음.
5. 확인 run `m4p531-p1`(F = `@machdep/m68k/kdp_machdep.c`, L, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` `m68k-274`): F·L `candidate`, canon·`obj_sig`(STABS 포함) 같음, 13/13, 객체가 §530 P 와 canon·`obj_sig`(STABS 수 포함) 같음; run `m4p531-e1` 에서 `-E` 토큰 F = L.
6. 최종 run `m4p531-a1`(REF = L): `gate.ok`; python 확인: 정의는 13 함수뿐(지역·COMMON·자료 0, 모두 원본에 있음), 원본에 없는 미정의 0, 입력 사슬, L1 `__text` 104 B 가 0x409295e 에 사유 없이 놓임, `-M` 에 i386 없음.
7. 기록: 상태표(예상 17 객체, OBJECT_MATCH 16; 두 번 실행 같음, 앞 16 행 그대로), PROVENANCE(`darwin01+authored`: 고지·머리 주석·11 시그니처는 Darwin 0.1 i386, `kdp_en_send_pkt`·`kdp_en_recv_pkt` 시그니처는 이 프로젝트 x86 판(D016), 빈 몸통과 m68k 주석은 D024; `07_kernel/LICENSES/APSL-1.0.txt`), MODIFICATIONS, DECISIONS D115, 근거 `m68k-kdp_machdep.md`, diff(x86 07 판 대비) `m68k-kdp_machdep.diff`.
관문: 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 531.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 설명 주석의 "8 B 빈 함수" 는 바이트가 정하는 것보다 많이 말함(§530 의 단서를 되살릴 것) | §530 사실 줄(이번 세션에 고친 줄) 읽음 | ✅ 문장을 고침 |
| P 와의 비교에 STABS 수 포함 `obj_sig` 도 요구할 것(P 의 STABS 166) | §530.2 에서 python 으로 낸 P 166·K 60 | ✅ |
| PROVENANCE 에 Darwin 보관본 해시·경로·함수 위치와 래퍼 시그니처의 이 프로젝트 판·위치를 밝힐 것(`7d3f5b51…` 은 이 프로젝트 커밋) | PROVENANCE 201 행(kernel-1.tar.gz sha256 `0c19349b…`) 읽음 | ✅ 기록 단계에서 그대로 적음 |
| APSL + NeXT 머리 유지와 `darwin01+authored` 표기, "Modified" 줄 꼴은 규칙에 맞음(D030 은 kernel/machdep 제외) | AGENTS.md, D030 | ✅ 계획 그대로 |

### 531.2 결과(2026-10-26)

- 1–2: L(`08_build/artifacts/m4p531/src/kdp_machdep_L.c`)은 주석을 뺀 토큰 191 개가 §530 P 와 같고, 13 시그니처는 i386 07 판의 줄 그대로입니다(python). 07 `src/machdep/m68k/kdp_machdep.c`(140 행, SHA-256 `31f48964…`) = L.
- 3: `stage_m68k.py` 632 → 636 행. `--plan 529` 재생성 = `m0p529-a1-stage`(모든 키), `--plan 531 stage m0p531-a1-stage`(918 파일)와의 차이는 `kdp_machdep.c` 하나.
- 4: x86 입력 불변(`m4-x86-inputs-p531-20261026.json` ok; `--plan 531 x86gate` 일곱 묶음 `same`, v183 경로 0); i386 `kdp_machdep.c` 그대로(git).
- 5: run `m4p531-p1`(기록 `m4-m68k-probe-p531-20261026.json`, 4 명령 종료 0·경고 0, i386 머리 0): F·L `candidate`, canon·`obj_sig` 같음, 13/13, L 은 §530 P 와 canon·`obj_sig`(STABS 166 포함) 같음. run `m4p531-e1`: `-E` 토큰 1052 개 같음.
- 6: run `m4p531-a1`(REF = p1 L; `m4-m68k-p531-final-20261026.json`): `gate` 모두 참, 객체 SHA-256 `49ee7a9d…`. python 확인(`m4-m68k-p531-checks-20261026.json`, `ok` 참): `__text` 104 B 하나, 외부 함수 13 개만 정의(모두 원본에 있음), 원본에 없는 미정의 0, 입력 사슬, L1 0x409295e 사유 없음, 13/13, i386 머리 없음.
- 7: 상태표 17 객체(OBJECT_MATCH 16, CODE+BSS_INFERRED 1), 행 37/188, 13848 B(6.41%), 앞 16 행 그대로, 두 번 돌린 출력 같음(`m4-m68k-status-p531-20261026.json`; `m4_m68k_status.py` 141 → 142 행). PROVENANCE 1129 → 1130 행(경로 중복 0), MODIFICATIONS 675 → 676 행, DECISIONS D115(118 → 119 행), 근거 `06_reconstruction/evidence/m68k-kdp_machdep.md`, diff `m68k-kdp_machdep.diff`(274 행).

## 532. M4-38 세부 계획 — `next/clock.c` 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션, python):
- 행 269 `_delay`(188 B)는 §416 경계 표에서 0x40922cc–0x4092436 이름 미대응 덩이(`__set_timer`·`_clear_timer`·`_delay`, 362 B)에 들고, 그 앞 `machine_clock` 덩이와 함수 순서가 x86 07 `machine_clock.c`(D024) 와 나란합니다. 이것이 한 객체라는 것은 가설입니다(§495 인벤토리는 268·269 를 나눔). 객체 경계와 최대 1566 B 의 바이트 작성이 걸린 큰 단위라 뒤로 미룹니다. NeXTMach `us_timer.c` 의 다른 함수(`microtime`·`microboot`·`us_timeout` 등)는 원본 0x404e98c 부근에 따로 있습니다.
- 행 276(`kpmon_null`·`pmonlog*`, 566 B)은 `pmonlog*` 넷의 참고 글이 NeXTMach·Darwin 어디에도 없습니다(NeXTMach `next/kernel_pmon.c` 는 `kpmon_null` 만).
- 행 266 `next/clock.c`: [0x40910d6, 0x4091e18), 3394 B, 정확 경계. 원본 22 함수 가운데 21 개가 NeXTMach `next/clock.c`(709 행)의 정의 순서와 같습니다(`rtc_set_clr` 65 … `rtc_real_blkread` 652). `rtc_tick`(0x40912be, 74 B)은 NeXTMach 에 없는 새 함수입니다. NeXTMach 의 `inittodr`(183)는 원본에서 0x400a42a(공통부 쪽)에 따로 있고, `resettodr`(242)는 원본 기호표에 없습니다. include 사슬(`machine/` → `next/` 대응, 85 머리)은 `nextdev/dma.h` 에 닿지 않습니다.
- 자료: `_new_clock_chip`(`__common`, NeXTMach 50 행 `int new_clock_chip;`), `_dayyr`(`__data` 0x40b2892, 247 행), 정적 `dmsize`·`ly_dmsize`(266·268 행).

머리(스테이징 `-I` 순서로 python 확인):
- 풀림: `sys/param.h`, `sys/time.h`, `sys/kernel.h`, `sys/errno.h`, `vm/vm_kern.h`, `next/cpu.h`(07 nextmach 사본, D109), `mon/global.h`(스테이징 판, NeXTMach 와 글이 다름), `machine/spl.h`, `kern/xpr.h`.
- 안 풀림: `next/clock.h`(NeXTMach 123 행, `next/eventc.h` 를 들임), `next/scr.h`(`scr1`·`scr2`·`brightness` 임시 정의), `next/eventc.h`(스테이징에는 m68k 덮어쓰기 `machdep/m68k/eventc.h`, §473 의 D091 수정 포함), `nextdev/video.h`, `mon/nvram.h`.

방법(진단; 명세 `08_build/artifacts/m4p532/spec.json`, run `m4p532-p1`, 바탕 `m0p531-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` `m68k-266`):
- 변형 N: NeXTMach `next/clock.c` 그대로. `inc`: NeXTMach 사본 `next/clock.h`·`next/scr.h`·`nextdev/video.h`·`mon/nvram.h`, 그리고 진단 별칭 `next/eventc.h`(`#import <machdep/m68k/eventc.h>`). 컴파일 오류가 가리키는 머리만 차례로 더하고(같은 run 안에서는 변형을 늘리지 않음) 기록합니다.
- 측정: `compare`(`diag_gate`, 옵션, `full_span`, L1(`__data`·`__cstring` 포함), 미정의), `m68k_funcbytes.py 40910d6 4091e18`, 객체 기호표(지역 포함)를 원본 기호표와 python 으로 대조(머리 오염 COMMON 은 이름을 적어 따로 셈), 컴파일 `.err` 전체 보존.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음): 함수별 같음 표와 자료 결과를 적습니다. 같지 않은 함수는 원본 바이트와 대조해 다음 계획(바이트가 요구하는 바뀜을 넣은 변형 D)의 근거로 씁니다.
관문: 명령 종료 상태 기록, i386 머리 0, 옵션 = M5 줄, 경고 기록(변형별).

### 532.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `rtc_intr`(NeXTMach `clock.c:86`)의 `mg->mg_intrstat` 은 스테이징 `mon/global.h`(plan 437 부분 구조체)에 없고, `inc` 는 기존 `-I` 뒤라 덮어쓸 수 없음 → N 은 컴파일 실패 | `clock.c:82–86`, 스테이징 `mon/global.h:19–24`, `m4_m68k_probe.py:207–209`, PROVENANCE 1071 행 읽음 | ✅ 그리고 원본 0x40911da 는 `mon_global` 대신 `_intrstat`(0x40b56d4, `__common` 4 B)을 읽음(이번 세션 확인). 변형을 N0(그대로; 실패 기록)과 N1(N0 + `rtc_intr` 의 이 한 곳만 `*intrstat`, 파일 안 `extern volatile int *intrstat;`)로 나눔 |
| NeXTMach 전체 `mon/global.h` 를 쓰면 `mon/*`·`next/machparam.h` 등 긴 사슬이 따라옴 | NeXTMach `mon/global.h:33–45` 읽음 | ✅ 쓰지 않음(N1 은 스테이징 부분 구조체로 충분) |
| `next/clock.h:34–36` 이 `timer_high`·`timer_low`·`timer_csr` 를 임시 정의함 | 그 줄 읽음 | ✅ 오염 후보로 기록(원본에 있는지와 이 객체 소유인지는 따로 적음) |
| `sec_to_tm` 은 정적 `dmsize`(0x40b28aa)·`ly_dmsize`(0x40b28c2)를 참조하고, 도구는 이를 `_dayyr+24`·`+48` 로 풀어 거짓 차이를 냄; 0x4091412 의 `_dayyr-2` 참조도 따로 볼 것 | 원본 목록 182525·182641·182644 행, 기호표(`_dayyr` 다음 기호까지 72 B) | ✅ 진단 대응 `40b28aa=_dmsize`·`40b28c2=_ly_dmsize` 를 주고, `_dayyr-2` 참조는 객체 재배치를 손으로 대조 |
| 자료 측정을 명시: `dayyr`·`dmsize`·`ly_dmsize` 의 섹션·크기·초기 바이트, COMMON 크기 | `m4_m68k_probe.py:345–346` 읽음 | ✅ python 으로 객체 `__data` 72 B 와 원본 0x40b2892 의 72 B 를 바이트 대조 |
| `_delay` 묶음 문장은 가설로 낮출 것 | §416 표 252–253 행, 인벤토리 72–73 행 | ✅ 문장을 고침 |

### 532.2 중간 결과와 도구 보완 계획(2026-10-26, 도구 코딩 전)

- run `m4p532-p1`: N0 은 예상대로 `clock_N0.c:86: structure has no member named 'mg_intrstat'` 로 실패(종료 1), N1 은 컴파일·`-M` 모두 종료 0·경고 0 입니다(`diag_gate.commands_ok` 는 N0 때문에 거짓). 기록 `09_validation/reconstruction/m4-m68k-probe-p532-20261026.json`.
- N1: `__text` 3540/3394 B. `_rtc_tick` 이 없고 `_inittodr`·`_resettodr` 가 더 있으며, 원본에 없는 미정의 `_us_timer_init` 이 있습니다. `__data` 72 B(`dayyr`, 정적 `dmsize`·`ly_dmsize`)는 원본 0x40b2892 의 72 B 와 바이트가 같습니다(python). COMMON 17 개 가운데 원본에 없는 것은 `_disk_chip`·`_scr1`(머리 오염)이고, `_timer_high`·`_timer_low`·`_timer_csr`·`_new_clock_chip` 은 원본에 있습니다.
- `m68k_funcbytes.py` 가 `scattered target 0xeaa outside the section of r_value 0xeac` 로 멈췄습니다. 객체 0x3d0 의 산재 재배치(`r_value` 0xeac = `_dayyr`)가 저장값 0xeaa(`_dayyr-2`, 앞 섹션 `__cstring` 끝)를 가리킵니다. 원본 0x4091412 `lea 0x40b2890` 과 같은 참조입니다(§532.1). 지금 도구는 저장값이 `r_value` 의 섹션 밖이면 안전하게 멈추도록 되어 있습니다(§521–522).

도구 보완 계획(`10_tools/reconstruction/m68k_funcbytes.py`):
1. 산재 재배치에서 저장값이 `r_value` 의 섹션 밖이면, `r_value` 와 정확히 같은 값의 기호(비 STABS)가 객체에 있을 때만 대상을 (그 기호 이름, 저장값 − `r_value`)로 풉니다. 그런 기호가 없으면 지금처럼 멈춥니다. 섹션 안이면 지금과 같습니다.
2. 같음 판정에 주소 비교를 더합니다: 객체 쪽 대상이 (이름, 오프셋)이고 그 이름의 원본 주소를 알 수 있으면(원본 기호표의 외부 기호, `ADDR=NAME` 대응, 범위 안 원본 함수), 원본 주소 + 오프셋이 원본 쪽 필드가 가리키는 주소와 같을 때도 같음으로 봅니다. 이름이 다르게 풀린 경우(예: 원본 `_crctab+1022` 대 객체 `_dayyr-2`)를 주소로 맞춥니다. `cstring` 대상은 지금처럼 내용으로만 비교합니다.
3. 회귀: 대응 없이 돌린 기존 기록 7 개(`p521-H`·`X`, `p522-M`, `p523-F`·`L`·`a1`, `p524-B2`)와 §525–531 의 함수별 기록, 받아들인 객체 일곱의 결과가 같아야 합니다. 거부 시험: 산재 재배치의 `r_value` 에 기호가 없으면 멈춤, 주소가 1 어긋나면 다름(임시 사본 객체의 저장값을 바꿔 시험).
4. 그 뒤 N1 을 대응 `40b28aa=_dmsize 40b28c2=_ly_dmsize` 로 다시 비교해 함수별 표를 적습니다(07 변경 없음).

#### 532.2.1 교차검토(codex `gpt-6.1-sol`) 판정과 도구 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 앵커를 "비 STABS 기호" 로만 고르면 COMMON(값 = 크기)·미정의(값 0)도 걸림 → `r_value` 의 섹션에 정의된 이름 있는 `SECT` 기호만 | `macho_obj.py:88` 의 `kind` 구분 읽음 | ✅ |
| 섹션 안 산재 재배치를 지금처럼 저장값으로만 풀면 앵커를 버려 거짓 같음이 생길 수 있음(SDK `mach-o/reloc.h` 의 산재 재배치 목적: 기호 값 + 오프셋) | SDK `reloc.h:66–78` 읽음; 기존 기록 객체 전체의 산재 재배치를 python 으로 셈: 2 개(`__data`→`__data`, 앵커 있음, 절대) | ✅ 모든 산재 재배치를 (앵커, 유효 대상 − `r_value`)로 풂 |
| PC 상대면 유효 대상 = 필드 주소 + 부호 있는 변위 | 도구 172 행의 계산 | ✅ 그 계산을 그대로 씀 |
| 주소 같음은 원본 주소가 하나로 정해질 때만; 같은 이름의 지역·외부 결합이 다르면 멈춤; `ADDR=NAME` 대응은 조건부 | 도구 구조 읽음 | ✅ 산재 경로에만 주소 비교를 쓰고, 다른 경로는 지금 그대로 |
| 시험을 늘릴 것(같은 섹션 넘김, PC 상대, COMMON·미정의 앵커 거부, 별칭, 결합 충돌, 정적 대응) | — | ✅ 아래 4 |

도구 계획(고친 것):
1. 산재 재배치: 유효 대상 t(절대 = 저장값, PC 상대 = 필드 주소 + 변위). 앵커 = `r_value` 의 섹션에 정의된, 값이 `r_value` 와 같은 이름 있는 `SECT` 기호(별칭이면 모두). 없으면 멈춤. 객체 쪽 대상 = (앵커 이름들, t − `r_value`).
2. 앵커의 원본 주소: 범위 안 원본 함수(이름 대응), `ADDR=NAME` 대응, 원본 기호표의 이름(같은 이름이 여러 주소면 멈춤). 별칭마다 구한 원본 주소가 서로 다르면 멈춤. 하나도 없으면 멈춤.
3. 같음 = 원본 주소 + (t − `r_value`) 가 원본 필드가 가리키는 주소와 같음. 기록에는 앵커 이름·오프셋·원본 주소를 남김. 산재가 아닌 재배치의 처리는 바꾸지 않음.
4. 시험: 기존 기록 36 개 재현(함수 표·같음 수), 받아들인 객체 일곱; 임시 사본으로 저장값 1 바꿈 → 다름, `r_value` 를 기호 없는 값으로 → 멈춤; 앵커 결합 함수(원본 주소 정하기)를 따로 불러 COMMON·미정의 앵커 거부, 별칭 일치·충돌, 대응 정적, PC 상대 계산을 시험.

### 532.3 결과(2026-10-26)

- 도구 `m68k_funcbytes.py`(230 → 232 행; 산재 재배치를 앵커 + 오프셋으로 풀고 원본 주소로 비교): 기존 함수별 기록 36 개를 대응 그대로 다시 돌려 함수 행까지 같고, 받아들인 객체 일곱도 모두 같음입니다(`nbic` 은 제가 처음에 범위를 잘못 적어 1/1 로 나왔고, 상태표 범위로 다시 돌려 2/2). 거부 시험(저장소 밖 임시 사본): 저장값을 1 바꾸면 `_tm_to_sec` 가 다름(`['_dayyr', -1]` 대 원본), `r_value` 를 기호 없는 값(0xead, 4)으로 바꾸면 멈춤, `40b2894=_dayyr` 처럼 대응이 원본 기호표와 충돌하면 멈춤. 별칭 앵커와 PC 상대 산재 재배치는 실제 사례가 없어 시험하지 못했습니다.
- N1(대응 `40b28aa=_dmsize`·`40b28c2=_ly_dmsize`; `m4-m68k-funcbytes-p532-N1-20261026.json`): 22 함수 가운데 18 개가 같습니다(`_dayyr-2` 참조 포함). 다른 것:
  - `rtc_tick`(0x40912be, 74 B): NeXTMach 에 없음. 원본: `addr = (rtc_read(RTC_STATUS) & RTC_NEW_CLOCK) ? RTC_CNTR3 : RTC_SEC`(0x23/0x20), `val = rtc_read(addr)`, `rtc_read(addr) == val` 인 동안 `delay(1000)`, 0 을 돌려줌.
  - `rtc_power_down` 78/50 B: 원본은 `spldma()` 뒤 `new_clock_chip` 이면 `rtc_tick()` 과 `delay(850000)`(0xcf850)을 부르고, 나머지는 NeXTMach 와 같은 흐름입니다.
  - `startrtclock` 132/138 B: 원본 끝에 `us_timer_init()` 호출이 없습니다(6 B 차이).
  - `resynctime` 8/26 B: 원본은 빈 몸통입니다.
  - 객체에만 있음: `inittodr`(원본은 0x400a42a 의 다른 객체), `resettodr`(원본 기호표에 없음).
- 판정: 미리 정한 대로 기록하고, 위 바뀜을 넣은 변형은 §533 에서 따로 시험합니다.

## 533. M4-39 세부 계획 — `clock.c` 변형 D 진단(07 변경 없음; 코딩 전, 2026-10-26)

방법(명세 `08_build/artifacts/m4p533/spec.json`, run `m4p533-p1`, 바탕·`inc`·줄 틀·`m4_id` 는 §532 N1 과 같음):
- 변형 D = N1 에 원본 바이트가 요구하는 다음만 더함:
  - `rtc_alarm` 과 `rtc_power_down` 사이에 `rtc_tick()` 정의: `int addr, val; addr = (rtc_read (RTC_STATUS) & RTC_NEW_CLOCK)? RTC_CNTR3 : RTC_SEC; val = rtc_read (addr); while (rtc_read (addr) == val) delay (1000); return (0);`
  - `rtc_power_down`: `s = spldma();` 뒤에 `if (new_clock_chip) { rtc_tick (); delay (850000); }`
  - `startrtclock`: `us_timer_init();` 줄을 뺌.
  - `resynctime`: 몸통을 비움(`struct timeval rtc_get();` 과 `time = rtc_get();` 를 뺌).
  - `inittodr`·`resettodr` 정의와 그 앞 주석을 뺌.
- 측정: §532 와 같음(`compare`, `m68k_funcbytes.py` 대응 둘, `__data` 72 B 바이트 대조, 정의·COMMON 을 원본 기호표와 대조, 미정의).

판정(미리 정함; 07 은 바꾸지 않음):
- D 가 `__text` 3394 B, 22/22 함수 같음, `__data` 같음, 원본에 없는 미정의 0 이고, 원본에 없는 정의가 머리 오염(`_disk_chip`·`_scr1`)뿐이면, 07 꼴(머리를 NeXTMach 사본으로 둘지 파일 안 매크로로 둘지, `intrstat` 선언, `rtc_tick` 의 꼴과 이름 표기, 뺀 줄의 처리)을 사용자께 여쭙고 구현 계획을 씁니다.
- 아니면 함수별 차이를 적고 멈춥니다(이번 run 에 변형을 더하지 않음).
관문: 명령 종료 0·경고 0(변형별), i386 머리 0, 옵션 = M5 줄.

### 533.1 교차검토 판정과 계획 수정

`gpt-6.1-sol` 은 용량 초과로 실패해(같은 질문, 237 초 뒤 종료 1), 메모리에 적힌 대체 모델 `gpt-6-luna` 로 다시 받았습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §532.3 의 네 함수 사실(74·78·132·8 B, 0x23/0x20, `0x3e8`, `0xcf850`, `us_timer_init` 없음, 빈 `resynctime`)은 맞음 | 이번 세션에 원본 목록 0x40912be–0x40913e2 를 읽음 | ✅ |
| `rtc_tick` 의 삼항 꼴이 같은 바이트를 낸다는 보장은 없음(안 되면 `if/else` 꼴) | 시험 전 | ⏭️ D 결과를 보고 다음 계획에서 |
| `inittodr`·`resettodr` 를 빼도 다른 함수는 바뀌지 않음(`resettodr` 호출은 `inittodr` 안), `inittodr` 는 원본 0x400a42a 의 다른 객체 | N1 182–222 행, `ufs_vfsops.c` 의 호출 읽음 | ✅ |
| `__cstring` 의 기대 결과가 없음: 뺀 함수의 문자열이 남지 않음을 확인할 것 | N1 의 `inittodr` 문자열, 원본 `strings.tsv` | ✅ D 의 `__cstring` 문자열이 모두 원본 `__cstring` 에 있고, `inittodr` 의 문자열("preposterous", "clock not set properly", "CHECK AND RESET")이 없음을 python 으로 확인 |
| COMMON 크기의 비교 근거를 밝힐 것(`symbols.tsv` 에는 크기가 없음) | 기호표 열 읽음 | ✅ COMMON 은 이름·종류와, 크기 ≤ 원본에서 다음 기호까지의 거리(§525 와 같은 방법)로 대조하고 그 표를 기록 |

### 533.2 결과(2026-10-26)

- run `m4p533-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p533-20261026.json`): 두 명령 종료 0·경고 0, i386 머리 0. D 는 `__text` 3394 B, `full_span`, 원본에 없는 미정의 0, 이름 빠짐·더함 0.
- 함수별(`m4-m68k-funcbytes-p533-D-20261026.json`): 22 가운데 21 개가 같습니다. `rtc_tick` 은 길이가 같고 2 B(함수 안 0x2e–0x2f) 다릅니다. 실기 `otool -tv`(`08_build/artifacts/m4p533/clock_D.otool.txt`)로 보면 D 는 `cmpl d0,d3`, 원본(0x40912ec)은 `cmpl d3,d0` 입니다. 나머지 명령은 같습니다.
- 자료(python): `__data` 72 B 원본과 같음; `__cstring` 문자열 2 개 모두 원본 `__cstring` 에 있고 `inittodr` 의 문자열 없음; COMMON 17 개 가운데 15 개는 원본에 있고 크기 ≤ 원본에서 다음 기호까지 거리, 원본에 없는 것은 `_disk_chip`·`_scr1`(머리 오염); 외부 정의 함수는 모두 원본에 있음.
- 판정: 미리 정한 둘째 갈래(함수 하나가 다름)입니다. 기록하고 멈춥니다. `rtc_tick` 의 비교 꼴은 §534 에서 따로 시험합니다.

## 534. M4-40 세부 계획 — `rtc_tick` 비교 꼴 진단(07 변경 없음; 코딩 전, 2026-10-26)

방법(명세 `08_build/artifacts/m4p534/spec.json`, run `m4p534-p1`, 바탕·`inc`·줄 틀·`m4_id` 는 §533 과 같음). D 에서 `rtc_tick` 만 바꾼 꼴:
- E1: `while (val == rtc_read (addr))`(비교 피연산자 순서만 바꿈).
- E2: `for (;;) { if (rtc_read (addr) != val) break; delay (1000); }`.
- E3: E1 에 더해 주소 고르기를 `if (…) addr = RTC_CNTR3; else addr = RTC_SEC;` 로.
- 측정: §533 과 같음(함수별, 자료·문자열·COMMON). 꼴마다 `rtc_tick` 밖의 21 함수가 D 와 같음을 함께 확인합니다.

판정(미리 정함; 07 은 바꾸지 않음): `__text` 3394 B, 22/22 같음, 자료 조건(§533.1) 충족인 꼴이 있으면, 같은 객체를 내는 꼴들과 07 꼴(머리를 NeXTMach 사본으로 둘지 파일 안 매크로로 둘지, `intrstat` 선언, 뺀 줄의 처리)을 사용자께 여쭙니다. 없으면 차이를 적고 멈춥니다.
관문: 명령 종료 0·경고 0, i386 머리 0, 옵션 = M5 줄.

### 534.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 차이는 `cmpl` 피연산자 순서뿐 | §533.2 의 실기 목록과 원본 목록 대조(이번 세션) | ✅ |
| `register int addr, val;`, 가드 있는 do-while, E2 의 `val != rtc_read (addr)` 도 시험할 것 | 계획에 없었음 | ✅ E4·E5·E6 을 더함 |
| 바이트가 같아도 원문 철자를 증명하지는 않음(비교 순서는 동작이 같음) | — | ✅ 판정 문장에 그대로 둠(같은 바이트를 내는 꼴 가운데 사용자가 고름) |

더한 꼴: E4 = D 에 `register int addr, val;`; E5 = `do { if (rtc_read (addr) != val) break; delay (1000); } while (1);`; E6 = E2 의 조건을 `val != rtc_read (addr)` 로.

### 534.2 결과(2026-10-26)

- run `m4p534-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p534-20261026.json`): 12 명령 종료 0·경고 0, i386 머리 0, 옵션 = M5 줄.
- E1(`while (val == rtc_read (addr))`), E3(E1 + `if/else` 주소), E6(`for (;;) { if (val != rtc_read (addr)) break; delay (1000); }`): `__text` 3394 B, L1 `OBJECT_MATCH`(자료 포함), `candidate`, 22/22 함수 같음, 서로 canon·`obj_sig`(STABS 수 978·981·983 제외) 같음. E1 의 `__data` 72 B 원본과 같음.
- E2·E4·E5: `rtc_tick` 이 2 B 다름(비교 피연산자 순서). 곧 원본은 `val` 을 먼저 쓰는 비교입니다.
- 07 꼴에 걸리는 머리(python, 원문이 쓰는 이름): `next/cpu.h` 에서 `I_BIT`·`I_POWER`, `next/scr.h` 에서 `SCR2_RTCE`·`SCR2_RTCLK`·`SCR2_RTDATA`·`scr2`(이 머리의 `scr1` 은 원본에 없는 COMMON), `next/clock.h` 에서 RTC 매크로·`struct rtc_clk_map(_new)`(이 머리의 `timer_high`·`timer_low`·`timer_csr` 임시 정의는 원본에 있는 COMMON), `mon/nvram.h` 에서 `struct nvram_info`, `nextdev/video.h` 에서 `struct alarm`. 스테이징에는 이 가운데 어느 것도 없고, SDK 에는 `bsd/dev/m68k/video.h`(1997 판, `struct alarm` 같음)만 있습니다.
- 판정: 미리 정한 첫 갈래입니다. 07 꼴을 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): 머리는 "video.h 만 SDK 판"(`next/clock.h`·`mon/nvram.h` 는 NeXTMach 사본, `struct alarm` 은 SDK `bsd/dev/m68k/video.h`, `next/cpu.h`·`next/scr.h` 이름은 파일 안), `rtc_tick` 은 while + 삼항(E1), 원본에 없는 줄은 지우고 머리 주석에 적음.

## 535. M4-41 D116 구현 계획 — 07 `src/machdep/m68k/clock.c`, 머리 셋, SDK `video.h` 스테이징(코딩 전, 2026-10-26)

1. 07 머리:
   - `07_kernel/nextmach/next/clock.h`: NeXTMach 사본에서 `#import <next/eventc.h>` 만 `#import <machdep/m68k/eventc.h>`(M5 의 `machdep/m68k/xpr.h:44` 와 같은 경로, 표시 plan 535). 스테이징 `src/bsd/next/clock.h`. 임시 정의 `timer_high`·`timer_low`·`timer_csr` 은 원본에 있는 COMMON 이라 그대로 둡니다.
   - `07_kernel/nextmach/mon/nvram.h`: NeXTMach 그대로. 스테이징 `src/mon/nvram.h`.
   - `07_kernel/nextdev/bsd/dev/m68k/video.h`: 실기 `/NextDeveloper/Headers/bsd/dev/m68k/video.h` 그대로(SHA-256 `b5213d36…` = `s4c-nextdev-headers-20261002.json` 의 값 = 로컬 사본). 스테이징 `src/bsd/dev/m68k/video.h`.
2. `stage_m68k.py`: `M4HEADERS` 항목에 선택 셋째 값(원본 뿌리, `07_kernel/nextmach`(기본) 또는 `07_kernel/nextdev`)을 받게 하고, `M4HEADERS[535]` = 531 목록 + 위 셋, `M4FILES[535]` = 531 목록 + `clock.c`, `EXCEPTS[535]` = 531. 기존 2 값 항목의 처리는 그대로여야 합니다.
3. 꼴 L(`08_build/artifacts/m4p535/src/clock_L.c`) = §534 E1 에서:
   - include: `<next/cpu.h>` → `<m68k/cpu.h>`(D110), `<next/scr.h>` 줄을 뺌, `<next/eventc.h>` → `<machdep/m68k/eventc.h>`, `<nextdev/video.h>` → `<dev/m68k/video.h>`. `<next/clock.h>`·`<mon/nvram.h>`·`<mon/global.h>` 는 그대로.
   - 파일 안(표시 plan 535, 값은 NeXTMach `next/cpu.h`·`next/scr.h`): `I`·`I_BIT`·`I_POWER`, `SCR2_RTDATA`·`SCR2_RTCLK`·`SCR2_RTCE`, `extern volatile int *scr2;`; `extern volatile int *intrstat;` 은 E1 의 `rtc_intr` 안 선언 그대로.
   - 먼저 run `m4p535-p1`(바탕 `m0p531-a1-stage`, 머리 셋은 `inc`)에서 L 이 22/22·L1 `OBJECT_MATCH`·`__data` 72 B 같음·`__cstring` 조건(§533.1)·원본에 없는 정의 0(COMMON 은 이름·크기 ≤ 다음 기호까지)인지 봅니다. 어긋나면 기록하고 멈춥니다. L 의 COMMON 목록을 기대값으로 고정합니다.
4. 07 `src/machdep/m68k/clock.c` = L + 설명 주석(NeXTMach 바탕, 원본 주소, 뺀 것: `inittodr`(원본 0x400a42a 의 다른 객체)·`resettodr`(원본에 없음)·`startrtclock` 의 `us_timer_init()`·`resynctime` 몸통·`rtc_intr` 의 `mon_global` 두 줄·`next/scr.h` import; 바꾼 것: `rtc_intr` 의 `*intrstat`, `rtc_power_down` 의 `rtc_tick`/`delay(850000)` 덩이, 새 `rtc_tick`; D024·D103·D104·D116) + 표시. 주석을 뺀 토큰 = L.
5. 회귀: `--plan 531` 재생성 = `m0p531-a1-stage`; `--plan 535 stage m0p535-a1-stage` 와의 차이는 네 파일(`clock.c` 와 머리 셋). 새 스테이징 경로 셋을 들이는 줄은 `clock.c` 말고 0 건(grep). M5 205 줄을 `m0p531-a1-stage`(run `m3p535-b531`)와 `m0p535-a1-stage`(run `m3p535-cc1`)에서 컴파일해 205 객체가 바이트 같고 stderr 가 같음(§517 절차).
6. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시 `m4_x86_inputs.py s6ll`, `--plan 535 x86gate`). `07_kernel/nextdev` 에 파일을 더하므로 x86 스테이징 매니페스트가 그대로인지가 이 관문입니다.
7. 확인 run `m4p535-p2`(F = `@machdep/m68k/clock.c`, L, `m4_id` `m68k-266`): F·L `candidate`, canon·`obj_sig` 같음, 22/22(대응 `40b28aa=_dmsize`·`40b28c2=_ly_dmsize`); run `m4p535-e1` `-E` 토큰 F = L.
8. 최종 run `m4p535-a1`(REF = L): `gate.ok`; python 확인(정의·COMMON = 기대값, 원본에 없는 정의·미정의 0, `__data` 72 B, `__cstring`, 입력 사슬(소스와 머리 셋), L1 0x40910d6 사유 없음, 22/22, `-M` 에 `next/cpu.h`·`next/scr.h`·i386 없음).
9. 기록: 상태표, PROVENANCE(`clock.c` nextmach+authored; `next/clock.h` nextmach 고친 사본; `mon/nvram.h` nextmach 그대로; `video.h` nextdev-os42, license TBD D017), MODIFICATIONS, DECISIONS D116, 근거 `m68k-clock.md`, diff `m68k-clock.diff`.
관문: 명령 종료 0·경고 0·i386 머리 0, 회귀 같음(M5 205 객체 포함), x86 입력 불변.

### 535.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| M5 205 줄은 경고가 있는 stderr 52 개가 원래 있으므로, 관문은 "clock 시험의 경고 0" 과 "M5 의 진단 출력 불변" 으로 나눌 것 | §517.2 의 6 단계 기록(52 개) 읽음 | ✅ |
| 상태표 회귀(두 번 실행 같음, 앞 행 보존)를 9 에 명시할 것; 머리 출처 확인은 매니페스트의 출처를 그대로 해시하므로 뿌리별 수정 불필요 | §529 의 7, `m4_m68k_status.py` 의 머리 확인 줄 읽음 | ✅ |
| M7 의무(COMMON 합침, `scr2`·`intrstat`·`timer_*` 의 정의 객체)를 기록할 것 | §526 의 9 | ✅ |
| L 의 형(`scr2`·`intrstat`), `I_POWER` = 0x23b·`I_BIT` = 4, SDK `video.h` 충돌 없음, 스테이징 경로 셋이 비어 있음, x86 매니페스트는 include 닫힘을 따르므로 그대로일 것 | 계획대로 컴파일·x86gate 로 확인 | ⏭️ 각 단계 결과로 판정 |

### 535.2 결과(2026-10-26)

- 1: 07 머리 셋 — `nextmach/next/clock.h`(SHA-256 `9936dab5…`, import 한 줄만 바뀜), `nextmach/mon/nvram.h`(NeXTMach 와 `cmp` 같음), `nextdev/bsd/dev/m68k/video.h`(`b5213d36…` = 실기 목록 = 로컬 사본).
- 3: run `m4p535-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p535-p1-20261026.json`): L 은 종료 0·경고 0, 22/22, L1 `OBJECT_MATCH`, §534 E1 과 `__text`·`__cstring`·`__data` 바이트·재배치가 같음, COMMON 은 `_new_clock_chip`·`_timer_csr`·`_timer_high`·`_timer_low`(모두 원본에 있고 크기 맞음), `__data` 72 B·`__cstring` 2 개 조건 충족. 이 COMMON 넷을 기대값으로 고정했습니다.
- 4: 07 `src/machdep/m68k/clock.c`(685 행, SHA-256 `b0c37ea9…`): 주석을 뺀 토큰 3643 개와 지시문 줄이 L 과 같음.
- 2·5: `stage_m68k.py` 636 → 645 행(`M4HEADERS` 셋째 값 `07_kernel/nextdev`). `--plan 531` 재생성 = `m0p531-a1-stage`(모든 키), `--plan 535 stage m0p535-a1-stage`(922 파일)와의 차이는 네 파일, 새 경로를 들이는 줄은 `clock.c` 뿐(grep). M5 205 줄: run `m3p535-b531`·`m3p535-cc1` 각 205 명령 종료 0, 205 객체 모두 바이트 같음, 비어 있지 않은 stderr 52 개가 서로 같음; `compare`(`m3-m68k-p535-compare-20261026.json`, `-b531-`)의 `differ_unexpected`·`lost` 빔, 요약 항목 모두 같음.
- 6: x86 입력 불변(`m4-x86-inputs-p535-20261026.json` ok; `--plan 535 x86gate` 일곱 묶음 `same`, v183 경로 0) — `07_kernel/nextdev` 에 파일을 더해도 x86 매니페스트는 그대로입니다.
- 7: run `m4p535-p2`(`m4-m68k-probe-p535-20261026.json`): F·L `candidate`, canon·`obj_sig` 같음, 22/22. run `m4p535-e1`: `-E` 토큰 9552 개 같음.
- 8: run `m4p535-a1`(REF = p2 L `d11906a4…`; `m4-m68k-p535-final-20261026.json`): `gate` 모두 참, 객체 SHA-256 `5dfcc1fe…`. python 확인(`m4-m68k-p535-checks-20261026.json`, `ok` 참). 제 오류: 첫 확인식은 외부 정의를 22 로 셌으나, 함수 22 개에 자료 `_dayyr` 가 더해진 23 개가 맞습니다. 기대 집합을 이름으로(원본 22 함수 + `_dayyr`) 고쳐 다시 계산했고 그 사실을 기록 안 `note` 에 적었습니다.
- 9: 상태표 18 객체(OBJECT_MATCH 17, CODE+BSS_INFERRED 1), 행 38/188, 17242 B(7.99%), 앞 17 행 그대로, 두 번 돌린 출력 같음(`m4-m68k-status-p535-20261026.json`; `m4_m68k_status.py` 142 → 143 행). PROVENANCE 1130 → 1134 행(경로 중복 0), MODIFICATIONS 676 → 680 행, DECISIONS D116(119 → 120 행), 근거 `06_reconstruction/evidence/m68k-clock.md`(처음 "18 함수 그대로" 라 적은 것을 python 으로 세어 17 로 고침), diff `m68k-clock.diff`(180 행).

## 536. M4-42 세부 계획 — `next/nextdbgasm.s` 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션, python): 남은 후보에 대해 `machine/` → `next/` 대응으로 include 사슬을 따라 `nextdev/dma.h` 도달을 다시 셌습니다. `dma.h` 와 무관하고 경계가 정확한 가장 작은 단위가 행 `m68k-307` `next/nextdbgasm.s`(136 B, 진입점 4/4 대응, 어셈블리)입니다. 어셈블리 경로는 §511–514(D108·D109)에서 세웠습니다.

확인한 사실(이번 세션; 원본 목록, 기호표, NeXTMach `next/nextdbgasm.s` 76 줄):
- 원본 [0x4096736, 0x40967be): `__dbg_trap` 70 B, `__dbg_kresume` 30 B, `_dbg_setjmp` 16 B, `_dbg_longjmp` 20 B. NeXTMach 의 `__nextdbginit`(와 그 `.lcomm dbgstack,DBG_STACK`)은 원본 기호표에 없습니다.
- `__dbg_trap` 은 NeXTMach 와 두 곳이 다릅니다: 처음에 `movel sp,0x40b5640`, 레지스터를 되살린 뒤 `movel 0x40b5640,sp`. 나머지(`clrw sp@-` … `jsr _dbg_trap`, `movel d0,dbgrts`(0x40b563c), `addql #4,sp`, … `movel dbgrts,sp@-; rts`)는 NeXTMach 와 같은 흐름입니다(`addal #0x46` = (16*4)+2+4, `sp@(0x44)` = (15*4)+8).
- `__dbg_kresume`·`_dbg_setjmp`·`_dbg_longjmp` 는 NeXTMach 와 같은 명령입니다(`_client_running` 0x40c9778, `_client_pcb` 0x40c96d4 의 +0·+4).
- 0x40b563c·0x40b5640 은 `__bss`(0x40b317c–0x40b5648) 끝의 이름 없는 정적 변수이고, 원본에서 이 둘을 쓰는 곳은 `__dbg_trap` 뿐입니다. 0x40b5638 이하는 `nextdbg.c` 쪽 정적 변수, 0x40b5644 는 `setconf`·`initrootnet` 쪽입니다. [0x40b523c, 0x40b563c) 안에도 다른 객체(`zs`·`en`·`clock` 등)의 참조가 있어 1024 B `dbgstack` 이 들어갈 자리가 없습니다(python). 따라서 이 객체의 `__bss` 는 8 B(`dbgrts`, 새 변수 순)로 봅니다.

방법(진단; 명세 `08_build/artifacts/m4p536/spec.json`, run `m4p536-p1`, 바탕 `m0p535-a1-stage`, 줄 틀 `machdep/i386/start.s`, `defs` `-DASSEMBLER`(D108), `m4_id` `m68k-307`):
- N: NeXTMach `next/nextdbgasm.s` 그대로.
- D1: N 에서 `DBG_STACK`·`.lcomm dbgstack`·`__nextdbginit` 덩이를 빼고, `.lcomm dbgrts,4` 뒤에 `.lcomm dbgsp,4` 를 두고, `__dbg_trap` 첫 명령으로 `movl sp,dbgsp`, `moveml sp@+,#0xffff` 뒤에 `movl dbgsp,sp`(이름 `dbgsp` 는 진단용).
- D2: D1 에서 `.lcomm dbgsp,4` 를 `.lcomm dbgrts,4` 앞에 둠(`__bss` 안 순서 확인).
- 측정: `compare`(`diag_gate`, `full_span`, L1, 미정의), `m68k_funcbytes.py 4096736 40967be 40b563c=dbgrts 40b5640=dbgsp`, 객체 `__bss` 크기와 지역 기호 값, D1·D2 에 `m5_m68k_zerofill.py objs`(후보가 [0x40b563c, 0x40b5644) 이고 받아들인 배치와 겹치지 않는지).

판정(미리 정함; 07 은 바꾸지 않음): D1·D2 가운데 `__text` 136 B, 4/4 같음, L1 사유가 `__DATA,__bss: unverified` 하나, `__bss` 8 B 에서 `dbgrts` 가 0, 새 변수가 4 이고 zerofill 이 `reference-inferred` 이며 겹침이 없는 꼴이 있으면, 07 꼴(새 변수 이름, 뺀 줄의 처리, 파일 자리 D103)을 사용자께 여쭙고 구현 계획(별도 분류 `CODE+BSS_INFERRED`, D113)을 씁니다. 없으면 기록하고 멈춥니다.
관문: 명령 종료 상태 기록, i386 머리 0, 옵션 = M5 줄(어셈블리는 §512 의 `-DASSEMBLER` 더함).

### 536.1 교차검토(codex `gpt-6.1-sol`) 판정과 새 사실 — 실행 전 멈춤

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본에 `__m68k_dbginit`(0x4096700)이 있어 `_dbgstack` 을 읽고 0x400 을 더함 → "디버거 스택이 없다" 는 말은 틀림; 앞 구간이 차 있다는 것은 이 객체의 1024 B 지역 `.lcomm` 이 없다는 것만 뜻함 | 원본 목록 0x4096700–0x4096736 읽음; 기호표 `__m68k_dbginit` 0x4096700(외부), `_dbgstack` 0x40c8ef4(`__common`), `_m68k_dbginit` 0x4095460 | ✅ 그리고 더 중요한 사실: `__m68k_dbginit`(54 B)은 NeXTMach `__nextdbginit` 과 같은 흐름(`movel sp@+,a0`, `moveml` 저장, `sr`, `movew #0x2700,sr`, 스택 바꿈, 프레임 형 0, `jsr`)에 이름과 스택 꼴(포인터 `_dbgstack` + 0x400)만 바뀐 것이고, 돌아오지 않고 `__dbg_trap` 으로 떨어집니다. 바로 앞 `_inet_aton` 은 `rts` 로 끝나는 C 함수입니다. 따라서 1997 `nextdbgasm.s` 객체는 [0x4096700, 0x40967be) 190 B, 진입점 5 개일 가능성이 큽니다 |
| 0x40b5638 은 `_dbg_trap` 이 쓰고 `_SENDEXC` 가 읽음(행 305 묶음 밖) | 원본 목록 0x4095610·0x4096526 grep | ✅ 사실 줄을 고칠 것(소유 객체는 정하지 않음) |
| `objs` 의 겹침 검사는 §464 후보만 보므로 이후 받아들인 배치(§526 포함)와 python 으로 따로 대조; 변형마다 따로 부르고 출력 폴더를 나눌 것 | `m5_m68k_zerofill.py:123–157` 읽음(§526 에서도 같은 이유로 따로 대조함) | ✅ |
| "0 과 4" 는 `__bss` 시작에서의 거리로 볼 것; `diag_gate` 를 명시적으로 단언할 것 | `macho_obj` 의 주소 보존, `m4_m68k_probe.py:364` | ✅ |
| `movc`·`jra`·`moveml` 즉시 마스크·`.lcomm` 순서·`addql` 선택은 시험 결과로 볼 것 | — | ⏭️ |

판정: 진단 대상 구간이 바뀌어야 하므로 run 하기 전에 멈춥니다.
- 1997 객체를 [0x4096700, 0x40967be) 로 보면, 그 구간이 행 `m68k-306`(정확 경계가 아닌 행, [0x4096386 또는 0x40964f2, 0x4096736), 진입점 `_SENDEXC`·`_inet_aton`·`__m68k_dbginit`)을 쪼갭니다.
- §511 의 명시 구간(`span`)은 겹치는 행이 구간 안에 모두 들어와야 하므로(`m4_m68k_probe.py:162`) 이 구간을 받지 못하고, 상태표의 "덮은 행" 셈도 행 일부를 다룰 수 없습니다.
- 행 일부만 덮는 객체를 받으려면 probe·상태표 도구의 기준(행 셈)을 바꿔야 합니다. 이는 받아들임 기준의 변경이므로 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): "도구를 넓혀 진행".

## 537. M4-43 세부 계획 — 행 일부를 덮는 명시 구간(도구 확장)과 `nextdbgasm.s` 진단(07 변경 없음; 코딩 전, 2026-10-26)

1. 도구 확장:
   - `m4_m68k_probe.py` `span`: 명시 구간 사전에 선택 키 `partial`(행 id 목록)을 받습니다. 단언: 겹치는 §495 행 = `rows` ∪ `partial`(겹침 없음); `rows` 는 지금처럼 구간 안에 완전히 들어옴; `partial` 의 각 행은 정확 경계가 아닌 행(`exact` ≠ 1)이고 구간 밖으로 나가며(완전히 안이면 거부), 구간 경계 `lo` 또는 `hi` 가 그 행의 가능한 범위 `[start_lo, end_hi)` 안에 있음; `basis` 는 지금처럼 필수. 돌려주는 값 (lo, hi, rows) 는 그대로이고(`rows` 는 완전히 덮은 행만), `partial` 은 새 도우미로 읽습니다. 기록(`compare`)에는 `partial_rows` 를 더합니다.
   - `m4_m68k_status.py`: 열 `partial_rows` 를 더하고(다른 객체는 빈칸), 요약에 `partial_rows` 목록을 둡니다. "덮은 행"·바이트 셈은 지금처럼 완전히 덮은 행만 셉니다. 객체 구간끼리 겹치지 않음 검사는 그대로입니다. 한 부분 행을 두 객체가 나눠 덮는 것은 허용합니다(구간은 겹치지 않아야 함).
   - 회귀: §512 최종(`m4p512-a1`, 명시 구간), §523·§535 최종을 고친 도구로 다시 `compare` 해 기록 필드가 `tool_sha256`·새 키 말고 같고 L1 파일이 바이트 같음; 상태표는 기존 기록으로 새 열 말고 같고 두 번 실행이 같음. 거부 시험(임시 명세): 정확 행을 `partial` 로 줌, 구간 안 행을 `partial` 로 줌, 겹치는 행을 빠뜨림, 경계가 그 행 범위 밖 — 모두 멈춤.
2. `nextdbgasm.s` 진단(명세 `08_build/artifacts/m4p537/spec.json`, run `m4p537-p1`, 바탕 `m0p535-a1-stage`, 줄 틀 `machdep/i386/start.s`, `defs` `-DASSEMBLER`), `m4_id` = `{"range": ["0x4096700", "0x40967be"], "rows": ["m68k-307"], "partial": ["m68k-306"], "basis": "…"}`(근거: `__m68k_dbginit` 은 NeXTMach `__nextdbginit` 의 흐름이고 `__dbg_trap` 으로 떨어짐, 앞 `_inet_aton` 은 `rts` 로 끝나는 C 함수, 이 구간은 NeXTMach `nextdbgasm.s` 의 정의 순서와 같음):
   - N: NeXTMach 그대로.
   - D1: 원본 바이트가 요구하는 것만 바꿈 — `__nextdbginit` → `__m68k_dbginit`, `jsr _nextdbginit` → `jsr _m68k_dbginit`, `movl #dbgstack+DBG_STACK,sp` → `movl _dbgstack,sp` 와 `addl #DBG_STACK,sp`(0x400), `.lcomm dbgstack,DBG_STACK` 를 뺌, `.lcomm dbgsp,4` 를 `.lcomm dbgrts,4` 뒤에, `__dbg_trap` 첫 줄 `movl sp,dbgsp`, `moveml sp@+,#0xffff` 뒤 `movl dbgsp,sp`(이름 `dbgsp` 는 진단용).
   - D2: D1 에서 `.lcomm dbgsp,4` 를 `.lcomm dbgrts,4` 앞에.
   - 원본 사실(이번 세션): `__m68k_dbginit` 의 저장 주소 0x40c96d8·0x40c971a·0x40c971c·0x40c9720 은 `_client_pcb`(0x40c96d4) + 4·70·72·76(python) 으로 NeXTMach 식 `+4`, `+(17*4)+2`, `+(17*4)+4`, `+(17*4)+8` 과 같습니다. 0x40b5638 은 `_dbg_trap` 이 쓰고 `_SENDEXC` 가 읽습니다(§536.1).
   - 측정: `compare`(명시적으로 `diag_gate` 단언, `full_span`, L1, 미정의), `m68k_funcbytes.py 4096700 40967be 40b563c=dbgrts 40b5640=dbgsp`, `__bss` 크기와 지역 기호의 `__bss` 시작 기준 거리, D1·D2 에 따로 `m5_m68k_zerofill.py objs`(각자 자신을 REF, 출력 폴더 따로) 와 받아들인 모든 m68k 배치(§464·M5 기록·§526)와의 겹침 python 대조.
   판정(미리 정함): D1·D2 가운데 `__text` 190 B, 5/5 같음, L1 사유가 `__DATA,__bss: unverified` 하나, `__bss` 8 B 에서 `dbgrts` 0·`dbgsp` 4, zerofill `reference-inferred`·겹침 0 인 꼴이 있으면 07 꼴(새 변수 이름, 뺀 줄 처리)을 여쭙고 구현 계획(`CODE+BSS_INFERRED`, D113)을 씁니다. 없으면 기록하고 멈춥니다.

### 537.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 지금 `span` 은 `rows` 가 비면 거부(154 행)하므로, 완전히 덮는 행이 없는 구간(예: [0x40964f2, 0x4096700) 의 `_SENDEXC`·`_inet_aton`)을 받으려면 `rows` ∪ `partial` 이 비지 않음으로 바꿀 것 | `m4_m68k_probe.py:154` 읽음; 함수 표 3275 행 부근 | ✅ |
| 시험을 더할 것: 인접한 두 객체가 같은 부분 행을 나눠 덮음(받음)·경계를 겹치게 바꿈(거부); [0x40964c0, 0x40967be) 는 행 307 완전 + 305·306 부분(하나라도 빠지면 거부); 부분 행 중복·두 목록에 같은 행·겹치지 않는 부분 행(거부) | 인벤토리 109 행(305 의 끝 범위 0x4096386–0x40964f2) | ✅ |
| "`lo` 또는 `hi` 가 그 행 범위 안" 조건은 맞음; 다른 호출자는 `rows` 에 부분 행이 없어도 됨; 상태표는 136 B 만 셈(객체 190 B, 부분 54 B) | 호출자 grep(312·422·status 95 행) | ✅ 상태표 기록에 객체 구간 바이트도 함께 적음 |
| D1 의 바뀜은 원본이 요구하는 것과 같음 | 이번 세션 원본 목록 0x4096700–0x40967be | ✅ |

### 537.2 결과(2026-10-26)

- 도구: `m4_m68k_probe.py` 462 → 480 행(`span` 의 `partial`, `partial_rows()`, 기록 키 `partial_rows` 는 부분 행이 있을 때만), `m4_m68k_status.py` 143 → 146 행(열 `partial_rows`, 요약 `partial_rows`·`object_bytes`).
  - 회귀: §512·§523·§535 최종 run 을 다시 `compare` 한 기록이 `tool_sha256` 말고 같고 L1 파일이 바이트 같음; 상태표는 지금 기록으로 새 열 말고 같고 두 번 실행이 같음(새 요약 `object_bytes` 17642 는 객체 구간 합으로, 덮은 행 바이트 17242 와 다름).
  - `span` 시험 11 개 모두 기대대로: 받음 — 대상 구간, 인접 구간 [0x40964f2, 0x4096700)(`rows` 빔, 306 부분), [0x40964c0, 0x40967be)(307 완전, 305·306 부분); 거부 — 305 빠짐, 306 빠짐, 정확 행을 부분으로, 부분 중복, 두 목록에 같은 행, 겹치지 않는 부분 행, 빈 `partial`, 행 없음. 상태표에서 두 객체가 같은 부분 행을 나눠 덮는 경우는 기록이 없어 시험하지 못했습니다(구간 겹침 검사는 바꾸지 않음).
- run `m4p537-p1`(기록 `09_validation/reconstruction/m4-m68k-probe-p537-20261026.json`): 여섯 명령 종료 0·경고 0, `diag_gate` 참(단언), i386 머리 0. 기록에 `partial_rows` = [`m68k-306`].
  - N: `__text` 172 B, `__bss` 1028 B(`dbgstack`, `dbgrts`), 3/5(`__m68k_dbginit` 없음, `__dbg_trap` 58/70 B), 원본에 없는 미정의 `_nextdbginit`.
  - D1: `__text` 190 B, 5/5(`m4-m68k-funcbytes-p537-D1-20261026.json`), L1 사유 `__DATA,__bss: unverified` 하나(`provisional`), `__bss` 8 B 에서 `dbgrts` 0·`dbgsp` 4. zerofill(`m4-m68k-zerofill-p537-D1-20261026.json`): `reference-inferred`, 후보 [0x40b563c, 0x40b5644), 참조 4, 문제 0; 받아들인 m68k 배치 29 개(§464·M5 기록·§526)와 겹침 0(python).
  - D2: 함수 대조는 이름으로 5/5 이지만 `__bss` 순서가 반대(`dbgsp` 0)라 L1 이 `__text` 참조를 확인하지 못함(`__TEXT,__text: unverified`). 곧 원본은 `dbgrts` 가 앞입니다.
- 판정: 미리 정한 첫 갈래(D1)입니다. 07 꼴을 사용자께 여쭙니다.
- 사용자 결정(2026-10-26, AskUserQuestion): 새 정적 변수 이름 `dbgsavesp`; 원본에 없는 줄은 지우고 바뀐·더한 줄에 표시, 머리 주석·MODIFICATIONS·근거 문서에 적음. 질문 문구의 "`// plan 539`" 는 제 번호 착오이며, 표시는 이 구현 계획 번호(plan 538)로 답니다.

## 538. M4-44 D117 구현 계획 — 07 `src/machdep/m68k/nextdbgasm.s`(코딩 전, 2026-10-26)

1. 꼴 L(`08_build/artifacts/m4p538/src/nextdbgasm_L.s`) = §537 D1 에서 `dbgsp` 를 `dbgsavesp` 로 바꾼 글(표시 없음). D1 과의 차이는 그 이름뿐이어야 합니다(python).
2. 07 `src/machdep/m68k/nextdbgasm.s`(D103) = L + `//` 설명 주석 한 덩이(NeXTMach 바탕, 원본 구간 [0x4096700, 0x40967be) 과 부분 행 306, 뺀 것: `.lcomm dbgstack,DBG_STACK` 와 그 주석; 바꾼 것: `__m68k_dbginit`·`_m68k_dbginit` 이름, `_dbgstack` 포인터 + `DBG_STACK`; 더한 것: `.lcomm dbgsavesp,4`, `__dbg_trap` 의 저장·복원 두 줄; `__bss` 는 `dbgrts`, `dbgsavesp` 순; D024·D103·D108·D117) + 바뀐·더한 줄 끝의 `// plan 538` 표시. `//` 주석을 뺀 줄이 L 과 같음(python).
3. `stage_m68k.py`: `M4FILES[538]` = 535 목록 + `nextdbgasm.s`, `M4HEADERS[538]` = 535, `EXCEPTS[538]` = 535. 회귀: `--plan 535` 재생성 = `m0p535-a1-stage`, `--plan 538 stage m0p538-a1-stage` 와의 차이는 이 파일 하나. 새 `src/machdep/m68k/` 파일이라 M5 205 줄은 읽지 않습니다(§520.1·§529 와 같은 이유).
4. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시 `m4_x86_inputs.py s6ll`, `--plan 538 x86gate`).
5. 확인 run `m4p538-p1`(바탕 `m0p538-a1-stage`, F = `@machdep/m68k/nextdbgasm.s`, L, 줄 틀 `machdep/i386/start.s`, `defs` `-DASSEMBLER`, `m4_id` = §537 의 명시 구간): F·L `provisional`(사유 bss 하나), canon·`obj_sig` 같음, 5/5(대응 `40b563c=dbgrts 40b5640=dbgsavesp`), §537 D1 과 섹션 바이트 같음; run `m4p538-e1` `-E` 토큰 F = L.
6. 최종 run `m4p538-a1`(REF = L, `bss_inferred` [`nextdbgasm`]): `gate.ok`; `m5_m68k_zerofill.py objs`(REF = L) `ok`; python 확인: `__text` 190 B·`__bss` 8 B(`dbgrts` 0, `dbgsavesp` 4), 외부 정의 = 원본 진입점 다섯, 원본에 없는 미정의 0, 입력 사슬, L1 0x4096700 사유 bss 하나, 5/5, 이전에 받아들인 배치 29 개(§537 진단 기록 제외)와 겹침 0, `diag_gate` 단언.
7. 기록: 상태표(`ACCEPTED` p538 + zerofill 기록; `partial_rows` = `m68k-306`; 덮은 행 307; 두 번 실행 같음, 앞 18 행 그대로), PROVENANCE(`nextmach+authored`), MODIFICATIONS, DECISIONS D117, 근거 `m68k-nextdbgasm.md`, diff(NeXTMach 대비) `m68k-nextdbgasm.diff`, M7 의무(bss 배치, `_dbgstack`·`_client_pcb`·`_client_running` 정의 객체, 행 306 의 나머지 `_SENDEXC`·`_inet_aton`).
관문: 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 538.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 6 의 겹침 비교 대상은 이전에 받아들인 29 개(§537 진단 기록은 빼야 함, 넣으면 자기 겹침) | §537.2 의 python 셈(29) | ✅ 제 문구 오류("30 개(29 + 없음)")를 "29 개" 로 고침 |
| 근거 문서를 상태표 실행보다 먼저 만들 것(§526.2 의 순서 오류) | `m4_m68k_status.py` 의 근거 문서 단언 | ✅ |
| `libc.s`·`monitor.s` 도 `//` 주석을 씀; `-E` 비교는 주석을 뺀 토큰으로 | 07 두 파일 grep | ✅ |
| `bss_inferred` 와 `partial` 명시 구간은 서로 독립 | 도구 읽음 | ⏭️ 최종 run 으로 확인 |

### 538.2 결과(2026-10-26)

- 1–2: L(`08_build/artifacts/m4p538/src/nextdbgasm_L.s`)은 §537 D1 과 `dbgsp` → `dbgsavesp` 세 줄만 다릅니다. 07 `src/machdep/m68k/nextdbgasm.s`(88 행, SHA-256 `51f08cd0…`)는 `//` 주석을 뺀 58 줄이 L 과 같습니다.
- 3: `stage_m68k.py` 645 → 649 행. `--plan 535` 재생성 = `m0p535-a1-stage`(모든 키), `--plan 538 stage m0p538-a1-stage`(923 파일)와의 차이는 `nextdbgasm.s` 하나.
- 4: x86 입력 불변(`m4-x86-inputs-p538-20261026.json` ok; `--plan 538 x86gate` 일곱 묶음 `same`, v183 경로 0).
- 5: run `m4p538-p1`(`m4-m68k-probe-p538-20261026.json`, `diag_gate` 참(단언)): F·L `provisional`(사유 bss 하나), canon·`obj_sig` 같음, §537 D1 과 `__text`·`__bss` 바이트 같음, 5/5. run `m4p538-e1`: 주석을 뺀 `-E` 토큰 301 개 같음.
- 6: run `m4p538-a1`(REF = p1 L, `bss_inferred` [`nextdbgasm`]; `m4-m68k-p538-final-20261026.json`): `gate` 모두 참, 객체 SHA-256 `9d80ee38…`(p1 L 과 같은 바이트). zerofill `m4-m68k-zerofill-p538-20261026.json`: `reference-inferred`, 후보 [0x40b563c, 0x40b5644), 요약 `not_ok`·`overlaps` 빔; 이전에 받아들인 배치 29 개와 겹침 0. python 확인(`m4-m68k-p538-checks-20261026.json`, `ok` 참): 섹션 `__text` 190·`__bss` 8, `dbgrts` +0·`dbgsavesp` +4, 외부 정의 = 원본 다섯, COMMON 0, 원본에 없는 미정의 0, `rows` = [307]·`partial_rows` = [306], 입력 사슬, L1 0x4096700 사유 bss 하나, 5/5, i386 없음.
- 7: 상태표 19 객체(OBJECT_MATCH 17, CODE+BSS_INFERRED 2), 덮은 행 39/188, 17378 B(8.05%), `partial_rows` = [`m68k-306`], 객체 구간 합 17832 B, 앞 18 행은 새 열 말고 그대로, 두 번 돌린 출력 같음(`m4-m68k-status-p538-20261026.json`; `m4_m68k_status.py` 146 → 148 행). PROVENANCE 1134 → 1135 행(경로 중복 0), MODIFICATIONS 680 → 681 행, DECISIONS D117(120 → 121 행), 근거 `06_reconstruction/evidence/m68k-nextdbgasm.md`, diff `m68k-nextdbgasm.diff`(58 행).
