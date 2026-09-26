F00EAF80: 9de3bf90                 save    %sp, -0x70, %sp
F00EAF84: 133c0506                 sethi   %hi(paSetversion), %o1
F00EAF88: 90100018                 mov     %i0, %o0! id
F00EAF8C: d2026264                 ld      [%o1+%lo(paSetversion)], %o1! SEL
F00EAF90: 40001a38                 call    _objc_msgSend
F00EAF94: 94102001                 mov     1, %o2
F00EAF98: 81c7e008                 ret
F00EAF9C: 81e80000                 restore
