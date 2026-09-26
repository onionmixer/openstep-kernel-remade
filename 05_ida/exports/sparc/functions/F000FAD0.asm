F000FAD0: 9de3bf98                 save    %sp, -0x68, %sp
F000FAD4: 133c04cf                 sethi   %hi(_active_u), %o1
F000FAD8: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F000FADC: e0020000                 ld      [%o0], %l0
F000FAE0: d0542030                 ldsh    [%l0+0x30], %o0
F000FAE4: 7ffffc0f                 call    _get_posix_proc
F000FAE8: a21261d8                 or      %o1, %lo(_active_u), %l1
F000FAEC: d0022010                 ld      [%o0+0x10], %o0
F000FAF0: d2542030                 ldsh    [%l0+0x30], %o1
F000FAF4: d002200c                 ld      [%o0+0xC], %o0
F000FAF8: 80a20009                 cmp     %o0, %o1
F000FAFC: 22800008                 be,a    loc_F000FB1C
F000FB00: d2046004                 ld      [%l1+4], %o1
F000FB04: 7ffffad7                 call    _pgfind
F000FB08: 90100009                 mov     %o1, %o0
F000FB0C: 80a22000                 cmp     %o0, 0
F000FB10: 02800006                 be      loc_F000FB28
F000FB14: 90100010                 mov     %l0, %o0
F000FB18: d2046004                 ld      [%l1+4], %o1
F000FB1C: 90102001                 mov     1, %o0
F000FB20: 10800008                 ba      locret_F000FB40
F000FB24: d02a6038                 stb     %o0, [%o1+0x38]
F000FB28: d2542030                 ldsh    [%l0+0x30], %o1
F000FB2C: 7ffffae2                 call    _enterpgrp
F000FB30: 94102001                 mov     1, %o2
F000FB34: d2046004                 ld      [%l1+4], %o1
F000FB38: d0542030                 ldsh    [%l0+0x30], %o0
F000FB3C: d0226030                 st      %o0, [%o1+0x30]
F000FB40: 81c7e008                 ret
F000FB44: 81e80000                 restore
