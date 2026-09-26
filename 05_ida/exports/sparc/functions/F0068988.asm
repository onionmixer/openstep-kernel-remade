F0068988: 9de3bf98                 save    %sp, -0x68, %sp
F006898C: 153c04f09412a0c0         set     _stackStats, %o2
F0068994: d202a00c                 ld      [%o2+0xC], %o1
F0068998: 113c04f0a01220e0         set     _stack_queue_lock, %l0
F00689A0: 90100010                 mov     %l0, %o0
F00689A4: 92026001                 inc     %o1
F00689A8: 40000107                 call    _lock_write
F00689AC: d222a00c                 st      %o1, [%o2+0xC]
F00689B0: b0063ff4                 inc     -0xC, %i0
F00689B4: 90102001                 mov     1, %o0
F00689B8: d0262008                 st      %o0, [%i0+8]
F00689BC: 7fffff9b                 call    _canSwap
F00689C0: 90100018                 mov     %i0, %o0
F00689C4: 80a22000                 cmp     %o0, 0
F00689C8: 02800004                 be      loc_F00689D8
F00689CC: 01000000                 nop
F00689D0: 7fffffae                 call    _doSwapout
F00689D4: 90100018                 mov     %i0, %o0
F00689D8: 40000197                 call    _lock_done
F00689DC: 90100010                 mov     %l0, %o0
F00689E0: 81c7e008                 ret
F00689E4: 81e80000                 restore
