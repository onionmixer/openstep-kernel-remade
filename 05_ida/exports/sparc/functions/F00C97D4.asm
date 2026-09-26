F00C97D4: 9de3bf90                 save    %sp, -0x70, %sp
F00C97D8: 133c0506                 sethi   %hi(paInterruptoccur), %o1
F00C97DC: 90100018                 mov     %i0, %o0! id
F00C97E0: d20260e0                 ld      [%o1+%lo(paInterruptoccur)], %o1! SEL
F00C97E4: 4000a023                 call    _objc_msgSend
F00C97E8: 94102000                 mov     0, %o2
F00C97EC: 81c7e008                 ret
F00C97F0: 81e80000                 restore
