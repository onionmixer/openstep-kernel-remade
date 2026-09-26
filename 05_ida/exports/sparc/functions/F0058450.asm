F0058450: 9de3bf98                 save    %sp, -0x68, %sp
F0058454: 40001a5c                 call    _ipc_thread_dequeue
F0058458: 90062008                 add     %i0, 8, %o0
F005845C: 80a22000                 cmp     %o0, 0
F0058460: 02800005                 be      locret_F0058474
F0058464: 01000000                 nop
F0058468: 4000386b                 call    _thread_go
F005846C: f2222098                 st      %i1, [%o0+0x98]
F0058470: 30bffff9                 ba,a    loc_F0058454
F0058474: 81c7e008                 ret
F0058478: 81e80000                 restore
