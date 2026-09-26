/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155f68. */
int __cdecl port_rename(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int result; // eax

  if ( a1 ) /*0x155f73*/
  {
    if ( a3 && a3 != -1 ) /*0x155f83*/
    {
      result = ipc_object_rename(a1, a2, a3); /*0x155f92*/
      if ( !result ) /*0x155f99*/
        return result; /*0x155f99*/
    }
    else
    {
      result = 18; /*0x155f85*/
    }
  }
  else
  {
    result = 16; /*0x155f75*/
  }
  if ( result != 13 ) /*0x155f9e*/
    return 4; /*0x155fa0*/
  return result; /*0x155fa7*/
}
