F0044504: 9de3bf98                 save    %sp, -0x68, %sp
F0044508: d4062030                 ld      [%i0+0x30], %o2
F004450C: a2102000                 mov     0, %l1
F0044510: 80a2a000                 cmp     %o2, 0
F0044514: 12800004                 bne     loc_F0044524
F0044518: b0062024                 inc     0x24, %i0 ! '$'
F004451C: 10800047                 ba      locret_F0044638
F0044520: b0102000                 mov     0, %i0
F0044524: d202a004                 ld      [%o2+4], %o1
F0044528: e402a07c                 ld      [%o2+0x7C], %l2
F004452C: d0028009                 ld      [%o2+%o1], %o0
F0044530: d0264000                 st      %o0, [%i1]
F0044534: 92028009                 add     %o2, %o1, %o1
F0044538: d0026004                 ld      [%o1+4], %o0
F004453C: d0266004                 st      %o0, [%i1+4]
F0044540: d0026008                 ld      [%o1+8], %o0
F0044544: d0266008                 st      %o0, [%i1+8]
F0044548: d002600c                 ld      [%o1+0xC], %o0
F004454C: a010000a                 mov     %o2, %l0
F0044550: d026600c                 st      %o0, [%i1+0xC]
F0044554: d054200a                 ldsh    [%l0+0xA], %o0
F0044558: 80a22001                 cmp     %o0, 1
F004455C: 02800014                 be      loc_F00445AC
F0044560: 80a42000                 cmp     %l0, 0
F0044564: d2160000                 lduh    [%i0], %o1
F0044568: d0142008                 lduh    [%l0+8], %o0
F004456C: 92224008                 sub     %o1, %o0, %o1
F0044570: d0162004                 lduh    [%i0+4], %o0
F0044574: d2360000                 sth     %o1, [%i0]
F0044578: 92023f80                 add     %o0, -0x80, %o1
F004457C: d2362004                 sth     %o1, [%i0+4]
F0044580: d0042004                 ld      [%l0+4], %o0
F0044584: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0044588: 08800003                 bleu    loc_F0044594
F004458C: 90027c00                 add     %o1, -0x400, %o0
F0044590: d0362004                 sth     %o0, [%i0+4]
F0044594: 7fff6548                 call    _m_free
F0044598: 90100010                 mov     %l0, %o0
F004459C: a0920000                 orcc    %o0, %g0, %l0
F00445A0: 32bfffee                 bne,a   loc_F0044558
F00445A4: d054200a                 ldsh    [%l0+0xA], %o0
F00445A8: 80a42000                 cmp     %l0, 0
F00445AC: 12800008                 bne     loc_F00445CC
F00445B0: 94100010                 mov     %l0, %o2
F00445B4: 113c0437                 sethi   %hi(aKuRecvfromNoBo), %o0! "ku_recvfrom: no body!\n"
F00445B8: 7fff4028                 call    _printf
F00445BC: 901221c8                 bset    %lo(aKuRecvfromNoBo), %o0! "ku_recvfrom: no body!\n"
F00445C0: e426200c                 st      %l2, [%i0+0xC]
F00445C4: 1080001d                 ba      locret_F0044638
F00445C8: b0102000                 mov     0, %i0
F00445CC: d2160000                 lduh    [%i0], %o1
F00445D0: d012a008                 lduh    [%o2+8], %o0
F00445D4: 92224008                 sub     %o1, %o0, %o1
F00445D8: d0162004                 lduh    [%i0+4], %o0
F00445DC: d2360000                 sth     %o1, [%i0]
F00445E0: 92023f80                 add     %o0, -0x80, %o1
F00445E4: d2362004                 sth     %o1, [%i0+4]
F00445E8: d002a004                 ld      [%o2+4], %o0
F00445EC: 80a2207c                 cmp     %o0, 0x7C ! '|'
F00445F0: 08800003                 bleu    loc_F00445FC
F00445F4: 90027c00                 add     %o1, -0x400, %o0
F00445F8: d0362004                 sth     %o0, [%i0+4]
F00445FC: d052a008                 ldsh    [%o2+8], %o0
F0044600: d4028000                 ld      [%o2], %o2
F0044604: 80a2a000                 cmp     %o2, 0
F0044608: 12bffff1                 bne     loc_F00445CC
F004460C: a2044008                 add     %l1, %o0, %l1
F0044610: 1100000890122260         set     0x2260, %o0
F0044618: 80a44008                 cmp     %l1, %o0
F004461C: 04800006                 ble     loc_F0044634
F0044620: e426200c                 st      %l2, [%i0+0xC]
F0044624: 113c0437901221e0         set     aKuRecvfromLenD, %o0! "ku_recvfrom: len = %d\n"
F004462C: 7fff400b                 call    _printf
F0044630: 92100011                 mov     %l1, %o1
F0044634: b0100010                 mov     %l0, %i0
F0044638: 81c7e008                 ret
F004463C: 81e80000                 restore
