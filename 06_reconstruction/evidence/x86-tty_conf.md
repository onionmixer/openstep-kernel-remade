# x86 `tty_conf.c` 데이터만 있는 목적 파일 — `x86-tty_conf` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1dafe8+484.
- 07 파일: `07_kernel/src/bsd/kern/tty_conf.c`(SHA-256 `829bffcab011a049cdb27c8bd041325c7846f2e75c8c06cd722c00aad9ffa353`).
- 바탕: NeXTMach mk-108.1 bsd/tty_conf.c.
- 고친 것: 표(`linesw` 10 × 48 B, `nldisp`)만 두고 `nullioctl` 함수를 뺐습니다(07 tty.c 가 정의, 원본 0x111bf4).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-tc1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 387, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-tty), L1 `09_validation/reconstruction/s6l1-g1a-l1-387.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-tty_conf.diff`(참조 원문 대비).
