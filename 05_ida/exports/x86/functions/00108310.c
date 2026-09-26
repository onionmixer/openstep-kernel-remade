/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108310. */
int suser()
{
  if ( !**(_DWORD **)(*(_DWORD *)(active_threads + 12) + 56) ) /*0x10831e*/
    return 0; /*0x108323*/
  if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x108335*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x108341*/
    return 0; /*0x108345*/
  }
  else
  {
    *(_BYTE *)(active_u + 580) |= 2u; /*0x10834c*/
    return 1; /*0x108353*/
  }
}
