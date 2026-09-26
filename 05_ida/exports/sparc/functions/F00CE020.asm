F00CE020: 9de3bf90                 save    %sp, -0x70, %sp
F00CE024: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CE028: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CE02C: 40008e11                 call    _objc_msgSend
F00CE030: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CE034: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CE038: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CE03C: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CE040: 40008e0c                 call    _objc_msgSend
F00CE044: 94102001                 mov     1, %o2
F00CE048: 81c7e008                 ret
F00CE04C: 81e80000                 restore
