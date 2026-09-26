/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b610. */
int __cdecl dnlc_lookup(int a1, char *a2, int a3)
{
  signed __int32 v4; // ecx
  int v5; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  int v9; // edx
  int *v10; // edx
  int v11; // eax

  if ( !doingcache ) /*0x11b620*/
    return 0; /*0x11b622*/
  v4 = strlen(a2); /*0x11b63c*/
  if ( v4 <= 32 ) /*0x11b642*/
  {
    v5 = ((_BYTE)a1 + (_BYTE)v4 + a2[v4 - 1] + *a2) & 0x3F; /*0x11b665*/
    v6 = sub_11B8DC(a1, a2, v4, v5, a3); /*0x11b673*/
    v7 = (_DWORD *)v6; /*0x11b678*/
    if ( v6 ) /*0x11b67c*/
    {
      ++ncstats; /*0x11b688*/
      *(_DWORD *)(*(_DWORD *)(v6 + 12) + 8) = *(_DWORD *)(v6 + 8); /*0x11b694*/
      *(_DWORD *)(*(_DWORD *)(v6 + 8) + 12) = *(_DWORD *)(v6 + 12); /*0x11b69d*/
      v8 = dword_1E9BEC; /*0x11b6a0*/
      v9 = *(_DWORD *)(dword_1E9BEC + 8); /*0x11b6a5*/
      *(_DWORD *)(dword_1E9BEC + 8) = v7; /*0x11b6a8*/
      v7[2] = v9; /*0x11b6ab*/
      *(_DWORD *)(v9 + 12) = v7; /*0x11b6ae*/
      v7[3] = v8; /*0x11b6b1*/
      v10 = (int *)v7[1]; /*0x11b6bb*/
      if ( v10 != &nc_hash[2 * v5] ) /*0x11b6c0*/
      {
        *(_DWORD *)(*v7 + 4) = v10; /*0x11b6c4*/
        *(_DWORD *)v7[1] = *v7; /*0x11b6cc*/
        v11 = *(_DWORD *)(v7[1] + 4); /*0x11b6d1*/
        *v7 = *(_DWORD *)v11; /*0x11b6d6*/
        v7[1] = v11; /*0x11b6d8*/
        *(_DWORD *)(*(_DWORD *)v11 + 4) = v7; /*0x11b6dd*/
        *(_DWORD *)v11 = v7; /*0x11b6e0*/
      }
      return v7[4]; /*0x11b6e2*/
    }
    else
    {
      ++dword_1E9C04; /*0x11b67e*/
      return 0; /*0x11b684*/
    }
  }
  else
  {
    ++dword_1E9C14; /*0x11b644*/
    return 0; /*0x11b64a*/
  }
}
