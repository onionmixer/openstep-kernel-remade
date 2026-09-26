F00A3024: 9de3bf98                 save    %sp, -0x68, %sp
F00A3028: 333c04f886166108         set     _lru_context, %g3
F00A3030: c620e004                 st      %g3, [%g3+4]
F00A3034: c6266108                 st      %g3, [%i1+0x108]
F00A3038: 053c0464                 sethi   %hi(_nctxs), %g2
F00A303C: f600a310                 ld      [%g2+%lo(_nctxs)], %i3
F00A3040: b0102001                 mov     1, %i0
F00A3044: 80a6001b                 cmp     %i0, %i3
F00A3048: 1a800013                 bcc     locret_F00A3094
F00A304C: b4100019                 mov     %i1, %i2
F00A3050: 053c04f7                 sethi   %hi(_context_table), %g2
F00A3054: c400a210                 ld      [%g2+%lo(_context_table)], %g2
F00A3058: b2100003                 mov     %g3, %i1
F00A305C: 8400a00c                 inc     0xC, %g2
F00A3060: c020a008                 clr     [%g2+8]
F00A3064: c606a108                 ld      [%i2+0x108], %g3
F00A3068: 80a0c019                 cmp     %g3, %i1
F00A306C: 32800003                 bne,a   loc_F00A3078
F00A3070: c420e004                 st      %g2, [%g3+4]
F00A3074: c4266004                 st      %g2, [%i1+4]
F00A3078: c6208000                 st      %g3, [%g2]
F00A307C: f220a004                 st      %i1, [%g2+4]
F00A3080: c426a108                 st      %g2, [%i2+0x108]
F00A3084: b0062001                 inc     %i0
F00A3088: 80a6001b                 cmp     %i0, %i3
F00A308C: 0abffff5                 bcs     loc_F00A3060
F00A3090: 8400a00c                 inc     0xC, %g2
F00A3094: 81c7e008                 ret
F00A3098: 81e80000                 restore
