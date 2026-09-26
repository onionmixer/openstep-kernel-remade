F000AF18: 9de3bf98                 save    %sp, -0x68, %sp
F000AF1C: 80a6a000                 cmp     %i2, 0
F000AF20: 02800005                 be      loc_F000AF34
F000AF24: f427a04c                 st      %i2, [%fp+arg_4C]
F000AF28: d0062008                 ld      [%i0+8], %o0
F000AF2C: 10800004                 ba      loc_F000AF3C
F000AF30: 90120019                 bset    %i1, %o0
F000AF34: d0062008                 ld      [%i0+8], %o0
F000AF38: 902a0019                 bclr    %i1, %o0
F000AF3C: 80a66004                 cmp     %i1, 4
F000AF40: 12800005                 bne     loc_F000AF54
F000AF44: d0262008                 st      %o0, [%i0+8]
F000AF48: 11200119                 sethi   -0x7FFB9C00, %o0
F000AF4C: 10800004                 ba      loc_F000AF5C
F000AF50: 9212227e                 or      %o0, 0x27E, %o1
F000AF54: 112001199212227d         set     -0x7FFB9983, %o1
F000AF5C: 90100018                 mov     %i0, %o0
F000AF60: 40000035                 call    _fioctl
F000AF64: 9407a04c                 add     %fp, arg_4C, %o2
F000AF68: 81c7e008                 ret
F000AF6C: 91e80008                 restore %g0, %o0, %o0
