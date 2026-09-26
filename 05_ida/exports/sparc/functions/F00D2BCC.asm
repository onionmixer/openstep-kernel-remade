F00D2BCC: 9de3bf90                 save    %sp, -0x70, %sp
F00D2BD0: d0062110                 ld      [%i0+0x110], %o0! id
F00D2BD4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D2BD8: 40007b26                 call    _objc_msgSend
F00D2BDC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D2BE0: d0062114                 ld      [%i0+0x114], %o0
F00D2BE4: 80a68008                 cmp     %i2, %o0
F00D2BE8: 3280000b                 bne,a   loc_F00D2C14
F00D2BEC: d0062110                 ld      [%i0+0x110], %o0
F00D2BF0: d04e21d0                 ldsb    [%i0+0x1D0], %o0
F00D2BF4: 80a22000                 cmp     %o0, 0
F00D2BF8: 22800007                 be,a    loc_F00D2C14
F00D2BFC: d0062110                 ld      [%i0+0x110], %o0
F00D2C00: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D2C04: 80a22000                 cmp     %o0, 0
F00D2C08: 32800008                 bne,a   loc_F00D2C28
F00D2C0C: d0062150                 ld      [%i0+0x150], %o0
F00D2C10: d0062110                 ld      [%i0+0x110], %o0! id
F00D2C14: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D2C18: 40007b16                 call    _objc_msgSend
F00D2C1C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D2C20: 1080001e                 ba      locret_F00D2C98
F00D2C24: b0103d3f                 mov     -0x2C1, %i0
F00D2C28: d2062154                 ld      [%i0+0x154], %o1
F00D2C2C: d4062160                 ld      [%i0+0x160], %o2
F00D2C30: d6062158                 ld      [%i0+0x158], %o3
F00D2C34: d806215c                 ld      [%i0+0x15C], %o4
F00D2C38: 7fffb12b                 call    _destroyEventShmem
F00D2C3C: c02e21d2                 clrb    [%i0+0x1D2]
F00D2C40: b4920000                 orcc    %o0, %g0, %i2
F00D2C44: 0280000b                 be      loc_F00D2C70
F00D2C48: 90100018                 mov     %i0, %o0! id
F00D2C4C: 133c0504                 sethi   %hi(paName), %o1
F00D2C50: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D2C54: 213c03ef                 sethi   %hi(aSDestroyevents), %l0! "%s: destroyEventShmem fails (%d).\n"
F00D2C58: 40007b06                 call    _objc_msgSend
F00D2C5C: a01421c0                 bset    %lo(aSDestroyevents), %l0! "%s: destroyEventShmem fails (%d).\n"
F00D2C60: 92100008                 mov     %o0, %o1
F00D2C64: 90100010                 mov     %l0, %o0
F00D2C68: 7fffcd23                 call    _IOLog
F00D2C6C: 9410001a                 mov     %i2, %o2
F00D2C70: c0262158                 clr     [%i0+0x158]
F00D2C74: c026215c                 clr     [%i0+0x15C]
F00D2C78: c0262160                 clr     [%i0+0x160]
F00D2C7C: c0262154                 clr     [%i0+0x154]
F00D2C80: d0062110                 ld      [%i0+0x110], %o0! id
F00D2C84: 133c0504                 sethi   %hi(paUnlock), %o1
F00D2C88: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D2C8C: 40007af9                 call    _objc_msgSend
F00D2C90: c0262150                 clr     [%i0+0x150]
F00D2C94: b010001a                 mov     %i2, %i0
F00D2C98: 81c7e008                 ret
F00D2C9C: 81e80000                 restore
