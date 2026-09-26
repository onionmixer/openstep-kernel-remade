F007A504: 9de3bf98                 save    %sp, -0x68, %sp
F007A508: 80a66001                 cmp     %i1, 1
F007A50C: 04800005                 ble     loc_F007A520
F007A510: f0060000                 ld      [%i0], %i0
F007A514: f22624c8                 st      %i1, [%i0+0x4C8]
F007A518: 10800003                 ba      locret_F007A524
F007A51C: b0102000                 mov     0, %i0
F007A520: b0102067                 mov     0x67, %i0 ! 'g'
F007A524: 81c7e008                 ret
F007A528: 81e80000                 restore
