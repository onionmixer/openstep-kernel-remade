F009BB74: 9de3bf98                 save    %sp, -0x68, %sp
F009BB78: 90100018                 mov     %i0, %o0
F009BB7C: 9210001a                 mov     %i2, %o1
F009BB80: 80a66001                 cmp     %i1, 1
F009BB84: 0280000d                 be      loc_F009BBB8
F009BB88: 9410001b                 mov     %i3, %o2
F009BB8C: 80a66001                 cmp     %i1, 1
F009BB90: 14800007                 bg      loc_F009BBAC
F009BB94: 80a66002                 cmp     %i1, 2
F009BB98: 80a66000                 cmp     %i1, 0
F009BB9C: 0280000f                 be      loc_F009BBD8
F009BBA0: 90100009                 mov     %o1, %o0
F009BBA4: 10800010                 ba      locret_F009BBE4
F009BBA8: b0102004                 mov     4, %i0
F009BBAC: 02800007                 be      loc_F009BBC8
F009BBB0: b0102004                 mov     4, %i0
F009BBB4: 3080000c                 ba,a    locret_F009BBE4
F009BBB8: 4000000d                 call    _get_thread_state
F009BBBC: 01000000                 nop
F009BBC0: 10800009                 ba      locret_F009BBE4
F009BBC4: b0100008                 mov     %o0, %i0
F009BBC8: 40000019                 call    _get_thread_fpstate
F009BBCC: 01000000                 nop
F009BBD0: 10800005                 ba      locret_F009BBE4
F009BBD4: b0100008                 mov     %o0, %i0
F009BBD8: 4000002e                 call    _get_thread_state_flavor_list
F009BBDC: 9210000a                 mov     %o2, %o1
F009BBE0: b0100008                 mov     %o0, %i0
F009BBE4: 81c7e008                 ret
F009BBE8: 81e80000                 restore
