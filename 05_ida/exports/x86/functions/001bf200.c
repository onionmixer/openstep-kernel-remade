/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf200. */
int __cdecl sub_1BF200(int a1, int a2)
{
  int result; // eax
  int v3; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf20d*/
  if ( *(_DWORD *)(a1 + 4) == 108 && result == 1 ) /*0x1bf21a*/
  {
    result = 268509186; /*0x1bf228*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 /*0x1bf244*/
      && (result = 272631816, *(_DWORD *)(a1 + 32) == 272631816)
      && (result = 268509186, *(_DWORD *)(a1 + 100) == 268509186) )
    {
      v4 = 4096; /*0x1bf250*/
      result = EvGetParameterChar( /*0x1bf26f*/
                 *(_DWORD *)(a1 + 12),
                 *(_DWORD *)(a1 + 28),
                 a1 + 36,
                 *(_DWORD *)(a1 + 104),
                 a2 + 44,
                 &v4);
      *(_DWORD *)(a2 + 28) = result; /*0x1bf274*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf246*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf277*/
    {
      *(_DWORD *)(a2 + 32) = 805306368; /*0x1bf283*/
      *(_DWORD *)(a2 + 36) = 524296; /*0x1bf28c*/
      *(_DWORD *)(a2 + 40) = 4096; /*0x1bf295*/
      *(_DWORD *)(a2 + 40) = v4; /*0x1bf29b*/
      v3 = v4 + 3; /*0x1bf2a1*/
      LOBYTE(v3) = (v4 + 3) & 0xFC; /*0x1bf2a4*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf2a6*/
      result = v3 + 44; /*0x1bf2aa*/
      *(_DWORD *)(a2 + 4) = result; /*0x1bf2ad*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf21c*/
  }
  return result; /*0x1bf2b0*/
}
