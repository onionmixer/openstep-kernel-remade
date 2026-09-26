F00C68A0: 9de3bf90                 save    %sp, -0x70, %sp
F00C68A4: d006211c                 ld      [%i0+0x11C], %o0! id
F00C68A8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C68AC: 4000abf1                 call    _objc_msgSend
F00C68B0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C68B4: 81c7e008                 ret
F00C68B8: 81e80000                 restore
