/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1acbc8. */
int __cdecl -[SCSIDisk SCSIDiskInit:targetId:lun:controller:](
        SCSIDisk *self,
        SEL a2,
        int a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        id a6)
{
  id v6; // eax
  char *v8; // ebx
  char *v9; // ebx
  const char *v10; // eax
  char *v11; // ebx
  char *v12; // ebx
  const char *v13; // eax
  objc_super v14; // [esp+20h] [ebp-10Ch] BYREF
  char v15[80]; // [esp+28h] [ebp-104h] BYREF
  char v16[32]; // [esp+78h] [ebp-B4h] BYREF
  char v17[80]; // [esp+98h] [ebp-94h] BYREF
  _BYTE v18[8]; // [esp+E8h] [ebp-44h] BYREF
  _BYTE v19[8]; // [esp+F0h] [ebp-3Ch] BYREF
  _BYTE v20[16]; // [esp+F8h] [ebp-34h] BYREF
  _BYTE v21[36]; // [esp+108h] [ebp-24h] BYREF

  self->_controller = a6; /*0x1acbe3*/
  self->_target = a4; /*0x1acbe9*/
  self->_lun = a5; /*0x1acbef*/
  -[IODevice setUnit:](self, sel_setUnit_, a3); /*0x1acbfe*/
  sprintf(v16, "sd%d", a3); /*0x1acc10*/
  -[IODevice setName:](self, sel_setName_, v16); /*0x1acc1e*/
  bzero(v18, 0x41u); /*0x1acc2c*/
  v6 = -[SCSIDisk sdInquiry:](self, sel_sdInquiry_, v18); /*0x1acc3a*/
  if ( v6 ) /*0x1acc44*/
  {
    if ( v6 == (id)1 ) /*0x1acc49*/
      return 2; /*0x1acc4b*/
    else
      return 3; /*0x1acc58*/
  }
  if ( (v18[0] & 0xE0) != 0 ) /*0x1acc69*/
    return 1; /*0x1acc69*/
  if ( (v18[0] & 0x1Fu) > 5 ) /*0x1acc71*/
  {
    if ( (v18[0] & 0x1F) == 7 ) /*0x1acc83*/
      goto LABEL_12; /*0x1acc83*/
    return 1; /*0x1acc8a*/
  }
  if ( (v18[0] & 0x1Fu) < 4 && (v18[0] & 0x1F) != 0 ) /*0x1acc7a*/
    return 1; /*0x1acc7a*/
LABEL_12:
  self->_inquiryDeviceType = v18[0] & 0x1F; /*0x1acc90*/
  if ( v18[1] < 0 ) /*0x1acca0*/
    -[IODisk setRemovable:](self, sel_setRemovable_, 1); /*0x1accac*/
  v8 = &v17[sub_1ACEEC(v19, v17, 8, 80)]; /*0x1accdd*/
  if ( *(v8 - 1) != 32 ) /*0x1acce7*/
    *v8++ = 32; /*0x1acce9*/
  v9 = &v8[sub_1ACEEC(v20, v8, 16, v17 - (v8 - 80))]; /*0x1acd09*/
  if ( *(v9 - 1) != 32 ) /*0x1acd12*/
    *v9++ = 32; /*0x1acd14*/
  v9[sub_1ACEEC(v21, v9, 4, v17 - (v9 - 80))] = 0; /*0x1acd34*/
  -[IODisk setDriveName:](self, sel_setDriveName_, v17); /*0x1acd41*/
  v10 = (const char *)objc_msgSend(a6, sel_name); /*0x1acd51*/
  sprintf(v15, "Target %d LUN %d at %s", self->_target, self->_lun, v10); /*0x1acd79*/
  -[IODevice setLocation:](self, sel_setLocation_, v15); /*0x1acd90*/
  IOLog((int)"%s: %s\n", v16, v17);
  -[SCSIDisk updateReadyState](self, sel_updateReadyState); /*0x1acdaf*/
  -[SCSIDisk scsiStartStop:inhibitRetry:](self, sel_scsiStartStop_inhibitRetry_, 0, 1); /*0x1acdc3*/
  -[IODisk setFormattedInternal:](self, sel_setFormattedInternal_, 0); /*0x1acdd2*/
  -[SCSIDisk updatePhysicalParameters](self, sel_updatePhysicalParameters); /*0x1acddf*/
  bzero(v17, 0x50u); /*0x1acdea*/
  v11 = &v17[sub_1ACEEC(v19, v17, 8, 80)]; /*0x1ace05*/
  if ( *(v11 - 1) != 32 ) /*0x1ace0f*/
    *v11++ = 32; /*0x1ace11*/
  v12 = &v11[sub_1ACEEC(v20, v11, 16, v17 - (v11 - 80))]; /*0x1ace2e*/
  if ( *(v12 - 1) != 32 ) /*0x1ace37*/
    *v12++ = 32; /*0x1ace39*/
  v12[sub_1ACEEC(v21, v12, 32, v17 - (v12 - 80))] = 0; /*0x1ace56*/
  -[IODisk setDriveName:](self, sel_setDriveName_, v17); /*0x1ace63*/
  v13 = (const char *)objc_msgSend(a6, sel_name); /*0x1ace73*/
  sprintf(v15, "Target %d LUN %d at %s", self->_target, self->_lun, v13); /*0x1ace95*/
  -[IODevice setLocation:](self, sel_setLocation_, v15); /*0x1aceac*/
  v14.receiver = self; /*0x1aceb8*/
  v14.super_class = objc_getOrigClass("IODisk"); /*0x1acecb*/
  -[IODevice init](&v14, sel_init); /*0x1aced8*/
  return 0; /*0x1acee5*/
}
