F00C6C28: 9de3bf90                 save    %sp, -0x70, %sp
F00C6C2C: f4262184                 st      %i2, [%i0+0x184]
F00C6C30: 90100018                 mov     %i0, %o0! id
F00C6C34: 133c0506                 sethi   %hi(paSetisphysical), %o1
F00C6C38: d20261b4                 ld      [%o1+%lo(paSetisphysical)], %o1! SEL
F00C6C3C: 4000ab0d                 call    _objc_msgSend
F00C6C40: 94102000                 mov     0, %o2
F00C6C44: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F00C6C48: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F00C6C4C: 4000ab09                 call    _objc_msgSend
F00C6C50: 9010001a                 mov     %i2, %o0
F00C6C54: d026218c                 st      %o0, [%i0+0x18C]
F00C6C58: 113c0504                 sethi   %hi(paIsremovable), %o0
F00C6C5C: d20221a8                 ld      [%o0+%lo(paIsremovable)], %o1! SEL
F00C6C60: 113c0506                 sethi   %hi(paSetremovable), %o0! id
F00C6C64: e00221b0                 ld      [%o0+%lo(paSetremovable)], %l0
F00C6C68: 4000ab02                 call    _objc_msgSend
F00C6C6C: 9010001a                 mov     %i2, %o0
F00C6C70: 952a2018                 sll     %o0, 24, %o2
F00C6C74: 90100018                 mov     %i0, %o0! id
F00C6C78: 92100010                 mov     %l0, %o1! SEL
F00C6C7C: 4000aafd                 call    _objc_msgSend
F00C6C80: 953aa018                 sra     %o2, 24, %o2
F00C6C84: 113c0504                 sethi   %hi(paIsformatted), %o0
F00C6C88: d2022178                 ld      [%o0+%lo(paIsformatted)], %o1! SEL
F00C6C8C: 113c0506                 sethi   %hi(paSetformattedin), %o0! id
F00C6C90: e00221ac                 ld      [%o0+%lo(paSetformattedin)], %l0
F00C6C94: 4000aaf7                 call    _objc_msgSend
F00C6C98: 9010001a                 mov     %i2, %o0
F00C6C9C: 952a2018                 sll     %o0, 24, %o2
F00C6CA0: 90100018                 mov     %i0, %o0! id
F00C6CA4: 92100010                 mov     %l0, %o1! SEL
F00C6CA8: 4000aaf2                 call    _objc_msgSend
F00C6CAC: 953aa018                 sra     %o2, 24, %o2
F00C6CB0: 113c0506                 sethi   %hi(paIswriteprotect), %o0
F00C6CB4: d20221bc                 ld      [%o0+%lo(paIswriteprotect)], %o1! SEL
F00C6CB8: 113c0506                 sethi   %hi(paSetwriteprotec), %o0! id
F00C6CBC: e00221a8                 ld      [%o0+%lo(paSetwriteprotec)], %l0
F00C6CC0: 4000aaec                 call    _objc_msgSend
F00C6CC4: 9010001a                 mov     %i2, %o0
F00C6CC8: 952a2018                 sll     %o0, 24, %o2
F00C6CCC: 90100018                 mov     %i0, %o0! id
F00C6CD0: 92100010                 mov     %l0, %o1! SEL
F00C6CD4: 4000aae7                 call    _objc_msgSend
F00C6CD8: 953aa018                 sra     %o2, 24, %o2
F00C6CDC: 90100018                 mov     %i0, %o0! id
F00C6CE0: 133c0506                 sethi   %hi(paSetlogicaldisk), %o1
F00C6CE4: d20261a4                 ld      [%o1+%lo(paSetlogicaldisk)], %o1! SEL
F00C6CE8: 4000aae2                 call    _objc_msgSend
F00C6CEC: 94102000                 mov     0, %o2
F00C6CF0: 113c0506                 sethi   %hi(paDevandidinfo_0), %o0
F00C6CF4: d20221a0                 ld      [%o0+%lo(paDevandidinfo_0)], %o1! SEL
F00C6CF8: 113c0506                 sethi   %hi(paSetdevandidinf), %o0! id
F00C6CFC: e002219c                 ld      [%o0+%lo(paSetdevandidinf)], %l0
F00C6D00: 4000aadc                 call    _objc_msgSend
F00C6D04: 9010001a                 mov     %i2, %o0
F00C6D08: 94100008                 mov     %o0, %o2
F00C6D0C: 90100018                 mov     %i0, %o0! id
F00C6D10: 4000aad8                 call    _objc_msgSend
F00C6D14: 92100010                 mov     %l0, %o1
F00C6D18: 81c7e008                 ret
F00C6D1C: 91e82000                 restore %g0, 0, %o0
