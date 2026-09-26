F00C5108: 9de3bf90                 save    %sp, -0x70, %sp
F00C510C: 113c0506                 sethi   %hi(paCharactermajor), %o0! id
F00C5110: d20221dc                 ld      [%o0+%lo(paCharactermajor)], %o1! SEL
F00C5114: 4000b1d7                 call    _objc_msgSend
F00C5118: 90100018                 mov     %i0, %o0
F00C511C: 80a23fff                 cmp     %o0, -1
F00C5120: 2280000a                 be,a    locret_F00C5148
F00C5124: b0102000                 mov     0, %i0
F00C5128: 400017a6                 call    _IORemoveFromCdevsw
F00C512C: 01000000                 nop
F00C5130: 90100018                 mov     %i0, %o0! id
F00C5134: 133c0506                 sethi   %hi(paSetcharacterma), %o1
F00C5138: d20261e4                 ld      [%o1+%lo(paSetcharacterma)], %o1! SEL
F00C513C: 4000b1cd                 call    _objc_msgSend
F00C5140: 94103fff                 mov     -1, %o2
F00C5144: b0102001                 mov     1, %i0
F00C5148: 81c7e008                 ret
F00C514C: 81e80000                 restore
