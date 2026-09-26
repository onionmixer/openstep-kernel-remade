F0038248: 9de3bf98                 save    %sp, -0x68, %sp
F003824C: a2100018                 mov     %i0, %l1
F0038250: d014603e                 lduh    [%l1+0x3E], %o0
F0038254: 80a22000                 cmp     %o0, 0
F0038258: 02800007                 be      loc_F0038274
F003825C: 113c0432                 sethi   -0xFEF3800, %o0
F0038260: d0146026                 lduh    [%l1+0x26], %o0
F0038264: 80a22000                 cmp     %o0, 0
F0038268: 3280000c                 bne,a   loc_F0038298
F003826C: 90100011                 mov     %l1, %o0
F0038270: 113c0432                 sethi   -0xFEF3800, %o0
F0038274: d2022164                 ld      [%o0+0x164], %o1
F0038278: 113c0432                 sethi   %hi(_tcp_recvspace), %o0
F003827C: d4022168                 ld      [%o0+%lo(_tcp_recvspace)], %o2
F0038280: 7fffa07d                 call    _soreserve
F0038284: 90100011                 mov     %l1, %o0
F0038288: 80a22000                 cmp     %o0, 0
F003828C: 1280001b                 bne     locret_F00382F8
F0038290: b0100008                 mov     %o0, %i0
F0038294: 90100011                 mov     %l1, %o0
F0038298: 133c04d9                 sethi   %hi(_tcb), %o1
F003829C: 7fffe100                 call    _in_pcballoc
F00382A0: 92126340                 bset    %lo(_tcb), %o1
F00382A4: 80a22000                 cmp     %o0, 0
F00382A8: 12800014                 bne     locret_F00382F8
F00382AC: b0100008                 mov     %o0, %i0
F00382B0: f0046008                 ld      [%l1+8], %i0
F00382B4: 7ffffc7d                 call    _tcp_newtcpcb
F00382B8: 90100018                 mov     %i0, %o0
F00382BC: 80a22000                 cmp     %o0, 0
F00382C0: 22800005                 be,a    loc_F00382D4
F00382C4: e0146006                 lduh    [%l1+6], %l0
F00382C8: c0322008                 clrh    [%o0+8]
F00382CC: 1080000b                 ba      locret_F00382F8
F00382D0: b0102000                 mov     0, %i0
F00382D4: 90100018                 mov     %i0, %o0
F00382D8: 920c3ffe                 and     %l0, -2, %o1
F00382DC: d2346006                 sth     %o1, [%l1+6]
F00382E0: 7fffe270                 call    _in_pcbdetach
F00382E4: a00c2001                 and     %l0, 1, %l0
F00382E8: d0146006                 lduh    [%l1+6], %o0
F00382EC: b0102037                 mov     0x37, %i0 ! '7'
F00382F0: 90120010                 bset    %l0, %o0
F00382F4: d0346006                 sth     %o0, [%l1+6]
F00382F8: 81c7e008                 ret
F00382FC: 81e80000                 restore
