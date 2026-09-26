F00F06A8: 9de3bf98                 save    %sp, -0x68, %sp
F00F06AC: a0102000                 mov     0, %l0
F00F06B0: 7fffff66                 call    sub_F00F0448
F00F06B4: d0062004                 ld      [%i0+4], %o0
F00F06B8: 94100008                 mov     %o0, %o2
F00F06BC: d00a8000                 ldub    [%o2], %o0
F00F06C0: 92100008                 mov     %o0, %o1
F00F06C4: 1080000b                 ba      loc_F00F06F0
F00F06C8: 90023fd0                 inc     -0x30, %o0
F00F06CC: 90020010                 add     %o0, %l0, %o0
F00F06D0: 912a2001                 sll     %o0, 1, %o0
F00F06D4: 90023fd0                 inc     -0x30, %o0
F00F06D8: 932a6018                 sll     %o1, 24, %o1
F00F06DC: 933a6018                 sra     %o1, 24, %o1
F00F06E0: a0020009                 add     %o0, %o1, %l0
F00F06E4: 9402a001                 inc     %o2
F00F06E8: d20a8000                 ldub    [%o2], %o1
F00F06EC: 90027fd0                 add     %o1, -0x30, %o0
F00F06F0: 900a20ff                 and     %o0, 0xFF, %o0
F00F06F4: 80a22009                 cmp     %o0, 9
F00F06F8: 08bffff5                 bleu    loc_F00F06CC
F00F06FC: 912c2002                 sll     %l0, 2, %o0
F00F0700: 81c7e008                 ret
F00F0704: 91e80010                 restore %g0, %l0, %o0
