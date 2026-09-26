F00375AC: 9de3bf98                 save    %sp, -0x68, %sp
F00375B0: e2062020                 ld      [%i0+0x20], %l1
F00375B4: e0060000                 ld      [%i0], %l0
F00375B8: 80a40018                 cmp     %l0, %i0
F00375BC: 0280000f                 be      loc_F00375F8
F00375C0: e404601c                 ld      [%l1+0x1C], %l2
F00375C4: e0040000                 ld      [%l0], %l0
F00375C8: d2042004                 ld      [%l0+4], %o1
F00375CC: d6024000                 ld      [%o1], %o3
F00375D0: d4026004                 ld      [%o1+4], %o2
F00375D4: d0026014                 ld      [%o1+0x14], %o0
F00375D8: d422e004                 st      %o2, [%o3+4]
F00375DC: d4026004                 ld      [%o1+4], %o2
F00375E0: d2024000                 ld      [%o1], %o1
F00375E4: 7fff99a0                 call    _m_freem
F00375E8: d2228000                 st      %o1, [%o2]
F00375EC: 80a40018                 cmp     %l0, %i0
F00375F0: 32bffff6                 bne,a   loc_F00375C8
F00375F4: e0040000                 ld      [%l0], %l0
F00375F8: d006201c                 ld      [%i0+0x1C], %o0
F00375FC: 80a22000                 cmp     %o0, 0
F0037600: 22800005                 be,a    loc_F0037614
F0037604: 90100018                 mov     %i0, %o0
F0037608: 7fff992b                 call    _m_free
F003760C: 900a3f80                 and     %o0, -0x80, %o0
F0037610: 90100018                 mov     %i0, %o0
F0037614: 4000c2e3                 call    _kfree
F0037618: 9210206c                 mov     0x6C, %o1 ! 'l'
F003761C: c0246020                 clr     [%l1+0x20]
F0037620: 7fffa29e                 call    _soisdisconnected
F0037624: 90100012                 mov     %l2, %o0
F0037628: 133c0432                 sethi   %hi(_tcp_last_inpcb), %o1
F003762C: d00260ac                 ld      [%o1+%lo(_tcp_last_inpcb)], %o0
F0037630: 80a44008                 cmp     %l1, %o0
F0037634: 12800004                 bne     loc_F0037644
F0037638: 113c04d9                 sethi   %hi(_tcb), %o0
F003763C: 90122340                 bset    %lo(_tcb), %o0
F0037640: d02260ac                 st      %o0, [%o1+%lo(_tcp_last_inpcb)]
F0037644: 7fffe597                 call    _in_pcbdetach
F0037648: 90100011                 mov     %l1, %o0
F003764C: 133c04e9921263a0         set     _tcpstat, %o1
F0037654: d0026014                 ld      [%o1+0x14], %o0
F0037658: 90022001                 inc     %o0
F003765C: d0226014                 st      %o0, [%o1+0x14]
F0037660: 81c7e008                 ret
F0037664: 91e82000                 restore %g0, 0, %o0
