F00C545C: 9de3bf90                 save    %sp, -0x70, %sp
F00C5460: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00C5464: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00C5468: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00C546C: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00C5470: 4000b100                 call    _objc_msgSend
F00C5474: 9410001a                 mov     %i2, %o2
F00C5478: 81c7e008                 ret
F00C547C: 91e80008                 restore %g0, %o0, %o0
