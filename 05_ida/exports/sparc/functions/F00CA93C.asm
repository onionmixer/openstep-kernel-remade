F00CA93C: 9de3bf90                 save    %sp, -0x70, %sp
F00CA940: e0062004                 ld      [%i0+4], %l0
F00CA944: 7ffd8544                 call    _if_opackets
F00CA948: 90100010                 mov     %l0, %o0
F00CA94C: 9202001a                 add     %o0, %i2, %o1
F00CA950: 7ffd8559                 call    _if_opackets_set
F00CA954: 90100010                 mov     %l0, %o0
F00CA958: 81c7e008                 ret
F00CA95C: 81e80000                 restore
