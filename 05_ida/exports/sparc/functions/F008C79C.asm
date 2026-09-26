F008C79C: 9de3bf90                 save    %sp, -0x70, %sp
F008C7A0: 2b3c0506                 sethi   %hi(paIodevice_0), %l5
F008C7A4: 293c0504                 sethi   -0xFEBF000, %l4
F008C7A8: 273c0504                 sethi   -0xFEBF000, %l3
F008C7AC: 253c0504                 sethi   -0xFEBF000, %l2
F008C7B0: 233c0516                 sethi   -0xFEBA800, %l1
F008C7B4: d0056270                 ld      [%l5+%lo(paIodevice_0)], %o0! id
F008C7B8: 94100010                 mov     %l0, %o2
F008C7BC: d2052010                 ld      [%l4+0x10], %o1! SEL
F008C7C0: 4001942c                 call    _objc_msgSend
F008C7C4: 9607bff4                 add     %fp, var_C, %o3
F008C7C8: 80a23d40                 cmp     %o0, -0x2C0
F008C7CC: 02800017                 be      locret_F008C828
F008C7D0: a0042001                 inc     %l0
F008C7D4: 80a23d29                 cmp     %o0, -0x2D7
F008C7D8: 02bffff8                 be      loc_F008C7B8
F008C7DC: d0056270                 ld      [%l5+0x270], %o0
F008C7E0: d007bff4                 ld      [%fp+var_C], %o0! id
F008C7E4: 40019423                 call    _objc_msgSend
F008C7E8: d204e014                 ld      [%l3+0x14], %o1
F008C7EC: d204a018                 ld      [%l2+0x18], %o1! SEL
F008C7F0: 40019420                 call    _objc_msgSend
F008C7F4: 94146084                 or      %l1, 0x84, %o2
F008C7F8: 912a2018                 sll     %o0, 24, %o0
F008C7FC: 80a22000                 cmp     %o0, 0
F008C800: 02bfffee                 be      loc_F008C7B8
F008C804: d0056270                 ld      [%l5+0x270], %o0
F008C808: 94100018                 mov     %i0, %o2
F008C80C: d007bff4                 ld      [%fp+var_C], %o0! id
F008C810: 133c0504                 sethi   %hi(paPerformWith), %o1
F008C814: d202601c                 ld      [%o1+%lo(paPerformWith)], %o1! SEL
F008C818: 40019416                 call    _objc_msgSend
F008C81C: 96100019                 mov     %i1, %o3
F008C820: 10bfffe6                 ba      loc_F008C7B8
F008C824: d0056270                 ld      [%l5+0x270], %o0
F008C828: 81c7e008                 ret
F008C82C: 81e80000                 restore
