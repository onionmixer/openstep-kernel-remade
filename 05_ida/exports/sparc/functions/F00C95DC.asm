F00C95DC: 9de3bf90                 save    %sp, -0x70, %sp
F00C95E0: d0062110                 ld      [%i0+0x110], %o0
F00C95E4: 80a22000                 cmp     %o0, 0
F00C95E8: 12800011                 bne     locret_F00C962C
F00C95EC: a0102000                 mov     0, %l0
F00C95F0: 113c0506                 sethi   %hi(paAttachinterrup_0), %o0! id
F00C95F4: d20220e8                 ld      [%o0+%lo(paAttachinterrup_0)], %o1! SEL
F00C95F8: 4000a09e                 call    _objc_msgSend
F00C95FC: 90100018                 mov     %i0, %o0
F00C9600: a0920000                 orcc    %o0, %g0, %l0
F00C9604: 1280000a                 bne     locret_F00C962C
F00C9608: 113c0324                 sethi   %hi(sub_F00C91B4), %o0
F00C960C: 901221b4                 bset    %lo(sub_F00C91B4), %o0
F00C9610: 400002ac                 call    _IOForkThread
F00C9614: 92100018                 mov     %i0, %o1
F00C9618: 80a6a000                 cmp     %i2, 0
F00C961C: 06800004                 bl      locret_F00C962C
F00C9620: d0262110                 st      %o0, [%i0+0x110]
F00C9624: 400002d2                 call    _IOSetThreadPriority
F00C9628: 9210001a                 mov     %i2, %o1
F00C962C: 81c7e008                 ret
F00C9630: 91e80010                 restore %g0, %l0, %o0
