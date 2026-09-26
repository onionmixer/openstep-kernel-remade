F00B1C90: 9de3be88                 save    %sp, -0x178, %sp
F00B1C94: 90103fff                 mov     -1, %o0
F00B1C98: d027bfe8                 st      %o0, [%fp+var_18]
F00B1C9C: 90103fff                 mov     -1, %o0
F00B1CA0: d037bfec                 sth     %o0, [%fp+var_14]
F00B1CA4: 7ffff974                 call    _prom_stdin_stdout_equivalence
F00B1CA8: c027bff0                 clr     [%fp+var_10]
F00B1CAC: 80a22000                 cmp     %o0, 0
F00B1CB0: 02800026                 be      loc_F00B1D48
F00B1CB4: a007bee8                 add     %fp, var_118, %l0
F00B1CB8: 90100010                 mov     %l0, %o0
F00B1CBC: 7ffff864                 call    _prom_get_stdin_dev_name
F00B1CC0: 92102100                 mov     0x100, %o1! __s2
F00B1CC4: 80a22000                 cmp     %o0, 0
F00B1CC8: 12800021                 bne     loc_F00B1D4C
F00B1CCC: 113c04fb                 sethi   -0xFEC1400, %o0
F00B1CD0: 113c047490122158         set     unk_F011D158, %o0! __s1
F00B1CD8: 7ffd5935                 call    _strcmp
F00B1CDC: 92100010                 mov     %l0, %o1
F00B1CE0: 80a22000                 cmp     %o0, 0
F00B1CE4: 1280001a                 bne     loc_F00B1D4C
F00B1CE8: 113c04fb                 sethi   -0xFEC1400, %o0
F00B1CEC: 7ffff8b6                 call    _prom_get_stdin_unit
F00B1CF0: 01000000                 nop
F00B1CF4: a2100008                 mov     %o0, %l1
F00B1CF8: 80a47fff                 cmp     %l1, -1
F00B1CFC: 02800014                 be      loc_F00B1D4C
F00B1D00: 113c04fb                 sethi   -0xFEC1400, %o0
F00B1D04: 7ffff908                 call    _prom_get_stdin_subunit
F00B1D08: a0102000                 mov     0, %l0
F00B1D0C: 80a22000                 cmp     %o0, 0
F00B1D10: 22800008                 be,a    loc_F00B1D30
F00B1D14: 912c6001                 sll     %l1, 1, %o0
F00B1D18: d04a0000                 ldsb    [%o0], %o0
F00B1D1C: 80a22000                 cmp     %o0, 0
F00B1D20: 02800003                 be      loc_F00B1D2C
F00B1D24: 90023f9f                 inc     -0x61, %o0
F00B1D28: a00a2001                 and     %o0, 1, %l0
F00B1D2C: 912c6001                 sll     %l1, 1, %o0
F00B1D30: a0040008                 add     %l0, %o0, %l0
F00B1D34: 1100000990122200         set     0x2600, %o0
F00B1D3C: 90140008                 bset    %l0, %o0
F00B1D40: 133c04fb                 sethi   %hi(_rconsdev), %o1
F00B1D44: d0326248                 sth     %o0, [%o1+%lo(_rconsdev)]
F00B1D48: 113c04fb                 sethi   -0xFEC1400, %o0
F00B1D4C: d0522248                 ldsh    [%o0+0x248], %o0
F00B1D50: 80a22000                 cmp     %o0, 0
F00B1D54: 02800011                 be      loc_F00B1D98
F00B1D58: 92100008                 mov     %o0, %o1
F00B1D5C: 113c0483                 sethi   %hi(_kbddev), %o0
F00B1D60: d2322224                 sth     %o1, [%o0+%lo(_kbddev)]
F00B1D64: 113c04fb                 sethi   %hi(_consdev), %o0
F00B1D68: d2322230                 sth     %o1, [%o0+%lo(_consdev)]
F00B1D6C: 133c02c792126344         set     _findcons, %o1
F00B1D74: 113c04fb                 sethi   %hi(_top_devinfo), %o0
F00B1D78: d0022088                 ld      [%o0+%lo(_top_devinfo)], %o0
F00B1D7C: 7ffffbd1                 call    _walk_devs
F00B1D80: 9407bfe8                 add     %fp, var_18, %o2
F00B1D84: d007bff0                 ld      [%fp+var_10], %o0
F00B1D88: 133c04fb                 sethi   %hi(_options_devinfo), %o1
F00B1D8C: 400000af                 call    _set_keyclick
F00B1D90: d0226228                 st      %o0, [%o1+%lo(_options_devinfo)]
F00B1D94: 3080006a                 ba,a    locret_F00B1F3C
F00B1D98: 7ffff540                 call    _prom_stdin_is_keyboard
F00B1D9C: 01000000                 nop
F00B1DA0: 80a22000                 cmp     %o0, 0
F00B1DA4: 12800028                 bne     loc_F00B1E44
F00B1DA8: 213c0483                 sethi   -0xFEDF400, %l0
F00B1DAC: a007bee8                 add     %fp, var_118, %l0
F00B1DB0: 90100010                 mov     %l0, %o0
F00B1DB4: 7ffff826                 call    _prom_get_stdin_dev_name
F00B1DB8: 92102100                 mov     0x100, %o1! __s2
F00B1DBC: 80a22000                 cmp     %o0, 0
F00B1DC0: 32800021                 bne,a   loc_F00B1E44
F00B1DC4: 213c0483                 sethi   -0xFEDF400, %l0
F00B1DC8: 113c047490122160         set     unk_F011D160, %o0! __s1
F00B1DD0: 7ffd58f7                 call    _strcmp
F00B1DD4: 92100010                 mov     %l0, %o1
F00B1DD8: 80a22000                 cmp     %o0, 0
F00B1DDC: 1280001a                 bne     loc_F00B1E44
F00B1DE0: 213c0483                 sethi   %hi(_kbddev), %l0
F00B1DE4: 7ffff878                 call    _prom_get_stdin_unit
F00B1DE8: 01000000                 nop
F00B1DEC: a2100008                 mov     %o0, %l1
F00B1DF0: 80a47fff                 cmp     %l1, -1
F00B1DF4: 02800015                 be      loc_F00B1E48
F00B1DF8: d0542224                 ldsh    [%l0+%lo(_kbddev)], %o0
F00B1DFC: 7ffff8ca                 call    _prom_get_stdin_subunit
F00B1E00: a0102000                 mov     0, %l0
F00B1E04: 80a22000                 cmp     %o0, 0
F00B1E08: 22800008                 be,a    loc_F00B1E28
F00B1E0C: 912c6001                 sll     %l1, 1, %o0
F00B1E10: d04a0000                 ldsb    [%o0], %o0
F00B1E14: 80a22000                 cmp     %o0, 0
F00B1E18: 02800003                 be      loc_F00B1E24
F00B1E1C: 90023f9f                 inc     -0x61, %o0
F00B1E20: a00a2001                 and     %o0, 1, %l0
F00B1E24: 912c6001                 sll     %l1, 1, %o0
F00B1E28: a0040008                 add     %l0, %o0, %l0
F00B1E2C: 1100000990122200         set     0x2600, %o0
F00B1E34: 90140008                 bset    %l0, %o0
F00B1E38: 133c0483                 sethi   %hi(_kbddev), %o1
F00B1E3C: d0326224                 sth     %o0, [%o1+%lo(_kbddev)]
F00B1E40: 213c0483                 sethi   -0xFEDF400, %l0
F00B1E44: d0542224                 ldsh    [%l0+0x224], %o0
F00B1E48: 80a23fff                 cmp     %o0, -1
F00B1E4C: 02800005                 be      loc_F00B1E60
F00B1E50: 133c02c7                 sethi   -0xFF4E400, %o1
F00B1E54: 40001e15                 call    _zsgetspeed
F00B1E58: 01000000                 nop
F00B1E5C: 133c02c7                 sethi   -0xFF4E400, %o1
F00B1E60: 92126344                 bset    0x344, %o1
F00B1E64: 113c04fb                 sethi   %hi(_top_devinfo), %o0
F00B1E68: d0022088                 ld      [%o0+%lo(_top_devinfo)], %o0
F00B1E6C: 7ffffb95                 call    _walk_devs
F00B1E70: 9407bfe8                 add     %fp, var_18, %o2
F00B1E74: d007bff0                 ld      [%fp+var_10], %o0
F00B1E78: 133c04fb                 sethi   %hi(_options_devinfo), %o1
F00B1E7C: 40000073                 call    _set_keyclick
F00B1E80: d0226228                 st      %o0, [%o1+%lo(_options_devinfo)]
F00B1E84: d407bfe8                 ld      [%fp+var_18], %o2
F00B1E88: 80a2bfff                 cmp     %o2, -1
F00B1E8C: 02800015                 be      loc_F00B1EE0
F00B1E90: 173c04fb                 sethi   %hi(_mousedev), %o3
F00B1E94: d052e240                 ldsh    [%o3+%lo(_mousedev)], %o0
F00B1E98: 80a23fff                 cmp     %o0, -1
F00B1E9C: 12800009                 bne     loc_F00B1EC0
F00B1EA0: d0542224                 ldsh    [%l0+0x224], %o0
F00B1EA4: 932aa001                 sll     %o2, 1, %o1
F00B1EA8: 92026001                 inc     %o1
F00B1EAC: 1100000990122200         set     0x2600, %o0
F00B1EB4: 92124008                 bset    %o0, %o1
F00B1EB8: d232e240                 sth     %o1, [%o3+%lo(_mousedev)]
F00B1EBC: d0542224                 ldsh    [%l0+0x224], %o0
F00B1EC0: 80a23fff                 cmp     %o0, -1
F00B1EC4: 32800008                 bne,a   loc_F00B1EE4
F00B1EC8: 213c0483                 sethi   -0xFEDF400, %l0
F00B1ECC: 932aa001                 sll     %o2, 1, %o1
F00B1ED0: 1100000990122200         set     0x2600, %o0
F00B1ED8: 92124008                 bset    %o0, %o1
F00B1EDC: d2342224                 sth     %o1, [%l0+0x224]
F00B1EE0: 213c0483                 sethi   -0xFEDF400, %l0
F00B1EE4: d0542224                 ldsh    [%l0+0x224], %o0
F00B1EE8: 80a23fff                 cmp     %o0, -1
F00B1EEC: 12800006                 bne     loc_F00B1F04
F00B1EF0: 133c0483                 sethi   -0xFEDF400, %o1
F00B1EF4: 113c0474                 sethi   %hi(aNoKeyboardFoun), %o0! "no keyboard found"
F00B1EF8: 7ffd8c9e                 call    _panic
F00B1EFC: 90122168                 bset    %lo(aNoKeyboardFoun), %o0! "no keyboard found"
F00B1F00: 133c0483                 sethi   -0xFEDF400, %o1
F00B1F04: 153c04fb                 sethi   %hi(_fbdev), %o2
F00B1F08: d052a238                 ldsh    [%o2+%lo(_fbdev)], %o0
F00B1F0C: 80a23fff                 cmp     %o0, -1
F00B1F10: 12800004                 bne     loc_F00B1F20
F00B1F14: c0226228                 clr     [%o1+0x228]
F00B1F18: d017bfec                 lduh    [%fp+var_14], %o0
F00B1F1C: d032a238                 sth     %o0, [%o2+%lo(_fbdev)]
F00B1F20: d0142224                 lduh    [%l0+0x224], %o0
F00B1F24: 133c04fb                 sethi   %hi(_rconsdev), %o1
F00B1F28: 900a20ff                 and     %o0, 0xFF, %o0
F00B1F2C: 90122c00                 bset    0xC00, %o0
F00B1F30: d0326248                 sth     %o0, [%o1+%lo(_rconsdev)]
F00B1F34: 133c04fb                 sethi   %hi(_consdev), %o1
F00B1F38: d0326230                 sth     %o0, [%o1+%lo(_consdev)]
F00B1F3C: 81c7e008                 ret
F00B1F40: 81e80000                 restore
