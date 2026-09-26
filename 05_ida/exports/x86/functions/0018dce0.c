/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18dce0. */
int thread_bootstrap_return()
{
  int v0; // edx
  int v1; // esi
  unsigned int v2; // edx
  void *v3; // eax
  int v4; // edx
  unsigned int v5; // ecx
  _BYTE *v6; // ecx
  _DWORD *v7; // eax
  int v8; // edx
  int v9; // ebx
  int v10; // edx
  _BYTE *v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // ebx
  unsigned int v16; // [esp+14h] [ebp-1Ch]
  size_t __n; // [esp+1Ch] [ebp-14h]
  void *__src; // [esp+20h] [ebp-10h]
  int v19; // [esp+24h] [ebp-Ch]
  _DWORD *v20; // [esp+28h] [ebp-8h]
  thread_act_t v21; // [esp+2Ch] [ebp-4h]

  v21 = active_threads; /*0x18dcef*/
  v20 = *(_DWORD **)(*(_DWORD *)(active_threads + 12) + 64); /*0x18dcf8*/
  v19 = *(_DWORD *)(active_threads + 40); /*0x18dcfe*/
  lock_read((int)(v20 + 4)); /*0x18dd05*/
  v0 = v20[3]; /*0x18dd10*/
  if ( v0 ) /*0x18dd15*/
  {
    __src = (void *)v20[2]; /*0x18dd1e*/
    __n = v20[3]; /*0x18dd21*/
    v1 = *(_DWORD *)(v21 + 40); /*0x18dd27*/
    v2 = v0 + 105; /*0x18dd2d*/
    if ( *(_DWORD *)(v1 + 4) < v2 ) /*0x18dd33*/
    {
      v16 = v2; /*0x18dd39*/
      v3 = (void *)kalloc(v2); /*0x18dd3d*/
      qmemcpy(v3, *(const void **)v1, 0x68u); /*0x18dd57*/
      if ( (*(_BYTE *)(v1 + 240) & 4) != 0 ) /*0x18dd66*/
      {
        v4 = *(_DWORD *)(v1 + 8); /*0x18dd68*/
        v5 = *(_DWORD *)(v1 + 12); /*0x18dd6b*/
        *(_DWORD *)(v1 + 8) = v3; /*0x18dd71*/
        *(_DWORD *)(v1 + 12) = v16; /*0x18dd77*/
        *(_DWORD *)v1 = v3; /*0x18dd7a*/
        *(_DWORD *)(v1 + 4) = v16; /*0x18dd7f*/
        *(_BYTE *)(v1 + 240) |= 4u; /*0x18dd82*/
        kfree(v4, v5); /*0x18dd8b*/
      }
      else
      {
        *(_DWORD *)(v1 + 8) = v3; /*0x18dd9e*/
        *(_DWORD *)(v1 + 12) = v16; /*0x18dda4*/
        *(_DWORD *)v1 = v3; /*0x18ddaa*/
        *(_DWORD *)(v1 + 4) = v16; /*0x18ddaf*/
        *(_BYTE *)(v1 + 240) |= 4u; /*0x18ddb2*/
      }
      if ( active_threads == v21 ) /*0x18ddc2*/
      {
        v6 = gdt; /*0x18ddc4*/
        v7 = *(_DWORD **)(v21 + 40); /*0x18ddca*/
        v8 = *v7 - 0x40000000; /*0x18ddcf*/
        v9 = v7[1] - 1; /*0x18ddd8*/
        *((_WORD *)gdt + 13) = *(_WORD *)v7; /*0x18ddd9*/
        v6[28] = BYTE2(v8); /*0x18dde2*/
        v6[31] = HIBYTE(v8); /*0x18dde8*/
        v6[29] = -119; /*0x18ddeb*/
        v6[30] &= ~0x80u; /*0x18ddef*/
        *((_WORD *)v6 + 12) = v9; /*0x18ddf3*/
        v6[30] = BYTE2(v9) & 0xF | v6[30] & 0xF0; /*0x18de06*/
        __asm { ltr word ptr ds:unk_1D14E8 } /*0x18de09*/
      }
    }
    memcpy((void *)(*(unsigned __int16 *)(*(_DWORD *)v1 + 102) + *(_DWORD *)v1), __src, __n); /*0x18de24*/
  }
  if ( *(_DWORD *)(v19 + 116) != *v20 ) /*0x18de37*/
  {
    v10 = v20[1]; /*0x18de39*/
    *(_DWORD *)(*(_DWORD *)(v21 + 40) + 116) = *v20; /*0x18de42*/
    *(_DWORD *)(*(_DWORD *)(v21 + 40) + 120) = v10; /*0x18de48*/
    if ( active_threads == v21 ) /*0x18de51*/
    {
      v11 = gdt; /*0x18de53*/
      v12 = *(_DWORD *)(v21 + 40); /*0x18de59*/
      v13 = *(_DWORD *)(v12 + 116); /*0x18de5c*/
      v14 = *(_DWORD *)(v12 + 120) - 1; /*0x18de62*/
      *((_WORD *)gdt + 17) = v13; /*0x18de63*/
      v11[36] = BYTE2(v13); /*0x18de6c*/
      v11[39] = HIBYTE(v13); /*0x18de72*/
      v11[37] = v11[37] & 0x60 | 0x82; /*0x18de7e*/
      v11[38] &= ~0x80u; /*0x18de81*/
      *((_WORD *)v11 + 16) = v14; /*0x18de85*/
      v11[38] = BYTE2(v14) & 0xF | v11[38] & 0xF0; /*0x18de98*/
      __asm { lldt ds:word_1D14EA } /*0x18de9b*/
    }
  }
  lock_done((int)(v20 + 4)); /*0x18dea9*/
  return thread_exception_return(); /*0x18deb6*/
}
