F002ABE4: 9de3bf90                 save    %sp, -0x70, %sp
F002ABE8: 4000047f                 call    _if_private
F002ABEC: 90100018                 mov     %i0, %o0! __s1
F002ABF0: e0022014                 ld      [%o0+0x14], %l0
F002ABF4: 133c03d3921260f0         set     _IFCONTROL_AUTOADDR, %o1! "autoaddr"
F002ABFC: 7fff756c                 call    _strcmp
F002AC00: 90100019                 mov     %i1, %o0
F002AC04: 80a22000                 cmp     %o0, 0
F002AC08: 1280000e                 bne     loc_F002AC40
F002AC0C: 90100019                 mov     %i1, %o0
F002AC10: d0568000                 ldsh    [%i2], %o0
F002AC14: 80a22002                 cmp     %o0, 2
F002AC18: 32800042                 bne,a   locret_F002AD20
F002AC1C: b010202f                 mov     0x2F, %i0 ! '/'
F002AC20: 40000471                 call    _if_private
F002AC24: 90100018                 mov     %i0, %o0
F002AC28: 94022008                 add     %o0, 8, %o2
F002AC2C: 90100018                 mov     %i0, %o0! __s1
F002AC30: 400012fe                 call    _in_bootp
F002AC34: 9210001a                 mov     %i2, %o1
F002AC38: 1080003a                 ba      locret_F002AD20
F002AC3C: b0100008                 mov     %o0, %i0
F002AC40: 133c03d3                 sethi   %hi(_IFCONTROL_SETADDR), %o1! "setaddr"
F002AC44: 7fff755a                 call    _strcmp
F002AC48: 921260e0                 bset    %lo(_IFCONTROL_SETADDR), %o1! "setaddr"
F002AC4C: 80a22000                 cmp     %o0, 0
F002AC50: 12800030                 bne     loc_F002AD10
F002AC54: 90100010                 mov     %l0, %o0
F002AC58: d0568000                 ldsh    [%i2], %o0
F002AC5C: 80a22002                 cmp     %o0, 2
F002AC60: 02800004                 be      loc_F002AC70
F002AC64: 01000000                 nop
F002AC68: 1080002e                 ba      locret_F002AD20
F002AC6C: b010202f                 mov     0x2F, %i0 ! '/'
F002AC70: 40000475                 call    _if_flags
F002AC74: 90100018                 mov     %i0, %o0
F002AC78: 1300002092126001         set     0x8001, %o1
F002AC80: 92120009                 bset    %o0, %o1
F002AC84: 40000488                 call    _if_flags_set
F002AC88: 90100018                 mov     %i0, %o0
F002AC8C: 40000440                 call    _if_init
F002AC90: 90100010                 mov     %l0, %o0
F002AC94: 80a22000                 cmp     %o0, 0
F002AC98: 12800007                 bne     loc_F002ACB4
F002AC9C: 01000000                 nop
F002ACA0: 40000469                 call    _if_flags
F002ACA4: 90100018                 mov     %i0, %o0
F002ACA8: 92122040                 or      %o0, 0x40, %o1
F002ACAC: 4000047e                 call    _if_flags_set
F002ACB0: 90100018                 mov     %i0, %o0
F002ACB4: 4000044c                 call    _if_private
F002ACB8: 90100018                 mov     %i0, %o0
F002ACBC: d206a004                 ld      [%i2+4], %o1
F002ACC0: d2222010                 st      %o1, [%o0+0x10]
F002ACC4: 40000460                 call    _if_flags
F002ACC8: 90100018                 mov     %i0, %o0
F002ACCC: 13000010                 sethi   0x4000, %o1
F002ACD0: 808a0009                 btst    %o1, %o0
F002ACD4: 32800013                 bne,a   locret_F002AD20
F002ACD8: b0102000                 mov     0, %i0
F002ACDC: 40000442                 call    _if_private
F002ACE0: 90100018                 mov     %i0, %o0
F002ACE4: d0022010                 ld      [%o0+0x10], %o0
F002ACE8: d027bff4                 st      %o0, [%fp+var_C]
F002ACEC: 4000043e                 call    _if_private
F002ACF0: 90100018                 mov     %i0, %o0
F002ACF4: 92022008                 add     %o0, 8, %o1
F002ACF8: 90100018                 mov     %i0, %o0
F002ACFC: 9407bff4                 add     %fp, var_C, %o2
F002AD00: 40000a1d                 call    _arpwhohas
F002AD04: 9606a004                 add     %i2, 4, %o3
F002AD08: 10800006                 ba      locret_F002AD20
F002AD0C: b0102000                 mov     0, %i0
F002AD10: 92100019                 mov     %i1, %o1
F002AD14: 400003c1                 call    _if_control
F002AD18: 9410001a                 mov     %i2, %o2
F002AD1C: b0100008                 mov     %o0, %i0
F002AD20: 81c7e008                 ret
F002AD24: 81e80000                 restore
