F003D56C: 9de3bf90                 save    %sp, -0x70, %sp
F003D570: 4000aac0                 call    _kalloc
F003D574: 901020ff                 mov     0xFF, %o0
F003D578: b0100008                 mov     %o0, %i0
F003D57C: 113c043492122068         set     aNfs, %o1! ".nfs"
F003D584: 90026004                 add     %o1, 4, %o0
F003D588: 80a24008                 cmp     %o1, %o0
F003D58C: 1a800009                 bcc     loc_F003D5B0
F003D590: a0100018                 mov     %i0, %l0
F003D594: 94100008                 mov     %o0, %o2
F003D598: d00a4000                 ldub    [%o1], %o0
F003D59C: d02c0000                 stb     %o0, [%l0]
F003D5A0: 92026001                 inc     %o1
F003D5A4: 80a2400a                 cmp     %o1, %o2
F003D5A8: 0abffffc                 bcs     loc_F003D598
F003D5AC: a0042001                 inc     %l0
F003D5B0: 233c04bd                 sethi   %hi(dword_F012F4EC), %l1
F003D5B4: d00460ec                 ld      [%l1+%lo(dword_F012F4EC)], %o0
F003D5B8: 80a22000                 cmp     %o0, 0
F003D5BC: 1280000a                 bne     loc_F003D5E4
F003D5C0: d20460ec                 ld      [%l1+%lo(dword_F012F4EC)], %o1
F003D5C4: 7fff5672                 call    _getthetime
F003D5C8: 9007bff0                 add     %fp, var_10, %o0
F003D5CC: d207bff0                 ld      [%fp+var_10], %o1
F003D5D0: 1100003f901223ff         set     0xFFFF, %o0
F003D5D8: 920a4008                 and     %o1, %o0, %o1
F003D5DC: d22460ec                 st      %o1, [%l1+%lo(dword_F012F4EC)]
F003D5E0: d20460ec                 ld      [%l1+%lo(dword_F012F4EC)], %o1
F003D5E4: 90026001                 add     %o1, 1, %o0
F003D5E8: 80a26000                 cmp     %o1, 0
F003D5EC: 0280000b                 be      loc_F003D618
F003D5F0: d02460ec                 st      %o0, [%l1+0xEC]
F003D5F4: 113c043494122070         set     a0123456789abcd_0, %o2! "0123456789ABCDEF"
F003D5FC: 900a600f                 and     %o1, 0xF, %o0
F003D600: 933a6004                 sra     %o1, 4, %o1
F003D604: d00a000a                 ldub    [%o0+%o2], %o0
F003D608: 80a26000                 cmp     %o1, 0
F003D60C: d02c0000                 stb     %o0, [%l0]
F003D610: 12bffffb                 bne     loc_F003D5FC
F003D614: a0042001                 inc     %l0
F003D618: c02c0000                 clrb    [%l0]
F003D61C: 81c7e008                 ret
F003D620: 81e80000                 restore
