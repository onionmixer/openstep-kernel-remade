F009419C: 9de3bf90                 save    %sp, -0x70, %sp
F00941A0: 233c0442                 sethi   %hi(_kernel_task), %l1
F00941A4: 9207bff4                 add     %fp, var_C, %o1
F00941A8: d0046250                 ld      [%l1+%lo(_kernel_task)], %o0
F00941AC: 213c0449                 sethi   %hi(dword_F0112518), %l0
F00941B0: d0022088                 ld      [%o0+0x88], %o0
F00941B4: 7fff1a2c                 call    _ipc_port_alloc
F00941B8: 94142118                 or      %l0, %lo(dword_F0112518), %o2
F00941BC: 92920000                 orcc    %o0, %g0, %o1
F00941C0: 02800005                 be      loc_F00941D4
F00941C4: 113c044a                 sethi   %hi(aVolStartThread), %o0! "vol_start_thread: port_alloc returned %"...
F00941C8: 7ffe0124                 call    _printf
F00941CC: 90122050                 bset    %lo(aVolStartThread), %o0! "vol_start_thread: port_alloc returned %"...
F00941D0: 3080001b                 ba,a    locret_F009423C
F00941D4: 133c024f                 sethi   %hi(sub_F0093F7C), %o1
F00941D8: d6042118                 ld      [%l0+0x118], %o3
F00941DC: 9212637c                 bset    %lo(sub_F0093F7C), %o1
F00941E0: d0046250                 ld      [%l1+0x250], %o0
F00941E4: 94102000                 mov     0, %o2
F00941E8: d802e010                 ld      [%o3+0x10], %o4
F00941EC: c022c000                 clr     [%o3]
F00941F0: 173c0449                 sethi   %hi(dword_F011251C), %o3
F00941F4: 7fff8610                 call    _kernel_thread
F00941F8: d822e11c                 st      %o4, [%o3+%lo(dword_F011251C)]
F00941FC: 133c044990126128         set     off_F0112528, %o0
F0094204: d0222004                 st      %o0, [%o0+4]
F0094208: d0226128                 st      %o0, [%o1+0x128]
F009420C: 153c0449                 sethi   %hi(dword_F0112530), %o2
F0094210: 92102001                 mov     1, %o1
F0094214: 213c04c4                 sethi   %hi(unk_F0131251), %l0
F0094218: d04c2251                 ldsb    [%l0+%lo(unk_F0131251)], %o0
F009421C: 80a22000                 cmp     %o0, 0
F0094220: 12800007                 bne     locret_F009423C
F0094224: d222a130                 st      %o1, [%o2+%lo(dword_F0112530)]
F0094228: 113c04c4                 sethi   %hi(unk_F0131254), %o0
F009422C: 7fff52b7                 call    _lock_init
F0094230: 90122254                 bset    %lo(unk_F0131254), %o0
F0094234: 90102001                 mov     1, %o0
F0094238: d02c2251                 stb     %o0, [%l0+%lo(unk_F0131251)]
F009423C: 81c7e008                 ret
F0094240: 81e80000                 restore
