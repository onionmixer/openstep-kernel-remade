F00D0DC8: 9de3bf90                 save    %sp, -0x70, %sp
F00D0DCC: 113c0504                 sethi   %hi(paDevicedescript_1), %o0! id
F00D0DD0: d2022158                 ld      [%o0+%lo(paDevicedescript_1)], %o1! SEL
F00D0DD4: 400082a7                 call    _objc_msgSend
F00D0DD8: 90100018                 mov     %i0, %o0! id
F00D0DDC: 133c0504                 sethi   %hi(paConfigtable_0), %o1! SEL
F00D0DE0: 400082a4                 call    _objc_msgSend
F00D0DE4: d2026310                 ld      [%o1+%lo(paConfigtable_0)], %o1
F00D0DE8: 80a22000                 cmp     %o0, 0
F00D0DEC: 02800014                 be      loc_F00D0E3C
F00D0DF0: 133c0504                 sethi   %hi(paValueforstring), %o1
F00D0DF4: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00D0DF8: 4000829e                 call    _objc_msgSend
F00D0DFC: 9410001b                 mov     %i3, %o2
F00D0E00: a0920000                 orcc    %o0, %g0, %l0
F00D0E04: 2280000f                 be,a    loc_F00D0E40
F00D0E08: f027bff0                 st      %i0, [%fp+var_10]
F00D0E0C: 7ffcd98b                 call    _strlen
F00D0E10: 01000000                 nop
F00D0E14: d2070000                 ld      [%i4], %o1! __src
F00D0E18: a2022001                 add     %o0, 1, %l1
F00D0E1C: 80a44009                 cmp     %l1, %o1
F00D0E20: 18800007                 bgu     loc_F00D0E3C
F00D0E24: 9010001a                 mov     %i2, %o0! __dst
F00D0E28: 7ffcd9c0                 call    _strcpy
F00D0E2C: 92100010                 mov     %l0, %o1
F00D0E30: e2270000                 st      %l1, [%i4]
F00D0E34: 1080000e                 ba      locret_F00D0E6C
F00D0E38: b0102000                 mov     0, %i0
F00D0E3C: f027bff0                 st      %i0, [%fp+var_10]
F00D0E40: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D0E44: 9410001a                 mov     %i2, %o2
F00D0E48: 133c0508                 sethi   %hi(stru_F014218C.ext), %o1
F00D0E4C: d60261b8                 ld      [%o1+%lo(stru_F014218C.ext)], %o3
F00D0E50: 9810001c                 mov     %i4, %o4
F00D0E54: 133c0504                 sethi   %hi(paGetcharvaluesF_0), %o1
F00D0E58: d627bff4                 st      %o3, [%fp+var_C]
F00D0E5C: d20262d0                 ld      [%o1+%lo(paGetcharvaluesF_0)], %o1! SEL
F00D0E60: 400082c7                 call    _objc_msgSendSuper
F00D0E64: 9610001b                 mov     %i3, %o3
F00D0E68: b0100008                 mov     %o0, %i0
F00D0E6C: 81c7e008                 ret
F00D0E70: 81e80000                 restore
