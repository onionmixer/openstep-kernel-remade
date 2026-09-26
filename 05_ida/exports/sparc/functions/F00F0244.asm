F00F0244: 9de3bf98                 save    %sp, -0x68, %sp
F00F0248: 113c03e890122360         set     unk_F00FA360, %o0
F00F0250: 80a60008                 cmp     %i0, %o0
F00F0254: 12800005                 bne     loc_F00F0268
F00F0258: a2100018                 mov     %i0, %l1
F00F025C: 313c03be                 sethi   %hi(sub_F00EF9D8), %i0
F00F0260: 1080003e                 ba      locret_F00F0358
F00F0264: b01621d8                 bset    %lo(sub_F00EF9D8), %i0
F00F0268: d0046010                 ld      [%l1+0x10], %o0
F00F026C: 808a2002                 btst    2, %o0
F00F0270: 02800008                 be      loc_F00F0290
F00F0274: 808a2004                 btst    4, %o0
F00F0278: 12800007                 bne     loc_F00F0294
F00F027C: 113c03e9                 sethi   -0xFF05C00, %o0! name
F00F0280: 400006a1                 call    _objc_getClass
F00F0284: d0046008                 ld      [%l1+8], %o0
F00F0288: 7ffffddf                 call    sub_F00EFA04
F00F028C: 01000000                 nop
F00F0290: 113c03e9                 sethi   -0xFF05C00, %o0
F00F0294: a6122128                 or      %o0, 0x128, %l3
F00F0298: 113c03c6a41222b0         set     __objc_msgForward, %l2
F00F02A0: d604601c                 ld      [%l1+0x1C], %o3
F00F02A4: 80a2e000                 cmp     %o3, 0
F00F02A8: 02800011                 be      loc_F00F02EC
F00F02AC: a0102000                 mov     0, %l0
F00F02B0: d402e004                 ld      [%o3+4], %o2
F00F02B4: 9482bfff                 inccc   -1, %o2
F00F02B8: 0c800008                 bneg    loc_F00F02D8
F00F02BC: 9202e008                 add     %o3, 8, %o1
F00F02C0: d0024000                 ld      [%o1], %o0
F00F02C4: 80a64008                 cmp     %i1, %o0
F00F02C8: 0280001f                 be      loc_F00F0344
F00F02CC: 9482bfff                 inccc   -1, %o2
F00F02D0: 1cbffffc                 bpos    loc_F00F02C0
F00F02D4: 9202600c                 inc     0xC, %o1
F00F02D8: d602c000                 ld      [%o3], %o3
F00F02DC: 80a2e000                 cmp     %o3, 0
F00F02E0: 32bffff5                 bne,a   loc_F00F02B4
F00F02E4: d402e004                 ld      [%o3+4], %o2
F00F02E8: a0102000                 mov     0, %l0
F00F02EC: 80a42000                 cmp     %l0, 0
F00F02F0: 12800017                 bne     loc_F00F034C
F00F02F4: 90100018                 mov     %i0, %o0
F00F02F8: e2046004                 ld      [%l1+4], %l1
F00F02FC: 80a46000                 cmp     %l1, 0
F00F0300: 32bfffe9                 bne,a   loc_F00F02A4
F00F0304: d604601c                 ld      [%l1+0x1C], %o3
F00F0308: 40000211                 call    _NXDefaultMallocZone
F00F030C: 01000000                 nop
F00F0310: 4000020f                 call    _NXDefaultMallocZone
F00F0314: a0100008                 mov     %o0, %l0
F00F0318: d4042004                 ld      [%l0+4], %o2
F00F031C: 9fc28000                 call    %o2
F00F0320: 9210200c                 mov     0xC, %o1
F00F0324: 92100008                 mov     %o0, %o1
F00F0328: f2224000                 st      %i1, [%o1]
F00F032C: e6226004                 st      %l3, [%o1+4]
F00F0330: e4226008                 st      %l2, [%o1+8]
F00F0334: 7fffff6c                 call    sub_F00F00E4
F00F0338: 90100018                 mov     %i0, %o0
F00F033C: 10800007                 ba      locret_F00F0358
F00F0340: b0100012                 mov     %l2, %i0
F00F0344: 10bfffea                 ba      loc_F00F02EC
F00F0348: a0100009                 mov     %o1, %l0
F00F034C: 7fffff66                 call    sub_F00F00E4
F00F0350: 92100010                 mov     %l0, %o1
F00F0354: f0042008                 ld      [%l0+8], %i0
F00F0358: 81c7e008                 ret
F00F035C: 81e80000                 restore
