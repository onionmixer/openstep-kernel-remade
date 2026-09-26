F008904C: 9de3bf98                 save    %sp, -0x68, %sp
F0089050: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0089058: d0040000                 ld      [%l0], %o0
F008905C: 80a22000                 cmp     %o0, 0
F0089060: 12bffffe                 bne     loc_F0089058
F0089064: 01000000                 nop
F0089068: 40003790                 call    _simple_lock_try
F008906C: 90100010                 mov     %l0, %o0
F0089070: 80a22000                 cmp     %o0, 0
F0089074: 02bffff9                 be      loc_F0089058
F0089078: 01000000                 nop
F008907C: 7fffff83                 call    _vm_page_remove
F0089080: 90100018                 mov     %i0, %o0
F0089084: 90100018                 mov     %i0, %o0
F0089088: 92100019                 mov     %i1, %o1
F008908C: 7fffff48                 call    _vm_page_insert
F0089090: 9410001a                 mov     %i2, %o2
F0089094: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0089098: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F008909C: 81c7e008                 ret
F00890A0: 81e80000                 restore
