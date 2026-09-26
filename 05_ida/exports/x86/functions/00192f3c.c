/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192f3c. */
int __cdecl byte_swap_disktab_out(int a1)
{
  int i; // edx
  char *v2; // ebx
  int result; // eax
  _BYTE v4[48]; // [esp+Ch] [ebp-30h] BYREF

  sub_192E28(a1); /*0x192f49*/
  for ( i = 0; i <= 7; qmemcpy(&v2[-2 * i], v4, 0x30u) ) /*0x192f4e*/
  {
    v2 = (char *)(a1 + 48 * i + 148); /*0x192f59*/
    qmemcpy(v4, v2, sizeof(v4)); /*0x192f6b*/
    ++i; /*0x192f6d*/
    result = 2 * i; /*0x192f6e*/
  }
  return result; /*0x192f88*/
}
