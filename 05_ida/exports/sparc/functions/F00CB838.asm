F00CB838: 9de3bf90                 save    %sp, -0x70, %sp
F00CB83C: d00e8000                 ldub    [%i2], %o0
F00CB840: 808a2001                 btst    1, %o0
F00CB844: 02800027                 be      loc_F00CB8E0
F00CB848: 94102001                 mov     1, %o2
F00CB84C: d04e2129                 ldsb    [%i0+0x129], %o0
F00CB850: 80a22000                 cmp     %o0, 0
F00CB854: 32800024                 bne,a   locret_F00CB8E4
F00CB858: b0102000                 mov     0, %i0
F00CB85C: 92102000                 mov     0, %o1
F00CB860: d00e8009                 ldub    [%i2+%o1], %o0
F00CB864: 80a220ff                 cmp     %o0, 0xFF
F00CB868: 1280000a                 bne     loc_F00CB890
F00CB86C: 92026001                 inc     %o1
F00CB870: 80a26005                 cmp     %o1, 5
F00CB874: 24bffffc                 ble,a   loc_F00CB864
F00CB878: d00e8009                 ldub    [%i2+%o1], %o0
F00CB87C: 80a2a000                 cmp     %o2, 0
F00CB880: 22800006                 be,a    loc_F00CB898
F00CB884: d0062138                 ld      [%i0+0x138], %o0! id
F00CB888: 10800017                 ba      locret_F00CB8E4
F00CB88C: b0102000                 mov     0, %i0
F00CB890: 10bffffb                 ba      loc_F00CB87C
F00CB894: 94102000                 mov     0, %o2
F00CB898: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CB89C: 400097f5                 call    _objc_msgSend
F00CB8A0: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CB8A4: 90100018                 mov     %i0, %o0! id
F00CB8A8: 133c0506                 sethi   %hi(paSearchmulti), %o1
F00CB8AC: d202605c                 ld      [%o1+%lo(paSearchmulti)], %o1! SEL
F00CB8B0: 400097f0                 call    _objc_msgSend
F00CB8B4: 9410001a                 mov     %i2, %o2
F00CB8B8: a0100008                 mov     %o0, %l0
F00CB8BC: d0062138                 ld      [%i0+0x138], %o0! id
F00CB8C0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CB8C4: 400097eb                 call    _objc_msgSend
F00CB8C8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CB8CC: 80a42000                 cmp     %l0, 0
F00CB8D0: 12800005                 bne     locret_F00CB8E4
F00CB8D4: b0102000                 mov     0, %i0
F00CB8D8: 10800003                 ba      locret_F00CB8E4
F00CB8DC: b0102001                 mov     1, %i0
F00CB8E0: b0102000                 mov     0, %i0
F00CB8E4: 81c7e008                 ret
F00CB8E8: 81e80000                 restore
