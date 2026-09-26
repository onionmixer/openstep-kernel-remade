/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b04b8. */
id __cdecl -[EventDriver postEvent:at:atTime:withData:](
        __int16 *a1,
        int a2,
        int a3,
        __int16 *a4,
        unsigned int a5,
        _DWORD *a6)
{
  int v6; // ebx
  id result; // eax
  int v8; // edx
  __int16 v9; // ax
  int v10; // edx
  __int16 v11; // ax
  int v12; // edx
  int v13; // edx
  int v14; // eax
  const char *v15; // eax
  __int16 *v16; // [esp+Ch] [ebp-18h]
  _BOOL4 v17; // [esp+18h] [ebp-Ch]
  int v18; // [esp+1Ch] [ebp-8h]
  int v19; // [esp+20h] [ebp-4h]

  v16 = *((__int16 **)a1 + 90); /*0x1b04ca*/
  v19 = (int)&v16[22 * *v16 + 40]; /*0x1b04db*/
  v18 = (int)&v16[22 * v16[2] + 40]; /*0x1b04ed*/
  v6 = (int)&v16[22 * v16[1] + 40]; /*0x1b04fb*/
  if ( ((8190 >> a3) & 1) != 0 ) /*0x1b050b*/
  {
    *((_DWORD *)a1 + 105) = *((_DWORD *)a1 + 104) + a5; /*0x1b0516*/
    if ( *((_BYTE *)a1 + 467) ) /*0x1b051c*/
      objc_msgSend(a1, sel_undoAutoDim); /*0x1b052d*/
  }
  if ( a5 > *((_DWORD *)v16 + 4) && a5 < *((_DWORD *)v16 + 4) + 320 ) /*0x1b054b*/
    *((_DWORD *)v16 + 4) = a5; /*0x1b0550*/
  v17 = 0; /*0x1b0553*/
  if ( *((_BYTE *)a1 + 466) ) /*0x1b055a*/
    v17 = **((_WORD **)a1 + 90) != *(_WORD *)(*((_DWORD *)a1 + 90) + 2); /*0x1b0575*/
  if ( (*((_BYTE *)v16 + 51) & 0x40) == 0 && v19 != v6 && *(_DWORD *)(v18 + 8) == a3 && ((736 >> a3) & 1) != 0 ) /*0x1b05a5*/
  {
    result = (id)ev_try_lock((volatile signed __int32 *)(v18 + 4)); /*0x1b05b1*/
    if ( result ) /*0x1b05bb*/
    {
      *(_DWORD *)(v18 + 12) = *a4; /*0x1b05c6*/
      *(_DWORD *)(v18 + 16) = a4[1]; /*0x1b05d3*/
      *(_DWORD *)(v18 + 20) = a5; /*0x1b05d9*/
      if ( a6 ) /*0x1b05e0*/
      {
        *(_DWORD *)(v18 + 32) = *a6; /*0x1b05ea*/
        *(_DWORD *)(v18 + 36) = a6[1]; /*0x1b05f6*/
        *(_DWORD *)(v18 + 40) = a6[2]; /*0x1b0602*/
      }
      ev_unlock((_DWORD *)(v18 + 4)); /*0x1b0609*/
      return result; /*0x1b060e*/
    }
  }
  if ( *(_DWORD *)v6 == *v16 )
  {
    v15 = (const char *)objc_msgSend(a1, sel_name); /*0x1b0830*/
    IOLog((int)"%s: postEvent LLEventQueue overflow.\n", v15);
    return objc_msgSend(a1, sel_kickEventConsumer); /*0x1b0848*/
  }
  *(_DWORD *)(v6 + 8) = a3; /*0x1b0626*/
  *(_DWORD *)(v6 + 12) = *a4; /*0x1b062f*/
  *(_DWORD *)(v6 + 16) = a4[1]; /*0x1b0639*/
  *(_DWORD *)(v6 + 24) = *((_DWORD *)v16 + 3); /*0x1b0642*/
  *(_DWORD *)(v6 + 20) = a5; /*0x1b0648*/
  *(_DWORD *)(v6 + 28) = 0; /*0x1b064b*/
  if ( a6 ) /*0x1b0656*/
  {
    *(_DWORD *)(v6 + 32) = *a6; /*0x1b065d*/
    *(_DWORD *)(v6 + 36) = a6[1]; /*0x1b0666*/
    *(_DWORD *)(v6 + 40) = a6[2]; /*0x1b066f*/
  }
  if ( a3 == 2 ) /*0x1b0676*/
  {
    *(_WORD *)(v6 + 34) = a1[250]; /*0x1b06fb*/
    a1[250] = 0; /*0x1b06ff*/
  }
  else if ( a3 > 2 ) /*0x1b0678*/
  {
    if ( a3 == 3 ) /*0x1b068c*/
    {
      v10 = *((_DWORD *)a1 + 90); /*0x1b06c8*/
      do /*0x1b06e1*/
        ++*(_WORD *)(v10 + 6); /*0x1b06d6*/
      while ( !*(_WORD *)(v10 + 6) ); /*0x1b06e1*/
      v11 = *(_WORD *)(v10 + 6); /*0x1b06e3*/
      a1[251] = v11; /*0x1b06e7*/
      *(_WORD *)(v6 + 34) = v11; /*0x1b06ee*/
    }
    else if ( a3 == 4 ) /*0x1b0692*/
    {
      *(_WORD *)(v6 + 34) = a1[251]; /*0x1b0713*/
      a1[251] = 0; /*0x1b0717*/
    }
  }
  else if ( a3 == 1 ) /*0x1b067e*/
  {
    v8 = *((_DWORD *)a1 + 90); /*0x1b069c*/
    do /*0x1b06b5*/
      ++*(_WORD *)(v8 + 6); /*0x1b06aa*/
    while ( !*(_WORD *)(v8 + 6) ); /*0x1b06b5*/
    v9 = *(_WORD *)(v8 + 6); /*0x1b06b7*/
    a1[250] = v9; /*0x1b06bb*/
    *(_WORD *)(v6 + 34) = v9; /*0x1b06c2*/
  }
  if ( ((102 >> a3) & 1) != 0 ) /*0x1b072c*/
    *(_BYTE *)(v6 + 40) = *((_BYTE *)a1 + 448); /*0x1b0734*/
  if ( ((30 >> a3) & 1) != 0 ) /*0x1b0743*/
  {
    if ( *((_DWORD *)a1 + 111) < a5 - *((_DWORD *)a1 + 110) ) /*0x1b0758*/
      goto LABEL_50; /*0x1b0758*/
    v12 = *a4 - a1[214]; /*0x1b0767*/
    if ( v12 < 0 ) /*0x1b0769*/
      v12 = a1[214] - *a4; /*0x1b076b*/
    if ( v12 > a1[216] ) /*0x1b0776*/
      goto LABEL_50; /*0x1b0776*/
    v13 = a4[1] - a1[215]; /*0x1b0786*/
    if ( v13 < 0 ) /*0x1b0788*/
      v13 = a1[215] - a4[1]; /*0x1b078a*/
    if ( v13 > a1[217] ) /*0x1b0795*/
    {
LABEL_50:
      if ( a3 == 1 || a3 == 3 ) /*0x1b07da*/
      {
        *((_DWORD *)a1 + 107) = *(_DWORD *)a4; /*0x1b07e1*/
        *((_DWORD *)a1 + 110) = a5; /*0x1b07ea*/
        *((_DWORD *)a1 + 109) = 1; /*0x1b07f0*/
        *(_DWORD *)(v6 + 36) = 1; /*0x1b07fa*/
      }
      else
      {
        *(_DWORD *)(v6 + 36) = 0; /*0x1b0804*/
      }
    }
    else if ( a3 == 1 || a3 == 3 ) /*0x1b07a1*/
    {
      *((_DWORD *)a1 + 110) = a5; /*0x1b07a6*/
      v14 = *((_DWORD *)a1 + 109); /*0x1b07ac*/
      *((_DWORD *)a1 + 109) = v14 + 1; /*0x1b07b5*/
      *(_DWORD *)(v6 + 36) = v14 + 1; /*0x1b07bc*/
    }
    else
    {
      *(_DWORD *)(v6 + 36) = *((_DWORD *)a1 + 109); /*0x1b07ca*/
    }
  }
  v16[1] = *(_DWORD *)v6; /*0x1b0810*/
  result = *(id *)v18; /*0x1b0817*/
  v16[2] = *(_DWORD *)v18; /*0x1b0819*/
  if ( !v17 ) /*0x1b0821*/
    return objc_msgSend(a1, sel_kickEventConsumer); /*0x1b0821*/
  return result; /*0x1b0850*/
}
