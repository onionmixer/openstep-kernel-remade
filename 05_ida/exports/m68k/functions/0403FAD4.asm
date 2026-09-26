0403FAD4: 4856                     pea     (a6)
0403FAD6: 2c4f                     movea.l sp,a6
0403FAD8: 4879040c2264             pea     (_ipc_notify_port_deleted_template).l
0403FADE: 61fffffffe06             bsr.l   _ipc_notify_init_port_deleted
0403FAE4: 4879040c2224             pea     (_ipc_notify_msg_accepted_template).l
0403FAEA: 61fffffffe54             bsr.l   _ipc_notify_init_msg_accepted
0403FAF0: 4879040c2284             pea     (_ipc_notify_port_destroyed_template).l
0403FAF6: 61fffffffea2             bsr.l   _ipc_notify_init_port_destroyed
0403FAFC: 4879040c2244             pea     (_ipc_notify_no_senders_template).l
0403FB02: 61fffffffef2             bsr.l   _ipc_notify_init_no_senders
0403FB08: 4879040c22a4             pea     (_ipc_notify_send_once_template).l
0403FB0E: 61ffffffff40             bsr.l   _ipc_notify_init_send_once
0403FB14: 4879040c2204             pea     (_ipc_notify_dead_name_template).l
0403FB1A: 61ffffffff5e             bsr.l   _ipc_notify_init_dead_name
0403FB20: 4e5e                     unlk    a6
0403FB22: 4e75                     rts
