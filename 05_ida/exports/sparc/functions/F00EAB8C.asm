F00EAB8C: 9de3bf88                 save    %sp, -0x78, %sp
F00EAB90: a4100018                 mov     %i0, %l2
F00EAB94: e804a014                 ld      [%l2+0x14], %l4
F00EAB98: d004a008                 ld      [%l2+8], %o0
F00EAB9C: 9210001a                 mov     %i2, %o1
F00EABA0: 7ffffd9c                 call    sub_F00EA210
F00EABA4: d404a010                 ld      [%l2+0x10], %o2
F00EABA8: 94100008                 mov     %o0, %o2
F00EABAC: 912aa003                 sll     %o2, 3, %o0
F00EABB0: d2050008                 ld      [%l4+%o0], %o1
F00EABB4: d227bfe8                 st      %o1, [%fp+var_18]
F00EABB8: 90050008                 add     %l4, %o0, %o0
F00EABBC: d0022004                 ld      [%o0+4], %o0
F00EABC0: d027bfec                 st      %o0, [%fp+__src]
F00EABC4: a2027fff                 add     %o1, -1, %l1
F00EABC8: 80a47fff                 cmp     %l1, -1
F00EABCC: 02800043                 be      loc_F00EACD8
F00EABD0: b0100008                 mov     %o0, %i0
F00EABD4: 113c0506                 sethi   %hi(paZone), %o0
F00EABD8: e6022254                 ld      [%o0+%lo(paZone)], %l3
F00EABDC: ab2aa003                 sll     %o2, 3, %l5
F00EABE0: ac050015                 add     %l4, %l5, %l6
F00EABE4: d004a008                 ld      [%l2+8], %o0
F00EABE8: 9210001a                 mov     %i2, %o1! SEL
F00EABEC: 7ffffdbf                 call    sub_F00EA2E8
F00EABF0: d4060000                 ld      [%i0], %o2
F00EABF4: 80a22000                 cmp     %o0, 0
F00EABF8: 02800034                 be      loc_F00EACC8
F00EABFC: d007bfe8                 ld      [%fp+var_18], %o0
F00EAC00: 80a22001                 cmp     %o0, 1
F00EAC04: 02800010                 be      loc_F00EAC44
F00EAC08: f0062004                 ld      [%i0+4], %i0
F00EAC0C: 90100012                 mov     %l2, %o0! id
F00EAC10: 40001b18                 call    _objc_msgSend
F00EAC14: 92100013                 mov     %l3, %o1! SEL
F00EAC18: a0100008                 mov     %o0, %l0
F00EAC1C: 90100012                 mov     %l2, %o0! id
F00EAC20: 40001b14                 call    _objc_msgSend
F00EAC24: 92100013                 mov     %l3, %o1
F00EAC28: d207bfe8                 ld      [%fp+var_18], %o1
F00EAC2C: 92027fff                 inc     -1, %o1
F00EAC30: d4042004                 ld      [%l0+4], %o2
F00EAC34: 9fc28000                 call    %o2
F00EAC38: 932a6003                 sll     %o1, 3, %o1
F00EAC3C: 10800003                 ba      loc_F00EAC48
F00EAC40: a0100008                 mov     %o0, %l0
F00EAC44: a0102000                 mov     0, %l0
F00EAC48: d407bfe8                 ld      [%fp+var_18], %o2
F00EAC4C: 9002bfff                 add     %o2, -1, %o0
F00EAC50: 80a20011                 cmp     %o0, %l1
F00EAC54: 02800007                 be      loc_F00EAC70
F00EAC58: 90100010                 mov     %l0, %o0! __dst
F00EAC5C: 94228011                 sub     %o2, %l1, %o2
F00EAC60: 9402bfff                 inc     -1, %o2! __len
F00EAC64: d207bfec                 ld      [%fp+__src], %o1! __src
F00EAC68: 7ffc74da                 call    _memmove
F00EAC6C: 952aa003                 sll     %o2, 3, %o2
F00EAC70: 80a46000                 cmp     %l1, 0
F00EAC74: 0280000b                 be      loc_F00EACA0
F00EAC78: d207bfe8                 ld      [%fp+var_18], %o1
F00EAC7C: 932a6003                 sll     %o1, 3, %o1
F00EAC80: 90040009                 add     %l0, %o1, %o0
F00EAC84: 952c6003                 sll     %l1, 3, %o2! __len
F00EAC88: 9022000a                 sub     %o0, %o2, %o0
F00EAC8C: d607bfec                 ld      [%fp+__src], %o3
F00EAC90: 9202400b                 add     %o1, %o3, %o1! __src
F00EAC94: 90023ff8                 inc     -8, %o0! void *
F00EAC98: 7ffc74ce                 call    _memmove
F00EAC9C: 9222400a                 sub     %o1, %o2, %o1
F00EACA0: 7ffdf598                 call    _free
F00EACA4: d007bfec                 ld      [%fp+__src], %o0
F00EACA8: d004a004                 ld      [%l2+4], %o0
F00EACAC: 90023fff                 inc     -1, %o0
F00EACB0: d024a004                 st      %o0, [%l2+4]
F00EACB4: d0050015                 ld      [%l4+%l5], %o0
F00EACB8: 90023fff                 inc     -1, %o0
F00EACBC: d0250015                 st      %o0, [%l4+%l5]
F00EACC0: 10800007                 ba      locret_F00EACDC
F00EACC4: e025a004                 st      %l0, [%l6+4]
F00EACC8: a2047fff                 inc     -1, %l1
F00EACCC: 80a47fff                 cmp     %l1, -1
F00EACD0: 12bfffc5                 bne     loc_F00EABE4
F00EACD4: b0062008                 inc     8, %i0
F00EACD8: b0102000                 mov     0, %i0
F00EACDC: 81c7e008                 ret
F00EACE0: 81e80000                 restore
