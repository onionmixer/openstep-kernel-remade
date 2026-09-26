F0083EC4: 9de3bf90                 save    %sp, -0x70, %sp
F0083EC8: 113c04d0                 sethi   %hi(_page_mask), %o0
F0083ECC: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0083ED0: b2064008                 add     %i1, %o0, %i1
F0083ED4: a02e4008                 andn    %i1, %o0, %l0
F0083ED8: 7fff93bb                 call    _lock_write
F0083EDC: 90100018                 mov     %i0, %o0
F0083EE0: d006204c                 ld      [%i0+0x4C], %o0
F0083EE4: 90022001                 inc     %o0
F0083EE8: d026204c                 st      %o0, [%i0+0x4C]
F0083EEC: 7fff9601                 call    _lock_set_recursive
F0083EF0: 90100018                 mov     %i0, %o0
F0083EF4: 90100018                 mov     %i0, %o0
F0083EF8: 92102000                 mov     0, %o1
F0083EFC: 9607bff4                 add     %fp, var_C, %o3
F0083F00: 98100010                 mov     %l0, %o4
F0083F04: d4062014                 ld      [%i0+0x14], %o2
F0083F08: 9a102001                 mov     1, %o5
F0083F0C: d427bff4                 st      %o2, [%fp+var_C]
F0083F10: 400001b0                 call    _vm_map_find
F0083F14: 94102000                 mov     0, %o2
F0083F18: b2100008                 mov     %o0, %i1
F0083F1C: 7fff960d                 call    _lock_clear_recursive
F0083F20: 90100018                 mov     %i0, %o0
F0083F24: 80a66000                 cmp     %i1, 0
F0083F28: 02800014                 be      loc_F0083F78
F0083F2C: 01000000                 nop
F0083F30: d0062018                 ld      [%i0+0x18], %o0
F0083F34: d2062014                 ld      [%i0+0x14], %o1
F0083F38: 90220009                 sub     %o0, %o1, %o0
F0083F3C: 80a20010                 cmp     %o0, %l0
F0083F40: 1a800006                 bcc     loc_F0083F58
F0083F44: 90100018                 mov     %i0, %o0
F0083F48: 7fff943b                 call    _lock_done
F0083F4C: 90100018                 mov     %i0, %o0
F0083F50: 10800010                 ba      locret_F0083F90
F0083F54: b0102000                 mov     0, %i0
F0083F58: 7fffb35f                 call    _assert_wait
F0083F5C: 92102001                 mov     1, %o1
F0083F60: 7fff9435                 call    _lock_done
F0083F64: 90100018                 mov     %i0, %o0
F0083F68: 7fffb9d6                 call    _thread_block
F0083F6C: 01000000                 nop
F0083F70: 10800005                 ba      loc_F0083F84
F0083F74: 80a66000                 cmp     %i1, 0
F0083F78: 7fff942f                 call    _lock_done
F0083F7C: 90100018                 mov     %i0, %o0
F0083F80: 80a66000                 cmp     %i1, 0
F0083F84: 12bfffd5                 bne     loc_F0083ED8
F0083F88: 01000000                 nop
F0083F8C: f007bff4                 ld      [%fp+var_C], %i0
F0083F90: 81c7e008                 ret
F0083F94: 81e80000                 restore
