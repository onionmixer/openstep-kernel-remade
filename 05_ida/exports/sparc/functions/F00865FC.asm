F00865FC: 9de3bf98                 save    %sp, -0x68, %sp
F0086600: 90102058                 mov     0x58, %o0 ! 'X'
F0086604: 94102000                 mov     0, %o2
F0086608: 96102000                 mov     0, %o3
F008660C: 193c0446                 sethi   %hi(aObjects), %o4! "objects"
F0086610: 133c04d0                 sethi   %hi(_page_mask), %o1
F0086614: da0260d8                 ld      [%o1+%lo(_page_mask)], %o5
F0086618: 98132340                 bset    %lo(aObjects), %o4! "objects"
F008661C: 13000200                 sethi   0x80000, %o1
F0086620: 92034009                 add     %o5, %o1, %o1
F0086624: 7fffc645                 call    _zinit
F0086628: 922a400d                 bclr    %o5, %o1
F008662C: 133c04f6                 sethi   %hi(_vm_object_zone), %o1
F0086630: d0226098                 st      %o0, [%o1+%lo(_vm_object_zone)]
F0086634: 9010200c                 mov     0xC, %o0
F0086638: 13000064                 sethi   0x19000, %o1
F008663C: 94102000                 mov     0, %o2
F0086640: 96102000                 mov     0, %o3
F0086644: 193c0446                 sethi   %hi(aObjectHashZone), %o4! "object hash zone"
F0086648: 7fffc63c                 call    _zinit
F008664C: 98132348                 bset    %lo(aObjectHashZone), %o4! "object hash zone"
F0086650: 133c04f4                 sethi   %hi(_object_hash_zone), %o1
F0086654: d02263f8                 st      %o0, [%o1+%lo(_object_hash_zone)]
F0086658: 133c04f590126018         set     _vm_object_cached_list, %o0
F0086660: d0222004                 st      %o0, [%o0+4]
F0086664: d0226018                 st      %o0, [%o1+%lo(dword_F013D018)]
F0086668: 133c04f690126030         set     _vm_object_list, %o0
F0086670: d0222004                 st      %o0, [%o0+4]
F0086674: d0226030                 st      %o0, [%o1+%lo(dword_F013D030)]
F0086678: 113c04f5                 sethi   %hi(_vm_object_count), %o0
F008667C: c0222020                 clr     [%o0+%lo(_vm_object_count)]
F0086680: 113c04f5                 sethi   %hi(_vm_cache_lock), %o0
F0086684: c0222000                 clr     [%o0+%lo(_vm_cache_lock)]
F0086688: 113c04f6                 sethi   %hi(_vm_object_list_lock), %o0
F008668C: c0222038                 clr     [%o0+%lo(_vm_object_list_lock)]
F0086690: 92102000                 mov     0, %o1
F0086694: 113c04f590122030         set     _vm_object_hashtable, %o0
F008669C: d0222004                 st      %o0, [%o0+4]
F00866A0: d0220000                 st      %o0, [%o0]
F00866A4: 92026001                 inc     %o1
F00866A8: 80a2607f                 cmp     %o1, 0x7F
F00866AC: 04bffffc                 ble     loc_F008669C
F00866B0: 90022008                 inc     8, %o0
F00866B4: 113c04f0                 sethi   %hi(_mem_size), %o0
F00866B8: d2022108                 ld      [%o0+%lo(_mem_size)], %o1
F00866BC: 153c04f5                 sethi   %hi(_vm_cache_max), %o2
F00866C0: 93326014                 srl     %o1, 20, %o1
F00866C4: 912a6001                 sll     %o1, 1, %o0
F00866C8: 90020009                 add     %o0, %o1, %o0
F00866CC: 912a2003                 sll     %o0, 3, %o0
F00866D0: 90020009                 add     %o0, %o1, %o0
F00866D4: 912a2001                 sll     %o0, 1, %o0
F00866D8: 80a229c4                 cmp     %o0, 0x9C4
F00866DC: 04800004                 ble     loc_F00866EC
F00866E0: d022a008                 st      %o0, [%o2+%lo(_vm_cache_max)]
F00866E4: 901029c4                 mov     0x9C4, %o0
F00866E8: d022a008                 st      %o0, [%o2+%lo(_vm_cache_max)]
F00866EC: 173c04f69612e040         set     _vm_object_template, %o3
F00866F4: 90102001                 mov     1, %o0
F00866F8: d032e018                 sth     %o0, [%o3+0x18]
F00866FC: c032e01a                 clrh    [%o3+0x1A]
F0086700: c022e014                 clr     [%o3+0x14]
F0086704: c022e01c                 clr     [%o3+0x1C]
F0086708: c022e028                 clr     [%o3+0x28]
F008670C: c022e030                 clr     [%o3+0x30]
F0086710: c022e034                 clr     [%o3+0x34]
F0086714: c022e02c                 clr     [%o3+0x2C]
F0086718: c022e020                 clr     [%o3+0x20]
F008671C: c022e024                 clr     [%o3+0x24]
F0086720: c022e054                 clr     [%o3+0x54]
F0086724: 113c04f4                 sethi   %hi(_kernel_object), %o0
F0086728: 133c04f4921263a0         set     _kernel_object_store, %o1
F0086730: d2222340                 st      %o1, [%o0+%lo(_kernel_object)]
F0086734: 1103c000                 sethi   0xF000000, %o0
F0086738: d802e044                 ld      [%o3+0x44], %o4
F008673C: 15000004                 sethi   0x1000, %o2
F0086740: 942b000a                 andn    %o4, %o2, %o2
F0086744: d422e044                 st      %o2, [%o3+0x44]
F0086748: c032e044                 clrh    [%o3+0x44]
F008674C: d802e048                 ld      [%o3+0x48], %o4
F0086750: 15000020                 sethi   0x8000, %o2
F0086754: 942b000a                 andn    %o4, %o2, %o2
F0086758: d422e048                 st      %o2, [%o3+0x48]
F008675C: 94102002                 mov     2, %o2
F0086760: d432e048                 sth     %o2, [%o3+0x48]
F0086764: d802e044                 ld      [%o3+0x44], %o4
F0086768: 15000008                 sethi   0x2000, %o2
F008676C: 942b000a                 andn    %o4, %o2, %o2
F0086770: d422e044                 st      %o2, [%o3+0x44]
F0086774: 9412a800                 bset    0x800, %o2
F0086778: 40000014                 call    __vm_object_allocate
F008677C: d422e044                 st      %o2, [%o3+0x44]
F0086780: 113c04f4                 sethi   %hi(_vm_submap_object), %o0
F0086784: 133c04f6921260a0         set     _vm_submap_object_store, %o1
F008678C: d2222350                 st      %o1, [%o0+%lo(_vm_submap_object)]
F0086790: 4000000e                 call    __vm_object_allocate
F0086794: 1103c000                 sethi   0xF000000, %o0
F0086798: 81c7e008                 ret
F008679C: 81e80000                 restore
