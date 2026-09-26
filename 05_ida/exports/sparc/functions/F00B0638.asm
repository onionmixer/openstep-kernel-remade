F00B0638: 9de3bf98                 save    %sp, -0x68, %sp
F00B063C: 40000132                 call    sub_F00B0B04
F00B0640: 213c04fb                 sethi   %hi(_top_devinfo), %l0
F00B0644: 7ffede8b                 call    _kalloc
F00B0648: 90102038                 mov     0x38, %o0! void *
F00B064C: d0242088                 st      %o0, [%l0+%lo(_top_devinfo)]
F00B0650: 7fff9202                 call    _bzero
F00B0654: 92102038                 mov     0x38, %o1 ! '8'
F00B0658: 7ffffb88                 call    _prom_nextnode
F00B065C: 90102000                 mov     0, %o0
F00B0660: d2042088                 ld      [%l0+%lo(_top_devinfo)], %o1
F00B0664: d0226028                 st      %o0, [%o1+0x28]
F00B0668: 4000005f                 call    sub_F00B07E4
F00B066C: 90100009                 mov     %o1, %o0
F00B0670: 40000163                 call    _attach_devs
F00B0674: d0042088                 ld      [%l0+%lo(_top_devinfo)], %o0
F00B0678: 81c7e008                 ret
F00B067C: 81e80000                 restore
