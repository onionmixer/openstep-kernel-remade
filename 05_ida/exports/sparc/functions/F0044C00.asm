F0044C00: 9de3bf98                 save    %sp, -0x68, %sp
F0044C04: 233c04eb                 sethi   -0xFEC5400, %l1
F0044C08: 40014823                 call    _splnet
F0044C0C: 01000000                 nop
F0044C10: d4060000                 ld      [%i0], %o2
F0044C14: d212a024                 lduh    [%o2+0x24], %o1
F0044C18: 80a26000                 cmp     %o1, 0
F0044C1C: 12800009                 bne     loc_F0044C40
F0044C20: a0100008                 mov     %o0, %l0
F0044C24: 7fff6dcf                 call    _sbwait
F0044C28: 9002a024                 add     %o2, 0x24, %o0 ! '$'
F0044C2C: d4060000                 ld      [%i0], %o2
F0044C30: d012a024                 lduh    [%o2+0x24], %o0
F0044C34: 80a22000                 cmp     %o0, 0
F0044C38: 02bffffb                 be      loc_F0044C24
F0044C3C: 01000000                 nop
F0044C40: 40014839                 call    _splx
F0044C44: 90100010                 mov     %l0, %o0! int
F0044C48: 7fffff7b                 call    _svc_getreq
F0044C4C: 90100018                 mov     %i0, %o0
F0044C50: d0046060                 ld      [%l1+0x60], %o0
F0044C54: 90022001                 inc     %o0
F0044C58: 10bfffec                 ba      loc_F0044C08
F0044C5C: d0246060                 st      %o0, [%l1+0x60]
