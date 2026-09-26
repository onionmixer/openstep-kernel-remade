/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c9b0. */
int __cdecl vnode_pager_allocpage(_DWORD *a1)
{
  int i; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // [esp+Ch] [ebp-8h]

  lock_write((int)(a1 + 13)); /*0x17c9c0*/
  if ( a1[6] ) /*0x17c9c8*/
  {
    i = 0; /*0x17c9e0*/
    v7 = a1[9] / 8; /*0x17c9ef*/
    v3 = a1[5]; /*0x17c9f2*/
    while ( 1 ) /*0x17c9f8*/
    {
      v4 = v3 + 7; /*0x17c9f8*/
      if ( v3 + 7 < 0 ) /*0x17c9fd*/
        v4 = v3 + 14; /*0x17c9ff*/
      if ( v7 >= v4 >> 3 ) /*0x17ca08*/
        break; /*0x17ca08*/
      if ( *(_BYTE *)(v7 + a1[4]) != 0xFF ) /*0x17ca14*/
      {
        for ( i = 0; i <= 7; ++i ) /*0x17ca16*/
        {
          v5 = *(char *)(i / 8 + a1[4] + v7); /*0x17ca3a*/
          if ( !_bittest(&v5, i % 8) ) /*0x17ca3d*/
            break; /*0x17ca40*/
        }
        break; /*0x17ca46*/
      }
      ++v7; /*0x17ca4c*/
    }
    v6 = i + 8 * v7; /*0x17ca54*/
    if ( a1[5] <= v6 ) /*0x17ca5d*/
      panic(aVnodePagerAllo); /*0x17ca64*/
    if ( a1[8] < v6 ) /*0x17ca6f*/
      a1[8] = v6; /*0x17ca71*/
    *(_BYTE *)(v6 / 8 + a1[4]) |= 1 << (v6 % 8); /*0x17ca9d*/
    --a1[6]; /*0x17caa0*/
    a1[9] = v6; /*0x17caa3*/
    lock_done((int)(a1 + 13)); /*0x17caaa*/
    return v6; /*0x17caaf*/
  }
  else
  {
    lock_done((int)(a1 + 13)); /*0x17c9cf*/
    return -1; /*0x17c9d4*/
  }
}
