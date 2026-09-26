F0039330: 9de3bf90                 save    %sp, -0x70, %sp
F0039334: 213c0432                 sethi   %hi(dword_F010C9CC), %l0
F0039338: d00421cc                 ld      [%l0+%lo(dword_F010C9CC)], %o0
F003933C: 80a22000                 cmp     %o0, 0
F0039340: 0280001f                 be      locret_F00393BC
F0039344: 01000000                 nop
F0039348: 40017653                 call    _splnet
F003934C: 01000000                 nop
F0039350: c02421cc                 clr     [%l0+%lo(dword_F010C9CC)]
F0039354: a4100008                 mov     %o0, %l2
F0039358: 7fffffed                 call    sub_F003930C
F003935C: 9007bff0                 add     %fp, var_10, %o0
F0039360: 92920000                 orcc    %o0, %g0, %o1
F0039364: 02800014                 be      loc_F00393B4
F0039368: 01000000                 nop
F003936C: a2100010                 mov     %l0, %l1
F0039370: a0102001                 mov     1, %l0
F0039374: d0026010                 ld      [%o1+0x10], %o0
F0039378: 80a22000                 cmp     %o0, 0
F003937C: 02800009                 be      loc_F00393A0
F0039380: 90023fff                 inc     -1, %o0
F0039384: 80a22000                 cmp     %o0, 0
F0039388: 12800005                 bne     loc_F003939C
F003938C: d0226010                 st      %o0, [%o1+0x10]
F0039390: 4000000d                 call    _igmp_sendreport
F0039394: 90100009                 mov     %o1, %o0
F0039398: 30800002                 ba,a    loc_F00393A0
F003939C: e02461cc                 st      %l0, [%l1+0x1CC]
F00393A0: 7fffffc5                 call    sub_F00392B4
F00393A4: 9007bff0                 add     %fp, var_10, %o0
F00393A8: 92920000                 orcc    %o0, %g0, %o1
F00393AC: 32bffff3                 bne,a   loc_F0039378
F00393B0: d0026010                 ld      [%o1+0x10], %o0
F00393B4: 4001765c                 call    _splx
F00393B8: 90100012                 mov     %l2, %o0
F00393BC: 81c7e008                 ret
F00393C0: 81e80000                 restore
