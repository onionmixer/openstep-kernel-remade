F00142E0: 9de3bf98                 save    %sp, -0x68, %sp
F00142E4: 40020a29                 call    _splusclock
F00142E8: b0102000                 mov     0, %i0
F00142EC: 173c042d                 sethi   %hi(_pmsgbuf), %o3
F00142F0: d202e08c                 ld      [%o3+%lo(_pmsgbuf)], %o1
F00142F4: d4026008                 ld      [%o1+8], %o2
F00142F8: d2026004                 ld      [%o1+4], %o1
F00142FC: 80a28009                 cmp     %o2, %o1
F0014300: 12800016                 bne     loc_F0014358
F0014304: a0100008                 mov     %o0, %l0
F0014308: 253c04d4                 sethi   %hi(_logsoftc), %l2
F001430C: a210000b                 mov     %o3, %l1
F0014310: d004a180                 ld      [%l2+%lo(_logsoftc)], %o0
F0014314: 808a2002                 btst    2, %o0
F0014318: 02800006                 be      loc_F0014330
F001431C: 90122008                 bset    8, %o0
F0014320: 40020a81                 call    _splx
F0014324: 90100010                 mov     %l0, %o0
F0014328: 10800039                 ba      locret_F001440C
F001432C: b0102023                 mov     0x23, %i0 ! '#'
F0014330: d024a180                 st      %o0, [%l2+0x180]
F0014334: d004608c                 ld      [%l1+0x8C], %o0! unsigned int
F0014338: 7ffff8d0                 call    _sleep
F001433C: 9210201a                 mov     0x1A, %o1
F0014340: d004608c                 ld      [%l1+0x8C], %o0
F0014344: d2022008                 ld      [%o0+8], %o1
F0014348: d0022004                 ld      [%o0+4], %o0
F001434C: 80a24008                 cmp     %o1, %o0
F0014350: 02bffff1                 be      loc_F0014314
F0014354: d004a180                 ld      [%l2+0x180], %o0
F0014358: 40020a73                 call    _splx
F001435C: 90100010                 mov     %l0, %o0
F0014360: 113c04d4                 sethi   %hi(_logsoftc), %o0
F0014364: d2022180                 ld      [%o0+%lo(_logsoftc)], %o1
F0014368: 920a7ff7                 and     %o1, -9, %o1
F001436C: d2222180                 st      %o1, [%o0+%lo(_logsoftc)]
F0014370: d0066014                 ld      [%i1+0x14], %o0
F0014374: 80a22000                 cmp     %o0, 0
F0014378: 04800025                 ble     locret_F001440C
F001437C: 233c042d                 sethi   %hi(_pmsgbuf), %l1
F0014380: a4102ff4                 mov     0xFF4, %l2
F0014384: d404608c                 ld      [%l1+%lo(_pmsgbuf)], %o2
F0014388: d002a004                 ld      [%o2+4], %o0
F001438C: d202a008                 ld      [%o2+8], %o1
F0014390: a0a20009                 subcc   %o0, %o1, %l0
F0014394: 2c800002                 bneg,a  loc_F001439C
F0014398: a0248009                 sub     %l2, %o1, %l0
F001439C: d0066014                 ld      [%i1+0x14], %o0
F00143A0: 80a40008                 cmp     %l0, %o0
F00143A4: 34800002                 bg,a    loc_F00143AC
F00143A8: a0100008                 mov     %o0, %l0
F00143AC: 80a42000                 cmp     %l0, 0
F00143B0: 02800017                 be      locret_F001440C
F00143B4: 9002600c                 add     %o1, 0xC, %o0
F00143B8: 90028008                 add     %o2, %o0, %o0
F00143BC: 92100010                 mov     %l0, %o1
F00143C0: 94102000                 mov     0, %o2
F00143C4: 7ffff7d5                 call    _uiomove
F00143C8: 96100019                 mov     %i1, %o3
F00143CC: b0920000                 orcc    %o0, %g0, %i0
F00143D0: 1280000f                 bne     locret_F001440C
F00143D4: d204608c                 ld      [%l1+0x8C], %o1
F00143D8: d0026008                 ld      [%o1+8], %o0
F00143DC: 90020010                 add     %o0, %l0, %o0
F00143E0: 80a22000                 cmp     %o0, 0
F00143E4: 06800005                 bl      loc_F00143F8
F00143E8: d0226008                 st      %o0, [%o1+8]
F00143EC: 80a22ff3                 cmp     %o0, 0xFF3
F00143F0: 28800004                 bleu,a  loc_F0014400
F00143F4: d0066014                 ld      [%i1+0x14], %o0
F00143F8: c0226008                 clr     [%o1+8]
F00143FC: d0066014                 ld      [%i1+0x14], %o0
F0014400: 80a22000                 cmp     %o0, 0
F0014404: 14bfffe1                 bg      loc_F0014388
F0014408: d404608c                 ld      [%l1+0x8C], %o2
F001440C: 81c7e008                 ret
F0014410: 81e80000                 restore
