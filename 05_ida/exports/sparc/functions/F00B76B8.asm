F00B76B8: 9de3bf98                 save    %sp, -0x68, %sp
F00B76BC: e00e6009                 ldub    [%i1+9], %l0
F00B76C0: 9a0c20ff                 and     %l0, 0xFF, %o5
F00B76C4: 9206000d                 add     %i0, %o5, %o1
F00B76C8: d00a605e                 ldub    [%o1+0x5E], %o0
F00B76CC: 80a22000                 cmp     %o0, 0
F00B76D0: 22800020                 be,a    loc_F00B7750
F00B76D4: d00e2031                 ldub    [%i0+0x31], %o0
F00B76D8: d00a606e                 ldub    [%o1+0x6E], %o0
F00B76DC: 80a22000                 cmp     %o0, 0
F00B76E0: 0280000d                 be      loc_F00B7714
F00B76E4: 153c047a                 sethi   %hi(aTargetDDRevert), %o2! "Target %d.%d reverting to async. mode"
F00B76E8: c02a6066                 clrb    [%o1+0x66]
F00B76EC: c02a605e                 clrb    [%o1+0x5E]
F00B76F0: 90100018                 mov     %i0, %o0
F00B76F4: 92102003                 mov     3, %o1
F00B76F8: 9412a388                 bset    %lo(aTargetDDRevert), %o2! "Target %d.%d reverting to async. mode"
F00B76FC: 96102001                 mov     1, %o3
F00B7700: d80e207a                 ldub    [%i0+0x7A], %o4
F00B7704: 972ac00d                 sll     %o3, %o5, %o3
F00B7708: 9813000b                 bset    %o3, %o4
F00B770C: 10800008                 ba      loc_F00B772C
F00B7710: d82e207a                 stb     %o4, [%i0+0x7A]
F00B7714: 90022001                 inc     %o0
F00B7718: d02a606e                 stb     %o0, [%o1+0x6E]
F00B771C: 90100018                 mov     %i0, %o0
F00B7720: 92102003                 mov     3, %o1
F00B7724: 153c047a9412a3b0         set     aTargetDDReduci, %o2! "Target %d.%d reducing sync. transfer ra"...
F00B772C: d80e600a                 ldub    [%i1+0xA], %o4
F00B7730: 4000012f                 call    _esplog
F00B7734: 9610000d                 mov     %o5, %o3
F00B7738: 90102001                 mov     1, %o0
F00B773C: d20e2078                 ldub    [%i0+0x78], %o1
F00B7740: 912a0010                 sll     %o0, %l0, %o0
F00B7744: 902a4008                 andn    %o1, %o0, %o0
F00B7748: d02e2078                 stb     %o0, [%i0+0x78]
F00B774C: d00e2031                 ldub    [%i0+0x31], %o0
F00B7750: 90023ffd                 inc     -3, %o0
F00B7754: 900a20ff                 and     %o0, 0xFF, %o0
F00B7758: 80a22001                 cmp     %o0, 1
F00B775C: 08800010                 bleu    locret_F00B779C
F00B7760: 01000000                 nop
F00B7764: d00e2032                 ldub    [%i0+0x32], %o0
F00B7768: 808a2080                 btst    0x80, %o0
F00B776C: 1280000c                 bne     locret_F00B779C
F00B7770: 90122080                 bset    0x80, %o0
F00B7774: d02e2032                 stb     %o0, [%i0+0x32]
F00B7778: 90100018                 mov     %i0, %o0
F00B777C: 92102003                 mov     3, %o1
F00B7780: d802209c                 ld      [%o0+0x9C], %o4
F00B7784: 153c047a                 sethi   %hi(aRevertingToSlo), %o2! "Reverting to slow SCSI cable mode"
F00B7788: d60b2020                 ldub    [%o4+0x20], %o3
F00B778C: 9412a3e0                 bset    %lo(aRevertingToSlo), %o2! "Reverting to slow SCSI cable mode"
F00B7790: 9612e080                 bset    0x80, %o3
F00B7794: 40000116                 call    _esplog
F00B7798: d62b2020                 stb     %o3, [%o4+0x20]
F00B779C: 81c7e008                 ret
F00B77A0: 81e80000                 restore
