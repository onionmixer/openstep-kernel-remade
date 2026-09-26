F008830C: 9de3bf98                 save    %sp, -0x68, %sp
F0088310: 400002de                 call    _vm_page_remove
F0088314: 90100018                 mov     %i0, %o0
F0088318: d206201c                 ld      [%i0+0x1C], %o1
F008831C: 11000004                 sethi   0x1000, %o0
F0088320: 808a4008                 btst    %o0, %o1
F0088324: 12800052                 bne     locret_F008846C
F0088328: 11000010                 sethi   0x4000, %o0
F008832C: 808a4008                 btst    %o0, %o1
F0088330: 02800014                 be      loc_F0088380
F0088334: 173c04f3                 sethi   %hi(_vm_page_queue_active), %o3
F0088338: d4060000                 ld      [%i0], %o2
F008833C: d2062004                 ld      [%i0+4], %o1
F0088340: 9012e008                 or      %o3, %lo(_vm_page_queue_active), %o0
F0088344: 80a24008                 cmp     %o1, %o0
F0088348: 12800004                 bne     loc_F0088358
F008834C: d222a004                 st      %o1, [%o2+4]
F0088350: 10800003                 ba      loc_F008835C
F0088354: d422e008                 st      %o2, [%o3+%lo(_vm_page_queue_active)]
F0088358: d4224000                 st      %o2, [%o1]
F008835C: 13000010                 sethi   0x4000, %o1
F0088360: d006201c                 ld      [%i0+0x1C], %o0
F0088364: 153c04f2                 sethi   %hi(_vm_page_active_count), %o2
F0088368: 922a0009                 andn    %o0, %o1, %o1
F008836C: d002a3f8                 ld      [%o2+%lo(_vm_page_active_count)], %o0
F0088370: d226201c                 st      %o1, [%i0+0x1C]
F0088374: 90023fff                 inc     -1, %o0
F0088378: d022a3f8                 st      %o0, [%o2+%lo(_vm_page_active_count)]
F008837C: d206201c                 ld      [%i0+0x1C], %o1
F0088380: 11000020                 sethi   0x8000, %o0
F0088384: 808a4008                 btst    %o0, %o1
F0088388: 02800013                 be      loc_F00883D4
F008838C: 173c04f0                 sethi   %hi(_vm_page_queue_inactive), %o3
F0088390: d4060000                 ld      [%i0], %o2
F0088394: d2062004                 ld      [%i0+4], %o1
F0088398: 9012e228                 or      %o3, %lo(_vm_page_queue_inactive), %o0
F008839C: 80a24008                 cmp     %o1, %o0
F00883A0: 12800004                 bne     loc_F00883B0
F00883A4: d222a004                 st      %o1, [%o2+4]
F00883A8: 10800003                 ba      loc_F00883B4
F00883AC: d422e228                 st      %o2, [%o3+%lo(_vm_page_queue_inactive)]
F00883B0: d4224000                 st      %o2, [%o1]
F00883B4: 13000020                 sethi   0x8000, %o1
F00883B8: d006201c                 ld      [%i0+0x1C], %o0
F00883BC: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F00883C0: 922a0009                 andn    %o0, %o1, %o1
F00883C4: d002a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o0
F00883C8: d226201c                 st      %o1, [%i0+0x1C]
F00883CC: 90023fff                 inc     -1, %o0
F00883D0: d022a220                 st      %o0, [%o2+%lo(_vm_page_inactive_count)]
F00883D4: d2062020                 ld      [%i0+0x20], %o1
F00883D8: 11040000                 sethi   0x10000000, %o0
F00883DC: 808a4008                 btst    %o0, %o1
F00883E0: 12800023                 bne     locret_F008846C
F00883E4: 01000000                 nop
F00883E8: 400039f4                 call    _spltty
F00883EC: 01000000                 nop
F00883F0: a2100008                 mov     %o0, %l1
F00883F4: 113c04f6a01220f8         set     _vm_page_queue_free_lock, %l0
F00883FC: d0040000                 ld      [%l0], %o0
F0088400: 80a22000                 cmp     %o0, 0
F0088404: 12bffffe                 bne     loc_F00883FC
F0088408: 01000000                 nop
F008840C: 40003aa7                 call    _simple_lock_try
F0088410: 90100010                 mov     %l0, %o0
F0088414: 80a22000                 cmp     %o0, 0
F0088418: 02bffff9                 be      loc_F00883FC
F008841C: 113c04f3                 sethi   %hi(_vm_page_queue_free), %o0
F0088420: d2022010                 ld      [%o0+%lo(_vm_page_queue_free)], %o1
F0088424: f0226004                 st      %i0, [%o1+4]
F0088428: d2260000                 st      %o1, [%i0]
F008842C: 133c04f390126010         set     _vm_page_queue_free, %o0
F0088434: d0262004                 st      %o0, [%i0+4]
F0088438: f0226010                 st      %i0, [%o1+0x10]
F008843C: d006201c                 ld      [%i0+0x1C], %o0
F0088440: 13000004                 sethi   0x1000, %o1
F0088444: 90120009                 bset    %o1, %o0
F0088448: d026201c                 st      %o0, [%i0+0x1C]
F008844C: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F0088450: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F0088454: 153c04f3                 sethi   %hi(_vm_page_free_count), %o2
F0088458: d202a000                 ld      [%o2+%lo(_vm_page_free_count)], %o1
F008845C: 90100011                 mov     %l1, %o0
F0088460: 92026001                 inc     %o1
F0088464: 40003a30                 call    _splx
F0088468: d222a000                 st      %o1, [%o2+%lo(_vm_page_free_count)]
F008846C: 81c7e008                 ret
F0088470: 81e80000                 restore
