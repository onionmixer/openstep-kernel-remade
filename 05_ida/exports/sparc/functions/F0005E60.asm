F0005E60: 9de3bf98                 save    %sp, -0x68, %sp
F0005E64: 80a6001a                 cmp     %i0, %i2
F0005E68: 2a80000d                 bcs,a   locret_F0005E9C
F0005E6C: b0102000                 mov     0, %i0
F0005E70: 08800004                 bleu    loc_F0005E80
F0005E74: 80a6401b                 cmp     %i1, %i3
F0005E78: 10800009                 ba      locret_F0005E9C
F0005E7C: b0102002                 mov     2, %i0
F0005E80: 1a800004                 bcc     loc_F0005E90
F0005E84: 80a6401b                 cmp     %i1, %i3
F0005E88: 10800005                 ba      locret_F0005E9C
F0005E8C: b0102000                 mov     0, %i0
F0005E90: 18800003                 bgu     locret_F0005E9C
F0005E94: b0102002                 mov     2, %i0
F0005E98: b0102001                 mov     1, %i0
F0005E9C: 81c7e008                 ret
F0005EA0: 81e80000                 restore
