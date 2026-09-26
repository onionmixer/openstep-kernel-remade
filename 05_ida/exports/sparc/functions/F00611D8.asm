F00611D8: 9de3bf98                 save    %sp, -0x68, %sp
F00611DC: e00620dc                 ld      [%i0+0xDC], %l0
F00611E0: d0040000                 ld      [%l0], %o0
F00611E4: 80a22000                 cmp     %o0, 0
F00611E8: 12bffffe                 bne     loc_F00611E0
F00611EC: 01000000                 nop
F00611F0: 4000d72e                 call    _simple_lock_try
F00611F4: 90100010                 mov     %l0, %o0
F00611F8: 80a22000                 cmp     %o0, 0
F00611FC: 02bffff9                 be      loc_F00611E0
F0061200: 11040010                 sethi   0x10004000, %o0
F0061204: d2062098                 ld      [%i0+0x98], %o1
F0061208: 90122001                 bset    1, %o0
F006120C: 80a24008                 cmp     %o1, %o0
F0061210: 12800010                 bne     loc_F0061250
F0061214: 90042008                 add     %l0, 8, %o0
F0061218: 7ffff6fe                 call    _ipc_thread_rmqueue
F006121C: 92100018                 mov     %i0, %o1
F0061220: c0240000                 clr     [%l0]
F0061224: 7fffe113                 call    _ipc_object_release
F0061228: d00620d8                 ld      [%i0+0xD8], %o0
F006122C: 90100018                 mov     %i0, %o0
F0061230: 13040010                 sethi   0x10004000, %o1
F0061234: 4000eb81                 call    _thread_set_syscall_return
F0061238: 92126005                 bset    5, %o1
F006123C: 113c026f901223e4         set     _thread_exception_return, %o0
F0061244: d0262034                 st      %o0, [%i0+0x34]
F0061248: 10800004                 ba      locret_F0061258
F006124C: b0102001                 mov     1, %i0
F0061250: c0240000                 clr     [%l0]
F0061254: b0102000                 mov     0, %i0
F0061258: 81c7e008                 ret
F006125C: 81e80000                 restore
