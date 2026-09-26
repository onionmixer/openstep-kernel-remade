/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17aa08. */
int __cdecl vm_page_startup(unsigned int a1, int a2, int a3)
{
  _DWORD *v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  void *v8; // eax
  int v9; // eax
  char v10; // cl
  unsigned int v11; // eax
  unsigned int v12; // eax
  _DWORD *v13; // ecx
  unsigned int v14; // esi
  char *v15; // edx
  int v16; // eax
  unsigned int v18; // [esp+Ch] [ebp-1Ch]
  _DWORD *v19; // [esp+Ch] [ebp-1Ch]
  _DWORD **v20; // [esp+Ch] [ebp-1Ch]
  unsigned int *v21; // [esp+10h] [ebp-18h]
  unsigned int v22; // [esp+20h] [ebp-8h]
  unsigned int v23; // [esp+24h] [ebp-4h]

  dword_1F7454 = 0; /*0x17aa11*/
  dword_1F7458 = 0; /*0x17aa1b*/
  word_1F745C = 0; /*0x17aa25*/
  byte_1F7460 = 1; /*0x17aa58*/
  byte_1F7461 &= 0xE2u; /*0x17aa62*/
  byte_1F745E = byte_1F745E & 0xC0 | 0x20; /*0x17aa6a*/
  dword_1F7464 = 0; /*0x17aa70*/
  dword_1F7468 = 0; /*0x17aa7a*/
  dword_1F746C = 0; /*0x17aa84*/
  vm_page_queue_free_lock = 0; /*0x17aa8e*/
  vm_page_queue_lock = 0; /*0x17aa98*/
  dword_1F6E4C = (int)&vm_page_queue_free; /*0x17aaa2*/
  vm_page_queue_free = (int)&vm_page_queue_free; /*0x17aaac*/
  dword_1F6E44 = (int)&vm_page_queue_active; /*0x17aab6*/
  vm_page_queue_active = (int)&vm_page_queue_active; /*0x17aac0*/
  dword_1F64E4 = (int)&vm_page_queue_inactive; /*0x17aaca*/
  vm_page_queue_inactive = (int)&vm_page_queue_inactive; /*0x17aad4*/
  v23 = 0; /*0x17aade*/
  v18 = a1; /*0x17aae8*/
  if ( a1 < a1 + 28 * a2 ) /*0x17aafa*/
  {
    v3 = (_DWORD *)(a1 + 20); /*0x17ab0f*/
    do /*0x17ab33*/
    {
      v23 += (v3[1] & ~page_mask) - (~page_mask & (page_mask + *v3)); /*0x17ab23*/
      v3 += 7; /*0x17ab26*/
      v18 += 28; /*0x17ab29*/
    }
    while ( v18 < a1 + 28 * a2 ); /*0x17ab33*/
  }
  if ( !vm_page_bucket_count ) /*0x17ab3c*/
  {
    for ( vm_page_bucket_count = 1; vm_page_bucket_count < v23 >> page_shift; vm_page_bucket_count *= 2 ) /*0x17ab56*/
      ; /*0x17ab66*/
  }
  vm_page_hash_mask = vm_page_bucket_count - 1; /*0x17ab78*/
  if ( ((vm_page_bucket_count - 1) & vm_page_bucket_count) != 0 )
    printf("vm_page_bootstrap: WARNING -- strange page hash\n");
  vm_page_buckets = vm_alloc_from_regions(8 * vm_page_bucket_count, 4); /*0x17aba5*/
  bzero((void *)vm_page_buckets, 8 * vm_page_bucket_count); /*0x17abba*/
  v4 = 0; /*0x17abc2*/
  v5 = vm_page_bucket_count; /*0x17abc4*/
  if ( vm_page_bucket_count ) /*0x17abcc*/
  {
    v6 = (_DWORD *)vm_page_buckets; /*0x17abce*/
    do /*0x17abe7*/
    {
      v6[1] = 0; /*0x17abd4*/
      *v6 = 0; /*0x17abdb*/
      v6 += 2; /*0x17abe1*/
      ++v4; /*0x17abe4*/
    }
    while ( v4 < v5 ); /*0x17abe7*/
  }
  zdata_size = 8 * page_size; /*0x17abf5*/
  zdata = vm_alloc_from_regions(8 * page_size, page_size); /*0x17ac02*/
  bzero((void *)zdata, zdata_size); /*0x17ac0f*/
  map_data_size = 800; /*0x17ac17*/
  map_data = vm_alloc_from_regions(800, 4); /*0x17ac2d*/
  bzero((void *)map_data, map_data_size); /*0x17ac3a*/
  kentry_data_size = 90112; /*0x17ac42*/
  kentry_data = vm_alloc_from_regions(90112, 4); /*0x17ac58*/
  bzero((void *)kentry_data, kentry_data_size); /*0x17ac65*/
  v19 = (_DWORD *)a1; /*0x17ac70*/
  if ( a1 < a1 + 28 * a2 ) /*0x17ac82*/
  {
    v7 = (_DWORD *)(a1 + 20); /*0x17ac8d*/
    do /*0x17ad0b*/
    {
      v8 = (void *)vm_alloc_from_regions( /*0x17acb6*/
                     48 * (((~page_mask & v7[1]) - (~page_mask & (unsigned int)(*v7 + page_mask))) >> page_shift),
                     4);
      *v19 = v8; /*0x17acc1*/
      bzero(v8, 48 * (((~page_mask & v7[1]) - (~page_mask & (unsigned int)(*v7 + page_mask))) >> page_shift)); /*0x17aceb*/
      v7 += 7; /*0x17acf3*/
      v19 += 7; /*0x17acf9*/
    }
    while ( (unsigned int)v19 < a1 + 28 * a2 ); /*0x17ad0b*/
  }
  vm_page_free_count = 0; /*0x17ad0d*/
  v20 = (_DWORD **)a1; /*0x17ad1a*/
  if ( a1 < a1 + 28 * a2 ) /*0x17ad2c*/
  {
    v21 = (unsigned int *)(a1 + 12); /*0x17ad3b*/
    do /*0x17aded*/
    {
      v9 = ~page_mask; /*0x17ad4d*/
      v21[2] = ~page_mask & (page_mask + v21[2]); /*0x17ad51*/
      v21[3] &= v9; /*0x17ad54*/
      v10 = page_shift; /*0x17ad57*/
      *(v21 - 2) = v21[2] >> page_shift; /*0x17ad65*/
      v11 = v21[3] >> v10; /*0x17ad6b*/
      *(v21 - 1) = v11; /*0x17ad6d*/
      v12 = v11 - *(v21 - 2); /*0x17ad70*/
      *v21 = v12; /*0x17ad73*/
      vm_page_free_count += v12; /*0x17ad75*/
      v13 = *v20; /*0x17ad7e*/
      v22 = v21[2]; /*0x17ad86*/
      v14 = 0; /*0x17ad89*/
      if ( *v21 ) /*0x17ad8e*/
      {
        v15 = (char *)v13 + 30; /*0x17ad92*/
        do /*0x17addd*/
        {
          *(_DWORD *)(v15 + 6) = v22; /*0x17ad9b*/
          v16 = dword_1F6E4C; /*0x17ad9e*/
          if ( (int *)dword_1F6E4C == &vm_page_queue_free ) /*0x17ada8*/
            vm_page_queue_free = (int)v13; /*0x17adaa*/
          else
            *(_DWORD *)dword_1F6E4C = v13; /*0x17adb4*/
          *(_DWORD *)(v15 - 26) = v16; /*0x17adb6*/
          *v13 = &vm_page_queue_free; /*0x17adb9*/
          dword_1F6E4C = (int)v13; /*0x17adbf*/
          *v15 |= 8u; /*0x17adc5*/
          v15 += 48; /*0x17adc8*/
          v13 += 12; /*0x17adcb*/
          v22 += page_size; /*0x17add4*/
          ++v14; /*0x17add7*/
        }
        while ( *v21 > v14 ); /*0x17addd*/
      }
      v21 += 7; /*0x17addf*/
      v20 += 7; /*0x17ade3*/
    }
    while ( (unsigned int)v20 < a1 + 28 * a2 ); /*0x17aded*/
  }
  vm_pages_needed_lock = 0; /*0x17adf3*/
  return a3; /*0x17ae03*/
}
