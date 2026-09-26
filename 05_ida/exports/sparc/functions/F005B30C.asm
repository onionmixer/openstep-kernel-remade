F005B30C: 9de3bf98                 save    %sp, -0x68, %sp
F005B310: 113c04ef                 sethi   %hi(_ipc_object_zones), %o0
F005B314: d0022300                 ld      [%o0+%lo(_ipc_object_zones)], %o0
F005B318: 4000776d                 call    _zalloc
F005B31C: a0100018                 mov     %i0, %l0
F005B320: b0920000                 orcc    %o0, %g0, %i0
F005B324: 0280000b                 be      loc_F005B350
F005B328: 92100010                 mov     %l0, %o1
F005B32C: c0260000                 clr     [%i0]
F005B330: 90102001                 mov     1, %o0
F005B334: d0262004                 st      %o0, [%i0+4]
F005B338: 11200000                 sethi   0x80000000, %o0
F005B33C: d0262008                 st      %o0, [%i0+8]
F005B340: 90100018                 mov     %i0, %o0
F005B344: 7ffffdb5                 call    _ipc_port_init
F005B348: 94102001                 mov     1, %o2
F005B34C: 30800002                 ba,a    locret_F005B354
F005B350: b0102000                 mov     0, %i0
F005B354: 81c7e008                 ret
F005B358: 81e80000                 restore
