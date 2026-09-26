F00180AC: 9de3bf98                 save    %sp, -0x68, %sp
F00180B0: 40000c0e                 call    _ttynty
F00180B4: 90100019                 mov     %i1, %o0
F00180B8: a0100008                 mov     %o0, %l0
F00180BC: d0042010                 ld      [%l0+0x10], %o0
F00180C0: 808a2800                 btst    0x800, %o0
F00180C4: 0280006e                 be      locret_F001827C
F00180C8: 11080000                 sethi   0x20000000, %o0
F00180CC: d206603c                 ld      [%i1+0x3C], %o1
F00180D0: 808a4008                 btst    %o0, %o1
F00180D4: 02800005                 be      loc_F00180E8
F00180D8: 113c04d0                 sethi   -0xFECC000, %o0
F00180DC: 7fffffd5                 call    _ttypend
F00180E0: 90100019                 mov     %i1, %o0
F00180E4: 113c04d0                 sethi   -0xFECC000, %o0
F00180E8: d2022218                 ld      [%o0+0x218], %o1
F00180EC: 153fc000                 sethi   -0x1000000, %o2
F00180F0: 808e000a                 btst    %o2, %i0
F00180F4: 92026001                 inc     %o1
F00180F8: 12800039                 bne     loc_F00181DC
F00180FC: d2222218                 st      %o1, [%o0+0x218]
F0018100: d006603c                 ld      [%i1+0x3C], %o0
F0018104: 808a2020                 btst    0x20, %o0 ! ' '
F0018108: 02800036                 be      loc_F00181E0
F001810C: 90100018                 mov     %i0, %o0
F0018110: d0064000                 ld      [%i1], %o0
F0018114: 80a22400                 cmp     %o0, 0x400
F0018118: 0480000a                 ble     loc_F0018140
F001811C: 90102004                 mov     4, %o0! __x
F0018120: 133c042d                 sethi   %hi(aTtyDRawInputOv), %o1! "tty%d: raw input overrun\n"
F0018124: d4566038                 ldsh    [%i1+0x38], %o2
F0018128: 7ffff1a3                 call    _log
F001812C: 921263f8                 bset    %lo(aTtyDRawInputOv), %o1! "tty%d: raw input overrun\n"
F0018130: 4000091d                 call    _ttwakeup
F0018134: 90100019                 mov     %i1, %o0
F0018138: 10800013                 ba      loc_F0018184
F001813C: d006603c                 ld      [%i1+0x3C], %o0
F0018140: 90100018                 mov     %i0, %o0! int
F0018144: 40001283                 call    _putc
F0018148: 92100019                 mov     %i1, %o1
F001814C: 80a22000                 cmp     %o0, 0
F0018150: 2680000d                 bl,a    loc_F0018184
F0018154: d006603c                 ld      [%i1+0x3C], %o0
F0018158: 40000902                 call    _ttcheckwakeup
F001815C: 90100010                 mov     %l0, %o0
F0018160: 80a22000                 cmp     %o0, 0
F0018164: 02800005                 be      loc_F0018178
F0018168: 90100018                 mov     %i0, %o0
F001816C: 4000090e                 call    _ttwakeup
F0018170: 90100019                 mov     %i1, %o0
F0018174: 90100018                 mov     %i0, %o0
F0018178: 4000089f                 call    _ttyecho
F001817C: 92100010                 mov     %l0, %o1
F0018180: d006603c                 ld      [%i1+0x3C], %o0
F0018184: 13002000                 sethi   0x800000, %o1
F0018188: 922a0009                 andn    %o0, %o1, %o1
F001818C: d226603c                 st      %o1, [%i1+0x3C]
F0018190: d0042010                 ld      [%l0+0x10], %o0
F0018194: 808a2010                 btst    0x10, %o0
F0018198: 02800014                 be      loc_F00181E8
F001819C: 11100000                 sethi   0x40000000, %o0
F00181A0: 808a4008                 btst    %o0, %o1
F00181A4: 2280000b                 be,a    loc_F00181D0
F00181A8: d0066040                 ld      [%i1+0x40], %o0
F00181AC: d20e6052                 ldub    [%i1+0x52], %o1
F00181B0: 80a260ff                 cmp     %o1, 0xFF
F00181B4: 2280000e                 be,a    loc_F00181EC
F00181B8: d0064000                 ld      [%i1], %o0
F00181BC: d00e6051                 ldub    [%i1+0x51], %o0
F00181C0: 80a24008                 cmp     %o1, %o0
F00181C4: 3280000a                 bne,a   loc_F00181EC
F00181C8: d0064000                 ld      [%i1], %o0
F00181CC: d0066040                 ld      [%i1+0x40], %o0
F00181D0: 900a3eff                 and     %o0, -0x101, %o0
F00181D4: 10800005                 ba      loc_F00181E8
F00181D8: d0266040                 st      %o0, [%i1+0x40]
F00181DC: 90100018                 mov     %i0, %o0
F00181E0: 400000ad                 call    _ttcooked
F00181E4: 92100010                 mov     %l0, %o1
F00181E8: d0064000                 ld      [%i1], %o0
F00181EC: d206600c                 ld      [%i1+0xC], %o1! FILE *
F00181F0: 90020009                 add     %o0, %o1, %o0
F00181F4: 80a221ff                 cmp     %o0, 0x1FF
F00181F8: 0480001f                 ble     loc_F0018274
F00181FC: 01000000                 nop
F0018200: d006603c                 ld      [%i1+0x3C], %o0
F0018204: 808a2022                 btst    0x22, %o0 ! '"'
F0018208: 12800005                 bne     loc_F001821C
F001820C: 808a2001                 btst    1, %o0
F0018210: 80a26000                 cmp     %o1, 0
F0018214: 04800018                 ble     loc_F0018274
F0018218: 808a2001                 btst    1, %o0
F001821C: 22800013                 be,a    loc_F0018268
F0018220: d0066040                 ld      [%i1+0x40], %o0
F0018224: d00e6052                 ldub    [%i1+0x52], %o0
F0018228: 80a220ff                 cmp     %o0, 0xFF
F001822C: 2280000f                 be,a    loc_F0018268
F0018230: d0066040                 ld      [%i1+0x40], %o0
F0018234: 912a2018                 sll     %o0, 24, %o0
F0018238: 913a2018                 sra     %o0, 24, %o0! int
F001823C: 40001245                 call    _putc
F0018240: 92066018                 add     %i1, 0x18, %o1
F0018244: 80a22000                 cmp     %o0, 0
F0018248: 32800008                 bne,a   loc_F0018268
F001824C: d0066040                 ld      [%i1+0x40], %o0
F0018250: d2066040                 ld      [%i1+0x40], %o1
F0018254: 90100019                 mov     %i1, %o0
F0018258: 92126400                 bset    0x400, %o1
F001825C: 7ffffa47                 call    _ttstart
F0018260: d2266040                 st      %o1, [%i1+0x40]
F0018264: d0066040                 ld      [%i1+0x40], %o0
F0018268: 13002000                 sethi   0x800000, %o1
F001826C: 90120009                 bset    %o1, %o0
F0018270: d0266040                 st      %o0, [%i1+0x40]
F0018274: 7ffffa41                 call    _ttstart
F0018278: 90100019                 mov     %i1, %o0
F001827C: 81c7e008                 ret
F0018280: 81e80000                 restore
