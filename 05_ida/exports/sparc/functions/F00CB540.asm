F00CB540: 9de3bf90                 save    %sp, -0x70, %sp
F00CB544: 113c0506                 sethi   %hi(paCleartimeout), %o0! id
F00CB548: d2022064                 ld      [%o0+%lo(paCleartimeout)], %o1! SEL
F00CB54C: 400098c9                 call    _objc_msgSend
F00CB550: 90100018                 mov     %i0, %o0
F00CB554: d006212c                 ld      [%i0+0x12C], %o0! id
F00CB558: 80a22000                 cmp     %o0, 0
F00CB55C: 2280000b                 be,a    loc_F00CB588
F00CB560: d406214c                 ld      [%i0+0x14C], %o2
F00CB564: 133c0506                 sethi   %hi(paSend), %o1
F00CB568: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CB56C: 400098c1                 call    _objc_msgSend
F00CB570: 94102004                 mov     4, %o2
F00CB574: d006212c                 ld      [%i0+0x12C], %o0! id
F00CB578: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00CB57C: 400098bd                 call    _objc_msgSend
F00CB580: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00CB584: d406214c                 ld      [%i0+0x14C], %o2
F00CB588: 80a2a000                 cmp     %o2, 0
F00CB58C: 22800007                 be,a    loc_F00CB5A8
F00CB590: d4062138                 ld      [%i0+0x138], %o2
F00CB594: 113c0503                 sethi   %hi(paFree), %o0! id
F00CB598: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00CB59C: 400098b5                 call    _objc_msgSend
F00CB5A0: 9010000a                 mov     %o2, %o0
F00CB5A4: d4062138                 ld      [%i0+0x138], %o2
F00CB5A8: 80a2a000                 cmp     %o2, 0
F00CB5AC: 02800028                 be      loc_F00CB64C
F00CB5B0: 113c0504                 sethi   %hi(paLock), %o0! id
F00CB5B4: d2022000                 ld      [%o0+%lo(paLock)], %o1! SEL
F00CB5B8: 400098ae                 call    _objc_msgSend
F00CB5BC: 9010000a                 mov     %o2, %o0
F00CB5C0: d0062144                 ld      [%i0+0x144], %o0
F00CB5C4: 92062144                 add     %i0, 0x144, %o1
F00CB5C8: 80a24008                 cmp     %o1, %o0
F00CB5CC: 22800019                 be,a    loc_F00CB630
F00CB5D0: d0062138                 ld      [%i0+0x138], %o0
F00CB5D4: a0100009                 mov     %o1, %l0
F00CB5D8: d0062144                 ld      [%i0+0x144], %o0
F00CB5DC: d6022008                 ld      [%o0+8], %o3
F00CB5E0: 80a4000b                 cmp     %l0, %o3
F00CB5E4: 12800004                 bne     loc_F00CB5F4
F00CB5E8: d402200c                 ld      [%o0+0xC], %o2
F00CB5EC: 10800003                 ba      loc_F00CB5F8
F00CB5F0: 92100010                 mov     %l0, %o1
F00CB5F4: 9202e008                 add     %o3, 8, %o1
F00CB5F8: 80a4000a                 cmp     %l0, %o2
F00CB5FC: 12800004                 bne     loc_F00CB60C
F00CB600: d4226004                 st      %o2, [%o1+4]
F00CB604: 10800003                 ba      loc_F00CB610
F00CB608: 92100010                 mov     %l0, %o1
F00CB60C: 9202a008                 add     %o2, 8, %o1
F00CB610: d6224000                 st      %o3, [%o1]
F00CB614: 7fffea4c                 call    _IOFree
F00CB618: 92102014                 mov     0x14, %o1
F00CB61C: d0062144                 ld      [%i0+0x144], %o0
F00CB620: 80a40008                 cmp     %l0, %o0
F00CB624: 32bfffef                 bne,a   loc_F00CB5E0
F00CB628: d6022008                 ld      [%o0+8], %o3
F00CB62C: d0062138                 ld      [%i0+0x138], %o0! id
F00CB630: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CB634: 4000988f                 call    _objc_msgSend
F00CB638: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CB63C: d0062138                 ld      [%i0+0x138], %o0! id
F00CB640: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00CB644: 4000988b                 call    _objc_msgSend
F00CB648: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00CB64C: f027bff0                 st      %i0, [%fp+var_10]
F00CB650: 133c0508                 sethi   %hi(stru_F014209C.super_class), %o1
F00CB654: d40260a0                 ld      [%o1+%lo(stru_F014209C.super_class)], %o2
F00CB658: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CB65C: 133c0503                 sethi   %hi(paFree), %o1
F00CB660: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00CB664: 400098c6                 call    _objc_msgSendSuper
F00CB668: d427bff4                 st      %o2, [%fp+var_C]
F00CB66C: 81c7e008                 ret
F00CB670: 91e80008                 restore %g0, %o0, %o0
