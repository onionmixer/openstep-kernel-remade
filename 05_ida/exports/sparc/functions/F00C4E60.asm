F00C4E60: 9de3bf78                 save    %sp, -0x88, %sp
F00C4E64: 113c0504                 sethi   %hi(paConfigtable_0), %o0! id
F00C4E68: d2022310                 ld      [%o0+%lo(paConfigtable_0)], %o1! SEL
F00C4E6C: e007a064                 ld      [%fp+arg_64], %l0
F00C4E70: e207a068                 ld      [%fp+arg_68], %l1
F00C4E74: e407a06c                 ld      [%fp+arg_6C], %l2
F00C4E78: e607a070                 ld      [%fp+arg_70], %l3
F00C4E7C: e807a074                 ld      [%fp+arg_74], %l4
F00C4E80: ea07a078                 ld      [%fp+arg_78], %l5
F00C4E84: 4000b27b                 call    _objc_msgSend
F00C4E88: 9010001a                 mov     %i2, %o0! id
F00C4E8C: 133c0504                 sethi   %hi(paValueforstring), %o1
F00C4E90: 153c03ea                 sethi   %hi(aCharacterMajor), %o2! "Character Major"
F00C4E94: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00C4E98: 4000b276                 call    _objc_msgSend
F00C4E9C: 9412a098                 bset    %lo(aCharacterMajor), %o2! "Character Major"
F00C4EA0: 80a22000                 cmp     %o0, 0
F00C4EA4: 02800019                 be      loc_F00C4F08
F00C4EA8: 98100008                 mov     %o0, %o4
F00C4EAC: d04b0000                 ldsb    [%o4], %o0
F00C4EB0: 96102000                 mov     0, %o3
F00C4EB4: 80a22000                 cmp     %o0, 0
F00C4EB8: 02800012                 be      loc_F00C4F00
F00C4EBC: d20b0000                 ldub    [%o4], %o1
F00C4EC0: 90027fd0                 add     %o1, -0x30, %o0
F00C4EC4: 900a20ff                 and     %o0, 0xFF, %o0
F00C4EC8: 80a22009                 cmp     %o0, 9
F00C4ECC: 1880000d                 bgu     loc_F00C4F00
F00C4ED0: 98032001                 inc     %o4
F00C4ED4: 912ae002                 sll     %o3, 2, %o0
F00C4ED8: 9002000b                 add     %o0, %o3, %o0
F00C4EDC: 912a2001                 sll     %o0, 1, %o0
F00C4EE0: 90023fd0                 inc     -0x30, %o0
F00C4EE4: 932a6018                 sll     %o1, 24, %o1
F00C4EE8: 933a6018                 sra     %o1, 24, %o1
F00C4EEC: d44b0000                 ldsb    [%o4], %o2
F00C4EF0: 96020009                 add     %o0, %o1, %o3
F00C4EF4: 80a2a000                 cmp     %o2, 0
F00C4EF8: 12bffff2                 bne     loc_F00C4EC0
F00C4EFC: d20b0000                 ldub    [%o4], %o1
F00C4F00: 10800003                 ba      loc_F00C4F0C
F00C4F04: b410000b                 mov     %o3, %i2
F00C4F08: b4103fff                 mov     -1, %i2
F00C4F0C: e023a05c                 st      %l0, [%sp+0x88+var_2C]
F00C4F10: e223a060                 st      %l1, [%sp+0x88+var_28]
F00C4F14: e423a064                 st      %l2, [%sp+0x88+var_24]
F00C4F18: e623a068                 st      %l3, [%sp+0x88+var_20]
F00C4F1C: e823a06c                 st      %l4, [%sp+0x88+var_1C]
F00C4F20: ea23a070                 st      %l5, [%sp+0x88+var_18]
F00C4F24: 9010001a                 mov     %i2, %o0
F00C4F28: 9210001b                 mov     %i3, %o1
F00C4F2C: d807a05c                 ld      [%fp+arg_5C], %o4
F00C4F30: 9410001c                 mov     %i4, %o2
F00C4F34: da07a060                 ld      [%fp+arg_60], %o5
F00C4F38: 400017a0                 call    _IOAddToCdevswAt
F00C4F3C: 9610001d                 mov     %i5, %o3
F00C4F40: 94920000                 orcc    %o0, %g0, %o2
F00C4F44: 1680001a                 bge     loc_F00C4FAC
F00C4F48: 133c0506                 sethi   -0xFEBE800, %o1
F00C4F4C: 80a6a000                 cmp     %i2, 0
F00C4F50: 1680000c                 bge     loc_F00C4F80
F00C4F54: 90100018                 mov     %i0, %o0! id
F00C4F58: 133c0504                 sethi   %hi(paName), %o1
F00C4F5C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C4F60: 213c03ea                 sethi   %hi(aSCouldNotAddTo), %l0! "%s: could not add to cdevsw table at an"...
F00C4F64: 4000b243                 call    _objc_msgSend
F00C4F68: a01420a8                 bset    %lo(aSCouldNotAddTo), %l0! "%s: could not add to cdevsw table at an"...
F00C4F6C: 92100008                 mov     %o0, %o1
F00C4F70: 40000461                 call    _IOLog
F00C4F74: 90100010                 mov     %l0, %o0! id
F00C4F78: 10800011                 ba      locret_F00C4FBC
F00C4F7C: b0102000                 mov     0, %i0
F00C4F80: 133c0504                 sethi   %hi(paName), %o1
F00C4F84: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C4F88: 213c03ea                 sethi   %hi(aSCouldNotAddTo_0), %l0! "%s: could not add to cdevsw table at ma"...
F00C4F8C: 4000b239                 call    _objc_msgSend
F00C4F90: a01420d8                 bset    %lo(aSCouldNotAddTo_0), %l0! "%s: could not add to cdevsw table at ma"...
F00C4F94: 92100008                 mov     %o0, %o1
F00C4F98: 90100010                 mov     %l0, %o0! id
F00C4F9C: 40000456                 call    _IOLog
F00C4FA0: 9410001a                 mov     %i2, %o2
F00C4FA4: 10800006                 ba      locret_F00C4FBC
F00C4FA8: b0102000                 mov     0, %i0
F00C4FAC: d20261e4                 ld      [%o1+0x1E4], %o1! SEL
F00C4FB0: 4000b230                 call    _objc_msgSend
F00C4FB4: 90100018                 mov     %i0, %o0
F00C4FB8: b0102001                 mov     1, %i0
F00C4FBC: 81c7e008                 ret
F00C4FC0: 81e80000                 restore
