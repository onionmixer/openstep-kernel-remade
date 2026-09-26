F005E498: 9de3bf88                 save    %sp, -0x78, %sp
F005E49C: d2062004                 ld      [%i0+4], %o1
F005E4A0: d0060000                 ld      [%i0], %o0
F005E4A4: 80a20019                 cmp     %o0, %i1
F005E4A8: 02800013                 be      loc_F005E4F4
F005E4AC: d227bff4                 st      %o1, [%fp+var_C]
F005E4B0: 90100009                 mov     %o1, %o0
F005E4B4: a2062008                 add     %i0, 8, %l1
F005E4B8: 92100011                 mov     %l1, %o1
F005E4BC: d406200c                 ld      [%i0+0xC], %o2
F005E4C0: a0062010                 add     %i0, 0x10, %l0
F005E4C4: d8062014                 ld      [%i0+0x14], %o4
F005E4C8: 7fffff80                 call    sub_F005E2C8
F005E4CC: 96100010                 mov     %l0, %o3
F005E4D0: 90100019                 mov     %i1, %o0
F005E4D4: 9407bff4                 add     %fp, var_C, %o2
F005E4D8: 96100011                 mov     %l1, %o3
F005E4DC: 9806200c                 add     %i0, 0xC, %o4
F005E4E0: 9a100010                 mov     %l0, %o5
F005E4E4: d207bff4                 ld      [%fp+var_C], %o1
F005E4E8: 84062014                 add     %i0, 0x14, %g2
F005E4EC: 7fffff2e                 call    sub_F005E1A4
F005E4F0: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F005E4F4: d007bff4                 ld      [%fp+var_C], %o0
F005E4F8: d206200c                 ld      [%i0+0xC], %o1
F005E4FC: d0022018                 ld      [%o0+0x18], %o0
F005E500: d0224000                 st      %o0, [%o1]
F005E504: d007bff4                 ld      [%fp+var_C], %o0
F005E508: d2062014                 ld      [%i0+0x14], %o1
F005E50C: d002201c                 ld      [%o0+0x1C], %o0
F005E510: d0224000                 st      %o0, [%o1]
F005E514: 113c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o0
F005E518: d00222d8                 ld      [%o0+%lo(_ipc_tree_entry_zone)], %o0
F005E51C: 40006b2d                 call    _zfree
F005E520: d207bff4                 ld      [%fp+var_C], %o1
F005E524: d2062008                 ld      [%i0+8], %o1
F005E528: f2062010                 ld      [%i0+0x10], %i1
F005E52C: 80a26000                 cmp     %o1, 0
F005E530: 12800004                 bne     loc_F005E540
F005E534: d227bff4                 st      %o1, [%fp+var_C]
F005E538: 10800016                 ba      loc_F005E590
F005E53C: f227bff4                 st      %i1, [%fp+var_C]
F005E540: 80a66000                 cmp     %i1, 0
F005E544: 02800013                 be      loc_F005E590
F005E548: 90062014                 add     %i0, 0x14, %o0
F005E54C: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F005E550: 90103fff                 mov     -1, %o0
F005E554: 9407bff4                 add     %fp, var_C, %o2
F005E558: a2062008                 add     %i0, 8, %l1
F005E55C: 96100011                 mov     %l1, %o3
F005E560: 9806200c                 add     %i0, 0xC, %o4
F005E564: a0062010                 add     %i0, 0x10, %l0
F005E568: 7fffff0f                 call    sub_F005E1A4
F005E56C: 9a100010                 mov     %l0, %o5
F005E570: d007bff4                 ld      [%fp+var_C], %o0
F005E574: d406200c                 ld      [%i0+0xC], %o2
F005E578: 92100011                 mov     %l1, %o1
F005E57C: d8062014                 ld      [%i0+0x14], %o4
F005E580: 7fffff52                 call    sub_F005E2C8
F005E584: 96100010                 mov     %l0, %o3
F005E588: d007bff4                 ld      [%fp+var_C], %o0
F005E58C: f222201c                 st      %i1, [%o0+0x1C]
F005E590: d007bff4                 ld      [%fp+var_C], %o0
F005E594: 80a22000                 cmp     %o0, 0
F005E598: 02800008                 be      locret_F005E5B8
F005E59C: d0262004                 st      %o0, [%i0+4]
F005E5A0: d0022010                 ld      [%o0+0x10], %o0
F005E5A4: d0260000                 st      %o0, [%i0]
F005E5A8: 90062008                 add     %i0, 8, %o0
F005E5AC: d026200c                 st      %o0, [%i0+0xC]
F005E5B0: 90062010                 add     %i0, 0x10, %o0
F005E5B4: d0262014                 st      %o0, [%i0+0x14]
F005E5B8: 81c7e008                 ret
F005E5BC: 81e80000                 restore
