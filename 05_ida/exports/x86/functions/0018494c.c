/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18494c. */
void __cdecl IOInitDDM(int a1)
{
  if ( !dword_1E7584 ) /*0x18495b*/
  {
    dword_1F74C4 = IOMalloc(36 * a1); /*0x184969*/
    uxprGlobal = a1; /*0x18496e*/
    dword_1E7580 = 36 * a1 + dword_1F74C4 - 36; /*0x184978*/
    IOClearDDM(); /*0x18497d*/
    xpr_lock = 0; /*0x184982*/
    dword_1E7584 = 1; /*0x18498c*/
  }
}
