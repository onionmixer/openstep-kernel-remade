F00CA818: 9de3bf90                 save    %sp, -0x70, %sp
F00CA81C: e0062004                 ld      [%i0+4], %l0
F00CA820: 7ffd8591                 call    _if_ipackets
F00CA824: 90100010                 mov     %l0, %o0
F00CA828: 92022001                 add     %o0, 1, %o1
F00CA82C: 7ffd85a6                 call    _if_ipackets_set
F00CA830: 90100010                 mov     %l0, %o0
F00CA834: 9210001a                 mov     %i2, %o1
F00CA838: d0062004                 ld      [%i0+4], %o0
F00CA83C: 7ffd865f                 call    _if_handle_input
F00CA840: 9410001b                 mov     %i3, %o2
F00CA844: 81c7e008                 ret
F00CA848: 91e80008                 restore %g0, %o0, %o0
