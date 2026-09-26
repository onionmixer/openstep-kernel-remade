/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181e24. */
int __cdecl kern_IOGetCharValues(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int result; // eax
  int v7; // [esp+4h] [ebp-4h] BYREF

  v7 = a4; /*0x181e34*/
  if ( !a1 ) /*0x181e39*/
    return -705; /*0x181e68*/
  result = +[IODevice getCharValues:forParameter:objectNumber:count:]( /*0x181e59*/
             aIodevice_0,
             sel_getCharValues_forParameter_objectNumber_count_,
             a5,
             a3,
             a2,
             &v7);
  *a6 = v7; /*0x181e61*/
  return result; /*0x181e6d*/
}
