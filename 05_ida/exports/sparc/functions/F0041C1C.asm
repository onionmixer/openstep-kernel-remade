F0041C1C: 9de3bf98                 save    %sp, -0x68, %sp
F0041C20: 90100018                 mov     %i0, %o0
F0041C24: 7ffffed8                 call    sub_F0041784
F0041C28: 92100019                 mov     %i1, %o1
F0041C2C: 80a22000                 cmp     %o0, 0
F0041C30: 22800057                 be,a    locret_F0041D8C
F0041C34: b0102000                 mov     0, %i0
F0041C38: d0060000                 ld      [%i0], %o0
F0041C3C: 80a22000                 cmp     %o0, 0
F0041C40: 1280004b                 bne     loc_F0041D6C
F0041C44: 90100018                 mov     %i0, %o0
F0041C48: d006604c                 ld      [%i1+0x4C], %o0
F0041C4C: 80a22000                 cmp     %o0, 0
F0041C50: 02800047                 be      loc_F0041D6C
F0041C54: 90100018                 mov     %i0, %o0
F0041C58: 400153d8                 call    _spltty
F0041C5C: 253c04d3                 sethi   %hi(_mfree), %l2
F0041C60: e004a168                 ld      [%l2+%lo(_mfree)], %l0
F0041C64: 80a42000                 cmp     %l0, 0
F0041C68: 02800018                 be      loc_F0041CC8
F0041C6C: a2100008                 mov     %o0, %l1
F0041C70: d054200a                 ldsh    [%l0+0xA], %o0
F0041C74: 80a22000                 cmp     %o0, 0
F0041C78: 02800004                 be      loc_F0041C88
F0041C7C: 113c0436                 sethi   %hi(aMget_16), %o0! "mget"
F0041C80: 7fff4d3c                 call    _panic
F0041C84: 90122108                 bset    %lo(aMget_16), %o0! "mget"
F0041C88: 90102001                 mov     1, %o0
F0041C8C: d034200a                 sth     %o0, [%l0+0xA]
F0041C90: 153c04d29412a2f0         set     _mbstat, %o2
F0041C98: d012a01c                 lduh    [%o2+0x1C], %o0
F0041C9C: d212a01e                 lduh    [%o2+0x1E], %o1
F0041CA0: 90023fff                 inc     -1, %o0
F0041CA4: d032a01c                 sth     %o0, [%o2+0x1C]
F0041CA8: 92026001                 inc     %o1
F0041CAC: d232a01e                 sth     %o1, [%o2+0x1E]
F0041CB0: 9010200c                 mov     0xC, %o0
F0041CB4: d2040000                 ld      [%l0], %o1
F0041CB8: d0242004                 st      %o0, [%l0+4]
F0041CBC: d224a168                 st      %o1, [%l2+0x168]
F0041CC0: 10800006                 ba      loc_F0041CD8
F0041CC4: c0240000                 clr     [%l0]
F0041CC8: 90102001                 mov     1, %o0
F0041CCC: 7fff6fa8                 call    _m_more
F0041CD0: 92102001                 mov     1, %o1
F0041CD4: a0100008                 mov     %o0, %l0
F0041CD8: 40015413                 call    _splx
F0041CDC: 90100011                 mov     %l1, %o0
F0041CE0: 80a42000                 cmp     %l0, 0
F0041CE4: 12800007                 bne     loc_F0041D00
F0041CE8: 113c0106                 sethi   -0xFFBE800, %o0
F0041CEC: 113c0436                 sethi   %hi(aXdrRrokFailedC), %o0! "xdr_rrok: FAILED, can't get mbuf\n"
F0041CF0: 7fff4a5a                 call    _printf
F0041CF4: 90122110                 bset    %lo(aXdrRrokFailedC), %o0! "xdr_rrok: FAILED, can't get mbuf\n"
F0041CF8: 10800025                 ba      locret_F0041D8C
F0041CFC: b0102000                 mov     0, %i0
F0041D00: d2042004                 ld      [%l0+4], %o1
F0041D04: 901222f0                 bset    0x2F0, %o0
F0041D08: d0240009                 st      %o0, [%l0+%o1]
F0041D0C: a0040009                 add     %l0, %o1, %l0
F0041D10: c0242004                 clr     [%l0+4]
F0041D14: d0066050                 ld      [%i1+0x50], %o0
F0041D18: d0242008                 st      %o0, [%l0+8]
F0041D1C: d006604c                 ld      [%i1+0x4C], %o0
F0041D20: d024200c                 st      %o0, [%l0+0xC]
F0041D24: d0066048                 ld      [%i1+0x48], %o0
F0041D28: 173c0107                 sethi   %hi(sub_F0041C00), %o3
F0041D2C: d0242010                 st      %o0, [%l0+0x10]
F0041D30: d2066044                 ld      [%i1+0x44], %o1
F0041D34: 9612e000                 bset    %lo(sub_F0041C00), %o3! unsigned int
F0041D38: d2242014                 st      %o1, [%l0+0x14]
F0041D3C: e0262008                 st      %l0, [%i0+8]
F0041D40: d2066048                 ld      [%i1+0x48], %o1
F0041D44: 98100010                 mov     %l0, %o4
F0041D48: d4066044                 ld      [%i1+0x44], %o2
F0041D4C: 40001097                 call    _xdrmbuf_putbuf
F0041D50: 90100018                 mov     %i0, %o0
F0041D54: 80a22000                 cmp     %o0, 0
F0041D58: 3280000d                 bne,a   locret_F0041D8C
F0041D5C: b0102001                 mov     1, %i0
F0041D60: 90102001                 mov     1, %o0
F0041D64: d0242004                 st      %o0, [%l0+4]
F0041D68: 90100018                 mov     %i0, %o0! XDR *
F0041D6C: 92066048                 add     %i1, 0x48, %o1 ! 'H'! char **
F0041D70: 94066044                 add     %i1, 0x44, %o2 ! 'D'! unsigned int *
F0041D74: 40000eb9                 call    _xdr_bytes
F0041D78: 17000008                 sethi   0x2000, %o3
F0041D7C: 80a22000                 cmp     %o0, 0
F0041D80: 12800003                 bne     locret_F0041D8C
F0041D84: b0102001                 mov     1, %i0
F0041D88: b0102000                 mov     0, %i0
F0041D8C: 81c7e008                 ret
F0041D90: 81e80000                 restore
