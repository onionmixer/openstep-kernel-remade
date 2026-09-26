F00E178C: 9de3bf98                 save    %sp, -0x68, %sp
F00E1790: 808e2001                 btst    1, %i0
F00E1794: 32800002                 bne,a   loc_F00E179C
F00E1798: b00e3ffe                 and     %i0, -2, %i0
F00E179C: 808e6001                 btst    1, %i1
F00E17A0: 32800002                 bne,a   loc_F00E17A8
F00E17A4: b20e7ffe                 and     %i1, -2, %i1
F00E17A8: b406bfff                 inc     -1, %i2
F00E17AC: 80a6bfff                 cmp     %i2, -1
F00E17B0: 02800009                 be      locret_F00E17D4
F00E17B4: 01000000                 nop
F00E17B8: b406bfff                 inc     -1, %i2
F00E17BC: c4160000                 lduh    [%i0], %g2
F00E17C0: 80a6bfff                 cmp     %i2, -1
F00E17C4: b0062002                 inc     2, %i0
F00E17C8: c4364000                 sth     %g2, [%i1]
F00E17CC: 12bffffb                 bne     loc_F00E17B8
F00E17D0: b2066002                 inc     2, %i1
F00E17D4: 81c7e008                 ret
F00E17D8: 81e80000                 restore
