F003D710: 9de3bf98                 save    %sp, -0x68, %sp
F003D714: 133c04ea                 sethi   %hi(_rlock_awaken_count), %o1
F003D718: d0026250                 ld      [%o1+%lo(_rlock_awaken_count)], %o0
F003D71C: 80a62000                 cmp     %i0, 0
F003D720: 90022001                 inc     %o0
F003D724: 02800004                 be      locret_F003D734
F003D728: d0226250                 st      %o0, [%o1+%lo(_rlock_awaken_count)]
F003D72C: 7fff55af                 call    _wakeup
F003D730: 90100018                 mov     %i0, %o0
F003D734: 81c7e008                 ret
F003D738: 81e80000                 restore
