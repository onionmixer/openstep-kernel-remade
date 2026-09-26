F002005C: 9de3bf98                 save    %sp, -0x68, %sp
F0020060: d2162006                 lduh    [%i0+6], %o1
F0020064: 90062054                 add     %i0, 0x54, %o0 ! 'T'
F0020068: 920a7ffb                 and     %o1, -5, %o1
F002006C: 92126038                 bset    0x38, %o1 ! '8'
F0020070: 7fffcb5e                 call    _wakeup
F0020074: d2362006                 sth     %o1, [%i0+6]
F0020078: 90100018                 mov     %i0, %o0
F002007C: 400000e4                 call    _sowakeup
F0020080: 9206203c                 add     %i0, 0x3C, %o1 ! '<'
F0020084: 90100018                 mov     %i0, %o0
F0020088: 400000e1                 call    _sowakeup
F002008C: 92022024                 add     %o0, 0x24, %o1 ! '$'
F0020090: 81c7e008                 ret
F0020094: 81e80000                 restore
