/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1583d4. */
unsigned int __cdecl ipc_kobject_destroy(int a1)
{
  unsigned int result; // eax

  result = *(unsigned __int16 *)(a1 + 8); /*0x1583da*/
  if ( result == 9 ) /*0x1583e1*/
    return vm_object_pager_wakeup(a1); /*0x158409*/
  if ( result > 9 ) /*0x1583e3*/
  {
    if ( result == 17 ) /*0x1583f3*/
      return netipc_ignore(0, a1); /*0x158417*/
  }
  else if ( result == 8 ) /*0x1583e8*/
  {
    return vm_object_destroy(a1); /*0x1583fd*/
  }
  return result; /*0x1583ec*/
}
