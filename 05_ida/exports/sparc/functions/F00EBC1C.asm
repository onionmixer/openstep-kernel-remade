F00EBC1C: 9de3bf90                 save    %sp, -0x70, %sp
F00EBC20: f627a050                 st      %i3, [%fp+arg_50]
F00EBC24: f827a054                 st      %i4, [%fp+arg_54]
F00EBC28: fa27a058                 st      %i5, [%fp+arg_58]
F00EBC2C: a007a050                 add     %fp, arg_50, %l0
F00EBC30: 113c04bc                 sethi   %hi(__error), %o0
F00EBC34: d6022100                 ld      [%o0+%lo(__error)], %o3
F00EBC38: 90100018                 mov     %i0, %o0
F00EBC3C: 9210001a                 mov     %i2, %o1
F00EBC40: 9fc2c000                 call    %o3
F00EBC44: 94100010                 mov     %l0, %o2
F00EBC48: 90100018                 mov     %i0, %o0
F00EBC4C: 9210001a                 mov     %i2, %o1
F00EBC50: 40001354                 call    __objc_error
F00EBC54: 94100010                 mov     %l0, %o2
F00EBC58: 81c7e008                 ret
F00EBC5C: 91e82000                 restore %g0, 0, %o0
