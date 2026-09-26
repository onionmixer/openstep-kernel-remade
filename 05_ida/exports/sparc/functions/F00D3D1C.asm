F00D3D1C: 9de3bf88                 save    %sp, -0x78, %sp
F00D3D20: d0062188                 ld      [%i0+0x188], %o0
F00D3D24: 80a22000                 cmp     %o0, 0
F00D3D28: 02800041                 be      locret_F00D3E2C
F00D3D2C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D3D30: d0062110                 ld      [%i0+0x110], %o0! id
F00D3D34: 400076cf                 call    _objc_msgSend
F00D3D38: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D3D3C: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D3D40: 80a22000                 cmp     %o0, 0
F00D3D44: 32800006                 bne,a   loc_F00D3D5C
F00D3D48: d4062168                 ld      [%i0+0x168], %o2
F00D3D4C: d0062110                 ld      [%i0+0x110], %o0
F00D3D50: 133c0504                 sethi   %hi(paUnlock), %o1
F00D3D54: 10800034                 ba      loc_F00D3E24
F00D3D58: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D3D5C: d212a018                 lduh    [%o2+0x18], %o1
F00D3D60: 90100018                 mov     %i0, %o0! id
F00D3D64: d237bfe8                 sth     %o1, [%fp+var_18]
F00D3D68: d412a01a                 lduh    [%o2+0x1A], %o2
F00D3D6C: 133c0505                 sethi   %hi(paPointtoscreen), %o1
F00D3D70: d20262ac                 ld      [%o1+%lo(paPointtoscreen)], %o1! SEL
F00D3D74: d437bfea                 sth     %o2, [%fp+var_16]
F00D3D78: 400076be                 call    _objc_msgSend
F00D3D7C: 9407bfe8                 add     %fp, var_18, %o2
F00D3D80: 92920000                 orcc    %o0, %g0, %o1
F00D3D84: 16800006                 bge     loc_F00D3D9C
F00D3D88: d226218c                 st      %o1, [%i0+0x18C]
F00D3D8C: d0062110                 ld      [%i0+0x110], %o0
F00D3D90: 133c0504                 sethi   %hi(paUnlock), %o1
F00D3D94: 10800024                 ba      loc_F00D3E24
F00D3D98: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D3D9C: 912a6002                 sll     %o1, 2, %o0
F00D3DA0: 90020009                 add     %o0, %o1, %o0
F00D3DA4: d4062180                 ld      [%i0+0x180], %o2
F00D3DA8: 912a2002                 sll     %o0, 2, %o0
F00D3DAC: 94028008                 add     %o2, %o0, %o2
F00D3DB0: d012a00c                 lduh    [%o2+0xC], %o0
F00D3DB4: d0362190                 sth     %o0, [%i0+0x190]
F00D3DB8: d612a00e                 lduh    [%o2+0xE], %o3
F00D3DBC: 113c0505                 sethi   %hi(paSetbrightness_0), %o0
F00D3DC0: d20222a8                 ld      [%o0+%lo(paSetbrightness_0)], %o1! SEL
F00D3DC4: d6362192                 sth     %o3, [%i0+0x192]
F00D3DC8: d812a010                 lduh    [%o2+0x10], %o4
F00D3DCC: 90100018                 mov     %i0, %o0! id
F00D3DD0: d6162192                 lduh    [%i0+0x192], %o3
F00D3DD4: d8362194                 sth     %o4, [%i0+0x194]
F00D3DD8: d412a012                 lduh    [%o2+0x12], %o2
F00D3DDC: 9602ffff                 inc     -1, %o3
F00D3DE0: d4362196                 sth     %o2, [%i0+0x196]
F00D3DE4: d4162196                 lduh    [%i0+0x196], %o2
F00D3DE8: d6362192                 sth     %o3, [%i0+0x192]
F00D3DEC: 9402bfff                 inc     -1, %o2
F00D3DF0: 400076a0                 call    _objc_msgSend
F00D3DF4: d4362196                 sth     %o2, [%i0+0x196]
F00D3DF8: 113c0505                 sethi   %hi(paShowcursor), %o0! id
F00D3DFC: d2022310                 ld      [%o0+%lo(paShowcursor)], %o1! SEL
F00D3E00: 4000769c                 call    _objc_msgSend
F00D3E04: 90100018                 mov     %i0, %o0
F00D3E08: d0062110                 ld      [%i0+0x110], %o0! id
F00D3E0C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D3E10: 40007698                 call    _objc_msgSend
F00D3E14: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D3E18: 113c0505                 sethi   %hi(paAttachdefaulte), %o0
F00D3E1C: d20222a4                 ld      [%o0+%lo(paAttachdefaulte)], %o1! SEL
F00D3E20: 90100018                 mov     %i0, %o0! id
F00D3E24: 40007693                 call    _objc_msgSend
F00D3E28: 01000000                 nop
F00D3E2C: 81c7e008                 ret
F00D3E30: 81e80000                 restore
