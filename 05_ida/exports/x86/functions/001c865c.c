/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c865c. */
int __cdecl -[IOVPCodeDisplay setIntValues:forParameter:count:](
        IOVPCodeDisplay *self,
        SEL a2,
        unsigned int *__src,
        char *a4,
        unsigned int a5)
{
  unsigned int *vpCode; // ecx
  unsigned int *v6; // eax
  unsigned int *v8; // ecx
  unsigned int vpCodeReceived; // edi
  objc_super v10; // [esp+14h] [ebp-8h] BYREF

  if ( !strcmp(a4, "VPSetVPCodeSize") ) /*0x1c867d*/
  {
    if ( a5 == 1 ) /*0x1c8685*/
    {
      vpCode = self->_vpCode; /*0x1c868b*/
      if ( vpCode ) /*0x1c8693*/
        IOFree((int)vpCode, 4 * self->_vpCodeCount); /*0x1c86a4*/
      self->_vpCodeCount = *__src; /*0x1c86b1*/
      self->_vpCodeReceived = 0; /*0x1c86b7*/
      v6 = (unsigned int *)IOMalloc(4 * self->_vpCodeCount); /*0x1c86cf*/
      self->_vpCode = v6; /*0x1c86d4*/
      if ( v6 ) /*0x1c86df*/
      {
        IOLog((int)"About to receive %d bytes of VPCode!\n", self->_vpCodeCount); /*0x1c86ed*/
        return 0; /*0x1c86f4*/
      }
      return -701; /*0x1c86df*/
    }
    return -706; /*0x1c873c*/
  }
  if ( !strcmp(a4, "VPSetVPCode") ) /*0x1c870b*/
  {
    v8 = self->_vpCode; /*0x1c870f*/
    if ( !v8 ) /*0x1c8717*/
      return -701; /*0x1c871e*/
    vpCodeReceived = self->_vpCodeReceived; /*0x1c8724*/
    if ( self->_vpCodeCount < vpCodeReceived + a5 ) /*0x1c8735*/
      return -706; /*0x1c8735*/
    memcpy(&v8[vpCodeReceived], __src, 4 * a5); /*0x1c875d*/
    self->_vpCodeReceived += a5; /*0x1c8768*/
    IOLog((int)"Received %d bytes of VPCode!\n", a5); /*0x1c8774*/
    return 0; /*0x1c8779*/
  }
  else if ( !strcmp(a4, "VPEndVPCode") ) /*0x1c878f*/
  {
    if ( -[IOVPCodeDisplay getDisplayInfo](self, sel_getDisplayInfo) ) /*0x1c879b*/
      return 0; /*0x1c87ac*/
    else
      return -711; /*0x1c87a4*/
  }
  else
  {
    v10.receiver = self; /*0x1c87c0*/
    v10.super_class = (Class)stru_1FA654.super_class; /*0x1c87c9*/
    return -[IOFrameBufferDisplay setIntValues:forParameter:count:]( /*0x1c87d0*/
             &v10,
             sel_setIntValues_forParameter_count_,
             __src,
             a4,
             a5);
  }
}
