F0089510: 9de3bf98                 save    %sp, -0x68, %sp
F0089514: c416201c                 lduh    [%i0+0x1C], %g2
F0089518: 80a0a000                 cmp     %g2, 0
F008951C: 32800049                 bne,a   loc_F0089640
F0089520: c416201c                 lduh    [%i0+0x1C], %g2
F0089524: c606201c                 ld      [%i0+0x1C], %g3
F0089528: 05000010                 sethi   0x4000, %g2
F008952C: 8088c002                 btst    %g2, %g3
F0089530: 02800014                 be      loc_F0089580
F0089534: 353c04f3                 sethi   %hi(_vm_page_queue_active), %i2
F0089538: f2060000                 ld      [%i0], %i1
F008953C: c6062004                 ld      [%i0+4], %g3
F0089540: 8416a008                 or      %i2, %lo(_vm_page_queue_active), %g2
F0089544: 80a0c002                 cmp     %g3, %g2
F0089548: 12800004                 bne     loc_F0089558
F008954C: c6266004                 st      %g3, [%i1+4]
F0089550: 10800003                 ba      loc_F008955C
F0089554: f226a008                 st      %i1, [%i2+%lo(_vm_page_queue_active)]
F0089558: f220c000                 st      %i1, [%g3]
F008955C: 073c04f2                 sethi   %hi(_vm_page_active_count), %g3
F0089560: c400e3f8                 ld      [%g3+%lo(_vm_page_active_count)], %g2
F0089564: 8400bfff                 inc     -1, %g2
F0089568: c420e3f8                 st      %g2, [%g3+%lo(_vm_page_active_count)]
F008956C: c606201c                 ld      [%i0+0x1C], %g3
F0089570: 05000010                 sethi   0x4000, %g2
F0089574: 8428c002                 andn    %g3, %g2, %g2
F0089578: c426201c                 st      %g2, [%i0+0x1C]
F008957C: c606201c                 ld      [%i0+0x1C], %g3
F0089580: 05000020                 sethi   0x8000, %g2
F0089584: 8088c002                 btst    %g2, %g3
F0089588: 02800013                 be      loc_F00895D4
F008958C: 353c04f0                 sethi   %hi(_vm_page_queue_inactive), %i2
F0089590: f2060000                 ld      [%i0], %i1
F0089594: c6062004                 ld      [%i0+4], %g3
F0089598: 8416a228                 or      %i2, %lo(_vm_page_queue_inactive), %g2
F008959C: 80a0c002                 cmp     %g3, %g2
F00895A0: 12800004                 bne     loc_F00895B0
F00895A4: c6266004                 st      %g3, [%i1+4]
F00895A8: 10800003                 ba      loc_F00895B4
F00895AC: f226a228                 st      %i1, [%i2+%lo(_vm_page_queue_inactive)]
F00895B0: f220c000                 st      %i1, [%g3]
F00895B4: 073c04f0                 sethi   %hi(_vm_page_inactive_count), %g3
F00895B8: c400e220                 ld      [%g3+%lo(_vm_page_inactive_count)], %g2
F00895BC: 8400bfff                 inc     -1, %g2
F00895C0: c420e220                 st      %g2, [%g3+%lo(_vm_page_inactive_count)]
F00895C4: c606201c                 ld      [%i0+0x1C], %g3
F00895C8: 05000020                 sethi   0x8000, %g2
F00895CC: 8428c002                 andn    %g3, %g2, %g2
F00895D0: c426201c                 st      %g2, [%i0+0x1C]
F00895D4: c606201c                 ld      [%i0+0x1C], %g3
F00895D8: 05000004                 sethi   0x1000, %g2
F00895DC: 8088c002                 btst    %g2, %g3
F00895E0: 02800013                 be      loc_F008962C
F00895E4: 353c04f3                 sethi   %hi(_vm_page_queue_free), %i2
F00895E8: f2060000                 ld      [%i0], %i1
F00895EC: c6062004                 ld      [%i0+4], %g3
F00895F0: 8416a010                 or      %i2, %lo(_vm_page_queue_free), %g2
F00895F4: 80a0c002                 cmp     %g3, %g2
F00895F8: 12800004                 bne     loc_F0089608
F00895FC: c6266004                 st      %g3, [%i1+4]
F0089600: 10800003                 ba      loc_F008960C
F0089604: f226a010                 st      %i1, [%i2+%lo(_vm_page_queue_free)]
F0089608: f220c000                 st      %i1, [%g3]
F008960C: 073c04f3                 sethi   %hi(_vm_page_free_count), %g3
F0089610: c400e000                 ld      [%g3+%lo(_vm_page_free_count)], %g2
F0089614: 8400bfff                 inc     -1, %g2
F0089618: c420e000                 st      %g2, [%g3+%lo(_vm_page_free_count)]
F008961C: c606201c                 ld      [%i0+0x1C], %g3
F0089620: 05000004                 sethi   0x1000, %g2
F0089624: 8428c002                 andn    %g3, %g2, %g2
F0089628: c426201c                 st      %g2, [%i0+0x1C]
F008962C: 073c04f6                 sethi   %hi(_vm_page_wire_count), %g3
F0089630: c400e180                 ld      [%g3+%lo(_vm_page_wire_count)], %g2
F0089634: 8400a001                 inc     %g2
F0089638: c420e180                 st      %g2, [%g3+%lo(_vm_page_wire_count)]
F008963C: c416201c                 lduh    [%i0+0x1C], %g2
F0089640: 8400a001                 inc     %g2
F0089644: c436201c                 sth     %g2, [%i0+0x1C]
F0089648: 81c7e008                 ret
F008964C: 81e80000                 restore
