F00CA974: 9de3bf90                 save    %sp, -0x70, %sp
F00CA978: e0062004                 ld      [%i0+4], %l0
F00CA97C: 7ffd853e                 call    _if_oerrors
F00CA980: 90100010                 mov     %l0, %o0
F00CA984: 92022001                 add     %o0, 1, %o1
F00CA988: 7ffd8553                 call    _if_oerrors_set
F00CA98C: 90100010                 mov     %l0, %o0
F00CA990: 81c7e008                 ret
F00CA994: 81e80000                 restore
