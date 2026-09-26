/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e41c. */
int __cdecl _io_get_kern_port(int a1)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  if ( object_copyin(IOTask_kern, a1, 6, 0, (int)&v2) ) /*0x17e435*/
    return v2; /*0x17e43e*/
  else
    return 0; /*0x17e448*/
}
