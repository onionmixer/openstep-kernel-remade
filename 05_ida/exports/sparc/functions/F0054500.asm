F0054500: 9de3bf98                 save    %sp, -0x68, %sp
F0054504: a0102000                 mov     0, %l0
F0054508: 90100018                 mov     %i0, %o0
F005450C: 92100019                 mov     %i1, %o1
F0054510: 9410001a                 mov     %i2, %o2
F0054514: 400000bc                 call    _ipc_hash_local_lookup
F0054518: 9610001b                 mov     %i3, %o3
F005451C: 80a22000                 cmp     %o0, 0
F0054520: 3280000d                 bne,a   locret_F0054554
F0054524: a0102001                 mov     1, %l0
F0054528: d0062040                 ld      [%i0+0x40], %o0
F005452C: 80a22000                 cmp     %o0, 0
F0054530: 02800009                 be      locret_F0054554
F0054534: 90100018                 mov     %i0, %o0
F0054538: 92100019                 mov     %i1, %o1
F005453C: 9410001a                 mov     %i2, %o2
F0054540: 40000031                 call    _ipc_hash_global_lookup
F0054544: 9610001b                 mov     %i3, %o3
F0054548: 80a22000                 cmp     %o0, 0
F005454C: 32800002                 bne,a   locret_F0054554
F0054550: a0102001                 mov     1, %l0
F0054554: 81c7e008                 ret
F0054558: 91e80010                 restore %g0, %l0, %o0
