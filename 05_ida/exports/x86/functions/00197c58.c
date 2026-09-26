/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197c58. */
int BasicAllocateConsole()
{
  int result; // eax
  _DWORD v1[34]; // [esp+4h] [ebp-88h] BYREF

  result = FBAllocateVBEConsole(); /*0x197c62*/
  if ( !result ) /*0x197c69*/
  {
    bzero(v1, 0x88u); /*0x197c77*/
    v1[0] = 640; /*0x197c7c*/
    v1[1] = 480; /*0x197c86*/
    return VGAAllocateConsole(v1); /*0x197c91*/
  }
  return result; /*0x197c96*/
}
