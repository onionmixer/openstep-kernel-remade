F0073874: 9de3bf98                 save    %sp, -0x68, %sp
F0073878: 80a62000                 cmp     %i0, 0
F007387C: 12800004                 bne     loc_F007388C
F0073880: a6102000                 mov     0, %l3
F0073884: 1080006b                 ba      locret_F0073A30
F0073888: b0102004                 mov     4, %i0
F007388C: ae102000                 mov     0, %l7
F0073890: d0060000                 ld      [%i0], %o0
F0073894: 80a22000                 cmp     %o0, 0
F0073898: 12bffffe                 bne     loc_F0073890
F007389C: 01000000                 nop
F00738A0: 40008d82                 call    _simple_lock_try
F00738A4: 90100018                 mov     %i0, %o0
F00738A8: 80a22000                 cmp     %o0, 0
F00738AC: 02bffff9                 be      loc_F0073890
F00738B0: 01000000                 nop
F00738B4: d0062008                 ld      [%i0+8], %o0
F00738B8: 80a22000                 cmp     %o0, 0
F00738BC: 02800045                 be      loc_F00739D0
F00738C0: 01000000                 nop
F00738C4: e8062024                 ld      [%i0+0x24], %l4
F00738C8: ab2d2002                 sll     %l4, 2, %l5
F00738CC: 80a54013                 cmp     %l5, %l3
F00738D0: 08800010                 bleu    loc_F0073910
F00738D4: ac100017                 mov     %l7, %l6
F00738D8: c0260000                 clr     [%i0]
F00738DC: 80a4e000                 cmp     %l3, 0
F00738E0: 02800004                 be      loc_F00738F0
F00738E4: 90100017                 mov     %l7, %o0
F00738E8: 7fffd22e                 call    _kfree
F00738EC: 92100013                 mov     %l3, %o1
F00738F0: a6100015                 mov     %l5, %l3
F00738F4: 7fffd1df                 call    _kalloc
F00738F8: 90100013                 mov     %l3, %o0
F00738FC: ae920000                 orcc    %o0, %g0, %l7
F0073900: 12bfffe4                 bne     loc_F0073890
F0073904: 01000000                 nop
F0073908: 1080004a                 ba      locret_F0073A30
F007390C: b0102006                 mov     6, %i0
F0073910: a0102000                 mov     0, %l0
F0073914: 80a40014                 cmp     %l0, %l4
F0073918: 1a80000b                 bcc     loc_F0073944
F007391C: e206201c                 ld      [%i0+0x1C], %l1
F0073920: a4102000                 mov     0, %l2
F0073924: 400003c4                 call    _thread_reference
F0073928: 90100011                 mov     %l1, %o0
F007392C: e2248016                 st      %l1, [%l2+%l6]
F0073930: a404a004                 inc     4, %l2
F0073934: a0042001                 inc     %l0
F0073938: 80a40014                 cmp     %l0, %l4
F007393C: 0abffffa                 bcs     loc_F0073924
F0073940: e2046010                 ld      [%l1+0x10], %l1
F0073944: c0260000                 clr     [%i0]
F0073948: 80a52000                 cmp     %l4, 0
F007394C: 1280000b                 bne     loc_F0073978
F0073950: 80a54013                 cmp     %l5, %l3
F0073954: c0264000                 clr     [%i1]
F0073958: 80a4e000                 cmp     %l3, 0
F007395C: 02800034                 be      loc_F0073A2C
F0073960: c0268000                 clr     [%i2]
F0073964: 90100017                 mov     %l7, %o0
F0073968: 7fffd20e                 call    _kfree
F007396C: 92100013                 mov     %l3, %o1
F0073970: 10800030                 ba      locret_F0073A30
F0073974: b0102000                 mov     0, %i0
F0073978: 3a800021                 bcc,a   loc_F00739FC
F007397C: ec264000                 st      %l6, [%i1]
F0073980: 7fffd1bc                 call    _kalloc
F0073984: 90100015                 mov     %l5, %o0
F0073988: a0920000                 orcc    %o0, %g0, %l0
F007398C: 32800014                 bne,a   loc_F00739DC
F0073990: 90100017                 mov     %l7, %o0
F0073994: a0102000                 mov     0, %l0
F0073998: 80a40014                 cmp     %l0, %l4
F007399C: 1a800008                 bcc     loc_F00739BC
F00739A0: a2102000                 mov     0, %l1
F00739A4: d0044016                 ld      [%l1+%l6], %o0
F00739A8: 40000281                 call    _thread_deallocate
F00739AC: a0042001                 inc     %l0
F00739B0: 80a40014                 cmp     %l0, %l4
F00739B4: 0abffffc                 bcs     loc_F00739A4
F00739B8: a2046004                 inc     4, %l1
F00739BC: 90100017                 mov     %l7, %o0! void *
F00739C0: 7fffd1f8                 call    _kfree
F00739C4: 92100013                 mov     %l3, %o1
F00739C8: 1080001a                 ba      locret_F0073A30
F00739CC: b0102006                 mov     6, %i0
F00739D0: c0260000                 clr     [%i0]
F00739D4: 10800017                 ba      locret_F0073A30
F00739D8: b0102005                 mov     5, %i0
F00739DC: 92100010                 mov     %l0, %o1! void *
F00739E0: 4000844c                 call    _bcopy
F00739E4: 94100015                 mov     %l5, %o2
F00739E8: 90100017                 mov     %l7, %o0
F00739EC: 7fffd1ed                 call    _kfree
F00739F0: 92100013                 mov     %l3, %o1
F00739F4: ac100010                 mov     %l0, %l6
F00739F8: ec264000                 st      %l6, [%i1]
F00739FC: a0102000                 mov     0, %l0
F0073A00: 80a40014                 cmp     %l0, %l4
F0073A04: 1a80000a                 bcc     loc_F0073A2C
F0073A08: e8268000                 st      %l4, [%i2]
F0073A0C: b0100016                 mov     %l6, %i0
F0073A10: d0060000                 ld      [%i0], %o0
F0073A14: 7fffd051                 call    _convert_thread_to_port
F0073A18: a0042001                 inc     %l0
F0073A1C: d0260000                 st      %o0, [%i0]
F0073A20: 80a40014                 cmp     %l0, %l4
F0073A24: 0abffffb                 bcs     loc_F0073A10
F0073A28: b0062004                 inc     4, %i0
F0073A2C: b0102000                 mov     0, %i0
F0073A30: 81c7e008                 ret
F0073A34: 81e80000                 restore
