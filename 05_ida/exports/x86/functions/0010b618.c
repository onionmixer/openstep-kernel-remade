/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b618. */
void __cdecl sethostid(__int32 a1)
{
  int *v1; // ebx

  v1 = *(int **)(dword_1E875C + 36); /*0x10b621*/
  if ( suser() ) /*0x10b624*/
    hostid = *v1; /*0x10b62f*/
}
