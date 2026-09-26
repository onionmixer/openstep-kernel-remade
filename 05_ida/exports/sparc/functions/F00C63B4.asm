F00C63B4: 9de3bf90                 save    %sp, -0x70, %sp
F00C63B8: 7ffd0420                 call    _strlen
F00C63BC: 9010001a                 mov     %i2, %o0
F00C63C0: 94100008                 mov     %o0, %o2
F00C63C4: 80a2a017                 cmp     %o2, 0x17
F00C63C8: 34800002                 bg,a    loc_F00C63D0
F00C63CC: 94102017                 mov     0x17, %o2! __n
F00C63D0: 90062120                 add     %i0, 0x120, %o0! __dst
F00C63D4: 7ffd0552                 call    _strncpy
F00C63D8: 9210001a                 mov     %i2, %o1
F00C63DC: c02e2137                 clrb    [%i0+0x137]
F00C63E0: 81c7e008                 ret
F00C63E4: 81e80000                 restore
