F007C4EC: 9de3bf90                 save    %sp, -0x70, %sp
F007C4F0: d0062004                 ld      [%i0+4], %o0
F007C4F4: 80a22020                 cmp     %o0, 0x20 ! ' '
F007C4F8: 1280000e                 bne     loc_F007C530
F007C4FC: 90103ed0                 mov     -0x130, %o0
F007C500: d0060000                 ld      [%i0], %o0
F007C504: 23200000                 sethi   0x80000000, %l1
F007C508: 808a0011                 btst    %l1, %o0
F007C50C: 12800009                 bne     loc_F007C530
F007C510: 90103ed0                 mov     -0x130, %o0
F007C514: d0062018                 ld      [%i0+0x18], %o0
F007C518: 133c0444                 sethi   %hi(dword_F0111098), %o1
F007C51C: d2026098                 ld      [%o1+%lo(dword_F0111098)], %o1
F007C520: 80a20009                 cmp     %o0, %o1
F007C524: 02800005                 be      loc_F007C538
F007C528: 01000000                 nop
F007C52C: 90103ed0                 mov     -0x130, %o0
F007C530: 10800029                 ba      locret_F007C5D4
F007C534: d026601c                 st      %o0, [%i1+0x1C]
F007C538: 7fffa3ca                 call    _convert_port_to_pset_name
F007C53C: d0062008                 ld      [%i0+8], %o0! set_name
F007C540: 92102400                 mov     0x400, %o1
F007C544: d227bff0                 st      %o1, [%fp+var_10]
F007C548: a0100008                 mov     %o0, %l0
F007C54C: 9407bff4                 add     %fp, var_C, %o2! host
F007C550: 96066034                 add     %i1, 0x34, %o3 ! '4'! info_out
F007C554: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007C558: 7fffcb80                 call    _processor_set_info
F007C55C: 9807bff0                 add     %fp, var_10, %o4
F007C560: d026601c                 st      %o0, [%i1+0x1C]
F007C564: 7fffcaf5                 call    _pset_deallocate
F007C568: 90100010                 mov     %l0, %o0
F007C56C: d006601c                 ld      [%i1+0x1C], %o0
F007C570: 80a22000                 cmp     %o0, 0
F007C574: 12800018                 bne     locret_F007C5D4
F007C578: 01000000                 nop
F007C57C: d0064000                 ld      [%i1], %o0
F007C580: 90120011                 bset    %l1, %o0
F007C584: d0264000                 st      %o0, [%i1]
F007C588: 113c0444                 sethi   %hi(dword_F011109C), %o0
F007C58C: d202209c                 ld      [%o0+%lo(dword_F011109C)], %o1
F007C590: d007bff4                 ld      [%fp+var_C], %o0
F007C594: 7fffa3d4                 call    _convert_host_to_port
F007C598: d2266020                 st      %o1, [%i1+0x20]
F007C59C: d0266024                 st      %o0, [%i1+0x24]
F007C5A0: 113c0444                 sethi   %hi(dword_F01110A0), %o0
F007C5A4: d20220a0                 ld      [%o0+%lo(dword_F01110A0)], %o1
F007C5A8: d2266028                 st      %o1, [%i1+0x28]
F007C5AC: 901220a0                 bset    %lo(dword_F01110A0), %o0
F007C5B0: d2022004                 ld      [%o0+4], %o1
F007C5B4: d226602c                 st      %o1, [%i1+0x2C]
F007C5B8: d2022008                 ld      [%o0+8], %o1
F007C5BC: d007bff0                 ld      [%fp+var_10], %o0
F007C5C0: d2266030                 st      %o1, [%i1+0x30]
F007C5C4: d0266030                 st      %o0, [%i1+0x30]
F007C5C8: 912a2002                 sll     %o0, 2, %o0
F007C5CC: 90022034                 inc     0x34, %o0 ! '4'
F007C5D0: d0266004                 st      %o0, [%i1+4]
F007C5D4: 81c7e008                 ret
F007C5D8: 81e80000                 restore
