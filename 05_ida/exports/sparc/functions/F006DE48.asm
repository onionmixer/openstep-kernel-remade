F006DE48: 9de3bf98                 save    %sp, -0x68, %sp
F006DE4C: 7fffeb99                 call    _simple_lock_alloc
F006DE50: 01000000                 nop
F006DE54: 133c04f0                 sethi   %hi(__kernDebuggerLock), %o1
F006DE58: d0226278                 st      %o0, [%o1+%lo(__kernDebuggerLock)]
F006DE5C: c0220000                 clr     [%o0]
F006DE60: 81c7e008                 ret
F006DE64: 81e80000                 restore
