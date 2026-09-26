F0086CE8: 9de3bf98                 save    %sp, -0x68, %sp
F0086CEC: 4000019b                 call    _vm_object_lookup
F0086CF0: 90100018                 mov     %i0, %o0
F0086CF4: 80a22000                 cmp     %o0, 0
F0086CF8: 02800004                 be      locret_F0086D08
F0086CFC: 01000000                 nop
F0086D00: 7ffffeee                 call    _vm_object_deallocate
F0086D04: 01000000                 nop
F0086D08: 81c7e008                 ret
F0086D0C: 81e80000                 restore
