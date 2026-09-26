F00A5D08: 9de3bf98                 save    %sp, -0x68, %sp
F00A5D0C: 173c0464                 sethi   %hi(_cpuid), %o3
F00A5D10: 133c04f898126110         set     _a_head, %o4
F00A5D18: d002e340                 ld      [%o3+%lo(_cpuid)], %o0
F00A5D1C: 133c04f8                 sethi   %hi(_a_tail), %o1
F00A5D20: 912a2002                 sll     %o0, 2, %o0
F00A5D24: d402000c                 ld      [%o0+%o4], %o2
F00A5D28: 92126118                 bset    %lo(_a_tail), %o1
F00A5D2C: d0020009                 ld      [%o0+%o1], %o0
F00A5D30: 80a28008                 cmp     %o2, %o0
F00A5D34: 02800067                 be      locret_F00A5ED0
F00A5D38: a4102000                 mov     0, %l2
F00A5D3C: a6100009                 mov     %o1, %l3
F00A5D40: 113c04f9aa122270         set     _a_flts, %l5
F00A5D48: 293c0466                 sethi   -0xFEE6800, %l4
F00A5D4C: ac10000c                 mov     %o4, %l6
F00A5D50: d402e340                 ld      [%o3+0x340], %o2
F00A5D54: 932aa002                 sll     %o2, 2, %o1
F00A5D58: d0024013                 ld      [%o1+%l3], %o0
F00A5D5C: 90022001                 inc     %o0
F00A5D60: 900a203f                 and     %o0, 0x3F, %o0
F00A5D64: d0224013                 st      %o0, [%o1+%l3]
F00A5D68: 932a2001                 sll     %o0, 1, %o1
F00A5D6C: 92024008                 add     %o1, %o0, %o1
F00A5D70: 932a6003                 sll     %o1, 3, %o1
F00A5D74: 912aa001                 sll     %o2, 1, %o0
F00A5D78: 9002000a                 add     %o0, %o2, %o0
F00A5D7C: 912a2009                 sll     %o0, 9, %o0
F00A5D80: 92024008                 add     %o1, %o0, %o1
F00A5D84: 90024015                 add     %o1, %l5, %o0
F00A5D88: f0022004                 ld      [%o0+4], %i0
F00A5D8C: e0022008                 ld      [%o0+8], %l0
F00A5D90: d2124015                 lduh    [%o1+%l5], %o1
F00A5D94: 80a26002                 cmp     %o1, 2
F00A5D98: 02800007                 be      loc_F00A5DB4
F00A5D9C: e202200c                 ld      [%o0+0xC], %l1
F00A5DA0: 80a26004                 cmp     %o1, 4
F00A5DA4: 02800023                 be      loc_F00A5E30
F00A5DA8: 113c0466                 sethi   -0xFEE6800, %o0
F00A5DAC: 10800033                 ba      loc_F00A5E78
F00A5DB0: 80a4a000                 cmp     %l2, 0
F00A5DB4: 808e2001                 btst    1, %i0
F00A5DB8: 32800002                 bne,a   loc_F00A5DC0
F00A5DBC: a4102001                 mov     1, %l2
F00A5DC0: 90100018                 mov     %i0, %o0
F00A5DC4: 92100010                 mov     %l0, %o1
F00A5DC8: 94100011                 mov     %l1, %o2
F00A5DCC: 40000316                 call    _log_mem_err
F00A5DD0: 96102000                 mov     0, %o3
F00A5DD4: 808e2008                 btst    8, %i0
F00A5DD8: 02800027                 be      loc_F00A5E74
F00A5DDC: 90100018                 mov     %i0, %o0
F00A5DE0: 92100010                 mov     %l0, %o1
F00A5DE4: 40000370                 call    _fix_nc_ecc
F00A5DE8: 94100011                 mov     %l1, %o2
F00A5DEC: 80a23fff                 cmp     %o0, -1
F00A5DF0: 12800022                 bne     loc_F00A5E78
F00A5DF4: 80a4a000                 cmp     %l2, 0
F00A5DF8: 113c046690122158         set     aAfsr0xX, %o0! "AFSR = 0x%x, "
F00A5E00: 7ffdba16                 call    _printf
F00A5E04: 92100018                 mov     %i0, %o1
F00A5E08: 113c046690122168         set     aAfar00xXAfar10, %o0! "AFAR0 = 0x%x, AFAR1 = 0x%x\n"
F00A5E10: 92100010                 mov     %l0, %o1
F00A5E14: 7ffdba11                 call    _printf
F00A5E18: 94100011                 mov     %l1, %o2
F00A5E1C: 113c0466                 sethi   %hi(aAsynchronousFa), %o0! "Asynchronous fault"
F00A5E20: 7ffdbcd4                 call    _panic
F00A5E24: 90122188                 bset    %lo(aAsynchronousFa), %o0! "Asynchronous fault"
F00A5E28: 10800014                 ba      loc_F00A5E78
F00A5E2C: 80a4a000                 cmp     %l2, 0
F00A5E30: 7ffdba0a                 call    _printf
F00A5E34: 901221a0                 bset    0x1A0, %o0
F00A5E38: 113c0466                 sethi   %hi(aDueToUserWrite), %o0! "due to user write - non-fatal\n"
F00A5E3C: 7ffdba07                 call    _printf
F00A5E40: 901221c0                 bset    %lo(aDueToUserWrite), %o0! "due to user write - non-fatal\n"
F00A5E44: 90100018                 mov     %i0, %o0
F00A5E48: 400001fa                 call    _log_mtos_err
F00A5E4C: 92100010                 mov     %l0, %o1! char *
F00A5E50: 113c04cf                 sethi   %hi(_active_u), %o0
F00A5E54: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00A5E58: d0020000                 ld      [%o0], %o0! unsigned int
F00A5E5C: 7ffdadc6                 call    _psignal
F00A5E60: 9210200a                 mov     0xA, %o1
F00A5E64: 90102001                 mov     1, %o0
F00A5E68: 92102309                 mov     0x309, %o1
F00A5E6C: 7ffef7a3                 call    _exception
F00A5E70: 94100010                 mov     %l0, %o2
F00A5E74: 80a4a000                 cmp     %l2, 0
F00A5E78: 32800005                 bne,a   loc_F00A5E8C
F00A5E7C: d0052154                 ld      [%l4+0x154], %o0
F00A5E80: 113c0466                 sethi   %hi(aAfsr0xXAfar00x), %o0! "AFSR = 0x%x, AFAR0 = 0x%x, AFAR1 = 0x%x"...
F00A5E84: 10800006                 ba      loc_F00A5E9C
F00A5E88: 901221e0                 bset    %lo(aAfsr0xXAfar00x), %o0! "AFSR = 0x%x, AFAR0 = 0x%x, AFAR1 = 0x%x"...
F00A5E8C: 80a22000                 cmp     %o0, 0
F00A5E90: 02800007                 be      loc_F00A5EAC
F00A5E94: 113c0466                 sethi   %hi(aAfsr0xXAfar00x_0), %o0! "AFSR = 0x%x, AFAR0 = 0x%x, AFAR1 = 0x%x"...
F00A5E98: 90122210                 bset    %lo(aAfsr0xXAfar00x_0), %o0! "AFSR = 0x%x, AFAR0 = 0x%x, AFAR1 = 0x%x"...
F00A5E9C: 92100018                 mov     %i0, %o1
F00A5EA0: 94100010                 mov     %l0, %o2
F00A5EA4: 7ffdb9ed                 call    _printf
F00A5EA8: 96100011                 mov     %l1, %o3
F00A5EAC: 173c0464                 sethi   %hi(_cpuid), %o3
F00A5EB0: d002e340                 ld      [%o3+%lo(_cpuid)], %o0
F00A5EB4: 912a2002                 sll     %o0, 2, %o0
F00A5EB8: d2020016                 ld      [%o0+%l6], %o1
F00A5EBC: a4102000                 mov     0, %l2
F00A5EC0: d0020013                 ld      [%o0+%l3], %o0
F00A5EC4: 80a24008                 cmp     %o1, %o0
F00A5EC8: 12bfffa2                 bne     loc_F00A5D50
F00A5ECC: c0252154                 clr     [%l4+0x154]
F00A5ED0: 81c7e008                 ret
F00A5ED4: 91e82001                 restore %g0, 1, %o0
