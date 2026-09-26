F008AA54: 9de3bf98                 save    %sp, -0x68, %sp
F008AA58: 90100018                 mov     %i0, %o0
F008AA5C: 92100019                 mov     %i1, %o1
F008AA60: 9410001a                 mov     %i2, %o2
F008AA64: 9610001b                 mov     %i3, %o3
F008AA68: 80a22000                 cmp     %o0, 0
F008AA6C: 02800006                 be      loc_F008AA84
F008AA70: 9810001c                 mov     %i4, %o4
F008AA74: 7fffed8b                 call    _vm_map_machine_attribute
F008AA78: 01000000                 nop
F008AA7C: 10800003                 ba      locret_F008AA88
F008AA80: b0100008                 mov     %o0, %i0
F008AA84: b0102004                 mov     4, %i0
F008AA88: 81c7e008                 ret
F008AA8C: 81e80000                 restore
