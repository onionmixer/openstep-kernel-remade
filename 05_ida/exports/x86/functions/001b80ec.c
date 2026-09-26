/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b80ec. */
void __cdecl -[AudioChannel setExclusiveUser:](AudioChannel *self, SEL a2, int a3)
{
  id v3; // eax
  int v4; // esi
  int v5; // ebx
  id v6; // eax

  self->exclusiveUser = a3; /*0x1b80f8*/
  objc_msgSend(self->streamListLock, sel_lock); /*0x1b8106*/
  v3 = objc_msgSend(self->streamList, sel_count); /*0x1b8116*/
  v4 = (int)v3; /*0x1b811b*/
  if ( v3 ) /*0x1b8122*/
  {
    v5 = 0; /*0x1b8124*/
    if ( (int)v3 > 0 ) /*0x1b8128*/
    {
      do /*0x1b8155*/
      {
        v6 = objc_msgSend(self->streamList, sel_objectAt_, v5); /*0x1b8141*/
        objc_msgSend(v6, sel_control_); /*0x1b814a*/
        ++v5; /*0x1b8152*/
      }
      while ( v5 < v4 ); /*0x1b8155*/
    }
  }
  objc_msgSend(self->streamListLock, sel_unlock); /*0x1b8162*/
}
