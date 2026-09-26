F0058F98: 9de3bf98                 save    %sp, -0x68, %sp
F0058F9C: 113c04ef                 sethi   %hi(_ipc_notify_port_deleted_template), %o0
F0058FA0: 7fffff73                 call    _ipc_notify_init_port_deleted
F0058FA4: 901223d0                 bset    %lo(_ipc_notify_port_deleted_template), %o0
F0058FA8: 113c04ef                 sethi   %hi(_ipc_notify_msg_accepted_template), %o0
F0058FAC: 7fffff89                 call    _ipc_notify_init_msg_accepted
F0058FB0: 90122390                 bset    %lo(_ipc_notify_msg_accepted_template), %o0
F0058FB4: 113c04ef                 sethi   %hi(_ipc_notify_port_destroyed_template), %o0
F0058FB8: 7fffff9f                 call    _ipc_notify_init_port_destroyed
F0058FBC: 901223f0                 bset    %lo(_ipc_notify_port_destroyed_template), %o0
F0058FC0: 113c04ef                 sethi   %hi(_ipc_notify_no_senders_template), %o0
F0058FC4: 7fffffb6                 call    _ipc_notify_init_no_senders
F0058FC8: 901223b0                 bset    %lo(_ipc_notify_no_senders_template), %o0
F0058FCC: 113c04f0                 sethi   %hi(_ipc_notify_send_once_template), %o0
F0058FD0: 7fffffcc                 call    _ipc_notify_init_send_once
F0058FD4: 90122010                 bset    %lo(_ipc_notify_send_once_template), %o0
F0058FD8: 113c04ef                 sethi   %hi(_ipc_notify_dead_name_template), %o0
F0058FDC: 7fffffd6                 call    _ipc_notify_init_dead_name
F0058FE0: 90122370                 bset    %lo(_ipc_notify_dead_name_template), %o0
F0058FE4: 81c7e008                 ret
F0058FE8: 81e80000                 restore
