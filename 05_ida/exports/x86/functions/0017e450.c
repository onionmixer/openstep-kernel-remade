/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e450. */
int __cdecl _io_convert_port_in(int a1)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  if ( object_copyin(*(_DWORD *)(active_threads + 12), a1, 6, 0, (int)&v2) ) /*0x17e46b*/
    return v2; /*0x17e474*/
  else
    return 0; /*0x17e47c*/
}
