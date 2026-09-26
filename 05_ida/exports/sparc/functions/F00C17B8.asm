F00C17B8: 9de3bf40                 save    %sp, -0xC0, %sp
F00C17BC: d0062140                 ld      [%i0+0x140], %o0
F00C17C0: 80a22000                 cmp     %o0, 0
F00C17C4: 02800028                 be      locret_F00C1864
F00C17C8: 01000000                 nop
F00C17CC: 7fff54fb                 call    _spltty
F00C17D0: 01000000                 nop
F00C17D4: 133c04cb                 sethi   %hi(dword_F0132FF0), %o1
F00C17D8: d40263f0                 ld      [%o1+%lo(dword_F0132FF0)], %o2
F00C17DC: 80a2a001                 cmp     %o2, 1
F00C17E0: 12800009                 bne     loc_F00C1804
F00C17E4: a0100008                 mov     %o0, %l0
F00C17E8: 113c04cb                 sethi   %hi(qword_F0132FA0), %o0
F00C17EC: d41a23a0                 ldd     [%o0+%lo(qword_F0132FA0)], %o2! size_t
F00C17F0: 901223a0                 bset    %lo(qword_F0132FA0), %o0
F00C17F4: d01a2008                 ldd     [%o0+8], %o0
F00C17F8: d43fbfa0                 std     %o2, [%fp+var_60]
F00C17FC: 10800007                 ba      loc_F00C1818
F00C1800: d03fbfa8                 std     %o0, [%fp+var_58]
F00C1804: 113c04cb901223a0         set     qword_F0132FA0, %o0! void *
F00C180C: 9207bfa0                 add     %fp, var_60, %o1! void *
F00C1810: 7fff4cc0                 call    _bcopy
F00C1814: 952aa004                 sll     %o2, 4, %o2
F00C1818: 90100010                 mov     %l0, %o0
F00C181C: 133c04cb                 sethi   %hi(dword_F0132FF0), %o1
F00C1820: e40263f0                 ld      [%o1+%lo(dword_F0132FF0)], %l2
F00C1824: a0102000                 mov     0, %l0
F00C1828: 7fff553f                 call    _splx
F00C182C: c02263f0                 clr     [%o1+%lo(dword_F0132FF0)]
F00C1830: 80a40012                 cmp     %l0, %l2
F00C1834: 1680000c                 bge     locret_F00C1864
F00C1838: 273c0504                 sethi   -0xFEBF000, %l3
F00C183C: a207bfa0                 add     %fp, var_60, %l1
F00C1840: 94100011                 mov     %l1, %o2
F00C1844: d0062140                 ld      [%i0+0x140], %o0! id
F00C1848: a2046010                 inc     0x10, %l1
F00C184C: d204e304                 ld      [%l3+0x304], %o1! SEL
F00C1850: 4000c008                 call    _objc_msgSend
F00C1854: a0042001                 inc     %l0
F00C1858: 80a40012                 cmp     %l0, %l2
F00C185C: 06bffffa                 bl      loc_F00C1844
F00C1860: 94100011                 mov     %l1, %o2
F00C1864: 81c7e008                 ret
F00C1868: 81e80000                 restore
