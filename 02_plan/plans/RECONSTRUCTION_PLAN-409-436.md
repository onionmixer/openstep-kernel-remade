# 커널 소스 복원 작업계획 — 보관 §409–436

`02_plan/RECONSTRUCTION_PLAN.md` 의 §409–436 를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-09, D026 방식, 사용자 지시 “완료된 작업은 알맞게 정리”). 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킵니다. 아래는 원문 그대로입니다.

---

## 409. M0-1 세부 계획 — m68k·SPARC 사전 측정: 실기 교차 도구 확인과 1997 i386 빌드 동일성 측정(07·x86 기록·도구 변경 없음; 코딩 전, 2026-10-09)

배경: 다른 아키텍처 작업 기준(로컬 문서 `02_plan/MULTIARCH_RECONSTRUCTION_STANDARD.md`)의 M0 와 9 절 미확인 항목 가운데 결정 D-M1–D-M4 에 앞서 사실을 모읍니다.
m68k·SPARC 원본은 mk-183.34(1997-04-27)이고 x86 07 트리는 mk-183.34.4(1999-01-26)에 맞춰져 있습니다.

확인한 사실(이번 세션, 읽기 전용):
- 실기 `/lib` 에 `m68k`·`sparc`·`i386`·`hppa` 디렉터리가 있습니다. `m68k`·`sparc` 에는 `as`·`cc1obj`·`cc1objplus`·`cc1plus`·`cpp`·`cpp-precomp`·`specs` 가 있고
  `hppa` 에는 `as`·`cpp-precomp` 뿐입니다(`ls -la`). 백엔드 날짜는 1997-04-22·23 입니다.
- `lipo -info`: `/bin/cc`·`/bin/as`·`/bin/ld`·`/bin/strip`·`/lib/libcc.a`·`/lib/crt0.o` 는 m68k·i386·sparc 세 조각의 fat 파일입니다.
- 실기 SDK `/NextDeveloper/Headers` 의 아키텍처 디렉터리(`ls -d */<arch>`): `architecture`·`mach`·`bsd`·`kernserv`·`mach-o`·`ansi` 에 m68k·sparc 가 있고,
  `driverkit` 에는 `hppa`·`i386`·`machine`·`sparc` 만 있고 **m68k 가 없습니다**.
- universal fat 조각 1(i386 mk-183.34)을 `03_original/installation-media/os42j/binaries/mach_kernel.universal`(SHA `f3b57f87…`)에서 python 으로 꺼내
  SHA `cb6217c2…`, 1,113,724 B 임을 확인했습니다(세션 scratchpad 에만 둠; `03_original` 에 넣는 것은 D-M2).
  `__text` 847,644 B(x86 183.34.4 는 851,436 B), `__const` 22,772 B·`__cstring` 13,892 B 는 x86 과 크기가 같습니다. 기호 SECT 3,648, ABS 100.
- 기존 `l1_compare.py` 는 이 조각(i386, 리틀엔디언)에 그대로 쓰입니다: 시험으로 s6 재빌드 객체 `memcmp`(함수 2 개)·`sched_prim`(35 개)이 모두 MATCH.

방법:
1. **교차 도구 목록(읽기 전용)**: 실기에서 `/lib/{m68k,sparc,i386}/*` 의 SHA-256(`krsha256`)과 `specs` 내용, fat 도구의 `lipo -info` 를 기록합니다.
   i386 기록 `08_build/toolchains/real-i386-20261001/sha256-vs-vm.json` 의 같은 파일과 해시를 대조합니다. 원 기록은 `08_build/toolchains/real-cross-20261009/`(무시 대상, IP 없음).
2. **교차 컴파일 탐침**: 프로젝트가 쓴 두 줄짜리 C 파일(전역 변수 하나와 그것을 읽는 함수 하나; 참고 코드 없음)을 새 run 디렉터리 `08_build/runs/m0p409-xc1/`(무시 대상, 새 ID)에서
   `cc -arch m68k -c -v`, `cc -arch sparc -c -v`, 대조로 `cc -arch i386 -c -v` 로 컴파일합니다. kr_run 은 i386 도구 목록이 고정이라 쓰지 않고, 명령·`-v` 출력·
   실행 전후 도구 해시를 그 디렉터리에 남깁니다. 호스트에서 python 으로 출력의 magic·바이트 순서·cputype(6·14·7)·절·기호·재배치 수를 읽고 SHA 를 적습니다.
   이것은 "백엔드가 목적 파일을 만든다" 는 확인뿐이며 ABI probe(M0-3)가 아닙니다.
3. **1997 i386 빌드 동일성 측정**: s6 재빌드 402 객체(`09_validation/reconstruction/s6-l1-G*-s6l4-*.json` 의 `obj`, SHA 확인)를 조각 1 에 대해
   `l1_compare.py --place-from-image`(.m 은 `--place-from-objc` 추가 — `l2_baseline.py` 와 같은 규칙)로 비교합니다. 새 읽기 전용 실행기
   `10_tools/reconstruction/m0_slice_l1.py` 가 조각을 원본 universal 에서 꺼내 SHA 를 확인하고, 객체별 결과와 python 집계(객체 판정, 함수 판정 수, MATCH 함수 바이트,
   소스 디렉터리별)를 냅니다. 실행기 자기 시험: 같은 실행기를 x86 원본 이미지에 돌리면 s6l4 기록 판정과 객체마다 같아야 합니다.
   출력 `09_validation/reconstruction/m0-i386-18334-l1-20261009.json`(객체별 상세는 크기를 보고 같은 디렉터리 하위 또는 무시 대상에 둠).
4. **해석 규칙(미리 정함)**: 조각 1 에서 OBJECT_MATCH 인 객체는 "`cc-744.13` 과 기록된 플래그·07 소스로 1997-04-27 i386 빌드의 그 객체 바이트를 다시 만든다" 는 뜻입니다.
   이는 i386 백엔드에 대한 근거이고, m68k·SPARC 백엔드가 1997 빌드와 같다는 증명은 아닙니다(같은 패키지·날짜라는 정황만 적음).
   NOT_MATCH 는 원인(소스 판·플래그·머리·컴파일러)을 가르지 않고 "판 차이 후보" 로만 셉니다. 측정은 M1(i386 183.34 다리)의 일부를 앞당기는 것이지만 기록·`03_original`·07 은 바꾸지 않습니다.
5. 기록: 이 절에 결과, 로컬 기준 문서 1·9 절 사실 갱신. 07·x86 표·기존 도구는 바꾸지 않으므로 x86 회귀 관문(기준 문서 6 절)은 해당하지 않습니다(새 도구 둘만 추가).
   그 뒤 측정값을 붙여 D-M1–D-M4 를 사용자에게 묻습니다.

### 409.1 codex 교차검토(gpt-6.1-sol, kz2akk1px) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 한 절 안 기호들의 델타가 둘 이상이면 그 절은 배치되지 않고, 이미지에 없는 기호는 무시됨 | `l1_compare.py:447–459` 읽음(`len(ds) == 1` 일 때만 배치) | ✅ 미배치 `__text` 를 따로 셈 |
| 기호 없는 절은 참조 추론, 참조 없으면 미검증, 추론된 zerofill 은 미검증 | `l1_compare.py:222–300` 읽음(`infer`, zerofill 은 `given by symbol` 일 때만 placement-only) | ✅ |
| 리터럴 절은 내용으로 참조만 확인 | `l1_compare.py:287–290` 읽음(`literal (references checked by content)`) | ✅ 해석 규칙에 반영 |
| ObjC 배치는 모듈 이름이 정확히 같아야 하는데 두 커널의 경로 앞부분이 다름 | `objc_place.py:56–65` 읽음(`module … not in image` 로 빈 결과); python 으로 두 이미지의 `.m` 경로 문자열 확인 — x86 61 개 `/BinarySourceCache_Mario1A/mk/mk-183.34.4/…`, 조각 1 61 개 `/private/Net/seaport/release/.sources/Sources6/mk_proj/mk-183.34/…` | ✅ .m 85 객체는 따로 셈(도구는 고치지 않음) |
| libcc 두 구성원은 402 객체 밖 | `objects_toolchain.tsv:2–3` 읽음; s6l4 G1–G6 객체 402 개와 링크 입력 402 개의 SHA 집합이 같음(python) | ✅ 이번 측정에서 제외하고 그렇게 적음 |
| 함수 기록에 `__TEXT,__const` 범위도 들어감 | `l1_compare.py:343–386` 읽음(`segname != '__TEXT'` 만 거름) | ✅ 함수 집계는 `__TEXT,__text` 만 |
| "그 객체 바이트를 다시 만든다" 는 과장; OBJECT_MATCH 는 이 도구의 비교 통과일 뿐(원 목적 파일·플래그·머리·컴파일러, 리터럴 전체, COMMON 크기, 함수 경계를 증명하지 않음) | `l1_compare.py:282–300·343–405`, `macho_obj.py:65–73`(COMMON 은 기호 종류로만 읽힘) 읽음 | ✅ 해석 문구를 고침 |
| NOT_MATCH 는 비교 수용 실패이지 바이트 차이·판 차이가 아님; DIFF 는 참조한 데이터 절 실패로도 생김 | `l1_compare.py:365` 읽음(`'fail' in dep_state.values()` → DIFF) | ✅ |
| BOUNDARY 는 object_verdict 에 영향 없음 | 이번 측정은 `--ranges` 를 쓰지 않음 | ⏭️ 해당 없음 |
| 탐침을 kr_run 없이 하려면 규약의 장치가 모두 필요 | `RECONSTRUCTION_PLAN.md:68–75`, 기준 문서 `:119–120` 읽음. 그리고 내가 따로 확인: `kr_run.py:39–41` 허용 도구에 `/bin/cc` 가 있고, `:344` EXPECT 가 두 바이트 순서 매직을 모두 받음 | ⚖️ 장치를 새로 만들지 않고 **kr_run 을 그대로 씀**(`/bin/cc -arch …`); 아키텍처 백엔드 해시는 1 의 실행 전후 목록으로 보충 |
| 빅엔디언 탐침 객체는 `macho_obj.py` 로 재배치를 못 읽음 | 기준 문서 1 절 11 판정표에 이미 확인(`:85`·`:91`) | ✅ 헤더·절·기호만 macho_obj, 재배치 수는 python 으로 따로 셈 |
| 목록에 fat 조각별 해시·subtype, libcc 아키텍처별 구성원, `migcom`·`migcom3`·`mig`·`/lib/cpp`, 링크 관계(inode), `cc -v` 가 고른 실행 파일, m68k VM 대조가 필요 | 기준 문서 `:95–99`(m68k VM 대조 요구) 읽음; `sha256-vs-vm.json` 의 vm 값은 i386 VM 임(파일 읽음); `cpp-precomp` 링크 수 5(`ls -la` 출력) | ✅ 1 에 넣음. m68k VM 은 실행하지 않고 디스크 이미지를 `nextufs mount`(기본 읽기 전용, `nextufs.1:86–87`)로 읽어 해시 |
| 자기 시험이 지금 규칙대로면 실패(329/73): PCinit·ufs_alloc·libDriver_vers 는 `l2_expect-s6p398.json` 의 명시 `__const` 배치가 필요, swapfs 는 이유가 달라짐 | `l2_rebuild.py:284–288` 읽음; `l2_expect-s6p398.json` 의 `place` 4 건(155 ufs_alloc 0x1d1280, 384 swapfs 0x1d1276, 402 libDriver_vers 0x1d647c, 53 PCinit 0x1d58e4) python 출력; 세 객체를 명시 배치 없이 x86 에 돌려 셋 다 `NOT_MATCH ['__TEXT,__const: unverified']` 재현 | ✅ 자기 시험은 명시 배치를 같이 주고 판정과 이유를 모두 대조. 조각 1 에는 x86 주소를 옮기지 않고 이 넷의 `__const` 는 미배치로 셈 |

추가로 확인: s6l4 기록의 등급(A 330, A\* 1, P 71)은 지금 표(A·A\* 315, P 70, 데이터 17)와 `x86-rtc` 하나가 다릅니다 — §398 뒤 A 로 옮겨짐(`objects_confirmed.tsv:316`). 집계에는 지금 06 표의 등급을 씁니다.

고친 방법:
1. 교차 도구 목록: 실기에서 `/lib/{i386,m68k,sparc,hppa}/*`·`/lib/cpp`·`/usr/lib/migcom`·`/usr/lib/migcom3`·`/usr/bin/mig` 의 `krsha256` 와 `ls -li`,
   fat 도구(`/bin/cc`·`as`·`ld`·`strip`·`/lib/libcc.a`·`/lib/crt0.o`)의 `lipo -info`, `specs` 내용. fat 파일은 `cat` 으로 run 디렉터리에 복사해 호스트에서 SHA 를 대조하고
   python 으로 조각별 cputype·subtype·SHA, libcc 조각의 구성원 이름·SHA 를 냅니다. 같은 경로를 m68k VM 디스크(`09_validation/images/m68k/openstep42-m68k-hdd.raw`, VM 이 꺼진 상태, 읽기 전용 마운트,
   전후 이미지 SHA 동일 확인)에서 해시해 대조합니다. 탐침 run 전후로 실기 목록을 두 번 떠서 같아야 합니다.
2. 교차 컴파일 탐침: kr_run 그대로(`RUN /bin/cc -arch m68k -c -v src/probe.c -o stage/probe-m68k.o`, sparc·i386 같은 꼴, EXPECT 셋). `-v` 출력(stage/_log)으로 실제 고른 백엔드 경로를 적습니다.
3. 1997 i386 측정: 402 객체(libcc 제외), `--place-from-image` + (.m) `--place-from-objc`. 명시 배치는 x86 자기 시험에서만 씁니다. 집계 칸: 객체 판정, 이유 종류(미배치·미검증 절·DIFF 등),
   `__text` 배치 여부, `__TEXT,__text` 함수만의 판정 수·바이트, .m 객체의 ObjC 대응 실패, 원래 등급별. 자기 시험은 x86 원본에서 402 객체의 판정과 이유가 s6l4 기록과 모두 같아야 합니다.
4. 해석: OBJECT_MATCH = "기록된 재빌드 객체가 이 도구의 비교(배치된 절의 바이트·재배치 재계산)를 조각 1 에서 통과함". 원 목적 파일·플래그·머리·컴파일러가 같다는 증명이 아니며,
   리터럴은 참조된 것만, COMMON 크기·함수 경계는 확인하지 않습니다. NOT_MATCH 는 원인을 가르지 않습니다. m68k·SPARC 백엔드에 대해서는 정황뿐입니다.

### 409.2 결과(2026-10-09)

**1. 교차 도구 목록**(`09_validation/reconstruction/m0-toolchain-cross-20261009.json`; 원 기록은 무시 대상 `08_build/toolchains/real-cross-20261009/`)
- 실기 34 경로의 `krsha256`·`ls -li`·`lipo -info` 를 탐침 전후 두 번 떠서 같았습니다.
- i386 쪽 14 경로는 기존 기록 `real-i386-20261001/sha256-vs-vm.json` 과 해시가 모두 같습니다.
- **아키텍처 백엔드(`/lib/{i386,m68k,sparc}/{as,cc1obj,cpp}`)도 m68k·i386·sparc 세 조각의 fat 실행 파일입니다**(`lipo -info`). 즉 같은 파일이 어느 호스트에서든 그 대상 코드를 냅니다.
  `cpp-precomp` 다섯 경로는 같은 inode(386985, 링크 수 5)입니다. `/usr/lib/migcom`·`migcom3` 는 fat 이 아닌 i386 실행 파일입니다.
- fat 도구 7 개(`cc`·`as`·`ld`·`strip`·`libcc.a`·`crt0.o`·`/lib/cpp`)는 `cat` 으로 복사해 호스트에서 SHA 를 대조한 뒤 조각별 SHA 를 냈습니다. `libcc.a` 의 세 조각은 모두 구성원 47 개입니다.
- m68k VM 디스크(`openstep42-m68k-hdd.raw`, VM 꺼짐, `nextufs mount -o ro`; 이미지 SHA `7097595f…` 전후 동일)와 대조: 34 경로 중 **32 같음**, 다른 둘은 `migcom`·`migcom3` —
  VM 쪽은 m68k(cputype 6) 실행 파일입니다. MIG 생성 결과가 호스트에 따라 같은지는 M0-3 MIG probe 에서 확인합니다.

**2. 교차 컴파일 탐침**(kr_run `m0p409-xc1`, DONE·게시 정상)
- `cc -arch m68k`·`-arch sparc`·`-arch i386` 모두 목적 파일을 만들었습니다. `-v` 출력에서 각각 `/lib/<arch>/{cpp-precomp,cc1obj,as}` 를 골랐고, 기본값으로 `-dynamic -fPIC` 가 붙습니다
  (커널 빌드는 `-static`; 플래그는 M0-3·M4 에서 정함).
- python 판독: m68k 빅엔디언 cputype 6(sub 1), sparc 빅엔디언 14(0), i386 리틀엔디언 7(3) — 원본 커널의 cputype(sub)와 같습니다. `__text` 30·36·24 B, 재배치 2·6·2.

**3. 1997 i386 빌드 동일성 측정**(`09_validation/reconstruction/m0-i386-18334-l1-20261009.json`; 상세는 무시 대상 `08_build/artifacts/m0p409/`, SHA 로 묶음)
- 자기 시험(x86 원본, 명시 배치 포함): **402/402 객체의 판정과 이유가 s6l4 기록과 같음**(OBJECT_MATCH 332, NOT_MATCH 70).
- 조각 1(i386 mk-183.34): OBJECT_MATCH 314, NOT_MATCH 88. 등급별 A 313/331, A\* 1/1, P 0/70(P 는 x86 에서도 NOT_MATCH).
- `__text` 가 있는 385 객체, 850,498 B: 함수 판정 MATCH 4,230 개 715,950 B(84.18 %), MATCH_UNVERIFIED 305 개 90,078 B(10.59 %), **DIFF 17 개 14,029 B(1.65 %)**,
  미배치 30,441 B(3.58 %). 합이 850,498 B 와 맞습니다(python). `__text` 함수가 모두 MATCH 인 객체 317/385(82.34 %).
- A 인데 NOT_MATCH 인 18 객체의 분류(객체별 이유를 읽음):
  - 코드는 모두 MATCH 이고 데이터 절 배치만 안 됨 11: `PCinit`·`ufs_alloc`(x86 에서도 명시 배치가 필요했던 `__TEXT,__const`), ObjC 9(`KernLock` 등 — 모듈 경로가 절대 경로라 `__module_info` 대응 실패).
    codex 지적과 달리 libDriver 모듈은 이름이 상대 경로(`Kernel/…` 등)라 두 판에서 같아 57 객체가 레코드까지 배치됐고, 실패는 절대 경로 모듈 19 객체뿐입니다.
  - 판 문자열 데이터 3: `vers`·`libDriver_vers`·`objc_vers`(`__text` 없음).
  - 코드 차이 후보 4: `FBConsole`(DIFF 16 함수 13,957 B), `unix_startup`·`rtc`(`__text` 미배치), `IODisk`(후보 2 개).
- 코드 차이 후보 전체(P 포함) 9 객체 45,098 B: 위 4 와 P 의 `BasicConsole`(DIFF 1 함수 72 B), `mach_clock`·`pmap`·`km`(미배치), `IOAudio`(후보 2 개). 원인(판·플래그·머리)은 가르지 않았습니다.
- 해석(409.1 의 규칙): 1997-04-27 i386 커널에서 기록된 재빌드 객체 대부분이 이 도구의 비교를 통과하므로, **`cc-744.13`(실기)과 1997 i386 빌드의 코드 생성이 이 객체들에 대해 구별되지 않습니다.**
  m68k·SPARC 백엔드에 대해서는 같은 fat 백엔드 파일이 세 대상을 모두 담는다는 정황뿐이고 증명이 아닙니다. 판 차이(183.34 ↔ 183.34.4)는 i386 에서 코드 차이 후보 9 객체 수준으로 작아 보이나,
  미배치·ObjC·데이터 절은 확인 범위 밖입니다.

07·x86 표·기존 도구는 바꾸지 않았습니다. 새 파일: `10_tools/reconstruction/m0_slice_l1.py`, 위 검증 JSON 2 개.

### 409.3 사용자 결정(2026-10-09)

D064 판별 덮어쓰기 트리, D065 조각 1 보관 + 후보 9·판 문자열 3 객체 원인 확인(183.34 i386 L2 는 하지 않음), D066 m68k 먼저, D067 L3 는 QEMU 만(`02_plan/DECISIONS.md`).

## 410. M1 세부 계획 — D065: i386 mk-183.34 조각 보관과 판 차이 후보 12 객체의 원인 확인(07·x86 표 변경 없음; 코딩 전, 2026-10-09)

배경: 사용자 결정 D065("조각 보관 + 후보 9개 확인"). §409.2 의 코드 차이 후보 9 객체(FBConsole·unix_startup·rtc·IODisk·BasicConsole·mach_clock·pmap·km·IOAudio)와
판 문자열 3 객체(vers·libDriver_vers·objc_vers)의 차이가 무엇인지 원본 바이트로 확인합니다. 183.34 i386 의 재구성(L2)은 하지 않습니다(D065).

확인한 사실(이번 세션, python, 읽기 전용):
- 두 원본 모두 `strip -x` 꼴이라 `__text` 에는 외부 기호만 있습니다. 외부 함수 기호 이름을 두 이미지에서 맞추고 "다음 기호까지의 거리"로 크기를 재면
  (정적 함수는 앞 외부 함수의 크기에 섞임), 후보 객체에서 크기가 다른 것: `unix_startup` `_startup_early` 232→280(x86→183.34),
  `FBConsole` `_FBAllocateConsole` 148→7,092 이고 `_FBAllocateVBEConsole`·`_VBEModeInfo2IODisplayInfo` 는 183.34 에 없음, `mach_clock` `_clock_interrupt` 376→292,
  `rtc` `_rtcput` 204→184·`_writetodc` 784→728, `BasicConsole` `_BasicAllocateConsole` 14,580→14,572, `pmap` `_pmap_bootstrap` 1,096→768, `km` `_kminit` 116→96.
  `IODisk`·`IOAudio` 는 외부 함수 기호가 없습니다(ObjC 메서드만).
- 호스트에 `objdump`(GNU)·`llvm-objdump` 가 있습니다.

방법:
A. **조각 보관**(기존 `03_original` 파일은 고치지 않고 새 디렉터리만 더함):
   1. `03_original/x86-mk-183.34/binaries/mach_kernel` — universal(SHA `f3b57f87…`)의 fat 헤더로 조각 1 을 꺼내 SHA `cb6217c2…`·1,113,724 B 확인(무시 대상, `/03_original/**/binaries/*`).
   2. `03_original/x86-mk-183.34/provenance.json`(새 파일, 추적): universal 경로·SHA, fat 색인·cputype·subtype·offset·size·align, 판 문자열, 추출 도구와 명령.
      `installation-media/os42j/provenance.json`·`manifest.json` 은 고치지 않고 새 provenance 에서 가리킵니다.
   3. `03_original/x86-mk-183.34/inventory/` — 기존 `10_tools/inventory_thin_macho.py --expected-endian little --expected-cpu 7` 로 macho.json·symbols.tsv·strings.tsv.
   4. `03_original/README.md` 는 기존 파일이라 고치지 않습니다(새 provenance 에 설명).
B. **원인 확인**(새 읽기 전용 도구 `10_tools/reconstruction/m1_version_diff.py`):
   1. 12 객체마다 s6 재빌드 객체(§409 의 SHA)의 함수 기호로 두 이미지의 대응 함수 범위를 정합니다. 외부 함수: 이름으로 대응. ObjC 메서드(IODisk·IOAudio):
      `objc_meta` 의 메서드 표(클래스·셀렉터 → IMP)로 대응. 대응하지 못한 함수는 그렇게 적습니다.
   2. 대응 함수마다 크기·바이트를 비교합니다: 같음 / 재배치 필드만 다름(l1_compare 와 같은 재계산 — 이미지 주소 차이) / 명령 차이. 명령 차이는 두 범위를 `objdump -b binary -m i386`
      으로 역어셈블해 차이 줄을 남깁니다(역어셈블은 해석 보조이고, 사실은 바이트 범위·크기).
   3. 판 문자열 3 객체: 두 이미지에서 그 객체 `__data`/`__const` 범위의 바이트를 비교하고 문자열 차이를 적습니다.
   4. 출력: `09_validation/reconstruction/m1-i386-18334-candidates-20261009.json`(객체·함수별 분류, 크기, 차이 오프셋, 입력 SHA)와 함수별 역어셈블 차이 텍스트(같은 이름 디렉터리).
   5. 자기 시험: 같은 도구를 x86 원본 대 x86 원본으로 돌리면 12 객체 모든 대응 함수가 "같음" 이어야 하고, 일부러 한 바이트를 바꾼 사본에서는 그 함수만 "명령 차이" 여야 합니다.
C. **분류 규칙(미리 정함)**: 원인은 원본 바이트로 보이는 것까지만 적습니다 — (a) 판 문자열 데이터, (b) 함수가 한쪽에만 있음(기능 추가·삭제), (c) 같은 함수의 명령 차이(소스·머리·플래그 중 무엇인지는
   가르지 않음; 역어셈블에서 보이는 것—상수·구조체 오프셋·호출 대상—만 적음), (d) 재배치만 다름(판 차이 아님), (e) 대응 불가. 참고 코드의 판 이력은 이번에 쓰지 않습니다.
D. 기록: 이 절에 결과, 로컬 기준 문서 12 절에 한 단락. 07·06 표·기존 도구 변경 없음 → x86 회귀 관문 해당 없음.

### 410.1 codex 교차검토(gpt-6.1-sol, khlwr6tqk) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| A(새 디렉터리 추가)는 규칙과 맞음; 바이너리는 무시, provenance·inventory 는 추적 | `DECISIONS.md:69`(D065), `AGENTS.md:14`, `.gitignore:5` 읽음; `git check-ignore -v --no-index` 로 바이너리 무시·provenance 비무시 확인 | ✅ |
| provenance 에 목적지·전체 SHA·실제 길이·바이트 순서/magic·추출 날짜·도구 해시, 기존 provenance 참조, manifest 에 없음을 적을 것; inventory 는 원시 사실 | `inventory_thin_macho.py:127` caveat("nlist entries are not function boundaries") 읽음 | ✅ 넣음 |
| "다음 외부 기호까지의 거리" 는 함수 크기가 아니라 기호 구간(정적 함수·채움·뒤 객체 코드 포함) | 재빌드 `BasicConsole` 객체: `__text` 700 B, `_BasicAllocateConsole` 628–700 = 72 B(python), 이미지 구간 14,580 B | ✅ 410 의 수치는 "기호 구간" 으로 읽어야 함; 함수 크기로 쓰지 않음 |
| ObjC 대응 키에 instance/class 종류가 필요 | `l1_compare.py:417–435`(키 `(owner, category, kind, selector)`), `objc_meta.py:79–89`(`'instance'`/`'class'`) 읽음 | ✅ 키를 고침 |
| 두 링크 이미지만으로 "재배치만 다름" 을 판정하려면 정렬된 경계, 필드 밖 바이트 같음, 필드마다 같은 대상·가산값이 필요; 아니면 "미해결 주소 필드 차이" | 원칙 — l1_compare 는 객체 재배치와 절 배치로 재계산함(`:164–218`) | ✅ 규칙에 반영 |
| C 의 "한쪽에만 있음 → 기능 추가·삭제", "재배치만 → 판 차이 아님" 은 과장 | 이름 변경·가시성·인라인·이동 가능성; 배치 변화도 판 차이의 결과일 수 있음 | ✅ 문구를 "기호 없음" / "검증된 대응 아래 주소 부호화만 다름" 으로 |
| 자기 시험: 임의 한 바이트 변경이 명령 차이라는 보장 없음; 필드 변경·대상 변경·대응 모호·경계 실패도 시험 | 원칙 | ✅ 시험 항목 고침 |
| 410 의 수치·VBE 부재·도구 존재가 모두 맞음 | §410 작성 때 내 python 출력과 같음 | ✅(내 측정) |
| IOAudio 는 ObjC 메서드만이 아님 — 정적 `_ioThread`·`_keyThread`·`_interruptHandler` | 재빌드 객체 기호 python: `__text` 11,164 B, 오프셋 4916·5244·11092 의 비외부 기호 | ✅ 410 정정 |

고친 방법 B:
1. 함수 범위는 **재빌드 객체**의 기호(외부·정적·ObjC 메서드)로 정합니다. 12 객체는 x86 에서 `__text` 가 L1 일치이므로(s6l4 기록) 객체 함수 범위 = x86 원본 범위입니다.
2. 183.34 쪽 대응은 **진입점만**: 외부 함수는 이름(이미지 전체에서 유일, `__TEXT,__text` 안), ObjC 메서드는 `(class, category, kind, selector)` 의 유일 IMP. 정적 함수는 대응 진입점이 없으므로
   "정적 — 단독 대응 없음" 으로 두고, 객체의 `__text` 가 한 델타로 배치될 때만(§409 의 결과) 그 델타로 봅니다.
3. 대응 함수 비교(길이 = 재빌드 객체의 함수 길이): (i) 바이트 같음, (ii) 객체 재배치 필드 밖은 모두 같고 필드마다 외부 기호 대상이 두 이미지에서 같은 이름·같은 가산값으로 풀림 →
   "검증된 대응 아래 주소 부호화만 다름", (iii) 필드 밖은 같으나 필드 대상을 확정할 수 없음(지역·절 재배치 등) → "미해결 주소 필드 차이", (iv) 필드 밖 바이트가 다름 → "내용 차이"
   (두 쪽을 역어셈블해 남김; 183.34 쪽 길이는 기호 구간으로 표시하고 함수 크기라고 하지 않음). 진입점이 183.34 에 없으면 "기호 없음".
4. 판 문자열 3 객체는 §409 L1 의 데이터 절 배치(기호 기반)로 두 이미지의 범위를 읽어 비교합니다.
5. 자기 시험: x86 대 x86 → 대응 함수 모두 (i). 조작한 183.34 사본 셋 — 필드 밖 명령 바이트 1 개 변경 → 그 함수 (iv); 외부 재배치 필드 값 변경 → (ii) 가 아닌 결과; 외부 기호 이름 1 개 지움 → "기호 없음".

### 410.2 결과(2026-10-09)

**A. 조각 보관** — `10_tools/extract_fat_slice.py` 로 `03_original/x86-mk-183.34/binaries/mach_kernel`(무시 대상)을 꺼냈습니다. SHA `cb6217c2…`, 1,113,724 B, `CEFAEDFE`(리틀엔디언),
cputype 7(3), 판 문자열 "NeXT Mach 4.2: Sun Apr 27 14:07:30 PDT 1997; …mk-183.34.obj~4/RELEASE_I386". 기록 `03_original/x86-mk-183.34/provenance.json`(컨테이너 SHA·fat 색인·도구 SHA·명령),
inventory 는 기존 `inventory_thin_macho.py`(절 26, 기호 3,748, 문자열 6,550; macho.json 키는 기존 m68k inventory 와 같은 18 개). 기존 `03_original` 파일은 바꾸지 않았습니다.

**B. 원인 확인** — 도구 `10_tools/reconstruction/m1_version_diff.py`, 결과 `09_validation/reconstruction/m1-i386-18334-candidates-20261009.json` 과 같은 이름 디렉터리(content 함수의 역어셈블 9 개).
- 계획에서 바꾼 점 둘(코딩 중 발견):
  1. 처음 규칙은 외부 재배치 필드만 풀어 지역 필드가 모두 "미해결" 이었습니다(89 함수). l1_compare 의 `evaluate`·`lit_check` 로 객체 재배치를 두 이미지에서 다시 계산하도록 고쳤습니다.
     183.34 쪽 지역 대상은 이름으로 정한 배치(`given by symbol`·`given by objc metadata`)만 쓰고 추론 배치는 쓰지 않습니다(409.1·410.1 의 순환 방지).
  2. FBConsole 의 정적 함수를 외부 기호 하나(`_FBAllocateConsole`)로 정한 `__text` 델타로 놓았더니 모두 첫 바이트부터 달랐습니다(정규화 명령 일치 5–20 %). 그 객체는 183.34 에
     진입점 둘이 없어 배치가 바뀐 것이므로, **진입점이 하나라도 없는 객체의 정적 함수는 위치를 정하지 않도록**(not_located) 고쳤습니다.
- 자기 시험(고친 뒤 다시): x86 대 x86 236 함수 모두 same; 조작 사본에서 명령 바이트 변경 → content, 외부 필드 변경 → unresolved_address, 기호 이름 훼손 → symbol_absent.
- 함수 236 개(9 객체): same 83, address_only 80, unresolved_address 32, **content 9**, **symbol_absent 2**, not_located 30(합 236, python).
  - symbol_absent: FBConsole `_FBAllocateVBEConsole`·`_VBEModeInfo2IODisplayInfo`(183.34 에 이 기호가 없음).
  - content(명령 차이가 있는 함수; 역어셈블에서 보이는 것만 적음, 원인 판정 아님): `unix_startup` `_startup_early`(183.34 쪽에 비교·분기·상수 0x10 대입이 더 있음),
    `mach_clock` `_clock_interrupt`(183.34 쪽에 `0xf0(%ebx)` 갱신 블록이 더 있음), `rtc` `_rtcput`(183.34.4 쪽에만 포트 0x70/0x71 로 레지스터 0x32 를 쓰는 7 명령),
    `rtc` `_writetodc`(183.34.4 쪽에 100 으로 나누는 계산과 큰 스택 프레임), `BasicConsole` `_BasicAllocateConsole`(183.34.4 쪽 오프셋 10 에 호출·검사·분기),
    `pmap` `_pmap_bootstrap`(스택 프레임 크기가 다르고 183.34.4 쪽 범위에 표처럼 보이는 바이트), `IODisk` `-setLogicalDisk:`(183.34.4 쪽에 인자 0 검사가 더 있음),
    `km` `_kminit`(183.34.4 쪽에 호출 하나와 결과 검사 뒤 다른 호출이 더 있음), `IOAudio` `-_setParameter:toInt:forObject:`(레지스터 배정과 표 바이트가 다름).
  - unresolved_address 32 는 필드 밖 바이트가 같고 주소 필드를 이름 기반 배치로 확정하지 못한 것입니다(대부분 `__data`·`__bss` 미배치 객체). 판 차이로 세지 않습니다.
- 판 문자열 3 객체: `vers` `__data` — "…Tue Jan 26 11:21:50 PST 1999…mk-183.34.4.obj~2…" ↔ "…Sun Apr 27 14:07:30 PDT 1997…mk-183.34.obj~4…"(183.34 쪽 범위가 절 끝을 넘어 108/110 B 읽음).
  `libDriver_vers` `__TEXT,__const`(183.34 쪽 배치 없음, 앞 16 B 검색 유일 후보): "driverkit-94.16.2 DEVELOPER:cfriesen BUILT:Fri Jan 22 16:11:10 PST 1999" ↔ "driverkit-94.16 DEVELOPER:root BUILT:Tue Apr 22 22:20:23 PDT 1997".
  `objc_vers`: 둘 다 "objc-170" 이고 BUILT 날짜만 다름(1997-03-27 ↔ 1997-04-22).
- 정리: 9 후보 객체의 차이는 9 함수의 명령 차이와 2 함수의 기호 부재로 좁혀집니다. 나머지 함수 163 개(same 83 + address_only 80)는 x86 07 소스의 출력과 183.34 i386 원본이 주소 부호화 말고는 같습니다.
  m68k·SPARC 에서는 아키텍처 공통부(`kern/mach_clock.c`, `driverkit/libDriver/IODisk.m`·`Kernel/IOAudio.m`)의 183.34 판 차이를 고려해야 하며, 나머지(`machdep/i386/` rtc·pmap·unix_startup, `bsd/dev/i386/` km·FBConsole·BasicConsole)는 원래 i386 전용 파일입니다(소스 경로는 §409 JSON 의 `source`).

## 411. M0-5 세부 계획 — m68k 용 도구 확장 1: 빅엔디언 재배치 읽기(`macho_obj.py`)와 m68k L1 비교(`l1_compare.py`)(07 변경 없음; 코딩 전, 2026-10-09)

배경: D066(m68k 먼저). 기준 문서 M0-5 의 고정점 가운데 m68k L1 에 필요한 최소 범위만 고칩니다. `l2_*`·`stage_headers`·`objc_meta`·`kr_run` 의 아키텍처 확장,
SPARC 고유 재배치 의미, ABI probe(M0-3)는 다음 절로 미룹니다.

확인한 사실(이번 세션):
- `macho_obj.py` 는 헤더·절·기호를 두 바이트 순서로 읽지만 재배치는 빅엔디언이면 scattered·일반 모두 거부합니다(`:85`·`:91` 의 raise). 형식 표는 `RELOC_TYPES_I386`
  `{0 VANILLA, 1 PAIR, 2 SECTDIFF, 3 PB_LA_PTR, 4 LOCAL_SECTDIFF}`(`:18`).
- SDK `mach-o/reloc.h`(로컬 사본 `01_resources/local_mirrors/headers/NextDeveloper/Headers/mach-o/reloc.h`): `relocation_info` 는 비트필드
  `r_symbolnum:24, r_pcrel:1, r_length:2, r_extern:1, r_type:4` 하나뿐이고(바이트 순서별 정의 없음), `scattered_relocation_info` 는 `__BIG_ENDIAN__` 에서
  `r_scattered:1, r_pcrel:1, r_length:2, r_type:4, r_address:24` 순입니다. 일반 형식은 `GENERIC_RELOC_{VANILLA, PAIR, SECTDIFF, PB_LA_PTR}` 넷이고,
  `mach-o/m68k/` 에는 `swap.h` 만 있어 m68k 고유 재배치 형식 정의가 없습니다(`mach-o/sparc/reloc.h` 는 있음).
  참고 트리의 `next-gcc-2.7.2/config` 에는 i386 만 있어, 빅엔디언에서 일반 형식 비트필드의 배치는 소스로 확인할 수 없습니다 → 실측으로 확인합니다.
- §409 탐침 객체(`m0p409-xc1`, `-dynamic -fPIC` 기본)의 재배치는 모두 scattered 였고, `llvm-objdump-14 --macho -r` 가 m68k(형식 2·1)·sparc(8·7·1) 를 숫자 형식으로 읽습니다.
  원 8 바이트(예 m68k `a2000012 0000001e`)는 위 빅엔디언 scattered 배치(scattered 1, pcrel 0, length 2, type 2, address 0x12)와 맞습니다.
- `l1_compare.py` 의 바이트 순서 고정: `:143`·`:157`·`:175`·`:232`·`:236`·`:318` 의 `'little'`, 형식 표 `TYPE = RELOC_TYPES_I386`(`:37`). 형식 표 사용처는 `zerofill_check.py:41`,
  `m1_version_diff.py:107` 도 있습니다(둘 다 i386 전용 그대로 둠).
- `check_macho_obj.py` 는 llvm-objdump 와 절·기호·재배치를 대조하며 형식 이름을 i386 표로 비교합니다(llvm 은 m68k·sparc 형식을 숫자로 출력).

방법:
1. `macho_obj.py`: 빅엔디언 재배치 읽기. scattered 는 reloc.h 의 `__BIG_ENDIAN__` 배치 그대로. 일반 형식은 가설 "첫 필드가 최상위 비트"(w1 = symbolnum<<8 | pcrel<<7 | length<<5 | extern<<4 | type)
   으로 읽고 **llvm-objdump 와 대조해서만 채택**합니다. `RELOC_TYPES_GENERIC`(0–3, reloc.h)과 `reloc_types(cputype)` 를 더하고, i386 표와 리틀엔디언 경로는 바꾸지 않습니다.
   SPARC 는 읽기(필드 분해)만 하고 형식 이름 표는 두지 않습니다.
2. `l1_compare.py`: 필드 읽기의 바이트 순서를 객체·이미지의 `endian` 으로 바꾸고(둘이 다르면 오류), 형식 표를 cputype 으로 고릅니다(i386 → 기존 표, m68k → 일반 표).
   그 밖의 cputype(SPARC·HPPA)은 **명시 오류로 거부**합니다(고유 재배치 의미를 구현하기 전에는 비교하지 않음). 계산식(F + S − Δ(P) 등)은 그대로 둡니다 — m68k 에서 맞는지는 3 의 링크 탐침으로 확인합니다.
3. 탐침(kr_run 새 ID `m0p411-pr1`, 실기): 프로젝트가 쓴 두 C 파일(`a.c` 는 외부 함수 호출·외부 데이터 읽기·정적 데이터·문자열·`switch` 점프 표·함수 포인터 표,
   `b.c` 는 그 정의)을 `-arch m68k`·`-arch sparc`·`-arch i386` 로 `-static -O2 -c`, m68k·i386 은 `ld -arch <a> -static -e _kr_a -o stage/probe-<a>.out a.o b.o` 로 링크합니다.
   - 대조 A: `check_macho_obj.py` 로 6 객체를 llvm-objdump 와 대조 — 모두 AGREE 여야 합니다(형식은 i386 이 아니면 숫자로 비교하도록 대조 도구를 고침).
   - 대조 B: `l1_compare.py --place-from-image` 로 m68k·i386 객체 4 개를 각 링크 결과와 비교 — OBJECT_MATCH 여야 합니다. 조작한 링크 결과 사본(재배치 밖 명령 바이트 1 개, 외부 재배치 필드 1 개)에서는
     그 함수가 DIFF 여야 합니다. SPARC 객체는 `l1_compare` 가 거부해야 합니다.
4. x86 회귀(기준 문서 6 절): (a) `m0_slice_l1.py selftest` 를 다시 돌려 402 객체 판정·이유가 같고, 객체별 상세 JSON 이 §409 때(`08_build/artifacts/m0p409/selftest/`)와 바이트 단위로 같음,
   (b) `check_macho_obj.py` 를 402 객체에 돌려 모두 AGREE, (c) `m1_version_diff.py selftest`·`run` 결과가 §410 기록과 같음. 하나라도 다르면 바꾼 것을 되돌리고 원인을 찾습니다.
5. 기록: 이 절, 기준 문서 12 절. 07·06 표는 바꾸지 않습니다.

### 411.1 codex 교차검토(gpt-6.1-sol, kf5189v8v) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 일반 재배치의 MSB 우선 배치는 reloc.h 필드 순서와 맞고, 저장소의 m68k `libcc.a` `_bb.o` 가 그 배치를 보임 | 실기 사본과 같은 `03_original/x86/userland/binaries/lib/libcc.a`(SHA `bccd689e…`, §409 의 실기 `/lib/libcc.a` 와 같음)의 m68k 조각을 python 으로 풀어 `_bb.o`(파일 오프셋 0xa48, 1,908 B)의 일반 재배치 43 개를 가설대로 해독 — 첫 줄 `000002f4 000004d0` = 기호 4, pcrel, long, extern, type 0; `llvm-objdump-14 --macho -r` 출력(`_atexit`, `1 (__TEXT,__text)` …)과 같음 | ✅ 1997 NeXT 가 만든 실제 m68k 객체가 근거. libcc m68k 47 구성원 전체를 대조 A 에 넣음 |
| 컴파일러 비트필드 배치를 직접 보는 `struct relocation_info` 초기화 탐침 | 위 실제 객체 대조가 같은 사실을 더 직접 보임 | ⚖️ 하지 않음(libcc 대조로 대체) |
| `r_address` 는 필드의 절 오프셋, m68k 분기 기준(+2)은 이미 F 에 들어 있음, 1/2/4 바이트를 정확히 빅엔디언으로 읽을 것 | reloc.h 주석(`:24`·`:28`); 기준 차이는 F 에 들어 있으므로 식 그대로 — 링크 탐침(대조 B)으로 확인 | ✅(식은 바꾸지 않고 실측으로 확인) |
| 지역 재배치의 `R_ABS`(절 번호 0)를 `evaluate` 가 `sections[T - 1]` = 마지막 절로 읽음 | `l1_compare.py:192`(`is_lit(obj['sections'][T - 1])`)·`:191`, reloc.h `:33` `#define R_ABS 0` 읽음; `infer` 에도 같은 꼴(`T = r['symbolnum']` 뒤 `sections[T - 1]`) | ✅ T == 0 이면 "R_ABS" 미확인으로 처리(두 곳) |
| cputype 일치도 요구하고, 지원하지 않는 일반 형식(0 이 아닌 type)은 VANILLA 식을 쓰기 전에 거부 | `evaluate` 는 일반 재배치의 type 을 보지 않음(읽음) | ✅ 넣음(i386 에서 바뀌면 회귀에서 드러남) |
| 순수 C 로는 2 바이트 필드·절 사이 SECTDIFF 가 보장되지 않음; 실제로 나온 재배치 목록을 기록하고 받을 것 | 원칙 | ✅ 탐침 결과의 형식·폭·pcrel·extern 조합을 python 으로 세어 기록, 나오지 않은 조합은 "미검증" 으로 남김. §409 PIC 탐침(SECTDIFF)도 대조에 넣음 |
| `ld -arch m68k -static` 직접 호출은 시작 파일·라이브러리를 붙이지 않음; 모든 외부를 정의할 것 | 탐침이 두 파일 안에서 모든 외부를 정의하도록 함; 결과는 실측 | ✅ |
| 12 개 파일이 macho_obj 를 import 하고, 거부가 풀리면 빅엔디언 객체가 리틀엔디언 가정 도구로 들어감: `objc_place.py:24`·`:38`, `zerofill_check.py:41`·`:88`·`:161`, `m1_version_diff.py:107`, `l2_coverage.py:75`·`:89`, `l2_place.py:74`·`:238` | python AST 로 import 파일 12 개 확인(앞서 내가 적은 13 은 틀림); 각 줄 sed 확인 | ✅ 그 도구들에 i386 전용 확인을 넣음 |
| 회귀가 L2·커버리지·zerofill 까지 가야 함(기준 문서 6 절 `:186`·`:187`) | 기준 문서 읽음 | ✅ 회귀 스크립트: 기존 시험 5 개, 402 객체 `check_macho_obj`, `m0_slice_l1 selftest`, `m1_version_diff selftest/run`, `l2_place`(+selftest), `l2_coverage`(기본·`L2_COVER=s6l1`) 를 고치기 전후로 돌려 출력 비교. 빌드 도구(kr_run·stage_headers·l2_rebuild·l2_link)는 바꾸지 않으므로 x86 재빌드는 해당 없음 |
| `next-gcc-2.7.2/config` 에는 i386 말고 `next/`(nextstep.h·nextstep.def)도 있음 | `ls config/next` | ✅ 사실 정정(m68k 백엔드 없음이라는 결론은 그대로) |
| m68k 분기 기준 근거 `audit_m68k_all_type19_direct_transfers.py:27` | `:27` 은 `def decoder(...)` 줄 | ⏭️ 옮기지 않음 |

### 411.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m0-tools-m68k-20261009.json`

바꾼 것:
- `macho_obj.py`: 빅엔디언 재배치 읽기(scattered 는 같은 수치 배치, 일반 형식은 MSB 우선), `RELOC_TYPES_GENERIC`(0–3), `reloc_types(cputype)`(i386·m68k 만, 그 밖은 None), `require_i386()`.
- `l1_compare.py`: 필드 읽기의 바이트 순서를 객체의 것으로, 형식 표를 `types_of(obj)`(SPARC·HPPA 거부)로, 객체와 이미지의 cputype·바이트 순서가 다르면 거부,
  일반 재배치의 type 이 0 이 아니면 계산하지 않고 미확인, `R_ABS`(절 0)는 미확인(`evaluate`·`infer` 두 곳). 모듈 변수 `TYPE` 은 기존 호출자를 위해 남김.
- i386 전용 확인(`require_i386`)을 넣은 도구: `objc_meta.py`, `objc_place.py`, `zerofill_check.py`, `l2_coverage.py`, `l2_place.py`, `m1_version_diff.py`.
- `check_macho_obj.py`: i386 이 아니면 형식을 숫자로 비교(llvm-objdump 가 m68k·SPARC 형식을 숫자로 출력).
- 새 시험 `test_l1_m68k.py`, 회귀 스크립트 `regress_m0p411.sh`.

검증:
- 실제 NeXT 객체 대조(`libcc.a` 각 조각의 모든 `.o` 46 개 × 3): m68k 46/46 AGREE(재배치 97, 모두 일반 형식), i386 46/46 AGREE(101).
  SPARC 28/46 AGREE — 나머지 18 개 객체의 불일치 113 행은 모두 SPARC 의 비-scattered type 1·symbolnum 0xffffff 항목으로, 필드 값은 llvm 과 같고 대조 도구가 참조 절 이름을 못 붙인 것뿐입니다(SPARC 는 읽기만).
- 탐침 `m0p411-pr1`(실기 kr_run, DONE): `cc -static -O2` 6 객체와 `ld -arch m68k|i386 -static -e _kr_a` 링크 둘 모두 성공. llvm 대조: m68k·i386 4 객체 AGREE, SPARC 2 객체는 같은 PAIR 표기 불일치만.
  m68k 에서 실제로 나온 재배치: `__text` 외부 절대 4·외부 pc 5·지역 절대 17·지역 pc 3·scattered 1, `__data` 외부 3·지역 2·scattered 1 — 모두 4 바이트 VANILLA.
  **2 바이트 필드와 링크 비교에서의 SECTDIFF 는 이번에 나오지 않아 m68k 에서 미검증**입니다(SECTDIFF 읽기는 §409 PIC 탐침에서 AGREE).
- `test_l1_m68k.py` 10/10: m68k·i386 객체 4 개가 각 링크와 OBJECT_MATCH(→ F + S − Δ(P) 등 일반 식이 NeXT ld 의 m68k 링크와 맞음), 조작 사본 4 종(필드 밖 바이트, 외부 pc 필드, `__data` 외부 필드, 지역 절대 필드) 모두 DIFF/NOT_MATCH,
  m68k 객체 대 i386 이미지 거부, SPARC 객체 거부.
- 원본 m68k 커널(`03_original/m68k/binaries/mach_kernel`)을 `l1_compare.Image` 로 읽음: cputype 6, big, 절 6, 외부 기호 이름 3,808.
- x86 회귀(고치기 전후 같은 명령, `08_build/artifacts/m0p411/{base,after}`): 출력 435 파일 중 433 바이트 동일, 나머지 둘은 출력 경로 문자열과 `l1_compare.py` 자신의 해시만 다름(python 으로 정규화해 확인).
  여기에 402 객체 L1 상세 JSON, 기존 시험 5 개, `l2_place`(+selftest), `l2_coverage`(기본·s6l1), `m1_version_diff` 가 들어 있습니다. 반환 코드도 같습니다.
  기준선에서 이미 실패하던 것(zerofill 시험 3/14 — 이번에 고른 알려진 배치 목록이 plan 302 때와 다름; `check_macho_obj` 396/402 — `-g` 객체의 STAB 기호 줄)은 전후 같게 남았습니다.

## 412. M0-3 세부 계획 — m68k ABI 탐침: C·Objective-C·어셈블리·MIG 를 `cc-744.13 -arch m68k` 로 컴파일하고 목적 파일 검사(07·기존 탐침·도구 변경 없음; 코딩 전, 2026-10-09)

목적: GCC27 문서 완료 판정 2 를 m68k 에 대해 채웁니다(기준 문서 M0-3, D066 m68k 먼저). 측정만 하며, 원본 m68k 커널의 구조체 오프셋과 맞추는 일은 M3 끝 조건입니다.

확인한 사실(이 세션에서 읽거나 실행):
- 기존 i386 탐침(§11 A3, `10_tools/reconstruction/probes/`): `c_layout.c`·`c_codegen.c`·`objc_probe.m`·`asm_probe.s`(i386 문법)·`mig_probe.defs` 와 명령 두 벌. 결과 `09_validation/reconstruction/toolchain/c-layout-probe-20261001.json`.
- 실기 `/usr/bin/mig` 는 49 줄 sh 스크립트입니다. `-arch A` 이면 `CPP=/lib/A/cpp` 로 전처리하고 `/usr/lib/migcom`(실기에서는 i386 단일 파일, §409)에 넘깁니다. 즉 m68k MIG 출력은 "m68k cpp + i386 migcom" 입니다.
- `/lib/m68k/` 의 백엔드(`as`·`cc1obj`·`cpp` 등)는 §409 기록(`m0-toolchain-cross-20261009.json`)에 해시가 있습니다. `kr_run.py` 는 실행 때 `/bin/cc` 등 허용 도구만 i386 기록과 대조하고 `/lib/m68k/*` 는 대조하지 않습니다.
- m68k 역어셈블러 셋: 실기 `/bin/otool -tv`(1997-04-23, `m0p411-pr1` 의 `a-m68k.o` 를 읽음), 호스트 `llvm-objdump-14`(대상 목록에 m68k), python capstone 4.0.2(`CS_ARCH_M68K`).
- `m0p411-pr1` 의 `-O2` m68k 코드는 `pea a6@; movel sp,a6` 로 프레임을 만들고, 포인터 반환을 `movel a0,d0` 로 d0 에 둡니다(otool 출력) — 호출 규약은 이번에 체계적으로 잽니다.
- NeXTMach `mk-108.1/conf/Makefile.NeXT:26` 의 m68k 플래그는 `-O -fwritable-strings -fcombine-regs` 입니다(GCC 1 시절 옵션; 원본 1997 m68k 커널의 플래그는 미확인).

방법:
1. 탐침 소스(새 파일, 프로젝트 작성, 참고 코드 없음; 기존 i386 탐침 파일은 고치지 않고 그대로 재사용):
   - `probes/c_abi.c`: 컴파일 시점 상수만 담은 초기화 전역 배열(실행 없이 `__data` 에서 읽음) — `long long`·`long double` 크기와 `{char; T}` 오프셋(T = short·int·long·float·double·포인터·long long·long double),
     `enum` 크기, `struct {char}`·`struct {char[3]}`·`struct {short; char}`·`union {char; short}` 크기, 구조체 안 구조체 정렬, 비트필드(12+12+12, `{char; int b:4}`, `int :0`) 크기,
     `char` 부호(`(char)-1 < 0`). 그리고 값을 넣은 인스턴스: 비트필드 구조체 `{unsigned a:3, b:5, c:9; char x}` = {5, 17, 300, 0x5a} 와 `{char; int; short}` 값 — 바이트로 비트 순서·채움·바이트 순서를 봅니다.
     `long long`·`long double` 은 GNU 확장으로 표시하고 측정만 합니다(커널 사용 여부는 M3).
   - `probes/c_call.c`: 외부 함수 호출로 인자 전달(char·short·int·long·포인터, float·double, 작은·큰 구조체 값, 가변 인자)과 반환(char·short·포인터·float·double·long long·작은/큰 구조체),
     레지스터를 많이 쓰는 함수 하나(호출 측 보존 레지스터 집합). 모두 프로토타입 있음.
   - `probes/asm_pp_m68k.s`: m68k(MIT 문법) 함수 하나·데이터 둘(상수, 함수 주소)·외부 호출 하나. `#define` 상수를 써서 `cc -c` 가 `.s` 를 전처리하는지 봅니다.
2. 명령(kr_run, 새 ID `m0p412-abi1`, 결정성 확인용 같은 입력 `m0p412-abi2`). 옵션 세 벌 × C 탐침(`c_layout`·`c_codegen`·`c_abi`·`c_call`):
   D 기본(`-arch m68k -c`), O 커널 후보 비-디버그(`-static -fwritable-strings -traditional-cpp -nostdinc -O3 -fno-omit-frame-pointer`), G = O + `-g`(x86 최종 플래그와 같은 꼴).
   ObjC `objc_probe.m`(D·G), 어셈블리 `asm_pp_m68k.s`(G 꼴, `-nostdinc` 제외), MIG `mig -arch m68k` 로 생성한 User·Server 를 G 로 컴파일. 대조군으로 `c_abi`·`c_call`·MIG 생성을 `-arch i386`(G) 로도 만듭니다.
   실행 전후에 gcds 로 `/lib/m68k/*`·`/bin/cc`·`/bin/as`·`/usr/bin/mig`·`/usr/lib/migcom` 을 `krsha256` 로 해시해 §409 기록과 같아야 합니다(읽기 전용).
3. 검사(호스트 python 새 도구 `10_tools/reconstruction/m0_abi_probe.py`, 결과 `09_validation/reconstruction/m0-abi-m68k-20261009.json`):
   a. 두 실행의 출력 해시가 모두 같음(결정성).
   b. D·O m68k 객체 전부 `check_macho_obj.py` AGREE(G 는 알려진 STAB 줄 한계가 있어 기록만).
   c. 배치 표: `c_layout`·`c_abi` 의 표를 `macho_obj` 로 읽고(빅엔디언), 같은 값을 `llvm-objdump-14 --macho -s` 의 16 진 출력에서 따로 python 으로 풀어 일치 확인. D·O·G 세 벌이 같아야 하고,
      i386 대조군 `c_layout` 값은 §11.2 기록과 같아야 합니다(판독 경로 확인).
   d. 호출 규약: `c_call` 의 각 함수를 otool·llvm-objdump-14·capstone 으로 역어셈블해 명령 경계(주소 목록)가 셋 모두 같은지 python 으로 확인하고, 인자 읽기 위치(`a6@(n)`)·반환 레지스터(d0/d1, fp0, a0/a1)·
      구조체 반환 방식·저장 레지스터를 목록 줄 인용과 함께 표로 기록(관찰 사실; 해석에 계산이 들면 python).
   e. ObjC: m68k 와 i386 `objc_probe.o` 의 절 이름 집합이 같은지, 절 크기·재배치 수 표. 메타데이터 내부 해석은 `objc_meta` 확장(M0-5) 뒤로 미룹니다.
   f. 어셈블리: `#define` 값이 명령 바이트에 들어갔는지(전처리 여부), 재배치(외부 pc·데이터 절대)를 `macho_obj` 와 llvm 으로 확인.
   g. MIG: m68k·i386 생성 `.c`·`.h` 를 python 으로 비교해 다른 줄 목록을 기록(다르면 원인 후보만 적고 판단은 보류), m68k 생성 코드가 G 로 컴파일됨.
4. 기록: 이 절 결과, 기준 문서 12 절, GCC27 문서 툴체인 확인 상태 한 줄(m68k probe 결과 인용). 07·06·기존 탐침·도구는 바꾸지 않습니다.

끝 조건: 모든 RUN 종료 0·게시, a–g 통과(g 는 차이가 있어도 기록되면 통과), 도구 해시 전후 동일. SPARC 는 이번 범위가 아닙니다(D066).
미해결로 남기는 것: 원본 1997 컴파일러와의 코드 동일성(M0-2), 원본 커널 구조체 오프셋 대조(M3), m68k VM 의 m68k `migcom` 출력과의 비교.

### 412.1 codex 교차검토(gpt-6.1-sol, kb35a8gso) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `llvm-objdump-14` 는 m68k 명령을 제대로 풀지 못함(`--triple` 없으면 대상 없음, 있으면 `invalid instruction encoding`) | `m0p411-pr1/out/a-m68k.o` 에 두 명령 실행: `unable to get target for ''`, `--triple=m68k` 는 경고 3 줄과 기호 줄만 출력 | ✅ 역어셈블 대조에서 llvm 을 뺌(절·기호·재배치·16 진 출력에는 계속 씀) |
| capstone 4.0.2 는 확장 정밀 즉시값 `fmove.x` 를 잘못 풂 | python capstone(`CS_MODE_M68K_040`)에 `f23c4800 3fff8000 00000000` → `fmove.x invalid, fp0`, 12 B 중 4 B 만 소비; `4856`→`pea.l (a6)`, `207900000172`→`movea.l $172.l, a0` 는 정상 | ✅ capstone 단독 판정 금지. 대신 **컴파일러 자신의 어셈블리(`-S`)** 를 기준으로 두고, otool·capstone 의 명령 수·경계·길이를 그와 대조, 불일치는 기록 |
| LLVM D142080·D147480, capstone #3013·#3016 | 열지 않음 | ⏭️ 옮기지 않음 |
| G(`-nostdinc`)로 `objc_probe.m` 을 빌드하면 `<objc/Object.h>` 를 못 찾음 | `objc_probe.m:2` `#import <objc/Object.h>`, 계획 412 의 "ObjC `objc_probe.m`(D·G)" | ✅ 머리가 필요한 탐침은 `-nostdinc` 없는 H 세트(= G − `-nostdinc`)로; 읽은 머리는 `-E` 줄 표시로 기록 |
| i386 대조군에 `c_layout`·`objc_probe` 가 빠짐 | 계획 412 의 대조군 문장(`c_abi`·`c_call`·MIG 만) | ✅ 더함 |
| `check_macho_obj` AGREE 는 절 내용·정렬을 검사하지 않음(이름·크기·주소만) | `check_macho_obj.py:37`–`:38` 의 비교 튜플 `(sectname, size, addr)` | ✅ 배치 표 바이트는 따로 대조(3c), 절 정렬은 `macho_obj` 값으로 기록 |
| `run.json` 에 실행 ID·수집 시각이 있어 "출력 해시 전부 같음" 이 성립할 수 없음 | 기존 `run.json` 키: `id`, `prepared_utc`, `collected_utc` … | ✅ 결정성 비교는 `run.json`·`_log` 를 뺀 산출물로 |
| 모든 명령이 종료 0 이어야 게시됨(기대 실패 시험은 따로) | `kr_run.py` collect 의 `need(rc == '0', …)` | ✅ 거부가 예상되는 옵션 시험은 넣지 않음 |
| `mig` 는 작업 디렉터리에서 `"$base".d` 를 지움 | 실기 `/usr/bin/mig` 본문(`rm -f "$base".d "$base".d~`) | ✅ `RUNIN stage/mig_m68k`·`stage/mig_i386` 로 분리 |
| `EXPECT` 는 `stage/` 없이 씀 | `kr_run.py` collect 의 `os.path.join(rdir, 'stage', e)` | ✅ |
| C 인라인 asm 제약자 탐침이 없음 | GCC27 문서 `:35`(inline assembly 확인)·`:39`(operand/constraint); 참고 `mk-108.1` 의 m68k 인라인 asm 은 `=a`·`a`·`=dm`·`=m`·`Jdm` 사용(`next/spl.h:42`·`:43`, `kern/lock.c:187`, grep) | ✅ 같은 제약자 글자만 쓰는 프로젝트 작성 탐침 `c_iasm.c`(문장은 새로 씀) |
| 정렬 종류(멤버·집합체·배열 보폭·전역·스택), 비트필드 멤버 위치·부호, 좁은 정수 인자, 구조체 모양별 반환(호출·피호출 양쪽), 가변 인자 피호출, 옛 형식 정의, enum 범위, `long long`·`long double` 인자, 보조 함수 기호 | 계획 412 목록과 대조(없음) | ✅ 탐침에 넣음(아래) |
| `((unsigned long)&((T*)0)->f)` 정적 초기화는 C89 상수식이 아니며 접혔는지 확인 필요 | `c_layout.c:8` | ✅ 표 범위에 재배치가 하나도 없어야 함, 컴파일 진단(`_log/*.err`) 비어야 함 |
| `-fwritable-strings` 효과는 D→O 묶음에 섞임 | 계획 412 옵션 정의 | ✅ 문자열 탐침 `c_str.c` 만 O 와 O − `-fwritable-strings` 둘로 |
| m68k 기본 CPU·FPU 설정을 확인할 것 | §409 `m0p409-xc1/out/_log/00.err`: `cc1obj … -arch m68k -quiet … -dynamic -fPIC`(`-m` 옵션 없음), `GNU Obj-C version 2.7.2.1 (68k, MIT syntax)` | ✅ `-v` 출력과 생성 명령(68040/68881 명령 사용 여부)을 기록 |
| `-g` 에서 코드 바이트가 같을 필요 없음 | GCC27 문서 `:18`(`-g` 에서만 인라인 판단이 다른 사례) | ✅ G 는 배치 표 값만 같아야 함 |

수정된 방법(412 의 1–3 을 대신함):
1. 새 탐침 소스(`10_tools/reconstruction/probes/`): `c_abi.c`(자료만), `c_call.c`(호출·반환·옛 형식·레지스터 압박·보조 함수), `c_vararg.c`(SDK `<stdarg.h>` 로 가변 인자 피호출), `c_iasm.c`, `c_str.c`, `asm_pp_m68k.s`.
2. 세트: D(`-arch A -c`), O(`-static -fwritable-strings -traditional-cpp -nostdinc -O3 -fno-omit-frame-pointer`), G(O + `-g`), H(G − `-nostdinc`, 머리가 필요한 것), W(O − `-fwritable-strings`, `c_str` 만).
   m68k: `c_layout`·`c_codegen`·`c_abi`·`c_call`·`c_iasm`·`c_str` × D·O·G, `c_vararg`·`objc_probe` × D·H, `c_str` × W, O 세트 C 탐침과 `c_vararg`(H)의 `-S`, `asm_pp_m68k.s`(H), MIG(RUNIN, H 로 컴파일), `-v` 한 줄.
   i386 대조: `c_layout`·`c_abi`·`c_call`·`c_str` × O, `c_vararg`·`objc_probe` × H, `-S`(O), MIG(H).
3. 검사: a 결정성(`run.json`·`_log` 제외 산출물 해시 동일), b D·O 객체 `check_macho_obj` AGREE(G·H 의 불일치는 STAB 줄인지 하나씩 분류), c 배치 표·값 인스턴스를 `macho_obj` 와 llvm 16 진 출력에서 각각 찾아 풀어 일치·표 범위 재배치 0·세트 간 동일·i386 `c_layout` 이 §11.2 와 같음,
   d 역어셈블: 컴파일러 `-S` 를 기준으로 otool(실기, 게시 뒤 읽기 전용)·capstone 의 명령 수·주소·길이 대조, 불일치 목록, 호출 규약 관찰은 `-S` 줄 인용으로 표, e ObjC 절 집합·크기(관찰), f `.s` 전처리 값·재배치, g MIG 차이 줄, h 정해 둔 기호·관찰이 모두 있음, i 도구 해시 전후 동일.

### 412.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m0-abi-m68k-20261009.json`

실행: kr_run `m0p412-abi1`·`m0p412-abi2`(실기, 같은 입력, 명령 49 개, 모두 종료 0·게시). 컴파일러 진단은 없고(`_log/*.err` 는 `-v` 한 줄짜리 실행만 비어 있지 않음),
도구 17 개(`/lib/m68k/*` 7, `/lib/i386/*` 5, `/bin/cc`·`/bin/as`·`/usr/bin/mig`·`/usr/lib/migcom`·`/bin/otool`)의 해시는 실행 전후 같고 `/bin/otool` 말고는 §409 기록과 같습니다(`/bin/otool` 은 §409 목록에 없음).
새 파일: 탐침 소스 6 개(`probes/c_abi.c`·`c_call.c`·`c_vararg.c`·`c_iasm.c`·`c_str.c`·`asm_pp_m68k.s`), 검사 도구 `10_tools/reconstruction/m0_abi_probe.py`. otool 출력은 `08_build/artifacts/m0p412/otool/`(무시 대상).

검사(모두 python):
- a 결정성: `run.json`·`_log` 를 뺀 산출물 53 개의 해시가 두 실행에서 모두 같습니다.
- b llvm 대조: 객체 34 개 중 D·O·W·`.s` 20 개 AGREE, `-g` 객체 14 개는 차이가 모두 STAB 줄(개수가 `macho_obj` 의 STAB 수와 같음)로 분류됨. 원천 파일 이름 STAB(`N_SO`)은 이름에 `:` 가 없어 처음 분류식이 놓쳤고, 실제 STAB 이름과 대조하도록 고쳤습니다.
- c 배치: 표 두 개(`_kr_layout` 21 칸, `_kr_abi` 52 칸)를 `macho_obj` 와 llvm 16 진 출력에서 따로 찾아 읽어 같고, 표 범위의 재배치 0, m68k D·O·G 세 벌이 같고, i386 `c_layout` 은 §11.2 기록과 같습니다.
  값 인스턴스 11 개의 필드 가설 19 개(m68k 는 빅엔디언 정수에서 최상위 비트부터, i386 은 리틀엔디언에서 최하위 비트부터)가 모두 초기값과 같습니다.
- d 역어셈블: 함수 53 개. 컴파일러 `-S` 와 otool 의 명령 수는 `-S` 가 있는 52 개 중 51 개가 같고, 다른 하나(`_kr_switch`)는 `__text` 안 점프 표 `.long` 7 개(otool 이 `orb` 7 개로 풂)만큼 다릅니다.
  otool·capstone 경계는 36 개가 같고 17 개가 다른데, 17 개 모두 capstone 4.0.2 결함으로 분류됩니다: `bsr.l`(0x61ff, 68020 32 비트 변위)를 2 바이트로 읽음 15, 확장 정밀도(`.x`) 메모리 원천 FPU 명령 2(그중 하나는 거기서 멈춤). 같은 자리를 otool 은 `-S` 와 맞게 풉니다.
  llvm-objdump-14 는 m68k 명령을 풀지 못합니다(412.1).
- 관찰 37 건은 `-S` 의 줄을 인용하고, 도구가 그 줄에 인용 문자열이 있는지 확인합니다(처음 적은 줄 번호 4 개가 틀려 고침).
- e ObjC: m68k·i386(H) `objc_probe.o` 의 절 21 개 이름 집합이 같고, 크기는 `__text`(92·91 B) 말고 모두 같으며, 정렬이 다릅니다(m68k 2^1, i386 2^2). D(PIC) 에는 `__picsymbol_stub`·`__la_symbol_ptr` 가 더 있습니다.
- f 어셈블리: `.s` 는 전처리됩니다 — `addql #KR_VAL,d0` 가 `5a80`(= `addql #5,d0`, python 으로 부호화), `.long KR_VAL` 이 5. 재배치는 외부 `jsr` 절대 1·`.long _kr_pp` 지역 절대 1.
- g MIG: `mig -arch m68k`(m68k cpp + i386 migcom) 와 `-arch i386` 의 `krprobe.h`·`krprobeUser.c`·`krprobeServer.c` 가 줄 단위로 같고(23·213·212 줄), H 로 컴파일됩니다.
- h 정해 둔 기호가 모든 객체에 있습니다.

m68k(`cc-744.13 -arch m68k`) ABI 측정값(i386 대조와 다른 것 위주; 근거는 기록의 `c_tables`·`d_observations`):
- 크기: char 1, short 2, int·long·포인터·float 4, double·long long 8, long double 12(68881 확장: 지수 16 비트, 0 채움 16 비트, 명시 정수 비트가 있는 가수 64 비트). char 는 부호 있음, enum 은 4 바이트·음수 허용.
- **정렬은 최대 2 바이트**: 2 바이트 이상인 형은 모두 `__alignof__` 2, `{char; T}` 의 T 오프셋은 모두 2, 전역도 2 바이트 경계(`_kr_g_c1` 272 → `_kr_g_i` 274). 구조체는 최소 정렬·크기 단위가 2(`struct {char}` 2 B, `struct {char[3]}` 4 B, 그 배열 보폭 4).
  예: `{char; int; short}` 8 B(i386 12), `{char; double}` 10 B(i386 12), 기존 `s4` 18 B(i386 24).
- 비트필드: 최상위 비트부터 채우고 저장 단위 경계를 넘을 수 있음(`u:12×3` 6 B, i386 8 B), `int :0` 은 2 바이트 경계로(`{u:4; int:0; u:4}` 4 B, i386 8 B), `{char; int b:4}` 2 B, 이름 없는 `int` 비트필드는 부호 있음(`bfexts`).
- 호출: 인자는 오른쪽부터 스택에 쌓고 모두 4 바이트 칸(char·short 는 칸의 오른쪽 끝, 8 바이트 형도 4 바이트 경계), 프로토타입 있는 float 는 4 바이트, 프로토타입 없거나 옛 형식이면 double 로 승격, 구조체 값은 크기대로 칸에(2 바이트 구조체는 오른쪽 끝). 가변 인자도 같은 칸 배치.
- 반환: 정수·포인터 d0(char·short 는 피호출 쪽이 32 비트로 확장), long long·double d0:d1(상위 d0), **float 도 d0**(fp0 아님), long double 은 a1 이 가리키는 곳에 쓰고 a1 을 d0 에도 둠,
  구조체는 4 바이트 이하 d0, `{int,int}` d0:d1, `{int[3]}`·`{double}`(8 B 이지만) 은 호출 쪽이 a1 으로 준 곳(주소를 d0 에도 둠).
- 보존 레지스터: d2–d7·a2–a5, FP 는 fp2·fp3 (fp4–fp7 은 이번 탐침에서 쓰이지 않아 미확인; 관찰: `moveml #0x3f3c` = d2–d7,a2–a5, `fmovem #0xc` = fp2,fp3 — 마스크는 python 으로 풂), a6 프레임 포인터. 잎 함수는 `link` 대신 `pea a6@; movel sp,a6`.
- 명령 집합: 68020 이상(`bsr.l`, `bfexts`/`bfextu`/`bfins`, `extbl`, `mulsl`)과 68881(`fmovex` 등)을 기본으로 냅니다(`-m` 옵션 없이; cc1obj 판 문자열 "68k, MIT syntax").
  double→int 변환은 FPCR 반올림을 0 방향으로 바꿨다가 되돌립니다.
- 보조 함수(정의되지 않은 기호): m68k `__ashldi3`·`__divdi3`·`__fixdfdi`·`__floatdidf`·`__umoddi3`, i386 `__divdi3`·`__umoddi3`.
- 인라인 asm: 제약자 `=a`·`a`·`=dm`·`=m`·`Jdm`, 일치 제약 `"0"`, 덮어쓰기 `"cc"`·`"memory"` 를 받아들입니다(진단 없음). `Jdm` 에 상수를 주면 즉시값(`movw #9984,sr`).
- 문자열: `-fwritable-strings` 이면 리터럴이 `__DATA,__data` 에 하나씩(같은 문자열도 합치지 않음), 빼면 `__TEXT,__cstring` 에 합쳐 놓입니다.

판단: GCC27 문서 완료 판정 2 의 m68k 작은 탐침(C·ObjC·어셈블리·MIG·구조체 배치)이 `cc-744.13` 으로 통과했습니다. 측정 범위는 이 컴파일러와 D·O·G·H·W 옵션이고,
1997 원본 컴파일러와의 코드 동일성(M0-2), 원본 m68k 커널 구조체 오프셋 대조(M3), ObjC 메타데이터 내부 해석(`objc_meta` 확장), SPARC 는 남았습니다.

## 413. M0-2 세부 계획 — m68k: `cc-744.13` 과 1997 원본 m68k 컴파일러의 코드 동일성 측정(07·x86 표·기존 도구 변경 없음; 코딩 전, 2026-10-09)

배경: 기준 문서 M0-2. 원본 m68k 커널(mk-183.34, 1997-04-27)을 만든 컴파일러가 실기 `cc-744.13` 과 같은 코드를 내는지 모릅니다. i386 에서는 §409 가 정황을 주었고
(1997 i386 조각에서 재빌드 객체 대부분 통과), m68k 백엔드는 같은 fat 파일이라는 정황뿐입니다. 이번에는 **아키텍처에 따라 전처리 결과가 바뀌지 않는 소스**만 골라
m68k 로 컴파일하고 원본 m68k 커널과 L1 로 비교해, 소스·머리 요인을 줄인 상태에서 컴파일러 요인을 잽니다.

확인한 사실(이번 세션, python, 읽기 전용):
- §409 기록(`m0-i386-18334-l1-20261009.json`)에서 등급 A·ObjC 아님·x86 과 1997 i386 조각 모두 OBJECT_MATCH 이고, `__TEXT,__text` 의 외부 기호가 모두
  원본 m68k 기호표(`03_original/m68k/inventory/symbols.tsv` 의 `defined_external`)에 있는 객체가 195 개(`__text` 394,952 B)입니다. 모두 `s6l4-g1a` 의 평범한 `RUN /bin/cc` 줄로 만들어졌습니다.
- 그 입력 스테이징 `08_build/runs/tools/s6l4-g1a-stage` 는 매니페스트 837 파일과 디스크 837 파일이 같고 SHA 가 모두 맞습니다.
- 스테이징의 `machine/` 머리는 `ARCH_INCLUDE` 나 `__i386__` 분기로 i386 머리를 고릅니다(예: `src/bsd/machine/endian.h`, `src/machdep/machine/features.h` 는 그 밖이면 `#error`).
  따라서 이 머리를 거치는 소스는 m68k 로 그대로 컴파일되지 않거나 다른 텍스트가 됩니다.

방법:
1. 후보: 위 195 개 중 C 소스(`.c`)만. 객체마다 s6l4 의 컴파일 줄을 그대로 쓰고 `-arch` 와 출력만 바꿉니다(최적화·`-g`·정의·포함 경로 동일; `-O` 는 `__OPTIMIZE__` 를 바꾸므로 `-E` 에도 그대로 둠).
2. run 1 `m0p413-pp1`(실기 kr_run, 입력은 위 스테이징): 후보마다 `-arch i386 … -E -o stage/NNN.i386.i`. 호스트에서 python 으로 줄 표시(`# n "file"`)를 읽어 포함 파일 목록을 만들고,
   (a) 경로 요소에 `i386`·`m68k`·`machine` 이 있거나 `ARCH_INCLUDE.h` 를 포함한 객체, (b) 소스·포함 파일 원문에 아키텍처 이름(`i386`·`__i386__`·`m68k`·`mc68000`·`__BIG_ENDIAN__`·`__LITTLE_ENDIAN__`·`BYTE_ORDER`·`sparc`·`hppa`·`ppc`)이 나오는 객체를 뺍니다.
   (b) 는 보수적 거르기이고(실패하는 m68k 컴파일로 run 전체가 게시되지 않는 것을 막음), 판정의 근거는 3 의 비교입니다.
3. run 2·3 `m0p413-m68k1`·`m0p413-m68k2`: 남은 객체마다 `-arch m68k … -E -o stage/NNN.m68k.i` 와 `-arch m68k … -c -o stage/NNN.o`. 두 run 의 산출물 SHA 가 같아야 합니다(결정성).
   m68k 백엔드(`/lib/m68k/*`) 해시는 run 전후 목록으로 보충합니다(§412 와 같은 방법). 호스트에서 객체마다 i386 `.i` 와 m68k `.i` 가 **바이트 동일**한지 봅니다.
   다르면 비교 대상에서 빼고 이유를 적습니다(다른 줄 수).
4. 비교: `.i` 가 같은 객체를 `l1_compare.py --image 03_original/m68k/binaries/mach_kernel --obj NNN.o --place-from-image` 로 비교합니다.
   python 집계: 객체 판정, 이유 종류, `__TEXT,__text` 함수 판정 수·바이트(MATCH·MATCH_UNVERIFIED·DIFF·미배치), 경로(디렉터리)별. 대조군으로 같은 객체의 s6l4 i386 객체가 x86 원본에서 OBJECT_MATCH 인 것은 §409 기록으로 둡니다.
5. DIFF 함수의 진단(판정과 분리): 함수 크기(원본은 다음 외부 기호까지, 객체는 기호 범위)의 같음/다름, 처음 다른 바이트 위치. 명령 수준 비교가 필요하면 실기 `otool` 로 원본과 객체를 읽기 전용으로 풀어 봅니다
   (capstone 은 `bsr.l`·`.x` 메모리 원천 FPU 명령을 잘못 읽으므로 쓰지 않음, §412.2).
6. 해석 규칙(미리 정함): MATCH 함수 = "`cc-744.13 -arch m68k` 와 기록된 플래그·07 소스·스테이징 머리로 만든 객체가 그 함수에서 이 도구의 비교를 원본 m68k 커널과 통과함"
   — 그 함수에 대해 1997 m68k 컴파일러와 구별되지 않는다는 근거입니다. DIFF 는 원인(소스 판 183.34 ↔ 183.34.4, 구성 값 H-meta, 플래그, 컴파일러)을 가르지 않습니다.
   MATCH 가 많으면 컴파일러 동일의 정황이 강해지고, 적어도 컴파일러 차이의 증명은 아닙니다. m68k 의 2 바이트 재배치·SECTDIFF 가 나오면 §411 의 미검증 항목이므로 따로 셉니다.
7. 기록: 이 절 결과, `09_validation/reconstruction/m0-m68k-cc-l1-20261009.json`(객체별 상세는 무시 대상 `08_build/artifacts/m0p413/`, SHA 로 묶음), 새 도구 `10_tools/reconstruction/m0_m68k_l1.py`
   (명령 파일 생성·`.i` 대조·L1 실행·집계). 07·x86 표·기존 도구는 바꾸지 않으므로 x86 회귀는 해당하지 않습니다. 로컬 기준 문서 M0-2 문단 갱신.

### 413.1 codex 교차검토(gpt-6.1-sol, klfatek4s) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 2 의 거르기로는 195 개가 모두 빠짐(기존 `-M` 의존 목록 기준) | `08_build/runs/s6l4-g1a/run.cmd` 의 `-M` RUN 312 개와 `out/_log/NN.out` 를 python 으로 대응: `.c` 194 개 모두 경로 요소 `i386`·`machine` 또는 `ARCH_INCLUDE.h` 를 거침, 나머지 1 개는 `.s`(`start.s`). 가장 흔한 것 `ARCH_INCLUDE.h` 185·`mach/machine/boolean.h` 184 | ✅ 결론 사실(codex 의 186+9 분할은 내 규칙과 달라 옮기지 않음). 방법을 바꿈(아래) |
| 원시 `.i` 동일은 보수적 거르기일 뿐이고 줄 표시와 확장 코드 차이를 구분해야 함 | §412 `m0p412-abi1/out/m68k_H_c_vararg.i` 의 줄 표시 형식 확인(`# n "file" flags`) | ✅ 줄 표시로 줄마다 출처 파일을 붙여 차이를 출처별로 분류 |
| `-imacros meta_features.h` 가 가져오는 머리는 `-M` 목록에 안 나옴; `__ARCHITECTURE__`·`__TARGET_ARCHITECTURE__` 도 아키텍처 단어 | `06.out` 에 `cpus.h`·`confdep.h` 0 건(grep); `ARCH_INCLUDE.h` 가 `__TARGET_ARCHITECTURE__`←`__ARCHITECTURE__` 로 경로를 만듦(파일 읽음); `meta_features.h` 의 `#import` 50 개 파일에 `i386`·`m68k`·`__ARCHITECTURE__` 0 건(grep -l 빈 출력) | ✅ 생성 머리는 아키텍처 단어 없음을 기록. 판정은 `.i` 출처 분류로 함 |
| 실패한 RUN 하나가 게시를 막음; `-E -o` 는 이미 됨; EXPECT 는 `stage/` 없이 | `kr_run.py:328–329`(rc≠0 이면 거부), `:141–144`·`:340–345`(EXPECT 는 `stage/` 를 붙여 찾음), `m0p412-abi1/run.cmd:33`(`-E -o`)·EXPECT 줄 | ✅ 전처리 run 을 먼저 따로 하고, 실패 객체는 로그로 확인해 다음 run 에서 뺌 |
| 배치는 한 절의 모든 대응 기호가 같은 델타일 때만 됨; 함수 하나 크기가 다르면 그 절 전체가 미배치 | `l1_compare.py:466–478`(`placements_from_image`, `len(ds) == 1`) | ✅ 미배치는 DIFF 로 세지 않고 따로 셈. 보조 진단으로 함수마다 원본 기호 주소에서 재배치 필드를 가린 바이트 대조(판정 아님) |
| 추론은 4 바이트 필드만 씀; 좁은·pc 상대 리터럴 참조는 미확인; 외부 재배치는 type≠0 검사 전에 반환 | `l1_compare.py:266`(`if w == 4 else None`), `:340–342`, `:188–197`(extern 분기가 `:198` 의 type 검사보다 앞) | ✅ 객체마다 재배치 종류(외부·pc·폭·type)를 세고, 1·2 바이트 필드·type≠0 이 들어간 함수는 MATCH 라도 따로 표시 |
| 리터럴은 `S_CSTRING`·`S_LITPTR` 만 내용 대조, 절 전체는 비교 안 함; `-fwritable-strings` 이면 문자열이 `__data` | `l1_compare.py:101–105`, `:307–310`; §412.2 문자열 결과 | ✅ 해석에 적음(`__data` 배치 결과가 플래그 가설의 시험이 됨) |
| 함수 "크기" 는 기호 범위이고 원본은 이름 없는 정적 함수를 품을 수 있음; STAB 정보는 무시 | `l1_compare.py:372–381`(객체 기호로 범위) | ⚖️ 범위가 기호 범위인 것은 사실. 객체 쪽 정적 함수는 `-g` 객체에서 비-STAB 지역 기호로도 있으므로 "STAB 에만 있어 합쳐짐" 은 이번 객체에 그대로 맞지 않음. "기호 범위" 로 적음 |
| DIFF 는 코드 바이트 차이 없이 참조 데이터 절 실패로도 생김; 추론은 원본 값을 씀 | `l1_compare.py:383–384`, `:245–266` | ✅ DIFF 를 코드 바이트·재배치·의존 절로 나눠 셈 |
| 같은 이름이라도 다른 구현(예: m68k `_strlen` 은 어셈블리) | 이번 후보에서 자기 파일이 `i386/` 아래인 18 개(`machdep/i386/libc/*` 포함)는 이미 빠짐(python) | ⏭️ 예시는 대상 밖이라 옮기지 않음. 일반 원칙은 해석에 적음 |
| 강하게 고른 부분집합이므로 거르기 단계별 수를 보고하고 일반화하지 말 것 | 설계 판단 | ✅ |
| 결정성은 `.i`·`.o` 만 대조, 도구·입력 해시로 묶을 것 | §412 방법(`run.json` 제외) | ✅ |

추가로 확인한 사실(이번 세션):
- `.c` 194 개 중 자기 파일이 `i386/` 아래 18, `machdep/`·`dev/`·`driverkit` 의 아키텍처 머리를 거치는 100 을 빼면 **76 개(`__text` 93,677 B)** 가 남고(python), 이들이 거치는 아키텍처 머리는 24 개입니다.
  그중 22 개는 실기 SDK `/NextDeveloper/Headers/…/i386/` 의 사본(스테이징 매니페스트 주석), `bsd/i386/reboot.h`·`spl.h` 2 개는 프로젝트 작성본입니다.
- 실기 SDK 의 m68k 디렉터리(`ls`, 읽기 전용): `architecture/m68k` 6 개(`fpu.h`·`frame.h`·`sel.h` 없음), `ansi/m68k` 7, `bsd/m68k` 17, `bsd/rpc/m68k` 1, `kernserv/m68k` 2, `mach/m68k` 9.

고친 방법(앞의 2–4 를 대체):
2'. **m68k 스테이징**: 위 여섯 SDK m68k 디렉터리의 모든 파일을 실기에서 `cat` 으로 무시 대상 `08_build/artifacts/m0p413/sdk-m68k/` 에 복사하고 실기 `krsha256` 과 호스트 SHA 를 대조합니다(D017: SDK 사본은 로컬).
   `s6l4-g1a-stage` 를 새 무시 대상 `08_build/runs/tools/m0p413-stage` 로 복사하고, i386 짝이 놓인 자리(`components/architecture/m68k`, `nextdev/ansi/m68k`, `src/bsd/m68k`, `src/bsd/rpc/m68k`, `src/kernserv/m68k`, `src/mach/m68k`)에 더합니다.
   기존 파일은 바꾸지 않습니다(같은 이름이 이미 있으면 SHA 가 같을 때만 둠). 매니페스트를 새로 씁니다.
3'. 대상: 76 개 중 프로젝트 작성 머리(`bsd/i386/reboot.h`·`spl.h`)나 SDK m68k 짝이 없는 머리(`architecture/i386/{fpu,frame,sel}.h`)를 거치는 객체를 뺀 것.
4'. run A `m0p413-pp1`: 대상마다 `-arch i386 … -E` 와 `-arch m68k … -E`(같은 새 스테이징). 실패가 있으면 로그로 원인을 적고 그 객체를 빼서 새 ID 로 다시 합니다.
   호스트 python: 줄 표시로 줄마다 출처 파일을 붙이고, 두 `.i` 의 차이(줄 표시 제외)가 모두 아키텍처 디렉터리(`/i386/`·`/m68k/`) 출처인 객체를 "공유 텍스트 같음" 으로, 아니면 "공유 텍스트 다름" 으로 나눕니다(뒤의 것도 비교하되 따로 셈).
5'. run B·C `m0p413-cc1`·`m0p413-cc2`: 남은 객체마다 `-arch m68k … -c`(s6l4 줄 그대로, `-arch` 만 바꿈). 두 run 의 `.o` SHA 동일(결정성). m68k 백엔드 해시는 run 전후 목록(§412 방법).
6'. 비교·집계는 앞의 4–6 과 같고, 413.1 판정대로 미배치·재배치 종류·DIFF 원인을 나눠 셉니다. 거르기 단계별 수(195 → … → 비교 대상)를 기록합니다.
   해석에 더함: 머리는 1997 커널 빌드의 내부 머리가 아니라 같은 시기 SDK 의 m68k 머리이므로 머리 요인이 남습니다.

### 413.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m0-m68k-cc-l1-20261009.json`

준비:
- 실기 SDK m68k 머리 42 개를 `cat` 으로 복사, 실기 `krsha256` 과 호스트 SHA 42/42 같음. 새 스테이징 `m0p413-stage` 는 기존 837 파일 + 41 개(`bsd/m68k/fptrace.h` 1 개는 같은 SHA 로 이미 있음) = 878 파일, 매니페스트와 디스크가 같음(도구 assert).
- 거르기(python, `m0_m68k_l1.py select`): 402 → 등급 A·비 ObjC·두 이미지 OBJECT_MATCH 아님 143, 외부 `__text` 기호 없음 12, m68k 원본에 없는 기호 52, `.c` 아님 1, 자기 파일이 `i386/` 18,
  i386 머리가 SDK 사본이 아니거나 SDK m68k 짝 없음 130(가장 많은 것 `machdep/i386/machspl.h` 37·`architecture/i386/frame.h` 26·`bsd/i386/spl.h` 26) → **대상 46 객체**(i386 `__text` 50,252 B).
- 실기 도구 12 경로 해시: run 전후 같고 §412 기록과도 같음.

전처리(run `m0p413-pp1`, 92 명령 모두 종료 0, 게시):
- `.i` 비교(python): 아키텍처 디렉터리 밖 차이 없음 2, `expansion` 44 — 공유 텍스트의 차이는 `TRUE`/`FALSE`(i386 `((boolean_t) 1)` ↔ m68k `(1)`), 바이트 순서 매크로(`NXSwapBigLongToHost(…)` ↔ 그대로) 등
  머리 매크로 펼침이고, `.c` 자체에서 줄이 생기거나 사라진 객체(`source_structural`)는 0, 46 개 `.c` 원문에 아키텍처 이름 0(단어 경계 검사; 처음 검색의 `inp_ppcb` 같은 부분 일치는 오탐).

컴파일(run `m0p413-cc1`·`cc2`, 46 명령씩 모두 종료 0, 게시):
- 두 run 의 `.o` 46/46 SHA 같음. 컴파일 경고가 있는 객체 15, 46/46 이 같은 객체의 s6l4 i386 컴파일과 경고 내용이 같음(파일:줄 앞부분 제외).
- 재배치(`__text`): 외부 pc 723·외부 절대 547·지역 절대 231·지역 pc 143·scattered 19, 모두 4 바이트 VANILLA. 1·2 바이트 필드나 type≠0 은 0 → §411 의 m68k 미검증 형식은 이번 판정에 들어가지 않음.

원본 m68k 커널과 L1(python 집계):
- 객체: **OBJECT_MATCH 18**(`__text` 7,480 B, 15.67 %), NOT_MATCH 28. `__text` 가 배치된 객체 33, 미배치 13(19,118 B — 같은 절 기호들의 델타가 하나가 아님).
- 함수(`__TEXT,__text`, 46 객체 47,724 B): **MATCH 105 개 12,296 B(25.76 %)**, MATCH_UNVERIFIED 5 개 2,144 B(4.49 %), DIFF 57 개 14,166 B(29.68 %), 나머지는 미배치.
  DIFF 원인(겹침): 코드 바이트 54, 재배치 값 37, 참조 데이터 절 실패 7.
- 보조 진단(판정 아님): 외부 함수 221 개를 원본 기호 주소에서 재배치 필드를 가리고 대조 — **173 개(78.28 %) 같음**, 그중 166 개는 원본의 다음 외부 기호까지 거리와 크기도 같음.
  OBJECT_MATCH 객체에는 `tcp_subr`(10 함수)·`ufs_lockf`(13)·`uipc_domain`(6)·`queue`(7)·`if_loop`(4) 등이 있습니다.
- DIFF 예시(python 바이트 + capstone m68k 로 확인, `bsr.l`·`.x` 결함 명령 제외):
  `_chdir` — 크기 82 같음, 재배치 밖 차이는 변위 0x15a ↔ 원본 0x156 뿐(구조체 필드 오프셋 4 차이, 머리·구성 요인으로 보임);
  `__authenticate` — 크기 90 같음, 같은 명령의 기본 블록 순서가 다름; `_ku_sendto_mbuf` — 크기 216 같음, 주소 레지스터 배정(a1 ↔ a0)이 다름.
  뒤의 둘은 같은 07 소스가 1997 i386 조각에서는 통과한 객체이므로, 원인 후보는 m68k 빌드 플래그(46 개 모두 x86 의 `-g -O3` 를 그대로 씀), 원 소스의 m68k 전용 분기, m68k 구성 값, 컴파일러입니다. 가르지 않았습니다.

판단(413 의 해석 규칙대로):
- `cc-744.13 -arch m68k` 는 이 부분집합에서 **1997 원본 m68k 커널과 바이트가 같은 함수 105 개(18 객체는 객체 전체)를 다시 만듭니다.** 재배치를 가린 대조로는 외부 함수의 78 % 가 같습니다.
  이 함수들에 대해 1997 m68k 컴파일러와 구별되지 않습니다. M0-2 의 "작은 객체로 먼저 측정" 은 이 결과로 답했고, m68k 재구성에 `cc-744.13` 을 쓰는 근거가 됩니다.
- 남은 차이는 원인을 가르지 않았습니다(컴파일러 차이의 증명도 아님). 강하게 고른 46 객체의 결과이므로 커널 전체로 일반화하지 않습니다.
- 다음 후보: DIFF·미배치 28 객체에 플래그 격자(`-O2`/`-O3`/`-O4`, `-g` 유무 등)를 대어 플래그 요인을 분리, 구조체 오프셋 차이는 M3(머리·구성)에서 다룸.

새 파일: `10_tools/reconstruction/m0_m68k_l1.py`, 위 검증 JSON. 07·x86 표·기존 도구는 바꾸지 않았습니다.

## 414. M0-2 후속 — §413 의 m68k 차이 원인 분리: 플래그 격자, 머리 구조 차이, 명령 수준 분류(07·x86 표·기존 도구 변경 없음; 코딩 전, 2026-10-09)

배경: §413 에서 외부 함수 221 개 중 48 개가 재배치를 가려도 원본 m68k 와 다릅니다(같은 크기 14, 다른 크기 34; python). 원인 후보는 m68k 빌드 플래그, 머리·구성 값, 원 소스의 차이, 컴파일러입니다.

확인한 사실(이번 세션, 읽기 전용):
- **§413 기록의 정정**: `ppcheck` 의 `expansion` 은 `.c` 에서 줄이 생기거나 사라지지 않았다는 뜻일 뿐, 공유 머리 안의 조건부 구조 차이를 걸러내지 않았습니다.
  예: `src/bsd/sys/user.h`(스테이징, 출처 `07_kernel/nextdev/bsd/sys/user.h`) 146–148 행 `#ifdef i386 … uu_sigreturn` 때문에 `struct utask` 가 m68k `.i` 에서 한 줄 짧습니다(두 `.i` 의 구조체 본문 python 대조: 40 ↔ 39 줄).
  §413.2 의 "공유 텍스트의 차이는 머리 매크로 펼침" 은 이런 구조 차이를 빠뜨린 설명입니다.
- `_umask`(`vfs_syscalls`) 는 실기 `otool -tv -p _umask` 로 원본과 객체를 풀면 `uu_cmask` 변위만 다릅니다(원본 `0x164`, 객체 `0x168`). 객체의 STABS 에서 m68k `struct utask` 의 `uu_cmask` 는 360 B(0x168), `uu_cdir` 346 B(0x15a) 입니다(python).
  `_chdir` 의 `0x15a ↔ 0x156` 도 같은 4 B 차이입니다. 즉 이번 스테이징 머리의 m68k `struct utask` 가 원본보다 그 앞 어딘가에서 4 B 큽니다.
- 원본 m68k 커널은 `not stripped`(실기 `file`), 실기 `/bin/otool -tv -p SYM` 이 원본과 m68k 객체를 모두 MIT 문법으로 풉니다(위 출력). capstone 4.0.2 는 `bsr.l`(0x61ff)을 2 바이트로 읽어 이후를 깨뜨립니다(이번 세션 `_nb_alloc` 등에서 재확인).
- 참고 구성: Darwin 0.1 `kernel/conf/MASTER.i386:81` gdb 구성 `-g -O3 -fno-omit-frame-pointer`, `MASTER.ppc:81` gdb 구성 `-g -O2`, 두 파일 82 행 비 gdb `-O3`; `Makefile.ppc` 의 `MACHINE_CFLAGS` 에 `-finline -fno-keep-inline-functions`;
  KCC 에 `-fno-builtin`; NeXTMach `mk-108.1/conf/Makefile.NeXT:26` m68k `-O -fwritable-strings -fcombine-regs`(GCC 1 옵션). m68k 의 1997 `MASTER` 는 없습니다(01_resources 에 `MASTER.m68k` 0 건, find).
- 바이트 예시(capstone, `bsr.l` 결함 부분 제외): `_raw_attach`·`_dnlc_lookupSymLink` 는 `if (…) return 오류값;` 블록의 놓는 자리가 다르고(방향은 함수마다 반대), `_pn_set` 은 인자 적재 순서, `_nb_alloc` 은 레지스터 배정과 크기(84 ↔ 80)가 다릅니다.

방법:
1. **플래그 격자 run `m0p414-fg1`**(실기 kr_run, 입력 `m0p413-stage`, 대상 §413 의 46 객체): s6l4 컴파일 줄에서 `-g -O3 -fno-omit-frame-pointer` 세 낱말만 아래 변형으로 바꿉니다(`-arch m68k`, 출력 `stage/Vk__BASE.o`).
   V0 `-g -O3 -fno-omit-frame-pointer`(§413 재현 — 46/46 이 `m0p413-cc1` 과 SHA 같아야 함), V1 `-g -O2`, V2 `-g -O2 -fno-omit-frame-pointer`, V3 `-g -O3`, V4 `-g -O`, V5 `-O3`, V6 `-O2`, V7 `-g -O3 -fno-omit-frame-pointer -fno-builtin`.
   46×8 = 368 명령. 하나라도 실패하면 게시되지 않으므로 로그로 원인을 적고 그 변형을 빼서 새 ID 로 다시 합니다. 실기 도구 12 경로 해시는 run 전후(§413 방법).
2. **격자 비교**(호스트 python, 새 도구 `10_tools/reconstruction/m0_m68k_cause.py`, `m0_m68k_l1.py` 의 함수를 가져다 씀): 변형·객체마다 `l1_compare.py --place-from-image` 와 §413 의 재배치 가림 대조.
   집계: 변형별 OBJECT_MATCH 수, 함수 MATCH 수·바이트, 가림 대조 같음 수(221 중). 함수마다 같음이 되는 변형 집합.
   미리 정한 해석: V0 에서 같던 것을 하나도 잃지 않고 더 얻는 변형이 있으면 그것을 "m68k 플래그 후보" 로 적습니다(역사적 사실 아님). 얻는 것이 변형마다 갈리면 결론 내지 않고 표만 둡니다.
   플래그로 같아지는 함수는 "플래그 요인" 으로 분류합니다.
3. **머리 구조 차이 재분류**(새 run 없음, `m0p413-pp1` 의 `.i`): 공유(아키텍처 디렉터리 밖) 파일에서 줄이 생기거나 사라진 차이를 파일별로 세어 객체마다 `header_structural` 여부와 그 파일·줄을 적습니다. §413 의 분류표는 고치지 않고 이번 기록에 정정으로 둡니다.
4. **남은 함수의 명령 수준 분류**: 2 의 최선 변형(없으면 V0)에서 아직 다른 함수를 실기 `/bin/otool -tv -p SYM` 으로 원본과 객체 모두 풉니다(읽기 전용 gcds, 출력은 호스트 파일; capstone 은 쓰지 않음).
   python 정규화: 주소 열 제거, 분기 대상은 함수 안 상대 위치로, 절대 주소 피연산자(재배치 자리)는 `ADDR` 로 바꿉니다. 분류(겹치지 않게 앞에서부터):
   D — 명령 줄 수·연산 부호·레지스터가 모두 같고 변위·즉치값만 다름(머리·구성 값 후보; 다른 값 쌍과 차이를 적음),
   R — 연산 부호 열은 같고 레지스터 이름만 다름(레지스터 배정),
   O — 정규화한 명령의 다중집합이 같고 순서만 다름(블록 배치·명령 순서),
   X — 그 밖. D 는 변위가 `struct utask` 필드(객체 STABS 의 오프셋)와 맞는지 표시합니다.
5. 해석 규칙(미리 정함): 플래그 요인은 2 의 결과로만, 머리 요인은 D 이면서 변위 차이가 머리 구조 차이(3)로 설명될 때만 붙입니다. R·O·X 는 "원 소스 또는 컴파일러" 로 남기고, 같은 07 소스가 1997 i386 에서 통과한 함수인지(§409 기록)를 함께 적습니다. 컴파일러 판 차이를 증명하거나 반증하지 않습니다.
6. 기록: 이 절 결과, `09_validation/reconstruction/m0-m68k-cause-20261009.json`(상세는 무시 대상 `08_build/artifacts/m0p414/`, SHA 로 묶음), 새 도구. 07·x86 표·기존 도구는 바꾸지 않습니다.

### 414.1 codex 교차검토(gpt-6.1-sol, k0b327maz) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `cc.cmd` 46 줄 모두 `-g -O3 -fno-omit-frame-pointer` 가 한 번씩 연속으로 있고 다른 `-O` 없음 → 세 낱말 치환 안전 | python: 46 줄 모두 `count(' -g -O3 -fno-omit-frame-pointer ')==1`, `-O*` 낱말 46·`-g` 46 | ✅ |
| `-g` 를 뺀 `-O3 -fno-omit-frame-pointer`·`-O2 -fno-omit-frame-pointer` 를 더해야 `-g` 요인이 프레임 포인터와 분리됨 | 격자 설계 검토(V5·V6 은 `-fno-omit-frame-pointer` 없음) | ✅ V8·V9 로 더함 |
| `-fno-thread-jumps`·`-fno-caller-saves`·`-fno-force-mem`·`-fno-defer-pop`·`-fno-inline` 후보(GNU 2.8 `toplev.c` 근거) | 외부 GNU 2.8 소스는 cc-744.13 의 근거가 아니며 열지 않음; 실기에서 인식 여부 미확인 | ⏭️ 이번 격자에 넣지 않음(인식 안 되면 run 전체가 막힘). 격자 결과가 갈리면 다음 절에서 실기 탐침 후 검토 |
| kr_run 에 RUN 수 제한 없음, 로그 번호 `%02d` 는 최소 폭, `EXPECT` 는 `stage/` 없이, 0 아닌 종료가 하나라도 있으면 게시 거부, `wait` 1800 초 고정 | `kr_run.py:245–253`(`'%02d' % i`), `:326–329`(`need(rc == '0')`), `:340–345`(`os.path.join(rdir,'stage',e)`), `:364`(`def wait(rid, limit=1800)`) 읽음 | ✅ |
| 가림 대조의 "같음" 은 객체 범위만큼의 앞부분 같음이고 재배치 대상은 확인하지 않음; `_xdr_callhdr` 는 객체 116 ↔ 원본 범위 272 인데 같음 | `m0_m68k_l1.py:385–392` 읽음; `report.json` python: `_xdr_callhdr` object_size 116·image_extent 272·masked_equal True, 같음이면서 범위가 다른 함수 7 | ✅ 변형 비교에서 엄격 L1 MATCH 집합과 "가림 같음 + 범위 같음" 집합을 따로 셈. §413 의 173 중 범위까지 같은 것은 이미 166 으로 적혀 있음 |
| `-g` 는 코드에 영향을 줄 수 있는 실험 요인; 새로 같아진 함수는 "이 입력에서 플래그에 반응함" 이지 역사적 원인 확정 아님 | GCC27 문서 19 행(`sched_prim.c` 는 `-g` 에서만 일치) | ✅ 문구 수정 |
| `read_i()` 는 줄 표시의 줄 번호를 버리고, 전역 difflib 정렬은 다른 머리의 같은 줄을 맞출 수 있으며, 길이 같은 치환이 매크로 펼침의 증명이 아님 | `m0_m68k_l1.py:239–252`(파일 이름과 본문만 보관), `:267–276` 읽음 | ✅ 3 을 (파일, 원 줄 번호) 열쇠 방식으로 바꿈(아래) |
| `otool -p SYM` 은 함수가 아니라 절 끝까지 출력 | 이번 세션 실기 `otool -tv -p _umask` 출력이 `_vhangup:` 으로 이어짐 | ✅ 범위를 기호표로 자름 |
| 객체의 `0x0:l` 자리는 재배치 기록으로 대상을 붙여야 하고, 분기 대상·pc 상대·점프 표 데이터(명령으로 잘못 풀림)에 주의 | `08_build/artifacts/m0p412/otool/m68k_O_c_codegen.txt:24`(`bsr 0x0:l`), `:51–52`(`jmp a0@` 뒤 `orb` 줄 = 표 데이터) 읽음 | ✅ 재배치·원본 기호표로 `기호+차이` 로 바꾸고, `jmp …@(…)` 뒤 표가 있는 범위는 `table` 로 표시 |
| D 는 분기 대상 변화를 빼야 하고, R 은 일관된 레지스터 대응이어야 하며, O 의 다중집합은 휴리스틱; 머리·구성은 R·O·X 의 원인도 될 수 있음 | 설계 검토 | ✅ 분기 대상은 D 판정에서 제외 표기, R 은 일대일 대응 검사, O 는 "휴리스틱" 으로 적고, 5 의 나머지를 "원 소스·머리·구성·컴파일러" 로 넓힘 |
| "`struct utask` 가 4 B 크다" 는 과함 — 관찰한 필드가 4 B 뒤에 있을 뿐, 크기·원인 필드 미확정 | 계획 문구 대조 | ✅ "관찰한 필드(`uu_cdir`·`uu_ttyp`·`uu_cmask`)가 원본보다 4 B 뒤" 로 고침 |

추가 확인: 원본 m68k 기호표(`symbols.tsv`, debug 0)는 모두 `defined_external=1` 입니다(python). 원본에는 정적 함수 이름이 없으므로 명령 수준 비교의 단위는 "외부 기호에서 다음 외부 기호까지" 로 양쪽을 같게 잡습니다(객체 쪽은 그 사이 정적 함수를 포함하고 그 사실을 표시).

고친 방법:
1'. 변형은 V0–V9(V8 `-O3 -fno-omit-frame-pointer`, V9 `-O2 -fno-omit-frame-pointer`), 46×10 = 460 명령, `EXPECT Vk__BASE.o`.
2'. 변형마다 집합 둘: 엄격 L1 함수 MATCH, 외부 구간 가림 같음 + 구간 길이 같음. 해석 규칙은 각 집합에 따로 적용하고, 결론은 "이 입력에서 플래그에 반응함".
3'. 머리 구조: `.i` 의 줄 표시로 (파일, 원 줄 번호) 마다 비어 있지 않은 출력 줄을 모아, 한쪽에만 있는 (파일, 줄) 을 "조건부 구조 차이", 양쪽에 있으나 본문이 다른 것을 "펼침 차이" 로 셉니다(아키텍처 디렉터리 밖만). 구조 차이가 있는 줄은 머리 원문 줄을 함께 적습니다.
4'. 명령 수준: 단위는 외부 구간. 객체는 재배치 기록, 원본은 기호표로 절대 피연산자를 `기호+차이` 로, 구간 안 분기 대상은 상대 위치로 바꿉니다. 분류 D/R/O/X 는 위 판정대로 좁히고, 점프 표가 있으면 `table` 표시.
5'. 머리 요인은 "D 이고 변위 차이가 관찰된 구조 차이와 맞음" 일 때만 붙이며, 나머지는 "원 소스·머리·구성·컴파일러 중 미분리" 로 둡니다.

### 414.2 중간 결과와 추가 단계(코딩 전 계획 덧붙임, 2026-10-09)

중간 결과(run `m0p414-fg1`, 460 명령 모두 종료 0·게시; 실기 도구 12 경로 해시 run 전후 같음; 변형마다 경고 내용 같음):
- V0 이 `m0p413-cc1` 의 46 객체와 SHA 가 모두 같습니다(도구 assert). `-g`·`-fno-omit-frame-pointer` 는 이번 46 객체의 `__TEXT` 를 바꾸지 않았습니다(`-O2` 무리 V1·V2·V6·V9 46/46, `-O3` 무리 V0·V3·V5·V7·V8 45/46 같음; V7 `-fno-builtin` 에서 1 객체 다름).
- **`-O2`(V1)**: OBJECT_MATCH 18 → **30**, 함수 MATCH 105 → **216**(25,958 B), V0 에서 MATCH 이던 함수 중 잃은 것 0. 외부 구간(가림 같음 + 길이 같음) 167 → 195(+32, −4). 잃은 4 개는 모두 `vfs_dnlc`(`-O3` 에서만 같음 — 정적 함수 인라인과 관련, 미분리). `-g -O`(V4)는 크게 나빠짐(MATCH 33).
- V1 에서 남은 외부 구간 26 개를 실기 `otool -tv` 로 분류(정규화 수정 셋 반영: 한 명령의 재배치 여러 개를 차례대로 대응, 객체 지역 분기 대상을 구간 안 상대 위치로, `jmp aN@` 뒤 점프 표를 바이트로 읽어 `.long L+off`): D 8, X 18.
  D 8 개는 모두 변위만 다릅니다: `vfs_syscalls` 7 개(`struct utask` 필드가 원본보다 4 B 뒤 — `uu_cdir`·`uu_rdir`·`uu_ttyp`·`uu_cmask` 와 `0x14a ↔ 0x146`)와 `_host_info`(`0x144 ↔ 0x13c`, 8 B).
- X 의 일부(`_acct`·`_unp_externalize`·`_lookuppn`)는 utask 변위 차이에 더해 **문자열 상수 참조**가 다릅니다: 객체는 `__DATA,__data`(`-fwritable-strings`), 원본은 `__TEXT,__cstring` 을 가리킵니다.
  원본 절 크기(python): m68k `__cstring` 28,920 B·`__data` 22,552 B, 1997 i386 조각 `__cstring` 13,892 B·`__data` 46,692 B — m68k 가 문자열을 `__cstring` 에 두었다는 정황입니다. Darwin `Makefile.i386:53`·`Makefile.ppc:57`, NeXTMach `Makefile.NeXT:26` 은 모두 `-fwritable-strings` 를 씁니다(1997 m68k Makefile 은 없음).

추가 단계(이 절 안, 미리 정함):
7. run `m0p414-fg2`: 46 객체 × 변형 둘 — V10 = V1 에서 `-fwritable-strings` 뺌(`-g -O2`), V11 = V0 에서 뺌(`-g -O3 -fno-omit-frame-pointer`). 다른 낱말은 그대로. `gridcmd` 에 변형 목록 인자를 더해 만듭니다.
8. V10·V11 을 2 와 같은 방법으로 비교하고, V10 에서 남은 구간을 4 의 방법으로 다시 분류합니다. 해석: V1 에서 같던 것을 잃지 않고 얻으면 "`-fwritable-strings` 없음" 을 m68k 플래그 후보로 적습니다(역사적 사실 아님). 잃는 객체가 있으면 파일별 차이로 적고 결론 내지 않습니다.

### 414.3 codex 교차검토(gpt-6.1-sol, kdi97zn7i) 판정, 결과(2026-10-09) — 기록 `09_validation/reconstruction/m0-m68k-cause-20261009.json`

414.2 검토 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| NeXT GCC 2.7.2 는 `flag_writable_strings` 이면 문자열 상수를 data 로, 아니면 cstring 으로(NUL 이 든 문자열은 const) 보냄 | `01_resources/upstream/next-gcc-2.7.2/config/next/nextstep.h:628–639`(`SELECT_SECTION`) 읽음 | ✅ 해석 근거에 더함 |
| 원본 `_lookuppn` 의 `"."` 참조 둘이 같은 주소(문자열 합침), 객체는 따로 | 이번 세션 정규화 출력: 원본 두 줄 모두 `__TEXT,__cstring+713`, 객체 `_metalinks+33`·`+38` | ✅ |
| `m0p412-abi1` 에 `m68k_W_c_str.o`(쓰기 가능 문자열 탐침)가 있음 | `ls 08_build/runs/m0p412-abi1/out/` 에 `m68k_W_c_str.o` 있음 | ✅(내용 대조는 하지 않음 — 결론에 쓰지 않음) |
| `cmd_grid` 가 전역 `VARIANTS` 를 돌고 V0 를 전제함 → V10·V11 만 있는 run 은 그대로 못 씀 | 도구 읽음(내가 쓴 코드) | ✅ `GRID_RUNS` 로 run 두 개를 합쳐 12 변형을 한 번에 비교, V1 기준 증감도 셈 |
| `l1_compare.py` 는 참조된 cstring 내용만 보고 리터럴 절 전체는 비교하지 않음 | `l1_compare.py:137–144`, `:307–310` 읽음 | ✅ 해석에 적음(OBJECT_MATCH 가 문자열 절 전체 같음을 뜻하지 않음) |
| 32 비트 피연산자를 재배치 수로 대응하면 재배치 없는 즉치값과 섞임(합성 예 `movel #0x400:l,0x0:l`) | 고친 뒤 같은 합성 예를 python 으로 돌림: `#0x400:l,@_x+0` | ✅ 재배치 필드에 저장된 값과 같은 피연산자에 대응하도록 고침 |
| `dbf d1,0x…` 형식을 분기로 못 읽음 | 원본 목록 `otool-V1/image.txt:1228` 읽음 | ✅ `dN,` 앞붙이를 허용 |
| 기호 주소 안의 숫자 차이(`@L+8`↔`@L+10`, `_foo+4`↔`_foo+8`)가 D 로 분류됨 | 고친 뒤 합성 예 python: 둘 다 X, `a0@(0x15a:w)`↔`0x156` 는 D | ✅ 기호 피연산자는 그대로 비교 |
| 점프 표 검출이 자료 흐름 없이 앞의 주소만 봄 | 설계 검토 | ✅ `movel aN@(0x0:b,Rm:l:4),aN` + `jmp aN@` 짝일 때만 표로 읽음(`_tcp_input` 는 첨자가 `a2` 라 `[ad]` 로 넓힘) |
| 원본에 쓰기 가능 문자열이 보이면 "모든 파일에 그 플래그 없음" 이 반증됨 | 설계 판단 | ✅ 결론을 이 46 객체로 한정 |

실행(실기, 모두 종료 0·게시, 실기 도구 12 경로 해시 run 전후 같음, 같은 객체의 경고 내용은 변형 사이에 같음):
`m0p414-fg1`(V0–V9, 460 명령), `m0p414-fg2`(V10·V11, 92 명령). V0 은 §413 객체 46/46 과 SHA 가 같습니다.

플래그 격자(python 집계, 원본 m68k 커널과 L1; 외부 구간 221 개):

| 변형 | 플래그 | OBJECT_MATCH | 함수 MATCH | MATCH 바이트 | 구간 같음 |
|---|---|---|---|---|---|
| V0 | `-g -O3 -fno-omit-frame-pointer` (§413) | 18 | 105 | 12,296 B(25.76 %) | 167 |
| V1 | `-g -O2` | 30 | 216 | 25,958 B(55.08 %) | 195 |
| V4 | `-g -O` | 7 | 33 | 1,572 B | 99 |
| **V10** | `-g -O2`, `-fwritable-strings` 없음 | **34** | **240** | **33,734 B(71.58 %)** | 195 |
| V11 | V0, `-fwritable-strings` 없음 | 20 | 112 | 15,172 B | 167 |

- `-g`·`-fno-omit-frame-pointer` 는 46 객체의 `__TEXT` 를 바꾸지 않았습니다(`-O2` 무리 46/46, `-O3` 무리 45/46 같음 — 다른 하나는 V7 `-fno-builtin` 의 `nfs_server`). V2·V6·V9 는 V1 과, V3·V5·V8 은 V0 과 같은 수입니다.
- V1 은 V0 의 함수 MATCH 를 하나도 잃지 않고 111 개를 더 얻고, V10 은 V1 의 MATCH 를 잃지 않고 24 개를 더 얻습니다. 미리 정한 규칙대로 **`-O2` 와 `-fwritable-strings` 없음은 이 46 객체에서 m68k 플래그 후보**입니다
  (Darwin `MASTER.ppc:81` 의 gdb 구성도 `-g -O2`; 역사적 플래그를 확정한 것은 아님). 구간 비교에서는 V1 이 V0 보다 4 개를 잃는데 모두 `vfs_dnlc`(`-O3` 에서만 같음)입니다.
- 머리 조건부 구조(§413 의 `expansion` 정정): 46 객체 중 44 에 공유 머리의 조건부 구조 차이가 있습니다 — `byte_order.h` 44(i386 에만 펼쳐지는 인라인 함수), `vm_param.h` 39(i386 에만 있는 `extern` 선언), `user.h` 15(`uu_sigreturn`), `ip.h` 6·`ip_var.h` 5·`tcp.h` 3(비트 필드 순서).

V10 에서 남은 외부 구간 26 개(실기 `otool -tv` 정규화 분류 D 11·X 15, 원인은 목록을 직접 읽어 적음):

| 원인 | 수 | 함수 |
|---|---|---|
| 머리·구성: `struct utask` 필드가 원본보다 4 B 앞(변위만 다름, `uu_ofile` 0x14a 부터 `uu_start` 0x236 까지 관찰) | 10 | `vfs_syscalls` 7, `_acct`, `_unp_externalize`, `_lookuppn` |
| 머리·구성: `struct processor` 의 `slot_num` 이 8 B 앞(0x144 ↔ 0x13c) | 1 | `_host_info` |
| 구성: 원본에 `simple_lock` 호출 없음, `processor_set` 필드 4–8 B 앞 | 1 | `_compute_mach_factor` |
| 머리: 원본은 `splx`·`splimp` 를 `movew sr` 인라인으로, 객체는 함수 호출(실기 SDK `kernserv/m68k/spl.h` 에 그 인라인 정의가 있으나 이 07 소스의 포함 사슬에는 없음) | 2 | `_ku_sendto_mbuf`, `_VENIP_RIF` |
| 머리 후보: 원본은 `ti_len` 을 두 번 저장(`HTONS` 가 대입형인 정의로 보임), 점프 표 주소는 그 결과로 4 B 밀림 | 1 | `_tcp_input` |
| 배치: 객체 코드는 같고 원본 구간이 이름 없는 정적 함수를 더 품음(`_venip_config` 는 정적 함수 주소만 다름) | 3 | `_xdr_fhstatus`, `_nfs_svc`, `_venip_config` |
| 인라인: `-O3` 변형에서만 같음 | 4 | `_dnlc_init`·`_dnlc_enter`·`_dnlc_lookup`·`_dnlc_purge1` |
| 미분리 | 4 | `_dnlc_enterSymLink`(어느 변형에서도 다름; 같은 객체의 `_dnlc_lookupSymLink` 는 `-O2`·`-O` 에서만 같음), `_icmp_sendMaskPacket`(명령 1 개), `_tcp_mss`(0 확장 1 곳), `_uname`(레지스터 배정, 원본만 점프 표) |

판단:
- §413 의 차이 대부분은 **플래그**(`-O2`, 문자열 상수 위치)로 설명됩니다. 남은 26 구간 중 15 개는 머리·구성 값(구조체 오프셋·NCPUS 계열·인라인 spl·`HTONS`), 3 개는 비교 구간의 경계 문제, 4 개는 `vfs_dnlc` 의 인라인 판단, 4 개는 미분리입니다.
- `vfs_dnlc` 는 같은 객체 안에서 `-O2` 에서만 같은 함수와 `-O3` 에서만 같은 함수가 섞여 있어 한 벌의 플래그로 설명되지 않습니다(원 소스의 `inline` 등 소스 요인 후보, 미확정).
- 컴파일러 판 차이를 가리키는 사례는 이번 분류에서 나오지 않았습니다(증명도 반증도 아님). 머리·구성 요인은 M3(m68k 머리·구성)에서 다룹니다.
- 분류는 46 객체에 한정합니다. 원인 칸은 목록을 읽은 해석이며, `D` 판정만 도구가 자동으로 냅니다.

새 파일: `10_tools/reconstruction/m0_m68k_cause.py`(`m0_m68k_l1.py` 의 함수를 가져다 씀), 위 검증 JSON. 상세(`grid.json`·`hdr.json`·`class-V*.json`·otool 목록)는 무시 대상 `08_build/artifacts/m0p414/` 에 두고 SHA 로 묶었습니다. 07·x86 표·기존 도구는 바꾸지 않았습니다.

## 415. M2-1 세부 계획 — m68k 원본 `__TEXT,__text` 의 객체 후보 지도: 외부 기호를 x86 재빌드 객체에 대응(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: 기준 문서 M2(원본 목록화). M0 의 m68k 항목(§409·411–414)이 끝났고, M3(머리·구성)·M5(공통부)는 m68k 원본의 객체 분할·순서가 있어야 시작할 수 있습니다.
원본 m68k 에는 지역 기호가 없고(§414.1 추가 확인), 이번 m68k 객체의 `__text` 정렬은 2 바이트(§414 V10 객체 46 개 모두 `align 1`, python)이므로 객체 사이 정렬 채움으로는 경계를 정할 수 없습니다.
이번 절은 **외부 기호 기준의 객체 후보 지도**만 만들고, 정확한 경계(정적 함수가 어느 쪽에 붙는지)는 다음 절로 미룹니다.

확인한 사실(이번 세션, python, 읽기 전용):
- m68k 원본 절(macho_obj): `__text` 0x4000310 크기 678,510 B(정렬 2^2), `__cstring` 28,920, `__const` 2,796, `__data` 22,552, `__bss` 9,420, `__common` 82,624.
  `symbols.tsv` 에서 debug 0·section 1 인 기호 2,821 개는 모두 외부 기호입니다.
- §409 기록(`m0-i386-18334-l1-20261009.json`)의 재빌드 객체 402 개(등급 A·A\*·P 전부, `s6l4-g1a` 산출)의 외부 정의 기호 3,232 개는 이름이 겹치지 않습니다.
  m68k `__text` 기호 2,821 개 중 2,042 개가 그 이름과 같고, 주소순으로 같은 객체끼리 묶으면 연속 구간 327 개(대응 없는 구간 50), 나타나는 객체 250 개, 둘 이상으로 갈라진 객체 13 개입니다.
- 이름만 같은 기계 의존 기호(예 `x86-start`·`x86-locore`·`x86-intr` 에 대응되는 m68k 기호)는 m68k 에서 다른 파일일 수 있습니다.

방법(새 도구 `10_tools/reconstruction/m2_m68k_text_map.py`, 읽기 전용 입력, python):
1. 원본: `03_original/m68k/binaries/mach_kernel` 을 macho_obj 로 읽어(SHA 대조) `__text` 의 외부 기호를 주소순으로 얻고, `symbols.tsv` 와 이름·값이 같은지 assert. 같은 주소의 별칭 기호는 한 진입점으로 묶음.
2. 대응: 402 객체(§409 기록의 `obj` 경로, SHA 대조)마다 외부 정의 기호와 그 절. m68k 기호 → x86 객체(그 기호를 x86 에서 `__text` 에 정의한 경우만 "text 대응"; 다른 절이면 따로 표시).
3. 구간: 주소순으로 같은 대응 객체가 이어지는 최대 구간. 구간의 시작 = 첫 기호 주소, 끝의 상한 = 다음 구간의 첫 기호 주소(사이의 정적 함수·이름 없는 코드 포함). 경계는 "앞 구간 마지막 기호 < 경계 ≤ 다음 구간 첫 기호" 인 구간값으로만 적습니다.
4. 객체 분류: contiguous(대응 기호가 한 구간), split(여러 구간 — 사이에 낀 것을 적음), absent(x86 객체가 m68k 에 기호 없음). x86 객체의 `__text` 외부 기호 중 m68k 에 있는 비율.
5. 대응 없는 기호: x86 183.34 조각(`03_original/x86-mk-183.34/inventory/symbols.tsv`)·x86 183.34.4(`03_original/x86/inventory/symbols.tsv`)에 같은 이름이 있는지(402 밖 객체 — libcc 구성원·자료 전용 등)와 없는지(m68k 전용 후보)로 나눔.
6. 순서: contiguous 객체의 m68k 순서와 1997 i386 조각의 `text_address` 순서(§409 기록, 배치된 것만)를 비교 — 최장 증가 부분열 길이와 그 밖의 객체 목록(python).
7. 분모: `__text` 바이트를 구간 종류(대응·대응 없음)별로 합하고, 원본 `__text` 크기와 합이 같은지 assert.
8. 산출: 표 `06_reconstruction/m68k-text-map.tsv`(구간마다: 순번, 시작, 끝 상한, 바이트 상한, 대응 객체 또는 `unmapped`, 기호 수, 첫·끝 기호, 분류), 검증 기록 `09_validation/reconstruction/m2-m68k-text-map-20261009.json`.
   표 머리에 "기호 대응 후보이며 경계·소스 확정 아님" 을 적습니다. 06_reconstruction/README.md 에 이 표의 뜻을 한 문단 더합니다.
해석 규칙(미리 정함): 이름이 같다는 것은 후보일 뿐이며, 객체 확정은 L1(이미 §413·414 의 46 객체는 측정됨) 이나 이후 절의 경계 분석으로만 합니다. 07·기존 도구·x86 표는 바꾸지 않으므로 x86 회귀는 해당하지 않습니다.

### 415.1 codex 교차검토(gpt-6.1-sol, k2v3chnie) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 절 주소·크기, 기호 2,821, 대응 2,042, 구간 327·대응 없음 50·객체 250·갈라짐 13 재현 | 이번 세션 앞의 python 출력과 같음(구간 수는 도구에서 다시 assert) | ✅ |
| 402 객체의 외부 정의는 `N_SECT` 3,232 + ObjC 표시용 `N_ABS` 99 | python: 외부 `ABS` 기호 99 | ✅ 문구를 "외부 `N_SECT` 정의" 로 한정 |
| 2,821 이름이 2,815 주소; `_ALLOW_FAULT_START` 와 `_copyoutstr` 가 0x400159a 공유 | python 고유 주소 2,815; `symbols.tsv:4`·`:423` 읽음 | ✅ 주소 묶음 단위로 처리, 묶음 안 대응 객체가 하나일 때만 소유 후보 |
| 402 안에 `__text` 없는 객체 17 | python: `__text` 크기 0 이거나 없는 객체 17 | ✅ 객체 기록에 따로 표시 |
| `x86-memcpy` 가 두 번(서로 다른 소스) | §409 기록: n 6 `machdep/i386/libc/memcpy.c`, n 201 `driverkit/memcpy.c` | ✅ 객체 식별은 n 과 소스로 |
| 대응 없는 이름 중 x86 인벤토리 두 곳에 있는 것은 `__udivdi3` 뿐, `__umoddi3` 는 m68k libcc 에 있음 → "x86 에 없음" 이 "m68k 전용 소스" 가 아님 | x86 두 `symbols.tsv` 에 `__udivdi3` 있음·`__umoddi3` 없음(python); `08_build/toolchains/real-cross-20261009/fat-slices.json` 에 `umoddi3` 있음(grep) | ✅ 분류 이름을 "x86 에 이름 없음" 으로 하고 m68k 전용이라 부르지 않음 |
| `__OBJC` 절 없음은 구조 관찰일 뿐 ObjC 입력 부재의 증명 아님 | 원본 절 목록 6 개(python) | ✅ 관찰로만 기록 |
| `l2_expect-s6p398.json` 은 링크 순서가 아님; 재빌드 링크 순서는 `08_build/runs/s6p404-ln1/run.cmd:2–4`(`ld -r` 두 묶음 포함) | 그 줄 읽음(`libDriver_kern.o`·`libkobjc.o` 의 `ld -r` 과 본 `ld`) | ✅ 순서 비교를 둘로: 1997 i386 조각 주소 순서, x86 재빌드 링크 순서(묶음 펼침) |
| LIS 는 진단일 뿐이며 LIS 밖 객체가 순서 오류로 확정되지 않음, 동률 처리 결정적 | 설계 판단 | ✅ |
| 7 의 합은 "잠정 구간 분할" 이지 바이트 소유가 아님 | 설계 판단 | ✅ 이름을 바꿈 |
| 구간 표만으로는 absent·자료 전용·갈라진 객체를 못 담음 | 설계 판단 | ✅ 객체 표를 따로 둠 |

고친 산출: `06_reconstruction/m68k-text-map.tsv`(구간), `06_reconstruction/m68k-text-objects.tsv`(x86 객체 402 행: n·이름·소스·m68k 구간 수·기호 수/x86 `__text` 외부 기호 수·분류), 검증 JSON(기호·주소 묶음별 상세와 분모: 이름 수·고유 주소 수, 함수 수는 미확정으로 표시).

### 415.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-text-map-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_text_map.py`(assert: 원본 SHA, `symbols.tsv` 와 원본 기호 일치, 402 객체 SHA, 외부 정의 이름 중복 없음, 주소 묶음 안 대응 객체 충돌 없음, 첫 구간이 `__text` 시작, 구간 합 = `__text` 크기,
재빌드 링크 순서 402/402 를 SHA 로 대응). 표 `06_reconstruction/m68k-text-map.tsv`(구간 327 행)·`m68k-text-objects.tsv`(객체 402 행).

- 기호: 이름 2,821, 고유 주소 2,815(별칭 묶음 5), 대응 이름 2,042(주소 2,040), x86 에서 `__text` 밖에 정의된 이름과의 대응 0.
- 구간 327(대응 없음 50). 잠정 구간 분할 바이트(소유·커버리지 아님): 대응 435,518 B(64.19 %), 대응 없음 242,992 B(35.81 %).
  대응 없는 큰 구간은 `_snd_device_init`…(65,692 B), `_adb_initialize`…(44,776 B), `_mmmmap`…(43,596 B), FPSP 계열 `bindec`…`fpsp_unsupp`(43,268 B) 등 m68k 기계 의존·장치 코드로 보입니다(이름으로 본 관찰).
- x86 객체 402: contiguous 237, split 13, absent 88, x86 외부 `__text` 기호 없음 64(ObjC·자료 전용 등). absent 에는 ObjC 런타임(`objc_*`·`Object`·`hashtable`…)과 i386 기계 의존부, DriverKit 대부분이 들고, m68k 원본에 `__OBJC` 절이 없는 것과 맞습니다(관찰).
  split 13 은 `memmove`·`memset`·`fault_copy`·`locore`·`pcb`·`machdep`·`trap`·`km`·`pmap`·`machine_clock`·`unix_signal`·`vm_unix`·`in_bootp` — 대부분 기계 의존 이름이 m68k 의 다른 파일에 있는 경우로 보이며, 객체 경계 판단에서 따로 다룹니다.
- 대응 없는 이름 779: x86 두 인벤토리에 이름이 있는 것 1(`__udivdi3`), 없는 것 778(m68k libcc 구성원 등을 포함하므로 "m68k 전용 소스" 가 아님).
- 순서: contiguous 237 중 1997 i386 조각에 배치된 235 의 최장 증가 부분열 216, 재빌드 x86 링크 순서(묶음 펼침) 기준 237 중 217. 조각 기준 부분열 밖 19 객체는 libc 10(`memcmp`·`memcpy`·`ffs`·`index`·`str*`)과 `start`·`intr`·`i386_init`·`cons`·`mem`·`kmDevice`·`kdp_machdep`·`miniMonMachdep`·`vol` 9 이고, 링크 기준은 여기에 `unix_startup` 이 더해집니다
  — 공통부의 링크 순서는 x86 과 대부분 같고, 기계 의존부·libc 의 위치가 다릅니다(부분열 밖이 순서 오류로 확정되는 것은 아님).

판단: M2 의 객체 분할·순서 중 **공통부 객체의 m68k 위치 후보와 순서**를 얻었습니다. 남은 M2: 구간 사이 경계(정적 함수 귀속), split 13·대응 없는 50 구간의 객체 분할, `__data`·`__const`·`__cstring`·`__bss`·`__common` 의 절 배정, 함수 분모.
07·기존 도구·x86 표는 바꾸지 않았습니다.

## 416. M2-2 세부 계획 — m68k `__text` 구간 경계: 이름 없는 함수 진입점과 참조로 정적 함수를 객체에 귀속(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §415 의 구간은 끝이 상한뿐입니다. 원본 m68k 에 지역 기호가 없으므로 구간 사이의 이름 없는 코드(정적 함수)가 앞 객체 꼬리인지 뒤 객체 머리인지 정해야 경계가 섭니다.

확인한 사실(이번 세션, python, 읽기 전용):
- 원본 역어셈 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`(실기 `/bin/otool -tv`, SHA 는 §414 기록 `otool_image_listing_sha256` 과 같음): 명령 202,259 줄, 0x4000310–0x40a5d7c.
- 프롤로그(`pea a6@` + `movel sp,a6`, 또는 `linkw a6,…`) 3,342 곳, 그 앞 명령은 `rts` 3,292·`nop` 23·`bra` 13·`jmp` 8·그 밖 7(표 자료가 명령으로 풀린 경우로 보임). 외부 기호 주소는 2,815 개입니다.
- 검증 기준: §414 V10 객체 46 중 OBJECT_MATCH 34 는 l1_compare 가 `__text` 를 원본 주소에 놓고 모든 바이트·참조가 같았으므로, 그 객체의 원본 안 범위 [주소, 주소+크기) 가 정적 함수까지 포함한 실제 범위입니다(배치 43, 그중 OBJECT_MATCH 34).

방법(새 도구 `10_tools/reconstruction/m2_m68k_boundaries.py`; 입력은 원본·목록·§415 기록, SHA 대조):
1. 진입점 후보: (a) 외부 기호 주소, (b) 프롤로그 주소 중 목록상 명령 경계이고 앞 명령이 흐름 끝(`rts`·`rte`·`jmp`·`bra`)이거나 다른 진입 근거가 있는 것, (c) 호출 대상(`bsr`·`jsr` 의 절대·pc 상대 대상). 근거 종류를 진입점마다 적습니다.
2. 참조: 목록의 `bsr`·`jsr`·`pea`·`lea`·`movel #` 등에서 `__text` 안을 가리키는 값, 그리고 `__data`·`__const` 의 4 바이트(2 정렬) 값 중 진입점과 같은 것(함수 포인터). 참조하는 쪽을 §415 구간으로 바꿉니다(자료 절 참조는 "data" 로 따로).
3. 경계: §415 의 이웃한 두 구간 A·B(둘 다 대응 객체이거나 한쪽이 `unmapped`)마다, A 의 마지막 외부 기호와 B 의 첫 외부 기호 사이의 이름 없는 진입점을 참조자로 나눕니다 — A 안에서만 참조 → A, B 안에서만 → B, 둘 다·다른 구간·자료만·참조 없음 → 미정.
   A 쪽 진입점이 모두 B 쪽보다 앞이고 미정이 없으면 경계 = B 쪽 첫 진입점(없으면 B 의 첫 외부 기호) — "결정". 미정이 있으면 경계를 좁힌 구간으로 둡니다. 순서가 엇갈리면 "충돌".
4. 보조 근거(판정과 분리): 대응 x86 재빌드 객체의 함수 순서(외부·정적, 객체 기호값 순)에서 A 의 마지막 외부 함수 뒤 정적 함수 수, B 의 첫 외부 함수 앞 정적 함수 수를 적고, 3 의 결과와 수가 맞는지 표시합니다(x86 은 `-O3` 인라인 등으로 다를 수 있음, §414).
5. 검증: 34 OBJECT_MATCH 객체의 실제 시작·끝과 3 의 결정 경계를 대조합니다 — 결정된 경계가 하나라도 실제와 다르면 방법을 고치기 전까지 결과를 쓰지 않습니다. 결정 비율도 셉니다.
6. 산출: `06_reconstruction/m68k-text-boundaries.tsv`(경계마다: A·B, 구간 [하한, 상한], 결정 여부·근거, 이름 없는 진입점 수와 귀속), 진입점 목록·참조·검증은 `09_validation/reconstruction/m2-m68k-boundaries-20261009.json`.
   진입점 수(외부·이름 없음, 근거별)는 함수 분모 후보로 기록하되 확정 분모라 하지 않습니다(어셈블리 함수는 프롤로그가 없을 수 있음).
해석 규칙(미리 정함): 정적 함수는 자기 객체 밖에서 이름으로 부를 수 없으므로 "한 구간에서만 참조" 는 그 객체 소속의 강한 근거이지만, 함수 포인터가 다른 객체로 넘겨질 수 있으므로 자료 참조는 판정에 쓰지 않습니다. 07·기존 표는 바꾸지 않습니다.

### 416.1 codex 교차검토(gpt-6.1-sol, kaku2rxzp) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 202,259 은 주소 달린 목록 줄이며 `.word` 268 줄 포함 | python: `.word` 268 | ✅ "목록 줄" 로 고침 |
| 프롤로그 3,342 = `pea` 형 2,514 + `linkw` 828, 앞 명령 "그 밖" 은 6(`addql` 3·`jsr` 1·`subb` 1·`subql` 1) | python 재계산 | ✅ 내 "7" 은 틀림 — 6 으로 고침 |
| "그 밖" 이 모두 표 자료는 아님: `real_inex` 는 `addql` 뒤에 `linkw`(목록 199895–199897) | 목록 그 줄 읽음 | ✅ 해석 문구 삭제, 앞 명령이 흐름 끝이 아닌 프롤로그는 "미확인 진입" 으로 둠 |
| 외부 기호 주소 22 개가 목록 명령 경계에 없음(`_intstacks`·`_msb`·FPSP 등) — 선형 역어셈이 어긋남 | python: 22, 처음 여섯 `_intstacks`·`_msb`·`decbin`·`do_func`·`pirzrm`·`pirp` | ✅ 어긋남이 있는 창은 결정하지 않음 |
| `_start` 뒤 0 이 명령으로 풀림(목록 3), `lea` 가 가리키는 표가 명령으로 풀림(184867) | 목록 3–4·184867 읽음 | ✅ 위와 같이 처리 |
| 어셈블리 진입은 `moveml` 로 시작할 수 있음(`std_trap`, 목록 1630) | 목록 1630 읽음 | ✅ 프롤로그 없는 진입은 기호·호출 대상으로만 잡고, 그런 창은 "진입 불완전 가능" 표시 |
| `linkw` 즉치는 부호 있는 16 비트 | 설계 | ✅ 형식만 보므로 영향 없음(기록) |
| `bra`·`jmp` 대상은 꼬리 호출일 수 있으나 진입 근거로는 약함(`_ovbcopy`·`_blkclr` 의 `jmp`, 목록 1476·1478) | 목록 1474–1479 읽음 | ✅ 진입 근거로 쓰지 않고 참조로만 셈 |
| `bsr X:l` 의 값은 이미 대상 주소(목록 2186 `bsr 0x4095456:l`) | 목록 그 줄 읽음 | ✅ |
| §415 구간 좌표로 참조자를 정하면 순환 논리 | 설계 검토 | ✅ 참조자는 "참조하는 명령을 품은 함수" 로 정하고, 소유는 외부 기호(§415 이름 대응)에서 시작해 전파 |
| 정적 함수가 다른 정적 함수에서만 불리는 경우가 있어 전이 전파가 필요 | 계획 검토(예시 이름은 원본에 기호가 없어 직접 확인 못 함 — 검증은 도구의 검증 단계에서) | ⚖️ 고정점 전파 채택, 예시는 옮기지 않음 |
| 자료 절 포인터로만 쓰이는 정적 함수(`xdr_mem` 8 개)는 직접 호출이 없음 | 목록 61000(`movel #0x40af08e:l,…`) 읽음, `07_kernel/src/bsd/rpc/xdr_mem.c:37` 은 도구 검증에서 확인 | ⚖️ 자료 참조는 판정에 쓰지 않고 "자료만 참조" 로 미정 처리 |
| L1 OBJECT_MATCH 는 재빌드 범위가 그 주소에서 같다는 것이지 원본 객체 경계의 유일한 증명은 아님 | 설계 | ✅ 검증 문구를 "재빌드 범위와 일치" 로 고침 |
| 검증 집합은 좁음: 이름 없는 정적 53 개(5 객체), 정적 함수가 낀 경계 창 4 개 | 도구 검증 단계에서 다시 셈 | ⚖️ 경계 창뿐 아니라 53 개 정적 모두의 귀속을 시험(틀리면 결과를 쓰지 않음), 결정·오류·보류를 따로 셈. 새 시험 고정물(fixture)은 이번에 만들지 않음 |

고친 방법:
1'. 진입점: 외부 기호 주소(목록 경계 밖이면 "목록 어긋남"), 프롤로그(두 형식) 중 목록 경계이고 앞 명령이 `rts`·`rte`·`jmp`·`bra`·`nop` 인 것, `bsr`·`jsr` 절대 대상(목록 경계일 때). 나머지 프롤로그는 "미확인 진입" 으로 기록만.
2'. 함수 범위 = 진입점에서 다음 진입점까지. 참조자 = 참조 명령을 품은 함수. 소유 씨앗 = §415 에서 x86 객체에 대응된 외부 기호. 이름 없는 함수는 직접 참조(`bsr`·`jsr`·`pea`·`lea`·`movel #`)자 모두가 같은 소유를 가지면 그 소유를 받고, 고정점까지 반복. 자료 참조만 있으면 미정.
3'. 경계: 이웃한 구간 A·B 사이 창의 이름 없는 진입점이 모두 A 또는 B 소유이고 A 쪽이 모두 앞이며, 창 안에 `.word` 줄·목록 어긋남·미확인 진입이 없을 때만 "결정". 그 밖은 좁힌 구간과 이유.
5'. 검증(규칙은 위로 고정한 뒤 실행): 34 OBJECT_MATCH 객체의 정적 53 개의 진입 검출과 소유(같은 이름의 x86 객체), 그리고 객체 시작·끝과 결정 경계의 일치. 하나라도 틀리면 결과를 쓰지 않고 원인을 기록합니다. 결정·오류·보류 수를 따로 적습니다.

### 416.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-boundaries-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_boundaries.py`(규칙은 416.1 그대로, 검증 전에 고정). 표 `06_reconstruction/m68k-text-boundaries.tsv`(경계 326 행).

- 진입점 3,570(외부 기호 주소 2,815 + 이름 없음 755; 근거 조합별 수는 기록), 미확인 프롤로그 4, 목록 밖 외부 기호 22, `.word` 줄 268.
- 이름 없는 함수 755 의 소유: 대응 객체 163, `unmapped` 구간 136, 미정 454(그중 자료 절 참조가 있는 것 346 — 디스패치 표·콜백으로 보임), 충돌 2.
- **검증**(§414 V10 의 OBJECT_MATCH 34 객체): 이름 없는 정적 53 개 모두 진입점으로 검출, 소유 정답 20·**오답 0**·보류 33(`xdr_mem` 8 과 `nfs_server` 25 — 자료 절 표로만 쓰이거나 그런 함수에서만 불림);
  이 객체들의 시작·끝과 관련된 결정 경계 64 개 **모두 일치**. 정적 함수가 낀 창은 `netbuf` 시작·`ufs_lockf` 끝이 결정되어 일치하고, `nfs_server` 끝·`xdr_mem` 끝은 보류(결정하지 않음)였습니다.
- 경계 326: **결정 298(91.41 %)**, 그중 이름 없는 진입점이 낀 것 29. 종류별(대응↔대응 207/226, 대응↔`unmapped` 45/50, `unmapped`↔대응 46/50 결정).
  미결정 28 의 사유: 미정 진입점 23, 목록 밖 외부 기호 4, `.word` 1.
- 양 끝이 결정된 구간 286/327, 그중 대응 객체 구간 242 개 344,312 B(50.75 %) — 이 바이트는 규칙에 따른 경계이며 내용 일치(L1)를 뜻하지 않습니다.
- 진단(판정에 넣지 않음): 객체가 링크에서 연속이라는 가정으로 "A 소유 진입점 앞의 미정은 A, B 소유 뒤의 미정은 B" 를 쓰면 미결정 28 중 1 개(`nfs_server`↔`nfs_subr`, 실제 끝 0x402872e 와 같음)가 더 정해집니다.

판단: m68k `__text` 의 객체 경계는 **이름 대응 객체 사이의 대부분(91 %)이 정적 함수 귀속까지 규칙대로 정해졌고**, 검증에서 틀린 귀속·경계가 없었습니다. 보류는 자료 절 표로만 쓰이는 정적 함수가 주원인입니다.
남은 M2: 미결정 28 경계(자료 절 표의 소유를 그 표를 초기화하는 자료 객체와 함께 정하는 방법 — 별도 절), `unmapped` 50 구간 안의 객체 분할, split 13, 자료 절 배정, 함수 분모(진입점 3,570 은 후보).
07·기존 도구·x86 표는 바꾸지 않았습니다.

## 417. M2-3 세부 계획 — 자료 절 표로만 쓰이는 정적 함수의 귀속과 미결정 경계 재판정(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §416 의 미결정 경계 28 은 주로 자료 절 표(디스패치 표·콜백 표)로만 쓰이는 정적 함수 때문입니다. 정적 자료 표는 자기 객체의 코드에서 주소로 참조되므로, **표의 소유 → 표 안 함수 포인터가 가리키는 함수의 소유** 로 귀속할 수 있습니다.

확인한 사실(이번 세션, python, 읽기 전용):
- 미결정 창 안의 미정 진입점 298: 자료 참조만 251, 코드 호출만 43(미정 함수에서만 불림), 둘 다 2, 둘 다 없음 2.
- 그 진입점을 가리키는 자료 낱말 300: `__data` 286(4 바이트 정렬 158·2 바이트 정렬 128), `__const` 14. 원본 m68k 기호표의 자료 기호: section 3(`__const`) 11·4(`__data`) 363·6(`__common`) 613.
- 검증 자료: §414 V10 OBJECT_MATCH 객체 중 `__DATA,__data` 가 원본 주소에 놓인 것 12(920 B), `__TEXT,__const` 1(18 B).

방법(새 도구 `10_tools/reconstruction/m2_m68k_data_owner.py`; §416 도구의 진입점·참조·소유 계산을 함수로 가져다 씀 — §416 도구는 바꾸지 않고, 필요하면 같은 코드를 새 도구에 둠):
1. 자료 항목 시작 후보: `__data`·`__const` 의 외부 기호 주소, 그리고 코드(목록 `0x…:l` 피연산자)가 가리키는 그 절 안 주소. 낱말 w 의 항목 = w 이하의 가장 큰 시작 후보.
2. 항목 소유: 시작이 외부 기호이고 x86 재빌드 객체가 그 이름을 자료 절에 정의하면 그 객체; 그 밖(이름이 x86 에 없거나 코드 참조 시작)은 그 시작 주소를 참조하는 코드 함수들의 소유(§416 방식: 외부 함수 소유 또는 전파된 소유)가 하나일 때 그것; 아니면 미정.
3. 함수 귀속: 미정이던 이름 없는 함수 e 를 가리키는 자료 낱말들의 항목 소유가 모두 같고, e 의 코드 호출자(있으면)의 소유와도 어긋나지 않으면 그 소유. 새로 귀속된 함수로부터 §416 의 코드 참조 전파를 다시 고정점까지.
4. 경계 재판정: §416 과 같은 규칙(창의 이름 없는 진입점이 모두 A·B 로 정해지고 A 쪽이 앞, 역어셈 의심 없음).
5. 검증(규칙 고정 뒤 실행): (a) 자료 항목 소유 — V10 OBJECT_MATCH 객체의 놓인 `__data`·`__const` 범위 안 낱말 중 항목 소유가 정해진 것은 모두 그 객체여야 함, (b) §416 의 정적 53 개 — 오답 0 유지, 보류 감소 수, (c) 결정 경계와 34 객체 시작·끝 일치. 하나라도 틀리면 결과를 쓰지 않고 원인을 적습니다.
6. 산출: 새 표를 만들지 않고 `06_reconstruction/m68k-text-boundaries.tsv` 를 이 규칙의 결과로 **다시 생성**하지 않습니다 — §416 표는 그대로 두고, 새 결과는 `06_reconstruction/m68k-text-boundaries-data.tsv`(같은 열 + 근거 열)와 `09_validation/reconstruction/m2-m68k-data-owner-20261009.json` 에 둡니다.
해석 규칙(미리 정함): 코드가 가리키는 주소가 다른 항목의 안쪽(구조체 필드 등)일 수 있으므로 항목 시작 규칙은 오귀속 위험이 있습니다 — 검증 (a) 로만 신뢰를 정하고, 결과는 "규칙에 따른 귀속" 으로 적습니다.

### 417.1 codex 교차검토(gpt-6.1-sol, kncl6gf63) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 298·251/43/2/2, 자료 낱말 300(286/14), 자료 기호 11/363/613, 검증 `__data` 12(920 B)·`__const` 1(18 B) 재현 | 이번 세션 python 출력과 같음 | ✅ |
| "코드 호출만 43" 은 미정 함수에서만 불리는 것이 아님 — 35 는 그렇고 8 은 소유된 호출자도 있음(예 0x402860e), 또 호출뿐 아니라 `lea`·`pea` 참조 | §416 기록: 0x402860e 는 참조자 10·미정(호출자에 미정 함수가 섞임); 수 35/8 은 새 도구에서 다시 셈 | ⚖️ 문구를 "코드 참조만 43(소유 안 된 참조자 포함)" 으로 고침, 수는 도구 결과로 기록 |
| 검증 범위의 코드 참조 자료 주소 23 중 5 는 기호 시작이 아님(`_tcp_ttl+3`·`_tcp_mssdflt+2`·`_ripdst+4`·`_ripsrc+4`·`_ripproto+2`) | 목록 43066·43070·43072·45558·45587 읽음(`lea 0x40aeb52` 등), `symbols.tsv` 의 `_ripdst` 0x40aeb30·`_ripproto` 0x40aeb50·`_ripsrc` 0x40aeb40·`_tcp_mssdflt` 0x40aeb70·`_tcp_ttl` 0x40aeb6c | ✅ 안쪽 참조가 실제로 있음 → 코드 참조 시작은 앞·뒤 외부 자료 기호의 소유와 맞을 때만 받아들임(아래) |
| 선행 시작 찾기는 절 안으로 한정하고 첫 시작 전은 보류 | 설계 | ✅ |
| 2 바이트 간격 탐색 유지, 같은 값은 포인터 "후보" | 검증 객체에서 일치 낱말이 모두 4 바이트 재배치와 대응(codex 수치, 새 도구에서 다시 셈) | ✅ |
| 검증 객체의 함수 포인터 표: `svc_auth` 3·`xdr_mbuf` 8·`xdr_mem` 8·`af` 34·`rpc_prot` 2·`auth_kern` 5·`bootparam_xdr` 1·`nfs_server` 72 | `xdr_mem.c:37`(`static struct xdr_ops xdrmem_ops`)·`nfs_server.c:1605`(`struct rfsdisp`) 읽음; 수는 새 도구에서 재배치로 다시 셈 | ⚖️ 검증 기록에 객체별 수를 도구 출력으로 둠 |
| 보류 처리를 하는 규칙이 "모두 보류" 로 통과하지 않게 귀속·오답·보류를 따로 보고 | 설계 | ✅ |
| x86 객체로 보류 시험(held-out) | x86 은 코드 참조를 m68k otool 목록이 아니라 재배치로 얻어야 하는 다른 구현이 됨 | ⏭️ 이번에 하지 않음. 대신 V10 NOT_MATCH 객체 중 `__data` 가 원본에 놓이고 바이트·참조가 같은 8 객체(172 B)를 추가 검증으로 씀(python: `mach_factor`·`kern_acct`·`subr_kudp`·`uipc_usrreq`·`ip_icmp`·`vfs_lookup`·`vfs_dnlc`·`tcp_input`) |
| §416 의 소유 탐색은 외부 기호에서 멈추므로 새 소유가 전파되지 않음; 먼저 §416 결과를 정확히 재현하고, 자료 소유 추론과 코드 전파를 번갈아 고정점까지, 기존 귀속과 모순이면 드러낼 것 | `m2_m68k_boundaries.py` 의 `owners()` 읽음(외부 기호 `tok` 에서만 멈춤) | ✅ |

고친 방법:
1'. §416 의 진입점·참조·소유를 같은 규칙으로 다시 계산하고 §416 기록과 **진입점·소유·경계가 모두 같은지 assert**.
2'. 자료 항목 시작: 같은 절 안의 외부 자료 기호와 코드 참조 주소. 항목 소유는 외부 기호면 x86 자료 정의 객체(이름이 x86 에 없으면 그 기호를 참조하는 코드 소유), 코드 참조 시작이면 참조 코드 소유가 하나이고 그것이 **앞 또는 뒤의 가장 가까운 외부 자료 기호의 소유와 같을 때만**. 그 밖 보류.
3'. 소유 씨앗 = 외부 기호 소유 + 이미 귀속된 이름 없는 함수. 이름 없는 함수의 소유 = (코드 참조자 소유들) ∪ (가리키는 자료 낱말의 항목 소유들) 이 하나이고 미정 참조자가 없을 때. 자료 단계와 코드 단계를 바뀜 없을 때까지 반복. §416 에서 귀속된 함수의 소유가 바뀌면 모순으로 세고 결과를 쓰지 않음.
5'. 검증: (a) OBJECT_MATCH 의 놓인 자료 범위 + NOT_MATCH 8 객체의 놓인 `__data`(바이트·참조 같음) 안의 낱말 항목 소유, (b) 정적 53 의 귀속(오답 0), (c) 경계. 귀속·오답·보류 수를 따로 적고, 객체별 함수 포인터 재배치 수를 기록.

### 417.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-data-owner-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_data_owner.py`(§416 의 진입점·소유·경계를 같은 규칙으로 다시 계산해 §416 기록과 모두 같음을 assert 한 뒤 확장). 표 `06_reconstruction/m68k-text-boundaries-data.tsv`(§416 표는 그대로 둠, `decided_416` 열로 대조).

- 자료 항목 시작 후보: `__data` 876, `__const` 91. 자료·코드 전파 3 회전으로 이름 없는 함수 **218 개를 새로 귀속**(대응 객체 163 → 344, `unmapped` 구간 136 → 173, 미정 454 → 236, 충돌 2 그대로). §416 귀속과의 **모순 0**.
- 경계 결정 298 → **309/326(94.79 %)**, 새로 결정 11(`nfs_server`↔`nfs_subr` 0x402872e — 실제 끝과 같음, NFS·specfs·swapfs·ufs·`miniMon` 등), §416 결정이 바뀌거나 풀린 것 0.
  양 끝 결정 구간 301/327, 그중 대응 객체 구간 256 개 391,648 B(57.72 %, 규칙에 따른 경계이며 내용 일치 아님).
- **검증**: 자료 낱말(OBJECT_MATCH 의 놓인 `__data`·`__const` + NOT_MATCH 중 `__data` 가 바이트·참조까지 같은 객체) 555 위치 — 소유 정답 400·**오답 0**·보류 155(`__const` 9 는 모두 보류);
  정적 53 — 정답 45·**오답 0**·보류 8(`xdr_mem` 의 `xdrmem_ops` 표: 객체에 외부 자료 기호가 없어 이웃 기호 조건을 못 채움); 결정 경계 66 **모두 일치**.
  검증 객체 안 자기 `__text` 를 가리키는 자료 재배치(비 scattered): `af` 30·`nfs_server` 36·`xdr_mbuf` 8·`xdr_mem` 8·`auth_kern` 5·`rpc_prot` 2·`svc_auth` 1·`bootparam_xdr` 1.
- 미결정 17: MIG 서버 객체(`exc_server`·`mach_host_server`·`mach_port_server`·`mach_server`·`kern_server_handler` 등)의 디스패치 표, `ufs_vfsops`↔`ufs_vnodeops`, `kdp`, SCSI 주변 `unmapped`, 역어셈 의심 5.

판단: 자료 표 귀속은 검증에서 틀린 값 없이 경계를 11 개 더 정했습니다. 남은 미결정은 주로 MIG 디스패치 표(외부 자료 기호가 없는 객체의 표)입니다.
남은 M2: 미결정 17, `unmapped` 구간 분할, split 13, 자료 절 배정, 함수 분모. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 418. M2-4 세부 계획 — 자료 절이 링크 순서를 따른다는 관찰로 코드 참조 자료 항목의 소유를 넓히고 미결정 경계 재판정(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §417 의 미결정 17 중 다수는 MIG 서버 객체의 디스패치 표입니다. 이 표는 그 객체 코드가 주소로 참조하지만, 객체에 외부 자료 기호가 없어 §417 의 "이웃 외부 자료 기호와 소유가 같음" 조건을 채우지 못합니다.
예: `exc_server`↔`mach_host_server` 창의 이름 없는 진입점을 가리키는 `__data` 낱말 34 개가 0x40b005c–0x40b00e0 에 있고, 앞 외부 자료 기호는 `_pn_register_port`(0x40aff50), 뒤는 `_object_collapses`(0x40b06b8)입니다(python).

확인한 사실(이번 세션, python, 읽기 전용):
- 원본 `__data` 외부 기호 363 중 x86 재빌드 객체가 자료 절에 정의하고 그 객체가 §415 에서 `__text` 위치를 가진 것 204. 주소순으로 같은 소유를 묶으면 73 구간·73 객체이고, 그 객체들의 `__text` 첫 위치 순서의 최장 증가 부분열이 **73(전부)** 입니다 — `__data` 의 객체 배치가 `__text` 링크 순서와 같습니다(`__const` 2 구간도 같은 순서).

방법(새 도구 `10_tools/reconstruction/m2_m68k_data_order.py`; §417 도구를 가져다 쓰고 §417 결과 재현을 먼저 assert):
1. 소유 토큰의 링크 위치: 대응 객체(§415 contiguous — 구간 하나)는 그 구간의 첫 외부 기호 주소, `unmapped` 토큰은 그 구간의 첫 외부 기호 주소. split 객체는 위치 없음(이 규칙에 쓰지 않음).
2. 코드 참조 자료 시작의 소유 규칙 확장: 참조 코드 소유 O 가 하나이고(§417 과 같음), 같은 절의 앞 외부 자료 기호 소유 P·뒤 외부 자료 기호 소유 Q(없으면 절 끝)에 대해 위치(P) ≤ 위치(O) ≤ 위치(Q) 이면 O 로 받아들입니다(§417 의 O = P 또는 O = Q 조건은 이 경우의 특수형).
   P·Q 의 위치가 없거나 순서 밖이면 보류. 절 안 외부 자료 기호의 소유 순서가 위치 순서를 어기는 곳이 있으면(관찰과 다르면) 그 절에서는 이 규칙을 쓰지 않습니다.
3. 나머지(전파·경계 판정)는 §417 과 같습니다.
4. 검증(규칙 고정 뒤): §417 과 같은 자료 낱말·정적 53·경계 검증 — 오답 0 이어야 하며, 정답·보류 변화를 적습니다. 추가로 검증 객체 안에서 이 확장 규칙으로만 정해진 자료 낱말 수를 따로 셉니다(새 규칙이 실제로 시험되었는지).
5. 산출: `06_reconstruction/m68k-text-boundaries-order.tsv`, `09_validation/reconstruction/m2-m68k-data-order-20261009.json`. §416·§417 표는 그대로 둡니다.
해석 규칙(미리 정함): "자료 절이 링크 순서를 따름" 은 외부 기호 204 개에서 본 관찰이며, 이름 없는 자료 항목에 대한 가정입니다. 코드가 다른 객체 항목의 안쪽을 가리키는 경우(§417.1 의 `_ripdst+4` 등)는 O 가 P 와 같을 때만 문제가 없으므로, O 가 P·Q 사이의 다른 객체인 안쪽 참조는 이 규칙에서 오귀속이 됩니다 — 검증에서 0 이 아니면 쓰지 않습니다.

### 418.1 codex 교차검토(gpt-6.1-sol, kyvo4spa8) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 204·73 구간·73 객체·LIS 73, `__const` 2 재현, 이 소유들 중 split 객체 없음 | 이번 세션 python 출력과 같음(split 여부는 새 도구에서 assert) | ✅ |
| §417 의 대체 소유(x86 에 이름 없는 m68k 자료 기호 → 참조 코드 소유)까지 넣으면 85 구간·81 토큰·LIS 81 로 역전 3(`_scb`/`_dk_ndrive` 등) → "역전 있으면 절 전체에 쓰지 않음" 규칙이 `__data` 확장을 막음 | `symbols.tsv`: `_scb` 0x40ada14·`_dk_ndrive` 0x40adb34 확인; 역전 수는 새 도구에서 다시 셈 | ⚖️ 순서 관찰과 P·Q 는 **x86 이 직접 정의한 외부 자료 기호(위치 있는 것)만** 씀. 대체 소유는 순서 근거에서 뺌 |
| `P ≤ O ≤ Q` 는 그럴듯함 거르기일 뿐 — 다른 객체가 P 항목 안쪽을 참조하는 실례 5: `_sysent+168`(swapfs)·`_sysent+504`(trap)·`_linesw+4`(mach_server)·`_around+4`·`_inside+4`(ufs_subr) | 목록 64677(`pea 0x40adbfc`)·193440(`movel #0x40add4c`)·116282(`lea 0x40ae4b0`)·72061–72062(`lea 0x40af35e`·`0x40af33a`)와 `symbols.tsv` 기호 주소로 오프셋 확인; `ufs_tables.c:32` `int around[9]` | ✅ 이 5 곳을 **음성 시험**으로 둠 — 새 규칙이 이것들을 참조 객체 소유로 받아들이면 실패 |
| 위치가 있는 객체도 자료가 없을 수 있음(자료 없는 contiguous 객체 24) | 설계(수는 옮기지 않음) | ✅ 해석에 적음 |
| §417 의 같음 규칙은 다른 이웃이 위치가 없을 때 새 규칙의 특수형이 아님 → 따로 유지 | 설계 | ✅ §417 규칙(O = 앞/뒤 외부 자료 기호 소유)은 그대로 두고, 새 규칙은 그다음에 적용 |
| 검증 객체에서 새 규칙이 시험될 위치가 있음(`clnt_perror`·`xdr_mem`·`rpc_prot`·`auth_kern`·`bootparam_xdr`·`svc_auth`, 합 120) | 새 도구에서 "새 규칙으로만 정해진 검증 낱말" 수로 다시 셈 | ⚖️ 수는 도구 결과로 기록 |
| 보류 시험: `xdr_mbuf` 의 외부 자료 기호를 추론에서 지우고 V10 배치를 숨은 정답으로 써서 새 규칙이 되찾는지 | 설계 | ✅ 추가(재빌드 불필요) |

고친 방법:
1'. 위치: §415 contiguous 대응 객체·`unmapped` 구간 토큰의 첫 외부 기호 주소. 순서 관찰은 x86 직접 정의 외부 자료 기호만으로 절마다 확인(역전이 있는 절에는 새 규칙 미적용).
2'. 코드 참조 시작 소유: (i) §417 규칙, (ii) 아니면 같은 절에서 앞·뒤의 가장 가까운 **x86 직접 정의·위치 있는** 외부 자료 기호의 소유 P·Q 에 대해 위치(P) ≤ 위치(O) ≤ 위치(Q)(앞 기호가 없으면 위치(O) ≤ 위치(Q), 뒤가 없으면 위치(P) ≤ 위치(O)). 그 밖 보류.
4'. 검증: §417 과 같은 셋 + 새 규칙으로만 정해진 검증 낱말 수 + 음성 시험 5 + `xdr_mbuf` 보류 시험(그 객체의 x86 자료 정의 이름을 추론에서 빼고 그 객체 `__data` 낱말의 소유를 다시 구해 정답·오답·보류).

### 418.2 첫 실행의 음성 시험 실패와 규칙 수정(코딩 전 기록, 2026-10-09)

첫 실행(산출은 scratchpad 에만, 표·기록에 쓰지 않음): §417 재현 assert 통과, 검증 자료 낱말 555 모두 정답·정적 53 모두 정답·경계 68 일치, `xdr_mbuf` 보류 시험 16/16 정답이었으나,
**음성 시험 5 중 2 실패** — `_around+4`(0x40af33a)·`_inside+4`(0x40af35e)가 참조 객체 `ufs_subr` 소유 항목으로 받아들여졌습니다. `_around`·`_inside` 를 정의한 x86 객체(`ufs_tables`)는 `__text` 가 없어 위치가 없고,
2' 가 "위치 있는 직접 정의 기호" 만 P 로 고르므로 그 기호를 건너뛰고 더 앞의 기호를 P 로 써서 생긴 오귀속입니다. 미리 정한 규칙대로 이 결과는 쓰지 않습니다.

수정한 2'(좁힘): P·Q 는 같은 절에서 앞·뒤의 **가장 가까운 외부 자료 기호(종류 무관)** 이고, 각각 x86 직접 정의이면서 위치가 있어야 합니다. 어느 쪽이든 위치가 없거나(자료 전용 객체·m68k 에만 있는 이름·split) 둘 다 없으면 보류. 절 끝 쪽은 이웃이 없으면 그쪽 조건을 생략합니다.
나머지(검증 셋·음성 시험·보류 시험·해석)는 그대로이며, 이 수정은 받아들이는 경우를 줄이기만 하므로 codex 재검토 없이 진행합니다.

### 418.3 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-data-order-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_data_order.py`(§417 도구를 복사해 매개변수화; 확장을 끄면 §417 의 요약·귀속·경계를 그대로 재현함을 assert). 표 `06_reconstruction/m68k-text-boundaries-order.tsv`(§416·417 표는 그대로).

- 순서 관찰: x86 직접 정의·위치 있는 외부 자료 기호 `__data` 204·`__const` 10, 두 절 모두 링크 순서와 어긋남 없음.
- 항목 시작 받아들임: §417 규칙 11, 새 순서 규칙 12. 이름 없는 함수 새 귀속 218(§417) → **355**(대응 객체 481·`unmapped` 구간 173·미정 99·충돌 2). §416 귀속과 모순 0.
- 경계 결정 309 → **315/326(96.63 %)**; 새로 결정된 것은 `xdr_mem`↔`xdr_reference`(0x403091e — 실제 끝과 같음), `kdp`↔`kdp_udp`, MIG 서버 넷(`exc_server`·`mach_host_server`·`mach_port_server`·`mach_server` 사이). 앞서 결정된 것이 바뀌거나 풀린 것 0.
  양 끝 결정 구간 309/327, 그중 대응 객체 구간 264 개 411,978 B(60.72 %, 규칙에 따른 경계).
- **검증**: 자료 낱말 555 — 정답 529(§417 규칙 26·새 규칙 129 포함)·**오답 0**·보류 26; 정적 53 **모두 정답**; 결정 경계 68 **모두 일치**;
  음성 시험 5(`_sysent+168`·`_sysent+504`·`_linesw+4`·`_around+4`·`_inside+4`) **모두 통과**(참조 객체 소유로 받아들이지 않음); 보류 시험 `xdr_mbuf`(`_xdrmbuf_ops` 를 추론에서 지움) 16/16 정답, 다른 객체 오답 0.
- 미결정 11: 역어셈 의심 5(목록 밖 외부 기호 4·`.word` 1), 미정 진입점 6(`ufs_vfsops`↔`ufs_vnodeops`, `kern_notify`↔`kern_server_handler`, `kern_server_reply_user`↔`exc_server`, SCSI 주변 3).

판단: 첫 실행이 미리 정한 음성 시험에 걸려 규칙을 좁혔고(418.2), 좁힌 규칙은 모든 시험을 통과했습니다. m68k `__text` 구간 경계는 326 중 315 가 규칙대로 정해졌습니다.
남은 M2: 미결정 11, `unmapped` 50 구간 안의 객체 분할, split 13, 자료 절 배정(이번 순서 관찰이 출발점), 함수 분모. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 419. M2-5 세부 계획 — m68k 자료 절(`__data`·`__const`) 객체 지도, `__cstring`·`__bss`·`__common` 관찰(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: M2 끝 조건의 "절 배정". §418 에서 `__data`·`__const` 의 객체 배치가 `__text` 링크 순서와 같음을 보았으므로, 같은 방식으로 자료 절을 객체 구간으로 나눕니다.

확인한 사실(이번 세션, python, 읽기 전용; 소유는 §418 최종 소유):
- 절 형식(원본 `flags`): `__cstring` 0x2(문자열 리터럴 — 링커가 같은 문자열을 합칠 수 있음), `__const`·`__data` 0x0, `__bss`·`__common` 0x1(zero-fill).
- `__data`: 외부 기호 363(x86 직접 정의 248), 코드 참조 주소 817(참조 함수 소유가 하나 743·여럿 67). `__const`: 외부 11(직접 10), 코드 참조 91(하나 60·여럿 7). `__cstring`: 외부 0, 코드 참조 987(하나 892·여럿 21).

방법(새 도구 `10_tools/reconstruction/m2_m68k_data_map.py`; §418 도구의 `main(extend=True)` 결과를 가져다 씀):
1. 닻(anchor): (a) x86 직접 정의 외부 자료 기호(그 x86 객체 소유), (b) 코드 참조 주소 중 참조 함수 소유가 하나인 것 — 단 §418.2 와 같은 조건(앞 외부 자료 기호 소유와 같거나, 앞·뒤 가장 가까운 외부 자료 기호가 모두 x86 직접 정의·위치 있음이고 위치 사이)일 때만. 그 밖 (b) 는 버리고 이유를 셉니다.
2. 구간: 닻을 주소순으로 놓고 같은 소유끼리 묶음. 한 객체가 둘 이상의 구간으로 나오면 split 으로 표시. 위치 있는 소유들의 순서가 링크 순서와 맞는지(최장 증가 부분열) 기록.
3. 경계: 이웃 구간 A·B 사이 경계는 (A 의 마지막 닻, B 의 첫 닻] 구간값으로만 적습니다(정적·미참조 자료 항목의 크기를 모르므로 "결정" 하지 않음). 진단으로 그 객체의 x86 재빌드 `__data`·`__const` 크기를 나란히 적습니다(정렬이 달라 같지 않을 수 있음).
4. 검증(규칙 고정 뒤): §414 V10 의 원본에 놓인 자료 절(OBJECT_MATCH, 그리고 NOT_MATCH 중 바이트·참조 같음) — (i) 그 범위 안 닻은 모두 그 객체 소유, (ii) 그 객체 구간의 첫 닻 ≥ 실제 시작·마지막 닻 < 실제 끝, (iii) 이웃 경계 구간값이 실제 시작·끝을 품음. 음성 시험: §418 의 안쪽 참조 5 곳이 다른 객체 닻이 되지 않음. 하나라도 틀리면 결과를 쓰지 않습니다.
5. 관찰만(배정하지 않음): `__cstring` 은 코드 참조 소유 하나인 주소를 주소순으로 놓고 링크 순서와 맞는 비율과 소유가 여럿인 문자열 수(합쳐진 리터럴 후보); `__common` 외부 기호 613 중 x86 재빌드 객체에 COMMON 으로 있는 이름 수; `__bss` 는 기호 없음(9,420 B).
6. 산출: `06_reconstruction/m68k-data-map.tsv`(절·구간 순번·첫 닻·마지막 닻·다음 구간 첫 닻·소유·닻 수(a/b)·x86 절 크기), `09_validation/reconstruction/m2-m68k-data-map-20261009.json`.
해석 규칙(미리 정함): 자료 구간은 닻 사이 구간값이며 바이트 소유가 아닙니다. 미참조 정적 자료는 어느 쪽인지 정하지 않습니다.

### 419.1 codex 교차검토(gpt-6.1-sol, kjy8ac0ef) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 수 재현; "소유 하나" 는 참조 함수 **모두**가 같은 귀속 토큰일 때여야 하고, 미정 함수가 섞이면 미해결(`__data` 7·`__const` 24·`__cstring` 74) | §418 도구 `code_owner`(미정이 섞이면 None) 읽음; 미해결 수는 새 도구에서 다시 셈 | ✅ 그 정의를 씀(내 첫 집계는 미정 함수를 걸러 셈) |
| 목록 정규식이 `:l` 만 받아 접미사 없는 즉치(`cmpl #0x40ae71e,…` — `_unixdomain`, 목록 27506)를 놓침 | 목록 그 줄과 `symbols.tsv` 의 `_unixdomain` 0x40ae71e 확인; python: 접미사 없는 즉치가 `__text` 를 가리키는 것 173, 그중 진입점 19 — **모두 외부 기호**(이름 없는 진입점 0) | ✅ 새 도구는 두 형식을 모두 읽음. §416–418 의 이름 없는 함수 귀속은 이 누락의 영향을 받지 않음(이름 없는 진입점을 가리키는 것이 0) |
| `__bss`·`__common` 은 파일 오프셋 0 — 바이트를 읽거나 앞 `__data` 기호로 분류하지 말 것 | 원본 절 목록(offset 0) 확인 | ✅ zero-fill 절은 참조 수만 따로 셈 |
| 배열 끝 다음·음수 오프셋 참조는 다른 객체 소유일 수 있음 | 설계 | ✅ (b) 닻은 "후보 닻" 으로 표시, 검증·음성 시험으로만 신뢰 |
| `unmapped` 구간 소유는 객체 확정이 아님 | 설계 | ✅ 표에 `unmapped#k` 로 둠 |
| 자료 전용 x86 객체 17 중 11 이 직접 대응 `__data` 기호 43 을 가짐 — 이 닻을 지키고 건너뛰지 말 것 | §418.2 규칙(가장 가까운 외부 기호를 건너뛰지 않음)과 같음 | ✅ (a) 닻으로 그대로 둠(위치 없음) |
| 문구: §417 규칙은 앞·뒤 어느 이웃과 같아도 됨 | `m2_m68k_data_order.py` 의 `o in (before, after)` 읽음 | ✅ (b) 조건을 §418 의 항목 규칙(§417 + 418.2)과 같다고 고침 |
| 검증 범위: 닻 있는 `__data` 범위 20(양쪽 이웃 19)·`__const` 1, `ip_icmp` 는 닻 없음, 검증 바이트 `__data` 4.84 %·`__const` 0.64 % | 새 도구에서 다시 셈 | ⚖️ 닻 없는 범위·시험된 쪽 수·검증 바이트 비율을 기록에 둠 |
| NeXT ld 는 같은 C 문자열을 입력 객체 사이에서 합침 | `01_resources/local_mirrors/nextdev-doc/…/04_Directives.rtf:586`("The link editor merges the like literal C strings in all the input object files") 읽음 | ✅ `__cstring` 은 설명용 관찰만, 참조 주소를 담은 문자열 시작으로 정규화 |
| COMMON 이름 비교는 선언 목록일 뿐, `n_value` 는 크기 | `nlist.h:86–90` 읽음 | ✅ 이름 수만 기록 |

고친 방법: 1' 의 (b) = §418 의 항목 규칙과 같은 조건, 참조 소유는 "모든 참조 함수가 같은 귀속 토큰". 코드 참조는 `0x…:l` 과 접미사 없는 즉치를 모두 읽고 `__data`·`__const` 범위만 닻 후보(zero-fill 은 수만). 검증은 범위별 닻 수·시험된 경계 쪽 수·검증 바이트 비율과 닻 없는 범위를 함께 적습니다.

### 419.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-data-map-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_data_map.py`(§418 결과 재현 assert 후 사용). 표 `06_reconstruction/m68k-data-map.tsv`(`__data` 117·`__const` 5 구간).

- `__data`(22,552 B): 닻 771 = (a) x86 직접 정의 외부 기호 248 + (b) 523(§417 규칙 209·418.2 순서 규칙 314); 버린 것 105(m68k 에만 있는 외부 기호 52·참조 주소 53 — 소유 하나 아님 49, 규칙 불충족 56).
  구간 117·소유 116(`unmapped` 구간 7), 위치 있는 구간 105 중 링크 순서 최장 증가 부분열 104.
  순서를 벗어난 하나는 `__data` 맨 앞의 `unmapped#287`(0x40ada18·0x40adac8)로, 앞 기호 `_scb`(0x40ada14, m68k 에만 있는 이름)의 소유를 참조 코드로 대신 정한 §417 대체 규칙에서 왔습니다 — **의심 구간**(그 소유는 같은 토큰이 0x40b2baa 에 또 나와 표에 `owner_split=1`).
- `__const`(2,796 B): 닻 14(a 10·b 4), 구간 5, 링크 순서와 모두 맞음; 참조 주소 76(규칙 불충족 52·소유 하나 아님 24)과 m68k 에만 있는 외부 기호 1(소유 하나 아님)은 버림.
- **검증**: V10 자료 범위 21(`__data` 1,092 B = 4.84 %·`__const` 18 B = 0.64 %) — 범위 안 다른 소유 닻 0, 자기 닻이 범위 밖 0, 객체가 둘로 나뉨 0, 이웃 경계 구간값 40 쪽 모두 실제 경계를 품음; 닻 없는 범위 1(`ip_icmp __data` — 시험되지 않음);
  음성 시험 5 모두 닻이 되지 않음. 검증 범위가 작으므로 이 통과는 표본에서의 일관성입니다.
- 관찰: `__cstring` 참조 주소 988 → 리터럴 978(소유 하나 882·여럿 22·미해결 74), 위치 있는 소유 구간 138 의 최장 증가 부분열 135 — 링커가 같은 문자열을 합치므로(NeXT 어셈블러 설명서) 설명용입니다.
  `__common` 외부 기호 613 중 x86 COMMON 선언 이름 352(여러 객체에 선언 43), x86 에서 자료 정의 2; 코드 참조 7,558. `__bss` 기호 0, 코드 참조 1,167.

판단: `__data`·`__const` 의 객체 순서와 각 객체 자료의 닻 구간을 얻었습니다(경계는 구간값). 링크 순서를 벗어난 구간 하나는 m68k 에만 있는 기호의 대체 소유 규칙이 원인으로 보여 의심으로 둡니다.
남은 M2: 미결정 `__text` 경계 11, `unmapped` 구간 분할(m68k 전용 객체 — 자료 닻도 근거가 됨), split 13, 함수 분모. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 420. M2-6 세부 계획 — m68k 전용(대응 없는) `__text` 구간을 NeXTMach 소스 파일 후보로 나누기(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §415 의 대응 없는 50 구간(잠정 242,992 B)은 x86 짝이 없는 m68k 전용 코드(장치·기계 의존·FPSP 등)입니다. 참고 자료 NeXTMach `01_resources/upstream/nextmach/mk-108.1`(1990 년경 m68k NeXT 커널, D013 으로 열람 허용)에
같은 이름의 정의가 있으면 그 소스 파일을 객체 후보로 쓸 수 있습니다. 판(1990 ↔ 1997) 차이로 파일 구성이 다를 수 있으므로 후보일 뿐입니다.

확인한 사실(이번 세션, python·ls, 읽기 전용):
- 대응 없는 이름 778. mk-108.1 의 `.c`·`.s`·`.m`·`.h` 720 파일에서 "줄 첫머리 식별자 + `(`"(C 정의)와 `.s` 의 줄 첫머리 `_이름:` 을 정의로 보면 282 이름에 정의가 있고 그중 252 는 한 파일뿐입니다(디렉터리별 `nextdev` 161·`next` 54·`nextif` 32 등).
  정의가 없는 예: `_intstacks`, `_pflush_super`, `__switch_context`, `std_trap`, `ipl1`…`ipl7`, FPSP 레이블(`_` 없는 `.s` 레이블은 이 규칙에 안 잡힘).
- `mk-108.1/conf/files.NeXT` 79 줄(기계 의존 파일 목록, 예 `next/autoconf.c`·`next/libc.s`·`next/locore.s` 계열), `conf/files` 492 줄.

방법(새 도구 `10_tools/reconstruction/m2_m68k_unmapped.py`):
1. 정의 색인(mk-108.1 만, 다른 nextmach 꾸러미는 쓰지 않음): C·ObjC 파일 — 줄 첫머리 식별자 다음 `(`, 그 줄이 `;` 로 끝나지 않는 것(선언 제외); `.s` 파일 — 줄 첫머리 레이블 `이름:`(밑줄 유무 모두, 원본 기호와 같은 철자로 맞춤)과 `.globl 이름`. 이름마다 파일 집합. `.h` 는 색인에서 뺍니다(인라인·매크로).
2. 대응 없는 구간마다 외부 기호(주소 묶음)를 후보 파일로 표시: 한 파일이면 그 파일, 여럿이면 "모호", 없으면 "없음".
3. 하위 구간: 대응 없는 구간 안에서 같은 후보 파일이 이어지는 최대 구간. "없음"·"모호" 는 따로 둡니다(흡수하지 않음). 한 파일이 둘 이상의 하위 구간으로 나오면 표시.
4. 방법 검증(미리 정함): 같은 색인을 **대응된 이름 2,042** 에 적용해, 색인이 한 파일을 주는 이름에서 그 파일 이름(확장자 뺀 것)이 §415 의 x86 객체 소스 파일 이름과 같은 비율을 셉니다. 다른 경우는 목록으로 남깁니다(판 차이로 파일이 옮겨졌을 수 있음).
   이 비율이 낮으면(미리 정한 기준 90 % 미만) 대응 없는 구간의 후보 파일을 "약한 후보" 로 표시합니다.
5. 진단: 하위 구간의 파일 순서를 `files.NeXT`·`files` 의 등장 순서와 비교(최장 증가 부분열) — 링크 순서 근거로 쓰지 않고 관찰만.
6. 산출: `06_reconstruction/m68k-text-unmapped.tsv`(하위 구간: 시작·끝 상한·바이트·§415 구간 순번·후보 파일·기호 수·첫·끝 기호), `09_validation/reconstruction/m2-m68k-unmapped-20261009.json`(이름별 후보·방법 검증·진단).
해석 규칙: 같은 이름 정의는 1990 판 파일 후보일 뿐이며 1997 m68k 객체의 소스·경계 확정이 아닙니다. 참고 코드의 원문은 기록에 옮기지 않고 경로와 줄 번호만 적습니다.

### 420.1 교차검토(Opus 5.5 서브에이전트 — 사용자 지시로 이 세션부터 codex 대신) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 778·282·252·디렉터리 분포 재현; 720 파일에 `.m` 0, 기호 링크 1 | `find mk-108.1 -name "*.m"` 0 | ✅(나머지 수는 새 도구에서 다시 셈) |
| 사실 줄의 "정의 없음" 예 중 `_pflush_super` 는 틀림 — `next/locore.s:355` `PROCENTRY (pflush_super)`, 매크로가 `.globl _##name; _##name:`(`next/cframe.h:59–60`) | 두 곳 읽음 | ✅ 내 사실 줄 정정: `.s` 의 `PROCENTRY` 정의를 놓쳤음 |
| 같은 줄에 반환형이 있는 정의(`void swapconf(void)` `next/autoconf.c:409`)를 규칙이 놓치고, 대신 빌드되지 않는 `src/config/mkswapconf.c` 를 유일 후보로 줌 | `autoconf.c:409` 읽음 | ✅ 정의 탐지를 고침, 색인을 빌드 목록으로 한정 |
| `PROCENTRY` 사용: `next/locore.s` 27·`next/libc.s` 15·`nextdev/monitor.s` 1·`stand/misc.s` 1; `_probe_rb` 는 `locore.s:866` 인데 대충 색인이 `stand/` 를 줌 | grep 수와 `locore.s:866` 읽음 | ✅ |
| FPSP 레이블은 `fpsp/*.sa`(37 파일)에 있고 `.sa` 는 색인되지 않음; `conf/files.NeXT:79` 가 미리 만든 `fpsp/fpsp.o`, `fpsp/Makefile:15–27` 이 `.sa` 를 변환·조립하고 `TRANS`(:24, 알파벳 순) 순서로 `ld -r` | 세 곳 읽음, `ls fpsp/*.sa` 37 | ✅ `.sa` 레이블을 색인하고 `fpsp.o` 묶음으로 다룸, `TRANS` 순서 시험 추가 |
| `locore.s`·`scb.s` 는 `conf/Makefile.NeXT:59–65` 에서 이어 붙여 `locore.o`, 링크 맨 앞(`Makefile.template:142` `LDOBJS=… locore.o ${OBJS} …`) | 두 곳 읽음 | ✅ 빌드 목록에 더함 |
| `next/swapgeneric.c` 도 빌드 목록에 더할 것 | `conf/files*` 에 없음, `Makefile.template:492` `LINTFILES` 에만 나옴 | ⚖️ 빌드 근거가 lint 줄뿐이라 더하지 않음 |
| 정적 함수 같은 이름(`static busdone` `nextdev/od.c:1472`); 1990 에 static 이던 것이 1997 에 외부 기호인 경우 있음 → `static` 은 버리지 말고 표시, 충돌 시 비 static 우선 | `od.c:1472` 읽음 | ✅ |
| `.globl` 은 선언이므로 정의로 세지 말 것(`locore.s:884–886`) | 읽음 | ✅ 계획 1 의 `.globl` 을 뺌 |
| 방법 검증(대응 이름의 파일 이름 일치)은 전체 91.71 % 이나 BSD 공통부가 대부분이고 `next`·`nextdev`·`nextif` 층은 44/70 | 새 도구에서 층별로 다시 셈 | ⚖️ 층별로 보고하고 기준(90 %)은 `next`·`nextdev`·`nextif` 층에 적용. 실제 수는 도구 결과로 |
| 더 반증 가능한 시험: 파일 안 소스 순서 ↔ 주소 순서, `fpsp.o` 의 `TRANS` 순서 | 설계 | ✅ 둘 다 추가(문자열 대조는 이번에 하지 않음) |
| 대응 없는 50 구간 중 16(7,090 B)은 같은 x86 객체 구간 사이에 낌(`pmap` 6·`km` 4·`machine_clock` 2·`machdep` 2·`in_bootp` 1·`trap` 1) — "x86 짝 없는 코드" 라는 배경은 틀림 | python: 16·7,090 B·객체별 수 같음 | ✅ 배경 정정. 이 16 은 파일로 나누지 않고 "이웃 객체에 흡수될 후보" 로 표시 |
| 큰 구간 4(237·218·233·316)가 197,332 B(81.2 %) | python: 197,332 B·81.21 % | ✅ 기록 |

고친 방법:
1'. 색인 대상: `conf/files`·`conf/files.NeXT` 에 있고 실제로 있는 파일 + `next/locore.s`·`next/scb.s`(`locore.o`), `fpsp/*.sa`(`fpsp.o` 의 구성원). 정의: C 는 줄 첫머리에서 시작하는 줄에 `이름(` 이 있고 그 뒤 들여쓰기 줄(K&R 인자)만 지나 줄 첫머리 `{` 가 오는 것(반환형이 같은 줄이든 앞 줄이든), `static` 은 표시; `.s` 는 줄 첫머리 레이블과 `PROCENTRY(이름)` → `_이름`; `.sa` 는 줄 첫머리 레이블. 같은 이름이 여러 파일이면 비 static 하나만 있을 때 그것, 아니면 모호.
2'. 단위: 같은 x86 객체 구간 사이에 낀 대응 없는 구간은 "이웃 흡수 후보" 로만 표시하고 파일로 나누지 않음. 나머지 대응 없는 구간은 파일 후보로 하위 구간을 만들고, 같은 파일 사이의 "없음" 구간은 "파일 안 빈틈" 으로 표시.
3'. 검증: (i) 대응 이름 2,042 의 파일 이름 일치를 디렉터리 층별로, 기준은 `next`·`nextdev`·`nextif` 층 90 %(못 미치면 결과를 "약한 후보" 로 표시), (ii) 후보 파일마다 이름의 소스 줄 순서와 원본 주소 순서의 최장 증가 부분열, (iii) `fpsp` 하위 구간의 파일 순서가 `TRANS` 순서를 따르는지.

### 420.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-unmapped-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_unmapped.py`. 표 `06_reconstruction/m68k-text-unmapped.tsv`(하위 구간 224 행, 머리 줄에 `candidates WEAK`).

- 색인: 빌드 목록 328 파일(`.c` 286·`.s` 5·`.sa` 37 — `fpsp.sa` 1 은 `TRANS` 에 없음), 정의 이름 3,673.
- 대응 없는 이름 778 중 **후보 파일 626(80.46 %)**: `nextdev` 348·`fpsp` 147·`next` 88·`nextif` 33·`vm` 2·`bsd` 1·`kern` 1, 모호 6, 없음 152.
- 대응 없는 구간 50: **이웃 흡수 후보 16(7,090 B)**, 나머지에서 하위 구간 — 파일 후보 141·파일 안 빈틈 33·없음 30·모호 3(흡수 후보 구간의 하위 17 따로). 후보 파일 86, 둘 이상의 하위 구간에 나오는 파일 25(`fpsp` 6·`next` 8·`nextdev` 10·`nextif` 1).
- **방법 검증**(미리 정한 기준): 대응 이름에 같은 색인을 쓴 파일 이름 일치는 전체 1,251/1,373(91.11 %)이나, 기준 층 `next`·`nextdev`·`nextif` 는 **78/127(61.42 %) < 90 %** → 규칙대로 이번 후보 전체를 **약한 후보** 로 표시합니다.
  층별: `bsd` 99.35 %·`netinet`·`nfs`·`ufs` 100 % 와 달리 `kern` 74.12 %·`next` 59.38 %·`nextdev` 65.52 %. 비교 기준이 1997 **i386** 파일 구성이라 m68k 기계 의존부에서는 기준 자체가 약합니다(검토 지적과 같음).
- 반증 가능한 시험: 후보 파일 66 개 중 60 개는 소스 줄 순서가 원본 주소 순서와 완전히 같고, 600 이름 중 최장 증가 부분열 밖 16(2.67 %).
  `fpsp` 하위 구간의 구성원 순서는 36 구성원 모두 `fpsp/Makefile:24` 의 `TRANS` 순서를 따릅니다(구성원 구간 44 — 같은 파일이 두 번 이상 나오는 것은 1990 ↔ 1997 FPSP 판 차이 후보, 검토 지적).

판단: NeXTMach 이름 정의로 m68k 전용 구간의 78 % 이상 이름에 파일 후보가 붙었고, 파일 안 순서·FPSP 링크 순서 시험은 후보와 잘 맞습니다. 그러나 미리 정한 파일 이름 일치 기준을 기계 의존 층에서 못 넘었으므로 결과는 "약한 후보" 입니다.
이웃 흡수 후보 16 은 §416–418 방식(이름 없는 진입점·참조)으로 이웃 객체와 함께 다뤄야 합니다. 남은 M2: 미결정 `__text` 경계 11, 흡수 후보 16, split 13, 함수 분모. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 421. M2-7 세부 계획 — 갈라진 x86 객체 13 과 이웃 흡수 후보 16 을 NeXTMach 파일 단위로 다시 묶기(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §415 의 split 13 객체(`locore`·`pmap`·`machdep`·`km`·`machine_clock`·`fault_copy` 등)와 §420 의 이웃 흡수 후보 16 구간은 대부분 같은 곳에 있습니다. §420 색인으로 구간마다 이름의 NeXTMach 후보 파일을 보면(python, 이번 세션),
기계 의존부는 x86 객체가 아니라 1990 파일 단위로 이어집니다 — 예: 구간 219–231 은 대응·대응 없음이 번갈아 나오지만 이름은 모두 `nextdev/km.c`(x86 `kmDevice` 이름 하나 포함), 291–305 는 모두 `next/pmap.c`, 3–13 은 `next/locore.s`(x86 `fault_copy`·`locore`·`memmove`·`memset`·`pcb` 이름 포함),
211–214 는 `vm/vm_unix.c`(x86 `fault_copy` 이름 포함), 274–284 는 `next/machdep.c`(x86 `unix_signal` 이름 포함), 238–240 은 `nextif/in_bootp.c`. 반대로 x86 `memmove`·`memset` 은 `locore.s` 쪽과 `next/libc.s` 쪽(259–262)에 나뉩니다.

방법(새 도구 `10_tools/reconstruction/m2_m68k_regroup.py`; §415 기록·§420 색인 함수 사용):
1. 구간 서명: 구간 이름들의 §420 후보 파일 집합(없음·모호 제외).
2. 재묶음 대상 구간: 대응 없는 구간, split 객체 구간, 그리고 서명 파일의 이름(확장자 뺀 것)이 그 x86 객체 소스 이름과 다른 대응 구간. 그 밖(파일 이름이 같은 대응 구간 등)은 그대로 둡니다.
3. 묶음: 주소순으로 서명이 같은 한 파일 F 인 구간이 이어지면(재묶음 대상이 하나 이상 포함) 한 묶음 "F" 로 합칩니다. 서명이 빈 구간(이름이 모두 없음)은 앞뒤가 같은 F 일 때만 그 묶음 안에 넣고 "빈틈" 으로 표시합니다. 서명이 두 파일 이상인 구간은 묶지 않습니다.
4. 시험(미리 정함): (a) 같은 F 가 두 묶음 이상에 나오면 표시(링크에서 객체는 연속이므로 모순 후보), (b) 묶음 안 이름의 F 소스 줄 순서 ↔ 주소 순서 최장 증가 부분열, (c) 묶음 경계가 §418 결정 경계와 겹치는지 — 묶음 안쪽의 결정 경계는 "객체 안쪽" 으로 바뀌고, 묶음 바깥 경계 중 미결정인 것을 셉니다.
5. 산출: `06_reconstruction/m68k-text-regroup.tsv`(묶음: F, 첫·마지막 구간 순번, 시작, 끝 상한, 바이트, 포함된 x86 객체 이름들, 대응 없는 구간 수, 빈틈 수, 시험 결과), `09_validation/reconstruction/m2-m68k-regroup-20261009.json`.
해석 규칙(미리 정함): §420 의 파일 후보가 "약한 후보" 이므로 이 묶음도 후보입니다. 근거는 (1) 링크에서 객체가 연속이라는 것, (2) 양쪽 이름이 같은 1990 파일에 정의되어 있다는 것, (3) 파일 안 순서 일치입니다. x86 객체 이름은 바꾸지 않고, 묶음은 "m68k 객체 후보" 로만 적습니다.

### 421.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 배경 예의 범위가 계획 자신의 규칙과 맞지 않음: 231 은 km 9 + `_mmopen`(`next/mem.c`) 두 파일, 274 는 세 파일(`machargs.c`·`machdep.c`·`kern/thread.c`), 13 은 `locore.s` + `fpsp/skeleton.sa`, 12(x86 `pcb`)는 정의 없는 `_call_continuation` 하나 | 이번 세션 앞의 구간별 파일 출력(231·274·13·12 줄)과 같음 | ✅ 배경 문구가 과했음. 규칙을 구간이 아니라 **주소 묶음(기호) 단위**로 바꿔 가장자리 이름에서 자름 |
| `pcb` 이름이 `locore.s` 라는 내 배경은 근거 없음 | 위와 같음 | ✅ 정정 |
| `_ovbcopy`·`_blkclr` 는 `_bcopy`·`_bzero` 로 뛰는 6·10 B 별칭 조각이라 memmove·memset 의 "갈라짐" 은 별칭 탓 | §416 이 본 목록 1476–1478(`jmp 0x4092d2c`·`jmp 0x4092e12`) | ✅ 기록 |
| `m2_m68k_unmapped.py` 가 x86 객체를 이름으로 열쇠 삼아 `x86-memcpy`(n 6·n 201 두 행)에서 뒤 행이 이김 → §420 기록의 불일치 목록 경로 하나가 틀림 | 도구 99 행 `objsrc = {r['x86_object']: …}` 읽음(검토가 든 120·125 행은 틀림), 두 행의 소스 이름 줄기는 모두 `memcpy` 라 층별 수는 같음 | ✅ §420 도구를 n 열쇠로 고치고 다시 생성해 요약이 같은지 확인. 새 도구도 n 열쇠 |
| 같은 1990 파일 ≠ 한 1997 객체: x86 1997 자체가 `machdep`→`machdep`·`unix_startup`·`unix_signal`, `km`→`km`·`kmDevice` 로 나뉨 | §415 객체 표(그 이름들이 각각 별도 x86 객체) | ✅ 연속(non-split)인 서로 다른 x86 객체는 파일 증거만으로 합치지 않음 |
| "소스 이름이 다름" 을 대상 조건으로 쓰면 바이트로 증명된 `pmap_krmt`(OBJECT_MATCH) 같은 공통부까지 대상이 됨 | §416 검증 목록에 `x86-pmap_krmt` 있음 | ✅ 그 조건을 뺌 — 대상은 대응 없는 구간과 split 객체 구간만 |
| x86 객체로 감싸인(같은 객체 구간 사이) 대응 없는 구간은 그 객체로 — 파일 증거보다 강함(`machine_clock` 246·248, `trap` 310) | §420 흡수 후보 16 과 같은 근거 | ✅ 1 순위 규칙으로 |
| 어셈블리 프롤로그 지문: `linkw a6,#0x0` 37 곳이 모두 외부 기호 주소이고 구간 2·3·4·7·13·233·254·257–271(264 제외)에만 있음; NeXTMach 매크로가 `link a6,#0`(`next/cframe.h:34`·48–49·69), C 는 `pea a6@` 또는 음수 `linkw` | python: 37·37·같은 구간 목록; `cframe.h` 그 줄 읽음 | ✅ 시험으로 추가(.s/.sa 묶음 안 C 프롤로그 외부 함수, .c 묶음 안 어셈블리 프롤로그를 모순으로 셈) |
| 구간 257 앞부분 `_kpmon_null`…은 C 프롤로그라 `libc.s` 에 합치면 566 B 잘못 흡수 | 위 시험에 걸림(도구에서 셈) | ✅ |
| `_bcmp`·`_ffs`·`_strlen` 의 `bsd/subr_xxx.c` 정의는 `#if BALANCE \|\| NeXT \|\| vax` 의 `#else` 쪽(169·171·184·195 행) — NeXT 에서 컴파일 안 됨 | awk 로 그 범위의 지시문·정의 줄 확인 | ⚖️ 일반 전처리는 하지 않고, 이 세 이름만 "NeXT 에서 빠지는 정의" 로 표시해 `next/libc.s` 로 해석 |
| 시험 (b)(파일 안 순서)는 잘못 합친 것을 못 잡음, (c)(§418 결정 경계)는 정적 함수 배치일 뿐 | 설계 | ✅ (b)(c)는 일관성 기록으로만 |
| 정적 함수 다리: §416 충돌 진입점 0x4096fd0·0x40970c6 은 여러 pmap 구간의 외부 함수가 부름 → 그 구간들이 한 객체라는 양성 근거 | §416 기록에 두 진입점 `conflict` 있음(앞서 확인), 호출자 구간은 새 도구에서 셈 | ✅ 시험 (d)로 추가 |
| 그룹마다 근거 등급(x86 감쌈·정적 다리·프롤로그 지문·파일만)을 적을 것 | 설계 | ✅ |

고친 방법:
1'. 단위는 주소 묶음. 각 묶음의 후보 파일(`_bcmp`·`_ffs`·`_strlen` 은 위 조건부 정의를 빼고 해석).
2'. 대상: 대응 없는 구간의 묶음과 split x86 객체 구간의 묶음. 연속 x86 객체의 묶음은 대상이 아니고 경계를 넘지 않음(묶음의 끝을 막음).
3'. 1 순위 — x86 감쌈: 같은 x86 객체 X 의 구간 사이에 있는 대상 묶음은 X 의 후보(근거 "bracket").
   2 순위 — 파일: 감싸이지 않은 대상 묶음이 같은 파일 F 로 이어지면 묶음 "F"(근거 "file"); 정의 없는 묶음은 앞뒤가 같은 F 일 때만 빈틈으로. 묶음 끝은 다른 파일·연속 x86 객체·두 파일 이상인 묶음에서 끊김.
4'. 시험: (a) 같은 F 가 둘 이상의 묶음에 나오면 표시(인접은 "가장자리", 떨어진 것은 "옮겨진 이름"), (b) 파일 안 순서(기록), (c) §418 결정 경계(기록), (d) 정적 다리 — §416/418 에서 소유 충돌인 이름 없는 진입점의 외부 호출자들이 한 묶음 안이면 양성, 여러 묶음이면 표시,
   (e) 프롤로그 지문 — `.s`·`.sa` 묶음 안 외부 함수가 C 프롤로그거나 `.c` 묶음 안에 `linkw a6,#0x0` 진입이 있으면 모순. 묶음마다 근거 등급과 바이트(감쌈·파일만)를 적음. 모순이 있는 묶음은 표에 표시하고 결론에서 뺌.

### 421.2 첫 실행에서 드러난 시험 (e) 정의 오류와 수정(기록 후 재실행, 2026-10-09)

첫 실행(scratchpad 에만)에서 (e) 가 `fpsp/*.sa` 묶음 8 개와 `next/locore.s` 묶음 하나에 "C 프롤로그" 모순을 냈습니다. 원인은 시험 정의입니다: 음수 `linkw a6,#…` 를 C 로 셌으나, `fpsp/*.sa` 원문은 `link a6,#-LOCAL_SIZE` 를 17 곳에서 씁니다(grep). 어셈블리도 음수 `link` 를 쓰므로 그것은 판별 근거가 아닙니다.
수정한 (e): 어셈블리 표지 = `linkw a6,#0x0`(NeXTMach `PROCENTRY` 매크로), C 표지 = `pea a6@` + `movel sp,a6`(GCC 의 빈 프레임), 음수 `linkw` 는 중립. `.s`·`.sa` 묶음 안 외부 함수의 C 표지, `.c` 묶음·x86 감쌈 묶음 안 어셈블리 표지를 모순으로 셉니다.
이 수정은 시험을 결과에 맞춘 것이 아니라 원문 근거로 정의를 고친 것이며, 첫 실행의 모순 목록은 기록에 남깁니다.

### 421.3 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-regroup-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_regroup.py`(§420 도구는 n 열쇠로 고쳐 다시 생성 — 요약·이름별 결과·표 동일, 불일치 목록의 `_bcopy` 경로만 `machdep/i386/libc/memcpy.c` 로 바로잡힘). 표 `06_reconstruction/m68k-text-regroup.tsv`(묶음 110).

- 대상 주소 묶음 903(대응 없는 구간 + split 객체): x86 감쌈 65·파일 742·남음 96. 대응 없는 구간 바이트 242,992 중 파일 묶음 202,102(83.17 %)·감쌈 5,488(2.26 %)·남음 35,402(14.57 %).
- **x86 감쌈으로 다시 합쳐진 split 객체 4**: `in_bootp`(238–240), `machine_clock`(245–249), `pmap`(292–304), `trap`(309–311). 나머지 split 9 는 파일 묶음으로 갈라집니다 —
  `memmove`·`memset` 은 `locore.s` 쪽 별칭 조각(`_ovbcopy`·`_blkclr`)과 `libc.s` 쪽, `fault_copy` 는 `locore.s` 와 `vm/vm_unix.c`, `locore`·`pcb` 는 `locore.s`(`pcb` 는 정의 없는 이름이 빈틈으로 들어감)·`next/pcb.c`, `machdep`·`unix_signal` 은 `next/machdep.c`(두 묶음)·`next_table.c`, `km` 은 x86 연속 객체 `kmDevice` 에서 끊겨 `nextdev/km.c` 두 묶음.
- 시험: (a) 둘 이상의 묶음에 나오는 파일 12(대부분 이웃한 묶음 — 연속 x86 객체·다른 파일 묶음에서 끊긴 것, `fpsp` 5 는 §420 의 판 차이 후보와 같음); (b) 파일 안 순서 — 최장 증가 부분열 밖 5;
  (c) 묶음 안쪽 §418 경계는 모두 결정된 것(기록); (d) **정적 다리**: 소유 충돌 진입점 0x4096fd0·0x40970c6 은 `next/pmap.c` 파일 묶음(구간 291) 안에 있고 외부 호출자 3 개씩은 모두 x86 `pmap` 감쌈 묶음 안 — 291 이 `pmap` 과 한 객체라는 양성 근거(자동으로 합치지는 않음);
  (e) 프롤로그 지문(421.2 수정 정의) 모순 **0**.
- 근거 등급: 감쌈 묶음 4(12,484 B, 그중 `pmap` 은 정적 다리 추가), 파일 묶음 106(212,938 B — §420 의 약한 후보에 기댐, `.s`·`.sa` 묶음 일부는 어셈블리 표지가 추가 근거).

판단: split 13 중 4 는 x86 감쌈으로 한 객체 후보가 되었고, 9 는 m68k 에서 다른 1990 파일들(특히 `locore.s`·`libc.s`·`machdep.c`)에 나뉘어 들어 있음이 이름·순서·프롤로그로 일관되게 보입니다. 파일 묶음은 약한 후보이며, `pmap` 의 291 처럼 정적 다리가 가리키는 합침은 다음 단계에서 다룹니다.
남은 M2: 미결정 `__text` 경계 11, 남은 대상 묶음 96(35,402 B), 정적 다리 1 건(291↔`pmap`)의 반영, 함수 분모. 07·x86 표는 바꾸지 않았습니다.

## 422. M2-8 세부 계획 — m68k 원본 안의 libcc 구성원 후보를 L1 로 판정(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §421 뒤 남은 대상 묶음 96(36,318 B — 묶음 다음 주소까지) 중에 `__ashldi3`·`__lshrdi3`·`__udivdi3`·`__umoddi3` 같은 컴파일러 런타임 이름이 있습니다. x86 에서는 `-lcc` 구성원이 등급 L(D051, `objects_toolchain.tsv`)로 바이트 판정되었습니다.

확인한 사실(이번 세션, python, 읽기 전용):
- `03_original/x86/userland/binaries/lib/libcc.a`(SHA `bccd689e…`, §409 에서 실기 `/lib/libcc.a` 와 같음)는 fat 3 조각이고 m68k 조각(cputype 6, 오프셋 68, 24,256 B)은 `!<arch>` 아카이브 47 구성원(`__.SYMDEF SORTED` 포함)입니다.
- 구성원의 외부 `__text` 기호가 원본 m68k `__text` 에 있는 것은 4: `_ashldi3.o`(`__ashldi3` 0x4090d00), `_lshrdi3.o`(`__lshrdi3` 0x4093146), `_udivdi3.o`(`__udivdi3` 0x409aa2e), `_umoddi3.o`(`__umoddi3` 0x409aa92).
  이들은 §415 의 대응 없는 구간 242·272·314 에 있고, 같은 구간에 `__bdiv`·`__lshldi3` 처럼 libcc 에 없는 이름이 섞여 있으며, 위치가 `__text` 끝이 아니라 중간입니다(x86 원본은 libcc 가 링크 끝).

방법(새 도구 `10_tools/reconstruction/m2_m68k_libcc.py`):
1. libcc.a 의 SHA 를 대조하고 m68k 조각의 구성원을 무시 대상 `08_build/artifacts/m2p422/libcc-m68k/` 에 풀어 둠(구성원 SHA 목록). 아카이브 머리(이름·크기)와 `#1/N` 긴 이름을 처리.
2. 위 4 구성원을 `l1_compare.py --image 03_original/m68k/binaries/mach_kernel --obj … --place-from-image` 로 비교. 함수·절 판정과 배치 주소를 기록.
3. 해석(미리 정함): OBJECT_MATCH 이면 그 구성원의 원본 범위가 그 구성원과 바이트까지 같다는 판정(x86 등급 L 과 같은 뜻 — 소스 컴파일이 아니라 라이브러리 구성원이 링크된 것과 일치). NOT_MATCH 이면 같은 이름의 다른 구현(커널 자체 소스 등)일 수 있음을 적고 결론 내지 않음.
   위치가 링크 끝이 아닌 것은 따로 적고, 같은 구간의 `__bdiv`·`__lshldi3` 의 출처는 정하지 않음.
4. 산출: `06_reconstruction/m68k-objects-toolchain.tsv`(구성원·SHA·판정·원본 범위), `09_validation/reconstruction/m2-m68k-libcc-20261009.json`.

### 422.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| fat·아카이브(47 구성원, 첫째 `__.SYMDEF SORTED`, 긴 이름 없음, 크기 모두 짝수)·4 구성원·구간 242/272/314 재현 | 이번 세션 python 출력과 같음(채움·긴 이름은 도구에서 assert) | ✅ |
| 4 구성원 모두 L1 NOT_MATCH(검토자가 scratch 에서 실행) | 판정 근거로 쓰지 않음 — 이 절의 도구로 직접 실행해 확인 | ⏭️→ 도구 결과로 대체 |
| 원본의 `__ashldi3` 는 이동 수를 `a6@(0x14)` 에서 읽음(libcc 는 0x10) — 다른 인자 꼴 | 원본 목록 181892 `movel a6@(0x14:w),d4` 읽음; libcc 쪽 값은 도구가 풀어 기록 | ✅(원본 쪽) |
| 원본의 `__udivdi3`·`__umoddi3` 는 `__bdiv`(0x4090d4c)를 부름; libcc 구성원은 재배치 0(나눗셈 함수 안에 펼쳐짐) | 원본 목록 194207 `bsr 0x4090d4c:l` 읽음; 구성원 재배치 수는 도구에서 셈 | ✅ |
| 원본 크기: 두 나눗셈 함수가 다음 기호까지 100 B 씩, libcc 구성원 `__text` 202·256 B | `symbols.tsv` 의 0x409aa2e·0x409aa92 와 다음 기호로 셈(도구에서 python) | ✅ 도구에서 기록 |
| libcc 의 `___clz_tab`(256 B, `__const`)은 원본 어디에도 없음; `--place-from-image` 만으로는 원본에 지역 기호가 없어 `__const` 를 놓을 수 없음 | 도구에서 원본 전체 바이트 검색으로 확인 | ✅ 검색을 도구에 넣음. L1 은 그대로 돌리되 `--ranges`(원본 기호 경계) 판도 함께 돌림 |
| `__bdiv`·`__lshldi3` 는 libcc 어느 조각에도 없고 mk-108.1 에 관련 이름 정의 0 | `grep -rlE "bdiv\|lshldi3\|ashldi3\|udivdi3\|umoddi3" mk-108.1` 빈 출력 | ✅ |
| mk-108.1 은 `LIBS=` 비어 있고(`conf/Makefile.NeXT:44`) 링크 줄 끝에 `${LIBS}`(`Makefile.template:289`) — 라이브러리는 끝; 세 쌍이 세 곳에 떨어져 있는 것은 `-lcc` 끌어오기와 맞지 않음 | 두 줄 읽음, 세 구간 위치(§415 표) | ✅ 해석에 적음(1997 m68k Makefile 은 없어 추론) |
| 해석 규칙 강화: 크기·`__bdiv` 호출·인자 위치·`__clz_tab` 부재는 "다른 구현" 의 양성 근거 | 위 확인 | ✅ |
| `m68k-objects-toolchain.tsv` 를 등급 L 표로 만들지 말 것 | 설계 | ✅ 표를 만들지 않고 검증 기록에만 둠 |
| `System.m68k`·libsys 의 "GNU library" 와 비교 | 위치 확인 안 함 | ⏭️ 이번 범위 밖 |

고친 방법: 2' 는 `--place-from-image` 판과, 원본 외부 기호 경계로 함수 범위를 준 판을 모두 기록하고, `___clz_tab` 바이트 열과 각 구성원 `__text` 앞 24 B 를 원본 전체에서 찾습니다. 3' 판정: NOT_MATCH 이고 위 양성 차이가 확인되면 "libcc 구성원 아님(다른 구현)" 으로 적고, 세 구간은 출처 미상 커널 객체 후보(쌍 셋)로 둡니다. 4' 표는 만들지 않습니다.

### 422.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-libcc-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_libcc.py`(구성원은 무시 대상 `08_build/artifacts/m2p422/libcc-m68k/`, 47 개 SHA 목록은 기록에).

- 4 구성원 모두 **NOT_MATCH**(`--place-from-image` 판·원본 기호 경계 `--ranges` 판 같음). `__text` 바이트 차이: `__ashldi3` 13/76, `__lshrdi3` 13/76, `__udivdi3` 184, `__umoddi3` 241.
- 크기: 두 이동 함수는 76 B 로 같고, 두 나눗셈 함수는 구성원 202·256 B ↔ 원본 다음 기호까지 100 B. 구성원은 재배치 0·미정의 기호 0(나눗셈이 함수 안에 펼쳐짐)인데 원본의 두 나눗셈 함수는 `__bdiv`(0x4090d4c)를 부릅니다(목록 194207).
- 구성원의 `___clz_tab`(256 B)은 원본 전체에서 0 회, 각 구성원 `__text` 앞 24 B 도 원본에서 0 회 나옵니다. 원본 `__ashldi3` 는 이동 수를 `a6@(0x14)` 에서 읽습니다(목록 181892).

판단(미리 정한 규칙 3'): 원본의 `__ashldi3`·`__lshrdi3`·`__udivdi3`·`__umoddi3` 는 **보관된 libcc 구성원이 아닌 다른 구현**입니다. 세 구간(242 `__ashldi3`+`__bdiv`, 272 `__lshldi3`+`__lshrdi3`, 314 `__udivdi3`+`__umoddi3`)은 서로 떨어져 있고 mk-108.1 은 라이브러리를 링크 끝에 둡니다(`conf/Makefile.NeXT:44`·`Makefile.template:289`) —
`-lcc` 로 끌려온 것이 아니라 출처 미상인 커널 객체 후보(쌍 셋)로 둡니다(참고 소스 없음: mk-108.1 에 이 이름 정의 0). 등급 L 표는 만들지 않았습니다. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 423. M2-9 세부 계획 — m68k 객체 후보 목록 통합과 분모(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: 기준 문서 M2 끝 조건 "객체 분할·순서·절 배정 목록, 분모(함수 수·바이트 수)가 python 으로 확정". §415–422 의 결과가 여러 표에 흩어져 있어 하나의 m68k 객체 후보 목록으로 모읍니다. 새 판정은 하지 않고, 앞 절들의 결과만 규칙대로 합칩니다.

입력(모두 SHA 대조): §415 기록(주소 묶음·소유·객체 분류), §418 기록(경계 326: 결정·하한·상한)과 §418 도구의 최종 소유(이름 없는 진입점 755), §421 기록(묶음 110: 종류·범위), §419 기록(`__data`·`__const` 구간), §422 기록(libcc 아님 판정).

방법(새 도구 `10_tools/reconstruction/m2_m68k_objects.py`):
1. 주소 묶음 이름표: §421 묶음에 든 묶음은 그 묶음(종류 `x86`(감쌈)·`file`), 그 밖에 연속 x86 객체 소유는 그 객체(종류 `x86-name`), 나머지(§421 이 남긴 대상 묶음)는 `unassigned`. 이름표가 같은 이웃 묶음을 이어 객체 후보로 만듭니다(`unassigned` 는 이어진 것끼리 하나).
2. 객체 시작: 앞 객체와의 경계가 §415 구간 경계와 같은 자리이면 §418 경계(결정이면 그 주소 — 앞에 정적 함수가 붙으면 첫 외부 기호보다 앞; 미결정이면 [하한, 상한]); 구간 안쪽에서 나뉜 자리(§421 이 주소 묶음 단위로 자른 곳)는 (앞 묶음 주소, 그 묶음 주소] 구간값. 끝은 다음 객체의 시작. 첫 객체는 `__text` 시작, 마지막은 `__text` 끝.
3. 분모: 객체 수(종류별), `__text` 바이트 — 양 끝이 정확한 객체의 바이트 합과 구간값이 있는 객체의 바이트 범위(최소·최대), 진입점 3,570(외부 2,815 + 이름 없음 755)을 정확한 범위로 객체에 나누고 구간값 창 안의 진입점은 따로 셈. 진입점은 "함수 후보" 이며 함수 확정 분모가 아님을 적음.
4. 절 배정: §419 `__data`·`__const` 구간의 소유를 객체에 연결(x86 이름 → 그 이름표의 객체; `unmapped#k` → §415 구간 k 의 묶음이 속한 객체가 하나일 때만, 여럿이면 표시). 연결되지 않은 자료 구간 수를 셈.
5. 검증(미리 정함): (a) 객체들이 `__text` 를 빈틈·겹침 없이 덮음(구간값은 최소·최대 모두), (b) §416·418 검증 34 객체(OBJECT_MATCH)의 실제 범위가 통합 목록의 같은 이름 객체 범위와 같음(양 끝이 정확한 경우), (c) 진입점 합 = 3,570, (d) §421 묶음과 연속 x86 객체 수가 입력과 맞음.
6. 산출: `06_reconstruction/m68k-objects.tsv`(id `m68k-NNN`, 순번, 이름표, 종류·근거, 시작·끝(정확/구간), 바이트(최소·최대), 외부 기호 수, 이름 없는 진입점 수, `__data`·`__const` 구간 수, 비고), `09_validation/reconstruction/m2-m68k-objects-20261009.json`.
해석 규칙: 이 목록은 M2 의 "후보 목록" 이며 `file` 종류는 약한 후보(§420), 경계는 규칙에 따른 것입니다. 소스·내용 일치(L1)는 M3 이후의 일입니다.

### 423.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 이름표 규칙은 입력과 맞음(묶음끼리 겹침 0, 묶음 안 연속 객체 소유 0, 이름표 수 x86 1,912·file 742·감쌈 65·unassigned 96 = 2,815); 같은 파일 이름표가 여러 이음에 나오므로 객체는 이름이 아니라 이음 단위 열쇠로 | §421 결과(65·742·96)와 같은 수; 나머지는 도구에서 assert | ✅ 이음 단위 열쇠, 묶음 둘이 한 이음에 합쳐지면 assert 실패 |
| 섞인 unassigned 이음(`unix_signal` 남은 묶음 + 구간 287)을 한 객체로 내놓지 말 것 | 설계 | ✅ unassigned 는 §415 구간마다 따로, 객체 수와 따로 보고 |
| 플래그가 있는 미결정 경계 5(k = 0·1·263·264 목록 밖 외부 기호, 315 `.word`)는 하한 = 상한이라 "[하한, 상한]" 규칙이 정확한 경계로 만들어 버림 | §418 기록 python: 그 다섯이 정확히 그 플래그로 나옴 | ✅ 플래그 경계는 (A 마지막 외부 기호, B 첫 외부 기호] 구간값 |
| 앞 정적 함수가 붙은 결정 경계 25(상한 < B 첫 기호) — 상한을 쓰는 것이 맞음 | python: 25 | ✅ |
| 구간 안쪽 경계 104 에 §416 규칙을 쓰지 않으면 창에 이름 없는 진입점이 없는 61 개도 구간값이 됨 | 설계 — §416 규칙(창 안 이름 없는 진입점 0, 역어셈 의심 없음 → 다음 묶음 주소에서 결정)을 그대로 적용 | ✅ 수는 도구에서 셈 |
| 검증 (a) 는 그대로면 구조상 실패(구간값 최소·최대) → 경계 단조, 처음·끝이 `__text` 처음·끝, Σ정확 + Σ최소 + Σ창 = 678,510 으로 | 설계 | ✅ |
| 검증 (b) 는 §418 의 경계 68 대조를 되풀이할 뿐(34 객체 모두 연속 객체·양 끝 결정) | 설계 | ✅ assert 로만 두고 "새 시험 아님" 으로 적음 |
| 추가 검사: 이름 없는 진입점의 §418 소유가 그 객체의 최대 범위 안에 있는지(분할 객체 소유 3 중 1 위반 = §421 정적 다리 0x4096f96) | 도구에서 셈 | ✅ 추가, 위반은 기록 |
| IDA 내보내기 `05_ida/exports/m68k/initial-functions.json`(함수 시작 3,214)과 진입점 대조(진단) | 파일 읽음: 목록 3,214 개 | ✅ 진단으로만(IDA 판단은 근거 아님) |
| 자료 연결: 122 중 106 연결; 자료 전용 x86 객체 11 의 구간, `x86-VGAConsole`(m68k 에 없음, `_ohlfs12` 이름 충돌 의심), 여러 이음에 걸친 `unmapped#k` 4 는 연결 안 됨; §419 의심(`unmapped#287`) 표시를 넘길 것 | 도구에서 셈 | ✅ 자료 전용 객체를 `__text` 없는 행으로 넣고, 의심 표시를 넘김 |
| M2 끝 조건에 빠진 것: 함수 분모, 자료 전용 객체, `__cstring`·`__bss`·`__common` 배정 가능 여부, ObjC 확인, 291↔pmap 다리 | 기준 문서 130–135·154 행 읽음 | ✅ 각각 다룸(아래). 함수 분모는 §4 규칙상 "진입점 후보" 이며 M2 는 그 점에서 열려 있음을 명시 |

고친 방법(앞의 1–6 에 더함/대체):
1'. 객체 열쇠는 이음. unassigned 는 §415 구간마다 따로. 객체 후보 수는 x86·감쌈·file 만, unassigned 는 따로.
2'. 경계: (i) §415 구간 경계와 같은 자리 — §418 결정이면 그 주소, 플래그가 있으면 (A 마지막 외부 기호, B 첫 외부 기호], 그 밖 미결정은 [하한, 상한]; (ii) 구간 안쪽 — 창(앞 묶음, 이 묶음) 안 이름 없는 진입점이 없고 `.word`·목록 밖 외부 기호·미확인 진입이 없으면 이 묶음 주소에서 결정, 아니면 (앞 묶음 주소, 이 묶음 주소].
3'. 분모: 객체 후보 수(종류별)·자료 전용 행 수; `__text` 바이트 Σ정확·Σ최소·Σ창; 진입점 3,570 의 정확 범위 배분과 창 안 수(창의 하한 주소에 있는 진입점은 창 안으로 셈). 함수 분모는 "경계 미확정" 이 남아 M2 는 이 항목에서 열려 있음.
4'. 자료: §419 구간 연결 + 자료 전용 x86 객체 행, 연결 안 된 구간과 이유, §419 의심 표시 승계. `__cstring`(링커가 문자열을 합침)·`__bss`(기호 0)·`__common`(COMMON 은 링커가 배치)은 객체 배정 불가로 이유와 크기만.
5'. 검증: (a') 단조·덮음·합, (b) §418 되풀이(assert), (c)(d) assert, (e) 진입점 소유 ↔ 객체 범위(위반 목록), (f) IDA 함수 시작 대조(진단).
6'. ObjC: 원본 로드 명령에 `__OBJC` 세그먼트가 없고 ObjC 런타임 이름(`objc_msgSend`·`.objc_class_name_` 등)이 기호표에 없음을 python 으로 확인해 기록(ObjC 로 컴파일된 객체는 `__OBJC` 절을 남기므로 링크 입력에 ObjC 객체가 없다는 바이트 근거). 291↔`pmap` 다리는 반영하지 않고 열린 항목으로 적음.

### 423.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-objects-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_objects.py`(assert: 묶음끼리 겹침 없음·묶음에 연속 객체 묶음 없음·묶음이 두 이음에 나뉘지 않음, §418 재현, 경계 단조, Σ최소 + Σ창 = `__text` 크기, 진입점 합 3,570). 표 `06_reconstruction/m68k-objects.tsv`(`__text` 객체 380 행 + 자료 행 16).

- **객체 후보 347**: x86 이름 대응(연속) 237, 감쌈 4, 파일(약한 후보) 106 — 그리고 `unassigned` 33(§415 구간별, 객체 수에서 뺌). 자료 전용 x86 객체 11 은 `__text` 없는 행으로 넣음(`init_sysent`·`tty_conf`·`uipc_proto`·`vfs_conf`·`in_proto`·`ufs_tables`·`param`·`counters`·`conf`·`ioconf`·`vers`).
- **경계 379**: 정확 325(§418 결정 264, 구간 안쪽 §416 규칙 61), 구간값 54(§418 미결정 6, 플래그 5, 구간 안쪽 창 43).
- **`__text` 바이트**: 양 끝이 정확한 객체 300 개 520,436 B(**76.70 %**); 모든 객체의 최소 바이트 합 614,904 B(90.63 %) + 경계 창 63,606 B(9.37 %) = 678,510 B.
- **진입점(함수 후보) 3,570**: 정확한 범위로 객체에 나눈 것 3,362, 경계 창 안 208. 함수 수 분모는 §4 함수 범위 규칙상 "경계 미확정" 이 남아 **M2 는 이 항목에서 열려 있음**.
- 검증: §418 의 34 객체 범위 34/34(새 시험 아님 — §418 되풀이). 이름 없는 진입점 654 의 소유 ↔ 객체 범위 위반 2 — `pmap` 정적 다리(0x4096f96, §421)와
  **새로 드러난 `ns_timer` 다리**: 0x404e458 은 x86 `ns_timer` 범위 안의 이름 없는 함수인데 구간 172 의 `_ns_timer_init` 만 `pea 0x404e458`(목록 99691)로 넘김 → 구간 172(`_ns_callout_init`·`_ns_timer_init`)가 m68k `ns_timer` 객체의 일부라는 근거(합치지 않고 열린 항목).
  IDA 함수 시작(`05_ida/exports/m68k/initial-functions.json`) 3,214 중 3,208 이 진입점과 같음, IDA 에만 6·진입점에만 362(진단, IDA 판단은 근거 아님).
- **자료**: §419 구간 122 중 객체에 연결 106, 자료 전용 행 11, 연결 안 됨 5(여러 객체에 걸친 `unmapped#k` 4, m68k `__text` 에 없는 `x86-VGAConsole` 1 — `_ohlfs12` 이름 충돌 의심). §419 의 의심 소유(`unmapped#287`)는 연결된 객체 비고로 넘김.
  `__cstring`(28,920 B, 링커가 문자열 합침)·`__bss`(9,420 B, 기호 0)·`__common`(82,624 B, 링커 배치)은 객체 배정 불가로 기록.
- **ObjC**: 원본 세그먼트는 `__TEXT`·`__DATA` 뿐(`__OBJC` 없음), 이름에 `objc` 가 든 기호는 `_kern_serv_load_objc` 하나(kernserv 함수 이름). ObjC 로 컴파일된 객체는 `__OBJC` 절을 남기므로 **링크 입력에 ObjC 객체가 없다는 바이트 근거**로 기록 — 기준 문서 M6 생략 조건(154 행)의 근거가 됩니다.

판단: M2 의 객체 분할·순서·절 배정이 하나의 후보 목록(`m68k-objects.tsv`)으로 모였고, `__text` 의 76.70 % 는 양 끝이 정확한 객체입니다. 열린 항목: 함수 분모(경계 미확정), 정적 참조 다리 2(`pmap`·`ns_timer`), `unassigned` 33·경계 창 54, 파일 종류 106 의 약한 근거. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 424. M2-10 세부 계획 — m68k 함수 목록과 분모: 진입점마다 도달 분석으로 함수 범위 확인(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09)

배경: §423 에서 M2 가 열려 있는 항목은 함수 분모입니다. RECONSTRUCTION_PLAN `:78` 의 함수 범위 규칙 — "모든 진입점·도달 블록(떨어진 꼬리 포함)을 원본에서 확인하지 못한 함수는 경계 미확정, 정렬 채움으로 보이는 바이트도 도달 여부로 확인" — 을 m68k 원본에 적용합니다.

입력: 원본 m68k 커널, 실기 `otool -tv` 목록(§416 과 같은 SHA), §418 진입점 3,570(외부 2,815 + 이름 없음 755)과 그 근거, §423 객체 목록.

방법(새 도구 `10_tools/reconstruction/m2_m68k_functions.py`):
1. 함수 후보 = 진입점, 후보 범위 = [진입점, 다음 진입점).
2. 도달 분석(목록 명령 기준): 진입점에서 시작해 이어지는 명령과 분기 대상(`bra`·`b<cc>`·`db<cc>`·`jmp 절대`)을 따라갑니다. `bsr`·`jsr` 는 호출로 보고 다음 명령으로 이어 가며, `rts`·`rte`·`rtd`·`rtr` 에서 멈춥니다.
   다른 진입점으로 가는 `bra`·`jmp` 는 꼬리 호출로 보고 따라가지 않습니다. `jmp aN@` 는 §416 과 같은 점프 표 인식(`movel aN@(0x0:b,Rm:l:4),aN`)이 되면 표 항목을 대상으로 더하고, 인식되지 않으면 "간접 분기 미해결".
3. 판정 "범위 확인": (a) 도달한 명령이 모두 후보 범위 안, (b) 도달한 주소가 모두 목록의 명령 경계이고 `.word` 가 아님, (c) 간접 분기가 모두 해결, (d) 후보 범위의 모든 바이트가 도달한 명령 또는 인식한 점프 표로 덮임.
   하나라도 어기면 "경계 미확정" 과 사유(범위 밖 도달 — 떨어진 꼬리 또는 진입점 누락 후보, 목록 어긋남, 간접 분기, 도달하지 않은 바이트).
4. 검증(규칙 고정 뒤): §414 V10 의 OBJECT_MATCH 34 객체(원본 위치 확정)의 함수 기호(외부·정적)로 만든 실제 함수 범위와 비교 — "범위 확인" 판정을 받은 후보가 실제 범위와 다르면 오류로 셉니다(하나라도 있으면 결과를 쓰지 않음). 실제 함수 중 "범위 확인" 비율을 적습니다.
   진단: IDA 함수 목록(`05_ida/exports/m68k/initial-functions.json`)의 시작·끝과 대조(근거 아님).
5. 분모: 함수 후보 수·범위 확인 수·바이트, 사유별 미확정 수; §423 객체별 함수 수.
6. 산출: `06_reconstruction/m68k-functions.tsv`(진입점, 이름(외부면), 근거, 후보 범위, 판정, 사유, §423 객체 id), `09_validation/reconstruction/m2-m68k-functions-20261009.json`.
해석 규칙: "범위 확인" 은 이 도달 규칙에 따른 원본 함수 범위이며 내용 일치(L1)가 아닙니다. 진입점 누락이 있으면 그 앞 함수가 "범위 밖 도달 없음 + 도달 안 된 바이트" 로 드러나도록 (d) 를 둡니다.

### 424.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `db<cc>` 피연산자에는 크기 접미사가 없음(116 줄 모두) — §416 의 분기 정규식은 접미사를 요구 | 목록 python: `db*` 116 줄, `:[bwl]$` 로 끝나는 것 0 | ✅ 새 도구는 접미사 없이 읽음. §416–418 영향: `db` 대상 중 다른 진입점을 가리키는 것 0(python) → 앞 결과 그대로 |
| `fb<cc>`(fbeq·fbge·fble·fblt·fbogt·fbne·fbgt·fbngt·fboge)가 있고 계획의 분기 목록에 없음 | 목록에서 9 종 41 줄 | ✅ 분기로 따름 |
| `rtd`·`rtr`·`trapv` 없음, `stop #0`(0x4094988)·`trap` 은 이어짐, `<bad ef>` 피연산자 줄 있음 | 목록: `rtd`·`rtr`·`trapv` 0, 186924 행 `stop #0x0`, `<bad ef>` 481 줄 | ✅ `stop`·`trap` 은 이어 감, `<bad ef>` 는 `.word` 와 같이 무효 |
| `jmp` 꼴: 절대 42·`a0@` 96·`a1@` 19·`a2@` 1·`pc@(…)` 6 | 목록 python 같음 | ✅ `pc@(…)` 는 간접(미해결) |
| 점프 표 길이는 앞의 `moveq #N`/`cmpl #N` 한계 + 1 과 같음(87 표 모두) — "범위 안이면 계속 읽기" 대신 이 한계를 쓸 것 | 도구에서 한계를 읽고 표 끝이 목록 행인지 assert | ✅ |
| 검증 34 객체(함수 181)는 표·꼬리 분기·어셈블리가 거의 없어 잘못된 확인을 못 잡음 — 적대 시험 필요: 진입점 빼기(앞 함수가 미확정이 되어야), 가짜 진입점 끼우기(뒷부분이 확인되면 안 됨, 계획대로면 49.8 % 가 잘못 확인) | 도구에 두 시험을 넣어 직접 셈 | ✅ (e) 규칙 추가: 이 후보에서 다른 진입점으로 가는 비호출 분기가 없고, 다른 후보의 분기·이어짐·표가 이 후보 시작이나 안쪽에 닿지 않을 것. 가짜 끼우기 시험의 잘못 확인 0 을 통과 조건으로 |
| 장벽(`bra`·`rts`·호출) 뒤 다음 진입점 바로 앞의 2 바이트 `nop` 은 GCC 가 넣는 것으로 보이며 도달하지 않음(예 `kern_exit` 0x40054c8: `bsr 0x40054ca` 다음 `nop`) | 목록 5799–5803 행 읽음 | ⚖️ GCC 소스 근거는 없음(검토자도 기억이라 함) → "다음 진입점 바로 앞의 마지막 2 바이트 `nop` 은 이어짐을 멈추고 덮인 것으로 셈" 을 **원본 관찰에 근거한 명시적 허용** 으로 두고 그 수를 따로 셈 |
| `jmp aN@` 로 끝나지만 범위가 다 덮인 것은 "범위 닫힘·간접 출구" 로 따로 | 설계 | ✅ 미확정의 하위 사유로 |
| 진입점 중 자료 이름(목록 밖·첫 줄이 `.word`/`<bad ef>`/0 낱말, 예 `_intstacks`)은 함수 후보가 아니라 "자료 이름" 분류로 | 설계(수는 도구에서) | ✅ |
| IDA 대조는 진단 | 설계 | ✅ |

고친 규칙: 분기 = `bra`·`b<cc>`(접미사 있음)·`db<cc>`(없음)·`fb<cc>`·`jmp 절대`; 호출 = `bsr`·`jsr`; 끝 = `rts`·`rte`; `stop`·`trap` 은 이어짐; 무효 = `.word`·`<bad ef>`; 점프 표 = GCC 꼴 + 한계 길이; 다른 진입점으로 가는 비호출 분기(어느 꼴이든)는 꼬리 분기로 기록하고 (e) 로 판정; 마지막 `nop` 허용; 자료 이름 분류.
판정 "범위 확인" = (a)–(d) + (e). 시험: 검증 34 객체(잘못 확인 0), 빼기 시험(빠진 진입점의 앞 함수가 모두 미확정), 끼우기 시험(잘못 확인 0) — 하나라도 어기면 결과를 쓰지 않음.

### 424.2 첫 실행의 시험 실패와 규칙 수정(기록 후 재실행, 2026-10-09)

첫 실행(scratchpad 에만): 검증 34 객체의 함수 181 은 모두 진입점·모두 범위 확인·잘못 확인 0 이었으나, **빼기 시험 3,307 중 1 실패, 끼우기 시험 6,957 중 22 실패** → 미리 정한 대로 결과를 쓰지 않았습니다.
- 끼우기 22 는 모두 가짜 진입점이 함수 끝 `nop` 한 줄(2 B)인 경우 — `nop` 하나짜리 "함수" 가 끝 `nop` 허용 때문에 확인되었습니다.
- 빼기 1 은 0x40054a6 의 `bsr 0x40054ca; nop` 다음 진입점 0x40054ca 를 뺀 경우 — 이어짐이 그 코드를 흡수했습니다. 그 주소는 바로 앞 `bsr` 의 호출 대상입니다.
수정(좁힘): (f) 후보 범위 안쪽(시작이 아닌 곳)에 `bsr`·`jsr` 절대 호출 대상이 있으면 미확정("범위 안 호출 대상"); 진입 줄이 `nop` 한 줄이고 바로 다음이 다음 진입점이면 그 후보는 "채움" 분류(함수 후보 아님). 두 시험과 검증은 같은 기준으로 다시 돌립니다.

### 424.3 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-functions-20261009.json`

도구 `10_tools/reconstruction/m2_m68k_functions.py`(규칙 424.1 + 424.2). 표 `06_reconstruction/m68k-functions.tsv`(진입점 3,570 행).

- 진입점 3,570 = **함수 후보 3,542** + 자료 이름 28(목록 밖·첫 줄 무효·0 낱말 — `_intstacks`, FPSP 상수 표 등). 채움(`nop` 한 줄) 0.
- **범위 확인 3,338**(625,128 B, `__text` 의 **92.13 %**), 경계 미확정 204. 확인된 것 중 끝 `nop` 허용 23, 점프 표 72.
  미확정 사유(겹침): 다른 후보에서 들어오는 비호출 가장자리 96·다른 진입점으로 가는 꼬리 분기 95·도달 안 된 바이트 63·범위 밖 도달 51·간접 분기 미해결 24·다음 진입점으로 이어짐 14·무효 줄 도달 1.
- §423 객체 종류별(정확 범위 안 후보): x86 이름 대응 2,395 중 확인 2,394, 감쌈 67 모두, 파일 793 중 628, unassigned 84 중 76; 경계 창 안 후보 203 중 173.
  미확정은 대부분 어셈블리(`locore.s`·FPSP·`libc.s` 등 공유 꼬리·계산된 분기·`__text` 안 자료)입니다.
- **시험(미리 정한 통과 조건 모두 충족)**: 검증 34 객체의 함수 181(외부 128·정적 53) — 모두 진입점·모두 범위 확인·잘못 확인 0; 빼기 시험 3,307 — 빠진 진입점의 앞 함수가 모두 미확정(실패 0); 끼우기 시험 6,957 — 잘못 확인 0.
- IDA 대조(진단): IDA 함수 3,214 중 확인 범위와 시작·끝 모두 같음 2,955, 시작만 같음 38, 확인 범위인데 IDA 함수 없음 345, IDA 시작이 진입점 아님 6.

판단: M2 의 함수 분모를 §4 함수 범위 규칙대로 정했습니다 — **함수 후보 3,542, 그중 범위 확인 3,338(625,128 B), 경계 미확정 204, 자료 이름 28**. 범위 확인은 이 도달 규칙에 따른 원본 함수 범위이며 내용 일치(L1)가 아닙니다.
이로써 기준 문서 M2 끝 조건(객체 분할·순서·절 배정 목록, 함수 수·바이트 분모)은 **후보 목록과 규칙 기반 분모로 채워졌습니다.** 남은 불확실성: 파일 종류 객체(약한 후보), 정적 참조 다리 2(`pmap`·`ns_timer`), unassigned·경계 창, 미확정 함수 204. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 425. M3-1 세부 계획 — m68k 구성 가설 `DRIVERKIT 0`(→ `MACH_SLOCKS 0`)을 재컴파일로 시험(07·기존 표 변경 없음; 코딩 전, 2026-10-09)

배경: §414 의 머리·구성 차이(`struct utask` 필드 4 B, `processor.slot_num` 8 B, `processor_set` 필드 4–8 B, 원본 `_compute_mach_factor` 에 `simple_lock` 호출 없음)는 잠금 자료 크기 하나로 설명될 수 있습니다.

확인한 사실(이번 세션, 읽기 전용):
- 스테이징 `m0p413-stage/src/kern/lock.h:66` `#define MACH_SLOCKS ((NCPUS > 1) || MACH_LDEBUG || DRIVERKIT)`; `MACH_SLOCKS` 이면 `struct lock` 끝에 `interlock`(`simple_lock_data_t`, m68k 4 B)이 들어가고, 아니면 빠지며 `simple_lock` 등은 빈 매크로입니다(같은 파일 82–105 행).
- 생성 머리 `generated/cpus.h` `NCPUS 1`, `generated/driverkit.h` `DRIVERKIT 1`(x86 구성에서 옴), `MACH_LDEBUG` 머리는 없음. `meta_features.h:8` 이 `driverkit.h` 를 `-imacros` 로 가져옴. 46 대상 중 21 이 `kern/lock.h` 를 거침(§413 의존 목록).
- `struct utask` 의 `uu_cred_lock` 은 `lock_data_t` 이고 그 뒤 필드들이 원본보다 4 B 뒤에 있음(§414.3).
- 원본 m68k 에서 `_simple_lock`·`_simple_unlock`·`_simple_lock_init` 은 같은 주소 0x40018c2 의 별칭(`_simple_lock_try` 0x40018c4), 이 주소를 부르는 `bsr`/`jsr` 는 2 곳뿐. m68k 원본에는 DriverKit·ObjC 객체가 없음(§415·§423). NeXTMach mk-108.1 에는 `DRIVERKIT` 이름이 없음(grep 0).

가설: 1997 m68k 커널 구성은 `DRIVERKIT` 0(그래서 `NCPUS 1` 과 함께 `MACH_SLOCKS` 0)입니다.

방법:
1. 새 무시 대상 스테이징 `08_build/runs/tools/m0p425-stage` = `m0p413-stage` 복사 + `generated/driverkit.h` 만 `#define DRIVERKIT 0` 으로 바꿈(매니페스트에 바뀐 파일 1 개 기록). 07 은 바꾸지 않습니다.
2. 실기 run `m0p425-cc1`: §414 V10 과 같은 명령(46 객체, `-arch m68k -g -O2`, `-fwritable-strings` 없음)을 새 스테이징으로. 실패하면 로그로 원인을 적고 실패 객체를 빼서 다시.
3. 비교(python, §414 도구 함수 재사용): 객체마다 V10 과 SHA 가 같은지(바뀐 객체 수), L1(OBJECT_MATCH·함수 MATCH)·외부 구간 같음 수를 V10 과 대조 — 얻은 것·잃은 것을 객체·함수 단위로. 특히 §414 의 D 11 구간(`vfs_syscalls` 7·`_acct`·`_unp_externalize`·`_lookuppn`·`_host_info`)과 `_compute_mach_factor`.
4. 해석(미리 정함): 잃은 것 없이 D 구간이 같아지면 "m68k 구성 `DRIVERKIT 0`/`MACH_SLOCKS 0` 후보" 로 기록(역사적 확정 아님). 잃는 것이 있으면 결론 내지 않고 객체별로 적음.
5. 산출: `09_validation/reconstruction/m3-m68k-config-driverkit-20261009.json`, 상세는 무시 대상 `08_build/artifacts/m3p425/`.

### 425.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `lock.h:66`·`cpus.h`·`driverkit.h` 값·`MACH_LDEBUG` 정의 없음 맞음; `-imacros` 는 컴파일 줄에서 오며 `meta_features.h:8` 은 `#import <driverkit.h>` 줄 | 앞서 읽은 출력과 같음 | ✅ 문구를 "컴파일 줄의 `-imacros meta_features.h` 가 `driverkit.h` 를 가져옴(8 행)" 으로 이해 |
| 원본 `_simple_lock_alloc` 은 `clrl d0` 만, `_simple_lock_free` 는 빈 함수(목록 95054–95064) — `lock.c` 의 `MACH_SLOCKS` 0 쪽 | 목록 그 줄 읽음 | ✅ 근거 추가 |
| 원본 `sizeof(lock_data_t)` = 8: `_lock_alloc` 이 `kalloc(8)`, `_lock_free` 가 크기 8, `_lock_init` 이 `bzero(…,8)` | 목록 0x404ab44–0x404ab82 의 `pea 0x8:w` + `bsr 0x404a200`(`_kalloc`)·`bsr 0x404a2c4`·`bsr 0x4092e12`(`_bzero`) 읽음 | ✅ 근거 추가(interlock 없으면 8, 있으면 12) |
| `DRIVERKIT` 로 가려지는 기호 6 개(`_KernDeviceInterruptMsgRelease`·`_dev_server_init`·`_device_master_self`·`_driverServer_server_routine`·`_vol_check_manual_poll`·`_vol_check_set_poll`)가 x86 에는 있고 m68k 에는 없음 | 두 `symbols.tsv` grep: m68k 0·x86 1 씩 | ✅ |
| m68k `_mach_trap_table`(0x40afaac, 항목 16 B) 항목 69 = `_kern_invalid` — `syscall_sw.c:100–101` `#if !DRIVERKIT … device_master_self kern_invalid`; 항목 56 = `_host_priv_self` 로 정렬 확인 | python 으로 항목 56·69 읽음; `syscall_sw.c:100–101` 읽음 | ✅ **`DRIVERKIT 0` 의 직접 근거**(컴파일 시험과 별개) |
| 두 호출처: `_miniMonInit` 의 `simple_lock_init`, `_miniMonLoop` 뒤 정적 함수의 `simple_lock_try`·`simple_unlock` — `mach/m68k/simple_lock.h` 의 실제 함수 선언을 직접 가져와 매크로를 피함 | 호출 수 2(+try 1)는 앞서 셈; 함수 이름은 목록 99496·99640·99648 행(도구에서 기록) | ⚖️ 기록(miniMon 재구성 때 주의점) |
| 종이 계산: `run_queue`·`processor`·`processor_set`·`utask` 배치에서 interlock 을 빼면 §414 의 모든 변위 차이(+4 ×32, +8 ×2, `_compute_mach_factor` 의 4·8·12·16)가 정확히 나옴 | 이 절의 재컴파일 결과로 직접 확인(종이 계산은 옮기지 않음) | ⏭️→ 시험 결과로 대체 |
| 문구 오류: `processor_set` 차이는 "4–8 B" 가 아니라 4·8·12·16 B; §414.3 표(2258 행)의 "원본보다 4 B 앞" 은 "뒤" 가 맞음 | 2258 행 읽음(다른 곳은 "뒤") | ✅ 이 표로 정정(앞 절 원문은 고치지 않음) |
| `-g` 의 STABS 가 바뀌므로 파일 SHA 로 "바뀐 객체" 를 세면 과대 — 절별로 비교하고 "STABS 만 바뀜" 을 따로 | 설계 | ✅ |
| 대조군·예측을 미리 정할 것: `lock.h` 를 안 거치는 객체는 비 STABS 바이트 동일, D 11 구간이 같아지고 `_compute_mach_factor` 가 `bsr` 4 개와 `pea` 를 잃음; m68k 의존 목록(`-M`)도 같은 run 에서 | 설계 | ✅ |
| 컴파일 시험은 `MACH_SLOCKS 0` 만 시험 — `DRIVERKIT 0` 자체는 기호 부재·트랩 표 근거로 따로 | 설계 | ✅ |
| 스테이징 복사는 매니페스트로 모든 파일 SHA 대조(바뀐 파일 정확히 1) | 설계 | ✅ |
| "잃은 것 없음" 은 X 15 구간·OBJECT_MATCH·함수 MATCH 수까지 | 설계 | ✅ |

고친 방법: 2' run `m0p425-cc1` 에 46 객체의 `-arch m68k -M` 줄을 함께 넣음. 3' 비교는 절별(`__text`·재배치·`__data`·`__cstring`)과 STABS 분리; 대조군 = m68k `-M` 에 `kern/lock.h` 가 없는 객체(비 STABS 동일이어야 함); 예측 = D 11 구간 같음, `_compute_mach_factor` 의 `bsr` 4·`pea` 1 사라짐; 잃은 것 = OBJECT_MATCH·함수 MATCH·외부 구간 같음 모두에서 0. 4' 해석: 시험이 통과하면 "`MACH_SLOCKS 0` 이 m68k 객체를 원본에 맞춤" 과 "`DRIVERKIT 0`(기호 부재 6·트랩 표 69)" 을 함께 m68k 구성 후보로 기록.

### 425.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-config-driverkit-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_config.py`. 스테이징 `m0p425-stage`(878 파일, 매니페스트 대조로 바뀐 파일은 `generated/driverkit.h` 하나). 실기 run `m3p425-cc1`(컴파일 46 + `-M` 46, 모두 종료 0·게시; 도구 12 경로 해시 전후 같음; 경고 내용 46/46 V10 과 같음).

- m68k `-M` 목록에서 `kern/lock.h` 를 거치는 객체 21(§413 의 i386 목록과 같은 수), **대조군**: 거치지 않는 25 는 파일까지 V10 과 같음(위반 0).
- 바뀐 절: `__text` 20 객체(바이트 또는 재배치의 기호 번호 — 빠진 `_simple_*` 미정의 기호 때문), `__data` 3.
- **원본 대조(V10 → DRIVERKIT 0)**: OBJECT_MATCH 34 → **40**(+`host`·`kern_acct`·`mach_factor`·`uipc_usrreq`·`vfs_lookup`·`vfs_syscalls`), 함수 MATCH 240 → **252**, 외부 구간 같음 195 → 207. **잃은 것 0**(객체·함수·구간).
- **예측**: §414 의 D 11 구간 모두 같아짐, X 였던 `_compute_mach_factor` 도 같아지고 `_simple_*` 참조가 사라짐.

판단(425.1 의 4'): `MACH_SLOCKS 0`(= m68k 에서 `NCPUS 1` 이고 `DRIVERKIT 0`)이 §414 의 머리·구성 차이(utask 4 B, processor 8 B, processor_set 4–16 B, 잠금 호출)를 모두 설명하며 잃는 것 없이 원본에 맞춥니다.
`DRIVERKIT 0` 자체는 원본의 별도 근거(DriverKit 가림 기호 6 개 부재, 트랩 표 항목 69 = `_kern_invalid`, `lock_data_t` 8 B, `_simple_lock_alloc` 이 0 반환)와 함께 **m68k 구성 후보**로 기록합니다(역사적 확정 아님).
M3 에 남은 것: §414 의 X 구간 중 머리 요인(인라인 spl, `HTONS`), `vfs_dnlc` 인라인, m68k 구성 값 전체(옵션 표의 m68k 열 — `config_options.tsv` 의 DRIVERKIT 기반 유도값 재검토 포함). 07·x86 표는 바꾸지 않았습니다.

## 426. M3-2 세부 계획 — m68k `machparam.h` 가 인라인 spl 을 가져왔다는 가설을 재컴파일로 시험(07·기존 표 변경 없음; 코딩 전, 2026-10-09)

배경: §414 의 X 구간 `_ku_sendto_mbuf`(subr_kudp)·`_VENIP_RIF`(if_venip) 에서 원본은 `splx`·`splimp` 를 `movew sr` 인라인으로, 객체는 함수 호출로 합니다. 두 07 소스는 `machine/spl.h` 를 가져오지 않고(subr_kudp.c 11–29 행), m68k `-M` 목록에도 spl 머리가 없습니다(§425 run).

확인한 사실(이번 세션, 읽기 전용):
- NeXTMach mk-108.1: `next/machparam.h:14` `#import <next/eventc.h>`, `next/eventc.h:38`(KERNEL 안) `#import <next/spl.h>`, `next/spl.h` 에 인라인 `splx`·`splnet` 매크로(34·47·100 행). `sys/param.h` → `machine/machparam.h` 를 거치는 모든 파일이 인라인 spl 을 받습니다. mk-108.1 `rpc/subr_kudp.c` 도 spl 머리를 직접 가져오지 않습니다(11–29 행).
- 스테이징의 SDK m68k `bsd/m68k/machparam.h`(58 행)는 `mach/m68k/vm_param.h` 만 가져오고 eventc·spl 을 가져오지 않습니다(공개 SDK 판).
- 스테이징 `bsd/m68k/spl.h` → `kernserv/m68k/spl.h` 가 같은 인라인 매크로를 정의하며, `KERNEL_BUILD` 면 생성 머리 `iplmeas.h`(`NIPLMEAS`)를 요구 — 지금 `generated/` 에 없음. mk-108.1 `conf/MASTER.next` 의 `iplmeas` 는 측정 구성(IPLMEAS)에만 있음.

가설: 1997 m68k 내부 `machparam.h` 도 KERNEL 에서 m68k spl 머리를 가져왔다(NeXTMach 와 같은 사슬).

방법(새 도구 함수는 §425 도구에 하위 명령으로 더하지 않고 새 도구 `10_tools/reconstruction/m3_m68k_spl.py`):
1. 무시 대상 스테이징 `08_build/runs/tools/m0p426-stage` = `m0p425-stage` 복사(모든 파일 SHA 대조) + (a) `generated/iplmeas.h` 새로 `#define NIPLMEAS 0`, (b) `src/bsd/m68k/machparam.h` 의 `#if KERNEL` 블록에 `#import <bsd/m68k/spl.h>` 한 줄 추가. 바뀐·더한 파일 2 개를 매니페스트에 적음. 07 은 바꾸지 않음.
2. 실기 run `m3p426-cc1`: §425 와 같은 46 컴파일 + `-M`. 컴파일 실패(예: 소스의 spl 함수 선언과 매크로 충돌)가 있으면 로그로 원인을 적고 그 객체를 빼서 새 ID 로.
3. 비교 기준선 = §425 run(DRIVERKIT 0). 미리 정한 대조군·예측: 대조군 — `-M` 에 `bsd/m68k/machparam.h` 를 거치지 않거나 spl 이름을 쓰지 않는 객체는 비 STABS 절 동일; 예측 — `_ku_sendto_mbuf`·`_VENIP_RIF` 구간이 원본과 같아짐; 잃은 것(OBJECT_MATCH·함수 MATCH·외부 구간) 0.
4. 해석: 통과하면 "m68k 내부 `machparam.h` 가 spl 머리를 가져옴" 을 m68k 머리 후보로 기록(SDK 판과 다름). 하나라도 어기면 결론 내지 않음.
5. 산출: `09_validation/reconstruction/m3-m68k-spl-20261009.json`, 상세는 무시 대상 `08_build/artifacts/m3p426/`.

### 426.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 인용 사실 맞음; 다만 `next/spl.h:34` 는 어셈블리용 `splx`, C 용은 :47 | 앞서 읽은 출력과 같음 | ✅ 줄 정정 |
| NeXTMach `next/spl.h` 매크로는 `register int ret`(41·48 행), SDK `kernserv/m68k/spl.h` 는 `register short ret`(46·53 행); 원본은 `movew sr,d0; movew #0x2300,sr; movew d0,d4; extl d4`(0x401c492–0x401c49a) — `extl` 은 short → int 넓힘이므로 **1997 원본은 SDK(short) 꼴** | 네 줄과 원본 목록 34924–34927 행 읽음 | ✅ 배경 문구 정정: 사슬은 NeXTMach 와 같을 수 있으나 매크로 본문은 SDK 꼴. 예측에 "short 꼴(`extl`)" 을 더함 |
| 원본 m68k 기호표에 `_spl*` 기호 0 → 원본에서 spl 을 함수로 부를 수 없음; `movew` 로 SR 을 다루는 함수 456(108 객체 묶음) | `grep -cP "\t_spl" symbols.tsv` = 0; 456 은 도구에서 다시 셈 | ✅ "m68k 에서 spl 은 모두 인라인" 은 컴파일 시험과 별개의 원본 사실로 기록 |
| 46 객체 중 `_spl*` 를 참조하는 것은 subr_kudp(`_splnet`·`_splx`)·if_venip(`_splimp`·`_splx`) 2 뿐 → 바뀔 수 있는 객체는 2, 나머지 44 는 코드가 같아야 함 | §425 객체 기호표 python: 정확히 그 2 개 | ✅ 대조군을 "§425 객체에 `_spl*` 참조 없음" 44 로 정밀화 |
| 컴파일 실패 예측 없음(46 객체의 m68k `-M` 머리 188 개에 spl 이름 선언·함수 포인터 없음) | 실행 결과로 확인 | ⏭️→ 실행으로 |
| `-M` 변화 예측: `machparam.h` 를 거치는 39 객체에만 머리 4 개(`iplmeas.h`·`bsd/m68k/spl.h`·`psl.h`·`kernserv/m68k/spl.h`)가 더해짐 | 도구에서 대조 | ✅ 예측에 추가 |
| 위험 항목 이름: subr_kudp `_ku_recvfrom` MATCH, if_venip 같음 구간 3(`_VENIP_PRIVATE`·`_VENIP_ENADDRP`·`_VENIP_IPADDR`); `_venip_config` 은 바뀔 수 있음 | 도구에서 기록 | ✅ |
| 시험은 매크로가 **어느 머리**로 들어왔는지 가르지 못함(두 파일이 공유하는 어느 경로든 같은 바이트) | 설계 | ✅ 해석을 좁힘: "SDK 꼴 인라인 spl 이 이 두 번역 단위에 보임; `machparam.h` 경로는 NeXTMach 근거의 후보이며 시험되지 않음" |
| 바뀐 두 객체에 블록·레지스터 변수 STABS 가 더해짐 — 잃음으로 세지 말 것 | 설계 | ✅ |

### 426.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-spl-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_spl.py`. 스테이징 `m0p426-stage`(879 파일: `src/bsd/m68k/machparam.h` 한 줄 추가, `generated/iplmeas.h` 추가). 실기 run `m3p426-cc1`(92 명령 종료 0·게시, 도구 해시 전후 같음).

- `-M` 예측 맞음: `machparam.h` 를 거치는 39 객체에 정확히 머리 4 개가 더해지고, 나머지 7 은 그대로. 대조군(§425 객체에 `_spl*` 참조 없는 44) 비 STABS 절 변화 0. 두 객체의 `_spl*` 미정의 참조는 모두 사라짐.
- 원본 대조(§425 → 이번): OBJECT_MATCH 40 → **41**(`subr_kudp`), 함수 MATCH 252 → 253(`_ku_sendto_mbuf`), 잃은 것 0, 위험 항목(`_ku_recvfrom`·`if_venip` 같음 구간 3) 그대로.
- **예측 하나 실패**: `_VENIP_RIF` 는 아직 다름 → 미리 정한 규칙대로 전체 결론은 내지 않습니다. 실기 `otool -tv` 로 풀어 보면 spl 부분은 원본과 같은 SDK 꼴(`movew sr,d0; movew #0x2300,sr; movew d0,dN; extl dN`)이 되었고,
  남은 차이는 레지스터 배정(d3 ↔ d4)과 원본에만 있는 `pea _IFCONTROL_SETIPADDRESS` 호출 묶음, `__const` 참조 위치입니다. 그 호출은 07 `if_venip.c:155–161` 의 `#if GDB` 안 `if_control(rifp, IFCONTROL_SETIPADDRESS, …)` 이고, 스테이징 `generated/gdb.h` 는 x86 구성의 `GDB 0` 입니다. mk-108.1 `conf/MASTER.next` 의 출시 구성(RELEASE)에는 `gdb` 가 들어 있습니다.
- 원본 사실(컴파일과 별개): m68k 기호표에 `_spl*` 기호 0 — m68k 에서 spl 은 모두 인라인.

판단: "SDK 꼴 인라인 spl 이 m68k 번역 단위에 들어와야 한다" 는 `subr_kudp` 에서 객체 전체 일치로 확인되었습니다(어느 머리로 들어왔는지는 이 시험으로 가르지 못함 — `machparam.h` 경로는 NeXTMach 근거의 후보). `if_venip` 의 남은 차이는 spl 이 아니라 **`GDB` 구성 값 후보**로 보이며 다음 절(§427)에서 시험합니다.

## 427. M3-3 세부 계획 — m68k 구성 가설 `GDB 1` 을 재컴파일로 시험(07·기존 표 변경 없음; 코딩 전, 2026-10-09)

배경: §426.2 에서 `_VENIP_RIF` 의 남은 차이가 07 `if_venip.c:155–161` 의 `#if GDB` 블록(`if_control(rifp, IFCONTROL_SETIPADDRESS, …)`)으로 보였습니다.

확인한 사실(이번 세션, 읽기 전용):
- 스테이징 전체에서 `GDB` 를 조건으로 쓰는 곳은 `src/bsd/net/if_venip.c` 의 29·155 행뿐(`grep -rnw GDB`), 생성 머리 `generated/gdb.h` 는 `#define GDB 0`(x86 구성; `machdep/i386/trap.c:337` 주석 "the original kernel has GDB 0, as if_venip shows"), `meta_features.h:12` 가 가져옴.
- 원본 m68k 기호표에 `_IFCONTROL_SETIPADDRESS`(0x40ad8bc, section 3 = `__const`)가 있고 x86 183.34.4 기호표에는 없음.
- NeXTMach mk-108.1 `conf/files.NeXT:25–26` 에서 `next/nextdbg.c`·`next/nextdbgasm.s` 는 `optional gdb` 인데, 그 이름의 함수(`_dbg_kresume`·`_kdbg_connect`·`_kdebug_send`·`__dbg_trap`…)가 m68k 원본에 있음(§420 표). `conf/MASTER.next:88` 출시 구성(RELEASE)에 `gdb` 포함.

가설: 1997 m68k 커널 구성은 `GDB 1` 입니다.

방법(도구 `10_tools/reconstruction/m3_m68k_gdb.py`, §426 도구와 같은 틀):
1. 스테이징 `08_build/runs/tools/m0p427-stage` = `m0p426-stage` + `generated/gdb.h` 를 `#define GDB 1` 로(매니페스트 대조, 바뀐 파일 1).
2. 실기 run `m3p427-cc1`: 46 컴파일 + `-M`(§426 명령에서 출력 이름만 바꿈).
3. 미리 정한 대조군·예측: 대조군 = `if_venip` 밖 45 객체는 파일 SHA 까지 §426 과 같음(GDB 를 쓰는 곳이 없으므로); 예측 = `if_venip` 의 `_VENIP_RIF` 구간이 원본과 같아짐(그리고 `if_venip` OBJECT_MATCH 가능); 잃은 것 0(특히 `if_venip` 의 같음 구간 3).
4. 해석: 통과하면 `GDB 1` 을 m68k 구성 후보로 기록(원본 근거: `_IFCONTROL_SETIPADDRESS` 기호, gdb 선택 파일의 함수). 07 의 다른 소스에 x86 에서 보이지 않아 빠진 `#if GDB` 블록이 있을 수 있음을 M5 주의점으로 적음.
5. 산출: `09_validation/reconstruction/m3-m68k-gdb-20261009.json`, 상세 `08_build/artifacts/m3p427/`(무시 대상).

### 427.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 사실 모두 맞음; `MASTER.next` 의 LOCKRELEASE·DEBUG·IPLMEAS(89–91 행)에도 `gdb` 가 있어 출시 구성만을 가리키지는 않음 | 앞서 읽은 88–90 행 출력 | ✅ 근거 문구를 "NeXTMach 구성들에 공통으로 gdb" 로 |
| mk-108.1 에서 `IFCONTROL_SETIPADDRESS` 는 `nextif/if_en.c` 에 정의(다른 객체) | `net/tags:1631` 읽음 | ✅ 원본 기호 0x40ad8bc 의 소유는 if_en 계열(§419 자료 표의 그 구간 소유 표시 `x86-kern_server` 는 상한일 뿐이므로 근거로 쓰지 않음) |
| 46 객체의 m68k `-M` 머리 192 개 중 `GDB`·디버그 매크로를 조건으로 쓰는 곳은 `if_venip.c` 뿐(그 밖 `user.h:212` `DEBUG`·`assert.h:42` 는 무관) → 대조군 45 객체 파일 동일, `-M` 46 목록 모두 동일 예측 | 실행 결과로 확인 | ✅ 예측에 "`-M` 목록 46 모두 동일" 추가 |
| `_VENIP_RIF` 일치 예측 근거: 객체·원본 크기 차 16 B 가 `#if GDB` 호출 묶음(18 B)·주소식 변화(−2·−2)·분기 길이(+2)·스택 정리 합침으로 설명; 레지스터 d3/d4 교환만 컴파일러 판단 | 실행 결과로 확인 | ⏭️→ 실행으로 |
| §426.2 의 "`__const` 참조 위치 0 ↔ 226" 은 재현되지 않음 | python: 원본 `__const` 시작 0x40ace76 + 226 = 0x40acf58 = `if_venip` 의 `__const` 시작(§419 자료 표 122 행) — 객체 쪽 `+0` 과 같은 항목을 서로 다른 절 기준으로 적은 정규화 산물 | ✅ **내 §426.2 서술 정정**: 실제 차이가 아님 |
| 새 도구는 §426 도구의 `K426__`·`NEW_DEPS` 고정값을 그대로 쓰면 안 됨; 기준선은 §426 run, 새 의존 0 예측 | 설계 | ✅ |
| 예측 추가: `if_venip` `__text` 1,582 B·`__const` 0x40acf58 배치 | 설계 | ✅ OBJECT_MATCH 와 함께 기록(크기·배치는 결과로 적음) |
| `_venip_config` 구간은 판정 근거로 쓰지 말 것(원본 범위 문제일 수 있음) | 설계 | ✅ |
| M5 주의: mk-108.1 의 `GDB` 사용 10 파일(`next/cframe.h`·`cons.h`·`locore.s`·`machargs.c`·`machdep.c`·`mmu.h`·`next_init.c`, `nextdev/zs.c`, `nextif/if_en.c`, `net/if_venip.c`); `07_kernel/generated/gdb.h` 는 x86 과 공유 — m68k 는 아키텍처별 생성값이 필요 | 설계(목록은 M5 에서 다시 확인) | ✅ 기록 |

### 427.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-gdb-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_gdb.py`. 스테이징 `m0p427-stage`(879 파일, `generated/gdb.h` 하나만 `GDB 1`). 실기 run `m3p427-cc1`(92 명령 종료 0·게시, 도구 해시 전후 같음).

- 대조군: `if_venip` 밖 45 객체 파일까지 §426 과 같음(위반 0); `-M` 목록 46 모두 같음.
- **예측 맞음**: `_VENIP_RIF` 구간 같아짐, `if_venip` **OBJECT_MATCH**(`__text` 1,582 B 를 0x401c2bc 에, `__const` 를 0x40acf58 에 배치 — 검토 예측과 같음), 함수 11 개 모두 MATCH.
- 원본 대조(§426 → 이번): OBJECT_MATCH 41 → **42**, 함수 MATCH 253 → **264**, 외부 구간 같음 208 → 209, **잃은 것 0**.

판단: `GDB 1` 을 m68k 구성 후보로 기록합니다(원본 근거: `_IFCONTROL_SETIPADDRESS` 기호가 m68k 에만 있음, gdb 선택 파일 `next/nextdbg.c`·`nextdbgasm.s` 의 함수가 원본에 있음). x86 은 `GDB 0`(`trap.c:337`)이므로 m68k 빌드에는 아키텍처별 생성값이 필요합니다.
M5 주의: 07 의 다른 소스에 x86 에서 보이지 않아 빠진 `#if GDB` 블록이 있을 수 있고, mk-108.1 은 `GDB` 를 10 파일에서 씁니다(§427.1). M3 m68k 구성 후보 누계: `DRIVERKIT 0`(§425)·SDK 꼴 인라인 spl(§426)·`GDB 1`(§427), 46 객체 OBJECT_MATCH 18(§413) → 34(§414 플래그) → 42.

## 428. M3-4 세부 계획 — 46 객체 중 남은 4 NOT_MATCH 의 명령 수준 진단(07·기존 표 변경 없음; 진단만, 2026-10-09)

배경: §427 까지의 구성(V10 플래그 + `DRIVERKIT 0` + 인라인 spl + `GDB 1`)에서 46 객체 중 4 가 NOT_MATCH 입니다(§427 기록): `ip_icmp`(`_icmp_sendMaskPacket` DIFF), `kern_uname`(`_uname` DIFF), `tcp_input`(`__text` 미배치 — `_tcp_input`·`_tcp_mss` 구간 다름), `vfs_dnlc`(`__text` 미배치 — 구간 5 다름).
이번 절은 가설을 세우기 위한 진단만 합니다(새 컴파일 없음).

방법(새 도구 `10_tools/reconstruction/m3_m68k_diag.py`):
1. 실기 `otool -tv`(읽기 전용 gcds)로 `m3p427-cc1` 의 네 객체를 풀어 무시 대상 `08_build/artifacts/m3p428/otool/` 에 둡니다(원본 목록은 §414 의 것, SHA 대조).
2. §414 의 정규화(`m0_m68k_cause.norm_span`·`classify`)와 difflib 정렬로 외부 구간마다 차이 덩어리를 뽑고, 덩어리마다 객체의 STABS 줄 번호(`N_SLINE`)로 07 소스 줄을 붙입니다(어느 소스 문장의 코드인지).
3. 덩어리별 분류(사람이 읽고 적되, 근거는 도구 출력): 구성·머리 값(변위·상수), 매크로 꼴(예 `HTONS`), 인라인 판단, 레지스터 배정만, 명령 선택·순서, 소스 문장 차이 후보.
   각 덩어리에 대해 참고 소스(NeXTMach mk-108.1·Darwin 0.1 의 같은 함수, 경로:줄만)를 대조해 "x86 에서는 같은 기계어였을 소스 차이" 후보인지 적습니다.
4. 산출: `09_validation/reconstruction/m3-m68k-diag-20261009.json`(덩어리·07 줄·분류·참고 위치), 계획에 결과 표. 다음 절의 시험 가설 목록을 이 결과로 정합니다.
해석 규칙: 진단은 가설 후보만 냅니다. 참고 소스 원문은 기록에 옮기지 않습니다.

### 428.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 네 객체의 `__text` 는 V10(§414)과 K427(§427) 사이에 바뀌지 않음(ip_icmp 는 파일 동일, 나머지는 절 바이트 동일, 재배치는 기호 번호만 다름 — 이름으로 바꾸면 같음; 바뀐 것은 `struct lock`·`utask` STABS) → §414 의 V10 목록을 그대로 쓸 수 있어 원격 otool 불필요 | 도구에서 절 바이트·이름 바꾼 재배치 동일을 assert | ✅ 1 단계를 "V10 = K427 동일성 확인 + §414 목록 재사용" 으로 대체 |
| `N_SLINE`(0x44)의 값은 절 기준 주소, `desc` 가 줄; `N_FUN` 은 그 함수의 SLINE 뒤에 옴; `N_SOL` 로 파일이 바뀜(tcp_input 의 `queue.h`); 같은 주소 여러 줄; 코드 없는 문장(`HTONS`)은 SLINE 없음 | 도구에서 주소 범위로 줄을 붙이고 파일은 N_SO/N_SOL 순서로 | ✅ |
| `norm_span` 은 주소를 돌려주지 않고 점프 표를 `.long` 으로 펼쳐 difflib 색인이 목록 색인과 어긋남 | `m0_m68k_cause.py` 의 `norm_span` 반환값(명령·메모뿐) 확인 | ✅ 새 도구에 주소를 함께 내는 사본 함수를 둠(§414 도구는 그대로) |
| 분류에 "아키텍처 전용 소스 블록 누락"(예: `_uname` 은 m68k 에서 `machine_type` 을 0–9 점프 표로 나눠 `NeXT_CUBE`… 문자열을 냄) 과 "결과적 차이"(표 주소·분기 길이·옮겨진 정적 함수·저장 레지스터) 를 더할 것 — §414.3 의 "`_uname` 레지스터 배정" 은 부정확 | 원본 문자열표에 `NeXT_CUBE`·`NeXT_WARP9`·`NeXT_X15`·`NeXT_WARP9C`·`NeXT_Turbo`·`NeXT_TurboC`·`NeXT_TurboCube`·`NeXT_TurboCubeC`(grep), `_machine_type` 0x40b61ac 기호 확인; 07 `kern_uname.c:51` 은 `machine_slot[0].cpu_subtype` 의 i386 값 switch | ✅ 분류 추가, §414.3 의 `_uname` 서술 정정 |
| 덩어리 원인 후보(ip_icmp 539 행 조건 안 대입 꼴, tcp_input 260 행 `HTONS` 재대입, tcp_mss 1465 행 식 꼴, vfs_dnlc 정적 도우미 인라인) | 도구 출력으로 다시 얻어 확인 | ⏭️→ 도구 결과로 |
| vfs_dnlc 고침은 x86 과 공유하는 소스를 건드림 — `inline` 은 GNU 확장이라 GCC27 문서상 cc-744.13 탐침과 x86 재빌드 확인 필요 | `08_build/GCC27_COMPATIBILITY.md` 36–37 행(GNU 확장은 확인한 형태만) | ✅ 다음 계획의 주의점으로 기록 |
| 이름 없는 정적 함수가 원본 구간에 들어 있어(`_dnlc_purge1` 402 = 54 + 176 + 172) 차이를 정적 함수별로 나눠야 함 | §424 함수 표로 나눔 | ✅ |
| 참고 출처 표시: icmp 후보는 Darwin(APSL, D022 구조만), tcp_input 은 NeXTMach, uname 상수 4·5·8·9 는 참고 소스에 없음 → SDK 머리 출처 필요 | 설계 | ✅ 기록 |

### 428.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-diag-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_diag.py`(assert: 네 객체의 V10 과 K427 이 절 바이트·이름 바꾼 재배치까지 같음 → §414 의 V10 실기 목록 재사용, 원격 실행 없음). 다른 외부 구간 9 개의 차이 덩어리를 주소·07 줄과 함께 뽑았습니다.

| 객체·함수 | 덩어리(07 줄) | 분류 | 비고(참고 위치) |
|---|---|---|---|
| `ip_icmp` `_icmp_sendMaskPacket` | 1(`ip_icmp.c:539`) | 소스 문장 꼴(x86 에서는 같은 기계어) | 객체는 메모리→메모리 `movel`, 원본은 d0 를 거침 — m68k 의 항등 `htonl` 에서 대입과 검사를 한 식으로 쓴 꼴 후보(Darwin `kernel/bsd/netinet/ip_icmp.c:744`, NeXTMach 에는 이 함수 없음; 07 은 작성본 plan 170) |
| `kern_uname` `_uname` | 16(`kern_uname.c:35–61`) | **아키텍처 전용 소스 블록 누락** + 결과적 레지스터 배정 | 원본은 `machine_type`(0x40b61ac, 바이트)을 0–9 점프 표로 나눠 `NeXT_CUBE`·`NeXT_WARP9`·`NeXT_X15`·`NeXT_WARP9C`·`NeXT_Turbo`·`NeXT_TurboC`·`NeXT_TurboCube`·`NeXT_TurboCubeC`·`Unknown` 을 냄; 07 은 i386 `cpu_subtype` switch(51 행). 레지스터 차이(a2/a3/a4)는 그 결과 — **§414.3 의 "`_uname` 레지스터 배정" 서술은 부정확**. 값 4·5·8·9 는 참고 소스에 없음(SDK 머리 필요) |
| `tcp_input` `_tcp_input` | 1 + 결과 2(`tcp_input.c:259–260`) | 매크로 꼴(`HTONS`) | 원본은 `ti_len` 을 한 번 더 저장(`HTONS` 가 대입형); 나머지 2 덩어리는 점프 표 주소 4 B 밀림. 후보: NeXTMach `netinet/tcp_input.c:228–229`(명시적 재대입) 또는 대입형 `HTONS` 정의 |
| `tcp_input` `_tcp_mss` | 1(`tcp_input.c:1465`) | 소스 식 꼴 | 객체는 `offer` 를 다시 0 확장, 원본은 재사용 — 07 의 `if (offer && mss > offer) mss = offer;` 와 다른 꼴 후보(미정) |
| `vfs_dnlc` 5 함수 | 25(`vfs_dnlc.c:118–131`, 171–178, 219–225, 278–296, 323…) | **인라인 판단(소스 키워드)** + 결과적 저장 레지스터·옮겨진 정적 함수 | 객체는 정적 도우미(`__text+0/42/74/110`)를 부르고, 원본은 펼침. §414 V11(`-O3`)에서 일부만 같았던 것과 함께, 도우미에만 인라인 지정이 있고 `-O2` 인 꼴이 후보(NeXTMach `bsd/vfs_dnlc.c:446`·`461` 참고). `inline` 은 GNU 확장이므로 GCC27 문서상 탐침과 x86 재빌드 확인 필요 |

판단: 남은 4 객체의 차이는 컴파일러 판이 아니라 **소스 쪽**입니다 — m68k 전용 블록 1(`_uname`), x86 에서 보이지 않는 소스·매크로 꼴 3(`ip_icmp`·`tcp_input` 둘), 인라인 지정 1(`vfs_dnlc`). 이것들은 M5(공통부)에서 07 의 판별 덮어쓰기(D064) 후보로 다루며, x86 바이트 동일성 관문을 함께 지켜야 합니다.
M3(머리·구성)로서의 46 객체 범위 결과는 OBJECT_MATCH 42/46 에서 정리합니다. 07·기존 도구·x86 표는 바꾸지 않았습니다.

## 429. M3-5 세부 계획 — 지금까지의 m68k 구성으로 이름 대응 공통부 208 객체를 컴파일·대조(07·기존 표 변경 없음; 코딩 전, 2026-10-09)

배경: §413–427 은 강하게 고른 46 객체로 m68k 플래그·구성 후보(`-g -O2`, `-fwritable-strings` 없음, `DRIVERKIT 0`, 인라인 spl, `GDB 1`)를 찾았습니다. 이를 더 넓은 범위에 적용해 (a) m68k 로 컴파일되지 않는 07 소스·빠진 m68k 머리(M3 작업 목록), (b) 컴파일되는 것의 원본 일치 정도를 잽니다.

확인한 사실(이번 세션, python): §415 `m68k-text-objects.tsv` 의 contiguous 237 객체 중 소스가 `.c` 이고 `i386/` 디렉터리 밖인 것 208(46 포함), 모두 `s6l4-g1a` 의 컴파일 줄이 있음.

방법(새 도구 `10_tools/reconstruction/m3_m68k_wide.py`):
1. 명령: 208 객체마다 s6l4 줄에서 `-arch i386` → `m68k`, 최적화 부분을 V10 플래그(`-g -O2`, `-fwritable-strings` 뺌)로, 출력 `stage/W429__BASE.o`. 스테이징은 `m0p427-stage`(바꾸지 않음).
2. 실기 run `m3p429-cc1`. 실패한 명령이 있으면 run 은 게시되지 않으므로, 그 run 의 `stage/_log`(게시 전 로그)를 **진단으로만** 읽어 실패 원인을 분류(빠진 머리 파일·i386 전용 구문·기타)하고 기록한 뒤, 실패 객체를 뺀 명령으로 run `m3p429-cc2` 를 만들어 게시합니다. 진단 로그는 근거 파일로 쓰지 않고 실패 목록·사유만 기록.
3. 게시된 run 의 객체를 원본과 대조(§414 도구 함수: L1 + 외부 구간 같음), 46 객체 부분이 §427 결과와 같은지 확인(재현).
4. 산출: `09_validation/reconstruction/m3-m68k-wide-20261009.json`(실패 객체·사유 분류, 성공 객체의 판정, 디렉터리별 집계), 상세는 무시 대상 `08_build/artifacts/m3p429/`.
해석 규칙(미리 정함): 실패는 "m68k 에 없는 머리·구성"(M3) 또는 "i386 전용 소스"(M4/M5) 의 작업 목록이지 결함 판정이 아님. 일치는 이 구성에서의 측정이며, 일치하지 않는 객체의 원인은 이번에 가르지 않음.

### 429.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 208 맞음, 모두 s6l4 컴파일 줄 하나; 최적화 낱말이 208 줄 모두 `-g -O3 -fno-omit-frame-pointer` 로 같아 치환이 잘 정의됨(-D/-I 집합은 16 가지 — x86 의 파일별 정의를 그대로 씀) | 도구에서 assert(줄마다 치환 대상 1 회) | ✅ 기록에 "-D/-I 는 x86 메이크 파일 정의" 라 적음 |
| 46 부분 명령은 §427 명령과 `-o` 앞까지 같음 → 재현 확인은 파일 SHA 같음으로 | 도구에서 assert | ✅ |
| **예측: 120 실패·88 컴파일** — 스테이징 `src/machdep/machine/*.h` 는 `__ppc__`·`__i386__` 밖이면 `#error architecture not supported`(예 `pmap.h:28–34`)이고 `machdep/m68k` 가 없음; 공유 머리 `kern/zalloc.h:73`·`vm/pmap.h:129`·`kern/processor.h:76`·`kern/thread.h:82` 등이 무조건 가져옴 | `pmap.h:28–34` 읽음, `ls machdep` = `i386 machine ppc` | ✅ 실행 전에 예측으로 고정. 실패는 첫 오류 줄로 분류, 실패 묶음은 "machdep/m68k 없음(커널 내부 머리, SDK 에 없음)" 한 작업 항목 |
| kr_run 은 실패해도 모든 명령을 돌리고 `output.manifest`·`DONE` 을 쓰며, `collect` 만 거부 — 로그는 `runs/<ID>/stage/_log/` 에 남음; 진단으로 읽을 때 `output.manifest` 해시로 대조할 것 | `kr_run.py:245–262` 읽음(로그 줄·manifest·DONE) | ✅ 해시 대조 후 진단으로만 |
| 46 밖 객체의 외부 기호 이름 규칙 필요 — x86 객체의 외부 `__text` 기호; `ufs_alloc`(`_verify_and_swap_cg`)·`ufs_dir`(`_brelse_and_swap`) 은 m68k 원본에 없는 i386 바이트 교환 도우미를 무조건 가짐 → NOT_MATCH 예상(M5 "공유 파일 안 i386 전용 소스") | m68k `symbols.tsv`: 두 이름 0 | ✅ 규칙 정하고 두 객체 표시 |
| 46 밖 42 중 11 은 1997 i386 조각에서도 NOT_MATCH, 10 은 등급 P → m68k 결과를 따로 보고 | §409 기록에서 도구가 표시 | ✅ |
| 이름 대응이 m68k 전용 소스를 가릴 수 있음(§428 `kern_uname`, `subr_prf`·`kern_xxx`·`miniMon` 등) | 설계 | ✅ 알려진 것은 표시 |
| 88 객체에 `-M` 을 더하면 M3 머리 목록에 쓸모 | 설계 | ✅ cc2 에 `-M` 추가 |
| 디렉터리 집계는 컴파일된 88 기준(ipc·vm 은 전부 실패 예상)이라고 명시 | 설계 | ✅ |

### 429.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-wide-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_wide.py`. 스테이징 `m0p427-stage`(그대로). 실기 도구 12 경로 해시 run 전후 같음.

- run `m3p429-cc1`(208 명령, 게시 안 됨 — 진단으로만; 로그는 그 run 의 `output.manifest` 해시와 대조): **예측과 정확히 같게 실패 120·컴파일 88**, 실패 120 은 모두 첫 오류가 `src/src/machdep/machine/*.h` 의 `#error architecture not supported`(machspl 43·pmap 42·ast 29·xpr 5·time_stamp 1). → M3 작업 항목: **m68k `machdep/m68k` 커널 내부 머리(SDK 에 없음)** — machspl·pmap·ast·ast_types·thread·timer·mach_param·xpr·time_stamp. ipc·vm 은 전부 이 이유로 실패.
- run `m3p429-cc2`(컴파일되는 88 + `-M` 88, 176 명령 종료 0·게시). §427 46 부분은 K427 객체와 **파일 SHA 46/46 같음**(재현).
- 원본 대조(88): OBJECT_MATCH **69**, 함수 MATCH 507·MATCH_UNVERIFIED 25·DIFF 9, MATCH 바이트 82,388/120,544(68.35 %), 외부 구간 같음 526/567.
  새 42: OBJECT_MATCH 27. 그중 1997 i386 조각에서도 OBJECT_MATCH 이고 등급 A 인 31 은 **27 OBJECT_MATCH**(MATCH 바이트 67.75 %); 나머지 11(i386 조각 NOT_MATCH 또는 등급 P)은 따로 표시.
  디렉터리별(OBJECT_MATCH/컴파일): mach 10/10, bsd/nfs 4/4, bsd/rpc 17/19, bsd/kern 17/21, bsd/net 8/9, kern 3/4, bsd/netinet 8/16, bsd/ufs 2/4, bsd/specfs 0/1.
- 새로 NOT_MATCH 15: `ufs_alloc`·`ufs_dir`(i386 바이트 교환 도우미가 07 에 무조건 있음 — 원본 m68k 에 그 기호 없음, M5), `in_pcb`·`ip_output`·`subr_prf`·`if_ether`·`igmp`·`in`·`ip_input`·`miniMon`·`netif`·`spec_vfsops`·`svc`·`tty_pty`·`xdr`(원인은 이번에 가르지 않음; 뒤 9 는 i386 조각에서도 NOT_MATCH 또는 등급 P).

판단: 지금까지의 m68k 구성으로 이름 대응 공통부 C 소스 208 중 88 이 컴파일되고 그 78 %(69)가 원본과 객체 전체가 같습니다. 컴파일되지 않는 120 은 모두 m68k `machdep` 머리 부재라는 한 가지 이유이므로, 다음 M3 항목은 **m68k `machdep/machine` 머리 9 개의 근거 있는 m68k 판**입니다(참고: NeXTMach mk-108.1 `next/*.h`, 원본 바이트로 확인). 07·x86 표는 바꾸지 않았습니다.

## 430. M3-6 세부 계획 — m68k `machdep` 머리를 시험 스테이징에 두고 공통부 120 객체를 컴파일·대조(07 변경 없음; 측정만, 코딩 전, 2026-10-09)

배경: §429 의 120 객체는 모두 `machdep/machine/*.h` 의 `#error`(m68k 분기 없음)로 실패했습니다. 07 의 `machdep/machine/*.h` 는 Darwin 0.1 원문 그대로의 배정 머리(PROVENANCE 50–52 행 등)이고 m68k 머리가 없습니다. 07 을 고치기 전에 **시험 스테이징에서만** m68k 머리를 두어, 어떤 내용이 원본과 맞는지 측정합니다.

확인한 사실(이번 세션, 읽기 전용):
- 첫 오류 머리: machspl·pmap·ast·xpr·time_stamp(§429.2). i386 판 크기: machspl 62 행(`typedef int spl_t`), ast 44(`AST_FP_EXTEN`·`MACHINE_AST_PER_THREAD`), xpr 99(DriverKit 머리 4 개를 가져옴 — m68k 는 `DRIVERKIT 0`), time_stamp 42(`TS_FORMAT TS_FORMAT_NeXT`), mach_param 56(`HZ 100`), pmap 157, thread 187, timer 84.
- `kern/processor.h:75–77` 는 `NCPUS > 1` 일 때만 `machine/ast_types.h` 를 가져오므로 m68k(`NCPUS 1`)에는 필요 없음.
- NeXTMach mk-108.1 `next/` 에 pmap.h 243·ast.h 63·thread.h 19·timer.h 9·xpr.h 39·time_stamp.h 21·pcb.h 72 행; machspl·mach_param 은 없음. `next/param.h:5` `HZ 64`.
- 원본 m68k: `_hz` = 64, `_tick` = 15625(`__data` 값, python) — `HZ 64` 와 맞음.

방법(새 도구 `10_tools/reconstruction/m3_m68k_machdep.py`):
1. 시험 스테이징 `08_build/runs/tools/m0p430-stage` = `m0p427-stage` + 새 디렉터리 `src/machdep/m68k/` 의 머리들 + `src/machdep/machine/*.h` 의 배정 머리에 **i386 분기 뒤** `#elif defined(__m68k__)` 분기 추가(i386 쪽 줄 번호를 바꾸지 않음). 모두 시험 스테이징 안에서만.
2. m68k 머리 내용(머리마다 출처·근거를 매니페스트와 계획에 적음):
   - machspl: `typedef int spl_t`(i386 과 같은 형 — 근거는 컴파일 대조로 확인), time_stamp: `TS_FORMAT_NeXT`(NeXTMach `next/time_stamp.h` 와 대조), mach_param: `HZ 64`(원본 `_hz`·`_tick`),
   - ast·xpr·timer·thread·pmap: NeXTMach `next/<같은 이름>.h` 를 바탕으로 하되 1997 의 공유 머리가 요구하는 이름(i386 판이 정의하는 매크로·형·구조체 이름)을 갖추도록 최소로 맞춤 — i386 판과 NeXTMach 판의 정의 이름 목록을 python 으로 비교해 빠진 것을 표로.
3. 실기 run(측정용, 실패 가능): 120 객체 컴파일. 실패는 §429 와 같이 진단으로만 읽고 첫 오류로 분류; 머리를 고쳐 다시(반복마다 새 run ID, 바꾼 내용을 계획에 기록). 반복은 최대 3 회로 미리 정함.
4. 컴파일되는 객체를 원본과 대조(§429 도구 함수). 결과: 컴파일 수, OBJECT_MATCH 수, 디렉터리별, 그리고 머리별 "원본과 맞는 근거"(구조체 변위가 원본과 같은 함수 수 등).
5. 산출: `09_validation/reconstruction/m3-m68k-machdep-20261009.json`, 상세는 무시 대상 `08_build/artifacts/m3p430/`.
해석 규칙(미리 정함): 이 머리들은 측정용 후보이며 07 에 넣는 것은 별도 계획(출처·라이선스 기록, x86 회귀 관문 포함)입니다. NeXTMach 원문은 시험 스테이징에만 두고 기록에는 경로·줄만 적습니다.

### 430.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 120 객체가 실제로 닿는 배정 머리는 7: machspl 119·pmap 117·thread 99·ast 99·mach_param 16·xpr 12·time_stamp 7; `timer.h` 는 `STAT_TIME` 이 아닐 때만(`kern/timer.h:95`, `generated/stat_time.h` = `STAT_TIME 1`), `ast_types.h` 는 `NCPUS > 1` 때만 | `stat_time.h`·`timer.h:95` 읽음 | ✅ 대상 7 머리로 줄임(9 는 과함) |
| **조용한 불일치 위험**: m68k 원본에 `_splx`·`_splsched`·`_spl0`·`_pcb_synch`·`_pcb_common_init`·`_pcb_common_terminate`·`_event_get` 기호가 없음 → 형 선언만 두면 이 이름들이 외부 함수 호출로 컴파일되어 원본과 어긋남 | `symbols.tsv` grep: m68k 0·x86 1 씩 | ✅ machspl 은 인라인 spl 을 가져오고, `pcb_synch`·`pcb_common_init`·`pcb_common_terminate` 는 빈 매크로, 객체마다 **미정의 외부 기호가 원본 기호표에 있는지** 검사를 첫 반복부터 |
| `PMAP_ACTIVATE`/`DEACTIVATE` 는 m68k 에서 pmap 을 건드리지 않아야 함(`_setup_main` 에 `_kernel_pmap` 참조 없음; `_pmove_crp` 는 문맥 전환에서만) | `_pmove_crp` m68k 1·x86 0 확인; `_setup_main` 참조는 도구에서 셈 | ⚖️ 빈 매크로로 시험 |
| `MACHINE_AST_PER_THREAD` 는 정의하지 않음(m68k 본문에 해당 상수 없음); NeXTMach `next/ast.h` 는 07 `kern/ast.h` 와 충돌하므로 바탕으로 쓰지 않음 | 설계 | ✅ m68k ast.h 는 가드만 |
| `USER_REGS`: 원본 `_init_task` 는 `thread->pcb`(+0x24)에서 +0x4c 를 검사하고 +0x48 을 씀, 아니면 `_thread_user_state` 호출 — i386·NeXTMach 어느 꼴도 아님(D024 작성 필요) | 목록 `_init_task` 9–12 행(`0x24`·`0x4c`·`0x48`) 읽음, `_thread_user_state` m68k 1 | ✅ 시험용 작성 꼴(구조체 앞부분을 바이트 근거 변위로만 둠, 07 반영 아님) |
| `HZ` 64(`_hz`·`_tick`), `TS_FORMAT_NeXT` 양쪽 같음 | 앞서 확인 | ✅ |
| `XPR_TIMESTAMP` 는 `kern_server.c:989` 에서 XPR 밖으로 쓰이며, m68k 에 `_event_get` 은 없고 `_eventc_latch` 등이 있음 → NeXTMach `next/eventc.h:88` 의 인라인 `event_get` 이 필요; `kern/time_stamp.c:55–57·68–76` 의 `m68k` 분기도 `machdep/m68k/eventc.h` 를 요구 | `_eventc_latch` m68k 1·x86 0 | ✅ 시험 스테이징에 NeXTMach `eventc.h` 를 **실행 때 01_resources 에서 복사**(도구 원문에 옮기지 않음 — 참고 코드 비공개 원칙)하고 가져오기 줄만 m68k 경로로 바꿈 |
| `pmap` 구조체: 120 이 쓰는 것은 `pmap_resident_count` 뿐, 원본 `_task_info` 에서 pmap+0x10 — i386·NeXTMach 배치 모두 0x10 이라 판별되지 않음; NeXTMach `pmap.h:186–197` 의 잠정 정의는 쓰지 말 것 | 설계(변위는 도구에서) | ✅ 시험용 최소 pmap(통계 위치 0x10)과 `pmap_t`·`PMAP_NULL`·`pmap_resident_count` |
| `__m68k__`·`m68k` 가 미리 정의됨(§412 `m0p412-abi1/out/_log/31.err`) — 맨 `m68k` 는 공유 코드의 m68k 분기도 켬 | `31.err` grep: `-Dm68k`·`-D__m68k__` | ✅ 배정 머리 분기는 `__m68k__`, 공유 코드 분기는 실행 결과로 드러남 |
| 반복 상한 3 은 좋으나 오류 줄은 첫 줄만이 아니라 객체별 전부를 분류 | 설계 | ✅ |

고친 방법: 2' 시험 머리 7(machspl: `typedef int spl_t` + `bsd/m68k/spl.h` 가져오기; pmap: 시험용 최소 구조체·`pmap_t`·`PMAP_NULL`·`pmap_resident_count`·빈 `PMAP_ACTIVATE/DEACTIVATE`; thread: `pcb_t`·시험용 `USER_REGS`·빈 `pcb_synch`/`pcb_common_init`/`pcb_common_terminate`; ast: 가드만; mach_param: `HZ 64`; xpr: `XPR_TIMESTAMP event_get()` + `machdep/m68k/eventc.h`; time_stamp: `TS_FORMAT_NeXT`) + `machdep/m68k/eventc.h`(NeXTMach 원문을 실행 때 복사·가져오기 줄 치환).
작성한 짧은 머리 본문은 도구에 두되 참고 원문은 도구에 넣지 않음. 4' 검사: 컴파일된 객체마다 미정의 외부 기호 ⊆ m68k 원본 기호(COMMON 제외), 오류는 객체별 전부 분류.

### 430.2 반복 기록(2026-10-09)

- 반복 1(스테이징 `m0p430-stage-1`, run `m3p430-it1`, 게시 안 됨 — 로그는 `output.manifest` 해시 대조 후 진단으로만): **120 중 116 컴파일**, 실패 4:
  `kern/mfs_prim.c:167` `machine_info` 선언 없음(i386 에서는 `machdep/i386/xpr.h` 의 DriverKit 머리 사슬로 `mach/machine.h` 가 들어옴 — s6l4 `-M` 순서), `bsd/kern/mach_process.c:170`·`bsd/kern/kern_exec.c:482` `PC` 선언 없음(i386 레지스터 색인 이름 — 공유 파일 안 i386 전용 소스, M5),
  `kern/ns_timer.c:43·47·147·150` i386 인라인 어셈블리 `divl`(m68k 어셈블러가 거부 — 공유 파일 안 i386 전용 소스, M5).
- 반복 2 계획: 시험용 m68k `xpr.h` 에 `#import <mach/machine.h>` 추가(선언만, 코드 영향 없음), 소스 쪽 실패 3 은 명령에서 빼고(목록 기록) 117 객체로 게시 가능한 run 을 만듦.

### 430.3 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-machdep-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_machdep.py`(시험 머리 7 + `eventc.h` 는 시험 스테이징에만; NeXTMach 원문은 실행 때 복사하고 도구 원문에 넣지 않음). 반복 2 = 스테이징 `m0p430-stage-2`, run `m3p430-it2`(117 명령 종료 0·게시).
실기 도구 해시: 이번 두 run 의 실행 전 목록은 받지 않았고(누락), 실행 뒤 목록이 §429 실행 뒤 목록과 같음을 확인했습니다.

- **컴파일 117/120**(소스 쪽 3 은 §430.2 대로 제외: `PC` 2·i386 `divl` 1). `machdep` 머리 부재로 막혔던 객체가 거의 모두 컴파일됩니다.
- 원본 대조: **OBJECT_MATCH 71/117**, 함수 MATCH 1,117·MATCH_UNVERIFIED 51·DIFF 35, MATCH 바이트 174,742/274,828(63.58 %), 외부 구간 같음 1,166/1,243.
  깨끗한 집합(1997 i386 조각 OBJECT_MATCH·등급 A) 98 중 71. 디렉터리별(OBJECT_MATCH/컴파일): **ipc 18/18**, mach 4/4, specfs 3/3, mach_debug 1/1, kern 18/34, bsd/kern 14/24, vm 8/13, kernserv 2/4, bsd/ufs 0/5, bsd/nfs 0/4, 그 밖 소수.
- **미정의 외부 기호가 원본에 없는 객체 6**(조용한 불일치 검사): `ufs_inode`·`ufs_vfsops`·`ufs_vnodeops`(i386 바이트 교환 함수 `_byte_swap_*`), `kern_shutdown`(`_us_spin`), `init_main`(`__objcInit`·`_objc_setClassHandler`·`_autoconf`·`_kmEnableAnimation`), `kern_server`(`_objc_registerModule`·`_objc_unregisterModule`) — 모두 공유 파일 안의 i386/DriverKit 전용 소스(M5 목록). 시험 머리의 spl·`pcb_*`·`event_get` 은 이 검사에 걸리지 않음(원본에 없는 기호를 부르지 않음).
- 깨끗한 집합에서 아직 다른 27: `vm_pager`·`time_stamp`·`ipc_sched`·`vm_fault`·`vm_pageout`·`task`·`thread`·`sched_prim`·`mfs_prim`·`ast`·`nfs_client`·`kern_fork`·`cmu_syscalls`·`ufs_dsort`·`ufs_subr`·`kern_exit`·`ufs_inode`·`ufs_vfsops`·`ufs_vnodeops`·`kern_shutdown`·`kern_sig`·`init_main`·`kern_clock`·`vm_kern`·`kdp`·`ipc_mig`·`kern_server`(원인은 이번에 가르지 않음 — 시험 머리 내용·구성·소스 중 무엇인지 다음 진단 대상).

판단: m68k `machdep` 머리 7 개(시험판)만으로 막혔던 120 중 117 이 컴파일되고 71 이 원본과 객체 전체가 같습니다. 이 머리 내용(spl 형·인라인 spl·빈 `PMAP_ACTIVATE`·빈 `pcb_*`·`HZ 64`·`event_get` 인라인)은 07 에 넣을 **후보**이며, 넣는 일은 출처·라이선스(NeXTMach `eventc.h` 는 D013 기록 필요)와 x86 회귀 관문을 포함한 별도 계획으로 합니다.
M3 누계: §429 의 88 + 이번 117 = 이름 대응 공통부 C 소스 205/208 이 m68k 로 컴파일되고, 그중 140(69 + 71)이 OBJECT_MATCH. 07·x86 표는 바꾸지 않았습니다.

## 431. M3-7 세부 계획 — §430 의 깨끗한 집합 중 다른 27 객체(외부 구간 41)의 명령 수준 진단(07 변경 없음; 진단만, 2026-10-09)

배경: §430 시험 머리로 컴파일한 객체 중 1997 i386 조각에서 OBJECT_MATCH 이고 등급 A 인 98 중 27 이 아직 다릅니다(외부 구간 41 개 다름). 시험 머리 내용(구조체 변위·매크로)이 원인인지, 구성·소스 쪽인지를 가려야 07 반영 전에 머리를 고칠 수 있습니다.

방법(새 도구 `10_tools/reconstruction/m3_m68k_diag2.py`; §428 도구의 함수 `norm_with_addr`·`lines_of` 를 가져다 씀):
1. 실기 `/bin/otool -tv`(읽기 전용 gcds 스크립트)로 run `m3p430-it2` 의 27 객체를 풀어 무시 대상 `08_build/artifacts/m3p431/otool/` 에 둠(원본 목록은 §414 의 것, SHA 대조). 스크립트는 실기에서 산출 파일의 `krsha256` 도 남김.
2. 다른 외부 구간 41 개마다 정규화·difflib 덩어리·주소·07 줄(§428 방식). 덩어리 자동 분류: D(변위·즉치만 — 차이값 목록), R(레지스터만), O(순서만), CALL(한쪽만 `bsr`/`jsr` 외부 호출 — 인라인·매크로 후보, 호출 이름 기록), X(그 밖).
3. 묶음 집계: 같은 변위 차이(예 +4)가 여러 함수에 반복되면 그 구조체·필드 후보를 객체 STABS(구조체 정의)로 찾아 "시험 머리 내용 요인" 후보로 적음; CALL 덩어리의 호출 이름이 원본 기호표에 없으면 "인라인·매크로 요인" 후보.
4. 산출: `09_validation/reconstruction/m3-m68k-diag2-20261009.json`, 계획에 요약 표(요인 후보별 객체·구간 수). 다음 절의 시험 머리 수정 목록을 이 결과로 정함.
해석 규칙: 진단은 후보만 냄. 참고 소스 원문은 기록에 옮기지 않음.

### 431.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

검토자는 capstone 과 바이트 비교로 41 구간을 미리 분류해 왔습니다(근거로 쓰지 않음 — 실기 otool 목록으로 다시 얻음). 사실 주장 검증:

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본에만 있는 `aston`/`astoff` 덩어리(`movea.l _active_threads,a0; movea.l $24(a0),a0; bset/bclr #4,$54(a0)`)가 10 구간의 주원인 — 원본 전체에 aston 서명 14·astoff 6 | 원본 바이트에서 서명 `2079 040b5648 2068 0024 08e8/08a8 0004 0054` 를 python 으로 셈: 14·6 | ✅ (구간 수는 도구에서) |
| `_need_ast`(0x40b6064)는 원본에 있음; 07 `kern/ast.c:74–85` 의 초기화 고리는 `#ifndef MACHINE_AST` 일 때만 | `symbols.tsv`·`ast.c` 그 줄 읽음 | ✅ → m68k 는 `MACHINE_AST` 정의 + `aston`/`astoff` 매크로(pcb +0x54 비트 0x10) 후보. §430 의 "ast.h 는 가드만" 시험 머리는 바이트와 어긋남(내 판단 오류) |
| `SIMPLE_CLOCK` — 원본에 `_sched_usec`·`_sched_usec_elapsed`·`_clock_value` 있음, 스테이징 `generated/simple_clock.h` 는 0 | `symbols.tsv`·`simple_clock.h` 확인 | ✅ m68k 구성 후보 `SIMPLE_CLOCK 1`(그러면 §430.2 에서 뺀 `ns_timer.c` 가 필요) |
| PMON 계측(`_pmonlogevent`·`_pmon_flags`)이 원본 `_vm_fault`·`_vm_pageout_scan` 에 있음; 07 에는 pmon 코드 없음 | 두 기호가 원본에 있음 | ✅ 소스 쪽 후보 |
| `ufs_dsort` 는 원본 `#$2600`(IPL 6 = `spldma`), 07 `ufs_dsort.c:597` 은 `splbio`(i386 선택, plan 206.1) | `spl.h` 의 `IPLDMA 6`·`IPLBIO 3`, `ufs_dsort.c:595–598` 읽음 | ✅ 소스 조건 쪽 |
| 구간 3(`_vm_pager_has_page`·`_vm_set_error`·`_locc`)은 원본 범위를 다음 이름 있는 기호까지 잰 탓(정적 함수에 이름 없음) — §416 경계로 끊어야 함 | 도구에서 §418 경계로 다시 잼 | ✅ |
| 분류 개선: 정규화 서명으로 삽입·삭제 덩어리를 묶기(aston 덩어리는 호출이 없어 CALL 로 안 잡힘), CALL 을 양방향(원본에만 있는 호출 포함), D 를 프레임(a6)·구조체 변위(a6 밖)·즉치로 나누기, 구간마다 우선 분류 하나 | 설계 | ✅ |
| 시험 머리 구조체 배치는 이 41 구간의 원인으로 보이지 않음(a6 밖 변위 차이 없음, `sizeof(thread)` 388·`sizeof(task)` 128 일치) | 도구에서 D-구조체 수를 셈 | ⏭️→ 도구 결과로 |
| 시험 `struct pcb` 는 0x50 B 인데 원본은 +0x54 를 씀 | 설계 | ✅ 다음 시험 머리 수정 목록에 |

고친 방법: 1' 실기 otool 목록(그대로). 2' 구간 끝은 §418 경계(결정이면 그 값, 아니면 다음 외부 기호), 덩어리 분류 = INS/DEL(정규화 서명으로 함수 사이 묶음)·CALL(양방향, 호출 이름과 쪽)·D-struct·D-frame·IMM·R·O·X, 구간마다 우선 분류. 3' 서명이 같은 덩어리 묶음과 원본에만 있는 호출 목록으로 요인 후보를 정리.

### 431.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-diag2-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_diag2.py`. 실기 `otool -tv`(읽기 전용) 로 27 객체를 풀었고, 실기 `krsha256` 목록과 객체 SHA 를 대조했습니다. 41 구간의 덩어리 분류(구간마다 우선 분류): CALL 19·INS 12·DEL 2·X 3·IMM 1·R 1, **구조체 변위 차이(D-struct) 0**.

| 요인 후보 | 구간 | 근거(도구 출력) |
|---|---|---|
| 구간 끝 측정 탓(원본 정적 함수에 이름 없음) | 3(`_vm_pager_has_page`·`_vm_set_error`·`_locc`) | §418 경계로 끊으면 같아짐 |
| **`MACHINE_AST`**: 원본에만 `aston`/`astoff`(`movel _active_threads,…; movel R@(0x24),R; bset/bclr #4,R@(0x54)`) | 11(`_thread_handoff`·`_task_suspend`·`_thread_terminate`·`_thread_suspend`·`_thread_invoke`·`_thread_block_with_continuation`·`_thread_setrun`·`_ast_check`·`_psignal`·`_hardclock` + `_ast_init` — 객체에만 `need_ast` 초기화 고리) | INS 서명 묶음 4 종, 원본 전체 서명 수 aston 14·astoff 6 |
| **`SIMPLE_CLOCK`**: 원본에만 `_sched_usec`·`_sched_usec_elapsed` 사용 | 3(`_thread_info`·`_sched_init`·`_recompute_priorities`; `_hardclock` 의 `_clock_value` 경로도) | 원본에만 있는 호출·참조 |
| PMON 계측(`_pmonlogevent`·`_pmonlogcontextflush`·`_pmon_flags`) | 2(`_vm_fault`·`_vm_pageout_scan`) | 원본에만 있는 호출 각 3 |
| spl 수준·`eventc` 꼴 | 3(`_disksort_first`·`_disksort_remove` 는 원본 `#0x2600`=`spldma`, `_kern_timestamp`) | IMM·INS |
| i386·DriverKit·ObjC 소스(M5) | 7(`_iget`·`_iupdat`·`_sbupdate`(`_byte_swap_*`), `_main`·`_cinit`(ObjC·`autoconf`·`kmEnableAnimation`·정적 `classHandler`), `_kern_serv_load_objc`·`_kern_serv_shutdown`) | 객체에만 있는 호출 |
| 그 밖 소스·코드 생성 | 12(`_vm_pager_deallocate`·`_mfs_init`·`_nfs_attrcache_va`·`_switch_unix_context`·`_table`·`_bufstats`·`_do_exit`·`_kmem_alloc`·`_kmem_alloc_wired`·`_kmem_alloc_zone`·`_kdp_packet`·`_msg_rpc`) | 원인은 덩어리별 기록에 둠 |

판단: §430 시험 머리의 구조체 배치는 이 41 구간의 원인이 아닙니다(D-struct 0). 가장 큰 요인은 **m68k 구성 `MACHINE_AST`(pcb +0x54 비트 0x10 의 `aston`/`astoff`)** 와 **`SIMPLE_CLOCK 1`** — 둘 다 머리·구성 쪽이므로 다음 시험 대상입니다(§430 의 "ast.h 는 가드만" 은 바이트와 어긋난 내 판단이었고, 시험 `struct pcb` 는 +0x54 를 품도록 넓혀야 함).
나머지는 소스 쪽(PMON 계측, `spldma`, `kmem_alloc_prim` 인자 수, `_do_exit` 의 m68k 전용 호출 등)과 M5 항목입니다. 07·x86 표는 바꾸지 않았습니다.

## 432. M3-8 세부 계획 — m68k 구성 `MACHINE_AST`(pcb +0x54 비트 0x10)와 `SIMPLE_CLOCK 1` 을 시험 스테이징에서 재컴파일로 시험(07 변경 없음; 코딩 전, 2026-10-09)

배경: §431.2 의 주요인 두 가지. 원본에서 확인한 사실: `aston` 서명 14·`astoff` 서명 6(`movel _active_threads,R; movel R@(0x24),R; bset/bclr #4,R@(0x54)`), `_need_ast` 는 원본에 있고 `_ast_init` 은 빈 함수, `_sched_usec`·`_sched_usec_elapsed`·`_clock_value` 가 원본에 있음.
07 `kern/ast.h` 는 `MACHINE_AST` 가 정의되면 `aston`/`astoff` 를 기계 머리에 맡기고(정의 안 되면 빈 매크로), `kern/ast.c:74–85` 의 `need_ast` 정의·초기화 고리는 `#ifndef MACHINE_AST` 일 때만입니다. NeXTMach `next/pcb.h` 는 `u_char pcb_flags` 와 `AST_SCHEDULE 0x8`(1990) — 1997 원본은 비트 0x10.

방법(도구 `10_tools/reconstruction/m3_m68k_ast.py`):
1. 시험 스테이징 `m0p432-stage` = `m0p430-stage-2` + (a) 시험 `machdep/m68k/ast.h`: `MACHINE_AST` 정의, `aston(mycpu)`/`astoff(mycpu)` = `current_thread()->pcb->pcb_flags` 의 0x10 켜기/끄기(시험용 작성), (b) 시험 `machdep/m68k/thread.h` 의 `struct pcb` 를 +0x54 의 `u_char pcb_flags` 까지 넓힘(+0x48·+0x4c 는 그대로), (c) `generated/simple_clock.h` 를 `SIMPLE_CLOCK 1`. 07 은 바꾸지 않음.
2. 실기 run: §430 반복 2 의 117 객체를 그대로(명령 같음, 출력 이름만 바꿈). 실패하면 진단으로만 읽고 기록.
3. 미리 정한 예측·대조군: 예측 — `MACHINE_AST` 11 구간(§431.2 표)과 `SIMPLE_CLOCK` 3 구간이 같아짐(`_hardclock` 은 `_clock_value` 경로가 07 에 없어 남을 수 있음), `ast` 객체의 `need_ast` 는 미정의 참조로 바뀜(원본 기호에 있음 — 미정의 검사 통과); 대조군 — `kern/ast.h`·`simple_clock.h`·`machdep/m68k/thread.h` 를 거치지 않는 객체는 비 STABS 절 동일; 잃은 것(§430 OBJECT_MATCH·함수 MATCH·구간) 0.
4. 산출: `09_validation/reconstruction/m3-m68k-ast-20261009.json`, 상세 `08_build/artifacts/m3p432/`.
해석: 통과하면 `MACHINE_AST`(비트 0x10)·`SIMPLE_CLOCK 1` 을 m68k 구성·머리 후보로 기록. 어긋나면 결론 없이 덩어리로 적음.

### 432.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **`u_char pcb_flags |= 0x10` 은 `bset` 이 아니라 `orb` 가 됨** — 원본 `_tcp_output` 의 `u_char t_flags |= 0x10` 은 `orb #0x10,a2@(0x1b)`; 우리 m68k 객체의 `int p_flag |= 0x200000` 은 `bset #5,a0@(0x29)`(바이트 오프셋 = 3 − 비트/8) → 원본 `bset #4,a0@(0x54)` 는 +0x54 의 **32 비트 필드에 0x10000000** | 원본 목록 45281 행 `orb #0x10,a2@(0x1b:w)`, `m3p431/otool/…kern_clock.txt:17` `bset #5,a0@(0x29:w)`, `proc.h:559` `SOWEUPC 0x00200000` 읽음 | ✅ **내 계획의 `u_char` 가 틀림** — 시험 머리를 `int pcb_flags`(+0x54, 0x50–0x53 채움 명시)·0x10000000 으로, `u_char` 꼴은 미리 정한 음성 대조(예측: `orb`/`andb`, 구간 다름) |
| 원본의 +0x54 비트 연산 사이트: `bset #4` 14·`bclr #4` 6, 모두 `movel _active_threads,a0; movel a0@(0x24),a0` 뒤; 그 밖 같은 필드에 `#6`·`#7`·`#3` 도 있음(32 비트 필드 정황) | 원본 목록 python: (bset #4) 14·(bclr #4) 6·#6 6·#7 2·#3 1 | ✅ |
| `current_thread()` = `active_threads[cpu_number()]`, `cpu_number()` = 0 | 설계(컴파일 결과로 확인) | ⏭️→ 실행으로 |
| `SIMPLE_CLOCK` 사용: `kern/sched.h:244–251`(extern), `sched_prim.c:111–113·229–231·1154–1168`, `thread.c:1640–1646`; `sched_usec_elapsed` 는 선언 없이 암묵 선언(경고만); `_hardclock` 의 `_clock_value` 경로는 07 에 없음 | 07 grep: `sched.h` 2·`sched_prim.c` 8·`thread.c` 2 줄 | ✅ |
| **대조군 정의 결함**: 모든 컴파일이 `-imacros meta_features.h` 로 `simple_clock.h` 를 가져오고 `kern/ast.h`·`thread.h` 도 대부분이 거치므로 "거치지 않는 객체" 는 거의 없음 → 소스의 토큰 사용으로 정의: 바뀔 7(`kern_clock`·`kern_sig`·`ast`·`ipc_sched`·`sched_prim`·`task`·`thread`), 나머지 110 은 비 STABS 절 동일 | 설계(도구에서 토큰 grep 으로 다시 정하고 assert) | ✅ |
| `_need_ast` 는 원본 `__common`(section 6) — 정의 객체를 원본에서 알 수 없음; `MACHINE_AST` 면 `ast.o` 는 미정의 참조(원본 기호에 있음) — 07 링크 때 m68k 전용 객체가 정의해야 함 | 설계 | ✅ 07 후속 항목으로 기록 |
| 사이트 수는 소스 매크로 수와 다를 수 있음(교차 점프) — 함수별 사이트 수로 대조 | 설계 | ✅ 기록에 함수별 bset/bclr 수 |
| `aston` 은 `mycpu` 를 쓰지 않음 | 설계 | ✅ |

고친 방법: 1' 시험 `machdep/m68k/thread.h` 의 `struct pcb` 는 +0x50–0x53 채움 + `+0x54 int pcb_flags`, `ast.h` 는 `MACHINE_AST` + `aston`/`astoff` = `current_thread()->pcb->pcb_flags |=/&= ~0x10000000`. 음성 대조 스테이징은 같은 위치 `u_char` + 0x10.
2' run 둘: 본 시험 117, 음성 대조(바뀔 7 객체만). 3' 대조군 = 토큰 사용이 없는 110 객체(비 STABS 절이 §430 과 같아야 함), 예측 = §431 의 `MACHINE_AST` 11·`SIMPLE_CLOCK` 3 구간 중 `_hardclock` 밖이 같아짐, 음성 대조는 `orb`/`andb` 로 다름.

### 432.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-ast-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_ast.py`. 시험 스테이징 `m0p432-stage-int`(본 시험)·`m0p432-stage-uchar`(음성 대조). 실기 run `m3p432-int`(117 명령)·`m3p432-uchar`(바뀔 수 있는 8 객체) 모두 종료 0·게시, 도구 12 경로 해시 run 전후 같음.

- 바뀔 수 있는 객체(소스 토큰 기준, 미리 정함) 8: `ast`·`ipc_sched`·`kern_clock`·`kern_sig`·`kern_synch`·`sched_prim`·`task`·`thread`. **대조군 109 은 절 바이트·이름으로 바꾼 재배치까지 §430 과 같음(위반 0)** — 처음 비교는 재배치의 기호 번호(STABS 변화로 밀림)를 그대로 비교해 76 을 잘못 "바뀜" 으로 셌고, 이름 기준으로 고쳐 다시 셈.
- **예측 맞음**: `MACHINE_AST` 구간 11 중 10 이 같아짐(`_hardclock` 은 07 에 없는 `_clock_value` 경로 때문에 남음 — 예측대로), `SIMPLE_CLOCK` 구간 3 모두 같아짐. OBJECT_MATCH 71 → **77**(+`ast`·`ipc_sched`·`kern_sig`·`sched_prim`·`task`·`thread`), **잃은 것 0**.
- **음성 대조**(`u_char` + 0x10): aston/astoff 구간 10 이 모두 다름(`_ast_init` 은 aston 을 쓰지 않아 같음) — 예측대로. 32 비트 필드가 맞는 꼴이라는 판별 근거.

판단: m68k 구성·머리 후보 `MACHINE_AST`(pcb +0x54 의 32 비트 `pcb_flags`, 0x10000000 의 `aston`/`astoff`)와 `SIMPLE_CLOCK 1` 을 기록합니다(역사적 확정 아님; NeXTMach 1990 의 `u_char`·0x8 과 다름).
07 후속 항목: `need_ast` 정의 객체(원본 `__common`, m68k 전용 쪽), 아키텍처별 생성 구성(`simple_clock.h` 는 x86 0·m68k 1), `_hardclock` 의 `_clock_value` 경로. M3 누계: 공통부 C 205/208 컴파일, OBJECT_MATCH 69 + 77 = 146. 07·x86 표는 바꾸지 않았습니다.

## 433. M3-9 세부 계획 — m68k 구성·머리 후보를 D068 의 덮어쓰기 트리 `07_kernel/v183.34/m68k/` 에 넣고 같은 결과를 재현(x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §425–432 의 m68k 구성·머리 후보는 시험 스테이징에만 있습니다. D068(판+아키텍처 트리)·D069(인라인 spl 은 m68k `machspl.h` 에서, SDK 사본은 고치지 않음)에 따라 07 에 넣습니다.

넣을 파일(모두 새 파일, `07_kernel/v183.34/m68k/` 아래 07 과 같은 경로):
- `generated/driverkit.h`(`DRIVERKIT 0`, §425), `generated/gdb.h`(`GDB 1`, §427), `generated/iplmeas.h`(`NIPLMEAS 0`, §426), `generated/simple_clock.h`(`SIMPLE_CLOCK 1`, §432) — 생성 구성의 m68k 값(근거 절 표기).
- `src/machdep/machine/{machspl,pmap,thread,ast,mach_param,xpr,time_stamp}.h` — m68k 빌드에서 07 본 트리의 Darwin 배정 머리 대신 쓰이는 프로젝트 작성 배정 머리(`#include "machdep/m68k/<이름>.h"` 한 줄; Darwin 원문을 복사하지 않음).
- `src/machdep/m68k/{machspl,pmap,thread,ast,mach_param,xpr,time_stamp}.h` — §430–432 시험 머리의 확정판(작성, D024: 원본 바이트 근거 — `_hz`·`_tick`, `_init_task` 의 +0x48/+0x4c, +0x54 32 비트 `pcb_flags` 0x10000000, `_task_info` 의 pmap+0x10, 원본에 `_spl*`·`_pcb_*`·`_event_get` 기호 없음).
- `src/machdep/m68k/eventc.h` — NeXTMach mk-108.1 `next/eventc.h` 를 원문 그대로 두고 가져오기 3 줄만 m68k 경로로 바꿈(D013: 출처·고지 유지, MODIFICATIONS 기록).
- `v183.34/README.md` — D068 배치와 스테이징 순서 설명.
- 기록: `07_kernel/PROVENANCE.tsv`·`MODIFICATIONS.md` 에 파일마다 행 추가(덧붙이기만).
`subr_kudp`·`if_venip` 의 인라인 spl(§426)은 D069 에 따라 이번에 넣지 않습니다(두 파일이 거치는 BSD 머리가 모두 SDK 사본이라 프로젝트 m68k 머리 경로가 없음 — 소스 쪽 처리는 사용자 확인 뒤).

방법:
1. 새 도구 `10_tools/reconstruction/stage_m68k.py`: m68k 스테이징 = `s6l4-g1a-stage`(x86 과 같은 바탕) + 실기 SDK m68k 머리 사본(로컬, §413) + `07_kernel/v183.34/common/`(지금 비어 있음) + `07_kernel/v183.34/m68k/`(이 순서로 덮어씀). 매니페스트에 파일마다 출처.
2. 재현 시험(미리 정한 기준): 새 스테이징으로 §429 의 88 + §430 의 117 = 205 객체를 컴파일해, 비 STABS 절·이름으로 바꾼 재배치가 시험 run 의 객체(88 은 `m3p429-cc2`, 117 은 `m3p432-int`)와 같아야 함. 예외는 미리 정함: `subr_kudp`·`if_venip`(SDK `machparam.h` 의 spl 가져오기를 넣지 않으므로 함수 호출로 돌아감 — 원본 대조는 §425 상태로 예상)과 `SIMPLE_CLOCK`·`MACHINE_AST` 를 쓰는 88 쪽 객체(§429 는 그 값이 아니었음 — 토큰 기준 목록으로 미리 정함).
3. x86 관문: x86 스테이징 도구(`stage_headers.py`)가 `v183.34/` 를 읽지 않음을 grep 으로 확인하고, x86 스테이징을 다시 만들어 기존 매니페스트와 같음을 확인(x86 트리 파일 변경 0 — `git status` 로 07 본 트리 변경이 기록 파일 덧붙이기뿐임을 확인).
4. 산출: 위 07 파일, `09_validation/reconstruction/m3-m68k-overlay-20261009.json`.
해석: 이 절은 시험 결과를 07 로 옮기는 것뿐이며 새 판정을 하지 않습니다. 재현이 기준대로면 m68k 빌드의 머리·구성은 07 덮어쓰기 트리가 근거가 됩니다.

### 433.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 파일 목록은 완전·최소: 시험 스테이징(`m0p432-stage-int`)과 바탕(`m0p413-stage`)의 차이는 생성 머리 4·배정 머리 7·`machdep/m68k` 8·SDK `machparam.h` 하나 — 계획 목록 + 일부러 뺀 `machparam.h` | 두 매니페스트(`m0p413-stage`·`m0p432-stage-int`)의 파일별 SHA 를 python 으로 비교: 다른 파일 20 개 = `generated/` 4(driverkit·gdb·iplmeas·simple_clock) + `src/machdep/machine/` 7 + `src/machdep/m68k/` 8 + `src/bsd/m68k/machparam.h` 1 | ✅ |
| **계획의 예외 설명이 틀림**: `if_venip` 는 "§425 상태" 로 돌아가는 것이 아니라 `GDB 1` 블록은 유지하고 spl 만 함수 호출로 돌아감; `subr_kudp`·`if_venip` 는 §429 에서 OBJECT_MATCH 였으므로 둘 다 잃고 미정의 검사(원본에 `_spl*` 없음)에도 걸림 → M3 누계 146 → 144 | `m3-m68k-wide-20261009.json` 을 python 으로 읽음: `x86-subr_kudp`·`x86-if_venip` 판정 OBJECT_MATCH(88 쪽, 69/88), 117 쪽(`m3-m68k-machdep`·`m3-m68k-ast`)에는 없음 | ✅ 문구 정정: 이 절은 **두 객체의 일치를 잃는 것을 미리 밝힌 채** 넣음(D069 의 처리 대기) |
| 88 쪽에서 `host`·`mach_factor` 는 `SIMPLE_CLOCK 1` 로 `extern int sched_usec;` 만 더해짐 — 비 STABS 절은 같아야 함 | `m0p427-stage/src/kern/sched.h:62-66` `#ifdef KERNEL_BUILD` 아래 `#include <simple_clock.h>`, 244–251 `#if SIMPLE_CLOCK … extern int sched_usec;`; `m3p429-cc2/run.cmd` host 줄에 `-DKERNEL_BUILD`; `m3p429-cc2` 의 −M 목록(`_log/88.out`·`89.out`)에서 sched.h 를 거치는 것은 host·mach_factor 뿐. 단 −M 목록은 불완전함(host.c:57 `#include <cpus.h>` 가 89.out 에 없음) — 그래서 −M 은 근거에서 빼고, 88 소스 본문(주석 제거)에서 `SIMPLE_CLOCK`·AST 토큰 0 건(python)만 보조로 씀 | ⚖️ 예측으로만 채택(재현 시험이 판정). 예외 목록: 코드 예외는 `subr_kudp`·`if_venip` 둘, `host`·`mach_factor` 는 "토큰 다름·비 STABS 같음 예측", 나머지는 모두 같음 |
| NeXTMach `eventc.h` 는 1 행에 SCCS `(c) 1988 NeXT` 만 있음; git `f6bdb9c…`, 원격 `johnsonjh/NeXTMach`; PROVENANCE 7 열, 수정본 선례(`netbuf.c`: "restoration edit … diff 06_reconstruction/evidence/…")와 원문 선례(`nextmach/sys/table.h`) | 1–3 행·git 정보·두 PROVENANCE 행 읽음 | ✅ eventc.h 는 수정본 꼴 + `06_reconstruction/evidence/m68k-eventc.diff` |
| "작성" 머리들도 NeXTMach·Darwin 식별자를 거의 그대로 씀(`PMAP_CONTEXT`·`pmap_resident_count`·`USER_REGS`·`pmap_phys_address` 꼴 등) → D013 상 식별자별 출처, source_id `authored+nextmach+darwin01`(선례 601 행) | 601 행 읽음 | ✅ |
| 새 경로는 무시 규칙에 걸리지 않아 공개됨(NeXTMach 는 D013 상 가능); SDK m68k 입력은 무시 대상에만 있고 커밋 기록이 없음 → 경로·SHA 를 검증 JSON 에 | `.gitignore` 와 경로는 실행 때 `git check-ignore` 로 확인, SDK 입력은 `m0p413-stage.manifest.json` 의 `sdk_list`·`sdk_list_sha256` 키를 python 으로 읽음 | ✅(check-ignore 는 실행 단계에서) |
| 07 파일마다 PROVENANCE 행을 요구하는 검사기는 없고, `stage_headers.py` 는 07 을 훑지 않음(논리 경로로만 찾음) → x86 스테이징에 영향 없음 | `stage_headers.py:300-324` `select()` 는 `os.path.join(K07, logical)` 만 만들고 논리 경로는 `src/…`·`generated/…` 꼴 — `v183.34/` 로 시작할 수 없음 | ✅ + 실행 때 x86 스테이징 재생성 비교 |
| m68k 생성값을 손으로 쓰면 `config_options.tsv` 단일 출처 원칙(`07_kernel/generated/README`)을 벗어남 → 생성하거나 예외를 문서화 | `07_kernel/generated/README:4` "…config_options.tsv; do not edit them by hand" 열어 읽음 | ⚖️ 이번에는 `v183.34/README.md` 에 예외(값마다 근거 절)를 적고, 생성 도구 확장은 후속 |
| 07 README 의 예약 구조(`src/arch/…`, 8–9 행)와 D068 이 겹침 → README 갱신 | 07 README 6–10 행 읽음 | ✅ README 에 D068 문단 덧붙임(기존 줄은 지우지 않음) |

### 433.2 실행 결과(2026-10-09)

07 에 넣은 파일(모두 새 파일): `07_kernel/v183.34/README.md`, `v183.34/m68k/generated/` 4, `v183.34/m68k/src/machdep/machine/` 7(작성 배정 머리: 자체 가드 + `#include "machdep/m68k/<이름>.h"` 한 줄 — Darwin 배정 머리 원문은 쓰지 않음), `v183.34/m68k/src/machdep/m68k/` 8.
- 출처: `07_kernel/PROVENANCE.tsv` 1048 → 1067 행, `MODIFICATIONS.md` 572 → 591 행(덧붙이기만, 앞부분 그대로임을 확인). NeXTMach 식별자는 파일 머리에 그 파일의 NeXT 저작권 줄(D013), Darwin 0.1 과 같거나 고친 줄은 `(Darwin)` 표시 + 파일 머리에 APSL 고지(D061 선례: `machdep/i386/machdep.c`). 줄 근거(직접 열어 확인): NeXTMach `next/pmap.h:155-160·217-227`, `next/pcb.h:58-62·67`, `next/param.h:5`, `next/xpr.h:18-20`, `next/time_stamp.h:18`; Darwin `machdep/i386/machspl.h:60`, `i386/pmap.h:119-120`, `i386/thread.h:180-185`, `ppc/thread.h:97-98`, `i386/xpr.h:45-47`.
- `eventc.h`: NeXTMach 원문 + 가져오기 3 줄 바꿈(`06_reconstruction/evidence/m68k-eventc.diff`), 근거 표 `06_reconstruction/evidence/m68k-overlay.md`.
- 07 `README.md` 에 D068 문단 덧붙임(21 → 23 행; 예약 구조 줄은 지우지 않음).
- 토큰 사전 검사(python, 주석 제거 후 토큰 비교): 생성 4·`machdep/m68k` 8 이 시험 머리와 토큰이 같고, 배정 머리 7 의 m68k `#include` 가 시험 판과 같음.

도구 `10_tools/reconstruction/stage_m68k.py`(stage·cmd·x86gate·compare). 실행 전후 해시: `08_build/artifacts/m3p433/tools-pre.sha`·`tools-post.sha`(같음). 스테이징 `08_build/runs/tools/m0p433-stage` 는 도구 첫 판(d5c6c8a8…)으로 만들었고, 그 뒤 고친 것은 `x86gate` 부분뿐입니다(아래).
- 스테이징: 887 파일(바탕 + SDK m68k + 덮어쓰기: 바꿈 10, 더함 9). 시험 스테이징 `m0p432-stage-int` 와 SHA 가 다른 파일 15 = `src/bsd/m68k/machparam.h`(일부러 SDK 원본) + 배정 머리 7 + `machdep/m68k` 7(주석만 다름; 생성 4·`eventc.h` 는 바이트까지 같음).
- x86 관문: `s6l4-g*` 7 스테이징을 `stage_headers.py` 와 각 매니페스트의 옵션으로 다시 만들어 매니페스트가 모두 같음(v183.34 경로 0). 첫 시도에서 g5a 가 달랐는데 원인은 제 관문 도구가 g5a 의 `--public-sdk kernserv/queue.h`(계획 293) 옵션을 넘기지 않은 것이었고, 둘째 시도는 변수 이름 겹침으로 g5a 행 이름이 잘못 찍혀 다시 돌렸습니다(시도 산출물 `x86gate-p433-try1`·`-try2` 는 무시 대상에 남김). 기록은 셋째 시도.
- run `m3p433-cc1`(205 명령, 모두 종료 0, 게시 616 파일).
- 비교(`09_validation/reconstruction/m3-m68k-overlay-20261009.json`): 비 STABS 절·이름 재배치가 시험 run 과 같은 것 **203/205**, 다른 것은 미리 정한 예외 `x86-subr_kudp`·`x86-if_venip` 둘뿐(`__TEXT,__text`; 미정의 `_splnet`·`_splx`, `_splimp`·`_splx` — 원본에는 `_spl*` 없음). 바이트까지 같은 것 88(88 쪽 86 + 117 쪽 2; 나머지는 머리 주석 길이로 STABS 줄 번호만 다름). `host`·`mach_factor` 는 바이트까지 같음(§433.1 의 "토큰 다름" 예측은 판정에 영향 없음).
- 원본 대비 OBJECT_MATCH: 146 → **144**(잃은 것은 예외 둘, 얻은 것 없음) — 미리 밝힌 대로.

해석: m68k 빌드의 머리·구성은 이제 07 덮어쓰기 트리가 근거입니다. 남은 차이는 `subr_kudp`·`if_venip` 의 인라인 spl(D069 처리 대기)과 §428–431 의 소스 쪽 항목입니다.

## 434. M3-10 세부 계획 — m68k 생성물(구성 머리·MIG 출력)의 재생성 명령과 해시(07 코드 변경 없음; 코딩 전, 2026-10-09)

배경: M3 의 내용에는 "구성 머리(`gen_config_headers.py` 계열의 옵션 값), 생성 코드(MIG·설정 머리)의 재생성 명령과 해시" 가 있습니다(MULTIARCH 표준 M3). §433 은 m68k 생성 머리 4 개를 손으로 써 `07_kernel/generated/README` 의 단일 출처 원칙에서 벗어났고(예외로 문서화), MIG 출력 17 객체(`exc_server`·`mach_host_server`·`mach_port_server`·`mach_server`·`mach_debug_server`·`kern_server_handler`·`kern_server_reply_user`·`port_*`·`*_special_port`·`vm_deallocate`·`vm_read`)는 `-arch i386` 로 만든 07 파일을 그대로 m68k 로 컴파일했습니다(§433 에서 모두 OBJECT_MATCH).

확인한 사실(이번 세션, 읽기 전용):
- 원본 m68k 기호표에 NeXTMach `next/ipl_meas.c`(`conf/files.NeXT:14` `optional iplmeas`)의 함수 10 개(`_ipl_change`·`_ipl_splu`·`_ipl_spld`·`_ipl_rte`·`_ipl_urte`·`_ipl_intr`·`_intr_call`·`_ipl_open`·`_ipl_read`·`_ipl_ioctl`)가 하나도 없음(python). mk-108.1 `conf/MASTER.next:88` RELEASE 에 `gdb`·`simple_clock`·`hw_ast` 는 있고 `iplmeas` 는 없음(91 행 IPLMEAS 구성에만).
- 원본에 `_sched_usec`·`_sched_usec_elapsed`·`_clock_value`·`_IFCONTROL_SETIPADDRESS`·`_need_ast` 있음(python).
- MIG 입력 중 아키텍처로 갈리는 것은 `mach/machine/machine_types.defs` 의 `ARCH_INCLUDE(mach/, machine_types.defs)` 뿐(5 개 MIG 스테이징의 `.defs` 를 `i386|m68k|ENDIAN|ARCH` 로 grep), 그리고 SDK `mach/i386/machine_types.defs` 와 `mach/m68k/machine_types.defs` 는 바이트까지 같음(`diff` 종료 0).
- `gen_config_headers.py --check` 는 지금 종료 0.

방법:
A. 구성 머리: 새 표 `06_reconstruction/config_options-m68k.tsv`(x86 표와 같은 6 열: option·macro·header·value·status·evidence)에 m68k 에서 x86 과 다른 값 4 행(`driverkit` 0, `gdb` 1, `iplmeas` 0, `simple_clock` 1 — 근거 절·원본 기호). `gen_config_headers.py` 에 `--arch m68k`(그 표를 읽어 `07_kernel/v183.34/m68k/generated/` 에 표의 머리만 씀, `meta_features.h` 는 만들지 않음 — m68k 빌드는 x86 `meta_features.h` 를 그대로 쓰고 `iplmeas.h` 는 `bsd/m68k/spl.h` 가 직접 가져옴; `--check` 지원). 인자 없는 x86 동작은 그대로(수정 전후 `render()` 결과 동일·`--check` 종료 0 을 확인). 생성 결과가 §433 의 4 파일과 바이트까지 같아야 함. `PROVENANCE.tsv`·`MODIFICATIONS.md` 의 그 4 행(§433 에서 쓴 미커밋 행)을 "generated" 로 고치고 행 수가 그대로인지 확인, `v183.34/README.md` 의 예외 문단을 표·명령으로 바꿈.
B. MIG: 새 도구 `10_tools/reconstruction/m3_m68k_generated.py`. 07 MIG 파일을 만든 실기 run 5 개(`s5p348-mig2`·`s5p349-mig1`·`s5p351-mig1`·`s5p361-mig3`·`s5p61-mig-1`)의 입력 스테이징을 무시 대상 새 스테이징으로 복사하고 SDK `mach/m68k/machine_types.defs`(§413 사본, SHA 대조)를 더한 뒤, 07 에 들어간 출력을 만든 명령만 골라 `-arch i386` → `-arch m68k` 로 바꿔 실기에서 다시 실행(새 run ID). 예측(미리 정함): 모든 출력이 07 파일과 바이트까지 같음. 다르면 차이를 진단만 하고 07 은 바꾸지 않음.
C. 기록 `09_validation/reconstruction/m3-m68k-generated-20261009.json`(표·도구 해시, 생성 비교, MIG run·출력 해시·07 대조).
해석: A 는 값의 출처를 표로 옮기는 것뿐이고 값은 바뀌지 않습니다. B 가 예측대로면 m68k 빌드는 07 MIG 출력을 그대로 쓰는 근거(재생성 명령과 해시)가 생깁니다. DriverKit MIG 출력(`EventServer`·`audioServer`·`audioReplyUser`·`driverServerServer`)은 m68k 원본에 그 객체가 없어(§415 `absent`) 대상이 아닙니다.

### 434.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `symbols.tsv` 는 외부 기호만(type 0xf 3808 + 0x3 1) — `ipl_change`·`ipl_traceback` 은 `static`(mk-108.1 `next/ipl_meas.c:66-67`, `:426-427`)이라 없는 것이 근거가 못 됨; 더 강한 근거는 전역 `ipl_meas`·`ipl_debug`(`:60-61`) 부재 | python 으로 type 집계 3809 = 0xf 3808·0x3 1, `_ipl_meas`·`_ipl_debug`·`_ipl_traceback` 0 건; `ipl_meas.c:58-68`·`:424-428` 읽음 | ✅ 근거를 "외부 함수 9 + 전역 2 부재" 로 고침 |
| `MASTER.next:88` RELEASE 에 gdb·simple_clock·hw_ast 있고 iplmeas·driverkit 없음 | §434 작성 때 80–95 행 읽음 | ✅ |
| MIG cpp 경로에 다른 조건부: `mach_host.defs:196 #ifndef NeXT`, `mach_types.defs:142-144 #if KERNEL_SERVER #include <norma_vm.h>`, `mach_debug.defs` 의 `#ifdef MACH_KERNEL`; `__BIG_ENDIAN__`·`__i386__` 검사 없음 | 세 곳 읽음(`mach_host.defs:194-197`, `mach_types.defs:141-145`, `mach_debug.defs:28-34`), `*.defs` grep 0 건 | ✅ 예측 위험: m68k cpp 가 `NeXT` 를 정의하지 않으면 `mach_host_server.c` 가 달라짐 — 실행이 판정. `norma_vm.h` 는 x86 생성 머리(m68k 덮어쓰기 없음) |
| `mig` 는 셸 스크립트: `-arch` 를 받아 `CPP="/lib/${arch}/cpp"` — `-arch m68k` 는 `/lib/m68k/cpp` 를 씀 | `08_build/toolchains/real-i386-20261001/mig` 25·39 행 읽음, sha `6341c61c…` = run `tools.expected` 의 `/usr/bin/mig` | ✅ |
| `kr_run.py` 의 `ALLOWED_TOOLS`(39–41 행)는 `/lib/i386/cpp` 만 해시 — `/lib/m68k/cpp` 는 기록되지 않음 → 실행 전후 해시 필요(§413 `tools-pre/post.txt` 선례, `/lib/m68k/cpp` `5591bbdf…`) | 39–41 행·`tool_hashes()`·`m0p413/tools-pre.txt` 읽음 | ✅ 실기 `krsha256` 로 실행 전후 해시를 run 산출 옆에 남기고 JSON 에 적음 |
| 07 에 들어간 출력과 명령: s5p348 RUN 1–4, s5p349 RUN 1, s5p351 RUNIN 1(`kern_server_handler.c`)·RUN 2(`kern_server_handler.h`)·RUN 3(`kern_server_reply_user.c`), s5p361 `migi`(14), s5p61 RUN 1–2(`generated/mach/memory_object_*.h`); r_·n_ 반복은 같음 | 5 run `out/` 과 07 파일 SHA 를 python 으로 대조(출력 그대로) | ✅ 계획 대상에 머리 3 개(`kern_server_handler.h`, `memory_object_user.h`·`memory_object_default.h`) 추가. 방법: 원래 `run.cmd` 전체(r_·n_ 포함 — `-nostdinc` 판이 닫힘 증명)를 `-arch i386` → `-arch m68k` 로만 바꿈 |
| `iplmeas.h` 는 `bsd/m68k/spl.h:23` 과 `kernserv/m68k/spl.h:21` 둘이 가져옴; m68k 스테이징 `meta_features.h` = 07 것(sha `13deaf59…`), `iplmeas` 가져오기 없음 | 두 spl.h grep(§434 작성 때 23·21 행), sha256sum 두 파일 같음, grep 0 | ✅ 문구 정정 |
| 상태 어휘: 생성기는 hypothesis·confirmed 만, undetermined 는 건너뜀; x86 표는 "CONFIRMED by bytes" 에만 confirmed | `gen_config_headers.py:25-28`, 표 3·6·10·18·19·22·23·54 행 confirmed, 13·15·17 undetermined 확인(awk) | ✅ driverkit 0·simple_clock 1 → confirmed(§425.2·§432.2 객체), gdb 1 → confirmed(§427 run `m3p427-cc1` 의 `if_venip` OBJECT_MATCH 를 근거로 명시; §433 에서는 D069 로 잃었음을 함께 적음), iplmeas 0 → hypothesis(부재·RELEASE 태그만, 바이트 시험 없음) |
| "x86 과 다른 값 4 행" 은 iplmeas 에 틀림(x86 표·생성 머리에 없음) | 표 grep 0, `07_kernel/generated/iplmeas.h` 없음 | ✅ 문구: "x86 과 다르거나 x86 에 없는 값" |
| 기본 x86 동작 위험 낮음 — 다른 호출자 없음, m68k 경로는 `render()`(meta 추가)와 x86 OUT 쓰기 앞에서 갈라야 함 | 설계(도구에서 x86 `render()` 전후 같음 + `--check` 종료 0 확인) | ✅ |
| MIG 출력에 경로·날짜 없음, r_·n_ 반복 같음 → 결정적 | r_·n_ 동일은 위 SHA 대조 출력 | ✅ |
| 실효 m68k 구성 = x86 표 + m68k 덮어쓰기 표 — 문서화; DRIVERKIT 에서 파생된 다른 값(mach_ldebug 17 행 등) 재확인은 후속 | 17 행 읽음(undetermined) | ⚖️ README 에 규칙을 적고, 파생 값 재확인은 후속 항목으로 |

### 434.2 실행 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-generated-20261009.json`

A. 구성 머리:
- 새 표 `06_reconstruction/config_options-m68k.tsv`(4 행: driverkit 0·gdb 1·simple_clock 1 은 confirmed, iplmeas 0 은 hypothesis — §434.1 판정대로).
- `gen_config_headers.py --arch m68k [--check]`: 표의 머리만 `07_kernel/v183.34/m68k/generated/` 에 쓰고, `meta_features.h` 는 만들지 않습니다.
- 확인:
  - 수정 전후 x86 `render()` 결과 51 파일의 해시가 같습니다(`08_build/artifacts/m3p434/x86-render-pre.json`).
  - x86 `--check` 와 `--arch m68k --check` 가 모두 종료 0 입니다.
  - 쓰기 모드로 다시 만든 4 파일은 §433 판과 SHA 가 같습니다.
  - 모르는 인자(`--arch sparc`, `--bogus`)는 거부합니다.
- 기록 수정(행 수는 그대로입니다):
  - `PROVENANCE.tsv`·`MODIFICATIONS.md` 의 해당 4 행을 x86 생성 행 꼴로 고쳤습니다(source_id `generated`, 도구·표). 1067·591 행이고, HEAD 대비 변경은 19 행 추가뿐입니다.
  - `v183.34/README.md` 의 예외 문단은 생성 명령·실효 구성 규칙(x86 표 + m68k 덮어쓰기)·상태 표로 바꿨습니다.
  - `07_kernel/generated/README` 에는 3 줄을 덧붙였습니다.

B. MIG:
- 도구 `10_tools/reconstruction/m3_m68k_generated.py`.
  - 스테이징과 명령은 첫 판(c2c00bf4…)으로 만들었습니다. 그 뒤에는 비교 부분만 고쳤습니다(`run.json` 제외, 구성·도구 해시 기록 추가). 기록은 마지막 판(222c8b77…)이고, 실행 전후 해시는 `08_build/artifacts/m3p434/tools-pre.sha` 에 있습니다.
- 스테이징 5 개 `08_build/runs/tools/m0p434-<run>-stage` = 원래 MIG 입력(매니페스트 SHA 대조) + SDK `mach/m68k/machine_types.defs`.
- run `m3p434-mig1`–`mig5` 의 명령 29 개는 원래 run 의 `run.cmd` 에서 `-arch i386` → `-arch m68k` 만 바꾼 것이고, 모두 종료 0·게시되었습니다.
- 실기 도구 해시(`/lib/m68k/cpp` `5591bbdf…` = §413 기록, `/lib/i386/cpp`, `/usr/bin/mig`, `migcom`, `migcom3`)는 실행 전후가 같습니다(`mtools-pre/post.txt`).
- 결과:
  - 원래 run 출력 249 개(`run.json` 제외)가 모두 `-arch m68k` 출력과 바이트까지 같습니다. 빠지거나 더해진 것은 0 입니다.
  - 07 에 들어간 MIG 파일 24 개도 모두 같습니다: `*_server.c` 5, `kern_server_handler.c`·`.h`, `kern_server_reply_user.c`, 루틴별 14, `generated/mach/memory_object_{user,default}.h`.
  - `mach_host.defs:196 #ifndef NeXT` 걱정과 달리 출력이 같으므로, m68k cpp 도 `NeXT` 를 정의하는 것과 결과가 맞습니다.

해석:
- m68k 빌드의 생성물 근거가 갖춰졌습니다. 구성 머리는 표와 명령으로 만들고, MIG 출력은 07 파일을 그대로 쓰며 `-arch m68k` 재생성과 같음을 확인했습니다.
- M3 끝 조건 가운데 "생성 코드" 부분은 m68k 공통부 범위에서 채워졌습니다. 남은 후속 항목은 DRIVERKIT 에서 파생된 값(예: `mach_ldebug`)의 m68k 재확인과 SPARC 입니다.

## 435. M3-11 세부 계획 — D070: `subr_kudp`·`if_venip` 의 m68k 판이 `<machine/spl.h>` 를 가져오게 해 인라인 spl 회복(x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §433 에서 두 객체만 SDK `machparam.h` 의 spl 가져오기(§426 시험)가 빠져 함수 호출로 돌아갔습니다(OBJECT_MATCH 146 → 144). D070 으로 두 소스의 m68k 판이 직접 가져옵니다.

확인한 사실(이번 세션, 읽기 전용):
- §433 run `m3p433-cc1` 의 205 객체 중 미정의 `_spl*` 를 가진 것은 이 둘뿐(`subr_kudp`: `_splnet`·`_splx`, `if_venip`: `_splimp`·`_splx`; python). 원본 m68k 에는 `_spl*` 기호 없음(§426).
- §426 시험은 SDK `bsd/m68k/machparam.h` 21 행(`#if KERNEL` 블록)에 `#import <bsd/m68k/spl.h>` 한 줄(diff 출력). 이 머리는 `sys/param.h:48` `#include <machine/machparam.h>` 로 들어옴.
- 스테이징의 `bsd/machine/spl.h` 는 SDK 배정 머리(`ARCH_INCLUDE(bsd/, spl.h)` → `bsd/m68k/spl.h` → `kernserv/m68k/spl.h`).
- 두 소스는 `#import <sys/param.h>` 를 `subr_kudp.c:11`, `if_venip.c:20` 에서 가져오고, spl 호출은 `subr_kudp.c:142·146·154`, `if_venip.c:151·171`. 둘 다 07 출처 `nextmach`(PROVENANCE 409·494 행; if_venip 은 복원 수정본).

방법:
1. 07 덮어쓰기 파일 `07_kernel/v183.34/m68k/src/bsd/rpc/subr_kudp.c`·`src/bsd/net/if_venip.c` = 07 본 파일 + `#import <sys/param.h>` 바로 다음 줄 `#import <machine/spl.h>\t/* plan 435 (D070): m68k inline spl */` 하나. diff 는 `06_reconstruction/evidence/m68k-spl-import.diff`. PROVENANCE·MODIFICATIONS 에 2 행씩 덧붙임(출처는 본 파일과 같음 + 수정 1 줄).
2. `stage_m68k.py` 보강: 덮어쓰기 `.c` 가 07 본 파일에서 `plan 435 (D070)` 표시 줄만 더한 것인지 스테이징 때 검사(본 파일이 바뀌면 멈춤). `compare` 의 예외 목록을 절 번호별로(433: 두 객체, 435: 없음) 고름.
3. 새 스테이징 `m0p435-stage`, 205 객체 재컴파일(새 run), 비교 기준(미리 정함): 205/205 가 기준 run(`m3p429-cc2`·`m3p432-int`)과 비 STABS 절·이름 재배치 같음, 두 객체에 미정의 `_spl*` 없음, OBJECT_MATCH 146(두 객체 회복, 잃은 것 0). x86 관문 다시(7 스테이징 매니페스트 불변).
4. 기록 `09_validation/reconstruction/m3-m68k-spl-import-20261009.json`, `v183.34/README.md` 의 "아직 넣지 않은 것" 갱신.
예측 근거: 인라인 spl 정의가 들어오는 위치만 §426 과 다르고(`sys/param.h` 안 → 바로 뒤), 정적 인라인 정의의 순서는 쓰는 함수보다 앞이면 코드에 영향이 없다고 봄 — 실행이 판정.

### 435.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `<machine/spl.h>` 는 m68k 스테이징에서 `bsd/machine/spl.h` → `ARCH_INCLUDE(bsd/, spl.h)` → `bsd/m68k/spl.h` → `kernserv/m68k/spl.h` 로, §426 과 같은 정의에 닿음 | §435 작성 때 스테이징 `bsd/machine/spl.h` 본문 확인(위 사실), 기준 run `m3p429-cc2` 의 입력이 `m0p427-stage` 임을 `prepare.json` grep 으로 확인 | ✅ |
| **계획 문구 오류**: spl 은 "정적 인라인 정의" 가 아니라 문장식(statement-expression) 매크로(`kernserv/m68k/spl.h` 의 `SPLU_MACRO`·`splx`, `splnet()` 등) — 순서 조건은 "첫 사용 전에 정의, 뒤에 함수 선언 없음" | `kernserv/m68k/spl.h:40-60·95-110` 읽음 | ✅ 문구 정정(예측 근거를 매크로 기준으로) |
| m68k 스테이징 머리에 `spl*` 함수 선언·원형 없음; 머리 안 사용은 매크로 안뿐(`sys/mbuf.h:172·190` 등) | 타입+spl 이름 꼴 grep(다른 아키텍처 디렉터리 제외) 0 건, `mbuf.h` grep | ✅ |
| 두 소스에 `__LINE__`·`__FILE__`·`assert` 없음 → 한 줄 끼움은 STABS 줄 번호만 바꿈 | 두 파일 grep 0 건 | ✅ |
| 덮어쓰기 바탕: s6l4-g1a 매니페스트의 두 파일 SHA = 현재 07 파일 | python 대조 True·True | ✅ |
| 파생 검사는 엄격해야 함: 표시 줄 정확히 하나, `#import <sys/param.h>` 바로 다음, 기존 줄 끝에 붙은 표시 거부, 표시 줄을 빼면 07 본 파일과 바이트 같음, 표시 없는 덮어쓰기 `.c` 거부 | 설계 | ✅ 그대로 구현 |
| `stage_m68k.py` 에 433 이 박힌 곳이 예외 말고도 있음(`PFX`, `plan=433` 3 곳, cmd 머리 주석) | grep `433`: 2·16·19·35·89·110·137·181 행 | ✅ `--plan N`(기본 433)으로 매개화: 접두 `O<N>__`, 기록 plan, 예외 목록 |
| `stage_vs_test_stage` 에 두 `.c` 가 더해짐 → 미리 정한 기대에 넣기 | 설계 | ✅ |
| NeXTMach 은 spl 을 `sys/param.h` 안에서 얻음: mk-108.1 `next/machparam.h:14` `#import <next/eventc.h>`, `next/eventc.h:38` `#import <next/spl.h>` — D070 은 위치가 다른 의도적 선택 | 두 줄 읽음 | ✅ 기록에 적음(D069·D070 의 선택; 코드 결과는 실행이 판정) |
| 성공 기준에 "205 객체 전체에 미정의 `_spl*` 0" 을 넣고, 두 객체의 기준 run 을 명시(`m3p429-cc2`), 다르면 진단만 | 설계(§433 에서 미정의 `_spl*` 는 이 둘뿐임을 python 으로 확인) | ✅ |
| PROVENANCE 꼴: source_id `nextmach`, 원 경로 그대로, "restoration edit … plan 435, D070 … derived from 07_kernel/src/… SHA …"; if_venip 은 "authored lines (D024)" 유지 + D070 줄 | 433 의 `eventc.h` 행·409·494 행 형식 확인 | ✅ |

### 435.2 실행 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-spl-import-20261009.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/rpc/subr_kudp.c`(12 행)·`src/bsd/net/if_venip.c`(21 행)에 `#import <machine/spl.h>` 한 줄(diff `06_reconstruction/evidence/m68k-spl-import.diff`). PROVENANCE 1067 → 1069, MODIFICATIONS 591 → 593(덧붙이기만).
- `stage_m68k.py`: `--plan N`(기본 433; 접두 `O<N>__`, 기록 plan, 예외 목록 433: 두 객체 / 435: 없음), 덮어쓰기 `.c` 파생 검사(`check_derived`), 비교 요약에 미정의 `_spl*`. 파생 검사 음성 시험 5 종(표시를 다른 줄 끝에 붙임·위치 옮김·다른 변경·표시 없음·표시 둘) 모두 거부, 정상판 통과. 실행 전 도구 해시 `08_build/artifacts/m3p435/tools-pre.sha`, 실행 뒤 같음.
- 스테이징 `m0p435-stage` 887 파일(덮어쓰기 바꿈 12·더함 9), x86 관문 `s6l4-g*` 7 매니페스트 모두 같음(v183.34 경로 0).
- run `m3p435-cc1`(205 명령 종료 0, 게시 616 파일). 비교: 비 STABS 절·이름 재배치가 기준 run(`m3p429-cc2`·`m3p432-int`)과 같은 것 **205/205**, 바이트까지 같은 것 88, 205 객체 전체 미정의 `_spl*` **0**, OBJECT_MATCH **146**(§433 의 144 에서 `subr_kudp`·`if_venip` 회복, 잃은 것 0). 시험 스테이징 대비 SHA 가 다른 파일 17 = §433 의 15 + 두 `.c`(미리 정한 대로).
해석: D069·D070 으로 m68k 인라인 spl 이 SDK 사본 수정 없이 모두 07 덮어쓰기 트리에서 옵니다. NeXTMach 은 spl 을 `sys/param.h` 안(`next/machparam.h:14` → `next/eventc.h:38`)에서 얻었으므로 가져오는 위치는 원래와 다를 수 있으나, 두 객체의 코드는 같습니다(매크로는 사용 지점에서 펼쳐짐).

## 436. M3-12 세부 계획 — §435 뒤 깨끗한 NOT_MATCH 중 원인을 아직 진단하지 않은 객체의 명령 수준 진단(07 변경 없음; 진단만, 2026-10-09)

배경: §435 의 205 객체 중 NOT_MATCH 는 59, 그중 깨끗한 것(1997 i386 조각 OBJECT_MATCH·등급 A)은 29. 진단된 것: §428 4(`ip_icmp`·`kern_uname`·`tcp_input`·`vfs_dnlc`), `ufs_dir`(i386 도우미), §431 의 21. 남은 3 객체는 §429(88 쪽)에서 새로 컴파일된 것으로 아직 진단하지 않았습니다.

확인한 사실(이번 세션, 읽기 전용, python):
- `x86-in_pcb`(`__text` 1710 B)는 외부 구간 `_in_pcbconnect` 하나만 다르고, `x86-subr_prf`(2868 B)는 `_panic` 하나, `x86-ip_output`(3522 B)은 `_ip_output` 하나만 다릅니다(`m0_m68k_cause.compare_object`). 셋의 L1 은 `__TEXT,__text: unverified`(자리 못 찾음)입니다.
- `x86-kern_shutdown` 의 L1 사유는 `_boot` 의 `symbol _us_spin not in image` 하나뿐 — §430 에 기록된 M5 항목.
- `x86-ufs_vnodeops`: 외부 구간 2 개(`_rdwri`·`_ufs_nlinks`)는 같고, 정적 함수 36 개 중 10 개가 DIFF(2712 B)이며 `__DATA,__data` 참조 4 개가 다릅니다. §430 은 이 객체를 i386 `_byte_swap_*` 호출 객체로 기록했습니다.

방법(새 도구 `10_tools/reconstruction/m3_m68k_diag3.py`; §431 도구의 `kind` 와 §428 도구의 `norm_with_addr`·`lines_of` 를 가져다 씀):
1. 실기 `/bin/otool -tv`(읽기 전용 gcds 스크립트)로 run `m3p435-cc1` 의 `in_pcb`·`subr_prf`·`ip_output`·`ufs_vnodeops` 4 객체를 풀어 무시 대상 `08_build/artifacts/m3p436/otool/` 에 둡니다. 실기 `krsha256` 으로 객체 SHA 도 남깁니다. 원본 목록은 §414 의 것을 SHA 대조해 씁니다.
2. 세 구간은 §431 과 같은 방식으로 다룹니다: 정규화, difflib 덩어리, 분류(CALL·INS·DEL·IMM·D-struct·D-frame·R·X), 07 줄 번호. 구간 끝은 §418 경계로 자릅니다.
3. `ufs_vnodeops`: L1 의 DIFF 함수 10 개(L1 자리 = 외부 기호 `_rdwri` 기준)마다 객체 쪽 호출 이름과 원본 쪽 호출을 대조합니다.
   - 판정: 모든 DIFF 함수에 객체 쪽에만 `_byte_swap_*` 호출이 있고 그 밖의 덩어리가 없으면 "M5 항목만" 으로 둡니다.
   - 그렇지 않으면 그 밖의 덩어리를 나열합니다.
   - `__data` 참조 4 개는 참조 위치와 대상을 적습니다.
4. 산출: `09_validation/reconstruction/m3-m68k-diag3-20261009.json` 과 요약 표(객체·구간별 요인 후보).
해석 규칙: 진단은 후보만 냅니다. 참고 소스 원문은 기록에 옮기지 않고, 07 은 바꾸지 않습니다.

### 436.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·구간 하나씩·`kern_shutdown` `_us_spin`·`ufs_vnodeops` DIFF 10(2712 B)·`__data` 참조 4 는 맞음; 다만 36 함수는 정적 34 + 외부 2(`_rdwri` 도 DIFF) | §436 작성 때 python 출력(심볼 목록에서 외부 E 2 개 `_rdwri`·`_ufs_nlinks`) | ✅ 문구 정정 |
| **`ufs_vnodeops` 의 L1 자리가 54 B 틀림**: `_rdwri` 기준 0x403a020 이 아니라 0x403a056 에서 객체 첫 함수가 시작; 0x403a056 은 §418 경계 k=130(미결정, lower 0x403a04c)의 upper | python: 객체 `__text` 첫 36 B 와 원본 0x403a020 차이 34 B, 0x403a056 차이 0; k=130 행 `decided: False`, upper 0x403a056; k=131(결정) 0x403bff6 까지 원본 8096 B = 객체 8150 − 54 | ✅ 방법 3 을 0x403a056 자리로 고침(L1 자리를 쓰지 않음). 결과는 k=130 경계의 근거 후보로 기록(§418 표는 바꾸지 않음) |
| 54 B 는 `rwip` 의 `byte_swap_dir_block_in/out` 덩어리(+28·+24)와 `move.l` 하나(+2); 나머지 DIFF 9 는 자리·분기 변위 산물, `__data` 참조 4 는 각각 정확히 54 차이 | 도구에서 0x403a056 자리로 전체 정규화 비교 | ⏭️→ 실행으로(아래) |
| `_panic`: 원본은 `_mon_global` 을 읽어 `printf("NeXT ROM Monitor %d.%d v%d\n", …)` 를 더 부름(문자열 0x40a62ad); 07 `subr_prf.c:543` "plan 220: no ROM monitor line", NeXTMach `bsd/subr_prf.c:515-516` 에 그 줄 | 원본 0x40a62ad 32 B 읽음(문자열 일치), 07 530–560 행·NeXTMach grep | ✅ m68k 전용 줄 후보(i386 은 계획 220 에서 그 줄이 없어야 맞음) — 도구에서 덩어리로 확인 |
| `_in_pcbconnect`: 호출 순서 같고, 차이는 계획 166 작성 MULTICAST 블록(`in_pcb.c:239-256`)의 비교 꼴(원본 `movea.l d0,a0; cmpa.l` vs 객체 `cmp.l`) | 07 236–258 행 읽음(계획 166 작성 표시 있음) | ✅ 줄은 맞음; 명령 차이는 도구에서 |
| `_ip_output`: 호출 같고 레지스터 배정 차이(+8 B) | 검토자는 capstone 힌트뿐 | ⏭️→ 실기 otool 목록으로 |
| m68k 에서 `ntohs`·`htons`·`NTOHS`·`HTONS` 등은 `(x)` — 코드 없음 | 아래 도구 결과로 간접 확인(필요 시) | ⏭️ 진단 해석에만 씀 |
| §418 끝 자르기는 이 세 구간에서 쓰이지 않음(`cap.get` 없음) — "검사" 라 부르지 말 것 | 도구에서 capped 여부를 기록 | ✅ |
| 각 후보에 i386 제약(i386 조각 OBJECT_MATCH 유지)을 적을 것 | 설계 | ✅ |

### 436.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-diag3-20261009.json`

도구 `10_tools/reconstruction/m3_m68k_diag3.py`. 실기 `otool -tv` 목록(`08_build/artifacts/m3p436/otool/`, 스크립트 `otool.sh`)과 실기 `krsha256` 의 객체 SHA 를 대조했습니다.
- 첫 실행에서 두 가지를 잘못 잡아 고쳤습니다. 둘 다 같은 run 의 같은 입력을 다시 읽었습니다.
  - 외부 이름을 한 개만 넘겨서 구간이 객체 끝까지 늘어났습니다. §431 처럼 x86 객체의 외부 이름 전부를 넘기도록 고쳤습니다.
  - `__data` 포인터는 "같음" 대신 "차이(shift)" 로 기록하도록 고쳤습니다.
- 도구 해시는 `08_build/artifacts/m3p436/tool-pre.sha` 에 있고, 마지막 판(9392764e…)이 기록과 같습니다.
- §418 끝 자르기는 세 구간 어디에도 쓰이지 않았습니다(`capping_used` false).

| 객체·구간 | 바이트(객체/원본) | 덩어리 | 요인 후보 | i386 제약 |
|---|---|---|---|---|
| `in_pcb` `_in_pcbconnect` | 568 / 570 | INS 1(원본에만 `movel d0,a0`, `in_pcb.c:247-249` = 계획 166 작성 MULTICAST 블록의 `ifp = imo->imo_multicast_ifp` 근처) + R 1 | 작성 블록의 소스 꼴(원본은 `ifp` 를 주소 레지스터로 옮겨 비교) | i386 조각 OBJECT_MATCH 를 유지하는 꼴이어야 함 |
| `subr_prf` `_panic` | 146 / 176 | CALL 1·INS 1·X 4 — 원본에만 `_mon_global` 을 a3 에 읽고 `printf("NeXT ROM Monitor %d.%d v%d\n", +0x30c, +0x30a, +0x312)`(07 줄 543 자리); 나머지 X 는 a3 보존·스택 정리 차이 | **m68k 전용 줄**: NeXTMach `bsd/subr_prf.c:515-516` 의 ROM Monitor `printf` | 07 `subr_prf.c:543` 은 계획 220 에서 i386 원본에 맞춰 그 줄을 뺐음 → m68k 덮어쓰기 후보(D064·D068) |
| `ip_output` `_ip_output` | 1318 / 1326 | R 57·X 12·DEL 1·INS 1, 호출 차이 0 — 원본은 `ro`(a6−20)를 d4 에 두고 쓸 때마다 a1 로 옮김, 객체는 a5; 옵션 포인터 레지스터도 다름(`ip_output.c:106-181`, 324, 351) | 레지스터 배정 — 소스 꼴(선언·임시 변수, 계획 175 작성 부분 포함) 후보 | 같은 |
| `ufs_vnodeops`(원본 0x403a056 부터 k=131 경계 0x403bff6 까지) | 8150 / 8096 | 모두 `_rwip`(`ufs_vnodeops.c:393-402`): `byte_swap_dir_block_in`·`_out` 호출과 그 조건 검사(CALL 2·DEL 1) + `movel d1,d0` 하나(X 1) | **i386 바이트 교환(M5 항목만)** | i386 은 그 호출이 있어야 맞음 → m68k 덮어쓰기 후보 |

- `ufs_vnodeops` 의 `__data` 안 `__text` 포인터는 33 개입니다.
  - `rwip` 앞의 함수 4 개(offset 0·36·46·156)를 가리키는 것은 차이 0 입니다.
  - 나머지 29 개는 모두 −54 이고, 객체의 `rwip` 에 더 있는 54 B 와 맞습니다.
  - 그래서 L1 의 "data 참조 4 다름" 과 DIFF 함수 10 개는 L1 이 `_rdwri` 기준으로 자리를 잡은 데서 생긴 산물입니다(§436.1).
- 객체 첫 36 B 는 원본 0x403a056 과 같고, 0x403a020 과는 34 B 다릅니다.
  - 따라서 이것은 §418 미결정 경계 k=130 을 upper(0x403a056)로 정하는 근거 후보입니다.
  - §418 표는 바꾸지 않았습니다.
- `kern_shutdown` 은 `_us_spin` 하나뿐입니다(§430 M5 항목).

판단:
- 깨끗한 NOT_MATCH 29 개의 원인 후보가 모두 기록되었습니다(§428·§431·§436).
- 이번 셋 가운데 `_panic` 은 m68k 전용 소스 줄(ROM Monitor 줄)이 원인 후보이고, 덮어쓰기 소스로 시험할 수 있습니다.
- `_in_pcbconnect`·`_ip_output` 은 i386 조각을 유지해야 하는 작성 블록의 소스 꼴 문제이며, M5 에서 다룹니다.
- 07·x86 표는 바꾸지 않았습니다.
