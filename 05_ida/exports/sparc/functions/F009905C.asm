F009905C: 9de3bf98                 save    %sp, -0x68, %sp
F0099060: 80a66000                 cmp     %i1, 0
F0099064: 02800032                 be      locret_F009912C
F0099068: 80a6204f                 cmp     %i0, 0x4F ! 'O'
F009906C: 08800004                 bleu    loc_F009907C
F0099070: 113c045b                 sethi   %hi(aAddintrVectorN), %o0! "addintr: vector number out of range"
F0099074: 7ffdf03f                 call    _panic
F0099078: 90122218                 bset    %lo(aAddintrVectorN), %o0! "addintr: vector number out of range"
F009907C: 113c045b901220d4         set     _vectorlist, %o0
F0099084: 932e2002                 sll     %i0, 2, %o1
F0099088: f0024008                 ld      [%o1+%o0], %i0
F009908C: 80a62000                 cmp     %i0, 0
F0099090: 32800006                 bne,a   loc_F00990A8
F0099094: d006200c                 ld      [%i0+0xC], %o0
F0099098: 113c045b                 sethi   %hi(aAddintrSpecifi), %o0! "addintr: specified vector can not be po"...
F009909C: 7ffdf035                 call    _panic
F00990A0: 90122240                 bset    %lo(aAddintrSpecifi), %o0! "addintr: specified vector can not be po"...
F00990A4: d006200c                 ld      [%i0+0xC], %o0
F00990A8: 80a23fff                 cmp     %o0, -1
F00990AC: 12800006                 bne     loc_F00990C4
F00990B0: 92102000                 mov     0, %o1
F00990B4: 113c045b                 sethi   %hi(aAddintrInterru), %o0! "addintr: interrupt trap vector busy\n"
F00990B8: 7ffdf02e                 call    _panic
F00990BC: 90122270                 bset    %lo(aAddintrInterru), %o0! "addintr: interrupt trap vector busy\n"
F00990C0: 92102000                 mov     0, %o1! size_t
F00990C4: a0062014                 add     %i0, 0x14, %l0
F00990C8: d0060000                 ld      [%i0], %o0
F00990CC: 80a22000                 cmp     %o0, 0
F00990D0: 12800009                 bne     loc_F00990F4
F00990D4: 80a20019                 cmp     %o0, %i1
F00990D8: 90100018                 mov     %i0, %o0! void *
F00990DC: 7fffef5f                 call    _bzero
F00990E0: 92102018                 mov     0x18, %o1
F00990E4: f2260000                 st      %i1, [%i0]
F00990E8: f8243ffc                 st      %i4, [%l0-4]
F00990EC: 10800004                 ba      loc_F00990FC
F00990F0: fa240000                 st      %i5, [%l0]
F00990F4: 12800007                 bne     loc_F0099110
F00990F8: a0042018                 inc     0x18, %l0
F00990FC: 90100018                 mov     %i0, %o0
F0099100: 9210001a                 mov     %i2, %o1
F0099104: 40000046                 call    sub_F009921C
F0099108: 9410001b                 mov     %i3, %o2
F009910C: 30800008                 ba,a    locret_F009912C
F0099110: 92026001                 inc     %o1
F0099114: 80a26009                 cmp     %o1, 9
F0099118: 04bfffec                 ble     loc_F00990C8
F009911C: b0062018                 inc     0x18, %i0
F0099120: 113c045b                 sethi   %hi(aAddintrTooMany), %o0! "addintr: too many devices"
F0099124: 7ffdf013                 call    _panic
F0099128: 90122298                 bset    %lo(aAddintrTooMany), %o0! "addintr: too many devices"
F009912C: 81c7e008                 ret
F0099130: 81e80000                 restore
