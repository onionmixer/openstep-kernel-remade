F007FB40: 9de3bf90                 save    %sp, -0x70, %sp
F007FB44: d0062004                 ld      [%i0+4], %o0
F007FB48: 80a22020                 cmp     %o0, 0x20 ! ' '
F007FB4C: 1280000e                 bne     loc_F007FB84
F007FB50: 90103ed0                 mov     -0x130, %o0
F007FB54: d0060000                 ld      [%i0], %o0
F007FB58: 23200000                 sethi   0x80000000, %l1
F007FB5C: 808a0011                 btst    %l1, %o0
F007FB60: 12800009                 bne     loc_F007FB84
F007FB64: 90103ed0                 mov     -0x130, %o0
F007FB68: d0062018                 ld      [%i0+0x18], %o0
F007FB6C: 133c0445                 sethi   %hi(dword_F0111468), %o1
F007FB70: d2026068                 ld      [%o1+%lo(dword_F0111468)], %o1
F007FB74: 80a20009                 cmp     %o0, %o1
F007FB78: 02800005                 be      loc_F007FB8C
F007FB7C: 01000000                 nop
F007FB80: 90103ed0                 mov     -0x130, %o0
F007FB84: 1080001e                 ba      locret_F007FBFC
F007FB88: d026601c                 st      %o0, [%i1+0x1C]
F007FB8C: 7fff9f7a                 call    _convert_port_to_space
F007FB90: d0062008                 ld      [%i0+8], %o0
F007FB94: a0100008                 mov     %o0, %l0
F007FB98: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F007FB9C: d206201c                 ld      [%i0+0x1C], %o1
F007FBA0: 7fff8ece                 call    _port_set_status
F007FBA4: 9607bff4                 add     %fp, var_C, %o3
F007FBA8: d026601c                 st      %o0, [%i1+0x1C]
F007FBAC: 7fffa002                 call    _space_deallocate
F007FBB0: 90100010                 mov     %l0, %o0
F007FBB4: d006601c                 ld      [%i1+0x1C], %o0
F007FBB8: 80a22000                 cmp     %o0, 0
F007FBBC: 12800010                 bne     locret_F007FBFC
F007FBC0: 92102030                 mov     0x30, %o1 ! '0'
F007FBC4: d0064000                 ld      [%i1], %o0
F007FBC8: d2266004                 st      %o1, [%i1+4]
F007FBCC: 90120011                 bset    %l1, %o0
F007FBD0: d0264000                 st      %o0, [%i1]
F007FBD4: 113c0445                 sethi   %hi(dword_F011146C), %o0
F007FBD8: d202206c                 ld      [%o0+%lo(dword_F011146C)], %o1
F007FBDC: d2266020                 st      %o1, [%i1+0x20]
F007FBE0: 9012206c                 bset    %lo(dword_F011146C), %o0
F007FBE4: d2022004                 ld      [%o0+4], %o1
F007FBE8: d2266024                 st      %o1, [%i1+0x24]
F007FBEC: d0022008                 ld      [%o0+8], %o0
F007FBF0: d207bff4                 ld      [%fp+var_C], %o1
F007FBF4: d0266028                 st      %o0, [%i1+0x28]
F007FBF8: d2266028                 st      %o1, [%i1+0x28]
F007FBFC: 81c7e008                 ret
F007FC00: 81e80000                 restore
