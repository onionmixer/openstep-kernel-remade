F007B834: 9de3bf98                 save    %sp, -0x68, %sp
F007B838: d0062004                 ld      [%i0+4], %o0
F007B83C: 80a22018                 cmp     %o0, 0x18
F007B840: 12800005                 bne     loc_F007B854
F007B844: d20e2003                 ldub    [%i0+3], %o1
F007B848: 80a26001                 cmp     %o1, 1
F007B84C: 22800004                 be,a    loc_F007B85C
F007B850: d206a024                 ld      [%i2+0x24], %o1
F007B854: 10800008                 ba      loc_F007B874
F007B858: 90103ed0                 mov     -0x130, %o0
F007B85C: 80a26000                 cmp     %o1, 0
F007B860: 02800005                 be      loc_F007B874
F007B864: 90103ed1                 mov     -0x12F, %o0
F007B868: 9fc24000                 call    %o1
F007B86C: d0068000                 ld      [%i2], %o0
F007B870: 90103ecf                 mov     -0x131, %o0
F007B874: d026601c                 st      %o0, [%i1+0x1C]
F007B878: 81c7e008                 ret
F007B87C: 81e80000                 restore
