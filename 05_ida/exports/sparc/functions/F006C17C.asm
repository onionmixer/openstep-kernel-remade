F006C17C: 9de3bf98                 save    %sp, -0x68, %sp
F006C180: e0060000                 ld      [%i0], %l0
F006C184: 80a42000                 cmp     %l0, 0
F006C188: 32800007                 bne,a   loc_F006C1A4
F006C18C: c0240000                 clr     [%l0]
F006C190: 113c04d2                 sethi   %hi(_vm_info_zone), %o0
F006C194: 400033ce                 call    _zalloc
F006C198: d0022250                 ld      [%o0+%lo(_vm_info_zone)], %o0
F006C19C: a0100008                 mov     %o0, %l0
F006C1A0: c0240000                 clr     [%l0]
F006C1A4: c0342004                 clrh    [%l0+4]
F006C1A8: c0342006                 clrh    [%l0+6]
F006C1AC: c0242008                 clr     [%l0+8]
F006C1B0: c024200c                 clr     [%l0+0xC]
F006C1B4: c0242010                 clr     [%l0+0x10]
F006C1B8: c0242030                 clr     [%l0+0x30]
F006C1BC: c0242034                 clr     [%l0+0x34]
F006C1C0: c0242014                 clr     [%l0+0x14]
F006C1C4: 90042018                 add     %l0, 0x18, %o0
F006C1C8: d4042038                 ld      [%l0+0x38], %o2
F006C1CC: 13200000                 sethi   0x80000000, %o1
F006C1D0: 922a8009                 andn    %o2, %o1, %o1
F006C1D4: 15100000                 sethi   0x40000000, %o2
F006C1D8: 942a400a                 andn    %o1, %o2, %o2
F006C1DC: 13080000                 sethi   0x20000000, %o1
F006C1E0: 94128009                 bset    %o1, %o2
F006C1E4: 13020000                 sethi   0x8000000, %o1
F006C1E8: 922a8009                 andn    %o2, %o1, %o1
F006C1EC: d2242038                 st      %o1, [%l0+0x38]
F006C1F0: 7ffff2c6                 call    _lock_init
F006C1F4: 92102001                 mov     1, %o1
F006C1F8: c0242024                 clr     [%l0+0x24]
F006C1FC: e0260000                 st      %l0, [%i0]
F006C200: 81c7e008                 ret
F006C204: 81e80000                 restore
