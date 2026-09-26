F00E9674: 9de3bf88                 save    %sp, -0x78, %sp
F00E9678: d00621fc                 ld      [%i0+0x1FC], %o0
F00E967C: 7fff65f5                 call    _ev_try_lock
F00E9680: 90022004                 inc     4, %o0
F00E9684: 80a22000                 cmp     %o0, 0
F00E9688: 028000a0                 be      locret_F00E9908
F00E968C: 01000000                 nop
F00E9690: d00621fc                 ld      [%i0+0x1FC], %o0
F00E9694: d40a2008                 ldub    [%o0+8], %o2
F00E9698: 9202a001                 add     %o2, 1, %o1
F00E969C: d22a2008                 stb     %o1, [%o0+8]
F00E96A0: 80a2a000                 cmp     %o2, 0
F00E96A4: 32800097                 bne,a   loc_F00E9900
F00E96A8: d00621fc                 ld      [%i0+0x1FC], %o0! id
F00E96AC: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E96B0: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E96B4: 4000206f                 call    _objc_msgSend
F00E96B8: 90100018                 mov     %i0, %o0
F00E96BC: d0022018                 ld      [%o0+0x18], %o0
F00E96C0: 80a22003                 cmp     %o0, 3
F00E96C4: 18800008                 bgu     loc_F00E96E4
F00E96C8: 80a22002                 cmp     %o0, 2
F00E96CC: 1a80008c                 bcc     loc_F00E98FC
F00E96D0: 80a22001                 cmp     %o0, 1
F00E96D4: 02800009                 be      loc_F00E96F8
F00E96D8: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1
F00E96DC: 10800089                 ba      loc_F00E9900
F00E96E0: d00621fc                 ld      [%i0+0x1FC], %o0
F00E96E4: 80a22004                 cmp     %o0, 4
F00E96E8: 0280004a                 be      loc_F00E9810
F00E96EC: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E96F0: 10800084                 ba      loc_F00E9900
F00E96F4: d00621fc                 ld      [%i0+0x1FC], %o0! id
F00E96F8: 4000205e                 call    _objc_msgSend
F00E96FC: 90100018                 mov     %i0, %o0
F00E9700: e00621fc                 ld      [%i0+0x1FC], %l0
F00E9704: d214200c                 lduh    [%l0+0xC], %o1
F00E9708: d237bfe8                 sth     %o1, [%fp+var_18]
F00E970C: d214200e                 lduh    [%l0+0xE], %o1
F00E9710: d237bfea                 sth     %o1, [%fp+var_16]
F00E9714: d4142010                 lduh    [%l0+0x10], %o2
F00E9718: a2100008                 mov     %o0, %l1
F00E971C: d437bfec                 sth     %o2, [%fp+var_14]
F00E9720: d2142012                 lduh    [%l0+0x12], %o1
F00E9724: 952aa010                 sll     %o2, 16, %o2
F00E9728: d237bfee                 sth     %o1, [%fp+var_12]
F00E972C: e4046008                 ld      [%l1+8], %l2
F00E9730: 953aa010                 sra     %o2, 16, %o2
F00E9734: d2142034                 lduh    [%l0+0x34], %o1
F00E9738: 90100012                 mov     %l2, %o0
F00E973C: 932a6010                 sll     %o1, 16, %o1
F00E9740: 933a6010                 sra     %o1, 16, %o1
F00E9744: 7ffc736f                 call    _umul
F00E9748: 92228009                 sub     %o2, %o1, %o1
F00E974C: d4046014                 ld      [%l1+0x14], %o2
F00E9750: d2142030                 lduh    [%l0+0x30], %o1
F00E9754: 9a042848                 add     %l0, 0x848, %o5
F00E9758: d617bfea                 lduh    [%fp+var_16], %o3
F00E975C: 94028008                 add     %o2, %o0, %o2
F00E9760: 932a6010                 sll     %o1, 16, %o1
F00E9764: d057bfe8                 ldsh    [%fp+var_18], %o0
F00E9768: 933a6010                 sra     %o1, 16, %o1
F00E976C: 92220009                 sub     %o0, %o1, %o1
F00E9770: 98028009                 add     %o2, %o1, %o4
F00E9774: 9622c008                 sub     %o3, %o0, %o3
F00E9778: 932ae010                 sll     %o3, 16, %o1
F00E977C: 933a6010                 sra     %o1, 16, %o1
F00E9780: d017bfee                 lduh    [%fp+var_12], %o0
F00E9784: d417bfec                 lduh    [%fp+var_14], %o2
F00E9788: 9022000a                 sub     %o0, %o2, %o0
F00E978C: 90023fff                 inc     -1, %o0
F00E9790: 84100008                 mov     %o0, %g2
F00E9794: 912a2010                 sll     %o0, 16, %o0
F00E9798: 913a2010                 sra     %o0, 16, %o0
F00E979C: 80a23fff                 cmp     %o0, -1
F00E97A0: 02800057                 be      loc_F00E98FC
F00E97A4: a4248009                 sub     %l2, %o1, %l2
F00E97A8: 9002ffff                 add     %o3, -1, %o0
F00E97AC: 94100008                 mov     %o0, %o2
F00E97B0: 912a2010                 sll     %o0, 16, %o0
F00E97B4: 913a2010                 sra     %o0, 16, %o0
F00E97B8: 80a23fff                 cmp     %o0, -1
F00E97BC: 0280000d                 be      loc_F00E97F0
F00E97C0: 9000bfff                 add     %g2, -1, %o0
F00E97C4: 9002bfff                 add     %o2, -1, %o0
F00E97C8: 94100008                 mov     %o0, %o2
F00E97CC: d20b4000                 ldub    [%o5], %o1! SEL
F00E97D0: 912a2010                 sll     %o0, 16, %o0
F00E97D4: 913a2010                 sra     %o0, 16, %o0
F00E97D8: 80a23fff                 cmp     %o0, -1
F00E97DC: d22b0000                 stb     %o1, [%o4]
F00E97E0: 9a036001                 inc     %o5
F00E97E4: 12bffff8                 bne     loc_F00E97C4
F00E97E8: 98032001                 inc     %o4
F00E97EC: 9000bfff                 add     %g2, -1, %o0
F00E97F0: 84100008                 mov     %o0, %g2
F00E97F4: 912a2010                 sll     %o0, 16, %o0
F00E97F8: 913a2010                 sra     %o0, 16, %o0
F00E97FC: 80a23fff                 cmp     %o0, -1
F00E9800: 12bfffea                 bne     loc_F00E97A8
F00E9804: 98030012                 add     %o4, %l2, %o4
F00E9808: 1080003e                 ba      loc_F00E9900
F00E980C: d00621fc                 ld      [%i0+0x1FC], %o0! id
F00E9810: 40002018                 call    _objc_msgSend
F00E9814: 90100018                 mov     %i0, %o0
F00E9818: e00621fc                 ld      [%i0+0x1FC], %l0
F00E981C: d214200c                 lduh    [%l0+0xC], %o1
F00E9820: d237bfe8                 sth     %o1, [%fp+var_18]
F00E9824: d214200e                 lduh    [%l0+0xE], %o1
F00E9828: d237bfea                 sth     %o1, [%fp+var_16]
F00E982C: d4142010                 lduh    [%l0+0x10], %o2
F00E9830: a2100008                 mov     %o0, %l1
F00E9834: d437bfec                 sth     %o2, [%fp+var_14]
F00E9838: d2142012                 lduh    [%l0+0x12], %o1
F00E983C: 952aa010                 sll     %o2, 16, %o2
F00E9840: d237bfee                 sth     %o1, [%fp+var_12]
F00E9844: e4046008                 ld      [%l1+8], %l2
F00E9848: 953aa010                 sra     %o2, 16, %o2
F00E984C: d2142034                 lduh    [%l0+0x34], %o1
F00E9850: 90100012                 mov     %l2, %o0
F00E9854: 932a6010                 sll     %o1, 16, %o1
F00E9858: 933a6010                 sra     %o1, 16, %o1
F00E985C: 7ffc7329                 call    _umul
F00E9860: 92228009                 sub     %o2, %o1, %o1
F00E9864: 1300000492126048         set     0x1048, %o1
F00E986C: d4046014                 ld      [%l1+0x14], %o2
F00E9870: 98040009                 add     %l0, %o1, %o4
F00E9874: d2142030                 lduh    [%l0+0x30], %o1
F00E9878: 912a2002                 sll     %o0, 2, %o0
F00E987C: d657bfe8                 ldsh    [%fp+var_18], %o3
F00E9880: 94028008                 add     %o2, %o0, %o2
F00E9884: 932a6010                 sll     %o1, 16, %o1
F00E9888: 933a6010                 sra     %o1, 16, %o1
F00E988C: 9222c009                 sub     %o3, %o1, %o1
F00E9890: 932a6002                 sll     %o1, 2, %o1
F00E9894: d057bfea                 ldsh    [%fp+var_16], %o0
F00E9898: 94028009                 add     %o2, %o1, %o2
F00E989C: d257bfee                 ldsh    [%fp+var_12], %o1
F00E98A0: 9a22000b                 sub     %o0, %o3, %o5
F00E98A4: d057bfec                 ldsh    [%fp+var_14], %o0
F00E98A8: 92224008                 sub     %o1, %o0, %o1
F00E98AC: 92027fff                 inc     -1, %o1
F00E98B0: 80a27fff                 cmp     %o1, -1
F00E98B4: 02800012                 be      loc_F00E98FC
F00E98B8: a424800d                 sub     %l2, %o5, %l2
F00E98BC: 852ca002                 sll     %l2, 2, %g2
F00E98C0: 96037fff                 add     %o5, -1, %o3
F00E98C4: 80a2ffff                 cmp     %o3, -1
F00E98C8: 2280000a                 be,a    loc_F00E98F0
F00E98CC: 92027fff                 inc     -1, %o1
F00E98D0: 9602ffff                 inc     -1, %o3
F00E98D4: d0030000                 ld      [%o4], %o0
F00E98D8: 80a2ffff                 cmp     %o3, -1
F00E98DC: d0228000                 st      %o0, [%o2]
F00E98E0: 98032004                 inc     4, %o4
F00E98E4: 12bffffb                 bne     loc_F00E98D0
F00E98E8: 9402a004                 inc     4, %o2
F00E98EC: 92027fff                 inc     -1, %o1
F00E98F0: 80a27fff                 cmp     %o1, -1
F00E98F4: 12bffff3                 bne     loc_F00E98C0
F00E98F8: 94028002                 add     %o2, %g2, %o2
F00E98FC: d00621fc                 ld      [%i0+0x1FC], %o0
F00E9900: 7fff6552                 call    _ev_unlock
F00E9904: 90022004                 inc     4, %o0
F00E9908: 81c7e008                 ret
F00E990C: 81e80000                 restore
