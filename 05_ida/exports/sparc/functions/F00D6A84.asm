F00D6A84: 9de3bf98                 save    %sp, -0x68, %sp
F00D6A88: 113c04bb                 sethi   %hi(unk_F012EEFC), %o0
F00D6A8C: d04a22fc                 ldsb    [%o0+%lo(unk_F012EEFC)], %o0
F00D6A90: 80a22000                 cmp     %o0, 0
F00D6A94: 0280000f                 be      loc_F00D6AD0
F00D6A98: 113c04cc                 sethi   -0xFECD000, %o0
F00D6A9C: 153c04bb                 sethi   %hi(dword_F012EF00), %o2
F00D6AA0: d202a300                 ld      [%o2+%lo(dword_F012EF00)], %o1
F00D6AA4: 113c04bb                 sethi   %hi(dword_F012EF04), %o0
F00D6AA8: d0022304                 ld      [%o0+%lo(dword_F012EF04)], %o0
F00D6AAC: 92024008                 add     %o1, %o0, %o1
F00D6AB0: 113c04bb                 sethi   %hi(dword_F012EF08), %o0
F00D6AB4: d0022308                 ld      [%o0+%lo(dword_F012EF08)], %o0
F00D6AB8: 80a22000                 cmp     %o0, 0
F00D6ABC: 02800004                 be      loc_F00D6ACC
F00D6AC0: d222a300                 st      %o1, [%o2+%lo(dword_F012EF00)]
F00D6AC4: 9fc20000                 call    %o0
F00D6AC8: 9e03e020                 inc     0x20, %o7 ! ' '
F00D6ACC: 113c04cc                 sethi   -0xFECD000, %o0
F00D6AD0: 7fffbd83                 call    _IOGetTimestamp
F00D6AD4: 901220d8                 bset    0xD8, %o0
F00D6AD8: 90100018                 mov     %i0, %o0
F00D6ADC: 92100019                 mov     %i1, %o1
F00D6AE0: 150008c8                 sethi   0x232000, %o2
F00D6AE4: 7ffee082                 call    _IOSendInterrupt
F00D6AE8: 9412a325                 bset    0x325, %o2
F00D6AEC: 81c7e008                 ret
F00D6AF0: 81e80000                 restore
