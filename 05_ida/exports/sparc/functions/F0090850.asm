F0090850: 9de3bf90                 save    %sp, -0x70, %sp
F0090854: 90100018                 mov     %i0, %o0
F0090858: 9410001a                 mov     %i2, %o2
F009085C: 9610001b                 mov     %i3, %o3
F0090860: 9810001c                 mov     %i4, %o4
F0090864: 80a22000                 cmp     %o0, 0
F0090868: 02800009                 be      loc_F009088C
F009086C: da07a05c                 ld      [%fp+arg_5C], %o5
F0090870: d206600c                 ld      [%i1+0xC], %o1
F0090874: da23a05c                 st      %o5, [%sp+0x70+var_14]
F0090878: 9b2f6018                 sll     %i5, 24, %o5
F009087C: 40000030                 call    _kern_dev_map_phys
F0090880: 9b3b6018                 sra     %o5, 24, %o5
F0090884: 10800003                 ba      locret_F0090890
F0090888: b0100008                 mov     %o0, %i0
F009088C: b0103d3f                 mov     -0x2C1, %i0
F0090890: 81c7e008                 ret
F0090894: 81e80000                 restore
