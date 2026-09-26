F0094744: 9de3bf98                 save    %sp, -0x68, %sp
F0094748: 4000de9b                 call    _en_reset
F009474C: 90102001                 mov     1, %o0
F0094750: 4000b9e7                 call    _debugger_le_init
F0094754: 01000000                 nop
F0094758: 40000424                 call    _vac_flushall
F009475C: 01000000                 nop
F0094760: 40000971                 call    _splx
F0094764: 90100018                 mov     %i0, %o0
F0094768: 81c7e008                 ret
F009476C: 81e80000                 restore
