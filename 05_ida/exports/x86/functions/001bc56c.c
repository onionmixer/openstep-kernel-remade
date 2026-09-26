/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc56c. */
int __cdecl sub_1BC56C(_DWORD *a1, int a2)
{
  int v3; // esi
  int v4; // edx
  _DWORD *v5; // edx
  _DWORD *v6; // ebx
  id v7; // eax
  id v8; // eax
  id v9; // eax
  int v10; // esi
  _DWORD *v11; // edx
  int v12; // eax
  int v13; // esi
  int v14; // edi
  _DWORD *v15; // edx
  _DWORD *v16; // edx
  int v17; // ebx
  int v18; // [esp-8h] [ebp-68h]
  int v19; // [esp-4h] [ebp-64h]
  id v20; // [esp+Ch] [ebp-54h]
  int v21; // [esp+10h] [ebp-50h]
  int v22; // [esp+1Ch] [ebp-44h]
  int v23; // [esp+20h] [ebp-40h]
  int v24; // [esp+24h] [ebp-3Ch]
  int v25; // [esp+28h] [ebp-38h]
  int v26; // [esp+2Ch] [ebp-34h]
  int v27; // [esp+30h] [ebp-30h]
  int v28; // [esp+34h] [ebp-2Ch]
  int v29; // [esp+38h] [ebp-28h]
  int v30; // [esp+3Ch] [ebp-24h]
  int v31; // [esp+40h] [ebp-20h]
  int v32; // [esp+4Ch] [ebp-14h] BYREF
  int v33; // [esp+50h] [ebp-10h] BYREF
  _DWORD *v34; // [esp+54h] [ebp-Ch]
  int v35; // [esp+58h] [ebp-8h] BYREF
  int v36; // [esp+5Ch] [ebp-4h] BYREF

  v31 = 0; /*0x1bc575*/
  v30 = 0; /*0x1bc57c*/
  LOBYTE(v29) = 0; /*0x1bc583*/
  v28 = 0; /*0x1bc58a*/
  v27 = -1; /*0x1bc591*/
  v26 = 0; /*0x1bc598*/
  v25 = 0; /*0x1bc59f*/
  v24 = a1[7]; /*0x1bc5ac*/
  v23 = 0; /*0x1bc5af*/
  v21 = 0; /*0x1bc5cb*/
  v20 = +[AudioChannel streamForUserPort:](aAudiochannel, sel_streamForUserPort_, a1[3]); /*0x1bc5e9*/
  if ( a1[5] == 1 ) /*0x1bc5f3*/
  {
    _NXAudioStreamInfo(v20, (int)&v36, (int)&v35); /*0x1bc601*/
    audio_snd_reply_ret_samples(a2, a1[4], v36, v35); /*0x1bc619*/
    return 0; /*0x1bc61e*/
  }
  else
  {
    v3 = a1[1] - 40; /*0x1bc62b*/
    v34 = a1 + 10; /*0x1bc631*/
    while ( 2 ) /*0x1bc636*/
    {
      if ( v3 > 0 ) /*0x1bc636*/
      {
        switch ( v34[1] ) /*0x1bc64b*/
        {
          case 0: /*0x1bc64b*/
            v34 += 10; /*0x1bc66c*/
            v3 -= 40; /*0x1bc670*/
            v27 = 0; /*0x1bc686*/
            continue; /*0x1bc68d*/
          case 1: /*0x1bc64b*/
            v4 = (*((_WORD *)v34 + 15) & 0xFFF) + 32; /*0x1bc69d*/
            v34 = (_DWORD *)((char *)v34 + v4); /*0x1bc6a2*/
            v3 -= v4; /*0x1bc6a5*/
            continue; /*0x1bc6a7*/
          case 2: /*0x1bc64b*/
            v6 = v34; /*0x1bc6f0*/
            v34 += 6; /*0x1bc6f6*/
            v3 -= 24; /*0x1bc6f9*/
            v26 = v6[3]; /*0x1bc6ff*/
            v25 = v6[4]; /*0x1bc705*/
            v7 = objc_msgSend(v20, sel_channel); /*0x1bc71b*/
            _NXAudioGetBufferOptions(v7, (id *)&v33, (id *)&v32); /*0x1bc724*/
            goto LABEL_12; /*0x1bc734*/
          case 3: /*0x1bc64b*/
            v5 = v34; /*0x1bc6ac*/
            v34 += 4; /*0x1bc6b2*/
            v3 -= 16; /*0x1bc6b5*/
            v30 |= v5[3]; /*0x1bc6bb*/
            continue; /*0x1bc6be*/
          case 4: /*0x1bc64b*/
            v34 += 4; /*0x1bc73e*/
            v3 -= 16; /*0x1bc741*/
            v8 = objc_msgSend(v20, sel_channel); /*0x1bc757*/
            _NXAudioGetBufferOptions(v8, (id *)&v33, (id *)&v32); /*0x1bc760*/
LABEL_12:
            v9 = objc_msgSend(v20, sel_channel); /*0x1bc770*/
            _NXAudioSetBufferOptions(v9, 0); /*0x1bc786*/
            continue; /*0x1bc78e*/
          case 5: /*0x1bc64b*/
            v34 += 6; /*0x1bc6ca*/
            v3 -= 24; /*0x1bc6cd*/
            v21 = 1; /*0x1bc6e2*/
            continue; /*0x1bc6e9*/
          default:
            v28 = 102; /*0x1bc794*/
            goto LABEL_14; /*0x1bc794*/
        }
      }
      break;
    }
LABEL_14:
    if ( v28 ) /*0x1bc7a1*/
    {
      v10 = a1[1] - 40; /*0x1bc7ad*/
      v34 = a1 + 10; /*0x1bc7b3*/
      while ( v10 > 0 ) /*0x1bc7b8*/
      {
        switch ( v34[1] ) /*0x1bc7c5*/
        {
          case 0: /*0x1bc7c5*/
            v11 = v34; /*0x1bc7e4*/
            v34 += 10; /*0x1bc7ea*/
            v10 -= 40; /*0x1bc7ed*/
            v19 = v11[8]; /*0x1bc7f3*/
            v18 = v11[9]; /*0x1bc7f7*/
            v12 = IOVmTaskSelf(); /*0x1bc7f8*/
            vm_deallocate_EXTERNAL(v12, v18, v19); /*0x1bc7fe*/
            break; /*0x1bc806*/
          case 1: /*0x1bc7c5*/
            v34 += 8; /*0x1bc808*/
            v10 -= 32; /*0x1bc80c*/
            break; /*0x1bc80f*/
          case 2: /*0x1bc7c5*/
          case 5: /*0x1bc7c5*/
            v34 += 6; /*0x1bc814*/
            v10 -= 24; /*0x1bc818*/
            break; /*0x1bc81b*/
          case 3: /*0x1bc7c5*/
          case 4: /*0x1bc7c5*/
            v34 += 4; /*0x1bc820*/
            v10 -= 16; /*0x1bc824*/
            break; /*0x1bc827*/
          default:
            continue;
        }
      }
      return v28; /*0x1bc82c*/
    }
    else
    {
      if ( (v30 & 2) != 0 ) /*0x1bc848*/
        _NXAudioStreamControl(v20, 2, 0, 0); /*0x1bc858*/
      if ( (v30 & 1) != 0 ) /*0x1bc866*/
        _NXAudioStreamControl(v20, 3, 0, 0); /*0x1bc876*/
      if ( (v30 & 4) != 0 ) /*0x1bc884*/
        _NXAudioStreamControl(v20, 0, 0, 0); /*0x1bc894*/
      v13 = a1[1] - 40; /*0x1bc8a2*/
      v34 = a1 + 10; /*0x1bc8a8*/
      while ( v13 > 0 ) /*0x1bc8ad*/
      {
        v14 = 0; /*0x1bc8b3*/
        switch ( v34[1] ) /*0x1bc8c0*/
        {
          case 0: /*0x1bc8c0*/
            v15 = v34; /*0x1bc8e0*/
            v34 += 10; /*0x1bc8e6*/
            v13 -= 40; /*0x1bc8e9*/
            v29 = v15[3]; /*0x1bc8ef*/
            v31 = v15[9]; /*0x1bc8f5*/
            v14 = v15[8]; /*0x1bc8f8*/
            v23 = v15[5]; /*0x1bc8fe*/
            break; /*0x1bc901*/
          case 1: /*0x1bc8c0*/
            v16 = v34; /*0x1bc904*/
            v34 += 8; /*0x1bc90a*/
            v13 -= 32; /*0x1bc90d*/
            v29 = v16[3]; /*0x1bc913*/
            v14 = v16[4]; /*0x1bc916*/
            v23 = v16[6]; /*0x1bc91c*/
            break; /*0x1bc91f*/
          case 2: /*0x1bc8c0*/
          case 5: /*0x1bc8c0*/
            v34 += 6; /*0x1bc924*/
            v13 -= 24; /*0x1bc928*/
            break; /*0x1bc92b*/
          case 3: /*0x1bc8c0*/
          case 4: /*0x1bc8c0*/
            v34 += 4; /*0x1bc930*/
            v13 -= 16; /*0x1bc934*/
            break; /*0x1bc934*/
          default:
            break;
        }
        if ( v14 ) /*0x1bc939*/
        {
          v17 = (v29 & 1) != 0; /*0x1bc949*/
          if ( !v27 && (v29 & 2) != 0 ) /*0x1bc956*/
            LOBYTE(v17) = v17 | 2; /*0x1bc958*/
          if ( (v29 & 8) != 0 ) /*0x1bc961*/
            LOBYTE(v17) = v17 | 4; /*0x1bc963*/
          if ( (v29 & 0x10) != 0 ) /*0x1bc96c*/
            LOBYTE(v17) = v17 | 8; /*0x1bc96e*/
          if ( (v29 & 4) != 0 ) /*0x1bc977*/
            LOBYTE(v17) = v17 | 0x10; /*0x1bc979*/
          if ( (v29 & 0x20) != 0 ) /*0x1bc982*/
            LOBYTE(v17) = v17 | 0x20; /*0x1bc984*/
          if ( v27 ) /*0x1bc98b*/
          {
            if ( v21 ) /*0x1bca3c*/
            {
              sub_1BC4E8(v27, v20); /*0x1bca5a*/
              _NXAudioRecordStreamData(v20, v14, v24, v23, v17); /*0x1bca6d*/
            }
            else
            {
              _NXAudioRecordStream(v20, v14, v24, v25, v26, v23, v17); /*0x1bca92*/
            }
          }
          else if ( v21 ) /*0x1bc995*/
          {
            sub_1BC4E8(0, v20); /*0x1bc9b1*/
            _NXAudioPlayStreamData(v20, v31, v14, v24, v23, v17); /*0x1bc9c8*/
          }
          else
          {
            v22 = 2; /*0x1bc9eb*/
            if ( objc_msgSend(v20, sel_type) == (id)3 ) /*0x1bc9f5*/
              v22 = 1; /*0x1bc9f7*/
            _NXAudioPlayStream(v20, v31, v14, v24, 2, v22, 0x8000, 0x8000, v25, v26, v23, v17); /*0x1bca28*/
          }
        }
      }
      if ( (v30 & 8) != 0 ) /*0x1bcaa6*/
        _NXAudioStreamControl(v20, 1, 0, 0); /*0x1bcab6*/
      return 100; /*0x1bcac2*/
    }
  }
}
