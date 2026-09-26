F000F55C: 9de3bf98                 save    %sp, -0x68, %sp
F000F560: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000F564: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F000F568: e0022024                 ld      [%o0+0x24], %l0
F000F56C: d0040000                 ld      [%l0], %o0
F000F570: 80a23fff                 cmp     %o0, -1
F000F574: 12800006                 bne     loc_F000F58C
F000F578: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F000F57C: d0027ffc                 ld      [%o1-4], %o0
F000F580: d002201c                 ld      [%o0+0x1C], %o0
F000F584: 10800003                 ba      loc_F000F590
F000F588: e6122008                 lduh    [%o0+8], %l3
F000F58C: a6100008                 mov     %o0, %l3
F000F590: 113c04cf                 sethi   %hi(_active_u), %o0
F000F594: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F598: d602201c                 ld      [%o0+0x1C], %o3
F000F59C: 912ce010                 sll     %l3, 16, %o0
F000F5A0: d252e008                 ldsh    [%o3+8], %o1
F000F5A4: 953a2010                 sra     %o0, 16, %o2
F000F5A8: 80a2400a                 cmp     %o1, %o2
F000F5AC: 2280000c                 be,a    loc_F000F5DC
F000F5B0: d0042004                 ld      [%l0+4], %o0
F000F5B4: d052e004                 ldsh    [%o3+4], %o0
F000F5B8: 80a2000a                 cmp     %o0, %o2
F000F5BC: 22800008                 be,a    loc_F000F5DC
F000F5C0: d0042004                 ld      [%l0+4], %o0
F000F5C4: 400000ea                 call    _suser
F000F5C8: 01000000                 nop
F000F5CC: 80a22000                 cmp     %o0, 0
F000F5D0: 02800039                 be      locret_F000F6B4
F000F5D4: 01000000                 nop
F000F5D8: d0042004                 ld      [%l0+4], %o0
F000F5DC: 80a23fff                 cmp     %o0, -1
F000F5E0: 12800006                 bne     loc_F000F5F8
F000F5E4: a4100008                 mov     %o0, %l2
F000F5E8: 113c04cf                 sethi   %hi(_active_u), %o0
F000F5EC: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F5F0: d002201c                 ld      [%o0+0x1C], %o0
F000F5F4: e4122004                 lduh    [%o0+4], %l2
F000F5F8: 113c04cf                 sethi   %hi(_active_u), %o0
F000F5FC: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F600: d602201c                 ld      [%o0+0x1C], %o3
F000F604: 912ca010                 sll     %l2, 16, %o0
F000F608: d252e008                 ldsh    [%o3+8], %o1
F000F60C: 953a2010                 sra     %o0, 16, %o2
F000F610: 80a2400a                 cmp     %o1, %o2
F000F614: 0280000b                 be      loc_F000F640
F000F618: 233c04cf                 sethi   %hi(_active_u), %l1
F000F61C: d052e004                 ldsh    [%o3+4], %o0
F000F620: 80a2000a                 cmp     %o0, %o2
F000F624: 02800008                 be      loc_F000F644
F000F628: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F000F62C: 400000d0                 call    _suser
F000F630: 01000000                 nop
F000F634: 80a22000                 cmp     %o0, 0
F000F638: 0280001f                 be      locret_F000F6B4
F000F63C: 01000000                 nop
F000F640: d00461d8                 ld      [%l1+0x1D8], %o0
F000F644: 400165e0                 call    _lock_write
F000F648: 90022020                 inc     0x20, %o0 ! ' '
F000F64C: d00461d8                 ld      [%l1+0x1D8], %o0
F000F650: 40000108                 call    _crcopy
F000F654: d002201c                 ld      [%o0+0x1C], %o0
F000F658: d20461d8                 ld      [%l1+0x1D8], %o1
F000F65C: d022601c                 st      %o0, [%o1+0x1C]
F000F660: d00461d8                 ld      [%l1+0x1D8], %o0
F000F664: d002201c                 ld      [%o0+0x1C], %o0
F000F668: 932ce010                 sll     %l3, 16, %o1
F000F66C: d0522008                 ldsh    [%o0+8], %o0
F000F670: a13a6010                 sra     %o1, 16, %l0
F000F674: 80a20010                 cmp     %o0, %l0
F000F678: 2280000a                 be,a    loc_F000F6A0
F000F67C: d00461d8                 ld      [%l1+0x1D8], %o0
F000F680: 4000005c                 call    _leavegroup
F000F684: 01000000                 nop
F000F688: 4000007d                 call    _entergroup
F000F68C: 90100010                 mov     %l0, %o0
F000F690: d00461d8                 ld      [%l1+0x1D8], %o0
F000F694: d002201c                 ld      [%o0+0x1C], %o0
F000F698: e6322008                 sth     %l3, [%o0+8]
F000F69C: d00461d8                 ld      [%l1+0x1D8], %o0
F000F6A0: d002201c                 ld      [%o0+0x1C], %o0
F000F6A4: e4322004                 sth     %l2, [%o0+4]
F000F6A8: d00461d8                 ld      [%l1+0x1D8], %o0
F000F6AC: 40016662                 call    _lock_done
F000F6B0: 90022020                 inc     0x20, %o0 ! ' '
F000F6B4: 81c7e008                 ret
F000F6B8: 81e80000                 restore
