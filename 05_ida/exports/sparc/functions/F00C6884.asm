F00C6884: 9de3bf90                 save    %sp, -0x70, %sp
F00C6888: d006211c                 ld      [%i0+0x11C], %o0! id
F00C688C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C6890: 4000abf8                 call    _objc_msgSend
F00C6894: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C6898: 81c7e008                 ret
F00C689C: 81e80000                 restore
