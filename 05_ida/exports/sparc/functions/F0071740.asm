F0071740: 9de3bf98                 save    %sp, -0x68, %sp
F0071744: 113c04d0                 sethi   %hi(_active_threads), %o0
F0071748: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F007174C: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F0071750: 4000950e                 call    _splusclock
F0071754: e00221b0                 ld      [%o0+%lo(_processor_ptr)], %l0
F0071758: a4100008                 mov     %o0, %l2
F007175C: 133c04cf                 sethi   %hi(_need_ast), %o1
F0071760: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0071764: 900a3ffb                 and     %o0, -5, %o0
F0071768: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F007176C: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0071770: 7ffffeaf                 call    _thread_select
F0071774: 90100010                 mov     %l0, %o0
F0071778: 94100008                 mov     %o0, %o2
F007177C: 90100011                 mov     %l1, %o0
F0071780: 7fffff1a                 call    _thread_invoke
F0071784: 92100018                 mov     %i0, %o1
F0071788: 80a22000                 cmp     %o0, 0
F007178C: 02bffff9                 be      loc_F0071770
F0071790: 01000000                 nop
F0071794: 40009564                 call    _splx
F0071798: 90100012                 mov     %l2, %o0
F007179C: 81c7e008                 ret
F00717A0: 81e80000                 restore
