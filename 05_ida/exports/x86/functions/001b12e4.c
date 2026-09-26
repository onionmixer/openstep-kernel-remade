/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b12e4. */
void __cdecl -[EventDriver unregisterScreen:](EventDriver *self, SEL a2, int a3)
{
  int v3; // ebx
  int v4; // edx
  int v5; // ecx

  v3 = a3 - 256; /*0x1b12f0*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b1304*/
  if ( self->eventsOpen && v3 >= 0 && self->screens > v3 ) /*0x1b1327*/
  {
    -[EventDriver hideCursor](self, sel_hideCursor); /*0x1b1340*/
    *((_DWORD *)self->evScreen + 5 * v3) = 0; /*0x1b1351*/
    if ( self->currentScreen == v3 ) /*0x1b1361*/
    {
      v4 = self->screens - 1; /*0x1b1369*/
      if ( self->screens ) /*0x1b1363*/
      {
        v5 = 20 * v4; /*0x1b1378*/
        while ( !*(_DWORD *)((char *)self->evScreen + v5) ) /*0x1b1385*/
        {
          v5 -= 20; /*0x1b1387*/
          if ( --v4 == -1 ) /*0x1b138e*/
            goto LABEL_11; /*0x1b138e*/
        }
        self->currentScreen = v4; /*0x1b1330*/
      }
LABEL_11:
      -[EventDriver setCursorPosition:](self, sel_setCursorPosition_, (char *)self->evg + 24); /*0x1b1390*/
    }
    else
    {
      -[EventDriver showCursor](self, sel_showCursor); /*0x1b13b4*/
    }
  }
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b13ca*/
}
