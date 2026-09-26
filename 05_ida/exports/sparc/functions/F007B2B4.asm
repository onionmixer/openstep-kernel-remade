F007B2B4: 9de3bf68                 save    %sp, -0x98, %sp
F007B2B8: 153c0443                 sethi   %hi(dword_F0110E44), %o2
F007B2BC: d602a244                 ld      [%o2+%lo(dword_F0110E44)], %o3
F007B2C0: 9412a244                 bset    %lo(dword_F0110E44), %o2
F007B2C4: d802a004                 ld      [%o2+4], %o4
F007B2C8: d627bfc8                 st      %o3, [%fp+var_38]
F007B2CC: d602a008                 ld      [%o2+8], %o3
F007B2D0: d827bfcc                 st      %o4, [%fp+var_34]
F007B2D4: d802a00c                 ld      [%o2+0xC], %o4
F007B2D8: d627bfd0                 st      %o3, [%fp+var_30]
F007B2DC: d602a010                 ld      [%o2+0x10], %o3
F007B2E0: d827bfd4                 st      %o4, [%fp+var_2C]
F007B2E4: d802a014                 ld      [%o2+0x14], %o4
F007B2E8: d627bfd8                 st      %o3, [%fp+var_28]
F007B2EC: d602a018                 ld      [%o2+0x18], %o3
F007B2F0: d827bfdc                 st      %o4, [%fp+var_24]
F007B2F4: d802a01c                 ld      [%o2+0x1C], %o4
F007B2F8: d627bfe0                 st      %o3, [%fp+var_20]
F007B2FC: d602a020                 ld      [%o2+0x20], %o3
F007B300: d827bfe4                 st      %o4, [%fp+var_1C]
F007B304: d802a024                 ld      [%o2+0x24], %o4
F007B308: 9007bfc8                 add     %fp, var_38, %o0
F007B30C: d627bfe8                 st      %o3, [%fp+var_18]
F007B310: d402a028                 ld      [%o2+0x28], %o2
F007B314: 92102001                 mov     1, %o1
F007B318: d827bfec                 st      %o4, [%fp+var_14]
F007B31C: d427bff0                 st      %o2, [%fp+var_10]
F007B320: f027bfe4                 st      %i0, [%fp+var_1C]
F007B324: f227bfe8                 st      %i1, [%fp+var_18]
F007B328: 153c04f2                 sethi   %hi(_pn_register_port_k), %o2
F007B32C: c027bfd4                 clr     [%fp+var_2C]
F007B330: d402a3f0                 ld      [%o2+%lo(_pn_register_port_k)], %o2
F007B334: f027bff0                 st      %i0, [%fp+var_10]
F007B338: d427bfd8                 st      %o2, [%fp+var_28]
F007B33C: 7fffaa3c                 call    _msg_send_from_kernel
F007B340: 94102000                 mov     0, %o2
F007B344: 92920000                 orcc    %o0, %g0, %o1
F007B348: 02800004                 be      locret_F007B358
F007B34C: 113c0444                 sethi   %hi(aPortRequestNot), %o0! "port_request_notification: msg_send ret"...
F007B350: 7ffe64c2                 call    _printf
F007B354: 90122028                 bset    %lo(aPortRequestNot), %o0! "port_request_notification: msg_send ret"...
F007B358: 81c7e008                 ret
F007B35C: 81e80000                 restore
