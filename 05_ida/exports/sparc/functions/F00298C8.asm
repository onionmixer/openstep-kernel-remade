F00298C8: 9de3bf98                 save    %sp, -0x68, %sp
F00298CC: 113c04d0                 sethi   %hi(_ifnet), %o0
F00298D0: e00220b8                 ld      [%o0+%lo(_ifnet)], %l0
F00298D4: 80a42000                 cmp     %l0, 0
F00298D8: 02800026                 be      loc_F0029970
F00298DC: a4100018                 mov     %i0, %l2
F00298E0: a204a002                 add     %l2, 2, %l1
F00298E4: f0042018                 ld      [%l0+0x18], %i0
F00298E8: 80a62000                 cmp     %i0, 0
F00298EC: 2280001e                 be,a    loc_F0029964
F00298F0: e004205c                 ld      [%l0+0x5C], %l0
F00298F4: d2160000                 lduh    [%i0], %o1
F00298F8: d0148000                 lduh    [%l2], %o0
F00298FC: 80a24008                 cmp     %o1, %o0
F0029900: 32800015                 bne,a   loc_F0029954
F0029904: f0062024                 ld      [%i0+0x24], %i0
F0029908: 90062002                 add     %i0, 2, %o0! void *
F002990C: 92100011                 mov     %l1, %o1! void *
F0029910: 7fff7193                 call    _bcmp
F0029914: 9410200e                 mov     0xE, %o2! size_t
F0029918: 80a22000                 cmp     %o0, 0
F002991C: 02800016                 be      locret_F0029974
F0029920: 01000000                 nop
F0029924: d014200c                 lduh    [%l0+0xC], %o0
F0029928: 808a2002                 btst    2, %o0
F002992C: 2280000a                 be,a    loc_F0029954
F0029930: f0062024                 ld      [%i0+0x24], %i0
F0029934: 90062012                 add     %i0, 0x12, %o0! void *
F0029938: 92100011                 mov     %l1, %o1! void *
F002993C: 7fff7188                 call    _bcmp
F0029940: 9410200e                 mov     0xE, %o2
F0029944: 80a22000                 cmp     %o0, 0
F0029948: 0280000b                 be      locret_F0029974
F002994C: 01000000                 nop
F0029950: f0062024                 ld      [%i0+0x24], %i0
F0029954: 80a62000                 cmp     %i0, 0
F0029958: 32bfffe8                 bne,a   loc_F00298F8
F002995C: d2160000                 lduh    [%i0], %o1
F0029960: e004205c                 ld      [%l0+0x5C], %l0
F0029964: 80a42000                 cmp     %l0, 0
F0029968: 32bfffe0                 bne,a   loc_F00298E8
F002996C: f0042018                 ld      [%l0+0x18], %i0
F0029970: b0102000                 mov     0, %i0
F0029974: 81c7e008                 ret
F0029978: 81e80000                 restore
