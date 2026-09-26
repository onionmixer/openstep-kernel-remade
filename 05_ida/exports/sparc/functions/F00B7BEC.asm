F00B7BEC: 9de3bf40                 save    %sp, -0xC0, %sp
F00B7BF0: d40e2030                 ldub    [%i0+0x30], %o2
F00B7BF4: ec07a05c                 ld      [%fp+arg_5C], %l6
F00B7BF8: e81fa060                 ldd     [%fp+arg_60], %l4
F00B7BFC: a007bfb8                 add     %fp, __s, %l0
F00B7C00: e607a068                 ld      [%fp+arg_68], %l3
F00B7C04: 90100010                 mov     %l0, %o0! __s
F00B7C08: e407a06c                 ld      [%fp+arg_6C], %l2
F00B7C0C: 133c047b                 sethi   %hi(aEspD), %o1! "esp%d: "
F00B7C10: e207a070                 ld      [%fp+arg_70], %l1
F00B7C14: 7ffd72d5                 call    _sprintf
F00B7C18: 921260b0                 bset    %lo(aEspD), %o1! "esp%d: "
F00B7C1C: 7ffd3e07                 call    _strlen
F00B7C20: 90100010                 mov     %l0, %o0
F00B7C24: e823a05c                 st      %l4, [%sp+0xC0+var_64]
F00B7C28: ea23a060                 st      %l5, [%sp+0xC0+var_60]
F00B7C2C: e623a064                 st      %l3, [%sp+0xC0+var_5C]
F00B7C30: e423a068                 st      %l2, [%sp+0xC0+var_58]
F00B7C34: e223a06c                 st      %l1, [%sp+0xC0+var_54]
F00B7C38: 90040008                 add     %l0, %o0, %o0! __s
F00B7C3C: 9210001a                 mov     %i2, %o1! char *
F00B7C40: 9410001b                 mov     %i3, %o2
F00B7C44: 9610001c                 mov     %i4, %o3
F00B7C48: 9810001d                 mov     %i5, %o4
F00B7C4C: 7ffd72c7                 call    _sprintf
F00B7C50: 9a100016                 mov     %l6, %o5
F00B7C54: 7ffd3df9                 call    _strlen
F00B7C58: 90100010                 mov     %l0, %o0
F00B7C5C: 9407bff8                 add     %fp, var_8, %o2
F00B7C60: 96028008                 add     %o2, %o0, %o3
F00B7C64: 9210200a                 mov     0xA, %o1
F00B7C68: d22affc0                 stb     %o1, [%o3-0x40]
F00B7C6C: 90022001                 inc     %o0
F00B7C70: 94028008                 add     %o2, %o0, %o2
F00B7C74: c02abfc0                 clrb    [%o2-0x40]
F00B7C78: 90100019                 mov     %i1, %o0! __x
F00B7C7C: 7ffd72ce                 call    _log
F00B7C80: 92100010                 mov     %l0, %o1
F00B7C84: 81c7e008                 ret
F00B7C88: 81e80000                 restore
