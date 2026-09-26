F006C2F4: 9de3bf98                 save    %sp, -0x68, %sp
F006C2F8: e0060000                 ld      [%i0], %l0
F006C2FC: d0142004                 lduh    [%l0+4], %o0
F006C300: 92022001                 add     %o0, 1, %o1
F006C304: 912a2010                 sll     %o0, 16, %o0
F006C308: 80a22000                 cmp     %o0, 0
F006C30C: 14800046                 bg      locret_F006C424
F006C310: d2342004                 sth     %o1, [%l0+4]
F006C314: d2042038                 ld      [%l0+0x38], %o1
F006C318: 11020000                 sethi   0x8000000, %o0
F006C31C: 808a4008                 btst    %o0, %o1
F006C320: 12800041                 bne     locret_F006C424
F006C324: 01000000                 nop
F006C328: 40000158                 call    _vmp_get
F006C32C: 90100010                 mov     %l0, %o0
F006C330: 90100018                 mov     %i0, %o0
F006C334: 92102000                 mov     0, %o1
F006C338: 40007c81                 call    _vnode_pager_setup
F006C33C: 94102001                 mov     1, %o2
F006C340: a2100008                 mov     %o0, %l1
F006C344: e2240000                 st      %l1, [%l0]
F006C348: 113c04f0                 sethi   %hi(_vm_alloc_lock), %o0
F006C34C: 7ffff29e                 call    _lock_write
F006C350: 90122200                 bset    %lo(_vm_alloc_lock), %o0
F006C354: 40006c01                 call    _vm_object_lookup
F006C358: 90100011                 mov     %l1, %o0
F006C35C: d0242024                 st      %o0, [%l0+0x24]
F006C360: 113c04f092122240         set     _vm_stat, %o1
F006C368: d002602c                 ld      [%o1+0x2C], %o0
F006C36C: 90022001                 inc     %o0
F006C370: d022602c                 st      %o0, [%o1+0x2C]
F006C374: d0042024                 ld      [%l0+0x24], %o0
F006C378: 80a22000                 cmp     %o0, 0
F006C37C: 3280000e                 bne,a   loc_F006C3B4
F006C380: d0026030                 ld      [%o1+0x30], %o0
F006C384: 40006907                 call    _vm_object_allocate
F006C388: 90102000                 mov     0, %o0
F006C38C: d0242024                 st      %o0, [%l0+0x24]
F006C390: 40006c3b                 call    _vm_object_enter
F006C394: 92100011                 mov     %l1, %o1
F006C398: d0042024                 ld      [%l0+0x24], %o0
F006C39C: 92100011                 mov     %l1, %o1
F006C3A0: 94102000                 mov     0, %o2
F006C3A4: 40006bdd                 call    _vm_object_setpager
F006C3A8: 96102000                 mov     0, %o3
F006C3AC: 10800005                 ba      loc_F006C3C0
F006C3B0: 113c04f0                 sethi   -0xFEC4000, %o0
F006C3B4: 90022001                 inc     %o0
F006C3B8: d0226030                 st      %o0, [%o1+0x30]
F006C3BC: 113c04f0                 sethi   -0xFEC4000, %o0
F006C3C0: 7ffff31d                 call    _lock_done
F006C3C4: 90122200                 bset    0x200, %o0
F006C3C8: c0242034                 clr     [%l0+0x34]
F006C3CC: 40000240                 call    _vnode_size
F006C3D0: 90100018                 mov     %i0, %o0
F006C3D4: d0242014                 st      %o0, [%l0+0x14]
F006C3D8: c0242008                 clr     [%l0+8]
F006C3DC: c024200c                 clr     [%l0+0xC]
F006C3E0: c0242010                 clr     [%l0+0x10]
F006C3E4: d0042038                 ld      [%l0+0x38], %o0
F006C3E8: 13020000                 sethi   0x8000000, %o1
F006C3EC: d4042014                 ld      [%l0+0x14], %o2
F006C3F0: 90120009                 bset    %o1, %o0
F006C3F4: 80a2a000                 cmp     %o2, 0
F006C3F8: 02800009                 be      loc_F006C41C
F006C3FC: d0242038                 st      %o0, [%l0+0x38]
F006C400: 113c043f                 sethi   %hi(_mfs_max_window), %o0
F006C404: d0022124                 ld      [%o0+%lo(_mfs_max_window)], %o0
F006C408: 80a28008                 cmp     %o2, %o0
F006C40C: 1a800004                 bcc     loc_F006C41C
F006C410: 90100018                 mov     %i0, %o0
F006C414: 4000004f                 call    _remap_vnode
F006C418: 92102000                 mov     0, %o1
F006C41C: 40000136                 call    _vmp_put
F006C420: 90100010                 mov     %l0, %o0
F006C424: 81c7e008                 ret
F006C428: 81e80000                 restore
