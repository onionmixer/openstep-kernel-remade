/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc6ec. */
int __cdecl NXMapRemove(_DWORD *a1, int a2)
{
  unsigned int v2; // eax
  _DWORD *v3; // esi
  unsigned int v4; // ebx
  int v5; // eax
  unsigned int v6; // ecx
  _DWORD *v7; // esi
  int v8; // eax
  int v10; // ebx
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // ecx
  int v15; // [esp+Ch] [ebp-A0h]
  unsigned int v16; // [esp+Ch] [ebp-A0h]
  unsigned int v17; // [esp+14h] [ebp-98h]
  char *v18; // [esp+18h] [ebp-94h]
  int v19; // [esp+1Ch] [ebp-90h]
  unsigned int v20; // [esp+20h] [ebp-8Ch]
  unsigned int v21; // [esp+24h] [ebp-88h]
  int v22; // [esp+28h] [ebp-84h]
  char v23; // [esp+2Ch] [ebp-80h] BYREF

  v22 = a1[3]; /*0x1cc6fe*/
  v2 = (*(int (__cdecl **)(_DWORD *, int))*a1)(a1, a2); /*0x1cc71f*/
  v21 = (65521 * (HIWORD(v2) ^ (unsigned __int16)v2) + v2) % a1[2]; /*0x1cc741*/
  v3 = (_DWORD *)(v22 + 8 * v21); /*0x1cc750*/
  v20 = 1; /*0x1cc753*/
  v15 = 0; /*0x1cc75d*/
  v19 = 0; /*0x1cc767*/
  if ( *v3 == -1 ) /*0x1cc774*/
    return 0; /*0x1cc774*/
  ++dword_1E55A0; /*0x1cc77a*/
  v4 = v21; /*0x1cc780*/
  if ( a2 == *v3 ) /*0x1cc78b*/
    v5 = 1; /*0x1cc7b4*/
  else
    v5 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v3, a2); /*0x1cc7aa*/
  if ( v5 ) /*0x1cc7bb*/
  {
    v15 = 1; /*0x1cc7bd*/
    v19 = v3[1]; /*0x1cc7c6*/
  }
  while ( 1 ) /*0x1cc7cf*/
  {
    v6 = 0; /*0x1cc7cf*/
    if ( a1[2] > v4 + 1 ) /*0x1cc7d7*/
      v6 = v4 + 1; /*0x1cc7d9*/
    v4 = v6; /*0x1cc7db*/
    if ( v21 == v6 ) /*0x1cc7e3*/
      break; /*0x1cc7e3*/
    v7 = (_DWORD *)(v22 + 8 * v6); /*0x1cc7eb*/
    if ( *v7 == -1 ) /*0x1cc7f1*/
      break; /*0x1cc7f1*/
    if ( a2 == *v7 ) /*0x1cc7f8*/
      v8 = 1; /*0x1cc820*/
    else
      v8 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v7, a2); /*0x1cc817*/
    if ( v8 ) /*0x1cc827*/
    {
      ++v15; /*0x1cc829*/
      v19 = v7[1]; /*0x1cc832*/
    }
    ++v20; /*0x1cc838*/
  }
  if ( !v15 ) /*0x1cc847*/
    return 0; /*0x1cc849*/
  if ( v15 != 1 )
    _NXLogError("**** NXMapRemove: incorrect table\n");
  if ( v20 <= 0x10 ) /*0x1cc86d*/
    v18 = &v23; /*0x1cc893*/
  else
    v18 = (char *)malloc(8 * v20 - 8); /*0x1cc885*/
  v10 = 0; /*0x1cc899*/
  v17 = v21; /*0x1cc8a1*/
  v16 = v20 - 1; /*0x1cc8ae*/
  if ( v20 ) /*0x1cc8b7*/
  {
    do /*0x1cc94b*/
    {
      v11 = (_DWORD *)(v22 + 8 * v17); /*0x1cc8cc*/
      if ( a2 == *v11 ) /*0x1cc8d4*/
        v12 = 1; /*0x1cc8fc*/
      else
        v12 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v11, a2); /*0x1cc8f3*/
      if ( !v12 ) /*0x1cc903*/
      {
        v13 = v11[1]; /*0x1cc90d*/
        *(_DWORD *)&v18[8 * v10] = *v11; /*0x1cc910*/
        *(_DWORD *)&v18[8 * v10++ + 4] = v13; /*0x1cc913*/
      }
      *v11 = -1; /*0x1cc918*/
      v11[1] = 0; /*0x1cc91e*/
      v14 = 0; /*0x1cc92c*/
      if ( a1[2] > v17 + 1 ) /*0x1cc934*/
        v14 = v17 + 1; /*0x1cc936*/
      v17 = v14; /*0x1cc938*/
      --v16; /*0x1cc93e*/
    }
    while ( v16 != -1 ); /*0x1cc94b*/
  }
  a1[1] -= v20; /*0x1cc95a*/
  if ( v10 != v20 - 1 )
    _NXLogError("**** NXMapRemove: bug\n");
  while ( --v10 != -1 ) /*0x1cc995*/
    NXMapInsert(a1, *(_DWORD *)&v18[8 * v10], *(_DWORD *)&v18[8 * v10 + 4]); /*0x1cc98d*/
  if ( v20 > 0x10 ) /*0x1cc9a2*/
    free(v18); /*0x1cc9ab*/
  return v19; /*0x1cc9bc*/
}
