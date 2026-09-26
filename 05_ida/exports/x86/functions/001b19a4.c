/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b19a4. */
id __cdecl -[EventDriver evDispatch:command:](EventDriver *self, SEL a2, int a3, int a4)
{
  id *v4; // ebx
  id v5; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v4 = (id *)((char *)self->evScreen + 20 * a3); /*0x1b19bf*/
  if ( self->eventsOpen ) /*0x1b19c2*/
  {
    v7 = *((_DWORD *)self->evg + 6); /*0x1b19d8*/
    if ( *v4 ) /*0x1b19db*/
    {
      if ( a4 == 2 ) /*0x1b19e8*/
      {
        objc_msgSend(*v4, sel_showCursor_frame_token_, &v7, *((_DWORD *)self->evg + 7), a3 + 256); /*0x1b1a47*/
      }
      else if ( (unsigned int)a4 > 2 ) /*0x1b19ea*/
      {
        if ( a4 == 3 ) /*0x1b19fb*/
        {
          objc_msgSend(*v4, sel_moveCursor_frame_token_, &v7, *((_DWORD *)self->evg + 7), a3 + 256); /*0x1b1a23*/
        }
        else if ( a4 == 4 ) /*0x1b1a00*/
        {
          v5 = -[EventDriver currentBrightness](self, sel_currentBrightness); /*0x1b1a77*/
          objc_msgSend(*v4, sel_setBrightness_token_, v5); /*0x1b1a8a*/
        }
      }
      else if ( a4 == 1 ) /*0x1b19ef*/
      {
        objc_msgSend(*v4, sel_hideCursor_, a3 + 256); /*0x1b1a61*/
      }
    }
  }
  return self; /*0x1b1a94*/
}
