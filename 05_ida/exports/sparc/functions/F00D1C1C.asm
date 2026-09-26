F00D1C1C: 9de3bd98                 save    %sp, -0x268, %sp
F00D1C20: ac102001                 mov     1, %l6
F00D1C24: a6102200                 mov     0x200, %l3
F00D1C28: a207bdf8                 add     %fp, var_208, %l1
F00D1C2C: a8102000                 mov     0, %l4
F00D1C30: a4102000                 mov     0, %l2
F00D1C34: 2b3c0504                 sethi   -0xFEBF000, %l5
F00D1C38: 90100011                 mov     %l1, %o0
F00D1C3C: 13000004                 sethi   0x1000, %o1
F00D1C40: d6062148                 ld      [%i0+0x148], %o3
F00D1C44: 94102000                 mov     0, %o2
F00D1C48: d624600c                 st      %o3, [%l1+0xC]
F00D1C4C: 7ffe5084                 call    _msg_receive
F00D1C50: e6246004                 st      %l3, [%l1+4]
F00D1C54: a0100008                 mov     %o0, %l0
F00D1C58: 80a43f36                 cmp     %l0, -0xCA
F00D1C5C: 22800086                 be,a    loc_F00D1E74
F00D1C60: ac102000                 mov     0, %l6
F00D1C64: 14800007                 bg      loc_F00D1C80
F00D1C68: 80a42000                 cmp     %l0, 0
F00D1C6C: 80a43f34                 cmp     %l0, -0xCC
F00D1C70: 02800008                 be      loc_F00D1C90
F00D1C74: 80a4e200                 cmp     %l3, 0x200
F00D1C78: 1080000f                 ba      loc_F00D1CB4
F00D1C7C: d2056008                 ld      [%l5+8], %o1
F00D1C80: 1280000d                 bne     loc_F00D1CB4
F00D1C84: d2056008                 ld      [%l5+8], %o1
F00D1C88: 10800014                 ba      loc_F00D1CD8
F00D1C8C: d404600c                 ld      [%l1+0xC], %o2
F00D1C90: 08800004                 bleu    loc_F00D1CA0
F00D1C94: 90100011                 mov     %l1, %o0
F00D1C98: 7fffd0ab                 call    _IOFree
F00D1C9C: 92100013                 mov     %l3, %o1! SEL
F00D1CA0: e6046004                 ld      [%l1+4], %l3
F00D1CA4: 7fffd0a3                 call    _IOMalloc
F00D1CA8: 90100013                 mov     %l3, %o0! id
F00D1CAC: 10800072                 ba      loc_F00D1E74
F00D1CB0: a2100008                 mov     %o0, %l1
F00D1CB4: 40007eef                 call    _objc_msgSend
F00D1CB8: 90100018                 mov     %i0, %o0
F00D1CBC: 153c03ef                 sethi   %hi(aSErrorOnMsgRec), %o2! "%s: error on msg_receive (%d)\n"
F00D1CC0: 92100008                 mov     %o0, %o1
F00D1CC4: 9012a308                 or      %o2, %lo(aSErrorOnMsgRec), %o0! "%s: error on msg_receive (%d)\n"
F00D1CC8: 7fffd10b                 call    _IOLog
F00D1CCC: 94100010                 mov     %l0, %o2
F00D1CD0: 1080006a                 ba      loc_F00D1E78
F00D1CD4: 80a5a000                 cmp     %l6, 0
F00D1CD8: d006213c                 ld      [%i0+0x13C], %o0
F00D1CDC: 80a28008                 cmp     %o2, %o0
F00D1CE0: 32800012                 bne,a   loc_F00D1D28
F00D1CE4: d0046014                 ld      [%l1+0x14], %o0
F00D1CE8: d204601c                 ld      [%l1+0x1C], %o1
F00D1CEC: d0062144                 ld      [%i0+0x144], %o0
F00D1CF0: 80a24008                 cmp     %o1, %o0
F00D1CF4: 12800061                 bne     loc_F00D1E78
F00D1CF8: 80a5a000                 cmp     %l6, 0
F00D1CFC: 80a26000                 cmp     %o1, 0
F00D1D00: 0280005e                 be      loc_F00D1E78
F00D1D04: 80a5a000                 cmp     %l6, 0
F00D1D08: 113c0505                 sethi   %hi(paEvcloseToken), %o0! id
F00D1D0C: d2022358                 ld      [%o0+%lo(paEvcloseToken)], %o1! SEL
F00D1D10: d4062134                 ld      [%i0+0x134], %o2
F00D1D14: d6062114                 ld      [%i0+0x114], %o3
F00D1D18: 40007ed6                 call    _objc_msgSend
F00D1D1C: 90100018                 mov     %i0, %o0
F00D1D20: 10800056                 ba      loc_F00D1E78
F00D1D24: 80a5a000                 cmp     %l6, 0
F00D1D28: 80a22001                 cmp     %o0, 1
F00D1D2C: 1280000d                 bne     loc_F00D1D60
F00D1D30: 92102000                 mov     0, %o1
F00D1D34: d0062134                 ld      [%i0+0x134], %o0
F00D1D38: 80a28008                 cmp     %o2, %o0
F00D1D3C: 12800015                 bne     loc_F00D1D90
F00D1D40: 80a26000                 cmp     %o1, 0
F00D1D44: 90100018                 mov     %i0, %o0! id
F00D1D48: 133c0505                 sethi   %hi(paIoophandler), %o1
F00D1D4C: d20262cc                 ld      [%o1+%lo(paIoophandler)], %o1! SEL
F00D1D50: 40007ec8                 call    _objc_msgSend
F00D1D54: 9404601c                 add     %l1, 0x1C, %o2
F00D1D58: 1080000d                 ba      loc_F00D1D8C
F00D1D5C: 92102001                 mov     1, %o1
F00D1D60: 80a4a000                 cmp     %l2, 0
F00D1D64: 12800007                 bne     loc_F00D1D80
F00D1D68: 90100011                 mov     %l1, %o0
F00D1D6C: 29000005                 sethi   0x1400, %l4
F00D1D70: 7fffd070                 call    _IOMalloc
F00D1D74: 90100014                 mov     %l4, %o0
F00D1D78: a4100008                 mov     %o0, %l2
F00D1D7C: 90100011                 mov     %l1, %o0
F00D1D80: 400043fb                 call    _Event_server
F00D1D84: 92100012                 mov     %l2, %o1
F00D1D88: 92100008                 mov     %o0, %o1
F00D1D8C: 80a26000                 cmp     %o1, 0
F00D1D90: 3280000a                 bne,a   loc_F00D1DB8
F00D1D94: d0046010                 ld      [%l1+0x10], %o0! id
F00D1D98: d2056008                 ld      [%l5+8], %o1! SEL
F00D1D9C: 40007eb5                 call    _objc_msgSend
F00D1DA0: 90100018                 mov     %i0, %o0
F00D1DA4: 153c03ef                 sethi   %hi(aSInvalidMessag), %o2! "%s: invalid message ID %d\n"
F00D1DA8: 92100008                 mov     %o0, %o1
F00D1DAC: 9012a328                 or      %o2, %lo(aSInvalidMessag), %o0! "%s: invalid message ID %d\n"
F00D1DB0: 10800020                 ba      loc_F00D1E30
F00D1DB4: d4046014                 ld      [%l1+0x14], %o2
F00D1DB8: 80a22000                 cmp     %o0, 0
F00D1DBC: 0280001f                 be      loc_F00D1E38
F00D1DC0: 80a4a000                 cmp     %l2, 0
F00D1DC4: 02800024                 be      loc_F00D1E54
F00D1DC8: 90100012                 mov     %l2, %o0
F00D1DCC: d004a004                 ld      [%l2+4], %o0! id
F00D1DD0: 80a20014                 cmp     %o0, %l4
F00D1DD4: 0880000a                 bleu    loc_F00D1DFC
F00D1DD8: d2056008                 ld      [%l5+8], %o1! SEL
F00D1DDC: 40007ea5                 call    _objc_msgSend
F00D1DE0: 90100018                 mov     %i0, %o0
F00D1DE4: 153c03ef                 sethi   %hi(aSReplyMsgOverf), %o2! "%s: reply msg overflow (%d > %d)\n"
F00D1DE8: 92100008                 mov     %o0, %o1
F00D1DEC: 9012a348                 or      %o2, %lo(aSReplyMsgOverf), %o0! "%s: reply msg overflow (%d > %d)\n"
F00D1DF0: d404a004                 ld      [%l2+4], %o2
F00D1DF4: 7fffd0c0                 call    _IOLog
F00D1DF8: 96100014                 mov     %l4, %o3
F00D1DFC: 90100012                 mov     %l2, %o0! id
F00D1E00: 92102000                 mov     0, %o1
F00D1E04: 7ffe4fb4                 call    _msg_send
F00D1E08: 94102000                 mov     0, %o2
F00D1E0C: a0920000                 orcc    %o0, %g0, %l0
F00D1E10: 0280000a                 be      loc_F00D1E38
F00D1E14: d2056008                 ld      [%l5+8], %o1! SEL
F00D1E18: 40007e96                 call    _objc_msgSend
F00D1E1C: 90100018                 mov     %i0, %o0
F00D1E20: 153c03ef                 sethi   %hi(aSErrorOnMsgSen), %o2! "%s: error on msg_send (%d)\n"
F00D1E24: 92100008                 mov     %o0, %o1
F00D1E28: 9012a370                 or      %o2, %lo(aSErrorOnMsgSen), %o0! "%s: error on msg_send (%d)\n"
F00D1E2C: 94100010                 mov     %l0, %o2
F00D1E30: 7fffd0b1                 call    _IOLog
F00D1E34: 01000000                 nop
F00D1E38: 80a4a000                 cmp     %l2, 0
F00D1E3C: 02800006                 be      loc_F00D1E54
F00D1E40: 90100012                 mov     %l2, %o0
F00D1E44: 7fffd040                 call    _IOFree
F00D1E48: 92100014                 mov     %l4, %o1
F00D1E4C: a4102000                 mov     0, %l2
F00D1E50: a8102000                 mov     0, %l4
F00D1E54: 80a4e200                 cmp     %l3, 0x200
F00D1E58: 08800008                 bleu    loc_F00D1E78
F00D1E5C: 80a5a000                 cmp     %l6, 0
F00D1E60: 90100011                 mov     %l1, %o0
F00D1E64: 7fffd038                 call    _IOFree
F00D1E68: 92100013                 mov     %l3, %o1
F00D1E6C: a6102200                 mov     0x200, %l3
F00D1E70: a207bdf8                 add     %fp, var_208, %l1
F00D1E74: 80a5a000                 cmp     %l6, 0
F00D1E78: 12bfff71                 bne     loc_F00D1C3C
F00D1E7C: 90100011                 mov     %l1, %o0
F00D1E80: 7fffe0e7                 call    _IOExitThread
F00D1E84: 01000000                 nop
F00D1E88: 81c7e008                 ret
F00D1E8C: 81e80000                 restore
