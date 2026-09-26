F00EF16C: 9de3bf98                 save    %sp, -0x68, %sp
F00EF170: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00EF174: 90100019                 mov     %i1, %o0! id
F00EF178: 400009be                 call    _objc_msgSend
F00EF17C: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00EF180: 81c7e008                 ret
F00EF184: 81e80000                 restore
