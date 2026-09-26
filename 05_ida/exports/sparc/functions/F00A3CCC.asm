F00A3CCC: 9de3bf98                 save    %sp, -0x68, %sp
F00A3CD0: 2f000032                 sethi   0xC800, %l7
F00A3CD4: ac102032                 mov     0x32, %l6 ! '2'
F00A3CD8: 213c0464                 sethi   %hi(_Cpudelay), %l0
F00A3CDC: 90102001                 mov     1, %o0
F00A3CE0: 7fffcee0                 call    _us_spin
F00A3CE4: d024231c                 st      %o0, [%l0+%lo(_Cpudelay)]
F00A3CE8: a8100010                 mov     %l0, %l4
F00A3CEC: 273c04f6                 sethi   -0xFEC2800, %l3
F00A3CF0: d005231c                 ld      [%l4+0x31C], %o0
F00A3CF4: 912a2001                 sll     %o0, 1, %o0
F00A3CF8: d025231c                 st      %o0, [%l4+0x31C]
F00A3CFC: 7fffcb89                 call    _spl8
F00A3D00: 01000000                 nop
F00A3D04: d204e1e8                 ld      [%l3+0x1E8], %o1
F00A3D08: a4100008                 mov     %o0, %l2
F00A3D0C: e2026004                 ld      [%o1+4], %l1
F00A3D10: 7fffced4                 call    _us_spin
F00A3D14: 90100016                 mov     %l6, %o0
F00A3D18: d004e1e8                 ld      [%l3+0x1E8], %o0
F00A3D1C: e0022004                 ld      [%o0+4], %l0
F00A3D20: 7fffcc01                 call    _splx
F00A3D24: 90100012                 mov     %l2, %o0
F00A3D28: 80a40011                 cmp     %l0, %l1
F00A3D2C: 0abffff4                 bcs     loc_F00A3CFC
F00A3D30: a2240011                 sub     %l0, %l1, %l1
F00A3D34: 80a44017                 cmp     %l1, %l7
F00A3D38: 0abfffef                 bcs     loc_F00A3CF4
F00A3D3C: d005231c                 ld      [%l4+0x31C], %o0
F00A3D40: 213c0464                 sethi   %hi(_Cpudelay), %l0
F00A3D44: d004231c                 ld      [%l0+%lo(_Cpudelay)], %o0
F00A3D48: 7ffd89ee                 call    _umul
F00A3D4C: 92100017                 mov     %l7, %o1
F00A3D50: 90020011                 add     %o0, %l1, %o0
F00A3D54: 7ffd8a2b                 call    _udiv
F00A3D58: 92100011                 mov     %l1, %o1
F00A3D5C: 80a22000                 cmp     %o0, 0
F00A3D60: 16800003                 bge     loc_F00A3D6C
F00A3D64: d024231c                 st      %o0, [%l0+%lo(_Cpudelay)]
F00A3D68: c024231c                 clr     [%l0+%lo(_Cpudelay)]
F00A3D6C: 273c04f6                 sethi   -0xFEC2800, %l3
F00A3D70: 7fffcb6c                 call    _spl8
F00A3D74: 01000000                 nop
F00A3D78: d204e1e8                 ld      [%l3+0x1E8], %o1
F00A3D7C: a4100008                 mov     %o0, %l2
F00A3D80: e2026004                 ld      [%o1+4], %l1
F00A3D84: 7fffceb7                 call    _us_spin
F00A3D88: 90100016                 mov     %l6, %o0
F00A3D8C: d004e1e8                 ld      [%l3+0x1E8], %o0
F00A3D90: e0022004                 ld      [%o0+4], %l0
F00A3D94: 7fffcbe4                 call    _splx
F00A3D98: 90100012                 mov     %l2, %o0
F00A3D9C: 80a40011                 cmp     %l0, %l1
F00A3DA0: 0abffff4                 bcs     loc_F00A3D70
F00A3DA4: 133c0464                 sethi   %hi(_cpudelay), %o1
F00A3DA8: 9010200b                 mov     0xB, %o0
F00A3DAC: d0226320                 st      %o0, [%o1+%lo(_cpudelay)]
F00A3DB0: a6100009                 mov     %o1, %l3
F00A3DB4: 2b3c04f6                 sethi   -0xFEC2800, %l5
F00A3DB8: a92da004                 sll     %l6, 4, %l4
F00A3DBC: d004e320                 ld      [%l3+0x320], %o0
F00A3DC0: 90023fff                 inc     -1, %o0
F00A3DC4: d024e320                 st      %o0, [%l3+0x320]
F00A3DC8: 7fffcb56                 call    _spl8
F00A3DCC: 01000000                 nop
F00A3DD0: d204e320                 ld      [%l3+0x320], %o1
F00A3DD4: a4100008                 mov     %o0, %l2
F00A3DD8: d00561e8                 ld      [%l5+0x1E8], %o0
F00A3DDC: 93350009                 srl     %l4, %o1, %o1
F00A3DE0: 92027fff                 inc     -1, %o1
F00A3DE4: 80a26000                 cmp     %o1, 0
F00A3DE8: 04800007                 ble     loc_F00A3E04
F00A3DEC: e2022004                 ld      [%o0+4], %l1
F00A3DF0: 92027fff                 inc     -1, %o1
F00A3DF4: 80a26000                 cmp     %o1, 0
F00A3DF8: 14bfffff                 bg      loc_F00A3DF4
F00A3DFC: 92027fff                 inc     -1, %o1
F00A3E00: d00561e8                 ld      [%l5+0x1E8], %o0
F00A3E04: e0022004                 ld      [%o0+4], %l0
F00A3E08: 7fffcbc7                 call    _splx
F00A3E0C: 90100012                 mov     %l2, %o0
F00A3E10: 80a40011                 cmp     %l0, %l1
F00A3E14: 0abfffed                 bcs     loc_F00A3DC8
F00A3E18: 01000000                 nop
F00A3E1C: a2240011                 sub     %l0, %l1, %l1
F00A3E20: 80a44017                 cmp     %l1, %l7
F00A3E24: 1a800005                 bcc     locret_F00A3E38
F00A3E28: d004e320                 ld      [%l3+0x320], %o0
F00A3E2C: 80a22000                 cmp     %o0, 0
F00A3E30: 14bfffe5                 bg      loc_F00A3DC4
F00A3E34: 90023fff                 inc     -1, %o0
F00A3E38: 81c7e008                 ret
F00A3E3C: 81e80000                 restore
