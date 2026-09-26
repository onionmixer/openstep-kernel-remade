F006A644: 9de3bf90                 save    %sp, -0x70, %sp
F006A648: 90100018                 mov     %i0, %o0
F006A64C: 92102000                 mov     0, %o1
F006A650: 400083bb                 call    _vnode_pager_setup
F006A654: 94102001                 mov     1, %o2
F006A658: e0066004                 ld      [%i1+4], %l0
F006A65C: 98100008                 mov     %o0, %o4
F006A660: d4060000                 ld      [%i0], %o2
F006A664: 932c2002                 sll     %l0, 2, %o1
F006A668: 92024010                 add     %o1, %l0, %o1
F006A66C: 932a6002                 sll     %o1, 2, %o1
F006A670: 96026008                 add     %o1, 8, %o3
F006A674: d402a014                 ld      [%o2+0x14], %o2
F006A678: 80a2c00a                 cmp     %o3, %o2
F006A67C: 18800008                 bgu     loc_F006A69C
F006A680: b0100010                 mov     %l0, %i0
F006A684: 113c04d0                 sethi   %hi(_page_mask), %o0
F006A688: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F006A68C: 9002c009                 add     %o3, %o1, %o0
F006A690: a4aa0009                 andncc  %o0, %o1, %l2
F006A694: 32800004                 bne,a   loc_F006A6A4
F006A698: c027bff4                 clr     [%fp+var_C]
F006A69C: 1080003a                 ba      locret_F006A784
F006A6A0: b0102002                 mov     2, %i0
F006A6A4: 113c04d1                 sethi   %hi(_kernel_map), %o0
F006A6A8: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006A6AC: 9207bff4                 add     %fp, var_C, %o1
F006A6B0: 94100012                 mov     %l2, %o2
F006A6B4: 96102001                 mov     1, %o3
F006A6B8: 4000801b                 call    _vm_allocate_with_pager
F006A6BC: 9a102000                 mov     0, %o5
F006A6C0: 80a22000                 cmp     %o0, 0
F006A6C4: 02800004                 be      loc_F006A6D4
F006A6C8: b2102000                 mov     0, %i1
F006A6CC: 1080002e                 ba      locret_F006A784
F006A6D0: b0102005                 mov     5, %i0
F006A6D4: a2102000                 mov     0, %l1
F006A6D8: a0043fff                 inc     -1, %l0
F006A6DC: d007bff4                 ld      [%fp+var_C], %o0
F006A6E0: 80a62000                 cmp     %i0, 0
F006A6E4: b0022008                 add     %o0, 8, %i0
F006A6E8: 113c04d1                 sethi   %hi(_machine_slot), %o0
F006A6EC: 04800012                 ble     loc_F006A734
F006A6F0: a6122360                 or      %o0, %lo(_machine_slot), %l3
F006A6F4: d2060000                 ld      [%i0], %o1
F006A6F8: d004e004                 ld      [%l3+4], %o0
F006A6FC: 80a24008                 cmp     %o1, %o0
F006A700: 3280000a                 bne,a   loc_F006A728
F006A704: b0062014                 inc     0x14, %i0
F006A708: 4000bccc                 call    _grade_cpu_subtype
F006A70C: d0062004                 ld      [%i0+4], %o0
F006A710: 80a20011                 cmp     %o0, %l1
F006A714: 24800005                 ble,a   loc_F006A728
F006A718: b0062014                 inc     0x14, %i0
F006A71C: a2100008                 mov     %o0, %l1
F006A720: b2100018                 mov     %i0, %i1
F006A724: b0062014                 inc     0x14, %i0
F006A728: 90940000                 orcc    %l0, %g0, %o0
F006A72C: 14bffff2                 bg      loc_F006A6F4
F006A730: a0043fff                 inc     -1, %l0
F006A734: 80a66000                 cmp     %i1, 0
F006A738: 32800004                 bne,a   loc_F006A748
F006A73C: d0064000                 ld      [%i1], %o0
F006A740: 1080000c                 ba      loc_F006A770
F006A744: b0102001                 mov     1, %i0
F006A748: d0268000                 st      %o0, [%i2]
F006A74C: d0066004                 ld      [%i1+4], %o0
F006A750: d026a004                 st      %o0, [%i2+4]
F006A754: d0066008                 ld      [%i1+8], %o0
F006A758: d026a008                 st      %o0, [%i2+8]
F006A75C: d006600c                 ld      [%i1+0xC], %o0
F006A760: d026a00c                 st      %o0, [%i2+0xC]
F006A764: d0066010                 ld      [%i1+0x10], %o0
F006A768: b0102000                 mov     0, %i0
F006A76C: d026a010                 st      %o0, [%i2+0x10]
F006A770: d207bff4                 ld      [%fp+var_C], %o1
F006A774: 113c04d1                 sethi   %hi(_kernel_map), %o0
F006A778: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006A77C: 40006af1                 call    _vm_map_remove
F006A780: 94024012                 add     %o1, %l2, %o2
F006A784: 81c7e008                 ret
F006A788: 81e80000                 restore
