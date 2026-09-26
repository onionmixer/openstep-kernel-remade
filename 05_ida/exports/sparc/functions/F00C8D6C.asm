F00C8D6C: 9de3bf90                 save    %sp, -0x70, %sp
F00C8D70: 113c0506                 sethi   %hi(paInterruptlist_0), %o0! id
F00C8D74: d202211c                 ld      [%o0+%lo(paInterruptlist_0)], %o1! SEL
F00C8D78: 4000a2be                 call    _objc_msgSend
F00C8D7C: 90100018                 mov     %i0, %o0
F00C8D80: f0020000                 ld      [%o0], %i0
F00C8D84: 81c7e008                 ret
F00C8D88: 81e80000                 restore
