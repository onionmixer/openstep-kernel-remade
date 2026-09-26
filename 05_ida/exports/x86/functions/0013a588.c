/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a588. */
int __cdecl logswap(char a1, int a2, int a3, char a4, char a5)
{
  int v5; // edx
  int result; // eax

  if ( logswapindex > 1999 ) /*0x13a5a2*/
    logswapindex = 0; /*0x13a5a4*/
  v5 = 3 * logswapindex; /*0x13a5b7*/
  logswp[v5] = a2; /*0x13a5c2*/
  logswp[v5 + 1] = a3; /*0x13a5cb*/
  LOBYTE(logswp[v5 + 2]) = a4 & 0xF | logswp[v5 + 2] & 0xF0; /*0x13a5dd*/
  LOBYTE(logswp[3 * logswapindex + 2]) = (16 * a5) | logswp[3 * logswapindex + 2] & 0xF; /*0x13a5fb*/
  result = 3 * logswapindex; /*0x13a604*/
  BYTE1(logswp[3 * logswapindex++ + 2]) = a1; /*0x13a60a*/
  return result; /*0x13a614*/
}
