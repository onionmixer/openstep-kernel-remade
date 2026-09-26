F006E35C: 9de3bf98                 save    %sp, -0x68, %sp
F006E360: 90100018                 mov     %i0, %o0
F006E364: 92100008                 mov     %o0, %o1
F006E368: 153c04f0                 sethi   %hi(_ns_per_tick), %o2
F006E36C: d41aa288                 ldd     [%o2+%lo(_ns_per_tick)], %o2
F006E370: 7ffe5c55                 call    __muldi3
F006E374: 90102000                 mov     0, %o0
F006E378: b0100008                 mov     %o0, %i0
F006E37C: b2100009                 mov     %o1, %i1
F006E380: 81c7e008                 ret
F006E384: 81e80000                 restore
