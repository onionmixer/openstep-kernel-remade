F00D3AF8: 9de3bf90                 save    %sp, -0x70, %sp
F00D3AFC: d0062110                 ld      [%i0+0x110], %o0! id
F00D3B00: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D3B04: 4000775b                 call    _objc_msgSend
F00D3B08: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D3B0C: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D3B10: 80a22000                 cmp     %o0, 0
F00D3B14: 2280007d                 be,a    loc_F00D3D08
F00D3B18: d0062110                 ld      [%i0+0x110], %o0
F00D3B1C: e0062168                 ld      [%i0+0x168], %l0
F00D3B20: 7fffc96f                 call    _IOGetTimestamp
F00D3B24: 90062200                 add     %i0, 0x200, %o0
F00D3B28: d41e2200                 ldd     [%i0+0x200], %o2
F00D3B2C: 9b2aa008                 sll     %o2, 8, %o5
F00D3B30: 9932e018                 srl     %o3, 24, %o4
F00D3B34: 9213400c                 or      %o5, %o4, %o1
F00D3B38: 96924000                 orcc    %o1, %g0, %o3
F00D3B3C: 12800003                 bne     loc_F00D3B48
F00D3B40: 9132a018                 srl     %o2, 24, %o0
F00D3B44: 96102001                 mov     1, %o3
F00D3B48: d6242010                 st      %o3, [%l0+0x10]
F00D3B4C: d04e2211                 ldsb    [%i0+0x211], %o0
F00D3B50: 80a22001                 cmp     %o0, 1
F00D3B54: 12800006                 bne     loc_F00D3B6C
F00D3B58: 90100018                 mov     %i0, %o0! id
F00D3B5C: 133c0505                 sethi   %hi(paSetcursorposit_0), %o1
F00D3B60: d20262c0                 ld      [%o1+%lo(paSetcursorposit_0)], %o1! SEL
F00D3B64: 40007743                 call    _objc_msgSend
F00D3B68: 940621a8                 add     %i0, 0x1A8, %o2
F00D3B6C: 7fffbcb9                 call    _ev_try_lock
F00D3B70: 90042040                 add     %l0, 0x40, %o0 ! '@'
F00D3B74: 80a22000                 cmp     %o0, 0
F00D3B78: 02800060                 be      loc_F00D3CF8
F00D3B7C: 113c0505                 sethi   -0xFEBEC00, %o0
F00D3B80: 7fffbcb4                 call    _ev_try_lock
F00D3B84: 90042014                 add     %l0, 0x14, %o0
F00D3B88: 80a22000                 cmp     %o0, 0
F00D3B8C: 02800058                 be      loc_F00D3CEC
F00D3B90: 01000000                 nop
F00D3B94: d2042038                 ld      [%l0+0x38], %o1
F00D3B98: d004203c                 ld      [%l0+0x3C], %o0
F00D3B9C: 80a24008                 cmp     %o1, %o0
F00D3BA0: 0280000c                 be      loc_F00D3BD0
F00D3BA4: 01000000                 nop
F00D3BA8: d0042010                 ld      [%l0+0x10], %o0
F00D3BAC: d4042038                 ld      [%l0+0x38], %o2
F00D3BB0: d214204c                 lduh    [%l0+0x4C], %o1
F00D3BB4: 9022000a                 sub     %o0, %o2, %o0
F00D3BB8: 932a6010                 sll     %o1, 16, %o1
F00D3BBC: 933a6010                 sra     %o1, 16, %o1
F00D3BC0: 80a20009                 cmp     %o0, %o1
F00D3BC4: 04800003                 ble     loc_F00D3BD0
F00D3BC8: 90102001                 mov     1, %o0
F00D3BCC: d02c2048                 stb     %o0, [%l0+0x48]
F00D3BD0: d00c2049                 ldub    [%l0+0x49], %o0
F00D3BD4: 80a22000                 cmp     %o0, 0
F00D3BD8: 02800010                 be      loc_F00D3C18
F00D3BDC: 01000000                 nop
F00D3BE0: d00c204a                 ldub    [%l0+0x4A], %o0
F00D3BE4: 80a22000                 cmp     %o0, 0
F00D3BE8: 0280000c                 be      loc_F00D3C18
F00D3BEC: 01000000                 nop
F00D3BF0: d00c2048                 ldub    [%l0+0x48], %o0
F00D3BF4: 80a22000                 cmp     %o0, 0
F00D3BF8: 02800008                 be      loc_F00D3C18
F00D3BFC: 01000000                 nop
F00D3C00: d0042044                 ld      [%l0+0x44], %o0
F00D3C04: 80a22000                 cmp     %o0, 0
F00D3C08: 12800017                 bne     loc_F00D3C64
F00D3C0C: 113c0505                 sethi   %hi(paShowwaitcursor), %o0
F00D3C10: 10800013                 ba      loc_F00D3C5C
F00D3C14: d20222bc                 ld      [%o0+%lo(paShowwaitcursor)], %o1
F00D3C18: d0042044                 ld      [%l0+0x44], %o0
F00D3C1C: 80a22000                 cmp     %o0, 0
F00D3C20: 02800011                 be      loc_F00D3C64
F00D3C24: 01000000                 nop
F00D3C28: d20621e0                 ld      [%i0+0x1E0], %o1
F00D3C2C: d0062200                 ld      [%i0+0x200], %o0
F00D3C30: 80a24008                 cmp     %o1, %o0
F00D3C34: 1880000c                 bgu     loc_F00D3C64
F00D3C38: 01000000                 nop
F00D3C3C: 12800007                 bne     loc_F00D3C58
F00D3C40: 113c0505                 sethi   -0xFEBEC00, %o0
F00D3C44: d20621e4                 ld      [%i0+0x1E4], %o1
F00D3C48: d0062204                 ld      [%i0+0x204], %o0
F00D3C4C: 80a24008                 cmp     %o1, %o0
F00D3C50: 18800005                 bgu     loc_F00D3C64
F00D3C54: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D3C58: d20222b8                 ld      [%o0+0x2B8], %o1! SEL
F00D3C5C: 40007705                 call    _objc_msgSend
F00D3C60: 90100018                 mov     %i0, %o0
F00D3C64: d0042044                 ld      [%l0+0x44], %o0
F00D3C68: 80a22000                 cmp     %o0, 0
F00D3C6C: 02800011                 be      loc_F00D3CB0
F00D3C70: 01000000                 nop
F00D3C74: d20621f0                 ld      [%i0+0x1F0], %o1
F00D3C78: d0062200                 ld      [%i0+0x200], %o0
F00D3C7C: 80a24008                 cmp     %o1, %o0
F00D3C80: 1880000c                 bgu     loc_F00D3CB0
F00D3C84: 01000000                 nop
F00D3C88: 12800007                 bne     loc_F00D3CA4
F00D3C8C: 113c0505                 sethi   -0xFEBEC00, %o0
F00D3C90: d20621f4                 ld      [%i0+0x1F4], %o1
F00D3C94: d0062204                 ld      [%i0+0x204], %o0
F00D3C98: 80a24008                 cmp     %o1, %o0
F00D3C9C: 18800005                 bgu     loc_F00D3CB0
F00D3CA0: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D3CA4: d20222b4                 ld      [%o0+0x2B4], %o1! SEL
F00D3CA8: 400076f2                 call    _objc_msgSend
F00D3CAC: 90100018                 mov     %i0, %o0
F00D3CB0: 7fffbc66                 call    _ev_unlock
F00D3CB4: 90042014                 add     %l0, 0x14, %o0
F00D3CB8: d2042010                 ld      [%l0+0x10], %o1
F00D3CBC: d00621a4                 ld      [%i0+0x1A4], %o0
F00D3CC0: 80a24008                 cmp     %o1, %o0
F00D3CC4: 0880000a                 bleu    loc_F00D3CEC
F00D3CC8: 01000000                 nop
F00D3CCC: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D3CD0: 80a22000                 cmp     %o0, 0
F00D3CD4: 12800006                 bne     loc_F00D3CEC
F00D3CD8: 01000000                 nop
F00D3CDC: 113c0505                 sethi   %hi(paDoautodim), %o0! id
F00D3CE0: d20222b0                 ld      [%o0+%lo(paDoautodim)], %o1! SEL
F00D3CE4: 400076e3                 call    _objc_msgSend
F00D3CE8: 90100018                 mov     %i0, %o0
F00D3CEC: 7fffbc57                 call    _ev_unlock
F00D3CF0: 90042040                 add     %l0, 0x40, %o0 ! '@'
F00D3CF4: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D3CF8: d2022308                 ld      [%o0+0x308], %o1! SEL
F00D3CFC: 400076dd                 call    _objc_msgSend
F00D3D00: 90100018                 mov     %i0, %o0
F00D3D04: d0062110                 ld      [%i0+0x110], %o0! id
F00D3D08: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D3D0C: 400076d9                 call    _objc_msgSend
F00D3D10: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D3D14: 81c7e008                 ret
F00D3D18: 81e80000                 restore
