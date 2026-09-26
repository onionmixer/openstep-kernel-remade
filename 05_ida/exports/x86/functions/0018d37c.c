/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d37c. */
void __cdecl switch_context(_DWORD *a1, int a2, _DWORD *a3)
{
  int v3; // eax
  unsigned __int32 v4; // eax
  int v5; // ebx
  _BYTE *v6; // edx
  int v7; // ecx
  _BYTE *v8; // edx
  int v9; // eax
  unsigned int v10; // ebx
  int v11; // ebx
  unsigned __int32 v12; // eax
  int *v13; // [esp+Ch] [ebp-8h]
  int *v14; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v13 = (int *)a3[10]; /*0x18d38b*/
  v14 = (int *)a1[10]; /*0x18d394*/
  v3 = a1[3]; /*0x18d39a*/
  if ( a3[3] != v3 ) /*0x18d3a0*/
  {
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 12) + 36) + 24) = 0; /*0x18d3a8*/
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3[3] + 12) + 36) + 24) = 1; /*0x18d3b8*/
  }
  active_threads = (thread_act_t)a3; /*0x18d3bf*/
  active_stacks[0] = a3[11]; /*0x18d3c8*/
  stack_pointers = a3[11] + 4084; /*0x18d3d7*/
  v4 = *(_DWORD *)(*v13 + 28); /*0x18d3e7*/
  if ( *(_DWORD *)(*v14 + 28) != v4 ) /*0x18d3ed*/
    __writecr3(v4); /*0x18d3ef*/
  v5 = v13[29]; /*0x18d3f5*/
  if ( v14[29] != v5 || v13[30] != v14[30] ) /*0x18d406*/
  {
    v6 = gdt; /*0x18d408*/
    v7 = v13[30] - 1; /*0x18d414*/
    *((_WORD *)gdt + 17) = v5; /*0x18d415*/
    v6[36] = BYTE2(v5); /*0x18d41e*/
    v6[39] = HIBYTE(v5); /*0x18d426*/
    v6[37] = v6[37] & 0x60 | 0x82; /*0x18d430*/
    v6[38] &= ~0x80u; /*0x18d433*/
    *((_WORD *)v6 + 16) = v7; /*0x18d437*/
    v6[38] = BYTE2(v7) & 0xF | v6[38] & 0xF0; /*0x18d448*/
    __asm { lldt ds:word_1D14EA } /*0x18d44b*/
  }
  v8 = gdt; /*0x18d452*/
  v9 = *v13 - 0x40000000; /*0x18d45d*/
  v10 = v13[1] - 1; /*0x18d465*/
  *((_WORD *)gdt + 13) = *(_WORD *)v13; /*0x18d466*/
  v8[28] = BYTE2(v9); /*0x18d46f*/
  v8[31] = HIBYTE(v9); /*0x18d475*/
  v8[29] = -119; /*0x18d478*/
  v8[30] &= ~0x80u; /*0x18d47c*/
  *((_WORD *)v8 + 12) = v10; /*0x18d480*/
  v11 = HIWORD(v10); /*0x18d484*/
  v8[30] = v11 & 0xF | v8[30] & 0xF0; /*0x18d493*/
  __asm { ltr word ptr ds:unk_1D14E8 } /*0x18d496*/
  v12 = __readcr0(); /*0x18d49d*/
  LOBYTE(v12) = v12 | 8; /*0x18d4a0*/
  __writecr0(v12); /*0x18d4a2*/
  a1[13] = a2; /*0x18d4ab*/
  if ( a2 ) /*0x18d4b0*/
    _switch_tss(v11, (int)&savedregs, a2, *v13, 0, *v13, (int)a1); /*0x18d4bb*/
  else
    _switch_tss(v11, (int)&savedregs, *v14, *v13, *v14, *v13, (int)a1); /*0x18d4d0*/
}
