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

## 보관된 세부 계획 색인 (§11–469)

§11–244 는 절 번호·내용을 바꾸지 않고 `02_plan/plans/` 의 보관 파일 세 개로 옮겼다(2026-10-03, 사용자 결정 D026). §245–320 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-245-320.md` 로 옮겼다(2026-10-05, 사용자 지시 “완료된 작업은 완료 문서로 분리”). 기존 인용 "RECONSTRUCTION_PLAN.md N"(N = 11–244)은 아래 색인의 보관 파일에서 같은 번호 절을 찾는다. §321–373 도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-321-373.md` 로 옮겼다(2026-10-07, 사용자 지시 “완료된 작업은 완료 문서로 분리해도 됩니다”; 이 묶음 안의 진단 메모 §341·365·369·371 도 함께 옮김 — 이어지는 진단은 §374). §374 부터는 이 파일 끝에 이어 쓴다. 옮김 검증: 보관 파일 본문을 이어 붙이면 원래 줄과 같음(Python, 아래 숫자). §374–408(x86 마무리, L2·L3)과 §409–436(m68k M0–M3)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-374-408.md`·`plans/RECONSTRUCTION_PLAN-409-436.md` 로 옮겼습니다(2026-10-09, 사용자 지시 “완료된 작업은 알맞게 정리”). 이 옮김의 검증(Python): 두 보관 파일의 본문 1162·1736 줄이 원래 줄과 같고, 남은 본문은 원래 파일에서 그 줄들을 빼고 색인 63 줄을 더한 것과 같습니다. §437 부터는 이 파일 끝에 이어 씁니다. §437–447·§449–457(m68k M3 끝·M5)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-437-457.md` 로 옮겼습니다(2026-10-15, 사용자 지시 “완료된 내용은 정리”). §448 은 멈춘 절(사용자 결정 대기)이라 본문에 남겼습니다. 이 옮김의 검증(Python): 보관 파일 본문 1348 줄이 원래 줄과 같고, 남은 본문은 원래 파일에서 그 줄들을 빼고 색인 21 줄을 더한 것과 같습니다(색인 제목·머리 문단 두 줄 고침 포함). §458 부터는 이 파일 끝에 이어 씁니다. §448·§458–469(m68k M5 의 `ns_timer`·`in_pcb`…`nfs`)도 같은 방식으로 `plans/RECONSTRUCTION_PLAN-448-469.md` 로 옮겼습니다(2026-10-16, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 에서 완료된 내용은 정리합니다”). §448 은 §468·§469 로 끝나 함께 옮겼습니다. 이 옮김의 검증 숫자는 아래 python 검사로 냈습니다(보관 본문 1343 줄). §470 부터는 이 파일 끝에 이어 씁니다.

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

## 470. M5-27 세부 계획 — 코드 차이가 남은 m68k 19 객체의 현재 상태 조사(survey; 07 변경 없음; 코딩 전, 2026-10-16)

사용자 지시(2026-10-16): 남은 작업의 2 번(M5 코드 차이 객체)을 진행합니다. 앞서 "차이가 작은 것부터" 를 권했습니다.

배경:
- 대상은 netif, miniMon, igmp, time_stamp, mfs_prim, nfs_client, kern_fork, cmu_syscalls, ufs_subr, kern_exit, ipc_mig, kalloc, kern_proc, mach_clock, tty, callout, kdp_udp, mach_net, swapfs 입니다.
- 이전 차이 수치는 §441 객체(`08_build/runs/m3p441-cc1`)와 scratchpad 도구로 낸 것이고, scratchpad 집계는 남아 있지 않습니다. 그 뒤 07·덮어쓰기·헤더가 여러 번 바뀌었으므로 지금 상태로 다시 잽니다.
- 원본 객체 범위는 `06_reconstruction/m68k-objects.tsv` 에 19 개 모두 정확한 값(start_lo = start_hi, end_lo = end_hi)으로 있습니다.
  - 크기: netif 1550, miniMon 922, igmp 1420, time_stamp 200, mfs_prim 4360, nfs_client 1224, kern_fork 1468, cmu_syscalls 1682, ufs_subr 1806, kern_exit 3262, ipc_mig 2346, kalloc 764, kern_proc 1824, mach_clock 964, tty 13698, callout 2994, kdp_udp 2238, mach_net 1700, swapfs 3908 B(표의 bytes 열).

방법(읽기 전용 분석; 07 은 바꾸지 않습니다):
1. 컴파일:
   - `stage_m68k.py --plan 469 cmd` 와 같은 205 줄(`ref_lines`)에서 19 객체의 줄만 골라 출력만 바꿉니다(`O470__<base>.o`).
   - 바탕은 지금 스테이징 `m0p469-a1-stage` 이고, run 은 `m5p470-s1` 입니다.
   - 모든 명령이 종료 0 이어야 하고, 19 객체가 모두 있어야 합니다.
2. 실기 읽기 전용 otool: 19 객체의 `otool -tv` 목록을 `08_build/artifacts/m5p470/otool/` 에 받습니다.
3. 새 도구 `10_tools/reconstruction/m5_m68k_survey.py`(읽기 전용; `cmd`·`otool`·`report`)를 만듭니다. 객체마다 다음을 기록합니다.
   - SHA-256, §441 객체와 `canon` 이 같은지. 다르면 그 뒤 바뀐 것이 있다는 뜻이므로 표시합니다.
   - L1(`--place-from-image`) 판정·이유.
   - 원본 범위 시작으로 텍스트 자리를 준 L1(`--place __TEXT,__text=<start>`)의 함수별 판정. 크기가 처음 달라지는 함수 뒤는 주소가 밀려 참고만 합니다.
   - 텍스트 크기와 원본 범위 크기, 그 차(python).
   - 원본 기호표에서 그 범위의 외부 텍스트 함수 이름으로 낸 구간 비교(`m0_m68k_cause.compare_object`). 객체에 없는 이름은 따로 적습니다.
   - 명령 단위 정렬 비교: 객체 otool 목록과 원본 목록(`08_build/artifacts/m0p414/otool-V10/image.txt`, 범위 안)을 `m0_m68k_cause` 의 정규화(절대 주소·분기 목적지 가림)로 맞춘 뒤 `difflib` 로 정렬합니다. 같지 않은 묶음 수·명령 수와 묶음이 속한 함수를 적습니다.
   - 원본에 없는 미정의 기호와 COMMON 기호.
   - 정렬 결과로 객체를 차이가 작은 순서로 줄 세웁니다. 기준은 같지 않은 명령 수, 그다음 크기 차입니다(python).
4. 기록: `09_validation/reconstruction/m5-m68k-survey-20261016.json` 과 계획의 표(§470.x).
   - 표를 보고 다음 절(§471~)에서 객체마다 원인 가설과 변형 계획을 따로 세웁니다. 이번 절에서는 07 을 바꾸지 않습니다.
5. 통과 조건(조사의 성립):
   - 19 객체가 모두 컴파일되어야 합니다.
   - 객체마다 원본 범위가 기호표의 외부 기호와 맞아야 합니다. 범위 시작은 기호이거나, 기호 없는 정적 함수이면 그 사실을 적습니다.
   - 정렬 비교는 객체 텍스트 크기와 원본 범위 크기를 함께 적습니다.

### 470.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §470 은 "그 뒤 07·덮어쓰기·헤더가 여러 번 바뀌었다" 고 적었습니다. 그런데 `m0p441-stage` 와 `m0p469-a1-stage` 의 manifest 를 비교하면 바뀐 25 개는 모두 이 19 객체와 무관한 `.c` 파일이고, 헤더 변경은 0 입니다(python). 그러니 19 객체의 입력은 §441 이후 그대로이고, §441 객체가 지금 상태를 나타냅니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 19 크기 = 끝 − 시작, 경계 정확 | python(`m68k-objects.tsv`) | ✅ |
| miniMon·kdp_udp·mach_net 은 이름 없는 함수에서 시작 | python(시작 주소에 기호표 이름 없음) | ✅ |
| cmu_syscalls·tty 범위 안에 점프 표 데이터(60·28·28 B) | 검토자 판독 | ⏭️ 줄 비교에서 "데이터 섞임" 으로 표시만 함 |
| 205 줄에서 19 줄을 고를 수 있음(m3p429-cc2 3, m3p432-int 16), 모두 `RUN`·`-O2` | 도구가 assert 로 확인 | ✅ 구현에서 assert |
| `base` 는 `L2_…__` 접두를 포함, 출력 접두만 바꿀 것 | `stage_m68k.cmd_cmd` 의 치환 방식 | ✅ |
| §441 이 19 객체의 알맞은 기준(입력 변경 없음) | 두 manifest 비교 python(바뀐 25 파일 목록) | ✅ 위 제 오류 |
| `canon` 만으로는 기호·COMMON·절 속성 비교가 빠짐 | `m3_m68k_diag.py:34-43` | ✅ obj_sig 도 함께 |
| 정규화가 상대 주소·사적 데이터 기호 표기로 가짜 차이를 냄 | 검토자 예시 | ⚖️ 줄 비교는 순위용 추정으로만 씀(판정 근거 아님). 숫자를 모두 가린 표기로 비교 |
| `compare_object` 는 첫 외부 기호 앞 정적 코드를 빼먹음(miniMon 196·kdp_udp 1292·mach_net 518 B) | 설계상 사실(`ext_spans` 는 외부 기호부터) | ✅ 앞부분 구간을 따로 둠 |
| 마지막 원본 구간이 객체 경계를 넘음(mfs_prim 끝 다음 기호 0x404e174, ufs_subr 0x4039e24) | python(끝 주소가 기호가 아님, 다음 기호) | ✅ 객체 범위로 자름 |
| 없는/남는 이름을 따로 보고해야 함 | `compare_object` 는 객체 기호만 돎 | ✅ |
| 시작 주소 자리 L1 은 고정 배치 진단으로만 의미 | 설계(§469 와 같음) | ✅ |
| 레지스터 차이와 구조 차이를 묶음별로 나눌 것 | 설계 | ✅ |
| 순위 계산식과 비교 범위를 밝힐 것 | 설계 | ✅ |

계획 수정(§470 의 3 을 대체):
- 컴파일(1)은 그대로 둡니다. 입력이 같으므로 결과가 §441 객체와 `canon`·obj_sig 모두 같아야 합니다(확인용).
- 구간을 원본과 객체에서 같은 규칙으로 만듭니다.
  - 앞부분 구간: [범위 시작, 첫 외부 기호)
  - 외부 기호마다: [그 기호, 다음 외부 기호 또는 범위 끝). 정적 함수는 앞 외부 함수에 들어갑니다.
  - 원본은 범위 끝에서 자르고, 객체는 텍스트 끝까지입니다.
  - 이름으로 짝을 짓고, 원본에만 있거나 객체에만 있는 이름을 따로 적습니다.
- 구간마다 길이 둘, 재배치 자리를 가린 바이트 같음 여부, 같지 않으면 명령 줄 비교를 적습니다.
  - 줄 비교: otool 줄을 연산자 + 피연산자로 하고 16 진 수를 모두 `N` 으로 가려 레지스터만 남깁니다. `SequenceMatcher(autojunk=False)` 로 정렬합니다.
  - 같지 않은 묶음마다 객체·원본 줄 수를 적고 종류를 나눕니다. **R** 은 줄 수와 연산자 순서가 같고 피연산자(레지스터)만 다른 것, **S** 는 그 밖입니다.
- 순위: 점수 = 같지 않은 묶음의 (객체 줄 + 원본 줄) 합, 같으면 |텍스트 크기 차| 순입니다(python). 비교한 바이트 범위(덮음)도 함께 적습니다. 점수는 다음 절의 대상을 고르는 추정치일 뿐이고 판정 근거가 아닙니다.
- L1 두 가지(자동 배치, 범위 시작 자리)를 적습니다.
- 입력 증거로 스테이징 manifest SHA, 명령 줄, 객체·목록 SHA, 정규화 메모를 적습니다.

### 470.2 조사 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-survey-20261016.json`

- run `m5p470-s1`(명령 19 개 모두 종료 0; 바탕 `m0p469-a1-stage`). 실기 krsha256 과 호스트 SHA-256 이 19 개 모두 같습니다.
- 19 객체 모두 §441 객체와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같습니다(입력이 그대로라는 §470.1 판단과 맞음).
- 순위표(점수 = 같지 않은 묶음의 객체 줄 + 원본 줄; 크기 차 = 객체 텍스트 − 원본 범위; R/S = 레지스터만 다른 묶음 / 그 밖의 묶음 수):

| 순위 | 객체 | 점수 | 크기 차(B) | R | S | 다른 구간 |
|---:|---|---:|---:|---:|---:|---|
| 1 | kalloc | 4 | 0 | 0 | 1 | `_realloc` |
| 2 | kern_fork | 5 | 0 | 1 | 1 | `_switch_unix_context` |
| 3 | nfs_client | 6 | 0 | 1 | 0 | `_nfs_attrcache_va` |
| 4 | kern_exit | 11 | -30 | 0 | 2 | `_do_exit` |
| 5 | kern_proc | 17 | 26 | 0 | 2 | `_alloc_posix_proc` |
| 6 | ipc_mig | 18 | 6 | 8 | 0 | `_msg_rpc` |
| 7 | mfs_prim | 20 | -48 | 0 | 4 | `_mfs_init` |
| 8 | cmu_syscalls | 31 | -2 | 0 | 2 | `_table` |
| 9 | ufs_subr | 65 | 54 | 10 | 5 | `_bufstats` |
| 10 | igmp | 71 | -28 | 2 | 7 | `_igmp_input`, `_igmp_joingroup`, `_igmp_leavegroup`, `_igmp_fasttimo` |
| 11 | mach_clock | 71 | 94 | 4 | 4 | `_clock_interrupt`, `_mach_clock_bootstrap` |
| 12 | mach_net | 74 | -66 | 2 | 7 | `_netipc_listen` |
| 13 | time_stamp | 80 | 24 | 1 | 7 | `_kern_timestamp` |
| 14 | tty | 101 | 16 | 25 | 9 | `_ttysetspec`, `_ttyinput`, `_ttyblkin`, `_ttcooked`, `_ttread`, `_ttyretype` |
| 15 | netif | 105 | 48 | 7 | 8 | `_if_ioctl`, `_if_collisions_set`, `_iflist_next`, `_if_detach`, `_if_attach`, `_if_output_mbuf` |
| 16 | miniMon | 154 | -74 | 1 | 7 | `<prefix>`, `_miniMonInit`, `_miniMonLoop`, `_safe_prf` |
| 17 | kdp_udp | 382 | -72 | 7 | 11 | `<prefix>`, `_kdp_raise_exception` |
| 18 | callout | 568 | 134 | 9 | 24 | `_calloutInitialize`, `_calloutDispatchDelayed`, `_calloutRemove`, `_calloutRemoveAll`, `_calloutEntryDispatchDelayed`, `_calloutEntryDispatchWithArgumentDelayed`, `_calloutEntryRemove` |
| 19 | swapfs | 1505 | -146 | 24 | 30 | `_logswap`, `_compress_data`, `_uncompress_data` |

- 앞쪽 다섯의 차이 내용(otool 목록 나란히; 원본 주소의 기호는 symbols.tsv):
  - `kalloc` `_realloc`: 비교 피연산자 순서만 다릅니다. 우리는 `cmpl a4,d0; bls`, 원본은 `cmpl d0,a4; bcc` 입니다(크기 같음).
  - `kern_fork` `_switch_unix_context`:
    - 원본은 공통 기호 `_active_u`(8 B)의 +4 와 +0 에 절대 주소로 바로 씁니다(`movel a0@(0x80:w),0x40b57d4:l` … `0x40b57d0:l`).
    - 우리는 `lea _active_u+4,a1` 뒤 `a1@`·`a1@(-4)` 로 씁니다.
  - `nfs_client` `_nfs_attrcache_va`: 레지스터 하나만 다릅니다(`moveq #124,d1` 대 `d0`).
  - `kern_exit` `_do_exit`(원본 30 B 김):
    - 원본에만 `moveb _machine_type,d0; beq …; cmpb #2,d0; bne …; … movew a1@(0x30:w),a1; movel a1,sp@-; bsr _od_unlock_check` 묶음이 있습니다. m68k(NeXT 광디스크) 전용 호출로 보입니다.
  - `kern_proc` `_alloc_posix_proc`(우리 26 B 김):
    - 원본은 `kalloc(30)` 뒤 `bzero(p, 30)` 을 부르고 `clrl a2@` 를 한 뒤 p 를 돌려줍니다.
    - 우리는 상수 틀(__const)을 통째로 복사합니다.
- 줄 비교는 순위용 추정입니다. `cmu_syscalls` 의 차이는 점프 표(데이터) 자리에 걸쳐 있어 해석에 주의해야 합니다(§470.1).
- 다음: 위 다섯을 한 절씩(§471~) 계획합니다. 원본 바이트·참고 코드(NeXTMach)에서 원인을 확인하고, 변형 시험, codex 교차검토, 사용자 결정 순서로 갑니다.

## 471. M5-28 세부 계획 — m68k `kern_exit`(`od_unlock_check`)·`kern_proc`(`alloc_posix_proc`)·`kalloc`(`realloc` 비교 꼴)(코딩 전, 2026-10-16)

§470.2 순위의 앞쪽 가운데, 원인을 원본 바이트와 참고 코드로 설명할 수 있는 셋을 다룹니다. `kern_fork`·`nfs_client` 는 §465 에서 시험한 꼴로 풀리지 않았고, 새 가설이 아직 없으므로 뒤로 미룹니다.

확인한 사실(§470 목록·기호표·참고 코드를 직접 읽음):
- **`kern_exit` `_do_exit`**(원본이 30 B 더 김):
  - 원본은 `bsr _crfree` 뒤에 다음을 둡니다. `moveb _machine_type,d0; beq L; cmpb #2,d0; bne S; L: movel d4,a1; movew a1@(0x30:w),a1; movel a1,sp@-; bsr _od_unlock_check`. 곧 `machine_type` 이 0 또는 2 이면 `od_unlock_check(p->p_pid)` 입니다.
  - 기호는 `_machine_type` 0x40b61ac(공통), `_od_unlock_check` 0x407a3ac 입니다.
  - NeXTMach `bsd/kern_exit.c:193-197` 은 같은 자리(`crfree(utask->uu_cred);` 바로 뒤)에 `#if NeXT` / `#if NOD > 0` / `od_unlock_check(p->p_pid);` 를 둡니다. 원본 m68k 는 여기에 기계 종류 조건이 더해진 꼴입니다.
  - 07 `kern_exit.c` 는 198 행 `crfree` 뒤에 이 블록이 없습니다(x86 원본에 맞춤). 07 의 `od.h` 는 `NOD 0` 이고, 07 에서 `NOD` 를 쓰는 곳은 없습니다(`#import <od.h>` 한 줄뿐).
  - 기계 종류 상수는 NeXTMach `next/scr.h:34-37`(`NeXT_CUBE 0`·`NeXT_X15 2`)에 있습니다. m68k 덮어쓰기 `kern_uname.c` 가 같은 줄을 D076 으로 복사해 썼습니다. `machine_type` 은 SDK `bsd/m68k/cpu.h:51` 의 `extern u_char` 입니다.
- **`kern_proc` `_alloc_posix_proc`**(우리가 26 B 더 김):
  - 원본은 `kalloc(0x1e)` 뒤에 `bzero(px, 0x1e)`(`_bzero` 0x4092e12), `clrl a2@` 를 하고 px 를 돌려줍니다.
  - 07 은 411 행 `static const struct posix_proc posix_proc_zero = { 0 };` 와 419 행 `*px = posix_proc_zero;`(x86 원본에 맞춘 꼴)입니다.
  - `struct posix_proc` 의 첫 필드는 `pid_t p_pid` 입니다(SDK `bsd/sys/proc.h:258`). 따라서 `clrl a2@` 는 `px->p_pid = 0` 에 해당합니다.
  - 우리 m68k 객체에는 `__TEXT,__const`(상수 틀)가 있습니다(L1 사유 `__TEXT,__const: unverified`).
- **`kalloc` `_realloc`**:
  - 비교 피연산자 순서만 다릅니다. 원본은 `cmpl d0,a4; bcc`(`size - *sizep`, 같거나 크면 `*sizep` 쪽)이고, 우리는 `cmpl a4,d0; bls` 입니다.
  - 07 은 `if (size < *sizep) bcopy(addr, new+2, size); else bcopy(addr, new+2, *sizep);`(07 `kern/kalloc.c` 313–316 행)입니다.
  - §465 의 T(삼항식)는 크기가 754 B 로 줄었고, R(`size >= *sizep`)은 다른 불일치였습니다.

방법(`m5_m68k_srcvar.py`, 객체마다 명세 하나, 바탕 `m0p469-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `O470__…`):
- `kern_exit`(run `m5p471-e1`):
  - `X1`: 머리의 `#import <od.h>` 묶음 뒤에 `extern u_char machine_type;`, `NeXT_CUBE`·`NeXT_X15` 정의, `extern void od_unlock_check();` 를 둡니다. `crfree` 뒤에 `if (machine_type == NeXT_CUBE || machine_type == NeXT_X15) od_unlock_check(p->p_pid);` 를 넣습니다.
  - `X2`: 같은 선언에 `switch (machine_type) { case NeXT_CUBE: case NeXT_X15: od_unlock_check(p->p_pid); }` 꼴입니다.
- `kern_proc`(run `m5p471-p1`):
  - `P1`: 복사를 `bzero((caddr_t)px, sizeof (struct posix_proc)); px->p_pid = 0;` 로 바꾸고 상수 틀 정의를 뺍니다.
  - `P2`: P1 이되 상수 틀 정의를 남깁니다. 쓰이지 않는 static const 가 -O2 에서 나오는지 보는 진단입니다.
- `kalloc`(run `m5p471-k1`):
  - `A1`: `if (*sizep > size)`(가지 그대로)
  - `A2`: `if (*sizep <= size) bcopy(…*sizep) else bcopy(…size)`
  - `A3`: `if (size > *sizep) bcopy(…*sizep) else bcopy(…size)`
- 판정에는 `m5_m68k_nst.py` 의 함수별 K 대비 비교를 쓰지 않습니다(그 도구는 ns_timer 전용). 대신 다음을 봅니다.
  - L1(`--place-from-image`) 판정·사유: `kern_exit` 는 OBJECT_MATCH, `kern_proc`·`kalloc` 는 사유가 `__DATA,__bss: unverified` 하나여야 합니다.
  - 원본에 없는 미정의 기호 0, COMMON·외부 텍스트 정의가 K 와 같음. `kern_proc` 의 지역 기호 `posix_proc_zero` 가 빠지는 것은 예상입니다.
  - 대조 K 가 `control_ref` 를 재현하지 못하면 그 객체는 멈춥니다.
- x86 확인: `kalloc` 의 A 꼴은 본 파일에 둘 수 있는지 `m5_x86_srcvar.py`(바탕 s6l5; 이 세 파일은 s6l5 뒤 바뀌지 않음)로 봅니다. `kern_exit`·`kern_proc` 는 m68k 전용 코드라 덮어쓰기에 둡니다.
- 고르기: 객체마다 기준을 통과한 꼴이 하나면 그것을 쓰고, 바이트로 구별되지 않는 꼴이 여럿이거나 자리(본 파일/덮어쓰기)를 정해야 하면 사용자에게 묻습니다. 없으면 진단을 기록하고 멈춥니다.
- 결정 뒤: 덮어쓰기(`plan 471 (m68k)` 표시, `stage_m68k.py` MARKERS·EXCEPTS[471]·`--plan`), D076 선례대로 NeXTMach `scr.h` 줄과 고지, PROVENANCE·MODIFICATIONS·DECISIONS 를 고칩니다. final 은 `m5_m68k_pc.py cmd2/final` 또는 같은 성격의 검사로 L1 사유와 변형 동일성을 assert 합니다(bss 가 남는 객체는 `m5_m68k_zerofill.py objs`).

### 471.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §471 의 X1 은 `extern u_char machine_type;` 과 상수 정의를 `#import <od.h>`(61 행) 뒤에 두려 했습니다. 그 자리에서는 `u_char` 가 아직 정의되지 않습니다(시스템 헤더는 77–98 행). 또 `machine_type` 은 `sys/user.h:345` 의 `#import <machine/cpu.h>` 를 거쳐 m68k 에서 이미 선언되므로 다시 선언할 필요가 없습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_do_exit`: `crfree`(0x4005666) 뒤 0x400566c 스택 정리, 0x400566e 부터 기계 종류 검사, 0x4005684 `od_unlock_check` | 원본 목록 0x4005650–0x40056a0 직접 읽음 | ✅ 주소 문구 고침 |
| d4 = p, `p_pid` 는 +0x30 의 short(부호 확장해 넣음) | 원본 `movew a1@(0x30:w),a1`; 검토자 STABS 판독 | ✅ |
| 우리 객체의 "한 줄 더" 는 뒤로 밀린 `addqw #4,sp`; 원본 32 B − 2 B = 30 B | 객체 목록 0x1b6–0x1f0 직접 읽음; python 32−2 | ✅ |
| `kern_exit` 의 다른 구간은 재배치 밖에서 같음 | §470 기록(다른 구간 `_do_exit` 하나) | ✅ |
| 상수·선언 자리가 틀림(`u_char` 전) / `machine_type` 은 이미 선언됨 | 07 `kern_exit.c` import 줄(61, 77–98), 스테이징 `bsd/sys/user.h:345` | ✅ 위 제 오류 |
| `od_unlock_check` 의 `extern void` 는 근거 없음(NeXTMach 정의는 암묵 int) | 설계 | ✅ 선언 없이 부름(NeXTMach 와 같음) |
| `_alloc_posix_proc` 시작은 0x4007178, 0x400717c 는 a2 저장 | 원본 목록 | ✅ 문구 고침 |
| `struct posix_proc` 30 B, `p_pid` 가 0 자리 32 비트 | 검토자 STABS·python | ⏭️ 시험 객체가 판정 |
| 상수 틀은 유일한 `__const` | 검토자 판독 | ⏭️ P1 객체가 판정 |
| kalloc A1·A2 는 K·R 의 다른 표기라 같은 결과일 수 있고, A3 이 가장 새로운 시험 | 설계 | ✅ 그대로 셋 시험 |
| `cc_line` 은 세 파일 모두 한 줄(cc.cmd); 대조는 `O470__L2_154__kern_exit.o`·`O470__L2_334__kern_proc.o`·`O470__L2_324__kalloc.o` | 도구가 assert 로 확인(실행 때) | ✅ |
| 세 파일 모두 m68k 덮어쓰기 없음, s6l5 와 같음 | `ls v183.34/m68k/src/bsd/kern`·`src/kern`(§471 준비 때) | ✅ |
| `m5_m68k_pc.py` 의 cmd2/final 은 이 파일들에 맞지 않음(FILES 없음, final 은 PC 모양 검사) | §469.1 판정과 같음 | ✅ 새 final 검사 도구 |
| `generated/meta_features.h` 도 `od.h` 를 가져옴(그래도 `NOD` 조건은 없음) | 스테이징 경로 확인 | ⚖️ 결론(NOD 조건 없음) 그대로 |

계획 수정:
- `kern_exit` X1·X2: NeXTMach `scr.h:34,36` 의 `NeXT_CUBE`·`NeXT_X15` 정의를 마지막 `#import`(98 행) 뒤에 둡니다. `machine_type`·`od_unlock_check` 선언은 넣지 않습니다.
- final 검사: 새 도구 `10_tools/reconstruction/m5_m68k_final.py` 를 만듭니다.
  - `cmd`: cc.cmd 의 그 파일 한 줄에서 출력만 `F<plan>__<name>.o` 로 바꿉니다.
  - `check`: 객체마다 다음을 assert 합니다.
    - 고른 변형 객체와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같음
    - L1 사유가 미리 정한 목록과 같음(`kern_exit` 는 빈 목록 = OBJECT_MATCH, 둘은 `['__DATA,__bss: unverified']`)
    - 원본에 없는 미정의 0
    - bss 가 남는 객체는 `m5_m68k_zerofill.py objs` 통과와 이미 정한 후보들과 겹침 0

### 471.2 변형 시험 결과(2026-10-16)

- m68k(run `m5p471-e1`·`-p1`·`-k1`, 명령 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-{kern-exit,kern-proc,kalloc}-variants-p471-20261016.json`). 세 대조 K 모두 §470 객체를 재현했습니다.
  - **`kern_exit` X1 은 OBJECT_MATCH** 입니다(원본에 없는 미정의 0, COMMON·외부 정의 수 K 와 같음). X2(switch 꼴)는 맞지 않습니다. 맞는 꼴이 하나이므로 X1 을 씁니다.
  - **`kern_proc` P1 은 L1 사유가 `__DATA,__bss: unverified` 하나**이고, `__TEXT,__const` 도 없어졌습니다. 상수 틀을 남긴 P2 는 `__const` 가 남아 맞지 않습니다(쓰이지 않는 static const 도 -O2 에서 나옴). 맞는 꼴이 하나이므로 P1 을 씁니다.
  - **`kalloc` A1(`if (*sizep > size)`)은 L1 사유가 bss 하나** 입니다. A2·A3·K 는 `__TEXT,__text: fail` 입니다.
- x86(`m5_x86_srcvar.py`, 바탕 s6l5, run `m5p471-xp1`·`-xk1`; 기록 `m5-x86-{kern-proc,kalloc}-variants-p471-20261016.json`):
  - `kern_proc` P1 은 x86 원본과 다릅니다. 그래서 m68k 덮어쓰기로 둡니다(x86 원본은 상수 틀 복사 꼴).
  - `kalloc` A1 은 x86 원본과 같습니다. 자리(07 본 파일 / m68k 덮어쓰기)를 사용자에게 묻습니다.
  - `kern_exit` X1 은 m68k 전용 호출이므로 덮어쓰기에 둡니다.
- 사용자 결정 **D089**: `kalloc` A1 의 자리는 "07 본 파일 (Recommended)" 입니다. `kern_exit` X1·`kern_proc` P1 은 맞는 꼴이 하나라 그대로 쓰고, m68k 덮어쓰기에 둡니다.

### 471.3 D089 구현 계획(07 본 파일 `kalloc.c` + 덮어쓰기 둘 + x86 전체 재빌드 s6l8 + final 검사 도구; 코딩 전, 2026-10-16)

§469.4 절차를 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: 고른 변형 객체 `08_build/runs/m5p471-e1/out/P471__X1.o`·`m5p471-p1/out/P471__P1.o`·`m5p471-k1/out/P471__A1.o` 를 final 의 REF 로 씁니다. 다시 만들지 않습니다.
1. 07 편집:
   - 본 파일 `kern/kalloc.c` 313 행 `if (size < *sizep)` → `if (*sizep > size)` 로 바꾸고 줄 끝에 `/* plan 471 (D089): … */` 를 붙입니다. 가지는 그대로입니다.
   - 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_exit.c`(새 파일)는 07 본 파일에 줄을 끼우는 꼴입니다.
     - 98 행 뒤에 `plan 471 (m68k) begin … end` 묶음을 둡니다. 내용은 NeXTMach `next/scr.h:1` 고지 줄, `scr.h:34`·`:36` 의 `NeXT_CUBE`·`NeXT_X15` 정의(D076 선례)입니다.
     - 198 행 `crfree` 뒤에 `#if m68k` 묶음으로 `if (machine_type == NeXT_CUBE || machine_type == NeXT_X15)` / `od_unlock_check(p->p_pid);` 를 둡니다. 호출은 NeXTMach `bsd/kern_exit.c:195` 와 같은 글입니다.
   - 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_proc.c`(새 파일):
     - 411 행 상수 틀 정의를 `#ifndef m68k` … `#endif` 로 감쌉니다.
     - 419 행 복사를 `#if m68k` `bzero((caddr_t)px, sizeof (struct posix_proc));` / `px->p_pid = 0;` `#else` 07 줄 `#endif` 로 바꿉니다(작성, D024).
   - 확인: `stage_m68k.check_derived` 로 두 덮어쓰기를 검사하고, 본 파일에 표시 문자열이 없어야 합니다.
2. x86 전체 재빌드 s6l8(일곱 묶음, `L2_FORMS`/`L2_EXPECT` s6p398), 통과 조건은 §469.4 와 같습니다.
3. prefixdiff s6l7↔s6l8(plan 471):
   - 스테이징 차이는 `src/kern/kalloc.c` 하나여야 합니다.
   - `sha_differ_not_rid_only` 는 `x86-kalloc` 하나이고, `differing_non_stabs_equal` 이 true 여야 합니다.
4. 링크 `s6p471-ln1` → `l2_compare` 의 `identical` 과 `cmp` 가 원본과 같아야 합니다.
5. `stage_m68k.py`:
   - `X86[471] = 's6l8'`, `EXCEPTS[471] = EXCEPTS[469]` 에 `x86-kalloc`·`x86-kern_exit`·`x86-kern_proc` 사유를 더합니다.
   - `MARKERS['plan 471 (m68k)']` 를 두 파일의 줄 수와 함께 등록하고, `--plan` 문서를 고칩니다.
   - `--plan 471 stage m0p471-a1-stage` → x86gate(s6l8) → `m0p469-a1-stage` 와의 파일 차이는 셋(`src/kern/kalloc.c`·`src/bsd/kern/kern_exit.c`·`src/bsd/kern/kern_proc.c`)이어야 합니다.
6. final(새 도구 `m5_m68k_final.py`):
   - `cmd PLAN NAME=REL …` 는 cc.cmd 의 그 파일 한 줄에서 출력만 `F471__<name>.o` 로 바꿉니다.
   - `check RUN PLAN RECORD NAME:REF:EXPECTED_REASONS …` 는 객체마다 다음을 assert 합니다.
     - REF 와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같음
     - L1 사유가 정확히 기대값과 같음(`kern_exit` 빈 목록, `kern_proc`·`kalloc` `['__DATA,__bss: unverified']`)
     - 원본에 없는 미정의 0
     - bss 가 남는 객체는 `m5_m68k_zerofill.py objs` 통과
     - bss 후보는 §464 후보·§467 nfs·§469 ns_timer 후보와 겹침 0(python)
   - run `m5p471-a1`.
7. 기록:
   - PROVENANCE: kalloc.c 210 행을 그 자리에서 갱신하고, 두 덮어쓰기는 새 행으로 둡니다(중복 0).
   - MODIFICATIONS 세 행, DECISIONS D089 를 적습니다.
   - diff `x86-kalloc-plan471.diff`·`m68k-kern_exit.diff`·`m68k-kern_proc.diff` 를 만들고, evidence `x86-kalloc.md` 에 plan 471 절을 덧붙입니다.
   - 검증 기록은 s6l8 일곱, prefixdiff, link, final, zerofill 입니다.
   - 집계: OBJECT_MATCH +1(`kern_exit`), "코드 검증 + bss 추정" +2(`kern_proc`·`kalloc`), 코드 차이가 남은 객체는 19 → 16 입니다.

### 471.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §471.3 의 3 은 `sha_differ_not_rid_only` 가 `['x86-kalloc']` 이어야 한다고 적었습니다. 그런데 A1 은 줄 수를 바꾸지 않으므로, 같은 파일 이름으로 다시 빌드하면 x86 kalloc 객체가 RID 경로 말고는 아예 같을 수 있습니다. x86 시험 객체 K·A1 은 기호 602 개 가운데 원본 파일 이름 기호 하나만 다르고 `canon` 이 같습니다(python).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 끼울 자리(kern_exit 98·198 행, kern_proc 411·419 행)가 맞고, 감싸는 꼴은 본 파일 줄을 표시 밖에 두면 파생 검사 통과 | §471 준비 때 줄 읽음; 구현 뒤 실제 `stage` 가 판정 | ✅ |
| X1 의 정의는 `#if m68k` 안(98 행 뒤) — 계획 문구에 명시할 것 | 명세 `spec-kern_exit.json` 의 치환 글 | ✅ 구현에서 `#if m68k` 묶음 |
| `scr.h:1` 고지 줄은 주석뿐 → 비 STABS 영향 없음 | 그 줄은 `/* … */` 한 줄 | ✅ final 은 canon·머리·절·비 STABS 기호만 비교 |
| A1 은 조건 줄만 다름; 줄 끝 주석은 줄 번호 불변 | 명세 치환 글 비교 | ✅ |
| prefixdiff 의 `sha_differ_not_rid_only` 는 `[]` 일 수도 있음 | x86 K·A1 기호 비교 python(차이는 파일 이름 기호 하나) | ✅ 위 제 오류. 기준: `[]` 또는 `['x86-kalloc']`, `differing_non_stabs_equal` true |
| `EXCEPTS[471]` 은 `--plan` 허용에 필요; `stage`·`x86gate` 모두에 `--plan 471` | `main()` 의 `in EXCEPTS` | ✅ |
| `objs` 는 §464 기록만 봄 → 두 새 객체를 한 번에 넣고, §467·§469 후보와는 따로 겹침 검사 | `m5_m68k_zerofill.py:148`; 두 기록의 `summary.candidates`(python) | ✅ |
| 미리 돌린 zerofill: kern_proc [0x40b317c, 0x40b3180) 4 B, kalloc [0x40b3612, 0x40b3712) 256 B, 겹침 없음 | 검토자 계산 | ⏭️ final 이 판정 |
| 기대 사유를 콜론 섞인 인자로 넘기지 말 것 | 설계 | ✅ final 은 JSON 명세 파일을 받음 |

### 471.5 D089 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p471-final-20261016.json`

- 07 편집:
  - 본 파일 `kern/kalloc.c` 313 행을 `if (*sizep > size)` 로 바꾸고 주석을 붙였습니다. 줄 수는 같습니다.
  - 새 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_exit.c`(표시 줄 9)와 `kern_proc.c`(표시 줄 7)를 만들었습니다. 파생 검사를 통과했고, 본 파일에 표시 문자열은 없습니다.
- x86 전체 재빌드 s6l8:
  - 명령 804 개가 모두 종료 0 입니다(python). check 기록 일곱, 402 행 연속, problem 0, 기준선과 같음 377 입니다.
  - prefixdiff s6l7↔s6l8: 스테이징 차이는 `src/kern/kalloc.c` 하나이고, 키·명령 차이는 없습니다. RID 경로 말고 다른 객체는 없습니다(`[]`, §471.4 의 예상대로).
  - 링크 `s6p471-ln1`: `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 471 stage m0p471-a1-stage` 는 파생 검사를 통과했고, x86gate(s6l8 일곱)는 모두 같으며 v183 경로는 0 입니다. `m0p469-a1-stage` 와의 차이는 세 파일(`kalloc.c`·`kern_exit.c`·`kern_proc.c`)입니다.
  - final run `m5p471-a1`(명령 3 개, 종료 0)에서 `m5_m68k_final.py check` 의 assert 를 모두 통과했습니다.
    - `x86-kern_exit` 은 **OBJECT_MATCH** 입니다.
    - `x86-kern_proc`·`x86-kalloc` 은 L1 사유가 `__DATA,__bss: unverified` 하나입니다.
    - 세 객체 모두 고른 변형과 `canon`·머리·절 머리·비 STABS 기호가 같고, 원본에 없는 미정의는 0 입니다.
  - zerofill(`m5-m68k-p471-zerofill-20261016.json`):
    - kern_proc 은 reference-inferred [0x40b317c, 0x40b3180) 4 B 입니다.
    - kalloc 은 reference-inferred-single [0x40b3612, 0x40b3712) 256 B 입니다.
    - §464 후보와 겹침 0, §467·§469 후보와 겹침 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 170 입니다(+ 명시 배치 `ufs_alloc` 1).
  - "코드 검증 + bss 추정" 은 21 입니다.
  - 코드 차이가 남은 객체는 16 개입니다(netif, miniMon, igmp, time_stamp, mfs_prim, nfs_client, kern_fork, cmu_syscalls, ufs_subr, ipc_mig, mach_clock, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 1097 행(kalloc 210 행 갱신, 덮어쓰기 두 행 새로, 중복 0), MODIFICATIONS 629 행, DECISIONS D089 를 적었습니다.
  - diff 셋을 만들고 `x86-kalloc.md` 에 plan 471 절을 덧붙였습니다.
  - 도구: 새로 만듦 `m5_m68k_survey.py`·`m5_m68k_final.py`, 고침 `stage_m68k.py`(plan 471). 고치기 전 사본은 `08_build/artifacts/m5p471/*.before` 입니다.

## 472. M5-29 세부 계획 — m68k `mfs_prim`(`mfs_map_size` 의 double 계산)·`cmu_syscalls`(`table` 의 스택 정리 자리)(코딩 전, 2026-10-16)

§470.2 순위에서 원인 가설이 분명한 두 객체를 다룹니다. `kern_fork`·`nfs_client`·`ipc_mig` 는 레지스터·주소 배정 차이라 가설이 없어 뒤로 미룹니다.

확인한 사실(§470 목록 `08_build/artifacts/m5p470/otool/`, 원본 목록, 기호표, 참고 코드를 직접 읽음):
- **`mfs_prim` `_mfs_init`**(우리가 48 B 짧음; 다른 구간은 이 하나):
  - 원본(0x404cf06–)은 `kmem_suballoc` 뒤 `_machine_info+16`(`memory_size`, `vm_size_t`)을 읽습니다.
  - 그다음 `fmovel d0,fp0; tstl d0; bge; faddd #4.29496e+09,fp0`(부호 없는 정수 → double), `fmoveml` 로 반올림을 0 방향으로 바꾼 `fmovel fp0,d0`(double → int), `_mfs_map_size` 저장, `cmpl #0x1000000` 상한 순서입니다. 곱셈·나눗셈은 없습니다.
  - 부동소수 코드가 d2 를 써서 원본은 d2 를 저장·복원합니다(앞뒤 한 줄씩 원본에만 있음).
  - 07 `kern/mfs_prim.c:165-167` 은 `(int) ((long long) MFS_MAP_SIZE_PER_UNIT / (long long) MFS_MEMORY_UNIT * (long long) machine_info.memory_size)`(plan 139, Darwin 0.1 `kern/mapfs.c:235-237` 와 같은 글, x86 원본으로 확인됨)입니다.
  - 두 상수는 모두 `1024 * 1024`(07 136–137 행)라 비율이 1 입니다.
  - 가설: 원본 m68k 는 같은 식을 double 로 쓴 판입니다. 비율 1.0 이 접혀 변환만 남은 꼴입니다.
- **`cmu_syscalls` `_table`**(우리가 2 B 짧음):
  - 원본은 `bsr _thread_reference`(0x40024ce) 바로 뒤에 `addqw #0x4,sp` 를 하고 `round_page`·`kmem_alloc_wait` 로 넘어갑니다. 우리는 이 스택 정리를 미룹니다.
  - 그 밖의 차이는 점프 표 값(상대 변위)뿐이고, 이 2 B 이동의 결과입니다.
  - 07 `bsd/kern/cmu_syscalls.c:451-459` 는 `task_lock(task); if (task->thread_count <= 0) { task_unlock(task); u.u_error = ESRCH; return; } th = …; thread_reference(th); task_unlock(task);`(plan 203, x86 원본에서 작성)입니다. `task_lock`·`task_unlock` 은 m68k·NeXTMach 모두 빈 매크로입니다(`kern/lock.h:102-103`, NeXTMach `kern/lock.h:153-154`).
  - 가설: 원본은 `thread_reference` 뒤에 분기(조건문 구조)가 있어 미뤄 둔 스택 정리가 그 자리에서 나왔습니다. 예를 들면 `if (task->thread_count > 0) { th = …; thread_reference(th); } else { …ESRCH…; return; }` 의 then 끝에서 else 를 건너뛰는 분기입니다.

방법(`m5_m68k_srcvar.py`, 객체마다 명세·스테이징·run 을 따로, 바탕 `08_build/runs/tools/m0p471-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체):
- `mfs_prim`(run `m5p472-m1`):
  - `F1`: `(int) ((double) MFS_MAP_SIZE_PER_UNIT / (double) MFS_MEMORY_UNIT * (double) machine_info.memory_size)`
  - `F2`: `(int) (MFS_MAP_SIZE_PER_UNIT / MFS_MEMORY_UNIT * (double) machine_info.memory_size)`
  - `F3`: `(vm_size_t)` 로 바꾼 F1(부호 없는 변환이 되어 달라야 하는 대조)
- `cmu_syscalls`(run `m5p472-c1`):
  - `C1`: `if (task->thread_count > 0) { th = …; thread_reference(th); } else { task_unlock(task); u.u_error = ESRCH; return; } task_unlock(task);`
  - `C2`: `if (task->thread_count <= 0) { task_unlock(task); u.u_error = ESRCH; return; } else { th = …; thread_reference(th); } task_unlock(task);`
- 판정(L1 `--place-from-image`):
  - `mfs_prim` 은 §470 에서 사유가 `__TEXT,__text: unverified` 하나였습니다. 맞으면 OBJECT_MATCH 이거나 bss 만 남아야 합니다.
  - `cmu_syscalls` 도 같은 기준입니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의 수가 K 와 같아야 합니다.
  - 대조 K 가 `control_ref` 를 재현하지 못하면 멈춥니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; 두 파일은 s6l5 뒤 바뀌지 않았는지 실행 전에 확인): 맞은 꼴이 x86 원본과도 같으면 자리를 사용자에게 묻고, 다르면 m68k 덮어쓰기로 둡니다.
- 고르기·결정·구현·final 은 §471 과 같습니다(`m5_m68k_final.py`, x86 본 파일 변경이 있으면 x86 재빌드·링크 cmp). 바이트로 구별되지 않는 꼴이 여럿이면 사용자에게 묻습니다.

### 472.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §472 는 `cmu_syscalls` 점프 표 값을 "상대 변위" 라고 적었습니다. 실제로는 절대 주소(지역 재배치)입니다. 원본 항목 − 객체 시작(0x4002284)과 객체 항목을 비교한 제 계산도 절대 주소로 다룬 것이고, 결과는 변경 지점 앞 0, 뒤 +2 였습니다. 또 원본에서는 뒤쪽 누적 정리가 `addaw #0x14,sp`(0x400252a)로 줄어 있습니다. 우리는 `addaw #0x18,sp`(0x2a4)이고 4 + 0x14 = 0x18 입니다(python). 곧 정리가 둘로 나뉜 꼴입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_mfs_init`: unsigned → double(상수 41f0000000000000) → 0 방향 반올림 int, 곱셈·나눗셈 없음; 뒤의 `mulul` 은 `/ 20` | 원본 목록 0x404cf06–0x404cfd2 직접 읽음 | ✅ |
| GCC 2.7.2 는 `* 1.0` 을 fast-math 없이 접음(`simplify_binary_operation`) | 검토자 인용(외부 소스, 직접 미확인) | ⏭️ 시험이 판정 |
| `(int)(double)memory_size` 직접 변환도 후보로 둘 것 | 설계 | ✅ F4 추가 |
| d2 저장·복원은 FPCR 값을 만드는 데 쓰임 | 원본 목록 `moveq #16,d2; orl d1,d2; andw #0xffdf,d2` | ✅ |
| mfs_prim 다른 구간은 같음(32 구간 중 31) | §470 기록(다른 구간 `_mfs_init` 하나) | ✅ |
| 점프 표는 절대 주소, 뒤쪽 대상은 정확히 +2 | 제 python 계산(15 항목: 0 셋, +2 열둘) | ✅ 위 제 오류(문구) |
| 뒤쪽 정리 `addaw #0x14` 대 `#0x18` | 두 목록 해당 줄 읽음, python 4+0x14 == 0x18 | ✅ |
| ESRCH 공유 경로(원본 0x400235a, 객체 0xd6)는 둘 다 있음 | §471 준비 때 목록(`ble 0x400235a`/`ble 0xd6`) | ✅ |
| C1·C2 모두 미룬 정리를 내보내는 경계를 만듦(C2 는 `expand_end_cond`) | 검토자 인용(직접 미확인) | ⏭️ 시험이 판정 |
| 대조 `O470__L2_078__mfs_prim.o`·`O470__L2_146__cmu_syscalls.o` | `ls 08_build/runs/m5p470-s1/out` | ✅ |
| `m5_m68k_srcvar.py` 는 `control_equals_ref` 를 기록만 함 | 167–168 행(§469.1 에서 읽음) | ✅ 결과에서 따로 확인 |
| `task_lock`/`task_unlock` 정의는 `kern/task.h:133-134` | 스테이징 grep 출력(§472 준비 때) | ✅ 문구 보탬 |

계획 수정:
- `mfs_prim` 에 `F4` = `(int) (double) machine_info.memory_size` 를 더합니다.
- `cmu_syscalls` 의 판정에 "뒤쪽 정리가 `addaw #0x14`" 를 포함하고, L1 결과로 봅니다.
- 두 run 모두 `control_equals_ref` 를 확인합니다.

### 472.2 변형 시험 결과(2026-10-16)

- m68k(run `m5p472-m1`·`-c1`, 명령 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-{mfs-prim,cmu-syscalls}-variants-p472-20261016.json`). 두 대조 K 모두 §470 객체를 재현했습니다(`control_equals_ref` true).
  - **`mfs_prim`: F1·F2·F4 가 OBJECT_MATCH** 이고, 세 객체는 비 STABS 로 같습니다(원본에 없는 미정의 0, COMMON·외부 정의 K 와 같음). F3(`vm_size_t` 변환)은 예상대로 다릅니다. "double 계산" 가설이 맞았습니다.
  - **`cmu_syscalls`: C1·C2 가 OBJECT_MATCH** 이고, 두 객체는 같습니다(같은 조건). "분기 경계" 가설이 맞았습니다.
- x86(`m5_x86_srcvar.py`, 바탕 s6l5; run `m5p472-xm1`·`-xc1`; 기록 `m5-x86-{mfs-prim,cmu-syscalls}-variants-p472-20261016.json`):
  - `mfs_prim` 의 F 꼴은 x86 원본과 다릅니다(x86 원본은 `long long` 꼴). 그래서 m68k 덮어쓰기로 둡니다.
  - `cmu_syscalls` C1·C2 는 x86 원본과 같습니다.
- 바이트로 구별되지 않는 꼴(mfs_prim F1·F2·F4, cmu_syscalls C1·C2)과 `cmu_syscalls` 의 자리를 사용자에게 묻습니다.
- 사용자 결정 **D090**:
  - `mfs_prim` 은 "F1 double 로 바꿈 (Recommended)" 입니다. m68k 덮어쓰기에 둡니다(x86 원본은 `long long` 꼴).
  - `cmu_syscalls` 는 "C2 else 더하기 (Recommended)" 이고, 자리는 "07 본 파일 (Recommended)" 입니다.

### 472.3 D090 구현 계획(07 본 파일 `cmu_syscalls.c` + 덮어쓰기 `mfs_prim.c` + x86 전체 재빌드 s6l9; 코딩 전, 2026-10-16)

§471.3 절차를 그대로 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p472-m1/out/P472__F1.o`·`m5p472-c1/out/P472__C2.o` 를 final 의 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집:
   - 본 파일 `bsd/kern/cmu_syscalls.c` 452–459 행을 C2 꼴로 바꿉니다. `}` 를 `} else {` 로 하고, `th = …`·`thread_reference(th);` 를 들여 쓴 뒤 `}` 를 더합니다(줄 수 +1). `} else {` 줄에 `/* plan 472 (D090): … */` 를 붙입니다.
   - 덮어쓰기 `v183.34/m68k/src/kern/mfs_prim.c`(새 파일): 165–167 행 앞에 `#if m68k /* plan 472 (m68k) begin */` F1 세 줄 `#else /* plan 472 (m68k) end */` 를 두고, 뒤에 `#endif /* plan 472 (m68k) */` 를 둡니다.
   - 확인: `check_derived` 를 통과해야 하고, 본 파일에 표시 문자열이 없어야 합니다. m68k 쪽 글은 python 으로 변형 F1 과 같은지 봅니다(주석·전처리 줄 제외).
2. x86 전체 재빌드 s6l9 를 합니다. 통과 조건은 §469.4 와 같습니다.
3. prefixdiff s6l8↔s6l9(plan 472):
   - 스테이징 차이는 `src/bsd/kern/cmu_syscalls.c` 하나여야 하고, 키·명령 차이는 없어야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-cmu_syscalls']` 여야 합니다. 줄 수가 바뀌어 STABS 가 다를 수 있습니다. `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p472-ln1` → `identical` 과 `cmp` 가 원본과 같아야 합니다.
5. `stage_m68k.py`:
   - `X86[472] = 's6l9'`, `EXCEPTS[472] = EXCEPTS[471]` 에 `x86-cmu_syscalls`·`x86-mfs_prim` 사유를 더합니다.
   - `MARKERS['plan 472 (m68k)']` 를 등록하고 `--plan` 문서를 고칩니다.
   - `--plan 472 stage m0p472-a1-stage` → x86gate(s6l9) → `m0p471-a1-stage` 와의 차이는 둘(`src/bsd/kern/cmu_syscalls.c`·`src/kern/mfs_prim.c`)이어야 합니다.
6. final: `m5_m68k_final.py`(plan 472, 두 객체 모두 기대 사유 빈 목록 = OBJECT_MATCH)로 run `m5p472-a1` 을 돌립니다.
7. 기록:
   - PROVENANCE: cmu_syscalls.c 행을 그 자리에서 갱신하고, mfs_prim 덮어쓰기는 새 행으로 둡니다.
   - MODIFICATIONS 두 행, DECISIONS D090 을 적습니다.
   - diff `x86-cmu_syscalls-plan472.diff`·`m68k-mfs_prim.diff` 를 만들고, evidence md 에 plan 472 절을 덧붙입니다.
   - 집계: OBJECT_MATCH +2, 코드 차이가 남은 객체는 16 → 14 입니다.

### 472.4 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 줄 범위(cmu_syscalls 452–459, mfs_prim 165–167)가 맞고, 줄 끝 주석은 토큰을 바꾸지 않음 | §472.3 작성 때 줄 읽음; 구현 뒤 final 이 판정 | ✅ |
| 덮어쓰기 표시 줄은 6(시작·F1 셋·`#else` 끝·`#endif`) | 구현 뒤 `check_derived` 로 확인 | ✅ |
| x86 에서 이 소스를 쓰는 객체는 `x86-cmu_syscalls` 하나 | s6l8 `cc -M` 기록 grep(파일 1 개) | ✅ |
| x86 C2 는 STABS 1036 대 s6l8 1034 → prefixdiff 에 `['x86-cmu_syscalls']` 로 나올 것 | python obj_sig STABS 수(1036 / 1034) | ✅ 허용 목록에 이미 있음 |
| m68k 다른 객체 영향 없음 | 스테이징 차이 검사가 판정 | ✅ |
| final 은 JSON 명세(`bss_records: []`, 두 객체 사유 빈 목록) | 도구 구조 | ✅ |
| PROVENANCE 553 행 그 자리 갱신, 385 행 유지 + 덮어쓰기 새 행 | 두 행 읽음(§472.3) | ✅ |

### 472.5 D090 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p472-final-20261016.json`

- 07 편집:
  - 본 파일 `bsd/kern/cmu_syscalls.c` 는 806 → 807 행입니다. 주석을 뺀 토큰이 변형 C2 와 같습니다(python).
  - 새 덮어쓰기 `v183.34/m68k/src/kern/mfs_prim.c` 는 표시 줄 6 이고, m68k 가지의 토큰이 F1 과 같습니다. 파생 검사를 통과했습니다.
- x86 전체 재빌드 s6l9:
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6l8↔s6l9: 스테이징 차이는 `src/bsd/kern/cmu_syscalls.c` 하나이고, `sha_differ_not_rid_only` 는 `['x86-cmu_syscalls']`(STABS 만; 비 STABS 같음)입니다.
  - 링크 `s6p472-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 472 stage m0p472-a1-stage` 와 x86gate(s6l9 일곱)가 모두 같고 v183 경로는 0 입니다. `m0p471-a1-stage` 와의 차이는 두 파일입니다.
  - final run `m5p472-a1`(명령 2 개, 종료 0)에서 `m5_m68k_final.py check` 를 통과했습니다. **`x86-mfs_prim`·`x86-cmu_syscalls` 모두 OBJECT_MATCH** 이고, 고른 변형과 서명이 같으며, 원본에 없는 미정의는 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 172 입니다(+ 명시 배치 `ufs_alloc` 1).
  - "코드 검증 + bss 추정" 은 21 입니다.
  - 코드 차이가 남은 객체는 14 개입니다(netif, miniMon, igmp, time_stamp, nfs_client, kern_fork, ufs_subr, ipc_mig, mach_clock, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 1098 행(553 행 갱신, 덮어쓰기 한 행 새로, 중복 0), MODIFICATIONS 631 행, DECISIONS D090 을 적었습니다.
  - diff 둘을 만들고 evidence 두 개에 plan 472 절을 덧붙였습니다.
  - 도구는 `stage_m68k.py`(plan 472)를 고쳤고, 고치기 전 사본은 `08_build/artifacts/m5p472/` 에 있습니다.

## 473. M5-30 세부 계획 — m68k `time_stamp`(`event_set_ts`)·`mach_clock`(`time_of_boot`·`service_timer` 자리)(코딩 전, 2026-10-16)

확인한 사실(§470 목록·원본 목록·기호표·참고 코드를 직접 읽음):
- **`time_stamp` `_kern_timestamp`**(원본 200 B, 우리 224 B):
  - 07 `kern/time_stamp.c` 68–69 행은 m68k 에서 `event_set_ts(&ts)` 를 부릅니다. 이 인라인 함수는 m68k 덮어쓰기 `machdep/m68k/eventc.h`(56 행에서 가져옴; PROVENANCE 1067 행, NeXTMach mk-108.1 `next/eventc.h`)에 있고, 다시 읽는 고리(`do … while (tsp->low_val < temp)`) 꼴입니다(eventc.h 104–114 행).
  - 원본(0x4054aaa–)은 다음 순서입니다.
    - `splusclock()`(0x2600)
    - `*eventc_latch` 읽기, `(h<<16)|(m<<8)|l` 을 `& 0xfffff`
    - `*event_middle ^ low` 의 bit 19 가 서 있으면 `*event_middle += 0x80000`. 그 뒤 `& 0xfff80000` 이 0 이면 `(*event_high)++`
    - `tsp->high_val = *event_high; tsp->low_val = *event_middle | low;`
    - `splx(s)`
  - 곧 하드웨어를 한 번 읽고, `event_sync` 몸체에 마스크를 더한 꼴입니다. 기호는 `_eventc_latch`·`_eventc_h`·`_eventc_m`·`_eventc_l`·`_event_middle`·`_event_high` 입니다.
  - `event_set_ts` 를 쓰는 07 소스는 `time_stamp.c` 하나입니다(grep). `time_stamp.c` 가 56 행 전에 가져오는 헤더는 `eventc.h` 를 부르지 않습니다(`mach/kern_return.h`·`kern/time_stamp.h`·`kern/clock.h` 와 그 아래, `meta_features.h` 확인).
- **`mach_clock`**(원본 964 B, 우리 1058 B):
  - `_clock_interrupt` 에 우리만 있는 64 비트 덩어리 둘이 있습니다. 07 `kern/mach_clock.c` 182·187 행의 `time_of_boot -= / += tickdelta * 1000;`(plan 235, x86 원본에서 넣음)입니다.
  - m68k 원본 기호표에 `_time_of_boot` 은 없습니다. 07 에서 `time_of_boot` 을 쓰는 곳은 이 파일(63 행 정의)과 i386 `machine_clock.c` 뿐입니다.
  - 원본은 정적 함수(spl 0x2300 = `splsched`, `telt->fcn`·`param` 읽고 `set` 지우기, `splx`, 호출 — `service_timer`)를 `_clock_interrupt` 바로 뒤, `_init_timeout_element`(0x404b11e) 앞에 둡니다. 07 은 199 행에 앞선 선언만 두고, 정의는 365–382 행(`host_adjust_time` 뒤)에 있습니다. -O2 는 소스 순서대로 냅니다(§467 과 같은 현상).
  - 레지스터 저장(a3 더 씀)과 분기 길이(`bra.w`/`.b`) 차이는 위 둘의 결과로 봅니다.

방법(`m5_m68k_srcvar.py`, 객체마다 명세·스테이징·run 을 따로, 바탕 `08_build/runs/tools/m0p472-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체):
- `time_stamp`(run `m5p473-t1`): 변형은 `time_stamp.c` 55–57 행의 `#if m68k / #import <machdep/m68k/eventc.h> / #endif` 를 고친 `eventc.h` 의 전문으로 바꿉니다. 고친 곳은 `event_set_ts` 만이고, 헤더 안 import 와 보호 매크로는 그대로입니다.
  - `E1`: `int s; register unsigned int low; s = splusclock(); low = *eventc_latch; low = (*eventc_h << 16) | (*eventc_m << 8) | *eventc_l; low &= EVENT_MASK; if ((low ^ *event_middle) & EVENT_HIGHBIT) { *event_middle += EVENT_HIGHBIT; if ((*event_middle & (~(EVENT_MASK>>1))) == 0) (*event_high)++; } tsp->high_val = *event_high; tsp->low_val = *event_middle | low; splx(s);`
  - `E2`: E1 의 비교를 `(*event_middle ^ low)` 로
  - `E3`: E1 의 증가를 `++*event_high` 로(원본은 증가 뒤 한 번 더 읽음: 0x4054b30)
  - `splusclock` 이 그 자리에서 보이는지는 컴파일이 판정합니다(안 보이면 실패로 기록하고 헤더 import 를 더한 2 차).
- `mach_clock`(run `m5p473-c1`):
  - `M1`: 63 행 정의, 182·187 행을 뺍니다. `service_timer` 정의(365–382 행)를 199 행 앞선 선언 바로 뒤로 옮깁니다(선언은 남김).
  - `M2`: 빼기만 합니다(옮기지 않음).
  - `M3`: 옮기기만 합니다.
- 판정(L1 `--place-from-image`): OBJECT_MATCH 이거나 bss 만 남아야 합니다. 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같아야 합니다(`mach_clock` 은 `_time_of_boot` 이 빠지는 것이 예상). 대조 K 가 `control_ref` 를 재현하는지(`control_equals_ref`)도 봅니다.
- x86 확인: `mach_clock` M3(옮기기)은 x86 원본과 같은지 `m5_x86_srcvar.py` 로 봅니다. `time_of_boot` 빼기와 `eventc.h` 는 m68k 전용이므로 덮어쓰기에 둡니다(`eventc.h` 는 덮어쓰기 전용 헤더라 그 파일을 고침).
- 고르기·결정·구현·final 은 §471·§472 와 같습니다.

### 473.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §473 은 `service_timer` 정의를 365–382 행이라 적었습니다. 실제로는 365–381 행이고(381 행이 `}`), `mach_clock_bootstrap`(351 행) 바로 뒤에 있습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_kern_timestamp` 판독이 맞음; 0x4054b30 의 다시 읽기는 실제이나 후위·전위 증가의 증거는 아님 | 원본 목록(§473 작성 때) | ✅ 가설로 둠 |
| `splusclock` 은 `eventc.h:38` → `bsd/m68k/spl.h` → `kernserv/m68k/spl.h` 로 이미 보임 | `eventc.h` import 줄 직접 읽음(37–40 행) | ✅ "컴파일로 판정" 문구 대신 사실로 |
| 헤더 붙여넣기 방식은 이 m68k 시험에서 성립(앞서 `_EVENTC_` 정의 없음) | §473 준비 때 헤더 사슬 grep | ✅ |
| `event_set_ts` 의 다른 사용처 없음; 그래도 `kern/xpr.h` 를 거쳐 헤더를 읽는 객체가 있으니 바뀐 헤더로 다시 짓는 비교가 알맞음 | grep(§473) | ✅ final 단계에서 스테이징 차이와 x86gate 로 봄 |
| `mach_clock` 의 덩어리는 182·187 행, `_time_of_boot` 은 원본에 없음; 원본 0x404b0f0 이 `service_timer` | 원본 목록 0x404b0ec–0x404b0f8 읽음, 기호표 grep | ✅ |
| 크기 차 94 = 42 + 42 + 6 + 2 + 2(덩어리 둘, 저장 꼬리 합침, 분기 길이) | 검토자 계산 | ⏭️ M1 이 판정 |
| E4(= E2 의 피연산자 순서 + E3 의 전위 증가)를 더할 것 | 설계 | ✅ 추가 |
| 두 객체 모두 bss 가 없으므로 기준은 OBJECT_MATCH | §470 기록(사유 `__TEXT,__text: unverified` 하나) | ✅ 기준을 OBJECT_MATCH 로 |
| `service_timer` 끝 줄 381 | 381 행 직접 읽음 | ✅ 위 제 오류 |

### 473.2 변형 시험 결과(2026-10-16)

- `time_stamp`:
  - 1 차 run `m5p473-t1`(명령 5, 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-time-stamp-variants-p473-20261016.json`): E1–E4 는 서로 같은 객체이고 원본과 달랐습니다(`__TEXT,__text: fail`). 대조 K 는 §470 객체를 재현했습니다.
  - otool 비교(`08_build/artifacts/m5p473/otool/P473__E1.txt`)로 보니 남은 차이는 한 곳입니다. 원본은 `orl d0,d1; movel d1,…`(결과를 `low` 의 레지스터에)이고, 우리는 `orl d1,d0` 입니다. 다른 구간 수가 줄어 §446 멈춤 조건에 해당하지 않습니다.
  - 2 차 run `m5p473-t2`(명세 `spec2-time_stamp.json`; 기록 `m5-m68k-time-stamp-variants2-p473-20261016.json`): `tsp->low_val = low | *event_middle;` 로 바꾼 **E5(E1 바탕)·E6(E3 바탕)이 OBJECT_MATCH** 이고, 두 객체는 같습니다. 원본에 없는 미정의 0, 외부 정의는 K 와 같습니다.
  - 1 차에서 XOR 순서(E1/E2)와 증가 꼴(후위/전위, E1/E3)도 객체가 같았습니다. 바이트로 구별되지 않습니다.
- `mach_clock`(run `m5p473-c1`, 명령 4, 모두 종료 0; 기록 `m5-m68k-mach-clock-variants-p473-20261016.json`):
  - **M1 이 OBJECT_MATCH** 입니다(COMMON 에서 `_time_of_boot` 이 빠짐, 그 밖 K 와 같음). M2(빼기만)·M3(옮기기만)은 맞지 않아, 두 원인이 모두 필요합니다.
  - x86(run `m5p473-xc1`; 기록 `m5-x86-mach-clock-variants-p473-20261016.json`): M3(옮기기)은 x86 원본과 같습니다.
- 사용자에게 묻는 것: `time_stamp` 의 꼴(E5/E6), `mach_clock` 의 `service_timer` 옮기기 자리(07 본 파일 / 덮어쓰기)입니다. `time_of_boot` 빼기는 x86 원본에 있는 코드라 덮어쓰기(`#if !m68k` 꼴)로 둡니다.
- 사용자 결정 **D091**:
  - `time_stamp` 는 "E5 후위 증가 (Recommended)" 입니다. m68k 덮어쓰기 헤더 `machdep/m68k/eventc.h` 의 `event_set_ts` 를 E5 꼴로 고칩니다.
  - `mach_clock` 의 `service_timer` 옮기기는 "07 본 파일 (Recommended)" 이고, `time_of_boot` 빼기는 m68k 덮어쓰기에 둡니다.

### 473.3 D091 구현 계획(07 본 파일 `mach_clock.c` + 덮어쓰기 `mach_clock.c`·`eventc.h` + x86 전체 재빌드 s6l10; 코딩 전, 2026-10-16)

§472.3 절차를 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p473-t2/out/P473__E5.o`·`m5p473-c1/out/P473__M1.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집:
   - 본 파일 `kern/mach_clock.c`: `service_timer` 정의(365–381 행)를 199 행 앞선 선언 바로 뒤로 옮깁니다(M3 와 같은 글). 옮긴 정의 앞에 `/* plan 473 (D091): … */` 한 줄을 둡니다.
   - 덮어쓰기 `v183.34/m68k/src/kern/mach_clock.c`(새 파일): 새 본 파일에 줄을 끼우는 꼴로, `time_of_boot` 정의와 보정 두 줄을 각각 `#ifndef m68k /* plan 473 (m68k) */` … `#endif /* plan 473 (m68k) */` 로 감쌉니다(작성, 원본에 `_time_of_boot` 없음).
   - 덮어쓰기 헤더 `machdep/m68k/eventc.h`: `event_set_ts` 몸체를 E5 로 바꾸고 `/* plan 473 (D091): … */` 를 붙입니다. 이 파일은 본 파일 짝이 없는 덮어쓰기 전용 헤더라 파생 검사 대상이 아닙니다(stage_m68k 규칙은 `.c`).
   - 확인: 파생 검사, 본 파일 표시 문자열 없음을 봅니다. python 으로 본 파일 토큰이 M3 와, 덮어쓰기 m68k 가지가 M1 과, `time_stamp` 에서 펼쳐진 헤더의 `event_set_ts` 가 E5 와 같은지 봅니다.
2. x86 전체 재빌드 s6l10 → check 관문(§469.4 와 같음).
3. prefixdiff s6l9↔s6l10(plan 473):
   - 스테이징 차이는 `src/kern/mach_clock.c` 하나여야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-mach_clock']` 이고, `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p473-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`:
   - `X86[473] = 's6l10'`, `EXCEPTS[473] = EXCEPTS[472]` 에 `x86-mach_clock`·`x86-time_stamp` 사유를 더합니다.
   - `MARKERS['plan 473 (m68k)']` 를 등록하고 `--plan` 문서를 고칩니다.
   - `--plan 473 stage m0p473-a1-stage` → x86gate(s6l10) → `m0p472-a1-stage` 와의 차이는 `src/kern/mach_clock.c`·`src/machdep/m68k/eventc.h` 둘이어야 합니다.
   - `eventc.h` 를 가져오는 다른 m68k 객체는 줄 번호(STABS)만 바뀌고 코드는 그대로일 것입니다(바뀐 함수의 사용처는 `time_stamp` 하나). 이번 final 은 두 객체만 컴파일합니다.
6. final(`m5_m68k_final.py`, plan 473): `time_stamp`·`mach_clock` 모두 OBJECT_MATCH 를 기대합니다. run `m5p473-a1`.
7. 기록:
   - PROVENANCE: 본 파일 `mach_clock.c` 행과 `eventc.h` 1067 행을 그 자리에서 갱신하고, `mach_clock.c` 덮어쓰기는 새 행으로 둡니다.
   - MODIFICATIONS, DECISIONS D091, diff 셋, evidence 를 적습니다.
   - 집계: OBJECT_MATCH +2, 코드 차이가 남은 객체는 14 → 12 입니다.

### 473.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §473.3 은 x86 재빌드 접두어를 `s6l10` 으로 정했습니다. 그런데 `l2_prefix_diff.py` 의 RID 정규화(86–89 행)는 실행 경로 바이트를 단순 치환합니다. s6l9 객체 가운데 15 개가 경로 `/08_build/runs/s6l9-` 를 품고 있으므로(python), 길이가 다른 접두어(`s6l10` 5 자 대 `s6l9` 4 자)로는 정규화가 같아질 수 없습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 덮어쓰기 표시 6, MARKERS 를 파생 검사 전에 등록 | 구현 때 실제 `check_derived` 로 확인 | ✅ 순서 고침 |
| 새 본 파일 토큰 = M3, 덮어쓰기 m68k 가지 = M1 | 구현 뒤 python 으로 확인 | ✅ |
| `eventc.h` 는 덮어쓰기 전용 헤더로 파생 검사 없이 m68k 층이 이김 | `cmd_stage` 설명(§469 때 읽음) | ✅ |
| `eventc.h` 를 가져오는 다른 객체 12 개는 코드가 그대로일 것(바뀐 함수 사용처는 `time_stamp` 하나), 단 이번 final 로 증명되지는 않음 | grep(§473) | ⚖️ 기대로 기록. 다음 전체 m68k 재컴파일 때 비 STABS 로 확인 |
| final `time_stamp` 는 REF E5 와 네 비교에서 같을 것 | final 이 판정 | ⏭️ |
| x86 M3 는 s6l9 와 비 STABS 같음(STABS 862 대 868) | §473.2 x86 기록(M3 same_as_ref) | ✅ |
| **접두어 길이가 다르면 RID 정규화가 깨짐** | python: 경로를 품은 s6l9 객체 15 개, 길이 4 대 5 | ✅ 위 제 오류. 접두어를 같은 길이의 `s6la` 로 |
| PROVENANCE 595·1067 갱신, 134 유지; 옮긴 `service_timer` 는 작성(D024) 표시 유지 | 행 읽음 | ✅ |

계획 수정: x86 재빌드 접두어는 `s6la`(RID `s6la-g1a` 등), 링크 `s6p473-ln1` 로 합니다. `X86[473] = 's6la'` 이고, prefixdiff 는 `s6l9 s6la` 입니다. 나머지 기준은 그대로입니다.

### 473.5 D091 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p473-final-20261016.json`

- 07 편집:
  - 본 파일 `kern/mach_clock.c` 는 381 → 382 행입니다(정의를 옮기고 주석 한 줄). 토큰이 M3 와 같습니다.
  - 새 덮어쓰기 `v183.34/m68k/src/kern/mach_clock.c` 는 표시 줄 6 이고, m68k 가지의 토큰이 M1 과 같습니다.
  - 덮어쓰기 헤더 `machdep/m68k/eventc.h` 는 135 → 144 행입니다(`event_set_ts` 만 바꿈). `time_stamp.c` 에 펼친 토큰이 E5 와 같습니다.
  - 파생 검사를 통과했습니다(python).
- x86 전체 재빌드 s6la(§473.4 의 같은 길이 접두어):
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6l9↔s6la: 스테이징 차이는 `src/kern/mach_clock.c` 하나이고, `sha_differ_not_rid_only` 는 `['x86-mach_clock']`(STABS 만, 비 STABS 같음)입니다. RID 정규화도 성립했습니다.
  - 링크 `s6p473-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 473 stage m0p473-a1-stage` 와 x86gate(s6la 일곱)가 모두 같고 v183 경로는 0 입니다. `m0p472-a1-stage` 와의 차이는 `src/kern/mach_clock.c`·`src/machdep/m68k/eventc.h` 둘입니다.
  - final run `m5p473-a1`: **`x86-time_stamp`·`x86-mach_clock` 모두 OBJECT_MATCH** 이고, 고른 변형과 서명이 같으며, 원본에 없는 미정의는 0 입니다.
  - `eventc.h` 를 가져오는 다른 m68k 객체 12 개의 코드는 그대로일 것으로 봅니다(바뀐 함수의 사용처는 `time_stamp` 하나). 다음 전체 m68k 재컴파일 때 비 STABS 로 확인합니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 174 입니다(+ 명시 배치 `ufs_alloc` 1).
  - "코드 검증 + bss 추정" 은 21 입니다.
  - 코드 차이가 남은 객체는 12 개입니다(netif, miniMon, igmp, nfs_client, kern_fork, ufs_subr, ipc_mig, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 1099 행(595·1067 행 갱신, 덮어쓰기 한 행 새로, 중복 0), MODIFICATIONS 634 행, DECISIONS D091 을 적었습니다.
  - diff 셋을 만들고 evidence 두 개에 plan 473 절을 덧붙였습니다.

## 474. M5-31 세부 계획 — m68k `igmp`: `IGMP_RANDOM_DELAY` 덧셈 순서와 `igmp_fasttimo` 의 멀티캐스트 순회 함수(코딩 전, 2026-10-16)

확인한 사실(§470 목록, 원본 목록 0x4025be0–0x402616c, 기호표, 참고 코드를 직접 읽음):
- 다른 구간은 `_igmp_input`·`_igmp_joingroup`(크기 같음)과 `_igmp_leavegroup`·`_igmp_fasttimo`(원본이 28 B 김)입니다.
- **덧셈 순서**:
  - 원본 `_igmp_input`·`_igmp_joingroup` 의 지연 계산은 `ipstat.ips_total`(`_ipstat`+0, `movel #_ipstat` 을 레지스터에 두고 `a5@`) + `IA_SIN(in_ifaddr)->sin_addr`(`_in_ifaddr` 의 +4) + 그룹 주소 순서로 더합니다.
  - 07 `bsd/netinet/igmp.c:57-60` 의 `IGMP_RANDOM_DELAY`(x86 원본에서 작성)는 앞 두 항이 반대입니다.
  - m68k 에서 `ntohl` 은 항등이라 덧셈 항 순서가 코드에 그대로 남습니다. 루프 밖으로 올린 적재 순서 차이도 같은 원인으로 봅니다.
- **순회 함수**:
  - 원본은 `_igmp_leavegroup` 뒤에 기호 없는 정적 함수 둘을 둡니다.
    - 0x4025f16: 인자 `step` 으로 `IN_NEXT_MULTI` 매크로 몸체와 같은 명령을 하고 `inm` 을 돌려줍니다.
    - 0x4025f4c: `step->i_ia = in_ifaddr; step->i_inm = 0;` 뒤 0x4025f16 을 불러 그 값을 돌려줍니다.
  - 원본 `_igmp_fasttimo`(0x4025f6a)는 `splnet`, `igmp_timers_are_running = 0` 뒤 `inm = first(&step)` 로 시작해 몸체 끝마다 `inm = next(&step)` 을 부르는 고리입니다.
  - 원본 `_igmp_input` 은 이 함수들을 부르지 않고 매크로를 펼친 꼴입니다(우리와 같음; 원본 `_igmp_input` 안 `bsr` 목록에 0x4025f16·0x4025f4c 없음).
  - 07 `igmp_fasttimo`(214–239 행)는 매크로 꼴입니다. Darwin 0.1 `igmp.c` 도 매크로 꼴이고, 정적 함수가 없습니다(`IGMP_RANDOM_DELAY` 는 Darwin 에서 `random()`).
  - 가설: m68k 원본 `igmp.c` 는 `igmp_leavegroup` 뒤에 `static` 순회 함수 둘(next, first 순서)을 두고 `igmp_fasttimo` 에서만 썼습니다. -O2 는 `inline` 없는 함수를 펼치지 않고 소스 순서대로 냅니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p473-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 `O470__…igmp.o`, run `m5p474-i1`):
- `R`: `IGMP_RANDOM_DELAY` 를 `((ipstat.ips_total + ntohl(IA_SIN(in_ifaddr)->sin_addr.s_addr) + ntohl((multiaddr).s_addr)) % (IGMP_MAX_HOST_REPORT_DELAY * PR_FASTHZ) + 1)` 로 바꿉니다.
- `H`: `igmp_leavegroup` 뒤에 둘을 둡니다.
  - `static struct in_multi *igmp_next_multi(step) struct in_multistep *step; { struct in_multi *inm; IN_NEXT_MULTI(*step, inm); return (inm); }`
  - `static struct in_multi *igmp_first_multi(step) …{ step->i_ia = in_ifaddr; step->i_inm = NULL; return (igmp_next_multi(step)); }`
  - `igmp_fasttimo` 의 고리를 `for (inm = igmp_first_multi(&step); inm != NULL; inm = igmp_next_multi(&step))` 로 바꾸고, `(void) &step;` 줄(plan 251)은 뺍니다. 이름은 작성입니다.
- `RH`: R + H 입니다.
- `RH2`: RH 에서 고리를 `inm = igmp_first_multi(&step); while (inm != NULL) { …; inm = igmp_next_multi(&step); }` 로 쓴 꼴입니다.
- 판정(L1 `--place-from-image`): §470 사유는 `__TEXT,__text: unverified`(bss 있는지 실행으로 확인)입니다. 맞으면 OBJECT_MATCH 이거나 bss 만 남아야 합니다. 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; `igmp.c` 는 s6l5 뒤 바뀌지 않았는지 stage 가 assert): R·H 가 x86 원본과 같은지 봅니다. 같으면 자리를 묻고, 다르면 m68k 덮어쓰기로 둡니다.
- 고르기·결정·구현·final 은 §471–§473 과 같습니다.

### 474.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- §474 는 §470 의 igmp L1 사유를 `__TEXT,__text: unverified` 하나로 적었습니다. 실제로는 text·data·bss 셋 다 unverified 입니다(survey 기록).
- "Darwin 에는 정적 함수가 없다" 는 틀렸습니다. Darwin 에도 `static igmp_sendreport` 가 있습니다. "정적 순회 함수가 없다" 가 맞습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| igmp 의 모든 차이는 R(덧셈 순서)과 H(순회 함수 둘과 그 사용)로 설명됨; `_igmp_leavegroup` 자체는 같고 구간에 이름 없는 함수가 들어감 | §474 작성 때 목록 비교; 검토자 해독(같은 결론) | ✅ 문구 고침 |
| 구조체 오프셋(`i_ia` 0, `i_inm` 4, `inm_timer` 0x10, `inm_next` 0x14, `ia_next` 0x40, `ia_multiaddrs` 0x44) | 원본 명령의 변위와 `in_var.h` 매크로(§474 준비 때 읽음) | ✅ |
| 0x40b3528 = `igmp_all_hosts_group`(bss), 0x40aec04 = `igmp_timers_are_running`(data); data 40 B 가 원본과 같음 | 쓰임새(§474 준비); data 비교는 검토자 | ⏭️ final L1 이 판정 |
| 크기 차 28 = 도우미 84 − 고리 56 | 검토자 계산 | ⏭️ RH 가 판정 |
| H 의 함수 꼴(포인터를 받아 `struct in_multi *` 를 돌려줌), next 가 first 앞; `(void) &step;` 빼기 | 설계 | ✅ |
| §470 사유는 text·data·bss 셋 | survey 기록 python 출력 | ✅ 위 제 오류 |
| `(void) &step;` 은 224 행 | grep | ✅ |
| `_igmp_joingroup` 은 `_ipstat` 를 직접 적재(레지스터 아님), `+4` 는 `in_ifaddr` 가 가리키는 대상 안의 오프셋 | 원본 목록 0x4025ec0–0x4025ed0 | ✅ 문구 고침 |
| x86 중립성은 R·H 를 따로 시험해야 함 | 설계 | ✅ x86 시험에 R·H·RH·RH2 모두 넣음 |

### 474.2 변형 시험 결과(2026-10-16)

- m68k(run `m5p474-i1`, 명령 5 개 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-igmp-variants-p474-20261016.json`). 대조 K 는 §470 객체를 재현했습니다.
  - **RH·RH2 는 L1 사유가 `__DATA,__bss: unverified` 하나** 입니다(텍스트·데이터 통과). 두 객체는 같고, 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같습니다.
  - R 만, H 만으로는 맞지 않습니다. 두 원인이 모두 필요합니다.
- x86(run `m5p474-xi1`, 바탕 s6l5; 기록 `m5-x86-igmp-variants-p474-20261016.json`): R·H·RH·RH2 가 모두 x86 원본과 같습니다. x86 -O3 가 정적 도우미를 펼칩니다.
- 사용자에게 묻는 것: 고리 꼴(RH 의 for / RH2 의 while)과 자리(07 본 파일 / m68k 덮어쓰기)입니다. final 에서는 bss 자리를 zerofill 로 추정합니다.
- 사용자 결정 **D092**: `igmp` 의 고리는 "RH for 문 (Recommended)" 이고, 자리는 "07 본 파일 (Recommended)" 입니다. `IGMP_RANDOM_DELAY` 덧셈 순서와 순회 함수 둘을 07 본 파일에 둡니다.

### 474.3 D092 구현 계획(07 본 파일 `igmp.c` + x86 전체 재빌드 s6lb; 코딩 전, 2026-10-16)

§472.3 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p474-i1/out/P474__RH.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집: 본 파일 `bsd/netinet/igmp.c` 를 RH 와 같은 글로 바꿉니다.
   - `IGMP_RANDOM_DELAY` 의 덧셈 순서를 바꿉니다.
   - `igmp_leavegroup` 뒤에 `igmp_next_multi`·`igmp_first_multi` 를 둡니다(작성, D024).
   - `igmp_fasttimo` 를 for 고리로 하고, `(void) &step;` 은 뺍니다.
   - 바뀐 자리마다 `/* plan 474 (D092): … */` 를 붙입니다.
   - python 으로 주석을 뺀 토큰이 RH 와 같은지 확인합니다.
2. x86 전체 재빌드 s6lb(접두어 길이 4, §473.4)와 check 관문을 거칩니다.
3. prefixdiff s6la↔s6lb(plan 474):
   - 스테이징 차이는 `src/bsd/netinet/igmp.c` 하나여야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-igmp']`, `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p474-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`: `X86[474] = 's6lb'`, `EXCEPTS[474] = EXCEPTS[473]` 에 `x86-igmp` 사유를 더하고, `--plan` 문서를 고칩니다. 표시는 더하지 않습니다(덮어쓰기 없음). `--plan 474 stage m0p474-a1-stage` → x86gate(s6lb) → `m0p473-a1-stage` 와의 차이는 `src/bsd/netinet/igmp.c` 하나여야 합니다.
6. final(`m5_m68k_final.py`, plan 474):
   - `igmp` 의 기대 사유는 `['__DATA,__bss: unverified']` 입니다.
   - zerofill 후보는 §464·§467(nfs)·§469(ns_timer)·§471(kern_proc·kalloc) 후보와 겹치지 않아야 합니다(`bss_records` 에 세 기록).
7. 기록:
   - PROVENANCE 의 `igmp.c` 행을 그 자리에서 갱신하고, MODIFICATIONS·DECISIONS D092·diff·evidence 를 적습니다.
   - 집계: "코드 검증 + bss 추정" +1, 코드 차이가 남은 객체는 12 → 11 입니다.

### 474.4 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 접두어 `s6lb` 는 길이 4, 미사용 | `ls 08_build/runs/tools`(§474.3 작성 전 `s6la` 까지만 있음); 구현 때 prepare 가 기존 이름이면 멈춤 | ✅ |
| 다른 x86·m68k 객체는 `igmp.c` 를 쓰지 않음 | x86 `cc -M` 기록·m68k 소스 검사(검토자); 스테이징 차이 검사가 판정 | ✅ 스테이징 차이로 확인 |
| final 은 `bss_records` 세 기록을 읽고, §464 기록은 `objs` 가 따로 읽음(스키마가 달라 `bss_records` 에 넣지 않음) | `m5_m68k_final.py`·`m5_m68k_zerofill.py:148` 코드 | ✅ |
| 예상 bss 후보 [0x40b3528, 0x40b352c), 겹침 0 | 검토자 계산 | ⏭️ final 이 판정 |
| prefixdiff 관문에 `stage_keys_differ == []`·`cmd_differ == []` 포함 | §469.4 부터 같은 관문 | ✅ |
| PROVENANCE 611 행 그 자리 갱신 | 행 grep | ✅ |

### 474.5 D092 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p474-final-20261016.json`

- 07 편집: 본 파일 `bsd/netinet/igmp.c` 는 292 → 311 행입니다. 주석을 뺀 토큰이 RH 와 같습니다(python).
- x86 전체 재빌드 s6lb:
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6la↔s6lb: 스테이징 차이는 `src/bsd/netinet/igmp.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-igmp']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p474-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 474 stage m0p474-a1-stage` 와 x86gate(s6lb 일곱)가 모두 같고, `m0p473-a1-stage` 와의 차이는 `igmp.c` 하나입니다.
  - final run `m5p474-a1`: `x86-igmp` 은 L1 사유가 `__DATA,__bss: unverified` 하나이고, REF 와 서명이 같으며, 미정의는 0 입니다.
  - zerofill(`m5-m68k-p474-zerofill-20261016.json`)은 reference-inferred [0x40b3528, 0x40b352c) 4 B 이고, 이전 후보와 겹침 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 174, "코드 검증 + bss 추정" 은 22 입니다.
  - 코드 차이가 남은 객체는 11 개입니다(netif, miniMon, nfs_client, kern_fork, ufs_subr, ipc_mig, tty, callout, kdp_udp, mach_net, swapfs).
- 기록: PROVENANCE 611 행 갱신(중복 0), MODIFICATIONS, DECISIONS D092, diff, `x86-igmp.md` 를 적었습니다.
