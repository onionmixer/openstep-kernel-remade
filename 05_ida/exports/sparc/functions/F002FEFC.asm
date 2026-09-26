F002FEFC: 9de3bf48                 save    %sp, -0xB8, %sp
F002FF00: f027a044                 st      %i0, [%fp+arg_44]
F002FF04: f227a048                 st      %i1, [%fp+arg_48]
F002FF08: f427a04c                 st      %i2, [%fp+arg_4C]
F002FF0C: f627a050                 st      %i3, [%fp+arg_50]
F002FF10: f827a054                 st      %i4, [%fp+arg_54]
F002FF14: fa27a058                 st      %i5, [%fp+arg_58]
F002FF18: b406a108                 inc     0x108, %i2
F002FF1C: f427bfb8                 st      %i2, [%fp+var_48]
F002FF20: b606e0ec                 inc     0xEC, %i3
F002FF24: f627bfb4                 st      %i3, [%fp+var_4C]
F002FF28: c027bfb0                 clr     [%fp+var_50]
F002FF2C: c027bfac                 clr     [%fp+var_54]
F002FF30: 4000f9a8                 call    _microtime
F002FF34: 9007bff0                 add     %fp, var_10, %o0
F002FF38: d007a054                 ld      [%fp+arg_54], %o0
F002FF3C: d207bff0                 ld      [%fp+var_10], %o1
F002FF40: d00a2005                 ldub    [%o0+5], %o0
F002FF44: 901a0009                 btog    %o1, %o0
F002FF48: d027bfc8                 st      %o0, [%fp+var_38]
F002FF4C: c027bfc0                 clr     [%fp+var_40]
F002FF50: d207a04c                 ld      [%fp+arg_4C], %o1
F002FF54: c027bfbc                 clr     [%fp+var_44]
F002FF58: d0226020                 st      %o0, [%o1+0x20]
F002FF5C: 90102002                 mov     2, %o0
F002FF60: d037bfd8                 sth     %o0, [%fp+var_28]
F002FF64: 90102043                 mov     0x43, %o0 ! 'C'
F002FF68: d037bfda                 sth     %o0, [%fp+var_26]
F002FF6C: 90103fff                 mov     -1, %o0
F002FF70: d027bfdc                 st      %o0, [%fp+var_24]
F002FF74: 90102001                 mov     1, %o0
F002FF78: d027bfc4                 st      %o0, [%fp+var_3C]
F002FF7C: d007bfc0                 ld      [%fp+var_40], %o0
F002FF80: 80a22000                 cmp     %o0, 0
F002FF84: 1280000c                 bne     loc_F002FFB4
F002FF88: 113c04cf                 sethi   -0xFECC400, %o0
F002FF8C: 7fffff4e                 call    _in_bootp_bptombuf
F002FF90: d007a04c                 ld      [%fp+arg_4C], %o0
F002FF94: d027bfcc                 st      %o0, [%fp+var_34]
F002FF98: 92100008                 mov     %o0, %o1
F002FF9C: d007a044                 ld      [%fp+arg_44], %o0
F002FFA0: 7ffff0ca                 call    _if_output_mbuf
F002FFA4: 9407bfd8                 add     %fp, var_28, %o2
F002FFA8: b0920000                 orcc    %o0, %g0, %i0
F002FFAC: 128000a5                 bne     loc_F0030240
F002FFB0: 113c04cf                 sethi   -0xFECC400, %o0
F002FFB4: d00221dc                 ld      [%o0+0x1DC], %o0
F002FFB8: d2022028                 ld      [%o0+0x28], %o1
F002FFBC: d227bfe8                 st      %o1, [%fp+var_18]
F002FFC0: d202202c                 ld      [%o0+0x2C], %o1
F002FFC4: 90022028                 inc     0x28, %o0 ! '('! jmp_buf
F002FFC8: 40019b63                 call    _setjmp
F002FFCC: d227bfec                 st      %o1, [%fp+var_14]
F002FFD0: 80a22000                 cmp     %o0, 0
F002FFD4: 02800009                 be      loc_F002FFF8
F002FFD8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F002FFDC: 113c00bf                 sethi   %hi(sub_F002FE88), %o0
F002FFE0: d60261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o3
F002FFE4: 90122288                 bset    %lo(sub_F002FE88), %o0
F002FFE8: d407bfe8                 ld      [%fp+var_18], %o2
F002FFEC: b0102004                 mov     4, %i0
F002FFF0: 10800025                 ba      loc_F0030084
F002FFF4: d422e028                 st      %o2, [%o3+0x28]
F002FFF8: 113c00bf90122288         set     sub_F002FE88, %o0! int
F0030000: 9207bfd4                 add     %fp, var_2C, %o1
F0030004: d607a048                 ld      [%fp+arg_48], %o3
F0030008: 153c043e                 sethi   %hi(_hz), %o2
F003000C: d402a3e0                 ld      [%o2+%lo(_hz)], %o2
F0030010: d627bfd4                 st      %o3, [%fp+var_2C]
F0030014: 7fff6805                 call    _timeout
F0030018: 01000000                 nop
F003001C: d007a048                 ld      [%fp+arg_48], %o0
F0030020: d207a050                 ld      [%fp+arg_50], %o1
F0030024: 7fffffa4                 call    sub_F002FEB4
F0030028: 9410212c                 mov     0x12C, %o2
F003002C: b0100008                 mov     %o0, %i0
F0030030: 80a62023                 cmp     %i0, 0x23 ! '#'
F0030034: 1280000a                 bne     loc_F003005C
F0030038: d207bfd4                 ld      [%fp+var_2C], %o1
F003003C: d007a048                 ld      [%fp+arg_48], %o0
F0030040: 80a24008                 cmp     %o1, %o0
F0030044: 12800007                 bne     loc_F0030060
F0030048: 80a62000                 cmp     %i0, 0
F003004C: 7fffc0c5                 call    _sbwait
F0030050: 90026024                 add     %o1, 0x24, %o0 ! '$'
F0030054: 10bffff3                 ba      loc_F0030020
F0030058: d007a048                 ld      [%fp+arg_48], %o0
F003005C: 80a62000                 cmp     %i0, 0
F0030060: 0280000f                 be      loc_F003009C
F0030064: 80a62023                 cmp     %i0, 0x23 ! '#'
F0030068: 0280000d                 be      loc_F003009C
F003006C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0030070: d60221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o3
F0030074: d207bfe8                 ld      [%fp+var_18], %o1
F0030078: 113c00bf90122288         set     sub_F002FE88, %o0
F0030080: d222e028                 st      %o1, [%o3+0x28]
F0030084: d407bfec                 ld      [%fp+var_14], %o2
F0030088: 9207bfd4                 add     %fp, var_2C, %o1
F003008C: 7fff67f2                 call    _untimeout
F0030090: d422e02c                 st      %o2, [%o3+0x2C]
F0030094: 1080006c                 ba      loc_F0030244
F0030098: 113c00bf                 sethi   -0xFFD0400, %o0
F003009C: d007bfd4                 ld      [%fp+var_2C], %o0
F00300A0: 80a22000                 cmp     %o0, 0
F00300A4: 1280002a                 bne     loc_F003014C
F00300A8: d407a050                 ld      [%fp+arg_50], %o2
F00300AC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00300B0: d40221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o2! size_t
F00300B4: d207bfc0                 ld      [%fp+var_40], %o1
F00300B8: d007bfe8                 ld      [%fp+var_18], %o0
F00300BC: 96026001                 add     %o1, 1, %o3
F00300C0: d022a028                 st      %o0, [%o2+0x28]
F00300C4: d007bfbc                 ld      [%fp+var_44], %o0
F00300C8: d627bfc0                 st      %o3, [%fp+var_40]
F00300CC: d207bfc4                 ld      [%fp+var_3C], %o1
F00300D0: 90022001                 inc     %o0
F00300D4: d027bfbc                 st      %o0, [%fp+var_44]
F00300D8: d007bfec                 ld      [%fp+var_14], %o0
F00300DC: 80a2c009                 cmp     %o3, %o1
F00300E0: 12800008                 bne     loc_F0030100
F00300E4: d022a02c                 st      %o0, [%o2+0x2C]
F00300E8: 80a2e03f                 cmp     %o3, 0x3F ! '?'
F00300EC: 34800005                 bg,a    loc_F0030100
F00300F0: c027bfc0                 clr     [%fp+var_40]
F00300F4: 912ae001                 sll     %o3, 1, %o0
F00300F8: d027bfc4                 st      %o0, [%fp+var_3C]
F00300FC: c027bfc0                 clr     [%fp+var_40]
F0030100: d007bfbc                 ld      [%fp+var_44], %o0
F0030104: 80a22014                 cmp     %o0, 0x14
F0030108: 12bfff9e                 bne     loc_F002FF80
F003010C: d007bfc0                 ld      [%fp+var_40], %o0
F0030110: d207a058                 ld      [%fp+arg_58], %o1
F0030114: d0024000                 ld      [%o1], %o0
F0030118: 80a22000                 cmp     %o0, 0
F003011C: 12800007                 bne     loc_F0030138
F0030120: 113c0431                 sethi   -0xFEF3C00, %o0
F0030124: 4000004d                 call    sub_F0030258
F0030128: 90100009                 mov     %o1, %o0
F003012C: b0920000                 orcc    %o0, %g0, %i0
F0030130: 12800044                 bne     loc_F0030240
F0030134: 113c0431                 sethi   -0xFEF3C00, %o0! char *
F0030138: 7fff9148                 call    _printf
F003013C: 901220e0                 bset    0xE0, %o0
F0030140: 90102001                 mov     1, %o0
F0030144: 10bfff8e                 ba      loc_F002FF7C
F0030148: d027bfb0                 st      %o0, [%fp+var_50]
F003014C: d007bfc8                 ld      [%fp+var_38], %o0
F0030150: d202a004                 ld      [%o2+4], %o1
F0030154: 80a24008                 cmp     %o1, %o0
F0030158: 12bfffb2                 bne     loc_F0030020
F003015C: d007a048                 ld      [%fp+arg_48], %o0
F0030160: d00a8000                 ldub    [%o2], %o0
F0030164: 80a22002                 cmp     %o0, 2
F0030168: 12bfffae                 bne     loc_F0030020
F003016C: d007a048                 ld      [%fp+arg_48], %o0
F0030170: 9002a01c                 add     %o2, 0x1C, %o0! void *
F0030174: d207a054                 ld      [%fp+arg_54], %o1! void *
F0030178: 7fff5779                 call    _bcmp
F003017C: 94102006                 mov     6, %o2
F0030180: 80a22000                 cmp     %o0, 0
F0030184: 12bfffa7                 bne     loc_F0030020
F0030188: d007a048                 ld      [%fp+arg_48], %o0
F003018C: d007bfb8                 ld      [%fp+var_48], %o0
F0030190: d00a2006                 ldub    [%o0+6], %o0
F0030194: 80a22000                 cmp     %o0, 0
F0030198: 1280001a                 bne     loc_F0030200
F003019C: 113c04cf                 sethi   -0xFECC400, %o0
F00301A0: d007bfb4                 ld      [%fp+var_4C], %o0
F00301A4: d00a2006                 ldub    [%o0+6], %o0
F00301A8: 80a22000                 cmp     %o0, 0
F00301AC: 02800014                 be      loc_F00301FC
F00301B0: d007bfac                 ld      [%fp+var_54], %o0
F00301B4: 80a22000                 cmp     %o0, 0
F00301B8: 1280000e                 bne     loc_F00301F0
F00301BC: d007bfd0                 ld      [%fp+var_30], %o0
F00301C0: 90102001                 mov     1, %o0
F00301C4: d027bfac                 st      %o0, [%fp+var_54]
F00301C8: d027bfd0                 st      %o0, [%fp+var_30]
F00301CC: 113c00bf                 sethi   %hi(sub_F002FEA4), %o0
F00301D0: 133c043e                 sethi   %hi(_hz), %o1
F00301D4: d60263e0                 ld      [%o1+%lo(_hz)], %o3
F00301D8: 901222a4                 bset    %lo(sub_F002FEA4), %o0
F00301DC: 9207bfd0                 add     %fp, var_30, %o1
F00301E0: 952ae002                 sll     %o3, 2, %o2
F00301E4: 9402800b                 add     %o2, %o3, %o2
F00301E8: 10bfff8b                 ba      loc_F0030014
F00301EC: 952aa001                 sll     %o2, 1, %o2
F00301F0: 80a22001                 cmp     %o0, 1
F00301F4: 02bfff8b                 be      loc_F0030020
F00301F8: d007a048                 ld      [%fp+arg_48], %o0
F00301FC: 113c04cf                 sethi   -0xFECC400, %o0
F0030200: d60221dc                 ld      [%o0+0x1DC], %o3
F0030204: d207bfe8                 ld      [%fp+var_18], %o1
F0030208: 113c00bf90122288         set     sub_F002FE88, %o0
F0030210: d222e028                 st      %o1, [%o3+0x28]
F0030214: d407bfec                 ld      [%fp+var_14], %o2
F0030218: 9207bfd4                 add     %fp, var_2C, %o1
F003021C: 7fff678e                 call    _untimeout
F0030220: d422e02c                 st      %o2, [%o3+0x2C]
F0030224: d007bfb0                 ld      [%fp+var_50], %o0
F0030228: 80a22000                 cmp     %o0, 0
F003022C: 02800004                 be      loc_F003023C
F0030230: 113c0431                 sethi   %hi(aNetworkRespond), %o0! "Network responded!\n"
F0030234: 7fff9109                 call    _printf
F0030238: 90122158                 bset    %lo(aNetworkRespond), %o0! "Network responded!\n"
F003023C: b0102000                 mov     0, %i0
F0030240: 113c00bf                 sethi   -0xFFD0400, %o0
F0030244: 901222a4                 bset    0x2A4, %o0
F0030248: 7fff6783                 call    _untimeout
F003024C: 9207bfd0                 add     %fp, var_30, %o1
F0030250: 81c7e008                 ret
F0030254: 81e80000                 restore
