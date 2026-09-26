F004CBE8: 9de3bf98                 save    %sp, -0x68, %sp
F004CBEC: e0062050                 ld      [%i0+0x50], %l0
F004CBF0: d2042050                 ld      [%l0+0x50], %o1
F004CBF4: 97364009                 srl     %i1, %o1, %o3
F004CBF8: 80a2e00b                 cmp     %o3, 0xB
F004CBFC: 34800010                 bg,a    loc_F004CC3C
F004CC00: e4042030                 ld      [%l0+0x30], %l2
F004CC04: 9002e001                 add     %o3, 1, %o0
F004CC08: d4062070                 ld      [%i0+0x70], %o2
F004CC0C: 912a0009                 sll     %o0, %o1, %o0
F004CC10: 80a28008                 cmp     %o2, %o0
F004CC14: 2a800004                 bcs,a   loc_F004CC24
F004CC18: d0042048                 ld      [%l0+0x48], %o0
F004CC1C: 10800008                 ba      loc_F004CC3C
F004CC20: e4042030                 ld      [%l0+0x30], %l2
F004CC24: d2042034                 ld      [%l0+0x34], %o1
F004CC28: 902a8008                 andn    %o2, %o0, %o0
F004CC2C: 90020009                 add     %o0, %o1, %o0
F004CC30: d204204c                 ld      [%l0+0x4C], %o1
F004CC34: 90023fff                 inc     -1, %o0
F004CC38: a40a0009                 and     %o0, %o1, %l2
F004CC3C: 90100018                 mov     %i0, %o0
F004CC40: 9210000b                 mov     %o3, %o1
F004CC44: 7ffff7ac                 call    _bmap
F004CC48: 94102001                 mov     1, %o2
F004CC4C: d2042064                 ld      [%l0+0x64], %o1
F004CC50: a32a0009                 sll     %o0, %o1, %l1
F004CC54: 80a46000                 cmp     %l1, 0
F004CC58: 1680000c                 bge     loc_F004CC88
F004CC5C: 113c04cf                 sethi   -0xFECC400, %o0
F004CC60: 90100018                 mov     %i0, %o0
F004CC64: 133c043a92126328         set     aNonexixtentDir, %o1! "nonexixtent directory block"
F004CC6C: 40000048                 call    sub_F004CD8C
F004CC70: 94100019                 mov     %i1, %o2
F004CC74: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004CC78: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F004CC7C: 90102002                 mov     2, %o0
F004CC80: d02a6038                 stb     %o0, [%o1+0x38]
F004CC84: 113c04cf                 sethi   -0xFECC400, %o0
F004CC88: d00221dc                 ld      [%o0+0x1DC], %o0
F004CC8C: d04a2038                 ldsb    [%o0+0x38], %o0
F004CC90: 80a22000                 cmp     %o0, 0
F004CC94: 02800004                 be      loc_F004CCA4
F004CC98: 92100011                 mov     %l1, %o1
F004CC9C: 10800015                 ba      locret_F004CCF0
F004CCA0: b0102000                 mov     0, %i0
F004CCA4: d0062040                 ld      [%i0+0x40], %o0
F004CCA8: 7fff5e1e                 call    _bread
F004CCAC: 94100012                 mov     %l2, %o2
F004CCB0: b0100008                 mov     %o0, %i0
F004CCB4: d0060000                 ld      [%i0], %o0
F004CCB8: 808a2004                 btst    4, %o0
F004CCBC: 02800006                 be      loc_F004CCD4
F004CCC0: 80a6a000                 cmp     %i2, 0
F004CCC4: 7fff5ee9                 call    _brelse
F004CCC8: 90100018                 mov     %i0, %o0
F004CCCC: 10800009                 ba      locret_F004CCF0
F004CCD0: b0102000                 mov     0, %i0
F004CCD4: 02800007                 be      locret_F004CCF0
F004CCD8: 01000000                 nop
F004CCDC: d0042048                 ld      [%l0+0x48], %o0
F004CCE0: d2062020                 ld      [%i0+0x20], %o1
F004CCE4: 902e4008                 andn    %i1, %o0, %o0
F004CCE8: 92024008                 add     %o1, %o0, %o1
F004CCEC: d2268000                 st      %o1, [%i2]
F004CCF0: 81c7e008                 ret
F004CCF4: 81e80000                 restore
