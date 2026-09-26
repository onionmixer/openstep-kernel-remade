F00EB658: 9de3bf90                 save    %sp, -0x70, %sp
F00EB65C: e0062008                 ld      [%i0+8], %l0
F00EB660: a0043fff                 inc     -1, %l0
F00EB664: 80a43fff                 cmp     %l0, -1
F00EB668: 0280000d                 be      locret_F00EB69C
F00EB66C: 233c0504                 sethi   -0xFEBF000, %l1
F00EB670: d2062004                 ld      [%i0+4], %o1
F00EB674: 912c2002                 sll     %l0, 2, %o0
F00EB678: d0024008                 ld      [%o1+%o0], %o0! id
F00EB67C: d204601c                 ld      [%l1+0x1C], %o1! SEL
F00EB680: 9410001a                 mov     %i2, %o2
F00EB684: 4000187b                 call    _objc_msgSend
F00EB688: 9610001b                 mov     %i3, %o3
F00EB68C: a0043fff                 inc     -1, %l0
F00EB690: 80a43fff                 cmp     %l0, -1
F00EB694: 32bffff8                 bne,a   loc_F00EB674
F00EB698: d2062004                 ld      [%i0+4], %o1
F00EB69C: 81c7e008                 ret
F00EB6A0: 81e80000                 restore
