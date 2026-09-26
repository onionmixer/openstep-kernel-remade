/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4434. */
void __cdecl +[IODevice setBlockMajor:](id a1, SEL a2, int a3)
{
  int *v3; // [esp+0h] [ebp-4h] BYREF

  if ( !sub_1A3E30((int)a1, &v3) ) /*0x1a4442*/
    v3[2] = a3; /*0x1a4451*/
}
