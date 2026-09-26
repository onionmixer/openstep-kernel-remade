F007D28C: 9de3bf90                 save    %sp, -0x70, %sp
F007D290: d0062004                 ld      [%i0+4], %o0
F007D294: 80a22024                 cmp     %o0, 0x24 ! '$'
F007D298: 1280000c                 bne     loc_F007D2C8
F007D29C: 90103ed0                 mov     -0x130, %o0
F007D2A0: d0060000                 ld      [%i0], %o0
F007D2A4: 80a22000                 cmp     %o0, 0
F007D2A8: 06800007                 bl      loc_F007D2C4
F007D2AC: 133c0444                 sethi   %hi(dword_F011112C), %o1
F007D2B0: d0062018                 ld      [%i0+0x18], %o0
F007D2B4: d202612c                 ld      [%o1+%lo(dword_F011112C)], %o1
F007D2B8: 80a20009                 cmp     %o0, %o1
F007D2BC: 22800005                 be,a    loc_F007D2D0
F007D2C0: d006201c                 ld      [%i0+0x1C], %o0
F007D2C4: 90103ed0                 mov     -0x130, %o0
F007D2C8: 10800012                 ba      locret_F007D310
F007D2CC: d026601c                 st      %o0, [%i1+0x1C]
F007D2D0: d027bff0                 st      %o0, [%fp+var_10]
F007D2D4: d0062020                 ld      [%i0+0x20], %o0
F007D2D8: d027bff4                 st      %o0, [%fp+var_C]
F007D2DC: 7fffa009                 call    _convert_port_to_host_priv
F007D2E0: d0062008                 ld      [%i0+8], %o0
F007D2E4: 9207bff0                 add     %fp, var_10, %o1
F007D2E8: 7fffb234                 call    _host_adjust_time
F007D2EC: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007D2F0: 80a22000                 cmp     %o0, 0
F007D2F4: 12800007                 bne     locret_F007D310
F007D2F8: d026601c                 st      %o0, [%i1+0x1C]
F007D2FC: 9010202c                 mov     0x2C, %o0 ! ','
F007D300: d0266004                 st      %o0, [%i1+4]
F007D304: 113c0444                 sethi   %hi(dword_F0111130), %o0
F007D308: d0022130                 ld      [%o0+%lo(dword_F0111130)], %o0
F007D30C: d0266020                 st      %o0, [%i1+0x20]
F007D310: 81c7e008                 ret
F007D314: 81e80000                 restore
