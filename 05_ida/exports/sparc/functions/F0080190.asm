F0080190: 9de3bf98                 save    %sp, -0x68, %sp
F0080194: d0062004                 ld      [%i0+4], %o0
F0080198: 80a22030                 cmp     %o0, 0x30 ! '0'
F008019C: 12800018                 bne     loc_F00801FC
F00801A0: 90103ed0                 mov     -0x130, %o0
F00801A4: d0060000                 ld      [%i0], %o0
F00801A8: 80a22000                 cmp     %o0, 0
F00801AC: 06800013                 bl      loc_F00801F8
F00801B0: 133c0445                 sethi   %hi(dword_F01114C0), %o1
F00801B4: d0062018                 ld      [%i0+0x18], %o0
F00801B8: d20260c0                 ld      [%o1+%lo(dword_F01114C0)], %o1
F00801BC: 80a20009                 cmp     %o0, %o1
F00801C0: 1280000f                 bne     loc_F00801FC
F00801C4: 90103ed0                 mov     -0x130, %o0
F00801C8: d0062020                 ld      [%i0+0x20], %o0
F00801CC: 133c0445                 sethi   %hi(dword_F01114C4), %o1
F00801D0: d20260c4                 ld      [%o1+%lo(dword_F01114C4)], %o1
F00801D4: 80a20009                 cmp     %o0, %o1
F00801D8: 12800009                 bne     loc_F00801FC
F00801DC: 90103ed0                 mov     -0x130, %o0
F00801E0: d0062028                 ld      [%i0+0x28], %o0
F00801E4: 133c0445                 sethi   %hi(dword_F01114C8), %o1
F00801E8: d20260c8                 ld      [%o1+%lo(dword_F01114C8)], %o1
F00801EC: 80a20009                 cmp     %o0, %o1
F00801F0: 02800005                 be      loc_F0080204
F00801F4: 01000000                 nop
F00801F8: 90103ed0                 mov     -0x130, %o0
F00801FC: 1080000c                 ba      locret_F008022C
F0080200: d026601c                 st      %o0, [%i1+0x1C]
F0080204: 7fff9dfd                 call    _convert_port_to_map
F0080208: d0062008                 ld      [%i0+8], %o0
F008020C: d206201c                 ld      [%i0+0x1C], %o1
F0080210: d4062024                 ld      [%i0+0x24], %o2
F0080214: a0100008                 mov     %o0, %l0
F0080218: 4000218a                 call    _vm_deactivate
F008021C: d606202c                 ld      [%i0+0x2C], %o3
F0080220: d026601c                 st      %o0, [%i1+0x1C]
F0080224: 40000ffa                 call    _vm_map_deallocate
F0080228: 90100010                 mov     %l0, %o0
F008022C: 81c7e008                 ret
F0080230: 81e80000                 restore
