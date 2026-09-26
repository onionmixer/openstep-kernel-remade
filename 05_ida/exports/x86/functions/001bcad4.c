/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bcad4. */
int __cdecl sub_1BCAD4(int a1, int a2)
{
  int v2; // edx
  id v3; // esi
  id v4; // esi
  id v5; // esi
  id v6; // eax
  int v7; // ecx
  id v8; // eax
  id v9; // eax
  id v10; // esi
  int i; // eax
  int v12; // ecx
  int j; // eax
  int v14; // edx
  int k; // eax
  int v16; // ecx
  int m; // eax
  int v18; // edx
  id v19; // eax
  id v20; // esi
  id v21; // eax
  id v23; // esi
  id v24; // eax
  int v25; // [esp-10h] [ebp-458h]
  int v26; // [esp+Ch] [ebp-43Ch]
  int v27; // [esp+Ch] [ebp-43Ch]
  int v28; // [esp+Ch] [ebp-43Ch]
  int v29; // [esp+10h] [ebp-438h]
  int v30; // [esp+14h] [ebp-434h] BYREF
  int v31; // [esp+18h] [ebp-430h] BYREF
  int v32[256]; // [esp+1Ch] [ebp-42Ch] BYREF
  id v33; // [esp+41Ch] [ebp-2Ch] BYREF
  int v34; // [esp+420h] [ebp-28h]
  int v35; // [esp+424h] [ebp-24h] BYREF
  int v36; // [esp+428h] [ebp-20h] BYREF
  int v37; // [esp+42Ch] [ebp-1Ch]
  int v38; // [esp+430h] [ebp-18h] BYREF
  int v39; // [esp+434h] [ebp-14h] BYREF
  int v40; // [esp+438h] [ebp-10h] BYREF
  int v41; // [esp+43Ch] [ebp-Ch] BYREF
  int v42; // [esp+440h] [ebp-8h]
  int v43; // [esp+444h] [ebp-4h]

  v29 = 100; /*0x1bcae3*/
  v40 = 0; /*0x1bcaed*/
  v26 = 0; /*0x1bcaf4*/
  v43 = 0; /*0x1bcafe*/
  v42 = 0; /*0x1bcb05*/
  switch ( *(_DWORD *)(a1 + 20) ) /*0x1bcb1b*/
  {
    case 'd': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 40 ) /*0x1bcb6c*/
        return 103; /*0x1bcb6c*/
      v2 = *(_DWORD *)(a1 + 28); /*0x1bcb72*/
      if ( v2 == 130 ) /*0x1bcb7b*/
      {
        v3 = +[IOAudio _inputChannelForSndPort:](aIoaudio, sel__inputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcb94*/
        v41 = (int)objc_msgSend(v3, sel_streamUserForOwnerPort_, *(_DWORD *)(a1 + 36)); /*0x1bcba7*/
        if ( !v41 ) /*0x1bcbaf*/
          _NXAudioAddStream(v3, (int)&v41, *(_DWORD *)(a1 + 36), 0, 1); /*0x1bcbb3*/
      }
      else
      {
        v27 = 4; /*0x1bcbb8*/
        if ( v2 == 129 ) /*0x1bcbc8*/
          v27 = 3; /*0x1bcbca*/
        v4 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcbeb*/
        v41 = (int)objc_msgSend(v4, sel_streamUserForOwnerPort_, *(_DWORD *)(a1 + 36)); /*0x1bcbfe*/
        if ( !v41 ) /*0x1bcc06*/
          _NXAudioAddStream(v4, (int)&v41, *(_DWORD *)(a1 + 36), 0, v27); /*0x1bcc1a*/
      }
      audio_snd_reply_ret_stream(a2, *(_DWORD *)(a1 + 16), v41); /*0x1bcc2e*/
      return 0; /*0x1bcc3d*/
    case 'e': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 32 ) /*0x1bcc48*/
        return 103; /*0x1bcc48*/
      v5 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcc65*/
      _NXAudioGetSndoutOptions(v5, &v40); /*0x1bcc6c*/
      if ( (*(_BYTE *)(a1 + 28) & 4) != 0 ) /*0x1bcc78*/
        LOBYTE(v40) = v40 | 1; /*0x1bcc7a*/
      else
        v40 &= ~1u; /*0x1bcc80*/
      if ( (*(_BYTE *)(a1 + 28) & 2) != 0 ) /*0x1bcc88*/
        LOBYTE(v40) = v40 | 0x10; /*0x1bcc8a*/
      else
        v40 &= ~0x10u; /*0x1bcc90*/
      if ( (*(_BYTE *)(a1 + 28) & 1) != 0 ) /*0x1bcc98*/
        LOBYTE(v40) = v40 | 8; /*0x1bcc9a*/
      else
        v40 &= ~8u; /*0x1bcca4*/
      goto LABEL_106; /*0x1bcc9e*/
    case 'f': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 24 ) /*0x1bccb4*/
        return 103; /*0x1bccb4*/
      v6 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcccc*/
      _NXAudioGetSndoutOptions(v6, &v40); /*0x1bccd8*/
      if ( (v40 & 1) != 0 ) /*0x1bcce6*/
        LOBYTE(v26) = 4; /*0x1bcce8*/
      if ( (v40 & 0x10) != 0 ) /*0x1bccf2*/
        LOBYTE(v26) = v26 | 2; /*0x1bccf4*/
      if ( (v40 & 8) != 0 ) /*0x1bccfe*/
        LOBYTE(v26) = v26 | 1; /*0x1bcd00*/
      audio_snd_reply_ret_parms(a2, *(_DWORD *)(a1 + 16), v26); /*0x1bcd16*/
      return 0; /*0x1bcd25*/
    case 'g': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 32 ) /*0x1bcd30*/
        return 103; /*0x1bcd30*/
      v7 = (unsigned __int8)*(_DWORD *)(a1 + 28); /*0x1bcd40*/
      v39 = 2 * *(unsigned __int8 *)(a1 + 29) - 86; /*0x1bcd50*/
      v38 = 2 * v7 - 86; /*0x1bcd5a*/
      v8 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcd6f*/
      _NXAudioSetSpeaker(v8, 0); /*0x1bcd81*/
      return v29; /*0x1bcd86*/
    case 'h': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 24 ) /*0x1bcd90*/
        return 103; /*0x1bcd90*/
      v9 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcda8*/
      _NXAudioGetSpeaker(v9, (id *)&v39, (id *)&v38); /*0x1bcdb8*/
      v39 = v39 / 2 + 43; /*0x1bcdce*/
      v38 = v38 / 2 + 43; /*0x1bcddf*/
      audio_snd_reply_ret_volume(a2, *(_DWORD *)(a1 + 16), v38 | (v39 << 8)); /*0x1bcdf0*/
      return 0; /*0x1bcdff*/
    case 'i': /*0x1bcb1b*/
    case 'l': /*0x1bcb1b*/
    case 'm': /*0x1bcb1b*/
    case 'o': /*0x1bcb1b*/
      return 108; /*0x1bd2f9*/
    case 'j': /*0x1bcb1b*/
    case 'k': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 40 ) /*0x1bd1a4*/
        return 103; /*0x1bd1a4*/
      v19 = +[AudioChannel streamForOwnerPort:](aAudiochannel, sel_streamForOwnerPort_, *(_DWORD *)(a1 + 36)); /*0x1bd1bc*/
      if ( v19 ) /*0x1bd1c6*/
        _NXAudioStreamControl(v19, 2, v42, v43); /*0x1bd1d7*/
      return v29; /*0x1bd1dc*/
    case 'n': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 32 ) /*0x1bd1e8*/
        return 103; /*0x1bd1e8*/
      v20 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bd205*/
      v25 = *(_DWORD *)(a1 + 28); /*0x1bd20a*/
      v21 = objc_msgSend(v20, sel_audioDevice); /*0x1bd213*/
      v28 = audio_reset_snd_dev_port(v21, v25); /*0x1bd221*/
      if ( !v28 ) /*0x1bd22c*/
        return 112; /*0x1bd233*/
      objc_msgSend(v20, sel_removeSndStreams); /*0x1bd240*/
      v23 = +[IOAudio _inputChannelForSndPort:](aIoaudio, sel__inputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bd25c*/
      objc_msgSend(v23, sel_removeSndStreams); /*0x1bd266*/
      audio_snd_reply_ret_device(a2, *(_DWORD *)(a1 + 16), v28); /*0x1bd27a*/
      return 0; /*0x1bd289*/
    case 'p': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 48 ) /*0x1bd290*/
        return 103; /*0x1bd290*/
      v24 = +[AudioChannel streamForOwnerPort:](aAudiochannel, sel_streamForOwnerPort_, *(_DWORD *)(a1 + 28)); /*0x1bd2a4*/
      if ( v24 ) /*0x1bd2ae*/
        goto LABEL_121; /*0x1bd2ae*/
      return 106; /*0x1bd2ae*/
    case 'q': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 48 ) /*0x1bd2b8*/
        return 103; /*0x1bd2b8*/
      v24 = +[AudioChannel streamForOwnerPort:](aAudiochannel, sel_streamForOwnerPort_, *(_DWORD *)(a1 + 28)); /*0x1bd2d6*/
      if ( !v24 ) /*0x1bd2e0*/
        return 106; /*0x1bd2e7*/
LABEL_121:
      _NXAudioRemoveStream(v24); /*0x1bd2ec*/
      return v29; /*0x1bd2f2*/
    case 'r': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 32 ) /*0x1bd140*/
        return 103; /*0x1bd140*/
      v5 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bd15d*/
      _NXAudioGetSndoutOptions(v5, &v40); /*0x1bd164*/
      if ( (*(_BYTE *)(a1 + 28) & 1) != 0 ) /*0x1bd170*/
        LOBYTE(v40) = v40 | 2; /*0x1bd172*/
      else
        v40 &= ~2u; /*0x1bd178*/
      if ( (*(_BYTE *)(a1 + 28) & 2) != 0 ) /*0x1bd180*/
        LOBYTE(v40) = v40 | 4; /*0x1bd182*/
      else
        v40 &= ~4u; /*0x1bd188*/
LABEL_106:
      _NXAudioSetSndoutOptions(v5, 0, v40); /*0x1bd18c*/
      return v29; /*0x1bd198*/
    case 's': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 24 ) /*0x1bce08*/
        return 103; /*0x1bce08*/
      v10 = +[IOAudio _outputChannelForSndPort:](aIoaudio, sel__outputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bce25*/
      _NXAudioGetSamplingRates(v10, &v31, (int)&v36, (int)&v35, (int)v32, &v30); /*0x1bce51*/
      v37 = v31 != 0; /*0x1bce69*/
      for ( i = 0; v30 > i; ++i ) /*0x1bce78*/
      {
        v12 = v32[i]; /*0x1bce80*/
        if ( (unsigned int)(v12 - 8000) > 0xD ) /*0x1bce90*/
        {
          if ( v12 == 22050 ) /*0x1bce9e*/
          {
            LOBYTE(v37) = v37 | 0x10; /*0x1bcee4*/
          }
          else if ( v12 > 22050 ) /*0x1bcea0*/
          {
            if ( v12 == 44100 ) /*0x1bceba*/
            {
              LOBYTE(v37) = v37 | 0x40; /*0x1bcef4*/
            }
            else if ( v12 > 44100 ) /*0x1bcebc*/
            {
              if ( v12 == 48000 ) /*0x1bcece*/
                LOBYTE(v37) = v37 | 0x80; /*0x1bcefc*/
            }
            else if ( v12 == 32000 ) /*0x1bcec4*/
            {
              LOBYTE(v37) = v37 | 0x20; /*0x1bceec*/
            }
          }
          else if ( v12 == 11025 ) /*0x1bcea8*/
          {
            LOBYTE(v37) = v37 | 4; /*0x1bced4*/
          }
          else if ( v12 == 16000 ) /*0x1bceb0*/
          {
            LOBYTE(v37) = v37 | 8; /*0x1bcedc*/
          }
        }
        else
        {
          LOBYTE(v37) = v37 | 2; /*0x1bce92*/
        }
      }
      _NXAudioGetDataEncodings(v10, (int)v32, &v30); /*0x1bcf1c*/
      v34 = 0; /*0x1bcf24*/
      for ( j = 0; j < v30; ++j ) /*0x1bcf35*/
      {
        v14 = v32[j]; /*0x1bcf40*/
        if ( v14 == 601 ) /*0x1bcf4d*/
        {
          LOBYTE(v34) = v34 | 2; /*0x1bcf6c*/
        }
        else if ( v14 > 601 ) /*0x1bcf4f*/
        {
          if ( v14 == 602 ) /*0x1bcf62*/
            LOBYTE(v34) = v34 | 1; /*0x1bcf64*/
        }
        else if ( v14 == 600 ) /*0x1bcf57*/
        {
          LOBYTE(v34) = v34 | 4; /*0x1bcf74*/
        }
      }
      goto LABEL_98; /*0x1bcf7b*/
    case 't': /*0x1bcb1b*/
      if ( *(_DWORD *)(a1 + 4) != 24 ) /*0x1bcf88*/
        return 103; /*0x1bd2ba*/
      v10 = +[IOAudio _inputChannelForSndPort:](aIoaudio, sel__inputChannelForSndPort_, *(_DWORD *)(a1 + 12)); /*0x1bcfa5*/
      _NXAudioGetSamplingRates(v10, &v31, (int)&v36, (int)&v35, (int)v32, &v30); /*0x1bcfd1*/
      v37 = v31 != 0; /*0x1bcfe9*/
      for ( k = 0; v30 > k; ++k ) /*0x1bcff8*/
      {
        v16 = v32[k]; /*0x1bd000*/
        if ( (unsigned int)(v16 - 8000) > 0xD ) /*0x1bd010*/
        {
          if ( v16 == 22050 ) /*0x1bd01e*/
          {
            LOBYTE(v37) = v37 | 0x10; /*0x1bd064*/
          }
          else if ( v16 > 22050 ) /*0x1bd020*/
          {
            if ( v16 == 44100 ) /*0x1bd03a*/
            {
              LOBYTE(v37) = v37 | 0x40; /*0x1bd074*/
            }
            else if ( v16 > 44100 ) /*0x1bd03c*/
            {
              if ( v16 == 48000 ) /*0x1bd04e*/
                LOBYTE(v37) = v37 | 0x80; /*0x1bd07c*/
            }
            else if ( v16 == 32000 ) /*0x1bd044*/
            {
              LOBYTE(v37) = v37 | 0x20; /*0x1bd06c*/
            }
          }
          else if ( v16 == 11025 ) /*0x1bd028*/
          {
            LOBYTE(v37) = v37 | 4; /*0x1bd054*/
          }
          else if ( v16 == 16000 ) /*0x1bd030*/
          {
            LOBYTE(v37) = v37 | 8; /*0x1bd05c*/
          }
        }
        else
        {
          LOBYTE(v37) = v37 | 2; /*0x1bd012*/
        }
      }
      _NXAudioGetDataEncodings(v10, (int)v32, &v30); /*0x1bd09c*/
      v34 = 0; /*0x1bd0a4*/
      for ( m = 0; m < v30; ++m ) /*0x1bd0b5*/
      {
        v18 = v32[m]; /*0x1bd0bc*/
        if ( v18 == 601 ) /*0x1bd0c9*/
        {
          LOBYTE(v34) = v34 | 2; /*0x1bd0e8*/
        }
        else if ( v18 > 601 ) /*0x1bd0cb*/
        {
          if ( v18 == 602 ) /*0x1bd0de*/
            LOBYTE(v34) = v34 | 1; /*0x1bd0e0*/
        }
        else if ( v18 == 600 ) /*0x1bd0d3*/
        {
          LOBYTE(v34) = v34 | 4; /*0x1bd0f0*/
        }
      }
LABEL_98:
      _NXAudioGetChannelCountLimit(v10, &v33); /*0x1bd0f9*/
      audio_snd_reply_ret_formats(a2, *(_DWORD *)(a1 + 16), v37, v36, v35, v34, v33); /*0x1bd125*/
      return 0;
    default:
      return v29;
  }
}
