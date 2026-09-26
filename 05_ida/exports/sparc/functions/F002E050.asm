F002E050: 9de3bf98                 save    %sp, -0x68, %sp
F002E054: d0164000                 lduh    [%i1], %o0
F002E058: 80a22002                 cmp     %o0, 2
F002E05C: 12800006                 bne     loc_F002E074
F002E060: a4102000                 mov     0, %l2
F002E064: d0166010                 lduh    [%i1+0x10], %o0
F002E068: 80a22000                 cmp     %o0, 0
F002E06C: 02800004                 be      loc_F002E07C
F002E070: 01000000                 nop
F002E074: 10800073                 ba      locret_F002E240
F002E078: b010202f                 mov     0x2F, %i0 ! '/'
F002E07C: 4001a2cf                 call    _spltty
F002E080: a8100019                 mov     %i1, %l4
F002E084: 92102013                 mov     0x13, %o1
F002E088: e0066004                 ld      [%i1+4], %l0
F002E08C: a6100008                 mov     %o0, %l3
F002E090: 7fff6204                 call    _urem
F002E094: 90100010                 mov     %l0, %o0
F002E098: 932a2001                 sll     %o0, 1, %o1
F002E09C: 92024008                 add     %o1, %o0, %o1
F002E0A0: 952a6004                 sll     %o1, 4, %o2
F002E0A4: 94228009                 sub     %o2, %o1, %o2
F002E0A8: 952aa002                 sll     %o2, 2, %o2! size_t
F002E0AC: 113c04d590122270         set     _arptab, %o0
F002E0B4: a2028008                 add     %o2, %o0, %l1
F002E0B8: 92102000                 mov     0, %o1
F002E0BC: d0044000                 ld      [%l1], %o0
F002E0C0: 80a20010                 cmp     %o0, %l0
F002E0C4: 02800007                 be      loc_F002E0E0
F002E0C8: 80a26008                 cmp     %o1, 8
F002E0CC: 92026001                 inc     %o1
F002E0D0: 80a26008                 cmp     %o1, 8
F002E0D4: 04bffffa                 ble     loc_F002E0BC
F002E0D8: a2046014                 inc     0x14, %l1
F002E0DC: 80a26008                 cmp     %o1, 8
F002E0E0: 34800002                 bg,a    loc_F002E0E8
F002E0E4: a2102000                 mov     0, %l1
F002E0E8: 80a46000                 cmp     %l1, 0
F002E0EC: 12800014                 bne     loc_F002E13C
F002E0F0: 1120091a                 sethi   -0x7FDB9800, %o0
F002E0F4: 1120091a9012211e         set     -0x7FDB96E2, %o0
F002E0FC: 80a60008                 cmp     %i0, %o0
F002E100: 02800006                 be      loc_F002E118
F002E104: 01000000                 nop
F002E108: 4001a307                 call    _splx
F002E10C: 90100013                 mov     %l3, %o0
F002E110: 1080004c                 ba      locret_F002E240
F002E114: b0102006                 mov     6, %i0
F002E118: 7fffee3e                 call    _ifa_ifwithnet
F002E11C: 90100019                 mov     %i1, %o0
F002E120: a4920000                 orcc    %o0, %g0, %l2
F002E124: 12800006                 bne     loc_F002E13C
F002E128: 1120091a                 sethi   -0x7FDB9800, %o0
F002E12C: 4001a2fe                 call    _splx
F002E130: 90100013                 mov     %l3, %o0
F002E134: 10800043                 ba      locret_F002E240
F002E138: b0102033                 mov     0x33, %i0 ! '3'
F002E13C: 90122120                 bset    0x120, %o0
F002E140: 80a60008                 cmp     %i0, %o0
F002E144: 02800034                 be      loc_F002E214
F002E148: 01000000                 nop
F002E14C: 14800008                 bg      loc_F002E16C
F002E150: 1130091a                 sethi   -0x3FDB9800, %o0
F002E154: 1120091a9012211e         set     -0x7FDB96E2, %o0
F002E15C: 80a60008                 cmp     %i0, %o0
F002E160: 02800008                 be      loc_F002E180
F002E164: 80a46000                 cmp     %l1, 0
F002E168: 30800033                 ba,a    loc_F002E234
F002E16C: 9012211f                 bset    0x11F, %o0
F002E170: 80a60008                 cmp     %i0, %o0
F002E174: 0280002b                 be      loc_F002E220
F002E178: 90046004                 add     %l1, 4, %o0
F002E17C: 3080002e                 ba,a    loc_F002E234
F002E180: 1280001c                 bne     loc_F002E1F0
F002E184: 90066012                 add     %i1, 0x12, %o0
F002E188: d004a020                 ld      [%l2+0x20], %o0
F002E18C: a0052004                 add     %l4, 4, %l0
F002E190: 7fffff72                 call    _arptnew
F002E194: 92100010                 mov     %l0, %o1
F002E198: a2920000                 orcc    %o0, %g0, %l1
F002E19C: 0280000e                 be      loc_F002E1D4
F002E1A0: 01000000                 nop
F002E1A4: d0066020                 ld      [%i1+0x20], %o0
F002E1A8: 808a2004                 btst    4, %o0
F002E1AC: 02800011                 be      loc_F002E1F0
F002E1B0: 90066012                 add     %i1, 0x12, %o0
F002E1B4: d0046010                 ld      [%l1+0x10], %o0
F002E1B8: 7fffff68                 call    _arptnew
F002E1BC: 92100010                 mov     %l0, %o1
F002E1C0: 80a22000                 cmp     %o0, 0
F002E1C4: 12800008                 bne     loc_F002E1E4
F002E1C8: 01000000                 nop
F002E1CC: 7fffff52                 call    _arptfree
F002E1D0: 90100011                 mov     %l1, %o0
F002E1D4: 4001a2d4                 call    _splx
F002E1D8: 90100013                 mov     %l3, %o0
F002E1DC: 10800019                 ba      locret_F002E240
F002E1E0: b0102031                 mov     0x31, %i0 ! '1'
F002E1E4: 7fffff4c                 call    _arptfree
F002E1E8: 01000000                 nop
F002E1EC: 90066012                 add     %i1, 0x12, %o0! void *
F002E1F0: 92046004                 add     %l1, 4, %o1! void *
F002E1F4: 40019a47                 call    _bcopy
F002E1F8: 94102006                 mov     6, %o2! size_t
F002E1FC: d0066020                 ld      [%i1+0x20], %o0
F002E200: 900a201c                 and     %o0, 0x1C, %o0
F002E204: 90122003                 bset    3, %o0
F002E208: d02c600b                 stb     %o0, [%l1+0xB]
F002E20C: 1080000a                 ba      loc_F002E234
F002E210: c02c600a                 clrb    [%l1+0xA]
F002E214: 7fffff40                 call    _arptfree
F002E218: 90100011                 mov     %l1, %o0! void *
F002E21C: 30800006                 ba,a    loc_F002E234
F002E220: 92066012                 add     %i1, 0x12, %o1! void *
F002E224: 40019a3b                 call    _bcopy
F002E228: 94102006                 mov     6, %o2
F002E22C: d00c600b                 ldub    [%l1+0xB], %o0
F002E230: d0266020                 st      %o0, [%i1+0x20]
F002E234: 4001a2bc                 call    _splx
F002E238: 90100013                 mov     %l3, %o0
F002E23C: b0102000                 mov     0, %i0
F002E240: 81c7e008                 ret
F002E244: 81e80000                 restore
