F0099DD8: 9de3bf90                 save    %sp, -0x70, %sp! int
F0099DDC: e0064000                 ld      [%i1], %l0
F0099DE0: d0040000                 ld      [%l0], %o0
F0099DE4: 80a22000                 cmp     %o0, 0
F0099DE8: 12bffffe                 bne     loc_F0099DE0
F0099DEC: 01000000                 nop
F0099DF0: 7ffff42e                 call    _simple_lock_try
F0099DF4: 90100010                 mov     %l0, %o0
F0099DF8: 80a22000                 cmp     %o0, 0
F0099DFC: 02bffff9                 be      loc_F0099DE0
F0099E00: 80a66000                 cmp     %i1, 0
F0099E04: 02800033                 be      loc_F0099ED0
F0099E08: a6100019                 mov     %i1, %l3
F0099E0C: 2d3fffc0                 sethi   -0x10000, %l6
F0099E10: 1100003faa1223ff         set     0xFFFF, %l5
F0099E18: a807bff6                 add     %fp, var_A, %l4
F0099E1C: e004e010                 ld      [%l3+0x10], %l0
F0099E20: e404e014                 ld      [%l3+0x14], %l2
F0099E24: a0260010                 sub     %i0, %l0, %l0
F0099E28: 900c0016                 and     %l0, %l6, %o0
F0099E2C: 91322010                 srl     %o0, 16, %o0
F0099E30: 7ffdb1b4                 call    _umul
F0099E34: 92100012                 mov     %l2, %o1
F0099E38: a2100008                 mov     %o0, %l1
F0099E3C: a00c0015                 and     %l0, %l5, %l0
F0099E40: 90100010                 mov     %l0, %o0
F0099E44: 7ffdb1af                 call    _umul
F0099E48: 92100012                 mov     %l2, %o1
F0099E4C: 91322010                 srl     %o0, 16, %o0
F0099E50: a2044008                 add     %l1, %o0, %l1
F0099E54: d204e008                 ld      [%l3+8], %o1
F0099E58: a20c7ffe                 and     %l1, -2, %l1
F0099E5C: a0024011                 add     %o1, %l1, %l0
F0099E60: 80a40009                 cmp     %l0, %o1
F0099E64: 2a800018                 bcs,a   loc_F0099EC4
F0099E68: e604e004                 ld      [%l3+4], %l3
F0099E6C: d004e00c                 ld      [%l3+0xC], %o0
F0099E70: 90020009                 add     %o0, %o1, %o0
F0099E74: 80a40008                 cmp     %l0, %o0
F0099E78: 3a800013                 bcc,a   loc_F0099EC4
F0099E7C: e604e004                 ld      [%l3+4], %l3
F0099E80: 90100010                 mov     %l0, %o0! int
F0099E84: 92100014                 mov     %l4, %o1! int
F0099E88: 7ffff874                 call    _copyin
F0099E8C: 94102002                 mov     2, %o2
F0099E90: 80a22000                 cmp     %o0, 0
F0099E94: 02800004                 be      loc_F0099EA4
F0099E98: 90100014                 mov     %l4, %o0! int
F0099E9C: 1080000d                 ba      loc_F0099ED0
F0099EA0: c0266014                 clr     [%i1+0x14]
F0099EA4: 92100010                 mov     %l0, %o1! int
F0099EA8: d617bff6                 lduh    [%fp+var_A], %o3
F0099EAC: 94102002                 mov     2, %o2! int
F0099EB0: 9602c01a                 add     %o3, %i2, %o3! int
F0099EB4: 7ffff886                 call    _copyout
F0099EB8: d637bff6                 sth     %o3, [%fp+var_A]
F0099EBC: 10800006                 ba      loc_F0099ED4
F0099EC0: d0064000                 ld      [%i1], %o0
F0099EC4: 80a4e000                 cmp     %l3, 0
F0099EC8: 32bfffd6                 bne,a   loc_F0099E20
F0099ECC: e004e010                 ld      [%l3+0x10], %l0
F0099ED0: d0064000                 ld      [%i1], %o0
F0099ED4: c0220000                 clr     [%o0]
F0099ED8: 81c7e008                 ret
F0099EDC: 81e80000                 restore
