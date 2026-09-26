F008512C: 9de3bf98                 save    %sp, -0x68, %sp
F0085130: d0166028                 lduh    [%i1+0x28], %o0
F0085134: 80a22000                 cmp     %o0, 0
F0085138: 02800004                 be      loc_F0085148
F008513C: 90100018                 mov     %i0, %o0
F0085140: 7ffffff4                 call    _vm_map_entry_unwire
F0085144: 92100019                 mov     %i1, %o1
F0085148: d006201c                 ld      [%i0+0x1C], %o0
F008514C: 90023fff                 inc     -1, %o0
F0085150: d026201c                 st      %o0, [%i0+0x1C]
F0085154: d2066004                 ld      [%i1+4], %o1
F0085158: d0064000                 ld      [%i1], %o0
F008515C: d0224000                 st      %o0, [%o1]
F0085160: d2064000                 ld      [%i1], %o1
F0085164: d0066004                 ld      [%i1+4], %o0
F0085168: d0226004                 st      %o0, [%o1+4]
F008516C: d206600c                 ld      [%i1+0xC], %o1
F0085170: d4066008                 ld      [%i1+8], %o2
F0085174: d0062028                 ld      [%i0+0x28], %o0
F0085178: 9222400a                 sub     %o1, %o2, %o1
F008517C: 90220009                 sub     %o0, %o1, %o0
F0085180: d0262028                 st      %o0, [%i0+0x28]
F0085184: d2066018                 ld      [%i1+0x18], %o1
F0085188: 11280000                 sethi   -0x60000000, %o0
F008518C: 808a4008                 btst    %o0, %o1
F0085190: 02800006                 be      loc_F00851A8
F0085194: 01000000                 nop
F0085198: 7ffffc1d                 call    _vm_map_deallocate
F008519C: d0066010                 ld      [%i1+0x10], %o0
F00851A0: 10800005                 ba      loc_F00851B4
F00851A4: 9006200c                 add     %i0, 0xC, %o0
F00851A8: 400005c4                 call    _vm_object_deallocate
F00851AC: d0066010                 ld      [%i1+0x10], %o0
F00851B0: 9006200c                 add     %i0, 0xC, %o0
F00851B4: 7ffffbf5                 call    __vm_map_entry_dispose
F00851B8: 92100019                 mov     %i1, %o1
F00851BC: 81c7e008                 ret
F00851C0: 81e80000                 restore
