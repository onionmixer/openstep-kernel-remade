/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1962b4. */
id __cdecl +[kmDevice new](id a1, SEL a2)
{
  id v2; // esi
  NXLock *v3; // eax
  int i; // eax
  int v5; // eax
  int v7; // [esp-10h] [ebp-2Ch]
  char v8[20]; // [esp+8h] [ebp-14h] BYREF

  if ( !dword_1E7778 ) /*0x1962c3*/
  {
    dword_1E7774 = 0; /*0x1962c5*/
    dword_1E7778 = 1; /*0x1962cf*/
  }
  v2 = objc_msgSend(a1, sel_alloc); /*0x1962e9*/
  v3 = +[Object new](aNxlock, sel_new); /*0x1962f9*/
  *((_DWORD *)v2 + 66) = v3; /*0x1962fe*/
  dword_1E776C = -[Object methodFor:](v3, sel_methodFor_, sel_lock); /*0x196318*/
  dword_1E7770 = (int (__stdcall *)(_DWORD, _DWORD))objc_msgSend(*((id *)v2 + 66), sel_methodFor_, sel_unlock); /*0x196337*/
  *((_DWORD *)v2 + 72) = 0; /*0x19633c*/
  for ( i = 1; i >= 0; --i ) /*0x196349*/
    *((_DWORD *)v2 + i + 67) = 0; /*0x196350*/
  v5 = dword_1E7764; /*0x19635e*/
  if ( !dword_1E7764 ) /*0x196365*/
    kmId = v2; /*0x196367*/
  *((_DWORD *)v2 + 67) = basicConsole; /*0x196373*/
  objc_msgSend(kmId, sel_setUnit_, v5); /*0x196388*/
  v7 = dword_1E7764++; /*0x196393*/
  sprintf(v8, "kmDevice%d", v7); /*0x1963a3*/
  objc_msgSend(kmId, sel_setName_, v8); /*0x1963b7*/
  objc_msgSend(kmId, sel_setDeviceKind_, aKmdevice_0); /*0x1963d2*/
  objc_msgSend(kmId, sel_setLocation_, 0); /*0x1963e7*/
  return v2; /*0x1963f1*/
}
