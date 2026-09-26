F00C96A0: 9de3bf78                 save    %sp, -0x88, %sp
F00C96A4: 11000004                 sethi   0x1000, %o0! id
F00C96A8: d206210c                 ld      [%i0+0x10C], %o1
F00C96AC: 80a26000                 cmp     %o1, 0
F00C96B0: 12800017                 bne     loc_F00C970C
F00C96B4: a0122100                 or      %o0, 0x100, %l0
F00C96B8: 10800034                 ba      locret_F00C9788
F00C96BC: b0103d21                 mov     -0x2DF, %i0
F00C96C0: 10800032                 ba      locret_F00C9788
F00C96C4: b0103d1f                 mov     -0x2E1, %i0
F00C96C8: 133c0504                 sethi   %hi(paName), %o1
F00C96CC: 213c03eb                 sethi   %hi(aSSWaitforinter), %l0! "%s: %s waitForInterrupt: msg_receive re"...
F00C96D0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C96D4: 4000a067                 call    _objc_msgSend
F00C96D8: a01423f8                 bset    %lo(aSSWaitforinter), %l0! "%s: %s waitForInterrupt: msg_receive re"...
F00C96DC: 133c0506                 sethi   %hi(paDevicekind_0), %o1
F00C96E0: a2100008                 mov     %o0, %l1
F00C96E4: d20261d0                 ld      [%o1+%lo(paDevicekind_0)], %o1! SEL
F00C96E8: 4000a062                 call    _objc_msgSend
F00C96EC: 90100018                 mov     %i0, %o0
F00C96F0: 94100008                 mov     %o0, %o2
F00C96F4: 90100010                 mov     %l0, %o0
F00C96F8: 92100011                 mov     %l1, %o1
F00C96FC: 7ffff27e                 call    _IOLog
F00C9700: 96100012                 mov     %l2, %o3
F00C9704: 10800021                 ba      locret_F00C9788
F00C9708: b0103d41                 mov     -0x2BF, %i0
F00C970C: a2102018                 mov     0x18, %l1
F00C9710: e227bfdc                 st      %l1, [%fp+var_24]
F00C9714: 9007bfd8                 add     %fp, var_28, %o0
F00C9718: 92100010                 mov     %l0, %o1
F00C971C: d606210c                 ld      [%i0+0x10C], %o3
F00C9720: 94102000                 mov     0, %o2
F00C9724: 7ffe71ce                 call    _msg_receive
F00C9728: d627bfe4                 st      %o3, [%fp+var_1C]
F00C972C: a4100008                 mov     %o0, %l2
F00C9730: 80a4bf34                 cmp     %l2, -0xCC
F00C9734: 02bfffe3                 be      loc_F00C96C0
F00C9738: 80a4a000                 cmp     %l2, 0
F00C973C: 02800004                 be      loc_F00C974C
F00C9740: 80a4bf35                 cmp     %l2, -0xCB
F00C9744: 12bfffe1                 bne     loc_F00C96C8
F00C9748: 90100018                 mov     %i0, %o0
F00C974C: 808c2100                 btst    0x100, %l0
F00C9750: 02800008                 be      loc_F00C9770
F00C9754: 80a4bf35                 cmp     %l2, -0xCB
F00C9758: 12800004                 bne     loc_F00C9768
F00C975C: 01000000                 nop
F00C9760: 10800004                 ba      loc_F00C9770
F00C9764: 21000004                 sethi   0x1000, %l0
F00C9768: 7ffea3d6                 call    _thread_block
F00C976C: 01000000                 nop
F00C9770: 80a4a000                 cmp     %l2, 0
F00C9774: 32bfffe8                 bne,a   loc_F00C9714
F00C9778: e227bfdc                 st      %l1, [%fp+var_24]
F00C977C: d007bfec                 ld      [%fp+var_14], %o0
F00C9780: b0102000                 mov     0, %i0
F00C9784: d0268000                 st      %o0, [%i2]
F00C9788: 81c7e008                 ret
F00C978C: 81e80000                 restore
