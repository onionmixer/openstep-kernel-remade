04040B40: 4856                     pea     (a6)
04040B42: 2c4f                     movea.l sp,a6
04040B44: 2039040c21d8             move.l  (_ipc_port_timestamp_data).l,d0
04040B4A: 52b9040c21d8             addq.l  #1,(_ipc_port_timestamp_data).l
04040B50: 4e5e                     unlk    a6
04040B52: 4e75                     rts
