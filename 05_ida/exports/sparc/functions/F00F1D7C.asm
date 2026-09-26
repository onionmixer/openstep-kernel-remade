F00F1D7C: 9de3bf98                 save    %sp, -0x68, %sp
F00F1D80: 7fffffe1                 call    _objc_getClass
F00F1D84: 90100018                 mov     %i0, %o0
F00F1D88: 80a22000                 cmp     %o0, 0
F00F1D8C: 32800003                 bne,a   locret_F00F1D98
F00F1D90: f0020000                 ld      [%o0], %i0
F00F1D94: b0102000                 mov     0, %i0
F00F1D98: 81c7e008                 ret
F00F1D9C: 81e80000                 restore
