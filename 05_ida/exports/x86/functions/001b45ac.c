/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b45ac. */
id __cdecl -[KeyMap free](KeyMap *self, SEL a2)
{
  id keyMappingLock; // esi
  char *mapping; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  objc_msgSend(self->keyMappingLock, sel_lock); /*0x1b45c5*/
  keyMappingLock = self->keyMappingLock; /*0x1b45ca*/
  self->keyMappingLock = nullptr; /*0x1b45d0*/
  mapping = self->curMapping.mapping; /*0x1b45dd*/
  if ( mapping && self->canFreeMapping == 1 ) /*0x1b45ee*/
  {
    IOFree((int)mapping, self->curMapping.mappingLen); /*0x1b45f8*/
    self->curMapping.mapping = nullptr; /*0x1b45fd*/
  }
  objc_msgSend(keyMappingLock, sel_unlock); /*0x1b4612*/
  objc_msgSend(keyMappingLock, sel_free); /*0x1b461f*/
  v5.receiver = self; /*0x1b462b*/
  v5.super_class = (Class)stru_1FA424.ext; /*0x1b4634*/
  return -[Object free](&v5, sel_free); /*0x1b4643*/
}
