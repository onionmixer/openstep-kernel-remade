/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11dbb8. */
int __cdecl ftruncate(int a1, off_t a2)
{
  int result; // eax
  _DWORD *v3; // edi
  char v4; // dl
  int v5; // esi
  char v6; // dl
  int v7; // [esp-4h] [ebp-54h]
  _BYTE v8[24]; // [esp+Ch] [ebp-44h] BYREF
  int v9; // [esp+24h] [ebp-2Ch]
  int v10; // [esp+4Ch] [ebp-4h] BYREF

  result = dword_1E875C; /*0x11dbc1*/
  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x11dbc6*/
  if ( (int)v3[1] >= 0 ) /*0x11dbcd*/
  {
    v4 = getvnodefp(*v3, &v10); /*0x11dbe4*/
    result = dword_1E875C; /*0x11dbe6*/
    *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11dbeb*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11dbf7*/
    {
      result = v10; /*0x11dbfd*/
      v5 = *(_DWORD *)(v10 + 24); /*0x11dc00*/
      if ( (*(_BYTE *)(v10 + 8) & 2) != 0 ) /*0x11dc07*/
      {
        result = *(_DWORD *)(v5 + 36); /*0x11dc10*/
        if ( (*(_BYTE *)(result + 12) & 1) != 0 ) /*0x11dc17*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 30; /*0x11dc19*/
        }
        else
        {
          vattr_null(v8); /*0x11dc24*/
          v9 = v3[1]; /*0x11dc2c*/
          v6 = (*(int (__stdcall **)(int, _BYTE *, _DWORD, int))(*(_DWORD *)(v5 + 28) + 24))( /*0x11dc40*/
                 v5,
                 v8,
                 *(_DWORD *)(v10 + 32),
                 v7);
          result = dword_1E875C; /*0x11dc42*/
          *(_BYTE *)(dword_1E875C + 104) = v6; /*0x11dc47*/
        }
      }
      else
      {
        *(_BYTE *)(dword_1E875C + 104) = 22; /*0x11dc09*/
      }
    }
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x11dbcf*/
  }
  return result; /*0x11dc4d*/
}
