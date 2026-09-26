/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1163f8. */
int __cdecl sbselqueue(int a1)
{
  int result; // eax

  result = selthreadcache((thread_act_t *)(a1 + 16)); /*0x116403*/
  if ( result ) /*0x11640a*/
    *(_BYTE *)(a1 + 20) |= 0x10u; /*0x11640c*/
  return result; /*0x116410*/
}
