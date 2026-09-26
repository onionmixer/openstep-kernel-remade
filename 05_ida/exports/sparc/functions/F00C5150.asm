F00C5150: 9de3bf90                 save    %sp, -0x70, %sp
F00C5154: 113c0506                 sethi   %hi(paBlockmajor), %o0! id
F00C5158: d20221d8                 ld      [%o0+%lo(paBlockmajor)], %o1! SEL
F00C515C: 4000b1c5                 call    _objc_msgSend
F00C5160: 90100018                 mov     %i0, %o0
F00C5164: 80a23fff                 cmp     %o0, -1
F00C5168: 2280000a                 be,a    locret_F00C5190
F00C516C: b0102000                 mov     0, %i0
F00C5170: 400016fb                 call    _IORemoveFromBdevsw
F00C5174: 01000000                 nop
F00C5178: 90100018                 mov     %i0, %o0! id
F00C517C: 133c0506                 sethi   %hi(paSetblockmajor), %o1
F00C5180: d20261e0                 ld      [%o1+%lo(paSetblockmajor)], %o1! SEL
F00C5184: 4000b1bb                 call    _objc_msgSend
F00C5188: 94103fff                 mov     -1, %o2
F00C518C: b0102001                 mov     1, %i0
F00C5190: 81c7e008                 ret
F00C5194: 81e80000                 restore
