F007F538: 9de3bf90                 save    %sp, -0x70, %sp
F007F53C: d0062004                 ld      [%i0+4], %o0
F007F540: 80a22018                 cmp     %o0, 0x18
F007F544: 12800008                 bne     loc_F007F564
F007F548: 90103ed0                 mov     -0x130, %o0
F007F54C: d0060000                 ld      [%i0], %o0
F007F550: 23200000                 sethi   0x80000000, %l1
F007F554: 808a0011                 btst    %l1, %o0
F007F558: 02800005                 be      loc_F007F56C
F007F55C: 01000000                 nop
F007F560: 90103ed0                 mov     -0x130, %o0
F007F564: 10800029                 ba      locret_F007F608
F007F568: d026601c                 st      %o0, [%i1+0x1C]
F007F56C: 7fffa102                 call    _convert_port_to_space
F007F570: d0062008                 ld      [%i0+8], %o0
F007F574: a0100008                 mov     %o0, %l0
F007F578: 9206602c                 add     %i1, 0x2C, %o1 ! ','
F007F57C: 9407bff4                 add     %fp, var_C, %o2
F007F580: 9606603c                 add     %i1, 0x3C, %o3 ! '<'
F007F584: 7fff8e92                 call    _port_names
F007F588: 9807bff0                 add     %fp, var_10, %o4
F007F58C: d026601c                 st      %o0, [%i1+0x1C]
F007F590: 7fffa189                 call    _space_deallocate
F007F594: 90100010                 mov     %l0, %o0
F007F598: d006601c                 ld      [%i1+0x1C], %o0
F007F59C: 80a22000                 cmp     %o0, 0
F007F5A0: 1280001a                 bne     locret_F007F608
F007F5A4: 92102040                 mov     0x40, %o1 ! '@'
F007F5A8: d0064000                 ld      [%i1], %o0
F007F5AC: d2266004                 st      %o1, [%i1+4]
F007F5B0: 90120011                 bset    %l1, %o0
F007F5B4: d0264000                 st      %o0, [%i1]
F007F5B8: 113c0445                 sethi   %hi(dword_F0111404), %o0
F007F5BC: d2022004                 ld      [%o0+%lo(dword_F0111404)], %o1
F007F5C0: d2266020                 st      %o1, [%i1+0x20]
F007F5C4: 90122004                 bset    %lo(dword_F0111404), %o0
F007F5C8: d2022004                 ld      [%o0+4], %o1
F007F5CC: d2266024                 st      %o1, [%i1+0x24]
F007F5D0: d0022008                 ld      [%o0+8], %o0
F007F5D4: d207bff4                 ld      [%fp+var_C], %o1
F007F5D8: d0266028                 st      %o0, [%i1+0x28]
F007F5DC: d2266028                 st      %o1, [%i1+0x28]
F007F5E0: 113c0445                 sethi   %hi(dword_F0111410), %o0
F007F5E4: d2022010                 ld      [%o0+%lo(dword_F0111410)], %o1
F007F5E8: d2266030                 st      %o1, [%i1+0x30]
F007F5EC: 90122010                 bset    %lo(dword_F0111410), %o0
F007F5F0: d2022004                 ld      [%o0+4], %o1
F007F5F4: d2266034                 st      %o1, [%i1+0x34]
F007F5F8: d0022008                 ld      [%o0+8], %o0
F007F5FC: d207bff0                 ld      [%fp+var_10], %o1
F007F600: d0266038                 st      %o0, [%i1+0x38]
F007F604: d2266038                 st      %o1, [%i1+0x38]
F007F608: 81c7e008                 ret
F007F60C: 81e80000                 restore
