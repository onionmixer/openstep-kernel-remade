F00C1DEC: 9de3bf90                 save    %sp, -0x70, %sp
F00C1DF0: d0062148                 ld      [%i0+0x148], %o0! id
F00C1DF4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C1DF8: 4000be9e                 call    _objc_msgSend
F00C1DFC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C1E00: d0062140                 ld      [%i0+0x140], %o0! id
F00C1E04: 80a22000                 cmp     %o0, 0
F00C1E08: 22800028                 be,a    loc_F00C1EA8
F00C1E0C: f4262140                 st      %i2, [%i0+0x140]
F00C1E10: 133c0504                 sethi   %hi(paRelinquishowne), %o1
F00C1E14: e002631c                 ld      [%o1+%lo(paRelinquishowne)], %l0
F00C1E18: 133c0504                 sethi   %hi(paRespondsto), %o1
F00C1E1C: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00C1E20: 4000be94                 call    _objc_msgSend
F00C1E24: 94100010                 mov     %l0, %o2
F00C1E28: 912a2018                 sll     %o0, 24, %o0
F00C1E2C: 80a22000                 cmp     %o0, 0
F00C1E30: 02800008                 be      loc_F00C1E50
F00C1E34: 90100018                 mov     %i0, %o0
F00C1E38: d0062140                 ld      [%i0+0x140], %o0! id
F00C1E3C: 92100010                 mov     %l0, %o1! SEL
F00C1E40: 4000be8c                 call    _objc_msgSend
F00C1E44: 94100018                 mov     %i0, %o2
F00C1E48: 10800011                 ba      loc_F00C1E8C
F00C1E4C: a6100008                 mov     %o0, %l3
F00C1E50: 133c0504                 sethi   %hi(paName), %o1! SEL
F00C1E54: a6103d2b                 mov     -0x2D5, %l3
F00C1E58: 213c0484                 sethi   %hi(aSOwnerSDoesNot), %l0! "%s: owner %s does not respond to relinq"...
F00C1E5C: e2026008                 ld      [%o1+%lo(paName)], %l1
F00C1E60: a01420a0                 bset    %lo(aSOwnerSDoesNot), %l0! "%s: owner %s does not respond to relinq"...
F00C1E64: 4000be83                 call    _objc_msgSend
F00C1E68: 92100011                 mov     %l1, %o1! SEL
F00C1E6C: a4100008                 mov     %o0, %l2
F00C1E70: d0062140                 ld      [%i0+0x140], %o0! id
F00C1E74: 4000be7f                 call    _objc_msgSend
F00C1E78: 92100011                 mov     %l1, %o1
F00C1E7C: 94100008                 mov     %o0, %o2
F00C1E80: 90100010                 mov     %l0, %o0
F00C1E84: 4000109c                 call    _IOLog
F00C1E88: 92100012                 mov     %l2, %o1
F00C1E8C: 80a4e000                 cmp     %l3, 0
F00C1E90: 3280000a                 bne,a   loc_F00C1EB8
F00C1E94: d0062148                 ld      [%i0+0x148], %o0
F00C1E98: f4262140                 st      %i2, [%i0+0x140]
F00C1E9C: 113c04fd                 sethi   %hi(_type5kbd_owner), %o0
F00C1EA0: 10800005                 ba      loc_F00C1EB4
F00C1EA4: f4222258                 st      %i2, [%o0+%lo(_type5kbd_owner)]
F00C1EA8: 113c04fd                 sethi   %hi(_type5kbd_owner), %o0
F00C1EAC: f4222258                 st      %i2, [%o0+%lo(_type5kbd_owner)]
F00C1EB0: a6102000                 mov     0, %l3
F00C1EB4: d0062148                 ld      [%i0+0x148], %o0! id
F00C1EB8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C1EBC: 4000be6d                 call    _objc_msgSend
F00C1EC0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C1EC4: 81c7e008                 ret
F00C1EC8: 91e80013                 restore %g0, %l3, %o0
