F00D4304: 9de3bf90                 save    %sp, -0x70, %sp
F00D4308: 7fffab2d                 call    _defaultEventSources
F00D430C: 01000000                 nop
F00D4310: a0100008                 mov     %o0, %l0
F00D4314: d0040000                 ld      [%l0], %o0! id
F00D4318: 80a22000                 cmp     %o0, 0
F00D431C: 0280000b                 be      locret_F00D4348
F00D4320: 233c0505                 sethi   %hi(paAttacheventsou), %l1
F00D4324: d204628c                 ld      [%l1+%lo(paAttacheventsou)], %o1! SEL
F00D4328: d4040000                 ld      [%l0], %o2
F00D432C: 40007551                 call    _objc_msgSend
F00D4330: 90100018                 mov     %i0, %o0
F00D4334: a0042004                 inc     4, %l0
F00D4338: d0040000                 ld      [%l0], %o0
F00D433C: 80a22000                 cmp     %o0, 0
F00D4340: 12bffffa                 bne     loc_F00D4328
F00D4344: d204628c                 ld      [%l1+0x28C], %o1
F00D4348: 81c7e008                 ret
F00D434C: 81e80000                 restore
