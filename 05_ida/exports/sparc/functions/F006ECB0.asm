F006ECB0: 9de3bf98                 save    %sp, -0x68, %sp
F006ECB4: 213c04d3a01423c0         set     _default_pset, %l0
F006ECBC: 4000002d                 call    _pset_init
F006ECC0: 90100010                 mov     %l0, %o0
F006ECC4: c0242128                 clr     [%l0+0x128]
F006ECC8: a2102000                 mov     0, %l1
F006ECCC: 113c04d2a61221b0         set     _processor_ptr, %l3
F006ECD4: 113c04f0a01222b0         set     _processor_array, %l0
F006ECDC: a4102000                 mov     0, %l2
F006ECE0: e0248013                 st      %l0, [%l2+%l3]
F006ECE4: 90100010                 mov     %l0, %o0
F006ECE8: 40000057                 call    _processor_init
F006ECEC: 92100011                 mov     %l1, %o1
F006ECF0: a0042148                 inc     0x148, %l0
F006ECF4: a2046001                 inc     %l1
F006ECF8: 80a46000                 cmp     %l1, 0
F006ECFC: 04bffff9                 ble     loc_F006ECE0
F006ED00: a404a004                 inc     4, %l2
F006ED04: 113c04d0                 sethi   %hi(_master_cpu), %o0
F006ED08: 133c04d2                 sethi   %hi(_processor_ptr), %o1
F006ED0C: d00220c8                 ld      [%o0+%lo(_master_cpu)], %o0
F006ED10: 921261b0                 bset    %lo(_processor_ptr), %o1
F006ED14: 912a2002                 sll     %o0, 2, %o0
F006ED18: d2020009                 ld      [%o0+%o1], %o1
F006ED1C: 153c04d3                 sethi   %hi(_all_psets), %o2
F006ED20: 113c04d8                 sethi   %hi(_master_processor), %o0
F006ED24: d22223d0                 st      %o1, [%o0+%lo(_master_processor)]
F006ED28: 9212a3b0                 or      %o2, %lo(_all_psets), %o1
F006ED2C: d2226004                 st      %o1, [%o1+4]
F006ED30: d222a3b0                 st      %o1, [%o2+%lo(_all_psets)]
F006ED34: 113c04d3                 sethi   %hi(_all_psets_lock), %o0
F006ED38: c02223b8                 clr     [%o0+%lo(_all_psets_lock)]
F006ED3C: 113c04d3901223c0         set     _default_pset, %o0
F006ED44: d022a3b0                 st      %o0, [%o2+%lo(_all_psets)]
F006ED48: d2222150                 st      %o1, [%o0+0x150]
F006ED4C: d222214c                 st      %o1, [%o0+0x14C]
F006ED50: d0226004                 st      %o0, [%o1+4]
F006ED54: 153c04f0                 sethi   %hi(_all_psets_count), %o2
F006ED58: 92102001                 mov     1, %o1
F006ED5C: d222a2a0                 st      %o1, [%o2+%lo(_all_psets_count)]
F006ED60: d2222154                 st      %o1, [%o0+0x154]
F006ED64: c0222128                 clr     [%o0+0x128]
F006ED68: 81c7e008                 ret
F006ED6C: 81e80000                 restore
