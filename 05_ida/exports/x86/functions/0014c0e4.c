/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c0e4. */
int __cdecl ipc_object_copyout_type_compat(unsigned int a1)
{
  if ( a1 == 16 ) /*0x14c0ed*/
    return 5; /*0x14c100*/
  if ( a1 < 0x10 || a1 > 0x12 ) /*0x14c0f4*/
    panic(aIpcObjectCopyo_0); /*0x14c111*/
  return 6; /*0x14c0fd*/
}
