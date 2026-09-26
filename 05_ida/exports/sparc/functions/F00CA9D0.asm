F00CA9D0: 9de3bf90                 save    %sp, -0x70, %sp
F00CA9D4: e0062004                 ld      [%i0+4], %l0
F00CA9D8: 7ffd852f                 call    _if_collisions
F00CA9DC: 90100010                 mov     %l0, %o0
F00CA9E0: 92022001                 add     %o0, 1, %o1
F00CA9E4: 7ffd8544                 call    _if_collisions_set
F00CA9E8: 90100010                 mov     %l0, %o0
F00CA9EC: 81c7e008                 ret
F00CA9F0: 81e80000                 restore
