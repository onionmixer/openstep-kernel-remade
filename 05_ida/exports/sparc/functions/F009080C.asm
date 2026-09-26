F009080C: 9de3bf98                 save    %sp, -0x68, %sp
F0090810: 80a62000                 cmp     %i0, 0
F0090814: 12800004                 bne     loc_F0090824
F0090818: 92100019                 mov     %i1, %o1
F009081C: 1080000b                 ba      locret_F0090848
F0090820: b0103d3f                 mov     -0x2C1, %i0
F0090824: d002600c                 ld      [%o1+0xC], %o0
F0090828: d0022050                 ld      [%o0+0x50], %o0
F009082C: 80a22000                 cmp     %o0, 0
F0090830: 32800006                 bne,a   locret_F0090848
F0090834: b0102000                 mov     0, %i0
F0090838: 90100018                 mov     %i0, %o0
F009083C: 40000017                 call    _kern_dev_map_port_com
F0090840: 94102001                 mov     1, %o2
F0090844: b0100008                 mov     %o0, %i0
F0090848: 81c7e008                 ret
F009084C: 81e80000                 restore
