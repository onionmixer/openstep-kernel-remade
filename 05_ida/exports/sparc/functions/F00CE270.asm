F00CE270: 9de3bf98                 save    %sp, -0x68, %sp
F00CE274: 86102000                 mov     0, %g3
F00CE278: 80a6a000                 cmp     %i2, 0
F00CE27C: 0280001a                 be      loc_F00CE2E4
F00CE280: b8100019                 mov     %i1, %i4
F00CE284: 80a6e000                 cmp     %i3, 0
F00CE288: 22800018                 be,a    locret_F00CE2E8
F00CE28C: b026401c                 sub     %i1, %i4, %i0
F00CE290: c44e0000                 ldsb    [%i0], %g2
F00CE294: 80a0a000                 cmp     %g2, 0
F00CE298: 02800007                 be      loc_F00CE2B4
F00CE29C: 80a0a020                 cmp     %g2, 0x20 ! ' '
F00CE2A0: 32800008                 bne,a   loc_F00CE2C0
F00CE2A4: 86102000                 mov     0, %g3
F00CE2A8: 80a0e000                 cmp     %g3, 0
F00CE2AC: 22800005                 be,a    loc_F00CE2C0
F00CE2B0: 86102001                 mov     1, %g3
F00CE2B4: b0062001                 inc     %i0
F00CE2B8: 10800008                 ba      loc_F00CE2D8
F00CE2BC: b406bfff                 inc     -1, %i2
F00CE2C0: b406bfff                 inc     -1, %i2
F00CE2C4: c40e0000                 ldub    [%i0], %g2
F00CE2C8: b606ffff                 inc     -1, %i3
F00CE2CC: c42e4000                 stb     %g2, [%i1]
F00CE2D0: b0062001                 inc     %i0
F00CE2D4: b2066001                 inc     %i1
F00CE2D8: 80a6a000                 cmp     %i2, 0
F00CE2DC: 12bfffeb                 bne     loc_F00CE288
F00CE2E0: 80a6e000                 cmp     %i3, 0
F00CE2E4: b026401c                 sub     %i1, %i4, %i0
F00CE2E8: 81c7e008                 ret
F00CE2EC: 81e80000                 restore
