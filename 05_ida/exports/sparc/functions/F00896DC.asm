F00896DC: 9de3bf98                 save    %sp, -0x68, %sp
F00896E0: d206201c                 ld      [%i0+0x1C], %o1
F00896E4: 11000010                 sethi   0x4000, %o0
F00896E8: 808a4008                 btst    %o0, %o1
F00896EC: 0280003c                 be      locret_F00897DC
F00896F0: 01000000                 nop
F00896F4: 4000578f                 call    _pmap_clear_reference
F00896F8: d0062024                 ld      [%i0+0x24], %o0
F00896FC: d4060000                 ld      [%i0], %o2
F0089700: d2062004                 ld      [%i0+4], %o1
F0089704: 173c04f39012e008         set     _vm_page_queue_active, %o0
F008970C: 80a24008                 cmp     %o1, %o0
F0089710: 12800004                 bne     loc_F0089720
F0089714: d222a004                 st      %o1, [%o2+4]
F0089718: 10800003                 ba      loc_F0089724
F008971C: d422e008                 st      %o2, [%o3+8]
F0089720: d4224000                 st      %o2, [%o1]
F0089724: 113c04f0                 sethi   %hi(dword_F013C22C), %o0
F0089728: d202222c                 ld      [%o0+%lo(dword_F013C22C)], %o1
F008972C: 9412222c                 or      %o0, %lo(dword_F013C22C), %o2
F0089730: 9002bffc                 add     %o2, -4, %o0
F0089734: 80a24008                 cmp     %o1, %o0
F0089738: 32800003                 bne,a   loc_F0089744
F008973C: f0224000                 st      %i0, [%o1]
F0089740: f022bffc                 st      %i0, [%o2-4]
F0089744: d2262004                 st      %o1, [%i0+4]
F0089748: 113c04f090122228         set     _vm_page_queue_inactive, %o0
F0089750: d0260000                 st      %o0, [%i0]
F0089754: f0222004                 st      %i0, [%o0+4]
F0089758: d206201c                 ld      [%i0+0x1C], %o1
F008975C: 11000010                 sethi   0x4000, %o0
F0089760: 902a4008                 andn    %o1, %o0, %o0
F0089764: 13000020                 sethi   0x8000, %o1
F0089768: 90120009                 bset    %o1, %o0
F008976C: 173c04f2                 sethi   %hi(_vm_page_active_count), %o3
F0089770: d026201c                 st      %o0, [%i0+0x1C]
F0089774: d202e3f8                 ld      [%o3+%lo(_vm_page_active_count)], %o1
F0089778: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F008977C: d002a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o0
F0089780: 92027fff                 inc     -1, %o1
F0089784: d222e3f8                 st      %o1, [%o3+%lo(_vm_page_active_count)]
F0089788: 90022001                 inc     %o0
F008978C: d206201c                 ld      [%i0+0x1C], %o1
F0089790: 808a6400                 btst    0x400, %o1
F0089794: 02800009                 be      loc_F00897B8
F0089798: d022a220                 st      %o0, [%o2+%lo(_vm_page_inactive_count)]
F008979C: 40005754                 call    _pmap_is_modified
F00897A0: d0062024                 ld      [%i0+0x24], %o0
F00897A4: 80a22000                 cmp     %o0, 0
F00897A8: 02800005                 be      loc_F00897BC
F00897AC: d006201c                 ld      [%i0+0x1C], %o0
F00897B0: 900a3bff                 and     %o0, -0x401, %o0
F00897B4: d026201c                 st      %o0, [%i0+0x1C]
F00897B8: d006201c                 ld      [%i0+0x1C], %o0
F00897BC: 13000008                 sethi   0x2000, %o1
F00897C0: 922a0009                 andn    %o0, %o1, %o1
F00897C4: 9132200a                 srl     %o0, 10, %o0
F00897C8: 901a2001                 btog    1, %o0
F00897CC: 900a2001                 and     %o0, 1, %o0
F00897D0: 912a200d                 sll     %o0, 13, %o0
F00897D4: 92124008                 bset    %o0, %o1
F00897D8: d226201c                 st      %o1, [%i0+0x1C]
F00897DC: 81c7e008                 ret
F00897E0: 81e80000                 restore
