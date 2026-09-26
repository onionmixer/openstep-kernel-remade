F005102C: 9de3bf98                 save    %sp, -0x68, %sp
F0051030: d0062128                 ld      [%i0+0x128], %o0
F0051034: d002200c                 ld      [%o0+0xC], %o0
F0051038: e4022020                 ld      [%o0+0x20], %l2
F005103C: 11000046                 sethi   0x11800, %o0
F0051040: d204a55c                 ld      [%l2+0x55C], %o1
F0051044: 90122154                 bset    0x154, %o0
F0051048: 80a24008                 cmp     %o1, %o0
F005104C: 02800004                 be      loc_F005105C
F0051050: 113c043c                 sethi   %hi(aUfsStatfs), %o0! "ufs_statfs"
F0051054: 7fff1047                 call    _panic
F0051058: 90122150                 bset    %lo(aUfsStatfs), %o0! "ufs_statfs"
F005105C: d004a034                 ld      [%l2+0x34], %o0
F0051060: d0266004                 st      %o0, [%i1+4]
F0051064: d004a028                 ld      [%l2+0x28], %o0
F0051068: d0266008                 st      %o0, [%i1+8]
F005106C: d004a0c4                 ld      [%l2+0xC4], %o0
F0051070: 7ffed524                 call    _umul
F0051074: d204a038                 ld      [%l2+0x38], %o1
F0051078: d204a0cc                 ld      [%l2+0xCC], %o1
F005107C: a2100008                 mov     %o0, %l1
F0051080: a2044009                 add     %l1, %o1, %l1
F0051084: e226600c                 st      %l1, [%i1+0xC]
F0051088: e004a028                 ld      [%l2+0x28], %l0
F005108C: 92102064                 mov     0x64, %o1 ! 'd'
F0051090: d404a03c                 ld      [%l2+0x3C], %o2
F0051094: 90100010                 mov     %l0, %o0! int
F0051098: 7ffed51a                 call    _umul
F005109C: 9222400a                 sub     %o1, %o2, %o1! int
F00510A0: 7ffed55a                 call    _div
F00510A4: 92102064                 mov     0x64, %o1 ! 'd'
F00510A8: a0240011                 sub     %l0, %l1, %l0
F00510AC: 90220010                 sub     %o0, %l0, %o0
F00510B0: d0266010                 st      %o0, [%i1+0x10]
F00510B4: d004a02c                 ld      [%l2+0x2C], %o0
F00510B8: 7ffed512                 call    _umul
F00510BC: d204a0b8                 ld      [%l2+0xB8], %o1
F00510C0: d0266014                 st      %o0, [%i1+0x14]
F00510C4: 90062014                 add     %i0, 0x14, %o0! void *
F00510C8: d404a0c8                 ld      [%l2+0xC8], %o2! size_t
F00510CC: 9206601c                 add     %i1, 0x1C, %o1! void *
F00510D0: d4266018                 st      %o2, [%i1+0x18]
F00510D4: 40010e8f                 call    _bcopy
F00510D8: 94102008                 mov     8, %o2
F00510DC: 81c7e008                 ret
F00510E0: 91e82000                 restore %g0, 0, %o0
