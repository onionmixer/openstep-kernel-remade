F0073FB0: 9de3bf98                 save    %sp, -0x68, %sp
F0073FB4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0073FB8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0073FBC: 80a60008                 cmp     %i0, %o0
F0073FC0: 02800004                 be      loc_F0073FD0
F0073FC4: 113c0442                 sethi   %hi(aStackPrivilege), %o0! "stack_privilege"
F0073FC8: 7ffe846a                 call    _panic
F0073FCC: 90122298                 bset    %lo(aStackPrivilege), %o0! "stack_privilege"
F0073FD0: d0062030                 ld      [%i0+0x30], %o0
F0073FD4: 80a22000                 cmp     %o0, 0
F0073FD8: 12800004                 bne     locret_F0073FE8
F0073FDC: 113c04f0                 sethi   %hi(_active_stacks), %o0
F0073FE0: d0022058                 ld      [%o0+%lo(_active_stacks)], %o0
F0073FE4: d0262030                 st      %o0, [%i0+0x30]
F0073FE8: 81c7e008                 ret
F0073FEC: 81e80000                 restore
