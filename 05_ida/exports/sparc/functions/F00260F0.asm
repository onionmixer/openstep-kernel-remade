F00260F0: 9de3bf48                 save    %sp, -0xB8, %sp
F00260F4: f027a044                 st      %i0, [%fp+arg_44]
F00260F8: f0062018                 ld      [%i0+0x18], %i0
F00260FC: f227a048                 st      %i1, [%fp+arg_48]
F0026100: f027bfac                 st      %i0, [%fp+var_54]
F0026104: c407bfac                 ld      [%fp+var_54], %g2
F0026108: f427a04c                 st      %i2, [%fp+arg_4C]
F002610C: d000a028                 ld      [%g2+0x28], %o0
F0026110: 92023fff                 add     %o0, -1, %o1
F0026114: 80a26008                 cmp     %o1, 8! switch 9 cases
F0026118: 18800081                 bgu     def_F0026130! jumptable F0026130 default case, cases 2,4-6
F002611C: c027bfb4                 clr     [%fp+var_4C]
F0026120: 113c009890122138         set     jpt_F0026130, %o0
F0026128: 932a6002                 sll     %o1, 2, %o1
F002612C: d0024008                 ld      [%o1+%o0], %o0
F0026130: 81c20000                 jmp     %o0! switch jump
F0026134: 01000000                 nop
F002615C: 11300119                 sethi   -0x3FFB9C00, %o0! jumptable F0026130 case 0
F0026160: d207a048                 ld      [%fp+arg_48], %o1
F0026164: 9012226a                 bset    0x26A, %o0
F0026168: 80a24008                 cmp     %o1, %o0
F002616C: 12800029                 bne     loc_F0026210
F0026170: 11200119                 sethi   -0x7FFB9C00, %o0
F0026174: d407a044                 ld      [%fp+arg_44], %o2
F0026178: d002a008                 ld      [%o2+8], %o0
F002617C: 17000004                 sethi   0x1000, %o3
F0026180: d207a04c                 ld      [%fp+arg_4C], %o1
F0026184: 900a000b                 and     %o0, %o3, %o0
F0026188: d027bfb0                 st      %o0, [%fp+var_50]
F002618C: d2024000                 ld      [%o1], %o1
F0026190: 80a26001                 cmp     %o1, 1
F0026194: 2280000d                 be,a    loc_F00261C8
F0026198: d002a008                 ld      [%o2+8], %o0
F002619C: 14800007                 bg      loc_F00261B8
F00261A0: 80a26002                 cmp     %o1, 2
F00261A4: 80a26000                 cmp     %o1, 0
F00261A8: 0280000f                 be      loc_F00261E4
F00261AC: d007bfb0                 ld      [%fp+var_50], %o0
F00261B0: 1080005e                 ba      locret_F0026328
F00261B4: b0102016                 mov     0x16, %i0
F00261B8: 22800007                 be,a    loc_F00261D4
F00261BC: d202a008                 ld      [%o2+8], %o1
F00261C0: 1080005a                 ba      locret_F0026328
F00261C4: b0102016                 mov     0x16, %i0
F00261C8: 9012000b                 bset    %o3, %o0
F00261CC: 10800005                 ba      loc_F00261E0
F00261D0: d022a008                 st      %o0, [%o2+8]
F00261D4: 11000004                 sethi   0x1000, %o0
F00261D8: 902a4008                 andn    %o1, %o0, %o0
F00261DC: d022a008                 st      %o0, [%o2+8]
F00261E0: d007bfb0                 ld      [%fp+var_50], %o0
F00261E4: 80a22000                 cmp     %o0, 0
F00261E8: 02800004                 be      loc_F00261F8
F00261EC: d207a04c                 ld      [%fp+arg_4C], %o1
F00261F0: 10800003                 ba      loc_F00261FC
F00261F4: 90102001                 mov     1, %o0
F00261F8: 90102002                 mov     2, %o0
F00261FC: d0224000                 st      %o0, [%o1]
F0026200: 1080004a                 ba      locret_F0026328
F0026204: b0102000                 mov     0, %i0
F0026208: 11200119                 sethi   -0x7FFB9C00, %o0! jumptable F0026130 cases 1,7
F002620C: d207a048                 ld      [%fp+arg_48], %o1
F0026210: 9012227d                 bset    0x27D, %o0
F0026214: 80a24008                 cmp     %o1, %o0
F0026218: 06800041                 bl      def_F0026130! jumptable F0026130 default case, cases 2,4-6
F002621C: 11200119                 sethi   -0x7FFB9C00, %o0
F0026220: 9012227e                 bset    0x27E, %o0
F0026224: 80a24008                 cmp     %o1, %o0
F0026228: 0480003f                 ble     loc_F0026324
F002622C: 11100119                 sethi   0x40046400, %o0
F0026230: 9012227f                 bset    0x27F, %o0
F0026234: 80a24008                 cmp     %o1, %o0
F0026238: 1280003a                 bne     loc_F0026320
F002623C: 90102019                 mov     0x19, %o0
F0026240: c407bfac                 ld      [%fp+var_54], %g2
F0026244: 113c04cf                 sethi   %hi(_active_u), %o0
F0026248: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F002624C: d200a01c                 ld      [%g2+0x1C], %o1
F0026250: d402201c                 ld      [%o0+0x1C], %o2
F0026254: d6026014                 ld      [%o1+0x14], %o3
F0026258: d007bfac                 ld      [%fp+var_54], %o0
F002625C: 9fc2c000                 call    %o3
F0026260: 9207bfb8                 add     %fp, var_48, %o1
F0026264: 80a22000                 cmp     %o0, 0
F0026268: 1280002f                 bne     loc_F0026324
F002626C: d027bfb4                 st      %o0, [%fp+var_4C]
F0026270: d207a044                 ld      [%fp+arg_44], %o1
F0026274: d007bfd0                 ld      [%fp+var_30], %o0
F0026278: d202601c                 ld      [%o1+0x1C], %o1
F002627C: d407a04c                 ld      [%fp+arg_4C], %o2
F0026280: 90220009                 sub     %o0, %o1, %o0
F0026284: 10800028                 ba      loc_F0026324
F0026288: d0228000                 st      %o0, [%o2]
F002628C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0! jumptable F0026130 cases 3,8
F0026290: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0026294: c0226030                 clr     [%o1+0x30]
F0026298: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F002629C: 4001c2ae                 call    _setjmp
F00262A0: 90022028                 inc     0x28, %o0 ! '('
F00262A4: 80a22000                 cmp     %o0, 0
F00262A8: 02800011                 be      loc_F00262EC
F00262AC: 153c04cf                 sethi   %hi(_active_u), %o2
F00262B0: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F00262B4: d0024000                 ld      [%o1], %o0
F00262B8: d04a2017                 ldsb    [%o0+0x17], %o0
F00262BC: d202613c                 ld      [%o1+0x13C], %o1
F00262C0: 90023fff                 inc     -1, %o0
F00262C4: 933a4008                 sra     %o1, %o0, %o1
F00262C8: 808a6001                 btst    1, %o1
F00262CC: 02800004                 be      loc_F00262DC
F00262D0: 9412a1d8                 bset    %lo(_active_u), %o2
F00262D4: 10800013                 ba      loc_F0026320
F00262D8: 90102004                 mov     4, %o0
F00262DC: d202a004                 ld      [%o2+4], %o1
F00262E0: 90102002                 mov     2, %o0
F00262E4: 10800010                 ba      loc_F0026324
F00262E8: d02a6039                 stb     %o0, [%o1+0x39]
F00262EC: d207a048                 ld      [%fp+arg_48], %o1
F00262F0: d407a04c                 ld      [%fp+arg_4C], %o2
F00262F4: c407bfac                 ld      [%fp+var_54], %g2
F00262F8: d807a044                 ld      [%fp+arg_44], %o4
F00262FC: d000a01c                 ld      [%g2+0x1C], %o0
F0026300: d6032008                 ld      [%o4+8], %o3
F0026304: da02200c                 ld      [%o0+0xC], %o5
F0026308: d8032020                 ld      [%o4+0x20], %o4
F002630C: 9fc34000                 call    %o5
F0026310: d007bfac                 ld      [%fp+var_54], %o0
F0026314: 10800004                 ba      loc_F0026324
F0026318: d027bfb4                 st      %o0, [%fp+var_4C]
F002631C: 90102019                 mov     0x19, %o0! jumptable F0026130 default case, cases 2,4-6
F0026320: d027bfb4                 st      %o0, [%fp+var_4C]
F0026324: f007bfb4                 ld      [%fp+var_4C], %i0
F0026328: 81c7e008                 ret
F002632C: 81e80000                 restore
