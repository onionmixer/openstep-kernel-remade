/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c84dc. */
id __cdecl -[IOVPCodeDisplay runVPCode:withRegs:](IOVPCodeDisplay *self, SEL a2, unsigned int a3, unsigned int *a4)
{
  unsigned int *v4; // ebx
  unsigned int *vpCode; // edx
  unsigned int vpCodeCount; // eax
  const char *v7; // eax
  const char *v9; // eax
  const char *v10; // eax
  unsigned int v11; // [esp-4h] [ebp-30h]
  _BYTE __b[32]; // [esp+Ch] [ebp-20h] BYREF

  v4 = a4; /*0x1c84eb*/
  vpCode = self->_vpCode; /*0x1c84ee*/
  if ( vpCode && (vpCodeCount = self->_vpCodeCount) != 0 )
  {
    if ( a3 < vpCodeCount )
    {
      if ( vpCode[a3] )
      {
        if ( self->_debug )
        {
          v11 = vpCode[a3]; /*0x1c855d*/
          v10 = -[IODevice name](self, sel_name); /*0x1c8566*/
          IOLog((int)"%s: Running vpcode at 0x%x\n", v10, v11);
        }
        if ( !a4 ) /*0x1c857e*/
        {
          v4 = (unsigned int *)__b; /*0x1c8584*/
          memset(__b, 0, sizeof(__b)); /*0x1c8588*/
        }
        return -[IOVPCodeDisplay jumpTo:withInitialSRegs:](self, sel_jumpTo_withInitialSRegs_, self->_vpCode[a3], v4); /*0x1c85a3*/
      }
      else
      {
        return self; /*0x1c854f*/
      }
    }
    else
    {
      v9 = -[IODevice name](self, sel_name); /*0x1c8531*/
      IOLog((int)"%s: entry point is out of range: 0x%x.\n", v9, a3);
      return nullptr; /*0x1c8544*/
    }
  }
  else
  {
    v7 = -[IODevice name](self, sel_name); /*0x1c850a*/
    IOLog((int)"%s: No vpcode to run.\n", v7);
    return nullptr; /*0x1c851a*/
  }
}
