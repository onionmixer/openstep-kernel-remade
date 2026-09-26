F0072464: 9de3bf98                 save    %sp, -0x68, %sp
F0072468: 400091c8                 call    _splusclock
F007246C: a0062100                 add     %i0, 0x100, %l0
F0072470: a6100008                 mov     %o0, %l3
F0072474: d0040000                 ld      [%l0], %o0
F0072478: 80a22000                 cmp     %o0, 0
F007247C: 12bffffe                 bne     loc_F0072474
F0072480: 01000000                 nop
F0072484: 40009289                 call    _simple_lock_try
F0072488: 90100010                 mov     %l0, %o0
F007248C: 80a22000                 cmp     %o0, 0
F0072490: 02bffff9                 be      loc_F0072474
F0072494: 01000000                 nop
F0072498: e4062108                 ld      [%i0+0x108], %l2
F007249C: 80a4a000                 cmp     %l2, 0
F00724A0: 0480003a                 ble     loc_F0072588
F00724A4: 133c04f1                 sethi   %hi(_stuck_threads), %o1
F00724A8: 2d3c04f0                 sethi   -0xFEC4000, %l6
F00724AC: 293c0441                 sethi   -0xFEEFC00, %l4
F00724B0: d0062104                 ld      [%i0+0x104], %o0
F00724B4: aa126090                 or      %o1, %lo(_stuck_threads), %l5
F00724B8: 912a2003                 sll     %o0, 3, %o0
F00724BC: a0060008                 add     %i0, %o0, %l0
F00724C0: d8040000                 ld      [%l0], %o4
F00724C4: 80a4000c                 cmp     %l0, %o4
F00724C8: 0280002e                 be      loc_F0072580
F00724CC: 80a4a000                 cmp     %l2, 0
F00724D0: d003204c                 ld      [%o4+0x4C], %o0
F00724D4: 900a200f                 and     %o0, 0xF, %o0
F00724D8: 80a22004                 cmp     %o0, 4
F00724DC: 12800024                 bne     loc_F007256C
F00724E0: e2030000                 ld      [%o4], %l1
F00724E4: d005a298                 ld      [%l6+0x298], %o0
F00724E8: d2032070                 ld      [%o4+0x70], %o1
F00724EC: 90220009                 sub     %o0, %o1, %o0
F00724F0: 80a22001                 cmp     %o0, 1
F00724F4: 0880001e                 bleu    loc_F007256C
F00724F8: da0521c0                 ld      [%l4+0x1C0], %o5
F00724FC: 80a36080                 cmp     %o5, 0x80
F0072500: 32800007                 bne,a   loc_F007251C
F0072504: d0032004                 ld      [%o4+4], %o0
F0072508: c0262100                 clr     [%i0+0x100]
F007250C: 40009206                 call    _splx
F0072510: 90100013                 mov     %l3, %o0
F0072514: 10800021                 ba      locret_F0072598
F0072518: b0102001                 mov     1, %i0
F007251C: d0246004                 st      %o0, [%l1+4]
F0072520: 90036001                 add     %o5, 1, %o0
F0072524: d6032004                 ld      [%o4+4], %o3
F0072528: d02521c0                 st      %o0, [%l4+0x1C0]
F007252C: d2030000                 ld      [%o4], %o1
F0072530: 113c0441                 sethi   %hi(_do_thread_scan_debug), %o0
F0072534: d40221bc                 ld      [%o0+%lo(_do_thread_scan_debug)], %o2
F0072538: d222c000                 st      %o1, [%o3]
F007253C: d0062108                 ld      [%i0+0x108], %o0
F0072540: 80a2a000                 cmp     %o2, 0
F0072544: 90023fff                 inc     -1, %o0
F0072548: d0262108                 st      %o0, [%i0+0x108]
F007254C: c0232008                 clr     [%o4+8]
F0072550: 912b6002                 sll     %o5, 2, %o0
F0072554: 02800006                 be      loc_F007256C
F0072558: d8220015                 st      %o4, [%o0+%l5]
F007255C: 113c0441901221c8         set     aDoRunqScanAddi, %o0! "do_runq_scan: adding thread %#x\n"
F0072564: 7ffe883d                 call    _printf
F0072568: 9210000c                 mov     %o4, %o1
F007256C: 98100011                 mov     %l1, %o4
F0072570: 80a4000c                 cmp     %l0, %o4
F0072574: 12bfffd7                 bne     loc_F00724D0
F0072578: a404bfff                 inc     -1, %l2
F007257C: 80a4a000                 cmp     %l2, 0
F0072580: 14bfffd0                 bg      loc_F00724C0
F0072584: a0043ff8                 inc     -8, %l0
F0072588: c0262100                 clr     [%i0+0x100]
F007258C: 400091e6                 call    _splx
F0072590: 90100013                 mov     %l3, %o0
F0072594: b0102000                 mov     0, %i0
F0072598: 81c7e008                 ret
F007259C: 81e80000                 restore
