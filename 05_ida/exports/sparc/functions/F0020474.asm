F0020474: 9de3bf98                 save    %sp, -0x68, %sp
F0020478: a006203c                 add     %i0, 0x3C, %l0 ! '<'
F002047C: 90100010                 mov     %l0, %o0
F0020480: 40000010                 call    _sbreserve
F0020484: 92100019                 mov     %i1, %o1
F0020488: 80a22000                 cmp     %o0, 0
F002048C: 2280000b                 be,a    locret_F00204B8
F0020490: b0102037                 mov     0x37, %i0 ! '7'
F0020494: 90062024                 add     %i0, 0x24, %o0 ! '$'
F0020498: 4000000a                 call    _sbreserve
F002049C: 9210001a                 mov     %i2, %o1
F00204A0: 80a22000                 cmp     %o0, 0
F00204A4: 12800005                 bne     locret_F00204B8
F00204A8: b0102000                 mov     0, %i0
F00204AC: 40000017                 call    _sbrelease
F00204B0: 90100010                 mov     %l0, %o0
F00204B4: b0102037                 mov     0x37, %i0 ! '7'
F00204B8: 81c7e008                 ret
F00204BC: 81e80000                 restore
