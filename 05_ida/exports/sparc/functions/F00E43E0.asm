F00E43E0: 9de3bf98                 save    %sp, -0x68, %sp
F00E43E4: d2062004                 ld      [%i0+4], %o1
F00E43E8: 80a26038                 cmp     %o1, 0x38 ! '8'
F00E43EC: 12800005                 bne     loc_F00E4400
F00E43F0: d00e2003                 ldub    [%i0+3], %o0
F00E43F4: 80a22000                 cmp     %o0, 0
F00E43F8: 22800005                 be,a    loc_F00E440C
F00E43FC: d0062018                 ld      [%i0+0x18], %o0
F00E4400: 90103ed0                 mov     -0x130, %o0
F00E4404: 10800028                 ba      locret_F00E44A4
F00E4408: d026601c                 st      %o0, [%i1+0x1C]
F00E440C: 133c03e6                 sethi   %hi(dword_F00F9B3C), %o1
F00E4410: d202633c                 ld      [%o1+%lo(dword_F00F9B3C)], %o1
F00E4414: 80a20009                 cmp     %o0, %o1
F00E4418: 1280001b                 bne     loc_F00E4484
F00E441C: 90103ed0                 mov     -0x130, %o0
F00E4420: d0062020                 ld      [%i0+0x20], %o0
F00E4424: 133c03e6                 sethi   %hi(dword_F00F9B40), %o1
F00E4428: d2026340                 ld      [%o1+%lo(dword_F00F9B40)], %o1
F00E442C: 80a20009                 cmp     %o0, %o1
F00E4430: 12800015                 bne     loc_F00E4484
F00E4434: 90103ed0                 mov     -0x130, %o0
F00E4438: d0062028                 ld      [%i0+0x28], %o0
F00E443C: 133c03e6                 sethi   %hi(dword_F00F9B44), %o1
F00E4440: d2026344                 ld      [%o1+%lo(dword_F00F9B44)], %o1
F00E4444: 80a20009                 cmp     %o0, %o1
F00E4448: 1280000f                 bne     loc_F00E4484
F00E444C: 90103ed0                 mov     -0x130, %o0
F00E4450: d0062030                 ld      [%i0+0x30], %o0
F00E4454: 133c03e6                 sethi   %hi(dword_F00F9B48), %o1
F00E4458: d2026348                 ld      [%o1+%lo(dword_F00F9B48)], %o1
F00E445C: 80a20009                 cmp     %o0, %o1
F00E4460: 12800009                 bne     loc_F00E4484
F00E4464: 90103ed0                 mov     -0x130, %o0
F00E4468: 7fffe6e6                 call    _audio_port_to_stream
F00E446C: d006200c                 ld      [%i0+0xC], %o0
F00E4470: d206201c                 ld      [%i0+0x1C], %o1
F00E4474: d4062024                 ld      [%i0+0x24], %o2
F00E4478: d606202c                 ld      [%i0+0x2C], %o3
F00E447C: 7fffea5c                 call    __NXAudioRecordStreamData
F00E4480: d8062034                 ld      [%i0+0x34], %o4
F00E4484: d026601c                 st      %o0, [%i1+0x1C]
F00E4488: d006601c                 ld      [%i1+0x1C], %o0
F00E448C: 80a22000                 cmp     %o0, 0
F00E4490: 12800005                 bne     locret_F00E44A4
F00E4494: 92102020                 mov     0x20, %o1 ! ' '
F00E4498: 90102001                 mov     1, %o0
F00E449C: d02e6003                 stb     %o0, [%i1+3]
F00E44A0: d2266004                 st      %o1, [%i1+4]
F00E44A4: 81c7e008                 ret
F00E44A8: 81e80000                 restore
