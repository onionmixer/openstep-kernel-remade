F00B0D14: 9de3bf98                 save    %sp, -0x68, %sp
F00B0D18: 80a62000                 cmp     %i0, 0
F00B0D1C: 02800008                 be      locret_F00B0D3C
F00B0D20: 90100018                 mov     %i0, %o0
F00B0D24: 9fc64000                 call    %i1
F00B0D28: 9210001a                 mov     %i2, %o1
F00B0D2C: f0062004                 ld      [%i0+4], %i0
F00B0D30: 80a62000                 cmp     %i0, 0
F00B0D34: 12bffffc                 bne     loc_F00B0D24
F00B0D38: 90100018                 mov     %i0, %o0
F00B0D3C: 81c7e008                 ret
F00B0D40: 81e80000                 restore
