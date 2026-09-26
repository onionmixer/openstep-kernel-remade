/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d520. */
int __cdecl pcb_init(int a1)
{
  _DWORD *v1; // edx
  int result; // eax

  v1 = (_DWORD *)zalloc(pcb_zone); /*0x18d535*/
  *(_DWORD *)(a1 + 40) = v1; /*0x18d537*/
  qmemcpy(v1, &unk_1D14EC, 0xF4u); /*0x18d547*/
  *v1 = v1 + 2; /*0x18d54c*/
  v1[1] = 104; /*0x18d54e*/
  result = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 12) + 12) + 36) + 4); /*0x18d55e*/
  v1[9] = result; /*0x18d561*/
  v1[29] = (char *)ldt - 0x40000000; /*0x18d570*/
  v1[30] = 24; /*0x18d573*/
  *((_WORD *)v1 + 52) = 32; /*0x18d57a*/
  *((_WORD *)v1 + 8) = 16; /*0x18d580*/
  v1[11] = 512; /*0x18d586*/
  *((_WORD *)v1 + 44) = 16; /*0x18d58d*/
  *((_WORD *)v1 + 42) = 8; /*0x18d593*/
  *((_WORD *)v1 + 46) = 16; /*0x18d599*/
  *((_WORD *)v1 + 40) = 16; /*0x18d59f*/
  *((_WORD *)v1 + 48) = 80; /*0x18d5a5*/
  *((_WORD *)v1 + 50) = 0; /*0x18d5ab*/
  *((_WORD *)v1 + 55) = 104; /*0x18d5b1*/
  return result; /*0x18d5ba*/
}
