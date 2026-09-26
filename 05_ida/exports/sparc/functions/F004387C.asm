F004387C: 9de3bf98                 save    %sp, -0x68, %sp
F0043880: 90100018                 mov     %i0, %o0! XDR *
F0043884: 4000071a                 call    _xdr_u_long
F0043888: 92100019                 mov     %i1, %o1! unsigned __int32 *
F004388C: 80a22000                 cmp     %o0, 0
F0043890: 0280003c                 be      loc_F0043980
F0043894: 90100018                 mov     %i0, %o0! XDR *
F0043898: 40000715                 call    _xdr_u_long
F004389C: 92066004                 add     %i1, 4, %o1! unsigned __int32 *
F00438A0: 80a22000                 cmp     %o0, 0
F00438A4: 02800037                 be      loc_F0043980
F00438A8: 90100018                 mov     %i0, %o0! XDR *
F00438AC: 40000710                 call    _xdr_u_long
F00438B0: 92066008                 add     %i1, 8, %o1
F00438B4: 80a22000                 cmp     %o0, 0
F00438B8: 22800033                 be,a    locret_F0043984
F00438BC: b0102000                 mov     0, %i0
F00438C0: d0062004                 ld      [%i0+4], %o0
F00438C4: d2022010                 ld      [%o0+0x10], %o1! unsigned __int32 *
F00438C8: 9fc24000                 call    %o1
F00438CC: 90100018                 mov     %i0, %o0
F00438D0: a6100008                 mov     %o0, %l3
F00438D4: 90100018                 mov     %i0, %o0! XDR *
F00438D8: a406600c                 add     %i1, 0xC, %l2
F00438DC: 40000704                 call    _xdr_u_long
F00438E0: 92100012                 mov     %l2, %o1
F00438E4: 80a22000                 cmp     %o0, 0
F00438E8: 22800027                 be,a    locret_F0043984
F00438EC: b0102000                 mov     0, %i0
F00438F0: d0062004                 ld      [%i0+4], %o0
F00438F4: d2022010                 ld      [%o0+0x10], %o1
F00438F8: 9fc24000                 call    %o1
F00438FC: 90100018                 mov     %i0, %o0
F0043900: d2066010                 ld      [%i1+0x10], %o1
F0043904: a2100008                 mov     %o0, %l1
F0043908: d4066014                 ld      [%i1+0x14], %o2
F004390C: 9fc28000                 call    %o2
F0043910: 90100018                 mov     %i0, %o0
F0043914: 80a22000                 cmp     %o0, 0
F0043918: 2280001b                 be,a    locret_F0043984
F004391C: b0102000                 mov     0, %i0
F0043920: d0062004                 ld      [%i0+4], %o0
F0043924: d2022010                 ld      [%o0+0x10], %o1
F0043928: 9fc24000                 call    %o1
F004392C: 90100018                 mov     %i0, %o0
F0043930: a0100008                 mov     %o0, %l0
F0043934: 90240011                 sub     %l0, %l1, %o0
F0043938: d026600c                 st      %o0, [%i1+0xC]
F004393C: d2062004                 ld      [%i0+4], %o1
F0043940: d4026014                 ld      [%o1+0x14], %o2
F0043944: 90100018                 mov     %i0, %o0
F0043948: 9fc28000                 call    %o2
F004394C: 92100013                 mov     %l3, %o1! unsigned __int32 *
F0043950: 90100018                 mov     %i0, %o0! XDR *
F0043954: 400006e6                 call    _xdr_u_long
F0043958: 92100012                 mov     %l2, %o1
F004395C: 80a22000                 cmp     %o0, 0
F0043960: 02800008                 be      loc_F0043980
F0043964: 90100018                 mov     %i0, %o0
F0043968: d2062004                 ld      [%i0+4], %o1
F004396C: d4026014                 ld      [%o1+0x14], %o2
F0043970: 9fc28000                 call    %o2
F0043974: 92100010                 mov     %l0, %o1
F0043978: 10800003                 ba      locret_F0043984
F004397C: b0102001                 mov     1, %i0
F0043980: b0102000                 mov     0, %i0
F0043984: 81c7e008                 ret
F0043988: 81e80000                 restore
