F00EA928: 9de3bf88                 save    %sp, -0x78, %sp
F00EA92C: e4062014                 ld      [%i0+0x14], %l2
F00EA930: d0062008                 ld      [%i0+8], %o0
F00EA934: 9210001a                 mov     %i2, %o1
F00EA938: 7ffffe36                 call    sub_F00EA210
F00EA93C: d4062010                 ld      [%i0+0x10], %o2
F00EA940: a6100008                 mov     %o0, %l3
F00EA944: 912ce003                 sll     %l3, 3, %o0
F00EA948: d2048008                 ld      [%l2+%o0], %o1
F00EA94C: d227bfe8                 st      %o1, [%fp+__len]
F00EA950: 90048008                 add     %l2, %o0, %o0
F00EA954: d0022004                 ld      [%o0+4], %o0
F00EA958: d027bfec                 st      %o0, [%fp+__src]
F00EA95C: a2027fff                 add     %o1, -1, %l1
F00EA960: 80a47fff                 cmp     %l1, -1
F00EA964: 02800010                 be      loc_F00EA9A4
F00EA968: a0100008                 mov     %o0, %l0
F00EA96C: d0062008                 ld      [%i0+8], %o0
F00EA970: 9210001a                 mov     %i2, %o1! SEL
F00EA974: 7ffffe5d                 call    sub_F00EA2E8
F00EA978: d4040000                 ld      [%l0], %o2
F00EA97C: 80a22000                 cmp     %o0, 0
F00EA980: 02800006                 be      loc_F00EA998
F00EA984: a2047fff                 inc     -1, %l1
F00EA988: f0042004                 ld      [%l0+4], %i0
F00EA98C: f4240000                 st      %i2, [%l0]
F00EA990: 1080002c                 ba      locret_F00EAA40
F00EA994: f6242004                 st      %i3, [%l0+4]
F00EA998: 80a47fff                 cmp     %l1, -1
F00EA99C: 12bffff4                 bne     loc_F00EA96C
F00EA9A0: a0042008                 inc     8, %l0
F00EA9A4: 213c0506                 sethi   %hi(paZone), %l0
F00EA9A8: 90100018                 mov     %i0, %o0! id
F00EA9AC: 40001bb1                 call    _objc_msgSend
F00EA9B0: d2042254                 ld      [%l0+%lo(paZone)], %o1! SEL
F00EA9B4: a2100008                 mov     %o0, %l1
F00EA9B8: 90100018                 mov     %i0, %o0! id
F00EA9BC: 40001bad                 call    _objc_msgSend
F00EA9C0: d2042254                 ld      [%l0+%lo(paZone)], %o1
F00EA9C4: d207bfe8                 ld      [%fp+__len], %o1
F00EA9C8: 92026001                 inc     %o1
F00EA9CC: d4046004                 ld      [%l1+4], %o2
F00EA9D0: 9fc28000                 call    %o2
F00EA9D4: 932a6003                 sll     %o1, 3, %o1
F00EA9D8: d407bfe8                 ld      [%fp+__len], %o2! __len
F00EA9DC: 80a2a000                 cmp     %o2, 0
F00EA9E0: 02800006                 be      loc_F00EA9F8
F00EA9E4: a0100008                 mov     %o0, %l0
F00EA9E8: 90042008                 add     %l0, 8, %o0! __dst
F00EA9EC: d207bfec                 ld      [%fp+__src], %o1! __src
F00EA9F0: 7ffc7578                 call    _memmove
F00EA9F4: 952aa003                 sll     %o2, 3, %o2
F00EA9F8: f4240000                 st      %i2, [%l0]
F00EA9FC: f6242004                 st      %i3, [%l0+4]
F00EAA00: d007bfe8                 ld      [%fp+__len], %o0! void *
F00EAA04: 80a22000                 cmp     %o0, 0
F00EAA08: 02800005                 be      loc_F00EAA1C
F00EAA0C: 932ce003                 sll     %l3, 3, %o1
F00EAA10: 7ffdf63c                 call    _free
F00EAA14: d007bfec                 ld      [%fp+__src], %o0
F00EAA18: 932ce003                 sll     %l3, 3, %o1
F00EAA1C: 94048009                 add     %l2, %o1, %o2
F00EAA20: d0048009                 ld      [%l2+%o1], %o0
F00EAA24: 90022001                 inc     %o0
F00EAA28: d0248009                 st      %o0, [%l2+%o1]
F00EAA2C: e022a004                 st      %l0, [%o2+4]
F00EAA30: d0062004                 ld      [%i0+4], %o0
F00EAA34: 90022001                 inc     %o0
F00EAA38: d0262004                 st      %o0, [%i0+4]
F00EAA3C: b0102000                 mov     0, %i0
F00EAA40: 81c7e008                 ret
F00EAA44: 81e80000                 restore
