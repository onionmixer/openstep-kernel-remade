F00CF140: 9de3bf90                 save    %sp, -0x70, %sp
F00CF144: d006a018                 ld      [%i2+0x18], %o0
F00CF148: 80a22000                 cmp     %o0, 0
F00CF14C: 12800007                 bne     loc_F00CF168
F00CF150: 9010001a                 mov     %i2, %o0
F00CF154: d006a01c                 ld      [%i2+0x1C], %o0! id
F00CF158: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00CF15C: 400089c5                 call    _objc_msgSend
F00CF160: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00CF164: 9010001a                 mov     %i2, %o0
F00CF168: 7fffdb77                 call    _IOFree
F00CF16C: 92102044                 mov     0x44, %o1 ! 'D'
F00CF170: 81c7e008                 ret
F00CF174: 81e80000                 restore
