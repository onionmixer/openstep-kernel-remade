/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad8b0. */
void __cdecl -[SCSIDisk doSdBuf:](SCSIDisk *self, SEL a2, $BB0ECD142E749ABD0946980FC80D177E *a3)
{
  int v3; // ebx
  id v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  char *v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // ecx
  char *v11; // eax
  int v12; // edi
  char *v13; // eax
  int v14; // edi
  char *v15; // eax
  int v16; // ebx
  char *v17; // eax
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *var5; // edx
  const char *v19; // [esp+10h] [ebp-74h]
  _BYTE v20[24]; // [esp+14h] [ebp-70h] BYREF
  __int16 v21; // [esp+2Ch] [ebp-58h]
  _BYTE v22[28]; // [esp+30h] [ebp-54h] BYREF
  int v23; // [esp+4Ch] [ebp-38h]
  unsigned __int8 v24; // [esp+50h] [ebp-34h]
  unsigned int v25; // [esp+54h] [ebp-30h]
  int v26; // [esp+58h] [ebp-2Ch]
  int v27; // [esp+5Ch] [ebp-28h]
  int v28; // [esp+60h] [ebp-24h]
  int v29; // [esp+64h] [ebp-20h]
  _BYTE v30[24]; // [esp+68h] [ebp-1Ch] BYREF
  __int16 v31; // [esp+80h] [ebp-4h]

  v3 = 100; /*0x1ad8b9*/
  v19 = -[IODevice name](self, sel_name); /*0x1ad8ce*/
  a3->var13 = 10; /*0x1ad8d4*/
  a3->var14 = 5; /*0x1ad8db*/
  a3->var15 = 10; /*0x1ad8e2*/
  if ( !a3->var13 ) /*0x1ad8f0*/
    goto LABEL_59; /*0x1ad8f0*/
  if ( !a3->var14 ) /*0x1ad8fa*/
    goto LABEL_56; /*0x1ad8fa*/
  while ( 1 )
  {
    if ( !a3->var15 ) /*0x1ad90f*/
      goto LABEL_56; /*0x1ad90f*/
    if ( -[SCSIDisk setupScsiReq:scsiReq:](self, sel_setupScsiReq_scsiReq_, a3, v22) ) /*0x1ad925*/
      return; /*0x1ad931*/
    v20[0] &= ~0x80u; /*0x1ad937*/
    v4 = objc_msgSend(self->_controller, sel_executeRequest_buffer_client_, v22, a3->var3, a3->var4); /*0x1ad95b*/
    v3 = (int)v4; /*0x1ad960*/
    if ( !v4 )
    {
      if ( a3->var0 > 1u || (v5 = -[IODisk blockSize](self, sel_blockSize), v25 == v5 * a3->var2) ) /*0x1ad994*/
      {
        if ( (*((_BYTE *)self + 394) & 2) != 0 ) /*0x1ad9ea*/
        {
          if ( a3->var0 ) /*0x1ad9f3*/
          {
            if ( a3->var0 == 1 ) /*0x1ad9fc*/
              -[IODisk addToBytesWritten:totalTime:latentTime:]( /*0x1ada47*/
                self,
                sel_addToBytesWritten_totalTime_latentTime_,
                v25,
                v26,
                v27,
                v28,
                v29);
          }
          else
          {
            -[IODisk addToBytesRead:totalTime:latentTime:]( /*0x1ada23*/
              self,
              sel_addToBytesRead_totalTime_latentTime_,
              v25,
              v26,
              v27,
              v28,
              v29);
          }
        }
        goto LABEL_56; /*0x1ada4f*/
      }
      v6 = a3->var14 - 1; /*0x1ad999*/
      a3->var14 = v6; /*0x1ad99c*/
      if ( v6 <= 0 )
      {
        IOLog((int)"%s: TRANSFER COUNT ERROR;  FATAL.\n", v19);
        -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1ade95*/
        v3 = 15; /*0x1ade9a*/
        goto LABEL_56; /*0x1adea2*/
      }
      IOLog((int)"%s: TRANSFER COUNT ERROR.  Expected = %d Received %d; Retrying.\n", v19, v5 * a3->var2, a3->var10);
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, 0); /*0x1ad9d2*/
      goto LABEL_48; /*0x1ad9da*/
    }
    if ( (*((_BYTE *)a3 + 32) & 2) != 0 ) /*0x1ada5b*/
      goto LABEL_56; /*0x1ada5b*/
    if ( (unsigned int)v4 > 9 ) /*0x1ada64*/
    {
      if ( (unsigned int)v4 > 0x13 ) /*0x1ada87*/
      {
        if ( v4 == (id)100 ) /*0x1ada9b*/
          goto LABEL_27; /*0x1ada9b*/
      }
      else
      {
        if ( (unsigned int)v4 >= 0xE ) /*0x1ada8c*/
          goto LABEL_27; /*0x1ada8c*/
        if ( v4 == (id)13 ) /*0x1ada91*/
          break; /*0x1ada91*/
      }
      goto LABEL_46; /*0x1ada91*/
    }
    if ( (unsigned int)v4 >= 7 || v4 == (id)1 )
    {
LABEL_27:
      v7 = IOFindNameForValue((int)v4, IOScStatusStrings); /*0x1adaa1*/
      IOLog((int)"%s: %s : FATAL ERROR\n", v19, v7);
      goto LABEL_64; /*0x1adabf*/
    }
    if ( (unsigned int)v4 <= 3 ) /*0x1ada79*/
      break; /*0x1ada79*/
LABEL_46:
    v14 = a3->var14 - 1; /*0x1add20*/
    a3->var14 = v14; /*0x1add29*/
    if ( v14 <= 0 ) /*0x1add2f*/
    {
      v17 = IOFindNameForValue((int)v4, IOScStatusStrings); /*0x1addea*/
      goto LABEL_63; /*0x1addea*/
    }
    v15 = IOFindNameForValue((int)v4, IOScStatusStrings); /*0x1add3b*/
    IOLog((int)"%s: %s; Retrying.\n", v19, v15);
    -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1add62*/
LABEL_48:
    if ( (*((_BYTE *)self + 394) & 2) != 0 ) /*0x1add74*/
    {
      if ( a3->var0 ) /*0x1add79*/
      {
        if ( a3->var0 == 1 ) /*0x1add82*/
          -[IODisk incrementWriteRetries](self, sel_incrementWriteRetries); /*0x1adda3*/
        else
          -[IODisk incrementOtherRetries](self, sel_incrementOtherRetries); /*0x1add84*/
      }
      else
      {
        -[IODisk incrementReadRetries](self, sel_incrementReadRetries); /*0x1add8e*/
      }
    }
    if ( !a3->var13 ) /*0x1addb2*/
      goto LABEL_59; /*0x1addb2*/
    if ( !a3->var14 ) /*0x1addb4*/
      goto LABEL_56; /*0x1addb8*/
  }
  if ( v24 != 2 )
  {
    if ( v24 != 8 )
    {
      IOLog((int)"%s: BOGUS SCSI STATUS (0x%x): FATAL.\n", v19, v24);
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1add0e*/
      v3 = 13; /*0x1add13*/
      goto LABEL_56; /*0x1add1b*/
    }
    v8 = a3->var13 - 1; /*0x1adadc*/
    a3->var13 = v8; /*0x1adadf*/
    if ( v8 <= 0 )
    {
      IOLog((int)"%s: BUSY STATUS; FATAL.\n", v19);
      goto LABEL_67; /*0x1ade4d*/
    }
    IOLog((int)"%s: BUSY STATUS; Retrying.\n", v19);
    IOSleep(0x3E8u); /*0x1adafe*/
    goto LABEL_48; /*0x1adb06*/
  }
  if ( v4 == (id)2 )
  {
    qmemcpy(v20, v30, sizeof(v20)); /*0x1adb50*/
    v21 = v31; /*0x1adb52*/
  }
  else
  {
    v3 = -[SCSIDisk reqSense:](self, sel_reqSense_, v20); /*0x1adb25*/
    if ( v3 )
    {
      IOLog((int)"%s: REQUEST SENSE ERROR;  FATAL.\n", v19);
      goto LABEL_56; /*0x1adb3f*/
    }
  }
  switch ( v20[2] & 0xF )
  {
    case 0:
    case 1:
    case 3:
    case 4:
      v10 = a3->var14 - 1; /*0x1adbe2*/
      a3->var14 = v10; /*0x1adbe5*/
      if ( v10 > 0 )
      {
        v11 = IOFindNameForValue(v20[2] & 0xF, IOSCSISenseStrings); /*0x1adbfd*/
        IOLog((int)"%s: %s; Retrying.\n", v19, v11);
        -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1adc24*/
        goto LABEL_48; /*0x1adc24*/
      }
      v17 = IOFindNameForValue(v20[2] & 0xF, IOSCSISenseStrings); /*0x1ade04*/
LABEL_63:
      IOLog((int)"%s: %s; FATAL.\n", v19, v17);
LABEL_64:
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1ade1c*/
LABEL_56:
      if ( a3->var13 && a3->var14 && a3->var15 ) /*0x1addcd*/
      {
        if ( v3 ) /*0x1adeaa*/
          v16 = (int)objc_msgSend(self->_controller, sel_returnFromScStatus_, v3); /*0x1adec3*/
        else
          v16 = 0; /*0x1adecc*/
        if ( v16 ) /*0x1aded0*/
          goto LABEL_73; /*0x1aded0*/
      }
      else
      {
LABEL_59:
        v16 = -714; /*0x1addd7*/
LABEL_73:
        if ( (*((_BYTE *)self + 394) & 2) != 0 ) /*0x1adedc*/
        {
          if ( a3->var0 ) /*0x1adee1*/
          {
            if ( a3->var0 == 1 ) /*0x1adeea*/
            {
              -[IODisk incrementWriteErrors](self, sel_incrementWriteErrors); /*0x1adf0b*/
            }
            else if ( (*((_BYTE *)a3 + 32) & 2) == 0 ) /*0x1adf17*/
            {
              -[IODisk incrementOtherErrors](self, sel_incrementOtherErrors); /*0x1adf24*/
            }
          }
          else
          {
            -[IODisk incrementReadErrors](self, sel_incrementReadErrors); /*0x1adefb*/
          }
        }
      }
      var5 = a3->var5; /*0x1adf2f*/
      if ( var5 ) /*0x1adf34*/
      {
        *((_DWORD *)var5 + 7) = v23; /*0x1adf39*/
        *((_BYTE *)a3->var5 + 32) = v24; /*0x1adf42*/
        *((_DWORD *)a3->var5 + 9) = v25; /*0x1adf4e*/
      }
      a3->var10 = v25; /*0x1adf57*/
      a3->var11 = v16; /*0x1adf5a*/
      -[SCSIDisk sdIoComplete:](self, sel_sdIoComplete_, a3); /*0x1adf69*/
      return;
    case 2:
      v9 = a3->var15 - 1; /*0x1adb92*/
      a3->var15 = v9; /*0x1adb95*/
      if ( v9 <= 0 )
      {
        IOLog((int)"%s: NOT READY; FATAL.\n", v19);
        goto LABEL_67; /*0x1ade41*/
      }
      IOLog((int)"%s: NOT READY; Retrying.\n", v19);
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1adbc2*/
      IOSleep(0x3E8u); /*0x1adbcc*/
      goto LABEL_48; /*0x1adbd4*/
    case 6:
      v12 = a3->var14 - 1; /*0x1adc32*/
      a3->var14 = v12; /*0x1adc35*/
      if ( v12 <= 0 )
      {
        IOLog((int)"%s: UNIT ATTENTION; FATAL.\n", v19);
LABEL_67:
        -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1ade52*/
        goto LABEL_56; /*0x1ade6d*/
      }
      IOLog((int)"%s: UNIT ATTENTION; Retrying.\n", v19);
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1adc62*/
      goto LABEL_48; /*0x1adc6a*/
    case 7:
      IOLog((int)"%s: WRITE PROTECTED. FATAL.\n", v19);
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1adc91*/
      v3 = 17; /*0x1adc96*/
      goto LABEL_56; /*0x1adc9e*/
    default:
      v13 = IOFindNameForValue(v20[2] & 0xF, IOSCSISenseStrings); /*0x1adcb0*/
      IOLog((int)"%s: %s; FATAL.\n", v19, v13);
      -[SCSIDisk logOpInfo:sense:](self, sel_logOpInfo_sense_, a3, v20); /*0x1adcd7*/
      v3 = 2; /*0x1adcdc*/
      goto LABEL_56; /*0x1adce4*/
  }
}
