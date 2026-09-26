F00F0708: 9de3bf98                 save    %sp, -0x68, %sp
F00F070C: a2102000                 mov     0, %l1
F00F0710: a0102000                 mov     0, %l0
F00F0714: 7fffff4d                 call    sub_F00F0448
F00F0718: d0062004                 ld      [%i0+4], %o0
F00F071C: 94100008                 mov     %o0, %o2
F00F0720: d00a8000                 ldub    [%o2], %o0
F00F0724: 90023fd0                 inc     -0x30, %o0
F00F0728: 900a20ff                 and     %o0, 0xFF, %o0
F00F072C: 80a22009                 cmp     %o0, 9
F00F0730: 28bffffc                 bleu,a  loc_F00F0720
F00F0734: 9402a001                 inc     %o2
F00F0738: 10800032                 ba      loc_F00F0800
F00F073C: d04a8000                 ldsb    [%o2], %o0
F00F0740: 22800034                 be,a    loc_F00F0810
F00F0744: d04a8000                 ldsb    [%o2], %o0
F00F0748: 7fffff40                 call    sub_F00F0448
F00F074C: 9010000a                 mov     %o2, %o0
F00F0750: 80a46000                 cmp     %l1, 0
F00F0754: 1280001e                 bne     loc_F00F07CC
F00F0758: 94100008                 mov     %o0, %o2
F00F075C: d04a8000                 ldsb    [%o2], %o0
F00F0760: 80a2202d                 cmp     %o0, 0x2D ! '-'
F00F0764: 12800004                 bne     loc_F00F0774
F00F0768: 96102000                 mov     0, %o3
F00F076C: 96102001                 mov     1, %o3
F00F0770: 9402a001                 inc     %o2
F00F0774: d00a8000                 ldub    [%o2], %o0
F00F0778: 92100008                 mov     %o0, %o1
F00F077C: 1080000b                 ba      loc_F00F07A8
F00F0780: 90023fd0                 inc     -0x30, %o0
F00F0784: 90020010                 add     %o0, %l0, %o0
F00F0788: 912a2001                 sll     %o0, 1, %o0
F00F078C: 90023fd0                 inc     -0x30, %o0
F00F0790: 932a6018                 sll     %o1, 24, %o1
F00F0794: 933a6018                 sra     %o1, 24, %o1
F00F0798: a0020009                 add     %o0, %o1, %l0
F00F079C: 9402a001                 inc     %o2
F00F07A0: d20a8000                 ldub    [%o2], %o1
F00F07A4: 90027fd0                 add     %o1, -0x30, %o0
F00F07A8: 900a20ff                 and     %o0, 0xFF, %o0
F00F07AC: 80a22009                 cmp     %o0, 9
F00F07B0: 28bffff5                 bleu,a  loc_F00F0784
F00F07B4: 912c2002                 sll     %l0, 2, %o0
F00F07B8: 80a2e000                 cmp     %o3, 0
F00F07BC: 3280000f                 bne,a   loc_F00F07F8
F00F07C0: a0200010                 neg     %l0
F00F07C4: 1080000e                 ba      loc_F00F07FC
F00F07C8: a2046001                 inc     %l1
F00F07CC: d04a8000                 ldsb    [%o2], %o0
F00F07D0: 80a2202d                 cmp     %o0, 0x2D ! '-'
F00F07D4: 32800004                 bne,a   loc_F00F07E4
F00F07D8: d00a8000                 ldub    [%o2], %o0
F00F07DC: 9402a001                 inc     %o2
F00F07E0: d00a8000                 ldub    [%o2], %o0
F00F07E4: 90023fd0                 inc     -0x30, %o0
F00F07E8: 900a20ff                 and     %o0, 0xFF, %o0
F00F07EC: 80a22009                 cmp     %o0, 9
F00F07F0: 28bffffc                 bleu,a  loc_F00F07E0
F00F07F4: 9402a001                 inc     %o2
F00F07F8: a2046001                 inc     %l1
F00F07FC: d04a8000                 ldsb    [%o2], %o0
F00F0800: 80a22000                 cmp     %o0, 0
F00F0804: 12bfffcf                 bne     loc_F00F0740
F00F0808: 80a44019                 cmp     %l1, %i1
F00F080C: d04a8000                 ldsb    [%o2], %o0
F00F0810: 80a22000                 cmp     %o0, 0
F00F0814: 22800026                 be,a    loc_F00F08AC
F00F0818: c0268000                 clr     [%i2]
F00F081C: b0102000                 mov     0, %i0
F00F0820: d4268000                 st      %o2, [%i2]
F00F0824: 7fffff09                 call    sub_F00F0448
F00F0828: 9010000a                 mov     %o2, %o0
F00F082C: 80a66000                 cmp     %i1, 0
F00F0830: 0280001f                 be      loc_F00F08AC
F00F0834: 94100008                 mov     %o0, %o2
F00F0838: d04a8000                 ldsb    [%o2], %o0
F00F083C: 80a2202d                 cmp     %o0, 0x2D ! '-'
F00F0840: 12800004                 bne     loc_F00F0850
F00F0844: 96102000                 mov     0, %o3
F00F0848: 96102001                 mov     1, %o3
F00F084C: 9402a001                 inc     %o2
F00F0850: d00a8000                 ldub    [%o2], %o0
F00F0854: 92100008                 mov     %o0, %o1
F00F0858: 1080000b                 ba      loc_F00F0884
F00F085C: 90023fd0                 inc     -0x30, %o0
F00F0860: 90020018                 add     %o0, %i0, %o0
F00F0864: 912a2001                 sll     %o0, 1, %o0
F00F0868: 90023fd0                 inc     -0x30, %o0
F00F086C: 932a6018                 sll     %o1, 24, %o1
F00F0870: 933a6018                 sra     %o1, 24, %o1
F00F0874: b0020009                 add     %o0, %o1, %i0
F00F0878: 9402a001                 inc     %o2
F00F087C: d20a8000                 ldub    [%o2], %o1
F00F0880: 90027fd0                 add     %o1, -0x30, %o0
F00F0884: 900a20ff                 and     %o0, 0xFF, %o0
F00F0888: 80a22009                 cmp     %o0, 9
F00F088C: 28bffff5                 bleu,a  loc_F00F0860
F00F0890: 912e2002                 sll     %i0, 2, %o0
F00F0894: 80a2e000                 cmp     %o3, 0
F00F0898: 32800002                 bne,a   loc_F00F08A0
F00F089C: b0200018                 neg     %i0
F00F08A0: 90260010                 sub     %i0, %l0, %o0
F00F08A4: 10800003                 ba      locret_F00F08B0
F00F08A8: d026c000                 st      %o0, [%i3]
F00F08AC: c026c000                 clr     [%i3]
F00F08B0: 81c7e008                 ret
F00F08B4: 91e80011                 restore %g0, %l1, %o0
