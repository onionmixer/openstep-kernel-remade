F001CE08: 9de3bf98                 save    %sp, -0x68, %sp
F001CE0C: 86100018                 mov     %i0, %g3
F001CE10: c400c000                 ld      [%g3], %g2
F001CE14: 80a0a000                 cmp     %g2, 0
F001CE18: 0280001e                 be      loc_F001CE90
F001CE1C: b0100019                 mov     %i1, %i0
F001CE20: c400e008                 ld      [%g3+8], %g2
F001CE24: b0062001                 inc     %i0
F001CE28: 80a60002                 cmp     %i0, %g2
F001CE2C: 02800019                 be      loc_F001CE90
F001CE30: 808e203f                 btst    0x3F, %i0 ! '?'
F001CE34: 12800005                 bne     loc_F001CE48
F001CE38: b20e203f                 and     %i0, 0x3F, %i1
F001CE3C: c4063fc0                 ld      [%i0-0x40], %g2
F001CE40: b000a00c                 add     %g2, 0xC, %i0
F001CE44: b20e203f                 and     %i0, 0x3F, %i1
F001CE48: 84100019                 mov     %i1, %g2
F001CE4C: f64e0000                 ldsb    [%i0], %i3
F001CE50: 80a66000                 cmp     %i1, 0
F001CE54: 860e3fc0                 and     %i0, -0x40, %g3
F001CE58: 16800003                 bge     loc_F001CE64
F001CE5C: f6268000                 st      %i3, [%i2]
F001CE60: 84066007                 add     %i1, 7, %g2
F001CE64: 8538a003                 sra     %g2, 3, %g2
F001CE68: 86008003                 add     %g2, %g3, %g3
F001CE6C: c648e004                 ldsb    [%g3+4], %g3
F001CE70: 8528a003                 sll     %g2, 3, %g2
F001CE74: 84264002                 sub     %i1, %g2, %g2
F001CE78: 8738c002                 sra     %g3, %g2, %g3
F001CE7C: 8088e001                 btst    1, %g3
F001CE80: 02800005                 be      locret_F001CE94
F001CE84: 8416e100                 or      %i3, 0x100, %g2
F001CE88: 10800003                 ba      locret_F001CE94
F001CE8C: c4268000                 st      %g2, [%i2]
F001CE90: b0102000                 mov     0, %i0
F001CE94: 81c7e008                 ret
F001CE98: 81e80000                 restore
