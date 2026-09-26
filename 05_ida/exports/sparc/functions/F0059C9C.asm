F0059C9C: 9de3bf98                 save    %sp, -0x68, %sp
F0059CA0: 80a66011                 cmp     %i1, 0x11
F0059CA4: 0280000c                 be      loc_F0059CD4
F0059CA8: 90100018                 mov     %i0, %o0
F0059CAC: 80a66011                 cmp     %i1, 0x11
F0059CB0: 18800005                 bgu     loc_F0059CC4
F0059CB4: 80a66010                 cmp     %i1, 0x10
F0059CB8: 0280000b                 be      loc_F0059CE4
F0059CBC: 01000000                 nop
F0059CC0: 3080000b                 ba,a    locret_F0059CEC
F0059CC4: 80a66012                 cmp     %i1, 0x12
F0059CC8: 02800005                 be      loc_F0059CDC
F0059CCC: 01000000                 nop
F0059CD0: 30800007                 ba,a    locret_F0059CEC
F0059CD4: 40000512                 call    _ipc_port_release_send
F0059CD8: 9e03e010                 inc     0x10, %o7
F0059CDC: 7ffffd76                 call    _ipc_notify_send_once
F0059CE0: 9e03e008                 inc     8, %o7
F0059CE4: 40000576                 call    _ipc_port_release_receive
F0059CE8: 01000000                 nop
F0059CEC: 81c7e008                 ret
F0059CF0: 81e80000                 restore
