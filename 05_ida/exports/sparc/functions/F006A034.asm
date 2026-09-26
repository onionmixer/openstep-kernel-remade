F006A034: 9de3bf98                 save    %sp, -0x68, %sp
F006A038: 90100018                 mov     %i0, %o0! mhp
F006A03C: 92100019                 mov     %i1, %o1! segname
F006A040: 4000000c                 call    _getsectbynamefromheader
F006A044: 9410001a                 mov     %i2, %o2
F006A048: 92920000                 orcc    %o0, %g0, %o1
F006A04C: 22800006                 be,a    loc_F006A064
F006A050: c026c000                 clr     [%i3]
F006A054: d0026024                 ld      [%o1+0x24], %o0
F006A058: d026c000                 st      %o0, [%i3]
F006A05C: 10800003                 ba      locret_F006A068
F006A060: f0026020                 ld      [%o1+0x20], %i0
F006A064: b0102000                 mov     0, %i0
F006A068: 81c7e008                 ret
F006A06C: 81e80000                 restore
