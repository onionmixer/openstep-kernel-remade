F00B0BFC: 9de3bf98                 save    %sp, -0x68, %sp
F00B0C00: d0062028                 ld      [%i0+0x28], %o0
F00B0C04: 7ffffa26                 call    _prom_childnode
F00B0C08: a4102000                 mov     0, %l2
F00B0C0C: a2920000                 orcc    %o0, %g0, %l1
F00B0C10: 0280002a                 be      locret_F00B0CB8
F00B0C14: 90100018                 mov     %i0, %o0
F00B0C18: 7fffff85                 call    sub_F00B0A2C
F00B0C1C: 92100011                 mov     %l1, %o1! size_t
F00B0C20: 80a22000                 cmp     %o0, 0
F00B0C24: 12800014                 bne     loc_F00B0C74
F00B0C28: 01000000                 nop
F00B0C2C: 7ffedd11                 call    _kalloc
F00B0C30: 90102038                 mov     0x38, %o0! void *
F00B0C34: a0100008                 mov     %o0, %l0
F00B0C38: 7fff9088                 call    _bzero
F00B0C3C: 92102038                 mov     0x38, %o1 ! '8'
F00B0C40: 90100018                 mov     %i0, %o0
F00B0C44: 7fffff8b                 call    sub_F00B0A70
F00B0C48: 92100010                 mov     %l0, %o1
F00B0C4C: e2242028                 st      %l1, [%l0+0x28]
F00B0C50: f0240000                 st      %i0, [%l0]
F00B0C54: 7ffffee4                 call    sub_F00B07E4
F00B0C58: 90100010                 mov     %l0, %o0
F00B0C5C: 7fffff62                 call    sub_F00B09E4
F00B0C60: d004200c                 ld      [%l0+0xC], %o0
F00B0C64: 80a4a000                 cmp     %l2, 0
F00B0C68: 12800003                 bne     loc_F00B0C74
F00B0C6C: d0242020                 st      %o0, [%l0+0x20]
F00B0C70: a4100010                 mov     %l0, %l2
F00B0C74: 7ffffa01                 call    _prom_nextnode
F00B0C78: 90100011                 mov     %l1, %o0
F00B0C7C: a2920000                 orcc    %o0, %g0, %l1
F00B0C80: 32bfffe6                 bne,a   loc_F00B0C18
F00B0C84: 90100018                 mov     %i0, %o0
F00B0C88: 10800009                 ba      loc_F00B0CAC
F00B0C8C: a0100012                 mov     %l2, %l0
F00B0C90: 80a22000                 cmp     %o0, 0
F00B0C94: 02800005                 be      loc_F00B0CA8
F00B0C98: e4042004                 ld      [%l0+4], %l2
F00B0C9C: d2022008                 ld      [%o0+8], %o1
F00B0CA0: 9fc24000                 call    %o1
F00B0CA4: 90100010                 mov     %l0, %o0
F00B0CA8: a0100012                 mov     %l2, %l0
F00B0CAC: 80a42000                 cmp     %l0, 0
F00B0CB0: 32bffff8                 bne,a   loc_F00B0C90
F00B0CB4: d0042020                 ld      [%l0+0x20], %o0
F00B0CB8: 81c7e008                 ret
F00B0CBC: 81e80000                 restore
