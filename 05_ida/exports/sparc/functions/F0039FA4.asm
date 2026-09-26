F0039FA4: 9de3bf68                 save    %sp, -0x98, %sp! int
F0039FA8: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0039FAC: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0039FB0: e4022024                 ld      [%o0+0x24], %l2
F0039FB4: 7fff566e                 call    _suser
F0039FB8: a6102000                 mov     0, %l3
F0039FBC: 80a22000                 cmp     %o0, 0
F0039FC0: 32800006                 bne,a   loc_F0039FD8
F0039FC4: d0048000                 ld      [%l2], %o0
F0039FC8: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0039FCC: 90102001                 mov     1, %o0
F0039FD0: 10800065                 ba      locret_F003A164
F0039FD4: d02a6038                 stb     %o0, [%o1+0x38]
F0039FD8: 80a220ff                 cmp     %o0, 0xFF
F0039FDC: 18800013                 bgu     loc_F003A028
F0039FE0: 92102000                 mov     0, %o1
F0039FE4: 7fff4528                 call    _getf
F0039FE8: a6102001                 mov     1, %l3
F0039FEC: 94920000                 orcc    %o0, %g0, %o2
F0039FF0: 02800007                 be      loc_F003A00C
F0039FF4: 113c0430                 sethi   %hi(_vnodefops), %o0
F0039FF8: d202a014                 ld      [%o2+0x14], %o1
F0039FFC: 901220b0                 bset    %lo(_vnodefops), %o0
F003A000: 80a24008                 cmp     %o1, %o0
F003A004: 22800006                 be,a    loc_F003A01C
F003A008: d002a018                 ld      [%o2+0x18], %o0
F003A00C: d20421dc                 ld      [%l0+0x1DC], %o1
F003A010: 90102016                 mov     0x16, %o0
F003A014: 10800054                 ba      locret_F003A164
F003A018: d02a6038                 stb     %o0, [%o1+0x38]
F003A01C: c027bfd4                 clr     [%fp+var_2C]
F003A020: 1080002f                 ba      loc_F003A0DC
F003A024: d027bfd0                 st      %o0, [%fp+var_30]
F003A028: 94102001                 mov     1, %o2
F003A02C: 9607bfd4                 add     %fp, var_2C, %o3
F003A030: a207bfd0                 add     %fp, var_30, %l1
F003A034: 7fffb264                 call    _lookupname
F003A038: 98100011                 mov     %l1, %o4
F003A03C: d20421dc                 ld      [%l0+0x1DC], %o1
F003A040: d02a6038                 stb     %o0, [%o1+0x38]
F003A044: d00421dc                 ld      [%l0+0x1DC], %o0
F003A048: d04a2038                 ldsb    [%o0+0x38], %o0
F003A04C: 80a22011                 cmp     %o0, 0x11
F003A050: 1280000c                 bne     loc_F003A080
F003A054: d00421dc                 ld      [%l0+0x1DC], %o0
F003A058: 92102000                 mov     0, %o1
F003A05C: 94102001                 mov     1, %o2
F003A060: 96102000                 mov     0, %o3! int
F003A064: d0048000                 ld      [%l2], %o0
F003A068: 7fffb257                 call    _lookupname
F003A06C: 98100011                 mov     %l1, %o4! int
F003A070: d20421dc                 ld      [%l0+0x1DC], %o1
F003A074: d02a6038                 stb     %o0, [%o1+0x38]
F003A078: c027bfd4                 clr     [%fp+var_2C]
F003A07C: d00421dc                 ld      [%l0+0x1DC], %o0
F003A080: d04a2038                 ldsb    [%o0+0x38], %o0
F003A084: 80a22000                 cmp     %o0, 0
F003A088: 12800010                 bne     loc_F003A0C8
F003A08C: 113c04cf                 sethi   -0xFECC400, %o0
F003A090: d007bfd0                 ld      [%fp+var_30], %o0
F003A094: 80a22000                 cmp     %o0, 0
F003A098: 1280000c                 bne     loc_F003A0C8
F003A09C: 113c04cf                 sethi   -0xFECC400, %o0
F003A0A0: d007bfd4                 ld      [%fp+var_2C], %o0
F003A0A4: 80a22000                 cmp     %o0, 0
F003A0A8: 02800005                 be      loc_F003A0BC
F003A0AC: d20421dc                 ld      [%l0+0x1DC], %o1
F003A0B0: 7fffbaad                 call    _vn_rele
F003A0B4: 01000000                 nop
F003A0B8: d20421dc                 ld      [%l0+0x1DC], %o1
F003A0BC: 90102002                 mov     2, %o0
F003A0C0: d02a6038                 stb     %o0, [%o1+0x38]
F003A0C4: 113c04cf                 sethi   -0xFECC400, %o0
F003A0C8: d00221dc                 ld      [%o0+0x1DC], %o0
F003A0CC: d04a2038                 ldsb    [%o0+0x38], %o0
F003A0D0: 80a22000                 cmp     %o0, 0
F003A0D4: 12800024                 bne     locret_F003A164
F003A0D8: 01000000                 nop
F003A0DC: d207bfd4                 ld      [%fp+var_2C], %o1
F003A0E0: d407bfd0                 ld      [%fp+var_30], %o2
F003A0E4: 40000022                 call    _findexivp
F003A0E8: 9007bfcc                 add     %fp, var_34, %o0
F003A0EC: a0920000                 orcc    %o0, %g0, %l0
F003A0F0: 12800010                 bne     loc_F003A130
F003A0F4: 80a4e000                 cmp     %l3, 0
F003A0F8: d207bfd0                 ld      [%fp+var_30], %o1
F003A0FC: a207bfd8                 add     %fp, var_28, %l1
F003A100: d407bfcc                 ld      [%fp+var_34], %o2! int
F003A104: 4000005e                 call    _makefh
F003A108: 90100011                 mov     %l1, %o0
F003A10C: a0920000                 orcc    %o0, %g0, %l0
F003A110: 12800008                 bne     loc_F003A130
F003A114: 80a4e000                 cmp     %l3, 0
F003A118: 90100011                 mov     %l1, %o0! int
F003A11C: d204a004                 ld      [%l2+4], %o1! int
F003A120: 400177eb                 call    _copyout
F003A124: 94102020                 mov     0x20, %o2 ! ' '
F003A128: a0100008                 mov     %o0, %l0
F003A12C: 80a4e000                 cmp     %l3, 0
F003A130: 1280000b                 bne     loc_F003A15C
F003A134: 113c04cf                 sethi   -0xFECC400, %o0
F003A138: 7fffba8b                 call    _vn_rele
F003A13C: d007bfd0                 ld      [%fp+var_30], %o0
F003A140: d007bfd4                 ld      [%fp+var_2C], %o0
F003A144: 80a22000                 cmp     %o0, 0
F003A148: 22800005                 be,a    loc_F003A15C
F003A14C: 113c04cf                 sethi   -0xFECC400, %o0
F003A150: 7fffba85                 call    _vn_rele
F003A154: 01000000                 nop
F003A158: 113c04cf                 sethi   -0xFECC400, %o0
F003A15C: d00221dc                 ld      [%o0+0x1DC], %o0
F003A160: e02a2038                 stb     %l0, [%o0+0x38]
F003A164: 81c7e008                 ret
F003A168: 81e80000                 restore
