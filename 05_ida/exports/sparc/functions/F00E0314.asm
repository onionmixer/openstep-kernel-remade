F00E0314: 9de3bf98                 save    %sp, -0x68, %sp
F00E0318: a2102001                 mov     1, %l1
F00E031C: 90102001                 mov     1, %o0
F00E0320: d02e6003                 stb     %o0, [%i1+3]
F00E0324: 90102018                 mov     0x18, %o0
F00E0328: d0266004                 st      %o0, [%i1+4]
F00E032C: c0266008                 clr     [%i1+8]
F00E0330: c026600c                 clr     [%i1+0xC]
F00E0334: c0266010                 clr     [%i1+0x10]
F00E0338: c0266014                 clr     [%i1+0x14]
F00E033C: d6062014                 ld      [%i0+0x14], %o3
F00E0340: 80a2e001                 cmp     %o3, 1
F00E0344: 18800007                 bgu     loc_F00E0360
F00E0348: a0102000                 mov     0, %l0
F00E034C: 90100018                 mov     %i0, %o0
F00E0350: 7ffffbfa                 call    sub_F00DF338
F00E0354: 92100019                 mov     %i1, %o1
F00E0358: 1080001c                 ba      loc_F00E03C8
F00E035C: a0100008                 mov     %o0, %l0
F00E0360: 9002ff9c                 add     %o3, -0x64, %o0
F00E0364: 80a22010                 cmp     %o0, 0x10
F00E0368: 18800006                 bgu     loc_F00E0380
F00E036C: 90100018                 mov     %i0, %o0
F00E0370: 7ffffd78                 call    sub_F00DF950
F00E0374: 92100019                 mov     %i1, %o1
F00E0378: 10800014                 ba      loc_F00E03C8
F00E037C: a0100008                 mov     %o0, %l0
F00E0380: 9002ff38                 add     %o3, -0xC8, %o0
F00E0384: 80a22007                 cmp     %o0, 7
F00E0388: 1880000a                 bgu     loc_F00E03B0
F00E038C: 113c03f2                 sethi   %hi(aAudioReceivedD), %o0! "Audio: received dsp cmd port msg!\n"
F00E0390: 7fff9759                 call    _IOLog
F00E0394: 901220f0                 bset    %lo(aAudioReceivedD), %o0! "Audio: received dsp cmd port msg!\n"
F00E0398: 90100019                 mov     %i1, %o0
F00E039C: 92102000                 mov     0, %o1
F00E03A0: d4062010                 ld      [%i0+0x10], %o2
F00E03A4: 98102066                 mov     0x66, %o4 ! 'f'
F00E03A8: 10800006                 ba      loc_F00E03C0
F00E03AC: d6062014                 ld      [%i0+0x14], %o3
F00E03B0: 90100019                 mov     %i1, %o0
F00E03B4: 92102000                 mov     0, %o1
F00E03B8: d4062010                 ld      [%i0+0x10], %o2
F00E03BC: 98102066                 mov     0x66, %o4 ! 'f'
F00E03C0: 4000043c                 call    _audio_snd_reply_illegal_msg
F00E03C4: a2102000                 mov     0, %l1
F00E03C8: 80a42000                 cmp     %l0, 0
F00E03CC: 02800007                 be      locret_F00E03E8
F00E03D0: 90100019                 mov     %i1, %o0
F00E03D4: d4062010                 ld      [%i0+0x10], %o2
F00E03D8: 92102000                 mov     0, %o1
F00E03DC: d6062014                 ld      [%i0+0x14], %o3
F00E03E0: 40000434                 call    _audio_snd_reply_illegal_msg
F00E03E4: 98100010                 mov     %l0, %o4
F00E03E8: 81c7e008                 ret
F00E03EC: 91e80011                 restore %g0, %l1, %o0
