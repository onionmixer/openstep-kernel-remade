/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1afbdc. */
int __cdecl -[EventDriver setIntValues:forParameter:count:](
        EventDriver *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  const char *v5; // edx
  EventDriver *v7; // esi
  int v8; // edx
  bool v9; // cf
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // edx
  unsigned int v16; // edx
  EventDriver *driverLock; // esi
  int v18; // ecx
  char *v19; // esi
  const char *v20; // edi
  bool v21; // zf
  int v22; // edx
  int v23; // edx
  queue_entry *next; // ecx
  id v25; // eax
  EventDriver *v27; // [esp-1Ch] [ebp-64h]
  const char *v28; // [esp-18h] [ebp-60h]
  EventDriver *v29; // [esp+10h] [ebp-38h]
  int v30; // [esp+1Ch] [ebp-2Ch]
  objc_super v31; // [esp+20h] [ebp-28h] BYREF
  unsigned __int64 v32; // [esp+28h] [ebp-20h] BYREF
  unsigned __int64 v33; // [esp+30h] [ebp-18h]
  int v34; // [esp+38h] [ebp-10h] BYREF
  _DWORD v35[3]; // [esp+3Ch] [ebp-Ch] BYREF

  v30 = -706; /*0x1afbe5*/
  v5 = "Ev_SetScreen"; /*0x1afbef*/
  if ( !strcmp(a4, "Ev_SetScreen") ) /*0x1afc00*/
  {
    if ( a5 == 7 ) /*0x1afc08*/
      return -[EventDriver evSetScreen:](self, sel_evSetScreen_, a3); /*0x1b02bf*/
    return v30; /*0x1afc08*/
  }
  if ( !strcmp(a4, "Ev_StartCursor") ) /*0x1afc38*/
  {
    -[EventDriver startCursor](self, sel_startCursor); /*0x1afc47*/
    return 0; /*0x1afc53*/
  }
  if ( !strcmp(a4, "Ev_MousePosition") ) /*0x1afc68*/
  {
    if ( a5 != 2 ) /*0x1afc70*/
      return v30; /*0x1afc70*/
    LOWORD(v34) = *(_WORD *)a3; /*0x1afc7c*/
    LOWORD(v5) = *((_WORD *)a3 + 2); /*0x1afc83*/
    v34 = ((_DWORD)v5 << 16) | (unsigned __int16)v34; /*0x1afc8f*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1afca3*/
    v7 = self; /*0x1afcb3*/
    -[EventDriver setCursorPosition:](self, sel_setCursorPosition_, &v34); /*0x1afcb7*/
    goto LABEL_58; /*0x1afcbc*/
  }
  if ( !strcmp(a4, "Evs_SetWaitThreshold") ) /*0x1afcd4*/
  {
    v8 = 0; /*0x1afcd8*/
    do /*0x1afcea*/
    {
      *((_DWORD *)&v32 + v8) = a3[v8]; /*0x1afce2*/
      v9 = v8++ == -1; /*0x1afce7*/
    }
    while ( v9 || v8 == 1 ); /*0x1afcea*/
    v33 = v32; /*0x1afcf2*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1afd09*/
    if ( self->eventsOpen ) /*0x1afd14*/
      *((_WORD *)self->evg + 38) = v33 >> 24; /*0x1afd3a*/
    goto LABEL_61; /*0x1afd3a*/
  }
  if ( !strcmp(a4, "Evs_SetWaitSustain") ) /*0x1afd64*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1afd79*/
    v10 = 0; /*0x1afd89*/
    do /*0x1afd9a*/
    {
      *((_DWORD *)&v32 + v10) = a3[v10]; /*0x1afd92*/
      v9 = v10++ == -1; /*0x1afd97*/
    }
    while ( v9 || v10 == 1 ); /*0x1afd9a*/
    v11 = HIDWORD(v32); /*0x1afd9f*/
    LODWORD(self->waitSustain) = v32; /*0x1afda2*/
    HIDWORD(self->waitSustain) = v11; /*0x1afda4*/
    v7 = self; /*0x1afdae*/
    goto LABEL_59; /*0x1afdb1*/
  }
  if ( !strcmp(a4, "Evs_SetWaitFrameInterval") ) /*0x1afdc8*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1afddd*/
    v12 = 0; /*0x1afded*/
    do /*0x1afdfe*/
    {
      *((_DWORD *)&v32 + v12) = a3[v12]; /*0x1afdf6*/
      v9 = v12++ == -1; /*0x1afdfb*/
    }
    while ( v9 || v12 == 1 ); /*0x1afdfe*/
    v13 = HIDWORD(v32); /*0x1afe03*/
    LODWORD(self->waitFrameRate) = v32; /*0x1afe06*/
    HIDWORD(self->waitFrameRate) = v13; /*0x1afe08*/
    goto LABEL_61; /*0x1afe1c*/
  }
  if ( !strcmp(a4, "Evs_SetBrightness") ) /*0x1afe34*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1afe49*/
    v7 = self; /*0x1afe5b*/
    -[EventDriver setBrightness:](self, sel_setBrightness_, *a3); /*0x1afe5f*/
LABEL_58:
    v28 = sel_unlock; /*0x1b01e6*/
    goto LABEL_59; /*0x1b01ec*/
  }
  if ( !strcmp(a4, "Evs_SetAttenuation") ) /*0x1afe7c*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1afe91*/
    -[EventDriver setUserAudioVolume:](self, sel_setUserAudioVolume_, *a3); /*0x1afea7*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1afeba*/
    return 0; /*0x1b0200*/
  }
  if ( !strcmp(a4, "Evs_SetAutoDimBrightness") ) /*0x1afed0*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1afee5*/
    v7 = self; /*0x1afef7*/
    -[EventDriver setAutoDimBrightness:](self, sel_setAutoDimBrightness_, *a3); /*0x1afefb*/
    goto LABEL_58; /*0x1aff00*/
  }
  if ( !strcmp(a4, "Evs_SetClickTime") ) /*0x1aff18*/
  {
    v14 = 0; /*0x1aff1c*/
    do /*0x1aff2e*/
    {
      *((_DWORD *)&v32 + v14) = a3[v14]; /*0x1aff26*/
      v9 = v14++ == -1; /*0x1aff2b*/
    }
    while ( v9 || v14 == 1 ); /*0x1aff2e*/
    v33 = v32; /*0x1aff36*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1aff4d*/
    v7 = self; /*0x1aff5f*/
    self->clickTimeThresh = v33 >> 24; /*0x1aff62*/
    goto LABEL_58; /*0x1aff68*/
  }
  if ( !strcmp(a4, "Evs_SetClickSpace") ) /*0x1aff80*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1aff95*/
    self->clickSpaceThresh.x = *(_WORD *)a3; /*0x1affa3*/
    self->clickSpaceThresh.y = *((_WORD *)a3 + 2); /*0x1affb4*/
    v7 = self; /*0x1affc2*/
LABEL_59:
    driverLock = (EventDriver *)v7->driverLock; /*0x1b01ed*/
    goto LABEL_60; /*0x1b01ed*/
  }
  if ( !strcmp(a4, "Evs_SetAutoDimTime") ) /*0x1affdc*/
  {
    v15 = 0; /*0x1affe0*/
    do /*0x1afff2*/
    {
      *((_DWORD *)&v32 + v15) = a3[v15]; /*0x1affea*/
      v9 = v15++ == -1; /*0x1affef*/
    }
    while ( v9 || v15 == 1 ); /*0x1afff2*/
    v33 = v32; /*0x1afffa*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1b0011*/
    v16 = v33 >> 24; /*0x1b002b*/
    self->autoDimTime = v16 + self->autoDimTime - self->autoDimPeriod; /*0x1b0034*/
    self->autoDimPeriod = v16; /*0x1b003d*/
    goto LABEL_61; /*0x1b0051*/
  }
  if ( !strcmp(a4, "Evs_SetAutoDimState") ) /*0x1b0068*/
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1b007d*/
    v7 = self; /*0x1b0090*/
    -[EventDriver forceAutoDimState:](self, sel_forceAutoDimState_, *(char *)a3); /*0x1b0094*/
    goto LABEL_58; /*0x1b0099*/
  }
  if ( !strcmp(a4, "Evs_ResetMouse") ) /*0x1b00b0*/
  {
    driverLock = self; /*0x1b00bb*/
LABEL_60:
    v27 = driverLock; /*0x1b01f3*/
LABEL_61:
    objc_msgSend(v27, v28); /*0x1b01f4*/
    return 0; /*0x1b01f4*/
  }
  if ( !strcmp(a4, "Evs_ResetKeyboard") ) /*0x1b00d4*/
  {
    driverLock = self; /*0x1b00df*/
    goto LABEL_60; /*0x1b00e2*/
  }
  if ( !strcmp(a4, "Ev_LLPostEvent") || !strcmp(a4, "Ev_PointerLLPostEvent") ) /*0x1b010c*/
  {
    if ( a5 != 6 ) /*0x1b0118*/
      return v30; /*0x1b0118*/
    LOWORD(v34) = *((_WORD *)a3 + 2); /*0x1b0125*/
    HIWORD(v34) = *((_WORD *)a3 + 4); /*0x1b0130*/
    v35[0] = a3[3]; /*0x1b013a*/
    v35[1] = a3[4]; /*0x1b0143*/
    v35[2] = a3[5]; /*0x1b014c*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1b0160*/
    v18 = 22; /*0x1b016d*/
    v19 = a4; /*0x1b0172*/
    v20 = "Ev_PointerLLPostEvent"; /*0x1b0174*/
    v22 = 0; /*0x1b0177*/
    v21 = 1; /*0x1b0177*/
    do /*0x1b0179*/
    {
      if ( !v18 ) /*0x1b0179*/
        break; /*0x1b0179*/
      v21 = *v19++ == *v20++; /*0x1b0179*/
      --v18; /*0x1b0179*/
    }
    while ( v21 ); /*0x1b0179*/
    if ( !v21 ) /*0x1b017b*/
      v22 = (unsigned __int8)*(v19 - 1) - *((unsigned __int8 *)v20 - 1); /*0x1b0185*/
    if ( !v22 ) /*0x1b018c*/
      -[EventDriver setCursorPosition:](self, sel_setCursorPosition_, &v34); /*0x1b019d*/
    IOGetTimestamp((int *)&v32); /*0x1b01ad*/
    v23 = v32 >> 24; /*0x1b01b8*/
    if ( !v23 ) /*0x1b01c4*/
      v23 = 1; /*0x1b01c6*/
    v7 = self; /*0x1b01dd*/
    -[EventDriver postEvent:at:atTime:withData:](self, sel_postEvent_at_atTime_withData_, *a3, &v34, v23, v35); /*0x1b01e1*/
    goto LABEL_58; /*0x1b01e1*/
  }
  objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b0219*/
  next = self->eventSrcList.next; /*0x1b0221*/
  if ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b0234*/
  {
    do /*0x1b0270*/
    {
      v29 = *((EventDriver **)next + 1); /*0x1b0255*/
      v25 = objc_msgSend(*(id *)next, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x1b0258*/
      next = (queue_entry *)v29; /*0x1b0260*/
      if ( v25 != (id)-706 ) /*0x1b0268*/
        v30 = (int)v25; /*0x1b026a*/
    }
    while ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)v29 ); /*0x1b0270*/
  }
  objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b0283*/
  if ( v30 == -706 ) /*0x1b0292*/
  {
    v31.receiver = self; /*0x1b02aa*/
    v31.super_class = (Class)stru_1FA3D4.ext; /*0x1b02b3*/
    return -[IODevice setIntValues:forParameter:count:](&v31, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x1b02ba*/
  }
  return v30; /*0x1b02c8*/
}
