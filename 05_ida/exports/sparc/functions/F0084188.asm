F0084188: 9de3bf98                 save    %sp, -0x68, %sp
F008418C: d0062014                 ld      [%i0+0x14], %o0
F0084190: 80a22000                 cmp     %o0, 0
F0084194: 02800005                 be      loc_F00841A8
F0084198: 92100019                 mov     %i1, %o1
F008419C: 113c04f4                 sethi   %hi(_vm_map_entry_zone), %o0
F00841A0: 10800004                 ba      loc_F00841B0
F00841A4: d0022378                 ld      [%o0+%lo(_vm_map_entry_zone)], %o0
F00841A8: 113c04f4                 sethi   %hi(_vm_map_kentry_zone), %o0
F00841AC: d0022380                 ld      [%o0+%lo(_vm_map_kentry_zone)], %o0
F00841B0: 7fffd408                 call    _zfree
F00841B4: 01000000                 nop
F00841B8: 81c7e008                 ret
F00841BC: 81e80000                 restore
