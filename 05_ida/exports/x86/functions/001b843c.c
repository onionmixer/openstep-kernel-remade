/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b843c. */
void __cdecl -[AudioChannel controlStreams:](AudioChannel *self, SEL a2, int a3)
{
  id v3; // eax
  int v4; // esi
  int v5; // ebx
  id v6; // eax

  objc_msgSend(self->streamListLock, sel_lock); /*0x1b8450*/
  v3 = objc_msgSend(self->streamList, sel_count); /*0x1b8460*/
  v4 = (int)v3; /*0x1b8465*/
  if ( v3 ) /*0x1b846c*/
  {
    v5 = 0; /*0x1b846e*/
    if ( (int)v3 > 0 ) /*0x1b8472*/
    {
      do /*0x1b849f*/
      {
        v6 = objc_msgSend(self->streamList, sel_objectAt_, v5); /*0x1b848b*/
        objc_msgSend(v6, sel_control_); /*0x1b8494*/
        ++v5; /*0x1b849c*/
      }
      while ( v5 < v4 ); /*0x1b849f*/
    }
  }
  objc_msgSend(self->streamListLock, sel_unlock); /*0x1b84ac*/
}
