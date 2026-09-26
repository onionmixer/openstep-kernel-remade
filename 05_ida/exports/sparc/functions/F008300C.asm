F008300C: 9de3bf98                 save    %sp, -0x68, %sp
F0083010: ea06e010                 ld      [%i3+0x10], %l5
F0083014: d206a00c                 ld      [%i2+0xC], %o1
F0083018: ba100018                 mov     %i0, %i5
F008301C: d006a008                 ld      [%i2+8], %o0
F0083020: a8102000                 mov     0, %l4
F0083024: f806e014                 ld      [%i3+0x14], %i4
F0083028: 40000dde                 call    _vm_object_allocate
F008302C: 90224008                 sub     %o1, %o0, %o0
F0083030: a2100008                 mov     %o0, %l1
F0083034: e606a008                 ld      [%i2+8], %l3
F0083038: e226a010                 st      %l1, [%i2+0x10]
F008303C: d006a00c                 ld      [%i2+0xC], %o0
F0083040: c026a014                 clr     [%i2+0x14]
F0083044: 80a4c008                 cmp     %l3, %o0
F0083048: 1a80007d                 bcc     locret_F008323C
F008304C: f206a020                 ld      [%i2+0x20], %i1
F0083050: a4046010                 add     %l1, 0x10, %l2
F0083054: 2d3c04f3                 sethi   -0xFEC3400, %l6
F0083058: 313c04f3                 sethi   -0xFEC3400, %i0
F008305C: 2f3c04f3                 sethi   -0xFEC3400, %l7
F0083060: d0048000                 ld      [%l2], %o0
F0083064: 80a22000                 cmp     %o0, 0
F0083068: 12bffffe                 bne     loc_F0083060
F008306C: 01000000                 nop
F0083070: 40004f8e                 call    _simple_lock_try
F0083074: 90100012                 mov     %l2, %o0
F0083078: 80a22000                 cmp     %o0, 0
F008307C: 02bffff9                 be      loc_F0083060
F0083080: 90100011                 mov     %l1, %o0
F0083084: 92100014                 mov     %l4, %o1
F0083088: 40001829                 call    _vm_page_alloc_sequential
F008308C: 94102001                 mov     1, %o2
F0083090: a0920000                 orcc    %o0, %g0, %l0
F0083094: 1280001e                 bne     loc_F008310C
F0083098: 01000000                 nop
F008309C: c0246010                 clr     [%l1+0x10]
F00830A0: b615a020                 or      %l6, 0x20, %i3
F00830A4: d006c000                 ld      [%i3], %o0
F00830A8: 80a22000                 cmp     %o0, 0
F00830AC: 12bffffe                 bne     loc_F00830A4
F00830B0: 01000000                 nop
F00830B4: 40004f7d                 call    _simple_lock_try
F00830B8: 9010001b                 mov     %i3, %o0
F00830BC: 80a22000                 cmp     %o0, 0
F00830C0: 02bffff9                 be      loc_F00830A4
F00830C4: 90162018                 or      %i0, 0x18, %o0
F00830C8: 92102000                 mov     0, %o1
F00830CC: 7fffb7cc                 call    _thread_wakeup_prim
F00830D0: 94102000                 mov     0, %o2
F00830D4: 9015e000                 or      %l7, 0, %o0
F00830D8: 9215a020                 or      %l6, 0x20, %o1
F00830DC: 7fffb838                 call    _thread_sleep
F00830E0: 94102000                 mov     0, %o2
F00830E4: b6046010                 add     %l1, 0x10, %i3
F00830E8: d006c000                 ld      [%i3], %o0
F00830EC: 80a22000                 cmp     %o0, 0
F00830F0: 12bffffe                 bne     loc_F00830E8
F00830F4: 01000000                 nop
F00830F8: 40004f6c                 call    _simple_lock_try
F00830FC: 9010001b                 mov     %i3, %o0
F0083100: 80a22000                 cmp     %o0, 0
F0083104: 02bffff9                 be      loc_F00830E8
F0083108: 80a42000                 cmp     %l0, 0
F008310C: 02bfffde                 be      loc_F0083084
F0083110: 90100011                 mov     %l1, %o0
F0083114: b6056010                 add     %l5, 0x10, %i3
F0083118: d006c000                 ld      [%i3], %o0
F008311C: 80a22000                 cmp     %o0, 0
F0083120: 12bffffe                 bne     loc_F0083118
F0083124: 01000000                 nop
F0083128: 40004f60                 call    _simple_lock_try
F008312C: 9010001b                 mov     %i3, %o0
F0083130: 80a22000                 cmp     %o0, 0
F0083134: 02bffff9                 be      loc_F0083118
F0083138: 90100015                 mov     %l5, %o0
F008313C: 40001797                 call    _vm_page_lookup
F0083140: 9205001c                 add     %l4, %i4, %o1
F0083144: b6920000                 orcc    %o0, %g0, %i3
F0083148: 32800006                 bne,a   loc_F0083160
F008314C: 9010001b                 mov     %i3, %o0
F0083150: 113c0446                 sethi   %hi(aVmFaultCopyWir), %o0! "vm_fault_copy_wired: page missing"
F0083154: 7ffe4807                 call    _panic
F0083158: 90122178                 bset    %lo(aVmFaultCopyWir), %o0! "vm_fault_copy_wired: page missing"
F008315C: 9010001b                 mov     %i3, %o0
F0083160: 400019f4                 call    _vm_page_copy
F0083164: 92100010                 mov     %l0, %o1
F0083168: c0256010                 clr     [%l5+0x10]
F008316C: c0246010                 clr     [%l1+0x10]
F0083170: 92100013                 mov     %l3, %o1
F0083174: b6046010                 add     %l1, 0x10, %i3
F0083178: d0076024                 ld      [%i5+0x24], %o0
F008317C: 96100019                 mov     %i1, %o3
F0083180: d4042024                 ld      [%l0+0x24], %o2
F0083184: 40006cca                 call    _pmap_enter
F0083188: 98102000                 mov     0, %o4
F008318C: d006c000                 ld      [%i3], %o0
F0083190: 80a22000                 cmp     %o0, 0
F0083194: 12bffffe                 bne     loc_F008318C
F0083198: 01000000                 nop
F008319C: 40004f43                 call    _simple_lock_try
F00831A0: 9010001b                 mov     %i3, %o0
F00831A4: 80a22000                 cmp     %o0, 0
F00831A8: 02bffff9                 be      loc_F008318C
F00831AC: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00831B0: b6122230                 or      %o0, %lo(_vm_page_queue_lock), %i3
F00831B4: d006c000                 ld      [%i3], %o0
F00831B8: 80a22000                 cmp     %o0, 0
F00831BC: 12bffffe                 bne     loc_F00831B4
F00831C0: 01000000                 nop
F00831C4: 40004f39                 call    _simple_lock_try
F00831C8: 9010001b                 mov     %i3, %o0
F00831CC: 80a22000                 cmp     %o0, 0
F00831D0: 02bffff9                 be      loc_F00831B4
F00831D4: 01000000                 nop
F00831D8: 40001983                 call    _vm_page_activate
F00831DC: 90100010                 mov     %l0, %o0
F00831E0: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00831E4: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F00831E8: d2042020                 ld      [%l0+0x20], %o1
F00831EC: 11200000                 sethi   0x80000000, %o0
F00831F0: 922a4008                 bclr    %o0, %o1
F00831F4: 11100000                 sethi   0x40000000, %o0
F00831F8: 808a4008                 btst    %o0, %o1
F00831FC: 02800008                 be      loc_F008321C
F0083200: d2242020                 st      %o1, [%l0+0x20]
F0083204: 902a4008                 andn    %o1, %o0, %o0
F0083208: d0242020                 st      %o0, [%l0+0x20]
F008320C: 90100010                 mov     %l0, %o0
F0083210: 92102000                 mov     0, %o1
F0083214: 7fffb77a                 call    _thread_wakeup_prim
F0083218: 94102000                 mov     0, %o2
F008321C: 113c0447                 sethi   %hi(_page_size), %o0
F0083220: d202213c                 ld      [%o0+%lo(_page_size)], %o1
F0083224: c0246010                 clr     [%l1+0x10]
F0083228: a604c009                 add     %l3, %o1, %l3
F008322C: d006a00c                 ld      [%i2+0xC], %o0
F0083230: 80a4c008                 cmp     %l3, %o0
F0083234: 0abfff8b                 bcs     loc_F0083060
F0083238: a8050009                 add     %l4, %o1, %l4
F008323C: 81c7e008                 ret
F0083240: 81e80000                 restore
