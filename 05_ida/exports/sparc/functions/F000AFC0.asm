F000AFC0: 9de3bf98                 save    %sp, -0x68, %sp
F000AFC4: d056200c                 ldsh    [%i0+0xC], %o0
F000AFC8: 80a22002                 cmp     %o0, 2
F000AFCC: 12800007                 bne     loc_F000AFE8
F000AFD0: f227a048                 st      %i1, [%fp+arg_48]
F000AFD4: d2062018                 ld      [%i0+0x18], %o1
F000AFD8: d017a04a                 lduh    [%fp+arg_48+2], %o0
F000AFDC: b0102000                 mov     0, %i0
F000AFE0: 10800013                 ba      locret_F000B02C
F000AFE4: d032605a                 sth     %o0, [%o1+0x5A]
F000AFE8: 80a66000                 cmp     %i1, 0
F000AFEC: 04800009                 ble     loc_F000B010
F000AFF0: 90200019                 neg     %i1, %o0
F000AFF4: 40000d33                 call    _pfind
F000AFF8: 90100019                 mov     %i1, %o0
F000AFFC: 80a22000                 cmp     %o0, 0
F000B000: 32800004                 bne,a   loc_F000B010
F000B004: d052202e                 ldsh    [%o0+0x2E], %o0
F000B008: 10800009                 ba      locret_F000B02C
F000B00C: b0102003                 mov     3, %i0
F000B010: d027a048                 st      %o0, [%fp+arg_48]
F000B014: 90100018                 mov     %i0, %o0
F000B018: 1320011d92126076         set     -0x7FFB8B8A, %o1
F000B020: 40000005                 call    _fioctl
F000B024: 9407a048                 add     %fp, arg_48, %o2
F000B028: b0100008                 mov     %o0, %i0
F000B02C: 81c7e008                 ret
F000B030: 81e80000                 restore
