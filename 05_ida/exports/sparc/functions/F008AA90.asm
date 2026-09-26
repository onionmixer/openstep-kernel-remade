F008AA90: 9de3bf88                 save    %sp, -0x78, %sp
F008AA94: 113c04d0                 sethi   %hi(_page_mask), %o0
F008AA98: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F008AA9C: 90064009                 add     %i1, %o1, %o0
F008AAA0: 94380009                 xnor    %g0, %o1, %o2
F008AAA4: a00a000a                 and     %o0, %o2, %l0
F008AAA8: 80a40019                 cmp     %l0, %i1
F008AAAC: 12800007                 bne     loc_F008AAC8
F008AAB0: a2100018                 mov     %i0, %l1
F008AAB4: 90068009                 add     %i2, %o1, %o0
F008AAB8: b20a000a                 and     %o0, %o2, %i1
F008AABC: 80a6401a                 cmp     %i1, %i2
F008AAC0: 02800004                 be      loc_F008AAD0
F008AAC4: 353c04ef                 sethi   -0xFEC4400, %i2
F008AAC8: 10800021                 ba      locret_F008AB4C
F008AACC: b0102004                 mov     4, %i0
F008AAD0: d006a320                 ld      [%i2+0x320], %o0! target_task
F008AAD4: 9207bff4                 add     %fp, address, %o1! address
F008AAD8: 94100019                 mov     %i1, %o2! size
F008AADC: 7fffff51                 call    _vm_allocate
F008AAE0: 96102001                 mov     1, %o3
F008AAE4: b0920000                 orcc    %o0, %g0, %i0
F008AAE8: 02800007                 be      loc_F008AB04
F008AAEC: 113c0447                 sethi   %hi(aVmReadKernelEr), %o0! "vm_read: kernel error %d\n"
F008AAF0: 90122288                 bset    %lo(aVmReadKernelEr), %o0! "vm_read: kernel error %d\n"
F008AAF4: 7ffe26d9                 call    _printf
F008AAF8: 92100018                 mov     %i0, %o1
F008AAFC: 10800014                 ba      locret_F008AB4C
F008AB00: b0102006                 mov     6, %i0
F008AB04: 92100011                 mov     %l1, %o1
F008AB08: 96100019                 mov     %i1, %o3
F008AB0C: 98100010                 mov     %l0, %o4
F008AB10: d407bff4                 ld      [%fp+address], %o2! size
F008AB14: 9a102000                 mov     0, %o5
F008AB18: d006a320                 ld      [%i2+0x320], %o0
F008AB1C: 7fffeac5                 call    _vm_map_copy
F008AB20: c023a05c                 clr     [%sp+0x78+var_1C]
F008AB24: b0920000                 orcc    %o0, %g0, %i0
F008AB28: 12800006                 bne     loc_F008AB40
F008AB2C: d006a320                 ld      [%i2+0x320], %o0
F008AB30: d007bff4                 ld      [%fp+address], %o0! target_task
F008AB34: d026c000                 st      %o0, [%i3]
F008AB38: 10800005                 ba      locret_F008AB4C
F008AB3C: f2270000                 st      %i1, [%i4]
F008AB40: d207bff4                 ld      [%fp+address], %o1! address
F008AB44: 7fffff57                 call    _vm_deallocate
F008AB48: 94100019                 mov     %i1, %o2
F008AB4C: 81c7e008                 ret
F008AB50: 81e80000                 restore
