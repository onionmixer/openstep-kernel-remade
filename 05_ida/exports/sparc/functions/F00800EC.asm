F00800EC: 9de3bf98                 save    %sp, -0x68, %sp
F00800F0: d0062004                 ld      [%i0+4], %o0
F00800F4: 80a22030                 cmp     %o0, 0x30 ! '0'
F00800F8: 12800018                 bne     loc_F0080158
F00800FC: 90103ed0                 mov     -0x130, %o0
F0080100: d0060000                 ld      [%i0], %o0
F0080104: 80a22000                 cmp     %o0, 0
F0080108: 06800013                 bl      loc_F0080154
F008010C: 133c0445                 sethi   %hi(dword_F01114B4), %o1
F0080110: d0062018                 ld      [%i0+0x18], %o0
F0080114: d20260b4                 ld      [%o1+%lo(dword_F01114B4)], %o1
F0080118: 80a20009                 cmp     %o0, %o1
F008011C: 1280000f                 bne     loc_F0080158
F0080120: 90103ed0                 mov     -0x130, %o0
F0080124: d0062020                 ld      [%i0+0x20], %o0
F0080128: 133c0445                 sethi   %hi(dword_F01114B8), %o1
F008012C: d20260b8                 ld      [%o1+%lo(dword_F01114B8)], %o1
F0080130: 80a20009                 cmp     %o0, %o1
F0080134: 12800009                 bne     loc_F0080158
F0080138: 90103ed0                 mov     -0x130, %o0
F008013C: d0062028                 ld      [%i0+0x28], %o0
F0080140: 133c0445                 sethi   %hi(dword_F01114BC), %o1
F0080144: d20260bc                 ld      [%o1+%lo(dword_F01114BC)], %o1
F0080148: 80a20009                 cmp     %o0, %o1
F008014C: 02800005                 be      loc_F0080160
F0080150: 01000000                 nop
F0080154: 90103ed0                 mov     -0x130, %o0
F0080158: 1080000c                 ba      locret_F0080188
F008015C: d026601c                 st      %o0, [%i1+0x1C]
F0080160: 7fff9e26                 call    _convert_port_to_map
F0080164: d0062008                 ld      [%i0+8], %o0
F0080168: d206201c                 ld      [%i0+0x1C], %o1
F008016C: d4062024                 ld      [%i0+0x24], %o2
F0080170: a0100008                 mov     %o0, %l0
F0080174: 4000219b                 call    _vm_set_policy
F0080178: d606202c                 ld      [%i0+0x2C], %o3
F008017C: d026601c                 st      %o0, [%i1+0x1C]
F0080180: 40001023                 call    _vm_map_deallocate
F0080184: 90100010                 mov     %l0, %o0
F0080188: 81c7e008                 ret
F008018C: 81e80000                 restore
