/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1925a0. */
void __cdecl machdep_call(int a1)
{
  int v1; // edx
  char v2; // al
  int v3; // ebx
  int v4; // edi
  void *v5; // esp
  int *v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // [esp-4h] [ebp-28h]
  _BYTE v10[12]; // [esp+0h] [ebp-24h] BYREF
  int v11; // [esp+Ch] [ebp-18h]
  int v12; // [esp+10h] [ebp-14h]
  _BYTE *v13; // [esp+14h] [ebp-10h]
  _BYTE *v14; // [esp+18h] [ebp-Ch]
  int (**v15)(); // [esp+1Ch] [ebp-8h]
  int v16; // [esp+20h] [ebp-4h]

  v16 = a1 + 52; /*0x1925af*/
  v11 = a1; /*0x1925b2*/
  v1 = *(_DWORD *)(active_threads + 40); /*0x1925ba*/
  v2 = *(_BYTE *)(v1 + 240); /*0x1925bd*/
  if ( (v2 & 1) != 0 ) /*0x1925c5*/
  {
    *(_BYTE *)(v1 + 240) = v2 & 0xFE; /*0x1925c9*/
    *(_DWORD *)(v11 + 64) |= 0x100u; /*0x1925d2*/
  }
  v3 = *(_DWORD *)(v11 + 44); /*0x1925dc*/
  if ( v3 < 0 || machdep_call_count <= v3 ) /*0x1925e9*/
  {
    *(_DWORD *)(v11 + 44) = kern_invalid(); /*0x1925f3*/
    thread_exception_return(); /*0x1925f6*/
  }
  v15 = &machdep_call_table[2 * v3]; /*0x192608*/
  v4 = (int)v15[1]; /*0x19260b*/
  v12 = v4; /*0x19260e*/
  if ( v4 <= 0 ) /*0x192613*/
  {
    *(_DWORD *)(v11 + 44) = machdep_call_table[2 * v3](); /*0x192683*/
  }
  else
  {
    v14 = v10; /*0x192615*/
    v5 = alloca(4 * v4); /*0x19261f*/
    v13 = v10; /*0x192621*/
    if ( copyin(*(_DWORD *)(v16 + 16) + 4, (unsigned int)v10, 4 * v4) ) /*0x192633*/
    {
      *(_DWORD *)(v11 + 44) = 1; /*0x192642*/
      thread_exception_return(); /*0x192649*/
    }
    v6 = (int *)&v13[4 * v4 - 4]; /*0x192651*/
    v7 = v12; /*0x192655*/
    do /*0x192662*/
    {
      v9 = *v6--; /*0x19265d*/
      --v7; /*0x192661*/
    }
    while ( v7 ); /*0x192662*/
    v8 = ((int (__cdecl *)(int))*v15)(v9); /*0x192666*/
    *(_DWORD *)(v11 + 44) = v8; /*0x19266d*/
  }
  thread_exception_return(); /*0x192686*/
}
