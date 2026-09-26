/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119538. */
char *vfs_mountroot()
{
  int v0; // esi
  const char **v1; // ebx
  char **v2; // edi
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edx
  char *result; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v0 = 0; /*0x119541*/
  rootvfs = kalloc(0x12Cu); /*0x11954d*/
  v1 = (const char **)&vfssw; /*0x119555*/
  if ( vfsNVFS <= (char *)&vfssw ) /*0x119560*/
  {
LABEL_4:
    v2 = nullptr; /*0x119583*/
  }
  else
  {
    while ( strcmp(rootfs, *v1) ) /*0x119576*/
    {
      v1 += 2; /*0x119578*/
      if ( vfsNVFS <= (char *)v1 ) /*0x119581*/
        goto LABEL_4; /*0x119581*/
    }
    v2 = (char **)v1; /*0x1195f0*/
  }
  if ( v2 ) /*0x119587*/
  {
    v3 = rootvfs; /*0x119589*/
    *(_DWORD *)rootvfs = 0; /*0x11958e*/
    *(_DWORD *)(v3 + 4) = v2[1]; /*0x119597*/
    *(_DWORD *)(v3 + 12) = 0; /*0x11959a*/
    *(_DWORD *)(v3 + 28) = 0; /*0x1195a1*/
    *(_DWORD *)(v3 + 296) = 0; /*0x1195a8*/
    *(_DWORD *)(v3 + 288) = 0; /*0x1195b2*/
    *(_WORD *)(v3 + 292) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x1195c9*/
    v0 = (*(int (__cdecl **)(int, int *, void *))(*(_DWORD *)(v3 + 4) + 24))(v3, &rootvp, &unk_1E9900); /*0x1195e3*/
    goto LABEL_13; /*0x1195e8*/
  }
  v2 = &vfssw; /*0x1195f4*/
  if ( vfsNVFS <= (char *)&vfssw )
  {
LABEL_13:
    if ( v0 )
    {
      printf("vfs_mountroot: error=%d\n", v0);
      panic(aVfsMountrootCa); /*0x119691*/
    }
    goto LABEL_15; /*0x11967f*/
  }
  v4 = &off_1DB644; /*0x119601*/
  while ( 1 ) /*0x119608*/
  {
    if ( *v4 ) /*0x119608*/
    {
      v5 = rootvfs; /*0x11960d*/
      *(_DWORD *)rootvfs = 0; /*0x119613*/
      *(_DWORD *)(v5 + 4) = *v4; /*0x11961b*/
      *(_DWORD *)(v5 + 12) = 0; /*0x11961e*/
      *(_DWORD *)(v5 + 28) = 0; /*0x119625*/
      *(_DWORD *)(v5 + 296) = 0; /*0x11962c*/
      *(_DWORD *)(v5 + 288) = 0; /*0x119636*/
      *(_WORD *)(v5 + 292) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x11964c*/
      v0 = (*(int (__cdecl **)(int, int *, void *))(*(_DWORD *)(v5 + 4) + 24))(v5, &rootvp, &unk_1E9900); /*0x119666*/
      if ( !v0 ) /*0x11966d*/
        break; /*0x11966d*/
    }
    v4 += 2; /*0x11966f*/
    v2 += 2; /*0x119672*/
    if ( vfsNVFS <= (char *)v2 ) /*0x11967b*/
      goto LABEL_13; /*0x11967b*/
  }
LABEL_15:
  if ( (*(int (__cdecl **)(int, int *))(*(_DWORD *)(rootvfs + 4) + 8))(rootvfs, &rootdir) ) /*0x1196aa*/
    panic(aVfsMountrootCa_0); /*0x1196ba*/
  *(_DWORD *)(active_u + 352) = rootdir; /*0x1196cd*/
  ++*(_WORD *)(*(_DWORD *)(active_u + 352) + 6); /*0x1196de*/
  *(_DWORD *)(active_u + 356) = 0; /*0x1196e7*/
  if ( rootname && !lookupname((int)&rootname, 1, 1, 0, (int)&v7) ) /*0x119709*/
  {
    rootdir = v7; /*0x119718*/
    vn_rele(*(_DWORD *)(active_u + 352)); /*0x11972a*/
    vn_rele(*(_DWORD *)(active_u + 352)); /*0x11973b*/
    *(_DWORD *)(active_u + 352) = rootdir; /*0x11974b*/
    ++*(_WORD *)(rootdir + 6); /*0x119756*/
  }
  dword_1E9988 = rootvp; /*0x119763*/
  result = strcpy(rootfs, *v2); /*0x119771*/
  dword_1E9984 = 0; /*0x119776*/
  dword_1E9980 = 1; /*0x119780*/
  return result; /*0x11978d*/
}
