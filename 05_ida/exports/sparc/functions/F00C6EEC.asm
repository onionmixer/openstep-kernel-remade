F00C6EEC: 9de3bf90                 save    %sp, -0x70, %sp
F00C6EF0: 113c0504                 sethi   %hi(paName), %o0! id
F00C6EF4: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00C6EF8: a4100018                 mov     %i0, %l2
F00C6EFC: 4000aa5d                 call    _objc_msgSend
F00C6F00: 90100012                 mov     %l2, %o0
F00C6F04: a2100008                 mov     %o0, %l1
F00C6F08: d004a184                 ld      [%l2+0x184], %o0! id
F00C6F0C: 133c0504                 sethi   %hi(paIsdiskready), %o1
F00C6F10: d2026164                 ld      [%o1+%lo(paIsdiskready)], %o1! SEL
F00C6F14: 4000aa57                 call    _objc_msgSend
F00C6F18: 94102001                 mov     1, %o2
F00C6F1C: b0100008                 mov     %o0, %i0
F00C6F20: 80a63bb2                 cmp     %i0, -0x44E
F00C6F24: 02800006                 be      loc_F00C6F3C
F00C6F28: 80a62000                 cmp     %i0, 0
F00C6F2C: 32800006                 bne,a   loc_F00C6F44
F00C6F30: 90100012                 mov     %l2, %o0
F00C6F34: 1080000f                 ba      loc_F00C6F70
F00C6F38: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C6F3C: 10800040                 ba      locret_F00C703C
F00C6F40: b0103bb2                 mov     -0x44E, %i0
F00C6F44: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00C6F48: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00C6F4C: 94100018                 mov     %i0, %o2
F00C6F50: 213c03ea                 sethi   %hi(aSDevicerwcommo), %l0! "%s deviceRwCommon: bogus return from is"...
F00C6F54: 4000aa47                 call    _objc_msgSend
F00C6F58: a01423a8                 bset    %lo(aSDevicerwcommo), %l0! "%s deviceRwCommon: bogus return from is"...
F00C6F5C: 94100008                 mov     %o0, %o2
F00C6F60: 90100010                 mov     %l0, %o0! id
F00C6F64: 7ffffc64                 call    _IOLog
F00C6F68: 92100011                 mov     %l1, %o1
F00C6F6C: 30800034                 ba,a    locret_F00C703C
F00C6F70: d2022188                 ld      [%o0+0x188], %o1! SEL
F00C6F74: 4000aa3f                 call    _objc_msgSend
F00C6F78: 90100012                 mov     %l2, %o0! id
F00C6F7C: 133c0504                 sethi   %hi(paDisksize), %o1
F00C6F80: b0100008                 mov     %o0, %i0
F00C6F84: d20261b0                 ld      [%o1+%lo(paDisksize)], %o1! SEL
F00C6F88: 4000aa3a                 call    _objc_msgSend
F00C6F8C: 90100012                 mov     %l2, %o0
F00C6F90: a0100008                 mov     %o0, %l0
F00C6F94: 9010001b                 mov     %i3, %o0
F00C6F98: 7ffcfe42                 call    _urem
F00C6F9C: 92100018                 mov     %i0, %o1
F00C6FA0: 80a22000                 cmp     %o0, 0
F00C6FA4: 02800007                 be      loc_F00C6FC0
F00C6FA8: 113c03ea                 sethi   %hi(aSBytesRequeste), %o0! "%s: Bytes requested not multiple of blo"...
F00C6FAC: 901223e0                 bset    %lo(aSBytesRequeste), %o0! "%s: Bytes requested not multiple of blo"...
F00C6FB0: 7ffffc51                 call    _IOLog
F00C6FB4: 92100011                 mov     %l1, %o1
F00C6FB8: 10800021                 ba      locret_F00C703C
F00C6FBC: b0103d3e                 mov     -0x2C2, %i0
F00C6FC0: 9010001b                 mov     %i3, %o0
F00C6FC4: 7ffcfd8f                 call    _udiv
F00C6FC8: 92100018                 mov     %i0, %o1
F00C6FCC: a2100008                 mov     %o0, %l1
F00C6FD0: 90068011                 add     %i2, %l1, %o0
F00C6FD4: 80a20010                 cmp     %o0, %l0
F00C6FD8: 08800006                 bleu    loc_F00C6FF0
F00C6FDC: 80a68010                 cmp     %i2, %l0
F00C6FE0: 0a800004                 bcs     loc_F00C6FF0
F00C6FE4: a224001a                 sub     %l0, %i2, %l1
F00C6FE8: 10800015                 ba      locret_F00C703C
F00C6FEC: b0103d3e                 mov     -0x2C2, %i0
F00C6FF0: d204a18c                 ld      [%l2+0x18C], %o1
F00C6FF4: 7ffcfd83                 call    _udiv
F00C6FF8: 90100018                 mov     %i0, %o0
F00C6FFC: a0100008                 mov     %o0, %l0
F00C7000: 90100011                 mov     %l1, %o0
F00C7004: 7ffcfd3f                 call    _umul
F00C7008: 92100010                 mov     %l0, %o1
F00C700C: a2100008                 mov     %o0, %l1
F00C7010: 9010001a                 mov     %i2, %o0
F00C7014: 7ffcfd3b                 call    _umul
F00C7018: 92100010                 mov     %l0, %o1
F00C701C: d204a188                 ld      [%l2+0x188], %o1
F00C7020: 90020009                 add     %o0, %o1, %o0
F00C7024: d0270000                 st      %o0, [%i4]
F00C7028: d204a18c                 ld      [%l2+0x18C], %o1
F00C702C: 7ffcfd35                 call    _umul
F00C7030: 90100011                 mov     %l1, %o0
F00C7034: d0274000                 st      %o0, [%i5]
F00C7038: b0102000                 mov     0, %i0
F00C703C: 81c7e008                 ret
F00C7040: 81e80000                 restore
