F0052294: 9de3bf98                 save    %sp, -0x68, %sp
F0052298: e0062030                 ld      [%i0+0x30], %l0
F005229C: 7ffff37b                 call    _ilock
F00522A0: 90100010                 mov     %l0, %o0
F00522A4: 7ffff71a                 call    _syncip
F00522A8: 90100010                 mov     %l0, %o0
F00522AC: 7ffff387                 call    _iunlock
F00522B0: 90100010                 mov     %l0, %o0
F00522B4: 81c7e008                 ret
F00522B8: 91e82000                 restore %g0, 0, %o0
