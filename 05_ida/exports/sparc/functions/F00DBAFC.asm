F00DBAFC: 9de3bf80                 save    %sp, -0x80, %sp
F00DBB00: c027bfec                 clr     [%fp+var_14]
F00DBB04: c027bfe8                 clr     [%fp+var_18]
F00DBB08: c027bfe0                 clr     [%fp+var_20]
F00DBB0C: c027bfe4                 clr     [%fp+var_1C]
F00DBB10: 90100018                 mov     %i0, %o0! id
F00DBB14: 133c0505                 sethi   %hi(paControlAttime), %o1
F00DBB18: d202604c                 ld      [%o1+%lo(paControlAttime)], %o1! SEL
F00DBB1C: 9410001a                 mov     %i2, %o2
F00DBB20: 40005754                 call    _objc_msgSend
F00DBB24: 9607bfe0                 add     %fp, var_20, %o3
F00DBB28: 81c7e008                 ret
F00DBB2C: 91e80008                 restore %g0, %o0, %o0
