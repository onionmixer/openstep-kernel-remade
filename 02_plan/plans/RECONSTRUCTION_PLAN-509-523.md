# 커널 소스 복원 작업계획 — 보관 §509–523

`02_plan/RECONSTRUCTION_PLAN.md` 의 §509–523(m68k M4: `mem`, 어셈블리 경로 `libc.s`·`monitor.s`, `machargs`, `in_cksum`, `in_bootp`; 결정 D107–D112)을 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-26, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 본문은 `---` 아래부터입니다.

---

## 509. M4-15 세부 계획 — `mem` 의 1997 년 꼴 진단(07 변경 없음; 코딩 전, 2026-10-24)

배경: 남은 M4 후보 넷 가운데 `mem` 을 먼저 다룹니다.
- 이유: 정확 경계 세 행(`m68k-227`·`228`·`229`, [0x4072264, 0x407247e), 538 B), NeXTMach 대응률 100% 입니다.
- `tty_pty` 꼬리는 M5 공유 파일에 붙어 x86 재빌드가 걸리고, `in_bootp` 는 3.8 KB, `in_cksum` 은 참고 글이 없는 `_oc_cksum` 이 딸려 있습니다.

확인한 사실(이번 세션; 원본 목록 `image.txt`, 기호표, NeXTMach `next/mem.c` 179 줄):
- 원본 함수: `_mmopen`(30 B)·`_mmread`(26)·`_mmwrite`(28)·`_mmrw`(392)·`_mmmmap`(62) — NeXTMach `mem.c` 의 다섯 함수와 같은 이름·순서입니다.
- `_mmrw` 의 `MM_MEM` 갈래:
  - `c = min(PAGE_SIZE - o, len)` 는 `_min`(0x400bf42) 호출이고, `page_size`(0x40b06d0)·`page_mask`(0x40b59dc)를 씁니다.
  - 경계 검사가 NeXTMach 의 `o > P_MAINMEM + P_MEMSIZE`(`next/cpu.h:188–189`: `SLOT_ID+0x04000000`, `0x04000000`)와 다릅니다. 원본은 `slot_id + 0x04000000` 을 먼저 계산한 뒤 끝 주소를 고릅니다.
    - `dma_chip`(word) == 0x139 이고 `machine_type` == 3 이면 `slot_id + 0x06000000`
    - `dma_chip` == 0x139 이고 그 밖의 기계면 `(slot_id + 0x04000000) + 0x04000000`
    - 그 밖이면 `slot_id + 0x0c000000`
    - 곧 `P_MAINMEM + 크기` 이고, 크기는 0x02000000·0x04000000·0x08000000 입니다.
  - `panic("mmrw")`(`_panic`), `uiomove`(0x4009a34) 호출은 NeXTMach 와 같은 자리입니다.
- `MM_DSP` 갈래: `c = MAX(len, 8)`(`moveq #8; cmpl; bcc`), `uio_offset &= 7`, `+= 0x02008000 + slot_id_bmap`(0x40c32f8; NeXTMach `P_DSP` = `SLOT_ID_BMAP+0x02008000`, `cpu.h:152`)입니다.
- `_mmmmap`: `MM_DSP` 이고 `off == 0` 이면 `(slot_id_bmap + 0x02008000) >> page_shift`(0x40c2c04), `MM_MEM` 이면 `off >> page_shift`, 아니면 -1 입니다. NeXTMach 와 같은 꼴입니다.
- 머리:
  - `next/mmu.h`(160 줄)에는 최상위 객체 정의가 없습니다(python; 구조체·`#if GDB`).
  - `next/cpu.h` 는 원본에 없는 `_disk_chip` 을 임시 정의합니다(§505). `nextdev/snd_dspreg.h` 는 12 행에서 `next/cpu.h` 를 들입니다.
  - §498 표: `next/mmu.h`·`nextdev/snd_dspreg.h` 는 NeXTMach 에만 있고, `nextdev/busvar.h` 는 스테이징 `dev/busvar.h`, `vm/vm_param.h` 는 스테이징의 다른 경로에 있습니다.

방법(`m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p509/spec.json`, run `m4p509-p1`, 바탕 `m0p508-a1-stage`, 줄 틀은 `machdep/i386/dkbad.c` 의 x86 줄, `m4_id` [`m68k-227`, `m68k-228`, `m68k-229`]):
- N(기준): NeXTMach `mem.c` 그대로. `inc` 에 NeXTMach `next/mmu.h`·`next/cpu.h`·`nextdev/snd_dspreg.h`·`nextdev/busvar.h` 사본을 둡니다. NeXTMach 글과 원본의 차이를 함수별로 재는 것이 목적입니다.
- M1(D104·D105 꼴; NeXTMach 글에서 다음만 바꿈):
  - `<nextdev/busvar.h>` → `<dev/busvar.h>`
  - `<next/mmu.h>` 는 `inc` 사본(`m68k/mmu.h` 자리; D104 의 스테이징 이름)으로 `<m68k/mmu.h>`
  - `<next/cpu.h>` 경유 머리(`nextdev/snd_dspreg.h`)를 빼고, `P_DSP`·`sizeof(struct dsp_regs)` 는 숫자(`slot_id_bmap + 0x02008000`, 8)로 씁니다.
  - `extern int slot_id, slot_id_bmap;` 을 둡니다. `dma_chip`·`machine_type` 은 SDK `m68k/cpu.h`(`sys/user.h` 가 들임)입니다.
  - 경계 검사는 `o > slot_id + 0x04000000 + (dma_chip == 313 ? (machine_type == 3 ? 0x02000000 : 0x04000000) : 0x08000000)` 로 씁니다.
  - `vm/vm_param.h` 는 N 처럼 스테이징 경로로 풀리는지 컴파일로 봅니다(안 풀리면 오류를 결과로 적음).
- 비교: `compare`(L1, `full_span`, 정의·COMMON 과 원본 기호표 대조), 실기 `otool` 과 `funcs`.
- 기록 `09_validation/reconstruction/m4-m68k-probe-p509-20261024.json`.

판정(미리 정함; 07 은 바꾸지 않음):
- M1 이 `candidate` 이고 원본에 없는 정의 기호가 없으면, 바이트로 정해지지 않는 것(크기 식의 꼴·이름, `dsp_regs` 크기 표기, `mmu.h` 자리)을 여쭙고 구현 계획을 씁니다.
- 아니면 함수별 차이를 적고 다음 꼴을 따로 계획합니다(이번 run 에 변형을 더하지 않음).

관문(어긋나면 멈춤): 명령 종료 0·i386 머리 0, 옵션이 M5 줄과 같음(사전형 `-I` 만 더해짐), 경고는 기록(N 의 원문 경고는 결과로 적음).

### 509.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류가 둘 있습니다.
- "`vm/vm_param.h` 는 스테이징 경로로 풀리는지 컴파일로 봄" 은 틀린 전제였습니다. M5 `-I` 순서로 매니페스트를 대조하면 `vm/vm_param.h` 는 풀리지 않습니다(python). 그대로 돌렸으면 N·M1 모두 컴파일에 실패했습니다. 07 의 선례(계획 138·162·164·197 등)는 NeXTMach `vm/vm_param.h` 를 `<mach/vm_param.h>` 로 고쳐 씁니다.
- 대화에서 `mem_region_t` 가 `next/mmu.h` 에 있다고 말한 것은 틀렸습니다. 스테이징 `vm/pmap.h:178`(NeXTMach `vm/vm_page.h:164`)에 있고 `vm/vm_map.h:71` 로 들어옵니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 해석에 잘못 읽은 명령 없음; 538 B; 경계 비교는 부호 있음; 바뀐 것은 메모리 끝 주소뿐 | 이번 세션 원본 목록 직접 읽음 | ✅ |
| `MM_DSP` 의 `MAX` 는 부호 없는 비교(`bcc`); `iov_len` 은 `int` 라 숫자 `8` 은 부호 있는 비교가 되므로 `8U` 로 | 스테이징 `sys/uio.h` `int iov_len`, `sys/types.h:131–132` KERNEL 에서 `off_t` = `u_long`, `sys/param.h:275` `MAX` | ✅ M1 은 `8U` |
| `vm/vm_param.h` 가 풀리지 않음 | python(위) | ✅ 제 오류 |
| `mem_region_t` 는 `vm/pmap.h`(`vm/vm_map.h` 경유) | grep | ✅ 제 오류 |
| `next/mmu.h` 에 최상위 객체 정의 없음; `snd_dspreg.h:12` 가 `next/cpu.h` 를 들임; `struct dsp_regs` 는 `sizeof` 로만 쓰임 | 이번 세션 python·원문 | ✅ |
| `refs` 없이는 `diag_gate` 실패에도 종료 0, 옵션 차이는 기록뿐 → python 으로 따로 관문; N 의 원문 경고와 M1 의 경고를 나눌 것; 정의·COMMON 은 이름·종류·크기까지 | §505·§507 에서 같은 줄 확인 | ✅ |

계획 수정(실행 전 고정):
- N: NeXTMach `mem.c` 그대로. `inc` 에 NeXTMach `next/mmu.h`·`next/cpu.h`·`nextdev/snd_dspreg.h`·`nextdev/busvar.h` 사본과, `vm/vm_param.h` 별칭 머리(`#import <mach/vm_param.h>` 한 줄)를 둡니다.
- M1: 위 M1 에서 `<vm/vm_param.h>` → `<mach/vm_param.h>`, `MAX(iov->iov_len, 8U)`.
- M2: M1 에서 `<m68k/mmu.h>` 를 뺀 것(`next/mmu.h` 가 필요한지 봄).
- 관문(python): 명령 종료 0, M1·M2 경고 0(N 의 경고는 기록), i386 머리 0, 옵션이 M5 줄과 같음(사전형 `-I` 만 더해짐).
- 판정: M1·M2 가 `candidate` 이고 정의·COMMON 이 원본 기호표와 맞으면(이름·종류, `__common` 크기) 여쭙고 구현 계획을 씁니다.

### 509.2 결과(2026-10-24)

- run `m4p509-p1`(명세 `08_build/artifacts/m4p509/spec.json`, 스테이징 `m4p509-stage` 905 파일 = 바탕 896 + 9; 기록 `09_validation/reconstruction/m4-m68k-probe-p509-20261024.json`).
  - 6 명령 모두 종료 0·경고 0(N 포함), i386 머리 0
  - 옵션이 M5 줄과 같음(사전형 `-I` 만 더해짐)
- **M1·M2 는 `candidate` 입니다.** L1 OBJECT_MATCH, 사유 없음, `full_span`(538 B, 0x4072264 배치, 원본 이름 다섯)이고, 원본에 없는 미정의는 없습니다.
  - COMMON 10 개는 모두 원본 기호표에 있습니다. 8 개는 `__common`, `_bufpages`·`_nbuf` 는 `__data`(§508 과 같은 머리 임시 정의)입니다.
  - M1 과 M2 는 canon 이 같고, obj_sig 의 차이는 STABS 뿐입니다(`next/mmu.h` 의 구조체 형 정보). 텍스트·자료·비 STABS 기호는 같으므로 `next/mmu.h` 를 들일지는 바이트로 정해지지 않습니다.
- N(NeXTMach 그대로)은 482 B, NOT_MATCH 이고, 원본에 없는 COMMON `_disk_chip`(`next/cpu.h`)을 냅니다.
- 바이트가 정한 것: 경계 검사의 끝 주소가 기계에 따라 다름(`dma_chip`·`machine_type`), `MM_DSP` 의 `MAX` 는 부호 없는 비교(`8U`).
- 바이트로 정해지지 않는 것(사용자 결정):
  - `next/mmu.h` 를 들일지(M1: NeXTMach include 줄을 두고 07 에 사본, M2: include 줄을 뺌)
  - 이름 공급: D105·D106 과 같이 숫자·파일 안 `extern` 으로 할지

사용자 결정 D107(2026-10-24): m68k `mem` 은
- `next/mmu.h` 를 둡니다("M1: 둠"; 바이트로는 STABS 만 다름).
- 이름 없는 값은 파일 안 매크로 이름으로 씁니다("파일 안 매크로 이름"; 제 추천은 숫자였음). NeXTMach `next/cpu.h` 의 이름 `SLOT_ID`·`SLOT_ID_BMAP`·`P_MAINMEM`·`P_MEMSIZE`·`P_DSP` 를 `mem.c` 안에 정의합니다. `P_MEMSIZE` 의 1997 년 정의는 알 수 없어 원본 바이트에서 작성합니다.
- `MM_DSP` 크기는 "snd_dspreg.h 고친 사본" 입니다. NeXTMach `nextdev/snd_dspreg.h` 에서 `#import <next/cpu.h>` 줄만 빼고(표시) 07 에 두고, `mem.c` 는 `sizeof(struct dsp_regs)` 를 그대로 씁니다.

## 510. M4-16 D107 확인과 구현 계획 — 07 `src/machdep/m68k/mem.c` 와 NeXTMach 머리 둘(코딩 전, 2026-10-24)

확인한 사실(이번 세션):
- SDK 의 배치(스테이징 매니페스트와 NeXTMach 이름 대조, python):
  - NeXTMach `next/X.h` → SDK `bsd/m68k/X.h`(`cpu.h`·`spl.h`·`table.h`·`reg.h` 등)
  - NeXTMach `nextdev/dma.h` → SDK `bsd/dev/m68k/dma.h`
  - 그래서 D104 자리는 `next/mmu.h` → 스테이징 `src/bsd/m68k/mmu.h`(`<m68k/mmu.h>`), `nextdev/snd_dspreg.h` → `src/bsd/dev/m68k/snd_dspreg.h`(`<dev/m68k/snd_dspreg.h>`, `dma.h` 선례)입니다. 두 자리 모두 지금 비어 있습니다.
- NeXTMach `nextdev/snd_dspreg.h`(93 줄):
  - 12 행 `#import <next/cpu.h>`
  - `struct dsp_regs` 는 `u_char` 넷과 `u_int` 공용체로 8 바이트
  - `#if KERNEL` 덩이는 매크로뿐이고, 최상위 객체 정의가 없습니다.
- `next/mmu.h` 는 최상위 객체 정의가 없고 `<gdb.h>`(m68k 생성 구성)를 들입니다(§509 M1 컴파일 성공).
- x86 `stage_headers.py` 의 07 `nextmach` 조회는 `NEXTMACH_DIRS`(`next`·`nextdev` 없음)·`NEXTMACH_RENAME` 뿐입니다(§506.1).

방법:
1. 확인 변형(run `m4p510-p1`, 명세 `08_build/artifacts/m4p510/spec.json`, 바탕 `m0p508-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` [227, 228, 229]):
   - M3 = NeXTMach `mem.c` 에서 다음만 바꾼 것.
     - include: `<vm/vm_param.h>` → `<mach/vm_param.h>`, `<next/mmu.h>` → `<m68k/mmu.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`, `<nextdev/snd_dspreg.h>` → `<dev/m68k/snd_dspreg.h>`
     - include 뒤: `extern int slot_id, slot_id_bmap;` 와 매크로 다섯. `SLOT_ID`=`slot_id`, `SLOT_ID_BMAP`=`slot_id_bmap`, `P_MAINMEM`=`(SLOT_ID+0x04000000)`, `P_MEMSIZE`=`(dma_chip == 313 ? (machine_type == 3 ? 0x02000000 : 0x04000000) : 0x08000000)`, `P_DSP`=`(SLOT_ID_BMAP+0x02008000)`
     - 코드 줄은 NeXTMach 그대로입니다(`o > P_MAINMEM + P_MEMSIZE`, `sizeof(struct dsp_regs)`, `P_DSP`).
   - `inc`: NeXTMach `next/mmu.h` 사본(`m68k/mmu.h`), `snd_dspreg.h` 고친 사본(`dev/m68k/snd_dspreg.h`; 12 행을 표시 주석으로 바꿈).
   - 대조 M1: §509 M1 그대로. M3 는 M1 과 canon 같음·비 STABS 기호 같음이어야 하고, M3 자체가 `candidate` 여야 합니다.
2. 07 파일 셋:
   - `07_kernel/nextmach/next/mmu.h` = NeXTMach 그대로
   - `07_kernel/nextmach/nextdev/snd_dspreg.h` = 1 의 고친 사본
   - `07_kernel/src/machdep/m68k/mem.c` = M3 에 설명 주석 한 덩이와 `/* plan 510 (D104/D107) */` 표시를 더한 것. 주석을 뺀 토큰이 M3 와 같음(python).
3. `stage_m68k.py`:
   - `M4FILES[510]` = 508 목록 + `mem.c`
   - `M4HEADERS[510]` = 506 항목 + (`next/mmu.h`, `src/bsd/m68k/mmu.h`) + (`nextdev/snd_dspreg.h`, `src/bsd/dev/m68k/snd_dspreg.h`)
   - `EXCEPTS[510]`, 문서 줄
   - 회귀: `--plan 508` 으로 다시 만든 매니페스트가 `m0p508-a1-stage` 와 같음
   - `--plan 510 stage m0p510-a1-stage` 와의 차이는 `mem.c`·`mmu.h`·`snd_dspreg.h` 셋
4. x86 입력 불변: `m4_x86_inputs.py s6ll`(`L2_FORMS`·`L2_EXPECT` 명시), `--plan 510 x86gate`.
5. 최종 run `m4p510-a1`(명세 `08_build/artifacts/m4p510/final/spec.json`, 변형 `F` = `@machdep/m68k/mem.c`, 바탕 `m0p510-a1-stage`, `refs` = M3 객체).
   - `gate.ok`
   - python 확인: 정의·COMMON 이 REF 와 같음(이름·종류·크기), 입력 사슬(소스·머리 둘) 07 = 스테이징 = run 사본, 의존 목록에서 두 머리가 `07_kernel/nextmach/…` 로 풀림, 옵션이 M5 줄과 같음
6. 상태표(근거 문서 먼저, `ACCEPTED` 추가, 두 번 돌린 출력 같음)와 기록:
   - PROVENANCE 새 행 셋: `mem.c` `nextmach+authored`, `mmu.h` 그대로, `snd_dspreg.h` 한 줄 뺌
   - MODIFICATIONS, DECISIONS D107, diff `06_reconstruction/evidence/m68k-mem.diff`, 근거 문서 `m68k-mem.md`, 상태 절과 결과 절

관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 옵션이 M5 줄과 같음, M3 `candidate` 이고 M1 과 canon 같음.

### 510.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: 최종 명세를 `08_build/artifacts/m4p510/final/spec.json` 에 두면 상태표 도구가 읽는 `m4p<계획>/spec.json`(`m4_m68k_status.py:51`)과 어긋나 명세 해시 검사가 실패합니다. 확인 명세를 `m4p510/confirm/spec.json`, 최종 명세를 `m4p510/spec.json` 으로 바꿉니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| SDK 배치(`next/X.h` → `bsd/m68k/`, `nextdev/dma.h` → `bsd/dev/m68k/`)가 맞고, 두 자리는 비어 있으며 `-Isrc/src/bsd` 로 풀림 | 이번 세션 python(매니페스트·`-I` 순서; `dev/m68k/dma.h` 선례 풀림) | ✅ |
| `snd_dspreg.h` 는 12 행만 `next/cpu.h` 에 기대고, `struct dsp_regs` 8 B·정렬 2, 최상위 객체 정의 없음 | 원문 읽음(위), §509 N 의 STABS `dsp_regs …=s8`(codex 인용, 크기는 원문 필드로 셈: 1+1+1+1+4) | ✅ |
| 매크로를 펼친 경계식은 M1 과 같은 토큰 묶음; 다섯 이름은 스테이징 어디에도 정의 없음 | 이번 세션 grep 0 | ✅ |
| `M4HEADERS[510]` 은 `bmap.h` 를 포함한 누적 목록이어야 함(선택은 목록 전체를 바꿈) | `stage_m68k.py` 선택 규칙(§506) | ✅ |
| 최종 REF 는 M3(STABS 가 M1 과 다름); 확인 단계의 진단·옵션·`candidate`·비 STABS 기호·COMMON 크기를 python 으로 단언; COMMON 10 개 중 `_bufpages`·`_nbuf` 는 원본 `__data`(M7 의무) | §509.2 결과, §508 과 같은 관문 | ✅ |
| 두 머리의 원래 고지를 두고, 고친 머리의 URL·커밋·줄·뺀 줄·해시·스테이징 대응, `P_MEMSIZE` 작성과 이어받은 매크로의 구분, 함수별 출처를 적을 것 | 설계 | ✅ |

### 510.2 결과(2026-10-24)

- 1(확인): run `m4p510-p1`(명세 `08_build/artifacts/m4p510/confirm/spec.json`, 스테이징 `m4p510-stage` 901 파일 = 바탕 896 + 5; 기록 `09_validation/reconstruction/m4-m68k-probe-p510-20261024.json`).
  - 4 명령 종료 0·경고 0, i386 머리 0, 옵션이 M5 줄과 같음
  - M3 는 `candidate`(OBJECT_MATCH 538 B, `full_span`)이고, M1 과 canon·머리·절·비 STABS 기호가 같음
  - 대조 M1 은 §509 의 M1 과 같음(재현)
  - REF = M3 객체(SHA-256 `f5fea39c…`)
- 2: 07 파일 셋.
  - `07_kernel/src/machdep/m68k/mem.c`(198 행, SHA-256 `e49923d9…`; 주석을 뺀 토큰 653 개가 M3 와 같음)
  - `07_kernel/nextmach/next/mmu.h`(NeXTMach 와 같음, `384ce263…`)
  - `07_kernel/nextmach/nextdev/snd_dspreg.h`(93 행, 12 행만 다름, `12437f2e…`)
  - diff `06_reconstruction/evidence/m68k-mem.diff`(57 행)
- 3: `stage_m68k.py` 591 → 595 행(고치기 전 사본 `08_build/artifacts/m4p510/stage_m68k.py.before510`).
  - `--plan 508` 으로 다시 만든 매니페스트가 `m0p508-a1-stage` 와 같음
  - `--plan 510 stage m0p510-a1-stage`(899 파일)와의 차이는 `mem.c`·`mmu.h`·`snd_dspreg.h` 셋, `m4_headers` 셋
- 4: x86 입력 불변(`m4-x86-inputs-p510-20261024.json` ok, `--plan 510 x86gate` 일곱 묶음 같음).
- 5: run `m4p510-a1`(명세 `08_build/artifacts/m4p510/spec.json`, 기록 `09_validation/reconstruction/m4-m68k-p510-final-20261024.json`). `gate` 모두 참이고, python 확인(`m4-m68k-p510-checks-20261024.json`, `ok` 참):
  - 정의·COMMON 이 REF 와 같음
  - COMMON 10 = `__common` 8 + `__data` 2(`_bufpages`·`_nbuf`, M7 의무)
  - 입력 사슬 셋 같음
  - 두 머리가 `07_kernel/nextmach` 로 풀림
  - 옵션이 M5 줄과 같음
- 6: 상태표 9 객체, §495 행 13/188, 5094 B(2.36%; python; `m4_m68k_status.py` 110 → 111 행, 앞 여덟 행 그대로, 두 번 돌린 출력 같음).
  - PROVENANCE 새 행 셋(1107 → 1110 행, 경로 중복 0)
  - MODIFICATIONS 셋(653 → 656 행)
  - DECISIONS D107(110 → 111 행)
  - 근거 문서 `06_reconstruction/evidence/m68k-mem.md`(NeXTMach 줄 번호는 python 으로 대조해 `cpu.h` 96·98·152·188 행으로 고침)

## 511. M4-17 세부 계획 — 어셈블리 경로 첫 시험: NeXTMach `next/libc.s` 한 객체(07 변경 없음; 도구 확장; 코딩 전, 2026-10-24)

배경: 남은 C 후보는 모두 무겁습니다.
- `tty_pty` 꼬리: 07 공유 파일 `bsd/kern/tty_pty.c` 에서 §189 가 뺀 NeXTMach `#if NeXT` 덩이(`pts_process_putc`·`ptsputc`·`ptsputcbuf`)를 m68k 에서 되살려야 하고, 받아들인 M5 객체의 자료·bss 검증이 함께 바뀝니다.
- `in_bootp`: 3.8 KB.
- `in_cksum`: 손 어셈블리 `_oc_cksum` 이 딸려 있습니다.

묶음 A(어셈블리, §495 51 행)를 다룰 경로를 아직 세우지 않았으므로, 가장 작은 확실한 어셈블리 단위로 그 경로를 먼저 시험합니다.

확인한 사실(이번 세션):
- 원본 [0x4092c50, 0x40930fa)(1194 B, python)의 함수 15 개(`m68k-functions.tsv`)는 NeXTMach `next/libc.s`(478 줄)의 `PROCENTRY` 15 개와 이름·순서가 같습니다: `abs`·`bcmp`·`memmove`·`bcopy`·`bytecopy`·`bzero`·`ffs`·`msb`·`index`·`strncpy`·`strcat`·`strcmp`·`strcpy`·`strncmp`·`strlen`.
- 원본 `_memmove` 는 `bra 0x4092d38:l` 로 `_bcopy` 안(+0xc, NeXTMach 의 지역 라벨 `bcopy_common`)으로 뜁니다. 지역 라벨이므로 두 함수가 한 객체에 있었다는 근거입니다.
- 원본 목록의 `abs`·`memmove`·`strncpy`·`strcat`·`strcmp`·`strcpy`·`strncmp`·`strlen` 명령은 NeXTMach `libc.s` 의 글과 같은 꼴입니다(`link a6,#0` … `unlk; rts`).
- `libc.s` 의 전처리 줄은 15 행 `#import <next/cframe.h>` 하나입니다. NeXTMach `next/cframe.h` 의 `PROCENTRY` 는 `##`(ANSI 토큰 붙이기)를 쓰고, `<gdb.h>` 를 들입니다(m68k 생성 구성에 있음). 스테이징에는 SDK `architecture/m68k/asm_help.h` 가 있고 `cframe.h` 는 없습니다.
- 구간을 덮는 §495 행은 14 개입니다(277–290). 이 가운데 282(x86-ffs)·283(file `libc.s`)·284(x86-index)는 경계가 정확하지 않고, 278(x86-memcmp)·290(x86-strlen)은 묶음 E(`_bcmp`·`_strlen` 이 `bsd/subr_xxx.c` 와 `libc.s` 에 함께 있어 모호)입니다.
- x86 07 의 `.s` 컴파일 줄(예: `machdep/i386/start.s`)은 C 와 같은 `/bin/cc -traditional-cpp -nostdinc … -c X.s` 이고, `-D`·`-I` 가 M5 m68k 줄과 같습니다(python, 24 개).
- probe 도구의 `span`(`m4_m68k_probe.py:133–142`)은 정확한 행만 받습니다.

방법:
1. 도구 확장(`m4_m68k_probe.py`; 상태표 도구는 같은 `span` 을 씀): `m4_id` 가 `{"range": [lo, hi], "rows": [...], "basis": "<근거>"}` 이면 다음을 단언하고 (lo, hi, rows) 를 돌려줍니다.
   - `lo`·`hi` 는 함수 표 진입점 경계입니다. `lo` 는 어떤 진입점이고, `hi` 는 어떤 진입점이거나 구간 마지막 진입점의 `end` 입니다.
   - 구간과 겹치는 §495 행이 `rows` 와 정확히 같습니다.
   - 각 행의 가능한 범위 `[start_lo, end_hi)` 가 구간 안에 있습니다.
   - `basis` 는 비어 있지 않습니다.
   - 기존 꼴(문자열·목록)은 그대로입니다.
   - 회귀: 고친 도구로 §510 최종 run(`m4p510-a1`)과 §509 run 을 다시 비교해 판정·`gate`·짝 같음이 이전 기록과 같아야 합니다.
2. 진단 run `m4p511-p1`(명세 `08_build/artifacts/m4p511/spec.json`, 바탕 `m0p510-a1-stage`):
   - 줄 틀: `machdep/i386/start.s` 의 x86 줄에 §429 치환
   - 대상 `libc`, `m4_id` = 위 구간 `[0x4092c50, 0x40930fa)` + 행 277–290 + basis(함수 순서·지역 라벨 분기)
   - 변형 N = NeXTMach `libc.s` 그대로, `inc` 에 NeXTMach `next/cframe.h` 사본
3. 비교: `compare`(L1, `full_span`, 원본 이름 15, 원본에 없는 미정의), 정의 기호, 맞지 않으면 실기 `otool` 과 `funcs`.

판정(미리 정함; 07 은 바꾸지 않음):
- N 이 `candidate` 이면, 바이트로 정해지지 않는 것을 여쭙고 구현 계획을 씁니다(07 자리, `cframe.h` 공급 방식(NeXTMach 사본 또는 SDK `asm_help.h`), include 표기).
- 컴파일이 실패하면 오류(예: `-traditional-cpp` 에서 `##`)를 기록하고, 고칠 꼴을 따로 계획합니다.
- 맞지 않으면 함수별 차이를 적습니다.

관문(어긋나면 멈춤): 회귀 같음, 명령 상태 기록, 옵션이 M5 줄과 같음, i386 머리 0.

### 511.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(작음): "`libc.s` 의 전처리 줄은 `#import` 하나" 는 include 줄에 대해서만 맞습니다. `#define BCMP_THRESH`·`BCOPY_THRESH` 도 있습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 함수 15 개·순서·1194 B·`memmove` → `bcopy+0xc`·행 277–290(겹침·포함)·`.s` 줄 옵션이 맞음 | 이번 세션 python(겹치는 행 14 개, 모두 구간 안), 원본 목록 | ✅ |
| 15 함수 모두 NeXTMach 글과 실질 차이 없음(어셈블러 별칭·짧은 꼴 차이뿐); 원본 목록은 `msb` 앞의 표를 명령으로 읽어 어긋남 | 원본 목록 일부를 이번 세션에 읽음(`abs`·`memmove`·`strncpy`…`strlen`); 나머지는 미확인 | ⚖️ 컴파일 결과로 판정 |
| GDB=1·GPROF 없음이면 `PROCENTRY` = `.globl _name; _name: link a6,#0`, `PROCEXIT` = `unlk a6; rts`; `a_p0`… 는 `cframe.h` | `cframe.h:73–85` grep(이번 세션) | ✅ |
| NeXTMach 는 어셈블리를 `-DKERNEL -DASSEMBLER` 로 빌드; `ASSEMBLER` 가 없으면 `cframe.h` 의 `struct frame` 이 어셈블러에 들어감 | `conf/Makefile.template:118` 읽음, x86 `s6l4-g1a.cmd` 의 `-DASSEMBLER` 0 건 | ✅ 변형 NA 를 더함 |
| SDK `asm_help.h` 는 `PROCENTRY`·인자 매크로가 없어 `cframe.h` 를 대신하지 못함 | 설계(구현 결정 때 다시 확인) | ⏭️ 이번 진단에 영향 없음 |
| `span` 확장을 엄격히: `lo < hi`, 함수 열의 마지막 `end` = `hi`, 행 id 중복 없음, 겹침 집합 같음(`[start_lo, end_hi)`), 포함, `basis` 공백 아님, 주소 없는 행 처리, `m4_id_alt` 에도 적용 | 설계 | ✅ |
| 상태표의 바이트는 행 최소 바이트(이 행들 794 B)이고 구간은 1194 B — 둘을 나눠 적을 것 | python(codex 값; 받아들일 때 다시 셈) | ⏭️ 받아들일 때 확인 |
| 관문: 의존 목록이 비어 있지 않고 `cframe.h`·`gdb.h` 를 담을 것; 옵션 같음을 python 으로; `refs` 없이도 `diag_gate` 를 같이 볼 것; 잘못된 구간을 거부하는 시험; 상태표 회귀 | 설계 | ✅ |

계획 수정(실행 전 고정):
- 도구:
  - 사전형 변형에 `defs`(`-D…` 문자열 목록; 선택)를 받습니다. 그 변형의 컴파일·의존 줄에서 마지막 `-D` 뒤에 넣습니다.
  - `span` 은 위 검사를 모두 단언합니다(사전형 `m4_id`).
  - 잘못된 구간(경계가 진입점이 아님, 행 빠짐, 행 넘침, 빈 `basis`)을 거부하는지 python 으로 시험합니다.
- 회귀(어긋나면 멈춤): 고친 도구로 §499(`m4_id_alt` 있음)·§509·§510 최종 run 을 다시 비교합니다. 도구 해시를 뺀 기록이 같아야 하고, 상태표를 다시 만든 출력이 지금과 같아야 합니다.
- 변형: N(그대로) + NA(`defs` = `-DASSEMBLER`). 둘 다 `inc` 에 NeXTMach `next/cframe.h` 를 둡니다.
- 관문(python):
  - 옵션이 M5 줄과 같고, 사전형 `-I` 와 NA 의 `-DASSEMBLER` 만 더해짐
  - 의존 목록에 `cframe.h`·`gdb.h` 가 있음
  - `diag_gate`
  - 판정은 `candidate` 와 `diag_gate` 를 함께 봄

### 511.2 결과(2026-10-24)

- 도구(`m4_m68k_probe.py` 429 → 456 행; 고치기 전 사본 `08_build/artifacts/m4p511/m4_m68k_probe.py.before511`):
  - 사전형 변형의 `defs` 를 받습니다.
  - 사전형 `m4_id`(명시 구간)를 받습니다.
  - 잘못된 구간 일곱 꼴(경계가 진입점 아님, 끝이 아님, 행 빠짐, 행 넘침, 빈 `basis`, 중복 행, `lo ≥ hi`)을 모두 거부하고, 옛 꼴(문자열·목록)은 그대로입니다(python 시험).
- 회귀:
  - 고친 도구로 다시 비교한 §509·§510 최종 run 기록이 도구 해시 말고 같습니다.
  - §499 run 은 그 뒤에 더한 칸(`dep_headers`·`err_lines`·`target`·`defined_symbols`)만 늘고, 옛 칸의 값이 모두 같습니다.
  - 상태표를 다시 만든 출력이 지금과 같습니다.
- run `m4p511-p1`(명세 `08_build/artifacts/m4p511/spec.json`, 스테이징 `m4p511-stage` 903 파일 = 바탕 899 + 4; 기록 `09_validation/reconstruction/m4-m68k-probe-p511-20261024.json`). 옵션은 M5 줄과 같고, 사전형 `-I` 와 NA 의 `-DASSEMBLER` 만 더해졌습니다.
  - N(`-DASSEMBLER` 없음): 컴파일 실패. `cframe.h:23` "Unknown operator -- Statement 'struct frame{' ignored" 등. `ASSEMBLER` 가 없으면 C 선언이 어셈블러에 들어갑니다(예상과 같음).
  - **NA(`-DASSEMBLER`): `candidate`** 입니다. L1 OBJECT_MATCH, 사유 없음, `full_span`(1194 B, 0x4092c50 배치, 원본 이름 15 개 모두), 원본에 없는 미정의 없음, 경고 0, i386 머리 0.
- 미리 정한 관문 "의존 목록에 `cframe.h`·`gdb.h` 가 있음" 은 어긋났습니다. 의존 목록은 `libc.s`·`cframe.h` 뿐입니다.
  - 원인: 컴파일 줄의 `-imacros src/generated/meta_features.h` 가 먼저 `#import <gdb.h>` 를 하므로, `cframe.h:10` 의 `#import <gdb.h>` 는 다시 읽히지 않습니다. `-M` 은 `-imacros` 로 읽은 파일을 적지 않습니다(M5·M4 의 모든 컴파일이 같음).
  - 다른 근거: 스테이징 `generated/gdb.h` 는 m68k 생성 구성(`#define GDB 1`)입니다. NA 객체가 원본과 같다는 것은 `cframe.h` 의 `!GPROF && GDB` 갈래(`link a6,#0`)가 쓰였다는 뜻입니다.
  - 관문 문구를 제가 바꾸지 않고 사용자께 여쭙니다.

사용자 결정 D108(2026-10-24): m68k `libc.s` 는
- §511 의 관문 "의존 목록에 `cframe.h`·`gdb.h`" 를 "`cframe.h` 는 의존 목록, `gdb.h` 는 `-imacros` 경유(스테이징 `generated/gdb.h` 내용 `GDB 1`)" 로 바꾸어 받습니다("대신 근거로 받음 (Recommended)"). 이후 어셈블리 관문도 이 문구를 씁니다.
- 07 자리는 D103·D104 를 따릅니다("D103·D104 따름 (Recommended)"): `07_kernel/src/machdep/m68k/libc.s`(NeXTMach 글, include 한 줄만 `<m68k/cframe.h>`), `cframe.h` 는 NeXTMach 그대로 `07_kernel/nextmach/next/cframe.h` → 스테이징 `src/bsd/m68k/cframe.h`.
- m68k `.s` 컴파일 줄에 `-DASSEMBLER` 를 더합니다(바이트가 요구: 없으면 컴파일 실패; NeXTMach `conf/Makefile.template:118` `SFLAGS` 선례).

## 512. M4-18 D108 확인과 구현 계획 — 07 `src/machdep/m68k/libc.s` 와 `07_kernel/nextmach/next/cframe.h`(코딩 전, 2026-10-24)

확인한 사실(이번 세션):
- NA 객체 `08_build/runs/m4p511-p1/stage/Q511__libc_NA.o`(SHA-256 `3d5e8b4810e030e263d1f89e03c73339938574703004cb0378da02cae280879d`)가 §511 의 `candidate` 입니다.
- `stage_m68k.py:430` 은 `M4FILES` 에 `.c` 만 받습니다. `m4_m68k_probe.py` 의 사전형 변형은 `src` 에 `@<rel>`(스테이징 파일 그대로)과 `defs` 를 함께 받습니다(`vrel` 93–99 행).
- NeXTMach `libc.s` 는 1–8 행에 `Copyright (c) 1987 NeXT, INC` 고지 덩이가 있고, 15 행이 `#import <next/cframe.h>` 입니다. `cframe.h` 는 1 행 SCCS 줄 `(c) 1986 NeXT` 입니다.

방법:
1. 확인 run `m4p512-p1`(명세 `08_build/artifacts/m4p512/confirm/spec.json`, 바탕 `m0p510-a1-stage`, 줄 틀 `machdep/i386/start.s`, `m4_id` = §511 과 같은 명시 구간):
   - L = NeXTMach `libc.s` 에서 15 행만 `#import <m68k/cframe.h>` 로 바꾼 것. `inc` 는 NeXTMach `cframe.h` 를 `m68k/cframe.h` 자리에, `defs` 는 `-DASSEMBLER` 입니다.
   - 대조 NA(§511 그대로).
   - 관문: L 이 `candidate` 이고 NA 와 canon·머리·절·비 STABS 기호가 같음. REF = L 객체.
2. 07 파일 둘:
   - `07_kernel/nextmach/next/cframe.h` = NeXTMach 그대로
   - `07_kernel/src/machdep/m68k/libc.s` = L 에 고지 덩이 뒤 설명 주석 한 덩이와 15 행 끝 표시 주석(`/* plan 512 (D104): NeXTMach <next/cframe.h> */`)을 더한 것. 주석을 뺀 토큰이 L 과 같음(python).
3. `stage_m68k.py`:
   - `M4FILES` 가 `.s` 도 받게 합니다(`.c`·`.s` 만; `.s` 는 덮어쓰기 검사 대상이 아님 — 그 검사는 덮어쓰기 트리의 `.c` 에만 쓰임).
   - `M4FILES[512]` = 510 목록 + `libc.s`
   - `M4HEADERS[512]` = 510 목록 + (`next/cframe.h`, `src/bsd/m68k/cframe.h`)
   - `EXCEPTS[512]`, 문서 줄
   - 회귀: `--plan 510` 으로 다시 만든 매니페스트가 `m0p510-a1-stage` 와 같음
   - `--plan 512 stage m0p512-a1-stage` 와의 차이는 `libc.s`·`cframe.h` 둘
4. x86 입력 불변: `m4_x86_inputs.py s6ll`(`L2_FORMS`·`L2_EXPECT` 명시), `--plan 512 x86gate`.
5. 최종 run `m4p512-a1`(명세 `08_build/artifacts/m4p512/spec.json`, 바탕 `m0p512-a1-stage`, 변형 `F` = `{"src": "@machdep/m68k/libc.s", "inc": [], "defs": ["-DASSEMBLER"]}`, `refs` = L 객체).
   - `gate.ok`
   - python 확인: 정의 기호가 REF 와 같음, 입력 사슬(`libc.s`·`cframe.h`) 07 = 스테이징 = run 사본, 의존 목록의 `cframe.h` 가 `07_kernel/nextmach/next/cframe.h` 로 풀림, `gdb.h` 는 D108 문구, 옵션이 M5 줄 + `-DASSEMBLER` 와 같음
6. 상태표(근거 문서 먼저, `ACCEPTED` 추가, 두 번 돌린 출력 같음). 객체 바이트는 구간 1194 B 이고, 요약의 행 최소 바이트 합과 다를 수 있으니 둘을 나눠 적습니다.
7. 기록:
   - PROVENANCE 새 행 둘(`libc.s` nextmach, include 한 줄; `cframe.h` 그대로)
   - MODIFICATIONS, DECISIONS D108, diff `06_reconstruction/evidence/m68k-libc.diff`, 근거 문서 `m68k-libc.md`
   - M7 의무: m68k `.s` 컴파일 줄의 `-DASSEMBLER`
   - 상태 절과 결과 절

관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 512.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: §511.2 의 "`cframe.h:10` 의 `#import <gdb.h>`" 는 17 행입니다(grep).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| NA 해시·`stage_m68k.py:430` 의 `.c` 단언·사전형 `@`+`defs` 처리·고지 줄이 맞음 | 이번 세션 `vrel`·`cmd_stage` 읽음(`@` 는 복사 않고 존재만 확인, 빈 `inc` 는 `-I` 없음) | ✅ |
| 상태표 도구가 이 기록을 다룸(소스 경로, 사전형 `m4_id`, `run.cmd` 줄 찾기, L1 파일 이름) | `m4_m68k_status.py` 의 해당 줄(§506 에서 읽음)과 `span` 확장 | ✅ 실행으로 확인 |
| `.s` 를 `M4FILES` 에 받아도 안전; 덮어쓰기 트리가 `.s` 를 덮는 것은 막지 않으므로 출처·해시 사슬 확인을 유지 | `stage_m68k.py` 의 덮어쓰기 처리(§506 에서 읽음) | ✅ 입력 사슬 관문 유지 |
| NA 객체에는 STABS 가 0 개라 경로 차이로 obj_sig 가 달라질 근거가 없음 | 확인 run 에서 L·NA 를 비교해 봄 | ⏭️ 실행으로 확인 |
| 구성 고정: `GDB 1`, `GPROF`·`KERNEL_FEATURES` 정의 없음 | 생성 머리·컴파일 줄 grep 0, `generated/gdb.h` `GDB 1` | ✅ 기록에 적음 |
| 확인 run 의 `diag_gate` 를 따로 단언; 실제 변형 옵션을 확인; M7 의무(`-DASSEMBLER`, `.s` 등록) 기록; 함수별 줄 대응 | 설계 | ✅ |
| 받아들인 뒤 요약 예상: 10 객체, 27/188 행, 5888 B, 2.73% | 받아들인 뒤 python 으로 셈 | ⏭️ 실행으로 확인 |

### 512.2 결과(2026-10-24)

- 1(확인): run `m4p512-p1`(명세 `08_build/artifacts/m4p512/confirm/spec.json`, 스테이징 `m4p512-stage` 903 파일; 기록 `09_validation/reconstruction/m4-m68k-probe-p512-20261024.json`).
  - 4 명령 종료 0·경고 0·i386 머리 0(`diag_gate` 참), 옵션 = M5 줄 + `-DASSEMBLER`(+ 사전형 `-I`)
  - L·NA 모두 `candidate`. L 은 NA 와 canon·머리·절·비 STABS 기호·STABS 까지 같고 SHA-256 도 같음(`3d5e8b48…`; 이 객체에는 STABS 가 없음). NA 는 §511 의 NA 와 같음(재현)
  - REF = L 객체
- 2: `07_kernel/src/machdep/m68k/libc.s`(485 행, SHA-256 `8c88ea6e…`; 주석을 뺀 토큰 2579 개가 L 과 같음), `07_kernel/nextmach/next/cframe.h`(NeXTMach 와 같음, `cc4065a7…`). diff `06_reconstruction/evidence/m68k-libc.diff`(22 행).
- 3: `stage_m68k.py` 595 → 600 행(고치기 전 사본 `08_build/artifacts/m4p512/stage_m68k.py.before512`). `M4FILES` 가 `.s` 를 받습니다.
  - `--plan 510` 으로 다시 만든 매니페스트가 `m0p510-a1-stage` 와 같음
  - `--plan 512 stage m0p512-a1-stage`(901 파일)와의 차이는 `libc.s`·`cframe.h` 둘
- 4: x86 입력 불변(`m4-x86-inputs-p512-20261024.json` ok, `--plan 512 x86gate` 일곱 묶음 같음).
- 5: run `m4p512-a1`(명세 `08_build/artifacts/m4p512/spec.json`, 기록 `09_validation/reconstruction/m4-m68k-p512-final-20261024.json`). `gate` 모두 참이고, python 확인(`m4-m68k-p512-checks-20261024.json`, `ok` 참):
  - 객체 SHA-256 이 REF 와 같음(`3d5e8b48…`), 정의 기호 15 개 같음
  - 입력 사슬 둘 같음
  - 의존 목록 = `cframe.h`(`07_kernel/nextmach/next/cframe.h`) 하나, `gdb.h` 는 D108 문구대로(`meta_features.h` 가 `#import <gdb.h>`, 스테이징 `#define GDB 1`)
  - 옵션 = M5 줄 + `-DASSEMBLER`
- 6: 상태표 10 객체, §495 행 27/188, 행 최소 바이트 합 5888 B(2.73%; python; codex 예상과 같음). `libc` 객체 자체는 1194 B 이고, 그 행들의 최소 바이트 합은 794 B 입니다. `m4_m68k_status.py` 111 → 112 행, 앞 아홉 행 그대로, 두 번 돌린 출력 같음.
- 7: PROVENANCE 새 행 둘(1110 → 1112 행, 경로 중복 0), MODIFICATIONS 둘(656 → 658 행), DECISIONS D108(111 → 112 행), 근거 문서 `06_reconstruction/evidence/m68k-libc.md`.

## 513. M4-19 세부 계획 — 어셈블리 둘째 단위 `nextdev/monitor.s` 진단(07 변경 없음; 코딩 전, 2026-10-24)

배경: §512 로 어셈블리 경로가 섰습니다. 묶음 A 의 작은 단위 둘을 비교했습니다.
- `next/nextdbgasm.s`: 1997 년 꼴이 NeXTMach 와 다릅니다(`__m68k_dbginit`, 전역 포인터 `_dbgstack`, `sp` 저장). 구간 시작 0x4096700 이 경계가 정확하지 않은 미배정 행 306 의 중간이라 지금 도구 규칙으로 받을 수 없습니다. 뒤로 미룹니다.
- `nextdev/monitor.s`: 행 230([0x407247e, 0x40725e2), 356 B, 정확 경계, 대응률 7/7). 원본 앞부분이 NeXTMach 글과 같은 꼴입니다.

확인한 사실(이번 세션):
- 원본 함수 8 개: `_mon_reset`(38 B)·`_mon_send`(8)·`_lpr_send`(10)·이름 없는 148 B(0x40724b6, NeXTMach 의 지역 라벨 `1:` 뒤 송신 본문)·`_mon_csr_and`(8)·`_lpr_csr_and`(68)·`_mon_csr_or`(8)·`_lpr_csr_or`(68).
- 원본 `_mon_reset` 은 `link a6,#0; movel #0x200e000,a1; tstl 0x40b1bca; …; movel #0x200,a1@; …; unlk; rts` 입니다. NeXTMach 의 `P_MON`(`next/cpu.h` 의 `SLOT_ID+0x0200e000`, ASSEMBLER 에서 `SLOT_ID` = 0)·`RESET`(0x200)·`minit` 과 맞습니다.
- NeXTMach `monitor.s`(253 줄)는 `next/cframe.h`·`next/cpu.h`·`nextdev/monreg.h`·`next/spl.h` 를 들입니다. 쓰는 머리 이름은 `PROCENTRY`·`PROCEXIT`(`cframe.h`), `P_MON`·`P_PRINTER`(`cpu.h`), `RESET`(`monreg.h`), `splhigh`·`splx`(`spl.h`) 입니다(python, 주석을 뺀 토큰과 `#define` 이름의 교집합).
- `next/spl.h` 는 `ASSEMBLER` 갈래에 어셈블러용 `splx` 를 둡니다. `<iplmeas.h>`(m68k 생성 구성)를 들입니다.
- SDK `bsd/m68k/spl.h`(스테이징)는 `kernserv/m68k/spl.h` 로 이어지고, SDK `bsd/m68k/cpu.h` 에는 `P_` 주소가 없습니다(§505).
- `monitor.s` 는 자료 `minit`(`.data`, 4 B)을 정의합니다.

방법(`m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p513/spec.json`, run `m4p513-p1`, 바탕 `m0p512-a1-stage`, 줄 틀 `machdep/i386/start.s`, `m4_id` `m68k-230`, 두 변형 모두 `defs` `-DASSEMBLER`):
- N: NeXTMach `monitor.s` 그대로. `inc` 에 NeXTMach `next/cframe.h`·`next/cpu.h`·`nextdev/monreg.h`·`next/spl.h` 사본을 둡니다(`next/spl.h` 가 다시 부르는 `next/spl_measured.h` 는 `NIPLMEAS` 가 0 이면 쓰이지 않음).
- S: N 에서 `#import <next/spl.h>` 만 SDK `<m68k/spl.h>` 로 바꾼 것(SDK 머리를 어셈블리에 쓸 수 있는지 봄).
- 비교: `compare`(L1, `full_span`, 원본 이름, 자료 `minit`), `funcs`(맞지 않을 때).
- 기록 `09_validation/reconstruction/m4-m68k-probe-p513-20261024.json`.

판정(미리 정함; 07 은 바꾸지 않음):
- `candidate` 인 변형이 있으면, 바이트로 정해지지 않는 것(머리 공급: NeXTMach `next/cpu.h` 를 어디에 둘지(SDK `m68k/cpu.h` 와 이름이 겹침), 파일 안 매크로 꼴(D107 처럼), `spl.h` 출처)을 여쭙고 구현 계획을 씁니다.
- 컴파일 실패는 오류를 기록합니다.

관문(어긋나면 멈춤): 옵션이 M5 줄 + 사전형 `-I` + `-DASSEMBLER`, i386 머리 0, `cframe.h` 는 의존 목록·`gdb.h` 는 D108 문구, 명령 상태 기록.

### 513.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: "원본 앞부분이 NeXTMach 글과 같은 꼴" 은 `_mon_reset`·`_mon_send`·`_lpr_send` 만 보고 쓴 것이고, 구간 전체를 맞대지 않았습니다. 원본 목록 전체를 이번 세션에 다시 읽으니, NeXTMach 에 없는 가드가 세 곳 있습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본에 `cmpw #0x139,_dma_chip; bne` 가드 셋: 0x4072504(송신, → 데이터 쓰기 `2:`), 0x4072568(`csr_and`, → `9:`), 0x40725b4(`csr_or`, → `9:`); 각 10 B, 빼면 326 B 예상 | 원본 목록 0x40724b6–0x40725e2 를 NeXTMach 60–253 행과 나란히 읽음; 0x40c32d0 = `_dma_chip`(§505) | ✅ 제 오류 |
| 그 밖의 명령(`splhigh`·`splx` 펼침, `orw #0x700,sr`, 프레임, `subl #16`, 주소·`RESET`)은 같음 | 같은 읽기 | ✅ |
| NeXTMach `next/cpu.h` 는 ASSEMBLER·KERNEL 에서 `SLOT_ID 0x0`, C 선언 제외; `next/spl.h` 는 `NIPLMEAS 0` 으로 어셈블러 매크로 | `cpu.h:88–93`(§505 에서 읽음), 스테이징 `generated/iplmeas.h` `NIPLMEAS 0` | ✅ |
| SDK `kernserv/m68k/spl.h` 는 어셈블러 갈래를 `__ASSEMBLER__` 로 가름(`-DASSEMBLER` 와 다름); 드라이버가 정의하는지 미확인 | 스테이징 파일 34 행 grep | ✅ S 는 그 점의 시험으로 둠 |
| 자료: 0x40b1bca 는 `__DATA,__data` 의 0(이름 없음, `minit` 은 추정); L1 이 자료를 실제로 봤는지 기록으로 단언할 것 | 설계 | ✅ 관문으로 |
| 변형마다 의존 목록 출처·경고 0·`diag_gate`; `funcs` 는 숫자를 가리므로 가드 상수를 증명하지 못함 | 설계 | ✅ |

계획 수정(실행 전 고정; 변형 글은 `08_build/artifacts/m4p513/src/`):
- N: NeXTMach 그대로(예상: 가드가 없어 326 B 안팎, NOT_MATCH).
- G: N 에 가드 세 쌍을 넣은 것(D024). 송신은 110 행 `btst #7,a1@` 앞에 `cmpw #0x139,_dma_chip; bne 2f`, `csr_and`·`csr_or` 는 179·233 행 `btst #7,a0@` 앞에 `cmpw #0x139,_dma_chip; bne 9f`. 각 줄에 원본 주소를 단 표시 주석을 둡니다.
- S: G 에서 `#import <next/spl.h>` 만 SDK `<m68k/spl.h>` 로(드라이버가 `__ASSEMBLER__` 를 정의하는지 봄).
- 세 변형 모두 `defs` `-DASSEMBLER`, `inc` 에 NeXTMach `next/cframe.h`·`next/cpu.h`·`nextdev/monreg.h`(+ N·G 는 `next/spl.h`).
- 관문(python): 명령 상태·경고, 옵션, 의존 목록 출처(`cframe.h`·`cpu.h`·`monreg.h`·`spl.h` 가 어디서 풀렸는지), `gdb.h` 는 D108 문구, `candidate` 인 변형은 L1 기록에서 `__DATA,__data` 의 주소 0x40b1bca·크기 4·바이트 차이 0 을 확인.

### 513.2 결과(2026-10-24)

- run `m4p513-p1`(명세 `08_build/artifacts/m4p513/spec.json`, 스테이징 `m4p513-stage` 915 파일 = 바탕 901 + 14; 기록 `09_validation/reconstruction/m4-m68k-probe-p513-20261024.json`).
  - 6 명령 종료 0·경고 0, i386 머리 0
  - 옵션은 M5 줄 + 사전형 `-I` + `-DASSEMBLER`
  - 의존 목록: `cframe.h`·`cpu.h`·`monreg.h` 는 NeXTMach 사본, `iplmeas.h` 는 m68k 생성 구성, `spl.h` 는 N·G 가 NeXTMach, S 가 SDK(`bsd/m68k/spl.h` → `kernserv/m68k/spl.h`, `m68k/psl.h`). `gdb.h` 는 D108 문구대로입니다.

| 변형 | 텍스트(객체/원본) | L1 | 판정 |
|---|---|---|---|
| N(NeXTMach 그대로) | 326 / 356 B | NOT_MATCH | no(가드 셋이 없음, 예측 326 B 와 같음) |
| G(가드 셋) | 356 / 356 B | OBJECT_MATCH | candidate |
| S(G + SDK `spl.h`) | 356 / 356 B | OBJECT_MATCH | candidate, G 와 canon·obj_sig 같음 |

- G·S 의 L1 기록:
  - `__TEXT,__text` 는 0x407247e, 356 B, 바이트 차이 0, 참조 차이 0
  - `__DATA,__data` 는 0x40b1bca, 4 B, 바이트 차이 0(`minit`)
- G 객체의 가드 바이트(python): 세 곳 모두 `0c79 0139` + 재배치 자리 + `6620`/`661c`/`661c` 로, 원본과 같은 인코딩입니다. `_dma_chip` 은 외부 미정의입니다.
- S 가 같은 객체이므로, 드라이버가 `.s` 에 `__ASSEMBLER__` 를 정의하고 SDK `spl.h` 의 어셈블러 매크로가 NeXTMach 것과 같은 명령을 냅니다.
- `nextdev/monreg.h` 는 SDK 에 없습니다(파일 이름 검색 0). 구조체는 `#ifndef ASSEMBLER` 안에만 있습니다.
- 바이트로 정해지지 않는 것(사용자 결정): `P_MON`·`P_PRINTER` 공급(SDK `m68k/cpu.h` 에 없음; NeXTMach `next/cpu.h` 는 SDK 와 이름이 겹침), `spl.h` 출처(SDK 또는 NeXTMach).

사용자 결정 D109(2026-10-24): m68k `monitor.s` 는
- `P_MON`·`P_PRINTER` 를 NeXTMach `next/cpu.h` 에서 받습니다("NeXTMach cpu.h 따로 둠"; 제 추천은 파일 안 매크로였음). 사본 `07_kernel/nextmach/next/cpu.h` 를 SDK `m68k/cpu.h` 와 겹치지 않는 스테이징 자리 `src/bsd/next/cpu.h` 에 두고 `<next/cpu.h>` 그대로 들입니다. D104 의 `<m68k/…>` 규칙에서 벗어나는 예외입니다.
- `splhigh`·`splx` 는 SDK `<m68k/spl.h>` 입니다("SDK <m68k/spl.h> (Recommended)").
- 주의: NeXTMach `next/cpu.h` 는 C 에서 들이면 원본에 없는 `_disk_chip` 등을 임시 정의합니다. 그래서 어셈블리(`-DASSEMBLER`)에서만 들여야 합니다.

## 514. M4-20 D109 확인과 구현 계획 — 07 `src/machdep/m68k/monitor.s` 와 NeXTMach 머리 둘(코딩 전, 2026-10-24)

확인한 사실(이번 세션):
- 스테이징(`m0p512-a1-stage`)에는 `next/` 디렉터리가 없고, M5 `-I` 순서로 `next/cpu.h`·`dev/m68k/monreg.h` 가 풀리는 자리가 비어 있습니다(python).
- NeXTMach `next/cpu.h` 는 `defined(KERNEL) && !defined(KERNEL_FEATURES)` 에서 `<cpus.h>` 를 들입니다(m68k 생성 구성 `NCPUS 1`). C 선언은 `#ifndef ASSEMBLER` 안입니다.
- 07 의 `.c`·머리 가운데 `next/cpu.h` 를 적은 곳은 `next_table.c`·`mem.c` 의 표시 주석뿐이고, include 줄은 없습니다(grep).
- §513 의 G 는 `candidate` 입니다. REF 는 07 글과 같은 include 꼴로 확인 run 을 따로 돌려 정합니다(§510·§512 와 같음).

방법:
1. 확인 run `m4p514-p1`(명세 `08_build/artifacts/m4p514/confirm/spec.json`, 바탕 `m0p512-a1-stage`, 줄 틀 `machdep/i386/start.s`, `m4_id` `m68k-230`, `defs` `-DASSEMBLER`):
   - L = G 에서 include 넷을 07 꼴로: `<m68k/cframe.h>`(스테이징에 있음), `<next/cpu.h>`(그대로), `<dev/m68k/monreg.h>`, `<m68k/spl.h>`(SDK). `inc` 는 NeXTMach `next/cpu.h` 를 `next/cpu.h` 에, `nextdev/monreg.h` 를 `dev/m68k/monreg.h` 에 둡니다.
   - 대조 G(§513 그대로).
   - 관문: L 이 `candidate`, G 와 canon·obj_sig 같음, 의존 목록 출처(`cframe.h` 는 07 nextmach, `spl.h` 는 SDK).
2. 07 파일 셋:
   - `07_kernel/nextmach/next/cpu.h`·`07_kernel/nextmach/nextdev/monreg.h` = NeXTMach 그대로
   - `07_kernel/src/machdep/m68k/monitor.s` = L 에 설명 주석 한 덩이와 include·가드 줄 표시 주석(`/* … */`)을 더한 것
   - 주석을 뺀 토큰이 L 과 같음(python)
3. `stage_m68k.py`:
   - `M4FILES[514]` = 512 목록 + `monitor.s`
   - `M4HEADERS[514]` = 512 목록 + (`next/cpu.h`, `src/bsd/next/cpu.h`) + (`nextdev/monreg.h`, `src/bsd/dev/m68k/monreg.h`)
   - `EXCEPTS[514]`, 문서 줄
   - 회귀: `--plan 512` 으로 다시 만든 매니페스트가 `m0p512-a1-stage` 와 같음
   - `--plan 514 stage m0p514-a1-stage` 와의 차이는 셋
   - python 관문: 스테이징의 `.c` 어디에도 `#import`/`#include <next/cpu.h>` 줄이 없음(D109 주의)
4. x86 입력 불변(`m4_x86_inputs.py s6ll`, `L2_FORMS`·`L2_EXPECT` 명시; `--plan 514 x86gate`).
5. 최종 run `m4p514-a1`(명세 `08_build/artifacts/m4p514/spec.json`, 변형 `F` = `{"src": "@machdep/m68k/monitor.s", "inc": [], "defs": ["-DASSEMBLER"]}`, `refs` = L 객체).
   - `gate.ok`
   - python 확인: 정의 기호, 입력 사슬(소스·머리 둘), 의존 목록 출처, 옵션, L1 의 `__DATA,__data`(0x40b1bca, 4 B, 차이 0), 가드 바이트
6. 상태표(근거 문서 먼저)와 기록: PROVENANCE 새 행 셋, MODIFICATIONS, DECISIONS D109, diff `06_reconstruction/evidence/m68k-monitor.diff`, 근거 문서 `m68k-monitor.md`, M7 의무(`next/cpu.h` 는 어셈블리만), 상태 절과 결과 절.

관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 514.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `src/bsd/next/` 없음, `<next/cpu.h>` 는 스테이징 뒤 `-Isrc/src/bsd` 로만 풀림; `-DASSEMBLER -DKERNEL` 에서 `cpus.h` 만 들임 | 이번 세션 python(매니페스트·`-I` 순서), `cpu.h:17–40` grep | ✅ |
| 스테이징 `.c`·`.h` 어디에도 `<next/cpu.h>` include 가 없음 | 이번 세션 python(900 파일, 꺾쇠·따옴표, `next/cpu.h`·`next/scr.h`) | ✅ |
| `.c` 만 보는 관문은 부족(머리가 조건부로 들일 수 있음) → 주석을 뺀 `.c`·`.h`·`.s`, 꺾쇠·따옴표, 조건부 갈래까지 | 설계 | ✅ 관문을 넓힘 |
| 기존 M5·M4 C 객체마다 의존 목록을 다시 뽑아 이 머리가 없음을 확인 | 설계 | ⚖️ 정적 전수 검사로 이 머리에 닿는 include 가 0 임을 보이면 컴파일 재현 없이도 충분하다고 판단(기록) |
| x86 `stage_headers.py` 는 `next`·`nextdev` 를 고르지 않음 | `stage_headers.py:127–128,240–255`(§506.1) | ✅ x86 관문 유지 |
| L 의 정의와 REF = L 이 맞음(관문 통과 뒤) | 설계 | ✅ |
| 최종 관문에 비 STABS 기호 = REF, COMMON 없음, `_dma_chip` 미정의, `minit` 자료 확인; `cpu.h` 출처에 C 임시 정의 위험 명기; M7 의무(`-DASSEMBLER`, SDK 어셈블리 전처리, `_dma_chip`); 받아들인 뒤 예상 11 객체·28/188 행·6244 B·2.89% | 설계; 숫자는 받아들인 뒤 python 으로 셈 | ✅ |

### 514.2 결과(2026-10-24)

- 1(확인): run `m4p514-p1`(명세 `08_build/artifacts/m4p514/confirm/spec.json`, 스테이징 `m4p514-stage` 909 파일; 기록 `09_validation/reconstruction/m4-m68k-probe-p514-20261024.json`).
  - 4 명령 종료 0·경고 0·i386 머리 0
  - 의존 목록 출처: `cframe.h` 는 `07_kernel/nextmach`, `spl.h`·`psl.h` 는 SDK, `cpu.h`·`monreg.h` 는 NeXTMach 사본, `iplmeas.h` 는 m68k 생성 구성(`gdb.h` 는 D108 문구)
  - L 은 `candidate` 이고 G 와 canon·obj_sig 같음. G 는 §513 의 G 와 같음(재현)
  - REF = L 객체(`a679ddad…`)
- 2: 07 파일 셋.
  - `07_kernel/src/machdep/m68k/monitor.s`(267 행, SHA-256 `75ae2fa0…`; 주석을 뺀 토큰 1249 개가 L 과 같음, include 표시 넷, 가드 셋)
  - `07_kernel/nextmach/next/cpu.h`(`148c9611…`)·`07_kernel/nextmach/nextdev/monreg.h`(`269775bc…`), 둘 다 NeXTMach 와 같음
  - diff `06_reconstruction/evidence/m68k-monitor.diff`(52 행)
- 3: `stage_m68k.py` 600 → 605 행(고치기 전 사본 `08_build/artifacts/m4p514/stage_m68k.py.before514`).
  - `--plan 512` 으로 다시 만든 매니페스트가 `m0p512-a1-stage` 와 같음
  - `--plan 514 stage m0p514-a1-stage`(904 파일)와의 차이는 셋
  - 격리 관문: 스테이징의 `.c`·`.h`·`.s`·`.m` 가운데 주석을 뺀 글에서 `<next/cpu.h>`(꺾쇠·따옴표)를 들이는 파일은 `monitor.s` 하나
- 4: x86 입력 불변(`m4-x86-inputs-p514-20261024.json` ok, `--plan 514 x86gate` 일곱 묶음 같음).
- 5: run `m4p514-a1`(명세 `08_build/artifacts/m4p514/spec.json`, 기록 `09_validation/reconstruction/m4-m68k-p514-final-20261024.json`). `gate` 모두 참이고, python 확인(`m4-m68k-p514-checks-20261024.json`, `ok` 참):
  - 객체 SHA-256 이 REF 와 같음, 비 STABS 기호 같음, COMMON 없음, 미정의 `_dma_chip` 하나
  - 입력 사슬 셋 같음, 의존 목록 출처가 07 사본
  - L1 `__DATA,__data` 0x40b1bca·4 B·차이 0
  - 가드 바이트 셋이 원본과 같은 꼴
  - 옵션 = M5 줄 + `-DASSEMBLER`
- 6: 상태표 11 객체, §495 행 28/188, 행 최소 바이트 합 6244 B(2.89%; python; codex 예상과 같음; `m4_m68k_status.py` 112 → 113 행, 앞 열 행 그대로, 두 번 돌린 출력 같음).
  - PROVENANCE 새 행 셋(1112 → 1115 행, 경로 중복 0)
  - MODIFICATIONS 셋(658 → 661 행)
  - DECISIONS D109(112 → 113 행)
  - 근거 문서 `06_reconstruction/evidence/m68k-monitor.md`

## 515. M4-21 세부 계획 — `next/machargs.c` 진단(07 변경 없음; 코딩 전, 2026-10-26)

확인한 사실(이번 세션, python):
- §495 행 `m68k-292`(이름표 `x86-i386_init`, 1126 B)와 `m68k-293`(`next/machargs.c`, 172 B)은 둘 다 정확 경계이고 이어집니다. 구간은 [0x4093192, 0x40936a4), 1298 B 입니다. 앞 행 `m68k-291` 은 미배정, 뒤 행 `m68k-294` 는 `next/machdep.c` 입니다.
- 구간 안 함수(`06_reconstruction/m68k-functions.tsv`)는 `_getargs` 796, `_isargsep` 40, `_argstrcpy` 54, `_getval` 236, `_machparam` 172 B 입니다. NeXTMach mk-108.1 `next/machargs.c` 의 정의 순서(240·344·353·365·427 행)와 같습니다.
- 원본 `__cstring` 에 NeXTMach `getargs` 의 printf 문자열이 있습니다(`init arg: %s`, `kernel flag %s = 0x%x`, `kernel flag %s = `, `kernel flag %s unknown`; `strings.tsv`). x86 07 `i386_init.c` 의 같은 함수(§248)는 x86 판이라 printf 가 없습니다.
- 자료:
  - `_kernargs` 는 `__DATA,__data` 0x40b28ee, 660 B = 12 B × 55 항목입니다(다음 기호 `_nbuf` 까지).
  - 원본 바이트로 푼 항목(이름 문자열·`i_ptr` 기호·`c_ptr` 값)과 NeXTMach 표의 차이:
    - 빠짐: `phz`, `maxphys`, `rmtdebug`, `mi_rv_delay`·`mi_expire`·`mi_expire_sh`·`mi_expire_sh2`·`mi_expire_jmp`·`mi_expire_max`
    - 새로 생김: `nmfsbuf`(`nbuf` 뒤), `kdb_ipaddr`(`breakpoint` 뒤), `scc_buffer`·`sb`(둘 다 `_scc_buffer`, `od_dbug` 뒤)
    - 거짓인 조건부 항목: `DEBUG`·`XPR_DEBUG`·`EVENTMETER`·`FP_DEBUG`·`MACH_LDEBUG`·`SHOW_SPACE`·`MALLOCDEBUG`·`NIPLMEAS`
    - 참인 조건부 항목: `GDB`(`breakpoint`), `NOD`(`od_*`)
    - `dsp*` 일곱 항목은 `c_ptr` 0x2008000–0x2008007(`SLOT_ID_BMAP` 0 의 `P_DSP+n`)입니다.
  - `_debug` 는 `__common`(0x40c9498)에 있고, `_maxphys` 기호는 원본에 없습니다.
- 머리(바탕 스테이징 `m0p514-a1-stage`, M5 m68k 줄의 `-I`):
  - 있음: `next/cpu.h`(NeXTMach 사본, D109 로 어셈블리 전용), `generated/gdb.h`(m68k, `GDB 1`), `generated/iplmeas.h`(m68k, 0)
  - `generated/od.h` 는 x86 의 `07_kernel/generated/od.h`(`NOD 0`)입니다. 그러나 원본 표에는 `od_*` 가 있고, m68k 목록에 `nextdev/od.c`(`m68k-234`)가 있습니다.
  - 없음: `show_space.h`·`mach_ldebug.h`·`mallocdebug.h`, NeXTMach 에만 있는 `next/event_meter.h`(`sound.h` 는 `#if DEBUG` 안)

방법(진단; 명세 `08_build/artifacts/m4p515/spec.json`, run `m4p515-p1`, 바탕 `m0p514-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`(§496), `m4_id` = [`m68k-292`, `m68k-293`]):
- 변형 G: NeXTMach `machargs.c` 그대로입니다. `inc` 로 공급하는 것:
  - NeXTMach `next/event_meter.h` 사본
  - 진단용 대역 구성 머리 `show_space.h`(`SHOW_SPACE 0`), `mach_ldebug.h`(`MACH_LDEBUG 0`), `mallocdebug.h`(`MALLOCDEBUG 0`). 0 인 근거는 원본 표에 그 항목이 없다는 것이고, 07 에는 넣지 않습니다.
  - `od.h` 는 `-I` 순서상 `inc` 로 덮을 수 없어 `NOD 0` 그대로입니다.
- 변형 T: G 에서 `kernargs` 표와 그에 쓰이는 `extern` 선언만 원본 55 항목대로 고칩니다(위 차이). `maxphys` 변수와 항목은 지웁니다. `od_*` 는 진단을 위해 조건 없이 둡니다. 함수 본문은 고치지 않습니다.
- 측정:
  - `compare`: 명령 종료·경고·i386 머리, L1, `__text` 크기, 외부 기호, 원본에 없는 미정의 기호, G·T 객체 같음
  - 실기 `otool -tv` 로 `funcs`(함수별 명령 수, 숫자를 가린 같음)
  - python: 객체 `__data` 의 `kernargs` 를 재배치를 따라 풀어 원본 55 항목(이름 문자열, `i_ptr` 기호와 덧셈, `c_ptr`)과 비교하고, 정의·COMMON 기호를 원본과 견줍니다(`_debug` COMMON, `_maxphys` 없음)

판정(미리 정함; 진단이므로 07 은 바꾸지 않음): 변형마다 함수별 같음, 표 같음, 기호 차이를 적습니다. 사용자께 여쭐 것(결과에 따라):
- `NOD` 를 m68k 구성(`06_reconstruction/config_options-m68k.tsv` → `gen_config_headers.py`)으로 1 로 둘지, `od_*` 항목을 조건 없이 쓸지(바이트로 구분 안 됨)
- 없는 구성 머리 셋을 m68k 생성 머리(값 0)로 둘지, include 줄을 지울지
- C 에서 `next/cpu.h` 가 필요할 때 D109 와의 관계(`P_DSP` 를 D107 처럼 파일 안 매크로로 둘지 등)

### 515.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류:
- "12 B × 55 항목" 은 끝 표시(0,0,0)를 넣은 수입니다. 이름이 있는 항목은 54 개이고 끝 표시는 0x40b2b76 에서 시작합니다(python).
- `dsp*` 의 `c_ptr` 을 "0x2008000–0x2008007" 로 적어 빠진 4 를 가렸습니다. 실제 덧셈은 0·1·2·3·5·6·7 입니다.
- "조건이 거짓/참" 은 표의 항목 유무에서 미룬 추정입니다. NeXTMach 에서 `#if GDB` 는 `breakpoint`·`rmtdebug` 를 함께 담는데(`machargs.c:171–174`) 원본에는 `breakpoint` 만 있습니다. `#if NOD` 도 지워진 `mi_*` 를 담습니다. 원래 조건 구조가 그대로였다는 보장은 없습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| NeXTMach `next/event_meter.h` 는 `KERNEL` 이고 `KERNEL_FEATURES` 가 없으면 `<eventmeter.h>` 를 들이는데, 스테이징에 없음 | `event_meter.h:15–19` 읽음, 스테이징 `find` 0 건 | ✅ 대역 `eventmeter.h`(`EVENTMETER 0`) 추가 |
| C 에서 `next/cpu.h` 는 `master_cpu`·`dma_chip`·`disk_chip`·`machine_type`·`board_rev`·`cpu_type`·`intrmask`·`intr_mask`·`slot_id`·`slot_id_bmap` 을 임시 정의함(`_disk_chip` 은 원본에 없음) | `cpu.h:42–106` grep·읽음 | ✅ 깨끗한 변형 C 추가, 정의·COMMON 을 모두 기록 |
| `candidate`·L1 `OBJECT_MATCH` 는 COMMON 깨끗함을 보이지 않음(`full_span` 은 텍스트 크기·외부 텍스트 이름·미정의·배치만) | `m4_m68k_probe.py:328–341` 읽음 | ✅ |
| `od.h` 는 `meta_features.h` 가 `-imacros` 로도 들이므로 `inc` 로 못 덮음 | 스테이징 `meta_features.h:41` 읽음, `probe.py:202–204`(`inc` 는 마지막 `-I` 뒤) | ✅ |
| L1 은 `--place-from-image` 로 놓인 `__data` 의 바이트와 재배치 칸을 비교하고, `__cstring` 은 참조마다 내용으로 비교함(통째 배치는 보지 않음) | `l1_compare.py:133–140,300–330,460–475` 읽음 | ✅ L1 결과를 그대로 남기고, 표 순서 비교는 따로 python 으로 |
| 해독: `_kernargs` 는 4 로 나눈 나머지 2(올림 금지), 객체 재배치(일반·지역·흩어진)와 덧셈 유지, `_od_flgstr+4`, `scc_buffer`·`sb` 는 같은 기호의 다른 항목 | python(`0x40b28ee % 4 = 2`), 위 해독 출력 | ✅ |
| `refs` 가 없으면 `diag_gate` 실패가 종료 코드를 바꾸지 않음; `funcs` 는 16 진 숫자를 가려 상수·대상을 못 봄 | `probe.py:359–370` 읽음 | ✅ `diag_gate` 와 옵션을 따로 확인, `funcs` 는 진단용으로만 |
| `NOD 1` 과 조건 없는 항목, 값 0 대역 머리와 include 삭제를 각각 시험할 것 | 설계 | ⚖️ 이 둘은 전처리 뒤 같은 글이 되도록 짤 수 있어 바이트로 가려지지 않는다는 점을 기록하고 사용자 결정으로 넘김(별도 바탕 스테이징은 만들지 않음) |
| D103–D109 는 `02_plan/DECISIONS.md:107–113` | 읽음 | ✅ |

수정한 방법(앞 방법을 대신함):
- 변형 G: NeXTMach 원문 그대로. `inc` = NeXTMach `next/event_meter.h` 사본과 진단 대역 `eventmeter.h`(`EVENTMETER 0`), `show_space.h`(`SHOW_SPACE 0`), `mach_ldebug.h`(`MACH_LDEBUG 0`), `mallocdebug.h`(`MALLOCDEBUG 0`).
- 변형 T: G 에서 표와 그 `extern` 만 원본 54 항목대로 고칩니다. `maxphys` 변수·항목은 지우고, `od_*` 는 조건 없이 둡니다.
- 변형 C: T 에서 `#import <next/cpu.h>` 를 지웁니다. 대신 파일 안에 `P_DSP` 매크로(D107 꼴, NeXTMach `cpu.h:152` 의 식)와 `extern int slot_id_bmap;` 을 둡니다. C 에서 `next/cpu.h` 를 쓰지 않는 깨끗한 변형입니다.
- 모든 변형의 함수 본문 토큰은 NeXTMach 와 같아야 합니다(python 확인). 다르면 run 전에 멈춥니다.
- 표 비교 도구 `10_tools/reconstruction/m68k_kernargs.py`(읽기 전용):
  - 원본: `_kernargs` 에서 12 B 씩, 끝 표시까지 읽습니다.
  - 객체: `__data` 의 `_kernargs` 기호부터 재배치를 따라 이름 문자열 내용, `i_ptr` 기호와 덧셈, `c_ptr` 을 풉니다.
  - 순서대로 맞대어 같음과 차이를 냅니다.
- 기록: `compare`(`diag_gate`, 옵션, L1 의 `__data` 주소·크기·바이트 차이·참조 차이, 정의·COMMON 기호 전부), 실기 `otool -tv` 와 `funcs`, 표 비교.

### 515.2 결과(2026-10-26)

- run `m4p515-p1`(스테이징 `m4p515-stage` 922 파일, 6 명령 모두 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p515-20261026.json`). T·C 의 함수 본문 토큰은 NeXTMach 와 같습니다(1119 토큰, python).
- 세 변형 모두 `__text` 는 1238 B 로, 원본 구간 1298 B 보다 60 B 작습니다. L1 은 `NOT_MATCH`(`__TEXT,__text: unverified`)입니다.
- 정의 기호:
  - G·T: `next/cpu.h` 의 COMMON 10 개(`_disk_chip` 포함)가 생깁니다. G 는 `_maxphys` 도 정의하고, 원본에 없는 미정의 `_phz`·`_rmtdebug` 가 있습니다.
  - C: 함수 다섯, `_kernargs`, COMMON `_debug`(4 B)뿐입니다.
  - T·C 는 canon 이 같습니다(기호 표만 다름).
- 표(`m68k_kernargs.py`, 새 도구; 기록 `m4-m68k-kernargs-p515-{G,T,C}-20261026.json`):
  - T·C 의 `__data` 는 660 B 로 `_kernargs` 하나이고, 55 항목(끝 표시 포함) 모두 원본과 같습니다. 이름 내용, `i_ptr` 기호와 덧셈(`_od_flgstr+4` 포함), `c_ptr` 을 봤습니다.
  - G 는 36 항목이고 차이가 32 개입니다.
  - L1 도 T·C 의 `__data` 에 실패 사유가 없습니다.
- 함수별(실기 `otool -tv`, `08_build/artifacts/m4p515/otool/`; 기록 `m4-m68k-funcs-p515-20261026.json`):
  - `isargsep`·`argstrcpy`·`getval`·`machparam` 은 숫자를 가린 명령 열이 원본과 같습니다.
  - `getargs` 만 다릅니다(원본 250, 객체 235 명령). 원본을 문자열·기호와 함께 풀어 보면, 이름 비교가 맞은 뒤 `*cp = c;` 다음에 다음이 있습니다(0x409332e–0x4093356, 0x40932a6–0x40932b8).
    - `while (isargsep(*cp)) cp++;`
    - `if (*cp == '=' && c != '=') { printf("no spaces surrounding '=' allowed\n"); args = cp+1; goto gotit; }`
    - x86 1997 판(07 `i386_init.c:419–424`, 바이트 검증; §517.3 에서 줄 번호 정정)에도 printf 만 빠진 같은 덩이가 있습니다.
  - 나머지 차이는 `args` 레지스터 배정(a5 대 d2)과 그에 따른 이동입니다.
  - `switch` 표(19 칸, `'a'`–`'s'`)는 경우→대상 묶음이 같습니다. 원본은 절대 주소, 객체는 객체 주소를 담고, 대상이 모두 6 B 차이입니다(python).

## 516. M4-22 세부 계획 — `getargs` 의 1997 덩이를 넣은 변형 D 진단(07 변경 없음; 코딩 전, 2026-10-26)

근거: §515.2 의 원본 `getargs` 풀이(0x409332e–0x4093356, 0x40932a6–0x40932b8)와 x86 1997 판 `07_kernel/src/machdep/i386/i386_init.c:419–424`(§517.3 에서 줄 번호 정정).

방법:
- 변형 D = §515 의 C 에 한 덩이만 더합니다. 자리는 `getargs` 의 `*cp = c;` 바로 뒤, `if (interactive && *cp == '=' &&` 앞입니다. 글은 x86 1997 판의 줄에 m68k 원본 문자열의 printf 한 줄을 더한 것입니다.
  ```c
  				while (isargsep (*cp))
  					cp++;
  				if (*cp == '=' && c != '=') {
  					printf("no spaces surrounding '=' allowed\n");
  					args = cp+1;
  					goto gotit;
  				}
  ```
- python 확인: D 와 C 의 차이는 이 7 줄 삽입뿐이고, 다른 토큰은 같아야 합니다.
- run `m4p516-p1`(명세 `08_build/artifacts/m4p516/spec.json`, 바탕 `m0p514-a1-stage`, `inc` 는 §515 와 같음, `m4_id` [`m68k-292`, `m68k-293`]). 변형은 D 와 대조용 C(§515 재현)입니다.
- 측정: `compare`(`diag_gate`, 옵션, `__text` 크기, L1, `full_span`, 정의·COMMON), `m68k_kernargs.py`, 맞지 않으면 실기 `otool -tv` 와 `funcs`.

판정(미리 정함): D 가 `candidate`(`full_span`, L1 `OBJECT_MATCH`)이고, 표가 같고, 정의 기호가 원본 기호표에 있으며 COMMON 이 `_debug` 뿐이면, 07 구현 계획(§517)으로 갑니다. 그 전에 바이트로 정해지지 않는 꼴을 사용자께 여쭙니다(`NOD`, 없는 구성 머리, `next/cpu.h` 대신 파일 안 `P_DSP`, 새 `extern` 의 형, printf 덩이의 글 꼴). 아니면 차이를 기록하고 멈춥니다.

### 516.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: §515 에서 만든 `m68k_kernargs.py` 에 거짓 "같음" 을 낼 수 있는 결함이 셋 있었습니다(아래 1–3). §515.2 의 T·C 결과는 고친 도구로 다시 돌려도 같습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1. 일반 지역 재배치의 `r_symbolnum`(섹션 번호)을 보지 않고 저장 값으로 섹션을 고름 | `m68k_kernargs.py:113`(고치기 전) 읽음. C 객체 사본의 첫 이름 재배치 섹션을 `__cstring`(3)에서 `__data`(2)로 바꾸면, 고친 도구는 "target outside its section" 으로 멈춤 | ✅ 고침 |
| 2. 흩어진 재배치가 문자열을 가리킬 때 덧셈(저장 값 − `r_value`)을 버림 | `:109–110` 읽음. 흩어진 VANILLA 로 바꾸고 저장 값 +1 인 사본은 이름이 `''` 로 풀려 차이로 잡힘 | ✅ 고침(실효 대상 = 저장 값, `r_value` 의 섹션 안이어야 함) |
| 3. 재배치 형을 보지 않음 | `:107` 읽음. 형을 PB_LA_PTR(3)로 바꾼 사본은 "unsupported relocation" 으로 멈춤 | ✅ VANILLA·4 B·PC 상대 아님만 받음 |
| 5. 표·문자열 읽기에 섹션 경계가 없고, 끝 표시가 없으면 깔끔히 멈추지 않음 | 코드 읽음 | ✅ 경계 검사와 표 크기(`extent`)·원본의 다음 기호까지 거리를 기록 |
| 6. 바깥 덧셈을 부호 없이 다룸; 기록에 해석 입력(`macho.json`·`symbols.tsv`·`macho_obj.py`) 해시가 없음 | 코드 읽음 | ✅ 부호 있게, 입력 해시 기록 |
| 4. §516 판정에 `diag_gate`·옵션, C 재현(재배치·COMMON 포함), 정의 집합과 `_debug` 크기, 표 크기를 필수로 | `m4_m68k_probe.py:328–341,359–377` 읽음(`candidate` 는 명령 결과·COMMON 크기와 무관) | ✅ 판정에 넣음 |
| 삽입 자리(`*cp = c;` 뒤, interactive 시험 앞)와 문자열이 맞음; 그 밖의 동작 차이 없음 | 이번 세션 원본 목록 0x40932f2–0x4093356·0x40932a6–0x40932b8 읽음, 원본 바이트로 문자열 34 B(끝 LF) 확인, `__cstring` 순서(`init arg` 0xac35e → 이 문자열 0xac36c → `kernel flag` 0xac38f)가 소스 순서와 맞음 | ✅ |

고친 도구 재실행(T·C): 55 항목 같음, 표 크기 660 = 객체 `__data` 660 = 원본 `_kernargs`→`_nbuf` 660 B, 재배치 종류는 일반 지역·바깥 VANILLA 뿐입니다.

수정한 판정(앞 판정을 대신함). 다음을 모두 만족하면 사용자 결정으로 넘어가고, 아니면 차이를 기록하고 멈춥니다.
- `diag_gate` 참, 옵션 = M5 줄.
- C 재현: 객체 SHA-256 이 §515 의 C(`cd69b33b…`)와 같음.
- D 가 `candidate`(`full_span`, L1 `OBJECT_MATCH`).
- D 의 정의 집합 = 함수 다섯 + `_kernargs` + COMMON `_debug` 4 B 이고, 모두 원본 기호표에 있음.
- `m68k_kernargs.py` 로 표 같음, 표 크기 660 = `__data` 크기.

### 516.2 결과(2026-10-26)

- run `m4p516-p1`(스테이징 `m4p516-stage` 916 파일, 4 명령 모두 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p516-20261026.json`).
- C 재현: 객체 SHA-256 `cd69b33b…` = §515 의 C.
- D(`08_build/artifacts/m4p516/src/machargs_D.c`, C 에 7 줄만 더함):
  - `candidate`: `full_span` 참, L1 `OBJECT_MATCH`(사유 없음), `__text` 1298 B 가 0x4093192 에 놓임, `__data` 660 B 가 0x40b28ee(`_kernargs`)에 놓임, `__cstring` 567 B 는 참조마다 내용 같음
  - 객체 SHA-256 `447498bb…`
  - 정의는 함수 다섯 + `_kernargs` + COMMON `_debug` 4 B 로 예상과 같고, 모두 원본 기호표에 있음(`_debug` 는 섹션 6 `__common`)
  - 원본에 없는 미정의 0
  - 표(`m68k_kernargs.py`, 고친 판; `m4-m68k-kernargs-p516-{C,D}-20261026.json`): 55 항목 같음, 크기 660 = `__data` 660
- 판정: §516.1 의 조건을 모두 만족합니다. 07 구현 전에 바이트로 정해지지 않는 꼴을 사용자께 여쭙니다.
- M7 에 넘길 것(원본 기호, python):
  - `_kdb_ipaddr` 는 `__common` 4 B 로 `_debug` 바로 뒤에 있습니다. 어느 객체가 정의하는지는 객체 바이트로 정해지지 않습니다.
  - `_scc_buffer` 는 `__data` 0x40b23be, 다음 기호까지 112 B 이고 정의 객체는 모릅니다.
  - `_nbuf`·`_nmfsbuf` 는 `_kernargs` 바로 뒤의 `__data` 입니다(다음 객체 `next/machdep.c` 쪽으로 보임).

### 516.3 사용자 결정(2026-10-26)과 SDK `m68k/cpu.h` 시험 계획(코딩 전)

사용자 결정(AskUserQuestion, D110 으로 적을 예정):
- `NOD`: m68k 구성에 `NOD 1` 을 둡니다(`06_reconstruction/config_options-m68k.tsv` → `gen_config_headers.py`). `machargs.c` 의 `#if NOD` 구조는 NeXTMach 그대로입니다.
- 없는 구성 머리: m68k 생성 머리 값 0 으로 둡니다(`SHOW_SPACE`·`MACH_LDEBUG`·`MALLOCDEBUG`·`EVENTMETER`). NeXTMach `next/event_meter.h` 는 D104 대로 `07_kernel/nextmach/` 에 둡니다. include 줄은 NeXTMach 그대로입니다.
- 새 `extern`: `nmfsbuf`·`kdb_ipaddr`·`scc_buffer` 모두 `extern int` 로 쓰고 표시 주석을 답니다(`scc_buffer` 의 실제 형은 모름, M7 의무).
- `next/cpu.h`: SDK `m68k/cpu.h` 를 시험한 뒤 정합니다.

확인한 사실(이번 세션):
- 스테이징 SDK `src/bsd/m68k/cpu.h`(실기 `/NextDeveloper/Headers/bsd/m68k/cpu.h`, 78 줄)는 `dma_chip`·`cpu_rev`·`cpu_clk`·`machine_type`·`board_rev`·`cpu_type`·`mon_rev` 의 `extern` 선언과 `MC68030/MC68040`·`cpu_number()` 만 있습니다.
- `P_DSP`·`slot_id_bmap` 은 없습니다. 로컬 SDK 사본(707 파일, 위 `cpu.h` 와 바이트 같음) 전체 grep 에서도 `P_DSP`·`slot_id_bmap`·`SLOT_ID_BMAP`·`0x02008000` 은 0 건입니다. 따라서 SDK 머리를 들여도 이 둘은 파일 안에 있어야 합니다.

시험(run `m4p516-p2`, 바탕·`inc`·`m4_id` 는 §516 과 같음):
- 변형 E = D 에서 `extern int slot_id_bmap;` 앞에 `#import <m68k/cpu.h>` 한 줄을 더한 것(NeXTMach `next/cpu.h` 자리)
- 대조로 D 를 다시 돌림(SHA-256 `447498bb…` 재현)
- 판정: E 가 D 와 canon·obj_sig 가 같고 정의 집합이 같으면 "SDK 머리는 바이트에 영향 없음, 파일 안 매크로는 어느 쪽이든 필요" 로 적고, 둘 중 어느 꼴로 할지 사용자께 다시 여쭙니다. 다르면 차이를 기록합니다.

#### 516.3 교차검토와 결과

- codex 판정:
  - ✅ D 는 이미 `sys/user.h:345` 의 `#import <machine/cpu.h>` 로 SDK `m68k/cpu.h` 를 들입니다(D 의 의존 목록 `m4p516-p1/stage/_log/03.out:20`, 이번 세션 읽음). E 는 같은 머리를 한 번 더 들이는 시험입니다.
  - ✅ `cpus.h` 는 `generated/cpus.h` 로 풀리고 충돌이 없습니다.
  - ❌ "SDK 사본 708 파일" 은 틀렸습니다. python 으로 일반 파일 707, 심볼릭 링크를 포함한 이름 709 입니다.
- run `m4p516-p2`(4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p516-p2-20261026.json`):
  - D 재현 `447498bb…`
  - E(`08_build/artifacts/m4p516/src/machargs_E.c`)는 `OBJECT_MATCH`·`candidate` 이고, D 와 canon·obj_sig 가 같습니다. 객체 SHA-256 `eb578b00…` 이 D 와 다른 것은 줄 하나가 늘어 생긴 차이로 보입니다(canon 에서 제외되는 부분).
  - 정의 집합이 같고, 두 변형의 의존 목록에 든 cpu 머리(`bsd/m68k/cpu.h`·`bsd/machine/cpu.h`)도 같습니다.
- 결론: SDK `m68k/cpu.h` 를 명시해도 바이트는 같습니다. `P_DSP`·`slot_id_bmap` 은 어느 쪽이든 파일 안에 둬야 합니다.

## 517. M4-23 D110 구현 계획 — 07 `src/machdep/m68k/machargs.c`, m68k 구성 머리 다섯, NeXTMach `next/event_meter.h`(코딩 전, 2026-10-26)

사용자 결정(D110, §516.3 과 그 뒤 질문): `NOD 1`(m68k 구성), 없는 구성 머리는 m68k 생성 머리 값 0, 새 `extern` 은 `extern int` 와 표시 주석, NeXTMach `#import <next/cpu.h>` 는 `#import <m68k/cpu.h>`(SDK) 로 바꾸고 그 뒤에 `extern int slot_id_bmap;` 과 `P_DSP` 매크로를 둠(변형 E 꼴).

확인한 사실(이번 세션):
- m68k 생성 머리는 `07_kernel/v183.34/m68k/generated/` 에 있고, `stage_m68k.py` 의 덮어쓰기(`OVL`)로 모든 계획의 m68k 스테이징에 들어갑니다(계획 번호로 가르지 않음). 지금 그곳의 `od.h` 는 없어서 x86 `07_kernel/generated/od.h`(`NOD 0`)가 쓰입니다.
- `meta_features.h`(x86 것, `-imacros`)가 `od.h` 를 들이므로 `NOD` 는 모든 m68k 컴파일에 보입니다. 그러나 스테이징 전체(`m0p514-a1-stage`)에서 `NOD` 를 쓰는 곳은 `generated/od.h` 하나입니다(grep).
- `SHOW_SPACE`(`vm_resident.c`)·`MACH_LDEBUG`(`kern/lock.h`)를 쓰는 곳은 있지만, `show_space.h`·`mach_ldebug.h`·`mallocdebug.h`·`eventmeter.h`·`event_meter.h` 를 들이는 파일은 스테이징에 없습니다(grep). 새 머리는 `machargs.c` 만 들입니다.
- NeXTMach `next/event_meter.h`(116 줄)의 변수 정의(`em`, `em_chirp`)는 `#if EVENTMETER` 안에 있어, 값 0 에서는 정의가 생기지 않습니다(읽음).

방법:
1. 구성: `06_reconstruction/config_options-m68k.tsv` 에 다섯 행을 덧붙입니다(6 → 11 행).
   - `od NOD od.h 1`: 근거는 §515–516 의 원본 `kernargs` `od_*` 항목 21 개, m68k 목록의 `nextdev/od.c`(`m68k-234`), D110
   - `show_space SHOW_SPACE show_space.h 0`, `mach_ldebug MACH_LDEBUG mach_ldebug.h 0`, `mallocdebug MALLOCDEBUG mallocdebug.h 0`, `eventmeter EVENTMETER eventmeter.h 0`: 근거는 원본 표에 그 조건의 항목이 없음(바이트로는 구분 안 됨), D110
   - 상태는 모두 `hypothesis` 이고, 6 의 결과 뒤 근거 칸에 run 을 적습니다(값은 그대로).
   - `gen_config_headers.py --arch m68k` 로 쓰고 `--check` 를 확인합니다. 기존 m68k 머리 다섯은 바뀌지 않아야 합니다.
2. `07_kernel/nextmach/next/event_meter.h` = NeXTMach 그대로(바이트 같음).
3. `07_kernel/src/machdep/m68k/machargs.c` = NeXTMach `next/machargs.c` 에 다음만 바꾼 글입니다. 바꾼 줄마다 표시 주석 `/* plan 517 (D110): … */` 를 답니다. 주석을 뺀 토큰은 5 의 확인 변형 L 과 같아야 합니다(python).
   - `#import <next/cpu.h>` → `#import <m68k/cpu.h>`, 그 뒤 `extern int slot_id_bmap;` 과 `#define P_DSP (SLOT_ID_BMAP+0x02008000)`
   - `extern` 목록에 `nmfsbuf`, `#if GDB` 안에 `extern int kdb_ipaddr;`, `#endif NOD` 뒤에 `extern int scc_buffer;`(실제 형 모름 주석)
   - `int maxphys = 8192;` 와 항목 `phz`·`maxphys`·`rmtdebug`·`mi_*` 6 개를 지움
   - 항목 `nmfsbuf`(`nbuf` 뒤), `kdb_ipaddr`(`breakpoint` 뒤, `#if GDB` 안), `scc_buffer`·`sb`(`#endif NOD` 뒤, 조건 없음)를 더함
   - `#if NOD` 구조는 그대로 둡니다(D110)
   - `getargs` 의 7 줄(§516)
4. `stage_m68k.py`: `M4FILES[517]` = 514 목록 + `machargs.c`, `M4HEADERS[517]` = 514 목록 + (`next/event_meter.h`, `src/bsd/next/event_meter.h`), `EXCEPTS[517]` = `EXCEPTS[514]`, 문서 줄.
   - 회귀: `--plan 514` 로 다시 만든 매니페스트와 `m0p514-a1-stage` 의 차이가 생성 머리 다섯(`od.h` 바뀜, 넷 더함)뿐이어야 합니다.
   - `--plan 517 stage m0p517-a1-stage` 와 `--plan 514` 재생성의 차이는 `machargs.c`·`event_meter.h` 둘입니다.
5. 확인 run `m4p517-p1`(명세 `08_build/artifacts/m4p517/confirm/spec.json`, 바탕 `m0p517-a1-stage`, `inc` 없음, `m4_id` [`m68k-292`, `m68k-293`]): 변형 F = `@machdep/m68k/machargs.c`.
   - 관문: `diag_gate`, 옵션 = M5 줄, `candidate`, 정의 집합 = 함수 다섯 + `_kernargs` + COMMON `_debug` 4 B, `m68k_kernargs.py` 같음(크기 660)
   - 의존 목록에 `generated/od.h`(07 m68k 생성, `NOD 1`)와 새 머리 넷, `next/event_meter.h`(07 nextmach)가 들어 있는지 봅니다.
   - E(§516.3)와 canon·obj_sig 같음
6. M5 회귀(새 생성 머리 때문): `stage_m68k.py --plan 517 cmd` 의 205 줄을 run `m3p517-cc1` 로 컴파일하고 `compare` 합니다. 모든 객체가 기준과 같아야 합니다(예외는 `EXCEPTS[514]` 그대로).
7. x86 입력 불변: `m4_x86_inputs.py s6ll`(`L2_FORMS`·`L2_EXPECT` 명시), `--plan 517 x86gate`.
8. 최종 run `m4p517-a1`(명세 `08_build/artifacts/m4p517/spec.json`, `refs` = 5 의 객체): `gate.ok`, python 확인(5 의 관문 + 입력 사슬 07 = 스테이징 = run 사본).
9. 상태표(근거 문서 먼저)와 기록:
   - `m4_m68k_status.py` 의 `ACCEPTED` 에 p517 을 더함(예상 12 객체, 행 30/188, 바이트는 python 으로 셈)
   - PROVENANCE 새 행(`machargs.c`, `event_meter.h`, 생성 머리 다섯)
   - MODIFICATIONS, DECISIONS D110
   - diff `06_reconstruction/evidence/m68k-machargs.diff`, 근거 문서 `m68k-machargs.md`
   - M7 의무: `_kdb_ipaddr`·`_scc_buffer` 정의 객체, `scc_buffer` 의 형, `_nbuf`·`_nmfsbuf` 는 다음 객체

관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 차이가 예상과 같음, M5 205 객체 같음, x86 입력 불변.

### 517.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류:
- 1 의 근거 "원본 `od_*` 항목 21 개" 는 틀렸습니다. python 으로 18 개(`od_frmr` … `od_dbug`)입니다.
- 3 이 "5 의 L" 을 가리키는데 5 에는 F 만 있었습니다.
- 5 의 "의존 목록에 `generated/od.h`" 관문은 성립하지 않습니다. `od.h` 는 `meta_features.h` 를 거쳐 `-imacros` 로 먼저 들어오므로 `-M` 에 나오지 않습니다. E 의 의존 목록(`m4p516-p2/stage/_log/03.out`)에서 `od.h` 는 0 건입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `od.h` 는 `-imacros` 경유라 `-M` 에 안 나옴 → D108 처럼 명령의 `-imacros`, `meta_features.h` 의 import, 스테이징·run 사본의 `od.h` 해시·내용으로 확인 | 위 grep 0 건 | ✅ |
| `stage_m68k.py compare` 는 예외 객체의 차이를 제한하지 않고, 결과를 단언하지 않음; canon 은 기호표 전체를 보지 않음 | `stage_m68k.py:540–585` 읽음 | ✅ 보존된 `m0p514-a1-stage` 로 같은 205 줄 기준 run 을 만들어 객체마다 비교 |
| 기존 소스에 `NOD` 를 쓰는 곳이 없으므로 M5 회귀는 `NOD 1` 이 보임을 보이지 못함 → 입력 사슬과 `machargs` 표(조건 `#if NOD` 안)가 그 근거 | 스테이징 grep(§517 확인한 사실) | ✅ |
| L 을 E 에서 `#if NOD` 줄만 되살린 글로 정의; 주석을 뺀 07 = L, 전처리 토큰(07, `NOD 1`) = E; 실제 `-traditional-cpp` 명령으로 확인 | 설계; `scc_buffer` 의 `extern`·항목 자리는 `#endif NOD` 뒤(E 의 순서 유지) | ✅ |
| `phz`·`rmtdebug`·`mi_*` 의 `extern` 은 E 대로 남기고 표 항목만 지움 | E 소스 읽음 | ✅ |
| 최종 관문에 새 입력 전부(생성 머리 포함)의 07 → 스테이징 → run 사본 해시, D109 격리 검사(`next/cpu.h` 를 들이는 파일은 `monitor.s` 뿐)를 다시 | §514 관문 | ✅ |
| 기록: 상류 커밋·함수 줄, `P_DSP` 의 `next/cpu.h:152` 출처, 고친 곳의 원본 주소(D024), 확인 기록 이름·해시, 상태표 앞 행 불변·출력 재현 | `DECISIONS.md:28`, §514.2 | ✅ |
| 생성기·스테이징 가정(머리별 묶음, `undetermined` 건너뜀, `--plan 514` 파일 차이는 생성 머리 다섯, `machargs.c` 는 스테이징 전에 등록해야 함) | `gen_config_headers.py:30–50` 읽음, `stage_m68k.py:425,437,449` 읽음 | ✅ `M4FILES` 등록을 07 파일보다 먼저(같은 단계에서) |

수정한 방법(앞 계획의 해당 단계를 대신함):
- 1: `od` 행의 근거는 "원본 `kernargs` 의 `od_*` 18 개(§515)" 입니다.
- 3: L = `08_build/artifacts/m4p516/src/machargs_E.c` 에서 `#if NOD`/`#endif NOD` 네 줄을 되살린 글(`08_build/artifacts/m4p517/src/machargs_L.c`).
  - `scc_buffer` 의 `extern` 은 `extern` 쪽 `#endif NOD` 뒤에 둡니다.
  - 항목 `scc_buffer`·`sb` 는 표의 `#endif NOD` 뒤, `#if MALLOCDEBUG` 앞에 둡니다.
  - 07 = L + 표시 주석(줄 끝 `/* … */` 또는 따로 선 줄; 지시문을 걸치지 않음)입니다.
  - 확인: 주석을 뺀 토큰 07 = L(python), 실기에서 실제 컴파일 줄에 `-E` 를 둔 전처리 출력으로 L·07 이 같음(`NOD 1` 스테이징).
- 4: `M4FILES[517]` 등록과 `machargs.c` 추가를 같은 단계에서 합니다. 그 뒤에 어느 계획이든 스테이징합니다.
- 5(확인 run `m4p517-p1`): 변형 F 와 대조 L(같은 스테이징)이 canon·obj_sig 같아야 합니다.
  - `od.h` 는 명령의 `-imacros src/generated/meta_features.h`, 스테이징 `meta_features.h:41` 의 `#import <od.h>`, 스테이징·run 사본 `generated/od.h` 의 해시·내용 `#define NOD 1` 로 확인합니다.
  - `-M` 에는 새 머리 넷과 `next/event_meter.h` 가 있어야 합니다.
  - F 는 E 와 canon·obj_sig 가 같아야 합니다.
- 6(M5 회귀): run `m3p517-b514`(보존된 `m0p514-a1-stage`, `--plan 514 cmd` 의 205 줄)와 run `m3p517-cc1`(`m0p517-a1-stage`, `--plan 517 cmd`)을 만듭니다.
  - 객체마다 canon 과 비 STABS 기호(이름·종류·섹션·값, COMMON 크기)가 같아야 합니다(python).
  - `stage_m68k.py compare` 보고에서 `differ_unexpected`·`lost` 가 비어 있어야 합니다(단언).
- 8: 최종 관문에 생성 머리 다섯·`event_meter.h`·`machargs.c` 의 07 → 스테이징 → run 사본 해시와 D109 격리 검사(주석을 뺀 `.c`·`.h`·`.s`·`.m` 에서 `<next/cpu.h>` 를 들이는 파일은 `monitor.s` 뿐)를 더합니다.

### 517.2 진행 결과(2026-10-26, 6 단계 관문에서 멈춤)

- 1: `config_options-m68k.tsv` 6 → 11 행(고치기 전 사본은 scratchpad).
  - 원본 기호표 확인(python): `_em`·`_em_chirp`·`_mallocdebug`·`_mach_ldebug` 는 없습니다. `_show_space` 는 있습니다(`__common` 0x40b6024). 이 정의는 07 `bsd/kern/init_main.c:175` 의 조건 없는 `int show_space;` 이고, `vm_resident.c`(`m68k-202`, M5 코드 검증)는 `#if SHOW_SPACE` 가 꺼진 채 맞습니다. 이 사실을 `show_space` 행 근거에 적었습니다.
  - `gen_config_headers.py --arch m68k` 로 새 머리 다섯(`od.h` `NOD 1`, 나머지 넷 0)을 만들었습니다. `--check` 통과, 기존 다섯은 그대로입니다(`git status` 는 새 파일 다섯뿐).
- 2: `07_kernel/nextmach/next/event_meter.h` = NeXTMach(`cmp` 같음).
- 3: `08_build/artifacts/m4p517/src/machargs_L.c` 와 07 `src/machdep/m68k/machargs.c`(484 행, SHA-256 `d5214107…`).
  - L 은 E 에 `#if NOD`/`#endif NOD` 네 줄만 더한 글입니다.
  - 07 은 주석을 뺀 토큰 2361 개와 지시문 줄이 L 과 같습니다.
  - 실기 `-E`(run `m4p517-e2`; `m4p517-e1` 은 EXPECT 줄이 없어 prepare 가 거부해 등록되지 않음)에서 07·L 의 전처리 토큰 4085 개가 같습니다. 표에 `"od_frmr"` 가 있고 `maxphys`·`rmtdebug`·`"phz"` 는 없습니다.
- 4: `stage_m68k.py` 605 → 612 행(고치기 전 사본 `08_build/artifacts/m4p517/stage_m68k.py.before517`).
  - `--plan 514` 재생성(`08_build/artifacts/m4p517/re514-stage`)과 `m0p514-a1-stage` 의 파일 차이는 생성 머리 다섯(`od.h` 바뀜, 넷 더함)입니다.
  - `--plan 517 stage m0p517-a1-stage`(910 파일)와의 차이는 `machargs.c`·`event_meter.h` 둘입니다.
- 5: run `m4p517-p1`(4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p517-20261026.json`).
  - F(07)·L 모두 `OBJECT_MATCH`·`candidate` 이고, 서로 그리고 E(§516.3)와 canon·obj_sig 가 같습니다.
  - 정의는 함수 다섯 + `_kernargs` + COMMON `_debug` 4 B 입니다.
  - 표 55 항목 같음, 크기 660(`m4-m68k-kernargs-p517-F-20261026.json`).
  - `-M` 에 새 머리 넷과 `next/event_meter.h` 가 07 출처로 있고, `next/cpu.h` 는 없습니다.
  - `od.h`: 4 명령 모두 `-imacros src/generated/meta_features.h`, 그 41 행이 `#import <od.h>`, run 사본·스테이징·07 의 `od.h` SHA-256 `fa666633…` 이 같고 내용은 `#define NOD 1` 입니다.
- 7: x86 입력 불변(`m4-x86-inputs-p517-20261026.json` ok; `--plan 517 x86gate` 일곱 묶음 `same`, v183 경로 0).
- 6: run `m3p517-b514`(보존된 `m0p514-a1-stage`, `--plan 514 cmd`)와 run `m3p517-cc1`(`m0p517-a1-stage`, `--plan 517 cmd`). 두 명령 파일은 출력 접두사만 다릅니다.
  - 각 205 명령 종료 0, `collect` 로 공개했습니다.
  - stderr 비어 있지 않은 파일은 둘 다 52 개이고, 내용이 모두 같습니다.
  - 객체 205 쌍이 **모두 바이트 같음**입니다(canon·obj_sig·비 STABS 기호도 같음, python).
  - `stage_m68k.py compare`(역사 기준 W429/A432 대비): 두 run 의 보고(`m3-m68k-p517-compare-20261026.json`, `m3-m68k-p517-b514-compare-20261026.json`)가 모든 요약 항목에서 같습니다. `lost` 는 빈칸, `object_match` 146 → 175 입니다.
  - 그러나 `differ_unexpected` = [`x86-vm_fault`, `x86-vm_pageout`] 입니다. 이 둘은 plan 446·447 의 m68k 덮어쓰기(`MARKERS`)로 바뀌어 `gained`(OBJECT_MATCH 얻음)에 있는 객체인데, `EXCEPTS` 에 등록된 적이 없습니다.
  - 미리 정한 관문 "`differ_unexpected` 가 빔" 은 문자 그대로는 충족되지 않습니다. 이번 변경 전(`m3p517-b514`)에도 같으므로 기준을 바꾸지 않고 사용자께 여쭙니다.

### 517.3 결과(2026-10-26, 사용자 결정 뒤 이어서)

- 6(이어서): 사용자 결정(D110 ⑤)대로 `EXCEPTS[517]` 에 `x86-vm_fault`·`x86-vm_pageout`(plan 446·447 의 m68k 덮어쓰기)을 등록했습니다(`stage_m68k.py` 612 → 615 행).
  - `compare` 를 다시 돌린 결과(`09_validation/reconstruction/m3-m68k-p517-compare2-20261026.json`): `differ_unexpected`·`lost` 가 비었습니다. 그 밖의 요약 항목과 객체 행은 첫 보고와 같습니다(python 단언).
- 8: run `m4p517-a1`(명세 `08_build/artifacts/m4p517/spec.json`, REF = L 객체 `6785508d…`; 기록 `09_validation/reconstruction/m4-m68k-p517-final-20261026.json`).
  - `gate` 모두 참, 객체 SHA-256 `128e2f60…` 은 확인 run 의 F 와 같습니다.
  - python 확인(`m4-m68k-p517-checks-20261026.json`, `ok` 참): 정의 집합, 입력 사슬 일곱(`machargs.c`·`event_meter.h`·생성 머리 다섯) 07 = 스테이징 = run 사본, `-M` 의 새 머리 다섯이 07 출처, `next/cpu.h` 없음, `-imacros` 2 명령 모두, `meta_features.h` 의 `od.h` import, `od.h` = `#define NOD 1`, D109 격리(`<next/cpu.h>` 를 들이는 파일은 `monitor.s` 하나), 표 55 항목 같음, 옵션 = M5 줄.
- 9:
  - 근거 문서 `06_reconstruction/evidence/m68k-machargs.md`, diff `m68k-machargs.diff`(133 행)
  - 상태표 12 객체, 행 30/188, 7542 B(3.49%; python; `m4_m68k_status.py` 113 → 114 행, 앞 11 행 그대로, 두 번 돌린 출력 같음; 기록 `m4-m68k-status-p517-20261026.json`)
  - PROVENANCE 1115 → 1122 행(경로 중복 0), MODIFICATIONS 661 → 668 행, DECISIONS D110(113 → 114 행)
  - 구성 표 다섯 행의 근거 칸에 run 을 적음(`--check` 통과)
- 제 오류(정정): §515.2·§516 의 x86 줄 번호 `i386_init.c:415–421` 은 `419–424` 입니다(덩이는 419 행 `while` 부터 424 행 `}` 까지). 근거 문서의 "table line 89" 는 `struct kernargs` 89 행·`kernargs[]` 93 행으로 고쳤습니다.
- 도구 실수: `m4p517-e1` 은 명령 파일에 EXPECT 줄이 없어 `prepare` 가 거부했고(등록되지 않음), 뒤이은 `wait` 가 없는 run 을 기다려 멈췄습니다. 그 명령을 끝내고 새 ID `m4p517-e2` 로 돌렸습니다.

## 518. M4-24 세부 계획 — `in_cksum`(C)과 `oc_cksum`(어셈블리) 진단(07 변경 없음; 코딩 전, 2026-10-26)

확인한 사실(이번 세션, python):
- §495 행 `m68k-272`(`x86-in_cksum`, 212 B, 묶음 B)와 `m68k-273`(미배정, 182 B, 묶음 G)은 정확 경계이고 이어집니다(0x40927d4–0x40928a8–0x409295e). 함수는 `_in_cksum`·`_oc_cksum` 하나씩입니다.
- 원본 기호표 3809 개는 모두 외부(`0xf`) 기호이므로, 정적 함수는 기호표에 나오지 않습니다. `_oc_cksum` 은 전역 함수입니다.
- `_in_cksum` 은 `_oc_cksum` 을 세 번 `bsr` 로 부릅니다(0x40927fa·0x4092844·0x4092890).
  - 흐름은 07 x86 1997 판 `in_cksum.c:84–122`(이 프로젝트가 x86 바이트로 쓴 글, D024)의 `in_cksum` 과 같습니다.
  - 다른 점: 홀수 바이트를 더할 때 `<< 8` 이 없습니다. 0x4092830 `moveb a1@+,d0; moveb d0,d3; addal d3,a3`, 0x409286c `moveb a1@+,d0; pea a3@(0,d0:l)`.
  - 함수 머리는 `pea a6@; movel sp,a6`(컴파일된 C 의 꼴)입니다.
- `_oc_cksum` 은 `linkw a6,#0` 으로 시작합니다. 원본에서 `linkw a6,#0x0` 으로 시작하는 함수 37 개는 `_ffs` 하나를 빼면 손으로 쓴 `.s`(`next/locore.s`·`next/libc.s`·`nextdev/monitor.s`, x86 이름의 libc 함수, `_curipl`·`_cache_push`)입니다. 07 `next/cframe.h` 의 `PROCENTRY`(GDB 1)는 `link a6,#0` 을, `PROCEXIT` 는 `unlk a6; rts` 를 냅니다.
  - 몸체: 인수 셋을 a0·d1·d0 에 싣고 d2 를 저장합니다. 끝의 홀수·2 바이트를 먼저 더하고(0x4092936–0x409295a), `jmp pc@(0x42,d2:l)` 로 16 번 펼친 `movel a0@+,d2; addxl d2,d0` 고리(`dbf`)에 뛰어듭니다. 끝에서 16 비트로 접어 `andl #0xffff,d0` 합니다.
- 참고 자료: `oc_cksum` 원문(`.s`)은 `01_resources` 에 없습니다(파일 이름 검색 0 건). Darwin 0.1 `machdep/i386/in_cksum.c` 는 i386 asm 판입니다. 따라서 `oc_cksum` 은 원본 바이트로 쓰는 작성(D024)이 됩니다.

방법(진단; 명세 `08_build/artifacts/m4p518/spec.json`, run `m4p518-p1`, 바탕 `m0p517-a1-stage`):
- 대상 `in_cksum`(`m4_id` `m68k-272`, 줄 틀 `machdep/i386/dkbad.c`, §496):
  - 변형 X: 07 x86 `in_cksum.c` 의 `in_cksum` 함수와 머리 import 를 그대로 두고, `static inline oc_cksum` 대신 `int oc_cksum();` 선언만 둠
  - 변형 B: X 에서 `<< 8` 두 곳만 지움
- 대상 `oc_cksum`(`m4_id` `m68k-273`, 줄 틀 `machdep/i386/start.s`, `defs` `-DASSEMBLER`, §514):
  - 변형 S: 원본 명령을 `PROCENTRY(oc_cksum)`·`a_p0`–`a_p2`·`PROCEXIT`(`#import <m68k/cframe.h>`)로 쓴 `.s`. 펼친 고리로 뛰는 `jmp` 의 변위는 원본(0x42)과 같게 둡니다.
- 측정: `compare`(`diag_gate`, 옵션, `full_span`, L1, 정의·COMMON, 원본에 없는 미정의), 맞지 않으면 실기 `otool -tv` 와 `funcs`.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음): 변형마다 결과를 적습니다. B·S 가 `candidate` 이면 07 구현 계획(§519)으로 가되, 그 전에 바이트로 정해지지 않는 꼴을 사용자께 여쭙니다(07 파일 자리·이름, `<< 8` 의 조건부 꼴(`#if`) 여부, `oc_cksum` 선언 꼴). 아니면 차이를 기록하고 멈춥니다.

### 518.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류:
- "원본 기호표 3809 개는 모두 `0xf`" 는 틀렸습니다. 모두 외부 기호인 것은 맞지만, `__mh_execute_header` 하나는 `0x3`(절대)이고 3808 개가 `0xf` 입니다(`symbols.tsv:93`).
- "`_ffs` 하나를 빼면" 은 틀렸습니다. `_ffs`(0x4092e76)는 07 `libc.s:247` 의 `PROCENTRY(ffs)` 로 받아들인 `libc` 객체 안에 있습니다. `_curipl` 은 NeXTMach `next/locore.s:337` 의 `PROCENTRY (curipl)` 입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 행 273 이 따로 된 `.s` 객체라는 것은 가설임. 목록의 경계는 원래 링크 입력 객체를 복원하지 않으며, C 파일 안의 최상위 `asm` 도 같은 바이트를 낼 수 있음. 0x40928a6 `rts` 와 0x40928a8 사이 채움 0 | 목록 행 273 `basis none`; 원본 바이트 0x40928a6 `4e75` 바로 뒤 0x40928a8 `4e560000`(python) | ✅ 파일 나눔은 바이트로 정해지지 않는 꼴로 사용자께 여쭐 항목에 넣음 |
| 판정에 `diag_gate`·옵션 통과를 필수로 | `m4_m68k_probe.py:337,359` 읽음(§516.1 과 같은 지적) | ✅ |
| `_in_cksum` 은 x86 판에서 `<< 8` 둘만 뺀 흐름과 같음; C 의 마지막 두 호출은 한 호출 지점으로 합쳐짐(0x4092878 → 0x4092890); 비교는 부호 있음(`bge`/`blt`), `m_len` 은 부호 있는 short | 이번 세션 원본 목록 읽음(0x40927d4–0x40928a6) | ✅ "원본 C 글과 같다" 가 아니라 "흐름이 같다" 로 적음 |
| 민감한 인코딩: `jmp` `4efb 2842`, CCR `023c 000f`, `movew` `3430 18fd`, `dbf` `51c9 ffbe`, `addxw` `d141`, `bne` 단어 변위 `6600 008c`, 꼬리 `bra` `6000 ff78`·`6000 ff6c`, `bne` 0x40928be 바이트 변위 | 원본 바이트를 python 으로 읽음(값 모두 같음); `jmp` 의 PC 기준 0x40928da + 0x42 = 0x409291c(`dbf`) | ✅ S 를 쓸 때 이 바이트를 관문으로 확인 |
| `linkw a6,#0` 으로 시작하는 곳은 함수 표 밖의 `_msb`(0x4092faa)까지 38 | 원본 바이트 0x4092faa `4e560000`(python) | ✅(근거 문장의 수만 고침, 결론 같음) |
| 도구는 대상마다 다른 줄 틀과 변형별 `defs` 를 받음(`defs` 는 변형 dict 안, `inc` 필요) | `m4_m68k_probe.py:64–69,194–213` | ✅ |

수정한 판정: B 와 S 가 각각 `candidate` 이고 `diag_gate` 참, 옵션 = M5 줄(S 는 + `-DASSEMBLER`)이면 07 구현 전에 사용자께 여쭙니다(파일 나눔(`.s` 따로 / C 파일 안 최상위 `asm`), 07 파일 자리, `<< 8` 의 꼴, `oc_cksum` 선언). S 는 위 민감한 인코딩 바이트가 원본과 같은지도 확인합니다.

### 518.2 결과(2026-10-26)

- run `m4p518-p1`(스테이징 `m4p518-stage` 913 파일, 6 명령 모두 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄, S 는 + `-DASSEMBLER`; 기록 `09_validation/reconstruction/m4-m68k-probe-p518-20261026.json`).
- `in_cksum`:
  - B(`08_build/artifacts/m4p518/src/in_cksum_B.c`, x86 07 `in_cksum` 본문에서 `<< 8` 둘만 뺌)는 `candidate` 입니다. `full_span`, L1 `OBJECT_MATCH`, 212/212 B, 객체 SHA-256 `a0ac4b72…`.
  - X(`<< 8` 그대로)는 218 B, `NOT_MATCH` 입니다(참조 차이 2).
  - 정의: `_in_cksum` 과 `sys/mbuf.h`(SDK 계열 `07_kernel/nextdev`)가 임시 정의하는 COMMON 8 개(`_embutl` 128, `_m_want` 4, `_mbstat` 92, `_mbutl` 4, `_mclfree` 4, `_mclrefcnt` 514, `_mfree` 4, `_nmbclusters` 4)입니다.
  - 이 여덟은 모두 원본 기호표에 있습니다. 7 개는 섹션 6 `__common`, `_nmbclusters` 는 섹션 4 `__data` 로 다른 객체가 정의합니다(M7 합침 의무, §506·§508 과 같은 꼴).
- `oc_cksum`: S(`08_build/artifacts/m4p518/src/oc_cksum_S.s`, `PROCENTRY`·`a_p0`–`a_p2`·`PROCEXIT`, 원본 명령 그대로)는 `candidate` 입니다.
  - `full_span`, L1 `OBJECT_MATCH`, 182/182 B, 객체 SHA-256 `b8422a89…`
  - 정의는 `_oc_cksum` 하나, 원본에 없는 미정의 0
  - 의존 목록의 `cframe.h` 는 07 nextmach 출처입니다(`gdb.h` 는 D108 대로 `-imacros`).
  - 민감한 인코딩(§518.1 표)은 L1 텍스트 바이트 같음에 들어 있습니다.
- 판정: B·S 모두 §518.1 의 조건을 만족합니다. 07 구현 전에 바이트로 정해지지 않는 꼴을 사용자께 여쭙니다.

## 519. M4-25 세부 계획 — 사용자 꼴(한 파일 + 최상위 `asm`, 프로토타입) 진단(07 변경 없음; 코딩 전, 2026-10-26)

사용자 결정(AskUserQuestion, D111 로 적을 예정): ① `oc_cksum` 은 `in_cksum.c` 한 파일 끝의 최상위 `asm` 으로 둠 ② `oc_cksum` 선언은 프로토타입 `int oc_cksum(unsigned char *buf, int len, unsigned long oldsum);`(x86 판 함수의 형과 같음). 둘 다 §518 에서 시험하지 않은 꼴입니다.

확인한 사실(이번 세션):
- C 파일 안의 문자열에서는 `cframe.h` 매크로(`PROCENTRY`·`a_p0`·`PROCEXIT`)가 펼쳐지지 않습니다. 그 정의는 GDB 1 에서 `link a6,#0`·`a6@(0x8)`·`a6@(0xc)`·`a6@(0x10)`·`unlk a6; rts` 입니다(`07_kernel/nextmach/next/cframe.h:66–92`).
- 07 x86 `in_cksum.c:25` 는 여러 줄 `asm("…")` 문자열을 씁니다(`-traditional-cpp` 줄에서 컴파일됨). 07 에 파일 범위 `asm` 의 선례는 없습니다(grep).

방법(진단; 명세 `08_build/artifacts/m4p519/spec.json`, run `m4p519-p1`, 바탕 `m0p517-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`):
- 변형 T(`m4_id` [`m68k-272`, `m68k-273`]): §518 B 에서 선언만 프로토타입으로 바꾸고, 파일 끝에 최상위 `asm("…");` 을 둡니다.
  - asm 글은 §518 S 의 명령과 같은 줄입니다. 매크로 대신 `.text`, `.globl _oc_cksum`, `_oc_cksum:`, `link a6,#0`, `a6@(0x8)` 등으로 펼쳐 씁니다. 숫자 지역 이름표는 S 와 같고, 주석은 넣지 않습니다.
- 변형 P(`m4_id` `m68k-272`): §518 B 에서 선언만 프로토타입으로 바꾼 것. 선언 꼴의 영향을 따로 봅니다.
- 측정: `compare`(`diag_gate`, 옵션, `full_span`, L1, 정의·COMMON, 미정의). P 는 §518 B 객체와 canon·obj_sig 를 비교합니다. T 는 `__text` 394 B(212 + 182; python)가 0x40927d4 에 놓이는지, 정의가 `_in_cksum`·`_oc_cksum` 과 COMMON 8 개인지 봅니다.

판정(미리 정함): P 가 B 와 같고, T 가 `candidate` 이면서 `diag_gate` 참이면 07 구현(§520)으로 갑니다. 아니면 차이를 기록하고 사용자께 다시 여쭙니다.

### 519.1 교차검토와 결과(2026-10-26)

- codex(`gpt-6.1-sol`) 판정:
  - ✅ 파일 범위 `asm` 은 앞 함수 뒤에 나옵니다. NeXT 디버그 꼬리는 `.text`·`.stabs`·이름표만 내고 정렬을 넣지 않습니다(`01_resources/upstream/next-gcc-2.7.2/config/next/nextstep.h:306–309` 읽음).
  - ✅ asm 글은 `.text` 로 시작합니다. `.even` 은 S 에 없던 지시어라 넣지 않았습니다(⚖️).
  - ✅ `.globl` 이 필요합니다.
  - ✅ 프로토타입은 인수 변환 명령을 더하지 않을 것입니다(결과로 확인).
- run `m4p519-p1`(스테이징 `m4p519-stage` 912 파일, 4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p519-20261026.json`):
  - P(`08_build/artifacts/m4p519/src/in_cksum_P.c`): `candidate`, §518 B 와 canon·obj_sig 같음(객체 SHA-256 `5e65aa31…`).
  - T(`08_build/artifacts/m4p519/src/in_cksum_T.c`, `m4_id` [272, 273]): `candidate`, `full_span`, L1 `OBJECT_MATCH`. `__text` 394/394 B 가 0x40927d4 에 놓입니다. 정의는 `_in_cksum`·`_oc_cksum` + COMMON 8 개(§518.2 와 같음), 원본에 없는 미정의 0, 객체 SHA-256 `47185365…`.
- 판정: §519 의 조건을 만족합니다. 07 구현(§520)으로 갑니다.

## 520. M4-26 D111 구현 계획 — 07 `src/machdep/m68k/in_cksum.c`(코딩 전, 2026-10-26)

방법(§514·§517 의 절차에서 생성 머리·M5 회귀를 뺀 것; 이번 변경은 m68k 전용 `.c` 하나라 M5 205 줄이 읽지 않음):
1. 07 `src/machdep/m68k/in_cksum.c` = T 에 설명 주석 한 덩이(근거: 원본 주소, x86 07 `in_cksum.c` 바탕, `<< 8` 제거, 최상위 `asm` 의 원본 바이트, D024·D103·D111)와 표시 주석을 더한 것입니다.
   - 표시 주석은 asm 문자열 안에 넣지 않습니다(문자열 바깥, 줄 끝 `/* … */` 또는 따로 선 줄).
   - 주석을 뺀 토큰이 T 와 같아야 합니다(python).
2. `stage_m68k.py`:
   - `M4FILES[520]` = 517 목록 + `in_cksum.c`, `M4HEADERS[520]` = `M4HEADERS[517]`, `EXCEPTS[520]` = `EXCEPTS[517]`, 문서 줄
   - 07 파일과 같은 단계에서 등록합니다(§517.1)
   - 회귀: `--plan 517` 로 다시 만든 매니페스트가 `m0p517-a1-stage` 와 같음, `--plan 520 stage m0p520-a1-stage` 와의 차이는 `in_cksum.c` 하나
3. x86 입력 불변(`m4_x86_inputs.py s6ll`, `--plan 520 x86gate`).
4. 확인 run `m4p520-p1`(F = `@machdep/m68k/in_cksum.c`, L = T, `m4_id` [272, 273]): 둘 다 `candidate`, F·L·T canon·obj_sig 같음, `diag_gate` 참, 옵션 = M5 줄.
5. 최종 run `m4p520-a1`(REF = L 객체): `gate.ok`. python 확인: 정의 집합, 입력 사슬 07 = 스테이징 = run 사본, D109 격리 검사 그대로, L1 `__text` 394 B 가 0x40927d4 에 놓이고 사유 없음.
6. 기록:
   - 상태표 `ACCEPTED` 에 p520 을 더함(예상 13 객체, 행 32/188, 바이트는 python)
   - PROVENANCE 한 행(authored D024: x86 07 `in_cksum.c` 의 `in_cksum` 본문이 바탕, `oc_cksum` 은 원본 바이트로 씀; 참고 원문 없음), MODIFICATIONS 한 행, DECISIONS D111
   - 근거 문서 `06_reconstruction/evidence/m68k-in_cksum.md`, diff(x86 07 판 대비) `m68k-in_cksum.diff`
   - M7 의무: `sys/mbuf.h` COMMON 8 개의 합침(`_nmbclusters` 는 `__data`)
관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 520.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| PROVENANCE 는 `authored`. 직접 바탕은 이 프로젝트의 x86 `in_cksum.c:84–122`(리비전·해시 기록)이고, 그 Darwin 일치 가능성 고지를 이어 적음. D030 은 해당 없고 D027 이 이 선례 | `DECISIONS.md:31`(D027: i386 `in_cksum`)·`:34`(D030 은 kernel/machdep 밖) 읽음; x86 파일 SHA-256 `8348507f…`, 커밋 `ac383f78` | ✅ |
| 상태표 앞 행 불변·두 번 출력 같음·기록 해시, `L2_FORMS`/`L2_EXPECT` 명시 | §517 절차 | ✅ |
| 주석은 asm 문자열·지시문 밖에만; 문자열을 아는 비교와 실기 `-E` 비교 | 설계 | ✅ `-E` run 추가 |
| M5 205 줄은 고정 기준 run 의 `-c` 줄만 되풀이하므로(`stage_m68k.py:487–495` `ref_lines`) m68k 전용 새 `.c` 를 읽지 않음 → M5 회귀 생략 타당 | 위 줄 읽음 | ✅ |

### 520.2 결과(2026-10-26)

- 1: 07 `src/machdep/m68k/in_cksum.c`(136 행, SHA-256 `f095d09c…`).
  - T 에 설명 주석 한 덩이와 표시 주석 넷을 더했습니다(프로토타입 줄, `<< 8` 을 뺀 두 줄, asm 앞의 따로 선 줄). asm 문자열 안에는 주석을 넣지 않았습니다.
  - 문자열을 아는 토큰 비교에서 T 와 같고(274 토큰), asm 문자열은 T 와 같습니다(python).
- 2: `stage_m68k.py` 615 → 619 행(`M4FILES[520]`, `M4HEADERS[520]` = 517, `EXCEPTS[520]` = 517).
  - `--plan 517` 재생성(`08_build/artifacts/m4p520/re517-stage`)의 파일·`replaced`·`added`·`m4_sources`·`m4_headers` 가 `m0p517-a1-stage` 와 같습니다.
  - `--plan 520 stage m0p520-a1-stage`(911 파일)와의 차이는 `in_cksum.c` 하나입니다.
- 3: x86 입력 불변(`m4-x86-inputs-p520-20261026.json` ok; `--plan 520 x86gate` 일곱 묶음 `same`, v183 경로 0).
- 4: run `m4p520-p1`(4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p520-20261026.json`).
  - F(07)·L(= T) 모두 `candidate` 이고, 서로 그리고 §519 T 와 canon·obj_sig 가 같습니다(L 은 T 와 SHA-256 도 같음 `47185365…`).
  - run `m4p520-e1`: `-E` 전처리 토큰 884 개가 F·L 같습니다.
- 5: run `m4p520-a1`(REF = L; 기록 `m4-m68k-p520-final-20261026.json`). `gate` 모두 참, 객체 SHA-256 `3556190c…` = F.
  - python 확인(`m4-m68k-p520-checks-20261026.json`, `ok` 참): 정의 집합(`_in_cksum`·`_oc_cksum` + COMMON 8), 입력 사슬 07 = 스테이징 = run 사본, L1 `__text` 394 B 가 0x40927d4 에 놓이고 바이트·참조 차이 0, D109 격리(`<next/cpu.h>` 는 `monitor.s` 뿐), 옵션 = M5 줄.
- 6:
  - 상태표 13 객체, 행 32/188, 7936 B(3.68%; python; `m4_m68k_status.py` 114 → 115 행, 앞 12 행 그대로, 두 번 돌린 출력 같음; 기록 `m4-m68k-status-p520-20261026.json`)
  - PROVENANCE 1122 → 1123 행(경로 중복 0), MODIFICATIONS 668 → 669 행, DECISIONS D111(114 → 115 행)
  - 근거 문서 `06_reconstruction/evidence/m68k-in_cksum.md`, diff `m68k-in_cksum.diff`(198 행, i386 판 대비)

## 521. M4-27 세부 계획 — `nextif/in_bootp.c` 의 NeXTMach 판 진단(07 변경 없음; 코딩 전, 2026-10-26)

다음 대상을 고른 이유(이번 세션):
- fpsp(§495 묶음 A, 44 행, 최소 23306 B)는 NeXTMach `fpsp/*.sa` 를 `conv` 로 바꿔 조립하고 `ld -r` 로 묶은 `fpsp.o` 하나입니다(`fpsp/Makefile`, `conf/files.NeXT:79`). 그러나 1997 판은 NeXTMach 1990 판과 다릅니다. 예를 들어 `x_bsun`(0x40a47ba) 원본은 `moveml d0/d1/a0/a1`·`fp0`–`fp3`·`link #-0xc0` 인데 NeXTMach `x_bsun.sa` 는 `d0-d7`·`a0-a1`·`fp0/fp1` 입니다. 나중 Motorola FPSP 판이 필요하며, 그 원문은 `01_resources` 에 없습니다. 사용자 결정 사항으로 미룹니다.
- `us_timer` 는 1997 판에 참고 글이 없는 새 함수(`__set_timer` 166 B, `_clear_timer`)가 있고, NeXTMach 전용 머리 넷(`next/scr.h`·`next/clock.h`·`next/eventc.h`·`next/us_timer.h`)이 필요합니다. `tty_pty` 꼬리는 x86 과 함께 쓰는 07 파일을 고쳐야 합니다.
- `in_bootp`: §495 행 `m68k-261`(530 B)·`m68k-262`(bracket, 3290 B), 둘 다 정확 경계이고 이어집니다. [0x408fd9e, 0x4090c8a), 3820 B.
  - §499 에서 07 x86 판(`bsd/netinet/in_bootp.c`)을 m68k 로 컴파일했을 때 15 함수 가운데 7 개가 같았습니다(`m4-m68k-funcs-p499-20261024.json`).
  - 원본의 함수 순서는 NeXTMach `nextif/in_bootp.c` 의 정의 순서와 같습니다(`initnet` 60 … `setaddress` 640, `static` `makeifreq` 682, `in_bootp` 711). 원본의 이름 없는 118 B 함수(0x4090a50)는 그 자리의 `static in_bootp_makeifreq` 와 맞습니다(원본 기호표에는 외부 기호만 있음).
  - 07 x86 판은 x86 바이트에 맞춰 함수가 `static` 이고 `in_bootp` 가 맨 앞입니다(§366).
- 머리(§498 표 `m68k-m4-headers.tsv`):
  - `sys/boolean.h`: 스테이징에는 `src/mach/boolean.h` 이고 NeXTMach `sys/boolean.h` 와 글이 다릅니다.
  - `mon/bootp.h`: 스테이징 `src/bsd/netinet/bootp.h`(SDK 계열, 1992 년 `nextvend` 채움 수정이 있음)이고 NeXTMach 와 다릅니다.
  - `nextdev/kmreg.h`: NeXTMach 에만 있습니다. 따옴표로 `mon/nvram.h` 를 들입니다.

방법(진단; 명세 `08_build/artifacts/m4p521/spec.json`, run `m4p521-p1`, 바탕 `m0p520-a1-stage`, 줄 틀 `machdep/i386/dkbad.c`, `m4_id` [`m68k-261`, `m68k-262`]):
- 변형 G: NeXTMach `nextif/in_bootp.c` 그대로. `inc` = NeXTMach 원문 사본 `sys/boolean.h`·`mon/bootp.h`·`nextdev/kmreg.h`·`mon/nvram.h`(그리고 컴파일 오류가 가리키는 NeXTMach 전용 머리만 차례로 더함, 기록).
- 변형 X: 07 `bsd/netinet/in_bootp.c` 그대로(§499 재현, 바탕만 새 스테이징).
- 측정: `compare`(`diag_gate`, 옵션, `full_span`, L1, 정의·COMMON, 미정의), 실기 `otool -tv` 와 `funcs`(G·X 함수별), 함수마다 G·X 중 원본과 같은 쪽을 표로 만듭니다(python).

판정(미리 정함; 진단이므로 07 은 바꾸지 않음): 함수별 같음 표를 적습니다. 결과로 1997 m68k 판의 꼴(NeXTMach 바탕에 x86 1997 의 바뀐 본문을 넣을지, x86 07 판에 m68k 덩이를 넣을지)과 머리 공급을 사용자께 여쭙고, 그 뒤 계획을 세웁니다.

### 521.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류:
- fpsp 의 차이로 든 "`link #-0xc0`" 은 차이가 아닙니다. NeXTMach `fpsp.sa:89` 의 `LOCAL_SIZE` 도 192 입니다. 다른 것은 저장하는 레지스터(`d0/d1/a0/a1`·`fp0`–`fp3` 대 `d0-d7`·`a0-a1`·`fp0/fp1`)입니다.
- §499 의 "7/15 같음" 은 숫자를 가린 비교라 상수 차이를 놓칩니다. 예: `initnet` 원본 0x408fde2 `orw #0x1,d0`, X `orw #0x21,d0`(07 `in_bootp.c:246` 의 `IFF_NOTRAILERS`). "7 함수 본문이 같다" 로 읽으면 안 됩니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `funcs` 는 16 진 피연산자를 모두 가림 → 상수·변위·분기 대상을 따로 비교해야 함 | 위 원본·X 목록 줄 읽음(원본 180799 행, X 168 행) | ✅ 함수별 바이트 비교 도구를 더함 |
| G 대 X 는 머리 차이와 본문 차이가 섞임 → H(NeXTMach 본문, include 만 스테이징 경로) 추가. 원본은 나중 bootp 배치(`pea 0x148` 0x408fefe, `clrb a2@(0x10e)` 0x408ff90, `moveq #55` 0x409089c) | 원본 목록 줄 읽음 | ✅ H 추가 |
| H 는 `kmreg.h` 대신 스테이징 `dev/kmreg_com.h` 를 쓰면 `alert_key` 선언이 없으므로, 진단용 다리 머리(`kmreg_com.h` 를 들이고 `extern int alert_key;`)가 필요 | 스테이징 grep(아래 결과) | ✅ 다리 머리를 기록하고 씀 |
| 이름 없는 0x4090a50 은 `makeifreq` 와 코드로도 맞음; X 에도 `_in_bootp_makeifreq` 가 있음(§499 에서는 짝이 없는 객체 함수로 셈) | X 목록 868 행 `_in_bootp_makeifreq:` | ✅ 진단용 주소→이름 대응을 더함(원본 기호 근거는 그대로) |
| G 에는 `machine/boolean.h` 도 필요(NeXTMach `sys/boolean.h:26`), 스테이징에 없음 | 원문 읽음 | ✅ NeXTMach `next/boolean.h` 를 `machine/boolean.h` 로 inc |
| G 의 `kmreg.h`(`KERNEL`)는 `km`·`alert_key`(·`km_coni`)를, `sys/tty.h` 는 `tthiwat` 등을 임시 정의 → COMMON 이름·크기를 기록하고 바탕과 나눔 | `kmreg.h:192–195` 읽음 | ✅ |
| `x86_rel` 은 실제 줄 `bsd/netinet/in_bootp.c`(§499 와 같음) | §499 명세 읽음 | ✅ |
| X 는 §499 객체와 canon 으로 재현을 확인; 528 행 경고는 따로 분류 | §499 결과 | ✅ |

수정한 방법(앞 방법을 대신함):
- `x86_rel` = `bsd/netinet/in_bootp.c`. 변형은 셋입니다.
  - G: NeXTMach 그대로. `inc` = `sys/boolean.h`·`machine/boolean.h`(← NeXTMach `next/boolean.h`)·`mon/bootp.h`·`nextdev/kmreg.h`·`mon/nvram.h`
  - H: NeXTMach 에서 include 줄 셋만 바꿈. `<sys/boolean.h>` → `<mach/boolean.h>`, `<mon/bootp.h>` → `<netinet/bootp.h>`, `<nextdev/kmreg.h>` → 진단 다리 머리 `m4bridge/kmreg.h`(`dev/kmreg_com.h` 를 들이고 `extern int alert_key;`)
  - X: 07 그대로
- 새 진단 도구 `10_tools/reconstruction/m68k_funcbytes.py`: 원본 함수마다 객체의 같은 이름 함수(진단 대응 0x4090a50 → `_in_bootp_makeifreq` 포함)의 바이트를 함수 기준 오프셋으로 맞댑니다.
  - 길이가 같으면, 객체 재배치 칸을 뺀 바이트 차이 수와 재배치 칸마다 대상(원본은 값이 가리키는 기호+덧셈, 객체는 재배치 기호+덧셈; 함수 안 분기는 함수 기준 오프셋)을 비교합니다.
  - 길이가 다르면 길이만 적습니다.
- 기록: 변형마다 함수별 표(길이, 연결(외부/정적), 숫자를 가린 같음, 바이트 차이, 참조 차이), 정의·COMMON 이름과 크기, X 의 §499 재현(canon), 경고 줄.

### 521.2 결과(2026-10-26)

- run `m4p521-p1`(스테이징 `m4p521-stage` 919 파일, 6 명령; 기록 `09_validation/reconstruction/m4-m68k-probe-p521-20261026.json`).
  - G 는 컴파일 실패입니다(종료 1). NeXTMach `machine/boolean.h`(`next/boolean.h`)의 `boolean_t` 가 스테이징 `mach/m68k/boolean.h:62` 와 겹칩니다. 빠진 머리가 아니라 1990 머리와 OPENSTEP 머리의 충돌이라 G 는 더 고치지 않습니다.
  - H·X 는 컴파일 종료 0 입니다. X 에는 §499 와 같은 528 행 경고가 있어 `diag_gate.commands_ok` 는 거짓입니다(G 실패 포함).
  - X 객체는 §499 X 와 canon 이 같습니다(재현).
- 새 도구 `10_tools/reconstruction/m68k_funcbytes.py`(함수별 바이트·참조 대상 비교).
  - 처음 판에는 결함 둘이 있었습니다: 흩어진 재배치의 덧셈을 버림, 원본 별칭(`_copyin`/`_copyinmsg`)을 하나만 봄. 둘 다 고쳤습니다.
  - 고친 뒤 받아들인 객체 일곱(`machargs`·`in_cksum`·`mem`·`next_table`·`vm_unix`·`nbic`·`cons`)에서 모든 함수가 "같음" 입니다. 다른 것은 다른 것으로 잡습니다(§515 C 의 `getargs`, X 의 `initnet`).
- 함수별 결과(`m4-m68k-funcbytes-p521-{H,X}-20261026.json`, 진단 대응 0x4090a50 = `_in_bootp_makeifreq`):

| 함수 | 원본 B | H(NeXTMach 본문) | X(07 x86 1997 판) |
|---|---|---|---|
| `initnet` | 336 | 같음 | 1 바이트 다름(`IFF_NOTRAILERS`) |
| `buildpacket` | 194 | 202 B | 같음 |
| `bptombuf` | 362 | 374 B | 같음 |
| `timeout`·`getpacket` | 26·68 | 같음 | 같음 |
| `promisctimeout` | 14 | 같음 | 16 B |
| `sendrequest` | 1038 | 1078 B | 같음 |
| `openconsole`·`closeconsole`·`noecho`·`echo` | 204·326·96·96 | 같음 | 다름/없음 |
| `processreply` | 332 | 같음 | 254 B |
| `setaddress`·`makeifreq` | 158·118 | 같음 | 같음 |
| `in_bootp` | 452 | 448 B | 8 바이트 다름 |

- `in_bootp` 의 X 차이는 끝 한 곳뿐입니다. 원본 0x4090c70(+0x1aa)은 NeXTMach 꼴 `if (vp) (void) in_bootp_closeconsole(vp);` 이고, X 는 `if (!error)` 입니다.
- m68k 원본 문자열에 x86 1997 `sendrequest` 의 문구("Type Control-C to start up computer without a network" 0xac11a, "Network responded!" 0xac15d)가 있습니다.
- 07 x86 판에서 "plan 366 (Darwin)" 표시는 x86 콘솔 쪽(`in_bootp.c:77` 정적 선언·`alertShowing`, `:607` `openconsole`·`closeconsole`, `:789` `kmgets`)에만 있습니다. m68k 에서 그 자리는 NeXTMach 판이 맞습니다(H 같음). x86 판에서 가져올 네 함수의 바뀜은 "plan 366"(Darwin 표시 없음)입니다.

## 522. M4-28 세부 계획 — 조합 변형 M 진단(07 변경 없음; 코딩 전, 2026-10-26)

변형 M(`08_build/artifacts/m4p521/src/in_bootp_M.c`, 만들어 두었고 아직 컴파일하지 않음):
- H(NeXTMach 본문, include 셋만 스테이징 경로, 진단 다리 머리)에서 네 함수만 07 x86 판의 글로 바꿉니다: `buildpacket`·`bptombuf`·`sendrequest`·`in_bootp`.
- 정적 지정과 x86 판의 맨 앞 `int` 는 빼서 NeXTMach 의 연결·꼴을 유지합니다.
- `in_bootp` 끝의 `if (!error) {` 는 NeXTMach 꼴 `if (vp) {` 로 둡니다.
- H 대비 차이는 위 네 함수의 "plan 366" 바뀜과 `in_bootp` 끝 표시 주석뿐입니다(diff 49 줄, python).

방법: run `m4p522-p1`(바탕 `m0p520-a1-stage`, `x86_rel` `bsd/netinet/in_bootp.c`, `m4_id` [261, 262], `inc` = H 의 다리 머리).
- `compare`(`diag_gate`, 옵션, `full_span`, L1, 정의·COMMON 이름·크기, 미정의)
- `m68k_funcbytes.py`(진단 대응 0x4090a50 = `_in_bootp_makeifreq`)

판정(미리 정함): M 이 `candidate`(L1 `OBJECT_MATCH`)이고 15 함수가 모두 바이트까지 같으며 경고 0 이면, 07 구현 전에 사용자께 여쭙니다.
- 바탕 꼴: NeXTMach 파일 + x86 판 함수 넷 / 07 x86 파일에 m68k 덩이
- 07 자리: `src/machdep/m68k/in_bootp.c`(D103)
- `kmreg.h` 다리(`alert_key` 선언)의 꼴과 자리
- COMMON 기록

아니면 차이를 기록하고 멈춥니다.

### 522.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: `m68k_funcbytes.py` 에 거짓 "같음" 이 남아 있었습니다. 바깥 PC 상대 호출의 덧셈을 늘 0 으로 보았고, 지역·흩어진 재배치의 섹션이 맞는지 보지 않았습니다. `m68k_kernargs.py`(§516.1)에서 고친 것과 같은 종류의 실수를 되풀이했습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 바깥 PC 상대 덧셈 무시로 `_kalloc+2` 변조도 같음 | 객체 둘에서 "저장 값 + 필드 주소 = 덧셈" 확인(덧셈 0 호출 63 개, python). 고친 뒤 X 사본의 `_kalloc` 호출을 +2 하면 `buildpacket` 참조 차이 1 | ✅ 고침 |
| 지역 재배치의 `r_symbolnum`, 흩어진 재배치의 `r_value` 섹션을 확인하지 않음 | 고친 뒤 `sendrequest` 안 지역 재배치 셋의 섹션을 `__data` 로 바꾸면 모두 "outside its section" 으로 멈춤 | ✅ 고침 |
| 함수 경계는 기호 기준 휴리스틱(이름표가 함수를 쪼갤 수 있음, 같은 주소 별칭); 단언 대신 명시 오류 | 코드 읽음; H·X 에는 같은 주소 기호 없음 | ✅ 명시 오류로 바꾸고, 한계를 기록함 |
| M 은 네 함수 밖에서 H 와 같고, 그 넷은 `if (vp)` 끝을 빼면 X 와 같음; `openconsole` 암묵 선언은 형이 같음; `TRUE` 있음 | 위 §522 diff(python), M:386·446 줄 읽음 | ✅ |
| 명세의 `m4_id` 는 문자열 `"m68k-261"`·`"m68k-262"` | `m4_m68k_probe.py:159` | ✅ |
| "같음" 은 재배치를 대상으로 바꿔 본 같음이며, L1 `OBJECT_MATCH` 를 따로 필수로 | 설계 | ✅ |

고친 도구로 받아들인 객체 일곱을 다시 돌려도 모든 함수가 "같음" 입니다.

### 522.2 결과(2026-10-26)

- run `m4p522-p1`(스테이징 `m4p522-stage` 913 파일, 2 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p522-20261026.json`).
- M(`08_build/artifacts/m4p521/src/in_bootp_M.c`): `candidate`. `full_span`, L1 `OBJECT_MATCH`(사유 없음), `__text` 3820/3820 B, 외부 텍스트 기호 14 개가 원본과 같음, 원본에 없는 미정의 0, 객체 SHA-256 `940ece02…`.
- 함수별(고친 `m68k_funcbytes.py`, `m4-m68k-funcbytes-p522-M-20261026.json`): 15/15 함수가 바이트와 참조 대상까지 같습니다(진단 대응 0x4090a50 = 정적 `_in_bootp_makeifreq`).
- 정의: 함수 14 개와 머리가 임시 정의하는 COMMON 20 개(`sys/mbuf.h`·`net/if.h`·`net/route.h`·`netinet/ip_var.h`·`udp_var.h` 등 계열; 크기는 기록에 있음). `kmreg.h` 의 `km`·`alert_key` 는 없습니다(H·M 은 NeXTMach `kmreg.h` 를 쓰지 않음).
- M 은 `alert_key` 를 쓰지 않습니다(334 행 주석뿐). 그래서 다리 머리 없이 x86 07 판처럼 `<nextdev/kmreg.h>` 를 스테이징 `kmreg_com.h` 로 바로 들일 수 있습니다.
- 판정: §522 의 조건을 만족합니다. 07 구현 전에 사용자께 여쭙니다.

## 523. M4-29 D112 구현 계획 — 07 `src/machdep/m68k/in_bootp.c`(코딩 전, 2026-10-26)

사용자 결정(D112, AskUserQuestion): NeXTMach 바탕 m68k 파일. 07 `src/machdep/m68k/in_bootp.c`(D103) = NeXTMach `nextif/in_bootp.c` 에 다음만 바꾼 글입니다.
- include 줄 셋을 x86 07 판과 같은 OPENSTEP 경로로: `<mach/boolean.h>`, `<netinet/bootp.h>`, `<bsd/dev/kmreg_com.h>`(07 x86 `in_bootp.c:48,71,72`)
- 네 함수의 바뀜: x86 07 판(plan 366, Darwin 표시 없음)과 같은 줄
- `in_bootp` 끝은 NeXTMach 꼴 `if (vp)`
- x86 공유 파일 `bsd/netinet/in_bootp.c` 는 바꾸지 않습니다.

방법(§520 절차; 새 m68k 전용 `.c` 하나라 M5 205 줄은 읽지 않음, §520.1):
1. L = M 에서 `#import <m4bridge/kmreg.h>` 를 `#import <bsd/dev/kmreg_com.h>` 로 바꾼 글(`08_build/artifacts/m4p523/src/in_bootp_L.c`). H 대비 차이는 include 줄 셋과 네 함수뿐이어야 합니다(python).
2. 07 파일 = L + 설명 주석 한 덩이(근거: NeXTMach 바탕, 원본 주소, x86 판에서 온 네 함수, 고친 include, D024·D103·D112, `makeifreq` 는 정적이라 원본 기호표에 없음) + 표시 주석. 네 함수에 x86 판에서 함께 온 `/* plan 366: … */` 주석은 출처 표시로 남기고, 설명 덩이에서 그 뜻을 밝힙니다. 주석을 뺀 토큰 = L(python).
3. `stage_m68k.py`: `M4FILES[523]` = 520 목록 + `in_bootp.c`, `M4HEADERS[523]` = 517, `EXCEPTS[523]` = 520.
   - 회귀: `--plan 520` 재생성 매니페스트 = `m0p520-a1-stage`
   - `--plan 523 stage m0p523-a1-stage` 와의 차이는 `in_bootp.c` 하나
4. x86 입력 불변(`L2_FORMS`/`L2_EXPECT` 명시 `m4_x86_inputs.py s6ll`, `--plan 523 x86gate`).
5. 확인 run `m4p523-p1`(F = `@machdep/m68k/in_bootp.c`, L, `x86_rel` `bsd/netinet/in_bootp.c`, `m4_id` [`m68k-261`, `m68k-262`]):
   - F·L `candidate`, F·L·M canon·obj_sig 같음, `diag_gate` 참, 옵션 = M5 줄
   - `m68k_funcbytes.py` 15/15
   - run `m4p523-e1` 에서 `-E` 토큰 F = L
6. 최종 run `m4p523-a1`(REF = L 객체): `gate.ok`. python 확인: 정의 집합(함수 14 + COMMON 20, 이름·크기 = M), 입력 사슬 07 = 스테이징 = run 사본, L1 `__text` 3820 B 가 0x408fd9e 에 놓이고 사유 없음, D109 격리 그대로.
7. 기록:
   - 상태표 `ACCEPTED` p523(예상 14 객체, 행 34/188, 바이트는 python)
   - PROVENANCE(`nextmach`, NeXTMach URL·커밋·경로, 네 함수의 바뀜은 이 프로젝트의 x86 07 판(plan 366, SHA-256 기록)에서 옴, NeXT 고지 유지, Darwin 글 없음)
   - MODIFICATIONS, DECISIONS D112, 근거 문서 `m68k-in_bootp.md`, diff(NeXTMach 대비) `m68k-in_bootp.diff`, 상태표 재현성
   - M7 의무: COMMON 20 개의 합침
관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 회귀 같음, x86 입력 불변.

### 523.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| "Darwin 글 없음" 은 단서가 필요. 네 함수는 D053 구역 밖이지만, 옮겨 오는 줄 가운데 Darwin 0.1 과 같은 줄이 있음 | Darwin `in_bootp.c:674` `printf("Network responded!\n");` = x86 07 `:595`; Darwin `:385` `htons(ip_id++)`, `:547` `htons(IPPORT_BOOTPS)`, `:562` `while (TRUE)` 도 같은 꼴(grep) | ✅ PROVENANCE·MODIFICATIONS 에 "NeXTMach 바탕 + 이 프로젝트 x86 판의 plan 366 줄(원본 바이트로 쓴 것), D053 구역은 들이지 않음, 몇 줄은 Darwin 0.1 과 같을 수 있음(D027)" 으로 적음 |
| §520 절차를 명시: x86 원본 리비전·해시, 07 파일과 `M4FILES` 를 같은 단계에서 등록, 상태표 앞 행 불변·출력 재현·기록 해시 | x86 07 `in_bootp.c` SHA-256 `5d87a7d1…`, 커밋 `ac383f78` | ✅ |
| `<bsd/dev/kmreg_com.h>` 는 다리 머리와 같은 `src/bsd/dev/kmreg_com.h` 로 풀리고, 그 머리에 `alert_key` 없음 | `-Isrc/src` 순서, 스테이징 grep 0 건 | ✅ |
| M5 205 줄에 `in_bootp` 없음 → M5 회귀 생략 타당 | `m5-517.cmd` grep 0 건 | ✅ |

### 523.2 결과(2026-10-26)

- 1–2: L(`08_build/artifacts/m4p523/src/in_bootp_L.c`)은 NeXTMach 대비 include 줄과 네 함수의 바뀜(14 군데)뿐입니다. 07 `src/machdep/m68k/in_bootp.c`(813 행, SHA-256 `00327a0e…`)는 주석을 뺀 토큰 3463 개와 지시문 줄이 L 과 같습니다.
- 3: `stage_m68k.py` 619 → 623 행.
  - `--plan 520` 재생성의 파일·`replaced`·`added`·`m4_sources`·`m4_headers` 가 `m0p520-a1-stage` 와 같습니다.
  - `--plan 523 stage m0p523-a1-stage`(912 파일)와의 차이는 `in_bootp.c` 하나입니다.
- 4: x86 입력 불변(`m4-x86-inputs-p523-20261026.json` ok; `--plan 523 x86gate` 일곱 묶음 `same`, v183 경로 0).
- 5: run `m4p523-p1`(4 명령 종료 0·경고 0·i386 머리 0, 옵션 = M5 줄; 기록 `09_validation/reconstruction/m4-m68k-probe-p523-20261026.json`).
  - F·L 모두 `candidate` 이고, 서로 그리고 M 과 canon·obj_sig 가 같습니다.
  - 함수별 15/15(F·L).
  - run `m4p523-e1`: `-E` 토큰 9840 개가 같습니다.
- 6: run `m4p523-a1`(REF = L `f7b65253…`; 기록 `m4-m68k-p523-final-20261026.json`). `gate` 모두 참, 객체 SHA-256 `adf20623…` = F.
  - python 확인(`m4-m68k-p523-checks-20261026.json`, `ok` 참): 정의(함수 14 + COMMON 20)가 M 과 같음, 입력 사슬 07 = 스테이징 = run 사본, L1 `__text` 3820 B 가 0x408fd9e 에 놓이고 바이트·참조 차이 0, 함수별 15/15, D109 격리, 옵션.
- 7:
  - 상태표 14 객체, 행 34/188, 11756 B(5.45%; python; `m4_m68k_status.py` 115 → 116 행, 앞 13 행 그대로, 두 번 돌린 출력 같음; 기록 `m4-m68k-status-p523-20261026.json`)
  - PROVENANCE 1123 → 1124 행(경로 중복 0), MODIFICATIONS 669 → 670 행, DECISIONS D112(115 → 116 행)
  - 근거 문서 `06_reconstruction/evidence/m68k-in_bootp.md`, diff `m68k-in_bootp.diff`(165 행)

