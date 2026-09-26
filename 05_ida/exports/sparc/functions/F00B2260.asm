F00B2260: 9de3bf98                 save    %sp, -0x68, %sp
F00B2264: ba100018                 mov     %i0, %i5
F00B2268: b6102000                 mov     0, %i3
F00B226C: 353c0474                 sethi   %hi(_ndma_map), %i2
F00B2270: c606a1d8                 ld      [%i2+%lo(_ndma_map)], %g3
F00B2274: 053c04fc                 sethi   %hi(_dma_map), %g2
F00B2278: 80a6c003                 cmp     %i3, %g3
F00B227C: 16800022                 bge     loc_F00B2304
F00B2280: f000a080                 ld      [%g2+%lo(_dma_map)], %i0
F00B2284: 05007fffb810a3ff         set     0x1FFFFFF, %i4
F00B228C: 8210001a                 mov     %i2, %g1
F00B2290: b406200c                 add     %i0, 0xC, %i2
F00B2294: c44e8000                 ldsb    [%i2], %g2
F00B2298: 80a0a000                 cmp     %g2, 0
F00B229C: 22800015                 be,a    loc_F00B22F0
F00B22A0: b406a010                 inc     0x10, %i2
F00B22A4: c406bff8                 ld      [%i2-8], %g2
F00B22A8: 80a0801d                 cmp     %g2, %i5
F00B22AC: 32800011                 bne,a   loc_F00B22F0
F00B22B0: b406a010                 inc     0x10, %i2
F00B22B4: c606bffc                 ld      [%i2-4], %g3
F00B22B8: 80a0e000                 cmp     %g3, 0
F00B22BC: 26800002                 bl,a    loc_F00B22C4
F00B22C0: 8600c01c                 add     %g3, %i4, %g3
F00B22C4: 84964000                 orcc    %i1, %g0, %g2
F00B22C8: 16800003                 bge     loc_F00B22D4
F00B22CC: 8738e019                 sra     %g3, 25, %g3
F00B22D0: 8400801c                 add     %g2, %i4, %g2
F00B22D4: 8538a019                 sra     %g2, 25, %g2
F00B22D8: 80a0c002                 cmp     %g3, %g2
F00B22DC: 32800005                 bne,a   loc_F00B22F0
F00B22E0: b406a010                 inc     0x10, %i2
F00B22E4: c02e8000                 clrb    [%i2]
F00B22E8: 10800008                 ba      locret_F00B2308
F00B22EC: f0060000                 ld      [%i0], %i0
F00B22F0: c40061d8                 ld      [%g1+0x1D8], %g2
F00B22F4: b606e001                 inc     %i3
F00B22F8: 80a6c002                 cmp     %i3, %g2
F00B22FC: 06bfffe6                 bl      loc_F00B2294
F00B2300: b0062010                 inc     0x10, %i0
F00B2304: b0102000                 mov     0, %i0
F00B2308: 81c7e008                 ret
F00B230C: 81e80000                 restore
