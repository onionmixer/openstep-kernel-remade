F00890A4: 9de3bf98                 save    %sp, -0x68, %sp
F00890A8: 153c04f6                 sethi   %hi(_vm_page_template), %o2
F00890AC: d202a150                 ld      [%o2+%lo(_vm_page_template)], %o1
F00890B0: 90100018                 mov     %i0, %o0
F00890B4: d2220000                 st      %o1, [%o0]
F00890B8: 9412a150                 bset    %lo(_vm_page_template), %o2
F00890BC: d202a004                 ld      [%o2+4], %o1
F00890C0: d2222004                 st      %o1, [%o0+4]
F00890C4: d202a008                 ld      [%o2+8], %o1
F00890C8: d2222008                 st      %o1, [%o0+8]
F00890CC: d202a00c                 ld      [%o2+0xC], %o1
F00890D0: d222200c                 st      %o1, [%o0+0xC]
F00890D4: d202a010                 ld      [%o2+0x10], %o1
F00890D8: d2222010                 st      %o1, [%o0+0x10]
F00890DC: d202a014                 ld      [%o2+0x14], %o1
F00890E0: d2222014                 st      %o1, [%o0+0x14]
F00890E4: d202a018                 ld      [%o2+0x18], %o1
F00890E8: d2222018                 st      %o1, [%o0+0x18]
F00890EC: d202a01c                 ld      [%o2+0x1C], %o1
F00890F0: d222201c                 st      %o1, [%o0+0x1C]
F00890F4: d202a020                 ld      [%o2+0x20], %o1
F00890F8: d2222020                 st      %o1, [%o0+0x20]
F00890FC: d202a024                 ld      [%o2+0x24], %o1
F0089100: d2222024                 st      %o1, [%o0+0x24]
F0089104: d202a028                 ld      [%o2+0x28], %o1
F0089108: d2222028                 st      %o1, [%o0+0x28]
F008910C: d202a02c                 ld      [%o2+0x2C], %o1
F0089110: d222202c                 st      %o1, [%o0+0x2C]
F0089114: f6222024                 st      %i3, [%o0+0x24]
F0089118: 92100019                 mov     %i1, %o1
F008911C: 7fffff24                 call    _vm_page_insert
F0089120: 9410001a                 mov     %i2, %o2
F0089124: 81c7e008                 ret
F0089128: 81e80000                 restore
