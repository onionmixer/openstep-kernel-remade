F0036808: 9de3bf90                 save    %sp, -0x70, %sp
F003680C: a4100018                 mov     %i0, %l2
F0036810: e004a020                 ld      [%l2+0x20], %l0
F0036814: d0042024                 ld      [%l0+0x24], %o0
F0036818: 80a22000                 cmp     %o0, 0
F003681C: 12800012                 bne     loc_F0036864
F0036820: 94042024                 add     %l0, 0x24, %o2 ! '$'
F0036824: d004200c                 ld      [%l0+0xC], %o0
F0036828: 80a22000                 cmp     %o0, 0
F003682C: 02800007                 be      loc_F0036848
F0036830: 90102002                 mov     2, %o0
F0036834: d0342028                 sth     %o0, [%l0+0x28]
F0036838: d204200c                 ld      [%l0+0xC], %o1
F003683C: 9010000a                 mov     %o2, %o0
F0036840: 7fffd906                 call    _rtalloc
F0036844: d224202c                 st      %o1, [%l0+0x2C]
F0036848: d0042024                 ld      [%l0+0x24], %o0
F003684C: 80a22000                 cmp     %o0, 0
F0036850: 32800006                 bne,a   loc_F0036868
F0036854: d002202c                 ld      [%o0+0x2C], %o0
F0036858: 113c0432                 sethi   %hi(_tcp_mssdflt), %o0
F003685C: 10800047                 ba      locret_F0036978
F0036860: f0022110                 ld      [%o0+%lo(_tcp_mssdflt)], %i0
F0036864: d002202c                 ld      [%o0+0x2C], %o0
F0036868: d052200a                 ldsh    [%o0+0xA], %o0
F003686C: b0023fd8                 add     %o0, -0x28, %i0
F0036870: 80a62400                 cmp     %i0, 0x400
F0036874: 04800003                 ble     loc_F0036880
F0036878: e204201c                 ld      [%l0+0x1C], %l1
F003687C: b00e3c00                 and     %i0, -0x400, %i0
F0036880: d204200c                 ld      [%l0+0xC], %o1
F0036884: 9007bff4                 add     %fp, var_C, %o0
F0036888: 7fffe015                 call    _in_localaddr
F003688C: d227bff4                 st      %o1, [%fp+var_C]
F0036890: 80a22000                 cmp     %o0, 0
F0036894: 32800008                 bne,a   loc_F00368B4
F0036898: 912e6010                 sll     %i1, 16, %o0
F003689C: 113c0432                 sethi   %hi(_tcp_mssdflt), %o0
F00368A0: d2022110                 ld      [%o0+%lo(_tcp_mssdflt)], %o1
F00368A4: 7fff7b16                 call    _min
F00368A8: 90100018                 mov     %i0, %o0
F00368AC: b0100008                 mov     %o0, %i0
F00368B0: 912e6010                 sll     %i1, 16, %o0
F00368B4: 91322010                 srl     %o0, 16, %o0
F00368B8: 80a22000                 cmp     %o0, 0
F00368BC: 02800004                 be      loc_F00368CC
F00368C0: 80a60008                 cmp     %i0, %o0
F00368C4: 34800002                 bg,a    loc_F00368CC
F00368C8: b0100008                 mov     %o0, %i0
F00368CC: 80a62020                 cmp     %i0, 0x20 ! ' '
F00368D0: 26800002                 bl,a    loc_F00368D8
F00368D4: b0102020                 mov     0x20, %i0 ! ' '
F00368D8: d014a018                 lduh    [%l2+0x18], %o0
F00368DC: 80a60008                 cmp     %i0, %o0
F00368E0: 06800005                 bl      loc_F00368F4
F00368E4: 912e6010                 sll     %i1, 16, %o0
F00368E8: 80a22000                 cmp     %o0, 0
F00368EC: 22800023                 be,a    locret_F0036978
F00368F0: f034a054                 sth     %i0, [%l2+0x54]
F00368F4: d214603e                 lduh    [%l1+0x3E], %o1
F00368F8: 80a24018                 cmp     %o1, %i0
F00368FC: 1a800004                 bcc     loc_F003690C
F0036900: 90100009                 mov     %o1, %o0
F0036904: 1080000c                 ba      loc_F0036934
F0036908: b0100009                 mov     %o1, %i0
F003690C: 1300003f                 sethi   0xFC00, %o1
F0036910: 7fff7afb                 call    _min
F0036914: 921263ff                 bset    0x3FF, %o1
F0036918: 7fff3f3a                 call    _udiv
F003691C: 92100018                 mov     %i0, %o1
F0036920: 7fff3ef8                 call    _umul
F0036924: 92100018                 mov     %i0, %o1
F0036928: 92100008                 mov     %o0, %o1
F003692C: 7fffa6e5                 call    _sbreserve
F0036930: 9004603c                 add     %l1, 0x3C, %o0 ! '<'
F0036934: f034a018                 sth     %i0, [%l2+0x18]
F0036938: d2146026                 lduh    [%l1+0x26], %o1
F003693C: 80a24018                 cmp     %o1, %i0
F0036940: 2880000e                 bleu,a  locret_F0036978
F0036944: f034a054                 sth     %i0, [%l2+0x54]
F0036948: 90100009                 mov     %o1, %o0
F003694C: 1300003f                 sethi   0xFC00, %o1
F0036950: 7fff7aeb                 call    _min
F0036954: 921263ff                 bset    0x3FF, %o1
F0036958: 7fff3f2a                 call    _udiv
F003695C: 92100018                 mov     %i0, %o1
F0036960: 7fff3ee8                 call    _umul
F0036964: 92100018                 mov     %i0, %o1
F0036968: 92100008                 mov     %o0, %o1
F003696C: 7fffa6d5                 call    _sbreserve
F0036970: 90046024                 add     %l1, 0x24, %o0 ! '$'
F0036974: f034a054                 sth     %i0, [%l2+0x54]
F0036978: 81c7e008                 ret
F003697C: 81e80000                 restore
