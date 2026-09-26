F00D4140: 9de3bf90                 save    %sp, -0x70, %sp
F00D4144: b52ea018                 sll     %i2, 24, %i2
F00D4148: b53ea018                 sra     %i2, 24, %i2
F00D414C: 80a6a001                 cmp     %i2, 1
F00D4150: 1280000f                 bne     loc_F00D418C
F00D4154: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D4158: 80a22000                 cmp     %o0, 0
F00D415C: 1280001c                 bne     locret_F00D41CC
F00D4160: 01000000                 nop
F00D4164: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4168: 80a22001                 cmp     %o0, 1
F00D416C: 12800006                 bne     loc_F00D4184
F00D4170: 113c0505                 sethi   -0xFEBEC00, %o0
F00D4174: d0062168                 ld      [%i0+0x168], %o0
F00D4178: d0022010                 ld      [%o0+0x10], %o0
F00D417C: d02621a4                 st      %o0, [%i0+0x1A4]
F00D4180: 113c0505                 sethi   -0xFEBEC00, %o0
F00D4184: 10800010                 ba      loc_F00D41C4
F00D4188: d20222b0                 ld      [%o0+0x2B0], %o1
F00D418C: 80a22001                 cmp     %o0, 1
F00D4190: 1280000f                 bne     locret_F00D41CC
F00D4194: 01000000                 nop
F00D4198: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D419C: 80a22001                 cmp     %o0, 1
F00D41A0: 32800008                 bne,a   loc_F00D41C0
F00D41A4: 113c0505                 sethi   -0xFEBEC00, %o0
F00D41A8: d0062168                 ld      [%i0+0x168], %o0
F00D41AC: d20621a0                 ld      [%i0+0x1A0], %o1
F00D41B0: d0022010                 ld      [%o0+0x10], %o0
F00D41B4: 90020009                 add     %o0, %o1, %o0
F00D41B8: d02621a4                 st      %o0, [%i0+0x1A4]
F00D41BC: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D41C0: d20222e0                 ld      [%o0+0x2E0], %o1! SEL
F00D41C4: 400075ab                 call    _objc_msgSend
F00D41C8: 90100018                 mov     %i0, %o0
F00D41CC: 81c7e008                 ret
F00D41D0: 81e80000                 restore
