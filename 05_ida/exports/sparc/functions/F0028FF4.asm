F0028FF4: 9de3bf98                 save    %sp, -0x68, %sp
F0028FF8: a0100018                 mov     %i0, %l0
F0028FFC: d0042028                 ld      [%l0+0x28], %o0
F0029000: 80a22001                 cmp     %o0, 1
F0029004: 12800005                 bne     loc_F0029018
F0029008: 90100010                 mov     %l0, %o0
F002900C: 40010d08                 call    _unmap_vnode
F0029010: 90100010                 mov     %l0, %o0
F0029014: 90100010                 mov     %l0, %o0
F0029018: d404201c                 ld      [%l0+0x1C], %o2
F002901C: 133c04cf                 sethi   %hi(_active_u), %o1
F0029020: d60261d8                 ld      [%o1+%lo(_active_u)], %o3
F0029024: a41261d8                 or      %o1, %lo(_active_u), %l2
F0029028: d802a004                 ld      [%o2+4], %o4
F002902C: 92100019                 mov     %i1, %o1
F0029030: d602e01c                 ld      [%o3+0x1C], %o3
F0029034: 9fc30000                 call    %o4
F0029038: 9410001a                 mov     %i2, %o2
F002903C: d2040000                 ld      [%l0], %o1
F0029040: 80a26000                 cmp     %o1, 0
F0029044: 0280001a                 be      locret_F00290AC
F0029048: b0100008                 mov     %o0, %i0
F002904C: d0026034                 ld      [%o1+0x34], %o0
F0029050: 80a22000                 cmp     %o0, 0
F0029054: 02800016                 be      locret_F00290AC
F0029058: 23000004                 sethi   0x1000, %l1
F002905C: b0100008                 mov     %o0, %i0
F0029060: c0226034                 clr     [%o1+0x34]
F0029064: d004a004                 ld      [%l2+4], %o0
F0029068: 353c04cf                 sethi   -0xFECC400, %i2
F002906C: f02a2038                 stb     %i0, [%o0+0x38]
F0029070: 40007e9a                 call    _fspause
F0029074: 900e4011                 and     %i1, %l1, %o0
F0029078: 80a22000                 cmp     %o0, 0
F002907C: 0280000c                 be      locret_F00290AC
F0029080: 01000000                 nop
F0029084: d0040000                 ld      [%l0], %o0
F0029088: f0022034                 ld      [%o0+0x34], %i0
F002908C: c0222034                 clr     [%o0+0x34]
F0029090: d206a1dc                 ld      [%i2+0x1DC], %o1
F0029094: 90100010                 mov     %l0, %o0
F0029098: 40011028                 call    _mfs_fsync
F002909C: f02a6038                 stb     %i0, [%o1+0x38]
F00290A0: 80a62000                 cmp     %i0, 0
F00290A4: 12bffff3                 bne     loc_F0029070
F00290A8: 01000000                 nop
F00290AC: 81c7e008                 ret
F00290B0: 81e80000                 restore
