F00EB39C: 9de3bf90                 save    %sp, -0x70, %sp
F00EB3A0: 133c0506                 sethi   %hi(paInsertobjectAt), %o1
F00EB3A4: 90100018                 mov     %i0, %o0! id
F00EB3A8: d2026234                 ld      [%o1+%lo(paInsertobjectAt)], %o1! SEL
F00EB3AC: 9410001a                 mov     %i2, %o2
F00EB3B0: 40001930                 call    _objc_msgSend
F00EB3B4: d6062008                 ld      [%i0+8], %o3
F00EB3B8: 81c7e008                 ret
F00EB3BC: 91e80008                 restore %g0, %o0, %o0
