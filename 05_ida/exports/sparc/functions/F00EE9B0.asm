F00EE9B0: 9de3bf98                 save    %sp, -0x68, %sp
F00EE9B4: e606200c                 ld      [%i0+0xC], %l3
F00EE9B8: a4100013                 mov     %l3, %l2
F00EE9BC: e2062008                 ld      [%i0+8], %l1
F00EE9C0: e8062004                 ld      [%i0+4], %l4
F00EE9C4: 90046001                 add     %l1, 1, %o0
F00EE9C8: 90020011                 add     %o0, %l1, %o0
F00EE9CC: d0262008                 st      %o0, [%i0+8]
F00EE9D0: c0262004                 clr     [%i0+4]
F00EE9D4: 40000861                 call    _NXZoneFromPtr
F00EE9D8: 90100018                 mov     %i0, %o0
F00EE9DC: e0062008                 ld      [%i0+8], %l0
F00EE9E0: d4022004                 ld      [%o0+4], %o2
F00EE9E4: 9fc28000                 call    %o2
F00EE9E8: 932c2003                 sll     %l0, 3, %o1
F00EE9EC: a0043fff                 inc     -1, %l0
F00EE9F0: 80a43fff                 cmp     %l0, -1
F00EE9F4: 02800009                 be      loc_F00EEA18
F00EE9F8: 92100008                 mov     %o0, %o1
F00EE9FC: 94103fff                 mov     -1, %o2
F00EEA00: d4224000                 st      %o2, [%o1]
F00EEA04: c0226004                 clr     [%o1+4]
F00EEA08: a0043fff                 inc     -1, %l0
F00EEA0C: 80a43fff                 cmp     %l0, -1
F00EEA10: 12bffffc                 bne     loc_F00EEA00
F00EEA14: 92026008                 inc     8, %o1
F00EEA18: d026200c                 st      %o0, [%i0+0xC]
F00EEA1C: 133c04bc                 sethi   %hi(dword_F012F0B8), %o1
F00EEA20: d00260b8                 ld      [%o1+%lo(dword_F012F0B8)], %o0
F00EEA24: 90022001                 inc     %o0
F00EEA28: d02260b8                 st      %o0, [%o1+%lo(dword_F012F0B8)]
F00EEA2C: 153c04bc                 sethi   %hi(dword_F012F0BC), %o2
F00EEA30: d002a0bc                 ld      [%o2+%lo(dword_F012F0BC)], %o0
F00EEA34: d2062004                 ld      [%i0+4], %o1
F00EEA38: 90020009                 add     %o0, %o1, %o0
F00EEA3C: 10800008                 ba      loc_F00EEA5C
F00EEA40: d022a0bc                 st      %o0, [%o2+%lo(dword_F012F0BC)]
F00EEA44: 80a27fff                 cmp     %o1, -1
F00EEA48: 02800004                 be      loc_F00EEA58
F00EEA4C: 90100018                 mov     %i0, %o0
F00EEA50: 40000011                 call    _NXMapInsert
F00EEA54: d404a004                 ld      [%l2+4], %o2
F00EEA58: a404a008                 inc     8, %l2
F00EEA5C: a2047fff                 inc     -1, %l1
F00EEA60: 80a47fff                 cmp     %l1, -1
F00EEA64: 32bffff8                 bne,a   loc_F00EEA44
F00EEA68: d2048000                 ld      [%l2], %o1
F00EEA6C: d0062004                 ld      [%i0+4], %o0
F00EEA70: 80a50008                 cmp     %l4, %o0
F00EEA74: 02800004                 be      loc_F00EEA84
F00EEA78: 113c03f3                 sethi   %hi(aMaptableCountD), %o0! "*** maptable: count differs after rehas"...
F00EEA7C: 400007b3                 call    __NXLogError
F00EEA80: 90122388                 bset    %lo(aMaptableCountD), %o0! "*** maptable: count differs after rehas"...
F00EEA84: 7ffde61f                 call    _free
F00EEA88: 90100013                 mov     %l3, %o0
F00EEA8C: 81c7e008                 ret
F00EEA90: 81e80000                 restore
