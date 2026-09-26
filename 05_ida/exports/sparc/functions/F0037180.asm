F0037180: 9de3bf98                 save    %sp, -0x68, %sp
F0037184: d056200a                 ldsh    [%i0+0xA], %o0
F0037188: d2162060                 lduh    [%i0+0x60], %o1
F003718C: 80a22000                 cmp     %o0, 0
F0037190: 932a6010                 sll     %o1, 16, %o1
F0037194: d0562062                 ldsh    [%i0+0x62], %o0
F0037198: 933a6012                 sra     %o1, 18, %o1
F003719C: 92024008                 add     %o1, %o0, %o1
F00371A0: 02800005                 be      loc_F00371B4
F00371A4: a13a6001                 sra     %o1, 1, %l0
F00371A8: 113c0432                 sethi   %hi(aTcpOutputRexmt), %o0! "tcp_output REXMT"
F00371AC: 7fff77f1                 call    _panic
F00371B0: 901220f8                 bset    %lo(aTcpOutputRexmt), %o0! "tcp_output REXMT"
F00371B4: 133c0432                 sethi   %hi(_tcp_backoff), %o1
F00371B8: d0562012                 ldsh    [%i0+0x12], %o0
F00371BC: 92126124                 bset    %lo(_tcp_backoff), %o1
F00371C0: 912a2002                 sll     %o0, 2, %o0
F00371C4: d2020009                 ld      [%o0+%o1], %o1
F00371C8: 7fff3cce                 call    _umul
F00371CC: 90100010                 mov     %l0, %o0
F00371D0: d036200c                 sth     %o0, [%i0+0xC]
F00371D4: 912a2010                 sll     %o0, 16, %o0
F00371D8: 913a2010                 sra     %o0, 16, %o0
F00371DC: 80a22009                 cmp     %o0, 9
F00371E0: 14800004                 bg      loc_F00371F0
F00371E4: 80a22078                 cmp     %o0, 0x78 ! 'x'
F00371E8: 10800004                 ba      loc_F00371F8
F00371EC: 9010200a                 mov     0xA, %o0
F00371F0: 04800003                 ble     loc_F00371FC
F00371F4: 90102078                 mov     0x78, %o0 ! 'x'
F00371F8: d036200c                 sth     %o0, [%i0+0xC]
F00371FC: d0562012                 ldsh    [%i0+0x12], %o0
F0037200: 80a2200b                 cmp     %o0, 0xB
F0037204: 14800003                 bg      locret_F0037210
F0037208: 90022001                 inc     %o0
F003720C: d0362012                 sth     %o0, [%i0+0x12]
F0037210: 81c7e008                 ret
F0037214: 81e80000                 restore
