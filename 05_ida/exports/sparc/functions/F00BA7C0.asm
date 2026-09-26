F00BA7C0: 9de3bf98                 save    %sp, -0x68, %sp
F00BA7C4: e0062010                 ld      [%i0+0x10], %l0
F00BA7C8: 92102001                 mov     1, %o1
F00BA7CC: e2062018                 ld      [%i0+0x18], %l1
F00BA7D0: 40000362                 call    _zszread
F00BA7D4: 90100010                 mov     %l0, %o0
F00BA7D8: 808a2020                 btst    0x20, %o0 ! ' '
F00BA7DC: d00c2002                 ldub    [%l0+2], %o0
F00BA7E0: 90102030                 mov     0x30, %o0 ! '0'
F00BA7E4: d02c0000                 stb     %o0, [%l0]
F00BA7E8: 02800012                 be      locret_F00BA830
F00BA7EC: 01000000                 nop
F00BA7F0: d0146008                 lduh    [%l1+8], %o0
F00BA7F4: d214600c                 lduh    [%l1+0xC], %o1
F00BA7F8: 90022001                 inc     %o0
F00BA7FC: d0346008                 sth     %o0, [%l1+8]
F00BA800: 92026001                 inc     %o1
F00BA804: d234600c                 sth     %o1, [%l1+0xC]
F00BA808: d00e2030                 ldub    [%i0+0x30], %o0
F00BA80C: 133c04fd                 sethi   %hi(_zssoftpend), %o1
F00BA810: 90122001                 bset    1, %o0
F00BA814: d02e2030                 stb     %o0, [%i0+0x30]
F00BA818: d00261d8                 ld      [%o1+%lo(_zssoftpend)], %o0
F00BA81C: 80a22000                 cmp     %o0, 0
F00BA820: 12800004                 bne     locret_F00BA830
F00BA824: 90102001                 mov     1, %o0
F00BA828: 40000346                 call    _setzssoft
F00BA82C: d02261d8                 st      %o0, [%o1+%lo(_zssoftpend)]
F00BA830: 81c7e008                 ret
F00BA834: 81e80000                 restore
