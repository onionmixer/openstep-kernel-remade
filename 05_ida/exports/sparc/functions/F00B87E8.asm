F00B87E8: 9de3bf98                 save    %sp, -0x68, %sp
F00B87EC: 92964000                 orcc    %i1, %g0, %o1
F00B87F0: 02800008                 be      loc_F00B8810
F00B87F4: 90100018                 mov     %i0, %o0
F00B87F8: d4022004                 ld      [%o0+4], %o2
F00B87FC: d602a01c                 ld      [%o2+0x1C], %o3
F00B8800: 9fc2c000                 call    %o3
F00B8804: 9410001a                 mov     %i2, %o2
F00B8808: 10800003                 ba      locret_F00B8814
F00B880C: b0100008                 mov     %o0, %i0
F00B8810: b0102000                 mov     0, %i0
F00B8814: 81c7e008                 ret
F00B8818: 81e80000                 restore
