F00B8454: 9de3bf50                 save    %sp, -0xB0, %sp
F00B8458: a2102000                 mov     0, %l1
F00B845C: a6102000                 mov     0, %l3
F00B8460: a8102000                 mov     0, %l4
F00B8464: 80a00019                 cmp     %g0, %i1
F00B8468: d0062010                 ld      [%i0+0x10], %o0
F00B846C: b2402000                 addc    %g0, 0, %i1
F00B8470: 80a22000                 cmp     %o0, 0
F00B8474: 12800009                 bne     loc_F00B8498
F00B8478: a4102003                 mov     3, %l2
F00B847C: 113c04f6                 sethi   %hi(_iopbmap), %o0
F00B8480: d0022300                 ld      [%o0+%lo(_iopbmap)], %o0
F00B8484: 7fffb277                 call    _rmalloc
F00B8488: 92102024                 mov     0x24, %o1 ! '$'
F00B848C: 80a22000                 cmp     %o0, 0
F00B8490: 02800071                 be      loc_F00B8654
F00B8494: d0262010                 st      %o0, [%i0+0x10]
F00B8498: aa062004                 add     %i0, 4, %l5
F00B849C: 90100015                 mov     %l5, %o0
F00B84A0: 92102006                 mov     6, %o1
F00B84A4: 94102001                 mov     1, %o2
F00B84A8: 400000c6                 call    _scsi_pktalloc
F00B84AC: 96100019                 mov     %i1, %o3
F00B84B0: a2920000                 orcc    %o0, %g0, %l1
F00B84B4: 02800068                 be      loc_F00B8654
F00B84B8: 92100018                 mov     %i0, %o1
F00B84BC: 94102009                 mov     9, %o2
F00B84C0: 96102000                 mov     0, %o3
F00B84C4: 98102000                 mov     0, %o4
F00B84C8: 400002cf                 call    _makecom_g0
F00B84CC: 9a102000                 mov     0, %o5
F00B84D0: 4000028e                 call    _scsi_poll
F00B84D4: 90100011                 mov     %l1, %o0
F00B84D8: 80a22000                 cmp     %o0, 0
F00B84DC: 16800008                 bge     loc_F00B84FC
F00B84E0: 113c04f6                 sethi   -0xFEC2800, %o0
F00B84E4: d00c6028                 ldub    [%l1+0x28], %o0
F00B84E8: 80a22001                 cmp     %o0, 1
F00B84EC: 1280005a                 bne     loc_F00B8654
F00B84F0: a4102004                 mov     4, %l2
F00B84F4: 10800058                 ba      loc_F00B8654
F00B84F8: a4102002                 mov     2, %l2
F00B84FC: d0022300                 ld      [%o0+0x300], %o0
F00B8500: 7fffb258                 call    _rmalloc
F00B8504: 92102014                 mov     0x14, %o1! size_t
F00B8508: a8920000                 orcc    %o0, %g0, %l4
F00B850C: 02800052                 be      loc_F00B8654
F00B8510: a007bfb0                 add     %fp, var_50, %l0
F00B8514: 90100010                 mov     %l0, %o0! void *
F00B8518: 7fff7250                 call    _bzero
F00B851C: 92102044                 mov     0x44, %o1 ! 'D'
F00B8520: e827bfd0                 st      %l4, [%fp+var_30]
F00B8524: 90102014                 mov     0x14, %o0
F00B8528: d027bfc4                 st      %o0, [%fp+var_3C]
F00B852C: 90102001                 mov     1, %o0
F00B8530: d027bfb0                 st      %o0, [%fp+var_50]
F00B8534: 90100015                 mov     %l5, %o0
F00B8538: 92102006                 mov     6, %o1
F00B853C: 94102001                 mov     1, %o2
F00B8540: 96100010                 mov     %l0, %o3
F00B8544: 4000007a                 call    _scsi_resalloc
F00B8548: 98100019                 mov     %i1, %o4
F00B854C: a6920000                 orcc    %o0, %g0, %l3
F00B8550: 02800042                 be      loc_F00B8658
F00B8554: 92100018                 mov     %i0, %o1! size_t
F00B8558: 94102009                 mov     9, %o2
F00B855C: 96102003                 mov     3, %o3
F00B8560: 98102000                 mov     0, %o4
F00B8564: 400002a8                 call    _makecom_g0
F00B8568: 9a102014                 mov     0x14, %o5
F00B856C: d004601c                 ld      [%l1+0x1C], %o0
F00B8570: d00a0000                 ldub    [%o0], %o0
F00B8574: 808a2002                 btst    2, %o0
F00B8578: 22800007                 be,a    loc_F00B8594
F00B857C: a007bfb0                 add     %fp, var_50, %l0
F00B8580: 40000262                 call    _scsi_poll
F00B8584: 90100013                 mov     %l3, %o0
F00B8588: 80a22000                 cmp     %o0, 0
F00B858C: 06800021                 bl      loc_F00B8610
F00B8590: a007bfb0                 add     %fp, var_50, %l0
F00B8594: 90100010                 mov     %l0, %o0! void *
F00B8598: 7fff7230                 call    _bzero
F00B859C: 92102044                 mov     0x44, %o1 ! 'D'
F00B85A0: 90100011                 mov     %l1, %o0
F00B85A4: 92100010                 mov     %l0, %o1! size_t
F00B85A8: d6062010                 ld      [%i0+0x10], %o3
F00B85AC: 94100019                 mov     %i1, %o2
F00B85B0: a0102024                 mov     0x24, %l0 ! '$'
F00B85B4: d627bfd0                 st      %o3, [%fp+var_30]
F00B85B8: e027bfc4                 st      %l0, [%fp+var_3C]
F00B85BC: 96102001                 mov     1, %o3
F00B85C0: 4000008a                 call    _scsi_dmaget
F00B85C4: d627bfb0                 st      %o3, [%fp+var_50]
F00B85C8: 80a22000                 cmp     %o0, 0
F00B85CC: 02800023                 be      loc_F00B8658
F00B85D0: 80a4e000                 cmp     %l3, 0
F00B85D4: d0062010                 ld      [%i0+0x10], %o0! void *
F00B85D8: 7fff7220                 call    _bzero
F00B85DC: 92102024                 mov     0x24, %o1 ! '$'
F00B85E0: 90100011                 mov     %l1, %o0
F00B85E4: 92100018                 mov     %i0, %o1
F00B85E8: 94102009                 mov     9, %o2
F00B85EC: 96102012                 mov     0x12, %o3
F00B85F0: 98102000                 mov     0, %o4
F00B85F4: 40000284                 call    _makecom_g0
F00B85F8: 9a102024                 mov     0x24, %o5 ! '$'
F00B85FC: 40000243                 call    _scsi_poll
F00B8600: 90100011                 mov     %l1, %o0
F00B8604: 80a22000                 cmp     %o0, 0
F00B8608: 36800004                 bge,a   loc_F00B8618
F00B860C: d004601c                 ld      [%l1+0x1C], %o0
F00B8610: 10800011                 ba      loc_F00B8654
F00B8614: a4102004                 mov     4, %l2
F00B8618: d00a0000                 ldub    [%o0], %o0
F00B861C: 808a2002                 btst    2, %o0
F00B8620: 22800005                 be,a    loc_F00B8634
F00B8624: d00c6029                 ldub    [%l1+0x29], %o0
F00B8628: 40000238                 call    _scsi_poll
F00B862C: 90100013                 mov     %l3, %o0
F00B8630: d00c6029                 ldub    [%l1+0x29], %o0
F00B8634: 808a2008                 btst    8, %o0
F00B8638: 02800007                 be      loc_F00B8654
F00B863C: a4102001                 mov     1, %l2
F00B8640: d0046024                 ld      [%l1+0x24], %o0
F00B8644: 90240008                 sub     %l0, %o0, %o0
F00B8648: 80a22003                 cmp     %o0, 3
F00B864C: 38800002                 bgu,a   loc_F00B8654
F00B8650: a4102000                 mov     0, %l2
F00B8654: 80a4e000                 cmp     %l3, 0
F00B8658: 02800005                 be      loc_F00B866C
F00B865C: 80a46000                 cmp     %l1, 0
F00B8660: 40000077                 call    _scsi_resfree
F00B8664: 90100013                 mov     %l3, %o0
F00B8668: 80a46000                 cmp     %l1, 0
F00B866C: 02800005                 be      loc_F00B8680
F00B8670: 80a52000                 cmp     %l4, 0
F00B8674: 40000072                 call    _scsi_resfree
F00B8678: 90100011                 mov     %l1, %o0
F00B867C: 80a52000                 cmp     %l4, 0
F00B8680: 02800006                 be      locret_F00B8698
F00B8684: 113c04f6                 sethi   %hi(_iopbmap), %o0
F00B8688: d0022300                 ld      [%o0+%lo(_iopbmap)], %o0
F00B868C: 92102014                 mov     0x14, %o1
F00B8690: 7fffb221                 call    _rmfree
F00B8694: 94100014                 mov     %l4, %o2
F00B8698: 81c7e008                 ret
F00B869C: 91e80012                 restore %g0, %l2, %o0
