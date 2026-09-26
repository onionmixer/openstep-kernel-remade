F0071DBC: 9de3bf98                 save    %sp, -0x68, %sp
F0071DC0: 40000010                 call    _rem_runq
F0071DC4: 90100018                 mov     %i0, %o0
F0071DC8: 80a22000                 cmp     %o0, 0
F0071DCC: 0280000b                 be      locret_F0071DF8
F0071DD0: f2262058                 st      %i1, [%i0+0x58]
F0071DD4: 80a6a000                 cmp     %i2, 0
F0071DD8: 02800006                 be      loc_F0071DF0
F0071DDC: 01000000                 nop
F0071DE0: 90100018                 mov     %i0, %o0
F0071DE4: 7fffffaf                 call    _thread_setrun
F0071DE8: 92102001                 mov     1, %o1
F0071DEC: 30800003                 ba,a    locret_F0071DF8
F0071DF0: 7fffff83                 call    _run_queue_enqueue
F0071DF4: 92100018                 mov     %i0, %o1
F0071DF8: 81c7e008                 ret
F0071DFC: 81e80000                 restore
