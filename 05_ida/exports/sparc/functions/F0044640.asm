F0044640: 9de3bf98                 save    %sp, -0x68, %sp
F0044644: 90102001                 mov     1, %o0
F0044648: 173c0437                 sethi   %hi(_Sendtries), %o3
F004464C: d402e1f8                 ld      [%o3+%lo(_Sendtries)], %o2
F0044650: 92102008                 mov     8, %o1
F0044654: e2062008                 ld      [%i0+8], %l1
F0044658: 9402a001                 inc     %o2
F004465C: 7fff64c0                 call    _m_get
F0044660: d422e1f8                 st      %o2, [%o3+%lo(_Sendtries)]
F0044664: a0920000                 orcc    %o0, %g0, %l0
F0044668: 12800006                 bne     loc_F0044680
F004466C: 90102010                 mov     0x10, %o0
F0044670: 7fff657d                 call    _m_freem
F0044674: 90100019                 mov     %i1, %o0
F0044678: 1080002f                 ba      locret_F0044734
F004467C: b0102037                 mov     0x37, %i0 ! '7'
F0044680: d2042004                 ld      [%l0+4], %o1
F0044684: d0342008                 sth     %o0, [%l0+8]
F0044688: d0068000                 ld      [%i2], %o0
F004468C: d0240009                 st      %o0, [%l0+%o1]
F0044690: d006a004                 ld      [%i2+4], %o0
F0044694: 92040009                 add     %l0, %o1, %o1
F0044698: d0226004                 st      %o0, [%o1+4]
F004469C: d006a008                 ld      [%i2+8], %o0
F00446A0: d0226008                 st      %o0, [%o1+8]
F00446A4: d006a00c                 ld      [%i2+0xC], %o0
F00446A8: 4001497b                 call    _splnet
F00446AC: d022600c                 st      %o0, [%o1+0xC]
F00446B0: a4100008                 mov     %o0, %l2
F00446B4: 90100011                 mov     %l1, %o0
F00446B8: f4046014                 ld      [%l1+0x14], %i2
F00446BC: 7fffb08a                 call    _in_pcbconnect
F00446C0: 92100010                 mov     %l0, %o1
F00446C4: b0920000                 orcc    %o0, %g0, %i0
F00446C8: 12800012                 bne     loc_F0044710
F00446CC: 113c0437                 sethi   -0xFEF2400, %o0
F00446D0: 90100011                 mov     %l1, %o0
F00446D4: 7fffd0ae                 call    _udp_output
F00446D8: 92100019                 mov     %i1, %o1
F00446DC: b0100008                 mov     %o0, %i0
F00446E0: 7fffb164                 call    _in_pcbdisconnect
F00446E4: 90100011                 mov     %l1, %o0
F00446E8: f4246014                 st      %i2, [%l1+0x14]
F00446EC: 4001498e                 call    _splx
F00446F0: 90100012                 mov     %l2, %o0
F00446F4: 7fff64f0                 call    _m_free
F00446F8: 90100010                 mov     %l0, %o0
F00446FC: 133c0437                 sethi   %hi(_Sendok), %o1
F0044700: d00261fc                 ld      [%o1+%lo(_Sendok)], %o0
F0044704: 90022001                 inc     %o0
F0044708: 1080000b                 ba      locret_F0044734
F004470C: d02261fc                 st      %o0, [%o1+%lo(_Sendok)]
F0044710: 90122200                 bset    0x200, %o0! char *
F0044714: 7fff3fd1                 call    _printf
F0044718: 92100018                 mov     %i0, %o1
F004471C: 40014982                 call    _splx
F0044720: 90100012                 mov     %l2, %o0
F0044724: 7fff6550                 call    _m_freem
F0044728: 90100019                 mov     %i1, %o0
F004472C: 7fff64e2                 call    _m_free
F0044730: 90100010                 mov     %l0, %o0
F0044734: 81c7e008                 ret
F0044738: 81e80000                 restore
