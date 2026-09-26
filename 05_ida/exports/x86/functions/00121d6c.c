/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121d6c. */
int __cdecl rtioctl(int a1, int a2)
{
  if ( (unsigned int)(a1 + 2144308726) > 1 ) /*0x121d7c*/
    return 22; /*0x121d7e*/
  if ( suser() ) /*0x121d88*/
    return rtrequest(a1, a2); /*0x121d96*/
  return *(char *)(dword_1E875C + 104); /*0x121da9*/
}
