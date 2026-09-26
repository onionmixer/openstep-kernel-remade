/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b81b8. */
unsigned int __cdecl -[AudioChannel streamCount](AudioChannel *self, SEL a2)
{
  id v2; // esi

  objc_msgSend(self->streamListLock, sel_lock); /*0x1b81cb*/
  v2 = objc_msgSend(self->streamList, sel_count); /*0x1b81e0*/
  objc_msgSend(self->streamListLock, sel_unlock); /*0x1b81ed*/
  return (unsigned int)v2; /*0x1b81f7*/
}
