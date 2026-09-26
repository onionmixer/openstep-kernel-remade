/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab364. */
id __cdecl -[IOTokenRing initFromDeviceDescription:](IOTokenRing *self, SEL a2, id a3)
{
  int v4; // esi
  DriverCmdtr *v5; // eax
  char v6[8]; // [esp+Ch] [ebp-10h] BYREF
  objc_super v7; // [esp+14h] [ebp-8h] BYREF

  v7.receiver = self; /*0x1ab37b*/
  v7.super_class = (Class)stru_1FA2E4.ext; /*0x1ab384*/
  if ( !-[IODirectDevice initFromDeviceDescription:](&v7, sel_initFromDeviceDescription_, a3) ) /*0x1ab38b*/
    return nullptr; /*0x1ab397*/
  if ( -[IODirectDevice startIOThread](self, sel_startIOThread) ) /*0x1ab3a8*/
  {
    -[IOTokenRing free](self, sel_free); /*0x1ab3bc*/
    return nullptr; /*0x1ab3c1*/
  }
  else
  {
    v4 = dword_1E5168++; /*0x1ab3c8*/
    sprintf(v6, "%s%d", "tr", v4); /*0x1ab3e3*/
    -[IODevice setName:](self, sel_setName_, v6); /*0x1ab3f1*/
    -[IODevice setDeviceKind:](self, sel_setDeviceKind_, aTokenring); /*0x1ab403*/
    -[IODevice setUnit:](self, sel_setUnit_, v4); /*0x1ab414*/
    if ( -[IOTokenRing _getInstanceTable:](self, sel__getInstanceTable_, a3) ) /*0x1ab425*/
    {
      -[IOTokenRing free](self, sel_free); /*0x1ab439*/
      return nullptr; /*0x1ab43e*/
    }
    else
    {
      -[IODirectDevice interruptPort](self, sel_interruptPort); /*0x1ab44c*/
      v5 = +[Object alloc](aDrivercmdtr, sel_alloc); /*0x1ab467*/
      self->_driverCmd = -[DriverCmdtr initPort:](v5, sel_initPort_); /*0x1ab475*/
      -[IOTokenRing _set8025FrameSizes](self, sel__set8025FrameSizes); /*0x1ab483*/
      return self; /*0x1ab488*/
    }
  }
}
