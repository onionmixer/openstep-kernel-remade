F00CA8E0: 9de3bf90                 save    %sp, -0x70, %sp
F00CA8E4: e0062004                 ld      [%i0+4], %l0
F00CA8E8: 7ffd8567                 call    _if_ierrors
F00CA8EC: 90100010                 mov     %l0, %o0
F00CA8F0: 9202001a                 add     %o0, %i2, %o1
F00CA8F4: 7ffd857c                 call    _if_ierrors_set
F00CA8F8: 90100010                 mov     %l0, %o0
F00CA8FC: 81c7e008                 ret
F00CA900: 81e80000                 restore
