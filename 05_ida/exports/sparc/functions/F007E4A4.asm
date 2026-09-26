F007E4A4: 9de3bf98                 save    %sp, -0x68, %sp
F007E4A8: d0062004                 ld      [%i0+4], %o0
F007E4AC: 80a22038                 cmp     %o0, 0x38 ! '8'
F007E4B0: 1280001e                 bne     loc_F007E528
F007E4B4: 90103ed0                 mov     -0x130, %o0
F007E4B8: d0060000                 ld      [%i0], %o0
F007E4BC: 80a22000                 cmp     %o0, 0
F007E4C0: 06800019                 bl      loc_F007E524
F007E4C4: 133c0444                 sethi   %hi(dword_F0111318), %o1
F007E4C8: d0062018                 ld      [%i0+0x18], %o0
F007E4CC: d2026318                 ld      [%o1+%lo(dword_F0111318)], %o1
F007E4D0: 80a20009                 cmp     %o0, %o1
F007E4D4: 12800015                 bne     loc_F007E528
F007E4D8: 90103ed0                 mov     -0x130, %o0
F007E4DC: d0062020                 ld      [%i0+0x20], %o0
F007E4E0: 133c0444                 sethi   %hi(dword_F011131C), %o1
F007E4E4: d202631c                 ld      [%o1+%lo(dword_F011131C)], %o1
F007E4E8: 80a20009                 cmp     %o0, %o1
F007E4EC: 1280000f                 bne     loc_F007E528
F007E4F0: 90103ed0                 mov     -0x130, %o0
F007E4F4: d0062028                 ld      [%i0+0x28], %o0
F007E4F8: 133c0444                 sethi   %hi(dword_F0111320), %o1
F007E4FC: d2026320                 ld      [%o1+%lo(dword_F0111320)], %o1
F007E500: 80a20009                 cmp     %o0, %o1
F007E504: 12800009                 bne     loc_F007E528
F007E508: 90103ed0                 mov     -0x130, %o0
F007E50C: d0062030                 ld      [%i0+0x30], %o0
F007E510: 133c0444                 sethi   %hi(dword_F0111324), %o1
F007E514: d2026324                 ld      [%o1+%lo(dword_F0111324)], %o1
F007E518: 80a20009                 cmp     %o0, %o1
F007E51C: 02800005                 be      loc_F007E530
F007E520: 01000000                 nop
F007E524: 90103ed0                 mov     -0x130, %o0
F007E528: 1080000d                 ba      locret_F007E55C
F007E52C: d026601c                 st      %o0, [%i1+0x1C]
F007E530: 7fffa532                 call    _convert_port_to_map
F007E534: d0062008                 ld      [%i0+8], %o0! target_task
F007E538: d206201c                 ld      [%i0+0x1C], %o1! address
F007E53C: d4062024                 ld      [%i0+0x24], %o2! size
F007E540: d606202c                 ld      [%i0+0x2C], %o3! set_maximum
F007E544: a0100008                 mov     %o0, %l0
F007E548: 400030fd                 call    _vm_protect
F007E54C: d8062034                 ld      [%i0+0x34], %o4
F007E550: d026601c                 st      %o0, [%i1+0x1C]
F007E554: 4000172e                 call    _vm_map_deallocate
F007E558: 90100010                 mov     %l0, %o0
F007E55C: 81c7e008                 ret
F007E560: 81e80000                 restore
