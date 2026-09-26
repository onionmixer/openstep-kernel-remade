/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181d64. */
int __cdecl kern_IOLookupByObjectNumber(int a1, int a2, int a3, int a4)
{
  if ( a1 ) /*0x181d6b*/
    return +[IODevice lookupByObjectNumber:deviceKind:deviceName:]( /*0x181d87*/
             aIodevice_0,
             sel_lookupByObjectNumber_deviceKind_deviceName_,
             a2,
             a3,
             a4);
  else
    return -705; /*0x181d90*/
}
