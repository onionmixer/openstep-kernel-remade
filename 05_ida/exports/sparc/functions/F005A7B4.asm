F005A7B4: 9de3bf98                 save    %sp, -0x68, %sp
F005A7B8: d006203c                 ld      [%i0+0x3C], %o0
F005A7BC: 80a64008                 cmp     %i1, %o0
F005A7C0: 28800013                 bleu,a  locret_F005A80C
F005A7C4: f226203c                 st      %i1, [%i0+0x3C]
F005A7C8: a0102000                 mov     0, %l0
F005A7CC: a2264008                 sub     %i1, %o0, %l1
F005A7D0: 80a40011                 cmp     %l0, %l1
F005A7D4: 3a80000e                 bcc,a   locret_F005A80C
F005A7D8: f226203c                 st      %i1, [%i0+0x3C]
F005A7DC: 4000117a                 call    _ipc_thread_dequeue
F005A7E0: 9006204c                 add     %i0, 0x4C, %o0 ! 'L'
F005A7E4: 80a22000                 cmp     %o0, 0
F005A7E8: 22800009                 be,a    locret_F005A80C
F005A7EC: f226203c                 st      %i1, [%i0+0x3C]
F005A7F0: 40002f89                 call    _thread_go
F005A7F4: c0222098                 clr     [%o0+0x98]
F005A7F8: a0042001                 inc     %l0
F005A7FC: 80a40011                 cmp     %l0, %l1
F005A800: 0abffff7                 bcs     loc_F005A7DC
F005A804: 01000000                 nop
F005A808: f226203c                 st      %i1, [%i0+0x3C]
F005A80C: 81c7e008                 ret
F005A810: 81e80000                 restore
