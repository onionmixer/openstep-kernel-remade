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

## 보관된 세부 계획 색인 (§11–373)

§11–244 는 절 번호·내용을 바꾸지 않고 `02_plan/plans/` 의 보관 파일 세 개로 옮겼다(2026-10-03, 사용자 결정 D026). §245–320 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-245-320.md` 로 옮겼다(2026-10-05, 사용자 지시 “완료된 작업은 완료 문서로 분리”). 기존 인용 "RECONSTRUCTION_PLAN.md N"(N = 11–244)은 아래 색인의 보관 파일에서 같은 번호 절을 찾는다. §321–373 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-321-373.md` 로 옮겼다(2026-10-07, 사용자 지시 “완료된 작업은 완료 문서로 분리해도 됩니다”; 이 묶음 안의 진단 메모 §341·365·369·371 도 함께 옮김 — 이어지는 진단은 §374). §374 부터는 이 파일 끝에 이어 쓴다. 옮김 검증: 보관 파일 본문을 이어 붙이면 원래 줄과 같음(Python, 아래 숫자).

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

## 374. 진단 메모 — plan 373 뒤 남은 레지스터·식 차이(07 손대지 않음, 2026-10-07)

- ip_output(D028): 남은 4 B 는 조각 루프의 체크섬 저장 한 곳 — 원본 0x12781a 가 `mov eax,[ebp-0x4c]; add eax,0xa` 로 주소를 먼저 만들고 `[eax]`·`[eax+1]` 에 씀(첫 조각 자리는 07 꼴 `map[10]`·`map[11]` 그대로 맞음). 변형(`s5p371-ipv1`–`ipv6`, scratchpad `ipv/`): `&mhip->ip_sum` 바이트 대입(v1), 지역 포인터 `cp`(v2·v3·v6), memcpy(v4, 1580 B), 2 바이트 구조체 대입(v5, 빌드 실패) — 모두 1584 B 또는 더 나쁨. 원인 미확정.
- FBConsole DrawRect: 원본은 [0x19e23c, +1424)(Init 끝, python). ColorTable 지역 선언 순서 바꾸기(`s5p369-fbda`–`fbdd`)는 DrawRect·EraseRect 정렬 차이 수 그대로(fmatch·alf 기준); x·y 를 `km_rect->` 로 읽기(`fbde`)는 나빠짐. 관찰: 원본은 table 을 ebx, bits 를 스택, i 를 esi, bBits 를 edi 에 두고 B 시프트(bits − bPos − bBits)를 루프 안에서 매번 계산, `width − 640` 을 스택에 내렸다 다시 읽음; 작업본은 B 시프트를 루프 밖으로 옮김. 다음 후보: ColorTable 를 함수가 아니라 DrawRect·EraseRect 안 같은 글로(인라인 경계 차이), 루프 꼴. 추가: `static inline`(`fbdi`)은 같음, `-O2`(+inline `fbdj`, 인라인 없음 `fbdk`)는 다른 함수까지 바뀜(Init 704→528 B) → 원본은 -O3 꼴. EraseRect 원본 0x19e7e4–0x19e7f6: `width − 640` 을 ecx 에 만들고 [ebp−0x4c] 에 저장 뒤 다시 읽음(작업본은 eax 에 둠) — 남는 레지스터가 있는데도 내려 놓은 꼴이라, reload 가 어떤 명령 때문에 하드 레지스터 하나를 함수 전체에서 비운 흔적으로 보임(가설). [ebp−0x4c] 는 인라인된 ColorTable 의 console 사본과 같은 칸.

### 373.2 기록 정정 — ObjC 기록 도구가 남긴 "authored" 출처(2026-10-07)
- 찾음(python): ObjC 객체 행 67 개가 출처 칸에 "authored from the original bytes, D024" 를 가짐. PROVENANCE 종류가 authored 가 아닌 것은 둘 — swapgeneric.m(darwin01, D036; plan 324)·km.m(darwin01+nextmach, D037; plan 326). 두 계획은 PROVENANCE·MODIFICATIONS 만 고치고 objects_partial·functions 행은 도구 기본값 그대로 둠.
- 고침: objects_partial 두 행 출처 문구; functions 25 행(swapgeneric 5, km 20) — Darwin 정의 줄 인용(`darwin01/…:N (edited file :M)`), kmselect 는 nextmach km.c:310, kmopen·kmstart·kmoutput 은 darwin01+nextmach(07 파일의 plan 326 주석과 PROVENANCE 의 km.c:262-273·320-348·350-388). kmstart 의 07 줄은 원형 선언 :88 이던 것을 정의 :352 로.
- 검사(python): 인용 53 개를 원문·07 정의 줄과 대조 — Darwin·NeXTMach 정의 줄 28(kmopen 의 NeXTMach 은 정의 :183 + 범위), 07 정의 줄 25 모두 맞음. 행 수 그대로(functions 4679, objects_partial 70 줄).
- machine_clock(plan 365 이어서, scratchpad `mcv/`, run `s5p365-mvm1`–`mvm9`): 크기 1957 B 는 원본과 같고, 남은 것은 두 곳(정렬): ① clock_timer_init 0x187b4e 원본 `mov eax,esi; mov [reload],ax`(작업본은 `mov [reload],si`) ② us_spin_calibrate 원본은 프레임 0x10, elapsed 를 [ebp−8] 에 두 번 저장(timer_read 결과, `0xffff − elapsed`)하고 나눗수 ecx·피제수 ebx 순; 작업본은 프레임 0xc, timer_read 바이트를 [ebp−4] 에 word 로 저장. ① 시도: `reload = last_count`(m1)·순서 바꿈(m2)·형변환(m3·m5·m8·m9) 그대로; 지역 `unsigned short r = count` 를 먼저(m4)는 `mov eax,esi; mov [..],ax` 가 나오나 두 저장 모두 ax 이고 r 이 스택에 남음(1953 B); r 을 last_count 저장 뒤(m7)는 r 이 전역을 다시 읽음(1961 B). ② 는 reload 가 하드 레지스터를 비운 흔적으로 보임(가설). 보류.

## 375. S5-P356 세부 계획 — `driverkit/libDriver/Kernel/devswAndVfssw.m`(D030 작성, Darwin 0.1 과 거의 같음; plan 364 조사 메모 이어서; 코딩 전, 2026-10-07)

0. 원본(ObjC 모듈 기록 없음 — 이름은 Darwin 0.1 같은 이름 파일을 따름): `__text` [0x1a9ad4, 0x1a9f19) 1093 B + `00` 3 B → 다음 IOEthernet 0x1a9f1c; 앞은 IONetbufQueue(끝 0x1a9ad3, `c3` 뒤 `00` 1 B). 함수 9(IOAddToBdevswAt·IOAddToBdevsw·IORemoveFromBdevsw·IOAddToCdevswAt·IOAddToCdevsw·IORemoveFromCdevsw·IOAddToVfsswAt·IOAddToVfssw·IORemoveFromVfssw — 원본 기호). `__data` 68 B [0x1e5100, 0x1e5144)(static no_cdev 44 B·no_bdev 24 B; no_bdev 0x1e512c 는 원본 memcmp 의 `mov edi,0x1e512c` 와 같음).
1. 참조: 같은 이름 파일은 Darwin 0.1 driverkit-1/libDriver/Kernel/devswAndVfssw.m 뿐(`find 01_resources/upstream -name 'devswAndVfssw*'`) → Darwin 전용 libDriver 파일 = D030(작성 유지, 머리·PROVENANCE·MODIFICATIONS 에 "nearly the same as Darwin 0.1 …").
2. 4.2 에 맞춘 차이(근거): Darwin 은 vfssw 함수 3 개를 `#if 0` 으로 뺐으나 원본에 기호가 있음 → 넣음; 4.2 SDK `<driverkit/devsw.h>` 의 IOAddToBdevsw(At) 는 ioctl 인자 없음, SDK `<bsd/sys/conf.h>` bdevsw 는 d_ioctl 없고 `d_flags`(Darwin d_type), 테이프 표시는 원본 `mov [edx+0x14],0x400` = SDK buf.h B_TAPE; strategy_fcn_t·putc_fcn_t 형변환 없음(SDK 에 없는 형); NO_CDEVICE 의 seltrue 가 SDK 머리에 선언되지 않아 파일 안 `extern int seltrue();`.
3. 진단(scratchpad `devsw/`, 새 도구 `diag_objc.py` = diag_k07 의 07 사본 무대 + iter_objc 의 libDriver 꼴): `s5p375-dv0`(Darwin 원문 + vfssw) seltrue 미선언으로 실패; `s5p375-dv1`(2 항 수정) **OBJECT_MATCH**(9); `s5p375-dv2`(07 후보 = dv1 + D030 머리, Darwin 고지 뺌) **OBJECT_MATCH**(9), text 0·data 0(참조 46·15 같음).
4. 07 `src/driverkit/libDriver/Kernel/devswAndVfssw.m` 배치 → iter_objc(ROOT driverkit/libDriver, MODULE Kernel/devswAndVfssw.m) → relcheck → 실기 cc -M → 기록(authored, D030 문구) → A.
5. codex 교차검토(ktqp4rleg, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| "원본 모듈 Kernel/devswAndVfssw.m" 은 근거 없음 — 원본에 이 모듈 기록 없음, 빌드 객체에도 module_info 없음 | `grep -rl devswAndVfssw 03_original/x86/`(objc.json 등) 0 건; 빌드 객체 절은 `__text`·`__data` 뿐(python) | ✅ 채택: 07 머리를 "원본에 ObjC 모듈 기록 없음, 이름·자리는 Darwin 0.1 같은 이름 파일을 따름" 으로, 0 항 문구도 같은 뜻 |
| `<bsd/sys/buf.h>` 가 공통 기호 10 개 496 B 를 더함; 원본에 이름이 있고 크기가 맞음 — 기존 공통 기호 규칙상 허용, 대안은 지역 B_TAPE | python: `_bfreelist` 272·`_bufhash` 192·나머지 8 개 4 B, 합 496 | ✅ buf.h 유지(B_TAPE 는 SDK 이름 그대로가 덜 지어냄), 머리에 출처(buf.h, 원본 0x1a9b7a) 적음; 기록 때 공통 기호 검사 결과 남김 |
| 0–3 항 수치·Darwin 차이 근거·D030 문구·373.2 정정 25 행 53 인용 | 앞서 내 python·L1·diff 결과와 같음 | ✅ |
- 결과: 07 `src/driverkit/libDriver/Kernel/devswAndVfssw.m`(= cand.m, 머리 고침 뒤). `s5p375-it1` **OBJECT_MATCH**(9), relcheck 0, 실기 cc -M `s5p375-dep1` 21 헤더 모두 07(객체 = it1). 기록: record_object(authored, D030 문구; ObjC 모듈 기록이 없어 record_objc 대신) → objects_confirmed +1(311 줄), functions +9(4688), PROVENANCE +1(1020), MODIFICATIONS +1(491); 함수 9 행의 07 줄 모두 정의 줄(python). 기록기가 gap_after 를 다음 C 기호(0x1aace0)로 잡아 "3527 x 00" 이라 쓴 것을 "3 x 00, 다음 객체 IOEthernet 0x1a9f1c" 로 고침(바이트 `00 00 00`·`55 89 e5`, python). 공통 기호 중 _bufpages·_nbuf 는 원본에서 `__data` 정의(기록기 규칙대로 크기 검사 제외).
- 범위(python): 이번 1093 B. A 310 obj 599065 B (70.36%), P 69 obj 223153 B (26.21%), L 2 obj 340 B; A+P 96.57%, A+P+L 96.61%, rem 28878.

## 376. S5-P357 세부 계획 — `driverkit/objc_support.m`(D054 ④, D030 꼴 작성; 코딩 전, 2026-10-07)

0. 원본: `__text` [0x17e1e8, 0x17e231) 73 B + `00` 3 B → autoconfCommon 0x17e234; 앞은 vnode_pager(P, 끝 0x17e1e8, 채움 없음). 함수 3: NXFlush(0 반환), NXPrintf(splhigh → vlog(3, format, &args) 0x17e20a → splx), abort(panic "objc: fatal error\n", 0x1e0f36). `__data` 19 B [0x1e0f36, 0x1e0f49)(그 문자열, -fwritable-strings). 공통 NXArgv(원본 기호 0x1f7484, `__common`). ObjC 모듈 기록 없음.
1. 참조: Darwin 0.1 kernel/driverkit/objc_support.m 의 앞 세 함수(+ `char **NXArgv;`) — 같은 이름 파일은 Darwin 에만. 그 파일의 zone 부분은 4.2 에서 objc-runtime/objc-zone.c(plan 360)로 따로 기록됨. 이름·자리: D054(Darwin conf/files 순서 vm/vnode_pager.c → driverkit/objc_support.m → driverkit/autoconfCommon.m 이 원본 링크 순서와 같음).
2. Darwin 과 다른 곳(근거): `log(LOG_ERR, format, ap)` → `vlog(LOG_ERR, format, ap)`(원본이 _vlog 를 3·format·&args 로 부름); `<bsd/stdarg.h>` → `<stdarg.h>`(SDK 에 bsd/stdarg.h 없음, ansi/stdarg.h 있음); zone 부분 없음; Darwin 고지 빼고 D030 머리.
3. 진단(scratchpad `objs/`, diag_k07 커널 C 꼴): `s5p376-os1` bsd/stdarg.h 없음으로 실패, `s5p376-os2` **OBJECT_MATCH**(3; text 73 B·data 19 B 0 차이).
4. 07 `src/driverkit/objc_support.m` → iter_k07(커널 C 꼴, .m 이라 L1 --place-from-objc) → relcheck → 실기 cc -M → record_object(authored, D030/D054 문구) → A.
5. codex 교차검토(k8kj5opso, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| PROVENANCE 에 비교한 Darwin 원문(판·해시·`objc_support.m:36–71`)을 남겨야 함 — record_object 의 authored 기본값은 "no reference text" | Darwin objc_support.m :36 `#import <streams/streams.h>`, :71 panic 줄, :72 `}`(sed) | ⚖️ 채택: 범위는 36–72 로(닫는 괄호 포함); 기록 뒤 PROVENANCE 4 칸에 비교 원문 적음 |
| "zone 부분은 4.2 에서 objc-zone.c" 는 원래 이름처럼 읽힘 — plan 360 은 재구성 선택 | 보관 plan 360(:1156) "objc-zone.c(D024 작성…)" | ✅ 머리를 "따로 재구성(objc-runtime/objc-zone.c)" 로 |
| NXArgv 4 B 는 원본 0x1f7484 `__common`, 다음 _IOTask 0x1f7488 | symbols.tsv awk | ✅ |
| 0–3 항 수치·vlog·stdarg.h·D030 머리 | 내 앞선 python·빌드 결과와 같음 | ✅ |
- 결과: 07 `src/driverkit/objc_support.m`(= cand.m). `s5p376-it1` **OBJECT_MATCH**(3), relcheck 0, 실기 cc -M `s5p376-dep1` 25 헤더 모두 07(객체 = it1). record_object(authored, D030/D054 문구) → objects_confirmed +1(312 줄), functions +3(4691), PROVENANCE +1(1021; 4 칸에 비교 원문 darwin01 objc_support.m:36–72·판 해시), MODIFICATIONS +1; 함수 3 행 07 정의 줄 확인(python).
- 범위(python): 이번 73 B. A 311 obj 599138 B (70.37%), P 69 obj 223153 B (26.21%), L 2 obj 340 B; A+P 96.58%, A+P+L 96.62%, rem 28805.

## 377. 진단 메모 — `bsd/net/if_vtrip.c`(D054 ②, 이름 추정; 07 손대지 않음, 2026-10-07)

- 원본 [0x11fb84, 0x1209e9) 3685 B + `00` 3 B(netbuf 0x1209ec): SRHash·SRIsEqual(전역), 정적 output 0x11fbdc·input 0x11fddc·attach 0x120458, 전역 vtrip_config 0x120614, 정적 control 0x120648·getbuf 0x12075c, 전역 nullsap_input 0x1207bc, 정적 0x120950·0x120968. `__const` [0x1d11d8, 0x1d1209) 49 B(SRTablePrototype 16 B = {SRHash, SRIsEqual, NXNoEffectFree, 0}, "Internet Protocol", "802.2 Null Sap"), `__data` [0x1db870, 0x1db940) 208 B(add_sr 문자열 두 벌, LLC/SNAP 머리 aa aa 03 00 00 00 + 형, ARP 하드웨어 형 00 01·00 06, 기본 MTU 8100, "4/16Mb Token-Ring", printf 문자열 둘). 참조 원문 없음 — D024 작성; 07 tokensr.h(Darwin 꼴) 주석 "Used by if_vtrXX modules".
- 4.2 의 원천 경로 표는 MAC 키: 항목 32 B = MAC 6 B(+0, RII 끔) · ipAddr(+8) · ri(+12); SRHash 는 앞 4 B 와 뒤 2 B 를 NXPtrHash 해 XOR; add_sr 내보내기 조건은 `at == NULL || ipAddr == 0`, 한도 500. 07 tokensr.h 의 srtable_t·find_sr·add_sr·get_src_route·save_src_route 를 이 꼴로 바꾼 scratch 사본(`vtrip/tokensr2.h`, add_sr 의 지역 ifp 없앰)으로 진단. 07 에서 이 함수들을 쓰는 다른 기록 객체 없음(IOTokenRing 은 get_8025_hdr_len 만).
- 진단(scratchpad `vtrip/`, run `s5p377-vt1`–`vt18`, `b*`, `d*`): 11 함수 중 **10 일치**(SRHash·SRIsEqual·output·attach·config·control·getbuf·nullsap_input·정적 둘). 맞춘 꼴: venip 처럼 접근 함수를 인라인으로 하되 `static inline`(원본엔 VTRIP_* 기호 없음; 스택 정리 시점이 인라인 꼴), output 은 `struct ether_header *eh = (…)dst->sa_data` 를 선언 때 초기화, attach 는 `mtu = if_mtu(rifp) − 8; vmtu = vp->vmtu ? vp->vmtu : 기본; mtu = MIN(vmtu, mtu)`, kalloc(32) & ~3, LLC 보조 함수 둘은 nullsap_input 뒤에 정의(앞에 두면 인라인됨).
- 남은 것: vtrip_input(크기 1660 같음, 레지스터 배정 다름). 원본은 rifp→ebx, th→edi 이고 ifp 는 매번 [ebp+8] 에서 읽으며, 인라인 add_sr 의 netif 인자를 따로 사본([ebp−0x54])으로 둠(작업본은 ifp→esi 로 사본 없이 씀). `&ifp` 진단(y1)은 더 나빠짐. 원인 미확정 — GCC 2.7 인라인 인자 복사 조건(매개변수가 본문에서 바뀌면 복사)과 관련된 4.2 머리 꼴로 추정.

## 378. 진단 메모 — `bsd/swapfs/swapfs.c`(D054 ①, 이름 추정; 07 손대지 않음, 2026-10-07)

- 원본 [0x13a588, 0x13b714) 4492 B, 함수 18(전역 logswap·compress_data·uncompress_data, 정적 15 — 기호 없음). 정적 함수 이름은 `__data` 의 연산 표로 정함: `_swapfs_vfsops` 0x1dd8bc(SDK vfsops 7 칸: mount 0x13b2ec·unmount·root·statfs·sync·vget/mountroot = EINVAL 함수), 이어서 이름 없는 vnodeops 0x1dd8d8(getattr·setattr·inactive·pagein 0x13a9dc·pageout 0x13ac9c·nlinks·devblocksize, 나머지 EINVAL 0x13b6fc, prepagein·apageout 0). 0x13b580 은 mount 가 sysent[21] 에 꽂는 통계 조회(100 B copyout). 노드 124 B = vnode 0x34 + swapfs 자료 0x48(조각 크기 page/8, 지도 항목 수, 실제 vnode, 지도 {블록 24 bit·조각 수 4·위치 4}, 비트맵, hipage·hint, 읽기·쓰기 캐시, 압축 버퍼, 참조·잠금 바이트). `__data` [0x1dd7b4, 0x1dd95c)(전역 7 + 문자열 + swpgotcha + 표), bss 통계 100 B 0x1e5a34, 공통 logswp·logswapindex·compress_backoff_*·maxswapdevice·swapfs_*_map.
- 작업본(scratchpad `swapfs/cur.c`, run `s5p378-sf2`–`sf31`, 채점 `swapfs/score.py`): `__data` 0 차이(문자열 순서는 인라인 함수 정의 순서를 따름). 18 함수 중 **15 일치**(pagein 은 재배치 바이트만 다름). 맞춘 꼴: 성공 시 `return (0)` 따로, logswap(int type, …, char nfrag, char pos), compress/uncompress 는 지역 포인터와 `for (i = 0; i <= 7 && n < nwords; i++, n++)`·`&dst[(size + 3) / 32 + 4]`, 잠금·해제·지도 조회·읽기 캐시·쓰기 캐시·무효화·쓰기를 인라인 함수로(원본의 인자 사본 칸과 문자열 순서가 그 꼴), 쓰기 캐시 안에 쓰이지 않는 `struct vm_page`(원본 프레임 48 B), mount 는 SDK `VN_INIT`·`VN_HOLD`.
- 남은 것: alloc(찾기 루프 비교 — 원본은 movzx 뒤 레지스터 0xff 와 int 비교, 작업본은 바이트 비교), pageout(압축 호출 앞뒤 짧은 임시값 레지스터 이름 3 곳, 4 B), mount(원본은 vp→edi·sn 스택, 작업본은 sn 이 블록 지역 의사로 edi).
- 함께 찾은 것: 07 `machdep/i386/pmap.c` 의 compress_data_from_phys·uncompress_data_to_phys 인자 이름(plan 373)이 실제 쓰임과 다름 — compress_data(src, size, dst)·uncompress_data(src, srcsize, dst, size, …)이고 감싸개는 첫(압축)·셋째(복원) 인자에 pmap_phys_to_kern 을 써야 맞음. pmap_phys_to_kern 이 항등이라 바이트는 같음. swapfs 를 07 에 넣을 때 함께 고칠 것(기록 SHA 갱신).
- 이어서(같은 날): alloc **일치** — 찾기 루프는 `int full = 0xff;` 지역과 비교하는 꼴(상수 비교는 앞단이 바이트 비교로 좁혀 버림; 변수면 movzx 후 레지스터 비교, 루프 불변으로 0xff 가 esi 에 남음). 18 중 **16 일치**(pagein 은 재배치 바이트만). 남은 것: pageout(압축 호출 앞뒤 reload 레지스터 이름 3 곳 — reload 스필 순서 차이로 보임), mount(원본은 sn 이 넘친 의사, 작업본은 sn 이 edi).
- GCC 동작 근거: 실기 `/NextDeveloper/Source/GNU/gcc/`(cc-744.13 의 원문, 302 파일)에서 integrate.c·local-alloc.c·global.c·reload1.c 등 21 개를 읽기만 하려고 scratchpad 로 복사(SHA-256 = 실기 krsha256, 저장소 밖 임시 디렉터리는 지움; 01_resources 에 들이지 않음 — 들이려면 D050 범위 확장 결정 필요). integrate.c:1305–1327: 인라인 함수 인자는 그 매개변수가 본문에서 값이 바뀔 때(또는 반환 대상과 겹칠 때)만 새 레지스터로 복사. vtrip_input 의 원본 [ebp−0x54](add_sr 진입의 netif 사본)는 4.2 판 add_sr 가 netif 를 고치는 꼴임을 뜻함 — 진단 `s5p377-vtd2`(본문 끝에 `netif = 0` 진단용 대입)에서 원본처럼 add_sr 진입에 `mov esi,[ebp+8]` 사본이 생김(배정은 아직 다름). 4.2 판에서 무엇이 netif 를 바꿨는지는 바이트로 알 수 없음.

## 379. S5-P358 세부 계획 — 커널 `bsd/dev/i386/FBConsole.c`(D024·D030, Darwin 0.1 바탕; plan 341·369·374 진단 이어서; 코딩 전, 2026-10-07)

0. 원본(L1 `s5p369-fbe4` 기록, python): `__text` [0x19ba18, 0x19f09d) 13957 B + `00` 3 B → EventSrcPCKeyboard 0x19f0a0(A); 앞은 VGAConsole(P, 끝 0x19ba15, 틈 3 B). `__data` [0x1e4704, 0x1e488b) 391 B(정적 표 셋 + 문자열, -fwritable-strings). 함수 16: 정적 FlipCursor·Erase·BltChar·FBPutC·SetTitle·InitWindow·Init·DrawRect·EraseRect·Free·Restore·PutC·GetSize, 외부 FBAllocateConsole(0x19ec24)·FBAllocateVBEConsole(0x19ecb8)·VBEModeInfo2IODisplayInfo(0x19ed8c). 원본 기호표에는 이 범위의 외부 기호 3 개만 있음(정적 이름은 Darwin 것, 정적 ColorTable·table2Bit·table8Bit·colorTable 은 이 프로젝트가 붙인 추정 이름).
1. 참조: Darwin 0.1 `kernel/bsd/dev/i386/FBConsole.c` 만(같은 이름은 Darwin i386·ppc 에만, NeXTMach·Mach4 에 없음 — find). D030: 파일 머리는 프로젝트 작성(Apple·NeXT 고지와 HISTORY 없음, VGAConsole.c plan 338 선례), 본문은 Darwin 과 거의 같고 다른 줄은 plan 표시. 머리 `bsd/dev/i386/FBConsPriv.h`(SDK 에 없음)는 D032 로 `07_kernel/nextdev_private/bsd/dev/i386/FBConsPriv.h` 에 Darwin 본문 그대로(VGAConsPriv.h 선례). 진단에서 쓰던 param.h·ohlfs12.h 덧붙임은 필요 없음(`s5p369-fbe4`: FBConsPriv.h 하나로 OBJECT_MATCH).
2. Darwin 과 다른 곳(모두 원본 바이트 근거, 이미 진단에서 함수별 0 차이 확인):
   - plan 341: FBPutC 첫머리 `window_type == SCM_GRAPHIC` 이면 return; InitWindow save-under 의 `if (save)` 없음; Init 색 상수(8 비트·15 비트·24 비트)·화면 지우기 조건(이전 window_type)·TEXT 창 디스플레이 3/4·SCM_GRAPHIC 갈래·ALERT save-under 1; VIDEO_W/H 640×480; ColorTable(2·8 비트 정적 표, 그 밖 pixelEncoding 으로 4 색) 인라인.
   - plan 369: FBAllocateVBEConsole·VBEModeInfo2IODisplayInfo(D024, 부트 매개변수 블록 지역 정의 D035 꼴); Restore(`if (save)` 없음, IOFree, saveBits = 0 없음).
   - plan 341·379 DrawRect·EraseRect 본문(원본 바이트로 작성, D024): Darwin 의 `return -1` 없음, 지역 x·y(rect 는 width 만 고침), 주소는 rowBytes 로(Darwin 은 totalWidth 로 pixel 을 만들고 `size <= 0` 검사), EraseRect 는 깊이별 채우기 루프(Darwin 은 2 비트/그 밖 둘), Darwin 의 Description·Preconditions 주석(1132×832 화면 설명)은 두지 않음 — 함수 앞 묶음 표시 주석 하나로 표시.
   - plan 379(이번): (a) ColorTable 두 번째 루프는 R·G·B 최댓값·시프트를 변수로 미리 두지 않고 루프 본문 식으로 — 원본은 i = 0(0x19e946 `xor esi, esi`)을 마스크 계산보다 먼저 두고 B 시프트(bits − bPos − bBits)를 루프 안에서 매번 계산(0x19e9de–0x19e9e6): loop.c 가 본문 불변식을 루프 앞(초기화 뒤)으로 옮기고 레지스터 한도로 마지막 것은 남긴 꼴. (b) DrawRect 의 x·y 식만 인자 `km_rect->x`·`km_rect->y` 를 읽음(원본 0x19e3fd·0x19e41f `mov ecx, [ebp+0xc]`, 나머지는 rect 사본 [ebp−0x14]). (c) InitWindow save-under 할당이 `kalloc_noblock` 아닌 `IOMalloc`(원본 호출 0x19d3ac → _IOMalloc 0x1a5448).
3. 진단(diag_k07 커널 C 꼴, 07 손대지 않음): `s5p369-fbe1`(a) 16 중 14 일치(EraseRect 일치), `fbe2`(+b) 15, `fbe3`(+c) **OBJECT_MATCH**(16), `fbe4`(덧붙임 FBConsPriv.h 만) **OBJECT_MATCH**(16; text 13957 B·data 391 B 0 차이).
4. 07 배치: `src/bsd/dev/i386/FBConsole.c`(= scratchpad `fbc/v8.c` 에 D030 머리와 빠진 plan 표시를 덧붙인 것; 코드 바이트는 바꾸지 않음), `nextdev_private/bsd/dev/i386/FBConsPriv.h`(D032) → iter_k07(커널 C 꼴) → relcheck → 실기 cc -M(모든 헤더 07) → record_object(authored, D024/D030 문구) → A. PROVENANCE 2 행(.c·.h), MODIFICATIONS, functions 16 행 정의 줄 확인, 범위 갱신.
5. codex 교차검토(kz1qbap6g, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| DrawRect `size <= 0` 검사 삭제·totalWidth → rowBytes·EraseRect 깊이별 루프·Description 주석 삭제가 2 항에 열거되지 않음 | Darwin FBConsole.c :1134–1144(Description), :1172–1175(pixel·totalWidth·size), EraseRect :1300–1324(sed); 작업본 v8.c 에 `size <= 0` 없음, totalWidth 는 다른 함수(:316·:326·:335·:368·:1497)에만(grep) | ✅ 채택: 2 항에 한 줄 추가, 07 본의 함수 앞 표시 주석에도 적음 |
| 작업본에 plan 표시 없는 변경 덩어리(531–532, 926, 932, 1040–1098, 1120–1128, 1183–1187, 1206–1207, 함수 본문) | difflib 덩어리 48 개 중 표시 있는 것 2 개(python) | ✅ 사실 — 4 항에 이미 예정. 07 후보본(scratchpad `fbc/cand.c`)에 줄 표시 13 곳 + DrawRect·EraseRect 앞 묶음 주석 |
| D030/D032 머리 처리는 VGAConsole.c·VGAConsPriv.h 선례와 같음 | VGAConsole.c :1–9, VGAConsPriv.h :1–8, DECISIONS :34·:36 (sed·grep) | ✅ |
| 0–4 항 범위·함수·추정 이름·경로 모순 없음 | 앞서 L1 json·원본 기호표 python 집계(text 13957 B, data 391 B, 외부 기호 3) | ✅ |
| pmap.c 지역 KERNBOOTSTRUCT 와 충돌 없음, FBConsPriv.h 는 ohlfs12 를 extern 으로만 | 번역 단위 지역 typedef(pmap.c :350 typedef); Darwin FBConsPriv.h :41 `extern char ohlfs12[96][CHAR_H];`(grep) | ✅ |
| objects_partial VGAConsole 의 gap_after "12815 x 00 … next symbol at 0x19ec24" 는 FBConsole 인정 뒤 3 B 로 고쳐야 함 | objects_partial.tsv 63 줄 11 칸(awk); 0x19ba18 − 0x19ba15 = 3, 0x19ec24 − 0x19ba15 = 12815(python) | ✅ 채택: 기록 때 "3 x 00 (next object FBConsole 0x19ba18)" 로 정정 |
- 결과: 07 `src/bsd/dev/i386/FBConsole.c`(= scratchpad `fbc/cand.c`, v8.c 에 D030 머리·plan 표시만 더함), `nextdev_private/bsd/dev/i386/FBConsPriv.h`(D032, 본문 Darwin 그대로). `s5p379-it1` **OBJECT_MATCH**(16), relcheck 불일치 1 은 도구 한계 — `_ohlfs12` 가산값 −0x180(원본 단어 0x1e407c = _ohlfs12 0x1e41fc − 0x180, 작업본 가산값 0xfffffe80; python), L1 refs 차이 0. 실기 cc -M `s5p379-dep1` 25 헤더 모두 07(객체 = it1). record_object(authored, D024/D027/D030) → objects_confirmed +1, functions +16(4707; 16 행 07 정의 줄 확인 python), PROVENANCE +2(1023; FBConsole.c 4 칸에 비교 원문 darwin01 FBConsole.c·판 해시, FBConsPriv.h 행), MODIFICATIONS +2. 기록 도구가 gap_after 를 다음 C 기호(0x1a0ac8)로 계산한 것을 "3 x 00 … EventSrcPCKeyboard 0x19f0a0" 로, VGAConsole(objects_partial) gap_after 를 "3 x 00 … FBConsole 0x19ba18" 로 고침(원본 바이트 00 00 00 확인, python); 두 증거 .md 의 next symbol 문구도 함께.
- 범위(python): 이번 13957 B. A 312 obj 613095 B (72.01%), P 69 obj 223153 B (26.21%), L 2 obj 340 B; A+P 98.22%, A+P+L 98.26%, rem 14848 B; 겹침 없음.

## 380. 진단 메모 — plan 379 뒤 남은 레지스터 차이(swapfs·vtrip·ip_output; 07 손대지 않음, 2026-10-07)

- swapfs_mount(원본 0x13b2ec, 660 B): 원본은 `page_size / 4` 를 ebx 에 둔 채 호출 넷을 건너 bzero 크기(`shl ebx, 2`)로 다시 씀 → 지역 변수(`nmap`) 꼴(호출 뒤 메모리 필드를 재사용할 수 없음). 그 꼴(`s5p378-sfm5`, scratchpad `swapfs/m1.c`)은 656 B(원본 660). 원본 sn 은 0xa2–0xa6 `push ecx; mov [ebp−0x20], ecx; call bzero` — 저장이 인자 push 뒤·호출 바로 앞이라 GCC 2.7 caller-save(복원은 첫 사용 앞)의 꼴로 보임: sn 이 callee-saved 레지스터를 못 받고 `4 × 호출수 < 참조수`(global.c:1085 CALLER_SAVE_PROFITABLE)로 ecx 를 받은 것. 작업본(`-dl -dg` `s5p378-sfmd`)은 sn(의사 28, 40 회·102 insn·호출 11)이 우선순위 1 위로 edi. 원본에서 vp 가 edi 를 먼저 받은 까닭은 미확정. sn 을 버퍼 뒤에 선언(`sfm2`·`sfm3`)은 효과 없음.
- vtrip_input(원본 0x11fddc, 1660 B): 원본 갈래는 `cmp cx,0x800; je; cmp cx,0x806; je; jmp 기본`(0xd4–0xe6), IP·ARP·기본(nullsap_input, 0x65c) 순 — switch 꼴. switch 변형(`s5p377-vs1`, `vtrip/w30.c`)은 분기·호출 배치는 원본과 같으나 1572 B(레지스터: 원본 rifp→ebx·th→edi 를 처음부터, 작업본은 th 를 매번 [ebp+0x14] 에서). add_sr 첫머리 `ifp = netif` 사본은 원본 [ebp−0x54]·작업본(tokensr3) [ebp−0x58] 로 둘 다 있음.
- ip_output(원본 0x127280, 1588 B, 작업본 1584): 루프의 체크섬 두 바이트 저장 — 원본은 `mov eax,[ebp−0x4c](map); add eax,0xa` 뒤 `[eax]`·`[eax+1]`. 지역 포인터(v3·v6)·인라인 보조 함수(`s5p371-ipv7`)도 CSE 가 `[map+0xa]` 로 접음(인라인은 스택 정리 시점까지 바뀜). 원인 미확정.
- machine_clock clock_timer_init(원본 0x187a40): 남은 것은 원본 0x187b4e `mov eax, esi` 뒤 `mov [reload], ax`(작업본 `mov [reload], si`, 1 B 차이 + 정렬 nop). `reload = last_count = count`(`s5p365-mvm10`)는 last_count 값을 스택 임시로 두어 나빠짐, `reload = count & 0xffff`(`mvm11`)는 m1 과 같음.
- (이어서) swapfs 진전 — 작업본 scratchpad `swapfs/p9.c`(= `cur2.c`), run `s5p378-sfq9`: 18 함수 중 mount 만 남음(이후 함수의 DIFF 는 mount 크기 차이로 밀린 것).
  - pageout **일치**(`sfq1`): `offset >= sd_nmap * page_size` 갈래를 `goto out` 대신 `swapfs_unlock(vp); return (error);` 로. 근거(GCC 원문): reload 레지스터는 함수 전체에서 spill 레지스터를 돌아가며 고름(reload1.c allocate_reload_reg 의 round-robin, last_spill_reg); 이 함수의 spill 레지스터는 eax·edx 둘(`-dg`)이라 앞쪽 reload 할당 수의 홀짝이 0x1f0·0x208·0x275 의 eax/edx 를 정함. 그 갈래의 꼬리는 교차 점프로 out: 과 합쳐져 최종 코드는 같고 reload 수만 달라짐.
  - pagein **일치**(`sfq9`): swapfs_getmap 이 csize 를 `*csizep` 로 쓰지 않고 값으로 돌려줌(`csize = swapfs_getmap(sd, offset, &foff, &fragoff)`). 근거: 원본 csize 는 [ebp−0x40](맨 아래 칸) — 주소를 받는 지역은 선언 때 칸을 받지만 원본은 reload 의 spill 칸(마지막)에 있음; 작업본은 [ebp−0xc] 이고 나머지 칸이 4 씩 밀림(L1 11 B).
  - mount: 원본은 sn 이 caller-save ecx(저장이 호출 바로 앞), vp 가 edi(local-alloc 이 cbuf 에 준 edi 를 vp 가 밀어냄). global.c 순서(1076–1092 caller-save 판단이 1096– 밀어내기보다 먼저)로 보면 원본 sn 은 `4 × 호출수 < 참조수` 가 참이어야 함; 작업본 sn 은 참조 40·호출 11 이라 거짓 → 밀어내기로 edi. 진단(원본 꼴 아님): VN_INIT 를 `do { } while (0)` 로 감싸 참조를 50 으로 올리면(`sfq6`) sn→ecx·vp→edi 로 바뀌고 나머지는 rbuf 임시 레지스터와 루프 시작 스택 정리만 다름 → 메커니즘 확인. 자연스러운 원본 꼴(참조 +5 또는 호출 −1)은 미확정: sd 포인터(`sfq5`)·인라인 할당 보조 함수(`sfqa`)는 효과 없음.
  - mount 추가 시도(효과 없음): `register struct swapnode *sn`(`sfrpb`·`pd`), nmap 결합(`sfrpc`), vnode 포인터 사본 `svp = &sn->sn_vnode`(`sfrpe`·`pf`, 참조 41).
- vtrip_input 추가 단서(`s5p377-vsd`, `-dl -dg`): 원본은 호출 결과마다 `mov ecx, eax`(if_private·nb_size·bcmp·nullsap_input 뒤)로 다른 레지스터에 옮기고, 매개변수 재읽기 reload 가 eax·edx·esi 를 돌아가며 씀 → 원본은 eax 가 spill 레지스터(그래서 호출 결과 의사가 eax 에 못 앉음). 작업본(switch 꼴)은 insn 408(GENERAL 2 개 필요) 때문에 edx·edi 를 spill 하고 th→ebx·rifp→esi(원본 rifp→ebx·th→edi). 원본에서 eax 를 spill 하게 만든 명령(AREG/AD_REGS 필요)이 무엇인지 미확정.
- machine_clock 추가(`s5p365-mvm12`–`mvm19`, `mvd1`·`mvd2` 덤프): 작업본의 `reload = last_count` 는 메모리→메모리 이동이라 reload 가 같은 값을 가진 esi 를 바로 씀(reload1.c 5290–5350). 원본의 `mov eax, esi` 는 별도 HI 임시 의사가 eax 에 배정되고 esi 에서 복사된 꼴로 보임; `r = last_count`(m12)·`r = count`(m14)는 CSE 가 last_count 메모리에서 읽게 바꿈, `reload = last_count = (u_short)count`(m15)는 두 저장 모두 ax, volatile(m18·m19)은 효과 없음.
- ip_output 추가(`s5p371-ipv8`·`ipv9`): 2 바이트 구조체 대입·memcpy 는 i386 에서 HImode 한 번 저장(`mov [edi+0xa], ax`)이 되어 원본(바이트 둘) 꼴 아님; `cp = map; cp += 10;` 도 CSE 가 `[map+0xa]` 로 접음. 근거(GCC 원문): i386 ADDRESS_COST 는 REG+상수 0 < REG 1(config i386.h 1506–1511)이라 cse.c find_best_addr 가 같은 값 부류에 `map + 10` 이 있으면 늘 그 꼴로 바꿈 → 원본의 `eax = map + 10` 은 CSE 가 그 값을 모르는 경로(다른 확장 블록에서 만든 값 등)에서 나온 것으로 보임. 미확정.

## 381. S5-P359 세부 계획 — `bsd/net/if_vtrip.c`(D054 ②, 이름 추정, D024 작성) + `nextdev_private/bsd/net/tokensr.h` 4.2 꼴(plan 377·380 이어서; 코딩 전, 2026-10-07)

0. 원본(L1 `s5p377-v4s4`, python): `__text` [0x11fb84, 0x1209ea) 3686 B, 앞 if_venip(끝 0x11fb81, `00` 3 B)·뒤 netbuf(0x1209ec, `00` 2 B); `__const` [0x1d11d8, 0x1d1209) 49 B(SRTablePrototype 16 B, "Internet Protocol" 18 B, "802.2 Null Sap" 15 B); `__data` [0x1db870, 0x1db91b) 171 B(L1d). 함수 11: SRHash·SRIsEqual·vtrip_config·nullsap_input(원본 기호 있음), 정적 vtrip_output·vtrip_input·vtrip_attach·vtrip_control·vtrip_getbuf·llc_reply·llc_send(이름 추정). 원본 기호는 그 밖에 _SRTablePrototype 뿐(정적 IFTYPE_IP·IFTYPE_NULLSAP 이름 추정).
1. 참조 원문 없음(같은 이름 파일 없음 — plan 377). 07 tokensr.h(Darwin 0.1 꼴, plan 303 D032)는 Darwin 의 IP 키 원천 경로 표; 원본 if_vtrip 바이트는 MAC 키 표(항목 32 B: MAC 6 B·ipAddr +8·ri +12)를 요구 → tokensr.h 의 srtable_t·find_sr·add_sr·get_src_route·save_src_route 를 4.2 꼴로(D024, 줄마다 plan 381 표시, 머리 문구 갱신). 이 머리를 쓰는 다른 07 파일은 libDriver Kernel/IOTokenRing.m 뿐(grep) — 새 머리로 진단 `s5p381-tr1`·`tr2` **OBJECT_MATCH**(41) 그대로.
2. plan 380 뒤 이번에 맞춘 것(근거):
   - switch 꼴(원본 0xd4–0xe6 `cmp cx,0x800; je; cmp cx,0x806; je; jmp 기본`).
   - `short etype`(부호 있음): C 앞단은 switch 식을 부호가 같을 때만 좁혀 16 비트 비교(원본 `cmp cx`), u_short 이면 int 로 넓혀 32 비트 비교(작업본 `movzx ecx,si; cmp ecx`).
   - add_sr 의 ARPTAB_LOOK 에 지역 `ipa` 없이 `sourceRouteEntry->ipAddr` 직접: 원본 ARP 갈래 0x54c·0x54f `mov eax,[ebp−0x4c]; mov [ebp−0x4c],eax`(안쪽 루프 0x554 바로 앞, 같은 칸 읽기·쓰기). 루프 안 비교용 읽기를 loop.c 가 루프 밖으로 옮긴 꼴로 해석함(해석; 원본 RTL 로 확정한 것은 아님) — 이 꼴로 바꾸면 ipa 가 edi 를 받고 reload 가 eax·edx·esi 를 비워(호출 결과 `mov ecx,eax` 들) 작업본이 원본과 일치함.
   - `__const` 순서: IFTYPE_IP·IFTYPE_NULLSAP 정적 배열을 SRTablePrototype 정의 뒤에(앞에 두면 문자열이 먼저 나와 52 B, vtrip_attach 의 참조 1 건 다름).
3. 진단: `s5p377-v4s1`(switch+tokensr4) vtrip_input 1664 B, `v4s3`(+short) text 0 차이·const 순서만 다름, `v4s4`(+const 순서) **OBJECT_MATCH**(14); 07 후보(scratchpad `vtrip/cand.c`·`vtrip/tokensr_cand.h`, 표시 주석만 더함) `s5p381-vc1` **OBJECT_MATCH**(14), IOTokenRing `s5p381-tr2` **OBJECT_MATCH**(41).
4. 07 배치: `src/bsd/net/if_vtrip.c`(= cand.c), `nextdev_private/bsd/net/tokensr.h`(= tokensr_cand.h) → iter_k07(if_vtrip) → iter_objc(IOTokenRing 재확인) → relcheck → 실기 cc -M(모든 헤더 07) → record_object(authored, D024/D054) → A; tokensr.h PROVENANCE·MODIFICATIONS 갱신(plan 381), gap 칸 확인(앞 3 B·뒤 2 B), 범위 갱신.
5. codex 교차검토(kdl3xjpay, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 후보 tokensr.h 에 "ipAddr must be the first element" 옛 주석이 남음(MAC 키와 모순) | 후보 :36–39(sed) | ✅ 채택: plan 381 표시로 MAC 키 설명으로 바꿈 |
| 0 항 범위·크기·틈·원본 기호 구분은 맞음 | 앞서 L1 json·원본 기호표 python(이번 세션) | ✅ |
| plan 377 의 3685 B·뒤 3 B·data 208 B, D054 의 3691 B 는 틀림(python 3688 B) | DECISIONS :58 `0x11fb84–0x1209ec 3691 B`(grep), python 0x1209ec−0x11fb84 = 3688, 0x1209ea−0x11fb84 = 3686; plan :569(sed) | ✅ 내 기록 오류 — 정정 메모(아래), D054 칸에 정정 덧붙임 |
| 머리 외 표시 없는 바뀐 줄은 빈 줄 하나뿐 | 후보 :229–233(cat -A) | ✅ 행동 변화 없음 |
| 다른 소비자 없음(IOTokenRing 만, get_8025_hdr_len) | 07 전수 grep(이번 세션): IOTokenRing.m·tokensr.h·기록 파일뿐 | ✅ |
| 2 항 관찰은 맞으나 loop.c 원인은 추정으로 써야 함 | 원본 역어셈블 0x54c·0x54f·0x554(이번 세션 출력) | ⚖️ 채택: 해석임을 밝힘 |
| PROVENANCE·MODIFICATIONS 의 "body verbatim" 문구 갱신 필요 | PROVENANCE :737(grep) | ✅ 4 항 예정대로 기록 때 반영 |
- 정정(plan 377 메모): 원본 if_vtrip 는 `__text` [0x11fb84, 0x1209ea) 3686 B + `00` 2 B(netbuf 0x1209ec), `__data` 171 B(L1d) — plan 377 의 3685 B·`00` 3 B·208 B 는 이전 추정치.
- 결과: 07 `src/bsd/net/if_vtrip.c`(= scratchpad `vtrip/cand.c`), `nextdev_private/bsd/net/tokensr.h`(= `vtrip/tokensr_cand.h`, codex 지적 주석 반영). `s5p381-it1` **OBJECT_MATCH**(14), relcheck 0; IOTokenRing 을 07 에서 다시 빌드 `s5p381-tok` **OBJECT_MATCH**(41); 실기 cc -M `s5p381-dep1` 48 헤더 모두 07(객체 = it1). record_object(authored, D024/D054) → objects_confirmed +1(gap 앞 3 B·뒤 2 B 맞음), functions +11(4718; 11 행 07 정의 줄 확인 python), PROVENANCE +1(if_vtrip) 및 tokensr.h 행 갱신(plan 381, 새 해시), MODIFICATIONS +2.
- 범위(python): 이번 3686 B. A 313 obj 616781 B (72.44%), P 69 obj 223153 B (26.21%), L 2 obj 340 B; A+P 98.65%, A+P+L 98.69%, rem 11162 B; 겹침 없음.

## 382. 진단 메모 — `machdep/i386/machine_clock.c`(plan 365·380 이어서; 07 손대지 않음, 2026-10-07)

- us_spin_calibrate **일치**(`s5p365-mvm28`, scratchpad `mcv/m28.c` = `mcv/cur.c`): Darwin 0.1 꼴처럼 `timer_cnt_val_t leftover` 하나에 읽고 `splx(s)` 뒤 식 안에서 `(int)(TIMER_COUNT_MAX - leftover)` 로 나눔. 근거: 원본은 timer 값(bx)을 splx 너머로 들고 가서 splx 뒤 [ebp−8] 에 두 번 저장(0 확장 값, `0xffff − 값`) — 같은 임시 의사가 두 번 쓰이고 idiv 의 reload 때문에 스택 칸으로 밀린 꼴; 작업본(`elapsed = timer_read()` 를 splx 앞에서)은 elapsed 가 레지스터. `mvm26`·`mvm27`(지역 count + splx 뒤 대입)은 코드는 같고 칸 배치만 달랐음.
- machine_clock L1(`mvm28`): 11 함수 중 clock_timer_init 만 DIFF(45 B = `mov eax, esi` 1 B 와 그 뒤 밀림), 나머지는 bss 배치 미확정으로 MATCH_UNVERIFIED.
- clock_timer_init: panic 문구 "clock_timer_constant 1/2/3" 과 Darwin `system_timer_constant()` 로 보아 4.2 에는 상수를 돌려주는 정적 함수 clock_timer_constant 가 인라인된 것으로 추정. 그 꼴(`mvm30`–`mvm39`): 반환형 timer_cnt_val_t 이고 함수 안에서 `last_count = count;` 를 한 뒤 `reload = clock_timer_constant();`(`mvm34`)면 `[last]=si; mov eax,esi; [reload]=ax` 가 원본과 같아지지만, CSE 가 반환값 의사를 last_count 메모리와 같은 값으로 보아 timer_write 인자가 스택 임시가 됨(원본은 last_count 메모리를 두 번 읽음); 반환형 unsigned int/int(`mvm36`·`mvm37`)는 timer_write 는 맞으나 반환값 복사가 combine 에 흡수(si). volatile reload 결합(`mvm38`·`mvm39`) 효과 없음. 미확정.
- (이어서, 2026-10-07) ip_output: 원본 커널 `__text` 전체에서 "주소를 레지스터로 더해 만든 뒤 `[r]`·`[r+1]` 바이트 저장" 꼴을 python 으로 찾으면 ip_output 의 0x12781a 한 곳뿐 — 이미 맞춘 객체에서 같은 관용구의 소스를 빌려 올 수 없음. 덤프(`s5p371-ipd3`, `-dr … -dl`)로는 지역 포인터 `cp = map + 10` 이 CSE 단계에서 `(plus map 10)` 주소로 접힘을 확인.
- machine_clock: 인라인 clock_timer_constant 꼴(`mvm34`)에서 반환값 의사가 last_count 메모리와 이어지는 것은 인라인 반환 레이블이 jump1 에서 지워져 CSE 가 한 블록으로 보기 때문(`s5p365-mvd5` rtl·cse 덤프). timer_write 를 ANSI 원형으로 바꾼 진단(`s5p365-tim34`)은 효과 없음.
- swapfs_mount: kalloc 결과를 임시 포인터로 받아 bzero 뒤 sn 에 대입(`s5p378-sfpt1`·`pt2`)해도 CSE 가 둘을 한 의사로 합쳐 참조 40·호출 11 그대로.
- 컴파일 옵션 가설 배제(2026-10-07, scratchpad `flagsweep.sh`·`flagsweep.log`, run `s5p383-fs1`–`fs14` × {swapfs `pc.c`, machine_clock `m28.c`, 07 ip_output}): -fno-caller-saves, -fno-expensive-optimizations, -fno-rerun-cse-after-loop, -fno-cse-follow-jumps, -fno-cse-skip-blocks, -fno-force-mem, -fno-defer-pop, -fno-strength-reduce, -fthread-jumps, -fno-inline-functions, -fkeep-inline-functions, -fno-function-cse, -m486, -fomit-frame-pointer 를 하나씩 더해도 swapfs_mount(656 B)·clock_timer_init(4 줄)·ip_output(9 줄) 잔여는 그대로이거나, 이미 일치하던 함수가 깨짐. 세 잔여는 옵션이 아니라 소스 꼴 차이로 판단.
- machine_clock 인라인 clock_timer_constant 조합 전수(`s5p384-t{0..4}{in,before,after}`, scratchpad `mcv/sw/`): 반환형 timer_cnt_val_t·unsigned short·int·unsigned int·long × last_count 대입 위치(함수 안/호출자에서 지역 사본으로/호출자에서 reload 뒤) 15 개. 함수 안·reload 뒤 꼴(int·unsigned int·long)은 m28 과 같은 잔여(`mov eax, esi` 없음), 나머지는 10 줄(timer_write 인자 스택 임시)로 더 나쁨. us_spin_calibrate 는 모두 0.
- 컴파일러 판 가설(사실과 추정 구분): 원본 커널 문자열 `NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386`(strings) — 1999-01 의 4.2 패치 빌드. 실기의 컴파일러는 `/bin/cc`·`/lib/i386/*` 1997-04-23 날짜의 cc-744.13 하나(gcds ls). 원본 커널을 만든 cc 판은 바이너리에 문자열이 없어 알 수 없음. 313 객체가 cc-744.13 으로 바이트 일치하므로 같은 계열이지만, 1999 빌드 기계의 cc 가 744 계열의 후속 패치판이었다면 남은 세 곳(caller-save 판단·CSE 등가·combine)의 드문 차이를 설명할 수 있음(추정). 확인하려면 다른 판의 NeXT cc 가 필요 — 들여오기는 사용자 결정 사항.
- ip_output 변형 조사(`s5p385-a1`·`a2`·`b1`·`c1`·`c2`, scratchpad `ipv/sw/`): 포인터를 bcopy 앞에서 만들기(a1·a2), 원천·대상 포인터 둘(c1·c2)은 기준과 같은 9 줄(CSE 가 접음). 포인터를 루프 첫머리(map 대입 직후)에서 만들기(b1)는 다른 확장 블록이라 접히지 않아 `[r]`·`[r+1]` 꼴이 나오지만, 포인터가 호출들을 건너 스택 칸([ebp−0x50])에 저장·재적재되어 원본(저장 직전 `[ebp−0x4c]`+0xa 재계산)과 다르고 프레임도 4 B 큼. 원본은 "같은 자리에서 계산하면서도 CSE 가 접지 않는" 경우인데 그 조건을 아직 못 찾음.
- 2026-10-07 사용자 답: 다른 판 NeXT cc 는 구할 수 없음 → cc-744.13 으로 소스 탐색 계속.
- swapfs_mount 진전(2026-10-07, scratchpad `swapfs/`): 루프 가중(flow 의 loop_depth)으로 sn 참조가 문턱을 넘는 꼴을 찾음 — 함수 본문 전체를 `do { … } while (0)` 로 감싼 `s5p378-sfpw1`(`pw1.c`, nmap 지역 포함)은 sn→caller-save ecx·vp→edi·뒤쪽(0xd9 이후) 전부가 원본과 같고, 앞쪽만 다름(data 인자가 ecx 를 받음, getvnodefp 인자 재적재 레지스터, rbuf 를 kalloc 결과 임시(원본 ecx) 없이 바로 저장, &max 를 스택에 내림). 루프 시작 위치 조사(`sfwl0`·`l0b`·`l1`·`l2`·`l3`): getvnodefp(L0b)·vp 대입(L1)부터면 크기 660 B 로 같지만 루프 안 ENOTDIR 반환 블록을 jump 최적화가 루프 앞으로 옮김; copyin(L0)부터면 data 가 레지스터를 받음; VN_HOLD(L2)·rbuf(L3)부터 또는 sd_rbuf 에서 끝나는 부분 루프(`sfpe1`–`pe3`)는 vp 가 스택으로 밀림. 조기 반환을 break 로 쓴 꼴(`sfpbc`·`pbd`·`pbe`)은 더 나쁨. 연쇄 대입 `wbuf = (rbuf = kalloc(..)) + page_size`(`sfpr*`)·SDK `<kernserv/kalloc.h>`(07 머리와 kalloc 선언 충돌로 컴파일 안 됨)도 rbuf 꼴 아님. 해석: 원본에는 vp 를 쓰는 구간 전체를 덮는 루프(가중) 구조가 있고 그 모양은 아직 미확정(추정).
- swapfs_mount(이어서): 루프 구문 `for (;;)`·`while (1)`(`sfgbf`·`gbw`·`gwf`·`gww`)은 do-while(0) 과 같은 결과. L2(VN_HOLD 부터) 덤프(`sfwl2d`): sn 은 caller-save ecx 로 원본과 같으나 rbuf(참조 8/56 insn, 우선순위 3·8/56)가 vp(15/121, 3·15/121)보다 앞서 edi 를 가져가 vp 가 스택으로 밀림 — 원본처럼 vp 가 앞서려면 vp 참조 16 이상(floor_log2 4) 또는 rbuf 참조 7 이하가 필요. 루프 안 ENOTDIR 반환 블록은 jump.c 의 "if (foo) bar; else break;" 범위 교환(jump.c 1800–1913)으로 옮겨지는 것으로 보임. kalloc 결과 형 변환(`sfpt*`)·별도 지역 buf(`sfpb*`)는 CSE 가 접어 효과 없음.
- **swapfs_mount 큰 진전**(`s5p378-sfpz1`, scratchpad `swapfs/pz1.c` = `cur3.c`): 두 번째 kmem_suballoc 문장(`swapfs_rem_map = …`)부터 함수 끝까지를 `do { … } while (0)` 로 감싸면, 앞쪽 rbuf·wbuf·cbuf 계산 7 명령(원본 0x7e–0x94, 크기 656 대 660 B)만 빼고 원본과 같음. 근거(GCC 원문): loop.c 는 루프 안 "조건 점프 뒤 루프 밖으로 나가는 블록"을 반환 레이블과 같은 깊이의 barrier 로 옮기므로(loop.c 2300–2420) ENOTDIR 반환 블록은 루프 밖이어야 하고, expand_start_loop 는 루프 시작에서 대기 스택 정리를 내보내므로(stmt.c expand_start_loop) 루프는 원본에 스택 정리가 있는 자리(0xcb `add esp,0x24`)에서 시작해야 함; 그 자리에서 시작하면 rbuf 참조 일부만 가중을 받아 vp 가 rbuf 보다 앞서 edi 를 받고, sn 은 caller-save ecx. 남은 7 명령: 원본은 kalloc 결과를 임시(ecx)에 받아 rbuf 에 저장하고 page_size 를 메모리 피연산자로 두 번 더함(`add ecx,[page_size]`); 작업본은 page_size 를 한 번 읽어 재사용. 시도: caddr_t 형(`sfpz3`·`pz4`), `+=`·연쇄·피연산자 순서(`sfpz6`–`pz8`) 효과 없음; 주소 잡기(`sfpz5`, 진단)는 칸 순서가 바뀌어 원본과 다름. 루프 꼴의 원본 소스 의미(왜 루프인지)는 미확정.
- swapfs_mount 남은 7 명령(원본 0x7e–0x94) 분석(`s5p378-sfpz1d` cse·lreg·greg 덤프): 작업본은 page_size 를 한 의사(REG_EQUIV `(mem page_size)`)로 CSE 해 두 덧셈이 공유하고 local-alloc 이 eax 를 줌; 원본은 두 덧셈 모두 `add r,[page_size]` 메모리 피연산자이고 kalloc 결과가 임시(ecx)를 거쳐 rbuf 칸에 저장됨 → 원본에서는 page_size 읽기가 둘로 나뉘어(각각 한 번 쓰이는 REG_EQUIV 의사라 local-alloc update_equiv_regs 가 메모리로 바꿈) CSE 가 합치지 않은 것으로 보임(해석). 선언 순서·형·register 조합 8 개(`s5p386-b1`–`b8`)는 효과 없음.
- swapfs_mount(이어서): update_equiv_regs 는 참조가 정확히 2(설정·사용 하나씩)인 의사만 메모리 등가로 바꿈(local-alloc.c `reg_n_refs[regno] == 2`) — 원본은 page_size 읽기가 둘로 나뉜 꼴이 맞음. kalloc 을 감싼 인라인 함수(`sfpi1`·`pi2`)는 인라인 끝에서 대기 스택 정리(`add esp,4`)가 생겨 원본 꼴 아님.
- machine_clock(이어서): 인라인 clock_timer_constant 에 반환 경로 둘(panic 갈래 안에서도 `last_count = count; return (count);`)을 두면(`s5p365-mvm43`·`mvm44`) 반환 레이블이 CSE 단계까지 남아 반환값 복사가 살아남고 timer_write 는 원본처럼 last_count 메모리를 읽음 — 다만 두 꼬리가 교차 점프로 합쳐지지 않아 `jmp`·중복 코드가 남고 복사 레지스터가 ecx(원본 eax). 방향 단서로 기록.
- machine_clock(이어서): K&R 꼴 인라인 `set_reload(val) timer_cnt_val_t val; { reload = val; }` 를 `last_count = count; set_reload(count);`(`mvm45`)·`set_reload(last_count)`(`mvm46`)로 부르면 reload 저장이 별도 의사를 거치고 timer_write 는 메모리를 읽어 원본 꼴에 가장 가까움 — 남은 차이는 그 의사의 원천이 `mov ax,[last_count]`(작업본) 대 `mov eax,esi`(원본). 16 비트 지역 사본(`mvm47`)·`set_reload(last_count = count)`(`mvm48`)는 timer_write 인자가 스택 임시가 되어 더 나쁨.

## 383. S5-P360 세부 계획 — `bsd/netinet/ip_output.c` 루프 체크섬 저장(plan 175.1·380 이어서; D024 작성; 코딩 전, 2026-10-07)

0. 원본(objects.tsv seq 82): `__text` [0x127280, 0x12823f) 4031 B(python), ip_output 1588 B. 07 `src/bsd/netinet/ip_output.c`(plan 175) 는 남은 차이가 이 저장 하나라 표에 넣지 않았음(175.1).
1. 남은 차이(원본 [0x12781a, 0x12782b), 17 B, python): `mov eax,[ebp−0x4c](map); add eax,0xa; mov cl,[ebp−0x1e]; mov [eax],cl; mov cl,[ebp−0x1d]; mov [eax+1],cl`. 07 은 `[map+0xa]`·`[map+0xb]` 로 접힘(i386 ADDRESS_COST, cse.c find_best_addr — plan 380).
2. 진단(07 손대지 않음, scratchpad `ipv/`):
   - codex 브레인스토밍 후보 중 빈 `__asm__` 로 `cp` 를 불투명하게 한 꼴(`s5p387-c5`) **OBJECT_MATCH** → 메커니즘 확인(별도 의사 레지스터에 `map + 10`). asm 은 원본 꼴로 보기 어려워 채택하지 않음.
   - 순수 C: `cp = map + 10; map = 0; mhip = 0;`(`c6`) text 3 B 차이(0x4a7·0x4aa·0x4c5: map 의 두 칸 −0x4c/−0x34 저장 순서와 ip_optcopy 인자 읽기 칸이 바뀜); `cp = map + 10; mhip = 0; map = 0;`(`c7`)·`cp = map + 10; map = 0;`(`c8`) **OBJECT_MATCH**(9); `cp = (char *)mhip + 10`(`c9`)·`cp = map + 10; mhip = 0;`(`c10`)·`map += 10` 꼴 둘(`c11`·`c13`)·`map = (char *)&mhip->ip_sum`(`c14`)·`mhip = (struct ip *)(map + 10)`(`c15`)는 크기가 달라 불일치.
   - 해석(GCC 원문 근거는 plan 380 의 cse 메모): `map` 에 새 값이 들어가면 cse 가 `cp` 를 `map + 10` 으로 되돌려 접을 수 없어 cp 가 따로 레지스터에 남음. 원본 소스 꼴은 모름 — c8 은 시험한 일치 꼴 중 가장 짧은 꼴(죽은 저장 `map = 0` 은 생성 코드에 남지 않음: OBJECT_MATCH).
3. 07 변경(c8 + 표시 주석, scratchpad `ipv/cand383.c`): 루프의 `map[10]`·`map[11]` 두 줄을 블록 `{ char *cp; cp = map + 10; map = 0; cp[0] = …; cp[1] = …; }` 로, plan 383 주석(원본 주소, 원본 꼴 모름) 포함. 첫 조각(0x1276bc, 접힌 꼴)은 그대로. 후보 진단 `s5p383-ic1` **OBJECT_MATCH**(9).
4. 이어서: iter_k07 → relcheck → 실기 cc -M(모든 헤더 07) → record_object(NeXTMach 바탕 + D024 작성; plan 175·383) → A; PROVENANCE·MODIFICATIONS·functions·evidence(x86-ip_output.md/.diff), 틈 칸(앞 0x12727e·뒤 0x128240, objects.tsv) 확인, 범위 갱신. plan 175.1 "기록 보류" 해제를 175 쪽(보관 문서)에 한 줄 덧붙임.
5. codex 교차검토(k4fso0nd6, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `map = 0` 뒤 map 을 읽는 곳 없음(다음 쓰기는 루프 첫머리) | 후보 전수 grep `\bmap\b`(82·293–302·319–336·351–352 행), done:/bad: 362–368 행(sed) | ✅ |
| 0x12781a·0x12782b·17 B 맞음, 끝은 배타 표기로 | python 0x127280+0x59a, +0x5ab, 0x5ab−0x59a | ✅ 표기 `[ , )` 로 고침 |
| c6 차이는 저장 순서만이 아니라 뒤 읽기도(0x4a7·0x4aa·0x4c5) | `s5p387-c6` L1 json first_differences 1191·1194·1221, python 파일 오프셋−244; c5/c6 objdump diff(0x4c3 `mov ecx,[ebp−0x34]`) | ✅ 문구 고침 |
| c9·c10·c14·c15 4027 B, c11·c13 4091 B | python macho_obj 로 각 목적 파일 `__text` 크기 | ✅ |
| "가장 짧은 꼴" 은 "시험한 꼴 중" 으로 | — | ✅ 문구 고침 |
| 4 항: 첫 기록이므로 파일 전체 출처(NeXTMach URL·커밋·경로, CMU/Berkeley 고지 유지), 175·175.1·383 전체 diff, 함수별 출처 구분 필요 | 06_reconstruction/README.md :15·:26–27(sed), PROVENANCE·MODIFICATIONS 에 ip_output 행 없음(grep 0 건) | ✅ 채택 |
| 더 자연스러운 꼴: `cp = map + 10; map = (char *)&iph.ip_sum; cp[0] = map[0]; cp[1] = map[1];` | 빌드 `s5p387-c16` **OBJECT_MATCH**(9) | ✅ 채택 — 죽은 저장이 없어 c8 대신 이 꼴 |

- 결정: 07 변경은 c16 꼴(+ plan 383 주석). 후보 `s5p383-ic2` **OBJECT_MATCH**(9). 3 항의 c8 꼴은 대안 기록으로 남김.
- 진단 덤: machine_clock 에 같은 원리(복사 뒤 원 변수 죽이기) `s5p387-k1`–`k4` 는 효과 없음(원본 0x187b4e `mov eax, esi` 여전히 없음); codex 의 빈 asm 꼴 `b3` 은 `mov ecx,eax; mov [reload],cx` 로 다름.
- 결과: 07 `src/bsd/netinet/ip_output.c`(= scratchpad `ipv/cand383.c`, c16 꼴 + plan 383 주석; 이전 본 `ipv/ip_output.pre383.c`). `s5p383-it1` **OBJECT_MATCH**(9), relcheck 0; 실기 cc -M `s5p383-dep1` 48 헤더 모두 07(객체 = it1). record_object(nextmach 바탕 + 복원 수정, 멀티캐스트 넷은 authored D024) → objects_confirmed +1(앞 `00`×2·뒤 `00`×1, 원본 바이트 python 확인), functions +9(4727; 인용 18 개 모두 정의 줄, python), PROVENANCE +1, MODIFICATIONS +1, evidence `x86-ip_output.md/.diff`.
- 범위(python): 이번 4031 B. A 314 obj 620812 B (72.91%), P 69 obj 223153 B (26.21%), L 2 obj 340 B; A+P 99.12%, A+P+L 99.16%, rem 7131 B; 겹침 없음.

## 384. 진단 메모 — plan 383 뒤 남은 둘(swapfs_mount·machine_clock; 07 손대지 않음, 2026-10-07)

- 도구 주의: scratchpad `alf.sh`(→ `tcp/al.py`)는 `ebp−0x30/0x34/0xc/0x10` 칸을 `S` 로 정규화하므로 그 칸이 바뀐 차이를 못 보임(ip_output `c6` 의 3 B 차이가 alf 에 안 나옴). 일치 판정은 diag 도구의 L1 결과로만 함.
- machine_clock(`s5p387-k1`–`k4`): 복사 뒤 원 변수 죽이기(`i = count; count = 0; reload = i;` 등) 4 개 모두 기준과 같음(원본 0x187b4e `mov eax, esi` 없음). 인라인 setter 변형(`s5p387-j1`–`j6`): last_count·reload 를 한 인라인에서 쓰기(j1·j3·j5·j6)는 last_count 가 스택 임시가 되어 나빠짐, `unsigned int` 매개변수(j2)는 기준과 같음, ANSI 원형 `set_reload(timer_cnt_val_t)` 를 `last_count = count;` 뒤에서(j4)는 m45 와 같음(`mov ax,[last_count]` 대 원본 `mov eax,esi`).
- swapfs_mount 남은 7 명령(원본 0x13b36a–0x13b383) RTL 근거(`s5p378-sfpz1d` lreg·greg): 작업본은 두 page_size 읽기를 CSE 가 의사 48(REG_EQUIV `(mem page_size)`, 사용 2)로 합치고 global alloc 이 eax(0)를 줌; 이 함수의 spill 레지스터는 esi(4)·edx(1)(greg "Spilling reg 4/1"); rbuf·wbuf·cbuf(의사 29·30·31)는 스택. 원본은 두 덧셈이 모두 `add r,[page_size]` 이고 reload 레지스터가 ecx·edx — 해석(미확정): 원본에서는 의사 48 이 spill 레지스터에 놓였다가 밀려나 reload 가 REG_EQUIV 메모리를 두 사용처에 넣은 꼴, kalloc 결과는 별도 임시(ecx)를 거침. cse.c 원문 근거: 두 읽기를 합치지 않게 하는 조건(note_mem_written 7555–7592 의 가변 주소 비구조체 저장·BLKmode 저장, 호출)이 원본 명령열에는 없음; 0x1e0d0c 의 기호는 `_page_size` 하나(symbols.tsv).
- swapfs_mount 덧셈 꼴(`s5p388-q1`–`q5`: `rbuf + page_size + page_size`, `rbuf + 2 * page_size`, 연쇄, 지역 변수에 page_size 먼저, 피연산자 순서)은 효과 없음(656 B 그대로 또는 더 나쁨).
- codex 브레인스토밍(kv9e2s3s0, gpt-6.1-sol; 근거 아님) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| spill_hard_reg 는 밀어낸 의사를 global 재할당에 다시 넣음(reload1.c:3498) | reload1.c 3490–3502(sed): `reg_renumber[i] = -1; something_changed = 1; if (global)` | ✅ — 원본의 page_size 의사는 밀려난 뒤 재할당도 못 받았어야 함 |
| 하드 레지스터 없는 의사의 메모리 등가가 사용처에 들어감(reload1.c:852), 초기화 insn 삭제(:1917) | reload1.c 852–856·1916–1919(sed) | ✅ |
| local-alloc 이 바뀌지 않는 MEM 적재에 REG_EQUIV 를 붙임(local-alloc.c:1051) | local-alloc.c 1045–1055(sed) | ✅ |
| 값이 쓰이는 메모리 대입은 store_expr 가 레지스터로 복사(expr.c:2767) | expr.c 2760–2770(sed) | ✅(원문 맞음; ecx 가 된다는 근거는 아님 — codex 도 그렇게 씀) |
| 후보 1: `rp = &rbuf; wbuf = (*rp = kalloc(..)) + page_size;` | `s5p388-x1`: 664 B, rbuf 가 [ebp−4] 칸을 받아 스택 배치 전체가 밀림 | ❌ 원본 꼴 아님 |
| 후보 2: 출력 포인터 셋을 받는 보조 함수 | `s5p388-x2`: 656 B, 차이 더 많음 | ❌ |
| 후보 3: 지역 구조체 buffers | `s5p388-x3`: 652 B | ❌ |
- machine_clock m45 덤프(`s5p388-m45d`, `-dr -ds -dc -dl -dg`): rtl 의 인라인 매개변수 적재 insn 192 `(set (reg:HI 43) (subreg:HI (reg/v:SI 26) 0))` 를 CSE 가 `(mem:HI last_count)` 로 바꿈(cse 덤프). 근거(GCC 원문): i386 `MODES_TIEABLE_P` 는 같은 모드만 참(config_i386_i386.h:439), cse.c rtx_cost 는 묶을 수 없는 SUBREG 에 `COSTS_N_INSNS (2)`(cse.c 735–739) → 메모리가 더 쌈. 원본의 `mov eax, esi; mov [reload], ax` 는 그 값의 등가 부류에 HImode 레지스터가 있었다는 뜻(해석). mvm34(인라인 clock_timer_constant 가 timer_cnt_val_t 반환)는 그 꼴이지만 같은 HI 레지스터가 timer_write 의 last_count 읽기까지 대신해 스택 임시가 생김 — 원본은 timer_write 에서 last_count 를 두 번 메모리에서 읽으므로, reload 저장 뒤 timer_write 앞에서 그 HI 레지스터 등가가 끊겨야 함(미확정).
- machine_clock `s5p388-v1`(mvm34 꼴 + `volatile` last_count): 더 나쁨(last_count 가 스택 임시, 크기 달라짐).
- swapfs 메커니즘 진단(원본 꼴 아님): `-fcall-saved-cx`(`s5p388-fxdcx`)는 640 B 로 멀어짐; `-ffixed-ax`(`s5p388-fxdax`)는 실기 컴파일 실패(상태 1, 로그 없음) — eax 를 빼는 진단은 이 도구로 불가.
- machine_clock mvm34 꼴 + `do { } while (0)` 블록 경계(`s5p388-w1` timer_write 감쌈, `w2` reload 대입 감쌈, `w3` 둘 다): 모두 mvm34 와 같음(timer_write 인자 스택 임시). 근거: toplev.c 3129 의 jump_optimize 가 3167 cse_main 앞에서 돌아 코드 없는 레이블은 CSE 전에 사라짐(해석). mvm43·44 에서 레이블이 남은 것은 실제 점프(panic 갈래의 반환)가 있었기 때문.
- swapfs `s5p388-x4`(x1 + rbuf 를 min·max 뒤에 선언): x1 과 같음(664 B, rbuf 가 [ebp−4]). 해석: 주소를 잡는 지역은 처음 `&` 가 나올 때 칸을 받음(put_var_into_stack, 문장 단위 확장) — 원본 칸 순서(fname −4·fp −8·min −0xc·max −0x10·rbuf −0x14)에서 min·max(&는 kmem_suballoc 에서)가 rbuf 보다 앞이므로 원본 rbuf 는 주소 잡힌 변수가 아니라 spill 칸 → codex 후보 1 갈래 종료. 원본 꼴의 해석(미확정): kalloc 값이 먼저 임시 의사(T, ecx)에 들어가 rbuf(스택)에 저장되고, wbuf 는 T 가 죽는 자리에서 같은 reload 레지스터 ecx 로, cbuf 는 상속된 ecx 를 edx 로 옮겨 계산 — page_size 의사는 하드 레지스터 없이 메모리 등가로 대입됨.
- swapfs 호출 결과 임시 의사 가설: expr.c 의 CALL_EXPR 처리(5211–5222)는 preexpand_calls(8822) 로 미리 확장된 호출이면 그 결과를 돌려주고, 미리 확장할 때는 target 이 없어 calls.c 2238 `copy_to_reg (valreg)` 로 새 의사가 생깁니다. 원본의 `mov ecx, eax` 임시가 이 경로라는 해석으로, pz1 기준 연쇄 대입 `wbuf = (rbuf = kalloc(..)) + page_size`(`s5p388-y1`), 세 겹 연쇄(`y2`), 피연산자 순서를 바꾼 꼴(`y3`)을 시험했습니다. 세 개 모두 기준과 같았습니다(656 B, 차이 391). 정정: preexpand_calls 원문(expr.c 8822–8885)은 대입식(부류 'e')의 피연산자까지 내려가므로 y1 에서도 호출은 target 없이 미리 확장됩니다. 결과가 같은 것은 그 임시 의사가 뒤 단계에서 rbuf 와 합쳐지기 때문으로 보이며(해석, 덤프 미확인), 남은 차이를 정하는 것은 page_size 의사의 할당입니다. 덤프 확인(`s5p388-y1d`, `-dr -ds -dc -dl -dg`): rtl 에는 호출 결과 임시 의사 48 과 `29 = 48` 이 있으나 cse 덤프에서 `29 = 48` 이 사라지고 rbuf 사용이 48 로 바뀌어, 임시가 곧 rbuf(스택)가 됩니다. page_size 의사 49 는 두 사용으로 합쳐진 채 eax(greg dispositions `49 in 0`)를 받고, spill 레지스터는 esi·edx("Spilling reg 4/1")로 기준과 같습니다. 원본 꼴이 되려면 page_size 의사가 끝내 하드 레지스터를 받지 못해야 하는데, 이 함수에서 그렇게 만드는 소스 조건은 아직 찾지 못했습니다.
- swapfs 다른 해석과 최적화 수준 진단: local-alloc.c 1056–1081 원문을 보면, 합쳐지지 않은 page_size 읽기는 설정 1·사용 1 이면 combine 이 덧셈에 바로 접습니다(원문 주석 "this can't succeed or combine would have done it"). 따라서 원본은 "두 읽기를 CSE 가 합치지 않음"으로도 설명됩니다. 이를 최적화 수준으로 시험했으나 원인이 아니었습니다. `-O`(`s5p388-oo1`)는 대부분의 함수가 깨졌고, `-O2`(`oo2`)는 자동 인라인이 빠져 pageout 이 1344 B(원본 1616 B)가 되었으며, mount 는 둘 다 648 B 였습니다.
- machine_clock 추가: 인라인 clock_timer_constant 가 `return (last_count = count);`(`s5p388-n1`), 호출자 `reload = (last_count = clock_timer_constant());`(`n2`)는 mvm34 와 같았습니다(timer_write 인자가 스택 임시).
- codex 브레인스토밍(ks6kpn03c, gpt-6.1-sol; 근거 아님) 판정:

| codex 후보 | 내 검증 방법 | 결과 |
|---|---|---|
| 1. 인라인 안 last_count 저장만 `*(volatile timer_cnt_val_t *)&last_count = count;` | 빌드 `s5p388-cx1` | ❌ timer_write 는 원본처럼 메모리를 읽지만 reload 복사가 사라져 기준과 같은 1 B 차이(`mov [reload], si`) |
| 2. unsigned int 매개변수 setter | 앞서 시험한 m49·m50·j2 와 같은 꼴(§382·§384) | ⏭️ 새 시험 없음 — 기준과 같음 |
| 3. 매개변수에 `val &= TIMER_COUNT_MAX` | 빌드 `s5p388-cx3` | ❌ 기준과 같음 |
| 4. 두 저장을 한 unsigned int setter 에서 | j2(§384)와 같은 꼴 | ⏭️ 기준과 같음 |
| 5. union 으로 하위 반쪽 고르기 | 빌드 `s5p388-cx5` | ❌ 기준과 같음 |
- machine_clock cx1 덤프(`s5p388-cx1d`): reload 복사가 사라지는 곳은 combine 이 아니라 local-alloc update_equiv_regs 입니다. lreg 덤프에서 반환값 의사 31 의 설정 insn 184 에 `REG_EQUIV (mem:HI reload)` 가 붙고, greg 에서는 `(set (mem:HI reload) (subreg:HI (reg esi)))` 하나가 됩니다. 원문 조건(local-alloc.c 980–996): 저장 원천 의사가 한 기본 블록 안에서만 쓰이고(`reg_basic_block >= 0`), 설정 insn 이 하나이며(`reg_equiv_init_insn != 0`), validate_equiv_mem 이 성립해야 합니다. 원본은 `mov eax, esi` 복사가 남았으므로 이 조건 중 하나가 깨진 꼴로 해석됩니다. mvm43·44(반환 경로 둘)가 복사를 남긴 것도 설정 insn 이 둘이기 때문으로 보입니다(해석). 다만 그 꼴은 jmp·중복 코드를 남기므로, 코드를 늘리지 않고 이 조건을 깨는 소스 꼴은 아직 찾지 못했습니다.
- machine_clock 루프 변수 `i` 를 거치는 꼴(`s5p388-z1` `reload = i = count;`, `z2` `i = count;` 를 last_count 저장 앞에)은 둘 다 기준과 같았습니다(CSE 가 i 를 count 로 바꿔 씀).
- codex 브레인스토밍(k1dy5kkqh, gpt-6.1-sol; 근거 아님) 판정 — swapfs page_size 두 읽기:

| codex 주장·후보 | 내 검증 방법 | 결과 |
|---|---|---|
| cse 의 MEM 해시·동치는 모드·주소만 보며 RTX_UNCHANGING·MEM_IN_STRUCT 는 무효화 분류에만 쓰임 | cse.c 1942–1957(sed) | ✅ — 같은 모드·주소의 page_size 를 다른 MEM 으로 만드는 선언·매크로 꼴은 없음 |
| union 생성자는 초기화 전에 CLOBBER 를 냄(expr.c 3026–3029), cse 는 MEM CLOBBER 를 쓰기로 처리(cse.c 6256–6262) | 두 곳 sed | ✅ |
| 정적 `&&label` 초기화는 forced_labels 로 레이블을 남김(expr.c 4170–4172, jump.c 234–235) | 두 곳 sed | ✅ |
| 후보 2: 정적 `&&label` 로 블록 경계(진단 전용 — 원본에 없는 정적 데이터를 더함) | 빌드 `s5p388-lb`: 672 B. 두 덧셈이 `add edx,[page_size]`·`add esi,[page_size]` 메모리 피연산자가 됨. 다만 레이블 자리에서 대기 스택 정리 `add esp,4` 가 나옴 | ⚖️ 메커니즘 확인(읽기를 나누면 메모리 피연산자), 원본 꼴 아님 |
| 후보 1: cbuf 를 BLKmode union 초기화로 | 빌드 `s5p388-un2`(첫 `un` 은 제 변환 실수로 컴파일 실패, 같은 ID 재빌드는 이전 결과가 남아 새 ID 사용): 676 B. 스택 정리 없이 두 덧셈이 메모리 피연산자가 되지만 union 칸·복사 명령이 늘고 프레임이 바뀜 | ⚖️ 메커니즘 확인(코드 없는 메모리 무효화가 있으면 원본 방향), 원본 꼴 아님 |

- 정리: 원본의 7 명령은 "두 page_size 읽기 사이에 코드를 남기지 않는 메모리 무효화(또는 블록 경계)" 가 있었다는 해석과 맞습니다. 이를 만드는 원본 소스 꼴은 아직 찾지 못했습니다.

### 383.1 기록 점검 — ip_output 의 비활성 원문 복원과 hunk 표시(코딩 전, 2026-10-07)

0. 점검 결과: 기록본(07 SHA 8fe86788…, NeXTMach 대비 diff 11 hunk) 중 6 hunk 에 plan 표시가 없습니다. 그중 셋은 plan 175(2026-10-03)가 NeXTMach 의 `#if NeXT` 블록 셋(참조 69–73 선언, 186–190 if_output_mbuf, 208–328 단편화)에서 `#if/#else/#endif` 와 `#else NeXT` 쪽 비활성 코드(mbuf 단편화 경로 약 60 줄)를 지운 것입니다. NeXT 가 정의되어 있어 바이트에는 영향이 없으므로 원본 바이트가 요구한 수정이 아니며, 2026-10-04 사용자 지시("비활성 코드를 정리하지 말 것", 메모리 no-feature-additions)에 맞지 않습니다. plan 175 는 그 지시보다 먼저 쓰였습니다.
1. 변경(주석·전처리 줄만, 후보 scratchpad `ipv/cand383_1.c`):
   - 참조 69–73: `nb`·`map`·`mhlen` 선언을 `#if\tNeXT` … `#endif\tNeXT` 로 다시 감쌉니다.
   - 참조 186–190: `if_output_mbuf` 줄을 참조 원문(`#if NeXT` / `#else NeXT` 의 `(*ifp->if_output)` / `#endif NeXT`)으로 되돌립니다.
   - 참조 208: 단편화 앞 `#if\tNeXT\t` 줄을 되살리고, 그 아래 iph 설명 주석에 plan 175 표시를 답니다.
   - 참조 264–328: 루프 뒤 `m_freem(m0);` 다음에 `#else NeXT` 쪽 원문과 `#endif NeXT` 를 그대로 넣습니다.
   - 표시 없는 나머지 hunk 에 plan 175 표시 주석(ROUTETOIF 블록·소스 주소 블록의 `ia` 함수 범위, 멀티캐스트 블록 0x12742c–0x127534, `sendit:`, 첫 조각 `iph = *ip;`)을 답니다.
2. 결과 예측과 진단: 참조 대비 diff 10 hunk 모두 plan 표시 있음(python 전수 검사), 지운 줄 21(python). 진단 `s5p383-ic3` **OBJECT_MATCH**(9), `__text` 4031 B·`__data` 10 B 의 SHA 와 재배치 수 87 이 기록본 `s5p383-it1` 과 같음(python).
3. 이어서: 07 반영 → iter_k07 → relcheck → 실기 cc -M(모든 헤더 07) → 기록 갱신(PROVENANCE 의 파일 SHA, MODIFICATIONS 행 문구에 비활성 원문 유지와 plan 383.1, evidence `.md` 의 SHA·run, `.diff` 재생성, functions.tsv 의 07 줄번호 인용 9 행 갱신과 정의 줄 검사). objects_confirmed 의 build 칸 run 이름도 확인합니다.
4. 같은 점검에서 본 것(이번 범위 밖, 사용자 판단 대상): 이미 기록된 tcp_input(참조 `#else` 3 → 07 1)·tcp_output(1 → 0)·netisr(1 → 0)·if_ether(42 → 41)도 참조보다 `#else` 가 적습니다. 원본 바이트가 요구한 것인지(빌드에 필요한 삭제였는지)는 아직 확인하지 않았습니다.
5. codex 교차검토(kmowxtxjg, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 되살린 블록이 참조 69–73·186–190·208·264–328 과 바이트 단위로 같고(`#if\tNeXT\t` 포함) 짝이 맞음 | python: 참조 블록 셋의 바이트열이 후보에 정확히 1 번씩 있음, `#if\tNeXT\t` 줄 1 개, 조건부 지시문 짝 검사 통과 | ✅ |
| NeXT 쪽 `m_freem(m0);` 는 `#else` 앞, `done:` 은 `#endif` 뒤(후보 373·374·438·439) | python 으로 후보 374·438·439 행 출력 | ✅ |
| 07 대비 바뀐 것은 주석·전처리 줄·비활성 갈래뿐 | 07→후보 diff 의 더한 줄 80 중 71 이 참조 원문, 나머지 9 는 표시 주석·`#if\tNeXT\t`·표시 붙은 두 줄; 지운 줄 4 는 표시 주석으로 바뀐 줄(python 분류) | ✅ |
| 10 hunk 모두 plan 표시, 멀티캐스트 범위는 plan 175 3 항과 같음 | python 전수 검사(표시 없음 0); RECONSTRUCTION_PLAN-100-199.md:2216(grep) | ✅ |
| functions.tsv 9 행의 검증 JSON 경로(`s5p383-it1`)도 갱신 필요, 후보 정의 줄은 62·454·494·527·600·708·943·994·1012 | python: functions.tsv 4719–4727 행의 run 이름 집합 {s5p383-it1}; 후보 정의 줄 계산 결과 같음 | ✅ 채택 — 3 항 기록 갱신에 포함 |
- 결과: 07 `src/bsd/netinet/ip_output.c` = scratchpad `ipv/cand383_1.c`(이전 본 `ipv/ip_output.pre383_1.c`), 파일 SHA-256 6d81e9770dacaa4c7ca82439d925650b478fb59acb51a43c6ada7d0ab46b4172. iter_k07 `s5p383-it2` **OBJECT_MATCH**(9), relcheck 0; 실기 cc -M `s5p383-dep2` 48 헤더 모두 07, 목적 파일 = it2(SHA 같음). 기록 갱신: PROVENANCE(파일 SHA), MODIFICATIONS(비활성 원문 유지 문구, plan 383.1), functions.tsv 9 행(07 정의 줄 62·454·494·527·600·708·943·994·1012, 검증 JSON `s5p383-it2`), objects_confirmed(build 칸 dep2·it2), evidence `.md`(SHA·run·경위)와 `.diff` 재생성. 갱신 뒤 python 검사: 인용 18 개 모두 정의 줄, 검증 JSON 9 개 존재, diff 10 hunk 모두 plan 표시, 표 행 수 변화 없음(PROVENANCE 1026·functions 4728·objects_confirmed 316·MODIFICATIONS 497).
- 4 항 확인 결과(사용자 판단 대상 아님): netisr(plan 154)·tcp_output(plan 174, `#if DEBUG`·`#if BSD>=43`)·if_ether(표시 있는 hunk)의 조건부 삭제는 모두 표시된 작성·복원 수정 안에 있습니다. tcp_input 은 바탕이 Net/2(plan 368, PROVENANCE `net2+nextmach`)라 NeXTMach 와 `#else` 수를 비교한 것이 맞지 않았습니다.
- 같은 점검을 이번 세션에 기록한 다른 파일에도 했습니다(python, 참조 대비 diff hunk 의 plan 표시). `nextdev_private/bsd/net/tokensr.h`(Darwin 대비 10 hunk)·`FBConsPriv.h`(1 hunk)는 모두 표시가 있습니다. `src/bsd/dev/i386/FBConsole.c` 는 Darwin 대비 13 hunk 중 6 개의 hunk 안에 표시가 없지만, 모두 같은 함수·블록의 표시 주석이 설명합니다. 15·24 비트 색 값은 1015 행 `plan 341: 4.2 colour values for 8, 15 and 24 bit` 가, DrawRect 의 화면 주소 계산·루프 변수와 EraseRect 본문은 DrawRect 앞 1175–1182 행 블록 주석(plan 341·379, 본문을 원본 바이트로 작성)이 설명합니다. Darwin 의 Description·Preconditions 주석을 뺀 것도 그 주석에 적혀 있으며, 지워진 비활성 원문은 없습니다. 그래서 07 은 바꾸지 않았습니다. `if_vtrip.c` 는 전부 작성한 파일이라 참조 대비 검사 대상이 아닙니다.
- swapfs(이어서): cse.c 8054–8072 원문상 loop.c 전의 CSE 는 기본 블록을 CODE_LABEL 외에 `NOTE_INSN_LOOP_END` 에서도 끊습니다. 그러나 두 page_size 읽기 사이에서 루프가 끝나는 꼴은 원본이 될 수 없다고 판단합니다. stmt.c 의 expand_loop_continue_here(2202)·expand_end_loop(2250 근처)가 대기 스택 정리를 내보내는데, 원본은 kalloc 인자 4 B 정리를 0xcb 의 `add esp,0x24` 에 합치고 있어 그 사이에 `add esp` 가 없습니다(레이블도 expand_label 643 에서 같은 이유로 제외). 확인 빌드 `s5p388-le1`(kalloc 과 wbuf 계산을 `do { } while (0)` 로 감쌈): 루프 끝 뒤의 두 번째 덧셈은 `add esi,[page_size]` 메모리 피연산자가 되었지만 0x92 에 `add esp,4` 가 나오고 684 B 가 되어 판단과 같았습니다.
- swapfs 원본 7 명령의 할당 해석(덤프·원본 대조, 미확정): kalloc 결과 임시 의사 T 가 global alloc 에서 ecx 를 받고, rbuf 는 T 와 다른 스택 의사입니다(`mov [ebp−0x14], ecx` 는 `rbuf = T`). wbuf 는 T 가 죽는 자리라 reload 가 ecx 를 그대로 출력 레지스터로 쓰고, cbuf 는 상속된 ecx 값을 spill 레지스터 edx 로 옮겨 계산합니다. 이 해석은 함수의 spill 레지스터 {esi, edx}(작업본 greg)와 모순되지 않습니다. y1 에서는 CSE 가 rbuf 사용을 T 로 바꿔 써서 둘이 합쳐졌으므로, 남은 조건은 "rbuf 가 T 와 합쳐지지 않고 page_size 의사가 레지스터를 받지 않는 꼴"입니다. 진단 `s5p388-y5`(y1 + `volatile` rbuf): rbuf 가 선언 때 [ebp−4] 칸을 받아 스택 배치가 밀렸습니다(672 B).
- swapfs 원본 점프 확인(python, capstone): 원본 swapfs_mount 의 점프는 0x10·0x17·0x30·0x48·0x58·0x65 의 여섯이고 뒤로 가는 점프는 없습니다. 대상 레이블은 0x1c·0x6c·0x28a 뿐이라 0x6c 뒤로는 끝까지 레이블이 없습니다. 그래서 CSE 경계로 남은 후보는 루프 끝 메모이며, 그 정리가 원본 0xcb `add esp,0x24` 와 겹치도록 "첫 루프가 0xcb 에서 끝나고 바로 pz1 의 둘째 루프가 시작"하는 꼴을 시험했습니다. `s5p388-t1`(rbuf 부터 swapfs_bit_map 까지 감쌈), `t2`(VN_HOLD 부터), `t3`(t1 + 연쇄 대입) 모두 680 B 였습니다. t3 은 두 번째 page_size 읽기가 메모리 피연산자가 되었지만, 첫 루프의 가중으로 rbuf 가 edi 를 받고 vp 가 [ebp−0x14] 로 밀렸으며 프레임이 4 B 커졌습니다(`sub esp,0x28`).
- D055(2026-10-07, 사용자 결정) 참고 원문 확보: 4.3BSD-Net/2·4.4BSD-Lite 의 `sys/vm` `swap_pager.c/.h`·`vm_swap.c`·`vnode_pager.c/.h` 를 TUHS 에서 받아 `01_resources/upstream/net2/sys/vm/`·`upstream/bsd44lite/sys/vm/` 에 두었습니다(Lite 는 배포처 cksum 5/5 일치, 매니페스트 `net2-vm-swap.json`·`bsd44lite-vm-swap.json`). 비교 결과: BSD 스왑은 스왑 장치 블록 지도(`rmalloc(swapmap, …)`)와 vm_pager 구조(`malloc(…, M_VMPAGER, …)`)를 쓰고, 4.4BSD-Lite swapon 은 블록 장치만 받습니다(`v_type != VBLK` → `ENOTBLK`, vm_swap.c). swapfs_mount 의 꼴(정규 파일 vnode·`ENOTDIR`, kalloc 버퍼 셋, `kmem_suballoc` 지도 둘, vfs_data)과 같은 원문이나 관용구는 없습니다. 남은 7 명령의 소스 꼴을 정하는 근거로는 쓸 수 없다고 판단합니다. 이 판단은 grep 결과와 두 swapon 원문을 직접 읽어 확인했습니다.
- swapfs 조합 탐색(2026-10-07, 사용자 선택 "1 탐색 계속"; scratchpad `swapfs/sw389/gen.py`·`run.sh`·`log`, run `s5p389-a?b?c?`): 할당식 꼴 6(a0 기본·a1 연쇄 대입·a2 임시 buf·a3 `buf +=`·a4 wbuf 연쇄·a5 피연산자 순서) × 루프 구조 3(b0 pz1·b1 첫 루프 rbuf 부터·b2 첫 루프 VN_HOLD 부터) × 선언 위치 2(c0 기존·c1 nmap 뒤) = 36 개(a0b0c0 = pz1 확인 뒤 35 개 빌드). 빌드 35 개 모두 상태 0, mount 크기·차이 바이트(python 집계): 656 B·391 이 9 개, 660 B·400 이 2 개, 676 B·396 이 4 개, 680 B·417 이 20 개. OBJECT_MATCH 는 없었습니다. a3b0c0·a3b0c1 은 크기만 660 B 로 원본과 같고, buf 가 스택으로 가고 vp 가 [ebp−0x14] 로 밀리는 등 배정은 기준보다 멉니다. 선언 위치(c)는 결과에 영향이 없었습니다.

## 385. 진단 메모 — 일치 객체를 증거로 쓰는 관용구 탐색과 machine_clock 의 RTL 추적(07 손대지 않음, 2026-10-07 밤)

- 방법 전환(사용자 질문 "남은 문제를 어떻게 추적해야 할까요?"): 소스 꼴 추측 대신, 이미 바이트가 맞은 객체에서 같은 명령 꼴을 찾아 그 07 소스로 "이 컴파일러에서 그 꼴을 내는 C 형태"를 확인합니다(scratchpad `idiom390.py`·`idiom390b.py`, 함수 경계마다 capstone 역어셈블, 기본 블록 단위).
  - swapfs 꼴(같은 전역을 한 블록에서 두 번 읽음, 둘 다 덧셈에 접힘): 일치 객체 안에는 없습니다. qsort(A) 의 1 건은 루프 경계를 사이에 둔 읽기라 다른 경우입니다. 넓힌 검색(같은 전역 두 번 읽기 29 건)은 모두 첫 읽기 레지스터가 그 사이에 망가진 경우(cse 가 합칠 수 없음)라 증거가 아닙니다.
  - machine_clock 꼴(32 비트 레지스터 복사 직후 16 비트 저장): 일치 객체에 4 건 — rewhence(kern_descrip, `switch (ld->l_whence = newwhence)`), tcp_input, unix_syscall(trap), initDmaLock(IOSVGADisplay). 네 건 모두 복사 레지스터가 저장 뒤에도 쓰입니다(cmp/add). 원본 machine_clock 은 저장 뒤 eax 를 쓰지 않으므로, "cse 뒤에 죽은 두 번째 쓰임" 가설로 이어졌습니다.
- machine_clock 변형(scratchpad `mcv/`, run `s5p390-*`): n3(`reload = count; timer_write(..., count)`)·n6(SI 사본 c)·n13·n4·n5(SI 반환 인라인의 반환값을 두 곳에)·cx·k·j 류는 기준과 같았습니다(SI 사본은 cse 가 count 로 되돌려 복사가 사라짐). n7(HI 사본 c 를 reload·timer_write 양쪽에)·q4(인라인이 `return (last_count)`)는 timer_write 는 원본과 같고 복사 출처만 `mov ax,[last_count]`(원본 `mov eax, esi`). n11·q2·q10·q7 은 m34 와 같거나 더 나빴습니다(앞단이 `& 0xffff`·`+ 0` 을 접음).
- RTL 추적(덤프 `s5p365-mvd5`(m34)·`s5p390-n7d`·`q4d`, GCC 원문):
  - `mov eax, esi` 는 HImode 레지스터 간 복사입니다. i386.md movhi 템플릿은 두 피연산자가 레지스터면 `movl %k1,%k0` 을 냅니다.
  - m34 의 복사: 인라인 반환값이 `39 = zero_extend:SI(subreg:HI count)` 와 `(subreg:SI (reg:HI 31)) = 39` 두 insn 으로 나옵니다. 앞단이 반환형 unsigned short 를 unsigned int 로 승격했고(zero_extend), integrate.c 1642–1662 가 arriving_mode(SI) ≠ departing_mode(HI) 라 대상을 `(subreg:SI (reg:HI 31))` 로 만듭니다. PROMOTE_FUNCTION_RETURN 은 i386/next 설정에 없습니다.
  - m34 가 timer_write 를 그르치는 이유: cse.c 7401–7450 의 "넓은 SUBREG 대상 기록" 규칙이 reg 31 을 `lowpart(39 의 부류)` = `(subreg:HI count)` = `(mem:HI last_count)` 부류에 넣고, 그래서 timer_write 의 `last_count` 적재가 reg 31 로 치환되어 바이트 읽기가 스택 임시가 됩니다. cse.c 7340–7352 는 원천이 ZERO_EXTEND/SIGN_EXTEND 이면 대상을 기록하지 않지만, m34 의 원천은 reg 39 라 적용되지 않습니다.
  - n7·q4 가 복사 출처를 메모리로 만드는 이유: `(set X (subreg:HI count))` 의 원천을 cse 가 더 싼 `(mem:HI last_count)` 로 바꾸고(비묶음 SUBREG 비용 cse.c 735–739), 그 X 는 REG_EQUIV 메모리를 받아 하드 레지스터 없이 남아 reload 가 `mov ax,[last_count]` 와 바이트 메모리 읽기를 냅니다.
  - 따라서 원본은 "`(set (subreg:SI X) (zero_extend:SI (subreg:HI count)))` 한 insn" 꼴로 해석됩니다. 그러면 7340–7352 규칙으로 X 가 last_count 부류에 들어가지 않아 timer_write 는 메모리를 읽고, combine 은 SUBREG 대상 insn 을 흡수하지 않아 복사가 남으며, 하위 16 비트만 쓰이므로 `mov eax, esi` 가 됩니다(해석). 이 한 insn 꼴이 어떤 C 소스에서 나오는지는 아직 찾지 못했습니다. stmt.c expand_return 은 `cleanups = 1`(#if 0 로 고정)이며 반환값을 먼저 의사 레지스터에 계산하는 경로가 보이는데, 최종 분기 조건(expand_return 뒷부분)은 아직 읽지 않았습니다.
- 사용자 지시(2026-10-07 밤): 이 작업까지 끝내고 잠시 대기. codex 모델은 이 작업의 분석·교차검토에 한해 `gpt-6-astra` 도 허용(메모리 기록).

## 386. 진단 메모 — machine_clock clock_timer_init: 원본 바이트를 내는 구조를 찾음, 남은 것은 레지스터 순서(07 손대지 않음, 2026-10-08)

0. 방법: 소스 꼴 추측 대신 RTL 단계별 덤프(`-dr -ds -dc -dl -dg -df`)와 GCC 원문(실기 cc 의 원문과 해시 일치 확인: i386.c·local-alloc.c·cse.c)으로 거꾸로 추적했습니다. 모든 run 은 `s5p390-*`·`s5p391-*`(scratchpad `mcv/`).
1. 사실(덤프·원문):
   - `mov eax, esi` 는 HImode 레지스터 간 복사입니다(i386.md movhi 는 레지스터 둘이면 `movl %k1,%k0`).
   - X 가 HI REG 여야 reload 저장이 레지스터에서 옵니다. SI 반환(m36)이면 저장 원천 `(subreg:HI X)`(비용 16)를 cse 가 메모리(비용 4)로 바꿔 `mov [reload], si` 가 됩니다(`s5p391-m36d` cse 덤프 insn 191).
   - HI 반환 인라인(m34)은 X 를 `(set (subreg:SI X) 39)`, `39 = zero_extend(subreg:HI count)` 두 insn 으로 만들고, cse.c 7401–7450 의 넓은 SUBREG 대상 기록 규칙이 X 를 `last_count` 메모리 부류에 넣습니다(gen_lowpart_common 이 zero_extend 의 피연산자를 돌려줌 — 실기 emit-rtl.c 567– 확인). 그래서 timer_write 의 `last_count` 적재가 X 로 치환되어 바이트 읽기가 스택 임시가 됩니다.
   - 복사가 combine 에 흡수되지 않는 조건은 "X 의 쓰임 둘 또는 설정 둘"입니다(w4f: 블록 경계로 치환만 막으면 쓰임이 하나가 되어 흡수됨; d1: 죽은 두 번째 대입은 delete_dead_from_cse 가 지워 역시 흡수).
   - 두 꼬리 구조(반환 둘)에서 mvm43 이 실패한 원인은 panic 호출의 인자 정리 `add esp,4` 가 return 까지 미뤄져 꼬리가 달라진 것입니다. 저장을 인라인 helper 호출로 하면 integrate.c 의 `do_pending_stack_adjust` 가 호출 직후 정리를 내보내 꼬리가 같아지고 최종 jump pass 의 cross-jump 가 합칩니다(e1·e3: 남은 차이는 복사 레지스터 ecx).
   - e1 의 X 는 전역(두 설정)이라 reload 의 eax spill(udivmodsi4 의 AREG 수요, `-dg` "Spilling reg 0")에 밀려났습니다. reload1.c 3480–3495: 블록 지역 pseudo 는 그 블록에 수요가 없으면 밀려나지 않습니다. 호출점을 둘로 나누어 꼬리마다 다른 pseudo 를 두면(g1: `if (count > 0xffff) { panic(...); reload = set_counts(count); } else reload = set_counts(count);`, set_counts 는 `last_count = count; return (count);` 인라인) X 가 꼬리 블록 지역이 되어 밀려나지 않습니다. **g1 은 복사 레지스터(edx, 원본 eax) 하나만 다릅니다.**
   - `-mreg-alloc=adcbSDB`(eax 우선, 진단 전용)로 g1 을 빌드하면 clock_timer_init 의 바이트가 원본과 같습니다(`s5p391-g1a`, alf 차이 재배치 자리뿐). 그러나 같은 옵션은 set_timer 를 바꾸므로(원본 set_timer 는 기본 순서) 빌드 옵션은 아닙니다.
   - edx 가 먼저인 이유: i386.c order_regs_for_local_alloc 은 함수 안에 SET_SRC 가 DImode 인 insn 이 있으면 순서를 edx·ecx·eax 로 바꿉니다(use_dca). clock_timer_init 에는 `time_of_boot` 의 DI 저장과 `__udivdi3` 인자·결과가 있어 원본에서도 참이었을 것입니다.
2. 남은 문제(한 가지): 꼬리 블록 지역 X 에 local-alloc 이 edx 대신 eax 를 주려면, X 의 생존 구간(복사→저장 2 insn)에 edx 와 ecx 가 살아 있거나(find_free_reg 의 regs_live_at), X 가 local-alloc 대상에서 빠져 global 이 할당해야 합니다(local_alloc 조건: `reg_basic_block >= 0 && reg_n_deaths == 1 && (alternate == NO_REGS || !CLASS_LIKELY_SPILLED_P(pref))`). g1·g5(조건 반전)·g3(timer_write 중복)·g6(HI 매개변수)은 모두 edx 또는 더 나쁨. 꼬리 블록 시작의 live 레지스터는 ebp·esp·s·count 뿐(flow 덤프)이라 현재 꼴에서는 edx 가 비어 있습니다. 어떤 자연스러운 C 구문이 그 조건을 만드는지는 아직 찾지 못했습니다.
3. 판단: 소스 구조는 거의 확정(두 호출점 + 인라인 helper, 혹은 그와 같은 RTL 을 내는 꼴)이고, 마지막 1 바이트는 local-alloc 의 레지스터 선택입니다. 다음은 그 선택을 바꾸는 자연스러운 구문 탐색입니다.
4. codex 브레인스토밍(k3vl6061t, gpt-6-astra; 근거 아님) 판정:

| codex 주장·후보 | 내 검증 방법 | 결과 |
|---|---|---|
| global.c 도 같은 reg_alloc_order 를 쓰므로 X 를 global 로 보내는 것만으로는 부족 | global.c find_reg 원문(`regno = reg_alloc_order[i]`, 앞서 읽음) | ✅ |
| 인라인 반환값은 eax 정체성을 잃음(integrate.c 1652·1666), REG_EQUIV(reload) 는 메모리 등가일 뿐 | integrate.c 1666–1667·1713–1717·2184–2196(앞서 읽음) | ✅ |
| 1 안: 두 꼬리에 각각 `x = set_counts(count); reload = x; timer_write(TIMER_CNT0_SEL, x);` | 빌드 `s5p391-cv1`: T = X 가 되어 바이트 읽기가 스택 임시, 꼬리도 합쳐지지 않음(jmp·중복) | ❌ |
| 2·3 안: 함수 범위 `x` 를 두 꼬리에서 설정하고 timer_write 에 넘김 | 1 안과 같은 T = X 구조(m34·n11·cv1 에서 모두 실패) | ❌(빌드 생략) |
| 더미 사용으로 edx·ecx 를 묶어 둘 수 없음(최적화·할당을 지나 남지 않음) | d1·k1–k4 결과와 일치 | ✅ |

5. 현재 결론: 원본 바이트를 내는 소스 구조(두 호출점 + `last_count` 저장·반환 인라인 helper, 꼬리 cross-jump)는 찾았고, 남은 1 바이트는 local-alloc 이 꼬리 블록의 HI pseudo 에 edx(DI 함수 순서) 대신 eax 를 준 이유입니다. 바이트 순서상 포트 적재가 reload 저장 뒤라 ecx 를 X 와 겹치게 할 지역 pseudo 는 보이지 않고, 자연스러운 C 구문으로 그 조건을 만드는 방법은 아직 없습니다. 사용자 판단 대상으로 보고합니다.

## 387. 계획 — 잔여 둘의 다음 탐색(codex 영어 질의 kgmj50qsl·k6t2bclxs 취합; 코딩 전, 2026-10-08)

0. 취합(모두 원문으로 확인한 사실만 적습니다):
   - machine_clock: 인라인 인자는 왼쪽부터 평가되나 수정되지 않는 매개변수의 MEM 인자는 모든 인자 평가 뒤 복사됩니다(integrate.c 1259–1304, 1480–1494; 수정되는 매개변수는 1306–1327 에서 즉시 복사). 포트 적재는 바이트상 reload 저장 뒤라 ecx 점유를 설명할 수 없습니다. sched 패스 없음(toplev.c 547–548, i386 설정에 OPTIMIZATION_OPTIONS 없음). 새 저비용 후보는 `timer_write(TIMER_CNT0_SEL, reload = set_counts(count))`(X 가 AREG 선호를 얻어 local-alloc 에서 제외되면 global 이 eax; local-alloc.c 472–477, config_i386_i386.h 744–751) 하나이며, T = X 가 되어 바이트 읽기가 레지스터가 될 위험이 큽니다.
   - swapfs: cse2 는 LOOP_END 를 무시하므로 do-while 경계는 되돌려집니다(cse.c 8067–8072). 원본의 `add r,[page_size]` 둘은 "합쳐진 pseudo 가 하드 레지스터를 못 받아 reload 가 메모리로 치환"(reload1.c 852–859·1910–1928·1958–1987)으로도 설명됩니다. y1 덤프: kalloc 임시 T 가 cse 의 정규형 규칙(cse.c 840–862)으로 rbuf 사용 전부를 흡수해 T 가 곧 rbuf(호출 6 개 교차)가 됩니다. 원본은 T(ecx) 가 짧게 살고 rbuf 는 메모리이므로, rbuf·wbuf·cbuf 는 pseudo 가 아닌 메모리 변수(집합체 또는 주소를 잡은 변수)로 해석됩니다. expand_decl(stmt.c)은 주소를 잡거나 BLKmode 인 지역을 선언 시점에 선언 순서대로 스택에 두므로, fname·fp·min·max(−4…−0x10) 뒤에 선언된 집합체가 −0x14 부터 받습니다. pz1·y1 의 spill 레지스터는 esi·edx 뿐이라, T 가 ecx 가 되려면 원본에서는 eax 도 spill 되었어야 합니다(진단 대상).
1. swapfs 변형(pz1 바탕, min·max 뒤에 선언, kalloc 임시 `buf`):
   - h1: `struct { vm_offset_t cbuf, wbuf, rbuf; } b;` + `buf = kalloc(page_size * 3); b.rbuf = buf; b.wbuf = buf + page_size; b.cbuf = b.wbuf + page_size;`
   - h2: h1 의 대입을 체인 `b.wbuf = (b.rbuf = kalloc(page_size * 3)) + page_size;` 로
   - h3: `vm_offset_t buf[3];`(rbuf = buf[2], wbuf = buf[1], cbuf = buf[0]) — 진단용
   확인: mount 크기·차이, 0x7e–0x94 명령열, `-dl -dg` 로 T 의 레지스터와 spill 레지스터.
2. machine_clock 변형(g1 바탕): c1: 두 갈래 모두 `timer_write(TIMER_CNT0_SEL, reload = set_counts(count));`.
3. 결과에 따라 다음을 정합니다. 어느 쪽도 맞지 않으면 사용자 보고.
4. 결과(2026-10-08): 커널 진단 빌드 h1·h2·h3(집합체 버퍼)은 652 B 로 pz1 보다 멀고, c1 은 T = X 라 더 나쁨. 집합체는 선언 시점에 첫 칸([ebp−4…])을 받아(GCC 2.7 C 는 문장 단위 전개; 주소를 잡는 스칼라는 `&` 가 처음 나올 때 칸을 받음) 원본 칸 순서와 맞지 않습니다.
5. **탐침 환경**(08_build/runs/tools/probe, git 무시; `run.sh`: 독립 C 파일을 실기 cc-744.13 으로 `-O3 -fno-omit-frame-pointer -traditional-cpp -S`, `runk.sh`: 커널 헤더 스테이징(s5p388-y1)으로 커널 소스 파일을 `-S`). 축약 탐침 p1(swapfs 꼴)·p2(machine_clock 꼴)는 커널 빌드의 해당 구간을 그대로 재현했습니다(p1 = pz1 꼴, p2 = g1 꼴). 건당 수 초.
   - p2a(DImode 연산 제거): 꼬리가 원본과 **정확히 같음**(`movl %esi,%eax; movw %ax,_reload`). p2b(time_of_boot 만 DI)·p2c(res 루프만 DI): 둘 다 edx. → 순서 가설 확정. 원본 함수에는 DI 가 있으므로 "edx·ecx 점유" 조건이 남습니다. q2(지역 사본)·q3·q4(포트를 미리 지역에) 는 edx 그대로이거나 asm 레지스터가 바뀜.
   - swapfs 탐침: v01(임시 buf)·v02(volatile)·v04(char * 반환)·v05(체인)·v08(구조체)·v14(+=)·v16(char * 버퍼) 모두 pz1 꼴 또는 더 멂. 강제 레이블(l0·l1·l5, 진단) 도 변화 없음 → "버퍼 계산 뒤 블록 경계" 가설 기각. **d1–d4(64 비트 복사 한 줄 추가 → edx 우선 순서)**: `movl %eax,-rbuf; movl _page_size,%edx; movl %eax,%ecx; addl %edx,%ecx; …` 로 원본 쪽(ecx·edx)으로 이동하지만 rbuf 저장 원천과 page_size 레지스터는 아직 다릅니다. 원본 swapfs_mount 바이트에 64 비트 쌍 저장·적재는 없습니다(python 검사).
6. 결과(2026-10-08, 전체 커널 문맥 탐침 `runk.sh` sw0–sw5; 덤프 `-dr -dl -dg`; gcc 소스 10 파일은 실기 `/NextDeveloper/Source/GNU/gcc` 와 BSD `sum` 일치 확인 — i386.md·i386.h·reload1.c·reload.c·caller-save.c·expr.c·calls.c·optabs.c·local-alloc.c·global.c):
   - 원본 0x7e–0x94 를 내는 RTL·할당은 다음으로 설명됩니다. (a) `-O2` 이상은 `-fforce-mem`(toplev.c 3718–3726) 이라 `page_size` 가 pseudo 로 적재되고(expand_binop, optabs.c 371–374), REG_EQUIV 메모리 등가를 받습니다(local-alloc.c 1049–1054); 하드 레지스터를 못 받으면 reload 가 `[page_size]` 로 치환합니다. (b) rbuf·wbuf·cbuf(pseudo 29·30·31)는 호출을 건너 살아 spill 되며 칸 −0x14·−0x18·−0x1c 는 우리 출력과 **같은 칸**입니다(sw0: −20·−24·−28; sn 의 caller-save 칸 −32 도 원본 −0x20 과 같음). 뒤쪽 읽기도 원본·우리 모두 같은 칸(원본 0x165·0x180·0x198). 따라서 메모리 변수(집합체·주소 취득) 가설은 기각(§387.4 와 일치). (c) 남은 차이는 두 가지뿐: 원본은 kalloc 값 복사 임시 T 가 **ecx**(우리는 eax 로 묶임), 합쳐진 page_size pseudo 가 **할당되지 않음**(우리는 eax/edx). 두 add 의 reload 는 inherit(`mov edx,ecx`)·in/out 규칙으로 원본과 같은 꼴이 됩니다.
   - T 가 생기는 경로 확인: expand_assignment 의 "call-first" 경로(expr.c 2587–2598: 좌변이 REG 인 VAR_DECL 이 아닐 때 `expand_expr(from, NULL)` 뒤 복사), expand_call 은 target 이 없을 때 `copy_to_reg(valreg)`(calls.c 2238; target 이 있으면 2157–2163 직접 이동), preexpand_calls(이항식 안의 호출). 단순 출력 reload 는 선택 reload 를 만들지 않으므로(reload.c 3527–3545 "Optional output reloads don't do anything") `mov ecx,eax; mov [-0x14],ecx` 는 반드시 실제 pseudo T 입니다.
   - 탐침: sw2·sw3(인라인 helper 로 `&rbuf` — put_var_into_stack fixup, RTL 243–258)·sw4(배열 `buf[3]`, call-first 경로 확인: RTL 113 `(set 45 eax)`·115 저장)·sw5(중첩 대입 체인) 모두 T = eax, page_size = 레지스터. 즉 T 를 만드는 구문은 여럿이지만 **eax 를 피하게 하는 조건**(T 수명 [113,121] 동안 eax 가 살아 있거나 설정됨)과 page_size pseudo 가 레지스터를 못 받는 조건은 아직 자연스러운 C 로 만들지 못했습니다. DI 순서는 원본에 64 비트 쌍이 없어 제외.
   - 다음 후보(미실행): kalloc 반환값이 두 번 읽히는 꼴(eax 수명 연장), 또는 T 수명 안에 eax 를 쓰는 짧은 식. 사용자 지시로 분석 중단(2026-10-08).
7. 결과(2026-10-08 재개분, 탐침 sw6–sw10; codex gpt-6-astra 영어 질의 k0j4dpyoo — 회신의 1 순위 "sn 의 pseudo 재사용"은 제가 독립적으로 먼저 도달한 가설과 같았고, 아래 탐침으로 검증했습니다):
   - 복사 임시 T 가 cse 를 살아남는 조건을 원문으로 확정: cse.c 7467–7520 은 `(set T eax)(set 29 T)` 에서 29 가 T 의 qty 정규 레지스터일 때 두 insn 을 맞바꿔 `(set 29 eax)` 로 만들고(sw6 덤프 116/118 로 확인), 반대로 T 가 정규이면 canon_reg 가 29 의 뒤 사용을 모두 T 로 바꿉니다(sw5: 29 사용 245·249 → 48). 정규 선택은 make_regs_eqv(cse.c 840–862)의 "마지막 사용이 더 늦은 쪽" 규칙입니다. 또 local-alloc 의 optimize_reg_copy_1(local-alloc.c 700–830)이 pseudo 간 복사를 합칩니다. 따라서 T 가 남으려면 **T 가 뒤에서 다른 값으로 다시 설정되는 변수**여야 합니다(sw8/sw9: 재사용 임시 `buf` → lreg 에서 `(set 30 29)` 가 29 의 REG_DEAD 와 함께 남음; 그러나 T = eax).
   - **sw10(`sn = (struct swapnode *)kalloc(page_size * 3); rbuf = (vm_offset_t)sn;` 뒤에 기존 `sn = kalloc(0x7c)`)**: `movl %eax,%ecx; movl %ecx,-20(%ebp)` 로 원본 0x7e–0x80 과 같아졌습니다. 이유: sn 의 pseudo 28 은 호출을 건너므로 global 에서 eax 와 충돌(call 이 eax 를 설정)하고 ebx·esi·edi 가 없어 caller-save 로 ecx 를 받으며(우리 빌드의 sn 과 같은 할당), 그 첫 구간이 kalloc 값의 짧은 복사가 됩니다. 남은 차이는 page_size pseudo 48 하나뿐: 우리는 global 이 eax 를 주고(통과 0: eax 는 regs_used_so_far 에 있고 아무도 선호하지 않음, global.c 946–990), 원본은 edx(reload 의 spill 레지스터 — 우리 덤프 "Spilling reg 4./Spilling reg 1." 즉 esi·edx; eax 는 spill 레지스터가 아님)를 받아 reload 가 REG_EQUIV 메모리로 치환했어야 합니다. 그러려면 48 보다 우선순위가 낮고 48 과 겹치는 allocno 가 eax 를 선호하거나(regs_someone_prefers, prune_preferences global.c 829–880), 48 의 수명 안에 eax 가 살아 있어야 합니다(set_preference 는 하드 레지스터 또는 local 할당 pseudo 와의 복사만 기록, global.c set_preference).
   - 기각: 선언 초기화(sw6·sw7), 배열(sw4), 중첩 대입(sw5), 단순 재사용 임시(sw8·sw9)는 T 가 eax. `-mreg-alloc=dcabSDB` 진단(sw10d)은 sn 이 edi 로 바뀌어 비교 무의미. fsid 복사는 원본·우리 모두 SI 조각(move_by_pieces, 교차 적재/저장)이라 DImode 순서(use_dca, i386.c 253–285) 근거가 없습니다.
   - 다음(미실행): sw10 구조에서 48 의 eax 를 막는 자연 구문 — (a) 첫 덧셈이 sn 을 직접 쓰는 꼴 `wbuf = (vm_offset_t)sn + page_size`(28 과 48 충돌; 단 28 의 선호는 call 교차로 가지치기됨), (b) rbuf 가 하드 레지스터/local pseudo 에서 복사되어 eax 선호를 갖는 꼴, (c) 48 수명 안에 eax 를 쓰는 식. 사용자 지시로 대기(2026-10-08).
8. 결과(2026-10-08 재개 2, 탐침 sw11–sw14, 객체 채점 `runko.sh`+`scoreo.py`(swapfs/score.py 를 객체 경로로 바꾼 사본)):
   - **sw11 = sw10 + `wbuf = (vm_offset_t)sn + page_size;`(기본 플래그)**: 원본과 다른 곳은 0x83–0x94 의 5 명령뿐입니다(우리 `movl _page_size,%eax; movl %ecx,%edx; addl %eax,%edx; movl %edx,-24(%ebp); addl %edx,%eax; movl %eax,-28(%ebp)`, 원본 `add ecx,[page_size]; mov [ebp-0x18],ecx; mov edx,ecx; add edx,[page_size]; mov [ebp-0x1c],edx`). 앞 두 명령(`mov ecx,eax; mov [ebp-0x14],ecx`)은 이제 일치합니다. 나머지 17 함수는 기존과 같이 일치(scoreo 차이 0).
   - **진단(소스 아님)**: 같은 sw11 을 `-fno-force-mem -fno-expensive-optimizations` 로 컴파일하면 swapfs_mount 가 **원본과 바이트 일치(차이 0)** 합니다. 그러나 이 두 플래그는 같은 파일의 다른 함수 8 개를 깨뜨리고(각 플래그 단독으로도 깨짐), 따라서 파일 플래그가 원인이 아니라 두 메커니즘을 소스가 비켜 가야 합니다.
     (1) expensive-optimizations: local-alloc.c 1004–1007 의 optimize_reg_copy_1(700–830)이 `(set rbuf sn)` 뒤의 덧셈 입력 sn 을 rbuf 로 바꿔(lreg 덤프 `(plus 29 48)`) 덧셈 입력이 죽는 하드 레지스터 ecx 가 아니게 되므로 find_dummy_reload(reload.c) 로 `add ecx,…` 가 나오지 못합니다. 이 변환은 복사와 sn 의 죽음 사이에 CODE_LABEL·JUMP_INSN·LOOP_BEG/END 노트, sn·rbuf 의 재설정, sn 의 USE 가 있을 때만 멈춥니다. 루프 노트는 expand_start_loop/expand_end_loop(stmt.c 2145–2275)가 대기 스택 조정을 내보내 원본의 0xcb `add esp,0x24`(kalloc·kalloc·bzero·kmem_suballoc 인자 4+4+8+20)와 어긋나므로 제외.
     (2) force-mem: 두 page_size 읽기가 pseudo 로 적재되고 cse 가 하나로 합쳐 두 번 쓰이므로 combine 이 메모리 피연산자로 되돌리지 못합니다. 두 읽기 사이에 cse 가 "all" 무효화(note_mem_written cse.c 7555–7590: 구조체·배열이 아닌 가변 주소 저장, BLKmode 저장, 호출)를 하거나 합쳐진 pseudo 가 하드 레지스터를 잃어야(eax 를 받지 않고 spill 레지스터 edx/esi 를 받은 뒤 그 블록의 reload 요구로 쫓겨남) 원본이 됩니다.
   - 기각: 버퍼를 주소 취득 변수로 둔 sn 재사용(sw13·sw14, 인라인 helper): sn 이 edi, vp 가 스택으로 바뀌어 더 멂.
9. **결과(2026-10-08 재개 2): swapfs.c 전체 text 일치 탐침.** codex(gpt-6-astra) 영어 질의 kw8ku9epm 의 1 순위 "sn 을 커서로 파괴적 갱신"을 탐침으로 검증했습니다(codex 회신은 근거가 아니며, 아래 결과만 근거입니다).
   - sw18(sw0 = pz1 바탕): `sn = (struct swapnode *)kalloc(page_size * 3); rbuf = (vm_offset_t)sn; sn = (struct swapnode *)((vm_offset_t)sn + page_size); wbuf = (vm_offset_t)sn; cbuf = wbuf + page_size;` 뒤에 기존 `sn = (struct swapnode *)kalloc(sizeof (struct swapnode));`.
   - 실기 cc-744.13 `-O3`(runko.sh, s5p388-y1 헤더)로 객체를 만들어 scoreo.py 로 비교: **swapfs.c 의 18 함수 모두 차이 0(재배치 가림), text 4492 = 원본 4492.** sw19(`cbuf = (vm_offset_t)sn + page_size;`)도 객체가 sw18 과 바이트 동일(cmp)이라 두 꼴은 바이트로 구별되지 않습니다.
   - 메커니즘(원문 대조): `(set rbuf sn)` 다음 insn 이 sn 을 다시 설정하므로 optimize_reg_copy_1(local-alloc.c 721–735 의 `reg_set_p (src, p)`)이 멈추고, `sn = sn + page_size` 의 입력 sn 이 그 insn 에서 죽는 ecx 라 reload 가 `add ecx,[page_size]` 를 만듭니다. page_size 가 메모리 피연산자가 되는 경로(합쳐진 pseudo 의 할당·reload 치환 또는 combine)는 덤프로 아직 확인하지 않았습니다(배치 계획에서 확인할 항목).
   - 남은 일: 07 에 배치(swapfs 는 아직 07 에 없음 — 새 파일 `bsd/swapfs/swapfs.c` 와 관련 헤더·기록), 데이터·cstring·bss 절 비교, iter_k07·relcheck·cc -M·기록. 별도 계획(§388)으로 세우고 codex 교차검토 뒤 코딩합니다.
10. **확인 빌드 s5p393-k1(2026-10-08, 진단, 07 아님)**: s5p392-h1 의 커널 형식 스테이지(`-g -O3 -fno-omit-frame-pointer`, 전체 -D/-I)를 복사해 swapfs.c 만 sw18 로 바꿈. L1(`09_validation/reconstruction/s5p393-k1-l1-swapfs-20261008.json`): `__TEXT,__text` 4492 B 바이트 차이 0·참조 183 중 차이 0, `__DATA,__data` 432 B 차이 0·참조 40 중 차이 0, 함수 MATCH 14·MATCH_UNVERIFIED 4(swapfs_alloc·swapfs_pagein·swapfs_pageout·swapfs_getstats, 미검증 의존은 `__bss` 뿐) [정정 2026-10-08 plan 388 검토: 처음에 "18 함수 모두 MATCH" 로 잘못 적음]. 객체 판정은 `__DATA,__bss`(100 B, 추정 배치) 미검증 하나로 NOT_MATCH — zerofill 확인과 07 배치는 §388 에서 계획합니다.

## 388. S5-P361 세부 계획 — `bsd/swapfs/swapfs.c`(D054 ①, 이름 추정, D024 작성) 07 배치(plan 378·387 이어서; 코딩 전, 2026-10-08)

0. 원본(L1 `s5p393-c1`, python): `__text` [0x13a588, 0x13b714) 4492 B — 앞 spec_vnodeops 끝 0x13a588(틈 0 B), 뒤 ufs_alloc 시작 0x13b714(틈 0 B, objects_confirmed); `__data` [0x1dd7b4, 0x1dd964) 432 B(plan 378 의 끝 0x1dd95c(424 B)는 이전 추정 — 정정); `__bss` 100 B 는 객체 쪽 크기이고 원본 안 자리는 참조로 추정한 것(정적 통계, 기호 없음; 3 항 — 소유를 증명하지 않음). 함수 18(전역 logswap·compress_data·uncompress_data, 정적 15 — plan 378 의 이름 추정). 원본 기호 중 이 구간 `__data` 의 것: _swapfs_cangrow·_swapfs_enabled·_compress_window_size·_compress_threashold·_compress_enable·_compress_backoff_on·_compress_backoff_off·_swpgotcha·_swapfs_vfsops(python 기호표 조회).
1. 참조 원문 없음(D054 ①; D055 의 BSD 스왑 원문은 설계가 달라 쓰지 않음 — plan 387 기록). 파일 전체 D024 작성.
2. 후보 = scratchpad `swapfs/cand388.c` = 탐침 sw21 + 머리 문구 갱신 + 표시 주석 2 곳(findblock 의 `int full`(plan 378 근거), mount 버퍼 꼴(plan 388)). sw21 = plan 387 의 sw18 에서 mount 의 `do { … } while (0)` 감싸개를 뺀 것 — 감싸개는 이전 레지스터 배정 우회용이었고, sn 커서 꼴에서는 있든 없든 객체가 바이트 동일(sw18·sw19·sw21 `.o` SHA-256 모두 1623ab6a…9c33, 재배치 포함; `__bss` 는 크기·배치만 비교 가능). 원본 바이트가 감싸개의 유무를 정하지 못하므로, 처음 작성하는 D024 파일에는 더 단순한 꼴(감싸개 없음)을 고른 것이며 "원본이 감싸개가 없었다" 는 주장은 아님. 반대로 `int full` 을 상수 비교로 바꾸면(sw23) alloc 이 660 B 로 달라져 필요함을 다시 확인. 마지막 줄 `cbuf = wbuf + page_size;` 는 `cbuf = (vm_offset_t)sn + page_size;` 와 객체가 바이트 동일(sw18·sw19 cmp) — 바이트로 가를 수 없음을 기록에 적음.
3. 진단(07 아님): `s5p393-k1`(sw18), `s5p393-c1`(cand388) 둘 다 `__text` 0 차이(참조 183 중 0), `__data` 0 차이(참조 40 중 0), 판정 사유는 `__DATA,__bss: unverified` 하나. zerofill_check(c1, known = `zerofill-known-s5p373b-20261007.json`): reference-inferred, 참조 19, Δ 하나 0x1e46f8, 후보 [0x1e5a34, 0x1e5a98)(100 B), 정렬·zero-fill 안·기호 없음·겹침 없음, 음성 검사 검출.
4. 07 배치: `src/bsd/swapfs/swapfs.c`(= cand388.c) → iter_k07(`s5p393-it1`, 커널 C 꼴) → relcheck(원본 text 0x13a588) → 실기 cc -M(`s5p393-dep1`, 모든 헤더 07 확인) → zerofill_check(it1 객체; 결과 json 저장, known 목록에 [0x1e5a34, 0x1e5a98) 추가한 새 판) → record_partial(authored, D024/D054, 등급 **P**: bss 만 미검증 — xdr·intr 선례; 함수 compared/high 14·medium 4; 앞뒤 틈 0 B 경계 증명; zerofill 은 직전 known 판으로 검사한 뒤 새 판에 [0x1e5a34, 0x1e5a98) 추가; PROVENANCE 에 D054 이름 추정 문구·원본 주소·파일 SHA-256·전체 D024 작성, 증거 md 에 최종 L1·zerofill json·명령·cc -M·sw18/sw19/sw21 동등성·page_size 메커니즘은 해석임을 적음) → objects_partial +1, functions +18(정의 줄 python 확인), PROVENANCE +1, MODIFICATIONS +1, 증거 md·diff, 범위(python).
5. 범위 밖(이번에 하지 않음): ① plan 378 메모의 07 `machdep/i386/pmap.c` compress_data_from_phys·uncompress_data_to_phys 매개변수 이름·변환 인자 — 바이트가 같아 원본 바이트가 요구하는 수정이 아니므로 별도 계획에서 판단. ② machine_clock 잔여(plan 386·387).
   - ① 의 내용(codex 검토로 보탬): uncompress_data_to_phys 는 둘째 인자(swapfs 가 넘기는 압축 크기)에 pmap_phys_to_kern 을 적용하고 셋째(물리 주소)는 그대로 넘기며, 다섯째 매개변수는 `int *result` 인데 swapfs 는 `(int)foff / 8192` 정수를 넘김. VM_MIN_KERNEL_ADDRESS = 0 이라 지금 바이트는 같음. plan 378 메모의 "swapfs 를 넣을 때 함께 고칠 것" 은 이 계획에서 "별도 계획" 으로 바꿈(이 줄이 유효한 지시).
6. codex 교차검토(kmd7gf1mo, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| §387.10 "18 함수 모두 MATCH" 는 틀림 — k1·c1 모두 MATCH 14·MATCH_UNVERIFIED 4 | k1·c1 L1 json 의 functions 판정을 python Counter 로 집계(alloc·pagein·pageout·getstats) | ✅ 내 기록 오류 — §387.10 정정 |
| §388.0·3 의 수(text 4492 B·data [0x1dd7b4, 0x1dd964) 432 B·bss 후보 [0x1e5a34, 0x1e5a98) 100 B·참조 19·Δ 0x1e46f8·앞뒤 틈 0 B·data 기호 9 개)는 맞음 | 이번 세션 python: L1 json 절 주소·크기, zf-c1.json, objects_confirmed spec_vnodeops 끝 0x13a588·ufs_alloc 시작 0x13b714, symbols.tsv 조회 | ✅ |
| bss 100 B 를 "원본" 사실로 쓰면 안 되고 참조 추정 자리로 써야 함 | L1 json `__bss` placement "inferred"·"zero-fill (not comparable)"(앞서 출력) | ✅ 채택: 0 항 문구 고침 |
| cand388.c 와 sw21.c 의 차이는 주석뿐, 표시 주석 주소 [0x13b35c, 0x13b383) 맞음 | diff 출력(머리·`full` 주석·mount 4 줄 주석), python 0x13b2ec+0x70·+0x97 | ✅ |
| sw18·sw19·sw21 `.o` 는 바이트 동일 | sha256sum 셋 = 1623ab6a…9c33 | ✅ 2 항을 객체 SHA 로 고침 |
| 감싸개 제거는 "원본 바이트가 요구" 가 아니라 바이트 중립 선택 — 그렇게 적어야 함 | 위 SHA 동일; DECISIONS D024(작성 파일) | ✅ 채택: 2 항에 명시 |
| `__bss` 는 "내용" 비교가 아니라 크기·배치 | 위 L1 json | ✅ 2 항 고침 |
| P 등급·흐름은 xdr 선례(objects_partial :13, 증거 x86-xdr.md :6–8)와 맞음, 함수 high 14·medium 4 | objects_partial :13·x86-xdr.md :6–8(sed), README :20–23 compared/high·medium 정의(sed) | ✅ 4 항에 반영 |
| zerofill 은 이전 known 목록으로 검사한 뒤 새 구간을 덧붙인 새 판을 만들어야 함(자기 구간을 넣고 검사하면 겹침) | zerofill_check.py :191–194 `overlaps` 검사(sed) | ✅ 4 항에 순서 명시(이미 그렇게 적었으나 분명히 함) |
| 경계 증명서(앞뒤 0 B) 기록 필요 | README :25 P 정의·§381 4 항(sed) | ✅ 4 항에 반영 |
| PROVENANCE·MODIFICATIONS 에 D054 이름 추정 문구·원본 주소·파일 SHA·전체 작성 표기 | PROVENANCE :1024·MODIFICATIONS :496 if_vtrip 선례(grep) | ✅ 4 항에 반영 |
| 범위는 P 에 text 4492 B 더하고 bss 는 세지 않음 | §381 범위 줄·README 정의 | ✅ |
| §387.9 의 page_size 메커니즘 확인이 4 항에 없음 | §387.9 문장(sed) | ⚖️ 채택: 해석으로 남김(바이트 일치가 근거) — 4 항에 적음 |
| pmap 은 이름만이 아니라 uncompress 감싸개가 둘째 인자(csize)에 pmap_phys_to_kern 을 씀, 다섯째 매개변수 `int *result` 인데 swapfs 는 `(int)foff / 8192` 정수를 넘김; 지금은 VM_MIN_KERNEL_ADDRESS = 0 이라 바이트 같음 | pmap.c :1889–1898(앞서 grep), pmap.h :121 `((phys) + VM_MIN_KERNEL_ADDRESS)`, nextdev/mach/i386/vm_param.h :44 `0x00000000`, cand388.c :387–388 | ✅ 사실 — 5 항 ① 에 내용 추가, plan 378 메모("함께 고칠 것")는 이번 결정으로 대체 |
- 결과(2026-10-08): 07 `src/bsd/swapfs/swapfs.c`(= cand388.c, SHA-256 cc29d0e0…a311). `s5p393-it1`(iter_k07): `__text` 0 차이(참조 183 중 0)·`__data` 432 B 0 차이(참조 40 중 0), 함수 MATCH 14·MATCH_UNVERIFIED 4(`__bss` 만), 객체 판정 사유 `__DATA,__bss: unverified` 하나; relcheck 0; 실기 cc -M `s5p393-dep1` 125 헤더 모두 07(객체 = it1, cmp). zerofill(직전 known `s5p373b`로 검사) reference-inferred [0x1e5a34, 0x1e5a98)(참조 19·Δ 0x1e46f8·음성 검사 검출) → 새 known `zerofill-known-s5p393-20261008.json`(70 → 71 행). 기록: record_partial 의 이번 판(scratchpad `record_partial388.py` — 함수별 판정으로 high/medium, 객체 행 문구를 spec 으로)으로 objects_partial +1(P, 앞뒤 0 B), functions +18(high 14·medium 4; 18 행 모두 07 정의 줄 확인 python), PROVENANCE +1, MODIFICATIONS +1, 증거 `x86-swapfs.md`·`.diff`(줄 수 4727→4745, 70→71, 1025→1026, 497→498 — wc 확인).
- 범위(python): 이번 4492 B. A 314 obj 620812 B (72.91%), P 70 obj 227645 B (26.74%), L 2 obj 340 B; A+P 99.65%, A+P+L 99.69%, rem 2639 B; 겹침 없음.

## 389. 진단 메모 — machine_clock clock_timer_init 잔여 1 바이트(복사 레지스터) 재탐색(07 손대지 않음, 2026-10-08)

0. 탐침: `08_build/runs/tools/probe` 의 `runk2.sh`(STAGE 환경변수로 헤더 스테이지 선택; machine_clock 은 `STAGE=s5p391-g1`), mc0 = scratchpad `mcv/g1.c`(대조: 복사 `movl %esi,%edx`, 원본 `mov eax,esi`).
1. 플래그 진단(mc0, 각 1 개 끔): -fno-expensive-optimizations·-fno-force-mem·-fno-cse-follow-jumps·-fno-cse-skip-blocks·-fno-rerun-cse-after-loop·-fno-strength-reduce·-fno-caller-saves·-fno-defer-pop·-fno-thread-jumps·-O2 모두 edx 그대로 → 남은 원인은 플래그가 아닌 레지스터 순서·점유(§386 의 use_dca)로 다시 확인.
2. 원본 꼬리(python 역어셈블 0x187b32–0x187b7d): panic 블록이 0x187b47 로 흘러들고, 그 뒤 저장·포트·out 두 번이 레이블 없는 한 블록. 0x187b47 `mov [last_count],si` → 0x187b4e `mov eax,esi` → 0x187b50 `mov [reload],ax` → 0x187b56 `mov cx,[port]` → `mov bl,[last_count]` …
3. 새 해석(덤프로 확인한 부분): `mov eax,esi` 는 X 가 eax 를 받은 것이 아니라 **reload 의 입력 reload**(reload 레지스터 eax = 첫 spill 레지스터, 값은 find_equiv_reg 로 esi 에서 가져옴)일 수 있습니다.
   - mc1·mc3·mc4·mc5·mc6·mc9(한 꼬리 꼴): `movl %esi,%eax; movw %ax,_reload` 가 나옴(eax!). 다만 값 pseudo 가 스택 칸 −20 을 받아 `movw %si,-20(%ebp)`·`movb -20(%ebp),%bl` 이 생김(cse 가 뒤의 last_count 읽기를 그 pseudo 로 바꿔 수명이 asm 까지 늘고, 저장 등가 규칙 local-alloc.c 987–1000 이 성립하지 않음).
   - mc11(두 갈래 끝에 `set_counts(count)` = `last_count = count`, 합류 뒤 `reload = last_count;`): 원본과 다른 곳은 `movw _last_count,%ax` 한 명령뿐(원본 `mov eax,esi`). 합류 레이블 때문에 reload 의 find_equiv_reg 가 앞 저장(esi)을 보지 못함.
   - mc12(한 꼬리, `last_count = count; reload = last_count;`): RTL 은 `(set (mem reload) (mem last_count))`, reload 가 find_equiv_reg(reload1.c 5279–5345)로 esi 를 찾아 **esi 를 reload 레지스터로 직접** 써서 `movw %si,_reload`.
   - 따라서 원본은 "같은 블록에서 esi 가 같은 값을 갖지만 esi 를 reload 레지스터로 직접 쓰지 못해(5279–5345 의 거부 조건) eax 로 복사" 한 꼴이거나, §386 의 "X 가 eax" 꼴 중 하나입니다. 아직 어느 쪽인지 정하지 못했습니다.
4. codex(ktwfb4l6s, gpt-6-astra) 1 순위 "합류를 건너는 공유 결과 pseudo"(mc13·mc14·mc15): 전역 pseudo 가 되어 edx 를 받고 reload 가 edx 를 spill 하자 retry_global_alloc 이 ecx 를 줌(`movl %esi,%ecx; movw %cx,_reload`, -dg "Spilling reg 1 … Register 39 now in 2") → 기각.
5. 꼴 24 가지 일괄 탐침(`probe/mcs/`, 도움 함수 8 × 꼬리 6, 결과 `mcs/result.txt`): 일치 없음. 묶음별 결과: 두 갈래 꼴은 edx(지역)·ecx(전역) 또는 si 직접; 한 꼬리 꼴은 `movl %esi,%eax; movw %ax,_reload` 가 나오나 값 pseudo Y 가 스택 칸을 받음.
6. 덤프로 확정한 reload 경로(mcs01 = 한 꼬리 `reload = set_counts(count)`): Y 는 asm 이 있는 블록에서 DREG 수요로 밀려나 스택 칸 −20 을 받고, Y 의 초기화 insn 이 `(set (mem −20) (subreg:HI esi))` 저장으로 바뀜; `reload = Y` 의 입력 reload 는 reload 레지스터 eax 를 받고 값은 그 저장에서 esi 로 가져옴(`(set (reg:HI ax) (subreg:HI esi))`). 즉 **원본은 Y 의 집이 스택 칸이 아니라 `last_count` 이고 초기화 insn 이 그 저장으로 남은 꼴**로 설명됩니다 = local-alloc.c 987–1000 의 저장 등가(Y 가 `last_count = Y` 에서 죽어야 함).
   - mc16(`last_count = count; return (last_count);` 도움 함수): Y 가 적재 규칙(1044–1054)으로 `last_count` 등가를 얻지만 초기화가 적재라 reload 가 지우고, reload 입력은 메모리에서 적재(`movw _last_count,%ax`) → 원본과 한 명령 다름.
   - 저장 규칙의 걸림돌: Y 가 저장에서 죽으려면 뒤의 timer_write 가 `last_count` 를 메모리로 읽어야 하는데, 같은 블록이면 cse 가 그 읽기를 Y 로 바꿔 Y 의 수명이 늘어남.
7. codex(k3u3n22bk, gpt-6-astra) 회신 검증과 결과: s01 의 eax 복사는 그 pseudo 의 선호 부류 Q_REGS(mcs01.c.lreg :946 "Register 39 used 4 times across 7 insns in block 15; 2 bytes; pref Q_REGS, else GENERAL_REGS.")로 reload 부류가 esi 를 빼고(reload.c find_reloads 의 선호 부류 좁힘), emit_reload_insns 가 ALL_REGS 로 찾은 esi 를 원천으로 쓴 결과라는 해석 — 덤프와 일치. 제안 "`last_count` 를 timer_write 뒤에 대입" 을 탐침: mc18(HI 매개변수 인라인 `reload = c; timer_write(SEL, c); last_count = c;`), mc19(HI 지역 `c = count; reload = c; timer_write(TIMER_CNT0_SEL, c); last_count = c;`), mc20(`reload = c = count; timer_write(SEL, reload); last_count = c;`) **세 꼴 모두 꼬리가 원본과 같음**. 커널 형식 `s5p394-m18`·`m19`·`m20`: `__text` 1957 B 0 차이(참조 98 중 0)·`__const`·`__data` 0 차이, 셋의 절 내용 동일(python). 저장 등가: local-alloc.c 984–1000 이 c 의 초기화 insn 에 REG_EQUIV `(mem last_count)` 를 달고, c 가 asm 블록 수요로 레지스터를 잃으면 reload 가 c 의 쓰임을 그 메모리로 바꾸며(reload1.c 586–595 가 끝의 저장을 등가 insn 으로 기록, 1910–1928 이 그 저장을 지움) 초기화 insn 이 `last_count` 저장으로 남음 [codex 검토로 단계 구분; 최종 명령 순서가 근거이고 각 단계의 분기 선택은 덤프로 직접 보지 않은 해석].

## 390. S5-P362 세부 계획 — `machdep/i386/machine_clock.c`(plan 240 작성, D024) 07 배치(plan 386·389 이어서; 코딩 전, 2026-10-08)

0. 원본(L1 `s5p394-c1`, python): `__text` [0x187844, 0x187fe9) 1957 B — 앞 checksum_16 끝 0x187842(`00 00` 2 B), 뒤 dkbad 시작 0x187fec(`00 00 00` 3 B); `__const` [0x1d14a0, 0x1d14dc) 60 B(L1d), `__data` [0x1e17f8, 0x1e1841) 73 B; `__bss` 40 B 는 객체 쪽 크기이고 원본 자리는 참조 추정(4 항). 함수 14(L1 은 `__const` 기호 `__timer_cnt_port_`·`_clock_attrs`·`_timer_attrs` 도 함께 나열해 17 행; 함수 14 중 MATCH 5·MATCH_UNVERIFIED 9).
1. 참조 원문 없음(plan 240: 전면 작성, D024). 07 에 아직 없음(plan 240·253·365 에서 보류).
2. 후보 = scratchpad `mclk/cand390.c` = 탐침 mc21 + 머리 문구(plan 240·386·389·390, 원본 범위) + 꼬리 표시 주석 하나(plan 390). mc21 = g1(scratchpad `mcv/g1.c`, §386)에서 clock_timer_init 꼬리를 `if (count > 0xffff) panic(...); c = count; reload = c; timer_write(TIMER_CNT0_SEL, c); last_count = c;` 로 바꾸고 쓰이지 않게 된 인라인 set_counts 를 뺀 것(뺀 뒤 `s5p394-m21` 절 내용이 m19 와 같음, python) — 바이트 중립 선택으로 처음 작성하는 D024 파일에 단순한 꼴을 고른 것이며 원본이 그랬다는 주장은 아님(swapfs 선례). mc18·mc19·mc20 은 절 내용·배치·재배치가 같아(객체 파일 해시는 디버그 정보로 다름) 바이트로 가를 수 없음 — 가장 단순한 지역 변수 꼴을 고름(원본이 그 꼴이었다는 주장은 아님).
3. 진단(07 아님): `s5p394-c1`: `__text`·`__const`·`__data` 0 차이·참조 차이 0, 판정 사유 `__DATA,__bss: unverified` 하나, L1 17 행 MATCH 8·MATCH_UNVERIFIED 9(그중 함수 14: MATCH 5·MATCH_UNVERIFIED 9).
4. zerofill(c1 이 아니라 07 빌드 객체로 다시; 진단 m21 결과: known `zerofill-known-s5p393-20261008.json` 로 검사 → reference-inferred, 참조 45, Δ 0x1e6d94, 후보 [0x1e75c4, 0x1e75ec) 40 B, 겹침 없음, 음성 검사 검출).
5. 07 배치: `src/machdep/i386/machine_clock.c`(= cand390.c) → iter_k07(`s5p394-it1`) → relcheck(원본 text 0x187844) → 실기 cc -M(`s5p394-dep1`, 헤더 모두 07) → zerofill(직전 known `s5p393` 판으로 검사, 새 판 `zerofill-known-s5p394-20261008.json` 에 추가) → record_partial388(authored, D024, 등급 **P**: bss 만 미검증, `__const` 는 L1d 로 검증; 함수 high 5·medium 9; 기록 도구는 bss 절 번호를 L1 json 에서 읽도록 고친 판(이 객체의 `__bss` 는 index 2); 앞 2 B·뒤 3 B `00` 경계) → objects_partial +1, functions +14(정의 줄 python 확인), PROVENANCE +1, MODIFICATIONS +1, 증거 `x86-machine_clock.md`·`.diff`, 범위(python).
6. 범위 밖: 없음(이것이 마지막 잔여). 
7. codex 교차검토(kgq96v8ez, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| record_partial388.py 는 bss 절 번호를 3 으로 고정 — 이 객체의 `__bss` 는 index 2, 함수 의존도 "2" 라 실패 | L1 json 절 index 출력(text 1·bss 2·const 3·data 4), 도구 :96–97(grep) | ✅ 채택: 도구가 L1 의 bss index 를 쓰도록 고침 |
| 함수 14 중 MATCH 5·MATCH_UNVERIFIED 9(나머지 MATCH 3 은 `__const` 기호), 기호 이름은 `__timer_cnt_port_` | python: 객체 text 기호 14 와 L1 판정 교차 집계, 비-text 3 행 이름 출력 | ✅ 내 기록 부정확 — 0·3·5 항 고침 |
| §389.7 "local-alloc 이 저장을 옮김" 은 단계 압축 — REG_EQUIV 표시(local-alloc) 뒤 reload 가 등가 메모리로 바꾸고 나중 저장을 지움 | reload1.c 576–595(등가 insn 기록), 1910–1928(삭제) sed | ✅ 채택: 문구 고침 |
| 저장 등가 코드는 local-alloc.c 1009 까지 | local-alloc.c 1001–1009 sed: optimize_reg_copy_1 부분 | ❌ 기각: 저장 등가는 984–1000(987–1000 에서 984–1000 으로만 넓힘) |
| set_counts 제거·mc19 꼴 선택은 바이트 중립 선택으로 적어야 함, 객체 해시는 서로 다름 | sha256sum m18·m19·m20 서로 다름(앞서 출력), 절 비교 같음 | ✅ 2 항 고침 |
| 범위·크기·틈 바이트·zerofill 수치는 맞음 | 이번 세션 python(L1 json 절, 원본 틈 `00 00`·`00 00 00`, zf-m21) | ✅ |
| 후보는 mc21 과 주석만 다르고 주석 주소 [0x187b47, 0x187b56) 맞음; "plan 240.1 … variant d5" 주석은 옛 계획 근거가 있어 남겨도 됨 | diff 출력, 원본 역어셈블 0x187b47–0x187b56(앞서 출력) | ✅ |
- 결과(2026-10-08): 07 `src/machdep/i386/machine_clock.c`(= cand390.c, SHA-256 3aabbc41…fa04d). `s5p394-it1`(iter_k07): `__text` 0 차이(참조 98 중 0)·`__const` 60 B L1d 0 차이·`__data` 73 B 0 차이, 함수 MATCH 5·MATCH_UNVERIFIED 9(`__bss` 만), 객체 판정 사유 `__DATA,__bss: unverified` 하나; relcheck 0; 실기 cc -M `s5p394-dep1` 116 헤더 모두 07(객체 = it1, cmp). zerofill(직전 known `s5p393` 로 검사) reference-inferred [0x1e75c4, 0x1e75ec)(참조 45·Δ 0x1e6d94·음성 검사 검출) → 새 known `zerofill-known-s5p394-20261008.json`(71 → 72 행). 기록(record_partial388.py, bss index 를 L1 에서 읽도록 고친 판): objects_partial +1(P, 앞 `00 00`·뒤 `00 00 00`), functions +14(high 5·medium 9, subsystem machdep; 14 행 모두 07 정의 줄 확인 python), PROVENANCE +1, MODIFICATIONS +1, 증거 `x86-machine_clock.md`·`.diff`(줄 수 4745→4759, 71→72, 1026→1027, 498→499).
- 범위(python): 이번 1957 B. A 314 obj 620812 B (72.91%), P 71 obj 229602 B (26.97%), L 2 obj 340 B; A+P 99.88%, A+P+L 99.92%, rem 682 B; 겹침 없음.

## 391. 진단 메모 — 마지막 미기록 구간 [0x15a628, 0x15a67c) 84 B(D054 ③; 사용자 지시로 다룸; 07 손대지 않음, 2026-10-08)

0. 사용자 지시(2026-10-08): "이제는 하나밖에 없으니 그것만 해결하면 끝나는게 아닌가요? 그럼 취급하는게 맞을거 같습니다." — D054 ③ 의 "계속 보류" 를 풀고 다룸.
1. 범위 계산(python): plan 390 뒤 미배정 `__text` 682 B 중 0 이 아닌 바이트가 있는 구간은 [0x15a628, 0x15a67c) 84 B 하나뿐(나머지는 객체 사이 0 채움).
2. 원본(python capstone): `_ds_notify` 0x15a628(`xor eax,eax` 반환), `_vm_object_pager_wakeup` 0x15a634(빈 함수), `_send_notification` 0x15a63c(msg_id ≠ 0x42 이면 반환, `task_get_special_port(task, 2, &tnotify)` 성공이면 `ipc_notify_msg_accepted_compat(tnotify, name)`), `_task_secure` 0x15a670(`return 1`). 함수 사이 채움은 `90`(목적 파일 안의 함수 정렬 채움과 같은 값 — 네 함수가 한 목적 파일이라는 해석의 근거일 뿐 증명은 아님; 커진 ipc_xxx 경계는 D056 의 재구성 결정), 앞 ipc_xxx 끝 0x15a628·뒤 kalloc 시작 0x15a67c 로 틈 0 B. 원본 기호표는 이름순이라 목적 파일 소속을 알려 주지 않음.
3. 참조: send_notification 은 Darwin 0.1 `kern/ipc_xxx.c:271`(port_release 바로 뒤, 본문이 원본 바이트와 같은 꼴)과 NeXTMach `kern/ipc_basics.c:593`(옛 IPC, 다른 본문); ds_notify 는 Mach4 `device/ds_routines.c:1371`(다른 본문); vm_object_pager_wakeup 는 Mach4 `vm/vm_object.c:683`(다른 본문); task_secure 는 NeXTMach `kern/ipc_tt.c:618`(다른 본문). 4.2 의 빈 꼴 셋은 어느 참조에도 없음. 07 `kern/ipc_xxx.c` 는 Darwin 바탕에서 send_notification 을 지운 판(PROVENANCE :161, "send_notification removed")이고 객체 A [0x15a39c, 0x15a628).
4. 진단 `s5p395-nt0`(diag_k07, 07 복사본에 `kern/notify_stubs.c` 임시 이름): `ds_notify`(FALSE 반환)·`vm_object_pager_wakeup`(빈 몸)·`send_notification`(Darwin 본문과 같은 꼴)·`task_secure`(TRUE 반환) 네 함수로 **OBJECT_MATCH**(`__text` 0 차이, 함수 4 MATCH).
5. 사용자 결정이 필요한 것: (a) 이 84 B 를 어느 07 파일에 둘지 — 07 `kern/ipc_xxx.c` 끝에 붙여 ipc_xxx 객체를 [0x15a39c, 0x15a67c) 로 넓힐지(2026-10-04 "Darwin 의 파일 배치는 기준 근거가 아님, ipc_xxx 경계 그대로" 지시를 바꾸는 것) 또는 새 파일(이름 추정, D054 방식)로 둘지; (b) send_notification 본문이 Darwin 과 같은 꼴이므로 D027(작성 처리) 적용 여부.

## 392. S5-P363 세부 계획 — D056: [0x15a628, 0x15a67c) 84 B 를 07 `kern/ipc_xxx.c` 끝에 붙여 ipc_xxx 객체를 [0x15a39c, 0x15a67c) 로 다시 기록(코딩 전, 2026-10-08)

0. 원본(python): ipc_xxx 의 기존 A 범위 [0x15a39c, 0x15a628) 652 B(함수 8) + 이번 84 B(함수 4) = [0x15a39c, 0x15a67c) 736 B, 함수 12; 앞 ipc_tt 끝 0x15a39c(0 B), 뒤 kalloc 시작 0x15a67c(0 B, task_secure `ret` 0x15a67b). `__data` 23 B 0x1ded00, common `_lookupd_port` 는 그대로.
1. 후보 = scratchpad `nt/ipc_xxx_cand392.c` = 07 `kern/ipc_xxx.c` + 끝에 표시 주석 묶음(plan 392, D024, D056) + `ds_notify`(FALSE 반환)·`vm_object_pager_wakeup`(빈 몸)·`send_notification`(Darwin 0.1 ipc_xxx.c 의 본문을 공백까지 그대로 — python 으로 Darwin 파일의 그 함수 시작부터 끝까지 잘라 붙임)·`task_secure`(TRUE 반환). 순서는 원본 주소순.
2. 진단 `s5p395-x1`(diag_k07, 07 복사본): **OBJECT_MATCH**(함수 12 MATCH, `__text`·`__data` 0 차이). 앞서 새 파일 꼴 `s5p395-nt0` 도 OBJECT_MATCH(함수 4) — 바이트로는 두 배치를 가를 수 없고 배치는 D056 사용자 결정.
3. 07 편집: `kern/ipc_xxx.c` = 후보. → iter_k07(`s5p395-it1`) OBJECT_MATCH 확인 → relcheck(0x15a39c) → 실기 cc -M(`s5p395-dep1`) → 기록 갱신(기존 행을 고침, 새로 덧붙이지 않음):
   - objects_confirmed `x86-ipc_xxx` 행: 끝 0x15a628 → 0x15a67c, 빌드 칸에 이번 run·cc -M, 뒤 경계 칸 "0 bytes (ret at 0x15a67b; _kalloc_init 0x15a67c)".
   - functions +4(ds_notify·vm_object_pager_wakeup·task_secure 는 authored D024, send_notification 은 darwin01 `kern/ipc_xxx.c:271` 바탕 D027 취지; 정의 줄 python 확인). 기존 8 행의 검증 json·근거 칸을 새 run 으로 바꿀지는 선례(plan 383.1) 대로 새 L1 경로로 갱신.
   - PROVENANCE `kern/ipc_xxx.c` 행: 파일 SHA, "send_notification removed" 문구를 "send_notification kept (D056); ds_notify·vm_object_pager_wakeup·task_secure authored (plan 392, D024)" 로.
   - MODIFICATIONS +1(2026-10-08, plan 392), 증거 `x86-ipc_xxx.md` 에 plan 392 절 덧붙임, `.diff` 다시 만듦(Darwin 대비).
   - 범위(python): 미배정 0 이 아닌 구간 0 이 되는지 확인.
4. codex 교차검토(k0im34j3r, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 후보에 `<ipc/ipc_notify.h>` 가 없어 ipc_notify_msg_accepted_compat(void) 선언이 보이지 않음 | 07 ipc_notify.h :117–123(sed, MACH_IPC_COMPAT 안 extern void), 07 ipc_xxx.c 가져오기 :38–41 | ✅ 채택: `#import <ipc/ipc_notify.h>`(plan 392 표시) 추가 → 진단 `s5p395-x2` OBJECT_MATCH(12), 절 내용 x1 과 같음(python); 실기 cc -E 로 선언이 보임(줄 14900 `ipc_notify_msg_accepted_compat( );`) |
| D056 의 "원본 바이트로 쓴 결과가 Darwin 과 같음" 은 잘라 붙인 사실과 다름 → "Darwin 원문 복원, 바이트로 검증" 으로 | 1 항 문구, D027 정의(DECISIONS :31) | ✅ D056 문구 정정 |
| MODIFICATIONS :44 의 "to be handled with those objects" 와 증거 md :7·:15·:24(밖에 있음·남은 의무)·`kern_server.c:1149`(지금은 :1118) 가 낡음 → 명시적으로 대체 표시 | MODIFICATIONS :44(sed), 증거 md :24 grep, kern_server.c :1116–1118 sed | ✅ 기록 때 옛 행·절에 "plan 392 로 대체" 덧붙임 |
| `90` 채움은 한 목적 파일의 증명이 아님 | 원본 역어셈블(앞서) | ✅ 391.2 문구 고침 |
| 미배정 682 B → 이번 뒤 598 B(모두 0) | python(앞서 682 B, 84 B) | ✅ 결과 줄에 적음 |
| D054 ③ "보류"·plan 245–320 :621·011–099 :1996·321–373 :1313 이 낡게 됨, objects.tsv :164·source_choice.tsv :165 는 역사적 탐색 출력이라 그대로 둠 | 각 줄 sed/grep(321–373 :1313 에 "0x15a628 의 84 B 는 … 보류 유지" 확인) | ✅ 계획 파일들 끝 메모·D054 칸에 "D056 으로 해제" 덧붙임, tsv 둘은 고치지 않음 |
| 빌드 칸의 옛 `-fno-common`·`-O3 = -O2` 문구는 옛 빌드 설명 → 새 빌드로 바꿔 적음 | objects_confirmed 행(앞서 출력) | ✅ |
- 결과(2026-10-08): 07 `kern/ipc_xxx.c`(= 후보 + `<ipc/ipc_notify.h>`, SHA-256 f6830c24…1cbe). `s5p395-it1`(iter_k07) **OBJECT_MATCH**(함수 12, `__text` 736 B 0 차이·참조 34 중 0, `__data` 23 B 0 차이); relcheck 0; 실기 cc -M `s5p395-dep1` 103 헤더 모두 07(객체 = it1). 기록: objects_confirmed `x86-ipc_xxx` 행 고침(끝 0x15a67c, 빌드 칸 새 run, 뒤 경계 "ret at 0x15a67b; _kalloc_init 0x15a67c"; 행 수 315 그대로), functions 기존 8 행 고침(07 정의 줄이 import 한 줄로 1 씩 밀림, 검증 칸 새 L1) + 4 행(ds_notify·vm_object_pager_wakeup·task_secure authored D024, send_notification darwin01 :271; 12 행 정의 줄 python 확인), PROVENANCE 행 고침(파일 SHA, send_notification kept), MODIFICATIONS 옛 행에 "superseded … plan 392" 덧붙이고 +1 행, 증거 md 에 plan 392 절(옛 경계·의무·:1149 대체), `.diff` 다시 만듦(send_notification 제거 hunk 없음). D054 칸과 옛 계획 세 줄(245–320 :621, 011–099 :1996, 321–373 :1313)에 "D056 으로 해제" 덧붙임; objects.tsv·source_choice.tsv 는 역사적 탐색 출력이라 그대로.
- 범위(python): 이번 84 B(A 객체 확장). A 314 obj 620896 B (72.92%), P 71 obj 229602 B (26.97%), L 2 obj 340 B; A+P 99.89%, A+P+L 99.93%, rem 598 B(모두 `00` 채움 — 0 이 아닌 미배정 구간 없음); 겹침 없음.

## 393. S6-1 세부 계획 — L2 링크(사용자 지시 2026-10-08 "L2 링크 작업을 진행합니다"; 코딩 전)

0. 사실(python, 원본 `03_original/x86/binaries/mach_kernel` 1,117,920 B, `macho.json`):
   - 명령 7: LC_SEGMENT 5(`__PAGEZERO` 0/4096, `__TEXT` 0x100000/892,928, `__DATA` 0x1da000/122,880(파일 49,152), `__OBJC` 0x1f8000/73,728, `__LINKEDIT` 0x780000/102,112), LC_SYMTAB, LC_UNIXTHREAD(eip 0x1860dc = `_start`). 파일 크기 = `__LINKEDIT` 파일 위치 1,015,808 + 102,112.
   - 절 26: `__text` 0x1012d0 851,436(파일 위치 4,816 = Mach 머리 28 + 명령 2,152 + `00` 채움 2,636; 채움의 원인 — headerpad 인자 또는 링커의 절 배치 — 은 정해지지 않음), `__const` 22,772, `__cstring` 13,892, `__data` 46,782, `__bss` 12,432, `__common` 62,464, `__OBJC` 20 절.
   - 기호 3,751(디버그 없음): 외부 정의(type 0xf) 3,651 = 절 1 `__text` 2,916 + 절 2 `__const` 18 + 절 4 `__data` 300 + 절 6 `__common` 417, 절대(type 0x3) 100(그중 99 가 `.objc_category_name_*`/`.objc_class_name_*` 꼴). 로컬 기호 없음. 판 문자열 "NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386" 은 `__data`(vers.o 로 추정).
   - Darwin 0.1 링크 꼴(참고, 근거 아님): `conf/Makefile.template:380–387` `${LD} -static ${LDFLAGS} ${FVMFILE_LDFLAGS} ${LDOBJS} $(MACH_OFILES) vers.o ${LDFLAGS2} ${LIBS}`(FVMFILE_LDFLAGS 의 실제 값은 확인 전), `:269–272` `strip -x -o mach_kernel mach_kernel.sys`, `conf/Makefile.i386:55–69` `LDFLAGS=-e _start -segaddr __TEXT ${RELOC} -segaddr __LINKEDIT ${SYMADDR} -segalign 0x1000 -force_cpusubtype_ALL -u __muldi3`, `LIBS=-lcc`, `LDOBJS_PREFIX= libc 객체`, `LDOBJS_SUFFIX= libDriver·libobjc`. 실기 `/bin/ld`(853,564 B, 1997-04-23, VM 과 해시 같음 — `08_build/toolchains/real-i386-20261001`).
   - 07 쪽: 기록된 객체 387(A 314·P 71·L 2), 컴파일 꼴이 여럿(빌드 칸 문구 그대로 184 가지, run id·숫자를 지워 묶으면 122 가지: 커널 C 꼴 `-fwritable-strings`·`-fno-common` 유무·`-O3`/`-O4 -funroll-all-loops`, libDriver(`-fwritable-strings` 없음, `-DMACH_USER_API`), ObjC 런타임 꼴(RUNIN), ABSROOT 절대 경로 ObjC, `.s`, libgcc). 객체 id `x86-memcpy` 가 둘(libc memcpy.c 와 DriverKit __IOCopyMemory)이라 객체는 (07 소스, 원본 범위)로 식별해야 함; 등급 A* 1(kdp_machdep).
1. 판정(L2, 1 절): 링크가 성공하고, 절 크기·외부 기호 집합을 원본과 python 으로 비교한다. 더 나아가 기호 주소·절 내용(재배치 해결 뒤)을 비교해 원본과의 차이를 목록으로 남긴다(원본 전체 바이트 동일은 1 절의 별도 목표 — 이번 판정 조건 아님). 성공을 돌려주는 임시 stub 금지(1 절).
2. 단계(각 단계 뒤 기록·보고, 다음 단계 전 계획 보강):
   - **L2-A 목록(빌드 없음)**: 도구 `10_tools/reconstruction/l2_inventory.py` → `06_reconstruction/l2_objects.tsv`: 객체마다 등급·`__text` 범위·07 소스·마지막 run id·그 run 의 `.cmd` 의 RUN/RUNIN 줄·`out/*.o` 경로와 SHA-256·L1 json. 자동으로 못 찾은 것은 증거 md 를 읽어 손으로 채우고 근거를 적음. 같은 도구가 원본 모든 절(`__text` 밖 포함)에 대해 객체들의 L1 배치를 모아 **배정 안 된 바이트**(데이터만 있는 객체: vers.o·ioconf.o 꼴, MIG, 링커가 만드는 것)를 목록으로 냄. 링크 순서 = `__text` 주소순(데이터만 있는 객체는 그 데이터 주소로 끼움) — 이것은 추정이며 절마다 객체 순서가 같은지 python 으로 확인.
   - **L2-B 기록된 객체로 첫 링크**: 각 객체의 기록된 `out/*.o`(해시 확인)를 L2-A 순서로 실기 `/bin/ld` 에 넘김. 링크 명령은 원본 배치(세그먼트 주소 0x100000·`__LINKEDIT` 0x780000·`-segalign 0x1000`·`-e _start`·`-lcc`)에 맞춤; 빠진 객체(L2-A 의 미배정)는 미해결 기호 목록으로 남기고 stub 을 만들지 않음 — 미해결이 있으면 링크 실패를 기록하고 멈춤(`-undefined` 경고 옵션으로 진단 링크만 따로 할지 그때 계획). 비교 도구 `10_tools/reconstruction/l2_compare.py`: 명령·세그먼트·절 주소/크기, 외부 기호 이름·형·절·주소, 절 내용 바이트 차이(원본 대비, 구간 목록).
   - **L2-C 현재 07 로 전체 다시 빌드**: L2-A 의 객체별 명령으로 한 run 에 모든 객체를 07 에서 다시 컴파일(L0 전체 빌드), 각 객체가 기록된 객체와 절 내용이 같은지(L1 판정 유지) 확인한 뒤 다시 링크·비교. 07 이 그동안 바뀌어 달라진 객체는 목록으로 남겨 따로 계획.
3. 하지 않는 것: 원본에 없는 기능·stub·임시 대체 객체; 07 소스 수정(차이가 나오면 별도 계획); 실기 커널 교체·재부팅(사용자 몫); QEMU 부팅(L3, 별도 단계).
4. 이번 첫 작업: L2-A 도구와 표(07 과 원본은 읽기만).
5. codex 교차검토(kzih9fbbc, gpt-6.1-sol) 판정과 계획 보강:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 4,816 B 는 머리·명령 크기가 아니라 `__text` 까지의 위치(28 + 2,152 + 0 채움 2,636) | python: 머리 `(magic,7,3,2,7,2152,1)`, 0x884–0x12d0 바이트 모두 0 | ✅ 0 항 고침 |
| Darwin 링크 줄에서 `${FVMFILE_LDFLAGS}` 를 빠뜨림, 마무리 `strip -x` 있음 | Makefile.template :386·:401 grep, :269–272 sed(앞서) | ✅ 0 항 고침 |
| 빌드 칸 문구는 184 가지(122 는 정규화 값), "337" 은 재현 방법이 없음 | python: 세 표의 빌드 칸 고유 184 | ✅ 고침; 자동 추정 숫자는 버림 |
| 객체 id `x86-memcpy` 중복, A* 1 | python: 중복 id·등급 집계 | ✅ 식별은 (07 소스, 원본 범위) |
| 링크 입력은 "마지막 run" 추정이 아니라 **채택된 L1 json 의 inputs(객체 경로·SHA-256)** 로 정해야 함; 한 run 에 변형(-fno-common/common)이 섞인 예(dma) | (내 확인) iter_k07 L1 json 에 `inputs` 키가 객체 경로·해시를 가짐(앞서 if_vtrip json 출력) | ✅ L2-A 의 근거로 채택 |
| OBJECT_MATCH 는 공통 기호 정의·중복 정의·전역 공통 배치를 보증하지 않음 → 링커 탐침 필요 | macho_obj.py·l1_compare.py 구조(codex 인용; 이 판정은 설계 판단) | ✅ L2-B 앞에 링커 탐침 단계 추가 |
| 데이터만 있는 내용: 커널 판(`_version*` 0x1e5650–), `_objc_VERS_STRING` 0x1d6754·`_objc_VERS_NUM` 0x1d67f4, `_pseudo_inits` 0x1e4f80(ioconf 꼴), DriverKit 판 문자열 | python: 기호표 조회(값 일치) | ✅ L2-A 에서 모두 목록화 |
| libDriver 는 Darwin 에서 `ld -r … $(OFILES) vers.o` 중간 링크 | driverkit-1/libDriver/Makefile :610–631 sed | ✅ 직접 링크와 `ld -r` 중간 링크를 탐침으로 비교 |
| 링크 후보에 `-static -force_cpusubtype_ALL -u __muldi3`; L 객체는 넘기지 말고 `-lcc` 로 | Makefile.i386 :55–64, D051 | ✅ |
| UNIXTHREAD 전체(flavor −1, count 16, eip·cs 0xf·ss/ds/es 0x17)와 LINKEDIT(symoff 1015808, nsyms 3751, stroff 1060820, strsize 57100), 기호 이름순·문자열 표를 비교 | python: SYMTAB 디코드·이름순 확인 | ✅ 비교 도구 항목에 넣음 |
| `__mh_execute_header` 도 절대 기호 | python | ✅ |
| D007 은 "원문 텍스트 일치와 기능 재구성 구분" — 전체 바이트 목표는 1 절 | DECISIONS :11 grep | ✅ 고침 |
| L2-C 는 객체별 작업 디렉터리·ABSROOT·ObjC 런타임 꼴·MIG 이름 바꿈을 지켜야 함; 선택한 객체는 새 run 입력으로 복사·해시 | D033·D047·MIG run cmd(codex 인용) | ✅ 원칙으로 채택(세부는 L2-C 계획에서 검증) |

6. 보강한 단계:
   - **L2-A 목록(빌드 없음)**: (a) 객체마다 채택 L1 json(기록의 검증 칸·증거 md 에서) → 그 json 의 `inputs` 로 정확한 `.o` 경로·SHA-256 → 그 run 의 `out/run.json`·`run.cmd` 로 명령·작업 디렉터리; 파일 해시가 지금도 같은지 확인. 못 찾은 객체는 목록으로 남겨 하나씩 증거로 채움. (b) 원본 모든 절의 배정: 정규 절(연속 배치)·리터럴 절(`__cstring` 내용 대응)·zero-fill 추정을 따로 집계, 외부 정의 기호 중 어느 객체도 정의하지 않는 것, 판·ObjC 판·`_pseudo_inits` 등 데이터만 있는 내용. (c) 순서 가설: `__text` 주소순과 각 데이터 절 안의 앞뒤 관계를 맞춰 보고 모순을 목록화(조용히 바꾸지 않음).
   - **L2-A2 링커 탐침**(작은 시험 객체, 07 아님): 입력 순서 뒤집기, 공통 기호 배치 규칙, 공통 vs 절 정의, 중복 강정의, 정렬, 직접 링크 vs `ld -r`, `-headerpad`·`-segaddr`·`-segalign` 이 머리 채움 2,636 B 와 세그먼트 주소에 주는 영향, `strip -x` 결과. 링커 옵션 가설 표(근거·선택 인자·탐침 결과)를 남김 — "원래 명령" 이라 부르지 않음.
   - **L2-B·L2-C**: 위 결과로 다시 세부 계획 → codex 검토 → 진행. kr_run 에 `ld`·`strip` 허용이 필요하면 그때 도구 변경 계획.
7. L2-A 첫 탐침(2026-10-08, 도구 아님 — python 한 번): 객체 387 중 "기록(functions 검증 칸·증거 md)에 적힌 L1 json 이 `inputs` 를 갖고, 그 입력 `.o` 가 지금도 같은 SHA-256 으로 남아 있는" 것은 **130**, 나머지 **257** 은 옛 형식(초기 plan 의 L1 json 에 `inputs` 가 없거나 증거에 json 경로가 없음 — 예: libc memcmp·memcpy·kern_machdep·vm_pager·ipc_thread·host·priority·vm_init …). 기록된 옛 객체를 고고학적으로 다시 찾는 비용이 큼.
   - 대안(판단 필요): L2-B(기록된 객체로 링크)를 건너뛰고 **L2-C(현재 07 로 전체 다시 빌드)를 먼저** 함 — 객체마다 명령 꼴(기록된 빌드 칸의 꼴: 커널 C 꼴·`-fno-common` 유무·`-O3/-O4`·libDriver·ObjC 런타임·ABSROOT·`.s`·MIG)을 정하고 한 번에 다시 컴파일한 뒤 원본에 L1 을 다시 돌려 **기록된 판정(A/A*/P)과 같은지** 확인. 같으면 그 객체들이 링크 입력(새 run 의 해시가 근거), 다르면 목록으로 남겨 하나씩 기록을 대조. 장점: 링크 입력이 모두 현재 07 에서 나와 L0 전체 빌드도 함께 확인됨. 단점: 객체마다 명령 꼴을 정하는 작업이 필요(기록 문구 184 가지 → 꼴 몇 개로 묶기).

## 394. S6-2 세부 계획 — D057: 현재 07 로 전체 재빌드(L0)와 객체별 L1 재판정, 링크 입력 확정(코딩 전, 2026-10-08)

0. 결정 D057(사용자): 링크 입력은 현재 07 로 다시 빌드한 객체. 객체 387(식별은 (07 소스, 원본 범위); `x86-memcpy` 두 개).
1. 컴파일 꼴 분류(python, 빌드 칸 문구의 낱말로 거칠게; 확정 전): c 기본 187, c + 옛 common 명령 41, c + `-O4` + 옛 common 38, libDriver ObjC(`-fwritable-strings` 없음) 22, 커널 트리 ObjC 절대 경로(ABSROOT, D033) 19, libDriver ObjC + `-DMACH_USER_API` 19, c + `-DMACH_USER_API`(MIG 사용자 쪽) 14, ObjC 런타임 꼴(D047) 13, libDriver c 12, libDriver ObjC + MIG 9, `.s` 5, c `-O4` 2, ObjC 기타 2, libgcc(L, 다시 빌드하지 않음 — `-lcc`) 2, ObjC 런타임 c·`.s` 각 1.
2. 단계:
   a. **꼴 표 확정**(도구 `10_tools/reconstruction/l2_forms.py`, 빌드 없음): 객체마다 (07 소스, 원본 범위, 등급, 꼴, 컴파일 명령 원형, stage_headers 선택지, 작업 디렉터리, 출력 이름)을 `06_reconstruction/l2_build_forms.tsv` 로. 명령 원형은 꼴마다 대표 run 의 `.cmd`(지금도 남아 있는 것) 에서 가져오고, 객체별 추가 정의(`-DMACH_USER_API`·`-UKERNEL_PRIVATE`·RUNIN 디렉터리·ABSROOT 경로·MIG 이름 바꿈)는 그 객체의 기록(빌드 칸·증거 md·마지막 cmd)에서 읽어 근거 칸에 적음. 옛 "common 명령"(`-fno-common`) 꼴 객체는 기록에 "common 변형도 OBJECT_MATCH" 가 있는 것이 대부분 — 원본 `__common` 417 기호와 맞는 쪽(공통 기호를 내는 변형)을 고르는 규칙을 이 단계에서 객체별 근거로 정함.
   b. **묶음 스테이징 검사**: 같은 stage_headers 선택지를 쓰는 객체끼리 한 스테이지에 모을 때, 각 객체 단독 스테이지와 파일 대응(논리 경로 → 출처·해시)이 충돌하지 않는지 python 으로 확인(충돌하면 그 객체는 따로 run).
   c. **다시 빌드**: 묶음마다 kr_run 하나(RUN 줄 여럿), 실기 cc-744.13, 07 은 읽기만. 실패한 컴파일은 목록.
   d. **L1 재판정**: 새 객체마다 l1_compare(+ P 는 zerofill_check, 직전 known 판)로 판정해 기록된 등급과 비교 → `09_validation/reconstruction/s6-l0-<날짜>.json`(객체별 결과·해시). 같지 않은 객체는 원인 조사 목록(07 이 그 뒤 바뀜·명령 꼴 잘못 정함·기록 오류).
   e. 결과 보고 후 링크 단계(L2-A2 링커 탐침 → 링크) 계획.
3. 하지 않는 것: 07 수정(차이는 별도 계획), 기록 표 고침(이번은 판정 결과 파일만), libgcc 다시 빌드.
4. 비용 추정: kr_run 한 번 몇 분 × 묶음 수(꼴 15 안팎 + 따로 run 객체). 실기 장시간 사용은 nohup(기존 kr_run 방식).
5. codex 교차검토(kf5uzhmfn, gpt-6.1-sol) 판정과 보강:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 빌드 칸 낱말 검색으로는 꼴을 가를 수 없음(채택 옵션과 "같은 객체" 대안이 섞임, 예 vm_pager `-O3`(대안 `-O4`), kern_machdep `-O2`) | 표 행 읽기(앞서 출력한 묶음 문구) | ✅ 1 항 분류는 선별용으로만; 꼴 표는 객체별 근거(마지막 최종 cmd·증거)로 |
| 최종 빌드는 `-fno-common` 을 쓰지 않음(GCC27_COMPATIBILITY.md :18–22, 템플릿 s5p107 "final object = O3c__"); `-fno-common` 만 맞는다는 기록은 없음 | GCC27_COMPATIBILITY.md :18–22 sed, s5p107-build.cmd :2 grep | ✅ 재빌드는 공통 기호 변형(=`-fno-common` 없음) |
| `-g` 는 sched_prim 인라인 판단을 바꾸므로 유지 | x86-sched_prim.md :20 sed | ✅ |
| libc 는 `-O4 -funroll-all-loops` 따로(`-O4`·`-O3` 이면 9 개 다름) | x86-libc-unroll.md :14 sed | ✅ |
| 꼴 표에는 순서 있는 argv·작업 디렉터리·소스 철자·stage 선택지(`--public-sdk`·`--subst`·COMPANION)·출력 이름을 넣어야 함; 예외: IOMallocLow·SCSIDiskThread(`--public-sdk kernserv/queue.h`), 오디오 ObjC(+`-DMACH_USER_API`), `-UKERNEL_PRIVATE` 는 객체별, 런타임 objc-runtime.m 의 NXString.h COMPANION·HashTable 의 별도 디렉터리, port_allocate 류 `-D<routine>=<routine>_EXTERNAL`(kern_server_reply_user.c 는 일반 꼴) | (codex 인용 — 각 객체 꼴을 정할 때 해당 cmd 로 확인 예정; 지금은 원칙만 채택) | ⚖️ 원칙 채택, 사례는 꼴 표 작성 때 하나씩 검증 |
| 묶음 스테이징은 선택지가 같으면 결정적이나, 다른 객체의 파일이 검색 경로에 끼어드는 문제·대소문자 충돌·`--subst` 결합 문제 → 단독/묶음 스테이지를 실제 `cc -M` 과 해시로 비교해야 함 | stage_headers 우선순위(앞서 --help 확인) | ✅ 2b 를 "실기 cc -M 비교"로 강화 |
| 등급만 같으면 부족 — 함수 범위·바이트·참조 차이·절 결과·미검증 사유·zerofill 결론까지 기준과 비교; A* 는 L1 판정이 아님; P 가 모두 zerofill 대상은 아님(vm_machdep const 미참조, bios bss 미참조, kalloc D019 단일 참조); `--place-from-l1`(kmGraphics) 유지 | objects_partial :2 bios "0 references" sed | ✅ 2d 보강 |
| 최신 known 목록에는 이미 그 객체 자신(swapfs 등)이 있어 그대로 다시 쓰면 겹침 실패 → 그 객체 자신의 구간을 뺀 목록으로 검사 후 기록된 후보와 비교, 마지막에 전체 겹침 검사 | zerofill-known-s5p394 :85 "swapfs" grep, zerofill_check.py :191–194 | ✅ |
| L1 은 NOT_MATCH 여도 종료 코드 0, kr_run 은 명령 하나라도 실패하면 전체 거부 → 상태를 하나씩 확인 | (설계 사실; 기존 도구 사용 경험과 일치) | ✅ |
| MIG 생성 C 는 07 에 있음 — 이번에는 그대로 컴파일, 재생성 검증은 별도 | (확인 예정) | ⚖️ |
| 객체 재빌드 완료를 커널 호환·링크 입력 완비로 보고하지 말 것(데이터만 있는 입력 남음) | §393 6 항 | ✅ |

6. 기존 자원: 같은 성격의 일괄 재빌드가 이미 있었음 — `08_build/runs/tools/s5p129-regress.cmd`(RUN 116, 최종 템플릿 꼴), 비교 결과 `09_validation/reconstruction/s5p*-regress-compare-*.json`, scratchpad `regress.py`(객체별 iter 재빌드). 꼴 표의 출발점으로 그 회귀 명령(초기 객체)과 이후 plan 들의 최종 run cmd(뒤 객체)를 씀.
7. 다음 작업: 꼴 표 도구(`l2_forms.py`) — 객체마다 근거 cmd 를 찾아 argv 를 뽑고, 근거가 없는 객체는 목록으로 남김(빌드 없음).
8. 꼴 표 초안(2026-10-08, 도구 `10_tools/reconstruction/l2_forms.py` 첫 판, 결과는 scratchpad `l2_forms_draft.tsv` — 아직 저장소 표로 내지 않음):
   - 근거: 끝난 run 마다 실제로 실행한 `08_build/runs/<run>/run.cmd`(도구 쪽 `.cmd` 이름과 run id 가 다른 경우가 있어서 — 예 `s4a1-regress.cmd` → run `s4a1-regress-1`)의 `-c` 줄을 소스별로 모으고, 객체 기록(빌드 칸·증거 md)에 이름이 나온 run 중 가장 늦은 것을 고름. 결과: 객체 385 중 기록에 이름이 나온 run 으로 384, 이름 없는 최근 run 1(memcmp → `s5p129-diaga-1`, 확인 필요).
   - 고른 명령을 지금 커널 C 템플릿(`s5p395-it1`)과 비교해 묶으면 85 묶음: 템플릿과 같음 174, libDriver ObjC(RUNIN·`@R` 절대 -I·`-fwritable-strings` 없음) 25, 그 + `-DMACH_USER_API` 20, libDriver C 12, ObjC 런타임 12, libc `-O4 -funroll-all-loops -fno-common` 11, 템플릿보다 -D 가 적은 옛 최종(xdr 류 `-DINET` 만 11, xdr_mem 류 0 개 9, netif 류 6, authunix_prot 류 4) 등.
   - 문제(다음 단계에서 정할 것): (i) 이름이 나온 run 이 초기(s5p3–s5p19)의 `-fno-common`·옛 헤더(스테이지 선택지 없음) 명령인 객체가 있음 — 그 뒤 일괄 회귀(s5p129·s5p171·s5p227·s5p249·s5p256 등)가 지금 템플릿으로 다시 확인했으나 기록에 그 run 이름이 없는 경우. 이런 객체의 재빌드 명령은 "기록된 최적화 수준 + 지금 템플릿(공통 기호)" 으로 하고 L1 로 확인. (ii) 한 run 에 변형 여러 줄(F/N, O2/O3/O3c/O4, U/O4u)이 있어 출력 이름 규칙(F·O3c·U 우선)으로 골라야 함. (iii) 템플릿보다 -D 가 적은 옛 최종 명령은 그대로 둘지(기록 존중) 지금 템플릿으로 맞출지 — L1 결과로 판단.
9. 꼴 표 확정(2026-10-08): `06_reconstruction/l2_build_forms.tsv`(도구 `l2_forms.py` 고친 판, 385 행 + 머리). 고르는 규칙(도구 머리 주석): ① 끝난 run 의 `run.cmd` 줄 중 그 run 의 입력 사본(`08_build/runs/<run>/src/src/<소스>`) SHA-256 이 지금 07 파일과 같은 것만(진단 run 의 scratch 사본·옛 본문 제외) ② `-fno-common` 없는 줄 우선 ③ D021/D022 헤더 묶음(bsd_set nextos·mach_set sdk)으로 스테이징한 run 우선 ④ 기록에 이름이 나온 run(295), 없으면 가장 늦은 run(90) ⑤ 출력 이름 F > O3c > U > O4u > O3d. 결과: 385 모두 지금 07 소스·지금 헤더 묶음·공통 기호·출력 이름 `F__`(385; 처음 적은 "F 330/O3c 55" 는 앞 초안 값 — codex 검토로 정정). 쓰인 플래그 전체 집계(python): 진단용 플래그(`-mreg-alloc`·`-d*`) 없음; `-O3` 353, `-O4` 16(그중 `-funroll-all-loops` 11), `-O` 15(ObjC 런타임), `-O2` 1(kern_machdep); `-DMACH_USER_API` 54, `-UKERNEL_PRIVATE` 5, MIG `-D<r>=<r>_EXTERNAL` 14(정정, python); `-DINET` 없는 것 11 등 옛 최종 명령의 -D 차이는 기록대로 둠.
   - 묶음(작업 디렉터리·public-sdk·ABSROOT 기준): 커널 C 300, libDriver RUNIN 40, ABSROOT ObjC 19, ObjC 런타임 RUNIN 14, public-sdk `kernserv/queue.h` 11(libDriver 10 + C 1), HashTable RUNIN 1.
10. 재빌드 실행 설계(코딩 전):
   - 묶음마다 stage_headers 한 번(같은 선택지, 소스 = 묶음의 모든 소스 + 각 행 stage 의 companion), kr_run 하나: 객체마다 `-M` 줄(같은 argv 에서 `-c … -o …` 를 `-M` 로)과 `-c` 줄. 출력 이름 `L2__<이름>.o`(같은 basename 충돌 — memcpy 둘 등 — 은 python 으로 미리 검사해 다른 이름).
   - 묶음 안전 검사(python): 객체마다 실기 `cc -M` 의존 목록의 각 파일이 그 소스 하나만 스테이징했을 때의 정적 closure(`stage_headers.py --list` 같은 선택지)에 있고 같은 출처·해시인지 확인; 아니면 그 객체는 따로 run.
   - 판정(python, `l2_verdict.py`): 객체마다 l1_compare(`.m` 은 `--place-from-objc`, 기록에 `--place-from-l1` 이 있는 것은 그대로) → A·A*: OBJECT_MATCH, P: object_reasons 가 그 행의 미검증 절과 같음, 함수 MATCH/MATCH_UNVERIFIED 수가 기록과 같음(functions.tsv). zerofill 은 P 중 기록이 reference-inferred 인 것만, 그 객체 자신의 구간을 뺀 최신 known 목록으로 검사해 기록된 후보와 같은지. 결과 `09_validation/reconstruction/s6-l0-rebuild-<날짜>.json`.
   - 하지 않는 것: 07·기록 표 수정, 링크(다음 단계).
11. codex 교차검토(k2ckbb8k1, gpt-6.1-sol) 판정과 설계 고침:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 출력 이름은 모두 `F__`(385), `_EXTERNAL` 14 | python 집계 | ✅ 9 항 정정 |
| 함수 수를 functions.tsv 와 비교하는 규칙은 못 씀: L1 `functions` 에 `__const` 기호도 들어감(kmGraphics·port_allocate·netif), functions.tsv 에 L1 과 다른 행(netif `_if_attach`·`_if_registervirtual`, `L1 ?` 행 IOAudio·objc_runtime) | (판단 근거는 codex 인용 줄; 함수 수 규칙은 버리므로 사실 여부와 무관하게 설계에서 뺌 — functions.tsv 불일치는 따로 확인할 목록으로 남김) | ✅ 규칙 바꿈 |
| `--place-from-l1` 은 l1_compare 가 아니라 zerofill_check 의 선택지, 새 L1 json 을 넘겨야 함(입력 해시 검사) | l1_compare.py :467(선택지 목록), zerofill_check.py :123·:143 grep | ✅ |
| 묶음 안전 검사의 단독 기준은 "소스 + 그 객체의 companion"(objc-runtime.m·objc-load.m 의 NXString.h, HashTable.m 의 objc-private.h) | (확인 예정: 선택 run 의 manifest `sources`) | ⚖️ 채택, 구현 때 manifest 로 검증 |
| P 는 object_reasons 만으로 부족 — 절 목록·크기·정렬·배치·검증된 절의 0 차이까지 | l1_compare 결과 구조(앞서 사용) | ✅ |
| 이름 충돌: `memcpy.c` 둘, `hashtable.m`/`HashTable.m`(대소문자) | python: 출력 이름 소문자 중복 `f__memcpy.o`·`f__hashtable.o` | ✅ 식별은 (소스, 원본 범위), 출력 이름은 고유하게 |
| "named" 는 "채택된" 이 아니라 "언급된" — 선택 전에 채택 L1 을 확인하지 않음; codex 가 90 개 current-source 행의 기존 객체로 L1 을 다시 돌려 A·A* 는 OBJECT_MATCH, P 13 은 NOT_MATCH(DIFF 없음) | (내가 같은 검사를 도구로 다시 할 것 — 아래 새 기준) | ⚖️ 채택: 아래 기준선 단계 |
| kr_run: RUN 수 제한 없음, wait 기본 1800 초, EXPECT 는 stage 기준 이름, 명령 하나 실패면 게시 안 됨 | (kr_run 사용 경험과 일치; 구현 때 코드로 확인) | ⚖️ |

12. 고친 판정 설계: **기준선 = 고른 run 의 기존 객체(해시 확인)에 지금 원본으로 다시 돌린 L1**(도구 `l2_baseline.py`, 빌드 없음). 기준선이 기록 등급과 맞는지 먼저 확인(A·A*: OBJECT_MATCH, P: NOT_MATCH 이고 DIFF/BOUNDARY 없음 + 기록의 미검증 절과 같은 절). 그다음 재빌드 객체의 L1 을 기준선과 **구조적으로** 비교: 절마다(이름·크기·배치·바이트/참조 차이·미검증), 함수마다(원본 주소·판정·참조 수), object_reasons. zerofill 은 기록이 reference-inferred(·-single) 인 P 만, 새 L1 로 `--place-from-l1`(kmGraphics) 포함, 그 객체 자신의 구간을 뺀 known 목록, 결론·후보 구간이 기록과 같은지.
13. 다음 작업: `l2_baseline.py`(빌드 없음, 07·기록 읽기만) → 결과 보고 → 재빌드 도구.
14. 기준선 결과(2026-10-08, `l2_baseline.py`, 요약 `09_validation/reconstruction/s6-l2-baseline-20261008.json`, 객체별 L1 `…/s6-l2-baseline-20261008/`): 385 객체 모두 고른 run 의 객체가 해시대로 있고, 기록 등급과 일치(A 313 OBJECT_MATCH, A* 1 OBJECT_MATCH, P 71 NOT_MATCH — 함수 판정은 MATCH/MATCH_UNVERIFIED 뿐, 사유는 모두 "…: unverified"). P 의 미검증 절을 objects_partial 의 9 열 문구와 대조(python): 70 같음, **1 다름 — `x86-vol`(bsd/dev/vol.c) 은 L1 사유 `__DATA,__bss: unverified` 인데 기록 9 열이 비어 있음**(기록 결함으로 보임; 이번 계획은 기록을 고치지 않으므로 별도 확인 목록).
15. 재빌드 도구 설계(코딩 전, `10_tools/reconstruction/l2_rebuild.py`):
   - `prepare GROUP RID`: 묶음 G1 커널 C(RUN, public-sdk 없음, ABSROOT 아님) · G2 libDriver RUNIN · G3 ABSROOT ObjC · G4 ObjC 런타임 RUNIN · G5 public-sdk `kernserv/queue.h` · G6 HashTable RUNIN 중 하나. 행마다 companion = 고른 run 의 stage manifest `sources` 중 `.h`(다른 번역 단위는 넣지 않음). stage_headers `--prefer-07 --nextdev --bsd-set nextos --mach-set sdk`(+ G5 `--public-sdk kernserv/queue.h`)로 묶음 스테이징 → `bsd_not_adopted`·`mach_not_adopted` 가 비어야 함. 명령 파일: 행마다 고른 argv 를 그대로 쓰되 `-o` 만 `stage/L2_<행번호>__<이름>.o`(행번호로 대소문자·동명 충돌 방지), 그 앞에 같은 argv 에서 `-c … -o …` 를 `-M <소스>` 로 바꾼 의존 줄; RUNIN 행은 같은 디렉터리로; G3 은 맨 앞에 `ABSROOT`; 행마다 `EXPECT L2_<n>__<이름>.o`. kr_run prepare/launch, wait 는 넉넉한 시간.
   - `check RID`: (a) 모든 명령 상태 0·게시 확인, (b) 행마다 `-M` 출력(로그)을 파싱 — 의존 파일 각각을 run 디렉터리 기준 경로(RUNIN 은 그 디렉터리, `@R`·ABSROOT 는 실제 경로로 풀어)로 바꿔 묶음 manifest 의 (논리 경로, 출처, 해시)에 대응; 같은 선택지로 `stage_headers.py --list <소스+companion>`(단독 closure)에 그 논리 경로가 있고 출처가 같아야 함 — 아니면 그 행은 "묶음 위험" 으로 표시, (c) 새 객체마다 l1_compare(+`.m` 은 `--place-from-objc`) 를 돌려 기준선 L1 과 구조 비교: object_verdict·reasons, 절마다(이름·placement·주소·크기·byte_differences·references·refs_differ·refs_unverified), 함수마다(names·image_range·verdict·byte_differences·refs·refs_differ). (d) 기록이 reference-inferred(·single) 인 P 는 zerofill_check(그 객체 자신의 구간을 뺀 known 목록, kmGraphics·volCheck 등 기록에 `--place-from-l1` 이 있는 것은 새 L1 로) → 결론·후보 구간이 기록과 같은지. 결과 `09_validation/reconstruction/s6-l0-<GROUP>-<RID>.json`.
   - 순서: G6(1)·G4(14)·G5(11) 처럼 작은 묶음부터 → G2(40) → G3(19) → G1(300).
16. codex 교차검토(kq46r1ckp, gpt-6.1-sol) 판정과 설계 고침:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| RUNIN 행의 출력은 `@R/stage/…` 로 써야 함(RUNIN 은 그 디렉터리에서 실행, `@R/` 는 RUNIN 에서만 풀림) | kr_run.py :244–250 sed, 기존 RUNIN run `s5p287-it1` 의 `-o @R/stage/F__NXSpinLock.o` grep | ✅ |
| G2(libDriver 40) 묶음에 `nextdev/objc/hashtable.h`(IOTokenRing)와 `HashTable.h`(IODirectDevice 등) 대소문자 충돌 → kr_run 거부 | python: s5p296-it1·s5p306-it1 manifest 의 해당 경로 | ✅ G2 를 둘로 나눔(소문자 hashtable.h 를 쓰는 행 / 나머지) |
| G4·G6 의 정적 closure 에 `mach_not_adopted` 3(`src/mach/cthreads.h` 등) — 옛 채택 run 에도 같음 | python: s5p356-r2rt·s5p359-r1ht manifest `mach_not_adopted` | ✅ "목록이 비어야 함" 규칙을 "**실기 `cc -M` 실제 의존이 모두 07(또는 07 에 들인 SDK 사본)이어야 함**; 정적 목록에만 있고 읽히지 않는 항목은 기록" 으로 바꿈 |
| `--list` 는 해시를 주지 않음 → 묶음 안전 검사는 closure()/sha 로 해시까지 | (stage_headers 코드 확인 예정) | ⚖️ 구현 때 확인 |
| 의존 경로는 run 디렉터리 기준으로 어휘적으로 풀고(ABSROOT 는 링크가 지워지므로 realpath 금지) Make 이어짐 줄 처리 | (설계 판단) | ✅ |
| L1 json 키: 객체는 `object_reasons`, 절은 `"SEG,SECT"` 키 사전, 조건부 키 주의; 정렬은 L1 에 없음(객체에서 읽어야); `methods` 대응도 비교; `object`·`inputs` 는 비교에서 빼고 해시는 따로 확인 | (구현 때 l1_compare 출력으로 확인) | ⚖️ |
| zerofill 재실행 대상은 9 열만으로 부족: `vol`(9 열 빈칸, 증거는 reference-inferred), `objc_runtime`(옛 `--place-from-l1` 사용이 9 열에 없음) | x86-vol.md :6·:8(앞서 grep) | ✅ 객체별 채택 zerofill 보고서를 명시적으로 대응시켜 씀 |
| 회신 묶음 수치(G1 300 → closure 821 등) | (참고; 구현 뒤 실제 manifest 로 확인) | ⏭️ |

17. P 등급 메모(사용자 질문 2026-10-08 "P 등급의 경우 다시 원본 분석 및 수정을 해야 하는건 아닌가요?" 에 대한 답): P 는 코드·초기화 데이터는 일치하고 기호 없는 정적 `__bss` 의 원본 위치만 참조 추정인 상태라 소스 수정 대상이 아님. **L2 링크 뒤 비교에서 각 객체 `__bss` 가 놓인 주소와 코드 속 참조 값이 원본과 같으면 P 의 위치가 확인됨**(L2 비교 항목으로 명시). 참조가 없는 bss(bios 등 7)·위치 못 정한 작은 `__const`(intr 등)는 링크 배치로만 판단.
18. 재빌드 결과(2026-10-08, D057, 도구 `l2_rebuild.py`; run `s6l0-g6a`·`g4a`·`g5a`·`g2aa`·`g2ba`·`g3a`·`g1a`, 결과 `09_validation/reconstruction/s6-l0-<묶음>-<run>.json`):
   - **385 객체 모두 현재 07 에서 다시 컴파일됨(실패 0), 새 객체의 원본 대비 L1 이 기준선과 절·함수·참조 단위로 완전히 같음(385/385)**; 묶음 스테이징과 단독 스테이징의 실제 의존(`cc -M`) 차이 0. 첫 시험에서 결과 경로 `.o.o` 버그를 고침.
   - 실제로 읽힌 07 밖 입력 4 객체(자족 빌드의 남은 틈): (a) `nextdev/mach-o/fat.h` 를 07 이 아닌 로컬 SDK 사본에서 읽음 — mach_fat(184)·mach_loader(185)·kern_exec(208); 07 `nextdev/mach-o/` 에는 ldsyms.h·loader.h·rld.h 만 있음. (b) EventSrcPCKeyboard(244)는 `src/bsd/dev/i386/PCKeymap.c` 를 **Darwin 원문**에서 읽음 — 07 의 작성본 `nextdev_private/bsd/dev/i386/PCKeymap.c`(SHA 613e80cf…, Darwin f79d4ede… 와 다름; PROVENANCE :815 은 이 작성본을 쓴다고 적음)가 쓰이지 않음(stage_headers 의 private 선택이 `.h` 에만 적용되는 것으로 보임 — codex kq46r1ckp 지적과 같음). 객체는 일치하므로 두 본문이 같은 바이트를 내거나 작성본이 쓰인 적이 없는 것 — 확인 필요.
   - 후속(별도 계획, 07·도구 변경이라 codex 검토 필요): (a) SDK `mach-o/fat.h` 를 07 `nextdev/mach-o/` 로 들임(기존 들임 절차·실기 해시 목록 확인); (b) PCKeymap.c 선택 규칙과 PROVENANCE 기록을 바로잡고 작성본으로 EventSrcPCKeyboard 일치 확인.

## 395. S6-3 세부 계획 — L0 자족 빌드의 남은 틈 둘: SDK `mach-o/fat.h` 들이기, `PCKeymap.c` 작성본 선택(plan 394 항목 18; 코딩 전, 2026-10-08)

0. 사실(python·grep):
   - (a) `nextdev/mach-o/fat.h`: mach_fat·mach_loader·kern_exec 의 실기 `cc -M` 의존이 로컬 SDK 사본(`…/ref/openstep/headers/NextDeveloper/Headers/mach-o/fat.h`, SHA-256 1147faac…773f)에서 읽힘. 이 SHA 는 실기 목록 `09_validation/reconstruction/s4c-nextdev-headers-20261002.json` 의 `/NextDeveloper/Headers/mach-o/fat.h`(1,467 B)와 같음. 07 `nextdev/mach-o/` 에는 ldsyms.h·loader.h·rld.h 만 있음. 선례: `nextdev/mach-o/loader.h` PROVENANCE :236(nextdev-os42, 실기 목록, license TBD D017, "none (verbatim; file SHA-256 …)", 증거 x86-mach_header.md).
   - (b) `PCKeymap.c`: EventSrcPCKeyboard.m:37 `#import <bsd/dev/i386/PCKeymap.c>`. 07 작성본 `nextdev_private/bsd/dev/i386/PCKeymap.c`(PROVENANCE :815, D030·D032) 와 Darwin 원문의 차이는 머리 주석뿐(diff: 머리 주석 블록 교체, 나머지 동일 — 키맵 데이터 같음). stage_headers.py `select()`(:279–302)는 `--bsd-set` 에서 `src/bsd/…` 의 `.h` 만 `bsd_pick`(private 먼저)으로 보내고, `.c` 는 07 `src/` → Darwin 순이라 작성본이 선택되지 않음. nextdev_private 에서 `.h` 가 아닌 파일은 이것 하나(find).
1. 고침:
   - (a) SDK `mach-o/fat.h` 를 07 `nextdev/mach-o/fat.h` 로 그대로 복사(실기 목록 SHA 확인), PROVENANCE +1(loader.h 행과 같은 꼴), 증거는 x86-mach_fat.md 에 한 줄.
   - (b) stage_headers.py `select()`: `--bsd-set` 이고 논리 경로가 `src/bsd/…` 의 `.h` 가 아닌 파일이며 07 `src/` 에 그 파일이 없고 `nextdev_private/bsd/<rel>` 이 있으면 그 작성본을 고름(plan 395 표시; 번역 단위인 BSD `.c` 는 07 `src/` 에 있으므로 영향 없음). manifest 의 출처 표기가 작성본으로 나오는지 확인. 시험 `test_stage_headers_private_data.py` 추가(작성본이 선택되고, 07 `src/` 에 같은 이름이 있으면 그것이 선택됨).
2. 확인: 영향 객체 4(mach_fat 184·mach_loader 185·kern_exec 208·EventSrcPCKeyboard 244)를 l2_rebuild 로 다시 빌드(행 지정 묶음 기능 추가: `prepare-rows`) → L1 이 기준선과 같고 실제 의존이 모두 07. 또 07 의 다른 `.c` 가 바뀌지 않음을 보이려고 stage_headers 고침 전후로 기존 묶음 manifest 를 다시 만들어 차이가 PCKeymap.c 한 줄뿐인지 python 으로 비교.
3. 하지 않는 것: 다른 SDK 헤더 일괄 들이기(실제로 읽힌 것만), 기록 표(objects·functions) 변경.
4. codex 교차검토(kp3yz0sin, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0 항 사실은 맞음(fat.h 해시·소비 객체 3·PCKeymap 머리 주석만 다름·`.h` 조건·private 의 비헤더 파일 하나) | 이번 세션 python·grep(앞서 출력) | ✅ |
| PROVENANCE :815 "used by EventSrcPCKeyboard (s5p330-it1)" 는 틀림 — 그 run 의 stage manifest :48 은 Darwin 파일 | s5p330-it1-stage.manifest.json 의 PCKeymap 행 python 출력(origin darwin01, f79d4ede…) | ✅ 기록 정정 |
| 비헤더 규칙은 범위가 넓음 → 명시 목록(PRIVATE_DATA)으로, `_no_symlink` 유지, `--prefer-07` 없을 때 동작 정의 | (설계 판단) | ✅ PRIVATE_DATA = (`dev/i386/PCKeymap.c`,) |
| 작성본 행에 private 주석을 달되 `.h` 조건을 넓히지 말 것 | stage_headers.py :553 근처 bsd_pick assert(앞서 sed) | ✅ 별도 분기로 주석 |
| fat.h 는 loader.h 처럼 들이면 `--prefer-07` 일반 규칙이 07 사본을 고름; 들인 파일의 해시·크기·링크 여부를 직접 확인 | (구현 후 확인) | ✅ |
| `prepare-rows` 면 check 도 같은 부분집합을 써야 함; fat 소비자는 G1, EventSrcPCKeyboard 는 G3(ABSROOT) | l2_rebuild.py check 의 dep 로그 색인(앞서 작성) | ✅ `RID.rows.json` 으로 묶음·순서 기록 |
| 시험 보강·기존 시험 실행 | — | ✅ 아래 |

5. 결과(2026-10-08):
   - stage_headers.py: `PRIVATE_DATA` 명시 목록과 `private_data()`(select 와 manifest 행에 plan 395 표시) 추가. 고침 전 사본(scratchpad `stage_headers.before395.py`)과 고친 판으로 기존 7 묶음의 `--list` 를 비교(python): 6 묶음 동일, G3 은 PCKeymap.c 한 줄의 출처만 Darwin → 07 private 로 바뀜(선택만 바뀐 비교; fat.h 는 들이기 전이라 차이 없음).
   - 시험 `test_stage_headers_private_data.py` 15 통과(선택·prefer07 유무·07 src 사본 우선·사본 없음·심볼릭 링크 거부·`--bsd-set` 없을 때 끔·실제 스테이징과 manifest 주석); 기존 components 11·rename 12·soundkit 13·subst 19 모두 통과.
   - 07 `nextdev/mach-o/fat.h` 들임(SDK 원문 그대로, SHA-256·크기 1,467 B 실기 목록과 같음, 링크 아님).
   - l2_rebuild.py: 행 지정 묶음(`prepare GROUP RID N1,N2`, `RID.rows.json`) 추가.
   - 다시 빌드: `s6l0-p395a`(mach_fat 184·mach_loader 185·kern_exec 208), `s6l0-p395b`(EventSrcPCKeyboard 244): 넷 다 OBJECT_MATCH, L1 이 기준선과 같음, 실제 의존 모두 07(64·116·132·153 파일), 묶음/단독 차이 0.
   - 기록: PROVENANCE +1(fat.h) 및 PCKeymap 행 정정, MODIFICATIONS +1, 증거 x86-mach_fat.md·x86-EventSrcPCKeyboard.md 덧붙임. → **L0: 385 객체 모두 07 만으로 다시 빌드되고 원본 L1 판정 유지.**

## 396. S6-4 세부 계획 — L2-A: 링크 입력의 빈 곳 찾기(원본 절별 배정·기호 대조; 빌드 없음, 코딩 전, 2026-10-08)

0. 입력: plan 394–395 재빌드 객체 385(행 → 최신 run: `s6l0-*`, 행 184·185·208·244 는 `s6l0-p395a/b`)와 그 L1 json, 원본 `macho.json`·`symbols.tsv`, libgcc 행(objects_toolchain 2: `__muldi3` 등, `-lcc` 로 링크). 재빌드 L1 의 절 배치 종류(python 집계): 정규 배치(`given by symbol`·`given by objc metadata`·`inferred, verified by L1d`), zero-fill 추정(`__bss` inferred 64), 배치 못 함(`unplaced`: `__bss` 3, `__TEXT,__const` 9, 빈 ObjC 절들), 내용 대조만 한 리터럴 절(`__TEXT,__cstring`·ObjC `__class_names`·`__meth_var_names`·`__meth_var_types`·`__message_refs`·`__cls_refs`).
1. 도구 `10_tools/reconstruction/l2_coverage.py`(읽기만) → `09_validation/reconstruction/s6-l2-coverage-<날짜>.json`:
   - 정규 절: 객체마다 배치된 [주소, 주소+크기) 를 원본 절별로 모아 겹침 검사, 배정 안 된 구간과 그 구간의 0 아닌 바이트 수(정렬 채움 `00`·`90` 과 구별).
   - zero-fill(`__bss`·`__common`): `__bss` 는 추정 구간 합집합과 빈 곳; `__common` 은 원본 기호(절 6, 417)와 객체들의 공통 기호(이름·크기) 대조 — 원본에 있는데 어느 객체도 공통/정의로 내지 않는 이름, 크기가 원본 간격보다 큰 이름.
   - 리터럴 절: 원본 절을 NUL 단위 문자열 목록으로, 객체들의 같은 절 문자열 집합과 대조 — 원본에만 있는 문자열(어느 객체도 내지 않음) 목록. (링커가 같은 문자열을 합치므로 순서·위치는 L2 링크 뒤 비교.)
   - 기호: 원본 외부 정의 3,651(절 1·2·4·6)과 절대 100 을 객체들의 외부 정의(SECT·COMMON·ABS)·libgcc 구성원과 대조 → 정의되지 않은 이름 목록(이것이 데이터만 있는 객체·판 객체 후보), 둘 이상이 강하게 정의하는 이름(중복) 목록.
   - 0 아닌 미배정 구간마다 그 구간을 가리키는 기호·재배치 출처(어느 객체가 참조하는지)를 붙여 다음 단계(누락 객체 작성 계획)의 근거로.
2. 하지 않는 것: 07·기록 변경, 링크.
3. codex 교차검토(kjkjsfhu0, gpt-6.1-sol) 판정과 계획 고침:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **`__bss` 가 맞지 않음**: 원본 12,432 B, 추정 64 구간 합 12,402 B(겹침 없음) → 남은 30 B, 배치 못 한 bss 3 개(bios 16·rtc 14·SCSIGenericKern 4) 34 B, 선택 객체 bss 합 12,436 B → 정렬 전에도 4 B 초과 | python(이번 세션): 행 → 최신 run(184·185·208·244 는 p395) 객체의 `__bss` 크기 합 12,436, L1 inferred 합집합 12,402·겹침 0, unplaced (315,16)(354,14)(371,4) | ✅ **새 발견** — §394 항목 17 의 "P 는 위치만 미확정" 은 이 셋(참조 없는 bss)에는 맞지 않을 수 있음; 원인 조사 대상(07 에 원본에 없는 정적 변수가 있거나 크기가 다를 가능성) |
| `__message_refs`·`__cls_refs` 는 S_LITERAL_POINTERS(0x5) — NUL 로 나누면 안 되고 재배치로 가리키는 문자열 내용으로 비교 | (도구 구현 때 macho.json 절 flags 로 확인) | ✅ 계획 고침 |
| 원본 `__cstring` 에 객체가 내지 않는 비어 있지 않은 문자열 51(DMA/SCSI 상태·명령 설명) | (도구로 다시 셀 것) | ⚖️ 도구 결과로 확인 |
| `00`/`90` 만으로 채움 판정 금지 — 다음 객체의 정렬 요구로 판정; text 미배정 598 B·282 구간 중 281 은 정렬로 설명, `[0x1c88f4, 0x1c8900)` 12 B(HashTable 앞)는 설명 안 됨 | (도구로 다시 셀 것) | ⚖️ |
| 공통 기호: 이름별 최대 요청 크기, 강정의가 이기는 경우, 원본 다음 주소는 상한일 뿐; 원본 `__data` 에 정의된 16 이름(`_hz`·`_tick`·`_time` 등)의 공통 요청은 오류 아님 | (도구 구현) | ✅ |
| 기호 비교는 `ext`·kind 로, `N_PEXT` 따로; `__mh_execute_header` 는 링커 정의; ObjC 절대 표지 99 는 객체가 정의; libgcc `__udivdi3` 의 지역 `___clz_tab` 256 B 도 덮음 | (도구 구현) | ✅ |
| 원본 이름 중 정의 없는 것 89(`__data` 56·`__common` 30·`__const` 3) | (도구로 다시 셀 것) | ⚖️ |
| 미배정 구간의 참조는 "소비자" 이지 정의 객체가 아님; 재배치는 PC 상대·SECTDIFF/PAIR 까지 풀어야 | l1_compare 재배치 해석 재사용 | ✅ |
| 행 선택은 명시적으로(184·185·208→p395a, 244→p395b), memcpy 두 행(6·201) 유지; unplaced 는 "있는 내용, 위치 모름" 으로 따로(`__bss` 34 B, `__const` 44 B) | python 행 선택 출력(위) | ✅ |

4. 고친 도구 범위(`l2_coverage.py`): 행 선택 명시 → 정규 절 배치 목록(배치 방법·해시·포함·정렬·겹침 검사) → text/정규 데이터 미배정 구간(다음 객체 정렬로 설명되는지) → `__bss`(zerofill 결과와 L1 대조, 크기 합 모순 보고) → `__common`(이름별 최대 요청·강정의·상한) → 리터럴 문자열 절(문자열·참조 오프셋)·리터럴 포인터 절(재배치로 가리키는 내용) → 기호(정의 없음·중복·추가·N_PEXT·링커 정의) → 미배정 구간의 참조 소비자. 숫자는 codex 값과 독립으로 다시 구해 대조.
5. 결과(2026-10-08, 도구 `l2_coverage.py`, `09_validation/reconstruction/s6-l2-coverage-20261008.json`; 숫자는 codex 회신 값과 독립으로 다시 구해 일치):
   - `__text`: 미배정 598 B 모두 `00`; 다음 객체 정렬로 설명 안 되는 것은 `[0x1c88f4, 0x1c8900)` 12 B(HashTable 앞) 하나. 배치 문제(겹침·포함·정렬) 0.
   - `__TEXT,__const`: 미배정 1,589 B 중 0 아닌 1,036 B, 정렬로 설명 안 되는 구간 9: `0x1d68b0` 256 B(libgcc `__udivdi3` 의 지역 `___clz_tab` 자리로 보임 — 도구가 libgcc 의 const 를 아직 넣지 않음), `_IODMAStatusStrings`, `_objc_VERS_NUM`·`_objc_VERS_STRING`, 기호 없는 892 B(0x1d58e4)·160 B·작은 12–14 B 넷(배치 못 한 const 44 B 후보).
   - `__DATA,__data`: 미배정 6,960 B 중 0 아닌 4,157 B, 구간 18 — `_sysent`/`_nsysent`, `_linesw`, `_unixsw`/`_unixdomain`, `_vfssw`, `_inetsw`/`_inetdomain`, `_fragtbl*`/`_around`/`_inside`, param 꼴(`_max_proc`·`_ncallout`·copyright 문자열 등), `_machdep_call_table`, `_bdevsw`/`_cdevsw`, `_pseudo_inits`, `_IOSCSI*Strings`, ObjC `__alloc` 등 훅, 판(`_version*`) — Darwin conf 류 "데이터만 있는" 파일(init_sysent·tty_conf·uipc_proto·vfs_conf·in_proto·param·conf·ioconf·ufs_tables·vers 등)의 내용으로 보임(이름은 가설).
   - 기호: 원본 정의 중 객체가 정의하지 않는 이름 89(`__data` 56·`__common` 30·`__const` 3), 강정의 중복 0, 원본에 없는 추가 정의 0, N_PEXT 0. 공통 기호: 요청이 상한을 넘는 것 0, 아무 객체도 요청·정의하지 않는 원본 공통 30(`_master_cpu`·`_active_u`·`_kernel_map`·`_cons`·`_file`·`_nmi_*` 등), 원본에서 `__data` 에 정의된 이름의 공통 요청 16(정상).
   - `__bss`: 객체 합 12,436 B > 원본 12,432 B(추정 합 12,402 + 배치 못 한 bios 16·rtc 14·SCSIGenericKern 4) — 정렬 전에도 4 B 초과(조사 필요).
   - 리터럴: `__cstring` 원본 문자열 중 객체가 내지 않는 51(DMA/SCSI 설명 문자열 — 위 `_IOSCSI*Strings` 표의 내용), ObjC 문자열 세 절은 차이 0; `__message_refs` 725·`__cls_refs` 32 슬롯이 가리키는 내용 집합이 객체와 같음(객체 쪽 슬롯 1,393·90 은 링커가 합침).
6. 판단: 링크 전에 **데이터만 있는 누락 객체**를 먼저 다시 만들어야 함(링크가 미정의 기호로 실패할 것). 다음 계획(§397)에서 구간마다 원본 바이트·참조 소스(Darwin conf·NeXTMach)·객체 경계를 정하고 07 에 둘 파일 이름은 D054 처럼 사용자 결정이 필요한 곳을 묻기로 함. 함께 조사: bss 4 B 초과, text 12 B 틈, 이름 없는 const 구간.

## 397. S6-5 세부 계획 — L2-B: 링크 입력의 빈 곳 메우기(구간별 출처 정하기, 링커 규칙 탐침, 데이터만 있는 객체 작성; 코딩 전, 2026-10-08)

0. 사실(이번 세션 python, `09_validation/reconstruction/s6-l2-coverage-20261008.json` 과 객체·원본 바이트 직접 대조):
   - (a) **배치 못 한 `__const` 44 B 는 빈 곳이 아닙니다.** 객체 9 개의 4·12 B const(intr·PCresume·vm_machdep·fp_support·i386_init·PCexception·trap·pmap 은 `18 00 20 00`, ddm 은 `40 00 00 00 41 00 00 00 42 00 00 00`)가 링크 순서대로 원본 빈 곳 `0x1d13e8`(ddm 12 B)·`0x1d14dc`(fp_support·i386_init·intr)·`0x1d163c`(pmap·trap·vm_machdep)·`0x1d5c56`(PCexception·PCresume, 정렬 2 B; plan 397 항목 4 에서 고침)과 바이트가 같습니다. `__const`·`__data`·`__bss` 의 배치 순서는 `__text` 순서와 어긋남이 0 입니다(배치된 const 48·data 217·bss 64).
   - (b) **`__const` 0x1d58e4 892 B** = 키맵 882 B(EventSrcPCKeyboard 의 `PCDefaultKeymap`, 원본 0x1d554a 의 것과 882 B 모두 같음) + 위 (a)의 8 B(0x1d5c56) + `00` 2 B 입니다(항목 4 에서 고침). 이 둘째 사본을 가리키는 참조는 원본에 없습니다(4 B 주소 검색 0 건). 링크 순서로 EventSrcPCPointer 와 PCexception 사이의 객체(PCPointer.m·EventShmemLock.s·kbd_entries.m·PCinit.c) 하나가 키맵을 한 번 더 들인 것으로 보입니다(어느 것인지는 아직 모릅니다).
   - (c) **`__DATA,__data` 0x1db91b 37 B** "add_sr: source route table overflow\n" 은 plan 377 기록(if_vtrip 원본 `__data` 208 B, add_sr 문자열 두 벌)의 둘째 벌입니다. 07 if_vtrip 객체는 171 B 이므로 37 B 가 모자랍니다. 참조 0 건입니다.
   - (d) **`__const` 0x1d1276 14 B** = "swapfs\0" + `00` 3 B + `04 00 00 00`(0x1d1280)입니다. 참조 0 건이고, 링크 순서로 netif 와 kern_server 사이(그 사이 객체 121 개 중 const 를 내는 것 0)에 있습니다. 참조 원문에 `"swapfs"` 문자열 0 건(grep)입니다. 주인을 아직 모릅니다.
   - (e) **판 문자열**: `0x1d647c` 160 B "@(#)LIBRARY:libDriver  PROJECT:driverkit-94.16.2 …" (strlen 105, 기호 없음), `_objc_VERS_STRING` 160 B(strlen 87)·`_objc_VERS_NUM` "170"(다음 객체까지 12 B, `char[10]` 이면 0x1d67fe 에서 끝나고 다음 const 정렬 4 로 0x1d6800), `__data` 끝 `_version_major` 4·`_version_minor` 2·`_version_variant` ""·`_version` "NeXT Mach 4.2: … RELEASE_I386\n"(101 B, `__data` 끝 0x1e56be 와 맞음). vers_string 꼴 `char[160]`·`char[10]` 은 가설입니다.
   - (f) **`__text` 12 B 틈 `[0x1c88f4, 0x1c8900)`**: 바로 뒤 HashTable 은 ObjC 런타임의 첫 객체이고 0x1c8900 은 16 B 정렬입니다. ObjC 런타임 객체 중 `objc-msg.s` 만 text 정렬 4(16 B)이므로, libobjc 를 `ld -r` 로 한 객체로 묶어 링크했다면 묶음 전체의 정렬이 16 B 가 되어 이 틈이 설명됩니다(가설, 탐침 필요).
   - (g) **`__bss` 4 B 초과의 원인은 rtc 입니다.** 빈 곳 6 개 합 30 B 중 bios(16 B)는 0x1e75a4(miniMonMachdep·APM_i386 사이), SCSIGenericKern(4 B)은 0x1e7570(SCSIDiskKern·ddm 사이)에 정확히 맞고, 나머지 넷(2·2·3·3 B)은 다음 객체의 정렬 채움입니다(합 20 + 10 = 30). rtc 의 자리(autoconf_i386 끝 0x1e7749 ~ kmDevice 0x1e774c)는 3 B 이므로, 07 rtc.c 의 참조 없는 `static unsigned char rtc[RTC_NREG]`(14 B, x86-rtc 증거에 "unreferenced")는 원본에 없던 것으로 보입니다.
   - (h) **데이터만 있는 객체 후보**(빈 곳의 링크 순서 위치·이름·참조 원문 grep): init_sysent(`_sysent`·`_nsysent`, init_main 과 kern_acct 사이), tty_conf(`_linesw`·`_nldisp`), uipc_proto(`_unixsw`·`_unixdomain`), vfs_conf(`_vfssw`·`_vfsNVFS`, 이름 문자열 "swapfs" "spec" "nfs" "4.3" 이 `__data` 안), in_proto(`_inetsw`·`_inetdomain`), ufs_tables(`_around`·`_inside`·`_fragtbl124`·`_fragtbl8`·`_fragtbl`), param(copyright 셋·`_max_proc`·`_nchsize`·`_ncallout`·`_nclist`·`_nmbclusters`·`_nport`·`_ncsize`·`_ndquot`·`_cfreelist`·`_cfreecount`·`_fifoinfo`; NeXTMach conf/param.c 의 순서와 같음), counters(`_c_thread_*` 5, ast·exception 사이), machdep_call(`_machdep_call_table`·`_count`, machdep·pcb 사이), conf(`_bdevsw`·`_nblkdev`·`_cdevsw`·`_nchrdev`, autoconf_i386·cons 사이), ioconf(`_pseudo_inits` = {32, pty_init}, {1, venip_config}, {0, 0}; NeXTMach config mkioconf.c 가 만드는 꼴), libDriver dma.c(`_IODMAStatusStrings` 7×8 B = 56 B, Darwin driverkit-1 libDriver/dma.c:35, 파일 44 줄), SCSIGlobals.m(`_IOScStatusStrings`·`_IOSCSISenseStrings`·`_IOSCSIOpcodeStrings`, Darwin libDriver/Kernel/SCSIGlobals.m), objc-globaldata.m(훅 11×4 B = 44 B, Darwin objc/objc-globaldata.m; objc-errors 와 objc-globaltext 사이), 판 객체 셋(위 e).
   - (i) **이미 있는 객체 끝에 붙는 것으로 보이는 이름**: `_pmsgbuf`(qsort·subr_prf 사이 = subr_log 자리, 값 0; NeXTMach bsd/subr_log.c:45), `_nrnode`(nfs_server·nfs_subr 사이, 값 0; NeXTMach next/machdep.c:173·175), `_active_mfsbufs`(mfs_prim 끝, 값 0; Darwin kern/mapfs.c:1081 `int active_mfsbufs = 0;`).
   - (j) **`__common` 배치 규칙(가설, 강한 근거)**: 원본 `__common` 417 이름을 주소 순으로 보면 이름이 알파벳 오름차순인 구간들로 나뉩니다. "링크 순서에서 그 이름을 처음 언급(UNDF 또는 COMMON)한 객체 순, 객체 안에서는 기호표 순" 으로 재빌드 객체 385 를 흉내 내면, 언급되는 406 이름 중 최장 증가 부분열이 400 입니다. 어긋나는 6 중 5(`_boottime` init_main·`_callout` kern_clock·`_inode_list`·`_iuniqtime` vfs·`_in_interfaces` in.c)는 07 객체가 **잠정 정의(COMMON)** 로 언급하는 것이고, 원본에서는 그 객체가 언급하지 않았거나(또는 UNDF 로) 다른 곳이 정의한 것으로 보입니다. `_master_cpu` 는 원본에서 맨 앞(0x1e8750)인데 재빌드 객체 중 처음 언급은 kern_sig(UNDF)입니다. 아무 객체도 언급하지 않는 11(`____xxx_state`·`_file`·`_mfsbuf_lock`·`_nmi_*` 8)은 그 이름을 정의하는 객체의 링크 위치를 알려 줍니다(예: `_callout`·`_file` 은 ufs_vfsops 구간 뒤 = param 자리).
1. 단계(차례대로; 각 단계 끝에 기록):
   - **B1 도구 고침**(07 변경 없음): `l2_coverage.py` 가 (a)의 배치 못 한 const 를 링크 순서·바이트 일치로 배치하고, libgcc 구성원의 const(`___clz_tab` 256 B, 0x1d68b0)를 넣고, (j)의 공통 기호 흉내(처음 언급 순)를 보고에 더합니다. 결과를 다시 만들어 숫자가 위와 같은지 확인합니다.
   - **B2 링커·컴파일러 탐침**(실기, gcds, 저장소 밖 임시 디렉터리; 결과 json 은 `09_validation/reconstruction/`):
     1. 공통 기호 배치 순서: 작은 객체 둘~셋(UNDF·COMMON·정의를 섞고 이름 순서를 바꿈)을 `ld` 로 링크해 `__common` 주소 순서가 "처음 언급 순, 객체 안 기호표 순" 인지, 객체 안에서 COMMON 과 UNDF 를 따로 처리하는지 확인합니다(in.c 의 `_in_interfaces`·`_ipintrq` 순서가 이 질문입니다).
     2. `ld -r` 묶음의 정렬: text 정렬 4 인 `.s` 와 정렬 2 인 `.c` 를 `ld -r` 로 묶어 묶음 `__text` 정렬이 4 가 되는지, 묶음을 링크했을 때 앞에 채움이 생기는지 확인합니다(f).
     3. GCC 2.7(cc-744.13) 동작: 참조 없는 `static const` 배열이 `.c`(cc1)와 `.m`(cc1obj)에서 객체에 남는지(b·d), `-fwritable-strings` 여부에 따라 인라인 함수의 문자열이 두 벌 나오는 조건(c).
     4. vers_string: 실기의 vers_string(있으면) 내용·출력 꼴을 읽기만 합니다(e의 `char[160]`·`char[10]`·기호 없는 libDriver 판 문자열의 꼴).
   - **B3 데이터만 있는 객체 작성**(h): 파일마다 참조 원문 후보(Darwin 0.1·NeXTMach·Mach4, 같은 이름 파일을 세 나무 모두에서 찾음)를 원본 바이트(재배치는 원본 기호 주소로 풀어서)와 대조해 고르고, 맞지 않는 줄은 D024 로 고칩니다. 객체별 확인은 "데이터 L1": 객체 `__data`·`__const`·`__cstring` 을 원본 빈 곳에 놓고 바이트·재배치 대상 주소가 모두 같은지 python 으로 봅니다. 출처·라이선스는 D013·D030 규칙대로 PROVENANCE·MODIFICATIONS 에 적습니다. 판 객체 셋은 원본 문자열(바이트 사실)로 작성합니다.
   - **B4 이미 있는 객체의 남은 바이트**(b·c·d·g·i): 각 객체를 따로 진단합니다(scratch 사본만; 07 은 결과가 바이트로 확정될 때만 고침). rtc 는 참조 없는 정적 배열을 빼면 원본 자리(3 B 이하)와 맞는지, 그때 rtc 객체가 L1 에서 A 가 되는지 확인합니다. pmsgbuf·nrnode·active_mfsbufs 는 값 0 초기화 정의가 그 객체의 `__data` 끝에 오면 원본 주소와 맞는지 확인합니다.
   - **B5 공통 기호 맞추기**(j): B2-1 규칙이 확정되면 재빌드 객체 + B3 객체로 흉내 내어 원본 417 순서와 같아질 때까지 07 의 잠정 정의/extern 선언을 고칩니다(text·data 바이트는 바뀌지 않음을 L1 로 확인). `_master_cpu`·`____xxx_state`·`_nmi_*` 처럼 정의하는 곳이 바이트로 정해지지 않는 이름은 사용자에게 묻습니다.
2. 사용자 결정이 필요한 곳(코딩 전에 묻지 않고, 해당 단계에 이르면 바이트로 정해지지 않는 것만 묶어서 묻습니다): 데이터만 있는 객체의 07 파일 이름·경로(특히 ioconf·판 객체 셋·counters), 키맵 둘째 사본·"swapfs" const 의 주인 파일이 바이트로 정해지지 않을 때, 정의 위치가 바이트로 정해지지 않는 공통 기호.
3. 하지 않는 것: 링크 자체(B1–B5 뒤 다음 계획), 등급 표 변경(B4 의 결과가 나오면 따로 계획), 01_resources·03_original 변경.
4. codex 교차검토(k6bny7aag, gpt-6.1-sol) 판정과 계획 고침(코딩 전):

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| (a)의 PCexception·PCresume 는 0x1d5c58 이 아니라 **0x1d5c56·0x1d5c5a**(정렬 2 B)이고 끝 `00` 2 B 가 뒤에 옴 | python: 키맵 끝 0x1d58e4+882 = 0x1d5c56, 원본 0x1d5c56 의 10 B = `18002000 18002000 0000` | ✅ **내 계획이 틀렸습니다.** 0 (a)·(b)를 "키맵 882 B + const 8 B(0x1d5c56) + `00` 2 B" 로 고칩니다. 나머지 일곱(ddm·fp_support·i386_init·intr·pmap·trap·vm_machdep) 위치는 그대로입니다 |
| 키맵 둘째 사본 882 B 일치, 그 주소를 가리키는 4 B 값 0 건 | python: `B(0x1d58e4,882)==B(0x1d554a,882)` → True (이번 세션 두 번째 확인) | ✅ |
| add_sr 문자열은 원본 파일에 세 군데(0x1d74d8 `__cstring`, 0x1db870 근처, 0x1db91b) | python 파일 검색: 파일 오프셋 0xd74d8·0xdb870·0xdb91b(= 주소 +0x100000) | ✅ (plan 377 기록과 같음) |
| `___clz_tab` 256 B = `bit_length(i)` 표 | python: `B(0x1d68b0,256)==bytes(i.bit_length() for i in range(256))` → True | ✅ B1 에 넣습니다 |
| rtc 14 B 를 두면 kmDevice 가 0x1e7758 로 12 B 밀림, 빼면 12,422 + 10 = 12,432 | python: 0x1e7749+14 = 0x1e7757 → 4 B 정렬 0x1e7758 | ✅ |
| 공통 기호 흉내: 417·406·LIS 400, 어긋남 6 같음. in.c 두 이름을 바꾸면 401, UNDF 먼저 367, COMMON 먼저 372 → "원본이 UNDF 였다" 만으로는 설명 안 됨 | python 흉내(이번 세션, 내 스크립트로 네 방식): symtab (406,400)·swap (406,401)·undf_first (406,367)·common_first (406,372) | ✅ 규칙은 가설로 두고 B2 탐침으로 정합니다. in.c 문제는 미해결로 기록합니다 |
| init_sysent: NeXTMach·Darwin 어느 쪽도 그대로는 184 항목이 아님(codex 182·234) | grep: 표 본문의 항목 줄 수(전처리 전, `#if` 양쪽 포함) NeXTMach 199·Darwin 218 — 전처리 뒤 수는 아직 안 셈 | ⚖️ "그대로 맞지 않음" 은 받아들이되, 정확한 수는 B3 에서 실기 `cc -E` 로 셉니다 |
| vfs_conf: 원본은 20 항목(NeXTMach 10) | python: `_vfsNVFS` 값 0x1db6e0, (0x1db6e0−0x1db640)/8 = 20; NeXTMach vfs_conf.c:48–79 항목 10 | ✅ D024 고침이 필요합니다 |
| param: 참조 전체는 248 B, `hz`·`tick`·`tickadj` 를 빼면 236 B; 이 셋은 재빌드 mach_clock.c 가 이미 정의 | 객체 기호: mach_clock.c `_hz`·`_tick`·`_tickadj` SECT; 원본 `_hz` 0x1dee30·`_tick` 0x1dee34·`_tickadj` 0x1dee48(`__data`, mach_clock 자리) | ✅ (248 은 B3 에서 빌드로 확인) |
| tty_conf: 참조 파일의 `nullioctl` 은 이미 tty.c 가 정의(원본 0x111bf4) | 객체 기호: tty.c `_nullioctl` SECT; symbols.tsv `_nullioctl` 0x111bf4 | ✅ 표만 옮깁니다 |
| in_proto·conf 는 참조 크기와 다름(원본 377·2,476 B) | (구조 크기 미측정) | ⏭️ B3 에서 빌드·측정으로 정합니다. 계획 숫자로 옮기지 않습니다 |
| dma.c 선언 줄은 44 가 아니라 35 | dma.c:35 `const IONamedValue IODMAStatusStrings[] = {`; `wc -l` 44 | ❌ 계획의 "44 줄" 은 파일 길이(44 줄)였습니다. 오해가 없도록 "dma.c:35, 파일 44 줄" 로 적습니다 |
| objc-globaldata.m 은 SHLIB 를 끄고 빌드해야 함(켜면 468 B 덧붙음) | Darwin objc-globaldata.m 끝 `#ifdef SHLIB char _objc_global_data_pad[468]` (이번 세션 읽음) | ✅ |
| 원본 ObjC 모듈 76, SCSIGlobals·globaldata 이름 없음 | python: `__module_info` 1,216/16 = 76; 원본 파일에 "SCSIGlobals"·"globaldata"·"objc-globaltext" 0 건(재빌드 objc-globaltext.m 도 모듈 없음) | ✅ 데이터만 있는 `.m` 이 모듈 정보를 내는지 B2 탐침에 넣습니다 |
| 참조 빌드는 libDriver·libobjc 를 `ld -r` 로 묶음: Darwin `driverkit-1/libDriver/Makefile:631`, `objc/Makefile.postamble:155` | 파일 열어 확인: Makefile:631 `$(LD) -r -o $@ $(OFILES) vers.o`(vers.o 가 끝); postamble:155 `$(LD) -r -o …/libk$(NAME).o …/static_obj/$${architecture}/*.o` | ✅ **중요한 근거입니다.** libDriver 판 문자열이 libDriver 끝(IOVPCodeDisplay 뒤)에 오는 것과, libobjc 구성원 순서(HashTable·List·Object·Protocol·except·hashtable… = `*.o` 의 ASCII 순)가 원본 text 순서와 맞습니다. 공통 기호 흉내는 묶음을 넣은 뒤 다시 합니다 |
| 객체 재배치 41,357 개를 풀어도 (b)–(d) 구간 대상 0 | (내 재배치 해석은 안 함) | ⏭️ 행동이 바뀌지 않습니다. 계획에 옮기지 않습니다 |
| 순서 권고: B1 고침 → B2 넓힘 → B3/B4 → 묶음 넣고 다시 흉내 → B5 | 위 확인들 | ✅ 받아들입니다 |

5. 고친 단계:
   - B1: 작은 const 아홉은 "링크 순서로 뒷받침되는 조건부 배치" 로 표시합니다(같은 바이트 `18002000` 이 여럿이라 유일 일치가 아님). `___clz_tab` 을 libgcc 행으로 넣습니다.
   - B2: (1) 공통 기호 순서, (2) `ld -r` 정렬, (3) 참조 없는 static const·인라인 문자열 두 벌, (4) vers_string 에 더해 (5) **libDriver·libobjc 를 참조 빌드처럼 `ld -r` 로 묶은 중간 객체**의 기호 순서·정렬·COMMON 처리·문자열 합침을 봅니다. (6) 데이터만 있는 `.m`(SCSIGlobals·objc-globaldata) 이 ObjC 모듈 정보를 내는지 봅니다.
   - B3: 참조 원문은 실기 `cc -E` 로 전처리한 뒤 항목 수·구조 크기를 재고, 이름이 바뀐 대응 파일(ufs_tables ↔ Darwin ffs_tables)도 찾습니다. 객체가 내는 모든 절과 COMMON 기호를 봅니다(목표 구간만 보지 않음). param 에서 `hz`·`tick`·`tickadj` 는 빼고, tty_conf 는 표만, objc-globaldata 는 SHLIB 없이 만듭니다.
   - B5: 묶음과 B3 객체를 넣은 뒤에만 합니다. 판정 기준은 LIS 가 아니라 공통 기호 주소·크기·정렬이 원본과 같고 L1 결과가 바뀌지 않는 것입니다.
6. B1 결과(2026-10-08, 고친 `l2_coverage.py` → `09_validation/reconstruction/s6-l2-coverage-20261008-b1.json`; 이전 결과 파일은 그대로 둠):
   - 조건부 배치 7 개가 바이트와 맞았습니다: ddm 0x1d13e8, fp_support 0x1d14dc·i386_init 0x1d14e0·intr 0x1d14e4, pmap 0x1d163c·trap 0x1d1640·vm_machdep 0x1d1644. PCexception·PCresume 는 앞의 키맵 둘째 사본(주인 미정)이 자리를 차지하고 있어 이 규칙으로는 배치되지 않습니다(바이트는 0x1d5c56·0x1d5c5a 에서 맞음, 항목 4). 키맵 주인이 정해지면 다시 돌립니다.
   - libgcc `__const` 256 B(0x1d68b0)가 `bit_length` 표와 같아 넣었습니다.
   - `__TEXT,__const` 남은 빈 곳: 1,297 B 중 0 아닌 766 B, 정렬로 설명 안 되는 구간 5(0x1d1276 14 B, 0x1d58e4 892 B, `_IODMAStatusStrings` 56 B, libDriver 판 160 B, objc 판 172 B; python 합 7+541+23+105+90 = 766). `__text`·`__data`·`__bss`·기호·문자열 숫자는 plan 396 결과와 같습니다.
   - 공통 기호 흉내(처음 언급 순): 원본 417, 언급 406, LIS 400, 어긋남 6(`_boottime`·`_callout`·`_master_cpu`·`_inode_list`·`_iuniqtime`·`_in_interfaces`), 언급 없음 11 — 항목 0 (j)·4 와 같습니다.
7. B2 결과(2026-10-08, 실기 gcds, `/bin/cc`(cc-744.13)·`/bin/ld`; 원문·스크립트·출력 `08_build/runs/tools/probe/l2b2/`(run.sh), 해석은 호스트 python `macho_obj`):
   - **B2-1 공통 기호 순서: 가설과 같습니다.** c1a.o(기호표: `_za` COMMON·`_zb` UNDF·`_zc` COMMON·`_zd` UNDF), c1b.o(`_zd` 정의·`_yy`·`_zb`·`_zz` COMMON), c1c.o(`_ww` COMMON·`_zz` UNDF)를 a·b·c 순으로 링크하면 `__common` 이 za 0x4010·zb 0x4014·zc 0x4018·yy 0x401c·zz 0x4020·ww 0x4024, c·b·a 순이면 ww·zz·yy·zb·za·zc 입니다. 곧 "링크 순서에서 처음 언급(UNDF·COMMON 가리지 않음)한 객체, 그 객체 안에서는 기호표 순" 이고, 강하게 정의된 `_zd` 는 `__data` 에 남습니다. (in.c 의 `_in_interfaces`·`_ipintrq` 순서는 이 규칙으로 설명되지 않아 미해결로 남깁니다.)
   - **B2-2 `ld -r` 묶음 정렬: 가설과 같습니다.** `ld -r` 로 a2c.o(정렬 2)·a2m.o(`.align 4`)를 묶은 lib2.o 의 `__text` 정렬은 4 이고, a2x.o(9 B) 뒤에 묶음을 링크하면 묶음이 0x3fe0 으로 가며 `00` 7 B 가 끼입니다(따로 링크하면 a2c 가 0x3fdc). 원본 HashTable 앞 12 B 틈과 같은 꼴입니다.
   - **B2-3 GCC 2.7:** 참조 없는 `static const` 는 `.c` 와 `.m` 모두 객체에 남습니다(s3.o `__const` 정렬 2 = "swapfs\0" + `00` + `04 00 00 00`, int 가 오프셋 8; s3m.o `__const` 정렬 0 = 6 B). 원본 0x1d1276 은 "swapfs\0" 뒤 int 가 오프셋 10 이고 시작이 4 B 정렬이 아니므로, 한 C 파일의 두 static const 로는 이 꼴이 나오지 않습니다(두 객체이거나 다른 꼴; 미정). 호출되지 않는 `static __inline__` 함수의 문자열도 객체에 남습니다(t3n.o: 본문 없이 문자열만; `-fwritable-strings` 이면 `__data`, 아니면 `__cstring`). 한 번 인라인된 경우 문자열은 한 벌입니다(t3·t3w).
   - **B2-4 vers_string(실기 `/usr/bin/vers_string`, 1,607 B, 읽기만):** `-l` → `static const char SGS_VERS[160] = "@(#)LIBRARY:…\n";`, `-c` → `const char SGS_VERS[160] = "@(#)PROGRAM:…\n";` 와 `const char VERS_NUM[10] = "<rev>";`. 원본의 기호 없는 libDriver 160 B(정적)·`_objc_VERS_STRING` 160 B·`_objc_VERS_NUM`(10 B + 다음 객체 정렬 2 B)과 맞습니다(objc 쪽 이름은 바꾼 꼴).
   - **B2-6 데이터만 있는 `.m`:** d6.m(클래스 없음)은 `__OBJC` 절을 내지 않고 `__data`·`__cstring` 만 냅니다 — 원본 모듈 76 에 SCSIGlobals·globaldata 가 없는 것과 맞습니다.
   - 다음: B3(데이터만 있는 객체). 참조 빌드처럼 libDriver(끝에 vers.o)·libobjc(`*.o` 순)를 `ld -r` 로 묶는 것은 링크 계획에서 정합니다.
8. B3 진단 결과(2026-10-08, 07 손대지 않음; scratch 사본을 07 사본 경로에 두고 이웃 객체의 l2_build_forms 꼴로 빌드 — scratchpad 도구 `diag_form.py`·`diag_k07.py`; L1 json `09_validation/reconstruction/s6p397-*-l1-*.json`). 모두 **OBJECT_MATCH**:

| 객체(진단 경로) | run | 바탕 | 고친 것 |
|---|---|---|---|
| ufs_tables (bsd/ufs/ufs_tables.c) | s6p397-ut1 | NeXTMach ufs/ufs_tables.c | 없음 |
| counters (kern/counters.c) | s6p397-ct2 | Mach4 kern/counters.c | `#include <mach_counters.h>` 한 줄(07 에 없음; MACH_COUNTERS 는 `<kern/counters.h>` → `<mach/features.h>`) |
| machdep_call (machdep/i386/machdep_call.c) | s6p397-mc1 | Darwin machdep/i386/machdep_call.c | 없음 |
| dma (driverkit/libDriver/dma.c) | s6p397-dm1 | Darwin driverkit-1 libDriver/dma.c | 없음 |
| SCSIGlobals (driverkit/libDriver/Kernel/SCSIGlobals.m) | s6p397-sg1 | Darwin driverkit-1 libDriver/Kernel/SCSIGlobals.m | 없음 |
| objc-globaldata (objc-runtime/objc-globaldata.m) | s6p397-gd1 | Darwin objc/objc-globaldata.m | 없음(SHLIB 정의 안 함) |
| tty_conf (bsd/kern/tty_conf.c) | s6p397-tc1 | NeXTMach bsd/tty_conf.c | `nullioctl` 함수 뺌(07 tty.c 가 정의, 원본 0x111bf4) |
| uipc_proto (bsd/kern/uipc_proto.c) | s6p397-up1 | NeXTMach bsd/uipc_proto.c | 없음 |
| vfs_conf (bsd/vfs/vfs_conf.c) | s6p397-vc1 | NeXTMach bsd/vfs_conf.c | 6 번 "swapfs"·`swapfs_vfsops`, 빈 항목 7–19(20 항목) |
| in_proto (bsd/netinet/in_proto.c) | s6p397-ip1 | NeXTMach netinet/in_proto.c | ICMP 와 raw 사이 IGMP 항목(Darwin in_proto.c:132 꼴) |
| param (conf/param.c) + confdep.h | s6p397-pm2 | NeXTMach conf/param.c | `hz`·`tick`·`tickadj` 와 `<machine/param.h>` 뺌(07 mach_clock.c 가 정의), `nclist = 216`(식 모름), 생성 머리 confdep.h `MAXUSERS 8`(nport 42·ncallout 184·nchsize 308·ncsize 140 과 맞음) |
| init_sysent (bsd/kern/init_sysent.c) | s6p397-is3 | NeXTMach bsd/init_sysent.c | 항목 23·52·139·147–154·174–183 을 원본대로, 끝 181 항목 뺌(184 항목) |
| conf (bsd/dev/i386/conf.c) | s6p397-cf1 | 원본 바이트로 작성(D024); 칸 배치·주석은 Darwin bsd/dev/i386/conf.c, 구조는 SDK `<sys/conf.h>`(6·11 필드) | Darwin 의 isdisk·chrtoblk 등 함수는 원본에 없음 |
| ioconf (conf/ioconf.c) | s6p397-io1 | NeXTMach config mkioconf.c 의 `pseudo_inits` 꼴 | {32, pty_init}, {1, venip_config}, {0, 0} |
| vers (conf/vers.c) | s6p397-vk1 | 원본 문자열; 꼴은 Darwin conf/tools/newvers 와 같은 네 정의 | — |
| objc_vers (objc-runtime/objc_vers.c) | s6p397-vo1 | vers_string -c + Darwin objc common.make:201–203 의 sed | — |
| libDriver vers (driverkit/libDriver/vers.c) | s6p397-vd1 | vers_string -l(Darwin libDriver Makefile:612) | 기호가 정적이라 `--place __TEXT,__const=0x1d647c` 로 비교 |

   진단 경로는 임시입니다. 07 에 둘 경로·이름(특히 param·ioconf·vers·confdep.h 같은 config 생성물, conf.c 의 출처 표기)은 바이트로 정해지지 않으므로 사용자에게 묻습니다. 링크 위치는 원본 데이터 순서로 정해집니다(예: init_sysent 는 init_main 과 kern_acct 사이, objc_vers 는 libobjc `*.o` 의 끝, libDriver vers 는 libDriver 묶음 끝).
9. B4 진단 결과(2026-10-08, 07 손대지 않음, scratch 사본 + `diag_form.py`):
   - **rtc**(s6p397-rt1): 07 rtc.c 에서 참조 없는 `static unsigned char rtc[RTC_NREG];` 한 줄을 빼면 **OBJECT_MATCH**(text 1,800 B·data 52 B, 함수 8 MATCH, `__bss` 없음). 기준선은 P(`__bss` unverified)였습니다. 원본 `__bss` 자리(3 B)와도 맞습니다.
   - **active_mfsbufs·mfsbuf_lock**(s6p397-mf1): 07 mfs_prim.c 에 Darwin kern/mapfs.c:132 `lock_data_t mfsbuf_lock;`(MACH_NBC 묶음 첫 줄)과 :1081 `int active_mfsbufs = 0;`(07 의 `extern int nmfsbuf;` 앞, Darwin 과 같은 자리)을 넣으면 **OBJECT_MATCH**, `__data` 97 → 104 B 로 `_active_mfsbufs` 가 0x1defb4 에 옵니다. 둘 다 Darwin 에서도 정의만 있고 쓰이지 않습니다.
   - **pmsgbuf**(s6p397-sl1): 07 subr_log.c 의 `struct msgbuf *pmsgbuf;` 를 `= 0` 으로 초기화하면 **OBJECT_MATCH**, `__data` 4 B 가 0x1dac14.
   - **nrnode**: nfs_subr.c 의 `extern int nrnode;` 를 `int nrnode = 0;` 로 바꾸는 꼴(s6p397-nr1: `__data` 0x1dc2c0 부터 671 B, 기준선과 같은 P 상태)과 nfs_server.c 끝에 `int nrnode = 0;` 을 붙이는 꼴(s6p397-nr2: OBJECT_MATCH, 868 B) 둘 다 원본 바이트와 맞습니다 — **바이트로 정해지지 않습니다**(NeXTMach 은 next/machdep.c 에 정의).
   - **키맵 둘째 사본**(882 B, 0x1d58e4): `#import <bsd/dev/i386/PCKeymap.c>` 를 kbd_entries.m(s6p397-kp2)이나 PCinit.c(s6p397-kp3)에 넣으면 둘 다 `--place __TEXT,__const=0x1d58e4` 로 **OBJECT_MATCH** 입니다. PCPointer.m(s6p397-kp1)에 넣으면 `__OBJC,__class_names` 가 115 → 81 B 로 바뀌어 맞지 않습니다. 둘 중 어느 것인지는 **바이트로 정해지지 않습니다**.
   - **"swapfs" const 14 B**(0x1d1276): B2-3 대로 한 C 파일의 두 static const 로는 이 꼴(int 가 오프셋 10)이 나오지 않으므로, 정렬 0 인 char 배열을 내는 객체 하나와 정렬 2 인 int 4 를 내는 객체 하나로 보입니다. 둘 다 참조가 없고, 이름·주인을 알려 주는 원문이 없습니다 — **바이트로 정해지지 않습니다**.
   - **if_vtrip add_sr 둘째 문자열 37 B**(0x1db91b, `__data` 끝): B2-3 대로 호출되지 않는 `static __inline__` 함수의 문자열은 남고, 한 번 인라인된 함수의 문자열은 한 벌입니다. 원본은 참조되는 첫 벌(`__data` 처음)과 참조 없는 둘째 벌(끝)을 가지므로, 같은 문자열을 가진 두 번째 정의가 파일 뒤쪽에 있었던 것으로 보이나 그 꼴은 **바이트로 정해지지 않습니다**. 이 37 B 가 없으면 링크에서 뒤 객체(raw_usrreq 등)의 `__data` 주소가 37 B 앞당겨집니다.
10. 사용자 결정이 필요한 것(B3·B4 결과로 좁힘; 07 반영과 B5 는 결정 뒤):
   1. 데이터만 있는 객체 17 개의 07 경로·이름, 특히 config 생성물(param.c·confdep.h·ioconf.c·vers.c)과 판 객체(objc_vers.c·libDriver vers.c), 그리고 conf.c(원본 바이트로 작성, Darwin 칸 배치)의 출처 표기.
   2. nrnode: nfs_subr.c 정의 또는 nfs_server.c 끝.
   3. 키맵 둘째 사본: kbd_entries.m 또는 PCinit.c.
   4. "swapfs" const 14 B 와 if_vtrip add_sr 둘째 문자열 37 B: 근거 없는 꼴로 작성할지(어느 파일에, D024 표시), 아니면 링크 단계에서 빈 곳으로 남기고 비교에서 따로 다룰지.
11. B5 미리 보기(scratch, 기록·07 변경 없음; scratchpad `commonsim3.py`): 재빌드 객체 385 에 B3 진단 객체 17 을 원본 데이터 순서 자리에 넣고 rtc·mfs_prim·subr_log 를 B4 사본으로 바꿔 "처음 언급 순" 을 흉내 내면 언급 408/417, LIS 402 입니다. `_file`(param)·`_mfsbuf_lock`(mfs_prim)이 제자리에 들어오고, 어긋남은 그대로 6(`_boottime`·`_callout`·`_master_cpu`·`_inode_list`·`_iuniqtime`·`_in_interfaces`), 언급 없음 9(`____xxx_state`·`_nmi_*` 8)가 남습니다. libDriver·libobjc 묶음은 아직 넣지 않았습니다.
12. 사용자 질문(2026-10-08 "4가지는 mach 2.0 이나 darwin 을 참고해서 배치할 수는 없나요?")과 지시("근거없는 두조각도 작성은 해야죠") 뒤 확인:
   - **경로·링크 위치는 Darwin 빌드 목록으로 정해집니다.** Darwin `kernel/conf/files`(:361–363 init_main·init_sysent·kern_acct, :396–399 tty·tty_compat·tty_conf·tty_pty, :403–404 uipc_mbuf·uipc_proto, :131·:134 vfs_bio·vfs_conf, :220–222 in_pcb·in_proto·ip_icmp, :410 conf/param.c, :431–433 ast·counters·exception)과 `files.i386`(:36–38 machdep_call·pcb, :47·:49·:50 autoconf_i386·conf·cons)의 차례가 원본 데이터 순서와 같습니다. Darwin `Makefile.template:232` `LDOBJS=${LDOBJS_PREFIX} ${OBJS} subr_prof.o ioconf.o ${LDOBJS_SUFFIX}`, `Makefile.i386:68–69`(PREFIX = libc 객체, SUFFIX = libDriver·libobjc 묶음), `Makefile.template:381–387`(newvers 로 vers.c 를 만들어 `${LDOBJS} $(MACH_OFILES) vers.o ${LIBS}` 순으로 링크)은 원본 순서(libc → 커널 객체 → ioconf → libDriver → libobjc → mach 사용자 스텁 → vers → libcc)와 같습니다. 그래서 07 경로: `bsd/kern/init_sysent.c`·`bsd/kern/tty_conf.c`·`bsd/kern/uipc_proto.c`·`bsd/vfs/vfs_conf.c`·`bsd/netinet/in_proto.c`·`kern/counters.c`·`machdep/i386/machdep_call.c`·`bsd/dev/i386/conf.c`·`conf/param.c`(Darwin·NeXTMach 모두 conf/param.c), `bsd/ufs/ufs_tables.c`(07 의 ufs 는 NeXTMach 처럼 평평; Darwin 은 ffs/ffs_tables.c), libDriver `driverkit/libDriver/dma.c`·`driverkit/libDriver/Kernel/SCSIGlobals.m`, `objc-runtime/objc-globaldata.m`. 빌드 생성물(config 의 ioconf.c·confdep.h, newvers 의 vers.c, vers_string 의 objc_vers.c·libDriver vers.c)의 07 위치는 plan 398 에서 정합니다(`07_kernel/generated/` 최상위는 gen_config_headers.py 가 쓰는 머리 자리이므로 그대로 쓰지 않음).
   - **nrnode·키맵 둘째 사본은 참조로 정해지지 않습니다.** Darwin 에는 nrnode 가 없고 NeXTMach 은 next/machdep.c 에 정의하나 4.2 machdep.c 의 `__data`(0x1e227c)는 다른 자리입니다. 키맵은 Darwin·NeXTMach 어디에서도 EventSrcPCKeyboard.m 밖에서 PCKeymap.c 를 들이지 않습니다(grep). Darwin files.i386 :68–72 차례(PCPointer.m·EventShmemLock.s·kbd_entries.m·PCinit.c)도 둘 다 같은 자리라 가르지 못합니다.
   - **근거 없는 두 조각의 꼴(실기 탐침, `l2b2/run2.sh`)**: 단독 `static const char x[] = "swapfs";` 는 `__const` 7 B 정렬 0, 단독 `static const int y = 4;` 는 4 B 정렬 2 → 원본 14 B 는 "char 배열을 낸 객체" 다음 "int 를 낸 객체" 꼴과 정확히 맞습니다(7 + 채움 3 + 4). 데이터 뒤에 호출되지 않는 `static __inline__` 함수(문자열 포함)를 두면 `-fwritable-strings` 에서 그 문자열이 `__data` 끝에 옵니다(t6w.o: `01 00 00 00` 뒤 "add_sr: …") → if_vtrip 끝 37 B 꼴과 맞습니다. 링크 순서상 char 배열은 netif 뒤 첫 const 자리, int 는 그 뒤 kern_server 앞(사이 객체 중 swapfs.c 가 이름과 맞음; swapfs.c 뒤 kern_server 앞 객체 66).

## 398. S6-6 세부 계획 — L2-B 07 반영: 데이터만 있는 객체 17 과 기존 객체 8 고침(plan 397·D058; 코딩 전, 2026-10-08)

0. 근거: plan 397 항목 8(B3 진단 17 OBJECT_MATCH), 9(B4), 12(Darwin 빌드 목록), D058(nrnode = nfs_subr.c, 키맵 = PCinit.c, 근거 없는 두 조각 = swapfs.c·ufs_alloc.c·if_vtrip.c 끝). 추가 진단(이번 세션, 07 손대지 않음): if_vtrip 끝에 호출되지 않는 static inline(문자열 하나) → `__data` 208 B **OBJECT_MATCH**(s6p397-vt1); swapfs.c 에 `static const char swapfs_const_name[] = "swapfs";` → `--place __TEXT,__const=0x1d1276` 에서 바이트 0 차이, 등급 P 그대로(`__bss` 만 미확정, s6p397-sw1); ufs_alloc.c 의 `#endif QUOTA` 뒤에 `static const int ufs_alloc_const_4 = 4;` → `--place …=0x1d1280` **OBJECT_MATCH**(s6p397-ua2; 처음 시도 ua1 은 `#if QUOTA` 안에 넣어 빠졌음).
1. 새 07 파일(내용 = plan 397 진단 사본; 머리·출처는 D013·D030·D024 규칙):

| 07 경로 | 바탕·라이선스 처리 | 비고 |
|---|---|---|
| src/bsd/kern/init_sysent.c | NeXTMach bsd/init_sysent.c, 고지 유지, 고친 줄 plan 397 표시 | 184 항목 |
| src/bsd/kern/tty_conf.c | NeXTMach bsd/tty_conf.c(표 부분만), 고지 유지 | nullioctl 뺌 |
| src/bsd/kern/uipc_proto.c | NeXTMach bsd/uipc_proto.c 그대로 | |
| src/bsd/vfs/vfs_conf.c | NeXTMach bsd/vfs_conf.c, 고지 유지 | swapfs 항목·20 항목 |
| src/bsd/netinet/in_proto.c | NeXTMach netinet/in_proto.c, 고지 유지 | IGMP 항목 |
| src/bsd/ufs/ufs_tables.c | NeXTMach ufs/ufs_tables.c 그대로 | |
| src/conf/param.c | NeXTMach conf/param.c, 고지 유지 | hz·tick·tickadj·machine/param.h 뺌, nclist 216 |
| src/kern/counters.c | Mach4 kern/counters.c, 고지 유지 | include 한 줄 |
| src/machdep/i386/machdep_call.c | Darwin kernel/machdep/i386/machdep_call.c, APSL 고지 유지 | 그대로 |
| src/bsd/dev/i386/conf.c | 원본 바이트로 작성(D024); 칸 배치·주석 꼴만 Darwin bsd/dev/i386/conf.c | 프로젝트 작성 |
| src/driverkit/libDriver/dma.c | Darwin driverkit-1 libDriver/dma.c — D030(Darwin 전용, kernel/machdep 밖, Mach4·NeXTMach 짝 없음): 프로젝트 작성, "nearly the same as Darwin 0.1 …" | 그대로 |
| src/driverkit/libDriver/Kernel/SCSIGlobals.m | 위와 같음(D030) | 그대로 |
| src/objc-runtime/objc-globaldata.m | Darwin objc/objc-globaldata.m — D030·D047 프로젝트 작성, "nearly the same as Darwin 0.1 objc-1 objc-globaldata.m", 머리 주석 교체·Darwin 고지 없음(선례: PROVENANCE 의 objc-globaltext.m·objc-errors.m 행) | 그대로(SHLIB 없음) |
| src/conf/ioconf.c, src/conf/vers.c | 빌드 생성물(config·newvers 출력 꼴)을 원본 바이트로 씀; 07_kernel/generated/README 에 MIG C 파일처럼 "src 옆에 둔 생성물" 로 적음 | |
| src/objc-runtime/objc_vers.c, src/driverkit/libDriver/vers.c | vers_string 출력 꼴(실기 /usr/bin/vers_string 확인)을 원본 바이트로 씀 | |
| generated/confdep.h | `06_reconstruction/config_options.tsv` 에 `maxusers MAXUSERS confdep.h 8 confirmed`(근거: param 값) 행 → gen_config_headers.py 로 생성 | meta_features.h 도 confdep.h 를 들이게 됨(아래 3) |

2. 기존 07 파일 고침(줄마다 plan 397/398 표시): rtc.c(참조 없는 `rtc[RTC_NREG]` 뺌), mfs_prim.c(Darwin mapfs.c:132·:1081 두 줄), subr_log.c(`pmsgbuf = 0`), nfs_subr.c(`int nrnode = 0;`, D058), PCinit.c(`#import <bsd/dev/i386/PCKeymap.c>`, D058; 마지막 #import 뒤), swapfs.c·ufs_alloc.c·if_vtrip.c(D058 근거 없는 조각, "no evidence" 머리 주석).
3. 빌드·확인:
   - confdep.h 가 meta_features.h(모든 컴파일의 `-imacros`)에 들어가 `MAXUSERS` 가 모든 번역 단위에 정의되므로(07·참조 머리 grep 으로 MAXUSERS 쓰는 곳 확인), **385 객체 전체를 다시 빌드**해(plan 394 l2_rebuild 묶음) L1 이 기준선과 같은지 봅니다. 바뀌어야 하는 객체(위 2 의 8 개)만 기대한 대로 바뀌어야 합니다(rtc P→A, 나머지 등급 그대로).
   - 새 17 객체는 이웃 객체의 l2_build_forms 꼴로 07 에서 빌드(진단과 같은 꼴), L1 OBJECT_MATCH(libDriver vers 는 `--place`), `cc -M` 의존이 모두 07(plan 395 기준).
   - 그 뒤 `l2_coverage.py` 를 새 객체까지 넣어 다시 돌려 `__const`·`__data` 빈 곳이 정렬 채움만 남는지, 정의 없는 원본 이름이 공통 기호(B5 대상)만 남는지 봅니다.
4. 기록: PROVENANCE(새 17 + 고친 8), MODIFICATIONS, 증거 파일(새 객체마다 x86-<name>.md·.diff, 고친 객체는 기존 파일에 덧붙임), 데이터만 있는 객체는 text 범위가 없으므로 새 표 `06_reconstruction/objects_data.tsv`(object·arch·binary_sha256·sections(절=시작+크기)·source·build·grade·evidence)를 만들고 l2_forms·l2_coverage 가 읽게 고칩니다. rtc 의 등급 변경은 objects_partial → objects_confirmed 이동으로 기록합니다.
5. 하지 않는 것: B5(공통 기호 선언 고침)와 링크 — 이 반영 뒤 다음 계획.
6. codex 교차검토(kj95ge9b3, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 진단 37 보고를 다시 계산해 모두 같음, B3 17 OBJECT_MATCH | (재계산은 codex 쪽; 나는 각 run 직후 L1 json 을 직접 읽어 이 세션 기록에 적음) | ⏭️ 행동 바뀌지 않음; 숫자 37 은 계획에 옮기지 않음 |
| in_proto.c 의 IGMP 항목은 Darwin in_proto.c:132 꼴이므로 출처는 NeXTMach+Darwin 섞임으로, in_bootp 선례(PROVENANCE:1011)처럼 | PROVENANCE.tsv 1011 행 읽음: `nextmach+darwin01`, Darwin 부분 줄 범위·APSL 고지 | ✅ (내 줄은 Darwin 의 `rip_usrreq` 대신 원본 바이트대로 `raw_usrreq` 이지만 꼴은 Darwin 에서 옴) → in_proto.c 는 섞임 출처, IGMP 줄에 Darwin 표시, APSL 고지 추가 |
| conf.c 는 D030 아님(두 참조에 짝 있음), D024 작성으로 됨 | 계획 표에 이미 D024 작성으로 적음 | ✅ 그대로 |
| generated/confdep.h 도 PROVENANCE 행 필요 | PROVENANCE 의 `07_kernel/generated/` 행 31, 예 mach_kdb.h 행(`generated` · gen_config_headers.py) | ✅ 추가 |
| MAXUSERS·confdep 를 쓰는 곳이 07·기준선 스테이징에 없음 | `grep -rln "MAXUSERS\|confdep" 07_kernel` 0 건; SDK rusers.h `#define MAXUSERS 100` 은 07 이 쓰지 않음(grep "rusers" 07 0 건) | ✅ 전체 재빌드는 확인용으로 그대로 함 |
| 빌드 대상 402(385+17) | python 385+17 = 402 | ✅ |
| objects_* 표를 직접 읽는 도구는 l2_forms.py:128 뿐 | `grep -rn "objects_confirmed\|objects_partial" 10_tools --include=*.py` → l2_forms.py:6·:128 | ✅; 간접 소비자(l2_baseline·l2_rebuild·l2_coverage)도 고쳐야 함 |
| 대안: 새 표 대신 기존 표에 text 범위 빈 칸 | (기존 표를 읽는 coverage·기록 도구가 text 범위를 숫자로 쓰는지 전수 확인 안 함) | ⚖️ 받지 않음 — 기존 A/P/L 집계가 text 범위로 계산되므로 빈 칸이 다른 도구를 깨뜨릴 위험이 있어 **새 표 `objects_data.tsv`** 유지, 대신 l2 도구 넷을 명시적으로 고침 |
| 명시 배치가 넷 필요: PCinit 0x1d58e4, swapfs 0x1d1276, ufs_alloc 0x1d1280, libDriver vers 0x1d647c | 이 세션 진단에서 넷 모두 `--place` 로만 확인됨(kp3·sw1·ua2·vd1) | ✅ 재빌드 확인 도구에 행별 배치 넣음 |
| l2_coverage.py:54 가 `same_as_baseline` 을 요구해 의도한 변경을 거부 | l2_coverage.py:54 `assert x.get('same_as_baseline') and not x.get('problem'), n` | ✅ 새 재빌드 결과를 읽도록 선택 규칙 고침 |
| rtc 를 표 사이로 옮기면 행 번호 40 개가 바뀜 | python: rtc 는 forms 354 행(objects_partial), confirmed 314 행 → 315 로 넣으면 315–354 의 40 행이 밀림 | ✅ 새 재빌드부터는 행 번호가 아니라 **object 이름**으로 잇고, 이전 결과 파일은 그대로 둠 |
| `x86-dma` 는 이미 machdep DMA 객체·증거 이름 | objects_partial.tsv `x86-dma` 행, 06_reconstruction/evidence/x86-dma.md 있음 | ✅ 새 이름 `x86-libDriver_dma` |
| 선언 순서 유지: nrnode 는 nfs_subr `__data` 오프셋 0, active_mfsbufs 는 100 | python: s6p397-nr1 객체 `_nrnode` 오프셋 0; 0x1defb4−0x1def50 = 100 | ✅ 진단 사본의 줄 자리를 그대로 옮김 |
| 생성 .c 는 "생성기 출력 꼴을 원본 바이트로 다시 쓴 것" 으로 적고 gen_config_headers.py --check | generated/README 의 MIG 문구는 실제 도구 출력용 | ✅ |

7. 고친 순서(코딩): (a) 07 새 파일 17·고친 파일 8·config_options.tsv 행 → gen_config_headers.py 로 confdep.h·meta_features.h, `--check`; (b) 새 표 objects_data.tsv 와 l2 도구 고침(object 이름 키, 행별 명시 배치, 데이터만 있는 객체의 링크 자리); (c) 402 객체 재빌드·L1·`cc -M` 의존 확인; (d) l2_coverage 다시; (e) 기록(PROVENANCE·MODIFICATIONS·증거·objects 표·README). 각 단계 끝에 결과를 이 절에 적습니다.
8. 단계 (a) 결과(2026-10-08): 07 새 파일 17(위 표 경로; 내용 = plan 397 진단 사본, 머리만 선례대로: D030·D047 파일은 머리 교체, conf.c·생성물 꼴 넷은 프로젝트 머리, in_proto.c 는 in_bootp 선례대로 NeXTMach 머리 뒤에 Darwin APSL 고지와 "plan 397 (Darwin)" 표시), 고친 파일 8(백업 scratchpad `bak398/`; diff 로 바뀐 줄 수 rtc 2·mfs_prim 2·subr_log 2·nfs_subr 2·PCinit 1·if_vtrip 13·swapfs 7·ufs_alloc 7 — 진단 사본에서 주석 문구만 다듬음). config_options.tsv 에 `maxusers MAXUSERS confdep.h 8 confirmed` 행(53 → 54 줄; python: NPROC 84, nport 42, ncallout 184, NINODE 280, nchsize 308, ncsize 140), gen_config_headers.py 로 `generated/confdep.h`(`#define MAXUSERS 8`)와 meta_features.h(`#import <confdep.h>` 한 줄 추가) 생성, `--check` 0.
9. 단계 (b)·(c) 결과(2026-10-08):
   - (b) 도구: `10_tools/reconstruction/l2_forms_s6p398.py` → `06_reconstruction/l2_build_forms-s6p398.tsv`(402 행: 1–385 행은 기존 forms 와 같음(python 비교 True), 386–402 행 = 새 17 객체, 이웃 템플릿 꼴에서 -c·-o 만 바꿈)와 `06_reconstruction/l2_expect-s6p398.json`(기대 25: 바뀐 8 + 새 17, 명시 배치 PCinit 0x1d58e4·swapfs 0x1d1276·ufs_alloc 0x1d1280·libDriver vers 0x1d647c). `l2_rebuild.py` 에 env `L2_FORMS`·`L2_EXPECT`(기대 행은 `--place` 를 주고 판정·이유를 기대와 비교, 나머지는 기준선 L1 과 비교) 추가(백업 scratchpad `bak398/l2_rebuild.py`, 306 → 331 줄). 데이터만 있는 객체 표(`objects_data.tsv`)와 l2_coverage 고침은 (d)·(e) 에서.
   - (c) 재빌드(07 에서, run s6l1-g6a·g2aa·g5a·g3a·g4a·g2ba·g1a; 결과 `09_validation/reconstruction/s6-l1-<G>-<run>.json`): 객체 402(행 1–402 모두), 기준선과 같음 377, 기대와 맞음 25(새 17 모두 OBJECT_MATCH, rtc P→OBJECT_MATCH, mfs_prim·subr_log·if_vtrip·PCinit·ufs_alloc OBJECT_MATCH, nfs_subr·swapfs 는 `__bss: unverified` 만), 실패 0, 문제 0, 묶음 대 단독 스테이징 의존 차이 0, **`cc -M` 의존이 07 밖인 객체 0**(python 집계). confdep.h 가 모든 컴파일에 들어갔지만 기존 377 객체는 바뀌지 않았습니다.
10. 단계 (d) 결과(2026-10-08): `l2_coverage.py` 에 env `L2_COVER=s6l1`(plan 398 재빌드 402 행을 읽고 기준선과 같거나 기대와 맞는 행만 받음)과 데이터만 있는 객체의 링크 자리(같은 절에서 바로 앞에 놓인 text 객체 뒤)를 넣음(백업 `bak398/l2_coverage.py`, 353 → 383 줄). 옛 모드로 다시 돌린 결과는 `s6-l2-coverage-20261008-b1.json` 과 키마다 같음(새 키 `link_keys_data_only` 만 빈 값). 새 결과 `09_validation/reconstruction/s6-l2-coverage-20261008-s6p398.json`:
   - `__TEXT,__const` 빈 곳 10 B 모두 `00`, 정렬로 설명 안 되는 구간 **0**(조건부 배치 9 개 모두 바이트 일치 — PCexception 0x1d5c56·PCresume 0x1d5c5a 포함). `__DATA,__data` 빈 곳 168 B 모두 `00`, 구간 **0**. `__text` 는 그대로 HashTable 앞 12 B 하나(libobjc `ld -r` 묶음 정렬, B2-2).
   - `__bss`: 객체 합 12,422 B, 원본 12,432 B, 차이 10 B = 정렬 채움(python: 12,402 + bios 16 + SCSIGenericKern 4 = 12,422).
   - 기호: 정의 없는 원본 이름 **25**(모두 `__common`), 중복·추가·N_PEXT 0. `__cstring` 원본 문자열 중 객체가 내지 않는 것 **0**. ObjC 리터럴 절 차이 0.
   - 공통 기호 흉내: 언급 408/417, LIS 402, 언급 없음 9(`____xxx_state`·`_nmi_*` 8) — B5 대상.
11. 단계 (e) 기록(2026-10-08; 백업 scratchpad `bak398/`):
   - `06_reconstruction/objects_data.tsv` 새 표 17 행(재빌드 L1 의 절 배치, build 열에 run·행·`--place`). `06_reconstruction/README.md` 에 표 설명 한 단락.
   - rtc: objects_partial(72 → 71 줄) → objects_confirmed(315 → 316 줄), 등급 A. functions.tsv 의 rtc 8 행 검증 문구를 A(`s6l1-g1a-l1-354.json`)로. functions.tsv 의 07 줄 번호 인용 68 개를 옮김(mfs_prim·PCinit·swapfs·ufs_alloc 줄이 늘어서; 옛 줄과 새 줄 내용이 모두 같음을 python 으로 확인, 행 수 4,763 그대로).
   - PROVENANCE 1,028 → 1,046 행(새 17 + confdep.h; 바뀐 8 행은 SHA-256 과 plan 398 고침을 적음; in_proto.c 는 `nextmach+darwin01`, APSL 고지). MODIFICATIONS 501 → 526 줄(25 항목). 증거: 새 객체마다 `x86-<name>.md`·`.diff`(17 쌍), 바뀐 8 객체는 증거 끝에 "plan 397·398 고침" 절, diff 다시 만듦(PCinit 은 새 `x86-PCinit.diff`). `07_kernel/generated/README` 에 생성물 꼴 C 파일 넷과 confdep.h 설명.
   - text 커버리지(python): A 622,696 B 73.13 %, P 227,802 B 26.76 %, L 340 B 0.04 %, 합 99.93 %, 남은 598 B(모두 정렬 `00`).
12. 다음: B5(공통 기호) — 남은 원본 공통 이름 25 개의 정의 자리와 어긋남 6·언급 없음 9 를, libDriver·libobjc `ld -r` 묶음을 넣은 링크 순서로 다시 흉내 낸 뒤 정합니다(별도 계획, codex 검토 먼저).

## 399. S6-7 세부 계획 — L2 시험 링크(진단; 실제 `__common` 배치를 얻어 B5 를 정하기 위함, 07 변경 없음; 코딩 전, 2026-10-08)

0. 사실(이번 세션 python·실기 읽기):
   - 원본 Mach-O(python): filetype 2(EXECUTE), cpu 7 sub 3, flags 0x1, ncmds 7, sizeofcmds 2,152; 세그먼트 `__PAGEZERO` 0–0x1000, `__TEXT` 0x100000 크기 0xda000(파일 0–892,928), `__DATA` 0x1da000 0x1e000, `__OBJC` 0x1f8000 0x12000, `__LINKEDIT` 0x780000 0x18ee0(파일 1,015,808, 102,112 B); SYMTAB symoff 1,015,808 nsyms 3,751 stroff 1,060,820 strsize 57,100; UNIXTHREAD flavor 0xffffffff count 16, eip 0x1860dc(`_start`), cs 0xf, ss·ds·es 0x17; 파일 1,117,920 B. 기호는 외부 3,651(구역) + 절대 100 뿐이고 이름순(지역 기호 없음).
   - Darwin 0.1 링크 꼴: `conf/Makefile.i386:55–59` `LDFLAGS=-e _start -segaddr __TEXT ${RELOC} -segaddr __LINKEDIT ${SYMADDR} -segalign 0x1000 -force_cpusubtype_ALL -u __muldi3`, `LIBS= -lcc`; `Makefile.template:386–387` `${LD} -static ${LDFLAGS} ${FVMFILE_LDFLAGS} ${LDOBJS} $(MACH_OFILES) vers.o ${LDFLAGS2} ${LIBS}`; `LDOBJS = libc 객체 + OBJS + subr_prof.o + ioconf.o + libDriver 묶음 + libobjc 묶음`(plan 397 항목 12). libDriver 묶음 = `$(LD) -r -o … $(OFILES) vers.o`(driverkit-1/libDriver/Makefile:631; OFILES 의 MD 목록 끝이 IOMallocLow·machdepFuncs, :177–178), libobjc 묶음 = `ld -r -o libkobjc.o …/*.o`(objc/Makefile.postamble:155). 실기 `/lib/libcc.a` SHA-256 = 원본 보관본(bccd689e…2fda5, 77,600 B).
   - 링크 순서(python, plan 398 재빌드 402 객체): text 객체는 원본 text 주소 순. 데이터만 있는 객체 17 중 9 는 원본 데이터 위치로 자리가 하나(init_sysent·vfs_conf·in_proto·ufs_tables·counters·machdep_call·objc_vers 등), 8 은 후보가 여럿이라 Darwin 목록 차례로 정함: tty_conf → tty.c 뒤(files:396–399), uipc_proto → uipc_mbuf 뒤(:403–404), param → ufs_vnodeops 뒤 = ipc_entry 앞(files:410–412 "conf/param.c" 다음 ipc), conf → autoconf_i386 뒤(files.i386:47–50), ioconf → PCemulatePROT 뒤(OBJS 끝, Makefile.template:232; files.i386:77), dma → disk_label 뒤(libDriver KERNEL_CFILES 차례 disk_label·dma·label_subr), SCSIGlobals → SCSIGeneric 뒤(KERNEL_MFILES), objc-globaldata → objc-errors 뒤(`*.o` 이름 차례), libDriver vers → machdepFuncs 뒤(묶음 끝), vers → mach 스텁 끝(vm_write) 뒤.
1. 도구 `10_tools/reconstruction/l2_link.py`(새로; 읽기·준비만):
   - `prepare RID`: plan 398 재빌드 결과(402 행, SHA 확인)와 위 순서 규칙(데이터만 있는 객체 8 개의 자리 표는 도구 안에 근거와 함께 명시)으로 링크 목록을 만들고, 객체를 `08_build/runs/tools/RID-src/objs/` 에 복사(SHA 재확인), `RID.cmd` 를 씀: (1) `/bin/ld -r -o stage/libDriver_kern.o <libDriver 묶음: ioconf 다음부터 machdepFuncs 까지 + libDriver vers>`, (2) `/bin/ld -r -o stage/libkobjc.o <objc-runtime 객체, 원본 text 순 + objc_vers>`, (3) `/bin/ld -static -e _start -segaddr __TEXT 0x100000 -segaddr __LINKEDIT 0x780000 -segalign 0x1000 -force_cpusubtype_ALL -u __muldi3 -o stage/mach_kernel <libc·OBJS·ioconf> stage/libDriver_kern.o stage/libkobjc.o <mach 스텁> <vers.o> -lcc`. 링크 목록·묶음 구성은 json 으로 남김.
   - 묶음 경계: libDriver 묶음은 ioconf 다음 객체(IODevice.m)부터 machdepFuncs.c 까지(원본 text 연속 구간), libobjc 묶음은 HashTable.m 부터 objc-sel.m + objc_vers, mach 스텁은 그 뒤 port_allocate … vm_write.
2. 도구 `10_tools/reconstruction/l2_compare.py`(새로; 읽기만): 링크 결과와 원본을 비교 — Mach-O 머리·로드 명령(세그먼트·절 주소·크기·정렬·플래그, UNIXTHREAD), 절마다 바이트(같지 않은 구간 목록), 기호(이름·값·종류; 원본에 없는 지역 기호는 따로 셈), `__common` 이름별 주소 차이, LINKEDIT(기호·문자열 표 크기). 결과 json `09_validation/reconstruction/s6-l2-link-<RID>.json`.
3. 실행: kr_run 진단 run `s6p399-ln1`(allow-list `/bin/ld` 이미 있음). 링크가 실패하면(미정의 기호 등) 메시지를 그대로 기록하고 멈춥니다.
4. 판단에 쓰는 기대: text·const·data·ObjC 절 바이트는 plan 398 결과대로 같아야 함(재배치 해석은 링크 결과가 실제 값). 다를 것으로 예상하는 곳: `__common` 순서(B5 대상 6+9 이름), 지역 기호(원본은 없음 → `-x` 류 처리 여부는 결과를 보고 다음 계획에서), `__cstring` 문자열 합침 순서. 예상 밖 차이는 모두 목록으로 남김.
5. 하지 않는 것: 07·기록 표 변경, 결과 커널 부팅, B5 고침(이 결과를 근거로 다음 계획).
6. codex 교차검토(klip8umee, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| **어떤 객체도 정의하지 않고 참조만 하는 전역 16 개** 때문에 최종 링크가 미정의 기호로 멈춤 | python: 빠진 원본 공통 이름 25 중 객체가 UNDF 로만 언급 16(`_active_u`·`_cons`·`_cons_tp`·`_cpu_config`·`_kernel_map`·`_master_cpu`·`_mem_region`·`_mem_size`·`_nfsslowlink`·`_num_regions`·`_pgrphash`·`_posix_proc_hash`·`_u_task_zone`·`_u_thread_zone`·`_virtual_avail`·`_virtual_end`), 아무도 언급하지 않음 9(`____xxx_state`·`_nmi_*` 8), COMMON/SECT 로 정의하는 객체 0 | ✅ **계획을 고칩니다**: B5(공통 정의)를 시험 링크 앞의 선행 단계로 |
| 머리 값·Darwin 인용은 맞으나 "자리 하나 9 / 여럿 8" 은 틀림(절 배치만 7/10, 문자열 순서까지 8/9) | 내 계산(ranges399.py, 절 배치만): 하나 7(init_sysent·vfs_conf·in_proto·ufs_tables·counters·machdep_call·objc_vers), 여럿 10 | ✅ 내 숫자가 틀렸습니다(7/10). 고른 자리는 모두 허용 범위 안 |
| files:410–412 는 "param 이 ipc_entry 앞" 만 말하고 ufs_vnodeops 바로 뒤를 말하지 않음; files.i386:77 은 OBJS 끝이 아님(fp_emul 이 뒤) | files 405–412 읽음(uipc_usrreq 뒤 param, 그 뒤 ipc), files.i386 74–80(PCemulatePROT 뒤 fp_emul optional) | ✅ 문구 고침: param 은 원본 데이터 허용 범위(ufs_vnodeops / ipc_init) 안에서 ipc 앞, ioconf 는 Makefile.template:232 `${OBJS} … ioconf.o` 로 OBJS 뒤 |
| libDriver 묶음 안의 strtol(커널 files:127)·IOTokenRing 은 Darwin libDriver 목록에 없음 → 묶음 소속은 추론 | (strtol 의 원본 text 위치가 묶음 구간 안임은 링크 순서 표에서 확인) | ⚖️ 바이트 순서상 그 자리여야 하므로 묶음 안에 둠, "추론" 으로 기록 |
| libobjc 의 objc-zone 은 `*.o` ASCII 순과 다름 | 원본 text: objc-globaltext 0x1cde40 → objc-zone 0x1cdeb0 → objc-load 0x1cdf30 | ✅ 원본 순서를 그대로 씀(이름 순 가정 안 함) |
| 묶음별로 리터럴 포인터 목록을 뒤집으면 메시지 참조 725·클래스 참조 32 슬롯이 맞음 | (계산 안 함) | ⏭️ 시험 링크 결과로 확인 |
| `-lcc` 가 고른 라이브러리는 kr_run 이 해시하지 않음 | kr_run.py ALLOWED_TOOLS·hash 는 도구만 | ✅ 실행 기록에 /lib/libcc.a 해시를 남김(이번 세션 실기 krsha256 = 보관본) |
| EXPECT 는 `stage/` 없이 | kr_run.py:21 "EXPECT <path under stage/>", collect 가 stage/ 를 붙임 | ✅ |
| 앞 RUN 출력을 뒤 RUN 입력으로 쓸 수 있음; RUN 실패해도 다음 RUN 계속, collect 가 거부 | kr_run.py parse_cmdfile(인자는 ARG_RE 만 검사) · 실행 스크립트(상태만 기록) | ✅ |
| 비교 도구: 묶음 중간물도 비교, zero-fill 은 파일 바이트 없음, STAB·지역 기호 구별, LINKEDIT 구조, macho_obj 보강, 공통 주소가 바뀌면 재배치 칸이 바뀌므로 바이트 비교는 조건부 | (설계 판단) | ✅ 비교 도구 범위에 넣음 |

7. **공통 기호 정의(B5) — 근거 조사(이번 세션, python·grep, 07 변경 없음)**: plan 397 B2-1 규칙(처음 언급 순)에서 **머리 파일의 잠정 정의**는 그 머리를 들이는 모든 객체를 COMMON 언급자로 만듭니다. 재빌드 402 객체의 `cc -M` 기록으로 각 머리를 링크 순서상 처음 들이는 객체를 구했습니다:
   - `_master_cpu`: 원본 `__common` 맨 앞(0x1e8750). 07 `kern/cpu_number.h`(Darwin 판 `extern int master_cpu;`)를 처음 들이는 객체는 libc **pagesize.c**(cmu_syscalls 보다 앞). Mach4 `kernel/kern/cpu_number.h:36` 은 `int master_cpu;`(잠정 정의) → 4.2 가 Mach4 꼴이면 맨 앞이 설명됩니다(Darwin 은 extern 으로 바꾸고 i386_init.c:77 에서 정의).
   - `____xxx_state`: 원본은 cmu_syscalls 덩어리(`_total`) 뒤, init_main 덩어리(`_active_threads` …) 첫 이름. 07 `nextdev_private/bsd/i386/reg.h`(`extern thread_saved_state_t *___xxx_state;`)를 처음 들이는 객체가 **init_main.c**(13 객체 중 첫째; Darwin conf/files 360–361 에서 cmu_syscalls 와 init_main 사이 파일 없음) → reg.h 의 잠정 정의 꼴이면 정확히 맞습니다(Darwin 은 extern + i386_init.c:103 "Just a placeholder" 정의).
   - `_nmi_*` 8: 원본 순서 `_glLanguage, _nmi_big, _nmi_cont, _nmi_gdb, _nmi_halt, _nmi_help, _nmi_mon, _nmi_msg, _nmi_reboot, _nmi_stay, _prettyShutdown` 는 07 machdep.c(이미 `_glLanguage` UNDF·`_nmi_stay` COMMON 을 처음 언급)의 이름순 한 덩어리 → Darwin machdep/i386/machdep.c:109–110 `int nmi_cont, nmi_gdb, nmi_mon, nmi_help, nmi_halt, nmi_msg, nmi_stay, nmi_reboot, nmi_big;` 을 07 의 `int nmi_stay;` 자리에 쓰면 맞습니다.
   - 나머지 UNDF 만 15(`_master_cpu` 제외): 처음 언급자가 이미 원본 덩어리와 맞으므로(예: `_kernel_map`·`_pgrphash`·`_posix_proc_hash` = init_main 덩어리, `_cons` = subr_prf, `_cpu_config` = fp_support), **정의를 그 처음 언급자와 같거나 뒤의 객체에 두면 배치가 바뀌지 않습니다**(B2-1 규칙). 참조가 정의 파일을 알려 주는 것: Darwin i386_init.c:78·83·85·86·88(`cpu_config`, `virtual_avail`·`virtual_end`, `mem_region`, `num_regions`, `mem_size`) → 07 machdep/i386/i386_init.c; Mach4 kernel/vm/vm_kern.c:55·Darwin vm_kern.c:70(`kernel_map`) → 07 vm/vm_kern.c; Darwin bsd/kern/kern_proc.c:95(`pgrphash`) → 07 bsd/kern/kern_proc.c; Darwin bsd/kern/kern_fork.c:346(`u_thread_zone`) → 07 bsd/kern/kern_fork.c; Darwin bsd/dev/i386/cons.c:47(`cons`) → 07 machdep/i386/cons.c. 참조 정의가 없는 것: `_active_u`·`_posix_proc_hash`·`_u_task_zone`·`_nfsslowlink`, 그리고 `_cons_tp`(NeXTMach 은 next/cons.h 에 잠정 정의).
   - 크기: 공통 크기는 요청 중 최댓값이므로 정의의 형이 원본 간격(다음 주소까지)을 넘지 않는지 시험 링크로 확인합니다(원본 nlist 에 크기는 없음).
8. 고친 순서: (B5-1) 07 고침 계획 — cpu_number.h·reg.h 잠정 정의, machdep.c nmi 줄, 참조가 알려 주는 정의 위치 다섯 파일, 참조 없는 다섯 이름의 정의 위치(사용자 결정) → codex 검토 → 고침 → 영향 객체 재빌드(머리 고침은 들이는 모든 객체; text·data 는 바뀌지 않아야 함) → (L2-1) 시험 링크 → 비교.

## 400. S6-8 세부 계획 — B5: 원본 공통 기호 25 개의 정의(07 고침; plan 399 항목 7·D059; 코딩 전, 2026-10-08)

0. 근거: plan 399 항목 7(머리 잠정 정의·처음 언급 규칙), D059. 형 크기(진단 객체 s6p399-sz1, 07 머리로 컴파일, python 으로 `__data` 값 읽음): `struct _u_address` 8, `struct pgrp *` 4·PIDHSZ 64(→ 256), `struct tty` 136, `struct mem_region` 28(×2 = 56), `cpu_conf_t` 4, `vm_map_t`·`struct zone *`·`vm_size_t`·`vm_offset_t`·`thread_saved_state_t *` 각 4. 원본 간격(다음 공통 주소까지, 상한): active_u 8, pgrphash 256, posix_proc_hash 256, cons 136, mem_region 56, 그 밖 4–16 — 모두 형 크기 이상입니다. `-fno-common` 으로 컴파일하는 행 0(머리 잠정 정의가 실제 정의로 바뀌는 객체 없음).
1. 07 고침(줄마다 plan 400 표시; text·data 바이트는 바뀌지 않아야 함):

| 파일 | 고침 | 근거 |
|---|---|---|
| src/kern/cpu_number.h | `extern int master_cpu;` → `int master_cpu;` | Mach4 kernel/kern/cpu_number.h:36; 처음 들이는 객체 pagesize.c → `__common` 맨 앞 |
| nextdev_private/bsd/i386/reg.h | `extern thread_saved_state_t *___xxx_state;` → 잠정 정의 | Darwin i386_init.c:103 "Just a placeholder"; 처음 들이는 객체 init_main.c |
| src/machdep/i386/machdep.c | `int nmi_stay;` → `int nmi_cont, nmi_gdb, nmi_mon, nmi_help, nmi_halt, nmi_msg, nmi_stay, nmi_reboot, nmi_big;` | Darwin machdep/i386/machdep.c:109–110 |
| src/machdep/i386/i386_init.c | `extern vm_offset_t virtual_avail, virtual_end;`·`extern vm_size_t mem_size;` → 정의, `cpu_conf_t cpu_config;`·`struct mem_region mem_region[2];`·`int num_regions;` 추가 | Darwin i386_init.c:77–88 |
| src/vm/vm_kern.c | `vm_map_t kernel_map;` | Mach4 vm_kern.c:55 |
| src/bsd/kern/kern_proc.c | `struct pgrp *pgrphash[PIDHSZ];`, `struct posix_proc *posix_proc_hash[PIDHSZ];` | Darwin kern_proc.c:95; posix_proc_hash 는 D059 |
| src/bsd/kern/kern_fork.c | `extern struct zone *u_task_zone, *u_thread_zone;` → 정의, `struct _u_address active_u[NCPUS];` | Darwin kern_fork.c:346; u_task_zone·active_u 는 D059 |
| src/machdep/i386/cons.c | `extern struct tty cons, *cons_tp;` → 정의 | Darwin bsd/dev/i386/cons.c:47; cons_tp 는 D059 |
| src/bsd/nfs/nfs_vnodeops.c | `extern int nfsslowlink;` → `int nfsslowlink;` | D059 |

   cpu_number.h 는 Darwin 원문 그대로였던 파일(PROVENANCE `none (verbatim)`) → 고침 기록 새로; reg.h 는 nextdev_private 작성본.
2. 확인: 머리 고침 둘이 많은 객체(cpu_number.h 178·reg.h 13 들임)에 들어가므로 **402 객체 전체 재빌드**(plan 398 도구 그대로, 새 run), L1 이 plan 398 결과(377 기준선 + 25 기대)와 모두 같아야 함(고친 9 파일의 객체도 text·data 같음 — 공통 요청만 늘어남). 그 뒤 공통 기호 흉내(l2_coverage)로 25 이름이 모두 정의되고 처음 언급 순 LIS 가 늘어나는지 봄(묶음 없는 근사; 실제는 plan 399 시험 링크로).
3. 기록: PROVENANCE(바뀐 9 행 SHA·고침), MODIFICATIONS 9 항목, 해당 증거 파일 끝에 덧붙임·diff 다시, functions.tsv 줄 번호 인용 다시 맞춤(plan 398 remap 방식). 
4. 하지 않는 것: 링크(plan 399 로 이어짐).
5. codex 교차검토(k2dzgnv73, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 고친 뒤 흉내: 언급 417/417, LIS 412, 어긋남 5(`_boottime`·`_callout`·`_inode_list`·`_iuniqtime`·`_in_interfaces`) | 내 흉내(scratchpad `sim400.py`, 머리 잠정 정의 = 들이는 모든 객체에 COMMON, 객체 안 이름순): mentioned 417, LIS 412, 같은 5 이름 | ✅ 이 다섯은 별도 계획(B5b) |
| **정렬 규칙**: 이름별 최대 요청 크기 + 2 의 거듭제곱 정렬(최대 16) 로 원본 순서대로 놓으면 417 주소와 끝 0x1f7b50 이 모두 맞음 | python: 객체 COMMON 최대 요청 + 계획 정의 크기로 같은 규칙 → 불일치 0, 끝 0x1f7b50 = 원본(0x1e8750 + 62,464) | ✅ 크기는 모두 맞고 순서만 남음 |
| vm_kern.c:351 의 `extern vm_map_t kernel_map;` 은 kmem_init 함수 안 — extern 만 지우면 지역 변수가 되어 코드가 바뀜; 파일 범위에 정의를 따로 둘 것 | vm_kern.c 345–351 읽음(`void kmem_init(start, end) … { vm_offset_t addr; extern vm_map_t kernel_map;`) | ✅ 계획 고침: 파일 범위 정의 추가, 함수 안 선언은 그대로 |
| kern_proc.c:61 이 `struct proc *pidhash[PIDHSZ];` | kern_proc.c 55·58 행이 pidhash(55 `struct proc *pidhash[PIDHSZ];`, 58 `short pidhash[PIDHSZ];`), 61 은 주석 줄 | ❌ 줄 번호 틀림(정의는 55·58); 행동은 바뀌지 않음(새 정의는 그 근처 파일 범위) |
| NCPUS 는 meta_features.h → cpus.h(`NCPUS 1`)로 정의됨 | (형 크기 진단 s6p399-sz1 이 같은 꼴로 컴파일되어 `active_u[0]` 8 B) | ✅ |
| `_master_cpu` 만 처음 언급자가 앞당겨짐(의도), 나머지 정의 위치는 모두 처음 언급자와 같거나 뒤 | 내 흉내에서 `_master_cpu` 가 pagesize.c 로, 다른 정의 파일은 바깥 목록에 없음 | ✅ |
| libDriver 묶음은 이 417 이름의 처음 언급을 하나도 주지 않고 libobjc 는 `__NXUncaughtExceptionHandler` 하나 | (계산 안 함) | ⏭️ 시험 링크로 확인 |
| 받아들임 기준은 LIS 가 아니라 정확한 공통 주소; 기호 추가로 객체 해시·디버그 기록·재배치 기호 번호가 바뀔 수 있으니 절 바이트와 풀린 재배치 대상으로 확인 | l2_rebuild check 는 L1(절 바이트·재배치 대상 해석) 구조 비교 | ✅ 재빌드 확인은 L1 구조 비교(객체 해시 비교 아님) |

6. 고친 계획: 표의 vm_kern.c 는 "파일 범위에 `vm_map_t kernel_map;` 추가(함수 안 extern 유지)". 나머지 그대로. B5b(어긋남 5)는 시험 링크 결과를 본 뒤 따로 계획합니다 — 원본 순서 `_in_interfaces, _ip_id, _ipq, _ipstat, _udb` 한 덩어리, `_inode_list, _iuniqtime, _reaper_queue, _rootdir, _rootvfs` 한 덩어리는 4.3BSD 식 머리 잠정 정의(ip_var.h·udp_var.h 등)의 흔적으로 보이며, 07 머리는 SDK 판이라 신중히 다뤄야 합니다.
7. 결과(2026-10-08): 9 파일 고침(백업 scratchpad `bak400/`; vm_kern.c 는 파일 범위 정의 추가). 402 객체 재빌드(s6l2-g6a·g2aa·g5a·g3a·g4a·g2ba·g1a; 결과 `09_validation/reconstruction/s6-l1-<G>-s6l2-*.json`): 기준선과 같음 377, 기대와 맞음 25, 실패 0, `cc -M` 의존이 07 밖 0 — 공통 요청만 늘고 절 바이트·재배치 해석은 그대로입니다. 기록: functions.tsv 07 줄 번호 인용 66 개를 옮김(옛·새 줄 내용 같음, 4,763 행 그대로), PROVENANCE 9 행(SHA·plan 400), MODIFICATIONS 9 항목(526 → 535 줄), 증거 7 파일 끝에 절 덧붙임, diff 7 다시·새 diff 둘(`x86-cpu_number_h.diff`, `x86-reg_h.diff`). machdep.c 의 nmi 줄은 원본 기호 이름으로 정해지는 선언이며 Darwin 0.1 machdep.c:109–110 과 같은 줄이라 출처 판단(APSL 고지 여부)은 사용자 판단 사항으로 남깁니다.
9. **시험 링크 결과**(2026-10-08, 진단 run `s6p399-ln1`, 도구 `l2_link.py`·`l2_compare.py`(원본 대 원본 시험: 같음 0 차이); 입력 plan 400 재빌드 402 객체; 결과 `09_validation/reconstruction/s6-l2-link-s6p399-ln1.json`):
   - `ld -r` 둘과 최종 `ld` 모두 상태 0, 경고·오류 출력 없음.
   - **Mach-O 머리 같음**(filetype·cpu·flags·ncmds 7·sizeofcmds 2,152). 세그먼트·절은 **모두 원본과 같은 주소·크기**(`__PAGEZERO`·`__TEXT`·`__DATA`·`__OBJC` 세그먼트 명령 같음, UNIXTHREAD 같음).
   - 절 바이트: `__text` 만 1,222 B 다름(1,066 구간), 나머지 `__const`·`__cstring`·`__data`·ObjC 절은 모두 같음. `__text` 의 다른 바이트는 **모두** 주소가 달라진 공통 기호 75 개를 가리키는 4 B 칸으로 설명됩니다(python: 설명 안 되는 바이트 0).
   - 외부 기호 3,751 이름 집합이 원본과 같고, 값이 다른 75 개는 모두 `__common`(공통 417 중 342 같음). 어긋남 5(`_boottime`·`_callout`·`_inode_list`·`_iuniqtime`·`_in_interfaces`)가 순서를 밀어 75 주소가 달라진 것입니다.
   - 로드 명령 차이 2: `__LINKEDIT` 크기(13,418,496 대 102,112 B)와 SYMTAB(nsyms 400,586 대 3,751) — 링크 결과에는 디버그 STAB 394,059 개와 지역 기호 2,776 개가 있고 원본에는 없습니다.
   - 남은 일: (1) B5b — 어긋남 5 의 처음 언급 자리 고침(4.3BSD 식 머리 잠정 정의 가설, 별도 계획·codex 검토), (2) 기호표: 원본처럼 STAB·지역 기호를 뺀 꼴 만들기(strip 류; kr_run allow-list 에 도구 추가가 필요하면 도구 해시 기록 포함, 별도 계획), (3) 그 뒤 파일 전체 비교.

## 401. S6-9 세부 계획 — B5b: 공통 기호 어긋남 5 개 고침(plan 399 항목 9; 코딩 전, 2026-10-08)

0. 사실(이번 세션 python·grep; 링크 순서 = `08_build/runs/tools/s6p399-ln1.link.json`, 의존 = plan 400 재빌드 `cc -M`):
   - 원본 `__common` 의 오름차순 덩어리: `[_all_psets, _all_psets_lock, _default_pset, _inode_list, _iuniqtime, _reaper_queue, _rootdir, _rootvfs]`(나머지는 지금 kern_shutdown 이 처음 언급), `[_boottime, _realhost]`(realhost 는 kern_time), `[_in_ifaddr, _ipintrq]` 다음 `[_in_interfaces, _ip_id, …]`, `[_callout, _file, …]`(file 은 param).
   - `_inode_list`·`_iuniqtime`: 07 SDK `nextdev/bsd/ufs/inode.h:202·287` 에 잠정 정의가 이미 있음. 이 머리를 처음 들이는 객체는 vfs.c(링크 순서 뒤쪽). Darwin `bsd/kern/kern_shutdown.c:61–62` 는 `ufs/ufs/quota.h`·`ufs/ufs/inode.h` 를 들임, 07 kern_shutdown.c(링크 31 번째) 는 들이지 않음 → 07 kern_shutdown 이 `ufs/inode.h` 를 들이면 처음 들이는 객체가 되어 원본 덩어리와 맞습니다.
   - `_in_ifaddr`·`_ipintrq`: 07 SDK `nextdev/bsd/netinet/in_var.h:56·58`(KERNEL) 잠정 정의. 처음 들이는 객체가 in.c(82 번째). Darwin `bsd/netinet/if_ether.c:85` 는 `netinet/in_var.h` 를 들임, 07 if_ether.c(81 번째)는 들이지 않음 → 들이면 in.c 앞에서 두 이름이 언급되어 `_in_interfaces` 가 원본처럼 그 뒤로 갑니다.
   - `_boottime`: 07 init_main.c:182 `struct timeval boottime;` 는 07 코드에서 쓰이지 않는 잠정 정의(grep: 그 줄뿐). kern_time.c(35 번째)가 UNDF 로 참조. NeXTMach init_main.c:188·Darwin init_main.c:275 는 init_main 에 정의하지만, 원본 배치는 4.2 init_main 이 이 이름을 언급하지 않았음을 보여 줍니다 → init_main 의 정의를 빼고 kern_time 이상의 자리에 정의(위치는 사용자 결정).
   - `_callout`: 07 kern_clock.c:101 `struct callout *callout;` 는 쓰이지 않는 잠정 정의(grep: 그 줄과 주석뿐); 07 conf/param.c:135 가 정의(NeXTMach param.c 와 같음); NeXTMach sys/callout.h:48 은 `extern` → kern_clock 의 줄을 `extern` 으로 바꾸면 처음 언급자가 param 이 되어 원본과 맞습니다.
1. 07 고침(줄마다 plan 401 표시): kern_shutdown.c 에 `#import <ufs/inode.h>`(필요하면 quota 머리도 — 스테이징으로 확인), if_ether.c 에 `#import <netinet/in_var.h>`, init_main.c:182 를 extern 으로, boottime 정의를 새 자리에, kern_clock.c:101 을 extern 으로.
2. 확인: 바뀌는 5 객체(+ 머리를 들이게 된 두 객체의 text·data 가 바뀌지 않는지)를 포함해 402 객체 재빌드 → L1 이 plan 400 결과와 같음, 흉내로 공통 417 순서 전부 일치(정렬 규칙으로 417 주소 일치), 그 뒤 시험 링크 다시 → `__text` 차이 0 기대.
3. codex 교차검토(k3amx92ab, gpt-6.1-sol) 판정과 결정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 항목 0 사실(inode.h:202·287, in_var.h:56·58, Darwin kern_shutdown.c:61–62·if_ether.c:85, init_main.c:182 유일, kern_clock.c:101 유일·param.c:135, NeXTMach callout.h:48 extern) 모두 맞음 | 이번 세션 grep·sed 로 같은 줄을 열어 확인(위 항목 0 의 근거 출력) | ✅ |
| 링크 위치 "31·35·81·82 번째" 는 0 부터 센 색인 — 서수로 32·36·82·83 번째 | 내 계산은 python `list.index`(0 부터) | ✅ **내 표기가 틀렸습니다**: 항목 0 의 "n 번째" 는 0 부터 센 색인으로 읽어야 합니다 |
| 고친 뒤 흉내: 417 이름 순서·주소 모두 원본과 같음(끝 0x1f7b50), 묶음 입력으로도 같음 | (재빌드·재링크로 직접 확인할 것) | ⚖️ 재링크 결과로 확인 |
| 두 머리에는 함수 본문·정적 객체·초기화 데이터·`#undef` 없음 → text·data 영향 없을 것 | (재빌드 L1 로 확인) | ⚖️ 재빌드로 확인 |
| quota 머리는 필요 없음(inode.h 는 불완전형 `struct dquot *` 만), Darwin 경로 `ufs/ufs/quota.h` 는 07 에 없음 | (컴파일로 확인) | ⚖️ quota 는 넣지 않고 컴파일로 확인 |
| inode.h 는 vnode 등 앞선 머리 뒤에, in_var.h 는 net/if.h·netinet/in.h 뒤에 | 07 if_ether.c 96–100 행(net/if.h → netinet/in.h → in_systm → ip → if_ether.h) | ✅ |

   결정 D060(사용자, 2026-10-08): boottime 은 kern_time.c 에 정의.

## 402. S6-10 세부 계획 — L2 링크 마무리: `strip -x` 단계와 도구 등록(코딩 전, 2026-10-08)

0. 사실(이번 세션):
   - Darwin `conf/Makefile.template:272` `SYS_RULE_2=strip -x -o $@ $@.sys` — 커널 이미지는 링크 결과(`.sys`)를 `strip -x` 한 것.
   - 탐침(07·기록 변경 없음; `08_build/runs/tools/probe/l2b3/run.sh`, 시험 링크 s6p399-ln1 출력의 사본): `strip -x` 결과는 파일 크기 1,117,920 B(원본과 같음), 로드 명령 차이 0, 기호 외부 3,751·STAB 0·지역 0. `strip -S` 는 지역 2,776 이 남아 1,219,072 B, `strip -x -S` 는 `-x` 와 같은 결과. 남은 차이는 공통 기호 75 값과 그 참조 칸(plan 401 로 고침 중)뿐.
   - 도구: 실기 `/bin/strip` 378,240 B, SHA-256 `80cb973b6092ab955f4843be0ef08a63b192779c6b32941bf21647e640c812d7`(krsha256). i386 VM 디스크(`09_validation/images/i386/openstep42-i386-hdd.raw`)의 scratch 사본을 nextufs 로 읽기 전용 마운트해 잰 `/bin/strip` 도 같은 값(대조: VM `/bin/ld` = 기록값 4c6dae19…, 저장소 디스크 SHA 전후 같음, 사본은 지움). 지금 kr_run allow-list 와 `sha256-vs-vm.json` 에 `/bin/strip` 이 없음.
1. 고침:
   - `08_build/toolchains/real-i386-20261001/sha256-vs-vm.json` 에 `/bin/strip` {real, vm, size} 추가(측정 방법은 계획에 기록), `kr_run.py` ALLOWED_TOOLS 에 `/bin/strip`.
   - `l2_link.py`: 최종 `ld` 출력을 `stage/mach_kernel.sys` 로, 이어서 `RUN /bin/strip -x -o stage/mach_kernel stage/mach_kernel.sys`(EXPECT 둘); 문서 문자열에 Darwin 근거.
2. 실행: plan 401 재빌드(s6l3-*) 결과로 `l2_link.py prepare s6p402-ln1 s6l3` → kr_run → `l2_compare.py`(stripped 대 원본). 기대: 파일 전체 같음(SHA-256 33469393…). 다르면 차이를 그대로 기록.
3. 하지 않는 것: 결과 커널 부팅(사용자·VM 계획 따로), 기록 표 등급 변경.
4. codex 교차검토(k4blnua6s, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Makefile.template:272 인용 맞음(원래 명령의 증명은 아님) | 이번 세션 grep 출력 | ✅ |
| 탐침: mk.x·mk.xS 크기·로드 명령 원본과 같음, 둘은 같은 파일; mk.S 는 지역 2,776 남음 | `cmp mk.x mk.xS` → 같음; l2_compare 출력(위 항목 0) | ✅ |
| mk.x 의 다른 바이트 1,306 = `__text` 1,222(공통 기호 참조 칸) + 기호표 n_value 84(75 기호), 문자열 표 57,100 B 같음, 그 밖 0 | python 분류(이번 세션): text 1,222·symtab 84(필드 오프셋 8–10 만)·strtab 0·기타 0 | ✅ |
| `/bin/strip` 은 ALLOWED_TOOLS 와 TOOLS_JSON(real = vm)에 넣고 REAL_ONLY 에는 넣지 않음; 해시 검사는 실기 실행 스크립트에서 빌드 전에 | kr_run.py tool_hashes()(:157–171: real ≠ vm 이면 die), 실행 스크립트 `tools.actual`/`tools.expected` cmp | ✅ |
| l2_link.py: 최종 출력 `stage/mach_kernel.sys` + `RUN /bin/strip -x -o stage/mach_kernel stage/mach_kernel.sys`, EXPECT 둘 | (설계 판단) | ✅ |
5. 결과(2026-10-08):
   - plan 401 고침 5 파일(백업 `bak401/`) 뒤 402 객체 재빌드(s6l3-g6a·g2aa·g5a·g3a·g4a·g2ba·g1a): 기준선과 같음 377, 기대와 맞음 25, 실패 0, 07 밖 의존 0.
   - 도구: `sha256-vs-vm.json` 에 `/bin/strip`(real = vm = 80cb973b…, 378,240 B; 15 → 16 도구), `kr_run.py` ALLOWED_TOOLS 에 `/bin/strip`, `l2_link.py` 에 `mach_kernel.sys` → `strip -x` 단계(백업 `bak402/`).
   - **L2 링크(run `s6p402-ln1`, `l2_link.py prepare s6p402-ln1 s6l3`; 명령 4 개 모두 상태 0, 출력 없음): 07 에서 다시 빌드한 402 객체 + `-lcc` 를 링크하고 `strip -x` 한 `mach_kernel` 이 원본과 바이트 단위로 같습니다** — SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`, 1,117,920 B; 머리·로드 명령 차이 0, 외부 기호 3,751 모두 같음, 공통 기호 417/417 같음(`09_validation/reconstruction/s6-l2-link-s6p402-ln1.json`).
   - 기록: functions.tsv 07 줄 번호 인용 30 개 옮김(4,763 행 그대로), PROVENANCE 5 행·MODIFICATIONS 5 항목(535 → 540 줄), 증거 5 파일 덧붙임·diff 다시.
   - 남은 것: 07 트리 밖 입력은 libcc(`-lcc`, 등급 L, D051)와 실기 도구뿐. 결과 커널의 부팅 확인(L3)은 원본과 같은 바이트이므로 원본과 같은 동작이 기대되나, VM 부팅은 별도 계획(사용자 지시 시).

## 403. 진단 메모 — L3(부팅) 확인 방법 조사(07·기록 변경 없음, 2026-10-08)

- 실기(읽기만, gcds): `/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`, 1,117,920 B(krsha256) = plan 402 의 07 재빌드·링크 결과(run s6p402-ln1)와 같음. `hostinfo` 의 실행 중 커널 판 문자열 "NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386" = 원본 바이트 안의 `_version` 문자열(python), `uptime` 7 일 21 시간.
- 판단: 실기는 디스크의 `/mach_kernel`(07 결과와 같은 바이트)과 같은 판 문자열의 커널로 7 일 넘게 돌며 이 작업의 모든 빌드를 수행했습니다. 실행 중 이미지가 그 파일에서 부팅됐다는 것은 기본 부팅 파일 경로에 따른 추론이며, 07 결과 파일 자체로 새로 부팅한 시험은 아닙니다.
- VM 쪽: `09_validation/images/i386/kernels/mach_kernel.183.34.4.pic`(같은 크기, SHA 304cb696…)·`extracted/mach_kernel`(1,113,724 B, SHA 00e49892…)은 07 결과와 다른 파일입니다. VM 으로 07 결과 파일을 직접 부팅하려면 디스크 사본에 커널을 넣고 `--snapshot` 으로 부팅하는 별도 계획이 필요합니다(실기 커널 교체·재부팅은 사용자 몫).

## 404. S6-11 세부 계획 — D061: 이번에 넣은 Darwin·Mach4 줄에 고지 붙이기(주석·기록만; 코딩 전, 2026-10-08)

0. 대상(plan 397–401 에서 넣은 줄, grep 으로 확인할 것):

| 07 파일 | 줄 | 출처 | 고지 |
|---|---|---|---|
| src/machdep/i386/machdep.c | nmi 선언(plan 400) | Darwin 0.1 machdep/i386/machdep.c:109–110 | Darwin 그 파일 머리 APSL |
| src/kern/mfs_prim.c | mfsbuf_lock·active_mfsbufs(plan 397) | Darwin kern/mapfs.c:132·:1081 | 〃 |
| src/machdep/i386/i386_init.c | 정의 5 줄(plan 400) | Darwin machdep/i386/i386_init.c:77–88 | 〃 |
| src/bsd/kern/kern_proc.c | pgrphash(plan 400) | Darwin bsd/kern/kern_proc.c:95 | 〃 |
| src/bsd/kern/kern_fork.c | u_task_zone·u_thread_zone 줄(plan 400; u_thread_zone 부분) | Darwin bsd/kern/kern_fork.c:346 | 〃 |
| src/machdep/i386/cons.c | cons 정의 줄(plan 400) | Darwin bsd/dev/i386/cons.c:47 | 〃 |
| src/bsd/kern/kern_shutdown.c | `#import <ufs/inode.h>`(plan 401) | Darwin bsd/kern/kern_shutdown.c:62 | 〃 |
| src/bsd/netinet/if_ether.c | `#import <netinet/in_var.h>`(plan 401) | Darwin bsd/netinet/if_ether.c:85 | 〃 |
| src/vm/vm_kern.c | `vm_map_t kernel_map;`(plan 400) | Mach4 kernel/vm/vm_kern.c:55 | Mach4 그 파일 머리(CMU·Utah) |
| src/kern/cpu_number.h | `int master_cpu;`(plan 400) | Mach4 kernel/kern/cpu_number.h:36 | 같은 CMU 고지가 이미 파일에 있음 → 출처 기록만 |

1. 꼴(in_bootp.c 선례, PROVENANCE:1011): 파일의 기존 머리 주석 뒤, 첫 `#import` 앞에 `/* Parts marked "plan NNN (Darwin)" follow Darwin 0.1 kernel/<path> (kernel-1), whose notice is: */` + 그 Darwin 파일의 첫 주석 블록(고지) 그대로. 해당 줄 주석의 "plan NNN" 을 "plan NNN (Darwin)"(Mach4 는 "(Mach4)")으로. 코드 줄은 바꾸지 않음.
2. 확인: 주석만 바뀌므로 객체 절 바이트는 같아야 함 — 바뀐 10 파일의 객체가 든 묶음 재빌드(cpu_number.h 는 178 객체가 들이므로 사실상 전체)로 L1 이 plan 401 결과와 같음을 확인, 그 뒤 링크·strip 한 커널이 다시 원본과 같은지(SHA) 확인. functions.tsv 줄 번호 인용 다시 맞춤(옛·새 줄 내용 같음 검사).
3. 기록: PROVENANCE 10 행(source_id 에 +darwin01 / +mach4, 개정·원본 경로·고지 칸, SHA), MODIFICATIONS 항목, 증거 덧붙임·diff 다시.
4. 교차검토 전 내 확인과 codex(kgauj4tp3, gpt-6.1-sol) 판정:

| 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| (내 발견, codex 도 같음) Darwin kern_proc.c:95 는 `u_long pgrphash;` — 07 의 `struct pgrp *pgrphash[PIDHSZ];` 와 다른 선언 | `sed -n 95p` Darwin kern_proc.c → `u_long pgrphash;` | ✅ **내 인용이 틀렸습니다**(plan 399 항목 7·400 표·07 주석·증거·MODIFICATIONS). 07 줄의 형은 SDK `sys/proc.h:250` extern 선언에서 온 것 → kern_proc.c 는 고지 대상 아님, 인용 정정 |
| machdep 의 Darwin 줄은 110–111(109 는 주석) | Darwin machdep.c 108–111 출력(108 빈 줄, 109 `/* nmi mini-monitor */`, 110–111 선언) | ✅ 인용을 110–111 로 정정 |
| reg.h:17 `___xxx_state` 는 Darwin i386_init.c:103 과 같은 선언; reg.h 는 PROVENANCE:437 에서 darwin01·APSL 로 적혀 있는데 파일에 APSL 고지가 없음 | PROVENANCE 437 행(“KERNEL_PRIVATE body of the Darwin file verbatim”, APSL-1.0.txt), reg.h 1–9 행 머리(작성 문구만), Darwin i386_init.c:103 | ✅ reg.h 에 APSL 고지 추가(plan 144 부터 있던 누락도 함께 고침) |
| init_sysent.c 334·345·373 행(`syss(setsid,0)`·`sysp(setprivexec,1)`·`syss(add_profil,4)`)이 Darwin init_sysent.c 457·467·495 와 같은 글자 | Darwin 457 행 = 07 334 행(주석 `/* 147 = setsid */` 까지 같음) | ✅ 원본 바이트로 쓴 줄이지만 글자가 같으므로 D061("모두 붙임")에 따라 "같은 글자" 로 표시하고 고지 추가 |
| kern_fork·cons 는 줄의 일부만(u_thread_zone, cons) Darwin 과 같음; kern_shutdown·if_ether 는 경로·지시어를 바꾼 꼴(`ufs/ufs/inode.h`, `#include`) | Darwin 346·47·62·85 행 출력 | ✅ 표시 문구에 "일부"·"꼴을 바꿈" 을 적음 |
| cpu_number.h 의 CMU 고지가 Mach4 cpu_number.h 고지와 글자 그대로 같음 | (python 비교는 codex; 나는 두 블록을 출력해 눈으로 대조 — 25 행 같음) | ⚖️ 출처 기록만(고지 이미 있음) |
| machdep_call.c(APSL 그대로)·counters.c(CMU 그대로)·in_proto.c(APSL 블록 있음)·D030/D047 파일은 이미 처리됨 | 이번 세션 plan 398 기록 | ✅ |
| 주석 추가는 -g 줄 정보(STAB)만 바꾸고 L1·strip 결과는 그대로일 것; 단 `__LINE__` 은 바이트를 바꿀 수 있음(kern/assert.h, MACH_ASSERT 0 이라 꺼짐) | generated/mach_assert.h `#define MACH_ASSERT 0`(config_options) | ✅ 재빌드 L1 + 링크·strip SHA 비교로 확인 |

5. 고친 대상: Darwin APSL 고지 — machdep.c(110–111), mfs_prim.c(132·1081), i386_init.c(78·83·85·86·88), kern_fork.c(346 의 u_thread_zone 부분), cons.c(47 의 cons 부분), kern_shutdown.c(62, 경로 바꿈), if_ether.c(85, 지시어 바꿈), init_sysent.c(457·467·495 와 같은 글자 세 줄), reg.h(Darwin 본문·i386_init.c:103 선언); Mach4 고지 — vm_kern.c(55); 출처 기록만 — cpu_number.h; 인용 정정 — kern_proc.c.

## 405. S7-1 세부 계획 — L3 준비: 07 에서 만든 커널로 QEMU(i386) 부팅 시험 준비(부팅은 하지 않음; 코딩 전, 2026-10-08)

0. 사실(이번 세션):
   - plan 402 의 07 링크 결과(run s6p402-ln1) = 원본(SHA-256 33469393…); plan 404(고지 주석) 뒤의 재빌드·재링크(s6l4-*·s6p404-ln1)로 현재 07 도 같은지 확인 중.
   - `11_emulation/QEMU_VM_CONFIGURATIONS.md` 3.4·4 절: 원본 그대로의 mk-183.34.4 커널은 이 QEMU 에서 IDE 인터럽트가 잠겨 부팅되지 않음; `_intr_handler` 12 B 를 고친 `.pic` 판(`10_tools/runtime/make_i386_pic_kernel.py`, 출력 SHA 304cb696…)으로 `boot:` 에서 `hd()mach_kernel.183.34.4.pic -v` 부팅, `hostinfo` 로 판 확인.
   - VM 디스크(`09_validation/images/i386/openstep42-i386-hdd.raw`)의 scratch 사본을 nextufs 로 읽기 전용 마운트(저장소 디스크 SHA 전후 같음, 사본은 지움): `/mach_kernel.183.34.4` = 33469393…(07 결과와 같은 바이트), `/mach_kernel.183.34.4.pic` = 304cb696…, `/mach_kernel` = 1997 판(00e49892…).
   - `vm-common.sh:69–79`: 디스크 경로는 고정(`openstep42-ARCH-hdd.raw`), `--snapshot` 이면 디스크에 쓰지 않음. 다른 디스크를 고르는 옵션은 없음.
1. 준비(부팅 없음):
   1. 현재 07 의 링크 결과가 원본과 같음을 확인(s6p404-ln1; 같지 않으면 멈춤).
   2. `make_i386_pic_kernel.py` 에 `--in PATH`(선택, 기본은 지금처럼 03_original) — 입력 SHA 가 기준 SHA 와 같아야 하고 출력 SHA 가 304cb696… 이어야 쓰는 검사는 그대로. 07 결과(`08_build/runs/s6p404-ln1/out/mach_kernel`)에 적용해 `09_validation/images/i386/kernels/mach_kernel.l2.pic` 를 만들고 SHA 를 디스크의 `.pic` 파일과 대조.
   3. 시험 디스크: 저장소 디스크의 **사본** `09_validation/images/i386/openstep42-i386-hdd.l2test.raw`(원본 디스크는 건드리지 않음, 사본 전후 SHA 기록)에 nextufs `mkfile` 로 `/mach_kernel.l2`(07 결과 그대로)와 `/mach_kernel.l2.pic`(위 2)를 넣고, 넣은 뒤 읽기 전용 마운트로 두 파일 SHA 확인·`fsck -n` 으로 파일 시스템 확인.
   4. `vm-common.sh`/`vm-i386.sh` 에 부팅 모드 전용 `--disk PATH` 옵션(시험 디스크 선택; `--snapshot` 과 함께일 때만 허용)을 넣고 README·QEMU_VM_CONFIGURATIONS 에 적음. 문법 검사(`bash -n`)와 옵션 오류 경로만 확인(QEMU 는 실행하지 않음).
2. 부팅 시험(다음 단계, 사용자 지시 뒤): `vm-i386.sh boot-nocd --disk …l2test.raw --snapshot` → `boot:` 에서 `hd()mach_kernel.l2.pic -v` → `hostinfo` 판 문자열 확인; 대조로 `hd()mach_kernel.l2 -v`(원본과 같은 IDE 잠김이 기대됨).
3. 하지 않는 것: 저장소 VM 디스크 쓰기, 실기 커널 교체.
4. codex 교차검토(kywj6mg32, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| s6p402-ln1 = 원본, s6p404-ln1 은 아직 없음(현재 07 확인 대기) | 이번 세션 `cmp`·sha256sum(같음); s6p404 재빌드 G1 진행 중 | ✅ 단계 1 은 그 결과로 판정 |
| `--disk` 는 기존 드라이브의 파일만 바꾸는 꼴로, i386 부팅 모드 + `--snapshot` 일 때만; raw 형식 확인, `-w` 요구 대신 읽기 가능 검사; `--` 로 드라이브를 더 넣는 방식은 IDE 제약에 어긋남 | vm-i386.sh 18–30 행(`-drive "file=$disk,if=ide,index=0,…,format=raw"`, `-display gtk -monitor stdio`), vm-common.sh 69–79 행(`[[ -w "$disk" ]]`) | ✅ 계획 고침 |
| 바이너리는 `mkfile --from-file SRC PATH HOSTFILE`, 이어서 권한 `0444`; 기본 `mkfile` 은 문자열을 씀 | nextufs.1 man(301 행 `source path contents` = 문자열, `--from-file` 항목) | ✅ 계획 고침; 권한·소유자·그룹·해시를 넣은 뒤 확인 |
| make_i386_pic_kernel.py `--in`: 기존 검사 유지, 출력이 입력·원본과 같은 파일(심볼릭·하드 링크)이면 거부 | 도구 44–64 행 읽음(입력 SHA·원본 바이트·12 B·출력 SHA 검사, 마지막 `open(..., 'wb')`) | ✅ 별칭 거부 추가 |
| 부팅 증거: `/mach -> $BOOTFILE` 유지, BootHelp 의 10 초 입력 창, 실제 부팅 명령·`-v` 화면·게스트 `hostinfo` 전체 기록; i386 은 직렬을 쓰지 않으므로 화면 기록 방법 필요; 시간 제한·실패 기준·종료·시험 뒤 디스크 해시 | vm-i386.sh(직렬 없음, GTK·monitor stdio) | ✅ 부팅 시험 계획(다음 단계)에 넣음: QEMU 모니터 `screendump` 로 화면을 PPM 으로 남김 |

5. 고친 준비 단계: (1) s6p404-ln1 = 원본 확인; (2) `make_i386_pic_kernel.py --in`(+ 출력 별칭 거부) → `09_validation/images/i386/kernels/mach_kernel.l2.pic`, SHA 304cb696… 확인; (3) QEMU 가 꺼진 상태에서 저장소 디스크 사본 `openstep42-i386-hdd.l2test.raw` 를 만들고(원본·사본 SHA 기록, `fsck -n` 전후), `mkfile --from-file` 로 `/mach_kernel.l2`·`/mach_kernel.l2.pic` 를 넣고 `--chmod … 0444`, `-o ro` 마운트로 형·권한·소유자·해시 확인; (4) `--disk PATH`(i386 `boot`/`boot-nocd` 와 `--snapshot` 일 때만, 일반 파일·raw 크기 확인) — `bash -n` 과 가짜 실행 파일로 인자 구성만 확인.
6. plan 404 확인(2026-10-08): 고지 주석을 넣은 현재 07 로 402 객체 재빌드(s6l4-*: 기준선과 같음 377·기대와 맞음 25·실패 0) → 링크·strip(run s6p404-ln1) → **원본과 바이트 단위로 같음**(`cmp` 차이 0, SHA-256 33469393…, l2_compare: 머리·로드 명령·기호 3,751·공통 417 모두 같음; `09_validation/reconstruction/s6-l2-link-s6p404-ln1.json`).
7. 준비 결과(2026-10-08; QEMU 실행 안 함):
   - (1) 현재 07 = 원본(항목 6 의 plan 404 확인, run s6p404-ln1).
   - (2) `make_i386_pic_kernel.py --in`(백업 `bak405/`): 출력 별칭 거부(원본 파일을 출력으로 주면 STOP), 해시가 다른 입력 거부, 기본 모드 출력이 예전과 같음, s6p402·s6p404 결과에 적용하면 12 B 바뀐 304cb696…(기존 `.pic` 과 `cmp` 같음). 파일: `09_validation/images/i386/kernels/mach_kernel.l2`(33469393…)·`mach_kernel.l2.pic`(304cb696…).
   - (3) QEMU 꺼짐 확인 → 저장소 디스크(SHA 36e437f6…) 사본 `09_validation/images/i386/openstep42-i386-hdd.l2test.raw`(사본 SHA 같음) → `fsck -n`(NO WRITE, 오류 없음, 37,675 파일) → `mkfile --from-file` 두 파일 + `--chmod 0444` → `fsck -n`(오류 없음, 37,677 파일; 로그 `09_validation/images/i386/logs/l2test-fsck-{before,after}-20261008.log`) → `-o ro` 마운트 확인: `/mach_kernel.l2`·`/mach_kernel.l2.pic` 일반 파일, 0444, uid/gid 0/0, 크기 1,117,920, 해시 위와 같음; 기존 `/mach_kernel`·`.183.34.4`·`.pic`·`/mach -> $BOOTFILE` 그대로. 시험 디스크 SHA dec0572b…. 저장소 디스크 SHA 전후 같음.
   - (4) `vm-common.sh`·`vm-i386.sh` 에 `--disk RAW`(백업 `bak405/`): `bash -n` 통과, QEMU 없이 vm_parse·vm_disk 만 부른 시험 8 가지(정상·--snapshot 없음·install·qcow2·512 배수 아님·없는 파일·sparc·옵션 없음) 모두 기대대로. README·QEMU_VM_CONFIGURATIONS 에 적음.
8. 부팅 시험 절차(다음 단계, 사용자 지시 뒤): `bash 11_emulation/scripts/vm-i386.sh boot-nocd --disk 09_validation/images/i386/openstep42-i386-hdd.l2test.raw --snapshot` → BootHelp 의 10 초 안에 `boot:` 에 `hd()mach_kernel.l2.pic -v` → 부팅 화면을 QEMU 모니터 `screendump` 로 PPM 저장 → 로그인 뒤 게스트 `hostinfo` 전체를 화면으로 남김(기대: "NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386") → 정상 종료(모니터 `quit`) → 시험 디스크 SHA 가 dec0572b… 그대로인지 확인. 대조 시험: `hd()mach_kernel.l2 -v`(원본과 같은 IDE 인터럽트 잠김이 기대됨, 시간 제한 두고 종료). 둘 다 `--snapshot`.

## 406. S7-2 세부 계획 — L3 부팅 시험(QEMU i386; 사용자 시작 확인 뒤 실행, 2026-10-08)

0. 준비 상태: plan 405 항목 7(시험 디스크 `09_validation/images/i386/openstep42-i386-hdd.l2test.raw` SHA dec0572b…, `/mach_kernel.l2`·`/mach_kernel.l2.pic`, `--disk` 옵션). QEMU 실행 파일 SHA 6b12d00f…(QEMU_VM_CONFIGURATIONS 표와 같음), 화면은 사용자 X 세션(DISPLAY :1)에 GTK 창으로. 사용자 지시: 시작 전에 확인을 받음, QEMU 는 사용자가 볼 수 있게 실행.
1. 실행(확인 뒤):
   1. 시험 디스크 SHA 확인(dec0572b…), QEMU·i386 소켓 없음 확인.
   2. `tail -f /dev/null | bash 11_emulation/scripts/vm-i386.sh boot-nocd --disk 09_validation/images/i386/openstep42-i386-hdd.l2test.raw --snapshot` 를 셸을 막지 않게 띄움(표준 입력은 열어 둔 채, QEMU 모니터 출력은 로그로) — GTK 창은 사용자 화면에 보임.
   3. scratchpad `qmp_boot.py`(QMP 로 VGA 텍스트 버퍼 0xb8000 을 읽어 "boot:" 를 감지 → `sendkey` 로 `hd()mach_kernel.l2.pic -v` + Enter → 5 초마다 `screendump` 를 PNG 로; VM 을 끄거나 재설정하지 않음)로 입력·기록. 기록 위치 `09_validation/images/i386/logs/l3-boot-<날짜>/`(무시 대상).
   4. 부팅이 끝나면 화면을 보고 로그인·`hostinfo` 는 사용자와 상의해 진행(로그인 계정은 기록에 남기지 않음). 기대 판 문자열 "NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386".
   5. 종료: QEMU 모니터 `quit`(QMP `quit`), 시험 디스크 SHA 가 그대로인지 확인(--snapshot).
   6. 대조 시험(`hd()mach_kernel.l2 -v`, IDE 잠김 기대)은 사용자가 원할 때 같은 절차로 따로.
2. 판정: 화면 기록과 `hostinfo` 판 문자열로 L3 를 기록. 실패하면 화면·로그를 그대로 남기고 원인을 따로 조사.
3. 문서·검토(2026-10-08, 사용자 지시 "HOWTOCOMPILE 문서… git ignore 의 update 가 필요한지 검토"):
   - `HOWTOCOMPILE.md`(저장소 최상위, 새 파일): 준비물·연결·컴파일 꼴·스테이징·kr_run·전체 빌드·링크·strip·비교·QEMU 판·주의. codex 사실 확인(kvw7rlx32) 지적을 하나씩 확인해 고침 — 실행 시 해시 검사 범위(ALLOWED_TOOLS 9 개, libcc·cc1obj 제외; kr_run.py:39–41, sha256-vs-vm.json 키 16 개), G3 의 ABSROOT 실기 링크(kr_run.py:241–244, plans/RECONSTRUCTION_PLAN-245-320.md:1638), nextdev_private 도 로컬 전용(.gitignore:71), gen_config_headers 실행, 이전 기록·krsha256 필요, pagesize `-O3`(forms 4 행), RID 정규식, wait 1,800 초(kr_run.py:364), check 는 판정하지 않음, Darwin LDOBJS 의 `subr_prof.o`(Makefile.template:232; files:391 주석 처리). 사이트 주소·계정 없음.
   - `.gitignore` 검토: 추적 외 4,976 파일 47 MB, 50 MB 넘는 파일 없음, 이번에 만든 큰 파일(시험 디스크·커널 사본·runs)은 기존 규칙으로 무시됨. 결정 필요 둘: (a) 최상위 `--help/`·`--help.manifest.json`(2026-10-03 `stage_headers.py --help` 가 만든 스테이징 부산물) 삭제, (b) kr_run 이 요구하는 `08_build/toolchains/real-i386-20261001/sha256-vs-vm.json`(해시만)을 예외로 추적할지.
4. codex 교차검토(kaoc0gg7s, gpt-6.1-sol) 판정과 고침:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `xp /2000bx` 는 2,000 B = 1,000 칸(12.5 줄)만 읽음; 80×25 화면은 4,000 B | python: 80×25×2 = 4000, 2000/2/80 = 12.5 | ✅ `/4000bx` 로, 읽은 바이트 수 검사 |
| 프롬프트 글자는 "boot: "(디스크 0x109b2·0x209b2), BootHelp 의 10 초; 60 초 감시로는 놓칠 수 있음 → 멈춘 채 띄우고 붙은 뒤 시작 | QEMU_VM_CONFIGURATIONS 3.3("`boot:` 에서 `hd()커널이름 -v`"), vm-common.sh `--gdb-wait` → `-S` | ✅ `--gdb-wait` 로 띄우고 driver 가 `cont`, 감시 30 초 |
| QMP 응답·오류·HMP 문자 오류를 버리고 있음, 읽기 시간 제한 없음 | qmp_boot.py(옛 판) 읽음 | ✅ 인사·오류·이벤트·HMP 출력 검사, 소켓 10 초 제한 |
| `screendump` 는 QEMU 작업 디렉터리 기준 상대 경로·덮어씀 → 절대 경로·실행마다 새 디렉터리 | (QEMU 소스 인용은 codex; 행동 바꿀 만함) | ✅ QMP `screendump` 에 절대 경로, 출력 디렉터리 새로 만듦(있으면 멈춤) |
| `commit` 은 스냅숏 내용을 디스크에 씀 → 금지; 정지는 QMP stop → quit, QEMU PID 확인, `tail` PID 정리, 두 디스크 해시 비교 | vm-common.sh(`-snapshot`) | ✅ qmp_stop.py(stop·quit 만), 실행 전후 해시 |
| vm-common.sh 의 512 배수 검사가 셸 산술 — 계산은 python 원칙 | vm-common.sh 해당 줄 | ✅ python 한 줄로 바꿈(`bash -n` 통과) |
| 키 이름(US 배열) `shift-9`·`shift-0`·`shift-minus`·`dot`·`minus`·`spc`·`ret` 맞음 | (QEMU qapi 인용은 codex) | ⚖️ 실제 입력 결과를 화면 기록으로 확인 |
5. **부팅 시험 결과**(2026-10-08, 사용자 시작 확인 "지금 시작"; 기록 `09_validation/images/i386/logs/l3-boot-20261008/`(무시 대상)):
   - 시작 전 해시: 시험 디스크 dec0572b…, 저장소 디스크 36e437f6…; QEMU·소켓 없음.
   - `tail -f /dev/null | vm-i386.sh boot-nocd --disk …l2test.raw --snapshot --gdb-wait`(GTK 창, 사용자 화면) → `qmp_boot.py`: 상태 prelaunch 에서 `cont`, 0.8 초 뒤 "boot:" 감지, `hd()mach_kernel.l2.pic -v` 입력(로그 `run1/driver.log`).
   - 첫 화면(`run1/shot-001.png`): "NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386", PCI·PnP·DriverKit 420, hc0/hd0(QEMU HARDDISK 1023 MB) 인식.
   - 사용자 보고: 로그인 화면 → 로그인 → Workspace 구동 성공. 게스트 Terminal 의 `hostinfo`(`run1/hostinfo.png`): 위와 같은 판 문자열, 단일 프로세서 I386(Intel 486), 메모리 64 MB, 34 tasks·67 threads.
   - 판정: **07 에서 다시 만든 커널(QEMU 용 12 B PIC 판)이 QEMU i386 에서 부팅해 Workspace 까지 동작(L3)**. PIC 판은 원본·07 결과와 `_intr_handler` 12 B 만 다르며(plan 405), 원본 그대로의 판은 이 QEMU 에서 IDE 인터럽트가 잠기는 것으로 기록돼 있음(QEMU_VM_CONFIGURATIONS 4 절; 대조 시험은 아직).
   - 정리: 사용자 결정에 따라 최상위 `--help/`·`--help.manifest.json` 삭제(추적되지 않던 부산물); 도구 해시 기록은 로컬 유지.
   - 종료(사용자 "확인은 끝났습니다"): `qmp_stop.py`(qmp_capabilities → stop → quit; 이벤트 STOP·SHUTDOWN), QEMU PID 1179582 종료 확인, `tail` 은 파이프가 닫혀 스스로 끝남, 시험 디스크·저장소 디스크 SHA 가 시작 전과 같음(dec0572b…, 36e437f6…).
6. `HOWTOUSE.md`(저장소 최상위, 새 파일, 사용자 지시 2026-10-08): 결과물·원본 대조·QEMU 용 PIC 판·시험 디스크·부팅·끄기·실기 시험(사용자 작업)·디버깅 참고. codex 사실 확인 지적 넷을 확인해 고침 — Workspace 부팅은 PIC 판(대조 시험 없음), `.sys` 는 `__LINKEDIT`·LC_SYMTAB 이 다름(plan 402 탐침 비교에서도 그 둘), 실기 시험은 "새 정보 없음" 이 아니라 결과 파일로 새로 부팅한 적 없음(plan 403), gdb 소켓은 `/tmp/kr-<arch>-gdb.sock`(vm-common.sh:54).
7. README 갱신(2026-10-08, 사용자 지시): 제목·현재 상태(x86 바이트 일치, QEMU Workspace 부팅, 객체·등급·커버리지 표)·스크린샷(`docs/images/qemu-i386-reconstructed-kernel-hostinfo-20261008.png`, 사용자 제공 화면 사본, SHA 원본과 같음, 801×661)·HOWTOCOMPILE/HOWTOUSE 안내·출처와 라이선스·도구·디렉터리 구성·저장소에 없는 것. codex 사실 확인(k1ig0efbh) 지적 다섯을 확인해 고침 — P 등급 설명(06_reconstruction/README.md:26, objects_partial 의 kern_notify·PCresume 행), PROVENANCE 가 모든 파일을 담지 않음(생성 머리 21–22·문서 제외; 내 python 대조에서 `src/driverkit/libDriver/Kernel/Event.defs`·`audio.defs` 도 행 없음 — 이번 세션 전부터의 누락, 사용자에게 보고 → plan 407 로 보완), 라이선스 TBD(PROVENANCE 364 곳)·Darwin 파일 중 BSD 고지(ansi.h, PROVENANCE:3), 입력 해시 없는 보고서(l1-sectof-diff-20261002.json).

## 407. S7-3 세부 계획 — 기록 공백 보완: `Event.defs`·`audio.defs` 의 PROVENANCE·MODIFICATIONS 행(기록만, 07 코드·빌드 변경 없음; 코딩 전, 2026-10-08)

배경: plan 406 항목 7 의 python 대조에서 `07_kernel/src/driverkit/libDriver/Kernel/Event.defs`·`audio.defs` 가 `07_kernel/PROVENANCE.tsv` 에 행이 없음을 찾았습니다(사용자 지시 "미처리 보완 진행"). 두 파일은 plan 343(2026-10-06)에서 D030 사본으로 두었으나, 그때 기록은 PROVENANCE 872→876(생성 C 3 + msg_type.h)·MODIFICATIONS 378→381 로 .defs 두 행이 빠졌습니다(plans/RECONSTRUCTION_PLAN-321-373.md 의 §343 기록 줄).

확인한 사실(이번 세션, python·sha256sum):
- 07 `Event.defs` SHA-256 cbaf090903ca6d9f146b4ca21b6f662cf851718fc750dfb9f50421cfc60a08bb(86 줄), `audio.defs` 420e65d9d68c5e50f08e378bafecafa2add078e175b74293c961de7719fb1f12(365 줄).
- Darwin 원문 `01_resources/upstream/darwin01/driverkit-1/libDriver/Kernel/Event.defs` 361d8cd4…(104 줄), `audio.defs` 20a635a4…(383 줄); 아카이브 `driverkit-139.1-1.tar.gz` 255235626e702fe52b28564c0bc5644a686f1e886697f1c567b6a4275bc43102.
- difflib: 차이는 머리 주석뿐 — Darwin 의 저작권·APSL 머리와 파일 설명 주석(Event: `File: bsd/dev/Event_server.defs`, audio: `audio.defs / MIG interface to audio driver kernel server.`)이 프로젝트 D030 머리 주석으로 바뀌었고 본문은 같습니다.
- 07 git 추적 파일 중 `src/` 의 `.defs` 로 PROVENANCE 행이 없는 것은 이 둘뿐입니다(PROVENANCE 1,045 행, 7 열).

할 일(선례: PROVENANCE `audioReply.defs` 행, MODIFICATIONS `audioReply.defs` 행):
1. `07_kernel/PROVENANCE.tsv` 끝에 두 행을 덧붙입니다(중간 삽입은 문서들이 인용한 행 번호를 밀므로 하지 않음). 열: destination · `authored` · `255235626e70…`(아카이브) · `darwin01/driverkit-1/libDriver/Kernel/<이름>` · D030 문구(nearly the same as Darwin 0.1 …, body verbatim, head comment replaced, Darwin notices not included, D017) · 작성 2026-10-06(plan 343)·파일 SHA-256·Darwin 파일 SHA-256·MIG 입력(생성 C, s5p343-mig2)·행 추가 plan 407 · 근거 `06_reconstruction/evidence/x86-EventServer.md` / `x86-audioServer.md`.
2. `07_kernel/MODIFICATIONS.md` 끝에 두 행(날짜 2026-10-08, 작성일 2026-10-06 은 설명에).
3. 검사(python): 행 수 1,046→1,048·552→554, 모든 행 7 열, destination 중복 없음, 새 행의 SHA 가 실제 파일과 같음, `.defs` 누락 0, 기존 행 바이트 그대로(앞부분 접두 비교).
4. 기록: 이 절에 결과, §406 항목 7 의 "사용자에게 보고" 뒤에 "→ plan 407 로 보완".

하지 않는 것: 07 `.defs` 본문·머리 수정, 빌드, 다른 표(objects_*·functions) 수정.

codex 교차검토(gpt-6.1-sol, k83bqzgmu) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 계획의 해시·줄 수·머리 주석만 다름·`.defs` 누락 둘뿐이 맞음 | 이번 세션 sha256sum, python difflib, PROVENANCE destination 과 git ls-files 대조(누락 `.defs` 2) | ✅(이미 내가 측정한 값과 같음; codex 가 인용한 매니페스트 줄은 쓰지 않음) |
| 끝에 덧붙이는 것이 맞음(행 번호 인용이 있음) | 이 계획 항목 1 의 이유와 같음; PROVENANCE·MODIFICATIONS 마지막 바이트 `0a`(xxd) | ✅ |
| "1,045 행"은 머리 뺀 레코드, 1,046→1,048 은 물리 줄 수 — 구분해 적을 것 | wc -l 1046, csv 레코드 1045 | ✅ 검사 문구를 고침(아래 3) |
| MODIFICATIONS 는 5 열, "7 열"은 PROVENANCE 만 | MODIFICATIONS.md:12 머리 `| Date | File | Original version | Change | Evidence |` | ✅ |
| MODIFICATIONS 변경 칸에 "nearly the same as Darwin 0.1 …"·본문 그대로·머리 교체·고지 없음·작성 plan 343·기록 plan 407 을 넣을 것 | MODIFICATIONS.md:375(audioReply.defs 선례), AGENTS.md:6(D030) | ✅ |
| 근거 md(x86-EventServer.md·x86-audioServer.md)에 입력 .defs 출처 문단을 덧붙일 것 | 두 파일 전문을 읽음 — 생성물 검증만 있고 .defs 출처 설명 없음 | ✅ 짧은 문단 추가 |
| objects·functions·README 는 고칠 필요 없음 | 이 보완은 객체 결과를 바꾸지 않음(07 코드 변경 없음) | ⏭️(행동 변화 없음; 인용 줄은 쓰지 않음) |
| **objc 머리 18 개(PROVENANCE 964–978·985–987)가 MODIFICATIONS 에 없음**, D047 은 MODIFICATIONS 에도 문구를 요구 | python: MODIFICATIONS 파일 칸 467 개와 PROVENANCE destination 대조 → 18 개 모두 없음; DECISIONS.md:51 D047 끝 "파일 머리·PROVENANCE·MODIFICATIONS 에 "nearly the same as Darwin 0.1 objc-1 <file>"" 확인; 18 개 SHA 가 PROVENANCE 기록과 같고 Darwin 원문과의 차이가 모두 첫 코드 줄 앞(머리 주석)뿐(difflib) | ✅ **새 발견** — 같은 종류의 기록 공백이므로 이번 보완에 넣음(아래 5) |
| 그 밖의 추적 소스 파일 누락 없음, 생성 머리 22 개는 README 예외 | 내 대조: "nearly the same" 또는 authored 이면서 MODIFICATIONS 에 없는 행은 위 18 + spl.h(:251)·diskstruct.h(:654) — 둘은 Darwin 문장을 옮기지 않음(PROVENANCE 문구 "no text copied"·"no reference text") → D030 문구 대상 아님 | ⚖️ 누락 18 은 확인, 생성 머리 22 개 수는 이 작업에 쓰지 않음 |

보강한 할 일:
3. 검사(python): 물리 줄 수 PROVENANCE 1,046→1,048(레코드 1,045→1,047), MODIFICATIONS 552→572(행 2+18); PROVENANCE 모든 레코드 7 열·destination 중복 없음; MODIFICATIONS 새 행 5 열·각 행에 "nearly the same as Darwin 0.1" 문구; 새 PROVENANCE 행 SHA 가 실제 파일과 같음; `.defs` 누락 0; D030/D047 "nearly the same" 행 가운데 MODIFICATIONS 에 없는 것 0; 기존 내용은 앞부분 접두 비교로 바이트 그대로.
5. `07_kernel/MODIFICATIONS.md` 끝에 objc 머리 18 행(날짜 2026-10-08; 선례 MODIFICATIONS `src/objc-runtime/maptable.m` 행 꼴; 원판 `objc-1.tar.gz sha256 3809cc3d…` `darwin01/objc/<이름>`; 변경 칸 "whole file nearly the same as Darwin 0.1 objc-1 <이름> (body verbatim; leading notice comments replaced by the project head comment), D030/D047; authored 2026-10-07 (plan 356/358/359); record added 2026-10-08 (plan 407)"; 근거는 각 PROVENANCE 행의 근거 칸).
6. 근거 md 두 곳(x86-EventServer.md·x86-audioServer.md)에 입력 .defs 출처 문단.

결과(2026-10-08, scratchpad `rec407.py`, 먼저 시험 실행 뒤 `--write`):
- `07_kernel/PROVENANCE.tsv` 물리 줄 1,046→1,048(레코드 1,045→1,047): `Event.defs`·`audio.defs` 행(작성 plan 343, Darwin 파일 SHA 포함, "row added … plan 407").
- `07_kernel/MODIFICATIONS.md` 552→572: 두 `.defs` 행 + objc 머리 18 행(PROVENANCE 964–978·985–987; 각 행 SHA 를 실제 파일과 대조한 뒤 씀).
- 근거 md 두 곳(`x86-EventServer.md`·`x86-audioServer.md`)에 입력 출처 문단 추가.
- 검사(python): 기존 바이트는 접두로 그대로, PROVENANCE 7 열·destination 중복 0, 새 MODIFICATIONS 행 5 열·문구 포함, `src/` `.defs` 누락 0, "nearly the same" PROVENANCE 행 가운데 MODIFICATIONS 에 없는 것 0. 07 코드·빌드 변경 없음.
