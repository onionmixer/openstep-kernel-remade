F005EE54: 9de3bf90                 save    %sp, -0x70, %sp
F005EE58: 90960000                 orcc    %i0, %g0, %o0
F005EE5C: 12800004                 bne     loc_F005EE6C
F005EE60: 92100019                 mov     %i1, %o1
F005EE64: 1080000d                 ba      locret_F005EE98
F005EE68: b0102010                 mov     0x10, %i0
F005EE6C: 94102001                 mov     1, %o2
F005EE70: 7fffea1b                 call    _ipc_object_translate
F005EE74: 9607bff4                 add     %fp, var_C, %o3
F005EE78: 80a22000                 cmp     %o0, 0
F005EE7C: 12800007                 bne     locret_F005EE98
F005EE80: b0100008                 mov     %o0, %i0
F005EE84: d007bff4                 ld      [%fp+var_C], %o0
F005EE88: b0102000                 mov     0, %i0
F005EE8C: d202201c                 ld      [%o0+0x1C], %o1
F005EE90: c0220000                 clr     [%o0]
F005EE94: d2268000                 st      %o1, [%i2]
F005EE98: 81c7e008                 ret
F005EE9C: 81e80000                 restore
