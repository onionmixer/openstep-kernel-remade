F00553A0: 9de3bf98                 save    %sp, -0x68, %sp
F00553A4: c0266010                 clr     [%i1+0x10]
F00553A8: 90066014                 add     %i1, 0x14, %o0
F00553AC: 92100018                 mov     %i0, %o1
F00553B0: 40010b5d                 call    _copyoutmsg
F00553B4: 9410001a                 mov     %i2, %o2
F00553B8: 80a22000                 cmp     %o0, 0
F00553BC: 02800004                 be      loc_F00553CC
F00553C0: 11040010                 sethi   0x10004000, %o0
F00553C4: 10800003                 ba      loc_F00553D0
F00553C8: b0122008                 or      %o0, 8, %i0
F00553CC: b0102000                 mov     0, %i0
F00553D0: d0066008                 ld      [%i1+8], %o0
F00553D4: 80a22100                 cmp     %o0, 0x100
F00553D8: 3280000c                 bne,a   loc_F0055408
F00553DC: d2066008                 ld      [%i1+8], %o1
F00553E0: 133c04ef                 sethi   %hi(_ipc_kmsg_cache), %o1
F00553E4: d0026348                 ld      [%o1+%lo(_ipc_kmsg_cache)], %o0
F00553E8: 80a22000                 cmp     %o0, 0
F00553EC: 32800007                 bne,a   loc_F0055408
F00553F0: d2066008                 ld      [%i1+8], %o1
F00553F4: 1080000a                 ba      locret_F005541C
F00553F8: f2226348                 st      %i1, [%o1+%lo(_ipc_kmsg_cache)]
F00553FC: 40004b69                 call    _kfree
F0055400: 90100019                 mov     %i1, %o0
F0055404: 30800006                 ba,a    locret_F005541C
F0055408: 80a26000                 cmp     %o1, 0
F005540C: 14bffffc                 bg      loc_F00553FC
F0055410: 01000000                 nop
F0055414: 7fffff7b                 call    _ipc_kmsg_free
F0055418: 90100019                 mov     %i1, %o0
F005541C: 81c7e008                 ret
F0055420: 81e80000                 restore
