F0037218: 9de3bf98                 save    %sp, -0x68, %sp
F003721C: 073c04e9                 sethi   %hi(_tcp_iss), %g3
F0037220: 84102001                 mov     1, %g2
F0037224: c420e398                 st      %g2, [%g3+%lo(_tcp_iss)]
F0037228: 073c04d98410e340         set     _tcb, %g2
F0037230: c420a004                 st      %g2, [%g2+4]
F0037234: c420e340                 st      %g2, [%g3+%lo(dword_F013A740)]
F0037238: 81c7e008                 ret
F003723C: 81e80000                 restore
