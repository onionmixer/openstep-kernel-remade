F003752C: 9de3bf98                 save    %sp, -0x68, %sp
F0037530: d0062020                 ld      [%i0+0x20], %o0
F0037534: d2562008                 ldsh    [%i0+8], %o1
F0037538: 80a26002                 cmp     %o1, 2
F003753C: 0480000b                 ble     loc_F0037568
F0037540: e002201c                 ld      [%o0+0x1C], %l0
F0037544: c0362008                 clrh    [%i0+8]
F0037548: 7ffffd0e                 call    _tcp_output
F003754C: 90100018                 mov     %i0, %o0
F0037550: 133c04e9921263a0         set     _tcpstat, %o1
F0037558: d002600c                 ld      [%o1+0xC], %o0
F003755C: 90022001                 inc     %o0
F0037560: 10800007                 ba      loc_F003757C
F0037564: d022600c                 st      %o0, [%o1+0xC]
F0037568: 133c04e9921263a0         set     _tcpstat, %o1
F0037570: d0026010                 ld      [%o1+0x10], %o0
F0037574: 90022001                 inc     %o0
F0037578: d0226010                 st      %o0, [%o1+0x10]
F003757C: 80a6603c                 cmp     %i1, 0x3C ! '<'
F0037580: 32800007                 bne,a   loc_F003759C
F0037584: f2342056                 sth     %i1, [%l0+0x56]
F0037588: d056206a                 ldsh    [%i0+0x6A], %o0
F003758C: 80a22000                 cmp     %o0, 0
F0037590: 32800002                 bne,a   loc_F0037598
F0037594: b2100008                 mov     %o0, %i1
F0037598: f2342056                 sth     %i1, [%l0+0x56]
F003759C: 40000004                 call    _tcp_close
F00375A0: 90100018                 mov     %i0, %o0
F00375A4: 81c7e008                 ret
F00375A8: 91e80008                 restore %g0, %o0, %o0
