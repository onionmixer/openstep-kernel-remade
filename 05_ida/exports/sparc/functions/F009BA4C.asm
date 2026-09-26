F009BA4C: 9de3bf98                 save    %sp, -0x68, %sp
F009BA50: 90100018                 mov     %i0, %o0
F009BA54: 9210001a                 mov     %i2, %o1
F009BA58: 80a66001                 cmp     %i1, 1
F009BA5C: 02800006                 be      loc_F009BA74
F009BA60: 9410001b                 mov     %i3, %o2
F009BA64: 80a66002                 cmp     %i1, 2
F009BA68: 02800007                 be      loc_F009BA84
F009BA6C: b0102004                 mov     4, %i0
F009BA70: 30800008                 ba,a    locret_F009BA90
F009BA74: 40000009                 call    _set_thread_state
F009BA78: 01000000                 nop
F009BA7C: 10800005                 ba      locret_F009BA90
F009BA80: b0100008                 mov     %o0, %i0
F009BA84: 40000026                 call    _set_thread_fpstate
F009BA88: 01000000                 nop
F009BA8C: b0100008                 mov     %o0, %i0
F009BA90: 81c7e008                 ret
F009BA94: 81e80000                 restore
