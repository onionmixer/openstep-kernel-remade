F002E8DC: 9de3bf98                 save    %sp, -0x68, %sp
F002E8E0: 053c0431                 sethi   %hi(_subnetsarelocal), %g2
F002E8E4: c400a0a8                 ld      [%g2+%lo(_subnetsarelocal)], %g2
F002E8E8: 80a0a000                 cmp     %g2, 0
F002E8EC: 02800013                 be      loc_F002E938
F002E8F0: f0060000                 ld      [%i0], %i0
F002E8F4: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F002E8F8: f200a070                 ld      [%g2+%lo(_in_ifaddr)], %i1
F002E8FC: 80a66000                 cmp     %i1, 0
F002E900: 2280001e                 be,a    locret_F002E978
F002E904: b0102000                 mov     0, %i0
F002E908: c406602c                 ld      [%i1+0x2C], %g2
F002E90C: c6066028                 ld      [%i1+0x28], %g3
F002E910: 840e0002                 and     %i0, %g2, %g2
F002E914: 80a08003                 cmp     %g2, %g3
F002E918: 22800018                 be,a    locret_F002E978
F002E91C: b0102001                 mov     1, %i0
F002E920: f2066040                 ld      [%i1+0x40], %i1
F002E924: 80a66000                 cmp     %i1, 0
F002E928: 32bffff9                 bne,a   loc_F002E90C
F002E92C: c406602c                 ld      [%i1+0x2C], %g2
F002E930: 10800012                 ba      locret_F002E978
F002E934: b0102000                 mov     0, %i0
F002E938: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F002E93C: f200a070                 ld      [%g2+%lo(_in_ifaddr)], %i1
F002E940: 80a66000                 cmp     %i1, 0
F002E944: 2280000d                 be,a    locret_F002E978
F002E948: b0102000                 mov     0, %i0
F002E94C: c4066034                 ld      [%i1+0x34], %g2
F002E950: c6066030                 ld      [%i1+0x30], %g3
F002E954: 840e0002                 and     %i0, %g2, %g2
F002E958: 80a08003                 cmp     %g2, %g3
F002E95C: 22800007                 be,a    locret_F002E978
F002E960: b0102001                 mov     1, %i0
F002E964: f2066040                 ld      [%i1+0x40], %i1
F002E968: 80a66000                 cmp     %i1, 0
F002E96C: 32bffff9                 bne,a   loc_F002E950
F002E970: c4066034                 ld      [%i1+0x34], %g2
F002E974: b0102000                 mov     0, %i0
F002E978: 81c7e008                 ret
F002E97C: 81e80000                 restore
