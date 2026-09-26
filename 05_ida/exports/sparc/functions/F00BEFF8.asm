F00BEFF8: 9de3bf98                 save    %sp, -0x68, %sp
F00BEFFC: c0268000                 clr     [%i2]
F00BF000: 40002ca5                 call    _IOGetKernPort
F00BF004: 90100018                 mov     %i0, %o0
F00BF008: b0920000                 orcc    %o0, %g0, %i0
F00BF00C: 12800004                 bne     loc_F00BF01C
F00BF010: 01000000                 nop
F00BF014: 10800032                 ba      locret_F00BF0DC
F00BF018: b0102004                 mov     4, %i0
F00BF01C: 7ffea277                 call    _convert_port_to_map
F00BF020: 90100018                 mov     %i0, %o0
F00BF024: a0920000                 orcc    %o0, %g0, %l0
F00BF028: 12800006                 bne     loc_F00BF040
F00BF02C: 01000000                 nop
F00BF030: 7ffea3a1                 call    _port_release
F00BF034: 90100018                 mov     %i0, %o0
F00BF038: 10800029                 ba      locret_F00BF0DC
F00BF03C: b0102004                 mov     4, %i0
F00BF040: 7ffea39d                 call    _port_release
F00BF044: 90100018                 mov     %i0, %o0
F00BF048: 113c04d0                 sethi   %hi(_page_mask), %o0
F00BF04C: d60220d8                 ld      [%o0+%lo(_page_mask)], %o3
F00BF050: 9210001c                 mov     %i4, %o1
F00BF054: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00BF058: 9406400b                 add     %i1, %o3, %o2
F00BF05C: b02a800b                 andn    %o2, %o3, %i0
F00BF060: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00BF064: 7fff11e8                 call    _kmem_alloc_wired
F00BF068: 94100018                 mov     %i0, %o2
F00BF06C: 80a22000                 cmp     %o0, 0
F00BF070: 12800018                 bne     loc_F00BF0D0
F00BF074: 90102000                 mov     0, %o0
F00BF078: 133c02fb921263d0         set     sub_F00BEFD0, %o1
F00BF080: 94102000                 mov     0, %o2
F00BF084: d6070000                 ld      [%i4], %o3
F00BF088: 7fff2cc6                 call    _vm_object_special
F00BF08C: 98100018                 mov     %i0, %o4
F00BF090: c026c000                 clr     [%i3]
F00BF094: 92100008                 mov     %o0, %o1
F00BF098: 90100010                 mov     %l0, %o0
F00BF09C: 94102000                 mov     0, %o2
F00BF0A0: 9610001b                 mov     %i3, %o3
F00BF0A4: 98100018                 mov     %i0, %o4
F00BF0A8: 7fff154a                 call    _vm_map_find
F00BF0AC: 9a102001                 mov     1, %o5
F00BF0B0: 92920000                 orcc    %o0, %g0, %o1
F00BF0B4: 12800005                 bne     loc_F00BF0C8
F00BF0B8: 113c0482                 sethi   -0xFEDF800, %o0! char *
F00BF0BC: e0268000                 st      %l0, [%i2]
F00BF0C0: 10800007                 ba      locret_F00BF0DC
F00BF0C4: b0102000                 mov     0, %i0
F00BF0C8: 7ffd5564                 call    _printf
F00BF0CC: 90122288                 bset    0x288, %o0
F00BF0D0: 7fff144f                 call    _vm_map_deallocate
F00BF0D4: 90100010                 mov     %l0, %o0
F00BF0D8: b0102003                 mov     3, %i0
F00BF0DC: 81c7e008                 ret
F00BF0E0: 81e80000                 restore
