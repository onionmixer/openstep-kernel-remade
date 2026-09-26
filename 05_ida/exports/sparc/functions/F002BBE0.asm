F002BBE0: 9de3bf98                 save    %sp, -0x68, %sp
F002BBE4: 90100018                 mov     %i0, %o0
F002BBE8: 92100019                 mov     %i1, %o1
F002BBEC: d6022034                 ld      [%o0+0x34], %o3
F002BBF0: 80a2e000                 cmp     %o3, 0
F002BBF4: 02800006                 be      loc_F002BC0C
F002BBF8: 9410001a                 mov     %i2, %o2
F002BBFC: 9fc2c000                 call    %o3
F002BC00: 01000000                 nop
F002BC04: 10800003                 ba      locret_F002BC10
F002BC08: b0100008                 mov     %o0, %i0
F002BC0C: b0102006                 mov     6, %i0
F002BC10: 81c7e008                 ret
F002BC14: 81e80000                 restore
