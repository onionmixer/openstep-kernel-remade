F00CA9F4: 9de3bf90                 save    %sp, -0x70, %sp
F00CA9F8: e0062004                 ld      [%i0+4], %l0
F00CA9FC: 7ffd8526                 call    _if_collisions
F00CAA00: 90100010                 mov     %l0, %o0
F00CAA04: 9202001a                 add     %o0, %i2, %o1
F00CAA08: 7ffd853b                 call    _if_collisions_set
F00CAA0C: 90100010                 mov     %l0, %o0
F00CAA10: 81c7e008                 ret
F00CAA14: 81e80000                 restore
