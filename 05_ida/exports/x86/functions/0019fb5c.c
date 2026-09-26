/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19fb5c. */
int __cdecl -[EventSrcPCKeyboard getCharValues:forParameter:count:](
        EventSrcPCKeyboard *self,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int *a5)
{
  id keyMap; // eax
  id v6; // eax
  id v7; // eax
  int v8; // ebx
  size_t v10; // [esp-4h] [ebp-20h]
  unsigned int v11; // [esp+10h] [ebp-Ch]
  objc_super v12; // [esp+14h] [ebp-8h] BYREF

  v11 = *a5; /*0x19fb6d*/
  if ( !strcmp(a4, aEvsCurrentkeym_0) ) /*0x19fb84*/
  {
    objc_msgSend(self->deviceLock, sel_lock); /*0x19fb9d*/
    keyMap = self->keyMap; /*0x19fba8*/
    if ( keyMap ) /*0x19fbb0*/
    {
      v6 = objc_msgSend(keyMap, sel_keyMappingLength); /*0x19fbba*/
      if ( v11 <= (unsigned int)v6 ) /*0x19fbc5*/
        v6 = (id)v11; /*0x19fbc7*/
      *a5 = (unsigned int)v6; /*0x19fbca*/
      v10 = (size_t)v6; /*0x19fbcc*/
      v7 = objc_msgSend(self->keyMap, sel_keyMapping_, 0); /*0x19fbe4*/
      bcopy(v7, a3, v10); /*0x19fbed*/
      v8 = 0; /*0x19fbf2*/
    }
    else
    {
      v8 = -729; /*0x19fbfc*/
    }
    objc_msgSend(self->deviceLock, sel_unlock); /*0x19fc12*/
  }
  else
  {
    v12.receiver = self; /*0x19fc2c*/
    v12.super_class = (Class)stru_1FA014.ext; /*0x19fc35*/
    v8 = -[IODevice getCharValues:forParameter:count:](&v12, sel_getCharValues_forParameter_count_, a3, a4, a5); /*0x19fc41*/
    if ( v8 == -711 ) /*0x19fc49*/
      return -706; /*0x19fc4b*/
  }
  return v8; /*0x19fc55*/
}
