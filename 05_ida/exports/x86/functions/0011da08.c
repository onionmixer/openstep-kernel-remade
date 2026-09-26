/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11da08. */
int __cdecl utimes(const char *a1, const timeval *a2)
{
  _DWORD *v2; // esi
  int result; // eax
  _BYTE v4[32]; // [esp+8h] [ebp-50h] BYREF
  int v5; // [esp+28h] [ebp-30h]
  int v6; // [esp+2Ch] [ebp-2Ch]
  int v7; // [esp+30h] [ebp-28h]
  int v8; // [esp+34h] [ebp-24h]
  _DWORD v9[4]; // [esp+48h] [ebp-10h] BYREF

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x11da16*/
  result = copyin(v2[1], v9, 16); /*0x11da23*/
  *(_BYTE *)(dword_1E875C + 104) = result; /*0x11da2e*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11da3a*/
  {
    vattr_null(v4); /*0x11da44*/
    v5 = v9[0]; /*0x11da4f*/
    v6 = v9[1]; /*0x11da52*/
    v7 = v9[2]; /*0x11da5b*/
    v8 = v9[3]; /*0x11da5e*/
    result = namesetattr(*v2, 1, v4); /*0x11da67*/
    *(_BYTE *)(dword_1E875C + 104) = result; /*0x11da72*/
  }
  return result; /*0x11da78*/
}
