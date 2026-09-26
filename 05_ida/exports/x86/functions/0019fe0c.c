/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19fe0c. */
int __cdecl -[EventSrcPCKeyboard setCharValues:forParameter:count:](
        EventSrcPCKeyboard *self,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int a5)
{
  int v5; // ebx
  void *v6; // edi
  id keyMap; // esi
  KeyMap *v8; // eax
  id v9; // eax
  objc_super v11; // [esp+10h] [ebp-8h] BYREF

  v5 = -706; /*0x19fe18*/
  if ( !strcmp(a4, aEvsSetkeymappi) ) /*0x19fe31*/
  {
    v6 = (void *)IOMalloc(a5); /*0x19fe42*/
    bcopy(a3, v6, a5); /*0x19fe4d*/
    objc_msgSend(self->deviceLock, sel_lock); /*0x19fe63*/
    keyMap = self->keyMap; /*0x19fe6b*/
    v8 = +[Object alloc](aKeymap, sel_alloc); /*0x19fe8d*/
    v9 = -[KeyMap initFromKeyMapping:length:canFree:](v8, sel_initFromKeyMapping_length_canFree_); /*0x19fe96*/
    self->keyMap = v9; /*0x19fe9e*/
    if ( v9 ) /*0x19fea9*/
    {
      if ( keyMap ) /*0x19fead*/
        objc_msgSend(keyMap, sel_free); /*0x19feb7*/
      objc_msgSend(self->keyMap, sel_setDelegate_, self); /*0x19fed1*/
      v5 = 0; /*0x19fed6*/
    }
    else
    {
      self->keyMap = keyMap; /*0x19fee3*/
    }
    objc_msgSend(self->deviceLock, sel_unlock); /*0x19fefa*/
  }
  else
  {
    v11.receiver = self; /*0x19ff17*/
    v11.super_class = (Class)stru_1FA014.ext; /*0x19ff20*/
    v5 = -[IODevice setCharValues:forParameter:count:](&v11, sel_setCharValues_forParameter_count_, a3, a4, a5); /*0x19ff2c*/
    if ( v5 == -711 ) /*0x19ff34*/
      return -706; /*0x19ff36*/
  }
  return v5; /*0x19ff40*/
}
