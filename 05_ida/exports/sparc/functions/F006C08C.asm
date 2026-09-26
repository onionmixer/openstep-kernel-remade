F006C08C: 9de3bf90                 save    %sp, -0x70, %sp
F006C090: 133c04f090126218         set     _vm_info_queue, %o0
F006C098: d0222004                 st      %o0, [%o0+4]
F006C09C: d0226218                 st      %o0, [%o1+0x218]
F006C0A0: 113c04f0                 sethi   %hi(_vm_info_lock_data), %o0
F006C0A4: c0222210                 clr     [%o0+%lo(_vm_info_lock_data)]
F006C0A8: 113c04f0901221c0         set     _mfs_alloc_lock_data, %o0
F006C0B0: 7ffff316                 call    _lock_init
F006C0B4: 92102001                 mov     1, %o1
F006C0B8: 113c04f0                 sethi   %hi(_mfs_alloc_wanted), %o0
F006C0BC: c02221d0                 clr     [%o0+%lo(_mfs_alloc_wanted)]
F006C0C0: 9207bff4                 add     %fp, var_C, %o1
F006C0C4: 9407bff0                 add     %fp, var_10, %o2
F006C0C8: 113c04d1                 sethi   %hi(_kernel_map), %o0
F006C0CC: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006C0D0: 233c043f                 sethi   %hi(_mfs_map_size), %l1
F006C0D4: d6046120                 ld      [%l1+%lo(_mfs_map_size)], %o3
F006C0D8: 40005e3e                 call    _kmem_suballoc
F006C0DC: 98102001                 mov     1, %o4
F006C0E0: 133c04f0                 sethi   %hi(_mfs_map), %o1
F006C0E4: d02261d8                 st      %o0, [%o1+%lo(_mfs_map)]
F006C0E8: 113c04f0                 sethi   %hi(dword_F013C050), %o0
F006C0EC: d0022050                 ld      [%o0+%lo(dword_F013C050)], %o0
F006C0F0: 15004000                 sethi   0x1000000, %o2
F006C0F4: 92100008                 mov     %o0, %o1
F006C0F8: 90102000                 mov     0, %o0
F006C0FC: 80a2400a                 cmp     %o1, %o2
F006C100: 08800003                 bleu    loc_F006C10C
F006C104: d2246120                 st      %o1, [%l1+%lo(_mfs_map_size)]
F006C108: d4246120                 st      %o2, [%l1+%lo(_mfs_map_size)]
F006C10C: 213c043f                 sethi   %hi(_mfs_max_window), %l0
F006C110: d0042124                 ld      [%l0+%lo(_mfs_max_window)], %o0
F006C114: 80a22000                 cmp     %o0, 0
F006C118: 12800007                 bne     loc_F006C134
F006C11C: d2042124                 ld      [%l0+%lo(_mfs_max_window)], %o1
F006C120: d0046120                 ld      [%l1+0x120], %o0
F006C124: 7ffe6937                 call    _udiv
F006C128: 92102014                 mov     0x14, %o1
F006C12C: d0242124                 st      %o0, [%l0+%lo(_mfs_max_window)]
F006C130: d2042124                 ld      [%l0+%lo(_mfs_max_window)], %o1
F006C134: 1100003f901223ff         set     0xFFFF, %o0
F006C13C: 80a24008                 cmp     %o1, %o0
F006C140: 18800003                 bgu     loc_F006C14C
F006C144: 11000040                 sethi   0x10000, %o0
F006C148: d0242124                 st      %o0, [%l0+0x124]
F006C14C: 9010203c                 mov     0x3C, %o0 ! '<'
F006C150: 13000249921263c0         set     0x927C0, %o1
F006C158: 15000008                 sethi   0x2000, %o2
F006C15C: 96102000                 mov     0, %o3
F006C160: 193c043f                 sethi   %hi(aVmInfoZone), %o4! "vm_info zone"
F006C164: 40002f75                 call    _zinit
F006C168: 98132130                 bset    %lo(aVmInfoZone), %o4! "vm_info zone"
F006C16C: 133c04d2                 sethi   %hi(_vm_info_zone), %o1
F006C170: d0226250                 st      %o0, [%o1+%lo(_vm_info_zone)]
F006C174: 81c7e008                 ret
F006C178: 81e80000                 restore
