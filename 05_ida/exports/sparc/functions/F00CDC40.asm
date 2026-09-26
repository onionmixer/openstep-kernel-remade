F00CDC40: 9de3bf80                 save    %sp, -0x80, %sp
F00CDC44: 90100018                 mov     %i0, %o0! id
F00CDC48: 94102000                 mov     0, %o2
F00CDC4C: 9610001a                 mov     %i2, %o3
F00CDC50: 9810001b                 mov     %i3, %o4
F00CDC54: d207a05c                 ld      [%fp+arg_5C], %o1
F00CDC58: 9a10001c                 mov     %i4, %o5
F00CDC5C: d223a05c                 st      %o1, [%sp+0x80+var_24]
F00CDC60: c023a060                 clr     [%sp+0x80+var_20]
F00CDC64: 133c0505                 sethi   %hi(paDevicerwcommon), %o1
F00CDC68: d20263d8                 ld      [%o1+%lo(paDevicerwcommon)], %o1! SEL
F00CDC6C: 40008f01                 call    _objc_msgSend
F00CDC70: fa23a064                 st      %i5, [%sp+0x80+var_1C]
F00CDC74: 81c7e008                 ret
F00CDC78: 91e80008                 restore %g0, %o0, %o0
