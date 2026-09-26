F00C9388: 9de3bf90                 save    %sp, -0x70, %sp
F00C938C: 113c0503                 sethi   %hi(paFree), %o0! id
F00C9390: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C9394: 4000a137                 call    _objc_msgSend
F00C9398: 90100018                 mov     %i0, %o0
F00C939C: 81c7e008                 ret
F00C93A0: 91e80008                 restore %g0, %o0, %o0
