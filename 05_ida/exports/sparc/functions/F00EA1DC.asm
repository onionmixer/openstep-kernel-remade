F00EA1DC: 9de3bf98                 save    %sp, -0x68, %sp
F00EA1E0: 80a62001                 cmp     %i0, 1
F00EA1E4: 28800005                 bleu,a  locret_F00EA1F8
F00EA1E8: b0102000                 mov     0, %i0
F00EA1EC: 7ffffffc                 call    sub_F00EA1DC
F00EA1F0: 91362001                 srl     %i0, 1, %o0
F00EA1F4: b0022001                 add     %o0, 1, %i0
F00EA1F8: 81c7e008                 ret
F00EA1FC: 81e80000                 restore
