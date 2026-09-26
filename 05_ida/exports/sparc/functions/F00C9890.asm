F00C9890: 9de3bf90                 save    %sp, -0x70, %sp
F00C9894: d0062108                 ld      [%i0+0x108], %o0! id
F00C9898: 133c0506                 sethi   %hi(paNuminterrupts), %o1
F00C989C: d20260dc                 ld      [%o1+%lo(paNuminterrupts)], %o1! SEL
F00C98A0: 40009ff4                 call    _objc_msgSend
F00C98A4: a0102000                 mov     0, %l0
F00C98A8: a2100008                 mov     %o0, %l1
F00C98AC: 80a40011                 cmp     %l0, %l1
F00C98B0: 1a80000a                 bcc     locret_F00C98D8
F00C98B4: 253c0506                 sethi   -0xFEBE800, %l2
F00C98B8: 90100018                 mov     %i0, %o0! id
F00C98BC: d204a0d0                 ld      [%l2+0xD0], %o1! SEL
F00C98C0: 94100010                 mov     %l0, %o2
F00C98C4: 40009feb                 call    _objc_msgSend
F00C98C8: a0042001                 inc     %l0
F00C98CC: 80a40011                 cmp     %l0, %l1
F00C98D0: 0abffffb                 bcs     loc_F00C98BC
F00C98D4: 90100018                 mov     %i0, %o0
F00C98D8: 81c7e008                 ret
F00C98DC: 81e80000                 restore
