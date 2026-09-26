F00C5F7C: 9de3bf98                 save    %sp, -0x68, %sp
F00C5F80: b2100018                 mov     %i0, %i1
F00C5F84: b0102000                 mov     0, %i0
F00C5F88: 9336601b                 srl     %i1, 27, %o1
F00C5F8C: 912e2005                 sll     %i0, 5, %o0
F00C5F90: 98124008                 or      %o1, %o0, %o4
F00C5F94: 9b2e6005                 sll     %i1, 5, %o5
F00C5F98: 9aa34019                 subcc   %o5, %i1, %o5
F00C5F9C: 98630018                 subc    %o4, %i0, %o4
F00C5FA0: 9733601a                 srl     %o5, 26, %o3
F00C5FA4: 952b2006                 sll     %o4, 6, %o2
F00C5FA8: 9012c00a                 or      %o3, %o2, %o0
F00C5FAC: 932b6006                 sll     %o5, 6, %o1
F00C5FB0: 92a2400d                 subcc   %o1, %o5, %o1
F00C5FB4: 9062000c                 subc    %o0, %o4, %o0
F00C5FB8: 9b32601d                 srl     %o1, 29, %o5
F00C5FBC: 992a2003                 sll     %o0, 3, %o4
F00C5FC0: 9413400c                 or      %o5, %o4, %o2
F00C5FC4: 972a6003                 sll     %o1, 3, %o3
F00C5FC8: 9682c019                 addcc   %o3, %i1, %o3
F00C5FCC: 94428018                 addc    %o2, %i0, %o2
F00C5FD0: 9b32e01a                 srl     %o3, 26, %o5
F00C5FD4: 992aa006                 sll     %o2, 6, %o4
F00C5FD8: 9013400c                 or      %o5, %o4, %o0
F00C5FDC: 7ffea06c                 call    _ns_sleep
F00C5FE0: 932ae006                 sll     %o3, 6, %o1
F00C5FE4: 81c7e008                 ret
F00C5FE8: 81e80000                 restore
