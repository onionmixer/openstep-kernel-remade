/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181d9c. */
int __cdecl kern_IOLookupByDeviceName(int a1, int a2, int a3, int a4)
{
  if ( a1 ) /*0x181da3*/
    return +[IODevice lookupByDeviceName:objectNumber:deviceKind:]( /*0x181dbf*/
             aIodevice_0,
             sel_lookupByDeviceName_objectNumber_deviceKind_,
             a2,
             a3,
             a4);
  else
    return -705; /*0x181dc8*/
}
