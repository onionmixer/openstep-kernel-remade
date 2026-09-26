F008D224: 9de3bf88                 save    %sp, -0x78, %sp
F008D228: c027bfec                 clr     [%fp+var_14]
F008D22C: c027bfe8                 clr     [%fp+var_18]
F008D230: f2062008                 ld      [%i0+8], %i1
F008D234: c406200c                 ld      [%i0+0xC], %g2
F008D238: ba062018                 add     %i0, 0x18, %i5
F008D23C: c207a040                 ld      [%fp+arg_40], %g1
F008D240: 80a64002                 cmp     %i1, %g2
F008D244: 1a80001c                 bcc     loc_F008D2B4
F008D248: b406401a                 add     %i1, %i2, %i2
F008D24C: b8268019                 sub     %i2, %i1, %i4
F008D250: c6074000                 ld      [%i5], %g3
F008D254: 80a0e000                 cmp     %g3, 0
F008D258: 22800007                 be,a    loc_F008D274
F008D25C: f227bfe8                 st      %i1, [%fp+var_18]
F008D260: c400e00c                 ld      [%g3+0xC], %g2
F008D264: 80a68002                 cmp     %i2, %g2
F008D268: 38800005                 bgu,a   loc_F008D27C
F008D26C: c400e010                 ld      [%g3+0x10], %g2
F008D270: f227bfe8                 st      %i1, [%fp+var_18]
F008D274: 10800007                 ba      loc_F008D290
F008D278: f827bfec                 st      %i4, [%fp+var_14]
F008D27C: 80a08019                 cmp     %g2, %i1
F008D280: 18800005                 bgu     loc_F008D294
F008D284: c407bfec                 ld      [%fp+var_14], %g2
F008D288: 10bffff2                 ba      loc_F008D250
F008D28C: ba00e004                 add     %g3, 4, %i5
F008D290: c407bfec                 ld      [%fp+var_14], %g2
F008D294: 80a0a000                 cmp     %g2, 0
F008D298: 12800008                 bne     loc_F008D2B8
F008D29C: c407bfe8                 ld      [%fp+var_18], %g2
F008D2A0: b206401b                 add     %i1, %i3, %i1
F008D2A4: c406200c                 ld      [%i0+0xC], %g2
F008D2A8: 80a64002                 cmp     %i1, %g2
F008D2AC: 0abfffe8                 bcs     loc_F008D24C
F008D2B0: b406801b                 add     %i2, %i3, %i2
F008D2B4: c407bfe8                 ld      [%fp+var_18], %g2
F008D2B8: c4204000                 st      %g2, [%g1]
F008D2BC: c407bfec                 ld      [%fp+var_14], %g2
F008D2C0: c4206004                 st      %g2, [%g1+4]
F008D2C4: 81c7e00c                 jmp     %i7+0xC
F008D2C8: 91e80001                 restore %g0, %g1, %o0
