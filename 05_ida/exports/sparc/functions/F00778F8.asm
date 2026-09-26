F00778F8: 9de3bf98                 save    %sp, -0x68, %sp
F00778FC: 113c04f2a4122340         set     _kernel_timer, %l2
F0077904: a2102000                 mov     0, %l1
F0077908: 113c04f2a6122338         set     _current_timer, %l3
F0077910: a0102000                 mov     0, %l0
F0077914: 4000000a                 call    _timer_init
F0077918: 90100012                 mov     %l2, %o0
F007791C: c0240013                 clr     [%l0+%l3]
F0077920: a0042004                 inc     4, %l0
F0077924: a2046001                 inc     %l1
F0077928: 80a46000                 cmp     %l1, 0
F007792C: 04bffffa                 ble     loc_F0077914
F0077930: a404a010                 inc     0x10, %l2
F0077934: 81c7e008                 ret
F0077938: 81e80000                 restore
