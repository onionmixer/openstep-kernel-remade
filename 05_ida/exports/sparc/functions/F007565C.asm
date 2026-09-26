F007565C: 9de3bf98                 save    %sp, -0x68, %sp
F0075660: a0960000                 orcc    %i0, %g0, %l0
F0075664: 02800006                 be      loc_F007567C
F0075668: 113c04d0                 sethi   %hi(_active_threads), %o0
F007566C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0075670: 80a40008                 cmp     %l0, %o0
F0075674: 12800004                 bne     loc_F0075684
F0075678: 01000000                 nop
F007567C: 1080000f                 ba      locret_F00756B8
F0075680: b0102004                 mov     4, %i0
F0075684: 7ffffef6                 call    _thread_hold
F0075688: 90100010                 mov     %l0, %o0
F007568C: 90100010                 mov     %l0, %o0
F0075690: 7fffff0b                 call    _thread_dowait
F0075694: 92102001                 mov     1, %o1
F0075698: 90100010                 mov     %l0, %o0
F007569C: 92100019                 mov     %i1, %o1
F00756A0: 9410001a                 mov     %i2, %o2
F00756A4: 40009934                 call    _thread_getstatus
F00756A8: 9610001b                 mov     %i3, %o3
F00756AC: b0100008                 mov     %o0, %i0
F00756B0: 7fffff61                 call    _thread_release
F00756B4: 90100010                 mov     %l0, %o0
F00756B8: 81c7e008                 ret
F00756BC: 81e80000                 restore
