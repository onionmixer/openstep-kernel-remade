F00BC088: 9de3bf98                 save    %sp, -0x68, %sp
F00BC08C: 113c04c8                 sethi   %hi(dword_F0132048), %o0
F00BC090: d0022048                 ld      [%o0+%lo(dword_F0132048)], %o0
F00BC094: 80a22000                 cmp     %o0, 0
F00BC098: 32800005                 bne,a   loc_F00BC0AC
F00BC09C: 133c047f                 sethi   -0xFEE0400, %o1
F00BC0A0: 4000004c                 call    _kminit
F00BC0A4: 01000000                 nop
F00BC0A8: 133c047f                 sethi   -0xFEE0400, %o1
F00BC0AC: 90100018                 mov     %i0, %o0
F00BC0B0: 4000053a                 call    _DoAlert
F00BC0B4: 92126160                 bset    0x160, %o1
F00BC0B8: 81c7e008                 ret
F00BC0BC: 91e82000                 restore %g0, 0, %o0
