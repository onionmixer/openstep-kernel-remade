F00BDF1C: 9de3bf90                 save    %sp, -0x70, %sp
F00BDF20: d2062024                 ld      [%i0+0x24], %o1
F00BDF24: 912a6001                 sll     %o1, 1, %o0
F00BDF28: 90020009                 add     %o0, %o1, %o0
F00BDF2C: d2062010                 ld      [%i0+0x10], %o1
F00BDF30: 912a2002                 sll     %o0, 2, %o0
F00BDF34: 92024008                 add     %o1, %o0, %o1
F00BDF38: d237bff2                 sth     %o1, [%fp+var_E]
F00BDF3C: d4062028                 ld      [%i0+0x28], %o2
F00BDF40: 90102000                 mov     0, %o0
F00BDF44: d206200c                 ld      [%i0+0xC], %o1
F00BDF48: 952aa003                 sll     %o2, 3, %o2
F00BDF4C: 9202400a                 add     %o1, %o2, %o1
F00BDF50: d237bff0                 sth     %o1, [%fp+var_10]
F00BDF54: 92102008                 mov     8, %o1
F00BDF58: d237bff4                 sth     %o1, [%fp+var_C]
F00BDF5C: 9210200c                 mov     0xC, %o1
F00BDF60: d237bff6                 sth     %o1, [%fp+var_A]
F00BDF64: 4000a0be                 call    _sparcfbInvertRect
F00BDF68: 9207bff0                 add     %fp, var_10, %o1
F00BDF6C: 81c7e008                 ret
F00BDF70: 81e80000                 restore
