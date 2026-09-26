F00A1CDC: 9de3bf98                 save    %sp, -0x68, %sp
F00A1CE0: 213c0447                 sethi   %hi(_page_size), %l0
F00A1CE4: d004213c                 ld      [%l0+%lo(_page_size)], %o0
F00A1CE8: 133c04f7                 sethi   %hi(_pmap_info), %o1
F00A1CEC: 9132200c                 srl     %o0, 12, %o0
F00A1CF0: d0326270                 sth     %o0, [%o1+%lo(_pmap_info)]
F00A1CF4: 912a2010                 sll     %o0, 16, %o0
F00A1CF8: 91322010                 srl     %o0, 16, %o0
F00A1CFC: 80a22040                 cmp     %o0, 0x40 ! '@'
F00A1D00: 08800005                 bleu    loc_F00A1D14
F00A1D04: a4126270                 or      %o1, %lo(_pmap_info), %l2
F00A1D08: 113c0463                 sethi   %hi(aFillPmapinfoVi), %o0! "fill_pmapinfo: virutal page size too bi"...
F00A1D0C: 7ffdcd19                 call    _panic
F00A1D10: 90122298                 bset    %lo(aFillPmapinfoVi), %o0! "fill_pmapinfo: virutal page size too bi"...
F00A1D14: e204213c                 ld      [%l0+0x13C], %l1
F00A1D18: 9534600a                 srl     %l1, 10, %o2
F00A1D1C: d434a002                 sth     %o2, [%l2+2]
F00A1D20: a1346008                 srl     %l1, 8, %l0
F00A1D24: e034a004                 sth     %l0, [%l2+4]
F00A1D28: 90100011                 mov     %l1, %o0
F00A1D2C: 952aa010                 sll     %o2, 16, %o2
F00A1D30: 9532a010                 srl     %o2, 16, %o2
F00A1D34: 932aa002                 sll     %o2, 2, %o1
F00A1D38: 9202400a                 add     %o1, %o2, %o1
F00A1D3C: 932a6002                 sll     %o1, 2, %o1
F00A1D40: 9202400a                 add     %o1, %o2, %o1
F00A1D44: 7ffd922f                 call    _udiv
F00A1D48: 932a6002                 sll     %o1, 2, %o1
F00A1D4C: d034a006                 sth     %o0, [%l2+6]
F00A1D50: 90100011                 mov     %l1, %o0
F00A1D54: a12c2010                 sll     %l0, 16, %l0
F00A1D58: a1342010                 srl     %l0, 16, %l0
F00A1D5C: 932c2002                 sll     %l0, 2, %o1
F00A1D60: 92024010                 add     %o1, %l0, %o1
F00A1D64: 7ffd9227                 call    _udiv
F00A1D68: 932a6003                 sll     %o1, 3, %o1
F00A1D6C: d034a008                 sth     %o0, [%l2+8]
F00A1D70: 81c7e008                 ret
F00A1D74: 81e80000                 restore
