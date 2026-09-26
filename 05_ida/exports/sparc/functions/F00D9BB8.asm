F00D9BB8: 9de3bf90                 save    %sp, -0x70, %sp
F00D9BBC: 90100018                 mov     %i0, %o0! id
F00D9BC0: 133c0505                 sethi   %hi(paSubclassrespon), %o1
F00D9BC4: d20260cc                 ld      [%o1+%lo(paSubclassrespon)], %o1! SEL
F00D9BC8: 40005f2a                 call    _objc_msgSend
F00D9BCC: 94100019                 mov     %i1, %o2
F00D9BD0: 81c7e008                 ret
F00D9BD4: 81e80000                 restore
