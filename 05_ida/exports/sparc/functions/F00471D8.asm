F00471D8: 9de3bf58                 save    %sp, -0xA8, %sp
F00471DC: a0100018                 mov     %i0, %l0
F00471E0: 400083a4                 call    _kalloc
F00471E4: 9010208c                 mov     0x8C, %o0! void *
F00471E8: b0100008                 mov     %o0, %i0
F00471EC: 4001371b                 call    _bzero
F00471F0: 9210208c                 mov     0x8C, %o1
F00471F4: 113c043890122180         set     _fifo_vnodeops, %o0
F00471FC: d0262020                 st      %o0, [%i0+0x20]
F0047200: d204201c                 ld      [%l0+0x1C], %o1
F0047204: 113c04cf                 sethi   %hi(_active_u), %o0
F0047208: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F004720C: d6026014                 ld      [%o1+0x14], %o3
F0047210: 90100010                 mov     %l0, %o0
F0047214: d402a01c                 ld      [%o2+0x1C], %o2
F0047218: 9fc2c000                 call    %o3
F004721C: 9207bfb8                 add     %fp, var_48, %o1
F0047220: d007bfd8                 ld      [%fp+var_28], %o0
F0047224: d026204c                 st      %o0, [%i0+0x4C]
F0047228: d007bfdc                 ld      [%fp+var_24], %o0
F004722C: d0262050                 st      %o0, [%i0+0x50]
F0047230: d007bfe0                 ld      [%fp+var_20], %o0
F0047234: d0262054                 st      %o0, [%i0+0x54]
F0047238: d007bfe4                 ld      [%fp+var_1C], %o0
F004723C: d0262058                 st      %o0, [%i0+0x58]
F0047240: d007bfe8                 ld      [%fp+var_18], %o0
F0047244: d026205c                 st      %o0, [%i0+0x5C]
F0047248: d007bfec                 ld      [%fp+var_14], %o0
F004724C: d0262060                 st      %o0, [%i0+0x60]
F0047250: 81c7e008                 ret
F0047254: 81e80000                 restore
