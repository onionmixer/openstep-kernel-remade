F0090414: 9de3bf90                 save    %sp, -0x70, %sp
F0090418: 98100019                 mov     %i1, %o4
F009041C: 9610001a                 mov     %i2, %o3
F0090420: f627bff4                 st      %i3, [%fp+var_C]
F0090424: 80a62000                 cmp     %i0, 0
F0090428: 0280000c                 be      loc_F0090458
F009042C: 9410001c                 mov     %i4, %o2
F0090430: 113c0506                 sethi   %hi(paIodevice_0), %o0
F0090434: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F0090438: 133c0504                 sethi   %hi(paGetintvaluesFo), %o1
F009043C: d2026148                 ld      [%o1+%lo(paGetintvaluesFo)], %o1! SEL
F0090440: 4001850c                 call    _objc_msgSend
F0090444: 9a07bff4                 add     %fp, var_C, %o5
F0090448: d207bff4                 ld      [%fp+var_C], %o1
F009044C: b0100008                 mov     %o0, %i0
F0090450: 10800003                 ba      locret_F009045C
F0090454: d2274000                 st      %o1, [%i5]
F0090458: b0103d3f                 mov     -0x2C1, %i0
F009045C: 81c7e008                 ret
F0090460: 81e80000                 restore
