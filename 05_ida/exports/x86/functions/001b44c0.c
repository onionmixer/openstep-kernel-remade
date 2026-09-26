/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b44c0. */
id __cdecl -[KeyMap setKeyMapping:length:canFree:](KeyMap *self, SEL a2, const char *a3, int a4, char a5)
{
  char *mapping; // eax
  _BYTE v7[1264]; // [esp+8h] [ebp-4F0h] BYREF

  if ( !-[KeyMap _parseKeyMapping:length:into:](self, sel__parseKeyMapping_length_into_, a3, a4, v7) ) /*0x1b44ed*/
    return nullptr; /*0x1b44f9*/
  objc_msgSend(self->keyMappingLock, sel_lock); /*0x1b450e*/
  mapping = self->curMapping.mapping; /*0x1b4516*/
  if ( mapping ) /*0x1b451e*/
  {
    if ( self->canFreeMapping == 1 ) /*0x1b4527*/
      IOFree((int)mapping, self->curMapping.mappingLen); /*0x1b4531*/
  }
  bcopy(v7, &self->curMapping, 0x4F0u); /*0x1b4549*/
  self->canFreeMapping = a5; /*0x1b4554*/
  objc_msgSend(self->keyMappingLock, sel_unlock); /*0x1b4568*/
  return self; /*0x1b456f*/
}
