F00EBD60: 9de3bf90                 save    %sp, -0x70, %sp
F00EBD64: 133c0504                 sethi   %hi(paConformsto), %o1
F00EBD68: d0060000                 ld      [%i0], %o0! id
F00EBD6C: d2026018                 ld      [%o1+%lo(paConformsto)], %o1! SEL
F00EBD70: 400016c0                 call    _objc_msgSend
F00EBD74: 9410001a                 mov     %i2, %o2
F00EBD78: 912a2018                 sll     %o0, 24, %o0
F00EBD7C: b13a2018                 sra     %o0, 24, %i0
F00EBD80: 81c7e008                 ret
F00EBD84: 81e80000                 restore
