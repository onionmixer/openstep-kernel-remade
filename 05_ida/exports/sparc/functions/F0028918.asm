F0028918: 9de3bf10                 save    %sp, -0xF0, %sp
F002891C: 7fff9c14                 call    _suser
F0028920: 01000000                 nop
F0028924: 80a22000                 cmp     %o0, 0
F0028928: 02800012                 be      locret_F0028970
F002892C: 233c04cf                 sethi   %hi(_active_u), %l1
F0028930: d20461d8                 ld      [%l1+%lo(_active_u)], %o1
F0028934: d0026164                 ld      [%o1+0x164], %o0
F0028938: 80a22000                 cmp     %o0, 0
F002893C: 0280000d                 be      locret_F0028970
F0028940: 01000000                 nop
F0028944: 4000000d                 call    _forceclose
F0028948: d0526168                 ldsh    [%o1+0x168], %o0
F002894C: a007bf70                 add     %fp, __dst, %l0
F0028950: d20461d8                 ld      [%l1+%lo(_active_u)], %o1
F0028954: 90100010                 mov     %l0, %o0! __dst
F0028958: d2026164                 ld      [%o1+0x164], %o1! __src
F002895C: 7fff7a51                 call    _memcpy
F0028960: 94102088                 mov     0x88, %o2
F0028964: 90100010                 mov     %l0, %o0
F0028968: 7fffa2dd                 call    _gsignal
F002896C: 92102001                 mov     1, %o1
F0028970: 81c7e008                 ret
F0028974: 81e80000                 restore
