F00B71F4: 9de3bf98                 save    %sp, -0x68, %sp
F00B71F8: 90100018                 mov     %i0, %o0
F00B71FC: d20a2041                 ldub    [%o0+0x41], %o1
F00B7200: d22a2042                 stb     %o1, [%o0+0x42]
F00B7204: 9210201c                 mov     0x1C, %o1
F00B7208: d22a2041                 stb     %o1, [%o0+0x41]
F00B720C: 40000196                 call    _esp_internal_reset
F00B7210: 92102007                 mov     7, %o1
F00B7214: 81c7e008                 ret
F00B7218: 91e83fff                 restore %g0, -1, %o0
