/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191144. */
char pmap_update()
{
  int *v0; // edx
  int *v1; // eax
  int *v2; // ecx
  int v3; // eax
  int v4; // esi
  int *v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // ecx
  _BYTE *v10; // edx
  unsigned __int8 v11; // dl
  _DWORD *v12; // ebx
  unsigned int v13; // esi
  vm_size_t v14; // edi
  char *v15; // edx
  unsigned __int32 v16; // eax
  int v17; // eax
  vm_size_t v18; // eax
  vm_size_t v20; // [esp+Ch] [ebp-18h]
  int v21; // [esp+10h] [ebp-14h]
  unsigned int v22; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h]
  int v24; // [esp+20h] [ebp-4h]

  if ( !dword_1E773C ) /*0x191154*/
    dword_1E773C = sched_tick; /*0x19115c*/
  v23 = sched_tick - dword_1E773C; /*0x19116e*/
  if ( sched_tick - dword_1E773C > 1 ) /*0x191174*/
  {
    while ( 1 ) /*0x19117c*/
    {
      v0 = (int *)pt_free_queue; /*0x19117c*/
      if ( (int *)pt_free_queue == &pt_free_queue ) /*0x191188*/
      {
        v1 = nullptr; /*0x19118a*/
      }
      else
      {
        *(_DWORD *)(*(_DWORD *)pt_free_queue + 4) = &pt_free_queue; /*0x191192*/
        pt_free_queue = *v0; /*0x19119b*/
        v1 = v0; /*0x1911a1*/
        if ( v0 ) /*0x1911a5*/
          --pt_free_count; /*0x1911a7*/
      }
      v2 = v1; /*0x1911ad*/
      if ( !v1 ) /*0x1911b1*/
        break; /*0x1911b1*/
      v3 = v1[2]; /*0x1911b3*/
      v4 = *(_DWORD *)(v3 + 8); /*0x1911b6*/
      *(_DWORD *)(v3 + 12) = 0; /*0x1911b9*/
      zfree(pg_exten_zone, v2); /*0x1911c8*/
      kmem_free(kernel_map, v4, page_size); /*0x1911df*/
      --pt_alloc_count; /*0x1911e4*/
    }
    v5 = (int *)pd_free_queue; /*0x1911f0*/
    while ( v5 != &pd_free_queue ) /*0x1911fc*/
    {
      if ( *((_WORD *)v5 + 12) ) /*0x1911fe*/
      {
        v5 = (int *)*v5; /*0x19125c*/
      }
      else
      {
        *(_DWORD *)(*v5 + 4) = v5[1]; /*0x19120a*/
        *(_DWORD *)v5[1] = *v5; /*0x191212*/
        --pd_free_count; /*0x191214*/
        v6 = v5[2]; /*0x19121a*/
        v7 = *(_DWORD *)(v6 + 8); /*0x19121d*/
        *(_DWORD *)(v6 + 12) = 0; /*0x191220*/
        zfree(pg_exten_zone, v5); /*0x19122f*/
        kmem_free(kernel_map, v7, page_size); /*0x191246*/
        --pd_alloc_count; /*0x19124b*/
        v5 = (int *)pd_free_queue; /*0x191251*/
      }
    }
  }
  if ( v23 >> 3 <= dword_1E2614 - 1 ) /*0x191274*/
    v8 = dword_1E2600[v23 >> 3]; /*0x191283*/
  else
    v8 = dword_1E25FC[dword_1E2614]; /*0x191276*/
  v22 = v8; /*0x19128a*/
  v9 = pt_active_queue; /*0x19128d*/
  while ( (int *)v9 != &pt_active_queue ) /*0x191299*/
  {
    v8 = 4 * (*(_DWORD *)(v9 + 20) >> 22); /*0x1912a8*/
    v10 = (_BYTE *)(v8 + **(_DWORD **)(v9 + 16)); /*0x1912ad*/
    if ( *(_WORD *)(v9 + 26) || (LOBYTE(v8) = *v10, (*v10 & 1) == 0) ) /*0x1912be*/
    {
      *(_BYTE *)(v9 + 29) = 0; /*0x1913cc*/
      v9 = *(_DWORD *)v9; /*0x1913d0*/
    }
    else
    {
      v24 = *(_DWORD *)v9; /*0x1912c6*/
      if ( v23 <= 0 ) /*0x1912cd*/
      {
        if ( (v8 & 0x20) == 0 ) /*0x1913ba*/
          goto LABEL_45; /*0x1913ba*/
LABEL_44:
        *v10 &= ~0x20u; /*0x1913bc*/
        *(_BYTE *)(v9 + 29) = 0; /*0x1913bf*/
        goto LABEL_45; /*0x1913bf*/
      }
      if ( (v8 & 0x20) != 0 ) /*0x1912d5*/
        goto LABEL_44; /*0x1912d5*/
      v11 = *(_BYTE *)(v9 + 29); /*0x1912db*/
      LOBYTE(v8) = v11 + v23; /*0x1912e1*/
      *(_BYTE *)(v9 + 29) = v11 + v23; /*0x1912e3*/
      if ( v11 > (unsigned __int8)(v11 + v23) || v22 < (unsigned __int8)v8 ) /*0x1912f0*/
      {
        v12 = *(_DWORD **)(v9 + 16); /*0x1912f6*/
        v13 = *(_DWORD *)(v9 + 20); /*0x1912fc*/
        v14 = section_size + v13; /*0x191301*/
        if ( v12 ) /*0x191309*/
        {
          v21 = splvm(); /*0x191314*/
          v15 = (char *)v13; /*0x191317*/
          if ( v12 == (_DWORD *)kernel_pmap || v12[6] ) /*0x191323*/
          {
            ++tlb_stat; /*0x191329*/
            if ( page_size >= v14 - v13 ) /*0x191339*/
            {
              if ( v13 < v14 ) /*0x191346*/
              {
                v17 = kernel_pmap; /*0x191348*/
                do /*0x191364*/
                {
                  if ( v12 == (_DWORD *)v17 ) /*0x19134f*/
                    __invlpg(v15); /*0x191351*/
                  else
                    __invlpg(MK_FP(__FS__, v15)); /*0x191358*/
                  v15 += 4096; /*0x19135c*/
                }
                while ( (unsigned int)v15 < v14 ); /*0x191364*/
              }
              ++dword_1F7AF4; /*0x191366*/
            }
            else
            {
              v16 = __readcr3(); /*0x19133b*/
              __writecr3(v16); /*0x19133e*/
            }
          }
          while ( v13 < v14 ) /*0x1913a5*/
          {
            v18 = (section_size + page_size + v13 - 1) & -section_size; /*0x191383*/
            if ( v18 > v14 ) /*0x191387*/
              v18 = v14; /*0x191389*/
            v20 = v18; /*0x191393*/
            sub_18F7F8(v12, v13, v18, 1); /*0x191396*/
            v13 = v20; /*0x19139e*/
          }
          LOBYTE(v8) = splx(v21); /*0x1913ab*/
        }
      }
LABEL_45:
      v9 = v24; /*0x1913c3*/
    }
  }
  dword_1E773C += v23; /*0x1913db*/
  return v8; /*0x1913e4*/
}
