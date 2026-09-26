F00C0CDC: 9de3bf90                 save    %sp, -0x70, %sp! int
F00C0CE0: 94102000                 mov     0, %o2
F00C0CE4: 113c04fd92122280         set     _kbddata, %o1
F00C0CEC: d002601c                 ld      [%o1+0x1C], %o0
F00C0CF0: 80a20019                 cmp     %o0, %i1
F00C0CF4: 02800012                 be      loc_F00C0D3C
F00C0CF8: 9402a001                 inc     %o2
F00C0CFC: 80a2a003                 cmp     %o2, 3
F00C0D00: 04bffffb                 ble     loc_F00C0CEC
F00C0D04: 9202602c                 inc     0x2C, %o1 ! ','
F00C0D08: 94102000                 mov     0, %o2
F00C0D0C: 113c04fda2122280         set     _kbddata, %l1
F00C0D14: 92100011                 mov     %l1, %o1
F00C0D18: d002601c                 ld      [%o1+0x1C], %o0
F00C0D1C: 80a22000                 cmp     %o0, 0
F00C0D20: 02800009                 be      loc_F00C0D44
F00C0D24: 9402a001                 inc     %o2
F00C0D28: 80a2a003                 cmp     %o2, 3
F00C0D2C: 04bffffa                 ble     loc_F00C0D14
F00C0D30: a202602c                 add     %o1, 0x2C, %l1 ! ','
F00C0D34: 1080003a                 ba      locret_F00C0E1C
F00C0D38: b0102010                 mov     0x10, %i0
F00C0D3C: 10800038                 ba      locret_F00C0E1C
F00C0D40: b0102000                 mov     0, %i0
F00C0D44: 7fff9395                 call    _stop_mon_clock
F00C0D48: a12e2010                 sll     %i0, 16, %l0
F00C0D4C: 133c043e                 sethi   %hi(_hz), %o1
F00C0D50: 90102064                 mov     0x64, %o0 ! 'd'
F00C0D54: d02263e0                 st      %o0, [%o1+%lo(_hz)]
F00C0D58: a53c2010                 sra     %l0, 16, %l2
F00C0D5C: 90100012                 mov     %l2, %o0
F00C0D60: 7fffe277                 call    _zsopen
F00C0D64: 92102001                 mov     1, %o1
F00C0D68: 113c0483                 sethi   %hi(_kbddevopen), %o0
F00C0D6C: a8102001                 mov     1, %l4
F00C0D70: e8222228                 st      %l4, [%o0+%lo(_kbddevopen)]
F00C0D74: 90100012                 mov     %l2, %o0
F00C0D78: 1310019d92126008         set     0x40067408, %o1
F00C0D80: a607bff0                 add     %fp, var_10, %l3
F00C0D84: 94100013                 mov     %l3, %o2
F00C0D88: a1342018                 srl     %l0, 24, %l0
F00C0D8C: 972c2001                 sll     %l0, 1, %o3
F00C0D90: 9602c010                 add     %o3, %l0, %o3
F00C0D94: 972ae002                 sll     %o3, 2, %o3
F00C0D98: 9622c010                 sub     %o3, %l0, %o3
F00C0D9C: 972ae002                 sll     %o3, 2, %o3
F00C0DA0: 193c0472981321f0         set     _cdevsw, %o4
F00C0DA8: a002c00c                 add     %o3, %o4, %l0
F00C0DAC: d8042010                 ld      [%l0+0x10], %o4
F00C0DB0: 9fc30000                 call    %o4
F00C0DB4: 96102000                 mov     0, %o3
F00C0DB8: b0920000                 orcc    %o0, %g0, %i0
F00C0DBC: 12800018                 bne     locret_F00C0E1C
F00C0DC0: 90102020                 mov     0x20, %o0 ! ' '
F00C0DC4: d037bff4                 sth     %o0, [%fp+var_C]
F00C0DC8: 90102009                 mov     9, %o0
F00C0DCC: d02fbff1                 stb     %o0, [%fp+var_F]
F00C0DD0: d02fbff0                 stb     %o0, [%fp+var_10]
F00C0DD4: 90100012                 mov     %l2, %o0
F00C0DD8: 1320019d92126009         set     -0x7FF98BF7, %o1! int
F00C0DE0: 94100013                 mov     %l3, %o2! int
F00C0DE4: d8042010                 ld      [%l0+0x10], %o4! int
F00C0DE8: 9fc30000                 call    %o4
F00C0DEC: 96102000                 mov     0, %o3! int
F00C0DF0: b0920000                 orcc    %o0, %g0, %i0
F00C0DF4: 1280000a                 bne     locret_F00C0E1C
F00C0DF8: 90102003                 mov     3, %o0! int
F00C0DFC: f224601c                 st      %i1, [%l1+0x1C]
F00C0E00: e8246018                 st      %l4, [%l1+0x18]
F00C0E04: 4000004c                 call    _kbd_setwrite
F00C0E08: d0246014                 st      %o0, [%l1+0x14]
F00C0E0C: 40000070                 call    _kbdreset
F00C0E10: 90100019                 mov     %i1, %o0
F00C0E14: 4000057b                 call    _sunmouse_init
F00C0E18: 01000000                 nop
F00C0E1C: 81c7e008                 ret
F00C0E20: 81e80000                 restore
