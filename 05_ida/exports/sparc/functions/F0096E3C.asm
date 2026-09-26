F0096E3C: 90100000                 clr     %o0
F0096E40: 033c041882106000         set     _kernel_stack, %g1
F0096E48: 80a38001                 cmp     %sp, %g1
F0096E4C: 28800002                 bleu,a  locret_F0096E54
F0096E50: 90102001                 mov     1, %o0
F0096E54: 81c3e008                 retl
F0096E58: 01000000                 nop
