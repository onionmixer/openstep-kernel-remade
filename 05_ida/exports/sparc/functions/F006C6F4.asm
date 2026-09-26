F006C6F4: 9de3bf98                 save    %sp, -0x68, %sp
F006C6F8: e0060000                 ld      [%i0], %l0
F006C6FC: d2042038                 ld      [%l0+0x38], %o1
F006C700: 11020000                 sethi   0x8000000, %o0
F006C704: 808a4008                 btst    %o0, %o1
F006C708: 12800005                 bne     loc_F006C71C
F006C70C: 01000000                 nop
F006C710: f2242014                 st      %i1, [%l0+0x14]
F006C714: 10800044                 ba      locret_F006C824
F006C718: b0102000                 mov     0, %i0
F006C71C: 4000005b                 call    _vmp_get
F006C720: 90100010                 mov     %l0, %o0
F006C724: 113c04d0                 sethi   %hi(_page_mask), %o0
F006C728: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F006C72C: d4042010                 ld      [%l0+0x10], %o2
F006C730: 90064009                 add     %i1, %o1, %o0
F006C734: a22a0009                 andn    %o0, %o1, %l1
F006C738: 80a4400a                 cmp     %l1, %o2
F006C73C: 0a800003                 bcs     loc_F006C748
F006C740: a4102000                 mov     0, %l2
F006C744: a424400a                 sub     %l1, %o2, %l2
F006C748: d604200c                 ld      [%l0+0xC], %o3
F006C74C: 80a4800b                 cmp     %l2, %o3
F006C750: 1a800008                 bcc     loc_F006C770
F006C754: 90100010                 mov     %l0, %o0
F006C758: d4042008                 ld      [%l0+8], %o2
F006C75C: 92028012                 add     %o2, %l2, %o1
F006C760: 9402800b                 add     %o2, %o3, %o2
F006C764: 4000012d                 call    _mfs_map_remove
F006C768: 96102000                 mov     0, %o3
F006C76C: e424200c                 st      %l2, [%l0+0xC]
F006C770: d4042014                 ld      [%l0+0x14], %o2
F006C774: 80a28011                 cmp     %o2, %l1
F006C778: 08800005                 bleu    loc_F006C78C
F006C77C: 90100018                 mov     %i0, %o0
F006C780: 92100011                 mov     %l1, %o1
F006C784: 400002df                 call    _vno_flush
F006C788: 94228011                 sub     %o2, %l1, %o2
F006C78C: 80a64011                 cmp     %i1, %l1
F006C790: 02800022                 be      loc_F006C818
F006C794: f2242014                 st      %i1, [%l0+0x14]
F006C798: d4042010                 ld      [%l0+0x10], %o2
F006C79C: 80a6400a                 cmp     %i1, %o2
F006C7A0: 0a800008                 bcs     loc_F006C7C0
F006C7A4: a2244019                 sub     %l1, %i1, %l1
F006C7A8: d004200c                 ld      [%l0+0xC], %o0
F006C7AC: 92064011                 add     %i1, %l1, %o1
F006C7B0: 90028008                 add     %o2, %o0, %o0
F006C7B4: 80a24008                 cmp     %o1, %o0
F006C7B8: 28800007                 bleu,a  loc_F006C7D4
F006C7BC: d0042008                 ld      [%l0+8], %o0
F006C7C0: 90100018                 mov     %i0, %o0
F006C7C4: 92100019                 mov     %i1, %o1
F006C7C8: 7fffff62                 call    _remap_vnode
F006C7CC: 94100011                 mov     %l1, %o2
F006C7D0: d0042008                 ld      [%l0+8], %o0
F006C7D4: 92100011                 mov     %l1, %o1! size_t
F006C7D8: d4042010                 ld      [%l0+0x10], %o2
F006C7DC: 90020019                 add     %o0, %i1, %o0! void *
F006C7E0: 4000a19e                 call    _bzero
F006C7E4: 9022000a                 sub     %o0, %o2, %o0
F006C7E8: d2142004                 lduh    [%l0+4], %o1
F006C7EC: 90100010                 mov     %l0, %o0
F006C7F0: 92026001                 inc     %o1
F006C7F4: d2342004                 sth     %o1, [%l0+4]
F006C7F8: d2042038                 ld      [%l0+0x38], %o1
F006C7FC: 15100000                 sethi   0x40000000, %o2
F006C800: 9212400a                 bset    %o2, %o1
F006C804: 4000037f                 call    _vmp_push
F006C808: d2242038                 st      %o1, [%l0+0x38]
F006C80C: d0142004                 lduh    [%l0+4], %o0
F006C810: 90023fff                 inc     -1, %o0
F006C814: d0342004                 sth     %o0, [%l0+4]
F006C818: 40000037                 call    _vmp_put
F006C81C: 90100010                 mov     %l0, %o0
F006C820: b0102001                 mov     1, %i0
F006C824: 81c7e008                 ret
F006C828: 81e80000                 restore
