# x86 `in_proto.c` 데이터만 있는 목적 파일 — `x86-in_proto` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1dbb64+377.
- 07 파일: `07_kernel/src/bsd/netinet/in_proto.c`(SHA-256 `02e5152666298e78e9dca916efae812ab6c251db4e57e37e148762b35183cbb6`).
- 바탕: NeXTMach mk-108.1 netinet/in_proto.c, IGMP 항목 꼴은 Darwin 0.1 kernel/bsd/netinet/in_proto.c:132–136.
- 고친 것: ICMP 와 raw 항목 사이에 IGMP 항목(`igmp_input`, `rip_output`, `rip_ctloutput`, `raw_usrreq`, `igmp_init`, `igmp_fasttimo`; 원본 바이트대로 `raw_usrreq`)과 그 선언을 넣었습니다. Darwin APSL 고지를 머리에 덧붙이고 줄에 "plan 397 (Darwin)" 을 적었습니다(in_bootp.c 선례).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-ip1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 390, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-in_pcb), L1 `09_validation/reconstruction/s6l1-g1a-l1-390.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-in_proto.diff`(참조 원문 대비).
