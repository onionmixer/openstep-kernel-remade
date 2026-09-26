F00B780C: 9de3bf98                 save    %sp, -0x68, %sp
F00B7810: d00e2041                 ldub    [%i0+0x41], %o0
F00B7814: 80a22000                 cmp     %o0, 0
F00B7818: 12800004                 bne     loc_F00B7828
F00B781C: 01000000                 nop
F00B7820: 10800005                 ba      locret_F00B7834
F00B7824: b0103fff                 mov     -1, %i0
F00B7828: 40000005                 call    _esp_abort_allcmds
F00B782C: 90100018                 mov     %i0, %o0
F00B7830: b0100008                 mov     %o0, %i0
F00B7834: 81c7e008                 ret
F00B7838: 81e80000                 restore
