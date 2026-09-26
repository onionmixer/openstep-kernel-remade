/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b984. */
int __cdecl vno_rw(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // ebx
  int result; // eax
  int v5; // edx
  int v6; // eax
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v3 = (_DWORD *)a1[6]; /*0x11b993*/
  if ( a2 == 1 && isrofile(v3) ) /*0x11b99d*/
    return 30; /*0x11b9a9*/
  v8 = *(_DWORD *)(a3 + 20); /*0x11b9b7*/
  v7 = v3[10]; /*0x11b9bf*/
  v5 = v7 == 1; /*0x11b9c7*/
  v6 = a1[2]; /*0x11b9c8*/
  if ( (v6 & 8) != 0 ) /*0x11b9cd*/
    LOBYTE(v5) = v5 | 2; /*0x11b9cf*/
  if ( (v6 & 0x40000) != 0 ) /*0x11b9d7*/
    LOBYTE(v5) = v5 | 4; /*0x11b9d9*/
  if ( v7 == 8 ) /*0x11b9e0*/
    *(_WORD *)(a3 + 16) = v6; /*0x11b9e2*/
  if ( v3[10] == 1 && (*(_BYTE *)(*v3 + 56) & 0x10) != 0 && (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) == 0 ) /*0x11b9ff*/
    result = mfs_io(v3, a3, a2, v5, a1[8]); /*0x11ba0c*/
  else
    result = (*(int (__cdecl **)(_DWORD *, int, int, int, _DWORD))(v3[7] + 8))(v3, a3, a2, v5, a1[8]); /*0x11ba25*/
  if ( !result ) /*0x11ba29*/
  {
    if ( (a1[2] & 8) != 0 || v3[10] == 8 ) /*0x11ba35*/
      a1[7] = *(_DWORD *)(a3 + 8) - (v8 - *(_DWORD *)(a3 + 20)); /*0x11ba42*/
    return 0; /*0x11ba45*/
  }
  return result; /*0x11ba4a*/
}
