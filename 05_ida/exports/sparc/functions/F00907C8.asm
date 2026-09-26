F00907C8: 9de3bf98                 save    %sp, -0x68, %sp
F00907CC: 80a62000                 cmp     %i0, 0
F00907D0: 12800004                 bne     loc_F00907E0
F00907D4: 92100019                 mov     %i1, %o1
F00907D8: 1080000b                 ba      locret_F0090804
F00907DC: b0103d3f                 mov     -0x2C1, %i0
F00907E0: d002600c                 ld      [%o1+0xC], %o0
F00907E4: d0022050                 ld      [%o0+0x50], %o0
F00907E8: 80a22000                 cmp     %o0, 0
F00907EC: 32800006                 bne,a   locret_F0090804
F00907F0: b0102000                 mov     0, %i0
F00907F4: 90100018                 mov     %i0, %o0
F00907F8: 40000028                 call    _kern_dev_map_port_com
F00907FC: 94102000                 mov     0, %o2
F0090800: b0100008                 mov     %o0, %i0
F0090804: 81c7e008                 ret
F0090808: 81e80000                 restore
