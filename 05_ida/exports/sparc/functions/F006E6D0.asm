F006E6D0: 9de3bf98                 save    %sp, -0x68, %sp
F006E6D4: 7ffffeda                 call    _timeval_to_ns_time
F006E6D8: 9010001a                 mov     %i2, %o0
F006E6DC: 94100008                 mov     %o0, %o2
F006E6E0: 96100009                 mov     %o1, %o3
F006E6E4: 90100018                 mov     %i0, %o0
F006E6E8: 92100019                 mov     %i1, %o1
F006E6EC: 7ffffe9a                 call    _ns_abstimeout
F006E6F0: 9810001b                 mov     %i3, %o4
F006E6F4: 81c7e008                 ret
F006E6F8: 81e80000                 restore
