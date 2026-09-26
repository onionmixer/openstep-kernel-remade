F0097908: 9de3bf90                 save    %sp, -0x70, %sp
F009790C: 4000006a                 call    sub_F0097AB4
F0097910: 9007bff0                 add     %fp, var_10, %o0
F0097914: c41fbff0                 ldd     [%fp+var_10], %g2
F0097918: 9b30e01b                 srl     %g3, 27, %o5
F009791C: 9928a005                 sll     %g2, 5, %o4
F0097920: 9013400c                 or      %o5, %o4, %o0
F0097924: 9328e005                 sll     %g3, 5, %o1
F0097928: 92a24003                 subcc   %o1, %g3, %o1
F009792C: 90620002                 subc    %o0, %g2, %o0
F0097930: 9b32601e                 srl     %o1, 30, %o5
F0097934: 992a2002                 sll     %o0, 2, %o4
F0097938: 9413400c                 or      %o5, %o4, %o2
F009793C: 972a6002                 sll     %o1, 2, %o3
F0097940: 9682c003                 addcc   %o3, %g3, %o3
F0097944: 94428002                 addc    %o2, %g2, %o2
F0097948: 9332e01d                 srl     %o3, 29, %o1
F009794C: 912aa003                 sll     %o2, 3, %o0
F0097950: a0124008                 or      %o1, %o0, %l0
F0097954: a32ae003                 sll     %o3, 3, %l1
F0097958: 80a62000                 cmp     %i0, 0
F009795C: 02800008                 be      loc_F009797C
F0097960: e03fbff0                 std     %l0, [%fp+var_10]
F0097964: 80a62001                 cmp     %i0, 1
F0097968: 1280000b                 bne     loc_F0097994
F009796C: 01000000                 nop
F0097970: b0100010                 mov     %l0, %i0
F0097974: b2100011                 mov     %l1, %i1
F0097978: 30800009                 ba,a    locret_F009799C
F009797C: 113c04c5                 sethi   %hi(qword_F0131468), %o0
F0097980: f01a2068                 ldd     [%o0+%lo(qword_F0131468)], %i0
F0097984: b2844019                 addcc   %l1, %i1, %i1
F0097988: b0440018                 addc    %l0, %i0, %i0
F009798C: 10800004                 ba      locret_F009799C
F0097990: f03fbff0                 std     %i0, [%fp+var_10]
F0097994: b0102000                 mov     0, %i0
F0097998: b2102000                 mov     0, %i1
F009799C: 81c7e008                 ret
F00979A0: 81e80000                 restore
