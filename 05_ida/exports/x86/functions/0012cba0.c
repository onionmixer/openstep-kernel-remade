/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cba0. */
int nfs_getfh()
{
  int *v0; // edi
  int result; // eax
  unsigned int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch] BYREF
  int v9; // [esp+14h] [ebp-28h] BYREF
  int v10; // [esp+18h] [ebp-24h] BYREF
  _BYTE v11[32]; // [esp+1Ch] [ebp-20h] BYREF

  v0 = *(int **)(dword_1E875C + 36); /*0x12cbae*/
  v7 = 0; /*0x12cbb1*/
  if ( !suser() ) /*0x12cbb8*/
  {
    result = dword_1E875C; /*0x12cbc1*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x12cbc6*/
    return result; /*0x12cbca*/
  }
  v2 = *v0; /*0x12cbd0*/
  if ( (unsigned int)*v0 <= 0xFF ) /*0x12cbd8*/
  {
    v7 = 1; /*0x12cbda*/
    v3 = getf(v2); /*0x12cbe2*/
    if ( !v3 || *(_UNKNOWN **)(v3 + 20) != &vnodefops ) /*0x12cbf5*/
    {
      result = dword_1E875C; /*0x12cbf7*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x12cbfc*/
      return result; /*0x12cc00*/
    }
    v9 = *(_DWORD *)(v3 + 24); /*0x12cc0b*/
    v10 = 0; /*0x12cc0e*/
    goto LABEL_16; /*0x12cc15*/
  }
  *(_BYTE *)(dword_1E875C + 104) = lookupname(v2, 0, 1, (int)&v10, (int)&v9); /*0x12cc35*/
  if ( *(_BYTE *)(dword_1E875C + 104) == 17 ) /*0x12cc44*/
  {
    *(_BYTE *)(dword_1E875C + 104) = lookupname(*v0, 0, 1, 0, (int)&v9); /*0x12cc5c*/
    v10 = 0; /*0x12cc5f*/
  }
  result = dword_1E875C; /*0x12cc69*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x12cc6e*/
  {
    if ( !v9 ) /*0x12cc7c*/
    {
      if ( v10 ) /*0x12cc83*/
        vn_rele(v10); /*0x12cc86*/
      *(_BYTE *)(dword_1E875C + 104) = 2; /*0x12cc93*/
    }
    result = dword_1E875C; /*0x12cc97*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x12cc9c*/
    {
LABEL_16:
      v4 = findexivp(&v8, v10, v9); /*0x12cca2*/
      LOBYTE(v5) = v4; /*0x12ccb3*/
      if ( !v4 ) /*0x12ccba*/
      {
        v6 = makefh(v11, v9, v8); /*0x12ccc8*/
        LOBYTE(v5) = v6; /*0x12cccd*/
        if ( !v6 ) /*0x12ccd4*/
          v5 = (unsigned __int8)copyout(v11, v0[1], 32); /*0x12cce2*/
      }
      if ( !v7 ) /*0x12cceb*/
      {
        vn_rele(v9); /*0x12ccf1*/
        if ( v10 ) /*0x12ccfe*/
          vn_rele(v10); /*0x12cd01*/
      }
      result = dword_1E875C; /*0x12cd06*/
      *(_BYTE *)(dword_1E875C + 104) = v5; /*0x12cd0b*/
    }
  }
  return result; /*0x12cd11*/
}
