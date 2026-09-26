/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8050. */
void __cdecl -[IOVPCodeDisplay revertToVGAMode](IOVPCodeDisplay *self, SEL a2)
{
  const char *v2; // eax
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  if ( self->_debug )
  {
    v2 = -[IODevice name](self, sel_name); /*0x1c806b*/
    IOLog((int)"%s: Resetting VGA parameters.\n", v2);
  }
  if ( -[IOVPCodeDisplay runVPCode:withRegs:](self, sel_runVPCode_withRegs_, 3, 0) ) /*0x1c808a*/
  {
    v3.receiver = self; /*0x1c809d*/
    v3.super_class = (Class)stru_1FA654.super_class; /*0x1c80a6*/
    -[IOFrameBufferDisplay revertToVGAMode](&v3, sel_revertToVGAMode); /*0x1c80ad*/
  }
}
