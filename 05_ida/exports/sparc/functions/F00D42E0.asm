F00D42E0: 9de3bf90                 save    %sp, -0x70, %sp
F00D42E4: 133c0505                 sethi   %hi(paEvdispatchComm), %o1
F00D42E8: d2026290                 ld      [%o1+%lo(paEvdispatchComm)], %o1! SEL
F00D42EC: 90100018                 mov     %i0, %o0! id
F00D42F0: d402218c                 ld      [%o0+0x18C], %o2
F00D42F4: 4000755f                 call    _objc_msgSend
F00D42F8: 96102003                 mov     3, %o3
F00D42FC: 81c7e008                 ret
F00D4300: 91e80008                 restore %g0, %o0, %o0
