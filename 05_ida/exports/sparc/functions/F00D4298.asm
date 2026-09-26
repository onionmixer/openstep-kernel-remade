F00D4298: 9de3bf90                 save    %sp, -0x70, %sp
F00D429C: 133c0505                 sethi   %hi(paEvdispatchComm), %o1
F00D42A0: d2026290                 ld      [%o1+%lo(paEvdispatchComm)], %o1! SEL
F00D42A4: 90100018                 mov     %i0, %o0! id
F00D42A8: d402218c                 ld      [%o0+0x18C], %o2
F00D42AC: 40007571                 call    _objc_msgSend
F00D42B0: 96102002                 mov     2, %o3
F00D42B4: 81c7e008                 ret
F00D42B8: 91e80008                 restore %g0, %o0, %o0
