/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a13a0. */
void __cdecl PCexception(int a1, int a2)
{
  int *v2; // eax
  int v3; // ebx
  unsigned int v4; // edx
  int v5; // eax
  _DWORD *v6; // ebx
  int v7; // eax
  mach_msg_type_number_t v8; // edi
  int v9; // eax
  exception_data_type_t *v10; // edx
  int v11; // eax
  char v12; // [esp+Ch] [ebp-4h]

  v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a13b2*/
  v3 = 0; /*0x1a13b8*/
  if ( v2 ) /*0x1a13bc*/
    v3 = *v2; /*0x1a13be*/
  if ( v3 ) /*0x1a13c2*/
  {
    v4 = *(_DWORD *)(v3 + 132); /*0x1a13c4*/
    if ( v4 > 7 ) /*0x1a13cd*/
      v5 = 0; /*0x1a13e0*/
    else
      v5 = v3 + 132 * v4 + 136; /*0x1a13d6*/
    v6 = (_DWORD *)v5; /*0x1a13e2*/
  }
  else
  {
    v6 = nullptr; /*0x1a13e8*/
  }
  if ( v6[18] ) /*0x1a13ea*/
  {
    v7 = *(_DWORD *)(a2 + 48); /*0x1a13f4*/
    if ( v7 == 14 ) /*0x1a13fa*/
    {
      v12 = *(_BYTE *)(dword_1E875C + 104); /*0x1a1409*/
      *(_BYTE *)(dword_1E875C + 104) = 0; /*0x1a140c*/
      v8 = __readcr2(); /*0x1a1410*/
      v9 = 1; /*0x1a1417*/
      if ( (*(_BYTE *)(a2 + 52) & 2) != 0 ) /*0x1a1420*/
        v9 = 3; /*0x1a1422*/
      v10 = (exception_data_type_t *)vm_fault(*(_DWORD *)(*(_DWORD *)(a1 + 12) + 12), v8 & ~page_mask, v9, 0, nullptr); /*0x1a1441*/
      *(_BYTE *)(dword_1E875C + 104) = v12; /*0x1a144b*/
      if ( v10 ) /*0x1a1453*/
      {
        v6[19] = *(_DWORD *)(a2 + 48); /*0x1a145c*/
        v6[20] = *(_DWORD *)(a2 + 52); /*0x1a1462*/
        v6[21] = v10; /*0x1a1465*/
        exception_with_continuation(1, v10, v8, (int)sub_1A1514); /*0x1a1471*/
        if ( v6[21] ) /*0x1a1479*/
        {
          v6[22] = 1; /*0x1a147f*/
          PCcallMonitor(a1, a2); /*0x1a148b*/
        }
      }
    }
    else if ( v7 != 7 || v6[27] ) /*0x1a149d*/
    {
      if ( (*(_BYTE *)(a2 + 66) & 2) != 0 ) /*0x1a14b4*/
        v11 = PCemulateREAL(a1, a2); /*0x1a14bb*/
      else
        v11 = PCemulatePROT(a1, a2); /*0x1a14c9*/
      if ( !v11 ) /*0x1a14d3*/
        return; /*0x1a14d3*/
    }
    else
    {
      fp_noextension(); /*0x1a14a4*/
    }
    if ( !v6[22] && (v6[29] || PCtimersPending(v6)) ) /*0x1a14e9*/
      PCcallMonitor(a1, a2); /*0x1a14fa*/
    thread_exception_return(); /*0x1a1502*/
  }
}
