/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1fe0. */
id __cdecl -[EventDriver _setCursorPosition:atTime:](
        EventDriver *self,
        SEL a2,
        $9B414A52084CF78D000E95AF47DF0AD5 *a3,
        unsigned int a4)
{
  _WORD *v5; // ecx
  signed __int16 var1; // ax
  signed __int16 minx; // dx
  signed __int16 miny; // dx
  signed __int16 v9; // cx
  void *evg; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v11 = -1; /*0x1b1fec*/
  evg = self->evg; /*0x1b1ff9*/
  if ( !self->screens ) /*0x1b1ffc*/
    return self; /*0x1b2005*/
  if ( ev_try_lock((volatile signed __int32 *)evg + 5) ) /*0x1b2013*/
  {
    self->needSetCursorPosition = 0; /*0x1b203c*/
    v5 = (char *)self->evScreen + 20 * self->currentScreen; /*0x1b2051*/
    if ( a3->var0 < v5[6] || a3->var0 >= v5[7] || (var1 = a3->var1, var1 < (__int16)v5[8]) || var1 >= (__int16)v5[9] ) /*0x1b2083*/
    {
      v11 = -[EventDriver pointToScreen:](self, sel_pointToScreen_, a3); /*0x1b2096*/
      if ( v11 < 0 ) /*0x1b209e*/
      {
        minx = self->cursorPin.minx; /*0x1b20a3*/
        if ( a3->var0 >= minx ) /*0x1b20ad*/
        {
          minx = a3->var0; /*0x1b20af*/
          if ( a3->var0 > self->cursorPin.maxx ) /*0x1b20bb*/
            minx = self->cursorPin.maxx; /*0x1b20bd*/
        }
        a3->var0 = minx; /*0x1b20c2*/
        miny = self->cursorPin.miny; /*0x1b20c9*/
        if ( a3->var1 >= miny ) /*0x1b20d3*/
        {
          miny = a3->var1; /*0x1b20d5*/
          if ( miny > self->cursorPin.maxy ) /*0x1b20e1*/
            miny = self->cursorPin.maxy; /*0x1b20e3*/
        }
        a3->var1 = miny; /*0x1b20e8*/
      }
    }
    self->pointerLoc = ($2F2A3E9C94EF4159E4A60D0C79A55791)*a3; /*0x1b20f1*/
    if ( a3->var0 != *((_WORD *)evg + 12) || a3->var1 != *((_WORD *)evg + 13) ) /*0x1b210e*/
    {
      *(($9B414A52084CF78D000E95AF47DF0AD5 *)evg + 6) = *a3; /*0x1b212c*/
      if ( v11 < 0 ) /*0x1b2133*/
      {
        -[EventDriver moveCursor](self, sel_moveCursor); /*0x1b2194*/
      }
      else
      {
        -[EventDriver hideCursor](self, sel_hideCursor); /*0x1b213d*/
        self->currentScreen = v11; /*0x1b2145*/
        self->cursorPin = *($0E0353769CC8267629AB56B88B89B261 *)((char *)self->evScreen + 20 * v11 + 12); /*0x1b215b*/
        --self->cursorPin.maxx; /*0x1b216b*/
        --self->cursorPin.maxy; /*0x1b2172*/
        -[EventDriver showCursor](self, sel_showCursor); /*0x1b2181*/
      }
      if ( *((_DWORD *)evg + 13) ) /*0x1b219f*/
      {
        if ( (*((_DWORD *)evg + 13) & 0x40) != 0 && (*((_DWORD *)evg + 2) & 4) != 0 ) /*0x1b21b4*/
        {
          -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 6, a3, a4, 0); /*0x1b21c2*/
        }
        else if ( (*((_DWORD *)evg + 13) & 0x80u) != 0 && (*((_DWORD *)evg + 2) & 1) != 0 ) /*0x1b21d4*/
        {
          -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 7, a3, a4, 0); /*0x1b21e2*/
        }
        else if ( (*((_DWORD *)evg + 13) & 0x20) != 0 ) /*0x1b21ed*/
        {
          -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 5, a3, a4, 0); /*0x1b2203*/
        }
      }
      if ( *((char *)evg + 51) < 0 ) /*0x1b2213*/
      {
        if ( a3->var0 < *((_WORD *)evg + 20) /*0x1b2241*/
          || a3->var0 >= *((_WORD *)evg + 21)
          || (v9 = a3->var1, v9 < *((__int16 *)evg + 22))
          || v9 >= *((__int16 *)evg + 23) )
        {
          if ( *((char *)evg + 51) < 0 ) /*0x1b224b*/
          {
            -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, 9, a3, a4, 0); /*0x1b2261*/
            *((_BYTE *)evg + 51) &= ~0x80u; /*0x1b226f*/
          }
        }
      }
    }
    ev_unlock((_DWORD *)evg + 5); /*0x1b227c*/
    return self; /*0x1b2281*/
  }
  else
  {
    self->needSetCursorPosition = 1; /*0x1b201f*/
    -[EventDriver scheduleNextPeriodicEvent](self, sel_scheduleNextPeriodicEvent); /*0x1b202e*/
    return self; /*0x1b2033*/
  }
}
