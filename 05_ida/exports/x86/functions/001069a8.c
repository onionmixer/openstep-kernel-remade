/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1069a8. */
int __cdecl cloneproc(int a1, int a2, int a3)
{
  int i; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v16; // [esp+Ch] [ebp-10h]
  int posix_proc; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]

  v20 = *(_DWORD *)(*(_DWORD *)(a1 + 104) + 56); /*0x1069ba*/
  do /*0x106a99*/
  {
    ++mpid; /*0x1069bd*/
    while ( 1 ) /*0x1069c3*/
    {
      if ( mpid > 29999 ) /*0x1069cd*/
      {
        mpid = 100; /*0x1069cf*/
        dword_1DA86C = 0; /*0x1069d9*/
      }
      if ( mpid < dword_1DA86C ) /*0x1069ee*/
        break; /*0x1069ee*/
      v16 = 0; /*0x1069f4*/
      dword_1DA86C = 30000; /*0x1069fb*/
      for ( i = allproc; ; i = *(_DWORD *)(i + 8) ) /*0x106a05*/
      {
        while ( !i ) /*0x106a6d*/
        {
          if ( v16 ) /*0x106a73*/
            goto LABEL_20; /*0x106a73*/
          v16 = 1; /*0x106a75*/
          i = zombproc; /*0x106a7c*/
        }
        if ( (*(__int16 *)(i + 48) == mpid || *(__int16 *)(i + 46) == mpid) && ++mpid >= dword_1DA86C ) /*0x106a34*/
          break; /*0x106a34*/
        v4 = *(__int16 *)(i + 48); /*0x106a36*/
        if ( mpid < v4 && dword_1DA86C > v4 ) /*0x106a48*/
          dword_1DA86C = *(__int16 *)(i + 48); /*0x106a4a*/
        v5 = *(__int16 *)(i + 46); /*0x106a4f*/
        if ( mpid < v5 && dword_1DA86C > v5 ) /*0x106a61*/
          dword_1DA86C = *(__int16 *)(i + 46); /*0x106a63*/
      }
    }
LABEL_20:
    ; /*0x106a84*/
  }
  while ( !insert_posix_proc(a3, mpid) ); /*0x106a99*/
  v6 = freeproc; /*0x106a9f*/
  if ( !freeproc ) /*0x106aa7*/
  {
    v7 = getproc(); /*0x106aa9*/
    v6 = v7; /*0x106aae*/
    if ( !v7 ) /*0x106ab2*/
      panic(aNoProcs); /*0x106ab9*/
    *(_DWORD *)(v7 + 8) = freeproc; /*0x106ac7*/
    freeproc = v7; /*0x106aca*/
  }
  freeproc = *(_DWORD *)(v6 + 8); /*0x106ad3*/
  *(_BYTE *)(v6 + 19) = 4; /*0x106ad9*/
  *(_DWORD *)(v6 + 96) = 0; /*0x106add*/
  *(_DWORD *)(v6 + 92) = 0; /*0x106ae4*/
  v8 = *(_DWORD *)(a1 + 40) & 0x2108000; /*0x106aee*/
  LOBYTE(v8) = 1; /*0x106af3*/
  *(_DWORD *)(v6 + 40) = v8; /*0x106af5*/
  *(_WORD *)(v6 + 44) = *(_WORD *)(a1 + 44); /*0x106afc*/
  *(_DWORD *)(v6 + 40) |= *(_DWORD *)(a1 + 40) & 0x40000000; /*0x106b08*/
  *(_BYTE *)(v6 + 22) = *(_BYTE *)(a1 + 22) & 2 | *(_BYTE *)(v6 + 22) & 0xFD; /*0x106b18*/
  posix_proc = get_posix_proc(*(__int16 *)(a1 + 48)); /*0x106b25*/
  *(_WORD *)(a3 + 4) = *(_WORD *)(posix_proc + 4); /*0x106b2f*/
  *(_WORD *)(a3 + 6) = *(_WORD *)(posix_proc + 6); /*0x106b3d*/
  *(_WORD *)(a3 + 8) = *(_WORD *)(posix_proc + 8); /*0x106b4b*/
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(posix_proc + 16); /*0x106b58*/
  *(_BYTE *)(a3 + 24) &= 0xFCu; /*0x106b5b*/
  *(_DWORD *)(a3 + 20) = 0; /*0x106b5f*/
  *(_WORD *)(v6 + 46) = *(_WORD *)(a1 + 46); /*0x106b6a*/
  *(_BYTE *)(v6 + 21) = *(_BYTE *)(a1 + 21); /*0x106b71*/
  *(_WORD *)(v6 + 48) = *(_WORD *)a3; /*0x106b7a*/
  *(_WORD *)(v6 + 50) = *(_WORD *)(a1 + 48); /*0x106b82*/
  *(_DWORD *)(v6 + 68) = a1; /*0x106b86*/
  *(_DWORD *)(v6 + 76) = *(_DWORD *)(a1 + 72); /*0x106b8c*/
  v9 = *(_DWORD *)(a1 + 72); /*0x106b92*/
  if ( v9 ) /*0x106b97*/
    *(_DWORD *)(v9 + 80) = v6; /*0x106b99*/
  *(_DWORD *)(v6 + 80) = 0; /*0x106b9c*/
  *(_DWORD *)(v6 + 72) = 0; /*0x106ba3*/
  *(_DWORD *)(a1 + 72) = v6; /*0x106baa*/
  *(_BYTE *)(v6 + 20) = 0; /*0x106bad*/
  *(_BYTE *)(v6 + 18) = 0; /*0x106bb1*/
  *(_DWORD *)(v6 + 28) = *(_DWORD *)(a1 + 28); /*0x106bb8*/
  *(_DWORD *)(v6 + 36) = *(_DWORD *)(a1 + 36); /*0x106bbe*/
  *(_DWORD *)(v6 + 32) = *(_DWORD *)(a1 + 32); /*0x106bc4*/
  *(_DWORD *)(v6 + 124) = 0; /*0x106bc7*/
  *(_DWORD *)(v6 + 128) = 0; /*0x106bce*/
  *(_WORD *)(v6 + 52) = 0; /*0x106bd8*/
  *(_DWORD *)(v6 + 24) = 0; /*0x106bde*/
  *(_BYTE *)(v6 + 23) = 0; /*0x106be5*/
  *(_BYTE *)(v6 + 22) &= ~1u; /*0x106be9*/
  pidhash_enter(v6); /*0x106bee*/
  v10 = *(_DWORD *)(v20 + 352); /*0x106bf9*/
  if ( v10 ) /*0x106c01*/
    ++*(_WORD *)(v10 + 6); /*0x106c03*/
  v11 = *(_DWORD *)(v20 + 356); /*0x106c0a*/
  if ( v11 ) /*0x106c12*/
    ++*(_WORD *)(v11 + 6); /*0x106c14*/
  ++**(_WORD **)(v20 + 28); /*0x106c1e*/
  *(_DWORD *)(a1 + 40) |= 0x100u; /*0x106c21*/
  *(_DWORD *)(v6 + 112) = 0; /*0x106c28*/
  *(_DWORD *)(v6 + 116) = 0; /*0x106c2f*/
  *(_DWORD *)(v6 + 120) = 0; /*0x106c36*/
  v19 = procdup(v6, a1); /*0x106c44*/
  for ( j = 0; ; ++j ) /*0x106c47*/
  {
    v14 = *(_DWORD *)(v6 + 104); /*0x106c7f*/
    if ( *(_DWORD *)(*(_DWORD *)(v14 + 56) + 344) < j ) /*0x106c8e*/
      break; /*0x106c8e*/
    v12 = *(_DWORD *)(*(_DWORD *)(v14 + 56) + 336); /*0x106c57*/
    v13 = *(_DWORD *)(v12 + 4 * j); /*0x106c60*/
    if ( v13 ) /*0x106c65*/
    {
      if ( v13 == -65536 ) /*0x106c6c*/
        *(_DWORD *)(v12 + 4 * j) = 0; /*0x106c6e*/
      else
        ++*(_WORD *)(v13 + 14); /*0x106c78*/
    }
  }
  lock_init((void *)(*(_DWORD *)(*(_DWORD *)(v6 + 104) + 56) + 32), 1); /*0x106c9c*/
  uarea_init(v19); /*0x106ca5*/
  *(_DWORD *)(a3 + 12) = *(_DWORD *)(posix_proc + 12); /*0x106cb3*/
  *(_DWORD *)(posix_proc + 12) = v6; /*0x106cb9*/
  *(_DWORD *)(v6 + 8) = allproc; /*0x106cc2*/
  *(_DWORD *)(allproc + 12) = v6 + 8; /*0x106ccd*/
  *(_DWORD *)(v6 + 12) = &allproc; /*0x106cd0*/
  allproc = v6; /*0x106cd7*/
  *(_BYTE *)(v6 + 19) = 3; /*0x106cdd*/
  spl0(); /*0x106ce1*/
  *(_DWORD *)(a1 + 40) &= ~0x100u; /*0x106ce6*/
  return v19; /*0x106cf3*/
}
