/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7f74. */
int __cdecl -[AudioChannel streamUserForOwnerPort:](AudioChannel *self, SEL a2, int a3)
{
  unsigned int i; // esi
  id v4; // ebx

  for ( i = 0; i < (unsigned int)objc_msgSend(self->streamList, sel_count); ++i ) /*0x1b7f7d*/
  {
    v4 = objc_msgSend(self->streamList, sel_objectAt_, i); /*0x1b7fa8*/
    if ( (id)a3 == objc_msgSend(v4, sel_ownerPort) ) /*0x1b7fbd*/
      return (int)objc_msgSend(v4, sel_userPort); /*0x1b7fcc*/
  }
  return 0; /*0x1b7fd9*/
}
