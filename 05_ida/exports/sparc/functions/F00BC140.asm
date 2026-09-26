F00BC140: 9de3bec0                 save    %sp, -0x140, %sp
F00BC144: a007bf30                 add     %fp, var_D0, %l0
F00BC148: d807a05c                 ld      [%fp+arg_5C], %o4
F00BC14C: 90100010                 mov     %l0, %o0! char *
F00BC150: d607a060                 ld      [%fp+arg_60], %o3
F00BC154: 92100018                 mov     %i0, %o1! char *
F00BC158: d407a064                 ld      [%fp+arg_64], %o2
F00BC15C: 9a10001c                 mov     %i4, %o5
F00BC160: fa23a05c                 st      %i5, [%sp+0x140+var_E4]
F00BC164: d823a060                 st      %o4, [%sp+0x140+var_E0]
F00BC168: d623a064                 st      %o3, [%sp+0x140+var_DC]
F00BC16C: d423a068                 st      %o2, [%sp+0x140+var_D8]
F00BC170: 94100019                 mov     %i1, %o2
F00BC174: 9610001a                 mov     %i2, %o3
F00BC178: 7ffd617c                 call    _sprintf
F00BC17C: 9810001b                 mov     %i3, %o4
F00BC180: d24c0000                 ldsb    [%l0], %o1
F00BC184: 90102000                 mov     0, %o0
F00BC188: 7ffffeba                 call    _kmputc
F00BC18C: a0042001                 inc     %l0
F00BC190: 80a42000                 cmp     %l0, 0
F00BC194: 32bffffc                 bne,a   loc_F00BC184
F00BC198: d24c0000                 ldsb    [%l0], %o1
F00BC19C: 81c7e008                 ret
F00BC1A0: 81e80000                 restore
