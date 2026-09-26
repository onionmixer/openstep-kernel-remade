F004F460: 9de3bf90                 save    %sp, -0x70, %sp
F004F464: d0562002                 ldsh    [%i0+2], %o0
F004F468: 80a22002                 cmp     %o0, 2
F004F46C: 12800003                 bne     loc_F004F478
F004F470: a2102023                 mov     0x23, %l1 ! '#'
F004F474: a2102028                 mov     0x28, %l1 ! '('
F004F478: 4000012d                 call    sub_F004F92C
F004F47C: 90100018                 mov     %i0, %o0
F004F480: a0920000                 orcc    %o0, %g0, %l0
F004F484: 22800032                 be,a    loc_F004F54C
F004F488: a2102001                 mov     1, %l1
F004F48C: d0160000                 lduh    [%i0], %o0
F004F490: 808a2001                 btst    1, %o0
F004F494: 02800006                 be      loc_F004F4AC
F004F498: 94102000                 mov     0, %o2
F004F49C: 40000211                 call    sub_F004FCE0
F004F4A0: 90100018                 mov     %i0, %o0
F004F4A4: 108000b8                 ba      locret_F004F784
F004F4A8: b010200b                 mov     0xB, %i0
F004F4AC: 10800010                 ba      loc_F004F4EC
F004F4B0: d204200c                 ld      [%l0+0xC], %o1
F004F4B4: 80a22031                 cmp     %o0, 0x31 ! '1'
F004F4B8: 14800011                 bg      loc_F004F4FC
F004F4BC: 9402a001                 inc     %o2
F004F4C0: d0026014                 ld      [%o1+0x14], %o0
F004F4C4: d0022014                 ld      [%o0+0x14], %o0
F004F4C8: d202200c                 ld      [%o0+0xC], %o1
F004F4CC: d006200c                 ld      [%i0+0xC], %o0
F004F4D0: 80a24008                 cmp     %o1, %o0
F004F4D4: 32800007                 bne,a   loc_F004F4F0
F004F4D8: d0026014                 ld      [%o1+0x14], %o0
F004F4DC: 40000201                 call    sub_F004FCE0
F004F4E0: 90100018                 mov     %i0, %o0
F004F4E4: 108000a8                 ba      locret_F004F784
F004F4E8: b010204e                 mov     0x4E, %i0 ! 'N'
F004F4EC: d0026014                 ld      [%o1+0x14], %o0
F004F4F0: 80a22000                 cmp     %o0, 0
F004F4F4: 12bffff0                 bne     loc_F004F4B4
F004F4F8: 9010000a                 mov     %o2, %o0
F004F4FC: e0262014                 st      %l0, [%i0+0x14]
F004F500: 90100010                 mov     %l0, %o0
F004F504: 4000019a                 call    sub_F004FB6C
F004F508: 92100018                 mov     %i0, %o1
F004F50C: 90100018                 mov     %i0, %o0! unsigned int
F004F510: d406200c                 ld      [%i0+0xC], %o2
F004F514: 92146100                 or      %l1, 0x100, %o1
F004F518: 7fff0c58                 call    _sleep
F004F51C: f022a014                 st      %i0, [%o2+0x14]
F004F520: d206200c                 ld      [%i0+0xC], %o1
F004F524: 80a22000                 cmp     %o0, 0
F004F528: 02bfffd4                 be      loc_F004F478
F004F52C: c0226014                 clr     [%o1+0x14]
F004F530: 90100010                 mov     %l0, %o0
F004F534: 4000019f                 call    sub_F004FBB0
F004F538: 92100018                 mov     %i0, %o1
F004F53C: 400001e9                 call    sub_F004FCE0
F004F540: 90100018                 mov     %i0, %o0
F004F544: 10800090                 ba      locret_F004F784
F004F548: b0102004                 mov     4, %i0
F004F54C: 113c013d                 sethi   %hi(jpt_F004F5A0), %o0
F004F550: d2062010                 ld      [%i0+0x10], %o1
F004F554: a41221a8                 or      %o0, %lo(jpt_F004F5A0), %l2
F004F558: d0062010                 ld      [%i0+0x10], %o0
F004F55C: 92026004                 inc     4, %o1
F004F560: d227bff4                 st      %o1, [%fp+var_10+4]
F004F564: e0022004                 ld      [%o0+4], %l0
F004F568: 90100010                 mov     %l0, %o0
F004F56C: 92100018                 mov     %i0, %o1
F004F570: 94102001                 mov     1, %o2
F004F574: 9607bff4                 add     %fp, var_10+4, %o3
F004F578: 40000105                 call    sub_F004F98C
F004F57C: 9807bff0                 add     %fp, var_10, %o4
F004F580: 92920000                 orcc    %o0, %g0, %o1
F004F584: 02800003                 be      loc_F004F590
F004F588: d007bff0                 ld      [%fp+var_10], %o0
F004F58C: e0022014                 ld      [%o0+0x14], %l0
F004F590: 80a26005                 cmp     %o1, 5! switch 6 cases
F004F594: 1880007b                 bgu     def_F004F5A0! jumptable F004F5A0 default case
F004F598: 912a6002                 sll     %o1, 2, %o0
F004F59C: d0020012                 ld      [%o0+%l2], %o0
F004F5A0: 81c20000                 jmp     %o0! switch jump
F004F5A4: 01000000                 nop
F004F5C0: 80a46000                 cmp     %l1, 0! jumptable F004F5A0 case 0
F004F5C4: 0280006f                 be      def_F004F5A0! jumptable F004F5A0 default case
F004F5C8: d007bff4                 ld      [%fp+var_10+4], %o0
F004F5CC: f0220000                 st      %i0, [%o0]
F004F5D0: d007bff0                 ld      [%fp+var_10], %o0
F004F5D4: 1080006b                 ba      def_F004F5A0! jumptable F004F5A0 default case
F004F5D8: d0262014                 st      %o0, [%i0+0x14]
F004F5DC: d0562002                 ldsh    [%i0+2], %o0! jumptable F004F5A0 case 1
F004F5E0: 80a22001                 cmp     %o0, 1
F004F5E4: 1280000a                 bne     loc_F004F60C
F004F5E8: d407bff0                 ld      [%fp+var_10], %o2
F004F5EC: d207bff0                 ld      [%fp+var_10], %o1
F004F5F0: d0526002                 ldsh    [%o1+2], %o0
F004F5F4: 80a22002                 cmp     %o0, 2
F004F5F8: 32800006                 bne,a   loc_F004F610
F004F5FC: d2162002                 lduh    [%i0+2], %o1
F004F600: 400001a9                 call    sub_F004FCA4
F004F604: 90100009                 mov     %o1, %o0
F004F608: d407bff0                 ld      [%fp+var_10], %o2
F004F60C: d2162002                 lduh    [%i0+2], %o1
F004F610: 90100018                 mov     %i0, %o0
F004F614: 400001b3                 call    sub_F004FCE0
F004F618: d232a002                 sth     %o1, [%o2+2]
F004F61C: 1080005a                 ba      locret_F004F784
F004F620: b0102000                 mov     0, %i0
F004F624: d407bff0                 ld      [%fp+var_10], %o2! jumptable F004F5A0 case 2
F004F628: d0562002                 ldsh    [%i0+2], %o0
F004F62C: d252a002                 ldsh    [%o2+2], %o1
F004F630: 80a24008                 cmp     %o1, %o0
F004F634: 32800006                 bne,a   loc_F004F64C
F004F638: d202a004                 ld      [%o2+4], %o1
F004F63C: 400001a9                 call    sub_F004FCE0
F004F640: 90100018                 mov     %i0, %o0
F004F644: 10800050                 ba      locret_F004F784
F004F648: b0102000                 mov     0, %i0
F004F64C: d0062004                 ld      [%i0+4], %o0
F004F650: 80a24008                 cmp     %o1, %o0
F004F654: 1280000a                 bne     loc_F004F67C
F004F658: 9010000a                 mov     %o2, %o0
F004F65C: d007bff4                 ld      [%fp+var_10+4], %o0
F004F660: f0220000                 st      %i0, [%o0]
F004F664: d207bff0                 ld      [%fp+var_10], %o1
F004F668: d0062008                 ld      [%i0+8], %o0
F004F66C: d2262014                 st      %o1, [%i0+0x14]
F004F670: 90022001                 inc     %o0
F004F674: 10800004                 ba      loc_F004F684
F004F678: d0226004                 st      %o0, [%o1+4]
F004F67C: 4000015f                 call    sub_F004FBF8
F004F680: 92100018                 mov     %i0, %o1
F004F684: 1080003d                 ba      loc_F004F778
F004F688: d007bff0                 ld      [%fp+var_10], %o0
F004F68C: d0562002                 ldsh    [%i0+2], %o0! jumptable F004F5A0 case 3
F004F690: 80a22001                 cmp     %o0, 1
F004F694: 1280000b                 bne     loc_F004F6C0
F004F698: d407bff0                 ld      [%fp+var_10], %o2
F004F69C: d207bff0                 ld      [%fp+var_10], %o1
F004F6A0: d0526002                 ldsh    [%o1+2], %o0
F004F6A4: 80a22002                 cmp     %o0, 2
F004F6A8: 32800007                 bne,a   loc_F004F6C4
F004F6AC: d2062018                 ld      [%i0+0x18], %o1
F004F6B0: 4000017d                 call    sub_F004FCA4
F004F6B4: 90100009                 mov     %o1, %o0
F004F6B8: 10800008                 ba      loc_F004F6D8
F004F6BC: 80a46000                 cmp     %l1, 0
F004F6C0: d2062018                 ld      [%i0+0x18], %o1
F004F6C4: d402a018                 ld      [%o2+0x18], %o2
F004F6C8: 90100018                 mov     %i0, %o0
F004F6CC: 40000128                 call    sub_F004FB6C
F004F6D0: d4262018                 st      %o2, [%i0+0x18]
F004F6D4: 80a46000                 cmp     %l1, 0
F004F6D8: 0280000a                 be      loc_F004F700
F004F6DC: d007bff4                 ld      [%fp+var_10+4], %o0
F004F6E0: a2102000                 mov     0, %l1
F004F6E4: f0220000                 st      %i0, [%o0]
F004F6E8: d007bff0                 ld      [%fp+var_10], %o0
F004F6EC: 92062014                 add     %i0, 0x14, %o1
F004F6F0: d0022014                 ld      [%o0+0x14], %o0
F004F6F4: d227bff4                 st      %o1, [%fp+var_10+4]
F004F6F8: 10800005                 ba      loc_F004F70C
F004F6FC: d0262014                 st      %o0, [%i0+0x14]
F004F700: d01fbff0                 ldd     [%fp+var_10], %o0
F004F704: d0022014                 ld      [%o0+0x14], %o0
F004F708: d0224000                 st      %o0, [%o1]
F004F70C: 40000175                 call    sub_F004FCE0
F004F710: d007bff0                 ld      [%fp+var_10], %o0
F004F714: 10bfff96                 ba      loc_F004F56C
F004F718: 90100010                 mov     %l0, %o0
F004F71C: 92062014                 add     %i0, 0x14, %o1! jumptable F004F5A0 case 4
F004F720: d007bff0                 ld      [%fp+var_10], %o0
F004F724: d227bff4                 st      %o1, [%fp+var_10+4]
F004F728: d2022014                 ld      [%o0+0x14], %o1
F004F72C: d2262014                 st      %o1, [%i0+0x14]
F004F730: f0222014                 st      %i0, [%o0+0x14]
F004F734: d2062004                 ld      [%i0+4], %o1
F004F738: a2102000                 mov     0, %l1
F004F73C: 92027fff                 inc     -1, %o1
F004F740: 40000159                 call    sub_F004FCA4
F004F744: d2222008                 st      %o1, [%o0+8]
F004F748: 10bfff89                 ba      loc_F004F56C
F004F74C: 90100010                 mov     %l0, %o0
F004F750: 80a46000                 cmp     %l1, 0! jumptable F004F5A0 case 5
F004F754: 02800005                 be      loc_F004F768
F004F758: d007bff4                 ld      [%fp+var_10+4], %o0
F004F75C: f0220000                 st      %i0, [%o0]
F004F760: d007bff0                 ld      [%fp+var_10], %o0
F004F764: d0262014                 st      %o0, [%i0+0x14]
F004F768: d2062008                 ld      [%i0+8], %o1
F004F76C: d007bff0                 ld      [%fp+var_10], %o0
F004F770: 92026001                 inc     %o1
F004F774: d2222004                 st      %o1, [%o0+4]
F004F778: 4000014b                 call    sub_F004FCA4
F004F77C: 01000000                 nop
F004F780: b0102000                 mov     0, %i0! jumptable F004F5A0 default case
F004F784: 81c7e008                 ret
F004F788: 81e80000                 restore
