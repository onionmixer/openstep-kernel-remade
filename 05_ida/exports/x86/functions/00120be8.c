/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120be8. */
int __cdecl if_ioctl(int a1, unsigned int a2, int a3)
{
  int (__stdcall *v3)(int, const char *, int); // ebx
  _DWORD v5[2]; // [esp+8h] [ebp-8h] BYREF

  v3 = *(int (__stdcall **)(int, const char *, int))(a1 + 56); /*0x120bfb*/
  if ( !v3 ) /*0x120c00*/
    return 6; /*0x120c07*/
  if ( a2 == -2145359567 ) /*0x120c12*/
    return v3(a1, "add-multicast", a3); /*0x120c89*/
  if ( a2 > 0x80206931 ) /*0x120c14*/
  {
    if ( a2 == -1071617779 ) /*0x120c2e*/
      return v3(a1, "getaddr", a3 + 16); /*0x120c6c*/
    if ( a2 > 0xC020690D ) /*0x120c30*/
    {
      if ( a2 == -1071617759 ) /*0x120c42*/
        return v3(a1, "autoaddr", a3 + 16); /*0x120c50*/
    }
    else if ( a2 == -2145359566 ) /*0x120c38*/
    {
      return v3(a1, "rmv-multicast", a3); /*0x120c95*/
    }
  }
  else
  {
    if ( a2 == -2145359604 ) /*0x120c1c*/
      return v3(a1, "setaddr", a3); /*0x120c5d*/
    if ( a2 == -2145359600 ) /*0x120c24*/
      return v3(a1, "setflags", a3 + 16); /*0x120c7c*/
  }
  v5[0] = a2; /*0x120c98*/
  v5[1] = a3; /*0x120c9b*/
  return (*(int (__stdcall **)(int, const char *, _DWORD *))(a1 + 56))(a1, "unix-ioctl", v5); /*0x120cb0*/
}
