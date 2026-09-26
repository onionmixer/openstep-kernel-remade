F004F78C: 9de3bf90                 save    %sp, -0x70, %sp
F004F790: d0062010                 ld      [%i0+0x10], %o0
F004F794: e0022004                 ld      [%o0+4], %l0
F004F798: 80a42000                 cmp     %l0, 0
F004F79C: 12800007                 bne     loc_F004F7B8
F004F7A0: 90022004                 inc     4, %o0
F004F7A4: 30800045                 ba,a    def_F004F804! jumptable F004F804 default case
F004F7A8: d0062008                 ld      [%i0+8], %o0
F004F7AC: 90022001                 inc     %o0
F004F7B0: 10800042                 ba      def_F004F804! jumptable F004F804 default case
F004F7B4: d022a004                 st      %o0, [%o2+4]
F004F7B8: d027bff4                 st      %o0, [%fp+var_10+4]
F004F7BC: 113c013ea212200c         set     jpt_F004F804, %l1
F004F7C4: 90100010                 mov     %l0, %o0
F004F7C8: 92100018                 mov     %i0, %o1
F004F7CC: 94102001                 mov     1, %o2
F004F7D0: 9607bff4                 add     %fp, var_10+4, %o3
F004F7D4: 4000006e                 call    sub_F004F98C
F004F7D8: 9807bff0                 add     %fp, var_10, %o4
F004F7DC: a0920000                 orcc    %o0, %g0, %l0
F004F7E0: 02800036                 be      def_F004F804! jumptable F004F804 default case
F004F7E4: 01000000                 nop
F004F7E8: 4000012f                 call    sub_F004FCA4
F004F7EC: d007bff0                 ld      [%fp+var_10], %o0
F004F7F0: 90043fff                 add     %l0, -1, %o0
F004F7F4: 80a22004                 cmp     %o0, 4! switch 5 cases
F004F7F8: 18800030                 bgu     def_F004F804! jumptable F004F804 default case
F004F7FC: 912a2002                 sll     %o0, 2, %o0
F004F800: d0020011                 ld      [%o0+%l1], %o0
F004F804: 81c20000                 jmp     %o0! switch jump
F004F808: 01000000                 nop
F004F820: d01fbff0                 ldd     [%fp+var_10], %o0! jumptable F004F804 case 0
F004F824: d0022014                 ld      [%o0+0x14], %o0
F004F828: d0224000                 st      %o0, [%o1]
F004F82C: 4000012d                 call    sub_F004FCE0
F004F830: d007bff0                 ld      [%fp+var_10], %o0
F004F834: 30800021                 ba,a    def_F004F804! jumptable F004F804 default case
F004F838: d407bff0                 ld      [%fp+var_10], %o2! jumptable F004F804 case 1
F004F83C: d0062004                 ld      [%i0+4], %o0
F004F840: d202a004                 ld      [%o2+4], %o1
F004F844: 80a24008                 cmp     %o1, %o0
F004F848: 02bfffd8                 be      loc_F004F7A8
F004F84C: 9010000a                 mov     %o2, %o0
F004F850: 400000ea                 call    sub_F004FBF8
F004F854: 92100018                 mov     %i0, %o1
F004F858: d207bff0                 ld      [%fp+var_10], %o1
F004F85C: d0062014                 ld      [%i0+0x14], %o0
F004F860: 10800016                 ba      def_F004F804! jumptable F004F804 default case
F004F864: d0226014                 st      %o0, [%o1+0x14]
F004F868: d01fbff0                 ldd     [%fp+var_10], %o0! jumptable F004F804 case 2
F004F86C: d0022014                 ld      [%o0+0x14], %o0
F004F870: d0224000                 st      %o0, [%o1]
F004F874: d007bff0                 ld      [%fp+var_10], %o0
F004F878: 4000011a                 call    sub_F004FCE0
F004F87C: e0022014                 ld      [%o0+0x14], %l0
F004F880: 10bfffd2                 ba      loc_F004F7C8
F004F884: 90100010                 mov     %l0, %o0
F004F888: d0062004                 ld      [%i0+4], %o0! jumptable F004F804 case 3
F004F88C: d207bff0                 ld      [%fp+var_10], %o1
F004F890: 90023fff                 inc     -1, %o0
F004F894: e0026014                 ld      [%o1+0x14], %l0
F004F898: d0226008                 st      %o0, [%o1+8]
F004F89C: 92026014                 inc     0x14, %o1
F004F8A0: 10bfffc9                 ba      loc_F004F7C4
F004F8A4: d227bff4                 st      %o1, [%fp+var_10+4]
F004F8A8: d0062008                 ld      [%i0+8], %o0! jumptable F004F804 case 4
F004F8AC: d207bff0                 ld      [%fp+var_10], %o1
F004F8B0: 90022001                 inc     %o0
F004F8B4: d0226004                 st      %o0, [%o1+4]
F004F8B8: 81c7e008                 ret! jumptable F004F804 default case
F004F8BC: 91e82000                 restore %g0, 0, %o0
