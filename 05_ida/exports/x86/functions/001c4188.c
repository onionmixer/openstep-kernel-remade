/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4188. */
int __cdecl -[IOFrameBufferDisplay setIntValues:forParameter:count:](
        IOFrameBufferDisplay *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  id v6; // eax
  unsigned int i; // edx
  unsigned int j; // edx
  objc_super v9; // [esp+Ch] [ebp-8h] BYREF

  if ( !strcmp(a4, "IO_Framebuffer_Unmap") ) /*0x1c41a5*/
  {
    -[IOFrameBufferDisplay revertToVGAMode](self, sel_revertToVGAMode); /*0x1c41b4*/
    return 0; /*0x1c41bb*/
  }
  if ( !strcmp(a4, "IO_Framebuffer_Unregister") ) /*0x1c41cf*/
  {
    if ( a5 == 1 ) /*0x1c41d7*/
    {
      v6 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1c41f8*/
      objc_msgSend(v6, sel_unregisterScreen_); /*0x1c4201*/
      return 0; /*0x1c4208*/
    }
    return -706; /*0x1c41d7*/
  }
  if ( strcmp(a4, "IOSetTransferTable") ) /*0x1c421f*/
  {
    if ( !strcmp(a4, "IO_BM256_to_BM38_map") ) /*0x1c42b7*/
    {
      if ( a5 == 256 ) /*0x1c42c2*/
      {
        if ( !self->_bm256To38SampleTable ) /*0x1c42c7*/
          self->_bm256To38SampleTable = (unsigned int *)IOMalloc(0x400u); /*0x1c42da*/
        for ( i = 0; i < 0x100; ++i ) /*0x1c42e0*/
          self->_bm256To38SampleTable[i] = a3[i]; /*0x1c42f3*/
        return 0; /*0x1c42fa*/
      }
    }
    else if ( !strcmp(a4, "IO_BM38_to_BM256_map") ) /*0x1c4313*/
    {
      if ( a5 == 256 ) /*0x1c431e*/
      {
        if ( !self->_bm38To256SampleTable ) /*0x1c4327*/
          self->_bm38To256SampleTable = (char *)IOMalloc(0x400u); /*0x1c433d*/
        for ( j = 0; j < 0x100; ++j ) /*0x1c4343*/
          *(_DWORD *)&self->_bm38To256SampleTable[4 * j] = a3[j]; /*0x1c4357*/
        return 0; /*0x1c435e*/
      }
    }
    else
    {
      if ( strcmp(a4, "IOSelectPendingDisplayMode") ) /*0x1c4373*/
      {
        v9.receiver = self; /*0x1c43bb*/
        v9.super_class = (Class)stru_1FA604.super_class; /*0x1c43c4*/
        return -[IODevice setIntValues:forParameter:count:](&v9, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x1c43cb*/
      }
      if ( a5 == 1 ) /*0x1c437b*/
      {
        if ( -[IOFrameBufferDisplay setPendingDisplayMode:](self, sel_setPendingDisplayMode_, *a3) != 1 ) /*0x1c4399*/
          return -751; /*0x1c43a4*/
        return 0; /*0x1c42fe*/
      }
    }
    return -706; /*0x1c426b*/
  }
  switch ( *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6) ) /*0x1c4242*/
  {
    case 0: /*0x1c4242*/
      if ( a5 != 4 ) /*0x1c4264*/
        return -706; /*0x1c4264*/
      break; /*0x1c4264*/
    case 1: /*0x1c4242*/
    case 4: /*0x1c4242*/
      if ( a5 != 256 ) /*0x1c4287*/
        return -706; /*0x1c4287*/
      break; /*0x1c4287*/
    case 2: /*0x1c4242*/
      if ( a5 != 16 ) /*0x1c4274*/
        return -706; /*0x1c4274*/
      break; /*0x1c4274*/
    case 3: /*0x1c4242*/
      if ( a5 != 32 ) /*0x1c427c*/
        return -706; /*0x1c427c*/
      break; /*0x1c427c*/
    default:
      return -706;
  }
  -[IOFrameBufferDisplay setTransferTable:count:](self, sel_setTransferTable_count_, a3, a5); /*0x1c429c*/
  return 0; /*0x1c43d3*/
}
