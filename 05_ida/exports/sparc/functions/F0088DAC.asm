F0088DAC: 9de3bf98                 save    %sp, -0x68, %sp
F0088DB0: d2062020                 ld      [%i0+0x20], %o1
F0088DB4: 11080000                 sethi   0x20000000, %o0
F0088DB8: 808a4008                 btst    %o0, %o1
F0088DBC: 02800004                 be      loc_F0088DCC
F0088DC0: 113c0447                 sethi   %hi(aVmPageInsert), %o0! "vm_page_insert"
F0088DC4: 7ffe30eb                 call    _panic
F0088DC8: 901221c0                 bset    %lo(aVmPageInsert), %o0! "vm_page_insert"
F0088DCC: f2262014                 st      %i1, [%i0+0x14]
F0088DD0: f4262018                 st      %i2, [%i0+0x18]
F0088DD4: 113c04f4                 sethi   %hi(_page_shift), %o0
F0088DD8: 153c04f6                 sethi   %hi(_vm_page_buckets), %o2
F0088DDC: d0022348                 ld      [%o0+%lo(_page_shift)], %o0
F0088DE0: 133c04f6                 sethi   %hi(_vm_page_hash_mask), %o1
F0088DE4: d2026140                 ld      [%o1+%lo(_vm_page_hash_mask)], %o1
F0088DE8: 91368008                 srl     %i2, %o0, %o0
F0088DEC: 90064008                 add     %i1, %o0, %o0
F0088DF0: 900a0009                 and     %o0, %o1, %o0
F0088DF4: d202a138                 ld      [%o2+%lo(_vm_page_buckets)], %o1
F0088DF8: 912a2003                 sll     %o0, 3, %o0
F0088DFC: 4000376f                 call    _spltty
F0088E00: b4024008                 add     %o1, %o0, %i2
F0088E04: a0100008                 mov     %o0, %l0
F0088E08: d0068000                 ld      [%i2], %o0
F0088E0C: 80a22000                 cmp     %o0, 0
F0088E10: 12bffffe                 bne     loc_F0088E08
F0088E14: 01000000                 nop
F0088E18: 40003824                 call    _simple_lock_try
F0088E1C: 9010001a                 mov     %i2, %o0
F0088E20: 80a22000                 cmp     %o0, 0
F0088E24: 02bffff9                 be      loc_F0088E08
F0088E28: 01000000                 nop
F0088E2C: d206a004                 ld      [%i2+4], %o1
F0088E30: d2262010                 st      %o1, [%i0+0x10]
F0088E34: f026a004                 st      %i0, [%i2+4]
F0088E38: c0268000                 clr     [%i2]
F0088E3C: 400037ba                 call    _splx
F0088E40: 90100010                 mov     %l0, %o0
F0088E44: d0066004                 ld      [%i1+4], %o0
F0088E48: 80a64008                 cmp     %i1, %o0
F0088E4C: 32800003                 bne,a   loc_F0088E58
F0088E50: f0222008                 st      %i0, [%o0+8]
F0088E54: f0264000                 st      %i0, [%i1]
F0088E58: d026200c                 st      %o0, [%i0+0xC]
F0088E5C: f2262008                 st      %i1, [%i0+8]
F0088E60: f0266004                 st      %i0, [%i1+4]
F0088E64: d0062020                 ld      [%i0+0x20], %o0
F0088E68: 13080000                 sethi   0x20000000, %o1
F0088E6C: 90120009                 bset    %o1, %o0
F0088E70: d0262020                 st      %o0, [%i0+0x20]
F0088E74: d016601a                 lduh    [%i1+0x1A], %o0
F0088E78: 90022001                 inc     %o0
F0088E7C: d036601a                 sth     %o0, [%i1+0x1A]
F0088E80: 81c7e008                 ret
F0088E84: 81e80000                 restore
