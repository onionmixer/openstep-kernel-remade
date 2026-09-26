F0088660: 9de3bf98                 save    %sp, -0x68, %sp
F0088664: 7fff82a4                 call    _lock_read
F0088668: 90100018                 mov     %i0, %o0
F008866C: e0062010                 ld      [%i0+0x10], %l0
F0088670: 9006200c                 add     %i0, 0xC, %o0
F0088674: 80a40008                 cmp     %l0, %o0
F0088678: 02800029                 be      loc_F008871C
F008867C: 01000000                 nop
F0088680: 25280000                 sethi   -0x60000000, %l2
F0088684: a2100008                 mov     %o0, %l1
F0088688: d0042018                 ld      [%l0+0x18], %o0
F008868C: 808a0012                 btst    %l2, %o0
F0088690: 02800008                 be      loc_F00886B0
F0088694: 92100019                 mov     %i1, %o1
F0088698: d0042010                 ld      [%l0+0x10], %o0
F008869C: 9410001a                 mov     %i2, %o2
F00886A0: 7ffffff0                 call    sub_F0088660
F00886A4: 9610001b                 mov     %i3, %o3
F00886A8: 1080001a                 ba      loc_F0088710
F00886AC: e0042004                 ld      [%l0+4], %l0
F00886B0: d4042008                 ld      [%l0+8], %o2
F00886B4: 80a2801a                 cmp     %o2, %i2
F00886B8: 38800016                 bgu,a   loc_F0088710
F00886BC: e0042004                 ld      [%l0+4], %l0
F00886C0: d004200c                 ld      [%l0+0xC], %o0
F00886C4: 80a20019                 cmp     %o0, %i1
F00886C8: 28800012                 bleu,a  loc_F0088710
F00886CC: e0042004                 ld      [%l0+4], %l0
F00886D0: 80a28019                 cmp     %o2, %i1
F00886D4: 38800002                 bgu,a   loc_F00886DC
F00886D8: b210000a                 mov     %o2, %i1
F00886DC: 80a2001a                 cmp     %o0, %i2
F00886E0: 1a800003                 bcc     loc_F00886EC
F00886E4: 9810001a                 mov     %i2, %o4
F00886E8: 98100008                 mov     %o0, %o4
F00886EC: d2042014                 ld      [%l0+0x14], %o1
F00886F0: 9610001b                 mov     %i3, %o3
F00886F4: d0042010                 ld      [%l0+0x10], %o0
F00886F8: 92024019                 add     %o1, %i1, %o1
F00886FC: 9222400a                 sub     %o1, %o2, %o1
F0088700: 9402400c                 add     %o1, %o4, %o2
F0088704: 7fffffa2                 call    sub_F008858C
F0088708: 94228019                 sub     %o2, %i1, %o2
F008870C: e0042004                 ld      [%l0+4], %l0
F0088710: 80a40011                 cmp     %l0, %l1
F0088714: 32bfffde                 bne,a   loc_F008868C
F0088718: d0042018                 ld      [%l0+0x18], %o0
F008871C: 7fff8246                 call    _lock_done
F0088720: 90100018                 mov     %i0, %o0
F0088724: 81c7e008                 ret
F0088728: 81e80000                 restore
