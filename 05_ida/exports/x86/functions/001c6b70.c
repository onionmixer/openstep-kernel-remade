/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6b70. */
int __cdecl -[IOSVGADisplay setIntValues:forParameter:count:](
        IOSVGADisplay *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  id v6; // eax
  objc_super v7; // [esp+Ch] [ebp-8h] BYREF

  if ( !strcmp(a4, "IO_Framebuffer_Unmap") ) /*0x1c6b8e*/
  {
    -[IOSVGADisplay revertToVGAMode](self, sel_revertToVGAMode); /*0x1c6b9d*/
    return 0; /*0x1c6ba2*/
  }
  else if ( !strcmp(a4, "IO_Framebuffer_Unregister") ) /*0x1c6bb7*/
  {
    if ( a5 == 1 ) /*0x1c6bbf*/
    {
      v6 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1c6be0*/
      objc_msgSend(v6, sel_unregisterScreen_); /*0x1c6be9*/
      return 0; /*0x1c6bee*/
    }
    else
    {
      return -706; /*0x1c6bc1*/
    }
  }
  else
  {
    v7.receiver = self; /*0x1c6c04*/
    v7.super_class = (Class)stru_1FA604.ext; /*0x1c6c0d*/
    return -[IODevice setIntValues:forParameter:count:](&v7, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x1c6c14*/
  }
}
