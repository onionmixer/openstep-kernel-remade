F00141D0: 9de3bf98                 save    %sp, -0x68, %sp
F00141D4: 313c04d4                 sethi   %hi(_log_open), %i0
F00141D8: d0062178                 ld      [%i0+%lo(_log_open)], %o0
F00141DC: 80a22000                 cmp     %o0, 0
F00141E0: 02800004                 be      loc_F00141F0
F00141E4: 213c04d4                 sethi   -0xFECB000, %l0
F00141E8: 10800024                 ba      locret_F0014278
F00141EC: b0102010                 mov     0x10, %i0
F00141F0: 113c04cf                 sethi   %hi(_active_u), %o0
F00141F4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00141F8: a0142180                 bset    0x180, %l0
F00141FC: c0242004                 clr     [%l0+4]
F0014200: d2020000                 ld      [%o0], %o1
F0014204: 113c0051                 sethi   %hi(sub_F001449C), %o0
F0014208: d252602e                 ldsh    [%o1+0x2E], %o1
F001420C: 9012209c                 bset    %lo(sub_F001449C), %o0
F0014210: d2242008                 st      %o1, [%l0+8]
F0014214: 40018b0b                 call    _calloutEntryAllocate
F0014218: 92102000                 mov     0, %o1
F001421C: d024200c                 st      %o0, [%l0+0xC]
F0014220: 90102001                 mov     1, %o0
F0014224: d0262178                 st      %o0, [%i0+0x178]
F0014228: 173c042d                 sethi   %hi(_pmsgbuf), %o3
F001422C: d402e08c                 ld      [%o3+%lo(_pmsgbuf)], %o2
F0014230: 1100018c                 sethi   0x63000, %o0
F0014234: d2028000                 ld      [%o2], %o1
F0014238: 90122061                 bset    0x61, %o0 ! 'a'
F001423C: 80a24008                 cmp     %o1, %o0
F0014240: 0280000e                 be      locret_F0014278
F0014244: b0102000                 mov     0, %i0
F0014248: d0228000                 st      %o0, [%o2]
F001424C: c022a008                 clr     [%o2+8]
F0014250: c022a004                 clr     [%o2+4]
F0014254: 92102000                 mov     0, %o1
F0014258: 9410000b                 mov     %o3, %o2
F001425C: d002a08c                 ld      [%o2+0x8C], %o0
F0014260: 90020009                 add     %o0, %o1, %o0
F0014264: 92026001                 inc     %o1
F0014268: 80a26ff3                 cmp     %o1, 0xFF3
F001426C: 08bffffc                 bleu    loc_F001425C
F0014270: c02a200c                 clrb    [%o0+0xC]
F0014274: b0102000                 mov     0, %i0
F0014278: 81c7e008                 ret
F001427C: 81e80000                 restore
