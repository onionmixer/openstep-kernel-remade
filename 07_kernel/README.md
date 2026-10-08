# 실제 복원 커널 소스

여기에서만 실제 복원 코드를 편집한다. 채택된 목적 파일과 그 등급은 `06_reconstruction/objects_confirmed.tsv`·
`objects_partial.tsv`, 함수 대응은 `06_reconstruction/functions.tsv` 가 기준이다.
도구 체인 라이브러리에서 링크되는 구성원(libgcc, `-lcc`)은 07 에 소스를 두지 않고 `06_reconstruction/objects_toolchain.tsv`(등급 L, D051)에 기록한다.
최종 코드·헤더·생성 코드는 GCC 2.7에서 컴파일되어야 한다.
C89 스타일을 기본으로 [호환 규약](../08_build/GCC27_COMPATIBILITY.md)을 따른다.
`src/common/`, `src/arch/x86/`, `src/arch/sparc/`, `src/arch/future_arch/`,
`include/`, `config/`는 작업 시작을 위한 예약 구조이다.
최초 기반 소스를 채택할 때 원래 파일 경로를 최대한 유지하는 방향으로 조정할 수 있다.
실제 채택 파일은 원래 경로를 유지해 `src/`(Darwin `kernel/` 경로 그대로), `components/architecture/`,
`generated/`(`10_tools/reconstruction/gen_config_headers.py` 생성 헤더), `nextdev/`(실기 OPENSTEP 4.2 `/NextDeveloper/Headers` 판,
D018; `stage_headers.py --nextdev` 로 Darwin 루트 뒤에서만 쓰임)에 있고, `nextdev_private/`(SDK 가 빼거나 싣지 않은 비공개 BSD 헤더의 작성판, 원본 바이트로 확인된 내용만; `--bsd-set nextos` 에서 SDK 보다 먼저 쓰임, 계획 132)에 있고, 위 예약 디렉터리는 비어 있다.

채택 파일마다 `PROVENANCE.tsv`에 출처/원 경로/고정 revision/수정 내용/라이선스 표시를 남긴다.
프로젝트 문서(`README.md`, `generated/README`)와 `PROVENANCE.tsv`·`MODIFICATIONS.md`·`LICENSES/` 는 그 대상이 아니다.
재구성한 함수는 `06_reconstruction/functions.tsv`의 evidence와 연결한다.
generated headers/MIG output, 커널 config, linker 설정도 재현 가능하게 관리한다.
아직 검증하지 않은 API에 성공을 반환하는 stub을 두어 복원 완료처럼 보이게 하지 않는다.
빌드 산출물은 `08_build/artifacts/`에 둔다.
최종 빌드 플래그는 `-g … -O3 -fno-omit-frame-pointer`(원본 RELEASE `gdb` 구성 가설), `-fno-common` 없음(계획 133), `-DINET`(계획 141: 원본 `afswitch` 의 INET 항목), `-DMACH`(계획 149: 원본 `raw_input` 의 `wakeup(&soft_net_wakeup)`), `-DMULTICAST`(계획 150: 원본 `raw_detach` 의 multicast 블록, `_rawcb` 크기 92 B), `-DPOSIX_KERN -D_POSIX_SOURCE`(계획 155: 원본 `soo_rw` 의 POSIX 검사와 POSIX 세션 함수; SDK `proc.h` 의 POSIX 블록이 쓰는 `pid_t` 는 `_POSIX_SOURCE` 에서만 정의)이며, 스테이징은 `stage_headers.py --prefer-07 --nextdev --bsd-set nextos --mach-set sdk` 이다. BSD 헤더는 `nextdev/`(SDK)·`nextmach/`(NeXTMach)·`nextdev_private/`(작성)에만 있고 `src/bsd/` 에는 BSD 소스(`libkern/strtol.c`)만 남는다. SDK 에 있는 `mach/`·`kernserv/`·`architecture/`·`driverkit/` 헤더도 `nextdev/` 의 SDK 판을 쓴다(D022, 계획 135); SDK 판이 커널 비공개 분기를 뺀 공개판인 7 개(`mach/mach_types.h`, `std_types.h`, `mach_traps.h`, `kernserv/lock.h`, `clock_timer.h`, `ns_timer.h`, `prototypes.h`)는 SDK 본문에 비공개 분기를 끼워 넣은 작성판을 `nextdev_private/` 에 둔다(D023, 계획 136). 근거와 템플릿은 `08_build/GCC27_COMPATIBILITY.md` 의 "툴체인 고정" 을 따른다.
