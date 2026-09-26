F0089650: 9de3bf98                 save    %sp, -0x68, %sp
F0089654: b2100018                 mov     %i0, %i1
F0089658: c416601c                 lduh    [%i1+0x1C], %g2
F008965C: 8400bfff                 inc     -1, %g2
F0089660: c436601c                 sth     %g2, [%i1+0x1C]
F0089664: 8528a010                 sll     %g2, 16, %g2
F0089668: 80a0a000                 cmp     %g2, 0
F008966C: 1280001a                 bne     locret_F00896D4
F0089670: 053c04f3                 sethi   %hi(dword_F013CC0C), %g2
F0089674: c600a00c                 ld      [%g2+%lo(dword_F013CC0C)], %g3
F0089678: b010a00c                 or      %g2, %lo(dword_F013CC0C), %i0
F008967C: 84063ffc                 add     %i0, -4, %g2
F0089680: 80a0c002                 cmp     %g3, %g2
F0089684: 32800003                 bne,a   loc_F0089690
F0089688: f220c000                 st      %i1, [%g3]
F008968C: f2263ffc                 st      %i1, [%i0-4]
F0089690: c6266004                 st      %g3, [%i1+4]
F0089694: 053c04f38410a008         set     _vm_page_queue_active, %g2
F008969C: c4264000                 st      %g2, [%i1]
F00896A0: f220a004                 st      %i1, [%g2+4]
F00896A4: 073c04f2                 sethi   %hi(_vm_page_active_count), %g3
F00896A8: c400e3f8                 ld      [%g3+%lo(_vm_page_active_count)], %g2
F00896AC: 313c04f6                 sethi   %hi(_vm_page_wire_count), %i0
F00896B0: 8400a001                 inc     %g2
F00896B4: c420e3f8                 st      %g2, [%g3+%lo(_vm_page_active_count)]
F00896B8: c606601c                 ld      [%i1+0x1C], %g3
F00896BC: 05000010                 sethi   0x4000, %g2
F00896C0: 8610c002                 bset    %g2, %g3
F00896C4: c4062180                 ld      [%i0+%lo(_vm_page_wire_count)], %g2
F00896C8: c626601c                 st      %g3, [%i1+0x1C]
F00896CC: 8400bfff                 inc     -1, %g2
F00896D0: c4262180                 st      %g2, [%i0+%lo(_vm_page_wire_count)]
F00896D4: 81c7e008                 ret
F00896D8: 81e80000                 restore
