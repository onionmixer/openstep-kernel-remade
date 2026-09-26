/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184aa0. */
int __cdecl IOGetDDMMask(int a1)
{
  if ( a1 <= 4 ) /*0x184aa9*/
    return IODDMMasks[a1]; /*0x184abc*/
  IOLog(aXprgetbitmaskI); /*0x184ab1*/
  return 0; /*0x184aba*/
}
