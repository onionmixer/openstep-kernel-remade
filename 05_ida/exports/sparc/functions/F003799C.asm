F003799C: 9de3bf98                 save    %sp, -0x68, %sp
F00379A0: 80a66001                 cmp     %i1, 1
F00379A4: 0280006d                 be      loc_F0037B58
F00379A8: 133c04e9                 sethi   -0xFEC5C00, %o1
F00379AC: 14800006                 bg      loc_F00379C4
F00379B0: 80a66002                 cmp     %i1, 2
F00379B4: 80a66000                 cmp     %i1, 0
F00379B8: 22800017                 be,a    loc_F0037A14
F00379BC: d0162012                 lduh    [%i0+0x12], %o0
F00379C0: 308000a7                 ba,a    locret_F0037C5C
F00379C4: 02800071                 be      loc_F0037B88
F00379C8: 80a66003                 cmp     %i1, 3
F00379CC: 128000a4                 bne     locret_F0037C5C
F00379D0: 01000000                 nop
F00379D4: d0562008                 ldsh    [%i0+8], %o0
F00379D8: 80a2200a                 cmp     %o0, 0xA
F00379DC: 0280000a                 be      loc_F0037A04
F00379E0: 133c04ea                 sethi   %hi(_tcp_maxidle), %o1
F00379E4: d0562058                 ldsh    [%i0+0x58], %o0
F00379E8: d2026058                 ld      [%o1+%lo(_tcp_maxidle)], %o1
F00379EC: 80a20009                 cmp     %o0, %o1
F00379F0: 14800005                 bg      loc_F0037A04
F00379F4: 113c0432                 sethi   %hi(_tcp_keepintvl), %o0
F00379F8: d0022120                 ld      [%o0+%lo(_tcp_keepintvl)], %o0
F00379FC: 10800098                 ba      locret_F0037C5C
F0037A00: d0362010                 sth     %o0, [%i0+0x10]
F0037A04: 7ffffeea                 call    _tcp_close
F0037A08: 90100018                 mov     %i0, %o0
F0037A0C: 10800094                 ba      locret_F0037C5C
F0037A10: b0100008                 mov     %o0, %i0
F0037A14: 90022001                 inc     %o0
F0037A18: d0362012                 sth     %o0, [%i0+0x12]
F0037A1C: 912a2010                 sll     %o0, 16, %o0
F0037A20: 913a2010                 sra     %o0, 16, %o0
F0037A24: 80a2200c                 cmp     %o0, 0xC
F0037A28: 0480000b                 ble     loc_F0037A54
F0037A2C: 173c04e9                 sethi   %hi(_tcpstat), %o3
F0037A30: 9010200c                 mov     0xC, %o0
F0037A34: d0362012                 sth     %o0, [%i0+0x12]
F0037A38: 90100018                 mov     %i0, %o0
F0037A3C: 9612e3a0                 bset    %lo(_tcpstat), %o3
F0037A40: d402e024                 ld      [%o3+0x24], %o2
F0037A44: 9210203c                 mov     0x3C, %o1 ! '<'
F0037A48: 9402a001                 inc     %o2
F0037A4C: 10800081                 ba      loc_F0037C50
F0037A50: d422e024                 st      %o2, [%o3+0x24]
F0037A54: 133c04e9921263a0         set     _tcpstat, %o1
F0037A5C: d0026028                 ld      [%o1+0x28], %o0
F0037A60: 153c0432                 sethi   %hi(_tcp_backoff), %o2
F0037A64: 90022001                 inc     %o0
F0037A68: d0226028                 st      %o0, [%o1+0x28]
F0037A6C: d2562012                 ldsh    [%i0+0x12], %o1
F0037A70: 9412a124                 bset    %lo(_tcp_backoff), %o2
F0037A74: d0162060                 lduh    [%i0+0x60], %o0
F0037A78: 932a6002                 sll     %o1, 2, %o1
F0037A7C: d202400a                 ld      [%o1+%o2], %o1
F0037A80: 912a2010                 sll     %o0, 16, %o0
F0037A84: d4562062                 ldsh    [%i0+0x62], %o2
F0037A88: 913a2013                 sra     %o0, 19, %o0
F0037A8C: 7fff3a9d                 call    _umul
F0037A90: 9002000a                 add     %o0, %o2, %o0
F0037A94: d0362014                 sth     %o0, [%i0+0x14]
F0037A98: 912a2010                 sll     %o0, 16, %o0
F0037A9C: d2162064                 lduh    [%i0+0x64], %o1
F0037AA0: 913a2010                 sra     %o0, 16, %o0
F0037AA4: 80a20009                 cmp     %o0, %o1
F0037AA8: 16800004                 bge     loc_F0037AB8
F0037AAC: 80a22080                 cmp     %o0, 0x80
F0037AB0: 10800005                 ba      loc_F0037AC4
F0037AB4: d2362014                 sth     %o1, [%i0+0x14]
F0037AB8: 04800003                 ble     loc_F0037AC4
F0037ABC: 90102080                 mov     0x80, %o0
F0037AC0: d0362014                 sth     %o0, [%i0+0x14]
F0037AC4: d0162014                 lduh    [%i0+0x14], %o0
F0037AC8: d2562012                 ldsh    [%i0+0x12], %o1
F0037ACC: 80a26003                 cmp     %o1, 3
F0037AD0: 0480000b                 ble     loc_F0037AFC
F0037AD4: d036200a                 sth     %o0, [%i0+0xA]
F0037AD8: 7fffe501                 call    _in_losing
F0037ADC: d0062020                 ld      [%i0+0x20], %o0
F0037AE0: d0162060                 lduh    [%i0+0x60], %o0
F0037AE4: d2162062                 lduh    [%i0+0x62], %o1
F0037AE8: 912a2010                 sll     %o0, 16, %o0
F0037AEC: 913a2012                 sra     %o0, 18, %o0
F0037AF0: 92024008                 add     %o1, %o0, %o1
F0037AF4: d2362062                 sth     %o1, [%i0+0x62]
F0037AF8: c0362060                 clrh    [%i0+0x60]
F0037AFC: d216203c                 lduh    [%i0+0x3C], %o1
F0037B00: d0062024                 ld      [%i0+0x24], %o0
F0037B04: c036205a                 clrh    [%i0+0x5A]
F0037B08: d4162054                 lduh    [%i0+0x54], %o2
F0037B0C: 80a2400a                 cmp     %o1, %o2
F0037B10: 08800003                 bleu    loc_F0037B1C
F0037B14: d0262028                 st      %o0, [%i0+0x28]
F0037B18: 9210000a                 mov     %o2, %o1! int
F0037B1C: f2162018                 lduh    [%i0+0x18], %i1
F0037B20: 91326001                 srl     %o1, 1, %o0! int
F0037B24: 7fff3ab9                 call    _div
F0037B28: 92100019                 mov     %i1, %o1
F0037B2C: 80a22001                 cmp     %o0, 1
F0037B30: 28800002                 bleu,a  loc_F0037B38
F0037B34: 90102002                 mov     2, %o0
F0037B38: f2362054                 sth     %i1, [%i0+0x54]
F0037B3C: d2162018                 lduh    [%i0+0x18], %o1
F0037B40: 7fff3a70                 call    _umul
F0037B44: c0362016                 clrh    [%i0+0x16]
F0037B48: d0362056                 sth     %o0, [%i0+0x56]
F0037B4C: 7ffffb8d                 call    _tcp_output
F0037B50: 90100018                 mov     %i0, %o0
F0037B54: 30800042                 ba,a    locret_F0037C5C
F0037B58: 921263a0                 bset    0x3A0, %o1
F0037B5C: d402602c                 ld      [%o1+0x2C], %o2
F0037B60: 90100018                 mov     %i0, %o0
F0037B64: 9402a001                 inc     %o2
F0037B68: 7ffffd86                 call    _tcp_setpersist
F0037B6C: d422602c                 st      %o2, [%o1+0x2C]
F0037B70: 90102001                 mov     1, %o0
F0037B74: d02e201a                 stb     %o0, [%i0+0x1A]
F0037B78: 7ffffb82                 call    _tcp_output
F0037B7C: 90100018                 mov     %i0, %o0
F0037B80: 10800037                 ba      locret_F0037C5C
F0037B84: c02e201a                 clrb    [%i0+0x1A]
F0037B88: 113c04e9961223a0         set     _tcpstat, %o3
F0037B90: d002e030                 ld      [%o3+0x30], %o0
F0037B94: 90022001                 inc     %o0
F0037B98: d022e030                 st      %o0, [%o3+0x30]
F0037B9C: d2562008                 ldsh    [%i0+8], %o1
F0037BA0: 80a26003                 cmp     %o1, 3
F0037BA4: 04800025                 ble     loc_F0037C38
F0037BA8: 90100018                 mov     %i0, %o0
F0037BAC: d0062020                 ld      [%i0+0x20], %o0
F0037BB0: d002201c                 ld      [%o0+0x1C], %o0
F0037BB4: d0122002                 lduh    [%o0+2], %o0
F0037BB8: 808a2008                 btst    8, %o0
F0037BBC: 0280001b                 be      loc_F0037C28
F0037BC0: 80a26005                 cmp     %o1, 5
F0037BC4: 1480001a                 bg      loc_F0037C2C
F0037BC8: 113c0432                 sethi   %hi(_tcp_keepidle), %o0
F0037BCC: d202211c                 ld      [%o0+%lo(_tcp_keepidle)], %o1
F0037BD0: 113c04ea                 sethi   %hi(_tcp_maxidle), %o0
F0037BD4: d0022058                 ld      [%o0+%lo(_tcp_maxidle)], %o0
F0037BD8: d4562058                 ldsh    [%i0+0x58], %o2
F0037BDC: 92024008                 add     %o1, %o0, %o1
F0037BE0: 80a28009                 cmp     %o2, %o1
F0037BE4: 16800015                 bge     loc_F0037C38
F0037BE8: 90100018                 mov     %i0, %o0
F0037BEC: d002e034                 ld      [%o3+0x34], %o0
F0037BF0: 94102000                 mov     0, %o2
F0037BF4: 90022001                 inc     %o0
F0037BF8: d022e034                 st      %o0, [%o3+0x34]
F0037BFC: d206201c                 ld      [%i0+0x1C], %o1
F0037C00: 9a102000                 mov     0, %o5
F0037C04: d8062024                 ld      [%i0+0x24], %o4
F0037C08: 90100018                 mov     %i0, %o0
F0037C0C: d6062040                 ld      [%i0+0x40], %o3
F0037C10: 7ffffdbe                 call    _tcp_respond
F0037C14: 98033fff                 inc     -1, %o4
F0037C18: 113c0432                 sethi   %hi(_tcp_keepintvl), %o0
F0037C1C: d0022120                 ld      [%o0+%lo(_tcp_keepintvl)], %o0
F0037C20: 1080000f                 ba      locret_F0037C5C
F0037C24: d036200e                 sth     %o0, [%i0+0xE]
F0037C28: 113c0432                 sethi   -0xFEF3800, %o0
F0037C2C: d002211c                 ld      [%o0+0x11C], %o0
F0037C30: 1080000b                 ba      locret_F0037C5C
F0037C34: d036200e                 sth     %o0, [%i0+0xE]
F0037C38: 173c04e99612e3a0         set     _tcpstat, %o3
F0037C40: d402e038                 ld      [%o3+0x38], %o2
F0037C44: 9210203c                 mov     0x3C, %o1 ! '<'
F0037C48: 9402a001                 inc     %o2
F0037C4C: d422e038                 st      %o2, [%o3+0x38]
F0037C50: 7ffffe37                 call    _tcp_drop
F0037C54: 01000000                 nop
F0037C58: b0100008                 mov     %o0, %i0
F0037C5C: 81c7e008                 ret
F0037C60: 81e80000                 restore
