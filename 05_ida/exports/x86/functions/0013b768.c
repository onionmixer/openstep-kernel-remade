/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13b768. */
int __cdecl alloc(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int v9; // [esp+0h] [ebp-18h]
  int v10; // [esp+4h] [ebp-14h]
  int v11; // [esp+8h] [ebp-10h]
  unsigned int v12; // [esp+Ch] [ebp-Ch]

  v3 = a2; /*0x13b774*/
  v4 = *(_DWORD *)(a1 + 80); /*0x13b777*/
  v12 = *(_DWORD *)(v4 + 48); /*0x13b77d*/
  if ( a3 > v12 || (~*(_DWORD *)(v4 + 76) & a3) != 0 ) /*0x13b78d*/
  {
    printf("dev = 0x%x, bsize = %d, size = %d, fs = %s\n", *(__int16 *)(a1 + 70), v12, a3, (const char *)(v4 + 212)); /*0x13b7a8*/
    panic(aAllocBadSize); /*0x13b7b2*/
  }
  if ( *(_DWORD *)(v4 + 48) == a3 && !*(_DWORD *)(v4 + 196) /*0x13b80e*/
    || *(_WORD *)(*(_DWORD *)(active_u + 28) + 2)
    && *(_DWORD *)(v4 + 204)
     + (*(_DWORD *)(v4 + 196) << *(_DWORD *)(v4 + 96))
     - *(_DWORD *)(v4 + 60) * *(_DWORD *)(v4 + 40) / 100 <= 0 )
  {
    goto LABEL_15; /*0x13b80e*/
  }
  if ( *(_DWORD *)(v4 + 36) <= a2 ) /*0x13b817*/
    v3 = 0; /*0x13b819*/
  v5 = v3 ? v3 / *(_DWORD *)(v4 + 188) : *(_DWORD *)(a1 + 72) / *(_DWORD *)(v4 + 184);
  v6 = hashalloc(a1, v5, v3, a3, alloccg); /*0x13b84c*/
  if ( v6 <= 0 ) /*0x13b853*/
  {
LABEL_15:
    fsfull(v4, 1); /*0x13b8af*/
    return 0; /*0x13b8b4*/
  }
  else
  {
    *(_DWORD *)(a1 + 204) += a3 /*0x13b86e*/
                           / (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)(a1 + 40) + 128))(
                               a1 + 12,
                               v9,
                               v10,
                               v11);
    *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13b874*/
    v7 = getblk(*(_DWORD *)(a1 + 64), v6 << *(_DWORD *)(v4 + 100), a3); /*0x13b890*/
    blkclr(*(void **)(v7 + 32), *(_DWORD *)(v7 + 20)); /*0x13b89a*/
    *(_DWORD *)(v7 + 40) = 0; /*0x13b89f*/
    return v7; /*0x13b8a6*/
  }
}
