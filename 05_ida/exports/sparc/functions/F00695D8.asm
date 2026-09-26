F00695D8: 9de3bf98                 save    %sp, -0x68, %sp
F00695DC: a0100018                 mov     %i0, %l0
F00695E0: b0042008                 add     %l0, 8, %i0
F00695E4: d0060000                 ld      [%i0], %o0
F00695E8: 80a22000                 cmp     %o0, 0
F00695EC: 12bffffe                 bne     loc_F00695E4
F00695F0: 01000000                 nop
F00695F4: 4000b62d                 call    _simple_lock_try
F00695F8: 90100018                 mov     %i0, %o0
F00695FC: 80a22000                 cmp     %o0, 0
F0069600: 02bffff9                 be      loc_F00695E4
F0069604: 133c04d0                 sethi   %hi(_active_threads), %o1
F0069608: d0040000                 ld      [%l0], %o0
F006960C: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0069610: 80a20009                 cmp     %o0, %o1
F0069614: 3280000f                 bne,a   loc_F0069650
F0069618: d0042004                 ld      [%l0+4], %o0
F006961C: d0142004                 lduh    [%l0+4], %o0
F0069620: c0242008                 clr     [%l0+8]
F0069624: 90023fff                 inc     -1, %o0
F0069628: d0342004                 sth     %o0, [%l0+4]
F006962C: d0042004                 ld      [%l0+4], %o0
F0069630: b0102001                 mov     1, %i0
F0069634: 920a3000                 and     %o0, -0x1000, %o1
F0069638: 900a2fff                 and     %o0, 0xFFF, %o0
F006963C: 90022001                 inc     %o0
F0069640: 900a2fff                 and     %o0, 0xFFF, %o0
F0069644: 92124008                 bset    %o0, %o1
F0069648: 10800028                 ba      locret_F00696E8
F006964C: d2242004                 st      %o1, [%l0+4]
F0069650: 13000020                 sethi   0x8000, %o1
F0069654: 808a0009                 btst    %o1, %o0
F0069658: 02800005                 be      loc_F006966C
F006965C: 90120009                 bset    %o1, %o0
F0069660: c0242008                 clr     [%l0+8]
F0069664: 10800021                 ba      locret_F00696E8
F0069668: b0102000                 mov     0, %i0
F006966C: d0242004                 st      %o0, [%l0+4]
F0069670: d0142004                 lduh    [%l0+4], %o0
F0069674: 90023fff                 inc     -1, %o0
F0069678: d0342004                 sth     %o0, [%l0+4]
F006967C: 912a2010                 sll     %o0, 16, %o0
F0069680: 80a22000                 cmp     %o0, 0
F0069684: 02800017                 be      loc_F00696E0
F0069688: b0042008                 add     %l0, 8, %i0
F006968C: 23000008                 sethi   0x2000, %l1
F0069690: d2042004                 ld      [%l0+4], %o1
F0069694: 90100010                 mov     %l0, %o0
F0069698: 94102000                 mov     0, %o2
F006969C: 92124011                 bset    %l1, %o1
F00696A0: d2242004                 st      %o1, [%l0+4]
F00696A4: 40001ec6                 call    _thread_sleep
F00696A8: 92100018                 mov     %i0, %o1
F00696AC: d0060000                 ld      [%i0], %o0
F00696B0: 80a22000                 cmp     %o0, 0
F00696B4: 12bffffe                 bne     loc_F00696AC
F00696B8: 01000000                 nop
F00696BC: 4000b5fb                 call    _simple_lock_try
F00696C0: 90100018                 mov     %i0, %o0
F00696C4: 80a22000                 cmp     %o0, 0
F00696C8: 02bffff9                 be      loc_F00696AC
F00696CC: 01000000                 nop
F00696D0: d0142004                 lduh    [%l0+4], %o0
F00696D4: 80a22000                 cmp     %o0, 0
F00696D8: 32bfffef                 bne,a   loc_F0069694
F00696DC: d2042004                 ld      [%l0+4], %o1
F00696E0: c0242008                 clr     [%l0+8]
F00696E4: b0102001                 mov     1, %i0
F00696E8: 81c7e008                 ret
F00696EC: 81e80000                 restore
