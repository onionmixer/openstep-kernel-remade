F00B0D44: 9de3bf98                 save    %sp, -0x68, %sp
F00B0D48: 80a62000                 cmp     %i0, 0
F00B0D4C: 0280000c                 be      locret_F00B0D7C
F00B0D50: 01000000                 nop
F00B0D54: d0062008                 ld      [%i0+8], %o0
F00B0D58: 80a22000                 cmp     %o0, 0
F00B0D5C: 22800005                 be,a    loc_F00B0D70
F00B0D60: f0062004                 ld      [%i0+4], %i0
F00B0D64: 9fc64000                 call    %i1
F00B0D68: 9210001a                 mov     %i2, %o1
F00B0D6C: f0062004                 ld      [%i0+4], %i0
F00B0D70: 80a62000                 cmp     %i0, 0
F00B0D74: 32bffff9                 bne,a   loc_F00B0D58
F00B0D78: d0062008                 ld      [%i0+8], %o0
F00B0D7C: 81c7e008                 ret
F00B0D80: 81e80000                 restore
