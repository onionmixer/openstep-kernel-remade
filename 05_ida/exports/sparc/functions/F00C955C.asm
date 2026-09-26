F00C955C: 9de3bf90                 save    %sp, -0x70, %sp
F00C9560: d006210c                 ld      [%i0+0x10C], %o0
F00C9564: 80a22000                 cmp     %o0, 0
F00C9568: 3280001b                 bne,a   locret_F00C95D4
F00C956C: b0102000                 mov     0, %i0
F00C9570: 7ffe7750                 call    _task_self
F00C9574: 01000000                 nop
F00C9578: 4000a97a                 call    _port_allocate_EXTERNAL
F00C957C: 9206210c                 add     %i0, 0x10C, %o1
F00C9580: 80a22000                 cmp     %o0, 0
F00C9584: 22800004                 be,a    loc_F00C9594
F00C9588: d0062114                 ld      [%i0+0x114], %o0! id
F00C958C: 10800012                 ba      locret_F00C95D4
F00C9590: b0103d27                 mov     -0x2D9, %i0
F00C9594: 133c0506                 sethi   %hi(paDevice_0), %o1! SEL
F00C9598: 4000a0b6                 call    _objc_msgSend
F00C959C: d20260fc                 ld      [%o1+%lo(paDevice_0)], %o1
F00C95A0: 133c0506                 sethi   %hi(paAttachinterrup), %o1
F00C95A4: d20260ec                 ld      [%o1+%lo(paAttachinterrup)], %o1! SEL
F00C95A8: 4000a0b2                 call    _objc_msgSend
F00C95AC: d406210c                 ld      [%i0+0x10C], %o2
F00C95B0: 80a22000                 cmp     %o0, 0
F00C95B4: 32800008                 bne,a   locret_F00C95D4
F00C95B8: b0102000                 mov     0, %i0
F00C95BC: 7ffe773d                 call    _task_self
F00C95C0: 01000000                 nop
F00C95C4: 4000a9aa                 call    _port_deallocate_EXTERNAL
F00C95C8: d206210c                 ld      [%i0+0x10C], %o1
F00C95CC: c026210c                 clr     [%i0+0x10C]
F00C95D0: b0103d27                 mov     -0x2D9, %i0
F00C95D4: 81c7e008                 ret
F00C95D8: 81e80000                 restore
