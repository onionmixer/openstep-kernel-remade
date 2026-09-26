/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b438. */
_DWORD *__cdecl timevalfix(_DWORD *a1)
{
  _DWORD *result; // eax

  result = a1; /*0x10b43b*/
  if ( (int)a1[1] < 0 ) /*0x10b442*/
  {
    --*a1; /*0x10b444*/
    a1[1] += 1000000; /*0x10b446*/
  }
  if ( (int)a1[1] > 999999 ) /*0x10b454*/
  {
    ++*a1; /*0x10b456*/
    a1[1] -= 1000000; /*0x10b458*/
  }
  return result; /*0x10b461*/
}
