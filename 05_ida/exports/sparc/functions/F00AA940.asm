F00AA940: 9de3bf90                 save    %sp, -0x70, %sp
F00AA944: 113c043c                 sethi   %hi(_nclist), %o0
F00AA948: d4022378                 ld      [%o0+%lo(_nclist)], %o2
F00AA94C: 213c0470                 sethi   %hi(_bufpages), %l0
F00AA950: 113c043c                 sethi   %hi(_ncsize), %o0
F00AA954: d2022384                 ld      [%o0+%lo(_ncsize)], %o1
F00AA958: 952aa006                 sll     %o2, 6, %o2
F00AA95C: 912a6003                 sll     %o1, 3, %o0
F00AA960: 90020009                 add     %o0, %o1, %o0
F00AA964: 912a2003                 sll     %o0, 3, %o0
F00AA968: d2042060                 ld      [%l0+%lo(_bufpages)], %o1
F00AA96C: 80a26000                 cmp     %o1, 0
F00AA970: 1280000a                 bne     loc_F00AA998
F00AA974: a2028008                 add     %o2, %o0, %l1
F00AA978: 113c04f0                 sethi   %hi(_mem_size), %o0
F00AA97C: d0022108                 ld      [%o0+%lo(_mem_size)], %o0
F00AA980: 7ffd6f20                 call    _udiv
F00AA984: 92102032                 mov     0x32, %o1 ! '2'
F00AA988: 133c04f4                 sethi   %hi(_page_shift), %o1
F00AA98C: d2026348                 ld      [%o1+%lo(_page_shift)], %o1
F00AA990: 91320009                 srl     %o0, %o1, %o0
F00AA994: d0242060                 st      %o0, [%l0+0x60]
F00AA998: 133c0470                 sethi   %hi(_nbuf), %o1
F00AA99C: d0026058                 ld      [%o1+%lo(_nbuf)], %o0
F00AA9A0: 80a22000                 cmp     %o0, 0
F00AA9A4: 12800009                 bne     loc_F00AA9C8
F00AA9A8: 253c0470                 sethi   -0xFEE4000, %l2
F00AA9AC: d0042060                 ld      [%l0+0x60], %o0
F00AA9B0: 80a2200f                 cmp     %o0, 0xF
F00AA9B4: 14800005                 bg      loc_F00AA9C8
F00AA9B8: d0226058                 st      %o0, [%o1+%lo(_nbuf)]
F00AA9BC: 90102010                 mov     0x10, %o0
F00AA9C0: d0226058                 st      %o0, [%o1+%lo(_nbuf)]
F00AA9C4: 253c0470                 sethi   -0xFEE4000, %l2
F00AA9C8: d004a058                 ld      [%l2+0x58], %o0
F00AA9CC: 80a220ff                 cmp     %o0, 0xFF
F00AA9D0: 24800005                 ble,a   loc_F00AA9E4
F00AA9D4: 113c0447                 sethi   -0xFEEE400, %o0
F00AA9D8: 901020ff                 mov     0xFF, %o0
F00AA9DC: d024a058                 st      %o0, [%l2+0x58]
F00AA9E0: 113c0447                 sethi   -0xFEEE400, %o0
F00AA9E4: d202213c                 ld      [%o0+0x13C], %o1
F00AA9E8: 7ffd6f06                 call    _udiv
F00AA9EC: 11000008                 sethi   0x2000, %o0
F00AA9F0: 92100008                 mov     %o0, %o1
F00AA9F4: 7ffd6ec3                 call    _umul
F00AA9F8: d004a058                 ld      [%l2+0x58], %o0
F00AA9FC: 213c0470                 sethi   %hi(_bufpages), %l0
F00AAA00: d2042060                 ld      [%l0+%lo(_bufpages)], %o1
F00AAA04: 80a24008                 cmp     %o1, %o0
F00AAA08: 38800002                 bgu,a   loc_F00AAA10
F00AAA0C: d0242060                 st      %o0, [%l0+%lo(_bufpages)]
F00AAA10: d404a058                 ld      [%l2+0x58], %o2
F00AAA14: 173c0470                 sethi   %hi(_nmfsbuf), %o3
F00AAA18: d202e05c                 ld      [%o3+%lo(_nmfsbuf)], %o1
F00AAA1C: 912aa004                 sll     %o2, 4, %o0
F00AAA20: 9002000a                 add     %o0, %o2, %o0
F00AAA24: 912a2002                 sll     %o0, 2, %o0
F00AAA28: 80a26000                 cmp     %o1, 0
F00AAA2C: 12800006                 bne     loc_F00AAA44
F00AAA30: a2044008                 add     %l1, %o0, %l1
F00AAA34: 9132a01f                 srl     %o2, 31, %o0
F00AAA38: 90028008                 add     %o2, %o0, %o0
F00AAA3C: 913a2001                 sra     %o0, 1, %o0
F00AAA40: d022e05c                 st      %o0, [%o3+%lo(_nmfsbuf)]
F00AAA44: 113c04d0                 sethi   %hi(_page_mask), %o0
F00AAA48: d60220d8                 ld      [%o0+%lo(_page_mask)], %o3
F00AAA4C: 9207bff4                 add     %fp, var_C, %o1! size_t
F00AAA50: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00AAA54: 9404400b                 add     %l1, %o3, %o2
F00AAA58: a22a800b                 andn    %o2, %o3, %l1
F00AAA5C: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00AAA60: 7fff6369                 call    _kmem_alloc_wired
F00AAA64: 94100011                 mov     %l1, %o2
F00AAA68: 80a22000                 cmp     %o0, 0
F00AAA6C: 02800004                 be      loc_F00AAA7C
F00AAA70: 113c0470                 sethi   %hi(aStartupEarlyNo), %o0! "startup_early: no memory"
F00AAA74: 7ffda9bf                 call    _panic
F00AAA78: 90122070                 bset    %lo(aStartupEarlyNo), %o0! "startup_early: no memory"
F00AAA7C: d007bff4                 ld      [%fp+var_C], %o0! void *
F00AAA80: 7fffa8f6                 call    _bzero
F00AAA84: 92100011                 mov     %l1, %o1
F00AAA88: 153c04d0                 sethi   %hi(_cfree), %o2
F00AAA8C: 113c043c                 sethi   %hi(_nclist), %o0
F00AAA90: d207bff4                 ld      [%fp+var_C], %o1
F00AAA94: 173c04d5                 sethi   %hi(_ncache), %o3
F00AAA98: d0022378                 ld      [%o0+%lo(_nclist)], %o0
F00AAA9C: d222a268                 st      %o1, [%o2+%lo(_cfree)]
F00AAAA0: 912a2006                 sll     %o0, 6, %o0
F00AAAA4: 92024008                 add     %o1, %o0, %o1
F00AAAA8: d227bff4                 st      %o1, [%fp+var_C]
F00AAAAC: 113c043c                 sethi   %hi(_ncsize), %o0
F00AAAB0: d4022384                 ld      [%o0+%lo(_ncsize)], %o2
F00AAAB4: d222e1e0                 st      %o1, [%o3+%lo(_ncache)]
F00AAAB8: 912aa003                 sll     %o2, 3, %o0
F00AAABC: 9002000a                 add     %o0, %o2, %o0
F00AAAC0: 912a2003                 sll     %o0, 3, %o0
F00AAAC4: 92024008                 add     %o1, %o0, %o1
F00AAAC8: d227bff4                 st      %o1, [%fp+var_C]
F00AAACC: 113c04cf                 sethi   %hi(_buf), %o0
F00AAAD0: d404a058                 ld      [%l2+0x58], %o2
F00AAAD4: d22222f0                 st      %o1, [%o0+%lo(_buf)]
F00AAAD8: 912aa004                 sll     %o2, 4, %o0
F00AAADC: 9002000a                 add     %o0, %o2, %o0
F00AAAE0: 912a2002                 sll     %o0, 2, %o0
F00AAAE4: 92024008                 add     %o1, %o0, %o1
F00AAAE8: d227bff4                 st      %o1, [%fp+var_C]
F00AAAEC: 81c7e008                 ret
F00AAAF0: 81e80000                 restore
