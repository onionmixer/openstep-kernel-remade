/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192ee0. */
int __cdecl byte_swap_disktab_in(int a1)
{
  int v1; // ebx
  int v2; // edx
  int v4; // [esp+Ch] [ebp-34h]
  _BYTE v5[48]; // [esp+10h] [ebp-30h] BYREF

  v4 = 7; /*0x192ee9*/
  v1 = 16; /*0x192ef0*/
  v2 = 484; /*0x192ef5*/
  do /*0x192f26*/
  {
    qmemcpy(v5, (const void *)(v2 + a1 - v1), sizeof(v5)); /*0x192f0e*/
    qmemcpy((void *)(v2 + a1), v5, 0x30u); /*0x192f1b*/
    v1 -= 2; /*0x192f1d*/
    v2 -= 48; /*0x192f20*/
    --v4; /*0x192f23*/
  }
  while ( v4 >= 0 ); /*0x192f26*/
  return sub_192E28(a1); /*0x192f34*/
}
