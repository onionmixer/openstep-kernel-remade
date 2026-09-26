/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6a10. */
int __cdecl -[IOSVGADisplay getIntValues:forParameter:count:](
        IOSVGADisplay *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  $514E7C50D28E54AB164B6500F83867A3 *v6; // eax
  int i; // eax
  id v8; // ebx
  unsigned int v9; // [esp+10h] [ebp-1Ch]
  objc_super v10; // [esp+18h] [ebp-14h] BYREF
  _DWORD v11[3]; // [esp+20h] [ebp-Ch]

  v9 = *a5; /*0x1c6a27*/
  if ( !strcmp(a4, "IO_Framebuffer_Map") ) /*0x1c6a3e*/
  {
    *a3 = 0; /*0x1c6a45*/
    -[IOSVGADisplay enterSVGAMode](self, sel_enterSVGAMode); /*0x1c6a56*/
    objc_msgSend(kmId, sel_registerDisplay_, self); /*0x1c6a6d*/
    *a5 = 1; /*0x1c6a75*/
    return 0; /*0x1c6a7b*/
  }
  else if ( !strcmp(a4, "IO_Framebuffer_Dimensions") ) /*0x1c6a93*/
  {
    v6 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c6aa2*/
    v11[0] = v6->var0; /*0x1c6aa9*/
    v11[1] = v6->var1; /*0x1c6aaf*/
    v11[2] = v6->var3; /*0x1c6ab5*/
    *a5 = 0; /*0x1c6abb*/
    for ( i = 0; i <= 2; ++i ) /*0x1c6ac1*/
    {
      if ( *a5 == v9 ) /*0x1c6ac9*/
        break; /*0x1c6ac9*/
      a3[i] = v11[i]; /*0x1c6ad2*/
      ++*a5; /*0x1c6ad5*/
    }
    return 0; /*0x1c6add*/
  }
  else if ( !strcmp(a4, "IO_Framebuffer_Register") ) /*0x1c6af3*/
  {
    v8 = -[IOSVGADisplay _registerWithED](self, sel__registerWithED); /*0x1c6b07*/
    *a5 = 0; /*0x1c6b0c*/
    if ( v9 ) /*0x1c6b19*/
    {
      *a5 = 1; /*0x1c6b1b*/
      *a3 = -[IODisplay token](self, sel_token); /*0x1c6b34*/
    }
    return (int)v8; /*0x1c6b36*/
  }
  else
  {
    v10.receiver = self; /*0x1c6b4c*/
    v10.super_class = (Class)stru_1FA604.ext; /*0x1c6b55*/
    return -[IODisplay getIntValues:forParameter:count:](&v10, sel_getIntValues_forParameter_count_, a3, a4, a5); /*0x1c6b5c*/
  }
}
