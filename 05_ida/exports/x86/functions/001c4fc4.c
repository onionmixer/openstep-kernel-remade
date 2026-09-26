/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4fc4. */
int __cdecl -[IOFrameBufferDisplay setCharValues:forParameter:count:](
        IOFrameBufferDisplay *self,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int a5)
{
  unsigned int i; // edx
  unsigned int j; // edx
  objc_super v8; // [esp+Ch] [ebp-8h] BYREF

  if ( !strcmp(a4, "IO_4BPS_to_5BPS_map") ) /*0x1c4fe4*/
  {
    if ( a5 == 16 ) /*0x1c4fec*/
    {
      if ( !self->_bm34To35SampleTable ) /*0x1c4fee*/
        self->_bm34To35SampleTable = (char *)IOMalloc(0x10u); /*0x1c4ffe*/
      for ( i = 0; i < 0x10; ++i ) /*0x1c5004*/
        self->_bm34To35SampleTable[i] = a3[i]; /*0x1c5014*/
      return 0; /*0x1c501f*/
    }
    return -706; /*0x1c5042*/
  }
  if ( strcmp(a4, "IO_5BPS_to_4BPS_map") ) /*0x1c5033*/
  {
    if ( !strcmp(a4, "IOCommitToPendingDisplayMode") ) /*0x1c508b*/
    {
      if ( self->_pendingDisplayMode < 0 ) /*0x1c5096*/
      {
        return -711; /*0x1c50b4*/
      }
      else
      {
        -[IOFrameBufferDisplay _commitToPendingMode](self, sel__commitToPendingMode); /*0x1c50a0*/
        self->_pendingDisplayMode = -1; /*0x1c50a5*/
        return 0; /*0x1c50af*/
      }
    }
    else
    {
      v8.receiver = self; /*0x1c50cc*/
      v8.super_class = (Class)stru_1FA604.super_class; /*0x1c50d5*/
      return -[IODevice setCharValues:forParameter:count:](&v8, sel_setCharValues_forParameter_count_, a3, a4, a5); /*0x1c50dc*/
    }
  }
  if ( a5 != 32 ) /*0x1c503b*/
    return -706; /*0x1c503b*/
  if ( !self->_bm35To34SampleTable ) /*0x1c5048*/
    self->_bm35To34SampleTable = (char *)IOMalloc(0x20u); /*0x1c5058*/
  for ( j = 0; j < 0x20; ++j ) /*0x1c505e*/
    self->_bm35To34SampleTable[j] = a3[j]; /*0x1c506c*/
  return 0; /*0x1c50e4*/
}
