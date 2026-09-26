F001449C: 9de3bf98                 save    %sp, -0x68, %sp
F00144A0: 113c04d4                 sethi   %hi(_log_open), %o0
F00144A4: d0022178                 ld      [%o0+%lo(_log_open)], %o0
F00144A8: 80a22000                 cmp     %o0, 0
F00144AC: 02800020                 be      locret_F001452C
F00144B0: 01000000                 nop
F00144B4: 400209b5                 call    _splusclock
F00144B8: 01000000                 nop
F00144BC: 133c04d4                 sethi   %hi(dword_F0135184), %o1
F00144C0: e0026184                 ld      [%o1+%lo(dword_F0135184)], %l0
F00144C4: a2126184                 or      %o1, %lo(dword_F0135184), %l1
F00144C8: 40020a17                 call    _splx
F00144CC: c0226184                 clr     [%o1+%lo(dword_F0135184)]
F00144D0: 80a42000                 cmp     %l0, 0
F00144D4: 02800006                 be      loc_F00144EC
F00144D8: 90100010                 mov     %l0, %o0
F00144DC: 4000070e                 call    _selwakeup
F00144E0: 92102000                 mov     0, %o1
F00144E4: 4001809c                 call    _thread_deallocate_interrupt
F00144E8: 90100010                 mov     %l0, %o0
F00144EC: d0047ffc                 ld      [%l1-4], %o0
F00144F0: 808a2004                 btst    4, %o0
F00144F4: 02800007                 be      loc_F0014510
F00144F8: 808a2008                 btst    8, %o0
F00144FC: d0046004                 ld      [%l1+4], %o0
F0014500: 7ffff3f7                 call    _gsignal
F0014504: 92102017                 mov     0x17, %o1
F0014508: d0047ffc                 ld      [%l1-4], %o0
F001450C: 808a2008                 btst    8, %o0
F0014510: 02800007                 be      locret_F001452C
F0014514: 113c042d                 sethi   %hi(_pmsgbuf), %o0
F0014518: 7ffffa34                 call    _wakeup
F001451C: d002208c                 ld      [%o0+%lo(_pmsgbuf)], %o0
F0014520: d0047ffc                 ld      [%l1-4], %o0
F0014524: 900a3ff7                 and     %o0, -9, %o0
F0014528: d0247ffc                 st      %o0, [%l1-4]
F001452C: 81c7e008                 ret
F0014530: 81e80000                 restore
