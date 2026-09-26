F00BF770: 9de3bf90                 save    %sp, -0x70, %sp
F00BF774: 113c0504                 sethi   %hi(paOwnerlock), %o0! id
F00BF778: d20222b0                 ld      [%o0+%lo(paOwnerlock)], %o1! SEL
F00BF77C: 4000c83d                 call    _objc_msgSend
F00BF780: 90100018                 mov     %i0, %o0! id
F00BF784: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BF788: 4000c83a                 call    _objc_msgSend
F00BF78C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BF790: 113c0504                 sethi   %hi(paOwner_0), %o0! id
F00BF794: d2022298                 ld      [%o0+%lo(paOwner_0)], %o1! SEL
F00BF798: 4000c836                 call    _objc_msgSend
F00BF79C: 90100018                 mov     %i0, %o0
F00BF7A0: 80a22000                 cmp     %o0, 0
F00BF7A4: 12800004                 bne     loc_F00BF7B4
F00BF7A8: a0103d2b                 mov     -0x2D5, %l0
F00BF7AC: c02e2130                 clrb    [%i0+0x130]
F00BF7B0: a0102000                 mov     0, %l0
F00BF7B4: 113c0504                 sethi   %hi(paOwnerlock), %o0! id
F00BF7B8: d20222b0                 ld      [%o0+%lo(paOwnerlock)], %o1! SEL
F00BF7BC: 4000c82d                 call    _objc_msgSend
F00BF7C0: 90100018                 mov     %i0, %o0! id
F00BF7C4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BF7C8: 4000c82a                 call    _objc_msgSend
F00BF7CC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BF7D0: 81c7e008                 ret
F00BF7D4: 91e80010                 restore %g0, %l0, %o0
