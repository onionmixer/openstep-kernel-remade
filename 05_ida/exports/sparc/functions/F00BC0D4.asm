F00BC0D4: 9de3bec0                 save    %sp, -0x140, %sp
F00BC0D8: d807a064                 ld      [%fp+arg_64], %o4
F00BC0DC: da07a068                 ld      [%fp+arg_68], %o5
F00BC0E0: a007bf30                 add     %fp, var_D0, %l0
F00BC0E4: d607a06c                 ld      [%fp+arg_6C], %o3
F00BC0E8: 90100010                 mov     %l0, %o0! char *
F00BC0EC: d407a070                 ld      [%fp+arg_70], %o2
F00BC0F0: 9210001b                 mov     %i3, %o1! char *
F00BC0F4: d823a05c                 st      %o4, [%sp+0x140+var_E4]
F00BC0F8: da23a060                 st      %o5, [%sp+0x140+var_E0]
F00BC0FC: d623a064                 st      %o3, [%sp+0x140+var_DC]
F00BC100: d423a068                 st      %o2, [%sp+0x140+var_D8]
F00BC104: d807a05c                 ld      [%fp+arg_5C], %o4
F00BC108: 9410001c                 mov     %i4, %o2
F00BC10C: da07a060                 ld      [%fp+arg_60], %o5
F00BC110: 7ffd6196                 call    _sprintf
F00BC114: 9610001d                 mov     %i5, %o3
F00BC118: 9010001a                 mov     %i2, %o0
F00BC11C: 4000051f                 call    _DoAlert
F00BC120: 92100010                 mov     %l0, %o1
F00BC124: 81c7e008                 ret
F00BC128: 91e82000                 restore %g0, 0, %o0
