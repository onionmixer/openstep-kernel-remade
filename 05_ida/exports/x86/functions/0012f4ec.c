/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f4ec. */
int *__cdecl makenfsnode(void *a1, int *a2, int a3)
{
  int *v3; // esi
  void *v4; // eax
  int v5; // edx
  __int16 v6; // dx
  int v8; // [esp+Ch] [ebp-8h]
  char v9; // [esp+10h] [ebp-4h]

  v9 = 0; /*0x12f4f5*/
  v3 = (int *)sub_12F8A8(a1, a3); /*0x12f506*/
  if ( !v3 ) /*0x12f50d*/
  {
    v4 = rpfreelist; /*0x12f513*/
    if ( rpfreelist && rnew >= nrnode ) /*0x12f528*/
    {
      v3 = (int *)rpfreelist; /*0x12f52a*/
      rpfreelist = *(void **)rpfreelist; /*0x12f52e*/
      sub_12F7D0(v4); /*0x12f535*/
      rp_rmhash(v3); /*0x12f53b*/
      rinactive(v3); /*0x12f541*/
      ++rreuse; /*0x12f546*/
    }
    else
    {
      if ( !rnode_zone ) /*0x12f55b*/
        rnode_zone = zinit(200, &unk_1E8480, 0, 0, aRnodeStructure); /*0x12f575*/
      v3 = (int *)zalloc(rnode_zone); /*0x12f589*/
      v3[3] = 0; /*0x12f58b*/
      vm_info_init(v3 + 3); /*0x12f596*/
      ++rnew; /*0x12f59b*/
    }
    v8 = v3[3]; /*0x12f5aa*/
    bzero(v3, 0xC8u); /*0x12f5b3*/
    v3[3] = v8; /*0x12f5bb*/
    mfs_uncache(v3 + 3); /*0x12f5bf*/
    *(_DWORD *)v3[3] = 0; /*0x12f5c7*/
    *(_DWORD *)(v3[3] + 20) = v3[38]; /*0x12f5d6*/
    bcopy(a1, v3 + 16, 0x20u); /*0x12f5e3*/
    *((_WORD *)v3 + 9) = 1; /*0x12f5e8*/
    v3[10] = (int)&nfs_vnodeops; /*0x12f5ee*/
    if ( a2 ) /*0x12f5fc*/
    {
      v5 = *a2; /*0x12f601*/
      if ( *a2 == 4 && a2[7] == -1 ) /*0x12f60c*/
        v5 = 8; /*0x12f60e*/
      v3[13] = v5; /*0x12f613*/
      if ( *a2 == 4 && a2[7] == -1 ) /*0x12f622*/
        v6 = 0; /*0x12f630*/
      else
        v6 = *((_WORD *)a2 + 14); /*0x12f627*/
      *((_WORD *)v3 + 28) = v6; /*0x12f632*/
    }
    v3[15] = (int)v3; /*0x12f636*/
    v3[12] = a3; /*0x12f63c*/
    sub_12F698(v3); /*0x12f640*/
    ++*(_DWORD *)(*(_DWORD *)(a3 + 296) + 24); /*0x12f64b*/
    v9 = 1; /*0x12f64e*/
  }
  if ( a2 ) /*0x12f65b*/
  {
    if ( !v9 ) /*0x12f661*/
      nfs_cache_check((int)(v3 + 3), a2[13], a2[14], a2[5], 0); /*0x12f678*/
    nfs_attrcache((int)(v3 + 3), (int)a2); /*0x12f685*/
  }
  return v3 + 3; /*0x12f68f*/
}
