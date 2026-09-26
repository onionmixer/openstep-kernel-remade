F00C9EB8: 9de3bf90                 save    %sp, -0x70, %sp
F00C9EBC: 92102001                 mov     1, %o1
F00C9EC0: e0062004                 ld      [%i0+4], %l0
F00C9EC4: 94102000                 mov     0, %o2
F00C9EC8: 7ffe9c4d                 call    _thread_wakeup_prim
F00C9ECC: 90042008                 add     %l0, 8, %o0
F00C9ED0: 7ffe7c59                 call    _lock_done
F00C9ED4: d0042004                 ld      [%l0+4], %o0
F00C9ED8: 81c7e008                 ret
F00C9EDC: 81e80000                 restore
