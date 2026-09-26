/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196e30. */
int kmclose()
{
  int savedregs; // [esp+0h] [ebp+0h]

  ((void (__stdcall *)(FILE *, int))*(&off_1DAFEC + 12 * SHIBYTE(cons._lb._base)))(&cons, savedregs); /*0x196e4b*/
  ttyclose(&cons); /*0x196e52*/
  return 0; /*0x196e5b*/
}
