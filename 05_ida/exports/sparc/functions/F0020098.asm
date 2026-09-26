F0020098: 9de3bf98                 save    %sp, -0x68, %sp
F002009C: d2162006                 lduh    [%i0+6], %o1
F00200A0: 90062054                 add     %i0, 0x54, %o0 ! 'T'
F00200A4: 920a7ff1                 and     %o1, -0xF, %o1
F00200A8: 92126030                 bset    0x30, %o1 ! '0'
F00200AC: 7fffcb4f                 call    _wakeup
F00200B0: d2362006                 sth     %o1, [%i0+6]
F00200B4: 90100018                 mov     %i0, %o0
F00200B8: 400000d5                 call    _sowakeup
F00200BC: 9206203c                 add     %i0, 0x3C, %o1 ! '<'
F00200C0: 90100018                 mov     %i0, %o0
F00200C4: 400000d2                 call    _sowakeup
F00200C8: 92022024                 add     %o0, 0x24, %o1 ! '$'
F00200CC: 81c7e008                 ret
F00200D0: 81e80000                 restore
