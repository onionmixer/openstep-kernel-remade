F00D42BC: 9de3bf90                 save    %sp, -0x70, %sp
F00D42C0: 133c0505                 sethi   %hi(paEvdispatchComm), %o1
F00D42C4: d2026290                 ld      [%o1+%lo(paEvdispatchComm)], %o1! SEL
F00D42C8: 90100018                 mov     %i0, %o0! id
F00D42CC: d402218c                 ld      [%o0+0x18C], %o2
F00D42D0: 40007568                 call    _objc_msgSend
F00D42D4: 96102001                 mov     1, %o3
F00D42D8: 81c7e008                 ret
F00D42DC: 91e80008                 restore %g0, %o0, %o0
