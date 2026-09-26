F0031CF4: 9de3bf90                 save    %sp, -0x70, %sp
F0031CF8: 90102002                 mov     2, %o0
F0031CFC: 921020ff                 mov     0xFF, %o1
F0031D00: 7fffadc8                 call    _pffindproto
F0031D04: 94102003                 mov     3, %o2
F0031D08: a0920000                 orcc    %o0, %g0, %l0
F0031D0C: 12800006                 bne     loc_F0031D24
F0031D10: 133c0431                 sethi   -0xFEF3C00, %o1
F0031D14: 113c0431                 sethi   %hi(aIpInit), %o0! "ip_init"
F0031D18: 7fff8d16                 call    _panic
F0031D1C: 901223d0                 bset    %lo(aIpInit), %o0! "ip_init"
F0031D20: 133c0431                 sethi   -0xFEF3C00, %o1
F0031D24: 921261a0                 bset    0x1A0, %o1
F0031D28: 92240009                 sub     %l0, %o1, %o1
F0031D2C: 912a6002                 sll     %o1, 2, %o0
F0031D30: 90020009                 add     %o0, %o1, %o0
F0031D34: 932a2004                 sll     %o0, 4, %o1
F0031D38: 90020009                 add     %o0, %o1, %o0
F0031D3C: 932a2008                 sll     %o0, 8, %o1
F0031D40: 90020009                 add     %o0, %o1, %o0
F0031D44: 932a2010                 sll     %o0, 16, %o1
F0031D48: 90020009                 add     %o0, %o1, %o0
F0031D4C: 90200008                 neg     %o0
F0031D50: 953a2004                 sra     %o0, 4, %o2
F0031D54: 113c04d990122220         set     _ip_protox, %o0
F0031D5C: 920220ff                 add     %o0, 0xFF, %o1
F0031D60: d42a4000                 stb     %o2, [%o1]
F0031D64: 92027fff                 inc     -1, %o1
F0031D68: 80a24008                 cmp     %o1, %o0
F0031D6C: 36bffffe                 bge,a   loc_F0031D64
F0031D70: d42a4000                 stb     %o2, [%o1]
F0031D74: 113c0431                 sethi   %hi(off_F010C704), %o0
F0031D78: e0022304                 ld      [%o0+%lo(off_F010C704)], %l0
F0031D7C: 90122304                 bset    %lo(off_F010C704), %o0
F0031D80: d0022004                 ld      [%o0+4], %o0
F0031D84: 80a40008                 cmp     %l0, %o0
F0031D88: 1a800023                 bcc     loc_F0031E14
F0031D8C: 193c0431                 sethi   -0xFEF3C00, %o4
F0031D90: 113c04d984122220         set     _ip_protox, %g2
F0031D98: 113c04319a1221a0         set     _inetsw, %o5
F0031DA0: 96042008                 add     %l0, 8, %o3
F0031DA4: d002fffc                 ld      [%o3-4], %o0
F0031DA8: d0020000                 ld      [%o0], %o0
F0031DAC: 80a22002                 cmp     %o0, 2
F0031DB0: 12800015                 bne     loc_F0031E04
F0031DB4: d0032308                 ld      [%o4+0x308], %o0
F0031DB8: d452c000                 ldsh    [%o3], %o2
F0031DBC: 80a2a000                 cmp     %o2, 0
F0031DC0: 02800011                 be      loc_F0031E04
F0031DC4: 01000000                 nop
F0031DC8: 80a2a0ff                 cmp     %o2, 0xFF
F0031DCC: 0280000e                 be      loc_F0031E04
F0031DD0: 9224000d                 sub     %l0, %o5, %o1
F0031DD4: 912a6002                 sll     %o1, 2, %o0
F0031DD8: 90020009                 add     %o0, %o1, %o0
F0031DDC: 932a2004                 sll     %o0, 4, %o1
F0031DE0: 90020009                 add     %o0, %o1, %o0
F0031DE4: 932a2008                 sll     %o0, 8, %o1
F0031DE8: 90020009                 add     %o0, %o1, %o0
F0031DEC: 932a2010                 sll     %o0, 16, %o1
F0031DF0: 90020009                 add     %o0, %o1, %o0
F0031DF4: 90200008                 neg     %o0
F0031DF8: 913a2004                 sra     %o0, 4, %o0
F0031DFC: d02a8002                 stb     %o0, [%o2+%g2]
F0031E00: d0032308                 ld      [%o4+0x308], %o0
F0031E04: a0042030                 inc     0x30, %l0 ! '0'
F0031E08: 80a40008                 cmp     %l0, %o0
F0031E0C: 0abfffe6                 bcs     loc_F0031DA4
F0031E10: 9602e030                 inc     0x30, %o3 ! '0'
F0031E14: 133c04d9901260b0         set     _ipq, %o0
F0031E1C: d0222004                 st      %o0, [%o0+4]
F0031E20: d02260b0                 st      %o0, [%o1+0xB0]
F0031E24: 7fff845a                 call    _getthetime
F0031E28: 9007bff0                 add     %fp, var_10, %o0
F0031E2C: d207bff0                 ld      [%fp+var_10], %o1
F0031E30: 113c04d9                 sethi   %hi(_ip_id), %o0
F0031E34: d23220a0                 sth     %o1, [%o0+%lo(_ip_id)]
F0031E38: 113c0431                 sethi   %hi(_ipqmaxlen), %o0
F0031E3C: d20223c8                 ld      [%o0+%lo(_ipqmaxlen)], %o1
F0031E40: 113c04d9                 sethi   %hi(dword_F013648C), %o0
F0031E44: d222208c                 st      %o1, [%o0+%lo(dword_F013648C)]
F0031E48: 81c7e008                 ret
F0031E4C: 81e80000                 restore
