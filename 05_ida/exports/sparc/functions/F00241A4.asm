F00241A4: 9de3bf98                 save    %sp, -0x68, %sp
F00241A8: c406200c                 ld      [%i0+0xC], %g2
F00241AC: 8088a002                 btst    2, %g2
F00241B0: 32800005                 bne,a   locret_F00241C4
F00241B4: b0102010                 mov     0x10, %i0
F00241B8: 8410a002                 bset    2, %g2
F00241BC: c426200c                 st      %g2, [%i0+0xC]
F00241C0: b0102000                 mov     0, %i0
F00241C4: 81c7e008                 ret
F00241C8: 81e80000                 restore
