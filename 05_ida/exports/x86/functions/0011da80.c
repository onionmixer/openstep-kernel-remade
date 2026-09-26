/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11da80. */
char _utime()
{
  _DWORD *v0; // esi
  _DWORD *posix_proc; // ebx
  char result; // al
  int v3; // edx
  _DWORD v4[2]; // [esp+Ch] [ebp-50h] BYREF
  int v5; // [esp+14h] [ebp-48h] BYREF
  int v6; // [esp+18h] [ebp-44h]
  _BYTE v7[32]; // [esp+1Ch] [ebp-40h] BYREF
  int v8; // [esp+3Ch] [ebp-20h]
  int v9; // [esp+40h] [ebp-1Ch]
  int v10; // [esp+44h] [ebp-18h]
  int v11; // [esp+48h] [ebp-14h]

  v0 = *(_DWORD **)(dword_1E875C + 36); /*0x11da8e*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x11daa2*/
  getthetime(&v5); /*0x11daa8*/
  vattr_null(v7); /*0x11dab1*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) == 0 || v0[1] ) /*0x11dac6*/
  {
    *(_BYTE *)(dword_1E875C + 104) = copyin(v0[1], v4, 8); /*0x11dafa*/
    result = dword_1E875C; /*0x11dafd*/
    if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x11db05*/
      return result; /*0x11db09*/
    v8 = v4[0]; /*0x11db0e*/
    v10 = v4[1]; /*0x11db14*/
    v11 = 0; /*0x11db17*/
    v9 = 0; /*0x11db1e*/
  }
  else
  {
    v10 = v5; /*0x11dacf*/
    v8 = v5; /*0x11dad2*/
    v11 = v6; /*0x11dad8*/
    v9 = v6; /*0x11dadb*/
    *((_BYTE *)posix_proc + 24) |= 1u; /*0x11dade*/
  }
  v3 = namesetattr(*v0, 1, v7); /*0x11db33*/
  *((_BYTE *)posix_proc + 24) &= ~1u; /*0x11db35*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 && v3 == 1 && !v0[1] ) /*0x11db55*/
    result = 13; /*0x11db5c*/
  else
    result = v3; /*0x11db57*/
  *(_BYTE *)(dword_1E875C + 104) = result; /*0x11db5e*/
  return result; /*0x11db64*/
}
