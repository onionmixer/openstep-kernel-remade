F00EE32C: 9de3bf98                 save    %sp, -0x68, %sp
F00EE330: 80a62001                 cmp     %i0, 1
F00EE334: 28800005                 bleu,a  locret_F00EE348
F00EE338: b0102000                 mov     0, %i0
F00EE33C: 7ffffffc                 call    sub_F00EE32C
F00EE340: 91362001                 srl     %i0, 1, %o0
F00EE344: b0022001                 add     %o0, 1, %i0
F00EE348: 81c7e008                 ret
F00EE34C: 81e80000                 restore
