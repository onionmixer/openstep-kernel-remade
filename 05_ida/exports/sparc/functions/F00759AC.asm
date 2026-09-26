F00759AC: 9de3bf98                 save    %sp, -0x68, %sp
F00759B0: 80a62000                 cmp     %i0, 0
F00759B4: 02800006                 be      loc_F00759CC
F00759B8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00759BC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00759C0: 80a60008                 cmp     %i0, %o0
F00759C4: 12800004                 bne     loc_F00759D4
F00759C8: 90100018                 mov     %i0, %o0
F00759CC: 10800014                 ba      locret_F0075A1C
F00759D0: b0102004                 mov     4, %i0
F00759D4: 7ffffc5d                 call    _thread_halt
F00759D8: 92102000                 mov     0, %o1
F00759DC: 80a22000                 cmp     %o0, 0
F00759E0: 02800004                 be      loc_F00759F0
F00759E4: 01000000                 nop
F00759E8: 1080000d                 ba      locret_F0075A1C
F00759EC: b010200e                 mov     0xE, %i0
F00759F0: 7fffbff4                 call    _mach_msg_abort_rpc
F00759F4: 90100018                 mov     %i0, %o0
F00759F8: 7ffffe8f                 call    _thread_release
F00759FC: 90100018                 mov     %i0, %o0
F0075A00: d0062064                 ld      [%i0+0x64], %o0! thread
F0075A04: 80a23fff                 cmp     %o0, -1
F0075A08: 22800005                 be,a    locret_F0075A1C
F0075A0C: b0102000                 mov     0, %i0
F0075A10: 7ffff451                 call    _thread_depress_abort
F0075A14: 90100018                 mov     %i0, %o0
F0075A18: b0102000                 mov     0, %i0
F0075A1C: 81c7e008                 ret
F0075A20: 81e80000                 restore
