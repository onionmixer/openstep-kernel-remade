F00CDC7C: 9de3bf80                 save    %sp, -0x80, %sp
F00CDC80: 90100018                 mov     %i0, %o0! id
F00CDC84: 94102000                 mov     0, %o2
F00CDC88: 9610001a                 mov     %i2, %o3
F00CDC8C: 9810001b                 mov     %i3, %o4
F00CDC90: d207a05c                 ld      [%fp+arg_5C], %o1
F00CDC94: 9a10001c                 mov     %i4, %o5
F00CDC98: d223a05c                 st      %o1, [%sp+0x80+var_24]
F00CDC9C: fa23a060                 st      %i5, [%sp+0x80+var_20]
F00CDCA0: 133c0505                 sethi   %hi(paDevicerwcommon), %o1
F00CDCA4: d20263d8                 ld      [%o1+%lo(paDevicerwcommon)], %o1! SEL
F00CDCA8: 40008ef2                 call    _objc_msgSend
F00CDCAC: c023a064                 clr     [%sp+0x80+var_1C]
F00CDCB0: 81c7e008                 ret
F00CDCB4: 91e80008                 restore %g0, %o0, %o0
