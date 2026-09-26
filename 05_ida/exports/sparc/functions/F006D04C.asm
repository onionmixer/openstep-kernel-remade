F006D04C: 9de3bf98                 save    %sp, -0x68, %sp
F006D050: 113c04f0a0122210         set     _vm_info_lock_data, %l0
F006D058: d0040000                 ld      [%l0], %o0
F006D05C: 80a22000                 cmp     %o0, 0
F006D060: 12bffffe                 bne     loc_F006D058
F006D064: 01000000                 nop
F006D068: 4000a790                 call    _simple_lock_try
F006D06C: 90100010                 mov     %l0, %o0
F006D070: 80a22000                 cmp     %o0, 0
F006D074: 02bffff9                 be      loc_F006D058
F006D078: 153c043f                 sethi   %hi(_vm_info_version), %o2
F006D07C: 113c04f0                 sethi   %hi(_vm_info_queue), %o0
F006D080: e0022218                 ld      [%o0+%lo(_vm_info_queue)], %l0
F006D084: 92122218                 or      %o0, %lo(_vm_info_queue), %o1
F006D088: 80a40009                 cmp     %l0, %o1
F006D08C: 02800027                 be      loc_F006D128
F006D090: e202a118                 ld      [%o2+%lo(_vm_info_version)], %l1
F006D094: 2f100000                 sethi   0x40000000, %l7
F006D098: 273c04f0                 sethi   -0xFEC4000, %l3
F006D09C: ac10000a                 mov     %o2, %l6
F006D0A0: aa100008                 mov     %o0, %l5
F006D0A4: a8100009                 mov     %o1, %l4
F006D0A8: d0042038                 ld      [%l0+0x38], %o0
F006D0AC: 808a0017                 btst    %l7, %o0
F006D0B0: 02800014                 be      loc_F006D100
F006D0B4: e4042028                 ld      [%l0+0x28], %l2
F006D0B8: c024e210                 clr     [%l3+0x210]
F006D0BC: 7ffffdf3                 call    _vmp_get
F006D0C0: 90100010                 mov     %l0, %o0
F006D0C4: 4000014f                 call    _vmp_push
F006D0C8: 90100010                 mov     %l0, %o0
F006D0CC: 7ffffe0a                 call    _vmp_put
F006D0D0: 90100010                 mov     %l0, %o0
F006D0D4: a014e210                 or      %l3, 0x210, %l0
F006D0D8: d0040000                 ld      [%l0], %o0
F006D0DC: 80a22000                 cmp     %o0, 0
F006D0E0: 12bffffe                 bne     loc_F006D0D8
F006D0E4: 01000000                 nop
F006D0E8: 4000a770                 call    _simple_lock_try
F006D0EC: 90100010                 mov     %l0, %o0
F006D0F0: 80a22000                 cmp     %o0, 0
F006D0F4: 02bffff9                 be      loc_F006D0D8
F006D0F8: 01000000                 nop
F006D0FC: a2046002                 inc     2, %l1
F006D100: d005a118                 ld      [%l6+0x118], %o0
F006D104: 80a44008                 cmp     %l1, %o0
F006D108: 12800004                 bne     loc_F006D118
F006D10C: e0056218                 ld      [%l5+0x218], %l0
F006D110: 10800003                 ba      loc_F006D11C
F006D114: a0100012                 mov     %l2, %l0
F006D118: a2100008                 mov     %o0, %l1
F006D11C: 80a40014                 cmp     %l0, %l4
F006D120: 32bfffe3                 bne,a   loc_F006D0AC
F006D124: d0042038                 ld      [%l0+0x38], %o0
F006D128: 113c04f0                 sethi   %hi(_vm_info_lock_data), %o0
F006D12C: c0222210                 clr     [%o0+%lo(_vm_info_lock_data)]
F006D130: 81c7e008                 ret
F006D134: 81e80000                 restore
