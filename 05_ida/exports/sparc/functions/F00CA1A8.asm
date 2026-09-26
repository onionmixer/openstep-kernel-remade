F00CA1A8: 9de3bf98                 save    %sp, -0x68, %sp
F00CA1AC: 92100019                 mov     %i1, %o1! policy
F00CA1B0: 80a26002                 cmp     %o1, 2
F00CA1B4: 12800004                 bne     loc_F00CA1C4
F00CA1B8: 94102000                 mov     0, %o2
F00CA1BC: 113c04f0                 sethi   %hi(_min_quantum), %o0! thr_act
F00CA1C0: d4022290                 ld      [%o0+%lo(_min_quantum)], %o2! base
F00CA1C4: 7ffeaef8                 call    _thread_policy
F00CA1C8: 90100018                 mov     %i0, %o0
F00CA1CC: 80a22004                 cmp     %o0, 4
F00CA1D0: 12800004                 bne     loc_F00CA1E0
F00CA1D4: 901a2005                 btog    5, %o0
F00CA1D8: 10800005                 ba      locret_F00CA1EC
F00CA1DC: b0103d3e                 mov     -0x2C2, %i0
F00CA1E0: 80a00008                 cmp     %g0, %o0
F00CA1E4: b0403fff                 addc    %g0, -1, %i0
F00CA1E8: b00e3d3f                 and     %i0, -0x2C1, %i0
F00CA1EC: 81c7e008                 ret
F00CA1F0: 81e80000                 restore
