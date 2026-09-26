/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140548. */
char *__cdecl disksort_init(char *a1)
{
  char v1; // dl

  bzero(a1, 0x28u); /*0x140552*/
  if ( dword_1F50EC ) /*0x140561*/
  {
    v1 = a1[12]; /*0x140563*/
    if ( (v1 & 1) == 0 && *((char **)a1 + 4) == a1 + 16 ) /*0x140571*/
    {
      a1[12] = v1 | 1; /*0x140576*/
      ((void (__stdcall *)(char *))dword_1F50E4)(a1); /*0x14057f*/
    }
  }
  else if ( (a1[12] & 1) != 0 && !dword_1F50DC(a1) ) /*0x140590*/
  {
    a1[12] &= ~1u; /*0x140599*/
    ((void (__stdcall *)(char *))dword_1F50E8)(a1); /*0x1405a3*/
  }
  *((_DWORD *)a1 + 5) = a1 + 16; /*0x1405a8*/
  *((_DWORD *)a1 + 4) = a1 + 16; /*0x1405ab*/
  *((_DWORD *)a1 + 6) = 20; /*0x1405ae*/
  *((_DWORD *)a1 + 9) = 0; /*0x1405b5*/
  return a1 + 16; /*0x1405bc*/
}
