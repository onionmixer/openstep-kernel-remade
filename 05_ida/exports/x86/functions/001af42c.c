/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1af42c. */
int __cdecl -[EventDriver getIntValues:forParameter:count:](
        EventDriver *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  unsigned int v5; // ebx
  int v6; // edx
  bool v7; // cf
  int waitSustain_high; // ecx
  int v9; // edx
  int waitFrameRate_high; // ecx
  int v11; // edx
  id driverLock; // ebx
  int v13; // edx
  int v14; // edx
  unsigned int autoDimPeriod; // edx
  int v16; // edx
  unsigned int v17; // edx
  int v18; // edx
  void *v19; // ecx
  void *v20; // ecx
  id v21; // eax
  void *v23; // [esp-10h] [ebp-58h]
  const char *v24; // [esp-Ch] [ebp-54h]
  int v25; // [esp-8h] [ebp-50h]
  id v26; // [esp-8h] [ebp-50h]
  int v27; // [esp-4h] [ebp-4Ch]
  char *v28; // [esp-4h] [ebp-4Ch]
  queue_entry *v29; // [esp+Ch] [ebp-3Ch]
  queue_entry *next; // [esp+Ch] [ebp-3Ch]
  unsigned int v31; // [esp+10h] [ebp-38h]
  int v32; // [esp+14h] [ebp-34h]
  objc_super v33; // [esp+18h] [ebp-30h] BYREF
  unsigned int v34; // [esp+20h] [ebp-28h] BYREF
  _DWORD v35[5]; // [esp+24h] [ebp-24h] BYREF
  __int64 v36; // [esp+38h] [ebp-10h]
  __int64 v37; // [esp+40h] [ebp-8h]

  v32 = -706; /*0x1af435*/
  v5 = *a5; /*0x1af43f*/
  v31 = *a5; /*0x1af441*/
  v34 = 0; /*0x1af444*/
  if ( strcmp(a4, "Ev_ButtonEventNums") ) /*0x1af45d*/
  {
    if ( !strcmp(a4, "Ev_ShmemSize") ) /*0x1af4cc*/
    {
      if ( v31 ) /*0x1af4d4*/
      {
        v34 = 1; /*0x1af4da*/
        *a3 = self->shmem_size; /*0x1af4ed*/
        v32 = 0; /*0x1af4ef*/
      }
      goto LABEL_76; /*0x1af4f6*/
    }
    if ( !strcmp(a4, "Evs_CurrentWaitCursorInfo") ) /*0x1af50c*/
    {
      if ( v31 <= 5 ) /*0x1af518*/
        goto LABEL_76; /*0x1af518*/
      v34 = 6; /*0x1af51e*/
      objc_msgSend(self->driverLock, sel_lock); /*0x1af536*/
      if ( self->eventsOpen == 1 ) /*0x1af548*/
        v37 = (__int64)*((__int16 *)self->evg + 38) << 24; /*0x1af563*/
      else
        v37 = 0; /*0x1af56c*/
      v36 = v37; /*0x1af580*/
      v6 = 0; /*0x1af586*/
      do /*0x1af596*/
      {
        a3[v6] = *((_DWORD *)&v36 + v6); /*0x1af58f*/
        v7 = v6++ == -1; /*0x1af593*/
      }
      while ( v7 || v6 == 1 ); /*0x1af596*/
      waitSustain_high = HIDWORD(self->waitSustain); /*0x1af5a7*/
      LODWORD(v36) = self->waitSustain; /*0x1af5ad*/
      HIDWORD(v36) = waitSustain_high; /*0x1af5b0*/
      v9 = 0; /*0x1af5b3*/
      do /*0x1af5c3*/
      {
        a3[v9 + 2] = *((_DWORD *)&v36 + v9); /*0x1af5bc*/
        v7 = v9++ == -1; /*0x1af5c0*/
      }
      while ( v7 || v9 == 1 ); /*0x1af5c3*/
      waitFrameRate_high = HIDWORD(self->waitFrameRate); /*0x1af5d4*/
      LODWORD(v36) = self->waitFrameRate; /*0x1af5da*/
      HIDWORD(v36) = waitFrameRate_high; /*0x1af5dd*/
      v11 = 0; /*0x1af5e0*/
      do /*0x1af5ef*/
      {
        a3[v11 + 4] = *((_DWORD *)&v36 + v11); /*0x1af5e8*/
        v7 = v11++ == -1; /*0x1af5ec*/
      }
      while ( v7 || v11 == 1 ); /*0x1af5ef*/
      v28 = sel_unlock; /*0x1af5f7*/
      driverLock = self->driverLock; /*0x1af5fb*/
      goto LABEL_67; /*0x1af601*/
    }
    if ( !strcmp(a4, "Evs_DeviceControlInfo") ) /*0x1af618*/
    {
      if ( v31 <= 2 ) /*0x1af620*/
        goto LABEL_76; /*0x1af620*/
      v34 = 3; /*0x1af626*/
      objc_msgSend(self->driverLock, sel_lock); /*0x1af63e*/
      *a3 = -[EventDriver brightness](self, sel_brightness); /*0x1af656*/
      a3[1] = self->curVolume; /*0x1af65e*/
      a3[2] = -[EventDriver autoDimBrightness](self, sel_autoDimBrightness); /*0x1af674*/
LABEL_68:
      objc_msgSend(v23, v24, v26, v28); /*0x1afae2*/
      goto LABEL_69; /*0x1afae2*/
    }
    if ( !strcmp(a4, "Evs_CurrentClickTime") ) /*0x1af6a0*/
    {
      if ( v31 <= 1 ) /*0x1af6a8*/
        goto LABEL_76; /*0x1af6a8*/
      v34 = 2; /*0x1af6ae*/
      objc_msgSend(self->driverLock, sel_lock); /*0x1af6c6*/
      v37 = (unsigned __int64)self->clickTimeThresh << 24; /*0x1af6e0*/
      v36 = v37; /*0x1af6e6*/
      v13 = 0; /*0x1af6ec*/
      do /*0x1af6fe*/
      {
        a3[v13] = *((_DWORD *)&v36 + v13); /*0x1af6f7*/
        v7 = v13++ == -1; /*0x1af6fb*/
      }
      while ( v7 || v13 == 1 ); /*0x1af6fe*/
      v28 = sel_unlock; /*0x1af706*/
      driverLock = self->driverLock; /*0x1af70a*/
LABEL_67:
      v26 = driverLock; /*0x1afae1*/
      goto LABEL_68; /*0x1afae1*/
    }
    if ( !strcmp(a4, "Evs_CurrentAutoDimTime") ) /*0x1af728*/
    {
      if ( v31 <= 1 ) /*0x1af730*/
        goto LABEL_76; /*0x1af730*/
      v34 = 2; /*0x1af736*/
      objc_msgSend(self->driverLock, sel_lock); /*0x1af74e*/
      v37 = (unsigned __int64)self->autoDimPeriod << 24; /*0x1af768*/
      v36 = v37; /*0x1af76e*/
      v14 = 0; /*0x1af774*/
      do /*0x1af786*/
      {
        a3[v14] = *((_DWORD *)&v36 + v14); /*0x1af77f*/
        v7 = v14++ == -1; /*0x1af783*/
      }
      while ( v7 || v14 == 1 ); /*0x1af786*/
LABEL_31:
      objc_msgSend(v23, v24, self->driverLock, sel_unlock); /*0x1af788*/
      goto LABEL_69; /*0x1af799*/
    }
    if ( strcmp(a4, "Evs_GetDeltaAutoDimTime") ) /*0x1af7b0*/
    {
      if ( !strcmp(a4, "Evs_GetIdleTime") ) /*0x1af880*/
      {
        if ( v31 <= 1 ) /*0x1af88c*/
          goto LABEL_76; /*0x1af88c*/
        v34 = 2; /*0x1af892*/
        objc_msgSend(self->driverLock, sel_lock); /*0x1af8aa*/
        if ( self->eventsOpen == 1 ) /*0x1af8bc*/
        {
          if ( self->autoDimmed ) /*0x1af8be*/
            v17 = *((_DWORD *)self->evg + 4) - (self->autoDimTime - self->autoDimPeriod); /*0x1af8df*/
          else
            v17 = self->autoDimPeriod - (self->autoDimTime - *((_DWORD *)self->evg + 4)); /*0x1af902*/
          v37 = (unsigned __int64)v17 << 24; /*0x1af90d*/
        }
        else
        {
          v37 = 0; /*0x1af918*/
        }
        v36 = v37; /*0x1af92c*/
        v18 = 0; /*0x1af932*/
        do /*0x1af942*/
        {
          a3[v18] = *((_DWORD *)&v36 + v18); /*0x1af93b*/
          v7 = v18++ == -1; /*0x1af93f*/
        }
        while ( v7 || v18 == 1 ); /*0x1af942*/
        v28 = sel_unlock; /*0x1af94a*/
        driverLock = self->driverLock; /*0x1af94e*/
      }
      else if ( !strcmp(a4, "Evs_CurrentClickSpace") ) /*0x1af96c*/
      {
        if ( v31 <= 1 ) /*0x1af974*/
          goto LABEL_76; /*0x1af974*/
        v34 = 2; /*0x1af97a*/
        objc_msgSend(self->driverLock, sel_lock); /*0x1af992*/
        *a3 = self->clickSpaceThresh.x; /*0x1af9a4*/
        a3[1] = self->clickSpaceThresh.y; /*0x1af9b3*/
        v24 = sel_unlock; /*0x1af9bc*/
        driverLock = self->driverLock; /*0x1af9c0*/
      }
      else if ( !strcmp(a4, "Evs_AutoDimmed") ) /*0x1af9dc*/
      {
        if ( !v31 ) /*0x1af9e4*/
          goto LABEL_76; /*0x1af9e4*/
        v34 = 1; /*0x1af9ea*/
        objc_msgSend(self->driverLock, sel_lock); /*0x1afa02*/
        *a3 = self->autoDimmed; /*0x1afa14*/
        v24 = sel_unlock; /*0x1afa1c*/
        driverLock = self->driverLock; /*0x1afa20*/
      }
      else
      {
        if ( strcmp(a4, "Evs_EventDeviceInfo") ) /*0x1afa3c*/
        {
          v34 = *a5; /*0x1afb01*/
          objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1afb15*/
          next = self->eventSrcList.next; /*0x1afb23*/
          if ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1afb34*/
          {
            while ( 1 ) /*0x1afb3f*/
            {
              v20 = *(void **)next; /*0x1afb3f*/
              next = *((queue_entry **)next + 1); /*0x1afb44*/
              v21 = objc_msgSend(v20, sel_getIntValues_forParameter_count_, a3, a4, &v34); /*0x1afb58*/
              if ( v21 != (id)-706 ) /*0x1afb65*/
                break; /*0x1afb65*/
              if ( next == (queue_entry *)&self->eventSrcList ) /*0x1afb73*/
                goto LABEL_74; /*0x1afb73*/
            }
            v32 = (int)v21; /*0x1afaf4*/
          }
LABEL_74:
          objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1afb75*/
          if ( v32 == -706 ) /*0x1afb95*/
          {
            v33.receiver = self; /*0x1afbad*/
            v33.super_class = (Class)stru_1FA3D4.ext; /*0x1afbb6*/
            v32 = -[IODevice getIntValues:forParameter:count:](&v33, sel_getIntValues_forParameter_count_, a3, a4, &v34); /*0x1afbc2*/
          }
          goto LABEL_76; /*0x1afbc2*/
        }
        objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1afa55*/
        v29 = self->eventSrcList.next; /*0x1afa63*/
        while ( v29 != (queue_entry *)&self->eventSrcList ) /*0x1afa74*/
        {
          if ( v31 <= 3 ) /*0x1afa7c*/
            break; /*0x1afa7c*/
          v19 = *(void **)v29; /*0x1afa81*/
          v29 = *((queue_entry **)v29 + 1); /*0x1afa86*/
          v35[0] = 0; /*0x1afa89*/
          if ( !objc_msgSend(v19, sel_getIntValues_forParameter_count_, &a3[v34], a4, v35) ) /*0x1afaae*/
          {
            v31 -= v35[0]; /*0x1afabd*/
            v34 += v35[0]; /*0x1afac0*/
          }
        }
        v28 = sel_unlock; /*0x1afad7*/
        driverLock = self->eventSrcListLock; /*0x1afadb*/
      }
      goto LABEL_67; /*0x1af954*/
    }
    if ( v31 <= 1 ) /*0x1af7bc*/
      goto LABEL_76; /*0x1af7bc*/
    v34 = 2; /*0x1af7c2*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1af7da*/
    if ( self->eventsOpen == 1 ) /*0x1af7ec*/
    {
      if ( self->autoDimmed ) /*0x1af7ee*/
      {
        v37 = 0; /*0x1af7f7*/
        goto LABEL_40; /*0x1af805*/
      }
      autoDimPeriod = self->autoDimTime - *((_DWORD *)self->evg + 4); /*0x1af81c*/
    }
    else
    {
      autoDimPeriod = self->autoDimPeriod; /*0x1af823*/
    }
    v37 = (unsigned __int64)autoDimPeriod << 24; /*0x1af832*/
LABEL_40:
    v36 = v37; /*0x1af838*/
    v16 = 0; /*0x1af844*/
    do /*0x1af856*/
    {
      a3[v16] = *((_DWORD *)&v36 + v16); /*0x1af84f*/
      v7 = v16++ == -1; /*0x1af853*/
    }
    while ( v7 || v16 == 1 ); /*0x1af856*/
    goto LABEL_31; /*0x1af856*/
  }
  if ( v5 > 1 ) /*0x1af464*/
  {
    v34 = 2; /*0x1af46a*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1af482*/
    *a3 = self->leftENum; /*0x1af494*/
    a3[1] = self->rightENum; /*0x1af4a3*/
    objc_msgSend(self->driverLock, sel_unlock, v25, v27); /*0x1af4b7*/
LABEL_69:
    v32 = 0; /*0x1afae7*/
  }
LABEL_76:
  *a5 = v34; /*0x1afbc5*/
  return v32; /*0x1afbd3*/
}
