F00BA57C: 9de3bf98                 save    %sp, -0x68, %sp
F00BA580: d4062018                 ld      [%i0+0x18], %o2
F00BA584: d052a118                 ldsh    [%o2+0x118], %o0
F00BA588: 80a22000                 cmp     %o0, 0
F00BA58C: 0480000f                 ble     loc_F00BA5C8
F00BA590: d6062010                 ld      [%i0+0x10], %o3
F00BA594: d00ac000                 ldub    [%o3], %o0
F00BA598: 808a2004                 btst    4, %o0
F00BA59C: 2280000c                 be,a    loc_F00BA5CC
F00BA5A0: d012a00c                 lduh    [%o2+0xC], %o0
F00BA5A4: d202a114                 ld      [%o2+0x114], %o1
F00BA5A8: 90026001                 add     %o1, 1, %o0
F00BA5AC: d022a114                 st      %o0, [%o2+0x114]
F00BA5B0: d00a4000                 ldub    [%o1], %o0
F00BA5B4: d02ae002                 stb     %o0, [%o3+2]
F00BA5B8: d012a118                 lduh    [%o2+0x118], %o0
F00BA5BC: 90023fff                 inc     -1, %o0
F00BA5C0: 10800011                 ba      locret_F00BA604
F00BA5C4: d032a118                 sth     %o0, [%o2+0x118]
F00BA5C8: d012a00c                 lduh    [%o2+0xC], %o0
F00BA5CC: 90022001                 inc     %o0
F00BA5D0: d032a00c                 sth     %o0, [%o2+0xC]
F00BA5D4: 90102028                 mov     0x28, %o0 ! '('
F00BA5D8: d02ac000                 stb     %o0, [%o3]
F00BA5DC: d00e2030                 ldub    [%i0+0x30], %o0
F00BA5E0: 133c04fd                 sethi   %hi(_zssoftpend), %o1
F00BA5E4: 90122001                 bset    1, %o0
F00BA5E8: d02e2030                 stb     %o0, [%i0+0x30]
F00BA5EC: d00261d8                 ld      [%o1+%lo(_zssoftpend)], %o0
F00BA5F0: 80a22000                 cmp     %o0, 0
F00BA5F4: 12800004                 bne     locret_F00BA604
F00BA5F8: 90102001                 mov     1, %o0
F00BA5FC: 400003d1                 call    _setzssoft
F00BA600: d02261d8                 st      %o0, [%o1+%lo(_zssoftpend)]
F00BA604: 81c7e008                 ret
F00BA608: 81e80000                 restore
