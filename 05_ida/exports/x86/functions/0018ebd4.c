/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ebd4. */
__int32 __cdecl pcb_terminate(int a1)
{
  int v1; // ebx
  int v2; // eax

  v1 = *(_DWORD *)(a1 + 40); /*0x18ebdc*/
  fp_terminate(a1); /*0x18ebe0*/
  if ( *(_DWORD *)(v1 + 236) ) /*0x18ebe8*/
    PCdestroy(a1); /*0x18ebf2*/
  v2 = *(_DWORD *)(v1 + 112); /*0x18ebfa*/
  if ( v2 ) /*0x18ebff*/
    kfree(v2, 0xE0u); /*0x18ec07*/
  if ( (*(_BYTE *)(v1 + 240) & 4) != 0 ) /*0x18ec16*/
    kfree(*(_DWORD *)(v1 + 8), *(_DWORD *)(v1 + 12)); /*0x18ec20*/
  *(_DWORD *)(a1 + 40) = 0; /*0x18ec28*/
  return zfree(pcb_zone, (_DWORD *)v1); /*0x18ec3f*/
}
