F00EBFAC: 9de3bf90                 save    %sp, -0x70, %sp
F00EBFB0: a4960000                 orcc    %i0, %g0, %l2
F00EBFB4: 2280004d                 be,a    locret_F00EC0E8
F00EBFB8: b0102000                 mov     0, %i0
F00EBFBC: 273c0506                 sethi   -0xFEBE800, %l3
F00EBFC0: d0048000                 ld      [%l2], %o0
F00EBFC4: d002200c                 ld      [%o0+0xC], %o0
F00EBFC8: 80a22002                 cmp     %o0, 2
F00EBFCC: 24800020                 ble,a   loc_F00EC04C
F00EBFD0: e404a004                 ld      [%l2+4], %l2
F00EBFD4: e204a024                 ld      [%l2+0x24], %l1
F00EBFD8: 80a46000                 cmp     %l1, 0
F00EBFDC: 2280001c                 be,a    loc_F00EC04C
F00EBFE0: e404a004                 ld      [%l2+4], %l2
F00EBFE4: 1080000c                 ba      loc_F00EC014
F00EBFE8: a0102000                 mov     0, %l0
F00EBFEC: 90020011                 add     %o0, %l1, %o0
F00EBFF0: d0022008                 ld      [%o0+8], %o0! id
F00EBFF4: d204e218                 ld      [%l3+0x218], %o1! SEL
F00EBFF8: 4000161e                 call    _objc_msgSend
F00EBFFC: 9410001a                 mov     %i2, %o2
F00EC000: 80a22000                 cmp     %o0, 0
F00EC004: 02800004                 be      loc_F00EC014
F00EC008: a0042001                 inc     %l0
F00EC00C: 10800037                 ba      locret_F00EC0E8
F00EC010: b0100008                 mov     %o0, %i0
F00EC014: d0046004                 ld      [%l1+4], %o0
F00EC018: 80a40008                 cmp     %l0, %o0
F00EC01C: 06bffff4                 bl      loc_F00EBFEC
F00EC020: 912c2002                 sll     %l0, 2, %o0
F00EC024: d0048000                 ld      [%l2], %o0
F00EC028: d002200c                 ld      [%o0+0xC], %o0
F00EC02C: 80a22004                 cmp     %o0, 4
F00EC030: 24800007                 ble,a   loc_F00EC04C
F00EC034: e404a004                 ld      [%l2+4], %l2
F00EC038: e2044000                 ld      [%l1], %l1
F00EC03C: 80a46000                 cmp     %l1, 0
F00EC040: 32bffff5                 bne,a   loc_F00EC014
F00EC044: a0102000                 mov     0, %l0
F00EC048: e404a004                 ld      [%l2+4], %l2
F00EC04C: 80a4a000                 cmp     %l2, 0
F00EC050: 32bfffdd                 bne,a   loc_F00EBFC4
F00EC054: d0048000                 ld      [%l2], %o0
F00EC058: a4960000                 orcc    %i0, %g0, %l2
F00EC05C: 02800023                 be      locret_F00EC0E8
F00EC060: b0102000                 mov     0, %i0
F00EC064: d404a01c                 ld      [%l2+0x1C], %o2
F00EC068: 80a2a000                 cmp     %o2, 0
F00EC06C: 2280001b                 be,a    loc_F00EC0D8
F00EC070: e404a004                 ld      [%l2+4], %l2
F00EC074: 92102000                 mov     0, %o1
F00EC078: d002a004                 ld      [%o2+4], %o0
F00EC07C: 80a24008                 cmp     %o1, %o0
F00EC080: 36800012                 bge,a   loc_F00EC0C8
F00EC084: d4028000                 ld      [%o2], %o2
F00EC088: d602a004                 ld      [%o2+4], %o3
F00EC08C: 912a6001                 sll     %o1, 1, %o0
F00EC090: 90020009                 add     %o0, %o1, %o0
F00EC094: b12a2002                 sll     %o0, 2, %i0
F00EC098: 90028018                 add     %o2, %i0, %o0
F00EC09C: d0022008                 ld      [%o0+8], %o0
F00EC0A0: 80a2001a                 cmp     %o0, %i2
F00EC0A4: 12800005                 bne     loc_F00EC0B8
F00EC0A8: 92026001                 inc     %o1
F00EC0AC: b0062008                 inc     8, %i0
F00EC0B0: 1080000e                 ba      locret_F00EC0E8
F00EC0B4: b0028018                 add     %o2, %i0, %i0
F00EC0B8: 80a2400b                 cmp     %o1, %o3
F00EC0BC: 06bffff5                 bl      loc_F00EC090
F00EC0C0: 912a6001                 sll     %o1, 1, %o0
F00EC0C4: d4028000                 ld      [%o2], %o2
F00EC0C8: 80a2a000                 cmp     %o2, 0
F00EC0CC: 32bfffeb                 bne,a   loc_F00EC078
F00EC0D0: 92102000                 mov     0, %o1
F00EC0D4: e404a004                 ld      [%l2+4], %l2
F00EC0D8: 80a4a000                 cmp     %l2, 0
F00EC0DC: 32bfffe3                 bne,a   loc_F00EC068
F00EC0E0: d404a01c                 ld      [%l2+0x1C], %o2
F00EC0E4: b0102000                 mov     0, %i0
F00EC0E8: 81c7e008                 ret
F00EC0EC: 81e80000                 restore
