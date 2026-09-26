F00C1ECC: 9de3bf90                 save    %sp, -0x70, %sp
F00C1ED0: d0062148                 ld      [%i0+0x148], %o0! id
F00C1ED4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C1ED8: 4000be66                 call    _objc_msgSend
F00C1EDC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C1EE0: d0062140                 ld      [%i0+0x140], %o0
F00C1EE4: 80a2001a                 cmp     %o0, %i2
F00C1EE8: 12800006                 bne     loc_F00C1F00
F00C1EEC: a2103d2b                 mov     -0x2D5, %l1
F00C1EF0: a2102000                 mov     0, %l1
F00C1EF4: c0262140                 clr     [%i0+0x140]
F00C1EF8: 113c04fd                 sethi   %hi(_type5kbd_owner), %o0
F00C1EFC: c0222258                 clr     [%o0+%lo(_type5kbd_owner)]
F00C1F00: d0062148                 ld      [%i0+0x148], %o0! id
F00C1F04: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C1F08: 4000be5a                 call    _objc_msgSend
F00C1F0C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C1F10: 80a46000                 cmp     %l1, 0
F00C1F14: 1280001e                 bne     locret_F00C1F8C
F00C1F18: 01000000                 nop
F00C1F1C: d0062144                 ld      [%i0+0x144], %o0! id
F00C1F20: 80a22000                 cmp     %o0, 0
F00C1F24: 0280001a                 be      locret_F00C1F8C
F00C1F28: 80a2001a                 cmp     %o0, %i2
F00C1F2C: 02800018                 be      locret_F00C1F8C
F00C1F30: 133c0504                 sethi   %hi(paCanbecomeowner), %o1
F00C1F34: e0026320                 ld      [%o1+%lo(paCanbecomeowner)], %l0
F00C1F38: 133c0504                 sethi   %hi(paRespondsto), %o1
F00C1F3C: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00C1F40: 4000be4c                 call    _objc_msgSend
F00C1F44: 94100010                 mov     %l0, %o2
F00C1F48: 912a2018                 sll     %o0, 24, %o0
F00C1F4C: 80a22000                 cmp     %o0, 0
F00C1F50: 02800006                 be      loc_F00C1F68
F00C1F54: 92100010                 mov     %l0, %o1! SEL
F00C1F58: d0062144                 ld      [%i0+0x144], %o0! id
F00C1F5C: 4000be45                 call    _objc_msgSend
F00C1F60: 94100018                 mov     %i0, %o2
F00C1F64: 3080000a                 ba,a    locret_F00C1F8C
F00C1F68: 90100018                 mov     %i0, %o0! id
F00C1F6C: 133c0504                 sethi   %hi(paName), %o1
F00C1F70: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C1F74: 213c0484                 sethi   %hi(aSDesiredownerD_0), %l0! "%s: desiredOwner does not respond to ca"...
F00C1F78: 4000be3e                 call    _objc_msgSend
F00C1F7C: a01420e0                 bset    %lo(aSDesiredownerD_0), %l0! "%s: desiredOwner does not respond to ca"...
F00C1F80: 92100008                 mov     %o0, %o1
F00C1F84: 4000105c                 call    _IOLog
F00C1F88: 90100010                 mov     %l0, %o0
F00C1F8C: 81c7e008                 ret
F00C1F90: 91e80011                 restore %g0, %l1, %o0
