/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1973c4. */
int __cdecl alert(int a1, int a2, int a3, char *a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  char v13[200]; // [esp+8h] [ebp-C8h] BYREF

  sprintf(v13, a4, a5, a6, a7, a8, a9, a10, a11, a12); /*0x1973fd*/
  DoAlert(a3, v13); /*0x197407*/
  return 0; /*0x197414*/
}
