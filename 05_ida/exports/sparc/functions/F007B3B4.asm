F007B3B4: 9de3bf98                 save    %sp, -0x68, %sp
F007B3B8: 90100018                 mov     %i0, %o0
F007B3BC: 92964000                 orcc    %i1, %g0, %o1
F007B3C0: 12800005                 bne     loc_F007B3D4
F007B3C4: 9810001a                 mov     %i2, %o4
F007B3C8: c0230000                 clr     [%o4]
F007B3CC: 10800008                 ba      locret_F007B3EC
F007B3D0: b0102000                 mov     0, %i0
F007B3D4: 94102006                 mov     6, %o2
F007B3D8: 7fffb28c                 call    _object_copyin
F007B3DC: 96102000                 mov     0, %o3
F007B3E0: 80a00008                 cmp     %g0, %o0
F007B3E4: b0403fff                 addc    %g0, -1, %i0
F007B3E8: b00e2004                 and     %i0, 4, %i0
F007B3EC: 81c7e008                 ret
F007B3F0: 81e80000                 restore
