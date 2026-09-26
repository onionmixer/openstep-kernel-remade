F007D21C: 9de3bf90                 save    %sp, -0x70, %sp
F007D220: d0062004                 ld      [%i0+4], %o0
F007D224: 80a22024                 cmp     %o0, 0x24 ! '$'
F007D228: 12800016                 bne     loc_F007D280
F007D22C: 90103ed0                 mov     -0x130, %o0
F007D230: d0060000                 ld      [%i0], %o0
F007D234: 80a22000                 cmp     %o0, 0
F007D238: 36800004                 bge,a   loc_F007D248
F007D23C: d0062018                 ld      [%i0+0x18], %o0
F007D240: 10800010                 ba      loc_F007D280
F007D244: 90103ed0                 mov     -0x130, %o0
F007D248: 133c0444                 sethi   %hi(dword_F0111128), %o1
F007D24C: d2026128                 ld      [%o1+%lo(dword_F0111128)], %o1
F007D250: 80a20009                 cmp     %o0, %o1
F007D254: 22800004                 be,a    loc_F007D264
F007D258: d006201c                 ld      [%i0+0x1C], %o0
F007D25C: 10800009                 ba      loc_F007D280
F007D260: 90103ed0                 mov     -0x130, %o0
F007D264: d027bff0                 st      %o0, [%fp+var_10]
F007D268: d0062020                 ld      [%i0+0x20], %o0
F007D26C: d027bff4                 st      %o0, [%fp+var_C]
F007D270: 7fffa024                 call    _convert_port_to_host_priv
F007D274: d0062008                 ld      [%i0+8], %o0
F007D278: 7fffb232                 call    _host_set_time
F007D27C: 9207bff0                 add     %fp, var_10, %o1
F007D280: d026601c                 st      %o0, [%i1+0x1C]
F007D284: 81c7e008                 ret
F007D288: 81e80000                 restore
