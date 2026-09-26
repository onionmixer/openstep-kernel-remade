F002A0C4: 9de3bf98                 save    %sp, -0x68, %sp
F002A0C8: d0168000                 lduh    [%i2], %o0
F002A0CC: 80a22002                 cmp     %o0, 2
F002A0D0: 02800006                 be      loc_F002A0E8
F002A0D4: 92100019                 mov     %i1, %o1
F002A0D8: 40000673                 call    _nb_free
F002A0DC: 90100009                 mov     %o1, %o0
F002A0E0: 1080000f                 ba      locret_F002A11C
F002A0E4: b010202f                 mov     0x2F, %i0 ! '/'
F002A0E8: 400014ea                 call    _inet_queue
F002A0EC: 90100018                 mov     %i0, %o0
F002A0F0: 40000759                 call    _if_opackets
F002A0F4: 90100018                 mov     %i0, %o0
F002A0F8: 92022001                 add     %o0, 1, %o1
F002A0FC: 4000076e                 call    _if_opackets_set
F002A100: 90100018                 mov     %i0, %o0
F002A104: 40000758                 call    _if_ipackets
F002A108: 90100018                 mov     %i0, %o0
F002A10C: 92022001                 add     %o0, 1, %o1
F002A110: 4000076d                 call    _if_ipackets_set
F002A114: 90100018                 mov     %i0, %o0
F002A118: b0102000                 mov     0, %i0
F002A11C: 81c7e008                 ret
F002A120: 81e80000                 restore
