F00C0F34: 9de3bf98                 save    %sp, -0x68, %sp
F00C0F38: 073c0483                 sethi   %hi(_kbdwriteenable), %g3
F00C0F3C: 84102001                 mov     1, %g2
F00C0F40: c420e284                 st      %g2, [%g3+%lo(_kbdwriteenable)]
F00C0F44: 81c7e008                 ret
F00C0F48: 81e80000                 restore
