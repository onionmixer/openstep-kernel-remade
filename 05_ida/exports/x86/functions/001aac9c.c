/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aac9c. */
$3D9F9298DBF9489C64856F2E59AA9D10 *__cdecl -[IOEthernet searchMulti:](
        IOEthernet *self,
        SEL a2,
        $D91DDCA3822F03E96939068EA8DE741A *a3)
{
  queue_entry *next; // edx

  next = self->_multicastQueue.next; /*0x1aaca8*/
  if ( &self->_multicastQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1aacb5*/
    return nullptr; /*0x1aacd3*/
  while ( memcmp(next, a3, 6u) ) /*0x1aacc6*/
  {
    next = *((queue_entry **)next + 2); /*0x1aaccc*/
    if ( &self->_multicastQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1aacd1*/
      return nullptr; /*0x1aacd1*/
  }
  return ($3D9F9298DBF9489C64856F2E59AA9D10 *)next; /*0x1aacd8*/
}
