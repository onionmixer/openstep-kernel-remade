/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b30a0. */
id __cdecl -[EventDriver keyboardSpecialEvent:flags:keyCode:specialty:atTime:](
        EventDriver *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned __int64 a7)
{
  char *v7; // eax
  id v8; // eax
  char *v9; // eax
  char *v10; // edx
  int v12; // [esp+Ch] [ebp-10h]
  _BYTE v13[2]; // [esp+10h] [ebp-Ch] BYREF
  __int16 v14; // [esp+12h] [ebp-Ah]

  v12 = -1; /*0x1b30ac*/
  bzero(v13, 0xCu); /*0x1b30b9*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b30db*/
  if ( self->eventsOpen ) /*0x1b30e3*/
  {
    *((_DWORD *)self->evg + 3) = a4 & 0x7F007F | *((_DWORD *)self->evg + 3) & 0xFF80FF80; /*0x1b311d*/
    if ( self->autoDimmed == 1 ) /*0x1b3127*/
      -[EventDriver forceAutoDimState:](self, sel_forceAutoDimState_, 0); /*0x1b3133*/
    if ( a3 == 10 ) /*0x1b313f*/
    {
      switch ( a6 ) /*0x1b3152*/
      {
        case 0u: /*0x1b3152*/
          if ( (a4 & 0x1C0000) == 0 ) /*0x1b317c*/
          {
            v7 = -[EventDriver audioVolume](self, sel_audioVolume); /*0x1b3186*/
            -[EventDriver setAudioVolume:](self, sel_setAudioVolume_, v7 + 1); /*0x1b3197*/
          }
          goto LABEL_9; /*0x1b3197*/
        case 1u: /*0x1b3152*/
          if ( (a4 & 0x1C0000) == 0 ) /*0x1b31ac*/
          {
            v9 = -[EventDriver audioVolume](self, sel_audioVolume); /*0x1b31b6*/
            -[EventDriver setAudioVolume:](self, sel_setAudioVolume_, v9 - 1); /*0x1b31c7*/
          }
LABEL_9:
          v8 = -[EventDriver audioVolume](self, sel_audioVolume); /*0x1b319f*/
          goto LABEL_19; /*0x1b31a5*/
        case 2u: /*0x1b3152*/
          if ( (a4 & 0x1C0000) != 0 ) /*0x1b31dc*/
            goto LABEL_18; /*0x1b31dc*/
          v10 = (char *)-[EventDriver brightness](self, sel_brightness) + 1; /*0x1b31eb*/
          break; /*0x1b31ee*/
        case 3u: /*0x1b3152*/
          if ( (a4 & 0x1C0000) != 0 ) /*0x1b31f4*/
            goto LABEL_18; /*0x1b31f4*/
          v10 = (char *)-[EventDriver brightness](self, sel_brightness) - 1; /*0x1b3203*/
          break; /*0x1b3203*/
        case 6u: /*0x1b3152*/
          v14 = 1; /*0x1b322c*/
          -[EventDriver postEvent:at:atTime:withData:]( /*0x1b3248*/
            self,
            sel_postEvent_at_atTime_withData_,
            14,
            &self->pointerLoc,
            (unsigned int)(a7 >> 24),
            v13);
          goto LABEL_21; /*0x1b3248*/
        default:
          goto LABEL_21;
      }
      -[EventDriver setBrightness:](self, sel_setBrightness_, v10); /*0x1b320f*/
LABEL_18:
      v8 = -[EventDriver brightness](self, sel_brightness); /*0x1b3217*/
LABEL_19:
      v12 = (int)v8; /*0x1b3224*/
    }
LABEL_21:
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b3250*/
    if ( v12 != -1 ) /*0x1b326a*/
      -[EventDriver evSpecialKeyMsg:direction:flags:level:]( /*0x1b3284*/
        self,
        sel_evSpecialKeyMsg_direction_flags_level_,
        a6,
        a3,
        a4,
        v12);
  }
  else
  {
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b30fa*/
  }
  return self; /*0x1b328e*/
}
