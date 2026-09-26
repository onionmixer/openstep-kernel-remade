F007E350: 9de3bf98                 save    %sp, -0x68, %sp
F007E354: d0062004                 ld      [%i0+4], %o0
F007E358: 80a22030                 cmp     %o0, 0x30 ! '0'
F007E35C: 12800018                 bne     loc_F007E3BC
F007E360: 90103ed0                 mov     -0x130, %o0
F007E364: d0060000                 ld      [%i0], %o0
F007E368: 80a22000                 cmp     %o0, 0
F007E36C: 06800013                 bl      loc_F007E3B8
F007E370: 133c0444                 sethi   %hi(dword_F0111300), %o1
F007E374: d0062018                 ld      [%i0+0x18], %o0
F007E378: d2026300                 ld      [%o1+%lo(dword_F0111300)], %o1
F007E37C: 80a20009                 cmp     %o0, %o1
F007E380: 1280000f                 bne     loc_F007E3BC
F007E384: 90103ed0                 mov     -0x130, %o0
F007E388: d0062020                 ld      [%i0+0x20], %o0
F007E38C: 133c0444                 sethi   %hi(dword_F0111304), %o1
F007E390: d2026304                 ld      [%o1+%lo(dword_F0111304)], %o1
F007E394: 80a20009                 cmp     %o0, %o1
F007E398: 12800009                 bne     loc_F007E3BC
F007E39C: 90103ed0                 mov     -0x130, %o0
F007E3A0: d0062028                 ld      [%i0+0x28], %o0
F007E3A4: 133c0444                 sethi   %hi(dword_F0111308), %o1
F007E3A8: d2026308                 ld      [%o1+%lo(dword_F0111308)], %o1! address
F007E3AC: 80a20009                 cmp     %o0, %o1
F007E3B0: 02800005                 be      loc_F007E3C4
F007E3B4: 01000000                 nop
F007E3B8: 90103ed0                 mov     -0x130, %o0
F007E3BC: 10800016                 ba      locret_F007E414
F007E3C0: d026601c                 st      %o0, [%i1+0x1C]
F007E3C4: 7fffa58d                 call    _convert_port_to_map
F007E3C8: d0062008                 ld      [%i0+8], %o0! target_task
F007E3CC: a0100008                 mov     %o0, %l0
F007E3D0: d4062024                 ld      [%i0+0x24], %o2! size
F007E3D4: d606202c                 ld      [%i0+0x2C], %o3! flags
F007E3D8: 40003112                 call    _vm_allocate
F007E3DC: 9206201c                 add     %i0, 0x1C, %o1
F007E3E0: d026601c                 st      %o0, [%i1+0x1C]
F007E3E4: 4000178a                 call    _vm_map_deallocate
F007E3E8: 90100010                 mov     %l0, %o0
F007E3EC: d006601c                 ld      [%i1+0x1C], %o0
F007E3F0: 80a22000                 cmp     %o0, 0
F007E3F4: 12800008                 bne     locret_F007E414
F007E3F8: 90102028                 mov     0x28, %o0 ! '('
F007E3FC: d0266004                 st      %o0, [%i1+4]
F007E400: 113c0444                 sethi   %hi(dword_F011130C), %o0
F007E404: d002230c                 ld      [%o0+%lo(dword_F011130C)], %o0
F007E408: d0266020                 st      %o0, [%i1+0x20]
F007E40C: d006201c                 ld      [%i0+0x1C], %o0
F007E410: d0266024                 st      %o0, [%i1+0x24]
F007E414: 81c7e008                 ret
F007E418: 81e80000                 restore
