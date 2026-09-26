/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c85b4. */
int __cdecl -[IOVPCodeDisplay getCharValues:forParameter:count:](
        IOVPCodeDisplay *self,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int *a5)
{
  const char *v5; // eax
  objc_super v7; // [esp+Ch] [ebp-8h] BYREF

  if ( self->_debug )
  {
    v5 = -[IODevice name](self, sel_name); /*0x1c85d8*/
    IOLog((int)"%s: received parameter `%s'.\n", v5, a4);
  }
  if ( !strcmp(a4, "VPGetVPCodeFilename") ) /*0x1c85fd*/
  {
    if ( -[IOVPCodeDisplay getVPCodeFilename:count:](self, sel_getVPCodeFilename_count_, a3, a5) ) /*0x1c8614*/
      return 0; /*0x1c8624*/
    else
      return -711; /*0x1c861d*/
  }
  else
  {
    v7.receiver = self; /*0x1c863b*/
    v7.super_class = (Class)stru_1FA654.super_class; /*0x1c8644*/
    return -[IOFrameBufferDisplay getCharValues:forParameter:count:]( /*0x1c864b*/
             &v7,
             sel_getCharValues_forParameter_count_,
             a3,
             a4,
             a5);
  }
}
