/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b4430. */
id __cdecl -[KeyMap initFromKeyMapping:length:canFree:](KeyMap *self, SEL a2, const char *a3, int a4, char a5)
{
  objc_super v6; // [esp+8h] [ebp-8h] BYREF

  v6.receiver = self; /*0x1b4447*/
  v6.super_class = (Class)stru_1FA424.ext; /*0x1b4450*/
  -[Object init](&v6, sel_init); /*0x1b4457*/
  if ( !self->keyMappingLock ) /*0x1b445f*/
    self->keyMappingLock = +[Object new](aNxlock, sel_new); /*0x1b447b*/
  if ( -[KeyMap setKeyMapping:length:canFree:](self, sel_setKeyMapping_length_canFree_, a3, a4, a5) ) /*0x1b4499*/
    return self; /*0x1b44b4*/
  else
    return -[KeyMap free](self, sel_free); /*0x1b44ad*/
}
