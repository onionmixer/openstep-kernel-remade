F009A640: 9de3bf50                 save    %sp, -0xB0, %sp
F009A644: a007bfb0                 add     %fp, var_50, %l0
F009A648: 90100010                 mov     %l0, %o0! void *
F009A64C: 7fffea03                 call    _bzero
F009A650: 92102044                 mov     0x44, %o1 ! 'D'
F009A654: f227bfd0                 st      %i1, [%fp+var_30]
F009A658: 90102008                 mov     8, %o0
F009A65C: d027bfb0                 st      %o0, [%fp+var_50]
F009A660: f427bfc4                 st      %i2, [%fp+var_3C]
F009A664: 90100018                 mov     %i0, %o0
F009A668: 92100010                 mov     %l0, %o1
F009A66C: 9410001b                 mov     %i3, %o2
F009A670: 9610001c                 mov     %i4, %o3
F009A674: 7ffffe94                 call    _mb_mapalloc
F009A678: 9810001d                 mov     %i5, %o4
F009A67C: 81c7e008                 ret
F009A680: 91e80008                 restore %g0, %o0, %o0
