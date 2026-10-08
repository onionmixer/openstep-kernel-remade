# x86 `ioconf.c` 데이터만 있는 목적 파일 — `x86-ioconf` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1e4f80+24.
- 07 파일: `07_kernel/src/conf/ioconf.c`(SHA-256 `b11c7df75da827e9c722e368c5e6583f15c7576acc7f975c39dcede4de8dd19b`).
- 바탕: NeXTMach config mkioconf.c(NeXT_pseudo_inits)의 출력 꼴.
- 고친 것: `pseudo_inits` = {32, pty_init}, {1, venip_config}, {0, 0} 를 원본 바이트대로 썼습니다(생성기 출력 꼴을 손으로 다시 쓴 것).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-io1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 396, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-PCemulatePROT), L1 `09_validation/reconstruction/s6l1-g1a-l1-396.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-ioconf.diff`(/dev/null 대비, 원문 없음).
