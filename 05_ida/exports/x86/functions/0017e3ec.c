/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e3ec. */
int __cdecl _io_task_get_port(int a1)
{
  int v2; // [esp+4h] [ebp-4h] BYREF

  port_reference(a1); /*0x17e3f7*/
  object_copyout(IOTask_kern, a1, 6, &v2); /*0x17e40a*/
  return v2; /*0x17e412*/
}
