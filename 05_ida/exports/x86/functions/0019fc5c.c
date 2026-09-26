/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19fc5c. */
int __cdecl -[EventSrcPCKeyboard setIntValues:forParameter:count:](
        EventSrcPCKeyboard *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  int result; // eax
  int v6; // edx
  bool v7; // cf
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  objc_super v11; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]

  result = -706; /*0x19fc6b*/
  if ( !strcmp(a4, aEvsSetkeyrepea) ) /*0x19fc87*/
  {
    if ( a5 != 2 ) /*0x19fc93*/
      return result; /*0x19fc93*/
    objc_msgSend(self->deviceLock, sel_lock); /*0x19fca7*/
    v6 = 0; /*0x19fcb5*/
    do /*0x19fcc6*/
    {
      *(&v12 + v6) = a3[v6]; /*0x19fcbe*/
      v7 = v6++ == -1; /*0x19fcc3*/
    }
    while ( v7 || v6 == 1 ); /*0x19fcc6*/
    v8 = v13; /*0x19fccb*/
    LODWORD(self->keyRepeat) = v12; /*0x19fcce*/
    HIDWORD(self->keyRepeat) = v8; /*0x19fcd0*/
    if ( self->keyRepeat <= 0xFED25F ) /*0x19fce9*/
      self->keyRepeat = 16700000; /*0x19fceb*/
LABEL_7:
    objc_msgSend(self->deviceLock, sel_unlock); /*0x19fcff*/
    return 0; /*0x19fdce*/
  }
  if ( !strcmp(a4, aEvsSetinitialk) ) /*0x19fd23*/
  {
    if ( a5 != 2 ) /*0x19fd2f*/
      return result; /*0x19fd2f*/
    objc_msgSend(self->deviceLock, sel_lock); /*0x19fd43*/
    v9 = 0; /*0x19fd51*/
    do /*0x19fd62*/
    {
      *(&v12 + v9) = a3[v9]; /*0x19fd5a*/
      v7 = v9++ == -1; /*0x19fd5f*/
    }
    while ( v7 || v9 == 1 ); /*0x19fd62*/
    v10 = v13; /*0x19fd67*/
    LODWORD(self->initialKeyRepeat) = v12; /*0x19fd6a*/
    HIDWORD(self->initialKeyRepeat) = v10; /*0x19fd6c*/
    if ( self->initialKeyRepeat <= 0xFED25F ) /*0x19fd85*/
      self->initialKeyRepeat = 16700000; /*0x19fd87*/
    goto LABEL_7; /*0x19fd87*/
  }
  if ( !strcmp(a4, aEvsResetkeyboa_0) ) /*0x19fdbb*/
  {
    -[EventSrcPCKeyboard resetKeyboard](self, sel_resetKeyboard); /*0x19fdc7*/
    return 0; /*0x19fdc7*/
  }
  v11.receiver = self; /*0x19fde0*/
  v11.super_class = (Class)stru_1FA014.ext; /*0x19fde9*/
  result = -[IODevice setIntValues:forParameter:count:](&v11, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x19fdf0*/
  if ( result == -711 ) /*0x19fdfa*/
    return -706; /*0x19fdfc*/
  return result; /*0x19fe04*/
}
