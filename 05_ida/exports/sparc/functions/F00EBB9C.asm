F00EBB9C: 9de3bf90                 save    %sp, -0x70, %sp
F00EBBA0: 213c0506                 sethi   %hi(paError), %l0
F00EBBA4: 40001ece                 call    _sel_getName
F00EBBA8: 9010001a                 mov     %i2, %o0
F00EBBAC: 96100008                 mov     %o0, %o3
F00EBBB0: 90100018                 mov     %i0, %o0! id
F00EBBB4: d2042228                 ld      [%l0+%lo(paError)], %o1! SEL
F00EBBB8: 153c03e8                 sethi   %hi(aMethodSNotImpl), %o2! "method '%s' not implemented"
F00EBBBC: 4000172d                 call    _objc_msgSend
F00EBBC0: 9412a208                 bset    %lo(aMethodSNotImpl), %o2! "method '%s' not implemented"
F00EBBC4: 81c7e008                 ret
F00EBBC8: 91e80008                 restore %g0, %o0, %o0
