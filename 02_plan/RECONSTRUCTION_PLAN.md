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

## 보관된 세부 계획 색인 (§11–482)

§11–244 는 절 번호·내용을 바꾸지 않고 `02_plan/plans/` 의 보관 파일 세 개로 옮겼다(2026-10-03, 사용자 결정 D026). §245–320 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-245-320.md` 로 옮겼다(2026-10-05, 사용자 지시 “완료된 작업은 완료 문서로 분리”). 기존 인용 "RECONSTRUCTION_PLAN.md N"(N = 11–244)은 아래 색인의 보관 파일에서 같은 번호 절을 찾는다. §321–373 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-321-373.md` 로 옮겼다(2026-10-07, 사용자 지시 “완료된 작업은 완료 문서로 분리해도 됩니다”; 이 묶음 안의 진단 메모 §341·365·369·371 도 함께 옮김 — 이어지는 진단은 §374). §374 부터는 이 파일 끝에 이어 쓴다. 옮김 검증: 보관 파일 본문을 이어 붙이면 원래 줄과 같음(Python, 아래 숫자). §374–408(x86 마무리, L2·L3)과 §409–436(m68k M0–M3)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-374-408.md`·`plans/RECONSTRUCTION_PLAN-409-436.md` 로 옮겼습니다(2026-10-09, 사용자 지시 “완료된 작업은 알맞게 정리”). 이 옮김의 검증(Python): 두 보관 파일의 본문 1162·1736 줄이 원래 줄과 같고, 남은 본문은 원래 파일에서 그 줄들을 빼고 색인 63 줄을 더한 것과 같습니다. §437 부터는 이 파일 끝에 이어 씁니다. §437–447·§449–457(m68k M3 끝·M5)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-437-457.md` 로 옮겼습니다(2026-10-15, 사용자 지시 “완료된 내용은 정리”). §448 은 멈춘 절(사용자 결정 대기)이라 본문에 남겼습니다. 이 옮김의 검증(Python): 보관 파일 본문 1348 줄이 원래 줄과 같고, 남은 본문은 원래 파일에서 그 줄들을 빼고 색인 21 줄을 더한 것과 같습니다(색인 제목·머리 문단 두 줄 고침 포함). §458 부터는 이 파일 끝에 이어 씁니다. §448·§458–469(m68k M5 의 `ns_timer`·`in_pcb`…`nfs`)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-448-469.md` 로 옮겼습니다(2026-10-16, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 에서 완료된 내용은 정리합니다”). §448 은 §468·§469 로 끝나 함께 옮겼습니다. 이 옮김의 검증 숫자는 아래 python 검사로 냈습니다(보관 본문 1343 줄). §470 부터는 이 파일 끝에 이어 썼습니다. §470–482(m68k M5 의 남은 객체 조사와 `kern_exit`…`miniMon`)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-470-482.md` 로 옮겼습니다(2026-10-23, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 이 옮김의 검증(python): 보관 본문 1707 줄이 원래 줄과 같고, 남은 본문은 원래 파일에서 그 줄들을 빼고 색인 13 줄과 "현재 상태와 다음 일" 절을 더한 것과 같습니다(색인 제목·머리 문단 고침 포함). §483 부터는 이 파일 끝에 이어 씁니다.

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
- §437 M3-13 세부 계획 — m68k `_panic` 의 ROM Monitor 줄을 덮어쓰기 소스로 시험(x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §438 M3-14 세부 계획 — m68k 구성 값 전체 재확인과 `KERNOBJC 0` 시험(x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §439 M3-15 세부 계획 — 다시 만든 m68k 객체로 §418 의 미결정 경계 판정(07 변경 없음; 표는 새 판으로; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §440 M3-16 세부 계획 — 경계 규칙 4(a 쪽 끝 함수 + b 쪽 첫 바이트의 맞닿음)로 k=130 다시 판정(사용자 지시 "진행합니다"; 07 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §441 M3-17 세부 계획 — m68k `need_ast` 의 정의 자리와 `_hardclock` 의 `_clock_value` 경로(조사·결정 대기; 07 변경 없음, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §442 M3-18 세부 계획 — m68k 커널 비공개 레지스터 색인(`PC`·`SP`·`PS`·`R0`·`R1`)과 남은 컴파일 실패 3 개(조사·결정 대기; 07 변경 없음, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §443 M3-19 세부 계획 — M3 끝 조건 점검: 덮어쓰기 구조체 오프셋 탐침과 근거 집계(07 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §444 M5-1 세부 계획 — m68k `mach_process.c`·`kern_exec.c` 의 PC 쓰기를 SDK `PCH`/`PCL` 로 작성(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §445 M5-2 세부 계획 — m68k PMON 1: `kern_exec` 의 `pmonlogexec` 호출(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §446 M5-3 세부 계획 — m68k PMON 2: `vm_fault` 의 사건 마스크 누적과 `pmonlogevent`(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §447 M5-4 세부 계획 — m68k PMON 2b: `vm_pageout_scan` 의 두 기록 자리(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §448 M5-5 세부 계획 — m68k `ns_timer.c`: `ns_div`·`ns_div_val` 의 68020 나눗셈 판(D024; x86 트리 변경 없음; 코딩 전, 2026-10-09) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §449 M5-6 세부 계획 — m68k `ufs_vnodeops`·`ufs_inode` 에서 i386 바이트 교환 빼기(NeXTMach 꼴 복원; x86 트리 변경 없음; 코딩 전, 2026-10-10) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §450 M5-7 세부 계획 — m68k `ufs_vfsops`: i386 바이트 교환 7 문장 빼기와 `mountfs` 프레임 자리 메움 크기(x86 트리 변경 없음; 코딩 전, 2026-10-10) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §451 M5-8 세부 계획 — m68k `ufs_dir`: 디렉터리 바이트 교환을 매크로로 지우고 NeXTMach `brelse()` 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-10) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §452 M5-9 세부 계획 — m68k `ufs_alloc`: 실린더 그룹 바이트 교환과 `blkpref` 의 큰 끝 읽기를 빼고 NeXTMach 검사 꼴 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-10) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §453 M5-10 세부 계획 — m68k `kern_shutdown`: `boot()` 의 `us_spin` 을 SDK `DELAY` 로(x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §454 M5-11 세부 계획 — m68k `init_main`: Objective-C·`kmEnableAnimation`·`autoconf`·`setconf` 빼기, `ns_timer_init`·`softint_th` 스레드 넣기(x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §455 M5-12 세부 계획 — m68k `kern_clock`: `hardclock` 의 `SIMPLE_CLOCK` 블록(`clock_value`·`last_hardclock`·64 비트 나눗셈, `tick` → `myticks`)(x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §456 M5-13 세부 계획 — m68k `kern_uname`: `machine` 필드를 `machine_type` 점프 표로(x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §457 M5-14 세부 계획 — m68k `ufs_dsort`: 고전 `disksort` 빼기와 NeXTMach `spldma()` 되살리기(x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-437-457.md](plans/RECONSTRUCTION_PLAN-437-457.md)
- §458 M5-15 세부 계획 — m68k `in_pcb`: MULTICAST 블록의 `ifp` 꼴(작성 블록의 소스 꼴)과 범용 변형 시험 도구(x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §459 M5-16 세부 계획 — m68k `ip_output`: 레지스터 배정 차이의 소스 꼴 찾기(변형 시험; x86 트리 변경 없음; 코딩 전, 2026-10-15) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §460 M5-17 세부 계획 — m68k `vm_kern`: `kmem_alloc_prim` 의 넷째 인자 `find_space`(x86 트리 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §461 M5-18 세부 계획 — m68k `ip_icmp`: `icmp_sendMaskPacket` 의 마스크 대입·시험 꼴(x86 트리 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §462 M5-19 세부 계획 — m68k `vfs_dnlc`: 큐 도우미 넷을 `static inline` 으로(x86 트리 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §463 M5-20 세부 계획 — m68k `tcp_input`: `ti_len` 의 `htons` 재대입과 `tcp_mss` 의 `offer` 비교 꼴(x86 트리 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §464 M5-21 세부 계획 — 코드가 맞은 m68k 16 객체의 bss 자리: `zerofill_check.py` 를 m68k 로 넓혀 "reference-inferred" 판정(07 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §465 M5-22 세부 계획 — 코드 차이가 작은 m68k 4 객체(`kern_fork`·`kalloc`·`vm_pager`·`nfs_client`)의 소스 꼴 변형 시험(07 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §466 M5-23 세부 계획 — m68k `kdp`: `kdp_regions` 응답의 영역 상수(07 변경은 m68k 덮어쓰기; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §467 M5-24 세부 계획 — m68k `nfs_subr`(함수 순서)·`nfs_vfsops`(쓰이지 않는 static `hostpath`): -O2/-O3 출력 차이(코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §468 M5-25 세부 계획 — m68k `ns_timer`: 콜아웃 큐 작성(사용자 선택 "(나)", §448.2; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §469 M5-26 세부 계획 — m68k `ns_timer` 남은 여섯 함수: `sched_usec_elapsed`(나눗셈)·`microtime`·`microboot`·`us_timeout`·`us_abstimeout`·`us_untimeout`(코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-448-469.md](plans/RECONSTRUCTION_PLAN-448-469.md)
- §470 M5-27 세부 계획 — 코드 차이가 남은 m68k 19 객체의 현재 상태 조사(survey; 07 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §471 M5-28 세부 계획 — m68k `kern_exit`(`od_unlock_check`)·`kern_proc`(`alloc_posix_proc`)·`kalloc`(`realloc` 비교 꼴)(코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §472 M5-29 세부 계획 — m68k `mfs_prim`(`mfs_map_size` 의 double 계산)·`cmu_syscalls`(`table` 의 스택 정리 자리)(코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §473 M5-30 세부 계획 — m68k `time_stamp`(`event_set_ts`)·`mach_clock`(`time_of_boot`·`service_timer` 자리)(코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §474 M5-31 세부 계획 — m68k `igmp`: `IGMP_RANDOM_DELAY` 덧셈 순서와 `igmp_fasttimo` 의 멀티캐스트 순회 함수(코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §475 M5-32 세부 계획 — m68k `kern_fork`(`switch_unix_context` 의 주소 묶음)·`nfs_client`(`nfs_attrcache_va` 의 레지스터) 2 차 변형 시험(07 변경 없음; 코딩 전, 2026-10-16) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §476 M5-33 세부 계획 — m68k `ipc_mig` `msg_rpc` 의 레지스터 배정(`map` 이 a5 에 있는가)(07 변경 없음; 코딩 전, 2026-10-17) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §477 M5-34 세부 계획 — m68k `nfs_client` `nfs_attrcache_va` 의 반환형(`void`)(07 변경 없음; 코딩 전, 2026-10-17) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §478 M5-35 세부 계획 — m68k `ufs_subr` `bufstats` 의 `counts` 크기(상수 대 가변 길이 배열)(07 변경 없음; 코딩 전, 2026-10-23) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §479 M5-36 세부 계획 — m68k `mach_net` `netipc_listen` 의 최적화 해제(`#pragma CC_OPT_OFF`)(07 변경 없음; 코딩 전, 2026-10-23) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §480 M5-37 세부 계획 — m68k `netif`: 정적 함수 자리·`if_ioctl` 의 `if_control` 직접 호출·`if_attach` 의 hostid 블록(07 변경 없음; 코딩 전, 2026-10-23) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §481 M5-38 세부 계획 — m68k `miniMon`: 디버거 잠금 호출·`mm_getline` 자리·명령 고리 꼴(07 변경 없음; 코딩 전, 2026-10-23) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)
- §482 M5-39 세부 계획 — m68k `miniMon` `safe_prf` 의 레지스터 하나(d1/d0) 진단 변형(07 변경 없음; 코딩 전, 2026-10-23) → [plans/RECONSTRUCTION_PLAN-470-482.md](plans/RECONSTRUCTION_PLAN-470-482.md)

## 현재 상태와 다음 일 (2026-10-23)

- x86: 07 소스로 다시 만든 커널이 원본과 바이트 단위로 같습니다. 07 을 고칠 때마다 x86 전체 재빌드·링크 `cmp` 로 다시 확인합니다(마지막 s6lh·`s6p482-ln1`).
- m68k M5(공통부 208 객체): 203 개(97.6%)가 코드 검증되었습니다. OBJECT_MATCH 177, 명시 배치 `ufs_alloc` 1, "코드 검증 + bss 추정" 25 입니다(§482.5).
- 코드 차이가 남은 m68k 객체는 5 개입니다. 차이 내용은 §470.2 의 표(보관본)에 있습니다.
  - `nfs_client`: 레지스터 하나(d0/d1). §465·§475·§477 의 꼴로 풀리지 않아 새 근거가 생길 때까지 미룹니다.
  - `tty`, `callout`, `kdp_udp`, `swapfs`: 아직 다루지 않았습니다.
- 남은 객체에서 자주 나온 원인(§479–482): x86 `-O3` 와 m68k `-O2` 의 정적 함수 출력 순서·인라인 차이, x86 바이트로 정해지지 않던 m68k 전용 줄(`#if i386`·`#if m68k`), 선언 형(`void`/`int`)이 바꾸는 레지스터, `#pragma CC_OPT_OFF`.
- SPARC: 에뮬레이터를 sparcstep 포크로 바꾸는 작업이 진행 중입니다(`02_plan/EMULATION_PLATFORM_PLAN.md`; 부팅 시험 S1 미완).

