F009168C: 9de3bf98                 save    %sp, -0x68, %sp
F0091690: d0062004                 ld      [%i0+4], %o0
F0091694: 80a22030                 cmp     %o0, 0x30 ! '0'
F0091698: 1280001a                 bne     loc_F0091700
F009169C: 90103ed0                 mov     -0x130, %o0
F00916A0: d0060000                 ld      [%i0], %o0
F00916A4: 80a22000                 cmp     %o0, 0
F00916A8: 16800016                 bge     loc_F0091700
F00916AC: 90103ed0                 mov     -0x130, %o0
F00916B0: d2062018                 ld      [%i0+0x18], %o1
F00916B4: 1104480090122018         set     0x11200018, %o0
F00916BC: 920a7ffc                 and     %o1, -4, %o1
F00916C0: 80a24008                 cmp     %o1, %o0
F00916C4: 1280000f                 bne     loc_F0091700
F00916C8: 90103ed0                 mov     -0x130, %o0
F00916CC: d0062020                 ld      [%i0+0x20], %o0
F00916D0: 133c0448                 sethi   %hi(dword_F011229C), %o1
F00916D4: d202629c                 ld      [%o1+%lo(dword_F011229C)], %o1
F00916D8: 80a20009                 cmp     %o0, %o1
F00916DC: 12800009                 bne     loc_F0091700
F00916E0: 90103ed0                 mov     -0x130, %o0
F00916E4: d0062028                 ld      [%i0+0x28], %o0
F00916E8: 133c0448                 sethi   %hi(dword_F01122A0), %o1
F00916EC: d20262a0                 ld      [%o1+%lo(dword_F01122A0)], %o1
F00916F0: 80a20009                 cmp     %o0, %o1
F00916F4: 02800005                 be      loc_F0091708
F00916F8: 01000000                 nop
F00916FC: 90103ed0                 mov     -0x130, %o0
F0091700: 10800021                 ba      locret_F0091784
F0091704: d026601c                 st      %o0, [%i1+0x1C]
F0091708: 7fff587b                 call    _convert_port_to_task
F009170C: d006201c                 ld      [%i0+0x1C], %o0
F0091710: a0100008                 mov     %o0, %l0
F0091714: 7ffffae1                 call    _convert_port_to_dev
F0091718: d0062008                 ld      [%i0+8], %o0
F009171C: 92100010                 mov     %l0, %o1
F0091720: d4062024                 ld      [%i0+0x24], %o2
F0091724: 7ffffd94                 call    _kern_IOMapLockShmem
F0091728: 9606202c                 add     %i0, 0x2C, %o3 ! ','
F009172C: d026601c                 st      %o0, [%i1+0x1C]
F0091730: 7fff865e                 call    _task_deallocate
F0091734: 90100010                 mov     %l0, %o0
F0091738: d006601c                 ld      [%i1+0x1C], %o0
F009173C: 80a22000                 cmp     %o0, 0
F0091740: 12800011                 bne     locret_F0091784
F0091744: 01000000                 nop
F0091748: d006201c                 ld      [%i0+0x1C], %o0
F009174C: 80a22000                 cmp     %o0, 0
F0091750: 02800006                 be      loc_F0091768
F0091754: 80a23fff                 cmp     %o0, -1
F0091758: 22800005                 be,a    loc_F009176C
F009175C: 90102028                 mov     0x28, %o0 ! '('
F0091760: 7fff266f                 call    _ipc_port_release_send
F0091764: 01000000                 nop
F0091768: 90102028                 mov     0x28, %o0 ! '('
F009176C: d0266004                 st      %o0, [%i1+4]
F0091770: 113c0448                 sethi   %hi(dword_F01122A4), %o0
F0091774: d00222a4                 ld      [%o0+%lo(dword_F01122A4)], %o0
F0091778: d0266020                 st      %o0, [%i1+0x20]
F009177C: d006202c                 ld      [%i0+0x2C], %o0
F0091780: d0266024                 st      %o0, [%i1+0x24]
F0091784: 81c7e008                 ret
F0091788: 81e80000                 restore
