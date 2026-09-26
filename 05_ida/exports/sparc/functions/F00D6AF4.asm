F00D6AF4: 9de3bf90                 save    %sp, -0x70, %sp
F00D6AF8: 113c0505                 sethi   %hi(paAudiocommand_0), %o0
F00D6AFC: e00221f8                 ld      [%o0+%lo(paAudiocommand_0)], %l0
F00D6B00: 90100018                 mov     %i0, %o0! id
F00D6B04: 40006b5b                 call    _objc_msgSend
F00D6B08: 92100010                 mov     %l0, %o1
F00D6B0C: 133c0505                 sethi   %hi(paCommand), %o1! SEL
F00D6B10: 40006b58                 call    _objc_msgSend
F00D6B14: d20261f4                 ld      [%o1+%lo(paCommand)], %o1
F00D6B18: 92100008                 mov     %o0, %o1
F00D6B1C: 80a2601b                 cmp     %o1, 0x1B! switch 28 cases
F00D6B20: 188001b8                 bgu     def_F00D6B38! jumptable F00D6B38 default case
F00D6B24: a2102001                 mov     1, %l1
F00D6B28: 113c035a90122340         set     jpt_F00D6B38, %o0
F00D6B30: 932a6002                 sll     %o1, 2, %o1
F00D6B34: d0024008                 ld      [%o1+%o0], %o0
F00D6B38: 81c20000                 jmp     %o0! switch jump
F00D6B3C: 01000000                 nop
F00D6BB0: 113c0505                 sethi   %hi(paUpdateinputgai_0), %o0! jumptable F00D6B38 case 0
F00D6BB4: d20221f0                 ld      [%o0+%lo(paUpdateinputgai_0)], %o1! SEL
F00D6BB8: 40006b2e                 call    _objc_msgSend
F00D6BBC: 90100018                 mov     %i0, %o0
F00D6BC0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6BC4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6BC8: 40006b2a                 call    _objc_msgSend
F00D6BCC: 90100018                 mov     %i0, %o0
F00D6BD0: 133c0506                 sethi   %hi(paDone), %o1
F00D6BD4: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6BD8: 10800190                 ba      loc_F00D7218
F00D6BDC: 94100011                 mov     %l1, %o2
F00D6BE0: 113c0505                 sethi   %hi(paUpdateinputgai), %o0! jumptable F00D6B38 case 1
F00D6BE4: d20221ec                 ld      [%o0+%lo(paUpdateinputgai)], %o1! SEL
F00D6BE8: 40006b22                 call    _objc_msgSend
F00D6BEC: 90100018                 mov     %i0, %o0
F00D6BF0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6BF4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6BF8: 40006b1e                 call    _objc_msgSend
F00D6BFC: 90100018                 mov     %i0, %o0
F00D6C00: 133c0506                 sethi   %hi(paDone), %o1
F00D6C04: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6C08: 10800184                 ba      loc_F00D7218
F00D6C0C: 94100011                 mov     %l1, %o2
F00D6C10: 113c0505                 sethi   %hi(paUpdateoutputmu), %o0! jumptable F00D6B38 case 2
F00D6C14: d20221e8                 ld      [%o0+%lo(paUpdateoutputmu)], %o1! SEL
F00D6C18: 40006b16                 call    _objc_msgSend
F00D6C1C: 90100018                 mov     %i0, %o0
F00D6C20: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6C24: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6C28: 40006b12                 call    _objc_msgSend
F00D6C2C: 90100018                 mov     %i0, %o0
F00D6C30: 133c0506                 sethi   %hi(paDone), %o1
F00D6C34: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6C38: 10800178                 ba      loc_F00D7218
F00D6C3C: 94100011                 mov     %l1, %o2
F00D6C40: 113c0505                 sethi   %hi(paUpdateoutputat_0), %o0! jumptable F00D6B38 case 3
F00D6C44: d20221e4                 ld      [%o0+%lo(paUpdateoutputat_0)], %o1! SEL
F00D6C48: 40006b0a                 call    _objc_msgSend
F00D6C4C: 90100018                 mov     %i0, %o0
F00D6C50: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6C54: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6C58: 40006b06                 call    _objc_msgSend
F00D6C5C: 90100018                 mov     %i0, %o0
F00D6C60: 133c0506                 sethi   %hi(paDone), %o1
F00D6C64: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6C68: 1080016c                 ba      loc_F00D7218
F00D6C6C: 94100011                 mov     %l1, %o2
F00D6C70: 113c0505                 sethi   %hi(paUpdateoutputat), %o0! jumptable F00D6B38 case 4
F00D6C74: d20221e0                 ld      [%o0+%lo(paUpdateoutputat)], %o1! SEL
F00D6C78: 40006afe                 call    _objc_msgSend
F00D6C7C: 90100018                 mov     %i0, %o0
F00D6C80: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6C84: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6C88: 40006afa                 call    _objc_msgSend
F00D6C8C: 90100018                 mov     %i0, %o0
F00D6C90: 133c0506                 sethi   %hi(paDone), %o1
F00D6C94: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6C98: 10800160                 ba      loc_F00D7218
F00D6C9C: 94100011                 mov     %l1, %o2
F00D6CA0: 113c0505                 sethi   %hi(paUpdateloudness), %o0! jumptable F00D6B38 case 5
F00D6CA4: d20221dc                 ld      [%o0+%lo(paUpdateloudness)], %o1! SEL
F00D6CA8: 40006af2                 call    _objc_msgSend
F00D6CAC: 90100018                 mov     %i0, %o0
F00D6CB0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6CB4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6CB8: 40006aee                 call    _objc_msgSend
F00D6CBC: 90100018                 mov     %i0, %o0
F00D6CC0: 133c0506                 sethi   %hi(paDone), %o1
F00D6CC4: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6CC8: 10800154                 ba      loc_F00D7218
F00D6CCC: 94100011                 mov     %l1, %o2
F00D6CD0: 113c0505                 sethi   %hi(paIsinputactive_0), %o0! jumptable F00D6B38 case 6
F00D6CD4: d2022210                 ld      [%o0+%lo(paIsinputactive_0)], %o1! SEL
F00D6CD8: 40006ae6                 call    _objc_msgSend
F00D6CDC: 90100018                 mov     %i0, %o0
F00D6CE0: 912a2018                 sll     %o0, 24, %o0
F00D6CE4: 80a22000                 cmp     %o0, 0
F00D6CE8: 2280000d                 be,a    loc_F00D6D1C
F00D6CEC: 113c0505                 sethi   -0xFEBEC00, %o0
F00D6CF0: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D6CF4: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1! SEL
F00D6CF8: 113c0505                 sethi   %hi(paStopdmaforchan_0), %o0! id
F00D6CFC: e00221d8                 ld      [%o0+%lo(paStopdmaforchan_0)], %l0
F00D6D00: 40006adc                 call    _objc_msgSend
F00D6D04: 90100018                 mov     %i0, %o0
F00D6D08: 94100008                 mov     %o0, %o2
F00D6D0C: 90100018                 mov     %i0, %o0! id
F00D6D10: 40006ad8                 call    _objc_msgSend
F00D6D14: 92100010                 mov     %l0, %o1
F00D6D18: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D6D1C: d20221f8                 ld      [%o0+0x1F8], %o1! SEL
F00D6D20: 40006ad4                 call    _objc_msgSend
F00D6D24: 90100018                 mov     %i0, %o0
F00D6D28: 133c0506                 sethi   %hi(paDone), %o1
F00D6D2C: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6D30: 1080013a                 ba      loc_F00D7218
F00D6D34: 94100011                 mov     %l1, %o2
F00D6D38: 113c0505                 sethi   %hi(paIsoutputactive_0), %o0! jumptable F00D6B38 case 7
F00D6D3C: d202220c                 ld      [%o0+%lo(paIsoutputactive_0)], %o1! SEL
F00D6D40: 40006acc                 call    _objc_msgSend
F00D6D44: 90100018                 mov     %i0, %o0
F00D6D48: 912a2018                 sll     %o0, 24, %o0
F00D6D4C: 80a22000                 cmp     %o0, 0
F00D6D50: 2280000d                 be,a    loc_F00D6D84
F00D6D54: 113c0505                 sethi   -0xFEBEC00, %o0
F00D6D58: 113c0505                 sethi   %hi(paOutputchannel), %o0
F00D6D5C: d2022218                 ld      [%o0+%lo(paOutputchannel)], %o1! SEL
F00D6D60: 113c0505                 sethi   %hi(paStopdmaforchan_0), %o0! id
F00D6D64: e00221d8                 ld      [%o0+%lo(paStopdmaforchan_0)], %l0
F00D6D68: 40006ac2                 call    _objc_msgSend
F00D6D6C: 90100018                 mov     %i0, %o0
F00D6D70: 94100008                 mov     %o0, %o2
F00D6D74: 90100018                 mov     %i0, %o0! id
F00D6D78: 40006abe                 call    _objc_msgSend
F00D6D7C: 92100010                 mov     %l0, %o1
F00D6D80: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D6D84: d20221f8                 ld      [%o0+0x1F8], %o1! SEL
F00D6D88: 40006aba                 call    _objc_msgSend
F00D6D8C: 90100018                 mov     %i0, %o0
F00D6D90: 133c0506                 sethi   %hi(paDone), %o1
F00D6D94: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6D98: 10800120                 ba      loc_F00D7218
F00D6D9C: 94100011                 mov     %l1, %o2
F00D6DA0: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 8
F00D6DA4: 9410201e                 mov     0x1E, %o2
F00D6DA8: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6DAC: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6DB0: 40006ab0                 call    _objc_msgSend
F00D6DB4: 96102001                 mov     1, %o3
F00D6DB8: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6DBC: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6DC0: 40006aac                 call    _objc_msgSend
F00D6DC4: 90100018                 mov     %i0, %o0
F00D6DC8: 133c0506                 sethi   %hi(paDone), %o1
F00D6DCC: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6DD0: 10800112                 ba      loc_F00D7218
F00D6DD4: 94100011                 mov     %l1, %o2
F00D6DD8: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 9
F00D6DDC: 9410201e                 mov     0x1E, %o2
F00D6DE0: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6DE4: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6DE8: 40006aa2                 call    _objc_msgSend
F00D6DEC: 96102000                 mov     0, %o3
F00D6DF0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6DF4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6DF8: 40006a9e                 call    _objc_msgSend
F00D6DFC: 90100018                 mov     %i0, %o0
F00D6E00: 133c0506                 sethi   %hi(paDone), %o1
F00D6E04: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6E08: 10800104                 ba      loc_F00D7218
F00D6E0C: 94100011                 mov     %l1, %o2
F00D6E10: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 10
F00D6E14: 9410201f                 mov     0x1F, %o2
F00D6E18: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6E1C: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6E20: 40006a94                 call    _objc_msgSend
F00D6E24: 96102001                 mov     1, %o3
F00D6E28: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6E2C: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6E30: 40006a90                 call    _objc_msgSend
F00D6E34: 90100018                 mov     %i0, %o0
F00D6E38: 133c0506                 sethi   %hi(paDone), %o1
F00D6E3C: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6E40: 108000f6                 ba      loc_F00D7218
F00D6E44: 94100011                 mov     %l1, %o2
F00D6E48: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 11
F00D6E4C: 9410201f                 mov     0x1F, %o2
F00D6E50: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6E54: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6E58: 40006a86                 call    _objc_msgSend
F00D6E5C: 96102000                 mov     0, %o3
F00D6E60: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6E64: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6E68: 40006a82                 call    _objc_msgSend
F00D6E6C: 90100018                 mov     %i0, %o0
F00D6E70: 133c0506                 sethi   %hi(paDone), %o1
F00D6E74: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6E78: 108000e8                 ba      loc_F00D7218
F00D6E7C: 94100011                 mov     %l1, %o2
F00D6E80: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 12
F00D6E84: 94102020                 mov     0x20, %o2 ! ' '
F00D6E88: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6E8C: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6E90: 40006a78                 call    _objc_msgSend
F00D6E94: 96102001                 mov     1, %o3
F00D6E98: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6E9C: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6EA0: 40006a74                 call    _objc_msgSend
F00D6EA4: 90100018                 mov     %i0, %o0
F00D6EA8: 133c0506                 sethi   %hi(paDone), %o1
F00D6EAC: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6EB0: 108000da                 ba      loc_F00D7218
F00D6EB4: 94100011                 mov     %l1, %o2
F00D6EB8: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 13
F00D6EBC: 94102020                 mov     0x20, %o2 ! ' '
F00D6EC0: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6EC4: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6EC8: 40006a6a                 call    _objc_msgSend
F00D6ECC: 96102000                 mov     0, %o3
F00D6ED0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6ED4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6ED8: 40006a66                 call    _objc_msgSend
F00D6EDC: 90100018                 mov     %i0, %o0
F00D6EE0: 133c0506                 sethi   %hi(paDone), %o1
F00D6EE4: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6EE8: 108000cc                 ba      loc_F00D7218
F00D6EEC: 94100011                 mov     %l1, %o2
F00D6EF0: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 14
F00D6EF4: 94102021                 mov     0x21, %o2 ! '!'
F00D6EF8: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6EFC: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6F00: 40006a5c                 call    _objc_msgSend
F00D6F04: 96102001                 mov     1, %o3
F00D6F08: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6F0C: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6F10: 40006a58                 call    _objc_msgSend
F00D6F14: 90100018                 mov     %i0, %o0
F00D6F18: 133c0506                 sethi   %hi(paDone), %o1
F00D6F1C: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6F20: 108000be                 ba      loc_F00D7218
F00D6F24: 94100011                 mov     %l1, %o2
F00D6F28: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 15
F00D6F2C: 94102021                 mov     0x21, %o2 ! '!'
F00D6F30: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6F34: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6F38: 40006a4e                 call    _objc_msgSend
F00D6F3C: 96102000                 mov     0, %o3
F00D6F40: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6F44: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6F48: 40006a4a                 call    _objc_msgSend
F00D6F4C: 90100018                 mov     %i0, %o0
F00D6F50: 133c0506                 sethi   %hi(paDone), %o1
F00D6F54: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6F58: 108000b0                 ba      loc_F00D7218
F00D6F5C: 94100011                 mov     %l1, %o2
F00D6F60: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 16
F00D6F64: 94102022                 mov     0x22, %o2 ! '"'
F00D6F68: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6F6C: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6F70: 40006a40                 call    _objc_msgSend
F00D6F74: 96102001                 mov     1, %o3
F00D6F78: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6F7C: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6F80: 40006a3c                 call    _objc_msgSend
F00D6F84: 90100018                 mov     %i0, %o0
F00D6F88: 133c0506                 sethi   %hi(paDone), %o1
F00D6F8C: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6F90: 108000a2                 ba      loc_F00D7218
F00D6F94: 94100011                 mov     %l1, %o2
F00D6F98: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 17
F00D6F9C: 94102022                 mov     0x22, %o2 ! '"'
F00D6FA0: 133c0505                 sethi   %hi(paSetinputEnable), %o1
F00D6FA4: d20261d4                 ld      [%o1+%lo(paSetinputEnable)], %o1! SEL
F00D6FA8: 40006a32                 call    _objc_msgSend
F00D6FAC: 96102000                 mov     0, %o3
F00D6FB0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6FB4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6FB8: 40006a2e                 call    _objc_msgSend
F00D6FBC: 90100018                 mov     %i0, %o0
F00D6FC0: 133c0506                 sethi   %hi(paDone), %o1
F00D6FC4: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D6FC8: 10800094                 ba      loc_F00D7218
F00D6FCC: 94100011                 mov     %l1, %o2
F00D6FD0: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 18
F00D6FD4: 94102019                 mov     0x19, %o2
F00D6FD8: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D6FDC: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D6FE0: 40006a24                 call    _objc_msgSend
F00D6FE4: 96102001                 mov     1, %o3
F00D6FE8: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D6FEC: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D6FF0: 40006a20                 call    _objc_msgSend
F00D6FF4: 90100018                 mov     %i0, %o0
F00D6FF8: 133c0506                 sethi   %hi(paDone), %o1
F00D6FFC: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D7000: 10800086                 ba      loc_F00D7218
F00D7004: 94100011                 mov     %l1, %o2
F00D7008: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 19
F00D700C: 94102019                 mov     0x19, %o2
F00D7010: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D7014: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D7018: 40006a16                 call    _objc_msgSend
F00D701C: 96102000                 mov     0, %o3
F00D7020: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D7024: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D7028: 40006a12                 call    _objc_msgSend
F00D702C: 90100018                 mov     %i0, %o0
F00D7030: 133c0506                 sethi   %hi(paDone), %o1
F00D7034: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D7038: 10800078                 ba      loc_F00D7218
F00D703C: 94100011                 mov     %l1, %o2
F00D7040: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 20
F00D7044: 9410201a                 mov     0x1A, %o2
F00D7048: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D704C: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D7050: 40006a08                 call    _objc_msgSend
F00D7054: 96102001                 mov     1, %o3
F00D7058: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D705C: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D7060: 40006a04                 call    _objc_msgSend
F00D7064: 90100018                 mov     %i0, %o0
F00D7068: 133c0506                 sethi   %hi(paDone), %o1
F00D706C: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D7070: 1080006a                 ba      loc_F00D7218
F00D7074: 94100011                 mov     %l1, %o2
F00D7078: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 21
F00D707C: 9410201a                 mov     0x1A, %o2
F00D7080: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D7084: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D7088: 400069fa                 call    _objc_msgSend
F00D708C: 96102000                 mov     0, %o3
F00D7090: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D7094: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D7098: 400069f6                 call    _objc_msgSend
F00D709C: 90100018                 mov     %i0, %o0
F00D70A0: 133c0506                 sethi   %hi(paDone), %o1
F00D70A4: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D70A8: 1080005c                 ba      loc_F00D7218
F00D70AC: 94100011                 mov     %l1, %o2
F00D70B0: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 22
F00D70B4: 9410201b                 mov     0x1B, %o2
F00D70B8: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D70BC: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D70C0: 400069ec                 call    _objc_msgSend
F00D70C4: 96102001                 mov     1, %o3
F00D70C8: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D70CC: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D70D0: 400069e8                 call    _objc_msgSend
F00D70D4: 90100018                 mov     %i0, %o0
F00D70D8: 133c0506                 sethi   %hi(paDone), %o1
F00D70DC: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D70E0: 1080004e                 ba      loc_F00D7218
F00D70E4: 94100011                 mov     %l1, %o2
F00D70E8: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 23
F00D70EC: 9410201b                 mov     0x1B, %o2
F00D70F0: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D70F4: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D70F8: 400069de                 call    _objc_msgSend
F00D70FC: 96102000                 mov     0, %o3
F00D7100: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D7104: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D7108: 400069da                 call    _objc_msgSend
F00D710C: 90100018                 mov     %i0, %o0
F00D7110: 133c0506                 sethi   %hi(paDone), %o1
F00D7114: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D7118: 10800040                 ba      loc_F00D7218
F00D711C: 94100011                 mov     %l1, %o2
F00D7120: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 24
F00D7124: 9410201c                 mov     0x1C, %o2
F00D7128: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D712C: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D7130: 400069d0                 call    _objc_msgSend
F00D7134: 96102001                 mov     1, %o3
F00D7138: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D713C: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D7140: 400069cc                 call    _objc_msgSend
F00D7144: 90100018                 mov     %i0, %o0
F00D7148: 133c0506                 sethi   %hi(paDone), %o1
F00D714C: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D7150: 10800032                 ba      loc_F00D7218
F00D7154: 94100011                 mov     %l1, %o2
F00D7158: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 25
F00D715C: 9410201c                 mov     0x1C, %o2
F00D7160: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D7164: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D7168: 400069c2                 call    _objc_msgSend
F00D716C: 96102000                 mov     0, %o3
F00D7170: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D7174: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D7178: 400069be                 call    _objc_msgSend
F00D717C: 90100018                 mov     %i0, %o0
F00D7180: 133c0506                 sethi   %hi(paDone), %o1
F00D7184: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D7188: 10800024                 ba      loc_F00D7218
F00D718C: 94100011                 mov     %l1, %o2
F00D7190: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 26
F00D7194: 9410201d                 mov     0x1D, %o2
F00D7198: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D719C: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D71A0: 400069b4                 call    _objc_msgSend
F00D71A4: 96102001                 mov     1, %o3
F00D71A8: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D71AC: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D71B0: 400069b0                 call    _objc_msgSend
F00D71B4: 90100018                 mov     %i0, %o0
F00D71B8: 133c0506                 sethi   %hi(paDone), %o1
F00D71BC: d2026034                 ld      [%o1+%lo(paDone)], %o1
F00D71C0: 10800016                 ba      loc_F00D7218
F00D71C4: 94100011                 mov     %l1, %o2
F00D71C8: 90100018                 mov     %i0, %o0! jumptable F00D6B38 case 27
F00D71CC: 9410201d                 mov     0x1D, %o2
F00D71D0: 133c0505                 sethi   %hi(paSetoutputEnabl), %o1
F00D71D4: d20261d0                 ld      [%o1+%lo(paSetoutputEnabl)], %o1! SEL
F00D71D8: 400069a6                 call    _objc_msgSend
F00D71DC: 96102000                 mov     0, %o3
F00D71E0: 113c0505                 sethi   %hi(paAudiocommand_0), %o0! id
F00D71E4: d20221f8                 ld      [%o0+%lo(paAudiocommand_0)], %o1! SEL
F00D71E8: 400069a2                 call    _objc_msgSend
F00D71EC: 90100018                 mov     %i0, %o0
F00D71F0: 133c0506                 sethi   %hi(paDone), %o1
F00D71F4: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00D71F8: 10800008                 ba      loc_F00D7218
F00D71FC: 94100011                 mov     %l1, %o2
F00D7200: 90100018                 mov     %i0, %o0! jumptable F00D6B38 default case
F00D7204: 4000699b                 call    _objc_msgSend
F00D7208: 92100010                 mov     %l0, %o1
F00D720C: 133c0506                 sethi   %hi(paDone), %o1
F00D7210: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00D7214: 94102001                 mov     1, %o2
F00D7218: 40006996                 call    _objc_msgSend
F00D721C: 01000000                 nop
F00D7220: 81c7e008                 ret
F00D7224: 81e80000                 restore
