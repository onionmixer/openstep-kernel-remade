F00EAF60: 9de3bf90                 save    %sp, -0x70, %sp
F00EAF64: 133c0506                 sethi   %hi(paPrintfordebugg), %o1
F00EAF68: 90100018                 mov     %i0, %o0! id
F00EAF6C: d2026240                 ld      [%o1+%lo(paPrintfordebugg)], %o1! SEL
F00EAF70: 40001a40                 call    _objc_msgSend
F00EAF74: 9410001a                 mov     %i2, %o2
F00EAF78: 81c7e008                 ret
F00EAF7C: 81e80000                 restore
