F000ECC0: 9de3bf48                 save    %sp, -0xB8, %sp
F000ECC4: 133c04d2                 sethi   %hi(_posix_proc_hash), %o1
F000ECC8: d0162030                 lduh    [%i0+0x30], %o0
F000ECCC: 921260b0                 bset    %lo(_posix_proc_hash), %o1
F000ECD0: 900a203f                 and     %o0, 0x3F, %o0
F000ECD4: 912a2002                 sll     %o0, 2, %o0
F000ECD8: d4020009                 ld      [%o0+%o1], %o2
F000ECDC: 80a2a000                 cmp     %o2, 0
F000ECE0: 02800011                 be      loc_F000ED24
F000ECE4: 96020009                 add     %o0, %o1, %o3
F000ECE8: d402c000                 ld      [%o3], %o2
F000ECEC: d2562030                 ldsh    [%i0+0x30], %o1
F000ECF0: d0028000                 ld      [%o2], %o0
F000ECF4: 80a20009                 cmp     %o0, %o1
F000ECF8: 32800008                 bne,a   loc_F000ED18
F000ECFC: d002a01c                 ld      [%o2+0x1C], %o0
F000ED00: 9010000a                 mov     %o2, %o0
F000ED04: d402201c                 ld      [%o0+0x1C], %o2
F000ED08: 92102020                 mov     0x20, %o1 ! ' '
F000ED0C: 40016525                 call    _kfree
F000ED10: d422c000                 st      %o2, [%o3]
F000ED14: 3080000c                 ba,a    locret_F000ED44
F000ED18: 80a22000                 cmp     %o0, 0
F000ED1C: 12bffff3                 bne     loc_F000ECE8
F000ED20: 9602a01c                 add     %o2, 0x1C, %o3
F000ED24: a007bfa8                 add     %fp, var_58, %l0
F000ED28: 90100010                 mov     %l0, %o0! char *
F000ED2C: 133c042c                 sethi   %hi(aDeletePosixPro), %o1! "delete_posix_proc(): no posix proc stru"...
F000ED30: d4562030                 ldsh    [%i0+0x30], %o2
F000ED34: 4000168d                 call    _sprintf
F000ED38: 92126190                 bset    %lo(aDeletePosixPro), %o1! "delete_posix_proc(): no posix proc stru"...
F000ED3C: 4000190d                 call    _panic
F000ED40: 90100010                 mov     %l0, %o0
F000ED44: 81c7e008                 ret
F000ED48: 81e80000                 restore
