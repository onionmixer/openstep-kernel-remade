/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18449c. */
int __cdecl sub_18449C(id a1, int *a2, int a3)
{
  id v3; // eax
  unsigned int v5; // edx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  unsigned int v14; // [esp+Ch] [ebp-FCh]
  int v15; // [esp+Ch] [ebp-FCh]
  id v16; // [esp+10h] [ebp-F8h]
  void *v17; // [esp+14h] [ebp-F4h]
  int v18; // [esp+18h] [ebp-F0h]
  int v19; // [esp+1Ch] [ebp-ECh]
  vm_map_t v20; // [esp+20h] [ebp-E8h]
  char v21; // [esp+24h] [ebp-E4h]
  int v22; // [esp+28h] [ebp-E0h]
  id v23; // [esp+2Ch] [ebp-DCh]
  _DWORD v24[8]; // [esp+30h] [ebp-D8h] BYREF
  bool v25; // [esp+50h] [ebp-B8h]
  int v26; // [esp+54h] [ebp-B4h]
  int v27; // [esp+58h] [ebp-B0h]
  char v28; // [esp+5Ch] [ebp-ACh]
  char v29; // [esp+5Fh] [ebp-A9h]
  char v30; // [esp+64h] [ebp-A4h]
  int v31; // [esp+68h] [ebp-A0h]
  unsigned int v32; // [esp+6Ch] [ebp-9Ch]
  unsigned int v33; // [esp+70h] [ebp-98h]
  _BYTE v34[2]; // [esp+9Ch] [ebp-6Ch] BYREF
  int v35; // [esp+9Eh] [ebp-6Ah]
  int v36; // [esp+A2h] [ebp-66h]
  int v37; // [esp+A6h] [ebp-62h]
  bool v38; // [esp+AAh] [ebp-5Eh]
  int v39; // [esp+ACh] [ebp-5Ch]
  int v40; // [esp+B0h] [ebp-58h]
  char v41; // [esp+B4h] [ebp-54h]
  char v42; // [esp+B7h] [ebp-51h]
  char v43; // [esp+BCh] [ebp-4Ch]
  int v44; // [esp+C0h] [ebp-48h]
  unsigned int v45; // [esp+C4h] [ebp-44h]
  unsigned int v46; // [esp+C8h] [ebp-40h]
  int v47; // [esp+F0h] [ebp-18h] BYREF
  int v48; // [esp+F4h] [ebp-14h] BYREF
  _BYTE v49[8]; // [esp+F8h] [ebp-10h] BYREF
  unsigned int v50; // [esp+100h] [ebp-8h]
  unsigned int v51; // [esp+104h] [ebp-4h]

  v22 = 0; /*0x1844ae*/
  v21 = 0; /*0x1844b8*/
  v20 = 0; /*0x1844bf*/
  v19 = 0; /*0x1844c9*/
  if ( a2 ) /*0x1844d5*/
  {
    v14 = a2[5]; /*0x1844da*/
    v18 = a2[3]; /*0x1844e3*/
    v17 = (void *)a2[4]; /*0x1844ec*/
  }
  else
  {
    if ( !a3 ) /*0x1844f6*/
      IOPanic(aSgDoiocreqNoSc); /*0x18451d*/
    v14 = *(_DWORD *)(a3 + 24); /*0x1844fb*/
    v18 = *(_DWORD *)(a3 + 16); /*0x184504*/
    v17 = *(void **)(a3 + 20); /*0x18450d*/
  }
  v3 = objc_msgSend(a1, sel_controller); /*0x184537*/
  if ( v14 > (unsigned int)objc_msgSend(v3, sel_maxTransfer) ) /*0x18454e*/
    return 22; /*0x184555*/
  if ( v14 ) /*0x184563*/
  {
    v16 = objc_msgSend(a1, sel_controller); /*0x184579*/
    objc_msgSend(v16, sel_getDMAAlignment_, v49); /*0x184591*/
    if ( v18 == 1 ) /*0x1845a0*/
      v5 = v51; /*0x1845a2*/
    else
      v5 = v50; /*0x1845a8*/
    v21 = 1; /*0x1845ab*/
    v20 = kernel_map; /*0x1845b8*/
    if ( v5 <= 1 ) /*0x1845c1*/
      v22 = v14; /*0x1845e2*/
    else
      v22 = -v5 & (v5 + v14 - 1); /*0x1845d1*/
    v23 = objc_msgSend(v16, sel_allocateBufferOfLength_actualStart_actualLength_, v14, &v48, &v47); /*0x18460a*/
    if ( v18 == 1 ) /*0x18461a*/
    {
      v19 = copyin(v17, v23, v14); /*0x184636*/
      if ( v19 ) /*0x184641*/
      {
        v19 = 14; /*0x184643*/
        goto LABEL_33; /*0x18464d*/
      }
    }
  }
  else
  {
    v23 = v17; /*0x18465a*/
  }
  if ( a2 ) /*0x184662*/
  {
    bzero(v34, 0x54u); /*0x18466e*/
    LODWORD(v6) = objc_msgSend(a1, sel_SCSI3_target); /*0x18467e*/
    if ( v6 > 0x1F || (v34[0] = v6, LODWORD(v7) = objc_msgSend(a1, sel_SCSI3_lun), v7 > 7) ) /*0x1846b0*/
    {
      v19 = 22; /*0x1846b2*/
      goto LABEL_33; /*0x1846bc*/
    }
    v34[1] = v7; /*0x1846c4*/
    v35 = *a2; /*0x1846c9*/
    v36 = a2[1]; /*0x1846cf*/
    v37 = a2[2]; /*0x1846d5*/
    v38 = a2[3] == 0; /*0x1846df*/
    v39 = v22; /*0x1846e8*/
    v40 = a2[6]; /*0x1846ee*/
    v41 = ((*((_BYTE *)a2 + 73) & 1) == 0) | v41 & 0xFE; /*0x184703*/
    v41 = *((_BYTE *)a2 + 73) & 2 | v41 & 0xFD; /*0x184711*/
    v41 = *((_BYTE *)a2 + 73) & 4 | v41 & 0xFB; /*0x18471f*/
    v42 = (16 * *((_BYTE *)a2 + 72)) | v42 & 0xF; /*0x184730*/
    a2[7] = (int)objc_msgSend(a1, sel_executeRequest_buffer_client_senseBuf_, v34, v23, v20, (char *)a2 + 33); /*0x184759*/
    *((_BYTE *)a2 + 32) = v43; /*0x18475f*/
    v8 = v44; /*0x184762*/
    a2[15] = v44; /*0x184765*/
    v15 = v8; /*0x184768*/
    v9 = a2[5]; /*0x18476e*/
    if ( v15 > v9 ) /*0x18477a*/
      a2[15] = v9; /*0x18477c*/
    ns_time_to_timeval(v45, v46, a2 + 16); /*0x18478b*/
  }
  else
  {
    bzero(v24, 0x6Cu); /*0x18479f*/
    v24[0] = objc_msgSend(a1, sel_SCSI3_target); /*0x1847b4*/
    v24[1] = v10; /*0x1847ba*/
    v24[2] = objc_msgSend(a1, sel_SCSI3_lun); /*0x1847d0*/
    v24[3] = v11; /*0x1847d6*/
    v24[4] = *(_DWORD *)a3; /*0x1847de*/
    v24[5] = *(_DWORD *)(a3 + 4); /*0x1847e7*/
    v24[6] = *(_DWORD *)(a3 + 8); /*0x1847f0*/
    v24[7] = *(_DWORD *)(a3 + 12); /*0x1847f9*/
    v25 = *(_DWORD *)(a3 + 16) == 0; /*0x184809*/
    v26 = v22; /*0x184815*/
    v27 = *(_DWORD *)(a3 + 28); /*0x18481e*/
    v28 = ((*(_BYTE *)(a3 + 77) & 1) == 0) | v28 & 0xFE; /*0x184839*/
    v28 = *(_BYTE *)(a3 + 77) & 2 | v28 & 0xFD; /*0x18484a*/
    v28 = *(_BYTE *)(a3 + 77) & 4 | v28 & 0xFB; /*0x18485b*/
    v29 = (16 * *(_BYTE *)(a3 + 76)) | v29 & 0xF; /*0x184872*/
    *(_DWORD *)(a3 + 32) = objc_msgSend(a1, sel_executeSCSI3Request_buffer_client_senseBuf_, v24, v23, v20, 33); /*0x18489f*/
    *(_BYTE *)(a3 + 36) = v30; /*0x1848a8*/
    v12 = v31; /*0x1848ab*/
    *(_DWORD *)(a3 + 64) = v31; /*0x1848b1*/
    v15 = v12; /*0x1848b4*/
    v13 = *(_DWORD *)(a3 + 24); /*0x1848ba*/
    if ( v15 > v13 ) /*0x1848c6*/
      *(_DWORD *)(a3 + 64) = v13; /*0x1848c8*/
    ns_time_to_timeval(v32, v33, (_DWORD *)(a3 + 68)); /*0x1848dd*/
  }
  if ( v18 || !v15 ) /*0x1848f5*/
    goto LABEL_33; /*0x1848f5*/
  if ( v21 ) /*0x1848fe*/
  {
    v19 = copyout(v23, v17, v15); /*0x18491a*/
LABEL_33:
    if ( v21 ) /*0x18492a*/
      IOFree(v48, v47); /*0x184934*/
  }
  return v19; /*0x184945*/
}
