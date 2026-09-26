/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13be90. */
int __cdecl ialloc(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // ebx
  int v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  unsigned __int16 v9; // dx
  int v11; // [esp+Ch] [ebp-4h]

  v3 = a2; /*0x13be99*/
  v4 = *(_DWORD *)(a1 + 80); /*0x13be9f*/
  if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) && *(_DWORD *)(v4 + 200) <= *(_DWORD *)(v4 + 148) /*0x13bec3*/
    || !*(_DWORD *)(v4 + 200) )
  {
    goto LABEL_14; /*0x13bec3*/
  }
  v5 = *(_DWORD *)(v4 + 184); /*0x13bed0*/
  if ( a2 >= v5 * *(_DWORD *)(v4 + 44) ) /*0x13bede*/
    v3 = 0; /*0x13bee0*/
  v6 = hashalloc(a1, v3 / v5, v3, a3, ialloccg); /*0x13bef9*/
  v11 = v6; /*0x13befe*/
  if ( !v6 )
  {
LABEL_14:
    if ( (*(_BYTE *)(v4 + 211) & 2) == 0 ) /*0x13bfa7*/
      fserr(v4, aOutOfInodes); /*0x13bfaf*/
    *(_BYTE *)(v4 + 211) |= 2u; /*0x13bfb7*/
    if ( (*(_BYTE *)(active_u + 608) & 8) == 0 )
      uprintf("\n%s: %s\n", (const char *)(v4 + 212), aCreateSymlinkF);
    if ( !*(_DWORD *)(dword_1E875C + 108) ) /*0x13bfe7*/
    {
      *(_DWORD *)(dword_1E875C + 108) = v4; /*0x13bfed*/
      *(_BYTE *)(dword_1E875C + 112) = 2; /*0x13bff5*/
    }
    *(_BYTE *)(dword_1E875C + 104) = 28; /*0x13bffe*/
    return 0; /*0x13bffe*/
  }
  v7 = iget(*(_WORD *)(a1 + 70), *(_DWORD *)(a1 + 80), v6); /*0x13bf16*/
  v8 = v7; /*0x13bf1b*/
  if ( !v7 ) /*0x13bf22*/
  {
    ifree(a1, v11, 0); /*0x13bf2e*/
    return 0; /*0x13c002*/
  }
  v9 = *(_WORD *)(v7 + 100); /*0x13bf38*/
  if ( v9 ) /*0x13bf3f*/
  {
    printf("mode = 0%o, inum = %d, fs = %s\n", v9, *(_DWORD *)(v7 + 72), (const char *)(v4 + 212)); /*0x13bf55*/
    panic(aIallocDupAlloc); /*0x13bf5f*/
  }
  if ( *(_DWORD *)(v7 + 204) ) /*0x13bf67*/
  {
    printf("free inode %s/%d had %d blocks\n", (const char *)(v4 + 212), v11, *(_DWORD *)(v7 + 204)); /*0x13bf82*/
    *(_DWORD *)(v8 + 204) = 0; /*0x13bf87*/
  }
  *(_DWORD *)(v8 + 200) = 0; /*0x13bf91*/
  return v8; /*0x13c007*/
}
