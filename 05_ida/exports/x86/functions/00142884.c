/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142884. */
void __cdecl update(__int16 a1, unsigned __int16 a2)
{
  int i; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // ebx
  int v6; // esi
  __int16 v7; // ax
  int v8; // [esp+10h] [ebp-8h] BYREF

  if ( syncprt ) /*0x1428a0*/
    bufstats(); /*0x1428a2*/
  if ( !updlock ) /*0x1428ae*/
  {
    updlock = 1; /*0x1428b4*/
    for ( i = mounttab; i; i = *(_DWORD *)(i + 32) ) /*0x1428c6*/
    {
      if ( a1 == -1 || a1 == (*(_WORD *)(i + 4) & a2) ) /*0x1428d9*/
      {
        v3 = *(_DWORD *)(i + 12); /*0x1428db*/
        if ( v3 ) /*0x1428e0*/
        {
          if ( *(_WORD *)(i + 4) != 0xFFFF ) /*0x1428e7*/
          {
            v4 = *(_DWORD *)(v3 + 32); /*0x1428e9*/
            if ( *(_BYTE *)(v4 + 208) ) /*0x1428ec*/
            {
              if ( *(_BYTE *)(v4 + 210) ) /*0x1428f5*/
              {
                printf("fs = %s\n", (const char *)(v4 + 212)); /*0x14290a*/
                panic(aUpdateRoFsMod); /*0x142914*/
              }
              *(_BYTE *)(v4 + 208) = 0; /*0x14291c*/
              getthetime(&v8); /*0x142927*/
              *(_DWORD *)(v4 + 32) = v8; /*0x14292f*/
              sbupdate(i); /*0x142933*/
            }
          }
        }
      }
    }
    v5 = inode_list; /*0x142942*/
    if ( inode_list ) /*0x14294a*/
    {
      while ( 1 ) /*0x14294c*/
      {
        if ( a1 == -1 ) /*0x142950*/
          goto LABEL_19; /*0x142950*/
        if ( a1 == (*(_WORD *)(v5 + 70) & a2) ) /*0x14295d*/
          break; /*0x14295d*/
LABEL_23:
        v5 = *(_DWORD *)(v5 + 8); /*0x1429af*/
        if ( !v5 ) /*0x1429b4*/
          goto LABEL_24; /*0x1429b4*/
      }
      v6 = *(_DWORD *)(v5 + 12) + 24; /*0x142962*/
      if ( lock_try_write(v6) == 1 ) /*0x142971*/
      {
        lock_done(v6); /*0x142974*/
        mfs_fsync(v5 + 12); /*0x14297d*/
      }
LABEL_19:
      v7 = *(_WORD *)(v5 + 68); /*0x142985*/
      if ( (v7 & 1) == 0 && (v7 & 0x100) != 0 && (v7 & 0x4E) != 0 ) /*0x142994*/
      {
        *(_BYTE *)(v5 + 68) |= 1u; /*0x142996*/
        ++*(_WORD *)(v5 + 18); /*0x14299a*/
        iupdat(v5, 0); /*0x1429a1*/
        iput(v5); /*0x1429a7*/
      }
      goto LABEL_23; /*0x1429a7*/
    }
LABEL_24:
    updlock = 0; /*0x1429b6*/
    bflush(0, a1, a2); /*0x1429cb*/
  }
}
