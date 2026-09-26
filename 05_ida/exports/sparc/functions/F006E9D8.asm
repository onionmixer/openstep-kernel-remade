F006E9D8: 9de3bf98                 save    %sp, -0x68, %sp
F006E9DC: 80a6e002                 cmp     %i3, 2
F006E9E0: 113c04d2901221b0         set     _processor_ptr, %o0
F006E9E8: b12e2002                 sll     %i0, 2, %i0
F006E9EC: f6060008                 ld      [%i0+%o0], %i3
F006E9F0: 113c04f0                 sethi   %hi(_min_quantum), %o0
F006E9F4: e0022290                 ld      [%o0+%lo(_min_quantum)], %l0
F006E9F8: 113c04d4                 sethi   %hi(dword_F013512C), %o0
F006E9FC: 028000ab                 be      locret_F006ECA8
F006EA00: e022212c                 st      %l0, [%o0+%lo(dword_F013512C)]
F006EA04: d006e120                 ld      [%i3+0x120], %o0
F006EA08: 9022001a                 sub     %o0, %i2, %o0
F006EA0C: 80a22000                 cmp     %o0, 0
F006EA10: 14800057                 bg      loc_F006EB6C
F006EA14: d026e120                 st      %o0, [%i3+0x120]
F006EA18: 4000a05c                 call    _splusclock
F006EA1C: b0066020                 add     %i1, 0x20, %i0 ! ' '
F006EA20: b4100008                 mov     %o0, %i2
F006EA24: d0060000                 ld      [%i0], %o0
F006EA28: 80a22000                 cmp     %o0, 0
F006EA2C: 12bffffe                 bne     loc_F006EA24
F006EA30: 01000000                 nop
F006EA34: 4000a11d                 call    _simple_lock_try
F006EA38: 90100018                 mov     %i0, %o0
F006EA3C: 80a22000                 cmp     %o0, 0
F006EA40: 02bffff9                 be      loc_F006EA24
F006EA44: 133c04f0                 sethi   %hi(_sched_tick), %o1
F006EA48: d0066070                 ld      [%i1+0x70], %o0
F006EA4C: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F006EA50: 80a20009                 cmp     %o0, %o1
F006EA54: 22800005                 be,a    loc_F006EA68
F006EA58: d0066060                 ld      [%i1+0x60], %o0
F006EA5C: 40000bfb                 call    _update_priority
F006EA60: 90100019                 mov     %i1, %o0
F006EA64: 30800033                 ba,a    loc_F006EB30
F006EA68: 80a22002                 cmp     %o0, 2
F006EA6C: 02800031                 be      loc_F006EB30
F006EA70: 01000000                 nop
F006EA74: d0066064                 ld      [%i1+0x64], %o0
F006EA78: 80a22000                 cmp     %o0, 0
F006EA7C: 1680002d                 bge     loc_F006EB30
F006EA80: 01000000                 nop
F006EA84: d206610c                 ld      [%i1+0x10C], %o1
F006EA88: d00660f8                 ld      [%i1+0xF8], %o0
F006EA8C: 80a24008                 cmp     %o1, %o0
F006EA90: 02800007                 be      loc_F006EAAC
F006EA94: d40660f0                 ld      [%i1+0xF0], %o2
F006EA98: 900660f0                 add     %i1, 0xF0, %o0
F006EA9C: 400023ff                 call    _timer_delta
F006EAA0: 92066108                 add     %i1, 0x108, %o1
F006EAA4: 10800005                 ba      loc_F006EAB8
F006EAA8: b0100008                 mov     %o0, %i0
F006EAAC: d0066108                 ld      [%i1+0x108], %o0
F006EAB0: b0228008                 sub     %o2, %o0, %i0
F006EAB4: d4266108                 st      %o2, [%i1+0x108]
F006EAB8: d2066104                 ld      [%i1+0x104], %o1
F006EABC: d00660e8                 ld      [%i1+0xE8], %o0
F006EAC0: 80a24008                 cmp     %o1, %o0
F006EAC4: 02800007                 be      loc_F006EAE0
F006EAC8: d40660e0                 ld      [%i1+0xE0], %o2
F006EACC: 900660e0                 add     %i1, 0xE0, %o0
F006EAD0: 400023f2                 call    _timer_delta
F006EAD4: 92066100                 add     %i1, 0x100, %o1
F006EAD8: 10800006                 ba      loc_F006EAF0
F006EADC: b0060008                 add     %i0, %o0, %i0
F006EAE0: d0066100                 ld      [%i1+0x100], %o0
F006EAE4: 90228008                 sub     %o2, %o0, %o0
F006EAE8: b0060008                 add     %i0, %o0, %i0
F006EAEC: d4266100                 st      %o2, [%i1+0x100]
F006EAF0: d0066110                 ld      [%i1+0x110], %o0
F006EAF4: d2066190                 ld      [%i1+0x190], %o1
F006EAF8: 90020018                 add     %o0, %i0, %o0
F006EAFC: d0266110                 st      %o0, [%i1+0x110]
F006EB00: d2026178                 ld      [%o1+0x178], %o1
F006EB04: 7ffe5e7f                 call    _umul
F006EB08: 90100018                 mov     %i0, %o0
F006EB0C: d2066114                 ld      [%i1+0x114], %o1
F006EB10: 92024008                 add     %o1, %o0, %o1
F006EB14: d2266114                 st      %o1, [%i1+0x114]
F006EB18: d006606c                 ld      [%i1+0x6C], %o0
F006EB1C: 90020009                 add     %o0, %o1, %o0
F006EB20: d026606c                 st      %o0, [%i1+0x6C]
F006EB24: c0266114                 clr     [%i1+0x114]
F006EB28: 40000b9e                 call    _compute_my_priority
F006EB2C: 90100019                 mov     %i1, %o0
F006EB30: c0266020                 clr     [%i1+0x20]
F006EB34: 4000a07c                 call    _splx
F006EB38: 9010001a                 mov     %i2, %o0
F006EB3C: c026e124                 clr     [%i3+0x124]
F006EB40: d0066060                 ld      [%i1+0x60], %o0
F006EB44: 80a22002                 cmp     %o0, 2
F006EB48: 02800005                 be      loc_F006EB5C
F006EB4C: d006e120                 ld      [%i3+0x120], %o0
F006EB50: 90020010                 add     %o0, %l0, %o0
F006EB54: 10800053                 ba      loc_F006ECA0
F006EB58: d026e120                 st      %o0, [%i3+0x120]
F006EB5C: d206605c                 ld      [%i1+0x5C], %o1
F006EB60: 90020009                 add     %o0, %o1, %o0
F006EB64: 1080004f                 ba      loc_F006ECA0
F006EB68: d026e120                 st      %o0, [%i3+0x120]
F006EB6C: 4000a007                 call    _splusclock
F006EB70: b0066020                 add     %i1, 0x20, %i0 ! ' '
F006EB74: b4100008                 mov     %o0, %i2
F006EB78: d0060000                 ld      [%i0], %o0
F006EB7C: 80a22000                 cmp     %o0, 0
F006EB80: 12bffffe                 bne     loc_F006EB78
F006EB84: 01000000                 nop
F006EB88: 4000a0c8                 call    _simple_lock_try
F006EB8C: 90100018                 mov     %i0, %o0
F006EB90: 80a22000                 cmp     %o0, 0
F006EB94: 02bffff9                 be      loc_F006EB78
F006EB98: 133c04f0                 sethi   %hi(_sched_tick), %o1
F006EB9C: d0066070                 ld      [%i1+0x70], %o0
F006EBA0: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F006EBA4: 80a20009                 cmp     %o0, %o1
F006EBA8: 22800005                 be,a    loc_F006EBBC
F006EBAC: d0066060                 ld      [%i1+0x60], %o0
F006EBB0: 40000ba6                 call    _update_priority
F006EBB4: 90100019                 mov     %i1, %o0
F006EBB8: 30800037                 ba,a    loc_F006EC94
F006EBBC: 80a22002                 cmp     %o0, 2
F006EBC0: 02800035                 be      loc_F006EC94
F006EBC4: 01000000                 nop
F006EBC8: d0066064                 ld      [%i1+0x64], %o0
F006EBCC: 80a22000                 cmp     %o0, 0
F006EBD0: 16800031                 bge     loc_F006EC94
F006EBD4: 01000000                 nop
F006EBD8: d206610c                 ld      [%i1+0x10C], %o1
F006EBDC: d00660f8                 ld      [%i1+0xF8], %o0
F006EBE0: 80a24008                 cmp     %o1, %o0
F006EBE4: 02800007                 be      loc_F006EC00
F006EBE8: d40660f0                 ld      [%i1+0xF0], %o2
F006EBEC: 900660f0                 add     %i1, 0xF0, %o0
F006EBF0: 400023aa                 call    _timer_delta
F006EBF4: 92066108                 add     %i1, 0x108, %o1
F006EBF8: 10800005                 ba      loc_F006EC0C
F006EBFC: b0100008                 mov     %o0, %i0
F006EC00: d0066108                 ld      [%i1+0x108], %o0
F006EC04: b0228008                 sub     %o2, %o0, %i0
F006EC08: d4266108                 st      %o2, [%i1+0x108]
F006EC0C: d2066104                 ld      [%i1+0x104], %o1
F006EC10: d00660e8                 ld      [%i1+0xE8], %o0
F006EC14: 80a24008                 cmp     %o1, %o0
F006EC18: 02800007                 be      loc_F006EC34
F006EC1C: d40660e0                 ld      [%i1+0xE0], %o2
F006EC20: 900660e0                 add     %i1, 0xE0, %o0
F006EC24: 4000239d                 call    _timer_delta
F006EC28: 92066100                 add     %i1, 0x100, %o1
F006EC2C: 10800006                 ba      loc_F006EC44
F006EC30: b0060008                 add     %i0, %o0, %i0
F006EC34: d0066100                 ld      [%i1+0x100], %o0
F006EC38: 90228008                 sub     %o2, %o0, %o0
F006EC3C: b0060008                 add     %i0, %o0, %i0
F006EC40: d4266100                 st      %o2, [%i1+0x100]
F006EC44: d0066110                 ld      [%i1+0x110], %o0
F006EC48: d2066190                 ld      [%i1+0x190], %o1
F006EC4C: 90020018                 add     %o0, %i0, %o0
F006EC50: d0266110                 st      %o0, [%i1+0x110]
F006EC54: d2026178                 ld      [%o1+0x178], %o1
F006EC58: 7ffe5e2a                 call    _umul
F006EC5C: 90100018                 mov     %i0, %o0
F006EC60: d2066114                 ld      [%i1+0x114], %o1
F006EC64: 94024008                 add     %o1, %o0, %o2
F006EC68: 1101ffff901223ff         set     0x7FFFFFF, %o0
F006EC70: 80a28008                 cmp     %o2, %o0
F006EC74: 08800008                 bleu    loc_F006EC94
F006EC78: d4266114                 st      %o2, [%i1+0x114]
F006EC7C: c0266114                 clr     [%i1+0x114]
F006EC80: d206606c                 ld      [%i1+0x6C], %o1
F006EC84: 90100019                 mov     %i1, %o0
F006EC88: 9202400a                 add     %o1, %o2, %o1
F006EC8C: 40000b45                 call    _compute_my_priority
F006EC90: d226606c                 st      %o1, [%i1+0x6C]
F006EC94: c0266020                 clr     [%i1+0x20]
F006EC98: 4000a023                 call    _splx
F006EC9C: 9010001a                 mov     %i2, %o0
F006ECA0: 7fffd313                 call    _ast_check
F006ECA4: 01000000                 nop
F006ECA8: 81c7e008                 ret
F006ECAC: 81e80000                 restore
