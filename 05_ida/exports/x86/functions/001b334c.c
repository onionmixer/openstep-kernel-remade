/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b334c. */
id __cdecl -[EventDriver _setButtonState:atTime:](EventDriver *self, SEL a2, int a3, unsigned int a4)
{
  _DWORD *evg; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax

  evg = self->evg; /*0x1b3358*/
  if ( (evg[2] & 4) != (a3 & 4) ) /*0x1b336c*/
  {
    if ( (a3 & 4) != 0 ) /*0x1b3370*/
    {
      -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 1, evg + 6, a4, 0); /*0x1b3383*/
      v5 = evg[2]; /*0x1b3388*/
      LOBYTE(v5) = v5 | 4; /*0x1b338b*/
    }
    else
    {
      -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 2, evg + 6, a4, 0); /*0x1b33a1*/
      v5 = evg[2]; /*0x1b33a6*/
      LOBYTE(v5) = v5 & 0xFB; /*0x1b33a9*/
    }
    evg[2] = v5; /*0x1b33ab*/
    *((_BYTE *)evg + 51) = (2 * *((_BYTE *)evg + 51)) & 0x40 | *((_BYTE *)evg + 51) & 0xBF; /*0x1b33c0*/
    v6 = evg[3]; /*0x1b33ca*/
    if ( (*((_BYTE *)evg + 51) & 0x40) != 0 ) /*0x1b33c8*/
      BYTE1(v6) |= 1u; /*0x1b33cd*/
    else
      BYTE1(v6) &= ~1u; /*0x1b33d7*/
    evg[3] = v6; /*0x1b33da*/
  }
  if ( (evg[2] & 1) != (a3 & 1) ) /*0x1b33eb*/
  {
    if ( (a3 & 1) != 0 ) /*0x1b33ef*/
    {
      -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 3, evg + 6, a4, 0); /*0x1b3402*/
      v7 = evg[2]; /*0x1b3407*/
      LOBYTE(v7) = v7 | 1; /*0x1b340a*/
    }
    else
    {
      -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 4, evg + 6, a4, 0); /*0x1b3421*/
      v7 = evg[2]; /*0x1b3426*/
      LOBYTE(v7) = v7 & 0xFE; /*0x1b3429*/
    }
    evg[2] = v7; /*0x1b342b*/
  }
  return self; /*0x1b3433*/
}
