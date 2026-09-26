F00B060C: 9de3bf98                 save    %sp, -0x68, %sp
F00B0610: 40000361                 call    _idprom
F00B0614: 01000000                 nop
F00B0618: 40000008                 call    _sbus_config
F00B061C: 01000000                 nop
F00B0620: 400003b1                 call    _pseudoconfig
F00B0624: 01000000                 nop
F00B0628: 40000579                 call    _cninit
F00B062C: 01000000                 nop
F00B0630: 81c7e008                 ret
F00B0634: 81e80000                 restore
