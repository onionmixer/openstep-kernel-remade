/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c4b8. */
int __cdecl nfsgetattr(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // edx
  int v5; // edx
  unsigned int v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // edx
  int *v11; // [esp+14h] [ebp-14h]
  int v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch]
  _DWORD v14[2]; // [esp+20h] [ebp-8h] BYREF

  v12 = a1[12]; /*0x12c4c7*/
  getthetime(v14); /*0x12c4ce*/
  v4 = *(_DWORD *)(v12 + 192); /*0x12c4d9*/
  if ( v14[0] < v4 || v14[0] == v4 && v14[1] < *(_DWORD *)(v12 + 196) ) /*0x12c4f1*/
  {
    qmemcpy(a2, (const void *)(v12 + 128), 0x40u); /*0x12c507*/
    v5 = *(_DWORD *)(*(_DWORD *)(a1[9] + 296) + 40); /*0x12c512*/
    BYTE1(v5) = -1; /*0x12c515*/
    a2[3] = v5; /*0x12c51a*/
    v6 = *(_DWORD *)(*a1 + 20); /*0x12c51f*/
    if ( a2[6] < v6 && ((*(_BYTE *)(*a1 + 56) & 2) != 0 || (*(_BYTE *)(v12 + 96) & 0x10) != 0) ) /*0x12c534*/
      a2[6] = v6; /*0x12c539*/
    v13 = 0; /*0x12c53c*/
  }
  else
  {
    v11 = (int *)kalloc(0x48u); /*0x12c54f*/
    v7 = rfscall(*(_DWORD *)(a1[9] + 296), 1, xdr_fhandle, a1[12] + 64, xdr_attrstat, v11, a3); /*0x12c57c*/
    if ( !v7 ) /*0x12c583*/
    {
      v7 = *v11; /*0x12c588*/
      if ( *v11 ) /*0x12c588*/
      {
        if ( v7 == 70 ) /*0x12c5bb*/
        {
          btrash((int)a1); /*0x12c5be*/
          vnode_uncache((int)a1); /*0x12c5c7*/
          mfs_invalidate(a1); /*0x12c5cd*/
          *(_DWORD *)(a1[12] + 192) = 0; /*0x12c5d5*/
          dnlc_purge_vp((int)a1); /*0x12c5e0*/
          binvalfree((int)a1); /*0x12c5e6*/
        }
      }
      else
      {
        nattr_to_vattr(a1, v11 + 1, a2); /*0x12c59a*/
        v8 = *(_DWORD *)(*(_DWORD *)(a1[9] + 296) + 40); /*0x12c5a8*/
        BYTE1(v8) = -1; /*0x12c5ab*/
        a2[3] = v8; /*0x12c5b0*/
      }
    }
    kfree((int)v11, 0x48u); /*0x12c5f4*/
    v13 = v7; /*0x12c5f9*/
    if ( !v7 ) /*0x12c601*/
    {
      v9 = a1[12]; /*0x12c619*/
      if ( *(char *)(v9 + 16) >= 0 /*0x12c63e*/
        && (*(_DWORD *)(v9 + 168) != a2[10] || *(_DWORD *)(v9 + 172) != a2[11] || *(_DWORD *)(v9 + 152) != a2[6]) )
      {
        sync_vp_invalidate(a1, a4); /*0x12c645*/
        vnode_uncache((int)a1); /*0x12c64b*/
        *(_DWORD *)(a1[12] + 192) = 0; /*0x12c653*/
        dnlc_purge_vp((int)a1); /*0x12c65e*/
        binvalfree((int)a1); /*0x12c664*/
      }
      if ( (a1[1] & 0x40) == 0 && (*(_BYTE *)(*(_DWORD *)(a1[9] + 296) + 20) & 0x10) == 0 ) /*0x12c67f*/
      {
        qmemcpy((void *)(a1[12] + 128), a2, 0x40u); /*0x12c695*/
        a1[10] = *a2; /*0x12c69c*/
        sub_12C380(a1); /*0x12c6a0*/
      }
    }
  }
  a2[6] = *(_DWORD *)(a1[12] + 152); /*0x12c6b1*/
  return v13; /*0x12c6ba*/
}
