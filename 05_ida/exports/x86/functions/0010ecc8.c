/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ecc8. */
int __cdecl ttselect(int a1, int a2)
{
  int v2; // esi
  FILE *v3; // ebx
  int v4; // edx
  int v6; // [esp+Ch] [ebp-4h]

  v2 = ttynty(a1); /*0x10ecdd*/
  v6 = spltty(); /*0x10ece4*/
  if ( a2 == 1 ) /*0x10eced*/
  {
    v3 = *(FILE **)v2; /*0x10ecf8*/
    if ( (*(_BYTE *)(*(_DWORD *)v2 + 63) & 0x20) != 0 ) /*0x10ecfe*/
      ttypend(*(FILE **)v2); /*0x10ed01*/
    v4 = *(_DWORD *)&v3->_flags; /*0x10ed09*/
    if ( (v3->_ur & 0x22) != 0 ) /*0x10ed10*/
    {
      v4 += (int)v3->_p; /*0x10ed12*/
      if ( v4 < *(unsigned __int8 *)(v2 + 21) ) /*0x10ed1a*/
        v4 = 0; /*0x10ed1c*/
    }
    if ( v4 <= 0 && (*(__int16 *)(v2 + 16) < 0 || (*(_BYTE *)(a1 + 64) & 0x10) != 0) ) /*0x10ed2d*/
    {
      if ( selthreadcache((thread_act_t *)(a1 + 40)) ) /*0x10ed33*/
        *(_DWORD *)(a1 + 64) |= 0x800u; /*0x10ed3f*/
      goto LABEL_17; /*0x10ed46*/
    }
  }
  else
  {
    if ( a2 != 2 ) /*0x10ecf2*/
    {
LABEL_17:
      splx(v6); /*0x10ed72*/
      return 0; /*0x10ed7d*/
    }
    if ( *(_DWORD *)(a1 + 24) > ttlowat[*(_BYTE *)(a1 + 74) & 0x1F] ) /*0x10ed59*/
    {
      if ( selthreadcache((thread_act_t *)(a1 + 44)) ) /*0x10ed5f*/
        *(_DWORD *)(a1 + 64) |= 0x1000u; /*0x10ed6b*/
      goto LABEL_17; /*0x10ed6b*/
    }
  }
  splx(v6); /*0x10ed84*/
  return 1; /*0x10ed91*/
}
