F0073718: 9de3bf98                 save    %sp, -0x68, %sp
F007371C: d0060000                 ld      [%i0], %o0
F0073720: 80a22000                 cmp     %o0, 0
F0073724: 12bffffe                 bne     loc_F007371C
F0073728: 01000000                 nop
F007372C: 40008ddf                 call    _simple_lock_try
F0073730: 90100018                 mov     %i0, %o0
F0073734: 80a22000                 cmp     %o0, 0
F0073738: 02bffff9                 be      loc_F007371C
F007373C: 01000000                 nop
F0073740: d0062008                 ld      [%i0+8], %o0
F0073744: 80a22000                 cmp     %o0, 0
F0073748: 32800005                 bne,a   loc_F007375C
F007374C: d0062018                 ld      [%i0+0x18], %o0
F0073750: c0260000                 clr     [%i0]
F0073754: 10800011                 ba      locret_F0073798
F0073758: b0102005                 mov     5, %i0
F007375C: a206201c                 add     %i0, 0x1C, %l1
F0073760: d206201c                 ld      [%i0+0x1C], %o1
F0073764: 90023fff                 inc     -1, %o0
F0073768: 80a44009                 cmp     %l1, %o1
F007376C: 02800009                 be      loc_F0073790
F0073770: d0262018                 st      %o0, [%i0+0x18]
F0073774: e0026010                 ld      [%o1+0x10], %l0
F0073778: 4000072f                 call    _thread_release
F007377C: 90100009                 mov     %o1, %o0
F0073780: 92100010                 mov     %l0, %o1
F0073784: 80a44009                 cmp     %l1, %o1
F0073788: 32bffffc                 bne,a   loc_F0073778
F007378C: e0026010                 ld      [%o1+0x10], %l0
F0073790: c0260000                 clr     [%i0]
F0073794: b0102000                 mov     0, %i0
F0073798: 81c7e008                 ret
F007379C: 81e80000                 restore
