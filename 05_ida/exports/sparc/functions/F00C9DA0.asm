F00C9DA0: 9de3bf90                 save    %sp, -0x70, %sp
F00C9DA4: 90100018                 mov     %i0, %o0! id
F00C9DA8: 133c0503                 sethi   %hi(paInitwith), %o1
F00C9DAC: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F00C9DB0: 40009eb0                 call    _objc_msgSend
F00C9DB4: 94102000                 mov     0, %o2
F00C9DB8: 81c7e008                 ret
F00C9DBC: 91e80008                 restore %g0, %o0, %o0
