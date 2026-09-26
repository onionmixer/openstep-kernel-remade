F00B15BC: 9de3bf98                 save    %sp, -0x68, %sp
F00B15C0: 90102000                 mov     0, %o0
F00B15C4: 133c047192126378         set     aSlaveOnly, %o1! "slave-only"
F00B15CC: 7ffffeb8                 call    _getprop
F00B15D0: 94102000                 mov     0, %o2
F00B15D4: a0920000                 orcc    %o0, %g0, %l0
F00B15D8: 2280000f                 be,a    locret_F00B1614
F00B15DC: b0103fff                 mov     -1, %i0
F00B15E0: 7fffffdb                 call    _sbusslot
F00B15E4: 90100018                 mov     %i0, %o0
F00B15E8: 92100008                 mov     %o0, %o1
F00B15EC: 80a27fff                 cmp     %o1, -1
F00B15F0: 02800008                 be      loc_F00B1610
F00B15F4: 90102001                 mov     1, %o0
F00B15F8: 912a0009                 sll     %o0, %o1, %o0
F00B15FC: 808c0008                 btst    %o0, %l0
F00B1600: 02800005                 be      locret_F00B1614
F00B1604: b0103fff                 mov     -1, %i0
F00B1608: 10800003                 ba      locret_F00B1614
F00B160C: b0100009                 mov     %o1, %i0
F00B1610: b0103fff                 mov     -1, %i0
F00B1614: 81c7e008                 ret
F00B1618: 81e80000                 restore
