F001B0E8: 9de3bf98                 save    %sp, -0x68, %sp
F001B0EC: 4001eeb3                 call    _spltty
F001B0F0: a0100018                 mov     %i0, %l0
F001B0F4: 80a42000                 cmp     %l0, 0
F001B0F8: 12800005                 bne     loc_F001B10C
F001B0FC: a2100008                 mov     %o0, %l1
F001B100: 113c042e                 sethi   %hi(aTtynty0), %o0! "ttynty(0)"
F001B104: 7fffe81b                 call    _panic
F001B108: 901220c0                 bset    %lo(aTtynty0), %o0! "ttynty(0)"
F001B10C: 113c04bc                 sethi   %hi(dword_F012F200), %o0
F001B110: f0022200                 ld      [%o0+%lo(dword_F012F200)], %i0
F001B114: 80a62000                 cmp     %i0, 0
F001B118: 0280000c                 be      loc_F001B148
F001B11C: 92122200                 or      %o0, %lo(dword_F012F200), %o1
F001B120: d0060000                 ld      [%i0], %o0
F001B124: 80a20010                 cmp     %o0, %l0
F001B128: 02800008                 be      loc_F001B148
F001B12C: 80a62000                 cmp     %i0, 0
F001B130: 92062004                 add     %i0, 4, %o1
F001B134: f0062004                 ld      [%i0+4], %i0
F001B138: 80a62000                 cmp     %i0, 0
F001B13C: 32bffffa                 bne,a   loc_F001B124
F001B140: d0060000                 ld      [%i0], %o0
F001B144: 80a62000                 cmp     %i0, 0
F001B148: 02800005                 be      loc_F001B15C
F001B14C: 01000000                 nop
F001B150: d0062004                 ld      [%i0+4], %o0
F001B154: 10800010                 ba      loc_F001B194
F001B158: d0224000                 st      %o0, [%o1]
F001B15C: 400133c5                 call    _kalloc
F001B160: 90102018                 mov     0x18, %o0
F001B164: b0100008                 mov     %o0, %i0
F001B168: e0260000                 st      %l0, [%i0]
F001B16C: 110709469012221c         set     0x1C251A1C, %o0
F001B174: d0262010                 st      %o0, [%i0+0x10]
F001B178: 9010205c                 mov     0x5C, %o0 ! '\'
F001B17C: d02e2014                 stb     %o0, [%i0+0x14]
F001B180: 90102001                 mov     1, %o0
F001B184: d02e2015                 stb     %o0, [%i0+0x15]
F001B188: c02e2016                 clrb    [%i0+0x16]
F001B18C: c0262008                 clr     [%i0+8]
F001B190: c026200c                 clr     [%i0+0xC]
F001B194: 153c04bc                 sethi   %hi(dword_F012F200), %o2
F001B198: d202a200                 ld      [%o2+%lo(dword_F012F200)], %o1
F001B19C: 90100011                 mov     %l1, %o0
F001B1A0: d2262004                 st      %o1, [%i0+4]
F001B1A4: 4001eee0                 call    _splx
F001B1A8: f022a200                 st      %i0, [%o2+%lo(dword_F012F200)]
F001B1AC: 81c7e008                 ret
F001B1B0: 81e80000                 restore
