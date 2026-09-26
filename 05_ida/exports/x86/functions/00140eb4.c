/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140eb4. */
void __cdecl iupdat(int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx
  int *v4; // eax
  int *v5; // edi
  __int16 v6; // dx
  int v7; // ebx
  __int16 v8; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 80); /*0x140ec0*/
  if ( (*(_BYTE *)(a1 + 68) & 0x4E) != 0 && !*(_BYTE *)(v2 + 210) ) /*0x140ecd*/
  {
    v3 = *(_DWORD *)(a1 + 72) / *(_DWORD *)(v2 + 184); /*0x140eed*/
    v4 = bread( /*0x140f33*/
           *(_DWORD *)(a1 + 64),
           ((((unsigned int)(*(_DWORD *)(a1 + 72) % *(_DWORD *)(v2 + 184)) / *(_DWORD *)(v2 + 120)) << *(_DWORD *)(v2 + 96))
          + *(_DWORD *)(v2 + 16)
          + *(_DWORD *)(v2 + 24) * (~*(_DWORD *)(v2 + 28) & v3)
          + v3 * *(_DWORD *)(v2 + 188)) << *(_DWORD *)(v2 + 100),
           *(_DWORD *)(v2 + 48));
    v5 = v4; /*0x140f38*/
    if ( (*(_BYTE *)v4 & 4) != 0 ) /*0x140f40*/
    {
      brelse((int)v4); /*0x140f43*/
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 68) & 0x46) != 0 ) /*0x140f54*/
      {
        microtime(&iuniqtime); /*0x140f5b*/
        if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x140f67*/
          *(_DWORD *)(a1 + 116) = iuniqtime; /*0x140f6e*/
        if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x140f75*/
          *(_DWORD *)(a1 + 124) = iuniqtime; /*0x140f7d*/
        if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x140f84*/
        {
          *(_DWORD *)(a1 + 76) = 0; /*0x140f86*/
          *(_DWORD *)(a1 + 132) = iuniqtime; /*0x140f92*/
        }
      }
      v6 = *(_WORD *)(a1 + 68); /*0x140f98*/
      v8 = v6; /*0x140f9c*/
      LOBYTE(v6) = v6 & 0xB1; /*0x140fa0*/
      *(_WORD *)(a1 + 68) = v6; /*0x140fa3*/
      v7 = v5[8] + ((*(_DWORD *)(a1 + 72) % *(_DWORD *)(v2 + 120)) << 7); /*0x140fb6*/
      *(_WORD *)(a1 + 68) = v8 & 0xFDB1; /*0x140fc1*/
      byte_swap_inode_out(a1, v7); /*0x140fc7*/
      if ( *(_WORD *)(*(_DWORD *)(a1 + 48) + 292) ) /*0x140fd2*/
      {
        *(_WORD *)(v7 + 4) = _byteswap_ulong(*(__int16 *)(a1 + 228)); /*0x140fe5*/
        *(_WORD *)(v7 + 6) = _byteswap_ulong(*(__int16 *)(a1 + 230)); /*0x140ff2*/
      }
      if ( a2 ) /*0x140ffa*/
        bwrite(v5); /*0x140ffd*/
      else
        bdwrite((int)v5); /*0x141005*/
    }
  }
}
