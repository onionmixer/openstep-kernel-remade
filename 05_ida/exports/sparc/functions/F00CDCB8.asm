F00CDCB8: 9de3bf80                 save    %sp, -0x80, %sp
F00CDCBC: 90100018                 mov     %i0, %o0! id
F00CDCC0: 94102001                 mov     1, %o2
F00CDCC4: 9610001a                 mov     %i2, %o3
F00CDCC8: 9810001b                 mov     %i3, %o4
F00CDCCC: d207a05c                 ld      [%fp+arg_5C], %o1
F00CDCD0: 9a10001c                 mov     %i4, %o5
F00CDCD4: d223a05c                 st      %o1, [%sp+0x80+var_24]
F00CDCD8: c023a060                 clr     [%sp+0x80+var_20]
F00CDCDC: 133c0505                 sethi   %hi(paDevicerwcommon), %o1
F00CDCE0: d20263d8                 ld      [%o1+%lo(paDevicerwcommon)], %o1! SEL
F00CDCE4: 40008ee3                 call    _objc_msgSend
F00CDCE8: fa23a064                 st      %i5, [%sp+0x80+var_1C]
F00CDCEC: 81c7e008                 ret
F00CDCF0: 91e80008                 restore %g0, %o0, %o0
