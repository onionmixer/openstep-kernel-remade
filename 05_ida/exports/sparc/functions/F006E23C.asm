F006E23C: 9de3bf98                 save    %sp, -0x68, %sp
F006E240: aa100018                 mov     %i0, %l5
F006E244: de054000                 ld      [%l5], %o7
F006E248: ba10000f                 mov     %o7, %i5
F006E24C: b93be01f                 sra     %o7, 31, %i4
F006E250: a937601b                 srl     %i5, 27, %l4
F006E254: 9f2f2005                 sll     %i4, 5, %o7
F006E258: 8415000f                 or      %l4, %o7, %g2
F006E25C: 872f6005                 sll     %i5, 5, %g3
F006E260: 86a0c01d                 subcc   %g3, %i5, %g3
F006E264: 8460801c                 subc    %g2, %i4, %g2
F006E268: a930e01a                 srl     %g3, 26, %l4
F006E26C: 9f28a006                 sll     %g2, 6, %o7
F006E270: b415000f                 or      %l4, %o7, %i2
F006E274: b728e006                 sll     %g3, 6, %i3
F006E278: b6a6c003                 subcc   %i3, %g3, %i3
F006E27C: b4668002                 subc    %i2, %g2, %i2
F006E280: 8736e01d                 srl     %i3, 29, %g3
F006E284: 852ea003                 sll     %i2, 3, %g2
F006E288: 9010c002                 or      %g3, %g2, %o0
F006E28C: 932ee003                 sll     %i3, 3, %o1
F006E290: 9282401d                 addcc   %o1, %i5, %o1
F006E294: 9042001c                 addc    %o0, %i4, %o0
F006E298: 8732601a                 srl     %o1, 26, %g3
F006E29C: 852a2006                 sll     %o0, 6, %g2
F006E2A0: 9410c002                 or      %g3, %g2, %o2
F006E2A4: c4056004                 ld      [%l5+4], %g2
F006E2A8: 972a6006                 sll     %o1, 6, %o3
F006E2AC: a6100002                 mov     %g2, %l3
F006E2B0: a538a01f                 sra     %g2, 31, %l2
F006E2B4: 9682c013                 addcc   %o3, %l3, %o3
F006E2B8: 94428012                 addc    %o2, %l2, %o2
F006E2BC: 8732e01b                 srl     %o3, 27, %g3
F006E2C0: 852aa005                 sll     %o2, 5, %g2
F006E2C4: 9810c002                 or      %g3, %g2, %o4
F006E2C8: 9b2ae005                 sll     %o3, 5, %o5
F006E2CC: 9aa3400b                 subcc   %o5, %o3, %o5
F006E2D0: 9863000a                 subc    %o4, %o2, %o4
F006E2D4: 8733601e                 srl     %o5, 30, %g3
F006E2D8: 852b2002                 sll     %o4, 2, %g2
F006E2DC: a010c002                 or      %g3, %g2, %l0
F006E2E0: a32b6002                 sll     %o5, 2, %l1
F006E2E4: a284400b                 addcc   %l1, %o3, %l1
F006E2E8: a044000a                 addc    %l0, %o2, %l0
F006E2EC: 8734601d                 srl     %l1, 29, %g3
F006E2F0: 852c2003                 sll     %l0, 3, %g2
F006E2F4: b010c002                 or      %g3, %g2, %i0
F006E2F8: b32c6003                 sll     %l1, 3, %i1
F006E2FC: 81c7e008                 ret
F006E300: 81e80000                 restore
