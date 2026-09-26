F00204C0: 9de3bf98                 save    %sp, -0x68, %sp
F00204C4: 050000338410a0cc         set     0xCCCC, %g2
F00204CC: 80a64002                 cmp     %i1, %g2
F00204D0: 28800004                 bleu,a  loc_F00204E0
F00204D4: f2362002                 sth     %i1, [%i0+2]
F00204D8: 1080000a                 ba      locret_F0020500
F00204DC: b0102000                 mov     0, %i0
F00204E0: b32e6001                 sll     %i1, 1, %i1
F00204E4: 0500003f8410a3ff         set     0xFFFF, %g2
F00204EC: 80a64002                 cmp     %i1, %g2
F00204F0: 34800002                 bg,a    loc_F00204F8
F00204F4: b2100002                 mov     %g2, %i1
F00204F8: f2362006                 sth     %i1, [%i0+6]
F00204FC: b0102001                 mov     1, %i0
F0020500: 81c7e008                 ret
F0020504: 81e80000                 restore
