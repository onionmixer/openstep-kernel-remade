F00CC524: 9de3bf90                 save    %sp, -0x70, %sp
F00CC528: 113c0504                 sethi   %hi(paConfigtable_0), %o0! id
F00CC52C: d2022310                 ld      [%o0+%lo(paConfigtable_0)], %o1! SEL
F00CC530: a4100018                 mov     %i0, %l2
F00CC534: 400094cf                 call    _objc_msgSend
F00CC538: 9010001a                 mov     %i2, %o0
F00CC53C: b4920000                 orcc    %o0, %g0, %i2
F00CC540: 12800013                 bne     loc_F00CC58C
F00CC544: 9010001a                 mov     %i2, %o0
F00CC548: 90100012                 mov     %l2, %o0! id
F00CC54C: 133c0504                 sethi   %hi(paName), %o1
F00CC550: 213c03ec                 sethi   %hi(aSCouldnTGetIns), %l0! "%s: couldn't get Instance%d.table\n"
F00CC554: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CC558: 400094c6                 call    _objc_msgSend
F00CC55C: a0142120                 bset    %lo(aSCouldnTGetIns), %l0! "%s: couldn't get Instance%d.table\n"
F00CC560: 133c0506                 sethi   %hi(paUnit_0), %o1
F00CC564: a2100008                 mov     %o0, %l1
F00CC568: d2026138                 ld      [%o1+%lo(paUnit_0)], %o1! SEL
F00CC56C: 400094c1                 call    _objc_msgSend
F00CC570: 90100012                 mov     %l2, %o0
F00CC574: 94100008                 mov     %o0, %o2
F00CC578: 90100010                 mov     %l0, %o0! id
F00CC57C: 7fffe6de                 call    _IOLog
F00CC580: 92100011                 mov     %l1, %o1
F00CC584: 10800073                 ba      locret_F00CC750
F00CC588: b0102001                 mov     1, %i0
F00CC58C: 133c0504                 sethi   %hi(paValueforstring), %o1
F00CC590: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00CC594: 153c03e5                 sethi   %hi(aRingSpeed), %o2! "Ring Speed"
F00CC598: 400094b6                 call    _objc_msgSend
F00CC59C: 9412a1b8                 bset    %lo(aRingSpeed), %o2! "Ring Speed"
F00CC5A0: b0100008                 mov     %o0, %i0
F00CC5A4: 133c03ec                 sethi   %hi(a4), %o1! "4"
F00CC5A8: 7ffcef01                 call    _strcmp
F00CC5AC: 92126148                 bset    %lo(a4), %o1! "4"
F00CC5B0: 80a22000                 cmp     %o0, 0
F00CC5B4: 12800004                 bne     loc_F00CC5C4
F00CC5B8: 90100018                 mov     %i0, %o0
F00CC5BC: 10800011                 ba      loc_F00CC600
F00CC5C0: 90102004                 mov     4, %o0! __s1
F00CC5C4: 133c03ec                 sethi   %hi(a16), %o1! "16"
F00CC5C8: 7ffceef9                 call    _strcmp
F00CC5CC: 92126150                 bset    %lo(a16), %o1! "16"
F00CC5D0: 80a22000                 cmp     %o0, 0
F00CC5D4: 0280000a                 be      loc_F00CC5FC
F00CC5D8: 90100012                 mov     %l2, %o0! id
F00CC5DC: 133c0504                 sethi   %hi(paName), %o1
F00CC5E0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CC5E4: 213c03ec                 sethi   %hi(aSInvalidRingSp), %l0! "%s: invalid ring speed in Instance.tabl"...
F00CC5E8: 400094a2                 call    _objc_msgSend
F00CC5EC: a0142158                 bset    %lo(aSInvalidRingSp), %l0! "%s: invalid ring speed in Instance.tabl"...
F00CC5F0: 92100008                 mov     %o0, %o1
F00CC5F4: 7fffe6c0                 call    _IOLog
F00CC5F8: 90100010                 mov     %l0, %o0
F00CC5FC: 90102010                 mov     0x10, %o0
F00CC600: d024a12c                 st      %o0, [%l2+0x12C]
F00CC604: 9010001a                 mov     %i2, %o0! id
F00CC608: 133c0504                 sethi   %hi(paFreestring), %o1! SEL
F00CC60C: e20260f4                 ld      [%o1+%lo(paFreestring)], %l1
F00CC610: 94100018                 mov     %i0, %o2
F00CC614: 40009497                 call    _objc_msgSend
F00CC618: 92100011                 mov     %l1, %o1
F00CC61C: 9010001a                 mov     %i2, %o0! id
F00CC620: 133c0504                 sethi   %hi(paValueforstring), %o1! SEL
F00CC624: 153c03e5                 sethi   %hi(aNodeAddress), %o2! "Node Address"
F00CC628: e00260e8                 ld      [%o1+%lo(paValueforstring)], %l0
F00CC62C: 9412a1c8                 bset    %lo(aNodeAddress), %o2! "Node Address"
F00CC630: 40009490                 call    _objc_msgSend
F00CC634: 92100010                 mov     %l0, %o1
F00CC638: b0100008                 mov     %o0, %i0
F00CC63C: 9010001a                 mov     %i2, %o0! id
F00CC640: 92100011                 mov     %l1, %o1! SEL
F00CC644: 4000948b                 call    _objc_msgSend
F00CC648: 94100018                 mov     %i0, %o2
F00CC64C: 9010001a                 mov     %i2, %o0! id
F00CC650: 92100010                 mov     %l0, %o1! SEL
F00CC654: 153c03e5                 sethi   %hi(a16mbEarlyToken), %o2! "16Mb Early Token"
F00CC658: 40009486                 call    _objc_msgSend
F00CC65C: 9412a200                 bset    %lo(a16mbEarlyToken), %o2! "16Mb Early Token"
F00CC660: b0100008                 mov     %o0, %i0
F00CC664: 133c03ec                 sethi   %hi(aYes), %o1! "YES"
F00CC668: 7ffceed1                 call    _strcmp
F00CC66C: 92126188                 bset    %lo(aYes), %o1! "YES"
F00CC670: 80a22000                 cmp     %o0, 0
F00CC674: 32800006                 bne,a   loc_F00CC68C
F00CC678: d204a128                 ld      [%l2+0x128], %o1
F00CC67C: d004a128                 ld      [%l2+0x128], %o0
F00CC680: 13100000                 sethi   0x40000000, %o1
F00CC684: 10800004                 ba      loc_F00CC694
F00CC688: 90120009                 bset    %o1, %o0
F00CC68C: 11100000                 sethi   0x40000000, %o0
F00CC690: 902a4008                 andn    %o1, %o0, %o0
F00CC694: d024a128                 st      %o0, [%l2+0x128]
F00CC698: 9010001a                 mov     %i2, %o0! id
F00CC69C: 133c0504                 sethi   %hi(paFreestring), %o1
F00CC6A0: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00CC6A4: 40009473                 call    _objc_msgSend
F00CC6A8: 94100018                 mov     %i0, %o2
F00CC6AC: 9010001a                 mov     %i2, %o0! id
F00CC6B0: 133c0504                 sethi   %hi(paValueforstring), %o1
F00CC6B4: 153c03e5                 sethi   %hi(aAutoRecovery), %o2! "Auto Recovery"
F00CC6B8: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00CC6BC: 4000946d                 call    _objc_msgSend
F00CC6C0: 9412a218                 bset    %lo(aAutoRecovery), %o2! "Auto Recovery"
F00CC6C4: b0100008                 mov     %o0, %i0
F00CC6C8: 133c03ec                 sethi   %hi(aYes), %o1! "YES"
F00CC6CC: 7ffceeb8                 call    _strcmp
F00CC6D0: 92126188                 bset    %lo(aYes), %o1! "YES"
F00CC6D4: 80a22000                 cmp     %o0, 0
F00CC6D8: 32800006                 bne,a   loc_F00CC6F0
F00CC6DC: d204a128                 ld      [%l2+0x128], %o1
F00CC6E0: d004a128                 ld      [%l2+0x128], %o0
F00CC6E4: 13080000                 sethi   0x20000000, %o1
F00CC6E8: 10800004                 ba      loc_F00CC6F8
F00CC6EC: 90120009                 bset    %o1, %o0
F00CC6F0: 11080000                 sethi   0x20000000, %o0
F00CC6F4: 902a4008                 andn    %o1, %o0, %o0
F00CC6F8: d024a128                 st      %o0, [%l2+0x128]
F00CC6FC: 9010001a                 mov     %i2, %o0! id
F00CC700: 133c0504                 sethi   %hi(paFreestring), %o1
F00CC704: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00CC708: 4000945a                 call    _objc_msgSend
F00CC70C: 94100018                 mov     %i0, %o2
F00CC710: 11000007901223a4         set     0x1FA4, %o0
F00CC718: d024a134                 st      %o0, [%l2+0x134]
F00CC71C: 90102008                 mov     8, %o0
F00CC720: d024a130                 st      %o0, [%l2+0x130]
F00CC724: 113c0432                 sethi   %hi(_ipforwarding), %o0
F00CC728: c022202c                 clr     [%o0+%lo(_ipforwarding)]
F00CC72C: b0102000                 mov     0, %i0
F00CC730: d004a128                 ld      [%l2+0x128], %o0
F00CC734: 13040000                 sethi   0x10000000, %o1
F00CC738: 90120009                 bset    %o1, %o0
F00CC73C: d024a128                 st      %o0, [%l2+0x128]
F00CC740: d004a128                 ld      [%l2+0x128], %o0
F00CC744: 13010000                 sethi   0x4000000, %o1
F00CC748: 90120009                 bset    %o1, %o0
F00CC74C: d024a128                 st      %o0, [%l2+0x128]
F00CC750: 81c7e008                 ret
F00CC754: 81e80000                 restore
