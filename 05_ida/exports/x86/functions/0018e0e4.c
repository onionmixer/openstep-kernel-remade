/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e0e4. */
void __cdecl start_initial_context(_DWORD *a1)
{
  int *v1; // esi
  int v2; // edi
  _BYTE *v3; // edx
  int v4; // eax
  int v5; // ebx
  _BYTE *v6; // edx
  int v7; // eax
  unsigned int v8; // ebx
  unsigned __int32 v9; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v1 = (int *)a1[10]; /*0x18e0ed*/
  ldt_init(); /*0x18e0f0*/
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1[3] + 12) + 36) + 24) = 1; /*0x18e0fe*/
  active_threads = (thread_act_t)a1; /*0x18e105*/
  v2 = a1[11]; /*0x18e10b*/
  active_stacks[0] = v2; /*0x18e10e*/
  stack_pointers = a1[11] + 4084; /*0x18e11d*/
  __writecr3(*(_DWORD *)(*v1 + 28)); /*0x18e128*/
  v3 = gdt; /*0x18e12b*/
  v4 = v1[29]; /*0x18e131*/
  v5 = v1[30] - 1; /*0x18e137*/
  *((_WORD *)gdt + 17) = v4; /*0x18e138*/
  v3[36] = BYTE2(v4); /*0x18e141*/
  v3[39] = HIBYTE(v4); /*0x18e147*/
  v3[37] = v3[37] & 0x60 | 0x82; /*0x18e151*/
  v3[38] &= ~0x80u; /*0x18e154*/
  *((_WORD *)v3 + 16) = v5; /*0x18e158*/
  v3[38] = BYTE2(v5) & 0xF | v3[38] & 0xF0; /*0x18e16b*/
  __asm { lldt ds:word_1D14EA } /*0x18e16e*/
  v6 = gdt; /*0x18e175*/
  v7 = *v1 - 0x40000000; /*0x18e17d*/
  v8 = v1[1] - 1; /*0x18e185*/
  *((_WORD *)gdt + 13) = *(_WORD *)v1; /*0x18e186*/
  v6[28] = BYTE2(v7); /*0x18e18f*/
  v6[31] = HIBYTE(v7); /*0x18e195*/
  v6[29] = -119; /*0x18e198*/
  v6[30] &= ~0x80u; /*0x18e19c*/
  *((_WORD *)v6 + 12) = v8; /*0x18e1a0*/
  v8 >>= 16; /*0x18e1a4*/
  v6[30] = v8 & 0xF | v6[30] & 0xF0; /*0x18e1b3*/
  __asm { ltr word ptr ds:unk_1D14E8 } /*0x18e1b6*/
  v9 = __readcr0(); /*0x18e1bd*/
  LOBYTE(v9) = v9 | 8; /*0x18e1c0*/
  __writecr0(v9); /*0x18e1c2*/
  _switch_tss(v8, (int)&savedregs, v2, *v1, 0, *v1, 0); /*0x18e1cc*/
}
