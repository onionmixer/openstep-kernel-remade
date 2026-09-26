/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14839c. */
char __cdecl ipc_kmsg_copyin_from_kernel(_DWORD *a1)
{
  int v1; // ebx
  int v2; // esi
  int v3; // esi
  int v4; // edx
  unsigned int v5; // eax
  signed int v6; // ebx
  unsigned __int8 *v7; // edi
  _BOOL4 v8; // ebx
  _BOOL4 v9; // esi
  _DWORD *v10; // edi
  int v11; // edx
  _DWORD *v12; // ebx
  int v13; // edx
  unsigned int i; // esi
  int v15; // ebx
  unsigned int v17; // [esp+Ch] [ebp-24h]
  int v18; // [esp+10h] [ebp-20h]
  _DWORD *v19; // [esp+14h] [ebp-1Ch]
  unsigned int v20; // [esp+18h] [ebp-18h]
  int v21; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v22; // [esp+20h] [ebp-10h]
  unsigned int v23; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h]
  int v25; // [esp+2Ch] [ebp-4h]

  v1 = a1[5]; /*0x1483a8*/
  v25 = (unsigned __int16)(v1 & 0xFF00) >> 8; /*0x1483b8*/
  v24 = a1[7]; /*0x1483be*/
  v2 = a1[8]; /*0x1483c4*/
  ipc_object_copyin_from_kernel(v24, (unsigned __int8)v1); /*0x1483cc*/
  if ( v2 && v2 != -1 ) /*0x1483db*/
    ipc_object_copyin_from_kernel(v2, v25); /*0x1483e2*/
  if ( v1 == -2147483629 ) /*0x1483f0*/
  {
    a1[5] = -2147483631; /*0x1483f5*/
  }
  else
  {
    v3 = ipc_object_copyin_type((unsigned __int8)v1); /*0x148406*/
    v4 = ipc_object_copyin_type(v25); /*0x148411*/
    LOBYTE(v5) = 0; /*0x148415*/
    v6 = v3 | (v4 << 8) | v1 & 0xFFFF0000; /*0x148421*/
    a1[5] = v6; /*0x148426*/
    if ( v6 >= 0 ) /*0x14842e*/
      return v5; /*0x14842e*/
  }
  v7 = (unsigned __int8 *)(a1 + 11); /*0x148437*/
  v5 = (unsigned int)a1 + a1[6] + 20; /*0x148443*/
  v23 = v5; /*0x148445*/
  if ( (unsigned int)(a1 + 11) < v5 ) /*0x14844a*/
  {
    do /*0x148551*/
    {
      v22 = v7; /*0x148450*/
      v8 = (v7[3] & 0x10) != 0; /*0x14845d*/
      v9 = (v7[3] & 0x20) != 0; /*0x148468*/
      if ( (v7[3] & 0x20) != 0 ) /*0x14846a*/
      {
        v21 = *((unsigned __int16 *)v7 + 2); /*0x148470*/
        v5 = *((unsigned __int16 *)v7 + 3); /*0x148473*/
        v20 = *((_DWORD *)v7 + 2); /*0x14847a*/
        v10 = v7 + 12; /*0x14847d*/
      }
      else
      {
        v21 = *v7; /*0x148487*/
        v5 = v7[1]; /*0x14848a*/
        v20 = *((_WORD *)v7 + 1) & 0xFFF; /*0x148498*/
        v10 = v7 + 4; /*0x14849b*/
      }
      v17 = (v20 * v5 + 7) >> 3; /*0x1484a8*/
      LOBYTE(v5) = (unsigned int)(v21 - 16) <= 5; /*0x1484b4*/
      v11 = (unsigned __int8)v5; /*0x1484b7*/
      if ( v8 ) /*0x1484bc*/
      {
        v12 = v10; /*0x1484be*/
        v5 = v17 + 3; /*0x1484c3*/
        LOBYTE(v5) = (v17 + 3) & 0xFC; /*0x1484c6*/
        v7 = (unsigned __int8 *)v10 + v5; /*0x1484c8*/
      }
      else
      {
        v12 = (_DWORD *)*v10; /*0x1484cc*/
        v7 = (unsigned __int8 *)(v10 + 1); /*0x1484ce*/
      }
      if ( v11 ) /*0x1484d3*/
      {
        v5 = ipc_object_copyin_type(v21); /*0x1484d9*/
        v13 = v5; /*0x1484de*/
        v19 = v12; /*0x1484e0*/
        if ( v9 ) /*0x1484e8*/
          *((_WORD *)v22 + 2) = v5; /*0x1484ed*/
        else
          *v22 = v5; /*0x1484f7*/
        for ( i = 0; v20 > i; ++i ) /*0x1484fe*/
        {
          v15 = v19[i]; /*0x148503*/
          if ( v15 ) /*0x148508*/
          {
            if ( v15 != -1 ) /*0x14850d*/
            {
              v18 = v13; /*0x148514*/
              LOBYTE(v5) = ipc_object_copyin_from_kernel(v15, v21); /*0x148517*/
              v13 = v18; /*0x14851f*/
              if ( v18 == 16 ) /*0x148525*/
              {
                v5 = ipc_port_check_circularity(v15, v24); /*0x14852f*/
                v13 = 16; /*0x148537*/
                if ( v5 ) /*0x14853c*/
                  a1[5] |= 0x40000000u; /*0x148541*/
              }
            }
          }
        }
      }
    }
    while ( v23 > (unsigned int)v7 ); /*0x148551*/
  }
  return v5; /*0x14855a*/
}
