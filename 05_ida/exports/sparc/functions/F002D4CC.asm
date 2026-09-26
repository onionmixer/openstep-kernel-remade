F002D4CC: 9de3bf98                 save    %sp, -0x68, %sp
F002D4D0: 113c00b5901220cc         set     _arptimer, %o0! int
F002D4D8: 133c043e                 sethi   %hi(_hz), %o1
F002D4DC: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F002D4E0: a4102000                 mov     0, %l2
F002D4E4: 952a6004                 sll     %o1, 4, %o2
F002D4E8: 94228009                 sub     %o2, %o1, %o2
F002D4EC: 92102000                 mov     0, %o1
F002D4F0: 7fff72ce                 call    _timeout
F002D4F4: 952aa002                 sll     %o2, 2, %o2
F002D4F8: 113c04d5a2122270         set     _arptab, %l1
F002D500: a004600b                 add     %l1, 0xB, %l0
F002D504: d00c0000                 ldub    [%l0], %o0
F002D508: 80a22000                 cmp     %o0, 0
F002D50C: 22800014                 be,a    loc_F002D55C
F002D510: a404a001                 inc     %l2
F002D514: 808a2004                 btst    4, %o0
F002D518: 32800011                 bne,a   loc_F002D55C
F002D51C: a404a001                 inc     %l2
F002D520: d00c3fff                 ldub    [%l0-1], %o0
F002D524: d20c0000                 ldub    [%l0], %o1
F002D528: 90022001                 inc     %o0
F002D52C: d02c3fff                 stb     %o0, [%l0-1]
F002D530: 808a6002                 btst    2, %o1
F002D534: 02800004                 be      loc_F002D544
F002D538: 900a20ff                 and     %o0, 0xFF, %o0
F002D53C: 10800003                 ba      loc_F002D548
F002D540: 80a22013                 cmp     %o0, 0x13
F002D544: 80a22002                 cmp     %o0, 2
F002D548: 24800005                 ble,a   loc_F002D55C
F002D54C: a404a001                 inc     %l2
F002D550: 40000271                 call    _arptfree
F002D554: 90100011                 mov     %l1, %o0
F002D558: a404a001                 inc     %l2
F002D55C: a0042014                 inc     0x14, %l0
F002D560: 80a4a0aa                 cmp     %l2, 0xAA
F002D564: 04bfffe8                 ble     loc_F002D504
F002D568: a2046014                 inc     0x14, %l1
F002D56C: 81c7e008                 ret
F002D570: 81e80000                 restore
