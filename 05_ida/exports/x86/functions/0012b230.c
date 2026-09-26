/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b230. */
int __cdecl tcp_usrclosed(int a1)
{
  int v1; // ebx

  v1 = a1; /*0x12b234*/
  switch ( *(_WORD *)(a1 + 8) ) /*0x12b240*/
  {
    case 0: /*0x12b240*/
    case 1: /*0x12b240*/
    case 2: /*0x12b240*/
      *(_WORD *)(a1 + 8) = 0; /*0x12b260*/
      v1 = tcp_close((_DWORD *)a1); /*0x12b26c*/
      break; /*0x12b271*/
    case 3: /*0x12b240*/
    case 4: /*0x12b240*/
      *(_WORD *)(a1 + 8) = 6; /*0x12b274*/
      break; /*0x12b27a*/
    case 5: /*0x12b240*/
      *(_WORD *)(a1 + 8) = 8; /*0x12b27c*/
      break; /*0x12b27c*/
    default:
      break;
  }
  if ( v1 && *(__int16 *)(v1 + 8) > 8 ) /*0x12b28b*/
    soisdisconnected(*(_DWORD *)(*(_DWORD *)(v1 + 32) + 28)); /*0x12b294*/
  return v1; /*0x12b29b*/
}
