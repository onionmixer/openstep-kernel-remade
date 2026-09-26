F00EA59C: 9de3bf90                 save    %sp, -0x70, %sp
F00EA5A0: 133c0506                 sethi   %hi(paNewkeydescValu), %o1
F00EA5A4: 90100018                 mov     %i0, %o0! id
F00EA5A8: d202624c                 ld      [%o1+%lo(paNewkeydescValu)], %o1! SEL
F00EA5AC: 9410001a                 mov     %i2, %o2
F00EA5B0: 40001cb0                 call    _objc_msgSend
F00EA5B4: 96102000                 mov     0, %o3
F00EA5B8: 81c7e008                 ret
F00EA5BC: 91e80008                 restore %g0, %o0, %o0
