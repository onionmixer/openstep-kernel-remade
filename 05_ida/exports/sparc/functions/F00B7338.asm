F00B7338: 9de3bf98                 save    %sp, -0x68, %sp
F00B733C: 153c047a                 sethi   %hi(aUnexpectedSele), %o2! "Unexpected Selection Attempt"
F00B7340: 90100018                 mov     %i0, %o0
F00B7344: 92102005                 mov     5, %o1
F00B7348: 40000229                 call    _esplog
F00B734C: 9412a338                 bset    %lo(aUnexpectedSele), %o2! "Unexpected Selection Attempt"
F00B7350: 81c7e008                 ret
F00B7354: 91e82008                 restore %g0, 8, %o0
