F0084140: 9de3bf98                 save    %sp, -0x68, %sp
F0084144: d0062014                 ld      [%i0+0x14], %o0
F0084148: 80a22000                 cmp     %o0, 0
F008414C: 02800004                 be      loc_F008415C
F0084150: 113c04f4                 sethi   %hi(_vm_map_entry_zone), %o0
F0084154: 10800004                 ba      loc_F0084164
F0084158: d0022378                 ld      [%o0+%lo(_vm_map_entry_zone)], %o0
F008415C: 113c04f4                 sethi   %hi(_vm_map_kentry_zone), %o0
F0084160: d0022380                 ld      [%o0+%lo(_vm_map_kentry_zone)], %o0
F0084164: 7fffd3da                 call    _zalloc
F0084168: 01000000                 nop
F008416C: b0920000                 orcc    %o0, %g0, %i0
F0084170: 12800004                 bne     locret_F0084180
F0084174: 113c0446                 sethi   %hi(aVmMapEntryCrea), %o0! "vm_map_entry_create"
F0084178: 7ffe43fe                 call    _panic
F008417C: 90122270                 bset    %lo(aVmMapEntryCrea), %o0! "vm_map_entry_create"
F0084180: 81c7e008                 ret
F0084184: 81e80000                 restore
