F00C93A4: 9de3bf78                 save    %sp, -0x88, %sp
F00C93A8: a207bfd8                 add     %fp, __b, %l1
F00C93AC: 90100011                 mov     %l1, %o0! __b
F00C93B0: e006211c                 ld      [%i0+0x11C], %l0
F00C93B4: 92102000                 mov     0, %o1! __c
F00C93B8: e4062118                 ld      [%i0+0x118], %l2
F00C93BC: 7ffcf3f0                 call    _memset
F00C93C0: 94102018                 mov     0x18, %o2
F00C93C4: d00fbfdb                 ldub    [%fp+__b+3], %o0
F00C93C8: d027bfd8                 st      %o0, [%fp+__b]
F00C93CC: d006210c                 ld      [%i0+0x10C], %o0
F00C93D0: 80a22000                 cmp     %o0, 0
F00C93D4: 0280001e                 be      loc_F00C944C
F00C93D8: 80a4a000                 cmp     %l2, 0
F00C93DC: d0062110                 ld      [%i0+0x110], %o0
F00C93E0: 80a22000                 cmp     %o0, 0
F00C93E4: 0280000d                 be      loc_F00C9418
F00C93E8: 90102018                 mov     0x18, %o0
F00C93EC: d027bfdc                 st      %o0, [%fp+var_24]
F00C93F0: 110008c890122336         set     0x232336, %o0
F00C93F8: d027bfec                 st      %o0, [%fp+var_14]
F00C93FC: 400003a6                 call    _IOGetKernPort
F00C9400: d006210c                 ld      [%i0+0x10C], %o0
F00C9404: d027bfe8                 st      %o0, [%fp+var_18]
F00C9408: 90100011                 mov     %l1, %o0
F00C940C: 92102000                 mov     0, %o1
F00C9410: 7ffe7207                 call    _msg_send_from_kernel
F00C9414: 94102000                 mov     0, %o2
F00C9418: d0062114                 ld      [%i0+0x114], %o0! id
F00C941C: 133c0506                 sethi   %hi(paDevice_0), %o1! SEL
F00C9420: 4000a114                 call    _objc_msgSend
F00C9424: d20260fc                 ld      [%o1+%lo(paDevice_0)], %o1
F00C9428: 133c0504                 sethi   %hi(paDetachinterrup_0), %o1! SEL
F00C942C: 4000a111                 call    _objc_msgSend
F00C9430: d20260b0                 ld      [%o1+%lo(paDetachinterrup_0)], %o1
F00C9434: 7ffe779f                 call    _task_self
F00C9438: 01000000                 nop
F00C943C: 4000aa0c                 call    _port_deallocate_EXTERNAL
F00C9440: d206210c                 ld      [%i0+0x10C], %o1
F00C9444: c026210c                 clr     [%i0+0x10C]
F00C9448: 80a4a000                 cmp     %l2, 0
F00C944C: 02800015                 be      loc_F00C94A0
F00C9450: 80a42000                 cmp     %l0, 0
F00C9454: d0048000                 ld      [%l2], %o0
F00C9458: 80a22001                 cmp     %o0, 1
F00C945C: 12800005                 bne     loc_F00C9470
F00C9460: 80a22002                 cmp     %o0, 2
F00C9464: 113c0506                 sethi   %hi(paFreeeisa), %o0
F00C9468: 1080000b                 ba      loc_F00C9494
F00C946C: d20220f8                 ld      [%o0+%lo(paFreeeisa)], %o1
F00C9470: 12800005                 bne     loc_F00C9484
F00C9474: 80a22003                 cmp     %o0, 3
F00C9478: 113c0506                 sethi   %hi(paFreehppa), %o0
F00C947C: 10800006                 ba      loc_F00C9494
F00C9480: d20220f4                 ld      [%o0+%lo(paFreehppa)], %o1
F00C9484: 12800007                 bne     loc_F00C94A0
F00C9488: 80a42000                 cmp     %l0, 0
F00C948C: 113c0506                 sethi   %hi(paFreesparc), %o0! id
F00C9490: d20220f0                 ld      [%o0+%lo(paFreesparc)], %o1! SEL
F00C9494: 4000a0f7                 call    _objc_msgSend
F00C9498: 90100018                 mov     %i0, %o0
F00C949C: 80a42000                 cmp     %l0, 0
F00C94A0: 22800015                 be,a    loc_F00C94F4
F00C94A4: f027bff0                 st      %i0, [%fp+var_10]
F00C94A8: d4040000                 ld      [%l0], %o2
F00C94AC: 80a2a000                 cmp     %o2, 0
F00C94B0: 22800007                 be,a    loc_F00C94CC
F00C94B4: d4042004                 ld      [%l0+4], %o2
F00C94B8: 113c0503                 sethi   %hi(paFree), %o0! id
F00C94BC: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C94C0: 4000a0ec                 call    _objc_msgSend
F00C94C4: 9010000a                 mov     %o2, %o0
F00C94C8: d4042004                 ld      [%l0+4], %o2
F00C94CC: 80a2a000                 cmp     %o2, 0
F00C94D0: 02800005                 be      loc_F00C94E4
F00C94D4: 113c0503                 sethi   %hi(paFree), %o0! id
F00C94D8: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C94DC: 4000a0e5                 call    _objc_msgSend
F00C94E0: 9010000a                 mov     %o2, %o0
F00C94E4: 90100010                 mov     %l0, %o0
F00C94E8: 7ffff297                 call    _IOFree
F00C94EC: 92102008                 mov     8, %o1
F00C94F0: f027bff0                 st      %i0, [%fp+var_10]
F00C94F4: 133c0507                 sethi   %hi(stru_F0141F5C.ext), %o1
F00C94F8: d4026388                 ld      [%o1+%lo(stru_F0141F5C.ext)], %o2
F00C94FC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9500: 133c0503                 sethi   %hi(paFree), %o1
F00C9504: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C9508: 4000a11d                 call    _objc_msgSendSuper
F00C950C: d427bff4                 st      %o2, [%fp+var_C]
F00C9510: 81c7e008                 ret
F00C9514: 91e80008                 restore %g0, %o0, %o0
