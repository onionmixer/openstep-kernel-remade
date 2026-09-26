F001EB04: 9de3bf98                 save    %sp, -0x68, %sp
F001EB08: 4001e063                 call    _splnet
F001EB0C: 01000000                 nop
F001EB10: d2162006                 lduh    [%i0+6], %o1
F001EB14: 808a6002                 btst    2, %o1
F001EB18: 12800004                 bne     loc_F001EB28
F001EB1C: a0100008                 mov     %o0, %l0
F001EB20: 1080000f                 ba      loc_F001EB5C
F001EB24: b0102039                 mov     0x39, %i0 ! '9'
F001EB28: 808a6008                 btst    8, %o1
F001EB2C: 02800004                 be      loc_F001EB3C
F001EB30: 90100018                 mov     %i0, %o0
F001EB34: 1080000a                 ba      loc_F001EB5C
F001EB38: b0102025                 mov     0x25, %i0 ! '%'
F001EB3C: 92102006                 mov     6, %o1
F001EB40: d802200c                 ld      [%o0+0xC], %o4
F001EB44: 94102000                 mov     0, %o2
F001EB48: da03201c                 ld      [%o4+0x1C], %o5
F001EB4C: 96102000                 mov     0, %o3
F001EB50: 9fc34000                 call    %o5
F001EB54: 98102000                 mov     0, %o4
F001EB58: b0100008                 mov     %o0, %i0
F001EB5C: 4001e072                 call    _splx
F001EB60: 90100010                 mov     %l0, %o0
F001EB64: 81c7e008                 ret
F001EB68: 81e80000                 restore
