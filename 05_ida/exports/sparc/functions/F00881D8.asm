F00881D8: 9de3bf98                 save    %sp, -0x68, %sp
F00881DC: 80a62000                 cmp     %i0, 0
F00881E0: 12800006                 bne     loc_F00881F8
F00881E4: 9210001a                 mov     %i2, %o1
F00881E8: 400005cd                 call    _vm_page_zero_fill
F00881EC: 90100019                 mov     %i1, %o0
F00881F0: 1080000d                 ba      locret_F0088224
F00881F4: b0102000                 mov     0, %i0
F00881F8: d0060000                 ld      [%i0], %o0
F00881FC: 80a22000                 cmp     %o0, 0
F0088200: 12800006                 bne     loc_F0088218
F0088204: 01000000                 nop
F0088208: 40000cfd                 call    _vnode_pagein
F008820C: 90100019                 mov     %i1, %o0
F0088210: 10800005                 ba      locret_F0088224
F0088214: b0100008                 mov     %o0, %i0
F0088218: 4000089d                 call    _device_pagein
F008821C: 90100019                 mov     %i1, %o0
F0088220: b0100008                 mov     %o0, %i0
F0088224: 81c7e008                 ret
F0088228: 81e80000                 restore
