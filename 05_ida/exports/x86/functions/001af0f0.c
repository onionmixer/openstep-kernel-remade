/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1af0f0. */
int __cdecl -[IODisplay getIntValues:forParameter:count:](
        IODisplay *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  id v6; // eax
  objc_super v7; // [esp+10h] [ebp-8h] BYREF

  if ( !strcmp(a4, "IOGetDisplayPort") || !strcmp(a4, "IO_Display_GetPort") ) /*0x1af126*/
  {
    if ( *a5 ) /*0x1af101*/
    {
      v6 = -[IODisplay devicePort](self, sel_devicePort); /*0x1af143*/
      *a3 = IOConvertPort((int)v6, (int)a5, (int)v6, 1, 2); /*0x1af155*/
      *a5 = 1; /*0x1af157*/
      return 0; /*0x1af15d*/
    }
    else
    {
      return -706; /*0x1af130*/
    }
  }
  else
  {
    v7.receiver = self; /*0x1af174*/
    v7.super_class = (Class)stru_1FA3D4.super_class; /*0x1af17d*/
    return -[IODevice getIntValues:forParameter:count:](&v7, sel_getIntValues_forParameter_count_, a3, a4, a5); /*0x1af184*/
  }
}
