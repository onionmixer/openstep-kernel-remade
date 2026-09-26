F002E4F8: 9de3bf98                 save    %sp, -0x68, %sp
F002E4FC: 133c0431                 sethi   %hi(dword_F010C474), %o1
F002E500: d0026074                 ld      [%o1+%lo(dword_F010C474)], %o0
F002E504: 80a22000                 cmp     %o0, 0
F002E508: 1280001d                 bne     loc_F002E57C
F002E50C: 80a66000                 cmp     %i1, 0
F002E510: 90102001                 mov     1, %o0
F002E514: 80a62000                 cmp     %i0, 0
F002E518: 12800004                 bne     loc_F002E528
F002E51C: d0226074                 st      %o0, [%o1+%lo(dword_F010C474)]
F002E520: 10800027                 ba      locret_F002E5BC
F002E524: b0102000                 mov     0, %i0
F002E528: d20e0000                 ldub    [%i0], %o1
F002E52C: 113c04bd                 sethi   %hi(byte_F012F418), %o0
F002E530: d22a2018                 stb     %o1, [%o0+%lo(byte_F012F418)]
F002E534: d20e2001                 ldub    [%i0+1], %o1
F002E538: 90122018                 bset    %lo(byte_F012F418), %o0! char *
F002E53C: d22a2001                 stb     %o1, [%o0+1]
F002E540: d20e2002                 ldub    [%i0+2], %o1
F002E544: d22a2002                 stb     %o1, [%o0+2]
F002E548: d20e2003                 ldub    [%i0+3], %o1
F002E54C: d22a2003                 stb     %o1, [%o0+3]
F002E550: d20e2004                 ldub    [%i0+4], %o1
F002E554: 213c0431                 sethi   %hi(aEthernetAddres), %l0! "Ethernet address = %s\n"
F002E558: d22a2004                 stb     %o1, [%o0+4]
F002E55C: d20e2005                 ldub    [%i0+5], %o1
F002E560: a0142078                 bset    %lo(aEthernetAddres), %l0! "Ethernet address = %s\n"
F002E564: 40000018                 call    _ether_sprintf
F002E568: d22a2005                 stb     %o1, [%o0+5]
F002E56C: 92100008                 mov     %o0, %o1
F002E570: 7fff983a                 call    _printf
F002E574: 90100010                 mov     %l0, %o0
F002E578: 80a66000                 cmp     %i1, 0
F002E57C: 0280000f                 be      loc_F002E5B8
F002E580: 113c04bd                 sethi   %hi(byte_F012F418), %o0
F002E584: d20a2018                 ldub    [%o0+%lo(byte_F012F418)], %o1
F002E588: d22e4000                 stb     %o1, [%i1]
F002E58C: 90122018                 bset    %lo(byte_F012F418), %o0
F002E590: d20a2001                 ldub    [%o0+1], %o1
F002E594: d22e6001                 stb     %o1, [%i1+1]
F002E598: d20a2002                 ldub    [%o0+2], %o1
F002E59C: d22e6002                 stb     %o1, [%i1+2]
F002E5A0: d20a2003                 ldub    [%o0+3], %o1
F002E5A4: d22e6003                 stb     %o1, [%i1+3]
F002E5A8: d20a2004                 ldub    [%o0+4], %o1
F002E5AC: d22e6004                 stb     %o1, [%i1+4]
F002E5B0: d00a2005                 ldub    [%o0+5], %o0
F002E5B4: d02e6005                 stb     %o0, [%i1+5]
F002E5B8: b0102001                 mov     1, %i0
F002E5BC: 81c7e008                 ret
F002E5C0: 81e80000                 restore
