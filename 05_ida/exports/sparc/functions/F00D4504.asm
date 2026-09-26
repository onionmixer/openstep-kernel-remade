F00D4504: 9de3bf90                 save    %sp, -0x70, %sp
F00D4508: 9010001a                 mov     %i2, %o0! id
F00D450C: 133c0504                 sethi   %hi(paBecomeowner), %o1
F00D4510: d2026264                 ld      [%o1+%lo(paBecomeowner)], %o1! SEL
F00D4514: 400074d7                 call    _objc_msgSend
F00D4518: 94100018                 mov     %i0, %o2
F00D451C: 80a22000                 cmp     %o0, 0
F00D4520: 02800004                 be      loc_F00D4530
F00D4524: 01000000                 nop
F00D4528: 1080001a                 ba      locret_F00D4590
F00D452C: b0102000                 mov     0, %i0
F00D4530: 7fffc680                 call    _IOMalloc
F00D4534: 9010200c                 mov     0xC, %o0! void *
F00D4538: a0100008                 mov     %o0, %l0
F00D453C: 7fff0247                 call    _bzero
F00D4540: 9210200c                 mov     0xC, %o1
F00D4544: f4240000                 st      %i2, [%l0]
F00D4548: d0062170                 ld      [%i0+0x170], %o0! id
F00D454C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D4550: 400074c8                 call    _objc_msgSend
F00D4554: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D4558: d2062178                 ld      [%i0+0x178], %o1
F00D455C: 90062174                 add     %i0, 0x174, %o0
F00D4560: 80a20009                 cmp     %o0, %o1
F00D4564: 32800003                 bne,a   loc_F00D4570
F00D4568: e0226004                 st      %l0, [%o1+4]
F00D456C: e0262174                 st      %l0, [%i0+0x174]
F00D4570: d2242008                 st      %o1, [%l0+8]
F00D4574: 90062174                 add     %i0, 0x174, %o0
F00D4578: d0242004                 st      %o0, [%l0+4]
F00D457C: e0262178                 st      %l0, [%i0+0x178]
F00D4580: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4584: d0062170                 ld      [%i0+0x170], %o0! id
F00D4588: 400074ba                 call    _objc_msgSend
F00D458C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D4590: 81c7e008                 ret
F00D4594: 81e80000                 restore
