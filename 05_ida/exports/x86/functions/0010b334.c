/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b334. */
int __cdecl itimerfix(_DWORD *a1)
{
  unsigned int v1; // eax

  if ( *a1 > 0x5F5E100u ) /*0x10b342*/
    return 22; /*0x10b342*/
  v1 = a1[1]; /*0x10b344*/
  if ( v1 > 0xF423F ) /*0x10b34c*/
    return 22; /*0x10b34e*/
  if ( !*a1 && v1 && (int)v1 < tick ) /*0x10b368*/
    a1[1] = tick; /*0x10b36a*/
  return 0; /*0x10b355*/
}
