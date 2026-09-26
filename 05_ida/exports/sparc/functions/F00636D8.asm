F00636D8: 9de3bf98                 save    %sp, -0x68, %sp
F00636DC: 90100018                 mov     %i0, %o0! task
F00636E0: 92100019                 mov     %i1, %o1! name
F00636E4: 9410001a                 mov     %i2, %o2! members
F00636E8: 7ffffc3a                 call    _mach_port_get_set_status
F00636EC: 9610001b                 mov     %i3, %o3
F00636F0: 80a22000                 cmp     %o0, 0
F00636F4: 02800004                 be      locret_F0063704
F00636F8: 80a22006                 cmp     %o0, 6
F00636FC: 32800002                 bne,a   locret_F0063704
F0063700: 90102004                 mov     4, %o0
F0063704: 81c7e008                 ret
F0063708: 91e80008                 restore %g0, %o0, %o0
