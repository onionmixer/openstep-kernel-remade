/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f96c. */
int __cdecl -[EventSrcPCKeyboard getIntValues:forParameter:count:](
        EventSrcPCKeyboard *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  int result; // eax
  int v6; // edx
  bool v7; // cf
  int v8; // edx
  id keyMap; // edx
  unsigned int v10; // [esp+14h] [ebp-14h]
  objc_super v11; // [esp+18h] [ebp-10h] BYREF
  unsigned __int64 initialKeyRepeat; // [esp+20h] [ebp-8h]

  result = -706; /*0x19f97b*/
  v10 = *a5; /*0x19f985*/
  if ( !strcmp(a4, aEvsCurrentkeyr) ) /*0x19f99f*/
  {
    if ( v10 <= 3 ) /*0x19f9ab*/
      return result; /*0x19f9ab*/
    *a5 = 4; /*0x19f9b4*/
    objc_msgSend(self->deviceLock, sel_lock); /*0x19f9cb*/
    initialKeyRepeat = self->initialKeyRepeat; /*0x19f9dc*/
    v6 = 0; /*0x19f9e8*/
    do /*0x19f9f7*/
    {
      a3[v6] = *((_DWORD *)&initialKeyRepeat + v6); /*0x19f9f0*/
      v7 = v6++ == -1; /*0x19f9f4*/
    }
    while ( v7 || v6 == 1 ); /*0x19f9f7*/
    initialKeyRepeat = self->keyRepeat; /*0x19fa05*/
    v8 = 0; /*0x19fa11*/
    do /*0x19fa1f*/
    {
      a3[v8 + 2] = *((_DWORD *)&initialKeyRepeat + v8); /*0x19fa18*/
      v7 = v8++ == -1; /*0x19fa1c*/
    }
    while ( v7 || v8 == 1 ); /*0x19fa1f*/
    objc_msgSend(self->deviceLock, sel_unlock); /*0x19fa32*/
    return 0; /*0x19fab2*/
  }
  if ( !strcmp(a4, aEvsCurrentkeym) ) /*0x19fa43*/
  {
    if ( !v10 ) /*0x19fa4b*/
      return result; /*0x19fa4b*/
    *a5 = 1; /*0x19fa54*/
    objc_msgSend(self->deviceLock, sel_lock); /*0x19fa6b*/
    keyMap = self->keyMap; /*0x19fa76*/
    if ( keyMap ) /*0x19fa7e*/
      *a3 = (unsigned int)objc_msgSend(keyMap, sel_keyMappingLength); /*0x19fa95*/
    else
      *a3 = 0; /*0x19fa80*/
    objc_msgSend(self->deviceLock, sel_unlock); /*0x19faab*/
    return 0; /*0x19faab*/
  }
  if ( !strcmp(a4, aEvsEventdevice_0) ) /*0x19fac7*/
  {
    *a5 = 0; /*0x19face*/
    *a3 = (unsigned int)objc_msgSend(self->kbdDevice, aInterfaceid); /*0x19faea*/
    a3[2] = 1; /*0x19faec*/
    a3[1] = 0; /*0x19faf3*/
    a3[3] = (unsigned int)objc_msgSend(self->kbdDevice, aHandlerid); /*0x19fb10*/
    *a5 = 4; /*0x19fb16*/
    return 0; /*0x19fb1c*/
  }
  else
  {
    v11.receiver = self; /*0x19fb30*/
    v11.super_class = (Class)stru_1FA014.ext; /*0x19fb39*/
    result = -[IODevice getIntValues:forParameter:count:](&v11, sel_getIntValues_forParameter_count_, a3, a4, a5); /*0x19fb40*/
    if ( result == -711 ) /*0x19fb4a*/
      return -706; /*0x19fb4c*/
  }
  return result; /*0x19fb54*/
}
