F009BD30: 9de3bf98                 save    %sp, -0x68, %sp
F009BD34: c4070000                 ld      [%i4], %g2
F009BD38: 80a0a000                 cmp     %g2, 0
F009BD3C: 22800002                 be,a    loc_F009BD44
F009BD40: c0270000                 clr     [%i4]
F009BD44: 80a66001                 cmp     %i1, 1
F009BD48: 12800008                 bne     locret_F009BD68
F009BD4C: b0102000                 mov     0, %i0
F009BD50: 80a6e012                 cmp     %i3, 0x12
F009BD54: 08800005                 bleu    locret_F009BD68
F009BD58: b0102004                 mov     4, %i0
F009BD5C: c406a004                 ld      [%i2+4], %g2
F009BD60: c4270000                 st      %g2, [%i4]
F009BD64: b0102000                 mov     0, %i0
F009BD68: 81c7e008                 ret
F009BD6C: 81e80000                 restore
