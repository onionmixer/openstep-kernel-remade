F0070C98: 9de3bf98                 save    %sp, -0x68, %sp
F0070C9C: 113c01c390122014         set     _thread_timeout, %o0
F0070CA4: d0262140                 st      %o0, [%i0+0x140]
F0070CA8: f0262144                 st      %i0, [%i0+0x144]
F0070CAC: 7fffe341                 call    _init_timeout_element
F0070CB0: 90062118                 add     %i0, 0x118, %o0
F0070CB4: 113c01ca901222e4         set     _thread_depress_timeout, %o0
F0070CBC: d0262178                 st      %o0, [%i0+0x178]
F0070CC0: f026217c                 st      %i0, [%i0+0x17C]
F0070CC4: 7fffe33b                 call    _init_timeout_element
F0070CC8: 90062150                 add     %i0, 0x150, %o0
F0070CCC: 81c7e008                 ret
F0070CD0: 81e80000                 restore
