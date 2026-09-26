F00EBA84: 9de3bf90                 save    %sp, -0x70, %sp
F00EBA88: 92968000                 orcc    %i2, %g0, %o1
F00EBA8C: 1280000c                 bne     loc_F00EBABC
F00EBA90: 90100019                 mov     %i1, %o0! sel
F00EBA94: 40001f12                 call    _sel_getName
F00EBA98: 213c0506                 sethi   %hi(paError), %l0
F00EBA9C: 96100008                 mov     %o0, %o3
F00EBAA0: 90100018                 mov     %i0, %o0! id
F00EBAA4: d2042228                 ld      [%l0+%lo(paError)], %o1! SEL
F00EBAA8: 153c03e89412a228         set     aMethodSGivenIn, %o2! "method %s given invalid selector %s"
F00EBAB0: 40001770                 call    _objc_msgSend
F00EBAB4: 98102000                 mov     0, %o4
F00EBAB8: 30800003                 ba,a    locret_F00EBAC4
F00EBABC: 4000176d                 call    _objc_msgSend
F00EBAC0: 90100018                 mov     %i0, %o0
F00EBAC4: 81c7e008                 ret
F00EBAC8: 91e80008                 restore %g0, %o0, %o0
