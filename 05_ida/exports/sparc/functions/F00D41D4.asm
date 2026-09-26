F00D41D4: 9de3bf90                 save    %sp, -0x70, %sp
F00D41D8: 80a6a000                 cmp     %i2, 0
F00D41DC: 16800004                 bge     loc_F00D41EC
F00D41E0: 80a6a040                 cmp     %i2, 0x40 ! '@'
F00D41E4: 10800004                 ba      loc_F00D41F4
F00D41E8: b4102000                 mov     0, %i2
F00D41EC: 34800002                 bg,a    loc_F00D41F4
F00D41F0: b4102040                 mov     0x40, %i2 ! '@'
F00D41F4: f42621c4                 st      %i2, [%i0+0x1C4]
F00D41F8: 81c7e008                 ret
F00D41FC: 81e80000                 restore
