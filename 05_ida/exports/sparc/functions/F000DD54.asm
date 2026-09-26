F000DD54: 9de3bf98                 save    %sp, -0x68, %sp
F000DD58: e0062158                 ld      [%i0+0x158], %l0
F000DD5C: 80a42000                 cmp     %l0, 0
F000DD60: 0280000a                 be      loc_F000DD88
F000DD64: 113c04d3                 sethi   -0xFECB400, %o0
F000DD68: d006214c                 ld      [%i0+0x14C], %o0
F000DD6C: 4001690d                 call    _kfree
F000DD70: 932c2002                 sll     %l0, 2, %o1
F000DD74: d0062150                 ld      [%i0+0x150], %o0
F000DD78: 4001690a                 call    _kfree
F000DD7C: 92100010                 mov     %l0, %o1
F000DD80: c0262158                 clr     [%i0+0x158]
F000DD84: 113c04d3                 sethi   -0xFECB400, %o0
F000DD88: d0022288                 ld      [%o0+0x288], %o0
F000DD8C: 4001ad11                 call    _zfree
F000DD90: 92100018                 mov     %i0, %o1
F000DD94: 81c7e008                 ret
F000DD98: 81e80000                 restore
