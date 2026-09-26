/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d250. */
unsigned __int32 __cdecl stack_handoff(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  _DWORD *v3; // esi
  int v4; // edx
  _DWORD *v5; // eax
  int v6; // eax
  unsigned __int32 v7; // eax
  int v8; // ebx
  _BYTE *v9; // edx
  int v10; // ecx
  _BYTE *v11; // edx
  int v12; // eax
  int v13; // ebx
  unsigned __int32 result; // eax

  v2 = (_DWORD *)a2[10]; /*0x18d25c*/
  v3 = (_DWORD *)a1[10]; /*0x18d25f*/
  v4 = a1[11]; /*0x18d262*/
  a1[11] = 0; /*0x18d265*/
  a2[11] = v4; /*0x18d26c*/
  v5 = *(_DWORD **)a2[10]; /*0x18d272*/
  v4 += 4084; /*0x18d274*/
  v5[15] = v4; /*0x18d27a*/
  v5[14] = v4; /*0x18d27d*/
  v5[8] = _stack_attach; /*0x18d280*/
  v5[13] = 0; /*0x18d287*/
  v6 = a1[3]; /*0x18d28e*/
  if ( a2[3] != v6 ) /*0x18d294*/
  {
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 12) + 36) + 24) = 0; /*0x18d29c*/
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2[3] + 12) + 36) + 24) = 1; /*0x18d2ac*/
  }
  active_threads = (thread_act_t)a2; /*0x18d2b3*/
  v7 = *(_DWORD *)(*v2 + 28); /*0x18d2bd*/
  if ( *(_DWORD *)(*v3 + 28) != v7 ) /*0x18d2c3*/
    __writecr3(v7); /*0x18d2c5*/
  v8 = v2[29]; /*0x18d2c8*/
  if ( v3[29] != v8 || v2[30] != v3[30] ) /*0x18d2d6*/
  {
    v9 = gdt; /*0x18d2d8*/
    v10 = v2[30] - 1; /*0x18d2e1*/
    *((_WORD *)gdt + 17) = v8; /*0x18d2e2*/
    v9[36] = BYTE2(v8); /*0x18d2eb*/
    v9[39] = HIBYTE(v8); /*0x18d2f3*/
    v9[37] = v9[37] & 0x60 | 0x82; /*0x18d2fd*/
    v9[38] &= ~0x80u; /*0x18d300*/
    *((_WORD *)v9 + 16) = v10; /*0x18d304*/
    v9[38] = BYTE2(v10) & 0xF | v9[38] & 0xF0; /*0x18d315*/
    __asm { lldt ds:word_1D14EA } /*0x18d318*/
  }
  v11 = gdt; /*0x18d31f*/
  v12 = *v2 - 0x40000000; /*0x18d327*/
  v13 = v2[1] - 1; /*0x18d32f*/
  *((_WORD *)gdt + 13) = *(_WORD *)v2; /*0x18d330*/
  v11[28] = BYTE2(v12); /*0x18d339*/
  v11[31] = HIBYTE(v12); /*0x18d33f*/
  v11[29] = -119; /*0x18d342*/
  v11[30] &= ~0x80u; /*0x18d346*/
  *((_WORD *)v11 + 12) = v13; /*0x18d34a*/
  v11[30] = BYTE2(v13) & 0xF | v11[30] & 0xF0; /*0x18d35d*/
  __asm { ltr word ptr ds:unk_1D14E8 } /*0x18d360*/
  result = __readcr0(); /*0x18d367*/
  LOBYTE(result) = result | 8; /*0x18d36a*/
  __writecr0(result); /*0x18d36c*/
  return result; /*0x18d372*/
}
