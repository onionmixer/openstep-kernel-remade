/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192698. */
void __cdecl mach_kernel_trap(int a1)
{
  int v1; // edx
  char v2; // al
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  void *v6; // esp
  int v7; // esi
  int *v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // [esp-10h] [ebp-34h]
  _BYTE v12[12]; // [esp+0h] [ebp-24h] BYREF
  int v13; // [esp+Ch] [ebp-18h]
  int v14; // [esp+10h] [ebp-14h]
  _BYTE *v15; // [esp+14h] [ebp-10h]
  _BYTE *v16; // [esp+18h] [ebp-Ch]
  int *v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v18 = a1 + 52; /*0x1926a7*/
  v13 = a1; /*0x1926aa*/
  v1 = *(_DWORD *)(active_threads + 40); /*0x1926b2*/
  v2 = *(_BYTE *)(v1 + 240); /*0x1926b5*/
  if ( (v2 & 1) != 0 ) /*0x1926bd*/
  {
    *(_BYTE *)(v1 + 240) = v2 & 0xFE; /*0x1926c1*/
    *(_DWORD *)(v13 + 64) |= 0x100u; /*0x1926ca*/
  }
  v3 = -*(_DWORD *)(v13 + 44); /*0x1926d7*/
  if ( *(int *)(v13 + 44) > 0 || mach_trap_count <= v3 ) /*0x1926e1*/
  {
    *(_DWORD *)(v13 + 44) = kern_invalid(); /*0x1926eb*/
    thread_exception_return(); /*0x1926ee*/
  }
  v17 = &mach_trap_table[4 * v3]; /*0x1926fe*/
  v4 = *v17; /*0x192701*/
  v14 = v4; /*0x192707*/
  if ( v4 <= 0 ) /*0x19270c*/
  {
    *(_DWORD *)(v13 + 44) = ((int (*)(void))v17[1])(); /*0x19277b*/
  }
  else
  {
    v16 = v12; /*0x19270e*/
    v5 = 4 * v4; /*0x192711*/
    v6 = alloca(4 * v4); /*0x192718*/
    v15 = v12; /*0x19271a*/
    v7 = v18; /*0x192722*/
    if ( copyin(*(_DWORD *)(v18 + 16) + 4, (unsigned int)v12, 4 * v4) ) /*0x19272c*/
      exception(1, (exception_data_t)1, *(_DWORD *)(v7 + 16) + 4); /*0x192743*/
    v8 = (int *)&v15[v5 - 4]; /*0x19274b*/
    v9 = v14; /*0x19274f*/
    do /*0x19275c*/
    {
      v11 = *v8--; /*0x192757*/
      --v9; /*0x19275b*/
    }
    while ( v9 ); /*0x19275c*/
    v10 = ((int (__cdecl *)(int))v17[1])(v11); /*0x192761*/
    *(_DWORD *)(v13 + 44) = v10; /*0x192768*/
  }
  thread_exception_return(); /*0x19277e*/
}
