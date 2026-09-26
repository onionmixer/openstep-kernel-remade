F000A028: 9de3bf98                 save    %sp, -0x68, %sp
F000A02C: 400190cc                 call    _ticks_to_ns_time
F000A030: 9010001a                 mov     %i2, %o0
F000A034: 94100008                 mov     %o0, %o2
F000A038: 96100009                 mov     %o1, %o3
F000A03C: 90100018                 mov     %i0, %o0
F000A040: 92100019                 mov     %i1, %o1
F000A044: 40019038                 call    _ns_timeout
F000A048: 98102000                 mov     0, %o4
F000A04C: 81c7e008                 ret
F000A050: 81e80000                 restore
