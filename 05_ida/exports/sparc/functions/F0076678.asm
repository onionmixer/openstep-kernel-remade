F0076678: 9de3bf98                 save    %sp, -0x68, %sp
F007667C: 113c0442                 sethi   %hi(dword_F0110BB0), %o0
F0076680: d00223b0                 ld      [%o0+%lo(dword_F0110BB0)], %o0
F0076684: 80a22000                 cmp     %o0, 0
F0076688: 1280002b                 bne     locret_F0076734
F007668C: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F0076690: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F0076694: 133c04c39012632c         set     dword_F0130F2C, %o0
F007669C: d0222004                 st      %o0, [%o0+4]
F00766A0: d022632c                 st      %o0, [%o1+0x32C]
F00766A4: 133c04c390126334         set     dword_F0130F34, %o0
F00766AC: d0222004                 st      %o0, [%o0+4]
F00766B0: d0226334                 st      %o0, [%o1+0x334]
F00766B4: 113c04c394122324         set     dword_F0130F24, %o2
F00766BC: d422a004                 st      %o2, [%o2+4]
F00766C0: d4222324                 st      %o2, [%o0+0x324]
F00766C4: 113c04c192122120         set     unk_F0130520, %o1
F00766CC: 90026a00                 add     %o1, 0xA00, %o0
F00766D0: 80a24008                 cmp     %o1, %o0
F00766D4: 1a80000b                 bcc     loc_F0076700
F00766D8: 96100008                 mov     %o0, %o3
F00766DC: d4224000                 st      %o2, [%o1]
F00766E0: d002a004                 ld      [%o2+4], %o0
F00766E4: d0226004                 st      %o0, [%o1+4]
F00766E8: d2220000                 st      %o1, [%o0]
F00766EC: d222a004                 st      %o1, [%o2+4]
F00766F0: 92026028                 inc     0x28, %o1 ! '('
F00766F4: 80a2400b                 cmp     %o1, %o3
F00766F8: 2abffffa                 bcs,a   loc_F00766E0
F00766FC: d4224000                 st      %o2, [%o1]
F0076700: 113c0442                 sethi   %hi(_kernel_task), %o0
F0076704: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F0076708: 133c01dd921262a8         set     sub_F00776A8, %o1
F0076710: 7ffffcc9                 call    _kernel_thread
F0076714: 94102000                 mov     0, %o2
F0076718: 90102000                 mov     0, %o0
F007671C: 133c01dd                 sethi   %hi(sub_F00776C8), %o1
F0076720: 400084cf                 call    _set_timer_expire_func
F0076724: 921262c8                 bset    %lo(sub_F00776C8), %o1
F0076728: 133c0442                 sethi   %hi(dword_F0110BB0), %o1
F007672C: 90102001                 mov     1, %o0
F0076730: d02263b0                 st      %o0, [%o1+%lo(dword_F0110BB0)]
F0076734: 81c7e008                 ret
F0076738: 81e80000                 restore
