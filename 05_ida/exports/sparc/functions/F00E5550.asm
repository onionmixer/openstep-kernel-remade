F00E5550: 9de3bf98                 save    %sp, -0x68, %sp
F00E5554: 80a6200f                 cmp     %i0, 0xF
F00E5558: 073c04bb                 sethi   %hi(_sparcfbs), %g3
F00E555C: 852e2004                 sll     %i0, 4, %g2
F00E5560: 84008018                 add     %g2, %i0, %g2
F00E5564: f000e364                 ld      [%g3+%lo(_sparcfbs)], %i0
F00E5568: 8528a002                 sll     %g2, 2, %g2
F00E556C: 8600a008                 add     %g2, 8, %g3
F00E5570: 18800006                 bgu     loc_F00E5588
F00E5574: b2060003                 add     %i0, %g3, %i1
F00E5578: c4060003                 ld      [%i0+%g3], %g2
F00E557C: 80a0a000                 cmp     %g2, 0
F00E5580: 12800004                 bne     loc_F00E5590
F00E5584: 01000000                 nop
F00E5588: 10800035                 ba      locret_F00E565C
F00E558C: b0103d40                 mov     -0x2C0, %i0
F00E5590: c4060003                 ld      [%i0+%g3], %g2
F00E5594: 80a0a002                 cmp     %g2, 2
F00E5598: 0280000b                 be      loc_F00E55C4
F00E559C: 01000000                 nop
F00E55A0: 18800005                 bgu     loc_F00E55B4
F00E55A4: 80a0a001                 cmp     %g2, 1
F00E55A8: 02800015                 be      loc_F00E55FC
F00E55AC: b0103fff                 mov     -1, %i0
F00E55B0: 3080002b                 ba,a    locret_F00E565C
F00E55B4: 80a0a003                 cmp     %g2, 3
F00E55B8: 02800011                 be      loc_F00E55FC
F00E55BC: b0103fff                 mov     -1, %i0
F00E55C0: 30800027                 ba,a    locret_F00E565C
F00E55C4: c606600c                 ld      [%i1+0xC], %g3
F00E55C8: 05000010                 sethi   0x4000, %g2
F00E55CC: c020c002                 clr     [%g3+%g2]
F00E55D0: 8600c002                 add     %g3, %g2, %g3
F00E55D4: 050026668410a199         set     0x999999, %g2
F00E55DC: c420e264                 st      %g2, [%g3+0x264]
F00E55E0: 050019998410a266         set     0x666666, %g2
F00E55E8: c420e198                 st      %g2, [%g3+0x198]
F00E55EC: 05003fff8410a3ff         set     0xFFFFFF, %g2
F00E55F4: 10800019                 ba      loc_F00E5658
F00E55F8: c420e3fc                 st      %g2, [%g3+0x3FC]
F00E55FC: c406600c                 ld      [%i1+0xC], %g2
F00E5600: 073fc000                 sethi   -0x1000000, %g3
F00E5604: c0208000                 clr     [%g2]
F00E5608: c020a004                 clr     [%g2+4]
F00E560C: c020a004                 clr     [%g2+4]
F00E5610: c020a004                 clr     [%g2+4]
F00E5614: c6208000                 st      %g3, [%g2]
F00E5618: c620a004                 st      %g3, [%g2+4]
F00E561C: c620a004                 st      %g3, [%g2+4]
F00E5620: c620a004                 st      %g3, [%g2+4]
F00E5624: 07264000                 sethi   -0x67000000, %g3
F00E5628: c6208000                 st      %g3, [%g2]
F00E562C: c620a004                 st      %g3, [%g2+4]
F00E5630: c620a004                 st      %g3, [%g2+4]
F00E5634: c620a004                 st      %g3, [%g2+4]
F00E5638: 07198000                 sethi   0x66000000, %g3
F00E563C: c6208000                 st      %g3, [%g2]
F00E5640: c620a004                 st      %g3, [%g2+4]
F00E5644: c620a004                 st      %g3, [%g2+4]
F00E5648: c620a004                 st      %g3, [%g2+4]
F00E564C: c0208000                 clr     [%g2]
F00E5650: 10800003                 ba      locret_F00E565C
F00E5654: b0102000                 mov     0, %i0
F00E5658: b0102000                 mov     0, %i0
F00E565C: 81c7e008                 ret
F00E5660: 81e80000                 restore
