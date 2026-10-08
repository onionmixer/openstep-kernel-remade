# x86 `vfs_conf.c` 데이터만 있는 목적 파일 — `x86-vfs_conf` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1db640+184.
- 07 파일: `07_kernel/src/bsd/vfs/vfs_conf.c`(SHA-256 `656ee6009936c2808841f7ba1cdaf4d070ee97d0b9cbd6bf347edb437f28d9e8`).
- 바탕: NeXTMach mk-108.1 bsd/vfs_conf.c.
- 고친 것: 6 번에 "swapfs"·`swapfs_vfsops` 를 넣고 빈 항목을 7–19 로 늘렸습니다(20 항목, `_vfsNVFS` = &vfssw[20] = 0x1db6e0).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-vc1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 389, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-vfs_bio), L1 `09_validation/reconstruction/s6l1-g1a-l1-389.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-vfs_conf.diff`(참조 원문 대비).
