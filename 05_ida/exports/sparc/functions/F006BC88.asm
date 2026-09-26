F006BC88: 9de3bf98                 save    %sp, -0x68, %sp
F006BC8C: 113c04f0                 sethi   %hi(_mach_net_kmsg_zone), %o0
F006BC90: d00221a0                 ld      [%o0+%lo(_mach_net_kmsg_zone)], %o0
F006BC94: 4000354f                 call    _zfree
F006BC98: 92100018                 mov     %i0, %o1
F006BC9C: 81c7e008                 ret
F006BCA0: 81e80000                 restore
