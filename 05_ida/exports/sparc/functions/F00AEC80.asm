F00AEC80: 9de3bf98                 save    %sp, -0x68, %sp
F00AEC84: 808e2003                 btst    3, %i0
F00AEC88: 02800004                 be      loc_F00AEC98
F00AEC8C: 92100019                 mov     %i1, %o1
F00AEC90: 1080000c                 ba      locret_F00AECC0
F00AEC94: b0102005                 mov     5, %i0
F00AEC98: 7fff6ccd                 call    _suword
F00AEC9C: 90100018                 mov     %i0, %o0
F00AECA0: 80a23fff                 cmp     %o0, -1
F00AECA4: 22800004                 be,a    loc_F00AECB4
F00AECA8: f026a020                 st      %i0, [%i2+0x20]
F00AECAC: 10800005                 ba      locret_F00AECC0
F00AECB0: b0102000                 mov     0, %i0
F00AECB4: 90102002                 mov     2, %o0
F00AECB8: d026a028                 st      %o0, [%i2+0x28]
F00AECBC: b0102006                 mov     6, %i0
F00AECC0: 81c7e008                 ret
F00AECC4: 81e80000                 restore
