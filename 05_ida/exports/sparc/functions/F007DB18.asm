F007DB18: 9de3bf90                 save    %sp, -0x70, %sp
F007DB1C: d0062004                 ld      [%i0+4], %o0
F007DB20: 80a22020                 cmp     %o0, 0x20 ! ' '
F007DB24: 1280000e                 bne     loc_F007DB5C
F007DB28: 90103ed0                 mov     -0x130, %o0
F007DB2C: d0060000                 ld      [%i0], %o0
F007DB30: 23200000                 sethi   0x80000000, %l1
F007DB34: 808a0011                 btst    %l1, %o0
F007DB38: 12800009                 bne     loc_F007DB5C
F007DB3C: 90103ed0                 mov     -0x130, %o0
F007DB40: d0062018                 ld      [%i0+0x18], %o0
F007DB44: 133c0444                 sethi   %hi(dword_F0111254), %o1
F007DB48: d2026254                 ld      [%o1+%lo(dword_F0111254)], %o1
F007DB4C: 80a20009                 cmp     %o0, %o1
F007DB50: 02800005                 be      loc_F007DB64
F007DB54: 01000000                 nop
F007DB58: 90103ed0                 mov     -0x130, %o0
F007DB5C: 1080001e                 ba      locret_F007DBD4
F007DB60: d026601c                 st      %o0, [%i1+0x1C]
F007DB64: 7fffa784                 call    _convert_port_to_space
F007DB68: d0062008                 ld      [%i0+8], %o0! task
F007DB6C: a0100008                 mov     %o0, %l0
F007DB70: 9406602c                 add     %i1, 0x2C, %o2 ! ','! members
F007DB74: d206201c                 ld      [%i0+0x1C], %o1! name
F007DB78: 7fff9316                 call    _mach_port_get_set_status
F007DB7C: 9607bff4                 add     %fp, var_C, %o3
F007DB80: d026601c                 st      %o0, [%i1+0x1C]
F007DB84: 7fffa80c                 call    _space_deallocate
F007DB88: 90100010                 mov     %l0, %o0
F007DB8C: d006601c                 ld      [%i1+0x1C], %o0
F007DB90: 80a22000                 cmp     %o0, 0
F007DB94: 12800010                 bne     locret_F007DBD4
F007DB98: 92102030                 mov     0x30, %o1 ! '0'
F007DB9C: d0064000                 ld      [%i1], %o0
F007DBA0: d2266004                 st      %o1, [%i1+4]
F007DBA4: 90120011                 bset    %l1, %o0
F007DBA8: d0264000                 st      %o0, [%i1]
F007DBAC: 113c0444                 sethi   %hi(dword_F0111258), %o0
F007DBB0: d2022258                 ld      [%o0+%lo(dword_F0111258)], %o1
F007DBB4: d2266020                 st      %o1, [%i1+0x20]
F007DBB8: 90122258                 bset    %lo(dword_F0111258), %o0
F007DBBC: d2022004                 ld      [%o0+4], %o1
F007DBC0: d2266024                 st      %o1, [%i1+0x24]
F007DBC4: d0022008                 ld      [%o0+8], %o0
F007DBC8: d207bff4                 ld      [%fp+var_C], %o1
F007DBCC: d0266028                 st      %o0, [%i1+0x28]
F007DBD0: d2266028                 st      %o1, [%i1+0x28]
F007DBD4: 81c7e008                 ret
F007DBD8: 81e80000                 restore
