F0077F38: 9de3bf98                 save    %sp, -0x68, %sp
F0077F3C: 113c04f2                 sethi   %hi(_zone_zone), %o0
F0077F40: d00223e8                 ld      [%o0+%lo(_zone_zone)], %o0
F0077F44: 80a22000                 cmp     %o0, 0
F0077F48: 1280000d                 bne     loc_F0077F7C
F0077F4C: a0100018                 mov     %i0, %l0
F0077F50: 113c04f290122350         set     __zone_default_space, %o0
F0077F58: 92102044                 mov     0x44, %o1 ! 'D'
F0077F5C: 40000222                 call    _zget_space
F0077F60: 94102000                 mov     0, %o2
F0077F64: 10800009                 ba      loc_F0077F88
F0077F68: b0100008                 mov     %o0, %i0
F0077F6C: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0077F70: 7fffc366                 call    _lock_init
F0077F74: 92102001                 mov     1, %o1
F0077F78: 30800037                 ba,a    loc_F0078054
F0077F7C: 40000454                 call    _zalloc
F0077F80: 01000000                 nop
F0077F84: b0100008                 mov     %o0, %i0
F0077F88: 80a62000                 cmp     %i0, 0
F0077F8C: 12800006                 bne     loc_F0077FA4
F0077F90: 80a6a000                 cmp     %i2, 0
F0077F94: 113c0442                 sethi   %hi(aZinit), %o0! "zinit"
F0077F98: 7ffe7476                 call    _panic
F0077F9C: 901223f8                 bset    %lo(aZinit), %o0! "zinit"
F0077FA0: 80a6a000                 cmp     %i2, 0
F0077FA4: 12800004                 bne     loc_F0077FB4
F0077FA8: 80a42000                 cmp     %l0, 0
F0077FAC: 113c0447                 sethi   %hi(_page_size), %o0
F0077FB0: f402213c                 ld      [%o0+%lo(_page_size)], %i2
F0077FB4: 22800002                 be,a    loc_F0077FBC
F0077FB8: a0102004                 mov     4, %l0
F0077FBC: 9204200f                 add     %l0, 0xF, %o1
F0077FC0: 113c04d0                 sethi   %hi(_page_mask), %o0
F0077FC4: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0077FC8: a00a7ff0                 and     %o1, -0x10, %l0
F0077FCC: 92064008                 add     %i1, %o0, %o1
F0077FD0: 94380008                 xnor    %g0, %o0, %o2
F0077FD4: b20a400a                 and     %o1, %o2, %i1
F0077FD8: 90068008                 add     %i2, %o0, %o0
F0077FDC: b40a000a                 and     %o0, %o2, %i2
F0077FE0: 80a6401a                 cmp     %i1, %i2
F0077FE4: 2a800002                 bcs,a   loc_F0077FEC
F0077FE8: b210001a                 mov     %i2, %i1
F0077FEC: c0262010                 clr     [%i0+0x10]
F0077FF0: c026200c                 clr     [%i0+0xC]
F0077FF4: c0262014                 clr     [%i0+0x14]
F0077FF8: f2262018                 st      %i1, [%i0+0x18]
F0077FFC: e026201c                 st      %l0, [%i0+0x1C]
F0078000: f4262020                 st      %i2, [%i0+0x20]
F0078004: f8262028                 st      %i4, [%i0+0x28]
F0078008: c0262008                 clr     [%i0+8]
F007800C: c0262024                 clr     [%i0+0x24]
F0078010: d206202c                 ld      [%i0+0x2C], %o1
F0078014: 11200000                 sethi   0x80000000, %o0
F0078018: 902a4008                 andn    %o1, %o0, %o0
F007801C: 932ee01f                 sll     %i3, 31, %o1
F0078020: 90120009                 bset    %o1, %o0
F0078024: d026202c                 st      %o0, [%i0+0x2C]
F0078028: d006202c                 ld      [%i0+0x2C], %o0
F007802C: 13100000                 sethi   0x40000000, %o1
F0078030: 922a0009                 andn    %o0, %o1, %o1
F0078034: 11080000                 sethi   0x20000000, %o0
F0078038: 902a4008                 andn    %o1, %o0, %o0
F007803C: 13040000                 sethi   0x10000000, %o1
F0078040: 90120009                 bset    %o1, %o0
F0078044: 80a22000                 cmp     %o0, 0
F0078048: 06bfffc9                 bl      loc_F0077F6C
F007804C: d026202c                 st      %o0, [%i0+0x2C]
F0078050: c0260000                 clr     [%i0]
F0078054: 40000298                 call    sub_F0078AB4
F0078058: 90100018                 mov     %i0, %o0
F007805C: c0262040                 clr     [%i0+0x40]
F0078060: 113c04f2b2122380         set     _all_zones_lock, %i1
F0078068: d0064000                 ld      [%i1], %o0
F007806C: 80a22000                 cmp     %o0, 0
F0078070: 12bffffe                 bne     loc_F0078068
F0078074: 01000000                 nop
F0078078: 40007b8c                 call    _simple_lock_try
F007807C: 90100019                 mov     %i1, %o0
F0078080: 80a22000                 cmp     %o0, 0
F0078084: 02bffff9                 be      loc_F0078068
F0078088: 133c04f2                 sethi   %hi(_last_zone), %o1
F007808C: d0026390                 ld      [%o1+%lo(_last_zone)], %o0
F0078090: 153c04f2                 sethi   %hi(_num_zones), %o2
F0078094: f0220000                 st      %i0, [%o0]
F0078098: 90062040                 add     %i0, 0x40, %o0 ! '@'
F007809C: d0226390                 st      %o0, [%o1+%lo(_last_zone)]
F00780A0: 133c04f2                 sethi   %hi(_all_zones_lock), %o1
F00780A4: d002a398                 ld      [%o2+%lo(_num_zones)], %o0
F00780A8: c0226380                 clr     [%o1+%lo(_all_zones_lock)]
F00780AC: 90022001                 inc     %o0
F00780B0: d022a398                 st      %o0, [%o2+%lo(_num_zones)]
F00780B4: 81c7e008                 ret
F00780B8: 81e80000                 restore
