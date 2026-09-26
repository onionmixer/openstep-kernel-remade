F0094620: 9de3bf98                 save    %sp, -0x68, %sp
F0094624: 80a66001                 cmp     %i1, 1
F0094628: 02800007                 be      loc_F0094644
F009462C: 9010001a                 mov     %i2, %o0
F0094630: 80a66002                 cmp     %i1, 2
F0094634: 02800006                 be      locret_F009464C
F0094638: b0102000                 mov     0, %i0
F009463C: 10800004                 ba      locret_F009464C
F0094640: b0102003                 mov     3, %i0
F0094644: 7fffffb2                 call    sub_F009450C
F0094648: b0102000                 mov     0, %i0
F009464C: 81c7e008                 ret
F0094650: 81e80000                 restore
