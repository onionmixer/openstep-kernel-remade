/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1963f8. */
id __cdecl -[kmDevice init:fb_mode:](kmDevice *self, SEL a2, char a3, int a4)
{
  objc_super v5; // [esp+Ch] [ebp-8h] BYREF

  objc_msgSend(self->kmOpenLock, sel_lock); /*0x196417*/
  self->outDex = 0; /*0x19641c*/
  self->inDex = 0; /*0x196426*/
  *((_BYTE *)self + 292) &= ~1u; /*0x196430*/
  self->alertRefCount = 0; /*0x196437*/
  self->fbMode = a4; /*0x196444*/
  self->inBufLock.locked = 0; /*0x19644d*/
  if ( a3 && !-[kmDevice initKb](self, sel_initKb) ) /*0x196463*/
    IOLog(aKmdeviceNoKeyb); /*0x196474*/
  v5.receiver = self; /*0x196483*/
  v5.super_class = (Class)stru_1FA014.super_class; /*0x19648c*/
  -[IODevice init](&v5, sel_init); /*0x196493*/
  if ( !self->hasRegistered ) /*0x19649b*/
  {
    -[IODevice registerDevice](self, sel_registerDevice); /*0x1964ac*/
    self->hasRegistered = 1; /*0x1964b1*/
  }
  objc_msgSend(self->kmOpenLock, sel_unlock); /*0x1964c9*/
  return self; /*0x1964d3*/
}
