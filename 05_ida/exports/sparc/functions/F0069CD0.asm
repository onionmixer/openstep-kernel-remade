F0069CD0: 9de3bf98                 save    %sp, -0x68, %sp
F0069CD4: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0069CD8: 253c043f                 sethi   %hi(_mtime), %l2
F0069CDC: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0069CE0: 213c0447                 sethi   %hi(_page_size), %l0
F0069CE4: d404213c                 ld      [%l0+%lo(_page_size)], %o2
F0069CE8: 400066c7                 call    _kmem_alloc_wired
F0069CEC: 9214a000                 or      %l2, %lo(_mtime), %o1! size_t
F0069CF0: 80a22000                 cmp     %o0, 0
F0069CF4: 22800006                 be,a    loc_F0069D0C
F0069CF8: d004a000                 ld      [%l2+%lo(_mtime)], %o0
F0069CFC: 113c043f                 sethi   %hi(aMappableTimeIn), %o0! "mappable_time_init"
F0069D00: 7ffead1c                 call    _panic
F0069D04: 90122008                 bset    %lo(aMappableTimeIn), %o0! "mappable_time_init"
F0069D08: d004a000                 ld      [%l2+%lo(_mtime)], %o0! void *
F0069D0C: 4000ac53                 call    _bzero
F0069D10: d204213c                 ld      [%l0+0x13C], %o1
F0069D14: 4000b39d                 call    _splusclock
F0069D18: 213c043e                 sethi   %hi(_time), %l0
F0069D1C: a6100008                 mov     %o0, %l3
F0069D20: a21423e8                 or      %l0, %lo(_time), %l1
F0069D24: 400011b2                 call    _get_calendar_time_value
F0069D28: 90100011                 mov     %l1, %o0
F0069D2C: d204a000                 ld      [%l2], %o1
F0069D30: 80a26000                 cmp     %o1, 0
F0069D34: 02800007                 be      loc_F0069D50
F0069D38: d00423e8                 ld      [%l0+%lo(_time)], %o0
F0069D3C: d0226008                 st      %o0, [%o1+8]
F0069D40: d0046004                 ld      [%l1+4], %o0
F0069D44: d0226004                 st      %o0, [%o1+4]
F0069D48: d00423e8                 ld      [%l0+%lo(_time)], %o0
F0069D4C: d0224000                 st      %o0, [%o1]
F0069D50: 4000b3f5                 call    _splx
F0069D54: 90100013                 mov     %l3, %o0
F0069D58: 81c7e008                 ret
F0069D5C: 81e80000                 restore
