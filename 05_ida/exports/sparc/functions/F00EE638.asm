F00EE638: 9de3bf88                 save    %sp, -0x78, %sp
F00EE63C: 80a60019                 cmp     %i0, %i1
F00EE640: 2280001b                 be,a    locret_F00EE6AC
F00EE644: b0102001                 mov     1, %i0
F00EE648: d2062004                 ld      [%i0+4], %o1
F00EE64C: d0066004                 ld      [%i1+4], %o0
F00EE650: 80a24008                 cmp     %o1, %o0
F00EE654: 32800016                 bne,a   locret_F00EE6AC
F00EE658: b0102000                 mov     0, %i0
F00EE65C: 40000255                 call    _NXInitMapState
F00EE660: 90100018                 mov     %i0, %o0
F00EE664: d027bff4                 st      %o0, [%fp+var_C]
F00EE668: 90100018                 mov     %i0, %o0
F00EE66C: 9207bff4                 add     %fp, var_C, %o1
F00EE670: 9407bff0                 add     %fp, var_10, %o2
F00EE674: 40000251                 call    _NXNextMapState
F00EE678: 9607bfec                 add     %fp, var_14, %o3
F00EE67C: 80a22000                 cmp     %o0, 0
F00EE680: 12800004                 bne     loc_F00EE690
F00EE684: 90100019                 mov     %i1, %o0
F00EE688: 10800009                 ba      locret_F00EE6AC
F00EE68C: b0102001                 mov     1, %i0
F00EE690: d207bff0                 ld      [%fp+var_10], %o1
F00EE694: 4000000a                 call    _NXMapMember
F00EE698: 9407bfec                 add     %fp, var_14, %o2
F00EE69C: 80a23fff                 cmp     %o0, -1
F00EE6A0: 12bffff3                 bne     loc_F00EE66C
F00EE6A4: 90100018                 mov     %i0, %o0
F00EE6A8: b0102000                 mov     0, %i0
F00EE6AC: 81c7e008                 ret
F00EE6B0: 81e80000                 restore
