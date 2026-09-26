/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161424. */
int __cdecl pset_remove_processor(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edx

  if ( (_DWORD *)a2[75] != a1 ) /*0x161435*/
    panic(aPsetRemoveProc); /*0x16143c*/
  v2 = (_DWORD *)a2[77]; /*0x161444*/
  v3 = (_DWORD *)a2[78]; /*0x16144a*/
  if ( a1 + 71 == v2 ) /*0x161458*/
    a1[72] = v3; /*0x16145a*/
  else
    v2[78] = v3; /*0x161464*/
  if ( a1 + 71 == v3 ) /*0x161472*/
    a1[71] = v2; /*0x161474*/
  else
    v3[77] = v2; /*0x16147c*/
  a2[75] = 0; /*0x161482*/
  --a1[73]; /*0x16148c*/
  return quantum_set(a1); /*0x16149b*/
}
