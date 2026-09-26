F0042544: 9de3bf78                 save    %sp, -0x88, %sp
F0042548: 113c04cf                 sethi   %hi(_active_u), %o0
F004254C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0042550: d002201c                 ld      [%o0+0x1C], %o0
F0042554: a402200a                 add     %o0, 0xA, %l2
F0042558: a202202a                 add     %o0, 0x2A, %l1 ! '*'
F004255C: 80a44012                 cmp     %l1, %l2
F0042560: 0880000a                 bleu    loc_F0042588
F0042564: 92100012                 mov     %l2, %o1
F0042568: d0547ffe                 ldsh    [%l1-2], %o0
F004256C: 80a23fff                 cmp     %o0, -1
F0042570: 12800007                 bne     loc_F004258C
F0042574: 293c04d1                 sethi   -0xFECBC00, %l4
F0042578: a2047ffe                 inc     -2, %l1
F004257C: 80a44009                 cmp     %l1, %o1
F0042580: 38bffffb                 bgu,a   loc_F004256C
F0042584: d0547ffe                 ldsh    [%l1-2], %o0
F0042588: 293c04d1                 sethi   -0xFECBC00, %l4
F004258C: d4052330                 ld      [%l4+0x330], %o2
F0042590: 90244012                 sub     %l1, %l2, %o0
F0042594: 933a2001                 sra     %o0, 1, %o1
F0042598: 9682a003                 addcc   %o2, 3, %o3
F004259C: 1c800003                 bpos    loc_F00425A8
F00425A0: aa100009                 mov     %o1, %l5
F00425A4: 9602a006                 add     %o2, 6, %o3
F00425A8: 90100019                 mov     %i1, %o0
F00425AC: 960afffc                 and     %o3, -4, %o3! xdr_op
F00425B0: 932a6002                 sll     %o1, 2, %o1
F00425B4: 92026014                 inc     0x14, %o1
F00425B8: d4066004                 ld      [%i1+4], %o2
F00425BC: a602c009                 add     %o3, %o1, %l3
F00425C0: d402a018                 ld      [%o2+0x18], %o2
F00425C4: 9fc28000                 call    %o2
F00425C8: 9204e010                 add     %l3, 0x10, %o1
F00425CC: a0920000                 orcc    %o0, %g0, %l0
F00425D0: 02800033                 be      loc_F004269C
F00425D4: 01000000                 nop
F00425D8: 7fff426d                 call    _getthetime
F00425DC: 9007bfd8                 add     %fp, var_28, %o0
F00425E0: 90102001                 mov     1, %o0
F00425E4: d0240000                 st      %o0, [%l0]
F00425E8: a0042004                 inc     4, %l0
F00425EC: e6240000                 st      %l3, [%l0]
F00425F0: a0042004                 inc     4, %l0
F00425F4: 113c04d1                 sethi   %hi(_hostname), %o0
F00425F8: d207bfd8                 ld      [%fp+var_28], %o1
F00425FC: 90122230                 bset    %lo(_hostname), %o0! void *
F0042600: d2240000                 st      %o1, [%l0]
F0042604: d2052330                 ld      [%l4+0x330], %o1! void *
F0042608: a0042004                 inc     4, %l0
F004260C: d2240000                 st      %o1, [%l0]
F0042610: a0042004                 inc     4, %l0
F0042614: d4052330                 ld      [%l4+0x330], %o2! size_t
F0042618: 4001493e                 call    _bcopy
F004261C: 92100010                 mov     %l0, %o1
F0042620: d0052330                 ld      [%l4+0x330], %o0
F0042624: 92822003                 addcc   %o0, 3, %o1
F0042628: 2c800002                 bneg,a  loc_F0042630
F004262C: 92022006                 add     %o0, 6, %o1
F0042630: 153c04cf                 sethi   %hi(_active_u), %o2
F0042634: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0042638: d002201c                 ld      [%o0+0x1C], %o0
F004263C: 920a7ffc                 and     %o1, -4, %o1
F0042640: d0522002                 ldsh    [%o0+2], %o0
F0042644: a0040009                 add     %l0, %o1, %l0
F0042648: d0240000                 st      %o0, [%l0]
F004264C: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0042650: d002201c                 ld      [%o0+0x1C], %o0
F0042654: 80a48011                 cmp     %l2, %l1
F0042658: d0522004                 ldsh    [%o0+4], %o0
F004265C: a0042004                 inc     4, %l0
F0042660: d0240000                 st      %o0, [%l0]
F0042664: a0042004                 inc     4, %l0
F0042668: ea240000                 st      %l5, [%l0]
F004266C: 1a800008                 bcc     loc_F004268C
F0042670: a0042004                 inc     4, %l0
F0042674: d0548000                 ldsh    [%l2], %o0
F0042678: d0240000                 st      %o0, [%l0]
F004267C: a404a002                 inc     2, %l2
F0042680: 80a48011                 cmp     %l2, %l1
F0042684: 0abffffc                 bcs     loc_F0042674
F0042688: a0042004                 inc     4, %l0
F004268C: c0240000                 clr     [%l0]
F0042690: c0242004                 clr     [%l0+4]
F0042694: 10800029                 ba      locret_F0042738
F0042698: b0102001                 mov     1, %i0
F004269C: 40009675                 call    _kalloc
F00426A0: 90102190                 mov     0x190, %o0
F00426A4: a2100008                 mov     %o0, %l1
F00426A8: a007bfe0                 add     %fp, var_20, %l0
F00426AC: 90100010                 mov     %l0, %o0! XDR *
F00426B0: 92100011                 mov     %l1, %o1! char *
F00426B4: 94102190                 mov     0x190, %o2! unsigned int
F00426B8: 40000e8a                 call    _xdrmem_create
F00426BC: 96102000                 mov     0, %o3
F00426C0: 40000050                 call    _xdr_authkern
F00426C4: 90100010                 mov     %l0, %o0
F00426C8: 80a22000                 cmp     %o0, 0
F00426CC: 12800007                 bne     loc_F00426E8
F00426D0: d007bfe4                 ld      [%fp+var_20.x_ops], %o0
F00426D4: 113c0436                 sethi   %hi(aAuthkernMarsha), %o0! "authkern_marshal: xdr_authkern failed\n"
F00426D8: 7fff47e0                 call    _printf
F00426DC: 901221a0                 bset    %lo(aAuthkernMarsha), %o0! "authkern_marshal: xdr_authkern failed\n"
F00426E0: 10800013                 ba      loc_F004272C
F00426E4: b0102000                 mov     0, %i0
F00426E8: d2022010                 ld      [%o0+0x10], %o1
F00426EC: 9fc24000                 call    %o1
F00426F0: 90100010                 mov     %l0, %o0
F00426F4: d0262008                 st      %o0, [%i0+8]
F00426F8: e2262004                 st      %l1, [%i0+4]
F00426FC: 90100019                 mov     %i1, %o0
F0042700: 400005c2                 call    _xdr_opaque_auth
F0042704: 92100018                 mov     %i0, %o1
F0042708: 80a22000                 cmp     %o0, 0
F004270C: 02800007                 be      loc_F0042728
F0042710: 90100019                 mov     %i1, %o0
F0042714: 400005bd                 call    _xdr_opaque_auth
F0042718: 9206200c                 add     %i0, 0xC, %o1
F004271C: 80a22000                 cmp     %o0, 0
F0042720: 12800003                 bne     loc_F004272C
F0042724: b0102001                 mov     1, %i0
F0042728: b0102000                 mov     0, %i0
F004272C: 90100011                 mov     %l1, %o0
F0042730: 4000969c                 call    _kfree
F0042734: 92102190                 mov     0x190, %o1
F0042738: 81c7e008                 ret
F004273C: 81e80000                 restore
