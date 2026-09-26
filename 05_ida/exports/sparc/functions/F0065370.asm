F0065370: 9de3bf98                 save    %sp, -0x68, %sp
F0065374: 80a62000                 cmp     %i0, 0
F0065378: 02800018                 be      locret_F00653D8
F006537C: a0102000                 mov     0, %l0
F0065380: 80a63fff                 cmp     %i0, -1
F0065384: 02800015                 be      locret_F00653D8
F0065388: 01000000                 nop
F006538C: d0060000                 ld      [%i0], %o0
F0065390: 80a22000                 cmp     %o0, 0
F0065394: 12bffffe                 bne     loc_F006538C
F0065398: 01000000                 nop
F006539C: 4000c6c3                 call    _simple_lock_try
F00653A0: 90100018                 mov     %i0, %o0
F00653A4: 80a22000                 cmp     %o0, 0
F00653A8: 02bffff9                 be      loc_F006538C
F00653AC: 01000000                 nop
F00653B0: d2062008                 ld      [%i0+8], %o1
F00653B4: 80a26000                 cmp     %o1, 0
F00653B8: 16800007                 bge     loc_F00653D4
F00653BC: 1100003f                 sethi   0xFC00, %o0
F00653C0: 901223ff                 bset    0x3FF, %o0
F00653C4: 900a4008                 and     %o1, %o0, %o0
F00653C8: 80a22005                 cmp     %o0, 5
F00653CC: 22800002                 be,a    loc_F00653D4
F00653D0: e0062014                 ld      [%i0+0x14], %l0
F00653D4: c0260000                 clr     [%i0]
F00653D8: 81c7e008                 ret
F00653DC: 91e80010                 restore %g0, %l0, %o0
