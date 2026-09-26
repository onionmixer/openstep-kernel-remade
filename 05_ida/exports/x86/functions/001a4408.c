/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4408. */
int __cdecl +[IODevice blockMajor](id a1, SEL a2)
{
  int *v3; // [esp+0h] [ebp-4h] BYREF

  if ( sub_1A3E30((int)a1, &v3) ) /*0x1a4416*/
    return -1; /*0x1a441f*/
  else
    return v3[2]; /*0x1a442b*/
}
