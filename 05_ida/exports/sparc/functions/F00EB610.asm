F00EB610: 9de3bf90                 save    %sp, -0x70, %sp
F00EB614: e0062008                 ld      [%i0+8], %l0
F00EB618: a0043fff                 inc     -1, %l0
F00EB61C: 80a43fff                 cmp     %l0, -1
F00EB620: 0280000c                 be      locret_F00EB650
F00EB624: 233c0506                 sethi   -0xFEBE800, %l1
F00EB628: d2062004                 ld      [%i0+4], %o1
F00EB62C: 912c2002                 sll     %l0, 2, %o0
F00EB630: d0024008                 ld      [%o1+%o0], %o0! id
F00EB634: d20461d4                 ld      [%l1+0x1D4], %o1! SEL
F00EB638: 4000188e                 call    _objc_msgSend
F00EB63C: 9410001a                 mov     %i2, %o2
F00EB640: a0043fff                 inc     -1, %l0
F00EB644: 80a43fff                 cmp     %l0, -1
F00EB648: 32bffff9                 bne,a   loc_F00EB62C
F00EB64C: d2062004                 ld      [%i0+4], %o1
F00EB650: 81c7e008                 ret
F00EB654: 81e80000                 restore
