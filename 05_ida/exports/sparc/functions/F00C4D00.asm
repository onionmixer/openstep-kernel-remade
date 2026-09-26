F00C4D00: 9de3bf90                 save    %sp, -0x70, %sp
F00C4D04: 7ffd09cd                 call    _strlen
F00C4D08: 9010001a                 mov     %i2, %o0
F00C4D0C: a0100008                 mov     %o0, %l0
F00C4D10: 80a4204f                 cmp     %l0, 0x4F ! 'O'
F00C4D14: 34800002                 bg,a    loc_F00C4D1C
F00C4D18: a010204f                 mov     0x4F, %l0 ! 'O'
F00C4D1C: 900620a8                 add     %i0, 0xA8, %o0! __dst
F00C4D20: 9210001a                 mov     %i2, %o1! __src
F00C4D24: 7ffd0afe                 call    _strncpy
F00C4D28: 94100010                 mov     %l0, %o2
F00C4D2C: 90060010                 add     %i0, %l0, %o0
F00C4D30: c02a20a8                 clrb    [%o0+0xA8]
F00C4D34: 81c7e008                 ret
F00C4D38: 81e80000                 restore
