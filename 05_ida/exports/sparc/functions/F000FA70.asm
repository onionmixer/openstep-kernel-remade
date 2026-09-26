F000FA70: 9de3bf98                 save    %sp, -0x68, %sp
F000FA74: 7fffffda                 call    _crget
F000FA78: a0100018                 mov     %i0, %l0
F000FA7C: b0100008                 mov     %o0, %i0
F000FA80: 92100010                 mov     %l0, %o1! __src
F000FA84: 7fffde07                 call    _memcpy
F000FA88: 9410202a                 mov     0x2A, %o2 ! '*'
F000FA8C: 7fffffe3                 call    _crfree
F000FA90: 90100010                 mov     %l0, %o0
F000FA94: 90102001                 mov     1, %o0
F000FA98: d0360000                 sth     %o0, [%i0]
F000FA9C: 81c7e008                 ret
F000FAA0: 81e80000                 restore
