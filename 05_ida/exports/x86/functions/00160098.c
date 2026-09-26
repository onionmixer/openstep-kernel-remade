/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160098. */
char __cdecl vm_set_close_flush(int a1, int a2)
{
  char result; // al

  result = (4 * (a2 != 0)) | *(_BYTE *)(*(_DWORD *)a1 + 56) & 0xFB; /*0x1600af*/
  *(_BYTE *)(*(_DWORD *)a1 + 56) = result; /*0x1600b1*/
  return result; /*0x1600b6*/
}
