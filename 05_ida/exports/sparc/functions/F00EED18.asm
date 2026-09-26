F00EED18: 9de3bf18                 save    %sp, -0xE8, %sp
F00EED1C: ea06200c                 ld      [%i0+0xC], %l5
F00EED20: d0060000                 ld      [%i0], %o0
F00EED24: d4020000                 ld      [%o0], %o2
F00EED28: 90100018                 mov     %i0, %o0
F00EED2C: 9fc28000                 call    %o2
F00EED30: 92100019                 mov     %i1, %o1
F00EED34: 94100008                 mov     %o0, %o2
F00EED38: 1300003f921263ff         set     0xFFFF, %o1
F00EED40: 920a8009                 and     %o2, %o1, %o1
F00EED44: 9132a010                 srl     %o2, 16, %o0
F00EED48: 921a4008                 btog    %o0, %o1
F00EED4C: 912a600c                 sll     %o1, 12, %o0
F00EED50: 90220009                 sub     %o0, %o1, %o0
F00EED54: 912a2004                 sll     %o0, 4, %o0
F00EED58: 90020009                 add     %o0, %o1, %o0
F00EED5C: 9002000a                 add     %o0, %o2, %o0
F00EED60: 7ffc5ed0                 call    _urem
F00EED64: d2062008                 ld      [%i0+8], %o1
F00EED68: a8100008                 mov     %o0, %l4
F00EED6C: 912d2003                 sll     %l4, 3, %o0
F00EED70: a2054008                 add     %l5, %o0, %l1
F00EED74: ac102001                 mov     1, %l6
F00EED78: a4102000                 mov     0, %l2
F00EED7C: d0054008                 ld      [%l5+%o0], %o0
F00EED80: 80a23fff                 cmp     %o0, -1
F00EED84: 02800038                 be      loc_F00EEE64
F00EED88: ae102000                 mov     0, %l7
F00EED8C: 133c04bc                 sethi   %hi(dword_F012F0CC), %o1
F00EED90: d00260cc                 ld      [%o1+%lo(dword_F012F0CC)], %o0
F00EED94: 90022001                 inc     %o0
F00EED98: d02260cc                 st      %o0, [%o1+%lo(dword_F012F0CC)]
F00EED9C: d2044000                 ld      [%l1], %o1
F00EEDA0: 80a24019                 cmp     %o1, %i1
F00EEDA4: 02800009                 be      loc_F00EEDC8
F00EEDA8: a0100014                 mov     %l4, %l0
F00EEDAC: d0060000                 ld      [%i0], %o0
F00EEDB0: d6022004                 ld      [%o0+4], %o3
F00EEDB4: 90100018                 mov     %i0, %o0
F00EEDB8: 9fc2c000                 call    %o3
F00EEDBC: 94100019                 mov     %i1, %o2
F00EEDC0: 10800004                 ba      loc_F00EEDD0
F00EEDC4: 80a22000                 cmp     %o0, 0
F00EEDC8: 90102001                 mov     1, %o0
F00EEDCC: 80a22000                 cmp     %o0, 0
F00EEDD0: 02800005                 be      loc_F00EEDE4
F00EEDD4: 92042001                 add     %l0, 1, %o1
F00EEDD8: a404a001                 inc     %l2
F00EEDDC: ee046004                 ld      [%l1+4], %l7
F00EEDE0: 92042001                 add     %l0, 1, %o1
F00EEDE4: d0062008                 ld      [%i0+8], %o0
F00EEDE8: 80a24008                 cmp     %o1, %o0
F00EEDEC: 1a800003                 bcc     loc_F00EEDF8
F00EEDF0: 90102000                 mov     0, %o0
F00EEDF4: 90100009                 mov     %o1, %o0
F00EEDF8: a0100008                 mov     %o0, %l0
F00EEDFC: 80a40014                 cmp     %l0, %l4
F00EEE00: 02800016                 be      loc_F00EEE58
F00EEE04: 912c2003                 sll     %l0, 3, %o0
F00EEE08: d2054008                 ld      [%l5+%o0], %o1
F00EEE0C: 80a27fff                 cmp     %o1, -1
F00EEE10: 02800012                 be      loc_F00EEE58
F00EEE14: a2054008                 add     %l5, %o0, %l1
F00EEE18: 80a24019                 cmp     %o1, %i1
F00EEE1C: 02800009                 be      loc_F00EEE40
F00EEE20: 90102001                 mov     1, %o0
F00EEE24: d0060000                 ld      [%i0], %o0
F00EEE28: d6022004                 ld      [%o0+4], %o3
F00EEE2C: 90100018                 mov     %i0, %o0
F00EEE30: 9fc2c000                 call    %o3
F00EEE34: 94100019                 mov     %i1, %o2
F00EEE38: 10800003                 ba      loc_F00EEE44
F00EEE3C: 80a22000                 cmp     %o0, 0
F00EEE40: 80a22000                 cmp     %o0, 0
F00EEE44: 02bfffe7                 be      loc_F00EEDE0
F00EEE48: ac05a001                 inc     %l6
F00EEE4C: a404a001                 inc     %l2
F00EEE50: 10bfffe4                 ba      loc_F00EEDE0
F00EEE54: ee046004                 ld      [%l1+4], %l7
F00EEE58: 80a4a000                 cmp     %l2, 0
F00EEE5C: 12800004                 bne     loc_F00EEE6C
F00EEE60: 80a4a001                 cmp     %l2, 1
F00EEE64: 10800051                 ba      locret_F00EEFA8
F00EEE68: b0102000                 mov     0, %i0
F00EEE6C: 02800006                 be      loc_F00EEE84
F00EEE70: 80a5a010                 cmp     %l6, 0x10
F00EEE74: 113c03f4                 sethi   %hi(aNxmapremoveInc), %o0! "**** NXMapRemove: incorrect table\n"
F00EEE78: 400006b4                 call    __NXLogError
F00EEE7C: 90122068                 bset    %lo(aNxmapremoveInc), %o0! "**** NXMapRemove: incorrect table\n"
F00EEE80: 80a5a010                 cmp     %l6, 0x10
F00EEE84: 08800006                 bleu    loc_F00EEE9C
F00EEE88: 9005bfff                 add     %l6, -1, %o0! __size
F00EEE8C: 7ffde4e9                 call    _malloc
F00EEE90: 912a2003                 sll     %o0, 3, %o0
F00EEE94: 10800003                 ba      loc_F00EEEA0
F00EEE98: a6100008                 mov     %o0, %l3
F00EEE9C: a607bf78                 add     %fp, var_88, %l3
F00EEEA0: a405bfff                 add     %l6, -1, %l2
F00EEEA4: 80a4bfff                 cmp     %l2, -1
F00EEEA8: 02800026                 be      loc_F00EEF40
F00EEEAC: a0102000                 mov     0, %l0
F00EEEB0: b4103fff                 mov     -1, %i2
F00EEEB4: 912d2003                 sll     %l4, 3, %o0
F00EEEB8: d2054008                 ld      [%l5+%o0], %o1
F00EEEBC: 80a24019                 cmp     %o1, %i1
F00EEEC0: 02800009                 be      loc_F00EEEE4
F00EEEC4: a2054008                 add     %l5, %o0, %l1
F00EEEC8: d0060000                 ld      [%i0], %o0
F00EEECC: d6022004                 ld      [%o0+4], %o3
F00EEED0: 90100018                 mov     %i0, %o0
F00EEED4: 9fc2c000                 call    %o3
F00EEED8: 94100019                 mov     %i1, %o2
F00EEEDC: 10800004                 ba      loc_F00EEEEC
F00EEEE0: 80a22000                 cmp     %o0, 0
F00EEEE4: 90102001                 mov     1, %o0
F00EEEE8: 80a22000                 cmp     %o0, 0
F00EEEEC: 3280000a                 bne,a   loc_F00EEF14
F00EEEF0: f4244000                 st      %i2, [%l1]
F00EEEF4: 912c2003                 sll     %l0, 3, %o0
F00EEEF8: d2044000                 ld      [%l1], %o1
F00EEEFC: d224c008                 st      %o1, [%l3+%o0]
F00EEF00: 9004c008                 add     %l3, %o0, %o0
F00EEF04: d2046004                 ld      [%l1+4], %o1
F00EEF08: d2222004                 st      %o1, [%o0+4]
F00EEF0C: a0042001                 inc     %l0
F00EEF10: f4244000                 st      %i2, [%l1]
F00EEF14: c0246004                 clr     [%l1+4]
F00EEF18: 92052001                 add     %l4, 1, %o1
F00EEF1C: d0062008                 ld      [%i0+8], %o0
F00EEF20: 80a24008                 cmp     %o1, %o0
F00EEF24: 1a800003                 bcc     loc_F00EEF30
F00EEF28: 90102000                 mov     0, %o0
F00EEF2C: 90100009                 mov     %o1, %o0
F00EEF30: a404bfff                 inc     -1, %l2
F00EEF34: 80a4bfff                 cmp     %l2, -1
F00EEF38: 12bfffdf                 bne     loc_F00EEEB4
F00EEF3C: a8100008                 mov     %o0, %l4
F00EEF40: d0062004                 ld      [%i0+4], %o0
F00EEF44: 90220016                 sub     %o0, %l6, %o0
F00EEF48: d0262004                 st      %o0, [%i0+4]
F00EEF4C: 9005bfff                 add     %l6, -1, %o0
F00EEF50: 80a40008                 cmp     %l0, %o0
F00EEF54: 0280000b                 be      loc_F00EEF80
F00EEF58: 113c03f4                 sethi   %hi(aNxmapremoveBug), %o0! "**** NXMapRemove: bug\n"
F00EEF5C: 4000067b                 call    __NXLogError
F00EEF60: 90122090                 bset    %lo(aNxmapremoveBug), %o0! "**** NXMapRemove: bug\n"
F00EEF64: 10800008                 ba      loc_F00EEF84
F00EEF68: a0043fff                 inc     -1, %l0
F00EEF6C: 9404c009                 add     %l3, %o1, %o2
F00EEF70: 90100018                 mov     %i0, %o0! void *
F00EEF74: d204c009                 ld      [%l3+%o1], %o1
F00EEF78: 7ffffec7                 call    _NXMapInsert
F00EEF7C: d402a004                 ld      [%o2+4], %o2
F00EEF80: a0043fff                 inc     -1, %l0
F00EEF84: 80a43fff                 cmp     %l0, -1
F00EEF88: 12bffff9                 bne     loc_F00EEF6C
F00EEF8C: 932c2003                 sll     %l0, 3, %o1
F00EEF90: 80a5a010                 cmp     %l6, 0x10
F00EEF94: 08800005                 bleu    locret_F00EEFA8
F00EEF98: b0100017                 mov     %l7, %i0
F00EEF9C: 7ffde4d9                 call    _free
F00EEFA0: 90100013                 mov     %l3, %o0
F00EEFA4: b0100017                 mov     %l7, %i0
F00EEFA8: 81c7e008                 ret
F00EEFAC: 81e80000                 restore
