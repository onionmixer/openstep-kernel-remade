/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8384. */
id __cdecl -[IOVPCodeDisplay initFromDeviceDescription:](IOVPCodeDisplay *self, SEL a2, id a3)
{
  unsigned int *v4; // eax
  const char *v5; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v6; // esi
  id v7; // eax
  objc_super v8; // [esp+Ch] [ebp-8h] BYREF

  v8.receiver = self; /*0x1c839b*/
  v8.super_class = (Class)stru_1FA654.super_class; /*0x1c83a4*/
  if ( -[IOFrameBufferDisplay initFromDeviceDescription:](&v8, sel_initFromDeviceDescription_, a3) )
  {
    self->_debug = 0; /*0x1c83d8*/
    v4 = (unsigned int *)objc_msgSend(a3, sel_memoryRangeList); /*0x1c83e7*/
    if ( v4 )
    {
      self->_videoRamAddress = *v4; /*0x1c842e*/
      self->_videoRamSize = v4[1]; /*0x1c8437*/
      self->blueTransferTable = nullptr; /*0x1c843d*/
      self->greenTransferTable = nullptr; /*0x1c8447*/
      self->redTransferTable = nullptr; /*0x1c8451*/
      self->transferTableCount = 0; /*0x1c845b*/
      self->brightnessLevel = 64; /*0x1c8465*/
      v6 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c847c*/
      v7 = -[IOFrameBufferDisplay mapFrameBufferAtPhysicalAddress:length:]( /*0x1c848a*/
             self,
             sel_mapFrameBufferAtPhysicalAddress_length_,
             0,
             0);
      v6->var5 = v7; /*0x1c848f*/
      if ( v7 ) /*0x1c8497*/
      {
        if ( self->_debug ) /*0x1c84a8*/
        {
          IOLog((int)"Video Ram Address = 0x%08x\n", self->_videoRamAddress); /*0x1c84bd*/
          IOLog((int)"Framebuffer Address = 0x%08x\n", v6->var5); /*0x1c84cb*/
        }
        return self; /*0x1c84d0*/
      }
      else
      {
        return -[IODirectDevice free](self, sel_free); /*0x1c84a1*/
      }
    }
    else
    {
      v5 = -[IODevice name](self, sel_name); /*0x1c83fb*/
      IOLog((int)"%s: No memory range set.\n", v5);
      v8.receiver = self; /*0x1c8412*/
      v8.super_class = (Class)stru_1FA654.super_class; /*0x1c841b*/
      return -[IODirectDevice free](&v8, sel_free); /*0x1c841f*/
    }
  }
  else
  {
    v8.receiver = self; /*0x1c83be*/
    v8.super_class = (Class)stru_1FA654.super_class; /*0x1c83c7*/
    return -[IODirectDevice free](&v8, sel_free); /*0x1c83cb*/
  }
}
