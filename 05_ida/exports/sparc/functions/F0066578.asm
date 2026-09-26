F0066578: 9de3bf98                 save    %sp, -0x68, %sp
F006657C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0066580: f0022260                 ld      [%o0+%lo(_active_threads)], %i0
F0066584: d00620bc                 ld      [%i0+0xBC], %o0
F0066588: 80a22000                 cmp     %o0, 0
F006658C: 32800006                 bne,a   locret_F00665A4
F0066590: f00620bc                 ld      [%i0+0xBC], %i0
F0066594: 400002ff                 call    _mach_reply_port
F0066598: 01000000                 nop
F006659C: d02620bc                 st      %o0, [%i0+0xBC]
F00665A0: f00620bc                 ld      [%i0+0xBC], %i0
F00665A4: 81c7e008                 ret
F00665A8: 81e80000                 restore
