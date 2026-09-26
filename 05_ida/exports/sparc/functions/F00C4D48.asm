F00C4D48: 9de3bf90                 save    %sp, -0x70, %sp
F00C4D4C: 80a6a000                 cmp     %i2, 0
F00C4D50: 12800004                 bne     loc_F00C4D60
F00C4D54: 01000000                 nop
F00C4D58: 1080000e                 ba      locret_F00C4D90
F00C4D5C: c02e2058                 clrb    [%i0+0x58]
F00C4D60: 7ffd09b6                 call    _strlen
F00C4D64: 9010001a                 mov     %i2, %o0
F00C4D68: a0100008                 mov     %o0, %l0
F00C4D6C: 80a4204f                 cmp     %l0, 0x4F ! 'O'
F00C4D70: 34800002                 bg,a    loc_F00C4D78
F00C4D74: a010204f                 mov     0x4F, %l0 ! 'O'
F00C4D78: 90062058                 add     %i0, 0x58, %o0 ! 'X'! __dst
F00C4D7C: 9210001a                 mov     %i2, %o1! __src
F00C4D80: 7ffd0ae7                 call    _strncpy
F00C4D84: 94100010                 mov     %l0, %o2
F00C4D88: 90060010                 add     %i0, %l0, %o0
F00C4D8C: c02a2058                 clrb    [%o0+0x58]
F00C4D90: 81c7e008                 ret
F00C4D94: 81e80000                 restore
