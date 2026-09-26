F002C5D4: 9de3bf98                 save    %sp, -0x68, %sp
F002C5D8: 113c04d0                 sethi   %hi(_ifnet), %o0
F002C5DC: d00220b8                 ld      [%o0+%lo(_ifnet)], %o0
F002C5E0: d2066004                 ld      [%i1+4], %o1! void *
F002C5E4: 80a22000                 cmp     %o0, 0
F002C5E8: 02800012                 be      loc_F002C630
F002C5EC: a2064009                 add     %i1, %o1, %l1
F002C5F0: f2164009                 lduh    [%i1+%o1], %i1
F002C5F4: 80a66003                 cmp     %i1, 3
F002C5F8: 34800018                 bg,a    locret_F002C658
F002C5FC: b010202f                 mov     0x2F, %i0 ! '/'
F002C600: 80a66002                 cmp     %i1, 2
F002C604: 26800015                 bl,a    locret_F002C658
F002C608: b010202f                 mov     0x2F, %i0 ! '/'
F002C60C: d0046004                 ld      [%l1+4], %o0
F002C610: 80a22000                 cmp     %o0, 0
F002C614: 02800009                 be      loc_F002C638
F002C618: 90100011                 mov     %l1, %o0
F002C61C: 7ffff4ab                 call    _ifa_ifwithaddr
F002C620: 90100011                 mov     %l1, %o0
F002C624: 80a22000                 cmp     %o0, 0
F002C628: 12800004                 bne     loc_F002C638
F002C62C: 90100011                 mov     %l1, %o0! void *
F002C630: 1080000a                 ba      locret_F002C658
F002C634: b0102031                 mov     0x31, %i0 ! '1'
F002C638: e0062008                 ld      [%i0+8], %l0
F002C63C: 94102010                 mov     0x10, %o2! size_t
F002C640: 4001a134                 call    _bcopy
F002C644: 9204201c                 add     %l0, 0x1C, %o1
F002C648: d014204c                 lduh    [%l0+0x4C], %o0
F002C64C: b0102000                 mov     0, %i0
F002C650: 90122001                 bset    1, %o0
F002C654: d034204c                 sth     %o0, [%l0+0x4C]
F002C658: 81c7e008                 ret
F002C65C: 81e80000                 restore
