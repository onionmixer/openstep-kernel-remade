F00D046C: 9de3bf90                 save    %sp, -0x70, %sp
F00D0470: d006212c                 ld      [%i0+0x12C], %o0! id
F00D0474: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D0478: 400084fe                 call    _objc_msgSend
F00D047C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D0480: d0062130                 ld      [%i0+0x130], %o0
F00D0484: 80a22000                 cmp     %o0, 0
F00D0488: 22800004                 be,a    loc_F00D0498
F00D048C: f4262130                 st      %i2, [%i0+0x130]
F00D0490: 10800007                 ba      loc_F00D04AC
F00D0494: b4102001                 mov     1, %i2
F00D0498: b4102000                 mov     0, %i2
F00D049C: d206211c                 ld      [%i0+0x11C], %o1
F00D04A0: 11200000                 sethi   0x80000000, %o0
F00D04A4: 902a4008                 andn    %o1, %o0, %o0
F00D04A8: d026211c                 st      %o0, [%i0+0x11C]
F00D04AC: d006212c                 ld      [%i0+0x12C], %o0! id
F00D04B0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D04B4: 400084ef                 call    _objc_msgSend
F00D04B8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D04BC: 81c7e008                 ret
F00D04C0: 91e8001a                 restore %g0, %i2, %o0
