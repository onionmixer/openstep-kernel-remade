F007C6A4: 9de3bf90                 save    %sp, -0x70, %sp
F007C6A8: d0062004                 ld      [%i0+4], %o0
F007C6AC: 80a22018                 cmp     %o0, 0x18
F007C6B0: 12800007                 bne     loc_F007C6CC
F007C6B4: 90103ed0                 mov     -0x130, %o0
F007C6B8: d0060000                 ld      [%i0], %o0
F007C6BC: 21200000                 sethi   0x80000000, %l0
F007C6C0: 808a0010                 btst    %l0, %o0
F007C6C4: 02800004                 be      loc_F007C6D4
F007C6C8: 90103ed0                 mov     -0x130, %o0
F007C6CC: 10800014                 ba      locret_F007C71C
F007C6D0: d026601c                 st      %o0, [%i1+0x1C]
F007C6D4: 7fffa327                 call    _convert_port_to_processor
F007C6D8: d0062008                 ld      [%i0+8], %o0! processor
F007C6DC: 7fffcb11                 call    _processor_get_assignment
F007C6E0: 9207bff4                 add     %fp, var_C, %o1
F007C6E4: 80a22000                 cmp     %o0, 0
F007C6E8: 1280000d                 bne     locret_F007C71C
F007C6EC: d026601c                 st      %o0, [%i1+0x1C]
F007C6F0: 92102028                 mov     0x28, %o1 ! '('
F007C6F4: d0064000                 ld      [%i1], %o0
F007C6F8: d2266004                 st      %o1, [%i1+4]
F007C6FC: 90120010                 bset    %l0, %o0
F007C700: d0264000                 st      %o0, [%i1]
F007C704: 113c0444                 sethi   %hi(dword_F01110B0), %o0
F007C708: d20220b0                 ld      [%o0+%lo(dword_F01110B0)], %o1
F007C70C: d007bff4                 ld      [%fp+var_C], %o0
F007C710: 7fffa396                 call    _convert_pset_name_to_port
F007C714: d2266020                 st      %o1, [%i1+0x20]
F007C718: d0266024                 st      %o0, [%i1+0x24]
F007C71C: 81c7e008                 ret
F007C720: 81e80000                 restore
