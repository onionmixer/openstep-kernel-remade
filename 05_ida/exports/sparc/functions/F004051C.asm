F004051C: 9de3bf48                 save    %sp, -0xB8, %sp
F0040520: 40009ed4                 call    _kalloc
F0040524: 90102068                 mov     0x68, %o0! void *
F0040528: a4100008                 mov     %o0, %l2
F004052C: 4001524b                 call    _bzero
F0040530: 92102068                 mov     0x68, %o1 ! 'h'
F0040534: a007bfb0                 add     %fp, var_50, %l0
F0040538: 90100010                 mov     %l0, %o0
F004053C: 92100019                 mov     %i1, %o1
F0040540: 7ffff1a9                 call    _setdiropargs
F0040544: 94100018                 mov     %i0, %o2
F0040548: 7ffff1b0                 call    _setdirgid
F004054C: 90100018                 mov     %i0, %o0
F0040550: d036a008                 sth     %o0, [%i2+8]
F0040554: d216a004                 lduh    [%i2+4], %o1
F0040558: 7ffff1be                 call    _setdirmode
F004055C: 90100018                 mov     %i0, %o0
F0040560: d036a004                 sth     %o0, [%i2+4]
F0040564: 9010001a                 mov     %i2, %o0
F0040568: 7ffff186                 call    _vattr_to_sattr
F004056C: 9207bfd4                 add     %fp, var_2C, %o1
F0040570: 7ffff42d                 call    _rlock
F0040574: d0062030                 ld      [%i0+0x30], %o0
F0040578: 90100018                 mov     %i0, %o0
F004057C: 7fff95ab                 call    _dnlc_remove
F0040580: 92100019                 mov     %i1, %o1
F0040584: 9210200e                 mov     0xE, %o1
F0040588: 153c01089412a330         set     _xdr_creatargs, %o2
F0040590: 96100010                 mov     %l0, %o3
F0040594: 193c0108                 sethi   %hi(_xdr_diropres), %o4
F0040598: d0062024                 ld      [%i0+0x24], %o0
F004059C: 98132284                 bset    %lo(_xdr_diropres), %o4
F00405A0: d0022128                 ld      [%o0+0x128], %o0
F00405A4: 9a100012                 mov     %l2, %o5
F00405A8: 7ffff073                 call    _rfscall
F00405AC: f823a05c                 st      %i4, [%sp+0xB8+var_5C]
F00405B0: d2062030                 ld      [%i0+0x30], %o1
F00405B4: a2100008                 mov     %o0, %l1
F00405B8: c02260c0                 clr     [%o1+0xC0]
F00405BC: 7ffff438                 call    _runlock
F00405C0: d0062030                 ld      [%i0+0x30], %o0
F00405C4: 80a46000                 cmp     %l1, 0
F00405C8: 32800032                 bne,a   loc_F0040690
F00405CC: c026c000                 clr     [%i3]
F00405D0: e2048000                 ld      [%l2], %l1
F00405D4: 80a46046                 cmp     %l1, 0x46 ! 'F'
F00405D8: 12800007                 bne     loc_F00405F4
F00405DC: 80a46000                 cmp     %l1, 0
F00405E0: 7fff93c7                 call    _btrash
F00405E4: 90100018                 mov     %i0, %o0
F00405E8: 7fffe410                 call    _nfs_invalidate_caches
F00405EC: 90100018                 mov     %i0, %o0
F00405F0: 80a46000                 cmp     %l1, 0
F00405F4: 32800027                 bne,a   loc_F0040690
F00405F8: c026c000                 clr     [%i3]
F00405FC: 9004a004                 add     %l2, 4, %o0
F0040600: a004a024                 add     %l2, 0x24, %l0 ! '$'
F0040604: d4062024                 ld      [%i0+0x24], %o2
F0040608: 7ffff1ba                 call    _makenfsnode
F004060C: 92100010                 mov     %l0, %o1
F0040610: d026c000                 st      %o0, [%i3]
F0040614: d2022030                 ld      [%o0+0x30], %o1
F0040618: 113c0435                 sethi   %hi(_nfs_dnlc), %o0
F004061C: d0022304                 ld      [%o0+%lo(_nfs_dnlc)], %o0
F0040620: 80a22000                 cmp     %o0, 0
F0040624: 02800007                 be      loc_F0040640
F0040628: c02260c0                 clr     [%o1+0xC0]
F004062C: 90100018                 mov     %i0, %o0
F0040630: 92100019                 mov     %i1, %o1
F0040634: d406c000                 ld      [%i3], %o2
F0040638: 7fff9449                 call    _dnlc_enter
F004063C: 9610001c                 mov     %i4, %o3
F0040640: d006c000                 ld      [%i3], %o0
F0040644: 92100010                 mov     %l0, %o1
F0040648: e016a008                 lduh    [%i2+8], %l0
F004064C: 7fffe4f7                 call    _nattr_to_vattr
F0040650: 9410001a                 mov     %i2, %o2
F0040654: 912c2010                 sll     %l0, 16, %o0
F0040658: d256a008                 ldsh    [%i2+8], %o1
F004065C: 913a2010                 sra     %o0, 16, %o0
F0040660: 80a20009                 cmp     %o0, %o1
F0040664: 0280000c                 be      loc_F0040694
F0040668: 90100012                 mov     %l2, %o0
F004066C: 7fffa38a                 call    _vattr_null
F0040670: 9010001a                 mov     %i2, %o0
F0040674: e036a008                 sth     %l0, [%i2+8]
F0040678: d006c000                 ld      [%i3], %o0
F004067C: 9210001a                 mov     %i2, %o1
F0040680: 7ffffc36                 call    sub_F003F758
F0040684: 9410001c                 mov     %i4, %o2
F0040688: 10800003                 ba      loc_F0040694
F004068C: 90100012                 mov     %l2, %o0
F0040690: 90100012                 mov     %l2, %o0
F0040694: 40009ec3                 call    _kfree
F0040698: 92102068                 mov     0x68, %o1 ! 'h'
F004069C: 81c7e008                 ret
F00406A0: 91e80011                 restore %g0, %l1, %o0
