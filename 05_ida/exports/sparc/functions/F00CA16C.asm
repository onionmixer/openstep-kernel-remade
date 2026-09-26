F00CA16C: 9de3bf98                 save    %sp, -0x68, %sp
F00CA170: 90100018                 mov     %i0, %o0
F00CA174: 92100019                 mov     %i1, %o1
F00CA178: 7ffeae98                 call    _thread_priority
F00CA17C: 94102000                 mov     0, %o2
F00CA180: 80a22004                 cmp     %o0, 4
F00CA184: 12800004                 bne     loc_F00CA194
F00CA188: 901a2005                 btog    5, %o0
F00CA18C: 10800005                 ba      locret_F00CA1A0
F00CA190: b0103d3e                 mov     -0x2C2, %i0
F00CA194: 80a00008                 cmp     %g0, %o0
F00CA198: b0403fff                 addc    %g0, -1, %i0
F00CA19C: b00e3d3f                 and     %i0, -0x2C1, %i0
F00CA1A0: 81c7e008                 ret
F00CA1A4: 81e80000                 restore
