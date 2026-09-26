F006C42C: 9de3bf90                 save    %sp, -0x70, %sp
F006C430: e0060000                 ld      [%i0], %l0
F006C434: d2042038                 ld      [%l0+0x38], %o1
F006C438: 11020000                 sethi   0x8000000, %o0
F006C43C: 808a4008                 btst    %o0, %o1
F006C440: 02800042                 be      locret_F006C548
F006C444: 01000000                 nop
F006C448: d2142004                 lduh    [%l0+4], %o1
F006C44C: 90027fff                 add     %o1, -1, %o0
F006C450: d0342004                 sth     %o0, [%l0+4]
F006C454: 912a2010                 sll     %o0, 16, %o0
F006C458: 80a22000                 cmp     %o0, 0
F006C45C: 1480003b                 bg      locret_F006C548
F006C460: 90100018                 mov     %i0, %o0
F006C464: d2342004                 sth     %o1, [%l0+4]
F006C468: d206201c                 ld      [%i0+0x1C], %o1
F006C46C: d402607c                 ld      [%o1+0x7C], %o2
F006C470: 9fc28000                 call    %o2
F006C474: 9207bff4                 add     %fp, var_C, %o1
F006C478: d4142004                 lduh    [%l0+4], %o2
F006C47C: d207bff4                 ld      [%fp+var_C], %o1
F006C480: 9002bfff                 add     %o2, -1, %o0
F006C484: 80a26000                 cmp     %o1, 0
F006C488: 12800006                 bne     loc_F006C4A0
F006C48C: d0342004                 sth     %o0, [%l0+4]
F006C490: 90100010                 mov     %l0, %o0
F006C494: 40000153                 call    _mfs_memfree
F006C498: 92102000                 mov     0, %o1
F006C49C: 3080002b                 ba,a    locret_F006C548
F006C4A0: 113c043f                 sethi   %hi(_close_flush), %o0
F006C4A4: d0022140                 ld      [%o0+%lo(_close_flush)], %o0
F006C4A8: 80a22000                 cmp     %o0, 0
F006C4AC: 12800007                 bne     loc_F006C4C8
F006C4B0: e2042024                 ld      [%l0+0x24], %l1
F006C4B4: d2042038                 ld      [%l0+0x38], %o1
F006C4B8: 11080000                 sethi   0x20000000, %o0
F006C4BC: 808a4008                 btst    %o0, %o1
F006C4C0: 02800008                 be      loc_F006C4E0
F006C4C4: b0046010                 add     %l1, 0x10, %i0
F006C4C8: d4342004                 sth     %o2, [%l0+4]
F006C4CC: 400000ef                 call    _vmp_get
F006C4D0: 90100010                 mov     %l0, %o0
F006C4D4: 4000044b                 call    _vmp_push
F006C4D8: 90100010                 mov     %l0, %o0
F006C4DC: b0046010                 add     %l1, 0x10, %i0
F006C4E0: d0060000                 ld      [%i0], %o0
F006C4E4: 80a22000                 cmp     %o0, 0
F006C4E8: 12bffffe                 bne     loc_F006C4E0
F006C4EC: 01000000                 nop
F006C4F0: 4000aa6e                 call    _simple_lock_try
F006C4F4: 90100018                 mov     %i0, %o0
F006C4F8: 80a22000                 cmp     %o0, 0
F006C4FC: 02bffff9                 be      loc_F006C4E0
F006C500: 01000000                 nop
F006C504: 40006a03                 call    _vm_object_deactivate_pages
F006C508: 90100011                 mov     %l1, %o0
F006C50C: 113c043f                 sethi   %hi(_close_flush), %o0
F006C510: d0022140                 ld      [%o0+%lo(_close_flush)], %o0
F006C514: c0246010                 clr     [%l1+0x10]
F006C518: 80a22000                 cmp     %o0, 0
F006C51C: 12800006                 bne     loc_F006C534
F006C520: 11080000                 sethi   0x20000000, %o0
F006C524: d2042038                 ld      [%l0+0x38], %o1
F006C528: 808a4008                 btst    %o0, %o1
F006C52C: 02800007                 be      locret_F006C548
F006C530: 01000000                 nop
F006C534: 400000f0                 call    _vmp_put
F006C538: 90100010                 mov     %l0, %o0
F006C53C: d0142004                 lduh    [%l0+4], %o0
F006C540: 90023fff                 inc     -1, %o0
F006C544: d0342004                 sth     %o0, [%l0+4]
F006C548: 81c7e008                 ret
F006C54C: 81e80000                 restore
