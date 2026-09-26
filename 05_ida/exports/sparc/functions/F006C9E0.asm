F006C9E0: 9de3bf98                 save    %sp, -0x68, %sp
F006C9E4: 113c04f0a0122210         set     _vm_info_lock_data, %l0
F006C9EC: d0040000                 ld      [%l0], %o0
F006C9F0: 80a22000                 cmp     %o0, 0
F006C9F4: 12bffffe                 bne     loc_F006C9EC
F006C9F8: 01000000                 nop
F006C9FC: 4000a92b                 call    _simple_lock_try
F006CA00: 90100010                 mov     %l0, %o0
F006CA04: 80a22000                 cmp     %o0, 0
F006CA08: 02bffff9                 be      loc_F006C9EC
F006CA0C: 01000000                 nop
F006CA10: d0062038                 ld      [%i0+0x38], %o0
F006CA14: 80a22000                 cmp     %o0, 0
F006CA18: 36800005                 bge,a   loc_F006CA2C
F006CA1C: 113c04f0                 sethi   -0xFEC4000, %o0
F006CA20: 7ffffe17                 call    _vm_info_dequeue
F006CA24: 90100018                 mov     %i0, %o0
F006CA28: 113c04f0                 sethi   -0xFEC4000, %o0
F006CA2C: c0222210                 clr     [%o0+0x210]
F006CA30: 7ffff0e5                 call    _lock_write
F006CA34: 90062018                 add     %i0, 0x18, %o0
F006CA38: d0562004                 ldsh    [%i0+4], %o0
F006CA3C: 80a22000                 cmp     %o0, 0
F006CA40: 12800007                 bne     loc_F006CA5C
F006CA44: 90100018                 mov     %i0, %o0
F006CA48: d2062038                 ld      [%i0+0x38], %o1
F006CA4C: 11020000                 sethi   0x8000000, %o0
F006CA50: 902a4008                 andn    %o1, %o0, %o0
F006CA54: d0262038                 st      %o0, [%i0+0x38]
F006CA58: 90100018                 mov     %i0, %o0
F006CA5C: d2062008                 ld      [%i0+8], %o1
F006CA60: a0102000                 mov     0, %l0
F006CA64: d406200c                 ld      [%i0+0xC], %o2
F006CA68: 96100019                 mov     %i1, %o3
F006CA6C: 4000006b                 call    _mfs_map_remove
F006CA70: 9402400a                 add     %o1, %o2, %o2
F006CA74: c026200c                 clr     [%i0+0xC]
F006CA78: d0562004                 ldsh    [%i0+4], %o0
F006CA7C: 80a22000                 cmp     %o0, 0
F006CA80: 1280000a                 bne     loc_F006CAA8
F006CA84: c0262008                 clr     [%i0+8]
F006CA88: e0062024                 ld      [%i0+0x24], %l0
F006CA8C: d0062030                 ld      [%i0+0x30], %o0
F006CA90: 80a22000                 cmp     %o0, 0
F006CA94: 02800005                 be      loc_F006CAA8
F006CA98: c0262024                 clr     [%i0+0x24]
F006CA9C: 7ffe8bdf                 call    _crfree
F006CAA0: 01000000                 nop
F006CAA4: c0262030                 clr     [%i0+0x30]
F006CAA8: 7ffff163                 call    _lock_done
F006CAAC: 90062018                 add     %i0, 0x18, %o0
F006CAB0: 80a42000                 cmp     %l0, 0
F006CAB4: 02800004                 be      locret_F006CAC4
F006CAB8: 01000000                 nop
F006CABC: 4000677f                 call    _vm_object_deallocate
F006CAC0: 90100010                 mov     %l0, %o0
F006CAC4: 81c7e008                 ret
F006CAC8: 81e80000                 restore
