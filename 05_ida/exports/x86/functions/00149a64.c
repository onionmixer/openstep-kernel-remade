/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x149a64. */
char __cdecl ipc_kmsg_copyin_compat_from_kernel(_DWORD *a1)
{
  int v1; // ebx
  int v2; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // ebx
  _BOOL4 v6; // esi
  _DWORD *v7; // edi
  _DWORD *v8; // esi
  unsigned int i; // esi
  int v10; // ebx
  unsigned int v12; // [esp+Ch] [ebp-40h]
  int v13; // [esp+10h] [ebp-3Ch]
  _DWORD *v14; // [esp+18h] [ebp-34h]
  _BOOL4 v15; // [esp+1Ch] [ebp-30h]
  unsigned int v16; // [esp+20h] [ebp-2Ch]
  int v17; // [esp+24h] [ebp-28h]
  int v18; // [esp+28h] [ebp-24h]
  unsigned int v19; // [esp+2Ch] [ebp-20h]
  int v20; // [esp+30h] [ebp-1Ch]
  _DWORD v21[6]; // [esp+34h] [ebp-18h] BYREF

  qmemcpy(v21, a1 + 5, sizeof(v21)); /*0x149a7c*/
  v20 = v21[4]; /*0x149a81*/
  v1 = v21[3]; /*0x149a84*/
  ipc_object_copyin_from_kernel(v21[4], 19); /*0x149a8a*/
  if ( v1 && v1 != -1 ) /*0x149a99*/
    ipc_object_copyin_from_kernel(v1, 20); /*0x149a9e*/
  v2 = ipc_object_copyin_type(19); /*0x149aad*/
  v3 = ipc_object_copyin_type(20) << 8; /*0x149ab6*/
  a1[5] = v3 | v2; /*0x149abe*/
  a1[6] = v21[1]; /*0x149ac4*/
  a1[7] = v20; /*0x149aca*/
  a1[8] = v1; /*0x149acd*/
  a1[9] = v21[2]; /*0x149ad3*/
  a1[10] = v21[5]; /*0x149ad9*/
  if ( !HIBYTE(v21[0]) ) /*0x149ae3*/
  {
    v18 = 0; /*0x149ae9*/
    v4 = (unsigned __int8 *)(a1 + 11); /*0x149af3*/
    v3 = (unsigned int)a1 + a1[6] + 20; /*0x149afc*/
    v19 = v3; /*0x149afe*/
    if ( (unsigned int)(a1 + 11) < v3 ) /*0x149b03*/
    {
      do /*0x149c3d*/
      {
        v5 = v4; /*0x149b0c*/
        v6 = (v4[3] & 0x10) != 0; /*0x149b19*/
        v15 = (v4[3] & 0x20) != 0; /*0x149b29*/
        if ( (v4[3] & 0x20) != 0 ) /*0x149b2c*/
        {
          v17 = *((unsigned __int16 *)v4 + 2); /*0x149b32*/
          v13 = *((unsigned __int16 *)v4 + 3); /*0x149b39*/
          v16 = *((_DWORD *)v4 + 2); /*0x149b3f*/
          v7 = v4 + 12; /*0x149b42*/
        }
        else
        {
          v17 = *v4; /*0x149b4b*/
          v13 = v4[1]; /*0x149b52*/
          v16 = *((_WORD *)v4 + 1) & 0xFFF; /*0x149b5f*/
          v7 = v4 + 4; /*0x149b62*/
        }
        v5[3] &= ~0x80u; /*0x149b7c*/
        if ( v15 ) /*0x149b84*/
        {
          *v5 = 0; /*0x149b86*/
          v5[1] = 0; /*0x149b89*/
          *((_WORD *)v5 + 1) &= 0xF000u; /*0x149b8d*/
        }
        v3 = (v13 * v16 + 7) >> 3; /*0x149b9d*/
        if ( v6 ) /*0x149ba2*/
        {
          v8 = v7; /*0x149ba4*/
          v3 += 3; /*0x149ba6*/
          LOBYTE(v3) = v3 & 0xFC; /*0x149ba9*/
          v4 = (unsigned __int8 *)v7 + v3; /*0x149bab*/
        }
        else
        {
          v8 = (_DWORD *)*v7; /*0x149bb0*/
          v4 = (unsigned __int8 *)(v7 + 1); /*0x149bb2*/
          v18 = 1; /*0x149bb5*/
        }
        if ( (unsigned int)(v17 - 5) <= 1 ) /*0x149bc0*/
        {
          v3 = ipc_object_copyin_type(v17); /*0x149bc6*/
          v12 = v3; /*0x149bcb*/
          v14 = v8; /*0x149bce*/
          if ( v15 ) /*0x149bd8*/
            *((_WORD *)v5 + 2) = v3; /*0x149bde*/
          else
            *v5 = v3; /*0x149be7*/
          for ( i = 0; v16 > i; ++i ) /*0x149bee*/
          {
            v10 = v14[i]; /*0x149bf3*/
            if ( v10 ) /*0x149bf8*/
            {
              if ( v10 != -1 ) /*0x149bfd*/
              {
                LOBYTE(v3) = ipc_object_copyin_from_kernel(v10, v17); /*0x149c04*/
                if ( v12 == 16 ) /*0x149c10*/
                {
                  v3 = ipc_port_check_circularity(v10, v20); /*0x149c17*/
                  if ( v3 ) /*0x149c21*/
                    a1[5] |= 0x40000000u; /*0x149c26*/
                }
              }
            }
          }
          v18 = 1; /*0x149c33*/
        }
      }
      while ( v19 > (unsigned int)v4 ); /*0x149c3d*/
    }
    if ( v18 ) /*0x149c47*/
      a1[5] |= 0x80000000; /*0x149c4c*/
  }
  return v3; /*0x149c56*/
}
