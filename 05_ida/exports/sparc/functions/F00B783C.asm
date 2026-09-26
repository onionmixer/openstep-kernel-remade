F00B783C: 9de3bf98                 save    %sp, -0x68, %sp
F00B7840: 90100018                 mov     %i0, %o0
F00B7844: d20a2041                 ldub    [%o0+0x41], %o1
F00B7848: d22a2042                 stb     %o1, [%o0+0x42]
F00B784C: 9210201d                 mov     0x1D, %o1
F00B7850: d22a2041                 stb     %o1, [%o0+0x41]
F00B7854: 40000004                 call    _esp_internal_reset
F00B7858: 92102007                 mov     7, %o1
F00B785C: 81c7e008                 ret
F00B7860: 91e83fff                 restore %g0, -1, %o0
