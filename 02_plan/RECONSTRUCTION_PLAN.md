# 커널 소스 복원 작업계획

작성 2026-10-01(사용자 결정 D011·D012, 잠정 D013). 이 계획은 코딩 전 codex 교차검토를 거친다(맨 끝 판정표).
기존 [ROADMAP](ROADMAP.md)의 P0–P7 단계를 구체화한 실행 계획이다. 모든 계산은 Python 으로 한다.

## 1. 목표와 판정 수준

대상: `03_original/x86/binaries/mach_kernel` — NeXT Mach 4.2, mk-183.34.4, 1999-01-26, RELEASE_I386,
SHA-256 `33469393…`. SPARC·m68k 는 x86 이후(8 절).

복원 결과는 다섯 수준으로 판정한다. 높은 수준이 낮은 수준을 대신하지 않는다.

| 수준 | 판정 | 증거 |
|---|---|---|
| L0 컴파일 | 모든 번역 단위가 GCC 2.7 계열 NeXT 컴파일러로 컴파일된다 | 게스트(또는 실기)의 전체 빌드 로그·종료 코드·도구 해시 |
| L1 함수 대조 | 함수별 기계어 대조 분류: **일치**(바이트 동일 + 모든 참조의 대상·가산값·종류 일치) / **다름(검토 기록)** / **경계 미확정** / **미비교**. 바이트 수준 분류이며 동작 동등의 증명이 아니다 | 비교 도구 출력(JSON), 분모 = 원본 함수 목록 |
| L1d 데이터 대조 | 초기화 데이터·상수·문자열·함수 포인터 표를 심볼(또는 주소 대응) 단위로 대조 | 비교 도구 출력 |
| L2 링크 | Mach-O 커널로 링크된다. 섹션 크기·외부 심볼 집합을 원본과 비교 | 링크 로그, Python 비교 |
| L3 부팅 | QEMU i386 에서 `--snapshot` 으로 부팅(루트 마운트·init·Workspace), 그다음 실기 | 콘솔 로그, `hostinfo`, GDB |
| L4 회귀 | 파일·프로세스·IPC·드라이버 적재·네트워크 작업 | 시험 스크립트 결과 |

원본 전체와의 바이트 동일은 별도 목표다(D007). 함수 이름 일치나 빌드 성공으로 대신하지 않는다.
성공을 돌려주는 임시 stub 으로 L2·L3 을 통과시키지 않는다. 미해결 함수는 목록으로 남긴다.

## 2. 입력 — 확인한 사실 (2026-10-01, Python 계산)

원본 x86:
- 세그먼트 `__TEXT` 0x100000(892,928 B, `__text` 851,436 B), `__DATA` 0x1da000(122,880 B), `__OBJC` 0x1f8000(73,728 B), `__LINKEDIT`.
- 심볼 3,751 개, 그중 외부 text 심볼(type 0xf, section 1) 2,916 개.
- 분석 자료(FULL_ANALYSIS): Ghidra `full-pass5` 함수 4,761 개 + 분석 조각 492 개(assembly·pseudocode), 경고 884 개. IDA 디컴파일 성공 4,519, 실패 244.
- ObjC(`03_original/x86/inventory/objc.json`): 모듈 76, 클래스 118, 카테고리 40, 메서드 1,137. 모듈 소스 이름 76 개 = 절대 경로 19(driverkit 10, bsd 8, machdep 1) + 상대 이름 57(예: `Kernel/IOConfigTable.m`, `IODevice.m`).
- 원본 심볼 표에는 외부 심볼(type 0xf) 3,651 과 절대 심볼(0x3) 100 만 있고 **로컬 심볼이 없다**. 정적 함수·로컬 데이터로 가는 참조는 이름이 아니라 주소 대응으로 맞춰야 한다.

참고 코드(`01_resources/upstream/`, 모두 원본과 대조 전까지 후보):
- Darwin 0.1: `kernel/`(bsd, conf, driverkit, ipc, kern, kernserv, mach, machdep/{i386,ppc}, vm …, `conf/MASTER.i386`·`files.i386`·`Makefile.template`), `driverkit-1/`, `architecture/`. 라이선스 APSL.
- NeXTMach: `mk-108.1/`(NeXTSTEP 3 계열, next/nextdev 등 m68k 중심) 외 cdrom·kernload·msdos·perf·streams. 라이선스 불명(D013).
- Mach4: CMU 계열.
- 외부 text 심볼 2,916 개 이름과 참고 트리의 함수 정의 이름(정규식, `.h` 포함 — 거친 추정)의 일치: Darwin 0.1 1,887(64.7 %), NeXTMach 1,484(50.9 %), Mach4 743(25.5 %), 합집합 2,360(80.9 %), 어디에도 없음 556. **이름 일치는 후보일 뿐 대응이 아니다.**

도구·환경:
- i386·m68k VM 에 개발자 패키지 설치 완료. `/bin/cc` = NeXT `cc-744.13`, `/lib/{i386,m68k,sparc}/cc1obj` 에 `2.7.2.1` 문자열, `/usr/lib/migcom`, `/bin/make`·`/bin/gnumake`, `/usr/bin/kl_ld`, 헤더 `/NextDeveloper/Headers/{mach,bsd,driverkit,kernserv,architecture,objc,…}`. **실행 확인 전.**
- 시험: QEMU i386(원본은 PIC 수정본으로만 부팅, `hd()mach_kernel.183.34.4.pic`), m68k, SPARC(ESP 경합, `11_emulation/HANDOFF_SPARC_ESP.md`). i386 실기는 원본 커널 운용 중(D012).
- 디스크 조작: `nextufs`(커밋 `6ef2908`) + 검증 `compare_ufs_images.py`·`verify_i386_kernel_add.py`. 읽기 `installed_kernel_identity.py`.

## 3. 방법 — 같은 컴파일러로 맞춰 가는 복원

1. 함수마다 후보 소스를 고른다: Darwin 0.1(i386 머신 의존부·driverkit 이 있는 가장 가까운 계보) → NeXTMach → Mach4 → 없음. 선택 근거(이름, 호출하는 함수 집합, 참조 문자열·상수, 구조체 오프셋)를 기록한다.
2. 후보를 원본에 맞게 고친다. 고친 이유를 원본 바이트·역어셈블 근거와 함께 남긴다. 후보가 없으면 역어셈블·디컴파일을 근거로 새로 쓴다(디컴파일 출력은 가설).
3. 같은 컴파일러·같은 옵션으로 컴파일해 L1 비교를 한다. 차이는 원인(소스 차이 / 옵션 / 헤더·타입 / 인라인·레지스터 배정)으로 분류한다.
4. 채택 판정과 출처를 `06_reconstruction/functions.tsv`·`07_kernel/PROVENANCE.tsv` 에 쓴다.

## 4. 단계

### S0 운영 규칙 (이번에 반영)
- `AGENTS.md`·`FULL_ANALYSIS.md`·`DECISIONS.md` 범위 변경 완료. 라이선스: D013(잠정).
- 산출물 경로: 소스 `07_kernel/`, 판단 `06_reconstruction/`, 빌드 산출물 `08_build/artifacts/`, 검증 `09_validation/reconstruction/`, 도구 `10_tools/reconstruction/`.

### S1 툴체인 확정과 빌드 경로 (P3) — 첫 작업
1. i386 VM 에서 `cc -v`, `cc -arch i386 -v -c`, `as`·`ld`·`migcom` 버전, 각 파일 SHA-256 을 기록한다(`08_build/toolchains/`). 실기에 개발 도구가 있는지 사용자에게 확인한다.
2. probe: C(구조체 배치·정렬·비트필드·호출 규약), Objective-C(클래스·메서드 메타데이터 섹션), `.s`(전처리 포함), MIG(`.defs` → 생성 코드)를 컴파일해 목적 파일을 호스트로 꺼내 Python 으로 검사한다.
3. 빌드 왕복 경로(2026-10-01 사용자 결정): **i386 빌드는 OPENSTEP 실기, 결과물 시험은 QEMU.**
   - 실기는 이 저장소를 NFS 로 `/ndrv/openstep-kernel-remade` 에 마운트하고, 호스트는 `gcds`(`NeXT_DRIVER/bin/gcds`, `GCDS_CONF=etc/gcds.cnf`, 대상 `next`)로 실기 명령을 실행한다(R0–R4 에서 쓴 경로, `10_tools/runtime/build.sh` 가 실기 `cc -O` 로 빌드한 선례). 빌드 입력과 출력이 모두 저장소 안에 있으므로 VM 디스크 왕복이 필요 없다.
   - 3 분 넘는 빌드는 실기에서 `nohup` 으로 분리 실행하고 로그를 저장소에 쓴다. 실기 재부팅·`gcdsd`·`/ndrv` 재마운트는 사용자 몫.
   - 출력은 NFS 캐시·부분 쓰기를 막기 위해 실기에서 `sync` 뒤 SHA-256(또는 `cksum`)을 실기·호스트 양쪽에서 계산해 비교한다.
   - 실기 툴체인이 VM 과 같은지(`/bin/cc`·`/lib/i386/*`·`as`·`ld`·`migcom` 해시)를 먼저 기록한다. 다르면 둘 다 기록하고 기준 툴체인을 정한다.
   - 시험: 결과 커널을 `nextufs` 로 i386 VM 디스크에 새 이름으로 넣고(게이트 검증) `--snapshot` 으로 부팅. 실기 커널 교체 시험은 사용자가 복구 가능한 부트 항목으로 수행.
   - VM 빌드(`nextufs` 로 넣고 게스트에서 빌드)는 실기를 쓸 수 없을 때의 예비 경로로 둔다.
   - **빌드 절차 규약**(codex QR3 반영, 도구는 S1 에서 작성):
     1. 빌드마다 소스를 불변 스냅샷으로 복사한다(`08_build/runs/<id>/src/`, 파일별 SHA-256 manifest). 작업 중인 `07_kernel/` 을 직접 빌드하지 않는다.
     2. 실기에서 먼저 manifest 를 재계산해 입력을 확인한다(경로·파일 종류·심볼릭 링크 대상·모드, 대소문자 충돌 거부).
     3. 빈 출력 디렉터리(`08_build/runs/<id>/stage/`)에 **전체 재빌드**. `make` 의 시각 판단에 기대지 않는다.
     4. 환경 고정: `env -i` 에 가까운 최소 환경, 도구는 절대 경로(`/bin/cc` 등), include 순서 명시, `TZ`·로케일 고정, 사용한 헤더·라이브러리 해시 기록.
     5. 한 번에 한 빌드: 실행 디렉터리의 잠금 파일로 동시 빌드를 막는다(호스트·실기 양쪽에서 확인).
     6. 게시: 빌드 프로세스의 종료 코드 0 과 로그 끝 표시를 확인한 뒤, stage 의 manifest(SHA-256)를 실기에서 만들고 호스트에서 재계산해 같을 때만 `08_build/runs/<id>/out/` 로 옮긴다. 소비자는 `out/` 과 manifest 만 쓴다.
     7. 시험 식별: QEMU 시험은 빌드 manifest 의 커널 해시를 받아 디스크 삽입 게이트를 매개변수로 돌리고(지금 `verify_i386_kernel_add.py` 는 원본 이름·해시가 고정), 부팅한 디스크 이미지 해시와 `boot:` 에 입력한 파일 이름을 시험 기록에 남긴다.
4. 컴파일 옵션 찾기: 참고 소스와 이름·구조가 같은 **작은 C 함수 표본**(예: 10–20 개, 매크로·인라인 의존이 적은 것)을 여러 옵션 조합(`-O`, `-O2`, `-fno-builtin`, `-DKERNEL` 등)으로 컴파일해 L1 비교 점수를 Python 으로 매긴다. 원본 커널을 만든 컴파일러 버전이 `cc-744.13` 과 같은지는 모른다(1999 빌드). 점수가 낮으면 컴파일러 차이를 먼저 의심하고 기록한다.
5. L1 비교 도구(`10_tools/reconstruction/`). 재배치 필드를 **가리지 않고 풀어서** 비교한다(codex QR1 반영):
   - 함수 범위: Ghidra `full-pass5` 경계는 가설. 모든 진입점·도달 블록(떨어진 꼬리 포함)을 원본에서 확인하지 못한 함수는 "경계 미확정" 으로 두고 일치 판정하지 않는다. 정렬 채움으로 보이는 바이트도 도달 여부로 확인한다.
   - 참조: 목적 파일의 재배치(일반·scattered·`SECTDIFF`/`PAIR` 포함)를 해석해 대상 심볼(또는 섹션+오프셋)·가산값·종류·폭을 얻고, 원본의 같은 자리 값이 가리키는 대상(주소 → 심볼, 로컬은 이미 대응시킨 주소)과 비교한다. 지원하지 않는 재배치 형식은 거부한다.
   - 재배치 없는 PC 상대 분기·호출(같은 목적 파일 안 정적 함수·로컬 레이블)도 목적지를 풀어 대응 블록·함수와 비교한다.
   - `__text` 안의 점프 표·리터럴과 함수가 참조하는 표·상수는 비교 범위에 넣고 표의 목적지도 비교한다.
   - 도구 시험: 원본 자기 대조, 일부러 바꾼 입력(호출 대상 교체, 가산값 변경, 표 목적지 변경, 경계 절단)이 모두 "다름" 으로 나오는지.

### S2 계보·구성 지도 (P2)
1. 함수별 후보 대응표: 원본 함수(4,761 + 조각) × 참고 트리. 이름 외 근거(호출 집합·문자열·상수)로 점수. 결과는 `06_reconstruction/functions.tsv`.
2. 목적 파일 경계와 링크 순서 복원: 원본 `__text` 안 함수 주소 순서, 정적 심볼·ObjC 모듈 76 개의 이름과 위치로 원래 `.o` 묶음과 순서를 추정하고, Darwin 0.1 `conf/files.i386`·`Makefile.template` 과 대조한다. 섹션 크기·정렬 틈으로 검증한다.
3. 대응 없는 함수(이름 기준 556 + 정적 함수 + ObjC 메서드)를 서브시스템별로 센다.

### S3 헤더와 타입 (P2→P4)
- 커널 내부 헤더는 Darwin 0.1 에서 출발하고, 설치된 `/NextDeveloper/Headers` 와 원본에서 얻은 구조체 오프셋(`06_reconstruction/types.tsv`)으로 맞춘다. 구조체마다 크기·필드 오프셋을 probe 로 확인한다(S1-2 방식).
- ObjC 클래스는 원본 `__OBJC` 메타데이터(클래스 118, 인스턴스 변수, 메서드 형식 문자열)가 기준이다.

### S4 빌드 골격
- Darwin 0.1 `conf/` 방식(MASTER·files·Makefile.template)을 기준으로 i386 구성을 만든다. MIG 생성물은 게스트 `migcom` 으로 만든다.
- 링크 명령·세그먼트 주소(`__TEXT` 0x100000 등)·링크 순서(S2-2)를 원본과 맞춘다.

### S5 서브시스템 복원 (P4)
순서(ROADMAP 과 같음): 기반 헤더·타입 → 머신 의존부(locore, trap/interrupt, pmap, context, FPU, clock) → Mach 공통(스케줄러·잠금, IPC, VM) → BSD(syscall, VFS/UFS, 네트워크) → DriverKit·커널 서버 로더. 서브시스템마다 L0 전부, L1 분류 완료를 끝 조건으로 한다. 진행률은 **함수 수·바이트 수 두 분모**로 Python 집계한다.

### S6 링크·부팅·회귀 (P5)
- 첫 전체 링크 뒤 L2 비교. QEMU i386 부팅은 원본과 같은 PIC 결함 때문에 원본 그대로의 복원 커널은 IDE 가 잠긴다. 소스는 원본 동작을 유지하고, QEMU 시험용으로만 같은 12 바이트 수정을 적용한 변형을 따로 만든다(수정 적용 도구·해시 기록). 실기는 원래 동작으로 시험한다.
- 부팅은 항상 새 이름의 커널 파일 + `--snapshot`, 실기는 사용자가 복구 가능한 부트 항목으로.

### S7 이후 아키텍처
- SPARC·m68k 는 x86 의 공통부 결과를 쓰되 각자 원본(`03_original/{sparc,m68k}`)으로 L1 을 다시 한다. SPARC 시험은 ESP 경합 대응 뒤.

## 5. 기록 규칙

- 원본 사실 / 디컴파일 해석 / 참고 코드 후보 / 복원 구현 / 검증 결과를 파일과 열로 분리한다.
- 함수마다: 원본 주소 범위, 후보 출처(트리·경로·revision), 채택 근거, L1 분류, 남은 차이.
- 파일마다 `PROVENANCE.tsv`: 출처, revision/SHA-256, 원 경로, 라이선스, 변경 요약.
- NeXTMach 에서 옮긴 텍스트는 공개 커밋 금지(D013 결정 전).

## 6. 위험과 미지수

| 항목 | 영향 | 대응 |
|---|---|---|
| 원본을 만든 컴파일러 버전·옵션 불명 | L1 동일 비율이 낮을 수 있음 | S1-4 에서 먼저 측정. 낮으면 "다름(검토)" 분류로 진행하고 원인 기록 |
| 참고 코드와 원본 버전 차이(mk-108.1, Darwin 0.1 vs mk-183.34.4) | 잘못된 채택 | 함수마다 원본 바이트 근거, 이름 일치만으로 채택 금지 |
| ObjC 런타임·메타데이터 ABI | 링크·적재 실패 | 원본 `__OBJC` 와 섹션 단위 비교 |
| MIG·어셈블러·링커 버전 | 생성 코드 차이 | 게스트 도구로만 생성, 버전·해시 기록 |
| 게스트 빌드 왕복 비용 | 속도 | S1-3 에서 자동화 설계 |
| QEMU 결함(i386 PIC, SPARC ESP) | 시험 해석 오류 | 변형·한계 명시, 실기 병행 |
| 라이선스(D013) | 공개 불가 코드 | 출처 기록, 결정 전 미커밋 |

## 7. 첫 작업 묶음 (S1, 이 순서)

1. 왕복 경로 확인(codex QR2 반영, 경로는 S1-3 의 실기): 실기가 응답하는지(`gcds next`), `/ndrv` 마운트, 작은 소스를 실기에서 `cc -c` 해 저장소에 쓴 목적 파일의 해시를 실기·호스트에서 비교. 이 경로로 아래 2–4 를 한다. 실기가 없으면 VM 예비 경로.
2. VM 툴체인 기록과 probe(S1-1·2). 결과 `08_build/toolchains/`, `09_validation/reconstruction/toolchain/`.
3. L1·L1d 비교 도구 작성과 자기 시험(S1-5).
4. 컴파일 옵션 표본 시험(S1-4).
5. 최종 빌드 왕복 경로 결정·자동화(S1-3) — 사용자와 함께.
각 항목은 착수 전에 세부 계획을 이 문서에 덧붙이고 codex 교차검토를 받는다.

## 8. 사용자 결정 대기

- D013: NeXTMach 코드의 공개 커밋 여부, Darwin 0.1(APSL) 코드의 공개 조건.
- (결정됨) i386 빌드는 실기, 시험은 QEMU. 실기 `cc` 존재는 선례(`build.sh`)로 확인, 버전·해시는 S1 첫 항목에서 기록.
- L1 에서 "재배치 필드만 다름" 을 채택 기준으로 볼지, 그 이상 차이를 허용할 기준.

## 9. codex 교차검토 판정 (2026-10-01, gpt-6-astra)

표의 `RECONSTRUCTION_PLAN.md:N` 줄 번호는 검토 시점(이 절을 쓰기 전) 문서 기준이다.

| 주장(질문) | codex 지적 | 내 검증 | 결과 |
|---|---|---|---|
| QR1: 재배치 필드만 가린 함수 바이트 비교가 동작이 다른 함수를 "동일" 로 판정할 수 없다 | 거짓: 경계 절단, 재배치 대상·가산값 차이 은폐, scattered/SECTDIFF, 재배치 없는 PC 상대 호출, 점프 표·리터럴 제외, 데이터 의존 차이 | 인용 줄 `RECONSTRUCTION_PLAN.md:16`(L1 정의)·`:64`(가림 방식)·`FULL_ANALYSIS.md:40`(경계 검증 별도) 열어 확인. 원본에 로컬 심볼이 없음을 Python 으로 확인(0xf 3,651, 0x3 100) → 정적 호출은 재배치 없이 해결될 수 있어 지적이 성립 | ✅ 채택: L1 을 "재배치 해석 비교"로 바꾸고 L1d 추가, 경계 미확정 분류, 도구 시험 항목 추가. 동작 동등이 아님을 명시 |
| QR2: 첫 작업 묶음 앞에 막는 누락·순서 오류가 없다 | ① probe 가 왕복 경로를 필요로 하는데 경로 결정이 맨 뒤 ② "`.m` 19 개뿐" 은 틀림(모듈 이름 76 = 절대 19 + 상대 57) | ① 7 절 순서(`:113`)와 S1-2(`:58`) 확인 ② `objc.json:197` = `Kernel/IOConfigTable.m`, Python 재계산: 모듈 76, 절대 19, 상대 57 | ✅ 둘 다 채택: 임시 수동 경로를 첫 항목으로, 2 절 수정. ②는 내 오기였다 |
| QR3: 실기 빌드(NFS `/ndrv` + gcds) → QEMU 시험 경로에 재현성·무결성 틈이 없다 | 거짓: NFS 캐시·시각으로 인한 낡은 입력과 `make` 오판, 동시 편집·빌드 혼합, 불완전 게시, 고정되지 않은 환경(`cc` 를 PATH 로 찾음), 파일 이름 대소문자·모드 미검사, 빌드와 부팅 파일의 연결 부재 | 인용 줄 모두 열어 확인: `RECONSTRUCTION_PLAN.md:62–66,82,120`(수정 전), `build.sh:5`(`cc -O …` PATH 의존, 고정 출력 경로), `snapshot.sh:17`(출력 전 `sync`), `verify_i386_kernel_add.py:25`(이름 고정) | ✅ 6 건 채택: S1-3 에 빌드 절차 규약 추가 |

## 10. 진행 기록

- 2026-10-01 실기 준비: 실기는 기준 커널(mk-183.34.4, 1999-01-26)로 동작, `/ndrv` 는 이미 마운트(hard,intr,timeo=30,retrans=5,rw). 사용자 허락으로 `NeXT_DRIVER/tools/nx-daemon.sh start`(telnet) 로 `gcdsd` 기동, `gcds next` 로 명령 실행 확인.
- S1-1 툴체인 기록: 실기 `cc -v` = `NeXT Software, Inc. version cc-744.13, gcc version 2.7.2.1`, `cc1obj` = `GNU Obj-C version 2.7.2.1 (80386, BSD syntax)`, 전처리기 `NeXT DevKit-based CPP 4.0`. 드라이버 기본 옵션은 `-dynamic -fPIC`(사용자 코드용) — 커널용 옵션은 S1-4 에서 찾는다. 파일 사본과 출력: `08_build/toolchains/real-i386-20261001/`(무시됨), 해시 비교 `sha256-vs-vm.json`: `/bin/cc`·`as`·`ld`·`/lib/cpp`·`migcom`·`make`·`gnumake`·`mig`·`/lib/i386/{as,cc1obj,cc1objplus,cc1plus,cpp,cpp-precomp,specs}` 15 개 모두 **실기 = i386 VM**. 실기에는 `42JDeveloperPatch1`·`42JUserPatch1`·`OS42MachUserPatch4` 영수증이 있으나 이 15 개 파일은 VM(패치 없음)과 같다.
- 함정(재현됨): 실기에서 읽기 전용 모드(`r-xr-xr-x`, `r--r--r--`) 파일을 `cp -p` 로 `/ndrv` 에 복사하면 **빈 파일**이 생긴다(SHA-256 `e3b0c442…`). 쓰기 가능한 모드의 파일은 정상. `cat src > dst` 로 복사하면 정상. 빌드 절차 규약 6(게시)의 manifest 검사가 이런 빈 출력을 잡아야 한다.

## 보관된 세부 계획 색인 (§11–436)

§11–244 는 절 번호·내용을 바꾸지 않고 `02_plan/plans/` 의 보관 파일 세 개로 옮겼다(2026-10-03, 사용자 결정 D026). §245–320 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-245-320.md` 로 옮겼다(2026-10-05, 사용자 지시 “완료된 작업은 완료 문서로 분리”). 기존 인용 "RECONSTRUCTION_PLAN.md N"(N = 11–244)은 아래 색인의 보관 파일에서 같은 번호 절을 찾는다. §321–373 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-321-373.md` 로 옮겼다(2026-10-07, 사용자 지시 “완료된 작업은 완료 문서로 분리해도 됩니다”; 이 묶음 안의 진단 메모 §341·365·369·371 도 함께 옮김 — 이어지는 진단은 §374). §374 부터는 이 파일 끝에 이어 쓴다. 옮김 검증: 보관 파일 본문을 이어 붙이면 원래 줄과 같음(Python, 아래 숫자). §374–408(x86 마무리, L2·L3)과 §409–436(m68k M0–M3)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-374-408.md`·`plans/RECONSTRUCTION_PLAN-409-436.md` 로 옮겼습니다(2026-10-09, 사용자 지시 “완료된 작업은 알맞게 정리”). 이 옮김의 검증(Python): 두 보관 파일의 본문 1162·1736 줄이 원래 줄과 같고, 남은 본문은 원래 파일에서 그 줄들을 빼고 색인 63 줄을 더한 것과 같습니다. §437 부터는 이 파일 끝에 이어 씁니다.

- §11 S1-A 세부 계획 — 빌드 왕복과 툴체인 probe (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §12 S1-B 세부 계획 — L1·L1d 비교 도구 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §13 S1-C 세부 계획 — 컴파일 옵션 표본 시험 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §14 S1-D 세부 계획 — Objective-C 목적 파일 대조 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §15 S2-A 세부 계획 — 목적 파일 경계와 링크 순서 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §16 S2-B 세부 계획 — 함수 단위 후보 대응 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §17 S5-P1 세부 계획 — 첫 시범 파일 `memcmp.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §18 S5-P2 세부 계획 — `kern_machdep.c` 와 첫 헤더 환경 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §19 S5-P3 세부 계획 — "복원 수정" 규칙과 첫 적용 `kern_machdep.c` (코딩 전, 2026-10-01, **사용자 결정 대기**) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §20 S5-P4 세부 계획 — `pagesize.c` 와 Mach 커널 헤더 확장 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §21 S4-A 사전 조사 — 설정 옵션과 생성 헤더 (조사만, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §22 S4-A1 세부 계획 — 공통 Mach 헤더가 요구하는 설정 옵션 6 개와 생성 헤더 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §23 S4-A2 세부 계획 — 미정의로 남은 설정 옵션 9 개 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §24 S4-B 세부 계획 — 헤더 판 차이: 구조체 배치 복원, 시범 `struct vm_object` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §25 S4-B2 세부 계획 — `struct thread` 배치 복원 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §26 S2-C 세부 계획 — 후보 소스 선택: Darwin 0.1 대 NeXTMach (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §27 S2-D 세부 계획 — 정의 파서(조건부 함수 머리)·결정성 수정과 재실행 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §28 S5-P5 세부 계획 — `vm_pager.c`: Darwin 바탕 + NeXTMach 구조 복원 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §29 S5-P6 세부 계획 — `ipc/ipc_thread.c`(Darwin 단일 후보) 와 스테이징 개선 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §30 S5-P7 세부 계획 — libc `memcpy.c`·`memmove.c` 의 `bcopy` 위치 복원 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §31 S5-P8 세부 계획 — libc `memchr.c`(그대로)·`memset.c`(뒷부분 삭제) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §32 S5-P9 세부 계획 — libc 두 번째 묶음 11 파일(`-O4 -funroll-all-loops`) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §33 S5-P10 세부 계획 — `kern/timer.c`(옵션 `STAT_TIME`·`NCPUS` 확정 시험) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §34 S4-C 조사와 S5-P11 세부 계획 — BSD 헤더 공백의 범위, `kern/mach_factor.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §35 S5-P12 세부 계획 — `ipc/ipc_table.c`(데이터 값 복원) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §36 S1-E 세부 계획 — `__common`(zero-fill) 의 심볼별 검증 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §37 S5-P13 세부 계획 — `kern/host.c`(`MACH_HOST` 확정 시험) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §38 S5-P14 세부 계획 — `kern/priority.c` `_thread_quantum_update` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §39 S5-P15 세부 계획 — `vm/vm_init.c` `_vm_mem_init` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §40 S4-C 사실 조사(2026-10-01) — 결정 없음, 기록만 → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §41 S5-P16 세부 계획 — machdep/i386 작은 세 파일 `bios.c`, `checksum_16.c`, `ldt.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §42 S5-P17 세부 계획 — `machdep/i386/gdt.c`, `idt.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §43 S5-P18 세부 계획 — `machdep/i386/dma_buf.c`, `dbl_fault.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §44 S5-P19 세부 계획 — `vm/vm_mem_region.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §45 S5-P20 세부 계획 — `kern/thread_swap.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §46 S1-F 세부 계획 — 정적 zero-fill 의 참조 기반 배치 판정, 참조 없는 영역의 등급 처리; S5-P21 `intr.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §47 S5-P22 세부 계획 — IPC 네 파일 `ipc_space.c`, `ipc_hash.c`, `ipc_pset.c` (+ `ipc_object.h`), `ipc_sched.c` 보류 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §48 새 코드 작성 규칙(D016)과 첫 적용 — `kern/time_stamp.c`, `kern/ipc_sched.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §49 S5-P24 세부 계획 — 일괄 진단 결과, `kern/lock.c`·`ipc/ipc_splay.c` 확정 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §50 S4-B3 세부 계획 — `struct task` 배치 복원(24 절 방법) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §51 S5-P25 세부 계획 — `kernserv/kern_notify.c` 를 P 로 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §52 S5-P26 세부 계획 — `ipc/ipc_marequest.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §53 S5-P27 세부 계획 — `ipc/ipc_object.c` + `ipc_entry.h`·`ipc_port.h` 원형 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §54 S5-P28 세부 계획 — `ipc/ipc_entry.c` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §55 S5-P29 세부 계획 — `ipc/ipc_port.c` + `ipc_port.h`·`ipc_kmsg.h` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §56 S5-P30 세부 계획 — `ipc/ipc_notify.c`·`mach/notify.h` 를 Mach4 판으로 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §57 S5-P31 세부 계획 — `ipc/ipc_right.c` = Mach4 판 + Darwin 의 `ipc_hash_delete` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §58 S5-P32 세부 계획 — `ipc/mach_port.c` + `mach/port.h` + 옵션 `MACH_OLD_VM_COPY` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §59 S5-P33 세부 계획 — `ipc/mach_debug.c` = Darwin 판 + 크기 변수 0 초기화 4 곳(작성, D016) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §60 S5-P34 세부 계획 — `kern/ipc_tt.c` = Darwin 판에서 `retrieve_task_self`·`retrieve_thread_self` 삭제 (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §61 S5-P35 세부 계획 — `kern/kalloc.c` = Darwin 판 + NeXTMach malloc 계열 + 작성 3 곳(D016) (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §62 S5-P36 세부 계획 — `kern/ipc_xxx.c` = Darwin 판에서 나중 추가분 제거 + `suser()` (코딩 전, 2026-10-01) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §63 S5-P37 세부 계획 — `vm/vm_user.c` = Darwin 판에서 `vm_reallocate`·`vm_wire` 삭제 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §64 S5-P38 세부 계획 — `machdep/i386/pc_support/PCinit.c`·`machdep/i386/fault_copy.c` 를 Darwin 판 그대로 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §65 S5-P39 세부 계획 — `kern/processor.c` 를 Darwin 판 그대로 채택(36.1 common 절차) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §66 S5-P40 세부 계획 — `machdep/i386/pc_support/PCresume.c` 를 Darwin 판 그대로 채택(등급 P) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §67 S5-P41 세부 계획 — 옵션 `MACH_KDB`·`NORMA_ETHER` 추가와 `kern/machine.c` 원문 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §68 S5-P42 세부 계획 — `machdep/i386/miniMonMachdep.c` 를 Darwin 판 그대로 채택(등급 P) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §69 S5-P43 세부 계획 — `pc_support/PCemulateREAL.c`·`PCemulatePROT.c` 를 Darwin 판 그대로 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §70 S5-P44 세부 계획 — `machdep/i386/dma.c` 를 Darwin 판 그대로 채택(등급 P) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §71 S5-P45 세부 계획 — `l1_compare.py` 의 크기 0 섹션 처리 수정 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §72 S5-P46 세부 계획 — 기록 정합성 점검, `07_kernel/README.md` 정정, 64 객체 최종 회귀 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §73 S5-P47 세부 계획 — D018(S4-C 안 B) 1 단계: 실기 헤더 확인·기록과 스테이징 루트 추가(선택 플래그) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §74 S5-P48 세부 계획 — `vm/vm_synchronize.c` 채택과 첫 NeXT 헤더 채택(D018) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §75 S5-P49 세부 계획 — `kern/timer.c`(A)·`machdep/i386/vm_machdep.c`(P) 를 Darwin 판 그대로 채택(`--nextdev`) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §76 S5-P50 세부 계획 — 옵션 `PC_SUPPORT`·`FP_EMUL`·`MACH_NBC` 추가, 67 객체 회귀, `machdep/i386/catch.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §77 S5-P51 세부 계획 — `machdep/i386/fp_support.c` 채택(등급 P)과 `FP_EMUL=0` 확정 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §78 S5-P52 세부 계획 — 첫 BSD 쪽 일괄 진단과 `bsd/libkern/strtol.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §79 S5-P53 세부 계획 — BSD 쪽 기준 판 조사: 구조체 비교 도구(NeXT SDK·NeXTMach·Darwin) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §80 S5-P54 세부 계획 — `machdep/i386/kdp_machdep.c` = Darwin 판 + 래퍼 2 개 작성(D016) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §81 S5-P55 세부 계획 — 옵션 `UXPR`·`XPR_DEBUG` 추가, Darwin `driverkit-1` 헤더 루트 추가, 70 객체 회귀 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §82 S5-P56 세부 계획 — `driverkit/ddm.c` 채택(등급 P) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §83 S5-P57 세부 계획 — D020(BSD 기준 = NeXTMach) 적용 1 단계: `stage_headers.py --bsd-next` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §84 S5-P58 세부 계획 — D019 를 `zerofill_check.py` 에 반영하고 `kern/kalloc.c`(61 절 보류분) 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §85 S5-P59 세부 계획 — `vm/vm_object.c` 진단(옵션 `NORMA_VM`·`MACH_PAGEMAP` 헤더) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §86 S5-P60 세부 계획 — MIG 생성 헤더 `mach/memory_object_user.h`·`mach/memory_object_default.h` 를 게스트 `mig` 로 만들고 vm_object 재진단 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §87 S5-P61 세부 계획 — SDK 판 `.defs` + `mig -newipc` 로 MIG 헤더 생성, vm_object 탐침 2 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §88 S5-P62 세부 계획 — vm_object.c 복원 수정(탐침 3) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §89 S5-P63 세부 계획 — vm_object 탐침 4: `vm_object_deactivate_pages` NeXTMach 본문, `vm_object_name` 작성 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §90 S5-P64 세부 계획 — `vm/vm_object.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §91 S5-P65 세부 계획 — vm/ 미채택 7 파일 일괄 진단(채택 없음) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §92 S5-P66 세부 계획 — `vm/vm_policy.c` 채택(Darwin 그대로) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §93 S5-P67 세부 계획 — `vm/vm_fault.c` 탐침(복원 수정 1 곳) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §94 S5-P68 세부 계획 — `vm/vm_fault.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §95 S5-P69 세부 계획 — `vm/vm_resident.c` 탐침(복원 수정 2 곳) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §96 S5-P70 세부 계획 — vm_resident 탐침 2 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §97 S5-P71 세부 계획 — `vm/vm_resident.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §98 S5-P72 세부 계획 — `vm/vm_pageout.c` 탐침 1: `vm_pageout()` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §99 S5-P73 세부 계획 — `vm_pageout_scan` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-011-099.md](plans/RECONSTRUCTION_PLAN-011-099.md)
- §100 S5-P74 세부 계획 — vm_pageout 탐침 4 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §101 S5-P75 세부 계획 — `vm/vm_pageout.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §102 S5-P76 세부 계획 — vm_kern 판단 보류, kern/ 미채택 파일 일괄 진단(채택 없음) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §103 S5-P77 세부 계획 — `kern/syscall_sw.c` 탐침(트랩 표 4 항목) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §104 S5-P78 세부 계획 — `kern/syscall_sw.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §105 S5-P79 세부 계획 — `kern/task.c` 탐침 1 (u-area 복원) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §106 S5-P80 세부 계획 — `kern/task.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §107 S5-P81 세부 계획 — `kern/mach_header.c` 탐침 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §108 S5-P82 세부 계획 — `l1_compare.py --define-symbol` (링커 정의 심볼) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §109 S5-P83 세부 계획 — `kern/mach_header.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §110 S5-P84 세부 계획 — `kern/mach_init.c` 탐침 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §111 S5-P85 세부 계획 — `kern/mach_init.c` 채택(MACH_NET·SDK version.h 포함) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §112 S5-P86 세부 계획 — 옵션 `MACH_DEBUG`·`HW_FOOTPRINT`·`NORMA_IPC` 진단 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §113 S5-P87 세부 계획 — `kern/kernel_stack.c` 탐침(스택 크기) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §114 S5-P88 세부 계획 — `kern/kernel_stack.c` 채택(MACH_DEBUG·KERNSTACK_SIZE) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §115 S5-P89 세부 계획 — thread·sched_prim 진단 2 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §116 S5-P90 세부 계획 — thread.c·sched_prim.c 탐침 1 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §117 S5-P91 세부 계획 — thread·sched_prim 탐침 2 (SIMPLE_CLOCK 0 + NeXTMach 줄) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §118 S5-P92 세부 계획 — thread 탐침 3 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §119 S5-P93 세부 계획 — `kern/thread.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §120 S5-P94 세부 계획 — sched_prim 탐침 2 (Mach4 타이머 형태) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §121 탐침 3 편집(스테이징만, D014 R1·R2, Mach4 출처) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §122 탐침 4 편집(스테이징만) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §123 통제 탐침 (스테이징 = 탐침 4 + S10) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §124 S5-P98 세부 계획 — `-g` 회귀와 thread_select 변형 2 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §125 S5-P99 세부 계획 — `kern/sched_prim.c` 채택과 표준 플래그에 `-g` 반영 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §126 S5-P100 세부 계획 — `-g` + 현재 config 로 미채택 후보 일괄 재진단(채택 없음) (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §127 S5-P101 세부 계획 — vm_map 탐침 1 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §128 vm_map 탐침 2 편집(스테이징만, NeXTMach D013/D014) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §129 S5-P103 세부 계획 — `vm/vm_map.c` 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §130 현황과 사용자 판단 요청 (2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §131 S5-P104 세부 계획 — D021(BSD 헤더 묶음 교체) 1 단계: 설계와 실현성 진단 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §132 S5-P106 세부 계획 — D021 2 단계: 실패 3 원인 수정과 잠정 정의 처리 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §133 S5-P107 세부 계획 — D021 3 단계: 07 반영(BSD 헤더 묶음 교체)과 최종 플래그 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §134 S5-P108 세부 계획 — D022(비-BSD 헤더 SDK 교체, Mach 내부는 Mach4 기본 참고) 1 단계 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §135 S5-P109 세부 계획 — D022 SDK 63 개 07 반영 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §136 S5-P110 세부 계획 — D023: 공개판 7 개의 비공개 분기 작성 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §137 S5-P111 세부 계획 — Mach4 기본 참고로 미복원 Mach 객체 후보 진단 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §138 S5-P112 세부 계획 — queue(A 후보)·syscall_subr(Darwin + NeXTMach `map_fd`) 채택 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §139 S5-P113 세부 계획 — NeXTMach `kern/mfs_prim.c` 복원 (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §140 S5-P114 세부 계획 — NeXTMach 후보 일괄 진단 (BSD 계층 포함, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §141 S5-P115 세부 계획 — 근접 4 객체(af·netbuf·rpc_prot·rpc_callmsg)와 `-DINET`, 작성판 `rpc/types.h` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §142 S5-P116 — 진단 9 결과와 3 객체 채택(140.4 와 같은 절차, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §144 S5-P118 — SDK 에 없는 i386 BSD 비공개 헤더 (2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §145 S5-P119 세부 계획 — `bsd/kern_time.c` 복원 (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §146 S5-P120 — `bsd/kern_subr.c`(2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §148 S5-P122 — `bsd/subr_xxx.c` (2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §149 S5-P123 세부 계획 — 명령행 `-DMACH` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §150 S5-P124 세부 계획 — 명령행 `-DMULTICAST` 와 `net/raw_cb.c` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §151 S5-P125 세부 계획 — `netinet/tcp_timer.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §152 S5-P126 세부 계획 — `netinet/tcp_debug.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §153 S5-P127 세부 계획 초안 — `net/netif.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §154 S5-P128 세부 계획 — `net/netisr.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §155 S5-P129 세부 계획 — 명령행 `-DPOSIX_KERN` 과 `kern/sys_socket.c` (코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §156 S5-P130 세부 계획 초안 — `bsd/kern/tty_tty.c` (D024, `-DPOSIX_KERN` 전제, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §157 S5-P131 세부 계획 — `bsd/kern/vfs_pathname.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §158 S5-P132 세부 계획 — `bsd/rpc/auth_kern.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §159 S5-P133 세부 계획 — `bsd/kern/vfs_vnode.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §160 S5-P134 세부 계획 — `bsd/kern/vfs_io.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §161 S5-P135 세부 계획 — `bsd/kern/uipc_usrreq.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §162 S5-P136 세부 계획 — `bsd/kern/uipc_mbuf.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §163 S5-P137 세부 계획 — `netinet/tcp_usrreq.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §164 S5-P138 세부 계획 — `bsd/kern/vfs.c` (D024, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §165 S5-P139 세부 계획 — `netinet/tcp_subr.c` (D024, 4.3-Reno 형태, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §166 S5-P140 세부 계획 — `netinet/in_pcb.c` (D024, 4.3-Reno + MULTICAST 1.0 형태, 코딩 전, 2026-10-02) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §167 사용자 공간 libsys(libc·cthreads) 분석 준비 — 원본 수집 계획 (2026-10-02, 사용자 지시) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §168 S5-P141 세부 계획 — `netinet/raw_ip.c` (D024, MULTICAST 1.0 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §169 S5-P142 세부 계획 — `netinet/udp_usrreq.c` (D024, 4.3-Reno + MULTICAST 1.0 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §170 S5-P143 세부 계획 — `netinet/ip_icmp.c` (D024, Reno + MULTICAST 1.0 + NeXT 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §171 S5-P144 세부 계획 — `netinet/in.c` (D024, MULTICAST 1.0 + NeXT 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §172 S5-P145 세부 계획 — `net/if.c` (D024, Reno + MULTICAST 1.0 + NeXT 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §173 S5-P146 세부 계획 — `netinet/if_ether.c` (D024, NeXTMach + MULTICAST 1.0 + NeXT 정렬 복사 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §174 S5-P147 세부 계획 — `netinet/tcp_output.c` (D024, 4.3-Reno + MULTICAST 1.0 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §175 S5-P148 세부 계획 — `netinet/ip_output.c` (D024, MULTICAST 1.x(4.3, mbuf 보관) + NeXT netbuf 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §176 S5-P149 세부 계획 — `net/if_venip.c` (D024, NeXT MULTICAST 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §177 S5-P150 세부 계획 — `bsd/vfs_lookup.c` (D024, NeXT POSIX 경로 처리, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §178 S5-P151 세부 계획 — `ufs/ufs_bmap.c` (D024, NeXT i386 빅엔디언 UFS 간접 블록, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §179 S5-P152 세부 계획 — `bsd/vfs_syscalls.c` (D024, NeXT POSIX 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §180 S5-P153 세부 계획 — `bsd/uipc_syscalls.c` (D024, NeXT u_ofile 등록·POSIX pipe 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §181 S5-P154 세부 계획 — `bsd/subr_log.c` (D024, NeXT callout·스레드 select 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §182 S5-P155 세부 계획 — `bsd/sys_generic.c` (D024, NeXT continuation select·스레드 캐시 형태, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §183 S5-P156 세부 계획 — `bsd/tty_subr.c` (D024, 4.3-Reno 꼴 quote 비트 cblock, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §184 S5-P157 세부 계획 — `bsd/vfs_dnlc.c` (D024, 인라인 큐 조작·NeXT 심볼릭 링크 캐시 수정, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §185 S5-P158 세부 계획 — `nfs/nfs_xdr.c` (D024, 정적 XDR 보조 루틴, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §186 S5-P159 세부 계획 — `nfs/nfs_subr.c` (D024, 정적 보조 함수·NeXT 수정, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §187 S5-P160 세부 계획 — `bsd/uipc_socket2.c` (D024, 스레드 select 캐시, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §188 S5-P161 세부 계획 — `specfs/fifo_vnodeops.c` (D024, 스레드 select 캐시·vn_devblocksize, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §189 S5-P162 세부 계획 — `bsd/kern/tty_pty.c` (D024, pty 표 지연 할당·스레드 select 캐시·POSIX, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §190 S5-P163 세부 계획 — `bsd/rpc/pmap_kgetport.c`·`bsd/rpc/pmap_prot.c` (커널용 `rpc/pmap_prot.h`, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §191 S5-P164 세부 계획 — `bsd/rpc/clnt_kudp.c` (D024, cred 참조 계수·getthetime, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §192 S5-P165 세부 계획 — `bsd/rpc/svc.c` (커널용 `rpc/svc.h`, 기록 객체 6 개 회귀 확인, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §193 S5-P166 세부 계획 — `bsd/nfs/nfs_common.c` (D024, NFSTSIZE·-1 uid/gid, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §194 S5-P167 세부 계획 — `bsd/kern/vfs_xxx.c` (D024, ustat 블록 단위 상수, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §195 S5-P168 세부 계획 — `bsd/kern/kern_xxx.c` (D024, RB_COMMAND·command 초기화, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §196 S5-P169 세부 계획 — `bsd/kern/mach_signal.c` (thread 의 uthread 필드 이름, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §197 S5-P170 세부 계획 — `bsd/kern/mach_process.c` (import 경로·`_uthread`, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §198 S5-P171 세부 계획 — `kern/ast.c` (D024, NeXTMach 기준 + Mach 3 식 ast_on, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §199 S5-P172 세부 계획 — `bsd/nfs/nfs_client.c` (D024, flag 인자·getthetime·NBC 크기, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-100-199.md](plans/RECONSTRUCTION_PLAN-100-199.md)
- §200 S5-P173 세부 계획 — `bsd/kern/kern_mman.c` (import·vm_map_entry 필드 이름, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §201 S5-P174 세부 계획 — `bsd/kern/kern_resource.c` (import·사용자 스택 주소, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §202 S5-P175 세부 계획 — `bsd/kern/kern_fork.c` (D024, POSIX 프로세스·u 영역 zone, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §203 S5-P176 세부 계획 — `bsd/kern/cmu_syscalls.c` (D024, table() 의 NeXT 변경, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §204 S5-P177 세부 계획 — `bsd/kern/kern_descrip.c` (D024, FPINPROGRESS 예약·재검사·POSIX 잠금, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §205 S5-P178 세부 계획 — `bsd/kern/kern_synch.c` (D024, continuation sleep, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §206 S5-P179 세부 계획 — `bsd/ufs/ufs_dsort.c` (고전 disksort·thread NULL 검사, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §207 S5-P180 세부 계획 — `bsd/ufs/ufs_subr.c` (bufstats 가변 배열·update getthetime, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §208 S5-P181 세부 계획 — `bsd/vfs/vfs_bio.c` (D024, vn_devblocksize·brelvp_wakeup·btrash, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §209 S5-P182 세부 계획 — `bsd/kern/uipc_socket.c` (mach/exception.h·POSIX EAGAIN·selthreadclear, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §210 보류 메모 — `bsd/kern/kern_exec.c` (분석만, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §211 S5-P185 세부 계획 — `bsd/kern/kern_proc.c` (D024, POSIX 프로세스 그룹·세션·posix_proc, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §212 S5-P186 세부 계획 — `bsd/kern/kern_prot.c` (D024, *_from_thread·POSIX setuid/setgid·setsid/setpgid, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §213 S5-P187 세부 계획 — `bsd/kern/kern_exit.c` (D024, continuation wait·waitpgrp·POSIX 세션, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §214 S5-P190 세부 계획 — `bsd/ufs/ufs_alloc.c` (D024, 실린더 그룹 byte swap·btodb 2 인자, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §215 S5-P191 세부 계획 — `bsd/ufs/ufs_inode.c` (D024, inode byte swap·inode_cache_clear·btodb 2 인자, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §216 S5-P194 세부 계획 — `bsd/ufs/ufs_vfsops.c` (D024, superblock byte swap·장치 블록 크기, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §217 S5-P195 세부 계획 — `bsd/ufs/ufs_vnodeops.c` (D024, 장치 블록 크기·POSIX·디렉터리 byte swap, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §218 S5-P196 세부 계획 — `bsd/ufs/ufs_dir.c` (D024, 디렉터리 블록 byte swap, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §219 S5-P197 세부 계획 — `uxkern/ux_exception.c` (D024 전면 작성, Mach 3 호환 포트 API, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §220 S5-P198 세부 계획 — `bsd/kern/subr_prf.c` (D024, stdarg·vlog·_printf, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §221 S5-P199 세부 계획 — `vm/vm_unix.c` (D024, Mach 3 u 영역·gc_control, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §222 S5-P202 세부 계획 — `bsd/specfs/spec_vfsops.c` (NeXTMach 원문 그대로, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §223 S5-P201 세부 계획 — `bsd/specfs/spec_vnodeops.c` (D024, set_blocksize·s_size 블록 크기·getthetime, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §224 S5-P203 세부 계획 — `bsd/specfs/spec_subr.c` (D024, set_blocksize, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §225 S5-P204 세부 계획 — `bsd/netinet/ip_input.c` (D024, MULTICAST·bootp.h·icmp_error 5 인자, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §226 S5-P206 세부 계획 — `rpc/bootparam_xdr.c`·`rpc/mountxdr.c`·`net/if_loop.c` (D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §227 S5-P207 세부 계획 — `next/ufs_machdep.c`·`next/dkbad.c` (NeXTMach 그대로, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §228 S5-P208 세부 계획 — physio·physstrat 객체 `bsd/kern/kern_physio.c` (NeXTMach 두 파일 조합, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §229 S5-P212 세부 계획 — boot·unmount_all·kill_tasks·proc_shutdown·fd_shutdown 객체 `bsd/kern/kern_shutdown.c` (NeXTMach 두 파일 조합 + 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §230 S5-P214 세부 계획 — core() 객체 `bsd/kern/kern_core.c` (NeXTMach kern_sig.c 의 core + 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §231 S5-P215 세부 계획 — kern_sig 본체 `bsd/kern/kern_sig.c` (NeXTMach + POSIX·4.2 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §232 S5-P216 세부 계획 — `bsd/kern/init_main.c` (NeXTMach + main·init_task·lightning_bolt 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §233 S5-P218 세부 계획 — `bsd/kern/kern_clock.c` (NeXTMach + 4.2 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §234 S5-P219 세부 계획 — 나노초 타이머 객체 `kern/ns_timer.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §235 S5-P220 세부 계획 — `kern/mach_clock.c` (Mach4 + 4.2 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §236 S5-P221 세부 계획 — `rpc/pmap_krmt.c` (NeXTMach, pmap_krmtcall 제거, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §237 S5-P222 세부 계획 — uname 객체 `bsd/kern/kern_uname.c` (전면 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §238 S5-P223 세부 계획 — `kern/power.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §239 S5-P224 세부 계획 — `kern/miniMon.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §240 S5-P225 세부 계획 — i386 시스템 시계 `machdep/i386/machine_clock.c` (전면 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §241 S5-P226 세부 계획 — i386 `machdep/i386/machdep.c` (작성 + NeXTMach addupc, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §242 S5-P227 세부 계획 — `vm/vnode_pager.c` (NeXTMach 원문 + 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §243 S5-P228 세부 계획 — `vm/vm_kern.c` (NeXTMach 원문 + Mach4 copyinmap + 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §244 S5-P229 세부 계획 — i386 `machdep/i386/io_prim.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-200-244.md](plans/RECONSTRUCTION_PLAN-200-244.md)
- §245 S5-P230 세부 계획 — `bsd/kern/tty.c` (NeXTMach 원문 + POSIX termios 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §246 S5-P231 세부 계획 — i386 `bsd/dev/i386/mem.c`(/dev/mem·kmem·null; 전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §247 S5-P232 세부 계획 — i386 `machdep/i386/in_cksum.c` (전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §248 S5-P233 세부 계획 — i386 `machdep/i386/i386_init.c` (전면 작성 + getargs 계열, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §249 S5-P234 세부 계획 — i386 `machdep/i386/pc_support/PCtimers.c` (전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §250 S5-P235 세부 계획 — `bsd/netinet/ip_mroute.c` 멀티캐스트 라우팅 없는 판(스텁 3 개, 전면 작성, D024, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §251 S5-P236 세부 계획 — `bsd/netinet/igmp.c` (MULTICAST 1.x 꼴, 전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §252 S5-P237 세부 계획 — i386 `machdep/i386/pc_support/PCexception.c` (전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §253 S5-P238 — machine_clock.c 재시도(plan 240 작업본 it8, 2026-10-03) — 보류 유지 → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §254 S5-P239 세부 계획 — i386 `machdep/i386/APM_i386.c` (전원 관리 PM*, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §255 S5-P240 세부 계획 — i386 `machdep/i386/bios_asm.s`(`__bios32`, 첫 어셈블리 소스, 전면 작성, D024·D027, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §256 S5-P241 세부 계획 — `kern/callout.c`(callout 계열 14 기호, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §257 S5-P242 세부 계획 — `kern/kdp.c`(원격 디버거 프로토콜 + UDP, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §258 S5-P243 세부 계획 — i386 `machdep/i386/unix_signal.c` (sendsig·sigreturn·machine_exception, 작성 + NeXTMach 신호 로직, D024·D013, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §259 S5-P244 세부 계획 — i386 `machdep/i386/unix_startup.c` (startup_early·startup, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §260 S5-P246 세부 계획 — `kern/mach_fat.c`(fatfile_getarch, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §261 S5-P247 세부 계획 — `kern/mach_net.c`(IP 데이터그램의 Mach 메시지 전달, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §262 S5-P248 세부 계획 — `kern/mach_loader.c`(Mach-O 적재, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §263 S5-P249 세부 계획 — `kern/exception.c`(Mach4 원문 + 바이트가 요구하는 수정) 와 `ipc/ipc_mqueue.h` 원형 복원(코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §264 S5-P250 세부 계획 — `kern/ipc_kobject.c`(Mach4 원문 + 바이트가 요구하는 수정, 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §265 S5-P251 세부 계획 — `kern/ipc_mig.c`(Mach4 원문 + 구 IPC 진입점 작성) 와 `ipc/ipc_kmsg.h` 원형 2 개 복원(코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §266 S5-P252 세부 계획 — `ipc/ipc_mqueue.c`(Mach4 원문 + 바이트가 요구하는 수정, 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §267 S5-P253 세부 계획 — `ipc/ipc_init.c`(Mach4 원문 + 바이트가 요구하는 수정, 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §268 S5-P254 세부 계획 — `ipc/mach_msg.c`(Mach4 원문 + 바이트가 요구하는 수정) 와 `ipc/ipc_kmsg.h` 원형 2 개 복원(코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §269 S5-P256 세부 계획 — `ipc/ipc_kmsg.c`(Mach4 원문 + MACH_OLD_VM_COPY 등 바이트가 요구하는 수정) 와 `ipc/ipc_kmsg.h` ipc_kmsg_copyout_body 원형 복원(코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §270 S5-P260 세부 계획 — `bsd/kern/qsort.c`(참조 원문 없음, 원본 바이트로 작성 D024; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §271 S5-P261 세부 계획 — `bsd/ufs/ufs_byte_order.c`(참조 원문 없음, 원본 바이트로 작성 D024; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §272 S5-P262 세부 계획 — `machdep/i386/sys_machdep.c`(NeXTMach next/sys_machdep.c + resuba; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §273 S5-P263 세부 계획 — `machdep/i386/trap.c`(원본 바이트로 작성 D024, Darwin 구조·NeXTMach u 영역 관용구) 와 Darwin `machdep/i386/machdep_call.h` 채택(코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §274 S5-P264 세부 계획 — `machdep/i386/pcb.c`(D024·D027: 바이트가 요구하는 문장 = Darwin 0.1 pcb.c 의 문장; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §275 진행 메모 — `machdep/i386/pmap.c`(D029: Darwin 0.1 바탕 + 수정; 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §276 S5-P266 세부 계획 — `machdep/i386/cons.c`(NeXTMach next/cons.c + POSIX 제어 터미널 작성; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §277 S5-P267 세부 계획 — `machdep/i386/rtc.c`(Mach4 i386at/rtc.c 바탕 + 원본 바이트 수정; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §278 S5-P268 세부 계획 — `machdep/i386/kdasm.s`(Mach4 i386at/kdasm.S 바탕; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §279 S5-P269 세부 계획 — `bsd/nfs/nfs_server.c`(NeXTMach nfs/nfs_server.c 바탕; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §280 S5-P270 세부 계획 — 확정 P 객체 `bsd/nfs/nfs_subr.c` 의 끝 보완: rlock_timeout(작성; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §281 S5-P271 세부 계획 — `bsd/nfs/nfs_vfsops.c`(NeXTMach nfs/nfs_vfsops.c 바탕 + 원본 바이트 수정; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §282 S5-P272 세부 계획 — `bsd/nfs/nfs_vnodeops.c`(NeXTMach nfs/nfs_vnodeops.c 바탕 + 원본 바이트 수정; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §283 S5-P273 세부 계획 — `machdep/i386/ev.c`(이벤트 드라이버 기계 의존부, 원본 바이트에서 작성 D024·D027; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §284 S5-P274 세부 계획 — `driverkit/memcpy.c`(_IOCopyMemory, 원본 바이트에서 작성 D024·D027; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §285 S5-P275 세부 계획 — `driverkit/label_subr.c`(checksum16·check_label, 원본 바이트에서 작성 D024·D027, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §286 S5-P276 세부 계획 — `driverkit/disk_label.c` + 작성 헤더 `driverkit/diskstruct.h`(원본 바이트에서 작성 D024·D027, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §287 S5-P277 세부 계획 — `driverkit/audio_mulaw.c`(원본 바이트·데이터에서 작성 D024·D027, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §288 S5-P278 세부 계획 — `driverkit/audio_peak.c`(원본 바이트에서 작성 D024·D027·D030, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §289 S5-P279 세부 계획 — `driverkit/audio_mix.c`(원본 바이트에서 작성 D024·D027·D030, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §290 S5-P280 세부 계획 — `driverkit/snd_reply.c`(원본 바이트에서 작성 D024·D027·D030) + `driverkit/snd_msgs.h`(NeXTMach nextdev/snd_msgs.h 바탕 + 수정); 코딩 전 — 스크래치 진단만, 2026-10-04 → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §291 S5-P281 세부 계획 — `bsd/kern/kern_exec.c`(NeXTMach bsd/kern_exec.c 바탕 + 원본 바이트 수정·작성; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §292 S5-P282 세부 계획 — `machdep/i386/start.s`(Darwin 0.1 원문 바탕, D029; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §293 S5-P283 세부 계획 — `driverkit/IOMallocLow.c`·`driverkit/machdepFuncs.c`(원본 바이트에서 작성 D024·D027·D030; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §294 S5-P284 세부 계획 — `driverkit/generalFuncs.c`(원본 바이트에서 작성 D024·D027·D030; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §295 S5-P285 진단 — `bsd/ufs/ufs_lockf.c`(lf_lockctl, 원본 바이트에서 작성 D024; 스크래치 진단만, 2026-10-04) — 보류 → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §296 S5-P286 진단 — 첫 ObjC 객체 `NXSpinLock.m`(libDriver Kernel/NXSpinLock.m; 스크래치 진단만, 2026-10-04) — 모듈 이름 방식 결정 대기 → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §297 S5-P287 세부 계획 — ObjC 빌드 경로(D031 “빌드 디렉터리 재현”)와 첫 객체 `NXSpinLock.m`(코딩 전, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §298 S5-P288 세부 계획 — `libDriver/Kernel/NXConditionLock.m`·`NXLock.m`(D024·D027·D030·D031; 코딩 전 — 스크래치 진단만, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §299 S5-P289 세부 계획 — `libDriver/Kernel/generalFuncsPrivate.m`(D024·D027·D030·D031) + l1_compare 의 메서드 없는 ObjC 모듈 처리(코딩 전, 2026-10-04) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §300 S5-P290 세부 계획 — libDriver ObjC 분류(진단)와 `Kernel/IONetbufQueue.m`·`Kernel/kernelDiskMethods.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §301 S5-P291 세부 계획 — `Kernel/IOBufDevice.m`·`Kernel/IOEventSource.m`·`Kernel/KeyMap.m`(A)·`i386/IOVPCodeDisplay.m`(P)(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §302 S5-P292 세부 계획 — zerofill_check 의 ObjC 참조 섹션 배치(`--place-from-l1`)와 `i386/IOVPCodeDisplay.m`(P)(코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §303 S5-P293 세부 계획 — 커널 BSD 비공개 머리 6 개(작성, D030) + `Kernel/IOTokenRing.m`·`IODisplay.m`·`EventDriver.m`·`EventInput.m`·`EventIO.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §304 S5-P294 세부 계획 — 절대 모듈 이름 빌드(D033, kr_run `ABSROOT`)와 첫 객체들(코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §305 S5-P295 세부 계획 — `src/driverkit/KernBus.m`(P)·`src/driverkit/KernDevice.m`(A)(D024·D027·D030·D033; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §306 S5-P296 세부 계획 — `src/driverkit/KernBusMemory.m`·`KernDeviceDescription.m`(D024·D027·D030·D033; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §307 S5-P297 세부 계획 — `libDriver/Kernel/SCSIGeneric.m`(D024·D027·D030·D031) + 객체별 빌드 정의 `-DMACH_USER_API`(코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §308 S5-P298 세부 계획 — `libDriver/IODirectDevice.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §309 S5-P299 세부 계획 — `libDriver/IODeviceDescription.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §310 S5-P300 세부 계획 — `libDriver/Kernel/IOEthernetDebugger.m` + 머리 `driverkit/IOEthernetPrivate.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §311 S5-P301 세부 계획 — `libDriver/IOLogicalDisk.m` + 머리 `driverkit/SCSIDisk.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §312 S5-P302 세부 계획 — `libDriver/Kernel/SCSIDiskPrivate.m` + 머리 `driverkit/SCSIDiskPrivate.h`·`SCSIDiskTypes.h`·`SCSIDiskThread.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §313 S5-P303 진단 — `libDriver/IODisk.m`(결정 대기, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §314 S5-P304 세부 계획 — `libDriver/Kernel/SCSIDisk.m` + `nextdev_private/driverkit/SCSIDisk.h` 수정(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §315 S5-P305 — libDriver 객체별 빌드 꼴 `-DMACH_USER_API -UKERNEL_PRIVATE`(plan 307 확장; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §316 S5-P306 세부 계획 — `libDriver/IODiskPartition.m`(D024·D027·D030·D031·D032, plan 315 꼴; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §317 S5-P307 세부 계획 — `libDriver/volCheck.m`(D024·D027·D030·D031·D032, plan 315 꼴; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §318 S5-P308 세부 계획 — `libDriver/Kernel/SCSIDiskThread.m` + 머리 `driverkit/SCSIStructInlines.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §319 S5-P309 세부 계획 — `libDriver/Kernel/IONetwork.m` 작성(D024·D027·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §320 S5-P310 세부 계획 — `libDriver/Kernel/IOSCSIController.m`(D024·D027·D030·D031, plan 315 꼴; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-245-320.md](plans/RECONSTRUCTION_PLAN-245-320.md)
- §321 S5-P311 세부 계획 — `libDriver/IODevice.m`(D024·D027·D030·D031, plan 315 꼴; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §322 S5-P312 세부 계획 — `libDriver/Kernel/IOEthernet.m` 작성(D024·D027·D030·D031; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §323 S5-P313 세부 계획 — `libDriver/Kernel/IOConfigTable.m`(D024·D027·D030·D031·D035; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §324 S5-P314 세부 계획 — 커널 트리 `machdep/i386/swapgeneric.m`(D024·D027·D033·D035; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §325 S5-P315 세부 계획 — 커널 트리 `driverkit/i386/autoconf_i386.m`(D024·D027·D030·D033·D035; 코딩 전, 2026-10-05) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §326 S5-P316 세부 계획 — 커널 트리 `bsd/dev/i386/km.m`(D013·D024·D029·D033·D035·D037; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §327 S5-P317 세부 계획 — 커널 트리 `bsd/dev/i386/kmDevice.m`(D024·D027·D030·D032·D033·D035; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §328 S5-P318 세부 계획 — 커널 트리 `bsd/dev/SCSIDiskKern.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §329 S5-P319 세부 계획 — 커널 트리 `bsd/dev/SCSIGenericKern.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §330 S5-P320 세부 계획 — 커널 트리 `bsd/dev/i386/EventSrcPCKeyboard.m`(D024·D027·D030·D032·D033; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §331 S5-P321 세부 계획 — 커널 트리 `bsd/dev/i386/PCPointer.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §332 S5-P322 세부 계획 — 커널 트리 `driverkit/autoconfCommon.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §333 S5-P323 세부 계획 — 커널 트리 `driverkit/driverServerXXX.m`(D024·D027·D030·D033, D035 와 같은 지역 정의; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §334 S5-P324 세부 계획 — 커널 트리 `bsd/dev/vol.c`(D013·D029·D036·D038; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §335 S5-P325 세부 계획 — `dev/busvar.h` 를 NeXTMach 판으로(D039) + autoconfCommon 마무리(plan 332; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §336 S5-P326 세부 계획 — 커널 트리 `bsd/dev/i386/kmGraphics.m`(D024·D027·D030·D032·D033·D040; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §337 S5-P327 세부 계획 — 커널 트리 `bsd/dev/i386/BasicConsole.c`(D024·D027·D030·D035; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §338 S5-P328 세부 계획 — 커널 트리 `bsd/dev/i386/VGAConsole.c`(D024·D027·D030·D032, ohlfs12.h 는 D013·D021·D039 방식; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §339 S5-P329 세부 계획 — zerofill_check `--place-from-l1` 이 L1d 추정 배치를 받도록(D041) + kmGraphics 기록(plan 336; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §340 S5-P330 세부 계획 — 커널 트리 `bsd/dev/i386/kmLocalized.c`(D024·D027·D030; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §341 진행 메모 — 커널 트리 `bsd/dev/i386/FBConsole.c`(진단만, 07 아님; 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §342 S5-P331 세부 계획 — libDriver 오디오 9 모듈(`Kernel/IOAudio.m` 외 8; D024·D027·D030·D031·D032·D042·D043; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §343 S5-P332 세부 계획 — libDriver MIG 생성 C 3 개(EventServer.c·audioServer.c·audioReplyUser.c; D030·D017; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §344 S5-P333 세부 계획 — 커널 트리 `driverkit/driverServerServer.c`(MIG 생성, driverServer.defs 4.2 판; D024·D030·D017; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §345 S5-P334 세부 계획 — libDriver 버스·디스플레이 5 모듈(`eisa/IOEISADirectDevice.m`·`eisa/IOEISADeviceDescription.m`·`pcmcia/IOPCMCIADeviceDescription.m`·`pcmcia/IOPCMCIATuple.m`·`Kernel/IOSVGADisplay.m`) + 쓰는 Darwin·SDK 머리 채택(D024·D027·D030·D031; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §346 S5-P335 세부 계획 — 기록된 객체가 Darwin 대체 경로로 읽는 나머지 머리 25 개를 07 에 둠(자기 완결; D013·D021·D030; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §347 S5-P336 세부 계획 — libDriver `Kernel/IOFrameBufferDisplay.m`(D024·D027·D030·D031·D032; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §348 S5-P337 세부 계획 — 커널 MIG 서버 4 개(`mach/exc_server.c`·`mach_host_server.c`·`mach_port_server.c`·`mach_server.c`; 4.2 SDK .defs; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §349 S5-P338 세부 계획 — 커널 MIG 서버 `mach_debug/mach_debug_server.c`(처음 제안은 Darwin 0.1 판 — 아래 “349 수정 계획”(Mach4 바탕)으로 대체됨; D013·D022·D024; 코딩 전, 2026-10-06) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §350 S5-P339 세부 계획 — 커널 `kern/zalloc.c`(Mach4 바탕, D044·D022·D024; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §351 S5-P340 세부 계획 — 커널 MIG 출력 `kernserv/kern_server_handler.c`·`kern_server_reply_user.c`(4.2 SDK .defs; D022; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §352 S5-P341 세부 계획 — 커널 `kernserv/kern_server.c`(NeXTMach 바탕, D024·D013·D022; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §353·354 진단 메모(코딩 전, 2026-10-07) — `bsd/netinet/tcp_input.c`, `bsd/specfs/spec_vnodeops.c` → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §356 S5-P342 세부 계획 — 커널 ObjC 런타임 9 모듈(`objc/*.m`, `except.c`; D045·D046·D047·D030·D022; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §357 S5-P343 세부 계획 — 도구 `10_tools/reconstruction/stage_headers.py`: `components/` 의 Darwin 대응을 architecture·driverkit-1 로 한정(D046 참고 트리 objc-1 배제; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §358 S5-P344 세부 계획 — ObjC 런타임 클래스 모듈 `List.m`·`Protocol.m`(D047·D030; plan 356 과 같은 꼴; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §359 S5-P345 세부 계획 — ObjC 런타임 `HashTable.m`(D049 별도 디렉터리; D047·D030; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §360 S5-P346 세부 계획 — ObjC 런타임 남은 조각 `objc-globaltext.m`·`objc-msg.s`·zone 층(D047·D030·D024; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §361 S5-P347 세부 계획 — Mach 사용자 API 스텁 14 개(`mach/<routine>.c`, `mig -i`, `<routine>_EXTERNAL`; 4.2 SDK mach.defs; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §362 S5-P348 세부 계획 — libgcc `__muldi3`·`__udivdi3`(D050 참고 원문 확보; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §363 S5-P349 세부 계획 — `bsd/dev/i386/EventShmemLock.s`(+`.h`)·`bsd/dev/i386/kbd_entries.m`(D030·D032; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §364 S5-P350 세부 계획 — `machdep/i386/locore.s`(D029; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §365 진단 메모 — `machdep/i386/machine_clock.c` 남은 3 B(plan 240.1 이어서; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §366 S5-P351 세부 계획 — `bsd/netinet/in_bootp.c`(NeXTMach 바탕 + 작성, D013·D022·D024·D027; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §367 진단 메모 — `bsd/ufs/ufs_lockf.c`(plan 295 이어서, D052 Net/2 원문 확보 뒤; 07 손대지 않음) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §368 S5-P352 세부 계획 — `bsd/netinet/tcp_input.c`(4.3BSD-Net/2 바탕, D048·D013·D024; plan 353 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §369 진단 메모 — `bsd/dev/i386/FBConsole.c`(plan 341 이어서; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §370 S5-P353 세부 계획 — `bsd/specfs/spec_vnodeops.c`·`bsd/ufs/ufs_dir.c` 남은 레지스터 차이 해결(plan 354·355 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §371 진단 메모 — plan 370 방법(암시적 int ↔ void 반환형)을 남은 차이에 적용(07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §372 S5-P354 세부 계획 — `bsd/ufs/ufs_lockf.c`(Net/2 바탕 D052 + 작성 D024; plan 295·367 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §373 S5-P355 세부 계획 — `machdep/i386/pmap.c`(D029: Darwin 0.1 바탕 + 수정; plan 275 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-321-373.md](plans/RECONSTRUCTION_PLAN-321-373.md)
- §374 진단 메모 — plan 373 뒤 남은 레지스터·식 차이(07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §375 S5-P356 세부 계획 — `driverkit/libDriver/Kernel/devswAndVfssw.m`(D030 작성, Darwin 0.1 과 거의 같음; plan 364 조사 메모 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §376 S5-P357 세부 계획 — `driverkit/objc_support.m`(D054 ④, D030 꼴 작성; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §377 진단 메모 — `bsd/net/if_vtrip.c`(D054 ②, 이름 추정; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §378 진단 메모 — `bsd/swapfs/swapfs.c`(D054 ①, 이름 추정; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §379 S5-P358 세부 계획 — 커널 `bsd/dev/i386/FBConsole.c`(D024·D030, Darwin 0.1 바탕; plan 341·369·374 진단 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §380 진단 메모 — plan 379 뒤 남은 레지스터 차이(swapfs·vtrip·ip_output; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §381 S5-P359 세부 계획 — `bsd/net/if_vtrip.c`(D054 ②, 이름 추정, D024 작성) + `nextdev_private/bsd/net/tokensr.h` 4.2 꼴(plan 377·380 이어서; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §382 진단 메모 — `machdep/i386/machine_clock.c`(plan 365·380 이어서; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §383 S5-P360 세부 계획 — `bsd/netinet/ip_output.c` 루프 체크섬 저장(plan 175.1·380 이어서; D024 작성; 코딩 전, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §384 진단 메모 — plan 383 뒤 남은 둘(swapfs_mount·machine_clock; 07 손대지 않음, 2026-10-07) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §385 진단 메모 — 일치 객체를 증거로 쓰는 관용구 탐색과 machine_clock 의 RTL 추적(07 손대지 않음, 2026-10-07 밤) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §386 진단 메모 — machine_clock clock_timer_init: 원본 바이트를 내는 구조를 찾음, 남은 것은 레지스터 순서(07 손대지 않음, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §387 계획 — 잔여 둘의 다음 탐색(codex 영어 질의 kgmj50qsl·k6t2bclxs 취합; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §388 S5-P361 세부 계획 — `bsd/swapfs/swapfs.c`(D054 ①, 이름 추정, D024 작성) 07 배치(plan 378·387 이어서; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §389 진단 메모 — machine_clock clock_timer_init 잔여 1 바이트(복사 레지스터) 재탐색(07 손대지 않음, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §390 S5-P362 세부 계획 — `machdep/i386/machine_clock.c`(plan 240 작성, D024) 07 배치(plan 386·389 이어서; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §391 진단 메모 — 마지막 미기록 구간 [0x15a628, 0x15a67c) 84 B(D054 ③; 사용자 지시로 다룸; 07 손대지 않음, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §392 S5-P363 세부 계획 — D056: [0x15a628, 0x15a67c) 84 B 를 07 `kern/ipc_xxx.c` 끝에 붙여 ipc_xxx 객체를 [0x15a39c, 0x15a67c) 로 다시 기록(코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §393 S6-1 세부 계획 — L2 링크(사용자 지시 2026-10-08 "L2 링크 작업을 진행합니다"; 코딩 전) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §394 S6-2 세부 계획 — D057: 현재 07 로 전체 재빌드(L0)와 객체별 L1 재판정, 링크 입력 확정(코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §395 S6-3 세부 계획 — L0 자족 빌드의 남은 틈 둘: SDK `mach-o/fat.h` 들이기, `PCKeymap.c` 작성본 선택(plan 394 항목 18; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §396 S6-4 세부 계획 — L2-A: 링크 입력의 빈 곳 찾기(원본 절별 배정·기호 대조; 빌드 없음, 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §397 S6-5 세부 계획 — L2-B: 링크 입력의 빈 곳 메우기(구간별 출처 정하기, 링커 규칙 탐침, 데이터만 있는 객체 작성; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §398 S6-6 세부 계획 — L2-B 07 반영: 데이터만 있는 객체 17 과 기존 객체 8 고침(plan 397·D058; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §399 S6-7 세부 계획 — L2 시험 링크(진단; 실제 `__common` 배치를 얻어 B5 를 정하기 위함, 07 변경 없음; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §400 S6-8 세부 계획 — B5: 원본 공통 기호 25 개의 정의(07 고침; plan 399 항목 7·D059; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §401 S6-9 세부 계획 — B5b: 공통 기호 어긋남 5 개 고침(plan 399 항목 9; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §402 S6-10 세부 계획 — L2 링크 마무리: `strip -x` 단계와 도구 등록(코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §403 진단 메모 — L3(부팅) 확인 방법 조사(07·기록 변경 없음, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §404 S6-11 세부 계획 — D061: 이번에 넣은 Darwin·Mach4 줄에 고지 붙이기(주석·기록만; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §405 S7-1 세부 계획 — L3 준비: 07 에서 만든 커널로 QEMU(i386) 부팅 시험 준비(부팅은 하지 않음; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §406 S7-2 세부 계획 — L3 부팅 시험(QEMU i386; 사용자 시작 확인 뒤 실행, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §407 S7-3 세부 계획 — 기록 공백 보완: `Event.defs`·`audio.defs` 의 PROVENANCE·MODIFICATIONS 행(기록만, 07 코드·빌드 변경 없음; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §408 S7-4 세부 계획 — x86 기록 마무리: 등급 P 70 객체의 링크 배치 증명과 재판정 규칙, `STATUS.md` 갱신(07·빌드 변경 없음; 코딩 전, 2026-10-08) → [plans/RECONSTRUCTION_PLAN-374-408.md](plans/RECONSTRUCTION_PLAN-374-408.md)
- §409 M0-1 세부 계획 — m68k·SPARC 사전 측정: 실기 교차 도구 확인과 1997 i386 빌드 동일성 측정(07·x86 기록·도구 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §410 M1 세부 계획 — D065: i386 mk-183.34 조각 보관과 판 차이 후보 12 객체의 원인 확인(07·x86 표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §411 M0-5 세부 계획 — m68k 용 도구 확장 1: 빅엔디언 재배치 읽기(`macho_obj.py`)와 m68k L1 비교(`l1_compare.py`)(07 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §412 M0-3 세부 계획 — m68k ABI 탐침: C·Objective-C·어셈블리·MIG 를 `cc-744.13 -arch m68k` 로 컴파일하고 목적 파일 검사(07·기존 탐침·도구 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §413 M0-2 세부 계획 — m68k: `cc-744.13` 과 1997 원본 m68k 컴파일러의 코드 동일성 측정(07·x86 표·기존 도구 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §414 M0-2 후속 — §413 의 m68k 차이 원인 분리: 플래그 격자, 머리 구조 차이, 명령 수준 분류(07·x86 표·기존 도구 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §415 M2-1 세부 계획 — m68k 원본 `__TEXT,__text` 의 객체 후보 지도: 외부 기호를 x86 재빌드 객체에 대응(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §416 M2-2 세부 계획 — m68k `__text` 구간 경계: 이름 없는 함수 진입점과 참조로 정적 함수를 객체에 귀속(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §417 M2-3 세부 계획 — 자료 절 표로만 쓰이는 정적 함수의 귀속과 미결정 경계 재판정(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §418 M2-4 세부 계획 — 자료 절이 링크 순서를 따른다는 관찰로 코드 참조 자료 항목의 소유를 넓히고 미결정 경계 재판정(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §419 M2-5 세부 계획 — m68k 자료 절(`__data`·`__const`) 객체 지도, `__cstring`·`__bss`·`__common` 관찰(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §420 M2-6 세부 계획 — m68k 전용(대응 없는) `__text` 구간을 NeXTMach 소스 파일 후보로 나누기(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §421 M2-7 세부 계획 — 갈라진 x86 객체 13 과 이웃 흡수 후보 16 을 NeXTMach 파일 단위로 다시 묶기(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §422 M2-8 세부 계획 — m68k 원본 안의 libcc 구성원 후보를 L1 로 판정(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §423 M2-9 세부 계획 — m68k 객체 후보 목록 통합과 분모(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §424 M2-10 세부 계획 — m68k 함수 목록과 분모: 진입점마다 도달 분석으로 함수 범위 확인(07·기존 도구·표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §425 M3-1 세부 계획 — m68k 구성 가설 `DRIVERKIT 0`(→ `MACH_SLOCKS 0`)을 재컴파일로 시험(07·기존 표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §426 M3-2 세부 계획 — m68k `machparam.h` 가 인라인 spl 을 가져왔다는 가설을 재컴파일로 시험(07·기존 표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §427 M3-3 세부 계획 — m68k 구성 가설 `GDB 1` 을 재컴파일로 시험(07·기존 표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §428 M3-4 세부 계획 — 46 객체 중 남은 4 NOT_MATCH 의 명령 수준 진단(07·기존 표 변경 없음; 진단만, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §429 M3-5 세부 계획 — 지금까지의 m68k 구성으로 이름 대응 공통부 208 객체를 컴파일·대조(07·기존 표 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §430 M3-6 세부 계획 — m68k `machdep` 머리를 시험 스테이징에 두고 공통부 120 객체를 컴파일·대조(07 변경 없음; 측정만, 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §431 M3-7 세부 계획 — §430 의 깨끗한 집합 중 다른 27 객체(외부 구간 41)의 명령 수준 진단(07 변경 없음; 진단만, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §432 M3-8 세부 계획 — m68k 구성 `MACHINE_AST`(pcb +0x54 비트 0x10)와 `SIMPLE_CLOCK 1` 을 시험 스테이징에서 재컴파일로 시험(07 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §433 M3-9 세부 계획 — m68k 구성·머리 후보를 D068 의 덮어쓰기 트리 `07_kernel/v183.34/m68k/` 에 넣고 같은 결과를 재현(x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §434 M3-10 세부 계획 — m68k 생성물(구성 머리·MIG 출력)의 재생성 명령과 해시(07 코드 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §435 M3-11 세부 계획 — D070: `subr_kudp`·`if_venip` 의 m68k 판이 `<machine/spl.h>` 를 가져오게 해 인라인 spl 회복(x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)
- §436 M3-12 세부 계획 — §435 뒤 깨끗한 NOT_MATCH 중 원인을 아직 진단하지 않은 객체의 명령 수준 진단(07 변경 없음; 진단만, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-409-436.md](plans/RECONSTRUCTION_PLAN-409-436.md)

## 437. M3-13 세부 계획 — m68k `_panic` 의 ROM Monitor 줄을 덮어쓰기 소스로 시험(x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §436 에서 m68k `_panic` 이 원본보다 30 B 짧은 원인 후보는 NeXTMach `bsd/subr_prf.c:515-516` 의 `printf ("NeXT ROM Monitor %d.%d v%d\n", mg->mg_major, mg->mg_minor, mg->mg_seq);` 입니다. 07 `subr_prf.c:543` 은 i386 원본에 맞춰(계획 220) 그 줄을 뺐습니다. 이것은 아키텍처 차이이므로 D068 덮어쓰기 트리에 둡니다.

확인한 사실(이번 세션, 읽기 전용):
- 원본 m68k `_panic`(0x400bc66)은 다음과 같이 동작합니다(§436 덩어리).
  - `movel @_mon_global,a3` 로 시작합니다.
  - `movew a3@(0x30c)`·`a3@(0x30a)`·`a3@(0x312)` 를 차례로 넣고 `printf` 를 부릅니다(문자열 0x40a62ad "NeXT ROM Monitor %d.%d v%d\n").
  - `moveml d2/a2/a3` 로 레지스터를 보존합니다.
- 원본 기호표에 `_mon_global`(0x40b69bc, section 6)이 있습니다.
- NeXTMach `panic` 은 `#if NeXT` 안에서 `extern struct mon_global *mon_global; struct mon_global *mg = mon_global;` 를 선언하고(484–490 행), 머리는 `#import <mon/global.h>`(117 행)입니다.
- NeXTMach `mon/global.h:99-101` 의 순서는 `short mg_minor, mg_seq; int (*mg_anim_run)(); short mg_major;` 입니다.
  - m68k 에서 0x30a 부터 놓으면 0x30a·0x30c·(0x30e 포인터)·0x312 가 되어 원본 변위와 상대 위치가 맞습니다(python).
  - 그 머리는 `mon/` 7 개와 `next/cpu.h`·`next/machparam.h` 를 가져와 닫힘이 큽니다.
- 07·m68k 스테이징에는 `mon/` 경로가 없습니다(find 0).

방법:
1. 07 덮어쓰기 `07_kernel/v183.34/m68k/src/bsd/kern/subr_prf.c` = 07 본 파일에 표시된 줄만 끼운 것입니다(지우거나 고치는 줄 없음).
   - `#endif NeXT`(114 행) 앞에 `#import <mon/global.h>` 를 넣습니다.
   - `panic` 의 `int bootopt` 다음에 NeXTMach 484–490 행 꼴의 두 선언을 넣습니다.
   - 543 행 앞에 NeXTMach 515–516 행의 `printf` 두 줄을 넣습니다.
   - 끼운 줄마다 끝에 `/* plan 437 (m68k) */` 를 붙입니다.
2. 07 덮어쓰기 `07_kernel/v183.34/m68k/src/mon/global.h`: 프로젝트 작성 부분 머리(D024)입니다.
   - `struct mon_global` 에 앞부분 채움 `char mg_pad0[0x30a]` + NeXTMach 이름의 네 멤버만 둡니다(원본 바이트 근거: `_panic` 의 변위).
   - NeXTMach 저작권 줄을 넣고(식별자 출처), 머리 주석에 "M4 에서 NeXTMach 전체 머리로 바꿀 후보" 를 적습니다.
   - 전체 머리를 지금 들이지 않는 이유는 위의 큰 닫힘과, 커널 공통부에서 쓰는 곳이 `panic` 하나뿐이라는 점입니다.
3. `stage_m68k.py` 의 파생 검사를 일반화합니다.
   - 등록된 표시(`plan 435 (D070)`·`plan 437 (m68k)`)가 붙은 줄을 모두 빼면 07 본 파일과 바이트까지 같아야 합니다.
   - D070 표시는 지금처럼 하나만, `#import <sys/param.h>` 바로 다음에만 허용합니다.
   - 기존 줄 끝에 붙은 표시는 그 줄을 빼면 본 파일과 달라지므로 거부됩니다.
   - 음성 시험을 다시 합니다.
4. 새 스테이징, 205 재컴파일(새 run), 미리 정한 기준:
   - `x86-subr_prf` 외 204 는 §435 run 과 비 STABS 절이 같습니다.
   - `x86-subr_prf` 는 `_panic` 구간이 같아지고 OBJECT_MATCH 가 됩니다(146 → 147). 잃은 것은 0, 미정의 기호 가운데 원본에 없는 것도 0 입니다.
   - 다르면 진단만 하고 07 을 그대로 둡니다(덮어쓰기 파일은 시험 결과와 함께 기록).
   - x86 관문(7 스테이징 불변)도 확인합니다.
5. PROVENANCE·MODIFICATIONS 에 행을 덧붙이고, diff `06_reconstruction/evidence/m68k-subr_prf.diff` 를 만듭니다. 기록은 `09_validation/reconstruction/m3-m68k-panic-20261009.json` 입니다.

### 437.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_panic`: `moveml d2/a2/a3` → `clrl d2`(bootopt) → `movel 0x40b69bc,a3`(mg, 선언 순서) … `movew a3@(0x30c/0x30a/0x312)` 를 오른쪽 인자부터 넣음(seq·minor·major) → `printf` | §414 원본 목록(`otool-V10/image.txt`) 0x400bc66–0x400bd0c 를 awk 로 읽음 | ✅ 초기화 꼴(`struct mon_global *mg = mon_global;`)이 a3 의 이른 적재와 맞음 |
| `addaw #0x20` vs `#0x1c` 와 `pea ""` 차이는 ROM 줄로 생긴 대기 스택 조정 차이(GCC 2.7 `calls.c` 의 32 B 기준) | 원본에 `pea 0x40a62e7`(빈 문자열 후보)·`addaw #0x20` 있음 확인; GCC 내부 설명은 미검증 | ⚖️ 설명은 가설, 판정은 실행 |
| 원본에 `mach_ldebug` 없음 → NeXTMach 484–486·509–511 은 넣지 않음 | §434.1 에서 `_mach_ldebug` 부재 확인(x86 표 17 행 근거와 같음) | ✅ |
| printf 는 542(`#if NeXT`)와 543 사이에 넣어야 함; 선언 둘을 `#if NeXT` 로 감쌀지 밝힐 것 | 07 540–545 행 읽음 | ✅ printf 두 줄은 542 와 543 사이, 선언 둘은 감싸지 않음(이 파일은 m68k 전용 덮어쓰기, `NeXT` 정의됨) |
| `<mon/global.h>` 는 `-Isrc/src` 로 덮어쓰기 `src/mon/global.h` 에 닿고 충돌 없음; `ddm.c` 는 다른 파일(`mon/mon_global.h`)이고 205 명령에 없음; `version` 은 `sys/systm.h:52` 에 선언 | 스테이징 `systm.h:52` 읽음, `cc.cmd` 의 `ddm` 0 건, §437 사실의 find 0 | ✅ |
| 채움 구조체: 0x30e 포인터·0x312 는 정렬 ≤ 2 에서만 성립 — m68k 최대 정렬 2(계획 412) | MULTIARCH 표준 275 행 "정렬 최대 2 바이트" 읽음 | ✅ 머리 주석에 `mg_pad0` 은 작성 이름, `sizeof` 는 원본과 다름, 다른 멤버 없음(쓰면 컴파일 오류)을 적음 |
| 파생 검사 일반화: D070 표시는 0 또는 1 개(있으면 `sys/param.h` 다음), 덮어쓰기 `.c` 마다 등록 표시 1 개 이상, 07 본 파일에는 표시 문자열 없음, 이어지는 줄에도 표시, 음성 시험(437 표시를 기존 줄 끝에 붙임·섞임) | 현재 `check_derived` 는 D070 정확히 1 개를 요구(읽음); 07 `src` 에 "plan 437" 0 건(grep) | ✅ 모두 반영. 위치 검사는 하지 않으므로 diff 파일이 위치 근거 |
| `--plan 437` 은 `EXCEPTS` 에 437 이 있어야 받음; 미리 정할 값: differ `['x86-subr_prf']`, same_non_stabs 204, byte_identical 87, object_match [146, 147], gained `['x86-subr_prf']`, lost [], stage_vs_test_stage 19 | `stage_m68k.py` main 의 `int(a[1]) in EXCEPTS` 읽음 | ✅ 그대로 미리 정함 |
| "원본에 없는 미정의 기호 0" 은 지금 `compare` 가 계산하지 않음(`_spl*` 만) | 도구 읽음 | ✅ 객체마다 원본 기호표에 없는 미정의 기호를 세고, 기준 객체에 없던 것만 "새로 생김" 으로 집계(기대 {}) |
| 새 문자열은 원본처럼 "panic: (Cpu" 와 "panic: %s" 사이(0x40a6299 < 0x40a62ad < 0x40a62c9) | 원본 목록의 `pea` 세 주소 읽음 | ✅ 실행 뒤 `__cstring` 순서 확인 |

### 437.2 실행 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-panic-20261009.json`

07 덮어쓰기 파일:
- `v183.34/m68k/src/bsd/kern/subr_prf.c`: 07 본 파일에 `plan 437 (m68k)` 표시 줄 5 개를 끼웠습니다.
  - 114 행 `#import <mon/global.h>`
  - `panic` 안에 NeXTMach 488–489 행의 선언 둘
  - 542 와 543 사이에 515–516 행의 `printf` 두 줄
  - diff 는 `06_reconstruction/evidence/m68k-subr_prf.diff` 입니다.
- `v183.34/m68k/src/mon/global.h`: 작성 부분 머리(채움 + 네 멤버).
- PROVENANCE 1069 → 1071, MODIFICATIONS 593 → 595(덧붙이기만).

`stage_m68k.py`:
- `--plan 437` 와 예외(`x86-subr_prf`)를 더했습니다.
- 파생 검사를 일반화했습니다.
  - 등록된 표시마다 허용 파일과 표시 줄 수를 정합니다(D070: `subr_kudp`·`if_venip` 각 1, 437: `subr_prf` 5).
  - 표시 줄을 빼면 07 본 파일과 같아야 하고, 07 본 파일에는 표시 문자열이 없어야 합니다.
  - D070 줄은 `sys/param.h` 다음에만 허용합니다.
  - 정상판 3 개는 통과하고 음성 시험 10 개는 모두 거부합니다.
- 비교 요약에 "원본에 없는 새 미정의 기호" 를 더했습니다.
  - 첫 계산은 STABS 기호까지 세는 제 오류가 있었고, `stab` 을 빼도록 고쳐 비교만 다시 돌렸습니다(재컴파일 없음).
  - 도구 해시는 `08_build/artifacts/m3p437/tools-pre.sha` 에 있고, 마지막 판(d013ad1d…)이 기록과 같습니다.
  - 스테이징·명령은 그 앞 판으로 만들었으며, 바뀐 것은 `compare` 부분뿐입니다.

결과:
- 스테이징 `m0p437-stage` 는 888 파일(덮어쓰기 바꿈 13·더함 10)입니다. x86 관문에서 7 스테이징이 모두 같습니다.
- run `m3p437-cc1` 은 205 명령이 모두 종료 0 이고 616 파일을 게시했습니다.
- 미리 정한 값과 모두 같습니다.
  - 비 STABS 절이 같은 것 **204**, 다른 것은 `x86-subr_prf` 하나입니다.
  - 바이트까지 같은 것 87 입니다.
  - OBJECT_MATCH 는 **146 → 147** 이고(얻은 것 `x86-subr_prf`, 잃은 것 0), 미정의 `_spl*` 는 0 입니다.
  - 원본에 없는 새 미정의 기호는 0 입니다(새 미정의 `_mon_global` 은 원본에 있음).
  - 시험 스테이징 대비 다른 파일은 19 입니다.
- 객체 `__cstring` 순서 "panic: (Cpu"(24) < "NeXT ROM Monitor"(44) < "panic: %s"(72) 는 원본 순서와 같습니다.

해석:
- m68k `_panic` 은 NeXTMach 의 ROM Monitor 줄과, 원본 변위로 정한 `struct mon_global` 부분 정의로 원본과 같아집니다.
- 이 줄은 m68k 전용 차이입니다. i386 은 계획 220 그대로 둡니다.

## 438. M3-14 세부 계획 — m68k 구성 값 전체 재확인과 `KERNOBJC 0` 시험(x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §434 의 m68k 덮어쓰기 표에는 4 값만 있고, 나머지 49 옵션은 x86 값을 그대로 씁니다. M3 를 닫기 전에 x86 표의 옵션마다 m68k 원본으로 같은 값이 맞는지 봅니다.

확인한 사실(이번 세션, 읽기 전용, python):
- x86 표 근거 칸에 적힌 `_` 기호를 m68k 기호표와 대조했습니다. 갈리는 옵션은 다음과 같습니다.
  - `simple_clock`·`driverkit`: 이미 덮어씀.
  - `pc_support`: `_PCcreate` 등 3 개가 m68k 에 없음.
  - `uxpr`: `_uxprGlobal` 등 3 개가 없음.
  - `xpr_debug`: 근거 `_IOMalloc`·`_IOAddDDMEntry` 가 없음(DriverKit 이 없어서).
  - `en`: `_en_recv_pkt`·`_en_send_pkt` 가 없음.
  - `od`: `_odattach` 가 m68k 에만 있음.
- 그 매크로를 쓰는 곳(m68k 스테이징, i386 디렉터리 제외 grep):
  - `PC_SUPPORT`·`NOD`·`DLI`·`FP_EMUL` 은 생성 머리뿐입니다.
  - `UXPR` 은 `kern/xpr.h:125` 인데 `#if XPR_DEBUG`(0) 안이라 효과가 없습니다.
  - `NEN` 은 `if_ether.c`, `NPTY` 는 `tty_pty.c`(둘 다 비청정), `MAXUSERS` 는 `conf/param.c`(205 밖), `MACH_LDEBUG` 는 `kern/lock.h`(DRIVERKIT 0 이면 MACH_SLOCKS 0) 입니다.
  - `KERNOBJC` 는 `kernserv/kern_server.c:604-607·834-837` 의 `objc_registerModule`·`objc_unregisterModule` 호출입니다. `kern/thread.c` 는 머리만 가져옵니다.
- §431 진단: `kern_server` 의 다른 구간은 `_kern_serv_load_objc`·`_kern_serv_shutdown` 둘이고, 각각 객체에만 `_objc_registerModule`·`_objc_unregisterModule` 호출이 있습니다(CALL 덩어리 하나씩).
- m68k 원본에는 그 두 기호가 없고(python), `__OBJC` 절도 없습니다(§423). mk-108.1 `conf/MASTER.next:88` RELEASE 에 `kernobjc` 가 없습니다(grep 0).

방법:
1. 새 도구 `10_tools/reconstruction/m3_m68k_config_review.py` 로 옵션마다 표를 만듭니다. 기록은 `09_validation/reconstruction/m3-m68k-config-review-20261009.json` 입니다.
   - 표의 열: 매크로, x86 값, m68k 덮어쓰기 값, 근거 기호의 x86·m68k 유무, m68k 스테이징에서 매크로를 쓰는 파일(i386 디렉터리 제외), 205 객체 가운데 그 파일을 소스로 가진 것, 판정.
   - 판정은 다음 넷 중 하나입니다: "같음(근거 같음)", "덮어씀", "m68k 후보값 있음 — 쓰는 객체가 아직 없어 미룸", "근거 없음".
   - 매크로 사용 검사는 grep 기준입니다(전처리 닫힘이 아님 — 한계로 적음).
2. `KERNOBJC 0` 을 `06_reconstruction/config_options-m68k.tsv` 에 덧붙입니다(hypothesis → 시험 뒤 판정). `gen_config_headers.py --arch m68k` 로 `v183.34/m68k/generated/kernobjc.h` 를 생성하고 PROVENANCE·MODIFICATIONS 에 행을 덧붙입니다.
3. 새 스테이징과 205 재컴파일(`stage_m68k.py --plan 438`, 예외 `x86-kern_server`)을 합니다. 미리 정한 기준은 다음과 같습니다.
   - `kern_server` 만 이전 run 과 달라지고 OBJECT_MATCH 가 됩니다(147 → 148).
   - `thread` 는 그대로입니다. 잃은 것 0, 원본에 없는 새 미정의 기호 0 입니다.
   - x86 관문은 불변입니다.
   - 다르면 표 행을 hypothesis 로 남기지 않고 되돌린 뒤 진단만 합니다.
4. 다른 후보값(`pc_support` 0, `uxpr`, `en`, `od`, `cputypes`, `maxusers`, `pty`, `mach_ldebug`)은 지금 205 객체의 코드에 영향이 없거나 쓰는 객체가 비청정이라, 바꾸지 않고 표에 "미룸" 으로 기록합니다. M4·M5 에서 그 객체를 만들 때 정합니다.

### 438.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 사실 목록이 불완전: `pc_support` 는 4 기호(`_PCresume` 포함), `od` 는 `_odopen` 도, `mach_debug` 의 `_stack_usage_lock` 은 x86 에만(MACH_SLOCKS 0 이면 `decl_simple_lock_data` 가 비어 정상) | 근거 칸 원문과 두 기호표 python 대조: `_PCresume`·`_PCcallMonitor`·`_stack_usage_lock` x86 만, `_odopen`·`_odattach` m68k 만 | ✅ **내 오류**: 예비 조사 정규식 `(?<![\w/.])` 이 `/` 뒤 기호를 빠뜨림 — 도구에서는 `/` 를 허용 |
| 205 컴파일 모두 `-imacros meta_features.h` 로 `KERNOBJC` 를 봄(`meta_features.h:17`), 그러나 `#if KERNOBJC` 는 `kern_server.c` 의 두 곳뿐 | `meta_features.h:17` 읽음; §438 사실의 grep(같은 결과) | ✅ |
| 크기: 객체 3846 B, 원본 구간 3804 B, 차 42 = 지워질 두 호출 덩어리(24 + 18); 원본 `_kern_serv_load_objc` 10 B | 실행 결과로 확인(재컴파일 뒤 크기 비교) | ⏭️→ 실행으로 |
| **도구가 `--plan 438` 을 받지 못함**(`EXCEPTS` 에 438 없음) | `stage_m68k.py:40-43` 읽음 | ✅ `EXCEPTS[438]` 추가 |
| **비교는 기준 run(`m3p429-cc2`·`m3p432-int`)과 하므로 예외는 누적돼야 함** — 438 예외 = `x86-subr_prf`(§437) + `x86-kern_server` | `cmd_compare` 가 `REFS` 와 비교함(읽음) | ✅ 계획 정정; 기준: differ = 두 객체, same_non_stabs 203, object_match [146, 148], gained 두 객체 |
| 바이트 동일은 기준이 아님(STABS 줄 번호) — `sections_differ` 기준 | §433 이후 그대로 씀 | ✅(기존 기준 유지) |
| 미루는 옵션 가운데 205 에 영향 없는 것: `NEN` 은 `if_ether.c:98-102` 가 `#else vax` 에서 0 으로 재정의, `NPTY` 는 `tty_pty.c:70-73` 이 1 일 때만 바꿈, `mach_ldebug.h` 는 undetermined 라 생성되지 않음 | 세 곳 읽음, `generated/mach_ldebug.h` 없음 | ✅ 표에 "소스가 재정의"·"생성 안 됨" 으로 따로 적음 |
| `cputypes.h`: CMU config 는 cpu 줄마다 `#define <cpu> 1`; `MASTER.next:96 cpu "NeXT"` → `#define NeXT 1` = 컴파일 줄의 `-DNeXT` 와 같음 | `MASTER.next` 96 행은 실행 때 도구로 읽어 기록; mkmakefile 설명은 미검증 | ⚖️ "같은 효과로 보임(미검증 부분 있음)" 으로 기록, 바꾸지 않음 |
| grep 방법의 한계: 머리 닫힘 아님, 다른 매크로를 거친 시험(MACH_SLOCKS·PRI_SHIFT 등), 지역 재정의·주석·`#ifdef` 도 사용으로 셈, `machdep/ppc` 도 셈 | 설계 | ✅ 도구가 `#if`/`#ifdef`/`#define`/주석을 나눠 세고 `machdep/{i386,ppc,hppa,sparc}` 를 빼며, 한계를 기록에 적음 |
| 미루는 옵션이 OBJECT_MATCH 객체에 쓰이는 경우(STAT_TIME·KERNEL_STACK·MACH_DEBUG 등)는 지금 값으로 이미 일치 — 바꿀 근거 없음 | 147 일치 사실 | ✅ "현재 값으로 일치하는 객체가 있음" 열을 둠 |

### 438.2 실행 결과(2026-10-09) — 기록 `m3-m68k-kernobjc-20261009.json`(재컴파일), `m3-m68k-config-review-20261009.json`(옵션 표)

**`KERNOBJC 0`**
- `06_reconstruction/config_options-m68k.tsv` 에 행을 덧붙였고, `generated/kernobjc.h` 를 `gen_config_headers.py --arch m68k` 로 생성했습니다.
  - 기존 m68k 머리 4 개는 바이트가 그대로입니다(SHA 확인). x86 `--check` 는 종료 0 입니다.
  - PROVENANCE 1071 → 1072, MODIFICATIONS 595 → 596(덧붙이기만).
- `stage_m68k.py` 에 `EXCEPTS[438]` 를 넣었습니다(§437 의 `x86-subr_prf` + `x86-kern_server`, 기준 run 과 비교하므로 누적).
- 실기 run `m3p438-cc1` 은 205 명령이 모두 종료 0 이고, 스테이징 888 파일, x86 관문 7 스테이징이 같습니다. 도구 해시는 실행 전후가 같습니다(`08_build/artifacts/m3p438/tools-pre.sha`).
- 미리 정한 값과 모두 같습니다.
  - 비 STABS 절이 같은 것 203, 다른 것은 `x86-kern_server`·`x86-subr_prf` 입니다.
  - OBJECT_MATCH 는 **146(기준 run) → 148**(얻은 것 두 객체, 잃은 것 0)입니다.
  - 미정의 `_spl*` 0, 원본에 없는 새 미정의 기호 0 입니다.
- 결과에 따라 표 행의 상태를 confirmed 로 고쳤습니다(오늘 쓴 행, 행 수 그대로). 생성 머리는 바뀌지 않습니다(`--check` 종료 0).

**옵션 표**
- 도구 `10_tools/reconstruction/m3_m68k_config_review.py`(11d2afb3…)로 x86 표 53 옵션을 판정했습니다.
  - 근거 같음 27, 덮어씀 4(`simple_clock`·`driverkit`·`kernobjc`·`gdb`; `iplmeas` 는 x86 표에 없음), 생성 안 됨 3(`new_vm_code`·`mach_vm_debug`·`mach_ldebug`), 기호 근거 없음 13, **근거가 갈려 미룸 6**입니다.
- 미룬 6 개와 이유:
  - `pc_support`·`od`: 값을 시험하는 파일이 스테이징에 없습니다(i386 전용·m68k 전용 장치는 M4).
  - `uxpr`·`xpr_debug`: 시험이 `kern/xpr.h`·`driverkit/ddm.c` 뿐이고, `#if XPR_DEBUG`(0) 안이거나 205 밖입니다.
  - `en`: `if_ether.c:98-102` 가 non-vax 에서 `NEN 0` 으로 다시 정의하므로 생성값이 효과가 없습니다.
  - `mach_debug`: `_stack_usage_lock` 이 m68k 에 없는 것은 `MACH_SLOCKS 0`(DRIVERKIT 0)에서 `decl_simple_lock_data` 가 비기 때문이고, 값 1 로 `thread`·`zalloc`·`ipc_kobject` 가 일치하므로 바꿀 근거가 없습니다.
- 한계(기록에 적음): 전처리 닫힘이 아닌 문자열 검사입니다. 다른 매크로를 거친 시험과 머리를 통한 사용은 객체에 연결하지 않았습니다. `cputypes.h`(빈 머리)가 `MASTER.next:96 cpu "NeXT"` 의 config 출력과 같은 효과라는 점은 검토 의견일 뿐 미검증입니다.

해석: x86 값을 그대로 쓰는 m68k 옵션 가운데, 지금 컴파일하는 205 객체에 영향을 주면서 근거가 갈리는 것은 남지 않았습니다. 미룬 6 개는 그 값을 쓰는 객체를 M4·M5 에서 만들 때 정합니다.

## 439. M3-15 세부 계획 — 다시 만든 m68k 객체로 §418 의 미결정 경계 판정(07 변경 없음; 표는 새 판으로; 코딩 전, 2026-10-09)

배경: §418 경계 326 개 가운데 미결정은 11 개입니다. 그중 양쪽 객체를 m68k 로 다시 만든 것은 셋입니다(k=130 `ufs_vfsops`|`ufs_vnodeops`, k=191 `kern_notify`|`kern_server_handler`, k=193 `kern_server_reply_user`|`exc_server`). 나머지 8 개는 대응 없는 구간·SCSI·`.word` 행과 맞닿아 있어 이번 대상이 아닙니다.

확인한 사실(이번 세션, python):
- k=191: OBJECT_MATCH 인 `kern_server_handler` 의 L1 자리는 0x40576ce 이고, 이는 하한과 같습니다(구간 [0x40576ce, 0x4057d74]). `kern_notify` 의 L1 끝도 0x40576ce 입니다.
- k=193: OBJECT_MATCH 인 `exc_server` 의 자리는 0x4058090 이고 하한과 같습니다. `kern_server_reply_user`(OBJECT_MATCH)의 끝도 0x4058090 입니다.
- k=130 은 [0x403a04c, 0x403a056] 입니다.
  - `ufs_vnodeops` 객체 첫 36 B 가 0x403a056 에서 같습니다(§436).
  - `ufs_vfsops` 는 결정된 k=129 의 0x4039568 에서 첫 32 B 중 3 B 만 다릅니다(재배치 필드로 보임).
  - 원본 범위 [0x4039568, 0x403a056) 는 2798 B 로 객체 2884 B 보다 86 B 짧습니다. 후보 원인은 §430 에 기록된 i386 `_byte_swap_*` 호출입니다.
  - `ufs_vfsops` 의 L1 자리 0x403952e("외부 기호 기준") 에서는 첫 32 B 가 모두 달라, §436 의 `ufs_vnodeops` 와 같은 자리 오류입니다.

방법(새 도구 `10_tools/reconstruction/m2_m68k_boundaries_built.py`; 입력 §418 표·기록, run `m3p438-cc1` 객체와 L1 기록):
1. 판정 규칙은 다음과 같습니다(미리 정함).
   - b 쪽이 OBJECT_MATCH 이면 그 L1 `__text` 자리를 경계로 봅니다.
   - a 쪽이 OBJECT_MATCH 이면 자리 + 크기를 경계로 봅니다.
   - 둘 다 아니면 b 객체 `__text` 첫 64 B(재배치 필드를 가림)가 [하한, 상한] 안의 짝수 주소 가운데 정확히 한 곳에서 같을 때 그 주소를 경계로 봅니다.
   - 어느 경우든 값이 [하한, 상한] 안이어야 합니다. 두 근거가 함께 있으면 서로 같아야 합니다.
2. k=130 의 a 쪽 정합 확인을 합니다. 실기 `otool -tv`(읽기 전용)로 `ufs_vfsops` 객체를 풀고, §436 도구 방식으로 [0x4039568, 0x403a056) 와 전체 정규화 비교를 합니다. 86 B 차이가 모두 `_byte_swap_*` 관련 덩어리여야 합니다. 아니면 k=130 을 결정하지 않습니다.
3. 산출:
   - 새 표 `06_reconstruction/m68k-text-boundaries-built.tsv` 는 §418 표 326 행 전체를 그대로 옮기고 열 `decided_439`·`boundary_439`·`basis_439` 를 더합니다. §418 표는 바꾸지 않습니다.
   - 기록은 `09_validation/reconstruction/m2-m68k-boundaries-built-20261009.json` 입니다.
   - §423 객체 목록의 "정확 경계" 수가 몇 개 늘어나는지 python 으로 셉니다(표는 다시 만들지 않고 기록만 합니다).
4. 음성 시험: 첫 64 B 대조를 경계 ±2·±4 로 옮겨 맞지 않음을 보입니다. 또 이미 결정된 경계 가운데 양쪽이 다시 만든 객체인 것 전부에 같은 규칙을 적용해, §418 값과 어긋남이 0 인지 봅니다.

### 439.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| k=191·193 의 L1 자리·끝 값 맞음; 단 `kern_notify` 는 NOT_MATCH 라 규칙 1.2 의 a 쪽 근거가 못 됨(정합 확인일 뿐) | §439 사실의 python 출력 | ✅ 규칙에 "a 쪽 근거는 OBJECT_MATCH 일 때만" 명시 |
| `ufs_vfsops` 의 0x4039568 차이 바이트는 27–29·51 이고, 각각 외부 pc 상대 재배치(offset 26, 4 B)와 지역 pc 상대 재배치(offset 48) 안 | python: 첫 64 B 차이 offset [27, 28, 29, 51], 재배치 (48, len 2, pcrel, local)·(26, len 2, pcrel, extern) | ✅ |
| 0x403a04c 의 10 B 진입점 = 객체 마지막 함수 `_ufs_badvfsop`(offset 2874; 2874 − 86 = 2788 = 0x403a04c − 0x4039568) — 하한 쪽 미해결 진입점은 a 쪽 함수 | python: 원본 0x403a04c 10 B 와 객체 끝 10 B 가 같음(`48562c4f70164e5e4e75`), 마지막 기호 `_ufs_badvfsop` 2874 | ✅ k=130 의 결정 근거는 a 쪽 전체 비교(관문)로 둠 |
| 같은 10 B 꼴이 `__text` 에 여러 번(11) 나타나므로 b 쪽 첫 바이트만으로는 k=130 을 정할 수 없음 | 도구에서 셈 | ⏭️→ 도구 기록 |
| 첫 64 B 규칙은 MIG 머리말 반복 때문에 유일하지 않을 수 있음(k=191 에서 3 곳) → 둘 다 OBJECT_MATCH 아닐 때만 쓰고, 후보는 [하한, 상한] 안의 **진입점**, 여럿이면 판정 보류 | 설계(도구에서 다시 셈) | ✅ |
| 재배치 가림: scattered PAIR 항목은 건너뛰고 나머지는 `1 << r_length` 바이트 | `l1_compare` 관례(검토 의견), 도구에 구현 | ✅ |
| 모든 205 객체 `__text` 정렬 2^1·크기 짝수 → 채움 없음; 결정된 경계 195 개(양쪽 재빌드) 중 OBJECT_MATCH 쪽 확인 모두 일치 | 도구에서 다시 셈 | ⏭️→ 음성 시험에 포함 |
| **음성 시험 설계가 무의미**: 결정된 경계는 하한 = 상한이라 "구간 안 유일" 이 자명 → 창을 (a_last, b_first] 로 넓혀 시험 | §418 표의 결정 행 lower = upper 확인(k=129 등) | ✅ 창 (a_last, b_first] 의 진입점으로 규칙 1.3 을 시험: 틀린 판정 0 이어야 함(놓침·보류는 허용, 수를 기록) |
| 6 객체(`m68k-123`·`124`·`184`–`187`)가 정확해져 300 → 306, 정확 바이트 76.70 % → 78.89 % | 도구에서 다시 셈 | ⏭️→ 도구 기록 |
| 2 단계의 합격 기준을 미리 정할 것; L1 의 잘못된 자리 대신 0x4039568·0x403a056 을 강제로 씀 | 설계 | ✅ 기준: (a) 객체 − 원본 바이트 차 합 = 86, (b) 객체에만 있는 호출은 `_byte_swap_*` 뿐, (c) 원본에만 있는 호출 0, (d) 그 밖의 덩어리는 바이트 차 0. 하나라도 어긋나면 k=130 은 결정하지 않음 |

### 439.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-boundaries-built-20261009.json`, 표 `06_reconstruction/m68k-text-boundaries-built.tsv`

도구 `10_tools/reconstruction/m2_m68k_boundaries_built.py`.
- 첫 실행은 §423 표의 `data-only` 행(시작 칸이 빔)에서 멈췄고, 고친 뒤 다시 돌렸습니다. 해시는 `08_build/artifacts/m3p439/tool-pre.sha` 에 있고, 마지막 판(f9564bab…)이 기록과 같습니다.
- `ufs_vfsops` 의 실기 `otool -tv` 목록은 `08_build/artifacts/m3p439/otool/` 에 두었고, 객체 SHA 를 실기 `krsha256` 과 대조했습니다.

결과:
- **k=191 → 0x40576ce**(규칙 1: `kern_server_handler` OBJECT_MATCH 자리), **k=193 → 0x4058090**(규칙 1 + 2 일치)로 결정했습니다.
- **k=130 은 결정하지 않았습니다**(미리 정한 a 쪽 관문 불통과).
  - 규칙 3 은 [하한, 상한] 안의 진입점 가운데 0x403a056 한 곳에서만 맞았습니다.
  - 관문에서 객체 − 원본 바이트 차의 합이 86 이 아니라 82 였습니다. 정규화로 같다고 본 분기도 길이가 다를 수 있어 4 B 가 덩어리 밖에 남은 것으로 보입니다(미검증).
  - 객체에만 있는 호출에 `_byte_swap_superblock`·`_byte_swap_ints` 말고도 `_copyin` 이 있고, 원본에만 `_copyinmsg` 가 있습니다(`ufs_mount`, 07·NeXTMach `ufs_vfsops.c:124` 는 `copyin`).
  - `bwrite` 정렬 덩어리 쌍(−8·+10)이 있었습니다.
  - `mountfs` 의 프레임 변위가 4 B 다릅니다(`linkw #0xffb0` 대 `#0xffb4`; 바이트 차 0 인 D-frame 13 개).
  - 0x403a04c 진입점의 10 B 는 `ufs_vfsops` 객체의 마지막 함수 `_ufs_badvfsop` 과 같습니다(§439.1). 따라서 경계가 0x403a056 이라는 근거는 강하지만, 미리 정한 기준이 아니어서 이번에는 결정하지 않습니다.
- 음성 시험(양쪽이 다시 만든 객체인 결정 경계 195 개)은 모두 통과했습니다.
  - 규칙 1 확인 142·규칙 2 확인 143, 어긋남 0.
  - 규칙 3 을 넓은 창 (a_last, b_first] 로 돌리면 맞음 179·놓침 14·모호 2·**틀림 0**.
  - ±2·±4 이동 거짓 일치 0.
- 새 표는 §418 표 326 행에 `decided_439`·`boundary_439`·`basis_439` 를 더한 것입니다(§418 표는 그대로). 결정된 것은 315 + 2 = 317 입니다.
- §423 객체 목록에 미치는 효과(표는 다시 만들지 않음):
  - 정확한 객체가 300 → 304(`m68k-184`–`187` = `kern_notify`·`kern_server_handler`·`kern_server_reply_user`·`exc_server`)입니다.
  - 정확 바이트는 520,436 → 524,384(`__text` 678,510 B 의 76.70 % → 77.28 %)입니다.
  - 검토자가 예상한 6 개 가운데 `m68k-123`·`124`(k=130) 는 들지 않았습니다.

새 M5 후보:
- `ufs_vfsops` `ufs_mount` 에서 원본은 `copyinmsg` 를 부릅니다.
- `mountfs` 의 지역 변수 4 B 차이가 있습니다(바이트 교환 외).

## 440. M3-16 세부 계획 — 경계 규칙 4(a 쪽 끝 함수 + b 쪽 첫 바이트의 맞닿음)로 k=130 다시 판정(사용자 지시 "진행합니다"; 07 변경 없음; 코딩 전, 2026-10-09)

배경: §439 에서 k=130 은 미리 정한 a 쪽 전체 비교 관문을 통과하지 못해 미결정으로 남았습니다(바이트 차 82 ≠ 86, `ufs_mount` 의 원본 `copyinmsg`, `mountfs` 프레임 4 B). 그 관문은 a 객체 전체가 바이트 교환 말고는 같아야 한다는 강한 조건이었습니다. 경계를 정하는 데 필요한 것은 "a 가 어디서 끝나고 b 가 어디서 시작하는가" 입니다. 그래서 끝과 시작이 맞닿는지만 보는 규칙을 새로 정하고, 이번에도 결과를 보기 전에 미리 정합니다.

확인한 사실(이번 세션, python):
- `ufs_vfsops` 객체의 마지막 함수(offset 2874, 10 B, 재배치 없음)와 같은 바이트열은 원본 `__text` 에 11 번 나옵니다(0x403a04c 포함).
- k=130 의 [하한, 상한] 안 진입점은 0x403a04c·0x403a056 두 개입니다.
- §439: `ufs_vnodeops` 의 가린 첫 64 B 는 그 안에서 0x403a056 에만 맞습니다.

규칙 4(미리 정함; 양쪽 다 다시 만든 객체이고 둘 다 OBJECT_MATCH 가 아닐 때만):
1. a 객체 `__text` 의 마지막 함수(마지막 기호부터 끝까지, 길이 L)를 재배치 필드를 가려 원본 진입점 e_a 와 대조합니다. e_a 의 범위는 [a_last, 상한] 안의 진입점입니다.
2. b 객체 첫 min(크기, 64) B 를 가려 진입점 c 와 대조합니다(§439 규칙 3 과 같은 방법). c 의 범위는 [하한, 상한] 입니다.
3. e_a + L = c 인 짝이 **정확히 하나**이면 c 를 경계로 정합니다. 없거나 둘 이상이면 보류합니다.
4. c 는 [하한, 상한] 안이어야 합니다.

음성 시험(미리 정함):
- 양쪽을 다시 만든 결정 경계 195 개에 규칙 4 를 넓은 창으로 적용합니다(e_a 는 [a_last, b_first] 진입점, c 는 (a_last, b_first] 진입점). **틀린 판정 0** 이어야 하고, 맞음·보류 수를 기록합니다.
- k=130 에서 c 를 ±2·±4 로 옮기면 짝이 성립하지 않아야 합니다.
- 하나라도 틀리면 규칙 4 를 쓰지 않습니다.

방법: §439 도구 `m2_m68k_boundaries_built.py` 에 `--plan 440`(규칙 4 추가, 규칙 1–3·관문은 그대로)을 더합니다. 표 `06_reconstruction/m68k-text-boundaries-built.tsv` 를 같은 열로 다시 만들고(근거 칸에 `rule4 (plan 440)`), 기록은 `09_validation/reconstruction/m2-m68k-boundaries-built4-20261009.json` 입니다. §439 기록은 그대로 둡니다. §423 객체 정확 수의 효과도 다시 셉니다.

해석 한계: 규칙 4 는 두 객체가 맞닿는다는 것만 보입니다. a 객체 안쪽의 차이(`copyinmsg`·프레임)는 M5 항목으로 남습니다.

### 440.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **"미리 정함" 은 k=130 에 대해 정직하지 않음**: 규칙의 두 입력(0x403a04c 의 10 B, 0x403a056 의 b 머리)을 이미 안 뒤에 정했으므로 k=130 에는 사전 등록 시험이 아님; 독립 근거는 음성 시험뿐 | §440 본문을 다시 읽음(사실 목록에 두 입력이 있음) | ✅ **내 오류** — 기록 문구를 "§439 결과를 본 뒤 사용자 지시로 정한 규칙; k=130 에는 사후 판정, 독립 근거는 음성·특이성 시험" 으로 고침 |
| 끝 함수 10 B 는 식별력이 없음(같은 꼴 11 곳; 다른 객체의 끝 함수와도 거짓 짝 25 / 39,780) → 고정 길이 a 꼬리(마지막 min(크기, 64) B, 가림)가 c 에서 끝나야 한다는 꼴이 더 강함 | 11 곳은 §440 사실의 python 출력; 거짓 짝 수는 도구에서 다시 셈 | ✅ 규칙 4 를 "a 꼬리 64 B" 로 바꿈 |
| 규칙 4 는 규칙 3(b 머리)을 포함하므로, 음성 시험의 힘은 규칙 3 이 모호했던 경계에서만 생김 | 설계 확인 | ✅ 기록에 "규칙 4 ⊂ 규칙 3 의 제한" 이라고 적고, 교차 짝 특이성 시험을 더함(아래) |
| 구조 근거: 객체 기호 `_getmdev`·`_ufs_vget`·`_ufs_badvfsop` 을 −86 옮기면 원본 진입점 0x4039f30·0x4039fae·0x403a04c 에 놓임 | python: 세 기호만 −86 에서 진입점과 일치(앞쪽 3 개는 0 에서, `_ufs_unmount`–`_sbupdate` 는 어느 쪽도 아님) | ✅ 보조 근거로 기록 |
| `e_a ≥ 하한` 조건은 일반적으로 틀림(결정 경계는 하한 = 상한) | 설계 확인 | ✅ 넣지 않음 |
| "마지막 함수" 의 정의를 밝힐 것 | — | ⏭️ 꼬리 꼴로 바꿔 필요 없음 |

고친 규칙 4(이 판정표 뒤, 실행 전에 고정):
- 양쪽 다 다시 만든 객체이고 둘 다 OBJECT_MATCH 가 아닐 때만 씁니다.
- a 객체 `__text` 의 마지막 min(크기, 64) B(재배치 필드 가림)가 원본에서 c 바로 앞에서 끝나고, b 객체 첫 min(크기, 64) B(가림)가 c 에서 시작하는 진입점 c 가 [하한, 상한] 안에 **정확히 하나** 일 때 c 로 정합니다.

시험:
- (i) 결정 경계 195 개에 넓은 창 (a_last, b_first] 로 적용합니다. **틀림 0** 이어야 하고, 맞음·보류 수를 기록합니다.
- (ii) 교차 짝 특이성: 결정 경계마다 참 경계 c 에서 다른 모든 다시 만든 객체의 a 꼬리, 그리고 다른 모든 객체의 b 머리가 성립하는 거짓 짝 수를 셉니다(판정 관문이 아니라 기록용).
- (iii) k=130 에서 c ±2·±4 를 확인합니다.
- (i) 에서 틀림이 하나라도 있으면 k=130 을 정하지 않습니다.

### 440.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m2-m68k-boundaries-built4-20261009.json`, 표 `06_reconstruction/m68k-text-boundaries-built.tsv`(다시 만듦)

도구는 `m2_m68k_boundaries_built.py --plan 440`(84feae6b…, `08_build/artifacts/m3p439/tool-pre.sha`)입니다. 규칙 1–3 과 관문은 §439 와 같습니다.

**정직성 표시**: 규칙 4 는 §439 결과(k=130 의 두 사실)를 본 뒤 사용자 지시로 정했습니다. 따라서 k=130 에 대해서는 사후 판정이고, 독립 근거는 아래 시험들입니다. 규칙 4 는 규칙 3(b 머리)에 a 꼬리 조건을 더한 제한입니다.

결과:
- **k=130 → 0x403a056(규칙 4)** 입니다.
  - [하한, 상한] 진입점 가운데 짝이 성립하는 곳은 0x403a056 하나입니다.
  - c ±2·±4 는 모두 불성립입니다.
  - 다시 만든 다른 객체의 64 B 꼬리 가운데 0x403a056 에서 끝나는 것은 없습니다(검토자가 짚은 10 B 끝 함수의 `spec_vfsops` 거짓 짝은 64 B 꼬리에서 사라짐).
  - 보조 근거: 객체 기호 `_getmdev`·`_ufs_vget`·`_ufs_badvfsop` 을 −86 옮기면 원본 진입점에 놓입니다(§440.1).
- 시험 (i): 결정 경계 195 개(양쪽 다시 만든 객체)에 넓은 창으로 규칙 4 를 적용했습니다. **맞음 172·틀림 0**·보류 23(모두 짝 없음)입니다.
- 시험 (ii), 교차 짝 특이성(기록용): 참 경계에서 다른 객체의 꼬리가 성립한 것 20 건, 다른 객체의 머리가 성립한 것 6 건입니다.
  - 그래서 꼬리나 머리 하나만으로는 식별력이 완전하지 않습니다.
  - 판정은 둘이 함께 맞고 창 안에서 하나일 때만 합니다.
- 표: §439 판과 비교하면 k=130 행의 덧붙인 세 열만 바뀌었습니다(`1`, `0x403a056`, `rule4 (plan 440)`). 앞 13 열과 다른 행은 같습니다(diff). 결정 경계는 318/326 입니다.
- §423 객체 효과(표는 다시 만들지 않음):
  - 정확한 객체가 300 → **306** 입니다(`m68k-123` `ufs_vfsops`·`124` `ufs_vnodeops`·`184`–`187`).
  - 정확 바이트는 520,436 → 535,278 B, `__text` 의 76.70 % → **78.89 %** 입니다.
- §439 기록(`m2-m68k-boundaries-built-20261009.json`)은 그대로 두었습니다.

## 441. M3-17 세부 계획 — m68k `need_ast` 의 정의 자리와 `_hardclock` 의 `_clock_value` 경로(조사·결정 대기; 07 변경 없음, 2026-10-09)

확인한 사실(이번 세션, python·grep):
- 원본 m68k `_need_ast` 는 `__common`(section 6) 0x40b6064 이고 크기는 4 B(다음 기호까지)입니다. 바로 앞이 `_last_hardclock`(0x40b605c), 바로 뒤가 `_file_zone`(0x40b6068) 입니다.
- 다시 만든 m68k 객체(run `m3p438-cc1`) 가운데 `_need_ast` 를 언급하는 7 개(`kern_clock`·`kern_sig`·`ast`·`ipc_sched`·`sched_prim`·`task`·`thread`)는 모두 미정의(UNDF)로만 참조합니다.
  - 07 `kern/ast.c:74-76` 이 `#ifndef MACHINE_AST` 일 때만 정의하는데, m68k 는 §432 부터 `MACHINE_AST` 입니다.
  - 이대로면 M7 링크에서 미정의 기호가 됩니다.
- B2-1 규칙(§397·§399: `__common` 순서 = 링크 순서에서 처음 언급(UNDF·COMMON 가리지 않음)한 객체, 그 안에서는 기호표 순) 으로 보면 다음과 같습니다.
  - 다시 만든 객체 가운데 처음 언급자는 링크 순서상 첫째인 `kern_clock`(원본 0x40033d2)입니다.
  - 원본 m68k `_hardclock` 은 `_last_hardclock` 에 쓰고 `ast` 를 검사하므로, `_last_hardclock`·`_need_ast` 가 이어 놓인 것과 맞습니다.
  - 뒤의 `_file_zone` 을 처음 언급하는 객체는 다음 객체 `kern_descrip` 입니다.
- NeXTMach mk-108.1 에서 `need_ast` 를 정의하는 곳은 `kern/ast.c:76`(`int need_ast[NCPUS];`, 조건 없음) 하나입니다. `next/` 기계 의존부에는 언급이 없습니다(grep).
- 따라서 정의(COMMON)는 `kern_clock` 과 같거나 뒤의 어느 객체에 있어도 원본 배치와 같습니다. 바이트만으로는 정의 파일을 정할 수 없습니다(x86 B5 의 `_master_cpu` 등과 같은 경우 — 그때도 사용자에게 물었습니다).
- `_hardclock` 의 `_clock_value` 경로:
  - 원본 m68k `_hardclock` 은 `pea 1; bsr _clock_value; lea _last_hardclock` 꼴로 `clock_value(1)` 를 `last_hardclock` 과 함께 씁니다(§431 덩어리).
  - `_clock_value` 는 m68k `__text` 0x40920aa 에 있는 함수입니다(기계 의존부로 보임).
  - 07 `kern_clock.c` 의 `hardclock` 은 x86 원본에서 작성한 판(계획 233)이고, NeXTMach `bsd/kern_clock.c:169-210` 은 `usec_elapsed` 꼴이라 둘 다 이 꼴이 아닙니다.
  - 이것은 m68k(또는 183.34) 전용 소스 블록이라 **M5 작성 항목**으로 넘깁니다(이번에는 고치지 않음).

결정이 필요한 것(사용자):
- `need_ast` 를 어디서 정의할지 정해야 합니다.
- 후보 (가): m68k 덮어쓰기 `kern/ast.c` 에 NeXTMach `kern/ast.c:76` 자리처럼 조건 없는 `volatile ast_t need_ast[NCPUS];` 를 둡니다(표시 줄 방식, `#ifndef MACHINE_AST` 는 초기화 고리에만 남김).
  - `ast` 는 `kern_clock` 뒤이므로 배치가 바뀌지 않습니다.
  - `ast` 객체의 `__text` 는 그대로일 것으로 예측합니다(COMMON 은 절 바이트를 바꾸지 않음).
- 후보 (나): M7 링크 때까지 미룹니다.

### 441.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **NeXTMach `kern/ast.c:75-77` 은 조건 없음이 아님**: `#if !HW_AST` 안이고 RELEASE 는 `hw_ast` → NeXTMach next 커널은 `need_ast` 를 정의하지 않음. 조건 없는 `volatile ast_t need_ast[NCPUS];` 는 Mach4 `kernel/kern/ast.c:58`·Darwin `kern/ast.c:82`(둘 다 초기화 고리만 `#ifndef MACHINE_AST`) | NeXTMach 72–88 행, Mach4 ast.c grep(58·63–68), Darwin ast.c grep(82·87–92) 읽음 | ✅ **내 오류**(앞선 grep 결과를 잘못 읽음) — 후보 (가) 의 출처를 Mach4 `kern/ast.c:58`(D022 기본 참고)로 고침 |
| 원본 `__text` 가 0x40b6064 를 17 번 참조하고, 그중 2 곳(0x4099e66, 0x409a328)은 trap 쪽 기계 의존 객체 → 원본 언급 객체는 9 개 | python 으로 `__text` 에서 4 B 값 검색: 17 곳, 주소 목록 일치 | ✅ trap 두 곳은 링크 순서상 뒤라 배치에 영향 없음; M5 에서 언급자로 더함 |
| `kern_clock` 앞의 객체(다시 만든 것·안 만든 것 모두)는 `need_ast` 를 언급하지 않음(원본 바이트에 0x400344e 아래 참조 없음; B2-1 로도 그렇다면 kern_acct 공통 기호 앞에 놓였을 것) | 위 17 곳 중 최소 주소 0x400344e(= `_hardclock` 안) 확인 | ✅ |
| `_hardclock` 은 `need_ast` 를 "검사" 가 아니라 `ast_on(AST_UNIX)` 꼴로 씀 | 원본 목록(§431 덩어리 `orl d6,d0`) | ✅ 문구 정정 |
| 덮어쓰기 파생 검사는 끼운 표시 줄만 허용 → (가) 는 07 `ast.c:76` 뒤에 표시 줄 하나 `volatile ast_t need_ast[NCPUS];` 를 끼우는 꼴이고, `MARKERS` 에 `{'src/kern/ast.c': 1}` 을 더해야 함 | `stage_m68k.py` `check_derived` 읽음(§437 에서 작성) | ✅ |
| 형은 07 `kern/ast.h:102` 의 `extern volatile ast_t` 와 같아야 함(NeXTMach `int` 는 충돌) | 07 `ast.h:102` grep(§441 사실) | ✅ |
| 07 `kern/ast.h:123-142` 가 `need_ast` 를 조건 없이 쓰므로, 07 `ast.c` 의 정의 가드(계획 198)는 Mach4 의 `MACHINE_AST` 뜻(aston/astoff 만 바꿈)과 맞지 않음 — (가) 를 뒷받침 | `ast.h` 123–142 행은 §441 grep 출력에 있음 | ✅ |
| `_last_hardclock`(8 B, 64 비트 산술 → `ns_time_t`)은 `kern_clock` 의 잠정 정의로 보이며, 다시 만든 `kern_clock` 은 아직 언급하지 않음(M5) | 원본 크기 8 확인(§441) | ✅ M5 항목에 더함 |
| 정의 파일은 바이트로 정해지지 않음(trap 등도 가능) → 사용자 결정 | — | ✅ |

고친 후보 (가):
- m68k 덮어쓰기 `kern/ast.c` 는 07 본 파일 76 행(`#endif MACHINE_AST`) 뒤에 `volatile ast_t\tneed_ast[NCPUS];\t/* plan 441 (m68k): Mach4 kern/ast.c:58 */` 한 줄을 끼웁니다.
- 출처는 Mach4 `kernel/kern/ast.c:58`(Darwin `kern/ast.c:82` 도 같은 줄)입니다. 07 `ast.c` 에는 CMU 고지가 이미 있지만 Mach4 판(Utah 포함) 고지 여부를 기록합니다.
- 예측: `ast` 객체는 기호 하나만 UNDF → COMMON(4) 으로 바뀌고 절 바이트는 그대로이며, 205 의 OBJECT_MATCH 는 그대로입니다.

### 441.2 사용자 결정 D071 과 구현 계획(코딩 전)

- 사용자 결정 **D071**: "ast.c 덮어쓰기 (Recommended)".
- 덮어쓰기 `07_kernel/v183.34/m68k/src/kern/ast.c` 는 07 본 파일 76 행 뒤에 다음을 끼웁니다.
  - 계획 404(`vm/vm_kern.c`) 선례대로 Mach4 고지(Mach4 `kernel/kern/ast.c` 1–28 행)를 먼저 넣습니다.
  - 그 뒤에 Mach4 58 행과 같은 정의 줄을 넣습니다.
- 여러 줄 고지에는 줄마다 표시를 달 수 없으므로 `stage_m68k.py` 의 파생 검사에 **묶음 표시**를 더합니다.
  - `plan 441 (m68k) begin` 이 있는 줄부터 `plan 441 (m68k) end` 가 있는 줄까지가 끼운 줄로 셈해집니다.
  - 표시별 줄 수는 등록합니다(등록 수 = 묶음 전체 줄 수).
  - 묶음이 닫히지 않거나 겹치면 거부합니다. 음성 시험을 다시 합니다.
- `EXCEPTS[441]` 은 §438 과 같습니다(`x86-subr_prf`·`x86-kern_server`). 기준 run 과 비교하므로 `ast` 는 비 STABS 절이 같아야 합니다.
- 미리 정한 기준(새 run)은 다음과 같습니다.
  - 비 STABS 절이 같은 것 203, 다른 것은 위 두 예외뿐입니다.
  - OBJECT_MATCH 148 은 그대로입니다.
  - `ast` 객체의 `_need_ast` 는 COMMON(값 4) 입니다.
  - 원본에 없는 새 미정의 기호 0, x86 관문은 불변입니다.
- 기록: PROVENANCE·MODIFICATIONS 에 행을 덧붙입니다. 출처는 nextmach(본 파일) + mach4 `kernel/kern/ast.c:58`(revision 은 PROVENANCE 의 기존 mach4 행과 같은 것)입니다. diff `06_reconstruction/evidence/m68k-ast.diff`, 기록 `09_validation/reconstruction/m3-m68k-need-ast-20261009.json` 입니다.

### 441.3 실행 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-need-ast-20261009.json`

07 덮어쓰기와 기록:
- `v183.34/m68k/src/kern/ast.c` 는 07 본 파일 76 행 뒤에 32 줄 묶음(`plan 441 (m68k) begin`…`end`)을 끼운 것입니다.
  - 묶음은 Mach4 `kernel/kern/ast.c:1-28` 고지와 58 행 정의 줄입니다.
  - diff 는 `06_reconstruction/evidence/m68k-ast.diff` 입니다.
- PROVENANCE 1072 → 1073, MODIFICATIONS 596 → 597(덧붙이기만).

`stage_m68k.py`:
- 묶음 표시를 지원합니다(시작 줄부터 끝 줄까지 셈, 닫히지 않음·겹침·다른 표시 섞임 거부). `MARKERS` 에 `ast.c: 32`, `EXCEPTS[441]` 를 더했습니다.
- 정상판 4 개는 통과했습니다.
- 음성 시험은 모두 거부했습니다. 대상은 묶음 미종결, 시작 없는 끝, 묶음 안 줄 추가·삭제, 묶음 밖 수정, 표시 없음, 묶음 둘, 묶음 안 다른 표시, 그리고 이전 경우들입니다.
  - 처음 두 경우는 바꿀 줄을 07 본문 머리에서 잘못 골랐습니다(같은 문장이 2 행에도 있음). 묶음 안 줄로 다시 시험했습니다.

결과:
- 스테이징 `m0p441-stage` 는 888 파일이고, x86 관문 7 스테이징이 같습니다.
- run `m3p441-cc1` 은 205 명령이 모두 종료 0 입니다. 도구 해시는 실행 전후가 같습니다.
- 미리 정한 값과 같습니다.
  - 비 STABS 절이 같은 것 203 이고, 다른 것은 예외 둘(`kern_server`·`subr_prf`)뿐입니다.
  - OBJECT_MATCH 148 은 그대로입니다. 잃은 것 0, 원본에 없는 새 미정의 기호 0 입니다.
  - `ast` 객체의 `_need_ast` 는 **COMMON(4)** 입니다(나머지 6 객체는 UNDF 그대로).
- 남은 M5 항목(§441·441.1):
  - m68k `_hardclock` 의 `clock_value(1)`·`last_hardclock`(`ns_time_t`, `kern_clock` 의 잠정 정의로 보임) 블록 작성.
  - 기계 의존 trap 두 객체의 `need_ast` 참조.

## 442. M3-18 세부 계획 — m68k 커널 비공개 레지스터 색인(`PC`·`SP`·`PS`·`R0`·`R1`)과 남은 컴파일 실패 3 개(조사·결정 대기; 07 변경 없음, 2026-10-09)

배경: §430 부터 m68k 에서 컴파일되지 않는 공통부 C 가 3 개 있습니다.
- `bsd/kern/mach_process.c:170` 과 `bsd/kern/kern_exec.c:482` 는 `PC` 가 선언되지 않았습니다(`SP` 도 씀).
- `kern/ns_timer.c:43·47·147·150` 은 i386 인라인 어셈블리 `divl` 를 씁니다.

확인한 사실(이번 세션):
- 두 소스는 `#import <machine/reg.h>` 로 SDK `bsd/machine/reg.h` → `bsd/m68k/reg.h` 를 읽습니다. m68k SDK `bsd/m68k/reg.h` 에는 `excp_frame` 등만 있고 `u_ar0` 색인이 없습니다(공개판).
- NeXTMach mk-108.1 `next/reg.h:198-203` 에는 "offset definitions into u.u_ar0 for machine independent code" 로 `R0 0`·`R1 1`·`SP 15`·`PS 17`·`PC 17` 이 있습니다.
- 원본 m68k 바이트는 이 색인과 맞습니다(python: 15×4 = 0x3c, 17×4 = 0x44).
  - `_execve`(0x40048fc) 범위에서 `movel a3,a0@(0x3c)`, `movel a0@(0x3c),d0`/`movel d0,a0@(0x3c)`(SP − NBPW), `movel d0,a0@(0x44)`(PC = entry point) 를 씁니다.
  - `_ptrace`(0x400ad9a) 범위에서 `orl d0,a3@(0x44)`(PS 비트) 를 씁니다.
- x86 선례: 같은 문제(SDK 공개판에 색인 없음)를 `07_kernel/nextdev_private/bsd/i386/reg.h`(설명 주석 + Darwin 의 `KERNEL_PRIVATE` 본문, 계획 144)로 풀었습니다. `07_kernel/nextdev_private/` 와 SDK 사본 `07_kernel/nextdev/` 는 통째로 git 무시 대상입니다(`.gitignore:72-73`; D017 SDK 라이선스 미정).
- `ns_timer.c` 의 `divl` 는 i386 전용 소스 블록입니다. m68k 원본의 해당 함수를 읽어 m68k 판을 작성해야 하는 **M5 작성 항목**이며, 이번 범위에서 뺍니다.

결정이 필요한 것(사용자): m68k 레지스터 색인을 어디에 둘지.
- (가) x86 선례대로 로컬 전용 `07_kernel/nextdev_private/bsd/m68k/reg.h` 에 둡니다.
  - 내용은 SDK m68k 본문 + NeXTMach `next/reg.h:198-203` 색인 블록(`#ifdef KERNEL_PRIVATE`)입니다.
  - `stage_m68k.py` 가 SDK 사본 뒤에 `nextdev_private` 의 m68k 파일을 덮어 놓습니다.
  - 커밋되지 않습니다(SDK 본문 때문).
- (나) 공개되는 m68k 덮어쓰기 트리에 SDK 본문 없이 작성 머리 `src/machdep/m68k/reg_private.h`(NeXTMach 색인 6 줄, D013)를 두고, 두 소스의 m68k 판이 `#import` 합니다(D070 꼴 표시 줄).
- (다) SDK 본문 + 색인을 공개 덮어쓰기 `src/bsd/m68k/reg.h` 에 둡니다(SDK 본문이 공개됨 — D017 과 충돌 가능).

시험(결정 뒤): 새 스테이징으로 205 + 두 객체 = 207 개를 컴파일합니다.
- 미리 정한 기준:
  - 두 객체가 컴파일되어야 합니다.
  - 다른 205 개는 이전 run 과 비 STABS 절이 같아야 합니다(예외 누적 2 개).
  - 원본에 없는 새 미정의 기호가 0 이어야 합니다.
- 두 객체의 원본 대조 결과(OBJECT_MATCH 여부)는 측정합니다. 판정 관문은 아닙니다(소스 쪽 차이가 더 있을 수 있음).

### 442.1 교차검토(Opus 5.5 서브에이전트) 판정과 결론 — 계획의 중심 사실이 틀림

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **SDK m68k `bsd/m68k/reg.h:195-200` 에 이미 `R0 0`·`R1 1`·`SP 15`·`PS 16`·`PCH 16`·`PCL 17` 이 있음; 없는 것은 `PC` 뿐** | SDK 사본 190–202 행 읽음 | ✅ **내 오류**: 예비 조사에서 `grep -v … \| head -60` 으로 잘린 출력만 보고 "색인 없음" 이라 적음 |
| 컴파일 실패는 `PC` 하나(`SP` 는 정의됨) | §430 진단 기록(검토자 인용)과 위 SDK 행 | ✅ |
| 원본 `_ptrace` 는 `PC` 를 둘로 나눠 OR: 0x400aee4–aee8 `swap; extl; orl d0,a3@(0x40)`(슬롯 16 = PCH), 0x400aeec–aef4 `swap; clrw; orl d0,a3@(0x44)`(슬롯 17 = PCL) — §442 의 "0x44 = PS 비트" 해석은 틀림; PT_STEP 은 0x400af3a–af40 `moveq #9; cmpl a2@; bne; bset #7,a3@(0x40)` = `PS 16` 에 `PSL_T`(= `SR_TSINGLE << 16`, `psl.h:43`) | 원본 목록 0x400aee0–0x400af44 읽음, `psl.h:43` grep | ✅ **내 오류**(해석) 정정 |
| 원본 `_execve` 의 PC 쓰기도 나뉨: 0x4005044 `movew a6@(0xff78),a0@(0x42)`(상위 반), 0x4005052–505e `swap; clrw; orw a0@(0x46),d0; movel d0,a0@(0x44)` | 원본 목록 0x4005040–0x4005062 읽음 | ✅ `u.u_ar0[PC] = entry` 한 줄로는 이 바이트가 나오지 않음 |
| NeXTMach `next/reg.h` 의 `PC 17`·`PS 17` 은 다른 `struct regs`(`short pad`) 기준이라 1997 바이트와 맞지 않음; `PC 17` 을 더하면 SDK 틀에서 형식 낱말을 덮어쓰는 틀린 코드 | 위 두 사실(원본은 0x40/0x42/0x44/0x46 을 나눠 씀) | ✅ 선택지 가·나·다(머리에 `PC` 정의)는 모두 버림 |
| x86 선례(`nextdev_private/bsd/i386/reg.h`)는 SDK 에 i386 reg.h 가 아예 없어서였고, m68k 는 SDK 파일이 있고 맞음 | x86 PROVENANCE 행 설명(§442 사실) | ✅ |
| NeXTMach 에 `PCH`/`PCL` 을 쓰는 C 코드 없음 | `grep -rn 'PCH\|PCL'` — `next/reg.h` 밖 결과는 모두 다른 이름(`TS_HUPCLS`·`PCLK_*` 등) | ✅ → m68k 판 두 소스는 원본 바이트에서 작성(D024) |
| `ns_timer.c` 는 무조건 i386 `divl` 인라인 어셈블리; m68k 원본 `_ns_time_to_timeval`(0x404e712)은 68020 `divull`·`divul` 두 단계 나눗셈 | 07 소스 43–50·147–150 행은 §430 기록, 원본 주소는 검토자 인용(미검증) | ⚖️ M5 작성 항목으로 둠(문구 "무조건 i386 asm") |
| `machine/reg.h` 를 들이는 스테이징 소스 14 개; `PS`·`R0`·`R1` 은 `kern_xxx.c` 의 `#ifdef COMPAT`(정의 안 됨) 안에서만 | 검토자 grep 인용 | ⏭️ 머리를 바꾸지 않으므로 영향 없음 |

결론:
- 결정할 머리 자리는 없습니다(SDK 가 맞음). 사용자 질문은 하지 않습니다.
- 남은 세 컴파일 실패는 모두 **M5 작성 항목**입니다.
  - `mach_process.c`·`kern_exec.c` 의 m68k 판: SDK `PCH`/`PCL` 로 PC 를 나눠 쓰는 블록을 원본 바이트에서 작성하고, 표시 묶음으로 끼웁니다.
  - `ns_timer.c` 의 m68k 판: `divull`/`divul` 꼴의 m68k 인라인 어셈블리.
- M3 범위(머리·구성·생성물)는 이 셋에 대해 더 할 일이 없습니다. 07 은 바꾸지 않았습니다.

## 443. M3-19 세부 계획 — M3 끝 조건 점검: 덮어쓰기 구조체 오프셋 탐침과 근거 집계(07 변경 없음; 코딩 전, 2026-10-09)

배경: MULTIARCH 표준 M3 의 끝 조건은 두 가지입니다.
- "M0-3 probe 와 원본의 구조체 오프셋 근거가 맞음"
- "생성 코드가 GCC 2.7 규칙을 만족"

148 OBJECT_MATCH 객체가 쓰는 구조체 변위는 바이트 일치로 이미 확인되었습니다. 그러나 프로젝트가 작성한 m68k 머리(§430–441)의 구조체는 "원본 변위를 내도록 썼다" 는 주장뿐이고, 그 변위가 실제 컴파일러로 나오는지 따로 잰 적이 없습니다.

방법:
1. 탐침 객체를 만듭니다(새 도구 `10_tools/reconstruction/m3_m68k_offsets.py`).
   - 스테이징 `m0p441-stage` 를 복사하고 `src/probe/m68k_offsets.c` 하나를 더합니다(SHA 매니페스트).
   - 탐침은 `int off[] = { ((int)&((struct X *)0)->m), …, sizeof(…) }` 를 `__data` 에 둡니다.
   - 컴파일 명령은 run `m3p441-cc1` 의 `kern/ast.c` 줄과 같은 플래그(`-arch m68k … -g -O2 -c`)이고, 소스·출력만 바꿉니다.
2. 미리 정한 기대값(원본 바이트 근거)은 다음과 같습니다.
   - `struct pcb`(`machdep/m68k/thread.h`): `pcb_regs` 0x48, `pcb_regs_valid` 0x4c(`_init_task` 의 USER_REGS, §430), `pcb_flags` 0x54(aston/astoff `bset/bclr #4,…@(0x54)`, §431–432).
   - `struct pmap`(`machdep/m68k/pmap.h`): `stats.resident_count` 0x10(`_task_info`, §430).
   - `struct mon_global`(`mon/global.h`): `mg_minor` 0x30a, `mg_seq` 0x30c, `mg_anim_run` 0x30e, `mg_major` 0x312(`_panic`, §437).
   - SDK `struct regs`(`bsd/m68k/reg.h`): `r_evec` 0x40, `r_pc`(`r_evec.e_pc`) 0x42. 이것은 `_execve`·`_ptrace` 의 0x40/0x42/0x44/0x46 쓰기(§442.1) 근거이며 M5 작성의 바탕이 됩니다.
   - 탐침 값이 기대와 하나라도 다르면 해당 머리를 고치기 전에 진단만 합니다.
3. 실기 run 을 새 ID 로 돌리고, 실행 전후 도구 해시를 남깁니다. `macho_obj` 로 `__data` 를 읽어 대조합니다(big-endian 4 B).
4. 근거를 집계합니다(기록 `09_validation/reconstruction/m3-m68k-closure-20261009.json`).
   - M0-3 ABI 탐침 기록(§412).
   - §431·§436 명령 수준 진단의 구조체 변위(D-struct) 덩어리 수.
   - 생성물: `gen_config_headers.py` x86·m68k `--check` 종료값, §434 MIG 24/24.
   - 현재 m68k 수치: 205 중 148, 정확 객체 306.
   - M4·M5 로 넘긴 항목 목록.
5. 끝 조건 판정 문단은 MULTIARCH 표준에 적습니다.

### 443.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 기대 변위의 원본 근거 확인: `_init_task` 0x4002dec `tstl a0@(0x4c)`·0x4002df2 `movel a0@(0x48)`, 0x4049464–6e `bset #4,a0@(0x54)`(0x40494ae `bclr`), `_task_info` 0x4052588 `movel a0@(0x10),d3`, `_panic` 0x400bcb8–c4 | §430–437 기록과 이번 세션 원본 목록 확인(`_panic` 줄은 §437.1 에서 읽음) | ✅ 주소를 기록에 인용 |
| `mg_anim_run`(0x30e)의 근거는 `_panic` 이 아니라 0x408a490·0x408acaa·0x40946e6 의 `movel aN@(0x30e),d0`(4 B) | 원본 목록 세 주소 grep: 셋 다 `movel a1/a4@(0x30e:w),d0` | ✅ 근거 인용 |
| 정렬 4 라도 pcb·pmap 은 같은 변위 → 컴파일러 ABI 를 실제로 시험하는 것은 mon_global·regs 뿐 | 설계 확인 | ✅ 기록에 적음 |
| **작성하지 않은 Mach 구조체도 원본 바이트로 대조**: `sizeof(struct task)` 0x80(`_task_init` 0x4051ddc `pea 0x80`, zinit), `sizeof(struct thread)` 0x184(`_thread_init` 0x40527ec `pea 0x184`), `offsetof(thread, pcb)` 0x24, `offsetof(task, map)` 0x8, `offsetof(vm_map, pmap)` 0x20 | 원본 목록 0x4051dc8–ddc·0x40527e0–ec grep(`pea 0x80`·`pea 0x184` 가 zinit 인자 자리) | ✅ 탐침에 더함(진짜 "탐침 대 원본" 대조) |
| `reg.h:174 #if MONITOR` — 0x40 은 MONITOR 미정의일 때만; 스테이징·명령에 정의 없음 | grep: `reg.h` 174·186 행, generated·cc.cmd 0 건 | ✅ 가정으로 적음 |
| 선례 탐침 `probes/c_layout.c` 의 `KR_OFF` 매크로·표시 낱말·비정적 전역을 씀 | 파일 1–20 행 읽음 | ✅ |
| 머리는 명시 경로로(`<machdep/m68k/thread.h>`·`<machdep/m68k/pmap.h>`·`<mon/global.h>`·`<bsd/m68k/reg.h>`), 비트필드 주소 대신 `sizeof(struct excp_frame)` 8·`sizeof(struct regs)` 0x48 | 설계(빌드로 확인) | ✅ |
| diag3 에는 `d_struct_blocks` 키가 없음 → 도구가 종류를 직접 셈; X·R 덩어리는 "구조체 아님" 의 증명이 아님 | diag2 키 확인(§443 사실 출력), diag3 요약 형태 확인 | ✅ 기록 문구에 한계 명시 |
| "생성 코드 GCC 2.7 규칙" 은 `--check`·MIG 일치만으로는 부족 → 그것을 실제로 쓴 m68k 컴파일 run(cc-744.13, `m3p441-cc1`)과 `08_build/GCC27_COMPATIBILITY.md` 규칙 대조를 인용 | 설계 | ✅ 기록에 run 과 해당 문서 절 인용 |
| 원본 `sizeof(struct pcb)`·`sizeof(struct mon_global)` 은 비교 불가 | 설계 | ✅ "비교 안 함" 으로 표시 |
| 스테이징 경로는 `src/probe/…`, 명령 줄 경로는 `src/src/probe/…`(run 의 src 아래) | `cc.cmd` 의 `src/src/kern/ast.c` 꼴 | ✅ 둘 다 명시 |

고친 탐침 목록(실행 전 고정): 표시 `KRM3`…`END!` 사이에 다음 순서로 둡니다.
- pcb 3, pmap 1, mon_global 4
- regs: `r_evec`·`r_pc`·`sizeof(struct excp_frame)`·`sizeof(struct regs)`
- task·thread: `sizeof(struct task)`·`sizeof(struct thread)`·`offsetof(struct thread, pcb)`·`offsetof(struct task, map)`·`offsetof(struct vm_map, pmap)`

기대값은 위 근거대로입니다(`sizeof` 둘은 원본 근거 없음 — 기록만).

### 443.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m3-m68k-closure-20261009.json`

도구는 `10_tools/reconstruction/m3_m68k_offsets.py`(0848118…) 입니다. 실행 전후 해시가 같습니다(`08_build/artifacts/m3p443/tools-pre.sha`).
- 스테이징 `m0p443-stage` = `m0p441-stage` + `src/probe/m68k_offsets.c` 이고, 889 파일입니다.
- run `m3p443-pr1` 은 1 명령이 종료 0 이고 게시되었습니다. 명령은 `kern/ast.c` 와 같은 플래그(cc-744.13 `-arch m68k … -g -O2`)입니다.

탐침 결과: 원본 근거가 있는 **15/15 가 기대값과 같습니다**.

| 항목 | 탐침 값 | 원본 근거 |
|---|---|---|
| `pcb.pcb_regs`·`pcb_regs_valid`·`pcb_flags` | 0x48·0x4c·0x54 | `_init_task` 0x4002df2·0x4002dec, aston 0x404946e |
| `pmap.stats.resident_count` | 0x10 | `_task_info` 0x4052588 |
| `mon_global` `mg_minor`·`mg_seq`·`mg_anim_run`·`mg_major` | 0x30a·0x30c·0x30e·0x312 | `_panic` 0x400bcbe·cb8·cc4, 0x408a490 등 |
| `regs.r_evec`·`r_pc` | 0x40·0x42 | `_ptrace` 0x400aee8·0x400af40, `_execve` 0x4005044 |
| `sizeof(struct task)`·`sizeof(struct thread)` | 0x80·0x184 | `_task_init` 0x4051ddc·`_thread_init` 0x40527ec 의 zinit 인자 |
| `thread.pcb`·`task.map`·`vm_map.pmap` | 0x24·0x8·0x20 | `_init_task`·`_task_info` |

- 기록만 하는 값은 `sizeof(struct excp_frame)` 8, `sizeof(struct regs)` 0x48 입니다(원본 근거 없음).
- pcb·pmap 은 정렬 2·4 어느 쪽이든 같으므로, 컴파일러 ABI(정렬 2)를 실제로 시험한 것은 `mon_global`·`regs` 입니다(§443.1).

근거 집계:
- 명령 수준 진단의 덩어리 종류:
  - §431: CALL 31·X 48·D-frame 20·R 167·INS 37·IMM 6·DEL 7.
  - §436: INS 3·R 58·X 17·CALL 3·DEL 2.
  - 두 진단 모두 **D-struct(구조체 변위만 다른 덩어리) 0** 입니다. X·R 은 구조체 차이가 없다는 증명이 아닙니다.
- 생성물: `gen_config_headers.py` x86·m68k `--check` 종료 0, MIG 24/24(§434). 이 머리·출력을 실제로 쓴 m68k 컴파일은 cc-744.13 run `m3p441-cc1`(205 명령 종료 0)입니다.
- 현재 m68k 수치: 205 중 OBJECT_MATCH 148, 정확 객체 306(`__text` 78.89 %).

**M3 끝 조건 판정**
- (1) 구조체 오프셋: M0-3 ABI 탐침(§412, 정렬 2)과 이번 탐침이 원본 바이트 근거 15/15 와 맞고, 진단 D-struct 0 입니다. → **충족**.
- (2) 생성 코드: 구성 머리는 표와 명령으로, MIG 는 재생성 해시가 일치하며, 둘 다 cc-744.13 m68k 로 컴파일되었습니다. → 머리·생성물 범위에서 **충족**.
- `08_build/GCC27_COMPATIBILITY.md` "완료 판정" 3–5(전체 번역 단위 컴파일·링크·부팅 입력)는 M4–M8 에서 채웁니다.
- 따라서 **M3 를 닫습니다.** 넘기는 항목은 다음과 같습니다.
  - M5(공통부 소스): `mach_process`·`kern_exec` PCH/PCL, `ns_timer` m68k 나눗셈, `_hardclock` `clock_value`·`last_hardclock`, `kern_uname`, PMON, `spldma`, `_byte_swap_*`·`_us_spin`·ObjC 호출 제거, `in_pcb`·`ip_output`·`ip_icmp`·`tcp_input`·`vfs_dnlc` 소스 꼴, `ufs_vfsops` `copyinmsg`·프레임, 비청정 30.
  - M4(기계 의존부): m68k 전용 파일 후보 106·묶음 4·미배정 33·자료만 16, trap 의 `need_ast` 참조, `mon/global.h` 전체판.
  - 구성 미룸 6(§438).

## 444. M5-1 세부 계획 — m68k `mach_process.c`·`kern_exec.c` 의 PC 쓰기를 SDK `PCH`/`PCL` 로 작성(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §442.1 에서 두 소스가 m68k 에서 컴파일되지 않는 이유가 `PC` 하나임을 확인했습니다. SDK m68k `reg.h` 에는 `PS 16`·`PCH 16`·`PCL 17` 이 있고, 원본은 PC 를 둘로 나눠 씁니다. NeXTMach 에 이 꼴의 코드가 없으므로 원본 바이트에서 작성합니다(D024).

확인한 사실(원본 목록 직접 읽음):
- `_ptrace` 0x400aed0–0x400aef4(07 `mach_process.c:162-170` PT_STEP/PT_CONTINUE):
  - `locr0`(a3) = `thread->_uthread->uu_ar0` 이고, `movel a2@(0x8),d0`(uap->addr), `moveq #1; cmpl; beq`(addr != 1) 입니다.
  - `swap d0; extl d0; orl d0,a3@(0x40)` → `locr0[PCH] |= (int)uap->addr >> 16`
  - `movew a2@(0xa),d0; swap d0; clrw d0; orl d0,a3@(0x44)` → `locr0[PCL] |= (int)uap->addr << 16`
  - 지우는 `andl` 이 없으므로 대입이 아니라 OR 입니다.
- `_execve` 0x400503c–0x400505e(07 `kern_exec.c:482`):
  - `movel u,a0; movel a0@,a0`(u.u_ar0)·`movew a6@(0xff78),a0@(0x42)` → PCH 슬롯의 하위 반에 `entry_point` 의 상위 반을 씁니다.
  - 다시 `u.u_ar0` 를 읽어 `movel a6@(0xff78),d0; swap; clrw; orw a0@(0x46),d0; movel d0,a0@(0x44)` → `u.u_ar0[PCL] = (entry << 16) | (u.u_ar0[PCL] & 0xffff)` 꼴입니다.
  - 첫 줄의 C 꼴은 후보 `u.u_ar0[PCH] = (u.u_ar0[PCH] & 0xffff0000) | ((unsigned)entry >> 16)` 입니다(GCC 가 하위 반 `movew` 로 바꾸는지는 실행이 판정).
- 기계 판별: §430 시험 스테이징의 Darwin 배정 머리 `#elif defined (__m68k__)` 가 m68k 가지를 골랐으므로 cc-744.13 `-arch m68k` 는 `__m68k__` 를 정의합니다.

방법:
1. 덮어쓰기 두 소스는 07 본 파일에 표시 묶음(`plan 444 (m68k) begin`…`end`)을 끼웁니다. 원래 줄은 지우지 않고 `#else` 가지에 남깁니다(파생 검사는 끼우기만 허용).
   - `mach_process.c`: 169 행 `if` 뒤에 `#ifdef __m68k__` + `{ locr0[PCH] |= …; locr0[PCL] |= …; }` + `#else` 를 끼우고, 170 행 뒤에 `#endif` 를 끼웁니다.
   - `kern_exec.c`: 482 행 앞에 `#ifdef __m68k__` + 두 줄 + `#else` 를 끼우고, 뒤에 `#endif` 를 끼웁니다.
   - 묶음은 파일마다 둘(시작·끝 위치가 갈림)입니다. `MARKERS` 에 줄 수를 등록합니다.
2. `stage_m68k.py --plan 444`(예외는 §441 과 같음)로 스테이징합니다. 시험 run 은 이 두 객체만 컴파일합니다(§430 `cc.cmd` 의 두 줄, 접두 `P444__`).
   - 스테이징 차이가 이 두 `.c` 뿐임을 매니페스트로 확인합니다. 그러면 다른 205 객체는 입력이 같으므로 다시 컴파일하지 않습니다.
3. 비교(미리 정한 기준):
   - 두 객체가 컴파일되어야 합니다.
   - 원본에 없는 새 미정의 기호 0 이어야 합니다.
   - 외부 구간 `_ptrace`·`_execve` 의 해당 덩어리(§436 도구 방식 진단)에서 PC 쓰기 부분이 원본과 같아야 합니다.
   - 객체 전체 OBJECT_MATCH 여부와 그 밖의 차이는 측정·진단합니다(다른 소스 차이가 있을 수 있음 — 관문 아님).
   - PC 쓰기 부분이 원본과 다르면 C 꼴을 바꿔 새 run 으로 다시 시험합니다(시도마다 기록).
4. 기록: PROVENANCE·MODIFICATIONS(작성 줄, D024), diff `06_reconstruction/evidence/m68k-pc-split.diff`, `09_validation/reconstruction/m5-m68k-pc-split-20261009.json`.

### 444.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 판독은 맞고(OR, `andl` 없음), 구조체 `->r_pc` 꼴은 제외: 같은 원본 `_sendsig` 0x409488a·`_sigreturn` 0x409495c 는 `r_pc` 를 `movel …,a2@(0x42)` 한 번으로 씀 | 원본 목록 두 주소 grep | ✅ 후보 (c) 제외 |
| `_execve` 는 두 문장(0x400504a 에서 `u` 를 다시 읽음); PCH 줄은 짧은 낱말 대입 꼴 `((short *)&u.u_ar0[PCH])[1] = entry >> 16` 이 가장 그럴듯, 그다음 and/or 꼴 | 판독은 §444 사실과 같음; 순위는 미검증 의견 | ⚖️ 후보를 모두 시험 컴파일로 판정 |
| `_ptrace` 의 PCL 쪽은 `movew a2@(0xa)`(하위 반만 읽기)라 `(int)uap->addr << 16` 이 아니라 `& 0xffff` 또는 `(u_short)` 꼴일 가능성(같은 컴파일러가 `_execve` 에서는 `movel` 로 읽음) | `_execve` 0x4005052 `movel a6@(0xff78),d0` 와 `_ptrace` 0x400aeec `movew a2@(0xa),d0` 비교 | ✅ 후보에 더함 |
| 시도마다 run 을 돌리지 말고 후보 꼴을 한 run 에서 탐침 파일로 컴파일(§443 선례) | 설계 | ✅ 변형 파일 방식으로 바꿈 |
| 기계 판별은 07 관례대로 `#if m68k`(`kern/time_stamp.c:55·68`, `kern_sig.c:181 #ifdef i386`) | 두 파일 grep | ✅ `#if m68k` 사용 |
| 한 파일에 같은 표시 묶음 여럿 가능; 한 줄짜리 `#endif` 는 묶음이 아닌 단순 표시 줄 | `check_derived` 설계(§441) | ✅ |
| `EXCEPTS[444]` 가 없으면 `--plan 444` 거부 | §438 경험 | ✅ 도구 변경에 넣음 |
| 원본 `_execve` 에는 PMON 호출(0x4005150–516c `btst #4,0x40b60c0` … `bsr _pmonlogexec`)이 있고 07 에는 없음 → `kern_exec` 은 PC 가 맞아도 OBJECT_MATCH 아님 | 원본 목록 0x4005150–516c 읽음, `_pmonlogexec` 0x4092b56 | ✅ 예측에 넣음 |
| D024 는 객체마다 OBJECT_MATCH 를 조건으로 함 → `kern_exec` 은 PMON 전까지 "중간 상태" 로 기록 | DECISIONS 28 행 읽음 | ✅ |
| 비교 기록을 쓰는 도구를 명시할 것 | — | ✅ 새 도구 `m5_m68k_pc.py` |

고친 방법(실행 전 고정):
1. **변형 시험 run**(새 도구 `10_tools/reconstruction/m5_m68k_pc.py`)
   - 스테이징 `m0p441-stage` 를 복사하고, `src/probe/pc/` 에 07 본 파일 + 후보 블록인 변형 소스를 둡니다.
   - `mach_process` 변형:
     - P1 `|= (int)uap->addr >> 16` / `|= (int)uap->addr << 16`
     - P2 PCL `|= ((int)uap->addr & 0xffff) << 16`
     - P3 PCL `|= (u_short)(int)uap->addr << 16`
   - `kern_exec` 변형:
     - E1 PCH and/or 꼴 + PCL `& 0xffff`
     - E2 PCH 짧은 낱말 대입 + PCL `& 0xffff`
     - E3 짧은 낱말 + PCL `(u_short)`
     - E4 and/or + PCL `(u_short)`
   - §430 `cc.cmd` 의 두 줄과 같은 플래그로 컴파일합니다(접두 `P444__`).
2. 실기 `otool -tv`(읽기 전용)로 변형 객체를 풉니다. 원본의 PC 쓰기 명령열과 비교합니다(주소·`a6` 변위는 가리고 명령·레지스터·나머지 피연산자는 그대로).
   - `_ptrace` 기준: 0x400aeda–0x400aef4 의 10 명령
   - `_execve` 기준: 0x400503c–0x400505e 의 8 명령
   - 같은 변형이 정확히 하나면 그 꼴을 고릅니다. 없으면 진단만 하고 멈춥니다.
3. 고른 꼴을 07 덮어쓰기 두 소스에 `#if m68k` 묶음으로 끼웁니다(`plan 444 (m68k)`). `MARKERS`·`EXCEPTS[444]` 를 더하고, 덮어쓰기 스테이징으로 두 객체를 컴파일합니다(스테이징 차이 = 두 `.c` 확인, x86 관문 포함).
   - 기준: 컴파일 성공, 원본에 없는 새 미정의 기호 0, PC 쓰기 명령열이 원본과 같음.
   - `mach_process` OBJECT_MATCH 여부와 `kern_exec` 의 PMON 차이는 측정해 기록합니다(`kern_exec` 은 중간 상태).

### 444.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pc-variants-20261009.json`(변형), `m5-m68k-pc-split-20261009.json`(최종)

변형 시험(run `m5p444-var1`, 7 명령 종료 0, 실기 otool 목록 SHA 대조):
- 원본 PC 쓰기 명령열과 모양이 같은 것은 P2·P3·E1·E2·E3·E4 입니다.
- P1(`(int)uap->addr << 16`)은 원본의 `movew a2@(0xa)` 대신 `movel a2@(0x8)` 로 읽어 다릅니다(검토 예측대로).
- P2·P3 끼리, E1–E4 끼리는 비 STABS 객체 전체가 같아 바이트로 구별되지 않습니다.
- 미리 정한 "정확히 하나" 규칙은 성립하지 않았고, 사용자 결정 **D072** 로 단순 꼴(P2·E1)을 골랐습니다.

07 덮어쓰기와 기록:
- `v183.34/m68k/src/bsd/kern/mach_process.c` 는 `#if m68k` 묶음 7 줄, `kern_exec.c` 는 5 줄입니다. 07 줄은 `#else` 에 남겼습니다.
- diff 는 `06_reconstruction/evidence/m68k-pc-split.diff` 입니다.
- `MARKERS` 와 `EXCEPTS[444]` 를 더했습니다. 덮어쓰기 `.c` 6 개는 파생 검사를 모두 통과했습니다.
- PROVENANCE 1073 → 1075, MODIFICATIONS 597 → 599(덧붙이기만).

최종 run `m5p444-fin1`:
- 스테이징 `m0p444-stage` 는 888 파일이고, `m0p441-stage` 대비 다른 파일은 두 `.c` 뿐입니다. 그래서 다른 205 객체는 입력이 같아 다시 컴파일하지 않았습니다. x86 관문 7 스테이징은 같습니다.
- 2 명령이 종료 0 입니다. 맨 `m68k` 가 미리 정의돼 있음이 컴파일 성공으로 확인되었습니다(아니면 `#else` 의 `PC` 에서 실패).
- 두 객체 모두 PC 쓰기 명령열이 원본과 같고(각 1 곳), 원본에 없는 미정의 기호는 0 입니다.
- **`x86-mach_process` 는 OBJECT_MATCH** 입니다.
- `x86-kern_exec` 은 NOT_MATCH(`_execve` 만 다름; 객체 2218 B 대 원본 2258 B) 입니다.
  - 덩어리는 PMON 블록 하나입니다: 원본에만 `btst #4,_pmon_flags` → `bsr _pmonlogexec`(0x400514c–, `kern_exec.c:537` 근처)와 그 앞뒤 스택 정리(X 1·DEL 1)가 있습니다.
  - D024 조건(객체 OBJECT_MATCH)을 아직 채우지 못한 **중간 상태** 로 둡니다(PMON 항목에서 마무리).
- 도구 해시: 변형 run 뒤 `cmd2`·`final` 명령을 더해 도구가 바뀌었습니다. 첫 판 해시(026cd263…)는 변형 run 기록, 마지막 판(4d0b7761…)은 최종 기록과 같습니다(`08_build/artifacts/m5p444/tools-pre.sha`).
- m68k 누계: 이름 대응 공통부 C 208 중 **207 컴파일**(`ns_timer` 만 남음), OBJECT_MATCH **149**.

## 445. M5-2 세부 계획 — m68k PMON 1: `kern_exec` 의 `pmonlogexec` 호출(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: 원본 m68k 공통부에서 PMON 호출은 세 객체에만 있습니다(python 으로 원본 목록 전체 검색).
- `kern_exec`: `_pmonlogexec` 1 회(0x400516c)
- `vm_fault`: `_pmonlogcontextflush`·`_pmonlogevent` 각 1 회(0x405cf38·0x405cf82)
- `vm_pageout`: 같은 쌍 2 회(0x40604e0·0x4060522·0x40605f6·0x4060638)

세 곳 모두 `_pmon_flags`(`__common` 0x40b607c, 160 B = int 40 개)의 `+0x44`(= `[17]`)를 검사합니다. x86 원본에는 PMON 기호가 없습니다. NeXTMach 1990 `next/kernel_pmon.h` 는 `DEBUG` 전용 인라인 `pmon_log_event` 이고, 소스 번호·사건 값(`next/pmon_targets.h`)이 1997 원본의 17·0x10000000 등과 맞지 않습니다. 그래서 원본 바이트에서 작성합니다(D024). 이 절은 가장 단순한 `kern_exec` 만 하고, `vm_fault`·`vm_pageout` 은 인자 계산을 따로 분석한 뒤 다음 절에서 다룹니다.

확인한 사실(원본 목록 0x4005134–0x400517e):
- `bcopy(pn.pn_buf, utask->uu_comm, pn_pathlen + 1)` 에서 `lea a4@(0x8),a2` 로 `&utask->uu_comm` 을 a2 에 둡니다.
- 바로 다음이 `btst #4,_pmon_flags+0x44; beq` → `movel a2,sp@-; movel _active_threads,sp@-; movel #0x10000000,sp@-; pea 0x11; bsr _pmonlogexec; addqw #8; addqw #8` 입니다.
- 그 뒤가 `movel a4@,a0; bset #7,a0@(0x28)` = 07 `kern_exec.c:532` `utask->uu_procp->p_flag |= SEXEC` 입니다.
- `btst #4` 는 바이트 +0x44 의 비트 4 = int `[17]` 의 0x10000000 입니다(§431 의 aston 과 같은 변환).
- 따라서 C 꼴은 `if (pmon_flags[17] & 0x10000000) pmonlogexec(17, 0x10000000, current_thread(), utask->uu_comm);` 입니다.

방법:
1. 07 덮어쓰기 `kern_exec.c`(§444 판)의 532 행 앞에 `#if m68k` 묶음(`plan 445 (m68k)`)을 끼웁니다.
   - 블록 안에 `extern int pmon_flags[]; extern void pmonlogexec();` 를 둡니다(새 머리를 만들지 않음).
   - 값은 숫자로 씁니다. 1997 이름은 알 수 없어 지어내지 않습니다.
2. `MARKERS`·`EXCEPTS[445]`(= 444) 를 더합니다. 스테이징 차이 = `kern_exec.c` 하나를 확인하고 x86 관문을 봅니다. 객체 하나를 컴파일합니다.
3. 미리 정한 기준:
   - `x86-kern_exec` OBJECT_MATCH
   - 원본에 없는 새 미정의 기호 0(`_pmon_flags`·`_pmonlogexec` 는 원본에 있음)
   - 아니면 진단만 합니다.
4. `pmon_flags` 의 정의(COMMON)는 이번에 넣지 않습니다(UNDF). §441 과 같은 B2-1 판단이 필요하며, 링크(M7) 전에 정합니다.
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-pmon-exec.diff`, `09_validation/reconstruction/m5-m68k-pmon-exec-20261009.json`.

### 445.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 판독 확인(인자 순서·`_active_threads`·`_pmonlogexec`·`[17]`·0x10000000); `SEXEC` 는 0x80000000(`proc.h:569`)이고 `p_flag` 는 int 라 `bset #7,…@(0x28)` | `proc.h` grep(569 행), F444 목록 663 행 `bset #7,a0@(0x28:w)` | ✅ (내 질문의 0x80 은 틀림 — 판독에는 영향 없음) |
| F444 와 원본 `_execve` 의 차이는 0x400513c 부근뿐(원본 `lea a4@(8),a2; movel a2,sp@-` 대 객체 `pea a4@(8)`, SEXEC 줄 위치, PMON 블록 없음) → 끼울 자리가 맞음 | §444.2 의 덩어리 진단(X 1·CALL 1·DEL 1)과 같은 내용 | ✅ |
| CSE 로 `&uu_comm` 이 a2 에 남는지는 컴파일로만 확인 가능(위험 낮음–중간) | — | ⏭️ 실행이 판정 |
| C89 에서 문장 뒤의 블록 범위 `extern` 은 `{ … }` 안에 있어야 함 | C89 규칙 | ✅ 중괄호 포함(줄 수에 셈) |
| `pmon_flags`·`pmonlogexec` 는 07·스테이징 어디에도 없음(충돌 없음); `current_thread()` = `active_threads[cpu_number()]`, `cpu_number()` = 0 | grep 0 건, 스테이징 `kern/thread.h:345` | ✅ |
| `MARKERS` 에 `plan 445` 항목(`kern_exec.c`: 묶음 전체 줄 수), `EXCEPTS[445]` 필요; 444 항목은 유지 | `check_derived` 설계 | ✅ |
| 한 객체 컴파일·비교 도구가 계획에 없음(`m5_m68k_pc.py` 는 444·`F444__`·두 파일 고정) | 도구 읽음 | ✅ `cmd2`·`final` 을 절 번호·대상 파일 인자로 일반화(444 기록은 그대로) |
| `pmon_flags` 참조는 `__text` 세 곳(+0x44)뿐이고 처음 언급자는 `kern_exec`; `__common` 에서 `kern_exec` 의 COMMON(`_init_exec_args`·`_vm_info_zone`) 사이에 놓임 → 정의 미룸은 B2-1 상 문제없음 | §445 사실(python 검색)과 같음 | ✅ |
| 끼울 자리는 덮어쓰기 판 **537 행**(532 는 07 본 파일 번호) | 덮어쓰기 파일 grep: 537 행 | ✅ **내 오류** 정정 |
| §444 의 `kern_exec` 중간 상태 기록은 445 결과로 갱신된다고 밝힐 것 | — | ✅ |

### 445.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pmon-exec-20261009.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_exec.c` 의 537 행(SEXEC) 앞에 9 줄 묶음(`plan 445 (m68k)`, `#if m68k` 안에 중괄호 블록·블록 범위 `extern` 둘·`if … pmonlogexec(…)`)을 끼웠습니다.
  - diff 는 `06_reconstruction/evidence/m68k-pmon-exec.diff`(07 본 파일 대비, §444 묶음 포함)입니다.
  - PROVENANCE 의 이 파일 행(§444 에서 오늘 쓴 행)을 갱신했고(행 수 1075 그대로), MODIFICATIONS 는 599 → 600 입니다.
- 도구:
  - `stage_m68k.py` 에 `MARKERS`(`plan 445`: `kern_exec.c` 9)·`EXCEPTS[445]` 를 더했습니다. 덮어쓰기 `.c` 파생 검사는 통과했습니다.
  - `m5_m68k_pc.py` 의 `cmd2`·`final` 을 절 번호·대상 파일 인자로 일반화했습니다.
  - 첫 `final` 실행은 내 코드의 변수 이름 겹침(`names`)으로 멈췄고, 고쳐 다시 실행했습니다. 해시는 `08_build/artifacts/m5p445/tools-pre.sha` 에 있고 마지막 판이 기록과 같습니다.
- 스테이징 `m0p445-stage` 는 `m0p444-stage` 대비 `kern_exec.c` 하나만 다릅니다. x86 관문 7 스테이징은 같습니다.
- run `m5p445-fin1` 은 1 명령 종료 0 이고, 실기 otool 목록 SHA 를 대조했습니다.
- 결과: **`x86-kern_exec` OBJECT_MATCH**(외부 구간 모두 같음). PC 쓰기 명령열(§444)도 그대로이고, 원본에 없는 새 미정의 기호는 0 입니다.
  - §444 의 "중간 상태" 는 해소되었습니다(D024 조건 충족).
- `pmon_flags` 정의(COMMON)는 미룹니다(§445.1; `kern_exec`·`vm_fault`·`vm_pageout` 은 UNDF 로 참조).
- m68k 누계: 207 컴파일, **OBJECT_MATCH 150**.

## 446. M5-3 세부 계획 — m68k PMON 2: `vm_fault` 의 사건 마스크 누적과 `pmonlogevent`(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

배경: §431 진단에서 `_vm_fault` 의 차이는 다음 셋입니다.
- PMON 사건 마스크(d5)를 함수 곳곳에서 쌓는 덩어리 8 개(INS)
- `pmap_enter` 앞의 기록 블록(CALL)
- 그에 따른 레지스터·프레임 차이(R 48·D-frame 11·X 8)

1997 PMON API 는 NeXTMach 1990 과 다릅니다(§445).

확인한 사실(원본 목록 `_vm_fault` 0x405c43c–0x405d07e, python 으로 분기 대상 조사):
- 시작: `movel #0x2000000,d5` 가 `vm_stat.faults++`(`addql #1,0x40c2404`, 07 114 행) 앞에 있습니다 → `int pmon_event = 0x2000000;` 선언 초기화.
- 마스크 누적 7 곳(`moveq #N,d4; orl d4,d5`):

| 원본 | 값 | 07 자리 | 블록 |
|---|---|---|---|
| 0x405c5a4 | 8 | 331(`first_m = VM_PAGE_NULL`)과 332(`vm_page_zero_fill(m)`) 사이 | — |
| 0x405c656 | 1 | 372(`vm_stat.reactivations++`) 뒤, `if (m->inactive)` 블록 안 | 0x405c626 의 분기가 `orl` 뒤로 감 |
| 0x405c6c0 | 2 | 392(`vm_stat.reactivations++`) 뒤, `if (m->free)` 블록 안 | 0x405c690 의 분기가 `orl` 뒤로 감 |
| 0x405c73c | 16 | 473(`#if NeXT`)과 474(`rc = vm_pager_get(…)`) 사이 | 앞 `if` 블록 뒤 공통 경로 |
| 0x405c86c | 8 | 563(`vm_page_zero_fill(m)`)과 564(`zero_fill_count++`) 사이 | 호출 뒤 |
| 0x405c8ce | 32 | 625(`vm_page_copy(m, first_m)`) 앞 | 쓰기 경로 |
| 0x405c98a | 64 | 693–695 블록 선언 뒤, 697 주석·`if ((fault_type & VM_PROT_WRITE) == 0)` 앞 | `first_object->copy != NULL` 블록 안 |

- `pmap_enter`(07 1140 행) 앞의 기록 블록(0x405cef0–0x405cf88):
  - `if (prot & VM_PROT_WRITE) pmon_event |= 0x100;`(`btst #1,a6@(0xfff3)` = `prot` 의 하위 바이트).
  - `vmstat = (vmlog_send++ & 1) ? vm_page_free_count : (vm_page_inactive_count | 0x8000);`(`moveq #1; andl _vmlog_send; addql #1,_vmlog_send; tstl`). `_vmlog_send` 는 원본 `__common` 0x40c2c28 이고 x86 에는 없습니다.
  - `if (pmon_flags[17] & 0x01000000) pmonlogcontextflush(17, 0x01000000);`(`btst #0` = 상위 바이트 비트 0).
  - `if (pmon_flags[17] & pmon_event) pmonlogevent(17, pmon_event, (atop(vaddr) << 16) | atop(VM_PAGE_TO_PHYS(m)), (pmap_resident_count(map->pmap) << 16) | vmstat, current_thread());`(`lsrl _page_shift` = `atop`, `mach/vm_param.h:118`).

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/vm/vm_fault.c` 를 만들고, 위 자리마다 `#if m68k` 묶음(`plan 446 (m68k)`)을 끼웁니다.
   - 선언 1 개, 누적 7 개, 기록 블록 1 개입니다.
   - 기록 블록 안의 블록 범위 `extern int pmon_flags[], vmlog_send; extern void pmonlogevent(), pmonlogcontextflush();` 와 지역 `int vmstat;` 는 중괄호 블록 안에 둡니다.
   - 값은 숫자로 씁니다.
2. 컴파일 → 실기 otool → 원본 `_vm_fault` 와 전체 정규화 비교(§436 방식, 덩어리 목록)를 합니다.
   - 미리 정한 기준: 최종적으로 `x86-vm_fault` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0.
   - 첫 시도에서 덩어리가 남으면 덩어리별로 원인을 적고 C 꼴을 고쳐 새 run 으로 다시 시험합니다(시도마다 기록; 같은 덩어리가 두 번 연속 줄지 않으면 멈추고 보고).
3. `vmlog_send`·`pmon_flags` 정의(COMMON)는 미룹니다(§445 와 같음).
4. `vm_pageout` 은 다음 절(§447)입니다.
5. 기록: PROVENANCE·MODIFICATIONS, diff, `09_validation/reconstruction/m5-m68k-pmon-fault-20261009.json`.

### 446.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 시작 초기화·누적 7 곳의 07 자리와 블록 소속이 모두 맞음(호출 대상 0x4061846 `_vm_page_zero_fill`, 0x406185e `_vm_page_copy`; 0x405c5a4 는 호출 앞, 0x405c86c 는 호출 뒤) | 기호표 grep(두 주소), §446 분기 대상 조사 출력 | ✅ |
| 기록 블록 판독(`prot` = a6@(0xfff0), `vmlog_send` 짝수면 inactive\|0x8000, flush 비트 0x01000000, 인자 순서, `phys_addr` +0x22, `map->pmap` +0x20, `atop`) 맞음 | `_vmlog_send` 0x40c2c28 기호, §446 판독과 같음 | ✅ |
| 블록 자리는 1128(panic) 뒤 — 1130 `vm_object_unlock(object)` 앞이든 뒤든 사이에 명령 없음; 1130 뒤 권고 | 07 1115–1132 행 읽음 | ✅ 1130 뒤에 둠 |
| 비 PMON 덩어리는 모두 레지스터·프레임 효과(copy_offset 가 레지스터→프레임으로 밀림, `_vm_page_free` 주소 끌어올림·꼬리 합치기 차이) — PMON 변수 하나로 함께 풀릴 가능성(미검증) | §431 덩어리 목록 | ⏭️ 실행이 판정 |
| `movel #pmon_flags+0x44,d3` 를 두 번 쓰는 꼴이 나올지는 미검증 | — | ⏭️ |
| 선언은 지역 변수 끝(112 행 `next_object` 뒤)에 `int` 로 먼저; R 덩어리가 남으면 `register`·선언 순서 변형을 별도 run 으로 | 설계 | ✅ |
| 64 비트 자리의 기준 줄은 700(`if ((fault_type & VM_PROT_WRITE) == 0)`), 697 은 주석 | 07 690–701 행 읽음 | ✅ 695 행(`vm_page_t copy_m;`) 뒤·697 주석 앞에 끼움 |
| `0x100`·`0x8000` 은 `orw`, 작은 값은 `moveq;orl` 로 나오는지는 미검증 | — | ⏭️ |
| 멈춤 기준에 "R 만 남으면 선언 변형을 별도 run 으로" 추가 | 설계 | ✅ |

### 446.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pmon-fault-20261009.json`, 진단 `08_build/artifacts/m5p446/a1-diag.json`

- 07 덮어쓰기 `v183.34/m68k/src/vm/vm_fault.c`(새 파일)는 07 본 파일(출처 darwin01, APSL·CMU 고지 그대로)에 `#if m68k` 묶음 9 개(46 줄, `plan 446 (m68k)`)를 끼운 것입니다.
  - 선언은 112 행 뒤, 누적 7 곳은 331·372·392·473·563·624(빈 줄, 625 `vm_page_copy` 앞)·695 행 뒤, 기록 블록은 1130 행 뒤입니다.
  - diff 는 `06_reconstruction/evidence/m68k-pmon-fault.diff` 입니다. PROVENANCE 1075 → 1076, MODIFICATIONS 600 → 601 입니다.
- 도구:
  - `stage_m68k.py` 에 `MARKERS`(`plan 446`: `vm_fault.c` 46)·`EXCEPTS[446]` 를 더했습니다. 파생 검사는 통과했습니다.
  - `m5_m68k_pc.py` 에 `vm_fault` 와 구간 진단 명령 `diag`(§436 방식)를 더했습니다.
- 스테이징 `m0p446-a1-stage` 는 `m0p445-stage` 대비 `vm_fault.c` 하나만 다릅니다. x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p446-a1`, 1 명령 종료 0, 실기 otool SHA 대조)에서 이미 `_vm_fault` 구간 3138 B 가 원본과 같습니다(덩어리 0).
  - 객체 L1 은 **OBJECT_MATCH** 입니다(외부 구간 `_vm_fault`·`_vm_fault_wire`·`_vm_fault_unwire`·`_vm_fault_copy_entry`·`_vm_fault_wire_fast` 모두 같음). 원본에 없는 새 미정의 기호는 0 입니다.
  - §431 의 비 PMON 덩어리(레지스터 R 48·프레임·`_vm_page_free` 호출 꼴)는 PMON 변수가 레지스터 하나를 차지하면서 모두 함께 풀렸습니다(§446.1 의 예측대로).
  - `final` 기록의 "shape" 항목은 §444 의 PC 쓰기 기준이므로 `vm_fault` 와 무관합니다(0 은 정상).
- `pmon_flags`·`vmlog_send` 정의(COMMON)는 미룹니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 151**.

## 447. M5-4 세부 계획 — m68k PMON 2b: `vm_pageout_scan` 의 두 기록 자리(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09)

확인한 사실(원본 `_vm_pageout_scan` 0x4060422–0x406070c 읽음; 07 `vm/vm_pageout.c` 는 darwin01 출처):
- 구조는 07 과 같습니다. `MACH_SLOCKS 0` 이라 `vm_object_lock_try` 는 상수가 되어 사라집니다.
- 원본에만 PMON 이 있습니다. 루프 앞에서 `lea _pmon_flags+0x44,a4` 로 `&pmon_flags[17]` 을 끌어올립니다.
- 자리 A(0x40604d0–0x406052c, clean 경로):
  - 앞뒤 문맥은 `did_work = TRUE`(`moveq #1,d4`)·`m->busy = TRUE`(`orb #0x80,a2@(0x20)`) 뒤, `pmap_remove_all`(0x4097e9c) 앞입니다.
  - 문장 1: `if (pmon_flags[17] & 0x01000000) pmonlogcontextflush(17, 0x01000000);`
  - 문장 2: `if (pmon_flags[17] & 0x04000001) pmonlogevent(17, 0x04000001, atop(VM_PAGE_TO_PHYS(m)), (vm_page_inactive_count << 16) | (vm_page_free_count & 0xffff), current_thread());`
  - `orw 0x40c2c0e` 는 `vm_page_free_count` 의 하위 반입니다. §444 E1 처럼 `& 0xffff` 가 `orw mem+2` 로 나옴을 이미 봤습니다.
- 자리 B(0x40605e6–0x4060642, dirty 경로): pager 를 마련하는 `if` 블록 뒤, `pageout_succeeded = FALSE`(`clrl d2`) 앞입니다. 같은 꼴이며 사건 값은 0x04000002 입니다.
- §431 의 비 PMON 덩어리(저장 레지스터 집합에 a4 추가, d2/d3 교대, 끝의 루프 조건 꼴)는 PMON 포인터가 a4 를 차지하는 데서 오는 것으로 봅니다(미검증, 실행이 판정).

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/vm/vm_pageout.c` 를 만듭니다.
   - 자리 A: 07 의 clean 블록 `vm_page_unlock_queues();` 뒤(`pmap_remove_all` 앞)에 둡니다.
   - 자리 B: pager `if` 블록의 닫는 중괄호 뒤(`pageout_succeeded = FALSE;` 앞)에 둡니다.
   - 각 자리에 `#if m68k` 묶음(`plan 447 (m68k)`, 블록 범위 `extern` 은 중괄호 안)을 끼웁니다.
2. `MARKERS`·`EXCEPTS[447]`·`m5_m68k_pc.py` 의 `FILES` 에 `vm_pageout` 을 더합니다. 컴파일 → otool → `_vm_pageout_scan` 진단 → `final` 순으로 합니다.
3. 미리 정한 기준:
   - `x86-vm_pageout` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0.
   - 아니면 덩어리별로 진단해 다시 시도합니다(§446 의 멈춤 기준 같음).
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-pmon-pageout.diff`, `09_validation/reconstruction/m5-m68k-pmon-pageout-20261009.json`.

### 447.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 자리 A·B 의 원본 순서와 07 줄(172 뒤 / 282 의 `}` 뒤·284 앞) 맞음; 호출 대상 0x4097e9c `_pmap_remove_all`·0x406093c `_vm_pager_allocate`·0x405ffea `_vm_object_setpager` | 기호표 grep 세 주소, 07 280–285 행 읽음 | ✅ |
| `vm_page_unlock_queues()` 는 `simple_unlock` 이고 `MACH_SLOCKS 0` 에서 빈 매크로 → 172 앞뒤 어디든 같은 코드 | 스테이징 `vm/vm_page.h:393`, `kern/lock.h:103-104` 읽음 | ✅ |
| 인자 판독(17, 0x4000001/2, `atop(phys)`, `(inactive << 16) \| low16(free)`, `current_thread()`) 맞음 | §447 사실과 같음 | ✅ |
| `& 0xffff` 는 §444 처럼 `(u_short)` 과 바이트로 구별되지 않을 수 있는 꼴 → D072(단순 꼴)를 인용 | §444.2 기록 | ✅ |
| 루프 앞 `lea …,a4` 는 두 자리의 `pmon_flags[17]` 을 루프 불변으로 끌어올린 것으로 보임(미검증); 비 PMON 덩어리(루프 끝 조건·d2/d3·a2 대 d2)는 그 결과로 설명 가능, 함수 끝(331–353)에 따로 소스 차이 없음 | §431 덩어리 목록(INS 1·CALL 2 외는 R·X·D-frame) | ⏭️ 실행이 판정 |
| 덮어쓰기는 새 파일이고 darwin01 APSL·CMU 고지를 그대로 유지; `MARKERS` 줄 수와 PROVENANCE(1076 → 1077)·MODIFICATIONS(601 → 602) 기대값을 적을 것 | — | ✅ |

### 447.2 결과(2026-10-09) — 기록 `09_validation/reconstruction/m5-m68k-pmon-pageout-20261009.json`, 진단 `08_build/artifacts/m5p447/a1-diag.json`

- 07 덮어쓰기 `v183.34/m68k/src/vm/vm_pageout.c`(새 파일, darwin01 APSL·CMU 고지 그대로)는 172 행 뒤(자리 A)와 282 행 뒤(자리 B)에 `#if m68k` 묶음 둘(26 줄, `plan 447 (m68k)`)을 끼운 것입니다.
  - 꼴은 D072 의 단순 꼴(`& 0xffff`)입니다.
  - diff 는 `06_reconstruction/evidence/m68k-pmon-pageout.diff` 입니다. PROVENANCE 1076 → 1077, MODIFICATIONS 601 → 602(미리 적은 기대값과 같음)입니다.
- 도구: `MARKERS`(`vm_pageout.c` 26)·`EXCEPTS[447]`, `m5_m68k_pc.py` `FILES` 에 `vm_pageout` 을 더했습니다. 실행 전후 해시가 같습니다(`08_build/artifacts/m5p447/tools-pre.sha`).
- 스테이징 차이는 `vm_pageout.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p447-a1`)에서 `_vm_pageout_scan` 748 B 가 원본과 같습니다(덩어리 0).
  - 객체 L1 은 **OBJECT_MATCH** 이고, 원본에 없는 새 미정의 기호는 0 입니다.
  - §431 의 비 PMON 덩어리(저장 레지스터 a4·d2/d3·루프 끝 조건)도 함께 풀렸습니다.
- PMON 정리: 원본 공통부의 PMON 호출 세 객체(`kern_exec`·`vm_fault`·`vm_pageout`)가 모두 OBJECT_MATCH 입니다. 남은 것은 `pmon_flags`·`vmlog_send` 의 정의(COMMON, 링크 전)와 기계 의존부의 PMON 함수(`_pmonlogevent` 등, M4)입니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 152**.

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

## 449. M5-6 세부 계획 — m68k `ufs_vnodeops`·`ufs_inode` 에서 i386 바이트 교환 빼기(NeXTMach 꼴 복원; x86 트리 변경 없음; 코딩 전, 2026-10-10)

배경: §448 은 멈췄고(사용자 선택 없음), 근거가 분명한 i386 전용 코드 제거(M5)로 넘어갑니다. 07 의 두 파일은 x86 원본에 맞춰 리틀엔디언 디스크 형식용 바이트 교환을 넣은 것입니다(계획 215·217). m68k(빅엔디언) 원본에는 그 호출이 없습니다.

확인한 사실:
- `ufs_vnodeops` §436:
  - 원본 대비 차이는 `_rwip` 의 `byte_swap_dir_block_in`/`_out` 호출과 그 조건(07 `ufs_vnodeops.c:399-400`·`402-403`, "plan 217") 및 그에 딸린 `movel d1,d0` 하나뿐입니다(원본 시작 0x403a056, 54 B).
  - NeXTMach `ufs/ufs_vnodeops.c` 에는 그 줄이 없습니다(grep `byte_swap` 0 건).
- `ufs_inode` §431:
  - `_iget` 에서 원본은 `lea a3@(0x62),a2; pea 0x80; …; bsr _bcopy` 이고, 07 은 `bsr _byte_swap_inode_in` 입니다.
  - `_iupdat` 에서 원본은 `pea 0x80; …; pea a3@(0x62); bsr _bcopy` 이고, 07 은 `_byte_swap_inode_out` 입니다.
  - 나머지 덩어리는 레지스터(R 45)·프레임(원본에만 `movel a1,a6@(0xfffc)`, `linkw #0xfffc`) 입니다.
  - 07 `ufs_inode.c:471`(`byte_swap_inode_in(dp, ip);`, plan 215)·`646`(`byte_swap_inode_out(ip, dp);`) 은 NeXTMach `ufs/ufs_inode.c:431` `ip->i_ic = dp->di_ic;`·`606/616` `dp->di_ic = ip->i_ic;`(구조체 대입) 을 바꾼 것입니다.
  - 128 B 구조체 대입은 GCC 가 `_bcopy` 호출로 내는 것으로 봅니다(미검증, 실행이 판정).

방법:
1. 07 덮어쓰기 두 파일(새 파일, NeXTMach 출처 고지 그대로)을 만듭니다.
   - `ufs_vnodeops.c`: 399·400 과 402·403 을 각각 `#ifndef m68k` … `#endif` 로 감쌉니다(끼운 줄 4 개, `plan 449 (m68k)`).
   - `ufs_inode.c`: 471 행 앞에 `#if m68k` + `ip->i_ic = dp->di_ic;` + `#else` 를, 뒤에 `#endif` 를 끼웁니다. 646 행도 같은 꼴로 `dp->di_ic = ip->i_ic;` 을 끼웁니다(NeXTMach 줄).
2. `MARKERS`·`EXCEPTS[449]`·`m5_m68k_pc.py` `FILES` 에 두 파일을 더하고, 두 객체를 컴파일합니다. 스테이징 차이 = 두 `.c`, x86 관문.
3. 미리 정한 기준:
   - 두 객체 OBJECT_MATCH, 원본에 없는 새 미정의 기호 0(바이트 교환 기호가 빠짐).
   - 아니면 구간 진단을 하고 두 시도 연속 줄지 않으면 멈춥니다.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-byteswap.diff`, `09_validation/reconstruction/m5-m68k-ufs-byteswap-20261010.json`.

### 449.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_iget`(0x4037588) 0x4037854–0x403786a: `lea a3@(0x62),a2; pea 0x80; movel a2,sp@-; …; movel d0,sp@-; bsr _bcopy` = `bcopy(dp, &ip->i_ic, 128)`; `_iupdat`(0x4037c0c) 0x4037d08 은 `bcopy(&ip->i_ic, dp, 128)` | 기호표 grep 세 기호, 원본 0x4037850–0x403786c 읽음 | ✅(`_iupdat` 쪽은 §431 덩어리와 검토자 인용) |
| `icommon` 128 B, `i_ic` +0x62 | 검토자 인용(SDK `inode.h:101-135`) + 원본 `pea 0x80` | ✅ |
| 128 B 구조체 대입이 `_bcopy` 로 나오는지는 컴파일러 원본으로 확인 불가 | — | ⏭️ 실행이 판정 |
| 07 642–658 행 = NeXTMach 601–617 행; 646 은 NeXTMach 606(`#if NeXT` 안), 657 은 `#else` 의 죽은 사본 → 되살릴 것은 606 하나 | 두 범위 나란히 읽음 | ✅ "606/616 짝" 은 **내 문구 오류** |
| 07 의 다른 x86 동기 줄(`architecture/byte_order.h` 가져오기, `NXSwapHostLongToBig` 2 줄 등)은 빅엔디언에서 항등이고 `_iupdat` 진단에 차이 없음 → 남기되 기록 | 07 652–654 행 읽음(`NXSwapHostLongToBig`) | ✅ MODIFICATIONS 에 "남김" 명시 |
| `ufs_vnodeops` 덩어리 4 개는 모두 `_rwip`, 크기 합 54 = 8150 − 8096 | §436.2 기록과 같음 | ✅ |
| 표시 줄은 모두 `plan 449 (m68k)` 를 달고, `begin`/`end` 묶음을 쓸 거면 `#else` 줄에서 닫아야 원래 줄이 묶음에 먹히지 않음; 등록 수 `ufs_vnodeops.c` 4·`ufs_inode.c` 8 | `check_derived` 규칙(§437–441) | ✅ 묶음 없이 줄마다 표시 |
| `EXCEPTS[449]`·`FILES` 등록 | — | ✅ |
| `ufs_dir.c` 에도 바이트 교환 호출 12 곳(다음 대상, 링크 전 필요) | 검토자 grep 인용 | ⏭️ 다음 항목 |

### 449.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-byteswap-20261010.json`

- 07 덮어쓰기(새 파일 둘, NeXTMach 고지 그대로)와 기록:
  - `v183.34/m68k/src/bsd/ufs/ufs_vnodeops.c` 는 표시 줄 4 개입니다(`#ifndef m68k`/`#endif` 두 쌍).
  - `ufs_inode.c` 는 표시 줄 8 개입니다(`#if m68k` 구조체 대입·`#else`·`#endif` 두 벌).
  - diff 는 `06_reconstruction/evidence/m68k-ufs-byteswap.diff` 입니다. PROVENANCE 1077 → 1079, MODIFICATIONS 602 → 604 입니다.
  - 남긴 x86 동기 줄(`NXSwapHostLongToBig` 등, 빅엔디언에서 항등)은 MODIFICATIONS 에 적었습니다.
- 도구: `MARKERS`(`plan 449`: 4·8)·`EXCEPTS[449]`(이전 둘 + 두 ufs 객체), `m5_m68k_pc.py` `FILES` 에 두 파일을 더했습니다. 실행 전후 해시가 같습니다.
- 스테이징 차이는 두 `.c` 이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p449-a1`, 2 명령 종료 0, 실기 otool SHA 대조): **`x86-ufs_vnodeops`·`x86-ufs_inode` 모두 OBJECT_MATCH** 이고, 원본에 없는 새 미정의 기호는 0 입니다.
  - 128 B 구조체 대입은 `_bcopy` 호출로 나왔습니다(§449 의 미검증 예측 확인).
  - `_iget` 의 레지스터·프레임 차이도 함께 풀렸습니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 154**.
- 다음 바이트 교환 후보: `ufs_vfsops`(바이트 교환 + `copyinmsg`·프레임, §439), `ufs_alloc`·`ufs_dir`(i386 도우미 함수 `_verify_and_swap_cg`·`_brelse_and_swap`).

## 450. M5-7 세부 계획 — m68k `ufs_vfsops`: i386 바이트 교환 7 문장 빼기와 `mountfs` 프레임 자리 메움 크기(x86 트리 변경 없음; 코딩 전, 2026-10-10)

확인한 사실:
- §439 a 쪽 관문 기록(`m2-m68k-boundaries-built-20261009.json` k=130)의 덩어리:
  - 바이트 교환 7 문장(07 `ufs_vfsops.c` 257–258·308·329·337·416·691·715, 모두 "plan 216")이고, 크기는 14·10·8·8·14·10·16 = 80 B 입니다(python).
  - `bwrite` 정렬 쌍(−8·+10)이 있습니다.
  - `mountfs` 프레임 차이(`linkw` 80 대 76, 지역 변위 +6 이동, python)가 있습니다.
  - 257 행 `fsp = tp->b_un.b_fs;` 도 원본 m68k 에 없습니다(덩어리 14 B = `movel a4@(0x20),a2` 4 B 포함).
- **§439 해석 정정**: `_copyin` 과 `_copyinmsg` 는 원본 m68k 에서 같은 주소(0x40016d0)의 별칭입니다(python: 두 이름 모두 호출 56 곳, 같은 함수 목록). §439 의 "`ufs_mount` 의 원본 `copyinmsg`" 는 진단 도구의 기호 이름 고르기에서 생긴 것이라 실제 차이가 아닙니다.
- 07 `mountfs` 의 `char unused[64];`(206–207 행)는 x86 원본 프레임(0x40 더 큼)에 맞춰 넣은 자리 메움입니다(계획 216.1, "이름·자리 추정"). m68k 원본은 이 크기가 다른 것으로 보입니다.

방법:
1. 변형 시험(한 run): 07 본 파일에서 바이트 교환 7 문장을 뺀 판에 `unused` 크기 64(바꾸지 않음)·62·60·58·56 을 시험합니다(새 도구 `10_tools/reconstruction/m5_m68k_vfsops.py`). 외부 구간 비교로 `mountfs` 를 담은 구간·`_ufs_mount`·`_sbupdate` 가 원본과 같은 크기를 고릅니다.
   - 같은 결과의 크기가 여럿이면 D072 처럼 사용자에게 묻습니다.
   - 하나도 없으면 진단 뒤 멈춥니다.
2. 고른 꼴로 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_vfsops.c` 를 만듭니다(새 파일).
   - 바이트 교환 줄은 `#ifndef m68k`/`#endif` 로 감쌉니다.
   - `unused` 는 `#if m68k` + `char unused[N];` + `#else` 로 감싸 07 줄을 `#else` 에 남깁니다.
   - 표시는 `plan 450 (m68k)` 입니다.
3. 미리 정한 기준: `x86-ufs_vfsops` OBJECT_MATCH, 원본에 없는 새 미정의 기호 0.
4. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-vfsops.diff`, `09_validation/reconstruction/m5-m68k-ufs-vfsops-20261010.json`.

### 450.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_copyin`·`_copyinmsg` 같은 주소 → §439 의 차이는 이름 산물 | 기호표 grep: 둘 다 0x40016d0 | ✅ |
| 바이트 교환 7 덩어리의 크기·줄이 계획과 같고 합 80; 257 행도 원본에 없음(REMOUNT 경로는 NeXTMach 245–247 행처럼 `bp = mp->m_bufp; goto modify_now;` 만) | §450 사실의 python 합과 같음; REMOUNT 판독은 검토자 인용 | ✅(판독은 실행으로 확인) |
| `unused` 는 207 행 하나(206 은 `{`) | 07 206–207 행 읽음 | ✅ 문구 정정 |
| 프레임은 4 의 배수로 올림(원본 `linkw` 828 개 모두 4 의 배수) → 크기 57·58 이 프레임 76·변위 +6 모두와 맞음; `devbsize` 는 레지스터라 무관 | python: `linkw` 828 개 중 4 의 배수 828 | ✅ |
| 크기로는 고를 수 없음(변위 길이가 같음) → **바이트 일치(OBJECT_MATCH)로 고를 것**; 시험에 57 을 더할 것 | 설계 | ✅ 후보 64·62·60·58·57·56 |
| 그 밖의 덩어리(D-frame +6·스택 조정 합치기·`bwrite` 자리·분기 `.w`/`.b` 4 B)는 제거·프레임의 부수 효과 | §439 덩어리 목록 | ⏭️ 실행이 판정 |
| 표시 줄 18(`#ifndef`/`#endif` 7 쌍 + `unused` 4 줄), `EXCEPTS[450]`·`--plan` 목록 | 설계 | ✅ |
| 한 크기로 두 아키텍처를 맞출 수 없음(x86 64, m68k 57/58) → `#if m68k` 분기 필요; 실제 지역 변수는 아키텍처마다 배치가 다른 것(구조체 등)일 수 있음(미검증) | — | ✅ 기록 |

고친 고르기 규칙(실행 전 고정): 객체 OBJECT_MATCH 인 크기가 하나면 그 크기를 씁니다. 여럿이고 그 객체들이 비 STABS 로 서로 같으면, D072 와 같은 경우로 보고 사용자에게 묻습니다.

### 450.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-vfsops-variants-20261010.json`(변형), `m5-m68k-ufs-vfsops-20261010.json`(최종)

변형 시험(도구 `10_tools/reconstruction/m5_m68k_vfsops.py`, run `m5p450-var1`, 6 명령 종료 0, 실행 전후 해시 같음):
- 바이트 교환 7 문장을 뺀 판에서 `unused` 크기 64·62·60·58·57·56 을 시험했습니다.
- **58·57 만 OBJECT_MATCH** 이고 두 객체는 서로 같습니다. 나머지는 불일치입니다.
- 미리 정한 규칙대로 사용자에게 물었고 결정은 **D073 = 58** 입니다.

07 덮어쓰기와 기록:
- `v183.34/m68k/src/bsd/ufs/ufs_vfsops.c`(새 파일)는 표시 줄 18 개입니다(`#ifndef m68k`/`#endif` 7 쌍, `#if m68k char unused[58]` / `#else` 07 줄 / `#endif`).
- diff 는 `06_reconstruction/evidence/m68k-ufs-vfsops.diff` 입니다. PROVENANCE 1079 → 1080, MODIFICATIONS 604 → 605 입니다.
- 도구: `MARKERS`(18)·`EXCEPTS[450]`·`FILES`. 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.

최종 run `m5p450-a1`:
- **`x86-ufs_vfsops` OBJECT_MATCH**(시험 변형 N=58 과 비 STABS 같음)이고, 원본에 없는 새 미정의 기호는 0 입니다.
- 외부 구간 비교에서 `_sbupdate` 만 "다름" 으로 나옵니다. 이는 객체의 마지막 외부 함수라 원본 쪽 구간이 다음 외부 기호(`ufs_vnodeops` 의 `_rdwri`, 0x403b6a2)까지 이어진 측정 산물입니다. 객체 쪽은 2798 B 에서 끝나고, 객체 L1 은 OBJECT_MATCH 입니다.
- §439 의 차 82 대 86 의 남은 4 B 는 분기 `.w`/`.b` 두 개였고(검토 의견), 이번에 함께 맞았습니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 155**.

## 451. M5-8 세부 계획 — m68k `ufs_dir`: 디렉터리 바이트 교환을 매크로로 지우고 NeXTMach `brelse()` 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-10)

확인한 사실:
- 07 `ufs_dir.c` 는 x86 원본에 맞춰 다음을 넣었습니다(계획 355·370).
  - 도우미 `brelse_and_swap(bp)`(78–91 행: `if (bp) { byte_swap_dir_block_out(bp); brelse(bp); }`)
  - 단독 문장 `byte_swap_dir_block_out(…)` 9 곳과 `byte_swap_dir_block_in(…)` 1 곳(1406 행)
  - NeXTMach `brelse(x)` 를 바꾼 `brelse_and_swap(x)` 8 곳
- NeXTMach `ufs/ufs_dir.c` 와 07 의 diff: `brelse_and_swap` 자리는 모두 NeXTMach 에서 그냥 `brelse(x)` 이고, 교환 문장은 NeXTMach 에 없습니다(diff grep).
- 교환 문장은 모두 조건이 없는 단독 문장입니다(10 곳 문맥 읽음; 1587 행은 `if (bp) { … }` 블록 안 첫 문장).
- §429: `x86-ufs_dir` 은 등급 A·i386 조각 OBJECT_MATCH 이고, m68k 에서는 외부 구간 0/5 가 같으며 원본에 없는 `_brelse_and_swap` 이 있습니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_dir.c`(새 파일)를 만듭니다.
   - 도우미 정의(주석 포함 78–91 행)를 `#ifndef m68k`/`#endif` 로 감쌉니다.
   - 그 뒤에 `#if m68k` 묶음으로 매크로 셋을 둡니다: `#define brelse_and_swap(bp) brelse(bp)`, `#define byte_swap_dir_block_out(bp)`, `#define byte_swap_dir_block_in(addr, n)`.
   - 전처리 뒤 함수 본문은 NeXTMach 문장과 같고(빈 문장 `;` 만 남음), 줄을 하나하나 고치지 않습니다. 표시는 `plan 451 (m68k)` 입니다.
2. 등록·스테이징·컴파일은 앞 절들과 같습니다(`MARKERS`·`EXCEPTS[451]`·`FILES`, 스테이징 차이 = 이 `.c`, x86 관문).
3. 미리 정한 기준:
   - 원본에 없는 새 미정의 기호 0(`_brelse_and_swap`·`_byte_swap_*` 사라짐).
   - `x86-ufs_dir` OBJECT_MATCH. 아니면 구간 진단을 하고, 다른 x86 동기 수정(계획 355·370 의 비 교환 줄)이 원인인지 가립니다(두 시도 연속 줄지 않으면 멈춤).
4. `ufs_alloc` 은 교환 외에도 x86 동기 수정이 많아(계획 214: `getthetime`·`VOP_DEVBLOCKSIZE`·`NXSwapBigLongToHost`·레지스터 변형) 다음 절에서 따로 다룹니다.
5. 기록: PROVENANCE·MODIFICATIONS, diff `06_reconstruction/evidence/m68k-ufs-dir.diff`, `09_validation/reconstruction/m5-m68k-ufs-dir-20261010.json`.

### 451.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `brelse_and_swap` 호출 8 곳(169·270·491·544·633·857·1367·1607)은 NeXTMach 에서 모두 `brelse(x)`; 매크로로 `brelse(` 가 NeXTMach 의 12 개가 됨; 원본 m68k 객체의 `_brelse` 호출도 12 | python: 호출 줄 목록, NeXTMach `brelse(` 12, 원본 [0x40354be, 0x4036d3e) 에서 `bsr 0x4017aec` 12 | ✅ |
| `_out` 는 도우미 밖 8 곳(+ 도우미 안 88 행), `_in` 1 곳(1406) — 계획의 "9 곳" 은 88 행 포함 | python 목록 | ✅ 문구 정정 |
| 비 교환 차이(`#ifdef QUOTA`→`#if QUOTA`, `dirrename` 의 `EISDIR`, `dircheckforname` 분기 반전, 초기화 두 줄)는 m68k 바이트와도 맞음(원본 주소 인용) | 검토자 판독(일부 미검증) | ⏭️ 실행이 판정 |
| 매크로는 91 행 뒤에 둬야 함(앞 프로토타입 `void byte_swap_dir_block_in();` 가 펼쳐지지 않게); 빈 문장 `;` 은 모든 자리에서 무해 | 75–76·78–91 행 위치(§451 사실), 자리 문맥 읽음 | ✅ |
| 표시 줄 7(`#ifndef`·`#endif`·`#if`·`#define` 3·`#endif`); `EXCEPTS[451]` 는 450 의 다섯 + `x86-ufs_dir` | 설계 | ✅ |
| 계획 1489 행 근처의 "바이트 교환 호출 12 곳" 은 낡은 문구 | §449.1 표 마지막 줄(검토 인용) | ✅ 기록(덮어쓰지 않음) |

### 451.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-dir-20261010.json`

- 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_dir.c`(새 파일)는 표시 줄 7 개입니다.
  - 도우미 정의를 `#ifndef m68k` 로 뺐습니다.
  - 91 행 뒤 `#if m68k` 에 매크로 셋을 두었습니다.
  - diff 는 `06_reconstruction/evidence/m68k-ufs-dir.diff` 입니다. PROVENANCE 1080 → 1081, MODIFICATIONS 605 → 606 입니다.
- 도구:
  - `MARKERS`(7)·`EXCEPTS[451]`·`FILES` 를 더했습니다.
  - `m5_m68k_pc.py cmd2` 가 §429 run(`m3p429-cc2`)의 컴파일 줄도 찾도록 고쳤습니다(`ufs_dir` 은 88 쪽). 고른 줄이 `-c` 컴파일 줄인지 확인했습니다.
  - 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p451-a1`): **`x86-ufs_dir` OBJECT_MATCH** 이고, 원본에 없는 새 미정의 기호는 0 입니다(`_brelse_and_swap`·`_byte_swap_*` 사라짐).
  - 비 교환 차이(`#if QUOTA`·`EISDIR`·분기 반전·초기화)는 m68k 에도 맞았습니다.
  - 외부 구간 비교의 `_blkatoff` "다름" 은 마지막 외부 함수라 원본 구간이 다음 객체까지 이어진 측정 산물입니다. 객체 끝 6272 B = 원본 0x4036d3e, 원본 쪽 구간은 0x4037142 까지입니다.
- m68k 누계: 207 컴파일, **OBJECT_MATCH 156**.

## 452. M5-9 세부 계획 — m68k `ufs_alloc`: 실린더 그룹 바이트 교환과 `blkpref` 의 큰 끝 읽기를 빼고 NeXTMach 검사 꼴 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-10)

확인한 사실:
- 원본 m68k 기호표에 `verify_and_swap`·`byte_swap` 이 든 이름이 없습니다(grep 0).
- 07 `ufs_alloc.c`(1414 행)와 NeXTMach `mk-108.1/ufs/ufs_alloc.c` 의 차이(계획 214·214.1·397)는 다음과 같습니다.
  - 바이트 교환 관련: 도우미 `verify_and_swap_cg`(121–142 행), 그 호출 다섯 곳(817·878·1118·1206·1303 행; 878·1118 은 뒤따르는 `nbfree`/`nifree` 검사 블록과 함께), 단독 `byte_swap_cylgroup(…)` 문장들, `blkpref` 의 `prevblk`·`NXSwapBigLongToHost`(666·669–676·685·688·709–716 행).
  - 바이트 교환과 무관: `getthetime(&tv)`, `btodb(…, VOP_DEVBLOCKSIZE(ITOV(ip)))` 세 곳, `fsfull` 의 `register` 와 `cmesg = umesg = 0`, `free_block` printf 의 `bno`(214.1), `ufs_alloc_const_4`(397), `#import <architecture/byte_order.h>`.
- 원본 m68k 함수 판독(이미지 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, python):
  - `_fragextend`·`_alloccg`·`_ialloccg`·`_free_block`·`_ifree` 는 각각 `btst #2,aN@(0x3)`(B_ERROR 0x4) 1 개와 `cmpl #0x90255,aM@(0x3d4)`(CG_MAGIC) 1 개, `_getthetime`(0x400a360) 호출 1 개를 가집니다. 검사 직후 실패하면 바로 `_brelse` 로 가므로 NeXTMach 의 합친 조건 꼴과 맞습니다.
  - `_blkpref` 는 호출이 없고 `bap[indx - 1]` 을 `movel a2@(-4,d3:l:4),d0` 로 두 번(0x4033df4·0x4033e14) 직접 읽습니다. `bap && indx > 0` 검사는 없습니다 → NeXTMach 꼴입니다.
  - `_fsfull` 의 패닉 앞 `clrl d3; clrl d2`(0x403376e) → `cmesg = umesg = 0` 은 m68k 에도 있습니다.
  - `_free_block` 의 "freeing free block" printf 는 `d5`(dtogd 뒤 `bno`)를 넣습니다(0x40349ba) → 214.1 의 `bno` 와 맞습니다.
  - `_alloc` 1 곳, `_realloccg` 2 곳의 `a0@` 간접 호출은 `VOP_DEVBLOCKSIZE` 로 보입니다(실행이 판정).
- 이 객체의 컴파일 줄은 §429 run(`m3p429-cc2/run.cmd`)에 있고, 같은 파일의 `-M` 의존성 줄(144 행)도 있습니다. `m5_m68k_pc.py cmd2` 는 지금 두 줄 다 고르게 되어 있어 `-c` 줄만 고르도록 고쳐야 합니다.

방법:
1. 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_alloc.c`(새 파일, 표시 `plan 452 (m68k)`)를 만듭니다. 07 본 파일에 표시 줄만 끼워 넣습니다(64 줄).
   - 도우미 121–142 행과 `prevblk` 선언(666 행)은 `#ifndef m68k`/`#endif` 로 감쌉니다.
   - 142 행 뒤에 `#if m68k` `#define byte_swap_cylgroup(cgp)`(빈 매크로) `#endif` 를 둡니다. 단독 교환 문장은 빈 문장이 됩니다.
   - `blkpref` 네 자리(669–676·685·688·709–716)와 호출 다섯 자리(817–818·878–884·1118–1124·1206–1207·1303–1304)는 `#if m68k` + NeXTMach 줄 + `#else` + 07 줄 + `#endif` 로 둡니다. 넣는 줄은 NeXTMach 634·643·646·667–671·771–774·830–834·1061–1065·1144–1147·1240–1243 행과 같은 글입니다(`time.tv_sec` 줄은 넣지 않음; `getthetime` 은 07 줄 유지).
   - 바이트 교환과 무관한 차이는 07 그대로 둡니다(원본 판독과 맞음).
2. 도구:
   - `stage_m68k.py`: `MARKERS['plan 452 (m68k)'] = {'src/bsd/ufs/ufs_alloc.c': 64}`, `EXCEPTS[452]` = 451 의 여섯 + `x86-ufs_alloc`, `--plan` 목록에 452.
   - `m5_m68k_pc.py`: `FILES['ufs_alloc']`, `cmd2` 는 `-c` 가 있는 줄만 고릅니다(§451 까지의 결과는 바뀌지 않음: 고른 줄이 같음을 확인).
3. 스테이징 `--plan 452`, x86 관문, 스테이징 차이 = 이 `.c` 하나, `cmd2 452 ufs_alloc`, kr_run, otool, `final`.
4. 미리 정한 기준:
   - 원본에 없는 새 미정의 기호 0(`_verify_and_swap_cg`·`_byte_swap_cylgroup`·`_NXSwap*` 없음).
   - `x86-ufs_alloc` OBJECT_MATCH. 아니면 구간 진단(`diag`)으로 원인을 가리고, 두 시도 연속 줄지 않으면 멈춥니다.
   - `ufs_alloc_const_4`(`__TEXT,__const` 4 B)가 m68k 원본과 맞지 않아 불일치가 나면, 이를 따로 보고하고 바꾸지 않습니다(근거 없는 제거 금지).
5. 기록: PROVENANCE·MODIFICATIONS 덧붙임, diff `06_reconstruction/evidence/m68k-ufs-alloc.diff`, `09_validation/reconstruction/m5-m68k-ufs-alloc-20261010.json`.

### 452.1 교차검토(Opus 5.5 서브에이전트) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **`cmd2` 의 `-M` 줄 문제는 없음**: 조건 `' src/src/%s '` 는 파일명 뒤 공백이 필요하고, `-M` 줄(run.cmd 144 행)은 파일명 뒤가 줄바꿈이라 걸리지 않음 | python: 9 개 파일 모두 고른 줄이 하나이고(`ufs_alloc` 은 296 번째 줄 = run.cmd 56 행), `' -c '` 를 더 걸어도 같음 | ✅ **제 오류 정정** — 도구는 고치지 않고 `FILES['ufs_alloc']` 만 더함 |
| 바이트 교환 관련 차이를 모두 다루고, 빈 문장이 되는 교환 10 곳은 모두 중괄호 안 또는 `bdwrite` 앞이라 흐름이 NeXTMach 와 같음 | 07 824·847·889·908·922·928·941·1169·1267·1325 행 문맥(§452 준비 중 읽음)과 넣은 30 줄 = NeXTMach 줄(python 일치) | ✅ |
| m68k 쪽 전처리 결과는 NeXTMach 와 유지한 차이(getthetime·btodb·fsfull·bno·const·import)만 다르며, 빈 줄 하나가 늘어남(120·143 행) | python: 07 120·143 행 모두 빈 줄 | ✅ (`__text` 무관) |
| 원본 판독(검사·getthetime 각 1, blkpref 직접 읽기, fsfull `clrl`, printf `d5`) 맞음; `_realloccg` 에도 `btst #2` 2 개(0x4033a30·0x4033b6e)가 있으나 `bread` 오류 검사 | python grep | ✅ |
| 표시 줄 64, 두 표시가 한 줄에 없음 | 생성기 출력 `marked 64`, 스테이징 검사가 다시 판정 | ✅ |
| `#define byte_swap_cylgroup` 자리 안전(헤더에 선언 없음) | §452 준비 중 `grep -rn byte_swap_cylgroup 07_kernel/src --include=*.h` 0 건 | ✅ |
| 기존 §429 객체에서 외부 구간 11 개가 이미 같고, 다른 것은 손대는 6 함수뿐이며 `_verify_and_swap_cg` 는 원본에 없음; 간접 호출 `a0@` 는 `VOP_DEVBLOCKSIZE` | python `compare_object`: 같음 11(`_alloc` … `_realloccg`), 다름 6(`_alloccg`·`_blkpref`·`_fragextend`·`_free_block`·`_ialloccg`·`_ifree`), 없음 1 | ✅ (간접 호출 판독은 같은 구간 일치로 갈음) |
| `ufs_alloc_const_4` 의 m68k 일치 여부는 미확인 | — | ⏭️ 실행이 판정(§452 기준 4 그대로) |

### 452.2 결과(2026-10-10) — 기록 `09_validation/reconstruction/m5-m68k-ufs-alloc-20261010.json`(최종), `m5-m68k-ufs-alloc-const-20261010.json`(상수 배치)

- 07 덮어쓰기 `v183.34/m68k/src/bsd/ufs/ufs_alloc.c`(새 파일, 1478 행)는 표시 줄 64 개입니다.
  - diff 는 `06_reconstruction/evidence/m68k-ufs-alloc.diff` 입니다. PROVENANCE 1081 → 1082, MODIFICATIONS 606 → 607 입니다.
- 도구: `stage_m68k.py` 의 `MARKERS`(64)·`EXCEPTS[452]`·`--plan` 목록, `m5_m68k_pc.py` 의 `FILES['ufs_alloc']` 만 더했습니다(`cmd2` 는 고치지 않음, §452.1). 실행 전후 해시가 같습니다.
- 스테이징 차이는 이 `.c` 하나이고, x86 관문 7 스테이징은 같습니다.
- **시도 1**(run `m5p452-a1`, 1 명령):
  - `__TEXT,__text` 바이트 차이 0, 참조 167 개 모두 같음, 외부 구간 17/17 같음, 원본에 없는 새 미정의 기호 0 입니다.
  - 기본 L1(`--place-from-image`) 판정은 **NOT_MATCH, 이유는 `__TEXT,__const: unverified` 하나**입니다. 기호가 없는 static 상수 `ufs_alloc_const_4`(4 B)는 이미지에서 자리를 찾지 못합니다(x86 에서도 같은 원인이었고, 계획 397·398 에서 명시 배치로 확인했습니다).
- 상수 배치 확인(소스 변경 없음, 측정만):
  - 원본 m68k `__TEXT,__const`(0x40ace76, 2796 B)에서 `"swapfs\0"`(0x40acfdb–0x40acfe1) 바로 뒤 0x40acfe2 에 큰 끝 정수 4(`00 00 00 04`, 2 B 정렬)가 있고, 바로 뒤가 `_kern_serv_proto`(0x40acfe6)입니다. x86 의 순서(swapfs 0x1d1276 → ufs_alloc 0x1d1280 → kern_server)와 같습니다.
  - `--place __TEXT,__const=0x40acfe2` 에서 **OBJECT_MATCH**(상수 바이트 차이 0)입니다. 대조 자리 0x40acfe6·0x40acfde 는 불일치(차이 1·4)입니다.
- 판정: 미리 정한 기준 1(새 미정의 기호 0)은 충족합니다. 기준 2 는 기본 L1 로는 NOT_MATCH(상수 미배치만)이고, x86 선례와 같은 명시 배치로는 OBJECT_MATCH 입니다. 기준 4 의 "상수가 맞지 않으면" 경우는 일어나지 않았습니다(상수는 원본과 같음).
- m68k 누계: 208 중 207 컴파일. OBJECT_MATCH 는 기본 L1 로 156 이고, 명시 배치 하나(`ufs_alloc` 0x40acfe2)를 넣으면 157 입니다.
