F00319F0: 9de3bf98                 save    %sp, -0x68, %sp
F00319F4: e20e0000                 ldub    [%i0], %l1
F00319F8: a00e3f80                 and     %i0, -0x80, %l0
F00319FC: d0042004                 ld      [%l0+4], %o0
F0031A00: d2142008                 lduh    [%l0+8], %o1
F0031A04: a20c600f                 and     %l1, 0xF, %l1
F0031A08: a32c6002                 sll     %l1, 2, %l1
F0031A0C: 90020011                 add     %o0, %l1, %o0
F0031A10: d0242004                 st      %o0, [%l0+4]
F0031A14: 92224011                 sub     %o1, %l1, %o1
F0031A18: e4042004                 ld      [%l0+4], %l2
F0031A1C: d2342008                 sth     %o1, [%l0+8]
F0031A20: a4040012                 add     %l0, %l2, %l2
F0031A24: c034a002                 clrh    [%l2+2]
F0031A28: d2562002                 ldsh    [%i0+2], %o1
F0031A2C: 90100010                 mov     %l0, %o0
F0031A30: 40019d16                 call    _in_cksum
F0031A34: 92224011                 sub     %o1, %l1, %o1
F0031A38: d034a002                 sth     %o0, [%l2+2]
F0031A3C: 90100010                 mov     %l0, %o0
F0031A40: 92100019                 mov     %i1, %o1
F0031A44: d6022004                 ld      [%o0+4], %o3
F0031A48: 98102000                 mov     0, %o4
F0031A4C: d4122008                 lduh    [%o0+8], %o2
F0031A50: 9622c011                 sub     %o3, %l1, %o3
F0031A54: d6222004                 st      %o3, [%o0+4]
F0031A58: 94028011                 add     %o2, %l1, %o2
F0031A5C: d4322008                 sth     %o2, [%o0+8]
F0031A60: 94102000                 mov     0, %o2
F0031A64: 40000687                 call    _ip_output
F0031A68: 96102000                 mov     0, %o3
F0031A6C: 81c7e008                 ret
F0031A70: 81e80000                 restore
