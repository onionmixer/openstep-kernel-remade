/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4ecc. */
int __cdecl -[IOFrameBufferDisplay getCharValues:forParameter:count:](
        IOFrameBufferDisplay *self,
        SEL a2,
        char *__dst,
        char *a4,
        unsigned int *a5)
{
  IOFrameBufferDisplay *v5; // edx
  $514E7C50D28E54AB164B6500F83867A3 *v7; // eax
  objc_super v8; // [esp+10h] [ebp-8h] BYREF

  v5 = self; /*0x1c4ed5*/
  if ( !strcmp(a4, "IO_Framebuffer_Pixel_Encoding") ) /*0x1c4ee8*/
  {
    if ( *a5 == 64 ) /*0x1c4ef2*/
    {
      v7 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c4f0a*/
      strncpy(__dst, v7->var8, 0x40u); /*0x1c4f1a*/
      return 0; /*0x1c4f1f*/
    }
    else
    {
      return -706; /*0x1c4ef4*/
    }
  }
  else if ( !strcmp(a4, "PostScript Driver") ) /*0x1c4f38*/
  {
    if ( self->_pendingDisplayMode >= 0 ) /*0x1c4f43*/
    {
      -[IOFrameBufferDisplay _commitToPendingMode](self, sel__commitToPendingMode); /*0x1c4f50*/
      v5 = self; /*0x1c4f55*/
      self->_pendingDisplayMode = -1; /*0x1c4f58*/
    }
    v8.receiver = v5; /*0x1c4f78*/
    v8.super_class = (Class)stru_1FA604.super_class; /*0x1c4f81*/
    return -[IODisplay getCharValues:forParameter:count:](&v8, sel_getCharValues_forParameter_count_, __dst, a4, a5); /*0x1c4f88*/
  }
  else
  {
    v8.receiver = self; /*0x1c4fa3*/
    v8.super_class = (Class)stru_1FA604.super_class; /*0x1c4fac*/
    return -[IODisplay getCharValues:forParameter:count:](&v8, sel_getCharValues_forParameter_count_, __dst, a4, a5); /*0x1c4fb3*/
  }
}
