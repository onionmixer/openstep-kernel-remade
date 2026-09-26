/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19704c. */
id __cdecl kmputc(int a1, int a2)
{
  int v3; // ebx
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h]

  if ( kmId ) /*0x19705b*/
  {
    if ( a2 == 10 ) /*0x197060*/
      objc_msgSend(kmId, sel_kmPutc_, 13); /*0x19706c*/
    return objc_msgSend(kmId, sel_kmPutc_, a2); /*0x197083*/
  }
  else
  {
    v3 = kmAlertConsole; /*0x19708c*/
    if ( !kmAlertConsole ) /*0x197094*/
      v3 = basicConsole; /*0x197096*/
    if ( a2 == 10 ) /*0x19709f*/
      (*(void (__cdecl **)(int, int))(v3 + 20))(v3, 13); /*0x1970a7*/
    (*(void (__stdcall **)(int, _DWORD, int, int, int))(v3 + 20))(v3, (char)a2, v4, v5, savedregs); /*0x1970b6*/
    return nullptr; /*0x1970b8*/
  }
}
