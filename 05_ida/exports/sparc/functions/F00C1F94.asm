F00C1F94: 9de3bf90                 save    %sp, -0x70, %sp
F00C1F98: d0062148                 ld      [%i0+0x148], %o0! id
F00C1F9C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C1FA0: 4000be34                 call    _objc_msgSend
F00C1FA4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C1FA8: d0062144                 ld      [%i0+0x144], %o0
F00C1FAC: 80a22000                 cmp     %o0, 0
F00C1FB0: 02800006                 be      loc_F00C1FC8
F00C1FB4: 80a2001a                 cmp     %o0, %i2
F00C1FB8: 22800005                 be,a    loc_F00C1FCC
F00C1FBC: f4262144                 st      %i2, [%i0+0x144]
F00C1FC0: 10800004                 ba      loc_F00C1FD0
F00C1FC4: b4103d2b                 mov     -0x2D5, %i2
F00C1FC8: f4262144                 st      %i2, [%i0+0x144]
F00C1FCC: b4102000                 mov     0, %i2
F00C1FD0: d0062148                 ld      [%i0+0x148], %o0! id
F00C1FD4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C1FD8: 4000be26                 call    _objc_msgSend
F00C1FDC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C1FE0: 81c7e008                 ret
F00C1FE4: 91e8001a                 restore %g0, %i2, %o0
