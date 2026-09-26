F00920F0: 9de3bf90                 save    %sp, -0x70, %sp
F00920F4: 912e2010                 sll     %i0, 16, %o0
F00920F8: 4000034f                 call    sub_F0092E34
F00920FC: 913a2010                 sra     %o0, 16, %o0
F0092100: a0920000                 orcc    %o0, %g0, %l0
F0092104: 0280000b                 be      loc_F0092130
F0092108: 90100010                 mov     %l0, %o0! id
F009210C: 133c0504                 sethi   %hi(paIsdiskready), %o1
F0092110: d2026164                 ld      [%o1+%lo(paIsdiskready)], %o1! SEL
F0092114: 940e6004                 and     %i1, 4, %o2
F0092118: 80a0000a                 cmp     %g0, %o2
F009211C: 40017dd5                 call    _objc_msgSend
F0092120: 94603fff                 subc    %g0, -1, %o2
F0092124: 80a22000                 cmp     %o0, 0
F0092128: 02800004                 be      loc_F0092138
F009212C: 333c04c4                 sethi   -0xFECF000, %i1
F0092130: 10800026                 ba      locret_F00921C8
F0092134: b0102006                 mov     6, %i0
F0092138: d0066248                 ld      [%i1+0x248], %o0
F009213C: 80a22000                 cmp     %o0, 0
F0092140: 12800011                 bne     loc_F0092184
F0092144: 900e2007                 and     %i0, 7, %o0
F0092148: 113c0449901220b0         set     unk_F01124B0, %o0
F0092150: 4000c934                 call    _IOGetObjectForDeviceName
F0092154: 9207bff4                 add     %fp, var_C, %o1
F0092158: 80a22000                 cmp     %o0, 0
F009215C: 02800004                 be      loc_F009216C
F0092160: 113c0449                 sethi   %hi(aSdopenCanTFind), %o0! "sdopen: can't find controller object"
F0092164: 4000cff0                 call    _IOPanic
F0092168: 901220b8                 bset    %lo(aSdopenCanTFind), %o0! "sdopen: can't find controller object"
F009216C: d007bff4                 ld      [%fp+var_C], %o0! id
F0092170: 133c0504                 sethi   %hi(paMaxtransfer), %o1! SEL
F0092174: 40017dbf                 call    _objc_msgSend
F0092178: d2026168                 ld      [%o1+%lo(paMaxtransfer)], %o1
F009217C: d0266248                 st      %o0, [%i1+0x248]
F0092180: 900e2007                 and     %i0, 7, %o0
F0092184: 80a22007                 cmp     %o0, 7
F0092188: 0280000f                 be      loc_F00921C4
F009218C: 912e2010                 sll     %i0, 16, %o0
F0092190: 133c04c4                 sethi   %hi(dword_F0131240), %o1
F0092194: d2026240                 ld      [%o1+%lo(dword_F0131240)], %o1
F0092198: 91322018                 srl     %o0, 24, %o0
F009219C: 80a20009                 cmp     %o0, %o1
F00921A0: 12800005                 bne     loc_F00921B4
F00921A4: 90100010                 mov     %l0, %o0! id
F00921A8: 133c0504                 sethi   %hi(paSetblockdevice), %o1
F00921AC: 10800004                 ba      loc_F00921BC
F00921B0: d202616c                 ld      [%o1+%lo(paSetblockdevice)], %o1
F00921B4: 133c0504                 sethi   %hi(paSetrawdeviceop), %o1
F00921B8: d2026170                 ld      [%o1+%lo(paSetrawdeviceop)], %o1! SEL
F00921BC: 40017dad                 call    _objc_msgSend
F00921C0: 94102001                 mov     1, %o2
F00921C4: b0102000                 mov     0, %i0
F00921C8: 81c7e008                 ret
F00921CC: 81e80000                 restore
