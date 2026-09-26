F004FF0C: 9de3bf98                 save    %sp, -0x68, %sp
F004FF10: e2062050                 ld      [%i0+0x50], %l1
F004FF14: d0062070                 ld      [%i0+0x70], %o0
F004FF18: d2046030                 ld      [%l1+0x30], %o1
F004FF1C: 90023fff                 inc     -1, %o0
F004FF20: 7ffed9b8                 call    _udiv
F004FF24: 90020009                 add     %o0, %o1, %o0
F004FF28: 133c0470                 sethi   %hi(_nbuf), %o1
F004FF2C: d2026058                 ld      [%o1+%lo(_nbuf)], %o1
F004FF30: a4100008                 mov     %o0, %l2
F004FF34: 9132601f                 srl     %o1, 31, %o0
F004FF38: 90024008                 add     %o1, %o0, %o0
F004FF3C: 913a2001                 sra     %o0, 1, %o0
F004FF40: 80a48008                 cmp     %l2, %o0
F004FF44: 36800026                 bge,a   loc_F004FFDC
F004FF48: 113c04cf                 sethi   -0xFECC400, %o0
F004FF4C: a0102000                 mov     0, %l0
F004FF50: 80a40012                 cmp     %l0, %l2
F004FF54: 1680005a                 bge     loc_F00500BC
F004FF58: 90100018                 mov     %i0, %o0
F004FF5C: 92100010                 mov     %l0, %o1
F004FF60: 7fffeae5                 call    _bmap
F004FF64: 94102001                 mov     1, %o2
F004FF68: d2046064                 ld      [%l1+0x64], %o1
F004FF6C: 80a4200b                 cmp     %l0, 0xB
F004FF70: d8062040                 ld      [%i0+0x40], %o4
F004FF74: 14800009                 bg      loc_F004FF98
F004FF78: 972a0009                 sll     %o0, %o1, %o3
F004FF7C: d2046050                 ld      [%l1+0x50], %o1
F004FF80: 90042001                 add     %l0, 1, %o0
F004FF84: d4062070                 ld      [%i0+0x70], %o2
F004FF88: 912a0009                 sll     %o0, %o1, %o0
F004FF8C: 80a28008                 cmp     %o2, %o0
F004FF90: 2a800004                 bcs,a   loc_F004FFA0
F004FF94: d0046048                 ld      [%l1+0x48], %o0
F004FF98: 10800008                 ba      loc_F004FFB8
F004FF9C: d4046030                 ld      [%l1+0x30], %o2
F004FFA0: d2046034                 ld      [%l1+0x34], %o1
F004FFA4: 902a8008                 andn    %o2, %o0, %o0
F004FFA8: 90020009                 add     %o0, %o1, %o0
F004FFAC: d204604c                 ld      [%l1+0x4C], %o1
F004FFB0: 90023fff                 inc     -1, %o0
F004FFB4: 940a0009                 and     %o0, %o1, %o2
F004FFB8: 9010000c                 mov     %o4, %o0
F004FFBC: 7fff5463                 call    _blkflush
F004FFC0: 9210000b                 mov     %o3, %o1
F004FFC4: a0042001                 inc     %l0
F004FFC8: 80a40012                 cmp     %l0, %l2
F004FFCC: 06bfffe4                 bl      loc_F004FF5C
F004FFD0: 90100018                 mov     %i0, %o0
F004FFD4: 1080003b                 ba      loc_F00500C0
F004FFD8: d4122044                 lduh    [%o0+0x44], %o2
F004FFDC: d00222f0                 ld      [%o0+0x2F0], %o0
F004FFE0: a0100008                 mov     %o0, %l0
F004FFE4: 912a6004                 sll     %o1, 4, %o0
F004FFE8: 90020009                 add     %o0, %o1, %o0
F004FFEC: 912a2002                 sll     %o0, 2, %o0
F004FFF0: a6040008                 add     %l0, %o0, %l3
F004FFF4: 80a40013                 cmp     %l0, %l3
F004FFF8: 1a800031                 bcc     loc_F00500BC
F004FFFC: 90100018                 mov     %i0, %o0
F0050000: a2042010                 add     %l0, 0x10, %l1
F0050004: d2046030                 ld      [%l1+0x30], %o1
F0050008: d0062040                 ld      [%i0+0x40], %o0
F005000C: 80a24008                 cmp     %o1, %o0
F0050010: 32800027                 bne,a   loc_F00500AC
F0050014: a0042044                 inc     0x44, %l0 ! 'D'
F0050018: d0040000                 ld      [%l0], %o0
F005001C: 808a2200                 btst    0x200, %o0
F0050020: 22800023                 be,a    loc_F00500AC
F0050024: a0042044                 inc     0x44, %l0 ! 'D'
F0050028: 40011ae4                 call    _spltty
F005002C: 01000000                 nop
F0050030: d2040000                 ld      [%l0], %o1
F0050034: 808a6008                 btst    8, %o1
F0050038: 0280000c                 be      loc_F0050068
F005003C: a4100008                 mov     %o0, %l2
F0050040: 90126040                 or      %o1, 0x40, %o0
F0050044: d0240000                 st      %o0, [%l0]
F0050048: 90100010                 mov     %l0, %o0! unsigned int
F005004C: 7fff098b                 call    _sleep
F0050050: 92102015                 mov     0x15, %o1
F0050054: 40011b34                 call    _splx
F0050058: 90100012                 mov     %l2, %o0
F005005C: a2047fbc                 inc     -0x44, %l1
F0050060: 10800012                 ba      loc_F00500A8
F0050064: a0043fbc                 inc     -0x44, %l0
F0050068: 40011b2f                 call    _splx
F005006C: 90100012                 mov     %l2, %o0
F0050070: 40011ad2                 call    _spltty
F0050074: 01000000                 nop
F0050078: d4044000                 ld      [%l1], %o2
F005007C: d2047ffc                 ld      [%l1-4], %o1
F0050080: d222a00c                 st      %o1, [%o2+0xC]
F0050084: d4047ffc                 ld      [%l1-4], %o2
F0050088: d2044000                 ld      [%l1], %o1
F005008C: d222a010                 st      %o1, [%o2+0x10]
F0050090: d2040000                 ld      [%l0], %o1
F0050094: 92126008                 bset    8, %o1
F0050098: 40011b23                 call    _splx
F005009C: d2240000                 st      %o1, [%l0]
F00500A0: 7fff51b2                 call    _bwrite
F00500A4: 90100010                 mov     %l0, %o0
F00500A8: a0042044                 inc     0x44, %l0 ! 'D'
F00500AC: 80a40013                 cmp     %l0, %l3
F00500B0: 0abfffd5                 bcs     loc_F0050004
F00500B4: a2046044                 inc     0x44, %l1 ! 'D'
F00500B8: 90100018                 mov     %i0, %o0
F00500BC: d4122044                 lduh    [%o0+0x44], %o2
F00500C0: 92102001                 mov     1, %o1
F00500C4: 9412a040                 bset    0x40, %o2 ! '@'
F00500C8: 7ffff91f                 call    _iupdat
F00500CC: d4322044                 sth     %o2, [%o0+0x44]
F00500D0: 81c7e008                 ret
F00500D4: 81e80000                 restore
