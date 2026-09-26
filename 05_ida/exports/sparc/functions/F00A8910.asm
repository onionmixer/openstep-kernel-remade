F00A8910: 9de3bf98                 save    %sp, -0x68, %sp
F00A8914: 92100019                 mov     %i1, %o1
F00A8918: 9410001a                 mov     %i2, %o2
F00A891C: d0024000                 ld      [%o1], %o0
F00A8920: 808a2040                 btst    0x40, %o0 ! '@'
F00A8924: 1280000a                 bne     loc_F00A894C
F00A8928: 9610001b                 mov     %i3, %o3
F00A892C: 11000040                 sethi   0x10000, %o0
F00A8930: 193c04cf                 sethi   %hi(dword_F0133DDC), %o4
F00A8934: da0321dc                 ld      [%o4+%lo(dword_F0133DDC)], %o5
F00A8938: 90160008                 bset    %i0, %o0
F00A893C: 9810001c                 mov     %i4, %o4
F00A8940: 7ffffbf0                 call    _user_trap
F00A8944: d2234000                 st      %o1, [%o5]
F00A8948: 30800004                 ba,a    locret_F00A8958
F00A894C: 90100018                 mov     %i0, %o0
F00A8950: 7fffff01                 call    _kernel_trap
F00A8954: 9810001c                 mov     %i4, %o4
F00A8958: 81c7e008                 ret
F00A895C: 81e80000                 restore
