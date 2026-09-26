F00B045C: 9de3bf98                 save    %sp, -0x68, %sp
F00B0460: 7ffffc0f                 call    _prom_childnode
F00B0464: 90100018                 mov     %i0, %o0
F00B0468: a2920000                 orcc    %o0, %g0, %l1
F00B046C: 12800004                 bne     loc_F00B047C
F00B0470: a0100011                 mov     %l1, %l0
F00B0474: 10800019                 ba      locret_F00B04D8
F00B0478: b0102000                 mov     0, %i0
F00B047C: 80a40019                 cmp     %l0, %i1
F00B0480: 02800016                 be      locret_F00B04D8
F00B0484: 01000000                 nop
F00B0488: 7ffffbfc                 call    _prom_nextnode
F00B048C: 90100010                 mov     %l0, %o0
F00B0490: a0920000                 orcc    %o0, %g0, %l0
F00B0494: 12bffffb                 bne     loc_F00B0480
F00B0498: 80a40019                 cmp     %l0, %i1
F00B049C: a0944000                 orcc    %l1, %g0, %l0
F00B04A0: 2280000e                 be,a    locret_F00B04D8
F00B04A4: b0102000                 mov     0, %i0
F00B04A8: 90100010                 mov     %l0, %o0
F00B04AC: 7fffffec                 call    sub_F00B045C
F00B04B0: 92100019                 mov     %i1, %o1
F00B04B4: 80a22000                 cmp     %o0, 0
F00B04B8: 32800008                 bne,a   locret_F00B04D8
F00B04BC: b0100008                 mov     %o0, %i0
F00B04C0: 7ffffbee                 call    _prom_nextnode
F00B04C4: 90100010                 mov     %l0, %o0
F00B04C8: a0920000                 orcc    %o0, %g0, %l0
F00B04CC: 12bffff8                 bne     loc_F00B04AC
F00B04D0: 90100010                 mov     %l0, %o0
F00B04D4: b0102000                 mov     0, %i0
F00B04D8: 81c7e008                 ret
F00B04DC: 81e80000                 restore
