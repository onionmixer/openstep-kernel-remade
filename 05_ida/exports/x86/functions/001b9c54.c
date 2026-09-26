/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9c54. */
unsigned int __cdecl -[OutputStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:](
        OutputStream *self,
        SEL a2,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a4,
        unsigned int a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        int a9,
        unsigned int a10)
{
  unsigned int v10; // eax
  char *mixBuffer1; // edi
  void *var2; // edx
  unsigned int v13; // esi
  unsigned int v14; // ecx
  unsigned int v15; // eax
  int v16; // edi
  queue_entry *next; // eax
  int v19; // [esp+10h] [ebp-30h]
  unsigned int v20; // [esp+14h] [ebp-2Ch]
  void *v21; // [esp+14h] [ebp-2Ch]
  unsigned int v22; // [esp+18h] [ebp-28h]
  char *mixBuffer2; // [esp+1Ch] [ebp-24h]
  int dataFormat; // [esp+20h] [ebp-20h]
  int v25; // [esp+24h] [ebp-1Ch]
  unsigned int v26; // [esp+28h] [ebp-18h]
  unsigned int v27; // [esp+2Ch] [ebp-14h]
  unsigned int v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+38h] [ebp-8h] BYREF
  int v30; // [esp+3Ch] [ebp-4h] BYREF

  v28 = 0; /*0x1b9c63*/
  v30 = 0; /*0x1b9c6a*/
  v29 = 0; /*0x1b9c71*/
  v27 = 0; /*0x1b9c78*/
  v10 = 0; /*0x1b9c7f*/
  v25 = 1; /*0x1b9c81*/
  dataFormat = self->super.dataFormat; /*0x1b9c8e*/
  mixBuffer1 = self->super.mixBuffer1; /*0x1b9c94*/
  mixBuffer2 = self->super.mixBuffer2; /*0x1b9c9a*/
  var2 = (void *)a3->var2; /*0x1b9ca0*/
  v26 = a6; /*0x1b9ca6*/
  v13 = a6; /*0x1b9ca9*/
  v14 = a3->var1 - (_DWORD)var2; /*0x1b9caf*/
  if ( a6 > v14 ) /*0x1b9cb6*/
  {
    v26 = a3->var1 - (_DWORD)var2; /*0x1b9cb8*/
    v13 = v26; /*0x1b9cbb*/
  }
  if ( !dataFormat ) /*0x1b9cc2*/
    v10 = 1; /*0x1b9cc4*/
  if ( self->leftGain != 0x8000 || self->rightGain != 0x8000 ) /*0x1b9cdc*/
    LOBYTE(v10) = v10 | 2; /*0x1b9cde*/
  if ( self->super.channelCount == 1 && a10 == 2 ) /*0x1b9ced*/
  {
    LOBYTE(v10) = v10 | 0x10; /*0x1b9cef*/
  }
  else if ( self->super.channelCount == 2 && a10 == 1 ) /*0x1b9d01*/
  {
    LOBYTE(v10) = v10 | 0x20; /*0x1b9d03*/
  }
  if ( self->super.samplingRate == 22050 && a8 == 44100 ) /*0x1b9d18*/
  {
    LOBYTE(v10) = v10 | 4; /*0x1b9d1a*/
  }
  else if ( self->super.samplingRate == 44100 && a8 == 22050 ) /*0x1b9d33*/
  {
    LOBYTE(v10) = v10 | 8; /*0x1b9d35*/
  }
  if ( dataFormat == 3 ) /*0x1b9d3b*/
  {
    if ( !a9 ) /*0x1b9d41*/
    {
      LOBYTE(v10) = v10 | 0x40; /*0x1b9d43*/
      goto LABEL_35; /*0x1b9d45*/
    }
    if ( a9 == 1 ) /*0x1b9d4c*/
    {
      LOBYTE(v10) = v10 | 0x80; /*0x1b9d4e*/
      goto LABEL_35; /*0x1b9d50*/
    }
  }
  if ( dataFormat ) /*0x1b9d58*/
    goto LABEL_30; /*0x1b9d58*/
  if ( a9 == 3 ) /*0x1b9d5e*/
  {
    BYTE1(v10) |= 1u; /*0x1b9d60*/
    goto LABEL_35; /*0x1b9d63*/
  }
  if ( a9 != 1 ) /*0x1b9d6c*/
  {
LABEL_30:
    if ( dataFormat == 1 ) /*0x1b9d78*/
    {
      if ( a9 ) /*0x1b9d7e*/
      {
        if ( a9 == 3 ) /*0x1b9d8c*/
          BYTE1(v10) |= 8u; /*0x1b9d8e*/
      }
      else
      {
        BYTE1(v10) |= 4u; /*0x1b9d80*/
      }
    }
  }
  else
  {
    BYTE1(v10) |= 2u; /*0x1b9d6e*/
  }
LABEL_35:
  if ( v10 == 24 ) /*0x1b9d94*/
  {
    audio_convertMonoToStereo(var2, mixBuffer1, v13, dataFormat); /*0x1ba00b*/
    audio_resample44To22(mixBuffer1, mixBuffer2, 2 * v13, dataFormat); /*0x1ba023*/
    goto LABEL_97; /*0x1ba028*/
  }
  if ( v10 > 0x18 ) /*0x1b9d9a*/
  {
    if ( v10 == 41 ) /*0x1b9e37*/
    {
      v13 *= 4; /*0x1ba1fc*/
      if ( v14 < v13 ) /*0x1ba202*/
        v13 = a3->var1 - (_DWORD)var2; /*0x1ba204*/
      v26 = v13 >> 2; /*0x1ba20c*/
      audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba219*/
      audio_convertStereoToMono(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba231*/
      audio_resample44To22(mixBuffer2, mixBuffer1, v13 >> 1, dataFormat); /*0x1ba24c*/
      goto LABEL_119; /*0x1ba24c*/
    }
    if ( v10 > 0x29 ) /*0x1b9e3d*/
    {
      if ( v10 == 257 ) /*0x1b9e95*/
      {
        v13 *= 2; /*0x1ba2e0*/
        if ( v14 < v13 ) /*0x1ba2e5*/
          v13 = a3->var1 - (_DWORD)var2; /*0x1ba2e7*/
        v26 = v13 >> 1; /*0x1ba2ee*/
        audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba2f4*/
        audio_convertLinear16ToLinear8(mixBuffer1, mixBuffer2, v13 >> 1); /*0x1ba308*/
        dataFormat = 3; /*0x1ba30d*/
      }
      else
      {
        if ( v10 <= 0x101 ) /*0x1b9e9b*/
        {
          if ( v10 == 64 ) /*0x1b9ea0*/
          {
            v13 >>= 1; /*0x1ba084*/
            audio_convertLinear8ToLinear16(var2, mixBuffer1, v13); /*0x1ba089*/
            dataFormat = 0; /*0x1ba08e*/
            goto LABEL_103; /*0x1ba095*/
          }
          if ( v10 == 128 ) /*0x1b9eab*/
          {
            audio_convertLinear8ToMulaw8(var2, mixBuffer1, v13); /*0x1ba09b*/
            dataFormat = 1; /*0x1ba0a0*/
            goto LABEL_103; /*0x1ba0a7*/
          }
          goto LABEL_130; /*0x1b9eab*/
        }
        if ( v10 == 1024 ) /*0x1b9ebd*/
        {
          v13 >>= 1; /*0x1ba05c*/
          audio_convertMulaw8ToLinear16(var2, mixBuffer1, v13); /*0x1ba061*/
          dataFormat = 0; /*0x1ba066*/
          goto LABEL_103; /*0x1ba06d*/
        }
        if ( v10 > 0x400 ) /*0x1b9ec3*/
        {
          if ( v10 == 2048 ) /*0x1b9edd*/
          {
            audio_convertMulaw8ToLinear8(var2, mixBuffer1, v13); /*0x1ba073*/
            dataFormat = 3; /*0x1ba078*/
            goto LABEL_103; /*0x1ba07f*/
          }
          goto LABEL_130; /*0x1b9edd*/
        }
        if ( v10 != 513 ) /*0x1b9eca*/
          goto LABEL_130; /*0x1b9eca*/
        v13 *= 2; /*0x1ba318*/
        if ( v14 < v13 ) /*0x1ba31d*/
          v13 = a3->var1 - (_DWORD)var2; /*0x1ba31f*/
        v26 = v13 >> 1; /*0x1ba326*/
        audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba32c*/
        audio_convertLinear16ToMulaw8(mixBuffer1, mixBuffer2, v13 >> 1); /*0x1ba340*/
        dataFormat = 1; /*0x1ba345*/
      }
LABEL_129:
      var2 = mixBuffer2; /*0x1ba34c*/
      goto LABEL_131; /*0x1ba352*/
    }
    if ( v10 == 33 ) /*0x1b9e42*/
    {
      v13 *= 2; /*0x1ba128*/
      if ( v14 < v13 ) /*0x1ba12d*/
        v13 = a3->var1 - (_DWORD)var2; /*0x1ba12f*/
      v26 = v13 >> 1; /*0x1ba136*/
      audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba13c*/
      audio_convertStereoToMono(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba154*/
      goto LABEL_114; /*0x1ba159*/
    }
    if ( v10 <= 0x21 ) /*0x1b9e48*/
    {
      if ( v10 == 25 ) /*0x1b9e4d*/
      {
        audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba263*/
        audio_convertMonoToStereo(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba272*/
        audio_resample44To22(mixBuffer2, mixBuffer1, 2 * v13, dataFormat); /*0x1ba28a*/
        var2 = mixBuffer1; /*0x1ba28f*/
        goto LABEL_131; /*0x1ba294*/
      }
      if ( v10 != 32 ) /*0x1b9e56*/
        goto LABEL_130; /*0x1b9e56*/
      v13 *= 2; /*0x1b9f2c*/
      if ( v14 < v13 ) /*0x1b9f31*/
        v13 = a3->var1 - (_DWORD)var2; /*0x1b9f33*/
      v26 = v13 >> 1; /*0x1b9f3a*/
      audio_convertStereoToMono(var2, mixBuffer1, v13, dataFormat); /*0x1b9f4d*/
      goto LABEL_119; /*0x1b9f52*/
    }
    if ( v10 == 37 ) /*0x1b9e67*/
    {
      audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba2a6*/
      audio_convertStereoToMono(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba2be*/
      audio_resample22To44(mixBuffer2, mixBuffer1, v13 >> 1, dataFormat); /*0x1ba2d0*/
      goto LABEL_122; /*0x1ba2d0*/
    }
    if ( v10 > 0x25 ) /*0x1b9e6d*/
    {
      if ( v10 != 40 ) /*0x1b9e83*/
        goto LABEL_130; /*0x1b9e83*/
      v13 *= 4; /*0x1b9fb8*/
      if ( v14 < v13 ) /*0x1b9fbe*/
        v13 = a3->var1 - (_DWORD)var2; /*0x1b9fc0*/
      v26 = v13 >> 2; /*0x1b9fc8*/
      audio_convertStereoToMono(var2, mixBuffer1, v13, dataFormat); /*0x1b9fdb*/
      audio_resample44To22(mixBuffer1, mixBuffer2, v13 >> 1, dataFormat); /*0x1b9ff7*/
      goto LABEL_105; /*0x1b9ffc*/
    }
    if ( v10 != 36 ) /*0x1b9e72*/
      goto LABEL_130; /*0x1b9e72*/
    audio_convertStereoToMono(var2, mixBuffer1, v13, dataFormat); /*0x1ba03c*/
    audio_resample22To44(mixBuffer1, mixBuffer2, v13 >> 1, dataFormat); /*0x1ba04c*/
LABEL_97:
    var2 = mixBuffer2; /*0x1ba051*/
    goto LABEL_131; /*0x1ba057*/
  }
  if ( v10 == 5 ) /*0x1b9da3*/
  {
    v13 >>= 1; /*0x1ba15c*/
    audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba165*/
    audio_resample22To44(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba174*/
    goto LABEL_129; /*0x1ba179*/
  }
  if ( v10 <= 5 ) /*0x1b9da9*/
  {
    if ( v10 == 2 ) /*0x1b9dae*/
    {
      v28 = audio_scaleSamples( /*0x1b9f09*/
              var2,
              mixBuffer1,
              v13,
              dataFormat,
              self->super.channelCount,
              self->leftGain,
              self->rightGain);
      var2 = mixBuffer1; /*0x1b9f0c*/
      goto LABEL_131; /*0x1b9f11*/
    }
    if ( v10 <= 2 ) /*0x1b9db4*/
    {
      if ( !v10 ) /*0x1b9db8*/
        goto LABEL_131; /*0x1b9db8*/
      if ( v10 != 1 ) /*0x1b9dc1*/
        goto LABEL_130; /*0x1b9dc1*/
      audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba0b3*/
LABEL_103:
      var2 = mixBuffer1; /*0x1ba0b8*/
      goto LABEL_131; /*0x1ba0bd*/
    }
    if ( v10 != 3 ) /*0x1b9dcf*/
    {
      if ( v10 != 4 ) /*0x1b9dd8*/
        goto LABEL_130; /*0x1b9dd8*/
      v13 >>= 1; /*0x1b9f58*/
      audio_resample22To44(var2, mixBuffer1, v13, dataFormat); /*0x1b9f61*/
LABEL_122:
      var2 = mixBuffer1; /*0x1ba2d5*/
      goto LABEL_131; /*0x1ba2da*/
    }
    audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba0cb*/
    v28 = audio_scaleSamples( /*0x1ba0f4*/
            mixBuffer1,
            mixBuffer2,
            v13,
            dataFormat,
            self->super.channelCount,
            self->leftGain,
            self->rightGain);
LABEL_105:
    var2 = mixBuffer2; /*0x1ba0f7*/
    goto LABEL_131; /*0x1ba0fd*/
  }
  if ( v10 == 16 ) /*0x1b9de7*/
  {
    v13 >>= 1; /*0x1b9f18*/
    audio_convertMonoToStereo(var2, mixBuffer1, v13, dataFormat); /*0x1b9f21*/
    goto LABEL_122; /*0x1b9f26*/
  }
  if ( v10 <= 0x10 ) /*0x1b9ded*/
  {
    if ( v10 != 8 ) /*0x1b9df2*/
    {
      if ( v10 != 9 ) /*0x1b9dfb*/
        goto LABEL_130; /*0x1b9dfb*/
      v13 *= 2; /*0x1ba180*/
      if ( v14 < v13 ) /*0x1ba185*/
        v13 = a3->var1 - (_DWORD)var2; /*0x1ba187*/
      v26 = v13 >> 1; /*0x1ba18e*/
      audio_resample44To22(var2, mixBuffer1, v13, dataFormat); /*0x1ba1a1*/
      audio_swapSamples(mixBuffer1, mixBuffer2, v13 >> 2); /*0x1ba1b1*/
LABEL_114:
      var2 = mixBuffer2; /*0x1ba1b6*/
      goto LABEL_131; /*0x1ba1bc*/
    }
    v13 *= 2; /*0x1b9f68*/
    if ( v14 < v13 ) /*0x1b9f6d*/
      v13 = a3->var1 - (_DWORD)var2; /*0x1b9f6f*/
    v26 = v13 >> 1; /*0x1b9f76*/
    audio_resample44To22(var2, mixBuffer1, v13, dataFormat); /*0x1b9f89*/
LABEL_119:
    var2 = mixBuffer1; /*0x1ba251*/
    goto LABEL_131; /*0x1ba256*/
  }
  if ( v10 == 20 ) /*0x1b9e0b*/
  {
    v13 >>= 2; /*0x1b9f90*/
    audio_convertMonoToStereo(var2, mixBuffer1, v13, dataFormat); /*0x1b9f9a*/
    audio_resample22To44(mixBuffer1, mixBuffer2, 2 * v13, dataFormat); /*0x1b9fac*/
    goto LABEL_114; /*0x1b9fb1*/
  }
  if ( v10 > 0x14 ) /*0x1b9e11*/
  {
    if ( v10 == 21 ) /*0x1b9e27*/
    {
      v13 >>= 2; /*0x1ba1c4*/
      audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba1ce*/
      audio_convertMonoToStereo(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba1dd*/
      audio_resample22To44(mixBuffer2, mixBuffer1, 2 * v13, dataFormat); /*0x1ba1ec*/
      var2 = mixBuffer1; /*0x1ba1f1*/
      goto LABEL_131; /*0x1ba1f6*/
    }
    goto LABEL_130; /*0x1b9e27*/
  }
  if ( v10 == 17 ) /*0x1b9e16*/
  {
    v13 >>= 1; /*0x1ba104*/
    audio_swapSamples(var2, mixBuffer1, v13 >> 1); /*0x1ba10d*/
    audio_convertMonoToStereo(mixBuffer1, mixBuffer2, v13, dataFormat); /*0x1ba11c*/
    goto LABEL_129; /*0x1ba121*/
  }
LABEL_130:
  v20 = a3->var2; /*0x1ba354*/
  IOLog((int)"Audio: unsupported mixing conversion 0x%x\n", v10);
  v25 = 0; /*0x1ba362*/
  var2 = (void *)v20; /*0x1ba36c*/
LABEL_131:
  if ( !v25 ) /*0x1ba373*/
    goto LABEL_141; /*0x1ba373*/
  if ( self->peakEnabled ) /*0x1ba37c*/
  {
    switch ( dataFormat ) /*0x1ba389*/
    {
      case 0: /*0x1ba389*/
        v21 = var2; /*0x1ba39c*/
        audio_linear16_peak(self->super.channelCount, var2, v26, &v30, &v29); /*0x1ba39f*/
LABEL_139:
        var2 = v21; /*0x1ba3ee*/
        break; /*0x1ba3f1*/
      case 3: /*0x1ba389*/
        v21 = var2; /*0x1ba3c2*/
        audio_linear8_peak(self->super.channelCount, var2, v26, &v30, &v29); /*0x1ba3c5*/
        goto LABEL_139; /*0x1ba3ca*/
      case 1: /*0x1ba389*/
        v21 = var2; /*0x1ba3e6*/
        audio_mulaw8_peak(self->super.channelCount, var2, v26, &v30, &v29); /*0x1ba3e9*/
        goto LABEL_139; /*0x1ba3e9*/
    }
  }
  v27 = audio_mix(var2, (void *)a5, v26, dataFormat, a7); /*0x1ba3f4*/
LABEL_141:
  a3->var2 += v13; /*0x1ba40e*/
  v15 = v28; /*0x1ba414*/
  if ( v27 > v28 ) /*0x1ba41a*/
    v15 = v27; /*0x1ba41c*/
  v19 = v30; /*0x1ba42e*/
  v16 = v29; /*0x1ba431*/
  v22 = v15; /*0x1ba434*/
  next = self->xferQueue.next; /*0x1ba43a*/
  if ( &self->xferQueue != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1ba443*/
  {
    while ( a4 != *($2D87D4CA0FCCD4E0D80DDC4A8D8F85EA **)next && *(_DWORD *)next ) /*0x1ba451*/
    {
      next = *((queue_entry **)next + 5); /*0x1ba46c*/
      if ( &self->xferQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1ba472*/
        return v26; /*0x1ba472*/
    }
    *(_DWORD *)next = a4; /*0x1ba456*/
    *((_DWORD *)next + 1) = v13; /*0x1ba458*/
    *((_DWORD *)next + 2) = v19; /*0x1ba45e*/
    *((_DWORD *)next + 3) = v16; /*0x1ba461*/
    *((_DWORD *)next + 4) = v22; /*0x1ba467*/
  }
  return v26; /*0x1ba47a*/
}
