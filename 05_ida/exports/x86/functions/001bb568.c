/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb568. */
int __cdecl _NXAudioControlStreams(id a1, int a2, unsigned int a3)
{
  if ( !a1 || !a2 ) /*0x1bb57c*/
    return 202; /*0x1bb57e*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a2) ) /*0x1bb591*/
    return 200; /*0x1bb59d*/
  if ( a3 > 1 && a3 - 2 > 1 ) /*0x1bb5af*/
    return 206; /*0x1bb5b1*/
  objc_msgSend(a1, sel_controlStreams_, a3); /*0x1bb5c1*/
  return 0; /*0x1bb5cb*/
}
