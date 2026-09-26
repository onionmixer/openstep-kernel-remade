F00ED010: 9de3bf98                 save    %sp, -0x68, %sp
F00ED014: 80a62001                 cmp     %i0, 1
F00ED018: 28800005                 bleu,a  locret_F00ED02C
F00ED01C: b0102000                 mov     0, %i0
F00ED020: 7ffffffc                 call    sub_F00ED010
F00ED024: 91362001                 srl     %i0, 1, %o0
F00ED028: b0022001                 add     %o0, 1, %i0
F00ED02C: 81c7e008                 ret
F00ED030: 81e80000                 restore
