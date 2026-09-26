/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116a64. */
int __cdecl sbflush(unsigned __int16 *a1)
{
  int result; // eax

  if ( (a1[10] & 1) != 0 ) /*0x116a6f*/
    panic(aSbflush); /*0x116a76*/
  while ( a1[2] ) /*0x116a92*/
    result = sbdrop(a1, *a1); /*0x116a85*/
  if ( *a1 || a1[2] || *((_DWORD *)a1 + 3) ) /*0x116aa1*/
    panic(aSbflush2); /*0x116aac*/
  return result; /*0x116ab1*/
}
