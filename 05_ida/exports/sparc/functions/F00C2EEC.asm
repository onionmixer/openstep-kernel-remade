F00C2EEC: 9de3bf98                 save    %sp, -0x68, %sp
F00C2EF0: 073c0485                 sethi   %hi(_ResetDebug), %g3
F00C2EF4: 84102001                 mov     1, %g2
F00C2EF8: c420e048                 st      %g2, [%g3+%lo(_ResetDebug)]
F00C2EFC: 81c7e008                 ret
F00C2F00: 81e80000                 restore
