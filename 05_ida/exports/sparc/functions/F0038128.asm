F0038128: 9de3bf98                 save    %sp, -0x68, %sp
F003812C: 92100019                 mov     %i1, %o1
F0038130: 9410001a                 mov     %i2, %o2
F0038134: d0026008                 ld      [%o1+8], %o0
F0038138: b4102000                 mov     0, %i2
F003813C: 80a2a006                 cmp     %o2, 6
F0038140: 02800008                 be      loc_F0038160
F0038144: f2022020                 ld      [%o0+0x20], %i1
F0038148: 90100018                 mov     %i0, %o0
F003814C: 9610001b                 mov     %i3, %o3
F0038150: 7fffef3e                 call    _ip_ctloutput
F0038154: 9810001c                 mov     %i4, %o4
F0038158: 1080003a                 ba      locret_F0038240
F003815C: b0100008                 mov     %o0, %i0
F0038160: 80a62000                 cmp     %i0, 0
F0038164: 02800021                 be      loc_F00381E8
F0038168: 80a62001                 cmp     %i0, 1
F003816C: 32800035                 bne,a   locret_F0038240
F0038170: b010001a                 mov     %i2, %i0
F0038174: 80a6e001                 cmp     %i3, 1
F0038178: 12800014                 bne     loc_F00381C8
F003817C: d4070000                 ld      [%i4], %o2
F0038180: 80a2a000                 cmp     %o2, 0
F0038184: 22800013                 be,a    loc_F00381D0
F0038188: b4102016                 mov     0x16, %i2
F003818C: d012a008                 lduh    [%o2+8], %o0
F0038190: 80a22003                 cmp     %o0, 3
F0038194: 2880000e                 bleu,a  loc_F00381CC
F0038198: b4102016                 mov     0x16, %i2
F003819C: d002a004                 ld      [%o2+4], %o0
F00381A0: d0028008                 ld      [%o2+%o0], %o0
F00381A4: 80a22000                 cmp     %o0, 0
F00381A8: 02800005                 be      loc_F00381BC
F00381AC: d00e601b                 ldub    [%i1+0x1B], %o0
F00381B0: 90122004                 bset    4, %o0
F00381B4: 10800006                 ba      loc_F00381CC
F00381B8: d02e601b                 stb     %o0, [%i1+0x1B]
F00381BC: 900a20fb                 and     %o0, 0xFB, %o0
F00381C0: 10800003                 ba      loc_F00381CC
F00381C4: d02e601b                 stb     %o0, [%i1+0x1B]
F00381C8: b4102016                 mov     0x16, %i2
F00381CC: 80a2a000                 cmp     %o2, 0
F00381D0: 0280001c                 be      locret_F0038240
F00381D4: b010001a                 mov     %i2, %i0
F00381D8: 7fff9637                 call    _m_free
F00381DC: 9010000a                 mov     %o2, %o0
F00381E0: 10800018                 ba      locret_F0038240
F00381E4: b010001a                 mov     %i2, %i0
F00381E8: 90102001                 mov     1, %o0
F00381EC: 7fff95dc                 call    _m_get
F00381F0: 9210200a                 mov     0xA, %o1
F00381F4: 94100008                 mov     %o0, %o2
F00381F8: d4270000                 st      %o2, [%i4]
F00381FC: 90102004                 mov     4, %o0
F0038200: 80a6e001                 cmp     %i3, 1
F0038204: 02800007                 be      loc_F0038220
F0038208: d032a008                 sth     %o0, [%o2+8]
F003820C: 80a6e002                 cmp     %i3, 2
F0038210: 22800009                 be,a    loc_F0038234
F0038214: d202a004                 ld      [%o2+4], %o1
F0038218: 10800009                 ba      loc_F003823C
F003821C: b4102016                 mov     0x16, %i2
F0038220: d00e601b                 ldub    [%i1+0x1B], %o0
F0038224: d202a004                 ld      [%o2+4], %o1
F0038228: 900a2004                 and     %o0, 4, %o0
F003822C: 10800004                 ba      loc_F003823C
F0038230: d0228009                 st      %o0, [%o2+%o1]
F0038234: d0166018                 lduh    [%i1+0x18], %o0
F0038238: d0228009                 st      %o0, [%o2+%o1]
F003823C: b010001a                 mov     %i2, %i0
F0038240: 81c7e008                 ret
F0038244: 81e80000                 restore
