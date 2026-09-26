F00BF5D8: 9de3bf90                 save    %sp, -0x70, %sp
F00BF5DC: 113c0504                 sethi   %hi(paOwner_0), %o0! id
F00BF5E0: d2022298                 ld      [%o0+%lo(paOwner_0)], %o1! SEL
F00BF5E4: 4000c8a3                 call    _objc_msgSend
F00BF5E8: 90100018                 mov     %i0, %o0! id
F00BF5EC: 133c0504                 sethi   %hi(paUpdateeventfla), %o1
F00BF5F0: d20262a8                 ld      [%o1+%lo(paUpdateeventfla)], %o1! SEL
F00BF5F4: 4000c89f                 call    _objc_msgSend
F00BF5F8: 9410001a                 mov     %i2, %o2
F00BF5FC: 81c7e008                 ret
F00BF600: 91e80008                 restore %g0, %o0, %o0
