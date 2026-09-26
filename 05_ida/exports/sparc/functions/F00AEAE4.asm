F00AEAE4: 9de3bf98                 save    %sp, -0x68, %sp
F00AEAE8: 90100018                 mov     %i0, %o0
F00AEAEC: 7ffffff6                 call    _fpu_set_exception
F00AEAF0: 92102004                 mov     4, %o1
F00AEAF4: c0264000                 clr     [%i1]
F00AEAF8: 111fffff901223ff         set     0x7FFFFFFF, %o0
F00AEB00: d026600c                 st      %o0, [%i1+0xC]
F00AEB04: 90103fff                 mov     -1, %o0
F00AEB08: d0266010                 st      %o0, [%i1+0x10]
F00AEB0C: d0266014                 st      %o0, [%i1+0x14]
F00AEB10: d0266018                 st      %o0, [%i1+0x18]
F00AEB14: 81c7e008                 ret
F00AEB18: 81e80000                 restore
