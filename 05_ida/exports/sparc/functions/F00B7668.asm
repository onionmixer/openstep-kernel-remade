F00B7668: 9de3bf98                 save    %sp, -0x68, %sp
F00B766C: 90100018                 mov     %i0, %o0
F00B7670: 92102003                 mov     3, %o1
F00B7674: d6166008                 lduh    [%i1+8], %o3
F00B7678: 153c047a                 sethi   %hi(aCurrentCommand), %o2! "Current command timeout for Target %d L"...
F00B767C: d80e600a                 ldub    [%i1+0xA], %o4
F00B7680: 4000015b                 call    _esplog
F00B7684: 9412a358                 bset    %lo(aCurrentCommand), %o2! "Current command timeout for Target %d L"...
F00B7688: 90100018                 mov     %i0, %o0
F00B768C: 4000000b                 call    _esp_sync_backoff
F00B7690: 92100019                 mov     %i1, %o1
F00B7694: 4000006a                 call    _esp_abort_allcmds
F00B7698: 90100018                 mov     %i0, %o0
F00B769C: 80a22005                 cmp     %o0, 5
F00B76A0: 12800004                 bne     locret_F00B76B0
F00B76A4: 90100018                 mov     %i0, %o0
F00B76A8: 7ffff393                 call    _esp_ustart
F00B76AC: 92102000                 mov     0, %o1
F00B76B0: 81c7e008                 ret
F00B76B4: 81e80000                 restore
