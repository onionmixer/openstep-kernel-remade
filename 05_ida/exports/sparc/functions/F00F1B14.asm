F00F1B14: 82003fa0                 add     %g0, -0x60, %g1
F00F1B18: 84a2a01c                 subcc   %o2, 0x1C, %g2
F00F1B1C: 04800003                 ble     loc_F00F1B28
F00F1B20: 84204002                 sub     %g1, %g2, %g2
F00F1B24: 8208bff8                 and     %g2, -8, %g1
F00F1B28: 9de38001                 save    %sp, %g1, %sp
F00F1B2C: 90100018                 mov     %i0, %o0! id
F00F1B30: 92100019                 mov     %i1, %o1! SEL
F00F1B34: b486bff8                 inccc   -8, %i2
F00F1B38: 0280001a                 be      loc_F00F1BA0
F00F1B3C: 01000000                 nop
F00F1B40: d406e008                 ld      [%i3+8], %o2
F00F1B44: b486bffc                 inccc   -4, %i2
F00F1B48: 02800016                 be      loc_F00F1BA0
F00F1B4C: 01000000                 nop
F00F1B50: d606e00c                 ld      [%i3+0xC], %o3
F00F1B54: b486bffc                 inccc   -4, %i2
F00F1B58: 02800012                 be      loc_F00F1BA0
F00F1B5C: 01000000                 nop
F00F1B60: d806e010                 ld      [%i3+0x10], %o4
F00F1B64: b486bffc                 inccc   -4, %i2
F00F1B68: 0280000e                 be      loc_F00F1BA0
F00F1B6C: 01000000                 nop
F00F1B70: da06e014                 ld      [%i3+0x14], %o5
F00F1B74: b486bffc                 inccc   -4, %i2
F00F1B78: 0280000a                 be      loc_F00F1BA0
F00F1B7C: 01000000                 nop
F00F1B80: b206e018                 add     %i3, 0x18, %i1
F00F1B84: ba03a05c                 add     %sp, arg_5C, %i5
F00F1B88: f6064000                 ld      [%i1], %i3
F00F1B8C: b486bffc                 inccc   -4, %i2
F00F1B90: f6274000                 st      %i3, [%i5]
F00F1B94: ba076004                 inc     4, %i5
F00F1B98: 12bffffc                 bne     loc_F00F1B88
F00F1B9C: b2066004                 inc     4, %i1
F00F1BA0: c607e008                 ld      [%i7+8], %g3
F00F1BA4: 053ff000                 sethi   -0x400000, %g2
F00F1BA8: 8088c002                 btst    %g2, %g3
F00F1BAC: 02800007                 be      loc_F00F1BC8
F00F1BB0: 01000000                 nop
F00F1BB4: 7fffff2f                 call    _objc_msgSend
F00F1BB8: 01000000                 nop
F00F1BBC: b0100008                 mov     %o0, %i0
F00F1BC0: 81c7e008                 ret
F00F1BC4: 93ea6000                 restore %o1, 0, %o1! SEL
F00F1BC8: c407a040                 ld      [%fp+arg_40], %g2
F00F1BCC: c423a040                 st      %g2, [%sp+arg_40]
F00F1BD0: 7fffff28                 call    _objc_msgSend
F00F1BD4: 01000000                 nop
F00F1BD8: 00000000                 illtrap
F00F1BDC: 81c7e00c                 jmp     %i7+0xC
F00F1BE0: 81e80000                 restore
