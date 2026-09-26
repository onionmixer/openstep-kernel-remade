F00B1704: 9de3bf98                 save    %sp, -0x68, %sp
F00B1708: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00B170C: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00B1710: 920e3000                 and     %i0, -0x1000, %o1
F00B1714: 940e2fff                 and     %i0, 0xFFF, %o2
F00B1718: 7fffae99                 call    _pmap_remove
F00B171C: b206400a                 add     %i1, %o2, %i1
F00B1720: 7fff951a                 call    _splusclock
F00B1724: 01000000                 nop
F00B1728: a0100008                 mov     %o0, %l0
F00B172C: 90100018                 mov     %i0, %o0
F00B1730: 7ffeda9c                 call    _kfree
F00B1734: 92100019                 mov     %i1, %o1
F00B1738: 7fff957b                 call    _splx
F00B173C: 90100010                 mov     %l0, %o0
F00B1740: 81c7e008                 ret
F00B1744: 81e80000                 restore
