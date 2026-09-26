F0093E04: 9de3bf98                 save    %sp, -0x68, %sp
F0093E08: a0100018                 mov     %i0, %l0
F0093E0C: 233c0449                 sethi   %hi(_panel_req_port), %l1
F0093E10: d0046114                 ld      [%l1+%lo(_panel_req_port)], %o0
F0093E14: 80a22000                 cmp     %o0, 0
F0093E18: 02800025                 be      loc_F0093EAC
F0093E1C: b0102000                 mov     0, %i0
F0093E20: 7fff5094                 call    _kalloc
F0093E24: 90102020                 mov     0x20, %o0 ! ' '
F0093E28: 153c0449                 sethi   %hi(dword_F0112630), %o2
F0093E2C: d202a230                 ld      [%o2+%lo(dword_F0112630)], %o1
F0093E30: d2220000                 st      %o1, [%o0]
F0093E34: 9412a230                 bset    %lo(dword_F0112630), %o2
F0093E38: d202a004                 ld      [%o2+4], %o1
F0093E3C: d2222004                 st      %o1, [%o0+4]
F0093E40: d202a008                 ld      [%o2+8], %o1
F0093E44: d2222008                 st      %o1, [%o0+8]
F0093E48: d202a00c                 ld      [%o2+0xC], %o1
F0093E4C: d222200c                 st      %o1, [%o0+0xC]
F0093E50: d202a010                 ld      [%o2+0x10], %o1
F0093E54: d2222010                 st      %o1, [%o0+0x10]
F0093E58: d202a014                 ld      [%o2+0x14], %o1
F0093E5C: d2222014                 st      %o1, [%o0+0x14]
F0093E60: d602a018                 ld      [%o2+0x18], %o3
F0093E64: d6222018                 st      %o3, [%o0+0x18]
F0093E68: d602a01c                 ld      [%o2+0x1C], %o3
F0093E6C: 92102001                 mov     1, %o1
F0093E70: 153c0449                 sethi   %hi(dword_F0112518), %o2
F0093E74: d622201c                 st      %o3, [%o0+0x1C]
F0093E78: d802a118                 ld      [%o2+%lo(dword_F0112518)], %o4
F0093E7C: e022201c                 st      %l0, [%o0+0x1C]
F0093E80: d4046114                 ld      [%l1+0x114], %o2
F0093E84: d822200c                 st      %o4, [%o0+0xC]
F0093E88: d4222010                 st      %o2, [%o0+0x10]
F0093E8C: 7fff4768                 call    _msg_send_from_kernel
F0093E90: 94102000                 mov     0, %o2
F0093E94: b0920000                 orcc    %o0, %g0, %i0
F0093E98: 02800005                 be      loc_F0093EAC
F0093E9C: 113c0449                 sethi   %hi(aVolPanelRemove), %o0! "vol_panel_remove: msg_send returned %d"...
F0093EA0: 901223b8                 bset    %lo(aVolPanelRemove), %o0! "vol_panel_remove: msg_send returned %d"...
F0093EA4: 7ffe01ed                 call    _printf
F0093EA8: 92100018                 mov     %i0, %o1
F0093EAC: 4000006a                 call    sub_F0094054
F0093EB0: 90100010                 mov     %l0, %o0
F0093EB4: 80a22000                 cmp     %o0, 0
F0093EB8: 02800004                 be      locret_F0093EC8
F0093EBC: 01000000                 nop
F0093EC0: 7fff50b8                 call    _kfree
F0093EC4: 92102014                 mov     0x14, %o1
F0093EC8: 81c7e008                 ret
F0093ECC: 81e80000                 restore
