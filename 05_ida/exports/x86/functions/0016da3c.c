/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16da3c. */
int (__stdcall *__cdecl sub_16DA3C(int a1, int a2, _DWORD *a3))(_DWORD)
{
  int (__stdcall *result)(_DWORD); // eax

  result = (int (__stdcall *)(_DWORD))a1; /*0x16da40*/
  if ( *(_DWORD *)(a1 + 4) == 24 && *(_BYTE *)(a1 + 3) == 1 ) /*0x16da56*/
  {
    result = (int (__stdcall *)(_DWORD))a3[9]; /*0x16da64*/
    if ( result ) /*0x16da69*/
    {
      result = (int (__stdcall *)(_DWORD))result(*a3); /*0x16da77*/
      *(_DWORD *)(a2 + 28) = -305; /*0x16da79*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16da6b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16da58*/
  }
  return result; /*0x16da80*/
}
