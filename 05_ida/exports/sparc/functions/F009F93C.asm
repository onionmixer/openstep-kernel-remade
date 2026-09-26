F009F93C: 9de3bf88                 save    %sp, -0x78, %sp
F009F940: 7fffdcef                 call    _splvm
F009F944: 01000000                 nop
F009F948: ac100008                 mov     %o0, %l6
F009F94C: 113c04f790122270         set     _pmap_info, %o0
F009F954: d20220ac                 ld      [%o0+0xAC], %o1
F009F958: 153c04f8a012a01c         set     dword_F013E01C, %l0
F009F960: 92026001                 inc     %o1
F009F964: d22220ac                 st      %o1, [%o0+0xAC]
F009F968: d0040000                 ld      [%l0], %o0
F009F96C: 80a22000                 cmp     %o0, 0
F009F970: 12bffffe                 bne     loc_F009F968
F009F974: 01000000                 nop
F009F978: 7fffdd4c                 call    _simple_lock_try
F009F97C: 90100010                 mov     %l0, %o0
F009F980: 80a22000                 cmp     %o0, 0
F009F984: 02bffff9                 be      loc_F009F968
F009F988: 113c04f8                 sethi   %hi(dword_F013E014), %o0
F009F98C: ea022014                 ld      [%o0+%lo(dword_F013E014)], %l5
F009F990: 90122014                 bset    %lo(dword_F013E014), %o0
F009F994: 80a6a000                 cmp     %i2, 0
F009F998: 0280002b                 be      loc_F009FA44
F009F99C: e2022004                 ld      [%o0+4], %l1
F009F9A0: 293c0447                 sethi   -0xFEEE400, %l4
F009F9A4: 273c04d0                 sethi   -0xFECC000, %l3
F009F9A8: 110003ffa41223ff         set     0xFFFFF, %l2
F009F9B0: e005213c                 ld      [%l4+0x13C], %l0
F009F9B4: 90100019                 mov     %i1, %o0
F009F9B8: 7ffd9bba                 call    _urem
F009F9BC: 92100010                 mov     %l0, %o1
F009F9C0: a0240008                 sub     %l0, %o0, %l0
F009F9C4: 80a68010                 cmp     %i2, %l0
F009F9C8: 2a800002                 bcs,a   loc_F009F9D0
F009F9CC: a010001a                 mov     %i2, %l0
F009F9D0: ea27bff4                 st      %l5, [%fp+var_C]
F009F9D4: c023a05c                 clr     [%sp+0x78+var_1C]
F009F9D8: 9007bff4                 add     %fp, var_C, %o0
F009F9DC: 92100011                 mov     %l1, %o1
F009F9E0: 96102007                 mov     7, %o3
F009F9E4: 98102001                 mov     1, %o4
F009F9E8: d404e0d8                 ld      [%l3+0xD8], %o2
F009F9EC: 9a102000                 mov     0, %o5
F009F9F0: 942e400a                 andn    %i1, %o2, %o2
F009F9F4: 9532a00c                 srl     %o2, 12, %o2
F009F9F8: 40000788                 call    _set_pte
F009F9FC: 940a8012                 and     %o2, %l2, %o2! size_t
F009FA00: d004e0d8                 ld      [%l3+0xD8], %o0
F009FA04: 902e4008                 andn    %i1, %o0, %o0
F009FA08: 9132200c                 srl     %o0, 12, %o0
F009FA0C: 40000629                 call    _pmap_vacflush
F009FA10: 900a0012                 and     %o0, %l2, %o0
F009FA14: 90100019                 mov     %i1, %o0
F009FA18: d205213c                 ld      [%l4+0x13C], %o1
F009FA1C: 7ffd9ba1                 call    _urem
F009FA20: b2064010                 add     %i1, %l0, %i1
F009FA24: 92100008                 mov     %o0, %o1
F009FA28: 90100018                 mov     %i0, %o0! void *
F009FA2C: 92044009                 add     %l1, %o1, %o1! void *
F009FA30: 7fffd438                 call    _bcopy
F009FA34: 94100010                 mov     %l0, %o2
F009FA38: b4a68010                 subcc   %i2, %l0, %i2
F009FA3C: 12bfffdd                 bne     loc_F009F9B0
F009FA40: b0060010                 add     %i0, %l0, %i0
F009FA44: 113c04f8                 sethi   %hi(dword_F013E01C), %o0
F009FA48: c022201c                 clr     [%o0+%lo(dword_F013E01C)]
F009FA4C: 7fffdcb6                 call    _splx
F009FA50: 90100016                 mov     %l6, %o0
F009FA54: 81c7e008                 ret
F009FA58: 81e80000                 restore
