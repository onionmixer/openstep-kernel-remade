F007E78C: 9de3bf98                 save    %sp, -0x68, %sp
F007E790: d0062004                 ld      [%i0+4], %o0
F007E794: 80a22030                 cmp     %o0, 0x30 ! '0'
F007E798: 12800018                 bne     loc_F007E7F8
F007E79C: 90103ed0                 mov     -0x130, %o0
F007E7A0: d0060000                 ld      [%i0], %o0
F007E7A4: 80a22000                 cmp     %o0, 0
F007E7A8: 06800013                 bl      loc_F007E7F4
F007E7AC: 133c0444                 sethi   %hi(dword_F011134C), %o1
F007E7B0: d0062018                 ld      [%i0+0x18], %o0
F007E7B4: d202634c                 ld      [%o1+%lo(dword_F011134C)], %o1
F007E7B8: 80a20009                 cmp     %o0, %o1
F007E7BC: 1280000f                 bne     loc_F007E7F8
F007E7C0: 90103ed0                 mov     -0x130, %o0
F007E7C4: d0062020                 ld      [%i0+0x20], %o0
F007E7C8: 133c0444                 sethi   %hi(dword_F0111350), %o1
F007E7CC: d2026350                 ld      [%o1+%lo(dword_F0111350)], %o1
F007E7D0: 80a20009                 cmp     %o0, %o1
F007E7D4: 12800009                 bne     loc_F007E7F8
F007E7D8: 90103ed0                 mov     -0x130, %o0
F007E7DC: d0062028                 ld      [%i0+0x28], %o0
F007E7E0: 133c0444                 sethi   %hi(dword_F0111354), %o1
F007E7E4: d2026354                 ld      [%o1+%lo(dword_F0111354)], %o1
F007E7E8: 80a20009                 cmp     %o0, %o1
F007E7EC: 02800005                 be      loc_F007E800
F007E7F0: 01000000                 nop
F007E7F4: 90103ed0                 mov     -0x130, %o0
F007E7F8: 1080000c                 ba      locret_F007E828
F007E7FC: d026601c                 st      %o0, [%i1+0x1C]
F007E800: 7fffa47e                 call    _convert_port_to_map
F007E804: d0062008                 ld      [%i0+8], %o0! target_task
F007E808: d206201c                 ld      [%i0+0x1C], %o1! source_address
F007E80C: d4062024                 ld      [%i0+0x24], %o2! size
F007E810: a0100008                 mov     %o0, %l0
F007E814: 400030e9                 call    _vm_copy
F007E818: d606202c                 ld      [%i0+0x2C], %o3
F007E81C: d026601c                 st      %o0, [%i1+0x1C]
F007E820: 4000167b                 call    _vm_map_deallocate
F007E824: 90100010                 mov     %l0, %o0
F007E828: 81c7e008                 ret
F007E82C: 81e80000                 restore
