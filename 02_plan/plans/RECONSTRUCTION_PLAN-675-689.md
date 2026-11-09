# 커널 소스 복원 작업계획 — 보관 §675–689

`02_plan/RECONSTRUCTION_PLAN.md` 의 §675–689(m68k M4 `if_bus.c`(D157), `km.c`·공유 `kmreg.h`(D158), `od.c`(D159), `pmap.c`(D160), `ev.c`(D161); §680·§684 는 절 제목이 없고 §679·§683 안의 결과로 적혀 있음)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-03, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 675. M4-179 세부 계획 — m68k `if_bus.c`(행 258·259·260 일부) 진단 A1(07 변경 없음; 코딩 전, 2026-11-01)

고른 까닭: 받아들인 `zscom` 바로 뒤이고, NeXTMach 글이 있으며 함수가 작습니다(다음 후보 첫째).

확인한 사실(이번 세션; 원본 풀이 scratch `p675/ifbus.dis`(scratch `odis.py`, 원본 바이트); 수는 python):
- 범위 [0x408d9aa, 0x408db8a) 480 B, 일곱 항목: 이름 없는 0x408d9aa 42·0x408d9d4 140, `_enbuf_get` 74, `_engetbuf` 62, `_if_busalloc` 94, `_if_busfree` 32, `_if_rbusget` 36 — NeXTMach mk-108.1 `nextif/if_bus.c`(167 행, SHA-256 `aa9101d9…`, ASCII; 고지 없음)의 `enbuf_put`(41 행, 정적)·`enbuf_alloc`(53, 정적)·`enbuf_get`(79)·`engetbuf`(96)·`if_busalloc`(119)·`if_busfree`(143)·`if_rbusget`(153)와 차례가 같음.
- 끝: 0x408db8a·0x408dbd2·0x408dc16 의 이름 없는 셋은 NeXTMach 에 없는 1997 코드(`_copywithin` 을 되풀이해 부름)입니다. 원본 텍스트 전체를 python 으로 훑으면, 0x408dbd2 는 `_eninit`·`_en_rx_dmaintr`·`_en_tx_dmaintr`·`_encontrol`·`_enintsetup` 이, 0x408dc16 은 `_en_jam`·`_en_tx_dmaintr`·`_en_recv` 가 `bsrl` 로 부릅니다. 정적 함수는 같은 번역 단위에서만 불리므로 이 둘은 `if_en.c` 의 것입니다. 0x408db8a 는 부르는 곳이 없으나 같은 꼴(같은 무리)이라 `if_en.c` 쪽으로 봅니다. 그래서 `if_bus.c` 의 끝을 0x408db8a 로 둡니다(뒤 단위 `if_en.c` 에서 다시 확인).
- 1997 차이로 보이는 것: `_enbuf_get` 이 바깥 이름입니다(NeXTMach 78 행은 `static`). `if_en.c` 의 `_en_bufalloc`(0x408f5ec·0x408f604)가 부르므로 맞는 바뀜입니다. 나머지 여섯은 NeXTMach 꼴로 보입니다(`m_clalloc(1, 2, 0)`, `page_size`·`sizeof(struct enbuf)` 1582·`DMA_ENDALIGNMENT` 16 반올림, `nb_alloc_wrapper(buf, 1514, enbuf_put, buf)`, `end_bp` +28, `pmap_resident_extract(vm_map_pmap(mb_map), …)`).
- 구간: `span()` 은 `{"range": ["0x408d9aa", "0x408db8a"], "rows": [], "partial": ["m68k-258", "m68k-259", "m68k-260"], …}` 를 받음(python 시험: 259 만, 259·260 이면 멈춤). 덮은 행·바이트는 그대로.
- 자료: `__data` [0x40b244a, 0x40b245a) 16 B = `en_bufs`·`enbuf_allocated`·`enbuf_free`(0 셋, 0x408d9ba·0x408da28·0x408d9c6 등에서 씀)와 `enbuf_cutoff` 0x400(NeXTMach 20–28 행; 명시 초기화라 `__data`). 앞은 받아들인 `zscom` 의 `_zs_com`, 뒤 0x40b245a `_etherbcastaddr` 는 `if_en.c` 쪽. bss·문자열 없음(`DEBUG` 끔).
- 참조(원본 기호): `_m_clalloc` 0x4011de8, `_page_size` 0x40b06d0, `_nb_alloc_wrapper` 0x401c950, `_nb_map` 0x401c97a, `_nb_free_wrapper` 0x401c99e, `_pmap_resident_extract` 0x40987f8, `_mb_map` 0x40b5de8.
- 머리: NeXTMach import 16 줄(1–18 행). 스테이지(`m0p674-a1-stage`)에 없는 것은 NeXTMach 전용 `nextif/if_bus.h`(35 행, SHA-256 `8ff8ec3a…`) 하나입니다. `nextdev/dma.h` 는 07 의 1997 판(D119)이 스테이지에 있고, `machine/spl.h`·`net/netbuf.h`·`netinet/*`·`vm/vm_kern.h` 도 스테이지에 있습니다.

방법(진단; 07 은 바꾸지 않음; scratch `p675/gen_p675.py` → `08_build/artifacts/m4p675/`):
- 변형 A1: NeXTMach `if_bus.c` 그대로. 진단 `inc`: `nextif/if_bus.h`(NeXTMach 사본). include 줄은 모두 스테이지에 있는 경로라 바꾸지 않습니다.
- 명세: 바탕 `m0p674-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `if_bus`, 위 구간(`basis` 적음), `x86_rel` `machdep/i386/dkbad.c`. run `m4p675-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`), 기록 `m4-m68k-probe-p675-p1-20261101.json`, funcbytes `-p675-A1-`(대응 `0x408d9aa=_enbuf_put`·`0x408d9d4=_enbuf_alloc`, 자료 기준점은 원본에 이름이 없어 쓰지 않음 — `__data` 는 바이트로 견줌).
- 측정: 종료·경고, 함수별 바이트·재배치 대상, 객체에만 있는 함수, 절(`__text` 480·`__data` 16 목표), `__data` 를 재배치 없이 원본과, 기호(`_enbuf_get` 이 A1 에서는 지역이라 L1 이 이름 차이를 낼 것)·COMMON(D136)·미정의, 의존 출처(i386 0).

판정(미리 정함; 07 은 바꾸지 않음): A1 기대는 함수 바이트 7/7, `_enbuf_get` 만 지역/바깥 차이. 컴파일이 안 되면 원인을 적고 최소 고침의 새 변형을 새 run 으로. 함수가 다르면 원본 바이트로 다시 읽어 진단 B. 7/7 이면 진단 B(`static` 뺌)로 L1 까지 맞춘 뒤, 바이트로 가려지지 않는 꼴(`enbuf_get` 의 `static` 을 지우는 꼴, `if_bus.h` 의 07 자리)을 구현 전에 여쭙니다.

### 675.1 교차검토(codex `gpt-6.1-sol`, task klbib322t) 판정과 계획 수정

먼저 제 잘못: ① 호출처 훑기에서 `lea 절대주소,An; jsr (An)` 꼴을 a0 만 셌습니다(a1–a7 을 빠뜨림). 그래서 "0x408db8a 는 부르는 곳이 없다" 고 적었으나, 다시 훑으면 `_en_rx_devintr`·`_en_recv` 가 부릅니다. ② `if_rbusget` 의 인수를 잘못 읽어 "NeXTMach 꼴" 이라 적었습니다. 원본은 0x408db78 에서 `fp@(16)`, 0x408db7c 에서 `fp@(12)` 를 쌓아 `nb_alloc_wrapper(둘째 인수, 셋째 인수, enbuf_put, endp->end_bp)` 입니다. 부르는 쪽(0x408e3cc–0x408e3d4)도 인수 셋입니다. ③ "정적 함수는 같은 번역 단위에서만 불린다" 를 증명처럼 적었으나, 함수 포인터로 밖에 나갈 수 있습니다(`enbuf_put` 이 그 예). 부르는 쪽이 모두 `if_en.c` 라는 것은 강한 근거일 뿐 증명이 아닙니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0x408db8a 를 `_en_rx_devintr`·`_en_recv` 가, 0x408dbd2 를 `if_en.c` 함수 일곱이, 0x408dc16 을 셋이, `_enbuf_get` 을 `_engetbuf`·`_if_busalloc`·`_en_bufalloc` 이 부름(`lea` 꼴 포함) | python 으로 `lea abs.l,A0–A7`·`bsrl`·`jsr abs`·`pea abs` 를 다시 훑음 | ✅ 위 ① |
| "정적 함수는 같은 단위에서만" 은 증명이 아님; `linkw` 꼴은 지역 변수 때문이지 파일 표지가 아님; 그래도 끝 0x408db8a 를 강하게 뒷받침 | `ifbus.dis` 의 꼴 | ✅ 위 ③; 경계는 그대로 두되 `if_en.c` 단위에서 다시 확인 |
| 여섯 함수는 NeXTMach 와 대응; 크기 14·1582·28·+4·1514 | python(이번 세션: `etherdefs.h:70`, `mbuf.h:42–43`, `dma.h:52–63`) | ✅ |
| `_if_rbusget` 이 다름 — 1997 꼴 `if_rbusget(endp, buffer, totlen)` → `nb_alloc_wrapper(buffer, totlen, enbuf_put, endp->end_bp)`, 부르는 쪽 인수 셋, `if_bus.h:34` 원형도 다름 | `ifbus.dis` 0x408db66–0x408db88, `odis` 0x408e3cc–0x408e3d4, NeXTMach `if_en.c:383`(인수 둘) | ✅ 위 ②; A1 기대를 6/7 로 고치고 진단 B 에 넣음 |
| `__data` 16 B 의 값·차례가 맞고, NeXT GCC 2.7 은 명시적 0 초기화 정적을 `__data` 에 둠(`kernel_stack.c:99` 의 M5 객체) | 원본 덤프(이번 세션) | ⚖️ 값·차례는 ✅; `__data` 배치는 A1 객체의 절로 판정 |
| 머리는 모두 풀림, `pmap_resident_extract` 선언은 없음(암묵 `int`), `ip_timestamp` 충돌 없음(호스트 전처리) | `grep` 으로 스테이지 머리에 `pmap_resident_extract` 없음 확인; 나머지는 A1 컴파일로 판정 | ⚖️ |
| 함수 바이트·재배치 대상을 그대로 견줄 것; 자료 귀속·단위 경계는 추정으로 둘 것 | `m68k_funcbytes.py` 가 그 비교를 함 | ✅ |

계획 수정: 같은 run `m4p675-p1` 에 변형 둘을 넣습니다.
- A1: NeXTMach 그대로(기준). 기대는 6/7(`_if_rbusget` 다름), `_enbuf_get` 은 지역 이름.
- B: A1 에 두 가지를 바꿉니다. `enbuf_get` 의 `static` 을 빼고, `if_rbusget` 을 `(en_dmabuf_t endp, void *buf, int totlen)` 과 `nb_alloc_wrapper(buf, totlen, enbuf_put, (void *)endp->end_bp)` 로 씁니다. 진단 `inc` 의 `if_bus.h` 원형도 셋째 인수를 더한 진단 사본으로 둡니다(`B` 전용). 기대는 7/7 과 L1 의 이름 일치입니다.
이 두 변형은 07 을 바꾸지 않는 진단입니다. B 의 꼴은 위 원본 바이트(① 의 인수 차례)에서 나왔습니다. 이름(`buf`)과 꼴은 B 뒤에 여쭙니다.

2차 자기검사: ✅ 행은 이번 세션의 python·풀이 줄입니다.

### 675.2 결과(run `m4p675-p1`, 2026-11-01)

- A1·B 컴파일 종료 0·경고 0, 의존 i386 0(`m4-m68k-probe-p675-p1-20261101.json`). 절은 `__text` 480(재배치 24)·`__data` 16(재배치 0) 둘뿐이고, `__data` 16 B 가 원본 0x40b244a 의 바이트와 같습니다(`en_bufs`·`enbuf_allocated`·`enbuf_free`·`enbuf_cutoff` 지역 기호가 +0·+4·+8·+12).
- funcbytes(대응 `0x408d9aa=_enbuf_put`·`0x408d9d4=_enbuf_alloc`, 자료 기준점 넷은 원본에 이름이 없어 추정 — 객체의 지역 기호 자리와 원본 접근 자리가 맞음): A1 **6/7**(`_if_rbusget` 만 바이트 3 다름), B **7/7**(`m4-m68k-funcbytes-p675-A1/B-20261101.json`). A1 의 L1 은 `_enbuf_get` 이 빠진 이름으로 NOT_MATCH, B 는 L1 `OBJECT_MATCH`·사유 없음·`full_span`.
- 단언(scratch `p675/chk_p675.py`; `m4-m68k-p675-diagchecks-20261101.json`, `ok`): 바깥 정의는 B 다섯(`_enbuf_get` 포함)이 원본 자리, 지역은 함수 둘·자료 넷, COMMON 23 은 공유 머리에서 와 D136 통과, 미정의 일곱(`_m_clalloc`·`_mb_map`·`_nb_*` 셋·`_page_size`·`_pmap_resident_extract`) 모두 원본 이름, `nextdev/dma.h` 는 07 판, `if_bus.h` 는 진단 사본.

판정(미리 정한 대로): 바이트로 가려지지 않는 꼴을 구현 전에 여쭙니다.

## 676. M4-180 D157 구현 계획 — 07 `src/machdep/m68k/if_bus.c`, 07 `nextmach/nextif/if_bus.h`(코딩 전, 2026-11-01)

사용자 결정(D157 로 적을 것; AskUserQuestion 셋): ① `if_rbusget` 의 새 둘째 인수는 `caddr_t buf`(추천안 `void *buf` 가 아님; 진단 B 의 꼴이 아니므로 확인 run 에서 바이트를 봄) ② `enbuf_get` 은 `static` 만 지움(추천안) ③ `if_bus.h` 는 07 `nextmach/nextif/if_bus.h`(NeXTMach 사본, D104)에서 34 행 원형만 셋째 인수를 더한 꼴로 고침(추천안). NeXTMach `if_bus.c`·`if_bus.h` 에는 고지가 없습니다(1 행부터 `#import`; `if_bus.h` 는 SCCS 줄 하나).

1. 07 `nextmach/nextif/if_bus.h`(scratch `p675/gen_p676.py --write`): NeXTMach `nextif/if_bus.h`(SHA `8ff8ec3a…`)의 34 행을 `netbuf_t if_rbusget(en_dmabuf_t, caddr_t, int);` 와 표시 `plan 676 (D024, D157)` 로. 단언: 진단 B 사본과 주석을 뺀 토큰이 `void *` ↔ `caddr_t` 만 다름.
2. 07 `src/machdep/m68k/if_bus.c`(같은 생성기): NeXTMach `if_bus.c`(SHA `aa9101d9…`) 앞에 머리 주석 덩이(바뀜 목록·사용자 결정; 고지가 없음을 적음) + 바뀜 셋(`enbuf_get` 의 `static` 지움, `if_rbusget` 의 `caddr_t buf` 인수, `nb_alloc_wrapper(buf, …)`; 표시 `plan 676 (D024, D157)`). include 줄은 그대로(모두 스테이지 경로). 단언: 진단 B 와 토큰이 `void *` ↔ `caddr_t` 한 곳만 다름; L(`08_build/artifacts/m4p676/src/if_bus_L.c`)과 F 의 토큰·토큰 줄 같음; 표시 없는 바뀐 줄 0.
3. `stage_m68k.py`: `M4FILES[676] = list(M4FILES[674]) + ['if_bus.c']`, `M4HEADERS[676] = list(M4HEADERS[674]) + [('nextif/if_bus.h', 'src/bsd/nextif/if_bus.h')]`, `EXCEPTS[676] = dict(EXCEPTS[674])`, 머리말 목록.
4. 회귀: `--plan 674` 재생성(`m0p674-r676-stage`) 매니페스트가 보관 `m0p674-a1-stage` 와 바이트까지 같음; `m0p676-a1-stage` 는 그것과 `if_bus.c`·`if_bus.h` 만(키 `files`·`m4_headers`·`m4_sources`·`plan`); `m5-674.cmd` 보관본과 같음, `m5-676.cmd` 는 계획 번호만; M5 205(`m3p676-b674` 보관 674 스테이지·`--plan 674 compare`, `m3p676-cc1`·`--plan 676`) 객체·출력 같음; x86 입력 `ok` 이고 p674 와 같음·`--plan 676 x86gate` 일곱 같음.
5. 확인 run `m4p676-p1`(명세 `08_build/artifacts/m4p676/confirm/spec.json`, 바탕 `m0p676-a1-stage`): F·L 종료 0·경고 0·i386 0, 7/7, L1 `OBJECT_MATCH`·`full_span`, F = L(canon·`obj_sig`), F 와 진단 B 객체는 canon 같음·`obj_sig` header·sections·symbols 같음(STABS 는 인수 형 `caddr_t` 로 달라도 됨), `chk_p675.py`(7, 출처 `07_kernel/nextmach/nextif/if_bus.h`) F·L `ok`. `-E` run `m4p676-e2`(F·L): 토큰 F = L, stderr 0, i386 0.
6. 최종 run `m4p676-a1`(명세 `08_build/artifacts/m4p676/spec.json`, F 만, `refs` = p1 L, 명령 파일 `probe.cmd`): `gate.ok`, OBJECT_MATCH, funcbytes 7/7. 확인 기록 `m4-m68k-p676-checks-20261101.json`(의존 SHA 사슬·선택지 = M5 줄·07 = 스테이지·e2·p1 `ok`).
7. 상태: `ACCEPTED` 에 두 칸 하나. 근거 `06_reconstruction/evidence/m68k-if_bus.md`·`m68k-if_bus.diff`·`m68k-if_bus_h.diff`(새) 를 먼저. 상태 도구 두 번, 기대(python): 객체 59(OBJECT_MATCH 47, CODE+BSS_INFERRED 12), 행 78/188, 78566 B(36.39%) 그대로, `object_bytes` 120610, 부분 행에 `m68k-260` 이 더해짐.
8. 기록: PROVENANCE(새 `if_bus.c`·`if_bus.h` 두 행), MODIFICATIONS, DECISIONS D157, 계획·HANDOFF·메모리. M7: `if_en.c` 가 `enbuf_get`·`if_rbusget`(인수 셋)·`engetbuf` 를 부름, COMMON 합침, 호출 대상(`m_clalloc`·`nb_*`·`pmap_resident_extract`).

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, 확인·`-E`·최종·확인 기록 `ok`, 상태 도구가 기대와 같음. `caddr_t` 꼴이 바이트가 다르면 멈추고 여쭙니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 676.1 교차검토(codex `gpt-6.1-sol`, task krsahs165) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `caddr_t`(`types.h:103` `char *`)를 `nb_alloc_wrapper(void *data, …)`(`netbuf.h:22`)에 넘기는 것은 암묵 변환이라 경고 없고 같은 코드일 것; 원형의 `caddr_t` 는 `sys/param.h:193` → `sys/types.h` 가 `if_bus.h` 보다 먼저 들어와 선언됨 | 세 줄을 열어 봄 | ✅(바이트·경고는 확인 run 이 판정) |
| 상태 기대 59·47·12·78/188·78566·36.39%·120610, 부분 행은 `m68k-260` 하나만 더해짐 | python(현재 상태 기록 + 480; `m68k-260` 이 아직 없음) | ✅ |
| 재생성 674 매니페스트는 보관본과 바이트까지 같을 것(매니페스트에 대상 이름·도구 해시 없음, `stage_m68k.py:626`); 스테이지에 `src/bsd/nextif` 없음; x86 매니페스트에 `nextif` 없음 | 그 줄을 열어 봄, `find`(이번 세션) | ✅(x86 은 회귀의 `x86gate` 로 판정) |
| F 대 B 는 canon + header·sections·symbols(STABS 수 제외)로; `-E` 에 B 를 넣어 F 와 견주려면 정의와 머리 원형 두 곳의 형 바꿈을 허용해야 함 | B 원천 155 행, B 머리 34 행 | ✅ `-E` 에 B 를 넣고, F 토큰은 B 토큰에서 `void *` → `caddr_t` 를 두 곳(정의·원형)만 바꾼 것과 같아야 함 |
| PROVENANCE 는 일곱 칸 두 행, 고지 없음은 `nextdbgasm.s` 꼴("the NeXTMach file has no notice", `PROVENANCE.tsv:1135`), `if_bus.h` 의 SCCS 줄은 남김; 근거 파일 이름은 `m68k-if_bus.md`(`m4_m68k_status.py:191`) | 그 줄들을 열어 봄 | ✅ |

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 676.2 결과(2026-11-01)

- 1–2 07 `nextmach/nextif/if_bus.h`(34 행 원형만 바뀜, SHA `67b52899…`), 07 `src/machdep/m68k/if_bus.c` 180 행(SHA `8442a034…`), L `08_build/artifacts/m4p676/src/if_bus_L.c`(scratch `p675/gen_p676.py --write`; 진단 B 와 토큰이 인수 형 한 곳(머리는 원형 한 곳)만 다름·F = L 토큰과 토큰 줄·표시 없는 바뀐 줄 0 단언). 3 `stage_m68k.py` 767 → 770 행.
- 4 회귀: `--plan 674` 재생성 매니페스트가 보관본과 바이트까지 같음; `m0p676-a1-stage`(1005)는 `if_bus.c`·`if_bus.h` 만(키 `files`·`m4_headers`·`m4_sources`·`plan`). `m5-674.cmd` 보관본과 같고 `m5-676.cmd` 는 계획 번호만. M5 205(`m3p676-b674`·`m3p676-cc1`) 접두어를 맞추면 객체·출력 모두 같음, `m3p676-b674` 는 `m3p674-cc1` 과 같음; `compare` 둘 `differ_unexpected`·`lost` 빔. x86 `m4-x86-inputs-p676-20261101.json` `ok`(p674 와 같음), `--plan 676 x86gate` 는 `plan`·도구 해시만 다름.
- 5 확인 run `m4p676-p1`(`m4-m68k-p676-p1checks-20261101.json` `ok`): F·L 7/7·경고 0·OBJECT_MATCH·`full_span`, `chk_p675.py`(출처 07 `if_bus.h`) F·L `ok`, F = L, F 와 진단 B 객체가 canon·`obj_sig` 전부 같음(`caddr_t` 꼴이 바이트로 같음). `-E` `m4p676-e2`(`ok`): F = L = B(인수 형 한 곳을 맞춘 뒤) 7633 토큰, stderr 0.
- 6 최종 run `m4p676-a1`(`m4-m68k-p676-final-20261101.json`, SHA `879c58b7…`): `gate.ok`, 7/7. 확인 `m4-m68k-p676-checks-20261101.json`(`ok`; 의존 87·SHA 사슬·선택지 = M5 줄·07 = 스테이지). 객체 SHA `a10d4fd6…`.
- 7 상태(`m4-m68k-status-p676-20261101.json`, 표 60 → 61 행; scratch 에 두 번 같음): 객체 59(OBJECT_MATCH 47, CODE+BSS_INFERRED 12), 행 78/188, 78566 B(36.39%), `object_bytes` 120610, 부분 행에 `m68k-260` — 미리 계산한 값과 같음. 근거 `m68k-if_bus.md`·`m68k-if_bus.diff`·`m68k-if_bus_h.diff`.
- 8 기록: PROVENANCE 1218 → 1220 행(일곱 칸, 겹침 없음), MODIFICATIONS 753 → 754, DECISIONS D157(160 → 161 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D157).

## 677. M4-181 세부 계획 — m68k `km.c`(행 223–226) 진단 A1(07 변경 없음; 코딩 전, 2026-11-01)

고른 까닭(python 으로 후보를 견줌): `if_en.c`(행 260)는 1997 함수 여덟(`en_rx_devintr`·`en_tx_guard`·`en_send`·`en_xmit` 등)과 이름 없는 정적 셋이 NeXTMach 에 없어 원본 바이트로 새로 쓸 양이 큽니다. `zs.c` 는 이름 없는 항목이 53 개입니다. `km.c` 는 항목 44 가운데 42 가 NeXTMach 글에 대응하고, 네 행이 모두 정확한 행이라 받아들이면 덮은 행이 늡니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p677/km.dis`; 수는 python):
- 범위 [0x406f0fe, 0x4072264) 12646 B = 정확한 행 223(5132)·224(114, 미배정)·225(92, x86 이름 `kmDevice` 꼴)·226(7308). 앞은 받아들인 `fd_subr`(행 222)이고, 뒤 0x4072264 `_mmopen` 은 `next/mem.c` 의 것입니다.
- 항목 44 개(이름 42, 이름 없음 2). NeXTMach mk-108.1 `nextdev/km.c`(2130 행, SHA-256 `6091238d…`)의 정의 42 개 가운데 40 개가 이름으로 대응하고, 정의 차례도 같습니다. 이름 없는 0x40705d8 은 정적 `special_key_process`(943 행), 0x4071a12 는 정적 `km_read_pcode`(1702 행)입니다. 1997 에만 있는 이름은 `_kmgetc_silent`(0x407050a, 114 B; `kmgetc` 와 `kmtrygetc` 사이)와 `_km_reset`(0x407077c, 78 B; `km_send` 와 `km_drawrect` 사이) 둘입니다. NeXTMach 에만 있는 `kmintr`(805 행)는 `#ifdef NOEVDRIVER` 안이라 빠집니다.
- 자료: `__data` [0x40b1bba, 0x40b1bce) 20 B — `_reconnect`(0x40b1bba)·정적 `km_access_stack`(+4)·`_mach_title`(0x40b1bc2) 뒤에 8 B 가 더 있습니다(1997 덧붙임으로 보임; A1 이 판정). 뒤 0x40b1bce `_np_copyright` 는 받아들인 `np` 의 것입니다. `__bss` 참조는 없습니다. COMMON 참조가 많습니다(`_km` 106 B·`_km_coni`·`_cons`·`_mon_global`·`_evg`·`_eventsOpen`·`_curBright`·`_eventTask` 등). 문자열은 0x40aa60c–0x40aa69c 쪽을 참조하며, 블록 경계는 A1 객체의 `__cstring` 을 원본에서 찾아 정합니다.
- 머리: NeXTMach import 42 줄(56–97 행). 스테이지(`m0p676-a1-stage`)와 선례 대응은 이렇습니다.
  - 스테이지 경로 그대로: `sys/*`·`kern/*`·`vm/*`·`machine/spl.h`·`mon/global.h`·`next/event_meter.h`·`nextdev/kmreg.h`·`nextdev/dma.h`·`next/cpu.h`(스테이지의 NeXTMach 사본, D109).
  - 선례대로 바꿈(D104): `next/psl.h` → `m68k/psl.h`, `next/bmap.h` → `m68k/bmap.h`, `next/eventc.h` → `machdep/m68k/eventc.h`, `next/cons.h` → `m68k/cons.h`, `nextdev/monreg.h` → `dev/m68k/monreg.h`, `nextdev/video.h` → `dev/m68k/video.h`, `nextdev/nbicreg.h` → `architecture/m68k/nbicreg.h`, `nextdev/busvar.h` → `dev/busvar.h`, `nextdev/event.h` → `dev/event.h`(스테이지에 있음).
  - 스테이지에 없음: `next/scr.h`, `next/trap.h`, `nextdev/td.h`, `nextdev/ev_vars.h`(NeXTMach 만), `nextdev/keycodes.h`(1997 SDK `bsd/dev/m68k/keycodes.h`, 실기 목록 SHA `952889f9…` = 로컬 미러), `nextdev/ohlfs12.h`(07 `nextmach/nextdev/ohlfs12.h` 가 NeXTMach 그대로 있으나 m68k 스테이징에는 아직 없음).

방법(진단; 07 은 바꾸지 않음; scratch `p677/gen_p677.py` → `08_build/artifacts/m4p677/`):
- 변형 A1: NeXTMach `km.c` + 위 "선례대로 바꿈" 아홉 줄(진단 표시). 스테이지에 없는 여섯은 진단 `inc` 사본으로 둡니다: `next/scr.h`·`next/trap.h`·`nextdev/td.h`·`nextdev/ev_vars.h`(NeXTMach), `nextdev/keycodes.h`(SDK 미러), `nextdev/ohlfs12.h`(07 사본). 이 사본들이 원본에 없는 COMMON 을 낳을 수 있습니다(§505·§507 의 `next/scr.h`). 그것은 기록하고 B 에서 다룹니다.
- 컴파일이 안 되면 오류가 가리키는 것만 최소로 고친 A1B 를 새 run ID 로 돌립니다(변형 이름은 대문자).
- 명세: 바탕 `m0p676-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `km`, `m4_id` `["m68k-223", "m68k-224", "m68k-225", "m68k-226"]`(맞닿은 정확한 행 목록, `span()` 이 받는지 python 으로 먼저 시험), `x86_rel` `machdep/i386/dkbad.c`. run `m4p677-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`), funcbytes `-p677-A1-`(대응 `0x40705d8=_special_key_process`·`0x4071a12=_km_read_pcode`; `__data` 기준점 `0x40b1bba=_reconnect`·`0x40b1bc2=_mach_title`).
- 측정: 종료·경고, 함수별 바이트·재배치 대상, 객체에만 있는 함수, 절 크기(`__text` 12646 목표·`__data` 20·`__cstring`·`__bss`), 문자열 블록을 원본에서 찾음, 기호·COMMON(D136)·미정의, 의존 출처(i386 0).

판정(미리 정함; 07 은 바꾸지 않음): A1 결과를 적고, 다른 함수마다 원본 바이트로 바뀜을 읽어 다음 진단을 세웁니다. 44/44 와 함수 밖 단언이 맞으면 바이트로 가려지지 않는 꼴을 구현 전에 여쭙니다.

### 677.1 교차검토(codex `gpt-6.1-sol`, task ks6frc8od) 판정과 계획 수정

먼저 제 잘못: ① `km.c` 의 `__data` 를 [0x40b1bba, 0x40b1bce) 20 B 로 적었습니다. 실제로는 [0x40b14b2, 0x40b1bca) 1816 B 입니다. 이는 `ohlfs12` 글꼴 1152 B(`nextdev/ohlfs12.h:9`)와 `ascii` 표 648 B(`nextdev/keycodes.h:69`), 그리고 `reconnect`·`km_access_stack`·`mach_title`·`km_vm_is_up`(`km.c:1631`, 함수 안 정적) 16 B 로 이루어집니다. 끝 0x40b1bca 의 낱말은 `monitor.s` 의 `minit`(07 `monitor.s:26`)입니다. ② 정의 수를 "42" 로 적었는데, 글로 된 정의는 43 이고 `NOEVDRIVER` 를 끄면 42 입니다. ③ 머리 의존을 덜 봤습니다: `km.c:1687` 의 따옴표 `#include "nextdev/km_pcode.h"`(probe 가 거부, `m4_m68k_probe.py:136`), `ev_vars.h:29–31` 이 들이는 `nextdev/event.h`·`evio.h`·`evsio.h`, 그것들이 들이는 `sys/port.h`·`sys/message.h`(스테이지에 없음, `mach/` 아래에 있음), 그리고 `EACCESS`(`km.c:216·755`)를 놓쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·44 항목·차례 맞음; 0x40705d8 = `special_key_process`(`_DoSpecialKey` 부름, `_kybd_process` 가 부름), 0x4071a12 = `km_read_pcode`(`_km_try_slot`·`_km_run_pcode` 가 부름); 정의 43(`NOEVDRIVER` 끄면 42) | 함수 표·NeXTMach 정의 python 대응(이번 세션) | ✅(호출처 주소는 A1 비교가 확인) |
| `__data` 는 [0x40b14b2, 0x40b1bca) 1816 B(글꼴 1152·`ascii` 648·전역/정적 16), 0x40b1bc6 = `km_vm_is_up`, 0x40b1bca = `monitor.s` `minit` | 기호 표(`_ohlfs12` 0x40b14b2·`_ascii` 0x40b1932·`_reconnect`·`_mach_title`), 원본 20 B 덤프, python 크기, 07 `monitor.s:26–34` | ✅ 위 ① |
| 문자열 블록 [0x40aa5f1, 0x40aa6ce) 221 B(제목·`%L`·전원 끄기 물음·종료 알림·p-code 오류 둘), 앞 `fd_sectsize_max`·뒤 `mmrw` | 원본 `__cstring` 덤프(이번 세션) | ✅ |
| 진단 사본 여섯은 가려지지 않음 | 스테이지 `-I` 뿌리 모두에서 `find`(이번 세션) | ✅ |
| `km.c:1687` 따옴표 include 는 probe 가 거부, `km_pcode.h` 는 스테이지에 없음 | 그 줄, `m4_m68k_probe.py:136` | ✅ A1 에서 `#import <nextdev/km_pcode.h>` 로 바꾸고(진단 표시) NeXTMach 사본을 `inc` 로 |
| `ev_vars.h` 는 옛 `event.h`·`evio.h`·`evsio.h` 를 들이고, SDK 판으로 바꾸면 이름이 맞지 않음; SDK `dev/event.h` 에는 `NX_NEXT*KEYMASK` 가 없음 | `ev_vars.h:29–31`; `NX_NEXTLALTKEYMASK` 는 NeXTMach `nextdev/event.h:103` 과 SDK `bsd/dev/m68k/event.h:128` 에 있음 | ⚖️ A1 은 `nextdev/event.h` 를 바꾸지 않고 NeXTMach `event.h`·`evio.h`·`evsio.h`·`ev_vars.h` 를 모두 진단 사본으로 둡니다(옛 사슬 그대로). `evio.h`·`evsio.h` 의 `sys/port.h`·`sys/message.h` 는 사본 안에서 `mach/port.h`·`mach/message.h` 로 바꿉니다(진단 표시; 스테이지에 있음). 1997 의 꼴은 A1 뒤에 정함 |
| `EACCESS`(216·755 행)는 스테이지 errno 에 없음 | NeXTMach 의 정의는 `mon/tftp.h:57` 의 TFTP 오류 번호 2(07 `mon/global.h` 는 D133 에서 `tftp.h` 를 빼서 들어오지 않음); 원본은 `_kmopen` 0x406f254·`_kmioctl` 0x40701be 에서 13(`EACCES`)을 돌려줌 | ✅ 1997 바뀜. A1 에서 두 곳을 `EACCES` 로(진단 표시) |
| `scr.h`·`trap.h` 의 형 충돌·`keycodes.h` 중복 없음; SDK 와 NeXTMach `keycodes.h` 는 바이트까지 같음; 스테이지 `next/cpu.h` 는 C 선언이 있으나 임시 정의 전역을 만듦 | `cmp`(이번 세션, 같음) | ✅ `keycodes.h` 는 SDK 미러 사본을 그대로 씀; 원본에 없는 COMMON 은 A1 기록에 적음 |
| `_kmgetc_silent` 는 `kmgetc` 에서 `cnputc` 메아리를 뺀 꼴, 입력 셋이 `_adb_check_keyboard` 를 부름, `_km_reset` 은 NMI 를 지우고 키보드 폴링을 설정한 뒤 지연 | 직접 읽지 않음 | ⏭️ B 를 세울 때 원본 바이트로 다시 읽음 |
| 계획에 p-code 머리·옛 event 사슬·자료 범위·두 표의 기준점을 넣을 것; `span()` 의 네 행 목록은 그대로 됨 | 위 확인, `span()` python(이번 세션) | ✅ |

계획 수정(A1): 위 따옴표 include·`EACCES` 두 곳을 진단 표시로 바꾸고, `inc` 를 열 개로 둡니다(`next/scr.h`·`next/trap.h`·`nextdev/td.h`·`nextdev/ev_vars.h`·`nextdev/event.h`·`nextdev/evio.h`·`nextdev/evsio.h`·`nextdev/km_pcode.h`(NeXTMach), `nextdev/keycodes.h`(SDK 미러), `nextdev/ohlfs12.h`(07)). `nextdev/event.h` 는 바꾸는 줄에서 뺍니다. 측정 목표를 `__data` 1816 B·`__cstring` 221 B 로 고치고, funcbytes 자료 기준점에 `0x40b14b2=_ohlfs12`·`0x40b1932=_ascii` 를 더합니다.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 677.2 A1 결과(run `m4p677-p1`)와 진단 A1B 계획(07 변경 없음; 코딩 전, 2026-11-01)

A1 은 컴파일에 실패했습니다(종료 1, `00.err`). 원인은 둘입니다.
- ① 진단 사본 `nextdev/keycodes.h:63` 의 `#define right 0x105` 가, 뒤에 `ev_vars.h:30` → `kern/kern_port.h` → `ipc/ipc_port.h` 로 들어오는 `ipc/ipc_object.h:177` 의 인수 이름 `right` 를 바꿉니다(파싱 오류).
- ② NeXTMach `evio.h:57·61` 의 `Point`·`Bounds` 가 SDK `dev/m68k/video.h:96·100` 의 같은 이름과 충돌합니다.
- 그 밖에 `km_drawrect` 의 `kfree` 경고 둘이 있습니다(1990 `kfree` 선언과 1997 머리 사이; `sd` 의 known_warnings 와 같은 꼴, D121·D153).

원본 바이트가 보이는 1997 의 꼴(python·풀이):
- `km.c` 의 COMMON 참조는 `_evg`(0x40c3640)·`_eventsOpen`(0x40c32d8)·`_curBright`(0x40c3324)·`_eventTask`(0x40c363c) 입니다. NeXTMach `km.c:1562–1569` 의 `evp->cursorSema` 자리(`_alert_lock_screen`, 0x40717e0–0x4071808)는 `evg` 를 읽어 그 +20 에 접근합니다.
- 이 +20 은 1997 SDK `bsd/dev/m68k/evio.h` 의 `EvGlobals` 의 `cursorSema`(앞에 `short` 넷 8 B + `int` 셋 12 B)와 맞습니다. 그 머리의 이력 줄은 "28Nov90 Ted Renamed EventGlobals -> EvGlobals, eventGlobals -> evg" 입니다. NeXTMach 의 `EvVars.cursorSema` 는 +0 입니다.
- SDK `bsd/dev/m68k/evio.h`·`event.h` 의 SHA 는 실기 목록과 같습니다(python). 두 머리와 SDK `video.h` 는 `__Point__`·`__Bounds__` 지킴이를 함께 써서 겹치지 않습니다. SDK `m68k/event.h:128` 에 `NX_NEXT*KEYMASK` 가 있습니다.

변형 A1B(A1 에서 바꾸는 것; 진단 표시):
- `#import <nextdev/event.h>` → `#import <bsd/dev/m68k/event.h>`.
- `#import <nextdev/ev_vars.h>` → `#import <bsd/dev/m68k/evio.h>` + 진단 선언 넷 `extern int eventsOpen; extern task_t eventTask; extern int curBright; extern EvGlobals *evg;`. 이 넷은 `km.c` 가 `ev_vars.h` 에서 쓰는 이름 전부입니다(python 으로 추림; `evp` 는 아래처럼 바꿈).
- `km.c:1562–1569` 의 `evp->cursorSema` 셋 → `evg->cursorSema`.
- 진단 `inc`: NeXTMach `ev_vars.h`·`event.h`·`evio.h`·`evsio.h` 를 빼고, SDK `bsd/dev/m68k/event.h`·`evio.h` 미러 사본을 더합니다. 나머지(`next/scr.h`·`next/trap.h`·`nextdev/td.h`·`nextdev/km_pcode.h`·`nextdev/keycodes.h`·`nextdev/ohlfs12.h`)는 그대로입니다.
- run `m4p677-p2`(새 ID). 판정은 §677 과 같습니다. 컴파일되면 함수별 바이트를 재고, 다른 함수는 원본 바이트로 다시 읽습니다.

### 677.3 A1B 결과(run `m4p677-p2`, 2026-11-01)와 다음 일

- A1B 컴파일 종료 0·경고 0, 의존 i386 0(`m4-m68k-probe-p677-p2-20261101.json`). A1 의 `kfree` 경고 둘은 사라졌습니다.
- 절: `__text` 11992(원본 12646, 654 B 짧음)·`__data` 1816(원본과 같은 크기)·`__cstring` 221(원본과 같은 크기). `__bss` 는 없습니다.
- `__data` 차례가 다릅니다. 객체는 `ascii`(+0)·`ohlfs12`(+648) 차례이고, 원본은 `ohlfs12` 0x40b14b2·`ascii` 0x40b1932 입니다. NeXTMach `km.c` 는 `keycodes.h`(88 행)를 `ohlfs12.h`(89 행)보다 먼저 들이므로, 1997 판은 이 둘을 반대 차례로 들인 것으로 보입니다. 그 뒤 `reconnect`·`km_access_stack`·`mach_title`·`km_vm_is_up.94` 는 원본 차례와 같습니다.
- COMMON 35 개 가운데 스테이지 NeXTMach `next/cpu.h`·`next/scr.h` 에서 온 것(`_scr1`·`_scr2`·`_disk_chip`·`_bmap_chip`·`_cpu_type`·`_brightness` 등)은 원본에 있는지 D136 으로 따로 봐야 합니다(§505·§507 의 `_scr1`·`_disk_chip`).
- funcbytes(`m4-m68k-funcbytes-p677-A1B-20261101.json`; 대응·기준점 scratch `p677/maps.txt`): **24/44**. 같음은 `kminit`·`kminit2`·`kmclose`·`kmread`·`kmwrite`·`kmselect`·`km_input`·`reconpoll`·`kmputc`·`special_key_process`·`kybd_process`·`km_send`·`km_drawrect`·`km_eraserect`·`km_clear_win`·`km_clear_screen`·`alert`·`alert_done`·`alert_lock_screen`(`evg` 꼴 확인)·`km_power_down`·`km_read_pcode`·`km_try_slot`·`km_begin_access`·`km_convert_addr` 입니다.
- 다름 20: 길이가 다른 것은 `kmopen`·`kmstart`·`kmoutput`·`kmpopup`·`kmrestore`·`kmioctl`·`kmgetc`·`kmtrygetc`·`kmpaint`·`km_flip_cursor`·`km_clear_eol`·`km_switch_to_vm`·`km_select_console`·`km_end_access`·`km_run_pcode` 입니다. 1997 새 함수 `kmgetc_silent`·`km_reset` 은 객체에 없습니다. 바이트만 다른 것은 `km_big`, 재배치 대상만 다른 것은 `km_autorepeat`·`kmintr_process` 입니다.
- 첫 풀이에서 본 것: `kmgetc`·`kmtrygetc` 는 1997 판이 첫머리에서 어떤 함수(codex 는 `_adb_check_keyboard` 로 읽음; 아직 내가 확인하지 않음)를 불러 0 이 아니면 건너뛰고, 읽은 값을 넘길 때 전역 주소를 `pea` 로 넘깁니다. `km_end_access` 는 판단 꼴이 다릅니다(`cpusha dc` 앞의 조건).
- 도구 메모: scratch `fdiff.py` 는 객체의 재배치 피연산자(작은 절 오프셋)를 `ABS` 로 바꾸지 않아, 재배치 자리가 차이로 보입니다. 판정은 `m68k_funcbytes.py`(재배치 대상까지 견줌)로 하고, `fdiff` 는 꼴을 읽는 데만 씁니다.

다음 일(§678): 다른 20 함수를 원본 바이트로 하나씩 읽어 1997 바뀜 목록을 세웁니다. `__data` 차례(`ohlfs12.h` 먼저)와 COMMON 출처도 함께 봅니다. 그 뒤 진단 B 를 세우고 codex 로 교차검토합니다.

## 678. M4-182 조사 결과와 세부 계획 — `km.c` 진단 B(1997 바뀜; 07 변경 없음; 코딩 전, 2026-11-01)

도구: scratch `p677/rdiff.py`(새로 씀). 원본과 A1B 객체의 함수를 재배치까지 이름으로 풀어 견주는 diff 입니다. 판정은 여전히 `m68k_funcbytes.py` 로 합니다. 참고: x86 07 `bsd/dev/i386/km.m`(x86 바이트로 확인된 OPENSTEP 4.2 판, Apple 글에 "lifted from 68k km.c")에 1997 꼴 `kmgetc_silent`·`ttynty` 를 쓰는 `kmoutput`·`selthreadclear`·`t_winsize` 채우기·`KMIOCSIZE` 등이 있습니다. 1997 SDK `bsd/dev/kmreg_com.h` 에 `KMIOCDISABLCONS`(_IO k 8)·`KMIOCANIMCTL`(_IOW k 9)·`KMIOCSTATUS`(_IOR k 10)·`KMIOCSIZE`(_IOR k 11)·`KM_ANIM_STOP/SUSPEND/RESUME`·`KMS_SEE_MSGS` 가 있습니다.

원본 바이트로 읽은 1997 바뀜(함수 순서; 원본 자리는 `rdiff` 출력 scratch `p677/diff20.txt`):
- ① `kmopen`: `tp->t_state |= TS_CARR_ON`(원본 `orl #16`; NeXTMach 는 `= TS_ISOPEN|TS_CARR_ON`). `l_open` 을 부른 뒤 결과를 그대로 돌려주기 전에 `t_winsize` 의 `ws_col = km.nc_w`·`ws_row = km.nc_h`·`ws_xpixel = KM_VIDEO_W`·`ws_ypixel = KM_VIDEO_H` 를 이 차례로 씁니다(오프셋 92·90·94·96; 결과 검사 없음). `EACCES` 는 A1 에서 바꿈.
- ② `kmstart`·`kmoutput`·`km_autorepeat`·`kmintr_process`: `softint_sched` → `callout_dispatch`(같은 인수 꼴 `(0, fn, arg)`; 선언은 `dma.c:75` 선례 `extern void callout_dispatch();`). `kmstart`·`kmoutput` 의 `tp->t_wsel = 0` → `selthreadclear(&tp->t_wsel)`(07 `tty_pty.c` 선례).
- ③ `kmoutput`: `struct nty *np = ttynty(tp)` 다음 `cc = -1`, 그다음 `s = spltty()`(IPL 1). 조건은 `(t_flags & (RAW|LITOUT|PASS8OUT)) || (np->t_pflags & TP_OPOST) == 0 || (np->t_pflags & TP_CSIZE) == TP_CS8` 일 때 `ndqb(…, 0)` 입니다(원본 `andil #0x2200020`·`btst #28`·`&0x300 == 0x300`; x86 07 `km.m:403–407` 꼴). 끝에서 `splx(s)`.
- ④ `km_big`: `kmem_alloc_wired(kernel_map, &km.store2, i)`(돌려준 값 검사 없음).
- ⑤ `kmrestore`: 앞의 `km_begin_access()` 만 없습니다(뒤 `km_end_access()` 는 남음; 원본 그대로 짝이 맞지 않음).
- ⑥ `kmioctl`: NeXTMach 여섯 경우 뒤에 `KMIOCSTATUS`(`suser()` 아니면 `EACCES`, `KMF_SEE_MSGS` 면 `KMS_SEE_MSGS`)·`KMIOCDRAWRECT`/`ERASERECT`(그대로)·`KMIOCDISABLCONS`(`km.flags &= ~KMF_SEE_MSGS`)·`KMIOCANIMCTL`(0/1/2 → `vidStopAnimation`/`vidSuspendAnimation`/`vidResumeAnimation`, 그 밖 `EINVAL`)·`KMIOCSIZE`(①과 같은 넷을 `data` 에)·`TIOCSWINSZ`(`EINVAL`)가 이 블록 차례로 있습니다. 함수 첫머리에 `status` 를 0 으로 둔 꼴로 보입니다(`clrl %d2`).
- ⑦ `kmgetc`·`kmgetc_silent`(새)·`kmtrygetc`: 장치 상태를 보기 전에 `adb_check_keyboard(&km.kybd_event)`(0x406500e) 를 부르고, 0 이 아니면 읽기를 건너뛰어 `kybd_process` 로 갑니다. `kmgetc` 는 상태가 없으면 바로 고리 첫머리(ADB 검사)로 돌아갑니다. `kmgetc_silent` 는 `kmgetc` 에서 `cnputc` 만 뺀 꼴입니다(x86 07 `km.m:330` 과 같은 관계).
- ⑧ `km_reset`(새, 78 B, `km_send` 와 `km_drawrect` 사이): `P_MON` 의 상태 낱말 셋째 바이트 비트 0 을 켬(SDK `monreg.h` 배치로는 `mon_csr.txloop`). 다음에 `mon_send(MON_KM_POLL, 0x1000a825)`·`mon_send(0, 0)`·`DELAY(10000)`. `splhigh()` 한 값을 되돌리지 않습니다.
- ⑨ `km_select_console`: `if (SLOT_ID == 0) nbic_bus_enable();`(NeXTMach 의 `*scr2 |= SCR2_OVERLAY`·`bmap_chip` 블록 대신; `_nbic_bus_enable` 은 받아들인 `nbic` 의 것).
- ⑩ `km_end_access`: `if (km_access_stack && --km_access_stack > 0) return;` 꼴(밑돎 방지 `= 0` 없음). 끝의 `machine_type` 갈래 대신 `if (km_coni.flag_bits & 2)` 일 때 `cpusha dc` 입니다. `km_flip_cursor` 도 `km_end_access()` 뒤에 같은 검사와 `cpusha dc` 를 둡니다. 2 의 이름은 참고 글에 없습니다(`KM_CON_ON_NEXTBUS` 1 만 있음).
- ⑪ `kmpopup`: `NC_W_FULL` 100·`NC_H_FULL` 48(NeXTMach 120·60). `km_begin_access()` 바로 앞에 `km_access_stack = 0;`. 레지스터 차이가 더 있어 B 에서 다시 봅니다.
- ⑫ `kmpaint`·`km_clear_eol`: `km_clear_eol` 이 인수를 받습니다. 0 이 아니면 `nchars = km.nc_w` 이고 열 기준이 `nc_lm` 입니다(`km.x` 를 빼지 않음). `kmpaint` 의 `'K'` 는 `km_clear_eol(0)`, 스크롤은 `km_clear_eol(1)` 입니다. 스크롤 앞뒤에 `if (KM_NPPW <= 2) adb_watchdog(0)`·`adb_watchdog(1)` 이 있습니다.
- ⑬ `km_switch_to_vm`: `kmem_alloc_wired(kernel_map, &KM_BACKING_STORE, WIN_SIZE_NOM)` 뒤 `KM_BACKING_STORE` 를 다시 읽어 검사(+80 = `map_addr[KM_CON_BACKINGSTORE].virt_addr`).
- ⑭ `km_run_pcode`: 원본이 14 B 짧고 `LOAD_AR` 갈래에 본문이 없습니다(다른 갈래로 뜀). `LOAD_AR` 에 `addr = km_convert_addr(addr);` 가 더해져 꼬리가 `LOAD_IR` 과 같아지고, 컴파일러가 합친 것으로 봅니다(B 에서 확인).
- ⑮ `__data` 차례: `ohlfs12.h` 를 `keycodes.h` 보다 먼저 들임(A1B 는 `ascii` 가 먼저).

변형(진단; 07 은 바꾸지 않음; scratch `p677/gen_p678.py` 가 A1B(SHA 단언)에서 만듦; 바뀐 줄마다 `plan 678 diagnostic B` 표시):
- B: ①–⑮ 모두. 새 ioctl 이름 넷과 `KM_ANIM_*`·`KMS_SEE_MSGS` 는 SDK 값으로 파일 안에 정의(진단). `kmgetc` 는 `for (;;) { if (!adb_check_keyboard(&km.kybd_event)) { csr = mon->mon_csr; if (csr.km_dav == 0) continue; km.kybd_event.data = mon->mon_km_data; } c = kybd_process(&km.kybd_event); if (c < inv) break; }` 꼴. `kmgetc_silent` 는 그 꼴에서 `cnputc` 를 뺌. `kmioctl` 의 `KMIOCSTATUS` 는 첫머리 `unsigned status = 0;` 과 `if (km.flags & KMF_SEE_MSGS) status |= KMS_SEE_MSGS; *(unsigned *)data = status;` 꼴(x86 07 `kmDevice.m:624–630` 꼴).
- B2: B 와 같되 `kmgetc`·`kmgetc_silent` 를 바깥 `do { … } while (c >= inv)` 와 안쪽 `goto` 로 쓴 꼴(바이트 꼴을 가르기 위한 대조).
- run `m4p678-p1`(REGISTRY 확인), funcbytes `-p678-B-`·`-B2-`(같은 대응·기준점). 판정: 함수별 수와 남은 차이를 원본 바이트로 다시 읽음. 44/44 가 되면 함수 밖 단언(절·`__data` 차례와 바이트·문자열 221 B·COMMON(D136, 특히 `next/cpu.h`·`next/scr.h` 사본에서 온 이름)·미정의)을 보고, 머리 꼴(`next/cpu.h`·`next/scr.h`·`next/trap.h`·`td.h`·`keycodes.h`·`ohlfs12.h`·`km_pcode.h` 의 07 자리)과 이름(2 의 플래그·`txloop`·0x1000a825·`km_clear_eol` 인수)을 구현 전에 여쭙니다.

### 678.1 교차검토(codex `gpt-6.1-sol`, task kz7vifg13) 판정과 계획 수정

먼저 제 잘못: ⑪ `kmpopup` 을 덜 읽었습니다. 원본은 16·32 비트 화소 갈래 첫머리(0x406fbe4·0x406fca0)에서 `adb_watchdog(0)` 을, 두 갈래의 공통 끝(0x406fd50)에서 `adb_watchdog(1)` 을 부릅니다(`_adb_watchdog` 0x4064792). 또 `km_flip_cursor()`(0x406fdd4) 다음의 `km_end_access()` 가 없습니다. ⑥ 은 "NeXTMach 여섯 경우 뒤에" 라고 적어 차례가 모호했습니다. 실제 블록 차례는 LEDS·RESTORE·DUMPLOG·GFLAGS·STATUS·DRAW·ERASE·DISABLCONS·ANIMCTL·SIZE·TIOCSWINSZ·기본입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| ①–⑤·⑦–⑩·⑫–⑮ 는 원본과 맞음(주소 인용); `TS_CARR_ON` 0x10 | `tty.h:123–125`, 원본 풀이(이번 세션), python 오프셋·상수 계산(`0x2200020`·`1<<28`·`km_coni` +20/+23/+48/+68·`km` +16/+20/+40) | ✅ |
| ⑥ 블록 차례(위)와 `status = 0` 이 첫머리 `clrl %d2` 를 설명; `KMIOCGFLAGS` 는 그대로 | 원본 `kmioctl` 목록(이번 세션) | ✅ 위 차례로 씀 |
| ⑦ `for (;;)`·`continue`·`if (c < inv) break` 가 가장 가까운 꼴; 바깥 `do/while` 안의 보통 `continue` 는 틀림 | 원본 0x40704b4–0x40704e8 흐름 | ✅ B 는 그 꼴, B2 는 `goto` 꼴(대조) |
| ⑪ 감시 호출 셋과 `km_end_access()` 삭제가 더 필요; 프레임·레지스터 차이는 그 호출들 때문일 수 있어 다시 견줄 것 | 원본 0x406fa7e–0x406fde0 풀이, `_adb_watchdog` 기호 | ✅ B 에 더함 |
| ⑭ `LOAD_AR` 은 주소 구성 뒤 0x4071fa2 에서 `LOAD_IR` 꼬리(0x4071fc8, `km_convert_addr` 부름)로 뜀 | 원본 풀이 | ✅ "본문 없음" 은 "꼬리 공유" 로 고침 |
| ⑮ 포함 차례는 배치로 뒷받침되나 글을 하나로 정하지는 못함 | 원본 기호 차례 | ⚖️ 진단으로 바꾸고 여쭐 때 적음 |

2차 자기검사: ✅ 행은 이번 세션의 풀이·python 입니다.

### 678.2 결과(runs `m4p678-p1`–`p4`, 2026-11-01)

- `m4p678-p1`: B·B2 컴파일 실패. `struct nty *np` 의 `np` 가 `keycodes.h:37` 의 `#define np 0x00c` 와 부딪혔습니다(x86 07 `km.m` 의 변수 이름이 m68k 머리에서는 쓰이지 못함). B·B2 원천에서 `ntp` 로 바꿔(진단; 생성기 `gen_p678.py` 는 아직 `np` — 따옴표 꼴이 맞지 않아 고침이 실패했고, 원천은 python 으로 직접 고침) 다시 돌렸습니다.
- `m4p678-p2`: B·B2 컴파일 0·경고 0, funcbytes **41/44**(둘 같음 — `kmgetc` 의 `for (;;)` 꼴과 `goto` 꼴은 바이트가 같음). 남은 셋:
  - `kmrestore` 1 바이트: 원본은 `km.store` 가 0 일 때도 `km_end_access()` 를 부릅니다. 그래서 그 호출이 `if (km.store)` 밖에 있습니다.
  - `km_clear_eol` 2 B 김: 열 계산 꼴이 다릅니다.
  - `km_switch_to_vm` 재배치 둘: 함수 안 정적 `km_vm_is_up` 의 꼬리 번호(`.94` 와 `.98`)뿐입니다. 컴파일러가 붙이는 이름이라, 기준점을 객체 이름에 맞추면 같습니다.
- `m4p678-p3`: C1·C2·C3(모두 `kmrestore` 고침, `km_clear_eol` 열 꼴만 다름). **C1 `km.nc_lm + (whole ? 0 : km.x)` 이 44/44**, C2(`!whole ? … : …`)·C3(B 꼴)은 43/44.
- `m4p678-p4`: D = C1 + `next/cpu.h` → `m68k/cpu.h` 와 쓰는 이름 블록(`slot_id`·`intrmask`·`intr_mask` extern, `SLOT_ID`·`P_MON`·`P_SCR2`·`I()`·`I_IPL`·`I_BIT`·`I_VIDEO` `I(3,8,5)`·`I_POWER` `I(3,11,2)`, NeXTMach 값; python 으로 쓰는 이름을 추림) + `next/scr.h`·`next/trap.h` import 지움(쓰는 이름 없음). 컴파일 0·경고 0, **44/44**, L1 `OBJECT_MATCH`·사유 없음·`full_span`, D 와 C1 은 canon 같음(`obj_sig` 는 COMMON 이 빠진 symbols 와 STABS 만 다름).
- 단언(scratch `p677/chk_km.py`; `m4-m68k-p678-diagchecks-20261101.json`, D `ok`):
  - 절은 `__text` 12646(재배치 741)·`__data` 1816(재배치 1)·`__cstring` 221 셋이고, 문자열은 원본 [0x40aa5f1, 0x40aa6ce) 과 바이트까지 같습니다.
  - `__data` 는 `mach_title` 의 재배치를 풀면 원본 [0x40b14b2, 0x40b1bca) 과 같습니다. `ohlfs12` 가 먼저입니다.
  - 바깥 정의는 모두 원본 자리입니다. 지역은 넷(`special_key_process`·`km_read_pcode`·`km_access_stack`·`km_vm_is_up.N`)이고 원본 자리입니다.
  - COMMON 23 은 모두 원본 이름이고 크기가 간격 이하입니다(C1 의 `_disk_chip`·`_scr1` 은 D 에서 사라짐). 미정의 65 는 모두 원본 이름입니다.

판정(미리 정한 대로): 바이트로 가려지지 않는 꼴과 머리 자리를 구현 전에 여쭙니다.

## 679. M4-183 D158 구현 계획 — 07 `src/machdep/m68k/km.c`, 07 머리 여섯, 공유 07 `kmreg.h` 의 ioctl 이름, `clock`·`machdep`·`m68k_init`·`zscom` 다시 받아들이기(코딩 전, 2026-11-01)

사용자 결정(D158 로 적을 것; AskUserQuestion 넷):
- ① 머리 자리는 선례대로입니다(추천안). `td.h`·`km_pcode.h` 는 07 `nextmach/nextdev/`(NeXTMach 사본)에 두고, `km.c` 의 따옴표 include 는 `#import <nextdev/km_pcode.h>` 로 씁니다. `ohlfs12.h` 는 있는 07 사본을 m68k 에도 스테이징합니다. `keycodes.h`(SDK = NeXTMach 바이트 같음)·SDK m68k `event.h`·`evio.h` 는 07 `nextdev/bsd/dev/m68k/` 실기 사본(로컬, D017)으로 두고 `#import <bsd/dev/m68k/…>` 로 씁니다. 모두 `M4HEADERS` 로 m68k 에만 둡니다.
- ② `kmgetc`·`kmgetc_silent` 는 do/while + `goto retry` 꼴입니다(추천안 `for (;;)` 가 아님; 진단 B2 가 바이트 같음).
- ③ 이름·철자는 추천안 묶음입니다(`ntp`·`whole`·`flag_bits & 2` 숫자·`mon_csr.txloop`·`0x1000a825` 숫자·`ev_vars.h` 대신 파일 안 extern 넷).
- ④ 새 ioctl 이름은 공유 07 `nextmach/nextdev/kmreg.h` 에 더합니다(추천안 "km.c 안 정의" 가 아님). 처음 추천한 "SDK `kmreg_com.h` 를 들임" 은 진단 E(run `m4p679-p1`)에서 `struct km_drawrect` 재정의로 실패했습니다(제 잘못, 확인 없이 추천함).

1. 07 머리(scratch `p677/gen_p679.py --write`; 덮어쓰지 않음 단언):
   - 새 파일: `nextmach/nextdev/td.h`·`km_pcode.h`(NeXTMach 그대로), `nextdev/bsd/dev/m68k/keycodes.h`·`event.h`·`evio.h`(실기 목록 SHA 와 같음 단언).
   - `nextmach/nextdev/kmreg.h` 의 `KMIOCERASERECT` 줄 뒤에 다음을 넣습니다(표시 `plan 679 (D158)`): `KMIOCDISABLCONS _IO('k', 8)`·`KMIOCANIMCTL _IOW('k', 9, int)`·`KMIOCSTATUS _IOR('k', 10, int)`·`KMIOCSIZE _IOR('k', 11, struct winsize)`·`KM_ANIM_STOP 0`·`KM_ANIM_SUSPEND 1`·`KM_ANIM_RESUME 2`·`KMS_SEE_MSGS 0x00000001`. SDK `kmreg_com.h:52–79` 의 값이고, `#define` 만 씁니다(SDK 의 `typedef enum km_anim_ctl_t` 를 쓰지 않는 까닭: 이 머리는 `mon/global.h` 를 거쳐 M5 `subr_prf` 등에도 들어가므로, 형 정의는 STABS 를 바꿈; 매크로는 객체를 바꾸지 않음).
2. 07 `src/machdep/m68k/km.c`(같은 생성기): NeXTMach `km.c`(SHA `6091238d…`) + 머리 주석 덩이 + include(표시) + 이름 블록(진단 D 꼴) + ①–⑮·`kmrestore` 고침·C1 꼴 + ② `goto` 꼴. 표시는 `plan 679 (D024, D158)` 입니다. 단언: ② 를 `for` 꼴로 만든 대조 원천이 진단 D 와 전처리 지시 줄을 뺀 토큰이 같음(진단 D 의 파일 안 ioctl 정의와 진단 머리 경로만 빠짐). F 는 그 대조와 `kmgetc`·`kmgetc_silent` 고리 둘만 다름. L(`08_build/artifacts/m4p679/src/km_L.c`)과 F 의 토큰·토큰 줄 같음. 표시 없는 바뀐 줄 0.
3. `stage_m68k.py`: `M4FILES[679] = list(M4FILES[676]) + ['km.c']`, `M4HEADERS[679] = list(M4HEADERS[676]) + [('nextdev/td.h', 'src/bsd/nextdev/td.h'), ('nextdev/km_pcode.h', 'src/bsd/nextdev/km_pcode.h'), ('nextdev/ohlfs12.h', 'src/bsd/nextdev/ohlfs12.h'), ('bsd/dev/m68k/keycodes.h', 'src/bsd/dev/m68k/keycodes.h', '07_kernel/nextdev'), ('bsd/dev/m68k/event.h', 'src/bsd/dev/m68k/event.h', '07_kernel/nextdev'), ('bsd/dev/m68k/evio.h', 'src/bsd/dev/m68k/evio.h', '07_kernel/nextdev')]`, `EXCEPTS[679] = dict(EXCEPTS[676])`, 머리말 목록.
4. 회귀:
   - `--plan 676` 재생성(`m0p676-r679-stage`)은 보관본과 `src/bsd/nextdev/kmreg.h` 해시 하나만 다름.
   - `m0p679-a1-stage` 는 그것과 `km.c`·새 머리 여섯만 다름.
   - `m5-676.cmd` 는 보관본과 같고, `m5-679.cmd` 는 계획 번호만 다름.
   - M5 205(`m3p679-b676` 보관 676 스테이지·`--plan 676 compare`, `m3p679-cc1`·`--plan 679`)는 객체·출력이 같아야 함(매크로만 더하므로 `kmreg.h` 를 들이는 M5 객체도 같아야 함).
   - x86 입력 `ok` 이고 p676 과 같음; `--plan 679 x86gate` 일곱 같음.
5. 확인 run `m4p679-p2`(바탕 `m0p679-a1-stage`): `km`(F, L), `clock`(F, L = `m4p535/src/clock_L.c`), `machdep`(F, L = `m4p600/src/machdep_L.c`), `m68k_init`(F, L = `m4p609/src/m68k_init_L.c`), `zscom`(F, L = `m4p674/src/zscom_L.c`).
   - 판정: 종료 0, 경고는 앞 받아들임과 같음(`machdep` 의 `thread_sleep` known_warnings 등은 앞 기록 그대로), i386 0.
   - funcbytes `km` 44·`clock`·`machdep` 23·`m68k_init` 1·`zscom` 5.
   - F = L. `km` F 와 진단 D 객체는 canon 같음·`obj_sig` header·sections·symbols 같음. 다시 받아들이는 넷은 앞 받아들인 객체와 canon 같음·`obj_sig` 는 STABS 만 달라도 됨.
   - `km` 의 함수 밖 단언 `chk_km.py`(머리 출처 07).
   - `-E` run `m4p679-e2`(다섯 F·L): 토큰 F = L, stderr 0, i386 0.
6. 최종 run 둘: `m4p679-a1`(명세 `08_build/artifacts/m4p679/spec.json`; `km`·`clock`·`machdep`·`zscom`, OBJECT_MATCH)과 `m4p680-a1`(명세 `08_build/artifacts/m4p680/spec.json`; `m68k_init`, `bss_inferred`; zerofill `m4-m68k-zerofill-p680-20261101.json`, 후보는 p609 와 같아야 함, 남은 받아들인 자리와 겹침 없음). 명령 파일은 명세 폴더의 `probe.cmd`. 확인 기록 `m4-m68k-p679-checks-20261101.json`·`m4-m68k-p680-checks-20261101.json`.
7. 상태: `ACCEPTED` 에서 p585·p600·p609·p674 튜플을 빼고 p679(두 칸)·p680(네 칸)을 넣음. 근거 `m68k-km.md`·`m68k-km.diff`·`m68k-kmreg_h.diff`(새)와 `m68k-clock.md`·`m68k-machdep.md`·`m68k-m68k_init.md`·`m68k-zscom.md` 에 plan 679 절. 상태 도구 두 번, 기대(python): 객체 60(OBJECT_MATCH 48, CODE+BSS_INFERRED 12), 행 82/188(행 223–226 이 덮임), 91212 B(42.25%), `object_bytes` 133256.
8. 기록: PROVENANCE(새 `km.c`·머리 다섯(`ohlfs12.h` 는 행 갱신)·`kmreg.h` 갱신·다시 받아들인 넷), MODIFICATIONS, DECISIONS D158, 계획·HANDOFF·메모리.

관문: 명령 종료 0, 경고 기준, i386 0, 회귀 같음, 확인·`-E`·최종·zerofill·확인 기록 `ok`, 상태 도구가 기대와 같음. 어긋나면 멈추고 알립니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

(§679 보충, codex 회신 전에 내가 확인한 것) 다시 받아들이는 넷의 옛 L 원천이 지금 07 파일과 맞지 않습니다(python lexer). `clock` 은 토큰은 같지만 줄 자리가 다릅니다(07 `clock.c` 686 행, `m4p535` L 672 행). `machdep` 은 토큰이 9 개 다릅니다(옛 L 에 진단 extern 한 줄). `m68k_init`·`zscom` 은 같습니다. 그래서 5 단계의 L 은 넷 모두 지금 07 파일에서 주석만 비운 새 L(`08_build/artifacts/m4p679/src/<이름>_L.c`, F 와 토큰·토큰 줄 같음 단언)로 바꿉니다. 앞 최종 명세의 known_warnings 는 `machdep` 2 줄(p600)뿐이고, 나머지 셋은 없습니다.

### 679.1 교차검토(codex `gpt-6.1-sol`, task kyqli4eds) 판정과 계획 수정

먼저 제 잘못: §678–679 와 두 번째 질문에서 `bsd/dev/kmreg_com.h` 를 "SDK" 머리라고 적었습니다. 스테이지의 그 파일은 07 `nextdev_private/bsd/dev/kmreg_com.h` 로, 프로젝트가 쓴 사설 머리입니다(1–7 행: "Not in the OPENSTEP 4.2 SDK", plan 303·D032, Darwin 0.1 글과 거의 같음). 실기 목록에도 `kmreg` 이름의 파일은 없습니다(python). 새 ioctl 네 값은 원본 `kmioctl` 의 비교 상수(0x20006b08·0x80046b09·0x40046b0a·0x40086b0b)가 정하므로 결정에는 영향이 없습니다. 이름은 이 07 사설 머리(그리고 x86 07 `km.m`)의 이름을 따른 것입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `kmreg.h` 를 의존하는 받아들인 객체는 정확히 넷; M5 205 줄 가운데 `subr_prf.c` 만 `mon/global.h → mon/kmreg.h` 로 닿고, 매크로는 STABS 에 나오지 않음 | 상태 도구 `dep_headers` 로 내가 셈(이번 세션, 넷); M5 은 회귀 run 이 판정 | ✅ 넷은 확인; M5 는 ⚖️(회귀가 판정) |
| 새 값이 맞고 `_IOW('k', 9, int)` 와 enum 꼴이 같은 값(0x80046b09; m68k enum 4 B); 07 `kmreg.h:17–19` 가 `sys/ioctl.h`·`sys/tty.h` 를 들임 | python 디코드(이번 세션), 그 줄 열어 봄 | ✅ |
| 스테이지의 `kmreg_com.h` 는 SDK 가 아님 | 그 파일 1–7 행, 매니페스트 출처 `07_kernel/nextdev_private/…`, 실기 목록 | ✅ 위 잘못 |
| 여섯 대상 경로 충돌 없음; `<bsd/dev/m68k/evio.h>` 와 그 import 가 풀림; `ohlfs12.h` 는 x86 경로로 따로 스테이징됨 | 진단 D 가 같은 경로로 컴파일됨(의존 출처), `find`(이번 세션) | ✅ |
| 상태 기대 60·48·12·82/188·91212·42.25%·133256 | python(이번 세션) | ✅ |
| `clock` 은 22 함수; `machdep` known_warnings 는 `thread_sleep` 경고 2 줄; F 와 L 의 경고 경로가 달라 최종 화이트리스트를 그대로 쓰지 못함 | `m4-m68k-funcbytes-p585-a1` 의 `total` 22, `m4p600/spec.json` 의 known_warnings(이번 세션) | ✅ 확인 run 은 변형마다 경고 수로 판정하고, 최종 명세는 F 만 두고 known_warnings 를 그 F stderr 그대로(§663 의 `sd` 와 같은 방식) |
| `m68k_init` zerofill 후보는 p609 와 같은 [0x40b55c4, 0x40b55cc) 8 B 여야 함 | 최종 단계에서 python 으로 견줌 | ⏭️(관문에 이미 있음) |

계획 수정: 5 단계 `clock` 은 22 함수. L 은 §679 보충대로 넷 모두 새로 만듭니다.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 679.2 결과(2026-11-01)

먼저 제 잘못과 계획과 다르게 한 점: ① 첫 회귀에서 새 ioctl 줄을 `kmreg.h` 중간(`KMIOCERASERECT` 뒤)에 넣었습니다. 그래서 뒤의 `km`·`alert_key`·`km_coni` 정의의 줄 번호가 9 씩 밀렸고, M5 `subr_prf` 객체의 STABS 셋(N_GSYM 의 줄 번호)이 달라졌습니다(run `m3p679-cc1`; canon·`obj_sig` 는 같음). 미리 정한 관문(M5 객체 같음)은 낮추지 않았습니다. 대신 줄을 파일 끝으로 옮겨 다시 돌렸고(`m3p679-cc2`), M5 객체가 같아졌습니다. ② 생성기 고침이 따옴표 꼴 때문에 두 번 실패했습니다(파일은 바뀌지 않았고, 줄 단위로 고침). ③ 확인 run 의 L 은 옛 L 대신 넷 모두 새로 만들었습니다(§679 보충).

- 1–2 07 `km.c` 2272 행(SHA `d630a5c7…`; `goto retry` 2 곳), L `08_build/artifacts/m4p679/src/km_L.c`; 새 머리 다섯(`td.h`·`km_pcode.h` NeXTMach, `keycodes.h`·`event.h`·`evio.h` 실기 SHA 같음); 07 `kmreg.h` 끝에 정의 여덟(SHA `bac6d361…`). 단언: `for` 꼴로 만든 대조 원천과 진단 D 는 전처리 줄을 뺀 토큰이 같음, F 와 L 의 토큰·토큰 줄 같음, 표시 없는 바뀐 줄 0(새 블록 줄에도 줄마다 표시). 3 `stage_m68k.py` 770 → 777 행.
- 4 회귀:
  - `--plan 676` 재생성(`m0p676-r679b-stage`)은 보관본과 `kmreg.h` 하나만 다름.
  - `m0p679-a2-stage`(1012)는 `km.c` 와 머리 여섯만 더함.
  - M5 205(`m3p679-b676`·`m3p679-cc2`)는 접두어를 맞추면 객체·출력이 모두 같음(`run.json` 만 다름); `compare` 의 `differ_unexpected`·`lost` 는 빔.
  - x86 `m4-x86-inputs-p679b-20261101.json` 은 `ok` 이고 p676 과 같음.
- 5 확인 run `m4p679-p2`(`m4-m68k-p679-p1checks-20261101.json` `ok`):
  - `km` 44·`clock` 22·`machdep` 23·`m68k_init` 1·`zscom` 5, F·L 모두 같음. 경고는 `machdep` 의 `thread_sleep` 하나(F·L 각 1)뿐입니다.
  - F = L. `km` F 는 진단 D 객체와 canon 같음. 넷은 앞 객체와 canon 이 같고 `obj_sig` 는 STABS 만 다릅니다(`machdep` 1834 → 1860; `clock`·`zscom` 은 객체 SHA 까지 같음).
  - `chk_km.py` F·L `ok`.
  - `-E` `m4p679-e2`(`ok`): 다섯 F = L, stderr 0.
- 6 최종 run 둘:
  - `m4p679-a1`(`km`·`clock`·`machdep`·`zscom`, SHA `4e4905b1…`)과 `m4p680-a1`(`m68k_init`, SHA `99a3afcf…`) 모두 `gate.ok`, 함수 모두 같음.
  - zerofill p680 은 `reference-inferred`, [0x40b55c4, 0x40b55cc) 로 p609 와 같음. 남은 자리 12 와 겹침 없음.
  - 확인 기록 `m4-m68k-p679/p680-checks-20261101.json` `ok`. `km` 객체 SHA `2f659928…`.
- 7 상태(`m4-m68k-status-p679-20261101.json`, 표 61 → 62 행; scratch 에 두 번 같음): 객체 60(OBJECT_MATCH 48, CODE+BSS_INFERRED 12), 행 **82/188**, **91212 B(42.25%)**, `object_bytes` 133256 — 미리 계산한 값과 같음.
- 8 기록: PROVENANCE 1220 → 1226 행(일곱 칸, 겹침 없음), MODIFICATIONS 754 → 756, DECISIONS D158(161 → 162 행).

판정(미리 정한 대로; 회귀는 ① 의 고침 뒤): 관문을 모두 통과해 받아들였습니다(D158).

## 681. M4-184 세부 계획 — m68k `od.c`(행 234, 행 235·236 일부) 진단 A1(07 변경 없음; 코딩 전, 2026-11-01)

고른 까닭: 남은 큰 단위 가운데 NeXTMach 글 대응이 가장 높습니다(원본 이름 58 가운데 NeXTMach 이름 57). 행 234 가 정확한 행이라 받아들이면 덮은 행이 늡니다. 앞은 받아들인 `np`(0x4074a6c 에서 끝남)입니다.

먼저 정정(§668 의 제 잘못): §668 에 0x40b202a `_dma_recover_wl` 을 "받아들인 `dma` 의 것" 으로 적었습니다. 받아들인 `dma` 객체에는 `__data` 가 없고(python), NeXTMach 는 `inhibit_label_errs`·`dma_recover_rl`·`dma_recover_wl` 을 `od.c:3756–3758` 에서 정의합니다. 이 셋은 `od` 의 자료입니다. 근거 문서 `m68k-sc.md` 에는 그 말이 없습니다.

확인한 사실(이번 세션; 수는 python):
- 범위 [0x4074a6c, 0x407aae0) 24692 B, 항목 61. NeXTMach mk-108.1 `nextdev/od.c`(5386 행, SHA-256 `07a2e1fa…`)와 대응합니다.
  - 이름 57 은 NeXTMach 정의 차례로 대응합니다(`od_xpr_alert` 691 … `od_eject` 5318, `od_panel_abort` 5341).
  - 이름 없는 0x4075ac0(18 B, `od_setup` 과 `od_done` 사이)은 정적 `busdone`(1472 행, `#ifdef OD_SFA_ARB`)으로 보입니다.
  - 이름 없는 0x407aa5c(110 B, `od_panel_abort` 뒤)는 정적 `od_dma_init`(5350 행)으로 보입니다.
  - 원본에서는 `_oddump`(0x407aaca)·`_odsize`(0x407aad2)가 맨 끝입니다. NeXTMach 에서는 `odminphys`(5013) 뒤 5052·5054 행입니다. 1997 판에서 차례가 다를 수 있으며, A1 이 판정합니다.
  - NeXTMach 에만 있는 정의(`od_xpr` 678, `dbug_vol`·`dbug_q`, `od_daemon` 4464)는 조건부로 보이며, A1 이 판정합니다.
- 구간: `span()` 은 `{"range": ["0x4074a6c", "0x407aae0"], "rows": ["m68k-234"], "partial": ["m68k-235", "m68k-236"], …}` 를 받습니다(python 시험; `partial` 이 235 만이면 멈춤).
- 자료: `__data` [0x40b1c10, 0x40b202e) 1054 B(`od_err` 0x40b1c10 … `inhibit_label_errs`·`dma_recover_rl`·`dma_recover_wl` 0x40b202a; 앞은 받아들인 `np` 의 66 B, 뒤는 받아들인 `sc` 의 `_scdriver`). 정적 bss 참조는 0x40b4fbe 하나입니다(4 B, 뒤 0x40b4fc2 는 받아들인 `sc` 의 정적 bss). COMMON 참조가 많습니다(`od_ctrl`·`od_drive`·`od_vol`… 와 공유 이름). 문자열 블록은 A1 객체의 `__cstring` 을 원본에서 찾아 정합니다(끝은 받아들인 `sc` 블록 0x40ab30a).
- 머리: NeXTMach import 46 줄(111–157 행). 스테이지(`m0p679-a2-stage`)에 없는 것과 선례 대응은 이렇습니다.
  - 선례대로 바꿈(D104): `next/psl.h` → `m68k/psl.h`, `next/pmap.h` → `vm/pmap.h`(snd·vm_machdep 선례), `next/printf.h` → `kernserv/printf.h`(sc 선례), `nextdev/disk.h` → `dev/disk.h`, `nextdev/insertmsg.h` → `kernserv/insertmsg.h`, `nextdev/voldev.h` → `dev/voldev.h`(fd_subr·sd 선례).
  - NeXTMach 만 있음: `nextdev/odvar.h`, `nextdev/canon.h`, `next/scr.h`.
  - `next/cpu.h` 는 스테이지의 NeXTMach 사본(D109)이 있어 A1 은 그대로 둡니다. `km`(§678)처럼, 함수가 맞은 뒤 쓰는 이름만 남기는 머리 정리를 따로 합니다.

방법(진단; 07 은 바꾸지 않음; scratch `p681/gen_p681.py` → `08_build/artifacts/m4p681/`):
- 변형 A1: NeXTMach `od.c` + 위 여섯 줄 바꿈(진단 표시), 진단 `inc` 셋(`nextdev/odvar.h`·`nextdev/canon.h`·`next/scr.h`, NeXTMach 사본). 그 밖은 NeXTMach 그대로입니다.
- 명세: 바탕 `m0p679-a2-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `od`, 위 구간(`basis` 적음), `x86_rel` `machdep/i386/dkbad.c`. run `m4p681-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`).
- funcbytes `-p681-A1-`: 대응 `0x4075ac0=_busdone`·`0x407aa5c=_od_dma_init`, 자료 기준점은 원본 기호(`_od_err` 등)이고, 정적 자료·bss 는 A1 객체의 지역 기호를 보고 정합니다.
- 측정: 종료·경고, 함수별 바이트·재배치 대상, 객체에만 있는 함수, 함수 차례, 절 크기(`__text` 24692·`__data` 1054·`__bss` 4 목표), 문자열 블록, 기호·COMMON(D136)·미정의, 의존 출처(i386 0). 다른 함수는 scratch `p677/rdiff.py` 로 원본 바이트와 견줍니다.

판정(미리 정함; 07 은 바꾸지 않음): 컴파일이 안 되면 원인을 적고 최소 고침의 새 변형을 새 run 으로 돌립니다. 되면 함수별 결과를 적고 1997 바뀜을 원본 바이트로 읽어 진단 B 를 세웁니다(B 앞에 codex 교차검토).

### 681.1 교차검토(codex `gpt-6.1-sol`, task kwav2w4d0) 판정과 계획 수정

먼저 제 잘못: ① 항목 수를 "이름 57" 로만 적었습니다. 이름 59(차례가 다른 `oddump`·`odsize` 포함)와 이름 없는 2 입니다. ② NeXTMach 에만 있는 정의로 적은 `dbug_vol`·`dbug_q` 는 매크로입니다(`od.c:533–666`). 무조건인 `od_dmaintr`(2853 행)도 원본에 없는데 빠뜨렸습니다. ③ A1 이 그대로는 컴파일되지 않을 것을 놓쳤습니다(`NOC`·`B_PHYS_COPY`).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 61 항목 = 이름 59 + 이름 없음 2; `busdone`(`OD_SFA_ARB` 는 `od.c:186` 에서 1)·`od_dma_init` 대응 맞음 | `od.c:186–190` 열어 봄, 함수 표(이번 세션) | ✅ |
| `odsize` 는 원본에서 1024 를 돌려줌(0x407aad6); NeXTMach `odsize() {}` | 원본 풀이, `od.c:5054` | ✅ 1997 바뀜 |
| `od_xpr` 는 `#if DEBUG`(677); `od_daemon` 은 무조건(4464); `od_dmaintr`(2853)도 원본 기호에 없음 | 조건 줄 python 으로 찾음; 기호 표에 `_od_dmaintr`·`_od_daemon` 없음 | ✅ 둘은 A1 에서 "객체에만 있는 함수" 로 나올 것 |
| `__data` 1054 B 는 이 단위의 것(`odvar.h` 의 `od_err`·`od_dcmd`·`od_fcmd` 포함); `od_more_info` 는 원본 6 B 이고 NeXTMach 는 더 큼, `mi_*` 전역은 원본에 없음 | 기호 표(`_od_more_info` 있음, `_mi_*` 없음) | ⚖️ 크기 차이는 A1 의 `__data` 비교가 판정 |
| 정적 bss 0x40b4fbe 는 `od_timer` 의 `static od_thread_init`(867 행) | `od.c:867–873` | ✅ |
| 문자열 블록 [0x40aa8f4, 0x40ab30a) 2582 B(첫 "excessive ECC errors", 앞은 np 의 "np_write: can't remove vm") | 원본 `__cstring` 덤프(이번 세션) | ✅ |
| `NOC` 미정의(`od.c:196·346·876`; 생성 `od.h` 는 `NOD` 만); `B_PHYS_COPY` 미정의(NeXTMach `sys/buf.h:150`, 스테이지 없음) | 스테이지 `generated/od.h` 내용, grep(이번 세션); `_odcinfo` 간격 4 B(python) → `NOC` 1 | ✅ A1 에 진단 정의 둘 |
| 1997 차이: `kmem_alloc_wired` 넷, `od_setup` 의 정렬 복사 경로 없음, `odprobe` 의 `dc_dmaintr` 지정 없음, SFA 그대로 | 직접 읽지 않음 | ⏭️ A1 결과와 함께 B 에서 원본으로 다시 읽음 |
| 측정에 COMMON 크기·`struct ctrl` 오프셋·공유 문자열을 넣을 것 | 계획 측정 목록 | ✅ |

계획 수정(A1): 진단 정의 둘을 둡니다. `#import <od.h>` 앞에 `#define NOC 1` 을 두고(진단; 07 에서는 구성 행 여부를 따로 여쭘), `B_PHYS_COPY` 는 NeXTMach 값 `0x01000000` 으로 정의합니다(진단; 1997 에서는 그 경로가 없어 B 에서 지움). 문자열 블록은 [0x40aa8f4, 0x40ab30a) 입니다.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 681.2 A1·A1B 결과(runs `m4p681-p1`·`p2`, 2026-11-01)

- `m4p681-p1`(A1): 컴파일 실패. `odread`·`odwrite` 의 `DEV_BSIZE` 와 `NeXT_page_size`·`NeXT_page_mask` 가 선언되지 않았습니다(1997 머리에 없음).
- `m4p681-p2`(A1B = A1 + `NeXT_page_*` → `m68k_page_*`, `DEV_BSIZE` → 1024(원본 `odread`·`odwrite` 가 0x400 을 넘김); 진단): 컴파일 0, 경고 1(`od_write_label` 의 `kfree`). funcbytes `-p681-A1B-` **23/61**, 객체에만 있는 함수 `_od_daemon`·`_od_dmaintr`. 절 `__text` 25716(원본 24692, 1024 B 김)·`__data` 1102(원본 1054)·`__cstring` 2647(원본 2582)·`__bss` 4.
- 도구: scratch `p681/ndiff.py`(`rdiff.py` 위에서 객체의 `struct ctrl` 오프셋을 원본 배치로 옮겨 견줌)·`olist.py`(한쪽 풀이). 판정은 여전히 `m68k_funcbytes.py` 입니다.

## 682. M4-185 조사 결과와 세부 계획 — `od.c` 진단 B(1997 바뀜; 07 변경 없음; 코딩 전, 2026-11-01)

원본 바이트로 읽은 1997 바뀜(주소는 원본; 수는 python):
- ① `struct ctrl` 652 B(NeXTMach 664 B). A1B 와 원본의 오프셋 짝이 548 까지 같고, 564→556·566→558·568→560(8 줄어듦), 584→572 부터 끝까지(12 줄어듦)입니다. 원본은 552 를 한 번도 쓰지 않습니다(540–599 의 쓰임 수: 544:202·548:3·556:12·558:8·560:12·564:2·568:19·572:17 …). 그래서 `c_tbuf`(548, `odprobe` 의 `pea %a3@(548)` 0x4074d4c) 뒤 복사 경로의 셋(`c_cbuf`·`c_ccount`·`c_cmap`) 가운데 둘이 없고 하나(쓰이지 않음)가 552 에 남습니다. 또 `c_test_blkno`(564, 쓰임 2)·`c_pblk`(568) 뒤의 `c_curpos_time` 이 없습니다. 남은 하나의 이름은 바이트로 가려지지 않습니다(B 는 `c_cbuf` 를 둠).
- ② `struct more_info` 6 B = `{ int mi_reserved_cyls; short mi_nsect; }`, 값 `{ 4149, 16 }`(0x40b1f8a `000010350010`). `mi_rv_delay` 등 전역 여섯이 없습니다(원본 기호 없음). `od_read_label` 의 첨자 곱이 6 입니다.
- ③ `odprobe`: 장치 번호 고리 둘을 맨 앞으로 옮김(0x4074aae–0x4074b4c). `machine_type` 이 `NeXT_CUBE`·`NeXT_X15` 가 아니면 `bdevsw[od_blk_major]` 의 `d_open`·`d_psize`·`d_dump`(이 차례, 오프셋 0·0x10·0xc)와 `cdevsw[od_raw_major].d_open` 에 `nodev`(0x400beaa)를 넣고 0 을 돌려줌(0x4074b4e–0x4074ba8). `od_readlabel`·`c_tbuf` 는 `kmem_alloc_wired(kernel_map, &…, size)` 가 0 이 아니면 `panic`(0x4074c08·0x4074d56; D150 꼴). `MHZ_20` 갈래가 들어감: `c_initr = 0xc0`, `scr1->s_cpu_clock >= CPU_25MHz` 면 `|= 0x10`(0x4074c7e–0x4074ca6). 이 읽기는 `slot_id + 0x200c000` 의 +3 바이트 `& 7` 이라(§682.1 에서 고침), 변수 `scr1`(NeXTMach `next/scr.h:115`, 원본에 `_scr1` 없음)이 아니라 `P_SCR1` 주소와 1997 `struct scr1`(`s_cpu_clock : 3`, 07 `m68k_init.c:130–139` 선례)입니다. `dc_dmaintr = od_dmaintr` 가 없습니다.
- ④ `odopen`·`odclose`·`od_setup`·`od_done`: 정렬 복사 경로(`c_cbuf` 할당·해제, `od_setup` 의 복사와 `B_PHYS_COPY`, `od_done` 의 되복사)가 모두 없습니다(문자열 셋 49 B 도 없음). `odopen` 은 `if (od_make_empty() < 0) { splx(s); return (ENXIO); }`(0x40750c8 뒤)와 `od_empty < 0` 일 때 `splx(s)` 뒤 `ENXIO` 입니다. `od_setup` 의 `c_pmap` 조건은 `(bp->b_flags & (B_PHYS|B_KERNSPACE)) == B_PHYS`(0x40759ae `andil #0x4000010`; 07 `sd.c:1221`·`fd_subr.c:202` 선례). `od_done` 은 `B_DONE` 이 아니면 `B_ERROR` 이고 `bp != &v->v_cbuf` 일 때 `b_error = EIO` 를 둔 뒤 `biodone`(0x4075bc2–0x4075bd6).
- ⑤ `od_fsm`: `OMD_SEEK` 의 상대 점프 계산이 없습니다. `r_csr_h`·`r_csr_l` 읽기(0x4076580·0x4076584)는 남고 곧바로 `c_dcmd = OMD1_SEK | (c_blkno & 0xfff)` 입니다(0x407658c). `seek:` 의 `CF_50_50_SEEK` 두 문장이 없습니다(그 앞 읽기는 `if (c->c_flags & CF_CUR_POS) dbug_xfer(…)` 의 것; 0x4076724 둘레).
- ⑥ `od_issue_cmd`: `dc_flags = (direction == DMACSR_READ) ? DMACHAN_INTR : 0`(0x40770e0 `seq`).
- ⑦ `odintr`: `dcp`(스택 0x4077698)를 씀. `CF_ERR_VALID` 가 없을 때 먼저 `if (c->c_flags & CF_NEED_DMA) dma_cleanup(dcp, 0)`(0x4077932; 07 `fd_cmds.c:515` 선례 꼴), `dma_abort(dcp)`(0x4077c00). 헤드 위치 시각(`c_curpos_time`) 블록이 없습니다(`CF_CUR_POS` 켜기는 남음).
- ⑧ `od_cmd`: `vsunlock(bufp, bcount, B_READ 이면 1 아니면 0)`(0x4078876–0x4078884; 1997 `vsunlock` 세 인수).
- ⑨ `odioctl` `DKIOCSLABEL`·`od_canon_remap`·`od_canon_label`·`od_make_free_pages`·`od_buf_alloc`: `kmem_alloc` → `kmem_alloc_wired`(호출 자리 0x4079b4c·0x4079ba6·0x4079c3c·0x4079f92·0x407a0d8·0x407a38c 와 `od_buf_alloc` 의 `lea` 0x407a486 + `jsr` 셋). 라벨·`od_buf_alloc` 은 실패면 `panic`, 불량 블록 표·비트맵은 `ENOMEM`, canon 둘과 `od_make_free_pages` 는 돌려준 값을 보지 않습니다.
- ⑩ `odminphys`: `scminphys`(07 `sc.c:1548–1557`, D155) 꼴 — 0x10000, `dma_chip == 313` 이면 8192, 넘으면 줄임; `minphys` 부름 없음(0x407a3cc, 42 B).
- ⑪ `od_make_empty`: `lru == 0` 이면 −1(0x407a61a). `od_request_vol` 은 `<= 0`(0x407a896 뒤 0x407a89e `blew`).
- ⑫ `od_dma_init`: `dma_list` 에 secsize·rathole_va 인수 없음(0x407aa94; 07 `fd_cmds.c:755–764` 선례).
- ⑬ `odsize`: 1024 를 돌려줌. `oddump`·`odsize` 는 파일 끝(`od_dma_init` 뒤).
- ⑭ 없는 함수: `od_dmaintr`(정의·선언·지정), `od_daemon`.
- 그 밖 같은 길이 함수의 차이는 `struct ctrl` 오프셋·자료 주소뿐입니다. `od_remap` 의 558 은 라벨(`dl_bad`)이라 제 정규화의 오탐입니다. `__data` 는 `od_more_info`·`mi_*` 말고 같습니다(포인터는 재배치). 문자열은 A1B 객체에만 있는 일곱을 빼면 원본과 차례까지 같습니다. 그 일곱 가운데 `"read"`·`"write"`·`""`·`"%s\n"`(16 B)은 다른 객체의 같은 문자열과 합쳐진 것이고(`sd` 선례), 나머지 셋(49 B)은 복사 경로의 것입니다.

변형(진단; 07 은 바꾸지 않음; scratch `p681/gen_p682.py` 가 A1B(SHA 단언)에서 만듦; 바꿀 자리마다 한 번만 맞는지 단언; 바뀐 줄마다 `plan 682 diagnostic B` 표시):
- B: ①–⑭ 모두. `next/scr.h` import 대신 파일 안 진단 블록(`NeXT_CUBE` 0·`NeXT_X15` 2·`CPU_25MHz` 2·1997 `struct scr1`)과 `#define MHZ_20 1`(진단), 읽기는 `((volatile struct scr1 *)P_SCR1)->s_cpu_clock`. `vsunlock` 셋째 인수 `(bp->b_flags & B_READ) ? 1 : 0`. `od_done` 은 `if ((bp->b_flags & B_ERROR) && bp != &v->v_cbuf)`.
- B2: B 와 같되 `scr1` 읽기에서 `volatile` 을 뺌, `vsunlock` 셋째 인수 `bp->b_flags & B_READ`, `od_done` 을 겹친 `if` 로(바이트 꼴을 가르는 대조; 서로 다른 함수라 funcbytes 로 따로 보임).
- run `m4p682-p1`(REGISTRY 확인), funcbytes `-p682-B-`·`-B2-`(대응·기준점은 A1B 와 같음). 측정: 종료·경고, 함수별, 객체에만 있는 함수(없어야 함), 절(`__text` 24692·`__data` 1054·`__cstring` 2598 = 2582 + 합쳐진 16·`__bss` 4 목표), 문자열 차례, `__data` 바이트, 기호·COMMON(D136; 특히 `_scr1` 이 없어야 함)·미정의.

판정(미리 정함): 61/61 이 아니면 남은 차이를 원본 바이트로 다시 읽어 새 변형을 새 run 으로 돌립니다. 61/61 이면 함수 밖 단언과 머리 정리(`next/cpu.h` 등, §678 D 선례)를 보고, 바이트로 가려지지 않는 꼴(552 의 이름, `MHZ_20` 꼴, `scr1` 꼴, `DEV_BSIZE` 자리의 1024, `NOC` 구성 행, 지운 문장의 표시 꼴 등)을 구현 전에 여쭙니다.

### 682.1 교차검토(codex `gpt-6.1-sol`, task kw4ucio4z) 판정과 계획 수정

먼저 제 잘못: ① 드라이브 수를 놓쳤습니다. 원본 `_od_drive` 는 64 B(= 32 × 2; 다음 기호 `_od_empty` 0x40c3e58), `_oddinfo` 는 8 B 입니다. 고리 끝 비교도 모두 `#0x40c3e58` 입니다. 그런데 스테이지 생성 `od.h` 는 `NOD 1` 이고(구성 행 `hypothesis`, D110), A1B 는 `_od_drive+32` 를 씁니다. ② `scr1` 읽기를 "셋째 바이트" 로 적었는데, `slot_id + 0x200c003`(+3 바이트)입니다. ③ "같은 길이 함수의 차이는 오프셋·자료 주소뿐" 은 지나쳤습니다. `c - od_ctrl` 의 나눗셈 곱수(예 `od_perror` 0x4078284 `1159377675`·`asrl #2`)도 배치에서 오는 차이입니다. ④ "552 를 한 번도 쓰지 않음" 은 "명시적 참조 없음" 으로 고칩니다. `odprobe` 의 `bzero(c, 652)` 는 그 자리도 씁니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 드라이브 둘: 고리 끝 `0x40c3e58` 이 0x4074f90·0x4074fd6·0x4079800·0x407986e·0x407a234·0x407a298·0x407a54a·0x407a584·0x407a5d8·0x407a9ca·0x407aa38 | 원본 풀이에서 그 주소 열한 줄을 엶; 기호 간격(python): `_od_drive` 64·`_oddinfo` 8·`_odcinfo` 4; 스테이지 `generated/od.h` = `NOD 1` | ✅ B·B2 에 진단 `#undef NOD`·`#define NOD 2` |
| 652 크기(0x4074a9c·0x4074f7e `addaw #652`), 556/558/560/564/568/572/576/580 자리 인용 | 0x4074f7e·0x407671e·0x407672a·0x4076588·0x4076218·0x407689c·0x4077948·0x40759f4·0x4077bdc·0x407794c 를 엶 | ✅ 지운 4 B 는 `c_curpos_time`(`c_save_nsect` 는 576 에 남음) |
| 552 는 명시적 참조 없음(`lea`/`pea`, 절대 `0x40c3db0` 포함); `bzero` 는 씀 | 원본 풀이에서 `(552)`·`0x228`·`#552` 0 건, 커널 전체 바이트 `040c3db0` 0 건(python) | ✅ 표현을 고침 |
| `od_more_info` 6 B, 첨자 곱 6(0x40789d6–0x40789ea) | 두 줄 엶, `__data` 덤프 `000010350010` | ✅ |
| `nodev` 넣기 차례 0x4074b70·0x4074b78·0x4074b80·0x4074b9e, 할당 검사, `scr1` 은 +3 바이트 | 원본 풀이(이번 세션) | ✅ ②의 고침 |
| `odopen` 의 두 `ENXIO` 앞 `splx`(0x40750c8–0x40750d6, 0x4075114–0x4075122), `od_setup` 마스크(0x40759ae–0x40759b8), `od_done` 바깥 `!B_DONE` 안의 `EIO`(0x4075bc2–0x4075bdc) | 그 줄들을 엶 | ✅ 계획과 같음 |
| `seek:` 의 남은 읽기 0x407671a, 트랙 0x407671e–0x407672a; `OMD_SEEK` 0x4076580–0x4076590 | 엶 | ✅ |
| `od_issue_cmd` `seq` 0/1, `odintr` `dcp` 0x4077698·`dma_cleanup` 0x4077932·`CF_CUR_POS` 0x407797e·`dma_abort` 0x4077c00 | 엶 | ✅ |
| `od_cmd` 0/1 플래그 0x4078872–0x407887c; B·B2 는 `B_READ` 가 1 이라 뜻이 같음 | 엶, 스테이지 `sys/buf.h:145` | ✅(바이트 꼴은 B2 가 가름) |
| `odioctl` 패닉 0x4079b60·`ENOMEM` 0x4079c4a, `od_buf_alloc` `jsr` 0x407a48c·0x407a4b4·0x407a4de | 엶 | ✅ |
| 문자열: 합쳐진 넷은 `od_fcmd` 포인터 0x40b1eee→`"read"`·0x40b1ef4→`"write"`, 0x407927a→`""`, 0x4078470→`"%s\n"`(블록 밖 주소) | 원본 `__data`·`__cstring` 을 python 으로 읽음 | ✅ 49 + 16 B |
| `nodev`(`sys/conf.h:28`)·`KERN_SUCCESS`(`vm/vm_kern.h:61` → `mach/kern_return.h`)·`dma_cleanup`(`nextdev/dma.h:236`)·`P_SCR1`(`next/cpu.h:177`)이 스테이지에 있음 | 그 줄들을 엶 | ✅ `next/cpu.h` 는 B 에서 그대로 둠 |
| `od_remap` 0x40773e2 는 라벨 주소 | 엶 | ✅(제가 이미 적은 오탐) |

계획 수정(B·B2): `#import <od.h>` 뒤에 진단 `#undef NOD`·`#define NOD 2` 를 둡니다. 07 에서는 구성 행 `od NOD od.h` 를 `1` → `2` 로 바꿀지 따로 여쭙니다. `machargs`(`#if NOD`)와 `od.h` 를 읽는 다른 객체는 그때 다시 받아들여야 합니다. 측정에 드라이브 고리 끝·`_od_drive` 64 B·`_oddinfo` 8 B(COMMON 크기)를 더합니다.

2차 자기검사: ✅ 행은 이번 세션에 연 원본 풀이 줄·헤더 줄·python 출력입니다.

### 682.2 결과(runs `m4p682-p1`–`p4`, 2026-11-01)

먼저 제 잘못: B 생성기(scratch `p681/gen_p682.py`)가 NeXTMach 첫머리의 `if (machine_type != NeXT_CUBE && machine_type != NeXT_X15) return (0);` 를 지우지 않았습니다(원본에는 `nodev` 블록의 검사 하나뿐). 또 처음 쓴 범위는 `od_daemon` 뒤의 `od_spiral` 까지 지울 뻔했습니다. 돌리기 전에 범위를 `od_spiral()` 앞으로 고쳤습니다.

- `m4p682-p1`(B·B2): 컴파일 0. 경고는 B·B2 각각 2(`kfree`, `odioctl` 의 register 변수 `l` 의 주소). funcbytes B **52/61**, B2 51/61. `__data` 1054·`__cstring` 2598 은 목표대로이고, `__text` 는 B 24702·B2 24696 입니다.
  - B·B2 의 `odprobe` 는 첫머리 검사 탓에 10 B 깁니다.
  - B2 의 `od_cmd`(`bp->b_flags & B_READ` 꼴)는 6 B 짧습니다. 그래서 `? 1 : 0` 꼴이 맞습니다.
  - `od_done` 의 겹친 `if` 꼴은 `&&` 꼴과 바이트가 같습니다.
- `m4p682-p2`(C = B − 첫머리 검사, C2 = C 에서 `scr1` 읽기의 `volatile` 을 뺌): 컴파일 0, 경고 2, `__text` 24692.
  - funcbytes 53/61. 나머지 여덟(`od_timer`·`od_read_label`·`od_spiral`·`od_lock`·`od_try_attach`·`od_make_empty`·`od_request_vol`·`od_eject`)은 바이트 차이 0 입니다. 재배치 대상 이름만 다르고 주소는 같습니다(python: `_od_drive`+64 = 0x40c3e58 = `_od_empty`, `_od_vol`−218 = 0x40c3dee = `_od_ctrl`+614, `_od_ctrl`+652 = `_od_dbug`).
  - L1 사유는 `__DATA,__bss: unverified` 하나이고, `full_span`, `provisional` 입니다. C 와 C2 는 canon·`obj_sig` 가 같습니다(`volatile` 은 바이트로 가려지지 않음).
  - 남은 문제는 COMMON `_disk_chip`(NeXTMach `next/cpu.h` 사본에서 옴, 원본 없음) 하나였습니다.
- `m4p682-p3`(D = C + `next/cpu.h` → `m68k/cpu.h` 와 쓰는 이름 블록: `slot_id`·`slot_id_bmap` extern, `SLOT_ID`·`P_DISK_CSR`·`P_SCR1`·`I()`·`I_IPL`·`I_DISK_DMA`·`I_DISK`, NeXTMach 값; §678 D 선례): 컴파일 0, 경고 2. funcbytes 53/61 에 주소가 같은 여덟을 더해 61/61 입니다. L1 은 C 와 같습니다.
  - 단언(scratch `p681/chk_od.py`; `m4-m68k-p682-diagchecks-20261101.json`, `ok`):
    - 절은 `__text` 24692(재배치 911)·`__data` 1054(재배치 121)·`__cstring` 2598·`__bss` 4 입니다.
    - 문자열은 합쳐진 넷을 빼면 원본 [0x40aa8f4, 0x40ab30a) 과 바이트까지 같습니다.
    - `__data` 는 재배치 121 의 대상(문자열 내용·함수·자료·외부 기호 주소)이 원본 포인터와 같고, 나머지 바이트도 같습니다.
    - 바깥 정의 91 은 모두 원본 자리입니다. 지역 셋(`_busdone` 0x4075ac0·`_od_dma_init` 0x407aa5c·`_od_thread_init.38` bss 0x40b4fbe)도 원본 자리입니다.
    - COMMON 48 은 모두 원본 이름이고 크기가 간격 이하입니다. 미정의 101 은 모두 원본 이름입니다.
- `m4p682-p4`(E = D 에서 `odioctl` 의 `l` 의 `register` 를 뺌): 경고는 `kfree` 1 입니다. `__text` 바이트가 D 와 같고, 단언도 모두 `ok` 입니다.

바이트로 가려지지 않는 것(구현 전에 여쭘): 552 의 쓰이지 않는 필드 이름; `MHZ_20` 꼴(조건을 지움 / 파일 안 `#define MHZ_20 1`); `scr1` 읽기의 `volatile`; `NOD` 2·`NOC` 1 의 자리(구성 행 / 파일 안); `odread`·`odwrite`·`odsize` 의 1024 표기; `l` 의 `register`; 지운 문장의 표시 꼴(D154 선례).

## 683. M4-186 D159 구현 계획 — 07 `src/machdep/m68k/od.c`, 07 `odvar.h`·`canon.h`, 구성 `NOD 2`·`NOC 1`, `machargs`·`swapgeneric` 다시 받아들이기(코딩 전, 2026-11-01)

사용자 결정(D159 로 적을 것; AskUserQuestion 넷):
- ① 552 의 쓰이지 않는 필드는 `c_cbuf` 를 남기고 `c_ccount`·`c_cmap` 을 지웁니다(추천안).
- ② `#if MHZ_20` 구조를 두고 파일 안에 `#define MHZ_20 1` 을 둡니다(추천안 "조건 지움" 이 아님). 클럭 읽기는 `((struct scr1 *)P_SCR1)->s_cpu_clock`(volatile 없음, 07 `m68k_init.c:265` 선례)입니다. 1997 `struct scr1` 과 `NeXT_CUBE`·`NeXT_X15`·`CPU_25MHz` 는 파일 안에 둡니다.
- ③ 구성 행에 `NOD 2`(confirmed)·`NOC 1` 을 둡니다(추천안). 생성 `od.h` 를 들이는 받아들인 객체는 다시 받아들입니다.
- ④ 1024 는 파일 안 `#define DEV_BSIZE 1024` 로 두고 NeXTMach 표기 `DEV_BSIZE` 를 씁니다(추천안의 "숫자" 가 아님). 묶음의 나머지는 추천안입니다. `odioctl` 의 `l` 에서 `register` 를 빼고(진단 E), 지운 문장·함수는 표시 주석과 함께 지우며(D154 선례), `vsunlock` 셋째 인수는 `(bp->b_flags & B_READ) ? 1 : 0` 입니다.

앞선 선례: include 는 OPENSTEP 경로(D104; §681 의 여섯 줄), `next/cpu.h` → `m68k/cpu.h` + 파일 안 이름 블록(D110·§682 D), `kmem_alloc_wired(…, (vm_offset_t *)&x, …) != KERN_SUCCESS`(D150), `dma_list` 인수(`fd_cmds.c` D131), `scminphys` 꼴(D155).

1. 07 머리(scratch `p681/gen_p683.py --write`; 없던 파일이어야 함 단언): `07_kernel/nextmach/nextdev/odvar.h`(NeXTMach SHA `b2787685…`)·`canon.h`(`aee6f498…`) 를 바이트 그대로 둡니다. 진단에 쓴 사본과 같습니다.
2. 07 `src/machdep/m68k/od.c`(같은 생성기): NeXTMach `nextdev/od.c`(SHA `07a2e1fa…`)에 다음을 더합니다.
   - NeXTMach 머리 주석 뒤에 머리 주석 덩이(바뀜 목록·사용자 결정·근거).
   - include 여섯 바꿈(D104), `next/cpu.h`·`next/scr.h` 대신 이름 블록(진단 D 의 값, ② 의 꼴), `#define DEV_BSIZE 1024`(④). 표시는 `plan 683 (D104)`·`(D110, D159)` 입니다.
   - §682 ①–⑭ 와 첫머리 검사 지움(진단 C), `l` 의 `register` 지움(E). 표시는 `plan 683 (D024, D159)` 입니다.
   - 단언 셋:
     - F 를 진단 E 의 차이(진단 `NOC`·`NOD`·`B_PHYS_COPY` 정의, A1B 의 1024 와 `m68k_page_*`, `volatile`, `MHZ_20` 정의 자리)만큼 되돌린 대조 원천이 진단 E 와 주석을 뺀 토큰이 같음.
     - L(`08_build/artifacts/m4p683/src/od_L.c`, 주석을 비운 F)과 F 의 토큰·토큰 줄이 같음.
     - 표시 없는 바뀐 줄이 0.
3. 구성: `config_options-m68k.tsv` 를 고칩니다(`wc -l` 22 → 23).
   - `od NOD od.h` 행: 값 `2`, 상태 `confirmed`. 근거는 원본 `_od_drive` 64 B = 2 × 32, `_oddinfo` 8 B, 드라이브 고리 끝 0x40c3e58, run `m4p682-p3` 입니다.
   - 새 행 `oc NOC od.h 1 confirmed`: `_odcinfo` 4 B. 옵션 이름 `oc` 는 `ocdriver` 에서 왔고, `m3_m68k_config_review.py:44` 가 옵션 이름으로 사전을 만들어 `od` 를 겹치지 않게 했습니다.
   - `gen_config_headers.py --arch m68k` 로 `generated/od.h` = `#define NOD 2` + `#define NOC 1` 을 만들고, 다른 생성 머리는 그대로 둡니다. `--check`(m68k·x86) 종료 0.
   - 07 `machargs.c:17` 머리 주석의 "NOD is 1" 을 "NOD is 2" 로 고칩니다(한 줄 안, 줄 수 그대로; 표시 `plan 683 (D159)`).
4. `stage_m68k.py`: `M4FILES[683] = list(M4FILES[679]) + ['od.c']`, `M4HEADERS[683] = list(M4HEADERS[679]) + [('nextdev/odvar.h', 'src/bsd/nextdev/odvar.h'), ('nextdev/canon.h', 'src/bsd/nextdev/canon.h')]`, `EXCEPTS[683] = dict(EXCEPTS[679])`, 머리말 목록.
5. 회귀:
   - `--plan 679` 재생성(`m0p679-r683-stage`)은 보관 `m0p679-a2-stage` 와 `generated/od.h`·`machargs.c` 만 다름.
   - `m0p683-a1-stage` 는 그것과 `od.c`·`odvar.h`·`canon.h` 만 다름.
   - `m5-679.cmd` 는 보관본과 같고, `m5-683.cmd` 는 계획 번호만 다름.
   - M5 205(`m3p683-b679` 보관 679 스테이지·`--plan 679 compare`, `m3p683-cc1`·`--plan 683`)는 객체·출력이 같아야 함(`kern_exit`·`machargs`·`swapgeneric` 는 `NOD` 를 참·거짓으로만 씀; `machargs.c` 는 주석만).
   - x86 입력 `ok` 이고 p679 와 같음; `--plan 683 x86gate` 일곱 같음.
6. 확인 run `m4p683-p1`(바탕 `m0p683-a1-stage`): `od`(F, L), `machargs`(F, L), `swapgeneric`(F, L). 옛 L 이 지금 07 과 토큰이 맞지 않으면 F 에서 새 L 을 만듭니다(§679 선례).
   - 판정: 종료 0, 경고는 `od` 의 `kfree` 1(known_warnings)·나머지는 앞 받아들임과 같음, i386 0.
   - funcbytes: `od` 53 같음 + 주소가 같은 여덟(`chk_od.py` 의 `funcbytes_ok`), `machargs`·`swapgeneric` 은 앞과 같음.
   - L1: `od` 는 사유 bss 하나·`full_span`, `machargs` 는 `OBJECT_MATCH`, `swapgeneric` 은 앞과 같음.
   - F = L. `od` F 와 진단 E 객체는 canon 같음·`obj_sig` header·sections·symbols 같음(STABS 는 달라도 됨). 다시 받아들이는 둘은 앞 받아들인 객체와 canon 같음.
   - `chk_od.py` F·L `ok`(머리 출처는 07 `odvar.h`·`canon.h`·생성 `od.h`).
   - `-E` run `m4p683-e2`(셋 F·L, 진단 E): 토큰 F = L, `od` F = E(`#` 줄 뺌), stderr 0, i386 0.
7. 최종 run `m4p683-a1`(명세 `08_build/artifacts/m4p683/spec.json`; `od`·`swapgeneric` 에 `bss_inferred`, `od` 에 `known_warnings` `kfree`, 명령 파일 `probe.cmd`).
   - zerofill `m4-m68k-zerofill-p683-20261101.json`: `od` 후보는 [0x40b4fbe, 0x40b4fc2), `swapgeneric` 은 p612 후보와 같아야 하고, 남은 받아들인 자리와 겹침이 없어야 함.
   - 확인 기록 `m4-m68k-p683-checks-20261101.json`: 의존 SHA 사슬(`odvar.h`·`canon.h`·`od.h`), 선택지 = M5 줄, 07 = 스테이지, e2·p1 `ok`.
8. 상태: `ACCEPTED` 에서 p517·p612 튜플을 빼고 p683(네 칸)을 넣습니다. 근거는 `m68k-od.md`·`m68k-od.diff`·`m68k-odvar_h`/`canon_h`(NeXTMach 그대로라 diff 없음을 적음)이고, `m68k-machargs.md`·`m68k-swapgeneric.md` 에 plan 683 절을 둡니다. 상태 도구 두 번, 기대(python):
   - 객체 61(OBJECT_MATCH 48, CODE+BSS_INFERRED 13), 행 83/188(행 234).
   - 115756 B(53.62%), `object_bytes` 157948, 부분 행 그대로(235·236 은 이미 있음).
9. 기록: PROVENANCE(새 `od.c`·`odvar.h`·`canon.h`, 생성 `od.h` 행 갱신, `machargs.c` 행 갱신), MODIFICATIONS, DECISIONS D159, `config_options-m68k.tsv`, 계획·HANDOFF·메모리. M7: COMMON 합침(`od_ctrl`·`od_drive`… 48), 호출 대상(`dma_*`·`kmem_*`·`vol_panel_*`·`sfa_*` …), `sf_access_head`.

관문: 명령 종료 0, 경고 기준, i386 0, 회귀 같음, 확인·`-E`·최종·zerofill·확인 기록 `ok`, 상태 도구가 기대와 같음. 어긋나면 멈추고 알립니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 683.1 교차검토(codex `gpt-6.1-sol`, task kol9zepso) 판정과 계획 수정

먼저 제 잘못:
- ① 최종 기록 하나에 `od`·`swapgeneric`(CODE+BSS_INFERRED)과 `machargs`(OBJECT_MATCH)를 함께 넣으려 했습니다. 상태 도구는 네 칸 튜플이면 그 기록의 모든 객체를 bss 사유로 검사합니다(`m4_m68k_status.py:143–187`). 또 명세는 `08_build/artifacts/m4p<plan>/spec.json` 이어야 합니다(같은 파일 153 행).
- ② `m68k_page_*` 가 복사 경로와 함께 없어졌다고 본 것은 잘린 grep 출력(`head`)에 기댄 판단이었습니다. `od_zero_fill` 이 NeXTMach `NeXT_page_size`·`NeXT_page_mask`(`od.c:5042`)를 쓰고, 진단 E 에서는 `m68k_page_*` 입니다(`od_E.c:4891`).
- ③ `-E` 의 F = E 는 그대로는 성립하지 않습니다(F 는 `volatile` 을 뺌).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 네 칸 튜플은 기록의 모든 객체에 bss 검사 → 최종 기록을 나눌 것(p679/p680 선례) | `m4_m68k_status.py:143–187` 을 엶 | ✅ `od`·`swapgeneric` 은 `m4p683-a1`(zerofill), `machargs` 는 `m4p684-a1`(명세 `m4p684/spec.json`) |
| `oc` 행은 생성기가 머리별로 묶어 `od.h` 에 두 줄; 옵션 이름이 겹치지 않음; `m3_m68k_config_review.py` 는 x86 표의 행만 돎(`oc` 는 보고에 안 나옴) | `gen_config_headers.py:30–45`, `m3_m68k_config_review.py:43–44·72` 을 엶 | ✅ 그 한계를 근거에 적음 |
| 어느 받아들인 M4 의 `-M` 출력에도 `od.h` 가 없음(`-imacros meta_features.h` 가 먼저 들임); 상태 도구는 `m4_headers` 만 봄; `machargs.c` 주석 고침은 원천 SHA 로 다시 받아들임을 강제 | `m4p517-a1`·`m4p612-a1` 의 `_log/*.out` grep(이번 세션) 0 건, `m4_m68k_status.py:163`(`source changed`) | ✅ |
| 스테이지 매니페스트 키: 재생성 p679 는 `files`, p683 는 `plan`·`m4_sources`·`m4_headers` 도 | §674.2 선례(`added`·`files`; 이번엔 새 생성 머리가 없어 `added` 는 그대로일 것) | ⚖️ 실제 키는 회귀 단계에서 적음 |
| 상태 기대 61(48/13)·83/188·115756(53.62%)·157948 | python(이번 세션, 인벤토리 행 234 `bytes_min` 24544) | ✅ |
| zerofill 은 `name:obj:ref` 둘; `swapgeneric` 후보 [0x40b5644, 0x40b5648); 도구는 M5 p464 후보만 겹침 검사 → 남은 받아들인 자리와의 겹침을 따로 볼 것 | `m4-m68k-zerofill-p612-20261030.json:15–22`, `m5_m68k_zerofill.py:113–120` | ✅ |
| 주석 고침은 한 줄 안이면 STABS 줄이 그대로; 옛 `machargs_L.c` 는 토큰은 같고 토큰 줄이 다름 → L 은 토큰·토큰 줄이 모두 같을 때만 다시 씀 | `machargs.c:17` 엶; 토큰 줄은 구현 때 python 으로 다시 잼 | ✅ 조건을 고침 |
| `-E` F = E 는 `volatile` 때문에 안 됨; `known_warnings` 는 정확한 stderr 줄; `DEV_BSIZE 512` 는 `#else NeXT` 쪽 | `od_E.c:771`, `m4_m68k_probe.py:385–391`, 스테이지 `sys/param.h:219–238` 을 엶 | ✅ |
| PROVENANCE 는 한 경로 한 행·일곱 칸; `od.h`(1118)·`machargs.c`(1116)·`swapgeneric.c`(1185) 행 갱신 | `PROVENANCE.tsv` 그 줄들 | ✅ |

계획 수정:
- 2 단계: `od_zero_fill` 의 `NeXT_page_size`·`NeXT_page_mask` 를 `m68k_page_size`·`m68k_page_mask` 로 바꿉니다(07 `dma.c:249` 선례; 표시 `plan 683 (D104)`). 대조 원천의 되돌림 목록에서 `m68k_page_*` 는 뺍니다.
- 6 단계: `-E` 는 F = L 이고, F 는 진단 E 에서 `volatile` 토큰 하나를 뺀 것과 같아야 합니다. 옛 L 은 토큰·토큰 줄이 지금 07 과 모두 같을 때만 다시 씁니다.
- 7 단계: 최종 run 둘입니다. 첫째 `m4p683-a1` 은 `od`·`swapgeneric`, `bss_inferred`, `known_warnings` `od` = F 의 정확한 stderr 두 줄이고, zerofill 은 둘(남은 받아들인 bss 자리와의 겹침을 python 으로 따로 봄)입니다. 둘째 `m4p684-a1` 은 `machargs`, OBJECT_MATCH 입니다.
- 8 단계: `ACCEPTED` 에서 p517·p612 를 빼고 p683(네 칸)·p684(두 칸)를 넣습니다. 기대는 그대로입니다.

2차 자기검사: ✅ 행은 이번 세션에 연 줄·python 입니다.

### 683.2 결과(2026-11-01)

먼저 제 잘못: ① 표시 주석 문구를 고치는 스크립트가 문법 오류로 실패했는데, 다음 줄의 `--write` 가 따로 돌아 옛 문구로 07 파일 넷이 쓰였습니다. 방금 만든 새 파일이라 지우고, 고친 생성기로 다시 썼습니다. ② `swapgeneric` 의 funcbytes 를 처음에 정적 자료 대응(`0x40b2bde=_genericconf`·`0x40b5644=_gc`, p612 기록) 없이 돌려 2/4 가 나왔습니다. 대응을 넣어 다시 돌렸습니다. ③ 최종 `machargs` 의 funcbytes 범위를 python 출력(0x4093192)이 아니라 잘못 옮겨 적은 값(0x4093592)으로 한 번 돌렸습니다. `span()` 값으로 다시 돌려 같은 경로의 기록을 바꿨습니다.

- 1–2 07 `od.c` 5284 행(SHA `a0c83470…`), L `08_build/artifacts/m4p683/src/od_L.c`, 07 `nextmach/nextdev/odvar.h`·`canon.h`(NeXTMach 그대로). 단언: 대조 원천 = 진단 E(주석을 뺀 토큰), F 와 L 의 토큰·토큰 줄 같음, 표시 없는 바뀐 줄 0.
- 3 구성: `od NOD 2 confirmed`, 새 행 `oc NOC 1 confirmed`(`wc -l` 22 → 23, 여섯 칸). 생성 `od.h` = `#define NOD 2` + `#define NOC 1` 이고, 다른 생성 머리는 스테이지 사본과 같습니다. `--check`(m68k·x86) 종료 0. `machargs.c:17` 은 "NOD is 2 (plan 683)"(484 행 그대로).
- 4 `stage_m68k.py` 777 → 780 행.
- 5 회귀:
  - `m0p679-r683-stage`(1012)는 보관본과 `generated/od.h`·`machargs.c` 만 다릅니다(키 `files`).
  - `m0p683-a1-stage`(1015)는 거기에 `od.c`·`odvar.h`·`canon.h` 만 더합니다(키 `files`·`m4_headers`·`m4_sources`·`plan`).
  - `m5-679.cmd` 는 보관본과 같고, `m5-683.cmd` 는 계획 번호만 다릅니다.
  - M5 205(`m3p683-b679`·`m3p683-cc1`)는 접두어를 맞추면 객체·출력이 모두 같고(`run.json` 만), `m3p679-cc2` 와도 같습니다. `compare` 둘의 `differ_unexpected`·`lost` 는 비었습니다.
  - x86 `m4-x86-inputs-p683-20261101.json` 은 `ok` 이고 p679b 와 같습니다. `--plan 683 x86gate` 일곱 같음.
- 6 확인 run `m4p683-p1`(`m4-m68k-p683-p1checks-20261101.json` `ok`):
  - 경고는 `od` F·L 의 `kfree` 하나씩뿐, i386 0.
  - funcbytes `od` 53 + 주소가 같은 8, `machargs` 5/5, `swapgeneric` 4/4(F·L).
  - L1: `od`·`swapgeneric` 은 사유 bss 하나, `machargs` 는 `OBJECT_MATCH`.
  - F = L(셋). `od` F 는 진단 E 와 canon·`obj_sig` 전부 같음. `machargs`·`swapgeneric` 은 앞 받아들인 객체와 canon·`obj_sig` 전부 같음.
  - `chk_od.py` F·L `ok`. 머리 출처는 07(`odvar.h`·`canon.h`·`odreg.h`·`sf_access.h`).
  - `machargs` 는 옛 L 의 토큰 줄이 달라 새 L, `swapgeneric` 은 옛 L.
  - `-E` `m4p683-e2`(`ok`): 셋 F = L, `od` F = E − `volatile` 하나, stderr 0.
- 7 최종 run 둘:
  - `m4p683-a1`(`od`·`swapgeneric`; `m4-m68k-p683-final-20261101.json`, SHA `d9e05fe3…`)과 `m4p684-a1`(`machargs`; SHA `cf1bf677…`) 모두 `gate.ok`.
  - zerofill p683 은 `reference-inferred`, `od` [0x40b4fbe, 0x40b4fc2), `swapgeneric` [0x40b5644, 0x40b5648)(p612 와 같음). 남은 받아들인 자리 46 구간과 겹침 없음(python).
  - 확인 기록 `m4-m68k-p683/p684-checks-20261101.json` `ok`. 객체 SHA: `od` `be6b1493…`, `swapgeneric` `3ef9996b…`(p612 와 같음), `machargs` `128e2f60…`.
- 8 상태(`m4-m68k-status-p683-20261101.json`, 표 62 → 63 행; scratch 에 두 번 같음): 객체 61(OBJECT_MATCH 48, CODE+BSS_INFERRED 13), 행 **83/188**, **115756 B(53.62%)**, `object_bytes` 157948, 부분 행 그대로 — 미리 계산한 값과 같음. 근거 `m68k-od.md`·`m68k-od.diff`, `m68k-machargs.md`·`m68k-swapgeneric.md` 에 plan 683 절.
- 9 기록: PROVENANCE 1226 → 1229 행(일곱 칸, 겹침 없음; `od.c`·`odvar.h`·`canon.h` 새 행, `od.h`·`machargs.c`·`swapgeneric.c` 행 갱신), MODIFICATIONS 756 → 758, DECISIONS D159(162 → 163 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D159).

## 685. M4-187 세부 계획 — m68k `pmap.c`(행 310–312) 진단 A1(07 변경 없음; 코딩 전, 2026-11-02)

고른 까닭(python 으로 후보를 견줌; 원본 함수 표의 이름 가운데 NeXTMach 글에 `이름(` 꼴로 있는 것):

| 후보 | 범위 | 항목 | 이름 / NeXTMach 에 있음 |
|---|---|---|---|
| `ev*.c`(행 213–218) | [0x40678ce, 0x406aa70) 12706 B | 58 | 50 / 40 |
| `video.c` 나머지 + `zs.c`(행 255 일부·256·257) | [0x4089786, 0x408d706) 16256 B | 77 | 23 / 21(이름 없는 54) |
| `if_en.c`(행 260 나머지) | [0x408db8a, 0x408fd9e) 8724 B | 26 | 23 / 17 |
| `nextdbg.c`(행 305) | [0x40954b2, 0x4096386) 3796 B | 12 | 10 / 5 |
| **`pmap.c`(행 310–312)** | **[0x4096e20, 0x40990ba) 8858 B** | **47** | **44 / 40** |

`pmap.c` 는 대응이 가장 높고, 세 행이 모두 정확한 행이며, 앞뒤가 받아들인 `pcb`(0x4096e20 에서 끝남)·`shutdown`(0x40990ba 에서 시작)입니다.

확인한 사실(이번 세션; 수는 python):
- 범위 [0x4096e20, 0x40990ba) 8858 B, 항목 47(함수 표 크기 합 8858 = 범위). 참고 글은 NeXTMach mk-108.1 `next/pmap.c`(2398 행, SHA-256 `4a1736ee…`)입니다.
  - 44 항목이 NeXTMach 정의 차례와 같습니다(`pmap_pte` 287 … `pmap_tt` 2354).
  - 0x4096f38 `_m68k_protection_init` 은 NeXTMach `NeXT_protection_init`(361 행)입니다.
  - 이름 없는 0x4096f96(58 B)·0x4096fd0(246 B)·0x40970c6(350 B)는 정적 `pt_init`(419)·`pt_alloc`(429)·`pt_free`(480)로 보이며, A1 이 판정합니다.
  - `pmap_copy_page`·`pmap_zero_page`·`copy_from_phys`·`copy_to_phys` 는 NeXTMach `#ifdef notdef` 의 `#else` 쪽(2319–2347 행)입니다.
- NeXTMach 에 없는 함수 셋(원본 풀이):
  - `_pmap_attribute`(0x4098c1e, 10 B)는 `moveq #4,d0` 를 돌려줍니다(`KERN_INVALID_ARGUMENT`).
  - `_compress_data_from_phys`(0x4098f64, 26 B)는 인수 셋을 그대로 `_compress_data`(0x40329fe)에 넘깁니다.
  - `_uncompress_data_to_phys`(0x4098f7e, 34 B)는 인수 다섯을 그대로 `_uncompress_data`(0x4032a72)에 넘깁니다.
  - 자리는 x86 07 `machdep/i386/pmap.c` 의 차례와 같습니다(`pmap_pageable` 뒤 `pmap_attribute`, `copy_to_phys` 뒤 압축 둘). x86 07 의 셋은 plan 373 에서 x86 원본 바이트로 쓴 꼴입니다(`pmap_phys_to_kern` 을 거침). 진단 B 의 후보입니다.
- NeXTMach 에만 있는 정의 `check_pv_list`(321)·`should_check_pv_list` 는 `#if DEBUG` 안이며, A1 이 판정합니다.
- 자료(scratch `p685/refs.py`):
  - `__data` [0x40b2bca, 0x40b2bde) 20 B 의 값은 `pmap_gc` 1, `pt_zone` = `&ptzone`(0x40c987c), `pte_zone` = `&ptezone`(0x40c9860), `max_virtual_size` 0x04000000, `pmap_coll` 1 입니다.
  - 앞은 받아들인 `m68k_init` 의 [0x40b2b9e, 0x40b2bca), 뒤는 받아들인 `swapgeneric` 의 0x40b2bde 입니다.
  - `max_virtual_size`·`pmap_coll` 은 NeXTMach 에 없는 1997 자료입니다.
  - `__bss` 참조는 0 입니다. 그래서 OBJECT_MATCH 를 목표로 할 수 있습니다.
  - COMMON 참조는 72 주소입니다.
    - `ptzone`·`ptezone` 은 28 B 간격으로, NeXTMach `struct pt_zone`(단일 CPU 에서 잠금 0 B + 7 × 4 B)과 맞습니다.
    - `kernel_pmap_store` 는 24 B 로, NeXTMach `struct pmap`(8 + 4 + 4 + 0 + 8)과 맞습니다.
    - NeXTMach 의 `map_size`·`pv_lock_table`·`NeXT_cache_inhibit` 은 원본 기호에 없습니다.
    - 원본에만 있는 것은 `m68k_cache_inhibit_serial`·`m68k_cache_inhibit_nonserial`·`max_virtual_size`·`pmap_coll` 입니다.
    - `page_table_alloc_size`·`page_table_memory_size`·`managed_page_count` 는 원본에서 COMMON 입니다. NeXTMach 은 `= 0` 으로 초기화하는데, 이 꼴은 `__data` 로 갑니다(`machdep` 의 `nbuf` 선례). 1997 에서 초기화가 없는 것으로 보이며, A1 이 판정합니다.
- 문자열 [0x40ac96e, 0x40ac996) 40 B: `"pmap"`, `"pv_list"`, `"No more room in kernel map"`. 앞은 `pcb` 의 `"pcb"`, 뒤는 `shutdown` 의 문자열입니다(`m68k-shutdown.md` 가 이 차례를 적음).
- 머리: NeXTMach import 는 21 줄입니다. 스테이지 `m0p683-a1-stage` 에 없는 것과 선례 대응은 다음과 같습니다.
  - 선례대로 바꿈(D104):
    - `vm/vm_param.h` → `mach/vm_param.h`, `vm/vm_prot.h` → `mach/vm_prot.h`(`m68k_init`).
    - `next/vm_param.h` → `mach/m68k/vm_param.h`(`m68k_init`). SDK 판의 HISTORY 는 "Converted NeXT_ stuff to m68k_ stuff"(1991)이고, `VM_MAX_KERNEL_ADDRESS` 가 0x14000000 입니다(NeXTMach 0x12000000).
    - `next/mmu.h` → `m68k/mmu.h`(`mem`).
    - `next/pcb.h` 는 뺍니다(`m68k_init`). `pmap_tt` 가 쓰는 `PCB_TT1` 만 진단 정의 `0x80`(NeXTMach `next/pcb.h:34`)으로 둡니다. `struct pcb` 의 `mmu_tt1`·`pcb_flags` 는 07 `thread.h`(D142)에 있습니다.
  - `next/cpu.h` 는 스테이지의 NeXTMach 사본(D109)을 그대로 씁니다(`od` A1 선례; 머리 정리는 함수가 맞은 뒤 따로 합니다). `next/scr.h` 는 진단 `inc`(NeXTMach 사본, `od` 선례)입니다.
  - 기계 의존 pmap 머리: NeXTMach 은 `vm/pmap.h` 를 거쳐 `next/pmap.h` 를 받습니다.
    - 07 `machdep/m68k/pmap.h`(D024, plan 430/433)는 `struct pmap` 의 첫 멤버가 `unsigned int mmu_rp[2]` 이고, pte·pv 꼴이 없습니다.
    - NeXTMach 코드는 `pmap->rp.rp_limit` 등을 씁니다(724–751·927–932 행).
    - A1 은 공유 머리를 바꾸지 않습니다. 소스 첫머리에서 07 머리의 include guard `_MACHDEP_M68K_PMAP_H_` 를 정의하고, 그 자리에 진단 블록을 둡니다. 블록은 NeXTMach `next/pmap.h` 25–235 행(`NeXT_` → `m68k_`)과 07 머리의 Darwin 두 매크로입니다.
    - 블록 앞에 들일 머리(`kern/lock.h`·`kern/zalloc.h`·`mach/vm_statistics.h`·`m68k/mmu.h`·`mach/m68k/vm_param.h`)는 조건을 무시한 include 닫힘에서도 pmap 머리를 끌어오지 않습니다(scratch `p685/incl.py`).
    - 07 에서 어느 꼴로 둘지(공유 머리를 넓힐지, 파일 안에 둘지)는 B 뒤에 따로 정합니다.
- 이름: NeXTMach 의 `NeXT_` 이름 39 개(코드에서 231 번, 진단 블록에서 6 번)를 `m68k_` 로 바꿉니다. 원본 기호가 `m68k_` 이름이고, SDK `vm_param.h` 의 HISTORY 가 그 바꿈을 적습니다. 기계 종류 이름 `NeXT_CUBE`·`NeXT_X15`·`NeXT_WARP9`·`NeXT_WARP9C` 는 `next/scr.h` 의 이름이라 그대로 둡니다. A1 은 주석 밖에서만 바꿉니다.

방법(진단; 07 은 바꾸지 않음; scratch `p685/gen_p685.py` → `08_build/artifacts/m4p685/`):
- 변형 A1 = NeXTMach `pmap.c` + 위 머리 대응(진단 표시) + `NeXT_` → `m68k_` + 진단 블록 + `PCB_TT1` 진단 정의 + 진단 `inc` `next/scr.h`. 그 밖은 NeXTMach 그대로입니다.
- 명세: 바탕 `m0p683-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `pmap`, `m4_id` `["m68k-310", "m68k-311", "m68k-312"]`, `x86_rel` `machdep/i386/dkbad.c`. run `m4p685-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`).
- funcbytes `-p685-A1-`: 대응 `0x4096f96=_pt_init`·`0x4096fd0=_pt_alloc`·`0x40970c6=_pt_free`.
- 측정:
  - 종료와 경고.
  - 함수별 바이트와 재배치 대상, 객체에만 있는 함수, 함수 차례.
  - 절 크기(목표 `__text` 8858, `__data` 20, `__cstring` 40, `__bss` 0).
  - 문자열 블록.
  - 기호·COMMON(D136)·미정의.
  - 의존 출처(i386 0).
- 다른 함수는 scratch `p677/rdiff.py`·`p681/ndiff.py` 꼴로 원본 바이트와 견줍니다.

판정(미리 정함; 07 은 바꾸지 않음):
- 컴파일이 안 되면 원인을 적고, 최소 고침을 한 새 변형을 새 run 으로 돌립니다.
- 되면 함수별 결과를 적고, 1997 바뀜을 원본 바이트로 읽어 진단 B 를 세웁니다(B 앞에 codex 교차검토).

### 685.1 교차검토(codex `gpt-6.1-sol`, task km8pj76dn) 판정과 계획 수정

먼저 제 잘못:
1. `max_virtual_size`·`pmap_coll` 을 "NeXTMach 에 없는 1997 자료" 로 적었습니다. 둘 다 NeXTMach 에 있습니다(`pmap.c:631` `long max_virtual_size = VM_MAX_KERNEL_ADDRESS - VM_MIN_KERNEL_ADDRESS;`, `:1248` `int pmap_coll = 1;`). 286 행까지만 읽고 판단한 탓입니다. 원본 값 0x04000000 은 SDK 의 경계(0x14000000 − 0x10000000)로 계산한 값이고, NeXTMach 경계로는 0x02000000 입니다(python). 그래서 이 값은 `next/vm_param.h` → `mach/m68k/vm_param.h` 대응을 뒷받침합니다.
2. COMMON 참조를 "72 주소" 로만 적었습니다. 구조체 안쪽 주소를 따로 센 수이고, 객체로는 61 입니다(python).
3. `__bss` 참조 0 은 출력된 피연산자만 훑은 결과(`refs.py`)입니다. "직접 참조 0" 으로 고칩니다.
4. 원본 자료 목록에 `__text` 안의 점프 표 둘을 빠뜨렸습니다.
5. `incl.py` 가 `#include ARCH_INCLUDE(prefix/, suffix)` 꼴을 따라가지 않았습니다. 고쳐서 다시 돌렸고, 결과는 같습니다(앞 머리에서 pmap 경로 0).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1–4, 6: 47 항목·44 차례·이름 없는 셋 = `pt_init`·`pt_alloc`·`pt_free`·`#else notdef` 쪽 | 함수 표 python(이번 세션), 원본 0x4096f96–0x4096fce 풀이(`bzero(…, 0x1c)`, +8 에 크기, +0x18 에 `page_size / size`), NeXTMach `pmap.c:419–426` | ✅ |
| 5: 새 셋의 꼴(4 를 돌려줌, 인수 셋·다섯을 그대로 넘김) | 원본 0x4098c1e–0x4098fa0 풀이, 기호 `_compress_data` 0x40329fe·`_uncompress_data` 0x4032a72 | ✅ |
| 7: `_m68k_protection_init` 은 함수 표에서 `confirmed=0`(간접 점프 미해결) | `m68k-functions.tsv` 의 그 행 | ✅ 범위 판정은 funcbytes 로 함 |
| 8: `__data` 20 B 값 | python(이번 세션) `00000001 040c987c 040c9860 04000000 00000001` | ✅ |
| 9: `max_virtual_size`·`pmap_coll` 은 NeXTMach 에 있음 | `pmap.c:631`·`:1248` 열어 봄 | ✅ 위 1 |
| 10: 0x04000000 = SDK 경계 차이 | SDK `mach/m68k/vm_param.h:71–72`, NeXTMach `next/vm_param.h:67–68`, python | ✅ 위 1 |
| 11: `pt_init` 의 `bzero` 0x1c, `pmap_create` 의 0x18 | 원본 풀이(0x4096fa6, 0x4097a90) | ✅ |
| 12: `_map_size`·`_pv_lock_table`·`_NeXT_cache_inhibit`·`_m68k_cache_inhibit` 은 원본 기호에 없음 | `symbols.tsv` 정확한 이름 검색 0 건 | ✅ A1 은 이 차이를 낼 것 |
| 13: 원본의 COMMON 자리만으로는 1997 의 초기화 없음을 증명하지 못함 | 계획 글(이미 "A1 이 판정"); 07 `machdep.c:219–221` 의 `nbuf = 0` 꼴은 원본 `__data`(근거 `m68k-machdep.md`) | ⚖️ 판정은 A1 결과로 함 |
| 14: `__bss` 0 은 출력된 피연산자 범위의 결과 | `refs.py` 읽어 봄 | ✅ 위 3 |
| 15: 72 는 주소 수; 바깥 자료 `_cache`·`_page_size` 둘 | python 으로 객체 수 61; `refs.py` 출력 | ✅ 위 2 |
| 16: 문자열 40 B 와 앞뒤 | python(이번 세션) | ✅ |
| 17·18: `__text` 안 점프 표 둘(0x4096f5c 32 B 여덟 대상, 0x40976c2 20 B 다섯 대상) | python 으로 원본 바이트 풀이, 0x40976b6–0x40976c0 의 표 적재·`jmp` | ✅ 위 4; 측정에 넣음 |
| 19: guard 대체가 배치 차이를 다룸 | 07 `pmap.h` 와 NeXTMach `pmap.h:155–161` | ✅ |
| 20: `incl.py` 가 `ARCH_INCLUDE` 를 놓침, 펼쳐도 pmap 경로 0 | 스테이지 `components/architecture/ARCH_INCLUDE.h`(`#prefix "m68k" "/" #suffix`), `incl.py` 고쳐 다시 돌림 | ✅ 위 5 |
| 21: 블록은 `kern/thread.h` 앞이어야 함(`thread.h:81` → `task.h:74` → `vm_map.h:71` → `vm/pmap.h`) | 세 줄 열어 봄, 고친 `incl.py` 로 `kern/thread.h` 가 07 `machdep/m68k/pmap.h` 에 닿음 | ✅ 계획은 맨 앞에 둠 |
| 22: `OLD_VM_CODE 1` 이라 07 `vm/pmap.h` 선언은 인수 없는 꼴 | 생성 `old_vm_code.h`, 07 `vm/pmap.h:134–165` | ✅ |
| 23: `ASSERT` 는 `vm_object.h:73` → `kern/assert.h`, `MACH_ASSERT 0` 으로 빈 매크로 | 두 파일 열어 봄 | ✅ |
| 24: `PAGE_SIZE`·VM 경계·`P_*`·`FC_SUPER*` 가 스테이지에 있음; `NeXT_MIN_PAGE_SIZE` 등은 쓰이지 않음 | 스테이지 `next/cpu.h:122–129`, `mach/vm_param.h:108`, 이름 수 python(이번 세션) | ✅ |
| 25: `pflush_*`·`pmove_tt1` 은 머리 선언이 없으나 원본 함수(locore) | 원본 기호 0x40013d6·0x40013f4·0x400146e·0x4001498; 07 `pcb.c:83` | ✅ 암묵 선언(C89) |
| 26: `zinit` 은 인수 다섯으로 맞음; `zfree(pmap_zone, pmap)` 은 포인터 → `vm_offset_t` 경고가 날 수 있음 | 스테이지 `kern/zalloc.h:116–126`, NeXTMach `pmap.c:890–892·962` | ✅ 경고는 A1 결과로 기록 |
| 27: 이름 수 39/231/6 | python(이번 세션, 같은 수) | ✅ |
| 28: 원본 `pmap_enter` 는 `pmap_enter_mapping` 에 인수 일곱(+`1`, +`0`), serial/nonserial 두 변수로 고름 | 원본 0x409827e–0x40982a4, `_m68k_cache_inhibit_*` 의 쓰기·읽기(0x409736c…, 0x40984e2…), NeXTMach `pmap.c:1410–1427·1575–1600` | ✅ B 에서 원본 바이트로 씀 |
| 29: 원본은 `kmem_alloc_wired`(0x409702c `pt_alloc`, 0x4097a0a `pmap_init`), NeXTMach 은 인수 둘의 `kmem_alloc` | 원본 호출 python, NeXTMach `pmap.c:452·882` | ✅ B 에서 D150 꼴 |
| 30: funcbytes 는 원본 바이트를 그대로 견주므로 점프 표도 견줌 | 도구가 함수 범위를 바이트로 견줌(§521; 받아들인 `km`·`od` 의 `switch` 표가 같게 나옴) | ✅ |
| 31: 절 크기는 원본 목표이지 A1 예상이 아님(새 셋 70 B) | python 10 + 26 + 34 = 70 | ✅ A1 의 절 차이는 진단 결과 |
| 32: 컴파일은 실제 run 으로만 확인됨 | 규칙(`GCC27_COMPATIBILITY.md`) | ✅ |

계획 수정(A1):
- 사실: `max_virtual_size`·`pmap_coll` 은 NeXTMach 자료이고, 원본에만 있는 자료는 `m68k_cache_inhibit_serial`·`m68k_cache_inhibit_nonserial` 입니다. COMMON 은 61 객체(72 주소)이고, `__bss` 는 직접 참조 0 입니다.
- 측정에 더합니다: 점프 표 둘(funcbytes 의 바이트 비교 안에서), 경고 줄(`zfree` 등).
- A1 에서 나올 것으로 보는 차이(B 에서 원본 바이트로 다룸):
  - 새 함수 셋(70 B).
  - `kmem_alloc` → `kmem_alloc_wired` 두 곳.
  - `pmap_enter_mapping` 의 일곱째 인수와 serial/nonserial 변수.
  - `map_size`·`pv_lock_table`·`m68k_cache_inhibit` COMMON 과 0 초기화 셋.
- 절 크기는 원본 목표로만 적습니다.

2차 자기검사: ✅ 행은 모두 이번 세션에 연 줄이나 python·grep 출력입니다. 13 행만 ⚖️ 입니다(판정을 A1 결과로 미룸).

### 685.2 A1 결과(run `m4p685-p1`, 2026-11-02)와 funcbytes 확장 계획(코딩 전)

A1(`08_build/artifacts/m4p685/src/pmap_A1.c`, SHA-256 `cee093e5…`; 이름 바꿈 231 + 6 건, 계획과 같음; 기록 `m4-m68k-probe-p685-p1-20261102.json`):
- 컴파일 0, 경고 3. `pmap_bootstrap` 의 "large integer implicitly truncated to unsigned type" 둘(A1 997·1036 행)과 `pmap_destroy` 의 `zfree` 둘째 인수 경고(1185 행; codex 주장 26 대로)입니다. 의존 출처에 i386 은 0 입니다.
- 절: `__text` 8162(원본 8858), `__data` 32(원본 20), `__cstring` 40(원본 40), `__bss` 없음.
- 원본에 없는 이름:
  - 미정의 `_zone_alignment` 하나(NeXTMach `pmap.c:689·712`)입니다.
  - COMMON 은 `_map_size`·`_pv_lock_table`·`_m68k_cache_inhibit` 와, 머리에서 온 `_disk_chip`·`_scr1` 입니다. 뒤 둘은 NeXTMach `next/cpu.h`·`next/scr.h` 때문이며 §505·§507 과 같습니다.
- `__data` 의 정의는 `page_table_alloc_size`·`page_table_memory_size`·`managed_page_count`(원본은 COMMON)와 `pmap_gc`·`pt_zone`·`pte_zone`·`max_virtual_size`·`pmap_coll` 입니다. 8 × 4 = 32 B 로 원본보다 12 B 큽니다.
- 객체에 없는 이름은 `_compress_data_from_phys`·`_pmap_attribute`·`_uncompress_data_to_phys` 이고, 객체에만 있는 이름은 없습니다.
- 함수별 비교는 아직 못 했습니다. `m68k_funcbytes.py` 가 "scattered relocation at 0x12e: no symbol at r_value 0x13c" 로 멈췄습니다.
  - 객체의 `__text` scattered relocation 은 하나뿐입니다(python, `macho_obj`). `_m68k_protection_init`(객체 0x118)의 0x12e 필드이고, `r_value` 0x13c 는 같은 함수 +0x24 의 점프 표입니다.
  - 원본은 0x4096f46 `movel #0x4096f5c,a2` 로, 같은 함수 +0x24 를 가리킵니다.
  - 지금 도구의 scattered 갈래는 `r_value` 에 이름 있는 기호(plan 532)가 있거나, `r_value` 가 `__cstring` 안일 때(plan 611)만 받습니다.

funcbytes 확장(plan 685; 도구는 07 이 아니므로 계획·근거에 적음):
- 규칙: scattered 이고, `r_value` 에 이름 있는 기호가 없고, `r_value` 가 객체 `__text` 안이면 다음과 같이 봅니다.
  - 앵커는 `r_value` 를 담은 객체 함수입니다(도구의 함수 표 `objf`).
  - 덧수는 실제 대상(절대 필드는 저장된 낱말, PC 상대는 필드 주소 + 변위) − 그 함수의 시작입니다.
  - 그 함수 이름의 원본 주소(`orig_addr`; 범위 안 함수와 ADDR=NAME 대응을 씀) + 덧수가 원본 필드의 대상과 같을 때 같다고 봅니다.
  - 기록 꼴은 plan 532 와 같습니다(`object` = [이름, 덧수], `original` = `orig_target`, `anchor_original`, `anchor` = `'text'`).
- 그 밖의 갈래는 바꾸지 않습니다. 머리말에 plan 685 줄을 더합니다.
- 회귀:
  - 고치기 전 도구 사본(scratch)과 새 도구를 받아들인 61 객체에 같은 인자로 돌립니다. 인자는 받아들인 객체의 `obj_sha256` 과 SHA 가 같은 funcbytes 기록에서 찾은 범위·대응입니다.
  - 기록 JSON 의 `functions`·`same`·`total`·`object_only`·종료 상태가 같아야 합니다(도구 SHA 칸은 빼고 견줌).
  - 기록은 `m4-m68k-funcbytes-tool-p685-20261102.json` 입니다.
- 새 갈래 시험:
  - A1 객체에서 0x12e 참조가 [`_m68k_protection_init`, 0x24] 로 풀리고 `same` 이어야 합니다.
  - 덧수를 일부러 1 바꾼 비교(시험 안에서 원본 대상을 +1)가 `same` 거짓이어야 합니다.
  - `r_value` 가 함수 앞(객체 `__text` 시작보다 작음)이면 멈춰야 합니다.

판정(미리 정함): 회귀가 하나라도 다르거나 시험이 하나라도 틀리면 도구를 되돌리고 원인을 적습니다. 다 맞으면 A1 의 funcbytes 를 돌리고 함수별 결과로 진단 B 를 세웁니다(B 앞에 codex 교차검토).

### 685.3 교차검토(codex `gpt-6.1-sol`, task k50vba8yu) 판정과 §685.2 수정

먼저 제 잘못:
1. 0x12e 의 scattered relocation 을 "점프 표(+0x24)를 가리키는 것" 으로 적었습니다. 실제로 이것은 `movel #0x4096f78,d0`(원본 0x4096f4c, 필드 0x4096f4e)의 필드이고, 점프 표 끝을 가리킵니다. 저장값 0x158 = `r_value` 0x13c(표 시작) + 덧수 0x1c, 즉 함수 +0x40 이고, 원본도 +0x40 입니다. 표 시작 +0x24 는 0x128 의 local relocation(`movel #0x4096f5c,a2`)이며, 지금 도구가 이미 맞게 다룹니다. 그래서 §685.2 의 양성 시험 기대값을 +0x40 으로 고칩니다.
2. 회귀 인자를 "funcbytes 기록에서" 만 찾는다고 적었습니다. 그 기록이 없는 객체가 12 개입니다(funcbytes 도구보다 먼저 받아들인 것). codex 회신 전에 이미 scratch `p685/fbargs.py` 로 찾았고, 12 개는 plan 611 회귀 기록의 경로·범위·대응을 객체 SHA 로 맞춰 채웠습니다(61/61, 객체 파일 SHA = 상태표).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 2: scattered 는 `r_value`(덧수 없는 항목 값)를 기준으로 옮겨짐 | SDK `mach-o/reloc.h:65–75`·`:117`("the value the item to be relocated is refering to (without any offset added)") | ✅ |
| 3: 대상 기준 앵커는 함수 경계를 넘는 덧수에서 틀릴 수 있음, `r_value` 기준이 나음 | 위 규칙. 계획이 이미 `r_value` 를 담은 함수를 앵커로 둠 | ✅ 계획대로 |
| 4·5: 0x12e 는 +0x40(0x158; 원본 0x4096f78), +0x24 는 0x128 local | python(`macho_obj`, 원본 낱말)과 `image.txt` 189660–189661 행 | ✅ 위 1 |
| 6: relocation 은 모두 VANILLA 4 B. `__text` 는 외부 320 + 외부 PC 43 + local 40 + local PC 51 + scattered 1, `__data` 는 외부 2. PC 상대 scattered 는 없음 | python 집계(이번 세션, 같은 수) | ✅ PC 상대는 합성 시험으로만 봄 |
| 7: 함수 안쪽을 가리키는 local 아홉(표 시작 + 표 항목 여덟)은 이미 원본과 같은 오프셋으로 풀림 | python(+0x24, +0x44/+0x4a 여덟, 원본과 같음) | ✅ |
| 8: `__data` relocation 은 도구가 보지 않음(`text['relocs']` 만 봄) | 도구 165 행 부근(`for r in text['relocs']`) | ✅ 자료는 probe 의 `chk` 꼴 검사로 따로 봄(od `chk_od.py` 선례) |
| 9: `orig_addr` 는 ADDR=NAME 대응과 정적 이름을 받음, 없거나 여럿이면 멈춤 | 도구 129–141 행 | ✅ |
| 10: 새 갈래는 `k >= 0`, `start <= r_value < end`, 빈 함수 표를 따로 검사해야 함(`obj_target` 의 앞 찾기는 검사하지 않음) | 도구 154–158 행: `bisect_right(...) - 1` 을 범위 검사 없이 씀 | ✅ 새 갈래에 검사를 넣음 |
| 11: SHA 가 맞는 funcbytes 기록은 49/61, 없는 12 객체 | `fbargs.py` 출력(이번 세션, 같은 12 이름) | ✅ 위 2 |
| 12: 옛 기록과 견주지 말고 같은 입력으로 옛·새 도구를 새로 돌릴 것, 둘 다 실패면 통과 아님 | 계획(옛 사본과 새 도구를 같은 인자로) | ✅ 종료 0 을 요구함 |
| 13: 시험이 모자람 | 아래 수정 | ⚖️ 합성 가능한 것만 받음(아래) |
| 14–17: 절 크기·`__data` 여덟 이름 32 B·원본에 없는 이름·경고 줄 | python 과 `00.err`(이번 세션) | ✅ §685.2 글과 같음 |

§685.2 수정:
- 새 갈래 규칙:
  - 앵커는 `r_value` 를 담은 객체 함수이며, `objf[k][0] <= r_value < objf[k][1]` 이고 `k >= 0` 이어야 합니다.
  - 함수 표가 비거나 그 범위 밖이면 멈춥니다("unsupported").
  - 덧수 = 실제 대상 − 앵커 함수 시작이며, 같음 조건은 `orig_addr([앵커]) + 덧수 == 원본 대상` 입니다.
- 시험(scratch `p685/tool_test.py`; A1 객체의 사본을 scratchpad 에서 바이트로 고쳐 돌림):
  1. A1 그대로: `_m68k_protection_init` 이 `same` 이고, 그 함수의 참조 수가 local 아홉 + scattered 하나를 포함합니다.
  2. 0x12e 저장값 +1: `refs_differ` 에 [`_m68k_protection_init`, 0x41] 이 나와야 합니다(앵커 표기 확인).
  3. scattered `r_value` 를 앞 함수 안(그 함수 +4)으로 옮김: 앵커가 그 함수가 되고 덧수가 바뀝니다. 원본과 객체의 그 함수 크기에 따라 같음·다름이 바뀌므로, python 으로 기대값을 따로 계산해 맞춰 봅니다.
  4. `r_value` 를 객체 `__text` 끝 밖(`__data` 안)으로 옮김: 지금처럼 멈춰야 합니다(새 갈래에 잡히지 않음).
  5. 대응 `0x4096f96=_m68k_protection_init` 을 더함: `orig_addr` 가 여럿으로 멈춰야 합니다.
  6. 그 함수의 relocation 밖 한 바이트를 바꿈: `byte_differences` 1 이어야 합니다.
  7. scattered 에 PC 상대 비트를 켬: 멈추지 않고 다름으로 나와야 합니다(원본 필드는 절대 꼴).
  - "앞 함수가 없는 `__text` 머리" 는 A1 의 첫 기호가 0 이라 만들 수 없습니다. 검사 코드만 둡니다.
  - 이름 있는 기호와 `__cstring` 갈래가 먼저 쓰이는지는 회귀(plan 532·611 갈래를 쓰는 받아들인 객체)로 봅니다.
- 회귀: 61 객체 모두 옛·새 도구 종료 0, 같은 출력이어야 합니다.

2차 자기검사: ✅ 행은 이번 세션에 연 줄과 python 출력입니다.

### 685.4 funcbytes 확장 결과와 A1 함수별 결과(2026-11-02)

- 도구: `m68k_funcbytes.py` 260 → 273 행(SHA-256 `c58b2e81…` → `346fbcc0…`). §685.3 의 규칙대로 scattered 갈래에 `__text` 앵커를 더했고, 머리말에 plan 685 줄을 더했습니다.
- 회귀(scratch `p685/tool_reg.py`): 61 객체 모두 옛·새 도구가 종료 0 이고, 출력과 기록이 같습니다(도구 칸 뺌).
  - 받아들인 객체의 `__text` scattered 는 이름 있는 앵커(plan 532) 154 건, `__cstring`(plan 611) 8 건입니다. 새 갈래에 걸리는 것은 0 건입니다(python).
  - 처음 돌렸을 때는 61 이 모두 "다름" 이었습니다. 원인은 scratch 사본이 `macho_obj` 를 찾지 못한 것(제 스크립트 잘못)이었고, `PYTHONPATH` 를 주고 다시 돌렸습니다.
- 시험(scratch `p685/tool_test.py`): §685.3 의 일곱 가지가 모두 맞습니다.
  - 2 에서 `refs_differ` 는 [`_m68k_protection_init`, 0x41] 대 원본 0x40, `anchor` `text` 입니다.
  - 3 에서 `_pmap_pte_valid` 는 두 쪽 모두 118 B 라 같음이 기대값과 맞습니다.
- 기록 `m4-m68k-funcbytes-tool-p685-20261102.json`.
- A1 funcbytes(`m4-m68k-funcbytes-p685-A1-20261102.json`): **31/47**, 객체에만 있는 함수 없음.
  - 원본에만 있는 셋: `pmap_attribute`, `compress_data_from_phys`, `uncompress_data_to_phys`.
  - 길이가 다른 13 개(원본 − 객체, B): `pt_alloc` +22, `pt_free` +16, `pmap_set_page_size` +14, `pmap_size` +12, `pmap_map` +6, `pmap_bootstrap` +496, `pmap_init` −24, `pmap_enter` +2, `pmap_enter_mapping` +28, `pmap_extract` +14, `pmap_resident_extract` +14, `pmap_expand_kernel` +16, `pmap_tt` +10.
- 주의: scratch `p677/rdiff.py` 는 한 명령에 relocation 이 둘이면 같은 이름을 붙여 보입니다(`pmap_set_page_size` +0x6c/+0x70 이 `_m68k_page_shift`/`_m68k_pte_shift` 인데 둘 다 `_m68k_pte_shift` 로 보임; `macho_obj` 로 확인). 판정은 funcbytes 로만 합니다.

## 686. M4-188 조사 결과와 세부 계획 — `pmap.c` 진단 B(1997 바뀜; 07 변경 없음; 코딩 전, 2026-11-02)

원본에서 읽은 1997 바뀜(scratch `p685/a1.diff`·`boot.diff`·`boot.addr`; 주소는 원본):
1. `pt_alloc`(0x4096fd0): `kmem_alloc(kernel_map, newsize)` → `kmem_alloc_wired(kernel_map, &newmem, newsize)` 입니다(되돌림 값을 보지 않음, `linkw -4`, 0x409702c). 이어서 `newmem = pmap_resident_extract(kernel_pmap, newmem)` 입니다.
2. `pt_free`(0x40970c6): NeXTMach 의 `ASSERT(pmap_phys_to_index(addr) != -1)`(493 행)이 없습니다. 대신 `magic` 저장과 `free_count = 0` 뒤에 `if (pmap_phys_to_index(addr) != -1 && zone->free_count > zone->elems_per_page)` 가 옵니다.
3. `pmap_set_page_size`: `m68k_cache_inhibit` 대신 `m68k_cache_inhibit_serial = CM_040_INH_SERIAL`(2)·`m68k_cache_inhibit_nonserial = CM_040_INH_NONSERIAL`(3)입니다. 68030 에서는 둘 다 `CM_030_CACHE_INH`(1)입니다.
4. `pmap_size`: 인수가 0 이면 `max_virtual_size`, 아니면 인수로 `howmany` 합니다. 진단 꼴은 둘입니다: B `if (memsize == 0) memsize = max_virtual_size;`, B2 `howmany(memsize ? memsize : max_virtual_size, …)`.
5. `pmap_map`: 여섯째 인수가 생겨 `pmap_enter_mapping(kernel_pmap, virt, start, prot, FALSE, cacheable, 여섯째)` 를 부릅니다.
6. `pmap_enter`: `pmap_enter_mapping(…, wired, TRUE, FALSE)` 입니다.
7. `pmap_enter_mapping`: 일곱째 인수가 생겼습니다. 두 곳의 `cm` 은 `cache_inhibit ? (일곱째 ? m68k_cache_inhibit_serial : m68k_cache_inhibit_nonserial) : m68k_cache` 입니다. 인수 이름은 작성 이름(`serial`)입니다.
8. `pmap_extract`·`pmap_resident_extract`: 조건이 `(int)(pte = pmap_pte(…)) < PTE_ENTRY_NULL || pte->pte_desctype != DT_PTE` 입니다(1668·1708 행).
9. `pmap_expand_kernel`: `panic` 검사 뒤에 `bzero(pte, m68k_pte_size)` 가 있습니다(1772 행 뒤).
10. `pmap_tt`: `pcb = th->pcb` 뒤에 `if (!cache) cacheable = FALSE;` 가 있습니다. `PCB_TT1` 은 0x80000000 입니다(`bset #7` 을 32 비트 `pcb_flags` 의 +0x54 바이트에 함; 07 `trap.c` `TRACE_PENDING` 0x08000000 과 같은 꼴, D142·D144).
11. `pmap_init`: `pv_lock_table` 이 없습니다. `s = round_page(sizeof(struct pv_entry) * npages)` 이고, `kmem_alloc_wired(kernel_map, &addr, s)` 입니다. `zinit` 인수는 NeXTMach 그대로입니다(24, 9600, 0, FALSE, "pmap"; 12, 1200000, 0, FALSE, "pv_list").
12. `pmap_bootstrap`(1312 B, `linkw -16`): 07 `m68k_init.c:451` 의 부름 `pmap_bootstrap(mem_region, num_regions, &virtual_avail, &virtual_end, (vm_offset_t) pmsgbuf - 256)` 과 맞는 인수 다섯입니다. 차례는 다음과 같습니다.
    - `pt_init` 둘, `m68k_protection_init()`, `m68k_ptes_per_page = m68k_btop(PAGE_SIZE)` 입니다. `zone_alignment` 은 없습니다.
    - `kernel_pmap = &kernel_pmap_store; lock_init(&pmap_lock, FALSE);`
    - `align` 은 NeXTMach 그대로입니다.
    - `ptbr = roundup(regions[0].first_phys_addr, align)`, `kernel_pmap->pt1 = ptbr`, 지역 `map_size = pmap_size(0)` 입니다.
    - `avail_kernel_map = ptbr + m68k_pt1_size`, `max_kernel_map = ptbr + map_size`, `regions[0].first_phys_addr` 에 `ptbr + map_size` 를 씁니다. 이 값은 레지스터 d4 에 남아 아래 고리에서 다시 쓰입니다.
    - `ref_count`·`rp` 셋·`m68k_kernel_mmu_rp`·`bzero(ptbr, map_size)` 는 NeXTMach 그대로이고, `SHOW_SPACE` 출력은 없습니다.
    - 두 CPU 모두에서 `pmap_map(trunc_page(0xf0fffff0), 같음, round_page(0xf0fffff0 + 4), VM_PROT_READ|VM_PROT_WRITE, FALSE, TRUE)` 를 부릅니다. 참고 머리에 이름이 없는 주소이므로 숫자로 씁니다(D105·D106 선례).
    - 68040 갈래:
      - `pmap_map` 으로 `P_EPROM`·`P_EPROM_BMAP`(+`P_EPROM_SIZE`, 읽기, TRUE, FALSE), `P_DEV_SPACE` ~ +0xc0040(읽기쓰기, FALSE, TRUE), `SLOT_ID+0x2100000` ~ +0x211e000(읽기쓰기, FALSE, TRUE) 을 잇습니다.
      - `switch (machine_type)` 의 점프 표는 다섯 칸(종류 1–5; 0x40976c2)입니다.
        - 종류 3(`NeXT_WARP9C`): `lbase = P_MAINMEM >> 24; lmask = ~0xd4;` 입니다.
        - 종류 1·2(`NeXT_WARP9`·`NeXT_X15`): `lbase` 는 같고 `lmask = ~0xfc;` 이며, `vidGetFBAddrAndSize(&fbaddr, &fbsize)` 뒤 `pmap_map(fbaddr, fbaddr, fbaddr + fbsize, 읽기쓰기, FALSE, TRUE)` 입니다.
        - 그 밖(종류 0·4·5 와 범위 밖; 4·5 칸은 기본 갈래를 가리킴): 위와 같이 시작하고, 이어서 `pmap_map` 으로 `SLOT_ID+0x2200000` ~ +0x2208000(FALSE, TRUE), `SLOT_ID+0x2210000` ~ +4(FALSE, TRUE), `SLOT_ID+0x3e00000` ~ +0x3e80000(FALSE, FALSE), 화면(FALSE, TRUE)을 잇습니다.
        - 그 다음 메모리 영역 고리입니다: `first_phys_addr >= SLOT_ID + 0x8000000` 인 영역마다 `s = pmap_size(last - first); max_kernel_map += s; avail += s; regions[0].first_phys_addr = avail; pmap_map(first, first, last, 읽기쓰기, TRUE, FALSE)`.
        - 마지막으로 다섯째 인수 `pmap_map(msgbuf, msgbuf, msgbuf + 4084, 읽기쓰기, FALSE, TRUE)` 입니다.
        - 종류 1–3 은 `break` 로 고리와 msgbuf 를 건너뜁니다(0x40976f2·0x4097744 의 `bra` 가 0x4097892 로 감).
      - 끝으로 `tt_lbase = lbase; tt_lmask = lmask;`, `tt_e`·`tt_super`, `tt_cm = cache ? TT_040_CM_COPYBACK : TT_040_CM_INH_NONSERIAL` 입니다.
    - 68030 갈래·`virtual_avail` 부분은 NeXTMach 그대로입니다. 끝 경계는 SDK 의 0x10000000·0x14000000 입니다.
    - 원본에 없는 `map_size` 전역은 지역이 됩니다.
13. 새 함수 셋(§685 확인): `pmap_attribute` 는 `KERN_INVALID_ARGUMENT` 를 돌려줍니다. `compress_data_from_phys(src, dst, count)` 는 `compress_data(src, dst, count)`, `uncompress_data_to_phys(src, dst, count, dstcount, result)` 는 `uncompress_data(src, dst, count, dstcount, result)` 입니다(m68k 는 물리 = 가상). x86 07 `pmap.c` 의 틀(이름·인수)에서 `pmap_phys_to_kern` 만 뺀 꼴이며, 자리는 `pmap_pageable` 뒤와 `copy_to_phys` 뒤입니다.
14. 자료: `page_table_alloc_size`·`page_table_memory_size`·`managed_page_count` 는 초기화를 뺍니다(원본 COMMON). `map_size`·`pv_lock_table`(블록)·`m68k_cache_inhibit` 은 지우고, `m68k_cache_inhibit_serial`·`m68k_cache_inhibit_nonserial` 을 정의합니다. `pmap_bootstrap` 의 `extern int zone_alignment` 은 지웁니다.

방법(진단; 07 은 바꾸지 않음; scratch `p685/gen_p686.py` → `08_build/artifacts/m4p686/`):
- 변형 B = A1 + 위 1–14(4 는 B 꼴). 변형 B2 = B 에서 4 만 B2 꼴. 모든 바뀜에 `plan 686 diagnostic` 표시를 답니다.
- 변형 BD = B + 머리 정리(`od` 진단 D 선례):
  - `#import <next/cpu.h>` → `#import <m68k/cpu.h>` + 파일 안 이름(`slot_id` extern, `SLOT_ID`, `P_EPROM`, `P_EPROM_BMAP`, `P_EPROM_SIZE`, `P_DEV_SPACE`, `P_MAINMEM`; NeXTMach `next/cpu.h` 값).
  - `next/scr.h` → 파일 안 `NeXT_CUBE`·`NeXT_WARP9`·`NeXT_X15`·`NeXT_WARP9C`(진단 `inc` 없음).
  - 목표는 `_disk_chip`·`_scr1` COMMON 이 없어지는 것입니다.
- 종류 4·5 칸은 바이트로 이름·`case` 유무를 가릴 수 없습니다(표 크기 다섯 = 가장 큰 `case` 값 5). 진단은 `case 4: case 5: default:` 로 쓰고, 07 꼴은 나중에 여쭙니다.
- `vidGetFBAddrAndSize` 의 선언은 스테이지 머리에 없습니다(python 확인 예정). 진단은 암묵 선언으로 둡니다.
- 명세: 바탕·`m5_line`·`x86_rel` 은 §685 와 같고, run `m4p686-p1`(REGISTRY 확인)입니다. funcbytes 대응은 §685 와 같습니다.
- 측정은 §685 와 같습니다. 그 밖에 `__data` 20 B 와 값(relocation 셋은 `_ptzone`·`_ptezone` 과 원본 0x40c987c·0x40c9860), COMMON·미정의가 모두 원본에 있는지를 봅니다.

판정(미리 정함; 07 은 바꾸지 않음):
- 47/47 이 아니면, 남은 함수를 원본과 견주어 새 변형을 새 run 으로 돌립니다.
- 47/47 이고 BD 가 원본에 없는 이름을 내지 않으면, 바이트로 가릴 수 없는 꼴을 여쭙고 구현 계획(§687)을 세웁니다.

### 686.1 교차검토(codex `gpt-6.1-sol`, task kpa6zswon) 판정과 계획 수정

먼저 제 잘못:
1. §686 의 12 에서 기본 갈래 첫 `pmap_map` 의 끝을 `SLOT_ID+0x2208000` 으로 적었습니다. 원본은 0x2209000 입니다(0x4097782 `22 7c 02 20 90 00`; 앞서 본 풀이의 35688448 = 0x2209000 을 잘못 옮김).
2. 4(`pmap_size`)의 두 꼴은 부호를 놓쳤습니다. 원본 0x4097416 은 `divsl`(`4c 41 08 00`)인데, NeXTMach 인수 형 `vm_size_t` 는 부호 없는 형이라 두 꼴 모두 `divul` 이 됩니다.
3. 13 의 새 함수 인수 이름을 x86 07 꼴(`src, dst, count`)로 적었습니다. 원본과 부르는 쪽(07 `swapfs.c:507·565`; 원본 0x40329fe·0x4032a72 의 인수 쓰임)으로 보면, 뜻은 `compress_data_from_phys(src, size, dst)`, `uncompress_data_to_phys(src, srcsize, dst, dstsize, 다섯째 = 블록 번호)` 입니다. 바이트는 인수를 차례대로 넘길 뿐이라 이름에 따라 달라지지 않지만, 07 에 쓸 이름은 이 뜻을 따릅니다(작성 이름).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1: A1 기록을 다시 계산하면 같음(31/47) | 같은 도구·입력(이번 세션 실행 결과) | ✅ |
| 2·3·4·5·7·8·9·11·12·14·15: 1·2·3·4(선택)·5·6·7·9·10(캐시)·11 의 내용과 차례, `zinit` 값(9600, 1200000) | 앞서 본 풀이(`a1.diff`·`misc.orig`·`boot.orig`, 이번 세션)와 python 값 풀이 | ✅ |
| 6: `pmap_size` 는 `divsl`(부호 있음), `vm_size_t` 꼴은 부호 없음 | 원본 0x4097416 바이트 `4c 41 08 00`(python), 풀이 `divsl d1,d0` | ✅ 위 2 |
| 10: 8 은 엄격한 `< 0`, 0 은 따로 거르지 않음 | 원본 풀이 `tstl a0; blt` | ✅ 계획 꼴 그대로 |
| 13: 0x80000000 은 32 비트 멤버 식의 실효 값이고, 같은 바이트를 내는 다른 쓰기도 있음 | python(0x80000000 → `80 00 00 00`), 07 `trap.c:122` 선례 | ✅ 07 이름·값은 선례 꼴로, 표기는 나중에 판단 |
| 16·17: 인수 다섯·`linkw -16`·차례, d4 = `ptbr + map_size`, 둥근 `ptbr` 를 영역에 먼저 쓰지 않음 | `boot.orig` 0–47 | ✅ |
| 18: 0x2209000 | python 바이트 | ✅ 위 1 |
| 19: `pmap_map` 열둘의 인수 | `boot.orig`·`boot.addr`(이번 세션) | ✅ 위 1 의 끝 하나만 고침 |
| 20·21: 표 다섯 칸, 종류 0·4·5·범위 밖 = 기본, 고리·msgbuf 는 기본 갈래만 | python 표 풀이, `boot.addr` 의 `bra L+3f2` 둘 | ✅ |
| 22: 기본 갈래는 `vidGetFBAddrAndSize` 를 장치 매핑 셋보다 먼저 부름 | `boot.orig` 188–236 | ✅ 계획 차례에 넣음 |
| 23: 지역 넷의 자리(`lbase` −16, `lmask` −12, `fbsize` −8, `fbaddr` −4) | `boot.orig` | ✅ |
| 24: 고리는 `a2` 에 둔 처음 값으로 매핑함(영역 0 에 쓴 뒤 다시 읽지 않음) | `boot.orig` 241–262 | ✅ 지역 변수 꼴로 씀 |
| 25–27: 고리 구조, 68040 tt, 68030·꼬리 | `boot.orig` | ✅ |
| 28·29: `vidGetFBAddrAndSize` 선언은 스테이지에 없음, 인수는 (주소*, 크기*) | grep 0 건(이번 세션), 원본 0x4089b1e 풀이 | ✅ |
| 30–32: 새 함수는 인수를 차례로 넘김; x86 07 이름은 뜻이 다름 | 07 `swapfs.c:505–507·565` | ✅ 위 3 |
| 33·34: B 의 `__data` 는 20 B 로 예상, 원본 값 | python(이번 세션) | ✅ B 결과로 확인 |
| 35·36: B 에 남는 원본 밖 이름은 `_disk_chip`·`_scr1`(BD 가 다룸); 정적 `_pt_*` 셋은 대응으로 예외 | A1 probe 기록 | ✅ 관문 글에 넣음 |
| 37: 그 밖의 차이는 없음 | 16 함수 목록(§685.4 와 같음) | ✅ |

계획 수정(§686):
- 12: 끝을 `SLOT_ID+0x2209000` 으로 고칩니다. 기본 갈래 차례는 `lbase`·`lmask` → `vidGetFBAddrAndSize` → 장치 매핑 셋 → 화면 → 고리 → msgbuf 입니다. 고리는 지역 `first` 에 처음 값을 두고 씁니다.
- 4:
  - 변형 B 는 인수를 `long memsize` 로 선언하고 `if (memsize == 0) memsize = max_virtual_size;` 를 둡니다.
  - 변형 B2 는 인수 형을 그대로 두고 지역 `long size = memsize ? memsize : max_virtual_size;` 로 `howmany` 합니다.
- 13: 인수 이름은 위 3 의 뜻으로 씁니다(작성 이름, `plan 686 diagnostic`).
- 관문 글: "원본에 없는 이름" 은 바깥 이름을 봅니다. 정적 `_pt_init`·`_pt_alloc`·`_pt_free` 는 funcbytes 대응으로 봅니다.

2차 자기검사: ✅ 행은 이번 세션에 연 풀이·python·grep 입니다.

### 686.2 진단 B–CG 결과(runs `m4p686-p1`–`p4`, 2026-11-02)

- `m4p686-p1`(B·B2·BD): 셋 모두 컴파일되지 않았습니다. `pmap_attribute` 의 `vm_machine_attribute_t` 가 이 번역 단위에 선언되지 않았습니다(제 확인 부족: `mach/mach_types.h` 가 이 경로로 들어온다고 짐작함). 생성기에 `#import <mach/vm_attributes.h>`(진단 표시)를 더해 `08_build/artifacts/m4p686/p2/` 에 다시 썼습니다. 처음 명세는 BD 의 `inc` 칸을 빠뜨려 스테이지 전에 멈췄고, 고쳐서 돌렸습니다.
- `m4p686-p2`:
  - B 45/47, BD 45/47 입니다. 남은 것은 `pmap_size`(80 대 82)와 `pmap_bootstrap`(1304 대 1312)입니다.
  - B2 는 46/47 이라, `pmap_size` 는 지역 `long size = memsize ? memsize : max_virtual_size;` 꼴입니다.
  - BD 는 원본에 없는 바깥 이름이 0 입니다(`_disk_chip`·`_scr1` 없어짐). B 와 canon 이 같습니다.
- `m4p686-p3`(B2 위의 `pmap_bootstrap` 꼴): **C 47/47**, L1 OBJECT_MATCH(전 구간, 0x4096e20)입니다.
  - C 의 꼴은 지역 `avail` 에 `roundup` 을 넣고 `ptbr = avail`, 그 뒤 `avail += map_size` 이며(NeXTMach `*avail_start` 꼴을 지역으로), 고리의 크기는 `map_size` 를 다시 씁니다.
  - 둘 중 하나만 쓴 C2·C3 은 1308 B 입니다.
- `m4p686-p4`(C 위):
  - CD = C + 머리 정리(`m68k/cpu.h` + 파일 안 `slot_id`·`SLOT_ID`·`P_EPROM`·`P_EPROM_BMAP`·`P_EPROM_SIZE`·`P_DEV_SPACE`·`P_DEV_BMAP`·`P_MAINMEM`, `NeXT_CUBE`…`NeXT_WARP9C`; 넷째 매핑 시작을 NeXTMach 이름 `P_DEV_BMAP`(SLOT_ID+0x02100000)으로 씀). 결과는 **47/47**, L1 OBJECT_MATCH, 경고 둘(68030 `tt_lmask = ~0xf0`, `zfree`; NeXTMach 그대로의 줄)입니다.
  - 검사 `scratch/p685/chk_pmap.py`(`chk_od.py` 를 옮김)는 `ok` 입니다. 절 8858/20/40, `__data` 원본과 같음(relocation 둘 `_ptzone`·`_ptezone`), 바깥 기호 49 가 원본 자리, 정적 셋은 대응 자리, COMMON 55 가 모두 원본에 있음(D136), 미정의 27 이 모두 원본에 있음.
  - CE(`case 4:` 없음): 8830 B, 46/47 입니다. 그래서 **`case 4: case 5: default:` 는 바이트가 정합니다**. 표를 만들 때 `case 4` 가 있어야 합니다.
  - CF(`#import <sys/msgbuf.h>` + `MSG_BSIZE`; 4096 − 3 × 4 = 4084, python)와 CG(`extern void vidGetFBAddrAndSize();`)는 CD 와 canon 이 같고 47/47 입니다. 바이트로 가릴 수 없습니다.
- 기록: `m4-m68k-probe-p686-p1/p2/p3/p4-20261102.json`, funcbytes `-p686-{B,B2,BD,C,C2,C3,CD,CE,CF,CG}-`, 검사 `m4-m68k-p686-diagchecks-20261102.json`.
- 판정(미리 정한 대로): 47/47 이고 원본 밖 이름이 없으므로, 바이트로 가릴 수 없는 꼴을 여쭙고 구현 계획(§687)을 세웁니다.

## 687. M4-189 D160 구현 계획 — 07 `src/machdep/m68k/pmap.c`(행 310–312; 코딩 전, 2026-11-02)

사용자 결정(D160 으로 적을 것; AskUserQuestion 넷):
- ① 기계 의존 pmap 꼴은 `pmap.c` 안 블록으로 둡니다(추천안). 공유 07 `machdep/m68k/pmap.h` 는 그대로 두고, `pmap.c` 첫머리에서 그 include guard 를 정의한 뒤 NeXTMach `next/pmap.h` 25–235 행(`m68k_` 이름, `pv_lock_table` 뺌)을 둡니다(D141 선례).
- ② msgbuf 매핑 끝은 `msgbuf + MSG_BSIZE` 로 쓰고 `#import <sys/msgbuf.h>` 를 들입니다(추천안 "숫자" 가 아님; 진단 CF).
- ③ `vidGetFBAddrAndSize` 는 함수 안 `extern void vidGetFBAddrAndSize();` 로 선언합니다(추천안; 진단 CG; D143 선례).
- ④ 나머지는 추천안대로입니다.
  - 작성 이름: `serial`, `msgbuf`, `avail`, `first`, `lbase`, `lmask`, `fbaddr`, `fbsize`, 압축 함수 인수 `src, size, dst` / `src, srcsize, dst, dstsize, index`.
  - `PCB_TT1` 은 NeXTMach 이름에 1997 값 0x80000000 입니다(D144 선례).
  - `#import <mach/vm_attributes.h>` 를 들입니다.
  - NeXTMach 에 같은 이름이 없는 주소는 숫자로 씁니다(셋째 끝은 `P_DEV_SPACE + 0xc0040`).
  - 지운 것은 표시 주석으로 남깁니다(D154).
  - 컴파일되지 않는 `SET_CACHE`·`#else BMAP_TBI` 쪽은 NeXTMach 글에 이름 바꿈만 합니다.

1. 07 `src/machdep/m68k/pmap.c`(새 파일; scratch `p685/gen_p687.py --write`, 없던 파일이어야 함을 단언). NeXTMach mk-108.1 `next/pmap.c`(SHA-256 `4a1736ee…`)에 다음을 더합니다.
   - NeXTMach 알림·HISTORY(1–63 행) 뒤에 머리 주석 덩이(바뀜 목록·결정·근거).
   - include(D104): `vm/vm_param.h` → `mach/vm_param.h`, `vm/vm_prot.h` → `mach/vm_prot.h`, `next/vm_param.h` → `mach/m68k/vm_param.h`, `next/mmu.h` → `m68k/mmu.h` 입니다. `next/pcb.h` 는 뺍니다(`PCB_TT1` 은 파일 안). `next/cpu.h`·`next/scr.h` 는 `m68k/cpu.h` + 파일 안 이름 블록(진단 CD 의 값)으로 바꿉니다. 새 `mach/vm_attributes.h`·`sys/msgbuf.h` 를 들입니다.
   - 기계 의존 pmap 블록(①):
     - guard 정의, 앞 머리 다섯, NeXTMach `next/pmap.h` 의 알림 한 줄("Copyright (c) 1987, 1988, 1989, 1990 NeXT, Inc.", D013·D141 선례)과 25–235 행입니다.
     - 진단 블록에 있던 07 머리의 Darwin 두 매크로(`pmap_phys_address`·`pmap_phys_to_frame`)는 넣지 않습니다. 이 파일은 둘을 쓰지 않고(python 으로 확인), 07 `vm/pmap.h:354–370` 이 매크로가 없을 때 `extern` 선언을 둡니다. Darwin 글(APSL)을 이 파일에 들이지 않으려는 것이며, 바이트가 같은지는 6 의 F 대 CD 비교가 판정합니다.
   - §686 의 1–14 를 진단 C 꼴(`pmap_size` 는 B2, `pmap_bootstrap` 은 C)로 넣고 ②–④ 를 반영합니다. 표시는 `plan 687 (D024, D160)`·`(D104)`·`(D110, D160)` 입니다.
   - 단언:
     - 대조 원천 CDFG(진단 CD + CF + CG 를 같은 생성기 조각으로 만듦)와 F 는, 주석을 뺀 토큰이 Darwin 두 매크로 줄을 빼고 같아야 합니다.
     - L(`08_build/artifacts/m4p687/src/pmap_L.c`, 주석을 비운 F)과 F 는 토큰·토큰 줄이 같아야 합니다.
     - 표시 없는 바뀐 줄이 0 이어야 합니다.
2. `stage_m68k.py`: `M4FILES[687] = list(M4FILES[683]) + ['pmap.c']`, `M4HEADERS[687] = list(M4HEADERS[683])`, `EXCEPTS[687] = dict(EXCEPTS[683])`, 머리말 목록에 687 을 더합니다.
3. 회귀:
   - `--plan 683` 재생성(`m0p683-r687-stage`)은 보관 `m0p683-a1-stage` 와 같아야 합니다(07 의 기존 파일은 바뀌지 않음).
   - `m0p687-a1-stage` 는 그것과 `pmap.c` 만 다르고(manifest 키 `files`·`m4_sources`·`plan`), `m5-683.cmd` 는 보관본과 같으며, `m5-687.cmd` 는 계획 번호만 다릅니다.
   - M5 205(`m3p687-cc1`, 새 스테이지)는 `m3p683-cc1` 과 객체·출력이 같아야 합니다(`compare` 의 `differ_unexpected`·`lost` 비어 있음).
   - x86 입력은 `ok` 이고 p683 과 같아야 하며, `--plan 687 x86gate` 일곱이 같아야 합니다.
4. 확인 run `m4p687-p1`(바탕 `m0p687-a1-stage`; 객체 `pmap` F·L).
   - 종료 0, i386 0 이어야 합니다.
   - 경고는 진단 CD 와 같은 둘이어야 합니다(68030 `tt_lmask = ~0xf0` 의 "large integer implicitly truncated", `zfree` 둘째 인수; NeXTMach 그대로의 줄).
   - funcbytes F·L 47/47, `chk_pmap.py` F·L `ok`, L1 `OBJECT_MATCH`, F = L 이어야 합니다.
   - F 와 진단 CD 객체는 canon 이 같고, `obj_sig` 의 header·sections·symbols 가 같아야 합니다(STABS 는 달라도 됨).
   - 머리 출처에 07 `machdep/m68k/pmap.h` 는 들어오지 않습니다(guard 때문에 `#import` 는 되나 내용은 건너뜀; 의존 목록에는 나올 수 있으며, 그것도 그대로 적습니다).
5. `-E` run `m4p687-e2`(F, L, 진단 CD+CF+CG 원천): 토큰 F = L, F = CDFG(`#` 줄 뺌; 두 매크로는 쓰이지 않아 펼친 뒤에는 차이가 없어야 함), stderr 0, i386 0 이어야 합니다.
6. 최종 run `m4p687-a1`(명세 `08_build/artifacts/m4p687/spec.json`; `refs` = L, `known_warnings` 는 확인 run 의 두 줄을 정확히, bss 없음): `gate.ok` 이어야 합니다. 확인 기록 `m4-m68k-p687-checks-20261102.json` 은 의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지 파일, p1·e2 `ok` 를 단언합니다.
7. 상태: `ACCEPTED` 에 p687(두 칸, OBJECT_MATCH)을 넣고, 근거 `m68k-pmap.md`·`m68k-pmap.diff` 를 먼저 씁니다. 상태 도구를 두 번 돌리고, 기대(python)는 다음과 같습니다.
   - 객체 62(OBJECT_MATCH 49, CODE+BSS_INFERRED 13), 행 86/188(행 310–312 정확한 행 셋).
   - 124614 B(57.73%), `object_bytes` 166806, 부분 행 그대로.
8. 기록: PROVENANCE(새 `pmap.c` 한 행), MODIFICATIONS, DECISIONS D160, `funcbytes` 도구 바뀜(§685.4, 계획·근거에), 계획·HANDOFF·메모리.
   - M7: `m68k_*` 전역·`kernel_pmap_store`·`ptzone` 등의 COMMON 합침, 호출 대상(`vidGetFBAddrAndSize`(video.c), `compress_data`·`uncompress_data`, `kmem_*`·`zinit`·`zalloc`·`zfree`, locore `pflush_*`·`pmove_*`), 바깥 자료 `cache`·`page_size`·`page_mask`·`mem_region`.

관문: 명령 종료 0, 경고 기준, i386 0, 회귀 같음, 확인·`-E`·최종·확인 기록 `ok`, 상태 도구가 기대와 같음. 어긋나면 멈추고 알립니다. 미리 정한 기준은 결과를 본 뒤 바꾸지 않습니다.

### 687.1 교차검토(codex `gpt-6.1-sol`, task k8r2ntl2m) 판정과 계획 수정

먼저 제 잘못:
1. 경고를 "두 줄" 로 적었습니다. CD 의 stderr 는 경고 둘에 함수 문맥 줄 둘이 붙어 네 줄이고(`00.err` 4 행), `known_warnings` 는 그 목록 전체와 견줍니다.
2. Darwin 두 매크로를 빼도 되는 까닭으로 "07 `vm/pmap.h:354–370` 의 `extern` 대체 선언" 을 들었습니다. 그 줄은 `#if OLD_VM_CODE`(133 행)의 `#else`(220 행) 쪽이고, 이 빌드는 `OLD_VM_CODE 1` 이라 들어오지 않습니다. 빼도 되는 까닭은 이 파일이 둘을 쓰지 않는다는 점 하나입니다.
3. 블록 앞 머리를 "다섯" 으로 적었습니다. 실제로는 여섯(`sys/types.h` 포함)입니다.
4. 블록과 guard 정의를 D141 선례라고만 적었습니다. D141 은 파일 안 선언의 선례일 뿐이고, guard 로 공유 머리를 건너뛰는 것은 이 단위가 처음 쓰는 방법입니다(D160 ①).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1: CD stderr 네 줄, `known_warnings` 는 전체 줄 목록 | `wc -l` 4(이번 세션) | ✅ 위 1 |
| 2: 대체 선언은 `OLD_VM_CODE` 의 `#else` 쪽 | 07 `vm/pmap.h:133·220`, 생성 `old_vm_code.h` | ✅ 위 2 |
| 3·4·6: 두 매크로·`PMAP_ACTIVATE` 계열은 이 번역 단위에서 펼쳐지지 않음, `ASSERT` 는 빈 매크로 | CD 의 grep(정의 줄만), 스테이지 grep(guard 쓰는 곳은 07 머리 하나) | ✅ |
| 5: 07 머리의 guard 는 `_MACHDEP_M68K_PMAP_H_` 하나 | 스테이지 grep | ✅ |
| 7: guard 건너뛰기는 D141 선례가 아님 | 07 `vm_machdep.c:26–29`(`vm/pmap.h` 를 그대로 들임) | ✅ 위 4 |
| 8: 블록은 NeXTMach 25–235 행 + 이름 바꿈 − `pv_lock_table` 에 두 매크로뿐 | 생성기 `gen_p685.py`·`gen_p686.py`(이번 세션에 씀) | ✅ |
| 9: `next/cpu.h` 의 알림(1986 NeXT, 1982·1986 버클리 대학)과 `next/scr.h`(1986 NeXT)도 적어야 함 | NeXTMach `cpu.h:1·23`, `scr.h:1`; 07 `fd_io.c` 의 PROVENANCE 알림 칸 선례 | ⚖️ PROVENANCE 알림 칸에 `fd_io` 꼴로 적음(파일 안 이름 블록 표시에 출처를 적음) |
| 10: 앞 머리 여섯 | CD 76–82 행 | ✅ 위 3 |
| 11·12: M5 명령은 `M4FILES` 를 컴파일하지 않음; 상속은 맞음 | `stage_m68k.py` 의 `M4FILES`·`REFS` 쓰임(§683 회귀에서 같은 꼴 확인) | ✅ |
| 13·14: manifest 차이는 `files`·`m4_sources`·`plan`; `compare` 의 빈 목록만으로는 p683 과 같음을 보이지 못함 → 새 M5 객체·출력을 `m3p683-cc1` 과 직접 견줌 | §683.2 의 회귀 꼴 | ✅ 직접 비교를 관문에 넣음 |
| 15–17: 행 310–312 정확한 행, 기대 수치, `object_bytes` 는 `__text` 만 | python(이번 세션) 8858 = 1574 + 7002 + 282, 기대 수치 같음 | ✅ |
| 18·19: OBJECT_MATCH 최종 기록은 `known_warnings` 를 쓸 수 있음(p679 `machdep` 선례), 두 칸 튜플 | p679 명세의 `known_warnings` | ✅ |
| 20: probe 에 `-E` 모드가 없고, od e2 는 따로 만든 `preproc.cmd` 를 씀 | `08_build/artifacts/m4p683/e2/preproc.cmd` 머리 | ✅ 같은 꼴로 만듦 |
| 21: 원천 비교에서는 두 매크로 줄만 빼고, `-E` 비교는 `#` 줄만 빼고 정확히 | 계획 5 와 같은 뜻 | ✅ |
| 22: CD·CF·CG 는 STABS 수가 다름(2006/2008/2002) → F 대 CD 는 비 STABS 술어, 최종 REF 는 L | §683 선례 | ✅ |
| 23·24: CD 47/47 재현; `chk_pmap` 은 COMMON 합침·링크를 증명하지 않음 | 계획의 M7 목록 | ✅ |
| 25: PROVENANCE 한 행에 출처(저장소·커밋·`pmap.c`·`pmap.h`·`cpu.h`·`scr.h`·`pcb.h:34`)와 바뀜 갈래 | PROVENANCE 일곱 칸 규칙 | ✅ |

계획 수정(§687):
- 4·6: `known_warnings` 는 F 의 stderr 네 줄(문맥 줄 포함)을 정확히 씁니다.
- 1: 매크로를 빼는 근거를 "쓰지 않음" 으로 고칩니다. 앞 머리는 여섯입니다.
- 3: M5 새 객체와 출력을 `m3p683-cc1` 과 직접 견주는 것(run 앞머리 경로를 맞춤)을 관문에 넣습니다.
- 8: PROVENANCE 알림 칸에 `next/cpu.h`·`next/scr.h` 의 알림을 적습니다(`fd_io` 선례).

2차 자기검사: ✅ 행은 이번 세션에 연 줄·grep·python 입니다. 9 는 ⚖️ 입니다(파일 안에는 이름 블록 출처 표시만 두는 선례를 따름).
- 1 의 "표시 없는 바뀐 줄 0" 을 코딩 전에 이렇게 구체화합니다(결과를 보기 전).
  - NeXTMach 와 다른 덩이마다 `plan 687` 표시가 있어야 합니다.
  - 예외는 `NeXT_` → `m68k_` 이름 바꿈만 있는 줄입니다. 이 바꿈은 머리 주석에 한 번 적고, 그 줄들은 이름을 되돌리면 NeXTMach 줄과 같아야 합니다(python 단언).

### 687.2 구현 결과(2026-11-02)

먼저 제 잘못:
1. 07 파일 이름 블록 주석의 `next/cpu.h` 줄 범위를 96–128 로 적었습니다. `extern int slot_id;` 는 95 행(`int slot_id;`)에서 왔습니다. 첫 확인·`-E`·최종 run 뒤에 찾았습니다. 그래서 생성기를 고쳐 07 파일을 다시 쓰고(L 은 그대로), 스테이지 `m0p687-a2-stage` 에서 M5·확인·`-E`·최종을 새 ID 로 다시 돌렸습니다. 첫 run 들은 기록으로 남깁니다.
2. 처음 쓴 머리 주석에 "SET_CACHE·!BMAP_TBI 줄은 이름 바꿈만" 이라고 적었습니다. `pmap_bootstrap` 의 그 줄은 다시 쓰면서 없어졌습니다. run 전에 고쳐 다시 썼습니다.
3. 생성기의 표시 수를 24 로 셌습니다(앞에서 따로 바꾼 넷을 빼면 21). 단언이 멈춰서 고쳤습니다.
4. M5 `compare` 에 x86gate JSON 대신 `/dev/null` 을 넘겼습니다(멈춤). x86gate 를 먼저 돌렸고, 처음에 `m5cmp` 에 쓴 것을 선례 자리 `x86gate/` 로 옮겼습니다.
5. x86 입력 검사를 HANDOFF 의 옛 예 `s6ll` 로 먼저 돌렸습니다. p683 과 같은 `s6ln` 으로 다시 돌려 기록을 덮어썼습니다.
6. a1 판 확인 기록 `m4-m68k-p687-checks-20261102.json` 을 a2 판으로 덮어썼습니다. a1 판 명세는 `spec.a1.json`·`probe.a1.cmd` 로 옮겼지만, `probe.cmd.opts.json` 은 a2 의 `cmd` 가 다시 썼습니다.

결과:
- 1 07 `src/machdep/m68k/pmap.c`: 2698 행, SHA-256 `209a7976…`(scratch `p685/gen_p687.py --write`).
  - 단언 셋을 통과했습니다. F 와 CDFG 는 Darwin 두 매크로 줄을 빼면 토큰이 같습니다(9923). F = L 은 토큰·줄 모두 같습니다. 표시 없는 덩이는 0 이고, 이름 바꿈만 있는 줄은 155 입니다.
  - L `08_build/artifacts/m4p687/src/pmap_L.c` 는 `e53e3b37…`(두 판 같음), CDFG `pmap_CDFG.c` 는 `0f98e416…` 입니다.
- 2 `stage_m68k.py` 780 → 783 행(`wc -l`): `M4FILES[687]`·`M4HEADERS[687]`·`EXCEPTS[687]`, 머리말 목록.
- 3 회귀:
  - `m0p683-r687-stage` 는 보관 `m0p683-a1-stage` 와 manifest 가 같습니다.
  - `m0p687-a1-stage` 는 `pmap.c` 만 더해졌고(`files`·`m4_sources`·`plan`), `m0p687-a2-stage` 는 a1 과 `pmap.c` 한 파일만 다릅니다.
  - `m5-683.cmd` 는 보관본과 같고, `m5-687.cmd` 는 계획 번호만 다릅니다(python).
  - M5 205: `m3p687-cc1`(a1)은 `m3p683-cc1` 과 617 파일 가운데 `run.json` 만 다르고, `m3p687-cc2`(a2)는 cc1 과 `run.json` 만 다릅니다.
  - `compare`(`m3-m68k-p687-compare-20261102.json`, `-compare-a2-`)는 `differ_unexpected`·`lost` 가 비었고, 205 객체 항목이 p683 과 같습니다. `stage_vs_test_stage` 는 `pmap.c` 만 늘었습니다.
  - x86: `m4-x86-inputs-p687-20261102.json` 은 `ok` 이고 p683 과 모든 칸이 같습니다. `--plan 687 x86gate`(`08_build/artifacts/m4p687/x86gate/`)는 일곱 스테이지와 머리 SHA 가 p683 과 같습니다.
- 4 확인 `m4p687-p2`(a2; `m4p687-p1` 과 객체 바이트 같음): `m4-m68k-p687-p2checks-20261102.json` `ok`.
  - 종료 0, 경고 넷째 줄까지 기대와 같음, i386 0 입니다.
  - funcbytes F·L 47/47, `chk_pmap` F·L `ok`, L1 OBJECT_MATCH, F = L 입니다.
  - F 대 CD 는 canon·header·sections·symbols 가 같고, STABS 는 2004/2006 입니다.
  - 의존 목록에는 건너뛴 `machdep/m68k/pmap.h` 가 나옵니다.
- 5 `-E` `m4p687-e3`(`m4-m68k-p687-e3-20261102.json` `ok`; e2 도 `ok`): F = L = CDFG(18455 토큰), stderr 0, i386 0.
- 6 최종 `m4p687-a2`(`m4-m68k-p687-final-a2-20261102.json`, SHA-256 `ccf97e1a…`): `gate.ok` 입니다. 확인 기록 `m4-m68k-p687-checks-20261102.json` 은 `ok` 입니다(의존 94, 저장소 파일 78 의 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, funcbytes 47/47). 객체 SHA-256 은 `72d278eb…` 입니다.
- 7 상태(`m4-m68k-status-p687-20261102.json`, 표 63 → 64 행; scratch 에서 두 번 같음): 객체 62(OBJECT_MATCH 49, CODE+BSS_INFERRED 13), 행 **86/188**, **124614 B(57.73%)**, `object_bytes` 166806, 부분 행 그대로입니다. 미리 계산한 값과 같습니다. 근거는 `m68k-pmap.md`·`m68k-pmap.diff` 입니다.
- 8 기록: PROVENANCE 1229 → 1230 행(일곱 칸, 겹침 없음), MODIFICATIONS 758 → 759, DECISIONS D160(163 → 164 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D160).

## 688. M4-190 세부 계획 — m68k `ev.c`(행 213) 진단 A(07 변경 없음; 코딩 전, 2026-11-02)

고른 까닭: §685 후보 표에서 `pmap.c` 다음입니다. 행 213 은 정확한 행이고, 받아들인 `dma` 가 끝나는 0x40678ce 에서 시작합니다. ev 묶음(행 213–218)의 첫 파일이라, 뒤의 `ev_ioctl`·`ev_kbd`·`ev_mouse` 가 쓸 머리 꼴을 여기서 세웁니다. `if_en.c` 는 부분 행이고 1997 새 함수가 여덟이며, `nextdbg.c` 는 NeXTMach 대응이 2/10 입니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p688/ev.dis`(scratch `odis.py`, 원본 바이트); 수는 python):
- 범위 [0x40678ce, 0x4068710) 3650 B, 13 항목입니다. 함수 표 크기 합이 범위와 같고 빈틈이 없습니다. 참고 글은 NeXTMach mk-108.1 `nextdev/ev.c`(698 행, SHA-256 `8669fed3…`)입니다.
- 대응(원본 차례):
  - `evinit`(133 행)·`evopen`(159)·`evclose`(222)·`evselect`(246)·`evmmap`(271).
  - 새 `ev_m_intr`(0x4067cb4, 184 B)·`ev_k_intr`(0x4067d6c, 194 B). NeXTMach 에 없습니다. 부르는 곳은 ADB 코드(0x4065b84·0x4064fd6)이고, 4 B 사건의 주소를 넘깁니다.
  - `evintr`(338)·`evvert`(430).
  - 이름 없는 0x40682e2(212 B)는 `power_intr`(486)입니다. `evinit` 이 `install_scanned_intr` 에 주소를 넘기고, 원본에 바깥 이름이 없으므로 1997 에서 정적입니다.
  - 이름 없는 0x40683b6(160 B)는 정적 `evMsgThreadProc`(548)입니다. `evopen` 이 `kernel_thread` 에 넘깁니다.
  - `evnewevents`(575)·`LLEventPost`(597).
- 따로 된 함수가 없는 것: `add_queued_event`(308)·`process_queued_events`(327)·`power_check`(527)·`myAbs`(588), 그리고 NeXTMach `ev_cursor.c:35` 의 `UniqueEventNum` 은 부르는 자리마다 펼쳐져 있습니다.
  - 큐 고리는 `ev_m_intr`·`ev_k_intr`·`evintr`·`evvert` 안에 있고, `power_check` 는 `evintr`·`evvert` 안에, 절댓값과 `eNum` 고리는 `LLEventPost` 안에 있습니다.
  - 컴파일 줄은 `-O2` 뿐이고 `-finline-functions` 가 없습니다(`m4p687/probe.cmd`). 그래서 1997 글에는 `inline` 이 있었다고 보고, 진단이 판정합니다. `power_check` 는 NeXTMach 에서 쓰는 곳보다 뒤에 정의되므로, 펼쳐지려면 정의가 `evintr` 앞에 있어야 합니다.
  - Darwin 0.1 `driverkit-1/libDriver/Kernel/EventDriver.m:1427–1435` 에 같은 꼴의 `static inline int myAbs`·`static inline short UniqueEventNum` 이 있습니다(구조 참고만, D027).
- 1997 바뀜(원본 바이트로 읽음; 이름은 원본 기호):
  - `evinit`: `*scr2 |= 0x80` 대신 `nbic_bus_enable()` 을 부릅니다. `install_scanned_intr` 의 첫 인수는 0x23b·0x1f70·0x33a 로, NeXTMach `next/cpu.h:213,220,261–262` 의 `I_POWER`·`I_NMI`·`I_KYBD_MOUSE` 값과 같습니다(python). 그 사이에 새 줄 `if (dma_chip != 313) install_scanned_intr(I_PFAIL, call_nmi, 0)`(0x1e71 = `I(7,1,30)`)이 있습니다. `dma_chip` 은 `cmpiw`(`u_short`, 07 `m68k/cpu.h:48`)입니다.
  - `evopen`: 공유 메모리 할당과 2.0 구조 설정이 빠졌습니다(`evmmap` 으로 옮김). 끝에 `evRetryMask = 0` 이 새로 있습니다. 나머지(부팅 그림 끄기, `kminit`, 한 번만 `kernel_thread`, `EBUSY`, `km` 세 칸, `evSelProcess`·`eventPort`, `evOpenCalled = 1`)는 NeXTMach 차례입니다.
  - `evclose`: `evSelProcess` 가 있으면 `thread_deallocate` 를 부릅니다. `kmem_free` 크기는 새 정적(아래 bss)의 `round_page` 입니다. `evScreen` 이 있으면 `kfree(evScreen, evScreenSize)` 를 부르고, `screens`·`evScreen`·`evScreenSize`·`evg`·`sharedMem`·`eventTask` 를 0 으로 둡니다(`evp`·`eventGlobals` 두 줄 대신 `evg` 한 줄).
  - `evselect`: `evg->LLEHead != evg->LLETail` 입니다. 처음 고를 때 `evSelProcess = current_thread()` 다음에 `thread_reference` 를 부릅니다. XPR 은 꺼져 있어 코드가 없습니다.
  - `evmmap`: 처음 부를 때 다음을 합니다.
    - 새 정적에 `totalShmemSize` 를 담습니다.
    - `off >= round_page(totalShmemSize)` 이면 -1 을 돌려줍니다(부호 없는 비교).
    - `kmem_alloc_wired(kernel_map, &sharedMem, round_page(totalShmemSize))` 가 0 이 아니면 `panic("ev: No space for shmem!\n")` 입니다.
    - `eop`(COMMON)에 `sharedMem` 을 두고, `evGlobalsOffset = 8`, `evShmemOffset = evGlobalsOffset + 3274` 로 채웁니다. 3274 는 SDK `bsd/dev/m68k/evio.h` 의 `EvGlobals` 크기(74 + 80 × 40, python)입니다.
    - `evg`·`evs` 를 정하고, 기다림 커서 셋(`waitThreshold` 80 등, SDK `evio.h` 의 `Default*`)과 `waitFrameRate`·`waitSustain`·`waitSusTime`, `lleqSize = LLEQSIZE`, 두 큐의 `queueFlag`·`queueFunc` 를 채웁니다.
    - 키보드 큐 함수는 `adb_keybd_present()` 가 참이면 `process_adb_event`, 아니면 `process_kbd_event` 입니다.
    - 그 뒤는 NeXTMach 차례(`InitMouse`·`InitKbd`·`eventsOpen = 1`)이고, `softint_sched` 대신 `callout_dispatch(2, evvert, 0)` 입니다(`CALLOUT_PRI_RETRACE` 2, 07 `sys/callout.h:57`). 마지막은 `eventTask = current_task()` 입니다.
    - 돌려주는 값은 `atop(pmap_resident_extract(pmap_kernel(), sharedMem+off))` 이고, `pmap_kernel` 은 함수 호출입니다.
  - `ev_m_intr(ev)`·`ev_k_intr(ev)`: `eventsOpen` 이면 `curEvent = *ev` 를 하고, `wereEvents`·큐에 넣기·큐 처리·`evnewevents` 를 합니다(`evintr` 의 갈래와 같음). `ev_k_intr` 는 `eventsOpen` 이 0 이면 `kmintr_process(ev)` 를 부릅니다. 알림 키 검사와 `power_check` 는 없습니다.
  - `evintr`: NeXTMach 와 같습니다. `P_MON` 은 `slot_id` + 0x0200e000(`km` 의 파일 안 이름)이고, `callfree` 는 `ns_callfree`(COMMON 0x40c2424)입니다. EVENTMETER·XPR 은 꺼져 있습니다(생성 `eventmeter.h`·`xpr_debug.h` 0).
  - `evvert`:
    - 반복 키, 마우스 움직임(조건 차례 `mouseDelX`·`mouseDelY`·`movedMask & FORCEMOUSEMOVEDMASK`), 남은 큐, `evnewevents`, 기다림 커서는 NeXTMach 차례입니다. 이름은 `ShowWaitCursor`·`HideWaitCursor`·`AnimateWaitCursor` 입니다.
    - `power_check`·자동 어둡게 뒤에 새 줄 `if (evRetryMask) evretry()` 가 있습니다.
    - `VertRetraceClock` 올리기(0 건너뜀)는 맨 앞에서 맨 뒤로 옮겨졌습니다.
  - `power_intr`: `force_power_down` 검사 뒤에 새 줄 `if (autoDimmed) UndoAutoDim()` 이 있습니다. `evg->eventFlags` 검사(`HARD_OFF_MASK` 0x28), `LLEventPost(NX_SYSDEFINED, powerPoint, &powerData)`, `km_power_down` 은 NeXTMach 와 같습니다.
  - `evMsgThreadProc`:
    - `ipc_kernel = TRUE` 가 없습니다.
    - `msg_copyin`·`msg_queue` 대신 `ipc_kmsg_get_from_kernel(&eventMsg, eventMsg.h.msg_size, 0, &kmsg)` 를 부르고, 성공하면 `ipc_kmsg_copyin_compat_from_kernel(kmsg)` 와 `ipc_mqueue_send(kmsg, 0, 0)`(인수 셋)를 부릅니다.
    - 실패하면 `printf("evMsgThreadProc: msg to window server fails (%d)", r)` 입니다.
  - `evnewevents`: `selwakeup` 뒤에 `thread_deallocate_interrupt(evSelProcess)` 가 새로 있습니다.
  - `LLEventPost`: `eventGlobals` → `evg` 입니다.
    - 합치기 조건 첫머리에 `!evg->dontCoalesce`(+51 의 비트 1)가 새로 있습니다.
    - `switch` 뒤에 `if (EventCodeMask(what) & PRESSUREEVENTMASK) …pressure = lastPressure` 가 새로 있습니다(마스크 0x66, Darwin `ppc/ev_private.h` 의 정의와 같음).
    - 사건 위치는 `int` 둘입니다(SDK `NXEvent`).
    - PMON 줄은 바이트에 없습니다.
- 자료(scratch `p685/refs.py`·`p688/dump.py`):
  - `__data` [0x40b122e, 0x40b1252) 36 B 는 다음과 같습니다.
    - `eventMsg` 28 B: `msg_simple` 1, `msg_size` 28, `msg_type_t` 의 inline 비트. NeXTMach 107–110 행과 같은 값입니다.
    - `force_power_down` 0.
    - 정적 `powerPoint` {0, 0}(`power_intr` 안).
  - 앞 0x40b122c 는 `_swapdev` 이고, 뒤 0x40b1252 는 `ev_kbd` 의 `downCount`·`downKey`(-1)와 `modKeys`(NeXTMach `ev_kbd.c:49–50,73`)입니다.
- `__bss` [0x40b4f5a, 0x40b4fb2) 88 B(이 범위만 참조; 앞 0x40b4f56 은 `dma` 의 `nitro_cache_flush`, 뒤 0x40b4fb2 는 `evdispatch`):
  - `evInitialized` 4(`evopen` 정적), `evSelProcess` 4, `needsMsg` 4.
  - 새 정적 4 B(0x40b4f66): `evmmap` 이 `totalShmemSize` 를 담고 `evclose` 가 `kmem_free` 크기로 씁니다. NeXTMach 에 없으므로 이름은 작성합니다(진단 이름 `sharedMemSize`).
  - `sharedMem` 4, `kbdQueued` 32, `mouseQueued` 32(`PreQueued` 4 + 4 + 4 + 5 × 4), `lleqSize` 4.
  - NeXTMach `evmmap` 의 정적 `returnValue` 는 자리가 없습니다(쓰이지 않는 정적).
  - 정적 bss 가 있으므로 `CODE+BSS_INFERRED` 가 예상입니다.
- `__cstring` [0x40aa03c, 0x40aa0be) 130 B 는 네 문자열입니다: `"Double select!\n"`, `"ev: No space for shmem!\n"`(NeXTMach `"ev: No space!\n"`), `"0x%x spurious keyboard/mouse interrupt\n"`, `"evMsgThreadProc: msg to window server fails (%d)"`.
- COMMON 참조는 52 주소입니다. 원본 COMMON 표에서 `alphaLock`…`waitSustain` 의 55 이름(ev 묶음 변수, `curEvent`, `recon_poll`, `sound_active`, `timer_*` 포함)이 ASCII 차례로 붙은 덩어리를 이룹니다. 관찰일 뿐 근거로 쓰지 않습니다.
- 머리: NeXTMach import 는 33 줄입니다. 스테이지 `m0p687-a2-stage` 에 없는 것과 선례 대응은 다음과 같습니다.
  - `next/cpu.h` → `<m68k/cpu.h>` + 파일 안 이름(`km` 의 D110 꼴: `slot_id`·`intrmask`·`intr_mask`·`P_MON`·`I()`·`I_BIT`·`I_*`).
  - `nextdev/monreg.h` → `<dev/m68k/monreg.h>`, `nextdev/video.h` → `<dev/m68k/video.h>`(`km`, D104).
  - `vm/vm_param.h` → `<mach/vm_param.h>`(`m68k_init`), `machine/mmu.h` → `<m68k/mmu.h>`(`mem`).
  - `nextdev/ev_vars.h` → SDK `<bsd/dev/m68k/event.h>`·`<bsd/dev/m68k/evio.h>`(`km`, D158) + 진단 이름 블록(이 파일이 쓰는 ev 변수의 임시 정의, `PreQueued` 와 마스크 매크로, NeXTMach `ev_vars.h` 와 SDK 이름).
  - `next/scr.h`·`next/xpr.h` 는 이름을 쓰지 않으면 뺍니다(D121).
- PMON: 스테이지의 07 `next/kernel_pmon.h:15` 는 `PMON 1` 입니다. 그러나 원본 바이트에는 `pmon_log_event` 호출이 없습니다(NeXTMach 316–323·667–673·680–687 행). 진단 A 는 이 import 를 빼서 `#if PMON` 을 끕니다. 07 에서 어떤 꼴(import 빼기 / 블록 빼기)로 할지는 구현 계획에서 여쭙니다.

방법(진단; 07 은 바꾸지 않음; scratch `p688/gen_p688.py` → `08_build/artifacts/m4p688/`):
- 변형 A = NeXTMach `ev.c` + 위 머리 대응 + 위 1997 바뀜 + 진단 이름 블록입니다. 바뀐 줄은 모두 진단 표시를 붙입니다. 바이트로 가려지지 않는 꼴은 NeXTMach 에 가까운 쪽을 고릅니다.
  - `inline` 넷(`add_queued_event`·`process_queued_events`·`power_check`·`myAbs`)과 `static inline short UniqueEventNum()`(NeXTMach `ev_cursor.c:35–40`, `evg`)을 둡니다. `power_check` 는 `evintr` 앞으로 옮깁니다.
  - `power_intr`·`evMsgThreadProc` 는 `static` 입니다.
  - `ev_m_intr`·`ev_k_intr` 의 인수는 진단에서 `union hw_event *` 입니다.
  - `ns_callfree` 는 진단에서 `extern int` 입니다(D110 꼴).
- 변형 A2 는 A 와 같되, 꼴이 둘 이상 가능한 세 곳을 다른 쪽으로 둡니다. 세 곳은 서로 다른 함수입니다.
  - `evselect`: `thread_reference(evSelProcess)`(A 는 `current_thread()`).
  - `evmmap`: `eop->` 대신 `((EvOffsets *)sharedMem)->` 로 씁니다.
  - `evvert`: `if (waitFrameTime-- == 1)`(A 는 NeXTMach `--waitFrameTime == 0`).
- 변형 A3 는 A 와 같되, `evvert` 끝의 둘째 증가를 `++evg->VertRetraceClock` 으로 둡니다(A 는 NeXTMach `…VertRetraceClock++`).
- 명세: 바탕 `m0p687-a2-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `ev`, `m4_id` `["m68k-213"]`, `x86_rel` `machdep/i386/dkbad.c`.
- run `m4p688-p1` 입니다(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`).
- funcbytes `-p688-A-`·`-A2-`·`-A3-` 의 대응은 `0x40682e2=_power_intr`·`0x40683b6=_evMsgThreadProc` 입니다.
- 측정:
  - 종료와 경고.
  - 함수별 바이트·재배치 대상, 객체에만 있는 함수, 함수 차례.
  - 절(목표 `__text` 3650·`__data` 36·`__cstring` 130·`__bss` 88).
  - `__data` 는 재배치 없이 원본과 견줍니다.
  - 기호·COMMON(D136)·미정의, 의존 출처(i386 0).

판정(미리 정함; 07 은 바꾸지 않음):
- 컴파일이 안 되면 원인을 적고, 최소 고침을 한 새 변형을 새 run 으로 돌립니다.
- 되면 함수별 결과를 적습니다. 다른 함수는 원본 바이트로 다시 읽고, 그 고침을 진단 B 로 세웁니다(B 앞에 codex 교차검토).
- 13/13 이 되면, 바이트로 가려지지 않는 꼴(이름 블록의 자리와 꼴, 새 정적 이름, 인수 형, PMON 처리, `ns_callfree` 형 등)을 구현 계획 전에 여쭙니다.

### 688.1 교차검토(codex `gpt-6.1-sol`; 첫 요청 task kto2foy7l 은 900 초 안에 끝나지 않아 멈춤, 둘로 나눈 task kzex4frta·k03hzu3zq) 판정과 계획 수정

먼저 제 잘못:
- ① "`inline` 넷" 이라고만 적었습니다. NeXTMach 의 `add_queued_event`·`process_queued_events`·`power_check` 는 바깥 이름이고, 원본에는 이 이름들이 없습니다. GCC 2.7 에서 `static` 없는 `inline` 은 바깥 본문도 냅니다. 그래서 `static inline` 이어야 합니다.
- ② NeXTMach `evmmap` 의 정적 `returnValue` 를 "자리가 없다" 고만 적고, 진단에 그대로 두려 했습니다. NeXT cc 는 쓰이지 않는 함수 안 정적도 `-O2` 에서 bss 에 냅니다. 그 측정이 `06_reconstruction/evidence/x86-machdep_small.md:14–16`(bios.c 의 넷, 16 B)에 있습니다. 그러므로 원본에 자리가 없다는 것은 1997 에서 이 줄이 지워졌다는 뜻입니다.
- ③ 인수 셋인 `ipc_mqueue_send` 호출의 위험을 "진단에서 판정" 으로 미뤘습니다. 다시 따라가 보니 넷 인수 원형이 확실히 보이는 경로가 있습니다. 그대로 두면 컴파일이 멈춥니다.
- ④ `evMsgThreadProc` 에서 "실패하면 `printf`" 라고만 적었습니다. 실제로는 `ipc_mqueue_send` 의 반환도 검사합니다(NeXTMach 은 `msg_queue` 의 반환을 버림).
- ⑤ 함수 포인터로만 쓰는 `process_adb_event` 와 객체 `ns_callfree` 는 암묵 선언이 안 되는데, 이 둘의 선언을 빠뜨렸습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 함수 열셋 가운데 `evMsgThreadProc` 만 빠진 것이 있음: `ipc_mqueue_send` 반환도 검사해 실패 시 출력 | `ev.dis:807–811`(0x406843c `tstl d0`, 0x406843e `beqs 0x40683c4`, 0x4068440 출력); NeXTMach `ev.c:568–570` | ✅ 위 ④; 다른 열두 함수는 지적 없음 |
| 넷 인수 원형에 닿는 경로: `next/autoconf.h:18` → `mach/mach_types.h:206` → `mach/std_types.h:80–81`(`_KERNEL && !MACH_USER_API`) → `ipc/ipc_port.h:95` → `ipc/ipc_mqueue.h:129` | 스테이지 다섯 줄을 열어 봄(`std_types.h` 는 plan 136(D023)의 커널 갈래) | ✅ 위 ③. 원본의 `bsr 0x403f378` 은 26 곳이고, `ev.c` 를 뺀 25 곳 가운데 19 곳은 바로 앞 네 줄이 모두 쌓기(인수 넷)입니다(python, `image.txt`). 나머지 6 곳(0x4044498·0x40458c2·0x4045c3e·0x4048b8c·0x4048c9a·0x4048fb0)은 갈래 앞에서 쌓기 시작해, 넷 줄 창으로는 인수 수를 다 보지 못했습니다. (처음에는 grep 앞 20 줄만 보고 "20 곳 모두 넷" 이라 적었다가 이렇게 고쳤습니다.) 그래서 진단은 원형을 피한 호출 `((mach_msg_return_t (*)())ipc_mqueue_send)(kmsg, 0, 0)` 로 씁니다. 바이트가 같은지는 진단이 판정하고, 07 꼴은 여쭙니다 |
| `kern/thread.h` 만으로는 경로를 못 찾음 | `kern/thread.h:63–84` 의 include 를 봄(`ipc/ipc_kmsg_queue.h`, `kern/task.h` 등) | ⏭️ 경로 하나로 이미 정해지므로 더 따지지 않음 |
| `install_scanned_intr` 원형은 `int (int, func, void *)`, `func` = `int (*)(void *)`; 형 변환을 지킬 것 | `next/autoconf.h:35`, `sys/callout.h:33` | ✅ NeXTMach 의 `(func)` 형 변환을 그대로 둠 |
| `kmem_alloc_wired`·`kmem_free`·`thread_reference`·`thread_deallocate` 는 옛 꼴 선언 | `vm/vm_kern.h:68,71`, `kern/thread.h:303–304` | ✅ 인수 검사 없음 |
| `ipc_kmsg_get_from_kernel` 은 인수 넷 원형, 첫 인수 `mach_msg_header_t *` | `ipc/ipc_kmsg.h:306–310` | ✅ 07 `kern/ipc_mig.c` 꼴로 `(mach_msg_header_t *) &eventMsg` 형 변환 |
| `nbic_bus_enable` 등 열세 이름은 스테이지 머리에 선언이 없고, `process_adb_event`(값으로 씀)·`ns_callfree`(객체)는 암묵 선언이 안 됨 | C 규칙(암묵 선언은 호출에만 생김); 진단 이름 블록에 넣을 목록과 견줌 | ✅ 위 ⑤. 진단 이름 블록에 `process_adb_event`·`process_kbd_event`·`process_mouse_event`(값으로 씀)·`ns_callfree` 선언을 넣음 |
| `pmap_kernel()` 은 선언됨, `current_task()` 는 매크로 | `vm/pmap.h:288`, `kern/thread.h:350` | ✅ |
| SDK m68k `event.h`·`evio.h` 끼리는 충돌 없음, 일반 `bsd/dev/evio.h` 는 들이지 말 것 | m68k `event.h:27`·일반 `event.h:26` 이 같은 `EVENT_H` 를 씀; 일반 `evio.h` 가 있음 | ⏭️ 진단은 일반 `evio.h` 를 들이지 않음(충돌 여부는 컴파일이 판정) |
| 완전히 펼쳐지고 주소를 쓰지 않는 `static inline` 은 본문이 안 남음; 뒤에 정의된 함수는 앞 호출에 펼쳐지지 않음; `static` 없는 `inline` 은 바깥 본문을 냄 | GCC 2.7 규칙. cc-744.13 에서는 아직 재지 않음(codex 도 못 잼) | ⚖️ 위 ①로 계획을 고침. 실제는 진단이 판정 |
| 쓰이지 않는 함수 안 정적도 NeXT cc `-O2` 에서 나옴 | `x86-machdep_small.md:14–16`, `s5p16-l1-bios-O2-20261001.json:15–18`(`__bss` 16, `unplaced`) | ✅ 위 ②; A 에서 `returnValue` 를 지움(진단 표시) |
| bss 차례 = 함수 안 정적(그 함수를 컴파일할 때) 다음 파일 정적(선언 차례) | 원본 배치와 맞음; 컴파일러 규칙으로는 재지 않음 | ⚖️ 진단이 판정 |
| `waitFrameTime`: `waitFrameTime-- == 1` 쪽이 더 그럴듯 | `ev.dis:665–671` | ⚖️ A(`--…== 0`)·A2(`…-- == 1`) 둘을 다 이미 잼 — 그대로 |
| `VertRetraceClock`: 둘째도 `++` 앞쪽이 더 그럴듯(둘째 증가 뒤에도 다시 읽음) | `ev.dis:695–704`; `evio.h:178` 의 volatile | ⚖️ A·A3 로 이미 잼; 둘 다 다르면 증가와 검사를 나눈 꼴을 다음 변형으로 |
| `evselect`: `current_thread()` 로 대입하고 `thread_reference(current_thread())` 가 더 그럴듯 | `ev.dis:162–165` | ✅ A 그대로, A2 가 다른 꼴 |
| `evmmap`: `eop` 대입 뒤 volatile 칸을 다시 읽는 꼴이 더 그럴듯; 지역 포인터 꼴도 시험할 만함 | `ev.dis:203–216` | ⚖️ A·A2 로 재고, 둘 다 다르면 지역 포인터 꼴을 다음 변형으로 |

2 차 자기검사: ✅ 행을 다시 읽으며 근거를 확인했습니다. 근거는 모두 이번 세션에 연 줄입니다(`ev.dis` 807–811·162–165, 스테이지 머리 다섯 줄과 `autoconf.h:35`·`callout.h:33`·`vm_kern.h:68,71`·`thread.h:303–304,350`·`ipc_kmsg.h:306–310`·`pmap.h:288`, `x86-machdep_small.md:14–16`, `image.txt` 의 호출 20 곳). 계산이 들어간 행은 없습니다.

고친 변형 A(A2·A3 도 같은 바탕):
- 보조 넷과 `UniqueEventNum` 은 `static inline` 입니다.
- `evmmap` 의 `static int returnValue;` 는 지웁니다.
- `ipc_mqueue_send` 는 원형을 피한 호출로, `ipc_kmsg_get_from_kernel` 첫 인수는 형 변환으로 씁니다.
- 반환 검사는 둘 다(`get` 실패 또는 `send` 실패 시 출력)입니다.
- 진단 이름 블록에 값으로 쓰는 함수 셋과 `ns_callfree` 의 선언을 넣습니다.

### 688.2 진단 A·A2·A3 결과(run `m4p688-p1`, 2026-11-02)

- 세 변형 모두 컴파일됐습니다(rc 0). 경고는 각 한 줄 `passing arg 1 of 'kfree' makes integer from pointer without a cast`(`evclose`)입니다.
- `__text` 3650 B 로 목표와 같고, 세 객체는 `canon`·`obj_sig` 가 서로 같습니다(probe 기록 `m4-m68k-probe-p688-p1-20261102.json`). 그래서 A2·A3 의 다른 꼴 넷(`thread_reference(evSelProcess)`, `((EvOffsets *)sharedMem)->`, `waitFrameTime-- == 1`, 둘째 `++…VertRetraceClock`)은 바이트로 가려지지 않습니다.
- funcbytes(정적 기호의 원본 주소는 python 으로 계산해 넘김, scratch `p688/maps.txt`): 세 변형 모두 **13/13** 함수가 같습니다(`m4-m68k-funcbytes-p688-{A,A2,A3}-20261102.json`). 원형을 피한 `ipc_mqueue_send` 호출도 원본과 같은 `bsrl` 입니다.
- 절: `__data` 36·`__bss` 88·`__cstring` 130 입니다. `__data`(재배치 0)와 `__cstring` 은 원본 [0x40b122e, 0x40b1252)·[0x40aa03c, 0x40aa0be) 와 바이트가 같습니다(python).
- 정적 배치: 객체의 bss 차례 `evInitialized.28` 0, `evSelProcess` 4, `needsMsg` 8, `sharedMemSize` 12, `sharedMem` 16, `kbdQueued` 20, `mouseQueued` 52, `lleqSize` 84 가 원본 [0x40b4f5a, 0x40b4fb2) 의 참조 배치와 같습니다. `powerPoint.51` 은 `__data` +32(0x40b124e)입니다.
- L1 은 `__DATA,__bss: unverified` 로 `provisional` 입니다(정적 bss). 미정의 가운데 원본에 없는 이름은 0 입니다.
- COMMON 에는 이 파일이 정의한 ev 변수와, 공유 머리에서 온 `_alert_key`·`_km`·`_km_coni`·`_file_list`·`_master_cpu`·`_tthiwat`·`_tthog`·`_ttlowat`·`_timer_*` 가 있습니다. 원본에 있는지는 상태 도구가 D136 으로 판정합니다.

판정(미리 정한 대로): 13/13 이므로 진단 B 는 없습니다. 바이트로 가려지지 않는 꼴을 구현 계획 전에 여쭙니다.

## 689. M4-191 D161 구현 계획 — 07 `src/machdep/m68k/ev.c`(행 213; 코딩 전, 2026-11-02)

사용자 결정(D161, 2026-11-02; AskUserQuestion 답):
- ① ev 변수 이름은 `ev.c` 안 블록에 `extern` 으로 둡니다(권장안 "임시 정의" 대신; `km.c` 꼴).
- ② PMON 은 `#import <next/kernel_pmon.h>` 를 두고, `#if PMON … #endif` 블록 셋(NeXTMach 316–323·667–673·680–687 행)을 지웁니다(권장안 "import 를 뺌" 대신).
- ③ `kfree` 경고는 `kfree((vm_offset_t)evScreen, evScreenSize)` 형 변환으로 없앱니다(권장안 known_warnings 대신).
- ④ 나머지는 권장대로입니다.
  - 새 정적 이름 `sharedMemSize`, `ev_m_intr`·`ev_k_intr` 인수 `union hw_event *`.
  - `extern int ns_callfree`, `ipc_mqueue_send` 의 형 변환 호출.
  - 가려지지 않은 네 곳은 A 꼴, `evSelProcess` 는 `struct proc *`.
  - 지운 줄은 표지 주석(D154).
  - 보조 넷과 `UniqueEventNum` 은 `static inline`, `power_check` 는 `evintr` 앞.

①–③ 은 진단 A 와 글이 다릅니다(바이트는 같으리라 보지만 재지 않았음). 그래서 아래 확인 run 에서 L 을 새로 잽니다.

방법:
1. 꼴 L(`08_build/artifacts/m4p689/src/ev_L.c`) = 진단 A + ①–③. scratch `p688/gen_p689.py` 가 NeXTMach `ev.c` 에서 만듭니다.
   - ①: 진단 이름 블록의 임시 정의 30 개를 `extern` 으로 바꿉니다: `eop`·`evg`·`evs`·`evScreen`·`evScreenSize`·`screens`·`totalShmemSize`·`evRetryMask`·`evOpenCalled`·`eventsOpen`·`waitSustain`·`waitSusTime`·`waitFrameRate`·`waitFrameTime`·`eventPort`·`eventTask`·`leftENum`·`rightENum`·`clickTime`·`clickLoc`·`clickState`·`clickTimeThresh`·`clickSpaceThresh`·`mouseDelX`·`mouseDelY`·`keySema`·`lastPressure`·`autoDimPeriod`·`autoDimmed`·`autoDimTime`. NeXTMach `ev.c` 자체의 `union hw_event curEvent;`(84 행)는 그대로 임시 정의입니다.
   - ②·③: 위와 같습니다.
2. 07 파일 F = L + 머리 주석 블록 + 표지(`plan 689 (D…)`)입니다. 진단 표지 `plan 688 diagnostic` 은 `plan 689 (D024, D161)` 등 결정 번호로 바꿉니다.
   - 머리 주석은 NeXTMach 머리(1–42 행, `Copyright 1987 NeXT, Inc.`)를 그대로 두고 그 뒤에 넣습니다(D013).
   - 검사(python): F 와 L 의 주석을 뺀 토큰이 같아야 합니다. NeXTMach 와의 차이 hunk 는 모두 표지가 있어야 합니다(지운 줄은 표지 주석, BEGIN/END 구역은 구역 전체로 셈).
3. `stage_m68k.py`: `M4FILES[689] = list(M4FILES[687]) + ['ev.c']`, `M4HEADERS[689] = list(M4HEADERS[687])`(새 머리 없음), `EXCEPTS[689] = dict(EXCEPTS[687])`. docstring 의 `--plan` 목록에도 689 를 넣습니다.
4. 회귀(07 공유 머리는 바꾸지 않음):
   - 계획 687 스테이지를 다시 만들어 보관본(`m0p687-a2-stage`)과 같은지 봅니다.
   - 새 스테이지 `m0p689-a1-stage` 와의 차이가 `src/machdep/m68k/ev.c` 하나뿐인지 봅니다.
   - M5 205 줄을 두 스테이지에서 컴파일해 객체·stderr 가 같은지 봅니다(`stage_m68k.py compare`, run `m3p689-cc1`·`cc2`).
   - x86 입력(`m4_x86_inputs.py s6ln`)과 `x86gate` 가 앞과 같은지 봅니다.
5. 확인 run `m4p689-p1`: 변형 F(`@machdep/m68k/ev.c`)·L.
   - 둘 다 funcbytes 13/13 이어야 합니다.
   - `__data` 36·`__cstring` 130 이 원본과 바이트 같고, bss 88 의 정적 차례가 §688.2 와 같아야 합니다.
   - F 와 L 의 `canon`·`obj_sig`(STABS 수 제외) 가 같아야 합니다.
   - 경고는 0 줄이어야 합니다(③).
   - 미정의 가운데 원본에 없는 이름이 0, COMMON 은 원본에 있어야 합니다(D136).
6. `-E` run `m4p689-e1`: F 와 L 의 전처리 토큰이 같아야 합니다.
7. 최종 run `m4p689-a1`: 명세 `08_build/artifacts/m4p689/spec.json`.
   - `refs` 는 p1 의 L 객체(SHA-256)이고, `bss_inferred: ["ev"]` 입니다.
   - 변형 F, `m4_id` `["m68k-213"]` 입니다.
   - 관문은 `gate.ok` 이고, 등급은 `CODE+BSS_INFERRED` 입니다.
8. 기록:
   - 근거 문서 `06_reconstruction/evidence/m68k-ev.md`·`m68k-ev.diff`.
   - 상태표 `m68k-m4-status.tsv` 에 한 행을 더합니다(상태 도구 ACCEPTED 에 최종 기록 SHA, 두 번 돌려 같음, 앞 행 그대로).
   - 상태 기대(python): 객체 63(OBJECT_MATCH 49, CODE+BSS_INFERRED 14), 행 87/188, 행 바이트 124614 + 3650 = 128264 B = 215874 의 59.42%, `object_bytes` 166806 + 3650 = 170456.
   - PROVENANCE 한 행(일곱 칸; NeXTMach mk-108.1 `nextdev/ev.c`, `nextdev/ev_vars.h` 의 이름·매크로 줄, `nextdev/ev_cursor.c:35–40` 의 `UniqueEventNum`, `next/cpu.h` 의 이름, Darwin 은 구조 참고만), MODIFICATIONS 한 행, DECISIONS D161, 계획 §689.x, HANDOFF·메모리.
   - M7 링크 의무: 이 객체는 ev 변수 30 개를 `extern` 으로만 씁니다. 그래서 그 COMMON 을 정의할 객체(뒤 `ev_kbd`·`ev_mouse`·`ev_ioctl` 단위나 링크)를 적습니다. `power_intr`·`evMsgThreadProc` 의 정적 이름과 bss 88 B 의 자리도 함께 적습니다.

판정(미리 정함):
- 5–7 이 모두 통과하면 받아들입니다.
- L 이나 F 가 13/13 이 아니거나 자료가 다르면 멈춥니다. ①–③ 가운데 어느 것이 바이트를 바꿨는지 적고 여쭙습니다(기준을 늦추지 않음).

### 689.1 교차검토(codex `gpt-6.1-sol`, task k50wo9piu) 판정과 계획 수정

먼저 제 잘못:
- ① §688 의 "스테이지의 07 `next/kernel_pmon.h:15` 는 `PMON 1` 입니다" 가 틀렸습니다. 그 줄은 `#ifdef DEBUG`(13 행) 안에 있습니다. m68k 빌드에는 `DEBUG` 가 없습니다: 스테이지의 `generated`·`src/bsd/next`·`src/bsd/sys`·`src/machdep/m68k` 에 `#define DEBUG` 0 건, `probe.cmd` 에 `-DDEBUG` 0 건이고, `m68k-fd_subr.md:13` 도 같은 사실을 적습니다. 그러므로 NeXTMach 글을 그대로 둬도 `#if PMON` 블록은 코드를 내지 않습니다. 이 틀린 전제로 결정 ② 를 여쭸으므로, ② 를 다시 여쭙니다.
- ② §689 에 zerofill 단계(`m5_m68k_zerofill.py`, 받아들인 다른 bss 자리와의 겹침 검사, `ACCEPTED` 의 넷 칸 항목)를 빠뜨렸습니다. `CODE+BSS_INFERRED` 에는 이것이 필요합니다.
- ③ 확인 기록의 검사 목록(의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, 종료 0, i386 0, `-E` stderr 0), A → L 의 허용 차이 단언, 받아들인 `m3p687-cc2` 출력과의 직접 비교를 빠뜨렸습니다. 또 관문 문장에 4 단계(회귀)가 빠져 있었습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| ev_A.c 의 임시 정의 30 개가 §689 ① 목록과 차례까지 같음; `curEvent` 는 블록 밖 | python 으로 블록을 따로 뽑아 견줌(30 = 30, 차례 같음) | ✅ |
| `extern` 으로 바꾸면 COMMON 이 미정의 참조가 되어 `obj_sig` 의 기호 칸(종류·값)이 A 와 달라짐; 재배치 대상은 같고 `canon` 은 이름으로 풀므로 같을 것 | `l2_prefix_diff.py:48–53`(기호 `[name, kind, ext, sect, value]`), `m3_m68k_diag.py:34–43`(외부 재배치는 이름) | ✅ A 와 L 의 비교는 `canon` 같음 + `obj_sig` 기호 차이가 30 이름(COMMON → UNDF)뿐임을 단언으로 둠 |
| `PMON 1` 은 `#ifdef DEBUG` 안 | `kernel_pmon.h:13–15` | ✅ 위 ① |
| `kernel_pmon.h` 를 다시 들여도 저장소 정의는 없으리라 보나, 재지 않음 | 머리 내용(`DEBUG` 없으면 빈 매크로와 pmon 머리 둘) | ⚖️ 확인 run 이 판정 |
| `kfree((vm_offset_t)evScreen, …)` 는 바이트가 같으리라 봄(원형이 `vm_offset_t`) | `kern/kalloc.h:62` | ⚖️ 확인 run 이 판정 |
| PMON 블록 셋을 지워도 C 가 바름(`else { …; }` 남음, 680–687 은 `else` 째 지워짐) | NeXTMach `ev.c:314–325,667–688` | ✅ |
| zerofill 단계와 넷 칸 `ACCEPTED` 가 빠짐 | `m4_m68k_status.py:144–149,180–189`, §683 의 1299–1300·1330 행 | ✅ 위 ② |
| A → L 단언, F = L 의 토큰 줄, 확인 목록, 회귀를 `m3p687-cc2` 에 직접 견주기 | §687 의 1703–1706·1719–1727·1748·1786–1788 행 | ✅ 위 ③ |

2 차 자기검사: ✅ 행의 근거는 모두 이번 세션에 연 줄이거나 python 출력입니다.

계획 수정:
- 1 단계: L 과 진단 A 를 견줘, 주석을 뺀 토큰 차이가 ①–③(그리고 다시 여쭐 ②의 답)뿐임을 단언합니다.
- 4 단계: M5 205 출력을 받아들인 `m3p687-cc2` 에 직접 견주고, 생성 명령 파일도 견줍니다.
- 5 단계: F = L 은 토큰과 토큰 줄이 같아야 합니다. A 와 L 은 `canon` 이 같고, `obj_sig` 차이는 30 이름의 기호 종류뿐이어야 합니다.
- 7 단계 뒤: zerofill 기록 `m4-m68k-zerofill-p689-20261102.json` 을 둡니다. `ev` 후보는 [0x40b4f5a, 0x40b4fb2) 이어야 하고, 남은 받아들인 bss 자리와 겹침이 없어야 합니다(python 으로 따로도 봄). `ACCEPTED` 에는 넷 칸 항목을 넣습니다.
- 확인 기록 `m4-m68k-p689-checks-20261102.json`: 의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, 종료 0, i386 0, `-E` stderr 0.
- 관문: 4–7 단계와 zerofill·확인 기록이 모두 `ok` 이고, 상태 도구가 기대와 같아야 합니다. 어긋나면 멈추고 알립니다.

### 689.2 구현 결과(2026-11-02)

먼저 제 잘못:
1. §688 의 PMON 사실이 틀렸고, 그 전제로 ② 를 여쭸습니다. §689.1 에서 바로잡고 다시 여쭈어 "NeXTMach 그대로" 로 정했습니다.
2. §689 첫 판에 zerofill·확인 목록·회귀 기준이 빠졌습니다. codex 가 잡았고, 코딩 전에 넣었습니다(§689.1).
3. 진단 생성기 첫 판에 주석 밖으로 글이 새는 줄 셋(`/* … */ A2` 등)과, 주석이 일찍 닫히는 줄 하나가 있었습니다. run 전에 찾아 고쳤습니다.
4. 원천 검사기 첫 판은 BEGIN/END 구역 안에서 지운 줄 둘을 표지 없음으로 셌습니다. 지운 위치를 구역과 대조하도록 고쳤습니다.
5. 근거 문서 초안에 "`ipc_mqueue_send` 의 다른 호출은 모두 인수 넷" 이라고 썼습니다. 확인한 것은 19/25 곳이므로 고쳤습니다.
6. PROVENANCE 행 초안의 `ev_vars.h` 줄 범위에, 쓰지 않은 줄(86·100·268–269·272–275)이 들어가고 이어지는 줄(79·122)이 빠져 있었습니다. 줄을 열어 확인하고 고쳤습니다.

결과(모두 미리 정한 기준대로):
- 1 07 `07_kernel/src/machdep/m68k/ev.c`(884 줄, SHA-256 `119f32e2…`)는 scratch `p688/gen_p689.py --write` 가 진단 A 의 생성기와 D161 꼴로 만들었습니다.
  - 원천 검사(`chk689.py`): F = L 토큰·토큰 줄 같음.
  - A → L 차이는 `extern` 30 줄·`kernel_pmon.h` import·`kfree` 형 변환뿐입니다.
  - NeXTMach 대비 80 hunk 에 표지 없는 줄 0 입니다(이름만 바꾼 줄 10).
- 2 `stage_m68k.py` 783 → 786 줄(`M4FILES`·`M4HEADERS`·`EXCEPTS[689]`, docstring).
- 3 회귀:
  - `m0p687-r689-stage` = 보관본 `m0p687-a2-stage`(1016 파일), `m0p689-a1-stage` 는 `ev.c` 하나만 늘었습니다.
  - `m5-687.cmd` = 보관본, `m5-689.cmd` 는 계획 번호만 다릅니다.
  - M5 205 `m3p689-cc1` 의 617 파일은 받아들인 `m3p687-cc2` 와 `run.json` 만 다릅니다. `compare`(`m3-m68k-p689-compare-20261102.json`)는 `differ_unexpected`·`lost` 가 비었고, 객체 항목이 p687 과 같고, `stage_vs_test_stage` 는 `ev.c` 만 늘었습니다.
  - x86 입력(`m4-x86-inputs-p689-20261102.json`)은 `ok` 이고 p687 과 같습니다. x86gate 는 `plan`·`tool_sha256` 만 다릅니다.
- 4 확인 run `m4p689-p1`(`m4-m68k-p689-p1checks-20261102.json` `ok`):
  - F·L 경고 0, 13/13.
  - 절·`__data`·`__cstring`·bss 차례가 원본과 같습니다.
  - 원본에 없는 미정의·COMMON 은 0 입니다.
  - F = L 입니다. A 와 L 은 `canon` 이 같고, 기호 차이는 30 이름 COMMON → UNDF 뿐입니다(STABS 1616 → 1603).
- 5 `-E` run `m4p689-e1`(`m4-m68k-p689-e1-20261102.json` `ok`): F = L 17799 토큰, stderr 0, i386 0.
- 6 최종 run `m4p689-a1`(`m4-m68k-p689-final-20261102.json`, SHA-256 `59f7a712…`): `gate.ok`, funcbytes 13/13 입니다.
  - zerofill `m4-m68k-zerofill-p689-20261102.json`(SHA-256 `cec313b9…`): `reference-inferred`, 후보 [0x40b4f5a, 0x40b4fb2), 받아들인 13 자리와 겹침 없음(python).
  - 확인 기록 `m4-m68k-p689-checks-20261102.json`: `ok`(의존 167, 저장소 파일 149 의 SHA 사슬; 선택지 = M5 줄; 07 = 스테이지).
  - 객체 SHA-256 `4c30f826…`.
- 7 상태(`m4-m68k-status-p689-20261102.json`, 표 64 → 65 줄; scratch 에서 두 번 돌려 출력 경로 칸만 다름):
  - 객체 63(OBJECT_MATCH 49, CODE+BSS_INFERRED 14).
  - 행 **87/188**, **128264 B(59.42%)**, `object_bytes` 170456. 미리 계산한 값과 같습니다.
- 8 기록: 근거 `m68k-ev.md`·`m68k-ev.diff`(741 줄), PROVENANCE 1230 → 1231 행(일곱 칸), MODIFICATIONS 759 → 760, DECISIONS D161(164 → 165 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D161).
