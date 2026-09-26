/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155454. */
int __cdecl mach_port_set_qlimit(int a1, int a2, unsigned int a3)
{
  int result; // eax
  volatile __int32 *v4; // [esp+4h] [ebp-4h] BYREF

  if ( !a1 ) /*0x155463*/
    return 16; /*0x155465*/
  if ( a3 > 0x10 ) /*0x15546f*/
    return 18; /*0x155471*/
  result = ipc_object_translate(a1, a2, 1, &v4); /*0x155483*/
  if ( !result ) /*0x15548d*/
  {
    ipc_port_set_qlimit((int)v4, a3); /*0x155494*/
    _InterlockedExchange(v4, 0); /*0x15549e*/
    return 0; /*0x1554a0*/
  }
  return result; /*0x1554a2*/
}
