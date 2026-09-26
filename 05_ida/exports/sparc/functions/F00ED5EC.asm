F00ED5EC: 9de3bf98                 save    %sp, -0x68, %sp
F00ED5F0: d0060000                 ld      [%i0], %o0
F00ED5F4: d4020000                 ld      [%o0], %o2
F00ED5F8: d0062010                 ld      [%i0+0x10], %o0
F00ED5FC: 9fc28000                 call    %o2
F00ED600: 92100019                 mov     %i1, %o1
F00ED604: 7ffc64a7                 call    _urem
F00ED608: d2062008                 ld      [%i0+8], %o1
F00ED60C: 912a2003                 sll     %o0, 3, %o0
F00ED610: d206200c                 ld      [%i0+0xC], %o1
F00ED614: e0020009                 ld      [%o0+%o1], %l0
F00ED618: 80a42000                 cmp     %l0, 0
F00ED61C: 02800025                 be      loc_F00ED6B0
F00ED620: 94020009                 add     %o0, %o1, %o2
F00ED624: 80a42001                 cmp     %l0, 1
F00ED628: 3280001e                 bne,a   loc_F00ED6A0
F00ED62C: e202a004                 ld      [%o2+4], %l1
F00ED630: d402a004                 ld      [%o2+4], %o2
F00ED634: 80a6400a                 cmp     %i1, %o2
F00ED638: 0280000a                 be      loc_F00ED660
F00ED63C: a0102000                 mov     0, %l0
F00ED640: d0060000                 ld      [%i0], %o0
F00ED644: d6022004                 ld      [%o0+4], %o3
F00ED648: d0062010                 ld      [%i0+0x10], %o0
F00ED64C: 9fc2c000                 call    %o3
F00ED650: 92100019                 mov     %i1, %o1
F00ED654: 80a22000                 cmp     %o0, 0
F00ED658: 02800017                 be      locret_F00ED6B4
F00ED65C: b0100010                 mov     %l0, %i0
F00ED660: a0102001                 mov     1, %l0
F00ED664: 10800014                 ba      locret_F00ED6B4
F00ED668: b0100010                 mov     %l0, %i0
F00ED66C: 80a6400a                 cmp     %i1, %o2
F00ED670: 22800011                 be,a    locret_F00ED6B4
F00ED674: b0102001                 mov     1, %i0
F00ED678: d0060000                 ld      [%i0], %o0
F00ED67C: d6022004                 ld      [%o0+4], %o3
F00ED680: d0062010                 ld      [%i0+0x10], %o0
F00ED684: 9fc2c000                 call    %o3
F00ED688: 92100019                 mov     %i1, %o1
F00ED68C: 80a22000                 cmp     %o0, 0
F00ED690: 02800004                 be      loc_F00ED6A0
F00ED694: a2046004                 inc     4, %l1
F00ED698: 10800007                 ba      locret_F00ED6B4
F00ED69C: b0102001                 mov     1, %i0
F00ED6A0: a0043fff                 inc     -1, %l0
F00ED6A4: 80a43fff                 cmp     %l0, -1
F00ED6A8: 32bffff1                 bne,a   loc_F00ED66C
F00ED6AC: d4044000                 ld      [%l1], %o2
F00ED6B0: b0102000                 mov     0, %i0
F00ED6B4: 81c7e008                 ret
F00ED6B8: 81e80000                 restore
