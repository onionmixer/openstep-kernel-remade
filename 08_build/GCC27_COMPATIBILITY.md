# GCC 2.7 호환 기준

사용자 확정 요구: **최종 복원 커널 소스는 GCC 2.7에서 컴파일 가능해야 한다.**
x86 우선 적용 후 SPARC 및 확정될 후속 CPU에도 같은 기준을 적용한다.
툴체인 확인 상태(2026-10-01): OPENSTEP 실기와 i386 VM 의 `cc-744.13`(`NeXT Software, Inc. version cc-744.13, gcc version 2.7.2.1`, 도구 15 개 해시 동일)으로 C·Objective-C·어셈블리·MIG probe 를 컴파일했고, 같은 컴파일러로 만든 함수 11 개가 원본 커널과 바이트가 같다(`02_plan/RECONSTRUCTION_PLAN.md` 11.2·13.2). 전체 커널 컴파일·링크(완료 판정 3)는 아직이다.

## 툴체인 고정

GCC 2.7 계열을 필수 컴파일러로 지정한다. 정확한 2.7.x 패치 버전,
NeXT 수정판 여부, target 설정은 아직 확정하지 않았으므로 임의로 가정하지 않는다.
P3 시작 시 실제 compiler 실행 경로, 버전 출력, 소스/실행 파일 해시, target,
사용 옵션과 함께 assembler, linker, MIG, SDK 헤더 버전을 기록한다.
GCC 버전 확인과 NeXT Mach-O·Objective-C ABI 지원 확인은 각각 필요하다.
네이티브/크로스 빌드 중 어떤 경로를 선택하더라도 이 기준은 동일하다.

원본 커널 빌드 플래그 가설(2026-10-02, `02_plan/RECONSTRUCTION_PLAN.md` 123.1·124.2): Darwin `conf/MASTER.i386:81` 의 RELEASE `gdb` 구성
`-g -O3 -fno-omit-frame-pointer`. 확정·부분 객체 83 개를 `-g … -fno-omit-frame-pointer` 로 다시 빌드해도 비디버그 내용이 모두 같았고
(`09_validation/reconstruction/s5p98-gregress-compare-20261002.json`), `kern/sched_prim.c` 는 `-g` 에서만 원본과 일치한다(GCC 2.7 인라인 판단).
2026-10-02 이후 최종 빌드는 이 플래그를 쓴다(템플릿 `08_build/runs/tools/s5p99-build.cmd`). 역사적 사실로 확정된 것은 아니다.
D021(BSD 헤더를 OPENSTEP 4.2 SDK/NeXTMach 묶음으로 교체, 계획 131–133) 이후 최종 빌드는 `-fno-common` 을 쓰지 않는다(템플릿 `08_build/runs/tools/s5p107-build.cmd`,
스테이징 `stage_headers.py --prefer-07 --nextdev --bsd-set nextos`, D022 이후 `--mach-set sdk` 추가 — 계획 135). 그 헤더들은 커널 전역을 `extern` 없이 잠정 정의하고, 실기 `ld` 는 `-fno-common` 정의가
다른 정의와 만나면 `multiple definitions` 로 거부한다(`09_validation/reconstruction/s5p106-e1-20261002.json`). 확정·부분 85 소스의 회귀에서 결과가 바뀐 20 객체는
L1 로 기존 등급과 같았다(`s5p107-regress-compare-20261002.json`, 계획 133.3). 이것도 이 헤더 묶음에서 링크 가능한 후보이며 원본 빌드 플래그를 확정한 것은 아니다.
계획 141 이후 `-DINET`, 계획 149 이후 `-DMACH`, 계획 150 이후 `-DMULTICAST`, 계획 155 이후 `-DPOSIX_KERN -D_POSIX_SOURCE` 를 더한다(POSIX_KERN: 원본 `soo_rw` 의 `p_posix`·`FPOSIX_PIPE` 검사와 `pgfind`·`setsid`·`get_posix_proc` 등 SDK `proc.h` POSIX_KERN 블록의 기능; `_POSIX_SOURCE`: 그 블록의 `pid_t` 는 SDK `sys/types.h`:139 에서 `_POSIX_SOURCE` 일 때만 정의, `types.h` 는 `!KERNEL && _POSIX_SOURCE` 일 때만 `standards.h` 를 포함; 116 객체 회귀 동일 `s5p129-diaga-compare-20261002.json`, POSIX_KERN 만으로는 4 객체가 `pid_t` 로 컴파일 실패 `s5p129-regress-compare-20261002.json`)(원본 `_rawcb` 간격 92 B = MULTICAST 판 `struct rawcb`; 112 객체 회귀에서 raw_usrreq 의 common 크기만 88 → 92, `s5p124-regress-compare-20261002.json`)(`MACH` 도 생성 헤더 없는 `options`; SDK `net/netisr.h` 의 `MACH` 분기가 원본 `raw_input` 과 일치; 111 객체 회귀 동일 `s5p123-regress-compare-20261002.json`)(config `options INET` 은 헤더가 없어 명령행 정의로 전달됨; 원본 `afswitch` 0x1db790 의 칸 2·3 이 `inet_hash/inet_netmatch`). 확정 96 객체는 이 정의 추가 전후 비-디버그 내용이 같다(`09_validation/reconstruction/s5p115-regress-compare-20261002.json`).

## 소스 작성 규칙

프로젝트의 보수적인 문법 기준은 C89 스타일이다.
이는 GCC 2.7이 모든 후대 구문을 거부한다는 주장 대신, 검증 전 사용할 구현 범위를 정하는 규칙이다.

- 선언은 블록의 문장들 앞에 놓고 `for (int i = ...)` 및 선언/문장 혼용을 사용하지 않는다.
- C 주석은 `/* ... */`를 사용한다. C99/C11 구문·헤더·언어 기능에 새로 의존하지 않는다.
- `<stdint.h>`, `<stdbool.h>` 등 현대 환경의 헤더를 가정하지 않는다.
  정수 폭·signedness·정렬은 대상 SDK와 원본 ABI로 정의하고 아키텍처별로 검증한다.
- GNU 확장, attributes, builtins, inline 및 inline assembly는 선택한 GCC 2.7에서
  지원 여부·코드 생성·호출 규약을 확인한 형태만 사용한다.
- Objective-C는 대상 NeXT 컴파일러/런타임의 문법과 메타데이터 ABI에 맞춘다.
  ARC, blocks 등 현대 Objective-C 기능을 새 의존성으로 도입하지 않는다.
- `.S` 전처리, assembly operand/constraint, symbol decoration과 relocation도
  선택한 컴파일러·assembler·linker 조합으로 검증한다.
- MIG 출력, config/offset 헤더 등 생성 코드는 동일한 GCC 2.7 규칙을 만족해야 한다.
  생성기의 버전과 재생성 명령을 기록한다.

참고 소스의 원문은 `01_resources`에 보존한다. 호환성 수정은 `07_kernel`의 채택 코드에
수행하고 `PROVENANCE.tsv`와 복원 evidence에 수정 이유를 연결한다.
디컴파일러 출력의 현대 타입·구문은 대상 ABI를 확인하여 정리한다.

## 완료 판정

1. 정확한 GCC 2.7 툴체인과 빌드 환경이 명세되어 있다.
2. C/Objective-C/assembly/MIG 및 구조체 layout에 대한 작은 probe가 해당 도구로 통과한다.
3. 깨끗한 출력 디렉터리에서 모든 커널 translation unit과 생성 코드를 GCC 2.7 기반으로
   컴파일하고 대상 Mach-O 커널로 링크한다. 현대 컴파일러로 미리 만든 커널 object로 대체하지 않는다.
4. 전체 빌드 명령·진단·종료 코드, 소스/설정/툴체인 식별자, 커널/map 파일 해시가 남아 있다.
5. 그 산출물을 정적 ABI 검사와 부팅·회귀검증의 입력으로 사용한다.

현대 GCC/Clang의 C89 모드 검사는 보조 검사로 사용할 수 있지만 2/3의 실검증을 대신하지 않는다.
빌드 로그에서 컴파일러 버전만 확인한 것도 전체 소스 호환성 통과가 아니다.
각 후속 architecture는 자체 GCC 2.7 빌드/ABI 결과를 가져야 한다.

분석·자료 수집용 호스트 도구(Python 등)는 이 커널 컴파일러 조건의 적용 대상이 아니다.
최종 빌드에 필요한 호스트 생성 도구가 있다면 의존성과 재현 방법을 별도로 명세한다.
