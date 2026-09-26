F0044C68: 9de3bf98                 save    %sp, -0x68, %sp
F0044C6C: d0066018                 ld      [%i1+0x18], %o0
F0044C70: d026200c                 st      %o0, [%i0+0xC]
F0044C74: d006601c                 ld      [%i1+0x1C], %o0
F0044C78: d0262010                 st      %o0, [%i0+0x10]
F0044C7C: d0066020                 ld      [%i1+0x20], %o0
F0044C80: d206201c                 ld      [%i0+0x1C], %o1
F0044C84: d0262014                 st      %o0, [%i0+0x14]
F0044C88: 113c04eb                 sethi   %hi(__null_auth), %o0
F0044C8C: d0022020                 ld      [%o0+%lo(__null_auth)], %o0
F0044C90: d0226020                 st      %o0, [%o1+0x20]
F0044C94: d006201c                 ld      [%i0+0x1C], %o0
F0044C98: c0222028                 clr     [%o0+0x28]
F0044C9C: d206200c                 ld      [%i0+0xC], %o1
F0044CA0: 80a26002                 cmp     %o1, 2
F0044CA4: 08800004                 bleu    loc_F0044CB4
F0044CA8: 932a6002                 sll     %o1, 2, %o1
F0044CAC: 10800009                 ba      locret_F0044CD0
F0044CB0: b0102002                 mov     2, %i0
F0044CB4: 153c04379412a218         set     unk_F010DE18, %o2
F0044CBC: d402400a                 ld      [%o1+%o2], %o2
F0044CC0: 90100018                 mov     %i0, %o0
F0044CC4: 9fc28000                 call    %o2
F0044CC8: 92100019                 mov     %i1, %o1
F0044CCC: b0100008                 mov     %o0, %i0
F0044CD0: 81c7e008                 ret
F0044CD4: 81e80000                 restore
