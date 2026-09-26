F00936AC: 9de3bf98                 save    %sp, -0x68, %sp
F00936B0: 073c04c4                 sethi   %hi(unk_F0131250), %g3
F00936B4: c448e250                 ldsb    [%g3+%lo(unk_F0131250)], %g2
F00936B8: 80a0a000                 cmp     %g2, 0
F00936BC: 12800005                 bne     locret_F00936D0
F00936C0: b0102010                 mov     0x10, %i0
F00936C4: 84102001                 mov     1, %g2
F00936C8: c428e250                 stb     %g2, [%g3+%lo(unk_F0131250)]
F00936CC: b0102000                 mov     0, %i0
F00936D0: 81c7e008                 ret
F00936D4: 81e80000                 restore
