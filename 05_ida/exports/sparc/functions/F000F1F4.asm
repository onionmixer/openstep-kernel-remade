F000F1F4: 9de3bf98                 save    %sp, -0x68, %sp
F000F1F8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000F1FC: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F000F200: e0022024                 ld      [%o0+0x24], %l0
F000F204: d0040000                 ld      [%l0], %o0
F000F208: 80a23fff                 cmp     %o0, -1
F000F20C: 12800006                 bne     loc_F000F224
F000F210: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F000F214: d0027ffc                 ld      [%o1-4], %o0
F000F218: d002201c                 ld      [%o0+0x1C], %o0
F000F21C: 10800003                 ba      loc_F000F228
F000F220: e4122006                 lduh    [%o0+6], %l2
F000F224: a4100008                 mov     %o0, %l2
F000F228: 113c04cf                 sethi   %hi(_active_u), %o0
F000F22C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F230: d602201c                 ld      [%o0+0x1C], %o3
F000F234: 912ca010                 sll     %l2, 16, %o0
F000F238: d252e006                 ldsh    [%o3+6], %o1
F000F23C: 953a2010                 sra     %o0, 16, %o2
F000F240: 80a2400a                 cmp     %o1, %o2
F000F244: 2280000c                 be,a    loc_F000F274
F000F248: d0042004                 ld      [%l0+4], %o0
F000F24C: d052e002                 ldsh    [%o3+2], %o0
F000F250: 80a2000a                 cmp     %o0, %o2
F000F254: 22800008                 be,a    loc_F000F274
F000F258: d0042004                 ld      [%l0+4], %o0
F000F25C: 400001c4                 call    _suser
F000F260: 01000000                 nop
F000F264: 80a22000                 cmp     %o0, 0
F000F268: 02800030                 be      locret_F000F328
F000F26C: 01000000                 nop
F000F270: d0042004                 ld      [%l0+4], %o0
F000F274: 80a23fff                 cmp     %o0, -1
F000F278: 12800006                 bne     loc_F000F290
F000F27C: a2100008                 mov     %o0, %l1
F000F280: 113c04cf                 sethi   %hi(_active_u), %o0
F000F284: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F288: d002201c                 ld      [%o0+0x1C], %o0
F000F28C: e2122002                 lduh    [%o0+2], %l1
F000F290: 113c04cf                 sethi   %hi(_active_u), %o0
F000F294: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F298: d602201c                 ld      [%o0+0x1C], %o3
F000F29C: 912c6010                 sll     %l1, 16, %o0
F000F2A0: d252e006                 ldsh    [%o3+6], %o1
F000F2A4: 953a2010                 sra     %o0, 16, %o2
F000F2A8: 80a2400a                 cmp     %o1, %o2
F000F2AC: 0280000b                 be      loc_F000F2D8
F000F2B0: 213c04cf                 sethi   %hi(_active_u), %l0
F000F2B4: d052e002                 ldsh    [%o3+2], %o0
F000F2B8: 80a2000a                 cmp     %o0, %o2
F000F2BC: 02800008                 be      loc_F000F2DC
F000F2C0: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F000F2C4: 400001aa                 call    _suser
F000F2C8: 01000000                 nop
F000F2CC: 80a22000                 cmp     %o0, 0
F000F2D0: 02800016                 be      locret_F000F328
F000F2D4: 01000000                 nop
F000F2D8: d00421d8                 ld      [%l0+0x1D8], %o0
F000F2DC: 400166ba                 call    _lock_write
F000F2E0: 90022020                 inc     0x20, %o0 ! ' '
F000F2E4: d00421d8                 ld      [%l0+0x1D8], %o0
F000F2E8: 400001e2                 call    _crcopy
F000F2EC: d002201c                 ld      [%o0+0x1C], %o0
F000F2F0: d20421d8                 ld      [%l0+0x1D8], %o1
F000F2F4: d022601c                 st      %o0, [%o1+0x1C]
F000F2F8: d00421d8                 ld      [%l0+0x1D8], %o0
F000F2FC: d0020000                 ld      [%o0], %o0
F000F300: e232202c                 sth     %l1, [%o0+0x2C]
F000F304: d00421d8                 ld      [%l0+0x1D8], %o0
F000F308: d002201c                 ld      [%o0+0x1C], %o0
F000F30C: e4322006                 sth     %l2, [%o0+6]
F000F310: d00421d8                 ld      [%l0+0x1D8], %o0
F000F314: d002201c                 ld      [%o0+0x1C], %o0
F000F318: e2322002                 sth     %l1, [%o0+2]
F000F31C: d00421d8                 ld      [%l0+0x1D8], %o0
F000F320: 40016745                 call    _lock_done
F000F324: 90022020                 inc     0x20, %o0 ! ' '
F000F328: 81c7e008                 ret
F000F32C: 81e80000                 restore
