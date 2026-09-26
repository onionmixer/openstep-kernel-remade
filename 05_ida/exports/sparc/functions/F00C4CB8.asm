F00C4CB8: 9de3bf90                 save    %sp, -0x70, %sp
F00C4CBC: 7ffd09df                 call    _strlen
F00C4CC0: 9010001a                 mov     %i2, %o0
F00C4CC4: a0100008                 mov     %o0, %l0
F00C4CC8: 80a4204f                 cmp     %l0, 0x4F ! 'O'
F00C4CCC: 34800002                 bg,a    loc_F00C4CD4
F00C4CD0: a010204f                 mov     0x4F, %l0 ! 'O'
F00C4CD4: 90062008                 add     %i0, 8, %o0! __dst
F00C4CD8: 9210001a                 mov     %i2, %o1! __src
F00C4CDC: 7ffd0b10                 call    _strncpy
F00C4CE0: 94100010                 mov     %l0, %o2
F00C4CE4: 90060010                 add     %i0, %l0, %o0
F00C4CE8: c02a2008                 clrb    [%o0+8]
F00C4CEC: 81c7e008                 ret
F00C4CF0: 81e80000                 restore
