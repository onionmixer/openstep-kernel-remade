F008F4E8: 9de3bf98                 save    %sp, -0x68, %sp
F008F4EC: a2100018                 mov     %i0, %l1
F008F4F0: a0102000                 mov     0, %l0
F008F4F4: 293c0504                 sethi   %hi(paCount_0), %l4
F008F4F8: 273c0504                 sethi   -0xFEBF000, %l3
F008F4FC: 253c0504                 sethi   -0xFEBF000, %l2
F008F500: d20520b8                 ld      [%l4+%lo(paCount_0)], %o1! SEL
F008F504: 400188db                 call    _objc_msgSend
F008F508: 90100011                 mov     %l1, %o0
F008F50C: 80a40008                 cmp     %l0, %o0
F008F510: 1a80000d                 bcc     loc_F008F544
F008F514: 90100011                 mov     %l1, %o0! id
F008F518: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F008F51C: 400188d5                 call    _objc_msgSend
F008F520: 94100010                 mov     %l0, %o2
F008F524: b0100008                 mov     %o0, %i0
F008F528: 400188d2                 call    _objc_msgSend
F008F52C: d204a11c                 ld      [%l2+0x11C], %o1
F008F530: 80a20019                 cmp     %o0, %i1
F008F534: 02800005                 be      locret_F008F548
F008F538: a0042001                 inc     %l0
F008F53C: 10bffff2                 ba      loc_F008F504
F008F540: d20520b8                 ld      [%l4+0xB8], %o1
F008F544: b0102000                 mov     0, %i0
F008F548: 81c7e008                 ret
F008F54C: 81e80000                 restore
