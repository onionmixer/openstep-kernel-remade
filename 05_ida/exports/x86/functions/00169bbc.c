/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169bbc. */
int __cdecl calloutEntryRemove(int *a1)
{
  int v1; // edx
  int v2; // eax

  v1 = splsched(); /*0x169bc8*/
  do /*0x169be5*/
  {
    while ( dword_1E7244 ) /*0x169bd3*/
      ; /*0x169bd1*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169be5*/
  v2 = a1[7]; /*0x169be7*/
  if ( v2 == 1 ) /*0x169bed*/
  {
    *(_DWORD *)(*a1 + 4) = a1[1]; /*0x169bf4*/
    *(_DWORD *)a1[1] = *a1; /*0x169bfc*/
    --dword_1E7260; /*0x169bfe*/
  }
  else
  {
    if ( v2 != 2 ) /*0x169c0b*/
      goto LABEL_11; /*0x169c0b*/
    *(_DWORD *)(*a1 + 4) = a1[1]; /*0x169c12*/
    *(_DWORD *)a1[1] = *a1; /*0x169c1a*/
  }
  a1[7] = 0; /*0x169c1c*/
  if ( a1 >= &dword_1E6A44 && a1 < &dword_1E7244 ) /*0x169c31*/
  {
    *a1 = (int)&dword_1E7248; /*0x169c33*/
    a1[1] = dword_1E724C; /*0x169c3f*/
    *(_DWORD *)a1[1] = a1; /*0x169c45*/
    dword_1E724C = (int)a1; /*0x169c47*/
  }
LABEL_11:
  _InterlockedExchange(&dword_1E7244, 0); /*0x169c4d*/
  return splx(v1); /*0x169c5b*/
}
