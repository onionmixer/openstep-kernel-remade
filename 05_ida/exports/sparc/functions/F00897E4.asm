F00897E4: 9de3bf98                 save    %sp, -0x68, %sp
F00897E8: d206201c                 ld      [%i0+0x1C], %o1
F00897EC: 11000020                 sethi   0x8000, %o0
F00897F0: 808a4008                 btst    %o0, %o1
F00897F4: 02800014                 be      loc_F0089844
F00897F8: 173c04f0                 sethi   %hi(_vm_page_queue_inactive), %o3
F00897FC: d4060000                 ld      [%i0], %o2
F0089800: d2062004                 ld      [%i0+4], %o1
F0089804: 9012e228                 or      %o3, %lo(_vm_page_queue_inactive), %o0
F0089808: 80a24008                 cmp     %o1, %o0
F008980C: 12800004                 bne     loc_F008981C
F0089810: d222a004                 st      %o1, [%o2+4]
F0089814: 10800003                 ba      loc_F0089820
F0089818: d422e228                 st      %o2, [%o3+%lo(_vm_page_queue_inactive)]
F008981C: d4224000                 st      %o2, [%o1]
F0089820: 133c04f0                 sethi   %hi(_vm_page_inactive_count), %o1
F0089824: d0026220                 ld      [%o1+%lo(_vm_page_inactive_count)], %o0
F0089828: 90023fff                 inc     -1, %o0
F008982C: d0226220                 st      %o0, [%o1+%lo(_vm_page_inactive_count)]
F0089830: d206201c                 ld      [%i0+0x1C], %o1
F0089834: 11000020                 sethi   0x8000, %o0
F0089838: 902a4008                 andn    %o1, %o0, %o0
F008983C: d026201c                 st      %o0, [%i0+0x1C]
F0089840: d206201c                 ld      [%i0+0x1C], %o1
F0089844: 11000004                 sethi   0x1000, %o0
F0089848: 808a4008                 btst    %o0, %o1
F008984C: 02800013                 be      loc_F0089898
F0089850: 173c04f3                 sethi   %hi(_vm_page_queue_free), %o3
F0089854: d4060000                 ld      [%i0], %o2
F0089858: d2062004                 ld      [%i0+4], %o1
F008985C: 9012e010                 or      %o3, %lo(_vm_page_queue_free), %o0
F0089860: 80a24008                 cmp     %o1, %o0
F0089864: 12800004                 bne     loc_F0089874
F0089868: d222a004                 st      %o1, [%o2+4]
F008986C: 10800003                 ba      loc_F0089878
F0089870: d422e010                 st      %o2, [%o3+%lo(_vm_page_queue_free)]
F0089874: d4224000                 st      %o2, [%o1]
F0089878: 133c04f3                 sethi   %hi(_vm_page_free_count), %o1
F008987C: d0026000                 ld      [%o1+%lo(_vm_page_free_count)], %o0
F0089880: 90023fff                 inc     -1, %o0
F0089884: d0226000                 st      %o0, [%o1+%lo(_vm_page_free_count)]
F0089888: d206201c                 ld      [%i0+0x1C], %o1
F008988C: 11000004                 sethi   0x1000, %o0
F0089890: 902a4008                 andn    %o1, %o0, %o0
F0089894: d026201c                 st      %o0, [%i0+0x1C]
F0089898: d016201c                 lduh    [%i0+0x1C], %o0
F008989C: 80a22000                 cmp     %o0, 0
F00898A0: 1280001d                 bne     locret_F0089914
F00898A4: 11000010                 sethi   0x4000, %o0
F00898A8: d206201c                 ld      [%i0+0x1C], %o1
F00898AC: 808a4008                 btst    %o0, %o1
F00898B0: 02800004                 be      loc_F00898C0
F00898B4: 113c0447                 sethi   %hi(aVmPageActivate), %o0! "vm_page_activate: already active"
F00898B8: 7ffe2e2e                 call    _panic
F00898BC: 901221d0                 bset    %lo(aVmPageActivate), %o0! "vm_page_activate: already active"
F00898C0: 113c04f3                 sethi   %hi(dword_F013CC0C), %o0
F00898C4: d202200c                 ld      [%o0+%lo(dword_F013CC0C)], %o1
F00898C8: 9412200c                 or      %o0, %lo(dword_F013CC0C), %o2
F00898CC: 9002bffc                 add     %o2, -4, %o0
F00898D0: 80a24008                 cmp     %o1, %o0
F00898D4: 32800003                 bne,a   loc_F00898E0
F00898D8: f0224000                 st      %i0, [%o1]
F00898DC: f022bffc                 st      %i0, [%o2-4]
F00898E0: d2262004                 st      %o1, [%i0+4]
F00898E4: 113c04f390122008         set     _vm_page_queue_active, %o0
F00898EC: d0260000                 st      %o0, [%i0]
F00898F0: f0222004                 st      %i0, [%o0+4]
F00898F4: d206201c                 ld      [%i0+0x1C], %o1
F00898F8: 11000010                 sethi   0x4000, %o0
F00898FC: 92124008                 bset    %o0, %o1
F0089900: 153c04f2                 sethi   %hi(_vm_page_active_count), %o2
F0089904: d002a3f8                 ld      [%o2+%lo(_vm_page_active_count)], %o0
F0089908: d226201c                 st      %o1, [%i0+0x1C]
F008990C: 90022001                 inc     %o0
F0089910: d022a3f8                 st      %o0, [%o2+%lo(_vm_page_active_count)]
F0089914: 81c7e008                 ret
F0089918: 81e80000                 restore
