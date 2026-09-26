F00D5638: 9de3bf90                 save    %sp, -0x70, %sp
F00D563C: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D5640: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D5644: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D5648: 4000708a                 call    _objc_msgSend
F00D564C: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D5650: 133c0505                 sethi   %hi(paRegisterevents), %o1
F00D5654: d2026288                 ld      [%o1+%lo(paRegisterevents)], %o1! SEL
F00D5658: 40007086                 call    _objc_msgSend
F00D565C: 9410001a                 mov     %i2, %o2
F00D5660: 81c7e008                 ret
F00D5664: 91e80008                 restore %g0, %o0, %o0
