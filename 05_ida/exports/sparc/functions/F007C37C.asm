F007C37C: 9de3bf90                 save    %sp, -0x70, %sp
F007C380: d0062004                 ld      [%i0+4], %o0
F007C384: 80a22018                 cmp     %o0, 0x18
F007C388: 12800007                 bne     loc_F007C3A4
F007C38C: 90103ed0                 mov     -0x130, %o0
F007C390: d0060000                 ld      [%i0], %o0
F007C394: 21200000                 sethi   0x80000000, %l0
F007C398: 808a0010                 btst    %l0, %o0
F007C39C: 02800004                 be      loc_F007C3AC
F007C3A0: 90103ed0                 mov     -0x130, %o0
F007C3A4: 10800014                 ba      locret_F007C3F4
F007C3A8: d026601c                 st      %o0, [%i1+0x1C]
F007C3AC: 7fffa3b8                 call    _convert_port_to_host
F007C3B0: d0062008                 ld      [%i0+8], %o0! host
F007C3B4: 7fffa39e                 call    _processor_set_default
F007C3B8: 9207bff4                 add     %fp, var_C, %o1
F007C3BC: 80a22000                 cmp     %o0, 0
F007C3C0: 1280000d                 bne     locret_F007C3F4
F007C3C4: d026601c                 st      %o0, [%i1+0x1C]
F007C3C8: 92102028                 mov     0x28, %o1 ! '('
F007C3CC: d0064000                 ld      [%i1], %o0
F007C3D0: d2266004                 st      %o1, [%i1+4]
F007C3D4: 90120010                 bset    %l0, %o0
F007C3D8: d0264000                 st      %o0, [%i1]
F007C3DC: 113c0444                 sethi   %hi(dword_F011108C), %o0
F007C3E0: d202208c                 ld      [%o0+%lo(dword_F011108C)], %o1
F007C3E4: d007bff4                 ld      [%fp+var_C], %o0
F007C3E8: 7fffa460                 call    _convert_pset_name_to_port
F007C3EC: d2266020                 st      %o1, [%i1+0x20]
F007C3F0: d0266024                 st      %o0, [%i1+0x24]
F007C3F4: 81c7e008                 ret
F007C3F8: 81e80000                 restore
