F00435A8: 9de3bf98                 save    %sp, -0x68, %sp
F00435AC: b2102000                 mov     0, %i1
F00435B0: 053c04368610a2a0         set     unk_F010DAA0, %g3
F00435B8: c400c000                 ld      [%g3], %g2
F00435BC: 80a08018                 cmp     %g2, %i0
F00435C0: 12800004                 bne     loc_F00435D0
F00435C4: b2066001                 inc     %i1
F00435C8: 10800007                 ba      locret_F00435E4
F00435CC: f000e004                 ld      [%g3+4], %i0
F00435D0: 80a66010                 cmp     %i1, 0x10
F00435D4: 08bffff9                 bleu    loc_F00435B8
F00435D8: 8600e008                 inc     8, %g3
F00435DC: 313c0437b0162120         set     aRpcUnknownErro, %i0! "RPC: (unknown error code)"
F00435E4: 81c7e008                 ret
F00435E8: 81e80000                 restore
