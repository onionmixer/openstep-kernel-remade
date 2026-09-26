F0005E1C: 9de3bf98                 save    %sp, -0x68, %sp
F0005E20: 80a6001a                 cmp     %i0, %i2
F0005E24: 2680000d                 bl,a    locret_F0005E58
F0005E28: b0102000                 mov     0, %i0
F0005E2C: 04800004                 ble     loc_F0005E3C
F0005E30: 80a6401b                 cmp     %i1, %i3
F0005E34: 10800009                 ba      locret_F0005E58
F0005E38: b0102002                 mov     2, %i0
F0005E3C: 1a800004                 bcc     loc_F0005E4C
F0005E40: 80a6401b                 cmp     %i1, %i3
F0005E44: 10800005                 ba      locret_F0005E58
F0005E48: b0102000                 mov     0, %i0
F0005E4C: 18800003                 bgu     locret_F0005E58
F0005E50: b0102002                 mov     2, %i0
F0005E54: b0102001                 mov     1, %i0
F0005E58: 81c7e008                 ret
F0005E5C: 81e80000                 restore
