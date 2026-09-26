F0022E1C: 9de3bf98                 save    %sp, -0x68, %sp
F0022E20: e0060000                 ld      [%i0], %l0
F0022E24: 90100018                 mov     %i0, %o0
F0022E28: 7fffffcc                 call    _unp_disconnect
F0022E2C: f2342056                 sth     %i1, [%l0+0x56]
F0022E30: d0042010                 ld      [%l0+0x10], %o0
F0022E34: 80a22000                 cmp     %o0, 0
F0022E38: 0280000a                 be      locret_F0022E60
F0022E3C: 01000000                 nop
F0022E40: c0242008                 clr     [%l0+8]
F0022E44: 7fffeb88                 call    _m_freem
F0022E48: d0062018                 ld      [%i0+0x18], %o0
F0022E4C: 90100018                 mov     %i0, %o0
F0022E50: 400114d4                 call    _kfree
F0022E54: 92102024                 mov     0x24, %o1 ! '$'
F0022E58: 7fffee57                 call    _sofree
F0022E5C: 90100010                 mov     %l0, %o0
F0022E60: 81c7e008                 ret
F0022E64: 81e80000                 restore
