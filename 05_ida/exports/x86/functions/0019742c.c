/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19742c. */
id __cdecl aprint(char *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  char *v9; // edi
  int v10; // esi
  id result; // eax
  int v12; // ebx
  char v13[200]; // [esp+10h] [ebp-C8h] BYREF

  v9 = v13; /*0x197438*/
  sprintf(v13, a1, a2, a3, a4, a5, a6, a7, a8, a9); /*0x197463*/
  do /*0x1974e2*/
  {
    v10 = *v9++; /*0x19746c*/
    if ( kmId ) /*0x19747d*/
    {
      if ( v10 == 10 ) /*0x197482*/
        objc_msgSend(kmId, sel_kmPutc_, 13); /*0x19748e*/
      result = objc_msgSend(kmId, sel_kmPutc_, v10); /*0x1974a5*/
    }
    else
    {
      v12 = kmAlertConsole; /*0x1974b0*/
      if ( !kmAlertConsole ) /*0x1974b8*/
        v12 = basicConsole; /*0x1974ba*/
      if ( v10 == 10 ) /*0x1974c3*/
        (*(void (__cdecl **)(int, int))(v12 + 20))(v12, 13); /*0x1974cb*/
      result = (id)(*(int (__cdecl **)(int, int))(v12 + 20))(v12, v10); /*0x1974db*/
    }
  }
  while ( v9 ); /*0x1974e2*/
  return result; /*0x1974ea*/
}
