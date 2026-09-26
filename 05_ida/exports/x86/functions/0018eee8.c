/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18eee8. */
int __cdecl pmap_bootstrap(int a1, int a2, unsigned int *a3, unsigned int *a4)
{
  int *v4; // edx
  char *v5; // eax
  int i; // ebx
  _DWORD *v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // ebx
  _BYTE *v10; // eax
  unsigned int *v11; // edx
  _DWORD *v12; // eax
  unsigned __int32 v13; // eax
  unsigned int v14; // ebx
  int v15; // esi
  _BYTE *v16; // eax
  _DWORD *v17; // edx
  _DWORD *v18; // eax
  unsigned __int32 v19; // eax
  unsigned int v20; // ebx
  unsigned int j; // esi
  _BYTE *v22; // eax
  unsigned int *v23; // edx
  _DWORD *v24; // eax
  unsigned int v25; // esi
  unsigned __int32 v26; // eax
  unsigned __int32 v27; // ebx
  _DWORD *v28; // edx
  _DWORD *v29; // eax
  unsigned int v30; // esi
  _BYTE *v31; // eax
  _DWORD *v32; // eax
  unsigned __int32 v33; // edx
  int result; // eax
  unsigned int v35; // [esp+10h] [ebp-14h]
  unsigned int v36; // [esp+10h] [ebp-14h]
  unsigned int v37; // [esp+10h] [ebp-14h]
  unsigned int v38; // [esp+14h] [ebp-10h]
  unsigned int v39; // [esp+18h] [ebp-Ch]
  unsigned int v40; // [esp+1Ch] [ebp-8h]
  unsigned int v41; // [esp+20h] [ebp-4h]

  v40 = *(_DWORD *)(a1 + 24); /*0x18eef7*/
  section_size = page_size >> 2 << 12; /*0x18ef08*/
  ptes_per_vm_page = page_size >> 12; /*0x18ef10*/
  v4 = kernel_prot_codes; /*0x18ef16*/
  v5 = &user_prot_codes; /*0x18ef1b*/
  for ( i = 0; i <= 7; ++i ) /*0x18ef20*/
  {
    switch ( i ) /*0x18ef29*/
    {
      case 0: /*0x18ef29*/
        *v4++ = 0; /*0x18ef50*/
        *(_DWORD *)v5 = 0; /*0x18ef59*/
        goto LABEL_6; /*0x18ef5f*/
      case 1: /*0x18ef29*/
      case 4: /*0x18ef29*/
      case 5: /*0x18ef29*/
        *v4++ = 0; /*0x18ef64*/
        *(_DWORD *)v5 = 2; /*0x18ef6d*/
        goto LABEL_6; /*0x18ef73*/
      case 2: /*0x18ef29*/
      case 3: /*0x18ef29*/
      case 6: /*0x18ef29*/
      case 7: /*0x18ef29*/
        *v4++ = 1; /*0x18ef78*/
        *(_DWORD *)v5 = 3; /*0x18ef81*/
LABEL_6:
        v5 += 4; /*0x18ef87*/
        break; /*0x18ef87*/
      default:
        continue;
    }
  }
  kernel_pmap = (int)&kernel_pmap_store; /*0x18ef90*/
  dword_1F7A6C = 0; /*0x18ef9a*/
  v39 = alloc_cnvmem(4096, 4096); /*0x18efba*/
  *(_DWORD *)kernel_pmap = v39; /*0x18efbd*/
  bzero((void *)v39, 0x1000u); /*0x18efc8*/
  v7 = (_DWORD *)kernel_pmap; /*0x18efcd*/
  *(_DWORD *)(kernel_pmap + 8) = 1; /*0x18efd2*/
  *v7 += 3072; /*0x18efd9*/
  v8 = 0; /*0x18efdf*/
  v35 = 0; /*0x18efe1*/
  v9 = 2 * (dword_1F7A8C & 3); /*0x18eff5*/
  for ( LOBYTE(v9) = v9 | 1; v35 < v40; v35 += 4096 ) /*0x18effd*/
  {
    v10 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (v8 >> 22)); /*0x18f012*/
    if ( (*v10 & 1) == 0 || (v11 = (unsigned int *)(((v8 >> 10) & 0xFFC) + (*(_DWORD *)v10 & 0xFFFFF000))) == nullptr ) /*0x18f02d*/
    {
      sub_18ECC0(v8); /*0x18f030*/
      v12 = (_DWORD *)(*(_DWORD *)kernel_pmap + 4 * (v8 >> 22)); /*0x18f046*/
      if ( (*(_BYTE *)v12 & 1) != 0 ) /*0x18f04b*/
        v11 = (unsigned int *)(((v8 >> 10) & 0xFFC) + (*v12 & 0xFFFFF000)); /*0x18f066*/
      else
        v11 = nullptr; /*0x18f04d*/
    }
    if ( v35 - 655360 > 0x5FFFF ) /*0x18f075*/
      LOBYTE(v9) = v9 & 0xF7; /*0x18f07c*/
    else
      LOBYTE(v9) = v9 | 8; /*0x18f077*/
    *v11 = v9; /*0x18f07f*/
    v9 = ((v9 & 0xFFFFF000) + 4096) | v9 & 0xFFF; /*0x18f093*/
    v8 += 4096; /*0x18f095*/
  }
  v13 = __readcr3(); /*0x18f0ae*/
  __writecr3(v13); /*0x18f0b1*/
  *a3 = v8; /*0x18f0ba*/
  v14 = v8; /*0x18f0bc*/
  v36 = 0; /*0x18f0bf*/
  v15 = 0; /*0x18f0c6*/
  do /*0x18f15d*/
  {
    v16 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (v14 >> 22)); /*0x18f0da*/
    if ( (*v16 & 1) == 0 || (v17 = (_DWORD *)(((v14 >> 10) & 0xFFC) + (*(_DWORD *)v16 & 0xFFFFF000))) == nullptr ) /*0x18f0f5*/
    {
      sub_18ECC0(v14); /*0x18f0f8*/
      v18 = (_DWORD *)(*(_DWORD *)kernel_pmap + 4 * (v14 >> 22)); /*0x18f10e*/
      if ( (*(_BYTE *)v18 & 1) != 0 ) /*0x18f113*/
        v17 = (_DWORD *)(((v14 >> 10) & 0xFFC) + (*v18 & 0xFFFFF000)); /*0x18f12e*/
      else
        v17 = nullptr; /*0x18f115*/
    }
    if ( v36 - 655360 > 0x5FFFF ) /*0x18f13d*/
      v15 &= ~8u; /*0x18f144*/
    else
      v15 |= 8u; /*0x18f13f*/
    *v17 = v15; /*0x18f147*/
    v14 += 4096; /*0x18f149*/
    v36 += 4096; /*0x18f14f*/
  }
  while ( v36 < 0x4000000 ); /*0x18f15d*/
  v19 = __readcr3(); /*0x18f163*/
  __writecr3(v19); /*0x18f166*/
  v41 = v14; /*0x18f169*/
  if ( MEMORY[0x1285C] ) /*0x18f174*/
  {
    v20 = ~page_mask & MEMORY[0x1286C]; /*0x18f19b*/
    v38 = ~page_mask & (page_mask + MEMORY[0x1285E] * MEMORY[0x12860] + 2 * MEMORY[0x1286C] - v20); /*0x18f1ac*/
    MEMORY[0x12854] = v41 + MEMORY[0x1286C] - v20; /*0x18f1b4*/
    v37 = v41; /*0x18f1bd*/
    for ( j = v20 & 0xFFFFF000 | (2 * (dword_1F7A8C & 3)) | 1; v38 > v20; v20 += 4096 ) /*0x18f1dc*/
    {
      v22 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (v37 >> 22)); /*0x18f1f3*/
      if ( (*v22 & 1) == 0 || (v23 = (unsigned int *)(((v37 >> 10) & 0xFFC) + (*(_DWORD *)v22 & 0xFFFFF000))) == nullptr ) /*0x18f20f*/
      {
        sub_18ECC0(v37); /*0x18f215*/
        v24 = (_DWORD *)(*(_DWORD *)kernel_pmap + 4 * (v37 >> 22)); /*0x18f22c*/
        if ( (*(_BYTE *)v24 & 1) != 0 ) /*0x18f231*/
          v23 = (unsigned int *)(((v37 >> 10) & 0xFFC) + (*v24 & 0xFFFFF000)); /*0x18f24b*/
        else
          v23 = nullptr; /*0x18f233*/
      }
      if ( v20 - 655360 > 0x5FFFF ) /*0x18f258*/
        v25 = j & 0xFFFFFFF7; /*0x18f260*/
      else
        v25 = j | 8; /*0x18f25a*/
      *v23 = v25; /*0x18f263*/
      j = ((v25 & 0xFFFFF000) + 4096) | v25 & 0xFFF; /*0x18f277*/
      v37 += 4096; /*0x18f279*/
    }
    v26 = __readcr3(); /*0x18f28f*/
    __writecr3(v26); /*0x18f292*/
    v41 = v37; /*0x18f298*/
  }
  *a4 = v41; /*0x18f2a1*/
  v27 = __readcr0(); /*0x18f2a3*/
  v28 = (_DWORD *)v39; /*0x18f2a6*/
  v29 = *(_DWORD **)kernel_pmap; /*0x18f2ae*/
  v30 = *(_DWORD *)kernel_pmap + 1024; /*0x18f2b0*/
  if ( *(_DWORD *)kernel_pmap < v30 ) /*0x18f2b8*/
  {
    do /*0x18f2c8*/
      *v28++ = *v29++; /*0x18f2be*/
    while ( (unsigned int)v29 < v30 ); /*0x18f2c8*/
  }
  v31 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (v39 >> 22)); /*0x18f2d9*/
  if ( (*v31 & 1) != 0 /*0x18f2fa*/
    && (v32 = (_DWORD *)((*(_DWORD *)v31 & 0xFFFFF000) + ((v39 >> 10) & 0xFFC))) != nullptr
    && (*(_BYTE *)v32 & 1) != 0 )
  {
    v33 = (v39 & 0xFFF) + (*v32 & 0xFFFFF000); /*0x18f310*/
  }
  else
  {
    v33 = 0; /*0x18f2fc*/
  }
  result = kernel_pmap; /*0x18f312*/
  *(_DWORD *)(kernel_pmap + 4) = v33; /*0x18f317*/
  __writecr3(v33); /*0x18f31a*/
  __writecr0(v27 | 0x80010000); /*0x18f323*/
  return result; /*0x18f329*/
}
