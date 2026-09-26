F006BFF8: 9de3bf98                 save    %sp, -0x68, %sp
F006BFFC: 4000aae3                 call    _splusclock
F006C000: 01000000                 nop
F006C004: 133c04d2921261b0         set     _processor_ptr, %o1
F006C00C: 952e2002                 sll     %i0, 2, %o2
F006C010: e2028009                 ld      [%o2+%o1], %l1
F006C014: a4100008                 mov     %o0, %l2
F006C018: a004613c                 add     %l1, 0x13C, %l0
F006C01C: d0040000                 ld      [%l0], %o0
F006C020: 80a22000                 cmp     %o0, 0
F006C024: 12bffffe                 bne     loc_F006C01C
F006C028: 01000000                 nop
F006C02C: 4000ab9f                 call    _simple_lock_try
F006C030: 90100010                 mov     %l0, %o0
F006C034: 80a22000                 cmp     %o0, 0
F006C038: 02bffff9                 be      loc_F006C01C
F006C03C: 932e2005                 sll     %i0, 5, %o1
F006C040: 113c04d190122360         set     _machine_slot, %o0
F006C048: 92024008                 add     %o1, %o0, %o1
F006C04C: c022600c                 clr     [%o1+0xC]
F006C050: 153c04f09412a040         set     _machine_info, %o2
F006C058: d202a00c                 ld      [%o2+0xC], %o1
F006C05C: 92027fff                 inc     -1, %o1
F006C060: d222a00c                 st      %o1, [%o2+0xC]
F006C064: c0246130                 clr     [%l1+0x130]
F006C068: c0246114                 clr     [%l1+0x114]
F006C06C: c024613c                 clr     [%l1+0x13C]
F006C070: 4000ab2d                 call    _splx
F006C074: 90100012                 mov     %l2, %o0
F006C078: 81c7e008                 ret
F006C07C: 81e80000                 restore
