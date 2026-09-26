/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1974f4. */
id kmdumplog()
{
  id result; // eax

  result = kmId; /*0x1974f7*/
  if ( kmId ) /*0x1974fe*/
    return objc_msgSend(kmId, sel_dumpMsgBuf); /*0x197508*/
  return result; /*0x19750f*/
}
