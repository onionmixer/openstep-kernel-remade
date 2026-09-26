F00CA998: 9de3bf90                 save    %sp, -0x70, %sp
F00CA99C: e0062004                 ld      [%i0+4], %l0
F00CA9A0: 7ffd8535                 call    _if_oerrors
F00CA9A4: 90100010                 mov     %l0, %o0
F00CA9A8: 9202001a                 add     %o0, %i2, %o1
F00CA9AC: 7ffd854a                 call    _if_oerrors_set
F00CA9B0: 90100010                 mov     %l0, %o0
F00CA9B4: 81c7e008                 ret
F00CA9B8: 81e80000                 restore
