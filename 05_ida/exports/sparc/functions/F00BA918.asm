F00BA918: 9de3bf98                 save    %sp, -0x68, %sp! int
F00BA91C: e0060000                 ld      [%i0], %l0
F00BA920: d256200a                 ldsh    [%i0+0xA], %o1
F00BA924: d0042034                 ld      [%l0+0x34], %o0
F00BA928: 80a26000                 cmp     %o1, 0
F00BA92C: 02800033                 be      loc_F00BA9F8
F00BA930: e2022010                 ld      [%o0+0x10], %l1
F00BA934: c036200a                 clrh    [%i0+0xA]
F00BA938: d00c4000                 ldub    [%l1], %o0
F00BA93C: 808a2008                 btst    8, %o0
F00BA940: 32800010                 bne,a   loc_F00BA980
F00BA944: d0042040                 ld      [%l0+0x40], %o0
F00BA948: 133c04fd                 sethi   %hi(_zssoftCAR), %o1
F00BA94C: d0142038                 lduh    [%l0+0x38], %o0
F00BA950: 921261d0                 bset    %lo(_zssoftCAR), %o1
F00BA954: 900a201f                 and     %o0, 0x1F, %o0
F00BA958: d04a0009                 ldsb    [%o0+%o1], %o0
F00BA95C: 80a22000                 cmp     %o0, 0
F00BA960: 32800008                 bne,a   loc_F00BA980
F00BA964: d0042040                 ld      [%l0+0x40], %o0
F00BA968: d2042040                 ld      [%l0+0x40], %o1
F00BA96C: 11100000                 sethi   0x40000000, %o0
F00BA970: 808a4008                 btst    %o0, %o1
F00BA974: 0280000b                 be      loc_F00BA9A0
F00BA978: 808a6010                 btst    0x10, %o1
F00BA97C: d0042040                 ld      [%l0+0x40], %o0
F00BA980: 808a2010                 btst    0x10, %o0
F00BA984: 3280001e                 bne,a   loc_F00BA9FC
F00BA988: d0562008                 ldsh    [%i0+8], %o0
F00BA98C: 7ffd6117                 call    _wakeup
F00BA990: 90042040                 add     %l0, 0x40, %o0 ! '@'
F00BA994: d0042040                 ld      [%l0+0x40], %o0
F00BA998: 10800017                 ba      loc_F00BA9F4
F00BA99C: 90122010                 bset    0x10, %o0
F00BA9A0: 02800013                 be      loc_F00BA9EC
F00BA9A4: 11004000                 sethi   0x1000000, %o0
F00BA9A8: d204203c                 ld      [%l0+0x3C], %o1
F00BA9AC: 808a4008                 btst    %o0, %o1
F00BA9B0: 32800010                 bne,a   loc_F00BA9F0
F00BA9B4: d0042040                 ld      [%l0+0x40], %o0
F00BA9B8: d0542044                 ldsh    [%l0+0x44], %o0
F00BA9BC: 7ffd5ac8                 call    _gsignal
F00BA9C0: 92102001                 mov     1, %o1
F00BA9C4: d0542044                 ldsh    [%l0+0x44], %o0
F00BA9C8: 7ffd5ac5                 call    _gsignal
F00BA9CC: 92102013                 mov     0x13, %o1
F00BA9D0: 90100010                 mov     %l0, %o0
F00BA9D4: 92102080                 mov     0x80, %o1
F00BA9D8: 7ffffeb9                 call    _zsmctl
F00BA9DC: 94102002                 mov     2, %o2! int
F00BA9E0: 90100010                 mov     %l0, %o0
F00BA9E4: 7ffd7013                 call    _ttyflush
F00BA9E8: 92102003                 mov     3, %o1
F00BA9EC: d0042040                 ld      [%l0+0x40], %o0
F00BA9F0: 900a3fef                 and     %o0, -0x11, %o0
F00BA9F4: d0242040                 st      %o0, [%l0+0x40]
F00BA9F8: d0562008                 ldsh    [%i0+8], %o0
F00BA9FC: 80a22000                 cmp     %o0, 0
F00BAA00: 22800006                 be,a    loc_F00BAA18
F00BAA04: d0562006                 ldsh    [%i0+6], %o0
F00BAA08: c0362008                 clrh    [%i0+8]
F00BAA0C: c0362110                 clrh    [%i0+0x110]
F00BAA10: c0362112                 clrh    [%i0+0x112]
F00BAA14: d0562006                 ldsh    [%i0+6], %o0
F00BAA18: 80a22000                 cmp     %o0, 0
F00BAA1C: 22800032                 be,a    loc_F00BAAE4
F00BAA20: a2102000                 mov     0, %l1
F00BAA24: d00c4000                 ldub    [%l1], %o0
F00BAA28: 808a2080                 btst    0x80, %o0
F00BAA2C: 3280002e                 bne,a   loc_F00BAAE4
F00BAA30: a2102000                 mov     0, %l1
F00BAA34: c0362006                 clrh    [%i0+6]
F00BAA38: d2542038                 ldsh    [%l0+0x38], %o1! int
F00BAA3C: 113c0483                 sethi   %hi(_kbddev), %o0
F00BAA40: d0522224                 ldsh    [%o0+%lo(_kbddev)], %o0
F00BAA44: 80a24008                 cmp     %o1, %o0
F00BAA48: 1280000b                 bne     loc_F00BAA74
F00BAA4C: 90100009                 mov     %o1, %o0
F00BAA50: 113c04fb                 sethi   %hi(_rconsdev), %o0
F00BAA54: d0522248                 ldsh    [%o0+%lo(_rconsdev)], %o0! int
F00BAA58: 80a24008                 cmp     %o1, %o0
F00BAA5C: 12800022                 bne     loc_F00BAAE4
F00BAA60: a2102000                 mov     0, %l1
F00BAA64: 4000195a                 call    _kbdreset
F00BAA68: 90100010                 mov     %l0, %o0
F00BAA6C: 1080001e                 ba      loc_F00BAAE4
F00BAA70: a2102000                 mov     0, %l1
F00BAA74: 900a201f                 and     %o0, 0x1F, %o0
F00BAA78: 80a22003                 cmp     %o0, 3
F00BAA7C: 32800006                 bne,a   loc_F00BAA94
F00BAA80: d0042040                 ld      [%l0+0x40], %o0
F00BAA84: 400020dc                 call    _mstrynextbaudrate
F00BAA88: 90100010                 mov     %l0, %o0
F00BAA8C: 10800016                 ba      loc_F00BAAE4
F00BAA90: a2102000                 mov     0, %l1
F00BAA94: 808a2004                 btst    4, %o0
F00BAA98: 02800013                 be      loc_F00BAAE4
F00BAA9C: a2102000                 mov     0, %l1
F00BAAA0: d004203c                 ld      [%l0+0x3C], %o0
F00BAAA4: 808a2020                 btst    0x20, %o0 ! ' '
F00BAAA8: 12800003                 bne     loc_F00BAAB4
F00BAAAC: 96102000                 mov     0, %o3
F00BAAB0: d60c204f                 ldub    [%l0+0x4F], %o3
F00BAAB4: d44c2047                 ldsb    [%l0+0x47], %o2
F00BAAB8: 932aa001                 sll     %o2, 1, %o1
F00BAABC: 9202400a                 add     %o1, %o2, %o1
F00BAAC0: 932a6004                 sll     %o1, 4, %o1
F00BAAC4: 153c042e9412a0cc         set     _linesw, %o2
F00BAACC: 9202400a                 add     %o1, %o2, %o1
F00BAAD0: d4026014                 ld      [%o1+0x14], %o2
F00BAAD4: 9010000b                 mov     %o3, %o0
F00BAAD8: 9fc28000                 call    %o2
F00BAADC: 92100010                 mov     %l0, %o1
F00BAAE0: a2102000                 mov     0, %l1
F00BAAE4: 113c042ea41220cc         set     _linesw, %l2
F00BAAEC: d4562112                 ldsh    [%i0+0x112], %o2
F00BAAF0: d0562110                 ldsh    [%i0+0x110], %o0
F00BAAF4: 80a28008                 cmp     %o2, %o0
F00BAAF8: 02800028                 be      loc_F00BAB98
F00BAAFC: 9210000a                 mov     %o2, %o1
F00BAB00: 92026001                 inc     %o1
F00BAB04: d2362112                 sth     %o1, [%i0+0x112]
F00BAB08: 9006000a                 add     %i0, %o2, %o0
F00BAB0C: 932a6010                 sll     %o1, 16, %o1
F00BAB10: 933a6010                 sra     %o1, 16, %o1
F00BAB14: 80a260ff                 cmp     %o1, 0xFF
F00BAB18: 04800003                 ble     loc_F00BAB24
F00BAB1C: d60a200f                 ldub    [%o0+0xF], %o3
F00BAB20: c0362112                 clrh    [%i0+0x112]
F00BAB24: d0042040                 ld      [%l0+0x40], %o0
F00BAB28: 808a2004                 btst    4, %o0
F00BAB2C: 2280001c                 be,a    loc_F00BAB9C
F00BAB30: d0562118                 ldsh    [%i0+0x118], %o0
F00BAB34: d0142038                 lduh    [%l0+0x38], %o0
F00BAB38: 900a201f                 and     %o0, 0x1F, %o0
F00BAB3C: 80a22003                 cmp     %o0, 3
F00BAB40: 12800007                 bne     loc_F00BAB5C
F00BAB44: 80a22002                 cmp     %o0, 2
F00BAB48: 9010000b                 mov     %o3, %o0
F00BAB4C: 40001ee7                 call    _msinput
F00BAB50: 92100010                 mov     %l0, %o1
F00BAB54: 10800012                 ba      loc_F00BAB9C
F00BAB58: d0562118                 ldsh    [%i0+0x118], %o0
F00BAB5C: 32800007                 bne,a   loc_F00BAB78
F00BAB60: d24c2047                 ldsb    [%l0+0x47], %o1
F00BAB64: 9010000b                 mov     %o3, %o0
F00BAB68: 40001abe                 call    _kbdIntHandler
F00BAB6C: 92100010                 mov     %l0, %o1
F00BAB70: 1080000b                 ba      loc_F00BAB9C
F00BAB74: d0562118                 ldsh    [%i0+0x118], %o0
F00BAB78: 9010000b                 mov     %o3, %o0
F00BAB7C: 952a6001                 sll     %o1, 1, %o2
F00BAB80: 94028009                 add     %o2, %o1, %o2
F00BAB84: 952aa004                 sll     %o2, 4, %o2
F00BAB88: 94028012                 add     %o2, %l2, %o2
F00BAB8C: d402a014                 ld      [%o2+0x14], %o2
F00BAB90: 9fc28000                 call    %o2
F00BAB94: 92100010                 mov     %l0, %o1
F00BAB98: d0562118                 ldsh    [%i0+0x118], %o0
F00BAB9C: 80a22000                 cmp     %o0, 0
F00BABA0: 3480001b                 bg,a    loc_F00BAC0C
F00BABA4: d2562112                 ldsh    [%i0+0x112], %o1
F00BABA8: d0042040                 ld      [%l0+0x40], %o0
F00BABAC: 808a2020                 btst    0x20, %o0 ! ' '
F00BABB0: 22800017                 be,a    loc_F00BAC0C
F00BABB4: d2562112                 ldsh    [%i0+0x112], %o1
F00BABB8: d256211a                 ldsh    [%i0+0x11A], %o1
F00BABBC: 7ffd8793                 call    _ndflush
F00BABC0: 90042018                 add     %l0, 0x18, %o0
F00BABC4: d0042040                 ld      [%l0+0x40], %o0
F00BABC8: d24c2047                 ldsb    [%l0+0x47], %o1
F00BABCC: 900a3fdf                 and     %o0, -0x21, %o0
F00BABD0: 80a26000                 cmp     %o1, 0
F00BABD4: 0280000b                 be      loc_F00BAC00
F00BABD8: d0242040                 st      %o0, [%l0+0x40]
F00BABDC: 912a6001                 sll     %o1, 1, %o0
F00BABE0: 90020009                 add     %o0, %o1, %o0
F00BABE4: 912a2004                 sll     %o0, 4, %o0
F00BABE8: 90020012                 add     %o0, %l2, %o0
F00BABEC: d2022020                 ld      [%o0+0x20], %o1
F00BABF0: 9fc24000                 call    %o1
F00BABF4: 90100010                 mov     %l0, %o0
F00BABF8: 10800005                 ba      loc_F00BAC0C
F00BABFC: d2562112                 ldsh    [%i0+0x112], %o1
F00BAC00: 7ffffdb8                 call    _zsstart
F00BAC04: 90100010                 mov     %l0, %o0
F00BAC08: d2562112                 ldsh    [%i0+0x112], %o1
F00BAC0C: d0562110                 ldsh    [%i0+0x110], %o0
F00BAC10: 80a24008                 cmp     %o1, %o0
F00BAC14: 02800008                 be      loc_F00BAC34
F00BAC18: 90046001                 add     %l1, 1, %o0
F00BAC1C: a2100008                 mov     %o0, %l1
F00BAC20: 912a2010                 sll     %o0, 16, %o0
F00BAC24: 913a2010                 sra     %o0, 16, %o0
F00BAC28: 80a22013                 cmp     %o0, 0x13
F00BAC2C: 24bfffb1                 ble,a   loc_F00BAAF0
F00BAC30: d4562112                 ldsh    [%i0+0x112], %o2
F00BAC34: 912c6010                 sll     %l1, 16, %o0
F00BAC38: 913a2010                 sra     %o0, 16, %o0
F00BAC3C: 80a22013                 cmp     %o0, 0x13
F00BAC40: 34800003                 bg,a    locret_F00BAC4C
F00BAC44: b0102001                 mov     1, %i0
F00BAC48: b0102000                 mov     0, %i0
F00BAC4C: 81c7e008                 ret
F00BAC50: 81e80000                 restore
