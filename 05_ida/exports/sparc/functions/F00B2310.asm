F00B2310: 9de3bf98                 save    %sp, -0x68, %sp
F00B2314: b4102000                 mov     0, %i2
F00B2318: 373c0474                 sethi   %hi(_ndma_map), %i3
F00B231C: c606e1d8                 ld      [%i3+%lo(_ndma_map)], %g3
F00B2320: 053c04fc                 sethi   %hi(_dma_map), %g2
F00B2324: 80a68003                 cmp     %i2, %g3
F00B2328: 16800013                 bge     locret_F00B2374
F00B232C: f200a080                 ld      [%g2+%lo(_dma_map)], %i1
F00B2330: b8102001                 mov     1, %i4
F00B2334: 8606600c                 add     %i1, 0xC, %g3
F00B2338: c448c000                 ldsb    [%g3], %g2
F00B233C: 80a0a000                 cmp     %g2, 0
F00B2340: 32800008                 bne,a   loc_F00B2360
F00B2344: 8600e010                 inc     0x10, %g3
F00B2348: c4064000                 ld      [%i1], %g2
F00B234C: 80a08018                 cmp     %g2, %i0
F00B2350: 32800004                 bne,a   loc_F00B2360
F00B2354: 8600e010                 inc     0x10, %g3
F00B2358: 10800007                 ba      locret_F00B2374
F00B235C: f828c000                 stb     %i4, [%g3]
F00B2360: c406e1d8                 ld      [%i3+0x1D8], %g2
F00B2364: b406a001                 inc     %i2
F00B2368: 80a68002                 cmp     %i2, %g2
F00B236C: 06bffff3                 bl      loc_F00B2338
F00B2370: b2066010                 inc     0x10, %i1
F00B2374: 81c7e008                 ret
F00B2378: 81e80000                 restore
