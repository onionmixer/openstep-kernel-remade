F00A5BD4: 9de3bf98                 save    %sp, -0x68, %sp
F00A5BD8: 7fffc3d2                 call    _spl8
F00A5BDC: b12e2004                 sll     %i0, 4, %i0
F00A5BE0: a4100008                 mov     %o0, %l2
F00A5BE4: 213c0008a0142100         set     loc_F0002100, %l0
F00A5BEC: a2060010                 add     %i0, %l0, %l1
F00A5BF0: 90100011                 mov     %l1, %o0
F00A5BF4: 7fffda74                 call    _pmap_change_prot
F00A5BF8: 92102007                 mov     7, %o1
F00A5BFC: d0064000                 ld      [%i1], %o0
F00A5C00: d0260010                 st      %o0, [%i0+%l0]
F00A5C04: d0066004                 ld      [%i1+4], %o0
F00A5C08: d0246004                 st      %o0, [%l1+4]
F00A5C0C: d2066008                 ld      [%i1+8], %o1
F00A5C10: 90100011                 mov     %l1, %o0
F00A5C14: d2222008                 st      %o1, [%o0+8]
F00A5C18: d406600c                 ld      [%i1+0xC], %o2
F00A5C1C: 92102001                 mov     1, %o1
F00A5C20: 7fffda69                 call    _pmap_change_prot
F00A5C24: d422200c                 st      %o2, [%o0+0xC]
F00A5C28: 7fffc43f                 call    _splx
F00A5C2C: 90100012                 mov     %l2, %o0
F00A5C30: 81c7e008                 ret
F00A5C34: 81e80000                 restore
