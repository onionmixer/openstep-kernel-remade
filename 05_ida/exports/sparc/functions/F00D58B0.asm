F00D58B0: 9de3bf90                 save    %sp, -0x70, %sp
F00D58B4: d0062110                 ld      [%i0+0x110], %o0! id
F00D58B8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D58BC: 40006fed                 call    _objc_msgSend
F00D58C0: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D58C4: d006210c                 ld      [%i0+0x10C], %o0
F00D58C8: 80a22000                 cmp     %o0, 0
F00D58CC: 02800006                 be      loc_F00D58E4
F00D58D0: 80a2001a                 cmp     %o0, %i2
F00D58D4: 22800005                 be,a    loc_F00D58E8
F00D58D8: f426210c                 st      %i2, [%i0+0x10C]
F00D58DC: 10800004                 ba      loc_F00D58EC
F00D58E0: b4103d2b                 mov     -0x2D5, %i2
F00D58E4: f426210c                 st      %i2, [%i0+0x10C]
F00D58E8: b4102000                 mov     0, %i2
F00D58EC: d0062110                 ld      [%i0+0x110], %o0! id
F00D58F0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D58F4: 40006fdf                 call    _objc_msgSend
F00D58F8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D58FC: 81c7e008                 ret
F00D5900: 91e8001a                 restore %g0, %i2, %o0
