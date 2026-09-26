F00EBACC: 9de3bf90                 save    %sp, -0x70, %sp
F00EBAD0: 90100019                 mov     %i1, %o0! sel
F00EBAD4: 92968000                 orcc    %i2, %g0, %o1
F00EBAD8: 1280000c                 bne     loc_F00EBB08
F00EBADC: 9410001b                 mov     %i3, %o2
F00EBAE0: 40001eff                 call    _sel_getName
F00EBAE4: 213c0506                 sethi   %hi(paError), %l0
F00EBAE8: 96100008                 mov     %o0, %o3
F00EBAEC: 90100018                 mov     %i0, %o0! id
F00EBAF0: d2042228                 ld      [%l0+%lo(paError)], %o1! SEL
F00EBAF4: 153c03e89412a228         set     aMethodSGivenIn, %o2! "method %s given invalid selector %s"
F00EBAFC: 4000175d                 call    _objc_msgSend
F00EBB00: 98102000                 mov     0, %o4
F00EBB04: 30800003                 ba,a    locret_F00EBB10
F00EBB08: 4000175a                 call    _objc_msgSend
F00EBB0C: 90100018                 mov     %i0, %o0
F00EBB10: 81c7e008                 ret
F00EBB14: 91e80008                 restore %g0, %o0, %o0
