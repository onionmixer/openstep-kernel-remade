/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163d28. */
int __cdecl compute_priority(_DWORD *a1, int a2)
{
  int result; // eax

  if ( a1[24] == 2 ) /*0x163d36*/
    return set_pri(a1, a1[20], a2); /*0x163d66*/
  result = a1[20] - (a1[27] >> 25); /*0x163d43*/
  if ( result < 0 ) /*0x163d47*/
    result = 0; /*0x163d49*/
  if ( (int)a1[25] < 0 ) /*0x163d4f*/
    return set_pri(a1, result, a2); /*0x163d53*/
  a1[25] = result; /*0x163d58*/
  return result; /*0x163d6b*/
}
