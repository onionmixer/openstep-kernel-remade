/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2fdc. */
id __cdecl -[EventDriver keyboardEvent:flags:keyCode:charCode:charSet:originalCharCode:originalCharSet:repeat:atTime:](
        EventDriver *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        unsigned int a9,
        char a10,
        unsigned __int64 a11)
{
  _WORD v12[6]; // [esp+Ch] [ebp-Ch] BYREF

  v12[1] = a10; /*0x1b2ffc*/
  v12[4] = a5; /*0x1b3004*/
  v12[2] = a7; /*0x1b300c*/
  v12[3] = a6; /*0x1b3014*/
  v12[0] = a9; /*0x1b301c*/
  v12[5] = a8; /*0x1b3024*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b3036*/
  if ( self->eventsOpen ) /*0x1b303e*/
  {
    *((_DWORD *)self->evg + 3) = a4 & 0x7F007F | *((_DWORD *)self->evg + 3) & 0xFF80FF80; /*0x1b3061*/
    -[EventDriver postEvent:at:atTime:withData:]( /*0x1b307c*/
      self,
      sel_postEvent_at_atTime_withData_,
      a3,
      &self->pointerLoc,
      (unsigned int)(a11 >> 24),
      v12);
  }
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b308f*/
  return self; /*0x1b3099*/
}
