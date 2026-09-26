/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7754. */
void __noreturn sub_1A7754()
{
  int v0; // esi
  id v1; // edi
  id v2; // ebx
  int v3; // eax
  id v4; // eax
  id v5; // ebx
  int i; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v7 = 1; /*0x1a775d*/
  while ( 1 ) /*0x1a7764*/
  {
    sub_1A7970(); /*0x1a7764*/
    v0 = dword_1E86D8; /*0x1a7769*/
    for ( i = vol_check_manual_poll(); (int *)v0 != &dword_1E86D8; v0 = *(_DWORD *)(v0 + 24) ) /*0x1a777d*/
    {
      objc_msgSend(*(id *)v0, sel_name); /*0x1a778e*/
      v1 = *(id *)v0; /*0x1a7793*/
      v2 = objc_msgSend(*(id *)v0, sel_lastReadyState); /*0x1a77a2*/
      if ( v2 ) /*0x1a77a9*/
      {
        if ( !(unsigned __int8)objc_msgSend(*(id *)v0, sel_needsManualPolling) || i || v2 == (id)3 ) /*0x1a77ca*/
          v7 = (int)objc_msgSend(v1, sel_updateReadyState); /*0x1a77d9*/
        else
          v7 = (int)v2; /*0x1a77e4*/
      }
      if ( (unsigned int)v2 > 2 ) /*0x1a77ea*/
      {
        if ( v2 == (id)3 ) /*0x1a77ff*/
        {
          if ( v7 ) /*0x1a7809*/
          {
            objc_msgSend(v1, sel_setLastReadyState_, 2); /*0x1a786a*/
            if ( *(_BYTE *)(v0 + 12) ) /*0x1a7872*/
            {
              *(_BYTE *)(v0 + 12) = 0; /*0x1a787c*/
              vol_panel_remove(*(_DWORD *)(v0 + 16)); /*0x1a7884*/
            }
          }
          else
          {
            v3 = *(_DWORD *)(v0 + 8); /*0x1a780b*/
            *(_DWORD *)(v0 + 8) = v3 - 1; /*0x1a7811*/
            if ( v3 == 1 ) /*0x1a7817*/
            {
              v4 = objc_msgSend(v1, sel_unit); /*0x1a7837*/
              vol_panel_request(0, 6, 1, 0, *(_DWORD *)(v0 + 20), (int)v4, 0, "", "", 0, v0 + 16); /*0x1a784c*/
              *(_BYTE *)(v0 + 12) = 1; /*0x1a7851*/
            }
          }
        }
      }
      else if ( v2 && !v7 ) /*0x1a7898*/
      {
        objc_msgSend(v1, sel_setLastReadyState_, 0); /*0x1a78a8*/
        if ( *(_BYTE *)(v0 + 13) ) /*0x1a78b0*/
          vol_panel_remove(*(_DWORD *)(v0 + 16)); /*0x1a78ba*/
        objc_msgSend(v1, sel_updatePhysicalParameters); /*0x1a78ca*/
        objc_msgSend(v1, sel_diskBecameReady); /*0x1a78d7*/
        v5 = objc_msgSend(&aIodevicedescri_0, sel_new); /*0x1a78ef*/
        objc_msgSend(v5, sel_setDirectDevice_, v1); /*0x1a78fa*/
        if ( !+[IODiskPartition probe:](aIodiskpartitio_1, sel_probe_, v5) ) /*0x1a7911*/
          objc_msgSend(v5, sel_free); /*0x1a7925*/
        if ( *(_BYTE *)(v0 + 13) ) /*0x1a792d*/
          *(_BYTE *)(v0 + 13) = 0; /*0x1a7933*/
        else
          sub_1A7C70(v1, *(_WORD *)(v0 + 4), *(_WORD *)(v0 + 6)); /*0x1a7947*/
      }
    }
    IOSleep(1000); /*0x1a7963*/
  }
}
