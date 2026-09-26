/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104a08. */
int __cdecl rewhence(int a1, int a2, int a3)
{
  int result; // eax
  __int16 v4; // ax
  _BYTE v5[24]; // [esp+Ch] [ebp-40h] BYREF
  int v6; // [esp+24h] [ebp-28h]

  if ( *(_WORD *)(a1 + 2) != 2 && a3 != 2 /*0x104a41*/
    || (result = (*(int (__stdcall **)(_DWORD, _BYTE *, _DWORD))(*(_DWORD *)(*(_DWORD *)(a2 + 24) + 28) + 20))(
                   *(_DWORD *)(a2 + 24),
                   v5,
                   *(_DWORD *)(active_u + 28))) == 0 )
  {
    v4 = *(_WORD *)(a1 + 2); /*0x104a43*/
    if ( v4 == 1 ) /*0x104a4b*/
    {
      *(_DWORD *)(a1 + 4) += *(_DWORD *)(a2 + 28); /*0x104a63*/
    }
    else if ( v4 > 1 ) /*0x104a4d*/
    {
      if ( v4 != 2 ) /*0x104a5c*/
        return 22; /*0x104a5c*/
      *(_DWORD *)(a1 + 4) += v6; /*0x104a6b*/
    }
    else if ( v4 ) /*0x104a52*/
    {
      return 22; /*0x104a75*/
    }
    *(_WORD *)(a1 + 2) = a3; /*0x104a7a*/
    if ( (_WORD)a3 == 1 ) /*0x104a82*/
    {
      *(_DWORD *)(a1 + 4) -= *(_DWORD *)(a2 + 28); /*0x104a8f*/
    }
    else if ( (_WORD)a3 == 2 ) /*0x104a88*/
    {
      *(_DWORD *)(a1 + 4) -= v6; /*0x104a97*/
    }
    return 0; /*0x104a9a*/
  }
  return result; /*0x104a9f*/
}
