F00893A8: 9de3bf98                 save    %sp, -0x68, %sp
F00893AC: d206201c                 ld      [%i0+0x1C], %o1
F00893B0: 11000010                 sethi   0x4000, %o0
F00893B4: 808a4008                 btst    %o0, %o1
F00893B8: 02800014                 be      loc_F0089408
F00893BC: 173c04f3                 sethi   %hi(_vm_page_queue_active), %o3
F00893C0: d4060000                 ld      [%i0], %o2
F00893C4: d2062004                 ld      [%i0+4], %o1
F00893C8: 9012e008                 or      %o3, %lo(_vm_page_queue_active), %o0
F00893CC: 80a24008                 cmp     %o1, %o0
F00893D0: 12800004                 bne     loc_F00893E0
F00893D4: d222a004                 st      %o1, [%o2+4]
F00893D8: 10800003                 ba      loc_F00893E4
F00893DC: d422e008                 st      %o2, [%o3+%lo(_vm_page_queue_active)]
F00893E0: d4224000                 st      %o2, [%o1]
F00893E4: 13000010                 sethi   0x4000, %o1
F00893E8: d006201c                 ld      [%i0+0x1C], %o0
F00893EC: 153c04f2                 sethi   %hi(_vm_page_active_count), %o2
F00893F0: 922a0009                 andn    %o0, %o1, %o1
F00893F4: d002a3f8                 ld      [%o2+%lo(_vm_page_active_count)], %o0
F00893F8: d226201c                 st      %o1, [%i0+0x1C]
F00893FC: 90023fff                 inc     -1, %o0
F0089400: d022a3f8                 st      %o0, [%o2+%lo(_vm_page_active_count)]
F0089404: d206201c                 ld      [%i0+0x1C], %o1
F0089408: 11000020                 sethi   0x8000, %o0
F008940C: 808a4008                 btst    %o0, %o1
F0089410: 02800013                 be      loc_F008945C
F0089414: 173c04f0                 sethi   %hi(_vm_page_queue_inactive), %o3
F0089418: d4060000                 ld      [%i0], %o2
F008941C: d2062004                 ld      [%i0+4], %o1
F0089420: 9012e228                 or      %o3, %lo(_vm_page_queue_inactive), %o0
F0089424: 80a24008                 cmp     %o1, %o0
F0089428: 12800004                 bne     loc_F0089438
F008942C: d222a004                 st      %o1, [%o2+4]
F0089430: 10800003                 ba      loc_F008943C
F0089434: d422e228                 st      %o2, [%o3+%lo(_vm_page_queue_inactive)]
F0089438: d4224000                 st      %o2, [%o1]
F008943C: 13000020                 sethi   0x8000, %o1
F0089440: d006201c                 ld      [%i0+0x1C], %o0
F0089444: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F0089448: 922a0009                 andn    %o0, %o1, %o1
F008944C: d002a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o0
F0089450: d226201c                 st      %o1, [%i0+0x1C]
F0089454: 90023fff                 inc     -1, %o0
F0089458: d022a220                 st      %o0, [%o2+%lo(_vm_page_inactive_count)]
F008945C: d2062020                 ld      [%i0+0x20], %o1
F0089460: 11040000                 sethi   0x10000000, %o0
F0089464: 808a4008                 btst    %o0, %o1
F0089468: 12800028                 bne     locret_F0089508
F008946C: 01000000                 nop
F0089470: 400035d2                 call    _spltty
F0089474: 01000000                 nop
F0089478: a2100008                 mov     %o0, %l1
F008947C: 113c04f6a01220f8         set     _vm_page_queue_free_lock, %l0
F0089484: d0040000                 ld      [%l0], %o0
F0089488: 80a22000                 cmp     %o0, 0
F008948C: 12bffffe                 bne     loc_F0089484
F0089490: 01000000                 nop
F0089494: 40003685                 call    _simple_lock_try
F0089498: 90100010                 mov     %l0, %o0
F008949C: 80a22000                 cmp     %o0, 0
F00894A0: 02bffff9                 be      loc_F0089484
F00894A4: 113c04f3                 sethi   %hi(dword_F013CC14), %o0
F00894A8: d2022014                 ld      [%o0+%lo(dword_F013CC14)], %o1
F00894AC: 94122014                 or      %o0, %lo(dword_F013CC14), %o2
F00894B0: 9002bffc                 add     %o2, -4, %o0
F00894B4: 80a24008                 cmp     %o1, %o0
F00894B8: 32800003                 bne,a   loc_F00894C4
F00894BC: f0224000                 st      %i0, [%o1]
F00894C0: f022bffc                 st      %i0, [%o2-4]
F00894C4: d2262004                 st      %o1, [%i0+4]
F00894C8: 113c04f390122010         set     _vm_page_queue_free, %o0
F00894D0: d0260000                 st      %o0, [%i0]
F00894D4: f0222004                 st      %i0, [%o0+4]
F00894D8: d006201c                 ld      [%i0+0x1C], %o0
F00894DC: 13000004                 sethi   0x1000, %o1
F00894E0: 90120009                 bset    %o1, %o0
F00894E4: d026201c                 st      %o0, [%i0+0x1C]
F00894E8: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F00894EC: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F00894F0: 153c04f3                 sethi   %hi(_vm_page_free_count), %o2
F00894F4: d202a000                 ld      [%o2+%lo(_vm_page_free_count)], %o1
F00894F8: 90100011                 mov     %l1, %o0
F00894FC: 92026001                 inc     %o1
F0089500: 40003609                 call    _splx
F0089504: d222a000                 st      %o1, [%o2+%lo(_vm_page_free_count)]
F0089508: 81c7e008                 ret
F008950C: 81e80000                 restore
