F000A24C: 9de3bea8                 save    %sp, -0x158, %sp! object_name
F000A250: 253c04cf                 sethi   %hi(_active_u), %l2
F000A254: d404a1d8                 ld      [%l2+%lo(_active_u)], %o2
F000A258: d0028000                 ld      [%o2], %o0
F000A25C: d2022028                 ld      [%o0+0x28], %o1
F000A260: 11008000                 sethi   0x2000000, %o0
F000A264: 808a4008                 btst    %o0, %o1
F000A268: 12800058                 bne     loc_F000A3C8
F000A26C: a614a1d8                 or      %l2, %lo(_active_u), %l3
F000A270: d202a01c                 ld      [%o2+0x1C], %o1
F000A274: d0126006                 lduh    [%o1+6], %o0
F000A278: d0326002                 sth     %o0, [%o1+2]
F000A27C: d004a1d8                 ld      [%l2+%lo(_active_u)], %o0
F000A280: d202201c                 ld      [%o0+0x1C], %o1
F000A284: d4020000                 ld      [%o0], %o2
F000A288: d0126006                 lduh    [%o1+6], %o0
F000A28C: d032a02c                 sth     %o0, [%o2+0x2C]
F000A290: d004a1d8                 ld      [%l2+%lo(_active_u)], %o0
F000A294: d202201c                 ld      [%o0+0x1C], %o1
F000A298: d0126008                 lduh    [%o1+8], %o0
F000A29C: d0326004                 sth     %o0, [%o1+4]
F000A2A0: d004a1d8                 ld      [%l2+0x1D8], %o0
F000A2A4: 213c04d0                 sethi   %hi(_active_threads), %l0
F000A2A8: c02a225c                 clrb    [%o0+0x25C]
F000A2AC: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000A2B0: ea02200c                 ld      [%o0+0xC], %l5
F000A2B4: ee05600c                 ld      [%l5+0xC], %l7
F000A2B8: d004a1d8                 ld      [%l2+0x1D8], %o0
F000A2BC: d205e028                 ld      [%l7+0x28], %o1
F000A2C0: d0022280                 ld      [%o0+0x280], %o0
F000A2C4: 80a24008                 cmp     %o1, %o0
F000A2C8: 1a800122                 bcc     locret_F000A750
F000A2CC: b0102000                 mov     0, %i0
F000A2D0: 4001a534                 call    _task_halt
F000A2D4: 90100015                 mov     %l5, %o0
F000A2D8: 400246cd                 call    _pcb_synch
F000A2DC: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000A2E0: a207bfb8                 add     %fp, var_48, %l1
F000A2E4: d204e004                 ld      [%l3+4], %o1
F000A2E8: 90100011                 mov     %l1, %o0
F000A2EC: 40007c6a                 call    _vattr_null
F000A2F0: c02a6038                 clrb    [%o1+0x38]
F000A2F4: ac102001                 mov     1, %l6
F000A2F8: ec27bfb8                 st      %l6, [%fp+var_48]
F000A2FC: a81021a4                 mov     0x1A4, %l4
F000A300: d004a1d8                 ld      [%l2+0x1D8], %o0
F000A304: e837bfbc                 sth     %l4, [%fp+var_44]
F000A308: d2020000                 ld      [%o0], %o1
F000A30C: a007bf98                 add     %fp, var_68, %l0
F000A310: d4526030                 ldsh    [%o1+0x30], %o2
F000A314: 90100010                 mov     %l0, %o0! char *
F000A318: 133c042b                 sethi   %hi(aCoresCoreD), %o1! "/cores/core.%d"
F000A31C: 40002913                 call    _sprintf
F000A320: 92126208                 bset    %lo(aCoresCoreD), %o1! "/cores/core.%d"
F000A324: 90100010                 mov     %l0, %o0
F000A328: 92102001                 mov     1, %o1
F000A32C: 94100011                 mov     %l1, %o2
F000A330: 96102000                 mov     0, %o3
F000A334: da04a1d8                 ld      [%l2+0x1D8], %o5
F000A338: 98102080                 mov     0x80, %o4
F000A33C: c403601c                 ld      [%o5+0x1C], %g2
F000A340: a007bf44                 add     %fp, var_BC, %l0
F000A344: 9a100010                 mov     %l0, %o5
F000A348: 40007aab                 call    _vn_create
F000A34C: c423a05c                 st      %g2, [%sp+0x158+var_FC]
F000A350: d204e004                 ld      [%l3+4], %o1
F000A354: d02a6038                 stb     %o0, [%o1+0x38]
F000A358: d204e004                 ld      [%l3+4], %o1
F000A35C: d04a6038                 ldsb    [%o1+0x38], %o0
F000A360: 80a22000                 cmp     %o0, 0
F000A364: 0280001b                 be      loc_F000A3D0
F000A368: d057bfcc                 ldsh    [%fp+var_34], %o0
F000A36C: c02a6038                 clrb    [%o1+0x38]
F000A370: 40007c49                 call    _vattr_null
F000A374: 90100011                 mov     %l1, %o0
F000A378: ec27bfb8                 st      %l6, [%fp+var_48]
F000A37C: e837bfbc                 sth     %l4, [%fp+var_44]
F000A380: 113c042b90122218         set     aCore, %o0! "core"
F000A388: 92102001                 mov     1, %o1
F000A38C: 94100011                 mov     %l1, %o2
F000A390: da04a1d8                 ld      [%l2+0x1D8], %o5
F000A394: 96102000                 mov     0, %o3
F000A398: c403601c                 ld      [%o5+0x1C], %g2
F000A39C: 98102080                 mov     0x80, %o4
F000A3A0: 9a100010                 mov     %l0, %o5! infoCnt
F000A3A4: 40007a94                 call    _vn_create
F000A3A8: c423a05c                 st      %g2, [%sp+0x158+var_FC]
F000A3AC: d204e004                 ld      [%l3+4], %o1
F000A3B0: d02a6038                 stb     %o0, [%o1+0x38]
F000A3B4: d004e004                 ld      [%l3+4], %o0
F000A3B8: d04a2038                 ldsb    [%o0+0x38], %o0
F000A3BC: 80a22000                 cmp     %o0, 0
F000A3C0: 02800004                 be      loc_F000A3D0
F000A3C4: d057bfcc                 ldsh    [%fp+var_34], %o0
F000A3C8: 108000e2                 ba      locret_F000A750
F000A3CC: b0102000                 mov     0, %i0
F000A3D0: 80a22001                 cmp     %o0, 1
F000A3D4: 128000d8                 bne     loc_F000A734
F000A3D8: a010200e                 mov     0xE, %l0
F000A3DC: a007bfb8                 add     %fp, var_48, %l0
F000A3E0: 40007c2d                 call    _vattr_null
F000A3E4: 90100010                 mov     %l0, %o0
F000A3E8: 233c04cf                 sethi   %hi(_active_u), %l1
F000A3EC: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F000A3F0: c027bfd0                 clr     [%fp+var_30]
F000A3F4: d402201c                 ld      [%o0+0x1C], %o2
F000A3F8: d007bf44                 ld      [%fp+var_BC], %o0
F000A3FC: d602201c                 ld      [%o0+0x1C], %o3
F000A400: d602e018                 ld      [%o3+0x18], %o3
F000A404: 9fc2c000                 call    %o3
F000A408: 92100010                 mov     %l0, %o1
F000A40C: 90102014                 mov     0x14, %o0
F000A410: d027bf40                 st      %o0, [%fp+var_C0]
F000A414: d40461d8                 ld      [%l1+%lo(_active_u)], %o2
F000A418: 92102000                 mov     0, %o1
F000A41C: d012a240                 lduh    [%o2+0x240], %o0
F000A420: a007bf48                 add     %fp, var_B8, %l0
F000A424: 90122008                 bset    8, %o0
F000A428: d032a240                 sth     %o0, [%o2+0x240]
F000A42C: e8056024                 ld      [%l5+0x24], %l4
F000A430: 9607bf40                 add     %fp, var_C0, %o3
F000A434: e605e01c                 ld      [%l7+0x1C], %l3
F000A438: 113c04d0                 sethi   %hi(_active_threads), %o0
F000A43C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000A440: 400245cd                 call    _thread_getstatus
F000A444: 94100010                 mov     %l0, %o2
F000A448: 80a22000                 cmp     %o0, 0
F000A44C: 02800004                 be      loc_F000A45C
F000A450: 113c042b                 sethi   %hi(aCoreFlavorList), %o0! "core flavor list"
F000A454: 40002b47                 call    _panic
F000A458: 90122220                 bset    %lo(aCoreFlavorList), %o0! "core flavor list"
F000A45C: ac102000                 mov     0, %l6
F000A460: d007bf40                 ld      [%fp+var_C0], %o0
F000A464: b0102000                 mov     0, %i0
F000A468: 91322001                 srl     %o0, 1, %o0
F000A46C: 80a60008                 cmp     %i0, %o0
F000A470: 1a80000c                 bcc     loc_F000A4A0
F000A474: d027bf40                 st      %o0, [%fp+var_C0]
F000A478: 96100008                 mov     %o0, %o3
F000A47C: 94100010                 mov     %l0, %o2
F000A480: b0062001                 inc     %i0
F000A484: 80a6000b                 cmp     %i0, %o3
F000A488: d002a004                 ld      [%o2+4], %o0
F000A48C: 9205a008                 add     %l6, 8, %o1
F000A490: 912a2002                 sll     %o0, 2, %o0
F000A494: ac024008                 add     %o1, %o0, %l6
F000A498: 0abffffa                 bcs     loc_F000A480
F000A49C: 9402a008                 inc     8, %o2
F000A4A0: 90100016                 mov     %l6, %o0
F000A4A4: 92100014                 mov     %l4, %o1
F000A4A8: a12ce003                 sll     %l3, 3, %l0
F000A4AC: a0240013                 sub     %l0, %l3, %l0
F000A4B0: a0050010                 add     %l4, %l0, %l0
F000A4B4: 7ffff013                 call    _umul
F000A4B8: a12c2003                 sll     %l0, 3, %l0
F000A4BC: 9207bf3c                 add     %fp, var_C4, %o1
F000A4C0: a0040008                 add     %l0, %o0, %l0
F000A4C4: b404201c                 add     %l0, 0x1C, %i2
F000A4C8: 9410001a                 mov     %i2, %o2
F000A4CC: 113c04d1                 sethi   %hi(_kernel_map), %o0
F000A4D0: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F000A4D4: 4001e4cc                 call    _kmem_alloc_wired
F000A4D8: a410201c                 mov     0x1C, %l2
F000A4DC: c027bf38                 clr     [%fp+var_C8]
F000A4E0: 80a4e000                 cmp     %l3, 0
F000A4E4: 113fbb7e901222ce         set     -0x1120532, %o0
F000A4EC: 133c04d1                 sethi   %hi(_machine_slot), %o1
F000A4F0: d407bf3c                 ld      [%fp+var_C4], %o2
F000A4F4: 92126360                 bset    %lo(_machine_slot), %o1
F000A4F8: d0228000                 st      %o0, [%o2]
F000A4FC: d8026004                 ld      [%o1+4], %o4
F000A500: 113c04d0                 sethi   %hi(_page_mask), %o0
F000A504: d60220d8                 ld      [%o0+%lo(_page_mask)], %o3
F000A508: d822a004                 st      %o4, [%o2+4]
F000A50C: 9006800b                 add     %i2, %o3, %o0
F000A510: a22a000b                 andn    %o0, %o3, %l1
F000A514: d2026008                 ld      [%o1+8], %o1
F000A518: 90102004                 mov     4, %o0
F000A51C: d222a008                 st      %o1, [%o2+8]
F000A520: d022a00c                 st      %o0, [%o2+0xC]
F000A524: 9004c014                 add     %l3, %l4, %o0
F000A528: d022a010                 st      %o0, [%o2+0x10]
F000A52C: 0480003e                 ble     loc_F000A624
F000A530: e022a014                 st      %l0, [%o2+0x14]
F000A534: a0102001                 mov     1, %l0
F000A538: 9007bf24                 add     %fp, var_DC, %o0
F000A53C: d023a05c                 st      %o0, [%sp+0x158+var_FC]
F000A540: 9007bf20                 add     %fp, var_E0, %o0
F000A544: d023a060                 st      %o0, [%sp+0x158+var_F8]
F000A548: 9007bf1c                 add     %fp, var_E4, %o0
F000A54C: d023a064                 st      %o0, [%sp+0x158+var_F4]
F000A550: 90100017                 mov     %l7, %o0! target_task
F000A554: 9207bf38                 add     %fp, var_C8, %o1! address
F000A558: 9407bf34                 add     %fp, size, %o2! size
F000A55C: 9607bf30                 add     %fp, new_protection, %o3! flavor
F000A560: 9807bf2c                 add     %fp, var_D4, %o4! info
F000A564: 4001eeeb                 call    _vm_region
F000A568: 9a07bf28                 add     %fp, var_D8, %o5
F000A56C: 80a22003                 cmp     %o0, 3
F000A570: 0280002d                 be      loc_F000A624
F000A574: d007bf3c                 ld      [%fp+var_C4], %o0
F000A578: d607bf38                 ld      [%fp+var_C8], %o3
F000A57C: d407bf34                 ld      [%fp+size], %o2! size
F000A580: 92102038                 mov     0x38, %o1 ! '8'
F000A584: d807bf30                 ld      [%fp+new_protection], %o4! new_protection
F000A588: e0220012                 st      %l0, [%o0+%l2]
F000A58C: 90020012                 add     %o0, %l2, %o0
F000A590: d2222004                 st      %o1, [%o0+4]
F000A594: d6222018                 st      %o3, [%o0+0x18]
F000A598: d422201c                 st      %o2, [%o0+0x1C]
F000A59C: e2222020                 st      %l1, [%o0+0x20]
F000A5A0: d4222024                 st      %o2, [%o0+0x24]
F000A5A4: d822202c                 st      %o4, [%o0+0x2C]
F000A5A8: c0222030                 clr     [%o0+0x30]
F000A5AC: d207bf2c                 ld      [%fp+var_D4], %o1
F000A5B0: 808b2001                 btst    1, %o4
F000A5B4: 12800007                 bne     loc_F000A5D0
F000A5B8: d2222028                 st      %o1, [%o0+0x28]
F000A5BC: 90100017                 mov     %l7, %o0! target_task
F000A5C0: 9210000b                 mov     %o3, %o1! address
F000A5C4: 96102000                 mov     0, %o3! set_maximum
F000A5C8: 400200dd                 call    _vm_protect
F000A5CC: 98132001                 bset    1, %o4
F000A5D0: d007bf2c                 ld      [%fp+var_D4], %o0
F000A5D4: 808a2001                 btst    1, %o0
F000A5D8: 0280000a                 be      loc_F000A600
F000A5DC: d207bf44                 ld      [%fp+var_BC], %o1
F000A5E0: 90102001                 mov     1, %o0
F000A5E4: d407bf38                 ld      [%fp+var_C8], %o2
F000A5E8: 98100011                 mov     %l1, %o4
F000A5EC: d607bf34                 ld      [%fp+size], %o3
F000A5F0: 9a102000                 mov     0, %o5
F000A5F4: e023a05c                 st      %l0, [%sp+0x158+var_FC]
F000A5F8: 40007917                 call    _vn_rdwr
F000A5FC: c023a060                 clr     [%sp+0x158+var_F8]
F000A600: a404a038                 inc     0x38, %l2 ! '8'
F000A604: a604ffff                 inc     -1, %l3
F000A608: d207bf34                 ld      [%fp+size], %o1
F000A60C: 80a4e000                 cmp     %l3, 0
F000A610: d007bf38                 ld      [%fp+var_C8], %o0
F000A614: a2044009                 add     %l1, %o1, %l1
F000A618: 90020009                 add     %o0, %o1, %o0
F000A61C: 14bfffc7                 bg      loc_F000A538
F000A620: d027bf38                 st      %o0, [%fp+var_C8]
F000A624: d0054000                 ld      [%l5], %o0
F000A628: 80a22000                 cmp     %o0, 0
F000A62C: 12bffffe                 bne     loc_F000A624
F000A630: 01000000                 nop
F000A634: 4002321d                 call    _simple_lock_try
F000A638: 90100015                 mov     %l5, %o0
F000A63C: 80a22000                 cmp     %o0, 0
F000A640: 02bffff9                 be      loc_F000A624
F000A644: 80a52000                 cmp     %l4, 0
F000A648: 0480002a                 ble     loc_F000A6F0
F000A64C: e605601c                 ld      [%l5+0x1C], %l3
F000A650: b6102004                 mov     4, %i3
F000A654: b205a008                 add     %l6, 8, %i1
F000A658: ae07bff8                 add     %fp, var_8, %l7
F000A65C: ac07bf48                 add     %fp, var_B8, %l6
F000A660: d007bf3c                 ld      [%fp+var_C4], %o0
F000A664: b0102000                 mov     0, %i0
F000A668: f6220012                 st      %i3, [%o0+%l2]
F000A66C: 90020012                 add     %o0, %l2, %o0
F000A670: f2222004                 st      %i1, [%o0+4]
F000A674: d007bf40                 ld      [%fp+var_C0], %o0
F000A678: 80a60008                 cmp     %i0, %o0
F000A67C: 1a800019                 bcc     loc_F000A6E0
F000A680: a404a008                 inc     8, %l2
F000A684: a0100016                 mov     %l6, %l0
F000A688: a2100017                 mov     %l7, %l1
F000A68C: 90100013                 mov     %l3, %o0
F000A690: d407bf3c                 ld      [%fp+var_C4], %o2
F000A694: 96042004                 add     %l0, 4, %o3
F000A698: d2047f50                 ld      [%l1-0xB0], %o1
F000A69C: b0062001                 inc     %i0
F000A6A0: d2228012                 st      %o1, [%o2+%l2]
F000A6A4: 98028012                 add     %o2, %l2, %o4
F000A6A8: d2047f54                 ld      [%l1-0xAC], %o1
F000A6AC: a404a008                 inc     8, %l2
F000A6B0: d2232004                 st      %o1, [%o4+4]
F000A6B4: d2040000                 ld      [%l0], %o1
F000A6B8: 4002452f                 call    _thread_getstatus
F000A6BC: 94028012                 add     %o2, %l2, %o2
F000A6C0: d0042004                 ld      [%l0+4], %o0
F000A6C4: a2046008                 inc     8, %l1
F000A6C8: 912a2002                 sll     %o0, 2, %o0
F000A6CC: a4048008                 add     %l2, %o0, %l2
F000A6D0: d007bf40                 ld      [%fp+var_C0], %o0
F000A6D4: 80a60008                 cmp     %i0, %o0
F000A6D8: 0abfffed                 bcs     loc_F000A68C
F000A6DC: a0042008                 inc     8, %l0
F000A6E0: a8053fff                 inc     -1, %l4
F000A6E4: 80a52000                 cmp     %l4, 0
F000A6E8: 14bfffde                 bg      loc_F000A660
F000A6EC: e604e010                 ld      [%l3+0x10], %l3
F000A6F0: c0254000                 clr     [%l5]
F000A6F4: 90102001                 mov     1, %o0
F000A6F8: 9610001a                 mov     %i2, %o3
F000A6FC: 98102000                 mov     0, %o4
F000A700: d207bf44                 ld      [%fp+var_BC], %o1
F000A704: 9a102001                 mov     1, %o5
F000A708: d407bf3c                 ld      [%fp+var_C4], %o2
F000A70C: 84102001                 mov     1, %g2
F000A710: c423a05c                 st      %g2, [%sp+0x158+var_FC]
F000A714: 400078d0                 call    _vn_rdwr
F000A718: c023a060                 clr     [%sp+0x158+var_F8]
F000A71C: a0100008                 mov     %o0, %l0
F000A720: 113c04d1                 sethi   %hi(_kernel_map), %o0
F000A724: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F000A728: d207bf3c                 ld      [%fp+var_C4], %o1
F000A72C: 4001e456                 call    _kmem_free
F000A730: 9410001a                 mov     %i2, %o2
F000A734: 4000790c                 call    _vn_rele
F000A738: d007bf44                 ld      [%fp+var_BC], %o0
F000A73C: 80a00010                 cmp     %g0, %l0
F000A740: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000A744: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F000A748: b0603fff                 subc    %g0, -1, %i0
F000A74C: e02a2038                 stb     %l0, [%o0+0x38]
F000A750: 81c7e008                 ret
F000A754: 81e80000                 restore
