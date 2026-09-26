F009178C: 9de3bf98                 save    %sp, -0x68, %sp
F0091790: d0062004                 ld      [%i0+4], %o0
F0091794: 80a22030                 cmp     %o0, 0x30 ! '0'
F0091798: 1280001a                 bne     loc_F0091800
F009179C: 90103ed0                 mov     -0x130, %o0
F00917A0: d0060000                 ld      [%i0], %o0
F00917A4: 80a22000                 cmp     %o0, 0
F00917A8: 16800016                 bge     loc_F0091800
F00917AC: 90103ed0                 mov     -0x130, %o0
F00917B0: d2062018                 ld      [%i0+0x18], %o1
F00917B4: 1104480090122018         set     0x11200018, %o0
F00917BC: 920a7ffc                 and     %o1, -4, %o1
F00917C0: 80a24008                 cmp     %o1, %o0
F00917C4: 1280000f                 bne     loc_F0091800
F00917C8: 90103ed0                 mov     -0x130, %o0
F00917CC: d0062020                 ld      [%i0+0x20], %o0
F00917D0: 133c0448                 sethi   %hi(dword_F01122A8), %o1
F00917D4: d20262a8                 ld      [%o1+%lo(dword_F01122A8)], %o1
F00917D8: 80a20009                 cmp     %o0, %o1
F00917DC: 12800009                 bne     loc_F0091800
F00917E0: 90103ed0                 mov     -0x130, %o0
F00917E4: d0062028                 ld      [%i0+0x28], %o0
F00917E8: 133c0448                 sethi   %hi(dword_F01122AC), %o1
F00917EC: d20262ac                 ld      [%o1+%lo(dword_F01122AC)], %o1
F00917F0: 80a20009                 cmp     %o0, %o1
F00917F4: 02800005                 be      loc_F0091808
F00917F8: 01000000                 nop
F00917FC: 90103ed0                 mov     -0x130, %o0
F0091800: 1080001a                 ba      locret_F0091868
F0091804: d026601c                 st      %o0, [%i1+0x1C]
F0091808: 7fff583b                 call    _convert_port_to_task
F009180C: d006201c                 ld      [%i0+0x1C], %o0
F0091810: a0100008                 mov     %o0, %l0
F0091814: 7ffffaa1                 call    _convert_port_to_dev
F0091818: d0062008                 ld      [%i0+8], %o0
F009181C: d4062024                 ld      [%i0+0x24], %o2
F0091820: d606202c                 ld      [%i0+0x2C], %o3
F0091824: 7ffffd7c                 call    _kern_IOUnMapLockShmem
F0091828: 92100010                 mov     %l0, %o1
F009182C: d026601c                 st      %o0, [%i1+0x1C]
F0091830: 7fff861e                 call    _task_deallocate
F0091834: 90100010                 mov     %l0, %o0
F0091838: d006601c                 ld      [%i1+0x1C], %o0
F009183C: 80a22000                 cmp     %o0, 0
F0091840: 1280000a                 bne     locret_F0091868
F0091844: 01000000                 nop
F0091848: d006201c                 ld      [%i0+0x1C], %o0
F009184C: 80a22000                 cmp     %o0, 0
F0091850: 02800006                 be      locret_F0091868
F0091854: 80a23fff                 cmp     %o0, -1
F0091858: 02800004                 be      locret_F0091868
F009185C: 01000000                 nop
F0091860: 7fff262f                 call    _ipc_port_release_send
F0091864: 01000000                 nop
F0091868: 81c7e008                 ret
F009186C: 81e80000                 restore
