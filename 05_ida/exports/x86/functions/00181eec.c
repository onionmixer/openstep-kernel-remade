/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181eec. */
int __cdecl kern_IOGetEISADeviceConfig(id a1, int a2, int *a3, int a4, int *a5, int a6, int *a7, int a8, int *a9)
{
  id v10; // edi
  int v11; // esi
  int i; // ebx
  id v13; // eax
  id v14; // edi
  int v15; // esi
  int j; // ebx
  id v17; // eax
  id v18; // edi
  int v19; // esi
  int k; // ebx
  id v21; // eax
  int v22; // edx
  id v23; // edi
  int v24; // esi
  int m; // ebx
  id v26; // eax
  int v27; // edx
  id v28; // [esp+Ch] [ebp-4h]

  if ( !a1 ) /*0x181efa*/
    return -705; /*0x181efc*/
  v28 = objc_msgSend(a1, sel_deviceDescription); /*0x181f15*/
  v10 = objc_msgSend(v28, sel_resourcesForKey_, aIrqLevels_1); /*0x181f2d*/
  v11 = (int)objc_msgSend(v10, sel_count); /*0x181f3c*/
  if ( v11 > 7 ) /*0x181f44*/
    v11 = 7; /*0x181f46*/
  for ( i = 0; i < v11; ++i ) /*0x181f4f*/
  {
    v13 = objc_msgSend(v10, sel_objectAt_, i); /*0x181f64*/
    *(_DWORD *)(a2 + 4 * i) = objc_msgSend(v13, sel_item); /*0x181f75*/
  }
  *a3 = v11; /*0x181f83*/
  v14 = objc_msgSend(v28, sel_resourcesForKey_, aDmaChannels_0); /*0x181f9a*/
  v15 = (int)objc_msgSend(v14, sel_count); /*0x181fa9*/
  if ( v15 > 4 ) /*0x181fb1*/
    v15 = 4; /*0x181fb3*/
  for ( j = 0; j < v15; ++j ) /*0x181fbc*/
  {
    v17 = objc_msgSend(v14, sel_objectAt_, j); /*0x181fd0*/
    *(_DWORD *)(a4 + 4 * j) = objc_msgSend(v17, sel_item); /*0x181fe1*/
  }
  *a5 = v15; /*0x181fef*/
  v18 = objc_msgSend(v28, sel_resourcesForKey_, aIOPorts_0); /*0x182006*/
  v19 = (int)objc_msgSend(v18, sel_count); /*0x182015*/
  if ( v19 > 20 ) /*0x18201d*/
    v19 = 20; /*0x18201f*/
  for ( k = 0; k < v19; ++k ) /*0x182028*/
  {
    v21 = objc_msgSend(v18, sel_objectAt_, k); /*0x18203c*/
    *(_DWORD *)(a6 + 8 * k) = objc_msgSend(v21, sel_range); /*0x18204d*/
    *(_DWORD *)(a6 + 8 * k + 4) = v22; /*0x182050*/
  }
  *a7 = v19; /*0x18205f*/
  v23 = objc_msgSend(v28, sel_resourcesForKey_, aMemoryMaps_0); /*0x182076*/
  v24 = (int)objc_msgSend(v23, sel_count); /*0x182085*/
  if ( v24 > 9 ) /*0x18208d*/
    v24 = 9; /*0x18208f*/
  for ( m = 0; m < v24; ++m ) /*0x182098*/
  {
    v26 = objc_msgSend(v23, sel_objectAt_, m); /*0x1820ac*/
    *(_DWORD *)(a8 + 8 * m) = objc_msgSend(v26, sel_range); /*0x1820bd*/
    *(_DWORD *)(a8 + 8 * m + 4) = v27; /*0x1820c0*/
  }
  *a9 = v24; /*0x1820cf*/
  return 0; /*0x1820d6*/
}
