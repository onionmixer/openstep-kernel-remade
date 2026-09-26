F0047CC8: 9de3bf90                 save    %sp, -0x70, %sp
F0047CCC: f027a044                 st      %i0, [%fp+arg_44]
F0047CD0: f227a048                 st      %i1, [%fp+arg_48]
F0047CD4: f427a04c                 st      %i2, [%fp+arg_4C]
F0047CD8: 80a6a001                 cmp     %i2, 1
F0047CDC: 14800051                 bg      loc_F0047E20
F0047CE0: f627a050                 st      %i3, [%fp+arg_50]
F0047CE4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0047CE8: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F0047CEC: 40013c1a                 call    _setjmp
F0047CF0: 90022028                 inc     0x28, %o0 ! '('
F0047CF4: 80a22000                 cmp     %o0, 0
F0047CF8: 0280000c                 be      loc_F0047D28
F0047CFC: d007a044                 ld      [%fp+arg_44], %o0
F0047D00: f0022030                 ld      [%o0+0x30], %i0
F0047D04: 1300003f                 sethi   0xFC00, %o1
F0047D08: 90100018                 mov     %i0, %o0
F0047D0C: d4122040                 lduh    [%o0+0x40], %o2
F0047D10: 921263f7                 bset    0x3F7, %o1
F0047D14: 940a8009                 and     %o2, %o1, %o2
F0047D18: 7fff2c34                 call    _wakeup
F0047D1C: d4322040                 sth     %o2, [%o0+0x40]
F0047D20: 10800041                 ba      locret_F0047E24
F0047D24: b0102004                 mov     4, %i0
F0047D28: d407a044                 ld      [%fp+arg_44], %o2
F0047D2C: f002a030                 ld      [%o2+0x30], %i0
F0047D30: d2062064                 ld      [%i0+0x64], %o1
F0047D34: d0562042                 ldsh    [%i0+0x42], %o0
F0047D38: 92027fff                 inc     -1, %o1
F0047D3C: d2262064                 st      %o1, [%i0+0x64]
F0047D40: 7ffffe5a                 call    _stillopen
F0047D44: d202a028                 ld      [%o2+0x28], %o1
F0047D48: 80a22000                 cmp     %o0, 0
F0047D4C: 32800036                 bne,a   locret_F0047E24
F0047D50: b0102000                 mov     0, %i0
F0047D54: d007a044                 ld      [%fp+arg_44], %o0
F0047D58: d4162042                 lduh    [%i0+0x42], %o2
F0047D5C: d0022028                 ld      [%o0+0x28], %o0
F0047D60: 80a22004                 cmp     %o0, 4
F0047D64: 0280000e                 be      loc_F0047D9C
F0047D68: d437bff6                 sth     %o2, [%fp+var_A]
F0047D6C: 80a22004                 cmp     %o0, 4
F0047D70: 18800006                 bgu     loc_F0047D88
F0047D74: 80a22003                 cmp     %o0, 3
F0047D78: 02800014                 be      loc_F0047DC8
F0047D7C: 92103fff                 mov     -1, %o1
F0047D80: 10800029                 ba      locret_F0047E24
F0047D84: b0102000                 mov     0, %i0
F0047D88: 80a22008                 cmp     %o0, 8
F0047D8C: 02800023                 be      loc_F0047E18
F0047D90: 113c0439                 sethi   -0xFEF1C00, %o0
F0047D94: 10800024                 ba      locret_F0047E24
F0047D98: b0102000                 mov     0, %i0
F0047D9C: 912aa010                 sll     %o2, 16, %o0
F0047DA0: 97322018                 srl     %o0, 24, %o3
F0047DA4: 952ae001                 sll     %o3, 1, %o2
F0047DA8: 9402800b                 add     %o2, %o3, %o2
F0047DAC: 952aa002                 sll     %o2, 2, %o2
F0047DB0: 9422800b                 sub     %o2, %o3, %o2
F0047DB4: 952aa002                 sll     %o2, 2, %o2
F0047DB8: 173c04729612e1f0         set     _cdevsw, %o3
F0047DC0: 10800010                 ba      loc_F0047E00
F0047DC4: d207a048                 ld      [%fp+arg_48], %o1
F0047DC8: d006203c                 ld      [%i0+0x3C], %o0
F0047DCC: 7fff7542                 call    _bflush
F0047DD0: 94103fff                 mov     -1, %o2
F0047DD4: 7fff75ff                 call    _binval
F0047DD8: d006203c                 ld      [%i0+0x3C], %o0
F0047DDC: d017bff6                 lduh    [%fp+var_A], %o0
F0047DE0: d207a048                 ld      [%fp+arg_48], %o1
F0047DE4: 912a2010                 sll     %o0, 16, %o0
F0047DE8: 97322018                 srl     %o0, 24, %o3
F0047DEC: 952ae001                 sll     %o3, 1, %o2
F0047DF0: 9402800b                 add     %o2, %o3, %o2
F0047DF4: 952aa003                 sll     %o2, 3, %o2
F0047DF8: 173c04719612e3ac         set     _bdevsw, %o3
F0047E00: 9402800b                 add     %o2, %o3, %o2
F0047E04: d402a004                 ld      [%o2+4], %o2
F0047E08: 9fc28000                 call    %o2
F0047E0C: 913a2010                 sra     %o0, 16, %o0! char *
F0047E10: 10800005                 ba      locret_F0047E24
F0047E14: b0102000                 mov     0, %i0
F0047E18: 7fff3210                 call    _printf
F0047E1C: 90122078                 bset    0x78, %o0 ! 'x'
F0047E20: b0102000                 mov     0, %i0
F0047E24: 81c7e008                 ret
F0047E28: 81e80000                 restore
