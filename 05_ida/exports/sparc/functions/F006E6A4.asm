F006E6A4: 9de3bf98                 save    %sp, -0x68, %sp
F006E6A8: 7ffffee5                 call    _timeval_to_ns_time
F006E6AC: 9010001a                 mov     %i2, %o0
F006E6B0: 94100008                 mov     %o0, %o2
F006E6B4: 96100009                 mov     %o1, %o3
F006E6B8: 90100018                 mov     %i0, %o0
F006E6BC: 92100019                 mov     %i1, %o1
F006E6C0: 7ffffe99                 call    _ns_timeout
F006E6C4: 9810001b                 mov     %i3, %o4
F006E6C8: 81c7e008                 ret
F006E6CC: 81e80000                 restore
