/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aabbc. */
void __cdecl -[IOEthernet disableMulticast:](IOEthernet *self, SEL a2, $D91DDCA3822F03E96939068EA8DE741A *a3)
{
  $3D9F9298DBF9489C64856F2E59AA9D10 *v3; // eax
  int var2; // eax
  IOEthernet *var0; // ecx
  IOEthernet *var1; // edx
  char *deviceName; // eax
  _DWORD *p_isa; // eax
  $3D9F9298DBF9489C64856F2E59AA9D10 *v9; // [esp+Ch] [ebp-4h]

  objc_msgSend(self->_multiLock, sel_lock); /*0x1aabd6*/
  v3 = -[IOEthernet searchMulti:](self, sel_searchMulti_, a3); /*0x1aabe7*/
  v9 = v3; /*0x1aabec*/
  if ( v3 ) /*0x1aabf4*/
  {
    var2 = v3->var2; /*0x1aabfa*/
    if ( var2 <= 0 || (v9->var2 = var2 - 1, var2 - 1 <= 0) ) /*0x1aac0d*/
    {
      var0 = (IOEthernet *)v9->var1.var0; /*0x1aac12*/
      var1 = (IOEthernet *)v9->var1.var1; /*0x1aac15*/
      if ( &self->_multicastQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)var0 ) /*0x1aac20*/
        deviceName = (char *)v9->var1.var0; /*0x1aac22*/
      else
        deviceName = var0->super.super._deviceName; /*0x1aac28*/
      *((_DWORD *)deviceName + 1) = var1; /*0x1aac2b*/
      if ( &self->_multicastQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)var1 ) /*0x1aac36*/
        p_isa = &var1->super.super.super.isa; /*0x1aac38*/
      else
        p_isa = var1->super.super._deviceName; /*0x1aac3c*/
      *p_isa = var0; /*0x1aac3f*/
      IOFree((int)v9, 20); /*0x1aac47*/
      self->_multiAddr = ($0F52D4C2E1E8F22E8199E6D21C589DA7)*a3; /*0x1aac51*/
      objc_msgSend(self->_driverCmd, sel_send_, 8); /*0x1aac75*/
    }
  }
  objc_msgSend(self->_multiLock, sel_unlock); /*0x1aac8b*/
}
