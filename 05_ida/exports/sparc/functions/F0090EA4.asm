F0090EA4: 9de3bf90                 save    %sp, -0x70, %sp
F0090EA8: 90100018                 mov     %i0, %o0
F0090EAC: 9410001a                 mov     %i2, %o2
F0090EB0: 9610001b                 mov     %i3, %o3
F0090EB4: 9810001c                 mov     %i4, %o4
F0090EB8: 80a22000                 cmp     %o0, 0
F0090EBC: 02800009                 be      loc_F0090EE0
F0090EC0: da07a05c                 ld      [%fp+arg_5C], %o5
F0090EC4: d206600c                 ld      [%i1+0xC], %o1
F0090EC8: da23a05c                 st      %o5, [%sp+0x70+var_14]
F0090ECC: 9b2f6018                 sll     %i5, 24, %o5
F0090ED0: 7ffffe9b                 call    _kern_dev_map_phys
F0090ED4: 9b3b6018                 sra     %o5, 24, %o5
F0090ED8: 10800003                 ba      locret_F0090EE4
F0090EDC: b0100008                 mov     %o0, %i0
F0090EE0: b0103d3f                 mov     -0x2C1, %i0
F0090EE4: 81c7e008                 ret
F0090EE8: 81e80000                 restore
