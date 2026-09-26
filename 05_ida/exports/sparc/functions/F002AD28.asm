F002AD28: 9de3bf98                 save    %sp, -0x68, %sp
F002AD2C: 4000042e                 call    _if_private
F002AD30: 90100018                 mov     %i0, %o0
F002AD34: e0022014                 ld      [%o0+0x14], %l0
F002AD38: 4000043b                 call    _if_mtu
F002AD3C: 90100018                 mov     %i0, %o0
F002AD40: a2100008                 mov     %o0, %l1
F002AD44: 4000041d                 call    _if_getbuf
F002AD48: 90100010                 mov     %l0, %o0
F002AD4C: b0920000                 orcc    %o0, %g0, %i0
F002AD50: 12800004                 bne     loc_F002AD60
F002AD54: 90100018                 mov     %i0, %o0
F002AD58: 1080000e                 ba      locret_F002AD90
F002AD5C: b0102000                 mov     0, %i0
F002AD60: 40000382                 call    _nb_shrink_top
F002AD64: 92102008                 mov     8, %o1
F002AD68: 4000035c                 call    _nb_size
F002AD6C: 90100018                 mov     %i0, %o0
F002AD70: 80a20011                 cmp     %o0, %l1
F002AD74: 08800007                 bleu    locret_F002AD90
F002AD78: 01000000                 nop
F002AD7C: 40000357                 call    _nb_size
F002AD80: 90100018                 mov     %i0, %o0
F002AD84: 92220011                 sub     %o0, %l1, %o1
F002AD88: 4000038a                 call    _nb_shrink_bot
F002AD8C: 90100018                 mov     %i0, %o0
F002AD90: 81c7e008                 ret
F002AD94: 81e80000                 restore
