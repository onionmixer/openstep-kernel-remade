F0093B6C: 9de3bf98                 save    %sp, -0x68, %sp
F0093B70: e807a05c                 ld      [%fp+arg_5C], %l4
F0093B74: e407a060                 ld      [%fp+arg_60], %l2
F0093B78: e207a064                 ld      [%fp+arg_64], %l1
F0093B7C: ec07a068                 ld      [%fp+arg_68], %l6
F0093B80: 273c0449                 sethi   %hi(_panel_req_port), %l3
F0093B84: d004e114                 ld      [%l3+%lo(_panel_req_port)], %o0
F0093B88: 80a22000                 cmp     %o0, 0
F0093B8C: 12800051                 bne     loc_F0093CD0
F0093B90: ea07a06c                 ld      [%fp+arg_6C], %l5
F0093B94: 80a72001                 cmp     %i4, 1
F0093B98: 2280000f                 be,a    loc_F0093BD4
F0093B9C: 113c0449                 sethi   -0xFEEDC00, %o0
F0093BA0: 14800007                 bg      loc_F0093BBC
F0093BA4: 80a72002                 cmp     %i4, 2
F0093BA8: 80a72000                 cmp     %i4, 0
F0093BAC: 02800008                 be      loc_F0093BCC
F0093BB0: 113c0449                 sethi   -0xFEEDC00, %o0
F0093BB4: 1080000c                 ba      loc_F0093BE4
F0093BB8: 113c0449                 sethi   -0xFEEDC00, %o0
F0093BBC: 02800008                 be      loc_F0093BDC
F0093BC0: 113c0449                 sethi   -0xFEEDC00, %o0
F0093BC4: 10800008                 ba      loc_F0093BE4
F0093BC8: 113c0449                 sethi   -0xFEEDC00, %o0
F0093BCC: 10800007                 ba      loc_F0093BE8
F0093BD0: 94122250                 or      %o0, 0x250, %o2
F0093BD4: 10800005                 ba      loc_F0093BE8
F0093BD8: 94122258                 or      %o0, 0x258, %o2
F0093BDC: 10800003                 ba      loc_F0093BE8
F0093BE0: 94122260                 or      %o0, 0x260, %o2
F0093BE4: 94122268                 or      %o0, 0x268, %o2
F0093BE8: 80a66006                 cmp     %i1, 6! switch 7 cases
F0093BEC: 18800033                 bgu     def_F0093C00! jumptable F0093C00 default case
F0093BF0: 113c024f                 sethi   %hi(jpt_F0093C00), %o0
F0093BF4: 90122008                 bset    %lo(jpt_F0093C00), %o0
F0093BF8: 932e6002                 sll     %i1, 2, %o1
F0093BFC: d0024008                 ld      [%o1+%o0], %o0
F0093C00: 81c20000                 jmp     %o0! switch jump
F0093C04: 01000000                 nop
F0093C24: 113c044990122270         set     aPleaseInsertSD, %o0! jumptable F0093C00 case 0
F0093C2C: 9210000a                 mov     %o2, %o1
F0093C30: 1080000e                 ba      loc_F0093C68
F0093C34: 9410001b                 mov     %i3, %o2
F0093C38: 113c0449                 sethi   %hi(aPleaseInsertSD_0), %o0! jumptable F0093C00 case 1
F0093C3C: 10800009                 ba      loc_F0093C60
F0093C40: 90122298                 bset    %lo(aPleaseInsertSD_0), %o0! "Please Insert %s Disk '%s' in Drive %d"...
F0093C44: 113c0449901222c0         set     aWrongDiskPleas, %o0! jumptable F0093C00 case 2
F0093C4C: 9210000a                 mov     %o2, %o1
F0093C50: 10800006                 ba      loc_F0093C68
F0093C54: 9410001b                 mov     %i3, %o2
F0093C58: 113c0449901222f8         set     aWrongDiskPleas_0, %o0! jumptable F0093C00 case 3
F0093C60: 9210000a                 mov     %o2, %o1
F0093C64: 94100012                 mov     %l2, %o2
F0093C68: 7ffe027c                 call    _printf
F0093C6C: 9610001d                 mov     %i5, %o3
F0093C70: 10800063                 ba      locret_F0093DFC
F0093C74: b0102000                 mov     0, %i0
F0093C78: 113c0449                 sethi   %hi(aSwapDeviceFull), %o0! jumptable F0093C00 case 4
F0093C7C: 7ffe0277                 call    _printf
F0093C80: 90122330                 bset    %lo(aSwapDeviceFull), %o0! "***Swap Device Full***\n"
F0093C84: 1080005e                 ba      locret_F0093DFC
F0093C88: b0102000                 mov     0, %i0
F0093C8C: 113c044990122348         set     aFileSystemSFul, %o0! jumptable F0093C00 case 5
F0093C94: 1080000c                 ba      loc_F0093CC4
F0093C98: 92100012                 mov     %l2, %o1
F0093C9C: 113c044990122368         set     aPleaseEjectSDi, %o0! jumptable F0093C00 case 6
F0093CA4: 9210000a                 mov     %o2, %o1
F0093CA8: 7ffe026c                 call    _printf
F0093CAC: 9410001d                 mov     %i5, %o2! __n
F0093CB0: 10800053                 ba      locret_F0093DFC
F0093CB4: b0102000                 mov     0, %i0
F0093CB8: 113c044990122388         set     aVolPanelReques, %o0! jumptable F0093C00 default case
F0093CC0: 92100019                 mov     %i1, %o1
F0093CC4: 7ffe0265                 call    _printf
F0093CC8: b0102000                 mov     0, %i0
F0093CCC: 3080004c                 ba,a    locret_F0093DFC
F0093CD0: 7fff50e8                 call    _kalloc
F0093CD4: 9010208c                 mov     0x8C, %o0! __dst
F0093CD8: a0100008                 mov     %o0, %l0
F0093CDC: 133c0449921261a4         set     unk_F01125A4, %o1! __src
F0093CE4: 7ffdcd6f                 call    _memcpy
F0093CE8: 9410208c                 mov     0x8C, %o2
F0093CEC: f224201c                 st      %i1, [%l0+0x1C]
F0093CF0: f4242020                 st      %i2, [%l0+0x20]
F0093CF4: f6242028                 st      %i3, [%l0+0x28]
F0093CF8: f824202c                 st      %i4, [%l0+0x2C]
F0093CFC: fa242030                 st      %i5, [%l0+0x30]
F0093D00: e8242034                 st      %l4, [%l0+0x34]
F0093D04: 113c0449                 sethi   %hi(dword_F0112518), %o0
F0093D08: d2022118                 ld      [%o0+%lo(dword_F0112518)], %o1
F0093D0C: 153c04c4                 sethi   %hi(dword_F0131260), %o2
F0093D10: d602a260                 ld      [%o2+%lo(dword_F0131260)], %o3
F0093D14: 90100012                 mov     %l2, %o0! __s
F0093D18: d224200c                 st      %o1, [%l0+0xC]
F0093D1C: d204e114                 ld      [%l3+0x114], %o1
F0093D20: d6242024                 st      %o3, [%l0+0x24]
F0093D24: d2242010                 st      %o1, [%l0+0x10]
F0093D28: 9202e001                 add     %o3, 1, %o1! __src
F0093D2C: 7ffdcdc3                 call    _strlen
F0093D30: d222a260                 st      %o1, [%o2+%lo(dword_F0131260)]
F0093D34: 80a22027                 cmp     %o0, 0x27 ! '''
F0093D38: 38800002                 bgu,a   loc_F0093D40
F0093D3C: c02ca027                 clrb    [%l2+0x27]
F0093D40: 7ffdcdbe                 call    _strlen
F0093D44: 90100011                 mov     %l1, %o0
F0093D48: 80a22027                 cmp     %o0, 0x27 ! '''
F0093D4C: 38800002                 bgu,a   loc_F0093D54
F0093D50: c02c6027                 clrb    [%l1+0x27]
F0093D54: 9004203c                 add     %l0, 0x3C, %o0 ! '<'! __dst
F0093D58: 7ffdcdf4                 call    _strcpy
F0093D5C: 92100012                 mov     %l2, %o1! __src
F0093D60: 90042064                 add     %l0, 0x64, %o0 ! 'd'! __dst
F0093D64: 7ffdcdf1                 call    _strcpy
F0093D68: 92100011                 mov     %l1, %o1
F0093D6C: 90100010                 mov     %l0, %o0
F0093D70: 92102001                 mov     1, %o1
F0093D74: 7fff47ae                 call    _msg_send_from_kernel
F0093D78: 94102000                 mov     0, %o2
F0093D7C: 80a22000                 cmp     %o0, 0
F0093D80: 22800004                 be,a    loc_F0093D90
F0093D84: d0042024                 ld      [%l0+0x24], %o0
F0093D88: 1080001d                 ba      locret_F0093DFC
F0093D8C: b0100008                 mov     %o0, %i0
F0093D90: 80a6a000                 cmp     %i2, 0
F0093D94: 02800019                 be      loc_F0093DF8
F0093D98: d0254000                 st      %o0, [%l5]
F0093D9C: 7fff50b5                 call    _kalloc
F0093DA0: 90102014                 mov     0x14, %o0
F0093DA4: 94920000                 orcc    %o0, %g0, %o2
F0093DA8: 32800004                 bne,a   loc_F0093DB8
F0093DAC: d0042024                 ld      [%l0+0x24], %o0
F0093DB0: 10800013                 ba      locret_F0093DFC
F0093DB4: b0102006                 mov     6, %i0
F0093DB8: d022a008                 st      %o0, [%o2+8]
F0093DBC: f022a00c                 st      %i0, [%o2+0xC]
F0093DC0: ec22a010                 st      %l6, [%o2+0x10]
F0093DC4: 113c0449                 sethi   %hi(off_F011252C), %o0
F0093DC8: d202212c                 ld      [%o0+%lo(off_F011252C)], %o1
F0093DCC: 9612212c                 or      %o0, %lo(off_F011252C), %o3
F0093DD0: 9002fffc                 add     %o3, -4, %o0
F0093DD4: 80a24008                 cmp     %o1, %o0
F0093DD8: 32800003                 bne,a   loc_F0093DE4
F0093DDC: d4224000                 st      %o2, [%o1]
F0093DE0: d422fffc                 st      %o2, [%o3-4]
F0093DE4: d222a004                 st      %o1, [%o2+4]
F0093DE8: 113c044990122128         set     off_F0112528, %o0
F0093DF0: d0228000                 st      %o0, [%o2]
F0093DF4: d4222004                 st      %o2, [%o0+4]
F0093DF8: b0102000                 mov     0, %i0
F0093DFC: 81c7e008                 ret
F0093E00: 81e80000                 restore
