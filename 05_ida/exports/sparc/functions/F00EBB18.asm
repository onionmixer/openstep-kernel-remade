F00EBB18: 9de3bf90                 save    %sp, -0x70, %sp
F00EBB1C: 90100019                 mov     %i1, %o0! sel
F00EBB20: 9210001a                 mov     %i2, %o1
F00EBB24: 9410001b                 mov     %i3, %o2
F00EBB28: 80a26000                 cmp     %o1, 0
F00EBB2C: 1280000c                 bne     loc_F00EBB5C
F00EBB30: 9610001c                 mov     %i4, %o3
F00EBB34: 40001eea                 call    _sel_getName
F00EBB38: 213c0506                 sethi   %hi(paError), %l0
F00EBB3C: 96100008                 mov     %o0, %o3
F00EBB40: 90100018                 mov     %i0, %o0! id
F00EBB44: d2042228                 ld      [%l0+%lo(paError)], %o1! SEL
F00EBB48: 153c03e89412a228         set     aMethodSGivenIn, %o2! "method %s given invalid selector %s"
F00EBB50: 40001748                 call    _objc_msgSend
F00EBB54: 98102000                 mov     0, %o4
F00EBB58: 30800003                 ba,a    locret_F00EBB64
F00EBB5C: 40001745                 call    _objc_msgSend
F00EBB60: 90100018                 mov     %i0, %o0
F00EBB64: 81c7e008                 ret
F00EBB68: 91e80008                 restore %g0, %o0, %o0
