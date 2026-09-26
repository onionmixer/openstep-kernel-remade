F0063140: 9de3bf98                 save    %sp, -0x68, %sp
F0063144: 90100018                 mov     %i0, %o0! task
F0063148: 92100019                 mov     %i1, %o1! old_name
F006314C: 7ffffc57                 call    _mach_port_rename
F0063150: 9410001a                 mov     %i2, %o2
F0063154: 80a22000                 cmp     %o0, 0
F0063158: 02800004                 be      locret_F0063168
F006315C: 80a2200d                 cmp     %o0, 0xD
F0063160: 32800002                 bne,a   locret_F0063168
F0063164: 90102004                 mov     4, %o0
F0063168: 81c7e008                 ret
F006316C: 91e80008                 restore %g0, %o0, %o0
