/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c3cdc. */
int __cdecl -[IOFrameBufferDisplay getIntValues:forParameter:count:](
        IOFrameBufferDisplay *self,
        SEL a2,
        unsigned int *a3,
        char *__s1,
        unsigned int *a5)
{
  $514E7C50D28E54AB164B6500F83867A3 *v6; // eax
  int i; // eax
  id v8; // ebx
  $514E7C50D28E54AB164B6500F83867A3 *v9; // eax
  char *v10; // ebx
  size_t v11; // esi
  char *j; // ebx
  int v13; // eax
  const char *v14; // esi
  const char *v15; // eax
  __int32 v16; // ebx
  unsigned int *v17; // eax
  signed int currentDisplayMode; // eax
  signed int pendingDisplayMode; // eax
  unsigned int v20; // [esp+10h] [ebp-20h]
  objc_super v21; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD v22[3]; // [esp+1Ch] [ebp-14h]
  int v23; // [esp+28h] [ebp-8h]
  unsigned int var9; // [esp+2Ch] [ebp-4h]

  v20 = *a5; /*0x1c3cea*/
  if ( !strcmp(__s1, "IO_Framebuffer_Map") ) /*0x1c3cff*/
  {
    *a3 = 0; /*0x1c3d06*/
    -[IOFrameBufferDisplay revertToVGAMode](self, sel_revertToVGAMode); /*0x1c3d17*/
    -[IOFrameBufferDisplay enterLinearMode](self, sel_enterLinearMode); /*0x1c3d27*/
    objc_msgSend(kmId, sel_registerDisplay_, self); /*0x1c3d3e*/
    *a5 = 1; /*0x1c3d46*/
    return 0; /*0x1c3d4e*/
  }
  if ( !strcmp(__s1, "IO_Framebuffer_Dimensions") ) /*0x1c3d64*/
  {
    v6 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c3d77*/
    v22[0] = v6->var0; /*0x1c3d7e*/
    v22[1] = v6->var1; /*0x1c3d84*/
    v22[2] = v6->var3; /*0x1c3d8a*/
    var9 = v6->var9; /*0x1c3d90*/
    switch ( v6->var6 ) /*0x1c3d9b*/
    {
      case 0: /*0x1c3d9b*/
        v23 = 2; /*0x1c3db8*/
        break; /*0x1c3dbf*/
      case 1: /*0x1c3d9b*/
        v23 = 8; /*0x1c3dc4*/
        break; /*0x1c3dcb*/
      case 2: /*0x1c3d9b*/
        v23 = 12; /*0x1c3dd0*/
        break; /*0x1c3dd7*/
      case 3: /*0x1c3d9b*/
        v23 = 15; /*0x1c3ddc*/
        break; /*0x1c3de3*/
      case 4: /*0x1c3d9b*/
        v23 = 32; /*0x1c3de8*/
        break; /*0x1c3de8*/
      default:
        break;
    }
    *a5 = 0; /*0x1c3def*/
    for ( i = 0; i <= 4; ++i ) /*0x1c3df5*/
    {
      if ( *a5 == v20 ) /*0x1c3dfd*/
        break; /*0x1c3dfd*/
      a3[i] = v22[i]; /*0x1c3e0a*/
      ++*a5; /*0x1c3e0d*/
    }
    return 0; /*0x1c3e13*/
  }
  if ( strcmp(__s1, "IO_Framebuffer_Register") ) /*0x1c3e2c*/
  {
    if ( !strcmp(__s1, "IOGetDisplayInfo") ) /*0x1c3e88*/
    {
      if ( v20 == 5 || v20 == 7 ) /*0x1c3e96*/
      {
        v9 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c3ea7*/
        *a3 = v9->var0; /*0x1c3eb1*/
        a3[1] = v9->var1; /*0x1c3eb6*/
        a3[2] = v9->var4; /*0x1c3ebc*/
        a3[3] = v9->var6; /*0x1c3ec2*/
        a3[4] = v9->var7; /*0x1c3ec8*/
        if ( *a5 == 7 ) /*0x1c3ed1*/
        {
          a3[5] = v9->var2; /*0x1c3edd*/
          a3[6] = v9->var3; /*0x1c3ee3*/
        }
        return 0; /*0x1c3ee6*/
      }
      return -706; /*0x1c3e96*/
    }
    if ( !strcmp(__s1, "IOGetDisplayModeNum") ) /*0x1c3efc*/
    {
      if ( v20 == 1 ) /*0x1c3f04*/
      {
        *a3 = -[IOFrameBufferDisplay displayModeCount](self, sel_displayModeCount); /*0x1c3f1d*/
        return 0; /*0x1c3f21*/
      }
      return -706; /*0x1c3f04*/
    }
    if ( !strncmp(__s1, "IOGetDisplayModeInfo:", 0x15u) ) /*0x1c3f33*/
    {
      if ( *a5 == 14 ) /*0x1c3f49*/
      {
        v10 = __s1; /*0x1c3f4f*/
        v11 = strlen("IOGetDisplayModeInfo:"); /*0x1c3f65*/
        if ( *__s1 ) /*0x1c3f68*/
        {
          while ( strncmp(v10, "IOGetDisplayModeInfo:", v11) ) /*0x1c3f81*/
          {
            if ( !*++v10 ) /*0x1c3fa9*/
              goto LABEL_39; /*0x1c3fac*/
          }
          for ( j = &v10[v11]; ; ++j ) /*0x1c3f83*/
          {
            v13 = *j; /*0x1c3f93*/
            if ( !*j || v13 != 32 && v13 != 9 ) /*0x1c3f90*/
              break; /*0x1c3f90*/
          }
          v14 = nullptr; /*0x1c3f9a*/
          if ( *j ) /*0x1c3f93*/
            v14 = j; /*0x1c3fa0*/
          v15 = v14; /*0x1c3fa2*/
        }
        else
        {
LABEL_39:
          v15 = nullptr; /*0x1c3fae*/
        }
        if ( v15 ) /*0x1c3fb2*/
        {
          v16 = strtol(v15, nullptr, 10); /*0x1c3fc2*/
          if ( v16 >= 0 && v16 < -[IOFrameBufferDisplay displayModeCount](self, sel_displayModeCount) ) /*0x1c3fe4*/
          {
            v17 = (unsigned int *)((char *)-[IOFrameBufferDisplay displayModes](self, sel_displayModes) + 136 * v16); /*0x1c4003*/
            *a3 = *v17; /*0x1c400b*/
            a3[1] = v17[1]; /*0x1c4010*/
            a3[2] = v17[4]; /*0x1c4016*/
            a3[3] = v17[6]; /*0x1c401c*/
            a3[4] = v17[7]; /*0x1c4022*/
            a3[5] = v17[2]; /*0x1c4028*/
            a3[6] = v17[3]; /*0x1c402e*/
            a3[7] = v17[26]; /*0x1c4034*/
            a3[8] = v17[27]; /*0x1c403a*/
            a3[9] = 0; /*0x1c403d*/
            a3[10] = v17[29]; /*0x1c4047*/
            a3[11] = v17[30]; /*0x1c404d*/
            a3[12] = v17[31]; /*0x1c4053*/
            a3[13] = v17[32]; /*0x1c405c*/
            return 0; /*0x1c4061*/
          }
        }
      }
      return -706; /*0x1c3fe4*/
    }
    if ( !strcmp(__s1, "IOGetDisplayMemory") ) /*0x1c4078*/
    {
      if ( *a5 == 1 ) /*0x1c4082*/
      {
        *a3 = -[IOFrameBufferDisplay displayMemorySize](self, sel_displayMemorySize); /*0x1c409b*/
        return 0; /*0x1c409f*/
      }
      return -706; /*0x1c4082*/
    }
    if ( !strcmp(__s1, "IOGetRAMDACSpeed") ) /*0x1c40b4*/
    {
      if ( *a5 == 1 ) /*0x1c40be*/
      {
        *a3 = -[IOFrameBufferDisplay ramdacSpeed](self, sel_ramdacSpeed); /*0x1c40d3*/
        return 0; /*0x1c40d7*/
      }
      return -706; /*0x1c40be*/
    }
    if ( !strcmp(__s1, "IOGetCurrentDisplayMode") ) /*0x1c40ec*/
    {
      if ( *a5 == 1 ) /*0x1c40f6*/
      {
        currentDisplayMode = self->_currentDisplayMode; /*0x1c40fb*/
        if ( currentDisplayMode >= 0 ) /*0x1c4103*/
        {
          *a3 = currentDisplayMode; /*0x1c4108*/
          return 0; /*0x1c410c*/
        }
        return -750; /*0x1c4103*/
      }
    }
    else
    {
      if ( strcmp(__s1, "IOGetPendingDisplayMode") ) /*0x1c4120*/
      {
        v21.receiver = self; /*0x1c4166*/
        v21.super_class = (Class)stru_1FA604.super_class; /*0x1c416f*/
        return -[IODisplay getIntValues:forParameter:count:](&v21, sel_getIntValues_forParameter_count_, a3, __s1, a5); /*0x1c4176*/
      }
      if ( *a5 == 1 ) /*0x1c412a*/
      {
        pendingDisplayMode = self->_pendingDisplayMode; /*0x1c4137*/
        if ( pendingDisplayMode >= 0 ) /*0x1c413f*/
        {
          *a3 = pendingDisplayMode; /*0x1c4144*/
          return 0; /*0x1c4146*/
        }
        return -750; /*0x1c414d*/
      }
    }
    return -706; /*0x1c4131*/
  }
  v8 = -[IOFrameBufferDisplay _registerWithED](self, sel__registerWithED); /*0x1c3e40*/
  *a5 = 0; /*0x1c3e45*/
  if ( v20 ) /*0x1c3e52*/
  {
    *a5 = 1; /*0x1c3e54*/
    *a3 = -[IODisplay token](self, sel_token); /*0x1c3e6d*/
  }
  return (int)v8; /*0x1c417e*/
}
