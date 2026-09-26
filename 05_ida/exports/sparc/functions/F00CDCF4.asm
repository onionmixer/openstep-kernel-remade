F00CDCF4: 9de3bf80                 save    %sp, -0x80, %sp
F00CDCF8: 90100018                 mov     %i0, %o0! id
F00CDCFC: 94102001                 mov     1, %o2
F00CDD00: 9610001a                 mov     %i2, %o3
F00CDD04: 9810001b                 mov     %i3, %o4
F00CDD08: d207a05c                 ld      [%fp+arg_5C], %o1
F00CDD0C: 9a10001c                 mov     %i4, %o5
F00CDD10: d223a05c                 st      %o1, [%sp+0x80+var_24]
F00CDD14: fa23a060                 st      %i5, [%sp+0x80+var_20]
F00CDD18: 133c0505                 sethi   %hi(paDevicerwcommon), %o1
F00CDD1C: d20263d8                 ld      [%o1+%lo(paDevicerwcommon)], %o1! SEL
F00CDD20: 40008ed4                 call    _objc_msgSend
F00CDD24: c023a064                 clr     [%sp+0x80+var_1C]
F00CDD28: 81c7e008                 ret
F00CDD2C: 91e80008                 restore %g0, %o0, %o0
