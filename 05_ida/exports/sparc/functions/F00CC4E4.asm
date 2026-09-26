F00CC4E4: 9de3bf90                 save    %sp, -0x70, %sp
F00CC4E8: c406212c                 ld      [%i0+0x12C], %g2
F00CC4EC: 80a0a004                 cmp     %g2, 4
F00CC4F0: 12800007                 bne     loc_F00CC50C
F00CC4F4: 80a0a010                 cmp     %g2, 0x10
F00CC4F8: 050000048410a178         set     0x1178, %g2
F00CC500: c4262138                 st      %g2, [%i0+0x138]
F00CC504: c406212c                 ld      [%i0+0x12C], %g2
F00CC508: 80a0a010                 cmp     %g2, 0x10
F00CC50C: 12800004                 bne     locret_F00CC51C
F00CC510: 05000011                 sethi   0x4400, %g2
F00CC514: 8410a188                 bset    0x188, %g2
F00CC518: c4262138                 st      %g2, [%i0+0x138]
F00CC51C: 81c7e008                 ret
F00CC520: 81e80000                 restore
