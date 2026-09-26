F00098C0: 9de3bf98                 save    %sp, -0x68, %sp
F00098C4: 313c04d0                 sethi   %hi(_cfree), %i0
F00098C8: c6062268                 ld      [%i0+%lo(_cfree)], %g3
F00098CC: 053c043c                 sethi   %hi(_nclist), %g2
F00098D0: c400a378                 ld      [%g2+%lo(_nclist)], %g2
F00098D4: 8600e03f                 inc     0x3F, %g3 ! '?'
F00098D8: b208ffc0                 and     %g3, -0x40, %i1
F00098DC: 8528a006                 sll     %g2, 6, %g2
F00098E0: c6062268                 ld      [%i0+%lo(_cfree)], %g3
F00098E4: 8400bfc0                 inc     -0x40, %g2
F00098E8: 8600c002                 add     %g3, %g2, %g3
F00098EC: 80a64003                 cmp     %i1, %g3
F00098F0: 1a80000c                 bcc     locret_F0009920
F00098F4: 353c043c                 sethi   -0xFEF1000, %i2
F00098F8: 313c043c                 sethi   -0xFEF1000, %i0
F00098FC: c406a38c                 ld      [%i2+0x38C], %g2
F0009900: c4264000                 st      %g2, [%i1]
F0009904: f226a38c                 st      %i1, [%i2+0x38C]
F0009908: b2066040                 inc     0x40, %i1 ! '@'
F000990C: c4062390                 ld      [%i0+0x390], %g2
F0009910: 80a64003                 cmp     %i1, %g3
F0009914: 8400a034                 inc     0x34, %g2 ! '4'
F0009918: 0abffff9                 bcs     loc_F00098FC
F000991C: c4262390                 st      %g2, [%i0+0x390]
F0009920: 81c7e008                 ret
F0009924: 81e80000                 restore
