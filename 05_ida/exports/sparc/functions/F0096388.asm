F0096388: 150000119412a300         set     0x4700, %o2
F0096390: 90102000                 mov     0, %o0
F0096394: d2820080                 lda     [%o0]#ASI_NUCLEUS, %o1
F0096398: 808a6800                 btst    0x800, %o1
F009639C: 12800004                 bne     loc_F00963AC
F00963A0: 01000000                 nop
F00963A4: 150001519412a300         set     0x54700, %o2
F00963AC: 9212400a                 bset    %o2, %o1
F00963B0: d2a20080                 sta     %o1, [%o0]#ASI_NUCLEUS
F00963B4: 81c3e008                 retl
F00963B8: 01000000                 nop
