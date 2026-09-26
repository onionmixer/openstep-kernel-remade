F00C5CCC: 9de3bf90                 save    %sp, -0x70, %sp
F00C5CD0: e4062004                 ld      [%i0+4], %l2
F00C5CD4: 7ffd05d9                 call    _strlen
F00C5CD8: 9010001a                 mov     %i2, %o0
F00C5CDC: a6100008                 mov     %o0, %l3
F00C5CE0: b010000e                 mov     %sp, %i0
F00C5CE4: 9004e06d                 add     %l3, 0x6D, %o0 ! 'm'
F00C5CE8: 900a3ff8                 and     %o0, -8, %o0
F00C5CEC: 9c238008                 sub     %sp, %o0, %sp
F00C5CF0: a003a060                 add     %sp, arg_60, %l0
F00C5CF4: a2102022                 mov     0x22, %l1 ! '"'
F00C5CF8: e22c0000                 stb     %l1, [%l0]
F00C5CFC: 90042001                 add     %l0, 1, %o0! __dst
F00C5D00: 7ffd060a                 call    _strcpy
F00C5D04: 9210001a                 mov     %i2, %o1! __little
F00C5D08: 90040013                 add     %l0, %l3, %o0
F00C5D0C: e22a2001                 stb     %l1, [%o0+1]
F00C5D10: c02a2002                 clrb    [%o0+2]
F00C5D14: 90100012                 mov     %l2, %o0! __big
F00C5D18: 4000001b                 call    _strstr
F00C5D1C: 92100010                 mov     %l0, %o1! __c
F00C5D20: a0920000                 orcc    %o0, %g0, %l0
F00C5D24: 0280000d                 be      loc_F00C5D58
F00C5D28: a204e002                 add     %l3, 2, %l1
F00C5D2C: 9c100018                 mov     %i0, %sp
F00C5D30: 90040011                 add     %l0, %l1, %o0! __s
F00C5D34: 7ffcfd72                 call    _strchr
F00C5D38: 92102022                 mov     0x22, %o1 ! '"'! __c
F00C5D3C: a0022001                 add     %o0, 1, %l0
F00C5D40: 90100010                 mov     %l0, %o0! __s
F00C5D44: 7ffcfd6e                 call    _strchr
F00C5D48: 92102022                 mov     0x22, %o1 ! '"'
F00C5D4C: 80a22000                 cmp     %o0, 0
F00C5D50: 12800004                 bne     loc_F00C5D60
F00C5D54: a6220010                 sub     %o0, %l0, %l3
F00C5D58: 10800009                 ba      locret_F00C5D7C
F00C5D5C: b0102000                 mov     0, %i0
F00C5D60: 40000074                 call    _IOMalloc
F00C5D64: 9004e001                 add     %l3, 1, %o0! __dst
F00C5D68: b0100008                 mov     %o0, %i0
F00C5D6C: 92100010                 mov     %l0, %o1! __src
F00C5D70: 7ffd06eb                 call    _strncpy
F00C5D74: 94100013                 mov     %l3, %o2
F00C5D78: c02e0013                 clrb    [%i0+%l3]
F00C5D7C: 81c7e008                 ret
F00C5D80: 81e80000                 restore
