/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b54c. */
char __cdecl lock_init(_DWORD *a1, char a2)
{
  char result; // al

  bzero(a1, 0xCu); /*0x15b556*/
  a1[2] = 0; /*0x15b55b*/
  *((_BYTE *)a1 + 6) &= 0xFCu; /*0x15b562*/
  *((_WORD *)a1 + 2) = 0; /*0x15b566*/
  result = (8 * (a2 & 1)) | *((_BYTE *)a1 + 6) & 0xF7; /*0x15b57a*/
  *((_BYTE *)a1 + 6) = result; /*0x15b57c*/
  *a1 = -1; /*0x15b57f*/
  *((_WORD *)a1 + 3) &= 0xFu; /*0x15b585*/
  return result; /*0x15b58a*/
}
