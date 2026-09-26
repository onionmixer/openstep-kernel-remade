/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104aa8. */
int __cdecl flock(int a1, int a2)
{
  _DWORD *v2; // ecx
  int result; // eax
  int v4; // edx
  char v5; // dl

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x104ab2*/
  if ( *(_DWORD *)(active_u + 348) <= *v2 /*0x104ad7*/
    || (result = *(_DWORD *)(active_u + 336), (v4 = *(_DWORD *)(result + 4 * *v2)) == 0)
    || v4 == -65536 )
  {
    result = dword_1E875C; /*0x104ad9*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x104ade*/
    return result; /*0x104ae2*/
  }
  if ( *(_WORD *)(v4 + 12) != 1 ) /*0x104ae9*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 45; /*0x104aeb*/
    return result; /*0x104aef*/
  }
  result = v2[1]; /*0x104af4*/
  if ( (result & 8) != 0 ) /*0x104af9*/
    return vno_bsd_unlock(v4, 384); /*0x104b06*/
  if ( (result & 2) != 0 ) /*0x104b0a*/
  {
    LOBYTE(result) = result & 0xFE; /*0x104b18*/
    v2[1] = result; /*0x104b1a*/
  }
  else if ( (result & 1) == 0 ) /*0x104b0e*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x104b10*/
    return result; /*0x104b14*/
  }
  v5 = vno_bsd_lock(v4, v2[1]); /*0x104b27*/
  result = dword_1E875C; /*0x104b29*/
  *(_BYTE *)(dword_1E875C + 104) = v5; /*0x104b2e*/
  return result; /*0x104b31*/
}
