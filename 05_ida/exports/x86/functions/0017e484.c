/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e484. */
int __cdecl _io_convert_port_out(int a1)
{
  int v2; // [esp+4h] [ebp-4h] BYREF

  port_reference(a1); /*0x17e48f*/
  object_copyout(*(_DWORD *)(active_threads + 12), a1, 6, &v2); /*0x17e4a4*/
  return v2; /*0x17e4ac*/
}
