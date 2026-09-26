/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f30c. */
int __cdecl ifconf(int a1, unsigned int *a2)
{
  unsigned int v2; // esi
  unsigned int i; // edi
  _BYTE *j; // eax
  _DWORD *v5; // ebx
  int v7; // [esp+Ch] [ebp-38h]
  int v8; // [esp+1Ch] [ebp-28h]
  _BYTE v9[14]; // [esp+24h] [ebp-20h] BYREF
  _BYTE v10[2]; // [esp+32h] [ebp-12h] BYREF
  _DWORD v11[4]; // [esp+34h] [ebp-10h] BYREF

  v8 = ifnet; /*0x11f321*/
  v2 = *a2; /*0x11f324*/
  v7 = 0; /*0x11f326*/
  for ( i = a2[1]; v2 > 0x20; v8 = *(_DWORD *)(v8 + 92) ) /*0x11f339*/
  {
    if ( !v8 ) /*0x11f34c*/
      break; /*0x11f34c*/
    bcopy(*(const void **)v8, v9, 0xEu); /*0x11f35e*/
    for ( j = v9; v10 > j; ++j ) /*0x11f36e*/
    {
      if ( !*j ) /*0x11f370*/
        break; /*0x11f373*/
    }
    *j = *(_BYTE *)(v8 + 8) + 48; /*0x11f384*/
    j[1] = 0; /*0x11f386*/
    v5 = *(_DWORD **)(v8 + 24); /*0x11f38d*/
    if ( v5 ) /*0x11f392*/
    {
      while ( v2 > 0x20 ) /*0x11f3fd*/
      {
        if ( !v5 ) /*0x11f3c2*/
          break; /*0x11f3c2*/
        v11[0] = *v5; /*0x11f3c6*/
        v11[1] = v5[1]; /*0x11f3cc*/
        v11[2] = v5[2]; /*0x11f3d2*/
        v11[3] = v5[3]; /*0x11f3d8*/
        v7 = copyout(v9, i, 32); /*0x11f3e7*/
        if ( v7 ) /*0x11f3ef*/
          break; /*0x11f3ef*/
        v2 -= 32; /*0x11f3f1*/
        i += 32; /*0x11f3f4*/
        v5 = (_DWORD *)v5[9]; /*0x11f3f7*/
      }
    }
    else
    {
      bzero(v11, 0x10u); /*0x11f39a*/
      v7 = copyout(v9, i, 32); /*0x11f3ab*/
      if ( v7 ) /*0x11f3b3*/
        break; /*0x11f3b3*/
      v2 -= 32; /*0x11f3b5*/
      i += 32; /*0x11f3b8*/
    }
  }
  *a2 -= v2; /*0x11f411*/
  return v7; /*0x11f41c*/
}
