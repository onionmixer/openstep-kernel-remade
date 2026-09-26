F006E464: 9de3bf68                 save    %sp, -0x98, %sp
F006E468: e6060000                 ld      [%i0], %l3
F006E46C: a53ce01f                 sra     %l3, 31, %l2
F006E470: 8534e01b                 srl     %l3, 27, %g2
F006E474: 872ca005                 sll     %l2, 5, %g3
F006E478: 90108003                 or      %g2, %g3, %o0
F006E47C: 932ce005                 sll     %l3, 5, %o1
F006E480: 92a24013                 subcc   %o1, %l3, %o1
F006E484: 90620012                 subc    %o0, %l2, %o0
F006E488: 9932601e                 srl     %o1, 30, %o4
F006E48C: 9b2a2002                 sll     %o0, 2, %o5
F006E490: 9413000d                 or      %o4, %o5, %o2
F006E494: 972a6002                 sll     %o1, 2, %o3
F006E498: 96a2c013                 subcc   %o3, %l3, %o3
F006E49C: 94628012                 subc    %o2, %l2, %o2
F006E4A0: 9332e01c                 srl     %o3, 28, %o1
F006E4A4: 912aa004                 sll     %o2, 4, %o0
F006E4A8: 92124008                 bset    %o0, %o1
F006E4AC: d227bfc8                 st      %o1, [%fp+var_38]
F006E4B0: 952ae004                 sll     %o3, 4, %o2
F006E4B4: d427bfcc                 st      %o2, [%fp+var_38+4]
F006E4B8: c41fbfc8                 ldd     [%fp+var_38], %g2
F006E4BC: c43fbfc8                 std     %g2, [%fp+var_38]
F006E4C0: 9a80c013                 addcc   %g3, %l3, %o5
F006E4C4: 98408012                 addc    %g2, %l2, %o4
F006E4C8: d83fbfc8                 std     %o4, [%fp+var_38]
F006E4CC: da07bfcc                 ld      [%fp+var_38+4], %o5
F006E4D0: c407bfc8                 ld      [%fp+var_38], %g2
F006E4D4: c607bfcc                 ld      [%fp+var_38+4], %g3
F006E4D8: 9333601d                 srl     %o5, 29, %o1
F006E4DC: 9128a003                 sll     %g2, 3, %o0
F006E4E0: a0124008                 or      %o1, %o0, %l0
F006E4E4: a328e003                 sll     %g3, 3, %l1
F006E4E8: a2a44013                 subcc   %l1, %l3, %l1
F006E4EC: a0640012                 subc    %l0, %l2, %l0
F006E4F0: 9334601b                 srl     %l1, 27, %o1
F006E4F4: 912c2005                 sll     %l0, 5, %o0
F006E4F8: a8124008                 or      %o1, %o0, %l4
F006E4FC: ab2c6005                 sll     %l1, 5, %l5
F006E500: aaa54011                 subcc   %l5, %l1, %l5
F006E504: a8650010                 subc    %l4, %l0, %l4
F006E508: 9335601e                 srl     %l5, 30, %o1
F006E50C: 912d2002                 sll     %l4, 2, %o0
F006E510: ac124008                 or      %o1, %o0, %l6
F006E514: af2d6002                 sll     %l5, 2, %l7
F006E518: ae85c013                 addcc   %l7, %l3, %l7
F006E51C: ac458012                 addc    %l6, %l2, %l6
F006E520: 9335e017                 srl     %l7, 23, %o1
F006E524: 912da009                 sll     %l6, 9, %o0
F006E528: 92124008                 bset    %o0, %o1
F006E52C: d227bff0                 st      %o1, [%fp+var_10]
F006E530: ad2de009                 sll     %l7, 9, %l6
F006E534: d0062004                 ld      [%i0+4], %o0
F006E538: ec27bff4                 st      %l6, [%fp+var_10+4]
F006E53C: d81fbff0                 ldd     [%fp+var_10], %o4
F006E540: ba100008                 mov     %o0, %i5
F006E544: b93a201f                 sra     %o0, 31, %i4
F006E548: 9337601b                 srl     %i5, 27, %o1
F006E54C: 912f2005                 sll     %i4, 5, %o0
F006E550: b4124008                 or      %o1, %o0, %i2
F006E554: b72f6005                 sll     %i5, 5, %i3
F006E558: b6a6c01d                 subcc   %i3, %i5, %i3
F006E55C: b466801c                 subc    %i2, %i4, %i2
F006E560: 9336e01e                 srl     %i3, 30, %o1
F006E564: 912ea002                 sll     %i2, 2, %o0
F006E568: 92124008                 bset    %o0, %o1
F006E56C: d227bfe8                 st      %o1, [%fp+var_18]
F006E570: b52ee002                 sll     %i3, 2, %i2
F006E574: f427bfec                 st      %i2, [%fp+var_18+4]
F006E578: c41fbfe8                 ldd     [%fp+var_18], %g2
F006E57C: d83fbff0                 std     %o4, [%fp+var_10]
F006E580: c43fbfe8                 std     %g2, [%fp+var_18]
F006E584: 9680c01d                 addcc   %g3, %i5, %o3
F006E588: 9440801c                 addc    %g2, %i4, %o2
F006E58C: 9332e01d                 srl     %o3, 29, %o1
F006E590: 912aa003                 sll     %o2, 3, %o0
F006E594: 92124008                 bset    %o0, %o1
F006E598: d227bfe0                 st      %o1, [%fp+var_20]
F006E59C: 952ae003                 sll     %o3, 3, %o2
F006E5A0: d427bfe4                 st      %o2, [%fp+var_20+4]
F006E5A4: d81fbfe0                 ldd     [%fp+var_20], %o4
F006E5A8: 90102000                 mov     0, %o0
F006E5AC: c41fbff0                 ldd     [%fp+var_10], %g2
F006E5B0: 9680c00d                 addcc   %g3, %o5, %o3
F006E5B4: 9440800c                 addc    %g2, %o4, %o2
F006E5B8: 9210000a                 mov     %o2, %o1
F006E5BC: 9410000b                 mov     %o3, %o2
F006E5C0: 4000a4f9                 call    _set_clock
F006E5C4: d83fbfe0                 std     %o4, [%fp+var_20]
F006E5C8: 81c7e008                 ret
F006E5CC: 81e80000                 restore
