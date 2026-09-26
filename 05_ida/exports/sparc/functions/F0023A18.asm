F0023A18: 9de3bf98                 save    %sp, -0x68, %sp
F0023A1C: 4001258c                 call    _mfs_sync
F0023A20: 01000000                 nop
F0023A24: 133c042f                 sethi   %hi(_vfssw), %o1
F0023A28: 153c0430                 sethi   %hi(_vfsNVFS), %o2
F0023A2C: d002a08c                 ld      [%o2+%lo(_vfsNVFS)], %o0
F0023A30: a01263d8                 or      %o1, %lo(_vfssw), %l0
F0023A34: 80a40008                 cmp     %l0, %o0
F0023A38: 1a80000e                 bcc     locret_F0023A70
F0023A3C: a210000a                 mov     %o2, %l1
F0023A40: d0042004                 ld      [%l0+4], %o0
F0023A44: 80a22000                 cmp     %o0, 0
F0023A48: 22800006                 be,a    loc_F0023A60
F0023A4C: d004608c                 ld      [%l1+0x8C], %o0
F0023A50: d2022010                 ld      [%o0+0x10], %o1
F0023A54: 9fc24000                 call    %o1
F0023A58: 90102000                 mov     0, %o0
F0023A5C: d004608c                 ld      [%l1+0x8C], %o0
F0023A60: a0042008                 inc     8, %l0
F0023A64: 80a40008                 cmp     %l0, %o0
F0023A68: 2abffff7                 bcs,a   loc_F0023A44
F0023A6C: d0042004                 ld      [%l0+4], %o0
F0023A70: 81c7e008                 ret
F0023A74: 81e80000                 restore
