F007EAF4: 9de3bf90                 save    %sp, -0x70, %sp
F007EAF8: d0062004                 ld      [%i0+4], %o0
F007EAFC: 80a22048                 cmp     %o0, 0x48 ! 'H'
F007EB00: 12800034                 bne     loc_F007EBD0
F007EB04: 90103ed0                 mov     -0x130, %o0
F007EB08: d0060000                 ld      [%i0], %o0
F007EB0C: 80a22000                 cmp     %o0, 0
F007EB10: 16800030                 bge     loc_F007EBD0
F007EB14: 90103ed0                 mov     -0x130, %o0
F007EB18: d0062018                 ld      [%i0+0x18], %o0
F007EB1C: 133c0444                 sethi   %hi(dword_F011138C), %o1
F007EB20: d202638c                 ld      [%o1+%lo(dword_F011138C)], %o1
F007EB24: 80a20009                 cmp     %o0, %o1
F007EB28: 1280002a                 bne     loc_F007EBD0
F007EB2C: 90103ed0                 mov     -0x130, %o0
F007EB30: d0062020                 ld      [%i0+0x20], %o0
F007EB34: 133c0444                 sethi   %hi(dword_F0111390), %o1
F007EB38: d2026390                 ld      [%o1+%lo(dword_F0111390)], %o1
F007EB3C: 80a20009                 cmp     %o0, %o1
F007EB40: 12800024                 bne     loc_F007EBD0
F007EB44: 90103ed0                 mov     -0x130, %o0
F007EB48: d0062028                 ld      [%i0+0x28], %o0
F007EB4C: 133c0444                 sethi   %hi(dword_F0111394), %o1
F007EB50: d2026394                 ld      [%o1+%lo(dword_F0111394)], %o1
F007EB54: 80a20009                 cmp     %o0, %o1
F007EB58: 1280001e                 bne     loc_F007EBD0
F007EB5C: 90103ed0                 mov     -0x130, %o0
F007EB60: d0062030                 ld      [%i0+0x30], %o0
F007EB64: 133c0444                 sethi   %hi(dword_F0111398), %o1
F007EB68: d2026398                 ld      [%o1+%lo(dword_F0111398)], %o1
F007EB6C: 80a20009                 cmp     %o0, %o1
F007EB70: 12800018                 bne     loc_F007EBD0
F007EB74: 90103ed0                 mov     -0x130, %o0
F007EB78: d0062038                 ld      [%i0+0x38], %o0
F007EB7C: 133c0444                 sethi   %hi(dword_F011139C), %o1
F007EB80: d202639c                 ld      [%o1+%lo(dword_F011139C)], %o1
F007EB84: 80a20009                 cmp     %o0, %o1
F007EB88: 12800012                 bne     loc_F007EBD0
F007EB8C: 90103ed0                 mov     -0x130, %o0
F007EB90: d2062040                 ld      [%i0+0x40], %o1
F007EB94: 1104480090122018         set     0x11200018, %o0
F007EB9C: 920a7ffc                 and     %o1, -4, %o1
F007EBA0: 80a24008                 cmp     %o1, %o0
F007EBA4: 1280000b                 bne     loc_F007EBD0
F007EBA8: 90103ed0                 mov     -0x130, %o0
F007EBAC: d0062008                 ld      [%i0+8], %o0
F007EBB0: d206201c                 ld      [%i0+0x1C], %o1
F007EBB4: d4062024                 ld      [%i0+0x24], %o2
F007EBB8: d606202c                 ld      [%i0+0x2C], %o3
F007EBBC: d8062034                 ld      [%i0+0x34], %o4
F007EBC0: c4062044                 ld      [%i0+0x44], %g2
F007EBC4: da06203c                 ld      [%i0+0x3C], %o5
F007EBC8: 7fffb343                 call    _netipc_listen
F007EBCC: c423a05c                 st      %g2, [%sp+0x70+var_14]
F007EBD0: d026601c                 st      %o0, [%i1+0x1C]
F007EBD4: 81c7e008                 ret
F007EBD8: 81e80000                 restore
