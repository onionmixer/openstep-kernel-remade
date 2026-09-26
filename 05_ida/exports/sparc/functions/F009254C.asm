F009254C: 9de3bf90                 save    %sp, -0x70, %sp
F0092550: 40000239                 call    sub_F0092E34
F0092554: d056201e                 ldsh    [%i0+0x1E], %o0
F0092558: a2920000                 orcc    %o0, %g0, %l1
F009255C: 32800004                 bne,a   loc_F009256C
F0092560: d2060000                 ld      [%i0], %o1
F0092564: 1080002e                 ba      loc_F009261C
F0092568: 90102006                 mov     6, %o0
F009256C: 1101000090122010         set     0x4000010, %o0
F0092574: 920a4008                 and     %o1, %o0, %o1
F0092578: 80a26010                 cmp     %o1, 0x10
F009257C: 32800006                 bne,a   loc_F0092594
F0092580: 113c04d1                 sethi   -0xFECBC00, %o0
F0092584: d006202c                 ld      [%i0+0x2C], %o0
F0092588: d0022068                 ld      [%o0+0x68], %o0
F009258C: 10800003                 ba      loc_F0092598
F0092590: e002200c                 ld      [%o0+0xC], %l0
F0092594: e0022340                 ld      [%o0+0x340], %l0
F0092598: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F009259C: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F00925A0: 40017cb4                 call    _objc_msgSend
F00925A4: 90100011                 mov     %l1, %o0
F00925A8: 80a22000                 cmp     %o0, 0
F00925AC: 32800004                 bne,a   loc_F00925BC
F00925B0: d4062024                 ld      [%i0+0x24], %o2
F00925B4: 1080001a                 ba      loc_F009261C
F00925B8: 90102006                 mov     6, %o0
F00925BC: d6062014                 ld      [%i0+0x14], %o3
F00925C0: d0060000                 ld      [%i0], %o0
F00925C4: 808a2001                 btst    1, %o0
F00925C8: 02800007                 be      loc_F00925E4
F00925CC: d8062020                 ld      [%i0+0x20], %o4
F00925D0: e023a05c                 st      %l0, [%sp+0x70+var_14]
F00925D4: 90100011                 mov     %l1, %o0
F00925D8: 133c0504                 sethi   %hi(paReadasyncatLen), %o1
F00925DC: 10800006                 ba      loc_F00925F4
F00925E0: d202618c                 ld      [%o1+%lo(paReadasyncatLen)], %o1
F00925E4: e023a05c                 st      %l0, [%sp+0x70+var_14]
F00925E8: 90100011                 mov     %l1, %o0! id
F00925EC: 133c0504                 sethi   %hi(paWriteasyncatLe), %o1
F00925F0: d2026190                 ld      [%o1+%lo(paWriteasyncatLe)], %o1! SEL
F00925F4: 40017c9f                 call    _objc_msgSend
F00925F8: 9a100018                 mov     %i0, %o5
F00925FC: 94920000                 orcc    %o0, %g0, %o2
F0092600: 12800004                 bne     loc_F0092610
F0092604: 133c0504                 sethi   -0xFEBF000, %o1
F0092608: 1080000c                 ba      locret_F0092638
F009260C: b0102000                 mov     0, %i0
F0092610: d2026194                 ld      [%o1+0x194], %o1! SEL
F0092614: 40017c97                 call    _objc_msgSend
F0092618: 90100011                 mov     %l1, %o0
F009261C: d036201c                 sth     %o0, [%i0+0x1C]
F0092620: d2060000                 ld      [%i0], %o1
F0092624: 90100018                 mov     %i0, %o0
F0092628: 92126004                 bset    4, %o1
F009262C: 7ffe4aa9                 call    _biodone
F0092630: d2220000                 st      %o1, [%o0]
F0092634: b0103fff                 mov     -1, %i0
F0092638: 81c7e008                 ret
F009263C: 81e80000                 restore
