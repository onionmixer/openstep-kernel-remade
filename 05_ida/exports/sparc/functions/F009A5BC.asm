F009A5BC: 9de3bf98                 save    %sp, -0x68, %sp
F009A5C0: 7ffff1cf                 call    _splvm
F009A5C4: 01000000                 nop
F009A5C8: a0100008                 mov     %o0, %l0
F009A5CC: 153c04c59412a13c         set     dword_F013153C, %o2
F009A5D4: d202a010                 ld      [%o2+0x10], %o1
F009A5D8: 90102000                 mov     0, %o0
F009A5DC: 92026001                 inc     %o1
F009A5E0: 7fffffbd                 call    sub_F009A4D4
F009A5E4: d222a010                 st      %o1, [%o2+0x10]
F009A5E8: 7ffff1cf                 call    _splx
F009A5EC: 90100010                 mov     %l0, %o0
F009A5F0: 81c7e008                 ret
F009A5F4: 81e80000                 restore
