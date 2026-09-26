F0045048: 9de3bf98                 save    %sp, -0x68, %sp
F004504C: 400146db                 call    _spltty
F0045050: e0062030                 ld      [%i0+0x30], %l0
F0045054: a6102000                 mov     0, %l3
F0045058: a4042024                 add     %l0, 0x24, %l2 ! '$'
F004505C: d2040000                 ld      [%l0], %o1
F0045060: 808a6001                 btst    1, %o1
F0045064: 0280000c                 be      loc_F0045094
F0045068: a2100008                 mov     %o0, %l1
F004506C: 90126002                 or      %o1, 2, %o0
F0045070: d0240000                 st      %o0, [%l0]
F0045074: 90100010                 mov     %l0, %o0! unsigned int
F0045078: 7fff3580                 call    _sleep
F004507C: 92102017                 mov     0x17, %o1
F0045080: d2040000                 ld      [%l0], %o1
F0045084: 808a6001                 btst    1, %o1
F0045088: 12bffffa                 bne     loc_F0045070
F004508C: 90126002                 or      %o1, 2, %o0
F0045090: d2040000                 ld      [%l0], %o1
F0045094: 90100011                 mov     %l1, %o0
F0045098: 92126001                 bset    1, %o1
F004509C: 40014722                 call    _splx
F00450A0: d2240000                 st      %o1, [%l0]
F00450A4: 113c011490122018         set     sub_F0045018, %o0
F00450AC: 92100010                 mov     %l0, %o1
F00450B0: 170000089612e260         set     0x2260, %o3
F00450B8: d406202c                 ld      [%i0+0x2C], %o2
F00450BC: 7fff64a1                 call    _mclgetx
F00450C0: 98102001                 mov     1, %o4
F00450C4: a2920000                 orcc    %o0, %g0, %l1
F00450C8: 12800005                 bne     loc_F00450DC
F00450CC: 90042024                 add     %l0, 0x24, %o0 ! '$'
F00450D0: 7fffffd2                 call    sub_F0045018
F00450D4: 90100010                 mov     %l0, %o0
F00450D8: 30800028                 ba,a    locret_F0045178
F00450DC: 92100011                 mov     %l1, %o1
F00450E0: 400002d2                 call    _xdrmbuf_init
F00450E4: 94102000                 mov     0, %o2
F00450E8: 90100012                 mov     %l2, %o0! XDR *
F00450EC: d4042004                 ld      [%l0+4], %o2
F00450F0: 92100019                 mov     %i1, %o1! rpc_msg *
F00450F4: 7ffffba2                 call    _xdr_replymsg
F00450F8: d4224000                 st      %o2, [%o1]
F00450FC: 80a22000                 cmp     %o0, 0
F0045100: 22800013                 be,a    loc_F004514C
F0045104: 113c0437                 sethi   -0xFEF2400, %o0
F0045108: d004a004                 ld      [%l2+4], %o0
F004510C: d2022010                 ld      [%o0+0x10], %o1
F0045110: 9fc24000                 call    %o1
F0045114: 90100012                 mov     %l2, %o0
F0045118: d2044000                 ld      [%l1], %o1
F004511C: 80a26000                 cmp     %o1, 0
F0045120: 22800002                 be,a    loc_F0045128
F0045124: d0346008                 sth     %o0, [%l1+8]
F0045128: d0060000                 ld      [%i0], %o0
F004512C: 92100011                 mov     %l1, %o1
F0045130: 7ffffd44                 call    _ku_sendto_mbuf
F0045134: 94062010                 add     %i0, 0x10, %o2
F0045138: 80a22000                 cmp     %o0, 0
F004513C: 22800008                 be,a    loc_F004515C
F0045140: a6102001                 mov     1, %l3
F0045144: 10800007                 ba      loc_F0045160
F0045148: d004a008                 ld      [%l2+8], %o0! char *
F004514C: 7fff3d43                 call    _printf
F0045150: 90122268                 bset    0x268, %o0
F0045154: 7fff62c4                 call    _m_freem
F0045158: 90100011                 mov     %l1, %o0
F004515C: d004a008                 ld      [%l2+8], %o0
F0045160: 80a22000                 cmp     %o0, 0
F0045164: 02800005                 be      locret_F0045178
F0045168: 01000000                 nop
F004516C: d2020000                 ld      [%o0], %o1
F0045170: 9fc24000                 call    %o1
F0045174: 01000000                 nop
F0045178: 81c7e008                 ret
F004517C: 91e80013                 restore %g0, %l3, %o0
