F00328C4: 9de3bf98                 save    %sp, -0x68, %sp
F00328C8: 400190f3                 call    _splnet
F00328CC: 01000000                 nop
F00328D0: 133c04d9                 sethi   %hi(_ipq), %o1
F00328D4: e00260b0                 ld      [%o1+%lo(_ipq)], %l0
F00328D8: a4100008                 mov     %o0, %l2
F00328DC: 80a42000                 cmp     %l0, 0
F00328E0: 02800019                 be      loc_F0032944
F00328E4: 921260b0                 bset    %lo(_ipq), %o1
F00328E8: 80a40009                 cmp     %l0, %o1
F00328EC: 02800015                 be      loc_F0032940
F00328F0: 113c04d9                 sethi   %hi(_ipstat), %o0
F00328F4: a21220d0                 or      %o0, %lo(_ipstat), %l1
F00328F8: a6100009                 mov     %o1, %l3
F00328FC: d00c2008                 ldub    [%l0+8], %o0
F0032900: 90023fff                 inc     -1, %o0
F0032904: d02c2008                 stb     %o0, [%l0+8]
F0032908: e0040000                 ld      [%l0], %l0
F003290C: d0042004                 ld      [%l0+4], %o0
F0032910: d00a2008                 ldub    [%o0+8], %o0
F0032914: 80a22000                 cmp     %o0, 0
F0032918: 12800008                 bne     loc_F0032938
F003291C: 80a40013                 cmp     %l0, %l3
F0032920: d0046020                 ld      [%l1+0x20], %o0
F0032924: 90022001                 inc     %o0
F0032928: d0246020                 st      %o0, [%l1+0x20]
F003292C: 7fffffbc                 call    _ip_freef
F0032930: d0042004                 ld      [%l0+4], %o0
F0032934: 80a40013                 cmp     %l0, %l3
F0032938: 32bffff2                 bne,a   loc_F0032900
F003293C: d00c2008                 ldub    [%l0+8], %o0
F0032940: 90100012                 mov     %l2, %o0
F0032944: 400190f8                 call    _splx
F0032948: 01000000                 nop
F003294C: 81c7e008                 ret
F0032950: 81e80000                 restore
