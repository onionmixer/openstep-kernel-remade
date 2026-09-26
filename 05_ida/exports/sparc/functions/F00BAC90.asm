F00BAC90: 9de3bf90                 save    %sp, -0x70, %sp
F00BAC94: 113c047e                 sethi   %hi(dword_F011FB10), %o0
F00BAC98: 233c04fd                 sethi   %hi(_zscom), %l1
F00BAC9C: d2022310                 ld      [%o0+%lo(dword_F011FB10)], %o1! size_t
F00BACA0: b4102000                 mov     0, %i2
F00BACA4: d00461e8                 ld      [%l1+%lo(_zscom)], %o0
F00BACA8: 80a22000                 cmp     %o0, 0
F00BACAC: 1280002a                 bne     loc_F00BAD54
F00BACB0: d226202c                 st      %o1, [%i0+0x2C]
F00BACB4: 113c04fc                 sethi   %hi(_nzs), %o0
F00BACB8: e0022150                 ld      [%o0+%lo(_nzs)], %l0
F00BACBC: a12c2007                 sll     %l0, 7, %l0
F00BACC0: 7ffeb4ec                 call    _kalloc
F00BACC4: 90100010                 mov     %l0, %o0! void *
F00BACC8: d02461e8                 st      %o0, [%l1+%lo(_zscom)]
F00BACCC: 7fff6863                 call    _bzero
F00BACD0: 92100010                 mov     %l0, %o1! size_t
F00BACD4: 7ffeb4e7                 call    _kalloc
F00BACD8: 90102004                 mov     4, %o0! void *
F00BACDC: 253c04fd                 sethi   %hi(_zssoftCAR), %l2
F00BACE0: d024a1d0                 st      %o0, [%l2+%lo(_zssoftCAR)]
F00BACE4: 7fff685d                 call    _bzero
F00BACE8: 92102004                 mov     4, %o1! size_t
F00BACEC: 7ffeb4e1                 call    _kalloc
F00BACF0: 90102010                 mov     0x10, %o0! void *
F00BACF4: 213c04fd                 sethi   %hi(_zsinfo), %l0
F00BACF8: d02421f8                 st      %o0, [%l0+%lo(_zsinfo)]
F00BACFC: 7fff6857                 call    _bzero
F00BAD00: 92102010                 mov     0x10, %o1
F00BAD04: d20461e8                 ld      [%l1+0x1E8], %o1
F00BAD08: 113c04fd                 sethi   %hi(_zscurr), %o0
F00BAD0C: 94026040                 add     %o1, 0x40, %o2 ! '@'
F00BAD10: d42221f0                 st      %o2, [%o0+%lo(_zscurr)]
F00BAD14: 113c04fd                 sethi   %hi(_zslast), %o0
F00BAD18: 80a26000                 cmp     %o1, 0
F00BAD1C: 02800009                 be      loc_F00BAD40
F00BAD20: d2222200                 st      %o1, [%o0+%lo(_zslast)]
F00BAD24: d004a1d0                 ld      [%l2+0x1D0], %o0
F00BAD28: 80a22000                 cmp     %o0, 0
F00BAD2C: 02800005                 be      loc_F00BAD40
F00BAD30: d00421f8                 ld      [%l0+%lo(_zsinfo)], %o0
F00BAD34: 80a22000                 cmp     %o0, 0
F00BAD38: 32800008                 bne,a   loc_F00BAD58
F00BAD3C: d006202c                 ld      [%i0+0x2C], %o0
F00BAD40: 113c047e                 sethi   %hi(aZsNoSpaceForSt), %o0! "zs: no space for structures\n"
F00BAD44: 7ffd6645                 call    _printf
F00BAD48: 90122350                 bset    %lo(aZsNoSpaceForSt), %o0! "zs: no space for structures\n"
F00BAD4C: 108000c5                 ba      locret_F00BB060
F00BAD50: b0103fff                 mov     -1, %i0
F00BAD54: d006202c                 ld      [%i0+0x2C], %o0
F00BAD58: 133c04fd                 sethi   %hi(_zscom), %o1
F00BAD5C: d20261e8                 ld      [%o1+%lo(_zscom)], %o1
F00BAD60: 912a2007                 sll     %o0, 7, %o0
F00BAD64: 7fffab8d                 call    _stop_mon_clock
F00BAD68: a2024008                 add     %o1, %o0, %l1
F00BAD6C: d0062010                 ld      [%i0+0x10], %o0
F00BAD70: 90023fff                 inc     -1, %o0
F00BAD74: 80a22001                 cmp     %o0, 1
F00BAD78: 28800009                 bleu,a  loc_F00BAD9C
F00BAD7C: d4062014                 ld      [%i0+0x14], %o2
F00BAD80: 113c047e                 sethi   %hi(dword_F011FB10), %o0
F00BAD84: d2022310                 ld      [%o0+%lo(dword_F011FB10)], %o1
F00BAD88: 113c047e                 sethi   %hi(aZsDWarningBadR), %o0! "zs%d: warning: bad register specificati"...
F00BAD8C: 7ffd6633                 call    _printf
F00BAD90: 90122370                 bset    %lo(aZsDWarningBadR), %o0! "zs%d: warning: bad register specificati"...
F00BAD94: 108000b3                 ba      locret_F00BB060
F00BAD98: b0103fff                 mov     -1, %i0
F00BAD9C: d002a004                 ld      [%o2+4], %o0
F00BADA0: d202a008                 ld      [%o2+8], %o1
F00BADA4: d4028000                 ld      [%o2], %o2
F00BADA8: 7fffda1d                 call    _map_regs
F00BADAC: a0102000                 mov     0, %l0
F00BADB0: ac100008                 mov     %o0, %l6
F00BADB4: ec246010                 st      %l6, [%l1+0x10]
F00BADB8: d0046010                 ld      [%l1+0x10], %o0
F00BADBC: 92102001                 mov     1, %o1
F00BADC0: 400001e6                 call    _zszread
F00BADC4: 90122004                 bset    4, %o0
F00BADC8: 808a2001                 btst    1, %o0
F00BADCC: 02800014                 be      loc_F00BAE1C
F00BADD0: 92102001                 mov     1, %o1
F00BADD4: d0046010                 ld      [%l1+0x10], %o0
F00BADD8: 400001e0                 call    _zszread
F00BADDC: 900a3ffb                 and     %o0, -5, %o0
F00BADE0: 808a2001                 btst    1, %o0
F00BADE4: 0280000e                 be      loc_F00BAE1C
F00BADE8: 92102000                 mov     0, %o1
F00BADEC: d0046010                 ld      [%l1+0x10], %o0
F00BADF0: 400001da                 call    _zszread
F00BADF4: 90122004                 bset    4, %o0
F00BADF8: 808a2004                 btst    4, %o0
F00BADFC: 02800008                 be      loc_F00BAE1C
F00BAE00: 92102000                 mov     0, %o1
F00BAE04: d0046010                 ld      [%l1+0x10], %o0
F00BAE08: 400001d4                 call    _zszread
F00BAE0C: 900a3ffb                 and     %o0, -5, %o0
F00BAE10: 808a2004                 btst    4, %o0
F00BAE14: 12800009                 bne     loc_F00BAE38
F00BAE18: 9210200c                 mov     0xC, %o1
F00BAE1C: 7fff7291                 call    _us_spin
F00BAE20: 901023e8                 mov     0x3E8, %o0
F00BAE24: 90100010                 mov     %l0, %o0
F00BAE28: 80a221f4                 cmp     %o0, 0x1F4
F00BAE2C: 04bfffe3                 ble     loc_F00BADB8
F00BAE30: a0042001                 inc     %l0
F00BAE34: 9210200c                 mov     0xC, %o1
F00BAE38: a8102000                 mov     0, %l4
F00BAE3C: 2f3c047fb215e034         set     _zs_proto, %i1
F00BAE44: d0046010                 ld      [%l1+0x10], %o0
F00BAE48: a6046014                 add     %l1, 0x14, %l3
F00BAE4C: 400001c3                 call    _zszread
F00BAE50: 90122004                 bset    4, %o0
F00BAE54: d037bff0                 sth     %o0, [%fp+var_10]
F00BAE58: d0046010                 ld      [%l1+0x10], %o0
F00BAE5C: 9210200d                 mov     0xD, %o1
F00BAE60: 400001be                 call    _zszread
F00BAE64: 90122004                 bset    4, %o0
F00BAE68: d217bff0                 lduh    [%fp+var_10], %o1
F00BAE6C: 912a2008                 sll     %o0, 8, %o0
F00BAE70: 92124008                 bset    %o0, %o1
F00BAE74: d237bff0                 sth     %o1, [%fp+var_10]
F00BAE78: d0046010                 ld      [%l1+0x10], %o0
F00BAE7C: 9210200c                 mov     0xC, %o1
F00BAE80: 400001b6                 call    _zszread
F00BAE84: 900a3ffb                 and     %o0, -5, %o0
F00BAE88: d037bff2                 sth     %o0, [%fp+var_E]
F00BAE8C: d0046010                 ld      [%l1+0x10], %o0
F00BAE90: 9210200d                 mov     0xD, %o1
F00BAE94: 400001b1                 call    _zszread
F00BAE98: 900a3ffb                 and     %o0, -5, %o0
F00BAE9C: 92102009                 mov     9, %o1
F00BAEA0: 941020c0                 mov     0xC0, %o2
F00BAEA4: d617bff2                 lduh    [%fp+var_E], %o3
F00BAEA8: 912a2008                 sll     %o0, 8, %o0
F00BAEAC: 9612c008                 bset    %o0, %o3
F00BAEB0: d637bff2                 sth     %o3, [%fp+var_E]
F00BAEB4: 961020c0                 mov     0xC0, %o3
F00BAEB8: d0046010                 ld      [%l1+0x10], %o0
F00BAEBC: 400001aa                 call    _zszwrite
F00BAEC0: d62c6029                 stb     %o3, [%l1+0x29]
F00BAEC4: 7fff7267                 call    _us_spin
F00BAEC8: 9010200a                 mov     0xA, %o0
F00BAECC: c02c6029                 clrb    [%l1+0x29]
F00BAED0: aa07bff8                 add     %fp, var_8, %l5
F00BAED4: 80a52000                 cmp     %l4, 0
F00BAED8: 32800005                 bne,a   loc_F00BAEEC
F00BAEDC: a604e040                 inc     0x40, %l3 ! '@'
F00BAEE0: 9015a004                 or      %l6, 4, %o0
F00BAEE4: 10800007                 ba      loc_F00BAF00
F00BAEE8: d024fffc                 st      %o0, [%l3-4]
F00BAEEC: a2046040                 inc     0x40, %l1 ! '@'
F00BAEF0: 900dbffb                 and     %l6, -5, %o0
F00BAEF4: d024fffc                 st      %o0, [%l3-4]
F00BAEF8: 113c04fd                 sethi   %hi(_zscurr), %o0
F00BAEFC: e22221f0                 st      %l1, [%o0+%lo(_zscurr)]
F00BAF00: d006202c                 ld      [%i0+0x2C], %o0
F00BAF04: 133c04fd                 sethi   %hi(_zsinfo), %o1
F00BAF08: d20261f8                 ld      [%o1+%lo(_zsinfo)], %o1
F00BAF0C: 912a2001                 sll     %o0, 1, %o0
F00BAF10: 90020014                 add     %o0, %l4, %o0
F00BAF14: d034c000                 sth     %o0, [%l3]
F00BAF18: 912a2010                 sll     %o0, 16, %o0
F00BAF1C: 913a200e                 sra     %o0, 14, %o0
F00BAF20: f0224008                 st      %i0, [%o1+%o0]
F00BAF24: 80a52000                 cmp     %l4, 0
F00BAF28: 02800005                 be      loc_F00BAF3C
F00BAF2C: d4062028                 ld      [%i0+0x28], %o2
F00BAF30: 113c047e                 sethi   %hi(aPortBIgnoreCd), %o0! "port-b-ignore-cd"
F00BAF34: 10800004                 ba      loc_F00BAF44
F00BAF38: 921223a0                 or      %o0, %lo(aPortBIgnoreCd), %o1! "port-b-ignore-cd"
F00BAF3C: 113c047e921223b8         set     aPortAIgnoreCd, %o1! "port-a-ignore-cd"
F00BAF44: 9010000a                 mov     %o2, %o0
F00BAF48: 7fffd859                 call    _getprop
F00BAF4C: 94102000                 mov     0, %o2
F00BAF50: d454c000                 ldsh    [%l3], %o2
F00BAF54: 133c04fd                 sethi   %hi(_zssoftCAR), %o1
F00BAF58: d20261d0                 ld      [%o1+%lo(_zssoftCAR)], %o1
F00BAF5C: d02a400a                 stb     %o0, [%o1+%o2]
F00BAF60: d005e034                 ld      [%l7+0x34], %o0
F00BAF64: 80a22000                 cmp     %o0, 0
F00BAF68: 2280000f                 be,a    loc_F00BAFA4
F00BAF6C: a8052001                 inc     %l4
F00BAF70: a4100015                 mov     %l5, %l2
F00BAF74: a0100019                 mov     %i1, %l0
F00BAF78: d254bff8                 ldsh    [%l2-8], %o1
F00BAF7C: d4040000                 ld      [%l0], %o2
F00BAF80: 90100011                 mov     %l1, %o0
F00BAF84: d4028000                 ld      [%o2], %o2
F00BAF88: 9fc28000                 call    %o2
F00BAF8C: a0042004                 inc     4, %l0
F00BAF90: d0040000                 ld      [%l0], %o0
F00BAF94: 80a22000                 cmp     %o0, 0
F00BAF98: 32bffff9                 bne,a   loc_F00BAF7C
F00BAF9C: d254bff8                 ldsh    [%l2-8], %o1
F00BAFA0: a8052001                 inc     %l4
F00BAFA4: 80a52001                 cmp     %l4, 1
F00BAFA8: 04bfffcb                 ble     loc_F00BAED4
F00BAFAC: aa056002                 inc     2, %l5
F00BAFB0: 90102009                 mov     9, %o0
F00BAFB4: d02c6029                 stb     %o0, [%l1+0x29]
F00BAFB8: 92102009                 mov     9, %o1
F00BAFBC: d0046010                 ld      [%l1+0x10], %o0
F00BAFC0: 40000169                 call    _zszwrite
F00BAFC4: 94102009                 mov     9, %o2
F00BAFC8: 80a6a000                 cmp     %i2, 0
F00BAFCC: 02800007                 be      loc_F00BAFE8
F00BAFD0: 9010001a                 mov     %i2, %o0
F00BAFD4: d02c6022                 stb     %o0, [%l1+0x22]
F00BAFD8: 92102002                 mov     2, %o1
F00BAFDC: d0046010                 ld      [%l1+0x10], %o0
F00BAFE0: 40000161                 call    _zszwrite
F00BAFE4: 94102000                 mov     0, %o2
F00BAFE8: 7fff721e                 call    _us_spin
F00BAFEC: 90102fa0                 mov     0xFA0, %o0
F00BAFF0: 7fffaada                 call    _start_mon_clock
F00BAFF4: 01000000                 nop
F00BAFF8: 113c04fd                 sethi   %hi(_zslast), %o0
F00BAFFC: d2062018                 ld      [%i0+0x18], %o1
F00BB000: 80a26000                 cmp     %o1, 0
F00BB004: 02800010                 be      loc_F00BB044
F00BB008: e2222200                 st      %l1, [%o0+%lo(_zslast)]
F00BB00C: d406200c                 ld      [%i0+0xC], %o2
F00BB010: 213c047e                 sethi   %hi(dword_F011FB10), %l0
F00BB014: d6042310                 ld      [%l0+%lo(dword_F011FB10)], %o3
F00BB018: d006201c                 ld      [%i0+0x1C], %o0
F00BB01C: 133c02ed                 sethi   %hi(_zsintr_hi), %o1
F00BB020: d0020000                 ld      [%o0], %o0
F00BB024: 7fff780e                 call    _addintr
F00BB028: 921260d0                 bset    %lo(_zsintr_hi), %o1
F00BB02C: 90102016                 mov     0x16, %o0
F00BB030: d406200c                 ld      [%i0+0xC], %o2
F00BB034: 133c02ec                 sethi   %hi(_zsintr), %o1
F00BB038: d6042310                 ld      [%l0+%lo(dword_F011FB10)], %o3
F00BB03C: 7fff7808                 call    _addintr
F00BB040: 921261bc                 bset    %lo(_zsintr), %o1
F00BB044: 7fffd77d                 call    _report_dev
F00BB048: 90100018                 mov     %i0, %o0
F00BB04C: 133c047e                 sethi   %hi(dword_F011FB10), %o1
F00BB050: d0026310                 ld      [%o1+%lo(dword_F011FB10)], %o0
F00BB054: b0102000                 mov     0, %i0
F00BB058: 90022001                 inc     %o0
F00BB05C: d0226310                 st      %o0, [%o1+%lo(dword_F011FB10)]
F00BB060: 81c7e008                 ret
F00BB064: 81e80000                 restore
