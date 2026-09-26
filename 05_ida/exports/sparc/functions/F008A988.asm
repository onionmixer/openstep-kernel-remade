F008A988: 9de3bf98                 save    %sp, -0x68, %sp
F008A98C: 80a62000                 cmp     %i0, 0
F008A990: 0280002e                 be      loc_F008AA48
F008A994: b4100019                 mov     %i1, %i2
F008A998: 053c0447                 sethi   %hi(_page_size), %g2
F008A99C: f200a13c                 ld      [%g2+%lo(_page_size)], %i1
F008A9A0: 073c04f3                 sethi   %hi(_vm_page_free_count), %g3
F008A9A4: f000e000                 ld      [%g3+%lo(_vm_page_free_count)], %i0
F008A9A8: 053c04f0                 sethi   %hi(_vm_stat), %g2
F008A9AC: f220a240                 st      %i1, [%g2+%lo(_vm_stat)]
F008A9B0: 8410a240                 bset    %lo(_vm_stat), %g2
F008A9B4: 073c04f2                 sethi   %hi(_vm_page_active_count), %g3
F008A9B8: c600e3f8                 ld      [%g3+%lo(_vm_page_active_count)], %g3
F008A9BC: f020a004                 st      %i0, [%g2+4]
F008A9C0: c620a008                 st      %g3, [%g2+8]
F008A9C4: 073c04f0                 sethi   %hi(_vm_page_inactive_count), %g3
F008A9C8: f000e220                 ld      [%g3+%lo(_vm_page_inactive_count)], %i0
F008A9CC: 073c04f6                 sethi   %hi(_vm_page_wire_count), %g3
F008A9D0: c600e180                 ld      [%g3+%lo(_vm_page_wire_count)], %g3
F008A9D4: f020a00c                 st      %i0, [%g2+0xC]
F008A9D8: c620a010                 st      %g3, [%g2+0x10]
F008A9DC: f2268000                 st      %i1, [%i2]
F008A9E0: c600a004                 ld      [%g2+4], %g3
F008A9E4: c626a004                 st      %g3, [%i2+4]
F008A9E8: c600a008                 ld      [%g2+8], %g3
F008A9EC: c626a008                 st      %g3, [%i2+8]
F008A9F0: c600a00c                 ld      [%g2+0xC], %g3
F008A9F4: c626a00c                 st      %g3, [%i2+0xC]
F008A9F8: c600a010                 ld      [%g2+0x10], %g3
F008A9FC: c626a010                 st      %g3, [%i2+0x10]
F008AA00: c600a014                 ld      [%g2+0x14], %g3
F008AA04: c626a014                 st      %g3, [%i2+0x14]
F008AA08: c600a018                 ld      [%g2+0x18], %g3
F008AA0C: c626a018                 st      %g3, [%i2+0x18]
F008AA10: c600a01c                 ld      [%g2+0x1C], %g3
F008AA14: c626a01c                 st      %g3, [%i2+0x1C]
F008AA18: c600a020                 ld      [%g2+0x20], %g3
F008AA1C: c626a020                 st      %g3, [%i2+0x20]
F008AA20: c600a024                 ld      [%g2+0x24], %g3
F008AA24: c626a024                 st      %g3, [%i2+0x24]
F008AA28: c600a028                 ld      [%g2+0x28], %g3
F008AA2C: c626a028                 st      %g3, [%i2+0x28]
F008AA30: c600a02c                 ld      [%g2+0x2C], %g3
F008AA34: c626a02c                 st      %g3, [%i2+0x2C]
F008AA38: c400a030                 ld      [%g2+0x30], %g2
F008AA3C: b0102000                 mov     0, %i0
F008AA40: 10800003                 ba      locret_F008AA4C
F008AA44: c426a030                 st      %g2, [%i2+0x30]
F008AA48: b0102004                 mov     4, %i0
F008AA4C: 81c7e008                 ret
F008AA50: 81e80000                 restore
