F0092E0C: 9de3bf98                 save    %sp, -0x68, %sp
F0092E10: c6062014                 ld      [%i0+0x14], %g3
F0092E14: 053c04c4                 sethi   %hi(dword_F0131248), %g2
F0092E18: c400a248                 ld      [%g2+%lo(dword_F0131248)], %g2
F0092E1C: 80a0c002                 cmp     %g3, %g2
F0092E20: 38800002                 bgu,a   loc_F0092E28
F0092E24: c4262014                 st      %g2, [%i0+0x14]
F0092E28: f0062014                 ld      [%i0+0x14], %i0
F0092E2C: 81c7e008                 ret
F0092E30: 81e80000                 restore
