/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1adf7c. */
void __cdecl __noreturn sdIoThread(id *a1)
{
  char *v1; // edi
  id v2; // eax
  id v3; // esi

  v1 = (char *)(a1 + 106); /*0x1adf85*/
  while ( 1 ) /*0x1adf9c*/
  {
    objc_msgSend(a1[110], sel_lockWhen_, 1); /*0x1adf9c*/
    while ( a1[108] != a1 + 108 ) /*0x1adfb0*/
      sub_1AE094(a1, 0); /*0x1adfb7*/
    if ( a1[106] != v1 ) /*0x1adfcd*/
    {
      do /*0x1ae01c*/
      {
        if ( objc_msgSend(a1, sel_lastReadyState) == (id)2 ) /*0x1adfeb*/
          break; /*0x1adfeb*/
        if ( objc_msgSend(a1, sel_lastReadyState) == (id)3 ) /*0x1ae000*/
          break; /*0x1ae000*/
        if ( *((_BYTE *)a1 + 456) ) /*0x1ae002*/
          break; /*0x1ae009*/
        sub_1AE094(a1, 1); /*0x1ae00e*/
      }
      while ( a1[106] != a1 + 106 ); /*0x1ae01c*/
    }
    v2 = objc_msgSend(a1, sel_lastReadyState); /*0x1ae026*/
    v3 = v2; /*0x1ae02b*/
    if ( a1[106] != v1 /*0x1ae056*/
      && (v2 == (id)1 && (unsigned __int8)objc_msgSend(a1, sel_isRemovable) || v3 == (id)2 || *((_BYTE *)a1 + 456)) )
    {
      objc_msgSend(a1, sel_unlockIoQLock); /*0x1ae067*/
      volCheckRequest((int)a1, 2); /*0x1ae06f*/
    }
    else
    {
      objc_msgSend(a1, sel_unlockIoQLock); /*0x1ae084*/
    }
  }
}
