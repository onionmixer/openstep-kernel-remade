F005A0D8: 9de3bf98                 save    %sp, -0x68, %sp
F005A0DC: 80a62010                 cmp     %i0, 0x10
F005A0E0: 22800009                 be,a    locret_F005A104
F005A0E4: b0102005                 mov     5, %i0
F005A0E8: 0a800004                 bcs     loc_F005A0F8
F005A0EC: 80a62012                 cmp     %i0, 0x12
F005A0F0: 08800005                 bleu    locret_F005A104
F005A0F4: b0102006                 mov     6, %i0
F005A0F8: 113c043d                 sethi   %hi(aIpcObjectCopyo), %o0! "ipc_object_copyout_type_compat: strange"...
F005A0FC: 7ffeec1d                 call    _panic
F005A100: 90122268                 bset    %lo(aIpcObjectCopyo), %o0! "ipc_object_copyout_type_compat: strange"...
F005A104: 81c7e008                 ret
F005A108: 81e80000                 restore
