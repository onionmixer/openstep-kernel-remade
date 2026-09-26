F0090464: 9de3bf90                 save    %sp, -0x70, %sp
F0090468: 98100019                 mov     %i1, %o4
F009046C: 9610001a                 mov     %i2, %o3
F0090470: f627bff4                 st      %i3, [%fp+var_C]
F0090474: 80a62000                 cmp     %i0, 0
F0090478: 0280000c                 be      loc_F00904A8
F009047C: 9410001c                 mov     %i4, %o2
F0090480: 113c0506                 sethi   %hi(paIodevice_0), %o0
F0090484: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F0090488: 133c0504                 sethi   %hi(paGetcharvaluesF), %o1
F009048C: d202614c                 ld      [%o1+%lo(paGetcharvaluesF)], %o1! SEL
F0090490: 400184f8                 call    _objc_msgSend
F0090494: 9a07bff4                 add     %fp, var_C, %o5
F0090498: d207bff4                 ld      [%fp+var_C], %o1
F009049C: b0100008                 mov     %o0, %i0
F00904A0: 10800003                 ba      locret_F00904AC
F00904A4: d2274000                 st      %o1, [%i5]
F00904A8: b0103d3f                 mov     -0x2C1, %i0
F00904AC: 81c7e008                 ret
F00904B0: 81e80000                 restore
