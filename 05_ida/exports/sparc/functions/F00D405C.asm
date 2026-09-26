F00D405C: 9de3bf90                 save    %sp, -0x70, %sp
F00D4060: 80a6a000                 cmp     %i2, 0
F00D4064: 16800004                 bge     loc_F00D4074
F00D4068: 80a6a040                 cmp     %i2, 0x40 ! '@'
F00D406C: 10800004                 ba      loc_F00D407C
F00D4070: b4102000                 mov     0, %i2
F00D4074: 34800002                 bg,a    loc_F00D407C
F00D4078: b4102040                 mov     0x40, %i2 ! '@'
F00D407C: d00621c8                 ld      [%i0+0x1C8], %o0
F00D4080: 80a68008                 cmp     %i2, %o0
F00D4084: 0280000b                 be      locret_F00D40B0
F00D4088: 01000000                 nop
F00D408C: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D4090: 80a22001                 cmp     %o0, 1
F00D4094: 12800007                 bne     locret_F00D40B0
F00D4098: f42621c8                 st      %i2, [%i0+0x1C8]
F00D409C: 113c0505                 sethi   %hi(paSetbrightness_0), %o0! id
F00D40A0: d20222a8                 ld      [%o0+%lo(paSetbrightness_0)], %o1! SEL
F00D40A4: 400075f3                 call    _objc_msgSend
F00D40A8: 90100018                 mov     %i0, %o0
F00D40AC: b0100008                 mov     %o0, %i0
F00D40B0: 81c7e008                 ret
F00D40B4: 81e80000                 restore
