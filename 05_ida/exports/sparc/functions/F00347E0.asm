F00347E0: 9de3bf98                 save    %sp, -0x68, %sp
F00347E4: 90100019                 mov     %i1, %o0
F00347E8: 92102000                 mov     0, %o1
F00347EC: 150ee6b2                 sethi   0x3B9AC800, %o2
F00347F0: 7fffa555                 call    _m_copy
F00347F4: 9412a200                 bset    0x200, %o2
F00347F8: b2920000                 orcc    %o0, %g0, %i1
F00347FC: 02800013                 be      locret_F0034848
F0034800: 01000000                 nop
F0034804: d4066004                 ld      [%i1+4], %o2
F0034808: a006400a                 add     %i1, %o2, %l0
F003480C: d2142002                 lduh    [%l0+2], %o1
F0034810: c034200a                 clrh    [%l0+0xA]
F0034814: d0142006                 lduh    [%l0+6], %o0
F0034818: d2342002                 sth     %o1, [%l0+2]
F003481C: d0342006                 sth     %o0, [%l0+6]
F0034820: d20e400a                 ldub    [%i1+%o2], %o1
F0034824: 90100019                 mov     %i1, %o0
F0034828: 920a600f                 and     %o1, 0xF, %o1
F003482C: 40019197                 call    _in_cksum
F0034830: 932a6002                 sll     %o1, 2, %o1
F0034834: d034200a                 sth     %o0, [%l0+0xA]
F0034838: 90100018                 mov     %i0, %o0
F003483C: 92100019                 mov     %i1, %o1
F0034840: 7fffd621                 call    _looutput
F0034844: 9410001a                 mov     %i2, %o2
F0034848: 81c7e008                 ret
F003484C: 81e80000                 restore
