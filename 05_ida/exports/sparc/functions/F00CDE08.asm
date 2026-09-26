F00CDE08: 9de3bf90                 save    %sp, -0x70, %sp
F00CDE0C: 90100018                 mov     %i0, %o0! id
F00CDE10: 133c0505                 sethi   %hi(paScsistartstopI), %o1
F00CDE14: d20263c8                 ld      [%o1+%lo(paScsistartstopI)], %o1! SEL
F00CDE18: 94102002                 mov     2, %o2
F00CDE1C: 40008e95                 call    _objc_msgSend
F00CDE20: 96102000                 mov     0, %o3
F00CDE24: 81c7e008                 ret
F00CDE28: 91e80008                 restore %g0, %o0, %o0
