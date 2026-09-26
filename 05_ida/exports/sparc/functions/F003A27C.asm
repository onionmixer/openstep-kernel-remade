F003A27C: 9de3bf90                 save    %sp, -0x70, %sp
F003A280: d206601c                 ld      [%i1+0x1C], %o1
F003A284: d4026064                 ld      [%o1+0x64], %o2
F003A288: 90100019                 mov     %i1, %o0
F003A28C: 9fc28000                 call    %o2
F003A290: 9207bff4                 add     %fp, var_C, %o1
F003A294: 80a22000                 cmp     %o0, 0
F003A298: 3280002e                 bne,a   locret_F003A350
F003A29C: b0102047                 mov     0x47, %i0 ! 'G'
F003A2A0: d407bff4                 ld      [%fp+var_C], %o2
F003A2A4: 80a2a000                 cmp     %o2, 0
F003A2A8: 2280002a                 be,a    locret_F003A350
F003A2AC: b0102047                 mov     0x47, %i0 ! 'G'
F003A2B0: d006a028                 ld      [%i2+0x28], %o0
F003A2B4: d2128000                 lduh    [%o2], %o1! size_t
F003A2B8: d0120000                 lduh    [%o0], %o0
F003A2BC: 90024008                 add     %o1, %o0, %o0
F003A2C0: 90022008                 inc     8, %o0
F003A2C4: 80a22020                 cmp     %o0, 0x20 ! ' '
F003A2C8: 1880001e                 bgu     loc_F003A340
F003A2CC: 90100018                 mov     %i0, %o0! void *
F003A2D0: 40016ae2                 call    _bzero
F003A2D4: 92102020                 mov     0x20, %o1 ! ' '
F003A2D8: d0066024                 ld      [%i1+0x24], %o0
F003A2DC: d0022014                 ld      [%o0+0x14], %o0
F003A2E0: d0260000                 st      %o0, [%i0]
F003A2E4: d0066024                 ld      [%i1+0x24], %o0
F003A2E8: d2022018                 ld      [%o0+0x18], %o1
F003A2EC: d007bff4                 ld      [%fp+var_C], %o0! void *
F003A2F0: d2262004                 st      %o1, [%i0+4]
F003A2F4: d4120000                 lduh    [%o0], %o2
F003A2F8: d4362008                 sth     %o2, [%i0+8]
F003A2FC: d4120000                 lduh    [%o0], %o2! size_t
F003A300: 9206200a                 add     %i0, 0xA, %o1! void *
F003A304: 40016a03                 call    _bcopy
F003A308: 90022002                 inc     2, %o0
F003A30C: d006a028                 ld      [%i2+0x28], %o0
F003A310: d4120000                 lduh    [%o0], %o2! size_t
F003A314: 92062016                 add     %i0, 0x16, %o1! void *
F003A318: d4362014                 sth     %o2, [%i0+0x14]
F003A31C: d006a028                 ld      [%i2+0x28], %o0! void *
F003A320: 400169fc                 call    _bcopy
F003A324: 90022002                 inc     2, %o0
F003A328: d007bff4                 ld      [%fp+var_C], %o0
F003A32C: d2120000                 lduh    [%o0], %o1
F003A330: 4000b79c                 call    _kfree
F003A334: 92026002                 inc     2, %o1
F003A338: 10800006                 ba      locret_F003A350
F003A33C: b0102000                 mov     0, %i0
F003A340: 9010000a                 mov     %o2, %o0
F003A344: 4000b797                 call    _kfree
F003A348: 92026002                 inc     2, %o1
F003A34C: b0102047                 mov     0x47, %i0 ! 'G'
F003A350: 81c7e008                 ret
F003A354: 81e80000                 restore
