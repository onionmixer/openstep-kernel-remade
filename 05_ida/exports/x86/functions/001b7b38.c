/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7b38. */
char __cdecl -[AudioChannel createChannelBuffer](AudioChannel *self, SEL a2)
{
  unsigned int v3; // eax
  unsigned int v4; // eax

  if ( self->channelBufferPtr ) /*0x1b7b3f*/
    return 1; /*0x1b7b4a*/
  if ( byte_1E539C && dword_1E53A0 ) /*0x1b7b60*/
  {
    self->channelBufferPtr = dword_1E53A0; /*0x1b7b62*/
    self->channelBuffer = objc_msgSend( /*0x1b7b86*/
                            self->audioDevice,
                            sel_createDMABufferFor_length_read_needsLowMemory_limitSize_,
                            &self->channelBufferPtr,
                            self->dmaSize,
                            self->_isRead,
                            1,
                            0);
    -[AudioChannel initializeFreeQueue](self, sel_initializeFreeQueue); /*0x1b7b91*/
    return 1; /*0x1b7b9b*/
  }
  if ( (unsigned __int8)objc_msgSend(self->audioDevice, sel_isEISAPresent) )
  {
    if ( (unsigned __int8)objc_msgSend(self->audioDevice, sel_isEISAPresent) ) /*0x1b7beb*/
    {
      v4 = alloc_cnvmem(self->dmaSize, page_size); /*0x1b7c02*/
      self->channelBufferPtr = v4; /*0x1b7c07*/
      if ( !v4 ) /*0x1b7c0f*/
        goto LABEL_8; /*0x1b7c0f*/
    }
  }
  else
  {
    v3 = alloc_cnvmem(self->dmaSize, 0x10000); /*0x1b7bc0*/
    self->channelBufferPtr = v3; /*0x1b7bc5*/
    if ( !v3 )
    {
LABEL_8:
      IOLog((int)"Audio: no memory for allocating buffers.\n");
      return 0; /*0x1b7bdb*/
    }
  }
  dword_1E53A0 = self->channelBufferPtr; /*0x1b7c23*/
  self->channelBuffer = objc_msgSend( /*0x1b7c4a*/
                          self->audioDevice,
                          sel_createDMABufferFor_length_read_needsLowMemory_limitSize_,
                          &self->channelBufferPtr,
                          self->dmaSize,
                          self->_isRead,
                          1,
                          0);
  -[AudioChannel initializeFreeQueue](self, sel_initializeFreeQueue); /*0x1b7c55*/
  return 1; /*0x1b7c5f*/
}
